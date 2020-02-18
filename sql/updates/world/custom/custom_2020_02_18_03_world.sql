-- Creature Nightbane Shadow Weaver 533 SAI
SET @ENTRY := 533;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Self: Set event phase to 1 // "),
(@ENTRY, 0, 1, 2, 1, 1, 100, 0, 1000, 10000, 21000, 24000, 5, 479, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 1000 and 10000 ms (and later repeats every 21000 and 24000 ms) - Self: Play emote ONESHOT_SNIFF (479) // "),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 4000, 4000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 4000 - 4000 ms // "),
(@ENTRY, 0, 3, 0, 59, 1, 100, 0, 0, 0, 0, 0, 11, 85072, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell Woven Shadows (85072) on Self // "),
(@ENTRY, 0, 4, 0, 0, 0, 100, 0, 6000, 6000, 11000, 11000, 11, 77721, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "When in combat and timer at the begining between 6000 and 6000 ms (and later repeats every 11000 and 11000 ms) - Self: Cast spell Shadow Weave (77721) on Victim // "),
(@ENTRY, 0, 5, 0, 4, 0, 100, 0, 0, 0, 0, 0, 23, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On aggro - Self: Increment phase by 1 and decrement by 0 // ");

UPDATE `creature_template_addon` SET `emote`= 27 WHERE `entry`= 533;
UPDATE `creature` SET `spawndist`= 7, `MovementType`= 1 WHERE `guid` IN (317363, 317444, 317445, 317446, 317449, 317450, 317451, 317456, 317457, 317461, 317464, 317465, 317466, 317467, 317469, 317470, 317529, 317532, 317533, 317536, 317537, 317540, 317541, 317555, 317560); 

-- Creature Woven Shadow 45554 SAI
SET @ENTRY := 45554;
UPDATE `creature_template` SET `AIName`="SmartAI", `minlevel`= 22, `maxlevel`= 23 WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 60, 0, 100, 1, 0, 0, 0, 0, 89, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ""),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 74348, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ""),
(@ENTRY, 0, 2, 0, 25, 0, 100, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, ""),
(@ENTRY, 0, 3, 0, 4, 0, 100, 0, 0, 0, 0, 0, 8, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "");

-- Creature Nightbane Stalker 44087 SAI
SET @ENTRY := 44087;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 0, 0, 100, 0, 15000, 16000, 11000, 12000, 11, 80576, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "");
