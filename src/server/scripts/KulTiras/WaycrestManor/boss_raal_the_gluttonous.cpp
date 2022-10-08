#include "ScriptMgr.h"
#include "waycrest_manor.h"

enum Spells
{
	TENDERIZE = 264923,
	TENDERIZE_DAMAGE = 262371,
	CONSUME_ALL = 264734,
	CALL_SERVANT = 264931,
	CONSUME_SERVANT_INSTAKILL = 265002,
	CONSUME_SERVANT_BUFF = 265005,
	ROTTEN_EXPULSION = 264694,
	ROTTEN_EXPULSION_MISSILE = 264697,
	ROTTEN_EXPULSION_AT = 264698 , // at 12821
	ROTTEN_EXPULSION_AT_AURA = 264712,
	ROTTEN_EXPULSION_SUMMON = 268231,
	BILE_EXPOLOSION
};

enum Events
{
	EVENT_TENDERIZE = 1,
	EVENT_CONSUME_ALL,
	EVENT_CALL_SERVANT,
	EVENT_ROTTEN_EXPULSION,
	EVENT_CHECK_RANGE,
	EVENT_NO_HOSTILES
};

enum Texts
{
	SAY_AGGRO = 0,
	SAY_WARNING_SERVANT = 1,
	SAY_SERVANT = 2,
	SAY_DEATH = 3,
};

const Position servant_left_pos = { -461.0f, -330.0f, 237.0f, 3.1f };
const Position servant_middle_pos = { -481.0f, -308.0f, 237.0f, 4.7f };
const Position servant_right_pos = { -525.0f, -330.0f, 237.0f, 0.0f };
const Position bile_oozeling_pos = { -493.0f, -328.0f, 236.0f, 4.69f };

//131863
struct boss_raal_the_gluttonous : public BossAI
{
	boss_raal_the_gluttonous(Creature* creature) : BossAI(creature, DATA_RAAL_THE_GLUTTONOUS) { }

	void Reset() override
	{
		BossAI::Reset();
		me->SetReactState(REACT_AGGRESSIVE);
		me->AddUnitState(UNIT_STATE_ROOT);
		SetCombatMovement(false);
	}

	void EnterCombat(Unit* target) override
	{
		Talk(SAY_AGGRO);
		_EnterCombat();
		instance->SetBossState(DATA_RAAL_THE_GLUTTONOUS, IN_PROGRESS);
		events.ScheduleEvent(EVENT_CHECK_RANGE, 1s);
		events.ScheduleEvent(EVENT_TENDERIZE, 3s);		
		events.ScheduleEvent(EVENT_ROTTEN_EXPULSION, 6s);
		events.ScheduleEvent(EVENT_CALL_SERVANT, 9s);
	}

	void JustSummoned(Creature* summon)
	{
		if (summon->GetEntry() == NPC_BILE_OOZELING)
			summon->AI()->DoZoneInCombat();
	}

	void EnterEvadeMode(EvadeReason /*why*/) override
	{
		_JustReachedHome();
		_DespawnAtEvade();
	}

	void MoveInLineOfSight(Unit* target) override
	{
		if (target->IsWithinMeleeRange(me) && target->IsCreature() && me->IsInCombat())
		{
			if (target->GetEntry() == NPC_WASTING_SERVANT)
			{
				me->CastSpell(target, CONSUME_SERVANT_INSTAKILL);
				me->AddAura(CONSUME_SERVANT_BUFF, me);
			}
		}
		if (target->GetDistance2d(me) >= 35.0f && target->IsPlayer() && me->IsInCombat())
		{
			me->AI()->EnterEvadeMode();
			me->AI()->JustReachedHome();
			me->DespawnCreaturesInArea(NPC_WASTING_SERVANT, 125.0f);
			me->DespawnCreaturesInArea(NPC_BILE_OOZELING, 125.0f);
			me->NearTeleportTo(me->GetHomePosition());
		}
	}

	void CheckRange()
	{
		std::list<Player*> p_list;
		me->GetPlayerListInGrid(p_list, 5.0f);
		for (auto & victim : p_list)
		if (victim->IsWithinMeleeRange(me))
			DoMeleeAttackIfReady();
		else
			events.ScheduleEvent(EVENT_CONSUME_ALL, 100ms);
	}

	void ExecuteEvent(uint32 eventId) override
	{
		switch (eventId)
		{
		case EVENT_CHECK_RANGE:
			CheckRange();
			events.Repeat(2600ms);
			break;	

		case EVENT_TENDERIZE:
			if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
				DoCast(target, TENDERIZE_DAMAGE);
			events.Repeat(15s);
			break;

		case EVENT_CONSUME_ALL:
			DoCastAOE(CONSUME_ALL);
			break;

		case EVENT_CALL_SERVANT:
			Talk(SAY_SERVANT);
			Talk(SAY_WARNING_SERVANT);
			me->SummonCreature(NPC_WASTING_SERVANT, servant_left_pos, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_WASTING_SERVANT, servant_middle_pos, TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_WASTING_SERVANT, servant_right_pos, TEMPSUMMON_MANUAL_DESPAWN);
			events.Repeat(30s);
			break;

		case EVENT_ROTTEN_EXPULSION:
			DoCast(ROTTEN_EXPULSION);
			CallScript();
			events.Repeat(20s);
			break;

		default:
			break;
		}
	}

	void CallScript()
	{
		std::list<Player*> p_list;
		me->GetPlayerListInGrid(p_list, 100.0f);
		for (auto & players : p_list)
		me->CastSpell(players, ROTTEN_EXPULSION_MISSILE);
		me->SummonCreature(NPC_BILE_OOZELING, bile_oozeling_pos, TEMPSUMMON_MANUAL_DESPAWN);
		me->SummonCreature(NPC_BILE_OOZELING, bile_oozeling_pos, TEMPSUMMON_MANUAL_DESPAWN);
		me->SummonCreature(NPC_BILE_OOZELING, bile_oozeling_pos, TEMPSUMMON_MANUAL_DESPAWN);
		me->SummonCreature(NPC_BILE_OOZELING, bile_oozeling_pos, TEMPSUMMON_MANUAL_DESPAWN);
		me->SummonCreature(NPC_BILE_OOZELING, bile_oozeling_pos, TEMPSUMMON_MANUAL_DESPAWN);
	}

	void JustDied(Unit* u) override
	{
		Talk(SAY_DEATH);
		_JustDied();
		instance->SetBossState(DATA_RAAL_THE_GLUTTONOUS, DONE);
		me->DespawnCreaturesInArea(NPC_BILE_OOZELING);
		me->DespawnCreaturesInArea(NPC_WASTING_SERVANT);
	}
};

//133361
struct npc_wasting_servant : public ScriptedAI
{
	npc_wasting_servant(Creature* c) : ScriptedAI(c) { }

	void Reset() override
	{
		ScriptedAI::Reset();
	}

	void IsSummonedBy(Unit* u)
	{		
		me->SetReactState(REACT_PASSIVE);
		me->SetWalk(true);
		if (Creature* raal = me->FindNearestCreature(NPC_RAAL_THE_GLUTTONOUS, 100.0f, true))
			me->GetMotionMaster()->MovePoint(1, -494.0f, -345.0f, 237.0f);
	}
};

void AddSC_boss_raal_the_gluttonous()
{
	RegisterCreatureAI(boss_raal_the_gluttonous);
	RegisterCreatureAI(npc_wasting_servant);
}
