DELETE FROM `gossip_menu_option` WHERE `MenuId`= 1291 AND `OptionIndex`= 3;
UPDATE `gossip_menu_option` SET `OptionType`= 1, `OptionNpcFlag`= 1 WHERE `MenuId`= 1291 AND `OptionIndex`= 0;
UPDATE `gossip_menu_option` SET `OptionType`= 8 WHERE `MenuId`= 1291 AND `OptionIndex`= 1;
UPDATE `gossip_menu_option` SET `OptionType`= 3 WHERE `MenuId`= 1291 AND `OptionIndex`= 2;
