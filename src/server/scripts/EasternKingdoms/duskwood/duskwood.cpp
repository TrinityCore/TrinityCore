/*
 * Auteur        : Chakor
 * All rights reserved */

/* ScriptData
SDName: Duskwood
SD%Complete: 100
SDComment: Quest support: 252
SDCategory: Duskwood
EndScriptData */

/* ContentData
npc_lord_ello_ebonlocke
EndContentData */

#include "scriptPCH.h"
#include "CreatureGroups.h"

enum NightmareCorruptionData
{
    SPELL_SOUL_CORRUPTION = 25805,
    SPELL_CREATURE_OF_NIGHTMARE = 25806,
    SPELL_SWELL_OF_SOULS = 21307,

    NPC_TWILIGHT_CORRUPTER = 15625,

    QUEST_NIGHTMARE_CORRUPTION = 8735,
};

void Handle_NightmareCorruption(/*const*/ Player* player)
{
    if (player->IsDead() || player->GetQuestStatus(QUEST_NIGHTMARE_CORRUPTION) != QUEST_STATUS_INCOMPLETE)
    {
        return;
    }

    auto corrupter = player->FindNearestCreature(NPC_TWILIGHT_CORRUPTER, 350.0f);

    if (!corrupter)
    {
        corrupter = player->SummonCreature(NPC_TWILIGHT_CORRUPTER, -10335.9f, -489.051f, 50.6233f, 2.59373f,
            TEMPSUMMON_DEAD_DESPAWN, 0);

        if (!corrupter)
        {
            sLog.outError("Handle_NightmareCorruption: Could not summon creature %u for quest %u for player %s",
                NPC_TWILIGHT_CORRUPTER, QUEST_NIGHTMARE_CORRUPTION, player->GetName());
            return;
        }
    }

    char message[200];
    sprintf(message, "Come, %s. See what the Nightmare brings...", player->GetName());

    corrupter->MonsterWhisper(message, player);
}

bool AreaTrigger_at_twilight_grove(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    Handle_NightmareCorruption(pPlayer);
    return false;
}

enum TwilightCorrupterData
{
    AGGRO_TEXT = 11269
};

