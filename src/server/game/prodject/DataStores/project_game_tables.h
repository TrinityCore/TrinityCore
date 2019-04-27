#ifndef PROJECT_GAME_TABLES_H
#define PROJECT_GAME_TABLES_H

#include "GameTables.h"

#define MAX_PRESTIGE_RANK 32
#define MAX_HONOR_RANK 50

namespace PROJECT
{
    namespace GameTables
    {
        void Load();

        namespace Structs
        {
            struct GtAzeriteBaseExperiencePerLevel
            {
                float BaseExerperienceToNextLevel;
                float MinimumExperienceToNextLevel;
            };

            struct GtAzeriteLevelToItemLevel
            {
                float ItemLevel;
            };

            struct GtBattlePetTypeDamageMod
            {
                float Modifiers[10/*MAX_ABILITY_SCHOOL*/];
            };

            struct GtBattlePetXP
            {
                float Wins;
                float XP;
            };

            struct GtChallengeModeDamage
            {
                float Modifier;
            };

            struct GtChallengeModeHealth
            {
                float Modifier;
            };


            struct GtHonorLevelEntry
            {
                float Amount[MAX_PRESTIGE_RANK+1] = { 0.0f };
            };
        }

        TC_GAME_API extern GameTable<Structs::GtAzeriteBaseExperiencePerLevel>  AzeriteBaseExperiencePerLevel;
        TC_GAME_API extern GameTable<Structs::GtAzeriteLevelToItemLevel>        AzeriteLevelToItemLevel;
        TC_GAME_API extern GameTable<Structs::GtBattlePetTypeDamageMod>         BattlePetTypeDamageMod;
        TC_GAME_API extern GameTable<Structs::GtBattlePetXP>                    BattlePetXP;
        TC_GAME_API extern GameTable<Structs::GtChallengeModeDamage>            ChallengeModeDamage;
        TC_GAME_API extern GameTable<Structs::GtChallengeModeHealth>            ChallengeModeHealth;
        TC_GAME_API extern GameTable<Structs::GtHonorLevelEntry>                HonorLevelGameTable;

    }
}

#endif
