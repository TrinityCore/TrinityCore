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
#include "StringConvert.h"
#include "Util.h"
#include <boost/filesystem/path.hpp>
#include <fstream>
#include <sstream>

GameTable<GtArtifactKnowledgeMultiplierEntry>   sArtifactKnowledgeMultiplierGameTable;
GameTable<GtArtifactLevelXPEntry>               sArtifactLevelXPGameTable;
GameTable<GtBarberShopCostBaseEntry>            sBarberShopCostBaseGameTable;
GameTable<GtBaseMPEntry>                        sBaseMPGameTable;
GameTable<GtBattlePetXPEntry>                   sBattlePetXPGameTable;
GameTable<GtCombatRatingsEntry>                 sCombatRatingsGameTable;
GameTable<GtCombatRatingsMultByILvl>            sCombatRatingsMultByILvlGameTable;
GameTable<GtHpPerStaEntry>                      sHpPerStaGameTable;
GameTable<GtItemSocketCostPerLevelEntry>        sItemSocketCostPerLevelGameTable;
GameTable<GtNpcManaCostScalerEntry>             sNpcManaCostScalerGameTable;
GameTable<GtSpellScalingEntry>                  sSpellScalingGameTable;
GameTable<GtStaminaMultByILvl>                  sStaminaMultByILvlGameTable;
GameTable<GtXpEntry>                            sXpGameTable;

template<class T>
inline uint32 LoadGameTable(std::vector<std::string>& errors, GameTable<T>& storage, boost::filesystem::path const& path)
{
    std::ifstream stream(path.string());
    if (!stream)
    {
        errors.push_back(Trinity::StringFormat("GameTable file {} cannot be opened.", path.string()));
        return 0;
    }

    std::string headers;
    if (!std::getline(stream, headers))
    {
        errors.push_back(Trinity::StringFormat("GameTable file {} is empty.", path.string()));
        return 0;
    }

    std::vector<std::string_view> columnDefs = Trinity::Tokenize(headers, '\t', false);

    ASSERT(columnDefs.size() - 1 == sizeof(T) / sizeof(float),
        "GameTable '%s' has different count of columns " SZFMTD " than expected by size of C++ structure (" SZFMTD ").",
        path.string().c_str(), columnDefs.size() - 1, sizeof(T) / sizeof(float));

    std::vector<T> data;
    data.emplace_back(); // row id 0, unused

    std::string line;
    while (std::getline(stream, line))
    {
        RemoveCRLF(line); // file extracted from client will always have CRLF line endings, on linux opening file in text mode will not work, manually erase \r
        std::vector<std::string_view> values = Trinity::Tokenize(line, '\t', true);
        if (values.empty())
            break;

        // make end point just after last nonempty token
        auto end = values.begin() + values.size() - 1;
        while (end->empty() && end != values.begin())
            --end;

        if (values.begin() == end)
            break;

        ++end;

        ASSERT(std::size_t(std::distance(values.begin(), end)) == columnDefs.size(), SZFMTD " == " SZFMTD, std::size_t(std::distance(values.begin(), end)), columnDefs.size());

        // client ignores id column - CombatRatings has copypasted rows for levels > 110
        //ASSERT(Trinity::StringTo<int32>(values[0], 10) == data.size(),
        //    "Unexpected row identifier %d at row " SZFMTD " (expected " SZFMTD ")",
        //    Trinity::StringTo<int32>(values[0], 10).value_or(0), data.size(), data.size());

        data.emplace_back();
        float* row = reinterpret_cast<float*>(&data.back());
        for (auto itr = values.begin() + 1; itr != end; ++itr)
            *row++ = Trinity::StringTo<float>(*itr, 10).value_or(0.0f);
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

    auto LOAD_GT = [&]<typename T>(GameTable<T>& gameTable, char const* file)
    {
        gameTableCount += LoadGameTable(bad_gt_files, gameTable, gtPath / file);
        ++expectedGameTableCount;
    };

    LOAD_GT(sArtifactKnowledgeMultiplierGameTable, "ArtifactKnowledgeMultiplier.txt");
    LOAD_GT(sArtifactLevelXPGameTable, "ArtifactLevelXP.txt");
    LOAD_GT(sBarberShopCostBaseGameTable, "BarberShopCostBase.txt");
    LOAD_GT(sBaseMPGameTable, "BaseMp.txt");
    LOAD_GT(sBattlePetXPGameTable, "BattlePetXP.txt");
    LOAD_GT(sCombatRatingsGameTable, "CombatRatings.txt");
    LOAD_GT(sCombatRatingsMultByILvlGameTable, "CombatRatingsMultByILvl.txt");
    LOAD_GT(sItemSocketCostPerLevelGameTable, "ItemSocketCostPerLevel.txt");
    LOAD_GT(sHpPerStaGameTable, "HpPerSta.txt");
    LOAD_GT(sNpcManaCostScalerGameTable, "NPCManaCostScaler.txt");
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

    TC_LOG_INFO("server.loading", ">> Initialized {} GameTables in {} ms", gameTableCount, GetMSTimeDiffToNow(oldMSTime));
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
