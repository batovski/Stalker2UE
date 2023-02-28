#pragma once
#include "CoreMinimal.h"

#include "XrRender/Public/ParticleCustom.h"

#include "StalkerParticleSystemComponent.generated.h"


UCLASS(BlueprintType)
class STALKER_API UStalkerParticleSystemComponent :public UParticleSystemComponent, public IRenderVisual, public IParticleCustom
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStalkerParticleSystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//IRenderVisual
	vis_data&	_BCL			getVisData();
	u32							getType();

	shared_str	_BCL			getDebugName();

	IKinematics*	_BCL		dcast_PKinematics			()				{ return 0;	}
	IKinematicsAnimated*		dcast_PKinematicsAnimated	()				{ return 0;	}
	IParticleCustom*	_BCL		dcast_ParticleCustom() override;
	class XRaySkeletonVisual*	CastToRaySkeletonVisual	()				{ return 0;	}
	class UStalkerKinematicsComponent*   CastToStalkerKinematicsComponent()				{ return 0; }

	//IParticleCustom
	void 	OnDeviceCreate();
	void 	OnDeviceDestroy();
	void	UpdateParent(const Fmatrix& m, const Fvector& velocity, BOOL bXFORM);
	void	OnFrame(u32 dt);
	void	Play();
	void	Stop(BOOL bDefferedStop = TRUE);
	BOOL	IsPlaying();
	u32		ParticlesCount();
	float	GetTimeLimit();
	BOOL	IsLooped() { return GetTimeLimit() < 0.f; }
	const shared_str	Name();
	void	SetHudMode(BOOL b);
	BOOL	GetHudMode();

private:
	vis_data									VisData;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* SceneComponent;
};
