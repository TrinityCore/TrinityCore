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
#include <sstream>

enum Spells
{
	//Relic visual
	SPELL_TRIDENT_OF_DEEP_OCEAN = 282171,
	SPELL_VOID_STONE = 282158,
	SPELL_TEMPEST_CALLER = 282162,

	SPELL_ENVELOPING_DARKNESS = 287876,
	SPELL_PACT_OF_THE_RESTLESS = 282675,

	SPELL_POWER_OVERWHELMING = 282914,

	// Fathuul
	SPELL_SHEAR_MIND = 282384,
	SPELL_VOID_CRASH_BIG = 282395,
	SPELL_VOID_CRASH_MIDDLE = 285412,
	SPELL_VOID_CRASH_SMALL = 285411,

	SPELL_CRUSHING_DOUBT = 282432,
	SPELL_CRUSHING_DOUBT_DAMAGE = 282437,

	// Zaxash
	SPELL_APHOTIC_BLAST = 283524,
	SPELL_APHOTIC_BLAST_HC = 282386,

	SPELL_CEREBRAL_ASSAULT = 282589,
	SPELL_DARK_HERALD = 282561,
	SPELL_PROMISES_OF_POWER = 282562,

	// Relics
	SPELL_EMBRACE_OF_THE_VOID = 282738,
	SPELL_UMBRAL_SHELL = 284722,

	SPELL_CUSTODY_OF_THE_DEEP = 282750,
	SPELL_ABYSSAL_COLLAPSE = 282886,
	SPELL_CUSTODY_OF_THE_DEEP_AT = 286701,

	SPELL_STORM_OF_ANNIHILATION = 282743,
	SPELL_ANNIHILATE = 282842,

	SPELL_ELDRITCH_REVELATION = 282617,
	SPELL_ELDRITCH_REVEATION_SUMMON = 282619,

	SPELL_VISAGE_FROM_BEYOND = 282515,
	SPELL_VISAGE_FROM_BEYOND_ADD = 287817,

	SPELL_WITNESS_THE_END = 282621,
	SPELL_WITNESS_THE_END_HC = 283540,
	SPELL_WITNESS_THE_END_AURA = 291580,

	SPELL_TERRIFYING_ECHO = 282517,
	SPELL_COALESCE_VOID = 282524,

	SPELL_AGENT_OF_DEMISE = 282540,
	SPELL_WRACK = 292880,
	SPELL_INCOMPLETE_FORM = 282630,

	SPELL_OCEANIC_ESSENCE_STUN = 293488,
	SPELL_OCEANIC_ESSENCE_VISUAL = 293475,
	SPELL_OCEANIC_ESSENCE_AT = 293478,
	SPELL_SPAWN_VISUAL = 293489, // !?
	SPELL_OCEANIC_ESSENCE_MISSILE = 293465,

	SPELL_STORM_ESSENCE = 293300,

	SPELL_VOID_ESSENCE_PERIODIC = 293461,
	SPELL_VOID_ESSENCE = 293514,
};

enum Events
{
	EVENT_ENRAGE = 1,

	EVENT_SHEAR_MIND,
	EVENT_VOID_CRASH,
	EVENT_CRUSHING_DOUBT,

	EVENT_CEREBRAL_ASSAULT,
	EVENT_APHOTIC_BLAST,
	EVENT_DARK_HERALD,

	EVENT_SUMMON_ELDRITCH,
	EVENT_SUMMON_VISAGE,

	EVENT_WITNESS_THE_END,
	EVENT_TERRIFYING_ECHO,

	EVENT_KILL,
	EVENT_KILL_2,

	EVENT_VOID_ESSENCE,
	EVENT_OCEANIC_ESSENCE,
	EVENT_STORM_ESSENCE,
	EVENT_CUSTODY_OF_THE_DEEP,
};

enum Action
{
	ACTION_RELIC_ACTIVATED = 1,
};

enum Timers
{
	TIMER_ENRAGE = 9 * MINUTE,

	TIMER_SHEAR_MIND = 5 * IN_MILLISECONDS,
	TIMER_VOID_CRASH = 25 * IN_MILLISECONDS,
	TIMER_CRUSHING_DOUBT = 30 * IN_MILLISECONDS,

	TIMER_DARK_HERALD = 40 * IN_MILLISECONDS,
	TIMER_APHOTIC_BLAST = 5 * IN_MILLISECONDS,
	TIMER_CEREBRAL_ASSAULT = 25 * IN_MILLISECONDS,

	TIMER_VOID_ESSENCE = 40 * IN_MILLISECONDS,
	TIMER_OCEANIC_ESSENCE = 6 * IN_MILLISECONDS,
	TIMER_STORM_ESSENCE = 20 * IN_MILLISECONDS,
};

enum Creatures
{
	BOSS_FATHUUL_THE_FEARED = 144754,
	BOSS_ZAXASJ_THE_SPEAKER = 144755,

	NPC_TRIDENT_OF_DEEP_OCEAN_RELIC = 144809,
	NPC_VOID_STONE_RELIC = 147572,
	NPC_TEMPEST_CALLER_RELIC = 147573,

	NPC_OCEANIC_ESSENCE = 151412,

	NPC_OCEAN_RUNE = 147762,

	NPC_ELDRITCH_ABOMINATION = 145053,
	NPC_VISAGE_FROM_BEYOND = 144996,
};

const Position centerPos = { 3631.75f, -1729.25f, 85.65f }; // 60y

const Position relicPos[3] =
{
	{3629.13f, -1761.63f, 85.65f + 5.0f },
	{3662.89f, -1711.87f, 85.72f + 5.0f },
	{3610.93f, -1700.21f, 85.65f + 5.0f },
};

