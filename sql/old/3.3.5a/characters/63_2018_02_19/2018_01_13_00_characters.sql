ALTER TABLE `character_aura`
ADD COLUMN `critChance` FLOAT NOT NULL DEFAULT '0' AFTER `remainCharges`,
ADD COLUMN `applyResilience` TINYINT(3) NOT NULL DEFAULT '0' AFTER `critChance`;

ALTER TABLE `pet_aura`
ADD COLUMN `critChance` FLOAT NOT NULL DEFAULT '0' AFTER `remainCharges`,
ADD COLUMN `applyResilience` TINYINT(3) NOT NULL DEFAULT '0' AFTER `critChance`;
