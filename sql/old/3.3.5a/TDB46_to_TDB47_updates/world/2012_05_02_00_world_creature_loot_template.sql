DELETE FROM `creature_loot_template` WHERE `entry` IN(38064,38103);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Precious 25 man
(38103,1,100,1,0,-35069,2), -- Two From ICC Trashgenerated on Precious
(38103,52019,30,1,0,1,1), -- Precious Ribbon on Precious
(38064,1,100,1,0,-35069,2); -- Two From ICC Trashgenerated on Stinky
-- add skinning loot for Stinky & Precious
UPDATE `creature_template` SET `skinloot`=70214 WHERE `entry` IN (37025,38064,37217,38103);
