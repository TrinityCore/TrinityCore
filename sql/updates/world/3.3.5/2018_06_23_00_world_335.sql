-- Private Thorsen
DELETE FROM `creature_text` WHERE `CreatureID` IN (738,775,733);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(738,0,0,"Time for my patrol.  I'll be back shortly.",12,7,100,66,0,0,102,0,"Private Thorsen"),
(738,1,0,"Now that the coast is clear...",12,7,100,0,0,0,103,0,"Private Thorsen"),
(738,2,0,"Well I'm here.  And I'm ready to rejoin...",12,7,100,1,0,0,23,0,"Private Thorsen"),
(738,3,0,"Thanks for saving me!",12,7,100,2,0,0,100,0,"Private Thorsen"),
(738,4,0,"I've been gone a long time...I better get back.",12,7,100,1,0,0,105,0,"Private Thorsen"),
(738,5,0,"Private Thorsen returning from patrol.  Nothing new to report - it's pretty quiet out there...",12,7,100,66,0,0,106,0,"Private Thorsen"),
(775,0,0,"You're not joining anyone, Thorsen..",12,7,100,25,0,0,24,0,"Kurzen's Agent"),
(775,1,0,"Now you die!",12,7,100,0,0,0,101,0,"Kurzen's Agent"),
(733,0,0,"Very good.  You are relieved, private.  Rest, but don't get too comfortable.  Kurzen won't leave us alone forever.",12,7,100,1,0,0,108,0,"Sergeant Yohwa");

