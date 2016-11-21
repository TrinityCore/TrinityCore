ALTER TABLE `char_sections` CHANGE `Id` `ID` int(10) unsigned NOT NULL DEFAULT 0 FIRST;

ALTER TABLE `chr_races`
  CHANGE `Unk` `Unk1` int(10) unsigned NOT NULL DEFAULT 0 AFTER `HighResFemaleDisplayID`,
  ADD `Unk2` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Unk1`,
  ADD `Unk3` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Unk2`;

ALTER TABLE `spell_scaling`
  CHANGE `MinScalingLevel` `MinScalingLevel` int(10) unsigned NOT NULL DEFAULT 0 AFTER `ScalingClass`,
  CHANGE `MaxScalingLevel` `MaxScalingLevel` int(10) unsigned NOT NULL DEFAULT 0 AFTER `MinScalingLevel`;
