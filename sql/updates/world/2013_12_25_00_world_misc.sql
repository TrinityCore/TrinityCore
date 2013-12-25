-- Commander Danath Trollbane SAI
SET @ENTRY := 16819;
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`= '' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,20,0,100,0,10254,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Danath Trollbane - On Quest Rewarded - Say 0"),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,11,6245,0,0,0,0,0,7,0,0,0,0,0,0,0,"Commander Danath Trollbane - On Quest Rewarded - Cast Force Target - Salute");

-- Add Conditions for Force Commander Danath Trollbane gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7352;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7352,9938,0,0,8,0,10254,0,0,1,0,0, '', 'Gossip Text - Show Text if Quest 10254 is not rewarded'),
(14,7352,9939,0,0,8,0,10254,0,0,0,0,0, '', 'Gossip Text - Show Text if Quest 10254 is rewarded'),
(14,7352,9939,0,1,8,0,10937,0,0,1,0,0, '', 'Gossip Text - Show Text if Quest 10937 is not rewarded'),
(14,7352,9944,0,0,8,0,10937,0,0,0,0,0, '', 'Gossip Text - Show Text if Quest 10937 is rewarded');
