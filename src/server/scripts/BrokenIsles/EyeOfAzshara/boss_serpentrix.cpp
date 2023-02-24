///*
// * Copyright 2023 AzgathCore
// * Copyright 2021 HellgarveCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//#include "AreaTrigger.h"
//#include "AreaTriggerAI.h"
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//
//enum Spells
//{
//	// Serpentrix
//	SPELL_TOXIC_WOUND = 191855,
//	SPELL_TOXIC_PUDDLE = 191858,
//	SPELL_POISON_SPIT = 192050, //cast
//	SPELL_POISON_SPIT_TRIGGER = 191839, // xyz marker
//	SPELL_POISON_SPIT_DMG_1 = 191841, //damage xyz
//	SPELL_POISON_SPIT_DMG_2 = 191843,
//	SPELL_POISON_SPIT_DMG_3 = 191845,
//	SPELL_SUMERGE = 191873,
//	SPELL_RAMPAGE = 191848,
//	SPELL_RAMPAGE_TRIGGER = 191850,
//	SPELL_HYDRA_HEAD = 202680,
//	SPELL_HYDRA_HEAD_HIDE = 180898,
//
//	// Blazing Hydra Spawn
//	SPELL_BLAZING_NOVA = 192003,
//
//	// Arcane Hydra Spawn
//	SPELL_ARCANE_BLAST = 192005,
//	SPELL_ARCANE_CHARGE = 192007,
//};
//
//enum Events
//{
//	EVENT_TOXIC_WOUND = 1,
//	EVENT_POISON_SPIT = 2,
//	EVENT_ACTIVATE_HEADS = 3,
//	EVENT_RAMPAGE = 4,
//
//	EVENT_ARCANE_BLAST,
//	EVENT_BLAZING_NOVA,
//};
//
//enum Creatures
//{
//	BOSS_SERPENTRIX = 91797,
//
//	NPC_BLAZING_HYDRA = 97259,
//	NPC_ARCANE_HYDRA = 97260,
//	NPC_SINK_HOLE = 97263,
//};
//
//enum Timers
//{
//	TIMER_ARCANE_BLAST = 3 * IN_MILLISECONDS,
//	TIMER_BLAZING_NOVA = 3 * IN_MILLISECONDS,
//
//	TIMER_TOXIC_WOUND = 25 * IN_MILLISECONDS,
//	TIMER_POISON_SPIT = 7 * IN_MILLISECONDS,
//
//	TIMER_RAMPAGE_CHECK = 2 * IN_MILLISECONDS,
//};
//
//const Position spawnHeadPos[4] = 
//{
//	{ -3256.36f, 4370.39f, 0.37f }, // 2
//	{ -3199.39f, 4384.95f, 0.16f }, // 3
//	{ -3246.70f, 4479.64f, 0.26f }, // 5
//	{ -3294.19f, 4460.52f, -0.63f }, // 6
//};
//
//const Position emergeBossPos[2] =
//{
//	{ -3192.23f, 4440.18f, -0.64f }, // 1
//	{ -3304.16f, 4405.52f, 0.08f }, // 2
//};
//
//const Position mainHole[1] =
//{
//	{ -3253.82f, 4428.95f, -1.74f }, // cheaters 95yards check also while reseting 
//};
//
//struct checkSpec : public std::unary_function<Unit*, bool>
//{
//	checkSpec() {}
//
//	bool operator() (const Unit* pTarget)
//	{
//		Player* player = const_cast<Player*>(pTarget->ToPlayer());
//		uint32 specialization = player->GetSpecializationId();
//		return ((player->getClass() == CLASS_DRUID && specialization == TALENT_SPEC_DRUID_BEAR)
//			|| (player->getClass() == CLASS_WARRIOR && specialization == TALENT_SPEC_WARRIOR_PROTECTION)
//			|| (player->getClass() == CLASS_PALADIN && specialization == TALENT_SPEC_PALADIN_PROTECTION)
//			|| (player->getClass() == CLASS_DEATH_KNIGHT && specialization == TALENT_SPEC_DEATHKNIGHT_BLOOD)
//			|| (player->getClass() == CLASS_DEMON_HUNTER && specialization == TALENT_SPEC_DEMON_HUNTER_VENGEANCE)
//			|| (player->getClass() == CLASS_MONK && specialization == TALENT_SPEC_MONK_BREWMASTER));
//	}
//};
//
//// at visual
//
//class bfa_boss_serpentrix : public CreatureScript
//{
//public:
//	bfa_boss_serpentrix() : CreatureScript("bfa_boss_serpentrix")
//	{}
//
//	struct bfa_boss_serpentrix_AI : public ScriptedAI
//	{
//		bfa_boss_serpentrix_AI(Creature* creature) : ScriptedAI(creature), summons(me)
//		{
//			instance = creature->GetInstanceScript();
//		}
//
//		SummonList summons;
//		Position EmergePos;
//		std::vector<Position> nextHole;
//		std::vector<Position> nextbossHole;
//		EventMap events;
//		bool adds1;
//		bool adds2;
//		InstanceScript* instance;
//
//		void JustSummoned(Creature* summon) override
//		{
//			summons.Summon(summon);
//
//			if (summon->GetEntry() == NPC_BLAZING_HYDRA || summon->GetEntry() == NPC_ARCANE_HYDRA)
//			{
//				summon->SetInCombatWithZone();
//				summon->AddAura(SPELL_HYDRA_HEAD);
//			}
//		}
//
//		void Reset() override
//		{
//			me->RemoveAllAuras();
//			nextHole.clear();
//			summons.DespawnAll();
//			me->SetSpeed(MOVE_RUN, 100.0f);
//			me->SetSpeed(MOVE_WALK, 100.0f);
//			me->RemoveAllAreaTriggers();
//			me->GetMotionMaster()->MovePoint(0, mainHole[0]);
//			nextbossHole.clear();
//			events.Reset();
//			me->RemoveAllAreaTriggers();
//			adds1 = false;
//			adds2 = false;
//			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//		}
//
//		void JustDied(Unit*) override
//		{
//			summons.DespawnAll();
//			me->RemoveAllAreaTriggers();
//			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//		}
//
//		void InitEmergeSerpentrix()
//		{
//			nextbossHole.clear();
//			// gather 2 possible holes
//			nextbossHole.push_back(emergeBossPos[0]);
//			nextbossHole.push_back(emergeBossPos[1]);
//
//			Trinity::Containers::RandomResize(nextbossHole, 1);
//
//			for (auto& it : nextbossHole)
//				me->NearTeleportTo(it, false);
//		}
//		void InitEmerge()
//		{
//			nextHole.clear();
//
//			//gather all 4 possible holes
//			nextHole.push_back(spawnHeadPos[0]);
//			nextHole.push_back(spawnHeadPos[1]);
//			nextHole.push_back(spawnHeadPos[2]);
//			nextHole.push_back(spawnHeadPos[3]);
//
//			Trinity::Containers::RandomResize(nextHole, 2);
//
//			if (me->GetMap()->IsHeroic() || me->GetMap()->IsMythic())
//			{
//				DoSummon(NPC_BLAZING_HYDRA, nextHole.front(), 5 * IN_MILLISECONDS);
//				DoSummon(NPC_ARCANE_HYDRA, nextHole.back(), 5 * IN_MILLISECONDS);
//			}
//			else
//				for (auto& it : nextHole)
//				{
//					DoSummon(NPC_BLAZING_HYDRA, it, 5 * IN_MILLISECONDS);
//				}
//		}
//
//		void OnSpellFinished(SpellInfo const* spellInfo) override
//		{
//			switch (spellInfo->Id)
//			{
//			case SPELL_SUMERGE:
//				InitEmerge();
//				InitEmergeSerpentrix();
//				break;
//			}
//		}
//
//		void SubmergeText()
//		{
//			std::ostringstream str;
//			str << "Serpentrix begins to |cFFF00000|h[Submerge]|h|r!";
//			me->TextEmote(str.str().c_str(), 0, true);
//		}
//
//		void DamageTaken(Unit* attacker, uint32 & /**/) override
//		{
//			if (attacker)
//			{
//				if (me->IsWithinMeleeRange(attacker) && me->HasAura(SPELL_RAMPAGE))
//					me->CastStop();
//			}
//
//			if (me->HealthBelowPct(66) && !adds1)
//			{
//				adds1 = true;
//				me->CastSpell(me, SPELL_SUMERGE);
//				SubmergeText();
//			}
//			if (me->HealthBelowPct(33) && !adds2)
//			{
//				adds2 = true;
//				me->CastSpell(me, SPELL_SUMERGE);
//				SubmergeText();
//			}
//		}
//
//		void EnterEvadeMode(EvadeReason why) override
//		{
//			Reset();
//		}
//
//		void JustEngagedWith(Unit* /**/) override
//		{
//			me->AddAura(42716);
//			instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//			events.ScheduleEvent(EVENT_RAMPAGE, TIMER_RAMPAGE_CHECK);
//			events.ScheduleEvent(EVENT_POISON_SPIT, TIMER_POISON_SPIT);
//			events.ScheduleEvent(EVENT_TOXIC_WOUND, TIMER_TOXIC_WOUND);
//		}
//
//		void UpdateAI(uint32 diff) override
//		{
//			if (!UpdateVictim())
//				return;
//
//			events.Update(diff);
//
//			if (me->HasUnitState(UNIT_STATE_CASTING))
//				return;
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_RAMPAGE:
//				{
//					if (!me->IsWithinMeleeRange(me->GetVictim()))
//						me->CastSpell(me, SPELL_RAMPAGE);
//					events.ScheduleEvent(EVENT_RAMPAGE, TIMER_RAMPAGE_CHECK);
//					break;
//				}
//				case EVENT_POISON_SPIT:
//				{
//						me->CastSpell(SPELL_POISON_SPIT,true);
//
//					events.ScheduleEvent(EVENT_POISON_SPIT, TIMER_POISON_SPIT);
//					break;
//				}
//				case EVENT_TOXIC_WOUND:
//				{
//					std::list<Unit*> targets;
//					SelectTargetList(targets, 5, SELECT_TARGET_RANDOM, 500.0f, true, false);
//					targets.remove_if(checkSpec());
//
//					if (!targets.empty())
//						if (targets.size() >= 1)
//							targets.resize(1);
//
//					for (std::list<Unit*>::iterator itr = targets.begin(); itr != targets.end(); ++itr)
//					{
//						std::ostringstream str;
//						str << ((*itr)->GetName()) << " is afflicted with |cFFF00000|h[Toxic Wound]|h|r!";
//						me->TextEmote(str.str().c_str(), 0, true);
//						me->CastSpell((*itr), SPELL_TOXIC_WOUND);
//					}
//					events.ScheduleEvent(EVENT_TOXIC_WOUND, TIMER_TOXIC_WOUND);
//					break;
//				}
//				}
//			}
//
//			DoMeleeAttackIfReady();
//		}
//	};
//
//	CreatureAI* GetAI(Creature* creature) const override
//	{
//		return new bfa_boss_serpentrix_AI(creature);
//	}
//};
//
//class bfa_npc_serpentrix_head : public CreatureScript
//{
//public:
//	bfa_npc_serpentrix_head() : CreatureScript("bfa_npc_serpentrix_head")
//	{}
//
//	struct bfa_npc_serpentrix_head_AI : public ScriptedAI
//	{
//		bfa_npc_serpentrix_head_AI(Creature* creature) : ScriptedAI(creature)
//		{
//			instance = creature->GetInstanceScript();
//		}
//
//		EventMap events;
//		InstanceScript* instance;
//
//		void Reset() override
//		{
//			me->AddUnitState(UNIT_STATE_ROOT);
//			events.Reset();
//		}
//
//		void JustEngagedWith(Unit* /**/) override
//		{
//			switch (me->GetEntry())
//			{
//			case NPC_ARCANE_HYDRA:
//				events.ScheduleEvent(EVENT_ARCANE_BLAST, TIMER_ARCANE_BLAST);
//				instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//				break;
//			case NPC_BLAZING_HYDRA:
//				events.ScheduleEvent(EVENT_BLAZING_NOVA, TIMER_BLAZING_NOVA);
//				instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
//				break;
//			}
//		}
//
//		void DamageTaken(Unit* attacker, uint32& damage)
//		{
//			uint32 damageToDeal = damage;
//
//			if (Creature* boss = me->FindNearestCreature(BOSS_SERPENTRIX, 500.0f, true))
//			{
//				boss->SetHealth(boss->GetHealth() - damageToDeal);
//			}
//		}
//
//		void JustDied(Unit*) override
//		{
//			instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
//		}
//
//		void UpdateAI(uint32 diff) override
//		{
//			if (!UpdateVictim())
//				return;
//
//			if (me->HasUnitState(UNIT_STATE_CASTING))
//				return;
//
//			events.Update(diff);
//
//			while (uint32 eventId = events.ExecuteEvent())
//			{
//				switch (eventId)
//				{
//				case EVENT_BLAZING_NOVA:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
//						me->CastSpell(target, SPELL_BLAZING_NOVA);
//					events.ScheduleEvent(EVENT_BLAZING_NOVA, TIMER_BLAZING_NOVA);
//					break;
//				case EVENT_ARCANE_BLAST:
//					if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
//						me->CastSpell(target, SPELL_ARCANE_BLAST);
//					events.ScheduleEvent(EVENT_ARCANE_BLAST, TIMER_ARCANE_BLAST);
//					break;
//				}
//			}
//		}
//	};
//
//	CreatureAI* GetAI(Creature* creature) const override
//	{
//		return new bfa_npc_serpentrix_head_AI(creature);
//	}
//};
//
//// 4856
//class bfa_at_toxic_wound : public AreaTriggerEntityScript
//{
//public:
//	bfa_at_toxic_wound() : AreaTriggerEntityScript("bfa_at_toxic_wound")
//	{}
//
//	struct bfa_at_toxic_wound_AI : public AreaTriggerAI
//	{
//		bfa_at_toxic_wound_AI(AreaTrigger* at) : AreaTriggerAI(at)
//		{}
//
//		uint32 damageTimer;
//		std::list<Unit*> targets;
//
//		void OnInitialize() override
//		{
//			damageTimer = 0;
//		}
//
//		void OnUnitEnter(Unit* unit) override
//		{
//			if (!unit || !at->GetCaster())
//				return;
//			if (unit->ToPlayer())
//				targets.push_back(unit);
//		}
//
//		void OnUnitExit(Unit* unit) override
//		{
//			if (!unit)
//				return;
//			if (unit->ToPlayer())
//				targets.remove(unit);
//		}
//
//
//		void OnUpdate(uint32 diff) override
//		{
//			damageTimer += diff;
//			if (damageTimer >= 2 * IN_MILLISECONDS)
//			{
//				Map::PlayerList const& playerList = at->GetMap()->GetPlayers();
//				for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
//					if (Player* player = i->GetSource())
//					{
//						if (!player->IsGameMaster() && player->GetDistance(at) <= 4.5f) //gm check
//						{
//							player->CastSpell(player, SPELL_TOXIC_PUDDLE, true);
//						}
//					}
//
//				damageTimer = 0;
//			}
//		}
//
//	};
//
//	AreaTriggerAI* GetAI(AreaTrigger* at) const override
//	{
//		return new bfa_at_toxic_wound_AI(at);
//	}
//};
//
//class bfa_spell_poison_spit : public SpellScriptLoader
//{
//public:
//	bfa_spell_poison_spit() : SpellScriptLoader("bfa_spell_poison_spit")
//	{}
//
//	class bfa_spell_poison_spit_SpellScript : public SpellScript
//	{
//	public:
//		PrepareSpellScript(bfa_spell_poison_spit_SpellScript);
//
//		void HandleAreaTargets(std::list<WorldObject*>& targets)
//		{
//			if (targets.empty())
//				return;
//
//			for (auto & it : targets)
//			{
//				if (it && it->ToPlayer())
//					_targets.push_back(it->ToPlayer());
//			}
//
//		}
//
//		void HandleOnCast()
//		{
//			if (!GetCaster() || _targets.empty())
//				return;
//
//			for (auto & it : _targets)
//				GetCaster()->CastSpell(it, SPELL_POISON_SPIT_TRIGGER, true);
//		}
//
//		void Register()
//		{
//			OnCast += SpellCastFn(bfa_spell_poison_spit_SpellScript::HandleOnCast);
//			OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(bfa_spell_poison_spit_SpellScript::HandleAreaTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//		}
//
//	private:
//		std::list<Player*> _targets;
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new bfa_spell_poison_spit_SpellScript();
//	}
//};
//
//class bfa_spell_poison_spit_dmg : public SpellScriptLoader
//{
//public:
//	bfa_spell_poison_spit_dmg() : SpellScriptLoader("bfa_spell_poison_spit_dmg")
//	{}
//
//	class bfa_spell_poison_spit_dmg_SpellScript : public SpellScript
//	{
//	public:
//		PrepareSpellScript(bfa_spell_poison_spit_dmg_SpellScript);
//
//		void HandleDmg()
//		{
//			if (!GetCaster() || !GetHitUnit())
//				return;
//
//			GetCaster()->CastSpell(GetHitUnit(), SPELL_POISON_SPIT_DMG_1, true);
//		}
//
//		void Register()
//		{
//			OnHit += SpellHitFn(bfa_spell_poison_spit_dmg_SpellScript::HandleDmg);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new bfa_spell_poison_spit_dmg_SpellScript();
//	}
//};
//
//class bfa_spell_rampage_dmg : public SpellScriptLoader
//{
//public:
//	bfa_spell_rampage_dmg() : SpellScriptLoader("bfa_spell_rampage_dmg")
//	{}
//
//	class bfa_spell_rampage_dmg_SpellScript : public SpellScript
//	{
//	public:
//		PrepareSpellScript(bfa_spell_rampage_dmg_SpellScript);
//
//		void HandleDummy(SpellEffIndex /**/)
//		{
//			if (!GetHitUnit())
//				return;
//
//			GetCaster()->CastSpell(GetHitUnit(), SPELL_POISON_SPIT_DMG_2, true);
//		}
//
//		void Register()
//		{
//			OnEffectHitTarget += SpellEffectFn(bfa_spell_rampage_dmg_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
//		}
//	};
//
//	SpellScript* GetSpellScript() const
//	{
//		return new bfa_spell_rampage_dmg_SpellScript();
//	}
//};
//
//
//void AddSC_boss_serpentrix()
//{
//	new bfa_boss_serpentrix();
//	new bfa_npc_serpentrix_head();
//
//	new bfa_at_toxic_wound();
//
//	new bfa_spell_poison_spit();
//	new bfa_spell_poison_spit_dmg();
//	new bfa_spell_rampage_dmg();
//}
