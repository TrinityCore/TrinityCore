/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "violet_hold_assault.h"
#include "Unit.h"
#include "GameObject.h"
#include "SpellPackets.h"
#include <G3D/Vector3.h>
#include "GameObject.h"

enum Spells
{
    SPELL_WING_BUFFET               = 201355,
    SPELL_FROST_BREATH              = 201379,
    SPELL_TAIL_SWEEP                = 201354,
    SPELL_RELENTLESS_STORM          = 201672,
    SPELL_RELENTLESS_STORM_AR_1     = 201643,
    SPELL_RELENTLESS_STORM_AR_2     = 201652,
    SPELL_RELENTLESS_STORM_MISSILE  = 201848,
    SPELL_RELENTELSS_STORM_DUMMY    = 201865,
    SPELL_RELENTLESS_STORM_DMG      = 201852,
    SPELL_FROSTBITE                 = 201957,
    SPELL_ICE_BOMB                  = 201960,
    SPELL_FROZEN                    = 202037,
    SPELL_ICE_BOMB_SUMMON           = 201993,
    SPELL_FRIGID_WINDS              = 202062,
    SPELL_CHILL                     = 202065,
};

enum Events
{
    EVENT_WING_BUFFET       = 1,
    EVENT_FROST_BREATH      = 2,
    EVENT_TAIL_SWEEP        = 3,
    EVENT_FROSTBITE         = 4,
    EVENT_ICE_BOMB          = 5,
    EVENT_RELENTLEESS_STORM = 6,
    EVENT_GO_GROUND         = 7,
    EVENT_FRIGID_WINDS      = 8,
    EVENT_RESTORE_STATE     = 9,
};

enum Adds
{
    NPC_ICE_BLOCK    = 102301,
};

enum Points
{
    POINT_GROUND    = 0,
    POINT_AIR       = 1,
};

const Position AirPosition =  { 4631.69f, 4016.5f, 115.0f };
const Position LandPosition = { 4631.139f, 4023.363f, 77.989f };

constexpr int32 DATA_TRAPPED_PLAYER = 1;

class boss_shivermaw : public CreatureScript
{
    public:
        boss_shivermaw() : CreatureScript("boss_shivermaw")
        {}

        struct boss_shivermaw_AI : public BossAI
        {
            boss_shivermaw_AI(Creature* creature) : BossAI(creature, DATA_SHIVERMAW)
            {}

            void Reset() override
            {
                _Reset();
            }

            void JustDied(Unit* /**/) override
            {
                _JustDied();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type == EFFECT_MOTION_TYPE)
                {
                    if (id == POINT_AIR)
                    {
                        me->AddUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                        DoCast(SPELL_ICE_BOMB);
                        events.ScheduleEvent(EVENT_GO_GROUND, Seconds(10));
                    }
                    else if (id == POINT_GROUND)
                    {
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
                        events.ScheduleEvent(EVENT_ICE_BOMB, Seconds(60));
                        events.ScheduleEvent(EVENT_FRIGID_WINDS, Seconds(50));
                    }
                }
            }

            void EnterEvadeMode(EvadeReason reason) override
            {
                me->RemoveAllAreaTriggers();
                CreatureAI::EnterEvadeMode(reason);
            }

            void EnterCombat(Unit* ) override
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_FROST_BREATH, Seconds(6));
                events.ScheduleEvent(EVENT_RELENTLEESS_STORM, Seconds(10));
                events.ScheduleEvent(EVENT_WING_BUFFET, Seconds(16));
                events.ScheduleEvent(EVENT_TAIL_SWEEP, Seconds(14));
                events.ScheduleEvent(EVENT_ICE_BOMB, Seconds(40));

                if (IsHeroic())
                    events.ScheduleEvent(EVENT_FRIGID_WINDS, Seconds(30));
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_WING_BUFFET:
                    {
                        DoCastVictim(SPELL_WING_BUFFET);
                        events.ScheduleEvent(EVENT_WING_BUFFET, Seconds(20));
                        break;
                    }

                    case EVENT_FROST_BREATH:
                    {
                        me->StopMoving();
                        DoCast(me, SPELL_FROST_BREATH);
                        events.ScheduleEvent(EVENT_FROST_BREATH, Seconds(urand(15, 30)));
                        events.ScheduleEvent(EVENT_RESTORE_STATE, Seconds(2));
                        break;
                    }

                    case EVENT_RESTORE_STATE:
                    {
                        me->ClearUnitState(UNIT_STATE_ROOT);
                        break;
                    }

                    case EVENT_TAIL_SWEEP:
                    {
                        DoCast(me, SPELL_TAIL_SWEEP);
                        events.ScheduleEvent(EVENT_TAIL_SWEEP, Seconds(urand(15, 25)));
                        break;
                    }

                    case EVENT_RELENTLEESS_STORM:
                    {
                        DoCast(me, SPELL_RELENTLESS_STORM);
                        events.ScheduleEvent(EVENT_RELENTLEESS_STORM, Seconds(10));
                        break;
                    }

                    case EVENT_FRIGID_WINDS:
                    {
                        DoCast(me, SPELL_FRIGID_WINDS);
                        break;
                    }

                    case EVENT_ICE_BOMB:
                    {
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        me->GetMotionMaster()->MoveTakeoff(POINT_AIR, AirPosition);
                        events.DelayEvents(Seconds(20));
                        break;
                    }

                    case EVENT_GO_GROUND:
                    {
                        me->GetMotionMaster()->MoveLand(POINT_GROUND, LandPosition);
                        break;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_shivermaw_AI(creature);
        }
};

