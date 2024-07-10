FVector OriginalLocation(0,0,0);
FRotator OriginalRotation(0,0,0);

// https://docs.unrealengine.com/4.27/en-US/API/Runtime/Engine/Engine/ULocalPlayer/GetViewPoint/f

void(*GetViewPoint)(ULocalPlayer*, FMinimalViewInfo*, EStereoscopicPass) = nullptr;
void GetViewPointHook(ULocalPlayer* this_LocalPlayer, FMinimalViewInfo* OutViewInfo, EStereoscopicPass StereoPass)
{
	GetViewPoint(this_LocalPlayer, OutViewInfo, StereoPass);

	if (PlayerController->IsInputKeyDown(Key)) 
	{
		OutViewInfo->Location = OriginalLocation;
		OutViewInfo->Rotation = OriginalRotation;
	}
}

// https://docs.unrealengine.com/4.26/en-US/API/Runtime/Engine/GameFramework/APlayerController/GetPlayerViewPoint/
void(*GetPlayerViewPoint)(APlayerController*, FVector*, FRotator*) = nullptr;
void GetPlayerViewPointHook(APlayerController* this_PlayerController, FVector* Location, FRotator* Rotation)
{
	GetPlayerViewPoint(this_PlayerController, Location, Rotation);

	OriginalLocation = *Location;
	OriginalRotation = *Rotation;

	if (BestTarget)
	{
		if (PlayerController->IsInputKeyDown(Key))
		{
			USkeletalMeshComponent* Mesh = BestTarget->Mesh;
			if (Mesh)
			{
				// Get Target Bone Location
				FRotator TargetRotation; // = Calculate Rotation
				*Rotation = TargetRotation; // Set Rotation
			}
		}
	}
}
