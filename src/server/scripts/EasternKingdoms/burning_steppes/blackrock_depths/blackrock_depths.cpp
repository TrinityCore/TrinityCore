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
SDName: Blackrock_Depths
SD%Complete: 80
SDComment: Quest support: 4001, 4342, 7604. Vendor Lokhtos Darkbargainer.
SDCategory: Blackrock Depths
EndScriptData */

/* ContentData
go_shadowforge_brazier
at_ring_of_law
npc_grimstone
mob_phalanx
npc_lokhtos_darkbargainer
go_dark_keeper_portrait
go_thunderbrew_laguer_keg
go_relic_coffer_door
npc_watchman_doomgrip
npc_ribbly_fermevanne
npc_golem_lord_argelmach
npc_GorShak
*/

#include "scriptPCH.h"
#include "blackrock_depths.h"
#include "CreatureGroups.h"

/*######
## go_shadowforge_brazier
######*/

bool GOHello_go_shadowforge_brazier(Player* pPlayer, GameObject* pGo)
{
    if (ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData())
    {
        if (pInstance->GetData(TYPE_LYCEUM) == IN_PROGRESS)
            pInstance->SetData(TYPE_LYCEUM, DONE);
        else
            pInstance->SetData(TYPE_LYCEUM, IN_PROGRESS);
    }
    return false;
}

/*######
## npc_grimstone
######*/

enum
{
    //4 or 6 in total? 1+2+1 / 2+2+2 / 3+3. Depending on this, code should be changed.
    MAX_MOB_AMOUNT      = 8
};

uint32 RingMob[] =
{
    8925,                                                   // Dredge Worm
    8926,                                                   // Deep Stinger
    8927,                                                   // Dark Screecher
    8928,                                                   // Burrowing Thundersnout
    8933,                                                   // Cave Creeper
    8932,                                                   // Borer Beetle
};

uint32 RingBoss[] =
{
    9027,                                                   // Gorosh
    9028,                                                   // Grizzle
    9029,                                                   // Eviscerator
    9030,                                                   // Ok'thor
    9031,                                                   // Anub'shiah
    9032,                                                   // Hedrum
};

/*######
## npc_grimstone
######*/

struct npc_grimstoneAI : public npc_escortAI
{
    npc_grimstoneAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        MobSpawnId = urand(0, 5);
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint8 EventPhase;
    uint32 Event_Timer;

    uint8 MobSpawnId;
    uint8 MobCount;
    uint32 MobDeath_Timer;

    uint64 RingMobGUID[MAX_MOB_AMOUNT];
    uint64 RingBossGUID;

    uint64 ChallengeMobGUID[4];

    bool ArenaChallenge;

    bool CanWalk;

    bool GroupIsWiped;

    void Reset() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

        EventPhase = 0;
        Event_Timer = 1000;

        MobCount = 0;
        MobDeath_Timer = 0;

        for (uint64 & guid : RingMobGUID)
            guid = 0;

        for (uint64 & guid : ChallengeMobGUID)
            guid = 0;

        RingBossGUID = 0;

