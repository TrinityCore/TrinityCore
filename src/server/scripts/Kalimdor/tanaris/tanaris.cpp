/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Tanaris
SD%Complete: 80
SDComment: Quest support: 1560, 4005, 10277, 10279(Special flight path), 2882. Noggenfogger vendor
SDCategory: Tanaris
EndScriptData */

/* ContentData
mob_aquementas
npc_marin_noggenfogger
npc_tooga
go_inconspicuous_landmark
EndContentData */

#include "scriptPCH.h"

/*######
## mob_aquementas
######*/

#define AGGRO_YELL_AQUE     -1000168

#define SPELL_AQUA_JET      13586
#define SPELL_FROST_SHOCK   15089

struct mob_aquementasAI : public ScriptedAI
{
    mob_aquementasAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        Reset();
    }

    uint32 SendItem_Timer;
    uint32 SwitchFaction_Timer;
    bool isFriendly;

    uint32 FrostShock_Timer;
    uint32 AquaJet_Timer;

    void Reset() override
    {
        SendItem_Timer = 0;
        SwitchFaction_Timer = 10000;
        m_creature->SetFactionTemplateId(35);
        isFriendly = true;

        AquaJet_Timer = 5000;
        FrostShock_Timer = 1000;
    }

    void SendItem(Unit* receiver)
    {
        if (((Player*)receiver)->HasItemCount(11169, 1, false) &&
                ((Player*)receiver)->HasItemCount(11172, 11, false) &&
                ((Player*)receiver)->HasItemCount(11173, 1, false) &&
                !((Player*)receiver)->HasItemCount(11522, 1, true))
        {
            ItemPosCountVec dest;
            uint8 msg = ((Player*)receiver)->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 11522, 1, nullptr);
            if (msg == EQUIP_ERR_OK)
                ((Player*)receiver)->StoreNewItem(dest, 11522, 1, true);
        }
    }

    void Aggro(Unit* who) override
    {
        DoScriptText(AGGRO_YELL_AQUE, m_creature, who);
    }

    void UpdateAI(uint32 const diff) override
    {
        if (isFriendly)
        {
            if (SwitchFaction_Timer < diff)
            {
                m_creature->SetFactionTemplateId(91);
                isFriendly = false;
            }
            else SwitchFaction_Timer -= diff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (!isFriendly)
        {
            if (SendItem_Timer < diff)
            {
                if (m_creature->GetVictim()->GetTypeId() == TYPEID_PLAYER)
                    SendItem(m_creature->GetVictim());
                SendItem_Timer = 5000;
            }
            else SendItem_Timer -= diff;
        }

        if (FrostShock_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FROST_SHOCK);
            FrostShock_Timer = 15000;
        }
        else FrostShock_Timer -= diff;

        if (AquaJet_Timer < diff)
        {
            DoCastSpellIfCan(m_creature, SPELL_AQUA_JET);
            AquaJet_Timer = 15000;
        }
        else AquaJet_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mob_aquementas(Creature* pCreature)
{
    return new mob_aquementasAI(pCreature);
}


#define WHISPER_CUSTODIAN_1     -1000217
#define WHISPER_CUSTODIAN_2     -1000218
#define WHISPER_CUSTODIAN_3     -1000219
#define WHISPER_CUSTODIAN_4     -1000220
#define WHISPER_CUSTODIAN_5     -1000221
#define WHISPER_CUSTODIAN_6     -1000222
#define WHISPER_CUSTODIAN_7     -1000223
#define WHISPER_CUSTODIAN_8     -1000224
#define WHISPER_CUSTODIAN_9     -1000225
#define WHISPER_CUSTODIAN_10    -1000226
#define WHISPER_CUSTODIAN_11    -1000227
#define WHISPER_CUSTODIAN_12    -1000228
#define WHISPER_CUSTODIAN_13    -1000229
#define WHISPER_CUSTODIAN_14    -1000230

struct npc_custodian_of_timeAI : public npc_escortAI
{
    npc_custodian_of_timeAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }

    void WaypointReached(uint32 i) override
    {
        Player* pPlayer = GetPlayerForEscort();

        if (!pPlayer)
            return;

        switch (i)
        {
            case 0:
                DoScriptText(WHISPER_CUSTODIAN_1, m_creature, pPlayer);
                break;
            case 1:
                DoScriptText(WHISPER_CUSTODIAN_2, m_creature, pPlayer);
                break;
            case 2:
                DoScriptText(WHISPER_CUSTODIAN_3, m_creature, pPlayer);
                break;
            case 3:
                DoScriptText(WHISPER_CUSTODIAN_4, m_creature, pPlayer);
                break;
            case 5:
                DoScriptText(WHISPER_CUSTODIAN_5, m_creature, pPlayer);
                break;
            case 6:
                DoScriptText(WHISPER_CUSTODIAN_6, m_creature, pPlayer);
                break;
            case 7:
                DoScriptText(WHISPER_CUSTODIAN_7, m_creature, pPlayer);
                break;
            case 8:
                DoScriptText(WHISPER_CUSTODIAN_8, m_creature, pPlayer);
                break;
            case 9:
                DoScriptText(WHISPER_CUSTODIAN_9, m_creature, pPlayer);
                break;
            case 10:
                DoScriptText(WHISPER_CUSTODIAN_4, m_creature, pPlayer);
                break;
            case 13:
                DoScriptText(WHISPER_CUSTODIAN_10, m_creature, pPlayer);
                break;
            case 14:
                DoScriptText(WHISPER_CUSTODIAN_4, m_creature, pPlayer);
                break;
            case 16:
                DoScriptText(WHISPER_CUSTODIAN_11, m_creature, pPlayer);
                break;
            case 17:
                DoScriptText(WHISPER_CUSTODIAN_12, m_creature, pPlayer);
                break;
            case 18:
                DoScriptText(WHISPER_CUSTODIAN_4, m_creature, pPlayer);
                break;
            case 22:
                DoScriptText(WHISPER_CUSTODIAN_13, m_creature, pPlayer);
                break;
            case 23:
                DoScriptText(WHISPER_CUSTODIAN_4, m_creature, pPlayer);
                break;
            case 24:
                DoScriptText(WHISPER_CUSTODIAN_14, m_creature, pPlayer);
                DoCastSpellIfCan(pPlayer, 34883);
                //below here is temporary workaround, to be removed when spell works properly
                pPlayer->AreaExploredOrEventHappens(10277);
                break;
        }
    }

    void MoveInLineOfSight(Unit *who) override
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
            return;

        if (who->GetTypeId() == TYPEID_PLAYER)
        {
            if (((Player*)who)->HasAura(34877, EFFECT_INDEX_1) && ((Player*)who)->GetQuestStatus(10277) == QUEST_STATUS_INCOMPLETE)
            {
                float Radius = 10.0;

                if (m_creature->IsWithinDistInMap(who, Radius))
                    Start(false, who->GetGUID());
            }
        }
    }

    void Reset() override { }
};

