-- Update Felboar
SET @ENTRY := 21878;
UPDATE `creature` SET `spawndist`=5,`MovementType`=1,`curhealth`=1,`spawntimesecs`=300 WHERE `id`=@ENTRY;
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `bytes2`=1,`auras`='33908' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,100,100,30000,55000,11,35570,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Felboar - Combat - Cast charge');

-- Update Dormant Infernal
SET @ENTRY := 21080;
UPDATE `creature_template_addon` SET `bytes2`=1,`auras`='36055' WHERE `entry`=@ENTRY;

-- Update Kagrosh
SET @ENTRY := 21725;
UPDATE `creature_template_addon` SET `bytes2`=1,`auras`='29266' WHERE `entry`=@ENTRY;
UPDATE `creature` SET `position_x`=-3421.365,`position_y`=2289.388,`position_z`=33.63479,`orientation`=3.874631 WHERE `guid`=86869;
DELETE FROM `creature` WHERE `guid`=86870;

-- Update Invis Deathforge Caster
SET @ENTRY := 21210;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES (@ENTRY,1,'36393');
UPDATE `creature_template` SET `flags_extra`=`flags_extra`|128 WHERE `entry`=@ENTRY;
