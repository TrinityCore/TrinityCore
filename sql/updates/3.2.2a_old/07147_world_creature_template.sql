ALTER TABLE `creature_template`
DROP COLUMN `dmg_Mod`,
DROP COLUMN `rangeddmg_Mod`,
ADD COLUMN `mindmg` float NOT NULL DEFAULT '0' AFTER `rank`,
ADD COLUMN `maxdmg` float NOT NULL DEFAULT '0' AFTER `mindmg`,
ADD COLUMN `attackpower` int(10) unsigned NOT NULL DEFAULT '0' AFTER `dmgschool`,
ADD COLUMN `minrangedmg` float NOT NULL DEFAULT '0' AFTER `trainer_race`,
ADD COLUMN `maxrangedmg` float NOT NULL DEFAULT '0' AFTER `minrangedmg`,
ADD COLUMN `rangedattackpower` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `maxrangedmg`;
