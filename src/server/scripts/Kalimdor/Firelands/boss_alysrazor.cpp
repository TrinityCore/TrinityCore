/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "SpellScript.h"
#include "MoveSplineInit.h"
#include "Cell.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "firelands.h"

enum Texts
{
    // Egg Pile
    EMOTE_CRACKING_EGGS         = 0,    // The Molten Eggs begin to crack and splinter!
};

enum Spells
{
    // Harbinger of Flame
    SPELL_FIRE_IT_UP                            = 100093,
    SPELL_FIEROBLAST_TRASH                      = 100094,
    SPELL_FIEROCLAST_BARRAGE                    = 100095,
    SPELL_FIRE_CHANNELING                       = 100109,

    // Blazing Monstrosity
    SPELL_RIDE_MONSTROSITY                      = 93970,
    SPELL_SHARE_HEALTH_LEFT                     = 101502,
    SPELL_SHARE_HEALTH_RIGHT                    = 101503,
    SPELL_SLEEP_ULTRA_HIGH_PRIORITY             = 99480,
    SPELL_GENERIC_DUMMY_CAST                    = 100088,
    SPELL_LEFT_SIDE_SMACK_L                     = 100076,
    SPELL_RIGHT_SIDE_SMACK_L                    = 100078,
    SPELL_HEAD_BONK_L                           = 100080,
    SPELL_TICKLE_L                              = 100082,
    SPELL_KNOCKBACK_RIGHT                       = 100084,
    SPELL_KNOCKBACK_LEFT                        = 100085,
    SPELL_KNOCKBACK_FORWARD                     = 100086,
    SPELL_KNOCKBACK_BACK                        = 100087,
    SPELL_HEAD_BONK_R                           = 100089,
    SPELL_LEFT_SIDE_SMACK_R                     = 100090,
    SPELL_RIGHT_SIDE_SMACK_R                    = 100091,
    SPELL_TICKLE_R                              = 100092,
    SPELL_MOLTEN_BARRAGE_EFFECT_L               = 100071,
    SPELL_MOLTEN_BARRAGE_LEFT                   = 100072,
    SPELL_MOLTEN_BARRAGE_RIGHT                  = 100073,
    SPELL_MOLTEN_BARRAGE_EFFECT_R               = 100074,
    SPELL_MOLTEN_BARRAGE_VISUAL                 = 100075,
    SPELL_AGGRO_CLOSEST                         = 100462,
    SPELL_INVISIBILITY_AND_STEALTH_DETECTION    = 18950,

    // Egg Pile
    SPELL_SUMMON_SMOULDERING_HATCHLING          = 100096,
    SPELL_MOLTEN_EGG_TRASH_CALL_L               = 100097,
    SPELL_MOLTEN_EGG_TRASH_CALL_R               = 100098,
    SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION       = 100099,
};

#define SPELL_SHARE_HEALTH          (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_SHARE_HEALTH_LEFT : SPELL_SHARE_HEALTH_RIGHT)
#define SPELL_MOLTEN_BARRAGE        (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_MOLTEN_BARRAGE_LEFT : SPELL_MOLTEN_BARRAGE_RIGHT)
#define SPELL_MOLTEN_BARRAGE_EFFECT (me->GetEntry() == NPC_BLAZING_MONSTROSITY_LEFT ? SPELL_MOLTEN_BARRAGE_EFFECT_L : SPELL_MOLTEN_BARRAGE_EFFECT_R)

enum Events
{
    // Blazing Monstrosity
    EVENT_START_SPITTING                = 1,
    EVENT_CONTINUE_SPITTING             = 2,

    // Harbinger of Flame
    EVENT_FIEROBLAST                    = 1,
    EVENT_FIEROCLAST_BARRAGE            = 2,

    // Egg Pile
    EVENT_SUMMON_SMOULDERING_HATCHLING  = 1,
};

enum MiscData
{
    MODEL_INVISIBLE_STALKER     = 11686,
    ANIM_KIT_BIRD_WAKE          = 1469,
    ANIM_KIT_BIRD_TURN          = 1473,
};

