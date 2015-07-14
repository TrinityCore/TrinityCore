--
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3946) AND `source_type`=0 AND `id` IN (4, 5) ;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3946, 0, 4, 0, 1, 0, 100, 1, 4000, 4000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Velinde Starsong - Out of Combat - Say Line 3'),
(3946, 0, 5, 0, 1, 0, 100, 1, 11000, 11000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Velinde Starsong - Out of Combat - Say Line 4');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (1, 2, 3, 4, 5, 6) AND `SourceEntry`=3946;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`, `ConditionTarget`) VALUES
(22,2,3946,0,23,2161,0,0,0,'','event require AREA 2161', 1, 1),
(22,3,3946,0,23,2161,0,0,0,'','event require AREA 2161', 1, 1),
(22,4,3946,0,23,2161,0,0,0,'','event require AREA 2161', 1, 1),
(22,5,3946,0,23,2161,0,0,0,'','event require AREA 2161', 0, 1),
(22,6,3946,0,23,2161,0,0,0,'','event require AREA 2161', 0, 1);

DELETE FROM `creature_text` WHERE `entry` IN (3946) AND `groupid` IN (3, 4);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(3946,3,0,'I have failed... I have failed in my duty... failed my people... The worgen run rampant, and the Scythe of my goddess is lost.',12,7,100,0,0,0,'Velinde Starsong', 1359),
(3946,4,0,'This evil I have unleashed... In whose hand does the power my goddess granted to me now lie... By whose hand is it directed?',12,7,100,0,0,0,'Velinde Starsong', 1360);
