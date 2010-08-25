/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Stormwind_City
SD%Complete: 100
SDComment: Quest support: 1640, 1447, 4185, 11223, 434.
SDCategory: Stormwind City
EndScriptData */

/* ContentData
npc_archmage_malin
npc_bartleby
npc_dashel_stonefist
npc_lady_katrana_prestor
npc_tyrion
npc_tyrion_spybot
npc_marzon_silent_blade
npc_lord_gregor_lescovar
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

/*######
## npc_archmage_malin
######*/

#define GOSSIP_ITEM_MALIN "Can you send me to Theramore? I have an urgent message for Lady Jaina from Highlord Bolvar."

class npc_archmage_malin : public CreatureScript
{
public:
    npc_archmage_malin() : CreatureScript("npc_archmage_malin") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (uiAction == GOSSIP_ACTION_INFO_DEF)
        {
            pPlayer->CLOSE_GOSSIP_MENU();
            pCreature->CastSpell(pPlayer, 42711, true);
        }

        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(11223) == QUEST_STATUS_COMPLETE && !pPlayer->GetQuestRewardStatus(11223))
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_MALIN, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

        return true;
    }

};


/*######
## npc_bartleby
######*/

enum eBartleby
{
    FACTION_ENEMY       = 168,
    QUEST_BEAT          = 1640
};

class npc_bartleby : public CreatureScript
{
public:
    npc_bartleby() : CreatureScript("npc_bartleby") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_BEAT)
        {
            pCreature->setFaction(FACTION_ENEMY);
            pCreature->AI()->AttackStart(pPlayer);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_bartlebyAI(pCreature);
    }

    struct npc_bartlebyAI : public ScriptedAI
    {
        npc_bartlebyAI(Creature *c) : ScriptedAI(c)
        {
            m_uiNormalFaction = c->getFaction();
        }

        uint32 m_uiNormalFaction;

        void Reset()
        {
            if (me->getFaction() != m_uiNormalFaction)
                me->setFaction(m_uiNormalFaction);
        }

        void AttackedBy(Unit* pAttacker)
        {
            if (me->getVictim())
                return;

            if (me->IsFriendlyTo(pAttacker))
                return;

            AttackStart(pAttacker);
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if (uiDamage > me->GetHealth() || me->HealthBelowPctDamaged(15, uiDamage))
            {
                //Take 0 damage
                uiDamage = 0;

                if (pDoneBy->GetTypeId() == TYPEID_PLAYER)
                    CAST_PLR(pDoneBy)->AreaExploredOrEventHappens(QUEST_BEAT);
                EnterEvadeMode();
            }
        }
    };

};



/*######
## npc_dashel_stonefist
######*/

enum eDashel
{
    QUEST_MISSING_DIPLO_PT8     = 1447,
    FACTION_HOSTILE             = 168
};

class npc_dashel_stonefist : public CreatureScript
{
public:
    npc_dashel_stonefist() : CreatureScript("npc_dashel_stonefist") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_MISSING_DIPLO_PT8)
        {
            pCreature->setFaction(FACTION_HOSTILE);
            CAST_AI(npc_dashel_stonefist::npc_dashel_stonefistAI, pCreature->AI())->AttackStart(pPlayer);
        }
        return true;
    }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_dashel_stonefistAI(pCreature);
    }

    struct npc_dashel_stonefistAI : public ScriptedAI
    {
        npc_dashel_stonefistAI(Creature *c) : ScriptedAI(c)
        {
            m_uiNormalFaction = c->getFaction();
        }

        uint32 m_uiNormalFaction;

        void Reset()
        {
            if (me->getFaction() != m_uiNormalFaction)
                me->setFaction(m_uiNormalFaction);
        }

        void AttackedBy(Unit* pAttacker)
        {
            if (me->getVictim())
                return;

            if (me->IsFriendlyTo(pAttacker))
                return;

            AttackStart(pAttacker);
        }

        void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
        {
            if (uiDamage > me->GetHealth() || me->HealthBelowPctDamaged(15, uiDamage))
            {
                uiDamage = 0;

                if (pDoneBy->GetTypeId() == TYPEID_PLAYER)
                    CAST_PLR(pDoneBy)->AreaExploredOrEventHappens(QUEST_MISSING_DIPLO_PT8);

                EnterEvadeMode();
            }
        }
    };

};



/*######
## npc_lady_katrana_prestor
######*/

#define GOSSIP_ITEM_KAT_1 "Pardon the intrusion, Lady Prestor, but Highlord Bolvar suggested that I seek your advice."
#define GOSSIP_ITEM_KAT_2 "My apologies, Lady Prestor."
#define GOSSIP_ITEM_KAT_3 "Begging your pardon, Lady Prestor. That was not my intent."
#define GOSSIP_ITEM_KAT_4 "Thank you for your time, Lady Prestor."

