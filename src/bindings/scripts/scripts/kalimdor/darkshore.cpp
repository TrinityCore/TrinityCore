/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Darkshore
SD%Complete: 100
SDComment: Quest support: 731, 2078
SDCategory: Darkshore
EndScriptData */

/* ContentData
npc_prospector_remtravel
npc_threshwackonator
EndContentData */

#include "precompiled.h"
#include "escortAI.h"

/*####
# npc_prospector_remtravel
####*/

enum
{
    SAY_REM_START               = -1000415,
    SAY_REM_AGGRO               = -1000427,
    SAY_REM_RAMP1_1             = -1000416,
    SAY_REM_RAMP1_2             = -1000417,
    SAY_REM_BOOK                = -1000418,
    SAY_REM_TENT1_1             = -1000419,
    SAY_REM_TENT1_2             = -1000420,
    SAY_REM_MOSS                = -1000421,
    EMOTE_REM_MOSS              = -1000422,
    SAY_REM_MOSS_PROGRESS       = -1000423,
    SAY_REM_PROGRESS            = -1000424,
    SAY_REM_REMEMBER            = -1000425,
    EMOTE_REM_END               = -1000426,

    FACTION_ESCORTEE            = 10,
    QUEST_ABSENT_MINDED_PT2     = 731,
    NPC_GRAVEL_SCOUT            = 2158,
    NPC_GRAVEL_BONE             = 2159,
    NPC_GRAVEL_GEO              = 2160
};

struct TRINITY_DLL_DECL npc_prospector_remtravelAI : public npc_escortAI
{
    npc_prospector_remtravelAI(Creature* pCreature) : npc_escortAI(pCreature) {}

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

        if (!pPlayer)
            return;

