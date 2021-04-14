-- Add loot for Hrothgar's Landing
DELETE FROM `creature_loot_template` WHERE `entry` IN (34980,34838,34839,34965);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- AURIAYA 10-man
-- Drottinn Hrothgar - http://old.wowhead.com/npc=34980
(34980,46859,-100,1,0,1,1), -- Stolen Tallstrider Leg
-- Kvaldir Reaver
(34838,46859,-100,1,0,1,1), -- Stolen Tallstrider Leg
(34838,49676,5,1,0,1,1), -- Kvaldir Attack Plans
(34838,33470,35,1,0,1,4), -- 1-4x Frostweave Cloth
(34838,1,10,1,0,-24727,1), -- 1 of Northrend scrolls
(34838,2,10,1,0,-26002,1), -- Northrend Grey Item Reference1
(34838,3,2,1,0,-35080,1), -- Northrend Green Item Reference
-- Kvaldir Mist Binder
(34839,46859,-100,1,0,1,1), -- Stolen Tallstrider Leg
(34839,49676,5,1,0,1,1), -- Kvaldir Attack Plans
(34839,33470,35,1,0,1,4), -- 1-4x Frostweave Cloth
(34839,1,10,1,0,-24727,1), -- 1 of Northrend scrolls
(34839,2,10,1,0,-26002,1), -- Northrend Grey Item Reference1
(34839,3, 2,1,0,-35080,1), -- Northrend Green Item Reference
-- Mistcaller Yngvar
(34965,46859,-100,1,0,1,1); -- Stolen Tallstrider Leg
