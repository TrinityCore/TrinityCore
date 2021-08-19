ALTER TABLE `corpse` ADD `class` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `race`;

UPDATE `corpse` SET `class`=(SELECT c.`class` FROM `characters` c WHERE c.`guid`=`guid`);