CreatureAI* GetAI_npc_custodian_of_time(Creature* pCreature)
{
    return new npc_custodian_of_timeAI(pCreature);
}

/*####
# npc_tooga
####*/

enum
{
    SAY_TOOGA_RANDOM_START      = 2221,
    SAY_TOOGA_RANDOM_END        = 2228,

    SAY_TOOG_POST_1             = 2137,
    SAY_TORT_POST_2             = 2138,
    SAY_TOOG_POST_3             = 2139,
    SAY_TORT_POST_4             = 2140,
    SAY_TOOG_POST_5             = 2141,
    SAY_TORT_POST_6             = 2145,

    QUEST_TOOGA                 = 1560,
    NPC_TORTA                   = 6015,

    POINT_ID_TO_WATER           = 1
};

float const m_afToWaterLoc[] = { -7032.664551f, -4906.199219f, -1.606446f};

struct npc_toogaAI : public FollowerAI
{
    npc_toogaAI(Creature* pCreature) : FollowerAI(pCreature)
    {
        Reset();
    }

    uint32 m_uiCheckSpeechTimer;
    uint32 m_uiPostEventTimer;
    uint32 m_uiPhasePostEvent;

    ObjectGuid m_tortaGuid;

    void Reset() override
    {
        m_uiCheckSpeechTimer = urand(30000, 60000);
        m_uiPostEventTimer = 1000;
        m_uiPhasePostEvent = 0;

        m_tortaGuid.Clear();
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        FollowerAI::MoveInLineOfSight(pWho);

        if (!m_creature->GetVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE | STATE_FOLLOW_POSTEVENT) && pWho->GetEntry() == NPC_TORTA)
        {
            if (m_creature->IsWithinDistInMap(pWho, INTERACTION_DISTANCE))
            {
                if (Player* pPlayer = GetLeaderForFollower())
                {
                    if (pPlayer->GetQuestStatus(QUEST_TOOGA) == QUEST_STATUS_INCOMPLETE)
                        pPlayer->GroupEventHappens(QUEST_TOOGA, m_creature);
                }

                m_tortaGuid = pWho->GetObjectGuid();
                SetFollowComplete(true);
            }
        }
    }

    void MovementInform(uint32 uiMotionType, uint32 uiPointId) override
    {
        FollowerAI::MovementInform(uiMotionType, uiPointId);

        if (uiMotionType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == POINT_ID_TO_WATER)
            SetFollowComplete();
    }

    void UpdateFollowerAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
        {
            //we are doing the post-event, or...
            if (HasFollowState(STATE_FOLLOW_POSTEVENT))
            {
                if (m_uiPostEventTimer < uiDiff)
                {
                    m_uiPostEventTimer = 5000;
                    Unit* pTorta = m_creature->GetMap()->GetCreature(m_tortaGuid);

                    if (!pTorta || !pTorta->IsAlive())
                    {
                        //something happened, so just complete
                        SetFollowComplete();
                        return;
                    }

                    switch (m_uiPhasePostEvent)
                    {
                        case 1:
                            DoScriptText(SAY_TOOG_POST_1, m_creature);
                            break;
                        case 2:
                            DoScriptText(SAY_TORT_POST_2, pTorta);
                            break;
                        case 3:
                            DoScriptText(SAY_TOOG_POST_3, m_creature);
                            break;
                        case 4:
                            DoScriptText(SAY_TORT_POST_4, pTorta);
                            break;
                        case 5:
                            DoScriptText(SAY_TOOG_POST_5, m_creature);
                            break;
                        case 6:
                            DoScriptText(SAY_TORT_POST_6, pTorta);
                            m_creature->GetMotionMaster()->MovePoint(POINT_ID_TO_WATER, m_afToWaterLoc[0], m_afToWaterLoc[1], m_afToWaterLoc[2]);
                            break;
                    }

                    ++m_uiPhasePostEvent;
                }
                else
                    m_uiPostEventTimer -= uiDiff;
            }
            //...we are doing regular speech check
            else if (HasFollowState(STATE_FOLLOW_INPROGRESS))
            {
                if (m_uiCheckSpeechTimer < uiDiff)
                {
                    m_uiCheckSpeechTimer = urand(30000, 60000);

                    if (Player* pPlayer = GetLeaderForFollower())
                        DoScriptText(urand(SAY_TOOGA_RANDOM_START, SAY_TOOGA_RANDOM_END), m_creature, pPlayer);
                }
                else
                    m_uiCheckSpeechTimer -= uiDiff;
            }

            return;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_tooga(Creature* pCreature)
{
    return new npc_toogaAI(pCreature);
}

bool QuestAccept_npc_tooga(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_TOOGA)
    {
        if (npc_toogaAI* pToogaAI = dynamic_cast<npc_toogaAI*>(pCreature->AI()))
            pToogaAI->StartFollow(pPlayer, FACTION_ESCORT_N_FRIEND_PASSIVE, pQuest);
    }

    return true;
}

