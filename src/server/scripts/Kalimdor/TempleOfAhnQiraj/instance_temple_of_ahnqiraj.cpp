/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_Temple_of_Ahnqiraj
SD%Complete: 80
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "temple_of_ahnqiraj.h"

class instance_temple_of_ahnqiraj : public InstanceMapScript
{
    public:
        instance_temple_of_ahnqiraj() : InstanceMapScript("instance_temple_of_ahnqiraj", 531) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_temple_of_ahnqiraj_InstanceMapScript(map);
        }

        struct instance_temple_of_ahnqiraj_InstanceMapScript : public InstanceScript
        {
            instance_temple_of_ahnqiraj_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                IsBossDied[0] = false;
                IsBossDied[1] = false;
                IsBossDied[2] = false;

                BugTrioDeathCount = 0;

                CthunPhase = 0;
            }

            //If Vem is dead...
            bool IsBossDied[3];

            //Storing Skeram, Vem and Kri.
            ObjectGuid SkeramGUID;
            ObjectGuid VemGUID;
            ObjectGuid KriGUID;
            ObjectGuid VeklorGUID;
            ObjectGuid VeknilashGUID;
            ObjectGuid ViscidusGUID;

            uint32 BugTrioDeathCount;

            uint32 CthunPhase;

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                case NPC_SKERAM:
                    SkeramGUID = creature->GetGUID();
                    break;
                case NPC_VEM:
                    VemGUID = creature->GetGUID();
                    break;
                case NPC_KRI:
                    KriGUID = creature->GetGUID();
                    break;
                case NPC_VEKLOR:
                    VeklorGUID = creature->GetGUID();
                    break;
                case NPC_VEKNILASH:
                    VeknilashGUID = creature->GetGUID();
                    break;
                case NPC_VISCIDUS:
                    ViscidusGUID = creature->GetGUID();
                    break;
                }
            }

            bool IsEncounterInProgress() const override
            {
                //not active in AQ40
                return false;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                case DATA_VEMISDEAD:
                    if (IsBossDied[0])
                        return 1;
                    break;

                case DATA_VEKLORISDEAD:
                    if (IsBossDied[1])
                        return 1;
                    break;

                case DATA_VEKNILASHISDEAD:
                    if (IsBossDied[2])
                        return 1;
                    break;

                case DATA_BUG_TRIO_DEATH:
                    return BugTrioDeathCount;

                case DATA_CTHUN_PHASE:
                    return CthunPhase;
                }
                return 0;
            }

            ObjectGuid GetGuidData(uint32 identifier) const override
            {
                switch (identifier)
                {
                case DATA_SKERAM:
                    return SkeramGUID;
                case DATA_VEM:
                    return VemGUID;
                case DATA_KRI:
                    return KriGUID;
                case DATA_VEKLOR:
                    return VeklorGUID;
                case DATA_VEKNILASH:
                    return VeknilashGUID;
                case DATA_VISCIDUS:
                    return ViscidusGUID;
                }
                return ObjectGuid::Empty;
            }                                                       // end GetGuidData

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                case DATA_VEM_DEATH:
                    IsBossDied[0] = true;
                    break;

                case DATA_BUG_TRIO_DEATH:
                    ++BugTrioDeathCount;
                    break;

                case DATA_VEKLOR_DEATH:
                    IsBossDied[1] = true;
                    break;

                case DATA_VEKNILASH_DEATH:
                    IsBossDied[2] = true;
                    break;

                case DATA_CTHUN_PHASE:
                    CthunPhase = data;
                    break;
                }
            }
        };

};

void AddSC_instance_temple_of_ahnqiraj()
{
    new instance_temple_of_ahnqiraj();
}
