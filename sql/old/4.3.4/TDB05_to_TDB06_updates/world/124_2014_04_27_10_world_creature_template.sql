ALTER TABLE `creature_template` DROP `faction_H`;
ALTER TABLE `creature_template` CHANGE `faction_A` `faction` SMALLINT(5) UNSIGNED NOT NULL DEFAULT '0';
