#include "ScriptMgr.h"
#include "waycrest_manor.h"

enum Spells
{
	SOUL_HARVEST = 260512,
	CRUSH = 260508,
	SOUL_THORNS = 260551,
	SOUL_THORNS_SPAWN_EFECT = 267912,
	SOUL_THORNS_MAIN = 267907,
	BURNING_BRUSH_AURA = 260541,
	BURNING_FISTS = 272668,
};

enum Events
{
	EVENT_SOUL_HARVEST = 1,
	EVENT_CRUSH,
	EVENT_SOUL_THORNS,
	EVENT_BURNING_BRUSH,
	EVENT_BURNING_SOUL_KILL
};

enum Texts
{
	SAY_AGGRO = 9,
	SAY_DEATH = 8,
	SAY_THORNS = 1,
	SAY_WARNING_SOUL_THORNS = 2,
	SAY_WARNING_SOUL_HARVEST = 3,
	SAY_FIRE = 7,
};

const Position burning_soul_pos = { -409.0f, -261.0f, 234.0f, 3.0f };

//131667
struct boss_soulbound_goliath : public BossAI
{
	boss_soulbound_goliath(Creature* creature) : BossAI(creature, DATA_SOULBOUND_GOLIATH) { }

	void Reset() override
	{
		BossAI::Reset();
		me->SetReactState(REACT_DEFENSIVE);
		me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
		me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
	}

	void EnterCombat(Unit* u) override
	{
		Talk(SAY_AGGRO);
		_EnterCombat();
		Talk(SAY_WARNING_SOUL_HARVEST);
		events.ScheduleEvent(EVENT_SOUL_HARVEST, 100ms);
		events.ScheduleEvent(EVENT_CRUSH, 3s);
		events.ScheduleEvent(EVENT_SOUL_THORNS, 6s);
		events.ScheduleEvent(EVENT_BURNING_BRUSH, 15s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_SOUL_HARVEST:
			me->AddAura(SOUL_HARVEST, me);
			events.Repeat(2s);
			break;

		case EVENT_CRUSH:
			if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO, 0, 8.0f, true))
			DoCast(target, CRUSH);
			events.Repeat(15s);
			break;

		case EVENT_SOUL_THORNS:
			//Talk(SAY_WARNING_SOUL_THORNS);
			Talk(SAY_THORNS);
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
			{
				me->AddAura(SOUL_THORNS_MAIN, target);
				if (target->HasAura(SOUL_THORNS_MAIN))
					target->SummonCreature(NPC_SOUL_THORNS, target->GetPositionX() + 0, target->GetPositionY() + 0, target->GetPositionZ() + 0);
			}
			events.Repeat(25s);
			break;

		case EVENT_BURNING_BRUSH:
			Talk(SAY_FIRE);
			me->CastSpell(me, BURNING_BRUSH_AURA);			
			me->RemoveAurasDueToSpell(SOUL_HARVEST);
			//On Heroic difficulty, when the The Soulbound Goliath runs into fire and gains Burning Brush it will spawn many Burning Souls adds.
			if (IsHeroic() || IsMythic())
			{
				for (uint8 i = 0; i < 6; i++)
				{
					me->SummonCreature(NPC_BURNING_SOUL, me->GetRandomPoint(burning_soul_pos, 10.0f));
				}
			}
			events.Repeat(30s);
			break;

		default:
			break;
		}
	}

	void JustReachedHome() override
	{
		_JustReachedHome();
		me->DespawnCreaturesInArea(NPC_BURNING_SOUL, 125.0f);
		me->DespawnCreaturesInArea(NPC_SOUL_THORNS, 125.0f);
	}

	void JustDied(Unit* u) override
	{
		Talk(SAY_DEATH);
		_JustDied();
		me->DespawnCreaturesInArea(NPC_BURNING_SOUL, 125.0f);
		me->DespawnCreaturesInArea(NPC_SOUL_THORNS, 125.0f);
		instance->SetBossState(DATA_SOULBOUND_GOLIATH, DONE);
	}
};

//136330
struct npc_soul_thorns : public ScriptedAI
{
	npc_soul_thorns(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		me->SetReactState(REACT_PASSIVE);
		me->CastSpell(me, SOUL_THORNS_SPAWN_EFECT);
	}

	void JustDied(Unit* u) override
	{
		std::list<Player*> p_list;
		me->GetPlayerListInGrid(p_list, 3.0f);
		for (auto & players : p_list)
		if (players->HasAura(SOUL_THORNS_MAIN))
			players->RemoveAura(SOUL_THORNS_MAIN);
	}
};

//136436
struct npc_burning_soul : public ScriptedAI
{
	npc_burning_soul(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
		if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
		{
			me->GetMotionMaster()->MoveChase(target);
			me->SetWalk(true);
			me->UpdateSpeed(MOVE_WALK);
		}
	}

	void IsSummonedBy(Unit* s) override
	{		
		me->CastSpell(me, BURNING_FISTS);
		me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
		events.ScheduleEvent(EVENT_BURNING_SOUL_KILL, 10s);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_BURNING_SOUL_KILL:
			 me->KillSelf();
			 break;
		}
	}
};

void AddSC_boss_soulbound_goliath()
{
	RegisterCreatureAI(boss_soulbound_goliath);
	RegisterCreatureAI(npc_soul_thorns);
	RegisterCreatureAI(npc_burning_soul);
}
