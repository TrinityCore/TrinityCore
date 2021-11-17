-- 
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuId` IN (5709);
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (6877,6878,6879,6880,6881);

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
