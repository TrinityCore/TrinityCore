#include "ScriptMgr.h"
#include "waycrest_manor.h"

enum Spells
{
	DARKENED_LIGHTNING = 266225,
	DARKENED_LIGHTNING_2 = 270464,

	SUMMON_DEATH_TOUCHED_SLAVER = 266266,
	SUMMON_DEATH_TOUCHED_SLAVER_MISSILE = 266260,
	DARK_LEAP = 273657,
	DARK_LEAP_2 = 273658,
	DREAD_BOLT = 266460,
	DREAD_ESSENCE = 266181,
	DREAD_ESSENCE_DISPELL = 272829,
	//Heroic+
	DEATH_LENS = 268202,
	DEATH_LENS_PERIODIC = 266724,
};

enum Events
{
	EVENT_DARKENED_LIGHTNING = 1,
	EVENT_DEATHTOUCHED_SLAVER,
	EVENT_DARK_LEAP,
	EVENT_DREAD_BOLT,
	EVENT_DREAD_ESSENCE,
	EVENT_DEATH_LENS,
};

enum Texts
{
	SAY_AGGRO = 0,
	SAY_RISE = 1,
	SAY_DEATH = 2,
};

//131864
struct boss_gorak_tul : public BossAI
{
	boss_gorak_tul(Creature* creature) : BossAI(creature, DATA_GORAK_TUL) { }

	void Reset()
	{
		BossAI::Reset();
		me->SetPowerType(POWER_LUNAR_POWER);
		me->SetPower(POWER_LUNAR_POWER, 1);
	}

	void EnterCombat(Unit* u) override
	{	
		_EnterCombat();
		Talk(SAY_AGGRO);
		events.ScheduleEvent(EVENT_DARKENED_LIGHTNING, 8s);
		events.ScheduleEvent(EVENT_DEATHTOUCHED_SLAVER, 13s);
		events.ScheduleEvent(EVENT_DREAD_ESSENCE, 24s);
	}

	void JustDied(Unit* u) override
	{
		Talk(SAY_DEATH);
		_JustDied();
		me->DespawnCreaturesInArea(NPC_DEATHTOUCHED_SLAVER);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
			case EVENT_DARKENED_LIGHTNING:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
			{
				DoCast(target, DARKENED_LIGHTNING);
				DoCast(target, DARKENED_LIGHTNING_2);
			}
			events.Repeat(15s);	
			break;

			case EVENT_DEATHTOUCHED_SLAVER:
		    DoCast(SUMMON_DEATH_TOUCHED_SLAVER);
			if (Creature* portal = me->FindNearestCreature(NPC_DRUSTWAR_SUMMONING_PORTAL, 100.0f, true))
			{
				me->CastSpell(portal, SUMMON_DEATH_TOUCHED_SLAVER_MISSILE);				
			}
			events.Repeat(20s);
			break;

			case EVENT_DREAD_ESSENCE:
			Talk(SAY_RISE);
			DoCastAOE(DREAD_ESSENCE);	
			events.Repeat(25s);
			break;
		}
	}

	void OnSpellFinished(SpellInfo const* spellInfo) override
	{
		switch (spellInfo->Id)
		{
		case DREAD_ESSENCE:
			 //CallDread();
			 break;

		default:
			break;
		}
	}

	void CallDread()
	{
		std::list<Creature*> c_li;
		me->GetCreatureListWithEntryInGrid(c_li, NPC_DEATHTOUCHED_SLAVER, 150.0f);
		for (auto & slaver : c_li)
		if (slaver->isDead())
		{
			slaver->Respawn();
			slaver->AI()->DoZoneInCombat();
		}
	}
};

//135552
struct npc_deathtouched_slaver : public ScriptedAI
{
	npc_deathtouched_slaver(Creature* c) : ScriptedAI(c) { }

	void IsSummonedBy(Unit* s) override
	{
		me->AI()->DoZoneInCombat();
	}

	void EnterCombat(Unit* u) override
	{
		events.ScheduleEvent(EVENT_DARK_LEAP, 3s);
		events.ScheduleEvent(EVENT_DREAD_BOLT, 6s);
		if (IsHeroic() || IsMythic())
			events.ScheduleEvent(EVENT_DEATH_LENS, 9s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_DARK_LEAP:
			if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 100.0f, true))
			{
				DoCast(target, DARK_LEAP);
				DoCast(target, DARK_LEAP_2);
			}
			events.Repeat(15s);
			break;

		case EVENT_DREAD_BOLT:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
			{
				DoCast(target, DREAD_BOLT);
			}
			events.Repeat(2s);
			break;

		case EVENT_DEATH_LENS:
			if (Unit* target = SelectTarget(SELECT_TARGET_FARTHEST, 0, 50.0f, true))
			{
				DoCast(target, DEATH_LENS);
				DoCast(target, DEATH_LENS_PERIODIC);
			}
			events.Repeat(20s);
			break;
		}
	}
};

void AddSC_boss_gorak_tul()
{
	RegisterCreatureAI(boss_gorak_tul);
	RegisterCreatureAI(npc_deathtouched_slaver);
}
