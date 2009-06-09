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
#include "def_dark_portal.h"

#define ENCOUNTERS              2

#define C_MEDIVH                15608
#define C_TIME_RIFT             17838

#define SPELL_RIFT_CHANNEL      31387

#define RIFT_BOSS               1
inline uint32 RandRiftBoss() { return rand()%2 ? C_RKEEP : C_RLORD; }

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
    instance_dark_portal(Map *map) : ScriptedInstance(map) {Initialize();};

    uint32 Encounter[ENCOUNTERS];

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
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;

        mRiftPortalCount    = 0;
        mShieldPercent      = 100;
        mRiftWaveCount      = 0;
        mRiftWaveId         = 0;

        CurrentRiftId = 0;

        NextPortal_Timer    = 0;
    }

    Player* GetPlayerInMap()
    {
        Map::PlayerList const& players = instance->GetPlayers();

        if (!players.isEmpty())
        {
            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player* plr = itr->getSource())
                    return plr;
            }
        }

        debug_log("TSCR: Instance Black Portal: GetPlayerInMap, but PlayerList is empty!");
        return NULL;
    }

    void UpdateBMWorldState(uint32 id, uint32 state)
    {
        Map::PlayerList const& players = instance->GetPlayers();

        if (!players.isEmpty())
        {
            for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            {
                if (Player* player = itr->getSource())
                    player->SendUpdateWorldState(id,state);
            }
        }else debug_log("TSCR: Instance Black Portal: UpdateBMWorldState, but PlayerList is empty!");
    }

    void InitWorldState(bool Enable = true)
    {
        UpdateBMWorldState(WORLD_STATE_BM,Enable ? 1 : 0);
        UpdateBMWorldState(WORLD_STATE_BM_SHIELD,100);
        UpdateBMWorldState(WORLD_STATE_BM_RIFT,0);
    }

    bool IsEncounterInProgress()
    {
        if (GetData(TYPE_MEDIVH) == IN_PROGRESS)
            return true;

        return false;
    }

    void OnPlayerEnter(Player *player)
    {
        if (GetData(TYPE_MEDIVH) == IN_PROGRESS)
            return;

        player->SendUpdateWorldState(WORLD_STATE_BM,0);
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        if (creature->GetEntry() == C_MEDIVH)
            MedivhGUID = creature->GetGUID();
    }

    //what other conditions to check?
    bool CanProgressEvent()
    {
        if (!GetPlayerInMap())
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
        Player *player = GetPlayerInMap();

        if (!player)
        {
            debug_log("TSCR: Instance Black Portal: SetData (Type: %u Data %u) cannot find any player.", type, data);
            return;
        }

        switch(type)
        {
        case TYPE_MEDIVH:
            if (data == SPECIAL && Encounter[0] == IN_PROGRESS)
            {
                --mShieldPercent;
                UpdateBMWorldState(WORLD_STATE_BM_SHIELD,mShieldPercent);

                if (!mShieldPercent)
                {
                    if (Unit *medivh = Unit::GetUnit(*player,MedivhGUID))
                    {
                        if (medivh->isAlive())
                        {
                            medivh->DealDamage(medivh, medivh->GetHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                            Encounter[0] = FAIL;
                            Encounter[1] = NOT_STARTED;
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
                    Encounter[1] = IN_PROGRESS;
                    NextPortal_Timer = 15000;
                }

                if (data == DONE)
                {
                    //this may be completed further out in the post-event
                    if (Unit *medivh = Unit::GetUnit(*player,MedivhGUID))
                    {
                        debug_log("TSCR: Instance Dark Portal: Event completed.");
                        player->GroupEventHappens(QUEST_OPENING_PORTAL,medivh);
                        player->GroupEventHappens(QUEST_MASTER_TOUCH,medivh);
                    }
                }

                Encounter[0] = data;
            }
            break;
        case TYPE_RIFT:
            if (data == SPECIAL)
            {
                if (mRiftPortalCount < 7)
                    NextPortal_Timer = 5000;
            }
            else
                Encounter[1] = data;
            break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
        case TYPE_MEDIVH:
            return Encounter[0];
        case TYPE_RIFT:
            return Encounter[1];
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

    Unit* SummonedPortalBoss(Unit* source)
    {
        uint32 entry = RiftWaves[GetRiftWaveId()].PortalBoss;
        if (entry == RIFT_BOSS)
            entry = RandRiftBoss();

        float x,y,z;
        source->GetRandomPoint(source->GetPositionX(),source->GetPositionY(),source->GetPositionZ(),10.0f,x,y,z);
        //normalize Z-level if we can, if rift is not at ground level.
        z = std::max(instance->GetHeight(x, y, MAX_HEIGHT), instance->GetWaterLevel(x, y));

        debug_log("TSCR: Instance Dark Portal: Summoning rift boss entry %u.",entry);

        Unit *Summon = source->SummonCreature(entry,x,y,z,source->GetOrientation(),
            TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,600000);

        if (Summon)
            return Summon;

        debug_log("TSCR: Instance Dark Portal: what just happened there? No boss, no loot, no fun...");
        return NULL;
    }

    void DoSpawnPortal()
    {
        Player *player = GetPlayerInMap();
        if (!player)
            return;

        if (Unit *medivh = Unit::GetUnit(*player,MedivhGUID))
        {
            int tmp = rand()%(4-1);

            if (tmp >= CurrentRiftId)
                tmp++;
                    debug_log("TSCR: Instance Dark Portal: Creating Time Rift at locationId %i (old locationId was %u).",tmp,CurrentRiftId);

                    CurrentRiftId = tmp;

                    Unit *temp = medivh->SummonCreature(C_TIME_RIFT,
                        PortalLocation[tmp][0],PortalLocation[tmp][1],PortalLocation[tmp][2],PortalLocation[tmp][3],
                        TEMPSUMMON_CORPSE_DESPAWN,0);
                    if (temp)
                    {

                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        temp->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);


                        if (Unit* boss = SummonedPortalBoss(temp))
                        {
                            if (boss->GetEntry() == C_AEONUS)
                            {
                                boss->AddThreat(medivh,0.0f);
                            }
                            else
                            {
                                boss->AddThreat(temp,0.0f);
                                temp->CastSpell(boss,SPELL_RIFT_CHANNEL,false);
                            }
                        }
                    }
        }
    }

    void Update(uint32 diff)
    {
        if (Encounter[1] != IN_PROGRESS)
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
                UpdateBMWorldState(WORLD_STATE_BM_RIFT,mRiftPortalCount);

                DoSpawnPortal();
                NextPortal_Timer = RiftWaves[GetRiftWaveId()].NextPortalTime;
            }else NextPortal_Timer -= diff;
        }
    }
};

InstanceData* GetInstanceData_instance_dark_portal(Map* map)
{
    return new instance_dark_portal(map);
}

void AddSC_instance_dark_portal()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "instance_dark_portal";
    newscript->GetInstanceData = &GetInstanceData_instance_dark_portal;
    newscript->RegisterSelf();
}

