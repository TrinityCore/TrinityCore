ALTER TABLE `creature_template_difficulty` 
    ADD COLUMN `ContentExpansion` TINYINT NOT NULL DEFAULT 0 AFTER `GoldMax`;

UPDATE `creature_template_difficulty` SET `ContentExpansion`= GREATEST(0, `HealthScalingExpansion`);