        CanWalk = false;
        ArenaChallenge = false;
        GroupIsWiped = false;
    }

    void DoGate(uint32 id, uint32 state)
    {
        if (GameObject* pGo = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(id)))
            pGo->SetGoState(GOState(state));

        sLog.outDebug("npc_grimstone, arena gate update state.");
    }

    //TODO: move them to center
    void SummonRingMob()
    {
        // No array overflow
        if (MobCount >= MAX_MOB_AMOUNT)
            return;
        if (Creature* tmp = m_creature->SummonCreature(RingMob[MobSpawnId], 608.960f, -235.322f, -53.907f, 1.857f, TEMPSUMMON_DEAD_DESPAWN, 0))
        {
            RingMobGUID[MobCount] = tmp->GetGUID();
            tmp->GetMotionMaster()->MovePoint(1, 596.285156f, -188.698944f, -54.132176f);
            tmp->SetHomePosition(596.285156f, -188.698944f, -54.132176f, 0);
            tmp->SetInCombatWithZone();

            ++MobCount;
        }

        if (MobCount == MAX_MOB_AMOUNT)
            MobDeath_Timer = 2500;
    }

    void SummonRingBoss()
    {
        float spawnX, spawnY, spawnZ, spawnO;
        float homeX, homeY, homeZ, homeO;
        spawnX = 644.300f;
        spawnY = -175.989f;
        spawnZ = -53.739f;
        spawnO = 3.418f;

        homeX = 596.285156f;
        homeY = -188.698944f;
        homeZ = -54.132176f;
        homeO = 0;

        // T0.5 Challenge has been put down, summon Theldren and his random adds
        if (m_pInstance->GetData(DATA_THELDREN) == IN_PROGRESS)
        {
            Player *challenger = m_creature->GetMap()->GetPlayer(m_pInstance->GetData64(DATA_ARENA_CHALLENGER));
            if (!challenger)
            {
                sLog.outError("[Blackrock Depths] Ring of Law challenger player not found!");
                return;
            }

            ArenaChallenge = true;

            // Can spawn up to 5 creatures. One is guaranteed to be Theldren, a DPS warrior
            // Always have at least one 'healer', priest or shaman
            // The last three are DPS. Can both be ranged, both melee or one from each.
            // https://web.archive.org/web/20060523124717/http://wow.allakhazam.com:80/db/quest.html?wquest=9015&mid=114423967727961

            uint32 HealerEntries[2];
            uint32 DPSEntries[6];

            HealerEntries[0] = 16053;
            HealerEntries[1] = 16055;

            DPSEntries[0] = 16058;
            DPSEntries[1] = 16051;
            DPSEntries[2] = 16052;
            DPSEntries[3] = 16049;
            DPSEntries[4] = 16050;
            DPSEntries[5] = 16054;
            // Offset spawns slightly so the NPCs aren't stacked
            if (Creature *healer = m_creature->SummonCreature(HealerEntries[rand() % 2], spawnX+3, spawnY-1, spawnZ-1, spawnO, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                healer->GetMotionMaster()->MovePoint(1, spawnX, spawnY, spawnZ);
                healer->SetHomePosition(homeX, homeY, homeZ, homeO);
                healer->SetInCombatWithZone();
                ChallengeMobGUID[0] = healer->GetGUID();
                ++MobCount;
            }

            // Spawn 3 more random DPS!
            for (uint8 i = 0; i < 3; ++i)
            {
                float x, y, z;
                x = spawnX + 1.5f;
                y = spawnY - 3 + 3 * i;
                z = spawnZ;

                if (Creature *dps = m_creature->SummonCreature(DPSEntries[rand() % 6], x, y, z, spawnO, TEMPSUMMON_DEAD_DESPAWN, 0))
                {
                    dps->GetMotionMaster()->MovePoint(1, spawnX, spawnY, spawnZ);
                    dps->SetHomePosition(homeX, homeY, homeZ, homeO);
                    dps->SetInCombatWithZone();
                    ChallengeMobGUID[i + 1] = dps->GetGUID();
                    ++MobCount;
                }
            }

            // Lastly, spawn Theldren
            if (Creature *theldren = m_creature->SummonCreature(NPC_THELDREN, spawnX, spawnY, spawnZ, spawnO, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                RingBossGUID = theldren->GetGUID();
                theldren->GetMotionMaster()->MovePoint(1, spawnX, spawnY, spawnZ);
                theldren->SetHomePosition(homeX, homeY, homeZ, homeO);
                theldren->SetInCombatWithZone();
                ++MobCount;
            }
        }
        else {
            if (Creature* tmp = m_creature->SummonCreature(RingBoss[rand() % 6], spawnX, spawnY, spawnZ, spawnO, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                RingBossGUID = tmp->GetGUID();
                tmp->GetMotionMaster()->MovePoint(1, 596.285156f, -188.698944f, -54.132176f);
                tmp->SetHomePosition(homeX, homeY, homeZ, homeO);
                tmp->SetInCombatWithZone();
                ++MobCount;
            }
        }

        MobDeath_Timer = 2500;
    }

    void WaypointReached(uint32 i) override
    {
        switch (i)
        {
            case 0:
                DoScriptText(-1000011, m_creature);
                CanWalk = false;
                Event_Timer = 5000;
                break;
            case 1:
                DoScriptText(-1000012, m_creature);
                CanWalk = false;
                Event_Timer = 5000;
                break;
            case 2:
                CanWalk = false;
                break;
            case 3:
                //DoScriptText(-1000013, m_creature);//5
                break;
            case 4:
                DoScriptText(-1000015, m_creature);
                CanWalk = false;
                Event_Timer = 5000;
                break;
            case 5:
                if (m_pInstance)
                {
                    m_pInstance->SetData(TYPE_RING_OF_LAW, DONE);

                    if (m_pInstance->GetData(DATA_THELDREN) == IN_PROGRESS)
                        m_pInstance->SetData(DATA_THELDREN, DONE);
                    sLog.outDebug("npc_grimstone: event reached end and set complete.");
                }
                break;
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_pInstance)
            return;

        if (MobDeath_Timer)
        {
            if (MobDeath_Timer <= diff)
            {
                MobDeath_Timer = 2500;

                if (RingBossGUID)
                {
                    Creature *boss = m_creature->GetMap()->GetCreature(RingBossGUID);
                    if (boss && !boss->IsAlive() && boss->IsDead())
                    {
                        RingBossGUID = 0;
                        Event_Timer = 5000;
                        MobDeath_Timer = 0;
                        
                        --MobCount;
                        // End of the event if boss dies, even if some adds are left alive
                        return;
                    }

                    if (ArenaChallenge)
                    {
                        for (uint64 & guid : ChallengeMobGUID)
                        {
                            Creature *mob = m_creature->GetMap()->GetCreature(guid);
                            if (mob && !mob->IsAlive() && mob->IsDead())
                            {
                                guid = 0;
                                --MobCount;
                            }
                        }
                    }
                }
                else 
                {
                    for (uint64 & guid : RingMobGUID)
                    {
                        Creature *mob = m_creature->GetMap()->GetCreature(guid);
                        if (mob && !mob->IsAlive() && mob->IsDead())
                        {
                            guid = 0;
                            --MobCount;

                            //seems all are gone, so set timer to continue and discontinue this
                            if (!MobCount)
                            {
                                Event_Timer = 10000;
                                MobDeath_Timer = 0;
                            }
                        }
                    }
                }

                // Group wiped?
                if (CheckForWipe())
                {
                    GroupIsWiped = true;
                    return;
                }
            }
            else MobDeath_Timer -= diff;
        }

        if (Event_Timer)
        {
            if (Event_Timer <= diff)
            {
                switch (EventPhase)
                {
                    case 0:
                        DoScriptText(-1000010, m_creature);
                        DoGate(DATA_ARENA4, GO_STATE_READY);
                        Start(false);
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                    case 1:
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                    case 2:
                        Event_Timer = 2000;
                        break;
                    case 3:
                        DoGate(DATA_ARENA1, GO_STATE_ACTIVE);
                        Event_Timer = 3000;
                        break;
                    case 4:
                        CanWalk = true;
                        m_creature->SetVisibility(VISIBILITY_OFF);
                        SummonRingMob();
                        Event_Timer = 3000;
                        break;
                    case 5:
                        SummonRingMob();
                        SummonRingMob();
                        Event_Timer = 4000;
                        break;
                    case 6:
                        SummonRingMob();
                        Event_Timer = 12000;
                        break;
                    case 7:
                        MobSpawnId = urand(0, 5);
                        SummonRingMob();
                        Event_Timer = 3000;
                        break;
                    case 8:
                        SummonRingMob();
                        SummonRingMob();
                        m_creature->SetVisibility(VISIBILITY_ON);
                        DoScriptText(-1000013, m_creature);
                        Event_Timer = 4000;
                        break;
                    case 9:
                        SummonRingMob();
                        DoScriptText(-1000014, m_creature);
                        m_creature->SetVisibility(VISIBILITY_OFF);
                        Event_Timer = 0;
                        break;
                    case 10:
                        m_creature->SetVisibility(VISIBILITY_ON);
                        DoGate(DATA_ARENA1, GO_STATE_READY);
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                    case 11:
                        DoGate(DATA_ARENA2, GO_STATE_ACTIVE);
                        Event_Timer = 5000;
                        break;
                    case 12:
                        m_creature->SetVisibility(VISIBILITY_OFF);
                        SummonRingBoss();
                        Event_Timer = 0;
                        break;
                    case 13:
                        //if quest, complete
                        DoGate(DATA_ARENA2, GO_STATE_READY);
                        DoGate(DATA_ARENA3, GO_STATE_ACTIVE);
                        DoGate(DATA_ARENA4, GO_STATE_ACTIVE);
                        CanWalk = true;
                        Event_Timer = 0;
                        break;
                }
                ++EventPhase;
            }
            else Event_Timer -= diff;
        }

        if (CanWalk)
            npc_escortAI::UpdateAI(diff);
    }

    bool CheckForWipe() {
        if (GroupIsWiped)
            return true;
        // If there are no players within the vicinity of Grimstone in combat
        // and there are mobs alive, it's a wipe
        bool wiped = MobCount > 0;
        if (!wiped)
            return wiped;

        Map::PlayerList const &PlayerList = m_creature->GetMap()->GetPlayers();

        for (const auto& itr : PlayerList)
        {
            Player *player = itr.getSource();

            if (player && player->IsWithinDistInMap(m_creature, 80.0f) && player->IsInCombat()) {
                wiped = false;
                break;
            }
        }

        if (wiped)
        {
            // Players wiped, open the gates. 
            DoGate(DATA_ARENA1, GO_STATE_READY);
            DoGate(DATA_ARENA2, GO_STATE_READY);
            DoGate(DATA_ARENA4, GO_STATE_ACTIVE); // jail entrance

            // If the phase is before the boss has spawned, reset the event
            if (!RingBossGUID)
            {
                m_pInstance->SetData(TYPE_RING_OF_LAW, NOT_STARTED);

                Reset();
                m_creature->ForcedDespawn();
            }
        }
        
        return wiped;
    }

    void PlayerEnteredArena(Player *player)
    {
        // Re-enter zone after wipe, have boss. Close gates
        if (GroupIsWiped)
        {
            if (Creature *boss = m_pInstance->GetCreature(RingBossGUID))
            {
                DoGate(DATA_ARENA4, GO_STATE_READY); // jail entrance

                // Charge!
                boss->SetInCombatWith(player);
            }

            GroupIsWiped = false;
        }
    }
};

CreatureAI* GetAI_npc_grimstone(Creature* pCreature)
{
    if (!pCreature->GetInstanceData())
        return nullptr;
    return new npc_grimstoneAI(pCreature);
}

bool AreaTrigger_at_ring_of_law(Player* pPlayer, AreaTriggerEntry const *at)
{
    if (ScriptedInstance* pInstance = (ScriptedInstance*)pPlayer->GetInstanceData())
    {
        if (pInstance->GetData(TYPE_RING_OF_LAW) == IN_PROGRESS || pInstance->GetData(TYPE_RING_OF_LAW) == DONE)
        {
            // Player triggered ring of law while it's in progress. Might have been after a wipe
            if (Creature *creature = pInstance->GetCreature(pInstance->GetData64(NPC_GRIMSTONE)))
            {
                if (npc_grimstoneAI *grimstoneAI = dynamic_cast<npc_grimstoneAI *>(creature->AI()))
                    grimstoneAI->PlayerEnteredArena(pPlayer);
            }
            return false;
        }


        pInstance->SetData(TYPE_RING_OF_LAW, IN_PROGRESS);
        pPlayer->SummonCreature(NPC_GRIMSTONE, 625.559f, -205.618f, -52.735f, 2.609f, TEMPSUMMON_DEAD_DESPAWN, 0);

        return false;
    }
    return false;
}

/*######
## mob_phalanx
######*/

enum
{
    SPELL_THUNDERCLAP       = 15588,
    SPELL_FIREBALLVOLLEY    = 15285,
    SPELL_MIGHTYBLOW        = 14099,

    YELL_PHALANX_AGGRO      = -1230041
};

struct mob_phalanxAI : public ScriptedAI
{
    mob_phalanxAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        m_bActivated           = false;
        Reset();
    }
    ScriptedInstance* m_pInstance;

    uint32 ThunderClap_Timer;
    uint32 FireballVolley_Timer;
    uint32 MightyBlow_Timer;

    uint32 m_uiCallPatrolTimer;

    float m_fKeepDoorOrientation;
    bool m_bActivated;

    void Reset() override
    {
        m_fKeepDoorOrientation = 2.06059f;
        m_uiCallPatrolTimer    = 0;

        ThunderClap_Timer      = 12000;
        FireballVolley_Timer   = 0;
        MightyBlow_Timer       = 15000;
    }

    void Activate()
    { 
        if (m_bActivated)
            return;

        if (m_pInstance->GetData(TYPE_PLUGGER) == DONE || m_pInstance->GetData(TYPE_PLUGGER) == IN_PROGRESS)
        {
            m_uiCallPatrolTimer = 10000;
            m_pInstance->SetData(TYPE_PLUGGER, DONE);
        }
        DoScriptText(YELL_PHALANX_AGGRO, m_creature);
        m_creature->SetHomePosition(868.122f, -223.884f, -43.695f, m_fKeepDoorOrientation);
        m_creature->GetMotionMaster()->MovePoint(0, 865.555f, -219.056f, -43.70f);
        m_creature->SetFactionTemplateId(14);
        m_bActivated = true;
    } 

    void MovementInform(uint32 uiType, uint32 uiPointId) override
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        if (uiPointId == 0)
            m_creature->GetMotionMaster()->MovePoint(1, 868.122f, -223.884f, -43.695f, MOVE_PATHFINDING, 0, 2.06059f); 
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_pInstance)
            return;

        if (m_uiCallPatrolTimer)
        {
            if (m_uiCallPatrolTimer <= diff && m_pInstance->GetData(TYPE_PATROL) != DONE)
            {
                m_pInstance->SetData(TYPE_PATROL, IN_PROGRESS);
                m_uiCallPatrolTimer = 0;
            }
            else
                m_uiCallPatrolTimer -= diff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //ThunderClap_Timer
        if (ThunderClap_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_THUNDERCLAP);
            ThunderClap_Timer = 10000;
        }
        else ThunderClap_Timer -= diff;

        //FireballVolley_Timer
        if (m_creature->GetHealthPercent() < 51.0f)
        {
            if (FireballVolley_Timer < diff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FIREBALLVOLLEY);
                FireballVolley_Timer = 15000;
            }
            else FireballVolley_Timer -= diff;
        }

        //MightyBlow_Timer
        if (MightyBlow_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_MIGHTYBLOW);
            MightyBlow_Timer = 10000;
        }
        else MightyBlow_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_mob_phalanx(Creature* pCreature)
{
    return new mob_phalanxAI(pCreature);
}

/*######
## npc_mistress_nagmara
######*/

enum
{
    GOSSIP_ITEM_NAGMARA         = 5040,
    GOSSIP_ID_NAGMARA           = 2727,
    GOSSIP_ID_NAGMARA_2         = 2729,
    SPELL_POTION_LOVE           = 14928,
    SPELL_NAGMARA_ROCKNOT       = 15064,

