-- Creature Benjamin Foxworthy 46983 SAI
SET @ENTRY := 46983;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 67, 0, 1, 1, 10000, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, "On reset (e.g. after reaching home) - Trigger timed event #0 in 1 - 1 ms and then trigger every 10000 - 10000 ms // "),
(@ENTRY, 0, 1, 0, 59, 0, 100, 0, 0, 0, 0, 0, 11, 45425, 0, 0, 0, 0, 0, 10, 280676, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Cast spell Shoot (45425) on Creature [DNT] Generic Target Bunny 46985 (280676) // ");
DELETE FROM `creature_template_addon` WHERE `entry`= @ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `bytes2`, `emote`) VALUES
(@ENTRY, 2, 214);
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`= 46985;
