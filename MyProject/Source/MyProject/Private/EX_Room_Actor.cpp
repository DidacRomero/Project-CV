// Fill out your copyright notice in the Description page of Project Settings.


#include "EX_Room_Actor.h"
#include "StandActorComponent.h"
#include "GenericPlatform/GenericPlatformMath.h" 
#include "Kismet/KismetMathLibrary.h"
#include "EX_Stand.h"

// Sets default values
AEX_Room_Actor::AEX_Room_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//This function is my first ever test of spawning objects from a C++ clas in UE 
void AEX_Room_Actor::SpawnStands(unsigned int ammount)
{
	stands = ammount;
	finished_spawns = false;
}

inline float AEX_Room_Actor::TimeToSpawn()
{
	return total_sp_time / stands;
}

// Called when the game starts or when spawned
void AEX_Room_Actor::BeginPlay()
{
	Super::BeginPlay();
	SpawnStands(15);
}

// Called every frame
void AEX_Room_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (finished_spawns == false)
	{
		//Spawn Items over time
		if (sp_time >= TimeToSpawn())
		{
			UWorld* world = GetWorld();
			if (world)
			{
				if (StandBP != nullptr)
				{
					//FVector spawn_pos = FVector(0, 300.0f *sp_stands, 0);
					FVector spawn_pos = PosInCircle(sp_stands);

					//Prepeare spawn data
					FActorSpawnParameters params;
					params.Owner = this;

					FRotator rot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), spawn_pos);
					//Spawn Stands Here
					AActor* st = world->SpawnActor<AActor>(StandBP, spawn_pos, rot, params);
					AEX_Stand* bp = (AEX_Stand*)st;
					bp->StartAnim();
				}
			}
			sp_time = 0.0f;
			sp_stands++;
			if (sp_stands >= stands)
			{
				finished_spawns = true;
			}
		}
		sp_time += DeltaTime;
	}
}

//Given an index number of an array of numbers, calculate the position of that index so we have equidistant points on a circle of n indexes
FVector AEX_Room_Actor::PosInCircle(int id)
{
	FVector center = GetActorLocation();
	//Calculate the DEG angle distance between indexes. and its QuadrantTODO use a different method with arrays & array size, less hardcoded
	spacing_angle = 2*PI / stands;
	const float total_angle = spacing_angle * id; //Total angle of the circle

	//Calculate X & Y offset from the center, using basic trigonometry
	float y_offset = FGenericPlatformMath::Sin(total_angle);
	float x_offset = FGenericPlatformMath::Cos(total_angle);
	FVector v = FVector(x_offset, y_offset, 0.0f) * c_radius; // direction * displacement

	return center + v;
}

