/* Copyright (C) 2006 - 2011 ScriptDev2 <http://www.scriptdev2.com/>
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
SDName: Boss_Victor_Nefarius
SD%Complete: 75
SDComment: Missing some text, Vael beginning event, and spawns Nef in wrong place
SDCategory: Blackwing Lair
EndScriptData */

#include "scriptPCH.h"
#include "blackwing_lair.h"

enum
{
    SAY_GAMESBEGIN_1                = -1469004,
    SAY_GAMESBEGIN_2                = -1469005,

    SAY_SCEPTER_RUN_START           = -1469031,
    SAY_SCEPTER_TAUNT_0             = -1469038,
    SAY_SCEPTER_TAUNT_1             = -1469040,
    SAY_SCEPTER_TAUNT_2             = -1469041,
    SAY_SCEPTER_TAUNT_3             = -1469042,
    SAY_SCEPTER_TAUNT_4             = -1469043,
    MAX_SCEPTER_TAUNTS              = 6,

    SAY_SCEPTER_RUN_LAUGHTER        = -1469039,

    SAY_SCEPTER_FAIL_LAUGHTER       = -1469044,
    SAY_SCEPTER_FAIL                = -1469045,

    GOSSIP_TEXT_NEFARIUS_1          = 7134,
    GOSSIP_TEXT_NEFARIUS_2          = 7198,
    GOSSIP_TEXT_NEFARIUS_3          = 7199,

    MAX_DRAKES                      = 5,
    MAX_DRAKE_KILLED                = 42,
    NPC_BRONZE_DRAKANOID            = 14263,
    NPC_BLUE_DRAKANOID              = 14261,
    NPC_RED_DRAKANOID               = 14264,
    NPC_GREEN_DRAKANOID             = 14262,
    NPC_BLACK_DRAKANOID             = 14265,
    NPC_CHROMATIC_DRAKANOID         = 14302,

    SPELL_NEFARIUS_BARRIER          = 22663,                // immunity in phase 1
    SPELL_SHADOWBOLT                = 22677,
    SPELL_SHADOWBOLT_VOLLEY         = 22665,
    SPELL_FEAR                      = 22678,
    SPELL_SILENCE                   = 22666,
    SPELL_SHADOW_COMMAND            = 22667,                // charm a player
    SPELL_SHADOW_BLINK              = 22664,                // 22681 ? // teleport around the room, possibly random
    SPELL_ROOT                      = 17507,
    SPELL_VISUAL_EFFECT             = 24180,
    SPELL_HOVER                     = 17131,

    FACTION_BLACK_DRAGON            = 103,
    FACTION_FRIENDLY                = 35,

    GO_DRAKONID_BONES               = 179804,

    NPC_NEFARIAN                    = 11583,

    QUEST_NEFARIUS_CORRUPTION       = 8730
};

struct SpawnLocation
{
    float m_fX, m_fY, m_fZ;
};

static SpawnLocation const aNefarianLocs[5] =
{
    { -7599.32f, -1191.72f, 475.545f},                      // opening where red/blue/black darknid spawner appear (ori 3.05433)
    { -7526.27f, -1135.04f, 473.445f},                      // same as above, closest to door (ori 5.75959)
    { -7515.644f, -1222.698f, 534.7169f},                    // nefarian spawn location (ori 1.798)
    { -7592.0f, -1264.0f, 481.0f},                          // hide pos (useless; remove this)
    { -7502.002f, -1256.503f, 486.758f}                    // nefarian fly to this position
};

static uint32 const aPossibleDrake[MAX_DRAKES] = {NPC_BRONZE_DRAKANOID, NPC_BLUE_DRAKANOID, NPC_RED_DRAKANOID, NPC_GREEN_DRAKANOID, NPC_BLACK_DRAKANOID};

//This script is complicated
//Instead of morphing Victor Nefarius we will have him control phase 1
//And then have him spawn "Nefarian" for phase 2
//When phase 2 starts Victor Nefarius will go invisible and stop attacking
//If Nefarian reched home because nef killed the players then nef will trigger this guy to EnterEvadeMode
//and allow players to start the event over
//If nefarian dies then he will kill himself then he will be despawned in Nefarian script
//To prevent players from doing the event twice

// Dev note: Lord Victor Nefarius should despawn completely, then ~5 seconds later Nefarian should appear.

struct boss_victor_nefariusAI : ScriptedAI
{
    explicit boss_victor_nefariusAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = static_cast<ScriptedInstance*>(pCreature->GetInstanceData());

