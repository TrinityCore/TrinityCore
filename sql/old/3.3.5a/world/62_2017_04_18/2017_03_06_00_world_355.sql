-- 
DELETE FROM `creature` WHERE `guid`=74033;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(74033, 10820, 0, 0, 0, 1, 1, 0, 1, 3285.289, -3379.695, 142.0929, 3.24509, 72000, 0, 0, 0, 0, 2, 0, 0, 0, 0);

SET @NPC := 74033;
SET @PATH := @NPC * 10;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,3285.289,-3379.695,142.0929,0,0,0,0,100,0),
(@PATH,2,3313.754,-3380.01,145.006,0,0,0,0,100,0),
(@PATH,3,3346.585,-3379.945,144.845,0,0,0,0,100,0),
(@PATH,4,3359.656,-3382.519,144.781,0,0,0,0,100,0),
(@PATH,5,3362.254,-3418.576,142.2686,0,0,0,0,100,0),
(@PATH,6,3387.635,-3420.767,142.2722,0,0,0,0,100,0),
(@PATH,7,3393.317,-3403.628,142.2489,0,0,0,0,100,0),
(@PATH,8,3392.779,-3354.851,142.2589,0,0,0,0,100,0),
(@PATH,9,3388.798,-3338.297,142.2719,0,0,0,0,100,0),
(@PATH,10,3371.812,-3338.535,142.272,0,0,0,0,100,0),
(@PATH,11,3361.786,-3350.167,142.2497,0,0,0,0,100,0),
(@PATH,12,3361.198,-3365.571,144.6385,0,0,0,0,100,0),
(@PATH,13,3354.42,-3379.488,144.8066,0,0,0,0,100,0),
(@PATH,14,3339.823,-3379.752,144.8782,0,0,0,0,100,0),
(@PATH,15,3322.654,-3379.821,144.9624,0,0,0,0,100,0),
(@PATH,16,3306.767,-3379.837,144.8372,0,0,0,0,100,0);
-- 0x203B0C00000A910000001600003C614C .go 3285.289 -3379.695 142.0929

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10820;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10820 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(10820, 0, 0, 0, 0, 0, 100, 0, 2000, 4000, 5000, 9000, 11, 12471, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Duke Ragereaver - IC - cast Shadow Bolt"),
(10820, 0, 1, 0, 0, 0, 100, 0, 3000, 6000, 21000, 25000, 11, 13847, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Duke Ragereaver - IC - cast recklessness"),
(10820, 0, 2, 0, 23, 0, 100, 0, 11733, 0, 0, 0, 11, 11733, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Duke Ragereaver - on missing aura - cast demon armor");
