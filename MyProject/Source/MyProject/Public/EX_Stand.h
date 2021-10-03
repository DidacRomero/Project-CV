// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "EX_Stand.generated.h"

UCLASS()
class MYPROJECT_API AEX_Stand : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEX_Stand();

	void StartAnim();


	UFUNCTION()
		void TimelineProgress(float val);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimeline curveTimeline;
	UPROPERTY(EditAnywhere, Category = "Timeline");
	UCurveFloat* curveFloat;

	UPROPERTY();
	FVector startPos;
	UPROPERTY();
	FVector endPos;

	//Since this is a component, to get actor pos we

	UPROPERTY(EditAnywhere, Category = "Timeline")
		float ZOffset;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
