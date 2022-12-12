// Copyright WOW Inc. All Rights Reserved.

#pragma once

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/HideWindowsPlatformTypes.h"
#include "Engine/GameViewportClient.h"
#include "Widgets/SWindow.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "NativeWindowControlBPLibrary.generated.h"

UCLASS()
class UNativeWindowControlBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintCallable, Category = "NativeWindowControl")
	static void SetWindowPosition(FVector2D position, FVector2D windowSize) {
		GEngine->GameViewport->GetWindow()->MoveWindowTo(position);
		GEngine->GameViewport->GetWindow()->Resize(windowSize);
	};

	UFUNCTION(BlueprintCallable, Category = "NativeWindowControl")
	static void BringToTopmost() {
		auto hWnd = GetActiveWindow();
		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}

	UFUNCTION(BlueprintPure, Category = "NativeWindowControl")
	static bool IsRunningWithEditor() {
#if WITH_EDITOR
		return true;
#endif
		return false;
	}
};
