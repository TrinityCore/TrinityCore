#include "project_game_tables.h"
#include "World.h"
#include <boost/filesystem/path.hpp>
#include <fstream>
#include <Utilities/Util.h>
#include <Logging/Log.h>

namespace PROJECT {
namespace GameTables {

GameTable<Structs::GtAzeriteBaseExperiencePerLevel>     AzeriteBaseExperiencePerLevel;
GameTable<Structs::GtAzeriteLevelToItemLevel>           AzeriteLevelToItemLevel;
GameTable<Structs::GtBattlePetTypeDamageMod>            BattlePetTypeDamageMod;
GameTable<Structs::GtBattlePetXP>                       BattlePetXP;
GameTable<Structs::GtChallengeModeDamage>               ChallengeModeDamage;
GameTable<Structs::GtChallengeModeHealth>               ChallengeModeHealth;
GameTable<Structs::GtHonorLevelEntry>                   HonorLevelGameTable;

template<class T>
inline uint32 Load(std::vector<std::string>& errors, GameTable<T>& storage, boost::filesystem::path const& path)
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

void Load()
{
    uint32 oldMSTime = getMSTime();

    boost::filesystem::path gtPath(sWorld->m_dataPath);
    gtPath /= "gt";

    std::vector<std::string> bad_gt_files;
    uint32 gameTableCount = 0, expectedGameTableCount = 0;

    #define LOAD_GT(store, file) gameTableCount += Load(bad_gt_files, store, gtPath / file); ++expectedGameTableCount;

    LOAD_GT(AzeriteBaseExperiencePerLevel,  "AzeriteBaseExperiencePerLevel.txt");
    LOAD_GT(AzeriteLevelToItemLevel,        "AzeriteLevelToItemLevel.txt");
    LOAD_GT(BattlePetTypeDamageMod,         "BattlePetTypeDamageMod.txt");
    LOAD_GT(BattlePetXP,                    "BattlePetXP.txt");
    LOAD_GT(ChallengeModeDamage,            "ChallengeModeDamage.txt");
    LOAD_GT(ChallengeModeHealth,            "ChallengeModeHealth.txt");
    LOAD_GT(HonorLevelGameTable,            "HonorLevel.txt");

    #undef LOAD_GT

    // error checks
    if (gameTableCount != expectedGameTableCount)
    {
        std::ostringstream str;
        for (std::string const& err  : bad_gt_files)
            str << err << std::endl;

        WPFatal(false, "Some required *.txt GameTable files (" SZFMTD ") not found or not compatible:\n%s", bad_gt_files.size(), str.str().c_str());
    }

    TC_LOG_INFO("server.loading", ">> Initialized %d PROJECT GameTables in %u ms", gameTableCount, GetMSTimeDiffToNow(oldMSTime));
}

} // GameTables
} // PROJECT
