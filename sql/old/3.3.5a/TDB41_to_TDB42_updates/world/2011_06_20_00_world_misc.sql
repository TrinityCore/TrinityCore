-- Taela Everstride "Allerian Stronghold, Terokkar Forest" SAI
SET @ENTRY   := 18704; -- NPC entry
SET @SPELL1  := 29121; -- Shoot Bow
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`='' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `bytes2`=258 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,5000,6000,5000,6000,11,@SPELL1,0,0,0,0,0,10,58462,16899,0,0,0,0,0, 'Taela Everstride - OOC - Cast shoot on target');
-- Fix Spell condition
UPDATE `conditions` SET `ConditionValue2`=16899 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=29121;
-- Remove out path data
DELETE FROM  `creature_addon` WHERE `guid`=66949;
DELETE FROM `waypoint_data` WHERE `id`=669490;
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 144 AND 156;