class RespawnEggEvent : public BasicEvent
{
    public:
        explicit RespawnEggEvent(Creature* egg) : _egg(egg) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _egg->RestoreDisplayId();
            return true;
        }

    private:
        Creature* _egg;
};

class MoltenEggCheck
{
    public:
        explicit MoltenEggCheck(Creature* pile) : _eggPile(pile) { }

        bool operator()(Unit* object) const
        {
            if (object->GetEntry() != NPC_MOLTEN_EGG_TRASH)
                return false;

            if (object->GetDisplayId() != object->GetNativeDisplayId())
                return false;

            if (_eggPile->GetDistance2d(object) > 20.0f)
                return false;

            return true;
        }

    private:
        Creature* _eggPile;
};

class TrashRespawnWorker
{
    public:
        void operator()(Creature* creature) const
        {
            switch (creature->GetEntry())
            {
                case NPC_BLAZING_MONSTROSITY_LEFT:
                case NPC_BLAZING_MONSTROSITY_RIGHT:
                case NPC_EGG_PILE:
                case NPC_HARBINGER_OF_FLAME:
                case NPC_MOLTEN_EGG_TRASH:
                    if (!creature->IsAlive())
                        creature->Respawn(true);
                    break;
                case NPC_SMOULDERING_HATCHLING:
                    creature->DespawnOrUnsummon();
                    break;
            }
        }
};

static void AlysrazorTrashEvaded(Creature* creature)
{
    TrashRespawnWorker check;
    Trinity::CreatureWorker<TrashRespawnWorker> worker(creature, check);
    creature->VisitNearbyGridObject(SIZE_OF_GRIDS, worker);
}

class npc_harbinger_of_flame : public CreatureScript
{
    public:
        npc_harbinger_of_flame() : CreatureScript("npc_harbinger_of_flame") { }

        struct npc_harbinger_of_flameAI : public ScriptedAI
        {
            npc_harbinger_of_flameAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void EnterCombat(Unit* /*target*/)
            {
                if (Creature* bird = ObjectAccessor::GetCreature(*me, me->GetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT)))
                    DoZoneInCombat(bird, 200.0f);

                me->InterruptSpell(CURRENT_CHANNELED_SPELL);
                _events.Reset();
                _events.ScheduleEvent(EVENT_FIEROBLAST, 1);
                _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, 6000);
            }

            void JustReachedHome() OVERRIDE
            {
                AlysrazorTrashEvaded(me);
            }

            void MoveInLineOfSight(Unit* unit) OVERRIDE
            {
                if (me->IsInCombat())
                    return;

                if (!unit->IsCharmedOwnedByPlayerOrPlayer())
                    return;

                ScriptedAI::MoveInLineOfSight(unit);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!me->IsInCombat())
                    if (!me->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                        if (Creature* fireBird = me->FindNearestCreature((me->GetHomePosition().GetPositionY() > -275.0f ? NPC_BLAZING_MONSTROSITY_LEFT : NPC_BLAZING_MONSTROSITY_RIGHT), 100.0f))
                            DoCast(fireBird, SPELL_FIRE_CHANNELING);

                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FIEROBLAST:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, false, -SPELL_RIDE_MONSTROSITY))
                                DoCast(target, SPELL_FIEROBLAST_TRASH);
                            _events.RescheduleEvent(EVENT_FIEROBLAST, 500);  // cast time is longer, but thanks to UNIT_STATE_CASTING check it won't trigger more often (need this because this creature gets a stacking haste aura)
                            break;
                        case EVENT_FIEROCLAST_BARRAGE:
                            DoCastAOE(SPELL_FIEROCLAST_BARRAGE);
                            _events.ScheduleEvent(EVENT_FIEROCLAST_BARRAGE, urand(9000, 12000));
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_harbinger_of_flameAI(creature);
        }
};

class npc_blazing_monstrosity : public CreatureScript
{
    public:
        npc_blazing_monstrosity() : CreatureScript("npc_blazing_monstrosity") { }

        struct npc_blazing_monstrosityAI : public PassiveAI
        {
            npc_blazing_monstrosityAI(Creature* creature) : PassiveAI(creature), _summons(creature)
            {
            }

