ALTER TABLE `gm_tickets`
    ADD COLUMN `response` text NOT NULL AFTER `comment`,
    ADD COLUMN `haveTicket` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `viewed`;
