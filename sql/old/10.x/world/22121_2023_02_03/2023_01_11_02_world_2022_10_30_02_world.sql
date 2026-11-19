-- Remove SAI path
UPDATE `creature_template` SET `AIName`="", `ScriptName`='' WHERE `entry`=18947;
DELETE FROM `smart_scripts` WHERE `entryorguid`=18947 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (1894700,1894701) AND `source_type`=9;
DELETE FROM `waypoints` WHERE `entry`=18947;

-- Pathing for Solanin <Bag Vendor> Entry: 18947
SET @NPC := 68009;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=9309.143,`position_y`=-6555.4087,`position_z`=34.67163 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,9311.077,-6546.257,34.846924,NULL,6000,0,1078,100,0), -- Emote Kneel 16
(@PATH,2,9305.104,-6541.021,34.835205,NULL,6000,0,1078,100,0), -- Emote Kneel 16
(@PATH,3,9301.6,-6547.752,34.710205,NULL,0,0,0,100,0),
(@PATH,4,9300,-6554.6353,33.846703,NULL,12000,0,0,100,0),
(@PATH,5,9311.535,-6549.8223,34.948242,NULL,0,0,0,100,0),
(@PATH,6,9311.535,-6549.8223,34.948242,3.00197,14000,0,7,100,0), -- Text 0, Text 1
(@PATH,7,9309.143,-6555.4087,34.67163,NULL,0,0,0,100,0),
(@PATH,8,9309.143,-6555.4087,34.67163,2.49582,175000,0,0,100,0);
-- Path scripting for Solanin <Bag Vendor>
DELETE FROM `waypoint_scripts` WHERE `id`=7;
INSERT INTO `waypoint_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`guid`) VALUES
(7,1,0,0,0,16099,0,0,0,0,16), -- Text 0
(7,1,1,6,0,0,0,0,0,0,17), -- Emote 6
(7,7,0,0,0,16100,0,0,0,0,18), -- Text 1
(7,7,1,1,0,0,0,0,0,0,19); -- Emote 1