// Chakor@nostalrius : quest "L'or de Cuergo"(id: 2882)
/*####
# go_inconspicuous_landmark
####*/
enum
{
    NPC_PIRATES_1 = 7899,
    NPC_PIRATES_2 = 7901,
    NPC_PIRATES_3 = 7902,
    GO_PIRATES_TREASURE = 142194
};

struct go_inconspicuous_landmarkAI: public GameObjectAI
{
    go_inconspicuous_landmarkAI(GameObject* pGo) : GameObjectAI(pGo)
    {
        timer = 0;
        state = 0;
    }
    uint32 timer;
    bool state;//0 = usual, can launch. //1 = in use, cannot launch

    void UpdateAI(uint32 const uiDiff) override
    {
        if (state)
        {
            if (timer < uiDiff)
            {
                state = 0;
                me->SetGoState(GO_STATE_READY);
                me->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
            }
            else
                timer -= uiDiff;
        }
    }
    bool CheckCanStartEvent()
    {
        return !state;
    }

    void SetInUse()
    {
        me->SetGoState(GO_STATE_ACTIVE);
        me->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        state = 1;
        timer = 600000;
    }
};
GameObjectAI* GetAIgo_inconspicuous_landmark(GameObject *pGo)
{
    return new go_inconspicuous_landmarkAI(pGo);
}
bool GOHello_go_inconspicuous_landmark(Player* pPlayer, GameObject* pGo)
{
    if (go_inconspicuous_landmarkAI* pMarkAI = dynamic_cast<go_inconspicuous_landmarkAI*>(pGo->AI()))
    {
        if (pMarkAI->CheckCanStartEvent())
        {
            pMarkAI->SetInUse();

            if (pGo->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
            {
                if (pPlayer->GetQuestStatus(2882) == QUEST_STATUS_INCOMPLETE)
                {
                    Creature* pirate1 = nullptr;
                    Creature* pirate2 = nullptr;
                    Creature* pirate3 = nullptr;
                    Creature* pirate4 = nullptr;
                    Creature* pirate5 = nullptr;
                    int extraPirateType[2];
                    extraPirateType[0] = NPC_PIRATES_1;
                    extraPirateType[1] = NPC_PIRATES_2;

                    if (pirate1 = pGo->SummonCreature(NPC_PIRATES_1, -10119.85f, -4068.36f, 4.55f, 1.35f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 310000))
                    {
                        pirate1->AI()->AttackStart(pPlayer);
                        pirate1->SetRespawnDelay(350000);
                    }
                    if (pirate2 = pGo->SummonCreature(NPC_PIRATES_2, -10109.80f, -4054.45f, 5.64f, 3.17f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 310000))
                    {
                        pirate2->AI()->AttackStart(pPlayer);
                        pirate2->SetRespawnDelay(350000);
                    }
                    if (pirate3 = pGo->SummonCreature(NPC_PIRATES_3, -10127.80f, -4047.04f, 4.50f, 5.07f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 310000))
                    {
                        pirate3->AI()->AttackStart(pPlayer);
                        pirate3->SetRespawnDelay(350000);
                    }

                    for (int & pirateEntry : extraPirateType)
                    {
                        switch (urand(0, 2))
                        {
                            case 0:
                                pirateEntry = NPC_PIRATES_1;
                                break;
                            case 1:
                                pirateEntry = NPC_PIRATES_2;
                                break;
                            case 2:
                                pirateEntry = NPC_PIRATES_3;
                                break;
                        }
                    }
                    if (pirate4 = pGo->SummonCreature(extraPirateType[0], -10113.952148f, -4040.484375f, 5.174251f, 4.300828f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 310000))
                    {
                        pirate4->AI()->AttackStart(pPlayer);
                        pirate4->SetRespawnDelay(350000);
                    }
                    if (pirate5 = pGo->SummonCreature(extraPirateType[1], -10136.779297f, -4063.175049f, 4.787039f, 0.526417f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 310000))
                    {
                        pirate5->AI()->AttackStart(pPlayer);
                        pirate5->SetRespawnDelay(350000);
                    }
                }
            }
        }
    }
    return true;
}

/*######
## npc_Yeh'Kinya
######*/

#define QUEST_YELL_HAKKAR_EVENT -1108998
#define SPELL_AV_VISUALTRANSFORM 24085
struct npc_yehkinyaAI : public npc_escortAI
{
    npc_yehkinyaAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Reset();
    }
    
    uint32 Event_Timer;
    bool   isEventStarted;
    uint32 Point;   
 
    void Reset() override
    {
        isEventStarted = false;
        m_creature->LoadEquipment(1315, true);
        m_creature->SetDisplayId(7902);
        Event_Timer = 0;
        m_creature->SetFly(false);
        m_creature->SetWalk(false);
    }

    void WaypointReached(uint32 i) override
    {
        switch (i)
        {
            case 1:
                m_creature->SetWalk(false);
                isEventStarted = true;
                m_creature->LoadEquipment(0, true);
                Event_Timer = 3000;
                DoCastSpellIfCan(m_creature, SPELL_AV_VISUALTRANSFORM);
                m_creature->SetDisplayId(1336);
                m_creature->SetFly(true);
                SetEscortPaused(true);
                break;
        }
    }

    void UpdateEscortAI(uint32 const diff) override
    {
        if (Event_Timer <= diff)
        {
            if(isEventStarted)
            {
                SetEscortPaused(false);
                m_creature->MonsterYell(QUEST_YELL_HAKKAR_EVENT, LANG_UNIVERSAL, 0);
                m_creature->SetWalk(false);
                Event_Timer = 15000;
            }
        }
        else
            Event_Timer -= diff;
    }
};

