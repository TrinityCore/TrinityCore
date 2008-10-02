ALTER TABLE `character_pet` ADD `CreatedBySpell` int(11) unsigned NOT NULL default '0' AFTER `modelid`;
ALTER TABLE `character_pet` ADD `PetType` tinyint(3) unsigned NOT NULL default '0' AFTER `CreatedBySpell`;
UPDATE `character_pet` SET `PetType` = 1, `CreatedBySpell` = 1515 WHERE (`entry` <> 416 AND `entry` <> 417 AND `entry` <> 1860 AND `entry` <> 1863 AND `entry` <> 17252 AND `entry` <> 510);
UPDATE `character_pet` SET `CreatedBySpell` = 688 WHERE (`entry` = 416);
UPDATE `character_pet` SET `CreatedBySpell` = 691 WHERE (`entry` = 417);
UPDATE `character_pet` SET `CreatedBySpell` = 697 WHERE (`entry` = 1860);
UPDATE `character_pet` SET `CreatedBySpell` = 712 WHERE (`entry` = 1863);
UPDATE `character_pet` SET `CreatedBySpell` = 30146 WHERE (`entry` = 17252);
UPDATE `character_pet` SET `CreatedBySpell` = 31687 WHERE (`entry` = 510);