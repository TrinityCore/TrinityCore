-- Webwood Spider Silk has Very High drop rate
-- http://eu.battle.net/wow/en/item/3412
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-90 WHERE `entry` IN (1998,1999,2000,2001) and `item`=3412;
