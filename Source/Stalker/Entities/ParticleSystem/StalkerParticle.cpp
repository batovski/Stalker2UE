// Fill out your copyright notice in the Description page of Project Settings.


#include "Entities/ParticleSystem/StalkerParticle.h"

#include "NiagaraComponent.h"

// Sets default values for this component's properties
AStalkerParticle::AStalkerParticle()
{
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
	VisData.clear();
	Particles = nullptr;
}

// Called when the game starts or when spawned
void AStalkerParticle::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStalkerParticle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AStalkerParticle::Init(UNiagaraComponent* NiagaraComponent)
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
vis_data& _BCL			AStalkerParticle::getVisData()
{
	return VisData;
}
u32						AStalkerParticle::getType()
{
	return 0;
}

shared_str	_BCL			AStalkerParticle::getDebugName()
{
	return DataName;
}
IParticleCustom* AStalkerParticle::dcast_ParticleCustom()
{
	return this;
}
void			AStalkerParticle::Detach()
{
	
}

//IParticleCustom
void 	AStalkerParticle::OnDeviceCreate()
{
	
}
void 	AStalkerParticle::OnDeviceDestroy()
{
	//Is thar right to delete Particles onne device is destroyed? 
	if (Particles)
	{
		check(Particles);
		Particles->DestroyInstance();
	}

	Destroy();
}

void	AStalkerParticle::UpdateParent(const Fmatrix& m, const Fvector& velocity, BOOL bXFORM)
{
	if (!Particles) { return; }

	Fvector transform;
	m.transform(OUT transform);
	//TODO:: fix scale based on the matrix
	FTransform new_transform = FTransform(FQuat(StalkerMath::XRayQuatToUnreal(m)), FVector(StalkerMath::XRayLocationToUnreal(m.c)), GetActorScale());
	SetActorTransform(new_transform, false);
}
void	AStalkerParticle::OnFrame(u32 dt)
{
	if (!Particles) { return; }
	return;
}

void	AStalkerParticle::Play()
{
	if(!Particles) {return;}
	check(Particles);

	Particles->Activate();
}
void	AStalkerParticle::Stop(BOOL bDefferedStop)
{
	if (!Particles) { return; }
	check(Particles);
	Particles->DeactivateImmediate();
}
BOOL	AStalkerParticle::IsPlaying()
{
	if (!Particles) { return false; }
	check(Particles);
	return Particles->GetAsset()->IsLooping();
}

u32		AStalkerParticle::ParticlesCount()
{
	if (!Particles) { return 0; }
	check(Particles);
	return Particles->GetAsset()->GetActiveInstancesCount();
}

float	AStalkerParticle::GetTimeLimit()
{
	if (!Particles) { return 0; }
	check(Particles);
	return Particles->GetMaxSimTime();
}

const shared_str	AStalkerParticle::Name()
{
	return DataName;
}
void	AStalkerParticle::SetHudMode(BOOL b)
{
	//Not sure what to do here
}
BOOL	AStalkerParticle::GetHudMode()
{
	return false;
}
