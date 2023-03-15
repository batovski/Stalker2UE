// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

THIRD_PARTY_INCLUDES_START
#include "XrRender/Public/ParticleCustom.h"
THIRD_PARTY_INCLUDES_END

#include "StalkerParticleSystemComponent.generated.h"


UCLASS(BlueprintType)
class STALKER_API UStalkerParticleSystemComponent : public UParticleSystemComponent, public IRenderVisual, public IParticleCustom
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStalkerParticleSystemComponent();

	//IRenderVisual
	vis_data& _BCL						getVisData() override;
	u32									getType() override;

	shared_str	_BCL					getDebugName() override;

	IKinematics* _BCL					dcast_PKinematics() override { return 0; }
	IKinematicsAnimated*				dcast_PKinematicsAnimated() override { return 0; }
	IParticleCustom*					dcast_ParticleCustom() override;
	class XRaySkeletonVisual*			CastToRaySkeletonVisual() override { return 0; }
	class UStalkerKinematicsComponent*	CastToStalkerKinematicsComponent() override { return 0; }
	void								Detach() override;

	//IParicleCustom
	void 	OnDeviceCreate() override;
	void 	OnDeviceDestroy() override;

	void	UpdateParent(const Fmatrix& m, const Fvector& velocity, BOOL bXFORM) override;
	void	OnFrame(u32 dt) override;

	void	Play() override;
	void	Stop(BOOL bDefferedStop = TRUE) override;
	BOOL	IsPlaying() override;

	u32		ParticlesCount() override;

	float	GetTimeLimit() override;
	BOOL	IsLooped() override { return GetTimeLimit() < 0.f; }

	const shared_str	Name() override;
	void	SetHudMode(BOOL b) override;
	BOOL	GetHudMode() override;

private:
	vis_data									VisData;
	shared_str									DataName;
		
};