    SAY_NAGMARA_1               = -1230071,
    SAY_NAGMARA_2               = -1230072,
    TEXTEMOTE_NAGMARA           = -1230073,
    TEXTEMOTE_ROCKNOT           = -1230074,

    QUEST_POTION_LOVE           = 4201
};

struct npc_mistress_nagmaraAI : public ScriptedAI
{
    npc_mistress_nagmaraAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    Creature* pRocknot;

    uint8 m_uiPhase;
    uint32 m_uiPhaseTimer;

    void Reset() override
    {
        m_uiPhase = 0;
        m_uiPhaseTimer = 0;
    }

    void DoPotionOfLoveIfCan()
    {
        if (!m_pInstance)
            return;

        pRocknot = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_ROCKNOT));
        if (!pRocknot)
            return;

        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
        m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
        pRocknot->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);

        m_creature->GetMotionMaster()->MoveIdle();
        m_creature->GetMotionMaster()->MoveFollow(pRocknot, 2.0f, 0);
        m_uiPhase = 1;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (m_uiPhaseTimer)
       {
            if (m_uiPhaseTimer <= uiDiff)
                m_uiPhaseTimer = 0;
            else
            {
                m_uiPhaseTimer -= uiDiff;
                return;
            }
        }

        if (!pRocknot)
            return;

        switch (m_uiPhase)
        {
            case 0:     // Phase 0 : Nagmara patrols in the bar to serve patrons or is following Rocknot passively
                break;
            case 1:     // Phase 1 : Nagmara is moving towards Rocknot
                if (m_creature->IsWithinDist2d(pRocknot->GetPositionX(), pRocknot->GetPositionY(), 5.0f))
                {
                    m_creature->GetMotionMaster()->MoveIdle();
                    m_creature->SetFacingToObject(pRocknot);
                    pRocknot->SetFacingToObject(m_creature);
                    DoScriptText(SAY_NAGMARA_1, m_creature);
                    m_uiPhase++;
                    m_uiPhaseTimer = 5000;
                }
                else
                    m_creature->GetMotionMaster()->MoveFollow(pRocknot, 2.0f, 0);
                break;
            case 2:     // Phase 2 : Nagmara is "seducing" Rocknot
                DoScriptText(SAY_NAGMARA_2, m_creature);
                m_uiPhaseTimer = 4000;
                m_uiPhase++;
                break;
            case 3:     // Phase 3: Nagmara give potion to Rocknot and Rocknot escort AI will handle the next part of the event
                if (DoCastSpellIfCan(m_creature, SPELL_POTION_LOVE) == CAST_OK)
                {
                    m_uiPhase = 0;
                    m_pInstance->SetData(TYPE_NAGMARA, SPECIAL);
                    m_creature->GetMotionMaster()->MoveFollow(pRocknot, 2.0f, 0);
                }
                break;
            case 4:     // Phase 4 : make the lovers face each other
                m_creature->SetFacingToObject(pRocknot);
                pRocknot->SetFacingToObject(m_creature);
                m_uiPhaseTimer = 4000;
                m_uiPhase++;
                m_pInstance->SetData(TYPE_NAGMARA, DONE);
                break;
            case 5:     // Phase 5 : Nagmara and Rocknot are under the stair kissing (this phase repeats endlessly)
                DoScriptText(TEXTEMOTE_NAGMARA, m_creature);
                DoScriptText(TEXTEMOTE_ROCKNOT, pRocknot);
                DoCastSpellIfCan(m_creature, SPELL_NAGMARA_ROCKNOT);
                pRocknot->CastSpell(pRocknot, SPELL_NAGMARA_ROCKNOT, false);
                m_uiPhaseTimer = 12000;
                break;
        }
    }
};

bool GossipHello_npc_mistress_nagmara(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->IsQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetObjectGuid());

    if (pPlayer->GetQuestRewardStatus(QUEST_POTION_LOVE))
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NAGMARA, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_NAGMARA_2, pCreature->GetObjectGuid());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_ID_NAGMARA, pCreature->GetObjectGuid());

    return true;
}

bool GossipSelect_npc_mistress_nagmara(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (npc_mistress_nagmaraAI* pNagmaraAI = dynamic_cast<npc_mistress_nagmaraAI*>(pCreature->AI()))
                pNagmaraAI->DoPotionOfLoveIfCan();
            break;
    }
    return true;
}

bool QuestRewarded_npc_mistress_nagmara(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)pCreature->GetInstanceData();

    if (!pInstance)
        return true;

    if (pQuest->GetQuestId() == QUEST_POTION_LOVE)
    {
        if (npc_mistress_nagmaraAI* pNagmaraAI = dynamic_cast<npc_mistress_nagmaraAI*>(pCreature->AI()))
            pNagmaraAI->DoPotionOfLoveIfCan();
    }

    return true;
}

CreatureAI* GetAI_npc_mistress_nagmara(Creature* pCreature)
{
    return new npc_mistress_nagmaraAI(pCreature);
}

/*######
## npc_rocknot
######*/

enum
{
    SAY_GOT_BEER       = -1230060,
    SAY_MORE_BEER      = -1230061,
    SAY_BARREL_1       = -1230062,
    SAY_BARREL_2       = -1230063,
    SAY_BARREL_3       = -1230064,

    SPELL_DRUNKEN_RAGE = 14872,

    QUEST_ALE          = 4295
};

static float const aPosNagmaraRocknot[3] = {878.1779f, -222.0662f, -49.96714f};


struct npc_rocknotAI : public npc_escortAI
{
    npc_rocknotAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;
    Creature* pNagmara;

    uint32 m_uiBreakKegTimer;
    uint32 m_uiBreakDoorTimer;
    uint32 m_uiEmoteTimer;
    uint32 m_uiBarReactTimer;

    float m_fInitialOrientation;

    void Reset() override
    {
        if (!m_pInstance)
            return;

        pNagmara = m_creature->GetMap()->GetCreature(m_pInstance->GetData64(DATA_NAGMARA));

        if (HasEscortState(STATE_ESCORT_ESCORTING))
            return;

        m_fInitialOrientation   = 3.21141f;
        m_uiBreakKegTimer       = 0;
        m_uiBreakDoorTimer      = 0;
        m_uiEmoteTimer          = 0;
        m_uiBarReactTimer       = 0;
    }

    void WaypointReached(uint32 uiPointId) override
    {
        if (!m_pInstance)
            return;

        switch (uiPointId)
        {
            case 0:     // if Nagmara and Potion of Love event is in progress, switch to second part of the escort
                SetEscortPaused(true);
                if (m_pInstance->GetData(TYPE_NAGMARA) == IN_PROGRESS)
                    setCurrentWP(9);

                SetEscortPaused(false);
                break;
            case 2:
                DoScriptText(SAY_BARREL_1, m_creature);
                break;
            case 3:
                DoScriptText(SAY_BARREL_2, m_creature);
                break;
            case 4:
                DoScriptText(SAY_BARREL_2, m_creature);
                break;
            case 5:
                DoScriptText(SAY_BARREL_1, m_creature);
                break;
            case 6:
                DoCastSpellIfCan(m_creature, SPELL_DRUNKEN_RAGE, false);
                m_uiBreakKegTimer = 2000;
                break;
            case 8:     // Back home stop here
                SetEscortPaused(true);
                m_creature->SetFacingTo(m_fInitialOrientation);
                break;
            case 9:     // This step is the start of the "alternate" waypoint path used with Nagmara
                // Make Nagmara follow Rocknot
                if (!pNagmara)
                {
                    SetEscortPaused(true);
                    setCurrentWP(8);
                }
                else
                    pNagmara->GetMotionMaster()->MoveFollow(m_creature, 2.0f, 0);
                break;
            case 16:
                // Open the bar back door if relevant
                if (GameObject* pGo = m_pInstance->GetGameObject(m_pInstance->GetData64(DATA_GO_BAR_DOOR)))
                {
                    if (pGo->GetGoState() == GO_STATE_READY) // Closed
                        pGo->SetGoState(GO_STATE_ACTIVE);
                }
                if (pNagmara)
                    pNagmara->GetMotionMaster()->MoveFollow(m_creature, 2.0f, 0);
                break;
            case 33: // Reach under the stair, make Nagmara move to her position and give the handle back to Nagmara AI script
                if (!pNagmara)
                    break;

                pNagmara->GetMotionMaster()->MoveIdle();
                pNagmara->GetMotionMaster()->MovePoint(0, aPosNagmaraRocknot[0], aPosNagmaraRocknot[1], aPosNagmaraRocknot[2]);
                if (npc_mistress_nagmaraAI* pNagmaraAI = dynamic_cast<npc_mistress_nagmaraAI*>(pNagmara->AI()))
                {
                    pNagmaraAI->m_uiPhase = 4;
                    pNagmaraAI->m_uiPhaseTimer = 5000;
                }
                SetEscortPaused(true);
                break;
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_pInstance)
            return;

        // When Nagmara is in Potion of Love event and reach Rocknot, she set TYPE_NAGMARA to SPECIAL
        // in order to make Rocknot start the second part of his escort quest
        if (m_pInstance->GetData(TYPE_NAGMARA) == SPECIAL)
        {
            m_pInstance->SetData(TYPE_NAGMARA, IN_PROGRESS);
            Start(false, ObjectGuid(), nullptr, true);
            return;
        }

        if (m_uiBreakKegTimer)
        {
            if (m_uiBreakKegTimer <= uiDiff)
            {
                if (GameObject* pGo = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(DATA_GO_BAR_KEG)))
                {
                    pGo->SetGoState(GO_STATE_ACTIVE);
                    m_uiBreakKegTimer  = 0;
                    m_uiBreakDoorTimer = 1000;
                    m_uiBarReactTimer  = 5000;
                }
            }
            else
                m_uiBreakKegTimer -= uiDiff;
        }