#define ZAX_AGGRO "Embrace the master's truth!"
#define FATHUUL_SHEAR_MIND "Cower before his might!"
#define ZAX_TEMPEST "You are but rubble in the storm's wake!"
#define FATHUUL_TEMPEST "Quake in fear of his endless strenght!"
#define ZAX_VOID "All will be consumed!"
#define FATHUUL_VOID "Tremble before his hunger! His darkness!"
#define ZAX_OCEAN "Your pathetic existence will be washed away!"
#define FATHUUL_OCEAN "You will drown in your terror!"
#define FATHUUL_PACT "Master! Grantme strenght!"
#define ZAX_PACT "He...will yet...claim you..."

struct checkSpec : public std::unary_function<Unit*, bool>
{
	checkSpec() {}

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


// debuff 10% increase after selecting one relic to find  283141, spell timers might need recheck

class bfa_boss_zaxasj_the_speaker : public CreatureScript
{
public:
	bfa_boss_zaxasj_the_speaker() : CreatureScript("bfa_boss_zaxasj_the_speaker")
	{}

	struct bfa_boss_zaxasj_the_speaker_AI : public BossAI
	{
		bfa_boss_zaxasj_the_speaker_AI(Creature* creature) : BossAI(creature, DATA_RESTLESS_CABAL), summons(me)
		{
			instance = me->GetInstanceScript();
		}

		EventMap events;
		InstanceScript* instance;
		SummonList summons;

		bool firstRelic;
		bool secondRelic;
		bool thirdRelic;
		bool isDead;
		bool tridentActivated;
		bool tempestActivated;
		bool voidstoneActivated;

		Creature* GetOceanRune()
		{
			return me->FindNearestCreature(NPC_OCEAN_RUNE, 500.0f, true);
		}

		void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
		{
			if (!me)
				return;

			if (me)
			{
				switch (selectedTextSound)
				{
				case 1:
					me->Yell(ZAX_AGGRO, LANG_UNIVERSAL, NULL);
					break;
				case 2:
					me->Yell(ZAX_OCEAN, LANG_UNIVERSAL, NULL);
					break;
				case 3:
					me->Yell(ZAX_PACT, LANG_UNIVERSAL, NULL);
					break;
				case 4:
					me->Yell(ZAX_TEMPEST, LANG_UNIVERSAL, NULL);
					break;
				case 5:
					me->Yell(ZAX_VOID, LANG_UNIVERSAL, NULL);
					break;
				}
			}
		}

		void DamageTaken(Unit* at, uint32& damage)
		{
			if (at->HasAura(SPELL_CUSTODY_OF_THE_DEEP))
			{
				int32 damageToRune = damage / 0.75f;
				if (Creature* rune = GetOceanRune())
					me->DealDamage(rune, damageToRune);
			}

			if (me->HealthBelowPct(75) && !firstRelic)
			{
				firstRelic = true;
				SelectRelic();
			}

			if (me->HealthBelowPct(50) && !secondRelic)
			{
				secondRelic = true;
				SelectRelic();
			}

			if (me->HealthBelowPct(25) && !thirdRelic)
			{
				thirdRelic = true;
				SelectRelic();
			}

			if (damage >= me->GetHealth() && !isDead)
			{
				isDead = true;
				damage = 0;
				SelectSoundAndText(me, 3);

				me->CastSpell(me, SPELL_PACT_OF_THE_RESTLESS);
				std::ostringstream str;
				str << "Zaxasj the Speaker begins to cast|cFFF00000|h[Pact of the Restless]|h|r!";
				me->TextEmote(str.str().c_str(), 0, true);
			}
		}

		void OnSpellFinished(SpellInfo const* spellInfo) //override
		{
			switch (spellInfo->Id)
			{
			case SPELL_PACT_OF_THE_RESTLESS:
			{
				isDead = false;
				break;
			case SPELL_VISAGE_FROM_BEYOND:
				me->CastSpell(me, SPELL_VISAGE_FROM_BEYOND_ADD, true);
				break;
			}
			}
		}

		void SelectRelic()
		{
			float safeDist = 100.0f;
			std::list<Creature*> relicList;
			GetCreatureListWithEntryInGrid(relicList, me, NPC_VOID_STONE_RELIC, 200.0f);
			GetCreatureListWithEntryInGrid(relicList, me, NPC_TEMPEST_CALLER_RELIC, 200.0f);
			GetCreatureListWithEntryInGrid(relicList, me, NPC_TRIDENT_OF_DEEP_OCEAN_RELIC, 200.0f);

			Creature* selectedRelic = NULL;

			for (auto relics : relicList)
			{
				for (uint8 i = 1; i < 3; i++)
				{
					if (me->GetDistance(relicPos[i]) < safeDist)
					{
						selectedRelic = relics;
					}
				}
			}

			if (selectedRelic)
			{
				switch (selectedRelic->GetEntry())
				{
				case NPC_VOID_STONE_RELIC:
				{
					if (voidstoneActivated)
						me->CastSpell(me, SPELL_POWER_OVERWHELMING, true);
					SelectSoundAndText(me, 5);

					voidstoneActivated = true;
					selectedRelic->CastSpell(me, SPELL_UMBRAL_SHELL, me);

					std::ostringstream str;
					str << "|cFFF00000|hZaxasj he Speaker|h|r activates the power of the Void Stone!";
					me->TextEmote(str.str().c_str(), 0, true);

					break;
				}
				case NPC_TRIDENT_OF_DEEP_OCEAN_RELIC:
				{
					if (tridentActivated)
						me->CastSpell(me, SPELL_POWER_OVERWHELMING, true);
					tridentActivated = true;
					SelectSoundAndText(me, 2);

					std::ostringstream str;
					str << "|cFFF00000|hZaxasj he Speaker|h|r activates the power of the Trident of Deep Ocean!";
					me->TextEmote(str.str().c_str(), 0, true);

					break;
				}
				case NPC_TEMPEST_CALLER_RELIC:
				{
					if (tempestActivated)
						me->CastSpell(me, SPELL_POWER_OVERWHELMING, true);
					tempestActivated = true;
					SelectSoundAndText(me, 4);

					std::ostringstream str;
				    str << "|cFFF00000|hZaxasj he Speaker|h|r activates the power of the Tempest Caller!";
					me->TextEmote(str.str().c_str(), 0, true);

					break;
				}
				}
			}

			events.ScheduleEvent(EVENT_SUMMON_VISAGE, 3000);
		}

