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

/* ScriptData
SDName: Boss_Ambassador_Hellmaw
SD%Complete: 80
SDComment: Enrage spell missing/not known
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedEscortAI.h"
#include "shadow_labyrinth.h"

enum Yells
{
    SAY_INTRO       = 0,
    SAY_AGGRO       = 1,
    SAY_HELP        = 2,
    SAY_SLAY        = 3,
    SAY_DEATH       = 4
};

enum Spells
{
    SPELL_BANISH            = 30231,
    SPELL_CORROSIVE_ACID    = 33551,
    SPELL_FEAR              = 33547,
    SPELL_ENRAGE            = 34970
};

enum Events
{
    EVENT_CORROSIVE_ACID = 1,
    EVENT_FEAR,
    EVENT_BERSERK
};

static constexpr uint32 PATH_ESCORT_HELLMAW = 149850;

struct boss_ambassador_hellmaw : public EscortAI
{
    boss_ambassador_hellmaw(Creature* creature) : EscortAI(creature)
    {
        _instance = creature->GetInstanceScript();
        _intro = false;
    }

    void Reset() override
    {
        if (!me->IsAlive())
            return;

        _events.Reset();
        _instance->SetBossState(DATA_AMBASSADOR_HELLMAW, NOT_STARTED);

        _events.ScheduleEvent(EVENT_CORROSIVE_ACID, 5s, 10s);
        _events.ScheduleEvent(EVENT_FEAR, 25s, 30s);
        if (IsHeroic())
            _events.ScheduleEvent(EVENT_BERSERK, 3min);

        DoAction(ACTION_AMBASSADOR_HELLMAW_BANISH);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (me->HasAura(SPELL_BANISH))
            return;

        EscortAI::MoveInLineOfSight(who);
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_AMBASSADOR_HELLMAW_INTRO)
            DoIntro();
        else if (actionId == ACTION_AMBASSADOR_HELLMAW_BANISH)
        {
            if (_instance->GetData(DATA_FEL_OVERSEER) && me->HasAura(SPELL_BANISH))
                DoCast(me, SPELL_BANISH, true); // this will not work, because he is immune to banish
        }
    }

    void DoIntro()
    {
        if (_intro)
            return;

        _intro = true;

        if (me->HasAura(SPELL_BANISH))
            me->RemoveAurasDueToSpell(SPELL_BANISH);

        Talk(SAY_INTRO);
        LoadPath(PATH_ESCORT_HELLMAW);
        Start(true, ObjectGuid::Empty, nullptr, false, true);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _instance->SetBossState(DATA_AMBASSADOR_HELLMAW, IN_PROGRESS);
        Talk(SAY_AGGRO);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SetBossState(DATA_AMBASSADOR_HELLMAW, DONE);
        Talk(SAY_DEATH);
    }

    void UpdateEscortAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasAura(SPELL_BANISH))
        {
            EnterEvadeMode(EvadeReason::Other);
            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CORROSIVE_ACID:
                    DoCastVictim(SPELL_CORROSIVE_ACID);
                    _events.ScheduleEvent(EVENT_CORROSIVE_ACID, 15s, 25s);
                    break;
                case EVENT_FEAR:
                    DoCastAOE(SPELL_FEAR);
                    _events.ScheduleEvent(EVENT_FEAR, 20s, 35s);
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_ENRAGE, true);
                    break;
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    bool _intro;
};

void AddSC_boss_ambassador_hellmaw()
{
    RegisterShadowLabyrinthCreatureAI(boss_ambassador_hellmaw);
}
