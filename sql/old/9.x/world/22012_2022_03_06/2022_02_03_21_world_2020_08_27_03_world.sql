-- 26040 is generic reference for Frostweave Cloth, 26041 should not be used without 26040
UPDATE `creature_loot_template` SET `Item` = 26040, `Reference` = 26040, `Chance` = 35 WHERE `Entry` = 31691 AND `Reference` = 26041;
