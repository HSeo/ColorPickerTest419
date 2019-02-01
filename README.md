# ColorPickerTest419
SColorPicker with NativeWidgetHost in (at least) Unreal Engine 4.19. cannot be packaged, while there is no problem during Play in Editor.
---

I'd like to use SColorPicker as UMG, so I tried a very simple implementation using UNativeWidgetHost like the followings.

* NativeWidgetHostColorPicker.h
``` cpp:NativeWidgetHostColorPicker.h
#pragma once

#include "CoreMinimal.h"
#include "Components/NativeWidgetHost.h"
#include "NativeWidgetHostColorPicker.generated.h"

UCLASS()
class COLORPICKERTEST419_API UNativeWidgetHostColorPicker : public UNativeWidgetHost
{
  GENERATED_BODY()

public:
  UNativeWidgetHostColorPicker(const FObjectInitializer& ObjectInitializer);
};
```  

* NativeWidgetHostColorPicker.cpp
``` cpp:NativeWidgetHostColorPicker.cpp
#include "NativeWidgetHostColorPicker.h"
#include "SColorPicker.h"

UNativeWidgetHostColorPicker::UNativeWidgetHostColorPicker(const FObjectInitializer& ObjectInitializer) : UNativeWidgetHost(ObjectInitializer) {
  TSharedRef<SColorPicker> color_picker = SNew(SColorPicker);

  SetContent(color_picker);
}
```  

