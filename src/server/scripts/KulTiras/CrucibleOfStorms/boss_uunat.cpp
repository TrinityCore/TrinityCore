#include "crucible_of_storms.h"
#include "Position.h"
#include "Common.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "SpellAuraDefines.h"
#include "AreaTrigger.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "SpellAuraEffects.h"

enum Spells
{
	// relic spells
	SPELL_TRIDENT_NPC_VISUAL = 287237,
	SPELL_TRIDENT_OF_DEEP_OCEAN_BUTTON = 284768,
	SPELL_FEEDBACK_OCEAN = 286457,

	SPELL_VOID_NPC_VISUAL = 285885,
	SPELL_VOID_STONE_BUTTON = 284684,
	SPELL_FEEDBACK_VOID = 286459,

	SPELL_VOID_STONE_ALLOW_CLICK = 286764,
	SPELL_TEMPEST_CALLER_ALLOW_CLICK = 286748,
	SPELL_TRIDENT_OF_DEEP_OCEAN_ALLOW_CLICK = 285883, //remove spellvisual

	SPELL_TEMPEST_NPC_VISUAL = 285884,
	SPELL_TEMPEST_CALLER_BUTTON = 286750,
	SPELL_FEEDBACK_STORM = 286458,
	
	// buttons
	SPELL_CUSTODY_OF_THE_DEEP = 284772, // trident of deep ocean
	SPELL_CUSTODY_SHIELD = 284804,
	SPELL_CUSTODY_AT = 286701,
	SPELL_ABYSSAL_COLLAPSE = 282886,

	SPELL_VOID_STONE_EFFECT = 284722,

	SPELL_TEMPEST_CALLER_EFFECT = 286755,
	SPELL_TEMPEST_CALLER_DAMAGE = 286754,
	SPELL_TEMPEST_CALLER_ANNIHILATE = 286753,

	// boss
	SPELL_GIFT_OF_NZOTH_OBSCURITY_CAST = 285453,
	SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_DAMAGE = 285477,
	SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_1 = 285457,
	SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_2 = 285461,
	SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_3 = 285465,
	SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_4 = 285467,

	SPELL_GIFT_OF_NZOTH_HYSTERIA_CAST = 285638,
	SPELL_GIFT_OF_NZOTH_HYSTERIA_AURA = 285642,

	SPELL_GIFT_OF_NZOTH_LUNACY = 285685,

	SPELL_OBLIVION_TEAR_AT = 285210,
	SPELL_OBLIVION_TEAR_MISSILE_PLAYER = 285185,
	SPELL_OBLIVION_TEAR_MISSILE_BOSS = 285225,

	SPELL_MADDENING_EYES_OF_NZOTH_AT = 295737,
	SPELL_MADDENING_EYES_OF_NZOTH = 285345,

	SPELL_PIERCING_GAZE_OF_NZOTH_AT = 285359,
	SPELL_PIERCING_GAZE_OF_NZOTH_AURA = 285367,

	SPELL_TOUCH_OF_THE_END = 284851,
	SPELL_SIGHTLESS_BOND = 287693,
	SPELL_UNNATURAL_REGENERATION = 285333,
	SPELL_SHROUD_OF_WHISPERS = 292590,

	SPELL_UNKNOWABLE_TERROR_CAST = 285562,

	SPELL_INSATIABLE_TORMENT = 285652,
	SPELL_INSATIABLE_TORMENT_RANGE = 300742,
	SPELL_FEED_ON_THE_UNWORTHY_DAMAGE = 285653,
	SPELL_FEED_ON_THE_UNWORTHY_HEAL = 285676,

	SPELL_UNSTABLE_RESONANCE_DAMAGE = 293665,
	SPELL_UNSTABLE_RESONANCE_CAST = 293653,
	SPELL_UNSTABLE_OCEAN = 293662,
	SPELL_UNSTABLE_STORM = 293661,
	SPELL_UNSTABLE_VOID = 293663,

	SPELL_VOID_CRASH_BIG = 293968,
	SPELL_VOID_CRASH_MID = 282405,
	SPELL_VOID_CRASH_LOW = 282418,

	// adds
	SPELL_CONSUME_ESSENCE = 285427,
	SPELL_VOID_ERUPTION = 285431,
	SPELL_HUNGER_FOR_THE_END = 287291,
	SPELL_HUNGER_FOR_THE_END_AURA = 287292,
	SPELL_VOIDSTEP = 287275,
	SPELL_FEED = 285307,

	SPELL_VOID_SHIELD = 286310,
};

enum Events
{
	// Adds
	EVENT_SIGHTLESS_BOND = 1,
	EVENT_ENERGY_REGEN,
	EVENT_FIXATE_TANK,
	EVENT_VOIDSTEP,
	EVENT_CONSUME_ESSENCE,

	EVENT_ABYSSAL_COLLAPSE,
	EVENT_ADD_FRAME,
	EVENT_REMOVE_FRAME,
	EVENT_RELIC_REGEN,

	// UUnat
	EVENT_VOID_CRASH,
	EVENT_SUMMON_GUARDIANS,
	EVENT_SUMMON_PRIMORDIAL_MINDBENDER,
	EVENT_INSATIABLE_TORMENT,
	EVENT_UNSTABLE_RESONANCE,
	EVENT_PIERCING_GAZE,
	EVENT_MADDENING_EYE,
	EVENT_TOUCH_OF_THE_END,
	EVENT_OBLIVION_TEAR,
	EVENT_UNKNOWABLE_TERROR,

	EVENT_GIFT_OF_NZOTH_LUNACY,
	EVENT_GIFT_OF_NZOTH_HYSTERIA,
	EVENT_GIFT_OF_NZOTH_OBSCURITY,
};

enum Timers
{
	TIMER_VOIDSTEP = 10 * IN_MILLISECONDS,
	TIMER_ENERGY_REGEN = 3 * IN_MILLISECONDS,

	TIMER_VOID_CRASH = 35 * IN_MILLISECONDS,
	TIMER_SUMMON_GUARDIANS = 30 * IN_MILLISECONDS,
	TIMER_SUMMON_PRIMORDIAL_MINDBENDER = 60 * IN_MILLISECONDS,
	TIMER_INSATIABLE_TORMENT = 50 * IN_MILLISECONDS,
	TIMER_UNSTABLE_RESONANCE = 35 * IN_MILLISECONDS,
	TIMER_PIERCING_GAZE = 40 * IN_MILLISECONDS,
	TIMER_MADDENING_EYE = 45 * IN_MILLISECONDS,
	TIMER_TOUCH_OF_THE_END = 10 * IN_MILLISECONDS,
	TIMER_OBLIVION_TEAR = 25 * IN_MILLISECONDS,
	TIMER_UNKNOWABLE_TERROR = 60 * IN_MILLISECONDS,
};

enum Creatures
{
	BOSS_UUNAT = 145371,
	
	NPC_PRIMORDIAL_MINDBENDER = 146940,
	NPC_SWARMING_VOIDSPAWN = 146945,
	NPC_UNDYING_GUARDIAN = 146829,
	NPC_MADDENING_EYE_TRIGGER = 146912,
	NPC_PIERCING_GAZE_TRIGGER = 146913,

	NPC_OCEAN_RUNE = 146642,
	NPC_VOID_RELIC = 144804,
	NPC_TEMPEST_RELIC = 144808,
	NPC_TRIDENT_RELIC = 147574,
};

const Position centerPos = { 3487.13f, -1077.65f, -381.98f };

Position addsSummonPos[3] =
{
	{ 3470.77f, -1065.60f, -382.78f },
	{ 3507.61f, -1067.70f - 382.98f },
	{ 3492.80f, -1099.37f, -383.25f },
};

class notAvailableTarget
{
public:
	bool operator()(Player* target) const
	{
		return target && !target->HasAura(SPELL_TOUCH_OF_THE_END);
	}
};

class noResonanceStorm
{
public:
	bool operator()(Player* target) const
	{
		return target && target->HasAura(SPELL_UNSTABLE_STORM);
	}
};

class noResonanceVoid
{
public:
	bool operator()(Player* target) const
	{
		return target && target->HasAura(SPELL_UNSTABLE_VOID);
	}
};

class noResonanceOcean
{
public:
	bool operator()(Player* target) const
	{
		return target && target->HasAura(SPELL_UNSTABLE_OCEAN);
	}
};

enum Points
{
	POINT_VOID_SHIELD = 200,
};

