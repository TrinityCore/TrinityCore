-- Stolen Powder Keg has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/58202
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry` IN (42221,42222) and `item`=58202;
