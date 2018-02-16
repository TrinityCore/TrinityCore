/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Player.h"
#include "ScriptMgr.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "trial_of_the_champion.h"

enum Yells
{
	// Eadric the Pure
	SAY_AGGRO_E = 1,
	EMOTE_RADIANCE = 2,
	EMOTE_HAMMER_RIGHTEOUS = 3,
	SAY_HAMMER_RIGHTEOUS = 4,
	SAY_KILL_UNIT_E = 5,
	SAY_DEFEATED_E = 6,

	// Argent Confessor Paletress
	SAY_AGGRO_P = 2,
	SAY_MEMORY_SUMMON = 3,
	SAY_MEMORY_DEATH = 4,
	SAY_KILL_UNIT_P = 5,
	SAY_DEFEATED_P = 6,

	// Memory of X
	EMOTE_WAKING_NIGHTMARE = 0
};

enum Events
{
	// Argent Lightwielder
	EVENT_BLAZING_LIGHT = 1,
	EVENT_CLEAVE,
	EVENT_UNBALANCING_STRIKE,

	// Argent Monk
	EVENT_FLURRY_OF_BLOWS,
	EVENT_PUMMEL,

	// Argent Priestess
	EVENT_HOLY_SMITE,
	EVENT_SHADOW_WORD_PAIN,
	EVENT_FOUNTAIN,
	EVENT_MIND_CONTROL,

	// Argent Confessor Paletress
	EVENT_HOLY_FIRE,
	EVENT_HOLY_SMITE_E,
	EVENT_RENEW,
	EVENT_SUMMON_MEMORY,
	EVENT_MEMORY_AGGRESSIVE,

	// Memory
	EVENT_OLD_WOUNDS,
	EVENT_SHADOWS_PAST,
	EVENT_WAKING_NIGHTMARE,

	// Eadric the Pure
	EVENT_RADIANCE,
	EVENT_HAMMER_OF_JUSTICE,

	// Shared
	EVENT_CHALLENGE_DONE
};

enum Spells
{
	// Argent Lightwielder
	SPELL_BLAZING_LIGHT = 67247,
	SPELL_CLEAVE = 15284,
	SPELL_UNBALANCING_STRIKE = 67237,

	// Argent Monk
	SPELL_FLURRY_OF_BLOWS = 67233,
	SPELL_PUMMEL = 67235,
	SPELL_DIVINE_SHIELD = 67251,
	SPELL_FINAL_MEDITATION = 67255,

	// Argent Priestess
	SPELL_HOLY_SMITE = 36176,
	SPELL_SHADOW_WORD_PAIN = 34941,
	SPELL_MIND_CONTROL = 67229,
	SPELL_SUMMON_FOUNTAIN = 67194,

	// Eadric the Pure
	SPELL_EADRIC_FACEROLLER = 68197,
	SPELL_HAMMER_JUSTICE = 66863,
	SPELL_HAMMER_JUSTICE_STUN = 66940,
	SPELL_HAMMER_RIGHTEOUS = 66867,
	SPELL_HAMMER_RIGHT_DUMMY = 66904,
	SPELL_HAMMER_RIGHTEOUS_PLR = 66905,
	SPELL_RADIANCE = 66935,
	SPELL_VENGEANCE = 66865,
	SPELL_EADRIC_ACH = 68575, // dummy spell for achievement credit (IDs 4297, 4298, 3778, 4296)

	// Paletress
	SPELL_PALETRESS_CONFESSOR = 68206, // achievement id 3802
	SPELL_SMITE = 66536,
	SPELL_HOLY_FIRE = 66538,
	SPELL_RENEW = 66537,
	SPELL_HOLY_NOVA = 66546,
	SPELL_SHIELD = 66515,
	SPELL_SHIELD_REFLECT = 33619,
	SPELL_CONFESS = 66680,
	SPELL_SUMMON_MEMORY = 66545,
	SPELL_PALETRESS_ACH = 68574, // dummy spell for achievement credit (IDs 4297, 4298, 3778, 4296)

	// Memory of X (Summon)
	SPELL_MEMORY_ALGALON = 66715,
	SPELL_MEMORY_ARCHIMONDE = 66704,
	SPELL_MEMORY_CHROMAGGUS = 66697,
	SPELL_MEMORY_CYANIGOSA = 66709,
	SPELL_MEMORY_DELRISSA = 66706,
	SPELL_MEMORY_ECK = 66710,
	SPELL_MEMORY_ENTROPIUS = 66707,
	SPELL_MEMORY_GRUUL = 66702,
	SPELL_MEMORY_HAKKAR = 66698,
	SPELL_MEMORY_HEIGAN = 66712,
	SPELL_MEMORY_HEROD = 66694,
	SPELL_MEMORY_HOGGER = 66543,
	SPELL_MEMORY_IGNIS = 66713,
	SPELL_MEMORY_ILLIDAN = 66705,
	SPELL_MEMORY_INGVAR = 66708,
	SPELL_MEMORY_KALITHRESH = 66700,
	SPELL_MEMORY_LUCIFRON = 66695,
	SPELL_MEMORY_MALCHEZAAR = 66701,
	SPELL_MEMORY_MUTANUS = 66692,
	SPELL_MEMORY_ONYXIA = 66711,
	SPELL_MEMORY_THUNDERAAN = 66696,
	SPELL_MEMORY_VANCLEEF = 66691,
	SPELL_MEMORY_VASHJ = 66703,
	SPELL_MEMORY_VEKNILASH = 66699,
	SPELL_MEMORY_VEZAX = 66714,

