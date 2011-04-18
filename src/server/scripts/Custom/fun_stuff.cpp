// UPDATE `creature_template` SET ScriptName='npc_aliance_general' WHERE `entry`=70121;
#include "ScriptPCH.h"

class npc_aliance_general : public CreatureScript
{
public:
    npc_aliance_general() : CreatureScript("npc_aliance_general") { }

    CreatureAI* GetAI(Creature* pCreature)
    {
	return new npc_aliance_generalAI (pCreature);
    }

    struct npc_aliance_generalAI : public ScriptedAI
    {
	npc_aliance_generalAI(Creature *pCreature) : ScriptedAI(pCreature)
	{
            Reset();
	}

	uint32 spell1_phase1_Timer;
	uint32 spell1_phase2_Timer;
	uint32 spell1_phase3_Timer;
	uint32 spell1_phase4_Timer;
	uint32 phase1_Percent;
	uint32 phase2_Percent;
	uint32 phase3_Percent;
	uint32 phase4_Percent;
	uint32 phase;

	bool enraged;

	void EnterCombat(Unit *who)
	{
		me->MonsterSay("Браться, нас отакуют!", LANG_UNIVERSAL, NULL);
		DoCast(me->getVictim(), 26082);
	}

	void KilledUnit(Unit* victim)
	{
	}

	void JustDied(Unit* Killer)
	{
	}

	void Reset()
	{
		spell1_phase1_Timer = 9000+rand()%1000;
		spell1_phase2_Timer = 35000+rand()%15000;
		spell1_phase3_Timer = 50000+rand()%25000;
		spell1_phase4_Timer = 75000+rand()%24000;
		phase1_Percent = 10;
		phase2_Percent = 50;
		phase3_Percent = 75;
		phase4_Percent = 80;
		phase = 0;
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_SHADOW, true);
		me->ApplySpellImmune(100, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_FROST, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_FIRE, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NATURE, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_HOLY, true);
		me->ApplySpellImmune(300, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		enraged = false;
	}

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 35) && !enraged)
		{
			enraged = true;
			DoCast(me, 31884);
			me->MonsterSay("Сила света, дай мне свои крылья!", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 10) && phase == 0)
		{
			phase = 1;
			me->MonsterSay("Я погибаю, но перед этим я заберу вас с собой!", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 50) && phase == 1)
		{
			phase = 2;
			me->MonsterSay("Очистим землю от зла.", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 75) && phase == 2)
		{
			phase = 3;
			me->MonsterSay("Как вы посмели напасть на наши угодья, чернь!", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 80) && phase == 3)
		{
			phase = 4;
			me->MonsterSay("И враг наш падет от наших рук!", LANG_UNIVERSAL, NULL);
		}

		if (phase == 1)
		{

			if (spell1_phase1_Timer <= diff)
			{
				DoCast(me, 642);
				spell1_phase1_Timer = 9000+rand()%1000;
			} else spell1_phase1_Timer -= diff;
		}

		if (phase == 2)
		{

			if (spell1_phase2_Timer <= diff)
			{
				DoCast(me->getVictim(), 53385);
				spell1_phase2_Timer = 35000+rand()%15000;
			} else spell1_phase2_Timer -= diff;
		}

		if (phase == 3)
		{

			if (spell1_phase3_Timer <= diff)
			{
				DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true), 66965);
				spell1_phase3_Timer = 50000+rand()%25000;
			} else spell1_phase3_Timer -= diff;
		}

		if (phase == 4)
		{

			if (spell1_phase4_Timer <= diff)
			{
				DoCast(me->getVictim(), 35395);
				spell1_phase4_Timer = 75000+rand()%24000;
			} else spell1_phase4_Timer -= diff;
		}

		DoMeleeAttackIfReady();
	}
    };
};


// UPDATE `creature_template` SET ScriptName='npc_Horde General' WHERE `entry`=70120;
class npc_horde_general : public CreatureScript
{
public:
    npc_horde_general() : CreatureScript("npc_horde_general") { }

    CreatureAI* GetAI(Creature* pCreature)
    {
	return new npc_horde_generalAI (pCreature);
    }

