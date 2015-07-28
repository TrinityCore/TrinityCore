SET @ENTRY = 24918;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY; - 4.x
UPDATE `creature_template` SET `AIName`='SmartAI',`ScriptName`='' WHERE `entry`=@ENTRY;

DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`event_type`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(@ENTRY,0,0,4000,6000,7000,9000,11,14873,0,2,'Felblood Initiate - Cast Sinister Strike'),
(@ENTRY,1,0,17000,22000,20000,26000,11,29098,1,2,'Felblood Initiate - Cast Bitter Withdrawal'),
(@ENTRY,2,0,8000,12000,18000,22000,11,35871,1,2,'Felblood Initiate - Cast Spellbreaker'),
(@ENTRY,3,8,44937,0,0,0,36,24955,1,1,'Felblood Initiate - Changes Template to Emaciated Felblood After Using Fel Siphon (Quest: 11515)');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup`=4 AND `SourceEntry`=@ENTRY AND `SourceId`=0;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ConditionTarget`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`NegativeCondition`,`Comment`) VALUE
(22,4,@ENTRY,0,1,31,3,24955,1,'Felblood Initiate may not already be transformed to template entry 24955 when trying to update template to 24955');