	// Memory
	SPELL_SHADOWFORM = 41408,
	SPELL_SPAWN_VISUAL = 66675,
	SPELL_OLD_WOUNDS = 66620,
	SPELL_SHADOWS_PAST = 66619,
	SPELL_WAKING_NIGHTMARE = 66552
};

enum PointMovement
{
	POINT_PREFIGHT = 0,
	POINT_PREPARE,
	POINT_DESPAWN
};

struct argent_challenge_baseAI : public BossAI
{
	argent_challenge_baseAI(Creature* creature) : BossAI(creature, DATA_ARGENT_CHALLENGE)
	{
		Initialize();
		creature->SetReactState(REACT_DEFENSIVE);
	}

	virtual void Initialize() { }

	virtual void OnReset()
	{
		_Reset();
	}

	void EnterEvadeMode(EvadeReason /*why*/) final override
	{
		if (instance->GetBossState(DATA_ARGENT_CHALLENGE) != SPECIAL &&
			instance->GetBossState(DATA_ARGENT_CHALLENGE) != DONE)
			BossAI::EnterEvadeMode();
	}

	void JustReachedHome() final override
	{
		if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == SPECIAL)
			events.ScheduleEvent(EVENT_CHALLENGE_DONE, 4 * IN_MILLISECONDS);
		else
			me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
	}

	void Reset() final override
	{
		if (instance->GetBossState(DATA_ARGENT_CHALLENGE) != SPECIAL)
			OnReset();
	}

	void AttackStart(Unit* who) final override
	{
		if (!me->HasAura(SPELL_SHIELD) && instance->GetBossState(DATA_ARGENT_CHALLENGE) != SPECIAL)
			BossAI::AttackStart(who);
	}

	void MovementInform(uint32 type, uint32 id) final override
	{
		if (type != POINT_MOTION_TYPE)
			return;

		switch (id)
		{
		case POINT_PREFIGHT:
			if (Creature* announcer = instance->GetCreature(DATA_ANNOUNCER))
				announcer->AI()->SetData(DATA_ARGENT_CHAMPION_PREPARE, 0);
			break;
		case POINT_PREPARE:
			me->SetWalk(false);
			me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
			break;
		case POINT_DESPAWN:
			me->DisappearAndDie();
			break;
		default:
			break;
		}
	}
};

enum EadricData
{
	DATA_FACEROLLER_ACHIEVEMENT = 1
};

class boss_eadric : public CreatureScript
{
public:
	boss_eadric() : CreatureScript("boss_eadric") { }

	struct boss_eadricAI : public argent_challenge_baseAI
	{
		boss_eadricAI(Creature* creature) : argent_challenge_baseAI(creature) { }

		void Initialize() override
		{
			_faceroller = false;
		}

		void SetData(uint32 type, uint32 data) override
		{
			if (type != DATA_FACEROLLER_ACHIEVEMENT)
				return;

			_faceroller = (data == 1);
		}

		uint32 GetData(uint32 type) const override
		{
			if (type != DATA_FACEROLLER_ACHIEVEMENT)
				return 0;

			return _faceroller ? 1 : 0;
		}

		void OnReset() override
		{
			Initialize();
			argent_challenge_baseAI::OnReset();
		}

		void DamageTaken(Unit* /*done_by*/, uint32& damage) override
		{
			if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == DONE)
			{
				damage = 0;
				return;
			}

			if (damage >= me->GetHealth())
			{
				damage = 0;
				if (instance->GetBossState(DATA_ARGENT_CHALLENGE) != SPECIAL)
				{
					instance->SetBossState(DATA_ARGENT_CHALLENGE, SPECIAL);
					events.Reset();
					Talk(SAY_DEFEATED_E);
				}
			}
		}

		void JustEngagedWith(Unit* who) override
		{
			if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == SPECIAL)
				return;

			DoCastAOE(SPELL_VENGEANCE);
			events.ScheduleEvent(EVENT_RADIANCE, urand(7 * IN_MILLISECONDS, 15 * IN_MILLISECONDS));
			Talk(SAY_AGGRO_E, who);
			_JustEngagedWith();
		}

		void KilledUnit(Unit* who) override
		{
			if (who->GetTypeId() == TYPEID_PLAYER)
				Talk(SAY_KILL_UNIT_E, who);
		}

		void UpdateAI(uint32 diff) override
		{
			events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_RADIANCE:
					DoCastAOE(SPELL_RADIANCE);
					Talk(EMOTE_RADIANCE);
					events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, urand(20 * IN_MILLISECONDS, 30 * IN_MILLISECONDS));
					break;
				case EVENT_HAMMER_OF_JUSTICE:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
					{
						DoCast(target, SPELL_HAMMER_JUSTICE, true);
						DoCast(target, SPELL_HAMMER_RIGHTEOUS);
						Talk(EMOTE_HAMMER_RIGHTEOUS, target);
						Talk(SAY_HAMMER_RIGHTEOUS);
					}
					events.ScheduleEvent(EVENT_RADIANCE, urand(7 * IN_MILLISECONDS, 15 * IN_MILLISECONDS));
					break;
				case EVENT_CHALLENGE_DONE:
					me->RemoveAllAuras();
					me->GetThreatManager().ClearAllThreat();
					me->SetFullHealth();
					me->RestoreFaction();
					DoCastAOE(SPELL_EADRIC_ACH, true);
					DoCastAOE(SPELL_EADRIC_FACEROLLER, true);

					_JustDied();
					me->SetWalk(true);
					me->GetMotionMaster()->MovePoint(POINT_DESPAWN, bossExitPos);
					break;
				default:
					break;
				}
			}

			if (!UpdateVictim())
				return;

			DoMeleeAttackIfReady();
		}

	private:
		bool _faceroller;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetTrialOfChampionAI<boss_eadricAI>(creature);
	}
};

