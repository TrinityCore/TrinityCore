-- Duggan Wildhammer
-- Add random movement
UPDATE `creature` SET `wander_distance` = 10, `MovementType` = 1 WHERE `id` = 10817;
-- Correct walk speed
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 10817;

-- Creature text
DELETE FROM `smart_scripts` WHERE `entryorguid`= 10817 AND `source_type`=0 AND `id`>2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10817, 0, 3, 0, 0, 0, 100, 1, 0, 0, 0, 0, 0, 1, 9, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - In Combat - Say Line 9"),
(10817, 0, 4, 0, 1, 0, 100, 0, 3000, 3000, 180000, 180000, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 0"),
(10817, 0, 5, 0, 1, 0, 100, 0, 15000, 15000, 180000, 180000, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 1"),
(10817, 0, 6, 0, 1, 0, 100, 0, 25000, 25000, 80000, 80000, 0, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 2"),
(10817, 0, 7, 0, 1, 0, 100, 0, 40000, 40000, 180000, 180000, 0, 1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 3"),
(10817, 0, 8, 0, 1, 0, 100, 0, 50000, 50000, 180000, 180000, 0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 4"),
(10817, 0, 9, 0, 1, 0, 100, 0, 70000, 70000, 120000, 120000, 0, 1, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 5"),
(10817, 0, 10, 0, 1, 0, 100, 0, 90000, 90000, 180000, 180000, 0, 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 6"),
(10817, 0, 11, 0, 1, 0, 100, 0, 100000, 100000, 120000, 120000, 0, 1, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 7"),
(10817, 0, 12, 0, 1, 0, 100, 0, 120000, 120000, 120000, 120000, 0, 1, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "Duggan Wildhammer - Out of Combat - Say Line 8");

DELETE FROM `creature_text` WHERE `creatureid`= 10817;
INSERT INTO `creature_text` (`creatureid`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(10817, 0, 0, "Ooooooooh...", 12, 0, 100, 15, 0, 0, 50906, 0, "Duggan Wildhammer - Line 0"),
(10817, 1, 0, "To the plaguelands went old Duggan, ta' send them Scourge back inta' th' groun'.", 12, 0, 100, 1, 0, 0, 50907, 0, "Duggan Wildhammer - Line 1"),
(10817, 2, 0, "Where th' scent of death is on th' wind and everythin' is mostly brown.", 12, 0, 100, 6, 0, 0, 50908, 0, "Duggan Wildhammer - Line 2"),
(10817, 3, 0, "An' when he did arrive there, what'd his dwarf eyes see?", 12, 0, 100, 25, 0, 0, 50909, 0, "Duggan Wildhammer - Line 3"),
(10817, 4, 0, "A hundred crates of barley there ta' be makin' inta' mead!", 12, 0, 100, 5, 0, 0, 50910, 0, "Duggan Wildhammer - Line 4"),
(10817, 5, 0, "But tha' mead was cursed with th' plague o' death, and now old Duggan, too.", 12, 0, 100, 18, 0, 0, 50911, 0, "Duggan Wildhammer - Line 5"),
(10817, 6, 0, "An' surrounded by the Lich King's beasts, what could old Duggan do?", 12, 0, 100, 430, 0, 0, 50912, 0, "Duggan Wildhammer - Line 6"),
(10817, 7, 0, "But though I feel the plague within, my hopes 'ave not yet sunk.", 12, 0, 100, 274, 0, 0, 50913, 0, "Duggan Wildhammer - Line 7"),
(10817, 8, 0, "If'n I'm gonna be Scourge anyway, I might as well be drunk!", 12, 0, 100, 11, 0, 0, 50914, 0, "Duggan Wildhammer - Line 8"),
(10817, 9, 0, "Ah ken see very well through this haze, but I'd know tha' smell anywhere! Die ye foul ogre!", 12, 0, 100, 0, 0, 0, 50905, 0, "Duggan Wildhammer - Line 9");
