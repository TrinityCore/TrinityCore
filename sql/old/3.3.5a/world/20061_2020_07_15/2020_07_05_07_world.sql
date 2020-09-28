-- Lakota Windsong SAI (https://www.youtube.com/watch?v=WY1mdBgs9iE)
SET @ID := 10646;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+4 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 10758 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,4904,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Quest 'Free at Last' Taken - Run Script"),
(@ID,0,1,0,40,0,100,0,9,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Waypoint 9 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,15,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Waypoint 15 Reached - Run Script"),
(@ID,0,3,0,40,0,100,0,22,0,0,0,0,80,@ID*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Waypoint 22 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,46,0,0,0,0,80,@ID*100+4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Waypoint 46 Reached - Run Script"),
(@ID,0,5,0,6,0,100,0,0,0,0,0,0,6,4904,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Death - Fail Quest 'Protect Kaya'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,3000,3000,0,0,0,53,0,10646,0,0,0,2,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Start Waypoint"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Remove Flag Immune To NPC's"),
-- Was 232 but 232 makes her agressive and in video she's passive
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Set Faction 113"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Pause Waypoint"),
-- She should not be attacked instantly, probably it's done by another way
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Add Flag Immune To NPC's"),
(@ID*100+1,9,2,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Say Line 1"),
(@ID*100+1,9,3,0,0,0,100,0,1000,1000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Summon Group 0"),
(@ID*100+1,9,4,0,0,0,100,0,1000,1000,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Remove Flag Immune To NPC's"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Add Flag Immune To NPC's"),
(@ID*100+2,9,2,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Say Line 2"),
(@ID*100+2,9,3,0,0,0,100,0,1000,1000,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Summon Group 1"),
(@ID*100+2,9,4,0,0,0,100,0,1000,1000,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Remove Flag Immune To NPC's"),

(@ID*100+3,9,0,0,0,0,100,0,0,0,0,0,0,54,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Pause Waypoint"),
(@ID*100+3,9,1,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Add Flag Immune To NPC's"),
(@ID*100+3,9,2,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Say Line 3"),
(@ID*100+3,9,3,0,0,0,100,0,1000,1000,0,0,0,107,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Summon Group 2"),
(@ID*100+3,9,4,0,0,0,100,0,1000,1000,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Remove Flag Immune To NPC's"),

(@ID*100+4,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Pause Waypoint"),
(@ID*100+4,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Set Orientation Stored Target 1"),
(@ID*100+4,9,2,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Say Line 4"),
(@ID*100+4,9,3,0,0,0,100,0,0,0,0,0,0,15,4904,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Quest Credit 'Free at Last'"),
(@ID*100+4,9,4,0,0,0,100,0,0,0,0,0,0,41,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lakota Windsong - On Script - Despawn (5000)"),

(10758,0,2,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,0,"Grimtotem Bandit - On Just Summoned - Start Attacking Closest Player");

UPDATE `creature_text` SET `comment` = "Lakota Windsong" WHERE `CreatureID` = @ID;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = @ID AND `GroupID` IN (0,1,2);
UPDATE `creature_text` SET `Emote` = 22 WHERE `CreatureID` = @ID AND `GroupID` = 3;
UPDATE `creature_text` SET `Emote` = 3 WHERE `CreatureID` = @ID AND `GroupID` = 4;

DELETE FROM `creature_summon_groups` WHERE `summonerId` = @ID;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(@ID,0,0,10758,-4905.479492,-2062.732666,84.352,0,4,60000,"Lakota Windsong - Group 0 - Grimtotem Bandit"),
(@ID,0,0,10758,-4915.201172,-2073.528320,84.733,0,4,60000,"Lakota Windsong - Group 0 - Grimtotem Bandit"),
(@ID,0,1,10758,-4878.883301,-1986.947876,91.966,0,4,60000,"Lakota Windsong - Group 1 - Grimtotem Bandit"),
(@ID,0,1,10758,-4877.503906,-1966.113403,91.859,0,4,60000,"Lakota Windsong - Group 1 - Grimtotem Bandit"),
(@ID,0,2,10758,-4767.985352,-1873.169189,90.192,0,4,60000,"Lakota Windsong - Group 2 - Grimtotem Bandit"),
(@ID,0,2,10758,-4788.861328,-1888.007813,89.888,0,4,60000,"Lakota Windsong - Group 2 - Grimtotem Bandit");

DELETE FROM `script_waypoint` WHERE `entry` = 10646;
DELETE FROM `waypoints` WHERE `entry` = 10646;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(10646,1,-4792.4,-2137.78,82.423,"Lakota Windsong"),
(10646,2,-4813.51,-2141.54,80.774,"Lakota Windsong"),
(10646,3,-4828.63,-2154.31,82.074,"Lakota Windsong"),
(10646,4,-4833.77,-2149.18,81.676,"Lakota Windsong"),
(10646,5,-4846.42,-2136.05,77.871,"Lakota Windsong"),
(10646,6,-4865.08,-2116.55,76.483,"Lakota Windsong"),
(10646,7,-4888.43,-2090.73,80.907,"Lakota Windsong"),
(10646,8,-4893.07,-2085.47,82.094,"Lakota Windsong"),
(10646,9,-4907.26,-2074.93,84.437,"Lakota Windsong"),
(10646,10,-4899.9,-2062.14,83.78,"Lakota Windsong"),
(10646,11,-4897.76,-2056.52,84.184,"Lakota Windsong"),
(10646,12,-4888.33,-2033.18,83.654,"Lakota Windsong"),
(10646,13,-4876.34,-2003.92,90.887,"Lakota Windsong"),
(10646,14,-4872.23,-1994.17,91.513,"Lakota Windsong"),
(10646,15,-4879.57,-1976.99,92.185,"Lakota Windsong"),
(10646,16,-4879.05,-1964.35,92.001,"Lakota Windsong"),
(10646,17,-4874.72,-1956.94,90.737,"Lakota Windsong"),
(10646,18,-4869.47,-1952.61,89.206,"Lakota Windsong"),
(10646,19,-4842.47,-1929,84.147,"Lakota Windsong"),
(10646,20,-4804.44,-1897.3,89.362,"Lakota Windsong"),
(10646,21,-4798.07,-1892.38,89.368,"Lakota Windsong"),
(10646,22,-4779.45,-1882.76,90.169,"Lakota Windsong"),
(10646,23,-4762.08,-1866.53,89.481,"Lakota Windsong"),
(10646,24,-4766.27,-1861.87,87.847,"Lakota Windsong"),
(10646,25,-4782.93,-1852.17,78.354,"Lakota Windsong"),
(10646,26,-4793.61,-1850.96,77.658,"Lakota Windsong"),
(10646,27,-4803.32,-1855.1,78.958,"Lakota Windsong"),
(10646,28,-4807.97,-1854.5,77.743,"Lakota Windsong"),
(10646,29,-4837.21,-1848.49,64.488,"Lakota Windsong"),
(10646,30,-4884.62,-1840.4,56.219,"Lakota Windsong"),
(10646,31,-4889.71,-1839.62,54.417,"Lakota Windsong"),
(10646,32,-4893.9,-1843.69,53.012,"Lakota Windsong"),
(10646,33,-4903.14,-1872.38,32.266,"Lakota Windsong"),
(10646,34,-4910.94,-1879.86,29.94,"Lakota Windsong"),
(10646,35,-4920.05,-1880.94,30.597,"Lakota Windsong"),
(10646,36,-4924.46,-1881.45,29.292,"Lakota Windsong"),
(10646,37,-4966.12,-1886.03,10.977,"Lakota Windsong"),
(10646,38,-4999.37,-1890.85,4.43,"Lakota Windsong"),
(10646,39,-5007.27,-1891.67,2.771,"Lakota Windsong"),
(10646,40,-5013.33,-1879.59,-1.947,"Lakota Windsong"),
(10646,41,-5023.33,-1855.96,-17.103,"Lakota Windsong"),
(10646,42,-5038.51,-1825.99,-35.821,"Lakota Windsong"),
(10646,43,-5048.73,-1809.8,-46.457,"Lakota Windsong"),
(10646,44,-5053.19,-1791.68,-57.186,"Lakota Windsong"),
(10646,45,-5062.09,-1794.4,-56.515,"Lakota Windsong"),
(10646,46,-5052.66,-1797.04,-54.734,"Lakota Windsong");

-- Pao'ka Swiftmountain SAI (https://www.youtube.com/watch?v=u_Lr-cbBmKU)
SET @ID := 10427;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,4770,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Quest 'Homeward Bound' Taken - Run Script"),
(@ID,0,1,0,40,0,100,0,16,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Waypoint 16 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,27,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Waypoint 27 Reached - Run Script"),
(@ID,0,3,0,6,0,100,0,0,0,0,0,0,6,4770,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Death - Fail Quest 'Homeward Bound'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,6000,6000,0,0,0,53,0,10427,0,0,0,2,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Start Waypoint"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Remove Flag Immune To NPC's"),
-- Was 232 but 232 makes him agressive and in video he's passive
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Set Faction 113"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Say Line 1"),
(@ID*100+1,9,2,0,0,0,100,0,5000,5000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Summon Group 0"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Say Line 2"),
(@ID*100+2,9,2,0,0,0,100,0,5000,5000,0,0,0,15,4770,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Quest Credit 'Homeward Bound'"),
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,0,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Play Emote 1"),
(@ID*100+2,9,4,0,0,0,100,0,1000,1000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Pao'ka Swiftmountain - On Script - Despawn (0)");

UPDATE `creature_text` SET `comment` = "Pao'ka Swiftmountain" WHERE `CreatureID` = @ID;
UPDATE `creature_text` SET `Emote` = 1 WHERE `CreatureID` = @ID AND `GroupID` IN (0,1);

DELETE FROM `creature_summon_groups` WHERE `summonerId` = @ID;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(@ID,0,0,4107,-4990.606,-906.057,-5.343,0,4,60000,"Pao'ka Swiftmountain - Group 0 - Highperch Wyvern"),
(@ID,0,0,4107,-4970.241,-927.378,-4.951,0,4,60000,"Pao'ka Swiftmountain - Group 0 - Highperch Wyvern"),
(@ID,0,0,4107,-4985.364,-952.528,-5.199,0,4,60000,"Pao'ka Swiftmountain - Group 0 - Highperch Wyvern");

DELETE FROM `script_waypoint` WHERE `entry` = 10427;
DELETE FROM `waypoints` WHERE `entry` = 10427;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(10427,1,-5185.46,-1185.93,45.951,"Pao'ka Swiftmountain"),
(10427,2,-5184.88,-1154.21,45.035,"Pao'ka Swiftmountain"),
(10427,3,-5175.88,-1126.53,43.701,"Pao'ka Swiftmountain"),
(10427,4,-5138.65,-1111.87,44.024,"Pao'ka Swiftmountain"),
(10427,5,-5134.73,-1104.8,47.365,"Pao'ka Swiftmountain"),
(10427,6,-5129.68,-1097.88,49.449,"Pao'ka Swiftmountain"),
(10427,7,-5125.3,-1080.57,47.033,"Pao'ka Swiftmountain"),
(10427,8,-5146.67,-1053.69,28.415,"Pao'ka Swiftmountain"),
(10427,9,-5147.46,-1027.54,13.818,"Pao'ka Swiftmountain"),
(10427,10,-5139.24,-1018.89,8.22,"Pao'ka Swiftmountain"),
(10427,11,-5121.17,-1013.13,-0.619,"Pao'ka Swiftmountain"),
(10427,12,-5091.92,-1014.21,-4.902,"Pao'ka Swiftmountain"),
(10427,13,-5069.24,-994.299,-4.631,"Pao'ka Swiftmountain"),
(10427,14,-5059.98,-944.112,-5.377,"Pao'ka Swiftmountain"),
(10427,15,-5013.55,-906.184,-5.49,"Pao'ka Swiftmountain"),
(10427,16,-4992.46,-920.983,-4.98,"Pao'ka Swiftmountain"),
(10427,17,-4976.35,-1003,-5.38,"Pao'ka Swiftmountain"),
(10427,18,-4958.48,-1033.19,-5.433,"Pao'ka Swiftmountain"),
(10427,19,-4953.35,-1052.21,-10.836,"Pao'ka Swiftmountain"),
(10427,20,-4937.45,-1056.35,-22.139,"Pao'ka Swiftmountain"),
(10427,21,-4908.46,-1050.43,-33.458,"Pao'ka Swiftmountain"),
(10427,22,-4905.53,-1056.89,-33.722,"Pao'ka Swiftmountain"),
(10427,23,-4920.83,-1073.28,-45.515,"Pao'ka Swiftmountain"),
(10427,24,-4933.37,-1082.7,-50.186,"Pao'ka Swiftmountain"),
(10427,25,-4935.31,-1092.35,-52.785,"Pao'ka Swiftmountain"),
(10427,26,-4929.55,-1101.27,-50.637,"Pao'ka Swiftmountain"),
(10427,27,-4920.68,-1100.03,-51.944,"Pao'ka Swiftmountain");