enum PaletressData
{
	DATA_MEMORY_ENTRY = 1,

	ACTION_MEMORY_DEATH
};

class boss_paletress : public CreatureScript
{
public:
	boss_paletress() : CreatureScript("boss_paletress") { }

	struct boss_paletressAI : public argent_challenge_baseAI
	{
		boss_paletressAI(Creature* creature) : argent_challenge_baseAI(creature) { }

		void Initialize() override
		{
			argent_challenge_baseAI::Initialize();
			_memorySummoned = false;
		}

		void OnReset() override
		{
			me->RemoveAura(SPELL_SHIELD);
			Initialize();
			argent_challenge_baseAI::OnReset();
		}

		void SummonedCreatureDies(Creature* /*summon*/, Unit* /*killer*/) override {
			me->InterruptNonMeleeSpells(true);
			Talk(SAY_MEMORY_DEATH);
			me->GetMotionMaster()->Clear();
			me->RemoveAura(SPELL_SHIELD);
		}

		uint32 GetData(uint32 type) const override
		{
			if (type != DATA_MEMORY_ENTRY || !_memory)
				return 0;

			return _memory->GetEntry();
		}

		void DamageTaken(Unit* /*done_by*/, uint32 &damage) override
		{
			if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == DONE)
			{
				damage = 0;
				return;
			}

			if (!_memorySummoned && me->HealthBelowPctDamaged(25, damage))
			{
				damage = me->GetHealth() - me->CountPctFromMaxHealth(25);
				_memorySummoned = true;
				me->InterruptNonMeleeSpells(true);
				DoCastAOE(SPELL_HOLY_NOVA);
				Talk(SAY_MEMORY_SUMMON);
				DoCastAOE(SPELL_SHIELD);
				DoCastAOE(SPELL_CONFESS);
				me->AttackStop();
				events.ScheduleEvent(EVENT_SUMMON_MEMORY, 2 * IN_MILLISECONDS);
			}

			if (damage >= me->GetHealth())
			{
				damage = 0;
				if (instance->GetBossState(DATA_ARGENT_CHALLENGE) != SPECIAL)
				{
					instance->SetBossState(DATA_ARGENT_CHALLENGE, SPECIAL);
					events.Reset();
					Talk(SAY_DEFEATED_P);
				}
			}
		}

		void JustSummoned(Creature* summon) override
		{
			argent_challenge_baseAI::JustSummoned(summon);
			
			ObjectGuid _memoryGuid = summon->GetGUID();
			_memory = ObjectAccessor::GetCreature(*me, _memoryGuid);
			me->GetMotionMaster()->MoveFollow(summon, 30.0f, 0.0f);
			events.ScheduleEvent(EVENT_MEMORY_AGGRESSIVE, 3 * IN_MILLISECONDS);
		}

		void JustEngagedWith(Unit* who) override
		{
			if (instance->GetBossState(DATA_ARGENT_CHALLENGE) == SPECIAL)
				return;

			events.ScheduleEvent(EVENT_HOLY_SMITE_E, 2 * IN_MILLISECONDS);
			events.ScheduleEvent(EVENT_HOLY_FIRE, urand(9 * IN_MILLISECONDS, 12 * IN_MILLISECONDS));
			events.ScheduleEvent(EVENT_RENEW, urand(15 * IN_MILLISECONDS, 17 * IN_MILLISECONDS));
			Talk(SAY_AGGRO_P, who);
			_JustEngagedWith();
		}

		void KilledUnit(Unit* who) override
		{
			if (who->GetTypeId() == TYPEID_PLAYER)
				Talk(SAY_KILL_UNIT_P, who);
		}

