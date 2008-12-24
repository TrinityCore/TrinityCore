ALTER TABLE db_version CHANGE COLUMN required_2008_12_22_12_mangos_player_levelstats required_2008_12_22_13_mangos_item_template bit;

ALTER TABLE `item_template`
    CHANGE COLUMN `TotemCategory` `TotemCategory` mediumint(9) NOT NULL default '0';