        if (m_uiBreakDoorTimer)
        {
            if (m_uiBreakDoorTimer <= uiDiff)
            {
                // Open the bar back door if relevant
                if (GameObject* pGo = m_pInstance->GetGameObject(m_pInstance->GetData64(DATA_GO_BAR_DOOR)))
                {
                    if (pGo->GetGoState() == GO_STATE_READY) // Closed
                    {
                        pGo->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                    }
                }

                DoScriptText(SAY_BARREL_3, m_creature);
                if (GameObject* pGo = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(DATA_GO_BAR_KEG_TRAP)))
                    pGo->SetGoState(GO_STATE_ACTIVE);                  // doesn't work very well, leaving code here for future
                // spell by trap has effect61

                m_uiBreakDoorTimer = 0;
            }
            else
                m_uiBreakDoorTimer -= uiDiff;
        }

        if (m_uiBarReactTimer)
        {
            if (m_uiBarReactTimer <= uiDiff)
            {
                // Activate Phalanx and handle nearby patrons says
                if (Unit *pPhalanx = m_creature->GetMap()->GetUnit(m_pInstance->GetData64(DATA_PHALANX)))
                {
                    if (mob_phalanxAI* pPhalanxAI = dynamic_cast<mob_phalanxAI*> (pPhalanx->AI()))
                        if (pPhalanx->IsAlive())
                            pPhalanxAI->Activate();
                }
                m_pInstance->SetData(TYPE_ROCKNOT, DONE);

                m_uiBarReactTimer = 0;
            }
            else
                m_uiBarReactTimer -= uiDiff;
        }

        // Several times Rocknot is supposed to perform an action (text, spell cast...) followed closely by an emote
        // we handle it here
        if (m_uiEmoteTimer)
        {
            if (m_uiEmoteTimer <= uiDiff)
            {
                // If event is SPECIAL (Rocknot moving to barrel), then we want him to say a special text and start moving
                // if not, he is still accepting beers, so we want him to cheer player
                if (m_pInstance->GetData(TYPE_ROCKNOT) == SPECIAL)
                {
                    DoScriptText(SAY_MORE_BEER, m_creature);
                    Start(false);
                }
                else
                    m_creature->HandleEmote(EMOTE_ONESHOT_CHEER);

                m_uiEmoteTimer = 0;
            }
            else
                m_uiEmoteTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_npc_rocknot(Creature* pCreature)
{
    return new npc_rocknotAI(pCreature);
}

bool QuestRewarded_npc_rocknot(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)pCreature->GetInstanceData());

    if (!pInstance)
        return true;

    if (pInstance->GetData(TYPE_ROCKNOT) == DONE || pInstance->GetData(TYPE_ROCKNOT) == SPECIAL)
        return true;

    if (pQuest->GetQuestId() == QUEST_ALE)
    {
        if (pInstance->GetData(TYPE_ROCKNOT) != IN_PROGRESS)
            pInstance->SetData(TYPE_ROCKNOT, IN_PROGRESS);

        pCreature->SetFacingToObject(pPlayer);
        DoScriptText(SAY_GOT_BEER, pCreature);
        if (npc_rocknotAI* pEscortAI = dynamic_cast<npc_rocknotAI*>(pCreature->AI()))
            pEscortAI->m_uiEmoteTimer = 1500;

        // We keep track of amount of beers given in the instance script by setting data to SPECIAL
        // Once the correct amount is reached, the script will also returns SPECIAL, if not, it returns IN_PROGRESS/DONE
        // the return state and the following of the script are handled in the Update->emote part of the Rocknot NPC escort AI script
        pInstance->SetData(TYPE_ROCKNOT, SPECIAL);
    }

    return true;
}

/*######
## go_dark_keeper_portrait
######*/

enum
{
    NPC_DARK_KEEPER_VORFALK    = 9437,
    NPC_DARK_KEEPER_BETHEK     = 9438,
    NPC_DARK_KEEPER_UGGEL      = 9439,
    NPC_DARK_KEEPER_ZIMREL     = 9441,
    NPC_DARK_KEEPER_OFGUT      = 9442,
    NPC_DARK_KEEPER_PELVER     = 9443,

    GO_VORFALK                 = 164820,
    GO_BETHEK                  = 164821,
    GO_UGGEL                   = 164822,
    GO_ZIMREL                  = 164823,
    GO_OFGUT                   = 164824,
    GO_PELVER                  = 164825,
};

bool GOHello_go_dark_keeper_portrait(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)pGo->GetInstanceData());

    if (!pInstance)
        return true;

    if (pInstance->GetData(TYPE_VAULT) != DONE)
    {
        switch (urand(0, 5))
        {
            case 0:
                pPlayer->SummonCreature(NPC_DARK_KEEPER_VORFALK, 815.60f, -168.54f, -49.75f, 5.97f, TEMPSUMMON_DEAD_DESPAWN, 0);
                pPlayer->SummonGameObject(GO_VORFALK, 831.54f, -339.529f, -46.682f, 0.802851f, 0, 0, 0, 0, 0);
                pInstance->SetData(TYPE_VAULT, DONE);
                break;
            case 1:
                pPlayer->SummonCreature(NPC_DARK_KEEPER_BETHEK, 846.66f, -317.18f, -50.29f, 3.90f, TEMPSUMMON_DEAD_DESPAWN, 0);
                pPlayer->SummonGameObject(GO_BETHEK, 831.54f, -339.529f, -46.682f, 0.802851f, 0, 0, 0, 0, 0);
                pInstance->SetData(TYPE_VAULT, DONE);
                break;
            case 2:
                pPlayer->SummonCreature(NPC_DARK_KEEPER_UGGEL, 963.27f, -343.73f, -71.74f, 2.22f, TEMPSUMMON_DEAD_DESPAWN, 0);
                pPlayer->SummonGameObject(GO_UGGEL, 831.54f, -339.529f, -46.682f, 0.802851f, 0, 0, 0, 0, 0);
                pInstance->SetData(TYPE_VAULT, DONE);
                break;
            case 3:
                pPlayer->SummonCreature(NPC_DARK_KEEPER_ZIMREL, 545.49f, -162.49f, -35.46f, 5.86f, TEMPSUMMON_DEAD_DESPAWN, 0);
                pPlayer->SummonGameObject(GO_ZIMREL, 831.54f, -339.529f, -46.682f, 0.802851f, 0, 0, 0, 0, 0);
                pInstance->SetData(TYPE_VAULT, DONE);
                break;
            case 4:
                pPlayer->SummonCreature(NPC_DARK_KEEPER_OFGUT, 681.52f, -11.55f, -60.06f, 1.98f, TEMPSUMMON_DEAD_DESPAWN, 0);
                pPlayer->SummonGameObject(GO_OFGUT, 831.54f, -339.529f, -46.682f, 0.802851f, 0, 0, 0, 0, 0);
                pInstance->SetData(TYPE_VAULT, DONE);
                break;
            case 5:
                pPlayer->SummonCreature(NPC_DARK_KEEPER_PELVER, 803.64f, -248.00f, -43.30f, 2.60f, TEMPSUMMON_DEAD_DESPAWN, 0);
                pPlayer->SummonGameObject(GO_PELVER, 831.54f, -339.529f, -46.682f, 0.802851f, 0, 0, 0, 0, 0);
                pInstance->SetData(TYPE_VAULT, DONE);
                break;
        }
    }
    return false;
}

/*######
## go_thunderbrew_laguer_keg
######*/

enum
{
    NPC_HURLEY             = 9537,
    NPC_HURLEY_CRONY       = 9541,
};

bool GOHello_go_thunderbrew_laguer_keg(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)pGo->GetInstanceData());

    if (!pInstance)
        return true;

    if (pInstance->GetData(TYPE_THUNDERBREW) == DONE)
        return false;

    if (pInstance->GetData(TYPE_THUNDERBREW) == NOT_STARTED)
        pInstance->SetData(TYPE_THUNDERBREW, IN_PROGRESS);

    if (pInstance->GetData(TYPE_THUNDERBREW) == DONE)
    {
        // Summon Hurley Blackbreath
        Creature* pHurley = pPlayer->SummonCreature(NPC_HURLEY,
                             856.087f, -149.747f, -49.672f, 0.059f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 300000);
        if (!pHurley)
            return true;

        pHurley->SetWalk(false);
        pHurley->GetMotionMaster()->Clear(false, true);
        pHurley->GetMotionMaster()->MoveWaypoint(0, 0, 1000, 0, 0, false);

        // Summon cronies around Hurley
        for (uint8 i = 0; i < 4; ++i)
        {
            float fX, fY, fZ;
            pPlayer->GetRandomPoint(856.087f, -149.747f, -49.672f, 2.0f, fX, fY, fZ);
            if (Creature* pSummoned = pPlayer->SummonCreature(NPC_HURLEY_CRONY, fX, fY, fZ, 0.059f, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                pSummoned->JoinCreatureGroup(pHurley, 3.0, i * (M_PI_F / 2.0f), OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER | OPTION_EVADE_TOGETHER);
            }
        }
    }

    return false;
}

/*######
## go_relic_coffer_door
######*/

enum
{
    RUINEPOIGNE_ENTRY    = 9476,
};