class npc_lady_katrana_prestor : public CreatureScript
{
public:
    npc_lady_katrana_prestor() : CreatureScript("npc_lady_katrana_prestor") { }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAT_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                pPlayer->SEND_GOSSIP_MENU(2694, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAT_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                pPlayer->SEND_GOSSIP_MENU(2695, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAT_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                pPlayer->SEND_GOSSIP_MENU(2696, pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                pPlayer->CLOSE_GOSSIP_MENU();
                pPlayer->AreaExploredOrEventHappens(4185);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        if (pPlayer->GetQuestStatus(4185) == QUEST_STATUS_INCOMPLETE)
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_KAT_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        pPlayer->SEND_GOSSIP_MENU(2693, pCreature->GetGUID());

        return true;
    }

};


/*######
## npc_lord_gregor_lescovar
######*/

enum eLordGregorLescovar
{
    SAY_LESCOVAR_2 = -1000457,
    SAY_GUARD_2    = -1000458,
    SAY_LESCOVAR_3 = -1000459,
    SAY_MARZON_1   = -1000460,
    SAY_LESCOVAR_4 = -1000461,
    SAY_TYRION_2   = -1000462,
    SAY_MARZON_2   = -1000463,

    NPC_STORMWIND_ROYAL = 1756,
    NPC_MARZON_BLADE    = 1755,
    NPC_TYRION          = 7766,

    QUEST_THE_ATTACK    = 434
};

class npc_lord_gregor_lescovar : public CreatureScript
{
public:
    npc_lord_gregor_lescovar() : CreatureScript("npc_lord_gregor_lescovar") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_lord_gregor_lescovarAI(pCreature);
    }

    struct npc_lord_gregor_lescovarAI : public npc_escortAI
    {
        npc_lord_gregor_lescovarAI(Creature* pCreature) : npc_escortAI(pCreature)
        {
            pCreature->RestoreFaction();
        }

        uint32 uiTimer;
        uint32 uiPhase;

        uint64 MarzonGUID;

        void Reset()
        {
            uiTimer = 0;
            uiPhase = 0;

            MarzonGUID = 0;
        }

        void EnterEvadeMode()
        {
            me->DisappearAndDie();

            if (Creature *pMarzon = Unit::GetCreature(*me, MarzonGUID))
            {
                if (pMarzon->isAlive())
                    pMarzon->DisappearAndDie();
            }
        }

        void EnterCombat(Unit* pWho)
        {
            if (Creature *pMarzon = Unit::GetCreature(*me, MarzonGUID))
            {
                if (pMarzon->isAlive() && !pMarzon->isInCombat())
                    pMarzon->AI()->AttackStart(pWho);
            }
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                case 14:
                    SetEscortPaused(true);
                    DoScriptText(SAY_LESCOVAR_2, me);
                    uiTimer = 3000;
                    uiPhase = 1;
                    break;
                case 16:
                    SetEscortPaused(true);
                    if (Creature *pMarzon = me->SummonCreature(NPC_MARZON_BLADE,-8411.360352f, 480.069733f, 123.760895f, 4.941504f, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000))
                    {
                        pMarzon->GetMotionMaster()->MovePoint(0,-8408.000977f, 468.611450f, 123.759903f);
                        MarzonGUID = pMarzon->GetGUID();
                    }
                    uiTimer = 2000;
                    uiPhase = 4;
                    break;
            }
        }
        //TO-DO: We don't have movemaps, also we can't make 2 npcs walks to one point propperly (and we can not use escort ai, because they are 2 different spawns and with same entry), because of it we make them, disappear.
        void DoGuardsDisappearAndDie()
        {
            std::list<Creature*> GuardList;
            me->GetCreatureListWithEntryInGrid(GuardList,NPC_STORMWIND_ROYAL,8.0f);
            if (!GuardList.empty())
            {
                for (std::list<Creature*>::const_iterator itr = GuardList.begin(); itr != GuardList.end(); ++itr)
                {
                    if (Creature* pGuard = *itr)
                        pGuard->DisappearAndDie();
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch(uiPhase)
                    {
                        case 1:
                            if (Creature* pGuard = me->FindNearestCreature(NPC_STORMWIND_ROYAL, 8.0f, true))
                                DoScriptText(SAY_GUARD_2, pGuard);
                            uiTimer = 3000;
                            uiPhase = 2;
                            break;
                        case 2:
                            DoGuardsDisappearAndDie();
                            uiTimer = 2000;
                            uiPhase = 3;
                            break;
                        case 3:
                            SetEscortPaused(false);
                            uiTimer = 0;
                            uiPhase = 0;
                            break;
                        case 4:
                            DoScriptText(SAY_LESCOVAR_3, me);
                            uiTimer = 0;
                            uiPhase = 0;
                            break;
                        case 5:
                            if (Creature *pMarzon = Unit::GetCreature(*me, MarzonGUID))
                                DoScriptText(SAY_MARZON_1, pMarzon);
                            uiTimer = 3000;
                            uiPhase = 6;
                            break;
                        case 6:
                            DoScriptText(SAY_LESCOVAR_4, me);
                            if (Player* pPlayer = GetPlayerForEscort())
                                pPlayer->AreaExploredOrEventHappens(QUEST_THE_ATTACK);
                            uiTimer = 2000;
                            uiPhase = 7;
                            break;
                        case 7:
                            if (Creature* pTyrion = me->FindNearestCreature(NPC_TYRION, 20.0f, true))
                                DoScriptText(SAY_TYRION_2, pTyrion);
                            if (Creature *pMarzon = Unit::GetCreature(*me, MarzonGUID))
                                pMarzon->setFaction(14);
                            me->setFaction(14);
                            uiTimer = 0;
                            uiPhase = 0;
                            break;
                    }
                } else uiTimer -= uiDiff;
            }
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};


/*######
## npc_marzon_silent_blade
######*/

class npc_marzon_silent_blade : public CreatureScript
{
public:
    npc_marzon_silent_blade() : CreatureScript("npc_marzon_silent_blade") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_marzon_silent_bladeAI(pCreature);
    }

    struct npc_marzon_silent_bladeAI : public ScriptedAI
    {
        npc_marzon_silent_bladeAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_WALKING);
        }

