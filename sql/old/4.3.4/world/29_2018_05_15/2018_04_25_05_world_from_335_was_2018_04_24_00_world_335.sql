/*
-- Quest "Ancient Spirit"
UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=4261; -- Prevents quest from auto completing
-- Arei
DELETE FROM `creature_text` WHERE `CreatureID`=9598;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9598,0,0,"Please, help me to get through this cursed forest, $r.",12,0,100,0,0,0,5004,0,"Arei"),
(9598,1,0,"The corruption of Felwood has trapped my spirit here... I may never rest...",12,0,100,0,0,0,5037,0,"Arei"),
(9598,2,0,"That I must fight against my own kind deeply saddens me.",12,0,100,0,0,0,5008,0,"Arei"),
(9598,3,0,"The corruption of the fel has not left any of the creatures of Felwood untouched, $n. Please, be on your guard.",12,0,100,0,0,0,5005,0,"Arei"),
(9598,4,0,"I can sense it now, $n. Ashenvale lies down this path.",12,0,100,0,0,0,5023,0,"Arei"),
(9598,5,0,"I feel... something strange...",12,0,100,0,0,0,5026,0,"Arei"),
(9598,6,0,"$n, my form has now changed! The true strength of my spirit is returning to me now... The cursed grasp of the forest is leaving me.",12,0,100,0,0,0,5029,0,"Arei"),
(9598,7,0,"Thank you, $n. Now my spirit will finally be at peace.",12,0,100,0,0,0,5036,0,"Arei"),
(9598,8,0,"I sense the taint of corruption upon this $n. Help me destroy it!",12,0,100,0,0,0,5473,0,"Arei"),
(9598,8,1,"This creature suffers from the effects of the fel... We must end its misery.",12,0,100,0,0,0,5474,0,"Arei"),
(9598,8,2,"This $n has been driven mad from the corruption!",12,0,100,0,0,0,5475,0,"Arei");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9598;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9598 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (959800,959801,959802) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9598,0,0,1,19,0,100,0,4261,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Arei - On Quest 'Ancient Spirit' Taken - Store Targetlist"),
(9598,0,1,2,61,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Quest 'Ancient Spirit' Taken - Remove Npc Flag Questgiver"),
(9598,0,2,0,61,0,100,0,0,0,0,0,80,959800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Quest 'Ancient Spirit' Taken - Run Script"),
(9598,0,3,0,6,0,100,0,0,0,0,0,6,4261,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Just Died - Fail Quest 'Ancient Spirit'"),
(9598,0,4,0,6,0,100,0,0,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Just Died - Say Line 1"),
(9598,0,5,0,40,0,100,0,7,9598,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Waypoint 7 Reached - Say Line 2"),
(9598,0,6,0,40,0,100,0,7,9598,0,0,54,5000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Waypoint 7 Reached - Pause Waypoint"),
(9598,0,7,0,40,0,100,0,15,9598,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Waypoint 15 Reached - Say Line 3"),
(9598,0,8,0,40,0,100,0,15,9598,0,0,54,8000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Waypoint 15 Reached - Pause Waypoint"),
(9598,0,9,0,40,0,100,0,36,9598,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Waypoint 36 Reached - Summon Group 1"),
(9598,0,10,0,40,0,100,0,37,9598,0,0,80,959802,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Waypoint 36 Reached - Run Script"),
(9598,0,11,0,4,0,50,0,0,0,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Aggro - Say Line 8"),
(9598,0,12,0,0,0,100,0,6000,9000,16000,21000,11,5337,0,0,0,0,0,2,0,0,0,0,0,0,0,"Arei - In Combat - Cast 'Wither Strike'"),
(959800,9,0,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Script - Say Line 0"),
(959800,9,1,0,0,0,100,0,5000,5000,0,0,53,0,9598,0,0,0,2,1,0,0,0,0,0,0,0,"Arei - On Script - Start Waypoint"),
(959800,9,2,0,0,0,100,0,0,0,0,0,2,250,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Script - Set Faction 250"),
(959802,9,0,0,0,0,100,0,0,0,0,0,2,124,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Script - Set Faction 124"),
(959802,9,1,0,0,0,100,0,1000,1000,0,0,1,4,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Script - Say Line 4"),
(959802,9,2,0,0,0,100,0,5000,5000,0,0,1,5,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Script - Say Line 5"),
(959802,9,3,0,0,0,100,0,2000,2000,0,0,11,14888,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Script - Cast 'Arei Transform'"),
(959802,9,4,0,0,0,100,0,3000,3000,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Script - Say Line 6"),
(959802,9,5,0,0,0,100,0,8000,8000,0,0,1,7,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Script - Say Line 7"),
(959802,9,6,0,0,0,100,0,0,0,0,0,15,4261,0,0,0,0,0,12,1,0,0,0,0,0,0,"Arei - On Script - Complete Quest 'Ancient Spirit'"),
(959802,9,7,0,0,0,100,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Arei - On Script - Despawn");

-- Condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=15033;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17,0,15033,0,0,29,0,9598,200,0,1,0,0,"","Spell 'Summon Ancient Spirits' cannot be casted if Arei is already summoned");

DELETE FROM `waypoints` WHERE `entry`=9598;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(9598,1,6004.265,-1180.494,376.377,''),
(9598,2,6002.512,-1157.294,381.407,''),
(9598,3,6029.228,-1139.720,383.127,''),
(9598,4,6042.479,-1128.963,386.582,''),
(9598,5,6062.820,-1115.522,386.850,''),
(9598,6,6089.188,-1111.907,383.105,''),
(9598,7,6104.390,-1114.561,380.490,''),
(9598,8,6115.080,-1128.572,375.779,''),
(9598,9,6119.352,-1147.314,372.518,''),
(9598,10,6119.003,-1176.082,371.072,''),
(9598,11,6120.982,-1198.408,373.432,''),
(9598,12,6123.521,-1226.636,374.119,''),
(9598,13,6127.737,-1246.035,373.574,''),
(9598,14,6133.433,-1253.642,369.100,''),
(9598,15,6150.787,-1269.151,369.240,''),
(9598,16,6155.805,-1275.029,373.627,''),
(9598,17,6163.544,-1307.130,376.234,''),
(9598,18,6174.800,-1340.885,379.039,''),
(9598,19,6191.144,-1371.260,378.453,''),
(9598,20,6215.652,-1397.517,376.012,''),
(9598,21,6243.784,-1407.675,371.594,''),
(9598,22,6280.775,-1408.259,370.554,''),
(9598,23,6325.360,-1406.688,370.082,''),
(9598,24,6355.000,-1404.337,370.646,''),
(9598,25,6374.679,-1399.176,372.105,''),
(9598,26,6395.803,-1367.057,374.910,''),
(9598,27,6408.569,-1333.487,376.616,''),
(9598,28,6409.075,-1312.168,379.598,''),
(9598,29,6418.689,-1277.697,381.638,''),
(9598,30,6441.689,-1247.316,387.246,''),
(9598,31,6462.136,-1226.316,397.610,''),
(9598,32,6478.021,-1216.260,408.284,''),
(9598,33,6499.632,-1217.087,419.461,''),
(9598,34,6523.165,-1220.780,430.549,''),
(9598,35,6542.716,-1216.997,437.788,''),
(9598,36,6557.279,-1211.125,441.452,''),
(9598,37,6574.568,-1204.589,443.216,'');

DELETE FROM `creature_summon_groups` WHERE `summonerId`=9598;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(9598,0,1,7139,6573.321,-1195.213,442.489,5.544130,3,300000),
(9598,0,1,7138,6573.240,-1213.475,443.643,2.371120,3,300000),
(9598,0,1,7138,6583.354,-1209.811,444.769,2.452802,3,300000);
*/
