ALTER TABLE `gm_tickets`
    ADD COLUMN `response` TEXT NOT NULL AFTER `comment`,
    ADD COLUMN `haveTicket` TINYINT(3) UNSIGNED NOT NULL AFTER `viewed`;
