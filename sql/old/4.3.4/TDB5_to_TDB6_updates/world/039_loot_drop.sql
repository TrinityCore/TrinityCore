-- Burning Legion Gate Key has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/29795
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=19298 and `item`=29795;
