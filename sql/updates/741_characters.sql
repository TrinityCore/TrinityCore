ALTER TABLE `gm_tickets` CHANGE `closed` `closed` tinyint(1) NOT NULL default '0';
ALTER TABLE `gm_tickets` ADD `closed` bit(1) NOT NULL AFTER `timestamp`;
ALTER TABLE `gm_tickets` ADD `assignedto` int(10) NOT NULL default '0' AFTER `timestamp`;

