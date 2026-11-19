SET @GUID := 209102;
SET @NPC_HERENN := 28601;
SET @NPC_DEATHS_HAND_ACOLYTE := 28602;
SET @PATH := @NPC_DEATHS_HAND_ACOLYTE * 10;
SET @OMEGA_RUNE := 38708;

DELETE FROM `creature` WHERE `id` IN (@NPC_HERENN,@NPC_DEATHS_HAND_ACOLYTE);
-- add High Cultist Herenn (28601)
INSERT INTO `creature` (`guid`,`id`,`map`,`position_x`,`position_y`,`position_z`,`orientation`) VALUES
(@GUID+10,@NPC_HERENN,1,-6028.08,-1249.02,-146.7644,3.054326);

-- add Death's Hand Acolyte (28602), genders are random (25342,25343)
INSERT INTO `creature`(`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,  @NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6163.63,-1249.54,-159.7329,3.11264,120,0,0,1,0,2),   -- wandering
(@GUID+1,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6083.673,-1249.462,-143.4821,0.01435,120,0,0,1,0,2), -- wandering
(@GUID+2,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6037.476,-1243.375,-146.8277,5.98647,120,0,0,1,0,0), -- kneeled
(@GUID+3,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6036.1,-1255.38,-146.8277,1.15191,120,0,0,1,0,0),    -- kneeled
(@GUID+4,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6065.16,-1256.21,-143.3607,3.10668,120,0,0,1,0,0),
(@GUID+5,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6118.18,-1241.33,-143.281,3.12169,120,0,0,1,0,0),
(@GUID+6,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6104.965,-1243.601,-143.1921,3.12413,120,0,0,1,0,0),
(@GUID+7,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6065.27,-1242.8,-143.3297,3.14159,120,0,0,1,0,0),
(@GUID+8,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6104.698,-1256.314,-143.1921,3.05432,120,0,0,1,0,0),
(@GUID+9,@NPC_DEATHS_HAND_ACOLYTE,1,1,1,0,0,-6121.342,-1258.456,-143.1921,2.9147,120,0,0,1,0,0);

-- update creature_template Death's Hand Acolyte for equipment
UPDATE `creature_template` SET `equipment_id`=815 WHERE `entry`=@NPC_DEATHS_HAND_ACOLYTE;

-- set waypoint id's and visual effects
DELETE FROM `creature_addon` WHERE `guid` IN (@GUID,@GUID+1,@GUID+2,@GUID+3);
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(@GUID  ,@PATH,0,1,0,''),
(@GUID+1,@PATH+20,0,1,0,''),
(@GUID+2,0,8,0,0,''),       -- kneeling
(@GUID+3,0,8,0,0,'');       -- kneeling

-- pathing Death's Hand Acolyte #1
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-6167.854,-1249.36,-162.6509,0,0,0,100,0),
(@PATH,2,-6154.54,-1249.757,-155.4785,0,0,0,100,0),
(@PATH,3,-6141.45,-1249.3,-147.7103,0,0,0,100,0),
(@PATH,4,-6140.292,-1249.466,-147.2287,0,0,0,100,0),
(@PATH,5,-6138.544,-1249.176,-145.9789,0,0,0,100,0),
(@PATH,6,-6136.085,-1249.64,-143.2982,0,0,0,100,0),
(@PATH,7,-6120.995,-1250.048,-143.2961,0,0,0,100,0),
(@PATH,8,-6133.946,-1250.144,-143.3480,0,0,0,100,0);

-- pathing Death's Hand Acolyte #2
DELETE FROM `waypoint_data` WHERE `id`=@PATH+20;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH+20,1,-6063.011,-1249.407,-143.4293,0,0,0,100,0),
(@PATH+20,2,-6067.342,-1249.435,-143.2057,0,0,0,100,0),
(@PATH+20,3,-6081.293,-1249.456,-143.4746,0,0,0,100,0),
(@PATH+20,4,-6083.673,-1249.462,-143.4821,0,0,0,100,0),
(@PATH+20,5,-6091.368,-1249.619,-143.6254,0,0,0,100,0),
(@PATH+20,6,-6100.618,-1249.619,-143.3754,0,0,0,100,0),
(@PATH+20,7,-6105.942,-1249.782,-143.2761,0,0,0,100,0);

-- SAI for High Cultist Herenn, also add loot and equipment
UPDATE `creature_template` SET `AIName`='SmartAI',`equipment_id`=1803 WHERE `entry`=@NPC_HERENN;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@NPC_HERENN;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC_HERENN,0,0,0,0,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'High Cultist Herenn - in Combat - Say Text 0');

-- High Cultist Herenn talk text
DELETE FROM `creature_text` WHERE `entry`=@NPC_HERENN;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@NPC_HERENN,0,0,'Fool! You led us to the only being that could stand up to our armies! You will never bring the Etymidian back to Northrend!',12,0,100,25,0,0,'High Cultist Herenn');