            void EnterEvadeMode() OVERRIDE
            {
                _summons.DespawnAll();
                _events.Reset();
                PassiveAI::EnterEvadeMode();
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _summons.DespawnAll();
                _events.Reset();
            }

            void JustReachedHome() OVERRIDE
            {
                AlysrazorTrashEvaded(me);
            }

            void EnterCombat(Unit* /*target*/)
            {
                DoZoneInCombat();
                me->RemoveAurasDueToSpell(SPELL_SLEEP_ULTRA_HIGH_PRIORITY);
                me->PlayOneShotAnimKit(ANIM_KIT_BIRD_WAKE);
                _events.Reset();
                _events.ScheduleEvent(EVENT_START_SPITTING, 6000);
                _events.ScheduleEvent(EVENT_CONTINUE_SPITTING, 9000);
            }

            void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) OVERRIDE
            {
                if (!apply)
                    return;

                // Our passenger is another vehicle (boardable by players)
                DoCast(passenger, SPELL_SHARE_HEALTH, true);
                passenger->setFaction(35);
                passenger->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                // Hack to relocate vehicle on vehicle so exiting players are not moved under map
                Movement::MoveSplineInit init(passenger);
                init.DisableTransportPathTransformations();
                init.MoveTo(0.6654003f, 0.0f, 1.9815f);
                init.SetFacing(0.0f);
                init.Launch();
            }

            void JustSummoned(Creature* summon) OVERRIDE
            {
                _summons.Summon(summon);
            }

            void SummonedCreatureDespawn(Creature* summon) OVERRIDE
            {
                _summons.Despawn(summon);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_START_SPITTING:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, false, -SPELL_RIDE_MONSTROSITY))
                                DoCast(target, SPELL_MOLTEN_BARRAGE);
                            break;
                        case EVENT_CONTINUE_SPITTING:
                            DoCastAOE(SPELL_MOLTEN_BARRAGE_EFFECT);
                            if (Creature* egg = me->FindNearestCreature(NPC_EGG_PILE, 100.0f))
                                egg->AI()->DoAction(me->GetEntry());
                            break;
                    }
                }
            }

        private:
            SummonList _summons;
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_blazing_monstrosityAI(creature);
        }
};

class npc_molten_barrage : public CreatureScript
{
    public:
        npc_molten_barrage() : CreatureScript("npc_molten_barrage") { }

        struct npc_molten_barrageAI : public NullCreatureAI
        {
            npc_molten_barrageAI(Creature* creature) : NullCreatureAI(creature)
            {
            }

            void AttackStart(Unit* target) OVERRIDE
            {
                if (target)
                    me->GetMotionMaster()->MoveFollow(target, 0.0f, 0.0f, MOTION_SLOT_IDLE);
            }

            void IsSummonedBy(Unit* /*summoner*/) OVERRIDE
            {
                DoCastAOE(SPELL_AGGRO_CLOSEST, true);
                DoCast(me, SPELL_MOLTEN_BARRAGE_VISUAL);
                DoCast(me, SPELL_INVISIBILITY_AND_STEALTH_DETECTION, true);
            }

            void MovementInform(uint32 movementType, uint32 /*pointId*/) OVERRIDE
            {
                if (movementType != EFFECT_MOTION_TYPE)
                    return;

                DoCastAOE(SPELL_AGGRO_CLOSEST);
                me->ClearUnitState(UNIT_STATE_CANNOT_TURN);
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_molten_barrageAI(creature);
        }
};

class npc_egg_pile : public CreatureScript
{
    public:
        npc_egg_pile() : CreatureScript("npc_egg_pile") { }

        struct npc_egg_pileAI : public CreatureAI
        {
            npc_egg_pileAI(Creature* creature) : CreatureAI(creature)
            {
            }

            void AttackStart(Unit* /*target*/) OVERRIDE { }

