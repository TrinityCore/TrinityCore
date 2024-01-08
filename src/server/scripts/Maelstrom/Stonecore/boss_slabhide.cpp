/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "stonecore.h"

enum Spells
{
    SPELL_FACE_RANDOM_PLAYER      = 82530,

    // Stalactite Trigger - Trash, On Ground
    SPELL_STALACTITE_SUMMON_TRIGGER = 81028,

    // Slabhide
    SPELL_LAVA_FISSURE            = 80803,
    SPELL_SAND_BLAST              = 80807,
    SPELL_STALACTITE_SUMMON       = 80656,
//  SPELL_COOLDOWN_5S             = 95323, Cooldown: Creature Special 1 (5s)?
    SPELL_CRYSTAL_STORM           = 92305,
    SPELL_CRYSTAL_STORM_TRIGGER   = 92265,

    // Lava Fissure
    SPELL_LAVA_FISSURE_CRACK      = 80798,
    SPELL_LAVA_FISSURE_ERUPTION   = 80800,

    // Stalactite Trigger - Boss
    SPELL_STALACTITE_SHADE        = 80654,
    SPELL_STALACTITE_MISSLE       = 80643,
    SPELL_STALACTITE_CREATE       = 80647,
};

enum Entries
{
    NPC_LAVA_FISSURE              = 43242,
    NPC_STALACTITE_TRIGGER_GROUND = 43357,
    NPC_STALACTITE_TRIGGER        = 43159,
    GO_STALACTITE                 = 204337,
};

enum Actions
{
    ACTION_STALACTITE_MISSLE,
};

enum Events
{
    EVENT_NONE,

    // Intro events
    EVENT_ROAR_EMOTE,

    // Slabhide combat
    EVENT_HANDLE_ROCK_WALLS,
    EVENT_LAVA_FISSURE,
    EVENT_SAND_BLAST,
    EVENT_AIR_PHASE,
    EVENT_TAKEOFF,
    EVENT_STALACTITE,
    EVENT_LAND,
    EVENT_ATTACK,

    // Lava Fissure
    EVENT_LAVA_FISSURE_ERUPTION,

    // Stalactite Trigger - Boss
    EVENT_STALACTITE_MISSLE,
};

enum MovementPoints
{
    POINT_NONE,

    POINT_SLABHIDE_INTRO,
    POINT_SLABHIDE_INTRO_LAND,

    POINT_SLABHIDE_MIDDLE,
    POINT_SLABHIDE_IN_AIR,
    POINT_SLABHIDE_LAND,
};

Position const SlabhideIntroPos = { 1292.27f, 1226.16f, 265.573f };
Position const SlabhideIntroLandPos = { 1292.352f, 1226.478f, 247.6368f, 3.630285f };

Position const SlabhideMiddlePos = { 1280.73f, 1212.31f, 247.3837f };
Position const SlabhideInAirPos = { 1280.73f, 1212.31f, 257.3837f };
Position const SlabhideLandPos = { 1282.7f, 1229.77f, 247.155f, 3.82227f };

class boss_slabhide : public CreatureScript
{
    public:
        boss_slabhide() : CreatureScript("boss_slabhide") { }

        struct boss_slabhideAI : public BossAI
        {
            boss_slabhideAI(Creature* creature) : BossAI(creature, DATA_SLABHIDE)
            {
                me->setActive(true);
                me->SetCanFly(true);
                me->SetDisableGravity(true);
                me->SetReactState(REACT_PASSIVE);
                instance->SetData(DATA_SLABHIDE_INTRO, NOT_STARTED);
                _isFlying = false;
            }

            void Reset() override
            {
                if (instance->GetData(DATA_SLABHIDE_INTRO) == NOT_STARTED)
                    return;

                _Reset();
                DespawnAll();

                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetReactState(REACT_AGGRESSIVE);
                _isFlying = false;
            }

