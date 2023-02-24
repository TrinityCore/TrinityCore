
#ifndef _BOT_ARENA_AI_
#define _BOT_ARENA_AI_

#include "BotAITool.h"
#include "BotAISpells.h"
#include "SpellMgr.h"
#include "PlayerBotSetting.h"
#include "GridNotifiers.h"
#include <mutex>

class Player;
class BotBGAIMovement;

class BotArenaAI : public PlayerAI
{
public:
	static BotArenaAI* CreateBotArenaAIByPlayerClass(Player* player);
	static BotArenaAI* debugArenaAI;

public:
	BotArenaAI(Player* player);
	~BotArenaAI();

	Player* GetAIPayer() { return me; }
	void UpdateAI(uint32 diff) override;
	virtual void ResetBotAI();
	void SetResetAI() { m_HasReset = false; }
	bool HasTeleport() { return !m_Teleporting.CanMovement(); }
	void SetTeleport(Position& telePos) { m_Teleporting.SetTeleport(telePos); }
    void SetTeleport(uint32 mapId, Position& telePos) { m_Teleporting.SetTeleport(mapId, telePos); }
	void UpdateTeleport(uint32 diff) { m_Teleporting.Update(diff, m_Movement); }
	bool IsBGSchedule();

protected:
	int32 m_UpdateTick;

	BotBGAIMovement* m_Movement;
	BotAIHorrorState* pHorrorState;
	BotAIStoped m_CheckStoped;
	BotAITeleport m_Teleporting;
	BotAIFlee m_Flee;

	bool m_HasReset;

	bool m_IsMeleeBot;
	bool m_IsRangeBot;
	bool m_IsHealerBot;

	std::mutex m_ItemLock;
};

#endif // _BOT_ARENA_AI_
