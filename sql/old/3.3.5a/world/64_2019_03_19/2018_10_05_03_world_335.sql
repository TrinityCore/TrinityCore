-- Grark Lorkrub
DELETE FROM `smart_scripts` WHERE `entryorguid`=9520 AND `source_type`=0 AND `id` IN (10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (952000,952001,952002,952003,952004) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9520,0,10,11,19,0,100,0,4121,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grark Lorkrub - On Quest 'Precarious Predicament' Taken - Store Targetlist"),
(9520,0,11,12,61,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Quest 'Precarious Predicament' Taken - Remove Npc Flag Questgiver"),
(9520,0,12,0,61,0,100,0,0,0,0,0,0,80,952000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Quest 'Precarious Predicament' Taken - Run Script"),
(9520,0,13,0,40,0,100,0,7,9520,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 7 Reached - Say Line 3"),
(9520,0,14,0,40,0,100,0,7,9520,0,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 7 Reached - Pause Waypoint"),
(9520,0,15,0,40,0,100,0,12,9520,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 12 Reached - Say Line 4"),
(9520,0,16,0,40,0,100,0,12,9520,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 12 Reached - Summon Group 1"),
(9520,0,17,0,40,0,100,0,12,9520,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 12 Reached - Set Rooted On"),
(9520,0,18,0,77,0,100,1,1,4,0,0,0,80,952001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Counter=4 - Run Script"),
(9520,0,19,0,40,0,100,0,24,9520,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 24 Reached - Say Line 6"),
(9520,0,20,0,40,0,100,0,24,9520,0,0,0,107,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 24 Reached - Summon Group 2"),
(9520,0,21,0,40,0,100,0,24,9520,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 24 Reached - Set Rooted On"),
(9520,0,22,0,77,0,100,1,1,8,0,0,0,80,952002,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Counter=8 - Run Script"),
(9520,0,23,0,40,0,100,0,28,9520,0,0,0,107,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 28 Reached - Summon Group 3"),
(9520,0,24,0,40,0,100,0,29,9520,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 29 Reached - Say Line 8"),
(9520,0,25,0,40,0,100,0,29,9520,0,0,0,103,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 29 Reached - Set Rooted On"),
(9520,0,26,0,40,0,100,0,29,9520,0,0,0,45,1,1,0,0,0,0,9,7046,0,100,0,0,0,0,"Grark Lorkrub - On Waypoint 29 Reached - Set Data to Searscale Drake"),
(9520,0,27,0,77,0,100,1,1,11,0,0,0,80,952003,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Counter=11 - Run Script"),
(9520,0,28,0,40,0,100,0,36,9520,0,0,0,1,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 36 Reached - Say Line 10"),
(9520,0,29,0,40,0,100,0,36,9520,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 36 Reached - Pause Waypoint"),
(9520,0,30,0,40,0,100,0,45,9520,0,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 45 Reached - Say Line 11"),
(9520,0,31,0,40,0,100,0,45,9520,0,0,0,107,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 45 Reached - Summon Group 4"),
(9520,0,32,0,40,0,100,0,46,9520,0,0,0,80,952004,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Waypoint 46 Reached - Run Script"),
(9520,0,33,0,11,0,100,0,0,0,0,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Respawn - Remove Unit Flags 'Immune to Player'+'Immune to NPC'"),
(952000,9,0,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 2"),
(952000,9,1,0,0,0,100,0,0,0,0,0,0,18,768,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Add Unit Flags 'Immune to Player'+'Immune to NPC'"),
(952000,9,2,0,0,0,100,0,4000,4000,0,0,0,53,0,9520,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Start Waypoint"),
(952001,9,0,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 5"),
(952001,9,1,0,0,0,100,0,4000,4000,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Set Rooted Off"),
(952002,9,0,0,0,0,100,0,0,0,0,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 7"),
(952002,9,1,0,0,0,100,0,5000,5000,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Set Rooted Off"),
(952003,9,0,0,0,0,100,0,0,0,0,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 9"),
(952003,9,1,0,0,0,100,0,4000,4000,0,0,0,103,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Set Rooted Off"),
(952004,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.63477,"Grark Lorkrub - On Script - Set Orientation"),
(952004,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,19,9539,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 0 (Shadow of Lexlort)"),
(952004,9,2,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Set Flag Standstate 'Kneel'"),
(952004,9,3,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,19,9539,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 1 (Shadow of Lexlort)"),
(952004,9,4,0,0,0,100,0,6000,6000,0,0,0,45,1,1,0,0,0,0,19,9538,0,0,0,0,0,0,"Grark Lorkrub - On Script - Set Data to High Executioner Nuzrak"),
(952004,9,5,0,0,0,100,0,7000,7000,0,0,0,1,2,0,0,0,0,0,19,9539,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 2 (Shadow of Lexlort)"),
(952004,9,6,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,19,9539,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 3 (Shadow of Lexlort)"),
(952004,9,7,0,0,0,100,0,2000,2000,0,0,0,5,37,0,0,0,0,0,19,9538,0,0,0,0,0,0,"Grark Lorkrub - On Script - Play Emote 'Attack 2H Tight' (High Executioner Nuzrak)"),
(952004,9,8,0,0,0,100,0,500,500,0,0,0,11,29266,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Cast 'Permanent Feign Death'"),
(952004,9,9,0,0,0,100,0,1000,1000,0,0,0,15,4121,0,0,0,0,0,12,1,0,0,0,0,0,0,"Grark Lorkrub - On Script - Complete Quest 'Precarious Predicament'"),
(952004,9,10,0,0,0,100,0,2000,2000,0,0,0,1,4,0,0,0,0,0,19,9539,0,0,0,0,0,0,"Grark Lorkrub - On Script - Say Line 4 (Shadow of Lexlort)"),
(952004,9,11,0,0,0,100,0,10000,10000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grark Lorkrub - On Script - Despawn");

DELETE FROM `creature_text` WHERE `CreatureID`=9520 AND `GroupID` IN (2,3,4,5,6,7,8,9,10,11);
DELETE FROM `creature_text` WHERE `CreatureID` IN (9539,9538);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9520,2,0,"I know the way, insect. There is no need to prod me as if I were cattle.",12,0,100,1,0,0,4903,0,"Grark Lorkrub"),
(9520,3,0,"Surely you do not think that you will get away with this incursion. They will come for me and you shall pay for your insolence.",12,0,100,1,0,0,4904,0,"Grark Lorkrub"),
(9520,4,0,"RUN THEM THROUGH BROTHERS!",12,0,100,5,0,0,4905,0,"Grark Lorkrub"),
(9520,5,0,"I doubt you will be so lucky the next time you encounter my brethren.",12,0,100,1,0,0,4906,0,"Grark Lorkrub"),
(9520,6,0,"They come for you, fool!",12,0,100,5,0,0,4907,0,"Grark Lorkrub"),
(9520,7,0,"What do you think you accomplish from this, fool? Even now, the Blackrock armies make preparations to destroy your world.",12,0,100,1,0,0,4908,0,"Grark Lorkrub"),
(9520,8,0,"On darkest wing they fly. Prepare to meet your end!",12,0,100,5,0,0,4909,0,"Grark Lorkrub"),
(9520,9,0,"The worst is yet to come!",12,0,100,1,0,0,4911,0,"Grark Lorkrub"),
(9520,10,0,"%s laughs.",16,0,100,11,0,0,4912,0,"Grark Lorkrub"),
(9520,11,0,"Time to make your final stand, insect.",12,0,100,0,0,0,4913,0,"Grark Lorkrub"),
(9539,0,0,"Kneel, Grark.",12,0,100,25,0,0,4928,0,"Shadow of Lexlort"),
(9539,1,0,"Grark Lorkrub, you have been charged and found guilty of treason against the Horde. How you plead is unimportant. High Executioner Nuzrak, step forward.",12,0,100,1,0,0,4929,0,"Shadow of Lexlort"),
(9539,2,0,"%s raises his hand and then lowers it.",16,0,100,0,0,0,4932,0,"Shadow of Lexlort"),
(9539,3,0,"End him...",12,0,100,0,0,0,4931,0,"Shadow of Lexlort"),
(9539,4,0,"You, soldier, report back to Kargath at once!",12,0,100,1,0,0,4933,0,"Shadow of Lexlort"),
(9538,0,0,"%s raises his massive axe over Grark.",16,0,100,0,0,0,4930,0,"High Executioner Nuzrak");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=9520;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(9520,0,1,9522,-7844.3,-1521.6,139.2,0.0,1,300000),
(9520,0,1,9522,-7860.4,-1507.8,141.0,6.0,1,300000),
(9520,0,1,9605,-7845.6,-1508.1,138.8,6.1,1,300000),
(9520,0,1,9605,-7859.8,-1521.8,139.2,6.2,1,300000),
(9520,0,2,9522,-8035.3,-1222.2,135.5,5.1,1,300000),
(9520,0,2,7042,-8037.5,-1216.9,135.8,5.1,1,300000),
(9520,0,2,9522,-8009.5,-1222.1,139.2,3.9,1,300000),
(9520,0,2,7042,-8007.1,-1219.4,140.1,3.9,1,300000),
(9520,0,3,7046,-7897.2,-1132.4,194.6,2.9,1,300000),  
(9520,0,3,7046,-7898.8,-1125.1,193.9,3.0,1,300000),
(9520,0,3,7046,-7895.6,-1119.5,194.5,3.1,1,300000),
(9520,0,4,9538,-7532.3,-1029.4,258.0,2.7,1,40000),
(9520,0,4,9539,-7532.8,-1032.9,258.2,2.5,1,40000);

DELETE FROM `waypoints` WHERE `entry`=9520;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(9520,1,-7699.62,-1444.29,139.87,""),
(9520,2,-7670.67,-1458.25,140.74,""),
(9520,3,-7675.26,-1465.58,140.74,""),
(9520,4,-7685.84,-1472.66,140.75,""),
(9520,5,-7700.08,-1473.41,140.79,""),
(9520,6,-7712.55,-1470.19,140.79,""),
(9520,7,-7717.27,-1481.7,140.72,""),
(9520,8,-7726.23,-1500.78,132.99,""),
(9520,9,-7744.61,-1531.61,132.69,""),
(9520,10,-7763.08,-1536.22,131.93,""),
(9520,11,-7815.32,-1522.61,134.16,""),
(9520,12,-7850.26,-1516.87,138.17,""),
(9520,13,-7850.26,-1516.87,138.17,""),
(9520,14,-7881.01,-1508.49,142.37,""),
(9520,15,-7888.91,-1458.09,144.79,""),
(9520,16,-7889.18,-1430.21,145.31,""),
(9520,17,-7900.53,-1427.01,150.26,""),
(9520,18,-7904.15,-1429.91,150.27,""),
(9520,19,-7921.48,-1425.47,140.54,""),
(9520,20,-7941.43,-1413.1,134.35,""),
(9520,21,-7964.85,-1367.45,132.99,""),
(9520,22,-7989.95,-1319.12,133.71,""),
(9520,23,-8010.43,-1270.23,133.42,""),
(9520,24,-8025.62,-1243.78,133.91,""),
(9520,25,-8025.62,-1243.78,133.91,""),
(9520,26,-8015.22,-1196.98,146.76,""),
(9520,27,-7991.59,-1154.3,160.529,""),
(9520,28,-7970.91,-1132.81,170.16,""),
(9520,29,-7927.59,-1122.79,185.86,""),
(9520,30,-7897.67,-1126.67,194.32,""),
(9520,31,-7897.67,-1126.67,194.32,""),
(9520,32,-7864.11,-1135.98,203.29,""),
(9520,33,-7837.31,-1137.73,209.63,""),
(9520,34,-7808.72,-1134.9,214.84,""),
(9520,35,-7786.85,-1127.24,214.84,""),
(9520,36,-7746.58,-1125.16,215.08,""),
(9520,37,-7746.41,-1103.62,215.62,""),
(9520,38,-7740.25,-1090.51,216.69,""),
(9520,39,-7730.97,-1085.55,217.12,""),
(9520,40,-7697.89,-1089.43,217.62,""),
(9520,41,-7679.3,-1059.15,220.09,""),
(9520,42,-7661.39,-1038.24,226.24,""),
(9520,43,-7634.49,-1020.96,234.3,""),
(9520,44,-7596.22,-1013.16,244.03,""),
(9520,45,-7556.53,-1021.74,253.21,""),
(9520,46,-7541.02,-1026.48,256.393,"");

-- Blackrock Ambusher
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9522;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9522 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9522,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Blackrock Ambusher - Just Summoned - Start Attacking"),
(9522,0,1,0,6,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,23,0,0,0,0,0,0,0,"Blackrock Ambusher - On Just Died - Set Counter");

-- Blackrock Ambusher
DELETE FROM `smart_scripts` WHERE `entryorguid`=9605 AND `source_type`=0 AND `id` IN (4,5);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9605,0,4,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Blackrock Raider - Just Summoned - Start Attacking"),
(9605,0,5,0,6,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,23,0,0,0,0,0,0,0,"Blackrock Raider - On Just Died - Set Counter");

-- Flamescale Dragonspawn
DELETE FROM `smart_scripts` WHERE `entryorguid`=7042 AND `source_type`=0 AND `id` IN (2,3);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7042,0,2,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Flamescale Dragonspawn - Just Summoned - Start Attacking"),
(7042,0,3,0,6,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,23,0,0,0,0,0,0,0,"Flamescale Dragonspawn - On Just Died - Set Counter");

-- Searscale Drake
DELETE FROM `smart_scripts` WHERE `entryorguid`=7046 AND `source_type`=0 AND `id` IN (1,2);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7046,0,1,0,6,0,100,0,0,0,0,0,0,63,1,1,0,0,0,0,23,0,0,0,0,0,0,0,"Searscale Drake - On Just Died - Set Counter"),
(7046,0,2,0,38,0,100,0,1,1,0,0,0,49,0,0,0,0,0,0,21,100,0,0,0,0,0,0,"Searscale Drake - On Data Set - Start Attacking");

-- High Executioner Nuzrak
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9538;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9538 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=953800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(9538,0,0,0,38,0,100,0,1,1,0,0,0,80,953800,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Executioner Nuzrak - On Data Set - Run Script"),
(953800,9,0,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Executioner Nuzrak - On Script - Set Run Off"),
(953800,9,1,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-7538.88,-1024.88,256.634,0,"High Executioner Nuzrak - On Script - Move to Position"),
(953800,9,2,0,0,0,100,0,5000,5000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.08835,"High Executioner Nuzrak - On Script - Set Orientation"),
(953800,9,3,0,0,0,100,0,0,0,0,0,0,17,375,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Executioner Nuzrak - On Script - Set Emote State 'Ready 2H'"),
(953800,9,4,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"High Executioner Nuzrak - On Script - Say Line 0");
