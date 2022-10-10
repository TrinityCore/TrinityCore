--
UPDATE `creature_text` SET `Text`="Thank ye, $G lad:lass;. Thank ye, greatly.", `Emote`=2, `BroadcastTextId`=2283 WHERE `CreatureID`=6172 AND `GroupID`=0;
UPDATE `creature_text` SET `Text`="Thank you, $G lad:lass;. Thank you, greatly.", `Language`=6, `BroadcastTextId`=2281 WHERE `CreatureID`=6177 AND `GroupID`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=17768;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17768, 0, 0, "This is... Silvermoon? My head... Next time Bloodvalor needs a volunteer, I'll point him in a different direction. Paragon of Blood Knight virtue, indeed!", 12, 0, 100, 0, 0, 0, 14367, 0, "Blood Knight Stillblade"),
(17768, 1, 0, "Don't get me wrong, $n. I very much appreciate the resurrection, but I think this is the last time I'll perform this particular duty. Maybe a goblet or two of wine will help with this headache.", 12, 0, 100, 0, 0, 0, 14368, 0, "Blood Knight Stillblade");

DELETE FROM `smart_scripts` WHERE `entryorguid`=1776800 AND `source_type`=9 AND `id` IN (5, 6, 7);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1776800, 9, 5, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Blood Knight Stillblade - On Script - Say Line 1"),
(1776800, 9, 6, 0, 0, 0, 100, 0, 120000, 120000, 0, 0, 94, 40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Blood Knight Stillblade - On Script - Set Dynamic Flags Tapped By Player & Dead"),
(1776800, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Blood Knight Stillblade - On Script - Set Flag Standstate Dead");
