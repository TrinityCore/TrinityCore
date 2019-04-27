#ifndef PROJECT_H
#define PROJECT_H

#include "Define.h"
#include "Common.h"
#include "Position.h"
#include "DatabaseEnv.h"
#include "project_config.h"
#include "Random.h"
#include "Realm.h"
#include "SmartScriptMgr.h"
#include "project_hardcoded_variables.h"
#include "SharedDefines.h"

class AuraEffect;
class Aura;
class Unit;
class Creature;
class WorldObject;
class ObjectGuid;
class Player;

namespace PROJECT
{
    namespace Defines
    {
        typedef std::vector<uint32> UInt32Vector;
        typedef std::vector<uint64> UInt64Vector;
        typedef std::vector<ObjectGuid> GuidVector;
        typedef std::vector<int32> Int32Vector;
        typedef std::list<std::string> StringList;
        typedef std::list<Unit*> UnitList;
        typedef std::list<Player*> PlayerList;
        typedef std::list<Creature*> CreatureList;
        typedef std::list<WorldObject*> WorldObjectList;
        typedef std::list<Aura*> AuraList;
        typedef std::map<uint32, uint32> UInt32Map;
        typedef std::unordered_map<std::string, uint32> StringUInt32Map;
        typedef std::unordered_map<uint32, std::string> UInt32StringMap;
        typedef std::unordered_map<uint32, float> UInt32FloatMap;
        typedef std::map<Creature *, uint32> CreatureOrderTimerList;
        typedef std::map<uint32, UInt32Vector> CreatureOrderList;
        typedef std::unordered_map<uint32, int8> CreatureDataCorrespondence;

        namespace Creatures
        {
            namespace SpellCaster
            {
                struct TC_GAME_API TextEntry
                {
                    uint32 broadcastId;
                    ChatMsg type;
                    uint8 flags;
                };

                typedef std::vector<TextEntry> TextsVector;
                typedef std::map<uint32, TextsVector> CreatureTextsMap;
                
                TC_GAME_API extern CreatureTextsMap CreatureTexts;
            }
        }
    }

    namespace Mutexes
    {
        extern std::mutex lockBossTimersMaxGuid;
        extern std::mutex lockUpdateLocalChannels;
    }

    namespace Lists
    {
        extern std::unordered_map<int32, uint8> ObjectVisibilityRealmDependent;
        extern std::unordered_map<uint32, uint32> VendorRequirements;
        extern std::map<uint32, PROJECT::Defines::Int32Vector*> PendingPlayerDBData;
        extern std::unordered_map<int8/*class*/, std::list<uint32/*itemid*/>> BgRewards;
    }

    namespace Constants
    {
        enum PlayerRoles
        {
            ROLE_NONE = 0,
            ROLE_TANK = 0,
            ROLE_HEAL = 1,
            ROLE_DPS  = 2,
        };

        enum Expansions
        {
            VANILLA,
            TBC,
            WOTLK,
            CATACLYSM,
            MOP,
            WOD,
            LEGION,
        };

        namespace Miscs
        {
            enum MiscsEnum
            {
                CREATURE_ORDER_TIMER = 5000,
                INVISIBLE_MODEL = 11686,
                INFINITE_MOVEMENT_ANIMATION_DURATION = 0xFFFFFFF,
                MAX_SECONDS_TO_RECORD_DAMAGE = 15,
            };
        }

