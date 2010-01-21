ALTER TABLE `creature_template`
DROP COLUMN `mindmg`,
DROP COLUMN `maxdmg`,
DROP COLUMN `attackpower`,
DROP COLUMN `minrangedmg`,
DROP COLUMN `maxrangedmg`,
DROP COLUMN `rangedattackpower`;

ALTER TABLE `creature_template`
ADD COLUMN `Dmg_Mod`  float NOT NULL DEFAULT 1 AFTER `Armor_Mod`,
ADD COLUMN `Rangeddmg_Mod`  float NOT NULL DEFAULT 1 AFTER `Dmg_Mod`;
