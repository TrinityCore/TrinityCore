-- Shatterspear Amulet has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/44942
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=32860 and `item`=44942;
