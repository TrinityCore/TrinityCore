-- 
-- Highlord Demitrian
UPDATE `creature_template` SET `gossip_menu_id`=5675 WHERE `entry`=14347;

DELETE FROM `gossip_menu` WHERE `MenuID`=5675 AND `TextID`=6954;
DELETE FROM `gossip_menu` WHERE `MenuID` IN (5781,5784,5783);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5675,6954,0),
(5781,6955,0),
(5784,6956,0),
(5783,6958,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=5675 AND `OptionID`=1;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5781,5784,5783);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5675,1,0,"What must be done?",9547,1,1,5781,0,0,0,"",0,0),
(5781,0,0,"The Firelord and all who dare stand in my way shall reel from my wrath.",9549,1,1,5784,0,0,0,"",0,0),
(5784,0,0,"I shall scour the earth for this Earthshaper. What of the essence?",9552,1,1,5783,0,0,0,"",0,0),
(5783,0,0,"Give me the vessel, Highlord.",9554,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup`=5675;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14,5675,6954,0,0,2,0,18564,1,0,0,0,0,"","Show gossip text 6954 if player has item 'Bindings of the Windseeker'"),
(14,5675,6954,0,0,14,0,7785,0,0,0,0,0,"","Show gossip text 6954 if quest 'Examine the vessel' is not taken"),
(14,5675,6954,0,1,2,0,18563,1,0,0,0,0,"","Show gossip text 6954 if player has item 'Bindings of the Windseeker'"),
(14,5675,6954,0,1,14,0,7785,0,0,0,0,0,"","Show gossip text 6954 if quest 'Examine the vessel' is not taken"),
(15,5675,1,0,0,2,0,18564,1,0,0,0,0,"","Show gossip option 1 if player has item 'Bindings of the Windseeker'"),
(15,5675,1,0,0,14,0,7785,0,0,0,0,0,"","Show gossip option 1 if quest 'Examine the vessel' is not taken"),
(15,5675,1,0,1,2,0,18563,1,0,0,0,0,"","Show gossip option 1 if player has item 'Bindings of the Windseeker'"),
(15,5675,1,0,1,14,0,7785,0,0,0,0,0,"","Show gossip option 1 if quest 'Examine the vessel' is not taken"),
(15,5675,0,0,0,2,0,18564,1,0,1,0,0,"","Show gossip option 0 if player doesn't have item 'Bindings of the Windseeker'"),
(15,5675,0,0,0,2,0,18563,1,0,1,0,0,"","Show gossip option 0 if player doesn't have item 'Bindings of the Windseeker'"),
(15,5675,0,0,0,14,0,7785,0,0,0,0,0,"","Show gossip option 0 if quest 'Examine the vessel' is not taken");

UPDATE `smart_scripts` SET `event_param1`=5783 WHERE `entryorguid`=14347 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=14347 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(14347,0,2,0,62,0,100,0,5783,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Highlord Demitrian - On Gossip Option Selected - Close Gossip");
