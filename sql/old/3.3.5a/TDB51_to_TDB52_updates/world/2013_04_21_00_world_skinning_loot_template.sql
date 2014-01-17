-- Simplify skinloot for Axtroz and make sure something drops as well
UPDATE `skinning_loot_template` SET `ChanceOrQuestChance`=50 WHERE `entry`=12899 AND `item`=8170;
UPDATE `skinning_loot_template` SET `ChanceOrQuestChance`=35 WHERE `entry`=12899 AND `item`=15414;
UPDATE `skinning_loot_template` SET `ChanceOrQuestChance`=10 WHERE `entry`=12899 AND `item`=8165;
UPDATE `skinning_loot_template` SET `ChanceOrQuestChance`=0 WHERE `entry`=12899 AND `item`=4304;
-- Update dropchance for rare items on Axtroz
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=5 WHERE `entry`=12899 AND `mincountOrRef`=-24020;