		void UpdateAI(uint32 diff) override
		{
			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_HOLY_SMITE_E:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
						DoCast(target, SPELL_SMITE);
					events.Repeat(2 * IN_MILLISECONDS, 3 * IN_MILLISECONDS);
					break;
				case EVENT_HOLY_FIRE:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.0f, true))
						DoCast(target, SPELL_HOLY_FIRE);
					events.Repeat(9 * IN_MILLISECONDS, 12 * IN_MILLISECONDS);
					break;
				case EVENT_RENEW:
					me->InterruptNonMeleeSpells(true);
					if (roll_chance_i(50) && me->GetHealthPct() < 100)
						DoCastSelf(SPELL_RENEW);
					else
					{
						if (_memory && _memory->GetHealth() > 1)
							DoCast(_memory, SPELL_RENEW);
						else
							DoCastSelf(SPELL_RENEW);
					}

					events.Repeat(15 * IN_MILLISECONDS, 17 * IN_MILLISECONDS);
					break;
				case EVENT_SUMMON_MEMORY:
					// Memory spawns at random player's position
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
						DoCast(target, SPELL_SUMMON_MEMORY, true);
					break;
				case EVENT_MEMORY_AGGRESSIVE:
					if(_memory) {
						_memory->SetReactState(REACT_AGGRESSIVE);
						_memory->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
					}
					break;
				case EVENT_CHALLENGE_DONE:
					me->RemoveAllAuras();
					me->GetThreatManager().ClearAllThreat();
					me->SetFullHealth();
					DoCastAOE(SPELL_PALETRESS_ACH, true);
					me->RestoreFaction();

					if (IsHeroic())
						DoCastAOE(SPELL_PALETRESS_CONFESSOR, true);

					_JustDied();
					me->SetWalk(true);
					me->GetMotionMaster()->MovePoint(POINT_DESPAWN, bossExitPos);
					break;
				default:
					break;
				}
			}

			if (!UpdateVictim())
				return;

			DoMeleeAttackIfReady();
		}

	private:
		bool _memorySummoned;
		Creature* _memory;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetTrialOfChampionAI<boss_paletressAI>(creature);
	}
};

class npc_argent_soldier : public CreatureScript
{
public:
	npc_argent_soldier() : CreatureScript("npc_argent_soldier") { }

	struct npc_argent_soldierAI : public ScriptedAI
	{
		npc_argent_soldierAI(Creature* creature) : ScriptedAI(creature)
		{
			_instance = creature->GetInstanceScript();
			Initialize();
			_waypointId = 0;
		}

		void Initialize()
		{
			_shielded = false;
		}

		void Reset() override
		{
			_events.Reset();
			Initialize();

			if (me->GetEntry() == NPC_PRIESTESS)
				if (Creature* fountain = ObjectAccessor::GetCreature(*me, _fountainGuid))
					fountain->DisappearAndDie();
		}

		void GenerateFinalPosition(Position& finalPos) const
		{
			switch (me->GetEntry())
			{
			case NPC_ARGENT_LIGHWIELDER:
				switch (_waypointId)
				{
				case 0:
					finalPos = { 712.14f, 628.42f, 411.88f, 5.81f };
					break;
				case 1:
					finalPos = { 742.44f, 650.29f, 411.79f, 4.60f };
					break;
				case 2:
					finalPos = { 774.94f, 636.64f, 411.89f, 3.78f };
					break;
				}
				break;
			case NPC_ARGENT_MONK:
				switch (_waypointId)
				{
				case 0:
					finalPos = { 713.12f, 632.97f, 411.90f, 5.81f };
					break;
				case 1:
					finalPos = { 746.73f, 650.24f, 411.56f, 4.60f };
					break;
				case 2:
					finalPos = { 777.33f, 633.08f, 411.89f, 3.78f };
					break;
				}
				break;
			case NPC_PRIESTESS:
				switch (_waypointId)
				{
				case 0:
					finalPos = { 715.06f, 637.07f, 411.91f, 5.81f };
					break;
				case 1:
					finalPos = { 750.72f, 650.20f, 411.77f, 4.60f };
					break;
				case 2:
					finalPos = { 780.13f, 629.18f, 411.89f, 3.78f };
					break;
				}
				break;
			default:
				break;
			}
		}

		void JustReachedHome() override
		{
			me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY1H);
		}

		void MovementInform(uint32 type, uint32 id) override
		{
			if (type != POINT_MOTION_TYPE)
				return;

			if (id == POINT_PREFIGHT)
			{
				me->SetWalk(false);
				me->GetMotionMaster()->MoveTargetedHome(); // this corrects facing 100%
				if (me->GetEntry() == NPC_ARGENT_MONK)
				{
					if (Creature* lightWielder = me->FindNearestCreature(NPC_ARGENT_LIGHWIELDER, 15.0f))
					{
						if (lightWielder->GetFollowAngle() != 0.f)
						{
							lightWielder->GetMotionMaster()->Clear();
							lightWielder->GetMotionMaster()->MovePoint(0, lightWielder->GetHomePosition());
						}
					}

					if (Creature* priestess = me->FindNearestCreature(NPC_PRIESTESS, 15.0f))
					{
						if (priestess->GetFollowAngle() != 0.f)
						{
							priestess->GetMotionMaster()->Clear();
							priestess->GetMotionMaster()->MovePoint(0, priestess->GetHomePosition());
						}
					}
				}
			}
		}

		void JustSummoned(Creature* summon) override
		{
			if (me->GetEntry() == NPC_PRIESTESS)
				_fountainGuid = summon->GetGUID();
		}

		void DamageTaken(Unit* /*attacker*/, uint32& damage) override
		{
			if (me->GetEntry() == NPC_ARGENT_MONK && damage >= me->GetHealth() && !_shielded)
			{
				_shielded = true;
				damage = me->GetHealth() - 1;
				me->AttackStop();

				DoCast(SPELL_DIVINE_SHIELD);
				DoCast(SPELL_FINAL_MEDITATION);
			}
		}

