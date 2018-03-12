/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"

enum Spells
{
    //AR = Ancient Rage. They're the "phase" spells.
    SPELL_AR_FIRE   = 217563,
    SPELL_AR_FROST  = 217831,
    SPELL_AR_ARCANE = 217834,

    //Name format for spell : SPELL_(FI/FR/A)_NAME

    ///Fire spells
    SPELL_FI_BURNING_BOMB = 217877, // - NO SCRIPT NEEDED

    //WF = Wrathful Flames
    SPELL_FI_WF_TARGET_PICKER   = 217893, //Picks 10 targets in 100 yards radius
    SPELL_FI_WF_MISSILE         = 217897, //Creates a missile that will spawn a Wrathful Flames (see NPCs)
    SPELL_FI_WF_AT              = 217903, //Creates the Area Trigger that will deal damage.
    SPELL_FI_WF_DAMAGE          = 217907, //Deals damage - NO SCRIPT NEEDED

    ///Frost spells

    //IC = Icy Comet
    SPELL_FR_IC_AOE             = 217919, //This spell starts the others. It launches the target picker, and also spawns 5 random Icy Comets in 60 yards radius.
    SPELL_FR_IC_TARGET_PICKER   = 217920, //Picks 10 random players to cast a missile on.
    SPELL_FR_IC_MISSILE         = 218390, //Missile that casts DAMAGE_AT.
    SPELL_FR_IC_DAMAGE_AT       = 217922, //Deals damage and create AT
    SPELL_FR_IC_SLOW            = 217925,

    SPELL_FR_HG_BUFF            = 217966, //This buff launches the damage, and also creates the area trigger.
    SPELL_FR_HG_AT              = 217967, //This creates an area trigger that pulls everyone near the center.
    ///Arcane spells
    //AD = Arcane Desolation
    SPELL_A_AD_DAMAGE           = 217995, //Simple damage + knockback - NO SCRIPT NEEDED
    SPELL_A_AD_TARGET           = 217986,
    SPELL_A_AD_MISSILE          = 218000,

    //AP = Arcanopulse
    SPELL_AP_SPAWNER            = 218005, //Casts 4 times the AT spell
    SPELL_AP_AT                 = 218003, //Creates an AT with a spline, that goes like a spiral
    SPELL_AP_DAMAGE             = 218012  //Damager + stun - NO SCRIPT NEEDED
};

enum NPCs
{
    NPC_WRATHFUL_FLAMES = 109456
};

enum Phases
{
    PHASE_NEUTRAL   = 1,
    PHASE_FIRE      = 2,
    PHASE_FROST     = 3,
    PHASE_ARCANE    = 4
};

enum Events
{
    ///Phase events
    EVENT_PHASE_FIRE = 1,
    EVENT_PHASE_FROST = 2,
    EVENT_PHASE_ARCANE = 3,
    EVENT_CHANGE_PHASE = 4,

    ///Fire events
    EVENT_BURNING_BOMB = 5,
    EVENT_WRATHFUL_FLAMES = 6,

    ///Frost events
    EVENT_ICY_COMET = 7,
    EVENT_HOWLING_GALE = 8,
    ///Arcane events
    EVENT_ARCANE_DESOLATION = 9,
    EVENT_ARCANOPULSE = 10
};

class boss_calamir : public CreatureScript
{
public:
    boss_calamir() : CreatureScript("boss_calamir") { }

    struct boss_calamirAI : public WorldBossAI
    {
        uint8 lastPhase;

        boss_calamirAI(Creature* creature) : WorldBossAI(creature)
        {
            lastPhase = 0;
        }

        void Reset() override
        {
            _Reset();
            me->SetFullHealth();
            me->CombatStop(true);
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
            events.SetPhase(PHASE_NEUTRAL);
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();
        }

        void EnterCombat(Unit* who) override
        {
            if (!who)
                return;

            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
        }

