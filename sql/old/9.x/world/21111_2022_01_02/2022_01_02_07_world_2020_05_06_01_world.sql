-- Only from gameobjects or items
DELETE FROM `creature_loot_template` WHERE `Item` IN (11184,11185,11186,11188,11325);
-- Only from Molten Destroyer
DELETE FROM `creature_loot_template` WHERE `Item` = 11382 AND `Entry` != 11659;

-- They shouldn't have loot table
DELETE FROM `creature_loot_template` WHERE `Entry` IN (8397,9136,10637,14757);
UPDATE `creature_template` SET `lootid` = 0 WHERE `Entry` IN (8397,9136,10637,14757);
