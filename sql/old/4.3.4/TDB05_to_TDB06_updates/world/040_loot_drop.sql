-- Demonic Rune Stone has High drop rate
-- http://eu.battle.net/wow/en/item/28513
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-75 WHERE `entry` IN (16950,18975,18981,19190,19282) and `item`=28513;
