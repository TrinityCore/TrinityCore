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

/*
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "utgarde_keep.h"

enum SkarvaldTexts
{
    // Texts are common for both bosses.
    SAY_AGGRO                         = 0,
    SAY_DEATH                         = 1, // Said once both bosses are dead.
    SAY_DIED_FIRST                    = 2, // Said by the first boss that dies.
    SAY_SLAY                          = 3,
    SAY_DEATH_RESPONSE                = 4  // Said by the boss alive after the first one dies.
};

enum SkarvaldSpells
{
    // Skarvald the Constructor
    SPELL_CHARGE                      = 43651,
    SPELL_STONE_STRIKE                = 48583,
    SPELL_ENRAGE                      = 48193,
    SPELL_SUMMON_SKARVALD_GHOST       = 48613,

    // Dalronn the Controller
    SPELL_SHADOW_BOLT                 = 43649,
    SPELL_SUMMON_SKELETONS            = 52611,
    SPELL_DEBILITATE                  = 43650,
    SPELL_SUMMON_DALRONN_GHOST        = 48612,

    // Ghosts
    SPELL_GHOST_VISUAL                = 22650,
    SPELL_PERIODIC_HEAL               = 48591,

    // Shared
    SPELL_PERMANENT_FEIGN_DEATH       = 29266,
    SPELL_QUIET_SUICIDE               = 3617
};

enum SkarvaldEvents
{
    // Skarvald the Constructor
    EVENT_SKARVALD_CHARGE             = 1,
    EVENT_STONE_STRIKE,
    EVENT_ENRAGE,

    // Dalronn the Controller
    EVENT_SHADOW_BOLT,
    EVENT_DEBILITATE,
    EVENT_SUMMON_SKELETONS,
    EVENT_DELAYED_AGGRO_SAY,

    // Common
    EVENT_DEATH_RESPONSE,
    EVENT_FEIGN_DEATH
};

enum SkarvaldActions
{
    ACTION_OTHER_FEIGNS_DEATH         = 1,
    ACTION_CLEANUP_AND_DIE            = 2
};

enum SkarvaldCreatures
{
    NPC_DALRONN_GHOST                 = 27389,
    NPC_SKARVALD_GHOST                = 27390
};

class SkarvaldChargePredicate
{
    public:
        SkarvaldChargePredicate(Unit* unit) : _me(unit) { }

        bool operator() (WorldObject* target) const
        {
            return target->GetDistance2d(_me) >= 5.0f && target->GetDistance2d(_me) <= 30.0f;
        }

    private:
        Unit* _me;
};

struct ControllerBaseAI : public BossAI
{
    ControllerBaseAI(Creature* creature) : BossAI(creature, DATA_SKARVALD_DALRONN)
    {
        OtherBossData = 0;
        IsInGhostForm = me->GetEntry() == NPC_SKARVALD_GHOST || me->GetEntry() == NPC_DALRONN_GHOST;
        OtherFeignsDeath = false;
        IsAboutToFeignDeath = false;
    }

    void JustAppeared() override
    {
        if (!IsInGhostForm)
            return;

        DoCastSelf(SPELL_GHOST_VISUAL);
        DoCastSelf(SPELL_PERIODIC_HEAL);

        DoZoneInCombat();
    }

    void Reset() override
    {
        if (!IsInGhostForm)
        {
            _Reset();
            OtherFeignsDeath = false;
            IsAboutToFeignDeath = false;
            me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
            me->SetReactState(REACT_AGGRESSIVE);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        if (!IsInGhostForm)
            BossAI::JustEngagedWith(who);
    }

    void DamageTaken(Unit* who, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        if (OtherFeignsDeath)
            return;

        if (damage >= me->GetHealth() && who != me)
        {
            damage = me->GetHealth() -1;

            if (!IsAboutToFeignDeath)
            {
                IsAboutToFeignDeath = true;

                if (Creature* otherBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(OtherBossData)))
                    otherBoss->AI()->DoAction(ACTION_OTHER_FEIGNS_DEATH);

                events.Reset();
                events.ScheduleEvent(EVENT_FEIGN_DEATH, 0s);
            }
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_OTHER_FEIGNS_DEATH:
                events.ScheduleEvent(EVENT_DEATH_RESPONSE, 4s);
                OtherFeignsDeath = true;
                break;
            case ACTION_CLEANUP_AND_DIE:
                summons.DespawnAll();
                DoCastSelf(SPELL_QUIET_SUICIDE, true);
                me->RemoveUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (!IsInGhostForm && who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (OtherFeignsDeath)
        {
            Talk(SAY_DEATH);
            _JustDied();

            if (Creature* otherBoss = ObjectAccessor::GetCreature(*me, instance->GetGuidData(OtherBossData)))
                otherBoss->AI()->DoAction(ACTION_CLEANUP_AND_DIE);
        }
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_DEATH_RESPONSE:
                Talk(SAY_DEATH_RESPONSE);
                break;
            case EVENT_FEIGN_DEATH:
                Talk(SAY_DIED_FIRST);
                DoCastSelf(OtherBossData == DATA_DALRONN ? SPELL_SUMMON_SKARVALD_GHOST : SPELL_SUMMON_DALRONN_GHOST, true);
                DoCastSelf(SPELL_PERMANENT_FEIGN_DEATH);
                me->SetUnitFlag(UNIT_FLAG_UNINTERACTIBLE);
                me->SetReactState(REACT_PASSIVE);
                break;
            default:
                break;
        }
    }

protected:
    uint32 OtherBossData;
    bool IsInGhostForm;
    bool OtherFeignsDeath;
    bool IsAboutToFeignDeath;
};

// 24200, 27390 - Skarvald the Constructor
struct boss_skarvald_the_constructor : public ControllerBaseAI
{
    boss_skarvald_the_constructor(Creature* creature) : ControllerBaseAI(creature)
    {
        OtherBossData = DATA_DALRONN;
    }

    void JustEngagedWith(Unit* who) override
    {
        ControllerBaseAI::JustEngagedWith(who);

        if (!IsInGhostForm)
            Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_SKARVALD_CHARGE, 5s);
        events.ScheduleEvent(EVENT_STONE_STRIKE, 10s);
        events.ScheduleEvent(EVENT_ENRAGE, 10s, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SKARVALD_CHARGE:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, SkarvaldChargePredicate(me)))
                    DoCast(target, SPELL_CHARGE);
                events.Repeat(5s, 10s);
                break;
            case EVENT_STONE_STRIKE:
                DoCastVictim(SPELL_STONE_STRIKE);
                events.Repeat(5s, 10s);
                break;
            case EVENT_ENRAGE:
                DoCastSelf(SPELL_ENRAGE);
                events.Repeat(20s, 30s);
                break;
            default:
                ControllerBaseAI::ExecuteEvent(eventId);
                break;
        }
    }
};

// 24201, 27389 - Dalronn the Controller
struct boss_dalronn_the_controller : public ControllerBaseAI
{
    boss_dalronn_the_controller(Creature* creature) : ControllerBaseAI(creature)
    {
        OtherBossData = DATA_SKARVALD;
    }

    void JustEngagedWith(Unit* who) override
    {
        ControllerBaseAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_SHADOW_BOLT, 1s);
        events.ScheduleEvent(EVENT_DEBILITATE, 5s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SUMMON_SKELETONS, 10s);

        if (!IsInGhostForm)
            events.ScheduleEvent(EVENT_DELAYED_AGGRO_SAY, 6s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_SHADOW_BOLT:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 45.0f, true))
                    DoCast(target, SPELL_SHADOW_BOLT);
                events.Repeat(2s, 4s);
                break;
            case EVENT_DEBILITATE:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 50.0f, true))
                    DoCast(target, SPELL_DEBILITATE);
                events.Repeat(5s, 10s);
                break;
            case EVENT_SUMMON_SKELETONS:
                DoCastSelf(SPELL_SUMMON_SKELETONS);
                events.Repeat(10s, 30s);
                break;
            case EVENT_DELAYED_AGGRO_SAY:
                Talk(SAY_AGGRO);
                break;
            default:
                ControllerBaseAI::ExecuteEvent(eventId);
                break;
        }
    }
};

void AddSC_boss_skarvald_dalronn()
{
    RegisterUtgardeKeepCreatureAI(boss_skarvald_the_constructor);
    RegisterUtgardeKeepCreatureAI(boss_dalronn_the_controller);
}
