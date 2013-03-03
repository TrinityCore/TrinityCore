ALTER TABLE `creature_template` ADD COLUMN `spell5` mediumint(8) unsigned NOT NULL default '0' AFTER `spell4`;
ALTER TABLE `creature_template` ADD COLUMN `spell6` mediumint(8) unsigned NOT NULL default '0' AFTER `spell5`;
ALTER TABLE `creature_template` ADD COLUMN `spell7` mediumint(8) unsigned NOT NULL default '0' AFTER `spell6`;
ALTER TABLE `creature_template` ADD COLUMN `spell8` mediumint(8) unsigned NOT NULL default '0' AFTER `spell7`;
