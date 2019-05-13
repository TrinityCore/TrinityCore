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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "molten_core.h"
#include "TemporarySummon.h"

Position const MajodoSummonPos   = { 737.850f, -1145.35f, -120.288f, 4.71368f };
Position const RagnarosTelePos   = { 829.159f, -815.773f, -228.972f, 5.30500f };
Position const RagnarosSummonPos = { 838.510f, -829.840f, -232.000f, 2.00000f };

class instance_molten_core : public InstanceMapScript
{
    public:
        instance_molten_core() : InstanceMapScript(MCScriptName, 409) { }

        struct instance_molten_core_InstanceMapScript : public InstanceScript
        {
            instance_molten_core_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                _executusSchedule = false;
                _ragnarosAddDeaths = 0;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (_executusSchedule)
                    SummonMajordomoExecutus();
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
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_CACHE_OF_THE_FIRELORD:
                        _cacheOfTheFirelordGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
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
                    if (CheckMajordomoExecutus())
                        SummonMajordomoExecutus();

                if (bossId == BOSS_MAJORDOMO_EXECUTUS && state == DONE)
                    DoRespawnGameObject(_cacheOfTheFirelordGUID, 7 * DAY);

                return true;
            }

            void SummonMajordomoExecutus()
            {
                _executusSchedule = false;
                if (_majordomoExecutusGUID)
                    return;

                if (GetBossState(BOSS_MAJORDOMO_EXECUTUS) != DONE)
                    instance->SummonCreature(NPC_MAJORDOMO_EXECUTUS, MajodoSummonPos);
                else if (TempSummon* summon = instance->SummonCreature(NPC_MAJORDOMO_EXECUTUS, RagnarosTelePos))
                    summon->AI()->DoAction(ACTION_START_RAGNAROS_ALT);
            }

            bool CheckMajordomoExecutus() const
            {
                if (GetBossState(BOSS_RAGNAROS) == DONE)
                    return false;

                for (uint8 i = 0; i < BOSS_MAJORDOMO_EXECUTUS; ++i)
                    if (GetBossState(i) != DONE)
                        return false;

                return true;
            }

            void ReadSaveDataMore(std::istringstream& /*data*/) override
            {
                if (CheckMajordomoExecutus())
                    _executusSchedule = true;
            }

        private:
            ObjectGuid _golemaggTheIncineratorGUID;
            ObjectGuid _majordomoExecutusGUID;
            ObjectGuid _cacheOfTheFirelordGUID;
            bool  _executusSchedule;
            uint8 _ragnarosAddDeaths;
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