            void Reset() OVERRIDE
            {
                me->SetReactState(REACT_PASSIVE);
                _events.Reset();
                _callHatchlingSpell = 0;
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _events.Reset();
                std::list<Creature*> eggs;
                GetCreatureListWithEntryInGrid(eggs, me, NPC_MOLTEN_EGG_TRASH, 20.0f);
                for (std::list<Creature*>::const_iterator itr = eggs.begin(); itr != eggs.end(); ++itr)
                    (*itr)->CastSpell(*itr, SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION, TRIGGERED_FULL_MASK);

                DoCast(me, SPELL_ALYSRAZOR_COSMETIC_EGG_XPLOSION, true);
            }

            void JustReachedHome() OVERRIDE
            {
                AlysrazorTrashEvaded(me);
            }

            void DoAction(int32 action) OVERRIDE
            {
                if (action != NPC_BLAZING_MONSTROSITY_LEFT &&
                    action != NPC_BLAZING_MONSTROSITY_RIGHT)
                    return;

                if (action == NPC_BLAZING_MONSTROSITY_LEFT)
                    Talk(EMOTE_CRACKING_EGGS);

                _callHatchlingSpell = (action == NPC_BLAZING_MONSTROSITY_LEFT) ? SPELL_MOLTEN_EGG_TRASH_CALL_L : SPELL_MOLTEN_EGG_TRASH_CALL_R;
                DoZoneInCombat();
                _events.Reset();
                _events.ScheduleEvent(EVENT_SUMMON_SMOULDERING_HATCHLING, 1);
            }

            void UpdateAI(uint32 diff) OVERRIDE
            {
                if (!UpdateVictim())
                    return;

                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_SUMMON_SMOULDERING_HATCHLING:
                        {
                            std::list<Creature*> eggs;
                            MoltenEggCheck check(me);
                            Trinity::CreatureListSearcher<MoltenEggCheck> searcher(me, eggs, check);
                            me->VisitNearbyGridObject(20.0f, searcher);
                            if (!eggs.empty())
                            {
                                Creature* egg = Trinity::Containers::SelectRandomContainerElement(eggs);
                                egg->CastSpell(egg, SPELL_SUMMON_SMOULDERING_HATCHLING, TRIGGERED_FULL_MASK);
                                egg->SetDisplayId(MODEL_INVISIBLE_STALKER);
                                egg->m_Events.AddEvent(new RespawnEggEvent(egg), egg->m_Events.CalculateTime(5000));
                            }

                            if (_callHatchlingSpell)
                                DoCastAOE(_callHatchlingSpell, true);
                            _events.ScheduleEvent(EVENT_SUMMON_SMOULDERING_HATCHLING, urand(6000, 10000));
                            break;
                        }
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            EventMap _events;
            uint32 _callHatchlingSpell;
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_egg_pileAI(creature);
        }
};

class spell_alysrazor_cosmetic_egg_xplosion : public SpellScriptLoader
{
    public:
        spell_alysrazor_cosmetic_egg_xplosion() : SpellScriptLoader("spell_alysrazor_cosmetic_egg_xplosion") { }

        class spell_alysrazor_cosmetic_egg_xplosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_cosmetic_egg_xplosion_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sCreatureDisplayInfoStore.LookupEntry(MODEL_INVISIBLE_STALKER))
                    return false;
                return true;
            }

            void HandleExplosion(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->SetDisplayId(MODEL_INVISIBLE_STALKER);
                if (Creature* creature = GetHitCreature())
                    creature->DespawnOrUnsummon(4000);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_cosmetic_egg_xplosion_SpellScript::HandleExplosion, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_alysrazor_cosmetic_egg_xplosion_SpellScript();
        }
};

class spell_alysrazor_turn_monstrosity : public SpellScriptLoader
{
    public:
        spell_alysrazor_turn_monstrosity() : SpellScriptLoader("spell_alysrazor_turn_monstrosity") { }

