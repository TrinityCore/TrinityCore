ALTER TABLE `version`
  CHANGE `core_version` `core_version` VARCHAR(255) DEFAULT '' NOT NULL COMMENT 'Core revision dumped at startup.';
