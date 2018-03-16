/*
-- J.D. Collie gossip options and conditions
DELETE FROM `gossip_menu` WHERE `MenuID`=2184 AND `TextID`=2833;
DELETE FROM `gossip_menu` WHERE `MenuID` IN (2200,2202,2203,2204);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2184,2833,0),
(2200,2834,0),
(2202,2836,0),
(2203,2837,0),
(2204,2838,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=2184;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,2184,2833,0,0,8,0,4321,0,0,0,0,0,"","Show gossip text 2833 if quest 'Making Sense of It' is rewarded"),
(15,2184,0,0,0,8,0,4321,0,0,0,0,0,"","Show gossip option 0 if quest 'Making Sense of It' is rewarded"),
(15,2184,1,0,0,8,0,4321,0,0,0,0,0,"","Show gossip option 1 if quest 'Making Sense of It' is rewarded"),
(15,2184,2,0,0,8,0,4321,0,0,0,0,0,"","Show gossip option 2 if quest 'Making Sense of It' is rewarded"),
(15,2184,3,0,0,8,0,4321,0,0,0,0,0,"","Show gossip option 3 if quest 'Making Sense of It' is rewarded"),
(15,2184,3,0,0,2,0,11482,1,1,1,0,0,"","Show gossip option 3 if player does not have item 'Crystal Pylon User's Manual'");

DELETE FROM `gossip_menu_option` WHERE `MenuID`=2184;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2184,0,0,"Tell me more about the Eastern Crystal Pylon.",5186,1,1,2200,0,0,0,"",0,0),
(2184,1,0,"Tell me more about the Northern Crystal Pylon.",5188,1,1,2202,0,0,0,"",0,0),
(2184,2,0,"Tell me more about the Western Crystal Pylon.",5190,1,1,2203,0,0,0,"",0,0),
(2184,3,0,"I lost my Crystal Pylon User's Manual and need another one.",5191,1,1,2204,0,0,0,"",0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=9117 AND `source_type`=0 AND `id`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(9117,0,1,0,62,0,100,0,2184,3,0,0,85,15211,0,0,0,0,0,7,0,0,0,0,0,0,0,"J.D. Collie - On Gossip Option 3 Selected - Invoker Cast 'Create Pylon User's Manual'");
*/
