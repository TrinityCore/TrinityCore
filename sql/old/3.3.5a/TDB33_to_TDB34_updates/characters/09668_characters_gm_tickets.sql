ALTER TABLE `gm_tickets` ADD COLUMN `completed` int(11) NOT NULL DEFAULT '0' AFTER `comment`;
ALTER TABLE `gm_tickets` ADD COLUMN `escalated` int(11) NOT NULL DEFAULT '0' AFTER `completed`;
ALTER TABLE `gm_tickets` ADD COLUMN `viewed` int(11) NOT NULL DEFAULT '0' AFTER `escalated`;