class npc_vha_ice_block : public CreatureScript
{
    public:
        npc_vha_ice_block() : CreatureScript("npc_vha_ice_block")
        {}

        struct npc_vha_ice_block_AI : public ScriptedAI
        {
            npc_vha_ice_block_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddUnitState(UNIT_STATE_ROOT);
            }

            void SetGUID(ObjectGuid guid, int32 data) override
            {
                if (data == DATA_TRAPPED_PLAYER)
                    _targetGuid = guid;
            }

            void JustDied(Unit* /**/) override
            {
                if (Player* player = ObjectAccessor::GetPlayer(*me, _targetGuid))
                    player->RemoveAurasDueToSpell(SPELL_FROZEN);
            }

            private:
                ObjectGuid _targetGuid;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_vha_ice_block_AI(creature);
        }
};

class spell_shivermaw_ice_bomb : public SpellScriptLoader
{
    public:
        spell_shivermaw_ice_bomb() : SpellScriptLoader("spell_shivermaw_ice_bomb")
        {}

        class spell_ice_bomb_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_ice_bomb_SpellScript);

                void FilterTargets(SpellTargets & targets)
                {
                    if (targets.empty())
                        return;

                    targets.remove_if([] (WorldObject*& target)
                    {
                        if (target->GetPositionZ() > 78.5f)
                            return true;

                        return false;
                    });
                }

                void HandleOnHit(SpellEffIndex /**/)
                {
                    if (!GetCaster() || !GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_FROZEN, true);
                    GetHitUnit()->CastSpell(GetHitUnit(), SPELL_ICE_BOMB_SUMMON, true);

                    if (Creature* tomb = GetHitUnit()->FindNearestCreature(NPC_ICE_BLOCK, 10.f, true))
                        tomb->GetAI()->SetGUID(GetHitUnit()->GetGUID(), DATA_TRAPPED_PLAYER);
                }

                void Register() override
                {
                    OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_ice_bomb_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                    OnEffectHitTarget += SpellEffectFn(spell_ice_bomb_SpellScript::HandleOnHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_ice_bomb_SpellScript();
        }
};

class spell_shivermaw_relentless_storm : public SpellScriptLoader
{
    public:
        spell_shivermaw_relentless_storm() : SpellScriptLoader("spell_shivermaw_relentless_storm")
        {}

        class spell_shivermaw_relentless_storm_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_shivermaw_relentless_storm_SpellScript);

                void HandleScriptEffect(SpellEffIndex /**/)
                {
                    if (!GetCaster())
                        return;

                    Unit* caster = GetCaster();

                    caster->CastSpell(caster, SPELL_RELENTLESS_STORM_AR_1, true);
                    caster->CastSpell(caster, SPELL_RELENTLESS_STORM_AR_2, true);

                    for (uint8 i = 0; i < 25; ++i)
                    {
                        float angle = frand(0, 2 * float(M_PI));
                        float radius = frand(10, 40);
                        Position pos = caster->GetNearPosition(radius, angle);

                        for (auto & it : GetCaster()->GetMap()->GetPlayers())
                        {
                            if (Player* ptr = it.GetSource())
                            {
                                Position tgt_pos = { pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() };
                                ptr->SendPlayOrphanSpellVisual(tgt_pos, 52628, 3.f, true, false);
                            }
                        }

                        caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_RELENTLESS_STORM_MISSILE, false);
                    }
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_shivermaw_relentless_storm_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SEND_EVENT);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shivermaw_relentless_storm_SpellScript();
        }
};

class spell_shivermaw_relentless_storm_missile : public SpellScriptLoader
{
    public:
        spell_shivermaw_relentless_storm_missile() : SpellScriptLoader("spell_shivermaw_relentless_storm_missile")
        {}

        class spell_shivermaw_relentless_storm_dmg_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_shivermaw_relentless_storm_dmg_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitDest() || !GetCaster())
                        return;

                    Unit* caster = GetCaster();
                    WorldLocation pos = *GetHitDest();

                    caster->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_RELENTLESS_STORM_DMG, true);

                    for (auto & it : GetCaster()->GetMap()->GetPlayers())
                    {
                        if (Player* ptr = it.GetSource())
                        {
                            Position tgt_pos = { pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() };
                            ptr->SendPlayOrphanSpellVisual(tgt_pos, 52630, 1.f, true, true);
                        }
                    }
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_shivermaw_relentless_storm_dmg_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_shivermaw_relentless_storm_dmg_SpellScript();
        }
};

class at_vha_relentless_storm : public AreaTriggerEntityScript
{
    public:
        at_vha_relentless_storm() : AreaTriggerEntityScript("at_vha_relentless_storm")
        {}

        struct at_vha_relentless_storm_AI : public AreaTriggerAI
        {
            at_vha_relentless_storm_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {}

            void OnUnitEnter(Unit* unit) override
            {
                if (!unit)
                    return;

                if (unit->GetTypeId() == TYPEID_PLAYER)
                    unit->CastSpell(unit, SPELL_FROSTBITE, true);
            }

            void OnUnitExit(Unit* unit) override
            {
                if (!unit)
                    return;

                if (unit->GetTypeId() == TYPEID_PLAYER)
                    unit->RemoveAurasDueToSpell(SPELL_FROSTBITE);
            }
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_vha_relentless_storm_AI(at);
        }
};

void AddSC_boss_shivermaw()
{
    new boss_shivermaw();
    new npc_vha_ice_block();
    new at_vha_relentless_storm();
    new spell_shivermaw_ice_bomb();
    new spell_shivermaw_relentless_storm();
    new spell_shivermaw_relentless_storm_missile();
}
