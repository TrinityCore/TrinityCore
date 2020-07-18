-- Ambassador Sunsorrow
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=7178;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,7178,8740,0,0,16,0,512,0,0,0,0,0,"","Show gossip text if player is a Blood Elf"),
(14,7178,8458,0,0,16,0,1279,0,0,0,0,0,"","Show gossip text if player is not a Blood Elf");

DELETE FROM `gossip_menu` WHERE `MenuID` IN (7178,8312) AND `TextID`=10378;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8312,10378,0);

UPDATE `gossip_menu_option` SET `ActionMenuID`=8312 WHERE `MenuID`=7178;

DELETE FROM `smart_scripts` WHERE `entryorguid`=16287 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16287,0,0,0,62,0,100,0,7178,0,0,0,0,85,37084,0,0,0,0,0,7,0,0,0,0,0,0,0,"Ambassador Sunsorrow - On Gossip Option 0 Selected - Create Item 'Lament of the Highborne'");
