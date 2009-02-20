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
SDName: Instance_Magtheridons_Lair
SD%Complete: 100
SDComment:
SDCategory: Hellfire Citadel, Magtheridon's lair
EndScriptData */

#include "precompiled.h"
#include "def_magtheridons_lair.h"

#define SPELL_SOUL_TRANSFER         30531 // core bug, does not support target 7
#define SPELL_BLAZE_TARGET          30541 // core bug, does not support target 7

#define CHAMBER_CENTER_X            -15.14
#define CHAMBER_CENTER_Y              1.8
#define CHAMBER_CENTER_Z             -0.4

#define ENCOUNTERS 2

struct TRINITY_DLL_DECL instance_magtheridons_lair : public ScriptedInstance
{
    instance_magtheridons_lair(Map *Map) : ScriptedInstance(Map)
    {
        Initialize();
    }

    uint32 Encounters[ENCOUNTERS];

    uint64 MagtheridonGUID;
    std::set<uint64> ChannelerGUID;
    uint64 DoorGUID;
    std::set<uint64> ColumnGUID;

    uint32 CageTimer;
    uint32 RespawnTimer;

    void Initialize()
    {
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounters[i] = NOT_STARTED;

        MagtheridonGUID = 0;
        ChannelerGUID.clear();
        DoorGUID = 0;
        ColumnGUID.clear();

        CageTimer = 0;
        RespawnTimer = 0;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            if(Encounters[i] == IN_PROGRESS) return true;
        return false;
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature->GetEntry())
        {
        case 17257:
            MagtheridonGUID = creature->GetGUID();
            break;
        case 17256:
            ChannelerGUID.insert(creature->GetGUID());
            break;
        }
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
        case 181713:
            go->SetUInt32Value(GAMEOBJECT_FLAGS, 0);
            break;
        case 183847:
            DoorGUID = go->GetGUID();
            break;
        case 184653: // hall
        case 184634: // six columns
        case 184635:
        case 184636:
        case 184637:
        case 184638:
        case 184639:
            ColumnGUID.insert(go->GetGUID());
            break;
        }
    }

    uint64 GetData64(uint32 type)
    {
        switch(type)
        {
        case DATA_MAGTHERIDON:
            return MagtheridonGUID;
        }
        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_MAGTHERIDON_EVENT:
            Encounters[0] = data;
            if(data == NOT_STARTED)
                RespawnTimer = 10000;
            if(data != IN_PROGRESS)
            {
                if(GameObject *Door = instance->GetGameObjectInMap(DoorGUID))
                    Door->SetGoState(0);
            }
            break;
        case DATA_CHANNELER_EVENT:
            switch(data)
            {
            case NOT_STARTED: // Reset all channelers once one is reset.
                if(Encounters[1] != NOT_STARTED)
                {
                    Encounters[1] = NOT_STARTED;
                    for(std::set<uint64>::iterator i = ChannelerGUID.begin(); i != ChannelerGUID.end(); ++i)
                    {
                        if(Creature *Channeler = instance->GetCreatureInMap(*i))
                        {
                            if(Channeler->isAlive())
                                Channeler->AI()->EnterEvadeMode();
                            else
                                Channeler->Respawn();
                        }
                    }
                    CageTimer = 0;
                    if(GameObject *Door = instance->GetGameObjectInMap(DoorGUID))
                        Door->SetGoState(0);
                }break;
            case IN_PROGRESS: // Event start.
                if(Encounters[1] != IN_PROGRESS)
                {
                    Encounters[1] = IN_PROGRESS;
                    // Let all five channelers aggro.
                    for(std::set<uint64>::iterator i = ChannelerGUID.begin(); i != ChannelerGUID.end(); ++i)
                    {
                        Creature *Channeler = instance->GetCreatureInMap(*i);
                        if(Channeler && Channeler->isAlive())
                            Channeler->AI()->AttackStart(Channeler->SelectNearestTarget(999));
                    }
                    // Release Magtheridon after two minutes.
                    Creature *Magtheridon = instance->GetCreatureInMap(MagtheridonGUID);
                    if(Magtheridon && Magtheridon->isAlive())
                    {
                        Magtheridon->MonsterTextEmote("'s bonds begin to weaken!", 0);
                        CageTimer = 120000;
                    }
                    if(GameObject *Door = instance->GetGameObjectInMap(DoorGUID))
                        Door->SetGoState(1);
                }break;
            case DONE: // Add buff and check if all channelers are dead.
                for(std::set<uint64>::iterator i = ChannelerGUID.begin(); i != ChannelerGUID.end(); ++i)
                {
                    Creature *Channeler = instance->GetCreatureInMap(*i);
                    if(Channeler && Channeler->isAlive())
                    {
                        //Channeler->CastSpell(Channeler, SPELL_SOUL_TRANSFER, true);
                        data = IN_PROGRESS;
                        break;
                    }
                }break;
            }
            Encounters[1] = data;
            break;
        case DATA_COLLAPSE:
            // true - collapse / false - reset
            for(std::set<uint64>::iterator i = ColumnGUID.begin(); i != ColumnGUID.end(); ++i)
            {
                if(GameObject *Column = instance->GetGameObjectInMap(*i))
                    Column->SetGoState(!data);
            }
            break;
        default:
            break;
        }
    }

    uint32 GetData(uint32 type)
    {
        if(type == DATA_MAGTHERIDON_EVENT)
            return Encounters[0];
        return 0;
    }

    void Update(uint32 diff)
    {
        if(CageTimer)
        {
            if(CageTimer <= diff)
            {
                Creature *Magtheridon = instance->GetCreatureInMap(MagtheridonGUID);
                if(Magtheridon && Magtheridon->isAlive())
                {
                    Magtheridon->clearUnitState(UNIT_STAT_STUNNED);
                    Magtheridon->AI()->AttackStart(Magtheridon->SelectNearestTarget(999));
                }
                CageTimer = 0;
            }else CageTimer -= diff;
        }

        if(RespawnTimer)
        {
            if(RespawnTimer <= diff)
            {
                for(std::set<uint64>::iterator i = ChannelerGUID.begin(); i != ChannelerGUID.end(); ++i)
                {
                    if(Creature *Channeler = instance->GetCreatureInMap(*i))
                    {
                        if(Channeler->isAlive())
                            Channeler->AI()->EnterEvadeMode();
                        else
                            Channeler->Respawn();
                    }
                }
                RespawnTimer = 0;
            }else RespawnTimer -= diff;
        }
    }
};

InstanceData* GetInstanceData_instance_magtheridons_lair(Map* map)
{
    return new instance_magtheridons_lair(map);
}

void AddSC_instance_magtheridons_lair()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_magtheridons_lair";
    newscript->GetInstanceData = &GetInstanceData_instance_magtheridons_lair;
    newscript->RegisterSelf();
}

