UPDATE `creature_loot_template` SET `mincountOrRef`=-10001 WHERE `mincountOrRef`=-24725;
UPDATE `gameobject_loot_template` SET `mincountOrRef`=-10001 WHERE `mincountOrRef`=-24725;
UPDATE `item_loot_template` SET `mincountOrRef`=-10001 WHERE `mincountOrRef`=-24725;

DELETE FROM `reference_loot_template` WHERE `entry`=24725;