        void Reset()
        {
            me->RestoreFaction();
        }

        void EnterCombat(Unit* pWho)
        {
            DoScriptText(SAY_MARZON_2, me);

            if (me->isSummon())
            {
                if (Unit* pSummoner = CAST_SUM(me)->GetSummoner())
                {
                    if (pSummoner && pSummoner->isAlive() && !pSummoner->isInCombat())
                        CAST_CRE(pSummoner)->AI()->AttackStart(pWho);
                }
            }
        }

        void EnterEvadeMode()
        {
            me->DisappearAndDie();

            if (me->isSummon())
            {
                if (Unit* pSummoner = CAST_SUM(me)->GetSummoner())
                {
                    if (pSummoner && pSummoner->isAlive())
                        CAST_CRE(pSummoner)->DisappearAndDie();
                }
            }
        }

        void MovementInform(uint32 uiType, uint32 /*uiId*/)
        {
            if (uiType != POINT_MOTION_TYPE)
                return;

            if (me->isSummon())
            {
                if (Unit* pSummoner = CAST_SUM(me)->GetSummoner())
                {
                    CAST_AI(npc_lord_gregor_lescovar::npc_lord_gregor_lescovarAI, CAST_CRE(pSummoner)->AI())->uiTimer = 2000;
                    CAST_AI(npc_lord_gregor_lescovar::npc_lord_gregor_lescovarAI, CAST_CRE(pSummoner)->AI())->uiPhase = 5;
                    //me->ChangeOrient(0.0f, pSummoner);
                }
            }
        }

        void UpdateAI(const uint32 /*diff*/)
        {
            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};


/*######
## npc_tyrion_spybot
######*/

enum eTyrionSpybot
{
    SAY_QUEST_ACCEPT_ATTACK  = -1000499,
    SAY_TYRION_1             = -1000450,
    SAY_SPYBOT_1             = -1000451,
    SAY_GUARD_1              = -1000452,
    SAY_SPYBOT_2             = -1000453,
    SAY_SPYBOT_3             = -1000454,
    SAY_LESCOVAR_1           = -1000455,
    SAY_SPYBOT_4             = -1000456,

    NPC_PRIESTESS_TYRIONA    = 7779,
    NPC_LORD_GREGOR_LESCOVAR = 1754,
};

class npc_tyrion_spybot : public CreatureScript
{
public:
    npc_tyrion_spybot() : CreatureScript("npc_tyrion_spybot") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_tyrion_spybotAI(pCreature);
    }

    struct npc_tyrion_spybotAI : public npc_escortAI
    {
        npc_tyrion_spybotAI(Creature* pCreature) : npc_escortAI(pCreature) {}

        uint32 uiTimer;
        uint32 uiPhase;

