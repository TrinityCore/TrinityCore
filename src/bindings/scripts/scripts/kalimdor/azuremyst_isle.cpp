 /* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Azuremyst_Isle
SD%Complete: 75
SDComment: Quest support: 9283, 9537, 9582, 9554, 9531, 9303(special flight path, proper model for mount missing). Injured Draenei cosmetic only
SDCategory: Azuremyst Isle
EndScriptData */
/* ContentData
npc_draenei_survivor
npc_engineer_spark_overgrind
npc_injured_draenei
npc_magwin
npc_geezle
mob_nestlewood_owlkin
EndContentData */
#include "precompiled.h"
#include "escort_ai.h"
#include <cmath>
/*######
## npc_draenei_survivor
######*/
enum eEnums
{
    SAY_HEAL1           = -1000248,
    SAY_HEAL2           = -1000249,
    SAY_HEAL3           = -1000250,
    SAY_HEAL4           = -1000251,
    SAY_HELP1           = -1000252,
    SAY_HELP2           = -1000253,
    SAY_HELP3           = -1000254,
    SAY_HELP4           = -1000255,
    SPELL_IRRIDATION    = 35046,
    SPELL_STUNNED       = 28630
};
struct TRINITY_DLL_DECL npc_draenei_survivorAI : public ScriptedAI
{
    npc_draenei_survivorAI(Creature *c) : ScriptedAI(c) {}
    uint64 pCaster;
    uint32 SayThanksTimer;
    uint32 RunAwayTimer;
    uint32 SayHelpTimer;
    bool CanSayHelp;
    void Reset()
    {
        pCaster = 0;
        SayThanksTimer = 0;
        RunAwayTimer = 0;
        SayHelpTimer = 10000;
        CanSayHelp = true;
        m_creature->CastSpell(m_creature, SPELL_IRRIDATION, true);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
        m_creature->SetHealth(int(m_creature->GetMaxHealth()*.1));
        m_creature->SetStandState(UNIT_STAND_STATE_SLEEP);
    }
    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who)
    {
        if (CanSayHelp && who->GetTypeId() == TYPEID_PLAYER && m_creature->IsFriendlyTo(who) && m_creature->IsWithinDistInMap(who, 25.0f))
        {
            //Random switch between 4 texts
            DoScriptText(RAND(SAY_HELP1, SAY_HELP2, SAY_HELP3, SAY_HELP4), m_creature, who);
            SayHelpTimer = 20000;
            CanSayHelp = false;
        }
    }
    void SpellHit(Unit *Caster, const SpellEntry *Spell)
    {
        if (Spell->SpellFamilyFlags[2] & 0x080000000)
        {
            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
            m_creature->SetStandState(UNIT_STAND_STATE_STAND);
            m_creature->CastSpell(m_creature, SPELL_STUNNED, true);
            pCaster = Caster->GetGUID();
            SayThanksTimer = 5000;
        }
    }
    void UpdateAI(const uint32 diff)
    {
        if (SayThanksTimer)
        {
            if (SayThanksTimer <= diff)
            {
                m_creature->RemoveAurasDueToSpell(SPELL_IRRIDATION);
                if (Player* pPlayer = Unit::GetPlayer(pCaster))
                {
                    DoScriptText(RAND(SAY_HEAL1, SAY_HEAL2, SAY_HEAL3, SAY_HEAL4), m_creature, pPlayer);
                    pPlayer->TalkedToCreature(m_creature->GetEntry(),m_creature->GetGUID());
                }
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MovePoint(0, -4115.053711f, -13754.831055f, 73.508949f);
                RunAwayTimer = 10000;
                SayThanksTimer = 0;
            }else SayThanksTimer -= diff;
            return;
        }
        if (RunAwayTimer)
        {
            if (RunAwayTimer <= diff)
                m_creature->ForcedDespawn();
            else
                RunAwayTimer -= diff;
            return;
        }
        if (SayHelpTimer < diff)
        {
            CanSayHelp = true;
            SayHelpTimer = 20000;
        }else SayHelpTimer -= diff;
    }
};
CreatureAI* GetAI_npc_draenei_survivor(Creature* pCreature)
{
    return new npc_draenei_survivorAI (pCreature);
}
/*######
## npc_engineer_spark_overgrind
######*/
enum eOvergrind
{
    SAY_TEXT        = -1000256,
    SAY_EMOTE       = -1000257,
    ATTACK_YELL     = -1000258,
    AREA_COVE       = 3579,
    AREA_ISLE       = 3639,
    QUEST_GNOMERCY  = 9537,
    FACTION_HOSTILE = 14,
    SPELL_DYNAMITE  = 7978
};
#define GOSSIP_FIGHT "Traitor! You will be brought to justice!"
struct TRINITY_DLL_DECL npc_engineer_spark_overgrindAI : public ScriptedAI
{
    npc_engineer_spark_overgrindAI(Creature *c) : ScriptedAI(c)
    {
        NormFaction = c->getFaction();
        NpcFlags = c->GetUInt32Value(UNIT_NPC_FLAGS);
        if (c->GetAreaId() == AREA_COVE || c->GetAreaId() == AREA_ISLE)
            IsTreeEvent = true;
    }
    uint32 NormFaction;
    uint32 NpcFlags;
    uint32 Dynamite_Timer;
    uint32 Emote_Timer;
    bool IsTreeEvent;
    void Reset()
    {
        Dynamite_Timer = 8000;
        Emote_Timer = 120000 + rand()%30000;
        m_creature->setFaction(NormFaction);
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, NpcFlags);
        IsTreeEvent = false;
    }
    void EnterCombat(Unit* who)
    {
        DoScriptText(ATTACK_YELL, m_creature, who);
    }
    void UpdateAI(const uint32 diff)
    {
        if (!m_creature->isInCombat() && !IsTreeEvent)
        {
            if (Emote_Timer < diff)
            {
                DoScriptText(SAY_TEXT, m_creature);
                DoScriptText(SAY_EMOTE, m_creature);
                Emote_Timer = 120000 + rand()%30000;
            }else Emote_Timer -= diff;
        }
        else if (IsTreeEvent)
            return;
        if (!UpdateVictim())
            return;
        if (Dynamite_Timer < diff)
        {
            DoCast(m_creature->getVictim(), SPELL_DYNAMITE);
            Dynamite_Timer = 8000;
        } else Dynamite_Timer -= diff;
        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_engineer_spark_overgrind(Creature* pCreature)
{
    return new npc_engineer_spark_overgrindAI (pCreature);
}
bool GossipHello_npc_engineer_spark_overgrind(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_GNOMERCY) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_FIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());
    return true;
}
bool GossipSelect_npc_engineer_spark_overgrind(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->setFaction(FACTION_HOSTILE);
        CAST_AI(npc_engineer_spark_overgrindAI, pCreature->AI())->AttackStart(pPlayer);
    }
    return true;
}
/*######
## npc_injured_draenei
######*/
struct TRINITY_DLL_DECL npc_injured_draeneiAI : public ScriptedAI
{
    npc_injured_draeneiAI(Creature *c) : ScriptedAI(c) {}
    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IN_COMBAT);
        m_creature->SetHealth(int(m_creature->GetMaxHealth()*.15));
        switch (rand()%2)
        {
            case 0: m_creature->SetStandState(UNIT_STAND_STATE_SIT); break;
            case 1: m_creature->SetStandState(UNIT_STAND_STATE_SLEEP); break;
        }
    }
    void EnterCombat(Unit *who) {}
    void MoveInLineOfSight(Unit *who)
    {
        return;                                             //ignore everyone around them (won't aggro anything)
    }
    void UpdateAI(const uint32 diff)
    {
        return;
    }
};
CreatureAI* GetAI_npc_injured_draenei(Creature* pCreature)
{
    return new npc_injured_draeneiAI (pCreature);
}
/*######
## npc_magwin
######*/
enum eMagwin
{
    SAY_START                   = -1000111,
    SAY_AGGRO                   = -1000112,
    SAY_PROGRESS                = -1000113,
    SAY_END1                    = -1000114,
    SAY_END2                    = -1000115,
    EMOTE_HUG                   = -1000116,
    QUEST_A_CRY_FOR_SAY_HELP    = 9528
};
struct TRINITY_DLL_DECL npc_magwinAI : public npc_escortAI
{
    npc_magwinAI(Creature *c) : npc_escortAI(c) {}

