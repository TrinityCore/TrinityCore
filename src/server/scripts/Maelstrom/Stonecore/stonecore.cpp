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
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"
#include "stonecore.h"

enum Texts
{
    // Millhouse Manastorm
    SAY_MILLHOUSE_EVENT_1           = 0,
    SAY_MILLHOUSE_EVENT_2           = 1
};

enum Spells
{
    // Millhouse Manastorm
    SPELL_SHADOW_BOLT                     = 81439,
    SPELL_FROSTBOLT_VOLLEY                = 81440,
    SPELL_SHADOWFURY                      = 81441,
    SPELL_FEAR                            = 81442,
//  SPELL_MILLHOUSE_SAFE_CHECK            = 81213, // unknown purpose
    SPELL_CLEAR_ALL_DEBUFFS               = 34098,
    SPELL_BLUR                            = 81216,
    SPELL_ANCHOR_HERE                     = 45313,
    SPELL_TIGULE_AND_FORORS_SPECIAL_BLEND = 81220,
    SPELL_IMPENDING_DOOM                  = 86838,
    SPELL_IMPENDING_DOOM_CHANNEL          = 86830,

//  SPELL_PORTAL_VISUAL                   = 79754,
};

enum Events
{
    // Millhouse Manastorm
    EVENT_FROSTBOLT_VOLLEY = 1,
    EVENT_SHADOWFURY,
    EVENT_FEAR,
    EVENT_SHADOW_BOLT,
    EVENT_CAST_IMPENDING_DOOM,
    EVENT_INTERRUPT_IMPENDING_DOOM,
    EVENT_RUN_AWAY
};

enum MovementPoints
{
    POINT_NONE,

    POINT_MILLHOUSE_GROUP_2,
    POINT_MILLHOUSE_GROUP_3,
    POINT_MILLHOUSE_GROUP_4,
};

// Millhouse trash groups
Position const MillhousePointGroup2 = { 977.3045f, 895.2347f, 306.3298f };
Position const MillhousePointGroup3 = { 1049.823f, 871.4349f, 295.006f };
Position const MillhousePointGroup4 = { 1149.04f, 884.431f, 284.9406f };

// 43391 - Millhouse Manastorm
class npc_sc_millhouse_manastorm : public CreatureScript
{
    public:
        npc_sc_millhouse_manastorm() : CreatureScript("npc_sc_millhouse_manastorm") { }

        struct npc_sc_millhouse_manastormAI : public ScriptedAI
        {
            npc_sc_millhouse_manastormAI(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
            {
                Initialize();
            }

            void Initialize()
            {
                _fleeCounter = 0;
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                events.Reset();
                events.ScheduleEvent(EVENT_SHADOWFURY, 3s);
                events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 5s);
                events.ScheduleEvent(EVENT_FEAR, 8s);
                events.ScheduleEvent(EVENT_SHADOW_BOLT, 1ms);
            }

            void AttackStart(Unit* who) override
            {
                if (me->HasAura(SPELL_TIGULE_AND_FORORS_SPECIAL_BLEND))
                    return;
                else
                    ScriptedAI::AttackStart(who);
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _EnterEvadeMode();
                me->GetMotionMaster()->MoveTargetedHome();

                if (_fleeCounter != 3)
                    DoCast(me, SPELL_TIGULE_AND_FORORS_SPECIAL_BLEND);
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (damage >= me->GetHealth())
                    damage = me->GetHealth() - 1;

                if (me->HealthBelowPctDamaged(50, damage))
                {
                    if (_fleeCounter > 3 || me->HasAura(SPELL_BLUR))
                        return;

                    events.Reset();
                    me->InterruptNonMeleeSpells(true);
                    me->AttackStop();
                    me->SetReactState(REACT_PASSIVE);
                    DoCast(me, SPELL_CLEAR_ALL_DEBUFFS);
                    DoCast(me, SPELL_BLUR);

                    if (_fleeCounter != 2)
                        Talk(SAY_MILLHOUSE_EVENT_1);

                    events.ScheduleEvent(EVENT_RUN_AWAY, 2s);
                    _fleeCounter++;
                }
            }

