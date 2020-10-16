--
UPDATE `smart_scripts` SET `event_flags` = 0, `action_param2` = 0, `comment` = "Weslex Quickwrench - On Quest 'Have a Part, Give a Part' Finished - Run Script" WHERE `entryorguid` = 28033 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2803300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(2803300,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Weslex Quickwrench - On Script - Say Line 0"),
(2803300,9,1,0,0,0,100,0,4000,4000,0,0,0,1,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Weslex Quickwrench - On Script - Say Line 1"),
(2803300,9,2,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,0,1.08210,"Weslex Quickwrench - On Script - Set Orientation"),
(2803300,9,3,0,0,0,100,0,0,0,0,0,0,1,2,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Weslex Quickwrench - On Script - Say Line 2"),
(2803300,9,4,0,0,0,100,0,4000,4000,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Weslex Quickwrench - On Script - Set Orientation Home Position"),
(2803300,9,5,0,0,0,100,0,0,0,0,0,0,1,3,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Weslex Quickwrench - On Script - Say Line 3");

-- Missing conditions for gossip text
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 9635;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(14,9635,13322,0,0,8,0,12523,0,0,1,0,0,"","Group 0: Show gossip text 13322 if quest 'Have a Part, Give a Part' is not rewarded");
