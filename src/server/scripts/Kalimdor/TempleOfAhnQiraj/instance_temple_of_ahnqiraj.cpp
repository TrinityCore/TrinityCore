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
SDName: Instance_Temple_of_Ahnqiraj
SD%Complete: 80
SDComment:
SDCategory: Temple of Ahn'Qiraj
EndScriptData */

#include "ScriptPCH.h"
#include "temple_of_ahnqiraj.h"

class instance_temple_of_ahnqiraj : public InstanceMapScript
{
public:
    instance_temple_of_ahnqiraj() : InstanceMapScript("instance_temple_of_ahnqiraj", 531) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_temple_of_ahnqiraj_InstanceMapScript(pMap);
    }

    struct instance_temple_of_ahnqiraj_InstanceMapScript : public InstanceScript
    {
        instance_temple_of_ahnqiraj_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

        //If Vem is dead...
        bool IsBossDied[3];

        //Storing Skeram, Vem and Kri.
        uint64 SkeramGUID;
        uint64 VemGUID;
        uint64 KriGUID;
        uint64 VeklorGUID;
        uint64 VeknilashGUID;

        uint32 BugTrioDeathCount;

        uint32 CthunPhase;

        void Initialize()
        {
            IsBossDied[0] = false;
            IsBossDied[1] = false;
            IsBossDied[2] = false;

            SkeramGUID = 0;
            VemGUID = 0;
            KriGUID = 0;
            VeklorGUID = 0;
            VeknilashGUID = 0;

            BugTrioDeathCount = 0;

            CthunPhase = 0;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case 15263: SkeramGUID = creature->GetGUID(); break;
                case 15544: VemGUID = creature->GetGUID(); break;
                case 15511: KriGUID = creature->GetGUID(); break;
                case 15276: VeklorGUID = creature->GetGUID(); break;
                case 15275: VeknilashGUID = creature->GetGUID(); break;
            }
        }

        bool IsEncounterInProgress() const
        {
            //not active in AQ40
            return false;
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
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

        uint64 GetData64 (uint32 identifier)
        {
            switch(identifier)
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
            }
            return 0;
        }                                                       // end GetData64

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
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
