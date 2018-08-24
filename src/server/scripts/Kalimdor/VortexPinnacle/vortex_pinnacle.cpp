/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "vortex_pinnacle.h"

enum Texts
{
    SAY_FEIGN_DEATH = 0,
};

enum Spells
{
    // Lurking Tempest
    SPELL_LIGHTNING_BOLT                            = 89105,
    SPELL_LURK                                      = 85467, // dummy aura while not playing dead
    SPELL_LURK_SEARCH                               = 85294, // periodically triggers either SPELL_LURK_CHECK or SPELL_FEIGN_DEATH_CHECK
    SPELL_LURK_CHECK                                = 85291,
    SPELL_FEIGN_DEATH                               = 85267,
    SPELL_FEIGN_DEATH_CHECK                         = 86493,
    SPELL_LURK_RESSURECT                            = 85281, // 1250 ms duration, on remove SPELL_LURK (85467) is cast
    SPELL_LURK_FIND_VICTIM                          = 86456,

    // Young Storm Dragon
    SPELL_HEALING_WELL                              = 88201,
    SPELL_CHILLING_BLAST                            = 88194,

    // Howling Gale
    SPELL_HOWLING_GALE_VISUAL                       = 85086,
    SPELL_HOWLING_GALE_KNOCKBACK                    = 85159,
    SPELL_HOWLING_GALE_VISUAL_2                     = 85137,
    SPELL_HOWLING_GALE_KNOCKBACK_2                  = 85085,

    // Slipstream (spells Slipstream npcs cast on passenger to make it enter next Slipstream)
    SPELL_SLIPSTREAM_SPELLCLICK                     = 84965, // spellclick
    SPELL_SLIPSTREAM_FIRST                          = 84980, // Cast on passenger by Slipstream 1 and 4.
    SPELL_SLIPSTREAM_FIRST_CONTROL_VEHICLE_AURA     = 84978, // Triggered by SPELL_SLIPSTREAM_FIRST. Targets closest NPC_SLIPSTREAM.
    SPELL_SLIPSTREAM_SECOND                         = 84988, // Cast on passenger by Slipstream 2 and 5.
    SPELL_SLIPSTREAM_SECOND_CONTROL_VEHICLE_AURA    = 84989, // Triggered by SPELL_SLIPSTREAM_SECOND.  Targets second closest NPC_SLIPSTREAM.
    SPELL_SLIPSTREAM_THIRD                          = 85394, // Cast on passenger by Slipstream 6.
    SPELL_SLIPSTREAM_THIRD_CONTROL_VEHICLE_AURA     = 85395, // Triggered by SPELL_SLIPSTREAM_THIRD.  Unknown how it targets next NPC_SLIPSTREAM.
    SPELL_SLIPSTREAM_FOURTH                         = 85397, // Cast on passenger by Slipstream 7.
    SPELL_SLIPSTREAM_FOURTH_CONTROL_VEHICLE_AURA    = 85396, // Triggered by SPELL_SLIPSTREAM_FORTH. Unknown how it targets next NPC_SLIPSTREAM.
    SPELL_SLIPSTREAM_LAST                           = 85016, // Cast on passenger by Slipstream 3 and 8.
    SPELL_SLIPSTREAM_LAST_CONTROL_VEHICLE_AURA      = 85017, // Triggered by SPELL_SLIPSTREAM_LAST. Targets NPC_SLIPSTREAM_LANDING_ZONE.

    // No one sniffed using Slipstreams at entrance, I guess they take you to Slipstream Landing Zone directly, but need spell IDs.
    // Possible spell IDs named 'Slipstream': 87742 Jet Stream??, 89498, 89500, 95911
    //  SPELL_SLIPSTREAM_LEFT = 0,
    //  SPELL_SLIPSTREAM_RIGHT = 0,

    // Slipstream Landing Zone
    SPELL_GENERIC_EJECT_ALL_PASSENGERS              = 79737, // Generic Eject All Passengers - Always Allow

    // Grounding Field
    SPELL_PRISM_BEAMS                               = 87724,
    SPELL_GROUNDING_FIELD                           = 87725,

    // Skyfall npc
    SPELL_SKYFALL_VISUAL                            = 85719,
    SPELL_SKYFALL                                   = 87850,

    // Skyfall Star npc
    SPELL_ARCANE_BARRAGE                            = 87845,
};

enum NPCs
{
    NPC_SKYFALL                                     = 45981,
    NPC_SKYFALL_STAR                                = 52019,
};

