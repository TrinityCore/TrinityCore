ALTER TABLE `custom_texts` ADD COLUMN `emote` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL AFTER `language`;
ALTER TABLE `eventai_texts` ADD COLUMN `emote` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL AFTER `language`;
ALTER TABLE `script_texts` ADD COLUMN `emote` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL AFTER `language`;