		void CheckFathuulDead()
		{
			if (Creature* fathuul = GetFathuul())
				if(fathuul->HasAura(42716))
					me->Kill(me);
		}


		void HandleFalseBooleans()
		{
			isDead = false;
			thirdRelic = false;
			secondRelic = false;
			firstRelic = false;
			tridentActivated = false;;
			tempestActivated = false;
			voidstoneActivated = false;
		}


		void Reset() override
		{
			HandleFalseBooleans();
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			events.Reset();
		}

		Creature* GetFathuul()
		{
			return me->FindNearestCreature(BOSS_FATHUUL_THE_FEARED, 500.0f, true);
		}

		void EnterEvadeMode(EvadeReason why) 
		{
			_DespawnAtEvade(15);
		}

		void JustSummoned(Creature* summon)
		{
			summons.Summon(summon);

			switch (summon->GetEntry())
			{
			case NPC_VISAGE_FROM_BEYOND:
				summon->SetInCombatWithZone();
				break;
			}
		}
		void JustDied(Unit*)
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			summons.DespawnAll();
		}

		void JustEngagedWith(Unit*)
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
			if (Creature* fathuul = GetFathuul())
				fathuul->SetInCombatWithZone();
			SelectSoundAndText(me, 1);
			events.ScheduleEvent(EVENT_APHOTIC_BLAST, TIMER_APHOTIC_BLAST);
			events.ScheduleEvent(EVENT_CEREBRAL_ASSAULT, TIMER_CEREBRAL_ASSAULT);
			events.ScheduleEvent(EVENT_DARK_HERALD, TIMER_DARK_HERALD);
		}

		void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			if (!UpdateVictim())
				return;

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			if (me->IsInCombat() && isDead)
				CheckFathuulDead();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_APHOTIC_BLAST:
					if (Unit* target = me->GetVictim())
						if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
							me->CastSpell(target, SPELL_APHOTIC_BLAST_HC);
						else
							me->CastSpell(target, SPELL_APHOTIC_BLAST);

					events.ScheduleEvent(EVENT_APHOTIC_BLAST, TIMER_APHOTIC_BLAST);
					break;
				case EVENT_CEREBRAL_ASSAULT:
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
						me->CastSpell(player, SPELL_CEREBRAL_ASSAULT);
					}

					events.ScheduleEvent(EVENT_CEREBRAL_ASSAULT, TIMER_CEREBRAL_ASSAULT);
					break;
				}
				case EVENT_DARK_HERALD:
				{
					std::list<Player*> playerList;
					me->GetPlayerListInGrid(playerList, 100.0f);
					playerList.remove_if(checkSpec());
					if (!playerList.empty())
					{
						playerList.resize(1);
					}

					for (auto player : playerList)
					{
						me->CastSpell(player, SPELL_DARK_HERALD);
					}

					events.ScheduleEvent(EVENT_DARK_HERALD, TIMER_DARK_HERALD);
					break;
				}
				case EVENT_SUMMON_VISAGE:
					me->CastSpell(me, SPELL_VISAGE_FROM_BEYOND);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_boss_zaxasj_the_speaker_AI(creature);
	}
};

class bfa_boss_fathuul_the_feared : public CreatureScript
{
public:
	bfa_boss_fathuul_the_feared() : CreatureScript("bfa_boss_fathuul_the_feared")
	{}

	struct bfa_boss_fathuul_the_feared_AI : public BossAI
	{
		bfa_boss_fathuul_the_feared_AI(Creature* creature) : BossAI(creature, DATA_RESTLESS_CABAL), summons(me)
		{
			instance = me->GetInstanceScript();
		}

