-- 
DELETE FROM `gossip_menu` WHERE `MenuID` IN (21210) AND `TextID` IN (769);
UPDATE `creature_template` SET `gossip_menu_id`=10482 WHERE `entry`=3701;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (21210,10482);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, BoxBroadcastTextID, `VerifiedBuild`) VALUES
(10482, 0, 0, "Tharnariun,, I have lost the trap. Could you please give me another?", 9431, 1, 1, 0, 0, 0, 0, "", 0, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (21210,10482);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 10482, 0, 0, 0, 2, 0, 7586, 1, 1, 1, 0, 0, "", "Show gossip option if player does not have item Tharnariun's Hope"),
(15, 10482, 0, 0, 0, 9, 0, 2118, 0, 0, 0, 0, 0, "", "Show gossip option if player has quest 'Plagued Lands' taken");

UPDATE `smart_scripts` SET `event_param1`=10482 WHERE `entryorguid` IN (3701) AND `source_type`=0 AND `id`=0;
