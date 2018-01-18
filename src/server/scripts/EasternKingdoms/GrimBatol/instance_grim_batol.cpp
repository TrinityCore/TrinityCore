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
#include "InstanceScript.h"
#include "grim_batol.h"

ObjectData const creatureData[] =
{
    { BOSS_GENERAL_UMBRISS,         DATA_GENERAL_UMBRISS        },
    { BOSS_FORGEMASTER_THRONGUS,    DATA_FORGEMASTER_THRONGUS   },
    { BOSS_DRAHGA_SHADOWBURNER,     DATA_DRAHGA_SHADOWBURNER    },
    { BOSS_ERUDAX,                  DATA_ERUDAX                 },
    { 0,                            0                           } // End
};

class instance_grim_batol : public InstanceMapScript
{
    public:
        instance_grim_batol() : InstanceMapScript(GBScriptName, 670) { }

        struct instance_grim_batol_InstanceMapScript : public InstanceScript
        {
            instance_grim_batol_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_BLITZ_STALKER:
                    case NPC_GROUND_SIEGE_STALKER:
                        if (Creature* umbriss = GetCreature(DATA_GENERAL_UMBRISS))
                            umbriss->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            void SetData(uint32 data, uint32 value) override
            {
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_grim_batol_InstanceMapScript(map);
        }
};

void AddSC_instance_grim_batol()
{
    new instance_grim_batol();
}
