/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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

#include "ScriptedPch.h"
#include "ScriptedEscortAI.h"

/*####
## npc_drakuru_shackles
####*/

enum eDrakuruShackles
{
    SPELL_LEFT_CHAIN           = 59951,
    SPELL_RIGHT_CHAIN          = 59952,
    SPELL_UNLOCK_SHACKLE       = 55083,
    SPELL_FREE_RAGECLAW        = 55223,

    NPC_RAGECLAW               = 29686
};

struct npc_drakuru_shacklesAI : public ScriptedAI
{
    npc_drakuru_shacklesAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    Unit* Rageclaw;

    void Reset()
    {
        Rageclaw = NULL;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        float x, y, z;
        m_creature->GetClosePoint(x, y, z, m_creature->GetObjectSize() / 3, 0.1f);

        if (Unit* summon = m_creature->SummonCreature(NPC_RAGECLAW, x, y, z,
            0, TEMPSUMMON_DEAD_DESPAWN, 1000))
        {
            Rageclaw = summon;
            LockRageclaw();
        }
    }

    void LockRageclaw()
    {
        m_creature->SetInFront(Rageclaw);
        Rageclaw->SetInFront(m_creature);

        DoCast(Rageclaw, SPELL_LEFT_CHAIN, true);
        DoCast(Rageclaw, SPELL_RIGHT_CHAIN, true);
    }

    void UnlockRageclaw(Unit* pWho)
    {
        if (!pWho)
            return;

        DoCast(Rageclaw, SPELL_FREE_RAGECLAW, true);

        m_creature->setDeathState(DEAD);
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_UNLOCK_SHACKLE)
        {
            if (Rageclaw)
                UnlockRageclaw(pCaster);
            else
                m_creature->setDeathState(JUST_DIED);
        }
    }
};


CreatureAI* GetAI_npc_drakuru_shackles(Creature* pCreature)
{
    return new npc_drakuru_shacklesAI (pCreature);
}

/*####
## npc_captured_rageclaw
####*/

enum eRageclaw
{
    SPELL_UNSHACKLED           = 55085,
    SPELL_KNEEL                = 39656
};

const char * SAY_RAGECLAW_1 =      "I poop on you, trollses!";
const char * SAY_RAGECLAW_2 =      "ARRRROOOOGGGGAAAA!";
const char * SAY_RAGECLAW_3 =      "No more mister nice wolvar!";

#define SAY_RAGECLAW RAND(SAY_RAGECLAW_1,SAY_RAGECLAW_2,SAY_RAGECLAW_3)

struct npc_captured_rageclawAI : public ScriptedAI
{
    npc_captured_rageclawAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 DespawnTimer;
    bool Despawn;

    void Reset()
    {
        Despawn = false;
        DespawnTimer = 0;
        m_creature->setFaction(35);
        DoCast(m_creature, SPELL_KNEEL, true); // Little Hack for kneel - Thanks Illy :P
    }

    void MoveInLineOfSight(Unit *who){}

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_FREE_RAGECLAW)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_LEFT_CHAIN);

            m_creature->RemoveAurasDueToSpell(SPELL_RIGHT_CHAIN);

            m_creature->RemoveAurasDueToSpell(SPELL_KNEEL);

            m_creature->setFaction(m_creature->GetCreatureInfo()->faction_H);

            DoCast(m_creature, SPELL_UNSHACKLED, true);
            m_creature->MonsterSay(SAY_RAGECLAW, LANG_UNIVERSAL, NULL);
            m_creature->GetMotionMaster()->MoveRandom(10);

            DespawnTimer = 10000;
            Despawn = true;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (UpdateVictim())
        {
            DoMeleeAttackIfReady();
            return;
        }

        if (!Despawn)
            return;

        if (DespawnTimer <= uiDiff)
            m_creature->DisappearAndDie();
        else DespawnTimer -= uiDiff;
   }
};

CreatureAI* GetAI_npc_captured_rageclaw(Creature* pCreature)
{
    return new npc_captured_rageclawAI (pCreature);
}

/*####
## npc_gymer
####*/

#define    GOSSIP_ITEM_G "I'm ready, Gymer. Let's go!"

enum eGymer
{
    QUEST_STORM_KING_VENGEANCE    = 12919,
    SPELL_GYMER                   = 55568
};

bool GossipHello_npc_gymer(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_STORM_KING_VENGEANCE) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_G, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(13640, pCreature->GetGUID());
    }

    return true;
}

bool GossipSelect_npc_gymer(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_GYMER, true);
    }

    return true;
}

/*####
## npc_gurgthock
####*/