            void JustEngagedWith(Unit* who) override
            {
                BossAI::JustEngagedWith(who);

                events.ScheduleEvent(EVENT_HANDLE_ROCK_WALLS, 4s);
                events.ScheduleEvent(EVENT_LAVA_FISSURE, 6s, 8s);
                events.ScheduleEvent(EVENT_SAND_BLAST, 8s, 10s);
                events.ScheduleEvent(EVENT_AIR_PHASE, 10s);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
            {
                if (_isFlying && damage >= me->GetHealth())
                    damage = me->GetHealth() - 1; // Let creature health fall to 1 hp but prevent it from dying during air phase.
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                // Despawn related npcs and gameobjects
                DespawnAll();
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_SLABHIDE_INTRO:
                    {
                        if (instance->GetData(DATA_SLABHIDE_INTRO) != NOT_STARTED)
                            return;

                        instance->SetData(DATA_SLABHIDE_INTRO, IN_PROGRESS);

                        // Execute Slabhide intro event
                        me->GetMotionMaster()->MovePoint(POINT_SLABHIDE_INTRO, SlabhideIntroPos);
                        break;
                    }
                    default:
                        break;
                }
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (id)
                {
                    case POINT_SLABHIDE_INTRO:
                        me->SetFacingTo(SlabhideIntroLandPos.GetOrientation());
                        me->GetMotionMaster()->MoveLand(POINT_SLABHIDE_INTRO_LAND, SlabhideIntroLandPos);
                        break;
                    case POINT_SLABHIDE_INTRO_LAND:
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->SetHover(false);
                        me->SetHomePosition(SlabhideIntroLandPos);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                        me->SetUninteractible(false);
                        me->SetReactState(REACT_AGGRESSIVE);
                        instance->SetData(DATA_SLABHIDE_INTRO, DONE);
                        break;
                    case POINT_SLABHIDE_MIDDLE:
                        _isFlying = true;
                        events.ScheduleEvent(EVENT_TAKEOFF, 100ms);
                        break;
                    case POINT_SLABHIDE_IN_AIR:
                        events.ScheduleEvent(EVENT_STALACTITE, 400ms);
                        break;
                    case POINT_SLABHIDE_LAND:
                        _isFlying = false;
                        //DoCast(me, SPELL_COOLDOWN_5S); // unknown purpose
                        events.ScheduleEvent(EVENT_ATTACK, 1200ms);
                        break;
                    default:
                        break;
                }
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
                        case EVENT_HANDLE_ROCK_WALLS: // Close rock walls
                            instance->SetData(DATA_SLABHIDE_ROCK_WALL, false);
                            break;
                        case EVENT_LAVA_FISSURE:
                            if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                                DoCast(target, SPELL_LAVA_FISSURE);
                            events.ScheduleEvent(EVENT_LAVA_FISSURE, 6s, 8s);
                            break;
                        case EVENT_SAND_BLAST:
                            DoCast(me, SPELL_SAND_BLAST);
                            events.ScheduleEvent(EVENT_SAND_BLAST, 8s, 11s);
                            break;
                        case EVENT_AIR_PHASE:
                            events.Reset();
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->GetMotionMaster()->MovePoint(POINT_SLABHIDE_MIDDLE, SlabhideMiddlePos);
                            events.ScheduleEvent(EVENT_AIR_PHASE, 1min);
                            break;
                        case EVENT_TAKEOFF:
                            me->GetMotionMaster()->MoveTakeoff(POINT_SLABHIDE_IN_AIR, SlabhideInAirPos);
                            break;
                        case EVENT_STALACTITE:
                            me->SetCanFly(true);
                            me->SetDisableGravity(true);
                            me->SetHover(true);

                            DoCast(me, SPELL_STALACTITE_SUMMON);

                            events.ScheduleEvent(EVENT_LAND, 8s);
                            break;
                        case EVENT_LAND:
                        {
                            Position pos = me->GetPosition();
                            me->UpdateGroundPositionZ(pos.GetPositionX(), pos.GetPositionY(), pos.m_positionZ);
                            me->GetMotionMaster()->MoveLand(POINT_SLABHIDE_LAND, pos);
                            break;
                        }
                        case EVENT_ATTACK:
                            me->SetCanFly(false);
                            me->SetDisableGravity(false);
                            me->SetHover(false);

                            events.ScheduleEvent(EVENT_LAVA_FISSURE, 6s, 8s);
                            events.ScheduleEvent(EVENT_SAND_BLAST, 8s, 10s);
                            DoCast(me, SPELL_CRYSTAL_STORM);
                            me->SetReactState(REACT_AGGRESSIVE);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            void DespawnAll()
            {
                // Despawn stalactite triggers npcs
                std::list<Creature*> listStalactiteTrigger;
                me->GetCreatureListWithEntryInGrid(listStalactiteTrigger, NPC_STALACTITE_TRIGGER, 200.0f);
                if (!listStalactiteTrigger.empty())
                    for (std::list<Creature*>::const_iterator itr = listStalactiteTrigger.begin(); itr != listStalactiteTrigger.end(); ++itr)
                        (*itr)->DespawnOrUnsummon();

                // Despawn stalactite objects
                std::list<GameObject*> listStalactite;
                me->GetGameObjectListWithEntryInGrid(listStalactite, GO_STALACTITE, 200.0f);
                if (!listStalactite.empty())
                    for (std::list<GameObject*>::const_iterator itr = listStalactite.begin(); itr != listStalactite.end(); ++itr)
                        (*itr)->Delete();
            }

            bool _isFlying;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<boss_slabhideAI>(creature);
        }
};

// 43242 - Lava Fissure
class npc_lava_fissure : public CreatureScript
{
public:
    npc_lava_fissure() : CreatureScript("npc_lava_fissure") { }