enum Actions
{
	ACTION_REGEN_RELIC = 1,
};

#define AGGRO_TEXT "Pay the price for your defiance!"
#define INTRO_TEXT "His eyes behold every truth.... every unnumbered crime!" // ?!
#define GIFT_OBSCURITY_TEXT "His wrath has awakened!"
#define PHASE2_TEXT "His devoted outnumber the sands... the stars!"
#define GIFT_HISTERYA_TEXT "Taste his true power!"
#define PHASE3_TEXT "His gaze falls upon every path... every dream given form!"
#define GIFT_LUNACY_TEXT "Aid your faithful servant, o mighty N'Zoth!"
#define DIED_TEXT "All... shall be... awakened..."
#define KILLED_TARGET "All glory to the master"

// Trident of Deep Ocean
struct tankSpecs : public std::unary_function<Unit*, bool>
{
	tankSpecs() {}

	bool operator() (const Unit* pTarget)
	{
		Player* player = const_cast<Player*>(pTarget->ToPlayer());
		uint32 specialization = player->GetSpecializationId();
		return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
			|| (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
			|| (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
			|| (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
			|| (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
			|| (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BREWMASTER));
	}
};

// Void Stone
struct healSpecs : public std::unary_function<Unit*, bool>
{
	healSpecs() {}

	bool operator() (const Unit* pTarget)
	{
		Player* player = const_cast<Player*>(pTarget->ToPlayer());
		uint32 specialization = player->GetSpecializationId();
		return ((player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_DISCIPLINE)
			|| (player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_HOLY)
			|| (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_RESTORATION)
			|| (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_MISTWEAVER)
			|| (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_HOLY)
			|| (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_RESTORATION));
	}
};

// Tempest Caller
struct dpsSpecs : public std::unary_function<Unit*, bool>
{
	dpsSpecs() {}

	bool operator() (const Unit* pTarget)
	{
		Player* player = const_cast<Player*>(pTarget->ToPlayer());
		uint32 specialization = player->GetSpecializationId();
		return ((player->getClass() == CLASS_PRIEST && specialization == TALENT_SPEC_PRIEST_SHADOW)
			|| (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_FROST)
			|| (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_UNHOLY)
			|| (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BALANCE)
			|| (player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_CAT)
			|| (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BATTLEDANCER)
			|| (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_ELEMENTAL)
			|| (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_HAVOC)
			|| (player->getClass() == CLASS_HUNTER && specialization == TALENT_SPEC_HUNTER_BEASTMASTER)
			|| (player->getClass() == CLASS_HUNTER && specialization == TALENT_SPEC_HUNTER_SURVIVAL)
			|| (player->getClass() == CLASS_HUNTER && specialization == TALENT_SPEC_HUNTER_MARKSMAN)
			|| (player->getClass() == CLASS_MAGE && specialization == TALENT_SPEC_MAGE_FIRE)
			|| (player->getClass() == CLASS_MAGE && specialization == TALENT_SPEC_MAGE_ARCANE)
			|| (player->getClass() == CLASS_MAGE && specialization == TALENT_SPEC_MAGE_FROST)
			|| (player->getClass() == CLASS_ROGUE && specialization == TALENT_SPEC_ROGUE_COMBAT)
			|| (player->getClass() == CLASS_ROGUE && specialization == TALENT_SPEC_ROGUE_ASSASSINATION)
			|| (player->getClass() == CLASS_ROGUE && specialization == TALENT_SPEC_ROGUE_SUBTLETY)
			|| (player->getClass() == CLASS_WARLOCK && specialization == TALENT_SPEC_WARLOCK_AFFLICTION)
			|| (player->getClass() == CLASS_WARLOCK && specialization == TALENT_SPEC_WARLOCK_DEMONOLOGY)
			|| (player->getClass() == CLASS_WARLOCK && specialization == TALENT_SPEC_WARLOCK_DESTRUCTION)
			|| (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_ARMS)
			|| (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_FURY)
			|| (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_RETRIBUTION)
			|| (player->getClass() == CLASS_SHAMAN && specialization == TALENT_SPEC_SHAMAN_ENHANCEMENT));
	}
};

// maddening eyes AT visual, spell timers might need recheck

class bfa_boss_uunat : public CreatureScript
{
public:
	bfa_boss_uunat() : CreatureScript("bfa_boss_uunat")
	{}

	struct bfa_boss_uunat_AI : public BossAI
	{
		bfa_boss_uunat_AI(Creature* creature) : BossAI(creature, DATA_UUNAT), summons(me)
		{
			instance = me->GetInstanceScript();
			me->SetPowerType(POWER_ENERGY);
			me->SetMaxPower(POWER_ENERGY, 100);
			me->SetPower(POWER_ENERGY, 0);
		}

		EventMap events;
		InstanceScript* instance;
		SummonList summons;

		bool introText;
		bool phase1;
		bool phase2;
		bool resonancePhase;
		bool phase3;
		bool canStartObscurity;
		uint8 obscurity;
		std::list<Player*> voidCrashTargets;

		void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
		{
			if (!me)
				return;

			if (me)
			{
				switch (selectedTextSound)
				{
				case 1:
					me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 2:
					me->Yell(INTRO_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 3:
					me->Yell(GIFT_HISTERYA_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 4:
					me->Yell(GIFT_LUNACY_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 5:
					me->Yell(GIFT_OBSCURITY_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 6:
					me->Yell(PHASE2_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 7:
					me->Yell(PHASE3_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 8:
					me->Yell(KILLED_TARGET, LANG_UNIVERSAL, NULL);
					break;
				case 9:
					me->Yell(DIED_TEXT, LANG_UNIVERSAL, NULL);
					break;
				}
			}
		}

		void KilledUnit(Unit*) 
		{
			SelectSoundAndText(me, 8);
		}
		void Reset() 
		{
			RemoveTormentFromPlayers();
			phase1 = false;
			introText = false;
			resonancePhase = false;
			phase2 = false;
			phase3 = false;
			canStartObscurity = false;
			summons.DespawnAll();
			me->RemoveAllAreaTriggers();
			events.Reset();
			DespawnRelics(NPC_VOID_RELIC);
			DespawnRelics(NPC_TRIDENT_RELIC);
			DespawnRelics(NPC_TEMPEST_RELIC);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
		}

		void MoveInLineOfSight(Unit* who) 
		{
			if (!introText)
			{
				Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
					if (Player* pPlayer = itr->GetSource())
						if (pPlayer->IsAlive() && pPlayer->IsWithinDist(me, 80.f))
						{
							SelectSoundAndText(me, 2);
							introText = true;
							return;
						}
			}
		}

		void JustDied(Unit*) 
		{
			RemoveTormentFromPlayers();
			SelectSoundAndText(me, 9);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			me->RemoveAllAreaTriggers();
			DespawnRelics(NPC_VOID_RELIC);
			DespawnRelics(NPC_TRIDENT_RELIC);
			DespawnRelics(NPC_TEMPEST_RELIC);
		}

		void EnterEvadeMode(EvadeReason why) 
		{
			RemoveTormentFromPlayers();
			DespawnRelics(NPC_VOID_RELIC);
			DespawnRelics(NPC_TRIDENT_RELIC);
			DespawnRelics(NPC_TEMPEST_RELIC);
			me->RemoveAllAreaTriggers();
			summons.DespawnAll();
			_DespawnAtEvade(15);
		}

		void AddVoidStoneRelicCheck()
		{
			std::list<Player*> healList;
			me->GetPlayerListInGrid(healList, 500.0f);
			healList.remove_if(dpsSpecs());
			healList.remove_if(tankSpecs());
			if (!healList.empty())
			{
				for (auto healers : healList)
				{
					me->AddAura(SPELL_VOID_STONE_ALLOW_CLICK, healers);
				}
			}
		}

		void AddTempestCallerRelicCheck()
		{
			std::list<Player*> dpsList;
			me->GetPlayerListInGrid(dpsList, 500.0f);
			dpsList.remove_if(healSpecs());
			dpsList.remove_if(tankSpecs());
			if (!dpsList.empty())
			{
				for (auto dps : dpsList)
				{
					me->AddAura(SPELL_TEMPEST_CALLER_ALLOW_CLICK, dps);
				}
			}

		}

		void SummonRelics()
		{
			AddVoidStoneRelicCheck();
			AddTempestCallerRelicCheck();

			if(Creature* voidRelic = me->SummonCreature(NPC_VOID_RELIC, 3485.75f, -1112.34f, -384.44f, TEMPSUMMON_MANUAL_DESPAWN))
				voidRelic->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
			if (Creature* tempestRelic = me->SummonCreature(NPC_TEMPEST_RELIC, 3495.06f, -1112.90f, -384.60f, TEMPSUMMON_MANUAL_DESPAWN))
				tempestRelic->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
			if (Creature* tridentRelic = me->SummonCreature(NPC_TRIDENT_RELIC, 3475.72f, -1111.14f, -384.46f, TEMPSUMMON_MANUAL_DESPAWN))
				tridentRelic->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
		}

		void DamageTaken(Unit* t, uint32& damage) 
		{
			if (me->HealthBelowPct(70) && !phase2)
			{
				phase1 = false;
				phase2 = true;
				HandlePhase(2);
			}

			if (me->HealthBelowPct(45) && !phase3)
			{
				phase2 = false;
				phase3 = true;
				HandlePhase(3);
			}
		}

		void JustSummoned(Creature* summon) 
		{
			summons.Summon(summon);

			switch (summon->GetEntry())
			{
			case NPC_UNDYING_GUARDIAN:
			case NPC_PRIMORDIAL_MINDBENDER:
				summon->SetInCombatWithZone();
				break;
			}
		}

		void RemoveTormentFromPlayers()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (player->HasAura(SPELL_INSATIABLE_TORMENT))
					{
						player->RemoveAura(SPELL_INSATIABLE_TORMENT);
					}
				}
		}

		void DespawnRelics(uint32 entry)
		{
			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					NowCreature->DespawnOrUnsummon();
		}

		void HandlePiercingGaze()
		{
			switch (rand() & 2)
			{
			case 1:
			{
				if (Creature* eyeTrigger = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3549.13f, -1120.18f, -371.38f, 2.96f, TEMPSUMMON_MANUAL_DESPAWN))
				{
					if (Creature* movementTrigger = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3424.27f, -1097.99f, -378.43f, TEMPSUMMON_MANUAL_DESPAWN))
					{
						eyeTrigger->AddUnitState(UNIT_STATE_ROOT);
						eyeTrigger->AI()->AttackStart(movementTrigger);
						eyeTrigger->SetFacingToObject(movementTrigger);
						movementTrigger->SetDisplayId(1607);
						movementTrigger->GetMotionMaster()->MovePoint(0, 3434.70f, -1022.87f, -371.17f);
					}
				}

				if (Creature* eyeTrigger2 = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3445.67f, -1155.84f, -370.95f, 0.89f, TEMPSUMMON_MANUAL_DESPAWN))
				{
					if (Creature* movementTrigger2 = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3559.88f, -1097.36f, -372.46f, TEMPSUMMON_MANUAL_DESPAWN))
					{
						eyeTrigger2->AddUnitState(UNIT_STATE_ROOT);
						eyeTrigger2->AI()->AttackStart(movementTrigger2);
						eyeTrigger2->SetFacingToObject(movementTrigger2);
						movementTrigger2->SetDisplayId(1607);
						movementTrigger2->GetMotionMaster()->MovePoint(0, 3459.68f, -1006.74f, -376.41f);
					}
				}
				break;
			}
			case 2:
			{
				if (Creature* eyeTrigger = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3430.03f, -124.17f, -370.11f, 5.42f, TEMPSUMMON_MANUAL_DESPAWN))
				{
					if (Creature* movementTrigger = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3553.15f, -1056.46f, -376.80f, TEMPSUMMON_MANUAL_DESPAWN))
					{
						eyeTrigger->AddUnitState(UNIT_STATE_ROOT);
						eyeTrigger->AI()->AttackStart(movementTrigger);
						eyeTrigger->SetFacingToObject(movementTrigger);
						movementTrigger->SetDisplayId(1607);
						movementTrigger->GetMotionMaster()->MovePoint(0, 3509.77f, -1143.68f, -377.76f);
					}
				}

				if (Creature* eyeTrigger2 = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3543.35f, -1024.56f, -363.77f, 4.00f,TEMPSUMMON_MANUAL_DESPAWN))
				{
					if (Creature* movementTrigger2 = me->SummonCreature(NPC_PIERCING_GAZE_TRIGGER, 3453.96f, -1140.97f, -372.28f,TEMPSUMMON_MANUAL_DESPAWN))
					{
						eyeTrigger2->AddUnitState(UNIT_STATE_ROOT);
						eyeTrigger2->AI()->AttackStart(movementTrigger2);
						eyeTrigger2->SetFacingToObject(movementTrigger2);
						movementTrigger2->SetDisplayId(1607);
						movementTrigger2->GetMotionMaster()->MovePoint(0, 3424.25f, -1040.97f, -372.10f);
					}
				}

				break;
			}
			}

			me->GetScheduler()//.Schedule(10s, [this](TaskContext /*context*/)
				{
					DespawnPiercingGaze();
				}//);
		}

		void DespawnPiercingGaze()
		{
			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, me, NPC_PIERCING_GAZE_TRIGGER, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					NowCreature->DespawnOrUnsummon();
		}

		void HandlePhase(uint32 phase)
		{
			switch (phase)
			{
			case 1:
				events.Reset();
				SummonRelics();
				obscurity = 0;
				me->GetMotionMaster()->MovePoint(POINT_VOID_SHIELD, 3486.29f, -1041.76f, -383.98f);

				events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
				events.ScheduleEvent(EVENT_OBLIVION_TEAR, TIMER_OBLIVION_TEAR);
				events.ScheduleEvent(EVENT_MADDENING_EYE, TIMER_MADDENING_EYE);
				events.ScheduleEvent(EVENT_PIERCING_GAZE, TIMER_PIERCING_GAZE);
				events.ScheduleEvent(EVENT_TOUCH_OF_THE_END, TIMER_TOUCH_OF_THE_END);
				
				if (me->GetMap()->IsHeroic())
					events.ScheduleEvent(EVENT_VOID_CRASH, TIMER_VOID_CRASH);
				if (me->GetMap()->IsMythic())
					events.ScheduleEvent(EVENT_UNSTABLE_RESONANCE, TIMER_UNSTABLE_RESONANCE);

				events.ScheduleEvent(EVENT_SUMMON_GUARDIANS, TIMER_SUMMON_GUARDIANS);
				break;
			case 2:
				events.Reset();
				SelectSoundAndText(me, 6);
				canStartObscurity = false;
				me->SetPower(POWER_ENERGY, 0);
				me->GetMotionMaster()->MovePoint(POINT_VOID_SHIELD, 3486.29f, -1041.76f, -383.98f);

				events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
				events.ScheduleEvent(EVENT_OBLIVION_TEAR, TIMER_OBLIVION_TEAR);
				events.ScheduleEvent(EVENT_TOUCH_OF_THE_END, TIMER_TOUCH_OF_THE_END);
				events.ScheduleEvent(EVENT_UNKNOWABLE_TERROR, TIMER_UNKNOWABLE_TERROR);

				if (me->GetMap()->IsMythic())
					events.ScheduleEvent(EVENT_UNSTABLE_RESONANCE, TIMER_UNSTABLE_RESONANCE);

				events.ScheduleEvent(EVENT_SUMMON_PRIMORDIAL_MINDBENDER, TIMER_SUMMON_PRIMORDIAL_MINDBENDER);
				events.ScheduleEvent(EVENT_SUMMON_GUARDIANS, TIMER_SUMMON_GUARDIANS);
				break;
			case 3:
				events.Reset();

				me->SetPower(POWER_ENERGY, 0);
				SelectSoundAndText(me, 7);
				me->GetMotionMaster()->MovePoint(POINT_VOID_SHIELD, 3486.29f, -1041.76f, -383.98f);
				events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
				events.ScheduleEvent(EVENT_OBLIVION_TEAR, TIMER_OBLIVION_TEAR);
				events.ScheduleEvent(EVENT_TOUCH_OF_THE_END, TIMER_TOUCH_OF_THE_END);
				events.ScheduleEvent(EVENT_INSATIABLE_TORMENT, TIMER_INSATIABLE_TORMENT);

				if(me->GetMap()->IsHeroic())
					events.ScheduleEvent(EVENT_PIERCING_GAZE, TIMER_PIERCING_GAZE);
				if (me->GetMap()->IsMythic())
					events.ScheduleEvent(EVENT_UNSTABLE_RESONANCE, TIMER_UNSTABLE_RESONANCE);

				events.ScheduleEvent(EVENT_SUMMON_GUARDIANS, TIMER_SUMMON_GUARDIANS);
				break;
			}
		}

		void MovementInform(uint32 type, uint32 pointId)
		{
			switch (pointId)
			{
			case POINT_VOID_SHIELD:
				me->CastSpell(me, SPELL_VOID_SHIELD, true);
				break;
			}
		}

		void JustEngagedWith(Unit*)
		{
			HandlePhase(1);
			voidCrashTargets.clear();
			phase1 = true;
			SelectSoundAndText(me, 1);

			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
		}

		void DistanceCheck(float distance)
		{
			if (canStartObscurity)
			{
				Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
					if (Player* player = i->GetSource())
					{
						if (!player->IsGameMaster()) //gm check
						{
							if (player->GetDistance(centerPos.GetPositionX(), centerPos.GetPositionY(), centerPos.GetPositionZ()) >= distance)
							{
								me->CastSpell(player, SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_DAMAGE, true);
							}
						}

					}
			}
		}

		void CheckObscurityDistance()
		{
			if (obscurity >= 1)
			{
				DistanceCheck(50.0f);
			}
			else if (obscurity >= 2)
			{
				DistanceCheck(40.0f);
			}
			else if (obscurity >= 3)
			{
				DistanceCheck(30.0f);
			}
			else if (obscurity >= 4)
			{
				DistanceCheck(20.0f);
			}
		}

		void NextVoidCrash(bool middle, bool low, bool clearList)
		{
			if (middle)
			{
				if (!voidCrashTargets.empty())
				{
					for (auto crashTarget : voidCrashTargets)
						me->CastSpell(crashTarget, SPELL_VOID_CRASH_MID);
				}
			}

			if (low)
			{
				if (!voidCrashTargets.empty())
				{
					for (auto crashTarget : voidCrashTargets)
						me->CastSpell(crashTarget, SPELL_VOID_CRASH_LOW);
				}
			}

			if (clearList)
				voidCrashTargets.clear();
		}

		void HandleUnstableResonanceEffect()
		{
			// 4 players each resonance Storm > Void > Ocean

			UnstableResonanceStorm();

			me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
				{
					UnstableResonanceVoid();
				});

			me->GetScheduler().Schedule(4s, [this](TaskContext /*context*/)
				{
					UnstableResonanceOcean();
				});
		}

