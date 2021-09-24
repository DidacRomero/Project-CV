// Fill out your copyright notice in the Description page of Project Settings.


#include "EX_Room_Actor.h"

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
	SpawnStands(10);
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
					FVector spawn_pos = FVector(0, 300.0f *sp_stands, 0);

					//Prepeare spawn data
					FActorSpawnParameters params;
					params.Owner = this;

					FRotator rot = FRotator(0.0f);
					//Spawn Stands Here
					world->SpawnActor<AActor>(StandBP, spawn_pos, rot, params);
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

