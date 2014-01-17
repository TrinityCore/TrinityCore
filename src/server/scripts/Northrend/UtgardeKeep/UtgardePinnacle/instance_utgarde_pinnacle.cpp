/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "utgarde_pinnacle.h"

DoorData const doorData[] =
{
    { GO_SKADI_THE_RUTHLESS_DOOR,   DATA_SKADI_THE_RUTHLESS,    DOOR_TYPE_PASSAGE,  BOUNDARY_W    },
    { GO_KING_YMIRON_DOOR,          DATA_KING_YMIRON,           DOOR_TYPE_PASSAGE,  BOUNDARY_N    },
    { 0,                            0,                          DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

class instance_utgarde_pinnacle : public InstanceMapScript
{
    public:
        instance_utgarde_pinnacle() : InstanceMapScript(UPScriptName, 575) { }

        struct instance_utgarde_pinnacle_InstanceMapScript : public InstanceScript
        {
            instance_utgarde_pinnacle_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                SvalaSorrowgraveGUID        = 0;
                GortokPalehoofGUID          = 0;
                SkadiTheRuthlessGUID        = 0;
                KingYmironGUID              = 0;

                UtgardeMirrorGUID           = 0;
                GortokPalehoofSphereGUID    = 0;

                FrenziedWorgenGUID          = 0;
                RavenousFurbolgGUID         = 0;
                FerociousRhinoGUID          = 0;
                MassiveJormungarGUID        = 0;
                PalehoofOrbGUID             = 0;

                SvalaGUID                   = 0;
                SacrificedPlayerGUID        = 0;
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case NPC_SVALA_SORROWGRAVE:
                        SvalaSorrowgraveGUID = creature->GetGUID();
                        break;
                    case NPC_GORTOK_PALEHOOF:
                        GortokPalehoofGUID = creature->GetGUID();
                        break;
                    case NPC_SKADI_THE_RUTHLESS:
                        SkadiTheRuthlessGUID = creature->GetGUID();
                        break;
                    case NPC_KING_YMIRON:
                        KingYmironGUID = creature->GetGUID();
                        break;
                    case NPC_FRENZIED_WORGEN:
                        FrenziedWorgenGUID = creature->GetGUID();
                        break;
                    case NPC_RAVENOUS_FURBOLG:
                        RavenousFurbolgGUID = creature->GetGUID();
                        break;
                    case NPC_MASSIVE_JORMUNGAR:
                        MassiveJormungarGUID = creature->GetGUID();
                        break;
                    case NPC_FEROCIOUS_RHINO:
                        FerociousRhinoGUID = creature->GetGUID();
                        break;
                    case NPC_SVALA:
                        SvalaGUID = creature->GetGUID();
                        break;
                    case NPC_PALEHOOF_ORB:
                        PalehoofOrbGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_UTGARDE_MIRROR:
                        UtgardeMirrorGUID = go->GetGUID();
                        break;
                    case GO_GORTOK_PALEHOOF_SPHERE:
                        GortokPalehoofSphereGUID = go->GetGUID();
                        if (GetBossState(DATA_GORTOK_PALEHOOF) == DONE)
                        {
                            HandleGameObject(0, true, go);
                            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        }
                        break;
                    case GO_SKADI_THE_RUTHLESS_DOOR:
                    case GO_KING_YMIRON_DOOR:
                        AddDoor(go, true);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_SKADI_THE_RUTHLESS_DOOR:
                    case GO_KING_YMIRON_DOOR:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            void SetData64(uint32 type, uint64 data) OVERRIDE
            {
                switch (type)
                {
                    case DATA_SACRIFICED_PLAYER:
                        SacrificedPlayerGUID = data;
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_SVALA_SORROWGRAVE:
                        return SvalaSorrowgraveGUID;
                    case DATA_GORTOK_PALEHOOF:
                        return GortokPalehoofGUID;
                    case DATA_SKADI_THE_RUTHLESS:
                        return SkadiTheRuthlessGUID;
                    case DATA_KING_YMIRON:
                        return KingYmironGUID;
                    case DATA_FRENZIED_WORGEN:
                        return FrenziedWorgenGUID;
                    case DATA_RAVENOUS_FURBOLG:
                        return RavenousFurbolgGUID;
                    case DATA_MASSIVE_JORMUNGAR:
                        return MassiveJormungarGUID;
                    case DATA_FEROCIOUS_RHINO:
                        return FerociousRhinoGUID;
                    case DATA_GORTOK_ORB:
                        return PalehoofOrbGUID;
                    case DATA_GORTOK_PALEHOOF_SPHERE:
                        return GortokPalehoofSphereGUID;
                    case DATA_UTGARDE_MIRROR:
                        return UtgardeMirrorGUID;
                    case DATA_SVALA:
                        return SvalaGUID;
                    case DATA_SACRIFICED_PLAYER:
                        return SacrificedPlayerGUID;
                    default:
                        break;
                }

                return 0;
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "U P " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) OVERRIDE
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'U' && dataHead2 == 'P')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 SvalaSorrowgraveGUID;
            uint64 GortokPalehoofGUID;
            uint64 SkadiTheRuthlessGUID;
            uint64 KingYmironGUID;

            uint64 UtgardeMirrorGUID;
            uint64 GortokPalehoofSphereGUID;

            uint64 FrenziedWorgenGUID;
            uint64 RavenousFurbolgGUID;
            uint64 FerociousRhinoGUID;
            uint64 MassiveJormungarGUID;

            uint64 PalehoofOrbGUID;

            uint64 SvalaGUID;
            uint64 SacrificedPlayerGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_utgarde_pinnacle_InstanceMapScript(map);
        }
};

void AddSC_instance_utgarde_pinnacle()
{
    new instance_utgarde_pinnacle();
}
