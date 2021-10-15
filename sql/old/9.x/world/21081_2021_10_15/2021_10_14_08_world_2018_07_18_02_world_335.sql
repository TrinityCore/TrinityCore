-- 
-- Razzle Sprysprocket
DELETE FROM `creature_text` WHERE `CreatureID` IN (1269,5568);
DELETE FROM `creature_text` WHERE `CreatureID`=1268 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1269,0,0,"Let me install these Gyromechanic Gears and Restabilization Cogs and we'll fire up The Recombobulator.",12,7,100,0,0,0,1883,0,"Razzle Sprysprocket"),
(1269,1,0,"That should do the trick.",12,7,100,0,0,0,1884,0,"Razzle Sprysprocket"),
(1269,2,0,"Time to save the entire gnomish race. Here goes nothing!",12,7,100,5,0,0,1885,0,"Razzle Sprysprocket"),
(1269,3,0,"Back to the drawing board.",12,7,100,0,0,0,1887,0,"Razzle Sprysprocket"),
(1269,4,0,"Perhaps a bit more grease will do the trick.",12,7,100,1,0,0,1888,0,"Razzle Sprysprocket"),
(1269,4,1,"Pretty close that time. I think we've almost got it.",12,7,100,1,0,0,1889,0,"Razzle Sprysprocket"),
(1269,4,2,"The Recombobulator is shaping up quite nicely. Just a few adjustments to go!",12,7,100,1,0,0,1890,0,"Razzle Sprysprocket"),
(1268,1,0,"Precisely.",12,7,100,273,0,0,1891,0,"Ozzie Togglevolt"),
(1268,1,1,"My thoughts exactly.",12,7,100,273,0,0,1892,0,"Ozzie Togglevolt"),
(1268,1,2,"Couldn't have said it better myself.",12,7,100,273,0,0,1893,0,"Ozzie Togglevolt"),
(1268,1,3,"Most definitely.",12,7,100,273,0,0,1894,0,"Ozzie Togglevolt"),
(1268,1,4,"I was thinking the same thing.",12,7,100,273,0,0,1895,0,"Ozzie Togglevolt"),
(5568,0,0,"Oh, great.",12,7,100,0,0,0,1886,0,"Captured Leper Gnome");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=1269;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1269 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (126900,126901,126902) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1269,0,0,0,20,0,100,0,412,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Quest 'Operation Recombobulation' Finished - Remove Npc Flag Questgiver"),
(1269,0,1,0,20,0,100,0,412,0,0,0,53,0,1269,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Quest 'Operation Recombobulation' Finished - Start Waypoint"),
(1269,0,2,0,20,0,100,0,412,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Quest 'Operation Recombobulation' Finished - Say Line 0"),
(1269,0,3,0,40,0,100,0,1,1269,0,0,80,126900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Waypoint 1 Reached - Run Script"),
(1269,0,4,0,40,0,100,0,2,1269,0,0,80,126901,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Waypoint 2 Reached - Run Script"),
(1269,0,5,0,40,0,100,0,3,1269,0,0,80,126902,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Waypoint 3 Reached - Run Script"),
(126900,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Pause Waypoint"),
(126900,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.31425,"Razzle Sprysprocket - On Script - Set Orientation"),
(126900,9,2,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Set Emote State 69"),
(126900,9,3,0,0,0,100,0,8000,8000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Set Emote State 0"),
(126900,9,4,0,0,0,100,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Say Line 1"),
(126901,9,0,0,0,0,100,0,0,0,0,0,54,15000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Pause Waypoint"),
(126901,9,1,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.27153,"Razzle Sprysprocket - On Script - Set Orientation"),
(126901,9,2,0,0,0,100,0,1000,1000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Say Line 2"),
(126901,9,3,0,0,0,100,0,4000,4000,0,0,5,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Play Emote 69"),
(126901,9,4,0,0,0,100,0,1000,1000,0,0,86,7344,0,19,5568,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Cross Cast 'Recombobulate'"),
(126901,9,5,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,19,5568,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Say Line 0 (Captured Leper Gnome)"),
(126901,9,6,0,0,0,100,0,3000,3000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Say Line 3"),
(126902,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.63683,"Razzle Sprysprocket - On Script - Set Orientation"),
(126902,9,1,0,0,0,100,0,500,500,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Say Line 4"),
(126902,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,19,1268,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Say Line 0 (Ozzie Togglevolt)"),
(126902,9,3,0,0,0,100,0,0,0,0,0,28,7344,0,0,0,0,0,19,5568,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Remove Aura 'Recombobulate' from Captured Leper Gnome"),
(126902,9,4,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Razzle Sprysprocket - On Script - Add Npc Flag Questgiver");

DELETE FROM `waypoints` WHERE `entry`=1269;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(1269,1,-5496.54,-455.453,395.439,""),
(1269,2,-5499.83,-454.55,395.439,""),
(1269,3,-5497.94,-455.835,395.438,"");
