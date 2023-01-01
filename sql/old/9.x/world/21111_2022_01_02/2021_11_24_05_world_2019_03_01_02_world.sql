-- 
UPDATE `event_scripts` SET `delay`=0, `x`=3521.2597, `y`=4550.4038, `z`=-12.8893, `o`= 3.954486, `datalong2`=180000 WHERE `id`=17084 AND `command`=10 AND `datalong`=25794;
UPDATE `event_scripts` SET `delay`=15, `x`=3454.721191, `y`=4511.480957, `z`=-12.996876, `o`= 1.450632, `datalong2`=180000 WHERE `id`=17084 AND `command`=10 AND `datalong`=25629;

DELETE FROM `waypoints` WHERE `entry`=25629; 
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(25629, 1, 3456.838379, 4512.561523, -13.007453, "Lord Kryxix"),
(25629, 2, 3460.417725, 4529.125488, -12.949759, "Lord Kryxix"),
(25629, 3, 3470.703613, 4542.340332, -12.984859, "Lord Kryxix"),
(25629, 4, 3480.046143, 4548.960938, -12.982792, "Lord Kryxix"),
(25629, 5, 3492.488525, 4548.432617, -12.966542, "Lord Kryxix"),
(25629, 6, 3498.693604, 4544.571777, -12.983426, "Lord Kryxix");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (25629,25794);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25629,25794,25742) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2574200,2574201) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25629, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 25629, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, 0, "Lord Kryxix - On Just Summoned - Start Waypoint"),
(25629, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 18, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lord Kryxix - On Just Summoned - Set unit flag"),
(25629, 0, 2, 3, 40, 0, 100, 0, 6, 25629, 0, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lord Kryxix - On Just Summoned - remove unit flag"),
(25629, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 21, 40, 0, 0, 0, 0, 0, 0, "Lord Kryxix - On Waypoint 6 Reached - Start Attacking"),
(25629, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Lord Kryxix - On evade - Despawn"),
(25794, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 0, 59, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Shake-n-Quake 5000 - On Just Summoned - Set run off"),
(25794, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 69, 1, 0, 0, 0, 0, 0, 8, 0, 0, 0, 3496.3134, 4539.457, -12.9751, 4.494835, "Shake-n-Quake 5000 - On Just Summoned - move to pos"),
(25794, 0, 2, 0, 1, 0, 100, 1, 30000, 30000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Shake-n-Quake 5000 - Ooc - ddepawn"),
(25794, 0, 3, 0, 34, 0, 100, 0, 8, 1, 0, 0, 0, 17, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Shake-n-Quake 5000 - On mov info - Set emote state"),
(25794, 0, 4, 0, 1, 0, 100, 1, 17000, 17000, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 19, 25629, 0, 0, 0, 0, 0, 0, "Shake-n-Quake 5000 - Ooc - Say text"),
(25742, 0, 0, 0, 54, 0, 100, 512, 0, 0, 0, 0, 0, 53, 0, 25742, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Alluvius - On Just Summoned - Start Waypoint"),
(25742, 0, 1, 0, 40, 0, 100, 512, 1, 25742, 0, 0, 0, 80, 2574200, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Alluvius - On Waypoint 1 Reached - Run Script"),
(2574200, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Alluvius - On Script - Play Emote 36"),
(2574200, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 19, 25629, 0, 0, 0, 0, 0, 0, "Alluvius - On Script - say text"),
(2574200, 9, 2, 0, 0, 0, 100, 0, 6000, 6000, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Alluvius - On Script - Despawn Instant");

DELETE FROM `event_scripts` WHERE `id` IN (16929);
INSERT INTO `event_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`) VALUES
(16929, 13, 10, 25629, 180000, 0, 3454.721191, 4511.480957, -12.996876, 1.450632),
(16929, 0, 10, 25742, 180000, 0, 3517.29, 4538.78, -12.9837, 4.42876),
(16929, 7, 8, 25742, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID`=25629 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25629,1,0,"Feebleminded tinkerer, do you really think your pathetic creation can stop me?",14,0,100,0,0,0,24998,0,'Lord Kryxix');

DELETE FROM `conditions` WHERE `SourceEntry` IN (46017,45942) AND `SourceTypeOrReferenceId`=17;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`, `ErrorType`, `ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17, 0, 46017, 0, 0, 29, 0, 25629, 70, 0, 1, 0, 0, "", ""),
(17, 0, 46017, 0, 0, 29, 0, 25794, 70, 0, 1, 0, 0, "", ""),
(17, 0, 46017, 0, 0, 29, 0, 25742, 70, 0, 1, 0, 0, "", ""),
(17, 0, 45942, 0, 0, 29, 0, 25629, 70, 0, 1, 0, 0, "", ""),
(17, 0, 45942, 0, 0, 29, 0, 25794, 70, 0, 1, 0, 0, "", ""),
(17, 0, 45942, 0, 0, 29, 0, 25742, 70, 0, 1, 0, 0, "", "");
