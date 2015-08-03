DELETE FROM `creature_loot_template` WHERE `entry` IN (4356,4357) AND `item`=33085;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(4356,33085,-37,1,0,1,1), -- Feathers drop from Bloodfen Razormaw
(4357,33085,-33,1,0,1,1); -- Feathers drop from Bloodfen Lashtail
