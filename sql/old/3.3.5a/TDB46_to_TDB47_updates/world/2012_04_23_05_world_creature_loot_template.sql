-- Update the dropchance to 100% if on quest
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=21477 AND `item`=31372; -- Rocknail Flayer Carcass
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=21478 AND `item`=31373; -- Rocknail Flayer Giblets
