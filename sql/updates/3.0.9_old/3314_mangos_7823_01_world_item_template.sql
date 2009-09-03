/*ALTER TABLE db_version CHANGE COLUMN required_7796_02_mangos_mangos_string required_7823_01_mangos_item_template bit;*/

ALTER TABLE item_template
CHANGE COLUMN ScalingStatValue ScalingStatValue int(6) unsigned NOT NULL default '0';