            void MovementInform(uint32 type, uint32 pointId) override
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                if (pointId < POINT_MILLHOUSE_GROUP_2 || pointId > POINT_MILLHOUSE_GROUP_4)
                    return;

                switch (pointId)
                {
                    case POINT_MILLHOUSE_GROUP_2:
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (Creature* worldtrigger = me->FindNearestCreature(NPC_WORLDTRIGGER, 200.0f))
                            me->SetFacingToObject(worldtrigger);
                        DoCast(me, SPELL_ANCHOR_HERE);
                        break;
                    case POINT_MILLHOUSE_GROUP_3:
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetOrientation(5.931499f);
                        DoCast(me, SPELL_ANCHOR_HERE);
                        break;
                    case POINT_MILLHOUSE_GROUP_4:
                        me->SetOrientation(3.455752f);
                        DoCast(me, SPELL_ANCHOR_HERE);
                        Talk(SAY_MILLHOUSE_EVENT_2);
                        events.ScheduleEvent(EVENT_CAST_IMPENDING_DOOM, 1s);
                        break;
                    default:
                        break;
                }

                EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
            }

            void UpdateAI(uint32 diff) override
            {
                // Do not update events if Millhouse is aggressive and has no combat.
                if (!UpdateVictim() && me->GetReactState() == REACT_AGGRESSIVE)
                    return;

                events.Update(diff);

                // Impending Doom is exception because it needs to be interrupted.
                if (me->HasUnitState(UNIT_STATE_CASTING) && !me->FindCurrentSpellBySpellId(SPELL_IMPENDING_DOOM))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FROSTBOLT_VOLLEY:
                            DoCastAOE(SPELL_FROSTBOLT_VOLLEY);
                            events.ScheduleEvent(EVENT_FROSTBOLT_VOLLEY, 7s);
                            break;
                        case EVENT_SHADOWFURY:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_SHADOWFURY);
                            events.ScheduleEvent(EVENT_SHADOWFURY, 7s);
                            break;
                        case EVENT_FEAR:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                                DoCast(target, SPELL_FEAR);
                            events.ScheduleEvent(EVENT_FEAR, 18s);
                            break;
                        case EVENT_SHADOW_BOLT:
                            DoCastVictim(SPELL_SHADOW_BOLT);
                            events.Repeat(2s);
                            break;
                        case EVENT_CAST_IMPENDING_DOOM:
                            DoCast(me, SPELL_IMPENDING_DOOM);
                            DoCast(me, SPELL_IMPENDING_DOOM_CHANNEL);
                            events.ScheduleEvent(EVENT_INTERRUPT_IMPENDING_DOOM, 15s, 20s);
                            break;
                        case EVENT_INTERRUPT_IMPENDING_DOOM:
                            me->InterruptNonMeleeSpells(true);
                            me->RemoveAllAuras();
                            me->HandleEmoteCommand(EMOTE_ONESHOT_KNOCKDOWN);
                            events.ScheduleEvent(EVENT_CAST_IMPENDING_DOOM, 3s);
                            break;
                        case EVENT_RUN_AWAY:
                            if (_fleeCounter == 1)
                                me->GetMotionMaster()->MovePoint(POINT_MILLHOUSE_GROUP_2, MillhousePointGroup2);
                            else if (_fleeCounter == 2)
                                me->GetMotionMaster()->MovePoint(POINT_MILLHOUSE_GROUP_3, MillhousePointGroup3);
                            else if (_fleeCounter == 3)
                                me->GetMotionMaster()->MovePoint(POINT_MILLHOUSE_GROUP_4, MillhousePointGroup4);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            InstanceScript* _instance;
            EventMap events;
            uint8 _fleeCounter;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<npc_sc_millhouse_manastormAI>(creature);
        }
};

// 81459 - Force of Earth
class spell_force_of_earth : public SpellScriptLoader
{
    public:
        spell_force_of_earth() : SpellScriptLoader("spell_force_of_earth") { }

