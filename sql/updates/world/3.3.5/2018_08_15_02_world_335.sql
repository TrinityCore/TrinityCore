-- Quest "The Missing Diplomat (Part 16)"
UPDATE `quest_template_addon` SET `SpecialFlags`=2 WHERE `ID`=1324; -- Prevents quest from auto completing

-- Texts
DELETE FROM `creature_text` WHERE `CreatureID` IN (4966,5184);
DELETE FROM `creature_text` WHERE `CreatureID`=4967 AND  `GroupID` IN (1,2,3,4);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(4966,0,0,"%s obviously beaten, tries to run.",16,0,100,0,0,0,8225,0,"Private Hendel"),
(4966,1,0,"%s, too injured, gives up the chase.",16,0,100,0,0,0,8224,0,"Private Hendel"),
(4966,2,0,"Please... please... Miss Proudmore. I didn't mean to...",12,7,100,0,0,0,1759,0,"Private Hendel"),
(4967,1,0,"Ah, Private Hendel. A pleasure to meet one of the men who would betray his kingdom for pride.",12,7,100,0,0,0,1657,0,"Archmage Tervosh"),
(4967,2,0,"Why don't we deal with you now, Hendel? Lady Proudmoore will speak to you back in the tower.",12,7,100,0,0,0,1663,0,"Archmage Tervosh"),
(4967,3,0,"I apologize for taking so long to get here. I wanted Lady Proudmoore to be present also.",12,7,100,0,0,0,1761,0,"Archmage Tervosh"),
(4967,4,0,"We can only stay a few moments before returning to the tower. If you wish to speak to us more you may find us there.",12,7,100,0,0,0,1808,0,"Archmage Tervosh"),
(5184,0,0,"It's Proudmoore! Get out of here!",12,7,100,0,0,0,7325,0,"Theramore Sentry"),
(5184,1,0,"Run!",12,7,100,0,0,0,7324,0,"Theramore Sentry"),
(5184,1,1,"Get out of here!",12,7,100,0,0,0,7340,0,"Theramore Sentry"),
(5184,1,2,"Don't let them catch you!",12,7,100,0,0,0,7341,0,"Theramore Sentry"),
(5184,1,3,"She'll have our heads if we're caught!",12,7,100,0,0,0,7342,0,"Theramore Sentry");

