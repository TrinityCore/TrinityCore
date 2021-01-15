DELETE FROM `gameobject_loot_template` WHERE `entry` IN (27743,27742,27741,27740);
INSERT INTO `gameobject_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(27743,49746,-100,1,0,1,1), -- Cask of Gnomenbrau
(27742,49744,-100,1,0,1,1), -- Keg of Stormhammer Stout
(27741,49745,-100,1,0,1,1), -- Keg of Theramore Pale Ale
(27740,49749,-100,1,0,1,1); -- Forgotten Dwarven Artifact
