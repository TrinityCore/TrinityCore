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
SDName: The_Barrens
SD%Complete: 90
SDComment: Quest support: 863, 898, 1719, 2458, 4921, 6981, 
SDCategory: Barrens
EndScriptData */

/* ContentData
npc_beaten_corpse
npc_gilthares
npc_sputtervalve
npc_taskmaster_fizzule
npc_twiggy_flathead
npc_wizzlecrank_shredder
EndContentData */

#include "precompiled.h"
#include "escort_ai.h"

/*######
## npc_beaten_corpse
######*/

#define GOSSIP_CORPSE "Examine corpse in detail..."

enum
{
    QUEST_LOST_IN_BATTLE    = 4921
};

bool GossipHello_npc_beaten_corpse(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_LOST_IN_BATTLE) == QUEST_STATUS_INCOMPLETE || pPlayer->GetQuestStatus(QUEST_LOST_IN_BATTLE) == QUEST_STATUS_COMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_CORPSE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    pPlayer->SEND_GOSSIP_MENU(3557, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_beaten_corpse(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF +1)
    {
        pPlayer->SEND_GOSSIP_MENU(3558, pCreature->GetGUID());
        pPlayer->TalkedToCreature(pCreature->GetEntry(), pCreature->GetGUID());
    }
    return true;
}

/*######
# npc_gilthares
######*/

enum
{
    SAY_GIL_START               = -1000370,
    SAY_GIL_AT_LAST             = -1000371,
    SAY_GIL_PROCEED             = -1000372,
    SAY_GIL_FREEBOOTERS         = -1000373,
    SAY_GIL_AGGRO_1             = -1000374,
    SAY_GIL_AGGRO_2             = -1000375,
    SAY_GIL_AGGRO_3             = -1000376,
    SAY_GIL_AGGRO_4             = -1000377,
    SAY_GIL_ALMOST              = -1000378,
    SAY_GIL_SWEET               = -1000379,
    SAY_GIL_FREED               = -1000380,

    QUEST_FREE_FROM_HOLD        = 898,
    AREA_MERCHANT_COAST         = 391,
    FACTION_ESCORTEE            = 232                       //guessed, possible not needed for this quest
};

struct TRINITY_DLL_DECL npc_giltharesAI : public npc_escortAI
{
    npc_giltharesAI(Creature* pCreature) : npc_escortAI(pCreature) { }

    void Reset() { }

    void WaypointReached(uint32 uiPointId)
    {
        Player* pPlayer = (Player*)Unit::GetUnit(*m_creature, PlayerGUID);

        if (!pPlayer)
            return;

        switch(uiPointId)
        {
            case 16:
                DoScriptText(SAY_GIL_AT_LAST, m_creature, pPlayer);
                break;
            case 17:
                DoScriptText(SAY_GIL_PROCEED, m_creature, pPlayer);
                break;
            case 18:
                DoScriptText(SAY_GIL_FREEBOOTERS, m_creature, pPlayer);
                break;
            case 37:
                DoScriptText(SAY_GIL_ALMOST, m_creature, pPlayer);
                break;
            case 47:
                DoScriptText(SAY_GIL_SWEET, m_creature, pPlayer);
                break;
            case 53:
                DoScriptText(SAY_GIL_FREED, m_creature, pPlayer);
                pPlayer->GroupEventHappens(QUEST_FREE_FROM_HOLD, m_creature);
                break;
        }
    }

    void Aggro(Unit* pWho)
    {
        //not always use
        if (rand()%4)
            return;

        //only aggro text if not player and only in this area
        if (pWho->GetTypeId() != TYPEID_PLAYER && m_creature->GetAreaId() == AREA_MERCHANT_COAST)
        {
            //appears to be pretty much random (possible only if escorter not in combat with pWho yet?)
            switch(rand()%4)
            {
                case 0: DoScriptText(SAY_GIL_AGGRO_1, m_creature, pWho); break;
                case 1: DoScriptText(SAY_GIL_AGGRO_2, m_creature, pWho); break;
                case 2: DoScriptText(SAY_GIL_AGGRO_3, m_creature, pWho); break;
                case 3: DoScriptText(SAY_GIL_AGGRO_4, m_creature, pWho); break;
            }
        }
    }
};

CreatureAI* GetAI_npc_gilthares(Creature* pCreature)
{
    return new npc_giltharesAI(pCreature);
}

