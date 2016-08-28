-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=28553;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(28553, 22739, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Mountain Trout School contains Loot item Tome of Polymorph: Turtle'),
(28553, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Mountain Trout School contains Loot item Sea Turtle'),
(28553, 52326, 0, 9.98, 0, 1, 1, 1, 1, 'Gameobject Mountain Trout School contains Loot item Volatile Water'),
(28553, 53063, 0, 90, 0, 1, 1, 1, 1, 'Gameobject Mountain Trout School contains Loot item Mountain Trout');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=38652 AND `Item`=52325;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(38652, 52325, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Pool of Fire contains Loot item Volatile Fire');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=34868;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(34868, 785, 0, 100, 0, 1, 1, 1, 3, 'Gameobject Frozen Herb contains Loot item Mageroyal'),
(34868, 2450, 0, 100, 0, 1, 1, 1, 3, 'Gameobject Frozen Herb contains Loot item Briarthorn'),
(34868, 2453, 0, 100, 0, 1, 1, 1, 3, 'Gameobject Frozen Herb contains Loot item Bruiseweed');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=40346;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(40346, 52078, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Chaos Orb'),
(40346, 72816, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Distortion Greaves'),
(40346, 72817, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Time Altered Legguards'),
(40346, 72818, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Breastplate of Tarnished Bronze'),
(40346, 72819, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Chrono Boots'),
(40346, 72820, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Crown of Epochs'),
(40346, 72821, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Temporal Pauldrons'),
(40346, 72822, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Jagged Edge of Time'),
(40346, 72823, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Timeway Headgear'),
(40346, 72824, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Time Twisted Tunic'),
(40346, 72825, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Mantle of Time'),
(40346, 72826, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Robes of Fate'),
(40346, 72897, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Murozond''s Temporal Cache contains Loot item Arrow of Time');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=40354;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(40354, 52078, 0, 100, 0, 1, 0, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Chaos Orb'),
(40354, 72839, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Cowl of Highborne Sorcerors'),
(40354, 72840, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Spaulders of Eternity'),
(40354, 72841, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Demonsbane Chestguard'),
(40354, 72842, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Annihilan Helm'),
(40354, 72843, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Helm of Power'),
(40354, 72844, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Pit Lord''s Destroyer'),
(40354, 72845, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Mannoroth''s Signet'),
(40354, 72846, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Thornwood Staff'),
(40354, 72847, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Helm of Thorns'),
(40354, 72848, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Legguards of the Legion'),
(40354, 72898, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Foul Gift of the Demon Lord'),
(40354, 72899, 0, 100, 0, 1, 1, 1, 1, 'Gameobject Minor Cache of the Aspects contains Loot item Varo''then''s Brooch');
 
-- Add items to gameobject_loot_template
DELETE FROM `gameobject_loot_template` WHERE `Entry`=38644;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(38644, 22739, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Tome of Polymorph: Turtle'),
(38644, 46109, 0, 0.01, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Sea Turtle'),
(38644, 52326, 0, 9.99, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Volatile Water'),
(38644, 67597, 0, 9.99, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Sealed Crate'),
(38644, 52985, 0, 80, 0, 1, 1, 1, 1, 'Gameobject Shipwreck Debris contains Loot item Azshara''s Veil');
