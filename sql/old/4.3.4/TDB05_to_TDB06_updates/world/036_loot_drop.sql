-- Shrunken Head has Guaranteed drop rate
-- http://eu.battle.net/wow/en/item/1532
UPDATE `creature_loot_template` SET `ChanceOrQuestChance`=-100 WHERE `entry`=671 and `item`=1532; -- Bloodscalp Headhunter
DELETE FROM `creature_loot_template` WHERE `entry` IN (597,660) and `item`=1532;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(597,1532,-100,1,0,1,3), -- Bloodscalp Berserker
(660,1532,-100,1,0,1,3); -- Bloodscalp Witch Doctor
