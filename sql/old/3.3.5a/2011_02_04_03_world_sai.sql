-- Honor Hold Archer fixup (tested)
-- Console no longer spamming waypoint script errors in Honor Hold
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=16896;
-- Honor Hold Archer "guid 58449 shoot at Honor Hold Target Dummy Right" SAI "Tested"
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-58449);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-58449,0,0,0,1,0,100,0,6000,6000,6000,6000,11,29120,2,0,0,0,0,10,58457,16898,0,0,0,0,0,'Fire at target every 6 sec');
-- Honor Hold Archer "guid 58450 shoot at Honor Hold Target Dummy Left" SAI "Tested"
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-58450);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-58450,0,0,0,1,0,100,0,4000,4000,6000,6000,11,29120,2,0,0,0,0,10,58461,16899,0,0,0,0,0,'Fire at target every 6 sec');
-- Honor Hold Archer "guid 58451 shoot at Honor Hold Target Dummy Middle" SAI "Tested"
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-58451);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-58451,0,0,0,1,0,100,0,2000,2000,6000,6000,11,29120,2,0,0,0,0,10,58455,16897,0,0,0,0,0,'Fire at target every 6 sec');
-- Fix Honor Hold Target Dummies InhabitType
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (16897,16898,16899);
-- Remove path data and scripts from Honor Hold Archers
DELETE FROM `waypoint_data` WHERE `id` IN (584490,584500,584510);
DELETE FROM `waypoint_scripts` WHERE `id` BETWEEN 52 AND 65;
UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid` IN (58449,58450,58451);
UPDATE `creature_addon` SET `path_id`=0 WHERE `guid` IN (58449,58450,58451);
-- Fix Spell condition for Spell 29120 to target either 16897,16898,16899
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=29120;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,29120,1,18,1,16897,0,0,'','Spell 29120 targets Honor Hold Target Dummy Middle'),
(13,0,29120,1,18,1,16898,0,0,'','Spell 29120 targets Honor Hold Target Dummy Right'),
(13,0,29120,1,18,1,16899,0,0,'','Spell 29120 targets Honor Hold Target Dummy Left');
