-- Trashloot for ICC/FoS/PoS/HoR
-- Generic
SET @ICC_TrashGenericGrey := 35063; -- Set by TDB (need x)
SET @ICC_TrashGenericWhite := @ICC_TrashGenericGrey+1;
SET @ICC_TrashGenericScroll := @ICC_TrashGenericGrey+2;
SET @ICC_TrashGenericGreen := @ICC_TrashGenericGrey+3;
SET @ICC_TrashGenericBlue := @ICC_TrashGenericGrey+4;
SET @ICC_TrashGenericPurpleICC := @ICC_TrashGenericGrey+5;
SET @ICC_TrashCitadelFinal := @ICC_TrashGenericGrey+6;
SET @ICC_TrashGenericPurpleDUNN := @ICC_TrashGenericGrey+7;
SET @ICC_TrashDungeonNFinal := @ICC_TrashGenericGrey+8;
SET @ICC_TrashGenericPurpleDUNH := @ICC_TrashGenericGrey+9;
SET @ICC_TrashDungeonHFinal := @ICC_TrashGenericGrey+10;

DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN @ICC_TrashGenericGrey AND @ICC_TrashGenericGrey+10; 
DELETE FROM `reference_loot_template` WHERE `entry` BETWEEN 35063 AND 35076; -- cleanup OLD loot
INSERT INTO reference_loot_template (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- grey items (45)
(@ICC_TrashGenericGrey,33430,0,1,1,1,1), -- Abandoned Greatsword
(@ICC_TrashGenericGrey,33426,0,1,1,1,1), -- Chipped Timber Axe
(@ICC_TrashGenericGrey,33424,0,1,1,1,1), -- Cracked Iron Staff
(@ICC_TrashGenericGrey,33428,0,1,1,1,1), -- Dulled SHiv
(@ICC_TrashGenericGrey,33397,0,1,1,1,1), -- Frigid Mail Armor
(@ICC_TrashGenericGrey,33398,0,1,1,1,1), -- Frigid Mail Belt
(@ICC_TrashGenericGrey,33399,0,1,1,1,1), -- Frigid Mail Boots
(@ICC_TrashGenericGrey,33400,0,1,1,1,1), -- Frigid Mail Bracers
(@ICC_TrashGenericGrey,33433,0,1,1,1,1), -- Frigid Mail Circlet
(@ICC_TrashGenericGrey,33401,0,1,1,1,1), -- Frigid Mail Gloves
(@ICC_TrashGenericGrey,33402,0,1,1,1,1), -- Frigid Mail Pants
(@ICC_TrashGenericGrey,33403,0,1,1,1,1), -- Frigid Mail Shoulderpads
(@ICC_TrashGenericGrey,33427,0,1,1,1,1), -- Frost-Encrusted Rifle
(@ICC_TrashGenericGrey,33365,0,1,1,1,1), -- Frost-Rimed Cloth Belt
(@ICC_TrashGenericGrey,33366,0,1,1,1,1), -- Frost-Rimed Cloth Boots
(@ICC_TrashGenericGrey,33367,0,1,1,1,1), -- Frost-Rimed Cloth Bracers
(@ICC_TrashGenericGrey,33368,0,1,1,1,1), -- Frost-Rimed Cloth Gloves
(@ICC_TrashGenericGrey,33346,0,1,1,1,1), -- Frost-Rimed Cloth Hat
(@ICC_TrashGenericGrey,33369,0,1,1,1,1), -- Frost-Rimed Cloth Pants
(@ICC_TrashGenericGrey,33370,0,1,1,1,1), -- Frost-Rimed Cloth Shoulderpads
(@ICC_TrashGenericGrey,33371,0,1,1,1,1), -- Frost-Rimed Cloth Vest
(@ICC_TrashGenericGrey,33412,0,1,1,1,1), -- Frost-Worn Plate Belt
(@ICC_TrashGenericGrey,33413,0,1,1,1,1), -- Frost-Worn Plate Boots
(@ICC_TrashGenericGrey,33414,0,1,1,1,1), -- Frost-Worn Plate Bracers
(@ICC_TrashGenericGrey,33415,0,1,1,1,1), -- Frost-Worn Plate Chestpiece
(@ICC_TrashGenericGrey,33416,0,1,1,1,1), -- Frost-Worn Plate Gloves
(@ICC_TrashGenericGrey,33435,0,1,1,1,1), -- Frost-Worn Plate Helmet
(@ICC_TrashGenericGrey,33417,0,1,1,1,1), -- Frost-Worn Plate Pants
(@ICC_TrashGenericGrey,33419,0,1,1,1,1), -- Frost-Worn Plate Shoulderpads
(@ICC_TrashGenericGrey,33379,0,1,1,1,1), -- Frozen Armor
(@ICC_TrashGenericGrey,33380,0,1,1,1,1), -- Frozen Belt
(@ICC_TrashGenericGrey,33381,0,1,1,1,1), -- Frozen Boots
(@ICC_TrashGenericGrey,33382,0,1,1,1,1), -- Frozen Bracers
(@ICC_TrashGenericGrey,33383,0,1,1,1,1), -- Frozen Gloves
(@ICC_TrashGenericGrey,33434,0,1,1,1,1), -- Frozen Leather Helmet
(@ICC_TrashGenericGrey,33384,0,1,1,1,1), -- Frozen Pants
(@ICC_TrashGenericGrey,33385,0,1,1,1,1), -- Frozen Shoulderpads
(@ICC_TrashGenericGrey,33429,0,1,1,1,1), -- Ice Cleaver
(@ICC_TrashGenericGrey,33425,0,1,1,1,1), -- Ice-Pitted Blade
(@ICC_TrashGenericGrey,33431,0,1,1,1,1), -- Icesmashing Mace
(@ICC_TrashGenericGrey,33423,0,1,1,1,1), -- Rime-Covered Mace
(@ICC_TrashGenericGrey,33422,0,1,1,1,1), -- Shattered Bow
(@ICC_TrashGenericGrey,43852,70,1,1,1,1), -- Thick Fur Clothing Scraps (drops more often)
-- white items
(@ICC_TrashGenericWhite,33470,0,1,1,2,7), -- Frostweave Cloth
(@ICC_TrashGenericWhite,33445,0,1,1,1,1), -- Honeymint Tea
(@ICC_TrashGenericWhite,33454,0,1,1,1,1), -- Salted Venison
(@ICC_TrashGenericWhite,35947,0,1,1,1,1), -- Sparkling Frostcap
(@ICC_TrashGenericWhite,33447,0,1,1,1,1), -- Runic Healing Potion
(@ICC_TrashGenericWhite,33448,0,1,1,1,1), -- Runic Mana Potion
-- Scroll items
(@ICC_TrashGenericScroll,43463,0,1,1,1,1), -- Scroll of Agility VII
(@ICC_TrashGenericScroll,37091,0,1,1,1,1), -- Scroll of Intellect VII
(@ICC_TrashGenericScroll,37093,0,1,1,1,1), -- Scroll of Stamina VII
(@ICC_TrashGenericScroll,43465,0,1,1,1,1), -- Scroll of Strength VII
(@ICC_TrashGenericScroll,37097,0,1,1,1,1), -- Scroll of Spirit VII
(@ICC_TrashGenericScroll,43464,0,1,1,1,1), -- Scroll of Agility VIII
(@ICC_TrashGenericScroll,37092,0,1,1,1,1), -- Scroll of Intellect VIII
(@ICC_TrashGenericScroll,37094,0,1,1,1,1), -- Scroll of Stamina VIII
(@ICC_TrashGenericScroll,43466,0,1,1,1,1), -- Scroll of Strength VIII
(@ICC_TrashGenericScroll,37098,0,1,1,1,1), -- Scroll of Spirit VIII
-- green items (166)
(@ICC_TrashGenericGreen,36609,0,1,1,1,1), -- Abandoned Spear
(@ICC_TrashGenericGreen,36497,0,1,1,1,1), -- Adamant Mallet
(@ICC_TrashGenericGreen,36511,0,1,1,1,1), -- Artic War Hammer
(@ICC_TrashGenericGreen,36694,0,1,1,1,1), -- Beatific Mace
(@ICC_TrashGenericGreen,36527,0,1,1,1,1), -- Blackened Blade
(@ICC_TrashGenericGreen,36611,0,1,1,1,1), -- Black Scythe
(@ICC_TrashGenericGreen,36638,0,1,1,1,1), -- Bloody Crossbow
(@ICC_TrashGenericGreen,36428,0,1,1,1,1), -- Bouquet Ring
(@ICC_TrashGenericGreen,36639,0,1,1,1,1), -- Brutal Ballista
(@ICC_TrashGenericGreen,36707,0,1,1,1,1), -- Cascading Water Staff
(@ICC_TrashGenericGreen,36539,0,1,1,1,1), -- Chilled Warblade
(@ICC_TrashGenericGreen,36723,0,1,1,1,1), -- Clawed Shuriken
(@ICC_TrashGenericGreen,36035,0,1,1,1,1), -- Condor Belt
(@ICC_TrashGenericGreen,36042,0,1,1,1,1), -- Condor Bindings
(@ICC_TrashGenericGreen,36038,0,1,1,1,1), -- Condor Gloves
(@ICC_TrashGenericGreen,36039,0,1,1,1,1), -- Condor Headpiece
(@ICC_TrashGenericGreen,36040,0,1,1,1,1), -- Condor Pants
(@ICC_TrashGenericGreen,36037,0,1,1,1,1), -- Condor Robe
(@ICC_TrashGenericGreen,36036,0,1,1,1,1), -- Condor Sandals
(@ICC_TrashGenericGreen,36041,0,1,1,1,1), -- Condor Shoulderpads
(@ICC_TrashGenericGreen,36266,0,1,1,1,1), -- Cormorant Bracelets
(@ICC_TrashGenericGreen,36261,0,1,1,1,1), -- Cormorant Chain Vest
(@ICC_TrashGenericGreen,36260,0,1,1,1,1), -- Cormorant Footwraps
(@ICC_TrashGenericGreen,36262,0,1,1,1,1), -- Cormorant Gloves
(@ICC_TrashGenericGreen,36263,0,1,1,1,1), -- Cormorant Helm
(@ICC_TrashGenericGreen,36264,0,1,1,1,1), -- Cormorant Leggings
(@ICC_TrashGenericGreen,36265,0,1,1,1,1), -- Cormorant Mantle
(@ICC_TrashGenericGreen,36259,0,1,1,1,1), -- Cormorant Waistband
(@ICC_TrashGenericGreen,36525,0,1,1,1,1), -- Craggy Machete
(@ICC_TrashGenericGreen,36709,0,1,1,1,1), -- Crystal Woodstaff
(@ICC_TrashGenericGreen,36050,0,1,1,1,1), -- Crystalsong Bracelets
(@ICC_TrashGenericGreen,36047,0,1,1,1,1), -- Crystalsong Crown
(@ICC_TrashGenericGreen,36046,0,1,1,1,1), -- Crystalsong Gloves
(@ICC_TrashGenericGreen,36048,0,1,1,1,1), -- Crystalsong Leggings
(@ICC_TrashGenericGreen,36049,0,1,1,1,1), -- Crystalsong Mantle
(@ICC_TrashGenericGreen,36045,0,1,1,1,1), -- Crystalsong Robe
(@ICC_TrashGenericGreen,36043,0,1,1,1,1), -- Crystalsong Sash
(@ICC_TrashGenericGreen,36044,0,1,1,1,1), -- Crystalsong Slippers
(@ICC_TrashGenericGreen,36554,0,1,1,1,1), -- Cursed Staff
(@ICC_TrashGenericGreen,43297,0,1,1,1,1), -- Damaged Necklace
(@ICC_TrashGenericGreen,36553,0,1,1,1,1), -- Desecrated Staff
(@ICC_TrashGenericGreen,36695,0,1,1,1,1), -- Dogmatic Scepter
(@ICC_TrashGenericGreen,36721,0,1,1,1,1), -- Dragon's Teeth
(@ICC_TrashGenericGreen,36413,0,1,1,1,1), -- Dyed Taffeta Cape
(@ICC_TrashGenericGreen,36427,0,1,1,1,1), -- Engraved Ring
(@ICC_TrashGenericGreen,36484,0,1,1,1,1), -- Etched Dagger
(@ICC_TrashGenericGreen,36499,0,1,1,1,1), -- Frigid War-Mace
(@ICC_TrashGenericGreen,36470,0,1,1,1,1), -- Gilded Scepter
(@ICC_TrashGenericGreen,36381,0,1,1,1,1), -- Golem Breastplate
(@ICC_TrashGenericGreen,36382,0,1,1,1,1), -- Golem Gauntlets
(@ICC_TrashGenericGreen,36379,0,1,1,1,1), -- Golem Girdle
(@ICC_TrashGenericGreen,36383,0,1,1,1,1), -- Golem Helmet
(@ICC_TrashGenericGreen,36384,0,1,1,1,1), -- Golem Legplates
(@ICC_TrashGenericGreen,36385,0,1,1,1,1), -- Golem Pauldrons
(@ICC_TrashGenericGreen,36380,0,1,1,1,1), -- Golem Sabatons
(@ICC_TrashGenericGreen,36386,0,1,1,1,1), -- Golem Vambraces
(@ICC_TrashGenericGreen,36623,0,1,1,1,1), -- Harnessed Longbow
(@ICC_TrashGenericGreen,36568,0,1,1,1,1), -- Hollowed Bone Knuckles
(@ICC_TrashGenericGreen,36637,0,1,1,1,1), -- Horrific Crossbow
(@ICC_TrashGenericGreen,36471,0,1,1,1,1), -- Ice Crystal
(@ICC_TrashGenericGreen,36582,0,1,1,1,1), -- Ice Pick
(@ICC_TrashGenericGreen,36597,0,1,1,1,1), -- Ice-Splintering Axe
(@ICC_TrashGenericGreen,36456,0,1,1,1,1), -- Ice Kite Shield
(@ICC_TrashGenericGreen,36457,0,1,1,1,1), -- Ivory Shield
(@ICC_TrashGenericGreen,36373,0,1,1,1,1), -- Kraken Breastplate
(@ICC_TrashGenericGreen,36377,0,1,1,1,1), -- Kraken Epaulets
(@ICC_TrashGenericGreen,36374,0,1,1,1,1), -- Kraken Gauntlets
(@ICC_TrashGenericGreen,36371,0,1,1,1,1), -- Kraken Girdle
(@ICC_TrashGenericGreen,36372,0,1,1,1,1), -- Kraken Greaves
(@ICC_TrashGenericGreen,36375,0,1,1,1,1), -- Kraken Helm
(@ICC_TrashGenericGreen,36376,0,1,1,1,1), -- Kraken Legplates
(@ICC_TrashGenericGreen,36378,0,1,1,1,1), -- Kraken Vambraces
(@ICC_TrashGenericGreen,36469,0,1,1,1,1), -- Lidless Orb
(@ICC_TrashGenericGreen,36513,0,1,1,1,1), -- Lode-Headed Hammer
(@ICC_TrashGenericGreen,36414,0,1,1,1,1), -- Mammoth Fur Cloack
(@ICC_TrashGenericGreen,36483,0,1,1,1,1), -- Mandible Edge
(@ICC_TrashGenericGreen,36625,0,1,1,1,1), -- Massive Recurved Bow
(@ICC_TrashGenericGreen,36555,0,1,1,1,1), -- Minion Staff
(@ICC_TrashGenericGreen,36651,0,1,1,1,1), -- Muzzled Musket
(@ICC_TrashGenericGreen,36680,0,1,1,1,1), -- Mystic Fang
(@ICC_TrashGenericGreen,36498,0,1,1,1,1), -- Nerubian Mace
(@ICC_TrashGenericGreen,36512,0,1,1,1,1), -- Onerous Mallet
(@ICC_TrashGenericGreen,36441,0,1,1,1,1), -- Pearl Woven Choker
(@ICC_TrashGenericGreen,36540,0,1,1,1,1), -- Petrified Sword
(@ICC_TrashGenericGreen,36610,0,1,1,1,1), -- Plagued Pike
(@ICC_TrashGenericGreen,36595,0,1,1,1,1), -- Planate Broadaxe
(@ICC_TrashGenericGreen,36455,0,1,1,1,1), -- Plated Bulwark
(@ICC_TrashGenericGreen,36443,0,1,1,1,1), -- Platinum Medallion
(@ICC_TrashGenericGreen,36666,0,1,1,1,1), -- Polar Wand
(@ICC_TrashGenericGreen,36653,0,1,1,1,1), -- Precipice Longrifle
(@ICC_TrashGenericGreen,36147,0,1,1,1,1), -- Pygmy Belt
(@ICC_TrashGenericGreen,36154,0,1,1,1,1), -- Pygmy Bindings
(@ICC_TrashGenericGreen,36148,0,1,1,1,1), -- Pygmy Boots
(@ICC_TrashGenericGreen,36150,0,1,1,1,1), -- Pygmy Gloves
(@ICC_TrashGenericGreen,36151,0,1,1,1,1), -- Pygmy Helmet
(@ICC_TrashGenericGreen,36152,0,1,1,1,1), -- Pygmy Pants
(@ICC_TrashGenericGreen,36153,0,1,1,1,1), -- Pygmy Shoulders
(@ICC_TrashGenericGreen,36149,0,1,1,1,1), -- Pygmy Tunic
(@ICC_TrashGenericGreen,36722,0,1,1,1,1), -- Pyramid Throwing Star
(@ICC_TrashGenericGreen,36389,0,1,1,1,1), -- Revenant Armor
(@ICC_TrashGenericGreen,36387,0,1,1,1,1), -- Revenant Belt
(@ICC_TrashGenericGreen,36394,0,1,1,1,1), -- Revenant Bracers
(@ICC_TrashGenericGreen,36393,0,1,1,1,1), -- Revenant Epaulets
(@ICC_TrashGenericGreen,36390,0,1,1,1,1), -- Revenant Gauntlets
(@ICC_TrashGenericGreen,36388,0,1,1,1,1), -- Revenant Greaves
(@ICC_TrashGenericGreen,36391,0,1,1,1,1), -- Revenant Helmet
(@ICC_TrashGenericGreen,36392,0,1,1,1,1), -- Revenant Legguards
(@ICC_TrashGenericGreen,36596,0,1,1,1,1), -- Rupturing Axe
(@ICC_TrashGenericGreen,36569,0,1,1,1,1), -- Savage Talons
(@ICC_TrashGenericGreen,36693,0,1,1,1,1), -- Serene Hammer
(@ICC_TrashGenericGreen,36624,0,1,1,1,1), -- Shrieking Bow
(@ICC_TrashGenericGreen,36442,0,1,1,1,1), -- Silken Cord Amulet
(@ICC_TrashGenericGreen,36679,0,1,1,1,1), -- Singing Dagger
(@ICC_TrashGenericGreen,36485,0,1,1,1,1), -- Sinuous Keris
(@ICC_TrashGenericGreen,36567,0,1,1,1,1), -- Six-Fingered Claws
(@ICC_TrashGenericGreen,36583,0,1,1,1,1), -- Skeletal Hacker
(@ICC_TrashGenericGreen,36526,0,1,1,1,1), -- SLeeted Longsword
(@ICC_TrashGenericGreen,36708,0,1,1,1,1), -- Snow Blossom Staff
(@ICC_TrashGenericGreen,36667,0,1,1,1,1), -- Solid Ice Wand
(@ICC_TrashGenericGreen,36275,0,1,1,1,1), -- Spiderlord Belt
(@ICC_TrashGenericGreen,36276,0,1,1,1,1), -- Spiderlord Boots
(@ICC_TrashGenericGreen,36282,0,1,1,1,1), -- Spiderlord Bracers
(@ICC_TrashGenericGreen,36277,0,1,1,1,1), -- Spiderlord Chestpiece
(@ICC_TrashGenericGreen,36278,0,1,1,1,1), -- Spiderlord Gauntlets
(@ICC_TrashGenericGreen,36279,0,1,1,1,1), -- Spiderlord Helm
(@ICC_TrashGenericGreen,36280,0,1,1,1,1), -- Spiderlord Legguards
(@ICC_TrashGenericGreen,36281,0,1,1,1,1), -- Spiderlord Spaulders
(@ICC_TrashGenericGreen,36429,0,1,1,1,1), -- Spur Ring
(@ICC_TrashGenericGreen,36652,0,1,1,1,1), -- Stocky Shotgun
(@ICC_TrashGenericGreen,36274,0,1,1,1,1), -- Ulduar Bracers
(@ICC_TrashGenericGreen,36269,0,1,1,1,1), -- Ulduar Breastplate
(@ICC_TrashGenericGreen,36270,0,1,1,1,1), -- Ulduar Gauntlets
(@ICC_TrashGenericGreen,36267,0,1,1,1,1), -- Ulduar Girdle
(@ICC_TrashGenericGreen,36268,0,1,1,1,1), -- Ulduar Greaves
(@ICC_TrashGenericGreen,36271,0,1,1,1,1), -- Ulduar Helm
(@ICC_TrashGenericGreen,36272,0,1,1,1,1), -- Ulduar Legguards
(@ICC_TrashGenericGreen,36273,0,1,1,1,1), -- Ulduar Shoulderguards
(@ICC_TrashGenericGreen,36415,0,1,1,1,1), -- Vintage Satin Cloak
(@ICC_TrashGenericGreen,36058,0,1,1,1,1), -- Vizier Bracelets
(@ICC_TrashGenericGreen,36054,0,1,1,1,1), -- Vizier Gloves
(@ICC_TrashGenericGreen,36055,0,1,1,1,1), -- Vizier Hood
(@ICC_TrashGenericGreen,36056,0,1,1,1,1), -- Vizier Leggings
(@ICC_TrashGenericGreen,36057,0,1,1,1,1), -- Vizier Mantle
(@ICC_TrashGenericGreen,36053,0,1,1,1,1), -- Vizier Robe
(@ICC_TrashGenericGreen,36051,0,1,1,1,1), -- Vizier Sash
(@ICC_TrashGenericGreen,36052,0,1,1,1,1), -- Vizier SLippers
(@ICC_TrashGenericGreen,36665,0,1,1,1,1), -- Wasteland Wand
(@ICC_TrashGenericGreen,36170,0,1,1,1,1), -- Webspinner Bindings
(@ICC_TrashGenericGreen,36164,0,1,1,1,1), -- Webspinner Boots
(@ICC_TrashGenericGreen,36163,0,1,1,1,1), -- Webspinner Cord
(@ICC_TrashGenericGreen,36166,0,1,1,1,1), -- Webspinner Gloves
(@ICC_TrashGenericGreen,36167,0,1,1,1,1), -- Webspinner Hood
(@ICC_TrashGenericGreen,36168,0,1,1,1,1), -- Webspinner Leggings
(@ICC_TrashGenericGreen,36169,0,1,1,1,1), -- Webspinner Shoulderguards
(@ICC_TrashGenericGreen,36165,0,1,1,1,1), -- Webspinner Vest
(@ICC_TrashGenericGreen,36162,0,1,1,1,1), -- Wendigo Bands
(@ICC_TrashGenericGreen,36156,0,1,1,1,1), -- Wendigo Boots
(@ICC_TrashGenericGreen,36157,0,1,1,1,1), -- Wendigo Chestpiece
(@ICC_TrashGenericGreen,36155,0,1,1,1,1), -- Wendigo Girdle
(@ICC_TrashGenericGreen,36158,0,1,1,1,1), -- Wendigo Gloves
(@ICC_TrashGenericGreen,36159,0,1,1,1,1), -- Wendigo Hood
(@ICC_TrashGenericGreen,36160,0,1,1,1,1), -- Wendigo Legguards
(@ICC_TrashGenericGreen,36161,0,1,1,1,1), -- Wendigo Pauldrons
(@ICC_TrashGenericGreen,36541,0,1,1,1,1), -- Wintry Claymore
(@ICC_TrashGenericGreen,36681,0,1,1,1,1), -- Wisdom Carver
(@ICC_TrashGenericGreen,36581,0,1,1,1,1), -- Wolvar Handaxe
-- blue items
(@ICC_TrashGenericBlue,37792,0,1,1,1,1), -- Agin's Crushing Carapace
(@ICC_TrashGenericBlue,37770,0,1,1,1,1), -- Bulge-Concealing Breastplate
(@ICC_TrashGenericBlue,37780,0,1,1,1,1), -- Condor-Bone Chestguard
(@ICC_TrashGenericBlue,37760,0,1,1,1,1), -- Cracklefire Wristguards
(@ICC_TrashGenericBlue,37781,0,1,1,1,1), -- Grips of the Warming Heart
(@ICC_TrashGenericBlue,37824,0,1,1,1,1), -- Gwyneth's Runed Dragonwand
(@ICC_TrashGenericBlue,37761,0,1,1,1,1), -- Shimmerthread Girdle
(@ICC_TrashGenericBlue,37793,0,1,1,1,1), -- Skullcage of Eternal Terror
(@ICC_TrashGenericBlue,37794,0,1,1,1,1), -- Torta's Oversized Choker
(@ICC_TrashGenericBlue,37822,0,1,1,1,1), -- Twisted Puzzle-Ring
(@ICC_TrashGenericBlue,37771,0,1,1,1,1), -- Wristguard of Verdant Recovery
-- Designs
(@ICC_TrashGenericBlue,41788,0,1,1,1,1), -- Design: Beaming Earthsiege Diamond
(@ICC_TrashGenericBlue,41780,0,1,1,1,1), -- Design: Champion's Monarch Topaz
(@ICC_TrashGenericBlue,41786,0,1,1,1,1), -- Design: Destructive Skyflare Diamond
(@ICC_TrashGenericBlue,41777,0,1,1,1,1), -- Design: Etched Monarch Topaz
(@ICC_TrashGenericBlue,41789,0,1,1,1,1), -- Design: Inscribed Monarch Topaz
(@ICC_TrashGenericBlue,41781,0,1,1,1,1), -- Design: Misty Forest Emerald
(@ICC_TrashGenericBlue,41783,0,1,1,1,1), -- Design: Purified Twilight Opal
(@ICC_TrashGenericBlue,41778,0,1,1,1,1), -- Design: Resolute MOnarch Topaz
(@ICC_TrashGenericBlue,41782,0,1,1,1,1), -- Design: Shining Forest Emerald
(@ICC_TrashGenericBlue,41784,0,1,1,1,1), -- Design: Sovereign Twilight Opal
(@ICC_TrashGenericBlue,41779,0,1,1,1,1), -- Design: Stalwart Monarch Topaz
(@ICC_TrashGenericBlue,41785,0,1,1,1,1), -- Design: Tenuous Twilight Opal
(@ICC_TrashGenericBlue,41787,0,1,1,1,1), -- Design: Thundering Skyflare Diamond
-- tailoring
(@ICC_TrashGenericBlue,43876,0,1,1,1,1), -- A Guide to Northern Cloth Scavenging
-- purple items icc (8)
(@ICC_TrashGenericPurpleICC,44311,0,1,1,1,1), -- Avool's Sword of Jin
(@ICC_TrashGenericPurpleICC,37835,0,1,1,1,1), -- Je'Tze's Bell
(@ICC_TrashGenericPurpleICC,44310,0,1,1,1,1), -- Namlak's Supernumerary Sticker
(@ICC_TrashGenericPurpleICC,44309,0,1,1,1,1), -- Sash of Jordan
(@ICC_TrashGenericPurpleICC,44308,0,1,1,1,1), -- Signet of Edward the Odd
(@ICC_TrashGenericPurpleICC,37254,0,1,1,1,1), -- Super Simian Sphere
(@ICC_TrashGenericPurpleICC,44312,0,1,1,1,1), -- Wapach's Spaulders of Solidarity
(@ICC_TrashGenericPurpleICC,44313,0,1,1,1,1), -- Zom's Crackling Bulwark
(@ICC_TrashGenericPurpleICC,50444,0,1,1,1,1), -- Rowan's Rifle of Silver Bullets
(@ICC_TrashGenericPurpleICC,50451,0,1,1,1,1), -- Belt of the Lonely Noble
(@ICC_TrashGenericPurpleICC,50775,0,1,1,1,1), -- Leggings of Dubious Charms
(@ICC_TrashGenericPurpleICC,50449,0,1,1,1,1), -- Stiffened Corpse Shoulderpads
(@ICC_TrashGenericPurpleICC,50453,0,1,1,1,1), -- Ring of Rotting Sinew
(@ICC_TrashGenericPurpleICC,50447,0,1,1,1,1), -- Harbinger's Bone Band
(@ICC_TrashGenericPurpleICC,50452,0,1,1,1,1), -- Wodin's Lucky Necklace
-- purple items dungeon_N (8)
(@ICC_TrashGenericPurpleDUNN,44311,0,1,1,1,1), -- Avool's Sword of Jin
(@ICC_TrashGenericPurpleDUNN,37835,0,1,1,1,1), -- Je'Tze's Bell
(@ICC_TrashGenericPurpleDUNN,44310,0,1,1,1,1), -- Namlak's Supernumerary Sticker
(@ICC_TrashGenericPurpleDUNN,44309,0,1,1,1,1), -- Sash of Jordan
(@ICC_TrashGenericPurpleDUNN,44308,0,1,1,1,1), -- Signet of Edward the Odd
(@ICC_TrashGenericPurpleDUNN,37254,0,1,1,1,1), -- Super Simian Sphere
(@ICC_TrashGenericPurpleDUNN,44312,0,1,1,1,1), -- Wapach's Spaulders of Solidarity
(@ICC_TrashGenericPurpleDUNN,44313,0,1,1,1,1), -- Zom's Crackling Bulwark
(@ICC_TrashGenericPurpleDUNN,49852,0,1,1,1,1), -- Coffin Nail
(@ICC_TrashGenericPurpleDUNN,49855,0,1,1,1,1), -- Plated Grips of Korth'azz
(@ICC_TrashGenericPurpleDUNN,49853,0,1,1,1,1), -- Titanium Links of Lore
(@ICC_TrashGenericPurpleDUNN,49854,0,1,1,1,1), -- Mantle of Tattered Feathers
-- purple items dungeon_H (8)
(@ICC_TrashGenericPurpleDUNH,44311,0,1,1,1,1), -- Avool's Sword of Jin
(@ICC_TrashGenericPurpleDUNH,37835,0,1,1,1,1), -- Je'Tze's Bell
(@ICC_TrashGenericPurpleDUNH,44310,0,1,1,1,1), -- Namlak's Supernumerary Sticker
(@ICC_TrashGenericPurpleDUNH,44309,0,1,1,1,1), -- Sash of Jordan
(@ICC_TrashGenericPurpleDUNH,44308,0,1,1,1,1), -- Signet of Edward the Odd
(@ICC_TrashGenericPurpleDUNH,37254,0,1,1,1,1), -- Super Simian Sphere
(@ICC_TrashGenericPurpleDUNH,44312,0,1,1,1,1), -- Wapach's Spaulders of Solidarity
(@ICC_TrashGenericPurpleDUNH,44313,0,1,1,1,1), -- Zom's Crackling Bulwark
(@ICC_TrashGenericPurpleDUNH,50319,0,1,1,1,1), -- Unsharpened Ice Razor
(@ICC_TrashGenericPurpleDUNH,50315,0,1,1,1,1), -- Seven-Fingered Claws
(@ICC_TrashGenericPurpleDUNH,50318,0,1,1,1,1), -- Ghostly Wristwraps
-- final output icc
(@ICC_TrashCitadelFinal,1,40,1,0,-@ICC_TrashGenericGrey,1), -- 1 grey loot (40%)
(@ICC_TrashCitadelFinal,2,40,1,0,-@ICC_TrashGenericGrey,1), -- 1 grey loot (40%)
(@ICC_TrashCitadelFinal,3,20,1,0,-@ICC_TrashGenericWhite,1), -- 1 white loot (20%)
(@ICC_TrashCitadelFinal,4,7,1,0,-@ICC_TrashGenericScroll,1), -- 1 scroll loot (7%)
(@ICC_TrashCitadelFinal,5,10,1,0,-@ICC_TrashGenericGreen,1), -- 1 green loot (10%)
(@ICC_TrashCitadelFinal,6,3,1,0,-@ICC_TrashGenericBlue,1), -- 1 blue loot (3%)
(@ICC_TrashCitadelFinal,7,1,1,0,-@ICC_TrashGenericPurpleICC,1), -- 1 purple loot (1%)
-- final output dungeon_n
(@ICC_TrashDungeonNFinal,1,40,1,0,-@ICC_TrashGenericGrey,1), -- 1 grey loot (40%)
(@ICC_TrashDungeonNFinal,2,40,1,0,-@ICC_TrashGenericGrey,1), -- 1 grey loot (40%)
(@ICC_TrashDungeonNFinal,3,20,1,0,-@ICC_TrashGenericWhite,1), -- 1 white loot (20%)
(@ICC_TrashDungeonNFinal,4,7,1,0,-@ICC_TrashGenericScroll,1), -- 1 scroll loot (7%)
(@ICC_TrashDungeonNFinal,5,10,1,0,-@ICC_TrashGenericGreen,1), -- 1 green loot (10%)
(@ICC_TrashDungeonNFinal,6,3,1,0,-@ICC_TrashGenericBlue,1), -- 1 blue loot (3%)
(@ICC_TrashDungeonNFinal,7,1,1,0,-@ICC_TrashGenericPurpleDUNN,1), -- 1 purple loot (1%)
-- final output dungeon_h
(@ICC_TrashDungeonHFinal,1,40,1,0,-@ICC_TrashGenericGrey,1), -- 1 grey loot (40%)
(@ICC_TrashDungeonHFinal,2,40,1,0,-@ICC_TrashGenericGrey,1), -- 1 grey loot (40%)
(@ICC_TrashDungeonHFinal,3,20,1,0,-@ICC_TrashGenericWhite,1), -- 1 white loot (20%)
(@ICC_TrashDungeonHFinal,4,7,1,0,-@ICC_TrashGenericScroll,1), -- 1 scroll loot (7%)
(@ICC_TrashDungeonHFinal,5,10,1,0,-@ICC_TrashGenericGreen,1), -- 1 green loot (10%)
(@ICC_TrashDungeonHFinal,6,3,1,0,-@ICC_TrashGenericBlue,1), -- 1 blue loot (3%)
(@ICC_TrashDungeonHFinal,7,1,1,0,-@ICC_TrashGenericPurpleDUNH,1); -- 1 purple loot (1%)

-- --------------------------------
-- -- Apply Trash Loot Dungeon_N --
-- --------------------------------
SET @LootDUNGEON_N := 100000; -- needs official entry designated
UPDATE `creature_template` SET `lootid`=@LootDUNGEON_N WHERE `entry` IN (36522,36620,36516,36564,36499,36478,36666); -- FoS
UPDATE `creature_template` SET `lootid`=@LootDUNGEON_N WHERE `entry` IN (36896,36842,36830,36879,37711,36788,37712,37713); -- PoS
UPDATE `creature_template` SET `lootid`=@LootDUNGEON_N WHERE `entry` IN (38176,38177,38173,38172,38175,36723); -- HoR
DELETE FROM `creature_loot_template` WHERE `entry` IN (36522,36620,36516,36564,36499,36478,36666,36896,36842,36830,36879,37711,36788,37712,37713,38176,38177,38173,38172,38175,36723,@LootDUNGEON_N);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@LootDUNGEON_N,1,100,1,0,-@ICC_TrashDungeonNFinal,2); -- 2 selection from reference

