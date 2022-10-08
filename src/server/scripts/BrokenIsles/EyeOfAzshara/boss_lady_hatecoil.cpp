#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "GameObjectAI.h"
#include "GameObject.h"

enum Spells
{
	SPELL_ARCANE_SHIELDING = 197868,
	SPELL_STATIC_NOVA = 193597,
	SPELL_BECKON_STORM = 193682,
	SPELL_BECKON_STORM_SUMMON = 193683,
	SPELL_FOCUSED_LIGHTNING = 193611,
	SPELL_EXCESS_LIGHTING_PLAYER = 193624,
	SPELL_EXCESS_LIGHTING_SAND = 193625,
	SPELL_CRACKLING_THUNDER = 197326,
	SPELL_CURSE_OF_WITCH_AURA = 193698,
	SPELL_CURSE_OF_WITCH_KNOCK = 193700,
	SPELL_CURSE_OF_WITCH_KILL = 193720,
	SPELL_MONSOON = 196630,

	SPELL_WATERY_SPLASH = 193636,

	SPELL_SAND_DUNE = 193060,
	SPELL_SAND_DUNE_SUMMON = 193061,

	// Monsoon
	SPELL_MONSOON_VISAL = 196609,
	SPELL_MONSOON_DMG = 196610,

	// Hatecoil Arcanist
	SPELL_AQUA_SPOT = 196027,
	SPELL_ARCANE_REBOUND = 196028,
	SPELL_POLYMORPH = 197105,
	SPELL_ARCANE_ALIGNMENT = 197115,
	SPELL_ARCANE_FORTIFICATION = 199865,
};

enum Npcs
{
	BOSS_LADY_HATECOIL = 91789,

	NPC_SALTSEA_GLOBULE = 98293,
	NPC_SAND_DUNE = 97853,
	NPC_MONSOON = 99852,
};

enum Objects
{
	GO_SAND_DUNE = 244690,
};

enum Timers
{
	TIMER_BECKON_STORM = 19 * IN_MILLISECONDS,
	TIMER_BECKON_STORM_AFTER = 40 * IN_MILLISECONDS,
	TIMER_CURSE_OF_WITCH = 16 * IN_MILLISECONDS,
	TIMER_CURSE_OF_WITCH_AFTER = 25 * IN_MILLISECONDS,
	TIMER_STATIC_NOVA = 11 * IN_MILLISECONDS,
	TIMER_CRACKLING_THUNDER_CHECK = 2 * IN_MILLISECONDS,

	TIMER_MONSOON_AFTER = 25 * IN_MILLISECONDS,
	TIMER_MONSOON = 50 * IN_MILLISECONDS,
};

enum Sounds
{
	SOUND_1 = 54194, // aggro
	SOUND_2 = 54201, // static nova
	SOUND_3 = 54204, // beckon storm
	SOUND_4 = 54203, // focused lightning 
	SOUND_5 = 54202, // cuse of witch
	SOUND_6 = 54195, // death
	SOUND_7 = 54199, // kilL
};

#define AGGRO_TEXT "Continue the rituals! I will handle these fools"
#define STATIC_NOVA_TEXT "Just you wait..."
#define BECKON_STORM_TEXT "The waters rise..."
#define FOCUSED_LIGHTNING_TEXT "A storm is gathering..."
#define CURSE_OF_WITCH_TEXT "There is no escape!"
#define DEATH_TEXT "Can you feel the winds? They come for you"
#define KILL_TEXT "The Hatecoil proves superior!"

enum Events
{
	EVENT_STATIC_NOVA = 1,
	EVENT_BECKON_STORM = 2,
	EVENT_FOCUSED_LIGHTING = 3,
	EVENT_CRACKLING_THUNDER = 4,
	EVENT_CURSE_OF_WITCH = 5,
	EVENT_MONSOON = 6,

	// Hatecoil Arcanist
	EVENT_AQUA_SPOT = 7,
	EVENT_ARCANE_REBOUND = 8,
	EVENT_POLYMORPH = 9,
};

