--  change secId from int(10)u to tinyint(3)u
ALTER TABLE `rbac_security_level_groups` CHANGE `secId` `secId` tinyint(3) unsigned NOT NULL COMMENT 'Security Level id';
