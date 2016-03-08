/* Sunken Temple - Support for quest 3447: Secret of the Circle */
SET @GO_GUID := 5521;
SET @ALTAR := 148836;
SET @LIGHT := 148883;
SET @ATAL_ALARION := 8580;
SET @ATALAI_IDOL := 148838;

-- Altar of Hakkar
UPDATE `gossip_menu_option` SET `action_menu_id`=1302 WHERE `menu_id`=1288;
-- SAI: Add Pattern of lights
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=@ALTAR;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ALTAR AND `source_type`=1 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ALTAR*100 AND `source_type`=9 AND `id` BETWEEN 0 AND 5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ALTAR,1,0,0,62,0,100,0,1288,0,0,0,80,@ALTAR*100,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On gossip option select run script'),
(@ALTAR*100,9,0,0,1,0,100,0,0,0,0,0,50,@LIGHT,3,0,0,0,0,8,0,0,0,-515.553,95.25821,-148.7401,-1.500983, 'Script - Summon Temp GO'),
(@ALTAR*100,9,1,0,1,0,100,0,3000,3000,0,0,50,@LIGHT,3,0,0,0,0,8,0,0,0,-419.8487,94.48368,-148.7401,-1.500983, 'Script - Summon Temp GO'),
(@ALTAR*100,9,2,0,1,0,100,0,3000,3000,0,0,50,@LIGHT,3,0,0,0,0,8,0,0,0,-491.4003,135.9698,-148.7401,-1.500983, 'Script - Summon Temp GO'),
(@ALTAR*100,9,3,0,1,0,100,0,3000,3000,0,0,50,@LIGHT,3,0,0,0,0,8,0,0,0,-491.4909,53.48179,-148.7401,-1.500983, 'Script - Summon Temp GO'),
(@ALTAR*100,9,4,0,1,0,100,0,3000,3000,0,0,50,@LIGHT,3,0,0,0,0,8,0,0,0,-443.8549,136.1007,-148.7401,-1.500983, 'Script - Summon Temp GO'),
(@ALTAR*100,9,5,0,1,0,100,0,3000,3000,0,0,50,@LIGHT,3,0,0,0,0,8,0,0,0,-443.4171,53.83124,-148.7401,-1.500983, 'Script - Summon Temp GO');

-- Mini-boss Atal'alarion <Guardian of the Idol> and GameObject Idol of Hakkar
DELETE FROM `creature` WHERE `guid`=34521 AND `id`=@ATAL_ALARION; -- spawned by script

DELETE FROM `gameobject` WHERE `guid`=@GO_GUID AND `id`=@ATALAI_IDOL; -- spawned but hidden until creature die
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneid`,`areaid`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`VerifiedBuild`) VALUES
(@GO_GUID,@ATALAI_IDOL,109,0,0,3,1,-476.2693,94.41199,-189.7297,1.588249,0,0,0,1,-1,255,1,12340);

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ATAL_ALARION AND `source_type`=0 AND `id`=7;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ATAL_ALARION,0,7,0,6,0,100,0,0,0,0,0,70,7200,0,0,0,0,0,14,@GO_GUID,@ATALAI_IDOL,0,0,0,0,0, 'Atal''alarion - On Just Died - Respawn Idol of Hakkar');
