// Script Generated: 08.04.2011 17:30:50
// Run this query on your world database
// UPDATE `creature_template` SET ScriptName='npc_Raeudiger_Wolf' WHERE `entry`=525;
#include "ScriptPCH.h"


struct Raeudiger WolfAI : public ScriptedAI
{
	Raeudiger WolfAI(Creature *c) : ScriptedAI(c)
	{
	}

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
		m_creature->MonsterYell("Euer Blut wird den Boden tränken!", LANG_UNIVERSAL, NULL);
		DoCast(m_creature->getVictim(), 774);
	}

	void KilledUnit(Unit* victim)
	{
	}

	void JustDied(Unit* Killer)
	{
		m_creature->MonsterYell("LoL was habt ihr getan?", LANG_UNIVERSAL, NULL);
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
		m_creature->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, true);
	}

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;

		if ((m_creature->GetHealth() * 100 / m_creature->GetMaxHealth() <= 80) && phase == 0)
		{
			phase = 1;
			m_creature->MonsterYell("Ich werde euch den Leib aufreißen", LANG_UNIVERSAL, NULL);
		}

		if ((m_creature->GetHealth() * 100 / m_creature->GetMaxHealth() <= 50) && phase == 1)
		{
			phase = 2;
			m_creature->MonsterYell("Eure Knochen werden Schmerzen", LANG_UNIVERSAL, NULL);
		}

		if (phase == 2)
		{
			if (phase3_Timer <= diff)
			{
				phase = 3;
				m_creature->MonsterYell("Jetzt esse ich euch!", LANG_UNIVERSAL, NULL);
			}
			else phase3_Timer -= diff;
		}

		if (phase == 1)
		{

			if (spell1_phase1_Timer <= diff)
			{
				DoCast(m_creature->getVictim(), 2142);
				spell1_phase1_Timer = 1000+rand()%29000;
			} else spell1_phase1_Timer -= diff;

			if (spell2_phase1_Timer <= diff)
			{
				DoCast(m_creature->getVictim(), 3324);
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
				DoCast(m_creature, 64238);
				spell1_phase3_Timer = 1000+rand()%4000;
			} else spell1_phase3_Timer -= diff;
		}

		DoMeleeAttackIfReady();
	}
};

CreatureAI* GetAIRaeudiger Wolf(Creature* pCreature)
{
	return new Raeudiger WolfAI (pCreature);
}

void AddSC_Raeudiger Wolf()
{
	Script *newscript;
	newscript = new Script;
	newscript->Name = "npc_Raeudiger Wolf";
	newscript->GetAI = &GetAIRaeudiger Wolf;
	newscript->RegisterSelf();
}