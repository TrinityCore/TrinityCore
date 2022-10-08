/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016-2019 MagicStorm
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

#include "trial_of_valor.h"

enum Spells
{
    SPELL_GUARDIANS_BREATH          = 228187,
    SPELL_GUARDIANS_BREATH_FC       = 232807,
    SPELL_GUARDIANS_BREATH_1        = 227658,
    SPELL_FIERY_PHLEGM              = 227539,
    SPELL_SALTY_SPITTLE             = 227566,
    SPELL_DARK_DISCHARGE            = 227570,
    SPELL_FIERY_PHLEGM_AURA         = 228758,
    SPELL_SALTY_SPITTLE_AURA        = 228768,
    SPELL_DARK_DISCHARGE_AURA       = 228769,
    SPELL_FROTHING_RAGE             = 228174,
    SPELL_FLASHING_FANGS            = 227514,
    SPELL_ROARING_LEAP              = 227883,
    SPELL_ACTIVATE                  = 228201,
    SPELL_ROARING_LEAP_JUMP         = 229350,
    SPELL_HEADLONG_CHARGE           = 227816,
    SPELL_FLAME_LICK                = 228228,
    SPELL_FROST_LICK                = 228246,
    SPELL_SHADOW_LICK               = 228250,
};

enum Events
{
    EVENT_GUARDIANS_BREATH = 1,
    EVENT_GUARDIANS_BREATH_DMG,
    EVENT_FROTHING_RAGE,
    EVENT_FLASHING_FANGS,
    EVENT_ROARING_LEAP,
    EVENT_HEADLONG_CHARGE,
    EVENT_LICK,
};

const Position guarmJump = { 454.967f, 543.651f, 2.99177f, 0.0f };

const Position guarmWaypoints[16] =
{
    { 466.7234f, 475.3623f, 5.49523f, 0.0f }, // .go xyz 466.7234 475.3623 5.49523 1648
    { 466.2234f, 483.6123f, 5.49523f, 0.0f },
    { 466.2234f, 484.1123f, 5.24523f, 0.0f },
    { 466.2234f, 484.8623f, 5.49523f, 0.0f },
    { 464.9734f, 489.1123f, 5.24523f, 0.0f },
    { 465.2234f, 493.6123f, 5.74523f, 0.0f },
    { 465.2234f, 496.3623f, 6.24523f, 0.0f },
    { 464.9734f, 503.1123f, 6.24523f, 0.0f },
    { 466.7234f, 505.8623f, 5.74523f, 0.0f },
    { 464.7234f, 514.6123f, 5.49523f, 0.0f },
    { 450.3374f, 493.5509f, 5.813526f, 0.0f },
    { 451.7007f, 482.807f, 5.506626f, 0.0f },
    { 451.7007f, 483.557f, 5.506626f, 0.0f },
    { 451.4507f, 487.057f, 5.506626f, 0.0f },
    { 451.2007f, 488.557f, 5.506626f, 0.0f },
    { 450.7007f, 492.057f, 6.006626f, 0.0f }
};

std::list<Unit*> guardiansBreathTargets;

std::list<Unit*> areaTrigger1Targets;
std::list<Unit*> areaTrigger2Targets;
std::list<Unit*> areaTrigger3Targets;

class boss_guarm : public CreatureScript
{
public:

    boss_guarm() : CreatureScript("boss_guarm") { }

    struct boss_guarmAI : public BossAI
    {
        boss_guarmAI(Creature* creature) : BossAI(creature, DATA_GUARM)
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->SetCanFly(false);

            if (instance)
                instance->SetBossState(DATA_GUARM, NOT_STARTED);
        }

        bool isJump;
        uint8 count;
        uint32 totalPlayersPct;
        Position atPos;

