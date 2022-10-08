#include "AreaTriggerAI.h"

enum Spells
{
	// Warlord Parjesh
	SPELL_ENERGIZE = 202143,
	SPELL_CRASHING_WAVE_CAST = 191900,
	SPELL_CRASHING_WAVE_DMG = 191919,
	SPELL_CRASHING_WAVE_CHARGE = 191902,
	SPELL_QUICKSAND = 192053,
	SPELL_QUICKSAND_AT = 192041,
	SPELL_QUICKSAND_5_YARDS = 192040,
	SPELL_QUICKSAND_10_YARDS = 192042,
	SPELL_QUICKSAND_15_YARDS = 192043,
	SPELL_QUICKSAND_20_YARDS = 192046,
	SPELL_QUICKSAND_25_YARDS = 192047,
	SPELL_IMPALING_SPEAR = 191946,
	SPELL_IMPALING_SPEAR_MARK = 192094,
	SPELL_IMPALING_SPEAR_KNOCK = 193183,
	SPELL_IMPALING_SPEAR_DMG = 191977,
	SPELL_IMPALING_SPEAR_ADD = 191975,
	SPELL_THROW_SPEAR = 192131,
	SPELL_CALL_REINFORCEMENTS = 196563,
	SPELL_CALL_REINFORCEMENTS_M = 192072, // Summon The melee add
	SPELL_CALL_REINFORCEMENTS_C = 192073, // Summon the caster add
	SPELL_ENRAGE = 197064,
	SPELL_EMPTY_ENERGY = 202146,

	// HateCoil ShellBreaker
	SPELL_BELLOWING_ROAR = 192135,
	SPELL_MOTIVATED = 197495,

	// HateCoil Crestrider
	SPELL_LIGHTING_STRIKE = 192138,
	SPELL_RESTORATION = 197502,
};

enum Events
{
	// Warlord Parjesh
	EVENT_CALL_REINFORCEMENTS = 1,
	EVENT_THROW_SPEAR = 2,
	EVENT_IMPALING_SPEAR = 3,
	EVENT_CRASHING_WAVE = 4,

	// Hatecoil ShellBreaker
	EVENT_BELLOWING_ROAR = 5,

	// Hatecoil Crestrider
	EVENT_LIGHTING_STRIKE = 6,
	EVENT_RESTORATION = 7,
};

enum Timers
{
	TIMER_CRASHING_WAVE = 30 * IN_MILLISECONDS,
	TIMER_IMPALE = 5 * IN_MILLISECONDS,
	TIMER_CALLING_REINFORCEMENTS = 5 * IN_MILLISECONDS,
	TIMER_CALLING_REINFORCEMENTS_AFTER = 20 * IN_MILLISECONDS,
	TIMER_THROW_SPEAR = 15 * IN_MILLISECONDS,

	TIMER_BELLOWING_ROAR = 10 * IN_MILLISECONDS,
	TIMER_RESTORATION = 15 * IN_MILLISECONDS,
	TIMER_LIGHTING_STRIKE = 3 * IN_MILLISECONDS,
};
enum Creatures
{	
	BOSS_WARLORD_PARJESH = 91784,

	NPC_HATECOIL_SHELLBREAKER = 97264,
	NPC_HATECOIL_CRESTRIDER = 97269,
};

enum Says
{
	SAY_INTRO = 0,
	SAY_AGGRO = 1,
	SAY_REINFORCEMENTS = 2,
	SAY_IMPALING_SPEAR = 3,
	SAY_ENRAGE = 4,
	SAY_KILL = 5,
	SAY_DEATH = 6,
};

enum SoundIds
{
	SOUND_1 = 54181,
	SOUND_2 = 54182,
	SOUND_3 = 0, // will update asap i will find it
	SOUND_4 = 54185,
	SOUND_5 = 54187,
	SOUND_6 = 54184,
}; 

enum AreaTriggers
{
	AREA_CRASHING_WAVE_MOVE = 4863,
	AREA_CRASHING_WAVE_DMG = 4888,
};

#define AGGRO_TEXT "Ah, we meet again, weakling. Now it's just you and me... and my guards!"
#define DEATH_TEXT "You can't stop.... the storm..."
#define INTRO_TEXT "Hmph. Intruders. They will not get far."
#define IMPALE_TEXT "Like fish in a net."
#define REINFORCEMENTS_TEXT "Ha, nowhere to hide!"
#define KILL_TEXT "Useless. All of you!"

//cheaters 70yards
// encounter unit 
// crashing wave at spawn

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

class bfa_boss_warlord_parjesh : public CreatureScript
{
public:
	bfa_boss_warlord_parjesh() : CreatureScript("bfa_boss_warlord_parjesh")
	{}

