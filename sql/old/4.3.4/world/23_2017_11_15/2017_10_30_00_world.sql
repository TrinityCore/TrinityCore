DELETE FROM `reference_loot_template` WHERE `Entry` IN (11919,11920,11921) OR `Entry` BETWEEN 13006 AND 13010;
INSERT INTO `reference_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
-- Milling
(11919, 61979, 11919,100, 0, 1, 0, 2, 4, 'Ashen Pigment'),
(11919, 61980, 11919, 25, 0, 1, 0, 1, 3, 'Burning Embers'),
(11920, 61979, 11920,100, 0, 1, 0, 2, 3, 'Ashen Pigment'),
(11920, 61980, 11920, 25, 0, 1, 0, 1, 3, 'Burning Embers'),
(11921, 61979, 11921,100, 0, 1, 0, 2, 4, 'Ashen Pigment'),
(11921, 61980, 11921, 50, 0, 1, 0, 1, 3, 'Burning Embers'),
-- Prospecting
(13006, 52327, 13006,100, 0, 1, 0, 1, 3, 'Volatile Earth from Pyrite Ore'),
(13007, 52177, 13007, 17, 0, 1, 1, 1, 1, 'Carnelian - Green gems'),
(13007, 52178, 13007, 17, 0, 1, 1, 1, 1, 'Zephyrite - Green gems'),
(13007, 52179, 13007, 17, 0, 1, 1, 1, 1, 'Alicite - Green gems'),
(13007, 52180, 13007, 16, 0, 1, 1, 1, 1, 'Nightstone - Green gems'),
(13007, 52181, 13007, 17, 0, 1, 1, 1, 1, 'Hessonite - Green gems'),
(13007, 52182, 13007, 16, 0, 1, 1, 1, 1, 'Jasper - Green gems'),
(13008, 52190, 13008,  4, 0, 1, 2, 1, 1, 'Inferno Ruby - Blue gems'),
(13008, 52191, 13008,  4, 0, 1, 2, 1, 1, 'Ocean Sapphire - Blue gems'),
(13008, 52192, 13008,  4, 0, 1, 2, 1, 1, 'Dream Emerald - Blue gems'),
(13008, 52193, 13008,  4, 0, 1, 2, 1, 1, 'Ember Topaz - Blue gems'),
(13008, 52194, 13008,  4, 0, 1, 2, 1, 1, 'Demonseye - Blue gems'),
(13008, 52195, 13008,  4, 0, 1, 2, 1, 1, 'Amberjewel - Blue gems'),
(13009, 52177, 13009, 17, 0, 1, 1, 1, 2, 'Carnelian - Green gems 2'),
(13009, 52178, 13009, 17, 0, 1, 1, 1, 2, 'Zephyrite - Green gems 2'),
(13009, 52179, 13009, 17, 0, 1, 1, 1, 2, 'Alicite - Green gems 2'),
(13009, 52180, 13009, 16, 0, 1, 1, 1, 2, 'Nightstone - Green gems 2'),
(13009, 52181, 13009, 17, 0, 1, 1, 1, 2, 'Hessonite - Green gems 2'),
(13009, 52182, 13009, 16, 0, 1, 1, 1, 2, 'Jasper - Green gems 2'),
(13010, 52190, 13010,  7, 0, 1, 2, 1, 2, 'Inferno Ruby - Blue gems 2'),
(13010, 52191, 13010,  7, 0, 1, 2, 1, 2, 'Ocean Sapphire - Blue gems 2'),
(13010, 52192, 13010,  7, 0, 1, 2, 1, 2, 'Dream Emerald - Blue gems 2'),
(13010, 52193, 13010,  7, 0, 1, 2, 1, 2, 'Ember Topaz - Blue gems 2'),
(13010, 52194, 13010,  7, 0, 1, 2, 1, 2, 'Demonseye - Blue gems 2'),
(13010, 52195, 13010,  7, 0, 1, 2, 1, 2, 'Amberjewel - Blue gems 2');

DELETE FROM `milling_loot_template` WHERE `Entry` BETWEEN 52983 AND 52988;
INSERT INTO `milling_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(52983, 11919, 11919, 100, 0, 1, 0, 1, 1, 'Cinderbloom - Ashen Pigment, Burning Embers'),
(52984, 11920, 11920, 100, 0, 1, 0, 1, 1, 'Stormvine - Ashen Pigment, Burning Embers'),
(52985, 11920, 11920, 100, 0, 1, 0, 1, 1, 'Azshara\'s Veil - Ashen Pigment, Burning Embers'),
(52986, 11919, 11919, 100, 0, 1, 0, 1, 1, 'Heartblossom - Ashen Pigment, Burning Embers'),
(52987, 11921, 11921, 100, 0, 1, 0, 1, 1, 'Twilight Jasmine - Ashen Pigment, Burning Embers'),
(52988, 11921, 11921, 100, 0, 1, 0, 1, 1, 'Whiptail - Ashen Pigment, Burning Embers');

DELETE FROM `prospecting_loot_template` WHERE `Entry` IN (52183,52185,53038);
INSERT INTO `prospecting_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(52183, 13006, 13006, 100, 0, 1, 0, 1, 1, 'Pyrite Ore - Volatile Earth'),
(52183, 13009, 13009, 100, 0, 1, 0, 1, 1, 'Pyrite Ore - Green gems 2'),
(52183, 13010, 13010, 100, 0, 1, 0, 1, 1, 'Pyrite Ore - Blue gems 2'),
(52185, 13007, 13007, 100, 0, 1, 0, 1, 1, 'Elementium Ore - Green gems'),
(52185, 13008, 13008, 100, 0, 1, 0, 1, 1, 'Elementium Ore - Blue gems'),
(53038, 13007, 13007, 100, 0, 1, 0, 1, 1, 'Obsidium Ore - Green gems'),
(53038, 13008, 13008,  50, 0, 1, 0, 1, 1, 'Obsidium Ore - Blue gems');
