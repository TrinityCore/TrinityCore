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
#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include <algorithm>

static constexpr ObjectData creatureData[] =
{
    { NPC_MAJORDOMO_EXECUTUS,  BOSS_MAJORDOMO_EXECUTUS },
    { NPC_RAGNAROS,            BOSS_RAGNAROS },
    { 0,                       0                       } // END
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_RUNE_OF_KORO,         DATA_RUNE_OF_KORO  },
    { GO_RUNE_OF_ZETH,         DATA_RUNE_OF_ZETH  },
    { GO_RUNE_OF_MAZJ,         DATA_RUNE_OF_MAZJ  },
    { GO_RUNE_OF_THERI,        DATA_RUNE_OF_THERI },
    { GO_RUNE_OF_BLAZ,         DATA_RUNE_OF_BLAZ  },
    { GO_RUNE_OF_KRESS,        DATA_RUNE_OF_KRESS },
    { GO_RUNE_OF_MOHN,         DATA_RUNE_OF_MOHN  },
    { 0,                       0                  } // END
};

struct MoltenCoreRuneInfo
{
    uint32 RuneData, BossId;
};

static constexpr MoltenCoreRuneInfo MoltenCoreRunes[] =
{
    { DATA_RUNE_OF_KRESS, BOSS_MAGMADAR },
    { DATA_RUNE_OF_MOHN,  BOSS_GEHENNAS },
    { DATA_RUNE_OF_BLAZ,  BOSS_GARR },
    { DATA_RUNE_OF_MAZJ,  BOSS_SHAZZRAH },
    { DATA_RUNE_OF_ZETH,  BOSS_BARON_GEDDON },
    { DATA_RUNE_OF_KORO,  BOSS_SULFURON_HARBINGER },
    { DATA_RUNE_OF_THERI, BOSS_GOLEMAGG_THE_INCINERATOR }
};

class instance_molten_core : public InstanceMapScript
{
    public:
        instance_molten_core() : InstanceMapScript(MCScriptName, 409) { }

        struct instance_molten_core_InstanceMapScript : public InstanceScript
        {
            instance_molten_core_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);

                ShouldSpawnMajordomoExecutus = false;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (ShouldSpawnMajordomoExecutus)
                    SpawnMajordomoExecutus();
            }

            void OnUnitDeath(Unit* unit) override
            {
                switch (unit->GetEntry())
                {
                    case NPC_FLAMEWAKER_HEALER:
                    case NPC_FLAMEWAKER_ELITE:
                        if (Creature* majordomo = GetCreature(BOSS_MAJORDOMO_EXECUTUS))
                            majordomo->AI()->DoAction(ACTION_FLAMEWAKER_DIES);
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 bossId, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(bossId, state))
                    return false;

                switch (bossId)
                {
                    case BOSS_MAGMADAR:
                    case BOSS_GEHENNAS:
                    case BOSS_GARR:
                    case BOSS_SHAZZRAH:
                    case BOSS_BARON_GEDDON:
                    case BOSS_SULFURON_HARBINGER:
                    case BOSS_GOLEMAGG_THE_INCINERATOR:
                        if (state == DONE)
                        {
                            auto runeItr = std::ranges::find(MoltenCoreRunes, bossId, &MoltenCoreRuneInfo::BossId);
                            if (runeItr != std::ranges::end(MoltenCoreRunes))
                            {
                                if (GameObject* rune = GetGameObject(runeItr->RuneData))
                                {
                                    rune->SetGoState(GO_STATE_READY);
                                    rune->SetLootState(GO_JUST_DEACTIVATED);
                                }
                            }
                        }
                        break;
                    case BOSS_MAJORDOMO_EXECUTUS:
                        if (state == DONE)
                            instance->SpawnGroupSpawn(SPAWN_GROUP_CACHE);
                        break;
                    default:
                        break;
                }

                if (state == DONE && bossId < BOSS_MAJORDOMO_EXECUTUS)
                    if (CanSpawnMajordomoExecutus())
                        SpawnMajordomoExecutus();

                return true;
            }

            void SpawnMajordomoExecutus()
            {
                ShouldSpawnMajordomoExecutus = false;

                if (GetBossState(BOSS_MAJORDOMO_EXECUTUS) != DONE)
                {
                    instance->SpawnGroupSpawn(SPAWN_GROUP_MAJORDOMO, true);
                    instance->SpawnGroupSpawn(SPAWN_GROUP_FLAMEWAKERS, true);
                }
                else
                    instance->SpawnGroupSpawn(SPAWN_GROUP_MAJORDOMO_ALT, true);
            }

            bool CanSpawnMajordomoExecutus() const
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
                if (CanSpawnMajordomoExecutus())
                    ShouldSpawnMajordomoExecutus = true;
            }

        protected:
            bool ShouldSpawnMajordomoExecutus;
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
