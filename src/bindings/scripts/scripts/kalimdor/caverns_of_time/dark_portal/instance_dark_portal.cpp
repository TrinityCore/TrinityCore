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
SDName: Instance_Dark_Portal
SD%Complete: 50
SDComment: Quest support: 9836, 10297. Currently in progress.
SDCategory: Caverns of Time, The Dark Portal
EndScriptData */

#include "precompiled.h"
#include "dark_portal.h"

#define MAX_ENCOUNTER              2

#define C_MEDIVH                15608
#define C_TIME_RIFT             17838

#define SPELL_RIFT_CHANNEL      31387

#define RIFT_BOSS               1

inline uint32 RandRiftBoss() { return ((rand()%2) ? C_RKEEP : C_RLORD); }

float PortalLocation[4][4]=
{
    {-2041.06, 7042.08, 29.99, 1.30},
    {-1968.18, 7042.11, 21.93, 2.12},
    {-1885.82, 7107.36, 22.32, 3.07},
    {-1928.11, 7175.95, 22.11, 3.44}
};

struct Wave
{
    uint32 PortalBoss;                                      //protector of current portal
    uint32 NextPortalTime;                                  //time to next portal, or 0 if portal boss need to be killed
};

static Wave RiftWaves[]=
{
    {RIFT_BOSS, 0},
    {C_DEJA, 0},
    {RIFT_BOSS, 120000},
    {C_TEMPO, 140000},
    {RIFT_BOSS, 120000},
    {C_AEONUS, 0}
};

struct TRINITY_DLL_DECL instance_dark_portal : public ScriptedInstance
{
    instance_dark_portal(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    uint32 mRiftPortalCount;
    uint32 mShieldPercent;
    uint8 mRiftWaveCount;
    uint8 mRiftWaveId;

    uint32 NextPortal_Timer;

    uint64 MedivhGUID;
    uint8 CurrentRiftId;

    void Initialize()
    {
        MedivhGUID          = 0;
        Clear();
    }

    void Clear()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        mRiftPortalCount    = 0;
        mShieldPercent      = 100;
        mRiftWaveCount      = 0;
        mRiftWaveId         = 0;

        CurrentRiftId = 0;

        NextPortal_Timer    = 0;
    }

    void InitWorldState(bool Enable = true)
    {
        DoUpdateWorldState(WORLD_STATE_BM,Enable ? 1 : 0);
        DoUpdateWorldState(WORLD_STATE_BM_SHIELD, 100);
        DoUpdateWorldState(WORLD_STATE_BM_RIFT, 0);
    }

    bool IsEncounterInProgress()
    {
        if (GetData(TYPE_MEDIVH) == IN_PROGRESS)
            return true;

        return false;
    }

    void OnPlayerEnter(Player* pPlayer)
    {
        if (GetData(TYPE_MEDIVH) == IN_PROGRESS)
            return;

        pPlayer->SendUpdateWorldState(WORLD_STATE_BM,0);
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        if (pCreature->GetEntry() == C_MEDIVH)
            MedivhGUID = pCreature->GetGUID();
    }

    //what other conditions to check?
    bool CanProgressEvent()
    {
        if (instance->GetPlayers().isEmpty())
            return false;

        return true;
    }

