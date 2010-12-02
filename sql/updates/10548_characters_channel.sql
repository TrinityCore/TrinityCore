ALTER TABLE `channels`
DROP COLUMN `m_moderate`,
CHANGE `m_name` `m_name` VARCHAR(128) NOT NULL,
CHANGE `m_announce` `m_announce` TINYINT(3) UNSIGNED DEFAULT '1' NOT NULL,
CHANGE `m_public` `m_ownership` TINYINT(3) UNSIGNED DEFAULT '1' NOT NULL,
CHANGE `m_password` `m_password` VARCHAR(32) NULL,
ADD COLUMN `last_used` INT(10) UNSIGNED NOT NULL AFTER `BannedList`;
SET last_used = UNIX_TIMESTAMP();
