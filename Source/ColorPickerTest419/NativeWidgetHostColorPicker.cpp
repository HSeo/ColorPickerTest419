#include "NativeWidgetHostColorPicker.h"
#include "SColorPicker.h"

UNativeWidgetHostColorPicker::UNativeWidgetHostColorPicker(const FObjectInitializer& ObjectInitializer) : UNativeWidgetHost(ObjectInitializer) {}

void UNativeWidgetHostColorPicker::ReleaseSlateResources(bool bReleaseChildren) {
  Super::ReleaseSlateResources(bReleaseChildren);
  color_picker_.Reset();
}

TSharedRef<SWidget> UNativeWidgetHostColorPicker::RebuildWidget() {
  SAssignNew(color_picker_, SColorPicker);
  SetContent(color_picker_.ToSharedRef()); // Unnecessary??

  return color_picker_.ToSharedRef();
}