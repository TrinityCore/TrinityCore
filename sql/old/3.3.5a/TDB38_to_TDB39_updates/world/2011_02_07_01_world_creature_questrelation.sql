-- Missing relation for quest You've Been Served
DELETE FROM `creature_questrelation` WHERE `id`=38208 AND `quest`=14488;
DELETE FROM `creature_involvedrelation` WHERE `id`=36296 AND `quest`=14488;
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES (38208,14488);
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES (36296,14488);

-- Missing loot form Standard Apothecary Serving Kit request for quest You've Been Served
DELETE FROM `item_loot_template` WHERE `entry`=49631 AND `item` IN (49352,49351,49635);
INSERT INTO `item_loot_template`(`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(49631,49352,100,1,0,1,1),
(49631,49351,100,1,0,1,1),
(49631,49635,100,1,0,1,1);