		void UnstableResonanceStorm()
		{
			std::list<Player*> playerList;
			me->GetPlayerListInGrid(playerList, 500.0f);
			playerList.remove_if(tankSpecs());
			if (!playerList.empty())
			{
				if (playerList.size() >= 4)
					playerList.resize(4);

				for (auto target : playerList)
				{
					me->AddAura(SPELL_UNSTABLE_STORM, target);
				}
			}
		}

		void UnstableResonanceVoid()
		{
			std::list<Player*> playerList;
			me->GetPlayerListInGrid(playerList, 500.0f);
			playerList.remove_if(tankSpecs());
			playerList.remove_if(noResonanceStorm());
			if (!playerList.empty())
			{
				if (playerList.size() >= 4)
					playerList.resize(4);

				for (auto target : playerList)
				{
					me->AddAura(SPELL_UNSTABLE_VOID, target);
				}
			}
		}

		void UnstableResonanceOcean()
		{
			std::list<Player*> playerList;
			me->GetPlayerListInGrid(playerList, 500.0f);
			playerList.remove_if(tankSpecs());
			playerList.remove_if(noResonanceStorm());
			playerList.remove_if(noResonanceVoid());
			if (!playerList.empty())
			{
				if (playerList.size() >= 4)
					playerList.resize(4);

				for (auto target : playerList)
				{
					me->AddAura(SPELL_UNSTABLE_OCEAN, target);
				}
			}
		}



