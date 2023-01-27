#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedGossip.h"
#include "eternal_palace.h"

enum
{
	SPELL_ARCANE_PROJECTION = 303674,
	SPELL_RAGE_OF_AZSHARA = 300997,
	SPELL_ASHVANES_ASCENSION = 302976,
};

const Position szalira_impact_pos = { 767.0f, 635.0f, 1289.0f, 0.62f };

//154480, Queen Azshara
struct npc_queen_azshara_154480 : public ScriptedAI
{
	npc_queen_azshara_154480(Creature* c) : ScriptedAI(c), state_first_wing(false) { }

	void Reset() override
	{
		me->AddAura(SPELL_ARCANE_PROJECTION, me);		
	}

	//I had some issues with pre-event, so i used this
	void sGossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
	{
		CloseGossipMenuFor(player);
		me->HasUnitFlag(UNIT_FLAG_NOT_SELECTABLE);

		if (instance->GetBossState(DATA_COMMANDER_SIVARA) == DONE && me->FindNearestCreature(NPC_SZALIRA, 25.0f, true))
		{
			//The ritual has begun! We all have our parts to play. Isn't that so, my child?
			Talk(0);
			if (Creature* szalira = me->FindNearestCreature(NPC_SZALIRA, 50.0f, true))
			{
				szalira->GetScheduler().Schedule(9s, [this, szalira](TaskContext context)
				{
					//Yes, my queen. I sacrifice all that I am to serve you!
					szalira->AI()->Talk(0);
				});

				me->GetScheduler().Schedule(17s, [this, szalira](TaskContext context)
				{
					//Gaze upon true devotion, landwalkers! Behold the rage of a queen!
					me->AI()->Talk(1);
					me->AddAura(SPELL_RAGE_OF_AZSHARA, szalira);
					//szalira->GetMotionMaster()->MoveJump(szalira_impact_pos, 15.0f, 15.0f);
				});

				if (Creature* radiance = me->FindNearestCreature(NPC_RADIANCE_OF_AZSHARA, 100.0f, true))
				{
					radiance->GetScheduler().Schedule(27s, [this, radiance, szalira](TaskContext context)
					{
						szalira->KillSelf(true);
						radiance->SetVisible(true);
						DoCast(SPELL_ARCANE_PROJECTION);
						me->DespawnOrUnsummon(2s);
					});
				}
			}
		}
	}

private:
    InstanceScript* instance;
    EventMap events;
	bool state_first_wing;
};

void AddSC_eternal_palace()
{
	RegisterCreatureAI(npc_queen_azshara_154480);
}