		void JustDied(Unit* /*killer*/) override
		{
			_instance->SetData(DATA_ARGENT_SOLDIER_DEFEATED, _instance->GetData(DATA_ARGENT_SOLDIER_DEFEATED) + 1);
			if (me->GetEntry() == NPC_PRIESTESS)
			{
				if (Creature* fountain = ObjectAccessor::GetCreature(*me, _fountainGuid))
					fountain->DisappearAndDie();
			}
		}

		void SetData(uint32 type, uint32 /*data*/) override
		{
			_waypointId = type;
			Position homePos;
			GenerateFinalPosition(homePos);

			if (homePos.IsPositionValid())
			{
				me->SetHomePosition(homePos);
				me->SetWalk(true);
				if (me->GetEntry() == NPC_ARGENT_MONK)
					me->GetMotionMaster()->MovePoint(POINT_PREFIGHT, homePos);
			}
		}

		void JustEngagedWith(Unit* /*who*/) override
		{
			switch (me->GetEntry())
			{
			case NPC_ARGENT_LIGHWIELDER:
				_events.ScheduleEvent(EVENT_BLAZING_LIGHT, 10 * IN_MILLISECONDS);
				_events.ScheduleEvent(EVENT_CLEAVE, urand(4 * IN_MILLISECONDS, 6 * IN_MILLISECONDS));
				if (IsHeroic())
					_events.ScheduleEvent(EVENT_UNBALANCING_STRIKE, 8 * IN_MILLISECONDS);
				break;
			case NPC_ARGENT_MONK:
				_events.ScheduleEvent(EVENT_FLURRY_OF_BLOWS, 2 * IN_MILLISECONDS);
				_events.ScheduleEvent(EVENT_PUMMEL, 12 * IN_MILLISECONDS);
				break;
			case NPC_PRIESTESS:
				_events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 500);
				_events.ScheduleEvent(EVENT_HOLY_SMITE, 2500);
				_events.ScheduleEvent(EVENT_FOUNTAIN, 10 * IN_MILLISECONDS);
				if (IsHeroic())
					_events.ScheduleEvent(EVENT_MIND_CONTROL, 15 * IN_MILLISECONDS);
				break;
			default:
				break;
			}
		}

		void AttackStart(Unit* who) override
		{
			if (!(me->GetEntry() == NPC_ARGENT_MONK && me->HasAura(SPELL_DIVINE_SHIELD)))
				ScriptedAI::AttackStart(who);
		}

		void UpdateAI(uint32 diff) override
		{
			_events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			if (!UpdateVictim())
				return;

			while (uint32 eventId = _events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_BLAZING_LIGHT:
					if (Unit* friendly = DoSelectLowestHpFriendly(40.0f))
					{
						if (friendly->GetHealthPct() > me->GetHealthPct())
							DoCastSelf(SPELL_BLAZING_LIGHT);
						else
							DoCast(friendly, SPELL_BLAZING_LIGHT);
					}
					_events.Repeat(10 * IN_MILLISECONDS);
					break;
				case EVENT_CLEAVE:
					DoCastVictim(SPELL_CLEAVE);
					_events.Repeat(4 * IN_MILLISECONDS, 6 * IN_MILLISECONDS);
					break;
				case EVENT_UNBALANCING_STRIKE:
					DoCastVictim(SPELL_UNBALANCING_STRIKE);
					_events.Repeat(15 * IN_MILLISECONDS);
					break;
				case EVENT_FLURRY_OF_BLOWS:
					DoCast(SPELL_FLURRY_OF_BLOWS);
					_events.Repeat(15 * IN_MILLISECONDS);
					break;
				case EVENT_PUMMEL:
				{
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, [this](Unit* u) -> bool { return u->IsWithinDist(me, 5.f) && u->IsNonMeleeSpellCast(true); }))
						DoCast(target, SPELL_PUMMEL);

					_events.Repeat(12 * IN_MILLISECONDS);
					break;
				}
				case EVENT_SHADOW_WORD_PAIN:
					DoCastVictim(SPELL_SHADOW_WORD_PAIN);
					_events.Repeat(15 * IN_MILLISECONDS);
					break;
				case EVENT_HOLY_SMITE:
					DoCastVictim(SPELL_HOLY_SMITE);
					_events.Repeat(4 * IN_MILLISECONDS, 7 * IN_MILLISECONDS);
					break;
				case EVENT_FOUNTAIN:
					DoCastAOE(SPELL_SUMMON_FOUNTAIN);
					_events.Repeat(50 * IN_MILLISECONDS);
					break;
				case EVENT_MIND_CONTROL:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 30.0f, true))
						DoCast(target, SPELL_MIND_CONTROL);
					_events.Repeat(15 * IN_MILLISECONDS);
					break;
				default:
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

	private:
		InstanceScript * _instance;
		EventMap _events;

		ObjectGuid _fountainGuid;

		uint8 _waypointId;
		bool _shielded;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetTrialOfChampionAI<npc_argent_soldierAI>(creature);
	}
};

class npc_fountain_of_light : public CreatureScript
{
public:
	npc_fountain_of_light() : CreatureScript("npc_fountain_of_light") { }

