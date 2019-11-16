-- Hotfix (2010-02-18): The drop rate of Frost Lotus, from herbs in Northrend, has been increased by 50%. From 5% to 7.5%
UPDATE `gameobject_loot_template` SET `Chance` = 7.5 WHERE `Entry` = 24093 AND `Item` = 36908;
UPDATE `gameobject_loot_template` SET `Chance` = 7.5 WHERE `Entry` = 24224 AND `Item` = 36908;
UPDATE `gameobject_loot_template` SET `Chance` = 7.5 WHERE `Entry` = 24225 AND `Item` = 36908;
UPDATE `gameobject_loot_template` SET `Chance` = 7.5 WHERE `Entry` = 24226 AND `Item` = 36908;
UPDATE `gameobject_loot_template` SET `MaxCount` = 1, `Chance` = 7.5 WHERE `Entry` = 24227 AND `Item` = 36908;
UPDATE `gameobject_loot_template` SET `Chance` = 7.5 WHERE `Entry` = 25089 AND `Item` = 36908;
UPDATE `gameobject_loot_template` SET `Chance` = 7.5 WHERE `Entry` = 25093 AND `Item` = 36908;