	struct bfa_boss_warlord_parjesh_AI : public ScriptedAI
	{
		bfa_boss_warlord_parjesh_AI(Creature* creature) : ScriptedAI(creature), summons(me)
		{
			introText = false;
			instance = creature->GetInstanceScript();
		}

		SummonList summons;
		EventMap events;
		bool enrage;
		bool introText;
		InstanceScript* instance;

		bool CheckCheaters()
		{
			if (me->GetDistance(me->GetHomePosition()) > 70.0f)
			{
				Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
					if (Player* player = i->GetSource())
					{
						if (!player->IsGameMaster()) //gm check
						{
							me->Kill(player, false);
							std::ostringstream str;
							str << "CHEATERS!";
							me->TextEmote(str.str().c_str(), 0, true);
							return false;
						}

					}
			}
			return true;
		}

		void Reset()
		{
			me->RemoveAllAreaTriggers();
			me->RemoveAllAuras();
			enrage = false;
			events.Reset();
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			DespawnCreatures(NPC_HATECOIL_CRESTRIDER);
			DespawnCreatures(NPC_HATECOIL_SHELLBREAKER);
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
							SelectSoundAndText(me, 3);
							introText = true;
							return;
						}
			}
		}

		void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
		{
			if (!me)
				return;

			if (me)
			{
				switch (selectedTextSound)
				{
				case 1: // Aggro
					me->PlayDirectSound(SOUND_1);
					me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 2: // Death
					me->PlayDirectSound(SOUND_2);
					me->Yell(DEATH_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 3: // Intro 
					me->PlayDirectSound(SOUND_3);
					me->Yell(INTRO_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 4: // Reinforcements
					me->PlayDirectSound(SOUND_4);
					me->Yell(REINFORCEMENTS_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 5: // Spear
					me->PlayDirectSound(SOUND_5);
					me->Yell(IMPALE_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 6: // Kill
					me->PlayDirectSound(SOUND_6);
					me->Yell(KILL_TEXT, LANG_UNIVERSAL, NULL);
					break;
				default:
					break;
				}
			}
		}

		void DamageTaken(Unit* /**/, uint32 & /**/) 
		{
			if (me->HealthBelowPct(30) && !enrage)
			{
				SelectSoundAndText(me, 2);
				enrage = true;
				std::ostringstream str;
				str << "Warlord Parjesh |cFFF00000|h[Enrages]|h|r!";
				me->TextEmote(str.str().c_str(), 0, true);
				me->CastSpell(me, SPELL_ENRAGE, true);
			}
		}

		void KilledUnit(Unit* unit) override
		{
			SelectSoundAndText(me, 6);
		}

		void JustDied(Unit* /**/) 
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			DespawnCreatures(NPC_HATECOIL_CRESTRIDER);
			DespawnCreatures(NPC_HATECOIL_SHELLBREAKER);
			me->RemoveAllAreaTriggers();
			SelectSoundAndText(me, 2);
		}

		void JustSummoned(Creature* summon)
		{

			summons.Summon(summon);

			if (summon->GetEntry() == NPC_HATECOIL_CRESTRIDER || summon->GetEntry() == NPC_HATECOIL_SHELLBREAKER)
			{
				summon->SetInCombatWithZone();
			}
		}

		void DespawnCreatures(uint32 entry)
		{
			std::list<Creature*> creatures;

			me->GetCreatureListWithEntryInGrid(creatures, entry, 250.0f);

			if (creatures.empty())
				return;

			for (auto & it : creatures)
				if (it)
					it->DespawnOrUnsummon();
		}

		void EnterCombat(Unit*) override
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
			SelectSoundAndText(me, 1);
			events.ScheduleEvent(EVENT_CALL_REINFORCEMENTS, TIMER_CALLING_REINFORCEMENTS);
			events.ScheduleEvent(EVENT_THROW_SPEAR, TIMER_THROW_SPEAR);
			events.ScheduleEvent(EVENT_CRASHING_WAVE, TIMER_CRASHING_WAVE);
		}


		void SpellHit(Unit* caster, SpellInfo const* spell) override
		{
			if (spell->Id == SPELL_CALL_REINFORCEMENTS)
			{
				if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
				{
					me->CastSpell(me, SPELL_CALL_REINFORCEMENTS_M, true);
					me->CastSpell(me, SPELL_CALL_REINFORCEMENTS_C, true);
				}
				else
				{
					if (roll_chance_f(50))
						me->CastSpell(me, SPELL_CALL_REINFORCEMENTS_C, true);
					else
						me->CastSpell(me, SPELL_CALL_REINFORCEMENTS_M, true);
				}
			}
		}

		void UpdateAI(uint32 diff) override
		{
			if (!UpdateVictim())
				return;

			events.Update(diff);

			if (me->HasUnitState(UNIT_STATE_CASTING))
				return;

			if (me->IsInCombat())
				CheckCheaters();

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_IMPALING_SPEAR:
				{
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
					{
						me->CastSpell(target, SPELL_IMPALING_SPEAR_MARK);
						me->CastSpell(target, SPELL_IMPALING_SPEAR);

						std::ostringstream str;
						str << "Warlord Parjesh targets " << (target->GetName()) <<  " with an |cFFF00000|h[Impaling Spear]|h|r! Get behind someone!";
						me->TextEmote(str.str().c_str(), 0, true);
					}
					break;
				}
				case EVENT_CALL_REINFORCEMENTS:
					me->CastSpell(me, SPELL_CALL_REINFORCEMENTS); // spell handle
					events.ScheduleEvent(EVENT_CALL_REINFORCEMENTS, TIMER_CALLING_REINFORCEMENTS_AFTER);
					break;
				case EVENT_THROW_SPEAR:
				{
					std::list<Unit*> targets;
					SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true); // 5 players, random targets, alive > non-tank spec selector Nontankselector selects the current target
					targets.remove_if(checkSpec());

					if (!targets.empty())
						if (targets.size() >= 1)
							targets.resize(1);

					for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
						me->CastSpell((*itr), SPELL_THROW_SPEAR);
					events.ScheduleEvent(EVENT_THROW_SPEAR, TIMER_THROW_SPEAR);
					break;
				}
				case EVENT_CRASHING_WAVE:
					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
						me->CastSpell(target, SPELL_CRASHING_WAVE_CAST, true);
					events.ScheduleEvent(EVENT_CRASHING_WAVE, TIMER_CRASHING_WAVE);
					events.ScheduleEvent(EVENT_IMPALING_SPEAR, TIMER_IMPALE);
					break;
				}
			}

			DoMeleeAttackIfReady();
		}

		void OnSpellFinished(SpellInfo const* spellInfo) override
		{
			switch (spellInfo->Id)
			{
			case SPELL_CRASHING_WAVE_CAST:
				me->CastSpell(me->GetPositionX() + 5.0f, me->GetPositionY(), me->GetPositionZ(), SPELL_QUICKSAND_AT, true);
				me->CastSpell(me->GetPositionX() + 10.0f, me->GetPositionY(), me->GetPositionZ(), SPELL_QUICKSAND_AT, true);
				me->CastSpell(me->GetPositionX() + 15.0f, me->GetPositionY(), me->GetPositionZ(), SPELL_QUICKSAND_AT, true);
				me->CastSpell(me->GetVictim(), SPELL_CRASHING_WAVE_DMG, true);
				break;
			}
		}

	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_boss_warlord_parjesh_AI(creature);
	}
};

