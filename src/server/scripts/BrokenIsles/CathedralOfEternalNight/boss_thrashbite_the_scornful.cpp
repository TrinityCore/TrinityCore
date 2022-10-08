/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "cathedral_of_eternal_night.h"

enum Spells
{
    SPELL_PULVERIZING_CUDGEL = 237276,
    SPELL_SCORNFUL_GAZE = 237726,
    SPELL_SCORNFUL_CHARGE = 238462,

    SPELL_HEAVE_CUDGEL = 243124, ///243153,
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
};

enum Phases
{
    PHASE_NORMAL,
    PHASE_INTRO
};

std::vector<TalkData> const talkData =
{
    { EVENT_ON_MOVEINLINEOFSIGHT,           EVENT_TYPE_TALK,            0 },
    { EVENT_ON_ENTERCOMBAT,                 EVENT_TYPE_TALK,            1 },
    { EVENT_ON_JUSTDIED,                    EVENT_TYPE_TALK,            2 },
};

Position const Pos1 ={ -528.8203f, 2525.414f, 439.7709f, 3.187753f };

struct boss_thrashbite_the_scornful : public BossAI
{
    boss_thrashbite_the_scornful(Creature* creature) : BossAI(creature, DATA_THRASHBITE_THE_SCORNFUL) { Initialize(); }

    void Initialize()
    {
        PhaseStatus = Phases::PHASE_INTRO;
        //SetDungeonEncounterID(2057);
        LoadTalkData(&talkData);
    }

    void DoAction(int32 param)
    {
        switch (param)
        {
        case 1:
            me->GetMotionMaster()->MoveJump(Pos1, 20.0f, 7.0f, 10.0f);
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_PC));
            me->SetHomePosition(Pos1);
            break;
        }
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_HEAVE_CUDGEL, 30000);
        events.ScheduleEvent(SPELL_PULVERIZING_CUDGEL, 5000);
        events.ScheduleEvent(SPELL_SCORNFUL_GAZE, 15000);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_HEAVE_CUDGEL:
        {
            DoCast(SPELL_HEAVE_CUDGEL);
            events.Repeat(30s);
            break;
        }
        case SPELL_PULVERIZING_CUDGEL:
        {
            DoCast(SPELL_PULVERIZING_CUDGEL);
            events.Repeat(5s);
            break;
        }
        case SPELL_SCORNFUL_GAZE:
        {
            DoCast(SPELL_SCORNFUL_GAZE);
            events.ScheduleEvent(SPELL_SCORNFUL_CHARGE, 7000);
            events.Repeat(30s);
            break;
        }
        case SPELL_SCORNFUL_CHARGE:
        {
            DoCast(SPELL_SCORNFUL_CHARGE);
            break;
        }
        default:
            break;
        }
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (who->IsPlayer() && me->IsWithinDist(who, 25.0f, false) && PhaseStatus == Phases::PHASE_INTRO)
        {
            PhaseStatus = Phases::PHASE_NORMAL;
            GetTalkData(EVENT_ON_MOVEINLINEOFSIGHT);
            DoAction(1);
        }
    }
    uint8 PhaseStatus;
};


enum MobSpells
{
    SPELL_BLINDING_GLARE = 239232,
    SPELL_FEL_GLARE = 239201,
    SPELL_FOCUSED_DESTRUCTION = 239235,
};
struct npc_gazerax_118723 : public ScriptedAI
{
    npc_gazerax_118723(Creature* creature) : ScriptedAI(creature) { Initialize(); }

    void JustDied(Unit* /*killer*/) override
    {
        if (Creature* target = instance->GetCreature(NPC_THRASHBITE_THE_SCORNFUL))
            target->AI()->DoAction(1);
    }

    void EnterCombat(Unit* /*victim*/) override
    {
        events.ScheduleEvent(SPELL_BLINDING_GLARE, 5000);
        events.ScheduleEvent(SPELL_FEL_GLARE, 5000);
        events.ScheduleEvent(SPELL_FOCUSED_DESTRUCTION, 5000);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case SPELL_BLINDING_GLARE:
            {
                DoCast(SPELL_BLINDING_GLARE);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_FEL_GLARE:
            {
                DoCast(SPELL_FEL_GLARE);
                events.Repeat(5s, 10s);
                break;
            }
            case SPELL_FOCUSED_DESTRUCTION:
            {
                DoCast(SPELL_FOCUSED_DESTRUCTION);
                events.Repeat(5s, 10s);
                break;
            }
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }

    void Initialize()
    {
        instance = me->GetInstanceScript();
    }
private:
    InstanceScript * instance;
};

void AddSC_boss_thrashbite_the_scornful()
{
    RegisterCreatureAI(boss_thrashbite_the_scornful);
    RegisterCreatureAI(npc_gazerax_118723);
}
