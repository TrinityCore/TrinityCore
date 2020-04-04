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

#include "GameTables.h"
#include "ItemTemplate.h"
#include "Timer.h"
#include "Log.h"
#include "Util.h"
#include <boost/filesystem/path.hpp>
#include <fstream>
#include <sstream>

GameTable<GtArmorMitigationByLvlEntry>          sArmorMitigationByLvlGameTable;
GameTable<GtArtifactKnowledgeMultiplierEntry>   sArtifactKnowledgeMultiplierGameTable;
GameTable<GtArtifactLevelXPEntry>               sArtifactLevelXPGameTable;
GameTable<GtBarberShopCostBaseEntry>            sBarberShopCostBaseGameTable;
GameTable<GtBaseMPEntry>                        sBaseMPGameTable;
GameTable<GtCombatRatingsEntry>                 sCombatRatingsGameTable;
GameTable<GtCombatRatingsMultByILvl>            sCombatRatingsMultByILvlGameTable;
GameTable<GtHpPerStaEntry>                      sHpPerStaGameTable;
GameTable<GtItemSocketCostPerLevelEntry>        sItemSocketCostPerLevelGameTable;
GameTable<GtNpcDamageByClassEntry>              sNpcDamageByClassGameTable[MAX_EXPANSIONS];
GameTable<GtNpcManaCostScalerEntry>             sNpcManaCostScalerGameTable;
GameTable<GtNpcTotalHpEntry>                    sNpcTotalHpGameTable[MAX_EXPANSIONS];
GameTable<GtSpellScalingEntry>                  sSpellScalingGameTable;
GameTable<GtStaminaMultByILvl>                  sStaminaMultByILvlGameTable;
GameTable<GtXpEntry>                            sXpGameTable;

template<class T>
inline uint32 LoadGameTable(std::vector<std::string>& errors, GameTable<T>& storage, boost::filesystem::path const& path)
{
    std::ifstream stream(path.string());
    if (!stream)
    {
        errors.push_back(Trinity::StringFormat("GameTable file %s cannot be opened.", path.string().c_str()));
        return 0;
    }

    std::string headers;
    if (!std::getline(stream, headers))
    {
        errors.push_back(Trinity::StringFormat("GameTable file %s is empty.", path.string().c_str()));
        return 0;
    }

    Tokenizer columnDefs(headers, '\t', 0, false);

    ASSERT(columnDefs.size() - 1 == sizeof(T) / sizeof(float),
        "GameTable '%s' has different count of columns " SZFMTD " than expected by size of C++ structure (" SZFMTD ").",
        path.string().c_str(), columnDefs.size() - 1, sizeof(T) / sizeof(float));

    std::vector<T> data;
    data.emplace_back(); // row id 0, unused

    std::string line;
    while (std::getline(stream, line))
    {
        Tokenizer values(line, '\t', uint32(columnDefs.size()));
        if (!values.size())
            break;

        // make end point just after last nonempty token
        auto end = values.begin() + values.size() - 1;
        while (!strlen(*end) && end != values.begin())
            --end;

        if (values.begin() == end)
            break;

        ++end;

        ASSERT(std::size_t(std::distance(values.begin(), end)) == columnDefs.size(), SZFMTD " == " SZFMTD, std::size_t(std::distance(values.begin(), end)), columnDefs.size());

        // client ignores id column - CombatRatings has copypasted rows for levels > 110
        //ASSERT(strtol(values[0], nullptr, 10) == data.size(),
        //    "Unexpected row identifier %u at row " SZFMTD " (expected " SZFMTD ")",
        //    strtol(values[0], nullptr, 10), data.size(), data.size());

        data.emplace_back();
        float* row = reinterpret_cast<float*>(&data.back());
        for (auto itr = values.begin() + 1; itr != end; ++itr)
            *row++ = strtof(*itr, nullptr);
    }

    storage.SetData(std::move(data));
    return 1;
}