        namespace Maps
        {
            enum MapsEnum
            {
                // Battlegrounds
                BG_WSG                      = 489,
                BG_AB                       = 529,
                BG_EOTS                     = 566,
                BG_AV                       = 30,
                BG_TP                       = 726,
                BG_SOTA                     = 607,
                BG_BG                       = 761,
                BG_KT                       = 998,
                BG_SSM                      = 727,
                BG_DG                       = 1105,
                // Arenas
                ARENA_DS                    = 617,
                ARENA_BE                    = 562,
                ARENA_RL                    = 572,
                ARENA_NA                    = 559,
                ARENA_TV                    = 980,
                ARENA_TP                    = 1134,
                // World
                EASTERN_KINGDOMS            = 0,
                KALIMDOR                    = 1,
                OUTLAND                     = 530,
                NORTHREND                   = 571,
                PANDARIA                    = 870,
                GILNEAS                     = 654,
                DRAENOR                     = 1116,
                BROKEN_ISLES                = 1220,
                // dungeons
                STONECORE                   = 725,
                THRONE_OF_THE_TIDES         = 643,
                HALLS_OF_ORIGINATION        = 644,
                END_TIME                    = 938,
                WELL_OF_ETERNITY            = 939,
                HOUR_OF_TWILIGHT            = 940,
                // dungeons MOP
                GATE_OF_THE_SETTING_SUN     = 962,
                MOGUSHAN_PALACE             = 994,
                SHADO_PAN_MONASTERY         = 959,
                SIEGE_OF_NIUZAO_TEMPLE      = 1011,
                SCHOLOMANCE                 = 1007,
                STORMSTOUT_BREWERY          = 961,
                TEMPLE_OF_JADE_SERPENT      = 960,
                SCARLET_HALLS               = 1001,
                SCARLET_MONASTERY           = 1004,
                // raids
                ICECROWN_CITADEL            = 631,
                SERPENTSHRINE_CAVERN        = 548,
                ULDUAR                      = 603,
                VAULT_OF_ARCHAVON           = 624,
                NAXXRAMAS                   = 533,
                BASTION_OF_TWILIGHT         = 671,
                BLACKWING_DESCENT           = 669,
                BARADIN_HOLD                = 757,
                FIRELANDS                   = 720,
                DRAGON_SOUL                 = 967,
                // raids MOP
                MOGUSHAN_VAULTS             = 1008,
                TERRACE_OF_ENDLESS_SPRING   = 996,
                HEART_OF_FEAR               = 1009,
                THRONE_OF_THUNDER           = 1098,
                SIEGE_OF_ORGRIMMAR          = 1136,
                // scenarios
                CELESTIAL_TOURNAMENT        = 1161,
                IOT_PROGRESSION             = 1126,
                // other
                DARKMOON_ISLAND             = 974,
                EMERALD_DREAM               = 169,
                ISLE_OF_THUNDER             = 1064,
                ISLE_OF_THUNDER_MISC        = 1122,
                PROVING_GROUNDS             = 1148,
            };
        }

        namespace CanHit
        {
            enum CanHitTypes
            {
                TYPE_DODGE   = 0x00000001,
                TYPE_BLOCK   = 0x00000002,
                TYPE_PARRY   = 0x00000004,
                TYPE_DEFLECT = 0x00000008,
                TYPE_MISS    = 0x00000010,
                TYPE_RESIST  = 0x00000020,

                TYPE_ALL     = TYPE_DODGE | TYPE_BLOCK | TYPE_PARRY | TYPE_DEFLECT | TYPE_MISS | TYPE_RESIST
            };
        }

        namespace GMRanks
        {
            enum FreakzGMRanksEnum
            {
                RANK_PLAYER   = 0,
                RANK_GM       = 2,
                RANK_ADMIN    = 4,
                RANK_SHOCKER  = 6,
            };
        }

        namespace AIActions
        {
            enum AIActionsEnum
            {
                SPELL_INTERRUPTED          = 999000,
                OWNER_TARGET_CHANGED       = 999001,
            };
        }

        namespace AccountVariables
        {
            enum AccountVariablesDatabaseIndexes
            {
                SPELL_QUEUE_STATUS                 = 1,
                UNUSED                             = 2,
                WARDEN_WARNINGS                    = 3,
                REPUTATION_BONUS_COMMENDATION_MASK = 4,
            };
        }

        namespace PlayerVariables
        {
            enum eFreakzPlayerVariablesUInt32DatabaseIndexes
            {
                PROJECT_PLAYER_FLAGS                = 1,
                CANT_BE_HIT_BY_SPELLS_IN_DARKMOON  = 4,
                BATTLEGROUND_CHALLENGES_TEAM       = 5,
                LAST_LEVEL_AUTOLEARNED_SPELLS      = 6,
                LFG_BONUS_FACTION_ID               = 8,
                LOOT_SPECIALIZATION                = 9,
                BONUS_ROLL_BAD_LUCK_CHANCE         = 10,
            };
        }

        namespace RealmVariables
        {
            enum eFreakzRealmVariables
            {
                // unused 0
                LAST_ARENA_STATS_RESET            = 1,
                // unused 2
                // unused 3
                RESET_INSTANCE_CDS_ON_REALM_START = 4,
            };
        }

        namespace PlayerFlags
        {
            enum PlayerFlagsEnum
            {
                GM_COMMON_GLOBAL_CHANNEL         = 0x00000001,
                RAID_FINDER_IGNORE_BROADCASTS    = 0x00000002,
                CHALLENGES_ENABLED               = 0x00000004,
                ANNOUNCER_3V3_IGNORE_BROADCASTS  = 0x00000008,
            };
        }

