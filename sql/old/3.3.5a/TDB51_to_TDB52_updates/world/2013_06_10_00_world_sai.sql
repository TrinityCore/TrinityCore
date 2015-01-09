-- Add SmartAI to Quarter Master Miranda Breechlock to give player item when selecting I need another Argent Dawn Commission.
SET @ENTRY := 11536;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES 
(@ENTRY,0,0,1,62,0,100,0,3461,0,0,0,11,17777,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Miranda Breechlock - On gossip select - Cast Create Commission'),
(@ENTRY,0,1,0,61,0,100,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Miranda Breechlock - On gossip select - Close Gossip');
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup` =3461;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15,3461,0,0,0,2,0,12846,1,0,1,0,'','I need another Argent Dawn Commission. - Must not already have Argent Dawn Commission'),
(15,3461,0,0,0,8,0,5401,0,0,0,0,'','I need another Argent Dawn Commission. - Must have completed Argent Dawn Commission Quest Alliance'),
(15,3461,0,0,1,2,0,12846,1,0,1,0,'','I need another Argent Dawn Commission. - Must not already have Argent Dawn Commission'),
(15,3461,0,0,1,8,0,5503,0,0,0,0,'','I need another Argent Dawn Commission. - Must have completed Argent Dawn Commission Quest Mage'),
(15,3461,0,0,2,2,0,12846,1,0,1,0,'','I need another Argent Dawn Commission. - Must not already have Argent Dawn Commission'),
(15,3461,0,0,2,8,0,5405,0,0,0,0,'','I need another Argent Dawn Commission. - Must have completed Argent Dawn Commission Quest Horde');