class bfa_npc_hatecoil_shellbreaker : public CreatureScript
{
public:
	bfa_npc_hatecoil_shellbreaker() : CreatureScript("bfa_npc_hatecoil_shellbreaker")
	{}

	struct bfa_npc_hatecoil_shellbreaker_AI : public ScriptedAI
	{
		bfa_npc_hatecoil_shellbreaker_AI(Creature* creature) : ScriptedAI(creature)
		{

		}

		EventMap events;

		void Reset()
		{
			events.Reset();
		}

		void EnterCombat(Unit* who)
		{
			events.ScheduleEvent(EVENT_BELLOWING_ROAR, TIMER_BELLOWING_ROAR);
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
				case EVENT_BELLOWING_ROAR:
					me->CastSpell(me->GetVictim(), SPELL_BELLOWING_ROAR);
					events.ScheduleEvent(EVENT_BELLOWING_ROAR, TIMER_BELLOWING_ROAR);
					break;
				}
			}
			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_hatecoil_shellbreaker_AI(creature);
	}
};

class bfa_npc_hatecoil_crestrider : public CreatureScript
{
public:
	bfa_npc_hatecoil_crestrider() : CreatureScript("bfa_npc_hatecoil_crestrider")
	{}

	struct bfa_npc_hatecoil_crestrider_AI : public ScriptedAI
	{
		bfa_npc_hatecoil_crestrider_AI(Creature* creature) : ScriptedAI(creature)
		{

		}

		EventMap events;

		void EnterCombat(Unit* who)
		{
			events.ScheduleEvent(EVENT_LIGHTING_STRIKE, TIMER_LIGHTING_STRIKE);
			events.ScheduleEvent(EVENT_RESTORATION, TIMER_RESTORATION);
		}

		Creature* Warlord()
		{
			return me->FindNearestCreature(BOSS_WARLORD_PARJESH, 300.0f, true);
		}