enum Events
{
    EVENT_NONE,

    // Young Storm Dragon
    EVENT_TAKEOFF,
    EVENT_ATTACK,
    EVENT_HEALING_WELL,
    EVENT_CHILLING_BLAST,

    // Grounding Field
    EVENT_CAST_PRISM_BEAMS,

    // Skyfall Star
    EVENT_FLY_RANDOM,

    // Slipstream Landing Zone
    EVENT_EJECT_ALL_PASSENGERS
};

enum Points
{
    POINT_NONE,

    POINT_RANDOM,
};

// TO-DO:
// - Grounding Field npc (47085) is broken somewhere, it won't load script assigned in DB. They are summoned in
//       SummonGroundingFieldPrism() void (instance_vortex_pinnacle.cpp), same like Slipstream which acts just fine.

// 45704 - Lurking Tempest
class npc_lurking_tempest : public CreatureScript
{
public:
    npc_lurking_tempest() : CreatureScript("npc_lurking_tempest") { }

    struct npc_lurking_tempestAI : public ScriptedAI
    {
        npc_lurking_tempestAI(Creature* creature) : ScriptedAI(creature)
        {
            ertan = false;
            SetCombatMovement(false);
        }

        void Reset() override
        {
            // Should have, but gets stuck in evade mode...
            //me->AddUnitState(UNIT_STATE_ROOT);
            DoCast(me, SPELL_LURK);
        }

        void IsSummonedBy(Unit* summoner) override
        {
            if (Creature* creature = summoner->ToCreature())
                ertan = (creature->GetEntry() == NPC_GRAND_VIZIER_ERTAN);
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (!me->IsInCombat() && me->IsWithinDist(who, ertan ? 100.0f : 45.0f) && me->IsValidAttackTarget(who))
                AttackStart(who);
        }

        void JustEngagedWith(Unit* /*target*/) override
        {
            DoCast(me, SPELL_LURK_SEARCH);
        }

        void SpellHit(Unit* /*unit*/, SpellInfo const* spellInfo) override
        {
            if (spellInfo->Id == SPELL_FEIGN_DEATH)
                Talk(SAY_FEIGN_DEATH);
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!me->HasAura(SPELL_LURK) || !UpdateVictim())
                return;

            // Just stop combat when target is far away.
            if (!ertan && !me->IsWithinDistInMap(me->GetVictim(), 45.0f))
            {
                me->DeleteThreatList();
                me->CombatStop(true);
                return;
            }

            DoSpellAttackIfReady(SPELL_LIGHTNING_BOLT);
        }

    private:
        bool ertan; // Is it summoned by Grand Vizier Ertan?
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<npc_lurking_tempestAI>(creature);
    }
};

// 45455 - Slipstream
class npc_slipstream : public CreatureScript
{
public:
    npc_slipstream() : CreatureScript("npc_slipstream") { }

    struct npc_slipstreamAI : public ScriptedAI
    {
        npc_slipstreamAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            me->SetExtraUnitMovementFlags(MOVEMENTFLAG2_NO_STRAFE | MOVEMENTFLAG2_NO_JUMPING);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (!apply)
                return;

            if (me->HasAura(SPELL_SLIPSTREAM_SPELLCLICK))
            {
                DoCast(who, SPELL_SLIPSTREAM_FIRST, true);
                who->SetDisableGravity(true, true);
            }
            else if (me->HasAura(SPELL_SLIPSTREAM_FIRST_CONTROL_VEHICLE_AURA))
                DoCast(who, SPELL_SLIPSTREAM_SECOND, true);
            else if (me->HasAura(SPELL_SLIPSTREAM_SECOND_CONTROL_VEHICLE_AURA))
            {
                if (InstanceScript* instance = me->GetInstanceScript())
                {
                    if (instance->GetCreature(DATA_SLIPSTREAM_3) == me)
                        DoCast(who, SPELL_SLIPSTREAM_LAST, true);
                    else
                        DoCast(who, SPELL_SLIPSTREAM_THIRD, true);
                }
            }
            else if (me->HasAura(SPELL_SLIPSTREAM_THIRD_CONTROL_VEHICLE_AURA))
                DoCast(who, SPELL_SLIPSTREAM_FOURTH, true);
            else if (me->HasAura(SPELL_SLIPSTREAM_FOURTH_CONTROL_VEHICLE_AURA))
                DoCast(who, SPELL_SLIPSTREAM_LAST, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<npc_slipstreamAI>(creature);
    }
};

// 45504 - Slipstream Landing Zone (can be converted to SAI later, whatever masters say)
class npc_slipstream_landing_zone : public CreatureScript
{
public:
    npc_slipstream_landing_zone() : CreatureScript("npc_slipstream_landing_zone") { }

