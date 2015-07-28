-- Recovered Possession has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/57987
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=42184 and `item`=57987;