bool GOHello_go_relic_coffer_door(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = ((ScriptedInstance*)pGo->GetInstanceData());

    if (!pInstance)
        return true;

    if (pInstance->GetData(TYPE_RELIC_COFFER) != IN_PROGRESS || pInstance->GetData(TYPE_RELIC_COFFER) != DONE)
        pInstance->SetData(TYPE_RELIC_COFFER, IN_PROGRESS);

    pInstance->SetData(TYPE_RELIC_COFFER, SPECIAL);

    if (pInstance->GetData(TYPE_RELIC_COFFER) == DONE)
    {
        if (Creature* pCreature = pPlayer->SummonCreature(RUINEPOIGNE_ENTRY,
            819.45f, -348.96f, -50.49f, 0.35f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 300000))
        {
            // pCreature->MonsterYell("Ne les laissez pas s'emparer du Coeur de la montagne!!", 0, pPlayer);
            pCreature->MonsterYell("Don't let them take the moutain hearth!", 0, pPlayer);
            // pCreature->MonsterYell(NOST_TEXT(153), 0, pPlayer); // seems to be custom
            pCreature->AI()->AttackStart(pPlayer);
        }

    }

    return false;
}

/*######
## npc_watchman_doomgrip
######*/

#define SPELL_BOIRE_LA_POTION_DE_SOINS    15504
#define SPELL_FRACASSER_ARMURE    11971
#define NPC_WARBRINGER_CONSTRUCT    8905

struct npc_watchman_doomgripAI : public ScriptedAI
{
    npc_watchman_doomgripAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 BoireLaPotionDeSoins_Timer;
    uint32 FracasserArmure_Timer;

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(TYPE_DOOMGRIP, DONE);
    }

    void Reset() override
    {
        BoireLaPotionDeSoins_Timer = 0;
        FracasserArmure_Timer = 1000;
    }

    void Aggro(Unit* pWho) override
    {
        std::list<Creature*> lGolems;
        GetCreatureListWithEntryInGrid(lGolems, m_creature, NPC_WARBRINGER_CONSTRUCT, 20.0f);
        if (!lGolems.empty())
        {
            for (const auto& pGolem : lGolems)
            {
                if (pGolem->IsAlive())
                {
                    pGolem->RemoveAurasDueToSpell(10255);
                    pGolem->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_IMMUNE_TO_NPC);
                    if (pWho)
                        pGolem->AI()->AttackStart(pWho);
                }
            }
        }
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //BoireLaPotionDeSoins_Timer
        if (m_creature->GetHealthPercent() < 51.0f)
        {
            if (BoireLaPotionDeSoins_Timer < diff)
            {
                DoCastSpellIfCan(m_creature->GetVictim(), SPELL_BOIRE_LA_POTION_DE_SOINS);
                BoireLaPotionDeSoins_Timer = 15000;
            }
            else BoireLaPotionDeSoins_Timer -= diff;
        }

        //FracasserArmure_Timer
        if (FracasserArmure_Timer < diff)
        {
            DoCastSpellIfCan(m_creature->GetVictim(), SPELL_FRACASSER_ARMURE);
            FracasserArmure_Timer = 10000;
        }
        else FracasserArmure_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_watchman_doomgrip(Creature* pCreature)
{
    return new npc_watchman_doomgripAI(pCreature);
}

/*######
## npc_golem_lord_argelmach
######*/

#define SPELL_BOUCLIER_DE_FOUDRE    15507
#define SPELL_CHAINE_D_ECLAIRES    15305
#define SPELL_HORION    15605

struct npc_golem_lord_argelmachAI : public ScriptedAI
{
    npc_golem_lord_argelmachAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 BouclierDeFoudre_Timer;
    uint32 ChaineDEclaires_Timer;
    uint32 Horion_Timer;

    void Aggro(Unit* pWho) override
    {
        m_creature->GetMotionMaster()->MovePoint(0, 846.801025f, 16.280600f, -53.639500f);
        //m_creature->MonsterYell("Golems, votre Seigneur a besoin de vous!", 0, pWho);
        //m_creature->MonsterYell(NOST_TEXT(155), 0, pWho); // seems to be custom

        if (m_pInstance)
            m_pInstance->SetData(DATA_ARGELMACH_AGGRO, IN_PROGRESS);
    }

    void JustDied(Unit* pKiller) override
    {
        if (m_pInstance)
            m_pInstance->SetData(DATA_ARGELMACH_AGGRO, DONE);
    }

    void Reset() override
    {
        BouclierDeFoudre_Timer = 0;
        ChaineDEclaires_Timer = 5000;
        Horion_Timer = 2000;
    }

    void UpdateAI(uint32 const diff) override
    {
        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        //BouclierDeFoudre_Timer
        if (BouclierDeFoudre_Timer < diff)
        {
            if (!m_creature->HasAura(SPELL_BOUCLIER_DE_FOUDRE))
                if (DoCastSpellIfCan(m_creature, SPELL_BOUCLIER_DE_FOUDRE) == CAST_OK)
                    BouclierDeFoudre_Timer = 15000;
        }
        else BouclierDeFoudre_Timer -= diff;

        //ChaineDEclaires_Timer
        if (ChaineDEclaires_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_CHAINE_D_ECLAIRES) == CAST_OK)
                ChaineDEclaires_Timer = 14000;
        }
        else ChaineDEclaires_Timer -= diff;

        //Horion_Timer
        if (Horion_Timer < diff)
        {
            if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_HORION) == CAST_OK)
                Horion_Timer = 6000;
        }
        else Horion_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_golem_lord_argelmach(Creature* pCreature)
{
    return new npc_golem_lord_argelmachAI(pCreature);
}

/*######
## at_shadowforge_bridge
######*/

static float const aGuardSpawnPositions[2][4] =
{
    {642.3660f, -274.5155f, -43.10918f, 0.4712389f},                // First guard spawn position
    {740.1137f, -283.3448f, -42.75082f, 2.8623400f}                 // Second guard spawn position
};

enum
{
    NPC_ANVILRAGE_GUARDMAN             = 8891,
    SAY_GUARD_AGGRO                    = -1230043
};