    struct npc_slipstream_landing_zoneAI : public ScriptedAI
    {
        npc_slipstream_landing_zoneAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            me->SetExtraUnitMovementFlags(MOVEMENTFLAG2_NO_STRAFE | MOVEMENTFLAG2_NO_JUMPING);
        }

        void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) override
        {
            if (!who)
                return;

            if (apply)
            {
                who->SetDisableGravity(true, true);
                _events.ScheduleEvent(EVENT_EJECT_ALL_PASSENGERS, 1s + 500ms);
            }
            else
                who->SetDisableGravity(false, true);
        }

        void UpdateAI(uint32 diff) override
        {
            _events.Update(diff);

            while (uint32 eventId = _events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EJECT_ALL_PASSENGERS:
                        DoCast(me, SPELL_GENERIC_EJECT_ALL_PASSENGERS);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<npc_slipstream_landing_zoneAI>(creature);
    }
};

// 45919 - Young Storm Dragon
class npc_young_storm_dragon : public CreatureScript
{
public:
    npc_young_storm_dragon() : CreatureScript("npc_young_storm_dragon") { }

    struct npc_young_storm_dragonAI : public ScriptedAI
    {
        npc_young_storm_dragonAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetCanFly(false);
            me->SetDisableGravity(false);
            me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);

            events.Reset();
            events.ScheduleEvent(EVENT_HEALING_WELL, 1);
            events.ScheduleEvent(EVENT_TAKEOFF, 3000);
            events.ScheduleEvent(EVENT_ATTACK, 6000);
        }

        void JustEngagedWith(Unit* /*target*/) override
        {
            me->SetReactState(REACT_PASSIVE);

            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->Clear(true);
            me->StopMoving();
            //me->GetMotionMaster()->MoveIdle();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_TAKEOFF:
                    {
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        Position pos = me->GetPosition();
                        pos.m_positionZ += 10.0f;
                        me->GetMotionMaster()->MoveTakeoff(0, pos);
                        break;
                    }
                    case EVENT_ATTACK:
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.RescheduleEvent(EVENT_CHILLING_BLAST, 14000);
                        events.RescheduleEvent(EVENT_HEALING_WELL, 15000);
                        break;
                    case EVENT_CHILLING_BLAST:
                        DoCastVictim(SPELL_CHILLING_BLAST);
                        events.ScheduleEvent(EVENT_CHILLING_BLAST, 14000);
                        break;
                    case EVENT_HEALING_WELL:
                        DoCast(me, SPELL_HEALING_WELL);
                        events.ScheduleEvent(EVENT_HEALING_WELL, 15000);
                        break;
                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<npc_young_storm_dragonAI>(creature);
    }
};

// 47085 - Grounding Field
class npc_grounding_field : public CreatureScript
{
public:
    npc_grounding_field() : CreatureScript("npc_grounding_field") { }

    struct npc_grounding_fieldAI : public ScriptedAI
    {
        npc_grounding_fieldAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
        }

        void DoAction(int32 action) override
        {
            if (action != ACTION_GROUNDING_FIELD_TOP)
                return;

            DoCast(me, SPELL_GROUNDING_FIELD);
            events.ScheduleEvent(EVENT_CAST_PRISM_BEAMS, 5000);
        }

        void UpdateAI(uint32 diff) override
        {
            if (events.Empty())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CAST_PRISM_BEAMS:
                        me->CastStop();
                        DoCast(me, SPELL_PRISM_BEAMS);
                        events.ScheduleEvent(EVENT_CAST_PRISM_BEAMS, 5000);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<npc_grounding_fieldAI>(creature);
    }
};

// 45981 - Skyfall
// TO-DO: Script despawn.
class npc_skyfall : public CreatureScript
{
public:
    npc_skyfall() : CreatureScript("npc_skyfall") { }

    struct npc_skyfallAI : public ScriptedAI
    {
        npc_skyfallAI(Creature* creature) : ScriptedAI(creature)
        {
            Initialize();
        }

        void Initialize()
        {
            _deadStarsCounter = 0;
            me->SetDisableGravity(true);
        }

