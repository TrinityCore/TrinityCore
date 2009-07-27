-- ALTER TABLE db_version CHANGE COLUMN required_8158_01_mangos_playercreateinfo_action required_8190_01_mangos_creature_template bit;

ALTER TABLE `creature_template`
    CHANGE COLUMN `unk1` `KillCredit1` int(11) unsigned NOT NULL default '0',
    CHANGE COLUMN `unk2` `KillCredit2` int(11) unsigned NOT NULL default '0';