/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "AreaBoundary.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "nerubar_palace.h"

ObjectData const creatureData[] =
{
    { BOSS_ULGRAX_THE_DEVOURER,   DATA_ULGRAX_THE_DEVOURER   },
    { BOSS_THE_BLOODBOUND_HORROR, DATA_THE_BLOODBOUND_HORROR },
    { BOSS_SIKRAN,                DATA_SIKRAN                },
    { BOSS_RASHANAN,              DATA_RASHANAN              },
    { BOSS_BROODTWISTER_OVINAX,   DATA_BROODTWISTER_OVINAX   },
    { BOSS_NEXUS_PRINCESS_KYVEZA, DATA_NEXUS_PRINCESS_KYVEZA },
    { BOSS_ANUBARASH,             DATA_THE_SILKEN_COURT      },
    { BOSS_QUEEN_ANSUREK,         DATA_QUEEN_ANSUREK         },
    { 0,                          0                          }  // END
};

DoorData const doorData[] =
{
    { GO_WEB_BRIDGE_ULGRAX_INTRO, DATA_WEB_BRIDGE_ULGRAX_INTRO, EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                          0,                            EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

ObjectData const objectData[] =
{
    { GO_NERUBAR_PALACE_DOOR_INTRO, DATA_NERUBAR_PALACE_DOOR_INTRO },
    { GO_WEB_BRIDGE_ULGRAX_INTRO,   DATA_WEB_BRIDGE_ULGRAX_INTRO   },
    { 0,                            0                              }  // END
};

BossBoundaryData const boundaries =
{
    { DATA_ULGRAX_THE_DEVOURER, new CircleBoundary(Position(-2862.7395f, -251.90973f), 150.0f) }
};

DungeonEncounterData const encounters[] =
{
    { DATA_ULGRAX_THE_DEVOURER,   {{ 2902 }} },
    { DATA_THE_BLOODBOUND_HORROR, {{ 2917 }} },
    { DATA_SIKRAN,                {{ 2898 }} },
    { DATA_RASHANAN,              {{ 2918 }} },
    { DATA_BROODTWISTER_OVINAX,   {{ 2919 }} },
    { DATA_NEXUS_PRINCESS_KYVEZA, {{ 2920 }} },
    { DATA_THE_SILKEN_COURT,      {{ 2921 }} },
    { DATA_QUEEN_ANSUREK,         {{ 2922 }} }
};

class instance_nerubar_palace : public InstanceMapScript
{
public:
    instance_nerubar_palace() : InstanceMapScript(NPScriptName, 2657) { }

    struct instance_nerubar_palace_InstanceMapScript: public InstanceScript
    {
        instance_nerubar_palace_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, objectData);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadDungeonEncounterData(encounters);

            _nerubarPalaceIntroTrashNPCs = 0;
            _ulgraxIntroTrashNPCs = 0;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_WEB_BRIDGE_ULGRAX_INTRO:
                    WebBridgeGUID = go->GetGUID();
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            if (creature->HasStringId("nerubar_palace_intro_trash"))
                _nerubarPalaceIntroTrashNPCs++;

            if (creature->HasStringId("ulgrax_intro_trash"))
                _ulgraxIntroTrashNPCs++;
        }

        void OnUnitDeath(Unit* unit) override
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            if (creature->HasStringId("nerubar_palace_intro_trash"))
            {
                _nerubarPalaceIntroTrashNPCs--;
                if (_nerubarPalaceIntroTrashNPCs > 0)
                    return;

                DoUseDoorOrButton(GetGuidData(DATA_NERUBAR_PALACE_DOOR_INTRO));
            }

            if (creature->HasStringId("ulgrax_intro_trash"))
            {
                _ulgraxIntroTrashNPCs--;
                if (_ulgraxIntroTrashNPCs > 0)
                    return;

                if (GameObject* webBridge = instance->GetGameObject(WebBridgeGUID))
                    webBridge->UseDoorOrButton();
            }
        }

    protected:
        uint8 _nerubarPalaceIntroTrashNPCs;
        uint8 _ulgraxIntroTrashNPCs;
        ObjectGuid WebBridgeGUID;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_nerubar_palace_InstanceMapScript(map);
    }
};

void AddSC_instance_nerubar_palace()
{
    new instance_nerubar_palace();
}