enum eGurgthock
{
    QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON   = 12935,
    QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER = 12936,
    QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2         = 12954,
    QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1         = 12932,
    QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR         = 12933,

    NPC_ORINOKO_TUSKBREAKER = 30020,
    NPC_KORRAK_BLOODRAGER   = 30023,
    NPC_YGGDRAS             = 30014,
    NPC_STINKBEARD          = 30017,

    SAY_QUEST_ACCEPT_TUSKARRMAGEDON = -1571031,
    SAY_QUEST_ACCEPT_KORRAK_1       = -1571033,
    SAY_QUEST_ACCEPT_KORRAK_2       = -1571034,
    SAY_QUEST_ACCEPT_MAGNATAUR      = -1571035
};

const Position SpawnPosition[] =
{
  {5757.765137, -2945.161133, 286.276672, 5.156380},
  {5762.054199, -2954.385010, 273.826955, 5.108289}  //yggdras
};

struct npc_gurgthockAI : public ScriptedAI
{
    npc_gurgthockAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pSummon = NULL;
    }

    Unit* pSummon;

    std::list<uint64> SummonList;

    uint32 uiTimer;
    uint32 uiPhase;
    uint32 uiRemoveFlagTimer;
    uint32 uiQuest;

    bool bEventInProgress;
    bool bRemoveFlag;

    void Reset()
    {
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        uiTimer = 0;
        uiPhase = 0;
        uiQuest = 0;
        uiRemoveFlagTimer = 5000;
        bEventInProgress = false;
        bRemoveFlag = false;
    }

    void RemoveSummons()
    {
        if (SummonList.empty())
            return;

        bEventInProgress = false;

        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

        for(std::list<uint64>::iterator itr = SummonList.begin(); itr != SummonList.end(); ++itr)
        {
            if (Creature* pTemp = (Creature*)Unit::GetUnit(*m_creature, *itr))
                if (pTemp)
                    pTemp->RemoveFromWorld();
        }
        SummonList.clear();
    }

    void SetData(uint32 uiId, uint32 uiValue)
    {
        if (!bEventInProgress)
        {
            bEventInProgress = true;
            bRemoveFlag = true;
            switch(uiId)
            {
                case 1:
                    switch(uiValue)
                    {
                        case QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON:
                            DoScriptText(SAY_QUEST_ACCEPT_TUSKARRMAGEDON, m_creature);
                            uiPhase = 1;
                            uiTimer = 4000;
                            break;
                        case QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER:
                            DoScriptText(SAY_QUEST_ACCEPT_KORRAK_1, m_creature);
                            uiPhase = 3;
                            uiTimer = 3000;
                            break;
                        case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2:
                        case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1:
                            uiPhase = 6;
                            uiTimer = 3000;
                            break;
                        case QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR:
                            uiTimer = 5000;
                            uiPhase = 7;
                            break;
                        }
                        break;
                }
            }
        }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!bEventInProgress)
            return;

        ScriptedAI::UpdateAI(uiDiff);

        if (bRemoveFlag)
        {
            if (uiRemoveFlagTimer <= uiDiff)
            {
                m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                bRemoveFlag = false;
                uiRemoveFlagTimer = 5000;
            } else uiRemoveFlagTimer -= uiDiff;
        }

        if (uiPhase)
        {
            if (uiTimer <= uiDiff)
            {
                switch(uiPhase)
                {
                    case 1:
                        pSummon = m_creature->SummonCreature(NPC_ORINOKO_TUSKBREAKER, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                        uiPhase = 2;
                        uiTimer = 4000;
                        break;
                     case 2:
                        if (pSummon)
                            pSummon->GetMotionMaster()->MoveJump(5776.319824, -2981.005371, 273.100037, 10.0f, 20.0f);
                        uiPhase = 0;
                        pSummon = NULL;
                        break;
                    case 3:
                        DoScriptText(SAY_QUEST_ACCEPT_KORRAK_2, m_creature);
                        uiTimer = 3000;
                        uiPhase = 4;
                        break;
                    case 4:
                        pSummon = m_creature->SummonCreature(NPC_KORRAK_BLOODRAGER, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                        uiTimer = 3000;
                        uiPhase = 0;
                        break;
                    case 6:
                        m_creature->SummonCreature(NPC_YGGDRAS, SpawnPosition[1], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                        uiPhase = 0;
                        break;
                    case 7:
                        DoScriptText(SAY_QUEST_ACCEPT_MAGNATAUR, m_creature);
                        uiTimer = 3000;
                        uiPhase = 8;
                        break;
                    case 8:
                        m_creature->SummonCreature(NPC_STINKBEARD, SpawnPosition[0], TEMPSUMMON_CORPSE_DESPAWN, 1000);
                        uiPhase = 0;
                        break;
                }
            } else uiTimer -= uiDiff;
        }
    }

    void JustSummoned(Creature* pSummon)
    {
        SummonList.push_back(pSummon->GetGUID());
    }

    void SummonedCreatureDespawn(Creature* pSummon)
    {
        if (bEventInProgress)
            bEventInProgress = false;

        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
    }
};

bool QuestAccept_npc_gurgthock(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    switch (pQuest->GetQuestId())
    {
        case QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON:
            pCreature->AI()->SetData(1, pQuest->GetQuestId());
            break;
        case QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER:
            pCreature->AI()->SetData(1, pQuest->GetQuestId());
            break;
        case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2:
        case QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1:
            pCreature->AI()->SetData(1, pQuest->GetQuestId());
            break;
        case QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR:
            pCreature->AI()->SetData(1, pQuest->GetQuestId());
            break;
    }
    return false;
}

CreatureAI* GetAI_npc_gurgthock(Creature* pCreature)
{
    return new npc_gurgthockAI(pCreature);
}

/*####
## npc_orinoko_tuskbreaker
####*/

enum eOrinokoTuskbreaker
{
    SPELL_BATTLE_SHOUT      = 32064,
    SPELL_FISHY_SCENT       = 55937,
    SPELL_IMPALE            = 55929,
    SPELL_SUMMON_WHISKER    = 55946,

    NPC_WHISKER             = 30113,
    NPC_HUNGRY_PENGUIN      = 30110,

    SAY_CALL_FOR_HELP       = -1571032
};

struct npc_orinoko_tuskbreakerAI : public ScriptedAI
{
    npc_orinoko_tuskbreakerAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetReactState(REACT_PASSIVE);
    }

    bool bSummoned;
    bool bBattleShout;
    bool bFishyScent;

    uint32 uiBattleShoutTimer;
    uint32 uiFishyScentTimer;

    Unit* pAffected;
    uint64 uiWhisker;

    void Reset()
    {
        bSummoned           = false;
        bBattleShout        = false;
        bFishyScent         = false;
        uiBattleShoutTimer  = 0;
        uiFishyScentTimer   = 20000;
        uiWhisker           = 0;
        pAffected           = NULL;
    }

    void EnterEvadeMode()
    {
        if (uiWhisker)
            if (Creature *pWhisker = m_creature->GetCreature(*m_creature, uiWhisker))
                pWhisker->RemoveFromWorld();

        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->RemoveSummons();
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetReactState(REACT_AGGRESSIVE);
        m_creature->SetHomePosition(m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(), 0);
        uiBattleShoutTimer  = 7000;
    }

    void EnterCombat(Unit* pWho)
    {
        DoCast(pWho, SPELL_IMPALE);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (!bBattleShout && uiBattleShoutTimer <= uiDiff)
        {
            DoCast(m_creature, SPELL_BATTLE_SHOUT);
            bBattleShout = true;
        } else uiBattleShoutTimer -= uiDiff;

        if (uiFishyScentTimer <= uiDiff)
        {
            if (pAffected = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(pAffected, SPELL_FISHY_SCENT);
            uiFishyScentTimer = 20000;
        } else uiFishyScentTimer -= uiDiff;

        if (!bSummoned && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 50)
        {
            DoScriptText(SAY_CALL_FOR_HELP ,m_creature);
            //DoCast(m_creature->getVictim(), SPELL_SUMMON_WHISKER); petai is not working correctly???
            
            if (Creature *pWhisker = m_creature->SummonCreature(NPC_WHISKER, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
                uiWhisker = pWhisker->GetGUID();
            bSummoned = true;
        }

        DoMeleeAttackIfReady();
    }

    void JustSummoned(Creature* pSummon)
    {
        switch(pSummon->GetEntry())
        {
            case NPC_WHISKER:
                pSummon->AI()->AttackStart(m_creature->getVictim());
                break;
            case NPC_HUNGRY_PENGUIN:
                if (pAffected && pAffected->isAlive())
                    pSummon->AI()->AttackStart(pAffected);
                break;
        }
    }

    void JustDied(Unit* pKiller)
    {
        if (uiWhisker)
            if (Creature *pWhisker = m_creature->GetCreature(*m_creature, uiWhisker))
                pWhisker->RemoveFromWorld();

        if (pKiller->GetTypeId() == TYPEID_PLAYER)
            CAST_PLR(pKiller)->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_TUSKARRMAGEDDON, CAST_PLR(pKiller));

        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->bEventInProgress = false;
    }
};

CreatureAI* GetAI_npc_orinoko_tuskbreaker(Creature* pCreature)
{
    return new npc_orinoko_tuskbreakerAI(pCreature);
}

/*####
## npc_korrak_bloodrager
####*/

enum eKorrakBloodrager
{
    SPELL_GROW     = 55948,
    SPELL_CHARGE   = 24193,
    SPELL_UPPERCUT = 30471,
    SPELL_ENRAGE   = 42745
};

struct npc_korrak_bloodragerAI : public npc_escortAI
{
    npc_korrak_bloodragerAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        Start(true,true, 0, NULL);
        SetDespawnAtEnd(false);
    }

    uint32 uiChargeTimer;
    uint32 uiUppercutTimer;

    bool bEnrage;

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetReactState(REACT_PASSIVE);
        uiChargeTimer = 15000;
        uiUppercutTimer = 12000;
        bEnrage = false;
    }

    void EnterEvadeMode()
    {
        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->RemoveSummons();
    }

    void WaypointReached(uint32 uiI)
    {
        switch(uiI)
        {
            case 6:
                m_creature->SetHomePosition(m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(), 0);
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                m_creature->SetReactState(REACT_AGGRESSIVE);
                break;
        }
    }

    void EnterCombat(Unit* pWho)
    {
        DoCast(m_creature, SPELL_GROW);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (!UpdateVictim())
            return;

        if (uiUppercutTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_NEAREST, 0))
                DoCast(pTarget, SPELL_UPPERCUT);
            uiUppercutTimer = 12000;
        } else uiUppercutTimer -= uiDiff;

        if (uiChargeTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_FARTHEST, 0))
                DoCast(pTarget, SPELL_CHARGE);
            uiChargeTimer = 15000;
        } else uiChargeTimer -= uiDiff;

        if (!bEnrage && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 20)
        {
            DoCast(m_creature, SPELL_ENRAGE);
            bEnrage = true;
        }
        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pKiller->GetTypeId() == TYPEID_PLAYER)
            CAST_PLR(pKiller)->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_KORRAK_BLOODRAGER, CAST_PLR(pKiller));

        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->bEventInProgress = false;
    }
};

