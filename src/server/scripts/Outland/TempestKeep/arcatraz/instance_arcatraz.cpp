/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_Arcatraz
SD%Complete: 80
SDComment: Mainly Harbringer Skyriss event
SDCategory: Tempest Keep, The Arcatraz
EndScriptData */

#include "ScriptPCH.h"
#include "arcatraz.h"

#define MAX_ENCOUNTER 9

enum eUnits
{
    CONTAINMENT_CORE_SECURITY_FIELD_ALPHA = 184318,//door opened when Wrath-Scryer Soccothrates dies
    CONTAINMENT_CORE_SECURITY_FIELD_BETA  = 184319,//door opened when Dalliah the Doomsayer dies
    POD_ALPHA                             = 183961,//pod first boss wave
    POD_BETA                              = 183963,//pod second boss wave
    POD_DELTA                             = 183964,//pod third boss wave
    POD_GAMMA                             = 183962,//pod fourth boss wave
    POD_OMEGA                             = 183965,//pod fifth boss wave
    WARDENS_SHIELD                        = 184802,// warden shield
    SEAL_SPHERE                           = 184802,//shield 'protecting' mellichar

    MELLICHAR                             = 20904,//skyriss will kill this unit
};


/* Arcatraz encounters:
1 - Zereketh the Unbound event
2 - Dalliah the Doomsayer event
3 - Wrath-Scryer Soccothrates event
4 - Harbinger Skyriss event, 5 sub-events
*/

class instance_arcatraz : public InstanceMapScript
{
    public:
        instance_arcatraz()
            : InstanceMapScript("instance_arcatraz", 552)
        {
        }
        struct instance_arcatraz_InstanceMapScript : public InstanceScript
        {
            instance_arcatraz_InstanceMapScript(Map* pMap) : InstanceScript(pMap) { Initialize(); };

            uint32 m_auiEncounter[MAX_ENCOUNTER];

            uint64 Containment_Core_Security_Field_AlphaGUID;
            uint64 Containment_Core_Security_Field_BetaGUID;
            uint64 Pod_AlphaGUID;
            uint64 Pod_GammaGUID;
            uint64 Pod_BetaGUID;
            uint64 Pod_DeltaGUID;
            uint64 Pod_OmegaGUID;
            uint64 Wardens_ShieldGUID;
            uint64 GoSphereGUID;
            uint64 MellicharGUID;

            void Initialize()
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                Containment_Core_Security_Field_AlphaGUID = 0;
                Containment_Core_Security_Field_BetaGUID = 0;
                Pod_AlphaGUID = 0;
                        Pod_GammaGUID = 0;
                        Pod_BetaGUID = 0;
                        Pod_DeltaGUID = 0;
                        Pod_OmegaGUID = 0;
                        Wardens_ShieldGUID = 0;
                        GoSphereGUID = 0;
                        MellicharGUID = 0;
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS) return true;

