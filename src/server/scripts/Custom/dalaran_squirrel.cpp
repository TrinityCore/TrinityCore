/********************************************
*                                           *
*         	WoW ALive                   *
*        Dalaran Squirrel Script            * 
*                                           *
*********************************************/


#include "ScriptPCH.h"

enum NPCs
{
NPC_DALARAN_SQUIRREL = 666666,
NPC_DALARAN_SQUIRREL_SUMMON = 666667,
};

class npc_dalaran_squirrel : public CreatureScript
{
public:
    npc_dalaran_squirrel() : CreatureScript("npc_dalaran_squirrel") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_dalaran_squirrelAI (creature);
    }

    struct npc_dalaran_squirrelAI : public ScriptedAI
    {
		npc_dalaran_squirrelAI(Creature* c) : ScriptedAI(c), summons(c) {}

		Unit* attacker;
		SummonList summons;

		void Reset()
        {
			summons.DespawnAll();
		}

		void EnterCombat(Unit* /*who*/)
        {
			me->MonsterSay("I would not have done that if I was in your place...", LANG_UNIVERSAL, 0);
			for(int i = 0; i < 19; i++)
				{
					me->SummonCreature(NPC_DALARAN_SQUIRREL_SUMMON, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ());
				}
		}

		void JustDied(Unit* /*victim*/)
        {
			me->Respawn();				
			me->CombatStart(attacker);
		}
		
		void JustSummoned(Creature* summon)
            {
				summons.Summon(summon);
				if(Unit* target = me->getVictim())
				{
					if(target->isTotem() || target ->isPet())
					{
						target = target->GetOwner();
					}
				summon->AI()->AttackStart(target);
				}
			}

		 void UpdateAI(const uint32 diff)
        {
			if (!UpdateVictim())
				return;
			
			if(Unit* target = me->getVictim())
			{
				if(target->isTotem() || target->isPet())
				{
					target = target->GetOwner();
				}
				attacker = target;
				DoMeleeAttackIfReady();
			}
		}
	};
};

void AddSC_dalaran_squirrel()
{
	new npc_dalaran_squirrel();
}