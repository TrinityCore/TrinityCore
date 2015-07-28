-- Priceless Rockjaw Artifact has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/49751
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=37105 and `item`=49751;
