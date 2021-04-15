ALTER TABLE `character_aura`
    ADD COLUMN `base_amount0` INT(11) NOT NULL DEFAULT '0' AFTER `amount2`,
    ADD COLUMN `base_amount1` INT(11) NOT NULL DEFAULT '0' AFTER `base_amount0`,
    ADD COLUMN `base_amount2` INT(11) NOT NULL DEFAULT '0' AFTER `base_amount1`,
    ADD COLUMN `recalculate_mask` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `effect_mask`;
