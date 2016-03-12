-- 
-- Grizzly Hills Giant SAI
SET @ENTRY := 26261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,1,8,0,100,0,47394,0,0,0,80,26261,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Hills Giant - On Spellhit 'Kurun's Blessing' - Run Script"),
(@ENTRY,0,1,0,61,0,100,0,47394,0,0,0,33,26261,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grizzly Hills Giant - On Spellhit 'Kurun's Blessing' - Quest Credit 'Rallying the Troops'"),
(@ENTRY,0,2,0,1,0,100,0,2000,5000,4000,6000,11,46815,0,0,0,0,0,19,26264,500,0,0,0,0,0,"Grizzly Hills Giant - Out of Combat - Cast 'Toss Boulder'");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `SourceEntry`=46815;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 46815, 0, 0, 31, 0, 3, 26264, 0, 0, 0, 0, '', 'Toss Boulder - only targets Dummy');
