-- creature_onkill_reputation correction: killing a WorldFaction-affiliated
-- Elwynn NPC must DECREASE reputation with that NPC's own faction, not
-- increase it - you killed one of their own, that is a hostile act toward
-- them, not a favor. 2026_09_16_02_world.sql originally shipped
-- RewOnKillRepValue1 = 1 (a straight sign error, caught by the first live
-- kill-test runtime pass - "Reputation with Elwynn Kobolds decreased by 1"
-- was the expected chat line, "increased" is what actually printed).
--
-- This is a CORRECTIVE migration, not a re-run of 2026_09_16_02_world.sql:
-- that file is already applied on any deployed server, and the updater does
-- not normally re-apply a migration under the same filename. Do not edit
-- 2026_09_16_02_world.sql itself.
--
-- entry list and target sign are exactly data/elwynn/factions/
-- world_faction_assignments.csv's own `onkill_rep_value` column (now -1 for
-- all 32 `tc_faction_action = CLONED` rows) - regenerate/re-verify this
-- migration against that CSV if either the entry list or the value ever
-- changes again.
--
-- V1 flat baseline unchanged otherwise: -1 reputation per kill, whether
-- common trash or a unique named NPC. Deliberately NOT touching the killed
-- NPC's own enemy WorldFaction's reputation (e.g. killing a Defias does NOT
-- currently grant Stormwind +1) - that is a separate, not-yet-designed
-- reputation/diplomacy reward policy, out of scope here.
UPDATE `creature_onkill_reputation`
SET `RewOnKillRepValue1` = -1
WHERE `creature_id` IN (6, 38, 40, 46, 60, 61, 79, 80, 94, 97, 99, 100, 103, 116, 257, 285, 327, 448,
    472, 473, 474, 475, 476, 478, 732, 735, 880, 881, 6093, 6846, 6927, 13159);
