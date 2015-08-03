-- Increase dropchance for Venture Co. Explosives
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-10 WHERE `entry` IN(28123,28124) AND `item`=39651;
