/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "AreaBoundary.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "utgarde_pinnacle.h"

BossBoundaryData const boundaries =
{
    { DATA_KING_YMIRON, new RectangleBoundary(340.0f, 443.0f, -412.0f, -275.0f) }
};

DoorData const doorData[] =
{
    { GO_SKADI_THE_RUTHLESS_DOOR,   DATA_SKADI_THE_RUTHLESS,    DOOR_TYPE_PASSAGE },
    { GO_KING_YMIRON_DOOR,          DATA_KING_YMIRON,           DOOR_TYPE_PASSAGE },
    { 0,                            0,                          DOOR_TYPE_ROOM } // END
};

class instance_utgarde_pinnacle : public InstanceMapScript
{
    public:
        instance_utgarde_pinnacle() : InstanceMapScript(UPScriptName, 575) { }

        struct instance_utgarde_pinnacle_InstanceMapScript : public InstanceScript
        {
            instance_utgarde_pinnacle_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
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
                    case NPC_GRAUF:
                        GraufGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
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
                            HandleGameObject(ObjectGuid::Empty, true, go);
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

            void OnGameObjectRemove(GameObject* go) override
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

            void SetGuidData(uint32 type, ObjectGuid data) override
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

            ObjectGuid GetGuidData(uint32 type) const override
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
                    case DATA_GRAUF:
                        return GraufGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

        protected:
            ObjectGuid SvalaSorrowgraveGUID;
            ObjectGuid GortokPalehoofGUID;
            ObjectGuid SkadiTheRuthlessGUID;
            ObjectGuid KingYmironGUID;

            ObjectGuid UtgardeMirrorGUID;
            ObjectGuid GortokPalehoofSphereGUID;

            ObjectGuid FrenziedWorgenGUID;
            ObjectGuid RavenousFurbolgGUID;
            ObjectGuid FerociousRhinoGUID;
            ObjectGuid MassiveJormungarGUID;

            ObjectGuid PalehoofOrbGUID;

            ObjectGuid SvalaGUID;
            ObjectGuid SacrificedPlayerGUID;

            ObjectGuid GraufGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_utgarde_pinnacle_InstanceMapScript(map);
        }
};

void AddSC_instance_utgarde_pinnacle()
{
    new instance_utgarde_pinnacle();
}
