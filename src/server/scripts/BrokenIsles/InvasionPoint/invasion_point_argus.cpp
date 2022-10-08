/*
* Copyright (C) 2021 BfaCore Reforged
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

#include "Scenario.h"
#include "OutdoorPvP.h"
#include "AccountMgr.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "SpellMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Log.h"
#include "Conversation.h"
#include "CreatureTextMgr.h"
#include "PhasingHandler.h"
#include "AreaTriggerAI.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "WorldQuestMgr.h"
#include "GameEventMgr.h"

enum events
{
    EVENT_1,
    EVENT_2,
    EVENT_3,
    EVENT_4
};
Position const DemonHunterBonich[5] =
{
    { -3730.54f, -8004.46f, 2.84272f, 3.7699f },
    { -3716.07f, -7999.76f, 2.85281f, 0.0f },
    { -3721.6f, -8007.37f, 2.49409f, 5.02602f },
    { -3721.6f, -7992.15f, 2.92483f, 1.25663f },
    { -3730.54f, -7995.06f, 3.14554f, 2.51329f }
};

Position const DemonHunterAurinor[5] =
{
    { -4073.0f, -4654.52f, 80.5863f, 2.51329f },
    { -4073.0f, -4663.92f, 80.5863f, 3.7699f },
    { -4064.05f, -4666.83f, 80.5863f, 5.02655f },
    { -4064.05f, -4651.61f, 80.5863f, 1.25663f },
    { -4058.52f, -4659.22f, 80.5863f, 0.0f }
};

Position const DemonHunterNaigtal[5] =
{
    { -1835.82f, -1596.12f, 1.11104f, 1.85724f },
    { -1836.24f, -1611.33f, 0.672226f, 4.37052f },
    { -1827.22f, -1608.67f, 0.583281f, 5.62716f },
    { -1826.96f, -1599.27f, 1.00169f, 0.600602f },
    { -1841.56f, -1603.57f, 0.681503f, 3.11388f }
};

Position const DemonHunterCengar[5] =
{
    { 655.852f, 604.255f, 40.9144f, 1.34802f },
    { 662.049f, 597.18f, 40.4902f, 0.0910225f },
    { 648.064f, 591.182f, 40.2618f, 3.86093f },
    { 657.235f, 589.101f, 40.2661f, 5.11757f },
    { 647.209f, 600.548f, 40.4144f, 2.60429f }
};

Position const DemonHunterVal[5] =
{
    { 4025.6f, 570.56f, 0.33214f, 0.202399f },
    { -4038.83f, 563.044f, 0.0224609f, 3.97231f },
    { -4032.55f, 576.901f, 0.58214f, 1.45902f },
    { -4040.72f, 572.257f, 0.962267f, 2.71566f },
    { -4029.49f, 561.995f, -0.219604f, 5.22931f }
};

Position const DemonHunterSangua[5] =
{
    { -1387.595f, 753.6718f, 61.38449f, 5.115621f },
    { -1388.96f, 768.8273f, 62.62868f, 1.346462f },
    { -1382.772f, 761.7454f, 62.27438f, 0.08982736f },
    { -1396.764f, 755.7639f, 62.23556f, 3.859742f },
    { -1397.607f, 765.1305f, 62.38156f, 2.603098f }
};

Position const GameObjectsFlagsSangua[2] =
{
    { -1401.347f, 756.7188f, 62.50092f, 2.286167f },
    { -1385.615f, 770.9549f, 62.50092f, 2.286167f }
};

Position const GameObjectsFlagsBonich[2] =
{
    { -3713.248f, -8003.493f, 3.149687f, 4.70962f },
    { -3734.464f, -8003.865f, 3.163017f, 4.70962f }
};

Position const GameObjectsFlagsCengar[2] =
{
    { 665.1163f, 594.6597f, 40.31978f, 1.030727f },
    { 646.6945f, 605.1945f, 40.31978f, 1.030727f }
};

Position const GameObjectsFlagsNaigtal[2] =
{
    { -1844.26f, -1599.764f, 0.8188952f, 1.540312f },
    { -1823.043f, -1599.976f, 0.8188952f, 1.540312f }
};

Position const GameObjectsFlagsAurinor[2] =
{
    { -4076.918f, -4663.325f, 80.46125f, 4.70962f },
    { -4055.703f, -4662.953f, 80.46125f, 4.70962f }
};

Position const GameObjectsFlagsVal[2] =
{
    { -4043.491f, 563.4879f, 0.4485643f, 2.398739f },
    { -4029.46f, 579.4011f, 0.4485643f, 2.398739f }
};

struct npc_baldrazar : ScriptedAI
{
    npc_baldrazar(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    EventMap events;
    bool Intro;
    bool Addthreatlist;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 5000);
        events.ScheduleEvent(EVENT_2, 11000);
        events.ScheduleEvent(EVENT_3, 29000);
    }

  /*  void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254531);
        DoCast(251298);*/

        /*if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
     /*   else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
    }*/

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125667, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
           // for (auto& players : playerList)
            //    if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(219960);
                events.ScheduleEvent(EVENT_1, 25000);
                break;
            case EVENT_2:
                DoCast(249463);
                DoCast(249464);
                events.ScheduleEvent(EVENT_2, 10000);
                break;
            case EVENT_3:
                DoCast(249465);
                events.ScheduleEvent(EVENT_3, 29000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_dreadbringer_valus : ScriptedAI
{
    npc_dreadbringer_valus(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        Intro = false;
        Addthreatlist = false;
    }

    EventMap events;
    bool Intro;
    bool Addthreatlist;
    SummonList summons;

    void Reset() override
    {
        events.Reset();
        DespawnAllSummons();
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 6000);
        events.ScheduleEvent(EVENT_2, 9000);
        events.ScheduleEvent(EVENT_3, 85000);
    }

    void JustSummoned(Creature* summon)
    {
        summons.Summon(summon);

        summon->SetReactState(REACT_PASSIVE);
        summon->SetControlled(1, UNIT_STATE_ROOT);

        if (summon->GetEntry() == 125576)
            summon->SetDisplayId(11686);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125576, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254526);
        DoCast(251298);

       /* if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
          //  for (auto& players : playerList)
         //       if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(249230);
                events.ScheduleEvent(EVENT_1, 15000);
                break;
            case EVENT_2:
                DoCast(249235);
                events.ScheduleEvent(EVENT_2, 32000);
                break;
            case EVENT_3:
                DoCast(249226);
                events.ScheduleEvent(EVENT_3, 30000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_vogrethar_the_defiled : ScriptedAI
{
    npc_vogrethar_the_defiled(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    EventMap events;
    bool Intro;
    bool Addthreatlist;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 3000);
        events.ScheduleEvent(EVENT_2, 15000);
        events.ScheduleEvent(EVENT_3, 18000);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125586, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254527);
        DoCast(251298);

    /*    if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
          /*  for (auto& players : playerList)
                if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());*/
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(249260);
                events.ScheduleEvent(EVENT_1, 8000);
                break;
            case EVENT_2:
                DoCast(249257);
                events.ScheduleEvent(EVENT_2, 34000);
                break;
            case EVENT_3:
                DoCast(249259);
                events.ScheduleEvent(EVENT_3, 22000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_flamebringer_azrothel : ScriptedAI
{
    npc_flamebringer_azrothel(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    EventMap events;
    bool Intro;
    bool Addthreatlist;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 7000);
        events.ScheduleEvent(EVENT_2, 11000);
        events.ScheduleEvent(EVENT_3, 22000);
        events.ScheduleEvent(EVENT_4, 37000);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125656, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254530);
        DoCast(251298);
/*
        if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
          //  for (auto& players : playerList)
          //      if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(249400);
                events.ScheduleEvent(EVENT_1, 21000);
                break;
            case EVENT_2:
                DoCast(249457);
                events.ScheduleEvent(EVENT_2, 40000);
                break;
            case EVENT_3:
                DoCast(249440);
                events.ScheduleEvent(EVENT_3, 43000);
                break;
            case EVENT_4:
             //   me->CastSpellDuration(me, 249391, false, 0, 3);
                events.ScheduleEvent(EVENT_4, 21000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_gorgoloth : ScriptedAI
{
    npc_gorgoloth(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 11000);
        events.ScheduleEvent(EVENT_2, 21000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254520);
        DoCast(251298);

    /*    if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
          //  for (auto& players : playerList)
         //       if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(248641);
                events.ScheduleEvent(EVENT_1, 28000);
                break;
            case EVENT_2:
                DoCast(248508);
                events.ScheduleEvent(EVENT_2, 16000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_flameweaver_verathix : ScriptedAI
{
    npc_flameweaver_verathix(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 12000);
        events.ScheduleEvent(EVENT_2, 6000);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125315, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(251252);
        DoCast(251298);
        DoCast(218802);

     /*   if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
        //    for (auto& players : playerList)
        //       if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                    DoCast(target, 248769, false);
                break;
            case EVENT_2:
                DoCast(248772);
                events.ScheduleEvent(EVENT_2, 50000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_velthrak_the_punisher : ScriptedAI
{
    npc_velthrak_the_punisher(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;
    SummonList summons;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 5000);
        events.ScheduleEvent(EVENT_2, 12000);
        events.ScheduleEvent(EVENT_3, 20000);
        events.ScheduleEvent(EVENT_4, 11000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254529);
        DoCast(251298);

     /*   if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void JustSummoned(Creature* summon)
    {
        summons.Summon(summon);
        summon->SetReactState(REACT_PASSIVE);

        switch (summon->GetEntry())
        {
        case 125638:
            summon->CastSpell(summon, 249406, false);
            break;
        case 125636:
          //  me->AddDelayedEvent(1000, [=]() -> void { summon->CastSpell(summon, 249394, false); });
            summon->DespawnOrUnsummon(3000);
            break;
        }
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125638, 200.0f);
        me->GetCreatureListWithEntryInGrid(list, 125636, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
         //   for (auto& players : playerList)
         //       if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(249403);
                events.ScheduleEvent(EVENT_1, 42000);
                break;
            case EVENT_2:
                DoCast(249400);
                events.ScheduleEvent(EVENT_2, 21000);
                break;
            case EVENT_3:
                DoCast(249392);
                events.ScheduleEvent(EVENT_3, 32000);
                break;
            case EVENT_4:
            //    me->CastSpellDuration(me, 249391, false, 0, 3);
                events.ScheduleEvent(EVENT_4, 20000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_mazgoroth : ScriptedAI
{
    npc_mazgoroth(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 12000);
        events.ScheduleEvent(EVENT_2, 16000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254522);
        DoCast(251298);

      /*  if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
     //   else if (me->GetZoneId() == 9102)
    /*    {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
          //  for (auto& players : playerList)
           //     if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
            {
                auto threatlist = me->getThreatManager().getThreatList();

                for (uint8 i = 0; i < 3; ++i)
                {
                    if (threatlist.empty())
                        break;

                    auto itr = Trinity::Containers::SelectRandomContainerElement(threatlist);
                    if (Unit* target = itr->getTarget())
                        DoCast(target, 248501, false);

                    threatlist.remove(itr);
                }
                events.ScheduleEvent(EVENT_1, 45000);
                break;
            }
            case EVENT_2:
                DoCast(248509);
                if (auto victim = me->GetVictim())
                    me->AddThreat(victim, 0.0f);
                events.ScheduleEvent(EVENT_2, 32000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_malphazel_argus : ScriptedAI
{
    npc_malphazel_argus(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;
    SummonList summons;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 12000);
        //events.ScheduleEvent(EVENT_2, 17000);
        events.ScheduleEvent(EVENT_3, 25000);
    }

    void JustSummoned(Creature* summon)
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
        case 125576:
            summon->SetControlled(1, UNIT_STATE_ROOT);
            summon->SetDisplayId(11686);
            summon->SetReactState(REACT_PASSIVE);
            break;
        }
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125576, 200.0f);
        me->GetCreatureListWithEntryInGrid(list, 125579, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254528);
        DoCast(251298);

      /*  if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void SpellHit(Unit* /*owner*/, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case 249245:
            if (auto victim = me->GetVictim())
                me->AddThreat(victim, 0.0f);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
            /*for (auto& players : playerList)
                if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());*/
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(249235);
                events.ScheduleEvent(EVENT_1, 64000);
                break;
                /*case EVENT_2:
                DoCast();
                events.ScheduleEvent(EVENT_2, 35000);
                break;*/
            case EVENT_3:
                DoCast(249245);
                events.ScheduleEvent(EVENT_3, 36000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_fel_lord_kazral : ScriptedAI
{
    npc_fel_lord_kazral(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 4000);
        events.ScheduleEvent(EVENT_2, 11000);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        std::list<GameObject*> listGo;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125274, 200.0f);
        me->GetGameObjectListWithEntryInGrid(listGo, 216056, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
      //  if (!listGo.empty())
        //    for (std::list<GameObject*>::const_iterator itr = listGo.begin(); itr != listGo.end(); itr++)
           //     (*itr)->RemoveFromOwner();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254524);
        DoCast(251298);

       /* if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
         //   for (auto& players : playerList)
            //    if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(217958);
                events.ScheduleEvent(EVENT_1, 16000);
                break;
            case EVENT_2:
                DoCast(248696);
                events.ScheduleEvent(EVENT_2, 10000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_harbinger_drelnathar : ScriptedAI
{
    npc_harbinger_drelnathar(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 5000);
        events.ScheduleEvent(EVENT_2, 16000);
        events.ScheduleEvent(EVENT_3, 26000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(251250);
        DoCast(251298);

    /*    if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
         //   for (auto& players : playerList)
         //       if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(249071);
                events.ScheduleEvent(EVENT_1, 30000);
                break;
            case EVENT_2:
                DoCast(249066);
                events.ScheduleEvent(EVENT_2, 24000);
                break;
            case EVENT_3:
                DoCast(249068);
                events.ScheduleEvent(EVENT_3, 26000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_flamecaller_vezrah : ScriptedAI
{
    npc_flamecaller_vezrah(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 6000);
        events.ScheduleEvent(EVENT_2, 10000);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(251256);
        DoCast(251298);

    /*    if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
          //  for (auto& players : playerList)
           //     if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(248757);
                events.ScheduleEvent(EVENT_1, 15000);
                break;
            case EVENT_2:
                DoCast(248768);
                events.ScheduleEvent(EVENT_2, 45000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_dread_knight_zakgal : ScriptedAI
{
    npc_dread_knight_zakgal(Creature* creature) : ScriptedAI(creature)
    {
        Intro = false;
        Addthreatlist = false;
    }

    bool Intro;
    bool Addthreatlist;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 6000);
        events.ScheduleEvent(EVENT_2, 38000);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 125254, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (Intro)
            return;

        Intro = true;
        DoCast(254525);
        DoCast(251298);

       /* if (me->GetZoneId() == 9180)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9100)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9128)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251005); });
        else if (me->GetZoneId() == 9127)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });
        else if (me->GetZoneId() == 9102)
        {
            DoCast(252113);
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251004); });
        }
        else if (me->GetZoneId() == 9126)
            me->AddDelayedEvent(9000, [=]() -> void { DoCast(251003); });*/
    }

    void JustDied(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9180)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterBonich[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsBonich[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -3724.07f, -7999.76f, 3.26834f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251015);
        }
        else if (me->GetZoneId() == 9100)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterAurinor[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsAurinor[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4066.52f, -4659.22f, 80.5446f, 1.61817f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
        else if (me->GetZoneId() == 9126)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterCengar[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsCengar[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, 654.082f, 596.453f, 40.4031f, 4.22246f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9127)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterVal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsVal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -4033.44f, 568.951f, 0.531898f, 5.59048f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251013);
        }
        else if (me->GetZoneId() == 9102)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterNaigtal[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsNaigtal[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1833.56f, -1603.79f, 0.902228f, 4.73205f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251014);
        }
        else if (me->GetZoneId() == 9128)
        {
            for (uint8 i = 0; i < 5; ++i)
                me->SummonCreature(127108, DemonHunterSangua[i], TEMPSUMMON_TIMED_DESPAWN, 20000);
            for (uint8 i = 0; i < 2; ++i)
                //me->SummonGameObject(276221, GameObjectsFlagsSangua[i], 0, 0, 0, 0, 0, 20);
            me->SummonCreature(124884, -1390.74f, 761.028f, 62.5843f, 5.47791f, TEMPSUMMON_TIMED_DESPAWN, 20000);

            DoCast(251010);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HealthBelowPct(20) && !Addthreatlist)
        {
            Addthreatlist = true;
            std::list<Player*> playerList;
            GetPlayerListInGrid(playerList, me, 300.0f);
        //    for (auto& players : playerList)
         //       if (!playerList.empty())
                    //me->AddThreatTarget(players->GetGUID());
        }

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(248663);
                events.ScheduleEvent(EVENT_1, 10000);
                break;
            case EVENT_2:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    DoCast(target, 248654, false);
                events.ScheduleEvent(EVENT_2, 35000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_fragment_of_argus : ScriptedAI
{
    npc_fragment_of_argus(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    ObjectGuid playerGuid;
    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoZoneInCombat(me, 100.0f);

        if (me->GetZoneId() == 9128)
            DoCast(251896);

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, me, 200.0f);
    //    Trinity::Containers::RandomResizeList(playerList, 1);
        for (auto& target : playerList)
        {
            DoCast(target, 218369, false);
            playerGuid = target->GetGUID();
            me->AI()->AttackStart(target);
            me->ClearUnitState(UNIT_STATE_CASTING);
        }
        events.ScheduleEvent(EVENT_1, 2000);
    }

    bool checkPlayers()
    {
        std::list<HostileReference*> threatList = me->getThreatManager().getThreatList();
        if (threatList.size() >= 1)
            return true;

        return false;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        //while (uint32 eventId = events.ExecuteEvent())
        //{
            //switch (eventId)
            //{
          /*  case EVENT_1:
            {
           //     Unit* player = Unit::GetUnit(*me, playerGuid);
         //       if (!player || !player->IsAlive() || !player->HasAura(218368))
         /*       {
                    if (me->GetAnyOwner())
                    {*/
                  //      if (Creature* summoner = me->GetAnyOwner()->ToCreature())*/
                    //    {
                    //        if (Unit* pTarget = summoner->AI()->SelectTarget(SELECT_TARGET_RANDOM, checkPlayers(), 200.0f, true))
                         //   {
                        //        playerGuid.Clear();
                        //        me->AttackStop();
                            //    me->CastSpell(pTarget, 218368, TriggerCastFlags(TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_IGNORE_AURA_INTERRUPT_FLAGS));
                     /*       }
                        }
                    }
                }*/
             //   else
             //       me->AI()->AttackStart(player);
           //     events.ScheduleEvent(EVENT_1, 2000);
             //   break;
         //   }
         //   default:
         //       break;
         //   }
        //}
      //  DoMeleeAttackIfReady();
    }
};

struct npc_gripping_shadows : ScriptedAI
{
    npc_gripping_shadows(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(11686);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(249466);
        me->DespawnOrUnsummon(8000);
    }
};

struct npc_explosive_orb : ScriptedAI
{
    npc_explosive_orb(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(me, 219464, true);
     //   me->AddDelayedEvent(1000, [=]() -> void { DoCast(249447); });
        me->DespawnOrUnsummon(13000);
    }
};

struct npc_wake_of_blood : ScriptedAI
{
    npc_wake_of_blood(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(43164);
    }

    EventMap events;
    std::list<ObjectGuid> listPlayers;

    void Reset() override
    {
        events.Reset();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(249264);

        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, me, 200.0f);
     //   Trinity::Containers::RandomResizeList(playerList, 1);
        for (auto& target : playerList)
            listPlayers.push_back(target->GetGUID());

        events.ScheduleEvent(EVENT_1, 500);
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
            case EVENT_1:
                for (auto& target : listPlayers)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, target))
                        me->GetMotionMaster()->MovePoint(1, player->GetPosition());
                events.ScheduleEvent(EVENT_2, 1000);
                break;
            case EVENT_2:
                for (auto& target : listPlayers)
                    if (Player* player = ObjectAccessor::GetPlayer(*me, target))
                        me->GetMotionMaster()->MovePoint(1, player->GetPosition());
                    else
                        events.ScheduleEvent(EVENT_1, 1000);

                events.ScheduleEvent(EVENT_2, 1000);
                break;
            }
        }
    }
};

