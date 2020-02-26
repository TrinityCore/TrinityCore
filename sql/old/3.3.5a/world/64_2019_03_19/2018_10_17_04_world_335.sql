-- 
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (6877,6878,6879,6880,6881, 5709,5710,5711,5712,5713);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5709, 0, 0, "Game? Are you crazy?", 9352, 1, 1, 0, 0, 0, 0, "", 0, 0),
(5710, 0, 0, "Why you little...", 9355, 1, 1, 0, 0, 0, 0, "", 0, 0),
(5711, 0, 0, "Mark my words,, I will catch you,, imp. And when I do!", 9356, 1, 1, 0, 0, 0, 0, "", 0, 0),
(5712, 0, 0, "DIE!", 9359, 1, 1, 0, 0, 0, 0, "", 0, 0),
(5713, 0, 0, "Prepare to meet your maker.", 9362, 1, 1, 0, 0, 0, 0, "", 0, 0);

DELETE FROM `gossip_menu` WHERE `MenuID`=5709 AND `TextID` IN (6878,6879,6880,6881);
UPDATE `smart_scripts` SET `action_param1`=5709, `action_param2`=6877 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param1`=5710, `action_param2`=6878 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=2;
UPDATE `smart_scripts` SET `action_param1`=5711, `action_param2`=6879 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=3;
UPDATE `smart_scripts` SET `action_param1`=5712, `action_param2`=6880 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=4;
UPDATE `smart_scripts` SET `action_param1`=5713, `action_param2`=6881 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=5;

UPDATE `smart_scripts` SET `event_param1`=5709 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=6;
UPDATE `smart_scripts` SET `event_param1`=5710 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=7;
UPDATE `smart_scripts` SET `event_param1`=5711 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=8;
UPDATE `smart_scripts` SET `event_param1`=5712 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=9;
UPDATE `smart_scripts` SET `event_param1`=5713 WHERE `entryorguid`=14354 AND `source_type`=0 AND `id`=10;