		void CheckResonanceDistance()
		{
			if (resonancePhase)
			{
				Player* voidPlayer = NULL;
				Player* stormPlayer = NULL;
				Player* oceanPlayer = NULL;
				std::list<Player*> specialPlayerList;
				// insert all UNSTABLE player into a list, should not crash anymore because won't execute if list is not filled
				// auracheck check was correct but it may crash since there's not another player nearby
				Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
					if (Player* player = i->GetSource())
					{
						if (player->IsAlive() && !player->IsGameMaster())
						{
							if (player->HasAura(SPELL_UNSTABLE_OCEAN))
							{
								oceanPlayer = player;
								specialPlayerList.push_back(oceanPlayer);
							}
							if (player->HasAura(SPELL_UNSTABLE_VOID))
							{
								voidPlayer = player;
								specialPlayerList.push_back(voidPlayer);
							}

							if (player->HasAura(SPELL_UNSTABLE_STORM))
							{
								stormPlayer = player;
								specialPlayerList.push_back(stormPlayer);
							}

							// additional checks, is UNSTABLE has players in it, check for special units, if they are present, execute
							if (specialPlayerList.size())
							{
								if (oceanPlayer)
								{
									if (oceanPlayer->GetDistance(voidPlayer) <= 3.5f || oceanPlayer->GetDistance(stormPlayer) <= 3.5f)
									{
										oceanPlayer->RemoveAura(SPELL_UNSTABLE_OCEAN);
										oceanPlayer->CastSpell(oceanPlayer, SPELL_UNSTABLE_RESONANCE_DAMAGE, true);
									}
								}

								if (voidPlayer)
								{
									if (voidPlayer->GetDistance(stormPlayer) <= 3.5f || voidPlayer->GetDistance(oceanPlayer) <= 3.5f)
									{
										voidPlayer->RemoveAura(SPELL_UNSTABLE_VOID);
										voidPlayer->CastSpell(voidPlayer, SPELL_UNSTABLE_RESONANCE_DAMAGE, true);
									}
								}

								if (stormPlayer)
								{
									if (stormPlayer->GetDistance(voidPlayer) <= 3.5f || stormPlayer->GetDistance(oceanPlayer) <= 3.5f)
									{
										stormPlayer->RemoveAura(SPELL_UNSTABLE_STORM);
										stormPlayer->CastSpell(stormPlayer, SPELL_UNSTABLE_RESONANCE_DAMAGE, true);
									}
								}
							}
						}
					}
			}
		}

		void OnSpellFinished(SpellInfo const* spellInfo) //override
		{
			switch (spellInfo->Id)
			{
			case SPELL_UNSTABLE_RESONANCE_CAST:
			{
				resonancePhase = true;
				HandleUnstableResonanceEffect();
				me->GetScheduler().Schedule(15s, [this](TaskContext /*context*/)
					{
						resonancePhase = false;
					});
				break;
			}
			}
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);