        void UpdateAI(uint32 diff) override
        {
            UpdateVictim();

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    ///Phase events
                case EVENT_CHANGE_PHASE:
                    events.SetPhase(PHASE_NEUTRAL);
                    break;
                case EVENT_PHASE_FIRE:
                    me->CastSpell(me, SPELL_AR_FIRE, true);
                    events.ScheduleEvent(EVENT_CHANGE_PHASE, 20000);
                    events.ScheduleEvent(EVENT_BURNING_BOMB, 200);
                    events.ScheduleEvent(EVENT_WRATHFUL_FLAMES, urand(7000, 8000));
                    lastPhase = PHASE_FIRE;
                    break;
                case EVENT_PHASE_FROST:
                    me->CastSpell(me, SPELL_AR_FROST, true);
                    events.ScheduleEvent(EVENT_HOWLING_GALE, 200);
                    events.ScheduleEvent(EVENT_ICY_COMET, 8000);
                    events.ScheduleEvent(EVENT_CHANGE_PHASE, 20000);
                    lastPhase = PHASE_FROST;
                    break;
                case EVENT_PHASE_ARCANE:
                    me->CastSpell(me, SPELL_AR_ARCANE, true);
                    events.ScheduleEvent(EVENT_CHANGE_PHASE, 20000);
                    events.ScheduleEvent(EVENT_ARCANE_DESOLATION, 200);

                    lastPhase = PHASE_ARCANE;
                    break;

                ///Fire events
                case EVENT_BURNING_BOMB:
                {
                    if (me->IsInCombat())
                        if (me->HasAura(SPELL_AR_FIRE))
                        {
                            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                            if (!target)
                                break;
                            DoCast(target, SPELL_FI_BURNING_BOMB, false);
                            events.ScheduleEvent(EVENT_BURNING_BOMB, 16000);
                        }
                    break;
                }
                case EVENT_WRATHFUL_FLAMES:
                {
                    if (me->IsInCombat())
                        if (me->HasAura(SPELL_AR_FIRE))
                            DoCast(SPELL_FI_WF_TARGET_PICKER);
                    break;
                }
                ///Frost events
                case EVENT_HOWLING_GALE:
                {
                    if(me->IsInCombat())
                        if (me->HasAura(SPELL_AR_FROST))
                            DoCast(SPELL_FR_HG_BUFF);
                    break;
                }
                case EVENT_ICY_COMET:
                {
                    if(me->IsInCombat())
                        if (me->HasAura(SPELL_AR_FROST))
                            DoCast(SPELL_FR_IC_AOE);
                    break;
                }
                ///Arcane events
                case EVENT_ARCANE_DESOLATION:
                {
                    if (me->IsInCombat())
                        if (me->HasAura(SPELL_AR_ARCANE))
                        {
                            events.ScheduleEvent(EVENT_ARCANE_DESOLATION, 12000);
                            me->CastSpell(me, SPELL_A_AD_TARGET, false);
                            events.ScheduleEvent(EVENT_ARCANOPULSE, 1000);
                        }
                    break;
                }
                case EVENT_ARCANOPULSE:
                {
                    if(me->IsInCombat())
                        if (me->HasAura(SPELL_AR_ARCANE))
                            DoCast(SPELL_AP_SPAWNER);
                    break;
                }
                }
            }

            switch (events.GetPhaseMask())
            {
            case PHASE_NEUTRAL:
                if (lastPhase == 0)
                {
                    events.ScheduleEvent(EVENT_PHASE_FIRE, 5000);
                    events.SetPhase(PHASE_FIRE);
                    lastPhase = PHASE_FIRE;
                }
                else if (lastPhase == PHASE_FIRE)
                {
                    events.ScheduleEvent(EVENT_PHASE_FROST, 5000);
                    events.SetPhase(PHASE_FROST);
                    lastPhase = PHASE_FROST;
                }
                else if (lastPhase == PHASE_FROST)
                {
                    events.ScheduleEvent(EVENT_PHASE_ARCANE, 5000);
                    events.SetPhase(PHASE_ARCANE);
                    lastPhase = PHASE_ARCANE;
                }
                else if (lastPhase == PHASE_ARCANE)
                {
                    events.ScheduleEvent(EVENT_PHASE_FIRE, 5000);
                    events.SetPhase(PHASE_FIRE);
                    lastPhase = PHASE_FIRE;
                }
                break;
            }

            DoMeleeAttackIfReady();
        }

    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_calamirAI(creature);
    }
};

//217893
class spell_calamir_wf_target_picker : public SpellScriptLoader
{
public:
    spell_calamir_wf_target_picker() : SpellScriptLoader("spell_calamir_wf_target_picker") { }

    class spell_calamir_wf_target_picker_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_calamir_wf_target_picker_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            if (!target)
                return;

            if (Unit* caster = GetCaster())
                caster->CastSpell(target, SPELL_FI_WF_MISSILE, false);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_calamir_wf_target_picker_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_calamir_wf_target_picker_SpellScript();
    }
};

//109456
class npc_calamir_wrathful_flames : public CreatureScript
{
public:
    npc_calamir_wrathful_flames() : CreatureScript("npc_calamir_wrathful_flames") {}

    struct npc_calamir_wrathful_flamesAI : public ScriptedAI
    {
        npc_calamir_wrathful_flamesAI(Creature* creature) : ScriptedAI(creature) {}

        enum SpellData
        {
            SPELL_TO_CAST = SPELL_FI_WF_AT
        };

        void Reset() override
        {
            //me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_REMOVE_CLIENT_CONTROL);
            ApplyBuff();
        }

        void ApplyBuff()
        {
            if (!me)
                return;

            me->CastSpell(me, SPELL_TO_CAST, true); //Applies AreaTrigger aura
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_calamir_wrathful_flamesAI(creature);
    }
};

//7625
class at_calamir_wrathful_flames : public AreaTriggerEntityScript
{
public:
    int32 timeInterval;
    at_calamir_wrathful_flames() : AreaTriggerEntityScript("at_calamir_wrathful_flames") { }