		EventMap events;
		InstanceScript* instance;
		SummonList summons;
		bool firstRelic;
		bool secondRelic;
		bool thirdRelic;
		bool isDead;
		bool tridentActivated;
		bool tempestActivated;
		bool voidstoneActivated;
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
					me->Yell(FATHUUL_OCEAN, LANG_UNIVERSAL, NULL);
					break;
				case 2:
					me->Yell(FATHUUL_PACT, LANG_UNIVERSAL, NULL);
					break;
				case 3:
					me->Yell(FATHUUL_SHEAR_MIND, LANG_UNIVERSAL, NULL);
					break;
				case 4:
					me->Yell(FATHUUL_TEMPEST, LANG_UNIVERSAL, NULL);
					break;
				case 5:
					me->Yell(FATHUUL_VOID, LANG_UNIVERSAL, NULL);
					break;
				}
			}
		}

		void SpawnRelics()
		{
			me->SummonCreature(NPC_VOID_STONE_RELIC, relicPos[0], TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TRIDENT_OF_DEEP_OCEAN_RELIC, relicPos[1], TEMPSUMMON_MANUAL_DESPAWN);
			me->SummonCreature(NPC_TEMPEST_CALLER_RELIC, relicPos[2], TEMPSUMMON_MANUAL_DESPAWN);
		}

		Creature* GetOceanRune()
		{
			return me->FindNearestCreature(NPC_OCEAN_RUNE, 500.0f, true);
		}

		void DamageTaken(Unit* at, uint32& damage)
		{
			if (at->HasAura(SPELL_CUSTODY_OF_THE_DEEP))
			{
				int32 damageToRune = damage / 0.75f;
				if (Creature* rune = GetOceanRune())
					me->DealDamage(rune, damageToRune);
			}

			if (me->HealthBelowPct(75) && !firstRelic)
			{
				firstRelic = true;
				SelectRelic();
			}

			if (me->HealthBelowPct(50) && !secondRelic)
			{
				secondRelic = true;
				SelectRelic();
			}

			if (me->HealthBelowPct(25) && !thirdRelic)
			{
				thirdRelic = true;
				SelectRelic();
			}

			if (damage >= me->GetHealth() && !isDead)
			{
				isDead = true;
				damage = 0;
				SelectSoundAndText(me, 2);
				me->AddAura(42716, me); //tempfix

				std::ostringstream str;
				str << "Fa'thuul the Feared begins to cast|cFFF00000|h[Pact of the Restless]|h|r!";
				me->TextEmote(str.str().c_str(), 0, true);
				me->CastSpell(me, SPELL_PACT_OF_THE_RESTLESS);
			}
		}

		void SelectRelic()
		{
			float safeDist = 100.0f;
			std::list<Creature*> relicList;
			GetCreatureListWithEntryInGrid(relicList, me, NPC_VOID_STONE_RELIC, 200.0f);
			GetCreatureListWithEntryInGrid(relicList, me, NPC_TEMPEST_CALLER_RELIC, 200.0f);
			GetCreatureListWithEntryInGrid(relicList, me, NPC_TRIDENT_OF_DEEP_OCEAN_RELIC, 200.0f);

			Creature* selectedRelic = NULL;

			for (auto relics : relicList)
			{
				for (uint8 i = 1; i < 3; i++)
				{
					if (me->GetDistance(relicPos[i]) < safeDist)
					{
						selectedRelic = relics;
					}
				}
			}

			if (selectedRelic)
			{
				switch (selectedRelic->GetEntry())
				{
				case NPC_VOID_STONE_RELIC:
				{
					SelectSoundAndText(me, 5);

					if (voidstoneActivated)
						me->CastSpell(me, SPELL_POWER_OVERWHELMING, true);
					voidstoneActivated = true;
					me->CastSpell(me, SPELL_UMBRAL_SHELL, me);
					selectedRelic->AI()->DoAction(ACTION_RELIC_ACTIVATED);

					std::ostringstream str;
					str << "|cFFF00000|hFa'thuul the Feared|h|r activates the power of the Void Stone!";
					me->TextEmote(str.str().c_str(), 0, true);

					break;
				}
				case NPC_TRIDENT_OF_DEEP_OCEAN_RELIC:
				{
					SelectSoundAndText(me, 1);

					if (tridentActivated)
						me->CastSpell(me, SPELL_POWER_OVERWHELMING, true);
					tridentActivated = true;
					selectedRelic->AI()->DoAction(ACTION_RELIC_ACTIVATED);

					std::ostringstream str;
					str << "|cFFF00000|hFa'thuul the Feared|h|r activates the power of the Trident of Deep Ocean!";
					me->TextEmote(str.str().c_str(), 0, true);

					break;
				}
				case NPC_TEMPEST_CALLER_RELIC:
				{
					SelectSoundAndText(me, 4);

					if (tempestActivated)
						me->CastSpell(me, SPELL_POWER_OVERWHELMING, true);
					tempestActivated = true;
					selectedRelic->AI()->DoAction(ACTION_RELIC_ACTIVATED);

					std::ostringstream str;
					str << "|cFFF00000|hFa'thuul the Feared|h|r activates the power of the Tempest Caller!";
					me->TextEmote(str.str().c_str(), 0, true);

					break;
				}
				}
			}

			events.ScheduleEvent(EVENT_SUMMON_ELDRITCH, 3000);
		}

		void DespawnCreature(uint32 entry)
		{
			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					NowCreature->DespawnOrUnsummon();
		}

		void RemoveFrames(uint32 entry)
		{
			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, NowCreature);
		}

		void OnSpellFinished(SpellInfo const* spellInfo) //override
		{
			switch (spellInfo->Id)
			{
			case SPELL_PACT_OF_THE_RESTLESS:
			{
				isDead = false;
				me->RemoveAura(42716); // temp fix
				break;
			}
			case SPELL_ELDRITCH_REVELATION:
				for (uint8 i = 0; i < 3; ++i)
					me->CastSpell(me, SPELL_ELDRITCH_REVEATION_SUMMON, true);
				break;
			}
		}

		void HandleFalseBooleans()
		{
			isDead = false;
			thirdRelic = false;
			secondRelic = false;
			firstRelic = false;
			tridentActivated = false;
			tempestActivated = false;
			voidstoneActivated = false;
		}

		void Reset() 
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			voidCrashTargets.clear();
			HandleFalseBooleans();
			events.Reset();
			DespawnCreature(NPC_VOID_STONE_RELIC);
			DespawnCreature(NPC_TEMPEST_CALLER_RELIC);
			DespawnCreature(NPC_TRIDENT_OF_DEEP_OCEAN_RELIC);

			RemoveFrames(NPC_OCEAN_RUNE);
			RemoveFrames(NPC_VISAGE_FROM_BEYOND);
			summons.DespawnAll();
		}

		Creature* GetZaxasj()
		{
			return me->FindNearestCreature(BOSS_ZAXASJ_THE_SPEAKER, 500.0f, true);
		}

		void EnterEvadeMode(EvadeReason why) 
		{
			DespawnCreature(NPC_VOID_STONE_RELIC);
			DespawnCreature(NPC_TEMPEST_CALLER_RELIC);
			DespawnCreature(NPC_TRIDENT_OF_DEEP_OCEAN_RELIC);
			_DespawnAtEvade(15);
		}

		void JustDied(Unit*)
		{
			DespawnCreature(NPC_VOID_STONE_RELIC);
			DespawnCreature(NPC_TEMPEST_CALLER_RELIC);
			DespawnCreature(NPC_TRIDENT_OF_DEEP_OCEAN_RELIC);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			summons.DespawnAll();
		}

		void JustSummoned(Creature* summon) 
		{
			summons.Summon(summon);

			switch (summon->GetEntry())
			{
			case NPC_ELDRITCH_ABOMINATION:
				summon->SetInCombatWithZone();
				break;
			}
		}

		void JustEngagedWith(Unit*)
		{
			SpawnRelics();
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
			if (Creature* zax = GetZaxasj())
				zax->SetInCombatWithZone();

			events.ScheduleEvent(EVENT_SHEAR_MIND, TIMER_SHEAR_MIND);
			events.ScheduleEvent(EVENT_VOID_CRASH, TIMER_VOID_CRASH);
			events.ScheduleEvent(EVENT_CRUSHING_DOUBT, TIMER_CRUSHING_DOUBT);
		}

		void CheckZaxDead()
		{
			if (Creature* zax = GetZaxasj())
				if (CAST_AI(bfa_boss_zaxasj_the_speaker::bfa_boss_zaxasj_the_speaker_AI, zax->AI())->isDead == true)
					me->Kill(me);

		}

		void NextVoidCrash(bool middle, bool low, bool clearList)
		{
			if (middle)
			{
				if (!voidCrashTargets.empty())
				{
					for (auto crashTarget : voidCrashTargets)
						me->CastSpell(crashTarget, SPELL_VOID_CRASH_MIDDLE);
				}
			}

			if (low)
			{
				if (!voidCrashTargets.empty())
				{
					for (auto crashTarget : voidCrashTargets)
						me->CastSpell(crashTarget, SPELL_VOID_CRASH_SMALL);
				}
			}

			if (clearList)
				voidCrashTargets.clear();
		}

		void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			if (!UpdateVictim())
				return;

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			if (me->IsInCombat() && isDead)
				CheckZaxDead();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_SHEAR_MIND:
					SelectSoundAndText(me, 3);
					if (Unit* target = me->GetVictim())
						me->CastSpell(target, SPELL_SHEAR_MIND);
					events.ScheduleEvent(EVENT_SHEAR_MIND, TIMER_SHEAR_MIND);
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
				case EVENT_CRUSHING_DOUBT:
				{
					std::list<Player*> playerList;
					me->GetPlayerListInGrid(playerList, 100.0f);
					if (!playerList.empty())
						playerList.resize(2);

					if (!playerList.empty())
					{
						for (auto player : playerList)
							me->CastSpell(player, SPELL_CRUSHING_DOUBT);
					}

					events.ScheduleEvent(EVENT_CRUSHING_DOUBT, TIMER_CRUSHING_DOUBT);
					break;
				}
				case EVENT_SUMMON_ELDRITCH:
					me->CastSpell(me, SPELL_ELDRITCH_REVELATION);
					break;
				}
			}
			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_boss_fathuul_the_feared_AI(creature);
	}
};