			CheckObscurityDistance();
			if (!UpdateVictim())
				return;

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			if (resonancePhase)
				CheckResonanceDistance();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_ENERGY_REGEN:
				{
					me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 5));

					if (me->GetPower(POWER_ENERGY) == 100)
					{
						me->SetPower(POWER_ENERGY, 0);
						if (phase1)
							events.ScheduleEvent(EVENT_GIFT_OF_NZOTH_OBSCURITY, 1000);
						else if (phase2)
							events.ScheduleEvent(EVENT_GIFT_OF_NZOTH_HYSTERIA, 1000);
						else if (phase3)
							events.ScheduleEvent(EVENT_GIFT_OF_NZOTH_LUNACY, 1000);
					}
					events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
					break;
				}
				case EVENT_GIFT_OF_NZOTH_LUNACY:
					SelectSoundAndText(me, 4);
					me->CastSpell(me->GetVictim(), SPELL_GIFT_OF_NZOTH_LUNACY);
					break;
				case EVENT_GIFT_OF_NZOTH_OBSCURITY:
				{
					SelectSoundAndText(me, 5);
					++obscurity;
					canStartObscurity = true;
					if (obscurity >= 1)
					{
						me->CastSpell(centerPos, SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_1, true);
					}
					else if (obscurity >= 2)
					{
						me->RemoveAreaTrigger(SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_1);
						me->CastSpell(centerPos, SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_2, true);
					}
					else if (obscurity >= 3)
					{
						me->RemoveAreaTrigger(SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_2);
						me->CastSpell(centerPos, SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_3, true);
					}
					else if (obscurity >= 4)
					{
						me->RemoveAreaTrigger(SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_3);
						me->CastSpell(centerPos, SPELL_GIFT_OF_NZOTH_OBSCURITY_AT_4, true);
					}
					break;
				}
				case EVENT_GIFT_OF_NZOTH_HYSTERIA:
					SelectSoundAndText(me, 3);
					me->CastSpell(me, SPELL_GIFT_OF_NZOTH_HYSTERIA_CAST);
					break;
				case EVENT_PIERCING_GAZE:
					HandlePiercingGaze();
					events.ScheduleEvent(EVENT_PIERCING_GAZE, TIMER_PIERCING_GAZE);
					break;
				case EVENT_TOUCH_OF_THE_END:
					me->CastSpell(me->GetVictim(), SPELL_TOUCH_OF_THE_END);
					events.ScheduleEvent(EVENT_TOUCH_OF_THE_END, TIMER_TOUCH_OF_THE_END);
					break;
				case EVENT_VOID_CRASH:
				{
					voidCrashTargets.clear();

					me->GetPlayerListInGrid(voidCrashTargets, 100.0f);
					if (!voidCrashTargets.empty())
						voidCrashTargets.resize(2);

					for (auto crashTarget : voidCrashTargets)
					{
						me->CastSpell(crashTarget, SPELL_VOID_CRASH_BIG);
					}
					events.ScheduleEvent(EVENT_VOID_CRASH, TIMER_VOID_CRASH);
					break;
				}
				case EVENT_OBLIVION_TEAR:
				{
					std::list<Player*> playerList;
					me->GetPlayerListInGrid(playerList, 100.0f);

					if (!playerList.empty())
					{
						playerList.resize(1);
					}

					for (auto player : playerList)
					{
						me->CastSpell(player, SPELL_OBLIVION_TEAR_MISSILE_PLAYER);
					}

					events.ScheduleEvent(EVENT_OBLIVION_TEAR, TIMER_OBLIVION_TEAR);
					break;
				}
				case EVENT_MADDENING_EYE:
					break;
				case EVENT_SUMMON_GUARDIANS:
					for (uint8 i = 0; i < 1; ++i)
						me->SummonCreature(NPC_UNDYING_GUARDIAN, addsSummonPos[i], TEMPSUMMON_CORPSE_DESPAWN);
					events.ScheduleEvent(EVENT_SUMMON_GUARDIANS, TIMER_SUMMON_GUARDIANS);
					break;
				case EVENT_SUMMON_PRIMORDIAL_MINDBENDER:
					if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
					{
						for (uint8 i = 0; i < 3; ++i)
							me->SummonCreature(NPC_PRIMORDIAL_MINDBENDER, addsSummonPos[i], TEMPSUMMON_CORPSE_DESPAWN);
					}
					else
					{
						for (uint8 i = 0; i < 2; ++i)
							me->SummonCreature(NPC_PRIMORDIAL_MINDBENDER, addsSummonPos[i], TEMPSUMMON_CORPSE_DESPAWN);
					}

					events.ScheduleEvent(EVENT_SUMMON_PRIMORDIAL_MINDBENDER, TIMER_SUMMON_PRIMORDIAL_MINDBENDER);
					break;
				case EVENT_UNSTABLE_RESONANCE:
					me->CastSpell(me, SPELL_UNSTABLE_RESONANCE_CAST);
					events.ScheduleEvent(EVENT_UNSTABLE_RESONANCE, TIMER_UNSTABLE_RESONANCE);
					break;
				case EVENT_INSATIABLE_TORMENT:
				{
					std::list<Player*> playerList;
					me->GetPlayerListInGrid(playerList, 100.0f);
					playerList.remove_if(tankSpecs());
					if (!playerList.empty())
						playerList.resize(1);

					for (auto target : playerList)
					{
						me->CastSpell(target, SPELL_INSATIABLE_TORMENT);
					}
					events.ScheduleEvent(EVENT_INSATIABLE_TORMENT, TIMER_INSATIABLE_TORMENT);
					break;
				}
				case EVENT_UNKNOWABLE_TERROR:
					me->CastSpell(3506.11f, -1167.28f, -375.83f, SPELL_UNKNOWABLE_TERROR_CAST);
					events.ScheduleEvent(EVENT_UNKNOWABLE_TERROR, TIMER_UNKNOWABLE_TERROR);
					break;
				}
			}
			DoMeleeAttackIfReady();
		}
	};
	
	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_boss_uunat_AI(creature);
	}
};

// 293968, 282405, 282418
class bfa_spell_void_crash_missile : public SpellScriptLoader
{
public:
	bfa_spell_void_crash_missile() : SpellScriptLoader("bfa_spell_void_crash_missile") { }

	class bfa_spell_void_crash_missile_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_void_crash_missile_SpellScript);

		void OnSpellHit(SpellEffIndex)
		{
			Unit* caster = GetCaster();
			Unit* target = GetHitUnit();

			if (!caster || !target)
				return;

			if (Creature* uunat = target->FindNearestCreature(BOSS_UUNAT, 500.0f, true))
			{
				switch (GetSpellInfo()->Id)
				{
				case SPELL_VOID_CRASH_BIG:
					CAST_AI(bfa_boss_uunat::bfa_boss_uunat_AI, uunat->AI())->NextVoidCrash(true, false, false);
					break;
				case SPELL_VOID_CRASH_MID:
					CAST_AI(bfa_boss_uunat::bfa_boss_uunat_AI, uunat->AI())->NextVoidCrash(false, true, false);
					break;
				case SPELL_VOID_CRASH_LOW:
					CAST_AI(bfa_boss_uunat::bfa_boss_uunat_AI, uunat->AI())->NextVoidCrash(false, false, true);
					break;
				}
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(bfa_spell_void_crash_missile_SpellScript::OnSpellHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_void_crash_missile_SpellScript();
	}
};

class bfa_npc_undying_guardian : public CreatureScript
{
public:
    bfa_npc_undying_guardian() : CreatureScript("bfa_npc_undying_guardian")
    {}

    struct bfa_npc_undying_guardian_AI : public ScriptedAI
    {
        bfa_npc_undying_guardian_AI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 0);
        }

        EventMap events;
        bool regen;

        void Reset() 
        {
            regen = false;
            events.Reset();
        }

        void DamageTaken(Unit* at, uint32& damage) 
        {
            if (damage >= me->GetHealth() && !regen)
            {
                regen = true;
                damage = 0;
                me->CastSpell(me, SPELL_UNNATURAL_REGENERATION);
            }
        }
        void JustEngagedWith(Unit*)
        {
            if (me->GetMap()->IsMythic())
        	{
        		me->CastSpell(me, SPELL_HUNGER_FOR_THE_END, true);
        		events.ScheduleEvent(EVENT_ENERGY_REGEN, TIMER_ENERGY_REGEN);
        	}

            events.ScheduleEvent(EVENT_FIXATE_TANK, 2000);
            events.ScheduleEvent(EVENT_SIGHTLESS_BOND, 3000);
            me->CastSpell(me, SPELL_SHROUD_OF_WHISPERS, true);
        }

        void CheckHealthRegen()
        {
            if (me->GetHealth() == me->GetMaxHealth() && regen && me->HasAura(SPELL_UNNATURAL_REGENERATION))
            {
                me->CastStop();
                regen = false;
            }
        }

        void UpdateHungerState()
        {
            if (Aura* hunger = me->GetAura(SPELL_HUNGER_FOR_THE_END_AURA))
            {
                if (hunger->GetStackAmount() >= 15)
                {
                    	me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_INTERRUPT_FLAG_INTERRUPT, true);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_AURA_MOD_STUN, true);
                }
                else
                {
                    me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_INTERRUPT_FLAG_INTERRUPT, false);
                    me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_AURA_MOD_STUN, false);
                }
            }
        }
        void UpdateAI(uint32 diff) 
        {
            events.Update(diff);

            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->IsInCombat())
            {
                CheckHealthRegen();
                UpdateHungerState();
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_FIXATE_TANK:
                {
                    std::list<Player*> playerList;
                    me->GetPlayerListInGrid(playerList, 100.0f);
                    playerList.remove_if(notAvailableTarget());

                    if (!playerList.empty())
                    {
                        playerList.resize(1);
                    }

                    for (auto player : playerList)
                    {
                        me->AddThreat(player, 9999999.9f);
                        me->AI()->AttackStart(player);
                    }
                    events.ScheduleEvent(EVENT_FIXATE_TANK, 10 * IN_MILLISECONDS); // just to make sure its still on tank
                    break;
                }
                case EVENT_SIGHTLESS_BOND:
                {
                    std::list<Creature*> uunat;
                    GetCreatureListWithEntryInGrid(uunat, me, BOSS_UUNAT, 200.0f);
                    if (!uunat.empty())
                    {
                        for (auto boss : uunat)
                        {
                            if (me->GetDistance(boss) <= 10.0f)
                                me->CastSpell(me, SPELL_SIGHTLESS_BOND, true);
                            else
                                me->RemoveAura(SPELL_SIGHTLESS_BOND);
                        }
                    }
                    events.ScheduleEvent(EVENT_SIGHTLESS_BOND, 2000);
                    break;
                }
                case EVENT_ENERGY_REGEN:
                    me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + urand(1, 5));

                    if (me->GetPower(POWER_ENERGY) == 100)
                    {
                        me->CastSpell(me->GetVictim(), SPELL_FEED);
                        me->SetPower(POWER_ENERGY, 0);
                    }
                    events.ScheduleEvent(EVENT_ENERGY_REGEN, 3000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_undying_guardian_AI(creature);
	}
};


