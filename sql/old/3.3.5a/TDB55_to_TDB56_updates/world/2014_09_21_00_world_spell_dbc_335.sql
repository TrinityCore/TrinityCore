ALTER TABLE `spell_dbc`  ADD `EffectItemType1` INT(10) UNSIGNED NOT NULL DEFAULT '0'  AFTER `EffectMultipleValue3`;
ALTER TABLE `spell_dbc`  ADD `EffectItemType2` INT(10) UNSIGNED NOT NULL DEFAULT '0'  AFTER `EffectItemType1`;
ALTER TABLE `spell_dbc`  ADD `EffectItemType3` INT(10) UNSIGNED NOT NULL DEFAULT '0'  AFTER `EffectItemType2`;

UPDATE `spell_dbc` SET `EffectItemType1`=30616 WHERE `Id`=37064;