        switch(i)
        {
            case 0:
                DoScriptText(SAY_REM_START, me, pPlayer);
                break;
            case 5:
                DoScriptText(SAY_REM_RAMP1_1, me, pPlayer);
                break;
            case 6:
                DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 9:
                DoScriptText(SAY_REM_RAMP1_2, me, pPlayer);
                break;
            case 14:
                //depend quest rewarded?
                DoScriptText(SAY_REM_BOOK, me, pPlayer);
                break;
            case 15:
                DoScriptText(SAY_REM_TENT1_1, me, pPlayer);
                break;
            case 16:
                DoSpawnCreature(NPC_GRAVEL_SCOUT, -10.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_GRAVEL_BONE, -10.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 17:
                DoScriptText(SAY_REM_TENT1_2, me, pPlayer);
                break;
            case 26:
                DoScriptText(SAY_REM_MOSS, me, pPlayer);
                break;
            case 27:
                DoScriptText(EMOTE_REM_MOSS, me, pPlayer);
                break;
            case 28:
                DoScriptText(SAY_REM_MOSS_PROGRESS, me, pPlayer);
                break;
            case 29:
                DoSpawnCreature(NPC_GRAVEL_SCOUT, -15.0f, 3.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_GRAVEL_BONE, -15.0f, 5.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                DoSpawnCreature(NPC_GRAVEL_GEO, -15.0f, 7.0f, 0.0f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 30000);
                break;
            case 31:
                DoScriptText(SAY_REM_PROGRESS, me, pPlayer);
                break;
            case 41:
                DoScriptText(SAY_REM_REMEMBER, me, pPlayer);
                break;
            case 42:
                DoScriptText(EMOTE_REM_END, me, pPlayer);
                pPlayer->GroupEventHappens(QUEST_ABSENT_MINDED_PT2, me);
                break;
        }
    }

    void Reset() {}

    void EnterCombat(Unit* who)
    {
        if (rand()%2)
            DoScriptText(SAY_REM_AGGRO, me, who);
    }

    void JustSummoned(Creature* pSummoned)
    {
        //unsure if it should be any
        //pSummoned->AI()->AttackStart(m_creature);
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

CreatureAI* GetAI_npc_prospector_remtravel(Creature* pCreature)
{
    npc_prospector_remtravelAI* tempAI = new npc_prospector_remtravelAI(pCreature);

    tempAI->FillPointMovementListForCreature();

    return tempAI;
}

bool QuestAccept_npc_prospector_remtravel(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ABSENT_MINDED_PT2)
    {
        if (npc_escortAI* pEscortAI = CAST_AI(npc_prospector_remtravelAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID());

        pCreature->setFaction(FACTION_ESCORTEE);
    }

    return true;
}

/*####
# npc_threshwackonator
####*/

enum
{
    EMOTE_START             = -1000413,
    SAY_AT_CLOSE            = -1000414,
    QUEST_GYROMAST_REV      = 2078,
    NPC_GELKAK              = 6667,
    FACTION_HOSTILE         = 14
};

#define GOSSIP_ITEM_INSERT_KEY  "[PH] Insert key"

struct TRINITY_DLL_DECL npc_threshwackonatorAI : public ScriptedAI
{
    npc_threshwackonatorAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Faction = pCreature->getFaction();
        NpcFlags = pCreature->GetUInt32Value(UNIT_NPC_FLAGS);
        PlayerGUID = 0;
    }

    uint64 PlayerGUID;
    uint32 Faction;
    uint32 NpcFlags;
    uint32 CheckPlayerTimer;

    void Reset()
    {
        CheckPlayerTimer = 2500;

        if (!PlayerGUID)
        {
            me->setFaction(Faction);
            me->SetUInt32Value(UNIT_NPC_FLAGS, NpcFlags);
        }
    }

    void MoveInLineOfSight(Unit* who)
    {
        if (who->GetEntry() == NPC_GELKAK)
        {
            if (PlayerGUID && me->IsWithinDistInMap(who, 10.0f))
            {
                DoScriptText(SAY_AT_CLOSE, who);
                DoAtEnd();
            }
        }

        ScriptedAI::MoveInLineOfSight(who);
    }

    void EnterEvadeMode()
    {
        me->RemoveAllAuras();
        me->DeleteThreatList();
        me->CombatStop(true);
        me->LoadCreaturesAddon();

        if (me->isAlive())
        {
            if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
                me->GetMotionMaster()->MoveFollow(pPlayer, PET_FOLLOW_DIST, m_creature->GetFollowAngle());
            else
            {
                me->GetMotionMaster()->MovementExpired();
                me->GetMotionMaster()->MoveTargetedHome();
            }
        }

        me->SetLootRecipient(NULL);

        Reset();
    }

    void DoStart(uint64 Starter)
    {
        PlayerGUID = Starter;
        me->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);

        if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
            me->GetMotionMaster()->MoveFollow(pPlayer, PET_FOLLOW_DIST, m_creature->GetFollowAngle());

        DoScriptText(EMOTE_START, me);
    }

    void DoAtEnd()
    {
        me->setFaction(FACTION_HOSTILE);

        if (Player* pHolder = Unit::GetPlayer(PlayerGUID))
            me->AI()->AttackStart(pHolder);

        PlayerGUID = 0;
    }

    void JustDied(Unit* pKiller)
    {
        if (PlayerGUID)
        {
            PlayerGUID = 0;
            me->GetMotionMaster()->MovementExpired();
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (PlayerGUID)
        {
            if (!me->isInCombat())
            {
                if (CheckPlayerTimer < diff)
                {
                    CheckPlayerTimer = 5000;

                    Player* pPlayer = Unit::GetPlayer(PlayerGUID);

                    if (pPlayer && !pPlayer->isAlive())
                    {
                        PlayerGUID = 0;
                        EnterEvadeMode();
                        return;
                    }
                }else CheckPlayerTimer -= diff;
            }
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_threshwackonator(Creature* pCreature)
{
    return new npc_threshwackonatorAI(pCreature);
}

bool GossipHello_npc_threshwackonator(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_GYROMAST_REV) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_INSERT_KEY, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_threshwackonator(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        CAST_AI(npc_threshwackonatorAI, pCreature->AI())->DoStart(pPlayer->GetGUID());
        pPlayer->CLOSE_GOSSIP_MENU();
    }

    return true;
}

void AddSC_darkshore()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_prospector_remtravel";
    newscript->GetAI = &GetAI_npc_prospector_remtravel;
    newscript->pQuestAccept = &QuestAccept_npc_prospector_remtravel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_threshwackonator";
    newscript->GetAI = &GetAI_npc_threshwackonator;
    newscript->pGossipHello = &GossipHello_npc_threshwackonator;
    newscript->pGossipSelect = &GossipSelect_npc_threshwackonator;
    newscript->pGossipSelect = &GossipSelect_npc_threshwackonator;
    newscript->RegisterSelf();
}

