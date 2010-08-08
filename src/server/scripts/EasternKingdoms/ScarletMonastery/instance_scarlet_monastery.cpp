/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
SDName: Instance_Scarlet_Monastery
SD%Complete: 50
SDComment:
SDCategory: Scarlet Monastery
EndScriptData */

#include "ScriptPCH.h"
#include "scarlet_monastery.h"

#define ENTRY_PUMPKIN_SHRINE    186267
#define ENTRY_HORSEMAN          23682
#define ENTRY_HEAD              23775
#define ENTRY_PUMPKIN           23694

#define MAX_ENCOUNTER 2

class instance_scarlet_monastery : public InstanceMapScript
{
public:
    instance_scarlet_monastery() : InstanceMapScript("instance_scarlet_monastery") { }

    InstanceScript* GetInstanceData_InstanceMapScript(Map* pMap)
    {
        return new instance_scarlet_monastery_InstanceMapScript(pMap);
    }

    struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
    {
        instance_scarlet_monastery_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint64 PumpkinShrineGUID;
        uint64 HorsemanGUID;
        uint64 HeadGUID;
        std::set<uint64> HorsemanAdds;

        uint64 MograineGUID;
        uint64 WhitemaneGUID;
        uint64 VorrelGUID;
        uint64 DoorHighInquisitorGUID;

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            PumpkinShrineGUID  = 0;
            HorsemanGUID = 0;
            HeadGUID = 0;
            HorsemanAdds.clear();

            MograineGUID = 0;
            WhitemaneGUID = 0;
            VorrelGUID = 0;
            DoorHighInquisitorGUID = 0;
        }

        void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
        {
            switch(pGo->GetEntry())
            {
            case ENTRY_PUMPKIN_SHRINE: PumpkinShrineGUID = pGo->GetGUID();break;
            case 104600: DoorHighInquisitorGUID = pGo->GetGUID(); break;
            }
        }

        void OnCreatureCreate(Creature* pCreature, bool /*add*/)
        {
            switch(pCreature->GetEntry())
            {
                case ENTRY_HORSEMAN:    HorsemanGUID = pCreature->GetGUID(); break;
                case ENTRY_HEAD:        HeadGUID = pCreature->GetGUID(); break;
                case ENTRY_PUMPKIN:     HorsemanAdds.insert(pCreature->GetGUID());break;
                case 3976: MograineGUID = pCreature->GetGUID(); break;
                case 3977: WhitemaneGUID = pCreature->GetGUID(); break;
                case 3981: VorrelGUID = pCreature->GetGUID(); break;
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

                m_auiEncounter[0] = data;
                break;
            case GAMEOBJECT_PUMPKIN_SHRINE:
                HandleGameObject(PumpkinShrineGUID, false);
                break;
            case DATA_HORSEMAN_EVENT:
                m_auiEncounter[1] = data;
                if (data == DONE)
                {
                    for (std::set<uint64>::const_iterator itr = HorsemanAdds.begin(); itr != HorsemanAdds.end(); ++itr)
                    {
                        Creature* add = instance->GetCreature(*itr);
                        if (add && add->isAlive())
                            add->Kill(add);
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
                return m_auiEncounter[0];
            if (type == DATA_HORSEMAN_EVENT)
                return m_auiEncounter[1];
            return 0;
        }
    };

};


void AddSC_instance_scarlet_monastery()
{
    new instance_scarlet_monastery();
}
