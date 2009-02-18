ALTER TABLE `guild_bank_tab`
  CHANGE COLUMN `TabText` `TabText` text;

ALTER TABLE `character_aura` ADD `stackcount` INT NOT NULL DEFAULT '1' AFTER `effect_index` ;
ALTER TABLE `pet_aura` ADD `stackcount` INT NOT NULL DEFAULT '1' AFTER `effect_index`;

