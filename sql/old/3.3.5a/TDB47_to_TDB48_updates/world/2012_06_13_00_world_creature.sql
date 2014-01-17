-- Pathing for Violetta (32720)
SET @NPC    := 32720;
SET @GUID   := 12402;
DELETE FROM `creature` WHERE `guid`=@GUID;
DELETE FROM `creature` WHERE `id`=@NPC;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)
VALUES (@GUID,@NPC,571,1,1,0,0,5693.527,680.9248,645.9013,4.681826,300,0,0,1,0,0,0,0,0);
DELETE FROM `creature_template_addon` WHERE `entry`=@NPC;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@NPC,0,0,0,1,0,'');
-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@NPC AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC*100+0,@NPC*100+1,@NPC*100+2,@NPC*100+3) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,1,25,0,100,0,0,0,0,0,71,1670,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On reset - Equip default"),
(@NPC,0,1,0,61,0,100,0,0,0,0,0,88,@NPC*100+0,@NPC*100+1,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On reset - Run random script"),
(@NPC,0,2,0,40,1,100,0,8,0,0,0,80,@NPC*100+2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On wp8 - Run script"),
(@NPC,0,3,0,40,2,100,0,8,0,0,0,80,@NPC*100+3,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On wp8 - Run script"),
(@NPC,0,4,0,58,0,100,0,0,0,0,0,41,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On wp end - Despawn"),
(@NPC*100+0,9,0,0,0,0,100,0,0,0,0,0,53,0,@NPC*10+0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script 1 - Start waypoint 1"),
(@NPC*100+0,9,1,0,0,0,100,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script 1 - Set phase 1"),
(@NPC*100+1,9,0,0,0,0,100,0,0,0,0,0,53,0,@NPC*10+1,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script 2 - Start waypoint 2"),
(@NPC*100+1,9,1,0,0,0,100,0,0,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script 2 - Set phase 2"),
(@NPC*100+2,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script - Pause WP 10 seconds"),
(@NPC*100+2,9,1,0,0,0,100,0,5000,5000,5000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script - Emote talk"),
(@NPC*100+2,9,2,0,0,0,100,0,3000,3000,3000,3000,71,0,0,44655,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script - Equip item"),
(@NPC*100+3,9,0,0,0,0,100,0,0,0,0,0,54,10000,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script - Pause WP 10 seconds"),
(@NPC*100+3,9,1,0,0,0,100,0,5000,5000,5000,5000,5,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script - Emote talk"),
(@NPC*100+3,9,2,0,0,0,100,0,3000,3000,3000,3000,71,0,0,40020,0,0,0,1,0,0,0,0,0,0,0,"Violetta - On script - Equip item");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry` IN (@NPC*10+0,@NPC*10+1);
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@NPC*10+0,1,5693.35,675.1416,645.6994,'Violetta wp1'),
(@NPC*10+0,2,5690.851,664.07,646.2488,'Violetta wp1'),
(@NPC*10+0,3,5686.851,656.5425,646.5913,'Violetta wp1'),
(@NPC*10+0,4,5679.384,648.7989,646.6834,'Violetta wp1'),
(@NPC*10+0,5,5675.498,647.6321,647.0242,'Violetta wp1'),
(@NPC*10+0,6,5669.809,645.4785,647.9725,'Violetta wp1'),
(@NPC*10+0,7,5664.492,643.8845,647.98,'Violetta wp1'),
(@NPC*10+0,8,5664.87,642.0466,647.98,'Violetta wp1'),
(@NPC*10+0,9,5669.127,645.5728,647.9717,'Violetta wp1'),
(@NPC*10+0,10,5675.875,647.3784,647.0391,'Violetta wp1'),
(@NPC*10+0,11,5681.011,648.9694,646.6834,'Violetta wp1'),
(@NPC*10+0,12,5683.774,658.9824,646.6004,'Violetta wp1'),
(@NPC*10+0,13,5682.824,671.3663,647.0424,'Violetta wp1'),
(@NPC*10+0,14,5677.113,674.4891,649.4763,'Violetta wp1'),
(@NPC*10+0,15,5667.89,677.9095,652.0448,'Violetta wp1'),
(@NPC*10+0,16,5655.117,684.3335,651.9886,'Violetta wp1'),
(@NPC*10+0,17,5649.896,690.4983,651.9928,'Violetta wp1'),
(@NPC*10+0,18,5646.092,697.507,651.9928,'Violetta wp1'),
(@NPC*10+0,19,5646.725,700.2504,651.9928,'Violetta wp1'),
(@NPC*10+1,1,5693.35,675.1416,645.6994,'Violetta wp2'),
(@NPC*10+1,2,5690.851,664.07,646.2488,'Violetta wp2'),
(@NPC*10+1,3,5686.851,656.5425,646.5913,'Violetta wp2'),
(@NPC*10+1,4,5679.384,648.7989,646.6834,'Violetta wp2'),
(@NPC*10+1,5,5675.498,647.6321,647.0242,'Violetta wp2'),
(@NPC*10+1,6,5669.809,645.4785,647.9725,'Violetta wp2'),
(@NPC*10+1,7,5664.369,644.7076,647.9811,'Violetta wp2'),
(@NPC*10+1,8,5661.005,643.9919,647.9821,'Violetta wp2'),
(@NPC*10+1,9,5669.143,645.5861,647.9418,'Violetta wp2'),
(@NPC*10+1,10,5675.875,647.3784,647.0391,'Violetta wp2'),
(@NPC*10+1,11,5681.011,648.9694,646.6834,'Violetta wp2'),
(@NPC*10+1,12,5683.774,658.9824,646.6004,'Violetta wp2'),
(@NPC*10+1,13,5682.824,671.3663,647.0424,'Violetta wp2'),
(@NPC*10+1,14,5677.113,674.4891,649.4763,'Violetta wp2'),
(@NPC*10+1,15,5667.89,677.9095,652.0448,'Violetta wp2'),
(@NPC*10+1,16,5655.117,684.3335,651.9886,'Violetta wp2'),
(@NPC*10+1,17,5649.896,690.4983,651.9928,'Violetta wp2'),
(@NPC*10+1,18,5646.092,697.507,651.9928,'Violetta wp2'),
(@NPC*10+1,19,5646.725,700.2504,651.9928,'Violetta wp2');