                return false;
            }


            void OnGameObjectCreate(GameObject* go)
            {
                switch(go->GetEntry())
                {
                case CONTAINMENT_CORE_SECURITY_FIELD_ALPHA: Containment_Core_Security_Field_AlphaGUID = go->GetGUID(); break;
                case CONTAINMENT_CORE_SECURITY_FIELD_BETA:  Containment_Core_Security_Field_BetaGUID =  go->GetGUID(); break;
                case POD_ALPHA:                             Pod_AlphaGUID = go->GetGUID();                             break;
                case POD_GAMMA:                             Pod_GammaGUID = go->GetGUID();                             break;
                case POD_BETA:                              Pod_BetaGUID =  go->GetGUID();                             break;
                case POD_DELTA:                             Pod_DeltaGUID = go->GetGUID();                             break;
                case POD_OMEGA:                             Pod_OmegaGUID = go->GetGUID();                             break;
                case SEAL_SPHERE:                           GoSphereGUID = go->GetGUID();                              break;
                //case WARDENS_SHIELD:                        Wardens_ShieldGUID = go->GetGUID();                        break;
                }
            }

            void OnCreatureCreate(Creature* creature)
            {
                if (creature->GetEntry() == MELLICHAR)
                    MellicharGUID = creature->GetGUID();
            }

            void SetData(uint32 type, uint32 data)
            {
                switch(type)
                {
                case TYPE_ZEREKETH:
                    m_auiEncounter[0] = data;
                    break;
                case TYPE_DALLIAH:
                    if (data == DONE)
                    {
                        if (GameObject* go = instance->GetGameObject(Containment_Core_Security_Field_BetaGUID))
                            go->UseDoorOrButton();
                    }
                    m_auiEncounter[1] = data;
                    break;
                case TYPE_SOCCOTHRATES:
                    if (data == DONE)
                    {
                        if (GameObject* go = instance->GetGameObject(Containment_Core_Security_Field_AlphaGUID))
                            go->UseDoorOrButton();
                    }
                    m_auiEncounter[2] = data;
                    break;
                case TYPE_HARBINGERSKYRISS:
                    if (data == NOT_STARTED || data == FAIL)
                    {
                        m_auiEncounter[4] = NOT_STARTED;
                        m_auiEncounter[5] = NOT_STARTED;
                        m_auiEncounter[6] = NOT_STARTED;
                        m_auiEncounter[7] = NOT_STARTED;
                        m_auiEncounter[8] = NOT_STARTED;
                    }
                    m_auiEncounter[3] = data;
                    break;
                case TYPE_WARDEN_1:
                    if (data == IN_PROGRESS)
                        if (GameObject* go = instance->GetGameObject(Pod_AlphaGUID))
                            go->UseDoorOrButton();
                    m_auiEncounter[4] = data;
                    break;
                case TYPE_WARDEN_2:
                    if (data == IN_PROGRESS)
                    {
                        if (GameObject* go = instance->GetGameObject(Pod_BetaGUID))
                            go->UseDoorOrButton();
                    }
                    m_auiEncounter[5] = data;
                    break;
                case TYPE_WARDEN_3:
                    if (data == IN_PROGRESS)
                    {
                        if (GameObject* go = instance->GetGameObject(Pod_DeltaGUID))
                            go->UseDoorOrButton();
                    }
                    m_auiEncounter[6] = data;
                    break;
                case TYPE_WARDEN_4:
                    if (data == IN_PROGRESS)
                    {
                        if (GameObject* go = instance->GetGameObject(Pod_GammaGUID))
                            go->UseDoorOrButton();
                    }
                    m_auiEncounter[7] = data;
                    break;
                case TYPE_WARDEN_5:
                    if (data == IN_PROGRESS)
                    {
                        if (GameObject* go = instance->GetGameObject(Pod_OmegaGUID))
                            go->UseDoorOrButton();
                    }
                    m_auiEncounter[8] = data;
                    break;
                case TYPE_SHIELD_OPEN:
                    if (data == IN_PROGRESS)
                    {
                        if (GameObject* go = instance->GetGameObject(Wardens_ShieldGUID))
                            go->UseDoorOrButton();
                    }
                    break;
                }
            }

            uint32 GetData(uint32 type)
            {
                switch(type)
                {
                case TYPE_HARBINGERSKYRISS: return m_auiEncounter[3];
                case TYPE_WARDEN_1:         return m_auiEncounter[4];
                case TYPE_WARDEN_2:         return m_auiEncounter[5];
                case TYPE_WARDEN_3:         return m_auiEncounter[6];
                case TYPE_WARDEN_4:         return m_auiEncounter[7];
                case TYPE_WARDEN_5:         return m_auiEncounter[8];
                }
                return 0;
            }

            uint64 GetData64(uint32 data)
            {
                switch(data)
                {
                case DATA_MELLICHAR:        return MellicharGUID;
                case DATA_SPHERE_SHIELD:    return GoSphereGUID;
                }
                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* pMap) const
        {
            return new instance_arcatraz_InstanceMapScript(pMap);
        }
};

void AddSC_instance_arcatraz()
{
    new instance_arcatraz;
}