-- Private Hendel
UPDATE `creature_template` SET `AIName`="SmartAI", `ScriptName`="" WHERE `entry`=4966;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4966 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (496600,496601) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4966,0,0,1,19,0,100,0,1324,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Remove Npc Flag Questgiver"),
(4966,0,1,2,61,0,100,0,0,0,0,0,0,42,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Set Invincibility at 1 HP"),
(4966,0,2,3,61,0,100,0,0,0,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Set Faction 168"),
(4966,0,3,4,61,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,11,5184,50,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Set Data 1 to Theramore Sentry"),
(4966,0,4,5,61,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Start Attacking"),
(4966,0,5,6,61,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Store Target"),
(4966,0,6,0,61,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Quest 'The Missing Diplomat (Part 16)' Taken - Set Event Phase 1"),
(4966,0,7,0,2,1,100,1,0,20,0,0,0,80,496600,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - Between 0-20% Health - Run Script 1 (Phase 1)"),
(4966,0,8,0,21,2,100,1,0,0,0,0,0,80,496601,2,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Reached Home - Run Script 2 (Phase 2)"),
(496600,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Script - Say Line 0"),
(496600,9,1,0,0,0,100,0,0,0,0,0,0,2,1077,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Faction 1077"),
(496600,9,2,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Script - Stop Combat"),
(496600,9,3,0,0,0,100,0,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Event Phase 2"),
(496601,9,0,0,0,0,100,0,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-2897.06,-3349.2,31.3004,0,"Private Hendel - On Script - Move to Position"),
(496601,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0.277231,"Private Hendel - On Script - Set Orientation"),
(496601,9,2,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Script - Say Line 1"),
(496601,9,3,0,0,0,100,0,0,0,0,0,0,17,64,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Script - Set Emote State 64"),
(496601,9,4,0,0,0,100,0,0,0,0,0,0,45,2,2,0,0,0,0,11,5184,50,0,0,0,0,0,"Private Hendel - On Script - Set Data 2 to Theramore Sentry"),
(496601,9,5,0,0,0,100,0,0,0,0,0,0,107,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Private Hendel - On Script - Summon Group"),
(496601,9,6,0,0,0,100,0,0,0,0,0,0,45,1,1,0,0,0,0,19,4967,0,0,0,0,0,0,"Private Hendel - On Script - Set Data to Archmage Tervosh"),
(496601,9,7,0,0,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,19,4967,0,0,0,0,0,0,"Private Hendel - On Script - Send Target to Archmage Tervosh");

DELETE FROM `creature_summon_groups` WHERE `summonerId`=4966;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES
(4966,0,1,4967,-2882.55,-3345.43,33.7722,3.39919,3,90000),
(4966,0,1,4968,-2880.52,-3346.80,34.5063,3.36777,3,90000),
(4966,0,1,4965,-2881.22,-3343.22,34.1732,3.52487,3,90000);

-- Theramore Sentry
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=5184;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-31271,-31268) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (518400,518401) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-31271,0,0,0,38,0,100,1,1,1,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Data 1 Set - Set Faction 168"),
(-31271,0,1,0,38,0,100,1,1,1,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Theramore Sentry - On Data 1 Set - Start Attacking"),
(-31271,0,2,0,38,0,100,1,2,2,0,0,0,80,518400,2,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Data 2 Set - Run Script"),
(-31271,0,3,0,40,0,100,0,2,518400,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Waypoint 2 Reahed - Despawn"),
(-31268,0,0,0,38,0,100,1,1,1,0,0,0,2,168,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Data Set - Set Faction 168"),
(-31268,0,1,0,38,0,100,1,1,1,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,"Theramore Sentry - On Data Set - Start Attacking"),
(-31268,0,2,0,38,0,100,1,2,2,0,0,0,80,518401,2,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Data 2 Set - Run Script"),
(-31268,0,3,0,40,0,100,0,3,518401,0,0,0,41,1000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Waypoint 3 Reahed - Despawn"),
(518400,9,0,0,0,0,100,0,1000,1000,0,0,0,2,150,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Set Faction 150"),
(518400,9,1,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Evade"),
(518400,9,2,0,0,0,100,0,0,0,0,0,0,53,1,518400,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Start Waypoint"),
(518400,9,3,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Say Line 0"),
(518401,9,0,0,0,0,100,0,1000,1000,0,0,0,2,150,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Set Faction 150"),
(518401,9,1,0,0,0,100,0,0,0,0,0,0,24,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Evade"),
(518401,9,2,0,0,0,100,0,0,0,0,0,0,53,1,518401,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Start Waypoint"),
(518401,9,3,0,0,0,100,0,1000,1000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Theramore Sentry - On Script - Say Line 1");

DELETE FROM `waypoints` WHERE `entry` IN (518400,518401);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(518400,1,-2906.15,-3345.12,31.3324,""),
(518400,2,-2910.64,-3353.77,30.4347,""),
(518401,1,-2897.26,-3330.35,33.442,""),
(518401,2,-2908.55,-3336.71,32.0493,""),
(518401,3,-2914.51,-3346.08,30.843,"");

-- Archmage Tervosh
DELETE FROM `smart_scripts` WHERE `entryorguid`=4967 AND `source_type`=0 AND `id` IN (0,4,5,6);
DELETE FROM `smart_scripts` WHERE `entryorguid`=496700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(4967,0,0,0,0,0,100,0,0,0,3000,5000,0,11,20822,64,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Tervosh - In Combat - Cast 'Frostbolt'"),
(4967,0,4,0,0,0,100,0,6000,8000,12000,14000,0,11,20823,0,0,0,0,0,2,0,0,0,0,0,0,0,"Archmage Tervosh - In Combat - Cast 'Fireball'"),
(4967,0,5,0,38,0,100,1,1,1,0,0,0,80,496700,2,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Data Set - Run Script"),
(496700,9,0,0,0,0,100,0,0,0,0,0,0,11,51347,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Script - Cast 'Teleport Visual Only'"),
(496700,9,1,0,0,0,100,0,0,0,0,0,0,86,51347,0,19,4965,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Script - Cross Cast 'Teleport Visual Only'"),
(496700,9,2,0,0,0,100,0,0,0,0,0,0,86,51347,0,19,4968,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Script - Cross Cast 'Teleport Visual Only'"),
(496700,9,3,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Script - Say Line 1"),
(496700,9,4,0,0,0,100,0,3000,3000,0,0,0,11,7081,0,0,0,0,0,19,4966,0,0,0,0,0,0,"Archmage Tervosh - On Script - Cast 'Encage'"),
(496700,9,5,0,0,0,100,0,4000,4000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Script - Say Line 2"),
(496700,9,6,0,0,0,100,0,5000,5000,0,0,0,1,2,0,0,0,0,0,19,4966,0,0,0,0,0,0,"Archmage Tervosh - On Script - Say Line 2 (Private Hendel)"),
(496700,9,7,0,0,0,100,0,3000,3000,0,0,0,11,7079,0,0,0,0,0,19,4966,0,0,0,0,0,0,"Archmage Tervosh - On Script - Cast 'Simple Teleport Other'"),
(496700,9,8,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,19,4966,0,0,0,0,0,0,"Archmage Tervosh - On Script - Despawn (Private Hendel)"),
(496700,9,9,0,0,0,100,0,2000,2000,0,0,0,15,1324,0,0,0,0,0,12,1,0,0,0,0,0,0,"Archmage Tervosh - On Script - Complete Quest 'The Missing Diplomat (Part 16)'"),
(496700,9,10,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Script - Say Line 2"),
(496700,9,11,0,0,0,100,0,6000,6000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Archmage Tervosh - On Script - Say Line 3");