        // Select the 2 different drakes that we are going to use until despawned
        // 5 possiblities for the first drake, 4 for the second, 20 total possiblites

        // select two different numbers between 0..MAX_DRAKES-1
        if (m_pInstance)
        {
            int const NUM_DRAKES = sizeof(aPossibleDrake) / sizeof(aPossibleDrake[0]);
            uint32 drakesType = m_pInstance->GetData64(DATA_NEF_COLOR);
            m_uiDrakeTypeOne = aPossibleDrake[drakesType % NUM_DRAKES];
            int idx2 = drakesType / NUM_DRAKES;
            if (idx2 == drakesType % NUM_DRAKES)
                ++idx2;
            m_uiDrakeTypeTwo = aPossibleDrake[idx2 % NUM_DRAKES];
        }

        boss_victor_nefariusAI::Reset();
    }

    uint32 const MAX_SCEPTER_RUN_TIME = 5 * HOUR * IN_MILLISECONDS;
    uint32 const SCEPTER_TAUNT_INTERVAL = MAX_SCEPTER_RUN_TIME / MAX_SCEPTER_TAUNTS;
    uint32 const SCEPTER_TAUNT_OFFSET = SCEPTER_TAUNT_INTERVAL / 2;

    ScriptedInstance* m_pInstance;

    uint32 m_uiKilledAdds;
    uint32 m_uiAddSpawnTimer;
    uint32 m_uiAddChromaSpawnTimer;
    uint32 m_uiShadowBoltTimer;
    uint32 m_uiShadowBoltVolleyTimer;
    uint32 m_uiFearTimer;
    uint32 m_uiSilenceTimer;
    uint32 m_uiMindControlTimer;
    uint32 m_uiShadowBlinkTimer;
    uint32 m_uiResetTimer;
    uint32 m_uiDrakeTypeOne;
    uint32 m_uiDrakeTypeTwo;
    uint32 m_uiEventTimer;
    uint32 blaBlaCount;
    uint32 scepterRunTime;
    uint32 nextScepterTauntTime;
    uint32 scepterTauntID;

    bool NefaEventStart;
    bool phase1;
    bool phase2;
    bool phase2bis;
    bool Smoke;
    bool scepterRun;
    bool watchScepterRun;

    ObjectGuid m_uiMindControledPlayerGuid;
    float m_uiMindControledPlayerAggro;

    void Reset() override
    {
        m_uiKilledAdds            = 0;
        m_uiAddSpawnTimer         = 6000;
        m_uiAddChromaSpawnTimer   = urand(7000, 9000);
        m_uiShadowBoltTimer       = 5000;
        m_uiShadowBoltVolleyTimer = 15000;
        m_uiFearTimer             = 8000;
        m_uiSilenceTimer          = 20000;
        m_uiMindControlTimer      = 25000;
        m_uiShadowBlinkTimer      = 1000;
        m_uiResetTimer            = 15 * MINUTE * IN_MILLISECONDS;
        scepterRunTime            = 0;
        nextScepterTauntTime      = 0;
        scepterTauntID            = 0;

        m_uiMindControledPlayerGuid.Clear();
        m_uiMindControledPlayerAggro = 0;

        m_uiEventTimer = 1000;
        blaBlaCount = 0;
        NefaEventStart = false;
        phase1 = false;
        phase2 = false;
        phase2bis = false;
        Smoke = false;
        scepterRun = false;
        watchScepterRun = false;

        m_creature->SetFactionTemplateId(FACTION_FRIENDLY);

        // set gossip flag to begin the event
        m_creature->SetStandState(UNIT_STAND_STATE_SIT_LOW_CHAIR);
        m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

        // Make visible if needed
        if (m_creature->GetVisibility() != VISIBILITY_ON)
            m_creature->SetVisibility(VISIBILITY_ON);

        LoadScepterRun();
    }

    void LoadScepterRun()
    {
        if (!m_pInstance)
            return;

        if (m_pInstance->GetData(TYPE_SCEPTER_RUN) == FAIL)
            return;

        watchScepterRun = true;

        if (m_pInstance->GetData(TYPE_SCEPTER_RUN) == IN_PROGRESS)
        {
            scepterRun = true;
            scepterRunTime = m_pInstance->GetData64(DATA_SCEPTER_RUN_TIME);

            // Find elapsed time + taunt time offset
            uint32 elapsedTime = MAX_SCEPTER_RUN_TIME - scepterRunTime;
            elapsedTime += SCEPTER_TAUNT_OFFSET;

            // Restore next scepter taunt ID
            scepterTauntID = elapsedTime / SCEPTER_TAUNT_INTERVAL;
            // Restore time to next taunt
            nextScepterTauntTime  = SCEPTER_TAUNT_INTERVAL - (elapsedTime % SCEPTER_TAUNT_INTERVAL);
        }

    }

    void StartScepterRun()
    {
        DoScriptText(SAY_SCEPTER_RUN_START, m_creature);

        scepterTauntID = 0;
        nextScepterTauntTime = SCEPTER_TAUNT_OFFSET;

        scepterRunTime = MAX_SCEPTER_RUN_TIME;
        scepterRun = true;

        m_pInstance->SetData(TYPE_SCEPTER_RUN, IN_PROGRESS);
    }

    void Aggro(Unit* /*pWho*/) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_NEFARIAN, IN_PROGRESS);

        m_creature->SetInCombatWithZone();
    }

    void EnterEvadeMode() override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void JustReachedHome() override
    {
        m_creature->SetFactionTemplateId(FACTION_FRIENDLY);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

        if (m_pInstance)
            m_pInstance->SetData(TYPE_NEFARIAN, FAIL);

        std::list<GameObject*> lGameObjects;
        m_creature->GetGameObjectListWithEntryInGrid(lGameObjects, GO_DRAKONID_BONES, 250.0f);
        for (const auto& pGo : lGameObjects)
            pGo->DeleteLater();

        // @TODO: Find out why there is this reset bug !!
        //m_creature->SetRespawnDelay(900); // 15mn 900
        m_creature->SetRespawnDelay(10);
        m_creature->DisappearAndDie();
    }

    void JustSummoned(Creature* pSummoned) override
    {
        if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
        {
            pSummoned->SetInCombatWithZone();
            pSummoned->AI()->AttackStart(pTarget);
        }

        pSummoned->SetRespawnDelay(7 * DAY);
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        // Despawn self when Nefarian is killed
        if (pSummoned->GetEntry() == NPC_NEFARIAN)
        {
            if (nullptr == m_pInstance)
                return;

            uint32 scepterRunResult = FAIL;

            // Check for successful Scepter Shard Run
            if (scepterRun)
            {
                // Check if still has time left
                if (Player* scepterChampion = m_creature->GetMap()->GetPlayer(m_pInstance->GetData64(DATA_SCEPTER_CHAMPION)))
                    if (scepterChampion->GetQuestStatus(QUEST_NEFARIUS_CORRUPTION) == QUEST_STATUS_INCOMPLETE)
                        scepterRunResult = DONE;

            }

            m_pInstance->SetData(TYPE_SCEPTER_RUN, scepterRunResult);


            m_creature->SetRespawnDelay(7 * DAY);
            m_creature->ForcedDespawn();
        }
        else
            ++m_uiKilledAdds;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (NefaEventStart && !phase1)
        {
            if (m_uiEventTimer < uiDiff)
            {
                ++blaBlaCount;
                switch (blaBlaCount)
                {
                    case 1:
                        DoScriptText(SAY_GAMESBEGIN_1, m_creature);
                        m_uiEventTimer = 7000;
                        break;
                    case 2:
                        DoScriptText(SAY_GAMESBEGIN_2, m_creature);
                        m_uiEventTimer = 4000;
                        break;
                    case 3:
                        DoCastSpellIfCan(m_creature, SPELL_NEFARIUS_BARRIER);
                        m_creature->SetFactionTemplateId(FACTION_BLACK_DRAGON);

                        Map::PlayerList const &liste = m_creature->GetMap()->GetPlayers();
                        for (const auto& i : liste)
                            if (i.getSource() && i.getSource()->IsAlive())
                                m_creature->AddThreat(i.getSource(), 10000.0f);

                        DoCastSpellIfCan(m_creature, SPELL_ROOT, CF_TRIGGERED); // root
                        break;
                }
            }
            else
                m_uiEventTimer -= uiDiff;
        }

        if (watchScepterRun && nullptr != m_pInstance)
        {
            if (scepterRun)
            {
                HandleScepterRun(uiDiff);
            }
            else
            {
                uint32 scepterRunStatus = m_pInstance->GetData(TYPE_SCEPTER_RUN);

                if (FAIL == scepterRunStatus)
                {
                    watchScepterRun = false;
                }
                else if (SPECIAL == scepterRunStatus)
                {
                    StartScepterRun();
                }
            }
        }


        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        if (phase2bis)
            return;

        if (m_uiKilledAdds >= MAX_DRAKE_KILLED) // 42 drakes killed
        {
            phase2bis = true;
            if (phase2)
                return;
        }

        // Add spawning mechanism
        if (m_uiAddSpawnTimer < uiDiff)
        {
            m_creature->SummonCreature(m_uiDrakeTypeOne,
                aNefarianLocs[0].m_fX,
                aNefarianLocs[0].m_fY,
                aNefarianLocs[0].m_fZ,
                5.000f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10 * IN_MILLISECONDS);
            m_creature->SummonCreature(m_uiDrakeTypeTwo,
                aNefarianLocs[1].m_fX,
                aNefarianLocs[1].m_fY,
                aNefarianLocs[1].m_fZ,
                5.000f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10 * IN_MILLISECONDS);

            m_uiAddSpawnTimer = urand(6000, 7000);
        }
        else
            m_uiAddSpawnTimer -= uiDiff;

        if (m_uiAddChromaSpawnTimer < uiDiff)
        {
            m_creature->SummonCreature(NPC_CHROMATIC_DRAKANOID,
                aNefarianLocs[0].m_fX,
                aNefarianLocs[0].m_fY,
                aNefarianLocs[0].m_fZ,
                5.000f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10 * IN_MILLISECONDS);
            m_creature->SummonCreature(NPC_CHROMATIC_DRAKANOID,
                aNefarianLocs[1].m_fX,
                aNefarianLocs[1].m_fY,
                aNefarianLocs[1].m_fZ,
                5.000f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 10 * IN_MILLISECONDS);
            m_uiAddChromaSpawnTimer = 35000;
        }
        else
            m_uiAddChromaSpawnTimer -= uiDiff;

        if (phase2) // 40 drakes killed
            return;

        //Begin phase 2 by spawning Nefarian
        if (m_uiKilledAdds >= (MAX_DRAKE_KILLED - 2)) // 40 drakes killed
        {
            //Inturrupt any spell casting
            m_creature->InterruptNonMeleeSpells(false);

            //Root self
            DoCastSpellIfCan(m_creature, SPELL_ROOT, CF_TRIGGERED);

            //Make super invis
            if (m_creature->GetVisibility() != VISIBILITY_OFF)
                m_creature->SetVisibility(VISIBILITY_OFF);

            // Spawn Nefarian
            // Summon as active, to be able to work proper!
            if (Creature* pNefarian = m_creature->SummonCreature(NPC_NEFARIAN,
                aNefarianLocs[2].m_fX,
                aNefarianLocs[2].m_fY,
                aNefarianLocs[2].m_fZ,
                0, TEMPSUMMON_MANUAL_DESPAWN, 0, true))
            {
                pNefarian->CastSpell(pNefarian, SPELL_HOVER, true);
                pNefarian->SetFly(true);
            }

            // Nefarian spawn when 40 drakes are killed
            // Adds will stop spawning when 42 are killed
            // He flies then arrives at his spawn point staying in the air
            // 10 seconds later: arise and cast shadow flame
            phase2 = true;
            return;
        }

        // Shadowbolt Timer
        if (m_uiShadowBoltTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWBOLT) == CAST_OK)
                m_uiShadowBoltTimer = urand(3000, 10000);
        }
        else
            m_uiShadowBoltTimer -= uiDiff;

        // Shadowbolt Volley Timer
        if (m_uiShadowBoltVolleyTimer < uiDiff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOWBOLT_VOLLEY) == CAST_OK)
                m_uiShadowBoltVolleyTimer = 15000;
        }
        else
            m_uiShadowBoltVolleyTimer -= uiDiff;

        // Fear Timer
        if (m_uiFearTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_FEAR) == CAST_OK)
                    m_uiFearTimer = urand(15000, 25000);
            }
        }
        else
            m_uiFearTimer -= uiDiff;

        // Silence Timer
        if (m_uiSilenceTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                if (DoCastSpellIfCan(pTarget, SPELL_SILENCE) == CAST_OK)
                    m_uiSilenceTimer = urand(25000, 40000);
            }
        }
        else
            m_uiSilenceTimer -= uiDiff;

        // Shadow Blink Timer
        if (m_uiShadowBlinkTimer < uiDiff)
        {
            if (!Smoke)
            {
                m_creature->InterruptNonMeleeSpells(false);
                m_creature->SendSpellGo(m_creature, SPELL_VISUAL_EFFECT);
                m_uiShadowBlinkTimer = 1000;
                Smoke = true;
            }
            else if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0))
            {
                m_creature->NearTeleportTo(pTarget->GetPositionX() + float(urand(0, 8)), pTarget->GetPositionY() + float(urand(0, 8)), pTarget->GetPositionZ(), m_creature->GetOrientation());
                m_creature->SendSpellGo(m_creature, SPELL_VISUAL_EFFECT);
                AttackStart(pTarget);
                m_creature->SetInCombatWithZone();
                DoCastSpellIfCan(m_creature, SPELL_ROOT, CF_TRIGGERED);    // Root Self
                m_uiShadowBlinkTimer = urand(20000, 25000);
                m_uiShadowBoltTimer = urand(3000, 6000);
                Smoke = false;
            }
        }
        else
            m_uiShadowBlinkTimer -= uiDiff;

        if (m_uiMindControledPlayerGuid)
        {
            if (Unit* pTarget = m_creature->GetMap()->GetPlayer(m_uiMindControledPlayerGuid))
            {
                if (!pTarget->HasAura(SPELL_SHADOW_COMMAND))
                {
                    m_creature->GetThreatManager().modifyThreatPercent(pTarget, -100);
                    m_creature->GetThreatManager().addThreatDirectly(pTarget, m_uiMindControledPlayerAggro);
                    DoCastSpellIfCan(m_creature, SPELL_ROOT, CF_TRIGGERED);    // Root self
                    m_uiMindControledPlayerGuid.Clear();
                    m_uiMindControledPlayerAggro = 0;
                }
            }
            else
            {
                m_uiMindControledPlayerGuid.Clear();
                m_uiMindControledPlayerAggro = 0;
            }
        }

        // Mind Control Timer
        if (m_uiMindControlTimer < uiDiff)
        {
            if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
            {
                m_uiMindControledPlayerGuid = pTarget->GetObjectGuid();
                m_uiMindControledPlayerAggro = m_creature->GetThreatManager().getThreat(pTarget);
                if (DoCastSpellIfCan(pTarget, SPELL_SHADOW_COMMAND, CF_AURA_NOT_PRESENT) == CAST_OK)
                    m_uiMindControlTimer = urand(25000, 40000);
            }
        }
        else
            m_uiMindControlTimer -= uiDiff;
    }

    void HandleScepterRun(uint32 uiDiff)
    {
        if (!m_pInstance)
            return;

        // Handle Nefarius' taunts throughout the run
        if (nextScepterTauntTime <= uiDiff)
        {
            switch (scepterTauntID)
            {
                case 0:
                    DoScriptText(SAY_SCEPTER_TAUNT_0, m_creature);
                    DoScriptText(SAY_SCEPTER_RUN_LAUGHTER, m_creature);
                    break;

                case 1:
                    DoScriptText(SAY_SCEPTER_TAUNT_1, m_creature);
                    break;

                case 2:
                    DoScriptText(SAY_SCEPTER_TAUNT_2, m_creature);
                    break;

                case 3:
                    DoScriptText(SAY_SCEPTER_TAUNT_3, m_creature);
                    break;

                case 4:
                    DoScriptText(SAY_SCEPTER_TAUNT_4, m_creature);
                    break;

            }

            scepterTauntID ++;
            nextScepterTauntTime = SCEPTER_TAUNT_INTERVAL;

        }
        else
            nextScepterTauntTime -= uiDiff;

        // Check overall Scepter Run time
        if (scepterRunTime <= uiDiff)
            FailScepterRun();
        else
            scepterRunTime -= uiDiff;


        m_pInstance->SetData(DATA_SCEPTER_RUN_TIME, scepterRunTime);
    }

    void FailScepterRun()
    {
        if (nullptr == m_pInstance)
            return;

        scepterRun =  false;
        watchScepterRun = false;
        m_pInstance->SetData(TYPE_SCEPTER_RUN, FAIL);

        DoScriptText(SAY_SCEPTER_FAIL, m_creature);
        DoScriptText(SAY_SCEPTER_FAIL_LAUGHTER, m_creature);
    }
};


CreatureAI* GetAI_boss_victor_nefarius(Creature* creature)
{
    if (creature->GetMapId() == 469) //BWL
        return new boss_victor_nefariusAI(creature);

    // UBRS
    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER);
    return new NullCreatureAI(creature);
}

void NefariusGossipOptionClicked(Creature* pCreature)
{
    if (auto pNefarius = dynamic_cast<boss_victor_nefariusAI*>(pCreature->AI()))
        pNefarius->NefaEventStart = true;
}

void AddSC_boss_victor_nefarius()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "boss_victor_nefarius";
    pNewScript->GetAI = &GetAI_boss_victor_nefarius;
    pNewScript->RegisterSelf();
}
