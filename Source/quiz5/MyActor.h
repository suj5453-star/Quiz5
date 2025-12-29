#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class QUIZ5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;	// Called every frame
	void Move();
	void Turn();
	void EventOccur();
	void TriggerEventWithProbability(float probability);
	void RandPlay();
	FTimerHandle ThreeSecondsTimerHandle;
	int EventCount = 0;
	int MoveCount = 0;
	int SpinCount = 0;
	int RepetitionsLeft = 10;
	float DTime = 0;

};