	struct npc_fountain_of_lightAI : public NullCreatureAI
	{
		npc_fountain_of_lightAI(Creature* creature) : NullCreatureAI(creature)
		{
			me->SetReactState(REACT_PASSIVE);
		}

		void JustDied(Unit* /*killer*/) override
		{
			me->DespawnOrUnsummon();
		}

		void AttackStart(Unit* /*who*/) override { }

		void UpdateAI(uint32 /*diff*/) override { }
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetTrialOfChampionAI<npc_fountain_of_lightAI>(creature);
	}
};

class npc_memory : public CreatureScript
{
public:
	npc_memory() : CreatureScript("npc_memory") { }

	struct npc_memoryAI : public ScriptedAI
	{
		npc_memoryAI(Creature* creature) : ScriptedAI(creature)
		{
			Initialize();
			me->SetReactState(REACT_PASSIVE);
			me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
			_events.ScheduleEvent(EVENT_OLD_WOUNDS, urand(14 * IN_MILLISECONDS, 16 * IN_MILLISECONDS));
			_events.ScheduleEvent(EVENT_SHADOWS_PAST, 8 * IN_MILLISECONDS);
			_events.ScheduleEvent(EVENT_WAKING_NIGHTMARE, urand(10 * IN_MILLISECONDS, 13 * IN_MILLISECONDS));
		}

		void Initialize()
		{
			DoCastAOE(SPELL_SHADOWFORM);
			DoCastAOE(SPELL_SPAWN_VISUAL);

		}

		void Reset() override
		{
			_events.Reset();
			Initialize();
		}


		void JustEngagedWith(Unit* /*who*/) override
		{
			DoZoneInCombat();
		}

		void UpdateAI(uint32 diff) override
		{
			_events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = _events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_OLD_WOUNDS:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 5.0f, true))
						DoCast(target, SPELL_OLD_WOUNDS);
					_events.Repeat(11 * IN_MILLISECONDS, 13 * IN_MILLISECONDS);
					break;
				case EVENT_SHADOWS_PAST:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 40.0f, true))
						DoCast(target, SPELL_SHADOWS_PAST);
					_events.Repeat(5 * IN_MILLISECONDS, 7 * IN_MILLISECONDS);
					break;
				case EVENT_WAKING_NIGHTMARE:
					Talk(EMOTE_WAKING_NIGHTMARE);
					DoCastAOE(SPELL_WAKING_NIGHTMARE);
					_events.Repeat(20 * IN_MILLISECONDS, 40 * IN_MILLISECONDS);
					break;
				default:
					break;
				}
			}

			if (!UpdateVictim())
				return;

			DoMeleeAttackIfReady();
		}

	private:
		EventMap _events;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return GetTrialOfChampionAI<npc_memoryAI>(creature);
	}
};

class spell_eadric_hammer_of_righteous : public SpellScriptLoader
{
public:
	spell_eadric_hammer_of_righteous() : SpellScriptLoader("spell_eadric_hammer_of_righteous") { }

	class spell_eadric_hammer_of_righteous_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_eadric_hammer_of_righteous_SpellScript);

		bool Validate(SpellInfo const* /*spellInfo*/) override
		{
			return ValidateSpellInfo({ SPELL_HAMMER_RIGHT_DUMMY, SPELL_HAMMER_JUSTICE_STUN });
		}

		void HandleDamage()
		{
			if (Unit* target = GetHitUnit())
			{
				if (!target->HasAura(SPELL_HAMMER_JUSTICE_STUN))
				{
					// If target does not have Hammer of Justice stun,
					// then target gets the dummy aura which allows you to throw hammer back to Eadric
					PreventHitDefaultEffect(EFFECT_0);
					PreventHitDamage();
					GetCaster()->CastSpell(target, SPELL_HAMMER_RIGHT_DUMMY, true);
				}
			}
		}

		void Register() override
		{
			BeforeHit += SpellHitFn(spell_eadric_hammer_of_righteous_SpellScript::HandleDamage);
		}
	};

	SpellScript* GetSpellScript() const override
	{
		return new spell_eadric_hammer_of_righteous_SpellScript();
	}
};

class spell_eadric_hammer_of_righteous_faceroller : public SpellScriptLoader
{
public:
	spell_eadric_hammer_of_righteous_faceroller() : SpellScriptLoader("spell_eadric_hammer_of_righteous_faceroller") { }

	class spell_eadric_hammer_of_righteous_faceroller_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_eadric_hammer_of_righteous_faceroller_SpellScript);

		bool Load() override
		{
			Unit* caster = GetCaster();
			return caster->GetTypeId() == TYPEID_PLAYER && caster->GetMap()->IsHeroic();
		}

		void CheckHealth(SpellEffIndex /*effIndex*/)
		{
			Creature* creature = GetHitCreature();
			if (!creature || creature->GetEntry() != NPC_EADRIC)
				return;

			// If the spell's damage is higher than Eadric' health,
			// player gets the achievement
			if (GetHitDamage() >= static_cast<int32>(GetHitUnit()->GetHealth()))
				creature->AI()->SetData(DATA_FACEROLLER_ACHIEVEMENT, 1);
		}

		void Register() override
		{
			OnEffectHitTarget += SpellEffectFn(spell_eadric_hammer_of_righteous_faceroller_SpellScript::CheckHealth, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
		}
	};

	SpellScript* GetSpellScript() const override
	{
		return new spell_eadric_hammer_of_righteous_faceroller_SpellScript();
	}
};


