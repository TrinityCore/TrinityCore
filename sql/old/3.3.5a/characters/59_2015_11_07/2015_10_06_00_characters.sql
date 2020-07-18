ALTER TABLE `gm_ticket`
  ADD COLUMN `resolvedBy` INT(10) NOT NULL DEFAULT '0' COMMENT 'GUID of GM who resolved the ticket' AFTER `needMoreHelp`;
