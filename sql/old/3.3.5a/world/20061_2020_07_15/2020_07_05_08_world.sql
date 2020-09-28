--
ALTER TABLE `creature_text_locale` DROP INDEX `PRIMARY`, ADD PRIMARY KEY (`CreatureID`,`GroupID`,`ID`,`Locale`);

-- A-Me 01 SAI (https://www.youtube.com/watch?v=or8qY6uId0w)
-- No summons here
SET @ID := 9623;
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 9623);
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+3 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Respawn - Set Flag Standstate Dead"),
(@ID,0,1,0,4,0,50,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Aggro - Say Line 3"),
(@ID,0,2,0,0,0,100,256,5800,11800,14500,35600,0,11,13730,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - In Combat - Cast 'Demoralizing Shout' (No Reset)"),
(@ID,0,3,0,19,0,100,0,4245,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Quest 'Chasing A-Me 01' Taken - Run Script"),
(@ID,0,4,0,40,0,100,0,20,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Waypoint 20 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,38,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Waypoint 38 Reached - Run Script"),
(@ID,0,6,0,40,0,100,0,40,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Waypoint 40 Reached - Despawn (5000)"),
(@ID,0,7,0,6,0,100,0,0,0,0,0,0,6,4245,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"A-Me 01 - On Death - Fail Quest 'Chasing A-Me 01'"),
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Remove NPC Flag Questgiver"),
-- Guessed timers, I didn't found video with this part
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Remove Flag Standstate Dead"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"A-Me 01 - On Script - Say Line 0"),
(@ID*100+0,9,4,0,0,0,100,0,2000,2000,0,0,0,53,0,9623,0,0,0,1,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Start Waypoint"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Remove Flag Immune To NPC's"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Set Faction 250"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"A-Me 01 - On Script - Say Line 1"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A-Me 01 - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"A-Me 01 - On Script - Say Line 2"),
(@ID*100+3,9,2,0,0,0,100,0,0,0,0,0,0,15,4245,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"A-Me 01 - On Script - Quest Credit 'Chasing A-Me 01'");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"A-Me good. Good, A-Me. Follow... follow A-Me. Home. A-Me go home.",12,0,100,0,0,0,0,0,"A-Me 01"), -- 5062
(@ID,1,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=5063),12,0,100,0,0,0,5063,0,"A-Me 01"), -- Good... good, A-Me. A-Me good. Home. Find home.
(@ID,2,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=5156),12,0,100,0,0,0,5156,0,"A-Me 01"), -- A-Me home! A-Me, good! Good A-Me. Home. Home. Home.
(@ID,3,0,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=5157),12,0,100,0,0,0,5157,0,"A-Me 01"), -- Bad, $n. $n, bad!
(@ID,3,1,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=5158),12,0,100,0,0,0,5158,0,"A-Me 01"), -- $n, no hurt A-Me. A-Me, good.
(@ID,3,2,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=5159),12,0,100,0,0,0,5159,0,"A-Me 01"), -- Danger. Danger! $n try hurt A-Me.
(@ID,3,3,(SELECT `Text` FROM `broadcast_text` WHERE `ID`=5160),12,0,100,0,0,0,5160,0,"A-Me 01"); -- A-Me, home. A-Me go home! $n, no stop A-Me.

-- "ptBR", "A-Me boa. Boa, A-Me. Seguir... seguir A-Me. Casa. A-Me, minha casa."
DELETE FROM `creature_text_locale` WHERE `CreatureID` = @ID AND `GroupID` = 0;
INSERT INTO `creature_text_locale` (`CreatureID`,`GroupID`,`ID`,`Locale`,`Text`) VALUES
(@ID,0,0,"deDE","A-Me gut. Gut, A-Me. Folgen... A-Me folgen. Heim. A-Me geht heim."), -- 5062
(@ID,0,0,"esES","Memo bueno. Bueno, Memo. Seguir... seguir a Memo. Casa. Memo ir a casa."), -- 5062
(@ID,0,0,"esMX","Memo bueno. Bueno, Memo. Seguir... seguir a Memo. Casa. Memo ir a casa."), -- 5062
(@ID,0,0,"frFR","A-mi bonne. Bonne, A-mi. Suivre... Suivre A-mi. Maison. A-mi va maison."), -- 5062
(@ID,0,0,"ruRU","Чи-Та хорошо. Все хорошо, Чи-Та. Идти… Идти за Чи-Та. Домой. Чи-Та идти домой."); -- 5062

