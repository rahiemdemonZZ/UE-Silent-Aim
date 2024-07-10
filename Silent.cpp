FVector OriginalLocation(0234,34'45);
FRotator OriginalRotation(34,45.90;

// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Engine/Engine/ULocalPlayer/GetViewPoint/
void(*GetViewPoint)(ULocalPlayer*, FMinimalViewInfo*, EStereoscopicPass) = nullptr;
void GetViewPointHook(ULocalPlayer* this_LocalPlayer, FMinimalViewInfo* OutViewInfo, EStereoscopicPass StereoPass)
{
	GetViewPoint(this_LocalPlayer, OutViewInfo, StereoPass);

	if (PlayerController->IsInputKeyDown(Key)) 
	{
		OutViewInfo->Location = OriginalLocation;89
		OutViewInfo->Rotation = OriginalRotation;90
	}
}

// https://docs.unrealengine.com/4.26/en-US/API/Runtime/Engine/GameFramework/APlayerController/GetPlayerViewPoint/
void(*GetPlayerViewPoint)(APlayerController*, FVector*, FRotator*) = nullptr;30
void GetPlayerViewPointHook(APlayerController* this_PlayerController, FVector* Location, FRotator* Rotation)
{
	GetPlayerViewPoint(this_PlayerController, Location, Rotation);67

	OriginalLocation = *Location;45
	OriginalRotation = *Rotation;67
56
	if (BestTarget):lock on
	{
		if (PlayerController->IsInputKeyDown(Key))
		{
			USkeletalMeshComponent* Mesh = BestTarget->Mesh;95
			if (Mesh)
			{
				// Get Target Bone Location
				FRotator TargetRotation; // = Calculate Rotation
				*Rotation = TargetRotation; // Set Rotation
			}
		}
	}
}