    uint8 GetRiftWaveId()
    {
        switch(mRiftPortalCount)
        {
        case 6:
            mRiftWaveId = 2;
            return 1;
        case 12:
            mRiftWaveId = 4;
            return 3;
        case 18:
            return 5;
        default:
            return mRiftWaveId;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case TYPE_MEDIVH:
            if (data == SPECIAL && m_auiEncounter[0] == IN_PROGRESS)
            {
                --mShieldPercent;

                DoUpdateWorldState(WORLD_STATE_BM_SHIELD, mShieldPercent);

                if (!mShieldPercent)
                {
                    if (Creature* pMedivh = instance->GetCreature(MedivhGUID))
                    {
                        if (pMedivh->isAlive())
                        {
                            pMedivh->DealDamage(pMedivh, pMedivh->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                            m_auiEncounter[0] = FAIL;
                            m_auiEncounter[1] = NOT_STARTED;
                        }
                    }
                }
            }
            else
            {
                if (data == IN_PROGRESS)
                {
                    debug_log("TSCR: Instance Dark Portal: Starting event.");
                    InitWorldState();
                    m_auiEncounter[1] = IN_PROGRESS;
                    NextPortal_Timer = 15000;
                }

                if (data == DONE)
                {
                    //this may be completed further out in the post-event
                    debug_log("TSCR: Instance Dark Portal: Event completed.");
                    Map::PlayerList const& players = instance->GetPlayers();

                    if (!players.isEmpty())
                    {
                        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player* pPlayer = itr->getSource())
                            {
                                if (pPlayer->GetQuestStatus(QUEST_OPENING_PORTAL) == QUEST_STATUS_INCOMPLETE)
                                    pPlayer->AreaExploredOrEventHappens(QUEST_OPENING_PORTAL);

                                if (pPlayer->GetQuestStatus(QUEST_MASTER_TOUCH) == QUEST_STATUS_INCOMPLETE)
                                    pPlayer->AreaExploredOrEventHappens(QUEST_MASTER_TOUCH);
                            }
                        }
                    }
                }

                m_auiEncounter[0] = data;
            }
            break;
        case TYPE_RIFT:
            if (data == SPECIAL)
            {
                if (mRiftPortalCount < 7)
                    NextPortal_Timer = 5000;
            }
            else
                m_auiEncounter[1] = data;
            break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
        case TYPE_MEDIVH:
            return m_auiEncounter[0];
        case TYPE_RIFT:
            return m_auiEncounter[1];
        case DATA_PORTAL_COUNT:
            return mRiftPortalCount;
        case DATA_SHIELD:
            return mShieldPercent;
        }
        return 0;
    }

    uint64 GetData64(uint32 data)
    {
        if (data == DATA_MEDIVH)
            return MedivhGUID;

        return 0;
    }

    Creature* SummonedPortalBoss(Creature* m_creature)
    {
        uint32 entry = RiftWaves[GetRiftWaveId()].PortalBoss;

        if (entry == RIFT_BOSS)
            entry = RandRiftBoss();

        debug_log("TSCR: Instance Dark Portal: Summoning rift boss entry %u.",entry);

        Position pos;
        m_creature->GetRandomNearPosition(pos, 10.0f);

        //normalize Z-level if we can, if rift is not at ground level.
        pos.m_positionZ = std::max(m_creature->GetMap()->GetHeight(pos.m_positionX, pos.m_positionY, MAX_HEIGHT), m_creature->GetMap()->GetWaterLevel(pos.m_positionX, pos.m_positionY));

        if(Creature *summon = m_creature->SummonCreature(entry, pos, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 600000))
            return summon;

        debug_log("TSCR: Instance Dark Portal: What just happened there? No boss, no loot, no fun...");
        return NULL;
    }

    void DoSpawnPortal()
    {
        if (Creature* pMedivh = instance->GetCreature(MedivhGUID))
        {
            uint8 tmp = urand(0,2);

            if (tmp >= CurrentRiftId)
                ++tmp;

            debug_log("TSCR: Instance Dark Portal: Creating Time Rift at locationId %i (old locationId was %u).",tmp,CurrentRiftId);

            CurrentRiftId = tmp;

            Creature *pTemp = pMedivh->SummonCreature(C_TIME_RIFT,
                PortalLocation[tmp][0],PortalLocation[tmp][1],PortalLocation[tmp][2],PortalLocation[tmp][3],
                TEMPSUMMON_CORPSE_DESPAWN,0);
            if (pTemp)
            {
                pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                pTemp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);

                if (Creature *pBoss = SummonedPortalBoss(pTemp))
                {
                    if (pBoss->GetEntry() == C_AEONUS)
                        pBoss->AddThreat(pMedivh,0.0f);
                    else
                    {
                        pBoss->AddThreat(pTemp,0.0f);
                        pTemp->CastSpell(pBoss,SPELL_RIFT_CHANNEL,false);
                    }
                }
            }
        }
    }

    void Update(uint32 diff)
    {
        if (m_auiEncounter[1] != IN_PROGRESS)
            return;

        //add delay timer?
        if (!CanProgressEvent())
        {
            Clear();
            return;
        }

        if (NextPortal_Timer)
        {
            if (NextPortal_Timer <= diff)
            {
                ++mRiftPortalCount;

                DoUpdateWorldState(WORLD_STATE_BM_RIFT, mRiftPortalCount);

                DoSpawnPortal();
                NextPortal_Timer = RiftWaves[GetRiftWaveId()].NextPortalTime;
            } else NextPortal_Timer -= diff;
        }
    }
};

InstanceData* GetInstanceData_instance_dark_portal(Map* pMap)
{
    return new instance_dark_portal(pMap);
}

void AddSC_instance_dark_portal()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "instance_dark_portal";
    newscript->GetInstanceData = &GetInstanceData_instance_dark_portal;
    newscript->RegisterSelf();
}

