-- Fluffy Fox Tail has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/60755
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry` IN (44635,45380) and `item`=60755;
