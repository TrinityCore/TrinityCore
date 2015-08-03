ALTER TABLE `creature_classlevelstats` ADD `basehp3` smallint(6) NOT NULL DEFAULT '1' AFTER `basehp2`;

ALTER TABLE `creature_classlevelstats` CHANGE `basehp0` `basehp0` smallint(6) NOT NULL DEFAULT '1';
ALTER TABLE `creature_classlevelstats` CHANGE `basehp1` `basehp1` smallint(6) NOT NULL DEFAULT '1';
ALTER TABLE `creature_classlevelstats` CHANGE `basehp2` `basehp2` smallint(6) NOT NULL DEFAULT '1';
ALTER TABLE `creature_classlevelstats` CHANGE `basemana` `basemana` smallint(6) NOT NULL DEFAULT '1';
ALTER TABLE `creature_classlevelstats` CHANGE `basearmor` `basearmor` smallint(6) NOT NULL DEFAULT '1';
