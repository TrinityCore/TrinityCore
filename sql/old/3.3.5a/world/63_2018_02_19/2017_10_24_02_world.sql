--
DELETE FROM `smart_scripts` WHERE `entryorguid`=2546 AND `source_type`=0 AND `id`=1;
DELETE FROM `smart_scripts` WHERE `entryorguid`=254600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2546, 0, 1, 0, 20, 0, 100, 0, 4621, 0, 0, 0, 80, 254600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Fleet Master Firallon - On Quest 'Avast Ye, Admiral!' Rewarded - Run Script"),
(254600, 9, 0, 0, 0, 0, 100, 0, 400, 400, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Fleet Master Firallon - On Script - Say Line 0"),
(254600, 9, 1, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Fleet Master Firallon - On Script - Say Line 1"),
(254600, 9, 2, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Fleet Master Firallon - On Script - Say Line 1"),
(254600, 9, 3, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Fleet Master Firallon - On Script - Say Line 1");

DELETE FROM `creature_text` WHERE `CreatureID`=2546;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2546, 0, 0, "Three cheers for $n -- Admiral o' the Bloodsail Bucaneer Navy!", 14, 0, 100, 0, 0, 0, 5522, 0, "Fleet Master Firallon"),
(2546, 1, 0, "Hip hip... arrrrr...", 14, 0, 100, 0, 0, 0, 5523, 0, "Fleet Master Firallon");
