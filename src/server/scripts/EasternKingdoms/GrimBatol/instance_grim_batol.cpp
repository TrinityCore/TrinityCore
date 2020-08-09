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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "grim_batol.h"
#include "Creature.h"
#include "EventMap.h"
#include "Map.h"
#include "ScriptMgr.h"
#include "MotionMaster.h"
#include "CreatureAI.h"

ObjectData const creatureData[] =
{
    { BOSS_GENERAL_UMBRISS,                 DATA_GENERAL_UMBRISS                },
    { BOSS_FORGEMASTER_THRONGUS,            DATA_FORGEMASTER_THRONGUS           },
    { BOSS_DRAHGA_SHADOWBURNER,             DATA_DRAHGA_SHADOWBURNER            },
    { BOSS_ERUDAX,                          DATA_ERUDAX                         },
    { NPC_VALIONA,                          DATA_VALIONA                        },
    { NPC_FACELESS_PORTAL_STALKER,          DATA_FACELESS_PORTAL_STALKER        },
    { 0,                                    0                                   } // End
};

enum Events
{
    EVENT_DESPAWN_BATTERED_RED_DRAKES = 1
};

enum BatteredDrakeStates
{
    STATE_EMPRISONED    = 0,
    STATE_FREED         = 1,
    STATE_DESPAWNED     = 2
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
                _initialized = false;
                _destroyedNets = 0;
                _batteredRedDrakeState = STATE_EMPRISONED;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (_initialized)
                    return;

                if (_batteredRedDrakeState != STATE_DESPAWNED)
                    instance->SummonCreatureGroup(SUMMON_GROUP_BATTERED_DRAKES);

                _initialized = true;
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
                    case NPC_TWILIGHT_HATCHLING:
                        if (Creature* erudax = GetCreature(DATA_ERUDAX))
                            erudax->AI()->JustSummoned(creature);
                        break;
                    case NPC_ALEXSTRASZAS_EGG:
                        creature->SetCorpseDelay(DAY);
                        creature->SetHealth(creature->GetMaxHealth());
                        _alexstraszasEggGuidSet.insert(creature->GetGUID());
                        break;
                    case NPC_BATTERED_RED_DRAKE_BOMBARDMENT:
                        _batteredRedDrakeGuidSet.insert(creature->GetGUID());
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
                                portal->CastSpell(portal, SPELL_PORTAL_VISUAL);
                            else
                                portal->RemoveAurasDueToSpell(SPELL_PORTAL_VISUAL);
                        }
                        if (state == FAIL)
                        {
                            for (ObjectGuid guid : _alexstraszasEggGuidSet)
                                if (Creature* egg = instance->GetCreature(guid))
                                    egg->DespawnOrUnsummon(0, 30s);

                            _alexstraszasEggGuidSet.clear();
                        }
                        else if (state == DONE)
                            for (ObjectGuid guid : _alexstraszasEggGuidSet)
                                if (Creature* egg = instance->GetCreature(guid))
                                    egg->DespawnOrUnsummon();
                        break;
                    default:
                        break;
                }
                return true;
            }

            void OnUnitDeath(Unit* victim) override
            {
                if (victim->GetTypeId() != TYPEID_UNIT)
                    return;

                switch (victim->GetEntry())
                {
                    case NPC_NET:
                        _destroyedNets++;
                        if (_destroyedNets == 5)
                        {
                            _batteredRedDrakeState = STATE_FREED;
                            SaveToDB();
                        }
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_BATTERED_RED_DRAKE_STATE:
                        return _batteredRedDrakeState;
                }
                return 0;
            }

            void SetData(uint32 type, uint32 /*data*/) override
            {
                switch (type)
                {
                    case DATA_START_BATTERED_RED_DRAKE_DESPAWN_EVENT:
                        _batteredRedDrakeState = STATE_DESPAWNED;
                        SaveToDB();
                        if (!_events.GetTimeUntilEvent(EVENT_DESPAWN_BATTERED_RED_DRAKES))
                            _events.ScheduleEvent(EVENT_DESPAWN_BATTERED_RED_DRAKES, 3min);
                        break;
                    default:
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_DESPAWN_BATTERED_RED_DRAKES:
                        {
                            for (ObjectGuid guid : _batteredRedDrakeGuidSet)
                            {
                                if (Creature* drake = instance->GetCreature(guid))
                                    if (!drake->GetCharmerOrOwnerPlayerOrPlayerItself())
                                        drake->DespawnOrUnsummon();
                            }
                            break;
                        }
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _batteredRedDrakeState;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _batteredRedDrakeState;
            }

        private:
            GuidSet _alexstraszasEggGuidSet;
            GuidSet _batteredRedDrakeGuidSet;
            uint8 _batteredRedDrakeState;
            uint8 _destroyedNets;
            bool _initialized;
            EventMap _events;
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