* WidgetBlueprint
![SColorPicker_UMG](https://user-images.githubusercontent.com/8625552/52100766-27316880-261c-11e9-98f1-977c5fe1e243.jpg)

---
  
It works fine during Play in Editor like the following image.
![SColorPicker_PIE](https://user-images.githubusercontent.com/8625552/52100760-226cb480-261c-11e9-8d37-5f29b84e6886.jpg)

However, when I try to packaging the project (Windows(64 bit)), it causes an error.

<details>
<summary>PackagingResults: Error: begin: stack for UAT (click the left triangle to show everything.)</summary>
<pre>
<code>
PackagingResults: Error: === Critical error: ===
PackagingResults: Error: Assertion failed: IsValid() [File:D:\Build\++UE4+Release-4.19+Compile\Sync\Engine\Source\Runtime\Core\Public\Templates/SharedPointer.h] [Line: 824]
PackagingResults: Error: [Callstack] 0x000000000143A388 KERNELBASE.dll!UnknownFunction []
PackagingResults: Error: [Callstack] 0x00000000DE247884 UE4Editor-ApplicationCore.dll!FWindowsErrorOutputDevice::Serialize() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\applicationcore\private\windows\windowserroroutputdevice.cpp:65]
PackagingResults: Error: [Callstack] 0x0000000023636D9B UE4Editor-Core.dll!FOutputDevice::LogfImpl() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\core\private\misc\outputdevice.cpp:70]
PackagingResults: Error: [Callstack] 0x0000000023571949 UE4Editor-Core.dll!FDebug::AssertFailed() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\core\private\misc\assertionmacros.cpp:419]
PackagingResults: Error: [Callstack] 0x0000000078F43B0F UE4Editor-SlateCore.dll!FSlateApplicationBase::Get() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\slatecore\public\application\slateapplicationbase.h:428]
PackagingResults: Error: [Callstack] 0x0000000078F8A897 UE4Editor-SlateCore.dll!SWidget::RegisterActiveTimer() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\slatecore\private\widgets\swidget.cpp:984]
PackagingResults: Error: [Callstack] 0x0000000069A67204 UE4Editor-AppFramework.dll!SColorPicker::Construct() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\appframework\private\widgets\colors\scolorpicker.cpp:90]
PackagingResults: Error: [Callstack] 0x000000000D3D2516 UE4Editor-ColorPickerTest419.dll!UNativeWidgetHostColorPicker::UNativeWidgetHostColorPicker() [c:\users\xxxx\documents\unreal projects\colorpickertest419\source\colorpickertest419\nativewidgethostcolorpicker.cpp:5]
PackagingResults: Error: [Callstack] 0x00000000AE0654F8 UE4Editor-CoreUObject.dll!UClass::CreateDefaultObject() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\coreuobject\private\uobject\class.cpp:2749]
PackagingResults: Error: [Callstack] 0x00000000AE2F7D30 UE4Editor-CoreUObject.dll!UObjectLoadAllCompiledInDefaultProperties() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\coreuobject\private\uobject\uobjectbase.cpp:821]
PackagingResults: Error: [Callstack] 0x00000000AE2D94A2 UE4Editor-CoreUObject.dll!ProcessNewlyLoadedUObjects() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\coreuobject\private\uobject\uobjectbase.cpp:895]
PackagingResults: Error: [Callstack] 0x00000000AE06A7F7 UE4Editor-CoreUObject.dll!TBaseStaticDelegateInstance<void __cdecl(void)>::ExecuteIfSafe() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\core\public\delegates\delegateinstancesimpl.h:788]
PackagingResults: Error: [Callstack] 0x0000000023424190 UE4Editor-Core.dll!TBaseMulticastDelegate<void>::Broadcast() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\core\public\delegates\delegatesignatureimpl.inl:937]
PackagingResults: Error: [Callstack] 0x0000000023635E91 UE4Editor-Core.dll!FModuleManager::LoadModuleWithFailureReason() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\core\private\modules\modulemanager.cpp:487]
PackagingResults: Error: [Callstack] 0x00000000DE7FFC7A UE4Editor-Projects.dll!FModuleDescriptor::LoadModulesForPhase() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\projects\private\moduledescriptor.cpp:484]
PackagingResults: Error: [Callstack] 0x00000000DE7FFFC2 UE4Editor-Projects.dll!FProjectManager::LoadModulesForProject() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\projects\private\projectmanager.cpp:69]
PackagingResults: Error: [Callstack] 0x00000000D1109731 UE4Editor-Cmd.exe!FEngineLoop::LoadStartupModules() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\launch\private\launchengineloop.cpp:2610]
PackagingResults: Error: [Callstack] 0x00000000D110DD83 UE4Editor-Cmd.exe!FEngineLoop::PreInit() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\launch\private\launchengineloop.cpp:2027]
PackagingResults: Error: [Callstack] 0x00000000D11069FA UE4Editor-Cmd.exe!GuardedMain() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\launch\private\launch.cpp:127]
PackagingResults: Error: [Callstack] 0x00000000D1106C4A UE4Editor-Cmd.exe!GuardedMainWrapper() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\launch\private\windows\launchwindows.cpp:144]
PackagingResults: Error: [Callstack] 0x00000000D1114177 UE4Editor-Cmd.exe!WinMain() [d:\build\++ue4+release-4.19+compile\sync\engine\source\runtime\launch\private\windows\launchwindows.cpp:223]
PackagingResults: Error: [Callstack] 0x00000000D1114FBF UE4Editor-Cmd.exe!__scrt_common_main_seh() [f:\dd\vctools\crt\vcstartup\src\startup\exe_common.inl:253]
PackagingResults: Error: [Callstack] 0x00000000026B3034 KERNEL32.DLL!UnknownFunction []
PackagingResults: Error: [Callstack] 0x00000000050A3691 ntdll.dll!UnknownFunction []
PackagingResults: Error: [Callstack] 0x00000000050A3691 ntdll.dll!UnknownFunction []
</code>
</pre>
</details>  
<br>  
  
It seems that
```cpp
TSharedRef<SColorPicker> color_picker = SNew(SColorPicker);
```
in NativeWidgetHostColorPicker.cpp causes an error.
And when I replace SColorPicker by other SWidget inherited class like SColorSpectrum,
```cpp
TSharedRef<SColorSpectrum> color_picker = SNew(SColorSpectrum);
```
it works fine during Playing in Editor, and it can be packaged with no error.
(The SColorSpectrum project is [here](https://github.com/HSeo/ColorSpectrumTest419).)

Is this a bug? Or maybe my implementation is somehow incorrect?
