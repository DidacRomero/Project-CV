// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class MYPROJECT_API EXRoom : public UActorComponent
{
public:
	EXRoom();
	~EXRoom();

	void SpawnStands();

protected:
	virtual void BeginPlay() override;


private:

};
