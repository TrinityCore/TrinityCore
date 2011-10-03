/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDComment: Support for Quest: 1950, 4770, 4904, 4966, 5151.
SDCategory: Thousand Needles
EndScriptData */

/* ContentData
npc_kanati
npc_lakota_windsong
npc_swiftmountain
npc_plucky
npc_enraged_panther
go_panther_cage
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*#####
# npc_kanati
######*/

enum eKanati
{
    SAY_KAN_START              = -1000410,

    QUEST_PROTECT_KANATI        = 4966,
    NPC_GALAK_ASS               = 10720
};

const float m_afGalakLoc[]= {-4867.387695f, -1357.353760f, -48.226f };

class npc_kanati : public CreatureScript
{
public:
    npc_kanati() : CreatureScript("npc_kanati") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_PROTECT_KANATI)
        {
            if (npc_kanatiAI* pEscortAI = CAST_AI(npc_kanati::npc_kanatiAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID(), pQuest, true);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_kanatiAI(creature);
    }

    struct npc_kanatiAI : public npc_escortAI
    {
        npc_kanatiAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() { }

        void WaypointReached(uint32 uiPointId)
        {
            switch (uiPointId)
            {
                case 0:
                    DoScriptText(SAY_KAN_START, me);
                    DoSpawnGalak();
                    break;
                case 1:
                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_PROTECT_KANATI, me);
                    break;
            }
        }

        void DoSpawnGalak()
        {
            for (int i = 0; i < 3; ++i)
                me->SummonCreature(NPC_GALAK_ASS,
                m_afGalakLoc[0], m_afGalakLoc[1], m_afGalakLoc[2], 0.0f,
                TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->AI()->AttackStart(me);
        }
    };

};

/*######
# npc_lakota_windsong
######*/

enum eLakota
{
    SAY_LAKO_START              = -1000365,
    SAY_LAKO_LOOK_OUT           = -1000366,
    SAY_LAKO_HERE_COME          = -1000367,
    SAY_LAKO_MORE               = -1000368,
    SAY_LAKO_END                = -1000369,

    QUEST_FREE_AT_LAST          = 4904,
    NPC_GRIM_BANDIT             = 10758,
    FACTION_ESCORTEE_LAKO       = 232,                      //guessed

    ID_AMBUSH_1                 = 0,
    ID_AMBUSH_2                 = 2,
    ID_AMBUSH_3                 = 4
};

float m_afBanditLoc[6][6]=
{
    {-4905.479492f, -2062.732666f, 84.352f},
    {-4915.201172f, -2073.528320f, 84.733f},
    {-4878.883301f, -1986.947876f, 91.966f},
    {-4877.503906f, -1966.113403f, 91.859f},
    {-4767.985352f, -1873.169189f, 90.192f},
    {-4788.861328f, -1888.007813f, 89.888f}
};

