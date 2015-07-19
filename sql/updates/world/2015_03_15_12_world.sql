-- 
-- Keryn Sylvius SAI
SET @ENTRY := 917;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,62,0,100,0,381,4,0,0,11,21100,0,0,0,0,0,7,0,0,0,0,0,0,0,"Keryn Sylvius - On Gossip Option 4 Selected - Cast 'Conjure Elegant Letter'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=381 AND `SourceEntry`=4;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 381, 4, 0, 0, 15, 0, 8, 0, 0, 0, 0, 0, '', 'Show gossip text if player is a rogue'),
(15, 381, 4, 0, 0, 27, 0, 24, 3, 0, 0, 0, 0, '', 'Show gossip text if level >= 24'),
(15, 381, 4, 0, 0, 2, 0, 17126, 1, 0, 1, 0, 0, '', 'Show gossip option if player does not have Elegant Letter');
