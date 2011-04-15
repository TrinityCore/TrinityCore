// Script Generated: 08.04.2011 17:30:50
// Run this query on your world database
// UPDATE `creature_template` SET ScriptName='npc_Raeudiger_Wolf' WHERE `entry`=525;
#include "ScriptPCH.h"


class npc_Raeudiger_Wolf : public CreatureScript
{
public:
    npc_Raeudiger_Wolf() : CreatureScript("npc_Raeudiger_Wolf") { }

    CreatureAI* GetAI(Creature *_Creature) const
    {
        return new npc_Raeudiger_WolfAI (_Creature);
    }

    struct npc_Raeudiger_WolfAI : public ScriptedAI
    {
        npc_Raeudiger_WolfAI(Creature *c) : ScriptedAI(c) { }
			uint32 spell1_phase1_Timer;
	uint32 spell2_phase1_Timer;
	uint32 spell1_phase2_Timer;
	uint32 spell1_phase3_Timer;
	uint32 phase1_Percent;
	uint32 phase2_Percent;
	uint32 phase3_Timer;
	uint32 phase;


	void EnterCombat(Unit *who)
	{
		me->MonsterYell("Euer Blut wird den Boden tränken!", LANG_UNIVERSAL, NULL);
		DoCast(me->getVictim(), 774);
	}

	void KilledUnit(Unit* victim)
	{
	}

	void JustDied(Unit* Killer)
	{
		me->MonsterYell("LoL was habt ihr getan?", LANG_UNIVERSAL, NULL);
	}

	void Reset()
	{
		spell1_phase1_Timer = 1000+rand()%29000;
		spell2_phase1_Timer = 1000+rand()%9000;
		spell1_phase2_Timer = 2000+rand()%22000;
		spell1_phase3_Timer = 1000+rand()%4000;
		phase1_Percent = 80;
		phase2_Percent = 50;
		phase3_Timer = 300000;
		phase = 0;
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, true);
	}

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 80) && phase == 0)
		{
			phase = 1;
			me->MonsterYell("Ich werde euch den Leib aufreißen", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 50) && phase == 1)
		{
			phase = 2;
			me->MonsterYell("Eure Knochen werden Schmerzen", LANG_UNIVERSAL, NULL);
		}

		if (phase == 2)
		{
			if (phase3_Timer <= diff)
			{
				phase = 3;
				me->MonsterYell("Jetzt esse ich euch!", LANG_UNIVERSAL, NULL);
			}
			else phase3_Timer -= diff;
		}

		if (phase == 1)
		{

			if (spell1_phase1_Timer <= diff)
			{
				DoCast(me->getVictim(), 2142);
				spell1_phase1_Timer = 1000+rand()%29000;
			} else spell1_phase1_Timer -= diff;

			if (spell2_phase1_Timer <= diff)
			{
				DoCast(me->getVictim(), 3324);
				spell2_phase1_Timer = 1000+rand()%9000;
			} else spell2_phase1_Timer -= diff;
		}

		if (phase == 2)
		{

			if (spell1_phase2_Timer <= diff)
			{
				DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true), 445);
				spell1_phase2_Timer = 2000+rand()%22000;
			} else spell1_phase2_Timer -= diff;
		}

		if (phase == 3)
		{

			if (spell1_phase3_Timer <= diff)
			{
				DoCast(me, 64238);
				spell1_phase3_Timer = 1000+rand()%4000;
			} else spell1_phase3_Timer -= diff;
		}

		DoMeleeAttackIfReady();
	}
    };
};

void AddSC_Raeudiger_Wolf()
{
    new npc_Raeudiger_Wolf();
}
