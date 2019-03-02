# ColorPickerTest419
SColorPicker with NativeWidgetHost both in Play in Editor and in packaged executable.
---

* NativeWidgetHostColorPicker.h
``` cpp:NativeWidgetHostColorPicker.h
#pragma once

#include "CoreMinimal.h"
#include "Components/NativeWidgetHost.h"
#include "NativeWidgetHostColorPicker.generated.h"

class SColorPicker;

UCLASS()
class COLORPICKERTEST419_API UNativeWidgetHostColorPicker : public UNativeWidgetHost {
  GENERATED_BODY()

public:
  UNativeWidgetHostColorPicker(const FObjectInitializer& ObjectInitializer);
  virtual void ReleaseSlateResources(bool bReleaseChildren) override;

protected:
  virtual TSharedRef<SWidget> RebuildWidget() override;

private:
  TSharedPtr<SColorPicker> color_picker_;
};
```  

* NativeWidgetHostColorPicker.cpp
``` cpp:NativeWidgetHostColorPicker.cpp
#include "NativeWidgetHostColorPicker.h"
#include "SColorPicker.h"

UNativeWidgetHostColorPicker::UNativeWidgetHostColorPicker(const FObjectInitializer& ObjectInitializer) : UNativeWidgetHost(ObjectInitializer) {}

void UNativeWidgetHostColorPicker::ReleaseSlateResources(bool bReleaseChildren) {
  Super::ReleaseSlateResources(bReleaseChildren);
  color_picker_.Reset();
}

TSharedRef<SWidget> UNativeWidgetHostColorPicker::RebuildWidget() {
  SAssignNew(color_picker_, SColorPicker);
  SetContent(color_picker_.ToSharedRef());

  //UNativeWidgetHost::RebuildWidget(); // Unnecessary?

  return GetContent().ToSharedRef();
}
```  

* WidgetBlueprint
![SColorPicker_UMG](https://user-images.githubusercontent.com/8625552/52100766-27316880-261c-11e9-98f1-977c5fe1e243.jpg)

---

**SetContent function has to be called in RebuildWidget instead of in the constructor of UNativeWidgetHostColorPicker.** If you put SetContent in the constructor, it cannot be packaged while it can be executed in Play in Editor.
I have no idea if Rebuildwidget function of the partent class (UNativeWidgetHost::RebuildWidget) should be called or not.

**ReleaseSlateResources is also inevitable to avoid memory leaks.**

![SColorPicker_PIE](https://user-images.githubusercontent.com/8625552/52100760-226cb480-261c-11e9-8d37-5f29b84e6886.jpg)
