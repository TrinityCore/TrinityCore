ALTER TABLE `spell_area` CHANGE `flags` `flags` TINYINT(3) UNSIGNED NOT NULL DEFAULT '7' AFTER `gender`;
UPDATE `spell_area` SET `flags`=`flags`|4;