class spell_eadric_radiance : public SpellScriptLoader
{
public:
	spell_eadric_radiance() : SpellScriptLoader("spell_eadric_radiance") { }

	class spell_eadric_radiance_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_eadric_radiance_SpellScript);

		void FilterTargets(std::list<WorldObject*>& targets)
		{
			Unit* caster = GetCaster();
			targets.remove_if([caster](WorldObject* target) -> bool
			{
				if (!target->IsWithinDist(caster, 40.f))
					return true;

				return !target->isInFront(caster, 2.5f);
			});
		}

		void Register() override
		{
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eadric_radiance_SpellScript::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
		}
	};

	SpellScript* GetSpellScript() const override
	{
		return new spell_eadric_radiance_SpellScript();
	}
};

std::vector<uint32> const memorySpells =
{
	SPELL_MEMORY_ALGALON,
	SPELL_MEMORY_ARCHIMONDE,
	SPELL_MEMORY_CHROMAGGUS,
	SPELL_MEMORY_CYANIGOSA,
	SPELL_MEMORY_DELRISSA,
	SPELL_MEMORY_ECK,
	SPELL_MEMORY_ENTROPIUS,
	SPELL_MEMORY_GRUUL,
	SPELL_MEMORY_HAKKAR,
	SPELL_MEMORY_HEIGAN,
	SPELL_MEMORY_HEROD,
	SPELL_MEMORY_HOGGER,
	SPELL_MEMORY_IGNIS,
	SPELL_MEMORY_ILLIDAN,
	SPELL_MEMORY_INGVAR,
	SPELL_MEMORY_KALITHRESH,
	SPELL_MEMORY_LUCIFRON,
	SPELL_MEMORY_MALCHEZAAR,
	SPELL_MEMORY_MUTANUS,
	SPELL_MEMORY_ONYXIA,
	SPELL_MEMORY_THUNDERAAN,
	SPELL_MEMORY_VANCLEEF,
	SPELL_MEMORY_VASHJ,
	SPELL_MEMORY_VEKNILASH,
	SPELL_MEMORY_VEZAX
};

// 66545 - Summon Memory
class spell_paletress_summon_memory : public SpellScriptLoader
{
public:
	spell_paletress_summon_memory() : SpellScriptLoader("spell_paletress_summon_memory") { }

	class spell_paletress_summon_memory_SpellScript : public SpellScript
	{
		PrepareSpellScript(spell_paletress_summon_memory_SpellScript);

		bool Validate(SpellInfo const* /*spellInfo*/) override
		{
			return ValidateSpellInfo({
				SPELL_MEMORY_ALGALON,
				SPELL_MEMORY_ARCHIMONDE,
				SPELL_MEMORY_CHROMAGGUS,
				SPELL_MEMORY_CYANIGOSA,
				SPELL_MEMORY_DELRISSA,
				SPELL_MEMORY_ECK,
				SPELL_MEMORY_ENTROPIUS,
				SPELL_MEMORY_GRUUL,
				SPELL_MEMORY_HAKKAR,
				SPELL_MEMORY_HEIGAN,
				SPELL_MEMORY_HEROD,
				SPELL_MEMORY_HOGGER,
				SPELL_MEMORY_IGNIS,
				SPELL_MEMORY_ILLIDAN,
				SPELL_MEMORY_INGVAR,
				SPELL_MEMORY_KALITHRESH,
				SPELL_MEMORY_LUCIFRON,
				SPELL_MEMORY_MALCHEZAAR,
				SPELL_MEMORY_MUTANUS,
				SPELL_MEMORY_ONYXIA,
				SPELL_MEMORY_THUNDERAAN,
				SPELL_MEMORY_VANCLEEF,
				SPELL_MEMORY_VASHJ,
				SPELL_MEMORY_VEKNILASH,
				SPELL_MEMORY_VEZAX
				});
		}

		void FilterTargets(std::list<WorldObject*>& targets)
		{
			if (targets.empty())
				return;

			WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
			targets.clear();
			targets.push_back(target);
		}

		void HandleScript(SpellEffIndex /*effIndex*/)
		{
			uint32 const randMemorySpellId = Trinity::Containers::SelectRandomContainerElement(memorySpells);
			GetHitUnit()->CastSpell(GetHitUnit(), randMemorySpellId, GetCaster()->GetGUID());
		}

		void Register() override
		{
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_paletress_summon_memory_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
			OnEffectHitTarget += SpellEffectFn(spell_paletress_summon_memory_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
		}
	};

	SpellScript* GetSpellScript() const override
	{
		return new spell_paletress_summon_memory_SpellScript();
	}
};

class spell_paletress_reflective_shield : public SpellScriptLoader
{
public:
	spell_paletress_reflective_shield() : SpellScriptLoader("spell_paletress_reflective_shield") { }

	class spell_paletress_reflective_shield_AuraScript : public AuraScript
	{
		PrepareAuraScript(spell_paletress_reflective_shield_AuraScript);

