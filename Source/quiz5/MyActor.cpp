#include "MyActor.h"
#include "Engine/Engine.h"


AMyActor::AMyActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0, 0, 0));
	SetActorRotation(FRotator(0.f, 0.f, 0.f));

	FVector Actorlocation = GetActorLocation();

	if (GEngine) // 유효성 검사
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Blue, TEXT("Hi"));

		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("Actor: %s"), *GetName()));
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, FString::Printf(TEXT("Location: %s"), *Actorlocation.ToString()));

		GetWorldTimerManager().SetTimer(ThreeSecondsTimerHandle, this, &AMyActor::RandPlay, 3.0f, true);

		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 30.0f, FColor::Yellow, FString::Printf(TEXT("EventCount: %d"), &EventCount));
		}
	}
}

void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DTime += DeltaTime;
}

void AMyActor::TriggerEventWithProbability(float Probability)
{
	int RandValue = FMath::RandRange(1, 100);

	if (RandValue <= Probability)
	{
		UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
		EventOccur();
		EventCount++;
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
	}
}

void AMyActor::Move()
{
	int32 X = FMath::RandRange(-500, 500);
	int32 Y = FMath::RandRange(-500, 500);
	int32 Z = FMath::RandRange(-100, 900);

	SetActorLocation(FVector(X, Y, Z));

	FVector Actorlocation = GetActorLocation();

	MoveCount++;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, FString::Printf(TEXT("Location: %s"), *Actorlocation.ToString()));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("MoveCount: %d"), MoveCount));

		TriggerEventWithProbability(50.f);
	}
}

void AMyActor::Turn() {
	SetActorRotation(FRotator(100.f, 100.f, 100.f));

	SpinCount++;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("The actor is spinned"));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, FString::Printf(TEXT("SpinCount: %d"), SpinCount));
	}
}

void AMyActor::RandPlay()
{
	int32 Rand = FMath::RandRange(1, 2);

	if (Rand == 1) {
		AMyActor::Move();
	}
	else {
		AMyActor::Turn();
	}

	RepetitionsLeft--;

	if (RepetitionsLeft <= 0)
	{
		GetWorldTimerManager().ClearTimer(ThreeSecondsTimerHandle);
	}
}

void AMyActor::EventOccur()
{
	int32 Event = FMath::RandRange(1, 3);

	if (Event == 1)
	{
		SetActorRotation(FRotator(100.f, 0.f, 0.f));
	}
	else if (Event == 2)
	{
		SetActorRotation(FRotator(0.f, 100.f, 0.f));
	}
	else
	{
		SetActorRotation(FRotator(0.f, 0.f, 100.f));
	}
}





