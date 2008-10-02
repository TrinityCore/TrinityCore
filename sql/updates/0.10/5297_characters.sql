ALTER TABLE `character` RENAME TO `characters`;
ALTER TABLE `group` RENAME TO `groups`;

ALTER TABLE `character_pet`
    CHANGE COLUMN `ABData` `abdata` longtext,
    CHANGE COLUMN `TeachSpelldata` `teachspelldata` longtext;

ALTER TABLE `guild`
    CHANGE COLUMN `MOTD`  `motd` varchar(255) NOT NULL default '';

ALTER TABLE `guild_member`
    CHANGE COLUMN `Pnote`   `pnote`   varchar(255) NOT NULL default '',
    CHANGE COLUMN `OFFnote` `offnote` varchar(255) NOT NULL default '';

ALTER TABLE `guild_bank_right` 
    CHANGE COLUMN `Right` `gbright` tinyint(3) unsigned NOT NULL default '0';