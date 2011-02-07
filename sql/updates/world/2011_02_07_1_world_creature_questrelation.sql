-- Missing relation for quest You've Been Served
INSERT INTO `creature_questrelation`(`id`,`quest`) VALUES
(38208,14488);
INSERT INTO `creature_involvedrelation`(`id`,`quest`) VALUES
(36296,14488);

-- Missing loot form Standard Apothecary Serving Kit request for quest You've Been Served
 INSERT INTO `item_loot_template`(`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES 
(49631,49352,100,1,0,1,1),
(49631,49351,100,1,0,1,1),
(49631,49635,100,1,0,1,1);
