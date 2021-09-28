 -- Plague Walker
SET @ENTRY := 30283;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 11, 56709, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Cast spell Aura of Lost Hope (56709) on Self"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 6, 7000, 11000, 120000, 130000, 11, 56707, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Every 120 - 130 seconds (7 - 11s initially) - Self: Cast spell Contagion of Rot (56707) on Victim"),
(@ENTRY, 0, 2, 0, 25, 0, 100, 2, 0, 0, 0, 0, 28, 56709, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset - Self: Remove 1 charges of aura due to spell Aura of Lost Hope (56709)"),
(@ENTRY, 0, 3, 0, 25, 0, 100, 4, 0, 0, 0, 0, 28, 61459, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset - Self: Remove 1 charges of aura due to spell Aura of Lost Hope (61459)");

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (56709);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(56709, 56709, 61459);

 -- Ahn'kahar Web Winder
SET @ENTRY := 30276;
DELETE FROM `smart_scripts` WHERE `entryOrGuid` = @ENTRY AND `source_type` = 0;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 1000, 4000, 10000, 20000, 11, 56640, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 10 - 20 seconds (1 - 4s initially) - Self: Cast spell Web Grab (56640) on Random hostile"),
(@ENTRY, 0, 1, 0, 0, 0, 100, 6, 5000, 9000, 16000, 21000, 11, 56632, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Every 16 - 21 seconds (5 - 9s initially) - Self: Cast spell Tangled Webs (56632) on Random hostile");

DELETE FROM `spelldifficulty_dbc` WHERE `id` IN (56640);
INSERT INTO `spelldifficulty_dbc` (`id`, `spellid0`, `spellid1`) VALUES
(56640, 56640, 59106);
