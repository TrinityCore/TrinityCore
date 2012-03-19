-- Dual-Blade Butcher loot fix
DELETE FROM `reference_loot_template` WHERE `item` IN (47285,47446);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES 
(34332,47285,0,1,1,1,1), -- normal
(34346,47446,0,1,1,1,1); -- heroic