        void Reset() override
        {
            me->AddUnitState(UNIT_STATE_ROOT);
            me->SetReactState(REACT_AGGRESSIVE);
            DoCast(me, SPELL_SKYFALL_VISUAL);
        }

        void JustEngagedWith(Unit* /*target*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            DoCast(me, SPELL_SKYFALL);
        }

        void DoAction(int32 action) override
        {
            if (action == ACTION_SKYFALL_STAR_DEAD)
            {
                _deadStarsCounter++;
                if (_deadStarsCounter == 8)
                    me->DespawnOrUnsummon();
            }
        }

        void UpdateAI(uint32 /*diff*/) override
        {
        }

        uint8 _deadStarsCounter;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<npc_skyfallAI>(creature);
    }
};

// 45932 - Skyfall Star
class npc_skyfall_star : public CreatureScript
{
public:
    npc_skyfall_star() : CreatureScript("npc_skyfall_star") { }

    struct npc_skyfall_starAI : public CreatureAI
    {
        npc_skyfall_starAI(Creature* creature) : CreatureAI(creature)
        {
            me->SetDisableGravity(true);
        }

        void Reset() override
        {
            me->SetReactState(REACT_AGGRESSIVE);
        }

        void JustEngagedWith(Unit* /*target*/) override
        {
            me->SetReactState(REACT_PASSIVE);
            DoCast(me, SPELL_ARCANE_BARRAGE);
            events.ScheduleEvent(EVENT_FLY_RANDOM, 0);
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (Creature* skyfall = me->FindNearestCreature(NPC_SKYFALL, 100.0f, true))
                skyfall->AI()->DoAction(ACTION_SKYFALL_STAR_DEAD);
            me->DespawnOrUnsummon();
        }

        void MovementInform(uint32 movementType, uint32 pointId) override
        {
            if (movementType == POINT_MOTION_TYPE || pointId == POINT_RANDOM)
                events.ScheduleEvent(EVENT_FLY_RANDOM, 1000);
        };

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || events.Empty())
                return;

            events.Update(diff);

            uint32 eventId = events.ExecuteEvent();
            if (!eventId || eventId != EVENT_FLY_RANDOM)
                return;

            // Fly to random near position.
            Position pos = me->GetRandomNearPosition(10.0f);
            pos.m_positionZ += frand(4.0f, 6.0f);
            me->GetMotionMaster()->MovePoint(POINT_RANDOM, pos);
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetVortexPinnacleAI<npc_skyfall_starAI>(creature);
    }
};

// 85294 - Lurk Search
class spell_lurk_search : public SpellScriptLoader
{
public:
    spell_lurk_search() : SpellScriptLoader("spell_lurk_search") { }

    class spell_lurk_search_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_lurk_search_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_LURK_CHECK, SPELL_FEIGN_DEATH_CHECK });
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Creature* owner = GetOwner()->ToCreature();
            if (!owner)
                return;

            if (owner->HasAura(SPELL_LURK))
            {
                if (owner->IsInCombat())
                    owner->CastSpell(owner, SPELL_LURK_CHECK, true);
            }
            else if (owner->HasAura(SPELL_FEIGN_DEATH))
                owner->CastSpell(owner, SPELL_FEIGN_DEATH_CHECK, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_lurk_search_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_lurk_search_AuraScript();
    }
};

// 85291 - Lurk Search (triggers Feign Death)
// 86493 - Lurk Search (triggers Lurk Ressurect)
class PlayerOrPetOrientationCheck
{
public:
    PlayerOrPetOrientationCheck(Unit* caster) : caster(caster) { }

    bool operator()(WorldObject* object)
    {
        return (!object->ToUnit()->IsCharmedOwnedByPlayerOrPlayer() || !object->isInFront(caster, 2.5f));
    }

private:
    Unit* caster;
};

class spell_lurk_search_check : public SpellScriptLoader
{
public:
    spell_lurk_search_check() : SpellScriptLoader("spell_lurk_search_check") { }

