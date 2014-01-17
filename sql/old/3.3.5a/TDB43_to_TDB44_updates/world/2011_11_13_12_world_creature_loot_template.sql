-- Add Heavy Scorpid Vest to Shadowsworn Thug and remove from Portal Seeker
DELETE FROM `creature_loot_template` WHERE `item`=15727;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(6005,15727,0.5,1,0,1,1); -- Shadowsworn Thug