    void WaypointReached(uint32 i)
    {
        Player* pPlayer = GetPlayerForEscort();
        if (!pPlayer)
            return;
        switch(i)
        {
        case 0:
            DoScriptText(SAY_START, m_creature, pPlayer);
            break;
        case 17:
            DoScriptText(SAY_PROGRESS, m_creature, pPlayer);
            break;
        case 28:
            DoScriptText(SAY_END1, m_creature, pPlayer);
            break;
        case 29:
            DoScriptText(EMOTE_HUG, m_creature, pPlayer);
            DoScriptText(SAY_END2, m_creature, pPlayer);
            pPlayer->GroupEventHappens(QUEST_A_CRY_FOR_SAY_HELP,m_creature);
            break;
        }
    }
    void EnterCombat(Unit* who)
    {
        DoScriptText(SAY_AGGRO, m_creature, who);
    }
    void Reset() { }
};
bool QuestAccept_npc_magwin(Player* pPlayer, Creature* pCreature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_A_CRY_FOR_SAY_HELP)
    {
        pCreature->setFaction(113);
        if (npc_escortAI* pEscortAI = CAST_AI(npc_escortAI, pCreature->AI()))
            pEscortAI->Start(true, false, pPlayer->GetGUID());
    }
    return true;
}
CreatureAI* GetAI_npc_magwinAI(Creature* pCreature)
{
    return new npc_magwinAI(pCreature);
}
/*######
## npc_geezle
######*/
enum eGeezle
{
    QUEST_TREES_COMPANY = 9531,
    SPELL_TREE_DISGUISE = 30298,
    GEEZLE_SAY_1    = -1000259,
    SPARK_SAY_2     = -1000260,
    SPARK_SAY_3     = -1000261,
    GEEZLE_SAY_4    = -1000262,
    SPARK_SAY_5     = -1000263,
    SPARK_SAY_6     = -1000264,
    GEEZLE_SAY_7    = -1000265,
    EMOTE_SPARK     = -1000266,
    MOB_SPARK       = 17243,
    GO_NAGA_FLAG    = 181694
};
static float SparkPos[3] = {-5029.91, -11291.79, 8.096};
struct TRINITY_DLL_DECL npc_geezleAI : public ScriptedAI
{
    npc_geezleAI(Creature *c) : ScriptedAI(c) {}
    uint64 SparkGUID;
    uint32 Step;
    uint32 SayTimer;
    bool EventStarted;
    void Reset()
    {
        SparkGUID = 0;
        Step = 0;
        StartEvent();
    }
    void EnterCombat(Unit* who){}
    void StartEvent()
    {
        Step = 0;
        EventStarted = true;
        Creature* Spark = m_creature->SummonCreature(MOB_SPARK, SparkPos[0], SparkPos[1], SparkPos[2], 0, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 1000);
        if (Spark)
        {
            SparkGUID = Spark->GetGUID();
            Spark->setActive(true);
            Spark->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        }
        SayTimer = 8000;
    }
    uint32 NextStep(uint32 Step)
    {
        Creature* Spark = Unit::GetCreature(*m_creature, SparkGUID);
        switch(Step)
        {
        case 0:
            if (Spark)
                Spark->GetMotionMaster()->MovePoint(0, -5080.70, -11253.61, 0.56);
            m_creature->GetMotionMaster()->MovePoint(0, -5092.26, -11252, 0.71);
            return 9000; // NPCs are walking up to fire
        case 1:
            DespawnNagaFlag(true);
            DoScriptText(EMOTE_SPARK, Spark);
            return 1000;
        case 2:
            DoScriptText(GEEZLE_SAY_1, m_creature, Spark);
            if (Spark)
            {
                Spark->SetInFront(m_creature);
                m_creature->SetInFront(Spark);
            }
            return 5000;
        case 3: DoScriptText(SPARK_SAY_2, Spark); return 7000;
        case 4: DoScriptText(SPARK_SAY_3, Spark); return 8000;
        case 5: DoScriptText(GEEZLE_SAY_4, m_creature, Spark); return 8000;
        case 6: DoScriptText(SPARK_SAY_5, Spark); return 9000;
        case 7: DoScriptText(SPARK_SAY_6, Spark); return 8000;
        case 8: DoScriptText(GEEZLE_SAY_7, m_creature, Spark); return 2000;
        case 9:
            m_creature->GetMotionMaster()->MoveTargetedHome();
            if (Spark)
                Spark->GetMotionMaster()->MovePoint(0, SparkPos[0], SparkPos[1], SparkPos[2]);
            CompleteQuest();
            return 9000;
        case 10:
            if (Spark)
                Spark->DisappearAndDie();
            DespawnNagaFlag(false);
            m_creature->DisappearAndDie();
        default: return 99999999;
        }
    }
    // will complete Tree's company quest for all nearby players that are disguised as trees
    void CompleteQuest()
    {
        float radius = 50.0f;
        std::list<Player*> players;
        Trinity::AnyPlayerInObjectRangeCheck checker(m_creature, radius);
        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(m_creature, players, checker);
        m_creature->VisitNearbyWorldObject(radius, searcher);
        for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
        {
            if((*itr)->GetQuestStatus(QUEST_TREES_COMPANY)==QUEST_STATUS_INCOMPLETE
                &&(*itr)->HasAuraEffect(SPELL_TREE_DISGUISE,3) )
            {
                (*itr)->KilledMonsterCredit(MOB_SPARK,0);
            }
        }
    }
    void DespawnNagaFlag(bool despawn)
    {
        std::list<GameObject*> FlagList;
        m_creature->GetGameObjectListWithEntryInGrid(FlagList,GO_NAGA_FLAG, 100.0f);
        if (!FlagList.empty())
        {
            for (std::list<GameObject*>::iterator itr = FlagList.begin(); itr != FlagList.end(); ++itr)
            {
                if (despawn)
                {
                    (*itr)->SetLootState(GO_JUST_DEACTIVATED);
                }
                else
                    (*itr)->Respawn();
            }
        } else error_log("SD2 ERROR: FlagList is empty!");
    }
    void UpdateAI(const uint32 diff)
    {
        if (SayTimer < diff)
        {
            if (EventStarted)
            {
                SayTimer = NextStep(Step++);
            }
        }else SayTimer -= diff;
    }
};
CreatureAI* GetAI_npc_geezleAI(Creature* pCreature)
{
    return new npc_geezleAI(pCreature);
}
/*######
## mob_nestlewood_owlkin
######*/
enum eOwlkin
{
    SPELL_INOCULATE_OWLKIN  = 29528,
    ENTRY_OWLKIN            = 16518,
    ENTRY_OWLKIN_INOC       = 16534
};
struct TRINITY_DLL_DECL npc_nestlewood_owlkinAI : public ScriptedAI
{
    npc_nestlewood_owlkinAI(Creature *c) : ScriptedAI(c) {}
    uint32 DespawnTimer;
    void Reset()
    {
        DespawnTimer = 0;
    }
    void UpdateAI(const uint32 diff)
    {
        //timer gets adjusted by the triggered aura effect
        if (DespawnTimer)
        {
            if (DespawnTimer <= diff)
            {
                //once we are able to, despawn us
                m_creature->ForcedDespawn();
                return;
            }else DespawnTimer -= diff;
        }
        if (!UpdateVictim())
            return;
        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_nestlewood_owlkinAI(Creature* pCreature)
{
    return new npc_nestlewood_owlkinAI (pCreature);
}
bool EffectDummyCreature_npc_nestlewood_owlkin(Unit *pCaster, uint32 spellId, uint32 effIndex, Creature *pCreatureTarget)
{
    //always check spellid and effectindex
    if (spellId == SPELL_INOCULATE_OWLKIN && effIndex == 0)
    {
        if (pCreatureTarget->GetEntry() != ENTRY_OWLKIN)
            return true;
        pCreatureTarget->UpdateEntry(ENTRY_OWLKIN_INOC);
        //set despawn timer, since we want to remove Creature after a short time
        CAST_AI(npc_nestlewood_owlkinAI, pCreatureTarget->AI())->DespawnTimer = 15000;
        //always return true when we are handling this spell and effect
        return true;
    }
    return false;
}
void AddSC_azuremyst_isle()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "npc_draenei_survivor";
    newscript->GetAI = &GetAI_npc_draenei_survivor;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "npc_engineer_spark_overgrind";
    newscript->GetAI = &GetAI_npc_engineer_spark_overgrind;
    newscript->pGossipHello =  &GossipHello_npc_engineer_spark_overgrind;
    newscript->pGossipSelect = &GossipSelect_npc_engineer_spark_overgrind;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "npc_injured_draenei";
    newscript->GetAI = &GetAI_npc_injured_draenei;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "npc_magwin";
    newscript->GetAI = &GetAI_npc_magwinAI;
    newscript->pQuestAccept = &QuestAccept_npc_magwin;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "npc_geezle";
    newscript->GetAI = &GetAI_npc_geezleAI;
    newscript->RegisterSelf();
    newscript = new Script;
    newscript->Name = "npc_nestlewood_owlkin";
    newscript->GetAI = &GetAI_npc_nestlewood_owlkinAI;
    newscript->pEffectDummyCreature = &EffectDummyCreature_npc_nestlewood_owlkin;
    newscript->RegisterSelf();
}