        namespace PendingDBData
        {
            enum PendingDBDataEnum
            {
                EXTERNAL_MAILS,
                DONATIONS_ACTIONS,

                MAX,
            };
        }

        namespace Conversations
        {
            enum ConversationsEnum
            {
                WELCOME_TO_WOW_PROJECT                   = 40000,
                LEVEL_10_CAN_TALK_ON_GLOBAL_CHANNEL     = 40001,
                LEVEL_20_MOUNT_REWARD                   = 40002,
                LEVEL_MAX_CONGRATULATIONS               = 40003,
                LEVEL_85_PANDARIA_AVAILABLE             = 40004,
                LEVEL_90_DRAENOR_AVAILABLE              = 40005,
                LEVEL_100_LEGION_AVAILABLE              = 40006,
            };
        }

        namespace Creatures
        {
            enum CreaturesEnum
            {
                COMBAT_TRIGGER          = 42844,
                COMBAT_TRIGGER_MOP      = 999508,
                INVISIBLE_TRIGGER       = 45979,
                INVISIBLE_TRIGGER_2     = 54020,
                INVISIBLE_TRIGGER_3     = 55091,
                TEMPORARY_TRIGGER       = 999036,
                PASSIVE_TRIGGER         = 999553,
                STAFF_CONVERSATION      = 999631,
            };

            enum FlagsEx2
            {
                IGNORE_MMAPS                       = 0x00000001,   // ignore path finding
                CANT_DIE_DAMAGE                    = 0x00000002,   // creature can never be damaged below 1HP
                NO_CURRENCY_REWARD                 = 0x00000004,   // creature won't award currency custom rewards
                IS_TRAINING_DUMMY                  = 0x00000008,   // creature is a training dummy (SET DYNAMICALLY)
                FORCE_ARMORY_FEED_LOG              = 0x00000010,   // force armory kill feed log even if requirements not met (boss, raid, etc)
                INSTANT_RESPAWN                    = 0x00000020,   // instantly respawn after death, regardless of respawn timer
                PERSONAL_LOOT                      = 0x00000040,   // creature loot is always treated as personal loot
                PERSONAL_LOOT_IN_LFR               = 0x00000080,   // creature loot is treated as personal loot only in LFR
                PERSONAL_LOOT_COOLDOWN             = 0x00000100,   // creature has personal loot cooldown system
                BONUS_ROLL                         = 0x00000200,   // creature allows bonus roll
                BONUS_ROLL_COOLDOWN                = 0x00000400,   // creature has bonus roll cooldown system
                BONUS_ROLL_IGNORE_COOLDOWN_IN_LFR  = 0x00000800,   // creature ignores bonus roll cooldown in LFR
                PERSONAL_LOOT_CHANCE_BASED_FOR_ALL = 0x00001000,   // creature has personal loot system but items have their original chance for each player
                HP_SCALLING_NUMBER_OF_PLAYERS      = 0x00002000,   // creature's HP scales depending on number of players in combat with creature
                MANUAL_TARGET_CHANGE               = 0x00004000,   // creature doesn't change his target when owner changes his target (used for pets only)
                ALWAYS_VALID_TARGET_FOR_ATTACK     = 0x00008000,   // creature will always be a valid attack target regardless of flags / etc
                DISABLE_SHARED_LOOT                = 0x00010000,   // disable shared tagging / loot IsAllowedToSharedLoot()
                CANT_BE_HEALED                     = 0x00020000,   // creature cannot be healed or receive absorb buffs
                NO_INITIAL_AGGRO                   = 0x00040000,   // MoveInLineOfSight() won't be called in UpdateObjectVisibility()
                NO_MELEE_ATTACKS                   = 0x00080000,   // creature will not do any melee attacks by default (DoMeleeAttackIfReady() will always return immediately)
                IGNORE_DAMAGE_HACK_CHECK           = 0x00100000,   // ignores damage limit hack check
                EXTRA_GROUND_POSITION              = 0x00200000,   // ground position is increased by 5y (used only for creatures that ignore ground position)
                GENERIC_SPELLCASTER_AI             = 0x00400000,   // generic spell caster AI which randomly casts spells from database fields when in combat
                BOSS_TIMERS                        = 0x00800000,   // has boss timers
                BOSS_TIMERS_EXPLICIT_START         = 0x01000000,   // boss timers start function is explicitly called
                BOSS_TIMERS_EXPLICIT_WIPE          = 0x02000000,   // boss timers wipe function is explicitly called
                BOSS_TIMERS_EXPLICIT_DONE          = 0x04000000,   // boss timers done function is explicitly called
                BOSS_TIMERS_EXPLICIT_INITIALIZE    = 0x08000000,   // boss timers initialize function is explicitly called

