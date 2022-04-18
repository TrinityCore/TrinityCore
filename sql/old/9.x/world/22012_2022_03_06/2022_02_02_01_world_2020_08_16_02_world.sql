--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (56711,56713);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,56711,0,0,31,0,3,30413,132012,0,0,0,"","Group 0: Spell 'Image Channel' targets creature 'Channel Image Target'"),
(13,1,56713,0,0,31,0,3,30413,132013,0,0,0,"","Group 0: Spell 'Image Channel' targets creature 'Channel Image Target'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 30111 AND `source_type` = 0 AND `id` IN (4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30179 AND `source_type` = 0 AND `id` IN (4,5);
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30319 AND `source_type` = 0 AND `id` IN (5,6);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30111,0,4,0,1,0,100,1,1000,1000,0,0,0,11,56711,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Worshipper - Out of Combat - Cast 'Image Channel' (No Repeat)"),
(30111,0,5,0,1,0,100,1,1000,1000,0,0,0,11,56713,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Worshipper - Out of Combat - Cast 'Image Channel' (No Repeat)"),
(30179,0,4,0,1,0,100,1,1000,1000,0,0,0,11,56711,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Apostle - Out of Combat - Cast 'Image Channel' (No Repeat)"),
(30179,0,5,0,1,0,100,1,1000,1000,0,0,0,11,56713,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Apostle - Out of Combat - Cast 'Image Channel' (No Repeat)"),
(30319,0,5,0,1,0,100,1,1000,1000,0,0,0,11,56711,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Darkcaster - Out of Combat - Cast 'Image Channel' (No Repeat)"),
(30319,0,6,0,1,0,100,1,1000,1000,0,0,0,11,56713,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Twilight Darkcaster - Out of Combat - Cast 'Image Channel' (No Repeat)");
