#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"

enum Spells
{
	SPELL_CALL_OF_SEAS = 193051,
	SPELL_CALL_OF_SEAS_AURA = 193054,
	SPELL_CALL_OF_SEAS_DMG = 193055,
	SPELL_QUAKE = 193152,
	SPELL_QUAKE_DMG = 193159,
	SPELL_AFTERSHOCK = 193167,
	SPELL_GASEOUS_BUBBLE = 193018,
	SPELL_GASEOUS_EXPLOSION = 193047,
	SPELL_GROUND_SLAM = 193093,
	SPELL_GROUND_SLAM_DMG = 193056,
	SPELL_FRENZY = 197550,
};

enum Events
{
	EVENT_CALL_OF_SEAS = 1,
	EVENT_QUAKE = 2,
	EVENT_GASEOUS_BUBBLES = 3,
	EVENT_GROUND_SLAM = 4,
	EVENT_ADD_ENERGY,
};

enum Timers
{
	TIMER_CALL_OF_SEAS = 30 * IN_MILLISECONDS,
	TIMER_QUAKE = 28 * IN_MILLISECONDS,
	TIMER_GROUND_SLAM_AFTER = 27 * IN_MILLISECONDS,
	TIMER_ADD_ENERGY = 1 * IN_MILLISECONDS,
	TIMER_GASEOUS_BUBBLE_AFTER = 28* IN_MILLISECONDS,
	TIMER_GROUND_SLAM = 7 * IN_MILLISECONDS,
	TIMER_GASEOUS_BUBBLE = 10 * IN_MILLISECONDS,
};
enum Adds
{
	BOSS_KING_DEEPBEARD = 91797,

	NPC_QUAKE = 97916,
	NPC_CALL_OF_THE_SEA = 97844,
};

const Position CenterPos = { -3447.563f, 4176.818f, 29.186f }; // also cheaters check

enum SoundIds
{
	SOUND_1 = 54316, // aggro
	SOUND_2 = 54310, // call seas
	SOUND_3 = 54315, // quake
	SOUND_4 = 54332, // kill
	SOUND_5 = 54313, // bubble
	SOUND_6 = 54319, // death
};

#define AGGRO_TEXT "You weaklings will drown beneath these waves!"
#define CALL_OF_SEAS_TEXT "Seas! Obey my command!"
#define QUAKE_TEXT "The earth trembles before the rising tide!"
#define KILL_TEXT "This was a inevitable as the tides, fools."
#define GASEOUS_BUBBLE_TEXT "Pity you cannot survive without air!"
#define DEATH_TEXT "I... I've failed... But my queen will not..."

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

class bfa_boss_king_deepbeard : public CreatureScript
{
public:
	bfa_boss_king_deepbeard() : CreatureScript("bfa_boss_king_deepbeard")
	{}

	struct bfa_boss_king_deepbeard_AI : public ScriptedAI
	{
		bfa_boss_king_deepbeard_AI(Creature* creature) : ScriptedAI(creature)
		{
			instance = me->GetInstanceScript();
		}

		EventMap events;
		bool enrage;
		InstanceScript* instance;

		void Reset()
		{
			events.Reset();
			enrage = false;
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			me->NearTeleportTo(me->GetHomePosition());
			me->SetPowerType(POWER_ENERGY);
			me->SetMaxPower(POWER_ENERGY, 100);
			me->SetPower(POWER_ENERGY, 30);
		}

		void JustDied(Unit* /**/) 
		{
			SelectSoundAndText(me, 2);
			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
			summons.DespawnAll();
			me->RemoveAllAreaTriggers();
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
				case 3: // bubble
					me->PlayDirectSound(SOUND_5);
					me->Yell(GASEOUS_BUBBLE_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 4: // Quake
					me->PlayDirectSound(SOUND_3);
					me->Yell(QUAKE_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 5: // Call seas
					me->PlayDirectSound(SOUND_2);
					me->Yell(CALL_OF_SEAS_TEXT, LANG_UNIVERSAL, NULL);
					break;
				case 6: // Kill
					me->PlayDirectSound(SOUND_4);
					me->Yell(KILL_TEXT, LANG_UNIVERSAL, NULL);
					break;
				default:
					break;
				}
			}
		}

		void KilledUnit(Unit* victim)
		{
			SelectSoundAndText(me, 6);
		}

		void EnterCombat(Unit* /**/)
		{
			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

			SelectSoundAndText(me, 1);
			events.ScheduleEvent(EVENT_ADD_ENERGY, TIMER_ADD_ENERGY);
			events.ScheduleEvent(EVENT_GROUND_SLAM, TIMER_GROUND_SLAM);
			events.ScheduleEvent(EVENT_GASEOUS_BUBBLES, TIMER_GASEOUS_BUBBLE);
			events.ScheduleEvent(EVENT_QUAKE, TIMER_QUAKE);
			events.ScheduleEvent(EVENT_CALL_OF_SEAS, TIMER_CALL_OF_SEAS);
			me->SetPower(POWER_ENERGY, 30);
		}

