/* Copyright (C) 2006 - 2010 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: gnomeregan
SD%Complete: 80
SDComment:  Grubbis Encounter
SDCategory: Gnomeregan
EndScriptData */

/* ContentData
npc_blastmaster_emi_shortfuse
EndContentData */

#include "scriptPCH.h"
#include "CreatureGroups.h"
#include "gnomeregan.h"

/*######
## npc_blastmaster_emi_shortfuse
######*/

enum
{
    SAY_START                   = -1090000,
    SAY_INTRO_1                 = -1090001,
    SAY_INTRO_2                 = -1090002,
    SAY_INTRO_3                 = -1090003,
    SAY_INTRO_4                 = -1090004,
    SAY_LOOK_1                  = -1090005,
    SAY_HEAR_1                  = -1090006,
    SAY_AGGRO_1                 = -1090007,
    SAY_CHARGE_1                = -1090008,
    SAY_CHARGE_2                = -1090009,
    SAY_BLOW_1_10               = -1090010,
    SAY_BLOW_1_5                = -1090011,
    SAY_BLOW_1                  = -1090012,
    SAY_FINISH_1                = -1090013,
    SAY_LOOK_2                  = -1090014,
    SAY_HEAR_2                  = -1090015,
    SAY_CHARGE_3                = -1090016,
    SAY_CHARGE_4                = -1090017,
    SAY_BLOW_2_10               = -1090018,
    SAY_BLOW_2_5                = -1090019,
    SAY_BLOW_SOON               = -1090020,
    SAY_BLOW_2                  = -1090021,
    SAY_FINISH_2                = -1090022,

    SAY_AGGRO_2                 = -1090028,

    SAY_GRUBBIS_SPAWN           = -1090023,

    GOSSIP_ITEM_START           = 4084,

    SPELL_EXPLOSION_NORTH       = 12159,
    SPELL_EXPLOSION_SOUTH       = 12158,
    SPELL_FIREWORKS_RED         = 11542,

    //GO_EXPLOSIVE_CHARGE         = 144065, //A USE

    MAX_SUMMON_POSITIONS        = 33,

    NPC_GRUBBIS                 = 7361,
    NPC_CHOMPER                 = 6215,
    NPC_CAVERNDEEP_BURROWER     = 6206,
    NPC_CAVERNDEEP_AMBUSHER     = 6207
};

struct sSummonInformation
{
    uint32 uiPosition, uiEntry;
    float fX, fY, fZ, fO;
};

static const sSummonInformation asSummonInfo[MAX_SUMMON_POSITIONS] =
{
    // Entries must be sorted by pack
    // First Cave-In
    {1, NPC_CAVERNDEEP_AMBUSHER, -566.8114f, -111.7036f, -151.1891f, 5.986479f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -568.5875f, -113.7559f, -151.1869f, 0.06981317f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -570.2333f, -116.8126f, -151.2272f, 0.296706f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -550.6331f, -108.7592f, -153.965f, 0.8901179f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -558.9717f, -115.0669f, -151.8799f, 0.5235988f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -556.6719f, -112.0526f, -152.8255f, 0.4886922f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -552.6419f, -113.4385f, -153.0727f, 0.8028514f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -549.1248f, -112.1469f, -153.7987f, 0.7504916f},
    {1, NPC_CAVERNDEEP_AMBUSHER, -546.7435f, -112.3051f, -154.2225f, 0.9250245f},
    {2, NPC_CAVERNDEEP_AMBUSHER, -571.4071f, -108.7721f, -150.6547f, 5.480334f},
    {2, NPC_CAVERNDEEP_AMBUSHER, -573.797f, -106.5265f, -150.4106f, 5.550147f},
    {2, NPC_CAVERNDEEP_AMBUSHER, -576.3784f, -108.0483f, -150.4227f, 5.585053f},
    {2, NPC_CAVERNDEEP_AMBUSHER, -576.697f, -111.7413f, -150.6484f, 5.759586f},
    {3, NPC_CAVERNDEEP_AMBUSHER, -571.3161f, -114.4412f, -151.0931f, 6.021386f},
    {3, NPC_CAVERNDEEP_AMBUSHER, -570.3127f, -111.7964f, -151.04f, 2.042035f},

    // Second Cave-In
    {4, NPC_CAVERNDEEP_AMBUSHER, -474.5954f, -104.074f, -146.0483f, 2.338741f},
    {4, NPC_CAVERNDEEP_AMBUSHER, -477.9396f, -108.6563f, -145.7394f, 1.553343f},
    {4, NPC_CAVERNDEEP_AMBUSHER, -475.6625f, -97.12168f, -146.5959f, 1.291544f},
    {4, NPC_CAVERNDEEP_AMBUSHER, -480.5233f, -88.40702f, -146.3772f, 3.001966f},
    {5, NPC_CAVERNDEEP_AMBUSHER, -474.2943f, -105.2212f, -145.9747f, 2.251475f},
    {5, NPC_CAVERNDEEP_AMBUSHER, -481.1831f, -101.4225f, -146.377f, 2.146755f},
    {5, NPC_CAVERNDEEP_BURROWER, -475.0871f, -100.016f, -146.4382f, 2.303835f},
    {5, NPC_CAVERNDEEP_AMBUSHER, -478.8562f, -106.9321f, -145.8533f, 1.658063f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -473.8762f, -107.4022f, -145.838f, 2.024582f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -490.5134f, -92.72843f, -148.0954f, 3.054326f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -491.401f, -88.25341f, -148.0358f, 3.560472f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -479.1431f, -106.227f, -145.9097f, 1.727876f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -475.3185f, -101.4804f, -146.2717f, 2.234021f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -485.1559f, -89.57419f, -146.9299f, 3.071779f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -482.2516f, -96.80614f, -146.6596f, 2.303835f},
    {6, NPC_CAVERNDEEP_AMBUSHER, -477.9874f, -92.82047f, -146.6944f, 3.124139f},

    // Grubbis and add
    {7, NPC_GRUBBIS, -476.3761f, -108.1901f, -145.7763f, 1.919862f},
    {7, NPC_CHOMPER, -473.1326f, -103.0901f, -146.1155f, 2.042035f}
};

