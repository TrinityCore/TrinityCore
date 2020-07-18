SET @R3D0 := 21690;

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@R3D0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@R3D0, @R3D0*100);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@R3D0, 0, 0, 0, 64, 0, 100, 0, 0, 0, 0, 0, 80, 2169000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "R-3D0 - On Gossip Hello - Call Actionlist"),
(@R3D0*100, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 91, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "R-3D0 - On Script - Remove Standstate Sleep"),
(@R3D0*100, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "R-3D0 - On Script - Talk"),
(@R3D0*100, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 90, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "R-3D0 - On Gossip Hello - Set Standstate Sleep");

DELETE FROM `creature_text` WHERE `entry`=@R3D0;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(@R3D0, 0, 0, "WARNING!  WARNING!  AWAY HOSTILE BEINGS!  DO NOT HEAD UP THE RIDGE TO TOSHLEY'S STATION!", 12, 0, 100, 35, 0, 0, 19311, 0, "R-3D0");
