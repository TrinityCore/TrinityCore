CREATE TABLE `creature_loot_template` AS SELECT DISTINCT
   `loot_template`.`entry`        AS `entry`,
   `loot_template`.`item`         AS `item`,
   `loot_template`.`chance`       AS `chance`,
   `loot_template`.`questchance`  AS `questchance`
FROM `loot_template`, `creature_template` WHERE `loot_template`.`entry` = `creature_template`.`lootid`;

CREATE TABLE `gameobject_loot_template` AS SELECT DISTINCT
   `loot_template`.`entry`        AS `entry`, 
   `loot_template`.`item`         AS `item`,
   `loot_template`.`chance`       AS `chance`,
   `loot_template`.`questchance`  AS `questchance`
FROM `loot_template`, `gameobject` WHERE `loot_template`.`entry` = `gameobject`.`loot`;

CREATE TABLE `fishing_loot_template` AS SELECT 
   (`loot_template`.`entry` - 30000) AS `entry`, 
   `loot_template`.`item`  AS `item`,
   `loot_template`.`chance` AS `chance`,
   `loot_template`.`questchance`  AS `questchance`
FROM `loot_template` WHERE `loot_template`.`entry` > 30000 AND `loot_template`.`entry` < 33000;

CREATE TABLE `pickpocketing_loot_template` (
  `entry` int(11) unsigned NOT NULL default '0',
  `item` int(11) unsigned NOT NULL default '0',
  `chance` float NOT NULL default '100',
  `questchance` float NOT NULL default '0',
  PRIMARY KEY  (`entry`,`item`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Loot System';

DROP TABLE `loot_template`;
