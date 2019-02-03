#include "NativeWidgetHostColorPicker.h"
#include "SColorPicker.h"

UNativeWidgetHostColorPicker::UNativeWidgetHostColorPicker(const FObjectInitializer& ObjectInitializer) : UNativeWidgetHost(ObjectInitializer) {}

TSharedRef<SWidget> UNativeWidgetHostColorPicker::RebuildWidget() {
  TSharedRef<SColorPicker> color_picker = SNew(SColorPicker);
  SetContent(color_picker);

  UNativeWidgetHost::RebuildWidget(); // Unnecessary?

  return GetContent().ToSharedRef();
}