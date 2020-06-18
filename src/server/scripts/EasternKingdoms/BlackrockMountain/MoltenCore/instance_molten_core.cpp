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
#include "molten_core.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

Position const SummonPositions[10] =
{
    {737.850f, -1145.35f, -120.288f, 4.71368f},
    {744.162f, -1151.63f, -119.726f, 4.58204f},
    {751.247f, -1152.82f, -119.744f, 4.49673f},
    {759.206f, -1155.09f, -120.051f, 4.30104f},
    {755.973f, -1152.33f, -120.029f, 4.25588f},
    {731.712f, -1147.56f, -120.195f, 4.95955f},
    {726.499f, -1149.80f, -120.156f, 5.24055f},
    {722.408f, -1152.41f, -120.029f, 5.33087f},
    {718.994f, -1156.36f, -119.805f, 5.75738f},
    {838.510f, -829.840f, -232.000f, 2.00000f},
};

Position const RagnarosTelePos = { 829.159f, -815.773f, -228.972f, 5.30500f };
Position const RagnarosSummonPos = { 838.510f, -829.840f, -232.000f, 2.00000f };

class instance_molten_core : public InstanceMapScript
{
public:
    instance_molten_core() : InstanceMapScript(MCScriptName, 409) { }

    struct instance_molten_core_InstanceMapScript : public InstanceScript
    {
        instance_molten_core_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);
            _executusSchedule = false;
            _ragnarosAddDeaths = 0;
            runesChecked = false;
            runeMap.clear();
        }

        void OnPlayerEnter(Player* /*player*/) override
        {
            if (_executusSchedule)
            {
                SummonMajordomoExecutus();
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_GOLEMAGG_THE_INCINERATOR:
                _golemaggTheIncineratorGUID = creature->GetGUID();
                break;
            case NPC_MAJORDOMO_EXECUTUS:
                _majordomoExecutusGUID = creature->GetGUID();
                break;
            case MCCreatures::NPC_MAGMADAR:
            {
                break;
            }
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_CACHE_OF_THE_FIRELORD:
            {
                _cacheOfTheFirelordGUID = go->GetGUID();
                break;
            }
            case MCGameObjects::GO_MOLTEN_RUNE_1:
            {
                runeMap[1] = go->GetGUID();
                break;
            }
            case MCGameObjects::GO_MOLTEN_RUNE_2:
            {
                runeMap[2] = go->GetGUID();
                break;
            }
            case MCGameObjects::GO_MOLTEN_RUNE_3:
            {
                runeMap[3] = go->GetGUID();
                break;
            }
            case MCGameObjects::GO_MOLTEN_RUNE_4:
            {
                runeMap[4] = go->GetGUID();
                break;
            }
            case MCGameObjects::GO_MOLTEN_RUNE_5:
            {
                runeMap[5] = go->GetGUID();
                break;
            }
            case MCGameObjects::GO_MOLTEN_RUNE_6:
            {
                runeMap[6] = go->GetGUID();
                break;
            }
            case MCGameObjects::GO_MOLTEN_RUNE_7:
            {
                runeMap[7] = go->GetGUID();
                break;
            }
            default:
                break;
            }
        }

        void Update(uint32 diff) override
        {
            if (!runesChecked)
            {
                if (runeMap.size() == 7)
                {
                    CheckRunes();
                }
            }
        }

        void OnUnitJustEngage(Unit* pmMe, Unit* pmTarget) override
        {
            if (pmMe->GetEntry() == MCCreatures::NPC_MAJORDOMO_EXECUTUS || pmMe->GetEntry() == MCCreatures::NPC_FLAMEWAKER_HEALER || pmMe->GetEntry() == MCCreatures::NPC_FLAMEWAKER_ELITE)
            {
                if (Creature* majordomo = pmMe->GetNearbyCreatureWithEntry(MCCreatures::NPC_MAJORDOMO_EXECUTUS, 100.0f))
                {
                    if (!majordomo->IsInCombat())
                    {
                        majordomo->AI()->AttackStart(pmTarget);
                    }
                }
                std::list<Creature*> healers;
                pmMe->GetCreatureListWithEntryInGrid(healers, MCCreatures::NPC_FLAMEWAKER_HEALER, 100.0f);
                if (healers.size() > 0)
                {
                    if (Creature* eachMember = *healers.begin())
                    {
                        if (!eachMember->IsInCombat())
                        {
                            eachMember->AI()->AttackStart(pmTarget);
                        }
                    }
                }
                std::list<Creature*> elites;
                pmMe->GetCreatureListWithEntryInGrid(elites, MCCreatures::NPC_FLAMEWAKER_ELITE, 100.0f);
                if (elites.size() > 0)
                {
                    if (Creature* eachMember = *elites.begin())
                    {
                        if (!eachMember->IsInCombat())
                        {
                            eachMember->AI()->AttackStart(pmTarget);
                        }
                    }
                }
            }

            if (pmMe->GetEntry() == MCCreatures::NPC_GOLEMAGG_THE_INCINERATOR || pmMe->GetEntry() == MCCreatures::NPC_CORE_RAGER)
            {
                if (Creature* gole = pmMe->GetNearbyCreatureWithEntry(MCCreatures::NPC_GOLEMAGG_THE_INCINERATOR, 100.0f))
                {
                    if (!gole->IsInCombat())
                    {
                        gole->AI()->AttackStart(pmTarget);
                    }
                }
                std::list<Creature*> ragers;
                pmMe->GetCreatureListWithEntryInGrid(ragers, MCCreatures::NPC_CORE_RAGER, 100.0f);
                if (ragers.size() > 0)
                {
                    if (Creature* eachRager = *ragers.begin())
                    {
                        if (!eachRager->IsInCombat())
                        {
                            eachRager->AI()->AttackStart(pmTarget);
                        }
                    }
                }
            }
        }

        void OnGameObjectUse(GameObject* pmGO, Unit* pmUserPlayer) override
        {

        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == DATA_RAGNAROS_ADDS)
            {
                if (data == 1)
                    ++_ragnarosAddDeaths;
                else if (data == 0)
                    _ragnarosAddDeaths = 0;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_RAGNAROS_ADDS:
                return _ragnarosAddDeaths;
            }

            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case BOSS_GOLEMAGG_THE_INCINERATOR:
                return _golemaggTheIncineratorGUID;
            case BOSS_MAJORDOMO_EXECUTUS:
                return _majordomoExecutusGUID;
            }

            return ObjectGuid::Empty;
        }

        bool SetBossState(uint32 bossId, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(bossId, state))
                return false;

            if (state == DONE && bossId < BOSS_MAJORDOMO_EXECUTUS)
            {
                if (runeMap.find(bossId) != runeMap.end())
                {
                    if (GameObject* rune = instance->GetGameObject(runeMap[bossId]))
                    {
                        rune->SetGoState(GOState::GO_STATE_READY);
                    }
                }
                if (CheckMajordomoExecutus())
                {
                    SummonMajordomoExecutus();
                }
            }

            if (bossId == BOSS_MAJORDOMO_EXECUTUS && state == DONE)
                DoRespawnGameObject(_cacheOfTheFirelordGUID, 7 * DAY);

            return true;
        }

        void CheckRunes()
        {
            runesChecked = true;
            for (int bossIndex = MCEncounters::BOSS_MAGMADAR; bossIndex < MCEncounters::BOSS_MAJORDOMO_EXECUTUS; bossIndex++)
            {
                GOState activeState = GOState::GO_STATE_ACTIVE;
                if (GetBossState(bossIndex) == EncounterState::DONE)
                {
                    activeState = GOState::GO_STATE_READY;
                }
                if (GameObject* rune = instance->GetGameObject(runeMap[bossIndex]))
                {
                    rune->SetGoState(activeState);
                }
            }
        }

        void SummonMajordomoExecutus()
        {
            _executusSchedule = false;
            if (_majordomoExecutusGUID)
                return;

            if (GetBossState(BOSS_MAJORDOMO_EXECUTUS) != DONE)
            {
                if (TempSummon* majordomo = instance->SummonCreature(NPC_MAJORDOMO_EXECUTUS, SummonPositions[0]))
                {
                    majordomo->AI()->Talk(1);
                }
                instance->SummonCreature(NPC_FLAMEWAKER_HEALER, SummonPositions[1]);
                instance->SummonCreature(NPC_FLAMEWAKER_HEALER, SummonPositions[2]);
                instance->SummonCreature(NPC_FLAMEWAKER_HEALER, SummonPositions[3]);
                instance->SummonCreature(NPC_FLAMEWAKER_HEALER, SummonPositions[4]);
                instance->SummonCreature(NPC_FLAMEWAKER_ELITE, SummonPositions[5]);
                instance->SummonCreature(NPC_FLAMEWAKER_ELITE, SummonPositions[6]);
                instance->SummonCreature(NPC_FLAMEWAKER_ELITE, SummonPositions[7]);
                instance->SummonCreature(NPC_FLAMEWAKER_ELITE, SummonPositions[8]);
            }
            else if (TempSummon* summon = instance->SummonCreature(NPC_MAJORDOMO_EXECUTUS, RagnarosTelePos))
            {
                summon->AI()->DoAction(ACTION_START_RAGNAROS_ALT);
            }
        }

        bool CheckMajordomoExecutus() const
        {
            if (GetBossState(BOSS_RAGNAROS) == DONE)
            {
                return false;
            }
            for (uint8 i = MCEncounters::BOSS_MAGMADAR; i < BOSS_MAJORDOMO_EXECUTUS; ++i)
            {
                if (GetBossState(i) != DONE)
                {
                    return false;
                }
            }
            return true;
        }

        void ReadSaveDataMore(std::istringstream& /*data*/) override
        {
            if (CheckMajordomoExecutus())
            {
                _executusSchedule = true;
            }
        }

    private:
        ObjectGuid _golemaggTheIncineratorGUID;
        ObjectGuid _majordomoExecutusGUID;
        ObjectGuid _cacheOfTheFirelordGUID;
        bool  _executusSchedule;
        uint8 _ragnarosAddDeaths;
        bool runesChecked;
        std::unordered_map<uint32, ObjectGuid> runeMap;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_molten_core_InstanceMapScript(map);
    }
};

void AddSC_instance_molten_core()
{
    new instance_molten_core();
}
