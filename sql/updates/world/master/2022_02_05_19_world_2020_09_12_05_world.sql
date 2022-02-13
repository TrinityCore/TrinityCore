--
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (7784,7806,7807));

-- Homing Robot OOX-17/TN SAI (Source: Sniffs)
SET @ID := 7784;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "", `flags_extra` = `flags_extra`|512 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Respawn - Set Flag Standstate Dead"),
(@ID,0,1,0,4,0,25,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Aggro - Say Line 1"),
(@ID,0,2,0,19,0,100,0,648,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Quest 'Rescue OOX-17/TN!' Taken - Run Script"),
(@ID,0,3,0,40,0,100,0,16,0,0,0,0,80,@ID*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Waypoint 16 Reached - Run Script"),
(@ID,0,4,0,1,1,100,0,500,500,500,500,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - Out of Combat - Run Script (Phase 1)"),
(@ID,0,5,0,40,0,100,0,19,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Waypoint 19 Reached - Despawn Instant"),
(@ID,0,6,0,6,0,100,0,0,0,0,0,0,6,648,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Death - Fail Quest 'Rescue OOX-17/TN!'"),
-- If quest is not sharable, it probably means credit will be not awarded to party members, do not store all guids
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,53,0,7784,0,0,0,2,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Start Waypoint"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Set Faction 113"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Remove Flag Immune To NPC's"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Remove Flag Standstate Dead"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Remove NPC Flag Questgiver"),
-- To be changed to 0 when WP pause issue will be fixed
(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Say Line 2"),
(@ID*100+1,9,2,0,0,0,100,0,1000,1000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Summon Group 0"),
-- This part is pretty tricky. Final actions are called after 20 sec (value from https://youtu.be/uiG-tnvsAJc?t=113     
-- and https://youtu.be/2zvTguAWo34?t=116 https://youtu.be/P3I2qClvKDQ?t=115)
-- The problem is timer can tick both in combat and OOC but the actions are called only while OOC
-- and not after killing summoned creatures (check videos, in two of them they even didn't spawned)
-- Currently we set phase to 1 here and in phase 1 we are trying to call action list every 500 ms
-- Once action list is called, we set phase to 0 to prevent double call
-- All other ways are way much more ugly or does not work like this one
-- Ideally we need to call ONE action list with update type 2 (in combat and out of combat) to allow timer tick in combat too
-- And call half of actions after 20 sec only if creature is not in combat
(@ID*100+1,9,3,0,0,0,100,0,20000,20000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Set Event Phase 1"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Set Event Phase 1"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Say Line 3"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Set Run On"),
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Set Active"),
(@ID*100+2,9,4,0,0,0,100,0,1000,1000,0,0,0,11,68499,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Cast 'OOX Lift Off'"),
(@ID*100+2,9,5,0,0,0,100,0,0,0,0,0,0,15,648,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Quest Credit 'Rescue OOX-17/TN!'"),
(@ID*100+2,9,6,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Add Flag Immune To NPC's"),
(@ID*100+2,9,7,0,0,0,100,0,2000,2000,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Set Fly On"),
(@ID*100+2,9,8,0,0,0,100,0,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-17/TN - On Script - Resume Waypoint");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = @ID AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(@ID,0,0,7803,-8343.939,-4444.1963,9.410067,4.06661,4,60000,"Homing Robot OOX-17/TN - Group 0 - Scorpid Duneburrower"),
(@ID,0,0,7803,-8342.946,-4454.9834,9.538595,2.18166,4,60000,"Homing Robot OOX-17/TN - Group 0 - Scorpid Duneburrower"),
(@ID,0,0,7803,-8356.769,-4448.491,10.246145,6.21337,4,60000,"Homing Robot OOX-17/TN - Group 0 - Scorpid Duneburrower");

DELETE FROM `script_waypoint` WHERE `entry` = 7784;
DELETE FROM `waypoints` WHERE `entry` = 7784;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(7784,1,-8810.634,-4373.8345,32.58877,"Homing Robot OOX-17/TN"),
(7784,2,-8794.969,-4366.311,26.136408,"Homing Robot OOX-17/TN"),
(7784,3,-8752.488,-4366.4326,24.101122,"Homing Robot OOX-17/TN"),
(7784,4,-8724.97,-4352.2266,20.744633,"Homing Robot OOX-17/TN"),
(7784,5,-8708.822,-4353.277,18.369633,"Homing Robot OOX-17/TN"),
(7784,6,-8684.997,-4379.1943,13.567807,"Homing Robot OOX-17/TN"),
(7784,7,-8656.829,-4388.013,12.275239,"Homing Robot OOX-17/TN"),
(7784,8,-8612.755,-4397.2524,9.712765,"Homing Robot OOX-17/TN"),
(7784,9,-8578.566,-4408.652,11.488994,"Homing Robot OOX-17/TN"),
(7784,10,-8539.096,-4421.452,12.616913,"Homing Robot OOX-17/TN"),
(7784,11,-8514.029,-4425.8203,13.824177,"Homing Robot OOX-17/TN"),
(7784,12,-8486.308,-4428.784,11.637026,"Homing Robot OOX-17/TN"),
(7784,13,-8446.95,-4440.7183,9.385215,"Homing Robot OOX-17/TN"),
(7784,14,-8417.598,-4445.191,10.385215,"Homing Robot OOX-17/TN"),
(7784,15,-8388.8955,-4448.0015,10.996256,"Homing Robot OOX-17/TN"),
(7784,16,-8352.005,-4447.594,10.134734,"Homing Robot OOX-17/TN"), --
(7784,17,-8327.56,-4442.5103,18.585197,"Homing Robot OOX-17/TN"),
(7784,18,-8262.676,-4426.0054,34.8352,"Homing Robot OOX-17/TN"),
(7784,19,-8161.7275,-4410.5435,58.08519,"Homing Robot OOX-17/TN"); -- No despawn packet, probably incomplete

UPDATE `creature_text` SET `comment` = "Homing Robot OOX-17/TN" WHERE `CreatureID` = 7784;

-- Scorpid Duneburrower SAI (Source: ACID 4.0.3 Official Data)
SET @ID := 7803;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Scorpid Duneburrower - On Just Summoned - Start Attacking Closest Player"),
(@ID,0,1,0,0,0,100,0,6400,14700,20900,45800,0,11,5416,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Scorpid Duneburrower - In Combat - Cast 'Venom Sting'");

-- Homing Robot OOX-09/HL SAI (Source: Homing Robot OOX-17/TN & https://www.youtube.com/watch?v=6nhntDjHhc8)
SET @ID := 7806;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "", `flags_extra` = `flags_extra`|512 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Respawn - Set Flag Standstate Dead"),
(@ID,0,1,0,4,0,25,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Aggro - Say Line 1"),
(@ID,0,2,0,19,0,100,0,836,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Quest 'Rescue OOX-09/HL!' Taken - Run Script"),
(@ID,0,3,0,40,0,100,0,27,0,0,0,0,80,@ID*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Waypoint 27 Reached - Run Script"),
(@ID,0,4,0,1,1,100,0,500,500,500,500,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - Out of Combat - Run Script (Phase 1)"),
(@ID,0,5,0,40,0,100,0,30,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Waypoint 30 Reached - Despawn Instant"),
(@ID,0,6,0,6,0,100,0,0,0,0,0,0,6,836,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Death - Fail Quest 'Rescue OOX-09/HL!'"),
-- If quest is not sharable, it probably means credit will be not awarded to party members, do not store all guids
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,53,0,7806,0,0,0,2,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Start Waypoint"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Set Faction 113"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Remove Flag Immune To NPC's"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Remove Flag Standstate Dead"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Remove NPC Flag Questgiver"),
-- To be changed to 0 when WP pause issue will be fixed
(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Say Line 2"),
(@ID*100+1,9,2,0,0,0,100,0,1000,1000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Summon Group 0"),
(@ID*100+1,9,3,0,0,0,100,0,20000,20000,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Set Event Phase 1"),

(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Set Event Phase 1"),
(@ID*100+2,9,1,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Say Line 3"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Set Run On"),
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Set Active"),
(@ID*100+2,9,4,0,0,0,100,0,1000,1000,0,0,0,11,68499,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Cast 'OOX Lift Off'"),
(@ID*100+2,9,5,0,0,0,100,0,0,0,0,0,0,15,836,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Quest Credit 'Rescue OOX-09/HL!'"),
(@ID*100+2,9,6,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Add Flag Immune To NPC's"),
(@ID*100+2,9,7,0,0,0,100,0,2000,2000,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Set Fly On"),
(@ID*100+2,9,8,0,0,0,100,0,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-09/HL - On Script - Resume Waypoint");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = @ID AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(@ID,0,0,7808,186.032150,-3820.854492,131.839096,1.997256,4,60000,"Homing Robot OOX-09/HL - Group 0 - Marauding Owlbeast"),
(@ID,0,0,7808,183.976471,-3825.723389,131.506836,1.961913,4,60000,"Homing Robot OOX-09/HL - Group 0 - Marauding Owlbeast"),
(@ID,0,0,7808,183.759094,-3820.448730,131.293335,2.197530,4,60000,"Homing Robot OOX-09/HL - Group 0 - Marauding Owlbeast");

DELETE FROM `script_waypoint` WHERE `entry` = 7806;
DELETE FROM `waypoints` WHERE `entry` = 7806;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(7806,1,495.404,-3478.35,114.837,"Homing Robot OOX-09/HL"),
(7806,2,492.705,-3486.11,108.627,"Homing Robot OOX-09/HL"),
(7806,3,487.25,-3485.76,107.89,"Homing Robot OOX-09/HL"),
(7806,4,476.852,-3489.88,99.985,"Homing Robot OOX-09/HL"),
(7806,5,467.212,-3493.36,99.819,"Homing Robot OOX-09/HL"),
(7806,6,460.017,-3496.98,104.481,"Homing Robot OOX-09/HL"),
(7806,7,439.619,-3500.73,110.534,"Homing Robot OOX-09/HL"),
(7806,8,428.326,-3495.87,118.662,"Homing Robot OOX-09/HL"),
(7806,9,424.664,-3489.38,121.999,"Homing Robot OOX-09/HL"),
(7806,10,424.137,-3470.95,124.333,"Homing Robot OOX-09/HL"),
(7806,11,421.791,-3449.24,119.126,"Homing Robot OOX-09/HL"),
(7806,12,404.247,-3429.38,117.644,"Homing Robot OOX-09/HL"),
(7806,13,335.465,-3430.72,116.456,"Homing Robot OOX-09/HL"),
(7806,14,317.16,-3426.71,116.226,"Homing Robot OOX-09/HL"),
(7806,15,331.18,-3464,117.143,"Homing Robot OOX-09/HL"),
(7806,16,336.394,-3501.88,118.201,"Homing Robot OOX-09/HL"),
(7806,17,337.251,-3544.76,117.284,"Homing Robot OOX-09/HL"),
(7806,18,337.749,-3565.42,116.797,"Homing Robot OOX-09/HL"),
(7806,19,336.011,-3597.36,118.225,"Homing Robot OOX-09/HL"),
(7806,20,324.619,-3622.88,119.811,"Homing Robot OOX-09/HL"),
(7806,21,308.027,-3648.6,123.047,"Homing Robot OOX-09/HL"),
(7806,22,276.325,-3685.74,128.356,"Homing Robot OOX-09/HL"),
(7806,23,239.981,-3717.33,131.874,"Homing Robot OOX-09/HL"),
(7806,24,224.951,-3730.17,132.125,"Homing Robot OOX-09/HL"),
(7806,25,198.708,-3768.29,129.42,"Homing Robot OOX-09/HL"),
(7806,26,183.758,-3791.07,128.045,"Homing Robot OOX-09/HL"),
(7806,27,178.111,-3801.58,128.37,"Homing Robot OOX-09/HL"),
(7806,28,149.076660,-3855.435791,144.834961,"Homing Robot OOX-09/HL"),
(7806,29,121.005402,-3906.975342,155.940018,"Homing Robot OOX-09/HL"),
(7806,30,96.769798,-3951.472656,165.527695,"Homing Robot OOX-09/HL");

UPDATE `creature_text` SET `comment` = "Homing Robot OOX-09/HL" WHERE `CreatureID` = 7806;
UPDATE `creature_text` SET `BroadcastTextId` = 3819 WHERE `CreatureID` = 7806 AND `GroupID` = 0 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 3821 WHERE `CreatureID` = 7806 AND `GroupID` = 2 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 3820, `Text` = "Flight systems online!  CLUCK!  Engaging rockets for transport to Booty Bay!" WHERE `CreatureID` = 7806 AND `GroupID` = 3 AND `ID` = 0;
DELETE FROM `creature_text` WHERE `CreatureID` = 7806 AND `GroupID` = 4 AND `ID` = 0;

-- Marauding Owlbeast SAI (Source: https://www.youtube.com/watch?v=6nhntDjHhc8)
SET @ID := 7808;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Marauding Owlbeast - On Just Summoned - Start Attacking Closest Player"),
(@ID,0,1,2,2,0,100,1,0,50,0,0,0,11,8599,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Marauding Owlbeast - Between 0-50% Health - Cast 'Enrage' (No Repeat)"),
(@ID,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Marauding Owlbeast - On Link - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = @ID;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(@ID,0,0,"%s goes into a frenzy!",16,0,100,0,0,0,1191,0,"Marauding Owlbeast");

-- Homing Robot OOX-22/FE SAI (Source: Homing Robot OOX-17/TN & https://www.youtube.com/watch?v=97CIQ81Y_0M & https://www.youtube.com/watch?v=6nhntDjHhc8)
-- This one is sligthly different from previous two
SET @ID := 7807;
UPDATE `creature_template` SET `AIName` = "SmartAI", `ScriptName` = "", `flags_extra` = `flags_extra`|512 WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN @ID*100+0 AND @ID*100+2 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,11,0,100,0,0,0,0,0,0,90,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Respawn - Set Flag Standstate Dead"),
(@ID,0,1,0,4,0,25,0,0,0,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Aggro - Say Line 1"),
(@ID,0,2,0,19,0,100,0,2767,0,0,0,0,80,@ID*100+0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Quest 'Rescue OOX-22/FE!' Taken - Run Script"),
(@ID,0,3,0,40,0,100,0,15,0,0,0,0,80,@ID*100+1,2,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Waypoint 15 Reached - Run Script"),
(@ID,0,4,0,40,0,100,0,16,0,0,0,0,80,@ID*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Waypoint 16 Reached - Run Script"),
(@ID,0,5,0,40,0,100,0,19,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Waypoint 19 Reached - Despawn Instant"),
(@ID,0,6,0,6,0,100,0,0,0,0,0,0,6,2767,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Death - Fail Quest 'Rescue OOX-22/FE!'"),
-- If quest is not sharable, it probably means credit will be not awarded to party members, do not store all guids
(@ID*100+0,9,0,0,0,0,100,0,0,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Store Targetlist"),
(@ID*100+0,9,1,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Say Line 0"),
(@ID*100+0,9,2,0,0,0,100,0,0,0,0,0,0,53,0,7807,0,0,0,2,1,0,0,0,0,0,0,0,0,"Ranger Lilatha - On Script - Start Waypoint"),
(@ID*100+0,9,3,0,0,0,100,0,0,0,0,0,0,2,113,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Set Faction 113"),
(@ID*100+0,9,4,0,0,0,100,0,0,0,0,0,0,19,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Remove Flag Immune To NPC's"),
(@ID*100+0,9,5,0,0,0,100,0,0,0,0,0,0,91,7,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Remove Flag Standstate Dead"),
(@ID*100+0,9,6,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Remove NPC Flag Questgiver"),
-- To be changed to 0 when WP pause issue will be fixed
(@ID*100+1,9,0,0,0,0,100,0,0,0,0,0,0,54,30000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Pause Waypoint"),
(@ID*100+1,9,1,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Say Line 2"),
(@ID*100+1,9,2,0,0,0,100,0,1000,1000,0,0,0,107,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Summon Group 0"),
(@ID*100+1,9,3,0,0,0,100,0,20000,20000,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Resume Waypoint"),
-- To be changed to 0 when WP pause issue will be fixed
(@ID*100+2,9,0,0,0,0,100,0,0,0,0,0,0,54,20000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Pause Waypoint"),
(@ID*100+2,9,1,0,0,0,100,0,1000,1000,0,0,0,1,3,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Say Line 3"),
(@ID*100+2,9,2,0,0,0,100,0,0,0,0,0,0,59,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Set Run On"),
(@ID*100+2,9,3,0,0,0,100,0,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Set Active"),
(@ID*100+2,9,4,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.49775,"Homing Robot OOX-22/FE - On Script - Set Orientation"),
(@ID*100+2,9,5,0,0,0,100,0,0,0,0,0,0,11,68499,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Cast 'OOX Lift Off'"),
(@ID*100+2,9,6,0,0,0,100,0,0,0,0,0,0,15,2767,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Quest Credit 'Rescue OOX-22/FE!'"),
(@ID*100+2,9,7,0,0,0,100,0,0,0,0,0,0,18,512,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Add Flag Immune To NPC's"),
(@ID*100+2,9,8,0,0,0,100,0,2000,2000,0,0,0,60,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Set Fly On"),
(@ID*100+2,9,9,0,0,0,100,0,0,0,0,0,0,65,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Homing Robot OOX-22/FE - On Script - Resume Waypoint");

DELETE FROM `creature_summon_groups` WHERE `summonerId` = @ID AND `summonerType` = 0;
INSERT INTO `creature_summon_groups` (`summonerId`,`summonerType`,`groupId`,`entry`,`position_x`,`position_y`,`position_z`,`orientation`,`summonType`,`summonTime`,`Comment`) VALUES
(@ID,0,0,7848,-4773.208008,1578.041870,86.939781,3.471461,4,60000,"Homing Robot OOX-22/FE - Group 0 - Lurking Feral Scar"),
(@ID,0,0,7848,-4775.565430,1582.444702,86.232521,3.874370,4,60000,"Homing Robot OOX-22/FE - Group 0 - Lurking Feral Scar");

DELETE FROM `script_waypoint` WHERE `entry` = 7807;
DELETE FROM `waypoints` WHERE `entry` = 7807;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(7807,1,-4943.74,1715.74,62.74,"Homing Robot OOX-22/FE"),
(7807,2,-4944.93,1706.66,63.16,"Homing Robot OOX-22/FE"),
(7807,3,-4942.82,1690.22,64.25,"Homing Robot OOX-22/FE"),
(7807,4,-4946.47,1669.62,63.84,"Homing Robot OOX-22/FE"),
(7807,5,-4955.93,1651.88,63,"Homing Robot OOX-22/FE"),
(7807,6,-4967.58,1643.86,64.31,"Homing Robot OOX-22/FE"),
(7807,7,-4978.12,1607.9,64.3,"Homing Robot OOX-22/FE"),
(7807,8,-4975.38,1596.16,64.7,"Homing Robot OOX-22/FE"),
(7807,9,-4972.82,1581.89,61.75,"Homing Robot OOX-22/FE"),
(7807,10,-4958.65,1581.05,61.81,"Homing Robot OOX-22/FE"),
(7807,11,-4936.72,1594.89,65.96,"Homing Robot OOX-22/FE"),
(7807,12,-4885.69,1598.1,67.45,"Homing Robot OOX-22/FE"),
(7807,13,-4874.2,1601.73,68.54,"Homing Robot OOX-22/FE"),
(7807,14,-4816.64,1594.47,78.2,"Homing Robot OOX-22/FE"),
(7807,15,-4802.2,1571.92,87.01,"Homing Robot OOX-22/FE"),
(7807,16,-4746.4,1576.11,84.59,"Homing Robot OOX-22/FE"),
(7807,17,-4746.320801,1624.022339,98.728851,"Homing Robot OOX-22/FE"),
(7807,18,-4743.309082,1665.165527,108.609444,"Homing Robot OOX-22/FE"),
(7807,19,-4743.872070,1744.252808,121.255127,"Homing Robot OOX-22/FE");

UPDATE `creature_text` SET `comment` = "Homing Robot OOX-22/FE" WHERE `CreatureID` = 7807;
UPDATE `creature_text` SET `BroadcastTextId` = 3824 WHERE `CreatureID` = 7807 AND `GroupID` = 0 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 3822 WHERE `CreatureID` = 7807 AND `GroupID` = 2 AND `ID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 3823 WHERE `CreatureID` = 7807 AND `GroupID` = 3 AND `ID` = 0;

-- Lurking Feral Scar SAI (Source: https://www.youtube.com/watch?v=97CIQ81Y_0M & https://www.youtube.com/watch?v=6nhntDjHhc8)
SET @ID := 7848;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = @ID;
DELETE FROM `smart_scripts` WHERE `entryorguid` = @ID AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ID,0,0,0,54,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,21,50,0,0,0,0,0,0,0,"Lurking Feral Scar - On Just Summoned - Start Attacking Closest Player");