		void DamageTaken(Unit* /**/, uint32 & /**/) 
		{
			if (me->HealthBelowPct(30) && !enrage)
			{
				enrage = true;
				me->CastSpell(me, SPELL_FRENZY, true);
			}
		}

		void EnterEvadeMode(EvadeReason reason)
		{
			me->RemoveAllAreaTriggers();
			summons.DespawnAll();
			Reset();
		}

		bool CheckCheaters()
		{
			Map::PlayerList const& playerList = me->GetMap()->GetPlayers();
			for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
				if (Player* player = i->GetSource())
				{
					if (!player->IsGameMaster()) //gm check
					{
						if (player->GetDistance(CenterPos.GetPositionX(), CenterPos.GetPositionY(), CenterPos.GetPositionZ()) >= 75.0f)
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

		void SummonedCreatureDespawn(Creature* summon) override
		{
			if (summon->GetEntry() == NPC_CALL_OF_THE_SEA)
			{
				Map::PlayerList const & players = me->GetMap()->GetPlayers();

				for (auto & it : players)
				{
					if (Player* player = it.GetSource())
					{
						player->RemoveAurasDueToSpell(SPELL_CALL_OF_SEAS_DMG);
						player->RemoveAurasDueToSpell(SPELL_CALL_OF_SEAS_AURA);
					}
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
				case EVENT_CALL_OF_SEAS:
				{
					SelectSoundAndText(me, 5);
					std::ostringstream str;
					str << "King Deepbeard begins to cast |cFFF00000|h[Call the Seas]|h|r!";
					me->TextEmote(str.str().c_str(), 0, true);
					DoCast(me, SPELL_CALL_OF_SEAS);
					events.ScheduleEvent(EVENT_CALL_OF_SEAS, TIMER_CALL_OF_SEAS);
					break;
				}
				case EVENT_ADD_ENERGY:
					me->SetPower(POWER_ENERGY, me->GetPower(POWER_ENERGY) + 5);
					events.ScheduleEvent(EVENT_ADD_ENERGY, TIMER_ADD_ENERGY);
					break;
				case EVENT_GROUND_SLAM:
				{
					DoCastVictim(SPELL_GROUND_SLAM);
					DoCastVictim(SPELL_GROUND_SLAM_DMG, true);
					events.ScheduleEvent(EVENT_GROUND_SLAM, TIMER_GROUND_SLAM_AFTER);
					break;
				}

				case EVENT_GASEOUS_BUBBLES:
				{
					SelectSoundAndText(me, 3);
					std::list<Unit*> targets;
					SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true);
					targets.remove_if(checkSpec());

					if (!targets.empty())
						if (targets.size() >= 2)
							targets.resize(2);

					for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
						me->CastSpell((*itr), SPELL_GASEOUS_BUBBLE);

					events.ScheduleEvent(EVENT_GASEOUS_BUBBLES, TIMER_GASEOUS_BUBBLE_AFTER);
					break;
				}

				case EVENT_QUAKE:
				{
					if (me->GetPower(POWER_ENERGY) == 100)
					{
						me->CastSpell(me->GetVictim(), SPELL_QUAKE);
						SelectSoundAndText(me, 4);
					}
					events.ScheduleEvent(EVENT_QUAKE, TIMER_QUAKE);
					break;
				}
				}
			}

			DoMeleeAttackIfReady();
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_boss_king_deepbeard_AI(creature);
	}
};

class bfa_npc_quake : public CreatureScript
{
public:
	bfa_npc_quake() : CreatureScript("bfa_npc_quake")
	{
	}

	struct bfa_npc_quake_AI : public ScriptedAI
	{
		bfa_npc_quake_AI(Creature* creature) : ScriptedAI(creature)
		{
			me->SetFaction(14);
		}

		void Reset()
		{
			me->CastSpell(me, SPELL_QUAKE_DMG, true);
			me->CastSpell(me, SPELL_AFTERSHOCK);
		}
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_quake_AI(creature);
	}
};

class bfa_npc_call_the_seas : public CreatureScript
{
public:
	bfa_npc_call_the_seas() : CreatureScript("bfa_npc_call_the_seas")
	{}

	struct bfa_npc_call_the_seas_AI : public ScriptedAI
	{
		bfa_npc_call_the_seas_AI(Creature* creature) : ScriptedAI(creature)
		{

		}

		void Reset()
		{
			me->SetReactState(REACT_PASSIVE);
			me->AddUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
			me->CastSpell(me, SPELL_CALL_OF_SEAS_AURA, true);

			me->GetMotionMaster()->MoveRandom(50.f);

			const auto & players = me->GetMap()->GetPlayers();

			if (players.isEmpty())
				return;

			for (auto & it : players)
			{
				if (it.GetSource())
					_targets.push_back(it.GetSource());
			}
		}

		void UpdateAI(uint32 diff) override
		{
			if (!_targets.empty())
			{
				for (auto & it : _targets)
				{
					if (it->GetDistance2d(me) <= 2.0f)
					{
						if (!it->HasAura(SPELL_CALL_OF_SEAS_DMG))
							me->CastSpell(it, SPELL_CALL_OF_SEAS_DMG, true);
					}
					else if (it)
						it->RemoveAurasDueToSpell(SPELL_CALL_OF_SEAS_DMG, me->GetGUID());
				}
			}
		}

	private:
		std::list<Player*> _targets;
	};

	CreatureAI* GetAI(Creature* creature) const override
	{
		return new bfa_npc_call_the_seas_AI(creature);
	}
};

class bfa_spell_gaseous_bubbles : public SpellScriptLoader
{
public:
	bfa_spell_gaseous_bubbles() : SpellScriptLoader("bfa_spell_gaseous_bubbles")
	{}

	class bfa_spell_gaseous_bubbles_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_gaseous_bubbles_SpellScript);

		void FilterTargets(std::list<WorldObject*> & targets)
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

		void Register()
		{
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_gaseous_bubbles_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
		}
	};

