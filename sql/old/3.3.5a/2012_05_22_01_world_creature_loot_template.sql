-- As of patch 3.1.0, the drop rate of Formula: Enchant Boots - Surefooted has been increased to Guaranteed (100%).
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=100 WHERE `entry`=16472 and `item`=22545;
