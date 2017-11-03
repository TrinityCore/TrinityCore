/*
* Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "GameObject.h"
#include "MapInstanced.h"
#include "lost_city_of_the_tolvir.h"
#include "ScriptMgr.h"

enum eScriptText
{
    YELL_FREE = 0,
};

class instance_lost_city_of_the_tolvir : public InstanceMapScript
{
    public:
        instance_lost_city_of_the_tolvir() : InstanceMapScript("instance_lost_city_of_the_tolvir", 755) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_lost_city_of_the_tolvir_InstanceMapScript(map);
        }

        struct instance_lost_city_of_the_tolvir_InstanceMapScript : public InstanceScript
        {
            instance_lost_city_of_the_tolvir_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { Initialize(); }

            uint32 Encounter[MAX_ENCOUNTER];
            ObjectGuid uiTunnelGUID[6];
            uint8 uiTunnelFlag;
            ObjectGuid uiHusamGUID;
            ObjectGuid uiLockmawGUID;
            ObjectGuid uiAughGUID;
            ObjectGuid uiBarimGUID;
            ObjectGuid uiBlazeGUID;
            ObjectGuid uiHarbingerGUID;
            ObjectGuid uiSiamatGUID;
            ObjectGuid uiSiamatPlatformGUID;
            uint32 uiUpdateTimer;
            bool BarimIsDone;

            void Initialize() override
            {
                memset(&Encounter, 0, sizeof(Encounter));
                uiTunnelFlag = 0;
                uiUpdateTimer = 7000;
                BarimIsDone = false;
            }

            void SiamatFree()
            {
                if (GameObject* platform = instance->GetGameObject(uiSiamatPlatformGUID))
                {
                    platform->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED);
                    platform->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                }

                for (int i = 0; i < 6; ++i)
                    if (Creature* tunnel = instance->GetCreature(uiTunnelGUID[i]))
                        tunnel->SetVisible(true);
            }

            void Update(uint32 diff) override
            {
                UpdateOperations(diff);

                if (BarimIsDone)
                {
                    if (uiUpdateTimer <= diff)
                    {
                        BarimIsDone = false;
                        SiamatFree();

                        if (Creature* siamat = instance->GetCreature(uiSiamatGUID))
                            siamat->AI()->Talk(YELL_FREE);
                    }
                    else
                        uiUpdateTimer -= diff;
                    }
            }

            bool IsEncounterInProgress() const override
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (Encounter[i] == IN_PROGRESS) return true;

                return false;
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                if (go->GetEntry() == SIAMAT_PLATFORM)
                {
                    go->setActive(true);
                    uiSiamatPlatformGUID = go->GetGUID();
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_GENERAL_HUSAM:
                        uiHusamGUID = creature->GetGUID();
                        break;
                    case BOSS_LOCKMAW:
                        uiLockmawGUID = creature->GetGUID();
                        break;
                    case BOSS_AUGH:
                        uiAughGUID = creature->GetGUID();
                        break;
                    case BOSS_HIGH_PROPHET_BARIM:
                        uiBarimGUID = creature->GetGUID();
                        break;
                    case BOSS_SIAMAT:
                        uiSiamatGUID = creature->GetGUID();
                        break;
                    case NPC_WIND_TUNNEL:
                    {
                        creature->SetVisible(false);
                        creature->SetCanFly(true);
                        uiTunnelGUID[uiTunnelFlag] = creature->GetGUID();
                        ++uiTunnelFlag;

                        if (uiTunnelFlag >= 6)
                            uiTunnelFlag = 0;
                    break;
                    }
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_GENERAL_HUSAM:      return uiSiamatGUID;
                    case DATA_LOCKMAW:            return uiLockmawGUID;
                    case DATA_AUGH:               return uiAughGUID;
                    case DATA_HIGH_PROPHET_BARIM: return uiBarimGUID;
                    case DATA_BLAZE:              return uiBlazeGUID;
                    case DATA_HARBINGER:          return uiHarbingerGUID;
                    case DATA_SIAMAT:             return uiSiamatGUID;
                }

                return ObjectGuid::Empty;
            }

            uint32 GetData(uint32 type) const override
            {
                return Encounter[type];
            }

            void SetGuidData(uint32 type, ObjectGuid data) override
            {
                switch (type)
                {
                    case DATA_HARBINGER:
                        uiHarbingerGUID = data;
                        break;
                    case DATA_BLAZE:
                        uiBlazeGUID = data;
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                Encounter[type] = data;

                if (type == DATA_HIGH_PROPHET_BARIM && data == DONE)
                    if (Encounter[DATA_SIAMAT] != DONE)
                        BarimIsDone = true;

                if (type == DATA_SIAMAT && data == DONE)
                {
                    SiamatFree();
                }

                if (data == DONE)
                    SaveToDB();
            }
        };
};

void AddSC_instance_lost_city_of_the_tolvir()
{
    new instance_lost_city_of_the_tolvir();
}
