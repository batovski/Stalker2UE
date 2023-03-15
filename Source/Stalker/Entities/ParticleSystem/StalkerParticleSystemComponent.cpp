// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/ParticleSystem/StalkerParticleSystemComponent.h"

// Sets default values for this component's properties
UStalkerParticleSystemComponent::UStalkerParticleSystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	VisData.clear();

	// ...
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
	
}

void	UStalkerParticleSystemComponent::UpdateParent(const Fmatrix& m, const Fvector& velocity, BOOL bXFORM)
{
	
}
void	UStalkerParticleSystemComponent::OnFrame(u32 dt)
{
	
}

void	UStalkerParticleSystemComponent::Play()
{
	
}
void	UStalkerParticleSystemComponent::Stop(BOOL bDefferedStop)
{
	
}
BOOL	UStalkerParticleSystemComponent::IsPlaying()
{
	return false;
}

u32		UStalkerParticleSystemComponent::ParticlesCount()
{
	return u32(0);
}

float	UStalkerParticleSystemComponent::GetTimeLimit()
{
	return 0.;
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
