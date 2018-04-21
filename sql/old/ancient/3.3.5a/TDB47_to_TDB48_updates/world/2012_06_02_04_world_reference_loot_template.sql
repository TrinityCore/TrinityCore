DELETE FROM `reference_loot_template` WHERE `entry` IN (14011,14012);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(14011,37759,0,1,1,1,1), -- Rhie-ay's Clutching Gauntlets
(14011,37768,0,1,1,1,1), -- Leggings of Violent Exsanguination
(14011,37790,0,1,1,1,1), -- Belt of Crystalline Tears
(14011,37806,0,1,1,1,1), -- Zabra's Misplaced Staff
(14011,37808,0,1,1,1,1), -- Dragonjaw Mauler
(14011,37809,0,1,1,1,1), -- Roc-Feather Longbow
(14012,3014,-70,1,0,1,1), -- Battleworn Axe
(14012,7906,-8,1,0,1,1); -- Horns of Nez'ra
UPDATE `creature_loot_template` SET `mincountOrRef`=14012 WHERE `mincountOrRef`=14011 AND `entry` IN (4464,436,437,440,485,615,4064,4065,4462,4463,435);