        void Reset() override
        {
            me->SetReactState(REACT_DEFENSIVE);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NON_ATTACKABLE));
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE));

            isJump = false;
            count = 0;
            totalPlayersPct = 0;

            _Reset();
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                instance->SetBossState(DATA_GUARM, FAIL);
            }

            me->SetReactState(REACT_DEFENSIVE);

            events.Reset();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
                instance->SetBossState(DATA_GUARM, IN_PROGRESS);
            }

            events.ScheduleEvent(EVENT_GUARDIANS_BREATH, 20.5 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_FLASHING_FANGS, 6 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_ROARING_LEAP, 45 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_HEADLONG_CHARGE, 60 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_LICK, 22 * IN_MILLISECONDS);

            //Talk(SAY_COMBAT);
            me->setActive(true);
            DoZoneInCombat();
        }

        void JustDied(Unit* /*killer*/) override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustDied();
                instance->SetBossState(DATA_GUARM, DONE);
            }

            if (GameObject* go = me->FindNearestGameObject(GO_GUARM_DOOR_HALYA, 1000.0f))
                go->UseDoorOrButton(300000);

            //Talk(SAY_DIED);
        }

        void KilledUnit(Unit* victim) override
        {
            //if (victim->GetTypeId() == TYPEID_PLAYER)
            //    Talk(SAY_KILL);
        }

        void JustReachedHome() override
        {
            if (instance)
            {
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                _JustReachedHome();
                instance->SetBossState(DATA_GUARM, FAIL);
            }
        }

        uint32 ChooseRandomLick()
        {
            uint32 lick;
            switch (urand(0, 2))
            {
                case 0:
                    lick = SPELL_FLAME_LICK;
                    break;
                case 1:
                    lick = SPELL_FROST_LICK;
                    break;
                case 2:
                    lick = SPELL_SHADOW_LICK;
                    break;
            }

            return lick;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id <= 15)
            {
                ++count;
                me->GetMotionMaster()->MovePoint(count, guarmWaypoints[count]);
            }

            if (id >= 15)
            {
                me->GetMotionMaster()->Clear();

                me->SetReactState(REACT_AGGRESSIVE);

                if (Unit* target = me->GetVictim())
                    me->CanStartAttack(target, true);

                events.ScheduleEvent(EVENT_GUARDIANS_BREATH, 30.5 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_FLASHING_FANGS, 12 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_ROARING_LEAP, 45 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_HEADLONG_CHARGE, 45 * IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_LICK, 22 * IN_MILLISECONDS);

                count = 0;

                me->SetWalk(true);
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->GetDistance2d(guarmJump.GetPositionX(), guarmJump.GetPositionY()) <= 0.0f && isJump)
            {
                me->GetMotionMaster()->Clear();
                me->CastSpell(guarmJump.GetPositionX(), guarmJump.GetPositionY(), guarmJump.GetPositionZ(), 228344, true);
                me->SetWalk(false);
                me->CastSpell(me, 229480, true);
                me->GetMotionMaster()->MovePoint(count, guarmWaypoints[count]);
                isJump = false;
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            Map::PlayerList const& PlayerList = me->GetMap()->GetPlayers();

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GUARDIANS_BREATH:
                        Talk(0);
                        me->CastSpell(me, SPELL_ACTIVATE, true);

                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_GUARDIANS_BREATH_FC, true);

                        if (AreaTrigger* areaTrigger = me->GetAreaTrigger(232805))
                            atPos = areaTrigger->GetPosition();

                        events.ScheduleEvent(EVENT_GUARDIANS_BREATH, 32 * IN_MILLISECONDS);
                        events.ScheduleEvent(EVENT_GUARDIANS_BREATH_DMG, 5 * IN_MILLISECONDS);
                        break;

                    case EVENT_GUARDIANS_BREATH_DMG:
                        me->CastSpell(me, SPELL_ACTIVATE, true);

                        me->CastSpell(atPos.GetPositionX(), atPos.GetPositionY(), atPos.GetPositionZ(), SPELL_GUARDIANS_BREATH_1, true);
                        me->CastSpell(atPos.GetPositionX(), atPos.GetPositionY(), atPos.GetPositionZ(), SPELL_FIERY_PHLEGM, true);
                        me->CastSpell(atPos.GetPositionX(), atPos.GetPositionY(), atPos.GetPositionZ(), SPELL_SALTY_SPITTLE, true);
                        me->CastSpell(atPos.GetPositionX(), atPos.GetPositionY(), atPos.GetPositionZ(), SPELL_DARK_DISCHARGE, true);

                        events.ScheduleEvent(EVENT_FROTHING_RAGE, 1000);
                        break;

                    case EVENT_FROTHING_RAGE:
                        if (guardiansBreathTargets.empty() || PlayerList.isEmpty())
                            return;

                        totalPlayersPct = CalculatePct(guardiansBreathTargets.size(), PlayerList.getSize());

                        if (totalPlayersPct < 60)
                            me->CastSpell(me, SPELL_FROTHING_RAGE, true);

                        totalPlayersPct = 0;
                        break;

                    case EVENT_FLASHING_FANGS:
                        me->CastSpell(me, SPELL_ACTIVATE, true);

                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_FLASHING_FANGS, true);

                        events.ScheduleEvent(EVENT_FLASHING_FANGS, 12 * IN_MILLISECONDS);
                        break;

                    case EVENT_ROARING_LEAP:
                        me->CastSpell(me, SPELL_ACTIVATE, true);

                        if (Unit* target = me->GetVictim())
                            me->CastSpell(target, SPELL_ROARING_LEAP, true);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                            me->CastSpell(target, SPELL_ROARING_LEAP_JUMP, true);

                        events.ScheduleEvent(EVENT_ROARING_LEAP, 24 * IN_MILLISECONDS);
                        break;

                    case EVENT_HEADLONG_CHARGE:
                        me->SetReactState(REACT_PASSIVE);
                        me->AttackStop();
                        me->GetMotionMaster()->MoveJump(guarmJump, 45.0f, 20.0f);
                        isJump = true;
                        events.CancelEvent(EVENT_FROTHING_RAGE);
                        events.CancelEvent(EVENT_FLASHING_FANGS);
                        events.CancelEvent(EVENT_ROARING_LEAP);
                        events.CancelEvent(EVENT_HEADLONG_CHARGE);
                        events.CancelEvent(EVENT_LICK);
                        break;

                    case EVENT_LICK:
                        if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                if (Player *player = i->GetSource())
                                    if (player->IsAlive() && player->GetDistance(me) >= 5.0f)
                                        me->CastSpell(player, ChooseRandomLick(), true);

                        events.ScheduleEvent(EVENT_LICK, 22 * IN_MILLISECONDS);
                        break;

                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTrialOfValorAI<boss_guarmAI>(creature);
    }
};

