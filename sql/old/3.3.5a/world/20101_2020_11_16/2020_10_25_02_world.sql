--
UPDATE `creature_template` SET `gossip_menu_id` = 6766, `AIName` = "SmartAI" WHERE `entry` = 15378;
UPDATE `creature_template` SET `gossip_menu_id` = 6765, `AIName` = "SmartAI" WHERE `entry` = 15379;
UPDATE `creature_template` SET `gossip_menu_id` = 6767, `AIName` = "SmartAI" WHERE `entry` = 15380;
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 15502;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15378,15379,15380,15502) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15378,0,0,0,64,0,100,0,0,0,0,0,0,98,6795,8113,0,0,0,0,7,0,0,0,0,0,0,0,0,"Merithra of the Dream - On Gossip Hello - Send Gossip"),
(15379,0,0,0,64,0,100,0,0,0,0,0,0,98,6794,8112,0,0,0,0,7,0,0,0,0,0,0,0,0,"Caelestrasz - On Gossip Hello - Send Gossip"),
(15380,0,0,0,64,0,100,0,0,0,0,0,0,98,6793,8111,0,0,0,0,7,0,0,0,0,0,0,0,0,"Arygos - On Gossip Hello - Send Gossip"),
(15502,0,0,2,62,0,100,0,6644,0,0,0,0,11,29182,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Andorgos - On Gossip Option 0 Selected - Cast 'Teleport to Twin Emperors'"),
(15502,0,1,2,62,0,100,0,6644,1,0,0,0,11,29188,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Andorgos - On Gossip Option 1 Selected - Cast 'Teleport to Final Chamber'"),
(15502,0,2,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Andorgos - On Link - Close Gossip");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` BETWEEN 15378 AND 15380 AND `SourceId` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 6644;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 6644;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22,1,15378,0,0,13,0,5,3,2,0,0,0,"","Group 0: Execute SAI (Action 0) if C'Thun is done"),
(22,1,15379,0,0,13,0,5,3,2,0,0,0,"","Group 0: Execute SAI (Action 0) if C'Thun is done"),
(22,1,15380,0,0,13,0,5,3,2,0,0,0,"","Group 0: Execute SAI (Action 0) if C'Thun is done"),
(14,6644,7899,0,0,13,0,4,3,2,1,0,0,"","Group 0: Show gossip text 7899 if Twin Emperors is not done"),
(14,6644,7899,0,0,13,0,8,3,2,1,0,0,"","Group 0: Show gossip text 7899 if Ouro is not done"),
(14,6644,8701,0,0,13,0,4,3,2,0,0,0,"","Group 0: Show gossip text 8701 if Twin Emperors is done"),
(14,6644,8702,0,0,13,0,8,3,2,0,0,0,"","Group 0: Show gossip text 8702 if Ouro is done"),
(15,6644,0,0,0,13,0,4,3,2,0,0,0,"","Group 0: Show Gossip Option 0 if Twin Emperors is done"),
(15,6644,1,0,0,13,0,8,3,2,0,0,0,"","Group 0: Show Gossip Option 1 if Ouro is done");

DELETE FROM `spell_scripts` WHERE `id` IN (29182,29188);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`,`Comment`) VALUES
(29182,0,0,15,29181,2,0,0,0,0,0,"Teleport to Twin Emperors - On Effect Hit (Script Effect) - Cast 'Teleport to Twin Emps Effect DND'"),
(29188,0,0,15,29190,2,0,0,0,0,0,"Teleport to Final Chamber - On Effect Hit (Script Effect) - Cast 'Teleport to Final Chamber Effect DND'");

DELETE FROM `spell_target_position` WHERE `ID` IN (29181,29190);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `VerifiedBuild`) VALUES
(29181,0,531,-8971.805,1321.432,-104.249,0.845,0),
(29190,0,531,-8632.802,2055.835,108.859,1.024,0);

UPDATE `gossip_menu_option` SET `OptionType` = 1, `OptionNpcFlag` = 1 WHERE `MenuID` = 6644;