bool QuestAccept_npc_gilthares(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_FREE_FROM_HOLD)
    {
        pCreature->setFaction(FACTION_ESCORTEE);
        pCreature->SetStandState(UNIT_STAND_STATE_STAND);

        DoScriptText(SAY_GIL_START, pCreature, pPlayer);

        if (npc_giltharesAI* pEscortAI = CAST_AI(npc_giltharesAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

/*######
## npc_sputtervalve
######*/

#define GOSSIP_SPUTTERVALVE "Can you tell me about this shard?"

bool GossipHello_npc_sputtervalve(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(6981) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SPUTTERVALVE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_sputtervalve(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF)
    {
        pPlayer->SEND_GOSSIP_MENU(2013, pCreature->GetGUID());
        pPlayer->AreaExploredOrEventHappens(6981);
    }
    return true;
}

/*######
## npc_taskmaster_fizzule
######*/

enum
{
    FACTION_FRIENDLY_F  = 35,
    SPELL_FLARE         = 10113,
    SPELL_FOLLY         = 10137,
};

struct TRINITY_DLL_DECL npc_taskmaster_fizzuleAI : public ScriptedAI
{
    npc_taskmaster_fizzuleAI(Creature* c) : ScriptedAI(c)
    {
        factionNorm = c->getFaction();
    }

    uint32 factionNorm;
    bool IsFriend;
    uint32 Reset_Timer;
    uint8 FlareCount;

    void Reset()
    {
        IsFriend = false;
        Reset_Timer = 120000;
        FlareCount = 0;
        m_creature->setFaction(factionNorm);
    }

    void DoFriend()
    {
        m_creature->RemoveAllAuras();
        m_creature->DeleteThreatList();
        m_creature->CombatStop(true);

        m_creature->StopMoving();
        m_creature->GetMotionMaster()->MoveIdle();

        m_creature->setFaction(FACTION_FRIENDLY_F);
        m_creature->HandleEmoteCommand(EMOTE_ONESHOT_SALUTE);
    }

    void SpellHit(Unit *caster, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_FLARE || spell->Id == SPELL_FOLLY)
        {
            ++FlareCount;

            if (FlareCount >= 2)
                IsFriend = true;
        }
    }

    void EnterCombat(Unit* who) { }

    void UpdateAI(const uint32 diff)
    {
        if (IsFriend)
        {
            if (Reset_Timer < diff)
            {
                EnterEvadeMode();
                return;
            } else Reset_Timer -= diff;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }

    void ReceiveEmote(Player* pPlayer, uint32 emote)
    {
        if (emote == TEXTEMOTE_SALUTE)
        {
            if (FlareCount >= 2)
            {
                if (m_creature->getFaction() == FACTION_FRIENDLY_F)
                    return;

                DoFriend();
            }
        }
    }
};

CreatureAI* GetAI_npc_taskmaster_fizzule(Creature* pCreature)
{
    return new npc_taskmaster_fizzuleAI(pCreature);
}

/*#####
## npc_twiggy_flathead
#####*/

#define BIG_WILL 6238
#define AFFRAY_CHALLENGER 6240
#define SAY_BIG_WILL_READY                  -1000267
#define SAY_TWIGGY_FLATHEAD_BEGIN           -1000268
#define SAY_TWIGGY_FLATHEAD_FRAY            -1000269
#define SAY_TWIGGY_FLATHEAD_DOWN            -1000270
#define SAY_TWIGGY_FLATHEAD_OVER            -1000271

float AffrayChallengerLoc[6][4]=
{
    {-1683, -4326, 2.79, 0},
    {-1682, -4329, 2.79, 0},
    {-1683, -4330, 2.79, 0},
    {-1680, -4334, 2.79, 1.49},
    {-1674, -4326, 2.79, 3.49},
    {-1677, -4334, 2.79, 1.66}
};

struct TRINITY_DLL_DECL npc_twiggy_flatheadAI : public ScriptedAI
{
    npc_twiggy_flatheadAI(Creature *c) : ScriptedAI(c) {}

    bool EventInProgress;
    bool EventGrate;
    bool EventBigWill;
    bool Challenger_down[6];
    uint32 Wave;
    uint32 Wave_Timer;
    uint32 Challenger_checker;
    uint64 PlayerGUID;
    uint64 AffrayChallenger[6];
    uint64 BigWill;

    void Reset()
    {
        EventInProgress = false;
        EventGrate = false;
        EventBigWill = false;
        Wave_Timer = 600000;
        Challenger_checker = 0;
        Wave = 0;
        PlayerGUID = 0;

        for(uint8 i = 0; i < 6; ++i)
        {
            AffrayChallenger[i] = 0;
            Challenger_down[i] = false;
        }
        BigWill = 0;
    }

    void EnterCombat(Unit *who) { }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who || (!who->isAlive())) return;

        if (m_creature->IsWithinDistInMap(who, 10.0f) && (who->GetTypeId() == TYPEID_PLAYER) && CAST_PLR(who)->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE && !EventInProgress)
        {
            PlayerGUID = who->GetGUID();
            EventInProgress = true;
        }
    }

    void KilledUnit(Unit *victim) { }

    void UpdateAI(const uint32 diff)
    {
        if (EventInProgress) {
            Player* pWarrior = NULL;

            if (PlayerGUID)
                pWarrior = Unit::GetPlayer(PlayerGUID);

            if (!pWarrior)
                return;

            if (!pWarrior->isAlive() && pWarrior->GetQuestStatus(1719) == QUEST_STATUS_INCOMPLETE) {
                EventInProgress = false;
                DoScriptText(SAY_TWIGGY_FLATHEAD_DOWN, m_creature);
                pWarrior->FailQuest(1719);

                for(uint8 i = 0; i < 6; ++i)
                {
                    if (AffrayChallenger[i])
                    {
                        Creature* pCreature = Unit::GetCreature((*m_creature), AffrayChallenger[i]);
                        if (pCreature) {
                            if (pCreature->isAlive())
                            {
                                pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                                pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                                pCreature->setDeathState(JUST_DIED);
                            }
                        }
                    }
                    AffrayChallenger[i] = 0;
                    Challenger_down[i] = false;
                }

                if (BigWill)
                {
                    Creature* pCreature = Unit::GetCreature((*m_creature), BigWill);
                    if (pCreature) {
                        if (pCreature->isAlive()) {
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
                            pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pCreature->setDeathState(JUST_DIED);
                        }
                    }
                }
                BigWill = 0;
            }

            if (!EventGrate && EventInProgress)
            {
                float x,y,z;
                pWarrior->GetPosition(x, y, z);

                if (x >= -1684 && x <= -1674 && y >= -4334 && y <= -4324) {
                    pWarrior->AreaExploredOrEventHappens(1719);
                    DoScriptText(SAY_TWIGGY_FLATHEAD_BEGIN, m_creature);

                    for(uint8 i = 0; i < 6; ++i)
                    {
                        Creature* pCreature = m_creature->SummonCreature(AFFRAY_CHALLENGER, AffrayChallengerLoc[i][0], AffrayChallengerLoc[i][1], AffrayChallengerLoc[i][2], AffrayChallengerLoc[i][3], TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000);
                        if (!pCreature)
                            continue;
                        pCreature->setFaction(35);
                        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        pCreature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        pCreature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                        AffrayChallenger[i] = pCreature->GetGUID();
                    }
                    Wave_Timer = 5000;
                    Challenger_checker = 1000;
                    EventGrate = true;
                }
            }
            else if (EventInProgress)
            {
                if (Challenger_checker < diff)
                {
                    for(uint8 i = 0; i < 6; ++i)
                    {
                        if (AffrayChallenger[i])
                        {
                            Creature* pCreature = Unit::GetCreature((*m_creature), AffrayChallenger[i]);
                            if ((!pCreature || (!pCreature->isAlive())) && !Challenger_down[i])
                            {
                                DoScriptText(SAY_TWIGGY_FLATHEAD_DOWN, m_creature);
                                Challenger_down[i] = true;
                            }
                        }
                    }
                    Challenger_checker = 1000;
                } else Challenger_checker -= diff;

                if (Wave_Timer < diff)
                {
                    if (AffrayChallenger[Wave] && Wave < 6 && !EventBigWill)
                    {
                        DoScriptText(SAY_TWIGGY_FLATHEAD_FRAY, m_creature);
                        Creature* pCreature = Unit::GetCreature((*m_creature), AffrayChallenger[Wave]);
                        if (pCreature && (pCreature->isAlive()))
                        {
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            pCreature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                            pCreature->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                            pCreature->setFaction(14);
                            (pCreature->AI())->AttackStart(pWarrior);
                            ++Wave;
                            Wave_Timer = 20000;
                        }
                    }
                    else if (Wave >= 6 && !EventBigWill) {
                        if (Creature* pCreature = m_creature->SummonCreature(BIG_WILL, -1722, -4341, 6.12, 6.26, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 480000))
                        {
                            BigWill = pCreature->GetGUID();
                            //pCreature->GetMotionMaster()->MovePoint(0, -1693, -4343, 4.32);
                            //pCreature->GetMotionMaster()->MovePoint(1, -1684, -4333, 2.78);
                            pCreature->GetMotionMaster()->MovePoint(2, -1682, -4329, 2.79);
                            pCreature->HandleEmoteCommand(EMOTE_STATE_READYUNARMED);
                            EventBigWill = true;
                            Wave_Timer = 1000;
                        }
                    }
                    else if (Wave >= 6 && EventBigWill && BigWill)
                    {
                        Creature* pCreature = Unit::GetCreature((*m_creature), BigWill);
                        if (!pCreature || !pCreature->isAlive())
                        {
                            DoScriptText(SAY_TWIGGY_FLATHEAD_OVER, m_creature);
                            EventInProgress = false;
                            EventBigWill = false;
                            EventGrate = false;
                            PlayerGUID = 0;
                            Wave = 0;
                        }
                    }
                } else Wave_Timer -= diff;
            }
        }
    }
};

CreatureAI* GetAI_npc_twiggy_flathead(Creature* pCreature)
{
    return new npc_twiggy_flatheadAI (pCreature);
}

/*#####
## npc_wizzlecrank_shredder
#####*/

enum
{
    SAY_PROGRESS_1      = -1000272,
    SAY_PROGRESS_2      = -1000273,
    SAY_PROGRESS_3      = -1000274,

    SAY_MERCENARY_4     = -1000275,

    SAY_PROGRESS_5      = -1000276,
    SAY_PROGRESS_6      = -1000277,
    SAY_PROGRESS_7      = -1000278,
    SAY_PROGRESS_8      = -1000279,

    QUEST_ESCAPE        = 863,
    FACTION_RATCHET     = 637,
    NPC_PILOT           = 3451,
    MOB_MERCENARY       = 3282,
};

struct TRINITY_DLL_DECL npc_wizzlecrank_shredderAI : public npc_escortAI
{
    npc_wizzlecrank_shredderAI(Creature* c) : npc_escortAI(c) { }

    bool Completed;

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = Unit::GetPlayer(PlayerGUID);

        if (!pPlayer)
            return;

        switch(i)
        {
        case 0: DoScriptText(SAY_PROGRESS_1, m_creature);
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE); break;
        case 1: DoScriptText(SAY_PROGRESS_2, m_creature); break;
        case 10: DoScriptText(SAY_PROGRESS_3, m_creature, pPlayer);
            m_creature->AddUnitMovementFlag(MOVEMENTFLAG_WALK_MODE); break;
        case 20:{
            Unit* Mercenary = m_creature->FindNearestCreature(MOB_MERCENARY, 99);
            if (Mercenary)
            {
                DoScriptText(SAY_MERCENARY_4, Mercenary);
                CAST_CRE(Mercenary)->AI()->AttackStart(m_creature);
                AttackStart(Mercenary);
            }
                }break;
        case 21: DoScriptText(SAY_PROGRESS_5, m_creature);
            m_creature->RemoveUnitMovementFlag(MOVEMENTFLAG_WALK_MODE); break;
        case 28: DoScriptText(SAY_PROGRESS_6, m_creature); break;
        case 29: DoScriptText(SAY_PROGRESS_7, m_creature); break;
        case 30: DoScriptText(SAY_PROGRESS_8, m_creature); break;
        case 31: m_creature->SummonCreature(NPC_PILOT, 1088.77, -2985.39, 91.84, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 300000);
            m_creature->setDeathState(JUST_DIED);
            Completed = true;
            pPlayer->GroupEventHappens(QUEST_ESCAPE, m_creature);
            break;
        }
    }

    void Reset()
    {
        m_creature->setDeathState(ALIVE);
        Completed = false;
        if (!IsBeingEscorted)
        {
            if (m_creature->getStandState() == UNIT_STAND_STATE_DEAD)
                 m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        }
    }
};

