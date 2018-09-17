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
    { BOSS_GENERAL_UMBRISS,                 DATA_GENERAL_UMBRISS                },
    { BOSS_FORGEMASTER_THRONGUS,            DATA_FORGEMASTER_THRONGUS           },
    { BOSS_DRAHGA_SHADOWBURNER,             DATA_DRAHGA_SHADOWBURNER            },
    { BOSS_ERUDAX,                          DATA_ERUDAX                         },
    { NPC_VALIONA,                          DATA_VALIONA                        },
    { NPC_FACELESS_PORTAL_STALKER,          DATA_FACELESS_PORTAL_STALKER        },
    { NPC_SHADOW_GALE_STALKER,              DATA_SHADOW_GALE_STALKER            },
    { NPC_SHADOW_GALE_CONTROLLER_STALKER,   DATA_SHADOW_GALE_CONTROLLER_STALKER },
    { NPC_FACELESS_CORRUPTOR_1,             DATA_FACELESS_CORRUPTOR_1           },
    { NPC_FACELESS_CORRUPTOR_2,             DATA_FACELESS_CORRUPTOR_2           },
    { 0,                                    0                                   } // End
};

class instance_grim_batol : public InstanceMapScript
{
    public:
        instance_grim_batol() : InstanceMapScript(GBScriptName, 670) { }

        struct instance_grim_batol_InstanceMapScript : public InstanceScript
        {
            instance_grim_batol_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
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
                    case NPC_HATCHED_TWILIGHT_EGG:
                        if (Creature* erudax = GetCreature(DATA_ERUDAX))
                            erudax->AI()->JustSummoned(creature);
                        break;
                    case NPC_TWILIGHT_HATCHLING:
                        creature->SetReactState(REACT_PASSIVE);
                        if (Creature* erudax = GetCreature(DATA_ERUDAX))
                            erudax->AI()->JustSummoned(creature);

                        if (Creature* stalker = GetCreature(DATA_SHADOW_GALE_CONTROLLER_STALKER))
                            creature->GetMotionMaster()->MoveCirclePath(stalker->GetPositionX(), stalker->GetPositionY(), 253.845f, 30.0f, true, 8);
                        break;
                    case NPC_ALEXSTRASZAS_EGG:
                        creature->SetCorpseDelay(DAY);
                        creature->SetHealth(creature->GetMaxHealth());
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
                        {
                            for (ObjectGuid guid : alexstraszasEggGuidList)
                                if (Creature* egg = instance->GetCreature(guid))
                                    egg->DespawnOrUnsummon(0, 30s);

                            alexstraszasEggGuidList.clear();
                        }
                        else if (state == DONE)
                            for (ObjectGuid guid : alexstraszasEggGuidList)
                                if (Creature* egg = instance->GetCreature(guid))
                                    egg->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
                return true;
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
