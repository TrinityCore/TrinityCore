-- creature_onkill_reputation correction #2: -1 reputation/kill (the value
-- 2026_09_21_00_world.sql just fixed the SIGN of) is itself too fragile a
-- magnitude. Player::CalculateReputationGain() (src/server/game/Entities/
-- Player/Player.cpp) applies faction/racial modifiers as a percentage, and
-- CalculatePct() (src/common/Utilities/Util.h) truncates the float result
-- toward zero when converting to int32 - it does not round. Any modifier
-- other than exactly 100% (e.g. the Human "Diplomacy" racial, +10% to
-- SPELL_AURA_MOD_REPUTATION_GAIN) can therefore truncate a magnitude-1
-- value to exactly 0 before ModifyReputation() ever sees it:
--   -1 rep * (100% - 10%) / 100 = -0.9  ->  int32(-0.9f) = 0
-- silently discarding the reward instead of applying a smaller one. -10 is
-- immune to this specific case (-10 * 90% = -9.0 exactly, no fractional
-- part to lose) and is also a more reasonable V1 gameplay magnitude - -1
-- rep/kill would have needed thousands of kills to move a single standing
-- tier.
--
-- This is a CORRECTIVE migration on top of 2026_09_21_00_world.sql, not a
-- rewrite of it - that file is already applied on any deployed server and
-- the updater does not re-apply a migration under the same filename.
--
-- entry list and target value are exactly data/elwynn/factions/
-- world_faction_assignments.csv's own `onkill_rep_value` column (now -10
-- for all 32 `tc_faction_action = CLONED` rows) - regenerate/re-verify this
-- migration against that CSV if either the entry list or the value ever
-- changes again.
UPDATE `creature_onkill_reputation`
SET `RewOnKillRepValue1` = -10
WHERE `creature_id` IN (6, 38, 40, 46, 60, 61, 79, 80, 94, 97, 99, 100, 103, 116, 257, 285, 327, 448,
    472, 473, 474, 475, 476, 478, 732, 735, 880, 881, 6093, 6846, 6927, 13159);
