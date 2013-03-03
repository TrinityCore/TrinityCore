ALTER TABLE `spell_proc_event` CHANGE COLUMN `entry` `entry` mediumint(8) unsigned NOT NULL DEFAULT '0';

DELETE FROM `spell_proc_event` WHERE `entry` IN
(44401, 58642, 58676, 61433, 61434);