struct npc_twilight_corrupterAI : ScriptedAI
{
    explicit npc_twilight_corrupterAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_twilight_corrupterAI::Reset();
    }

    uint32 m_uiSoulCorruptionTimer;
    uint32 m_uiCreatureOfNightmareTimer;
    uint32 m_uiCheckTimer;
    bool bEngaged;
    uint64 CoNPlayerGuid;
    float CoNPlayerAggro;
    uint64 GUIDs[40];

    void Reset() override
    {
        m_uiSoulCorruptionTimer         = urand(6000, 18000);
        m_uiCreatureOfNightmareTimer    = urand(10000, 20000);
        m_uiCheckTimer  = 1000;
        CoNPlayerGuid   = 0;
        CoNPlayerAggro  = 0;
        bEngaged        = false;

        for (uint64 & guid : GUIDs)
            guid = 0;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!bEngaged)
        {
            DoScriptText(AGGRO_TEXT, m_creature);
            bEngaged = true;
        }
    }

    void FillPlayerList()
    {
        for (uint64 & guid : GUIDs)
            guid = 0;

        ThreatList const& tList = m_creature->GetThreatManager().getThreatList();
        for (const auto i : tList)
        {
            Unit* pUnit = m_creature->GetMap()->GetUnit(i->getUnitGuid());

            if (pUnit && pUnit->IsPlayer())
                for (uint64 & guid : GUIDs)
                    if (guid == 0)
                        guid = pUnit->GetGUID();
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiSoulCorruptionTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature, SPELL_SOUL_CORRUPTION) == CAST_OK)
                m_uiSoulCorruptionTimer = urand(20000, 30000);
        }
        else
            m_uiSoulCorruptionTimer -= uiDiff;

        if (CoNPlayerGuid)
        {
            if (Unit* pTarget = m_creature->GetMap()->GetPlayer(CoNPlayerGuid))
            {
                if (!pTarget->HasAura(SPELL_CREATURE_OF_NIGHTMARE))
                {
                    m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                    m_creature->GetThreatManager().addThreatDirectly(pTarget, CoNPlayerAggro);
                    CoNPlayerGuid = 0;
                    CoNPlayerAggro = 0;
                }
            }
            else
            {
                CoNPlayerGuid = 0;
                CoNPlayerAggro = 0;
            }
        }

        if (m_uiCreatureOfNightmareTimer < uiDiff)
        {
            Unit* pTarg = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0);
            if (pTarg && pTarg->IsPlayer())
            {
                CoNPlayerGuid = pTarg->GetGUID();
                CoNPlayerAggro = m_creature->GetThreatManager().getThreat(pTarg);
                if (DoCastSpellIfCan(pTarg, SPELL_CREATURE_OF_NIGHTMARE) == CAST_OK)
                    m_uiCreatureOfNightmareTimer = urand(35000, 40000);
            }
        }
        else
            m_uiCreatureOfNightmareTimer -= uiDiff;

        if (m_uiCheckTimer < uiDiff)
        {
            FillPlayerList();
            for (uint64 & guid : GUIDs)
            {
                if (Player* player = m_creature->GetMap()->GetPlayer(guid))
                {
                    if (player->IsDead())
                    {
                        char eMessage[200];
                        sprintf(eMessage, "Twilight Corrupter squeezes the last bit of life out of %s and swallows their soul.", player->GetName());
                        m_creature->MonsterTextEmote(eMessage, nullptr, false);
                        m_creature->CastSpell(m_creature, SPELL_SWELL_OF_SOULS, true);
                        guid = 0;
                    }
                }
            }
            m_uiCheckTimer = 1000;
        }
        else
            m_uiCheckTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_twilight_corrupter(Creature* pCreature)
{
    return new npc_twilight_corrupterAI(pCreature);
}

/*
 * Watcher Blomberg (Stitches event support)
 */

enum WatcherBlombergData
{
    NPC_WATCHER_DODDS   = 888,
    NPC_WATCHER_PAIGE   = 499
};

struct npc_watcher_blombergAI : ScriptedAI
{
    explicit npc_watcher_blombergAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_watcher_blombergAI::Reset();
        npc_watcher_blombergAI::ResetCreature();
    }

    bool m_bIsEngaged;
    uint32 m_uiSayTimer;
    ObjectGuid m_DoddsGuid;
    ObjectGuid m_PaigeGuid;

    void Reset() override
    {
        m_creature->SetWalk(false);
    }

    void ResetCreature() override
    {
        m_bIsEngaged = false;
        m_uiSayTimer = 3000;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_bIsEngaged)
        {
            if (m_uiSayTimer < uiDiff)
            {
                m_creature->MonsterSay("The abomination is coming! Dodds! Paige! Come here and help us!");
                m_bIsEngaged = true;

                if (auto pDodds = m_creature->FindNearestCreature(NPC_WATCHER_DODDS, 200.0f))
                {
                    m_DoddsGuid = pDodds->GetObjectGuid();
                    pDodds->GetMotionMaster()->MovePoint(0, -10903.043945f, -377.539124f, 40.065773f, MOVE_PATHFINDING, 0, 1.19f);                    
                }


                if (auto pPaige = m_creature->FindNearestCreature(NPC_WATCHER_PAIGE, 200.0f))
                {
                    m_PaigeGuid = pPaige->GetObjectGuid();
                    pPaige->GetMotionMaster()->MovePoint(0, -10906.221680f, -375.957214f, 39.960278f, MOVE_PATHFINDING, 0, 1.19f);                    
                }
            }
            else
                m_uiSayTimer -= uiDiff;
        }

        ScriptedAI::UpdateAI(uiDiff);
    }
};