// 232804
class areatrigger_guarm_fire : public AreaTriggerEntityScript
{
public:
    areatrigger_guarm_fire() : AreaTriggerEntityScript("areatrigger_guarm_fire") { }

    struct areatrigger_guarm_fireAI : AreaTriggerAI
    {
        areatrigger_guarm_fireAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        bool canDoDamage;
        uint32 damageTimer;
        bool canCastBreath;
        Unit* caster = at->GetCaster();

        void OnInitialize() override
        {
            at->SetDuration(10000);
            //at->SetTimeToTargetScale(100000);
            damageTimer = 5000;
            canDoDamage = false;
            canCastBreath = false;
        }

        void OnUpdate(uint32 diff) override
        {
            if (damageTimer <= diff)
            {
                if (!canDoDamage)
                {
                    //at->SetTimeToTargetScale(10000);
                    canDoDamage = true;
                }
            }
            else
                damageTimer -= diff;
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            areaTrigger1Targets.push_back(unit);
            guardiansBreathTargets.push_back(unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            areaTrigger1Targets.remove(unit);
            guardiansBreathTargets.remove(unit);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_guarm_fireAI(areatrigger);
    }
};

// 232805
class areatrigger_guarm_nature : public AreaTriggerEntityScript
{
public:
    areatrigger_guarm_nature() : AreaTriggerEntityScript("areatrigger_guarm_nature") { }

    struct areatrigger_guarm_natureAI : AreaTriggerAI
    {
        areatrigger_guarm_natureAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        bool canDoDamage;
        uint32 damageTimer;
        uint32 giveDamageTimer;
        Unit* caster = at->FindNearestCreature(BOSS_GUARM, 1500.0f, true);

        void OnInitialize() override
        {
            at->SetDuration(10000);
            //at->SetTimeToTargetScale(100000);
            damageTimer = 5000;
            canDoDamage = false;
        }

