-- Make Fjola drop two items from her loot table
-- 10 Normal
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=34497 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=34497 AND `item`=1;
-- 25 Normal
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35350 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35350 AND `item`=1;
-- 10 Heroic
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35351 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35351 AND `item`=1;
-- 25 Herioc
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35352 AND `item`=2;
UPDATE `creature_loot_template` SET `maxcount`=2 WHERE `entry`=35352 AND `item`=1;
