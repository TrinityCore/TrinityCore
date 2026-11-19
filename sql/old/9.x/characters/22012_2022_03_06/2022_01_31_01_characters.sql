ALTER TABLE `characters` ADD `summonedPetNumber` int unsigned NOT NULL DEFAULT '0' AFTER `extra_flags`;

UPDATE `characters` SET `summonedPetNumber` = COALESCE((SELECT `id` FROM `character_pet` WHERE `owner` = `guid` AND `slot` = 0 AND `curhealth` > 0), 0);
