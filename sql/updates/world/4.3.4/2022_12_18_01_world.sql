-- Kazemde Inkeeper
UPDATE `gossip_menu_option` SET `OptionNpcFlag`= 0x80, `OptionType`= 8 WHERE `MenuId`= 9868 AND `OptionIndex`= 0;
UPDATE `gossip_menu_option` SET `OptionNpcFlag`= 0x10000, `OptionType`= 3 WHERE `MenuId`= 9868 AND `OptionIndex`= 1;
UPDATE `gossip_menu_option` SET `OptionNpcFlag`= 0, `OptionType`= 0 WHERE `MenuId`= 9868 AND `OptionIndex`= 2;

-- Ramkahen resting area trigger
DELETE FROM `areatrigger_tavern` WHERE `id`= 6524;
INSERT INTO `areatrigger_tavern` (`id`, `name`) VALUES
(6524, 'Ramkahen');

-- Remove invalid loot from Mac Frog
UPDATE `creature_template` SET `lootid`= 0 WHERE `entry`= 50491;
DELETE FROM `creature_loot_template` WHERE `Entry`= 50491;
