DELETE FROM `reference_loot_template` WHERE `entry`=11112;
UPDATE `reference_loot_template` SET `entry`=11114 WHERE `item`= 34831 AND `entry`=11115;
DELETE FROM `item_loot_template` WHERE `entry`=35348;
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(35348,1,100,1,0,-11113,1), -- Garanteed Drops
(35348,2, 60,1,0,-11116,1), -- Rare Pets
(35348,4, 60,1,0,-11115,1), -- Junk items
(35348,3,  5,1,0,-11114,1); -- Lesser Treasures
