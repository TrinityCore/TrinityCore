/*
-- 
-- Mux Manascrambler
DELETE FROM `gossip_menu_option` WHERE `MenuID`=7083;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7083,0,0,"About that ghost revealer.  Did I happen to leave it here?  I seem to be missing it.",11909,1,1,0,0,0,0,"",0,0),
(7083,1,0,"I seem to have misplaced the distiller, Mux.  Did I happen to leave it here?",11908,1,1,0,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=7083 AND `SourceEntry`=1;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,7083,1,0,0,9,0,8924,0,0,0,0,0,"","Show gossip option if quest 'Hunting for Ectoplasm' is taken"),
(15,7083,1,0,0,2,0,21946,1,1,1,0,0,"","Show gossip option if player does not have item 'Ectoplasmic Distiller'");

UPDATE `smart_scripts` SET `action_type`=85, `action_param2`=2 WHERE `entryorguid`=16014 AND `source_type`=0 AND `id`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=16014 AND `source_type`=0 AND `id`=2;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(16014,0,2,1,62,0,100,0,7083,1,0,0,85,27752,2,0,0,0,0,7,0,0,0,0,0,0,0,"Mux Manascrambler - On Gossip Option 1 Selected - Invoker Cast 'Create Ectoplasmic Distiller'");
*/
