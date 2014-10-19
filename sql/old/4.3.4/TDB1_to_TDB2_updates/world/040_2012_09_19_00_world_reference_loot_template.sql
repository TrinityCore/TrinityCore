-- Changes To VOA Loot
-- Update gold drops for bosses
-- Archavon 10 & 25
UPDATE `creature_template` SET `mingold`=1700000,`maxgold`=1800000 WHERE `entry` IN (31125,31722);
-- Emalon & koralon 10 & 25
UPDATE `creature_template` SET `mingold`=1800000,`maxgold`=1900000 WHERE `entry` IN (33993,33994,35013,35360);
-- Toravon 10 & 25
UPDATE `creature_template` SET `mingold`=1900000,`maxgold`=2000000 WHERE `entry` IN (38433,38462);
-- Combine PVP and PVE ref templates so loot has chance to be all pvp or all pve not one of each
-- Revome deadly items other than chest lega and hands from Archavon 25 loot
-- Toravon 25 drops 3 items
SET @ARCHAVON10 = 34209;
SET @ARCHAVON25 = 34216;
SET @EMALON10 = 34208;
SET @EMALON25 = 34215;
SET @TORAVON10 = 34206;
SET @TORAVON25 = 34207;
SET @KORALON10 = 34204;
SET @KORALON25 = 34205;
-- Create Reference loot template for @ARCHAVON25 T7(25) & Deadly Chest,Legs,Hands
DELETE FROM `reference_loot_template` WHERE `entry` IN (@ARCHAVON25,@KORALON25,@EMALON25);
INSERT INTO `reference_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@ARCHAVON25,40550,0,1,1,1,1), -- Valorous Scourgeborne Battleplate
(@ARCHAVON25,40552,0,1,1,1,1), -- Valorous Scourgeborne Gauntlets
(@ARCHAVON25,40556,0,1,1,1,1), -- Valorous Scourgeborne Legplates
(@ARCHAVON25,40559,0,1,1,1,1), -- Valorous Scourgeborne Chestguard
(@ARCHAVON25,40563,0,1,1,1,1), -- Valorous Scourgeborne Handguards
(@ARCHAVON25,40567,0,1,1,1,1), -- Valorous Scourgeborne Legguards
(@ARCHAVON25,40463,0,1,1,1,1), -- Valorous Dreamwalker Robe
(@ARCHAVON25,40460,0,1,1,1,1), -- Valorous Dreamwalker Handguards
(@ARCHAVON25,40462,0,1,1,1,1), -- Valorous Dreamwalker Leggings
(@ARCHAVON25,40503,0,1,1,1,1), -- Valorous Cryptstalker Tunic
(@ARCHAVON25,40504,0,1,1,1,1), -- Valorous Cryptstalker Handguards
(@ARCHAVON25,40506,0,1,1,1,1), -- Valorous Cryptstalker Legguards
(@ARCHAVON25,40418,0,1,1,1,1), -- Valorous Frostfire Robe
(@ARCHAVON25,40415,0,1,1,1,1), -- Valorous Frostfire Gloves
(@ARCHAVON25,40417,0,1,1,1,1), -- Valorous Frostfire Leggings
(@ARCHAVON25,40569,0,1,1,1,1), -- Valorous Redemption Tunic
(@ARCHAVON25,40570,0,1,1,1,1), -- Valorous Redemption Gloves
(@ARCHAVON25,40572,0,1,1,1,1), -- Valorous Redemption Greaves
(@ARCHAVON25,40579,0,1,1,1,1), -- Valorous Redemption Breastplate
(@ARCHAVON25,40580,0,1,1,1,1), -- Valorous Redemption Handguards
(@ARCHAVON25,40583,0,1,1,1,1), -- Valorous Redemption Legguards
(@ARCHAVON25,40574,0,1,1,1,1), -- Valorous Redemption Chestpiece
(@ARCHAVON25,40575,0,1,1,1,1), -- Valorous Redemption Gauntlets
(@ARCHAVON25,40577,0,1,1,1,1), -- Valorous Redemption Legplates
(@ARCHAVON25,40449,0,1,1,1,1), -- Valorous Robe of Faith
(@ARCHAVON25,40445,0,1,1,1,1), -- Valorous Gloves of Faith
(@ARCHAVON25,40448,0,1,1,1,1), -- Valorous Leggings of Faith
(@ARCHAVON25,40458,0,1,1,1,1), -- Valorous Raiments of Faith
(@ARCHAVON25,40454,0,1,1,1,1), -- Valorous Handwraps of Faith
(@ARCHAVON25,40457,0,1,1,1,1), -- Valorous Pants of Faith
(@ARCHAVON25,40495,0,1,1,1,1), -- Valorous Bonescythe Breastplate
(@ARCHAVON25,40496,0,1,1,1,1), -- Valorous Bonescythe Gauntlets
(@ARCHAVON25,40500,0,1,1,1,1), -- Valorous Bonescythe Legplates
(@ARCHAVON25,40514,0,1,1,1,1), -- Valorous Earthshatter Hauberk
(@ARCHAVON25,40515,0,1,1,1,1), -- Valorous Earthshatter Gloves
(@ARCHAVON25,40517,0,1,1,1,1), -- Valorous Earthshatter Kilt
(@ARCHAVON25,40523,0,1,1,1,1), -- Valorous Earthshatter Chestguard
(@ARCHAVON25,40520,0,1,1,1,1), -- Valorous Earthshatter Grips
(@ARCHAVON25,40522,0,1,1,1,1), -- Valorous Earthshatter War-Kilt
(@ARCHAVON25,40508,0,1,1,1,1), -- Valorous Earthshatter Tunic
(@ARCHAVON25,40509,0,1,1,1,1), -- Valorous Earthshatter Handguards
(@ARCHAVON25,40512,0,1,1,1,1), -- Valorous Earthshatter Legguards
(@ARCHAVON25,40423,0,1,1,1,1), -- Valorous Plagueheart Robe
(@ARCHAVON25,40420,0,1,1,1,1), -- Valorous Plagueheart Gloves
(@ARCHAVON25,40422,0,1,1,1,1), -- Valorous Plagueheart Leggings
(@ARCHAVON25,40525,0,1,1,1,1), -- Valorous Dreadnaught Battleplate
(@ARCHAVON25,40527,0,1,1,1,1), -- Valorous Dreadnaught Gauntlets
(@ARCHAVON25,40529,0,1,1,1,1), -- Valorous Dreadnaught Legplates
(@ARCHAVON25,40544,0,1,1,1,1), -- Valorous Dreadnaught Breastplate
(@ARCHAVON25,40545,0,1,1,1,1), -- Valorous Dreadnaught Handguards
(@ARCHAVON25,40547,0,1,1,1,1), -- Valorous Dreadnaught Legguards
(@ARCHAVON25,40469,0,1,1,1,1), -- Valorous Dreamwalker Vestments
(@ARCHAVON25,40466,0,1,1,1,1), -- Valorous Dreamwalker Gloves
(@ARCHAVON25,40468,0,1,1,1,1), -- Valorous Dreamwalker Trousers
(@ARCHAVON25,40471,0,1,1,1,1), -- Valorous Dreamwalker Raiments
(@ARCHAVON25,40472,0,1,1,1,1), -- Valorous Dreamwalker Handgrips
(@ARCHAVON25,40493,0,1,1,1,1), -- Valorous Dreamwalker Legguards
(@ARCHAVON25,40786,0,1,1,1,1), -- Deadly Gladiator's Plate Chestpiece
(@ARCHAVON25,41951,0,1,1,1,1), -- Deadly Gladiator's Silk Raiment
(@ARCHAVON25,41997,0,1,1,1,1), -- Deadly Gladiator's Felweave Raiment
(@ARCHAVON25,41649,0,1,1,1,1), -- Deadly Gladiator's Leather Tunic
(@ARCHAVON25,40784,0,1,1,1,1), -- Deadly Gladiator's Dreadplate Chestpiece
(@ARCHAVON25,41086,0,1,1,1,1), -- Deadly Gladiator's Chain Armor
(@ARCHAVON25,41920,0,1,1,1,1), -- Deadly Gladiator's Satin Robe
(@ARCHAVON25,40785,0,1,1,1,1), -- Deadly Gladiator's Scaled Chestpiece
(@ARCHAVON25,41660,0,1,1,1,1), -- Deadly Gladiator's Dragonhide Robes
(@ARCHAVON25,41858,0,1,1,1,1), -- Deadly Gladiator's Mooncloth Robe
(@ARCHAVON25,40905,0,1,1,1,1), -- Deadly Gladiator's Ornamented Chestguard
(@ARCHAVON25,40990,0,1,1,1,1), -- Deadly Gladiator's Ringmail Armor
(@ARCHAVON25,41315,0,1,1,1,1), -- Deadly Gladiator's Wyrmhide Robes
(@ARCHAVON25,41309,0,1,1,1,1), -- Deadly Gladiator's Kodohide Robes
(@ARCHAVON25,41080,0,1,1,1,1), -- Deadly Gladiator's Linked Armor
(@ARCHAVON25,40991,0,1,1,1,1), -- Deadly Gladiator's Mail Armor
(@ARCHAVON25,40926,0,1,1,1,1), -- Deadly Gladiator's Ornamented Gloves
(@ARCHAVON25,40938,0,1,1,1,1), -- Deadly Gladiator's Ornamented Legplates
(@ARCHAVON25,40846,0,1,1,1,1), -- Deadly Gladiator's Scaled Legguards
(@ARCHAVON25,41863,0,1,1,1,1), -- Deadly Gladiator's Mooncloth Leggings
(@ARCHAVON25,41926,0,1,1,1,1), -- Deadly Gladiator's Satin Leggings
(@ARCHAVON25,41873,0,1,1,1,1), -- Deadly Gladiator's Mooncloth Gloves
(@ARCHAVON25,41032,0,1,1,1,1), -- Deadly Gladiator's Mail Leggings
(@ARCHAVON25,41006,0,1,1,1,1), -- Deadly Gladiator's Mail Gauntlets
(@ARCHAVON25,41198,0,1,1,1,1), -- Deadly Gladiator's Linked Leggings
(@ARCHAVON25,41666,0,1,1,1,1), -- Deadly Gladiator's Dragonhide Legguards
(@ARCHAVON25,41772,0,1,1,1,1), -- Deadly Gladiator's Dragonhide Gloves
(@ARCHAVON25,41000,0,1,1,1,1), -- Deadly Gladiator's Ringmail Gauntlets
(@ARCHAVON25,41136,0,1,1,1,1), -- Deadly Gladiator's Linked Gauntlets
(@ARCHAVON25,41286,0,1,1,1,1), -- Deadly Gladiator's Kodohide Gloves
(@ARCHAVON25,40805,0,1,1,1,1), -- Deadly Gladiator's Scaled Gauntlets
(@ARCHAVON25,41939,0,1,1,1,1), -- Deadly Gladiator's Satin Gloves
(@ARCHAVON25,41297,0,1,1,1,1), -- Deadly Gladiator's Kodohide Legguards
(@ARCHAVON25,41026,0,1,1,1,1), -- Deadly Gladiator's Ringmail Leggings
(@ARCHAVON25,41958,0,1,1,1,1), -- Deadly Gladiator's Silk Trousers
(@ARCHAVON25,41970,0,1,1,1,1), -- Deadly Gladiator's Silk Handguards
(@ARCHAVON25,40844,0,1,1,1,1), -- Deadly Gladiator's Plate Legguards
(@ARCHAVON25,41303,0,1,1,1,1), -- Deadly Gladiator's Wyrmhide Legguards
(@ARCHAVON25,41292,0,1,1,1,1), -- Deadly Gladiator's Wyrmhide Gloves
(@ARCHAVON25,42004,0,1,1,1,1), -- Deadly Gladiator's Felweave Trousers
(@ARCHAVON25,41142,0,1,1,1,1), -- Deadly Gladiator's Chain Gauntlets
(@ARCHAVON25,40845,0,1,1,1,1), -- Deadly Gladiator's Dreadplate Legguards
(@ARCHAVON25,40804,0,1,1,1,1), -- Deadly Gladiator's Plate Gauntlets
(@ARCHAVON25,42016,0,1,1,1,1), -- Deadly Gladiator's Felweave Handguards
(@ARCHAVON25,40806,0,1,1,1,1), -- Deadly Gladiator's Dreadplate Gauntlets
(@ARCHAVON25,41654,0,1,1,1,1), -- Deadly Gladiator's Leather Legguards
(@ARCHAVON25,41766,0,1,1,1,1), -- Deadly Gladiator's Leather Gloves
(@ARCHAVON25,41204,0,1,1,1,1), -- Deadly Gladiator's Chain Leggings
-- Create Ref for Emalon 25 furious PVP + T8(25) (chest,hands,legs)
(@EMALON25,41640,0,1,1,1,1), -- Furious Gladiator's Armwraps of Dominance
(@EMALON25,41625,0,1,1,1,1), -- Furious Gladiator's Armwraps of Salvation
(@EMALON25,41840,0,1,1,1,1), -- Furious Gladiator's Armwraps of Triumph
(@EMALON25,42116,0,1,1,1,1), -- Furious Gladiator's Band of Dominance
(@EMALON25,42117,0,1,1,1,1), -- Furious Gladiator's Band of Triumph
(@EMALON25,41630,0,1,1,1,1), -- Furious Gladiator's Belt of Dominance
(@EMALON25,41617,0,1,1,1,1), -- Furious Gladiator's Belt of Salvation
(@EMALON25,41832,0,1,1,1,1), -- Furious Gladiator's Belt of Triumph
(@EMALON25,41635,0,1,1,1,1), -- Furious Gladiator's Boots of Dominance
(@EMALON25,41621,0,1,1,1,1), -- Furious Gladiator's Boots of Salvation
(@EMALON25,41836,0,1,1,1,1), -- Furious Gladiator's Boots of Triumph
(@EMALON25,40983,0,1,1,1,1), -- Furious Gladiator's Bracers of Salvation
(@EMALON25,40889,0,1,1,1,1), -- Furious Gladiator's Bracers of Triumph
(@EMALON25,41143,0,1,1,1,1), -- Furious Gladiator's Chain Gauntlets
(@EMALON25,41205,0,1,1,1,1), -- Furious Gladiator's Chain Leggings
(@EMALON25,42071,0,1,1,1,1), -- Furious Gladiator's Cloak of Ascendancy
(@EMALON25,42073,0,1,1,1,1), -- Furious Gladiator's Cloak of Deliverance
(@EMALON25,42069,0,1,1,1,1), -- Furious Gladiator's Cloak of Dominance
(@EMALON25,42072,0,1,1,1,1), -- Furious Gladiator's Cloak of Salvation
(@EMALON25,42070,0,1,1,1,1), -- Furious Gladiator's Cloak of Subjugation
(@EMALON25,42074,0,1,1,1,1), -- Furious Gladiator's Cloak of Triumph
(@EMALON25,42075,0,1,1,1,1), -- Furious Gladiator's Cloak of Victory
(@EMALON25,41898,0,1,1,1,1), -- Furious Gladiator's Cord of Dominance
(@EMALON25,41881,0,1,1,1,1), -- Furious Gladiator's Cord of Salvation
(@EMALON25,41909,0,1,1,1,1), -- Furious Gladiator's Cuffs of Dominance
(@EMALON25,41893,0,1,1,1,1), -- Furious Gladiator's Cuffs of Salvation
(@EMALON25,41773,0,1,1,1,1), -- Furious Gladiator's Dragonhide Gloves
(@EMALON25,41667,0,1,1,1,1), -- Furious Gladiator's Dragonhide Legguards
(@EMALON25,40809,0,1,1,1,1), -- Furious Gladiator's Dreadplate Gauntlets
(@EMALON25,42017,0,1,1,1,1), -- Furious Gladiator's Felweave Handguards
(@EMALON25,42005,0,1,1,1,1), -- Furious Gladiator's Felweave Trousers
(@EMALON25,40976,0,1,1,1,1), -- Furious Gladiator's Girdle of Salvation
(@EMALON25,40881,0,1,1,1,1), -- Furious Gladiator's Girdle of Triumph
(@EMALON25,40977,0,1,1,1,1), -- Furious Gladiator's Greaves of Salvation
(@EMALON25,40882,0,1,1,1,1), -- Furious Gladiator's Greaves of Triumph
(@EMALON25,41287,0,1,1,1,1), -- Furious Gladiator's Kodohide Gloves
(@EMALON25,41298,0,1,1,1,1), -- Furious Gladiator's Kodohide Legguards
(@EMALON25,41767,0,1,1,1,1), -- Furious Gladiator's Leather Gloves
(@EMALON25,41655,0,1,1,1,1), -- Furious Gladiator's Leather Legguards
(@EMALON25,41137,0,1,1,1,1), -- Furious Gladiator's Linked Gauntlets
(@EMALON25,41199,0,1,1,1,1), -- Furious Gladiator's Linked Leggings
(@EMALON25,41007,0,1,1,1,1), -- Furious Gladiator's Mail Gauntlets
(@EMALON25,41033,0,1,1,1,1), -- Furious Gladiator's Mail Leggings
(@EMALON25,41874,0,1,1,1,1), -- Furious Gladiator's Mooncloth Gloves
(@EMALON25,41864,0,1,1,1,1), -- Furious Gladiator's Mooncloth Leggings
(@EMALON25,40927,0,1,1,1,1), -- Furious Gladiator's Ornamented Gloves
(@EMALON25,40939,0,1,1,1,1), -- Furious Gladiator's Ornamented Legplates
(@EMALON25,42037,0,1,1,1,1), -- Furious Gladiator's Pendant of Ascendancy
(@EMALON25,42039,0,1,1,1,1), -- Furious Gladiator's Pendant of Deliverance
(@EMALON25,42036,0,1,1,1,1), -- Furious Gladiator's Pendant of Dominance
(@EMALON25,42040,0,1,1,1,1), -- Furious Gladiator's Pendant of Salvation
(@EMALON25,42038,0,1,1,1,1), -- Furious Gladiator's Pendant of Subjugation
(@EMALON25,46373,0,1,1,1,1), -- Furious Gladiator's Pendant of Sundering
(@EMALON25,42034,0,1,1,1,1), -- Furious Gladiator's Pendant of Triumph
(@EMALON25,42035,0,1,1,1,1), -- Furious Gladiator's Pendant of Victory
(@EMALON25,40807,0,1,1,1,1), -- Furious Gladiator's Plate Gauntlets
(@EMALON25,40847,0,1,1,1,1), -- Furious Gladiator's Plate Legguards
(@EMALON25,41001,0,1,1,1,1), -- Furious Gladiator's Ringmail Gauntlets
(@EMALON25,41027,0,1,1,1,1), -- Furious Gladiator's Ringmail Leggings
(@EMALON25,41075,0,1,1,1,1), -- Furious Gladiator's Sabatons of Dominance
(@EMALON25,41055,0,1,1,1,1), -- Furious Gladiator's Sabatons of Salvation
(@EMALON25,41230,0,1,1,1,1), -- Furious Gladiator's Sabatons of Triumph
(@EMALON25,41940,0,1,1,1,1), -- Furious Gladiator's Satin Gloves
(@EMALON25,41927,0,1,1,1,1), -- Furious Gladiator's Satin Leggings
(@EMALON25,40808,0,1,1,1,1), -- Furious Gladiator's Scaled Gauntlets
(@EMALON25,40849,0,1,1,1,1), -- Furious Gladiator's Scaled Legguards
(@EMALON25,41971,0,1,1,1,1), -- Furious Gladiator's Silk Handguards
(@EMALON25,41959,0,1,1,1,1), -- Furious Gladiator's Silk Trousers
(@EMALON25,41903,0,1,1,1,1), -- Furious Gladiator's Slippers of Dominance
(@EMALON25,41885,0,1,1,1,1), -- Furious Gladiator's Slippers of Salvation
(@EMALON25,41070,0,1,1,1,1), -- Furious Gladiator's Waistguard of Dominance
(@EMALON25,41051,0,1,1,1,1), -- Furious Gladiator's Waistguard of Salvation
(@EMALON25,41235,0,1,1,1,1), -- Furious Gladiator's Waistguard of Triumph
(@EMALON25,41065,0,1,1,1,1), -- Furious Gladiator's Wristguards of Dominance
(@EMALON25,41060,0,1,1,1,1), -- Furious Gladiator's Wristguards of Salvation
(@EMALON25,41225,0,1,1,1,1), -- Furious Gladiator's Wristguards of Triumph
(@EMALON25,41293,0,1,1,1,1), -- Furious Gladiator's Wyrmhide Gloves
(@EMALON25,41304,0,1,1,1,1), -- Furious Gladiator's Wyrmhide Legguards
(@EMALON25,40811,0,1,1,1,1), -- Furious Gladiator's Girdle of Triumph
(@EMALON25,46155,0,1,1,1,1), -- Conqueror's Aegis Gauntlets
(@EMALON25,46179,0,1,1,1,1), -- Conqueror's Aegis Gloves
(@EMALON25,46181,0,1,1,1,1), -- Conqueror's Aegis Greaves
(@EMALON25,46174,0,1,1,1,1), -- Conqueror's Aegis Handguards
(@EMALON25,46176,0,1,1,1,1), -- Conqueror's Aegis Legguards
(@EMALON25,46153,0,1,1,1,1), -- Conqueror's Aegis Legplates
(@EMALON25,46113,0,1,1,1,1), -- Conqueror's Darkruned Gauntlets
(@EMALON25,46119,0,1,1,1,1), -- Conqueror's Darkruned Handguards
(@EMALON25,46121,0,1,1,1,1), -- Conqueror's Darkruned Legguards
(@EMALON25,46116,0,1,1,1,1), -- Conqueror's Darkruned Legplates
(@EMALON25,46135,0,1,1,1,1), -- Conqueror's Deathbringer Gloves
(@EMALON25,46139,0,1,1,1,1), -- Conqueror's Deathbringer Leggings
(@EMALON25,46188,0,1,1,1,1), -- Conqueror's Gloves of Sanctification
(@EMALON25,46163,0,1,1,1,1), -- Conqueror's Handwraps of Sanctification
(@EMALON25,46132,0,1,1,1,1), -- Conqueror's Kirin Tor Gauntlets
(@EMALON25,46133,0,1,1,1,1), -- Conqueror's Kirin Tor Leggings
(@EMALON25,46195,0,1,1,1,1), -- Conqueror's Leggings of Sanctification
(@EMALON25,46189,0,1,1,1,1), -- Conqueror's Nightsong Gloves
(@EMALON25,46158,0,1,1,1,1), -- Conqueror's Nightsong Handgrips
(@EMALON25,46183,0,1,1,1,1), -- Conqueror's Nightsong Handguards
(@EMALON25,46185,0,1,1,1,1), -- Conqueror's Nightsong Leggings
(@EMALON25,46160,0,1,1,1,1), -- Conqueror's Nightsong Legguards
(@EMALON25,46192,0,1,1,1,1), -- Conqueror's Nightsong Trousers
(@EMALON25,46170,0,1,1,1,1), -- Conqueror's Pants of Sanctification
(@EMALON25,46142,0,1,1,1,1), -- Conqueror's Scourgestalker Handguards
(@EMALON25,46144,0,1,1,1,1), -- Conqueror's Scourgestalker Legguards
(@EMALON25,46148,0,1,1,1,1), -- Conqueror's Siegebreaker Gauntlets
(@EMALON25,46164,0,1,1,1,1), -- Conqueror's Siegebreaker Handguards
(@EMALON25,46169,0,1,1,1,1), -- Conqueror's Siegebreaker Legguards
(@EMALON25,46150,0,1,1,1,1), -- Conqueror's Siegebreaker Legplates
(@EMALON25,46124,0,1,1,1,1), -- Conqueror's Terrorblade Gauntlets
(@EMALON25,46126,0,1,1,1,1), -- Conqueror's Terrorblade Legplates
(@EMALON25,46207,0,1,1,1,1), -- Conqueror's Worldbreaker Gloves
(@EMALON25,46200,0,1,1,1,1), -- Conqueror's Worldbreaker Grips
(@EMALON25,46199,0,1,1,1,1), -- Conqueror's Worldbreaker Handguards
(@EMALON25,46210,0,1,1,1,1), -- Conqueror's Worldbreaker Kilt
(@EMALON25,46202,0,1,1,1,1), -- Conqueror's Worldbreaker Legguards
(@EMALON25,46208,0,1,1,1,1), -- Conqueror's Worldbreaker War-Kilt
-- Create Ref for koralon 25 relentless + T9.5 (hands,legs)
(@KORALON25,41641,0,1,1,1,1), -- Relentless Gladiator's Armwraps of Dominance
(@KORALON25,41626,0,1,1,1,1), -- Relentless Gladiator's Armwraps of Salvation
(@KORALON25,41841,0,1,1,1,1), -- Relentless Gladiator's Armwraps of Triumph
(@KORALON25,42118,0,1,1,1,1), -- Relentless Gladiator's Band of Ascendancy
(@KORALON25,42119,0,1,1,1,1), -- Relentless Gladiator's Band of Victory
(@KORALON25,41631,0,1,1,1,1), -- Relentless Gladiator's Belt of Dominance
(@KORALON25,41618,0,1,1,1,1), -- Relentless Gladiator's Belt of Salvation
(@KORALON25,41833,0,1,1,1,1), -- Relentless Gladiator's Belt of Triumph
(@KORALON25,41636,0,1,1,1,1), -- Relentless Gladiator's Boots of Dominance
(@KORALON25,41622,0,1,1,1,1), -- Relentless Gladiator's Boots of Salvation
(@KORALON25,41837,0,1,1,1,1), -- Relentless Gladiator's Boots of Triumph
(@KORALON25,40984,0,1,1,1,1), -- Relentless Gladiator's Bracers of Salvation
(@KORALON25,40890,0,1,1,1,1), -- Relentless Gladiator's Bracers of Triumph
(@KORALON25,41144,0,1,1,1,1), -- Relentless Gladiator's Chain Gauntlets
(@KORALON25,41206,0,1,1,1,1), -- Relentless Gladiator's Chain Leggings
(@KORALON25,42078,0,1,1,1,1), -- Relentless Gladiator's Cloak of Ascendancy
(@KORALON25,42080,0,1,1,1,1), -- Relentless Gladiator's Cloak of Deliverance
(@KORALON25,42076,0,1,1,1,1), -- Relentless Gladiator's Cloak of Dominance
(@KORALON25,42079,0,1,1,1,1), -- Relentless Gladiator's Cloak of Salvation
(@KORALON25,42077,0,1,1,1,1), -- Relentless Gladiator's Cloak of Subjugation
(@KORALON25,42081,0,1,1,1,1), -- Relentless Gladiator's Cloak of Triumph
(@KORALON25,42082,0,1,1,1,1), -- Relentless Gladiator's Cloak of Victory
(@KORALON25,41899,0,1,1,1,1), -- Relentless Gladiator's Cord of Dominance
(@KORALON25,41882,0,1,1,1,1), -- Relentless Gladiator's Cord of Salvation
(@KORALON25,41910,0,1,1,1,1), -- Relentless Gladiator's Cuffs of Dominance
(@KORALON25,41894,0,1,1,1,1), -- Relentless Gladiator's Cuffs of Salvation
(@KORALON25,41774,0,1,1,1,1), -- Relentless Gladiator's Dragonhide Gloves
(@KORALON25,41668,0,1,1,1,1), -- Relentless Gladiator's Dragonhide Legguards
(@KORALON25,40851,0,1,1,1,1), -- Relentless Gladiator's Dreadplate Legguards
(@KORALON25,42018,0,1,1,1,1), -- Relentless Gladiator's Felweave Handguards
(@KORALON25,42006,0,1,1,1,1), -- Relentless Gladiator's Felweave Trousers
(@KORALON25,40978,0,1,1,1,1), -- Relentless Gladiator's Girdle of Salvation
(@KORALON25,40883,0,1,1,1,1), -- Relentless Gladiator's Girdle of Triumph
(@KORALON25,40979,0,1,1,1,1), -- Relentless Gladiator's Greaves of Salvation
(@KORALON25,40884,0,1,1,1,1), -- Relentless Gladiator's Greaves of Triumph
(@KORALON25,41288,0,1,1,1,1), -- Relentless Gladiator's Kodohide Gloves
(@KORALON25,41299,0,1,1,1,1), -- Relentless Gladiator's Kodohide Legguards
(@KORALON25,41768,0,1,1,1,1), -- Relentless Gladiator's Leather Gloves
(@KORALON25,41656,0,1,1,1,1), -- Relentless Gladiator's Leather Legguards
(@KORALON25,41138,0,1,1,1,1), -- Relentless Gladiator's Linked Gauntlets
(@KORALON25,41200,0,1,1,1,1), -- Relentless Gladiator's Linked Leggings
(@KORALON25,41008,0,1,1,1,1), -- Relentless Gladiator's Mail Gauntlets
(@KORALON25,41034,0,1,1,1,1), -- Relentless Gladiator's Mail Leggings
(@KORALON25,41875,0,1,1,1,1), -- Relentless Gladiator's Mooncloth Gloves
(@KORALON25,41865,0,1,1,1,1), -- Relentless Gladiator's Mooncloth Leggings
(@KORALON25,40928,0,1,1,1,1), -- Relentless Gladiator's Ornamented Gloves
(@KORALON25,40940,0,1,1,1,1), -- Relentless Gladiator's Ornamented Legplates
(@KORALON25,42044,0,1,1,1,1), -- Relentless Gladiator's Pendant of Ascendancy
(@KORALON25,42046,0,1,1,1,1), -- Relentless Gladiator's Pendant of Deliverance
(@KORALON25,42043,0,1,1,1,1), -- Relentless Gladiator's Pendant of Dominance
(@KORALON25,42047,0,1,1,1,1), -- Relentless Gladiator's Pendant of Salvation
(@KORALON25,42045,0,1,1,1,1), -- Relentless Gladiator's Pendant of Subjugation
(@KORALON25,46374,0,1,1,1,1), -- Relentless Gladiator's Pendant of Sundering
(@KORALON25,42041,0,1,1,1,1), -- Relentless Gladiator's Pendant of Triumph
(@KORALON25,42042,0,1,1,1,1), -- Relentless Gladiator's Pendant of Victory
(@KORALON25,40810,0,1,1,1,1), -- Relentless Gladiator's Plate Gauntlets
(@KORALON25,40850,0,1,1,1,1), -- Relentless Gladiator's Plate Legguards
(@KORALON25,41002,0,1,1,1,1), -- Relentless Gladiator's Ringmail Gauntlets
(@KORALON25,41028,0,1,1,1,1), -- Relentless Gladiator's Ringmail Leggings
(@KORALON25,41076,0,1,1,1,1), -- Relentless Gladiator's Sabatons of Dominance
(@KORALON25,41056,0,1,1,1,1), -- Relentless Gladiator's Sabatons of Salvation
(@KORALON25,41231,0,1,1,1,1), -- Relentless Gladiator's Sabatons of Triumph
(@KORALON25,41941,0,1,1,1,1), -- Relentless Gladiator's Satin Gloves
(@KORALON25,41928,0,1,1,1,1), -- Relentless Gladiator's Satin Leggings
(@KORALON25,40812,0,1,1,1,1), -- Relentless Gladiator's Scaled Gauntlets
(@KORALON25,40852,0,1,1,1,1), -- Relentless Gladiator's Scaled Legguards
(@KORALON25,41972,0,1,1,1,1), -- Relentless Gladiator's Silk Handguards
(@KORALON25,41960,0,1,1,1,1), -- Relentless Gladiator's Silk Trousers
(@KORALON25,41904,0,1,1,1,1), -- Relentless Gladiator's Treads of Dominance
(@KORALON25,41886,0,1,1,1,1), -- Relentless Gladiator's Treads of Salvation
(@KORALON25,41071,0,1,1,1,1), -- Relentless Gladiator's Waistguard of Dominance
(@KORALON25,41052,0,1,1,1,1), -- Relentless Gladiator's Waistguard of Salvation
(@KORALON25,41236,0,1,1,1,1), -- Relentless Gladiator's Waistguard of Triumph
(@KORALON25,41066,0,1,1,1,1), -- Relentless Gladiator's Wristguards of Dominance
(@KORALON25,41061,0,1,1,1,1), -- Relentless Gladiator's Wristguards of Salvation
(@KORALON25,41226,0,1,1,1,1), -- Relentless Gladiator's Wristguards of Triumph
(@KORALON25,41294,0,1,1,1,1), -- Relentless Gladiator's Wyrmhide Gloves
(@KORALON25,41305,0,1,1,1,1), -- Relentless Gladiator's Wyrmhide Legguards
(@KORALON25,48094,0,1,1,1,1), -- Zabra's Pants of Triumph
(@KORALON25,48064,0,1,1,1,1), -- Zabra's Leggings of Triumph
(@KORALON25,48096,0,1,1,1,1), -- Zabra's Handwraps of Triumph
(@KORALON25,48066,0,1,1,1,1), -- Zabra's Gloves of Triumph
(@KORALON25,48271,0,1,1,1,1), -- Windrunner's Legguards of Triumph
(@KORALON25,48273,0,1,1,1,1), -- Windrunner's Handguards of Triumph
(@KORALON25,48362,0,1,1,1,1), -- Thrall's War-Kilt of Triumph
(@KORALON25,48303,0,1,1,1,1), -- Thrall's Legguards of Triumph
(@KORALON25,48332,0,1,1,1,1), -- Thrall's Kilt of Triumph
(@KORALON25,48301,0,1,1,1,1), -- Thrall's Handguards of Triumph
(@KORALON25,48364,0,1,1,1,1), -- Thrall's Grips of Triumph
(@KORALON25,48334,0,1,1,1,1), -- Thrall's Gloves of Triumph
(@KORALON25,47770,0,1,1,1,1), -- Sunstrider's Leggings of Triumph
(@KORALON25,47772,0,1,1,1,1), -- Sunstrider's Gauntlets of Triumph
(@KORALON25,48180,0,1,1,1,1), -- Runetotem's Trousers of Triumph
(@KORALON25,48195,0,1,1,1,1), -- Runetotem's Legguards of Triumph
(@KORALON25,48150,0,1,1,1,1), -- Runetotem's Leggings of Triumph
(@KORALON25,48152,0,1,1,1,1), -- Runetotem's Handguards of Triumph
(@KORALON25,48193,0,1,1,1,1), -- Runetotem's Handgrips of Triumph
(@KORALON25,48182,0,1,1,1,1), -- Runetotem's Gloves of Triumph
(@KORALON25,48623,0,1,1,1,1), -- Liadrin's Legplates of Triumph
(@KORALON25,48660,0,1,1,1,1), -- Liadrin's Legguards of Triumph
(@KORALON25,48658,0,1,1,1,1), -- Liadrin's Handguards of Triumph
(@KORALON25,48591,0,1,1,1,1), -- Liadrin's Greaves of Triumph
(@KORALON25,48593,0,1,1,1,1), -- Liadrin's Gloves of Triumph
(@KORALON25,48625,0,1,1,1,1), -- Liadrin's Gauntlets of Triumph
(@KORALON25,48497,0,1,1,1,1), -- Koltira's Legplates of Triumph
(@KORALON25,48554,0,1,1,1,1), -- Koltira's Legguards of Triumph
(@KORALON25,48556,0,1,1,1,1), -- Koltira's Handguards of Triumph
(@KORALON25,48499,0,1,1,1,1), -- Koltira's Gauntlets of Triumph
(@KORALON25,48394,0,1,1,1,1), -- Hellscream's Legplates of Triumph
(@KORALON25,48464,0,1,1,1,1), -- Hellscream's Legguards of Triumph
(@KORALON25,48462,0,1,1,1,1), -- Hellscream's Handguards of Triumph
(@KORALON25,48392,0,1,1,1,1), -- Hellscream's Gauntlets of Triumph
(@KORALON25,47805,0,1,1,1,1), -- Gul'dan's Leggings of Triumph
(@KORALON25,47803,0,1,1,1,1), -- Gul'dan's Gloves of Triumph
(@KORALON25,48239,0,1,1,1,1), -- Garona's Legplates of Triumph
(@KORALON25,48241,0,1,1,1,1), -- Garona's Gauntlets of Triumph
(@KORALON25,48379,0,1,2,1,1), -- Wrynn's Legplates of Triumph
(@KORALON25,48446,0,1,2,1,1), -- Wrynn's Legguards of Triumph
(@KORALON25,48452,0,1,2,1,1), -- Wrynn's Handguards of Triumph
(@KORALON25,48377,0,1,2,1,1), -- Wrynn's Gauntlets of Triumph
(@KORALON25,48258,0,1,2,1,1), -- Windrunner's Legguards of Triumph
(@KORALON25,48256,0,1,2,1,1), -- Windrunner's Handguards of Triumph
(@KORALON25,48079,0,1,2,1,1), -- Velen's Pants of Triumph
(@KORALON25,48077,0,1,2,1,1), -- Velen's Handwraps of Triumph
(@KORALON25,47983,0,1,2,1,1), -- Velen's Gloves of Triumph
(@KORALON25,48226,0,1,2,1,1), -- VanCleef's Legplates of Triumph
(@KORALON25,48224,0,1,2,1,1), -- VanCleef's Gauntlets of Triumph
(@KORALON25,48610,0,1,2,1,1), -- Turalyon's Legplates of Triumph
(@KORALON25,48638,0,1,2,1,1), -- Turalyon's Legguards of Triumph
(@KORALON25,48640,0,1,2,1,1), -- Turalyon's Handguards of Triumph
(@KORALON25,48578,0,1,2,1,1), -- Turalyon's Greaves of Triumph
(@KORALON25,48576,0,1,2,1,1), -- Turalyon's Gloves of Triumph
(@KORALON25,48608,0,1,2,1,1), -- Turalyon's Gauntlets of Triumph
(@KORALON25,48484,0,1,2,1,1), -- Thassarian's Legplates of Triumph
(@KORALON25,48541,0,1,2,1,1), -- Thassarian's Legguards of Triumph
(@KORALON25,48539,0,1,2,1,1), -- Thassarian's Handguards of Triumph
(@KORALON25,48482,0,1,2,1,1), -- Thassarian's Gauntlets of Triumph
(@KORALON25,48349,0,1,2,1,1), -- Nobundo's War-Kilt of Triumph
(@KORALON25,48288,0,1,2,1,1), -- Nobundo's Legguards of Triumph
(@KORALON25,48319,0,1,2,1,1), -- Nobundo's Kilt of Triumph
(@KORALON25,48286,0,1,2,1,1), -- Nobundo's Handguards of Triumph
(@KORALON25,48347,0,1,2,1,1), -- Nobundo's Grips of Triumph
(@KORALON25,48317,0,1,2,1,1), -- Nobundo's Gloves of Triumph
(@KORALON25,48165,0,1,2,1,1), -- Malfurion's Trousers of Triumph
(@KORALON25,48210,0,1,2,1,1), -- Malfurion's Legguards of Triumph
(@KORALON25,48135,0,1,2,1,1), -- Malfurion's Leggings of Triumph
(@KORALON25,48133,0,1,2,1,1), -- Malfurion's Handguards of Triumph
(@KORALON25,48212,0,1,2,1,1), -- Malfurion's Handgrips of Triumph
(@KORALON25,48163,0,1,2,1,1), -- Malfurion's Gloves of Triumph
(@KORALON25,47755,0,1,2,1,1), -- Khadgar's Leggings of Triumph
(@KORALON25,47753,0,1,2,1,1), -- Khadgar's Gauntlets of Triumph
(@KORALON25,47780,0,1,2,1,1), -- Kel'Thuzad's Leggings of Triumph
(@KORALON25,47782,0,1,2,1,1), -- Kel'Thuzad's Gloves of Triumph
(@KORALON25,47985,0,1,2,1,1); -- Velen's Leggings of Triumph
-- Merge PVP and PVE items to one ref
UPDATE `reference_loot_template` SET `entry`=@TORAVON25 WHERE `entry`=34214; -- 25 Toravon
UPDATE `reference_loot_template` SET `entry`=@TORAVON10 WHERE `entry`=34213; -- 10 Toravon
UPDATE `reference_loot_template` SET `entry`=@ARCHAVON10 WHERE `entry`=34210; -- 10 Archavon
UPDATE `reference_loot_template` SET `entry`=@EMALON10 WHERE `entry`=34211; -- 10 Emalon
UPDATE `reference_loot_template` SET `entry`=@KORALON10 WHERE `entry`=34212; -- 10 Koralon
-- Assign to cratures
SET @Tora10 =38433;
SET @Tora25 =38462;
SET @Arch10 =31125;
SET @Arch25 =31722;
SET @Emal10 =33993;
SET @Emal25 =33994;
SET @Kora10 =35013;
SET @Kora25 =35360;
DELETE FROM `creature_loot_template` WHERE `entry`IN (@Tora10,@Tora25,@Arch10,@Arch25,@Emal10,@Emal25,@Kora10,@Kora25);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Update loot template for Toravon 10
(@Tora10,47241,100,1,0,2,2), -- Emblem of triumph
(@Tora10,1,100,1,0,-@TORAVON10,2), -- Gear(Relentless PVP,T10 PVE)
(@Tora10,2,1,1,0,-34203,1), -- Mount
-- Update loot template for Toravon 25 to drop 3 items
(@Tora25,49426,100,1,0,2,2), -- Emblem of frost
(@Tora25,1,100,1,0,-@TORAVON25,3), -- Gear(Wrathful PVP,T10.5 PVE)
(@Tora25,2,1,1,0,-34203,1), -- Mount
-- Update loot template for Archavon 10
(@Arch10,47241,100,1,0,2,2), -- Emblem of triumph
(@Arch10,1,100,1,0,-@ARCHAVON10,2), -- Gear(Hate PVP,T7 PVE)
(@Arch10,2,1,1,0,-34203,1), -- Mount
-- Update loot template for Archavon 25
(@Arch25,47241,100,1,0,2,2), -- Emblem of triumph
(@Arch25,1,100,1,0,-@ARCHAVON25,4), -- Gear(Deadly PVP,T7(25) PVE)
(@Arch25,2,1,1,0,-34203,1), -- Mount
-- Update loot template for Emalon 10
(@Emal10,47241,100,1,0,2,2), -- Emblem of triumph
(@Emal10,1,100,1,0,-@EMALON10,2), -- Gear(Deadly PVP,T8 PVE)
(@Emal10,2,1,1,0,-34203,1), -- Mount
-- Update loot template for Emalon 25
(@Emal25,47241,100,1,0,2,2), -- Emblem of triumph
(@Emal25,1,100,1,0,-@EMALON25,4), -- Gear(Deadly PVP,T8(25) PVE)
(@Emal25,2,1,1,0,-34203,1), -- Mount
-- Update loot template for Koralon 10
(@Kora10,47241,100,1,0,2,2), -- Emblem of triumph
(@Kora10,1,100,1,0,-@KORALON10,2), -- Gear(Furious PVP,T9 PVE)
(@Kora10,2,1,1,0,-34203,1), -- Mount
-- Update loot template for Koralon 25
(@Kora25,47241,100,1,0,2,2), -- Emblem of triumph
(@Kora25,1,100,1,0,-@KORALON25,4), -- Gear(Relentless PVP,T9.5 PVE)
(@Kora25,2,1,1,0,-34203,1); -- Mount