    struct npc_horde_generalAI : public ScriptedAI
    {
	npc_horde_generalAI(Creature *pCreature) : ScriptedAI(pCreature)
	{
            Reset();
	}

	uint32 spell1_phase1_Timer;
	uint32 spell1_phase2_Timer;
	uint32 spell1_phase3_Timer;
	uint32 spell1_phase4_Timer;
	uint32 spell1_phase5_Timer;
	uint32 phase1_Percent;
	uint32 phase2_Percent;
	uint32 phase3_Percent;
	uint32 phase4_Percent;
	uint32 phase5_Percent;
	uint32 phase;

	void EnterCombat(Unit *who)
	{
		me->MonsterTextEmote(+ "Как вы посмели ступить сюда!", NULL, false);
		DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true), 26082);
	}

	void KilledUnit(Unit* victim)
	{
		me->MonsterSay("Огонь, сожги неверных!", LANG_UNIVERSAL, NULL);
		DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true), 66965);
	}

	void JustDied(Unit* Killer)
	{
	}

	void Reset()
	{
		spell1_phase1_Timer = 99000+rand()%1000;
		spell1_phase2_Timer = 50000+rand()%49000;
		spell1_phase3_Timer = 49000+rand()%1000;
		spell1_phase4_Timer = 34000+rand()%1000;
		spell1_phase5_Timer = 8000+rand()%2000;
		phase1_Percent = 100;
		phase2_Percent = 75;
		phase3_Percent = 50;
		phase4_Percent = 35;
		phase5_Percent = 10;
		phase = 0;
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_FROST, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_SHADOW, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_FIRE, true);
		me->ApplySpellImmune(200, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NATURE, true);
		me->ApplySpellImmune(100, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_HOLY, true);
		me->ApplySpellImmune(100, IMMUNITY_DAMAGE, 0, true);
		me->ApplySpellImmune(0, IMMUNITY_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, true);
		me->ApplySpellImmune(300, IMMUNITY_DAMAGE, 0, true);
	}

	void UpdateAI(const uint32 diff)
	{
		if (!UpdateVictim())
			return;

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 100) && phase == 0)
		{
			phase = 1;
			me->MonsterSay("Братья, в наше святилище проникли враги!", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 75) && phase == 1)
		{
			phase = 2;
			me->MonsterSay("Да окраситься мой клинок в кровавый цвет!", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 50) && phase == 2)
		{
			phase = 3;
			me->MonsterSay("И все наши враги падут...", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 35) && phase == 3)
		{
			phase = 4;
			me->MonsterSay("Мой клинок, помоги мне в этой битве!", LANG_UNIVERSAL, NULL);
		}

		if ((me->GetHealth() * 100 / me->GetMaxHealth() <= 10) && phase == 4)
		{
			phase = 5;
			me->MonsterSay("Нас много, ибо имя нам ЛЕГИОН...", LANG_UNIVERSAL, NULL);
		}

		if (phase == 1)
		{

			if (spell1_phase1_Timer <= diff)
			{
				DoCast(me, 469);
				spell1_phase1_Timer = 99000+rand()%1000;
			} else spell1_phase1_Timer -= diff;
		}

		if (phase == 2)
		{

			if (spell1_phase2_Timer <= diff)
			{
				DoCast(SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true), 67031);
				spell1_phase2_Timer = 50000+rand()%49000;
			} else spell1_phase2_Timer -= diff;
		}

		if (phase == 3)
		{

			if (spell1_phase3_Timer <= diff)
			{
				DoCast(me, 76307);
				spell1_phase3_Timer = 49000+rand()%1000;
			} else spell1_phase3_Timer -= diff;
		}

		if (phase == 4)
		{

			if (spell1_phase4_Timer <= diff)
			{
				DoCast(me, 41107);
				spell1_phase4_Timer = 34000+rand()%1000;
			} else spell1_phase4_Timer -= diff;
		}

		if (phase == 5)
		{

			if (spell1_phase5_Timer <= diff)
			{
				DoCast(me, 25807);
				spell1_phase5_Timer = 8000+rand()%2000;
			} else spell1_phase5_Timer -= diff;
		}

		DoMeleeAttackIfReady();
	}
    };
};


void AddSC_fun_stuff()
{
    new npc_aliance_general;
    new npc_horde_general;
}