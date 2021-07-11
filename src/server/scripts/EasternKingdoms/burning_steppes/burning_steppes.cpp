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
SDName: Burning_Steppes
SD%Complete: 100
SDCategory: Burning Steppes
EndScriptData */

#include "scriptPCH.h"

//IMPORT SD2
/*######
## npc_grark_lorkrub
######*/

enum
{
    SAY_START                   = -1000873,
    SAY_PAY                     = -1000874,
    SAY_FIRST_AMBUSH_START      = -1000875,
    SAY_FIRST_AMBUSH_END        = -1000876,
    SAY_SEC_AMBUSH_START        = -1000877,
    SAY_SEC_AMBUSH_END          = -1000878,
    SAY_THIRD_AMBUSH_START      = -1000879,
    SAY_THIRD_AMBUSH_END        = -1000880,
    EMOTE_LAUGH                 = -1000881,
    SAY_LAST_STAND              = -1000882,
    SAY_LEXLORT_1               = -1000883,
    SAY_LEXLORT_2               = -1000884,
    EMOTE_RAISE_AXE             = -1000885,
    EMOTE_LOWER_HAND            = -1000886,
    SAY_LEXLORT_3               = -1000887,
    SAY_LEXLORT_4               = -1000888,

    EMOTE_SUBMIT                = -1000889,
    SAY_AGGRO                   = -1000890,

    SPELL_CAPTURE_GRARK             = 14250,

    NPC_BLACKROCK_AMBUSHER          = 9522,
    NPC_BLACKROCK_RAIDER            = 9605,
    NPC_FLAMESCALE_DRAGONSPAWN      = 7042,
    NPC_SEARSCALE_DRAKE             = 7046,

    NPC_GRARK_LORKRUB               = 9520,
    NPC_HIGH_EXECUTIONER_NUZARK     = 9538,
    NPC_SHADOW_OF_LEXLORT           = 9539,

    FACTION_FRIENDLY                = 35,

    QUEST_ID_PRECARIOUS_PREDICAMENT = 4121
};
struct DialogueEntry
{
    int32 action;
    int32 who;
    uint64 timer;
};

static const DialogueEntry aOutroDialogue[] =
{
    {SAY_LAST_STAND,    NPC_GRARK_LORKRUB,              5000},
    {SAY_LEXLORT_1,     NPC_SHADOW_OF_LEXLORT,          3000},
    {SAY_LEXLORT_2,     NPC_SHADOW_OF_LEXLORT,          5000},
    {EMOTE_RAISE_AXE,   NPC_HIGH_EXECUTIONER_NUZARK,    4000},
    {EMOTE_LOWER_HAND,  NPC_SHADOW_OF_LEXLORT,          3000},
    {SAY_LEXLORT_3,     NPC_SHADOW_OF_LEXLORT,          3000},
    {NPC_GRARK_LORKRUB, 0,                              5000},
    {SAY_LEXLORT_4,     NPC_SHADOW_OF_LEXLORT,          0},
    {0, 0, 0},
};

struct npc_grark_lorkrubAI : public npc_escortAI/*, private DialogueHelper*/
{
    npc_grark_lorkrubAI(Creature* pCreature) : npc_escortAI(pCreature)/*,
        DialogueHelper(aOutroDialogue)*/
    {
        Reset();
    }

    ObjectGuid m_nuzarkGuid;
    ObjectGuid m_lexlortGuid;

    GuidList m_lSearscaleGuidList;

    uint32 m_uiSomethingWentWrongTimer;
    uint8 m_uiKilledCreatures;
    bool m_bIsFirstSearScale;

    void Reset() override
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiSomethingWentWrongTimer =400000;//~6minutes
            m_uiKilledCreatures = 0;
            m_bIsFirstSearScale = true;
            dialogueStep = -1;

            m_lSearscaleGuidList.clear();

