-- Ram Racing Reins
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (24510,24468) AND `source_type` = 0 AND `id` IN (3,4,5);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24510,0,3,5,62,0,100,0,8958,6,0,0,0,11,44262,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Driz Tumblequick - On Gossip Option 6 Selected - Cast 'Brewfest - Create Ram Racing Crop'"),
(24510,0,4,5,62,0,100,0,8960,0,0,0,0,11,44262,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Driz Tumblequick - On Gossip Option 0 Selected - Cast 'Brewfest - Create Ram Racing Crop'"),
(24510,0,5,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Driz Tumblequick - On Link - Close Gossip"),
(24468,0,3,5,62,0,100,0,8958,6,0,0,0,11,44262,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Pol Amberstill - On Gossip Option 6 Selected - Cast 'Brewfest - Create Ram Racing Crop'"),
(24468,0,4,5,62,0,100,0,8960,0,0,0,0,11,44262,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Pol Amberstill - On Gossip Option 0 Selected - Cast 'Brewfest - Create Ram Racing Crop'"),
(24468,0,5,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Pol Amberstill - On Link - Close Gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8958 AND `SourceEntry` = 6;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 8960 AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(15,8958,6,0,0,2,0,33306,1,1,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have item 'Ram Racing Reins'"),
(15,8960,0,0,0,2,0,33306,1,1,1,0,0,"","Group 0: Show Gossip Option 0 if player does not have item 'Ram Racing Reins'");

-- Fix messed up gossip options related to Synthebrew Goggles
UPDATE `conditions` SET `ConditionValue3` = 1 WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (9006,9016) AND `SourceEntry` = 0;
UPDATE `smart_scripts` SET `event_param1` = 10603 WHERE `entryorguid` = 23486 AND `source_type` = 0 AND `id` = 0;
UPDATE `smart_scripts` SET `event_param1` = 10604 WHERE `entryorguid` = 24657 AND `source_type` = 0 AND `id` = 0;