-- --------------------------------
-- -- Apply Trash Loot Dungeon_H --
-- -------------------------------- 
SET @LootDUNGEON_H := 100001; -- needs official entry designated
UPDATE `creature_template` SET `lootid`=@LootDUNGEON_H WHERE `entry` IN (37569,37568,37567,37565,38193,37566,37563); -- FoS
UPDATE `creature_template` SET `lootid`=@LootDUNGEON_H WHERE `entry` IN (37609,37638,37637,37635,37636,38249,38025,38026); -- PoS
UPDATE `creature_template` SET `lootid`=@LootDUNGEON_H WHERE `entry` IN (37720,38524,38525,38563,38544,38564); -- HoR
DELETE FROM `creature_loot_template` WHERE `entry` IN (37569,37568,37567,37565,38193,37566,37563,37609,37638,37637,37635,37636,38249,38025,38026,37720,38524,38525,38563,38544,38564,@LootDUNGEON_H);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@LootDUNGEON_H,1,100,1,0,-@ICC_TrashDungeonHFinal,2); -- 2 selection from reference

-- --------------------------
-- -- Apply Trash Loot ICC --
-- --------------------------
SET @LootRAID := 100002; -- needs official entry designated
UPDATE `creature_template` SET `lootid`=@LootRAID WHERE `entry` IN(37012,37022,37571,37664,37595,37662,37665,37663,37666,37007,36811,36807,36829,36805,36808,36880,37546,37531,37229,37228,36725,37501,37502,37023,10404,38494,38490,36724,37126,37544,37545,37098,37038);
DELETE FROM `creature_loot_template` WHERE `entry` IN(37012,37022,37571,37664,37595,37662,37665,37663,37666,37007,36811,36807,36829,36805,36808,36880,37546,37531,37229,37228,36725,37501,37502,37023,10404,38494,38490,36724,37126,37544,37545,37098,37038,@LootRAID);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
(@LootRAID,1,100,1,0,-@ICC_TrashCitadelFinal,2); -- 2 selection from reference

-- --------------------
-- -- Special Cases: --
-- --------------------
-- Specialids
CALL `sp_set_npc_lootid_bylist` ('37217,37025,37230,37532,36891',NULL);
-- Loot
DELETE FROM `creature_loot_template` WHERE `entry` IN (37217,37025,37230,37532,36891);
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`) VALUES
-- Precious
(37217,1,100,1,0,-@ICC_TrashCitadelFinal,2), -- 2 selection from reference
(37217,52019,30,1,0,1,1), -- Precious Ribbon
-- Stinky
(37025,1,100,1,0,-@ICC_TrashCitadelFinal,2), -- 2 selection from reference
-- Dragons (Spire Frostwyrm)
(37230,1,100,1,0,-@ICC_TrashCitadelFinal,2), -- 2 selection from reference
(37230,33631,65,1,1,2,3), -- Frosted Claw
(37230,33632,35,1,1,2,3), -- Icicle Fang
(37532,33631,65,1,1,2,3), -- Frosted Claw
(37532,33632,35,1,1,2,3), -- Icicle Fang
(36891,33631,65,1,1,2,3), -- Frosted Claw
(36891,33632,35,1,1,2,3); -- Icicle Fang
