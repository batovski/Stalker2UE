// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NiagaraComponent.h"
#include "Components/ActorComponent.h"
#include "NiagaraParticleSystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), Meta = (BlueprintSpawnableComponent, DisplayName = "Stalker Particle System Component"))
class STALKER_API UNiagaraParticleSystemComponent : public UNiagaraComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UNiagaraParticleSystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