UPDATE `creature_template` SET `faction`=11, `AIName`="SmartAI" WHERE `entry`=738;
DELETE FROM `smart_scripts` WHERE `entryorguid`=738 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (73800,73801,73802,73803,73804) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(738,0,0,0,11,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Respawn - Remove Npc Flag Questgiver"),
(738,0,1,0,11,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Respawn - Set Active On"),
(738,0,2,0,11,0,100,0,0,0,0,0,0,80,73800,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Respawn - Run Sript"),
(738,0,3,0,40,0,100,0,14,73800,0,0,0,80,73801,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Waypoint 14 Reached - Run Script"),
(738,0,4,0,40,0,100,0,16,73800,0,0,0,80,73802,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Waypoint 16 Reached - Run Script"),
(738,0,5,0,38,0,100,0,1,1,0,0,0,80,73803,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Data Set - Run Script"),
(738,0,6,0,40,0,100,0,16,73801,0,0,0,80,73804,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Waypoint 16 Reached - Run Script"),
(73800,9,0,0,0,0,100,0,600000,600000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 0"),
(73800,9,1,0,0,0,100,0,5000,5000,0,0,0,53,0,73800,0,0,0,2,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Start Waypoint"),
(73801,9,0,0,0,0,100,0,0,0,0,0,0,54,4000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Pause Waypoint"),
(73801,9,1,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 1"),
(73801,9,2,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Set Run On"),
(73802,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.23057,"Private Thorsen - On Script - Set Orientation"),
(73802,9,1,0,0,0,100,0,0,0,0,0,0,12,775,1,60000,0,0,0,8,0,0,0,-11520.9,-383.511,39.8521,1.21196,"Private Thorsen - On Script - Summon Creature 'Kurzen's Agent'"),
(73802,9,2,0,0,0,100,0,0,0,0,0,0,12,775,1,60000,0,0,0,8,0,0,0,-11524.9,-381.701,40.096,1.05488,"Private Thorsen - On Script - Summon Creature 'Kurzen's Agent'"),
(73802,9,3,0,0,0,100,0,9000,9000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 2"),
(73802,9,4,0,0,0,100,0,5000,5000,0,0,0,1,0,0,0,0,0,0,19,775,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 0 (Kurzen's Agent)"),
(73802,9,5,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,19,775,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 1 (Kurzen's Agent)"),
(73802,9,6,0,0,0,100,0,1000,1000,0,0,0,45,1,1,0,0,0,0,11,775,50,0,0,0,0,0,"Private Thorsen - On Script - Set Data to Kurzen's Agent"),
(73803,9,0,0,0,0,100,0,2000,2000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 3"),
(73803,9,1,0,0,0,100,0,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Add Npc Flag Questgiver"),
(73803,9,2,0,0,0,100,0,120000,120000,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Remove Npc Flag Questgiver"),
(73803,9,3,0,0,0,100,0,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 4"),
(73803,9,4,0,0,0,100,0,5000,5000,0,0,0,53,0,73801,0,0,0,2,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Start Waypoint"),
(73804,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.5676,"Private Thorsen - On Script - Set Orientation"),
(73804,9,1,0,0,0,100,0,500,500,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 5"),
(73804,9,2,0,0,0,100,0,7000,7000,0,0,0,1,0,0,0,0,0,0,19,733,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 0 (Sergeant Yohwa)"),
(73804,9,3,0,0,0,100,0,900000,900000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Say Line 0"),
(73804,9,4,0,0,0,100,0,5000,5000,0,0,0,53,0,73800,0,0,0,2,1,0,0,0,0,0,0,0,"Private Thorsen - On Script - Start Waypoint");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=738;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,6,738,0,0,29,1,775,200,0,1,0,0,"","SAI triggers only if both Kurzen's Agents are dead");

DELETE FROM `waypoints` WHERE `entry` IN (73800,73801);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(73800,1,-11328.6,-204.605,75.3066,""),
(73800,2,-11344.1,-211.834,75.2203,""),
(73800,3,-11368.8,-212.901,75.2614,""),
(73800,4,-11376.9,-217.981,75.0992,""),
(73800,5,-11381.8,-226.245,73.6393,""),
(73800,6,-11382.7,-248.431,65.2537,""),
(73800,7,-11389.8,-277.379,59.5323,""),
(73800,8,-11393.7,-283.161,58.6077,""),
(73800,9,-11397.5,-285.631,58.2045,""),
(73800,10,-11417,-284.249,53.5163,""),
(73800,11,-11434.1,-286.4,48.2306,""),
(73800,12,-11471.1,-288.588,37.1529,""),
(73800,13,-11480.6,-296.055,36.0918,""),
(73800,14,-11513.5,-322.018,35.78,""),
(73800,15,-11520.2,-337.882,37.4359,""),
(73800,16,-11513.3,-362.046,37.7542,""),
(73801,1,-11520.2,-337.882,37.4359,""),
(73801,2,-11513.5,-322.018,35.78,""),
(73801,3,-11480.6,-296.055,36.0918,""),
(73801,4,-11471.1,-288.588,37.1529,""),
(73801,5,-11434.1,-286.4,48.2306,""),
(73801,6,-11417,-284.249,53.5163,""),
(73801,7,-11397.5,-285.631,58.2045,""),
(73801,8,-11393.7,-283.161,58.6077,""),
(73801,9,-11389.8,-277.379,59.5323,""),
(73801,10,-11382.7,-248.431,65.2537,""),
(73801,11,-11381.8,-226.245,73.6393,""),
(73801,12,-11376.9,-217.981,75.0992,""),
(73801,13,-11368.8,-212.901,75.2614,""),
(73801,14,-11344.1,-211.834,75.2203,""),
(73801,15,-11328.6,-204.605,75.3066,""),
(73801,16,-11313.9,-202.766,75.576,"");

-- Kurzen's Agent
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=775;
DELETE FROM `smart_scripts` WHERE `entryorguid`=775 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(775,0,0,0,54,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen's Agent - Just Summoned - Set Run Off"),
(775,0,1,0,54,0,100,0,0,0,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,18,0,0,"Kurzen's Agent - Just Summoned - Move Forward"),
(775,0,2,0,38,0,100,0,1,1,0,0,0,2,46,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kurzen's Agent - On Data Set - Set Faction 46"),
(775,0,3,0,38,0,100,0,1,1,0,0,0,49,0,0,0,0,0,0,19,738,0,0,0,0,0,0,"Kurzen's Agent - On Data Set - Start Attacking"),
(775,0,4,0,6,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,738,0,0,0,0,0,0,"Kurzen's Agent - On Just Died - Set Data to Private Thorsen");
