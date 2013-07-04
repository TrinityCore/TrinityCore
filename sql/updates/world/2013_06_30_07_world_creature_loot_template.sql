-- Gnomish Grenades have Very High drop chance
-- http://eu.battle.net/wow/en/item/34772
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-90 WHERE `entry`=25449 and `item`=34772;
