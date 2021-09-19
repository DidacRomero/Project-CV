// Fill out your copyright notice in the Description page of Project Settings.


#include "EX_Room_Actor.h"

// Sets default values
AEX_Room_Actor::AEX_Room_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

//This function is my first ever test of spawning objects from a C++ clas in UE 
void AEX_Room_Actor::SpawnStands()
{
	UWorld* world = GetWorld();
	if (world)
	{
		if (StandBP != nullptr)
		{
			FVector pos_offset = FVector(0, 300, 0);
			FVector spawn_pos = FVector(0, 0, 0);

			for (int i = 0; i < 10; ++i)
			{
				//Prepeare spawn data
				FActorSpawnParameters params;
				params.Owner = this;

				FRotator rot;
				//Spawn Stands Here
				world->SpawnActor<AActor>(StandBP, spawn_pos, rot, params);
				spawn_pos += pos_offset;
			}
		}
	}
}

// Called when the game starts or when spawned
void AEX_Room_Actor::BeginPlay()
{
	Super::BeginPlay();
	SpawnStands();
}

// Called every frame
void AEX_Room_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