		bool Validate(SpellInfo const* /*spellInfo*/) override
		{
			return ValidateSpellInfo({ SPELL_SHIELD_REFLECT });
		}

		void HandleScript(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
		{
			// Reflecting 25% of absorbed damage back to attacker
			if (dmgInfo.GetAttacker() == GetTarget())
				return;

			int32 bp = CalculatePct(absorbAmount, GetSpellInfo()->Effects[EFFECT_2].CalcValue());

			GetTarget()->CastSpell(dmgInfo.GetAttacker(), SPELL_SHIELD_REFLECT, CastSpellExtraArgs(aurEff).AddSpellBP0(bp));
		}

		void Register() override
		{
			AfterEffectAbsorb += AuraEffectAbsorbFn(spell_paletress_reflective_shield_AuraScript::HandleScript, EFFECT_0);
		}
	};

	AuraScript* GetAuraScript() const override
	{
		return new spell_paletress_reflective_shield_AuraScript();
	}
};

template <uint32 Entry>
class achievement_argent_confessor : public AchievementCriteriaScript
{
public:
	achievement_argent_confessor(char const* name) : AchievementCriteriaScript(name) { }

	bool OnCheck(Player* /*source*/, Unit* target) override
	{
		if (!target || !target->IsAIEnabled)
			return false;

		return target->GetAI()->GetData(DATA_MEMORY_ENTRY) == Entry;
	}
};

class achievement_eadric_faceroller : public AchievementCriteriaScript
{
public:
	achievement_eadric_faceroller() : AchievementCriteriaScript("achievement_eadric_faceroller") { }

	bool OnCheck(Player* /*source*/, Unit* target) override
	{
		if (!target || !target->IsAIEnabled)
			return false;

		return !!target->GetAI()->GetData(DATA_FACEROLLER_ACHIEVEMENT);
	}
};

void AddSC_boss_argent_challenge()
{
	new boss_eadric();
	new boss_paletress();

	new npc_argent_soldier();
	new npc_fountain_of_light();
	new npc_memory();

	new spell_eadric_hammer_of_righteous();
	new spell_eadric_hammer_of_righteous_faceroller();
	new spell_eadric_radiance();

	new spell_paletress_summon_memory();
	new spell_paletress_reflective_shield();

	new achievement_argent_confessor<NPC_MEMORY_HOGGER>("achievement_argent_confessor_hogger");
	new achievement_argent_confessor<NPC_MEMORY_VANCLEEF>("achievement_argent_confessor_vancleef");
	new achievement_argent_confessor<NPC_MEMORY_MUTANUS>("achievement_argent_confessor_mutanus");
	new achievement_argent_confessor<NPC_MEMORY_HEROD>("achievement_argent_confessor_herod");
	new achievement_argent_confessor<NPC_MEMORY_LUCIFRON>("achievement_argent_confessor_lucifron");
	new achievement_argent_confessor<NPC_MEMORY_THUNDERAAN>("achievement_argent_confessor_thunderaan");
	new achievement_argent_confessor<NPC_MEMORY_CHROMAGGUS>("achievement_argent_confessor_chromaggus");
	new achievement_argent_confessor<NPC_MEMORY_HAKKAR>("achievement_argent_confessor_hakkar");
	new achievement_argent_confessor<NPC_MEMORY_VEKNILASH>("achievement_argent_confessor_veknilash");
	new achievement_argent_confessor<NPC_MEMORY_KALITHRESH>("achievement_argent_confessor_kalithresh");
	new achievement_argent_confessor<NPC_MEMORY_MALCHEZAAR>("achievement_argent_confessor_malchezaar");
	new achievement_argent_confessor<NPC_MEMORY_GRUUL>("achievement_argent_confessor_gruul");
	new achievement_argent_confessor<NPC_MEMORY_VASHJ>("achievement_argent_confessor_vashj");
	new achievement_argent_confessor<NPC_MEMORY_ARCHIMONDE>("achievement_argent_confessor_archimonde");
	new achievement_argent_confessor<NPC_MEMORY_ILLIDAN>("achievement_argent_confessor_illidan");
	new achievement_argent_confessor<NPC_MEMORY_DELRISSA>("achievement_argent_confessor_delrissa");
	new achievement_argent_confessor<NPC_MEMORY_MURU>("achievement_argent_confessor_muru");
	new achievement_argent_confessor<NPC_MEMORY_INGVAR>("achievement_argent_confessor_ingvar");
	new achievement_argent_confessor<NPC_MEMORY_CYANIGOSA>("achievement_argent_confessor_cyanigosa");
	new achievement_argent_confessor<NPC_MEMORY_ECK>("achievement_argent_confessor_eck");
	new achievement_argent_confessor<NPC_MEMORY_ONYXIA>("achievement_argent_confessor_onyxia");
	new achievement_argent_confessor<NPC_MEMORY_HEIGAN>("achievement_argent_confessor_heigan");
	new achievement_argent_confessor<NPC_MEMORY_IGNIS>("achievement_argent_confessor_ignis");
	new achievement_argent_confessor<NPC_MEMORY_VEZAX>("achievement_argent_confessor_vezax");
	new achievement_argent_confessor<NPC_MEMORY_ALGALON>("achievement_argent_confessor_algalon");

	new achievement_eadric_faceroller();
}
