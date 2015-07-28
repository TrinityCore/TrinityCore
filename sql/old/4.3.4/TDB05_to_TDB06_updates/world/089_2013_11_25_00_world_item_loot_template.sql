-- Fix loot for cooking book
DELETE FROM `item_loot_template` WHERE `entry` IN (46809,46810);
INSERT INTO `item_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Alliance book
(46809,44861,100,1,0,1,1), -- Recipe: Slow-Roasted Turkey
(46809,44859,100,1,0,1,1), -- Recipe: Candied Sweet Potato
(46809,44858,100,1,0,1,1), -- Recipe: Cranberry Chutney
(46809,44862,100,1,0,1,1), -- Recipe: Pumpkin Pie
(46809,44860,100,1,0,1,1), -- Recipe: Spice Bread Stuffing
-- Horde book
(46810,46806,100,1,0,1,1), -- Recipe: Slow-Roasted Turkey
(46810,46805,100,1,0,1,1), -- Recipe: Candied Sweet Potato
(46810,46804,100,1,0,1,1), -- Recipe: Cranberry Chutney
(46810,46807,100,1,0,1,1), -- Recipe: Pumpkin Pie
(46810,46803,100,1,0,1,1); -- Recipe: Spice Bread Stuffing
