-- Threshadon Chunk has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/55232
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=41137 and `item`=55232;