// 282395, 285412, 285411
class bfa_spell_void_crash_damage : public SpellScriptLoader
{
public:
	bfa_spell_void_crash_damage() : SpellScriptLoader("bfa_spell_void_crash_damage") { }

	class bfa_spell_void_crash_damage_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_void_crash_damage_SpellScript);

		void OnSpellHit(SpellEffIndex)
		{
			Unit* caster = GetCaster();
			Unit* target = GetHitUnit();

			if (!caster || !target)
				return;

			if (Creature* fathuul = target->FindNearestCreature(BOSS_FATHUUL_THE_FEARED, 500.0f, true))
			{
				switch (GetSpellInfo()->Id)
				{
				case SPELL_VOID_CRASH_BIG:
					CAST_AI(bfa_boss_fathuul_the_feared::bfa_boss_fathuul_the_feared_AI, fathuul->AI())->NextVoidCrash(true, false, false);
					break;
				case SPELL_VOID_CRASH_MIDDLE:
					CAST_AI(bfa_boss_fathuul_the_feared::bfa_boss_fathuul_the_feared_AI, fathuul->AI())->NextVoidCrash(false, true, false);
					break;
				case SPELL_VOID_CRASH_SMALL:
					CAST_AI(bfa_boss_fathuul_the_feared::bfa_boss_fathuul_the_feared_AI, fathuul->AI())->NextVoidCrash(false, false, true);
					break;
				}
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(bfa_spell_void_crash_damage_SpellScript::OnSpellHit, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_void_crash_damage_SpellScript();
	}
};

// 282562
class bfa_spell_promises_of_power : public SpellScriptLoader
{
public:
	bfa_spell_promises_of_power() : SpellScriptLoader("bfa_spell_promises_of_power")
	{}

	class bfa_spell_promises_of_power_AuraScript : public AuraScript
	{
	public:
		PrepareAuraScript(bfa_spell_promises_of_power_AuraScript);

		void HandleEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes mode)
		{
			if (!GetUnitOwner())
				return;

			Unit* owner = GetUnitOwner();
			AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

			if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL)
			{
				if(owner->GetMap()->IsHeroic() || owner->GetMap()->IsMythic())
					owner->CastSpell(owner, SPELL_WRACK, true);
			}
		}
		void Register()
		{
			AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_promises_of_power_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_promises_of_power_AuraScript();
	}
};


// 282432
class bfa_spell_crushing_doubt : public SpellScriptLoader
{
public:
	bfa_spell_crushing_doubt() : SpellScriptLoader("bfa_spell_crushing_doubt") { }

