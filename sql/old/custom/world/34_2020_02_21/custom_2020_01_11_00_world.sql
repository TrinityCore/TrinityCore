ALTER TABLE `spell_area` CHANGE `autocast` `flags` TINYINT(3) UNSIGNED NOT NULL DEFAULT '3' AFTER `gender`;
UPDATE `spell_area` SET `flags`=`flags` | 2;
