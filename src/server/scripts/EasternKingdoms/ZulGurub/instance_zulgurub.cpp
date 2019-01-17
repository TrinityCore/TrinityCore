/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "zulgurub.h"

ObjectData const creatureData[] =
{
    { BOSS_HIGH_PRIEST_VENOXIS,         DATA_HIGH_PRIEST_VENOXIS                },
    { BOSS_BLOODLORD_MANDOKIR,          DATA_BLOODLORD_MANDOKIR                 },
    { BOSS_HIGH_PRIESTESS_KILNARA,      DATA_HIGH_PRIESTESS_KILNARA             },
    { BOSS_ZANZIL,                      DATA_ZANZIL                             },
    { BOSS_JINDO_THE_GODBREAKER,        DATA_JINDO_THE_GODBREAKER               },
    { NPC_OHGAN,                        DATA_OHGAN                              },
    { NPC_SPIRIT_OF_HAKKAR,             DATA_SPIRIT_OF_HAKKAR                   },
    { NPC_SHADOW_OF_HAKKAR,             DATA_SHADOW_OF_HAKKAR                   },
    { NPC_JINDO_THE_GODBREAKER,         DATA_JINDO_THE_GODBREAKER_SPIRIT_WORLD  },
    { 0,                                0                                       }  // END
};

DoorData const doorData[] =
{
    { GO_VENOXIS_COIL,                  DATA_HIGH_PRIEST_VENOXIS,       DOOR_TYPE_ROOM },
    { GO_ARENA_DOOR_1,                  DATA_BLOODLORD_MANDOKIR,        DOOR_TYPE_ROOM },
    { GO_FORCEFIELD,                    DATA_HIGH_PRIESTESS_KILNARA,    DOOR_TYPE_ROOM },
    { GO_ZANZIL_DOOR,                   DATA_ZANZIL,                    DOOR_TYPE_ROOM },
    //{ GO_THE_CACHE_OF_MADNESS_DOOR,     DATA_xxxxxxx,                     DOOR_TYPE_ROOM },
    { 0,                                0,                              DOOR_TYPE_ROOM }  // END
};

class instance_zulgurub : public InstanceMapScript
{
    public:
        instance_zulgurub() : InstanceMapScript(ZGScriptName, 859) { }

        struct instance_zulgurub_InstanceMapScript : public InstanceScript
        {
            instance_zulgurub_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDoorData(doorData);
                Initialize();
            }

            void Initialize()
            {
                _defeatedBossesCount = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_VENOMOUS_EFFUSION:
                    case NPC_BLOODVENOM:
                        if (Creature* venoxis = GetCreature(DATA_HIGH_PRIEST_VENOXIS))
                            venoxis->AI()->JustSummoned(creature);
                        break;
                    case NPC_DEVASTATING_SLAM:
                        if (Creature* mandokir = GetCreature(DATA_BLOODLORD_MANDOKIR))
                            mandokir->AI()->JustSummoned(creature);
                        break;
                    case NPC_CAVE_IN_STALKER:
                        _caveInStalkerGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_TOXIC_VENOMSPITTER:
                    case NPC_MUTATED_OVERGROWTH:
                        _poisonPlantGUIDs.push_back(creature->GetGUID());
                        if (GetBossState(DATA_HIGH_PRIEST_VENOXIS) != DONE)
                            creature->CastSpell(creature, SPELL_POISON_CLOUD);
                        break;
                    case BOSS_JINDO_THE_GODBREAKER:
                        creature->setActive(true);

                        if (_defeatedBossesCount >= 2)
                        {
                            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_NOT_SELECTABLE);
                            creature->RemoveAurasDueToSpell(SPELL_COSMETIC_ALPHA_STATE_25_PCT);
                        }
                        break;
                    case NPC_JINDO_THE_GODBREAKER:
                    case NPC_SPIRIT_OF_HAKKAR:
                    case NPC_SHADOW_OF_HAKKAR:
                    case NPC_HAKKARS_CHAINS:
                    case NPC_TWISTED_SPIRIT:
                    case NPC_TWISTED_SHADOW:
                    case NPC_GURUBASHI_SPIRIT_WARRIOR:
                    case NPC_GURUBASHI_SHADOW:
                    case NPC_GURUBASHI_SPIRIT:
                    case NPC_SPIRIT_PORTAL:
                        if (Creature* jindo = GetCreature(DATA_JINDO_THE_GODBREAKER))
                            jindo->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetTypeId() != TYPEID_UNIT)
                    return;

                switch (unit->GetEntry())
                {
                    case NPC_HAKKARS_CHAINS:
                        if (Creature* jindo = GetCreature(DATA_JINDO_THE_GODBREAKER))
                            jindo->AI()->SummonedCreatureDies(unit->ToCreature(), nullptr);
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
                    case DATA_HIGH_PRIEST_VENOXIS:
                        if (state == DONE)
                            for (ObjectGuid guid : _poisonPlantGUIDs)
                                if (Creature* plant = instance->GetCreature(guid))
                                    plant->RemoveAurasDueToSpell(SPELL_POISON_CLOUD);
                        break;
                    default:
                        break;
                }

                if (state == DONE)
                {
                    _defeatedBossesCount++;

                    if (_defeatedBossesCount >= 2)
                        if (Creature* jindo = GetCreature(DATA_JINDO_THE_GODBREAKER))
                            jindo->AI()->DoAction(ACTION_TRIGGER_JINDO_INTRO);

                    SaveToDB();
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_CAST_CAVE_IN_VISUAL:
                        for (ObjectGuid guid : _caveInStalkerGUIDs)
                            if (Creature* stalker = instance->GetCreature(guid))
                                stalker->CastSpell(stalker, SPELL_CAVE_IN_VISUAL, false);
                        break;
                    case DATA_KILLED_GURUBASHI_SPIRIT_WARRIORS:
                        _killedGurubashiSpiritWarriorMask = data;
                        SaveToDB();
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_KILLED_GURUBASHI_SPIRIT_WARRIORS:
                        return _killedGurubashiSpiritWarriorMask;
                    default:
                        return 0;
                }
                return 0;
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _defeatedBossesCount << ' '
                    << _killedGurubashiSpiritWarriorMask;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _defeatedBossesCount;
                data >> _killedGurubashiSpiritWarriorMask;
            }

        private:
            GuidVector _caveInStalkerGUIDs;
            GuidVector _poisonPlantGUIDs;
            uint8 _defeatedBossesCount;
            uint8 _killedGurubashiSpiritWarriorMask;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_zulgurub_InstanceMapScript(map);
        }
};

void AddSC_instance_zulgurub()
{
    new instance_zulgurub();
}
