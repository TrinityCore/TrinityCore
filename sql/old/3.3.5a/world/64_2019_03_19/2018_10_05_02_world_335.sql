-- Quest "Freedom for All Creatures"
UPDATE `smart_scripts` SET `action_param1`=2 WHERE `entryorguid`=7956 AND `source_type`=0 AND `id`=6;
DELETE FROM `smart_scripts` WHERE `entryorguid`=7956 AND `source_type`=0 AND `id` IN (13,14);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(7956,0,13,0,9,0,100,0,0,30,2000,4000,0,11,6660,64,0,0,0,0,2,0,0,0,0,0,0,0,"Kindal Moonweaver - Within 0-30 Range - Cast 'Shoot'"),
(7956,0,14,0,0,0,100,0,5000,7000,8000,11000,0,11,14443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Kindal Moonweaver - In Combat - Cast 'Multi-Shot'");

-- Quest "Wandering Shay"
DELETE FROM `creature_text` WHERE `CreatureID`=7774 AND `GroupID` IN (1,3) AND `ID`=4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(7774,1,4,"Oh, there you are!",12,0,100,0,0,0,3906,0,"Shay Leafrunner"),
(7774,3,4,"Hmmm, I wonder what's over this way?",12,0,100,0,0,0,3911,0,"Shay Leafrunner");

-- Quest "Get Me Out of Here!"
UPDATE `smart_scripts` SET `action_param1`=17000 WHERE `entryorguid`=12277 AND `source_type`=0 AND `id`=7;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1227700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(1227700,9,0,0,0,0,100,0,1000,1000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Script - Say Line 2"),
(1227700,9,1,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Script - Say Line 3"),
(1227700,9,2,0,0,0,100,0,5000,5000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Melizza Brimbuzzle - On Script - Say Line 4"),
(1227700,9,3,0,0,0,100,0,5000,5000,0,0,0,1,0,0,0,0,0,0,19,6019,0,0,0,0,0,0,"Melizza Brimbuzzle - On Script - Say Line 0 (Hornizz Brimbuzzle)"),
(1227700,9,4,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,19,6019,0,0,0,0,0,0,"Melizza Brimbuzzle - On Script - Say Line 1 (Hornizz Brimbuzzle)");

DELETE FROM `creature_text` WHERE `CreatureID`=6019;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(6019,0,0,"Bye!  Better luck next time!",12,0,100,3,0,0,7553,0,"Hornizz Brimbuzzle"),
(6019,1,0,"Always on the go, that girl.",12,0,100,0,0,0,7554,0,"Hornizz Brimbuzzle");

-- Quest "Rot Hide Origins"
DELETE FROM `creature_text` WHERE `CreatureID`=1498 AND `GroupID`=3 AND `ID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1498,3,2,"$n, I have the information you seek...",12,0,100,1,0,0,517,0,"Bethor Iceshard");

-- Quest "Deeprun Rat Roundup"
DELETE FROM `smart_scripts` WHERE `entryorguid`=12997 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1299700,1299701) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(12997,0,0,1,20,0,100,0,6661,0,0,0,0,53,0,12997,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - On Quest 'Deeprun Rat Roundup' Finished - Start Waypoint"),
(12997,0,1,0,61,0,100,0,0,0,0,0,0,83,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - On Quest 'Deeprun Rat Roundup' Finished - Remove Npc Flag Questgiver+Gossip"),
(12997,0,2,0,40,0,100,0,1,12997,0,0,0,80,1299700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - On Waypoint 1 Reached - Run Script"),
(12997,0,3,0,40,0,100,0,2,12997,0,0,0,80,1299701,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - On Waypoint 2 Reached - Run Script"),
(12997,0,4,0,1,0,100,0,50000,70000,540000,620000,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - Out Of Combat - Say Line 1"),
(1299700,9,0,0,0,0,100,0,0,0,0,0,0,54,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - On Script - Pause Waypoint"),
(1299700,9,1,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.597,"Monty - On Script - Set Orientation"),
(1299700,9,2,0,0,0,100,0,500,500,0,0,0,11,21052,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - On Script - Cast 'Monty Bashes Rats' (DND)"),
(1299700,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Monty - On Script - Say Line 0"),
(1299701,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.79965,"Monty - On Script - Set Orientation"),
(1299701,9,1,0,0,0,100,0,0,0,0,0,0,82,3,0,0,0,0,0,1,0,0,0,0,0,0,4.79965,"Monty - On Script - Add Npc Flag Questgiver+Gossip");

DELETE FROM `waypoints` WHERE `entry`=12997;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(12997,1,-19.613,38.2831,-4.29804,""),
(12997,2,-19.6312,40.0752,-4.21403,"");

-- Quest "The Thandol Span (Part 2)"
DELETE FROM `creature_text` WHERE `CreatureID`=4062;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4062,0,0,"Still no sign of the final shipment of explosives.",12,7,100,0,0,0,782,0,"Dark Iron Bombardier"),
(4062,0,1,"No sign of the final explosives shipment to the west either.  Where are those lollygaggers?",12,7,100,0,0,0,783,0,"Dark Iron Bombardier"),
(4062,0,2,"This bridge should have been destroyed by now.  How long does it take for those lazy sods to get here from the Highlands!",12,7,100,0,0,0,784,0,"Dark Iron Bombardier");

UPDATE `smart_scripts` SET `action_param1`=0 WHERE `entryorguid`=406200 AND `source_type`=9 AND `id`=1;

-- Quest "Hints of a New Plague? (Part 4)"
UPDATE `smart_scripts` SET `action_param1`=8000 WHERE `entryorguid`=2713 AND `source_type`=0 AND `id`=11;
UPDATE `smart_scripts` SET `action_param1`=10000 WHERE `entryorguid`=2713 AND `source_type`=0 AND `id`=13;
UPDATE `smart_scripts` SET `action_param1`=6000 WHERE `entryorguid`=2713 AND `source_type`=0 AND `id`=16;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2713 AND `source_type`=0 AND `id` IN (12,21,22,23);
DELETE FROM `smart_scripts` WHERE `entryorguid`=271300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2713,0,12,13,40,0,100,0,18,2713,0,0,0,80,271300,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 18 Reached - Run Script"),
(2713,0,21,22,61,0,100,512,35,2713,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.14159,"Kinelory - On Waypoint 35 Reached - Set Orientation"),
(2713,0,22,23,61,0,100,512,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 35 Reached - Set Npc Flag Questgiver"),
(2713,0,23,0,61,0,100,512,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kinelory - On Waypoint 35 Reached - Set Unit Flag 'Immune To NPCs'"),
(271300,9,0,0,0,0,100,0,0,0,0,0,0,1,9,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Script - Say Line 9"),
(271300,9,1,0,0,0,100,0,4000,4000,0,0,0,1,4,0,0,0,0,0,12,0,0,0,0,0,0,0,"Kinelory - On Script - Say Line 9");

DELETE FROM `creature_text` WHERE `CreatureID`=2713 AND `GroupID`=9;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2713,9,0,"Found something... I think.",12,7,100,0,0,0,820,0,"Kinelory");

UPDATE `smart_scripts` SET `target_type`=1, `target_param1`=0 WHERE `entryorguid`=2733 AND `source_type`=0 AND `id`=0; -- Fix target type for Apothecary Jorell

-- Quest "Challenge Overlord Mok'Morokk"
DELETE FROM `creature_text` WHERE `CreatureID`=4500 AND `GroupID`=2;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4500,2,0,"Me still boss of ogres. Haw!",14,0,100,0,0,0,1514,0,"Overlord Mok'Morokk");

DELETE FROM `smart_scripts` WHERE `entryorguid`=4500 AND `source_type`=0 AND `id`=10;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4500,0,10,0,5,0,100,1,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Overlord Mok'Morokk - On Killed Unit - Say Line 2");

-- Quest "Suspicious Hoofprints (Horde)"
UPDATE `smart_scripts` SET `event_param1`=6000, `event_param2`=6000 WHERE `entryorguid`=492600 AND `source_type`=9 AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=15000 WHERE `entryorguid`=4972 AND `source_type`=0 AND `id`=1;

-- Quest "Traitors Among Us"
DELETE FROM `smart_scripts` WHERE `entryorguid`=23602 AND `source_type`=0 AND `id`=7;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23602,0,7,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,"Deserter Agitator - Between 0-15% Health - Flee For Assist (No Repeat)");

-- Quest "Discrediting the Deserters"
DELETE FROM `creature_text` WHERE `CreatureID`=4979 AND `GroupID`=3;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4979,3,0,"%s reads the leaflet.",16,0,100,6,0,0,22112,0,"Theramore Guard");

UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=4979 AND `GroupID`=0;
UPDATE `creature_text` SET `Emote`=11 WHERE `CreatureID`=4979 AND `GroupID`=1;
UPDATE `creature_text` SET `Emote`=5 WHERE `CreatureID`=4979 AND `GroupID`=2;

DELETE FROM `smart_scripts` WHERE `entryorguid`=4979 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=497900 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4979,0,0,1,62,0,100,0,8851,0,0,0,0,80,497900,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Run Script"),
(4979,0,1,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Close Gossip"),
(497900,9,0,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Remove NPC Flag Gossip"),
(497900,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Say Line 0"),
(497900,9,2,0,0,0,100,0,0,0,0,0,0,75,42246,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Add Aura 'Doctored Leaflet'"),
(497900,9,3,0,0,0,100,0,3000,3000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Say Line 3"),
(497900,9,4,0,0,0,100,0,3000,3000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Say Line 1"),
(497900,9,5,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Say Line 2"),
(497900,9,6,0,0,0,100,0,0,0,0,0,0,33,4979,0,0,0,0,0,7,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Give Kill Credit"),
(497900,9,7,0,0,0,100,0,5000,5000,0,0,0,82,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Guard - On Gossip Option Selected - Add NPC Flag Gossip");

-- Quest "Suspicious Hoofprints (Alliance)"
DELETE FROM `smart_scripts` WHERE `entryorguid`=4944 AND `source_type`=0 AND `id` IN (2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=494401 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4944,0,2,0,20,0,100,0,1284,0,0,0,0,80,494401,2,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garran Vimes - On Quest 'Suspicious Hoofprints' Finished - Run Script"),
(494401,9,0,0,0,0,100,0,10,10,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Garran Vimes - On Script - Say Line 3"),
(494401,9,1,0,0,0,100,0,6000,6000,0,0,0,1,0,0,0,0,0,0,19,4948,50,0,0,0,0,0,"Captain Garran Vimes - On Script - Say Line 0 (Adjutant Tesoran)"),
(494401,9,2,0,0,0,100,0,0,0,0,0,0,12,5088,5,0,0,0,0,8,0,0,0,-3717.04,-4523.46,25.8339,5.15678,"Captain Garran Vimes - On Script - Summon Creature 'Falgran Hastil'");

-- Quest "Take Down Tethyr!"
DELETE FROM `creature_text` WHERE `CreatureID`=23905 AND `GroupID`=4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(23905,4,0,"We defeated the sea monster!",14,0,100,0,0,0,22634,0,"Major Mills");

DELETE FROM `smart_scripts` WHERE `entryorguid`=23905 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2390501 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23905,0,0,0,19,0,100,512,11198,0,0,0,0,80,2390500,2,0,0,0,0,1,0,0,0,0,0,0,0,"Major Mills - On Quest 'Take Down Tethyr!' Taken - Run Script"),
(23905,0,1,0,38,0,100,512,0,1,0,0,0,80,2390501,2,0,0,0,0,1,0,0,0,0,0,0,0,"Major Mills - On Data Set - Run Script"),
(23905,0,2,0,38,0,100,512,0,2,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Major Mills - On Data Set - Add Npc Flag Questgiver"),
(2390501,9,0,0,0,0,100,512,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Major Mills - On Script - Add Npc Flag Questgiver"),
(2390501,9,1,0,0,0,100,512,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Major Mills - On Script - Say Line 3"),
(2390501,9,2,0,0,0,100,512,0,0,0,0,0,15,11198,0,0,0,0,0,18,100,0,0,0,0,0,0,"Major Mills - On Script - Complete Quest 'Take Down Tethyr!'"),
(2390501,9,3,0,0,0,100,512,4000,4000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Major Mills - On Script - Say Line 4");

-- Quest "Stromgarde Badges"
DELETE FROM `smart_scripts` WHERE `entryorguid`=2700 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=270000 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2700,0,0,0,20,0,100,0,682,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Quest 'Stromgarde Badges' Finished - Remove Npc Flag Questgiver"),
(2700,0,1,0,20,0,100,0,682,0,0,0,0,53,0,2700,0,0,0,2,1,0,0,0,0,0,0,0,"Captain Nials - On Quest 'Stromgarde Badges' Finished - Start Waypoint"),
(2700,0,2,0,40,0,100,0,2,2700,0,0,0,80,270000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Waypoint 2 Reached - Run Script"),
(2700,0,3,0,40,0,100,0,4,2700,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.27122,"Captain Nials - On Waypoint 4 Reached - Set Orientation"),
(2700,0,4,0,40,0,100,0,4,2700,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Waypoint 4 Reached - Add Npc Flag Questgiver"),
(270000,9,0,0,0,0,100,0,0,0,0,0,0,54,17000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Pause Waypoint"),
(270000,9,1,0,0,0,100,0,1000,1000,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Set Emote State 69"),
(270000,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 0"),
(270000,9,3,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 1"),
(270000,9,4,0,0,0,100,0,4500,4500,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 2"),
(270000,9,5,0,0,0,100,0,3000,3000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Set Emote State 0"),
(270000,9,6,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 3"),
(270000,9,7,0,0,0,100,0,1500,1500,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 4"),
(270000,9,8,0,0,0,100,0,5000,5000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Captain Nials - On Script - Say Line 5");

DELETE FROM `waypoints` WHERE `entry`=2700;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(2700,1,-1276.56,-2514.61,21.4246,""),
(2700,2,-1276.63,-2512.68,21.5479,""),
(2700,3,-1275.98,-2515.15,21.4072,""),
(2700,4,-1274.69,-2516.63,21.4792,"");

-- Quest "Peace at Last"
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23768,23769) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2376800 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23768,0,0,0,11,0,100,0,0,0,0,0,0,80,2376800,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lynn Hyal - On Spawn - Run Script"),
(23769,0,0,0,38,0,100,0,1,1,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,1.18451,"Jimmy Hyal - On Data Set - Set Orientation"),
(23769,0,1,0,38,0,100,0,1,1,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Jimmy Hyal - On Data Set - Say Line 1"),
(2376800,9,0,0,0,0,100,0,0,0,0,0,0,1,1,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Say Line 1"),
(2376800,9,1,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Say Line 2"),
(2376800,9,2,0,0,0,100,0,5000,5000,0,0,0,1,3,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Say Line 3"),
(2376800,9,3,0,0,0,100,0,7000,7000,0,0,0,1,4,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Say Line 4"),
(2376800,9,4,0,0,0,100,0,8000,8000,0,0,0,45,1,1,0,0,0,0,19,23769,0,0,0,0,0,0,"Lynn Hyal - On Script - Set Data to Jimmy Hyal"),
(2376800,9,5,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.3104,"Lynn Hyal - On Script - Set Orientation"),
(2376800,9,6,0,0,0,100,0,0,0,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Set Flag Standstate 'Kneel'"),
(2376800,9,7,0,0,0,100,0,0,0,0,0,0,1,5,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Say Line 5"),
(2376800,9,8,0,0,0,100,0,4000,4000,0,0,0,33,23768,0,0,0,0,0,23,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Quest Credit 'Peace at Last'"),
(2376800,9,9,0,0,0,100,0,3000,3000,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"Lynn Hyal - On Script - Remove Flag Standstate 'Kneel'");

UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=23768 AND `GroupID` IN (1,2,3,4);
UPDATE `creature_text` SET `Emote`=1 WHERE `CreatureID`=23769;

UPDATE `event_scripts` SET `datalong2`=40000 WHERE `id`=15385 AND `command`=10;

-- Quest "Screecher Spirits"
DELETE FROM `smart_scripts` WHERE `entryorguid`=8612 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(8612,0,0,1,64,0,100,513,0,0,0,0,0,33,8612,0,0,0,0,0,7,0,0,0,0,0,0,0,"Screecher Spirit - On Gossip Hello - Quest Credit 'Screecher Spirits'"),
(8612,0,1,0,61,0,100,513,0,0,0,0,0,41,6000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Screecher Spirit - On Gossip Hello - Despawn In 6000 ms");

-- Quest "Barbecued Buzzard Wings"
DELETE FROM `smart_scripts` WHERE `entryorguid`=2817 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=281700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2817,0,0,0,20,0,100,0,703,0,0,0,80,281700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Quest 'Barbecued Buzzard Wings' Rewarded - Run Script"),
(281700,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Remove Npc Flag Questgiver"),
(281700,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 0"),
(281700,9,2,0,0,0,100,0,0,0,0,0,11,4094,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Cast 'Barbecued Buzzard Wing'"),
(281700,9,3,0,0,0,100,0,2000,2000,0,0,5,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Play Emote 'Eat'"),
(281700,9,4,0,0,0,100,0,2000,2000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 1"),
(281700,9,5,0,0,0,100,0,0,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Add Npc Flag Questgiver");

DELETE FROM `creature_text` WHERE `CreatureID`=2817 AND `GroupID`=1;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2817,1,0,"Ow.  Spicy.",12,0,100,33,0,0,934,0,"Rigglefuzz");