        class spell_alysrazor_turn_monstrosity_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_turn_monstrosity_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_GENERIC_DUMMY_CAST))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_RIGHT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_LEFT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_FORWARD))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_KNOCKBACK_BACK))
                    return false;
                return true;
            }

            void KnockBarrage(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->GetMotionMaster()->MoveIdle();
                if (TempSummon* summ = GetHitUnit()->ToTempSummon())
                    if (Unit* summoner = summ->GetSummoner())
                        GetHitUnit()->CastSpell(summoner, SPELL_GENERIC_DUMMY_CAST, TRIGGERED_FULL_MASK);

                float angle = 0.0f;
                if (Unit* bird = GetCaster()->GetVehicleBase())
                {
                    bird->SetInFront(GetHitUnit());
                    angle = bird->GetOrientation();
                }

                uint32 spellId = 0;
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_RIGHT_SIDE_SMACK_R:
                    case SPELL_RIGHT_SIDE_SMACK_L:
                        spellId = SPELL_KNOCKBACK_RIGHT;
                        angle -= M_PI * 0.5f;
                        break;
                    case SPELL_LEFT_SIDE_SMACK_R:
                    case SPELL_LEFT_SIDE_SMACK_L:
                        spellId = SPELL_KNOCKBACK_LEFT;
                        angle += M_PI * 0.5f;
                        break;
                    case SPELL_HEAD_BONK_R:
                    case SPELL_HEAD_BONK_L:
                        spellId = SPELL_KNOCKBACK_FORWARD;
                        break;
                    case SPELL_TICKLE_R:
                    case SPELL_TICKLE_L:
                        spellId = SPELL_KNOCKBACK_BACK;
                        angle -= M_PI;
                        break;
                }

                // Cannot wait for object update to process facing spline, it's needed in next spell cast
                GetHitUnit()->SetOrientation(angle);
                GetHitUnit()->SetFacingTo(angle);
                GetHitUnit()->AddUnitState(UNIT_STATE_CANNOT_TURN);
                GetHitUnit()->CastSpell(GetHitUnit(), spellId, TRIGGERED_FULL_MASK);
            }

            void TurnBird(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->PlayOneShotAnimKit(ANIM_KIT_BIRD_TURN);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_turn_monstrosity_SpellScript::KnockBarrage, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_turn_monstrosity_SpellScript::TurnBird, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_alysrazor_turn_monstrosity_SpellScript();
        }
};

class spell_alysrazor_aggro_closest : public SpellScriptLoader
{
    public:
        spell_alysrazor_aggro_closest() : SpellScriptLoader("spell_alysrazor_aggro_closest") { }

        class spell_alysrazor_aggro_closest_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_aggro_closest_SpellScript);

            bool Load() OVERRIDE
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT;
            }

            void HandleEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                float curThreat = GetCaster()->getThreatManager().getThreat(GetHitUnit(), true);
                GetCaster()->getThreatManager().addThreat(GetHitUnit(), -curThreat + 50000.0f / std::min(1.0f, GetCaster()->GetDistance(GetHitUnit())));
            }

            void UpdateThreat()
            {
                GetCaster()->ClearUnitState(UNIT_STATE_CASTING);
                GetCaster()->GetAI()->AttackStart(GetCaster()->ToCreature()->SelectVictim());
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_alysrazor_aggro_closest_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
                AfterCast += SpellCastFn(spell_alysrazor_aggro_closest_SpellScript::UpdateThreat);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_alysrazor_aggro_closest_SpellScript();
        }
};

class spell_alysrazor_fieroblast : public SpellScriptLoader
{
    public:
        spell_alysrazor_fieroblast() : SpellScriptLoader("spell_alysrazor_fieroblast") { }

        class spell_alysrazor_fieroblast_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_alysrazor_fieroblast_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) OVERRIDE
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FIRE_IT_UP))
                    return false;
                return true;
            }

            void FireItUp()
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_FIRE_IT_UP, TRIGGERED_FULL_MASK);
            }

            void Register() OVERRIDE
            {
                AfterCast += SpellCastFn(spell_alysrazor_fieroblast_SpellScript::FireItUp);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_alysrazor_fieroblast_SpellScript();
        }
};

void AddSC_boss_alysrazor()
{
    new npc_harbinger_of_flame();
    new npc_blazing_monstrosity();
    new npc_molten_barrage();
    new npc_egg_pile();
    new spell_alysrazor_cosmetic_egg_xplosion();
    new spell_alysrazor_turn_monstrosity();
    new spell_alysrazor_aggro_closest();
    new spell_alysrazor_fieroblast();
}
