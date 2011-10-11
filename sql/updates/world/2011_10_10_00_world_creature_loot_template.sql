-- Fixes the loot for the NPC Core Hound
DELETE FROM `creature_loot_template` WHERE `item`=11370 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21595 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21590 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21593 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21592 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21589 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21562 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21559 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21561 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21557 AND `entry`=11671;
DELETE FROM `creature_loot_template` WHERE `item`=21558 AND `entry`=11671;

-- Changes the drop chance of Item ID 20951 to 100% (should be like this since patch 3.0.9)


UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE `item`=20951;