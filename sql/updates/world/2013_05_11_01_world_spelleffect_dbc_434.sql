ALTER TABLE `spelleffect_dbc` CHANGE `EffectAplitude` `EffectAmplitude` INT(10) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `spelleffect_dbc` ADD `EffectBonusCoefficient` FLOAT UNSIGNED NOT NULL AFTER `EffectIndex`;