CreatureAI* GetAI_watcherBlomberg(Creature* pCreature)
{
    return new npc_watcher_blombergAI(pCreature);
}

/*
 * Watcher Selkin (Stitches event support)
 */

struct npc_watcher_selkinAI : npc_escortAI
{
    explicit npc_watcher_selkinAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        npc_watcher_selkinAI::Reset();
    }

    void Reset() override
    {
        m_creature->SetWalk(false);
    }

    void WaypointReached(uint32 /*uiPoint*/) override { }
};

CreatureAI* GetAI_watcherSelkin(Creature* pCreature)
{
    return new npc_watcher_selkinAI(pCreature);
}

struct npc_commander_felstromAI : ScriptedAI
{
    explicit npc_commander_felstromAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        npc_commander_felstromAI::Reset();
    }

    bool b_suicide;
    uint32 m_uiSuicide_Timer;

    void Reset() override
    {
        m_uiSuicide_Timer = 1500;
        b_suicide = false;
        m_creature->ForceValuesUpdateAtIndex(UNIT_DYNAMIC_FLAGS);
    }

    void JustDied(Unit* Killer) override
    {
        if (Killer->GetEntry() == 771)
            m_creature->SetLootRecipient(nullptr);
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiSuicide_Timer < uiDiff)
        {
            if (m_creature->GetHealthPercent() <= 10.0f)
            {
                if (!b_suicide)
                {
                    DoCastSpellIfCan(m_creature, 3488, true);
                    b_suicide = true;
                }
            }
        }
        else
            m_uiSuicide_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_commanderFelstrom(Creature* pCreature)
{
    return new npc_commander_felstromAI(pCreature);
}

/*
* Lord Ello Ebonlocke
*/

enum LordElloEbonlockeData
{
    NPC_STITCHES = 412,

    QUEST_TRANSLATION_TO_ELO = 252
};

struct elloEbonlockeAI : ScriptedAI
{
    explicit elloEbonlockeAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        elloEbonlockeAI::Reset();
        elloEbonlockeAI::ResetCreature();
    }

    ObjectGuid m_stitchesGuid;
    uint32 m_uiTimer;
    bool m_bCanSummon;

    void Reset() override { }

    void ResetCreature() override
    {
        m_bCanSummon = false;
        m_uiTimer = 3000;
    }

    void StitchesDied()
    {
        m_uiTimer = 10 * MINUTE * IN_MILLISECONDS;
        m_stitchesGuid.Clear();
    }

    bool SummonStitches();

    void LaunchStitches(Creature* pStitches) const;

    void UpdateAI(uint32 const uiDiff) override
    {
        if (!m_stitchesGuid && !m_bCanSummon)
        {
            if (m_uiTimer < uiDiff)
                m_bCanSummon = true;
            else
                m_uiTimer -= uiDiff;
        }

        ScriptedAI::UpdateAI(uiDiff);
    }
};

/*
 * Stitches
 */

enum StitchesData
{
    NPC_WATCHER_CORWIN      = 1204,
    NPC_WATCHER_SARYS       = 1203,
    NPC_TOWN_CRIER          = 468,
    NPC_WATCHER_HUTCHINS    = 1001,
    NPC_WATCHER_BLOMBERG    = 1000,
    NPC_WATCHER_CUTFORD     = 1436,
    NPC_WATCHER_MERANT      = 1098,
    NPC_WATCHER_GELWIN      = 1099,
    NPC_WATCHER_SELKIN      = 1100,
    NPC_WATCHER_THAYER      = 1101,

    STITCHES_YELL_1         = 277,
    STITCHES_YELL_2         = 278,
    TOWNCRIER_YELL_1        = 89,
    TOWNCRIER_YELL_2        = 90,
    TOWNCRIER_YELL_3        = 91,
    TOWNCRIER_YELL_4        = 92,
    TOWNCRIER_YELL_5        = 93,
    CUTFORD_YELL            = 276,

