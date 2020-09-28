--
UPDATE `creature_template` SET `gossip_menu_id`= 9794 WHERE `entry`= 29196;
UPDATE `gossip_menu_option` SET `OptionNpcFlag`= 16 WHERE `MenuId` IN (9792, 9793, 9794);
UPDATE `gossip_menu_option` SET `OptionType`= 16 WHERE `MenuId` IN (9792, 9793, 9794) AND `OptionIndex`= 1;

DELETE FROM `creature_trainer` WHERE `CreatureId` IN (29194, 29195, 29196, 28472, 28471);
INSERT INTO `creature_trainer` (`CreatureId`, `TrainerId`, `MenuId`, `OptionIndex`) VALUES
(29194, 55, 9792, 0), -- Amal'thazad
(29195, 55, 9793, 0), -- Lady Alistra
(28471, 55, 9691, 0), -- Lady Alistra
(29196, 55, 9794, 0), -- Lord Thorval
(28472, 55, 9692, 0); -- Lord Thorval
