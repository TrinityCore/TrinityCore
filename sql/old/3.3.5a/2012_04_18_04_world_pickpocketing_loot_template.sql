-- implement missing Northrend pickpocket loot
-- reference IDs
SET @NEWREF0 := 10026;
SET @NEWREF1 := @NEWREF0+1;
SET @NEWREF2 := @NEWREF0+2;
SET @NEWREF3 := @NEWREF0+3;
SET @NEWREF4 := @NEWREF0+4;
SET @NEWREF5 := @NEWREF0+5;
SET @NEWREF6 := @NEWREF0+6;
SET @NEWREF7 := @NEWREF0+7;
SET @NEWREF8 := @NEWREF0+8;
SET @NEWREF9 := @NEWREF0+9;
-- new references
DELETE FROM `reference_loot_template` WHERE entry IN (@NEWREF0, @NEWREF1, @NEWREF2, @NEWREF3, @NEWREF4, @NEWREF5, @NEWREF6, @NEWREF7, @NEWREF8, @NEWREF9);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`mincountOrRef`,`maxcount`) VALUES
(@NEWREF0,33447,25,1,1),-- Runic Healing Potion
(@NEWREF0,35953,30,1,1),-- Mead Basted Caribou
(@NEWREF0,38260,50,1,1),-- Empty Tobacco Pouch
(@NEWREF0,43575,80,1,1),-- Reinforced Junkbox
(@NEWREF1,36862,4,1,1),-- Wrogn Troll Dice
(@NEWREF1,40202,20,1,1),-- Sizzling Grizzly Flank
(@NEWREF2,33452,30,1,1),-- Honey-Spiced Lichen
(@NEWREF2,38269,35,1,1),-- Soggy Handkerchief
(@NEWREF3,33454,15,1,1),-- Salted Venison
(@NEWREF3,38261,13,1,1),-- Ben House Key
(@NEWREF4,38263,19,1,1),-- Too-Small Amband
(@NEWREF4,38264,18,1,1),-- A Very Pretty Rock
(@NEWREF5,29448,9,1,1),-- Mag'har Mild Cheese
(@NEWREF5,29450,13,1,1),-- Telaari Grapes
(@NEWREF5,37467,40,1,1),-- A Steamy Romance Novel: Forbidden Love
(@NEWREF6,35947,25,1,1),-- Sparkling Frostcap
(@NEWREF6,38269,40,1,1),-- Soggy Handkerchief
(@NEWREF7,33447,25,1,1),-- Runic Healing Potion
(@NEWREF7,35947,25,1,1),-- Sparkling Frostcap
(@NEWREF7,38269,40,1,1),-- Soggy Handkerchief
(@NEWREF7,43575,80,1,1),-- Reinforced Junkbox
(@NEWREF8,35948,11,1,1),-- Savory Snowplum
(@NEWREF8,35950,9,1,1),-- Sweet Potato Bread
(@NEWREF8,35952,8,1,1),-- Briny Hardcheese
(@NEWREF9,33447,25,1,1),-- Runic Healing Potion
(@NEWREF9,38260,50,1,1),-- Empty Tobacco Pouch
(@NEWREF9,43575,80,1,1); -- Reinforced Junkbox
-- implement pickpokect loot
UPDATE `creature_template` SET `pickpocketloot`=entry WHERE `entry` IN (25800,23667,23674,23760,23796,23865,23875,23963,24069,24262,24400,24460,25351,25427,25428,25429,25430,25601,25801,26073,26202,26334,26413,26447,26480,26481,26620,26621,26624,26626,26635,26636,26637,26639,26658,26681,26696,26727,26729,26800,26802,26836,26948,27105,27210,27211,/**/27234,27235,27247,27278,27289,27334,27342,27431,27533,27580,27639,27640,27699,27800,27859,27860,27961,27964,27965,28494,28496,28565,28803,28837,28838,28848,28961,28965,29369,29407,29553,29554,29656,29793,29820,29822,29836,29874,29875,29885,29920,30283,30319,30856,30868,31396,31554,32263);
UPDATE `creature_template` SET `pickpocketloot`=25430 WHERE `entry` IN (23654,23656,23663,23665,25434,26728,26827,26926,27554,32572);
UPDATE `creature_template` SET `pickpocketloot`=26481 WHERE `entry` IN (23662,23940,24016,24161,26493,26655,27007,27009);
UPDATE `creature_template` SET `pickpocketloot`=25351 WHERE `entry` IN (23993,24540,25224,25383,26343,26492,26891,26946,27224,27226,27283,27360,27552,27799,27823,27826,28564,28750);
UPDATE `creature_template` SET `pickpocketloot`=27533 WHERE `entry` IN (26555,26669,26670,26694,26830,27871,28022,28108,28242,28268,28419,29123,29133,29722,29738,30701,30894,30922,30949,31139,31150,31779,31847,32278,32505);
UPDATE `creature_template` SET `pickpocketloot`=30319 WHERE `entry` IN (30111,30179);
DELETE FROM `pickpocketing_loot_template` WHERE entry IN (25800,23656,23662,23663,23665,23667,23674,23760,23796,23865,23875,23940,23963,23993,24016,24069,24161,24262,24400,24460,24540,25224,25351,25383,25427,25428,25429,25430,25434,25601,25801,26073,26202,26334,26343,26413,26447,26480,26481,26492,26493,26555,26620,26621,26624,26626,26635,26636,26637,26639,26655,26658,26669,26670,26681,26694,26696,26727,26728,26729,26800,26802,26827,26830,26836,26891,26926,26946,26948,27007,27009,27105,27210,27211,27224,27226,27234,27235,27247,27278,27283,27289,27334,27342,27360,27431,27533,27552,27554,27580,27639,27640,27699,27799,27800,27823,27826,27859,27860,27871,27961,27964,27965,28022,28108,28242,28268,28419,28494,28496,28564,28565,28750,28803,28837,28838,28848,28961,28965,29123,29133,29369,29407,29553,29554,29656,29722,29738,29793,29820,29822,29836,29874,29875,29885,29920,30111,30179,30283,30319,30701,30856,30868,30894,30922,30949,31139,31150,31396,31554,31779,31847,32263,32278,32505,32572);
INSERT INTO `pickpocketing_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Plague Walker
(30283,43575,100,0,1,1),-- Reinforced Junkbox
(30283,0,100,0,-@NEWREF6,1),
-- Twilight Darkcaster
(30319,0,100,0,-@NEWREF0,1),
(30319,33449,11,0,1,1),-- Crusty Flatbread
(30319,1,100,0,-@NEWREF1,1),
(30319,2,100,0,-@NEWREF3,1),
-- High Priest Talet-Kha
(26073,43575,58,0,1,1),-- Reinforced Junkbox
(26073,0,100,0,-@NEWREF5,1),
(26073,33449,8,0,1,1),-- Crusty Flatbread
(26073,33447,8,0,1,1),-- Runic Healing Potion
-- Nedar, Lord of Rhinos
(25801,0,100,0,-@NEWREF5,1),
(25801,33447,6,0,1,1),-- Runic Healing Potion
(25801,38261,6,0,1,1),-- Bent House Key
-- Clam Master K
(25800,43575,47,0,1,1),-- Reinforced Junkbox
(25800,0,100,0,-@NEWREF5,1),
(25800,38261,15,0,1,1),-- Bent House Key
(25800,33449,5,0,1,1),-- Crusty Flatbread
(25800,33447,5,0,1,1),-- Runic Healing Potion
-- Magmothregar
(25430,0,100,0,-@NEWREF3,1),
(25430,1,100,0,-@NEWREF9,1),
(25430,33449,7,0,1,1),-- Crusty Flatbread
(25430,36862,4,0,1,1),-- Wrogn Troll Dice
-- Kaganishu
(25427,43575,43,0,1,1),-- Reinforced Junkbox
(25427,33454,35,0,1,1),-- Salted Venison
(25427,0,100,0,-@NEWREF4,1),
(25427,33447,8,0,1,1),-- Runic Healing Potion
-- Prince Valanar
(25601,43575,43,0,1,1),-- Reinforced Junkbox
(25601,37467,39,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(25601,33447,9,0,1,1),-- Runic Healing Potion
(25601,38261,9,0,1,1),-- Bent House Key
(25601,33449,4,0,1,1),-- Crusty Flatbread
(25601,29450,4,0,1,1),-- Telaari Grapes
-- Ghostly Sage
(25351,43575,42,0,1,1),-- Reinforced Junkbox
(25351,0,100,0,-@NEWREF2,1),
(25351,33447,10,0,1,1),-- Runic Healing Potion
-- Luthion the Vile
(27860,43575,42,0,1,1),-- Reinforced Junkbox
(27860,0,100,0,-@NEWREF5,1),
(27860,38261,13,0,1,1),-- Bent House Key
(27860,33449,6,0,1,1),-- Crusty Flatbread
(27860,33447,6,0,1,1),-- Runic Healing Potion
-- Reckless Scavenger
(26658,0,100,0,-@NEWREF2,1),
(26658,43575,40,0,1,1),-- Reinforced Junkbox
-- Ziggurat Defender
(26202,43575,40,0,1,1),-- Reinforced Junkbox
(26202,0,100,0,-@NEWREF2,1),
(26202,33447,7,0,1,1),-- Runic Healing Potion
(26202,29569,3,0,1,1),-- Strong Junkbox
-- Magmoth Forager
(25429,43575,39,0,1,1),-- Reinforced Junkbox
(25429,33454,27,0,1,1),-- Salted Venison
(25429,0,100,0,-@NEWREF4,1),
(25429,33447,10,0,1,1),-- Runic Healing Potion
(25429,38266,0.5,0,1,1),-- Rotund Relic
-- Magmoth Shaman
(25428,43575,39,0,1,1),-- Reinforced Junkbox
(25428,33454,28,0,1,1),-- Salted Venison
(25428,0,100,0,-@NEWREF4,1),
(25428,33447,9,0,1,1),-- Runic Healing Potion
(25428,38266,0.5,0,1,1),-- Rotund Relic
-- Vanthryn the Merciless
(27859,43575,39,0,1,1),-- Reinforced Junkbox
(27859,0,100,0,-@NEWREF5,1),
(27859,33449,12,0,1,1),-- Crusty Flatbread
(27859,38261,12,0,1,1),-- Bent House Key
(27859,33447,3,0,1,1),-- Runic Healing Potion
-- Unbound Corrupter
(30868,43575,47,0,1,1),-- Reinforced Junkbox
(30868,40202,18,0,1,1),-- Sizzling Grizzly Flank
(30868,33447,16,0,1,1),-- Runic Healing Potion
(30868,0,100,0,-@NEWREF4,1),
-- Unbound Trickster
(30856,43575,38,0,1,1),-- Reinforced Junkbox
(30856,0,100,0,-@NEWREF4,1),
(30856,33447,19,0,1,1),-- Runic Healing Potion
(30856,40202,14,0,1,1),-- Sizzling Grizzly Flank
-- Kreug Oathbreaker
(27105,43575,63,0,1,1),-- Reinforced Junkbox
(27105,33447,25,0,1,1),-- Runic Healing Potion
(27105,38269,13,0,1,1),-- Soggy Handkerchief
-- Lead Cannoneer Zierhut
(27235,43575,53,0,1,1),-- Reinforced Junkbox
(27235,0,100,0,-@NEWREF5,1),
(27235,33447,8,0,1,1),-- Runic Healing Potion
(27235,38261,8,0,1,1),-- Bent House Key
-- Devout Bodyguard
(27247,43575,50,0,1,1),-- Reinforced Junkbox
(27247,37467,42,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(27247,33447,8,0,1,1),-- Runic Healing Potion
(27247,29450,8,0,1,1),-- Telaari Grapes
(27247,38261,8,0,1,1),-- Bent House Key
-- Magnataur Alpha
(26481,0,100,0,-@NEWREF9,1),
(26481,1,100,0,-@NEWREF3,1),
(26481,33449,5,0,1,1),-- Crusty Flatbread
-- High General Abbendis
(27210,43575,48,0,1,1),-- Reinforced Junkbox
(27210,0,100,0,-@NEWREF5,1),
(27210,33449,10,0,1,1),-- Crusty Flatbread
(27210,33447,10,0,1,1),-- Runic Healing Potion
(27210,38261,8,0,1,1),-- Bent House Key
-- Anub'ar Dreadweaver
(26413,43575,44,0,1,1),-- Reinforced Junkbox
(26413,43576,22,0,1,1),-- Chitin Polish
(26413,33452,11,0,1,1),-- Honey-Spiced Lichen
(26413,33447,11,0,1,1),-- Runic Healing Potion
(26413,43577,11,0,1,1),-- Carapace Cleanser
-- Naxxramas Necrolord
(27289,33452,44,0,1,1),-- Honey-Spiced Lichen
(27289,43575,44,0,1,1),-- Reinforced Junkbox
(27289,33447,11,0,1,1),-- Runic Healing Potion
-- Onslaught Commander Iustus
(27334,37467,50,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(27334,43575,44,0,1,1),-- Reinforced Junkbox
(27334,29448,13,0,1,1),-- Mag'har Mild Cheese
(27334,38261,6,0,1,1),-- Bent House Key
-- Blacksmith Goodman
(27234,43575,41,0,1,1),-- Reinforced Junkbox
(27234,0,100,0,-@NEWREF5,1),
(27234,38261,13,0,1,1),-- Bent House Key
(27234,33447,9,0,1,1),-- Runic Healing Potion
(27234,33449,7,0,1,1),-- Crusty Flatbread
-- Magnataur Youngling
(26480,33449,19,0,1,1),-- Crusty Flatbread
(26480,0,100,0,-@NEWREF3,1),
(26480,1,100,0,-@NEWREF9,1),
-- Bloodpaw Warrior
(27342,43575,40,0,1,1),-- Reinforced Junkbox
(27342,33454,26,0,1,1),-- Salted Venison
(27342,0,100,0,-@NEWREF4,1),
(27342,33447,11,0,1,1),-- Runic Healing Potion
(27342,38266,0.6,0,1,1),-- Rotund Relic
-- Frigid Geist
(27533,0,100,0,-@NEWREF7,1),
-- Snowplain Zealot
(27278,43575,40,0,1,1),-- Reinforced Junkbox
(27278,33454,22,0,1,1),-- Salted Venison
(27278,0,100,0,-@NEWREF4,1),
(27278,33447,12,0,1,1),-- Runic Healing Potion
(27278,38266,0.3,0,1,1),-- Rotund Relic
-- Hulking Atrocity
(26948,43575,39,0,1,1),-- Reinforced Junkbox
(26948,0,100,0,-@NEWREF2,1),
(26948,33447,9,0,1,1),-- Runic Healing Potion
(26948,29569,0.3,0,1,1),-- Strong Junkbox
(26948,38268,0.3,0,1,1),-- Spare Hand
-- Onslaught Executioner
(27211,43575,39,0,1,1),-- Reinforced Junkbox
(27211,0,100,0,-@NEWREF5,1),
(27211,33449,12,0,1,1),-- Crusty Flatbread
(27211,38261,11,0,1,1),-- Bent House Key
(27211,33447,5,0,1,1),-- Runic Healing Potion
-- Gigantaur
(26836,0,100,0,-@NEWREF9,1),
(26836,1,100,0,-@NEWREF3,1),
(26836,33449,12,0,1,1),-- Crusty Flatbread
-- Leprous Servant
(27800,43575,38,0,1,1),-- Reinforced Junkbox
(27800,0,100,0,-@NEWREF2,1),
(27800,33447,7,0,1,1),-- Runic Healing Potion
(27800,38268,2,0,1,1),-- Spare Hand
-- Wretched Belcher
(26624,43575,100,0,1,1),-- Reinforced Junkbox
(26624,0,100,0,-@NEWREF2,1),
(26624,33447,25,0,1,1),-- Runic Healing Potion
(26624,35947,25,0,1,1),-- Sparkling Frostcap
-- Drakkari Commander
(27431,43575,90,0,1,1),-- Reinforced Junkbox
(27431,0,100,0,-@NEWREF2,1),
(27431,33447,26,0,1,1),-- Runic Healing Potion
(27431,35947,10,0,1,1),-- Sparkling Frostcap
-- Drakkari Guardian
(26620,0,100,0,-@NEWREF0,1),
(26620,33454,17,0,1,1),-- Salted Venison
(26620,33449,9,0,1,1),-- Crusty Flatbread
(26620,38261,9,0,1,1),-- Bent House Key
(26620,1,100,0,-@NEWREF1,1),
-- Risen Drakkari Soulmage
(26636,43575,85,0,1,1),-- Reinforced Junkbox
(26636,0,100,0,-@NEWREF2,1),
(26636,35947,21,0,1,1),-- Sparkling Frostcap
(26636,33447,16,0,1,1),-- Runic Healing Potion
-- Ghoul Tormentor
(26621,43575,81,0,1,1),-- Reinforced Junkbox
(26621,0,100,0,-@NEWREF2,1),
(26621,35947,24,0,1,1),-- Sparkling Frostcap
(26621,33447,14,0,1,1),-- Runic Healing Potion
-- Risen Drakkari Warrior
(26635,43575,71,0,1,1),-- Reinforced Junkbox
(26635,0,100,0,-@NEWREF2,1),
(26635,33447,29,0,1,1),-- Runic Healing Potion
(26635,35947,18,0,1,1),-- Sparkling Frostcap
(26635,38268,0.8,0,1,1),-- Spare Hand
-- Risen Drakkari Handler
(26637,0,100,0,-@NEWREF2,1),
(26637,43575,67,0,1,1),-- Reinforced Junkbox
(26637,33447,30,0,1,1),-- Runic Healing Potion
(26637,35947,18,0,1,1),-- Sparkling Frostcap
-- Scourge Reanimator
(26626,0,100,0,-@NEWREF2,1),
(26626,43575,67,0,1,1),-- Reinforced Junkbox
(26626,33447,21,0,1,1),-- Runic Healing Potion
(26626,35947,21,0,1,1),-- Sparkling Frostcap
-- Drakkari Shaman
(26639,0,100,0,-@NEWREF0,1),
(26639,33449,18,0,1,1),-- Crusty Flatbread
(26639,1,100,0,-@NEWREF3,1),
(26639,40202,11,0,1,1),-- Sizzling Grizzly Flank
-- Selas
(27580,43575,50,0,1,1),-- Reinforced Junkbox
(27580,0,100,0,-@NEWREF3,1),
(27580,38260,20,0,1,1),-- Empty Tobacco Pouch
-- Forgemaster Damrath
(26334,43575,48,0,1,1),-- Reinforced Junkbox
(26334,0,100,0,-@NEWREF5,1),
(26334,33447,9,0,1,1),-- Runic Healing Potion
(26334,38261,9,0,1,1),-- Bent House Key
-- Grumbald One-Eye
(26681,43575,39,0,1,1),-- Reinforced Junkbox
(26681,33454,28,0,1,1),-- Salted Venison
(26681,0,100,0,-@NEWREF4,1),
(26681,33447,9,0,1,1),-- Runic Healing Potion
-- Drakkari Shaman
(26447,0,100,0,-@NEWREF9,1),
(26447,1,100,0,-@NEWREF3,1),
(26447,33449,10,0,1,1),-- Crusty Flatbread
(26447,35799,0.2,0,1,1),-- Frozen Mojo
(26447,36862,0.2,0,1,1),-- Wrogn Troll Dice
-- Drakkari God Hunter
(29820,0,100,0,-@NEWREF0,1),
(29820,1,100,0,-@NEWREF1,1),
-- Drakkari Battle Rider
(29836,0,100,0,-@NEWREF0,1),
(29836,40202,18,0,1,1),-- Sizzling Grizzly Flank
-- Ruins Dweller
(29920,43575,71,0,1,1),-- Reinforced Junkbox
(29920,37452,69,0,1,1),-- Fatty Bluefin
(29920,38274,58,0,1,1),-- Large Snail Shell
(29920,38273,35,0,1,1),-- Brain Coral
(29920,33447,16,0,1,1),-- Runic Healing Potion
-- Drakkari Fire Weaver
(29822,0,100,0,-@NEWREF0,1),
(29822,40202,24,0,1,1),-- Sizzling Grizzly Flank
-- Drakkari Inciter
(29874,0,100,0,-@NEWREF0,1),
(29874,36862,16,0,1,1),-- Wrogn Troll Dice
(29874,40202,12,0,1,1),-- Sizzling Grizzly Flank
-- Titanium Siegebreaker
(28961,0,100,0,-@NEWREF0,1),
(28961,40202,35,0,1,1),-- Sizzling Grizzly Flank
-- Stormforged Sentinel
(28837,0,100,0,-@NEWREF0,1),
(28837,40202,16,0,1,1),-- Sizzling Grizzly Flank
-- Titanium Thunderer
(28965,0,100,0,-@NEWREF0,1),
(28965,40202,44,0,1,1),-- Sizzling Grizzly Flank
-- Titanium Vanguard
(28838,0,100,0,-@NEWREF0,1),
(28838,40202,27,0,1,1),-- Sizzling Grizzly Flank
-- Dark Rune Scholar
(27964,0,100,0,-@NEWREF9,1),
(27964,1,100,0,-@NEWREF1,1),
-- Dark Rune Worker
(27961,0,100,0,-@NEWREF0,1),
(27961,40202,29,0,1,1),-- Sizzling Grizzly Flank
(27961,36862,4,0,1,1),-- Wrogn Troll Dice
-- Dark Rune Shaper
(27965,0,100,0,-@NEWREF0,1),
(27965,40202,28,0,1,1),-- Sizzling Grizzly Flank
-- Steel Gate Archaeologist
(24400,0,100,0,-@NEWREF0,1),
(24400,1,100,0,-@NEWREF5,1),
(24400,33449,7,0,1,1),-- Crusty Flatbread
(24400,38261,9,0,1,1),-- Bent House Key
-- Blacksouled Keeper
(23875,0,100,0,-@NEWREF0,1),
(23875,1,100,0,-@NEWREF3,1),
(23875,33449,14,0,1,1),-- Crusty Flatbread
-- Winterskorn Rune-Seer
(23667,0,100,0,-@NEWREF0,1),
(23667,33449,7,0,1,1),-- Crusty Flatbread
(23667,33454,7,0,1,1),-- Salted Venison
-- Sergeant Lorric
(23963,43575,45,0,1,1),-- Reinforced Junkbox
(23963,0,100,0,-@NEWREF5,1),
(23963,33447,13,0,1,1),-- Runic Healing Potion
(23963,38261,11,0,1,1),-- Bent House Key
(23963,33449,7,0,1,1),-- Crusty Flatbread
-- Gjalerhorn Scavenger
(27699,0,100,0,-@NEWREF4,1),
(27699,43575,43,0,1,1),-- Reinforced Junkbox
(27699,33454,22,0,1,1),-- Salted Venison
(27699,33447,7,0,1,1),-- Runic Healing Potion
(27699,29569,0.8,0,1,1),-- Strong Junkbox
-- Iron Rune Binder
(23796,0,100,0,-@NEWREF5,1),
(23796,43575,42,0,1,1),-- Reinforced Junkbox
(23796,38261,12,0,1,1),-- Bent House Key
(23796,33449,11,0,1,1),-- Crusty Flatbread
(23796,33447,9,0,1,1),-- Runic Healing Potion
(23796,29569,0.5,0,1,1),-- Strong Junkbox
-- Forsaken Plaguebringer
(23760,0,100,0,-@NEWREF2,1),
(23760,43575,41,0,1,1),-- Reinforced Junkbox
(23760,33447,10,0,1,1),-- Runic Healing Potion
(23760,38268,0.3,0,1,1),-- Spare Hand
-- Chillmere Tidehunter
(24460,43575,40,0,1,1),-- Reinforced Junkbox
(24460,38274,33,0,1,1),-- Large Snail Shell
(24460,37452,18,0,1,1),-- Fatty Bluefin
(24460,38273,15,0,1,1),-- Brain Coral
(24460,33447,7,0,1,1),-- Runic Healing Potion
-- Vrykul Soul
(24262,0,100,0,-@NEWREF2,1),
(24262,43575,40,0,1,1),-- Reinforced Junkbox
(24262,33447,3,0,1,1),-- Runic Healing Potion
-- Iron Rune Sage
(23674,0,100,0,-@NEWREF5,1),
(23674,43575,39,0,1,1),-- Reinforced Junkbox
(23674,38261,13,0,1,1),-- Bent House Key
(23674,33449,9,0,1,1),-- Crusty Flatbread
(23674,33447,6,0,1,1),-- Runic Healing Potion
-- Vengeance Bringer
(23865,43575,39,0,1,1),-- Reinforced Junkbox
(23865,0,100,0,-@NEWREF2,1),
-- Restless Lookout
(31554,43575,80,0,1,1),-- Reinforced Junkbox
(31554,35947,40,0,1,1),-- Sparkling Frostcap
-- Val'kyr Taskmistress
(31396,43575,56,0,1,1),-- Reinforced Junkbox
(31396,35947,38,0,1,1),-- Sparkling Frostcap
(31396,33447,15,0,1,1),-- Runic Healing Potion
-- Overseer Veraj
(32263,43575,42,0,1,1),-- Reinforced Junkbox
(32263,37467,28,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(32263,38261,15,0,1,1),-- Bent House Key
(32263,33447,13,0,1,1),-- Runic Healing Potion
(32263,0,100,0,-@NEWREF8,1),
-- Steward
(26729,0,100,0,-@NEWREF0,1),
(26729,1,100,0,-@NEWREF3,1),
(26729,33449,31,0,1,1),-- Crusty Flatbread
(26729,29569,0.5,0,1,1),-- Strong Junkbox
-- Alliance Berserker
(26800,43575,62,0,1,1),-- Reinforced Junkbox
(26800,33449,19,0,1,1),-- Crusty Flatbread
(26800,38261,16,0,1,1),-- Bent House Key
(26800,33447,10,0,1,1),-- Runic Healing Potion
(26800,0,100,0,-@NEWREF5,1),
-- Alliance Ranger
(26802,0,100,0,-@NEWREF5,1),
(26802,43575,60,0,1,1),-- Reinforced Junkbox
(26802,38261,34,0,1,1),-- Bent House Key
(26802,33449,24,0,1,1),-- Crusty Flatbread
(26802,33447,12,0,1,1),-- Runic Healing Potion
-- Mage Hunter Ascendant
(26727,0,100,0,-@NEWREF0,1),
(26727,1,100,0,-@NEWREF3,1),
(26727,33449,29,0,1,1),-- Crusty Flatbread
-- Ring-Lord Sorceress
(27639,43575,87,0,1,1),-- Reinforced Junkbox
(27639,37467,46,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(27639,38261,28,0,1,1),-- Bent House Key
(27639,33447,19,0,1,1),-- Runic Healing Potion
(27639,0,100,0,-@NEWREF8,1),
(27639,36863,1.6,0,1,1),-- Decahedral Dwarven Dice
-- Ring-Lord Conjurer
(27640,37467,67,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(27640,43575,64,0,1,1),-- Reinforced Junkbox
(27640,33447,30,0,1,1),-- Runic Healing Potion
(27640,38261,26,0,1,1),-- Bent House Key
(27640,0,100,0,-@NEWREF8,1),
-- Mildred the Cruel
(29885,0,100,0,-@NEWREF0,1),
(29885,40202,13,0,1,1),-- Sizzling Grizzly Flank
-- Snowblind Devotee
(29407,43575,42,0,1,1),-- Reinforced Junkbox
(29407,40202,29,0,1,1),-- Sizzling Grizzly Flank
(29407,0,100,0,-@NEWREF4,1),
(29407,33447,12,0,1,1),-- Runic Healing Potion
-- Snowblind Devotee
(29554,43575,43,0,1,1),-- Reinforced Junkbox
(29554,40202,27,0,1,1),-- Sizzling Grizzly Flank
(29554,0,100,0,-@NEWREF4,1),
(29554,33447,12,0,1,1),-- Runic Healing Potion
(29554,38266,0.2,0,1,1),-- Rotund Relic
-- Frostfeather Witch
(29793,43575,40,0,1,1),-- Reinforced Junkbox
(29793,40202,21,0,1,1),-- Sizzling Grizzly Flank
(29793,0,100,0,-@NEWREF4,1),
(29793,33447,16,0,1,1),-- Runic Healing Potion
-- Icemane Yeti
(29875,43575,39,0,1,1),-- Reinforced Junkbox
(29875,40202,23,0,1,1),-- Sizzling Grizzly Flank
(29875,0,100,0,-@NEWREF4,1),
(29875,33447,15,0,1,1),-- Runic Healing Potion
(29875,38266,0.3,0,1,1),-- Rotund Relic
-- Garm Watcher
(29553,0,100,0,-@NEWREF0,1),
(29553,1,100,0,-@NEWREF1,1),
(29553,24231,0.3,0,2,2),-- Coarse Snuff
-- Stormforged Taskmaster
(29369,43575,38,0,1,1),-- Reinforced Junkbox
(29369,37467,34,0,1,1),-- A Steamy Romance Novel: Forbidden Love
(29369,33447,13,0,1,1),-- Runic Healing Potion
(29369,38261,6,0,1,1),-- Bent House Key
(29369,0,100,0,-@NEWREF8,1),
-- Dragonflayer Bonecrusher
(24069,0,100,0,-@NEWREF0,1),
(24069,1,100,0,-@NEWREF1,1),
(24069,29569,47,0,1,1),-- Strong Junkbox
(24069,29570,34,0,1,1),-- A Gnome Effigy
(24069,27855,22,0,1,1),-- Mag'har Grainbread
(24069,27854,19,0,1,1),-- Smoked Talbuk Venison
(24069,22829,10,0,1,1),-- Super Healing Potion
(24069,23438,1.2,0,1,1),-- Star of Elune
-- Ymirjar Berserker
(26696,0,100,0,-@NEWREF7,1),
(26696,29569,1.1,0,1,1),-- Strong Junkbox
-- Kutube'sa
(28494,0,100,0,-@NEWREF0,1),
(28494,1,100,0,-@NEWREF1,1),
-- Chulo the Mad
(28496,0,100,0,-@NEWREF0,1),
(28496,40202,6,0,1,1),-- Sizzling Grizzly Flank
-- Drakuru's Guard
(28803,43575,50,0,1,1),-- Reinforced Junkbox
(28803,33447,33,0,1,1),-- Runic Healing Potion
(28803,38269,17,0,1,1),-- Soggy Handkerchief
-- Prophet of Har'koa
(28848,0,100,0,-@NEWREF0,1),
(28848,40202,3,0,1,1),-- Sizzling Grizzly Flank
-- Decaying Ghoul
(28565,0,100,0,-@NEWREF7,1),
(28565,22829,0.9,0,1,1),-- Super Healing Potion
-- Drakuru Berserker
(29656,0,100,0,-@NEWREF0,1),
(29656,1,100,0,-@NEWREF3,1),
(29656,33449,11,0,1,1),-- Crusty Flatbread
(29656,29569,0.9,0,1,1); -- Strong Junkbox