// When players cross the shadowforge bridge for the first time, two guards spawn and attack.
bool AreaTrigger_at_shadowforge_bridge(Player* pPlayer, AreaTriggerEntry const* pAt)
{
    if (ScriptedInstance* pInstance = (ScriptedInstance*)pPlayer->GetInstanceData())
    {
        if (pPlayer->IsGameMaster() || !pPlayer->IsAlive() || pInstance->GetData(TYPE_BRIDGE) == DONE)
            return false;

        if (Creature* pMasterGuard = pPlayer->SummonCreature(NPC_ANVILRAGE_GUARDMAN, aGuardSpawnPositions[0][0], aGuardSpawnPositions[0][1], aGuardSpawnPositions[0][2], aGuardSpawnPositions[0][3], TEMPSUMMON_DEAD_DESPAWN, 0))
        {
            pMasterGuard->SetWalk(false);
            pMasterGuard->GetMotionMaster()->MoveWaypoint();
            DoScriptText(SAY_GUARD_AGGRO, pMasterGuard);
            float fX, fY, fZ;
            pPlayer->GetContactPoint(pMasterGuard, fX, fY, fZ);
            pMasterGuard->GetMotionMaster()->MovePoint(1,fX, fY, fZ);

            if (Creature* pSlaveGuard = pPlayer->SummonCreature(NPC_ANVILRAGE_GUARDMAN, aGuardSpawnPositions[1][0], aGuardSpawnPositions[1][1], aGuardSpawnPositions[1][2], aGuardSpawnPositions[1][3], TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                pSlaveGuard->GetMotionMaster()->MoveFollow(pMasterGuard, 2.0f, 0);
            }
        }
        pInstance->SetData(TYPE_BRIDGE, DONE);
    }
    return false;
}


/*######
## boss_plugger_spazzring
######*/

enum
{
    SAY_OOC_1                       = -1230065,
    SAY_OOC_2                       = -1230066,
    SAY_OOC_3                       = -1230067,
    SAY_OOC_4                       = -1230068,

    YELL_STOLEN_1                   = -1230054,
    YELL_STOLEN_2                   = -1230055,
    YELL_STOLEN_3                   = -1230056,
    
    YELL_AGRRO_1                    = -1230057,
    YELL_AGRRO_2                    = -1230058,
    YELL_PICKPOCKETED               = -1230059,

    // spells
    SPELL_BANISH                    = 8994,
    SPELL_CURSE_OF_TONGUES          = 13338,
    SPELL_DEMON_ARMOR               = 13787,
    SPELL_IMMOLATE                  = 12742,
    SPELL_SHADOW_BOLT               = 12739,
    SPELL_PICKPOCKET                = 921,
};

static int const aRandomSays[] = { SAY_OOC_1, SAY_OOC_2, SAY_OOC_3, SAY_OOC_4 };

static int const aRandomYells[] = { YELL_STOLEN_1, YELL_STOLEN_2, YELL_STOLEN_3 };

struct boss_plugger_spazzringAI : public ScriptedAI
{

    boss_plugger_spazzringAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        m_pInstance = (ScriptedInstance*)pCreature->GetInstanceData();
        Reset();
    }

    ScriptedInstance* m_pInstance;

    uint32 m_uiOocSayTimer;
    uint32 m_uiDemonArmorTimer;
    uint32 m_uiBanishTimer;
    uint32 m_uiImmolateTimer;
    uint32 m_uiShadowBoltTimer;
    uint32 m_uiCurseOfTonguesTimer;
    uint32 m_uiPickpocketTimer;

    void Reset() override
    {
        m_uiOocSayTimer          = 10000;
        m_uiDemonArmorTimer      = 1000;
        m_uiBanishTimer          = 0;
        m_uiImmolateTimer        = 0;
        m_uiShadowBoltTimer      = 0;
        m_uiCurseOfTonguesTimer  = 0;
        m_uiPickpocketTimer      = 0;
    }

    void Aggro(Unit* /*pWho*/) override
    {
        m_uiBanishTimer          = urand(9000, 15000);
        m_uiImmolateTimer        = urand(5000, 8000);
        m_uiShadowBoltTimer      = 1000;
        m_uiCurseOfTonguesTimer  = 14000;
    }

    void JustDied(Unit* pKiller) override
    {
        if (!m_pInstance)
            return;

        // Activate Phalanx and handle patrons faction
        m_pInstance->SetData(TYPE_PLUGGER, IN_PROGRESS); // The event is set IN_PROGRESS even if Plugger is dead because his death triggers more actions that are part of the event
        m_pInstance->SetData(EVENT_BAR_PATRONS, PATRON_HOSTILE);
        if (Unit *pPhalanx = m_creature->GetMap()->GetUnit(m_pInstance->GetData64(DATA_PHALANX)))
        {
            if (mob_phalanxAI* pPhalanxAI = dynamic_cast<mob_phalanxAI*> (pPhalanx->AI()))
                if (pPhalanx->IsAlive())
                    pPhalanxAI->Activate();
        }
    }

    void SpellHit(Unit* pCaster, SpellEntry const* pSpell) override
    {
        if (pCaster->GetTypeId() == TYPEID_PLAYER)
        {
            if (pSpell->Id == SPELL_PICKPOCKET)
                m_uiPickpocketTimer = 5000;
        }
    }

    // Players stole one of the ale mug/roasted boar: warn them
    void WarnThief(Player* pPlayer)
    {
        DoScriptText(aRandomYells[urand(0, 2)], m_creature);
        m_creature->SetFacingToObject(pPlayer);
    }

    // Players stole too much of the ale mug/roasted boar: attack them
    void AttackThief(Player* pPlayer)
    {
        if (pPlayer)
        {
            DoScriptText(urand(0, 1) < 1 ? YELL_AGRRO_1 : YELL_AGRRO_2, m_creature);
            m_creature->SetFacingToObject(pPlayer);
            m_creature->SetFactionTemporary(FACTION_DARK_IRON, TEMPFACTION_RESTORE_RESPAWN);
            AttackStart(pPlayer);
        }
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        // Combat check
        if (m_creature->SelectHostileTarget() && m_creature->GetVictim())
        {
            if (m_uiBanishTimer < uiDiff)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 1))
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_BANISH) == CAST_OK)
                        m_uiBanishTimer = urand(26, 28) * 1000;
                }
            }
            else
                m_uiBanishTimer -= uiDiff;

            if (m_uiImmolateTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_IMMOLATE) == CAST_OK)
                    m_uiImmolateTimer = 25000;
            }
            else
                m_uiImmolateTimer -= uiDiff;

            if (m_uiShadowBoltTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature->GetVictim(), SPELL_SHADOW_BOLT) == CAST_OK)
                    m_uiShadowBoltTimer = urand(36, 63) * 100;
            }
            else
                m_uiShadowBoltTimer -= uiDiff;

            if (m_uiCurseOfTonguesTimer < uiDiff)
            {
                if (Unit* pTarget = m_creature->SelectAttackingTarget(ATTACKING_TARGET_RANDOM, 0, SPELL_CURSE_OF_TONGUES, SELECT_FLAG_POWER_MANA))
                {
                    if (DoCastSpellIfCan(pTarget, SPELL_CURSE_OF_TONGUES) == CAST_OK)
                        m_uiCurseOfTonguesTimer = urand(19, 31) * 1000;
                }
            }
            else
                m_uiCurseOfTonguesTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
        // Out of Combat (OOC)
        else
        {
            if (m_uiOocSayTimer)
            {
                if (m_uiOocSayTimer <= uiDiff)
                {
                    DoScriptText(aRandomSays[urand(0, 3)], m_creature);
                    m_uiOocSayTimer = urand(30000, 35000);
                }
                else
                    m_uiOocSayTimer -= uiDiff;
            }

            if (m_uiPickpocketTimer)
            {
                if (m_uiPickpocketTimer <= uiDiff)
                {
                    DoScriptText(YELL_PICKPOCKETED, m_creature);
                    m_creature->SetFactionTemporary(FACTION_DARK_IRON, TEMPFACTION_RESTORE_RESPAWN);
                    m_uiPickpocketTimer = 0;
                    m_uiOocSayTimer = 0;
                }
                else
                    m_uiPickpocketTimer -= uiDiff;
            }

            if (m_uiDemonArmorTimer < uiDiff)
            {
                if (DoCastSpellIfCan(m_creature, SPELL_DEMON_ARMOR) == CAST_OK)
                    m_uiDemonArmorTimer = 5*MINUTE*IN_MILLISECONDS;
            }
            else
                m_uiDemonArmorTimer -= uiDiff;
        }
    }
};

CreatureAI* GetAI_boss_plugger_spazzring(Creature* pCreature)
{
    return new boss_plugger_spazzringAI(pCreature);
}

/*######
## go_bar_ale_mug
######*/

bool GOUse_go_bar_ale_mug(Player* pPlayer, GameObject* pGo)
{
    if (ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData())
    {
        if (pInstance->GetData(TYPE_PLUGGER) == IN_PROGRESS || pInstance->GetData(TYPE_PLUGGER) == DONE) // GOs despawning on use, this check should never be true but this is proper to have it there
            return false;
        else
        {
            if (Creature* pPlugger = pInstance->GetCreature(pInstance->GetData64(DATA_PLUGGER)))
            {
                if (boss_plugger_spazzringAI* pPluggerAI = dynamic_cast<boss_plugger_spazzringAI*>(pPlugger->AI()))
                {
                    // Every time we set the event to SPECIAL, the instance script increments the number of stolen mugs/boars, capping at 3
                    pInstance->SetData(TYPE_PLUGGER, SPECIAL);
                    // If the cap is reached the instance script changes the type from SPECIAL to IN_PROGRESS
                    // Plugger then aggroes and engage players, else he just warns them
                    if (pInstance->GetData(TYPE_PLUGGER) == IN_PROGRESS)
                        pPluggerAI->AttackThief(pPlayer);
                    else
                        pPluggerAI->WarnThief(pPlayer);
                }
            }
        }
    }
    return false;
}


/*######
## quest_jail_break
######*/

enum
{
    SAY_DUGHAL_FREE             = -1230010,
    SAY_WINDSOR_AGGRO1          = -1230011,
    SAY_WINDSOR_AGGRO2          = -1230012,
    SAY_WINDSOR_AGGRO3          = -1230013,
    SAY_WINDSOR_1               = -1230014,
    SAY_WINDSOR_4_1             = -1230015,
    SAY_WINDSOR_4_2             = -1230016,
    SAY_WINDSOR_4_3             = -1230017,
    SAY_WINDSOR_6               = -1230018,
    SAY_WINDSOR_9               = -1230019,

    SAY_REGINALD_WINDSOR_0_1    = -1230020,
    SAY_REGINALD_WINDSOR_0_2    = -1230021,
    SAY_REGINALD_WINDSOR_5_1    = -1230022,
    SAY_REGINALD_WINDSOR_5_2    = -1230023,
    SAY_REGINALD_WINDSOR_5_3    = -1230040,
    SAY_REGINALD_WINDSOR_7_1    = -1230024,
    SAY_REGINALD_WINDSOR_7_2    = -1230025,
    SAY_REGINALD_WINDSOR_7_3    = -1230026,
    SAY_REGINALD_WINDSOR_7_4    = -1230037,
    SAY_REGINALD_WINDSOR_13_1   = -1230027,
    SAY_REGINALD_WINDSOR_13_2   = -1230028,
    SAY_REGINALD_WINDSOR_13_3   = -1230029,
    SAY_REGINALD_WINDSOR_14_1   = -1230030,
    SAY_REGINALD_WINDSOR_14_2   = -1230031,
    SAY_REGINALD_WINDSOR_20_1   = -1230032,
    SAY_REGINALD_WINDSOR_20_2   = -1230033,

    SAY_TOBIAS_FREE_1           = -1230034,
    SAY_TOBIAS_FREE_2           = -1230039,

    SAY_SHILL_DINGER            = -1230035,
    SAY_CREST_KILLER            = -1230036,
    SAY_OGRABISI                = -1230038,

    NPC_REGINALD_WINDSOR        = 9682,
    NPC_DUGHAL                  = 9022,
    NPC_TOBIAS                  = 9679,

    SPELL_WINDSORS_FRENZY       = 15167
};

struct npc_dughal_stormwingAI : npc_escortAI
{
    explicit npc_dughal_stormwingAI(Creature* m_creature) : npc_escortAI(m_creature)
    {
        m_pInstance = static_cast<ScriptedInstance*>(m_creature->GetInstanceData());
        npc_dughal_stormwingAI::Reset();
    }

    ScriptedInstance* m_pInstance;

    void Reset() override {}

    void WaypointReached(uint32 uiPointId) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS)
            return;

        switch (uiPointId)
        {
            case 0:
                if (Player* pTemp = GetPlayerForEscort())
                    DoScriptText(SAY_DUGHAL_FREE, m_creature, pTemp);
                break;
            case 1:
                m_pInstance->SetData(TYPE_JAIL_DUGHAL, IN_PROGRESS);
                break;
            case 2:
                m_pInstance->SetData(TYPE_JAIL_DUGHAL, DONE);
                break;
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS)
            return;

        if (m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) == FAIL || 
            m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) == DONE || 
            m_pInstance->GetData(TYPE_JAIL_DUGHAL) == DONE)
        {
            m_creature->SetVisibility(VISIBILITY_OFF);            
        }
        else
             m_creature->SetVisibility(VISIBILITY_ON);

        npc_escortAI::UpdateEscortAI(uiDiff);
    }

    void OnScriptEventHappened(uint32 uiEvent, uint32 uiData, WorldObject* pInvoker) override
    {
        if (pInvoker && pInvoker->IsPlayer())
        {
            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            Start(true, pInvoker->GetObjectGuid());
        }
    }
};

