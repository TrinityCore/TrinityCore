-- Pozzik
DELETE FROM `smart_scripts` WHERE `entryorguid`=4630 AND `source_type`=0 AND `id` IN (3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=463001 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4630,0,3,0,20,1,100,0,1192,0,0,0,80,463001,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pozzik - On Quest 'Indurium Ore' Rewarded - Run Script (Phase 1)"),
(463001,9,0,0,0,0,100,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pozzik - On Script - Set Event Phase 0"),
(463001,9,1,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Pozzik - On Script - Say Line 1"),
(463001,9,2,0,0,0,100,0,0,0,0,0,45,2,2,0,0,0,0,10,21553,4429,0,0,0,0,0,"Pozzik - On Script - Set Data to Goblin Pit Crewman");

-- Goblin Pit Crewman
DELETE FROM `smart_scripts` WHERE `entryorguid`=-21553 AND `source_type`=0 AND `id` IN (4,5,6,7);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (442902,442903,442904) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-21553,0,4,0,38,0,100,0,2,2,0,0,0,80,442902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Data Set - Run Script"),
(-21553,0,5,0,40,0,100,0,1,442900,0,0,0,80,442903,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Waypoint 1 Reached - Run Script"),
(-21553,0,6,0,40,0,100,0,5,442900,0,0,0,80,442904,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Waypoint 5 Reached - Run Script"),
(-21553,0,7,0,40,0,100,0,8,442900,0,0,0,89,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Waypoint 8 Reached - Start Random Movement"),
(442902,9,0,0,0,0,100,0,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Stop Random Movement"),
(442902,9,1,0,0,0,100,0,0,0,0,0,0,53,0,442900,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Start Waypoint"),
(442902,9,2,0,0,0,100,0,0,0,0,0,0,71,0,0,1903,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Equip Item"),
(442903,9,0,0,0,0,100,0,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Pause Waypoint"),
(442903,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.35229,"Goblin Pit Crewman - On Script - Set Orientation"),
(442903,9,2,0,0,0,100,0,1000,1000,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Set Emote State 233"),
(442903,9,3,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Say Line 2"),
(442903,9,4,0,0,0,100,0,6000,6000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Set Emote State 0"),
(442904,9,0,0,0,0,100,0,0,0,0,0,0,54,12000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Pause Waypoint"),
(442904,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.1611,"Goblin Pit Crewman - On Script - Set Orientation"),
(442904,9,2,0,0,0,100,0,1000,1000,0,0,0,17,233,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Set Emote State 233"),
(442904,9,3,0,0,0,100,0,10000,10000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Say Line 3"),
(442904,9,4,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Set Emote State 0"),
(442904,9,5,0,0,0,100,0,3000,3000,0,0,0,1,2,0,0,0,0,0,19,4630,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Say Line 2 (Pozzik)"),
(442904,9,6,0,0,0,100,0,5000,5000,0,0,0,45,1,1,0,0,0,0,19,4630,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Set Data to Pozzik"),
(442904,9,7,0,0,0,100,0,0,0,0,0,0,71,0,0,1911,0,0,0,1,0,0,0,0,0,0,0,"Goblin Pit Crewman - On Script - Equip Item");

DELETE FROM `creature_text` WHERE `CreatureID`=4630 AND `GroupID` IN (1,2);
DELETE FROM `creature_text` WHERE `CreatureID`=4429 AND `GroupID` IN (2,3);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4630,1,0,"Thanks again, $n.  Now I'll use this indurium to beef up my car!",12,0,100,0,0,0,1505,0,"Goblin Pit Crewman"),
(4630,2,0,"Now for the next race, the car will be even FASTER than before!",12,0,100,4,0,0,1508,0,"Goblin Pit Crewman"),
(4429,2,0,"BANG! BANG! BANG!  I'm beefing up the car!!!",12,0,100,0,0,0,1506,0,"Goblin Pit Crewman"),
(4429,3,0,"All done!",12,0,100,0,0,0,1507,0,"Goblin Pit Crewman");

DELETE FROM `waypoints` WHERE `entry`=442900;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(442900,1,-6190.84,-3962.75,-58.7498,""),
(442900,2,-6191.97,-3963.59,-58.7498,""),
(442900,3,-6192.18,-3965.88,-58.7498,""),
(442900,4,-6190.21,-3966.79,-58.7498,""),
(442900,5,-6189.04,-3965.8,-58.7498,""),
(442900,6,-6190.21,-3966.79,-58.7498,""),
(442900,7,-6192.18,-3965.88,-58.7498,""),
(442900,8,-6193.59,-3963.64,-58.6251,"");