    struct npc_lava_fissureAI : public ScriptedAI
    {
        npc_lava_fissureAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, SPELL_LAVA_FISSURE_CRACK, true);
            events.ScheduleEvent(EVENT_LAVA_FISSURE_ERUPTION, 6s);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_LAVA_FISSURE_ERUPTION:
                        me->RemoveAurasDueToSpell(SPELL_LAVA_FISSURE_CRACK);
                        DoCast(me, SPELL_LAVA_FISSURE_ERUPTION, true);
                        me->DespawnOrUnsummon(14s);
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
        return GetStonecoreAI<npc_lava_fissureAI>(creature);
    }
};

// 43159 - Stalactite Trigger - Boss
class npc_stalactite_trigger : public CreatureScript
{
public:
    npc_stalactite_trigger() : CreatureScript("npc_stalactite_trigger") { }

    struct npc_stalactite_triggerAI : public ScriptedAI
    {
        npc_stalactite_triggerAI(Creature* creature) : ScriptedAI(creature)
        {
            me->SetDisableGravity(true);
            DoCast(me, SPELL_STALACTITE_SHADE, true);
            events.ScheduleEvent(EVENT_STALACTITE_MISSLE, 5600ms);
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
                    case EVENT_STALACTITE_MISSLE:
                        DoCast(me, SPELL_STALACTITE_MISSLE);
                        me->DespawnOrUnsummon(11s);
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
        return GetStonecoreAI<npc_stalactite_triggerAI>(creature);
    }
};

// 81035 - Stalactite (check if player is near to summon stalactite)
class spell_s81035_stalactite : public SpellScriptLoader
{
public:
    spell_s81035_stalactite() : SpellScriptLoader("spell_s81035_stalactite") { }

    class spell_s81035_stalactite_SpellScript : public SpellScript
    {
        void SummonStalactiteTrigger()
        {
            Unit* caster = GetCaster();
            caster->CastSpell(caster, SPELL_STALACTITE_SUMMON_TRIGGER, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_s81035_stalactite_SpellScript::SummonStalactiteTrigger);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_s81035_stalactite_SpellScript();
    }
};

// 81028 - Stalactite (summons "Stalactite Trigger - Boss", 20 yard radius)
// 80650 - Stalactite (summons "Stalactite Trigger - Boss", 40 yard radius)
class spell_s81028_s80650_stalactite : public SpellScriptLoader
{
public:
    spell_s81028_s80650_stalactite() : SpellScriptLoader("spell_s81028_s80650_stalactite") { }

