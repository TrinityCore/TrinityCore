ALTER TABLE `gm_tickets` ADD `closed` tinyint(1) NOT NULL default '0' AFTER `timestamp`;
ALTER TABLE `gm_tickets` ADD `assignedto` int(10) NOT NULL default '0' AFTER `timestamp`;
