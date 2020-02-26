-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (4962,4971,4963);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4962,0,0,"Oh, it's on now! Bet you thought I'd be alone too, huh?!",12,7,100,0,0,0,5827,0,"Tapoke \"Slim\" Jahn"),
(4962,1,0,"Okay, okay! No need to get all violent. I'll talk. I'll talk!",12,7,100,0,0,0,1743,0,"Tapoke \"Slim\" Jahn"),
(4962,2,0,"I have a few notes from the job back at my place. I'll get them and then meet you back in the inn.",12,7,100,0,0,0,1744,0,"Tapoke \"Slim\" Jahn"),
(4971,0,0,"Whoa! This is way more than what I bargained for, you're on your own, Slim!",12,7,100,0,0,0,5828,0,"Slim's Friend"),
(4963,0,0,"I'm glad the commotions died down some around here. The last thing this place needs is another brawl.",12,7,100,0,0,0,4169,0,"Mikhail");

-- Waypoint
DELETE FROM `script_waypoint` WHERE `entry`=4962;
DELETE FROM `waypoints` WHERE `entry`=4962;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(4962,1,-3804.44,-828.048,10.0931,""),
(4962,2,-3803.93,-835.772,10.0777,""),
(4962,3,-3792.63,-835.671,9.65566,""),
(4962,4,-3772.43,-835.346,10.869,""),
(4962,5,-3765.94,-840.129,10.8856,""),
(4962,6,-3738.63,-830.997,11.0574,""),
(4962,7,-3690.22,-862.262,9.96045,"");

-- Mikhail
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=4963;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4963 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=496300 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4963,0,0,0,11,0,100,0,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mikhail - On Respawn - Set Npc Flag Questgiver"),
(4963,0,1,0,19,0,100,0,1249,0,0,0,0,81,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Set Npc Flag Gossip"),
(4963,0,2,0,19,0,100,0,1249,0,0,0,0,45,1,1,0,0,0,0,10,10873,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Set Data to Tapoke \"Slim\" Jahn"),
(4963,0,3,0,19,0,100,0,1249,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Store Target"),
(4963,0,4,0,19,0,100,0,1249,0,0,0,0,100,1,0,0,0,0,0,10,10873,0,0,0,0,0,0,"Mikhail - On Quest 'The Missing Diplomat (Part 11)' Taken - Send Target to Tapoke \"Slim\" Jahn"),
(4963,0,5,0,38,0,100,0,1,1,0,0,0,80,496300,2,0,0,0,0,1,0,0,0,0,0,0,0,"Mikhail - On Data Set - Run Script"),
(496300,9,0,0,0,0,100,0,10000,10000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mikhail - On Script - Say Line 0"),
(496300,9,1,0,0,0,100,0,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Mikhail - On Script - Set Npc Flag Questgiver");

-- Tapoke "Slim" Jahn
UPDATE `creature` SET `spawntimesecs`=10 WHERE `guid`=10873;
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=4962;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4962 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=496200 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4962,0,0,0,38,0,100,1,1,1,0,0,0,11,1785,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Data Set - Cast 'Stealth'"),
(4962,0,1,0,38,0,100,1,1,1,0,0,0,53,0,4962,0,0,0,2,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Data Set - Start Waypoint"),
(4962,0,2,0,38,0,100,1,1,1,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Data Set - Set Invincibility at 1 HP"),
(4962,0,3,0,40,0,100,0,3,4962,0,0,0,28,1785,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 3 Reached - Remove Aura 'Stealth'"),
(4962,0,4,0,40,0,100,0,3,4962,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 3 Reached - Set Faction 168"),
(4962,0,5,0,40,0,100,0,7,4962,0,0,0,6,1249,0,0,0,0,0,12,1,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 7 Reached - Fail Quest 'The Missing Diplomat (Part 11)'"),
(4962,0,6,0,40,0,100,0,7,4962,0,0,0,45,1,1,0,0,0,0,10,9432,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 7 Reached - Set Data to Mikhail"),
(4962,0,7,0,40,0,100,0,7,4962,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Waypoint 7 Reached - Despawn"),
(4962,0,8,0,4,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Aggro - Say Line 0"),
(4962,0,9,0,4,0,100,0,0,0,0,0,0,11,16457,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Aggro - Cast 'Call Friends'"),
(4962,0,10,0,2,0,100,1,0,20,0,0,0,80,496200,2,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - Between 0-20% Health - Run Script"),
(496200,9,0,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,4971,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Set Data to Slim's Friend"),
(496200,9,1,0,0,0,100,0,0,0,0,0,0,2,123,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Set Faction 123"),
(496200,9,2,0,0,0,100,0,0,0,0,0,0,27,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Stop Combat"),
(496200,9,3,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Say Line 1"),
(496200,9,4,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Say Line 2"),
(496200,9,5,0,0,0,100,0,6000,6000,0,0,0,15,1249,0,0,0,0,0,12,1,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Complete Quest 'The Missing Diplomat (Part 11)'"),
(496200,9,6,0,0,0,100,0,1000,1000,0,0,0,45,1,1,0,0,0,0,10,9432,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Set Data to Mikhail"),
(496200,9,7,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tapoke \"Slim\" Jahn - On Script - Despawn");

-- Slim's Friend
DELETE FROM `smart_scripts` WHERE `entryorguid`=4971 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=497100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4971,0,0,0,25,0,100,0,0,0,0,0,0,11,3616,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slim's Friend - On Reset - Cast 'Poison Proc'"),
(4971,0,1,0,25,0,100,0,0,0,0,0,0,11,8601,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slim's Friend - On Reset - Cast 'Slowing Poison'"),
(4971,0,2,0,67,0,100,0,3000,6000,0,0,0,11,2589,0,0,0,0,0,2,0,0,0,0,0,0,0,"Slim's Friend - On Behind Target - Cast Backstab"),
(4971,0,3,0,38,0,100,1,1,1,0,0,0,80,497100,2,0,0,0,0,1,0,0,0,0,0,0,0,"Slim's Friend - On Data Set - Run Script"),
(497100,9,0,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slim's Friend - On Script - Evade"),
(497100,9,1,0,0,0,100,0,0,0,0,0,0,2,123,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slim's Friend - On Script - Set Faction 123"),
(497100,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slim's Friend - On Script - Say Line 0"),
(497100,9,3,0,0,0,100,0,6000,6000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Slim's Friend - On Script - Despawn");
