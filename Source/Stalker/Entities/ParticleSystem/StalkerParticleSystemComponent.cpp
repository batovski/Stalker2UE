// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/ParticleSystem/StalkerParticleSystemComponent.h"

#include "NiagaraComponent.h"

// Sets default values for this component's properties
UStalkerParticleSystemComponent::UStalkerParticleSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	VisData.clear();

	// ...
}

void UStalkerParticleSystemComponent::Init(UNiagaraComponent* NiagaraComponent)
{
	if (!NiagaraComponent) { return; }
	Particles = NiagaraComponent;
	Particles->SetAutoDestroy(true);

	FBox Box = NiagaraComponent->Bounds.GetBox();

	VisData.box.invalidate();
	VisData.box.modify(StalkerMath::UnrealLocationToXRay(Box.Min));
	VisData.box.modify(StalkerMath::UnrealLocationToXRay(Box.Max));
	Fvector Center;
	VisData.box.getcenter(Center);
	VisData.sphere.set(Center, VisData.box.getradius());
}

//IRenderVisual
vis_data& _BCL			UStalkerParticleSystemComponent::getVisData()
{
	return VisData;
}
u32						UStalkerParticleSystemComponent::getType()
{
	return 0;
}

shared_str	_BCL			UStalkerParticleSystemComponent::getDebugName()
{
	return DataName;
}
IParticleCustom* UStalkerParticleSystemComponent::dcast_ParticleCustom()
{
	return this;
}
void			UStalkerParticleSystemComponent::Detach()
{
	
}

//IParticleCustom
void 	UStalkerParticleSystemComponent::OnDeviceCreate()
{
	
}
void 	UStalkerParticleSystemComponent::OnDeviceDestroy()
{
	if (Particles)
	{
		Particles->DestroyInstance();
	}

	AActor* Parent = this->GetAttachParentActor();
	if(!Parent)
	{
		DestroyComponent(false);
	}
	else
	{
		Parent->Destroy();
	}
}

void	UStalkerParticleSystemComponent::UpdateParent(const Fmatrix& m, const Fvector& velocity, BOOL bXFORM)
{
	if (!Particles) { return; }

	Fvector transform;
	m.transform(OUT transform);
	AActor* Parent = Particles->GetAttachParentActor();
	if(Parent)
	{
		FTransform new_transform = FTransform(FQuat(StalkerMath::XRayQuatToUnreal(m)), FVector(StalkerMath::XRayLocationToUnreal(m.c)), Parent->GetActorScale());
		Parent->SetActorTransform(new_transform, false);
	}
	else
	{
		Particles->MoveComponent((FVector)StalkerMath::XRayLocationToUnreal(transform), Particles->GetComponentQuat(), false);
	}
}
void	UStalkerParticleSystemComponent::OnFrame(u32 dt)
{
	if (!Particles) { return; }
	return;
}

void	UStalkerParticleSystemComponent::Play()
{
	if(!Particles) {return;}

	Particles->Activate();
}
void	UStalkerParticleSystemComponent::Stop(BOOL bDefferedStop)
{
	if (!Particles) { return; }
	check(Particles);
	Particles->DeactivateImmediate();
}
BOOL	UStalkerParticleSystemComponent::IsPlaying()
{
	if (!Particles) { return false; }

	return Particles->GetAsset()->IsLooping();
}

u32		UStalkerParticleSystemComponent::ParticlesCount()
{
	if (!Particles) { return 0; }

	return Particles->GetAsset()->GetActiveInstancesCount();
}

float	UStalkerParticleSystemComponent::GetTimeLimit()
{
	if (!Particles) { return 0; }
	return Particles->GetMaxSimTime();
	//return Particles->GetAsset()->
}

const shared_str	UStalkerParticleSystemComponent::Name()
{
	return DataName;
}
void	UStalkerParticleSystemComponent::SetHudMode(BOOL b)
{
	
}
BOOL	UStalkerParticleSystemComponent::GetHudMode()
{
	return false;
}
