--
ALTER TABLE `gossip_menu` ADD COLUMN `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0';
ALTER TABLE `gossip_menu_option` ADD COLUMN `VerifiedBuild` SMALLINT(5) NOT NULL DEFAULT '0';
UPDATE `gossip_menu` SET `VerifiedBuild`=-1 where `entry` >49999;
