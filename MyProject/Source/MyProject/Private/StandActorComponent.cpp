// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TimelineComponent.h"
#include "StandActorComponent.h"

// Sets default values for this component's properties
UStandActorComponent::UStandActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UStandActorComponent::TimelineProgress(float val)
{
	FVector newPos = FMath::Lerp(startPos,endPos, val);
	if(owner != nullptr)
	owner->SetActorLocation(newPos); //This code can only run on AActor inherited c++ classes,, so I need to rewfactor the code
}

// Called when the game starts
void UStandActorComponent::BeginPlay()
{
	Super::BeginPlay();

	//Get the actor in which we're a component
	owner = this->GetOwner();

	// ...
	if (curveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this, FName("TimelineProgress"));
		curveTimeline.AddInterpFloat(curveFloat, TimelineProgress);
		curveTimeline.SetLooping(true);

		if(owner != nullptr)
		startPos = endPos = owner->GetActorLocation(); //This code can only run on AActor inherited c++ classes,, so I need to rewfactor the code
		endPos.Z += ZOffset;

		curveTimeline.PlayFromStart();
	}
}


// Called every frame
void UStandActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	curveTimeline.TickTimeline(DeltaTime);
}