struct npc_blastmaster_emi_shortfuseAI : public npc_escortAI
{
    npc_blastmaster_emi_shortfuseAI(Creature* pCreature) : npc_escortAI(pCreature)
    {
        m_pInstance = (instance_gnomeregan*)pCreature->GetInstanceData();
        // Remove Gossip-Menu in reload case for DONE enounter
        if (m_pInstance && m_pInstance->GetData(TYPE_GRUBBIS) == DONE)
            pCreature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
        Reset();
    }

    instance_gnomeregan* m_pInstance;

    uint8 m_uiPhase;
    uint32 m_uiPhaseTimer;
    ObjectGuid m_playerGuid;
    bool m_bDidAggroText, m_bSouthernCaveInOpened, m_bNorthernCaveInOpened;
    GuidList m_luiSummonedMobGUIDs;

    void Reset() override
    {
        m_bDidAggroText = false;                            // Used for 'defend' text, is triggered when the npc is attacked

        if (!HasEscortState(STATE_ESCORT_ESCORTING))
        {
            m_uiPhase = 0;
            m_uiPhaseTimer = 0;
            m_bSouthernCaveInOpened = m_bNorthernCaveInOpened = false;
            m_luiSummonedMobGUIDs.clear();
        }
    }

    void DoSummonPack(uint8 uiIndex)
    {
        for (const auto& i : asSummonInfo)
        {
            // This requires order of the array
            if (i.uiPosition > uiIndex)
                break;
            if (i.uiPosition == uiIndex)
                m_creature->SummonCreature(i.uiEntry, i.fX, i.fY, i.fZ, i.fO, TEMPSUMMON_DEAD_DESPAWN, 0);
        }
    }

