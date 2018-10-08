-- Rigglefuzz
DELETE FROM `smart_scripts` WHERE `entryorguid`=2817 AND `source_type`=0 AND `id` IN (1,2,3);
DELETE FROM `smart_scripts` WHERE `entryorguid`=281701 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(2817,0,1,0,20,0,100,0,705,0,0,0,80,281701,2,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Quest 'Pearl Diving' Finished - Run Script"),
(2817,0,2,0,17,0,100,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,"Rigglefuzz - On Summoned Unit - Store Targetlist"),
(281701,9,0,0,0,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Remove Npc Flag Questgiver"),
(281701,9,1,0,0,0,100,0,0,0,0,0,2,121,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Faction 121"),
(281701,9,2,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 2"),
(281701,9,3,0,0,0,100,0,0,0,0,0,17,69,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Emote State 'Usestanding'"),
(281701,9,4,0,0,0,100,0,6000,6000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Emote State 'None'"),
(281701,9,5,0,0,0,100,0,0,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 3"),
(281701,9,6,0,0,0,100,0,1000,1000,0,0,12,2732,3,19000,0,0,0,8,0,0,0,-6823.6,-3140.42,255.654,0.152051,"Rigglefuzz - On Script - Summon Creature 'Ridge Huntress'"),
(281701,9,7,0,0,0,100,0,3000,3000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.59272,"Rigglefuzz - On Script - Set Orientation"),
(281701,9,8,0,0,0,100,0,0,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 4"),
(281701,9,9,0,0,0,100,0,5000,5000,0,0,11,5134,0,0,0,0,0,12,1,0,0,0,0,0,0,"Rigglefuzz - On Script - Cast 'Flash Bomb'"),
(281701,9,10,0,0,0,100,0,0,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 5"),
(281701,9,11,0,0,0,100,0,0,0,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Say Line 6"),
(281701,9,12,0,0,0,100,0,5000,5000,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Add Npc Flag Questgiver"),
(281701,9,13,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,5.20016,"Rigglefuzz - On Script - Set Orientation"),
(281701,9,14,0,0,0,100,0,0,0,0,0,2,120,0,0,0,0,0,1,0,0,0,0,0,0,0,"Rigglefuzz - On Script - Set Faction 120");

DELETE FROM `creature_text` WHERE `CreatureID`=2817 AND `GroupID` IN (2,3,4,5,6);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(2817,2,0,"%s grinds the pearls $n gave him...",16,0,100,0,0,0,1021,0,"Rigglefuzz"),
(2817,3,0,"There we are.  A new batch of flash bombs!",12,0,100,0,0,0,1023,0,"Rigglefuzz"),
(2817,4,0,"Look out!  We're under attack by a $n!",12,0,100,5,0,0,1022,0,"Rigglefuzz"),
(2817,5,0,"Take that, beast!",12,0,100,0,0,0,1024,0,"Rigglefuzz"),
(2817,6,0,"%s tosses dynamite through the air and it lands near by.",16,0,100,0,0,0,1025,0,"Rigglefuzz");

DELETE FROM `waypoints` WHERE `entry`=2732;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(2732,1,-6809.03,-3137.6,248.361,""),
(2732,2,-6791.57,-3140.57,240.744,""),
(2732,3,-6772.49,-3135.47,240.423,"");

-- Ridge Huntress
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=2732;
DELETE FROM `smart_scripts` WHERE `entryorguid`=2732 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2732,0,0,0,54,0,100,0,0,0,0,0,0,53,1,2732,0,0,0,0,1,0,0,0,0,0,0,0,"Ridge Huntress - Just Summoned - Start Waypoint"),
(2732,0,1,0,54,0,100,0,0,0,0,0,0,18,256,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ridge Huntress - Just Summoned - Add Unit Flag 'Immune to Player'");
