ALTER TABLE db_version CHANGE COLUMN required_2008_12_22_04_mangos_item_template required_2008_12_22_07_mangos_quest_template bit;

alter table `quest_template`
    add column `PlayersSlain` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `CharTitleId`,
    add column `BonusTalents` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `PlayersSlain`;