    void JustSummoned(Creature* pSummoned) override
    {
        switch (pSummoned->GetEntry())
        {
            case NPC_CAVERNDEEP_BURROWER:
            case NPC_CAVERNDEEP_AMBUSHER:
            {
                if (GameObject* pDoor = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(m_uiPhase > 20 ? GO_CAVE_IN_NORTH : GO_CAVE_IN_SOUTH)))
                {
                    float fX, fY, fZ;
                    pDoor->GetNearPoint(pDoor, fX, fY, fZ, 0.0f, 2.0f, frand(0.0f, 2 * M_PI_F));
                    pSummoned->GetMotionMaster()->MovePoint(1, fX, fY, fZ, MOVE_PATHFINDING);
                }
                break;
            }
            case NPC_GRUBBIS:
                // Movement of Grubbis and Add to be handled by DB waypoints
                DoScriptText(SAY_GRUBBIS_SPAWN, pSummoned);
                break;
            case NPC_CHOMPER: //chomper must be invoqued after grubbis
                pSummoned->JoinCreatureGroup(pSummoned->FindNearestCreature(NPC_GRUBBIS, 10, true), 3, ((pSummoned->GetAngle(m_creature) - m_creature->GetOrientation()) + 2 * M_PI_F), (OPTION_FORMATION_MOVE | OPTION_AGGRO_TOGETHER));
                break;
        }
        m_luiSummonedMobGUIDs.push_back(pSummoned->GetObjectGuid());
    }

    void SummonedCreatureJustDied(Creature* pSummoned) override
    {
        if (pSummoned->GetEntry() == NPC_GRUBBIS)
        {
            if (m_pInstance)
                m_pInstance->SetData(TYPE_GRUBBIS, DONE);
            m_uiPhaseTimer = 1000;
        }
        m_luiSummonedMobGUIDs.remove(pSummoned->GetObjectGuid());
    }

    bool IsPreparingExplosiveCharge()
    {
        return m_uiPhase == 11 || m_uiPhase == 13 || m_uiPhase == 26 || m_uiPhase == 28;
    }

    void MoveInLineOfSight(Unit* pWho) override
    {
        // In case we are preparing the explosive charges, we won't start attacking mobs
        if (IsPreparingExplosiveCharge())
            return;

        npc_escortAI::MoveInLineOfSight(pWho);
    }

    void AttackStart(Unit* pWho) override
    {
        // In case we are preparing the explosive charges, we won't start attacking mobs
        if (IsPreparingExplosiveCharge())
            return;

        npc_escortAI::AttackStart(pWho);
    }

    void AttackedBy(Unit* pAttacker) override
    {
        // Possibility for Aggro-Text only once per combat
        if (m_bDidAggroText)
            return;

        m_bDidAggroText = true;

        if (!urand(0, 2))
            DoScriptText(urand(0, 1) ? SAY_AGGRO_1 : SAY_AGGRO_2, m_creature, pAttacker);
    }

    void JustDied(Unit* /*pKiller*/) override
    {
        if (!m_pInstance)
            return;

        m_pInstance->SetData(TYPE_GRUBBIS, FAIL);

        if (m_bSouthernCaveInOpened)                        // close southern cave-in door
            m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_CAVE_IN_SOUTH));
        if (m_bNorthernCaveInOpened)                        // close northern cave-in door
            m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_CAVE_IN_NORTH));

        for (const auto& guid : m_luiSummonedMobGUIDs)
        {
            if (Creature* pSummoned = m_creature->GetMap()->GetCreature(guid))
                pSummoned->ForcedDespawn();
        }
    }

    void StartEvent(Player* pPlayer)
    {
        if (!m_pInstance)
            return;

        m_pInstance->SetData(TYPE_GRUBBIS, IN_PROGRESS);

        m_uiPhase = 1;
        m_uiPhaseTimer = 1000;
        m_playerGuid = pPlayer->GetObjectGuid();
    }

    void WaypointStart(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 10:
                // Open Southern Cave-In
                if (m_pInstance && !m_bSouthernCaveInOpened)
                {
                    //m_pInstance->DoUseDoorOrButton(GO_CAVE_IN_SOUTH);
                    m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_CAVE_IN_SOUTH));
                    m_bSouthernCaveInOpened = true;
                }
                break;
            case 12:
                DoScriptText(SAY_CHARGE_1, m_creature);
                break;
            case 16:
                DoScriptText(SAY_CHARGE_3, m_creature);
                // Open Northern Cave-In
                if (m_pInstance && !m_bNorthernCaveInOpened)
                {
                    m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_CAVE_IN_NORTH));
                    m_bNorthernCaveInOpened = true;
                }
                break;
        }
    }

    void WaypointReached(uint32 uiPointId) override
    {
        switch (uiPointId)
        {
            case 4:
                m_uiPhaseTimer = 1000;
                break;
            case 9:
                m_uiPhaseTimer = 2000;
                break;
            case 11:
                m_creature->HandleEmote(EMOTE_STATE_USESTANDING);
                m_uiPhaseTimer = 15000;
                break;
            case 13:
                m_creature->HandleEmote(EMOTE_STATE_USESTANDING);
                m_uiPhaseTimer = 10000;
                break;
            case 15:
                SetEscortPaused(true);
                if (m_pInstance)
                {
                    if (GameObject* pDoor = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(GO_CAVE_IN_SOUTH)))
                        m_creature->SetFacingToObject(pDoor);
                }
                DoScriptText(SAY_BLOW_1_10, m_creature);
                m_uiPhaseTimer = 5000;
                break;
            case 16:
                m_creature->HandleEmote(EMOTE_STATE_USESTANDING);
                m_uiPhaseTimer = 15000;
                break;
            case 17:
                m_creature->HandleEmote(EMOTE_STATE_USESTANDING);
                m_uiPhaseTimer = 10000;
                break;
            case 19:
                m_uiPhaseTimer = 2000;
                SetEscortPaused(true);                      // And keep paused from now on!
                break;
        }
    }

    void UpdateEscortAI(uint32 const uiDiff) override
    {
        // the phases are handled OOC (keeps them in sync with the waypoints)
        if (m_uiPhaseTimer && !m_creature->GetVictim())
        {
            if (m_uiPhaseTimer <= uiDiff)
            {
                switch (m_uiPhase)
                {
                    case 1:
                        DoScriptText(SAY_START, m_creature);
                        m_creature->SetFactionTemporary(FACTION_ESCORT_N_NEUTRAL_PASSIVE, TEMPFACTION_RESTORE_RESPAWN);
                        m_creature->SetUInt32Value(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_NONE);
                        m_creature->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
                        m_uiPhaseTimer = 5000;
                        break;
                    case 2:
                        DoScriptText(SAY_INTRO_1, m_creature);
                        m_uiPhaseTimer = 3500;              // 6s delay, but 2500ms for escortstarting
                        break;
                    case 3:
                        Start(false, m_playerGuid, nullptr, false, false);
                        m_uiPhaseTimer = 0;
                        break;

                    case 4:                                 // Shortly after reached WP 4
                        DoScriptText(SAY_INTRO_2, m_creature);
                        m_uiPhaseTimer = 0;
                        break;

                    case 5:                                 // Shortly after reached WP 9
                        DoScriptText(SAY_INTRO_3, m_creature);
                        m_uiPhaseTimer = 6000;
                        break;
                    case 6:
                        DoScriptText(SAY_INTRO_4, m_creature);
                        m_uiPhaseTimer = 9000;
                        break;
                    case 7:
                        if (m_pInstance)
                        {
                            if (GameObject* pDoor = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(GO_CAVE_IN_SOUTH)))
                                m_creature->SetFacingToObject(pDoor);
                        }
                        m_uiPhaseTimer = 2000;
                        break;
                    case 8:
                        DoScriptText(SAY_LOOK_1, m_creature);
                        m_uiPhaseTimer = 5000;
                        break;
                    case 9:
                        DoScriptText(SAY_HEAR_1, m_creature);
                        m_uiPhaseTimer = 2000;
                        break;
                    case 10:                                // Shortly shortly before starting WP 11
                        DoSummonPack(1);
                        m_uiPhaseTimer = 0;
                        break;

                    case 11:                                // 15s after reached WP 11
                        DoSummonPack(2);

                        // Summon first explosive charge //BCP trop tard ?
                        if (m_pInstance)
                            m_pInstance->SetData(TYPE_EXPLOSIVE_CHARGE, DATA_EXPLOSIVE_CHARGE_1);
                        //TEST
                        //m_creature->SummonGameObject(GO_EXPLOSIVE_CHARGE, -535.2656, -105.9493, -156, 0.717935, 0, 0, 0, 0, 600);//coords?//o: 0.717935
                        //m_creature->SummonGameObject(GO_EXPLOSIVE_CHARGE, -542.357, -98.06, -155.8473, 5.578764, 0, 0, 0, 0, 600);//coords?//o: 5.578764
                        // Remove EMOTE_STATE_USESTANDING state-emote
                        m_creature->HandleEmote(EMOTE_ONESHOT_NONE);

                        m_uiPhaseTimer = 1;
                        break;
                    case 12:                                // Empty Phase, used to store information about set charge
                        m_uiPhaseTimer = 0;
                        break;

                    case 13:                                // 10s after reached WP 13
                        DoSummonPack(3);

                        // Summon second explosive charge //trop tard?
                        if (m_pInstance)
                            m_pInstance->SetData(TYPE_EXPLOSIVE_CHARGE, DATA_EXPLOSIVE_CHARGE_2);
                        // Remove EMOTE_STATE_USESTANDING state-emote
                        m_creature->HandleEmote(EMOTE_ONESHOT_NONE);

                        m_uiPhaseTimer = 11000;
                        break;
                    case 14:                                // Empty Phase, used to store information about set charge
                        m_uiPhaseTimer = 1;
                        break;
                    case 15:                                // shortly before starting WP 14
                        if (Player* pPlayer = m_creature->GetMap()->GetPlayer(m_playerGuid))
                            m_creature->SetFacingToObject(pPlayer);
                        DoScriptText(SAY_CHARGE_2, m_creature);
                        m_uiPhaseTimer = 0;
                        break;

                    case 16:                                // 5s after reaching WP 15
                        DoScriptText(SAY_BLOW_1_5, m_creature);
                        m_uiPhaseTimer = 5000;
                        break;
                    case 17:
                        DoScriptText(SAY_BLOW_1, m_creature);
                        m_uiPhaseTimer = 1000;
                        break;
                    case 18:
                        DoCastSpellIfCan(m_creature, SPELL_EXPLOSION_SOUTH);
                        m_uiPhaseTimer = 500;
                        break;
                    case 19:
                        // Close southern cave-in and let charges explode
                        if (m_pInstance)
                        {
                            m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_CAVE_IN_SOUTH));
                            m_bSouthernCaveInOpened = false;
                            m_pInstance->SetData(TYPE_EXPLOSIVE_CHARGE, DATA_EXPLOSIVE_CHARGE_USE);
                        }
                        m_uiPhaseTimer = 5000;
                        break;
                    case 20:
                        m_creature->HandleEmote(EMOTE_ONESHOT_CHEER);
                        m_uiPhaseTimer = 6000;
                        break;
                    case 21:
                        DoScriptText(SAY_FINISH_1, m_creature);
                        m_uiPhaseTimer = 6000;
                        break;
                    case 22:
                        DoScriptText(SAY_LOOK_2, m_creature);
                        m_uiPhaseTimer = 3000;
                        break;
                    case 23:
                        if (m_pInstance)
                        {
                            if (GameObject* pDoor = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(GO_CAVE_IN_NORTH)))
                                m_creature->SetFacingToObject(pDoor);
                        }
                        m_uiPhaseTimer = 3000;
                        break;
                    case 24:
                        DoScriptText(SAY_HEAR_2, m_creature);
                        m_uiPhaseTimer = 8000;
                        break;
                    case 25:                                // shortly before starting WP 16
                        SetEscortPaused(false);
                        DoSummonPack(4);
                        m_uiPhaseTimer = 0;
                        break;

                    case 26:                                // 15s after reaching WP 16
                        DoSummonPack(5);

                        // Summon third explosive charge
                        if (m_pInstance)
                            m_pInstance->SetData(TYPE_EXPLOSIVE_CHARGE, DATA_EXPLOSIVE_CHARGE_3);
                        // Remove EMOTE_STATE_USESTANDING state-emote
                        m_creature->HandleEmote(EMOTE_ONESHOT_NONE);

                        m_uiPhaseTimer = 1;
                        break;
                    case 27:                                // Empty Phase, used to store information about set charge
                        m_uiPhaseTimer = 0;
                        break;

                    case 28:                                // 10s after reaching WP 17
                        DoSummonPack(6);

                        // Summon forth explosive charge
                        if (m_pInstance)
                            m_pInstance->SetData(TYPE_EXPLOSIVE_CHARGE, DATA_EXPLOSIVE_CHARGE_4);
                        // Remove EMOTE_STATE_USESTANDING state-emote
                        m_creature->HandleEmote(EMOTE_ONESHOT_NONE);

                        m_uiPhaseTimer = 10000;
                        break;
                    case 29:                                // Empty Phase, used to store information about set charge
                        m_uiPhaseTimer = 1;
                        break;
                    case 30:                                // shortly before starting WP 18
                        DoScriptText(SAY_CHARGE_4, m_creature);
                        m_uiPhaseTimer = 0;
                        break;

                    case 31:                                // shortly after reaching WP 19
                        if (m_pInstance)
                        {
                            if (GameObject* pDoor = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(GO_CAVE_IN_NORTH)))
                                m_creature->SetFacingToObject(pDoor);
                        }
                        DoScriptText(SAY_BLOW_2_10, m_creature);
                        m_uiPhaseTimer = 5000;
                        break;
                    case 32:
                        DoScriptText(SAY_BLOW_2_5, m_creature);
                        m_uiPhaseTimer = 1000;
                        break;
                    case 33:
                        DoSummonPack(7);                    // Summon Grubbis and add
                        m_uiPhaseTimer = 0;
                        break;

                    case 34:                                // 1 sek after Death of Grubbis
                        if (m_pInstance)
                        {
                            if (GameObject* pDoor = m_creature->GetMap()->GetGameObject(m_pInstance->GetData64(GO_CAVE_IN_NORTH)))
                                m_creature->SetFacingToObject(pDoor);
                        }
                        m_creature->HandleEmote(EMOTE_ONESHOT_CHEER);
                        m_uiPhaseTimer = 5000;
                        break;
                    case 35:
                        DoScriptText(SAY_BLOW_SOON, m_creature);
                        m_uiPhaseTimer = 5000;
                        break;
                    case 36:
                        DoScriptText(SAY_BLOW_2, m_creature);
                        m_uiPhaseTimer = 2000;
                        break;
                    case 37:
                        m_creature->HandleEmote(EMOTE_ONESHOT_POINT);
                        m_uiPhaseTimer = 1000;
                        break;
                    case 38:
                        DoCastSpellIfCan(m_creature, SPELL_EXPLOSION_NORTH);
                        m_uiPhaseTimer = 500;
                        break;
                    case 39:
                        // Close northern cave-in and let charges explode
                        if (m_pInstance)
                        {
                            m_pInstance->DoUseDoorOrButton(m_pInstance->GetData64(GO_CAVE_IN_NORTH));
                            m_bNorthernCaveInOpened = false;
                            m_pInstance->SetData(TYPE_EXPLOSIVE_CHARGE, DATA_EXPLOSIVE_CHARGE_USE);
                        }
                        m_uiPhaseTimer = 8000;
                        break;
                    case 40:
                        DoCastSpellIfCan(m_creature, SPELL_FIREWORKS_RED);
                        DoScriptText(SAY_FINISH_2, m_creature);
                        m_uiPhaseTimer = 0;
                        break;
                }
                ++m_uiPhase;
            }
            else
                m_uiPhaseTimer -= uiDiff;
        }

        if (!m_creature->SelectHostileTarget() || !m_creature->GetVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_blastmaster_emi_shortfuse(Creature* pCreature)
{
    return new npc_blastmaster_emi_shortfuseAI(pCreature);
}

bool GossipHello_npc_blastmaster_emi_shortfuse(Player* pPlayer, Creature* pCreature)
{
    if (instance_gnomeregan* pInstance = (instance_gnomeregan*)pCreature->GetInstanceData())
    {
        if (pInstance->GetData(TYPE_GRUBBIS) == NOT_STARTED || pInstance->GetData(TYPE_GRUBBIS) == FAIL)
        {
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_START /*"I am ready to begin."*/, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetObjectGuid());
        }
    }
    return true;
}

