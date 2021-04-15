-- Argent Stand Defender "guid 107662 throwing mace at target" SAI (Tested)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=28801;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-107662);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-107662,0,0,0,1,0,100,0,12000,18000,12000,18000,11,54423,2,0,0,0,0,10,117888,29416,0,0,0,0,0,'Fire at target every 12-18 sec');
-- Spell condition for "Hammer of the Righteous"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=54423;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,54423,0,18,1,29416,0,0,'','Spell 54423 targets Argent Stand Dummy');
-- Fix Argent Stand Dummy InhabitType and movement
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=29416;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `id`=29416;