	class bfa_spell_crushing_doubt_AuraScript : public AuraScript
	{
		PrepareAuraScript(bfa_spell_crushing_doubt_AuraScript);

		void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			Unit* caster = GetCaster();
			Unit* target = GetTarget();
			if (!caster || !target)
				return;

			target->CastSpell(target, SPELL_CRUSHING_DOUBT_DAMAGE, true);
		}

		void Register()
		{
			OnEffectRemove += AuraEffectRemoveFn(bfa_spell_crushing_doubt_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_crushing_doubt_AuraScript();
	}
};

// 282386
class bfa_spell_aphotic_blast : public SpellScriptLoader
{
public:
	bfa_spell_aphotic_blast() : SpellScriptLoader("bfa_spell_aphotic_blast") { }

	class bfa_spell_aphotic_blast_AuraScript : public AuraScript
	{
		PrepareAuraScript(bfa_spell_aphotic_blast_AuraScript);

		void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
		{
			Unit* caster = GetCaster();
			Unit* target = GetTarget();
			if (!caster || !target)
				return;

			target->CastSpell(target, SPELL_AGENT_OF_DEMISE, true);
		}

		void Register()
		{
			OnEffectRemove += AuraEffectRemoveFn(bfa_spell_aphotic_blast_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_MOD_THREAT, AURA_EFFECT_HANDLE_REAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_aphotic_blast_AuraScript();
	}
};
// 282437
#define SAFE_DISTANCE 30.0f
class bfa_spell_crushing_doubt_damage : public SpellScriptLoader
{
public:
	bfa_spell_crushing_doubt_damage() : SpellScriptLoader("bfa_spell_crushing_doubt_damage") {}

	class bfa_spell_crushing_doubt_damage_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_crushing_doubt_damage_SpellScript);

		void HandleEffectHitTarget(SpellEffIndex /*eff_idx*/)
		{
			if (Unit* caster = GetCaster())
			{
				if (Unit* target = GetHitUnit())
				{
					float distance = caster->GetExactDist2d(target);
					uint32 mindmg = 0, maxdmg = 0;

					switch (caster->GetMap()->GetDifficultyID())
					{
					case DIFFICULTY_10_N:
					case DIFFICULTY_25_N:
						mindmg = 300000;
						maxdmg = 400000;
						break;
					case DIFFICULTY_10_HC:
					case DIFFICULTY_25_HC:
						mindmg = 400000;
						maxdmg = 500000;
						break;
					}

					if (distance > SAFE_DISTANCE)
						distance = SAFE_DISTANCE;

					SetHitDamage(((mindmg / -SAFE_DISTANCE) * distance) + maxdmg);
				}
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(bfa_spell_crushing_doubt_damage_SpellScript::HandleEffectHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_crushing_doubt_damage_SpellScript();
	}
};



class bfa_npc_eldritch_abomination : public CreatureScript
{
public:
	bfa_npc_eldritch_abomination() : CreatureScript("bfa_npc_eldritch_abomination")
	{}

	struct bfa_npc_eldritch_abomination_AI : public ScriptedAI
	{
		bfa_npc_eldritch_abomination_AI(Creature* creature) : ScriptedAI(creature)
		{
		}

		EventMap events;

		void Reset() 
		{
			events.Reset();
		}

		void JustEngagedWith(Unit*)
		{
			events.ScheduleEvent(EVENT_WITNESS_THE_END, 1000);
			if (me->GetMap()->IsMythic())
				me->CastSpell(me, SPELL_INCOMPLETE_FORM, true);
		}

		void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			if (!UpdateVictim())
				return;

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

            if (me->HasAura(SPELL_INCOMPLETE_FORM) && me->IsInCombat())
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_OBS_MOD_HEALTH,  true);
            else
                me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_OBS_MOD_HEALTH, false);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_WITNESS_THE_END:
					if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
						me->CastSpell(me, SPELL_WITNESS_THE_END_HC);
					else
						me->CastSpell(me, SPELL_WITNESS_THE_END);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_eldritch_abomination_AI(creature);
	}
};

class bfa_npc_visage_from_beyond : public CreatureScript
{
public:
	bfa_npc_visage_from_beyond() : CreatureScript("bfa_npc_visage_from_beyond")
	{}

	struct bfa_npc_visage_from_beyond_AI : public ScriptedAI
	{
		bfa_npc_visage_from_beyond_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->AddUnitState(UNIT_STATE_ROOT);
			instance = me->GetInstanceScript();
		}

		bool canCoalesce;
		EventMap events;
		InstanceScript* instance;

		void Reset() 
		{
			canCoalesce = false;
			events.Reset();
		}

		void DamageTaken(Unit* a, uint32& damage) 
		{
			if (damage >= me->GetHealth() && !canCoalesce)
			{
				canCoalesce = true;
				damage = 0;
				me->CastStop();
				me->CastSpell(me, SPELL_COALESCE_VOID);
			}
		}

		void JustEngagedWith(Unit*)
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

			if(me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
				events.ScheduleEvent(EVENT_KILL, 90 * IN_MILLISECONDS);
			else
				events.ScheduleEvent(EVENT_KILL_2, 60 * IN_MILLISECONDS);
			events.ScheduleEvent(EVENT_TERRIFYING_ECHO, 3000);
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);

			if (me->GetHealth() == me->GetMaxHealth() && canCoalesce)
			{
				canCoalesce = false;
				events.ScheduleEvent(EVENT_TERRIFYING_ECHO, 3000);
				me->RemoveAura(SPELL_COALESCE_VOID);
			}

