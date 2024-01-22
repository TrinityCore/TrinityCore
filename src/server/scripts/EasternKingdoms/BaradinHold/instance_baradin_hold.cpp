/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
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
#include "baradin_hold.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"

DoorData const doorData[] =
{
    { GO_ARGALOTH_DOOR,  BOSS_ARGALOTH, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_OCCUTHAR_DOOR,  BOSS_OCCUTHAR, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_ALIZABAL_DOOR,  BOSS_ALIZABAL, EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                 0,             EncounterDoorBehavior::OpenWhenNotInProgress }  // END
};

ObjectData const creatureData[] =
{
    { NPC_ARGALOTH, BOSS_ARGALOTH   },
    { NPC_OCCUTHAR, BOSS_OCCUTHAR   },
    { NPC_ALIZABAL, BOSS_ALIZABAL   },
    { 0,            0               } // END
};

DungeonEncounterData const encounters[] =
{
    { BOSS_ARGALOTH, {{ 1033 }} },
    { BOSS_OCCUTHAR, {{ 1250 }} },
    { BOSS_ALIZABAL, {{ 1332 }} }
};

class instance_baradin_hold: public InstanceMapScript
{
    public:
        instance_baradin_hold() : InstanceMapScript(BHScriptName, 757) { }

        struct instance_baradin_hold_InstanceMapScript: public InstanceScript
        {
            instance_baradin_hold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
                LoadDungeonEncounterData(encounters);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch(creature->GetEntry())
                {
                    case NPC_FEL_FLAMES:
                        _felFlameGUIDs.push_back(creature->GetGUID());
                        creature->m_Events.AddEventAtOffset([creature]() { creature->CastSpell(nullptr, SPELL_FEL_FLAMES); }, 1s);
                        break;
                    default:
                        break;
                }
            }

            void SetData(uint32 type, uint32 /*value*/) override
            {
                switch (type)
                {
                    case DATA_EXTINUISH_FEL_FLAMES:
                        for (ObjectGuid const& guid : _felFlameGUIDs)
                            if (Creature* felFlame = instance->GetCreature(guid))
                                felFlame->RemoveAllAuras();

                        _felFlameGUIDs.clear();
                        break;
                    default:
                        break;
                }
            }

        private:
            std::vector<ObjectGuid> _felFlameGUIDs;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_baradin_hold_InstanceMapScript(map);
        }
};

void AddSC_instance_baradin_hold()
{
    new instance_baradin_hold();
}