	class bfa_spell_gaseous_bubbles_AuraScript : public AuraScript
	{
	public:
		PrepareAuraScript(bfa_spell_gaseous_bubbles_AuraScript);

		bool Load() override
		{
			_amountAbsorbed = 0;
			return true;
		}

		void HandleEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
		{
			if (!GetUnitOwner())
				return;

			Unit* owner = GetUnitOwner();
			AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();

			if (int32(_amountAbsorbed) >= aurEff->GetBaseAmount())
				return;

			if (removeMode == AURA_REMOVE_BY_EXPIRE)
			{
				if (owner->GetMap() && owner->GetMap()->IsHeroic() || owner->GetMap()->IsMythic())
					owner->CastCustomSpell(SPELL_GASEOUS_EXPLOSION, SPELLVALUE_BASE_POINT0, aurEff->GetBaseAmount() - _amountAbsorbed, owner, true);
				else
					owner->CastSpell(owner, SPELL_GASEOUS_EXPLOSION, true);
			}
		}

		void HandleDmgAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
		{
			_amountAbsorbed += absorbAmount;
		}

		void Register()
		{
			AfterEffectAbsorb += AuraEffectAbsorbFn(bfa_spell_gaseous_bubbles_AuraScript::HandleDmgAbsorb, EFFECT_0);
			AfterEffectRemove += AuraEffectRemoveFn(bfa_spell_gaseous_bubbles_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
		}

	private:
		uint32 _amountAbsorbed;
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_gaseous_bubbles_SpellScript();
	}

	AuraScript* GetAuraScript() const
	{
		return new bfa_spell_gaseous_bubbles_AuraScript();
	}
};

class bfa_spell_call_of_seas : public SpellScriptLoader
{
public:
	bfa_spell_call_of_seas() : SpellScriptLoader("bfa_spell_call_of_seas")
	{}

	class bfa_spell_call_of_seas_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_call_of_seas_SpellScript);

		void HandleOnCast()
		{
			if (!GetCaster())
				return;


			for (uint8 i = 0; i < 40; i++)
			{
				Position random = GetCaster()->GetRandomPoint(CenterPos, 45.0f);
				GetCaster()->SummonCreature(NPC_CALL_OF_THE_SEA, random, TEMPSUMMON_TIMED_DESPAWN, 21 * IN_MILLISECONDS);
			}
		}

		void FilterTargets(std::list<WorldObject*> & targets)
		{
			if (targets.empty())
				return;

			targets.clear();
		}

		void Register()
		{
			OnCast += SpellCastFn(bfa_spell_call_of_seas_SpellScript::HandleOnCast);
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_call_of_seas_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
		}

	private:
		std::list<Player*> _targets;
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_call_of_seas_SpellScript();
	}
};

class bfa_spell_quake : public SpellScriptLoader
{
public:
	bfa_spell_quake() : SpellScriptLoader("bfa_spell_quake")
	{}

	class bfa_spell_quake_SpellScript : public SpellScript
	{
	public:
		PrepareSpellScript(bfa_spell_quake_SpellScript);

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

		void Register()
		{
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_quake_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_quake_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENTRY);
		}
	};

	SpellScript* GetSpellScript() const
	{
		return new bfa_spell_quake_SpellScript();
	}
};

void AddSC_boss_king_deepbeard()
{
	new bfa_boss_king_deepbeard();

	new bfa_npc_quake();
	new bfa_npc_call_the_seas();

	new bfa_spell_gaseous_bubbles();
	new bfa_spell_call_of_seas();
	new bfa_spell_quake();
}
