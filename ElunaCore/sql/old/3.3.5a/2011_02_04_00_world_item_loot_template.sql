-- Derrok's Wand Case
DELETE FROM `item_loot_template` WHERE `entry`=30650;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(30650,30651,100,1,1,1,1), -- Dertrok's First Wand
(30650,30652,100,1,2,1,1), -- Dertrok's Second Wand
(30650,30653,100,1,3,1,1), -- Dertrok's Third Wand
(30650,30654,100,1,4,1,1); -- Dertrok's Fourth Wand