CreatureAI* GetAI_npc_korrak_bloodrager(Creature* pCreature)
{
    return new npc_korrak_bloodragerAI(pCreature);
}

/*####
## npc_yggdras
####*/

enum eYggdras
{
    SPELL_CLEAVE            = 40504,
    SPELL_CORRODE_FLESH     = 57076,
    SPELL_JORMUNGAR_SPAWN   = 55859
};

struct npc_yggdrasAI : public ScriptedAI
{
    npc_yggdrasAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 uiCleaveTimer;
    uint32 uiCorrodeFleshTimer;

    void Reset()
    {
        uiCleaveTimer = 12000;
        uiCorrodeFleshTimer = 18000;
    }

    void EnterEvadeMode() //If you lose the combat, then the npc go away
    {
        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->RemoveSummons();
    }

    void EnterCombat(Unit* pWho)
    {
        DoCast(m_creature, SPELL_GROW);
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (uiCleaveTimer <= uiDiff)
        {
            DoCast(m_creature->getVictim(), SPELL_CLEAVE);
            uiCleaveTimer = 12000;
        } else uiCleaveTimer -= uiDiff;

        if (uiCorrodeFleshTimer <= uiDiff)
        {
            DoCast(m_creature->getVictim(), SPELL_CHARGE);
            uiCorrodeFleshTimer = 18000;
        } else uiCorrodeFleshTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pKiller->GetTypeId() == TYPEID_PLAYER)
        {
            CAST_PLR(pKiller)->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_1, CAST_PLR(pKiller));
            CAST_PLR(pKiller)->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_YGGDRAS_2, CAST_PLR(pKiller));
        }

        for (uint8 i = 0; i < 2; ++i)
            DoCast(pKiller, SPELL_JORMUNGAR_SPAWN, true);

        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->bEventInProgress = false;
    }
};

