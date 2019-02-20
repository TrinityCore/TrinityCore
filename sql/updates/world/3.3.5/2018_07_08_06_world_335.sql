-- Malyfous Darkhammer
DELETE FROM `gossip_menu` WHERE `MenuID` IN (2991,2992,2993);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(2991,3674,0),
(2992,3675,0),
(2993,3676,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (2984,2991,2992,2993);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2984,0,0,"Tell me about the hide.",6129,1,1,2991,0,0,0,"",0,0),
(2991,0,0,"What are the chances of obtaining such a hide?",6131,1,1,2992,0,0,0,"",0,0),
(2992,0,0,"So let us pretend I get this hide, what else would you need and what could you actually make?",6133,1,1,2993,0,0,0,"",0,0),
(2993,0,0,"Ok!",6135,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2984;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2984,0,0,0,8,0,5047,0,0,0,0,0,"","Show gossip option if quest 'Finkle Einhorn, At Your Service!' is rewarded");

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=10637;
DELETE FROM `smart_scripts` WHERE `entryorguid`=10637 AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=1063700 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(10637,0,0,0,62,0,100,0,2993,0,0,0,80,1063700,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malyfous Darkhammer - On Gossip Option Selected - Run Script"),
(10637,0,1,0,62,0,100,0,2993,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Malyfous Darkhammer - On Gossip Option Selected - Close Gossip"),
(1063700,9,0,0,0,0,100,0,0,0,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.88205,"Malyfous Darkhammer - On Script - Set Orientation"),
(1063700,9,1,0,0,0,100,0,500,500,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Malyfous Darkhammer - On Script - Say Line 0"),
(1063700,9,2,0,0,0,100,0,5000,5000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.12414,"Malyfous Darkhammer - On Script - Set Orientation");

DELETE FROM `creature_text` WHERE `CreatureID`=10637;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(10637,0,0,"Read through my catalogue, $n.",12,0,100,25,0,0,6139,0,"Malyfous Darkhammer");
