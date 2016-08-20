ALTER TABLE `creature_addon` ADD `aiAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `emote`;
ALTER TABLE `creature_addon` ADD `movementAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `aiAnimKit`;
ALTER TABLE `creature_addon` ADD `meleeAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `movementAnimKit`;
ALTER TABLE `creature_template_addon` ADD `aiAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `emote`;
ALTER TABLE `creature_template_addon` ADD `movementAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `aiAnimKit`;
ALTER TABLE `creature_template_addon` ADD `meleeAnimKit` SMALLINT NOT NULL DEFAULT 0 AFTER `movementAnimKit`;
