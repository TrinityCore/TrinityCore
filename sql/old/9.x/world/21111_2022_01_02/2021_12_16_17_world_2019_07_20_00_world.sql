--
UPDATE `smart_scripts` SET `action_param1`=1 WHERE `entryorguid` IN (10803, 10805) AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1243 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=124300 AND `source_type`=9;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10610 AND `source_type`=0 AND `id`=7;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10611 AND `source_type`=0 AND `id` IN (13, 14);
DELETE FROM `smart_scripts` WHERE `entryorguid`=10803 AND `source_type`=0 AND `id` IN (17, 18, 19);
DELETE FROM `smart_scripts` WHERE `entryorguid`=10804 AND `source_type`=0 AND `id` IN (19, 20);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1243, 0, 0, 0, 20, 0, 100, 512, 5541, 0, 0, 0, 0, 80, 124300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Run Actionlist"),
(1243, 0, 1, 0, 38, 0, 100, 512, 3, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 0.0349066, "Hegnar Rumbleshot - Om Data Set 3 0 - Set Orientation 0.03490658"),
(10610, 0, 7, 0, 40, 0, 100, 512, 4, 10610, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 2.18492, "Angus - On Waypoint 4 Reached - Set Orientation"),
(10611, 0, 13, 0, 38, 0, 100, 0, 1, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Shorty - On Data Set 1 0 - Set Run Off"),
(10611, 0, 14, 0, 38, 0, 100, 0, 12, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Shorty - On Data Set 12 0 - Set Run On"),
(10803, 0, 17, 0, 38, 0, 100, 0, 1, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rifleman Wheeler - On Data Set 1 0 - Set Run Off"),
(10803, 0, 18, 0, 38, 0, 100, 0, 14, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rifleman Wheeler - On Data Set 14 0 - Set Run Off"),
(10803, 0, 19, 0, 38, 0, 100, 0, 16, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rifleman Wheeler - On Data Set 16 0 - Set Run On"),
(10804, 0, 19, 0, 38, 0, 100, 0, 1, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rifleman Middlecamp - On Data Set 1 0 - Set Run Off"),
(10804, 0, 20, 0, 38, 0, 100, 0, 18, 0, 0, 0, 0, 59, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Rifleman Middlecamp - On Data Set 18 0 - Set Run On"),
(124300, 9, 0, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 19, 10610, 20, 0, 0, 0, 0, 0, 0, "Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(124300, 9, 1, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 19, 10611, 20, 0, 0, 0, 0, 0, 0, "Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(124300, 9, 2, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 19, 10804, 20, 0, 0, 0, 0, 0, 0, "Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(124300, 9, 3, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 19, 10805, 20, 0, 0, 0, 0, 0, 0, "Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(124300, 9, 4, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 45, 1, 0, 0, 0, 0, 0, 19, 10803, 20, 0, 0, 0, 0, 0, 0, "Hegnar Rumbleshot - On Quest 'Ammo for Rumbleshot' Finished - Set Data 1 0"),
(124300, 9, 5, 0, 0, 0, 100, 512, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 0, 3.68522, "Hegnar Rumbleshot - On Data Set 2 0 - Set Orientation 3,68522");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=16786;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 16786, 0, 0, 31, 0, 3, 11875, 0, 0, 0, 0, "", "Mortar Shot can only hit Mortar Team Target Dummy");