            m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        }
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!HasEscortState(STATE_ESCORT_ESCORTING))
            DoScriptText(SAY_AGGRO, m_creature);
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // No combat during escort
        if (HasEscortState(STATE_ESCORT_ESCORTING))
            return;

        npc_escortAI::MoveInLineOfSight(pWho);
    }

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 1:
                DoScriptText(SAY_START, m_creature);
                //SetRun(true);//ALITA temporaire
                break;
            case 7:
                DoScriptText(SAY_PAY, m_creature);
                break;
            case 12:
                DoScriptText(SAY_FIRST_AMBUSH_START, m_creature);
                SetEscortPaused(true);

                m_creature->SummonCreature(NPC_BLACKROCK_AMBUSHER, -7844.3f, -1521.6f, 139.2f, 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_BLACKROCK_AMBUSHER, -7860.4f, -1507.8f, 141.0f, 6.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_BLACKROCK_RAIDER,   -7845.6f, -1508.1f, 138.8f, 6.1f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_BLACKROCK_RAIDER,   -7859.8f, -1521.8f, 139.2f, 6.2f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                break;
            case 24:
                DoScriptText(SAY_SEC_AMBUSH_START, m_creature);
                SetEscortPaused(true);

                m_creature->SummonCreature(NPC_BLACKROCK_AMBUSHER,     -8035.3f, -1222.2f, 135.5f, 5.1f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_FLAMESCALE_DRAGONSPAWN, -8037.5f, -1216.9f, 135.8f, 5.1f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_BLACKROCK_AMBUSHER,     -8009.5f, -1222.1f, 139.2f, 3.9f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_FLAMESCALE_DRAGONSPAWN, -8007.1f, -1219.4f, 140.1f, 3.9f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                break;
            case 28:
                m_creature->SummonCreature(NPC_SEARSCALE_DRAKE, -7900.1f, -1133.14f, 193.98f, 3.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_SEARSCALE_DRAKE, -7898.8f, -1125.1f, 193.9f, 3.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                m_creature->SummonCreature(NPC_SEARSCALE_DRAKE, -7895.6f, -1119.5f, 194.5f, 3.1f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 200000);
                break;
            case 30:
            {
                if (m_uiKilledCreatures < 11)
                    SetEscortPaused(true);
                DoScriptText(SAY_THIRD_AMBUSH_START, m_creature);

                Player* pPlayer = GetPlayerForEscort();
                if (!pPlayer)
                    return;
                //break;ok so... it turns out I kill them BEFORE  we get to the paused ^.^

                // Set all the dragons in combat
                for (const auto& guid : m_lSearscaleGuidList)
                {
                    if (Creature* pTemp = m_creature->GetMap()->GetCreature(guid))
                        pTemp->AI()->AttackStart(pPlayer);
                }
                break;
            }
            case 36:
                DoScriptText(EMOTE_LAUGH, m_creature);
                break;
            case 45:
                StartNextDialogueText(SAY_LAST_STAND);
                SetEscortPaused(true);

                m_creature->SummonCreature(NPC_HIGH_EXECUTIONER_NUZARK, -7532.3f, -1029.4f, 258.0f, 2.7f, TEMPSUMMON_TIMED_DESPAWN, 40000);
                m_creature->SummonCreature(NPC_SHADOW_OF_LEXLORT,       -7532.8f, -1032.9f, 258.2f, 2.5f, TEMPSUMMON_TIMED_DESPAWN, 40000);
                break;
        }
    }
    uint32 dialogueTimer;
    int32 dialogueStep;
    void StartNextDialogueText(int32 firstAction)
    {
        for (int i = 0; i < 9; i++) //aOutroDialogue.length .size
        {
            if (aOutroDialogue[i].action == firstAction)
            {
                dialogueStep = i;
                dialogueTimer = 0;
                //sLog.nostalrius("size of aOutroDialogue: 9, i=%i, firstAction=%i",i,firstAction);
                break;
            }
        }
    }

    void DialogueUpdate(uint32 uiDiff)
    {
        if (dialogueStep < 0)
            return;
        if (dialogueTimer < uiDiff)
        {
            if (aOutroDialogue[dialogueStep].action != 0)
            {
                if (aOutroDialogue[dialogueStep].who != 0)
                {
                    if (Creature* speaker = GetSpeakerByEntry(aOutroDialogue[dialogueStep].who))
                        DoScriptText(aOutroDialogue[dialogueStep].action, speaker);
                }
                JustDidDialogueStep(aOutroDialogue[dialogueStep].action);
                dialogueStep++;
                dialogueTimer = aOutroDialogue[dialogueStep].timer;
            }
            else
                dialogueStep = -1;
        }
        else
            dialogueTimer -= uiDiff;
    }

    void JustDidDialogueStep(int32 iEntry)
    {
        switch (iEntry)
        {
            case SAY_LEXLORT_1:
                m_creature->SetStandState(UNIT_STAND_STATE_KNEEL);
                break;
            case SAY_LEXLORT_3:
                // Note: this part isn't very clear. Should he just simply attack him, or charge him?
                if (Creature* pNuzark = m_creature->GetMap()->GetCreature(m_nuzarkGuid))
                    pNuzark->HandleEmote(EMOTE_ONESHOT_ATTACK2HTIGHT);
                break;
            case NPC_GRARK_LORKRUB:
                // Fake death creature when the axe is lowered. This will allow us to finish the event
                m_creature->InterruptNonMeleeSpells(true);
                m_creature->SetHealth(1);
                m_creature->StopMoving();
                m_creature->ClearComboPointHolders();
                m_creature->RemoveAllAurasOnDeath();
                //m_creature->ModifyAuraState(AURA_STATE_HEALTHLESS_20_PERCENT, false);
                //m_creature->ModifyAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, false);
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_creature->ClearAllReactives();
                m_creature->GetMotionMaster()->Clear();
                m_creature->GetMotionMaster()->MoveIdle();
                m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
                break;
            case SAY_LEXLORT_4:
                // Finish the quest
                if (Player* pPlayer = GetPlayerForEscort())
                    pPlayer->GroupEventHappens(QUEST_ID_PRECARIOUS_PREDICAMENT, m_creature);
                // Kill self
                m_creature->DealDamage(m_creature, m_creature->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NONE, nullptr, false);
                break;
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        switch (pSummoned->GetEntry())
        {
            case NPC_HIGH_EXECUTIONER_NUZARK:
                m_nuzarkGuid  = pSummoned->GetObjectGuid();
                break;
            case NPC_SHADOW_OF_LEXLORT:
                m_lexlortGuid = pSummoned->GetObjectGuid();
                break;
            case NPC_SEARSCALE_DRAKE:
                // If it's the flying drake allow him to move in circles
                if (m_bIsFirstSearScale)
                {
                    m_bIsFirstSearScale = false;

                    //pSummoned->SetLevitate(true); //maybe grounding it????
                    // ToDo: this guy should fly in circles above the creature
                    //pSummoned->SetDefaultMovementType(IDLE_MOTION_TYPE); //Probably should be enough, OR NOT
                    //pSummoned->GetMotionMaster()->MoveIdle();
                    //pSummoned->GetMotionMaster()->MoveRandom();
                    //if(pSummoned->CanFly())
                    //sLog.nostalrius("creature can fly");
                }
                m_lSearscaleGuidList.push_back(pSummoned->GetObjectGuid());
                break;

            default:
                // The hostile mobs should attack the player only
                if (Player* pPlayer = GetPlayerForEscort())
                    pSummoned->AI()->AttackStart(pPlayer);
                break;
        }
    }

    void SummonedCreatureJustDied(Creature* /*pSummoned*/) override
    {
        ++m_uiKilledCreatures;
        //sLog.nostalrius("m_uiKilledCreatures = %u", m_uiKilledCreatures);
        switch (m_uiKilledCreatures)
        {
            case 4:
                DoScriptText(SAY_FIRST_AMBUSH_END, m_creature);
                m_uiSomethingWentWrongTimer =400000;
                SetEscortPaused(false);
                break;
            case 8:
                DoScriptText(SAY_SEC_AMBUSH_END, m_creature);
                m_uiSomethingWentWrongTimer =400000;
                SetEscortPaused(false);
                break;
            case 11:
                DoScriptText(SAY_THIRD_AMBUSH_END, m_creature);
                m_uiSomethingWentWrongTimer =400000;
                SetEscortPaused(false);
                break;
        }
    }

    Creature* GetSpeakerByEntry(uint32 uiEntry)
    {
        switch (uiEntry)
        {
            case NPC_GRARK_LORKRUB:
                return m_creature;
            case NPC_HIGH_EXECUTIONER_NUZARK:
                return m_creature->GetMap()->GetCreature(m_nuzarkGuid);
            case NPC_SHADOW_OF_LEXLORT:
                return m_creature->GetMap()->GetCreature(m_lexlortGuid);

            default:
                return nullptr;
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        DialogueUpdate(uiDiff);
        if (HasEscortState(STATE_ESCORT_PAUSED) && HasEscortState(STATE_ESCORT_ESCORTING))
        {
            if(m_uiSomethingWentWrongTimer < uiDiff)//basically if players avoid killing adds, he will stay stuck.
            {
                m_creature->DisappearAndDie();
            }
            else
                m_uiSomethingWentWrongTimer -=  uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_grark_lorkrub(Creature* pCreature)
{
    return new npc_grark_lorkrubAI(pCreature);
}

bool QuestAccept_npc_grark_lorkrub(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_ID_PRECARIOUS_PREDICAMENT)
    {
        if (npc_grark_lorkrubAI* pEscortAI = dynamic_cast<npc_grark_lorkrubAI*>(pCreature->AI()))
            pEscortAI->Start(false, pPlayer->GetGUID(), pQuest);

        return true;
    }

    return false;
}

bool EffectDummyCreature_spell_capture_grark(WorldObject* /*pCaster*/, uint32 uiSpellId, SpellEffectIndex uiEffIndex, Creature* pCreatureTarget/*, ObjectGuid*/ /*originalCasterGuid*/)
{
    // always check spellid and effectindex
    if (uiSpellId == SPELL_CAPTURE_GRARK && uiEffIndex == EFFECT_INDEX_0)
    {
        // Note: this implementation needs additional research! There is a lot of guesswork involved in this!
        if (pCreatureTarget->GetHealthPercent() > 25.0f)
            return true;//false <= NOT : cf always return true :p

        // The faction is guesswork - needs more research
        DoScriptText(EMOTE_SUBMIT, pCreatureTarget);
        pCreatureTarget->SetFactionTemporary(85, TEMPFACTION_RESTORE_RESPAWN); /*FACTION_FRIENDLY*/
        pCreatureTarget->AI()->EnterEvadeMode();

        // always return true when we are handling this spell and effect
        return true;
    }

    return false;
}

enum
{
    SPELL_FOOLS_PLIGHT              = 23504,    
    
    SPELL_DEMONIC_FRENZY            = 23257,
    SPELL_ENTROPIC_STING            = 23260,

    EMOTE_FRENZY                    = 7797,

    NPC_NELSON_THE_NICE             = 14529,
    NPC_KLINFRAN_THE_CRAZED         = 14534,
    NPC_THE_CLEANER                 = 14503,
    
    QUEST_STAVE_OF_THE_ANCIENTS     = 7636
};

#define GOSSIP_ITEM                 "Show me your real face, demon."

/*######
## npc_franklin_the_friendly
######*/

/*######
## npc_klinfran_the_crazed
######*/

struct npc_klinfranAI : public ScriptedAI
{
    npc_klinfranAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_bTransform      = false;
        m_uiDespawn_Timer = 0;
        Reset();
    }

    uint32 m_uiTransform_Timer;
    uint32 m_uiTransformEmote_Timer;
    bool m_bTransform;

    ObjectGuid m_hunterGuid;
    uint32 m_uiDemonic_Frenzy_Timer;
    uint32 m_uiDespawn_Timer;

    void Reset()  override
    {
        switch (m_creature->GetEntry())
        {
            case NPC_NELSON_THE_NICE:
                m_creature->SetRespawnDelay(35*MINUTE);
                m_creature->SetRespawnTime(35*MINUTE);
                m_creature->SetHomePosition(-8318.19f, -993.662f, 176.956f, 5.65024f);
                m_creature->NearTeleportTo(-8318.19f, -993.662f, 176.956f, 5.65024f);
                if (m_creature->GetMotionMaster()->GetCurrentMovementGeneratorType() != WAYPOINT_MOTION_TYPE)
                {
                    m_creature->SetDefaultMovementType(WAYPOINT_MOTION_TYPE);
                    m_creature->GetMotionMaster()->Initialize();
                }
                
                m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                m_uiTransform_Timer      = 10000;
                m_uiTransformEmote_Timer = 5000;
                m_bTransform             = false;
                m_uiDespawn_Timer        = 0;
                break;
            case NPC_KLINFRAN_THE_CRAZED:
                if (!m_uiDespawn_Timer)
                    m_uiDespawn_Timer = 20*MINUTE*IN_MILLISECONDS;

                m_hunterGuid.Clear();
                m_uiDemonic_Frenzy_Timer = 5000;
                break;
        }
    }

    /** Franklin the Friendly */
    void Transform()
    {
        m_creature->UpdateEntry(NPC_KLINFRAN_THE_CRAZED);
        m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetOrientation());
        m_creature->SetDefaultMovementType(IDLE_MOTION_TYPE);
        m_creature->GetMotionMaster()->Initialize();
        Reset();
    }

    void BeginEvent(ObjectGuid playerGuid)
    {
        m_hunterGuid = playerGuid;
        m_creature->GetMotionMaster()->Clear(false);
        m_creature->GetMotionMaster()->MoveIdle();
        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
        m_bTransform = true;      
    }

    /** Klinfran the Crazed */
    void Aggro(Unit* pWho) override
    {
        if (pWho->GetClass() == CLASS_HUNTER && (m_hunterGuid.IsEmpty() || m_hunterGuid == pWho->GetObjectGuid())/*&& pWho->GetQuestStatus(QUEST_STAVE_OF_THE_ANCIENTS) == QUEST_STATUS_INCOMPLETE*/)
        {
            m_hunterGuid = pWho->GetObjectGuid();
        }
        else
            DemonDespawn();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        m_creature->SetHomePosition(-8318.19f, -993.662f, 176.956f, 5.65024f);

        // DRSS
        uint32 m_respawn_delay_Timer = 3*HOUR;
        if (sWorld.GetActiveSessionCount() > BLIZZLIKE_REALM_POPULATION)
            m_respawn_delay_Timer *= float(BLIZZLIKE_REALM_POPULATION) / float(sWorld.GetActiveSessionCount());

        m_creature->SetRespawnDelay(m_respawn_delay_Timer);
        m_creature->SetRespawnTime(m_respawn_delay_Timer);
        m_creature->SaveRespawnTime();
    }
    
    void DemonDespawn(bool triggered = true)
    {
        m_creature->SetHomePosition(-8318.19f, -993.662f, 176.956f, 5.65024f);
        m_creature->SetRespawnDelay(15*MINUTE);
        m_creature->SetRespawnTime(15*MINUTE);
        m_creature->SaveRespawnTime();
    
        if (triggered)
        {
            Creature* pCleaner = m_creature->SummonCreature(NPC_THE_CLEANER, m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), m_creature->GetAngle(m_creature), TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 20*MINUTE*IN_MILLISECONDS);
            if (pCleaner)
            {
                ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
                
                for (const auto itr : tList)
                {
                    if (Unit* pUnit = m_creature->GetMap()->GetUnit(itr->getUnitGuid()))
                    {
                        if (pUnit->IsAlive())
                        {
                            pCleaner->SetInCombatWith(pUnit);
                            pCleaner->AddThreat(pUnit);
                            pCleaner->AI()->AttackStart(pUnit);
                        }
                    }
                }
            }
        }
        
        m_creature->ForcedDespawn();
    }
    
    void SpellHit(Unit* /*pCaster*/, SpellEntry const* pSpell) override
    {
        if (pSpell && pSpell->Id == 14277)   // Scorpid Sting (Rank 4)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_DEMONIC_FRENZY);
            DoCastSpellIfCan(m_creature, SPELL_ENTROPIC_STING, CF_TRIGGERED);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        /** Franklin the Friendly */
        if (m_bTransform)
        {
            if (m_uiTransformEmote_Timer)
            {
                if (m_uiTransformEmote_Timer <= uiDiff)
                {
                    m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                    m_uiTransformEmote_Timer = 0;
                }
                else
                    m_uiTransformEmote_Timer -= uiDiff;
            }

            if (m_uiTransform_Timer < uiDiff)
            {
                m_bTransform = false;
                Transform();
            }
            else
                m_uiTransform_Timer -= uiDiff;
        }

        /** Klinfran the Crazed */
        if (m_uiDespawn_Timer)
        {
            if (m_uiDespawn_Timer <= uiDiff)
            {
                if (m_creature->IsAlive() && !m_creature->IsInCombat())
                    DemonDespawn(false);
            }
            else
                m_uiDespawn_Timer -= uiDiff;
        }
            
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_creature->GetThreatManager().getThreatList().size() > 1 /*|| pHunter->IsDead()*/)
            DemonDespawn();

        if (m_uiDemonic_Frenzy_Timer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_DEMONIC_FRENZY) == CAST_OK)
            {
                DoScriptText(EMOTE_FRENZY, m_creature);
                m_uiDemonic_Frenzy_Timer = 15000;
            }
        }
        else
            m_uiDemonic_Frenzy_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_npc_klinfran(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_STAVE_OF_THE_ANCIENTS) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(0, GOSSIP_ITEM , GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);
    
    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
    return true;
}

bool GossipSelect_npc_klinfran(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction )
{
    pPlayer->CLOSE_GOSSIP_MENU();
    ((npc_klinfranAI*)pCreature->AI())->BeginEvent(pPlayer->GetObjectGuid());    
    return true;
}

CreatureAI* GetAI_npc_klinfran(Creature* pCreature)
{
    return new npc_klinfranAI(pCreature);
}

void AddSC_burning_steppes()
{
    Script* newscript;

    //import SD2
    newscript = new Script;
    newscript->Name = "npc_grark_lorkrub";
    newscript->GetAI = &GetAI_npc_grark_lorkrub;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_grark_lorkrub;
    newscript->pEffectDummyCreature = &EffectDummyCreature_spell_capture_grark;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_klinfran";
    newscript->GetAI = &GetAI_npc_klinfran;
    newscript->pGossipHello =  &GossipHello_npc_klinfran;
    newscript->pGossipSelect = &GossipSelect_npc_klinfran;
    newscript->RegisterSelf();
}
