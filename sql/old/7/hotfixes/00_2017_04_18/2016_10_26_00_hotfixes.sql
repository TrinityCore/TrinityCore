ALTER TABLE `chr_classes` MODIFY `IconFileDataID` int(10) unsigned NOT NULL DEFAULT '0' AFTER `SelectScreenFileDataID`;

ALTER TABLE `creature_model_data`
  DROP `FootstepShakeSize`,
  DROP `DeathThudShakeSize`;

ALTER TABLE `item_class` ADD `OldEnumValue` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `Name`;

ALTER TABLE `lfg_dungeons` ADD `MinItemLevel` float NOT NULL DEFAULT '0' AFTER `PlayerConditionID`;

ALTER TABLE `spell_x_spell_visual`
  CHANGE `Unk620` `Chance` float NOT NULL DEFAULT '0' AFTER `SpellID`,
  ADD `UnitConditionID` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `PlayerConditionID`,
  CHANGE `Flags` `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `UnitConditionID`,
  ADD `Priority` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`;
