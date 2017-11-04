ALTER TABLE `gameobject_template_addon` ADD COLUMN `worldeffectid` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `maxgold`;
ALTER TABLE `gameobject_addon` ADD COLUMN `worldeffectid` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0' AFTER `invisibilityValue`;
