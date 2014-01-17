-- Update Narain's Scrying Goggles
SET @Item := 20951;
DELETE FROM `creature_loot_template` WHERE `item`=@Item;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(11502,@Item,-100,1,0,1,1), -- Ragnaros
(11658,@Item,-100,1,0,1,1), -- Molten Giant
(11659,@Item,-100,1,0,1,1), -- Molten Destroyer
(11661,@Item,-100,1,0,1,1), -- Flamewaker
(11662,@Item,-100,1,0,1,1), -- Flamewaker Priest
(11663,@Item,-100,1,0,1,1), -- Flamewaker Healer
(11664,@Item,-100,1,0,1,1), -- Flamewaker Elite
(11665,@Item,-100,1,0,1,1), -- Lava Annihilator
(11666,@Item,-100,1,0,1,1), -- Firewalker
(11667,@Item,-100,1,0,1,1), -- Flameguard
(11669,@Item,-100,1,0,1,1), -- Flame Imp
(11673,@Item,-100,1,0,1,1), -- Ancient Core Hound
(11982,@Item,-100,1,0,1,1), -- Magmadar
(11988,@Item,-100,1,0,1,1), -- Golemagg the Incinerator
(12056,@Item,-100,1,0,1,1), -- Baron Geddon
(12057,@Item,-100,1,0,1,1), -- Garr
(12076,@Item,-100,1,0,1,1), -- Lava Elemental
(12098,@Item,-100,1,0,1,1), -- Sulfuron Harbinger
(12100,@Item,-100,1,0,1,1), -- Lava Reaver
(12101,@Item,-100,1,0,1,1), -- Lava Surger
(12118,@Item,-100,1,0,1,1), -- Lucifron
(12119,@Item,-100,1,0,1,1), -- Flamewaker Protector
(12231,@Item,-100,1,0,1,1), -- Firelord
(12259,@Item,-100,1,0,1,1), -- Gehennas
(12264,@Item,-100,1,0,1,1); -- Shazzrah
