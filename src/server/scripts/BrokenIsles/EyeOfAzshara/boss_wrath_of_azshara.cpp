#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "MoveSplineInit.h"
#include <G3D/Vector3.h>
#include "ScriptMgr.h"
#include "Vehicle.h"

enum Spells
{
	// Wrath of Azshara
	SPELL_ARCANE_BOMB = 192706,
	SPELL_ARCANE_BOMB_DMG = 192708,
	SPELL_ARCANE_BOMB_VISUAL = 192711,
	SPELL_SURGING_WATERS = 192633,
	SPELL_MASSIVE_DELUGE = 192617,
	SPELL_MASSIVE_DELUGE_DMG = 192619,

	SPELL_MYSTIC_TORNADO = 192680,
	SPELL_MYSTIC_TORNADO_SUMMON = 192681,

	SPELL_CRUSHING_DEPTHS = 197365,
	SPELL_CRY_OF_WRATH = 192985,
	SPELL_RAGING_STORMS = 192696,
	SPELL_HEAVING_SANDS = 197165,

	SPELL_TIDAL_WAVE_AURA = 192940,
	SPELL_TIDAL_WAVE_DUMMY = 192793,
	SPELL_LIGHTING_STRIKES_AURA = 192737,
	SPELL_LIGHTING_STRIKES_TARGET = 192966,
	SPELL_LIGHTING_STRIKES_DMG = 192796,

	SPELL_TIDAL_WAVE_AURA_CRY = 197219,
	SPELL_TIDAL_WAVE_CRY_DUMMY = 192797,

	SPELL_LIGHTING_STRIKES_AURA_CRY = 192989,
	SPELL_RIDE_VEHICLE = 46598,

	SPELL_VIOLET_WINDS_AURA = 191805,
	SPELL_VIOLET_WINDS_AURA_CRY = 192649,
	SPELL_VIOLET_WINDS_DEBUFF = 191797,
	SPELL_VIOLET_WINDS_AREA = 191794,

	// Crushing Wave
	SPELL_FROST_RESONANCE = 196666,

	// Mystic Tornado   
	SPELL_MYSTIC_TORNADO_VISUAL = 192673,
	SPELL_MYSTIC_TORNADO_DMG = 192675,
	SPELL_MAGIC_RESONANCE = 196665,

	// Tidal Wave
	SPELL_TIDAL_WAVE_TARGET = 192792,
	SPELL_TIDAL_WAVE_DMG = 192801,
	SPELL_TIDAL_WAVE_VISUAL = 192753,

	// Ritualist Spells
	SPELL_MAGIC_BINDING = 196515,
	SPELL_POLYMORPH_FISH = 197105,
	SPELL_AQUA_SPOT = 196027,
	SPELL_STORM = 196870,
	SPELL_LIGHTING_BLAST = 196516,
	SPELL_STORM_CONDUIT = 193196,
};

enum Events
{
	EVENT_ARCANE_BOMB = 1,
	EVENT_CRUSHING_DEPTHS = 2,
	EVENT_MASSIVE_DELUGE = 3,
	EVENT_MYSTIC_TORNADO = 4,
	EVENT_RAGING_STORMS = 5,

	// Mystic Tornado
	EVENT_CHECK_DISTANCE = 6,
	EVENT_FIND_POSITION = 7,
	EVENT_BORN = 8,

	// Tidal Wave
	EVENT_TIDAL_WAVE = 9,
};

enum Adds
{
	BOSS_WRATH_OF_AZSHARA = 96028,

	NPC_ARCANE_BOMB = 97691,
	NPC_MYSTIC_TORNADO = 97673,
	NPC_TIDAL_WAVE = 97739,
};

enum Timers
{
	TIMER_MYSTIC_TORNADO = 26 * IN_MILLISECONDS,
	TIMER_MYSTIC_TORNADO_WRATH = 15 * IN_MILLISECONDS,

	TIMER_MASSIVE_DELUGE = 27 * IN_MILLISECONDS,

	TIMER_TIDAL_WAVE_WRATH = 8 * IN_MILLISECONDS,
	TIMER_TIDAL_WAVE = 15 * IN_MILLISECONDS,

	TIMER_CRUSHING_DEPTHS = 43 * IN_MILLISECONDS,

	TIMER_ARCANE_BOMB = 24 * IN_MILLISECONDS,
	
	TIMER_RAGING_STORM_CHECK = 5 *IN_MILLISECONDS,
};