bool QuestAccept_npc_wizzlecrank_shredder(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_ESCAPE)
    {
        pCreature->setFaction(FACTION_RATCHET);
        if (npc_escortAI* pEscortAI = CAST_AI(npc_wizzlecrank_shredderAI, pCreature->AI()))
            pEscortAI->Start(true, false, pPlayer->GetGUID());
    }
    return true;
}

CreatureAI* GetAI_npc_wizzlecrank_shredderAI(Creature* pCreature)
{
    npc_wizzlecrank_shredderAI* thisAI = new npc_wizzlecrank_shredderAI(pCreature);

    thisAI->AddWaypoint(0, 1109.15, -3104.11, 82.41, 6000);
    thisAI->AddWaypoint(1, 1105.39, -3102.86, 82.74, 2000);
    thisAI->AddWaypoint(2, 1104.97, -3108.52, 83.10, 1000);
    thisAI->AddWaypoint(3, 1110.01, -3110.48, 82.81, 1000);
    thisAI->AddWaypoint(4, 1111.72, -3103.03, 82.21, 1000);
    thisAI->AddWaypoint(5, 1106.98, -3099.44, 82.18, 1000);
    thisAI->AddWaypoint(6, 1103.74, -3103.29, 83.05, 1000);
    thisAI->AddWaypoint(7, 1112.55, -3106.56, 82.31, 1000);
    thisAI->AddWaypoint(8, 1108.12, -3111.04, 82.99, 1000);
    thisAI->AddWaypoint(9, 1109.32, -3100.39, 82.08, 1000);
    thisAI->AddWaypoint(10, 1109.32, -3100.39, 82.08, 6000);
    thisAI->AddWaypoint(11, 1098.92, -3095.14, 82.97);
    thisAI->AddWaypoint(12, 1100.94, -3082.60, 82.83);
    thisAI->AddWaypoint(13, 1101.12, -3068.83, 82.53);
    thisAI->AddWaypoint(14, 1096.97, -3051.99, 82.50);
    thisAI->AddWaypoint(15, 1094.06, -3036.79, 82.70);
    thisAI->AddWaypoint(16, 1098.22, -3027.84, 83.79);
    thisAI->AddWaypoint(17, 1109.51, -3015.92, 85.73);
    thisAI->AddWaypoint(18, 1119.87, -3007.21, 87.08);
    thisAI->AddWaypoint(19, 1130.23, -3002.49, 91.27, 5000);
    thisAI->AddWaypoint(20, 1130.23, -3002.49, 91.27, 3000);
    thisAI->AddWaypoint(21, 1130.23, -3002.49, 91.27, 4000);
    thisAI->AddWaypoint(22, 1129.73, -2985.89, 92.46);
    thisAI->AddWaypoint(23, 1124.10, -2983.29, 92.81);
    thisAI->AddWaypoint(24, 1111.74, -2992.38, 91.59);
    thisAI->AddWaypoint(25, 1111.06, -2976.54, 91.81);
    thisAI->AddWaypoint(26, 1099.91, -2991.17, 91.67);
    thisAI->AddWaypoint(27, 1096.32, -2981.55, 91.73);
    thisAI->AddWaypoint(28, 1091.28, -2985.82, 91.74, 4000);
    thisAI->AddWaypoint(29, 1091.28, -2985.82, 91.74, 3000);
    thisAI->AddWaypoint(30, 1091.28, -2985.82, 91.74, 7000);
    thisAI->AddWaypoint(31, 1091.28, -2985.82, 91.74, 3000);

    return thisAI;
}

void AddSC_the_barrens()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_beaten_corpse";
    newscript->pGossipHello = &GossipHello_npc_beaten_corpse;
    newscript->pGossipSelect = &GossipSelect_npc_beaten_corpse;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_gilthares";
    newscript->GetAI = &GetAI_npc_gilthares;
    newscript->pQuestAccept = &QuestAccept_npc_gilthares;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_sputtervalve";
    newscript->pGossipHello = &GossipHello_npc_sputtervalve;
    newscript->pGossipSelect = &GossipSelect_npc_sputtervalve;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_taskmaster_fizzule";
    newscript->GetAI = &GetAI_npc_taskmaster_fizzule;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_twiggy_flathead";
    newscript->GetAI = &GetAI_npc_twiggy_flathead;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name="npc_wizzlecrank_shredder";
    newscript->GetAI = &GetAI_npc_wizzlecrank_shredderAI;
    newscript->pQuestAccept = &QuestAccept_npc_wizzlecrank_shredder;
    newscript->RegisterSelf();
}