class npc_lakota_windsong : public CreatureScript
{
public:
    npc_lakota_windsong() : CreatureScript("npc_lakota_windsong") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_FREE_AT_LAST)
        {
            DoScriptText(SAY_LAKO_START, creature, player);
            creature->setFaction(FACTION_ESCORTEE_LAKO);

            if (npc_lakota_windsongAI* pEscortAI = CAST_AI(npc_lakota_windsong::npc_lakota_windsongAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID(), pQuest);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_lakota_windsongAI(creature);
    }

    struct npc_lakota_windsongAI : public npc_escortAI
    {
        npc_lakota_windsongAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() { }

        void WaypointReached(uint32 uiPointId)
        {
            switch (uiPointId)
            {
                case 8:
                    DoScriptText(SAY_LAKO_LOOK_OUT, me);
                    DoSpawnBandits(ID_AMBUSH_1);
                    break;
                case 14:
                    DoScriptText(SAY_LAKO_HERE_COME, me);
                    DoSpawnBandits(ID_AMBUSH_2);
                    break;
                case 21:
                    DoScriptText(SAY_LAKO_MORE, me);
                    DoSpawnBandits(ID_AMBUSH_3);
                    break;
                case 45:
                    if (Player* player = GetPlayerForEscort())
                        player->GroupEventHappens(QUEST_FREE_AT_LAST, me);
                    break;
            }
        }

        void DoSpawnBandits(int uiAmbushId)
        {
            for (int i = 0; i < 2; ++i)
                me->SummonCreature(NPC_GRIM_BANDIT,
                m_afBanditLoc[i+uiAmbushId][0], m_afBanditLoc[i+uiAmbushId][1], m_afBanditLoc[i+uiAmbushId][2], 0.0f,
                TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        }
    };

};

/*######
# npc_paoka_swiftmountain
######*/

enum ePacka
{
    SAY_START           = -1000362,
    SAY_WYVERN          = -1000363,
    SAY_COMPLETE        = -1000364,

    QUEST_HOMEWARD      = 4770,
    NPC_WYVERN          = 4107,
    FACTION_ESCORTEE    = 232                               //guessed
};

float m_afWyvernLoc[3][3]=
{
    {-4990.606f, -906.057f, -5.343f},
    {-4970.241f, -927.378f, -4.951f},
    {-4985.364f, -952.528f, -5.199f}
};

class npc_paoka_swiftmountain : public CreatureScript
{
public:
    npc_paoka_swiftmountain() : CreatureScript("npc_paoka_swiftmountain") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_HOMEWARD)
        {
            DoScriptText(SAY_START, creature, player);
            creature->setFaction(FACTION_ESCORTEE);

            if (npc_paoka_swiftmountainAI* pEscortAI = CAST_AI(npc_paoka_swiftmountain::npc_paoka_swiftmountainAI, creature->AI()))
                pEscortAI->Start(false, false, player->GetGUID(), pQuest);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_paoka_swiftmountainAI(creature);
    }

    struct npc_paoka_swiftmountainAI : public npc_escortAI
    {
        npc_paoka_swiftmountainAI(Creature* creature) : npc_escortAI(creature) { }

        void Reset() { }

        void WaypointReached(uint32 uiPointId)
        {
            switch (uiPointId)
            {
                case 15:
                    DoScriptText(SAY_WYVERN, me);
                    DoSpawnWyvern();
                    break;
                case 26:
                    DoScriptText(SAY_COMPLETE, me);
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
                me->SummonCreature(NPC_WYVERN,
                m_afWyvernLoc[i][0], m_afWyvernLoc[i][1], m_afWyvernLoc[i][2], 0.0f,
                TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
        }
    };

};

/*#####
# npc_plucky
######*/

#define GOSSIP_P    "Please tell me the Phrase.."

enum ePlucky
{
    FACTION_FRIENDLY        = 35,
    QUEST_SCOOP             = 1950,
    SPELL_PLUCKY_HUMAN      = 9192,
    SPELL_PLUCKY_CHICKEN    = 9220
};

class npc_plucky : public CreatureScript
{
public:
    npc_plucky() : CreatureScript("npc_plucky") { }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                player->CompleteQuest(QUEST_SCOOP);
            break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(QUEST_SCOOP) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_P, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        player->SEND_GOSSIP_MENU(738, creature->GetGUID());

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_pluckyAI(creature);
    }

    struct npc_pluckyAI : public ScriptedAI
    {
        npc_pluckyAI(Creature* c) : ScriptedAI(c) { m_uiNormFaction = c->getFaction(); }

        uint32 m_uiNormFaction;
        uint32 m_uiResetTimer;

        void Reset()
        {
            m_uiResetTimer = 120000;

            if (me->getFaction() != m_uiNormFaction)
                me->setFaction(m_uiNormFaction);

            if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
                me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

            DoCast(me, SPELL_PLUCKY_CHICKEN, false);
        }

        void ReceiveEmote(Player* player, uint32 uiTextEmote)
        {
            if (player->GetQuestStatus(QUEST_SCOOP) == QUEST_STATUS_INCOMPLETE)
            {
                if (uiTextEmote == TEXT_EMOTE_BECKON)
                {
                    me->setFaction(FACTION_FRIENDLY);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    DoCast(me, SPELL_PLUCKY_HUMAN, false);
                }
            }

            if (uiTextEmote == TEXT_EMOTE_CHICKEN)
            {
                if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
                    return;
                else
                {
                    me->setFaction(FACTION_FRIENDLY);
                    me->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    DoCast(me, SPELL_PLUCKY_HUMAN, false);
                    me->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (me->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
            {
                if (m_uiResetTimer <= uiDiff)
                {
                    if (!me->getVictim())
                        EnterEvadeMode();
                    else
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                    return;
                }
                else
                    m_uiResetTimer -= uiDiff;
            }

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

enum ePantherCage
{
    ENRAGED_PANTHER = 10992
};

class go_panther_cage : public GameObjectScript
{
public:
    go_panther_cage() : GameObjectScript("go_panther_cage") { }

    bool OnGossipHello(Player* player, GameObject* pGo)
    {

        if (player->GetQuestStatus(5151) == QUEST_STATUS_INCOMPLETE)
        {
            if (Creature* panther = pGo->FindNearestCreature(ENRAGED_PANTHER, 5, true))
            {
                panther->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                panther->SetReactState(REACT_AGGRESSIVE);
                panther->AI()->AttackStart(player);
            }
        }

        return true ;
    }
};

class npc_enraged_panther : public CreatureScript
{
public:
    npc_enraged_panther() : CreatureScript("npc_enraged_panther") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_enraged_pantherAI(creature);
    }

    struct npc_enraged_pantherAI : public ScriptedAI
    {
        npc_enraged_pantherAI(Creature* c) : ScriptedAI(c) {}

        void Reset()
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
            me->SetReactState(REACT_PASSIVE);
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_thousand_needles()
{
    new npc_kanati();
    new npc_lakota_windsong();
    new npc_paoka_swiftmountain();
    new npc_plucky();
    new npc_enraged_panther();
    new go_panther_cage();
}