enum Sounds
{
	SOUND_1 = 54212, // intro
	SOUND_2 = 54207, // aggro
	SOUND_3 = 54209, // kill
	SOUND_4 = 54206, //death
	SOUND_5 = 54213, //massive deluge
	SOUND_6 = 54214, // crushing depths
	SOUND_7 = 54215, //arcane bomb
	SOUND_8 = 54208, //cry of wrath
};

#define INTRO_TEXT "THE STORM AWAKENS."
#define AGGRO_TEXT "THE TIDES RISE!"
#define KILL_TEXT "WASHED AWAY!"
#define DEATH_TEXT "WATER... ETERNAL..."
#define MASSIVE_DELUGE_TEXT "CRUSH!"
#define CRUSHING_DEPTHS_TEXT "DROWN!"
#define ARCANE_BOMB_TEXT "SEEK... MAGIC..." 
#define CRY_OF_WRATH_TEXT "TEMPEST!"

const Position SurgingWatersCheck = { -3487.26f, 4385.58f, -3.60f }; // also cheaters check

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

// arcane bomb visuals

class bfa_boss_wrath_of_azshara : public CreatureScript
{
public:
	bfa_boss_wrath_of_azshara() : CreatureScript("bfa_boss_wrath_of_azshara")
	{}

	struct bfa_boss_wrath_of_azshara_AI : public ScriptedAI
	{
		bfa_boss_wrath_of_azshara_AI(Creature* creature) : ScriptedAI(creature), summons(me)
		{
			introText = false;
			instance = me->GetInstanceScript();
		}

		EventMap events;
		SummonList summons;
		bool wrath;
		InstanceScript* instance;
		bool introText;

		bool CheckSurgingWaters()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
					if (!player->IsGameMaster()) //gm check
						if (player->GetDistance(SurgingWatersCheck.GetPositionX(), SurgingWatersCheck.GetPositionY(), SurgingWatersCheck.GetPositionZ()) < 15.0f)
						{
							me->CastSpell(player, SPELL_SURGING_WATERS, true);
							return false;
						}

			return true;
		}

