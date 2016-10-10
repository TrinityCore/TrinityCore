--
ALTER TABLE `creature_template_addon` ADD COLUMN `visibilityRange` INT(3) UNSIGNED DEFAULT 0 NOT NULL AFTER `emote`;
ALTER TABLE `gameobject_template_addon` ADD COLUMN `visibilityRange` INT(3) UNSIGNED DEFAULT 0 NOT NULL AFTER `maxgold`;