const Position ArenaCenter = { -3439.963f, 4589.192f, -0.4387f }; //cheaters check aswell

// dune gob destroyed proper visual

class bfa_boss_lady_hatecoil : public CreatureScript
{
public:
	bfa_boss_lady_hatecoil() : CreatureScript("bfa_boss_lady_hatecoil")
	{}

	struct bfa_boss_lady_hatecoil_AI : public ScriptedAI
	{
		bfa_boss_lady_hatecoil_AI(Creature* creature) : ScriptedAI(creature), summons(me)
		{
			instance = me->GetInstanceScript();
		}

		SummonList summons;
		EventMap events;
		InstanceScript* instance;

		void Reset()
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);

			events.Reset();
			summons.DespawnAll();
			RespawnDunes();
			DespawnCreature(NPC_SALTSEA_GLOBULE);
			DespawnCreature(NPC_MONSOON);
		}

		void EnterEvadeMode(EvadeReason reason) 
		{
			me->NearTeleportTo(me->GetHomePosition());
			Reset();
		}

		void KilledUnit(Unit* target) 
		{
			SelectSoundAndText(me, 6);
		}

		void JustDied(Unit* /**/) 
		{
			DespawnCreature(NPC_SALTSEA_GLOBULE);
			DespawnCreature(NPC_MONSOON);
			SelectSoundAndText(me, 2);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
		}

		bool CheckCheaters()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster()) //gm check
					{
						if (player->GetDistance(ArenaCenter.GetPositionX(), ArenaCenter.GetPositionY(), ArenaCenter.GetPositionZ()) >= 55.0f)
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

		void EnterCombat(Unit*)
		{
			SelectSoundAndText(me, 1);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

			events.ScheduleEvent(EVENT_BECKON_STORM, TIMER_BECKON_STORM);
			events.ScheduleEvent(EVENT_CURSE_OF_WITCH, TIMER_CURSE_OF_WITCH);
			events.ScheduleEvent(EVENT_STATIC_NOVA, TIMER_STATIC_NOVA);
			events.ScheduleEvent(EVENT_CRACKLING_THUNDER, TIMER_CRACKLING_THUNDER_CHECK);

			if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
				events.ScheduleEvent(EVENT_MONSOON, 50 * IN_MILLISECONDS);
		}

		void RespawnDunes()
		{
			std::list<GameObject*> dunesGob;

			me->GetGameObjectListWithEntryInGrid(dunesGob, GO_SAND_DUNE, 500.0f);

			if (!dunesGob.empty())
			{
				for (auto & it : dunesGob)
					it->SetGoState(GO_STATE_READY);
			}

			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, me, NPC_SAND_DUNE, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					NowCreature->Respawn();
		}

		void DespawnCreature(uint32 entry)
		{
			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, me, entry, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					NowCreature->DespawnOrUnsummon();
		}

		void CheckPlayersFar()
		{
			Map::PlayerList const & players = me->GetMap()->GetPlayers();

			if (players.isEmpty())
				return;

			for (auto & it : players)
			{
				if (Player* player = it.GetSource())
				{
					if (player->GetDistance(ArenaCenter.GetPositionX(), ArenaCenter.GetPositionY(), ArenaCenter.GetPositionZ()) >= 50.0f)
						me->CastSpell(player, SPELL_CRACKLING_THUNDER, true);
				}
			}
		}

		void ExcessLightHandler()
		{
			std::list<Player*> players;
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
					if (player->IsAlive())
						players.push_back(player);
			Player* validTarget = NULL;
			uint32 expectedPlayers = 2;
			if (players.size())
			{
				for (auto initialPlayer : players)
				{
					uint32 count = 1; // initial player
					for (auto otherPlayer : players)
					{
						if (initialPlayer == otherPlayer)
							continue;
						if (initialPlayer->GetDistance2d(otherPlayer) <= 5.0f)
							count++;
					}
					if (count >= expectedPlayers)
					{
						validTarget = initialPlayer;
						break;
					}
				}
			}
			if (validTarget)
			{
				me->CastSpell(validTarget, SPELL_EXCESS_LIGHTING_PLAYER);
			}
		}

		void SpellHitTarget(Unit* target, SpellInfo const* spell) override
		{
			if (spell->Id == SPELL_FOCUSED_LIGHTNING)
			{
				ExcessLightHandler();

				std::list<Creature*> creatureList;
				GetCreatureListWithEntryInGrid(creatureList, target, NPC_SAND_DUNE, 6.5f);
				if (!creatureList.empty())
					for (auto NowCreature : creatureList)
					{
						if (GameObject* dune = NowCreature->FindNearestGameObject(GO_SAND_DUNE, 6.5f))
							dune->SetGoState(GO_STATE_ACTIVE);
						me->Kill(NowCreature, false);
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
					me->PlayDirectSound(SOUND_6);
					me->Yell(DEATH_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 3: // static nova
					me->PlayDirectSound(SOUND_2);
					me->Yell(STATIC_NOVA_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 4: // beckon storm
					me->PlayDirectSound(SOUND_3);
					me->Yell(BECKON_STORM_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 5: // curse
					me->PlayDirectSound(SOUND_5);
					me->Yell(CURSE_OF_WITCH_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 6: // Kill
					me->PlayDirectSound(SOUND_7);
					me->Yell(KILL_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 7:
					me->PlayDirectSound(SOUND_4);
					me->Yell(FOCUSED_LIGHTNING_TEXT, LANG_UNIVERSAL, NULL);
					break;
				}
			}
		}
		void CalculateCurseOfWitchTargets()
		{
			uint32 targets = 0; // 0 targets init

			//we get all players
			std::list<Player*> targetList;
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
					if (player->IsAlive() && !player->IsGameMaster())
						targetList.push_back(player);

			// with each cast, randomize from 1 to 5 players at once
			if (!targetList.empty())
			{
				switch (rand() % 5)
				{
				case 0:
					targets = 1;
					break;
				case 1:
					targets = 2;
					break;
				case 2:
					targets = 3;
					break;
				case 3:
					targets = 4;
					break;
				case 4:
					targets = 5;
					break;
				}
				targetList.resize(targets);

				for (auto validTarget : targetList)
					me->CastSpell(validTarget, SPELL_CURSE_OF_WITCH_AURA);
			}
		}

		void UpdateAI(uint32 diff)
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
				case EVENT_MONSOON:
				{
					me->CastSpell(me->GetVictim(), SPELL_MONSOON, true);

					events.ScheduleEvent(EVENT_MONSOON, TIMER_MONSOON_AFTER);
					break;
				}
				case EVENT_CRACKLING_THUNDER:
				{
					CheckPlayersFar();
					events.ScheduleEvent(EVENT_CRACKLING_THUNDER, TIMER_CRACKLING_THUNDER_CHECK);
					break;
				}

				case EVENT_CURSE_OF_WITCH:
				{
					SelectSoundAndText(me, 5);
					CalculateCurseOfWitchTargets();
					events.ScheduleEvent(EVENT_CURSE_OF_WITCH, TIMER_CURSE_OF_WITCH_AFTER);
					break;
				}
				case EVENT_STATIC_NOVA:
				{
					std::ostringstream str;
					str << "Lady Hatecoil starts to invoke a |cFFF00000|h[Static Nova]|h|r. Get out of the water!";
					me->TextEmote(str.str().c_str(), 0, true);
					SelectSoundAndText(me, 3);
					DoCast(me, SPELL_STATIC_NOVA);
					events.ScheduleEvent(EVENT_FOCUSED_LIGHTING, 15 * IN_MILLISECONDS);
					break;
				}
				case EVENT_FOCUSED_LIGHTING:
				{
					SelectSoundAndText(me, 7);
					DoCast(me, SPELL_FOCUSED_LIGHTNING);
					events.ScheduleEvent(EVENT_STATIC_NOVA, 20 * IN_MILLISECONDS);
					break;
				}

				case EVENT_BECKON_STORM:
				{
					SelectSoundAndText(me, 4);
					std::ostringstream str;
					str << "Lady Hatecoil begins to cast |cFFF00000|h[Beckon Storm]|h|r!";
					me->TextEmote(str.str().c_str(), 0, true);

					std::list<Unit*> targets;
					SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);

					if (!targets.empty())
						for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
							me->CastSpell((*itr), SPELL_BECKON_STORM);
					events.ScheduleEvent(EVENT_BECKON_STORM, 45 * IN_MILLISECONDS);
					break;
				}
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_boss_lady_hatecoil_AI(creature);
	}
};

class bfa_go_sand_dune : public GameObjectScript
{
public:
	bfa_go_sand_dune() : GameObjectScript("bfa_go_sand_dune")
	{}

	struct bfa_go_sand_dune_AI : public GameObjectAI
	{
		bfa_go_sand_dune_AI(GameObject* go) : GameObjectAI(go)
		{}

		void Reset()
		{
			go->HasFlag(GO_FLAG_NOT_SELECTABLE);
		}
	};

	GameObjectAI* GetAI(GameObject* go) const override
	{
		return new bfa_go_sand_dune_AI(go);
	}
};

class bfa_npc_saltsea_globule : public CreatureScript
{
public:
	bfa_npc_saltsea_globule() : CreatureScript("bfa_npc_saltsea_globule")
	{}

	struct bfa_npc_saltsea_globule_AI : public ScriptedAI
	{
		bfa_npc_saltsea_globule_AI(Creature* creature) : ScriptedAI(creature)
		{}

		void JustDied(Unit*)
		{
			DoCast(me, SPELL_WATERY_SPLASH, true);
		}

		void UpdateAI(uint32 diff)
		{
			if (!me->IsInCombat())
				me->SetInCombatWithZone();

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_saltsea_globule_AI(creature);
	}
};

enum MonsmoonEvents
{
	EVENT_FIXATE = 1,
	EVENT_CHECK_PLAYER_DISTANCE,
	EVENT_CHECK_DUNE_DISTANCE,
};

class bfa_npc_mosoon : public CreatureScript
{
public:
	bfa_npc_mosoon() : CreatureScript("bfa_npc_mosoon")
	{}

	struct bfa_npc_mosoon_AI : public ScriptedAI
	{
		bfa_npc_mosoon_AI(Creature* creature) : ScriptedAI(creature)
		{

		}

		EventMap events;

		void Reset() override
		{
			events.Reset();
			me->CastSpell(me, SPELL_MONSOON_VISAL, true);
			me->SetWalk(true);
			me->SetWaterWalking(true);
			me->SetSpeed(MOVE_WALK, 0.25f);
			me->SetSpeed(MOVE_RUN, 0.05f);
			HandleEvents();
		}

		void HandleEvents()
		{
			events.ScheduleEvent(EVENT_FIXATE, 1000);
			events.ScheduleEvent(EVENT_CHECK_PLAYER_DISTANCE, 3000);
			events.ScheduleEvent(EVENT_CHECK_DUNE_DISTANCE, 2000);
		}

		void UpdateAI(uint32 diff) override
		{
			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_CHECK_PLAYER_DISTANCE:
				{
					Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
					for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
						if (Player* player = i->GetSource())
						{
							if (!player->IsGameMaster()) //gm check
							{
								if (me->GetDistance(player) <= 3.0f)
								{
									me->CastSpell(player, SPELL_MONSOON_DMG, true);
									me->DespawnOrUnsummon();
								}
							}
						}
					events.ScheduleEvent(EVENT_CHECK_PLAYER_DISTANCE, 1500);
					break;
				}
				case EVENT_CHECK_DUNE_DISTANCE:
				{
					if (GameObject* dune = me->FindNearestGameObject(GO_SAND_DUNE, 6.5f))
					{
						dune->SetGoState(GO_STATE_ACTIVE);
						me->DespawnOrUnsummon();
					}
					events.ScheduleEvent(EVENT_CHECK_DUNE_DISTANCE, 2000);
					break;
				}
				case EVENT_FIXATE:
				{
					me->SetWalk(true);
					me->SetWaterWalking(true);
					me->SetSpeed(MOVE_WALK, 0.25f);
					me->SetSpeed(MOVE_RUN, 0.05f);

					std::list<Player*> targetList;
					Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
					for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
						if (Player* player = i->GetSource())
							if (player->IsAlive() && !player->IsGameMaster())
								targetList.push_back(player);
					if(targetList.size() >= 1)
						targetList.resize(1);

					for (auto validTarget : targetList)
					{
						me->AI()->AttackStart(validTarget);
						me->AddThreat(validTarget, 999999999.9f);
					}

					break;
				}
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_mosoon_AI(creature);
	}
};

class bfa_spell_beckon_storm : public SpellScriptLoader
{
public:
	bfa_spell_beckon_storm() : SpellScriptLoader("bfa_spell_beckon_storm")
	{}

	class bfa_spell_beckon_storm_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_beckon_storm_SpellScript);

		void FilterTargets(std::list<WorldObject*>& targets)
		{
			if (targets.empty())
				return;

			targets.remove_if([](WorldObject*& target)
			{
				if (target && target->ToPlayer())
					return false;

				return true;
			});
		}

		void HandleDummy(SpellEffIndex /**/)
		{
			if (!GetCaster() || !GetHitUnit())
				return;

			GetCaster()->CastSpell(GetHitUnit(), SPELL_BECKON_STORM_SUMMON, true);
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(bfa_spell_beckon_storm_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_beckon_storm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_beckon_storm_SpellScript();
	}
};

class bfa_spell_curse_of_witch : public SpellScriptLoader
{
public:
	bfa_spell_curse_of_witch() : SpellScriptLoader("bfa_spell_curse_of_witch")
	{}

	class bfa_spell_curse_of_witch_AuraScript : public AuraScript
	{
	public:
		PrepareAuraScript(bfa_spell_curse_of_witch_AuraScript);

		void HandleEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
		{
			if (!GetUnitOwner() || !GetCaster())
				return;

			Unit* target = GetUnitOwner();

			target->CastSpell(target, SPELL_CURSE_OF_WITCH_KNOCK, true);
			//target->CastSpell(target, SPELL_CURSE_OF_WITCH_KILL, true);
			KillSaltsea();
			//target->CastSpell(target, SPELL_CURSE_OF_WITCH_ROOT, true);
		}

		void KillSaltsea()
		{
			Unit* caster = GetUnitOwner();

			std::list<Creature*> creatureList;
			GetCreatureListWithEntryInGrid(creatureList, caster, NPC_SALTSEA_GLOBULE, 500.0f);
			if (!creatureList.empty())
				for (auto NowCreature : creatureList)
					if (caster->isInFront(NowCreature, 3.14f / 2.0f)) // m_pi would have gave warning, handled this way,its the same
						NowCreature->Kill(NowCreature, false);
		}

		void Register()
		{
			AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_curse_of_witch_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_curse_of_witch_AuraScript();
	}
};

class bfa_spell_static_nova : public SpellScriptLoader
{
public:
	bfa_spell_static_nova() : SpellScriptLoader("bfa_spell_static_nova")
	{}

	class bfa_spell_static_nova_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_static_nova_SpellScript);

		void FilterTargets(std::list<WorldObject*> & targets)
		{
			targets.remove_if([](WorldObject*& target)
			{
				if (target && target->GetPositionZ() > 0 && target->ToPlayer())
					return true;

				return false;
			});
		}

		void Register()
		{
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_static_nova_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_static_nova_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_static_nova_SpellScript();
	}
};
          

void AddSC_boss_lady_hatecoil()
{
	new bfa_boss_lady_hatecoil();
	new bfa_npc_mosoon();
	new bfa_npc_saltsea_globule();

	new bfa_go_sand_dune();

	new bfa_spell_beckon_storm();
	new bfa_spell_curse_of_witch();
	new bfa_spell_static_nova();
}