    SPELL_AURA_OF_ROT       = 3106
};

struct Coords
{
    uint32 entry;
    float x, y, z, o;
};

static const Coords Watchman[] = 
{
    { NPC_WATCHER_HUTCHINS, -10912.09f, -394.11f, 41.11f, 5.93f },
    { NPC_WATCHER_BLOMBERG, -10909.53f, -397.48f, 41.14f, 5.93f },

    { NPC_WATCHER_CUTFORD,  -10910.27f, -519.03f, 52.99f, 5.93f },

    { NPC_WATCHER_SELKIN,   -10618.22f, -1185.36f, 28.58f, 5.93f },
    { NPC_WATCHER_GELWIN,   -10618.90f, -1182.15f, 28.57f, 5.93f },
    { NPC_WATCHER_MERANT,   -10616.64f, -1181.67f, 28.49f, 5.93f },
    { NPC_WATCHER_THAYER,   -10615.99f, -1184.56f, 28.46f, 5.93f },

    { NPC_WATCHER_SARYS,    -10574.31f, -1179.06f, 28.03f, 3.05f },
    { NPC_WATCHER_CORWIN,   -10575.13f, -1170.07f, 28.25f, 3.61f }
};

struct npc_stitchesAI : npc_escortAI
{
    explicit npc_stitchesAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        npc_stitchesAI::Reset();
    }

    std::list<ObjectGuid> m_lWatchman;
    ObjectGuid m_townCrierGuid, m_DoddsGuid, m_PaigeGuid, m_lordElloGuid;
    uint32 m_uiAuraOfRotTimer;
    uint32 m_uiLaunchTimer;
    bool m_bLaunchChecked;

    void Reset() override
    {
        m_uiAuraOfRotTimer = 0;
        m_uiLaunchTimer = 10000;
        m_bLaunchChecked = false;
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        auto pTownCrier = m_creature->GetMap()->GetCreature(m_townCrierGuid);
        if (pTownCrier && pTownCrier->IsAlive())
            pTownCrier->MonsterYellToZone(TOWNCRIER_YELL_5);

        DespawnWatcher();

        if (auto pDodds = m_creature->GetMap()->GetCreature(m_DoddsGuid))
            pDodds->GetMotionMaster()->MoveTargetedHome();

        if (auto pPaige = m_creature->GetMap()->GetCreature(m_PaigeGuid))
            pPaige->GetMotionMaster()->MoveTargetedHome();

        if (auto pEllo = m_creature->GetMap()->GetCreature(m_lordElloGuid))
        {
            if (auto pElloAI = static_cast<elloEbonlockeAI*>(pEllo->AI()))
                pElloAI->StitchesDied();
        }
    }

    void KilledUnit(Unit* pUnit) override
    {
        if (pUnit && (pUnit->GetEntry() == NPC_WATCHER_SELKIN))
        {
            auto pTownCrier = m_creature->GetMap()->GetCreature(m_townCrierGuid);
            if (pTownCrier && pTownCrier->IsAlive())
                pTownCrier->MonsterYellToZone(TOWNCRIER_YELL_3);
        }
    }

    void DespawnWatcher()
    {
        for (const auto& guid : m_lWatchman)
        {
            if (auto pWatchman = m_creature->GetMap()->GetCreature(guid))
            {
                if (pWatchman->IsAlive())
                    pWatchman->DisappearAndDie();
            }
        }
    }

    Creature* SummonWatchman(uint8 index) const
    {
        return m_creature->SummonCreature(Watchman[index].entry, 
            Watchman[index].x,
            Watchman[index].y,
            Watchman[index].z,
            Watchman[index].o, TEMPSUMMON_DEAD_DESPAWN, 10000, true);
    }

    void AddToFormation(Creature* pLeader, Creature* pAdd) const
    {
        if (!pLeader || !pAdd)
            return;

        pAdd->JoinCreatureGroup(pLeader, 4.0f, pLeader->GetAngle(pAdd) - (pAdd)->GetOrientation(),
            OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER | OPTION_EVADE_TOGETHER);
    }

    void JustSummoned(Creature* pSummoned) override
    {
        m_lWatchman.push_back(pSummoned->GetObjectGuid());

        switch (pSummoned->GetEntry())
        {
            case NPC_WATCHER_HUTCHINS:
                pSummoned->SetWalk(false);
                pSummoned->GetMotionMaster()->MovePoint(0, -10905.52f, -374.1f, 39.88f, MOVE_PATHFINDING);
                pSummoned->SetCombatStartPosition(-10905.52f, -374.1f, 39.88f);
                pSummoned->SetHomePosition(-10905.52f, -374.1f, 39.88f, 0.0f); 
                break;
            case NPC_WATCHER_BLOMBERG:
                pSummoned->SetWalk(false);
                pSummoned->GetMotionMaster()->MovePoint(0, -10902.211914f, -375.488495f, 40.000954f, MOVE_PATHFINDING);
                pSummoned->SetCombatStartPosition(-10902.211914f, -375.488495f, 40.000954f);
                pSummoned->SetHomePosition(-10902.211914f, -375.488495f, 40.000954f, 0.0f);
                if (auto pSummonedAI = static_cast<npc_watcher_blombergAI*>(pSummoned->AI()))
                {
                    m_DoddsGuid = pSummonedAI->m_DoddsGuid;
                    m_PaigeGuid = pSummonedAI->m_PaigeGuid;
                }
                break;
            case NPC_WATCHER_CUTFORD:
                pSummoned->SetWalk(false);
                if (pSummoned->GetDistance2d(m_creature) > 40.0f)
                {
                    pSummoned->GetMotionMaster()->MovePoint(0, -10904.632f, -425.087f, 42.189217f, MOVE_PATHFINDING);
                    pSummoned->SetCombatStartPosition(-10904.632f, -425.087f, 42.189217f);
                    pSummoned->SetHomePosition(-10904.632f, -425.087f, 42.189217f, 0.0f);
                }
                else
                    pSummoned->AI()->AttackStart(m_creature);
                pSummoned->MonsterYell(CUTFORD_YELL);
                break;
            case NPC_WATCHER_SELKIN:
                if (auto pSummonedAI = static_cast<npc_watcher_selkinAI*>(pSummoned->AI()))
                    pSummonedAI->Start(true);
                break;
        }
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        m_lWatchman.remove(pSummoned->GetObjectGuid());
    }

    void WaypointReached(uint32 uiPoint) override
    {
        switch (uiPoint)
        {
            case 10:
            case 29:
                m_creature->MonsterYellToZone(STITCHES_YELL_1);
                break;
            case 30:
                {
                    auto pTownCrier = m_creature->GetMap()->GetCreature(m_townCrierGuid);
                    if (pTownCrier && pTownCrier->IsAlive())
                        pTownCrier->MonsterYellToZone(TOWNCRIER_YELL_1);
                }
                break;
            case 31:
                SummonWatchman(0);
                SummonWatchman(1);
                break;
            case 34:
                SummonWatchman(2);
                break;
            case 35:
            {
                auto pTownCrier = m_creature->GetMap()->GetCreature(m_townCrierGuid);
                if (pTownCrier && pTownCrier->IsAlive())
                    pTownCrier->MonsterYellToZone(TOWNCRIER_YELL_2);
            }
            break;
            case 39:
            {
                auto pLeader = SummonWatchman(3);
                AddToFormation(pLeader, SummonWatchman(4));
                AddToFormation(pLeader, SummonWatchman(5));
                AddToFormation(pLeader, SummonWatchman(6));
                pLeader->SetWalk(false);             
            }
            break;
            case 61:
            {
                m_creature->MonsterYellToZone(STITCHES_YELL_1);
                SummonWatchman(7);
                SummonWatchman(8);
                auto pTownCrier = m_creature->GetMap()->GetCreature(m_townCrierGuid);
                if (pTownCrier && pTownCrier->IsAlive())
                    pTownCrier->MonsterYellToZone(TOWNCRIER_YELL_4);
            }
            break;
            case 65:
                m_creature->SetHomePosition(m_creature->GetPositionX(), m_creature->GetPositionY(), m_creature->GetPositionZ(), 1.64f);
                Stop();
                m_creature->GetMotionMaster()->MoveRandom();
                break;
        }
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (!urand(0, 3))
            m_creature->MonsterYell(STITCHES_YELL_2);
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_bLaunchChecked)
        {
            if (m_uiLaunchTimer < uiDiff)
            {
                if (!HasEscortState(STATE_ESCORT_ESCORTING))
                {
                    sLog.outError("[Duskwood.Stitches] Emergency launch.");
                    Start();
                }

                m_bLaunchChecked = true;
            }
            else
                m_uiLaunchTimer -= uiDiff;            
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (m_uiAuraOfRotTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_AURA_OF_ROT) == CAST_OK)
                m_uiAuraOfRotTimer = 3000;
        }
        else
        {
            m_uiAuraOfRotTimer -= uiDiff;
            DoMeleeAttackIfReady();
        }  
    }
};