struct npc_fel_spike_argus : ScriptedAI
{
    npc_fel_spike_argus(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(71142);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(248702);
    }
};

struct npc_shadowy_illusion_argus : ScriptedAI
{
    npc_shadowy_illusion_argus(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        me->DespawnOrUnsummon();
        ScriptedAI::EnterEvadeMode();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(249242);

        if (Unit* owner = me->GetOwner())
            owner->CastSpell(me, 98581, false);

        DoZoneInCombat(me, 100.0f);
        events.ScheduleEvent(EVENT_1, 11000);
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
            case EVENT_1:
                DoCast(249243);
                events.ScheduleEvent(EVENT_1, 8000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct npc_flame_fissure : ScriptedAI
{
    npc_flame_fissure(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
        me->SetDisplayId(11686);
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(248771);
    }
};

struct npc_demonhunter_argus_invasion : ScriptedAI
{
    npc_demonhunter_argus_invasion(Creature* creature) : ScriptedAI(creature)
    {
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }
};

struct npc_temporal_anomaly : ScriptedAI
{
    npc_temporal_anomaly(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    bool use;

  /*  void Reset() override
    {
        use = false;
      //  me->AddDelayedEvent(2000, [=]() -> void
        {
            me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
            DoCast(me, 252456, true);
     //   });
    }*/

    void DoAction(int32 const action) override
    {
        //switch (action)
        //{
      //  case ACTION_1:
            if (!use)
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 10.0f);
              //  Trinity::Containers::RandomResizeList(playerList, 1);
                for (auto& players : playerList)
                {
                    if (!playerList.empty())
                    {
                        use = true;
                        auto outdoor = players->GetOutdoorPvP();
                   //     if (outdoor && outdoor->GetTypeId() == OUTDOOR_PVP_ARGUS_INVASION)
                            outdoor->HandleKill(players, me);
                    }
                }
                me->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                me->AddUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
                DoCast(252472);
                me->RemoveAura(252456);
                me->DespawnOrUnsummon(2000);
            }
            //break;
        //}
    }
};

struct npc_demon_hunter_val : ScriptedAI
{
    npc_demon_hunter_val(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    bool use;

    void Reset() override
    {
        use = false;
        DoCast(250898);
        me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
    }

    void DoAction(int32 const action) override
    {
        //switch (action)
        //{
      //  case ACTION_1:
            if (!use)
            {
                std::list<Player*> playerList;
                GetPlayerListInGrid(playerList, me, 10.0f);
            //    Trinity::Containers::RandomResizeList(playerList, 1);
                for (auto& players : playerList)
                {
                    if (!playerList.empty())
                    {
                        use = true;
                        auto outdoor = players->GetOutdoorPvP();
              //          if (outdoor && outdoor->GetTypeId() == OUTDOOR_PVP_ARGUS_INVASION)
                            outdoor->HandleKill(players, me);
                    }
                }
                Talk(0);
                me->RemoveNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                me->RemoveAllAuras();
                me->RemoveAllControlled();
                me->DespawnOrUnsummon(3000);
            }
            //break;
        //}
    }
};

//125755
struct npc_felflame_invader : ScriptedAI
{
    npc_felflame_invader(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();

    //    me->AddDelayedEvent(2000, [=]() -> void
      //  {
            if (me->GetZoneId() == 9100)
            {
                if (auto c = me->FindNearestCreature(125856, 5.0f))
                    if (!c->IsInCombat())
                        me->CastSpell(c, 249995, false);
            }
            else if (me->GetZoneId() == 9128)
            {
                if (auto c = me->FindNearestCreature(125874, 10.0f))
                    if (!c->IsInCombat())
                        me->CastSpell(c, 252327, false);
            }
      //  });
    }

    void JustReachedHome() override
    {
        if (me->GetZoneId() == 9100)
        {
            if (auto c = me->FindNearestCreature(125856, 5.0f))
                me->CastSpell(c, 249995, false);
        }
        else if (me->GetZoneId() == 9128)
            if (auto c = me->FindNearestCreature(125856, 10.0f))
                me->CastSpell(c, 252327, false);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(0);
        events.ScheduleEvent(EVENT_1, 2000);
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void JustDied(Unit* /*who*/) override
    {
        //me->RemoveAllAreaObjects();
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
            case EVENT_1:
                DoCast(253609);
                events.ScheduleEvent(EVENT_1, 7000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//125197
struct npc_felflame_subjugator : ScriptedAI
{
    npc_felflame_subjugator(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
        //me->RemoveAllAreaObjects();

      //  me->AddDelayedEvent(2000, [=]() -> void
       // {
            if (me->GetZoneId() == 9128)
            {
                if (auto c = me->FindNearestCreature(125874, 10.0f))
                    if (!c->IsInCombat())
                        me->CastSpell(c, 252327, false);
            }
            else if (me->GetZoneId() == 9126)
            {
                DoCast(251888);

                if (me->GetPositionX() >= 673.15f && me->GetPositionX() <= 673.25f)
                    DoCast(252628);
                else if (me->GetPositionX() >= 674.018f && me->GetPositionX() <= 674.038f)
                    DoCast(252628);
                else if (me->GetPositionX() >= 653.899f && me->GetPositionX() <= 653.906f)
                    DoCast(252628);
                else if (me->GetPositionX() >= 654.0201f && me->GetPositionX() <= 654.0215f)
                    DoCast(252628);
            }
      //  });
    }

    void JustReachedHome() override
    {
        if (me->GetZoneId() == 9128)
        {
            if (auto c = me->FindNearestCreature(125856, 10.0f))
                me->CastSpell(c, 252327, false);
        }
        else if (me->GetZoneId() == 9126)
            DoCast(252628);
    }

    void EnterCombat(Unit* /*who*/) override
    {
        Talk(0);
        events.ScheduleEvent(EVENT_1, 2000);
    }

    void JustDied(Unit* /*who*/) override
    {
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
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
            case EVENT_1:
                DoCast(253606);
                events.ScheduleEvent(EVENT_1, 7000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//126230
struct npc_crazed_corruptor : ScriptedAI
{
    npc_crazed_corruptor(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;
    ObjectGuid guid;

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_2, 2500);
        events.ScheduleEvent(EVENT_3, 3000);
        //me->RemoveAllAreaObjects();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        if (me->GetZoneId() == 9126)
            DoCast(251896);

        events.ScheduleEvent(EVENT_1, 2000);
    }

    void JustDied(Unit* /*who*/) override
    {
        //me->RemoveAllAreaObjects();

        if (auto target = ObjectAccessor::GetUnit(*me, guid))
        {
            target->CastSpell(target, 252699, false);
            target->ToCreature()->DespawnOrUnsummon(2000);
        }
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && me->IsInCombat())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(249747);
                events.ScheduleEvent(EVENT_1, 7000);
                break;
            case EVENT_2:
                if (auto c = me->FindNearestCreature(126293, 80.0f))
                    guid = c->GetGUID();
                break;
            case EVENT_3:
                if (auto target = ObjectAccessor::GetUnit(*me, guid))
                    DoCast(target, 252241, false);
                events.ScheduleEvent(EVENT_3, 16000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//124835
struct npc_magma_giant : ScriptedAI
{
    npc_magma_giant(Creature* creature) : ScriptedAI(creature), summons(me)
    {
        introDone = false;
        number = 0;
    }

    EventMap events;
    SummonList summons;
    uint32 number;
    bool introDone;

    void Reset() override
    {
        events.Reset();
        DoCast(251888);
        //me->RemoveAllAreaObjects();
        DespawnAllSummons();

        if (!introDone)
            me->AddUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
        else
            me->SetDisplayId(79099);

    }

    void JustReachedHome() override
    {
        if (introDone)
        {
            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
            me->SetDisplayId(79099);
            DoCast(251896);
            events.ScheduleEvent(EVENT_3, 1000);
        }
    }

    void EnterCombat(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_1, 18000);
        events.ScheduleEvent(EVENT_2, 3000);
    }

    void JustDied(Unit* /*who*/) override
    {
        //me->RemoveAllAreaObjects();
    }

    void EnterEvadeMode(EvadeReason Why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void JustSummoned(Creature* summon)
    {
        summons.Summon(summon);

        summon->CastSpell(summon, 252735, true);
    }

    void StartEvent()
    {
        me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
        DoCast(252790);
        DoCast(251896);

        introDone = true;
        me->SetHomePosition(663.905f, 623.85f, 40.26792f, 0.0f);
      //  me->AddDelayedEvent(2000, [=]() -> void
       // {
            me->GetMotionMaster()->MovePoint(1, 663.905f, 623.85f, 40.26792f);
     //   });
    }

    void MovementInform(uint32 type, uint32 data)
    {
        if (type == POINT_MOTION_TYPE)
        {
            if (data == 1)
                events.ScheduleEvent(EVENT_3, 1000);
        }
    }

    void DoAction(int32 const action) override
    {
        //switch (action)
        //{
      //  case ACTION_1:
            number++;

            if (number == 1)
            {
                if (me->GetPositionX() >= 715.79f && me->GetPositionX() <= 729.79f)
                    StartEvent();
            }
            if (number == 2)
            {
                if (me->GetPositionX() >= 730.9829f && me->GetPositionX() <= 735.9929f)
                    StartEvent();
            }
            if (number == 3)
            {
                if (me->GetPositionX() >= 650.615f && me->GetPositionX() <= 657.635f)
                    StartEvent();
            }
            if (number == 4)
            {
                if (me->GetPositionX() >= 589.9629f && me->GetPositionX() <= 595.9929f)
                    StartEvent();
            }
            if (number == 5)
            {
                if (me->GetPositionX() >= 629.623f && me->GetPositionX() <= 635.653f)
                    StartEvent();
            }
            //break;
        //default:
            //break;
        //}
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 127356, 200.0f);
        if (!list.empty())
            for (std::list<Creature*>::const_iterator itr = list.begin(); itr != list.end(); itr++)
                (*itr)->DespawnOrUnsummon();
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && me->IsInCombat())
            return;

       // if (CheckHomeDistToEvade(diff, 150.0f))
        //    return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_1:
                DoCast(252736);
                events.ScheduleEvent(EVENT_1, 20000);
                break;
            case EVENT_2:
                DoCast(252731);
                events.ScheduleEvent(EVENT_2, 6000);
                break;
            case EVENT_3:
                me->GetMotionMaster()->MoveRandom(15.0f);
                events.ScheduleEvent(EVENT_3, 7000);
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

//127378
struct npc_emblazoned_fire_tamer : ScriptedAI
{
    npc_emblazoned_fire_tamer(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
    //    me->AddDelayedEvent(3000, [=]() -> void { DoCast(252778); });
    }
};

//251888
class spell_fire_enchanted : public AuraScript
{
    PrepareAuraScript(spell_fire_enchanted);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
            caster->CastSpell(caster, 251891, false);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_fire_enchanted::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//252113
class spell_spore_filled : public AuraScript
{
    PrepareAuraScript(spell_spore_filled);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

       // if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
            caster->CastSpell(caster, 252120, false);
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_spore_filled::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//249391
class spell_cripple : public AuraScript
{
    PrepareAuraScript(spell_cripple);

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        target->RemoveAuraFromStack(249391);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_cripple::OnProc, EFFECT_0, SPELL_AURA_MELEE_SLOW);
    }
};

//248508
class spell_creeping_doom_argus_dummy : public SpellScript
{
    PrepareSpellScript(spell_creeping_doom_argus_dummy);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* object) {
            Unit* unit = object->ToUnit();
            if (!unit)
                return true;

            if (unit->IsPlayer() && unit->isMoving())
                return true;
            else
                return false;
        });
    }

    void HandleDummy(SpellEffIndex effIndex)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();
        if (!caster)
            return;
        if (!target)
            return;

   //     caster->CastSpellDuration(target, 248507, false, 0, 10);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_creeping_doom_argus_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_creeping_doom_argus_dummy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//248507
class spell_creeping_doom_argus : public AuraScript
{
    PrepareAuraScript(spell_creeping_doom_argus);

    void OnPeriodic(AuraEffect const*aurEff)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        if (target->IsPlayer())
        {
            if (Aura * aur = target->GetAura(248507))
            {
                if (target->isMoving())
                    target->RemoveAuraFromStack(248507);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_creeping_doom_argus::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};

//249257
class spell_narcolepsy : public AuraScript
{
    PrepareAuraScript(spell_narcolepsy);

    void OnPeriodic(AuraEffect const*aurEff)
    {
        Unit* target = GetTarget();
        if (!target)
            return;

        if (target->IsPlayer())
        {
            if (target->isMoving())
            {
                if (!target->HasAura(224090))
                    target->CastSpell(target, 224090, false);
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_narcolepsy::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

//249440
class spell_summon_explosive_orbs : public SpellScript
{
    PrepareSpellScript(spell_summon_explosive_orbs);

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        for (uint8 i = 0; i < 3; ++i)
            caster->CastSpell(caster, 249439, false);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_summon_explosive_orbs::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

//252470
class spell_destroying_ip_argus : public SpellScript
{
    PrepareSpellScript(spell_destroying_ip_argus);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        //if (auto anomaly = caster->FindNearestCreature(125856, 5.0f))
        //    anomaly->GetAI()->DoAction(ACTION_1);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_destroying_ip_argus::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//252320
class spell_destroying_argus_val : public SpellScript
{
    PrepareSpellScript(spell_destroying_argus_val);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

     //   if (auto anomaly = caster->FindNearestCreature(126446, 5.0f))
      //      anomaly->GetAI()->DoAction(ACTION_1);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_destroying_argus_val::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

struct Data
{
    uint32 Entry;
    Position Pos;
};

/*Data DataStep2_Zone_9128[] =
{
    { 125939,   { -1321.17f, 799.384f, 63.0559f, 3.39445f }},
    { 125939,   { -1441.34f, 757.934f, 62.4823f, 4.57599f }},
    { 125939,   { -1508.04f, 720.811f, 61.0926f, 0.464685f }},
    { 125939,   { -1366.44f, 752.663f, 62.605f, 2.48168f }},
    { 125939,   { -1333.87f, 736.024f, 60.828f, 1.70031f }},
    { 125970,   { -1363.52f, 712.21f, 64.1861f, 1.81572f }},
    { 125970,   { -1391.13f, 761.986f, 62.6062f, 2.76529f }},
    { 125197,   { -1353.62f, 704.002f, 66.6211f, 1.171f }},
    { 125197,   { -1345.48f, 813.102f, 61.1649f, 3.3129f }},
    { 125197,   { -1392.79f, 792.872f, 61.9965f, 1.51161f }},
    { 125755,   { -1365.26f, 744.2f, 62.7074f, 3.285f }},
    { 125755,   { -1377.77f, 806.203f, 61.9774f, 1.29514f }},
    { 125755,   { -1435.58f, 767.802f, 62.7637f, 0.531257f }},
    { 125757,   { -1329.76f, 739.024f, 60.6013f, 1.70031f }},
    { 125757,   { -1503.84f, 717.918f, 61.0346f, 0.464685f }},
    { 125779,   { -1383.61f, 726.965f, 60.9887f, 2.45969f }},
    { 125779,   { -1389.32f, 729.312f, 60.9944f, 4.8478f }},
    { 125781,   { -1376.74f, 730.68f, 61.092f, 2.45969f }},
    { 125781,   { -1369.18f, 700.104f, 66.2134f, 2.49794f }},
    { 125781,   { -1387.12f, 739.326f, 61.0833f, 1.24508f }},
    { 125781,   { -1394.99f, 736.049f, 61.0913f, 2.76945f }},
    { 125781,   { -1341.09f, 809.901f, 61.0929f, 5.27092f }},
    { 125781,   { -1397.4f, 785.753f, 61.6893f, 3.5971f }},
    { 125790,   { -1358.54f, 754.945f, 62.7668f, 2.48168f }},
    { 125790,   { -1335.8f, 769.854f, 62.658f, 4.02982f }},
    { 125790,   { -1384.41f, 801.901f, 62.0226f, 2.8456f }},
    { 125790,   { -1332.42f, 779.097f, 62.5055f, 1.38611f }},
    { 125790,   { -1507.25f, 726.816f, 61.2437f, 0.464685f }},
    { 125790,   { -1446.51f, 768.847f, 62.8523f, 2.80806f }},
    { 125790,   { -1339.27f, 738.736f, 60.9879f, 1.70031f }},
    { 125963,   { -1379.26f, 739.552f, 61.0573f, 2.00625f }},
    { 125963,   { -1350.81f, 742.938f, 63.007f, 1.4162f }},
    { 125963,   { -1357.74f, 700.985f, 66.9066f, 1.58901f }},
    { 125963,   { -1361.41f, 701.207f, 66.4137f, 1.59293f }}
};

Data DataStep2_Zone_9102[] =
{
    { 125958,   { -1832.91f, -1665.07f, 3.89259f, 1.82685f }},
    { 125958,   { -1837.31f, -1394.83f, 9.71673f, 1.84392f }},
    { 125958,   { -1765.11f, -1563.66f, 5.48917f, 2.61755f }},
    { 125958,   { -1815.45f, -1454.0f, 7.22429f, 3.82934f }},
    { 125958,   { -1884.57f, -1490.02f, 7.1204f, 3.63883f }},
    { 126595,   { -1793.67f, -1678.33f, -10.7889f, 1.90558f }},
    { 126595,   { -1835.91f, -1385.34f, 10.3231f, 4.44112f }},
    { 125931,   { -1759.67f, -1568.76f, 5.83333f, 2.56709f }},
    { 125931,   { -1831.86f, -1399.93f, 10.342f, 1.86665f }},
    { 125931,   { -1886.62f, -1497.98f, 7.32465f, 3.49314f }},
    { 125936,   { -1757.62f, -1560.8f, 6.21724f, 2.81381f }},
    { 125936,   { -1829.81f, -1391.97f, 10.3924f, 1.8929f }},
    { 125936,   { -1821.29f, -1666.95f, 2.44956f, 1.8929f }},
    { 125936,   { -1803.83f, -1455.88f, 8.42708f, 3.63883f }},
    { 125965,   { -1834.02f, -1672.68f, 3.8185f, 1.8087f }},
    { 125965,   { -1816.56f, -1461.61f, 6.75695f, 3.67065f }},
    { 125965,   { -1896.19f, -1488.15f, 8.09028f, 3.82934f }},
    { 125967,   { -1892.06f, -1492.88f, 7.42708f, 3.66634f }},
    { 125969,   { -1841.44f, -1390.09f, 10.1996f, 1.82685f }},
    { 125969,   { -1769.24f, -1558.93f, 5.61162f, 2.71734f }},
    { 125954,   { -1787.84f, -1529.0f, 5.16737f, 1.6378f }},
    { 125954,   { -1794.34f, -1585.34f, 2.40625f, 0.0f }},
    { 125865,   { -1811.32f, -1458.74f, 7.65649f, 3.66634f }},
    { 125865,   { -1828.78f, -1669.81f, 3.80392f, 1.84392f }}
};

Data DataStep1_Zone_9128[] =
{
    { 125197,   { -1481.54f, 730.55f, 61.0565f, 5.7227f  }},
    { 125197,   { -1338.61f, 774.339f, 62.4051f, 2.96509f }},
    { 125197,   { -1472.19f, 773.375f, 64.8954f, 3.50129f }},
    { 125779,   { -1289.04f, 777.116f, 61.5154f, 3.83427f }},
    { 125779,   { -1459.98f, 720.312f, 61.3231f, 1.90804f }},
    { 125781,   { -1341.42f, 789.941f, 61.1006f, 3.98867f }},
    { 125781,   { -1438.87f, 798.557f, 65.5051f, 3.98867f }},
    { 125781,   { -1334.52f, 824.891f, 62.6617f, 4.44229f }},
    { 125790,   { -1337.98f, 782.903f, 61.1799f, 3.98867f }},
    { 125790,   { -1435.42f, 791.517f, 64.618f, 3.98867f }},
    { 125874,   { -1481.61f, 759.531f, 61.0929f, 0.0f }},
    { 125874,   { -1340.55f, 815.09f, 61.0929f, 0.0f }},
    { 125874,   { -1476.31f, 728.295f, 61.0929f, 0.0f }},
    { 125874,   { -1390.27f, 734.366f, 61.0843f, 0.0f }},
    { 125874,   { -1292.07f, 772.887f, 60.9033f, 0.0f }},
    { 125874,   { -1437.1f, 728.604f, 61.0929f, 0.0f }},
    { 125874,   { -1413.73f, 775.76f, 61.091f, 0.0f }},
    { 125874,   { -1350.79f, 776.75f, 61.0929f, 0.0f }},
    { 125963,   { -1402.71f, 756.2f, 62.4175f, 2.43503f }},
    { 125963,   { -1381.34f, 767.542f, 62.3694f, 2.66044f }},
    { 125963,   { -1400.78f, 758.792f, 62.3271f, 3.69819f }},
    { 125963,   { -1363.3f, 748.41f, 62.7244f, 0.0f }},
    { 125963,   { -1369.11f, 746.969f, 62.4206f, 1.74777f }}
};

Data DataStep1_Zone_9127[] =
{
    { 125777,   { -4013.22f, 599.632f, 1.96098f, 1.83415f }},
    { 125777,   { -4069.94f, 566.516f, 3.22501f, 3.17406f }},
    { 125777,   { -4072.75f, 547.002f, 2.14367f, 2.76662f }},
    { 125777,   { -4008.52f, 564.335f, 0.822757f, 0.143869f }},
    { 125777,   { -4023.46f, 547.033f, -0.865039f, 0.846469f }},
    { 125777,   { -4039.59f, 604.415f, 2.88048f, 2.63445f }},
    { 125777,   { -4053.49f, 521.96f, 0.646413f, 2.76662f }},
    { 125777,   { -4137.58f, 648.206f, 15.8113f, 1.81154f }},
    { 125199,   { -4075.3f, 576.359f, 4.78812f, 0.0861575f }},
    { 125197,   { -4125.33f, 624.741f, 14.0953f, 5.75504f }},
    { 125199,   { -4122.19f, 629.45f, 14.0955f, 5.75387f }},
    { 125779,   { -4140.39f, 645.83f, 15.2386f, 0.91397f }},
    { 125777,   { -4017.18f, 552.096f, 0.0286142f, 3.17406f }},
    { 125779,   { -4087.78f, 627.578f, 12.4545f, 0.936147f }},
    { 125779,   { -4062.95f, 606.571f, 4.54217f, 1.76219f }},
    { 125779,   { -4018.92f, 603.852f, 3.65298f, 5.90642f }},
    { 125779,   { -4056.77f, 526.83f, 0.379433f, 4.85105f }},
    { 125779,   { -4039.83f, 536.715f, 0.0833333f, 5.75733f }},
    { 125779,   { -3988.91f, 592.125f, 0.175224f, 0.211624f }},
    { 125779,   { -4119.92f, 599.768f, 11.1501f, 3.72734f }},
    { 125781,   { -4083.08f, 622.703f, 10.0201f, 1.85899f }},
    { 125781,   { -4038.68f, 530.783f, 0.0833333f, 2.54279f }},
    { 125781,   { -4071.33f, 562.5f, 3.21215f, 3.02888f }},
    { 125781,   { -4068.84f, 611.74f, 5.39891f, 4.02166f }},
    { 125781,   { -4003.02f, 564.684f, 1.32897f, 2.71397f }},
    { 126446,   { -4089.83f, 597.958f, 7.27123f, 0.477128f }},
    { 126446,   { -4077.47f, 620.172f, 7.4616f, 4.9654f }},
    { 126446,   { -4085.96f, 630.073f, 12.278f, 4.12866f }},
    { 126446,   { -4120.88f, 604.517f, 12.3491f, 5.56478f }},
    { 126446,   { -4042.73f, 604.57f, 2.96107f, 0.477128f }},
    { 126446,   { -4074.57f, 547.91f, 2.72269f, 0.477128f }},
    { 126446,   { -4028.02f, 603.873f, 3.3963f, 0.477128f }},
    { 126446,   { -3994.57f, 596.189f, 0.916976f, 0.477128f }},
    { 126446,   { -3985.8f, 593.752f, 0.589902f, 3.6487f }},
    { 126446,   { -4026.27f, 544.654f, -1.19156f, 0.477128f }},
    { 126446,   { -4020.52f, 550.156f, -0.460265f, 2.60443f }},
    { 126446,   { -4056.6f, 523.347f, 0.379375f, 0.407602f }}
};

Data DataStep1_Zone_9100[] =
{
    { 125856,   { -4140.0f, -4828.33f, 113.182f, 0.0f }},
    { 125755,   { -4134.88f, -4824.49f, 109.761f, 3.39135f }},
    { 125758,   { -4118.87f, -4838.42f, 108.17f, 5.83203f }},
    { 125755,   { -4117.52f, -4936.5f, 112.05f, 5.08028f }},
    { 125199,   { -4116.52f, -4870.62f, 111.275f, 1.59584f }},
    { 125856,   { -4114.58f, -4939.57f, 115.303f, 0.0f }},
    { 125785,   { -4113.19f, -4919.31f, 109.803f, 3.72148f }},
    { 125197,   { -4111.73f, -4869.32f, 111.275f, 1.77626f }},
    { 125755,   { -4110.12f, -4943.81f, 112.246f, 2.3564f }},
    { 125758,   { -4109.33f, -4678.63f, 80.5449f, 5.83203f }},
    { 125856,   { -4108.19f, -4650.49f, 83.5449f, 0.0f }},
    { 125755,   { -4106.1f, -4645.4f, 80.5475f, 5.01445f }},
    { 125788,   { -4105.03f, -4841.63f, 107.964f, 5.76941f }},
    { 125785,   { -4103.16f, -4801.04f, 103.304f, 3.90489f }},
    { 125788,   { -4097.94f, -4938.06f, 109.803f, 1.60014f }},
    { 125785,   { -4095.45f, -4844.11f, 107.998f, 3.72148f }},
    { 125755,   { -4093.25f, -4704.79f, 80.5764f, 5.90167f }},
    { 125758,   { -4090.27f, -4706.67f, 80.5447f, 2.29212f }},
    { 125785,   { -4089.23f, -4661.72f, 80.5863f, 0.73815f }},
    { 125755,   { -4088.74f, -4689.77f, 80.5446f, 0.431894f }},
    { 125758,   { -4085.33f, -4688.9f, 80.5446f, 3.10553f }},
    { 125755,   { -4082.29f, -4869.53f, 112.942f, 6.11687f }},
    { 125788,   { -4080.13f, -4756.58f, 87.2224f, 4.92821f }},
    { 125856,   { -4076.22f, -4871.5f, 115.361f, 0.0f }},
    { 125758,   { -4070.73f, -4939.67f, 111.439f, 1.57379f }},
    { 125785,   { -4067.74f, -4752.88f, 84.9758f, 1.05213f }},
    { 125758,   { -4067.31f, -4876.58f, 112.254f, 2.25744f }},
    { 125199,   { -4061.05f, -4718.92f, 81.8143f, 3.8198f }},
    { 125197,   { -4056.78f, -4888.27f, 112.508f, 0.610699f }},
    { 125755,   { -4053.5f, -4676.5f, 80.5446f, 5.90167f }},
    { 125758,   { -4052.36f, -4614.46f, 80.595f, 4.19466f }},
    { 125758,   { -4050.51f, -4678.38f, 80.5446f, 2.29212f }},
    { 125758,   { -4048.02f, -4766.32f, 82.6039f, 3.41225f }},
    { 125788,   { -4047.2f, -4900.65f, 112.656f, 1.0527f }},
    { 125758,   { -4034.31f, -4944.09f, 121.343f, 1.98536f }},
    { 125856,   { -4029.94f, -4645.58f, 83.7087f, 0.0f }},
    { 125856,   { -4028.64f, -4704.34f, 82.6397f, 0.0f }},
    { 125755,   { -4026.86f, -4650.54f, 80.5446f, 1.8397f }},
    { 125755,   { -4024.68f, -4909.46f, 115.722f, 0.939778f }},
    { 125755,   { -4023.15f, -4702.3f, 80.5533f, 3.80528f }},
    { 125856,   { -4022.87f, -4906.04f, 118.622f, 0.0f }},
    { 125755,   { -4013.5f, -4648.92f, 80.7292f, 5.90167f }},
    { 125758,   { -4013.41f, -4672.1f, 80.5729f, 2.99014f }},
    { 125758,   { -4010.51f, -4650.79f, 80.8229f, 2.29212f }},
    { 125788,   { -4005.66f, -4938.23f, 118.996f, 2.12258f }},
    { 125197,   { -4004.13f, -4964.08f, 123.935f, 1.7181f }},
    { 125199,   { -3997.51f, -4961.69f, 123.935f, 1.62531f }},
    { 125755,   { -3996.06f, -4990.18f, 130.895f, 5.52614f }},
    { 125856,   { -3991.85f, -4992.97f, 133.341f, 0.330515f }},
    { 125758,   { -3991.04f, -4952.26f, 122.097f, 0.177986f }}
};

Data DataStep1_Zone_9102[] =
{
    { 125197,   { -1892.44f, -1543.11f, 5.32667f, 1.91579f }},
    { 126231,   { -1822.38f, -1529.16f, 0.993233f, 2.51429f }},
    { 126231,   { -1829.97f, -1473.76f, 3.45083f, 5.9775f }},
    { 126231,   { -1777.88f, -1516.96f, 6.69483f, 6.25191f }},
    { 126231,   { -1803.61f, -1518.68f, 3.92393f, 0.548457f }},
    { 126231,   { -1875.05f, -1573.73f, 2.24553f, 3.79317f }},
    { 126231,   { -1782.93f, -1533.8f, 4.70316f, 2.1415f }},
    { 126231,   { -1864.06f, -1526.85f, 3.34974f, 0.0989199f }},
    { 126231,   { -1885.95f, -1464.1f, 7.96435f, 2.92736f }},
    { 126231,   { -1780.19f, -1585.38f, 3.27826f, 5.05126f }},
    { 125745,   { -1782.23f, -1494.51f, 5.13094f, 0.87731f }},
    { 125776,   { -1830.38f, -1425.03f, 26.1867f, 2.20402f }},
    { 125776,   { -1814.74f, -1383.61f, 46.0185f, 3.41532f }},
    { 125776,   { -1797.88f, -1652.82f, 2.41725f, 4.84935f }},
    { 125776,   { -1808.96f, -1663.29f, 0.0110608f, 5.71599f }},
    { 125776,   { -1818.19f, -1680.55f, 3.48233f, 0.355135f }},
    { 125777,   { -1873.04f, -1426.55f, 42.0778f, 1.0122f }},
    { 125199,   { -1819.55f, -1472.04f, 6.64193f, 3.2989f }},
    { 125776,   { -1823.78f, -1419.27f, 26.5602f, 2.43368f }},
    { 125759,   { -1886.79f, -1541.08f, 5.32667f, 1.91553f }},
    { 125758,   { -1818.49f, -1466.14f, 6.64193f, 2.72022f }},
    { 125755,   { -1788.88f, -1578.64f, 2.79053f, 0.0f }},
    { 125755,   { -1776.5f, -1546.5f, 4.62242f, 4.79576f }},
    { 125755,   { -1824.82f, -1468.04f, 4.6876f, 2.96488f }},
    { 125745,   { -1807.6f, -1470.66f, 7.15369f, 0.0f }},
    { 125745,   { -1877.94f, -1488.66f, 5.61963f, 0.0f }},
    { 125745,   { -1846.29f, -1563.71f, 0.28832f, 0.0f }},
    { 125745,   { -1787.6f, -1532.76f, 4.5912f, 2.74711f }},
    { 125745,   { -1784.19f, -1532.38f, 4.84681f, 1.77203f }},
    { 125745,   { -1793.37f, -1493.75f, 4.32357f, 5.94308f }},
    { 125777,   { -1777.28f, -1648.51f, 2.22263f, 4.06045f }},
    { 125777,   { -1894.55f, -1528.39f, 6.67505f, 1.9154f }},
    { 125921,   { -1804.77f, -1503.05f, 3.12494f, 0.821999f }},
    { 125921,   { -1804.65f, -1468.7f, 7.56578f, 0.0880074f }},
    { 125921,   { -1880.4f, -1465.83f, 8.21079f, 0.116475f }},
    { 125921,   { -1782.56f, -1543.47f, 3.58306f, 4.03499f }},
    { 125921,   { -1873.0f, -1525.91f, 3.73364f, 5.95711f }},
    { 125921,   { -1794.15f, -1589.17f, 2.29634f, 1.83001f }},
    { 125921,   { -1877.7f, -1594.47f, 1.65048f, 0.741228f }},
    { 125921,   { -1800.78f, -1499.18f, 3.25511f, 0.0f }},
    { 125921,   { -1790.13f, -1546.48f, 2.47708f, 0.0f }},
    { 125921,   { -1839.78f, -1473.58f, 3.6995f, 0.0f }},
    { 126231,   { -1863.59f, -1465.81f, 6.0507f, 3.85185f }},
    { 126231,   { -1897.3f, -1495.75f, 7.38414f, 3.67065f }},
    { 126231,   { -1770.35f, -1566.53f, 4.65278f, 2.40061f }}
};

Data DataStep2_Zone_9180[] =
{
    { 127982,   { -3771.69f, -7890.97f, 0.541121f, 0.958083f }},
    { 127982,   { -3703.45f, -8026.82f, 3.06202f, 3.02327f }},
    { 127982,   { -3843.54f, -8024.73f, 1.96556f, 1.41499f }},
    { 127982,   { -3706.81f, -8093.56f, 0.984805f, 1.47862f }},
    { 127982,   { -3753.17f, -7920.41f, 0.973486f, 4.77218f }},
    { 127982,   { -3681.07f, -7944.44f, 1.08348f, 4.00472f }},
    { 127982,   { -3770.63f, -8024.54f, 1.28108f, 1.03137f }},
    { 127982,   { -3808.82f, -8002.55f, 1.3943f, 5.98331f }},
    { 127982,   { -3642.42f, -8058.29f, 6.20896f, 0.958083f }},
    { 127982,   { -3620.74f, -7994.13f, 3.43647f, 0.728563f }},
    { 127982,   { -3797.47f, -8093.29f, 4.03895f, 0.958083f }},
    { 127982,   { -3851.01f, -7995.4f, 2.02806f, 4.81012f }}
};

Data DataStep1_Zone_9180[] =
{
    { 125745,   { -3751.78f, -7954.73f, 1.26963f, 1.69554f }},
    { 125745,   { -3806.94f, -8143.03f, 9.65898f, 1.69554f }},
    { 125745,   { -3718.72f, -7899.77f, 1.31142f, 1.69554f }},
    { 125745,   { -3839.79f, -7943.28f, 3.06444f, 1.69554f }},
    { 125745,   { -3643.78f, -7981.53f, 1.62641f, 1.69554f }},
    { 125745,   { -3660.64f, -8018.65f, 1.34445f, 1.69554f }},
    { 125745,   { -3724.05f, -8089.34f, 0.397029f, 1.69554f }},
    { 125745,   { -3822.91f, -8057.69f, 0.692964f, 1.69554f }},
    { 125745,   { -3691.1f, -8127.75f, 0.835321f, 1.69554f }},
    { 125759,   { -3634.6f, -7969.19f, 0.981406f, 1.69554f }},
    { 125759,   { -3709.54f, -7887.42f, 0.954128f, 1.69554f }},
    { 125759,   { -3830.62f, -7930.93f, 1.40659f, 1.69554f }},
    { 125759,   { -3742.6f, -7942.38f, 1.18481f, 1.69554f }},
    { 125759,   { -3651.46f, -8006.31f, 2.10221f, 1.69554f }},
    { 125759,   { -3714.88f, -8077.0f, 0.964969f, 1.69554f }},
    { 125759,   { -3813.73f, -8045.34f, 0.985187f, 1.69554f }},
    { 125759,   { -3797.77f, -8130.68f, 8.07637f, 1.69554f }},
    { 125759,   { -3681.92f, -8115.4f, 0.595555f, 1.69554f }},
    { 125776,   { -3716.62f, -7885.29f, 0.660708f, 1.69554f }},
    { 125776,   { -3837.7f, -7928.79f, 1.56191f, 1.69554f }},
    { 125776,   { -3641.68f, -7967.05f, 0.964036f, 1.69554f }},
    { 125776,   { -3749.68f, -7940.25f, 1.80889f, 1.69554f }},
    { 125776,   { -3658.54f, -8004.17f, 2.32923f, 1.69554f }},
    { 125776,   { -3820.81f, -8043.2f, 0.91785f, 1.69554f }},
    { 125776,   { -3721.96f, -8074.86f, 1.70118f, 1.69554f }},
    { 125776,   { -3804.85f, -8128.54f, 8.44048f, 1.69554f }},
    { 125776,   { -3689.0f, -8113.26f, 0.371085f, 1.69554f }},
    { 125788,   { -3739.49f, -8123.55f, 8.83642f, 1.69554f }},
    { 125788,   { -3689.57f, -7943.58f, 1.07113f, 1.50451f }},
    { 125788,   { -3739.49f, -8123.55f, 8.83642f, 1.69554f }},
    { 125788,   { -3685.67f, -8047.56f, 3.87407f, 6.17923f }},
    { 125788,   { -3810.14f, -7976.9f, 0.904133f, 1.69554f }},
    { 125788,   { -3789.13f, -8043.35f, 1.43936f, 1.69554f }},
    { 125921,   { -3741.59f, -8138.04f, 9.75712f, 1.69554f }},
    { 125921,   { -3692.82f, -7956.48f, 2.03469f, 1.69554f }},
    { 125921,   { -3693.86f, -8059.61f, 2.90874f, 1.04407f }},
    { 125921,   { -3812.23f, -7991.38f, 1.02781f, 1.69554f }},
    { 125921,   { -3791.22f, -8057.83f, 1.26262f, 1.69554f }},
    { 125921,   { -3741.59f, -8138.04f, 9.75712f, 1.69554f }},
    { 125921,   { -3648.02f, -8066.03f, 4.44978f, 0.958083f }},
    { 125921,   { -3753.92f, -7927.52f, 1.15309f, 4.77218f }},
    { 125921,   { -3673.79f, -7953.3f, 1.09892f, 4.00472f }},
    { 125921,   { -3853.46f, -7963.94f, 2.16722f, 4.84345f }},
    { 125921,   { -3856.69f, -7948.18f, 2.9431f, 1.19558f }},
    { 125921,   { -3791.4f, -8090.53f, 3.84092f, 0.958083f }},
    { 125921,   { -3802.13f, -8087.07f, 3.67844f, 0.958083f }},
    { 125921,   { -3745.02f, -7924.24f, 1.15856f, 4.77218f }},
    { 125921,   { -3704.97f, -8019.35f, 2.00811f, 3.02327f }},
    { 125921,   { -3807.31f, -8005.72f, 1.49747f, 5.98331f }},
    { 125921,   { -3705.72f, -8034.42f, 3.54202f, 3.02327f }},
    { 125921,   { -3773.72f, -7894.47f, 0.740425f, 0.958083f }},
    { 125921,   { -3647.08f, -8052.74f, 5.8689f, 0.958083f }},
    { 125921,   { -3689.52f, -7948.12f, 1.61595f, 4.00472f }},
    { 125921,   { -3758.31f, -7900.56f, 0.703697f, 0.958083f }},
    { 125921,   { -3800.7f, -7999.83f, 1.98858f, 5.98331f }},
    { 125931,   { -3626.08f, -7990.84f, 2.81967f, 6.25366f }},
    { 125931,   { -3706.37f, -8085.0f, 0.774656f, 4.68804f }},
    { 125931,   { -3770.66f, -8014.77f, 2.24178f, 5.20638f }},
    { 125931,   { -3696.86f, -8092.07f, 0.474696f, 2.9543f }},
    { 125931,   { -3617.84f, -7985.1f, 3.30404f, 4.79594f }},
    { 125931,   { -3763.75f, -8024.19f, 1.33513f, 2.33975f }},
    { 125931,   { -3834.42f, -8017.04f, 1.7238f, 3.30909f }},
    { 125931,   { -3631.15f, -7990.68f, 2.14427f, 6.25282f }},
    { 125931,   { -3779.27f, -8016.56f, 0.969664f, 5.99575f }},
    { 125931,   { -3848.68f, -8011.7f, 2.15514f, 5.45174f }},
    { 125931,   { -3700.56f, -8088.89f, 0.525755f, 3.36557f }},
    { 125931,   { -3835.25f, -8024.02f, 1.23502f, 2.48679f }},
    { 125931,   { -3626.92f, -7998.76f, 3.32479f, 0.674299f }},
    { 125931,   { -3766.78f, -8016.99f, 2.15241f, 4.3551f }},
    { 125931,   { -3714.64f, -8091.06f, 0.499204f, 0.100135f }},
    { 125931,   { -3850.45f, -8018.75f, 2.61543f, 0.0426431f }},
    { 125931,   { -3843.27f, -8013.65f, 1.91312f, 4.86127f }},
    { 125931,   { -3625.11f, -7985.19f, 2.77691f, 5.63378f }},
    { 125931,   { -3765.35f, -8030.96f, 0.996618f, 1.79623f }},
    { 125931,   { -3714.9f, -8093.45f, 0.489974f, 0.365248f }},
    { 125936,   { -3682.4f, -7949.38f, 1.07113f, 1.44775f }},
    { 125936,   { -3803.05f, -7979.04f, 0.690251f, 1.69554f }},
    { 125936,   { -3782.04f, -8045.48f, 0.827134f, 1.69554f }},
    { 125936,   { -3732.41f, -8125.69f, 11.2171f, 1.69554f }},
    { 125936,   { -3681.65f, -8053.94f, 3.46416f, 5.39127f }},
    { 125936,   { -3732.41f, -8125.69f, 11.2171f, 1.69554f }}
};

Data DataStep2_Zone_9126[] =
{
    { 125197,   { 669.986f, 619.545f, 40.4531f, 0.0f }},
    { 125199,   { 662.135f, 627.195f, 40.3129f, 0.0f }},
    { 125757,   { 673.507f, 627.733f, 40.3281f, 0.0f }},
    { 125779,   { 633.523f, 580.142f, 40.6267f, 0.763893f }},
    { 125788,   { 638.934f, 577.941f, 40.6173f, 0.763893f }},
    { 125790,   { 641.021f, 661.899f, 40.4555f, 5.51811f }},
    { 125931,   { 663.691f, 606.424f, 40.8854f, 1.45404f }},
    { 125931,   { 663.892f, 616.399f, 40.5347f, 4.74007f }},
    { 125933,   { 627.971f, 578.038f, 40.5434f, 0.763893f }},
    { 125938,   { 642.07f, 587.462f, 40.3332f, 5.0922f }},
    { 125938,   { 666.701f, 569.904f, 40.3914f, 4.15f }},
    { 125939,   { 652.134f, 660.111f, 40.8004f, 3.4526f }},
    { 125964,   { 668.938f, 611.635f, 40.6822f, 3.52251f }}
};

Data DataStep1_Zone_9126[] =
{
    { 124835,   { 655.635f, 536.521f, 36.1326f, 5.04064f }},
    { 124835,   { 719.792f, 663.938f, 37.2122f, 6.24573f }},
    { 124835,   { 592.993f, 598.58f, 36.0851f, 2.13949f }},
    { 124835,   { 632.653f, 677.323f, 37.6201f, 2.11126f }},
    { 124835,   { 733.993f, 576.927f, 36.2361f, 3.51348f }},
    { 125197,   { 653.903f, 607.91f, 40.8136f, 5.36333f }},
    { 125197,   { 673.219f, 629.562f, 40.3021f, 5.36333f }},
    { 125197,   { 643.927f, 588.203f, 41.3332f, 5.0922f }},
    { 125197,   { 666.473f, 573.292f, 41.3914f, 4.14843f }},
    { 125197,   { 674.038f, 609.627f, 40.6892f, 5.36333f }},
    { 125197,   { 700.1f, 602.5f, 41.6867f, 4.54583f }},
    { 125197,   { 654.021f, 629.811f, 40.3876f, 5.36333f }},
    { 125199,   { 696.156f, 603.166f, 41.6867f, 4.54464f }},
    { 125757,   { 697.59f, 599.649f, 40.7664f, 4.54518f }},
    { 125936,   { 640.212f, 586.72f, 41.3332f, 5.09222f }},
    { 125936,   { 669.857f, 571.16f, 41.3914f, 4.15121f }},
    { 126230,   { 626.816f, 652.061f, 40.5954f, 0.79289f }},
    { 126230,   { 714.865f, 601.373f, 40.3334f, 5.2708f }},
    { 126230,   { 616.885f, 638.351f, 41.2133f, 1.56092f }},
    { 126230,   { 631.689f, 572.878f, 40.5338f, 4.10148f }},
    { 126230,   { 668.877f, 558.54f, 40.1502f, 4.71227f }},
    { 126230,   { 656.172f, 664.952f, 40.9267f, 0.455596f }},
    { 126230,   { 620.102f, 608.983f, 41.1812f, 3.36707f }},
    { 126230,   { 706.16f, 646.648f, 39.9241f, 0.751072f }},
    { 126293,   { 626.532f, 717.115f, 49.2053f, 5.25205f }},
    { 126293,   { 583.554f, 694.499f, 48.0843f, 5.49944f }},
    { 126293,   { 597.266f, 523.721f, 48.0618f, 0.965623f }},
    { 126293,   { 746.654f, 550.488f, 47.8118f, 2.46084f }},
    { 126293,   { 559.57f, 663.805f, 48.4048f, 5.8689f }},
    { 126293,   { 749.981f, 687.559f, 47.4518f, 3.81194f }},
    { 126293,   { 558.613f, 593.245f, 48.7298f, 0.237159f }},
    { 126293,   { 668.87f, 498.5f, 47.6778f, 1.62157f }},
    { 126825,   { 663.927f, 620.938f, 76.7553f, 0.0f }},
    { 126826,   { 593.316f, 558.342f, 36.083f, 0.0f }},
    { 126826,   { 645.641f, 704.411f, 36.1204f, 0.0f }},
    { 126826,   { 726.115f, 678.429f, 37.2122f, 0.0f }},
    { 126826,   { 735.208f, 636.382f, 37.2122f, 0.0f }},
    { 126826,   { 620.292f, 536.042f, 36.083f, 0.0f }},
    { 126826,   { 679.505f, 518.267f, 36.0832f, 0.0f }},
    { 126826,   { 758.337f, 577.945f, 36.0642f, 0.0f }},
    { 126826,   { 566.609f, 618.719f, 36.083f, 0.0f }},
    { 126826,   { 620.292f, 536.042f, 36.083f, 0.0f }},
    { 126826,   { 577.597f, 666.165f, 36.083f, 0.0f }},
    { 127257,   { 742.776f, 618.422f, 65.3952f, 0.0547515f }},
    { 127378,   { 669.271f, 496.943f, 44.8655f, 1.92554f }},
    { 127378,   { 600.512f, 730.573f, 40.8968f, 5.25528f }},
    { 127378,   { 555.432f, 656.776f, 40.4991f, 5.35873f }},
    { 127378,   { 743.488f, 662.557f, 44.2912f, 3.04197f }},
    { 127378,   { 718.802f, 570.46f, 43.4094f, 0.343917f }},
    { 127404,   { 664.368f, 620.438f, 72.6862f, 0.0f }}
};
*/
std::map<uint32, std::vector<uint32>> zonesByEvents {
    { 180,  { 9126 }},
    { 181,  { 9127 }},
    { 182,  { 9180 }},
    { 183,  { 9100 }},
    { 184,  { 9102 }},
    { 185,  { 9127 }},
    { 186,  { 9126 }},
    { 187,  { 9128 }},
    { 188,  { 9100 }},
    { 189,  { 9180 }},
    { 190,  { 9102 }},
    { 191,  { 9128 }}
};
/*
uint32 ListBossIds[13] = { 125666, 125527, 125655, 125148, 125634, 125252, 125137, 125280, 125587, 125272, 125483, 125578, 125314 };

class OutdoorPVPArgusInvasion : public OutdoorPvP
{
public:
    OutdoorPVPArgusInvasion()
    {
    //    m_TypeId = OUTDOOR_PVP_ARGUS_INVASION;
    }

    ~OutdoorPVPArgusInvasion()
    {
   //     for (auto& pair : m_scenarios)
  //          delete pair.second;
    }

    bool SetupOutdoorPvP() override
    {
        for (auto zone : { 9126, 9102, 9100, 9180, 9127, 9128 })
            RegisterZone(zone);

        return true;
    }*/
/*
    void Initialize(uint32 zoneId) 
    {
      //  if (m_scenarios.find(zoneId) != m_scenarios.end())
      //      return;

        uint32 scenarioId = 0;
        switch (zoneId)
        {
        case 9126:
            scenarioId = 1404;
            break;
        case 9102:
            scenarioId = 1411;
            break;
        case 9100:
            scenarioId = 1391;
            break;
        case 9180:
            scenarioId = 1409;
            break;
        case 9127:
            scenarioId = 1406;
            break;
        case 9128:
            scenarioId = 1394;
            break;
        }
        */
     /*   if (scenarioId)
        {
        //    //m_scenarios[zoneid] = new Scenario(m_map, scenarioId);
       //     //m_scenarios[zoneid]->SetOutdoorPvP(this, zoneId);

         //   if (!m_players[zoneId].empty())
          //      //m_scenarios[zoneid]->SetCurrentStep(0);

        //    m_justInitialized[zoneId] = !m_players[zoneId].empty();

          //  for (auto& guid : m_players[zoneId])
          //      if (Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr))
           //         //m_scenarios[zoneid]->SendStepUpdate(player, true);
        }*/
  //  }
    /*
    void HandlePlayerEnterZone(ObjectGuid guid, uint32 zone) //override
    {
      //  OutdoorPvP::HandlePlayerEnterZone(guid, zone);

      //  Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr);
       // if (!player)
       //     return;

        uint32 questId = 0;
        uint32 eventid1 = 0, eventid2 = 0;

        switch (zone)
        {
        case 9126:
            eventid1 = 180;
            eventid2 = 186;
            questId = 49098;
            break;
        case 9102:
            eventid1 = 184;
            eventid2 = 190;
            questId = 49096;
            break;
        case 9100:
            eventid1 = 183;
            eventid2 = 188;
            questId = 48982;
            break;
        case 9180:
            eventid1 = 182;
            eventid2 = 189;
            questId = 49099;
            break;
        case 9127:
            eventid1 = 181;
            eventid2 = 185;
            questId = 49091;
            break;
        case 9128:
            eventid1 = 187;
            eventid2 = 191;
            questId = 49097;
            break;
        }

      /*  if (questId && player->WorldQuestCompleted(questId) && !player->IsGameMaster())
            player->CastSpell(player, 247069, false);

        if (eventid1 && eventid2)
            if (!sGameEventMgr->IsActiveEvent(eventid1) && !sGameEventMgr->IsActiveEvent(eventid2))
                player->CastSpell(player, 210818, false);*/

      //  if (m_scenarios.find(zone) == m_scenarios.end())
      //      return;

      //  if (!m_justInitialized[zone])
     //   {
     //       m_justInitialized[zone] = true;
         //   m_scenarios[zone]->SetCurrentStep(0);
     //   }
        
  /*    //  m_scenarios[zone]->SendStepUpdate(player, true);
        m_players[zone].insert(guid);
    }

    void HandlePlayerLeaveZone(ObjectGuid guid, uint32 zone) //override
    {*/
      //  OutdoorPvP::HandlePlayerLeaveZone(guid, zone);
     ////   Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr);
      //  if (!player)
     //       return;

  /*      m_players[zone].erase(guid);

      //  if (m_players[zone].empty())
       //     m_timersPerZone[zone] = 1;
    }

    void HandleKill(Player* killer, Unit* killed) override
    {
        if (!killer || !killed)
            return;*/

      //  if (m_scenarios.find(killer->GetZoneId()) == m_scenarios.end())
      //      return;
/*
        if (m_players[killer->GetZoneId()].find(killer->GetGUID()) == m_players[killer->GetZoneId()].end())
            return;

        uint32 zoneid = killed->GetZoneId();
        uint32 criteria = 0;
        */
    /*    switch (killed->GetEntry())
        {
        case 125785:
        case 125758:
        case 125777:
        case 125199:
        case 125197:
            switch (zoneid)
            {
            case 9102:
            case 9100:
            case 9127:
           //     //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 6, 0, nullptr, killer);
                break;
            case 9180:
           //     //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 9, 0, nullptr, killer);
                break;
            case 9128:
            //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 18, 0, nullptr, killer);
                break;
            }
            break;
        case 125666:
        case 125527:
        case 125655:
        case 125148:
        case 125634:
        case 125252:
        case 125137:
        case 125280:
        case 125587:
        case 125272:
        case 125483:
        case 125578:
        case 125314:
            criteria = 59372;
            break;
        case 125856:
        case 126446:
            criteria = 59346;
            break;
        case 126231:
        //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 19, 0, nullptr, killer);
            break;
        case 125921:
        case 125755:
            switch (zoneid)
            {
            case 9128:
            case 9102:
          //      //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 3, 0, nullptr, killer);
                break;
            case 9100:
            //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 5, 0, nullptr, killer);
                break;
            }
            break;
        case 125936:
            switch (zoneid)
            {
            case 9128:
            case 9102:
            //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 3, 0, nullptr, killer);
                break;
            case 9100:
             //   //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 12, 0, nullptr, killer);
                break;
            }
            break;
        case 125759:
            switch (zoneid)
            {
            case 9102:
            //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 4, 0, nullptr, killer);
                break;
            case 9180:
            //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 7, 0, nullptr, killer);
                break;
            }
            break;
        case 125776:
            switch (zoneid)
            {
            case 9102:
            //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 6, 0, nullptr, killer);
                break;
            case 9180:
             //   //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 5, 0, nullptr, killer);
                break;
            }
            break;
        case 125745:
            switch (zoneid)
            {
            case 9102:
            //    //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 6, 0, nullptr, killer);
                break;
            case 9180:
           //     //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 7, 0, nullptr, killer);
                break;
            }
            break;
        case 125788:
            switch (zoneid)
            {
            case 9102:
            case 9100:
            case 9127:
             //   //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 6, 0, nullptr, killer);
                break;
            case 9180:
             //   //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 5, 0, nullptr, killer);
                break;
            case 9128:
             //   //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 18, 0, nullptr, killer);
                break;
            }
            break;
        case 125958:
            //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_KILL_CREATURE, 125958, 1, 0, nullptr, killer);
            break;
        case 127982:
            //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_KILL_CREATURE, 127982, 1, 0, nullptr, killer);
            break;
        case 124835:
     //   {
            //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_KILL_CREATURE, 126371, 1, 0, nullptr, killer);

         //   for (auto& guid : m_creatures[zoneid])
          //  {
              //  if (Creature* cre = ObjectAccessor::GetObjectInMap(guid, m_map, (Creature*)nullptr))
              //  {
                 //   if (cre->GetEntry() == 124835)
                  //      cre->GetAI()->DoAction(ACTION_1);
              //  }
          //  }
            break;
    //    }
        case 125874:
            criteria = 59752;
            break;
        case 125781:
        case 125790:
        case 125963:
            switch (zoneid)
            {
            case 9128:
                //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 9, 0, nullptr, killer);
            case 9102:
            case 9127:
                //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 6, 0, nullptr, killer);
                break;
            }
            break;
        case 125970:
            //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 28, 0, nullptr, killer);
            break;
        case 125939:
            //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 22, 0, nullptr, killer);
            break;
        case 125779:
            switch (zoneid)
            {
            case 9128:
                //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 13, 0, nullptr, killer);
                break;
            case 9127:
                //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 59201, 6, 0, nullptr, killer);
                break;
            }
            break;
        case 126230:
            criteria = 60406;
            break;
        default:
            break;
        }*/

      //  if (criteria)
            //m_scenarios[zoneid]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, criteria, 0, 0, nullptr, killer);
   // }

   /* void HandleSpellClick(Player* player, Unit* target)// override
    {
        if (!player || !target)
            return;

        if (m_scenarios.find(player->GetZoneId()) == m_scenarios.end())
            return;

        if (m_players[player->GetZoneId()].find(player->GetGUID()) == m_players[player->GetZoneId()].end())
            return;

        uint32 criteria = 0;
        //switch (target->GetEntry()) {}

      //  if (criteria)
      //      m_scenarios[player->GetZoneId()]->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, criteria, 0, 0, nullptr, player);
    }

    void BroadcastPacketByZone(const WorldPacket & data, uint32 zone) //override
    {
        if (m_players.find(zone) == m_players.end())
            return;

     //   for (auto& guid : m_players[zone])
     //     //  if (Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr))
           //     player->SendDirectMessage(&data);
    }

    void ApplyOnEveryPlayerInZone(std::function<void(Player*)> function, uint32 zone) //override
    {
        if (m_players.find(zone) == m_players.end())
            return;

        /*for (auto& guid : m_players[zone])
            if (Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr))
                function(player);
    }

    void SetData(uint32 zone, uint32 step) override
    {
        if (step == 100)
        {
            /*for (auto& guid : m_creatures[zone])
                if (Creature* cre = ObjectAccessor::GetObjectInMap(guid, m_map, (Creature*)nullptr))
                    cre->DespawnOrUnsummon();

         //   m_timersPerZone[zone] = 20 * IN_MILLISECONDS;
            return;
        }

        if (step == 0)
        {
            for (auto& guid : m_creatures[zone])
            {
              //  if (Creature* cre = ObjectAccessor::GetObjectInMap(guid, m_map, (Creature*)nullptr))
              //  {
                    switch (zone)
                    {
                    case 9102:
                        if (cre->GetEntry() == 126231)
                        {
                            if (auto c = cre->FindNearestCreature(127131, 20.0f))
                            {
                                float orientation = c->GetOrientation();
                                cre->SetOrientation(orientation);
                                cre->AddDelayedEvent(1000, [=]() -> void { cre->CastSpell(c, 252310, false); });
                            }
                        }
                        break;
                    }
                }
            }

            switch (zone)
            {
            case 9126:
                if (sGameEventMgr->IsActiveEvent(180) || sGameEventMgr->IsActiveEvent(186))
                {
                    for (auto x : DataStep1_Zone_9126)
                    {
                        if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                        {
                            m_creatures[zone].push_back(creature->GetGUID());
                            creature->CastSpell(creature, 251298, false);
                        }
                    }
                }
                break;
            case 9102:
                if (sGameEventMgr->IsActiveEvent(184) || sGameEventMgr->IsActiveEvent(190))
                {
                    for (auto x : DataStep1_Zone_9102)
                    {
                        if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                        {
                            m_creatures[zone].push_back(creature->GetGUID());
                            creature->CastSpell(creature, 251298, false);
                        }
                    }
                }
                break;
            case 9100:
                if (sGameEventMgr->IsActiveEvent(183) || sGameEventMgr->IsActiveEvent(188))
                {
                    for (auto x : DataStep1_Zone_9100)
                    {
                        if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                        {
                            m_creatures[zone].push_back(creature->GetGUID());
                            creature->CastSpell(creature, 251298, false);
                        }
                    }
                }
                break;
            case 9180:
                if (sGameEventMgr->IsActiveEvent(182) || sGameEventMgr->IsActiveEvent(189))
                {
                    for (auto x : DataStep1_Zone_9180)
                    {
                        if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                        {
                            m_creatures[zone].push_back(creature->GetGUID());
                            creature->CastSpell(creature, 251298, false);
                        }
                    }
                }
                break;
            case 9127:
                if (sGameEventMgr->IsActiveEvent(181) || sGameEventMgr->IsActiveEvent(185))
                {
                    for (auto& guid : m_players[zone])
                        if (Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr))
                            player->CastSpell(player, 251005, false);

                    for (auto x : DataStep1_Zone_9127)
                    {
                        if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                        {
                            m_creatures[zone].push_back(creature->GetGUID());
                            creature->CastSpell(creature, 251298, false);
                        }
                    }
                }
                break;
            case 9128:
                if (sGameEventMgr->IsActiveEvent(187) || sGameEventMgr->IsActiveEvent(191))
                {
                    for (auto x : DataStep1_Zone_9128)
                    {
                        if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                        {
                            m_creatures[zone].push_back(creature->GetGUID());
                            creature->CastSpell(creature, 251298, false);
                        }
                    }
                }
                break;
            }
        }

        if (step == 1)
        {
            for (auto& guid : m_players[zone])
            {
                if (Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr))
                {
                    switch (zone)
                    {
                    case 9100:
                        player->CastSpell(player, 251004, false);
                        break;
                    case 9180:
                    case 9102:
                        player->CastSpell(player, 251005, false);
                        break;
                    case 9128:
                    case 9126:
                        player->CastSpell(player, 251006, false);
                        break;
                    }
                }
            }

            switch (zone)
            {
            case 9126:
                for (auto x : DataStep2_Zone_9126)
                {
                    if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                    {
                        m_creatures[zone].push_back(creature->GetGUID());
                        creature->CastSpell(creature, 251298, false);
                    }
                }
                break;
            case 9102:
                for (auto x : DataStep2_Zone_9102)
                {
                    if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                    {
                        m_creatures[zone].push_back(creature->GetGUID());
                        creature->CastSpell(creature, 251298, false);
                    }
                }
                break;
            case 9180:
                for (auto x : DataStep2_Zone_9180)
                {
                    if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                    {
                        m_creatures[zone].push_back(creature->GetGUID());
                        creature->CastSpell(creature, 251298, false);
                    }
                }
                break;
            case 9128:
                for (auto x : DataStep2_Zone_9128)
                {
                    if (Creature* creature = m_map->SummonCreature(x.Entry, x.Pos))
                    {
                        m_creatures[zone].push_back(creature->GetGUID());
                        creature->CastSpell(creature, 251298, false);
                    }
                }
                break;
            }

            for (auto& guid : m_creatures[zone])
            {
                if (Creature* cre = ObjectAccessor::GetObjectInMap(guid, m_map, (Creature*)nullptr))
                {
                    switch (zone)
                    {
                    case 9126:
                        if (cre->GetEntry() == 124835)
                            cre->GetAI()->DoAction(ACTION_1);
                        break;
                    case 9100:
                        if (cre->GetEntry() == 125856)
                            cre->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                        break;
                    case 9127:
                        if (cre->GetEntry() == 126446)
                            cre->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
                        break;
                    case 9102:
                        if (cre->GetEntry() == 126231)
                        {
                            if (auto c = cre->FindNearestCreature(127131, 20.0f))
                            {
                                float orientation = c->GetOrientation();
                                cre->SetOrientation(orientation);
                                cre->AddDelayedEvent(1000, [=]() -> void { cre->CastSpell(c, 252310, false); });
                            }
                        }
                        break;
                    }
                }
            }
        }

        if (step == 2)
        {
            switch (zone)
            {
            case 9126:
                if (Creature* creature = m_map->SummonCreature(ListBossIds[urand(0, 12)], { 663.7761f, 618.4219f, 40.47853f, 1.392737f }))
                    m_creatures[zone].push_back(creature->GetGUID());
                break;
            case 9102:
                if (Creature* creature = m_map->SummonCreature(ListBossIds[urand(0, 12)], { -1834.573f, -1604.095f, 0.8263019f, 1.677646f }))
                    m_creatures[zone].push_back(creature->GetGUID());
                break;
            case 9100:
                if (Creature* creature = m_map->SummonCreature(ListBossIds[urand(0, 12)], { -4066.832f, -4662.799f, 80.54459f, 4.627432f }))
                    m_creatures[zone].push_back(creature->GetGUID());
                break;
            case 9180:
                if (Creature* creature = m_map->SummonCreature(ListBossIds[urand(0, 12)], { -3722.05f, -7994.531f, 3.177111f, 4.192229f }))
                    m_creatures[zone].push_back(creature->GetGUID());
                break;
            case 9127:
                if (Creature* creature = m_map->SummonCreature(ListBossIds[urand(0, 12)], { -4035.54f, 571.6875f, 0.6500577f, 2.5145f }))
                    m_creatures[zone].push_back(creature->GetGUID());
                break;
            case 9128:
                if (Creature* creature = m_map->SummonCreature(ListBossIds[urand(0, 12)], { -1361.656f, 704.0347f, 65.68648f, 1.881438f }))
                    m_creatures[zone].push_back(creature->GetGUID());
                break;
            }
            return;
        }
    }

    bool Update(uint32 diff) override
    {
        std::vector<uint32> clearing{};

        for (auto itr = m_timersPerZone.begin(); itr != m_timersPerZone.end(); ++itr)
        {
            if ((*itr).second <= diff)
            {
                uint32 zoneid = (*itr).first;

                for (auto& guid : m_creatures[zoneid])
                    if (Creature* cre = ObjectAccessor::GetObjectInMap(guid, m_map, (Creature*)nullptr))
                        cre->DespawnOrUnsummon();

                for (auto& guid : m_players[zoneid])
                    if (Player* player = ObjectAccessor::GetObjectInMap(guid, m_map, (Player*)nullptr))
                        if (!player->IsGameMaster())
                            player->CastSpell(player, 247069, false);

                m_creatures[zoneid].clear();
                delete //m_scenarios[zoneid];
                m_scenarios.erase(zoneid);
                Initialize(zoneid); // recreate scenario
                clearing.push_back((*itr).first);
            }
            else
                (*itr).second -= diff;
        }

        for (auto& id : clearing)
            m_timersPerZone.erase(id);

        return true;
    }*/

  //  void HandleGameEventStart(uint32 eventId)
   // {
     //   for (auto& id : zonesByEvents[eventId])
        //    m_timersPerZone[id] = 1;
  //  }

/*private:
    std::map<uint32, Scenario*> m_scenarios{};
    std::map<uint32, std::set<ObjectGuid>> m_players{};
    std::map<uint32, std::vector<ObjectGuid>> m_creatures{};
    std::map<uint32, int32> m_timersPerZone{}; // zoneid + timer
    std::map<uint32, bool> m_justInitialized{};
};*/
/*
class OutdoorPvP_ArgusInvasion : public OutdoorPvPScript
{
public:
    OutdoorPvP_ArgusInvasion() : OutdoorPvPScript("outdoorpvp_argus") {}

    OutdoorPvP* GetOutdoorPvP() const override
    {
        return new OutdoorPVPArgusInvasion();
    }
};*/

void AddSC_invasion_point_argus()
{
    RegisterCreatureAI(npc_baldrazar);
    RegisterCreatureAI(npc_dreadbringer_valus);
    RegisterCreatureAI(npc_vogrethar_the_defiled);
    RegisterCreatureAI(npc_flamebringer_azrothel);
    RegisterCreatureAI(npc_gorgoloth);
    RegisterCreatureAI(npc_flameweaver_verathix);
    RegisterCreatureAI(npc_velthrak_the_punisher);
    RegisterCreatureAI(npc_mazgoroth);
    RegisterCreatureAI(npc_malphazel_argus);
    RegisterCreatureAI(npc_fel_lord_kazral);
    RegisterCreatureAI(npc_harbinger_drelnathar);
    RegisterCreatureAI(npc_flamecaller_vezrah);
    RegisterCreatureAI(npc_dread_knight_zakgal);
    RegisterCreatureAI(npc_fragment_of_argus);
  /*  RegisterCreatureAI(npc_gripping_shadows);
    RegisterCreatureAI(npc_explosive_orb);
    RegisterCreatureAI(npc_wake_of_blood);
    RegisterCreatureAI(npc_fel_spike_argus);
    RegisterCreatureAI(npc_shadowy_illusion_argus);
    RegisterCreatureAI(npc_flame_fissure);
    RegisterCreatureAI(npc_temporal_anomaly);
    RegisterCreatureAI(npc_felflame_invader);
    RegisterCreatureAI(npc_demon_hunter_val);
    RegisterCreatureAI(npc_felflame_subjugator);
    RegisterCreatureAI(npc_demonhunter_argus_invasion);
    RegisterCreatureAI(npc_crazed_corruptor);
    RegisterCreatureAI(npc_emblazoned_fire_tamer);
    RegisterCreatureAI(npc_magma_giant);
    RegisterSpellScript(spell_creeping_doom_argus_dummy);
    RegisterSpellScript(spell_summon_explosive_orbs);
    RegisterSpellScript(spell_destroying_ip_argus);
    RegisterSpellScript(spell_destroying_argus_val);
*/
    RegisterAuraScript(spell_fire_enchanted);

/*    RegisterAuraScript(spell_spore_filled);
    RegisterAuraScript(spell_cripple);
    RegisterAuraScript(spell_creeping_doom_argus);
    RegisterAuraScript(spell_narcolepsy);*/
   // new OutdoorPvP_ArgusInvasion();
}
