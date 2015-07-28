-- Add SAI line to Inspector Tarem
SET @TAREM := 23567;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@TAREM AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@TAREM,0,2,0,1,0,100,0,60000,70000,60000,70000,1,0,0,0,0,0,0,11,9079,10,0,0,0,0,0, 'Inspector Tarem -  OOC - Say 0');

-- Text for Inspector Tarem
DELETE FROM `creature_text` WHERE `entry` IN (@TAREM);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@TAREM,0,0,'Mysterious hoofprints, scorched shields, stray badges... how do we make sense of all this?',12,0,100,6,0,0,'Inspector Tarem');

-- Add SAI to Krixil Slogswitch
SET @KRIXIL := 23573;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@KRIXIL;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@KRIXIL;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KRIXIL,0,0,0,1,0,100,0,60000,70000,170000,180000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Krixil Slogswitch -  OOC - Say 0');

-- Text for Krixil Slogswitch
DELETE FROM `creature_text` WHERE `entry` IN (@KRIXIL);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@KRIXIL,0,0,'I don''t think Drazzit''s going to have any luck finding anyone to kill this raptor. I mean, he''s already raised the reward twice...',12,0,100,1,0,0,'Krixil Slogswitch');

-- Add SAI to Axle
SET @AXLE := 23995;
SET @BROGG := 23579;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@AXLE;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@AXLE;
DELETE FROM `smart_scripts` WHERE `source_type`=9 AND `entryorguid`=@AXLE*100;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@AXLE,0,0,0,11,0,100,0,0,0,0,0,53,0,@AXLE,1,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Spawn - load waypoints'),
(@AXLE,0,1,2,40,0,100,0,4,@AXLE,0,0,54,24000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Reach wp 4 - Pause Path'),
(@AXLE,0,2,0,61,0,100,0,0,0,0,0,80,@AXLE*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Reach wp 4 - Run Script'),
(@AXLE,0,3,4,40,0,100,0,8,@AXLE,0,0,54,140000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Reach wp 8 - Pause Path'),
(@AXLE,0,4,0,61,0,100,0,0,0,0,0,66,@AXLE,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Reach wp 8 - Turn to'),
(@AXLE*100,9,0,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Script - Say 0'),
(@AXLE*100,9,1,0,0,0,100,0,4000,4000,0,0,1,0,0,0,0,0,0,11,@BROGG,10,0,0,0,0,0, 'Axle -  Script - brogg Say 0'),
(@AXLE*100,9,2,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Script - Say 1'),
(@AXLE*100,9,3,0,0,0,100,0,4000,4000,0,0,1,1,0,0,0,0,0,11,@BROGG,10,0,0,0,0,0, 'Axle -  Script - brogg Say 1'),
(@AXLE*100,9,4,0,0,0,100,0,4000,4000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Axle -  Script - Say 2');

UPDATE `creature` SET `position_x`=-4629.937,`position_y`=-3176.124,`position_z`=41.22349,`orientation`=6.263439 WHERE `id`=@AXLE;

DELETE FROM `waypoints` WHERE `entry`=@AXLE;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@AXLE,1,-4627.793,-3176.207,41.40616, 'Axle'),
(@AXLE,2,-4617.293,-3178.556,34.95082, 'Axle'),
(@AXLE,3,-4615.726,-3176.381,34.81108, 'Axle'),
(@AXLE,4,-4618.000,-3175.210,34.81240, 'Axle'),
(@AXLE,5,-4615.726,-3176.381,34.81108, 'Axle'),
(@AXLE,6,-4617.293,-3178.556,34.95082, 'Axle'),
(@AXLE,7,-4627.793,-3176.207,41.40616, 'Axle'),
(@AXLE,8,-4629.937,-3176.124,41.22349, 'Axle');

-- Text for Axle
DELETE FROM `creature_text` WHERE `entry` IN (@AXLE);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@AXLE,0,0,'I thought we talked about this, Brogg. You can''t stay in this building. Sure, it can house you, but there''s no room for anyone else!',12,0,100,1,0,0,'Axle'),
(@AXLE,1,0,'Yes, we said you can stay here, but this building is our headquarters! All of our manuals and blueprints are stored here!',12,0,100,1,0,0,'Axle'),
(@AXLE,2,0,'I''m inclined to say they made ogres too big! I can see I''m not going to convince you to move now, but don''t think this is permanent!',12,0,100,1,0,0,'Axle');

-- Text for Brogg
DELETE FROM `creature_text` WHERE `entry` IN (@BROGG);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@BROGG,0,0,'You said Brogg could stay here! You promised Brogg you'' help regain Stonemaul clan Mound!',12,0,100,1,0,0,'Brogg'),
(@BROGG,1,0,'But this the only building that fit Brogg! Goblins make buildings too small!',12,0,100,1,0,0,'Brogg');

UPDATE `creature` SET `MovementType`=0 WHERE `guid`=18594;
DELETE FROM `creature_addon` WHERE `guid`=18594;
DELETE FROM `waypoint_data` WHERE `id`=185940;
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=18597;
DELETE FROM `creature_addon` WHERE `guid`=18597;
DELETE FROM `waypoint_data` WHERE `id`=185970;
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=18598;
DELETE FROM `creature_addon` WHERE `guid`=18598;
DELETE FROM `waypoint_data` WHERE `id`=185980;
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=18599;
DELETE FROM `creature_addon` WHERE `guid`=18599;
DELETE FROM `waypoint_data` WHERE `id`=185990;
UPDATE `waypoint_data` SET `action`=0 WHERE `action` BETWEEN 14 AND 21;
DELETE FROM `db_script_string` WHERE `entry` BETWEEN 2000005010 AND 2000005017;
DELETE FROM `waypoint_scripts` WHERE `dataint` BETWEEN 2000005010 AND 2000005017;