		bool CheckCheaters()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster()) //gm check
					{
						if (player->GetDistance(SurgingWatersCheck.GetPositionX(), SurgingWatersCheck.GetPositionY(), SurgingWatersCheck.GetPositionZ()) >= 75.0f)
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

		void MoveInLineOfSight(Unit* who)
		{
			if (!introText)
			{
				Map::PlayerList const& lPlayers = me->GetMap()->GetPlayers();
				for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
					if (Player* pPlayer = itr->GetSource())
						if (pPlayer->IsAlive() && pPlayer->IsWithinDist(me, 50.f))
						{
							SelectSoundAndText(me, 1);
							introText = true;
							return;
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

		void SelectSoundAndText(Creature* me, uint32  selectedTextSound = 0)
		{
			if (!me)
				return;

			if (me)
			{
				switch (selectedTextSound)
				{
				case 1:
					me->PlayDirectSound(SOUND_1);
					me->Yell(INTRO_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 2:
					me->PlayDirectSound(SOUND_2);
					me->Yell(AGGRO_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 3:
					me->PlayDirectSound(SOUND_3);
					me->Yell(KILL_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 4:
					me->PlayDirectSound(SOUND_4);
					me->Yell(DEATH_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 5:
					me->PlayDirectSound(SOUND_5);
					me->Yell(MASSIVE_DELUGE_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 6:
					me->PlayDirectSound(SOUND_6);
					me->Yell(CRUSHING_DEPTHS_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 7:
					me->PlayDirectSound(SOUND_7);
					me->Yell(ARCANE_BOMB_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 8:
					me->PlayDirectSound(SOUND_8);
					me->Yell(CRY_OF_WRATH_TEXT, LANG_UNIVERSAL, NULL);
					break;
				}
			}
		}

		void Reset() override
		{
			me->SetHealth(me->GetMaxHealth() * 0.2);

			DespawnCreature(NPC_MYSTIC_TORNADO);
			DespawnCreature(NPC_ARCANE_BOMB);
			me->RemoveAllAreaTriggers();
			wrath = false;
			me->SetObjectScale(0.6f);
			summons.DespawnAll();
			me->setRegeneratingHealth(false);
			me->AddUnitState(UNIT_STATE_ROOT);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
		}

		void DamageTaken(Unit* attacker, uint32 & damage) override
		{
			if (me->HealthBelowPct(10) && !wrath)
			{
				SelectSoundAndText(me, 8);
				me->CastSpell(me, SPELL_CRY_OF_WRATH);
				wrath = true;
			}

			if (attacker)
			{
				if (me->IsWithinMeleeRange(attacker) && me->HasAura(SPELL_RAGING_STORMS))
					me->CastStop();
			}
		}


		void EnterEvadeMode(EvadeReason reason) override
		{
			Reset();
		}

		void EnterCombat(Unit* /**/) override
		{
			SelectSoundAndText(me, 2);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

			events.ScheduleEvent(EVENT_ARCANE_BOMB, TIMER_ARCANE_BOMB);
			events.ScheduleEvent(EVENT_MYSTIC_TORNADO, TIMER_MYSTIC_TORNADO);
			events.ScheduleEvent(EVENT_MASSIVE_DELUGE, TIMER_MASSIVE_DELUGE);
			events.ScheduleEvent(EVENT_TIDAL_WAVE, TIMER_TIDAL_WAVE);
			events.ScheduleEvent(EVENT_RAGING_STORMS, TIMER_RAGING_STORM_CHECK);

			if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
				events.ScheduleEvent(EVENT_CRUSHING_DEPTHS, TIMER_CRUSHING_DEPTHS);
		}

		void KilledUnit(Unit* unit) override
		{
			SelectSoundAndText(me, 3);
		}

		void JustDied(Unit*) override
		{
			me->RemoveAllAreaTriggers();
			SelectSoundAndText(me, 4);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
		}

		void DamageDealt(Unit* victim, uint32& /*damage*/, DamageEffectType damageType) override
		{
			if (victim)
			{
				if (victim == me->GetVictim() && damageType == DIRECT_DAMAGE)
					me->CastSpell(me, SPELL_HEAVING_SANDS, true);
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
			{
				CheckSurgingWaters();
				CheckCheaters();
			}

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_RAGING_STORMS:
					if (!me->IsWithinMeleeRange(me->GetVictim()))
						me->CastSpell(me, SPELL_RAGING_STORMS);
					events.ScheduleEvent(EVENT_RAGING_STORMS, TIMER_RAGING_STORM_CHECK);
					break;
				case EVENT_ARCANE_BOMB:
				{
					std::list<Unit*> targets;
					SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
					targets.remove_if(checkSpec()); //no tanks

					if (!targets.empty())
						if (targets.size() >= 1)
							targets.resize(1);

					for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
						me->CastSpell((*itr), SPELL_ARCANE_BOMB);
					
					events.ScheduleEvent(EVENT_ARCANE_BOMB, TIMER_ARCANE_BOMB);
					break;
				}
				case EVENT_CRUSHING_DEPTHS:
				{
					std::list<Unit*> targets;
					SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
					targets.remove_if(checkSpec()); //no tanks

					if (!targets.empty())
						if (targets.size() >= 1)
							targets.resize(1);

					for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
						me->CastSpell((*itr), SPELL_CRUSHING_DEPTHS);
					events.ScheduleEvent(EVENT_CRUSHING_DEPTHS, TIMER_CRUSHING_DEPTHS);
					break;
				}
				case EVENT_MASSIVE_DELUGE:
					me->CastSpell(me->GetVictim(), SPELL_MASSIVE_DELUGE);
					events.ScheduleEvent(EVENT_MASSIVE_DELUGE, TIMER_MASSIVE_DELUGE);
					break;
				case EVENT_MYSTIC_TORNADO:
				{
					std::list<Unit*> targets;
					SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
					targets.remove_if(checkSpec()); //no tanks

					if (!targets.empty())
						if (targets.size() >= 1)
							targets.resize(1);

					for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
						me->CastSpell((*itr), SPELL_MYSTIC_TORNADO_SUMMON, true);
					events.ScheduleEvent(EVENT_MYSTIC_TORNADO, wrath ? TIMER_MYSTIC_TORNADO_WRATH : TIMER_MYSTIC_TORNADO);
					break;
				}
				case EVENT_TIDAL_WAVE:
					me->CastSpell(me, SPELL_TIDAL_WAVE_VISUAL, true);
					events.ScheduleEvent(EVENT_TIDAL_WAVE, wrath ? TIMER_TIDAL_WAVE_WRATH : TIMER_TIDAL_WAVE);
					break;
				}	
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_boss_wrath_of_azshara_AI(creature);
	}
};

class bfa_npc_mystic_tornado : public CreatureScript
{
public:
	bfa_npc_mystic_tornado() : CreatureScript("bfa_npc_mystic_tornado")
	{}

	struct bfa_npc_mystic_tornado_AI : public ScriptedAI
	{
		bfa_npc_mystic_tornado_AI(Creature* creature) : ScriptedAI(creature)
		{
		}

		EventMap events;

		void Reset()
		{
			me->SetSpeed(MOVE_RUN, 1.2f);

			events.Reset();

			me->setActive(true);

			events.ScheduleEvent(EVENT_BORN, 2 * IN_MILLISECONDS);
		}

		void SpellHitTarget(Unit* target, SpellInfo const* spell) override
		{
			if (!target)
				return;

			if(target->GetMap()->IsHeroic() || target->GetMap()->IsMythic())
				if (spell->Id == SPELL_MYSTIC_TORNADO_DMG)
					me->CastSpell(target, SPELL_MAGIC_RESONANCE, true);
		}

		void CheckDist()
		{
			Map::PlayerList const & players = me->GetMap()->GetPlayers();

			if (!players.isEmpty())
			{
				for (auto & it : players)
				{
					if (Player* player = it.GetSource())
					{
						if (me->GetDistance2d(player) <= 3.0f)
							me->CastSpell(player, SPELL_MYSTIC_TORNADO_DMG, true);
					}
				}
			}
		}

		void UpdateAI(uint32 diff) override
		{
			events.Update(diff);

			while (uint32 eventId = events.ExecuteEvent())
			{
				switch (eventId)
				{
				case EVENT_CHECK_DISTANCE:
					CheckDist();
					events.ScheduleEvent(EVENT_CHECK_DISTANCE, 500);
					break;
				case EVENT_BORN:
					me->CastSpell(me, SPELL_MYSTIC_TORNADO_VISUAL, true);
					me->GetMotionMaster()->MoveRandom(25.0f);
					events.ScheduleEvent(EVENT_CHECK_DISTANCE, 500);
					break;
				}
			}
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_mystic_tornado_AI(creature);
	}
};

class bfa_npc_arcane_bomb : public CreatureScript
{
public:
	bfa_npc_arcane_bomb() : CreatureScript("bfa_npc_arcane_bomb")
	{}

	struct bfa_npc_arcane_bomb_AI : public ScriptedAI
	{
		bfa_npc_arcane_bomb_AI(Creature* creature) : ScriptedAI(creature)
		{}

		void Reset() override
		{
			_timerCast = 0;
			_casted = false;
		}

		void IsSummonedBy(Unit* summoner) override
		{
			if (!summoner)
				return;

			_summoner = summoner;

			for (auto & it : me->GetMap()->GetPlayers())
			{
				if (Player* player = it.GetSource())
				{
					if (player->HasAura(SPELL_ARCANE_BOMB))
					{
						me->NearTeleportTo(player->GetPosition());
						DoCast(player, SPELL_RIDE_VEHICLE, true);
						DoCast(player, SPELL_ARCANE_BOMB_VISUAL, true);
						_events.ScheduleEvent(EVENT_ARCANE_BOMB, 100);
						break;
					}
				}
			}
		}

		void UpdateAI(uint32 diff) override
		{
			_events.Update(diff);

			while (uint32 eventId = _events.ExecuteEvent())
			{
				if (eventId == EVENT_ARCANE_BOMB)
				{
					DoCast(me, SPELL_ARCANE_BOMB_DMG, false);
				}
			}
		}

	private:
		EventMap _events;
		Unit* _summoner;
		bool _casted;
		uint32 _timerCast;


	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_arcane_bomb_AI(creature);
	}
};

class bfa_spell_arcane_bomb : public SpellScriptLoader
{
public:
	bfa_spell_arcane_bomb() : SpellScriptLoader("bfa_spell_arcane_bomb")
	{}

	class bfa_spell_arcane_bomb_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_arcane_bomb_SpellScript);

		void HandleSummon()
		{
			if (!GetCaster() || !GetHitUnit())
				return;

			Position summon_pos = GetHitUnit()->GetPosition();

			GetCaster()->SummonCreature(NPC_ARCANE_BOMB, summon_pos, TEMPSUMMON_TIMED_DESPAWN, 20 * IN_MILLISECONDS);
		}

		void Register()
		{
			AfterHit += SpellHitFn(bfa_spell_arcane_bomb_SpellScript::HandleSummon);
		}
	};

	class bfa_spell_arcane_bomb_AuraScript : public AuraScript
	{
	public:
		PrepareAuraScript(bfa_spell_arcane_bomb_AuraScript);

		void HandleDispel(DispelInfo* dispelInfo)
		{
			if (!GetCaster() || !GetUnitOwner())
				return;

			Unit* owner = GetUnitOwner();

			owner->RemoveAurasDueToSpell(SPELL_RIDE_VEHICLE);

			if (Vehicle* vehicle = owner->GetVehicle())
				vehicle->RemoveAllPassengers();

			if (Creature* bomb = owner->FindNearestCreature(NPC_ARCANE_BOMB, 50.0f, true))
				bomb->AddUnitState(UNIT_STATE_ROOT);
		}

		void Register()
		{
			OnDispel += AuraDispelFn(bfa_spell_arcane_bomb_AuraScript::HandleDispel);
		}
	};

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_arcane_bomb_AuraScript();
	}

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_arcane_bomb_SpellScript();
	}
};


class bfa_spell_crushing_depths : public SpellScriptLoader
{
public:
	bfa_spell_crushing_depths() : SpellScriptLoader("bfa_spell_crushing_depths")
	{}

	class bfa_spell_crushing_depths_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_crushing_depths_SpellScript);

		bool Load() override
		{
			_targetsSize = 1;
			return true;
		}

		void FilterTargets(std::list<WorldObject*> & targets)
		{
			if (targets.empty())
				return;
			if (!targets.empty())
				_targetsSize = targets.size();
		}

		void HandleDamage(SpellEffIndex)
		{
			if (!GetCaster())
				return;

			SetHitDamage(GetHitDamage() / _targetsSize);
		}

		void Register()
		{
			OnEffectLaunchTarget += SpellEffectFn(bfa_spell_crushing_depths_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_DAMAGE_FROM_MAX_HEALTH_PCT);
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_crushing_depths_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
		}

	private:
		uint32 _targetsSize;
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_crushing_depths_SpellScript();
	}
};


class bfa_spell_cry_of_wrath : public SpellScriptLoader
{
public:
	bfa_spell_cry_of_wrath() : SpellScriptLoader("bfa_spell_cry_of_wrath")
	{}

	class bfa_spell_cry_of_wrath_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_cry_of_wrath_SpellScript);

		void HandleDummy(SpellEffIndex)
		{
			if (!GetCaster())
				return;

			GetCaster()->CastSpell(GetCaster(), SPELL_TIDAL_WAVE_AURA_CRY, true);
			GetCaster()->CastSpell(GetCaster(), SPELL_LIGHTING_STRIKES_AURA_CRY, true);
			GetCaster()->CastSpell(GetCaster(), SPELL_VIOLET_WINDS_AURA_CRY, true);
		}

		void Register()
		{
			OnEffectHitTarget += SpellEffectFn(bfa_spell_cry_of_wrath_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_cry_of_wrath_SpellScript();
	}
};

// 4950
class bfa_at_tidal_wave : public AreaTriggerEntityScript
{
public:
	bfa_at_tidal_wave() : AreaTriggerEntityScript("bfa_at_tidal_wave")
	{}

	struct bfa_at_tidal_wave_AI : public AreaTriggerAI
	{
		bfa_at_tidal_wave_AI(AreaTrigger* at) : AreaTriggerAI(at)
		{}

		void FillCirclePath(Position const& center, float radius, float z, Movement::PointsArray& path, bool clockwise)
		{
			float step = clockwise ? -M_PI / 8.0f : M_PI / 8.0f;
			float angle = center.GetAngle(at->GetPositionX(), at->GetPositionY());

			for (uint8 iter = 0; iter < 16; angle += step, ++iter)
			{
				G3D::Vector3 point;
				point.x = center.GetPositionX() + radius * cosf(angle);
				point.y = center.GetPositionY() + radius * sinf(angle);
				point.z = z;
				path.push_back(point);
			}
		}

		void OnInitialize() override
		{
			Position center = at->GetPosition();

			std::vector<G3D::Vector3> points;
			FillCirclePath(center, urand(30,50), at->GetPositionZ(), points, false);
			at->InitSplines(points, 60000);
		}

		void OnUnitEnter(Unit* target) override
		{
			if (target->ToPlayer())
			{
				at->GetCaster()->CastSpell(target, SPELL_TIDAL_WAVE_DMG, true);
				if (target->GetMap()->IsHeroic() || target->GetMap()->IsMythic())
					target->CastSpell(target, SPELL_FROST_RESONANCE, true);
			}
		} 

	};

	AreaTriggerAI* GetAI(AreaTrigger* at) const override
	{
		return new bfa_at_tidal_wave_AI(at);
	}
};

void AddSC_boss_wrath_of_azshara()
{
	new bfa_boss_wrath_of_azshara();

	new bfa_npc_mystic_tornado();
	new bfa_npc_arcane_bomb();

	new bfa_spell_crushing_depths();
	new bfa_spell_arcane_bomb();
	new bfa_spell_cry_of_wrath();

	new bfa_at_tidal_wave();
}