    struct at_calamir_wrathful_flamesAI : AreaTriggerAI
    {
        at_calamir_wrathful_flamesAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                        unit->CastSpell(unit, SPELL_FI_WF_DAMAGE, true); //Applies an aura that damages everything
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            if (!unit)
                return;

            if(unit->GetTypeId() == TYPEID_PLAYER)
                unit->CastSpell(unit, SPELL_FI_WF_DAMAGE, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (!unit)
                return;

            if (unit->HasAura(SPELL_FI_WF_DAMAGE))
                unit->RemoveAura(SPELL_FI_WF_DAMAGE);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!at || !caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->HasAura(SPELL_FI_WF_DAMAGE))
                        unit->RemoveAura(SPELL_FI_WF_DAMAGE);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_calamir_wrathful_flamesAI(areatrigger);
    }
};

//217986
class spell_calamir_arcane_desolation_target : public SpellScriptLoader
{
public:
    spell_calamir_arcane_desolation_target() : SpellScriptLoader("spell_calamir_arcane_desolation_target") { }

    class spell_calamir_arcane_desolation_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_calamir_arcane_desolation_target_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            if (!target)
                return;

            if (Unit* caster = GetCaster())
                caster->CastSpell(target, SPELL_A_AD_MISSILE, false);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_calamir_arcane_desolation_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_calamir_arcane_desolation_target_SpellScript();
    }
};

//7630
class at_calamir_icy_comet : public AreaTriggerEntityScript
{
public:
    at_calamir_icy_comet() : AreaTriggerEntityScript("at_calamir_icy_comet") { }

    struct at_calamir_icy_cometAI : AreaTriggerAI
    {
        at_calamir_icy_cometAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 0;
        }

        int32 timeInterval;

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            at->SetUInt32Value(AREATRIGGER_DECAL_PROPERTIES_ID, 13);

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                        unit->CastSpell(unit, SPELL_FR_IC_SLOW, true);

        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            if (!unit)
                return;

            if (unit->GetTypeId() == TYPEID_PLAYER)
                unit->CastSpell(unit, SPELL_FR_IC_SLOW, true);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (!unit)
                return;

            if (unit->HasAura(SPELL_FR_IC_SLOW))
                unit->RemoveAura(SPELL_FR_IC_SLOW);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!at || !caster)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->HasAura(SPELL_FR_IC_SLOW))
                        unit->RemoveAura(SPELL_FR_IC_SLOW);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_calamir_icy_cometAI(areatrigger);
    }
};

//7650
class at_calamir_arcanopulse : public AreaTriggerEntityScript
{
public:
    at_calamir_arcanopulse() : AreaTriggerEntityScript("at_calamir_arcanopulse") { }

    struct at_calamir_arcanopulseAI : AreaTriggerAI
    {
        at_calamir_arcanopulseAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;
        }

        /*void OnSetCreatePosition(Unit* caster, Position& startPos, Position& endPos, std::list<Position>& path) override
        {
            if (!caster)
                return;

            bool clockwise = true;
            Position center = caster->GetPosition();
            float radius = 0.0f;

            float step = clockwise ? -M_PI / 8.0f : M_PI / 8.0f;
            float angle = center.GetAngle(trigger->GetPositionX(), trigger->GetPositionY());
            for (uint8 l_Iter = 0; l_Iter < 60; angle += step, ++l_Iter)
            {
                Position point;
                point.m_positionX = center.GetPositionX() + radius * cosf(angle);
                point.m_positionY = center.GetPositionY() + radius * sinf(angle);
                point.m_positionZ = trigger->GetPositionZ();
                path.push_back(point);
                if(radius < 30.0f)
                    radius += 1.0f;
            }

            endPos = path.back();

            //trigger->SetLinearMove(caster, startPos, endPos, path, 20);
        }*/

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            caster->CastSpell(unit, SPELL_AP_DAMAGE, false);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            if (!caster || !unit)
                return;

        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_calamir_arcanopulseAI(areatrigger);
    }
};

//7640
class at_calamir_howling_gale : public AreaTriggerEntityScript
{
public:
    at_calamir_howling_gale() : AreaTriggerEntityScript("at_calamir_howling_gale") { }

    struct at_calamir_howling_galeAI : AreaTriggerAI
    {
        int32 timeInterval;
        at_calamir_howling_galeAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 1000;
        }

        void OnUpdate(uint32 p_Time) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            timeInterval += p_Time;
            if (timeInterval < 1000)
                return;

            for (auto guid : at->GetInsideUnits())
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                    if (unit->GetTypeId() == TYPEID_PLAYER)
                    {
                        unit->GetMotionMaster()->MoveCloserAndStop(1, caster, 2.0f);
                    }

            timeInterval -= 1000;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_calamir_howling_galeAI(areatrigger);
    }
};


void AddSC_boss_calamir()
{
    new at_calamir_arcanopulse();
    new at_calamir_howling_gale();
    new at_calamir_icy_comet();
    new at_calamir_wrathful_flames();

    new boss_calamir();

    new npc_calamir_wrathful_flames();

    new spell_calamir_arcane_desolation_target();
    new spell_calamir_wf_target_picker();
}