CreatureAI* GetAI_npc_dughal_stormwing(Creature* pCreature)
{
    return new npc_dughal_stormwingAI(pCreature);
}

// npc_marshal_reginald_windsor
struct npc_marshal_reginald_windsorAI : npc_escortAI
{
    explicit npc_marshal_reginald_windsorAI(Creature* m_creature) : npc_escortAI(m_creature)
    {
        m_pInstance = static_cast<ScriptedInstance*>(m_creature->GetInstanceData());
        npc_marshal_reginald_windsorAI::Reset();        
    }

    ScriptedInstance* m_pInstance;
    uint32 m_uiWP;
    bool m_bEncounterStarted;

    void Reset() override
    {
        if (!HasEscortState(STATE_ESCORT_PAUSED))
            m_uiWP = 0;
        m_bEncounterStarted = false;
    }

    void DoJailBreakQuestCredit() const
    {
        if (Player* pPlayer = GetPlayerForEscort())
            pPlayer->GroupEventHappens(QUEST_JAIL_BREAK, m_creature);
    }

    void WaypointReached(uint32 uiPointId) override
    {
        Player* pPlayer = GetPlayerForEscort();
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS || !pPlayer)
            return;

        m_uiWP = uiPointId;
        switch (uiPointId)
        {
            case 0:
                DoScriptText(SAY_REGINALD_WINDSOR_0_1, m_creature, pPlayer);
                m_creature->SetFacingToObject(pPlayer);
                break;
            case 1:
                DoScriptText(SAY_REGINALD_WINDSOR_0_2, m_creature);
                m_creature->SetFacingToObject(pPlayer);
                break;
            case 7:
                if (!m_pInstance->GetData(GO_JAIL_DOOR_JAZ))
                {
                    m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
                    DoScriptText(SAY_REGINALD_WINDSOR_5_1, m_creature);
                }
                SetEscortPaused(true);
                break;
            case 8:
                DoScriptText(SAY_REGINALD_WINDSOR_5_2, m_creature);
                break;
            case 11:
                if (!m_pInstance->GetData(GO_JAIL_DOOR_SHILL))
                {
                    m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
                    DoScriptText(SAY_REGINALD_WINDSOR_7_1, m_creature);
                }
                SetEscortPaused(true);
                break;
            case 12:
                DoScriptText(SAY_REGINALD_WINDSOR_7_2, m_creature);
                break;
            case 13:
                DoScriptText(SAY_REGINALD_WINDSOR_7_3, m_creature);
                break;
            case 20:
                if (!m_pInstance->GetData(GO_JAIL_DOOR_CREST))
                {
                    m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
                    DoScriptText(SAY_REGINALD_WINDSOR_13_1, m_creature);
                }
                SetEscortPaused(true);
                break;
            case 21:
                DoScriptText(SAY_REGINALD_WINDSOR_13_3, m_creature);
                break;
            case 23:
                {
                    if (!m_pInstance->GetData(GO_JAIL_DOOR_TOBIAS))
                    {
                        m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
                        DoScriptText(SAY_REGINALD_WINDSOR_14_1, m_creature);
                    }

                    if (Creature* pTobias = m_creature->FindNearestCreature(NPC_TOBIAS, 200.0f))
                        pTobias->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                    SetEscortPaused(true);                    
                }
                break;
            case 24:
                DoScriptText(SAY_REGINALD_WINDSOR_14_2, m_creature, pPlayer);
                break;
            case 31:
                DoScriptText(SAY_REGINALD_WINDSOR_20_1, m_creature);
                break;
            case 32:
                DoScriptText(SAY_REGINALD_WINDSOR_20_2, m_creature);
                
                DoJailBreakQuestCredit();
                
                m_pInstance->SetData(TYPE_QUEST_JAIL_BREAK, DONE);
                break;
        }
    }

    void EnterCombat(Unit* pWho) override
    {
        m_creature->CastSpell(m_creature, SPELL_WINDSORS_FRENZY, true);

        switch (pWho->GetEntry())
        {
            case NPC_OGRABISI:
            case NPC_JAZ:
                DoScriptText(SAY_REGINALD_WINDSOR_5_3, m_creature); break;
            case NPC_CREST: 
                DoScriptText(SAY_REGINALD_WINDSOR_13_2, m_creature); break;
            case NPC_SHILL: 
                DoScriptText(SAY_REGINALD_WINDSOR_7_4, m_creature); break;
        }

        npc_escortAI::EnterCombat(pWho);
    }

    void EnterEvadeMode() override
    {
        m_creature->RemoveAurasDueToSpell(SPELL_WINDSORS_FRENZY);
        npc_escortAI::EnterEvadeMode();
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (Player* pPlayer = GetPlayerForEscort())
            pPlayer->GroupEventFailHappens(QUEST_JAIL_BREAK);
        
        m_pInstance->SetData(TYPE_QUEST_JAIL_BREAK, FAIL);
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS)
            return;

        switch (m_uiWP)
        {
            case 7:
            {
                Creature* pJaz = m_pInstance->instance->GetCreature(m_pInstance->GetData64(NPC_JAZ));
                Creature* pOgrabisi = m_pInstance->instance->GetCreature(m_pInstance->GetData64(NPC_OGRABISI));
                if (pJaz && pOgrabisi && pJaz->IsAlive() && pOgrabisi->IsAlive() && m_pInstance->GetData(GO_JAIL_DOOR_JAZ) && !m_bEncounterStarted)
                {
                    pJaz->SetFactionTemplateId(54);
                    pJaz->AI()->AttackStart(m_creature);
                    pOgrabisi->SetFactionTemplateId(54);
                    pOgrabisi->AI()->AttackStart(m_creature);
                    m_pInstance->SetData(GO_JAIL_DOOR_JAZ, false);
                    DoScriptText(SAY_OGRABISI, pOgrabisi);
                    m_bEncounterStarted = true;
                }
                if (pJaz && pOgrabisi && pJaz->IsDead() && pOgrabisi->IsDead())
                {
                    SetEscortPaused(false);
                    m_bEncounterStarted = false;
                }
                break;
            }
            case 11:
            {
                Creature* pShill = m_pInstance->instance->GetCreature(m_pInstance->GetData64(NPC_SHILL));
                if (pShill && pShill->IsAlive() && m_pInstance->GetData(GO_JAIL_DOOR_SHILL) && !m_bEncounterStarted)
                {
                    pShill->SetFactionTemplateId(54);
                    pShill->AI()->AttackStart(m_creature);
                    m_pInstance->SetData(GO_JAIL_DOOR_SHILL, false);
                    DoScriptText(SAY_SHILL_DINGER, pShill);
                    m_bEncounterStarted = true;
                }
                if (pShill && pShill->IsDead())
                {
                    SetEscortPaused(false);
                    m_bEncounterStarted = false;
                }
                break;
            }
            case 20:
            {
                Creature* pCrest = m_pInstance->instance->GetCreature(m_pInstance->GetData64(NPC_CREST));
                if (pCrest && pCrest->IsAlive() && m_pInstance->GetData(GO_JAIL_DOOR_CREST) && !m_bEncounterStarted)
                {
                    pCrest->SetFactionTemplateId(54);
                    pCrest->AI()->AttackStart(m_creature);
                    m_pInstance->SetData(GO_JAIL_DOOR_CREST, false);
                    m_bEncounterStarted = true;
                }
                if (pCrest && pCrest->IsDead())
                {
                    SetEscortPaused(false);
                    m_bEncounterStarted = false;
                }
                break;
            }
        }

        if (m_pInstance->GetData(TYPE_JAIL_TOBIAS) == IN_PROGRESS) 
            SetEscortPaused(false);

        npc_escortAI::UpdateEscortAI(uiDiff);
    }
};

CreatureAI* GetAI_npc_marshal_reginald_windsor(Creature* pCreature)
{
    return new npc_marshal_reginald_windsorAI(pCreature);
}

// npc_marshal_windsor
struct npc_marshal_windsorAI : npc_escortAI
{
    explicit npc_marshal_windsorAI(Creature* m_creature) : npc_escortAI(m_creature)
    {
        m_pInstance = static_cast<ScriptedInstance*>(m_creature->GetInstanceData());
        npc_marshal_windsorAI::Reset();
    }

    ScriptedInstance* m_pInstance;
    uint32 m_uiWP;
    bool m_uiSaidJustOnce;

    void Reset() override
    {
        if (!HasEscortState(STATE_ESCORT_PAUSED))
            m_uiWP = 0;
        m_uiSaidJustOnce = false;
    }