CreatureAI* GetAI_npc_yggdras(Creature* pCreature)
{
    return new npc_yggdrasAI(pCreature);
}

enum eStinkbeard
{
    SPELL_ENRAGE_STINKBEARD = 50420,
    SPELL_KNOCK_AWAY        = 31389,
    SPELL_STINKY_BEARD      = 55867,
    SPELL_THUNDERBLADE      = 55866,
    SPELL_THUNDERCLAP       = 15588
};

/*####
## npc_stinkbeard
####*/

struct npc_stinkbeardAI : public npc_escortAI
{
    npc_stinkbeardAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
        m_creature->SetReactState(REACT_PASSIVE);
        Start(true,true, 0, NULL);
        SetDespawnAtEnd(false);
    }

    uint32 uiThunderclapTimer;
    uint32 uiKnockAwayTimer;
    uint32 uiStinkyBeardTimer;

    bool bEnrage;

    void Reset()
    {
        DoCast(m_creature, SPELL_THUNDERBLADE);
        uiThunderclapTimer = 5000;
        uiKnockAwayTimer   = 10000;
        uiStinkyBeardTimer = 15000;
        bEnrage = false;
    }

    void EnterEvadeMode()
    {
        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->RemoveSummons();
    }

    void WaypointReached(uint32 uiI)
    {
        switch(uiI)
        {
            case 7:
                m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
                m_creature->SetReactState(REACT_AGGRESSIVE);
                m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetOrientation());
                break;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        npc_escortAI::UpdateAI(uiDiff);

        if (!UpdateVictim())
            return;

        if (uiThunderclapTimer <= uiDiff)
        {
            DoCastAOE(SPELL_THUNDERCLAP);
            uiThunderclapTimer = 5000;
        } else uiThunderclapTimer -= uiDiff;

        if (uiKnockAwayTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget, SPELL_KNOCK_AWAY);
            }
            uiKnockAwayTimer = 10000;
        } else uiKnockAwayTimer -= uiDiff;

        if (uiStinkyBeardTimer <= uiDiff)
        {
            if (Unit* pTarget = SelectUnit(SELECT_TARGET_RANDOM, 0))
            {
                if (pTarget && pTarget->isAlive())
                    DoCast(pTarget, SPELL_STINKY_BEARD);
            }
            uiStinkyBeardTimer = 15000;
        } else uiStinkyBeardTimer -= uiDiff;

       if (!bEnrage && m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 20)
        {
            DoCast(m_creature, SPELL_ENRAGE_STINKBEARD);
            bEnrage = true;
        }
        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (m_creature->isSummon())
            if (Creature* pSummoner = CAST_CRE(CAST_SUM(m_creature)->GetSummoner()))
                if (npc_gurgthockAI* pAI = CAST_AI(npc_gurgthockAI,pSummoner->AI()))
                    pAI->bEventInProgress = false;

        if (pKiller->GetTypeId() == TYPEID_PLAYER)
           CAST_PLR(pKiller)->GroupEventHappens(QUEST_AMPHITHEATER_ANGUISH_MAGNATAUR, CAST_PLR(pKiller));
    }
};

