ALTER TABLE `spelleffect_dbc`
    CHANGE `EffectPointsPerResource` `EffectPointsPerResource` FLOAT UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `EffectIndex` `EffectIndex` INT(10) UNSIGNED DEFAULT 0 NOT NULL,
    CHANGE `Comment` `Comment` VARCHAR(128) CHARSET utf8 COLLATE utf8_general_ci DEFAULT '' NOT NULL;

ALTER TABLE `spell_dbc`
    CHANGE `Comment` `Comment` VARCHAR(128) CHARSET utf8 COLLATE utf8_general_ci DEFAULT '' NOT NULL;