CreatureAI* GetAI_npc_yehkinya(Creature* pCreature)
{
    return new npc_yehkinyaAI(pCreature);
}

#define QUEST_HAKKAR_EVENT 8181
#define QUEST_TEXT_HAKKAR_EVENT -1108999

bool QuestRewarded_npc_yehkinya(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_HAKKAR_EVENT)
    {
        DoScriptText(QUEST_TEXT_HAKKAR_EVENT, pCreature);

        if (npc_yehkinyaAI* pEscortAI = dynamic_cast<npc_yehkinyaAI*>(pCreature->AI()))
        {
            pEscortAI->Start(true, 0, nullptr, true);
            pCreature->SetWalk(false);
        }
    }
    return true;
}

void AddSC_tanaris()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "npc_yehkinya";
    newscript->pQuestRewardedNPC = &QuestRewarded_npc_yehkinya;
    newscript->GetAI = &GetAI_npc_yehkinya;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_aquementas";
    newscript->GetAI = &GetAI_mob_aquementas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_tooga";
    newscript->GetAI = &GetAI_npc_tooga;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_tooga;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_inconspicuous_landmark";
    newscript->GOGetAI = &GetAIgo_inconspicuous_landmark;
    newscript->pGOHello = &GOHello_go_inconspicuous_landmark;
    newscript->RegisterSelf();
}
