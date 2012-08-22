DELETE FROM `creature_loot_template` WHERE `entry` IN (31702,32297) AND `item`=44564;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(31702,44564,0.5,1,0,1,1), -- Recipe: Mighty Arcane Protection Potion on Frostbrood Spawn
(32297,44564,0.5,1,0,1,1); -- Recipe: Mighty Arcane Protection Potion on Cult Researcher
