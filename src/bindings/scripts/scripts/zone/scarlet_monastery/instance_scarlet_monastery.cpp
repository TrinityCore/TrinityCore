/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>.sourceforge.net/>
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
SDName: Instance_Scarlet_Monastery
SD%Complete: 50
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "precompiled.h"
#include "def_scarlet_monastery.h"
#include "sc_creature.h"

#define ENTRY_PUMPKIN_SHRINE    186267
#define ENTRY_HORSEMAN          23682
#define ENTRY_HEAD              23775
#define ENTRY_PUMPKIN           23694

#define ENCOUNTERS 1

struct TRINITY_DLL_DECL instance_scarlet_monastery : public ScriptedInstance
{
    instance_scarlet_monastery(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 PumpkinShrineGUID;
    uint64 HorsemanGUID;
    uint64 HeadGUID;
    std::set<uint64> HorsemanAdds;

    uint64 MograineGUID;
    uint64 WhitemaneGUID;
    uint64 VorrelGUID;
    uint64 DoorHighInquisitorGUID;

    uint32 Encounter[ENCOUNTERS];

    void Initialize()
    {
        PumpkinShrineGUID  = 0;
        HorsemanGUID = 0;
        HeadGUID = 0;
        HorsemanAdds.clear();

        MograineGUID = 0;
        WhitemaneGUID = 0;
        VorrelGUID = 0;
        DoorHighInquisitorGUID = 0;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        switch(go->GetEntry())
        {
        case ENTRY_PUMPKIN_SHRINE: PumpkinShrineGUID = go->GetGUID();break;
        case 104600: DoorHighInquisitorGUID = go->GetGUID(); break;
        }
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case ENTRY_HORSEMAN:    HorsemanGUID = creature->GetGUID(); break;
            case ENTRY_HEAD:        HeadGUID = creature->GetGUID(); break;
            case ENTRY_PUMPKIN:     HorsemanAdds.insert(creature->GetGUID());break;
            case 3976: MograineGUID = creature->GetGUID(); break;
            case 3977: WhitemaneGUID = creature->GetGUID(); break;
            case 3981: VorrelGUID = creature->GetGUID(); break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case TYPE_MOGRAINE_AND_WHITE_EVENT:
            if (data == IN_PROGRESS)
                DoUseDoorOrButton(DoorHighInquisitorGUID);
            if (data == FAIL)
                DoUseDoorOrButton(DoorHighInquisitorGUID);

            Encounter[0] = data;
            break;
        case GAMEOBJECT_PUMPKIN_SHRINE:
            HandleGameObject(PumpkinShrineGUID, false);
            break;
        case DATA_HORSEMAN_EVENT:
            if (data == DONE)
            {
                for(std::set<uint64>::iterator itr = HorsemanAdds.begin(); itr != HorsemanAdds.end(); ++itr)
                {
                    Creature* add = instance->GetCreature(*itr);
                    if(add && add->isAlive())
                        add->DealDamage(add, add->GetMaxHealth(), NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                }
                HorsemanAdds.clear();
                HandleGameObject(PumpkinShrineGUID, false);
            }
            break;
        }
    }

    uint64 GetData64(uint32 type)
    {
        switch(type)
        {
            //case GAMEOBJECT_PUMPKIN_SHRINE:   return PumpkinShrineGUID;
            //case DATA_HORSEMAN:               return HorsemanGUID;
            //case DATA_HEAD:                   return HeadGUID;
            case DATA_MOGRAINE:             return MograineGUID;
            case DATA_WHITEMANE:            return WhitemaneGUID;
            case DATA_VORREL:               return VorrelGUID;
            case DATA_DOOR_WHITEMANE:       return DoorHighInquisitorGUID;
        }
        return 0;
    }

    uint32 GetData(uint32 type)
    {
        if (type == TYPE_MOGRAINE_AND_WHITE_EVENT)
            return Encounter[0];

        return 0;
    }
};

InstanceData* GetInstanceData_instance_scarlet_monastery(Map* map)
{
    return new instance_scarlet_monastery(map);
}

void AddSC_instance_scarlet_monastery()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_scarlet_monastery";
    newscript->GetInstanceData = &GetInstanceData_instance_scarlet_monastery;
    newscript->RegisterSelf();
}

