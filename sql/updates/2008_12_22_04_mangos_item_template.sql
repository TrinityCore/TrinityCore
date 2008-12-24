ALTER TABLE db_version CHANGE COLUMN required_2008_12_22_03_mangos_item_template required_2008_12_22_04_mangos_item_template bit;

alter table `item_template`
    add column `StatsCount` tinyint(3) UNSIGNED DEFAULT '0' NOT NULL after `ContainerSlots`;
