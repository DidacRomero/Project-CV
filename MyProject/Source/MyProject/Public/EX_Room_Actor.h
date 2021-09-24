// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EX_Room_Actor.generated.h"

UCLASS()
class MYPROJECT_API AEX_Room_Actor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEX_Room_Actor();
	void SpawnStands(unsigned int ammount);
	inline float TimeToSpawn();
	

	UPROPERTY(EditAnywhere);
	TSubclassOf <class AActor> StandBP = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	unsigned int stands = 0;
	unsigned int sp_stands = 0; //Spawned stands
	bool finished_spawns = true;
	float total_sp_time = 2.0f;
	float sp_time = 0.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