DELETE FROM `script_waypoint` WHERE `entry` = 9623;
DELETE FROM `waypoints` WHERE `entry` = 9623;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(9623,1,-6383.07,-1964.37,-258.709,"A-Me 01"),
(9623,2,-6393.65,-1949.57,-261.449,"A-Me 01"),
(9623,3,-6397.85,-1931.1,-263.366,"A-Me 01"),
(9623,4,-6397.5,-1921.47,-263.876,"A-Me 01"),
(9623,5,-6389.63,-1910,-259.601,"A-Me 01"),
(9623,6,-6380.07,-1905.45,-255.858,"A-Me 01"),
(9623,7,-6373.44,-1900.28,-254.774,"A-Me 01"),
(9623,8,-6372.87,-1893.5,-255.678,"A-Me 01"),
(9623,9,-6379.73,-1877.63,-259.654,"A-Me 01"),
(9623,10,-6380.26,-1871.14,-260.617,"A-Me 01"),
(9623,11,-6373.83,-1855.62,-259.566,"A-Me 01"),
(9623,12,-6368.82,-1847.77,-259.246,"A-Me 01"),
(9623,13,-6370.9,-1835.04,-260.212,"A-Me 01"),
(9623,14,-6376.59,-1821.59,-260.856,"A-Me 01"),
(9623,15,-6381.93,-1810.43,-266.18,"A-Me 01"),
(9623,16,-6396.71,-1807.12,-269.329,"A-Me 01"),
(9623,17,-6400.27,-1795.05,-269.744,"A-Me 01"),
(9623,18,-6402.68,-1747.51,-272.961,"A-Me 01"),
(9623,19,-6397,-1710.05,-273.719,"A-Me 01"),
(9623,20,-6388.11,-1676.33,-272.133,"A-Me 01"),
(9623,21,-6370.71,-1638.64,-272.031,"A-Me 01"),
(9623,22,-6366.71,-1592.65,-272.201,"A-Me 01"),
(9623,23,-6333.87,-1534.6,-270.493,"A-Me 01"),
(9623,24,-6305.36,-1477.91,-269.518,"A-Me 01"),
(9623,25,-6311.59,-1419.02,-267.622,"A-Me 01"),
(9623,26,-6330.01,-1400.06,-266.425,"A-Me 01"),
(9623,27,-6356.02,-1392.61,-267.123,"A-Me 01"),
(9623,28,-6370.86,-1386.18,-270.218,"A-Me 01"),
(9623,29,-6381.53,-1369.78,-272.11,"A-Me 01"),
(9623,30,-6405.38,-1321.52,-271.699,"A-Me 01"),
(9623,31,-6406.58,-1307.57,-271.802,"A-Me 01"),
(9623,32,-6386.33,-1286.85,-272.074,"A-Me 01"),
(9623,33,-6364.25,-1264.71,-269.075,"A-Me 01"),
(9623,34,-6343.64,-1239.84,-268.364,"A-Me 01"),
(9623,35,-6335.57,-1202.45,-271.515,"A-Me 01"),
(9623,36,-6325.62,-1184.46,-270.461,"A-Me 01"),
(9623,37,-6317.8,-1177.67,-269.792,"A-Me 01"),
(9623,38,-6303.02,-1180.25,-269.332,"A-Me 01"),
(9623,39,-6301.98,-1184.79,-269.371,"A-Me 01"),
(9623,40,-6297.58,-1186.41,-268.962,"A-Me 01");
