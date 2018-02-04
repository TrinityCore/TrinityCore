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
    { BOSS_GENERAL_UMBRISS,         DATA_GENERAL_UMBRISS            },
    { BOSS_FORGEMASTER_THRONGUS,    DATA_FORGEMASTER_THRONGUS       },
    { BOSS_DRAHGA_SHADOWBURNER,     DATA_DRAHGA_SHADOWBURNER        },
    { BOSS_ERUDAX,                  DATA_ERUDAX                     },
    { NPC_VALIONA,                  DATA_VALIONA                    },
    { NPC_FACELESS_PORTAL_STALKER,  DATA_FACELESS_PORTAL_STALKER    },
    { NPC_SHADOW_GALE_STALKER,      DATA_SHADOW_GALE_STALKER        },
    { 0,                            0                               } // End
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
                    case NPC_CAVE_IN_STALKER:
                    case NPC_FIXATE_STALKER:
                        if (Creature* throngus = GetCreature(DATA_FORGEMASTER_THRONGUS))
                            throngus->AI()->JustSummoned(creature);
                        break;
                    case NPC_INVOKED_FLAMING_SPIRIT:
                    case NPC_SEEPING_TWILIGHT:
                    case NPC_DEVOURING_FLAMES:
                        if (Creature* drahga = GetCreature(DATA_DRAHGA_SHADOWBURNER))
                            drahga->AI()->JustSummoned(creature);
                        break;
                    case NPC_SHADOW_GALE_STALKER:
                        if (Creature* erudax = GetCreature(DATA_ERUDAX))
                            erudax->AI()->JustSummoned(creature);
                        break;
                    case NPC_ALEXSTRASZAS_EGG:
                        alexstraszasEggGuidList.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_ERUDAX:
                        if (Creature* portal = GetCreature(DATA_FACELESS_PORTAL_STALKER))
                        {
                            if (state == IN_PROGRESS)
                                portal->CastSpell(portal, SPELL_PORTAL_VISUAL, true);
                            else
                                portal->RemoveAurasDueToSpell(SPELL_PORTAL_VISUAL);
                        }
                        if (state == FAIL)
                            for (auto itr = alexstraszasEggGuidList.begin(); itr != alexstraszasEggGuidList.end(); itr++)
                                if (Creature* egg = instance->GetCreature((*itr)))
                                    egg->Respawn();
                        break;
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 data, uint32 value) override
            {
            }

        private:
            GuidSet alexstraszasEggGuidList;
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