			if (!UpdateVictim())
				return;

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_TERRIFYING_ECHO:
				{
					std::ostringstream str;
					str << "Visage from Beyond begins to cast |cFFF00000|h[Terrifying Echo]|h|r!";
					me->TextEmote(str.str().c_str(), 0, true);
					me->CastSpell(me, SPELL_TERRIFYING_ECHO);
					break;
				}
				case EVENT_KILL:
				{
					instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
					me->Kill(me);
					break;
				}
				case EVENT_KILL_2:
					instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
					me->Kill(me);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_visage_from_beyond_AI(creature);
	}
};

class bfa_npc_void_stone : public CreatureScript
{
public:
	bfa_npc_void_stone() : CreatureScript("bfa_npc_void_stone")
	{}

	struct bfa_npc_void_stone_AI : public ScriptedAI
	{
		bfa_npc_void_stone_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->AddAura(SPELL_VOID_STONE, me);
			me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
			me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
			me->SetCanFly(true);
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
			case ACTION_RELIC_ACTIVATED:
			{
				if (me->GetMap()->IsMythic())
				{
					me->RemoveAreaTrigger(SPELL_VOID_ESSENCE);
					events.ScheduleEvent(EVENT_VOID_ESSENCE, 2000);
				}

				break;
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

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_VOID_ESSENCE:
					me->CastSpell(me, SPELL_VOID_ESSENCE, true);
					events.ScheduleEvent(EVENT_VOID_ESSENCE, TIMER_VOID_ESSENCE);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_void_stone_AI(creature);
	}
};

// 16382
class bfa_at_void_essence : public AreaTriggerEntityScript
{
public:
	bfa_at_void_essence() : AreaTriggerEntityScript("bfa_at_void_essence") { }

	struct bfa_at_void_essence_AI : AreaTriggerAI
	{
		bfa_at_void_essence_AI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

		void OnUnitEnter(Unit* unit)
		{
			unit->ApplyMovementForce(at->GetGUID(), at->GetPosition(), -5.0f, 0);
		}

		void OnUnitExit(Unit* unit)
		{
			unit->RemoveMovementForce(at->GetGUID());
		}

	};

	AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const 
	{
		return new bfa_at_void_essence_AI(areatrigger);
	}
};

class bfa_npc_tempest_caller : public CreatureScript
{
public:
	bfa_npc_tempest_caller() : CreatureScript("bfa_npc_tempest_caller")
	{}

	struct bfa_npc_tempest_caller_AI : public ScriptedAI
	{
		bfa_npc_tempest_caller_AI(Creature* creature) : ScriptedAI(creature)
		{	
			me->SetCanFly(true);
			me->AddAura(SPELL_TEMPEST_CALLER, me);
			me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
			me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
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
			case ACTION_RELIC_ACTIVATED:
			{
				if (me->GetMap()->IsMythic())
				{
					events.ScheduleEvent(EVENT_STORM_ESSENCE, 20000);
				}
				TempestPlayers();
				break;
			}
			}
		}

		void TempestPlayers()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster()) //gm check
					{
						me->CastSpell(player, SPELL_STORM_OF_ANNIHILATION, true);
					}
				}
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_STORM_ESSENCE:
				{
					float safeDist = 50.0f;
					Player* validtarget = NULL;
					std::list<Player*> playerList;
					me->GetPlayerListInGrid(playerList, 300.0f);
					if (!playerList.empty())
					{
						for (auto player : playerList)
						{
							if (player->GetDistance(me) < safeDist)
								validtarget = player;
						}
					}

					if (validtarget)
						me->CastSpell(validtarget, SPELL_STORM_ESSENCE);

					events.ScheduleEvent(EVENT_STORM_ESSENCE, TIMER_STORM_ESSENCE);
					break;
				}
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_tempest_caller_AI(creature);
	}
};

class bfa_npc_oceanic_essence : public CreatureScript
{
public:
	bfa_npc_oceanic_essence() : CreatureScript("bfa_npc_oceanic_essence")
	{}

	struct bfa_npc_oceanic_essence_AI : public ScriptedAI
	{
		bfa_npc_oceanic_essence_AI(Creature* creature) : ScriptedAI(creature)
		{		
		}

		EventMap events;

		void Reset() 
		{
			me->CastSpell(me, SPELL_OCEANIC_ESSENCE_AT);
			me->CastSpell(me, SPELL_OCEANIC_ESSENCE_VISUAL);
			events.Reset();
		}

		void CheckNearbyPlayers()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster()) //gm check
					{
						if (me->GetDistance(player) <= 3.0f)
						{
							if(!player->HasAura(SPELL_OCEANIC_ESSENCE_STUN))
								me->CastSpell(player, SPELL_OCEANIC_ESSENCE_STUN, true);
						}
					}
				}
		}

		void UpdateAI(uint32 diff) 
		{
			events.Update(diff);
			CheckNearbyPlayers();
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_oceanic_essence_AI(creature);
	}
};

class bfa_npc_trident_of_deep_ocean : public CreatureScript
{
public:
	bfa_npc_trident_of_deep_ocean() : CreatureScript("bfa_npc_trident_of_deep_ocean")
	{}

	struct bfa_npc_trident_of_deep_ocean_AI : public ScriptedAI
	{
		bfa_npc_trident_of_deep_ocean_AI(Creature* creature) : ScriptedAI(creature)
		{	
			me->AddAura(SPELL_TRIDENT_OF_DEEP_OCEAN, me);
			me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
			me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
			me->SetCanFly(true);

			instance = me->GetInstanceScript();
		}

		EventMap events;
		InstanceScript* instance;

		void Reset() 
		{
			events.Reset();
		}