        void OnUpdate(uint32 diff) override
        {
            if (damageTimer <= diff)
            {
                if (!canDoDamage)
                {
                    //at->SetTimeToTargetScale(10000);
                    canDoDamage = true;
                }
            }
            else
                damageTimer -= diff;
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            areaTrigger2Targets.push_back(unit);
            guardiansBreathTargets.push_back(unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            areaTrigger2Targets.remove(unit);
            guardiansBreathTargets.remove(unit);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_guarm_natureAI(areatrigger);
    }
};

// 232801
class areatrigger_guarm_shadow : public AreaTriggerEntityScript
{
public:
    areatrigger_guarm_shadow() : AreaTriggerEntityScript("areatrigger_guarm_shadow") { }

    struct areatrigger_guarm_shadowAI : AreaTriggerAI
    {
        areatrigger_guarm_shadowAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        bool canDoDamage;
        uint32 damageTimer;
        Unit* caster = at->FindNearestCreature(BOSS_GUARM, 1500.0f, true);

        void OnInitialize() override
        {
            at->SetDuration(10000);
            //at->SetTimeToTargetScale(100000);
            damageTimer = 5000;
            canDoDamage = false;
        }

        void OnUpdate(uint32 diff) override
        {
            if (damageTimer <= diff)
            {
                if (!canDoDamage)
                {
                    //at->SetTimeToTargetScale(10000);
                    canDoDamage = true;
                }
            }
            else
                damageTimer -= diff;
        }

        void OnUnitEnter(Unit* unit) override
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            areaTrigger3Targets.push_back(unit);
            guardiansBreathTargets.push_back(unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return;

            areaTrigger3Targets.remove(unit);
            guardiansBreathTargets.remove(unit);
        }

        void OnRemove() override
        {
            guardiansBreathTargets.clear();
            areaTrigger1Targets.clear();
            areaTrigger2Targets.clear();
            areaTrigger3Targets.clear();
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_guarm_shadowAI(areatrigger);
    }
};

// 227570 - 227566 - 227539
class spell_guarm_guardians_breath : public SpellScriptLoader
{
public:
    spell_guarm_guardians_breath() : SpellScriptLoader("spell_guarm_guardians_breath") { }

    class spell_guarm_guardians_breath_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_guarm_guardians_breath_SpellScript);

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            unitList.clear();

            if (GetSpellInfo()->Id == SPELL_DARK_DISCHARGE)
            {
                for (auto target : areaTrigger3Targets)
                {
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        continue;

                    unitList.push_back(target);

                    if (target->HasAura(SPELL_SALTY_SPITTLE) || target->HasAura(SPELL_FIERY_PHLEGM))
                        GetCaster()->DealDamage(target, 3000000, 0, DIRECT_DAMAGE, GetSpellInfo()->GetSchoolMask(), GetSpellInfo());
                }
            }

            if (GetSpellInfo()->Id == SPELL_SALTY_SPITTLE)
            {
                for (auto target : areaTrigger2Targets)
                {
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        continue;

                    unitList.push_back(target);

                    if (target->HasAura(SPELL_DARK_DISCHARGE) || target->HasAura(SPELL_FIERY_PHLEGM))
                        GetCaster()->DealDamage(target, 3000000, 0, DIRECT_DAMAGE, GetSpellInfo()->GetSchoolMask(), GetSpellInfo());
                }
            }

            if (GetSpellInfo()->Id == SPELL_FIERY_PHLEGM)
            {
                for (auto target : areaTrigger1Targets)
                {
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        continue;

                    unitList.push_back(target);

                    if (target->HasAura(SPELL_SALTY_SPITTLE) || target->HasAura(SPELL_DARK_DISCHARGE))
                        GetCaster()->DealDamage(target, 3000000, 0, DIRECT_DAMAGE, GetSpellInfo()->GetSchoolMask(), GetSpellInfo());
                }
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_guarm_guardians_breath_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CONE_ENEMY_24);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_guarm_guardians_breath_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_CONE_ENEMY_24);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_guarm_guardians_breath_SpellScript();
    }
};

void AddSC_boss_guarm()
{
    new boss_guarm();
    new areatrigger_guarm_fire();
    new areatrigger_guarm_nature();
    new areatrigger_guarm_shadow();
    new spell_guarm_guardians_breath();
}
