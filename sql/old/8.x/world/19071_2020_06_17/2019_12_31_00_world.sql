-- 
UPDATE `creature_template` SET `gossip_menu_id`=4267 WHERE `entry`=3523;
DELETE FROM `gossip_menu_option_trainer` WHERE `MenuId` IN (4347,4267);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(4347, 0, 163),
(4267, 0, 163);