		void DoAction(int32 action)
		{
			switch (action)
			{
			case ACTION_RELIC_ACTIVATED:
			{
				if (me->GetMap()->IsMythic())
				{
					DespawnCreature(NPC_OCEANIC_ESSENCE);
					me->RemoveAreaTrigger(SPELL_OCEANIC_ESSENCE_AT);
					events.ScheduleEvent(EVENT_OCEANIC_ESSENCE, 6000);
				}
				
				events.ScheduleEvent(EVENT_CUSTODY_OF_THE_DEEP, 20 * IN_MILLISECONDS);
				if (Creature* ocean = me->SummonCreature(NPC_OCEAN_RUNE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), TEMPSUMMON_MANUAL_DESPAWN))
				{
					me->CastSpell(ocean, SPELL_CUSTODY_OF_THE_DEEP_AT, true);
					instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, ocean);
				}
				break;
			}
			}
		}

		void DespawnCreature(uint32 entry)
		{
			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					NowCreature->DespawnOrUnsummon();
		}

		void OceanHasBeenKilled()
		{
			if (Creature* ocean = me->FindNearestCreature(NPC_OCEAN_RUNE, 50.0f, true))
			{
				instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, ocean);
				ocean->DespawnOrUnsummon();
				me->RemoveAreaTrigger(SPELL_CUSTODY_OF_THE_DEEP_AT);
			}
		}

		void UpdateAI(uint32 diff)
		{
			events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_OCEANIC_ESSENCE:
				{
					Position spawnPos;
					spawnPos = me->GetRandomNearPosition(30.0f);
					me->CastSpell(spawnPos, SPELL_OCEANIC_ESSENCE_MISSILE, true);
					events.ScheduleEvent(EVENT_OCEANIC_ESSENCE, TIMER_OCEANIC_ESSENCE);
					break;
				}
				case EVENT_CUSTODY_OF_THE_DEEP:
				{
					if (Creature* ocean = me->FindNearestCreature(NPC_OCEAN_RUNE, 200.0f, true))
					{
						me->RemoveAreaTrigger(SPELL_CUSTODY_OF_THE_DEEP_AT);
						me->CastSpell(me, SPELL_ABYSSAL_COLLAPSE, true);
						instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, ocean);
						ocean->DespawnOrUnsummon();
					}

					break;
				}
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_trident_of_deep_ocean_AI(creature);
	}
};

class bfa_npc_ocean_rune : public CreatureScript
{
public:
	bfa_npc_ocean_rune() : CreatureScript("bfa_npc_ocean_rune")
	{}

	struct bfa_npc_ocean_rune_AI : public ScriptedAI
	{
		bfa_npc_ocean_rune_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->AddUnitState(UNIT_STATE_ROOT);
		}

		void JustDied(Unit*) 
		{
			if(Creature* relic = me->FindNearestCreature(NPC_TRIDENT_OF_DEEP_OCEAN_RELIC, 10.0f, true))
				CAST_AI(bfa_npc_trident_of_deep_ocean::bfa_npc_trident_of_deep_ocean_AI, relic->AI())->OceanHasBeenKilled();
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
							me->CastSpell(player, SPELL_CUSTODY_OF_THE_DEEP, true);
						}
						else
							player->RemoveAura(SPELL_CUSTODY_OF_THE_DEEP);
					}
				}
		}

		void UpdateAI(uint32 diff) 
		{
			CheckNearbyPlayers();
		}
	};

	CreatureAI* GetAI(Creature* creature) const 
	{
		return new bfa_npc_ocean_rune_AI(creature);
	}
};

// 282743
class bfa_spell_storm_of_annihilation : public SpellScriptLoader
{
public:
	bfa_spell_storm_of_annihilation() : SpellScriptLoader("bfa_spell_storm_of_annihilation") { }

	class bfa_spell_storm_of_annihilation_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_storm_of_annihilation_SpellScript);

		void DealDamage()
		{
			if (Unit* caster = GetCaster())
			{
				if (Unit* target = GetHitUnit())
				{
					if (target->HealthBelowPct(25))
						caster->CastSpell(target, SPELL_ANNIHILATE, true);
				}
			}
		}

		void Register()
		{
			OnHit += SpellHitFn(bfa_spell_storm_of_annihilation_SpellScript::DealDamage);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_storm_of_annihilation_SpellScript();
	}
};

// 293300
class bfa_spell_storm_essence : public SpellScriptLoader
{
public:
	bfa_spell_storm_essence() : SpellScriptLoader("bfa_spell_storm_essence") { }

	class bfa_spell_storm_essence_SpellScript : public SpellScript
	{
		PrepareSpellScript(bfa_spell_storm_essence_SpellScript);

		void DealDamage()
		{
			if (Unit* caster = GetCaster())
			{
				if (Unit* target = GetHitUnit())
				{
					if (target->HealthBelowPct(25))
						caster->CastSpell(target, SPELL_ANNIHILATE, true);
				}
			}
		}

		void Register()
		{
			OnHit += SpellHitFn(bfa_spell_storm_essence_SpellScript::DealDamage);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_storm_essence_SpellScript();
	}
};

void AddSC_bfa_boss_restless_cabal()
{
	new bfa_boss_fathuul_the_feared();
	new bfa_boss_zaxasj_the_speaker();

	new bfa_npc_eldritch_abomination();
	new bfa_npc_void_stone();
	new bfa_npc_oceanic_essence();
	new bfa_npc_ocean_rune();
	new bfa_npc_tempest_caller();
	new bfa_npc_trident_of_deep_ocean();
	new bfa_npc_visage_from_beyond();

	new bfa_spell_aphotic_blast();
	new bfa_spell_crushing_doubt();
	new bfa_spell_crushing_doubt_damage();
	new bfa_spell_promises_of_power();
	new bfa_spell_void_crash_damage();
	new bfa_spell_storm_essence();
	new bfa_spell_storm_of_annihilation();

	new bfa_at_void_essence();
}