        void Reset()
        {
            uiTimer = 0;
            uiPhase = 0;
        }

        void WaypointReached(uint32 uiPointId)
        {
            switch(uiPointId)
            {
                case 1:
                    SetEscortPaused(true);
                    uiTimer = 2000;
                    uiPhase = 1;
                    break;
                case 5:
                    SetEscortPaused(true);
                    DoScriptText(SAY_SPYBOT_1, me);
                    uiTimer = 2000;
                    uiPhase = 5;
                    break;
                case 17:
                    SetEscortPaused(true);
                    DoScriptText(SAY_SPYBOT_3, me);
                    uiTimer = 3000;
                    uiPhase = 8;
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch(uiPhase)
                    {
                        case 1:
                            DoScriptText(SAY_QUEST_ACCEPT_ATTACK, me);
                            uiTimer = 3000;
                            uiPhase = 2;
                            break;
                        case 2:
                            if (Creature* pTyrion = me->FindNearestCreature(NPC_TYRION,10.0f))
                                DoScriptText(SAY_TYRION_1, pTyrion);
                            uiTimer = 3000;
                            uiPhase = 3;
                            break;
                        case 3:
                            me->UpdateEntry(NPC_PRIESTESS_TYRIONA, ALLIANCE);
                            uiTimer = 2000;
                            uiPhase = 4;
                            break;
                        case 4:
                           SetEscortPaused(false);
                           uiPhase = 0;
                           uiTimer = 0;
                           break;
                        case 5:
                            if (Creature* pGuard = me->FindNearestCreature(NPC_STORMWIND_ROYAL, 10.0f, true))
                                DoScriptText(SAY_GUARD_1, pGuard);
                            uiTimer = 3000;
                            uiPhase = 6;
                            break;
                        case 6:
                            DoScriptText(SAY_SPYBOT_2, me);
                            uiTimer = 3000;
                            uiPhase = 7;
                            break;
                        case 7:
                            SetEscortPaused(false);
                            uiTimer = 0;
                            uiPhase = 0;
                            break;
                        case 8:
                            if (Creature* pLescovar = me->FindNearestCreature(NPC_LORD_GREGOR_LESCOVAR,10.0f))
                                DoScriptText(SAY_LESCOVAR_1, pLescovar);
                            uiTimer = 3000;
                            uiPhase = 9;
                            break;
                        case 9:
                            DoScriptText(SAY_SPYBOT_4, me);
                            uiTimer = 3000;
                            uiPhase = 10;
                            break;
                        case 10:
                            if (Creature* pLescovar = me->FindNearestCreature(NPC_LORD_GREGOR_LESCOVAR,10.0f))
                            {
                                if (Player* pPlayer = GetPlayerForEscort())
                                {
                                    CAST_AI(npc_lord_gregor_lescovar::npc_lord_gregor_lescovarAI,pLescovar->AI())->Start(false, false, pPlayer->GetGUID());
                                    CAST_AI(npc_lord_gregor_lescovar::npc_lord_gregor_lescovarAI, pLescovar->AI())->SetMaxPlayerDistance(200.0f);
                                }
                            }
                            me->DisappearAndDie();
                            uiTimer = 0;
                            uiPhase = 0;
                            break;
                    }
                } else uiTimer -= uiDiff;
            }
            npc_escortAI::UpdateAI(uiDiff);

            if (!UpdateVictim())
                return;

            DoMeleeAttackIfReady();
        }
    };

};


/*######
## npc_tyrion
######*/

enum eTyrion
{
    NPC_TYRION_SPYBOT = 8856
};

class npc_tyrion : public CreatureScript
{
public:
    npc_tyrion() : CreatureScript("npc_tyrion") { }

    bool OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const *pQuest)
    {
        if (pQuest->GetQuestId() == QUEST_THE_ATTACK)
        {
            if (Creature* pSpybot = pCreature->FindNearestCreature(NPC_TYRION_SPYBOT, 5.0f, true))
            {
                CAST_AI(npc_tyrion_spybot::npc_tyrion_spybotAI,pSpybot->AI())->Start(false, false, pPlayer->GetGUID());
                CAST_AI(npc_tyrion_spybot::npc_tyrion_spybotAI,pSpybot->AI())->SetMaxPlayerDistance(200.0f);
            }
            return true;
        }
        return false;
    }

};

void AddSC_stormwind_city()
{
    new npc_archmage_malin();
    new npc_bartleby();
    new npc_dashel_stonefist();
    new npc_lady_katrana_prestor();
    new npc_tyrion();
    new npc_tyrion_spybot();
    new npc_lord_gregor_lescovar();
    new npc_marzon_silent_blade();
}