    class spell_s81028_s80650_stalactite_SpellScript : public SpellScript
    {
        void ModDestHeight(SpellDestination& dest)
        {
            // All stalactite triggers should have Z position 301.3837f, but no way to relocate (not relocateoffset!) height only.
            Position offset = { 0.0f, 0.0f, 50.0f, 0.0f };
            dest.RelocateOffset(offset);
        }

        void Register() override
        {
            OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_s81028_s80650_stalactite_SpellScript::ModDestHeight, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_s81028_s80650_stalactite_SpellScript();
    }
};

// 80654       - Stalactite (creates visual shade on ground)
// 80643/92653 - Stalactite (launches missle to the ground)
// 80647/92309 - Stalactite (creates stalactite object)
class spell_stalactite_mod_dest_height : public SpellScriptLoader
{
public:
    spell_stalactite_mod_dest_height() : SpellScriptLoader("spell_stalactite_mod_dest_height") { }

    class spell_stalactite_mod_dest_height_SpellScript : public SpellScript
    {
        void ModDestHeight(SpellDestination& dest)
        {
            Unit* caster = GetCaster();
            Position pos = caster->GetPosition();
            pos.m_positionZ = caster->GetMap()->GetHeight(caster->GetPhaseShift(), pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), true, 100.0f);
            dest.Relocate(pos);
        }

        void Register() override
        {
            OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_stalactite_mod_dest_height_SpellScript::ModDestHeight, EFFECT_0, TARGET_DEST_CASTER);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_stalactite_mod_dest_height_SpellScript();
    }
};

// 92306 - Crystal storm (heroic mode check)
class spell_s92306_crystal_storm : public SpellScriptLoader
{
public:
    spell_s92306_crystal_storm() : SpellScriptLoader("spell_s92306_crystal_storm") { }

    class spell_s92306_crystal_storm_SpellScript : public SpellScript
    {
        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_CRYSTAL_STORM_TRIGGER });
        }

        void HandleDummyEffect(SpellEffIndex /*eff*/)
        {
            Unit* caster = GetCaster();
            if (caster->GetMap()->IsHeroic())
                caster->CastSpell(caster, SPELL_CRYSTAL_STORM_TRIGGER, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_s92306_crystal_storm_SpellScript::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_s92306_crystal_storm_SpellScript();
    }
};

// 92300 - Crystal Storm (damage)
class BehindObjectCheck
{
    public:
        BehindObjectCheck(Unit* caster, std::list<GameObject*> objectList) : caster(caster), objectList(objectList) { }

        bool operator()(WorldObject* unit)
        {
            for (std::list<GameObject*>::const_iterator itr = objectList.begin(); itr != objectList.end(); ++itr)
                if (!(*itr)->IsInvisibleDueToDespawn(unit) && (*itr)->IsInBetween(caster, unit, 1.5f))
                    return true;
            return false;
        }

    private:
        Unit* caster;
        std::list<GameObject*> objectList;
};

class spell_s92300_crystal_storm : public SpellScriptLoader
{
public:
    spell_s92300_crystal_storm() : SpellScriptLoader("spell_s92300_crystal_storm") { }

    class spell_s92300_crystal_storm_SpellScript : public SpellScript
    {
        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            Unit* caster = GetCaster();

            std::list<GameObject*> goList;
            caster->GetGameObjectListWithEntryInGrid(goList, GO_STALACTITE, 40.0f);
            if (goList.empty())
                return;

            unitList.remove_if(BehindObjectCheck(caster, goList));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_s92300_crystal_storm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_s92300_crystal_storm_SpellScript();
    }
};

void AddSC_boss_slabhide()
{
    new boss_slabhide();
    new npc_lava_fissure();
    new npc_stalactite_trigger();
    new spell_s81035_stalactite();
    new spell_s81028_s80650_stalactite();
    new spell_stalactite_mod_dest_height();
    new spell_s92306_crystal_storm();
    new spell_s92300_crystal_storm();
}