                MASK_LOOT_RELATED = PERSONAL_LOOT | PERSONAL_LOOT_IN_LFR | PERSONAL_LOOT_COOLDOWN | BONUS_ROLL | BONUS_ROLL_COOLDOWN | BONUS_ROLL_IGNORE_COOLDOWN_IN_LFR,
            };

            namespace SpellCaster
            {
                enum Flags
                {
                    AGGRO_AND_FIGHT = 0x00,
                    ONLY_AGGRO      = 0x01,
                    ONLY_DEATH      = 0x02,
                    DISABLED        = 0x04,
                };
            }
        }

        namespace GameObjects
        {
            enum GameObjectsEnum
            {
                ARENA_READY     = 999189,
            };
        }

        namespace Reputations
        {
            enum ReputationsEnum
            {
                GUILD           = 1168,
            };
        }

        namespace LFG
        {
            namespace Queues
            {
                enum QueuesEnum
                {
                    SCENARIOS  = 1,
                    LFR        = 2,
                    FLEX       = 3,
                };
            }
        }

        namespace Mythic
        {
            enum Affix
            {
                AFFIX_OVERFLOWING = 1,
                AFFIX_SKITTISH,
                AFFIX_VOLCANIC,
                AFFIX_NECROTIQUE,
                AFFIX_TEEMING,
                AFFIX_RAGING,
                AFFIX_BLOSTERING,
                AFFIX_SANGUINE,
                AFFIX_TYRANNICAL,
                AFFIX_FORTIFIED,
            };

            enum Spells
            {
                CHALLENGER_MIGHT = 206150,
                CHALLENGER_BURDEN = 206151,
                SANGUINE_ICHOR = 226489,
                SANGUINE_ICHOR_HEAL = 226510,
                SANGUINE_ICHOR_DAMAGE = 226512,
                BLOSTER = 209859,
                NECROTIC_ROT = 209858,
                ENRAGE = 178658,
            };

            enum GameObject
            {
                CHALLENGER_DOOR = 212387,
                CHALLENGER_CACHE_1 = 252680,
                CHALLENGER_CACHE_2 = 252681,
                CHALLENGER_CACHE_3 = 252682,
            };
        }

        namespace GameEvents
        {
            enum GameEventsEnum
            {
                GURUBASHY_ARENA_BOOTY_RUN = 112,
            };
        }

        namespace Currencies
        {
            enum CurrenciesEnum
            {
                // archaeology
                TOLVIR_ARCHAEOLOGY_FIND     = 401,
                VRYKUL_ARCHAEOLOGY_FIND     = 399,
                DRAENEI_ARCHAEOLOGY_FIND    = 398,
                ORC_ARCHAEOLOGY_FIND        = 397,
                FOSSIL_ARCHAEOLOGY_FIND     = 393,
                DWARF_ARCHAEOLOGY_FIND      = 384,
                NERUBIAN_ARCHAEOLOGY_FIND   = 400,
                NIGHTELF_ARCHAEOLOGY_FIND   = 394,
                TROLL_ARCHAEOLOGY_FIND      = 385,
                MANTID_ARCHAEOLOGY_FIND     = 754,
                MOGU_ARCHAEOLOGY_FIND       = 677,
                PANDAREN_ARCHAEOLOGY_FIND   = 676,
                ARAKKOA_ARCHAEOLOGY_FIND    = 829,
                DRAENOR_CLANS_ARCHAEOLOGY_FIND = 821,
                OGRE_ARCHAEOLOGY_FIND       = 828,
                HIGHBORNE_ARCHAEOLOGY_FIND  = 1172,
                HIGHMOUNTAIN_ARCHAEOLOGY_FIND = 1173,
                DEMONIC_ARCHAEOLOGY_FIND    = 1174,

                MOTE_OF_DARKNESS            = 614,
                LESSER_CHARM_OF_GOOD_FORTUNE= 738,
                TIMELESS_COIN               = 777,
            };
        }

