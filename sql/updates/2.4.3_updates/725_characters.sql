ALTER TABLE `character_ticket` RENAME TO `gm_tickets`; 
ALTER TABLE `gm_tickets` CHANGE `guid` `playerGuid` int(11) unsigned NOT NULL default '0'; 
ALTER TABLE `gm_tickets` CHANGE `ticket_id` `guid` int(11) unsigned NOT NULL default '0'; 
ALTER TABLE `gm_tickets` CHANGE `ticket_text` `message` text(0) NOT NULL;
ALTER TABLE `gm_tickets` CHANGE `ticket_lastchange` `timestamp` int(10) NOT NULL default '0';