bool GossipSelect_npc_blastmaster_emi_shortfuse(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
    {
        if (instance_gnomeregan* pInstance = (instance_gnomeregan*)pCreature->GetInstanceData())
        {
            if (pInstance->GetData(TYPE_GRUBBIS) == NOT_STARTED || pInstance->GetData(TYPE_GRUBBIS) == FAIL)
            {
                if (npc_blastmaster_emi_shortfuseAI* pEmiAI = dynamic_cast<npc_blastmaster_emi_shortfuseAI*>(pCreature->AI()))
                    pEmiAI->StartEvent(pPlayer);
            }
        }
    }
    pPlayer->CLOSE_GOSSIP_MENU();

    return true;
}
/*######
## npc_kernobee
## TODO: It appears there are some things missing, including his? alarm-bot
######*/

enum
{
    QUEST_A_FINE_MESS           = 2904,
    TRIGGER_GNOME_EXIT          = 324,                      // Add scriptlib support for it, atm simply use hardcoded values

    SPELL_EXPLOSION             = 27745, //spell de Clank.

    SAY_KERNOBEE_START          = -1780204,
    SAY_BOMB_START              = -1780205,
    SAY_BOMB_SEE_END            = -1780206,
    SAY_KERNOBEE_SEE_END        = -1780207,
    SAY_KERNOBEE_END            = -1780208,
};