    class spell_lurk_search_check_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_lurk_search_check_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_FEIGN_DEATH, SPELL_LURK_RESSURECT });
        }

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            unitList.remove_if(PlayerOrPetOrientationCheck(GetCaster()));
            countFacingUnits = unitList.size();
        }

        void OnLaunch(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            switch (GetSpellInfo()->Id)
            {
                case SPELL_LURK_CHECK:
                    if (countFacingUnits && !caster->HasAura(SPELL_FEIGN_DEATH))
                        caster->CastSpell(caster, SPELL_FEIGN_DEATH, true);
                    break;
                case SPELL_FEIGN_DEATH_CHECK:
                    if (!countFacingUnits)
                        caster->CastSpell(caster, SPELL_LURK_RESSURECT, true);
                    break;
                default:
                    break;
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_lurk_search_check_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectLaunch += SpellEffectFn(spell_lurk_search_check_SpellScript::OnLaunch, EFFECT_0, SPELL_EFFECT_DUMMY);
        }

        uint32 countFacingUnits = 0;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_lurk_search_check_SpellScript();
    }
};

// 85267 - Feign Death
class spell_feign_death : public SpellScriptLoader
{
public:
    spell_feign_death() : SpellScriptLoader("spell_feign_death") { }

    class spell_feign_death_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_feign_death_SpellScript);

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            Creature* creature = GetHitUnit()->ToCreature();
            if (!creature)
                return;

            creature->RemoveAurasDueToSpell(SPELL_LURK);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_feign_death_SpellScript::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_feign_death_SpellScript();
    }
};

// 85281 - Lurk Ressurect
class spell_lurk_ressurect : public SpellScriptLoader
{
public:
    spell_lurk_ressurect() : SpellScriptLoader("spell_lurk_ressurect") { }

    class spell_lurk_ressurect_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_lurk_ressurect_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_LURK, SPELL_LURK_SEARCH });
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Creature* owner = GetOwner()->ToCreature();
            if (!owner)
                return;

            owner->RemoveAurasDueToSpell(SPELL_FEIGN_DEATH);
            owner->RemoveAurasDueToSpell(SPELL_LURK_SEARCH);

            owner->DeleteThreatList();
            owner->CombatStop(true);

            owner->CastSpell(owner, SPELL_LURK_FIND_VICTIM, true);
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Creature* owner = GetOwner()->ToCreature())
                owner->CastSpell(owner, SPELL_LURK, true);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_lurk_ressurect_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_lurk_ressurect_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_lurk_ressurect_AuraScript();
    }
};

// 86456 - Lurk Search
class spell_lurk_search_victim : public SpellScriptLoader
{
public:
    spell_lurk_search_victim() : SpellScriptLoader("spell_lurk_search_victim") { }

    class spell_lurk_search_victim_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_lurk_search_victim_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->AddThreat(GetHitUnit(), 0.0f);
            GetCaster()->SetInCombatWith(GetHitUnit());
            GetHitUnit()->SetInCombatWith(GetCaster());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_lurk_search_victim_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_lurk_search_victim_SpellScript();
    }
};

// 84978, 84989, 85395, 85396, 85017 - Slipstream
// TO-DO: Fix passenger entering vehicle from another vehicle, passenger's vehicle enters vehicle instead... need core fix or we must handle it in this spellscript?
class spell_slipstream : public SpellScriptLoader
{
public:
    spell_slipstream() : SpellScriptLoader("spell_slipstream") { }

    class spell_slipstream_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_slipstream_SpellScript);

        void SetTarget(WorldObject*& target)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            Creature* slipstream = GetCaster()->GetVehicleCreatureBase();
            if (!slipstream)
                return;

            switch (GetSpellInfo()->Id)
            {
                case SPELL_SLIPSTREAM_FIRST_CONTROL_VEHICLE_AURA:
                    if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_1))
                        target = instance->GetCreature(DATA_SLIPSTREAM_2);
                    else if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_4))
                        target = instance->GetCreature(DATA_SLIPSTREAM_5);
                    break;
                case SPELL_SLIPSTREAM_SECOND_CONTROL_VEHICLE_AURA:
                    if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_2))
                        target = instance->GetCreature(DATA_SLIPSTREAM_3);
                    else if (slipstream->GetGUID() == instance->GetGuidData(DATA_SLIPSTREAM_5))
                        target = instance->GetCreature(DATA_SLIPSTREAM_6);
                    break;
                case SPELL_SLIPSTREAM_THIRD_CONTROL_VEHICLE_AURA:
                    target = instance->GetCreature(DATA_SLIPSTREAM_7);
                    break;
                case SPELL_SLIPSTREAM_FOURTH_CONTROL_VEHICLE_AURA:
                    target = instance->GetCreature(DATA_SLIPSTREAM_8);
                    break;
                case SPELL_SLIPSTREAM_LAST_CONTROL_VEHICLE_AURA:
                    if (Creature* landingZone = slipstream->FindNearestCreature(NPC_SLIPSTREAM_LANDING_ZONE, 100.0f))
                        target = landingZone;
                    break;
                default:
                    break;
            }
        }

        void Register() override
        {
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_slipstream_SpellScript::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_slipstream_SpellScript();
    }
};


