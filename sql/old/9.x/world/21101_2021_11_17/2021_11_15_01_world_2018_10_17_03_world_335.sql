-- 
DELETE FROM `gossip_menu` WHERE `MenuId` IN (21253) AND `TextId` IN (9520);
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE `MenuId` IN (7771);
UPDATE `creature_template` SET `gossip_menu_id`=7771 WHERE `entry`=18715;
UPDATE `smart_scripts` SET `event_param1`=7771 WHERE `entryorguid` IN (18715) AND `source_type`=0 AND `id`=2;