void LoadGameTables(std::string const& dataPath)
{
    uint32 oldMSTime = getMSTime();

    boost::filesystem::path gtPath(dataPath);
    gtPath /= "gt";

    std::vector<std::string> bad_gt_files;
    uint32 gameTableCount = 0, expectedGameTableCount = 0;

#define LOAD_GT(store, file) gameTableCount += LoadGameTable(bad_gt_files, store, gtPath / file); ++expectedGameTableCount;

    LOAD_GT(sArmorMitigationByLvlGameTable, "ArmorMitigationByLvl.txt");
    LOAD_GT(sArtifactKnowledgeMultiplierGameTable, "ArtifactKnowledgeMultiplier.txt");
    LOAD_GT(sArtifactLevelXPGameTable, "ArtifactLevelXP.txt");
    LOAD_GT(sBarberShopCostBaseGameTable, "BarberShopCostBase.txt");
    LOAD_GT(sBaseMPGameTable, "BaseMp.txt");
    LOAD_GT(sCombatRatingsGameTable, "CombatRatings.txt");
    LOAD_GT(sCombatRatingsMultByILvlGameTable, "CombatRatingsMultByILvl.txt");
    LOAD_GT(sItemSocketCostPerLevelGameTable, "ItemSocketCostPerLevel.txt");
    LOAD_GT(sHpPerStaGameTable, "HpPerSta.txt");
    LOAD_GT(sNpcDamageByClassGameTable[0], "NpcDamageByClass.txt");
    LOAD_GT(sNpcDamageByClassGameTable[1], "NpcDamageByClassExp1.txt");
    LOAD_GT(sNpcDamageByClassGameTable[2], "NpcDamageByClassExp2.txt");
    LOAD_GT(sNpcDamageByClassGameTable[3], "NpcDamageByClassExp3.txt");
    LOAD_GT(sNpcDamageByClassGameTable[4], "NpcDamageByClassExp4.txt");
    LOAD_GT(sNpcDamageByClassGameTable[5], "NpcDamageByClassExp5.txt");
    LOAD_GT(sNpcDamageByClassGameTable[6], "NpcDamageByClassExp6.txt");
    LOAD_GT(sNpcDamageByClassGameTable[7], "NpcDamageByClassExp7.txt");
    LOAD_GT(sNpcManaCostScalerGameTable, "NPCManaCostScaler.txt");
    LOAD_GT(sNpcTotalHpGameTable[0], "NpcTotalHp.txt");
    LOAD_GT(sNpcTotalHpGameTable[1], "NpcTotalHpExp1.txt");
    LOAD_GT(sNpcTotalHpGameTable[2], "NpcTotalHpExp2.txt");
    LOAD_GT(sNpcTotalHpGameTable[3], "NpcTotalHpExp3.txt");
    LOAD_GT(sNpcTotalHpGameTable[4], "NpcTotalHpExp4.txt");
    LOAD_GT(sNpcTotalHpGameTable[5], "NpcTotalHpExp5.txt");
    LOAD_GT(sNpcTotalHpGameTable[6], "NpcTotalHpExp6.txt");
    LOAD_GT(sNpcTotalHpGameTable[7], "NpcTotalHpExp7.txt");
    LOAD_GT(sSpellScalingGameTable, "SpellScaling.txt");
    LOAD_GT(sStaminaMultByILvlGameTable, "StaminaMultByILvl.txt");
    LOAD_GT(sXpGameTable, "xp.txt");

#undef LOAD_GT

    // error checks
    if (gameTableCount != expectedGameTableCount)
    {
        std::ostringstream str;
        for (std::string const& err  : bad_gt_files)
            str << err << std::endl;

        WPFatal(false, "Some required *.txt GameTable files (" SZFMTD ") not found or not compatible:\n%s", bad_gt_files.size(), str.str().c_str());
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d GameTables in %u ms", gameTableCount, GetMSTimeDiffToNow(oldMSTime));
}

template<class T>
float GetIlvlStatMultiplier(T const* row, InventoryType invType)
{
    switch (invType)
    {
        case INVTYPE_NECK:
        case INVTYPE_FINGER:
            return row->JewelryMultiplier;
            break;
        case INVTYPE_TRINKET:
            return row->TrinketMultiplier;
            break;
        case INVTYPE_WEAPON:
        case INVTYPE_SHIELD:
        case INVTYPE_RANGED:
        case INVTYPE_2HWEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
        case INVTYPE_HOLDABLE:
        case INVTYPE_RANGEDRIGHT:
            return row->WeaponMultiplier;
            break;
        default:
            return row->ArmorMultiplier;
            break;
    }
}

template float GetIlvlStatMultiplier(GtCombatRatingsMultByILvl const* row, InventoryType invType);
template float GetIlvlStatMultiplier(GtStaminaMultByILvl const* row, InventoryType invType);
