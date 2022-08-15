--
DELETE FROM `creature_loot_template` WHERE `Entry` IN (4625,11374,12352,27213,27414,31205);
DELETE FROM `pickpocketing_loot_template` WHERE `Entry` IN (12352);
UPDATE `creature_template` SET `lootid` = 0, `pickpocketloot` = 0 WHERE `entry` IN (4625,11374,12352,27213,27414,31205);