// 85084 - Howling Gale
class spell_howling_gale : public SpellScriptLoader
{
public:
    spell_howling_gale() : SpellScriptLoader("spell_howling_gale") { }

    class spell_howling_gale_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_howling_gale_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
                {
                    SPELL_HOWLING_GALE_VISUAL,
                    SPELL_HOWLING_GALE_KNOCKBACK,
                    SPELL_HOWLING_GALE_VISUAL_2,
                    SPELL_HOWLING_GALE_KNOCKBACK_2
                });
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            PreventDefaultAction();

            tickCountdown = 20; // 10 seconds
            proced = true;
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            if (tickCountdown > 0)
                tickCountdown -= 1;
            else
            {
                Unit* caster = GetUnitOwner();
                if (!caster)
                    return;

                // After Howling Gale has been damaged, different spells are cast.
                caster->CastSpell(caster, !proced ? SPELL_HOWLING_GALE_VISUAL : SPELL_HOWLING_GALE_VISUAL_2);
                caster->CastSpell(caster, !proced ? SPELL_HOWLING_GALE_KNOCKBACK : SPELL_HOWLING_GALE_KNOCKBACK_2);
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_howling_gale_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_howling_gale_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }

        uint32 tickCountdown = 0;
        bool proced = false;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_howling_gale_AuraScript();
    }
};

// 87726 - Grounding Field
class spell_grounding_field : public SpellScriptLoader
{
public:
    spell_grounding_field() : SpellScriptLoader("spell_grounding_field") { }

    class spell_grounding_field_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_grounding_field_SpellScript);

        bool Load() override
        {
            prevent = false;
            return true;
        }

        void GetNearbyGroundFields()
        {
            std::list<Creature*> groundingFields;
            GetCaster()->GetCreatureListWithEntryInGrid(groundingFields, NPC_GROUNDING_FIELD, 60.0f);

            if (groundingFields.size() < 3)
                prevent = true;

            int count = 0;
            for (Creature* groundingField : groundingFields)
            {
                if (GetCaster()->GetGUID() == groundingField->GetGUID())
                    continue;

                GroundFieldPositions[count++] = groundingField->GetPosition();
                if (count == 3)
                    break;
            }
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            TriangleBoundary triangle(GroundFieldPositions[0], GroundFieldPositions[1], GroundFieldPositions[2], true);
            targets.remove_if([&](WorldObject* target)
            {
                return triangle.IsWithinBoundary(target);
            });
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_grounding_field_SpellScript::GetNearbyGroundFields);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_grounding_field_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }

    private:
        bool prevent;
        Position GroundFieldPositions[3];
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_grounding_field_SpellScript();
    }
};

// 87850 - Skyfall
class spell_skyfall : public SpellScriptLoader
{
public:
    spell_skyfall() : SpellScriptLoader("spell_skyfall") { }

    class spell_skyfall_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_skyfall_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Creature* creature = GetHitCreature())
                creature->CombatStart(GetCaster()->GetVictim());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_skyfall_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_skyfall_SpellScript();
    }
};

// 87854 - Arcane Barrage
class spell_arcane_barrage : public SpellScriptLoader
{
public:
    spell_arcane_barrage() : SpellScriptLoader("spell_arcane_barrage") { }

    class spell_arcane_barrage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_arcane_barrage_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 1);
        }

        void Register()
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arcane_barrage_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_arcane_barrage_SpellScript();
    }
};

void AddSC_vortex_pinnacle()
{
    new npc_lurking_tempest();
    new npc_slipstream();
    new npc_slipstream_landing_zone();
    new npc_young_storm_dragon();
    new npc_grounding_field();
    new npc_skyfall();
    new npc_skyfall_star();
    new spell_lurk_search();
    new spell_lurk_search_check();
    new spell_feign_death();
    new spell_lurk_ressurect();
    new spell_lurk_search_victim();
    new spell_slipstream();
    new spell_howling_gale();
    new spell_grounding_field();
    new spell_skyfall();
    new spell_arcane_barrage();
}
