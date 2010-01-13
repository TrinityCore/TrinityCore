ALTER TABLE `creature_template`
  CHANGE COLUMN heroic_entry difficulty_entry_1 mediumint(8) unsigned NOT NULL default '0';
ALTER TABLE `creature_template` ADD `difficulty_entry_2` MEDIUMINT(8) unsigned
 NOT NULL default 0 AFTER `difficulty_entry_1`;
ALTER TABLE `creature_template` ADD `difficulty_entry_3` MEDIUMINT(8) unsigned
 NOT NULL default 0 AFTER `difficulty_entry_2`;