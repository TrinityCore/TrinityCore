--
/*
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=3693;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 3693, 0, 0, 29, 1, 3694, 100, 0, 1, 0, 0, "", "Terenthis - Execute SAI 0 only if not within 100 yards of Sentinel Selarin"),
(22, 2, 3693, 0, 0, 29, 1, 3694, 100, 0, 1, 0, 0, "", "Terenthis - Execute SAI 1 only if not within 100 yards of Sentinel Selarin");

DELETE FROM `creature_text` WHERE `entry`=3694;
DELETE FROM `creature_text` WHERE `entry`=3693 AND `groupid`=7;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(3694, 0, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=1302), 12, 7, 100, 0, 0, 0, 1302, 0, "Sentinel Selarin"),
(3694, 1, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=1303), 12, 7, 100, 0, 0, 0, 1303, 0, "Sentinel Selarin"),
(3694, 2, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=1304), 12, 7, 100, 0, 0, 0, 1304, 0, "Sentinel Selarin"),
(3694, 3, 0, (SELECT `FemaleText` FROM `broadcast_text` WHERE `ID`=1306), 12, 7, 100, 0, 0, 0, 1306, 0, "Sentinel Selarin"),
(3693, 7, 0, (SELECT `MaleText` FROM `broadcast_text` WHERE `ID`=1305), 12, 7, 100, 0, 0, 0, 1305, 0, "Terenthis");

UPDATE `smart_scripts` SET `link`=5 WHERE `entryorguid`=3694 AND `id`=2;
UPDATE `smart_scripts` SET `link`=6 WHERE `entryorguid`=3694 AND `id`=4;
DELETE FROM `smart_scripts` WHERE `entryorguid`=3694 AND `id` IN (5, 6);
DELETE FROM `smart_scripts` WHERE `entryorguid`=369400;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3694, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Summon - Remove Questgiver+Gossip npcflag"),
(3694, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 369400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Waypoint 12 Reached - Run Actionlist"),

(369400, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Script - Talk 0"),
(369400, 9, 1, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 7, 0, 0, 0, 0, 0, 19, 3693, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Script - Talk 7 (Terenthis)"),
(369400, 9, 2, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Script - Talk 1"),
(369400, 9, 3, 0, 0, 0, 100, 0, 7000, 7000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Script - Talk 2"),
(369400, 9, 4, 0, 61, 0, 100, 0, 2000, 2000, 0, 0, 82, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Summon - Add Questgiver+Gossip npcflag"),
(369400, 9, 5, 0, 0, 0, 100, 0, 90000, 90000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Script - Talk 3"),
(369400, 9, 6, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 83, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sentinel Selarin - On Script - Remove Questgiver+Gossip npcflag");
*/
