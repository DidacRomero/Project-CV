// Fill out your copyright notice in the Description page of Project Settings.


#include "EX_Stand.h"

// Sets default values
AEX_Stand::AEX_Stand()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEX_Stand::StartAnim()
{
	// ...
	if (curveFloat)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this, FName("TimelineProgress"));
		curveTimeline.AddInterpFloat(curveFloat, TimelineProgress);
		curveTimeline.SetLooping(false);

		startPos = endPos = GetActorLocation(); //This code can only run on AActor inherited c++ classes,, so I need to rewfactor the code
		endPos.Z += ZOffset;

		curveTimeline.PlayFromStart();
	}
}

void AEX_Stand::TimelineProgress(float val)
{
	FVector newPos = FMath::Lerp(startPos, endPos, val);
	SetActorLocation(newPos);
}

// Called when the game starts or when spawned
void AEX_Stand::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEX_Stand::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	curveTimeline.TickTimeline(DeltaTime);
}

