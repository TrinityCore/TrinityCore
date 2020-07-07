-- Kaya Flathoof SAI (https://www.youtube.com/watch?v=axY4vXGm7Q4)
SET @ID := 11856;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11910 AND `source_type` = 0 AND `id` = 1;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11912 AND `source_type` = 0 AND `id` = 2;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 11913 AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,19,0,100,0,6523,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Quest 'Protect Kaya' Taken - Run Script"),
(@ID,0,1,0,40,0,100,0,17,0,0,0,0,80,@ID*100+1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Waypoint 17 Reached - Run Script"),
(@ID,0,2,0,40,0,100,0,19,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Waypoint 19 Reached - Run Script"),
(@ID,0,3,0,6,0,100,0,0,0,0,0,0,6,6523,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kaya Flathoof - On Death - Fail Quest 'Protect Kaya'"),

(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Remove NPC Flag Questgiver"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Say Line 0"),
(@ID*100+0,9,3,0,0,0,100,0,5000,5000,0,0,0,53,0,11856,0,0,0,2,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Start Waypoint"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Remove Flag Immune To NPC's"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Set Faction 113"),

(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,7000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Pause Waypoint"),
-- She should not be attacked instantly, probably it's done by another way
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Add Flag Immune To NPC's"),
(@ID*100+1,9,2,0,0,0,100,0,2000,2000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Summon Group 0"),
(@ID*100+1,9,3,0,0,0,100,0,2000,2000,0,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Say Line 1"),
(@ID*100+1,9,4,0,0,0,100,0,3000,3000,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Remove Flag Immune To NPC's"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,1000,1000,0,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Set Orientation Stored Target 1"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Say Line 2"),
(@ID*100+2,9,3,0,0,0,100,0,5000,5000,0,0,0,26,6523,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Quest Credit 'Protect Kaya'"),
(@ID*100+2,9,4,0,0,0,100,0,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kaya Flathoof - On Script - Despawn (0)"),

(11910,0,1,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,0,"Grimtotem Ruffian - On Just Summoned - Start Attacking Closest Player"),
(11912,0,2,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,0,"Grimtotem Brute - On Just Summoned - Start Attacking Closest Player"),
(11913,0,3,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,30,0,0,0,0,0,0,0,"Grimtotem Sorcerer - On Just Summoned - Start Attacking Closest Player");

UPDATE `creature_text` SET `comment` = "Kaya Flathoof" WHERE `CreatureID` = @ID;

DELETE FROM `creature_summon_groups` WHERE `summonerId` = @ID;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(@ID,0,0,11910,-50.75,-500.77,-46.13,0.4,4,60000,"Kaya Flathoof - Group 0 - Grimtotem Ruffian"),
(@ID,0,0,11912,-40.05,-510.89,-46.05,1.7,4,60000,"Kaya Flathoof - Group 0 - Grimtotem Brute"),
(@ID,0,0,11913,-32.21,-499.20,-45.35,2.8,4,60000,"Kaya Flathoof - Group 0 - Grimtotem Sorcerer");

DELETE FROM `script_waypoint` WHERE `entry` = 11856;
DELETE FROM `waypoints` WHERE `entry` = 11856;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(11856,1,113.91,-350.13,4.55,"Kaya Flathoof"),
(11856,2,109.54,-350.08,3.74,"Kaya Flathoof"),
(11856,3,106.95,-353.4,3.6,"Kaya Flathoof"),
(11856,4,100.28,-338.89,2.97,"Kaya Flathoof"),
(11856,5,110.11,-320.26,3.47,"Kaya Flathoof"),
(11856,6,109.78,-287.8,5.3,"Kaya Flathoof"),
(11856,7,105.02,-269.71,4.71,"Kaya Flathoof"),
(11856,8,86.71,-251.81,5.34,"Kaya Flathoof"),
(11856,9,64.1,-246.38,5.91,"Kaya Flathoof"),
(11856,10,-2.55,-243.58,6.3,"Kaya Flathoof"),
(11856,11,-27.78,-267.53,-1.08,"Kaya Flathoof"),
(11856,12,-31.27,-283.54,-4.36,"Kaya Flathoof"),
(11856,13,-28.96,-322.44,-9.19,"Kaya Flathoof"),
(11856,14,-35.63,-360.03,-16.59,"Kaya Flathoof"),
(11856,15,-58.3,-412.26,-30.6,"Kaya Flathoof"),
(11856,16,-58.88,-474.17,-44.54,"Kaya Flathoof"),
(11856,17,-45.92,-496.57,-46.26,"Kaya Flathoof"),
(11856,18,-40.25,-510.07,-46.05,"Kaya Flathoof"),
(11856,19,-38.88,-520.72,-46.06,"Kaya Flathoof");