static float const aKernobeePositions[3][3] =
{
    { -390.82f, 42.34f, -154.795f},                          // I can see the end!
    { -330.92f, -3.03f, -152.85f},                          // End position
    { -297.32f, -7.32f, -152.85f}                           // Walk out of the door
};

struct npc_kernobeeAI : public FollowerAI
{
    npc_kernobeeAI(Creature* pCreature) : FollowerAI(pCreature)
    {
        QuestReset();
        Reset();
    }

    uint32 m_uiCheckEndposTimer;
    uint32 m_nextStepTimer;
    uint16 nextStep;
    uint64 bombGuid;
    bool canSeeEnd;

    void Reset() override {}

    void JustRespawned() override
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        FollowerAI::JustRespawned();
    }

    void UpdateFollowerAI(uint32 const uiDiff) override
    {
        FollowerAI::UpdateFollowerAI(uiDiff);               // Do combat handling
        if (nextStep == 5) //HasFollowState(STATE_FOLLOW_COMPLETE)
        {
            if (m_nextStepTimer < uiDiff)
            {
                if (Creature* creature = m_creature->GetMap()->GetCreature(bombGuid))
                {
                    creature->CastSpell(creature, SPELL_EXPLOSION, true);
                    //creature->ForcedDespawn();
                    //creature->DisappearAndDie();
                    //m_creature->DisappearAndDie();
                    nextStep = 6;
                    m_nextStepTimer = 200;
                }
            }
            else
                m_nextStepTimer -= uiDiff;
        }
        else if (nextStep == 6) //HasFollowState(STATE_FOLLOW_COMPLETE)
        {
            if (m_nextStepTimer < uiDiff)
            {
                if (Creature* creature = m_creature->GetMap()->GetCreature(bombGuid))
                {
                    nextStep = 0;
                    creature->DisappearAndDie();
                    m_creature->DisappearAndDie();
                }
            }
            else
                m_nextStepTimer -= uiDiff;
        }

        if (m_creature->IsInCombat() || !HasFollowState(STATE_FOLLOW_INPROGRESS) || HasFollowState(STATE_FOLLOW_COMPLETE))
            return;

        if (nextStep == 1) /*HasFollowState(STATE_FOLLOW_PAUSED)*/
        {
            if (m_nextStepTimer < uiDiff)
            {
                if (m_creature->FindNearestCreature(NPC_ALARM_A_BOMB_2600, 10.0f)) //détecter la bombe a proximité.
                {
                    m_creature->SetWalk(true);//speed influences speed of follower
                    SetFollowPaused(false);
                    m_nextStepTimer = 5 * MINUTE * IN_MILLISECONDS;;
                    nextStep = 2;
                }
                else
                    m_nextStepTimer = 500;
            }
            else
                m_nextStepTimer -= uiDiff;
        }
        if (nextStep == 2)
        {
            if (m_nextStepTimer < uiDiff)
            {
                if (Creature* creature = m_creature->GetMap()->GetCreature(bombGuid))
                {
                    creature->CastSpell(creature, SPELL_EXPLOSION, true);
                    nextStep = 6; //skip to they both die.
                    m_nextStepTimer = 200;
                }
            }
            else
                m_nextStepTimer -= uiDiff;
        }
        if (m_uiCheckEndposTimer < uiDiff)
        {
            if (nextStep == 2) /*!explosionTimerStarted*/
            {
                if (Creature* bomb = m_creature->GetMap()->GetCreature(bombGuid))
                {
                    if (bomb->IsWithinDist3d(aKernobeePositions[0][0], aKernobeePositions[0][1], aKernobeePositions[0][2], 2 * INTERACTION_DISTANCE))
                    {
                        //explosionTimerStarted=true;
                        nextStep = 3;
                        m_nextStepTimer = 20000;
                        DoScriptText(SAY_BOMB_SEE_END, bomb);
                    }
                }
            }
            if (!canSeeEnd)
            {
                if (m_creature->IsWithinDist3d(aKernobeePositions[0][0], aKernobeePositions[0][1], aKernobeePositions[0][2], 2 * INTERACTION_DISTANCE))
                {
                    DoScriptText(SAY_KERNOBEE_SEE_END, m_creature);
                    canSeeEnd = true;
                }
            }
            else
            {
                if (m_creature->IsWithinDist3d(aKernobeePositions[1][0], aKernobeePositions[1][1], aKernobeePositions[1][2], 2 * INTERACTION_DISTANCE))
                {
                    DoScriptText(SAY_KERNOBEE_END, m_creature);
                    nextStep = 5;
                    m_nextStepTimer = 2500;
                    SetFollowComplete(true);
                    if (Player* pPlayer = GetLeaderForFollower())
                        pPlayer->GroupEventHappens(QUEST_A_FINE_MESS, m_creature);
                    //m_creature->GetMotionMaster()->MovePoint(1, aKernobeePositions[2][0], aKernobeePositions[2][1], aKernobeePositions[2][2], false);
                    //m_creature->ForcedDespawn(3000);
                }
            }
            m_uiCheckEndposTimer = 200;
        }
        else
            m_uiCheckEndposTimer -= uiDiff;
        if (nextStep == 3)
        {
            if (m_nextStepTimer < uiDiff)
            {
                if (Creature* crea = m_creature->GetMap()->GetCreature(bombGuid))
                {
                    crea->CastSpell(crea, SPELL_EXPLOSION, true);
                    crea->DealDamage(m_creature, m_creature->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                    crea->DealDamage(crea, crea->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                    nextStep = 4;
                    m_nextStepTimer = 200;
                }
            }
            else
                m_nextStepTimer -= uiDiff;
        }
        if (nextStep == 4)
        {
            if (m_nextStepTimer < uiDiff)
            {
                if (Creature* crea = m_creature->GetMap()->GetCreature(bombGuid))
                {
                    crea->DealDamage(crea, crea->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                    nextStep = 0;
                    crea->DealDamage(m_creature, m_creature->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                }
            }
            else
                m_nextStepTimer -= uiDiff;
        }
    }

    void JustDied(Unit* pKiller) override
    {
        FollowerAI::JustDied(pKiller);
        QuestReset();
        if (Creature* bomb = m_creature->GetMap()->GetCreature(bombGuid))
            bomb->DisappearAndDie();
    }
    void QuestReset()
    {
        m_creature->SetStandState(UNIT_STAND_STATE_DEAD);
        m_uiCheckEndposTimer = 10000;
        m_nextStepTimer = 2000;
        canSeeEnd = false;
        nextStep = 0;
    }
    void StartQuest(Player* pPlayer, Quest const* pQuest)
    {
        DoScriptText(SAY_KERNOBEE_START, m_creature);
        m_creature->SetStandState(UNIT_STAND_STATE_STAND);
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
        StartFollow(pPlayer, 0/*FACTION_ESCORT_N_FRIEND_PASSIVE*/, pQuest);
        if (bombGuid = ((instance_gnomeregan*)m_creature->GetInstanceData())->GetData64(NPC_ALARM_A_BOMB_2600))
        {
            if (Creature* bomb = m_creature->GetMap()->GetCreature(bombGuid))
            {
                SetFollowPaused(true);
                //bomb->SetWalk(false);
                m_creature->SetWalk(false);
                bomb->GetMotionMaster()->MoveFollow(m_creature, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);
                DoScriptText(SAY_BOMB_START, bomb);
            }
        }
        nextStep = 1;
    }
};

CreatureAI* GetAI_npc_kernobee(Creature* pCreature)
{
    return new npc_kernobeeAI(pCreature);
}

bool QuestAccept_npc_kernobee(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_A_FINE_MESS)
    {
        if (npc_kernobeeAI* pAI = dynamic_cast<npc_kernobeeAI*>(pCreature->AI()))
            pAI->StartQuest(pPlayer, pQuest);
    }
    return true;
}



void AddSC_gnomeregan()
{
    Script* pNewScript;

    pNewScript = new Script;
    pNewScript->Name = "npc_blastmaster_emi_shortfuse";
    pNewScript->GetAI = &GetAI_npc_blastmaster_emi_shortfuse;
    pNewScript->pGossipHello = &GossipHello_npc_blastmaster_emi_shortfuse;
    pNewScript->pGossipSelect = &GossipSelect_npc_blastmaster_emi_shortfuse;
    pNewScript->RegisterSelf();

    pNewScript = new Script;
    pNewScript->Name = "npc_kernobee";
    pNewScript->GetAI = &GetAI_npc_kernobee;
    pNewScript->pQuestAcceptNPC = &QuestAccept_npc_kernobee;
    pNewScript->RegisterSelf();
}