    void WaypointReached(uint32 uiPointId) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS)
            return;

        m_uiWP = uiPointId;
        switch (uiPointId)
        {
            case 1:
                DoScriptText(SAY_WINDSOR_1, m_creature);
                break;
            case 7:
                if (!m_pInstance->GetData(GO_JAIL_DOOR_DUGHAL))
                {
                    if (Player* pTemp = GetPlayerForEscort())
                        DoScriptText(SAY_WINDSOR_4_1, m_creature, pTemp);
                    m_creature->HandleEmoteCommand(EMOTE_STATE_POINT);
                }

                if (Creature* pDughal = m_creature->FindNearestCreature(NPC_DUGHAL, 200.0f))
                    pDughal->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                SetEscortPaused(true);
                break;
            case 12:
                if (Player* pTemp = GetPlayerForEscort())
                    DoScriptText(SAY_WINDSOR_6, m_creature, pTemp);
                m_pInstance->SetData(TYPE_JAIL_SUPPLY_ROOM, IN_PROGRESS);
                break;
            case 13:
                if (!m_pInstance->GetData(GO_JAIL_DOOR_SUPPLY))
                    m_creature->HandleEmoteCommand(EMOTE_STATE_USESTANDING);
                break;
            case 14:
                if (!m_pInstance->GetData(GO_JAIL_DOOR_SUPPLY))
                    m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_JAIL_DOOR_SUPPLY));
                break;
            case 16:
                DoScriptText(SAY_WINDSOR_9, m_creature);
                break;
            case 17:
                m_creature->HandleEmoteCommand(EMOTE_STATE_USESTANDING);
                break;
            case 18:
                if (GameObject* pGo = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(GO_JAIL_SUPPLY_CRATE)))
                    pGo->Delete();
                break;
            case 19:
                m_creature->SetVisibility(VISIBILITY_OFF);
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                if (Creature* pTemp = m_creature->SummonCreature(NPC_REGINALD_WINDSOR, 
                    m_creature->GetPositionX(), 
                    m_creature->GetPositionY(), 
                    m_creature->GetPositionZ(), 3.600f, TEMPSUMMON_DEAD_DESPAWN, 0))
                {
                    if (auto pEscortAI = dynamic_cast<npc_marshal_reginald_windsorAI*>(pTemp->AI()))
                    {
                        pTemp->SetFactionTemplateId(11);
                        m_pInstance->SetData(TYPE_JAIL_SUPPLY_ROOM, DONE);
                        pEscortAI->Start(false, GetPlayerForEscort()->GetObjectGuid());
                    }                    
                }                    
                break;
        }
    }

    void Aggro(Unit* /*pWho*/) override
    {
        Player* pPlayer = GetPlayerForEscort();
        if (!pPlayer)
            return;

        switch (urand(0, 2))
        {
            case 0: DoScriptText(SAY_WINDSOR_AGGRO1, m_creature); break;
            case 1: DoScriptText(SAY_WINDSOR_AGGRO2, m_creature); break;
            case 2: DoScriptText(SAY_WINDSOR_AGGRO3, m_creature, pPlayer); break;
        }
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (Player* pPlayer = GetPlayerForEscort())
            pPlayer->GroupEventFailHappens(QUEST_JAIL_BREAK);
            
        m_pInstance->SetData(TYPE_QUEST_JAIL_BREAK, FAIL);
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS)
            return;

        if (m_pInstance->GetData(GO_JAIL_DOOR_DUGHAL) && m_pInstance->GetData(TYPE_JAIL_DUGHAL) == NOT_STARTED && m_uiWP == 7)
        {
            DoScriptText(SAY_WINDSOR_4_2, m_creature);
            m_pInstance->SetData(GO_JAIL_DOOR_DUGHAL, false);
        }

        if (m_pInstance->GetData(TYPE_JAIL_DUGHAL) == IN_PROGRESS && !m_uiSaidJustOnce && m_uiWP == 7)
        {
            SetEscortPaused(false);
            m_uiSaidJustOnce = true;
            if (Player* pTemp = GetPlayerForEscort())
                DoScriptText(SAY_WINDSOR_4_3, m_creature, pTemp);
        }

        npc_escortAI::UpdateEscortAI(uiDiff);
    }

};

bool QuestAccept_npc_marshal_windsor(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_JAIL_BREAK)
    {
        if (auto pInstance = static_cast<ScriptedInstance*>(pPlayer->GetInstanceData()))
        {
            if (pInstance->GetData(TYPE_QUEST_JAIL_BREAK) == NOT_STARTED)
            {
                pInstance->SetData(TYPE_QUEST_JAIL_BREAK, IN_PROGRESS);
                pCreature->SetFactionTemplateId(11);

                if (auto pEscortAI = dynamic_cast<npc_marshal_windsorAI*>(pCreature->AI()))
                    pEscortAI->Start(false, pPlayer->GetObjectGuid(), pQuest);
            }
        }
    }

    return true;
}

CreatureAI* GetAI_npc_marshal_windsor(Creature* pCreature)
{
    return new npc_marshal_windsorAI(pCreature);
}

// npc_tobias_seecher
struct npc_tobias_seecherAI : npc_escortAI
{
    explicit npc_tobias_seecherAI(Creature* m_creature) : npc_escortAI(m_creature)
    {
        m_pInstance = static_cast<ScriptedInstance*>(m_creature->GetInstanceData());
        npc_tobias_seecherAI::Reset();
    }

    ScriptedInstance* m_pInstance;

    void Reset() override {}

    void WaypointReached(uint32 uiPointId) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS)
            return;

        switch (uiPointId)
        {
            case 0:
                switch (urand(0, 1))
                {
                    case 0: DoScriptText(SAY_TOBIAS_FREE_1, m_creature); break;
                    case 1: DoScriptText(SAY_TOBIAS_FREE_2, m_creature); break;
                }
            case 2:
                m_pInstance->SetData(TYPE_JAIL_TOBIAS, IN_PROGRESS);
                break;
            case 4:
                m_pInstance->SetData(TYPE_JAIL_TOBIAS, DONE);
                break;
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        if (!m_pInstance || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) != IN_PROGRESS)
            return;

        if (m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) == FAIL || m_pInstance->GetData(TYPE_QUEST_JAIL_BREAK) == DONE || m_pInstance->GetData(TYPE_JAIL_TOBIAS) == DONE)
            m_creature->SetVisibility(VISIBILITY_OFF);
        else
             m_creature->SetVisibility(VISIBILITY_ON);

        npc_escortAI::UpdateEscortAI(uiDiff);
    }

    void OnScriptEventHappened(uint32 uiEvent, uint32 uiData, WorldObject* pInvoker) override
    {
        if (pInvoker && pInvoker->IsPlayer())
        {
            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            Start(true, pInvoker->GetObjectGuid());
        }
    }
};

CreatureAI* GetAI_npc_tobias_seecher(Creature* pCreature)
{
    return new npc_tobias_seecherAI(pCreature);
}

/*
 *
 */

struct go_cell_doorAI : GameObjectAI
{
    explicit go_cell_doorAI(GameObject* pGo) : GameObjectAI(pGo)
    {

    }

    bool OnUse(Unit* /*pCaster*/) override
    {
        auto pInstance = static_cast<ScriptedInstance*>(me->GetInstanceData());

        if (!pInstance)
            return true;

        pInstance->SetData(me->GetEntry(), true);
        Creature* pTemp = GetClosestCreatureWithEntry(me, NPC_CREST, 50.0f);

        if (me->GetEntry() == GO_JAIL_DOOR_CREST && pTemp)
            DoScriptText(SAY_CREST_KILLER, pTemp);

        return false;
    }
};

GameObjectAI* GetAI_go_cell_door(GameObject* pGo)
{
    return new go_cell_doorAI(pGo);
}

/*
 *
 */

void AddSC_blackrock_depths()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "go_shadowforge_brazier";
    newscript->pGOHello = &GOHello_go_shadowforge_brazier;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_ring_of_law";
    newscript->pAreaTrigger = &AreaTrigger_at_ring_of_law;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_grimstone";
    newscript->GetAI = &GetAI_npc_grimstone;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_phalanx";
    newscript->GetAI = &GetAI_mob_phalanx;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_rocknot";
    newscript->GetAI = &GetAI_npc_rocknot;
    newscript->pQuestRewardedNPC = &QuestRewarded_npc_rocknot;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_dark_keeper_portrait";
    newscript->pGOHello = &GOHello_go_dark_keeper_portrait;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_thunderbrew_laguer_keg";
    newscript->pGOHello = &GOHello_go_thunderbrew_laguer_keg;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_relic_coffer_door";
    newscript->pGOHello = &GOHello_go_relic_coffer_door;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_watchman_doomgrip";
    newscript->GetAI = &GetAI_npc_watchman_doomgrip;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_golem_lord_argelmach";
    newscript->GetAI = &GetAI_npc_golem_lord_argelmach;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_shadowforge_bridge";
    newscript->pAreaTrigger = &AreaTrigger_at_shadowforge_bridge;
    newscript->RegisterSelf();

    // The Grim Guzzler
    newscript = new Script;
    newscript->Name = "npc_mistress_nagmara";
    newscript->GetAI = &GetAI_npc_mistress_nagmara;
    newscript->pGossipHello = &GossipHello_npc_mistress_nagmara;
    newscript->pGossipSelect = &GossipSelect_npc_mistress_nagmara;
    newscript->pQuestRewardedNPC = &QuestRewarded_npc_mistress_nagmara;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "boss_plugger_spazzring";
    newscript->GetAI = &GetAI_boss_plugger_spazzring;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_bar_ale_mug";
    newscript->pGOHello = &GOUse_go_bar_ale_mug;
    newscript->RegisterSelf();

    // Jail Break!
    newscript = new Script;
    newscript->Name = "npc_dughal_stormwing";
    newscript->GetAI = &GetAI_npc_dughal_stormwing;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_marshal_reginald_windsor";
    newscript->GetAI = &GetAI_npc_marshal_reginald_windsor;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_marshal_windsor";
    newscript->GetAI = &GetAI_npc_marshal_windsor;
    newscript->pQuestAcceptNPC = &QuestAccept_npc_marshal_windsor;
    newscript->RegisterSelf();    

    newscript = new Script;
    newscript->Name = "npc_tobias_seecher";
    newscript->GetAI = &GetAI_npc_tobias_seecher;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_cell_door";
    newscript->GOGetAI = &GetAI_go_cell_door;
    newscript->RegisterSelf();
}
