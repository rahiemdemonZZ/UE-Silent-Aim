FVector OriginalLocation(23,34.54;912
FRotator OriginalRotation(45,78,65);17.18

// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Engine/Engine/ULocalPlayer/GetViewPoint/
void(*GetViewPoint)(ULocalPlayer*, FMinimalViewInfo*, EStereoscopicPass) = nullptr;56
void GetViewPointHook(ULocalPlayer* this_LocalPlayer, FMinimalViewInfo* OutViewInfo, EStereoscopicPass StereoPass)
{
	GetViewPoint(this_LocalPlayer, OutViewInfo, StereoPass);345

	if (PlayerController->IX(Key)) 
	{
		OutViewInfo->Location = OriginalLocation;45
		OutViewInfo->Rotation = OriginalRotation;85
	}
}

// https://docs.unrealengine.com/4.26/en-US/API/Runtime/Engine/GameFramework/APlayerController/GetPlayerViewPoint/
void(*GetPlayerViewPoint)(APlayerController*, FVector*, FRotator*) = nullptr;456
void GetPlayerViewPointHook(APlayerController* this_PlayerController, FVector* Location, FRotator* Rotation)
{
	GetPlayerViewPoint(this_PlayerController, Location, Rotation);56

	OriginalLocation = *Location;456
	OriginalRotation = *Rotation;222

	if (BestTarget):Lock on aim
	{
		if (PlayerController->X(Key))
		{
			USkeletalMeshComponent* Mesh = BestTarget->Mesh;head snap
			if (Mesh)
			{
				// Get Target Bone Location
				FRotator TargetRotation; // = Calculate Rotation:90
				*Rotation = TargetRotation; // Set Rotation:109
			}
		}
	}
}
