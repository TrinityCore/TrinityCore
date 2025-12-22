
ALTER TABLE `creature_addon` 
    MODIFY COLUMN `aiAnimKit` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `emote`,
    MODIFY COLUMN `movementAnimKit` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `aiAnimKit`,
    MODIFY COLUMN `meleeAnimKit` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `movementAnimKit`;

ALTER TABLE `creature_template_addon` 
    MODIFY COLUMN `aiAnimKit` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `emote`,
    MODIFY COLUMN `movementAnimKit` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `aiAnimKit`,
    MODIFY COLUMN `meleeAnimKit` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `movementAnimKit`;
