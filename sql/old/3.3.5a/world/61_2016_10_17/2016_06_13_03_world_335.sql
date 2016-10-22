-- 
UPDATE `gameobject_loot_template` SET `Chance`=50, `MaxCount`=6 WHERE `Item`=2835 AND `Entry` IN (1502, 1735, 2626, 18092);
UPDATE `gameobject_loot_template` SET `Chance`=50, `MaxCount`=8 WHERE `Item`=2836 AND `Entry` IN (1503, 1736, 2627, 18093);
UPDATE `gameobject_loot_template` SET `MaxCount`=4 WHERE `Item` IN (2770, 2771) AND `Entry` IN (1502, 1503, 1735, 1736, 2626, 2627, 18092, 18093);