        namespace WorldStates
        {
            enum WorldStatesEnum
            {
                RATED_BATTLEGROUND_TYPE                   = 5508,
                ISLE_OF_THUNDER_STAGE_HORDE               = 7617,
                ISLE_OF_THUNDER_STAGE_ALLIANCE            = 7618,
                ISLE_OF_THUNDER_PARTICIPATION_HORDE       = 7797,
                ISLE_OF_THUNDER_PARTICIPATION_ALLIANCE    = 7796,
                ISLE_OF_THUNDER_PROGRESS_HORDE            = 7242,
                ISLE_OF_THUNDER_PROGRESS_ALLIANCE         = 7244,
            };
        }

        namespace Battlegrounds
        {
            enum Miscs
            {
                RATED_BATTLEGROUND_CONQUEST_PER_WIN = 60,
            };
        }

        namespace GossipIDs
        {
            enum eFreakzGossipIDs
            {
                ARENA_SPECTATE_MAIN              = 999999,
                ARENA_SPECTATE_MATCHES           = 999998,
                BATTLEGROUND_SPECTATE_MAIN       = 999997,
                ARENA_SOLO_QUEUE                 = 999996,
                TIMELESS_ISLE_QUESTION_INCORRECT = 999995,
                TIMELESS_ISLE_QUESTION_CORRECT   = 999994,
                TIMELESS_ISLE_MASTER_LI_DEFAULT  = 999993,
                TIMELESS_ISLE_MASTER_LI_MORE     = 999992,
                CELESTIAL_TOURNAMENT_TAMER       = 999991,
                WRATHION_CHAPTER_3_START         = 999990,
                CHALLENGE_MODE_CHALLENGER_ORB    = 999989,
            };
        }

        namespace Quests
        {
            namespace KillCredits
            {
                enum KillCreditsEnum
                {
                    ARENA_3V3              = 999512,
                    ARENA_3V3_SOLO_QUEUE   = 999544,
                    RANDOM_BATTLEGROUND    = 999789,
                };
            }
        }

        namespace BossTimers
        {
            enum BossState
            {
                STATE_ALIVE         = 0,
                STATE_WIPE          = 1,
                STATE_DONE          = 2,
                STATE_INTERRUPTED   = 3, // most probably server crash
                STATE_NONE          = 4,
            };

            enum Misc
            {
                MINIMUM_TIMER = 10,
            };
        }

        namespace ProcEx
        {
            enum ProcExFlags
            {
                FORCE_DONT_REQUIRE_FAMILY    = 0x00200000,
                PROC_ON_FULL_ABSORB_TOO      = 0x00400000,
            };
        }

        namespace Items
        {
            enum Flags
            {
                RECOVERED_FROM_SITE        = 0x00200000,
                BOUGHT_FROM_VOTE_SHOP      = 0x00400000,
                BOUGHT_FROM_DONATION_SHOP  = 0x00800000,
            };
        }

        namespace TeleportLocations
        {
            TC_GAME_API extern WorldLocation DALARAN;
            TC_GAME_API extern WorldLocation ORGRIMMAR;
            TC_GAME_API extern WorldLocation STORMWIND;
        }
    }

    namespace EntityVisibility
    {
        namespace Types
        {
            enum Type
            {
                HIDDEN  = 0,
                VISIBLE = 1,
            };
        }

        namespace Flags
        {
            enum Flag
            {
                ACTIVE      = 0x01,
                COMPLETED   = 0x02,
                REWARDED    = 0x04,
            };
        }

        struct EntityVisibilityStruct
        {
            EntityVisibilityStruct(uint32 entityId, uint32 questId, uint8 type, uint8 flags) : EntityID(entityId), QuestID(questId), Type((Types::Type)type), Flags(flags) { }

            uint32 EntityID;
            uint32 QuestID;
            Types::Type Type;
            uint8 Flags;
        };

        typedef std::list<EntityVisibilityStruct> VisibilityList;

        extern VisibilityList CreatureVisibilities;
        extern VisibilityList GameobjectVisibilities;
    }

    namespace Battlegrounds
    {
        struct RatedStats
        {
            RatedStats() { MMR = PROJECT::Config->GetInt("Arena.StartMatchmakerRating"); }
            uint32 Wins = 0;
            uint32 TotalPlayed = 0;
            uint32 MMR = 1500;
            uint32 Rating = 0;
        };
    }
}

// macros
#define GET_SPELL(id)    (const_cast<SpellInfo*>(sSpellMgr->GetSpellInfo(id)))
#define ENUM_INT(e) static_cast<int>(e)

#endif
