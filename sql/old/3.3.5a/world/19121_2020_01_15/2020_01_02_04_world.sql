-- 
UPDATE `creature_template` SET `gossip_menu_id`=1702 WHERE `entry` IN (6548);
UPDATE `creature_template` SET `gossip_menu_id`=434 WHERE `entry` IN (4419);

DELETE FROM `gossip_menu` WHERE `MenuID` IN (21211,21212,280,282,1702,21217,434) AND `TextID` IN (778,780,2354,932);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(280,778),
(282,780),
(1702,2354),
(434,932);

UPDATE `creature_template` SET `gossip_menu_id`=280 WHERE `entry` =4429;
UPDATE `creature_template` SET `gossip_menu_id`=282 WHERE `entry` IN (4430,13000);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (15) AND `SourceGroup` IN (21211,21212,280,282,434,21217);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 280, 0, 0, 0, 9, 0, 1950, 0, 0, 0, 0, 0, "", "Show gossip option if quest 'Get the Scoop' is taken"),
(15, 282, 0, 0, 0, 9, 0, 1950, 0, 0, 0, 0, 0, "", "Show gossip option if quest 'Get the Scoop' is taken"),
(15, 434, 0, 0, 0, 9, 0, 1950, 0, 0, 0, 0, 0, "", "Show gossip option if quest 'Get the Scoop' is taken");

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (21211,21212,280,282,434,21217);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, BoxBroadcastTextID, `VerifiedBuild`) VALUES
(280, 0, 0, "Where is Tirth's assistant?", 2769, 1, 1, 281, 0, 0, 0, "", 0, 0),
(282, 0, 0, "Where is Tirth's assistant?", 2779, 1, 1, 283, 0, 0, 0, "", 0, 0),
(434, 0, 0, "Where is Tirth's assistant?", 2779, 1, 1, 433, 0, 0, 0, "", 0, 0);
