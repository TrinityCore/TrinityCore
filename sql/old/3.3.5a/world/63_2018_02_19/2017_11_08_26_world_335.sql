--
UPDATE `smart_scripts` SET `event_param1`=0, `event_param2`=0, `action_param2`=0 WHERE `entryorguid`=305400 AND `source_type`=9 AND `id`=1;
UPDATE `smart_scripts` SET `event_param1`=5500, `event_param2`=5500 WHERE `entryorguid`=305400 AND `id`=2;

UPDATE `creature_template` SET `speed_run`=0.75 WHERE `entry`=2983;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2983, 298300, 298301) AND `source_type` IN (0, 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `COMMENT`) VALUES
(2983, 0, 0, 0, 54, 0, 100, 512, 0, 0, 0, 0, 80, 298300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Just Summoned - Run Script"),
(2983, 0, 1, 0, 40, 0, 100, 512, 1, 2983, 0, 0, 80, 298301, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Waypoint 1 Reached - Run Script"),
(2983, 0, 2, 0, 40, 0, 100, 512, 48, 2983, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Waypoint 48 Reached - Talk 2"),
(2983, 0, 3, 0, 40, 0, 100, 512, 49, 2983, 0, 0, 41, 200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Waypoint 49 Reached - Despawn In 200 ms"),
(298300, 9, 0, 0, 0, 0, 100, 512, 1000, 1000, 0, 0, 53, 1, 2983, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Script - Start Waypoint"),
(298301, 9, 0, 0, 0, 0, 100, 512, 0, 0, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Script - Pause Waypoint for 5 seconds"),
(298301, 9, 1, 0, 0, 0, 100, 512, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Script - Talk 0"),
(298301, 9, 2, 0, 0, 0, 100, 512, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "The Plains Vision - On Script - Talk 1");

DELETE FROM `creature_text` WHERE `CreatureID`=2983;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2983, 0, 0, "%s beings to draw energy from the earth", 16, 0, 100, 0, 0, 0, 944, 0, "The Plains Vision"),
(2983, 1, 0, "%s stares to the northwest and lets out a long, drawn out howl.", 16, 0, 100, 0, 0, 0, 945, 0, "The Plains Vision"),
(2983, 2, 0, "%s lets forth a mighty howl.", 16, 0, 100, 0, 0, 0, 946, 0, "The Plains Vision");
