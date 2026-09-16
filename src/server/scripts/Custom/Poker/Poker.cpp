/*
 * Southport Poker: no-limit Texas Hold'em for 2 to 8 players seated at a physical table.
 * Chairs (gameobject entry 5000100, gameobject_template.ScriptName "PokerChair") seat players.
 * Tables are formed by chair proximity (chairs within 6 yards of one another); no table
 * gameobject is required.
 * Money: buy-in 5g to 100g creates a table stack; blinds 50s/1g; 10% rake taken from the pot at
 * settlement. The pot is paid back into the winner's table stack and only converted to real money
 * on cash-out (leaving the chair), so the table's chips are conserved apart from the rake.
 * Transport: LANG_ADDON whispers. Client sends SendAddonMessage("SPoker", cmd, "WHISPER", own name),
 * which arrives in PlayerScript::OnChat as "SPoker\t<cmd>". The server replies with a manual
 * SMSG_MESSAGECHAT system packet carrying "SPoker\t<payload>", delivered as CHAT_MSG_ADDON.
 */

#include "ScriptMgr.h"
#include "AchievementMgr.h"
#include "DBCEnums.h"
#include "DBCStores.h"
#include "PokerAchievements.h"
#include "Poker.h"
#include "GameObjectAI.h"
#include "Chat.h"
#include "RBAC.h"
#include "DatabaseEnv.h"
#include "GameTime.h"
#include "Log.h"
#include "Timer.h"
#include "Player.h"
#include "GameObject.h"
#include "Mail.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "SharedDefines.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Config.h"
#include "PokerRefundLedger.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <ctime>
#include <map>
#include <random>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace
{
    using namespace Trinity::ChatCommands;

    constexpr char const* ADDON_PREFIX = "SPoker";
    constexpr uint32 CHAIR_ENTRY = 5000100;
    constexpr uint32 MAX_SEATS = 8;
    constexpr uint32 DEFAULT_TABLE_ID = 1;                // tableId used for chairs not mapped in `poker_chair`
    constexpr uint32 ACTION_TIMEOUT_MS = 30 * 1000;
    constexpr uint32 START_DELAY_MS = 10 * 1000;
    constexpr uint32 HAND_COMPLETE_MS = 5 * 1000;         // "hand complete" beat, then the start countdown runs
    constexpr uint32 NEXT_HAND_DELAY_MS = 10 * 1000;
    constexpr uint32 REVEAL_DELAY_MS = 3 * 1000;
    constexpr uint32 SHOW_STAGGER_MS = 1000;              // pause between each player's showdown reveal
    constexpr uint32 SHOWDOWN_HOLD_MS = 4 * 1000;         // hands face up: let players compare before the pot moves
    constexpr uint32 STATE_BROADCAST_MS = 1000;
    constexpr uint32 AWAY_GRACE_MS = 15 * 1000;           // how long a player may be off their chair before being removed
    constexpr float LEAVE_RANGE = 25.0f;                  // farther than this counts as left

    using RefundBalances = SouthportPoker::RefundLedger::Balances;
    bool g_pokerReady = false;
    CharacterDatabaseTransaction g_pokerTransaction;
    std::map<ObjectGuid, uint32> g_originalWallets;
    struct PendingPokerMessage
    {
        ObjectGuid receiver;
        std::string text;
        bool system;
    };
    std::vector<PendingPokerMessage> g_pendingMessages;
    std::unordered_set<ObjectGuid> g_pendingAchievementPlayers;

    void RecordPokerResult(ObjectGuid guid, bool won, uint32 flags)
    {
        ASSERT(g_pokerTransaction);
        // Persist native criteria in the payout transaction, including offline
        // players. The ordered character worker prevents an older character save
        // overtaking it.
        for (uint32 id = PokerAchievements::FirstCriteria; id <= PokerAchievements::LastCriteria; ++id)
        {
            bool advance = PokerAchievements::Advances(id, won, flags);
            if (!advance && id != PokerAchievements::StreakCriteria)
                continue;
            uint32 limit = PokerAchievements::Limits[id - PokerAchievements::FirstCriteria];
            g_pokerTransaction->PAppend("INSERT INTO character_achievement_progress (guid, criteria, counter, date) VALUES ({}, {}, {}, {}) "
                "ON DUPLICATE KEY UPDATE counter = IF(counter >= {}, counter, IF({}, LEAST(counter + 1, {}), 0)), date = VALUES(date)",
                guid.GetCounter(), id, advance ? 1 : 0, uint32(GameTime::GetGameTime()), limit, advance ? 1 : 0, limit);
        }
        g_pendingAchievementPlayers.insert(guid);
    }

    // Check the external criteria definitions against the loaded DBCs before
    // enabling poker; these definitions are owned by this module.
    bool ValidatePokerAchievements()
    {
        for (uint32 id = PokerAchievements::FirstCriteria; id <= PokerAchievements::LastCriteria; ++id)
        {
            AchievementCriteriaEntry const* criteria = sAchievementCriteriaStore.LookupEntry(id);
            if (!criteria || criteria->AchievementID != id - 46000 ||
                criteria->Type != ACHIEVEMENT_CRITERIA_TYPE_USE_GAMEOBJECT ||
                criteria->Quantity != PokerAchievements::Limits[id - PokerAchievements::FirstCriteria] ||
                !sAchievementStore.LookupEntry(criteria->AchievementID))
            {
                TC_LOG_ERROR("misc", "Poker disabled: achievement criteria {} is missing or does not match the poker definitions.", id);
                return false;
            }
        }
        return true;
    }

    // Push committed counters into the online achievement manager, completing the
    // achievement if a stored counter is already satisfied.
    void SyncPlayerPokerAchievements(Player* player)
    {
        // Only apply once the module is enabled; the startup validation guards
        // every apply path against mismatched DBCs.
        if (!player || !g_pokerReady)
            return;
        std::ostringstream qs;
        qs << "SELECT criteria, counter, date FROM character_achievement_progress WHERE guid = "
            << player->GetGUID().GetCounter() << " AND criteria BETWEEN "
            << PokerAchievements::FirstCriteria << " AND " << PokerAchievements::LastCriteria;
        QueryResult result = CharacterDatabase.QueryNoRetry(qs.str().c_str());
        if (!result)
            return;
        do
        {
            Field* fields = result->Fetch();
            if (AchievementMgr* mgr = player->GetAchievementMgr())
                mgr->ApplyExternalCriteriaProgress(fields[0].GetUInt32(), fields[1].GetUInt32(), time_t(fields[2].GetUInt32()));
        } while (result->NextRow());
    }

    void TrackWallet(Player* player)
    {
        g_originalWallets.emplace(player->GetGUID(), player->GetMoney());
    }

    // Use the ordered character worker queue, including its older character
    // saves, and wait for the actual commit result before acknowledging money.
    TransactionOutcome CommitPoker(CharacterDatabaseTransaction trans)
    {
        trans->SetNoRetry();
        if (CharacterDatabase.AsyncCommitTransaction(trans).m_future.get())
            return TransactionOutcome::Committed;
        // The commit failed; the DB layer recorded whether it proved a rollback
        // or whether the outcome is indeterminate.
        return trans->GetOutcome();
    }

    // ---- per-table configuration (loaded from the `poker_table_config` DB table) ----
    struct PokerTableConfig
    {
        uint32 smallBlind = 0;
        uint32 bigBlind = 0;
        uint32 minBuyIn = 0;
        uint32 maxBuyIn = 0;
        uint32 maxBet = 0;                 // 0 = uncapped (no-limit)
        uint32 maxSeats = MAX_SEATS;
    };

    std::unordered_map<uint32, PokerTableConfig> g_tableConfigs;  // tableId -> config
    std::unordered_map<uint32, uint32> g_chairTable;             // chair spawnId -> tableId
    std::unordered_map<uint32, uint32> g_chairPos;               // chair spawnId -> seat position (1-8, 0=auto)

    PokerTableConfig const& ConfigFor(uint32 tableId)
    {
        auto it = g_tableConfigs.find(tableId);
        if (it != g_tableConfigs.end())
            return it->second;
        // no row for this table: reuse the default table's row so the DB stays authoritative
        auto def = g_tableConfigs.find(DEFAULT_TABLE_ID);
        if (def != g_tableConfigs.end())
            return def->second;
        static PokerTableConfig const empty;
        return empty;
    }

    uint32 TableIdForChair(uint32 spawnId)
    {
        auto it = g_chairTable.find(spawnId);
        return it != g_chairTable.end() ? it->second : DEFAULT_TABLE_ID;
    }

    uint32 ChairPosition(uint32 spawnId)
    {
        auto it = g_chairPos.find(spawnId);
        return it != g_chairPos.end() ? it->second : 0;
    }

    void LoadPokerConfig()
    {
        uint32 oldMSTime = getMSTime();

        // load into locals and only swap them in on success, so a DB hiccup or a bad query keeps
        // the last known good config instead of silently zeroing every blind and buy-in
        std::unordered_map<uint32, PokerTableConfig> tableConfigs;
        std::unordered_map<uint32, uint32> chairTable;
        std::unordered_map<uint32, uint32> chairPos;

        uint32 cfgCount = 0;
        if (QueryResult result = WorldDatabase.QueryNoRetry(
                "SELECT tableId, smallBlind, bigBlind, minBuyIn, maxBuyIn, maxBet, maxSeats FROM poker_table_config"))
        {
            do
            {
                Field* fields = result->Fetch();
                PokerTableConfig cfg;
                uint32 id = fields[0].GetUInt32();
                cfg.smallBlind = fields[1].GetUInt32();
                cfg.bigBlind = fields[2].GetUInt32();
                cfg.minBuyIn = fields[3].GetUInt32();
                cfg.maxBuyIn = fields[4].GetUInt32();
                cfg.maxBet = fields[5].GetUInt32();
                cfg.maxSeats = fields[6].GetUInt32();
                if (cfg.maxSeats == 0 || cfg.maxSeats > MAX_SEATS) cfg.maxSeats = MAX_SEATS;
                if (cfg.smallBlind == 0)
                {
                    TC_LOG_ERROR("sql.sql", "Poker: table {} has smallBlind 0, skipping it", id);
                    continue;
                }
                if (cfg.bigBlind < cfg.smallBlind)
                {
                    TC_LOG_ERROR("sql.sql", "Poker: table {} has bigBlind < smallBlind, clamping", id);
                    cfg.bigBlind = cfg.smallBlind;
                }
                if (cfg.minBuyIn == 0)
                {
                    TC_LOG_ERROR("sql.sql", "Poker: table {} has minBuyIn 0, using the big blind", id);
                    cfg.minBuyIn = cfg.bigBlind;
                }
                if (cfg.maxBuyIn < cfg.minBuyIn)
                {
                    TC_LOG_ERROR("sql.sql", "Poker: table {} has maxBuyIn < minBuyIn, clamping", id);
                    cfg.maxBuyIn = cfg.minBuyIn;
                }
                tableConfigs[id] = cfg;
                ++cfgCount;
            } while (result->NextRow());
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Poker: poker_table_config query failed; keeping the previous config");
            return;
        }

        if (tableConfigs.empty())
        {
            TC_LOG_ERROR("sql.sql", "Poker: poker_table_config is empty; keeping the previous config");
            return;
        }

        uint32 chairCount = 0;
        if (QueryResult result = WorldDatabase.QueryNoRetry("SELECT chairSpawnId, tableId, position FROM poker_chair"))
        {
            do
            {
                Field* fields = result->Fetch();
                uint32 spawn = fields[0].GetUInt32();
                chairTable[spawn] = fields[1].GetUInt32();
                chairPos[spawn] = fields[2].GetUInt32();
                ++chairCount;
            } while (result->NextRow());
        }
        else
        {
            TC_LOG_ERROR("sql.sql", "Poker: poker_chair query failed; keeping the previous config");
            return;
        }

        g_tableConfigs.swap(tableConfigs);
        g_chairTable.swap(chairTable);
        g_chairPos.swap(chairPos);

        TC_LOG_INFO("server.loading", ">> Loaded {} poker table configs and {} poker chairs in {} ms",
            cfgCount, chairCount, GetMSTimeDiffToNow(oldMSTime));
    }

    enum SeatState : uint8
    {
        SEAT_WAIT = 0,      // seated, not bought in
        SEAT_BETWEEN = 1,   // bought in, waiting for the next hand
        SEAT_ACTIVE = 2,    // in the current hand, still deciding
        SEAT_FOLDED = 3,
        SEAT_ALLIN = 4
    };

    enum Phase : uint8
    {
        PH_WAIT = 0,
        PH_PREFLOP = 1,
        PH_FLOP = 2,
        PH_TURN = 3,
        PH_RIVER = 4,
        PH_SHOWDOWN = 5
    };

    enum TimerMode : uint8
    {
        TM_NONE = 0,
        TM_START = 1,
        TM_ACTION = 2,
        TM_REVEAL = 3,
        TM_NEXT = 4,
        TM_SHOW_ONE = 5,     // staggered showdown reveal, one player at a time
        TM_HOLD = 6          // all hands face up: hold before paying the pot
    };

    bool IsInHand(SeatState s) { return s == SEAT_ACTIVE || s == SEAT_FOLDED || s == SEAT_ALLIN; }

    // Card encoding: card = rank * 4 + suit. rank 0..12 is 2..A, suit 0..3 is C D H S.

    struct PokerSeat
    {
        uint32 chairId = 0;     // gameobject spawn id of the chair
        uint32 slot = 0;        // stable seat slot index (0..MAX_SEATS-1) around the table
        ObjectGuid playerGuid;
        std::string name;
        uint32 stack = 0;
        uint32 bet = 0;         // committed in the current betting round
        uint32 committed = 0;   // committed in the whole hand (escrow)
        SeatState state = SEAT_WAIT;
        uint32 cards[2] = { 0, 0 };
        bool acted = false;
        bool sittingOut = false; // seated and bought in, but skipping hands until they sit back in
        bool revealed = false; // public cards for this hand, retained through the settlement display
        bool awaySitOut = false; // the manual sit-out choice to restore when they return from AWAY
        bool waitingBB = false;  // just sat / moved / sat out: owes a dead blind on return
        bool leaveAfterHand = false; // away too long mid-hand: remove the seat once the hand settles
        bool canReraise = true;  // may re-raise this street; a short all-in does not reopen the action
        bool mailCashout = false; // logout: mail the cash-out instead of crediting a wallet that will never be saved
        uint32 seatedAt = 0;    // GameTime ms when the player sat (grace period for stand-sync)
        uint32 awaySince = 0;   // GameTime ms when the player left their chair (0 = present)
        uint8 playerClass = 0;  // player class id, for the name tint in the addon
        uint8 playerRace = 0;   // for the race icon in the addon
        uint8 playerGender = 0; // gender (0 male, 1 female) for the race icon
        uint32 icon = 0;        // per-player seat icon chosen in the addon
    };

    uint32 RankFive(uint32 const* cards)
    {
        uint32 rankCount[13] = { 0 };
        uint32 suitCount[4] = { 0 };
        uint32 rankMask = 0;
        for (uint32 i = 0; i < 5; ++i)
        {
            uint32 r = cards[i] / 4;
            uint32 s = cards[i] % 4;
            ++rankCount[r];
            ++suitCount[s];
            rankMask |= (1u << r);
        }

        bool flush = false;
        for (uint32 i = 0; i < 4; ++i)
            if (suitCount[i] == 5)
                flush = true;

        int quad = -1, trip = -1;
        int pairs[2] = { -1, -1 };
        for (int r = 12; r >= 0; --r)
        {
            if (rankCount[r] == 4) quad = r;
            else if (rankCount[r] == 3) trip = r;
            else if (rankCount[r] == 2) { if (pairs[0] < 0) pairs[0] = r; else if (pairs[1] < 0) pairs[1] = r; }
        }

        int straightHigh = -1;
        for (int high = 12; high >= 4; --high)
            if (((rankMask >> (high - 4)) & 0x1F) == 0x1F) { straightHigh = high; break; }
        if (straightHigh < 0 && (rankMask & 0x100F) == 0x100F) // wheel A 5 4 3 2
            straightHigh = 3;

        int desc[5] = { 0, 0, 0, 0, 0 };
        int n = 0;
        for (int r = 12; r >= 0 && n < 5; --r)
            for (int c = 0; c < static_cast<int>(rankCount[r]) && n < 5; ++c)
                desc[n++] = r;

        auto score = [](uint32 cat, int k0, int k1 = 0, int k2 = 0, int k3 = 0, int k4 = 0)
        {
            return (cat << 20) | ((k0 & 0xF) << 16) | ((k1 & 0xF) << 12) | ((k2 & 0xF) << 8) | ((k3 & 0xF) << 4) | (k4 & 0xF);
        };

        if (flush && straightHigh >= 0)
            return score(8, straightHigh);
        if (quad >= 0)
        {
            int kick = 0;
            for (int r = 12; r >= 0; --r)
                if (r != quad && rankCount[r] > 0) { kick = r; break; }
            return score(7, quad, kick);
        }
        if (trip >= 0 && pairs[0] >= 0)
            return score(6, trip, pairs[0]);
        if (flush)
            return score(5, desc[0], desc[1], desc[2], desc[3], desc[4]);
        if (straightHigh >= 0)
            return score(4, straightHigh);
        if (trip >= 0)
        {
            int kick[2] = { 0, 0 }; int kn = 0;
            for (int r = 12; r >= 0 && kn < 2; --r)
                if (r != trip && rankCount[r] > 0) kick[kn++] = r;
            return score(3, trip, kick[0], kick[1]);
        }
        if (pairs[1] >= 0)
        {
            int kick = 0;
            for (int r = 12; r >= 0; --r)
                if (r != pairs[0] && r != pairs[1] && rankCount[r] > 0) { kick = r; break; }
            return score(2, pairs[0], pairs[1], kick);
        }
        if (pairs[0] >= 0)
        {
            int kick[3] = { 0, 0, 0 }; int kn = 0;
            for (int r = 12; r >= 0 && kn < 3; --r)
                if (r != pairs[0] && rankCount[r] > 0) kick[kn++] = r;
            return score(1, pairs[0], kick[0], kick[1], kick[2]);
        }
        return score(0, desc[0], desc[1], desc[2], desc[3], desc[4]);
    }

    uint32 BestSeven(uint32 const* cards7)
    {
        static const uint8 combos[21][5] =
        {
            {0,1,2,3,4},{0,1,2,3,5},{0,1,2,3,6},{0,1,2,4,5},{0,1,2,4,6},{0,1,2,5,6},
            {0,1,3,4,5},{0,1,3,4,6},{0,1,3,5,6},{0,1,4,5,6},{0,2,3,4,5},{0,2,3,4,6},
            {0,2,3,5,6},{0,2,4,5,6},{0,3,4,5,6},{1,2,3,4,5},{1,2,3,4,6},{1,2,3,5,6},
            {1,2,4,5,6},{1,3,4,5,6},{2,3,4,5,6}
        };
        uint32 best = 0;
        uint32 five[5];
        for (uint32 i = 0; i < 21; ++i)
        {
            for (uint32 j = 0; j < 5; ++j)
                five[j] = cards7[combos[i][j]];
            best = std::max(best, RankFive(five));
        }
        return best;
    }

    char const* const RANK_NAMES[13] =
    {
        "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"
    };

    // plural rank name ("Sixes" is the one irregular)
    std::string PluralRank(int r)
    {
        if (r == 4)
            return "Sixes";
        return std::string((r >= 0 && r <= 12) ? RANK_NAMES[r] : "?") + "s";
    }

    // decode a RankFive/BestSeven score into a readable hand name
    std::string DescribeScore(uint32 score)
    {
        uint32 cat = score >> 20;
        int k0 = (score >> 16) & 0xF;
        int k1 = (score >> 12) & 0xF;
        int k2 = (score >> 8) & 0xF;
        auto R = [](int r) { return (r >= 0 && r <= 12) ? RANK_NAMES[r] : "?"; };
        switch (cat)
        {
            case 8: return std::string("a Straight Flush, ") + R(k0) + " high";
            case 7: return std::string("Four of a Kind, ") + PluralRank(k0) + ", " + R(k1) + " kicker";
            case 6: return std::string("a Full House, ") + PluralRank(k0) + " over " + PluralRank(k1);
            case 5: return std::string("a Flush, ") + R(k0) + " high";
            case 4: return std::string("a Straight, ") + R(k0) + " high";
            case 3: return std::string("Three of a Kind, ") + PluralRank(k0) + ", " + R(k1) + " kicker";
            case 2: return std::string("Two Pair, ") + PluralRank(k0) + " and " + PluralRank(k1) + ", " + R(k2) + " kicker";
            case 1: return std::string("a Pair of ") + PluralRank(k0) + ", " + R(k1) + " kicker";
            default: return std::string(R(k0)) + " high";
        }
    }

    // best RankFive score over every 5-card subset (needs at least 5 cards); optionally returns the
    // winning five cards so callers can show the exact hand
    uint32 BestFive(std::vector<uint32> const& cards, uint32* out5 = nullptr)
    {
        int n = static_cast<int>(cards.size());
        uint32 best = 0;
        for (int a = 0; a < n - 4; ++a)
            for (int b = a + 1; b < n - 3; ++b)
                for (int c = b + 1; c < n - 2; ++c)
                    for (int d = c + 1; d < n - 1; ++d)
                        for (int e = d + 1; e < n; ++e)
                        {
                            uint32 five[5] = { cards[a], cards[b], cards[c], cards[d], cards[e] };
                            uint32 sc = RankFive(five);
                            if (sc > best)
                            {
                                best = sc;
                                if (out5)
                                    for (int j = 0; j < 5; ++j)
                                        out5[j] = five[j];
                            }
                        }
        return best;
    }

    std::string RankLetter(int r)
    {
        static char const* const LETTERS[13] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
        return (r >= 0 && r <= 12) ? LETTERS[r] : "?";
    }

    // name the best hand from the player's hole cards plus whatever board is out
    std::string DescribeHand(std::vector<uint32> const& cards)
    {
        if (cards.size() < 5)
        {
            if (cards.size() == 2)
            {
                int r0 = cards[0] / 4, r1 = cards[1] / 4;
                if (r0 == r1)
                    return std::string("a Pair of ") + PluralRank(r0);
                return std::string(RANK_NAMES[std::max(r0, r1)]) + " high";
            }
            return "";
        }
        return DescribeScore(BestFive(cards));
    }

    void SendPokerAddon(Player* to, std::string const& msg)
    {
        if (!to || msg.empty())
            return;

        if (g_pokerTransaction)
        {
            g_pendingMessages.push_back({ to->GetGUID(), msg, false });
            return;
        }

        // Mirror GOMove::SendAddonMessage (proven on this core + 3.3.5 client):
        // CHAT_MSG_SYSTEM + LANG_ADDON + raw uint64 guids. Type CHAT_MSG_ADDON (0xFF)
        // makes the 3.3.5 client take a different parse path and hard-crash.
        std::string full = "SPoker\t";
        full += msg;

        WorldPacket data;
        data.Initialize(SMSG_MESSAGECHAT, full.size() + 32);
        data << uint8(CHAT_MSG_SYSTEM);
        data << int32(LANG_ADDON);
        data << uint64(to->GetGUID().GetRawValue());
        data << uint32(0);
        data << uint64(to->GetGUID().GetRawValue());
        data << uint32(full.size() + 1);
        data << full;                     // ByteBuffer string writer appends the null terminator
        data << uint8(0);
        to->GetSession()->SendPacket(&data);
    }

    void SysMsg(Player* player, std::string const& text)
    {
        if (player && g_pokerTransaction)
        {
            g_pendingMessages.push_back({ player->GetGUID(), text, true });
            return;
        }
        if (player)
            ChatHandler(player->GetSession()).SendSysMessage(text);
    }

    // copper -> "1g 23s 45c" for chat notifications
    std::string MoneyStr(uint32 copper)
    {
        std::ostringstream ss;
        uint32 g = copper / 10000;
        uint32 s = (copper % 10000) / 100;
        uint32 c = copper % 100;
        if (g)
            ss << g << "g ";
        if (s || g)
            ss << s << "s ";
        ss << c << "c";
        return ss.str();
    }

    // make a seated player unattackable/immune so they can't be griefed
    void OnSeated(Player* player)
    {
        player->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1
            | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_PACIFIED);
    }

    void OnUnseated(Player* player)
    {
        player->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_ATTACKABLE_1
            | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_PACIFIED);
    }

    // mail a poker cash-out to the player (works whether they are online or not); it arrives from
    // the Southport Casino NPC (creature_template entry 5000017, no spawn of its own)
    void MailPokerMoney(ObjectGuid guid, uint32 amount, bool recovery = false)
    {
        if (amount == 0)
            return;
        ASSERT(g_pokerTransaction);
        MailDraft draft(recovery ? "Southport Poker refund" : "Southport Casino",
            recovery ? "The server restarted. Your unfinished poker hand was voided. "
                "This returns your remaining table gold and your contributions to that hand. "
                "Completed hands keep their results. No rake was taken from the voided hand."
                : "Here is the gold you had on the table. Come back and see us.");
        draft.AddMoney(amount);
        draft.SendMailTo(g_pokerTransaction, MailReceiver(guid.GetCounter()), MailSender(MAIL_CREATURE, 5000017 /* Southport Casino */));
    }

    // hand a player their money: immediately for whatever fits under the gold cap, by mail for the
    // rest (and for a fully offline player, all of it). returns the amount credited to their wallet.
    uint32 PokerCashOut(Player* p, ObjectGuid guid, uint32 amount)
    {
        if (amount == 0)
            return 0;
        uint32 pay = 0;
        if (p)
        {
            uint32 money = p->GetMoney();
            uint32 room = money < MAX_MONEY_AMOUNT ? (MAX_MONEY_AMOUNT - money) : 0;
            uint32 want = std::min(amount, room);
            if (want > 0)
            {
                TrackWallet(p);
                // ModifyMoney refuses at the exact cap (it uses a strict '<'), so trust what the
                // wallet actually gained rather than the requested amount, and mail the shortfall
                uint32 before = p->GetMoney();
                p->ModifyMoney(static_cast<int32>(want), false);
                uint32 after = p->GetMoney();
                pay = after > before ? after - before : 0;
            }
        }
        if (pay < amount)
        {
            MailPokerMoney(guid, amount - pay);
            if (p)
                SysMsg(p, "Your wallet is full: " + MoneyStr(amount - pay) + " was mailed to you by the Southport Casino.");
        }
        return pay;
    }

    class PokerTable
    {
    public:
        PokerTable(uint32 key) : _key(key) { }
        ~PokerTable()
        {
            for (PokerSeat* s : _seats)
                delete s;
            _seats.clear();
        }

        // ---- public interface used by the manager ----

        bool Empty() const { return _seats.empty(); }

        RefundBalances Recoverable() const
        {
            RefundBalances stacks;
            for (PokerSeat const* seat : _seats)
                stacks[seat->playerGuid.GetCounter()] += seat->stack;
            return _refundLedger.Recoverable(stacks);
        }

        // Recovery teardown: stand every seated player up without paying them. The
        // escrow journal returns their balance when recovery mails it.
        void ForceCloseForRecovery()
        {
            for (PokerSeat* seat : _seats)
                if (Player* player = FindPlayer(seat))
                {
                    OnUnseated(player);
                    player->SetStandState(UNIT_STAND_STATE_STAND);
                    SendPokerAddon(player, "LEAVEOK 0");
                    SysMsg(player, "Poker was reset after a database error. Any table gold is being returned from the saved refund record.");
                }
        }

        bool IsMarkedForDelete() const { return _markedForDelete; }
        std::size_t SeatCount() const { return _seats.size(); }

        PokerSeat* FindByPlayer(ObjectGuid guid)
        {
            for (PokerSeat* s : _seats)
                if (s->playerGuid == guid)
                    return s;
            return nullptr;
        }

        PokerSeat* FindByChair(uint32 chairId)
        {
            for (PokerSeat* s : _seats)
                if (s->chairId == chairId)
                    return s;
            return nullptr;
        }

        // discover this table's chair gameobjects (from the `poker_chair` mapping) and assign
        // stable slot indices, ordered by bearing around the chair-ring centroid
        void PopulateChairs(GameObject* clicked, uint32 tableId, uint32 entry, float searchRange)
        {
            if (!_chairs.empty())
                return;

            std::vector<GameObject*> gos;
            clicked->GetGameObjectListWithEntryInGrid(gos, entry, searchRange);

            // keep only chairs mapped to this table; fall back to all nearby chairs if nothing is mapped
            std::vector<GameObject*> mine;
            for (GameObject* go : gos)
                if (TableIdForChair(go->GetSpawnId()) == tableId)
                    mine.push_back(go);

            bool hasClicked = false;
            for (GameObject* go : mine)
                if (go->GetSpawnId() == clicked->GetSpawnId())
                    hasClicked = true;
            if (!hasClicked)
                mine.push_back(clicked);
            if (mine.empty())
                return;

            // ring centre = average chair position (NOT one of the chairs, so no degenerate angle)
            float cx = 0.0f, cy = 0.0f, cz = 0.0f;
            for (GameObject* go : mine)
            {
                cx += go->GetPositionX();
                cy += go->GetPositionY();
                cz += go->GetPositionZ();
            }
            _x = cx / mine.size();
            _y = cy / mine.size();
            _z = cz / mine.size();
            _mapId = clicked->GetMapId();

            std::sort(mine.begin(), mine.end(), [this](GameObject* a, GameObject* b)
            {
                // order by the explicit seat position from `poker_chair`; 0 = auto (by angle)
                uint32 pa = ChairPosition(a->GetSpawnId());
                uint32 pb = ChairPosition(b->GetSpawnId());
                if (pa != pb)
                    return (pa ? pa : 1000) < (pb ? pb : 1000);
                return std::atan2(a->GetPositionY() - _y, a->GetPositionX() - _x)
                     < std::atan2(b->GetPositionY() - _y, b->GetPositionX() - _x);
            });

            for (GameObject* go : mine)
            {
                if (_chairs.size() >= MAX_SEATS)
                    break;
                ChairSlot slot;
                slot.spawnId = go->GetSpawnId();
                slot.x = go->GetPositionX();
                slot.y = go->GetPositionY();
                slot.z = go->GetPositionZ();
                slot.o = go->GetOrientation();
                if (GameObjectTemplate const* info = go->GetGOInfo())
                    slot.height = info->chair.height;
                _chairs.push_back(slot);
            }
        }

        int FindChairSlot(uint32 spawnId) const
        {
            for (std::size_t i = 0; i < _chairs.size(); ++i)
                if (_chairs[i].spawnId == spawnId)
                    return static_cast<int>(i);
            return -1;
        }

        bool SlotIsFree(int slot) const
        {
            if (slot < 0 || slot >= static_cast<int>(_chairs.size()))
                return false;
            uint32 spawnId = _chairs[slot].spawnId;
            for (PokerSeat const* s : _seats)
                if (s->chairId == spawnId)
                    return false;
            return true;
        }

        bool AddSeat(Player* player, uint32 chairId)
        {
            if (_seats.size() >= Config().maxSeats || FindByChair(chairId) || FindByPlayer(player->GetGUID()))
                return false;
            int chairSlot = FindChairSlot(chairId);
            if (chairSlot < 0)
                return false;   // chair is not part of this table's ring
            PokerSeat* s = new PokerSeat();
            s->chairId = chairId;
            s->slot = static_cast<uint32>(chairSlot);
            s->playerGuid = player->GetGUID();
            s->name = player->GetName();
            s->playerClass = player->GetClass();
            s->playerRace = player->GetRace();
            s->playerGender = player->GetGender();
            s->seatedAt = GameTime::GetGameTimeMS();
            s->waitingBB = true;   // joining owes a blind; it does not enable sitting out
            {
                // load the player's saved seat icon; a missing table or row simply leaves 0
                std::ostringstream qs;
                qs << "SELECT icon FROM poker_icon WHERE guid = " << player->GetGUID().GetCounter();
                if (QueryResult result = CharacterDatabase.QueryNoRetry(qs.str().c_str()))
                    s->icon = result->Fetch()[0].GetUInt32();
            }
            _seats.push_back(s);
            SortSeats();   // keep the vector in table (slot) order so blinds/action rotate correctly
            return true;
        }

        uint32 Key() const { return _key; }

        PokerTableConfig const& Config() const { return ConfigFor(_key); }

        void Tick(uint32 diff)
        {
            ValidateSeats();

            if (_timerMode != TM_NONE)
            {
                if (_timer > diff)
                    _timer -= diff;
                else
                {
                    _timer = 0;
                    OnTimer();
                }
            }

            if (_phase == PH_WAIT)
            {
                // a seat that cannot cover the big blind cannot be dealt in: sit them out and prompt
                // a top-up, so we never start a countdown for a hand that cannot actually begin
                bool shortChanged = false;
                for (PokerSeat* s : _seats)
                {
                    if (s->state != SEAT_BETWEEN || s->sittingOut || s->stack >= MinStartStack())
                        continue;
                    s->state = SEAT_WAIT;
                    s->acted = false;
                    if (Player* p = FindPlayer(s))
                    {
                        SysMsg(p, "You cannot cover the blinds. Buy in again to keep playing.");
                        SendBuyinPrompt(p, s, "REBUY");
                    }
                    shortChanged = true;
                }
                if (shortChanged)
                    BroadcastState();

                if (ReadyCount() >= 2)
                {
                    if (_timerMode != TM_START)
                    {
                        TC_LOG_INFO("misc", "Poker: table {} start countdown (ready {})", _key, ReadyCount());
                        for (Player* p : ConnectedPlayers())
                            SysMsg(p, "A new hand begins in 10 seconds.");
                        StartTimer(TM_START, START_DELAY_MS);
                    }
                }
                else if (_timerMode == TM_START)
                {
                    _timerMode = TM_NONE;
                    // only tell the players still ready to play, not whoever just stood up / left
                    for (PokerSeat* s : _seats)
                        if (s->state == SEAT_BETWEEN && s->stack > 0 && !s->sittingOut)
                            if (Player* p = FindPlayer(s))
                                SysMsg(p, "Waiting for another player to begin.");
                }
            }

            _broadcastAcc += diff;
            if (_broadcastAcc >= STATE_BROADCAST_MS && !_seats.empty())
            {
                _broadcastAcc = 0;
                BroadcastState();
            }
        }

        void HandleBuyin(Player* player, uint32 amount)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s || s->state != SEAT_WAIT)
            {
                SendPokerAddon(player, "ALREADY");
                return;
            }
            uint64 resultingStack = uint64(s->stack) + amount;
            if (amount == 0 || resultingStack < Config().minBuyIn || resultingStack > Config().maxBuyIn)
            {
                SendDeny(player, "BUYINRANGE");
                return;
            }
            uint64 tableMoney = PotTotal();
            for (PokerSeat const* seat : _seats)
                tableMoney += seat->stack;
            if (amount > MAX_MONEY_AMOUNT || tableMoney + amount > MAX_MONEY_AMOUNT)
            {
                SysMsg(player, "This buy-in would exceed the table's safe gold limit.");
                return;
            }
            TrackWallet(player);
            if (!player->HasEnoughMoney(amount) || !player->ModifyMoney(-static_cast<int32>(amount)))
            {
                SendDeny(player, "GOLD");
                return;
            }
            s->stack += amount;   // top up: preserves any leftover chips when a short stack re-buys
            _refundLedger.BuyIn(player->GetGUID().GetCounter(), amount);
            s->state = SEAT_BETWEEN;
            TC_LOG_INFO("misc", "Poker: {} bought in (key {}, ready {})", player->GetName(), _key, ReadyCount());
            SendPokerAddon(player, "BOUGHT");
            if (ReadyCount() >= 2)
                SysMsg(player, "You bought in for " + MoneyStr(amount) + ".");
            else
                SysMsg(player, "You bought in for " + MoneyStr(amount) + ". Waiting for at least one more player to buy in.");
            BroadcastState();
        }

        void HandleLeave(Player* player)
        {
            if (PokerSeat* s = FindByPlayer(player->GetGUID()))
                LeaveSeat(s);
        }

        // logging out: never fold a live hand (settle it first) and mail the cash-out, because a
        // wallet credit made during LogoutPlayer lands after the character save and is lost
        void HandleLogout(Player* player)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s)
                return;
            if (InHand() && (s->state == SEAT_ACTIVE || s->state == SEAT_ALLIN))
            {
                s->leaveAfterHand = true;
                s->mailCashout = true;
                return;
            }
            LeaveSeat(s, true);
        }

        // a client /reload stands the character up from the chair, so treat it as a stand-up: keep
        // the seat for the away grace but keep the table UI hidden instead of resuming it
        void HandleReload(Player* player)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s)
                return;
            // a reload is a deliberate stand-up: keep them sitting out when they come back so the
            // "sit out" checkbox matches, until they uncheck it. Set this even if the world tick
            // already noticed the stand-up (standing up physically usually beats this message).
            s->awaySitOut = true;
            s->sittingOut = true;
            if (s->awaySince == 0)
            {
                s->awaySince = GameTime::GetGameTimeMS();
                SysMsg(player, "The interface reloaded, so you stood up from the table. You are sitting out.");
            }
            SendPokerAddon(player, "AWAY");
            BroadcastState();
        }

        // toggle whether a bought-in player is dealt into upcoming hands (they keep their seat)
        void HandleSitOut(Player* player, bool sitOut)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s)
            {
                SendDeny(player, "NOTSEATED");
                return;
            }
            s->sittingOut = sitOut;
            if (sitOut)
                s->waitingBB = true;   // skipping hands still owes a blind on return: no sit-out blind dodge
            SysMsg(player, sitOut ? "You are sitting out. You will be dealt in again when you sit in."
                                  : "You are sitting in. You will be dealt the next hand.");
            BroadcastState();
        }

        // store the player's chosen seat icon and push it out to every client
        void HandleIcon(Player* player, uint32 index)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s)
                return;
            if (index > 65535)
                index = 65535;
            s->icon = index;
            std::ostringstream ss;
            ss << "REPLACE INTO poker_icon (guid, icon) VALUES ("
               << player->GetGUID().GetCounter() << ", " << index << ")";
            CharacterDatabase.Execute(ss.str().c_str());
            BroadcastState();
        }

        // true when the player is actually on their chair right now. The seat record alone is stale:
        // awaySince is only refreshed by ValidateSeats on the world tick, which a /reload HELLO can
        // race, so this is the authoritative check before reopening the window.
        bool SeatPresent(Player* player, PokerSeat const* s)
        {
            if (!player || !s || s->awaySince != 0 || player->GetMapId() != _mapId)
                return false;
            uint32 now = GameTime::GetGameTimeMS();
            if (s->seatedAt != 0 && now - s->seatedAt < 1000)
                return true;   // still settling right after seating / a seat move
            return player->IsSitState() && player->GetDistance(_x, _y, _z) <= LEAVE_RANGE;
        }

        // OPEN/REBUY amounts are additions to the existing stack. Include that
        // stack so the addon can label top-ups and display the resulting blinds.
        void SendBuyinPrompt(Player* player, PokerSeat const* s, char const* command)
        {
            uint32 minimum = s->stack < Config().minBuyIn ? Config().minBuyIn - s->stack : 0;
            uint32 maximum = s->stack < Config().maxBuyIn ? Config().maxBuyIn - s->stack : 0;
            std::ostringstream ss;
            ss << command << " " << minimum << " " << maximum
               << " " << Config().smallBlind << " " << Config().bigBlind << " " << Config().maxBet
               << " " << s->stack;
            SendPokerAddon(player, ss.str());
        }

        // (re)open the table UI for a seated player; show the buy-in prompt if they have not bought in yet
        void SendResume(Player* player)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s || !SeatPresent(player, s))
            {
                // not actually on the chair (a reload stood them up, they are away, or wrong map):
                // keep the window hidden instead of resuming the table
                SendPokerAddon(player, "AWAY");
                return;
            }
            // repair the client's pose reset by re-asserting the chair sit state
            if (s->slot < _chairs.size())
                player->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + _chairs[s->slot].height));
            if (s->state == SEAT_WAIT)
            {
                SendBuyinPrompt(player, s, "OPEN");
            }
            else
            {
                std::ostringstream ss;
                ss << "BACK " << Config().maxBet;   // carry the house cap so the sliders stay correct
                SendPokerAddon(player, ss.str());
            }
        }

        // full private resync: window state, own hole cards, and the current best-hand line
        void ResyncPlayer(Player* player)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s)
                return;
            SendResume(player);
            BroadcastState(); // establish the hand phase before replaying cards after reload
            ResendHole(player);
            SendOwnHand(s);
            if (SeatPresent(player, s) && _phase != PH_WAIT)
                for (PokerSeat* shown : _seats)
                    if (shown->revealed)
                    {
                        std::ostringstream ss;
                        ss << "SHOW " << shown->name << " " << shown->cards[0] << " " << shown->cards[1];
                        SendPokerAddon(player, ss.str());
                        SendPokerAddon(player, "RANK " + shown->name + " " + SeatHandDesc(shown));
                    }
        }

        // resend the player's own hole cards (used after a /reload while they are still in the hand)
        void ResendHole(Player* player)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s || !InHand() || !IsInHand(s->state) || !SeatPresent(player, s))
                return;
            std::ostringstream ss;
            ss << "HOLE " << s->cards[0] << " " << s->cards[1];
            SendPokerAddon(player, ss.str());
        }

        // Both physical returns and explicit chair clicks must undo the temporary
        // away sit-out before clearing its marker. Preserve a deliberate sit-out.
        bool RestoreReturnedSeat(PokerSeat* s)
        {
            bool returned = s->awaySince != 0 || s->leaveAfterHand;
            if (s->awaySince != 0)
            {
                s->sittingOut = s->awaySitOut;
                s->awaySitOut = false;
                s->awaySince = 0;
                s->waitingBB = true;
            }
            s->leaveAfterHand = false;
            s->mailCashout = false;
            return returned;
        }

        // change which chair a player sits at (move to an empty seat around the table)
        void HandleMoveSeat(Player* player, uint32 chairSpawnId)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s)
            {
                SendDeny(player, "NOTSEATED");
                return;
            }
            int slot = FindChairSlot(chairSpawnId);
            if (slot < 0)
                return;
            if (chairSpawnId == s->chairId)
            {
                // clicked own chair: re-seat the player (they may have stood up) and reopen the window
                ChairSlot const& dest = _chairs[slot];
                s->seatedAt = GameTime::GetGameTimeMS();
                RestoreReturnedSeat(s);
                player->TeleportTo(_mapId, dest.x, dest.y, dest.z, dest.o, TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);
                player->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + dest.height));
                OnSeated(player);
                ResyncPlayer(player);
                BroadcastState();
                return;
            }
            if (InHand() && IsInHand(s->state))
            {
                SendDeny(player, "INHAND");
                return;
            }
            if (!SlotIsFree(slot))
            {
                SendDeny(player, "OCCUPIED");
                return;
            }
            ChairSlot const& dest = _chairs[slot];
            s->chairId = dest.spawnId;
            s->slot = static_cast<uint32>(slot);
            SortSeats();                               // re-order so the ring stays consistent
            s->waitingBB = true;                        // moving owes a blind (anti-swap)
            s->seatedAt = GameTime::GetGameTimeMS();   // fresh sync grace for the teleport
            RestoreReturnedSeat(s);
            player->TeleportTo(_mapId, dest.x, dest.y, dest.z, dest.o, TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);
            player->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + dest.height));
            OnSeated(player);
            ResyncPlayer(player);
            BroadcastState();
        }

        void HandleAction(Player* player, std::string const& cmd, uint32 arg)
        {
            PokerSeat* s = FindByPlayer(player->GetGUID());
            if (!s)
            {
                SendDeny(player, "NOTSEATED");
                return;
            }
            // only the seat that is actually on the clock may act. Requiring TM_ACTION also rejects
            // stragglers and crafted actions during the staggered showdown / run-out, when the last
            // actor may still be SEAT_ACTIVE but betting is closed
            if (!InHand() || _timerMode != TM_ACTION || s->chairId != _actorChairId || s->state != SEAT_ACTIVE)
            {
                SendDeny(player, "NOTYOURTURN");
                return;
            }

            if (cmd == "FOLD")
                DoFold(s);
            else if (cmd == "CHECK")
                DoCheck(s);
            else if (cmd == "CALL")
                DoCall(s);
            else if (cmd == "RAISE")
                DoRaise(s, arg);
        }

        void BroadcastState()
        {
            std::ostringstream ss;
            // round a running timer UP: a countdown must never read 0 before it actually fires,
            // otherwise clients briefly draw the "waiting for players" text on the last tick
            ss << "STATE " << uint32(_phase) << " " << (_timerMode != TM_NONE ? (_timer + 999) / 1000 : 0)
               << " " << PotTotal() << " " << _currentBet << " ";
            if (_commCount == 0)
                ss << "-";
            else
                for (uint32 i = 0; i < _commCount; ++i)
                    ss << (i ? "," : "") << _comm[i];
            ss << " " << SlotOfChair(_phase == PH_WAIT ? NextDealerChairId() : _dealerChairId)
               << " " << SlotOfChair(_actorChairId)
               << " " << SlotOfChair(_sbChairId) << " " << SlotOfChair(_bbChairId);
            ss << " " << MinimumRaiseTo();
            for (std::size_t i = 0; i < _seats.size(); ++i)
            {
                PokerSeat const* s = _seats[i];
                ss << " S" << s->slot << " " << s->name << " " << uint32(s->playerClass)
                   << " " << uint32(s->playerRace) << " " << uint32(s->playerGender)
                   << " " << s->stack << " " << s->bet << " "
                   << uint32(s->state) << " " << (s->acted ? "1" : "0") << " " << (s->sittingOut ? "1" : "0") << " " << (s->waitingBB ? "1" : "0") << " I" << s->icon;
            }
            // chair spawn ids in seat-position order so the addon can place seats and offer move targets
            ss << " CHAIRS";
            for (ChairSlot const& c : _chairs)
                ss << " " << c.spawnId;
            std::string msg = ss.str();
            for (Player* p : ConnectedPlayers())
                SendPokerAddon(p, msg);
        }

    private:
        // ---- small helpers ----

        // the smallest stack that can be dealt in: a seat must be able to post its blinds in FULL.
        // Both forced bets must be covered (the big blind is normally the larger), so a partial blind
        // is never posted; a seat that cannot cover it sits the hand out and is prompted to top up.
        // There are no antes or straddles.
        uint32 MinStartStack() const
        {
            return std::max(Config().smallBlind, Config().bigBlind);
        }

        std::size_t ReadyCount() const
        {
            std::size_t n = 0;
            for (PokerSeat const* s : _seats)
                if (s->state == SEAT_BETWEEN && s->stack >= MinStartStack() && !s->sittingOut)
                    ++n;
            return n;
        }

        std::size_t NonFoldedCount() const
        {
            std::size_t n = 0;
            for (PokerSeat const* s : _seats)
                if (IsInHand(s->state) && s->state != SEAT_FOLDED)
                    ++n;
            return n;
        }

        std::size_t ActiveCount() const
        {
            std::size_t n = 0;
            for (PokerSeat const* s : _seats)
                if (s->state == SEAT_ACTIVE)
                    ++n;
            return n;
        }

        uint32 PotTotal() const
        {
            uint32 total = 0;
            for (uint32 forfeit : _forfeit)
                total += forfeit;
            for (PokerSeat const* s : _seats)
                total += s->committed;
            return total;
        }

        // the part of the single deepest contribution that nobody matched. It is returned to that
        // player before the rake, so the house does not tax a bet that was never called. Folded seats
        // and departed escrow count as matched money for this test, but only a live non-folded seat
        // can own the returned excess. Sets ownerIdx to that seat (or -1) and returns the amount.
        uint32 UncalledExcess(int& ownerIdx) const
        {
            uint32 top1 = 0, top2 = 0;
            int topCount = 0;
            int topOwner = -1;
            auto consider = [&](uint32 c, int idx)
            {
                if (c == 0)
                    return;
                if (c > top1) { top2 = top1; top1 = c; topCount = 1; topOwner = idx; }
                else if (c == top1) { ++topCount; topOwner = -1; }
                else if (c > top2) { top2 = c; }
            };
            for (std::size_t i = 0; i < _seats.size(); ++i)
                consider(_seats[i]->committed, static_cast<int>(i));
            for (uint32 forfeit : _forfeit)
                consider(forfeit, -1);   // dead money can tie (blocking a return) but never own one
            if (topCount != 1 || top1 <= top2 || topOwner < 0
                || !IsInHand(_seats[topOwner]->state) || _seats[topOwner]->state == SEAT_FOLDED)
            {
                ownerIdx = -1;
                return 0;
            }
            ownerIdx = topOwner;
            return top1 - top2;
        }

        int IndexOf(uint32 chairId) const
        {
            for (std::size_t i = 0; i < _seats.size(); ++i)
                if (_seats[i]->chairId == chairId)
                    return static_cast<int>(i);
            return -1;
        }

        // the seat the button will move to next hand (display only; mirrors StartHand's rotation):
        // the first eligible seat clockwise after the current dealer, or the current dealer if none
        uint32 NextDealerChairId() const
        {
            if (_seats.empty())
                return _dealerChairId;
            // mirror StartHand: walk the chair ring from the previous dealer's chair (which may
            // still exist after its seat left) to the first eligible seat
            int const prevDealer = FindChairSlot(_dealerChairId);
            if (prevDealer < 0)
            {
                for (PokerSeat const* s : _seats)
                    if (s->state == SEAT_BETWEEN && s->stack >= MinStartStack() && !s->sittingOut)
                        return s->chairId;
                return _dealerChairId;
            }
            int const n = static_cast<int>(_chairs.size());
            for (int step = 1; step <= n; ++step)
            {
                uint32 slot = static_cast<uint32>((prevDealer + step) % n);
                for (PokerSeat const* s : _seats)
                    if (s->slot == slot && s->state == SEAT_BETWEEN && s->stack >= MinStartStack() && !s->sittingOut)
                        return s->chairId;
            }
            return _dealerChairId;
        }

        // keep _seats ordered by table slot so NextActiveIdx walks the ring, not join order
        void SortSeats()
        {
            std::sort(_seats.begin(), _seats.end(),
                [](PokerSeat const* a, PokerSeat const* b) { return a->slot < b->slot; });
        }

        // addon-facing seat slot index of the seat occupying a chair (for dealer/actor highlight)
        int SlotOfChair(uint32 chairId) const
        {
            for (PokerSeat const* s : _seats)
                if (s->chairId == chairId)
                    return static_cast<int>(s->slot);
            return -1;
        }

        // next seat index (after "from") whose state is SEAT_ACTIVE; -1 when none can act.
        // from -1 starts scanning at seat 0
        int NextActiveIdx(int from) const
        {
            int const n = static_cast<int>(_seats.size());
            if (n == 0)
                return -1;
            int i = from < 0 ? n - 1 : from;
            for (int k = 0; k < n; ++k)
            {
                i = (i + 1) % n;
                if (_seats[i]->state == SEAT_ACTIVE)
                    return i;
            }
            return -1;
        }

        PokerSeat* CurrentActor()
        {
            int idx = IndexOf(_actorChairId);
            if (idx < 0)
                return nullptr;
            PokerSeat* s = _seats[idx];
            return s->state == SEAT_ACTIVE ? s : nullptr;
        }

        void SetActor(std::size_t idx)
        {
            // never put a folded / all-in / departed seat on the clock: that leaves a phantom actor
            // whose 30s timer fires against a null CurrentActor() and wedges the hand
            if (idx >= _seats.size() || _seats[idx]->state != SEAT_ACTIVE)
            {
                _actorChairId = 0;
                _timerMode = TM_NONE;
                _timer = 0;
                return;
            }
            _actorChairId = _seats[idx]->chairId;
            _timerMode = TM_ACTION;
            _timer = ACTION_TIMEOUT_MS;
        }

        void StartTimer(TimerMode mode, uint32 ms)
        {
            _timerMode = mode;
            _timer = ms;
        }

        uint32 ToCall(PokerSeat const* s) const
        {
            return s->bet >= _currentBet ? 0 : _currentBet - s->bet;
        }

        // move money from the player's stack into the hand pot (escrow); returns false if short
        bool PostFromStack(PokerSeat* s, uint32 amount)
        {
            uint32 pay = std::min(amount, s->stack);
            s->stack -= pay;
            s->bet += pay;
            s->committed += pay;
            if (s->stack == 0)
                s->state = SEAT_ALLIN;
            return pay == amount;
        }

        Player* FindPlayer(PokerSeat* s) const { return ObjectAccessor::FindConnectedPlayer(s->playerGuid); }

        // everyone who should receive table chat / state: seated, online, and actually at the chair.
        // A player who stood up (or was auto-sat-out) is treated as gone for messaging even though
        // their seat and stack are held for the rejoin grace period.
        std::vector<Player*> ConnectedPlayers() const
        {
            std::vector<Player*> out;
            for (PokerSeat const* s : _seats)
                if (s->awaySince == 0)
                    if (Player* p = ObjectAccessor::FindConnectedPlayer(s->playerGuid))
                        out.push_back(p);
            return out;
        }

        void SendDeny(Player* player, char const* code)
        {
            std::ostringstream ss;
            ss << "DENY " << code;
            SendPokerAddon(player, ss.str());
        }

        void DenySeat(PokerSeat* s, char const* code)
        {
            if (Player* p = FindPlayer(s))
                SendDeny(p, code);
        }

        bool InHand() const
        {
            return _phase == PH_PREFLOP || _phase == PH_FLOP || _phase == PH_TURN || _phase == PH_RIVER || _phase == PH_SHOWDOWN;
        }

        // ---- timer ----

        void OnTimer()
        {
            switch (_timerMode)
            {
                case TM_START:
                    _timerMode = TM_NONE;
                    StartHand();
                    break;
                case TM_ACTION:
                    _timerMode = TM_NONE;
                    if (PokerSeat* actor = CurrentActor())
                        DoAutoAct(actor);
                    break;
                case TM_REVEAL:
                    _timerMode = TM_NONE;
                    RevealNextStreet();
                    break;
                case TM_NEXT:
                    _timerMode = TM_NONE;
                    // "hand complete" beat is over: drop to the waiting countdown to the next hand
                    _phase = PH_WAIT;
                    break;
                case TM_SHOW_ONE:
                    _timerMode = TM_NONE;
                    ShowNextInOrder();
                    break;
                case TM_HOLD:
                    _timerMode = TM_NONE;
                    DoShowdown();   // the showdown pause is over: settle the pot
                    break;
                default:
                    break;
            }
        }

        // ---- hand lifecycle ----

        void StartHand()
        {
            for (PokerSeat* s : _seats)
                s->revealed = false;
            uint32 const bb = Config().bigBlind;

            // (a) players who cannot cover the big blind sit this hand out and are prompted to top up
            for (PokerSeat* s : _seats)
            {
                if (s->state != SEAT_BETWEEN || s->sittingOut || s->stack >= MinStartStack())
                    continue;
                s->state = SEAT_WAIT;
                s->acted = false;
                if (Player* p = FindPlayer(s))
                {
                    SysMsg(p, "You cannot cover the blinds. Buy in again to keep playing.");
                    SendBuyinPrompt(p, s, "REBUY");
                }
            }

            // (b) a player who just sat or moved owes a big blind: they post it (dead) and play from
            //     now on, so nobody can drop in or reposition to dodge the blinds or farm the button
            std::vector<std::size_t> eligible;
            for (std::size_t i = 0; i < _seats.size(); ++i)
            {
                PokerSeat* s = _seats[i];
                if (s->state == SEAT_BETWEEN && s->stack >= MinStartStack() && !s->sittingOut)
                    eligible.push_back(i);
            }

            if (eligible.size() < 2)
            {
                _phase = PH_WAIT;
                BroadcastState();
                return;
            }

            for (std::size_t idx : eligible)
                _seats[idx]->state = SEAT_ACTIVE;

            RefundBalances participants;
            for (std::size_t idx : eligible)
                participants[_seats[idx]->playerGuid.GetCounter()] = _seats[idx]->stack;
            _refundLedger.BeginHand(participants);

            _currentBet = bb;
            _commCount = 0;
            _phase = PH_PREFLOP;
            _lastAggressorChairId = 0;
            _riverFirstToActChairId = 0;
            _runoutRevealed = false;
            _showOrder.clear();
            _showIndex = 0;
            TC_LOG_INFO("misc", "Poker: table {} dealing hand to {} players", _key, eligible.size());

            for (uint32 i = 0; i < 52; ++i)
                _deck[i] = i;
            std::shuffle(_deck.begin(), _deck.end(), _rng);
            _deckTop = 0;

            // rotate the dealer button to the next eligible seat clockwise after the previous dealer.
            // Scan the whole ring, not just the eligible list, so a departed or ineligible previous
            // dealer still advances the button instead of dumping it on the lowest slot.
            int prevDealer = FindChairSlot(_dealerChairId);
            std::size_t dIdx = eligible[0];
            if (prevDealer >= 0)
            {
                int const n = static_cast<int>(_chairs.size());
                for (int step = 1; step <= n; ++step)
                {
                    int slot = (prevDealer + step) % n;
                    auto candidate = std::find_if(eligible.begin(), eligible.end(), [this, slot](std::size_t idx)
                    {
                        return _seats[idx]->slot == static_cast<uint32>(slot);
                    });
                    if (candidate != eligible.end())
                    {
                        dIdx = *candidate;
                        break;
                    }
                }
            }
            _dealerChairId = _seats[dIdx]->chairId;

            // blinds (heads-up: dealer posts the small blind)
            std::size_t sbIdx = dIdx, bbIdx = dIdx;
            if (eligible.size() == 2)
            {
                int b = NextActiveIdx(static_cast<int>(dIdx));
                if (b >= 0) bbIdx = static_cast<std::size_t>(b);
            }
            else
            {
                int s = NextActiveIdx(static_cast<int>(dIdx));
                if (s >= 0) sbIdx = static_cast<std::size_t>(s);
                int b = NextActiveIdx(static_cast<int>(sbIdx));
                if (b >= 0) bbIdx = static_cast<std::size_t>(b);
            }
            _sbChairId = _seats[sbIdx]->chairId;
            _bbChairId = _seats[bbIdx]->chairId;
            PostFromStack(_seats[sbIdx], Config().smallBlind);
            PostFromStack(_seats[bbIdx], bb);

            // a player who owes a big blind posts it as dead money into the pot, unless they are
            // already one of the live blinds this hand (posting that clears the debt instead)
            for (std::size_t idx : eligible)
            {
                PokerSeat* s = _seats[idx];
                if (!s->waitingBB)
                    continue;
                s->waitingBB = false;
                if (idx == sbIdx || idx == bbIdx)
                    continue;
                uint32 pay = std::min(bb, s->stack);
                s->stack -= pay;
                if (s->stack == 0)
                {
                    // the dead post is the whole stack: it becomes a normal all-in contribution so the
                    // player can still win the pot they are all-in for
                    s->committed += pay;
                    s->state = SEAT_ALLIN;
                }
                else
                    _forfeit.push_back(pay);   // otherwise it is dead money: not returned and not winnable
            }

            // hole cards
            _achievementParticipants.clear();
            for (std::size_t idx : eligible)
            {
                PokerSeat* s = _seats[idx];
                _achievementParticipants.push_back(s->playerGuid);
                s->cards[0] = _deck[_deckTop++];
                s->cards[1] = _deck[_deckTop++];
                s->acted = false;
                s->canReraise = true;
                if (Player* p = FindPlayer(s))
                {
                    std::ostringstream ss;
                    ss << "HOLE " << s->cards[0] << " " << s->cards[1];
                    SendPokerAddon(p, ss.str());
                }
            }
            SendAllOwnHands();   // pre-flop: pair / high card from the hole cards

            if (ActiveCount() >= 2)
            {
                int first = (eligible.size() == 2) ? static_cast<int>(dIdx) : NextActiveIdx(static_cast<int>(bbIdx));
                if (first < 0 || _seats[first]->state != SEAT_ACTIVE)
                    first = NextActiveIdx(first);
                if (first >= 0 && _seats[first]->state == SEAT_ACTIVE)
                    SetActor(static_cast<std::size_t>(first));
                else
                {
                    _actorChairId = 0;
                    ShowAllImmediate();   // fewer than two can act: reveal and run the board out
                    StartTimer(TM_REVEAL, REVEAL_DELAY_MS);
                }
            }
            else
            {
                _actorChairId = 0;
                ShowAllImmediate();
                StartTimer(TM_REVEAL, REVEAL_DELAY_MS);
            }

            BroadcastState();
        }

        // ---- actions ----

        void BroadcastAction(char const* action)
        {
            for (Player* p : ConnectedPlayers())
                SendPokerAddon(p, std::string("ACTION ") + action);
        }

        void DoFold(PokerSeat* s)
        {
            s->state = SEAT_FOLDED;
            s->acted = true;
            BroadcastAction("FOLD");
            AfterAction();
        }

        void DoCheck(PokerSeat* s)
        {
            if (ToCall(s) > 0)
            {
                DenySeat(s, "CANTCHECK");
                return;
            }
            s->acted = true;
            BroadcastAction("CHECK");
            AfterAction();
        }

        void DoCall(PokerSeat* s)
        {
            if (ToCall(s) == 0)
            {
                DoCheck(s);
                return;
            }
            PostFromStack(s, ToCall(s));
            s->acted = true;
            AfterAction();
        }

        uint64 MinimumRaiseTo() const
        {
            // House rule: raise to at least twice the live bet. An unopened
            // street still starts at one big blind. Widen before multiplying.
            return _currentBet ? uint64(_currentBet) * 2 : Config().bigBlind;
        }

        void DoRaise(PokerSeat* s, uint32 to)
        {
            uint32 const shoveTo = s->bet + s->stack;   // the true all-in "to" before any cap
            uint32 maxTo = shoveTo;
            uint32 const cap = Config().maxBet;         // 0 = no cap (no-limit)
            if (cap > 0 && cap < maxTo)
                maxTo = cap;
            // house rule: you cannot put in more than the biggest opponent could match, so there
            // is never an uncalled excess. heads-up this is simply the shorter stack.
            uint32 oppMax = 0;
            for (PokerSeat* o : _seats)
                if (o != s && IsInHand(o->state) && o->state != SEAT_FOLDED)
                    oppMax = std::max(oppMax, o->bet + o->stack);
            if (oppMax > 0 && oppMax < maxTo)
                maxTo = oppMax;
            if (to > maxTo)
                to = maxTo;                             // clamp to the callable amount / all-in / table cap
            if (to > _currentBet && !s->canReraise)
                to = _currentBet;                       // a short all-in does not reopen: this is just a call
            if (to <= s->bet)
            {
                DoCall(s);                              // nothing extra to put in: acts as a call/check
                return;
            }
            if (to <= _currentBet)
            {
                // all-in for less than the current bet: acts as a call and does not reopen betting
                PostFromStack(s, to - s->bet);
                s->acted = true;
                AfterAction();
                return;
            }

            bool const allIn = (to == shoveTo);         // true only when the whole stack goes in
            bool const cappedRaise = (to == maxTo);     // putting in the house cap / what opponents can match
            bool const fullRaise = uint64(to) >= MinimumRaiseTo();
            if (!allIn && !cappedRaise && !fullRaise)
            {
                DenySeat(s, "MINRAISE");
                return;
            }

            PostFromStack(s, to - s->bet);
            _currentBet = s->bet;
            _lastAggressorChairId = s->chairId;         // the last bet/raise sets the showdown reveal order
            if (fullRaise)
            {
                // a full raise reopens the action for everyone still to act
                for (PokerSeat* other : _seats)
                    if (other != s && other->state == SEAT_ACTIVE)
                    {
                        other->acted = false;
                        other->canReraise = true;
                    }
            }
            else
            {
                // an incomplete (short all-in) raise does not reopen the betting: anyone who has
                // already acted this street may only call or fold from here on
                for (PokerSeat* other : _seats)
                    if (other != s && other->state == SEAT_ACTIVE && other->acted)
                        other->canReraise = false;
            }
            s->acted = true;
            AfterAction();
        }

        void DoAutoAct(PokerSeat* s)
        {
            if (ToCall(s) > 0)
            {
                SysMsg(FindPlayer(s), "You timed out and folded.");
                DoFold(s);
            }
            else
            {
                SysMsg(FindPlayer(s), "You timed out and checked.");
                DoCheck(s);
            }
        }

        void AfterAction()
        {
            if (NonFoldedCount() <= 1)
            {
                FoldWin();
                return;
            }
            if (!RoundComplete())
            {
                int nxt = NextActiveIdx(IndexOf(_actorChairId));
                if (nxt >= 0 && _seats[nxt]->state == SEAT_ACTIVE)
                    SetActor(static_cast<std::size_t>(nxt));
                else
                    EndRound();   // no one left to act: run the board out instead of wedging
            }
            else
                EndRound();
            BroadcastState();
        }

        bool RoundComplete() const
        {
            for (PokerSeat const* s : _seats)
                if (s->state == SEAT_ACTIVE && !(s->acted && ToCall(s) == 0))
                    return false;
            return true;
        }

        void EndRound()
        {
            for (PokerSeat* s : _seats)
            {
                s->bet = 0;
                s->acted = false;
                s->canReraise = true;   // a new street reopens the betting for everyone
            }
            _currentBet = 0;

            if (ActiveCount() < 2)
            {
                // fewer than two players can still act (everyone else is all-in): reveal and run the board out
                _actorChairId = 0;   // nobody is on the clock while the board runs out
                ShowAllImmediate();
                StartTimer(TM_REVEAL, REVEAL_DELAY_MS);
                return;
            }
            RevealNextStreet();
        }

        void RevealNextStreet()
        {
            switch (_phase)
            {
                case PH_PREFLOP:
                    for (int i = 0; i < 3; ++i)
                        _comm[_commCount++] = _deck[_deckTop++];
                    _phase = PH_FLOP;
                    break;
                case PH_FLOP:
                    _comm[_commCount++] = _deck[_deckTop++];
                    _phase = PH_TURN;
                    break;
                case PH_TURN:
                    _comm[_commCount++] = _deck[_deckTop++];
                    _phase = PH_RIVER;
                    break;
                case PH_RIVER:
                    BeginShowdown();
                    return;
                default:
                    return;
            }

            SendAllOwnHands();   // a new board street: update every in-hand player's best hand
            // Already-revealed hands change on every street of an all-in runout.
            // Hidden hands remain private until SendShow reveals them.
            if (_runoutRevealed)
                for (PokerSeat* s : _seats)
                    if (IsInHand(s->state) && s->state != SEAT_FOLDED)
                        SendRank(s);
            if (_runoutRevealed)
                BroadcastEquity();   // win chances update as each run-out street lands
            _lastAggressorChairId = 0;   // a new betting street: no aggressor yet

            if (ActiveCount() < 2)
            {
                // still not enough players to bet: reveal everyone and keep running the board out
                _actorChairId = 0;   // nobody is on the clock while the board runs out
                ShowAllImmediate();
                StartTimer(TM_REVEAL, REVEAL_DELAY_MS);
                BroadcastState();
                return;
            }
            int firstActive = NextActiveIdx(IndexOf(_dealerChairId));
            if (firstActive < 0)
            {
                _actorChairId = 0;
                ShowAllImmediate();
                StartTimer(TM_REVEAL, REVEAL_DELAY_MS);
                BroadcastState();
                return;
            }
            if (_phase == PH_RIVER)
                _riverFirstToActChairId = _seats[firstActive]->chairId;   // fallback reveal order
            SetActor(static_cast<std::size_t>(firstActive));
            BroadcastState();
        }

        // ---- settlement ----

        // send a system line to everyone at the table (winners, amounts, rake)
        void BroadcastSys(std::string const& text)
        {
            for (Player* p : ConnectedPlayers())
                SysMsg(p, text);
        }

        // ---- showdown reveals ----

        // broadcast a revealed seat's current best hand name (used once the cards are face up)
        void SendRank(PokerSeat* s)
        {
            std::string desc = SeatHandDesc(s);
            if (desc.empty())
                return;
            std::ostringstream ss;
            ss << "RANK " << s->name << " " << desc;
            std::string msg = ss.str();
            for (Player* p : ConnectedPlayers())
                SendPokerAddon(p, msg);
        }

        // broadcast one seat's hole cards so every client can draw them next to that window
        void SendShow(PokerSeat* s)
        {
            s->revealed = true;
            std::ostringstream ss;
            ss << "SHOW " << s->name << " " << s->cards[0] << " " << s->cards[1];
            std::string msg = ss.str();
            for (Player* p : ConnectedPlayers())
                SendPokerAddon(p, msg);
            SendRank(s);   // publish the current description as soon as the cards are face up
        }

        // best hand a seat currently holds (hole + whatever board is out)
        std::string SeatHandDesc(PokerSeat* s) const
        {
            std::vector<uint32> cards = { s->cards[0], s->cards[1] };
            for (uint32 i = 0; i < _commCount; ++i)
                cards.push_back(_comm[i]);
            return DescribeHand(cards);
        }

        // the winner's best five cards as a compact string (for example "A A A K Q")
        std::string SeatBestFiveText(PokerSeat* s) const
        {
            std::vector<uint32> cards = { s->cards[0], s->cards[1] };
            for (uint32 i = 0; i < _commCount; ++i)
                cards.push_back(_comm[i]);
            if (cards.size() < 5)
                return "";
            uint32 five[5];
            BestFive(cards, five);
            std::sort(five, five + 5, [](uint32 a, uint32 b) { return (a / 4) > (b / 4); });
            std::string out;
            for (int j = 0; j < 5; ++j)
            {
                if (j)
                    out += " ";
                out += RankLetter(five[j] / 4);
            }
            return out;
        }

        // privately tell a seat what its current best hand is
        void SendOwnHand(PokerSeat* s)
        {
            if (!s || !IsInHand(s->state) || s->state == SEAT_FOLDED)
                return;
            std::string desc = SeatHandDesc(s);
            if (desc.empty())
                return;
            if (Player* p = FindPlayer(s))
                SendPokerAddon(p, "HAND " + desc);
        }

        void SendAllOwnHands()
        {
            for (PokerSeat* s : _seats)
                SendOwnHand(s);
        }

        // all-in run-out: each live hand's chance to win (Monte Carlo over the remaining board)
        void BroadcastEquity()
        {
            std::vector<PokerSeat*> live;
            for (PokerSeat* s : _seats)
                if (IsInHand(s->state) && s->state != SEAT_FOLDED)
                    live.push_back(s);
            if (live.size() < 2)
                return;

            bool used[52] = { false };
            for (PokerSeat* s : live)
            {
                used[s->cards[0]] = true;
                used[s->cards[1]] = true;
            }
            for (uint32 i = 0; i < _commCount; ++i)
                used[_comm[i]] = true;
            std::vector<uint32> deck;
            for (uint32 c = 0; c < 52; ++c)
                if (!used[c])
                    deck.push_back(c);

            int const need = 5 - static_cast<int>(_commCount);
            int const runs = (need == 0) ? 1 : 20000;
            std::vector<double> eq(live.size(), 0.0);
            uint32 board[5] = { 0, 0, 0, 0, 0 };
            for (uint32 i = 0; i < _commCount; ++i)
                board[i] = _comm[i];

            for (int it = 0; it < runs; ++it)
            {
                for (int j = 0; j < need; ++j)
                {
                    std::size_t span = deck.size() - j;
                    std::size_t pick = _rng() % span;
                    std::swap(deck[j], deck[pick]);
                    board[_commCount + j] = deck[j];
                }
                std::size_t n = live.size();
                uint32 best = 0;
                int nbest = 0;
                std::vector<uint32> sc(n, 0);
                for (std::size_t i = 0; i < n; ++i)
                {
                    uint32 seven[7] = { live[i]->cards[0], live[i]->cards[1], board[0], board[1], board[2], board[3], board[4] };
                    uint32 s = BestSeven(seven);
                    sc[i] = s;
                    if (s > best) { best = s; nbest = 1; }
                    else if (s == best) ++nbest;
                }
                for (std::size_t i = 0; i < n; ++i)
                    if (sc[i] == best)
                        eq[i] += 1.0 / nbest;
            }

            std::ostringstream ss;
            ss << "EQUITY";
            for (std::size_t i = 0; i < live.size(); ++i)
                ss << " " << live[i]->name << " " << static_cast<int>(eq[i] / runs * 100.0 + 0.5);
            std::string msg = ss.str();
            for (Player* p : ConnectedPlayers())
                SendPokerAddon(p, msg);
        }

        // all-in run-out: reveal every remaining hand at once, side-pot order (bigger commitment first)
        void ShowAllImmediate()
        {
            _runoutRevealed = true;

            std::vector<PokerSeat*> showing;
            for (PokerSeat* s : _seats)
                if (IsInHand(s->state) && s->state != SEAT_FOLDED)
                    showing.push_back(s);

            std::stable_sort(showing.begin(), showing.end(),
                [](PokerSeat const* a, PokerSeat const* b) { return a->committed > b->committed; });

            for (PokerSeat* s : showing)
                if (!s->revealed)
                    SendShow(s);
            BroadcastEquity();
        }

        // non-all-in showdown: reveal in order, one player at a time (last aggressor first)
        void BeginStaggeredShowdown()
        {
            _showOrder.clear();
            _showIndex = 0;

            int startIdx = -1;
            if (_lastAggressorChairId != 0)
                startIdx = IndexOf(_lastAggressorChairId);
            if (startIdx < 0 && _riverFirstToActChairId != 0)
                startIdx = IndexOf(_riverFirstToActChairId);
            if (startIdx < 0)
                startIdx = IndexOf(_dealerChairId);
            if (startIdx < 0)
                startIdx = 0;

            int n = static_cast<int>(_seats.size());
            for (int k = 0; k < n; ++k)
            {
                PokerSeat* s = _seats[(startIdx + k) % n];
                if (IsInHand(s->state) && s->state != SEAT_FOLDED)
                    _showOrder.push_back(s->chairId);
            }
            ShowNextInOrder();
        }

        // all hands are face up: hold for a beat so players can compare before the pot is paid
        void BeginSettlement()
        {
            // Do not allow an incomplete reveal sequence to skip a live hand.
            for (PokerSeat* s : _seats)
                if (IsInHand(s->state) && s->state != SEAT_FOLDED && !s->revealed)
                    SendShow(s);
            _actorChairId = 0;
            _timerMode = TM_HOLD;
            _timer = SHOWDOWN_HOLD_MS;
            BroadcastState();
        }

        void ShowNextInOrder()
        {
            while (_showIndex < _showOrder.size())
            {
                uint32 chairId = _showOrder[_showIndex++];
                int idx = IndexOf(chairId);
                if (idx < 0)
                    continue;   // seat left mid-showdown
                PokerSeat* s = _seats[idx];
                if (!IsInHand(s->state) || s->state == SEAT_FOLDED)
                    continue;
                SendShow(s);
                if (_showIndex < _showOrder.size())
                {
                    StartTimer(TM_SHOW_ONE, SHOW_STAGGER_MS);
                    BroadcastState();
                }
                else
                    BeginSettlement();   // last hand revealed: hold, then pay
                return;
            }
            BeginSettlement();
        }

        // rivers resolved: either everyone is already revealed (all-in run-out) or reveal in turn
        void BeginShowdown()
        {
            _phase = PH_SHOWDOWN;
            _actorChairId = 0;      // nobody is on the clock once betting is closed
            _timerMode = TM_NONE;
            if (_runoutRevealed || ActiveCount() < 2)
            {
                ShowAllImmediate();
                BeginSettlement();
            }
            else
                BeginStaggeredShowdown();
        }

        void FoldWin()
        {
            if (!InHand() || NonFoldedCount() > 1)
                return;

            PokerSeat* winner = nullptr;
            for (PokerSeat* s : _seats)
                if (IsInHand(s->state) && s->state != SEAT_FOLDED)
                    winner = s;
            if (!winner)
                return;

            uint32 pot = PotTotal();
            int uncalledOwner = -1;
            uint32 uncalled = UncalledExcess(uncalledOwner);   // the winner's own unmatched bet is not raked
            uint32 rake = (pot - uncalled) / 10;
            uint32 share = pot - rake;

            {
                std::ostringstream ss;
                ss << "RESULT " << rake;
                std::string msg = ss.str();
                for (Player* p : ConnectedPlayers())
                    SendPokerAddon(p, msg);
            }
            {
                std::ostringstream ss;
                ss << "WON " << winner->name << " " << share;
                std::string msg = ss.str();
                for (Player* p : ConnectedPlayers())
                    SendPokerAddon(p, msg);
            }
            Award(winner, share);
            RecordHandAchievements({ { winner, share } }, {});
            {
                std::string const tail = " won " + MoneyStr(share) + " from the poker pot. Rake: " + MoneyStr(rake) + " (10%).";
                for (Player* p : ConnectedPlayers())
                    SysMsg(p, (winner->name == p->GetName() ? std::string("You") : winner->name) + tail);
            }
            EndOfHandHousekeeping();
        }

        void DoShowdown()
        {
            std::vector<PokerSeat*> inHand;
            for (PokerSeat* s : _seats)
                if (IsInHand(s->state))
                    inHand.push_back(s);

            std::unordered_map<ObjectGuid, uint32> scores;
            for (PokerSeat* s : inHand)
            {
                if (s->state == SEAT_FOLDED)
                    continue;
                uint32 seven[7] = { s->cards[0], s->cards[1], _comm[0], _comm[1], _comm[2], _comm[3], _comm[4] };
                scores[s->playerGuid] = BestSeven(seven);
            }

            // the board is complete: publish every revealed hand name (covers the all-in run-out,
            // where the cards were shown street by street and no final SHOW is sent)
            for (PokerSeat* s : inHand)
                if (s->state != SEAT_FOLDED)
                    SendRank(s);

            // the deepest unmatched bet is returned to its owner outside the pot: it is not raked and
            // cannot be won by anyone else. Shrink that seat's commitment so the side-pot math runs on
            // the contested pot only, then credit the excess back after settlement.
            int uncalledIdx = -1;
            uint32 uncalled = UncalledExcess(uncalledIdx);
            if (uncalledIdx >= 0 && uncalled > 0)
                _seats[uncalledIdx]->committed -= uncalled;

            std::vector<uint32> levels;
            for (PokerSeat* s : inHand)
                if (s->committed > 0)
                    levels.push_back(s->committed);
            for (uint32 forfeit : _forfeit)   // departed players' escrow still defines side-pot layers
                if (forfeit > 0)
                    levels.push_back(forfeit);
            std::sort(levels.begin(), levels.end());
            levels.erase(std::unique(levels.begin(), levels.end()), levels.end());

            uint32 pot = PotTotal();           // contested pot, after the uncalled bet was removed
            uint32 rake = pot / 10;
            uint32 distributable = pot - rake;
            uint32 cumDistributed = 0;

            {
                std::ostringstream ss;
                ss << "RESULT " << rake;
                std::string msg = ss.str();
                for (Player* p : ConnectedPlayers())
                    SendPokerAddon(p, msg);
            }

            uint64 rawTotal = 0;
            for (PokerSeat* s : inHand)
                rawTotal += s->committed;
            for (uint32 forfeit : _forfeit)
                rawTotal += forfeit;

            std::vector<std::pair<PokerSeat*, uint32>> awards;
            uint64 rawCum = 0;
            for (std::size_t li = 0; li < levels.size(); ++li)
            {
                uint32 prevLevel = li == 0 ? 0 : levels[li - 1];
                uint32 level = levels[li];

                uint32 layerAmount = 0;
                for (PokerSeat* s : inHand)
                    layerAmount += std::min(s->committed, level) - std::min(s->committed, prevLevel);
                for (uint32 forfeit : _forfeit)
                    layerAmount += std::min(forfeit, level) - std::min(forfeit, prevLevel);
                rawCum += layerAmount;

                std::vector<PokerSeat*> eligible;
                for (PokerSeat* s : inHand)
                    if (s->state != SEAT_FOLDED && s->committed >= level)
                        eligible.push_back(s);

                if (eligible.empty())
                    continue;   // dead money in this layer: folded into the winners' shares below

                // scale the RAW running total to the rake-adjusted pot. The raw total only ever
                // rises, so the scaled target is monotonic and can never underflow into a huge payout
                uint32 target = rawTotal
                    ? static_cast<uint32>((rawCum * distributable) / rawTotal)
                    : 0;
                if (target <= cumDistributed)
                    continue;
                uint32 layerShare = target - cumDistributed;
                cumDistributed = target;

                uint32 best = 0;
                for (PokerSeat* s : eligible)
                    best = std::max(best, scores[s->playerGuid]);

                std::vector<PokerSeat*> winners;
                for (PokerSeat* s : eligible)
                    if (scores[s->playerGuid] == best)
                        winners.push_back(s);

                uint32 base = layerShare / winners.size();
                uint32 rem = layerShare - base * winners.size();
                for (std::size_t wi = 0; wi < winners.size(); ++wi)
                {
                    uint32 amt = base + (wi == 0 ? rem : 0);
                    if (amt == 0)
                        continue;
                    bool merged = false;
                    for (auto& a : awards)
                        if (a.first == winners[wi]) { a.second += amt; merged = true; break; }
                    if (!merged)
                        awards.emplace_back(winners[wi], amt);
                }
            }

            // any leftover (dead money from folds, rounding) goes to the main-pot winner
            if (!awards.empty() && cumDistributed < distributable)
                awards.front().second += distributable - cumDistributed;
            else if (awards.empty())
            {
                // no live commitment built a layer (the whole pot came from departed seats): give the
                // contested pot to the best remaining hand instead of silently destroying it
                PokerSeat* bestSeat = nullptr;
                uint32 bestScore = 0;
                for (PokerSeat* s : inHand)
                    if (s->state != SEAT_FOLDED && (!bestSeat || scores[s->playerGuid] > bestScore))
                    {
                        bestSeat = s;
                        bestScore = scores[s->playerGuid];
                    }
                if (bestSeat && distributable > 0)
                    awards.emplace_back(bestSeat, distributable);
            }

            RecordHandAchievements(awards, scores);
            struct WonPart { ObjectGuid guid; std::string name; std::string text; };
            std::vector<WonPart> wonParts;   // one entry per award, text is "won X with ..."
            std::vector<ObjectGuid> announced;   // name the winning hand once per player, not per side pot
            for (auto const& a : awards)
            {
                std::ostringstream ss;
                ss << "WON " << a.first->name << " " << a.second;
                std::string msg = ss.str();
                for (Player* p : ConnectedPlayers())
                    SendPokerAddon(p, msg);
                Award(a.first, a.second);
                std::string text = "won " + MoneyStr(a.second);
                bool first = true;
                for (ObjectGuid g : announced)
                    if (g == a.first->playerGuid) { first = false; break; }
                if (first)
                {
                    announced.push_back(a.first->playerGuid);
                    std::string desc = SeatHandDesc(a.first);
                    if (!desc.empty())
                        text += " with " + desc;
                    std::string five = SeatBestFiveText(a.first);
                    if (!five.empty())
                        text += " (" + five + ")";
                }
                wonParts.push_back({ a.first->playerGuid, a.first->name, text });
            }
            // return the uncalled bet to its owner (neither raked nor winnable by anyone else)
            if (uncalledIdx >= 0 && uncalled > 0 && uncalledIdx < static_cast<int>(_seats.size()))
                Award(_seats[uncalledIdx], uncalled);
            // per recipient, so the winner reads "You won ..." instead of their own name
            if (!wonParts.empty())
            {
                std::string const tail = " from the poker pot. Rake: " + MoneyStr(rake) + " (10%).";
                for (Player* p : ConnectedPlayers())
                {
                    std::string line;
                    for (WonPart const& wp : wonParts)
                    {
                        if (!line.empty())
                            line += ", ";
                        line += ((wp.guid == p->GetGUID()) ? std::string("You") : wp.name) + " " + wp.text;
                    }
                    SysMsg(p, line + tail);
                }
            }

            EndOfHandHousekeeping();
        }

        void RecordHandAchievements(std::vector<std::pair<PokerSeat*, uint32>> const& awards,
            std::unordered_map<ObjectGuid, uint32> const& scores)
        {
            for (ObjectGuid guid : _achievementParticipants)
            {
                bool won = std::any_of(awards.begin(), awards.end(), [guid](auto const& award)
                    { return award.first->playerGuid == guid && award.second > 0; });
                PokerSeat* seat = nullptr;
                for (PokerSeat* candidate : _seats)
                    if (candidate->playerGuid == guid)
                        seat = candidate;
                uint32 flags = 0;
                if (won && seat)
                {
                    uint32 r0 = seat->cards[0] / 4, r1 = seat->cards[1] / 4;
                    if (((r0 == 0 && r1 == 5) || (r0 == 5 && r1 == 0)) && seat->cards[0] % 4 != seat->cards[1] % 4)
                        flags |= 1u << 10;
                }
                auto score = scores.find(guid);
                if (seat && score != scores.end())
                {
                    uint32 category = score->second >> 20;
                    if (won)
                    {
                        flags |= 1u << category;
                        if (category == 8 && ((score->second >> 16) & 15) == 12)
                            flags |= 1u << 9;
                    }
                    // A stronger hand must contest the same pot; ties and uncalled refunds do not qualify.
                    for (PokerSeat* opponent : _seats)
                    {
                        auto other = scores.find(opponent->playerGuid);
                        if (opponent == seat || other == scores.end() || !seat->committed || !opponent->committed)
                            continue;
                        bool opponentWon = std::any_of(awards.begin(), awards.end(), [opponent](auto const& award)
                            { return award.first == opponent && award.second > 0; });
                        if (!won && category >= 7 && opponentWon && other->second > score->second)
                            flags |= 1u << 11;
                        if (won && category == 5 && opponent->playerClass == CLASS_MAGE && other->second < score->second)
                        {
                            uint32 sharedLevel = std::min(seat->committed, opponent->committed);
                            bool beaten = std::any_of(_seats.begin(), _seats.end(), [&](PokerSeat* contender)
                            {
                                auto rank = scores.find(contender->playerGuid);
                                return rank != scores.end() && contender->committed >= sharedLevel && rank->second > score->second;
                            });
                            if (!beaten)
                                flags |= 1u << 12;
                        }
                    }
                }
                RecordPokerResult(guid, won, flags);
            }
            _achievementParticipants.clear();
        }

        // pay a pot share into the winner's table stack (converted to real money only on cash-out)
        void Award(PokerSeat* s, uint32 amount)
        {
            if (amount == 0)
                return;
            s->stack += amount;
        }

        void EndOfHandHousekeeping()
        {
            _refundLedger.Settle();
            _forfeit.clear();  // dead money has been paid out with this hand's pot
            _currentBet = 0;   // no bet is live between hands (otherwise clients show a stale "to call")
            _actorChairId = 0; // no actor during the hand-complete beat (otherwise a leaving seat re-arms it)
            _lastAggressorChairId = 0;
            // keep the board/reveals up through the "hand complete" beat; the client hides them
            // once the next hand is waiting, and StartHand clears the board for the new hand
            _runoutRevealed = false;
            _showOrder.clear();
            _showIndex = 0;

            std::vector<PokerSeat*> busted;
            for (PokerSeat* s : _seats)
            {
                s->committed = 0;   // escrow is settled; clear it so it cannot leak into the next hand
                s->bet = 0;
                if (IsInHand(s->state))
                    s->state = SEAT_BETWEEN;
                if (s->stack == 0 && s->state != SEAT_WAIT && !s->leaveAfterHand)
                    busted.push_back(s);
            }
            for (PokerSeat* s : busted)
            {
                // out of chips: stay in the seat and prompt a re-buy rather than being stood up
                s->state = SEAT_WAIT;
                s->acted = false;
                if (Player* p = FindPlayer(s))
                {
                    SysMsg(p, "You are out of chips. Buy in again to keep playing.");
                    SendBuyinPrompt(p, s, "REBUY");
                }
            }

            // seats that were away too long during the hand leave now that it has settled
            std::vector<PokerSeat*> leaving;
            for (PokerSeat* s : _seats)
                if (s->leaveAfterHand)
                    leaving.push_back(s);
            for (PokerSeat* s : leaving)
                LeaveSeat(s);

            // always give the "hand complete" beat, even when only one player is left with chips:
            // without it an all-in run-out that busts someone jumps straight to "waiting for players"
            // and the client hides the board before the result can be read
            _phase = PH_SHOWDOWN;
            StartTimer(TM_NEXT, HAND_COMPLETE_MS);
            BroadcastSys("Hand complete.");
            BroadcastState();
        }

        // ---- leaving ----

        void LeaveSeat(PokerSeat* s, bool mailOnly = false)
        {
            if (std::find(_seats.begin(), _seats.end(), s) == _seats.end())
                return;

            Player* p = FindPlayer(s);
            bool wasActor = (s->chairId == _actorChairId);
            // if the acting player is leaving, resolve their successor BEFORE the seat is erased
            uint32 nextActorChairId = 0;
            int removedIdx = IndexOf(s->chairId);
            if (InHand() && wasActor && removedIdx >= 0)
            {
                int nxt = NextActiveIdx(removedIdx);
                if (nxt >= 0 && _seats[nxt]->state == SEAT_ACTIVE)
                    nextActorChairId = _seats[nxt]->chairId;
            }

            // any escrow still committed to the running hand stays in the pot: removing the seat
            // takes it out of the active PotTotal() sum, so keep it per-commitment for side pots
            if (s->committed > 0)
                _forfeit.push_back(s->committed);
            s->committed = 0;

            uint32 cashout = s->stack;   // pay the remaining stack out; escrow stays in the pot
            _refundLedger.CashOut(s->playerGuid.GetCounter(), cashout);
            s->stack = 0;
            ObjectGuid guid = s->playerGuid;
            bool mailCashed = mailOnly || s->mailCashout;
            s->state = SEAT_FOLDED;

            auto it = std::find(_seats.begin(), _seats.end(), s);
            _seats.erase(it);
            delete s;

            uint32 paid = 0;
            if (cashout > 0)
                // logging out: mail the stack, because a wallet credit after the logout save is lost
                paid = PokerCashOut(mailCashed ? nullptr : p, guid, cashout);

            if (p)
            {
                OnUnseated(p);
                p->SetStandState(UNIT_STAND_STATE_STAND);
                std::ostringstream ss;
                ss << "LEAVEOK " << cashout;
                SendPokerAddon(p, ss.str());
                SysMsg(p, "You left the poker table.");
                if (paid > 0)
                    SysMsg(p, MoneyStr(paid) + " was returned to you.");
            }

            // the leaver was the only live hand left: nobody else can win, so pay them the pot
            // (escrow included) instead of stranding it for the destructor to drop
            if (InHand() && NonFoldedCount() == 0)
            {
                RecordHandAchievements({}, {});
                _refundLedger.Settle();
                uint32 stranded = PotTotal();
                _forfeit.clear();
                for (PokerSeat* other : _seats)
                    other->committed = 0;
                if (stranded > 0)
                {
                    uint32 extra = PokerCashOut(mailCashed ? nullptr : p, guid, stranded);
                    if (p && extra > 0)
                        SysMsg(p, MoneyStr(extra) + " from the pot was returned to you.");
                }
            }

            if (_seats.empty())
            {
                _markedForDelete = true;
                return;
            }

            if (InHand() && _timerMode != TM_SHOW_ONE && _timerMode != TM_HOLD)   // let a reveal / showdown hold finish
            {
                if (NonFoldedCount() <= 1)
                    FoldWin();
                else if (wasActor)
                {
                    int idx = nextActorChairId ? IndexOf(nextActorChairId) : -1;
                    if (idx >= 0 && _seats[idx]->state == SEAT_ACTIVE)
                        SetActor(static_cast<std::size_t>(idx));
                    else
                        EndRound();   // no successor can act: run the board out instead of wedging
                }
            }
            BroadcastState();
        }

        // ---- seat validation ----

        void ValidateSeats()
        {
            uint32 now = GameTime::GetGameTimeMS();
            std::vector<PokerSeat*> gone;
            bool changed = false;
            for (PokerSeat* s : _seats)
            {
                Player* p = ObjectAccessor::FindConnectedPlayer(s->playerGuid);
                if (!p)
                {
                    // a live hand cannot lose an active/all-in seat: settle it first, then drop the seat
                    if (InHand() && (s->state == SEAT_ACTIVE || s->state == SEAT_ALLIN))
                        s->leaveAfterHand = true;
                    else
                        gone.push_back(s);
                    continue;
                }
                // skip the stand-sync grace window right after seating (client takes a moment to settle on the chair)
                if (s->seatedAt != 0 && now - s->seatedAt < 1000)
                    continue;

                bool present = p->GetMapId() == _mapId && p->IsSitState() && p->GetDistance(_x, _y, _z) <= LEAVE_RANGE;
                if (present)
                {
                    // returned to the chair within the grace period: cancel any pending eviction and
                    // restore their sit-out choice
                    if (RestoreReturnedSeat(s))
                    {
                        ResyncPlayer(p);       // reopen as OPEN (unbought) or BACK, resend hole + hand line
                        SysMsg(p, s->sittingOut ? "You returned to your seat. You are still sitting out."
                                               : "You returned to your seat.");
                        changed = true;
                    }
                }
                else if (s->awaySince == 0)
                {
                    // just left the chair / stood up: keep the seat for a grace period so they can
                    // come back, and auto sit out the next hand
                    s->awaySince = now;
                    s->awaySitOut = s->sittingOut;   // remember a deliberate sit-out to restore on return
                    s->sittingOut = true;
                    SendPokerAddon(p, "AWAY");
                    std::string grace = std::to_string(AWAY_GRACE_MS / 1000) + " seconds";
                    if (s->state == SEAT_ACTIVE)
                        SysMsg(p, "You stood up. You will auto-check or fold on your turn; if you do not return within " + grace + " your chips are refunded to you and you leave the table.");
                    else
                        SysMsg(p, "You stood up and are sitting out the next hand; if you do not return within " + grace + " your chips are refunded to you and you leave the table.");
                    changed = true;
                }
                else if (now - s->awaySince >= AWAY_GRACE_MS)
                {
                    // a live hand cannot lose an active/all-in seat (it would kill the running
                    // hand): mark them to leave once the hand settles instead
                    if (InHand() && (s->state == SEAT_ACTIVE || s->state == SEAT_ALLIN))
                    {
                        if (!s->leaveAfterHand)
                        {
                            s->leaveAfterHand = true;
                            SysMsg(p, "You were away from your seat too long; you will leave when the hand ends.");
                        }
                    }
                    else
                    {
                        gone.push_back(s);   // LeaveSeat sends the "You left the poker table." notice
                    }
                }
            }
            for (PokerSeat* s : gone)
            {
                TC_LOG_INFO("misc", "Poker: removing seat {} (key {})", s->name, _key);
                LeaveSeat(s);
            }
            if (changed && !_markedForDelete)
                BroadcastState();
        }

        // ---- data ----

        uint32 _key;
        SouthportPoker::RefundLedger _refundLedger;
        std::vector<PokerSeat*> _seats;

        Phase _phase = PH_WAIT;
        TimerMode _timerMode = TM_NONE;
        uint32 _timer = 0;
        uint32 _broadcastAcc = 0;

        uint32 _dealerChairId = 0;
        uint32 _actorChairId = 0;   // 0 = none; spawn ids are never 0
        uint32 _sbChairId = 0;      // small-blind seat for the current hand
        uint32 _bbChairId = 0;      // big-blind seat for the current hand
        uint32 _currentBet = 0;

        // showdown reveal state
        uint32 _lastAggressorChairId = 0;    // last bet/raiser on the current street
        uint32 _riverFirstToActChairId = 0;  // fallback when the river was checked around
        bool _runoutRevealed = false;        // SHOW already broadcast for this all-in run-out
        std::vector<uint32> _showOrder;      // chair ids to reveal, in order
        std::size_t _showIndex = 0;

        std::vector<uint32> _forfeit;   // dead escrow from departed seats, kept per commitment for side pots
        std::vector<ObjectGuid> _achievementParticipants;

        // ---- seat slots (fixed positions around the table, from the chair gameobjects) ----
        struct ChairSlot
        {
            uint32 spawnId = 0;
            float x = 0.0f, y = 0.0f, z = 0.0f, o = 0.0f;
            uint32 height = 1;
        };
        std::vector<ChairSlot> _chairs;

        std::array<uint32, 52> _deck;
        uint32 _deckTop = 0;
        uint32 _comm[5] = { 0, 0, 0, 0, 0 };
        uint32 _commCount = 0;

        std::mt19937 _rng{ std::random_device{}() };

        uint32 _mapId = 0;
        float _x = 0.0f, _y = 0.0f, _z = 0.0f;
        bool _markedForDelete = false;
    };

    class PokerMgr
    {
    public:
        static PokerMgr* instance()
        {
            static PokerMgr mgr;
            return &mgr;
        }

        bool CanEnable()
        {
            // Multiple character workers may race an older full character save
            // against a newer poker wallet transaction. Require the ordered queue.
            if (sConfigMgr->GetIntDefault("CharacterDatabase.WorkerThreads", 1) != 1)
            {
                TC_LOG_ERROR("misc", "Poker disabled: CharacterDatabase.WorkerThreads must be 1 for ordered wallet saves.");
                return false;
            }
            if (!sObjectMgr->GetCreatureTemplate(5000017))
            {
                TC_LOG_ERROR("misc", "Poker disabled: Southport Casino mail sender 5000017 is missing.");
                return false;
            }
            QueryResult engines = CharacterDatabase.QueryNoRetry("SELECT COUNT(*) FROM information_schema.tables "
                "WHERE table_schema = DATABASE() AND table_name IN ('characters', 'mail', 'poker_refund_escrow', 'character_achievement', 'character_achievement_progress') "
                "AND engine = 'InnoDB'");
            if (!engines || engines->Fetch()[0].GetUInt32() != 5)
            {
                TC_LOG_ERROR("misc", "Poker disabled: characters, mail, poker_refund_escrow and native achievement tables must exist and use InnoDB. "
                    "Install poker_refund_escrow.sql and poker_achievements.sql in the character database.");
                return false;
            }
            if (!ValidatePokerAchievements())
            {
                TC_LOG_ERROR("misc", "Poker disabled: install the matching poker achievement DBC files.");
                return false;
            }
            // COUNT distinguishes an empty journal from a missing/unavailable table.
            QueryResult count = CharacterDatabase.QueryNoRetry("SELECT COUNT(*) FROM poker_refund_escrow");
            if (!count)
            {
                TC_LOG_ERROR("misc", "Poker disabled: install poker_refund_escrow.sql in the character database.");
                return false;
            }
            return true;
        }

        // Mail every outstanding refund claim and delete it in one transaction. Shared
        // by startup and in-process recovery; a crash leaves either the claim or its mail.
        bool RecoverEscrow()
        {
            QueryResult count = CharacterDatabase.QueryNoRetry("SELECT COUNT(*) FROM poker_refund_escrow");
            if (!count)
                return false;
            if (count->Fetch()[0].GetUInt64() == 0)
                return true;

            QueryResult rows = CharacterDatabase.QueryNoRetry("SELECT guid, amount FROM poker_refund_escrow ORDER BY guid");
            if (!rows)
                return false;

            g_pokerTransaction = CharacterDatabase.BeginTransaction();
            uint64 refunded = 0;
            do
            {
                Field* fields = rows->Fetch();
                uint64 guid = fields[0].GetUInt64();
                uint64 remaining = fields[1].GetUInt64();
                refunded += remaining;
                // One player can leave one running table and join another.
                // Split combined claims into mail attachments below the gold cap.
                while (remaining)
                {
                    uint32 chunk = static_cast<uint32>(std::min<uint64>(remaining, MAX_MONEY_AMOUNT));
                    MailPokerMoney(ObjectGuid::Create<HighGuid::Player>(static_cast<ObjectGuid::LowType>(guid)), chunk, true);
                    remaining -= chunk;
                }
                g_pokerTransaction->PAppend("DELETE FROM poker_refund_escrow WHERE guid = {}", guid);
            } while (rows->NextRow());

            bool committed = (CommitPoker(g_pokerTransaction) == TransactionOutcome::Committed);
            g_pokerTransaction.reset();
            if (!committed)
            {
                TC_LOG_ERROR("misc", "Poker recovery was not confirmed; poker remains disabled. "
                    "Committed mail and remaining refund records will be checked on the next recovery attempt.");
                return false;
            }
            TC_LOG_INFO("misc", "Poker recovery: mailed {} copper from saved refund records.", refunded);
            return true;
        }

        void Recover()
        {
            g_pokerReady = false;
            if (!CanEnable())
                return;
            if (!RecoverEscrow())
                return;
            _persisted.clear();
            g_pokerReady = true;
        }

        // Free every table so recovery starts from an empty, DB-reconciled state. Seated
        // players are stood up without being paid; escrow mail returns their gold.
        void TearDownTables()
        {
            for (auto& pair : _tables)
            {
                pair.second->ForceCloseForRecovery();
                delete pair.second;
            }
            _tables.clear();
        }

        // Recover poker in-process after a failed money transaction.
        // walletsAreCertain: true when the DB confirmed a rollback, so the pre-action
        // in-memory wallets can be restored; false when the outcome is unknown and the
        // affected wallets were already quarantined by the caller.
        bool AttemptRecover(bool walletsAreCertain)
        {
            // Recovery must not run while a journal transaction is open, or the
            // teardown notices would be queued and then dropped. A release build
            // must fail closed here rather than continue with a broken invariant.
            if (g_pokerTransaction)
            {
                TC_LOG_ERROR("misc", "Poker: cannot recover while a money transaction is open.");
                return false;
            }
            g_pokerReady = false;
            if (walletsAreCertain)
                for (auto const& wallet : g_originalWallets)
                    if (Player* player = ObjectAccessor::FindConnectedPlayer(wallet.first))
                        player->SetMoney(wallet.second);
            TearDownTables();
            if (!CanEnable())
                return false;
            if (!RecoverEscrow())
                return false;
            _persisted.clear();
            g_pokerReady = true;
            TC_LOG_INFO("misc", "Poker: in-process recovery succeeded; poker is re-enabled.");
            return true;
        }

        template <typename Action>
        void RunDurably(Action action)
        {
            if (!g_pokerReady)
                return;
            ASSERT(!g_pokerTransaction);
            g_originalWallets.clear();
            g_pendingMessages.clear();
            g_pendingAchievementPlayers.clear();
            g_pokerTransaction = CharacterDatabase.BeginTransaction();
            action();

            RefundBalances next;
            for (auto const& table : _tables)
                for (auto const& balance : table.second->Recoverable())
                    if (balance.second)
                        next[balance.first] += balance.second;

            for (auto const& balance : next)
            {
                auto old = _persisted.find(balance.first);
                if (old == _persisted.end() || old->second != balance.second)
                    g_pokerTransaction->PAppend("INSERT INTO poker_refund_escrow (guid, amount) VALUES ({}, {}) "
                        "ON DUPLICATE KEY UPDATE amount = VALUES(amount)", balance.first, balance.second);
            }
            for (auto const& old : _persisted)
                if (next.find(old.first) == next.end())
                    g_pokerTransaction->PAppend("DELETE FROM poker_refund_escrow WHERE guid = {}", old.first);

            for (auto const& wallet : g_originalWallets)
                if (Player* player = ObjectAccessor::FindConnectedPlayer(wallet.first))
                    if (player->GetMoney() != wallet.second)
                        player->SaveGoldToDB(g_pokerTransaction);

            TransactionOutcome outcome = TransactionOutcome::Committed;
            if (g_pokerTransaction->GetSize() != 0)
                outcome = CommitPoker(g_pokerTransaction);
            g_pokerTransaction.reset();
            if (outcome != TransactionOutcome::Committed)
            {
                g_pendingMessages.clear();
                g_pendingAchievementPlayers.clear();
                g_pokerReady = false;

                bool walletsAreCertain = (outcome == TransactionOutcome::RolledBack);
                if (walletsAreCertain)
                    // The DB confirmed a rollback, so the pre-action wallets are
                    // authoritative again and are restored by AttemptRecover.
                    TC_LOG_ERROR("misc", "Poker money transaction rolled back; resetting tables in-process.");
                else
                {
                    // A failed acknowledgement does not prove rollback. Do not write
                    // either wallet guess back over the database. Disconnect only
                    // affected wallet owners without saving their uncertain state;
                    // a new login reads the DB's actual outcome. Mail uses GUID-only
                    // receivers, so no online mail-cache mutation needs undoing.
                    TC_LOG_ERROR("misc", "Poker money transaction outcome unknown; resetting tables in-process and quarantining changed wallets.");
                    for (auto const& wallet : g_originalWallets)
                        if (Player* player = ObjectAccessor::FindConnectedPlayer(wallet.first))
                            if (player->GetMoney() != wallet.second)
                            {
                                _uncertainWallets.insert(wallet.first);
                                player->SuspendCharacterSaves();
                                player->GetSession()->KickPlayer("Unconfirmed poker wallet transaction; reload authoritative database balance");
                            }
                }

                if (AttemptRecover(walletsAreCertain))
                    return;

                // AttemptRecover already tore the tables down; poker stays disabled
                // until a manual retry or a restart can confirm the journal.
                TC_LOG_ERROR("misc", "Poker disabled after a failed money transaction; use '.poker recover' or restart to retry recovery.");
                return;
            }
            _persisted = std::move(next);
            for (ObjectGuid guid : g_pendingAchievementPlayers)
                if (Player* player = ObjectAccessor::FindConnectedPlayer(guid))
                    SyncPlayerPokerAchievements(player);
            g_pendingAchievementPlayers.clear();
            for (PendingPokerMessage const& message : g_pendingMessages)
                if (Player* player = ObjectAccessor::FindConnectedPlayer(message.receiver))
                {
                    if (message.system)
                        SysMsg(player, message.text);
                    else
                        SendPokerAddon(player, message.text);
                }
            g_pendingMessages.clear();
            g_originalWallets.clear();
        }

        void ResolveUncertainLogin(Player* player)
        {
            if (_uncertainWallets.find(player->GetGUID()) == _uncertainWallets.end())
                return;
            // A locking current read waits for the old payment's row lock. This
            // avoids trusting a login snapshot read before that payment finished.
            std::string sql = Trinity::StringFormat("SELECT money FROM characters WHERE guid = {} FOR UPDATE",
                player->GetGUID().GetCounter());
            QueryResult result = CharacterDatabase.QueryNoRetry(sql.c_str());
            if (!result)
            {
                player->SuspendCharacterSaves();
                player->GetSession()->KickPlayer("Poker wallet is still awaiting database confirmation");
                return;
            }
            player->SetMoney(result->Fetch()[0].GetUInt32());
            _uncertainWallets.erase(player->GetGUID());
            SysMsg(player, "Your gold balance was reloaded from the database after a poker payment error. "
                "Any unpaid table gold is returned by poker recovery.");
        }

        void HandleChairUse(Player* player, GameObject* go)
        {
            if (!player || !go)
                return;
            if (player->IsInCombat())
            {
                SysMsg(player, "You cannot sit down while in combat.");
                return;
            }

            uint32 tableId = TableIdForChair(go->GetSpawnId());

            if (PokerTable* existing = FindByPlayer(player->GetGUID()))
            {
                // already seated: right-clicking a free chair at the same table moves them there
                if (existing->Key() == tableId)
                {
                    existing->PopulateChairs(go, tableId, CHAIR_ENTRY, 12.0f);
                    existing->HandleMoveSeat(player, go->GetSpawnId());
                }
                else
                    SysMsg(player, "You are already at a poker table.");
                return;
            }

            PokerTable* table = FindByKey(tableId);
            if (!table)
            {
                // free any table still parked for deletion so replacing it does not leak the object
                auto stale = _tables.find(tableId);
                if (stale != _tables.end())
                {
                    delete stale->second;
                    _tables.erase(stale);
                }
                table = new PokerTable(tableId);
                _tables[tableId] = table;
            }
            // discover this table's chairs (grouped by `poker_chair`) and order the slots
            table->PopulateChairs(go, tableId, CHAIR_ENTRY, 12.0f);

            if (table->SeatCount() >= table->Config().maxSeats)
            {
                SysMsg(player, "That poker table is full.");
                return;
            }
            if (!table->AddSeat(player, go->GetSpawnId()))
            {
                // an empty table that could not seat the player (chair outside the ring) would leak
                if (table->SeatCount() == 0)
                {
                    auto self = _tables.find(tableId);
                    if (self != _tables.end() && self->second == table)
                    {
                        delete table;
                        _tables.erase(self);
                    }
                }
                return;
            }
            TC_LOG_INFO("misc", "Poker: {} seated (tableId {}, seats {})", player->GetName(), table->Key(), table->SeatCount());

            // seat the player ourselves (we swallowed the vanilla chair use)
            player->TeleportTo(go->GetMapId(), go->GetPositionX(), go->GetPositionY(), go->GetPositionZ(),
                go->GetOrientation(), TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET);
            uint32 chairHeight = 1;
            if (GameObjectTemplate const* info = go->GetGOInfo())
                chairHeight = info->chair.height;
            player->SetStandState(UnitStandStateType(UNIT_STAND_STATE_SIT_LOW_CHAIR + chairHeight));
            OnSeated(player);

            SysMsg(player, "You took a seat at the poker table.");
            std::ostringstream ss;
            ss << "OPEN " << table->Config().minBuyIn << " " << table->Config().maxBuyIn
               << " " << table->Config().smallBlind << " " << table->Config().bigBlind << " " << table->Config().maxBet;
            SendPokerAddon(player, ss.str());
            table->BroadcastState();
        }

        PokerTable* FindByKey(uint32 key)
        {
            auto it = _tables.find(key);
            // never hand back a table that is already scheduled for deletion: a player could be
            // seated into it and then lose their seat (and stack) when Update deletes the table
            if (it == _tables.end() || it->second->IsMarkedForDelete())
                return nullptr;
            return it->second;
        }

        PokerTable* FindByPlayer(ObjectGuid guid)
        {
            for (auto& pair : _tables)
                if (pair.second->FindByPlayer(guid))
                    return pair.second;
            return nullptr;
        }

        void HandleAddonMessage(Player* player, std::string const& payload)
        {
            if (!player || payload.empty())
                return;

            std::istringstream ss(payload);
            std::string cmd;
            ss >> cmd;
            uint32 arg = 0;
            if (cmd == "RAISE" || cmd == "MOVE" || cmd == "BUYIN" || cmd == "SITOUT" || cmd == "ICON")
                if (!(ss >> arg))
                    return;

            PokerTable* table = FindByPlayer(player->GetGUID());

            // HELLO is a resync request: answer only if seated, and never as a "not seated" deny
            if (cmd == "HELLO")
            {
                if (table)
                {
                    table->ResyncPlayer(player);   // window + own hole cards + best-hand line
                    table->BroadcastState();
                }
                return;
            }

            // RELOAD: the client interface reloaded, which stands the character up; do not resume
            if (cmd == "RELOAD")
            {
                if (table)
                    table->HandleReload(player);
                return;
            }

            if (!table)
            {
                SendPokerAddon(player, "DENY NOTSEATED");
                return;
            }

            if (cmd == "BUYIN")
                table->HandleBuyin(player, arg);
            else if (cmd == "FOLD" || cmd == "CHECK" || cmd == "CALL" || cmd == "RAISE")
                table->HandleAction(player, cmd, arg);
            else if (cmd == "MOVE")
                table->HandleMoveSeat(player, arg);
            else if (cmd == "SITOUT")
                table->HandleSitOut(player, arg != 0);
            else if (cmd == "ICON")
                table->HandleIcon(player, arg);
            else if (cmd == "LEAVE")
                table->HandleLeave(player);
        }

        void HandleLogout(Player* player)
        {
            if (PokerTable* table = FindByPlayer(player->GetGUID()))
                table->HandleLogout(player);
        }

        void Update(uint32 diff)
        {
            std::vector<uint32> dead;
            for (auto& pair : _tables)
            {
                pair.second->Tick(diff);
                if (pair.second->IsMarkedForDelete())
                    dead.push_back(pair.first);
            }
            for (uint32 key : dead)
            {
                delete _tables[key];
                _tables.erase(key);
            }
        }

    private:
        RefundBalances _persisted;
        std::unordered_set<ObjectGuid> _uncertainWallets;
        std::unordered_map<uint32, PokerTable*> _tables;
    };

    // ---- script classes ----

    class PokerChairAI : public GameObjectAI
    {
    public:
        PokerChairAI(GameObject* go) : GameObjectAI(go) { }

        bool OnGossipHello(Player* player) override
        {
            if (!g_pokerReady)
                SysMsg(player, "Poker is unavailable until its database recovery succeeds.");
            else
                PokerMgr::instance()->RunDurably([&] { PokerMgr::instance()->HandleChairUse(player, me); });
            return true; // swallow the vanilla chair seating; we seat the player ourselves
        }
    };

    class PokerChairScript : public GameObjectScript
    {
    public:
        PokerChairScript() : GameObjectScript("PokerChair") { }

        GameObjectAI* GetAI(GameObject* go) const override
        {
            return new PokerChairAI(go);
        }
    };

    class PokerPlayerScript : public PlayerScript
    {
    public:
        PokerPlayerScript() : PlayerScript("PokerPlayerScript") { }

        void OnChat(Player* player, uint32 type, uint32 lang, std::string& msg, Player* /*receiver*/) override
        {
            if (type != CHAT_MSG_WHISPER || lang != uint32(LANG_ADDON))
                return;
            // addon whispers arrive as "prefix\t<cmd>"; only accept our prefix
            std::size_t tab = msg.find('\t');
            if (tab == std::string::npos || msg.compare(0, tab, ADDON_PREFIX) != 0)
                return;
            std::string payload = msg.substr(tab + 1);
            PokerMgr::instance()->RunDurably([&] { PokerMgr::instance()->HandleAddonMessage(player, payload); });
        }

        void OnLogout(Player* player) override
        {
            PokerMgr::instance()->RunDurably([&] { PokerMgr::instance()->HandleLogout(player); });
        }

        void OnLogin(Player* player, bool /*firstLogin*/) override
        {
            PokerMgr::instance()->ResolveUncertainLogin(player);
            SyncPlayerPokerAchievements(player);
        }
    };

    class PokerWorldScript : public WorldScript
    {
    public:
        PokerWorldScript() : WorldScript("PokerWorldScript") { }

        void OnStartup() override
        {
            LoadPokerConfig();
            PokerMgr::instance()->Recover();
        }

        void OnConfigLoad(bool /*reload*/) override
        {
            LoadPokerConfig();   // also refresh on `.reload config`
        }

        void OnUpdate(uint32 diff) override
        {
            static uint32 acc = 0;
            acc += diff;
            if (acc < 200)
                return;
            uint32 step = acc;
            acc = 0;
            PokerMgr::instance()->RunDurably([&] { PokerMgr::instance()->Update(step); });
        }
    };

    class PokerCommandScript : public CommandScript
    {
    public:
        PokerCommandScript() : CommandScript("PokerCommandScript") { }

        ChatCommandTable GetCommands() const override
        {
            // Recovery is an administrative database operation; reuse the
            // server-info permission rather than add a new RBAC entry.
            static ChatCommandTable commandTable =
            {
                { "poker status",  HandlePokerStatusCommand,  rbac::RBAC_PERM_COMMAND_SERVER_INFO, Console::No },
                { "poker recover", HandlePokerRecoverCommand, rbac::RBAC_PERM_COMMAND_SERVER_INFO, Console::No }
            };
            return commandTable;
        }

        static bool HandlePokerStatusCommand(ChatHandler* handler)
        {
            handler->SendSysMessage(g_pokerReady
                ? "Poker is running."
                : "Poker is paused after a database error. Use '.poker recover' once the database is available.");
            return true;
        }

        static bool HandlePokerRecoverCommand(ChatHandler* handler)
        {
            if (g_pokerReady)
            {
                handler->SendSysMessage("Poker is already running.");
                return true;
            }
            if (PokerMgr::instance()->AttemptRecover(false))
            {
                handler->SendSysMessage("Poker recovery succeeded; poker is available again.");
                return true;
            }
            handler->SendSysMessage("Poker recovery failed; verify the database is reachable and check the server log.");
            handler->SetSentErrorMessage(true);
            return false;
        }
    };
} // anonymous namespace

void AddSC_poker()
{
    // Register the poker criteria range before any player can load, so ordinary
    // game events can never advance it.
    AchievementMgr::RegisterExternalCriteriaRange(PokerAchievements::FirstCriteria, PokerAchievements::LastCriteria);
    new PokerChairScript();
    new PokerPlayerScript();
    new PokerWorldScript();
    new PokerCommandScript();
}