class bfa_npc_primordial_mindbender : public CreatureScript
{
public:
	bfa_npc_primordial_mindbender() : CreatureScript("bfa_npc_primordial_mindbender")
	{}

	struct bfa_npc_primordial_mindbender_AI : public ScriptedAI
	{
		bfa_npc_primordial_mindbender_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->AddAura(42716, me);
		}

		EventMap events;

		void Reset() 
		{
			events.Reset();
		}

		void JustEngagedWith(Unit*)
		{
			if (me->GetMap()->IsMythic())
			{
				me->CastSpell(me, SPELL_HUNGER_FOR_THE_END, true);
			}

			events.ScheduleEvent(EVENT_CONSUME_ESSENCE, 1500);
		}

		void JustDied(Unit*) 
		{
			for (uint8 i = 0; i < 3; ++i)
				me->SummonCreature(NPC_SWARMING_VOIDSPAWN, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_CORPSE_DESPAWN);

		}

		void OnSpellCastInterrupt(SpellInfo const* spell) 
		{
			if (me->HasAura(42716))
			{
				events.ScheduleEvent(EVENT_CONSUME_ESSENCE, 3000);
			}
		}

		void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			if (!UpdateVictim())
				return;

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_CONSUME_ESSENCE:
					me->CastSpell(me, SPELL_CONSUME_ESSENCE);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_primordial_mindbender_AI(creature);
	}
};


class bfa_npc_swarming_voidspawns : public CreatureScript
{
public:
	bfa_npc_swarming_voidspawns() : CreatureScript("bfa_npc_swarming_voidspawns")
	{}

	struct bfa_npc_swarming_voidspawns_AI : public ScriptedAI
	{
		bfa_npc_swarming_voidspawns_AI(Creature* creature) : ScriptedAI(creature)
		{
		}

		EventMap events;

		void Reset() 
		{
			events.Reset();
		}

		void JustEngagedWith(Unit*)
		{
			if (me->GetMap()->IsMythic())
			{
				events.ScheduleEvent(EVENT_VOIDSTEP, TIMER_VOIDSTEP);
				me->CastSpell(me, SPELL_HUNGER_FOR_THE_END, true);
			}
		}

		void DamageTaken(Unit* at, uint32& damage) 
		{
			if (damage >= me->GetHealth())
			{
				damage = 0;
				me->CastSpell(me, SPELL_VOID_ERUPTION, true);
				me->DespawnOrUnsummon(1000);
			}
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);

			if (!UpdateVictim())
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_VOIDSTEP:
				{
					std::list<Player*> playerList;
					me->GetPlayerListInGrid(playerList, 100.0f);
					if (!playerList.empty())
					{
						playerList.resize(1);
					}

					for (auto player : playerList)
					{
						me->SetFacingToObject(player);
						me->NearTeleportTo(player->GetPosition(), false);
						me->CastSpell(player, SPELL_VOIDSTEP, true);
					}
					events.ScheduleEvent(EVENT_VOIDSTEP, TIMER_VOIDSTEP);
					break;
				}
				}
			}
			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_swarming_voidspawns_AI(creature);
	}
};

// 285210 - 15417
class bfa_at_oblivion_terror : public AreaTriggerEntityScript
{
public:
	bfa_at_oblivion_terror() : AreaTriggerEntityScript("bfa_at_oblivion_terror") { }

	struct bfa_at_oblivion_terror_AI : AreaTriggerAI
	{
		bfa_at_oblivion_terror_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }


		void OnUnitEnter(Unit* unit) 
		{
			if (unit->IsPlayer() && !unit->ToPlayer()->IsGameMaster())
			{
				if (Creature* uunat = unit->FindNearestCreature(BOSS_UUNAT, 500.0f, true))
				{
					unit->CastSpell(uunat, SPELL_OBLIVION_TEAR_MISSILE_BOSS, true);
					at->Remove();
				}
			 }
		}

	};

	AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const 
	{
		return new bfa_at_oblivion_terror_AI(areatrigger);
	}
};

// 285638
class bfa_spell_gift_of_nzoth_hysteria : public SpellScriptLoader
{
public:
	bfa_spell_gift_of_nzoth_hysteria() : SpellScriptLoader("bfa_spell_gift_of_nzoth_hysteria") {}

	class bfa_spell_gift_of_nzoth_hysteria_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_gift_of_nzoth_hysteria_SpellScript);

		void HandleAfterCast()
		{
			Unit* caster = GetCaster();
			if (!caster)
				return;

			std::list<Creature*> creatureList;
			caster->GetCreatureListWithEntryInGrid(creatureList, NPC_UNDYING_GUARDIAN, 200.0f);
			caster->GetCreatureListWithEntryInGrid(creatureList, NPC_SWARMING_VOIDSPAWN, 200.0f);
			caster->GetCreatureListWithEntryInGrid(creatureList, NPC_PRIMORDIAL_MINDBENDER, 200.0f);
			if (!creatureList.empty())
			{
				for (auto creature : creatureList)
					caster->AddAura(SPELL_GIFT_OF_NZOTH_HYSTERIA_AURA, creature);
			}
		}

		void Register()
		{
			AfterCast += SpellCastFn(bfa_spell_gift_of_nzoth_hysteria_SpellScript::HandleAfterCast);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_gift_of_nzoth_hysteria_SpellScript();
	}
};

class bfa_npc_piercing_gaze_trigger : public CreatureScript
{
public:
	bfa_npc_piercing_gaze_trigger() : CreatureScript("bfa_npc_piercing_gaze_trigger")
	{}

	struct bfa_npc_piercing_gaze_trigger_AI : public ScriptedAI
	{
		bfa_npc_piercing_gaze_trigger_AI(Creature* creature) : ScriptedAI(creature)
		{
		}

		EventMap events;
		uint32 checkTimer;
		void Reset() 
		{
			events.Reset();
			checkTimer = 0;
		}

		bool IsOnBeam(WorldObject* obj, Position source, Position destination, float heightDiff, float beamWidth, float beamLenght)
		{
			if (beamLenght < obj->GetExactDist2d(source.GetPositionX(), source.GetPositionY()))
				return false;

			if (obj->GetPositionZ() - heightDiff > std::max(source.GetPositionZ(), destination.GetPositionZ()) &&
				obj->GetPositionZ() + heightDiff < std::min(source.GetPositionZ(), destination.GetPositionZ()))
				return false;

			float angleSourceDest = source.GetAngle(&destination);
			float angleSourcePoint = source.GetAngle(obj);

			float angle = fabs(angleSourceDest - angleSourcePoint);
			return fabs(sin(angle)) * source.GetExactDist2d(obj->GetPositionX(), obj->GetPositionY()) < beamWidth;
		}

