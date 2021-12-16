-- Crusader Rhydalla SAI (Source: Sniffs)
SET @ID := 33417;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID*100+0 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,20,0,100,0,13641,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Rhydalla - On Quest 'The Seer's Crystal' Finished - Run Script"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Crusader Rhydalla - On Script - Say Line 0"),
(@ID*100+0,9,1,0,0,0,100,0,5000,5000,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Crusader Rhydalla - On Script - Say Line 1"),
(@ID*100+0,9,2,0,0,0,100,0,3000,3000,0,0,0,5,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Rhydalla - On Script - Play Emote 25"),
(@ID*100+0,9,3,0,0,0,100,0,2000,2000,0,0,0,11,62993,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Crusader Rhydalla - On Script - Cast 'Imbue'");

-- Corki (sniffed)
UPDATE `smart_scripts` SET `comment` = "Corki - On Data Set 1 1 - Run Script" WHERE `entryorguid` = 20812 AND `source_type` = 0 AND `id` = 0;
UPDATE `creature_text` SET `Emote` = 1, `comment` = "Corki" WHERE `CreatureID` = 20812 AND `GroupID` = 0;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 20812 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2081200 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20812,0,1,0,40,0,100,0,3,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Corki - On Waypoint 3 Reached - Despawn Instant"),

(2081200,9,0,0,0,0,100,0,0,0,0,0,0,33,20812,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Corki - On Script - Quest Credit 'Corki's Gone Missing Again!'"),
(2081200,9,1,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Corki - On Script - Remove NPC Flag Gossip"),
(2081200,9,2,0,0,0,100,0,1500,1500,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Corki - On Script - Say Line 0"),
(2081200,9,3,0,0,0,100,0,3500,3500,0,0,0,53,1,20812,0,0,0,2,1,0,0,0,0,0,0,0,0,"Corki - On Script - Start Waypoint");

-- May be incomplete, no despawn packet
DELETE FROM `waypoints` WHERE `entry` = 20812;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`point_comment`) VALUES
(20812,1,-983.2487,8119.262,-95.248436,0,0,"Corki"),
(20812,2,-998.8075,8115.3135,-95.95265,0,0,"Corki"),
(20812,3,-1013.5875,8113.922,-94.19407,0,0,"Corki");
