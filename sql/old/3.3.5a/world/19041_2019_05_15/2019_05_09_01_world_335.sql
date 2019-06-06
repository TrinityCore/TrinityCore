-- Wooden Outhouse
DELETE FROM `smart_scripts` WHERE `entryorguid`=173265 AND `source_type`=1 AND `id`=4;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(173265,1,4,0,62,0,100,0,2387,0,0,0,0,70,60,0,0,0,0,0,14,47578,173266,0,0,0,0,0,"Wooden Outhouse - On Gossip Option Selected - Respawn Gameobject 'Goodsteel Ledger'");

DELETE FROM `gossip_menu_option` WHERE `MenuID`=2387;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2387,0,0,"Um... sorry to bother you, but could I see Goodsteel's ledger again... if you're not using it.",5410,1,1,2386,0,0,0,"",0,0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=2387;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15,2387,0,0,0,9,0,4450,0,0,0,0,0,"","Show gossip option if quest 'Ledger from Tanaris' is taken"),
(15,2387,0,0,0,2,0,11727,1,1,1,0,0,"","Show gossip option if player does not have item 'Goodsteel Ledger'");