CreatureAI* GetAI_npc_stinkbeard(Creature* pCreature)
{
    return new npc_stinkbeardAI(pCreature);
}

/*####
## npc_released_offspring_harkoa
####*/

struct npc_released_offspring_harkoaAI : public ScriptedAI
{
    npc_released_offspring_harkoaAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void Reset()
    {
        float x, y, z;
        m_creature->GetClosePoint(x, y, z, m_creature->GetObjectSize() / 3, 25.0f);
        m_creature->GetMotionMaster()->MovePoint(0, x, y, z);
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;
        m_creature->DisappearAndDie();
    }
};

CreatureAI* GetAI_npc_released_offspring_harkoa(Creature* pCreature)
{
    return new npc_released_offspring_harkoaAI(pCreature);
}

void AddSC_zuldrak()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_drakuru_shackles";
    newscript->GetAI = &GetAI_npc_drakuru_shackles;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_captured_rageclaw";
    newscript->GetAI = &GetAI_npc_captured_rageclaw;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_gymer";
    newscript->pGossipHello = &GossipHello_npc_gymer;
    newscript->pGossipSelect = &GossipSelect_npc_gymer;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_gurgthock";
    newscript->GetAI = &GetAI_npc_gurgthock;
    newscript->pQuestAccept = &QuestAccept_npc_gurgthock;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_orinoko_tuskbreaker";
    newscript->GetAI = &GetAI_npc_orinoko_tuskbreaker;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_korrak_bloodrager";
    newscript->GetAI = &GetAI_npc_korrak_bloodrager;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_yggdras";
    newscript->GetAI = &GetAI_npc_yggdras;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_stinkbeard";
    newscript->GetAI = &GetAI_npc_stinkbeard;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_released_offspring_harkoa";
    newscript->GetAI = &GetAI_npc_released_offspring_harkoa;
    newscript->RegisterSelf();
}
