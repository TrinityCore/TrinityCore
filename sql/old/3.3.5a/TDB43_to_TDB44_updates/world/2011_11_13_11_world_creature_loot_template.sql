-- Add Orders From Kael'thas to the following creatures
DELETE FROM `creature_loot_template` WHERE `item`=29797;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(18860,29797,-80,1,0,1,1), -- Daughter of Destiny
(20285,29797,-80,1,0,1,1), -- Gan'arg Warp-Tinker
(20326,29797,-80,1,0,1,1); -- Mo'arg Warp-Master
