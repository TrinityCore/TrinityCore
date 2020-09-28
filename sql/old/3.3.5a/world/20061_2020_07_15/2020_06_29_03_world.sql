-- The video from 3.x.x or TBC is no longer available, I used it as source for some parts of this script
-- Videos from classic sometimes looks like they're from private servers
-- Deathstalker Erland SAI
SET @ID := 1978;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+5 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,4,0,50,0,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Aggro - Say Line 8"),
(@ID,0,1,0,19,0,100,0,435,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Quest 'Escorting Erland' Taken - Run Script"),
(@ID,0,2,0,40,0,100,0,2,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Waypoint 2 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,14,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Waypoint 14 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,15,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Waypoint 15 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,22,0,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Waypoint 22 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,23,0,0,0,0,80,@ID*100+5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Waypoint 23 Reached - Run Script"),
(@ID,0,7,0,6,0,100,0,0,0,0,0,0,6,435,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Erland - On Death - Fail Quest 'Escorting Erland'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Remove NPC Flag Questgiver"),
-- Aggressive reactstate https://www.wowhead.com/quest=435/escorting-erland#comments:id=140653
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,53,0,1978,0,0,0,2,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Start Waypoint"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 1"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,26,435,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Quest Credit 'Escorting Erland'"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 2"),
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Set Run On"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Set Run Off"),
(@ID*100+3,9,2,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 3"),
(@ID*100+3,9,3,0,0,0,100,0,3000,3000,0,0,0,1,0,0,0,0,0,0,19,1950,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 0 (Rane Yorick)"),
(@ID*100+3,9,4,0,0,0,100,0,5000,5000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 4"),
(@ID*100+3,9,5,0,0,0,100,0,5000,5000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 5"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Pause Waypoint"),
(@ID*100+4,9,1,0,0,0,100,0,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 6"),

(@ID*100+5,9,0,0,0,0,100,0,0,0,0,0,0,54,35000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Pause Waypoint"),
(@ID*100+5,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,1951,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 0 (Quinn Yorick)"),
(@ID*100+5,9,2,0,0,0,100,0,5000,5000,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Say Line 7"),
(@ID*100+5,9,3,0,0,0,100,0,0,0,0,0,0,41,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Deathstalker Erland - On Script - Despawn (30000)");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=481),12,0,100,0,0,0,481,0,"Deathstalker Erland"), -- Let's get to the others, and keep an eye open for those wolves outside...
(@ID,1,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=482),12,0,100,0,0,0,482,0,"Deathstalker Erland"), -- Be careful, $n.  Those wolves like to hide among the trees.
(@ID,2,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=483),12,0,100,0,0,0,483,0,"Deathstalker Erland"), -- We're almost there!
(@ID,3,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=484),12,0,100,0,0,0,484,0,"Deathstalker Erland"), -- We made it!  Thanks, $n.  I couldn't have gotten here without you.
(@ID,4,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=535),12,0,100,0,0,0,535,0,"Deathstalker Erland"), -- Masses of wolves are to the east, and whoever lived at Malden's Orchard is gone.
(@ID,5,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=536),12,0,100,0,0,0,536,0,"Deathstalker Erland"), -- If I am excused, then I'd like to check on Quinn...
(@ID,6,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=537),12,0,100,0,0,0,537,0,"Deathstalker Erland"), -- Hello, Quinn.  How are you faring?
(@ID,7,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=538),12,0,100,0,0,0,538,0,"Deathstalker Erland"), -- Try to take better care of yourself, Quinn.  You were lucky this time.
(@ID,8,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=541),12,0,100,0,0,0,541,0,"Deathstalker Erland"), -- Beware!  A $n is upon us!
(@ID,8,1,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=543),12,0,100,0,0,0,543,0,"Deathstalker Erland"), -- A $n attacks!
(@ID,8,2,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=544),12,0,100,0,0,0,544,0,"Deathstalker Erland"); -- Beware!  I am under attack!

UPDATE `creature_text` SET `comment` = "Rane Yorick" WHERE `CreatureID` = 1950;
UPDATE `creature_text` SET `comment` = "Quinn Yorick" WHERE `CreatureID` = 1951;

DELETE FROM `script_waypoint` WHERE `entry` = 1978;
DELETE FROM `waypoints` WHERE `entry` = 1978;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(1978,1,1406.32,1083.10,52.55,"Deathstalker Erland"),
(1978,2,1400.49,1080.42,52.50,"Deathstalker Erland"), --
(1978,3,1388.48,1083.10,52.52,"Deathstalker Erland"),
(1978,4,1370.16,1084.02,52.30,"Deathstalker Erland"),
(1978,5,1359.02,1080.85,52.46,"Deathstalker Erland"),
(1978,6,1341.43,1087.39,52.69,"Deathstalker Erland"),
(1978,7,1321.93,1090.51,50.66,"Deathstalker Erland"),
(1978,8,1312.98,1095.91,47.49,"Deathstalker Erland"),
(1978,9,1301.09,1102.94,47.76,"Deathstalker Erland"),
(1978,10,1297.73,1106.35,50.18,"Deathstalker Erland"),
(1978,11,1295.49,1124.32,50.49,"Deathstalker Erland"),
(1978,12,1294.84,1137.25,51.75,"Deathstalker Erland"),
(1978,13,1292.89,1158.99,52.65,"Deathstalker Erland"),
(1978,14,1290.75,1168.67,52.56,"Deathstalker Erland"), --
(1978,15,1287.12,1203.49,52.66,"Deathstalker Erland"), --
(1978,16,1290.72,1207.44,52.69,"Deathstalker Erland"),
(1978,17,1297.50,1207.18,53.74,"Deathstalker Erland"),
(1978,18,1301.32,1220.90,53.74,"Deathstalker Erland"),
(1978,19,1298.55,1220.43,53.74,"Deathstalker Erland"),
(1978,20,1297.38,1212.87,58.51,"Deathstalker Erland"),
(1978,21,1297.80,1210.04,58.51,"Deathstalker Erland"),
(1978,22,1305.01,1206.10,58.51,"Deathstalker Erland"), --
(1978,23,1310.51,1207.36,58.51,"Deathstalker Erland"); --
