UPDATE `creature_loot_template` SET `Chance` = 80 WHERE `Entry` = 95226 AND `Item` = 128227;
DELETE FROM smart_scripts WHERE entryorguid = 93105;
UPDATE creature_template SET AIName = "" WHERE entry = 93105;
