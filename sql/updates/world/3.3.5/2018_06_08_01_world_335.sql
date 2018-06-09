-- Muigin
DELETE FROM `creature_text` WHERE `CreatureID`=9119;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(9119,0,0,"I hope this works!",12,0,100,0,0,0,4966,0,"Muigin"),
(9119,1,0,"%s adds the haze to the Bloodpetal sprouts.",16,0,100,0,0,0,4967,0,"Muigin"),
(9119,2,0,"Look at them go!",12,0,100,0,0,0,4968,0,"Muigin"),
(9119,3,0,"%s laughs as he watches the pests run off.",16,0,100,11,0,0,4969,0,"Muigin");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9119;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9119 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=911900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9119,0,0,0,20,0,100,0,4144,0,0,0,80,911900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Quest 'Bloodpetal Sprouts' Finished - Run Script"),
(911900,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Script - Remove Npc Flag Questgiver"),
(911900,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Script - Say Line 0"),
(911900,9,2,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.90575,"Muigin - On Script - Set Orientation"),
(911900,9,3,0,0,0,100,0,2000,2000,0,0,11,13463,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Script - Cast 'Summon Bloodpetal Mini Pests'"),
(911900,9,4,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Script - Say Line 1"),
(911900,9,5,0,0,0,100,0,2000,2000,0,0,12,9157,3,300000,0,0,0,8,0,0,0,-6196.68,-1054.22,-196.653,3.84015,"Muigin - On Script - Summon Creature 'Bloodpetal Pest'"),
(911900,9,6,0,0,0,100,0,0,0,0,0,12,9157,3,300000,0,0,0,8,0,0,0,-6199.55,-1058.29,-198.296,2.40288,"Muigin - On Script - Summon Creature 'Bloodpetal Pest'"),
(911900,9,7,0,0,0,100,0,0,0,0,0,12,9157,3,300000,0,0,0,8,0,0,0,-6200.40,-1053.85,-197.275,4.41349,"Muigin - On Script - Summon Creature 'Bloodpetal Pest'"),
(911900,9,8,0,0,0,100,0,0,0,0,0,12,9157,3,300000,0,0,0,8,0,0,0,-6203.03,-1059.16,-198.382,1.95127,"Muigin - On Script - Summon Creature 'Bloodpetal Pest'"),
(911900,9,9,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.86947,"Muigin - On Script - Set Orientation"),
(911900,9,10,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Script - Say Line 2"),
(911900,9,11,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Script - Say Line 3"),
(911900,9,12,0,0,0,100,0,5000,5000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Muigin - On Script - Add Npc Flag Questgiver");

-- Bloodpetal Pest
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=9157;
DELETE FROM `smart_scripts` WHERE `entryorguid`=9157 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=915700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9157,0,0,0,54,0,100,0,0,0,0,0,80,915700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Bloodpetal Pest - Just Summoned - Run Script"),
(9157,0,1,0,40,0,100,0,6,9157,0,0,49,0,0,0,0,0,0,19,9118,0,0,0,0,0,0,"Bloodpetal Pest - On Waypoint 6 Reached - Start Attacking"),
(915700,9,0,0,0,0,100,0,2000,2000,0,0,53,1,9157,0,0,0,2,1,0,0,0,0,0,0,0,"Bloodpetal Pest - On Script - Start Waypoint");

DELETE FROM `waypoints` WHERE `entry`=9157;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(9157,1,-6198.16,-1066.19,-202.208,""),
(9157,2,-6204.42,-1085.39,-212.243,""),
(9157,3,-6191.72,-1114.78,-218.861,""),
(9157,4,-6172.88,-1129.4,-216.835,""),
(9157,5,-6162.34,-1146.16,-217.942,""),
(9157,6,-6166.14,-1153.26,-216.84,"");