        class spell_force_of_earth_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_force_of_earth_SpellScript);

            void DummyEffect(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->SetDisplayId(26693); // can be moved to SAI part, need sniffs to see what this dummy does (note: npc 43552)
            }

            void Register()
            {
                OnEffectLaunch += SpellEffectFn(spell_force_of_earth_SpellScript::DummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_force_of_earth_SpellScript();
        }
};

// 45313 - Anchor Here
class spell_sc_anchor_here : public SpellScriptLoader
{
public:
    spell_sc_anchor_here() : SpellScriptLoader("spell_sc_anchor_here") { }

    class spell_sc_anchor_here_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sc_anchor_here_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Creature* creature = GetHitUnit()->ToCreature())
                creature->SetHomePosition(creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sc_anchor_here_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sc_anchor_here_SpellScript();
    }
};

// 93167 - Twilight Documents
class spell_sc_twilight_documents : public SpellScriptLoader
{
    public:
        spell_sc_twilight_documents() : SpellScriptLoader("spell_sc_twilight_documents") { }

        class spell_sc_twilight_documents_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sc_twilight_documents_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sObjectMgr->GetGameObjectTemplate(GAMEOBJECT_TWILIGHT_DOCUMENTS))
                    return false;
                return true;
            }

            void SpawnGameObject(SpellEffIndex /*effIndex*/)
            {
                if (WorldLocation* loc = GetHitDest())
                    GetCaster()->SummonGameObject(GAMEOBJECT_TWILIGHT_DOCUMENTS, *loc, QuaternionData(), 7200);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_sc_twilight_documents_SpellScript::SpawnGameObject, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sc_twilight_documents_SpellScript();
        }
};

// 81008 - Quake
class JumpCheck
{
    public:
        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                return (target->HasUnitMovementFlag(MOVEMENTFLAG_FALLING)
                    || target->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR)
                    || target->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP));

            return false;
        }
};

class spell_sc_quake : public SpellScriptLoader
{
    public:
        spell_sc_quake() : SpellScriptLoader("spell_sc_quake") { }

        class spell_sc_quake_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sc_quake_SpellScript);

            void FilterTargets(std::list<WorldObject*>& unitList)
            {
                unitList.remove_if(JumpCheck());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sc_quake_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sc_quake_SpellScript();
        }
};

class spell_sc_ring_wyrm_knockback : public SpellScript
{
    PrepareSpellScript(spell_sc_ring_wyrm_knockback);

    void SetDest(SpellDestination& dest)
    {
        Unit* caster = GetCaster();

        float angle = caster->GetOrientation();
        float x = caster->GetPositionX() + cos(caster->GetOrientation() + float(M_PI)) * 100.0f;
        float y = caster->GetPositionY() + sin(caster->GetOrientation() + float(M_PI)) * 100.0f;
        float z = caster->GetPositionZ();
        dest.Relocate({ x, y, z, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_sc_ring_wyrm_knockback::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class at_sc_corborus_intro : public AreaTriggerScript
{
public:
    at_sc_corborus_intro() : AreaTriggerScript("at_sc_corborus_intro") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (instance->GetData(DATA_EVENT_PROGRESS) < EVENT_INDEX_CORBORUS_INTRO)
                instance->SetData(DATA_EVENT_PROGRESS, EVENT_INDEX_CORBORUS_INTRO);
        return true;
    }
};

class at_sc_slabhide_intro : public AreaTriggerScript
{
public:
    at_sc_slabhide_intro() : AreaTriggerScript("at_sc_slabhide_intro") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
    {
        if (InstanceScript* instance = player->GetInstanceScript())
            if (instance->GetData(DATA_EVENT_PROGRESS) < EVENT_INDEX_SLABHIDE_INTRO)
                instance->SetData(DATA_EVENT_PROGRESS, EVENT_INDEX_SLABHIDE_INTRO);
        return true;
    }
};

void AddSC_stonecore()
{
    new npc_sc_millhouse_manastorm();
    new spell_force_of_earth();
    new spell_sc_anchor_here();
    new spell_sc_twilight_documents();
    new spell_sc_quake();
    RegisterSpellScript(spell_sc_ring_wyrm_knockback);
    new at_sc_corborus_intro();
    new at_sc_slabhide_intro();
}
