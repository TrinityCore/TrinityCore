-- Correct dropchance for Mote of Life, wowhead was wrong (as usual)
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=18.5307 WHERE `entry`=22307 AND `item`=22575;
