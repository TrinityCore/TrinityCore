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
SDName: Thousand Needles
SD%Complete: 100
SDComment: Support for Quest: 4770, 4904, 4966, 5151.
SDCategory: Thousand Needles
EndScriptData */

/* ContentData
npc_lakota_windsong
npc_swiftmountain
npc_enraged_panther
go_panther_cage
EndContentData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptedEscortAI.h"
#include "ScriptedGossip.h"

/*######
# npc_lakota_windsong
######*/

enum Lakota
{
    SAY_LAKO_START        = 0,
    SAY_LAKO_LOOK_OUT     = 1,
    SAY_LAKO_HERE_COME    = 2,
    SAY_LAKO_MORE         = 3,
    SAY_LAKO_END          = 4,

    QUEST_FREE_AT_LAST    = 4904,
    NPC_GRIM_BANDIT       = 10758,

    ID_AMBUSH_1           = 0,
    ID_AMBUSH_2           = 2,
    ID_AMBUSH_3           = 4
};

Position const BanditLoc[6] =
{
    {-4905.479492f, -2062.732666f, 84.352f, 0.0f},
    {-4915.201172f, -2073.528320f, 84.733f, 0.0f},
    {-4878.883301f, -1986.947876f, 91.966f, 0.0f},
    {-4877.503906f, -1966.113403f, 91.859f, 0.0f},
    {-4767.985352f, -1873.169189f, 90.192f, 0.0f},
    {-4788.861328f, -1888.007813f, 89.888f, 0.0f}
};

class npc_lakota_windsong : public CreatureScript
{
public:
    npc_lakota_windsong() : CreatureScript("npc_lakota_windsong") { }

    struct npc_lakota_windsongAI : public EscortAI
    {
        npc_lakota_windsongAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override { }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 8:
                    Talk(SAY_LAKO_LOOK_OUT);
                    DoSpawnBandits(ID_AMBUSH_1);
                    break;
                case 14:
                    Talk(SAY_LAKO_HERE_COME);
                    DoSpawnBandits(ID_AMBUSH_2);
                    break;
                case 21:
                    Talk(SAY_LAKO_MORE);
                    DoSpawnBandits(ID_AMBUSH_3);
                    break;
                case 45:
                    Talk(SAY_LAKO_END);
                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_FREE_AT_LAST, me);
                    break;
            }
        }

        void DoSpawnBandits(int AmbushId)
        {
            for (int i = 0; i < 2; ++i)
                me->SummonCreature(NPC_GRIM_BANDIT, BanditLoc[i+AmbushId], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_FREE_AT_LAST)
            {
                Talk(SAY_LAKO_START, player);
                me->SetFaction(FACTION_ESCORTEE_H_NEUTRAL_ACTIVE);

                Start(false, false, player->GetGUID(), quest);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_lakota_windsongAI(creature);
    }
};

/*######
# npc_paoka_swiftmountain
######*/

enum Packa
{
    SAY_START        = 0,
    SAY_WYVERN       = 1,
    SAY_COMPLETE     = 2,

    QUEST_HOMEWARD   = 4770,
    NPC_WYVERN       = 4107
};

Position const WyvernLoc[3] =
{
    {-4990.606f, -906.057f, -5.343f, 0.0f},
    {-4970.241f, -927.378f, -4.951f, 0.0f},
    {-4985.364f, -952.528f, -5.199f, 0.0f}
};

class npc_paoka_swiftmountain : public CreatureScript
{
public:
    npc_paoka_swiftmountain() : CreatureScript("npc_paoka_swiftmountain") { }

    struct npc_paoka_swiftmountainAI : public EscortAI
    {
        npc_paoka_swiftmountainAI(Creature* creature) : EscortAI(creature) { }

        void Reset() override { }

        void WaypointReached(uint32 waypointId, uint32 /*pathId*/) override
        {
            switch (waypointId)
            {
                case 15:
                    Talk(SAY_WYVERN);
                    DoSpawnWyvern();
                    break;
                case 26:
                    Talk(SAY_COMPLETE);
                    break;
                case 27:
                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_HOMEWARD, me);
                    break;
            }
        }

        void DoSpawnWyvern()
        {
            for (int i = 0; i < 3; ++i)
                me->SummonCreature(NPC_WYVERN, WyvernLoc[i], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        }

        void QuestAccept(Player* player, Quest const* quest) override
        {
            if (quest->GetQuestId() == QUEST_HOMEWARD)
            {
                Talk(SAY_START, player);
                me->SetFaction(FACTION_ESCORTEE_H_NEUTRAL_ACTIVE);

                Start(false, false, player->GetGUID(), quest);
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_paoka_swiftmountainAI(creature);
    }
};

enum PantherCage
{
    QUEST_HYPERCAPACITOR_GIZMO = 5151,
    ENRAGED_PANTHER            = 10992
};

class go_panther_cage : public GameObjectScript
{
public:
    go_panther_cage() : GameObjectScript("go_panther_cage") { }

    struct go_panther_cageAI : public GameObjectAI
    {
        go_panther_cageAI(GameObject* go) : GameObjectAI(go) { }

        bool GossipHello(Player* player) override
        {
            me->UseDoorOrButton();
            if (player->GetQuestStatus(QUEST_HYPERCAPACITOR_GIZMO) == QUEST_STATUS_INCOMPLETE)
            {
                if (Creature* panther = me->FindNearestCreature(ENRAGED_PANTHER, 5, true))
                {
                    panther->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    panther->SetReactState(REACT_AGGRESSIVE);
                    panther->AI()->AttackStart(player);
                }
            }

            return true;
        }
    };

    GameObjectAI* GetAI(GameObject* go) const override
    {
        return new go_panther_cageAI(go);
    }
};

class npc_enraged_panther : public CreatureScript
{
public:
    npc_enraged_panther() : CreatureScript("npc_enraged_panther") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_enraged_pantherAI(creature);
    }

    struct npc_enraged_pantherAI : public ScriptedAI
    {
        npc_enraged_pantherAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(uint32 /*diff*/) override
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_thousand_needles()
{
    new npc_lakota_windsong();
    new npc_paoka_swiftmountain();
    new npc_enraged_panther();
    new go_panther_cage();
}
