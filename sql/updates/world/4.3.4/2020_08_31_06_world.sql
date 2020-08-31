UPDATE `gossip_menu_option` SET `OptionType`=5, `OptionNpcflag`=16 WHERE  `MenuId`=12523 AND `OptionIndex`=0;
UPDATE `gossip_menu_option` SET `OptionType`=16, `OptionNpcflag`=16 WHERE  `MenuId`=12523 AND `OptionIndex`=1;

DELETE FROM `creature_trainer` WHERE `CreatureId` IN (49781, 49961);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(49781, 16, 12523, 0),
(49961, 16, 7263, 0);
