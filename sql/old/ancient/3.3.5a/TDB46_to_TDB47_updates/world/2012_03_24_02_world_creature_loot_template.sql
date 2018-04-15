-- (re) Add reference 26042
SET @NEC := 26042; -- Northrend Emotion Cooking Recipe Reference
DELETE FROM `reference_loot_template` WHERE `entry`=@NEC;
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@NEC,43507,0,1,1,1,1), -- Recipe: Tasty cupcake
(@NEC,43508,0,1,1,1,1), -- Recipe: Last Week's Mammoth
(@NEC,43509,0,1,1,1,1), -- Recipe: Bad Clams
(@NEC,43510,0,1,1,1,1); -- Recipe: Haunted Herring

DELETE FROM `creature_loot_template` WHERE `entry` IN (2436,5928,5936,12239,12240,12241,12242,12243,14527,14529,14531,16506,16836,17307,21166,23809,23954,23963,23964,23983,24175,25234,28027,28113,28138,28494,29554,30177,30954,31779,40419);
UPDATE `creature_template`SET `lootid`=entry WHERE `entry` IN (2436,5928,5936,12239,12240,12241,12242,12243,14527,14529,14531,16506,16836,21166,23809,23963,23964,23983,25234,28027,28138,28494,29554,30954,31779,40419);
UPDATE `creature_template` SET `lootid`=0 WHERE `entry` IN (17307,23954,24175,28113,30177);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Farmer Kent (friendly?)
(2436,3692,-100,1,0,1,1), -- Hilsbrad Human Skull
-- Sorrow Wing
(5928,5808,-50,1,0,1,1), --  Pridewing Venom Sac
(5928,5137,80,1,0,1,1), -- Bright Eyeball
(5928,5136,10,1,0,1,1), -- Torn Furry Ear
(5928,1,100,1,0,-@NEC,1), -- Random world green drop ilvl 25-30
-- Orca
(5936,26000,3,1,1,-26000,1), -- Northrend World Grey Reference #1
(5936,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(5936,26003,1,1,1,-26003,1), -- Northrend World Green Reference #1
(5936,26004,1,1,1,-26004,1), -- Northrend World Green Reference #2
(5936,26005,1,1,1,-26005,1), -- Northrend World Green Reference #3
(5936,26006,1,1,1,-26006,1), -- Northrend World Green Reference #4
(5936,26017,0.5,1,1,-26017,1), -- Northrend World Blue Reference #1
(5936,26018,0.5,1,1,-26018,1), -- Northrend World Blue Reference #2
(5936,26019,0.5,1,1,-26019,1), -- Northrend World Blue Reference #3
(5936,26020,0.5,1,1,-26020,1), -- Northrend World Blue Reference #4
-- Add Theradric Crystal Carving (17684) to the following creatures
(12239,17684,-25,1,0,1,1), -- Spirit of Gelk
(12240,17684,-25,1,0,1,1), -- Spirit of Kolk
(12241,17684,-25,1,0,1,1), -- Spirit of Magra
(12242,17684,-25,1,0,1,1), -- Spirit of Maraudos
(12243,17684,-25,1,0,1,1), -- Spirit of Veng
(14527,18952,-100,1,0,1,1), -- Simone the Inconspicuous - Simone's Head
(14529,18953,-100,1,0,1,1), -- Franklin the Friendly - Klinfran's Head
(14531,18955,-100,1,0,1,1), -- Artorius the Amiable - Artorius's Head
(16506,22708,-100,1,0,1,1), -- Naxxramas Worshipper - Fate of Ramaladni
(16836,23460,-100,1,0,1,1), -- Escaped Dreghood - Broken Blood Sample
(21166,30451,-15,1,0,1,1), -- Illidari Dreadlord - Lohn'goron, Bow of the Torn-heart
-- Vengeance Landing Cannoneer
(23809,26000,3,1,1,-26000,1), -- Northrend World Grey Reference #1
(23809,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(23809,26005,1,1,1,-26005,1), -- Northrend World Green Reference #3
-- Sergeant Lorric
(23963,26000,3,1,1,-26000,1), -- Northrend World Grey Reference #1
(23963,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(23963,26003,1,1,1,-26003,1), -- Northrend World Green Reference #1
(23963,26004,1,1,1,-26004,1), -- Northrend World Green Reference #2
(23963,26017,0.5,1,1,-26017,1), -- Northrend World Blue Reference #1
(23963,26018,0.5,1,1,-26018,1), -- Northrend World Blue Reference #2
(23963,26044,2,1,0,-@NEC,1), -- Northrend Emotion Cooking Recipes
-- Lieutenant Celeyne
(23964,26000,3,1,1,-26000,1), -- Northrend World Grey Reference #1
(23964,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(23964,26003,1,1,1,-26003,1), -- Northrend World Green Reference #1
(23964,26004,1,1,1,-26004,1), -- Northrend World Green Reference #2
(23964,26017,0.5,1,1,-26017,1), -- Northrend World Blue Reference #1
(23964,26018,0.5,1,1,-26018,1), -- Northrend World Blue Reference #2
(23964,26044,2,1,0,-@NEC,1), -- Northrend Emotion Cooking Recipes
-- North Fleet Marine
(23983,26000,3,1,1,-26000,1), -- Northrend World Grey Reference #1
(23983,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(23983,26003,1,1,1,-26003,1), -- Northrend World Green Reference #1
(23983,26004,1,1,1,-26004,1), -- Northrend World Green Reference #2
(23983,26017,0.5,1,1,-26017,1), -- Northrend World Blue Reference #1
(23983,26018,0.5,1,1,-26018,1), -- Northrend World Blue Reference #2
(23983,26044,2,1,0,-@NEC,1), -- Northrend Emotion Cooking Recipes
-- Stormfleet Deckhand
(25234,26000,3,1,1,-26000,1), -- Northrend World Grey Reference #1
(25234,26003,1,1,1,-26003,1), -- Northrend World Green Reference #1
-- High-Oracle Soo-say
(28027,17058,50,1,0,1,1), -- Fish Oil
(28027,17057,30,1,0,1,1), -- Shiny Fish Scales
(28027,33470,15,1,0,2,4), -- Frostweave Cloth
(28027,35951,10,1,0,1,3), -- Poached Emperor Salmon
(28027,38642,-1,1,0,1,1), -- Golden Engagement Ring
-- Elder Harkek
(28138,33470,40,1,0,2,4), -- Frostweave Cloth
(28138,33447,4,1,0,1,1), -- Runic Healing Potion
(28138,38642,-1,1,0,1,1), -- Golden Engagement Ring
-- Kutube'sa
(28494,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(28494,26002,3,1,1,-26002,1), -- Northrend World Grey Reference #3
(28494,26010,1,1,1,-26010,1), -- Northrend World Green Reference #4
(28494,26011,1,1,1,-26011,1), -- Northrend World Green Reference #5
(28494,26012,1,1,1,-26012,1), -- Northrend World Green Reference #6
(28494,26023,0.5,1,1,-26023,1), -- Northrend World Blue Reference #3
(28494,26025,0.5,1,1,-26025,1), -- Northrend World Blue Reference #4
(28494,26026,0.5,1,1,-26026,1), -- Northrend World Blue Reference #5
(28494,26044,2,1,0,-@NEC,1), -- Northrend Emotion Cooking Recipes
(28494,39152,35,1,0,1,1), -- Manual: Heavy Frostweave Bandage
(28494,43297,1,1,0,1,1), -- Damaged Necklace
-- Snowblind Devotee
(29554,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(29554,26002,3,1,1,-26002,1), -- Northrend World Grey Reference #3
(29554,26009,1,1,1,-26009,1), -- Northrend World Green Reference #3
(29554,26010,1,1,1,-26010,1), -- Northrend World Green Reference #4
(29554,26011,1,1,1,-26011,1), -- Northrend World Green Reference #5
(29554,26012,1,1,1,-26012,1), -- Northrend World Green Reference #6
(29554,26013,1,1,1,-26013,1), -- Northrend World Green Reference #7
(29554,26023,0.5,1,1,-26023,1), -- Northrend World Blue Reference #3
(29554,26024,0.5,1,1,-26024,1), -- Northrend World Blue Reference #4
(29554,26025,0.5,1,1,-26025,1), -- Northrend World Blue Reference #5
(29554,26026,0.5,1,1,-26026,1), -- Northrend World Blue Reference #6
(29554,26044,2,1,0,-@NEC,1), -- Northrend Emotion Cooking Recipes
(29554,39152,35,1,0,1,1), -- Manual: Heavy Frostweave Bandage
(29554,43297,1,1,0,1,1), -- Damaged Necklace
-- Rokir
(30954,26001,6,1,1,-26001,1), -- Northrend World Grey Reference #2
(30954,26002,6,1,1,-26002,1), -- Northrend World Grey Reference #3
(30954,26014,2,1,1,-26014,1), -- Northrend World Green Reference #8
(30954,26015,2,1,1,-26015,1), -- Northrend World Green Reference #9
-- Skeletal Archmage
(31779,26001,3,1,1,-26001,1), -- Northrend World Grey Reference #2
(31779,26002,3,1,1,-26002,1), -- Northrend World Grey Reference #3
(31779,26013,1,1,1,-26013,1), -- Northrend World Green Reference #7
(31779,26014,1,1,1,-26014,1), -- Northrend World Green Reference #8
(31779,26015,1,1,1,-26015,1), -- Northrend World Green Reference #9
(31779,26028,0.5,1,1,-26028,1), -- Northrend World Blue Reference #8
(31779,39152,50,1,0,1,1), -- Manual: Heavy Frostweave Bandage
(31779,43297,1,1,0,1,1), -- Damaged Necklace
-- Charscale Assaulter
(40419,26001,6,1,1,-26001,1), -- Northrend World Grey Reference #2
(40419,26002,6,1,1,-26002,1), -- Northrend World Grey Reference #3
(40419,26015,2,1,1,-26015,1), -- Northrend World Green Reference #9
(40419,26016,2,1,1,-26016,1); -- Northrend World Green Reference #10
-- conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 1 AND `SourceGroup` IN (28494,29554,31779);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES
(1,28494,39152,7,129,390,'Manual: Heavy Frostweave Bandage will drop only if the player has first aid at 390'),
(1,29554,39152,7,129,390,'Manual: Heavy Frostweave Bandage will drop only if the player has first aid at 390'),
(1,31779,39152,7,129,390,'Manual: Heavy Frostweave Bandage will drop only if the player has first aid at 390');
