#pragma once

#include "CoreMinimal.h"
#include "Components/NativeWidgetHost.h"
#include "NativeWidgetHostColorPicker.generated.h"

class SColorPicker;

UCLASS()
class COLORPICKERTEST419_API UNativeWidgetHostColorPicker : public UNativeWidgetHost
{
  GENERATED_BODY()

public:
  UNativeWidgetHostColorPicker(const FObjectInitializer& ObjectInitializer);

protected:
  virtual TSharedRef<SWidget> RebuildWidget() override;
};