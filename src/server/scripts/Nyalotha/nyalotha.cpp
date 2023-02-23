#include "nyalotha.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"

//500501
struct go_nyalotha_entrance : public GameObjectAI
{
	go_nyalotha_entrance(GameObject* go) : GameObjectAI(go) { timer = 1500; }

	void UpdateAI(uint32 diff) override
	{
		if (timer <= diff)
		{
			std::list<Player*> players;
		//	go->GetPlayerListInGrid(players, 5.f);
			for (Player* plr : players)
			{	
				if (plr->GetLevel() >= 120 && plr->GetMapId() != 2217 && !plr->IsInCombat())
				{
                    /*plr->GetScheduler().Schedule(100ms, [plr](TaskContext context)
					{
                        plr->TeleportTo(2217, -1799.0f, -43.0f, -1476.0f, 6.24f);
					});*/
				}
                if (plr->GetLevel() >= 120 && plr->GetMapId() == 2217 && !plr->IsInCombat())
                {
					/*plr->GetScheduler().Schedule(100ms, [plr](TaskContext context)
                    {
                        plr->TeleportTo(870, 1138.0f, 1361.0f, 349.4f, 4.76f);
                    });*/
                }
			}
		}
		else
		timer -= diff;
	}

private:
	uint32 timer;
};

enum 
{
	ACTION_NZOTH_TALK,
	ACTION_WRATHION_TALK,
};

const Position annex_of_prophecy_first_elevator_pos = { -1099.468f, -45.313f, -237.333f, 0.043f };

//161720, used as custom mini event because of first elevator
struct npc_wrathion_special : public ScriptedAI
{
	npc_wrathion_special(Creature* c) : ScriptedAI(c) { }

private:
	bool Talk;

	void Reset() override
	{
		ScriptedAI::Reset();
		Talk = false;
		me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
	}

	void MoveInLineOfSight(Unit* who) override
	{
		if (!Talk && who->IsPlayer() && who->GetDistance2d(me) <= 15.0f)
		{
			Talk = true;

			if (Talk)
				me->Say("Champions! I will lead you to the top.", LANG_UNIVERSAL);
		}
	}

private:
    InstanceScript* instance;
};

//500528
struct npc_generic_bunny_nyalotha : public ScriptedAI
{
	npc_generic_bunny_nyalotha(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
	}

	void MoveInLineOfSight(Unit* target) override
	{
		if (!target->IsPlayer())
			return;

		if (me->GetDistance2d(target) <= 10.0f)
			if (instance->GetBossState(DATA_VEXIONA) == DONE && instance->GetBossState(DATA_RADEN) == DONE && instance->GetBossState(DATA_HIVEMIND) == DONE && instance->GetBossState(DATA_DRESTAGATH) == DONE)
				target->NearTeleportTo(-11681.565f, 9313.876f, 130.329f, 0.04f, false);
	}
private:
    InstanceScript* instance;
};

void AddSC_nyalotha()
{
	RegisterGameObjectAI(go_nyalotha_entrance);
	RegisterCreatureAI(npc_wrathion_special);
	RegisterCreatureAI(npc_generic_bunny_nyalotha);
}

