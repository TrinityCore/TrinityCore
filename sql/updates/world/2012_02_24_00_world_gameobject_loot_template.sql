DELETE FROM `gameobject_loot_template` WHERE `entry` IN (28058,28074,28088,28064,28082,28096) AND `item`=49908;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Deathbringer's Cache
(28058,49908,20,1,0,1,1), -- Primordial Saronite 10H
(28074,49908,20,1,0,1,1), -- Primordial Saronite 25N
(28088,49908,20,1,0,1,1), -- Primordial Saronite 25H
-- Cache of the Dreamwalker
(28064,49908,20,1,0,1,1), -- Primordial Saronite 10H
(28082,49908,20,1,0,1,1), -- Primordial Saronite 25N
(28096,49908,20,1,0,1,1); -- Primordial Saronite 25H
