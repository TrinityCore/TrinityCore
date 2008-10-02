ALTER TABLE `quest_template` ADD COLUMN `Repeatable` tinyint(1) unsigned NOT NULL default '0';

UPDATE `quest_template` SET `Repeatable`='1' WHERE `SpecialFlags`&'32'='32';