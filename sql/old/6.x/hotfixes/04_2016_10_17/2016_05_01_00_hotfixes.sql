ALTER TABLE `battle_pet_species_locale`
  CHANGE `SourceText` `SourceText_lang` text,
  CHANGE `Description` `Description_lang` text;

ALTER TABLE `creature_display_info_locale`
  CHANGE `TextureVariation_lang1` `TextureVariation1_lang` text,
  CHANGE `TextureVariation_lang2` `TextureVariation2_lang` text,
  CHANGE `TextureVariation_lang3` `TextureVariation3_lang` text;

ALTER TABLE `gameobjects` CHANGE `Data7` `Data8` int(10) NOT NULL DEFAULT '0' AFTER `Data6`;
ALTER TABLE `gameobjects` CHANGE `Data6` `Data7` int(10) NOT NULL DEFAULT '0' AFTER `Data5`;
ALTER TABLE `gameobjects` CHANGE `Data5` `Data6` int(10) NOT NULL DEFAULT '0' AFTER `Data4`;
ALTER TABLE `gameobjects` CHANGE `Data4` `Data5` int(10) NOT NULL DEFAULT '0' AFTER `Data3`;
ALTER TABLE `gameobjects` CHANGE `Data3` `Data4` int(10) NOT NULL DEFAULT '0' AFTER `Data2`;
ALTER TABLE `gameobjects` CHANGE `Data2` `Data3` int(10) NOT NULL DEFAULT '0' AFTER `Data1`;
ALTER TABLE `gameobjects` CHANGE `Data1` `Data2` int(10) NOT NULL DEFAULT '0' AFTER `Data0`;
ALTER TABLE `gameobjects` CHANGE `Data0` `Data1` int(10) NOT NULL DEFAULT '0' AFTER `Type`;

ALTER TABLE `phase_group` RENAME `phase_x_phase_group`;