		Creature* Crestrider()
		{
			return me->FindNearestCreature(NPC_HATECOIL_CRESTRIDER, 300.0f, true);
		}

		void Reset()
		{
			events.Reset();
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
				case EVENT_LIGHTING_STRIKE:
				{
					Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me));

					me->CastSpell(target, SPELL_LIGHTING_STRIKE);
					events.ScheduleEvent(EVENT_LIGHTING_STRIKE, TIMER_LIGHTING_STRIKE);
					break;
				}
				case EVENT_RESTORATION:
				{
					switch (urand(1, 3)) // self, crestrider, boss
					{
					case 1:
						me->CastSpell(me, SPELL_RESTORATION);
						break;
					case 2:
						if (Creature* crestrider = Crestrider())
							me->CastSpell(crestrider, SPELL_RESTORATION);
						break;
					case 3:
						if (Creature* warlord = Warlord())
							me->CastSpell(warlord, SPELL_RESTORATION);
						break;
					}
					events.ScheduleEvent(EVENT_RESTORATION, TIMER_RESTORATION);
					break;
				}
				}
			}
			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_hatecoil_crestrider_AI(creature);
	}
};

class bfa_spell_bellowing_roar : public SpellScriptLoader
{
public:
	bfa_spell_bellowing_roar() : SpellScriptLoader("bfa_spell_bellowing_roar")
	{}

	class bfa_spell_bellowing_roar_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_bellowing_roar_SpellScript);

		void HandleDummy(SpellEffIndex /**/)
		{
			if (!GetCaster())
				return;

			if (Map* map = GetCaster()->GetMap())
			{
				if (map->IsHeroic())
					GetCaster()->CastSpell(GetCaster(), SPELL_MOTIVATED, true);
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(bfa_spell_bellowing_roar_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_bellowing_roar_SpellScript();
	}
};

class bfa_spell_impale_spear : public SpellScriptLoader
{
public:
	bfa_spell_impale_spear() : SpellScriptLoader("bfa_spell_impale_spear")
	{}

	class bfa_spell_impale_spear_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_impale_spear_SpellScript);

		void HandleDummy(SpellEffIndex /**/)
		{
			if (!GetCaster() || !GetHitUnit())
				return;

			Unit* caster = GetCaster();
			Unit* target = GetHitUnit();

			std::list<Creature*> minions;

			target->GetCreatureListWithEntryInGrid(minions, NPC_HATECOIL_CRESTRIDER, 100);
			target->GetCreatureListWithEntryInGrid(minions, NPC_HATECOIL_SHELLBREAKER, 100);

			if (!minions.empty())
			{
				for (auto & it : minions)
				{
					if (it && it->IsInBetween(GetCaster(), target, 5.0f))
					{
						target = it;
						break;
					}
				}
			}

			if (target->ToPlayer())
				caster->CastSpell(target, SPELL_IMPALING_SPEAR_DMG, true);
			else if (target->ToCreature())
			{
				if (Creature* parjesh = caster->ToCreature())
					parjesh->AI()->Talk(SAY_IMPALING_SPEAR);

				caster->CastSpell(target, SPELL_IMPALING_SPEAR_ADD, true);
			}
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(bfa_spell_impale_spear_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_impale_spear_SpellScript();
	}

};

// 4887
class bfa_at_quicksand : public AreaTriggerEntityScript
{
public:
	bfa_at_quicksand() : AreaTriggerEntityScript("bfa_at_quicksand")
	{

	}

	struct bfa_at_quicksand_AI : public AreaTriggerAI
	{
		bfa_at_quicksand_AI(AreaTrigger* at) : AreaTriggerAI(at)
		{}

		void OnUnitEnter(Unit* unit) override
		{
			if (!unit)
				return;

			if (unit->GetTypeId() == TYPEID_PLAYER)
				unit->CastSpell(unit, SPELL_QUICKSAND, true);
		}

		void OnUnitExit(Unit* unit) override
		{
			if (!unit)
				return;

			if (unit && unit->GetTypeId() == TYPEID_PLAYER)
				unit->RemoveAurasDueToSpell(SPELL_QUICKSAND);
	}
	};

	AreaTriggerAI* GetAI(AreaTrigger* at) const override
	{
		return new bfa_at_quicksand_AI(at);
	}
};



void AddSC_boss_warlord_parjesh()
{
	new bfa_boss_warlord_parjesh();
	new bfa_npc_hatecoil_shellbreaker();
	new bfa_npc_hatecoil_crestrider();

	new bfa_spell_bellowing_roar();
	new bfa_spell_impale_spear();

	new bfa_at_quicksand();
}
