ALTER TABLE `gm_ticket`
  ADD COLUMN `type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' COMMENT '0 open, 1 closed, 2 character deleted' AFTER `id`;

UPDATE `gm_ticket` SET `type` = 1 WHERE `closedBy` != 0 OR `completed` != 0 OR `resolvedBy` != 0;
UPDATE `gm_ticket` SET `closedBy` = 0 WHERE `closedBy` < 0;
UPDATE `gm_ticket` SET `resolvedBy` = 0 WHERE `resolvedBy` < 0;

ALTER TABLE `gm_ticket`
  CHANGE COLUMN `closedBy` `closedBy` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `lastModifiedTime`,
  CHANGE COLUMN `resolvedBy` `resolvedBy` INT(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'GUID of GM who resolved the ticket' AFTER `needMoreHelp`;