CreatureAI* GetAI_stitches(Creature* pCreature)
{
    return new npc_stitchesAI(pCreature);
}

/*
 * Lord Ello Ebonlocke
 */

bool elloEbonlockeAI::SummonStitches()
{
    if (m_creature->GetMap()->GetCreature(m_stitchesGuid))
        return false;

    if (!m_bCanSummon)
        return false;

    if (auto pStitches = m_creature->SummonCreature(NPC_STITCHES, -10277.63f, 54.27f, 42.2f, 4.22f, TEMPSUMMON_DEAD_DESPAWN, 0, true))
    {
        m_bCanSummon = false;
        m_stitchesGuid = pStitches->GetObjectGuid();
        pStitches->SetObjectScale(2.0f);

        LaunchStitches(pStitches);
        return true;
    }

    return false;
}

void elloEbonlockeAI::LaunchStitches(Creature* pStitches) const
{
    if (auto stitchesAI = static_cast<npc_stitchesAI*>(pStitches->AI()))
    {
        if (auto pTownCrier = m_creature->FindNearestCreature(NPC_TOWN_CRIER, 400.0f))
            stitchesAI->m_townCrierGuid = pTownCrier->GetObjectGuid();

        stitchesAI->m_lordElloGuid = m_creature->GetObjectGuid();

        stitchesAI->Start();
    }
    else
        sLog.outError("[Duskwood.Stitches] Failed to cast AI.");
}

CreatureAI* GetAI_ElloEbonlocke(Creature* pCreature)
{
    return new elloEbonlockeAI(pCreature);
}

bool QuestRewarded_npc_lord_ello_ebonlocke(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_TRANSLATION_TO_ELO)
    {
        if (auto pCreatureAI = static_cast<elloEbonlockeAI*>(pCreature->AI()))
            return !pCreatureAI->SummonStitches();
    }

    return false;
}

void AddSC_duskwood()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "commander_felstrom";
    newscript->GetAI = &GetAI_commanderFelstrom;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "watcher_selkin";
    newscript->GetAI = &GetAI_watcherSelkin;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "watcher_blomberg";
    newscript->GetAI = &GetAI_watcherBlomberg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_stitches";
    newscript->GetAI = &GetAI_stitches;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lord_ello_ebonlocke";
    newscript->GetAI = &GetAI_ElloEbonlocke;
    newscript->pQuestRewardedNPC = &QuestRewarded_npc_lord_ello_ebonlocke;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_twilight_grove";
    newscript->pAreaTrigger = &AreaTrigger_at_twilight_grove;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_twilight_corrupter";
    newscript->GetAI = &GetAI_npc_twilight_corrupter;
    newscript->RegisterSelf();
}
