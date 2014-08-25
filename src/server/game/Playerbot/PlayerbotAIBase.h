#pragma once

class Player;
class PlayerbotMgr;
class ChatHandler;

using namespace std;

class PlayerbotAIBase
{
public:
	PlayerbotAIBase();

public:
	bool CanUpdateAI();
	void SetNextCheckDelay(const uint32 delay);
    void IncreaseNextCheckDelay(uint32 delay);
	void YieldThread();
    virtual void UpdateAI(uint32 elapsed);
    virtual void UpdateAIInternal(uint32 elapsed) = 0;

protected:
	uint32 nextAICheckDelay;
};