		void UpdateAI(uint32 diff) 
		{
			checkTimer += diff;

			if (checkTimer >= 2 * IN_MILLISECONDS)
			{
				Unit* maintrigger = me;
				Unit* triggerTarget = me->GetVictim();
				Unit* targetPlayer = NULL;

				if (!maintrigger || !triggerTarget)
					return;

				Map::PlayerList const& playerList = maintrigger->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
					if (Player* player = i->GetSource())
					{
						Position myPos = maintrigger->GetPosition();
						Position triggerPos = triggerTarget->GetPosition();
						if (IsOnBeam(player, myPos, triggerPos, 5.0f, 3.0f, maintrigger->GetExactDist2d(triggerTarget)) && maintrigger->isInFront(player))
						{
							maintrigger->CastSpell(player, SPELL_PIERCING_GAZE_OF_NZOTH_AURA, true);
						}
					}
			}
			checkTimer = 0;
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_piercing_gaze_trigger_AI(creature);
	}
};

class bfa_npc_void_stone_relic : public CreatureScript
{
public:
	bfa_npc_void_stone_relic() : CreatureScript("bfa_npc_void_stone_relic") { }

	bool OnGossipHello(Player* player, Creature* me)
	{
		if (!me || !player)
			return false;

		if (!player->HasAura(SPELL_FEEDBACK_VOID) && player->HasAura(SPELL_VOID_STONE_ALLOW_CLICK))
		{
			me->CastSpell(player, SPELL_VOID_STONE_BUTTON, true);
			me->DespawnOrUnsummon();
		}
		return true;
	}

	struct bfa_npc_void_stone_relic_AI : public ScriptedAI
	{
		bfa_npc_void_stone_relic_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->CastSpell(me, SPELL_VOID_NPC_VISUAL, true);
		}

		EventMap events;

		void Reset() 
		{
			events.Reset();
		}

		void DoAction(int32 action)
		{
			switch (action)
			{
			case ACTION_REGEN_RELIC:
				events.ScheduleEvent(EVENT_RELIC_REGEN, 60 * IN_MILLISECONDS);
				break;
			}
		}

		void CheckUnstableResonanceDist()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster() && player->IsAlive() && player->HasAura(SPELL_UNSTABLE_VOID))
					{
						if (me->GetDistance(player) <= 2.0f)
						{
							player->RemoveAura(SPELL_UNSTABLE_VOID);
						}
					}
				}
		}

		void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			if (me->GetMap()->IsMythic())
				CheckUnstableResonanceDist();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_RELIC_REGEN:
					me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_void_stone_relic_AI(creature);
	}
};

// 284684
class bfa_spell_void_stone_relic_remove : public SpellScriptLoader
{
public:
	bfa_spell_void_stone_relic_remove() : SpellScriptLoader("bfa_spell_void_stone_relic_remove") { }

	class bfa_spell_void_stone_relic_remove_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_void_stone_relic_remove_SpellScript);

		void HandleAfterCast()
		{
			Unit* caster = GetCaster();
			if (!caster)
				return;
			caster->RemoveAura(SPELL_VOID_STONE_BUTTON);
			caster->AddAura(SPELL_FEEDBACK_VOID, caster);
			if (Creature* relicnpc = caster->SummonCreature(NPC_VOID_RELIC, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
				relicnpc->AI()->DoAction(ACTION_REGEN_RELIC);
		}

		void Register()
		{
			AfterCast += SpellCastFn(bfa_spell_void_stone_relic_remove_SpellScript::HandleAfterCast);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_void_stone_relic_remove_SpellScript();
	}
};

class bfa_npc_trident_of_deep_ocean_relic : public CreatureScript
{
public:
	bfa_npc_trident_of_deep_ocean_relic() : CreatureScript("bfa_npc_trident_of_deep_ocean_relic") { }

	bool OnGossipHello(Player* player, Creature* me)
	{
		if (!me || !player)
			return false;

		if (!player->HasAura(SPELL_FEEDBACK_OCEAN) && !player->HasAura(SPELL_VOID_STONE_ALLOW_CLICK) || !player->HasAura(SPELL_TEMPEST_CALLER_ALLOW_CLICK))
		{
			me->CastSpell(player, SPELL_TRIDENT_OF_DEEP_OCEAN_BUTTON, true);
			me->DespawnOrUnsummon();
		}
		return true;
	}

	struct bfa_npc_trident_of_deep_ocean_relic_AI : public ScriptedAI
	{
		bfa_npc_trident_of_deep_ocean_relic_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->CastSpell(me, SPELL_TRIDENT_NPC_VISUAL, true);
		}

		EventMap events;

		void Reset() 
		{
			events.Reset();
		}

		void DoAction(int32 action)
		{
			switch (action)
			{
			case ACTION_REGEN_RELIC:
				events.ScheduleEvent(EVENT_RELIC_REGEN, 120 * IN_MILLISECONDS);
				break;
			}
		}

		void CheckUnstableResonanceDist()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster() && player->IsAlive() && player->HasAura(SPELL_UNSTABLE_OCEAN))
					{
						if (me->GetDistance(player) <= 2.0f)
						{
							player->RemoveAura(SPELL_UNSTABLE_OCEAN);
						}
					}
				}
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);

			if (me->GetMap()->IsMythic())
				CheckUnstableResonanceDist();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_RELIC_REGEN:
					me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_trident_of_deep_ocean_relic_AI(creature);
	}
};

// 284768
class bfa_spell_trident_of_deep_ocean_relic_remove : public SpellScriptLoader
{
public:
	bfa_spell_trident_of_deep_ocean_relic_remove() : SpellScriptLoader("bfa_spell_trident_of_deep_ocean_relic_remove") { }

	class bfa_spell_trident_of_deep_ocean_relic_remove_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_trident_of_deep_ocean_relic_remove_SpellScript);

		void HandleAfterCast()
		{
			Unit* caster = GetCaster();
			if (!caster)
				return;
			caster->RemoveAura(SPELL_TRIDENT_OF_DEEP_OCEAN_BUTTON);
			caster->AddAura(SPELL_FEEDBACK_OCEAN, caster);
			caster->SummonCreature(NPC_OCEAN_RUNE, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN);
			if (Creature* relicnpc = caster->SummonCreature(NPC_TRIDENT_RELIC, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
				relicnpc->AI()->DoAction(ACTION_REGEN_RELIC);
		}

		void Register()
		{
			AfterCast += SpellCastFn(bfa_spell_trident_of_deep_ocean_relic_remove_SpellScript::HandleAfterCast);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_trident_of_deep_ocean_relic_remove_SpellScript();
	}
};

class bfa_npc_tempest_caller_relic : public CreatureScript
{
public:
	bfa_npc_tempest_caller_relic() : CreatureScript("bfa_npc_tempest_caller_relic") { }

	bool OnGossipHello(Player* player, Creature* me)
	{
		if (!me || !player)
			return false;

		if (!player->HasAura(SPELL_FEEDBACK_STORM) && !player->HasAura(SPELL_TEMPEST_CALLER_ALLOW_CLICK))
		{
			me->CastSpell(player, SPELL_TEMPEST_CALLER_BUTTON, true);
			me->DespawnOrUnsummon();
		}
		return true;
	}

	struct bfa_npc_tempest_caller_relic_AI : public ScriptedAI
	{
		bfa_npc_tempest_caller_relic_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->CastSpell(me, SPELL_TEMPEST_NPC_VISUAL, true);
		}

		EventMap events;

		void Reset() 
		{
			events.Reset();
		}

		void DoAction(int32 action)
		{
			switch (action)
			{
			case ACTION_REGEN_RELIC:
				events.ScheduleEvent(EVENT_RELIC_REGEN, 30 * IN_MILLISECONDS);
				break;
			}
		}

		void CheckUnstableResonanceDist()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster() && player->IsAlive() && player->HasAura(SPELL_UNSTABLE_STORM))
					{
						if (me->GetDistance(player) <= 2.0f)
						{
							player->RemoveAura(SPELL_UNSTABLE_STORM);
						}
					}
				}
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);

			if (me->GetMap()->IsMythic())
				CheckUnstableResonanceDist();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_RELIC_REGEN:
					me->SetNpcFlags(UNIT_NPC_FLAG_GOSSIP);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_tempest_caller_relic_AI(creature);
	}
};

// 284569
class bfa_spell_tempest_caller_relic_remove : public SpellScriptLoader
{
public:
	bfa_spell_tempest_caller_relic_remove() : SpellScriptLoader("bfa_spell_tempest_caller_relic_remove") { }

	class bfa_spell_tempest_caller_relic_remove_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_tempest_caller_relic_remove_SpellScript);

		void HandleAfterCast()
		{
			Unit* caster = GetCaster();
			if (!caster)
				return;
			caster->RemoveAura(SPELL_TEMPEST_CALLER_BUTTON);
			caster->AddAura(SPELL_FEEDBACK_STORM, caster);
			if(Creature* relicnpc = caster->SummonCreature(NPC_TEMPEST_RELIC, caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
				relicnpc->AI()->DoAction(ACTION_REGEN_RELIC);
		}

		void Register()
		{
			AfterCast += SpellCastFn(bfa_spell_tempest_caller_relic_remove_SpellScript::HandleAfterCast);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_tempest_caller_relic_remove_SpellScript();
	}
};

// 286754
class bfa_spell_storm_of_annihilation_effect : public SpellScriptLoader
{
public:
	bfa_spell_storm_of_annihilation_effect() : SpellScriptLoader("bfa_spell_storm_of_annihilation_effect") { }

	class bfa_spell_storm_of_annihilation_effect_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_storm_of_annihilation_effect_SpellScript);

		void DealDamage()
		{
			if (Unit* caster = GetCaster())
			{
				if (Unit* target = GetHitUnit())
				{
					if (target->HealthBelowPct(25))
						caster->CastSpell(target, SPELL_TEMPEST_CALLER_ANNIHILATE, true);
				}
			}
		}

		void Register()
		{
			OnHit += SpellHitFn(bfa_spell_storm_of_annihilation_effect_SpellScript::DealDamage);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_storm_of_annihilation_effect_SpellScript();
	}
};

class bfa_npc_ocean_rune_trigger : public CreatureScript
{
public:
	bfa_npc_ocean_rune_trigger() : CreatureScript("bfa_npc_ocean_rune_trigger") { }

	struct bfa_npc_ocean_rune_trigger_AI : public ScriptedAI
	{
		bfa_npc_ocean_rune_trigger_AI(Creature* creature) : ScriptedAI(creature)
		{
			instance = me->GetInstanceScript();
			me->AddUnitState(UNIT_STATE_ROOT);
		}

		EventMap events;
		InstanceScript* instance;

		void Reset() 
		{
			events.Reset();
			events.ScheduleEvent(EVENT_ABYSSAL_COLLAPSE, 20 * IN_MILLISECONDS);
			events.ScheduleEvent(EVENT_ADD_FRAME, 100);
		}

		void JustDied(Unit*) 
		{
			me->RemoveAreaTrigger(SPELL_CUSTODY_AT);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
		}

		void CheckNearbyPlayers()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster()) //gm check
					{
						if (me->GetDistance(player) <= 15.0f)
						{
							if(!player->HasAura(SPELL_CUSTODY_SHIELD))
								me->CastSpell(player, SPELL_CUSTODY_SHIELD, true);
						}
					}
				}
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);

			CheckNearbyPlayers();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_ADD_FRAME:
					instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
					break;
				case EVENT_REMOVE_FRAME:
					me->RemoveAreaTrigger(SPELL_CUSTODY_AT);
					instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
					break;
				case EVENT_ABYSSAL_COLLAPSE:
					me->CastSpell(me, SPELL_ABYSSAL_COLLAPSE, true);
					events.ScheduleEvent(EVENT_REMOVE_FRAME, 500);
					me->DespawnOrUnsummon(1000);
					break;
				}
			}
		}

	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_ocean_rune_trigger_AI(creature);
	}
};

// 284804
class bfa_spell_custody_of_deep_absorb : public SpellScriptLoader
{
public:
	bfa_spell_custody_of_deep_absorb() : SpellScriptLoader("bfa_spell_custody_of_deep_absorb")
	{}

	class bfa_spell_custody_of_deep_absorb_AuraScript : public AuraScript
	{
	public:
		PrepareAuraScript(bfa_spell_custody_of_deep_absorb_AuraScript);

		uint32 damageToRune;

		bool Load() 
		{
			damageToRune = 0;
			return true;
		}

		void HandleDmgAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
		{
			Unit* target = GetTarget();
			if (!target)
				return;

			damageToRune = absorbAmount / 0.75f; // 75% of absorbed damage is dealt  to rune

			if (Creature* oceanRune = target->FindNearestCreature(NPC_OCEAN_RUNE, 50.0f, true))
				target->DealDamage(oceanRune, damageToRune);
		}

		void Register()
		{
			AfterEffectAbsorb += AuraEffectAbsorbFn(bfa_spell_custody_of_deep_absorb_AuraScript::HandleDmgAbsorb, EFFECT_0);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_custody_of_deep_absorb_AuraScript();
	}
};

// 293662, 293661, 293663
class bfa_spell_unstable_resonance_remove_effect : public SpellScriptLoader
{
public:
	bfa_spell_unstable_resonance_remove_effect() : SpellScriptLoader("bfa_spell_unstable_resonance_remove_effect") { }

	class bfa_spell_unstable_resonance_remove_effect_AuraScript : public AuraScript
	{
		PrepareAuraScript(bfa_spell_unstable_resonance_remove_effect_AuraScript);

		void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			Unit* caster = GetCaster();
			Unit* target = GetTarget();
			if (!caster || !target)
				return;
			AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

			if(removeMode == AURA_REMOVE_BY_EXPIRE)
				target->CastSpell(target, SPELL_UNSTABLE_RESONANCE_DAMAGE, true);
		}

		void Register()
		{
			OnEffectRemove += AuraEffectRemoveFn(bfa_spell_unstable_resonance_remove_effect_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_unstable_resonance_remove_effect_AuraScript();
	}
};

// 285652
class bfa_spell_insatiable_torment : public SpellScriptLoader
{
public:
	bfa_spell_insatiable_torment() : SpellScriptLoader("bfa_spell_insatiable_torment") { }

	class bfa_spell_insatiable_torment_AuraScript : public AuraScript
	{
		PrepareAuraScript(bfa_spell_insatiable_torment_AuraScript);

		void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			Unit* caster = GetCaster();
			Unit* target = GetTarget();
			if (!caster || !target)
				return;
			target->RemoveAura(SPELL_INSATIABLE_TORMENT_RANGE);
		}

		void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			Unit* caster = GetCaster();
			Unit* target = GetTarget();
			if (!caster || !target)
				return;
			target->CastSpell(target, SPELL_INSATIABLE_TORMENT_RANGE, true);
		}

		void OnPeriodic(AuraEffect const* aurEff)
		{
			Unit* caster = GetCaster();
			Unit* target = GetTarget();
			if (!caster || !target)
				return;

			std::list<Player*> players;
			Map::PlayerList const& playerList = target->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
					if (player->IsAlive() && target->GetDistance(player) <= 5.0f && !player->IsGameMaster())
						players.push_back(player);

			Player* validTarget = NULL;
			if (players.size())
			{
				for (auto initialPlayer : players)
				{
						if (initialPlayer == target)
							continue;
						initialPlayer = validTarget;
				}
			}

			if (validTarget)
			{
				target->CastSpell(validTarget, SPELL_FEED_ON_THE_UNWORTHY_DAMAGE, true);
				target->CastSpell(target, SPELL_FEED_ON_THE_UNWORTHY_HEAL, true);
			}
		}

		void Register()
		{
			OnEffectRemove += AuraEffectRemoveFn(bfa_spell_insatiable_torment_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
			OnEffectApply += AuraEffectApplyFn(bfa_spell_insatiable_torment_AuraScript::OnApply, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
			OnEffectPeriodic += AuraEffectPeriodicFn(bfa_spell_insatiable_torment_AuraScript::OnPeriodic, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_insatiable_torment_AuraScript();
	}
};

void AddSC_bfa_boss_uunat()
{
	new bfa_boss_uunat();

	new bfa_npc_piercing_gaze_trigger();
	new bfa_npc_primordial_mindbender();
	new bfa_npc_swarming_voidspawns();
	new bfa_npc_tempest_caller_relic();
	new bfa_npc_trident_of_deep_ocean_relic();
	new bfa_npc_undying_guardian();
	new bfa_npc_void_stone_relic();
	new bfa_npc_ocean_rune_trigger();

	new bfa_spell_gift_of_nzoth_hysteria();
	new bfa_spell_tempest_caller_relic_remove();
	new bfa_spell_trident_of_deep_ocean_relic_remove();
	new bfa_spell_void_stone_relic_remove();
	new bfa_spell_void_crash_missile();
	new bfa_spell_storm_of_annihilation_effect();
	new bfa_spell_custody_of_deep_absorb();
	new bfa_spell_insatiable_torment();
	new bfa_spell_unstable_resonance_remove_effect();

	new bfa_at_oblivion_terror();
}
