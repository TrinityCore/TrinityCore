-- Added all tier 11 itemsets for the t11 vendors at stormwind and orgrimmar
DELETE FROM `npc_vendor` WHERE `entry` IN (58154, 58155);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`, `Type`) VALUES
(58154, 60244, 96, 0, 3033, 1), -- Firelord's Robes
(58154, 60247, 97, 0, 3034, 1), -- Firelord's Gloves
(58154, 60243, 98, 0, 3049, 1), -- Firelord's Hood
(58154, 60245, 99, 0, 3033, 1), -- Firelord's Leggings
(58154, 60246, 101, 0, 3043, 1), -- Firelord's Mantle

(58154, 60301, 103, 0, 3033, 1), -- Wind Dancer's Tunic
(58154, 60298, 104, 0, 3034, 1), -- Wind Dancer's Gloves
(58154, 60299, 105, 0, 3049, 1), -- Wind Dancer's Helmet
(58154, 60300, 106, 0, 3033, 1), -- Wind Dancer's Legguards
(58154, 60302, 107, 0, 3043, 1), -- Wind Dancer's Spaulders

(58154, 60339, 108, 0, 3033, 1), -- Magma Plated Battleplate
(58154, 60349, 109, 0, 3033, 1), -- Magma Plated Chestguard
(58154, 60340, 110, 0, 3034, 1), -- Magma Plated Gauntiets
(58154, 60350, 111, 0, 3034, 1), -- Magma Plated Handguards
(58154, 60341, 112, 0, 3049, 1), -- Magma Plated Helmet
(58154, 60351, 113, 0, 3049, 1), -- Magma Plated Faceguard
(58154, 60342, 114, 0, 3033, 1), -- Magma Plated Legplates
(58154, 60352, 115, 0, 3033, 1), -- Magma Plated Legguards
(58154, 60343, 116, 0, 3043, 1), -- Magma Plated Pauldrons
(58154, 60353, 117, 0, 3043, 1), -- Magma Plated Shoulderguards

(58154, 60276, 118, 0, 3033, 1), -- Stormrider's Robes
(58154, 60281, 120, 0, 3033, 1), -- Stormrider's Vestment
(58154, 60287, 122, 0, 3033, 1), -- Stormrider's Raiment
(58154, 60280, 123, 0, 3034, 1), -- Stormrider's Handwraps
(58154, 60285, 124, 0, 3034, 1), -- Stormrider's Gloves
(58154, 60290, 125, 0, 3034, 1), -- Stormrider's Grips
(58154, 60277, 126, 0, 3049, 1), -- Stormrider's Helm
(58154, 60282, 127, 0, 3049, 1), -- Stormrider's Cover
(58154, 60286, 128, 0, 3049, 1), -- Stormrider's Headpiece
(58154, 60278, 129, 0, 3033, 1), -- Stormrider's Legwraps
(58154, 60283, 130, 0, 3033, 1), -- Stormrider's Leggings
(58154, 60288, 131, 0, 3033, 1), -- Stormrider's Legguards
(58154, 60279, 132, 0, 3043, 1), -- Stormrider's Mantle
(58154, 60284, 133, 0, 3043, 1), -- Stormrider's Shoulderwraps
(58154, 60289, 134, 0, 3043, 1), -- Stormrider's Spaulders

(58154, 60304, 135, 0, 3033, 1), -- Lightning-Charged Tunic
(58154, 60307, 137, 0, 3034, 1), -- Lightning-Charged Gloves
(58154, 60303, 136, 0, 3051, 1), -- Lightning-Charged Headguard
(58154, 60305, 138, 0, 3033, 1), -- Lightning-Charged Legguards
(58154, 60306, 140, 0, 3045, 1), -- Lightning-Charged Spaulders

(58154, 60309, 142, 0, 3033, 1), -- Tunic of the Raging Elements
(58154, 60313, 143, 0, 3033, 1), -- Hauberk of the Raging Elements
(58154, 60318, 144, 0, 3033, 1), -- Cuirass of the Raging Elements
(58154, 60312, 145, 0, 3034, 1), -- Handwraps of the Raging Elements
(58154, 60314, 146, 0, 3034, 1), -- Gloves of the Raging Elements
(58154, 60319, 147, 0, 3034, 1), -- Grips of the Raging Elements
(58154, 60308, 148, 0, 3051, 1), -- Faceguard of the Raging Elements 
(58154, 60315, 149, 0, 3051, 1), -- Headpiece of the Raging Elements
(58154, 60320, 150, 0, 3051, 1), -- Helmet of the Raging Elements
(58154, 60310, 151, 0, 3033, 1), -- Legwraps of the Raging Elements
(58154, 60316, 152, 0, 3033, 1), -- Kilt of the Raging Elements
(58154, 60321, 153, 0, 3033, 1), -- Legguards of the Raging Elements
(58154, 60311, 154, 0, 3045, 1), -- Mantle of the Raging Elements
(58154, 60317, 155, 0, 3045, 1), -- Shoulderwraps of the Raging Elements
(58154, 60322, 156, 0, 3045, 1), -- Spaulders of the Raging Elements

(58154, 60360, 157, 0, 3033, 1), -- Reinforced Sapphirium Breastplate
(58154, 60344, 158, 0, 3033, 1), -- Reinforced Sapphirium Battleplate
(58154, 60354, 160, 0, 3033, 1), -- Reinforced Sapphirium Chestguard
(58154, 60363, 161, 0, 3034, 1), -- Reinforced Sapphirium Gloves
(58154, 60345, 162, 0, 3034, 1), -- Reinforced Sapphirium Gauntiets
(58154, 60355, 163, 0, 3034, 1), -- Reinforced Sapphirium Handguards
(58154, 60359, 164, 0, 3050, 1), -- Reinforced Sapphirium Headguard  
(58154, 60346, 165, 0, 3050, 1), -- Reinforced Sapphirium Helmet
(58154, 60356, 166, 0, 3050, 1), -- Reinforced Sapphirium Faceguard
(58154, 60361, 167, 0, 3033, 1), -- Reinforced Sapphirium Greaves
(58154, 60347, 168, 0, 3033, 1), -- Reinforced Sapphirium Legplates
(58154, 60357, 169, 0, 3033, 1), -- Reinforced Sapphirium Legguards 
(58154, 60362, 170, 0, 3044, 1), -- Reinforced Sapphirium Mantle
(58154, 60348, 171, 0, 3044, 1), -- Reinforced Sapphirium Pauldrons
(58154, 60358, 172, 0, 3044, 1), -- Reinforced Sapphirium Shoulderguards

(58154, 60259, 173, 0, 3033, 1), -- Mercurial Robes
(58154, 60254, 174, 0, 3033, 1), -- Mercurial Vestment
(58154, 60275, 175, 0, 3034, 1), -- Mercurial Handwraps
(58154, 60257, 176, 0, 3034, 1), -- Mercurial Gloves
(58154, 60258, 177, 0, 3050, 1), -- Mercurial Cowl
(58154, 60256, 178, 0, 3050, 1), -- Mercurial Hood
(58154, 60261, 179, 0, 3033, 1), -- Mercurial legwraps
(58154, 60255, 180, 0, 3033, 1), -- Mercurial Leggings
(58154, 60262, 181, 0, 3044, 1), -- Mercurial Mantle
(58154, 60253, 182, 0, 3044, 1), -- Mercurial Shoulderwra

(58154, 60251, 183, 0, 3033, 1), -- Shadowflame Robes
(58154, 60248, 186, 0, 3034, 1), -- Shadowflame Handwraps
(58154, 60249, 187, 0, 3050, 1), -- Shadowflame Hood
(58154, 60250, 188, 0, 3033, 1), -- Shadowflame Leggings
(58154, 60252, 189, 0, 3044, 1), -- Shadowflame Mantle

(58154, 67425, 190, 0, 3329, 1), -- Chest of the Forlorn Vanquisher
(58154, 65089, 191, 0, 3329, 1), -- Shoulders of the Forlorn Vanquisher
(58154, 67431, 192, 0, 3329, 1), -- Gauntlets of the Forlorn Vanquisher
(58154, 65002, 194, 0, 3329, 1), -- Crown of the Forlorn Vanquisher
(58154, 67426, 195, 0, 3329, 1), -- Leggings of the Forlorn Vanquisher

(58154, 67423, 197, 0, 3329, 1), -- Chest of the Forlorn Conqueror
(58154, 65088, 198, 0, 3329, 1), -- Shoulders of the Forlorn Conqueror
(58154, 67429, 201, 0, 3329, 1), -- Gauntlets of the Forlorn Conqueror
(58154, 65001, 203, 0, 3329, 1), -- Crown of the Forlorn Conqueror
(58154, 67428, 204, 0, 3329, 1), -- Leggings of the Forlorn Conqueror

(58154, 65212, 206, 0, 3090, 1), -- Firelord's Robes
(58154, 65209, 207, 0, 3151, 1), -- Firelord's Gloves
(58154, 65210, 209, 0, 3054, 1), -- Firelord's Hood
(58154, 65211, 210, 0, 3107, 1), -- Firelord's Leggings
(58154, 65213, 211, 0, 3118, 1), -- Firelord's Mantle

(58154, 65239, 212, 0, 3079, 1), -- Wind Dancer's Tunic
(58154, 65240, 213, 0, 3157, 1), -- Wind Dancer's Gloves
(58154, 65241, 214, 0, 3054, 1), -- Wind Dancer's Helmet
(58154, 65242, 215, 0, 3101, 1), -- Wind Dancer's Legguards
(58154, 65243, 216, 0, 3118, 1), -- Wind Dancer's Spaulders

(58154, 65179, 217, 0, 3085, 1), -- Magma Plated Battleplate
(58154, 65184, 218, 0, 3084, 1), -- Magma Plated Chestguard
(58154, 65180, 219, 0, 3145, 1), -- Magma Plated Gauntiets
(58154, 65185, 220, 0, 3146, 1), -- Magma Plated Handguards
(58154, 65181, 221, 0, 3054, 1), -- Magma Plated Helmet
(58154, 65186, 222, 0, 3054, 1), -- Magma Plated Faceguard
(58154, 65182, 223, 0, 3113, 1), -- Magma Plated Legplates
(58154, 65187, 224, 0, 3112, 1), -- Magma Plated Legguards
(58154, 65183, 225, 0, 3118, 1), -- Magma Plated Pauldrons
(58154, 65188, 226, 0, 3118, 1), -- Magma Plated Shoulderguards

(58154, 65197, 227, 0, 3092, 1), -- Stormrider's Robes
(58154, 65202, 228, 0, 3091, 1), -- Stormrider's Vestment
(58154, 65192, 229, 0, 3093, 1), -- Stormrider's Raiment
(58154, 65194, 230, 0, 3148, 1), -- Stormrider's Handwraps
(58154, 65199, 231, 0, 3149, 1), -- Stormrider's Gloves
(58154, 65189, 232, 0, 3147, 1), -- Stormrider's Grips
(58154, 65195, 233, 0, 3054, 1), -- Stormrider's Helm
(58154, 65200, 234, 0, 3054, 1), -- Stormrider's Cover
(58154, 65190, 235, 0, 3054, 1), -- Stormrider's Headpiece
(58154, 65196, 236, 0, 3110, 1), -- Stormrider's Legwraps
(58154, 65201, 237, 0, 3109, 1), -- Stormrider's Leggings
(58154, 65191, 238, 0, 3111, 1), -- Stormrider's Legguards
(58154, 65198, 239, 0, 3118, 1), -- Stormrider's Mantle
(58154, 65203, 240, 0, 3118, 1), -- Stormrider's Shoulderwraps
(58154, 65193, 241, 0, 3118, 1), -- Stormrider's Spaulders

(58154, 65204, 242, 0, 3083, 1), -- Lightning-Charged Tunic
(58154, 65205, 243, 0, 3150, 1), -- Lightning-Charged Gloves
(58154, 65206, 244, 0, 3056, 1), -- Lightning-Charged Headguard
(58154, 65207, 245, 0, 3108, 1), -- Lightning-Charged Legguards
(58154, 65208, 246, 0, 3120, 1), -- Lightning-Charged Spaulders

(58154, 65244, 247, 0, 3078, 1), -- Tunic of the Raging Elements
(58154, 65254, 248, 0, 3076, 1), -- Hauberk of the Raging Elements
(58154, 65249, 249, 0, 3077, 1), -- Cuirass of the Raging Elements
(58154, 65245, 250, 0, 3158, 1), -- Handwraps of the Raging Elements
(58154, 65255, 251, 0, 3144, 1), -- Gloves of the Raging Elements
(58154, 65250, 252, 0, 3159, 1), -- Grips of the Raging Elements
(58154, 65246, 253, 0, 3056, 1), -- Faceguard of the Raging Elements 
(58154, 65256, 254, 0, 3056, 1), -- Headpiece of the Raging Elements
(58154, 65251, 255, 0, 3056, 1), -- Helmet of the Raging Elements
(58154, 65247, 256, 0, 3100, 1), -- Legwraps of the Raging Elements
(58154, 65257, 257, 0, 3098, 1), -- Kilt of the Raging Elements
(58154, 65252, 258, 0, 3099, 1), -- Legguards of the Raging Elements
(58154, 65248, 259, 0, 3120, 1), -- Mantle of the Raging Elements
(58154, 65258, 260, 0, 3120, 1), -- Shoulderwraps of the Raging Elements
(58154, 65253, 261, 0, 3120, 1), -- Spaulders of the Raging Elements

(58154, 65219, 262, 0, 3081, 1), -- Reinforced Sapphirium Breastplate
(58154, 65214, 263, 0, 3082, 1), -- Reinforced Sapphirium Battleplate
(58154, 65224, 264, 0, 3080, 1), -- Reinforced Sapphirium Chestguard
(58154, 65220, 265, 0, 3153, 1), -- Reinforced Sapphirium Gloves
(58154, 65215, 266, 0, 3152, 1), -- Reinforced Sapphirium Gauntiets
(58154, 65225, 267, 0, 3154, 1), -- Reinforced Sapphirium Handguards
(58154, 65221, 268, 0, 3055, 1), -- Reinforced Sapphirium Headguard  
(58154, 65216, 269, 0, 3055, 1), -- Reinforced Sapphirium Helmet
(58154, 65226, 270, 0, 3055, 1), -- Reinforced Sapphirium Faceguard
(58154, 65222, 271, 0, 3105, 1), -- Reinforced Sapphirium Greaves
(58154, 65217, 272, 0, 3106, 1), -- Reinforced Sapphirium Legplates
(58154, 65227, 273, 0, 3104, 1), -- Reinforced Sapphirium Legguards 
(58154, 65223, 274, 0, 3119, 1), -- Reinforced Sapphirium Mantle
(58154, 65218, 275, 0, 3119, 1), -- Reinforced Sapphirium Pauldrons
(58154, 65228, 276, 0, 3119, 1), -- Reinforced Sapphirium Shoulderguards

(58154, 65232, 277, 0, 3089, 1), -- Mercurial Robes
(58154, 65237, 278, 0, 3088, 1), -- Mercurial Vestment
(58154, 65229, 279, 0, 3155, 1), -- Mercurial Handwraps
(58154, 65234, 280, 0, 3156, 1), -- Mercurial Gloves
(58154, 65230, 281, 0, 3055, 1), -- Mercurial Cowl
(58154, 65235, 282, 0, 3055, 1), -- Mercurial Hood
(58154, 65231, 283, 0, 3103, 1), -- Mercurial legwraps
(58154, 65236, 284, 0, 3102, 1), -- Mercurial Leggings
(58154, 65233, 285, 0, 3119, 1), -- Mercurial Mantle
(58154, 65238, 286, 0, 3119, 1), -- Mercurial Shoulderwra

(58154, 65262, 287, 0, 3094, 1), -- Shadowflame Robes
(58154, 65259, 288, 0, 3143, 1), -- Shadowflame Handwraps
(58154, 65260, 289, 0, 3055, 1), -- Shadowflame Hood
(58154, 65261, 290, 0, 3116, 1), -- Shadowflame Leggings
(58154, 65263, 301, 0, 3119, 1), -- Shadowflame Mantle

(58154, 58126, 1, 0, 3038, 1), -- Vest of the Waking Dream
(58154, 58131, 2, 0, 3038, 1), -- Tunic of Sinking Envy
(58154, 58101, 3, 0, 3038, 1), -- Chestplate of the Steadfast
(58154, 58096, 4, 0, 3038, 1), -- Breastplate of Raging Fury
(58154, 58106, 5, 0, 3038, 1), -- Chestguard of Dancing Waves
(58154, 58121, 6, 0, 3038, 1), -- Vest of the True Companion
(58154, 58130, 7, 0, 3039, 1), -- Gleaning Gloves
(58154, 58138, 8, 0, 3039, 1), -- Sticky Fingers
(58154, 58163, 9, 0, 3039, 1), -- Gloves of Purification
(58154, 58105, 10, 0, 3039, 1), -- Numbing Handguards
(58154, 58099, 11, 0, 3039, 1), -- Reaping Gauntlets
(58154, 58110, 12, 0, 3039, 1), -- Gloves of Curious Conscience
(58154, 58125, 13, 0, 3039, 1), -- Gloves of the Passing Night
(58154, 58152, 14, 0, 3039, 1), -- Blessed Hands of Elune
(58154, 58158, 15, 0, 3039, 1), -- Gloves of the Painless Midnight
(58154, 58128, 16, 0, 3038, 1), -- Helm of the Inward Eye
(58154, 58133, 17, 0, 3038, 1), -- Mask of Vines
(58154, 58161, 18, 0, 3038, 1), -- Mask of New Snow
(58154, 58103, 19, 0, 3038, 1), -- Helm of the Proud
(58154, 58098, 20, 0, 3038, 1), -- Helm of Easeful Death
(58154, 58108, 21, 0, 3038, 1), -- Crown of the Blazing Sun
(58154, 58123, 22, 0, 3038, 1), -- Willow Mask
(58154, 58150, 23, 0, 3038, 1), -- Cluster of Stars
(58154, 58155, 24, 0, 3038, 1), -- Cowl of Pleasant Gloom
(58154, 57924, 25, 0, 3041, 1), -- Apple-Bent Bough
(58154, 57923, 26, 0, 3041, 1), -- Hermit's Lamp
(58154, 58127, 27, 0, 3038, 1), -- Leggings of Soothing Silence
(58154, 58132, 28, 0, 3038, 1), -- Leggings of the Burrowing Mole
(58154, 58160, 29, 0, 3038, 1), -- Leggings of Charity
(58154, 58102, 30, 0, 3038, 1), -- Greaves of Splendor
(58154, 58097, 31, 0, 3038, 1), -- Greaves of Gallantry
(58154, 58107, 32, 0, 3038, 1), -- Legguards of the Gentle
(58154, 58122, 33, 0, 3038, 1), -- Hillside Striders
(58154, 58140, 34, 0, 3038, 1), -- Leggings of Late Blooms
(58154, 58154, 35, 0, 3038, 1), -- Pensive Legwraps
(58154, 57932, 36, 0, 3040, 1), -- The Lustrous Eye
(58154, 57930, 37, 0, 3040, 1), -- Pendant of Quiet Breath
(58154, 57934, 38, 0, 3040, 1), -- Celadon Pendant
(58154, 57933, 39, 0, 3040, 1), -- String of Beaded Bubbles
(58154, 57931, 40, 0, 3040, 1), -- Amulet of Dull Dreaming
(58154, 57929, 41, 0, 3041, 1), -- Dawnblaze Blade
(58154, 57928, 42, 0, 3041, 1), -- Windslicer
(58154, 57927, 43, 0, 3041, 1), -- Throat Slasher
(58154, 58159, 44, 0, 3038, 1), -- Musk Rose Robes
(58154, 58139, 45, 0, 3038, 1), -- Chestguard of Forgetfulness
(58154, 58153, 46, 0, 3038, 1), -- Robes of Embalmed Darkness
(58154, 57926, 47, 0, 3041, 1), -- Shield of the Four Grey Towers
(58154, 57925, 48, 0, 3041, 1), -- Shield of the Mists
(58154, 58129, 49, 0, 3039, 1), -- Seafoam Mantle
(58154, 58134, 50, 0, 3039, 1), -- Embrace of the Night
(58154, 58162, 51, 0, 3039, 1), -- Summer Song Shoulderwraps
(58154, 58104, 52, 0, 3039, 1), -- Sunburnt Pauldrons
(58154, 58100, 53, 0, 3039, 1), -- Pauldrons of the High Requiem
(58154, 58109, 54, 0, 3039, 1), -- Pauldrons of the Forlorn
(58154, 58124, 55, 0, 3039, 1), -- Wrap of the Valley Glades
(58154, 58151, 56, 0, 3039, 1), -- Somber Shawl
(58154, 58157, 57, 0, 3039, 1), -- Meadow Mantle
(58154, 57917, 58, 0, 3039, 1), -- Belt of the Still Stream
(58154, 57918, 59, 0, 3039, 1), -- Sash of Musing
(58154, 57922, 60, 0, 3039, 1), -- Belt of the Falling Rain
(58154, 57914, 61, 0, 3039, 1), -- Girdle of the Mountains
(58154, 57913, 62, 0, 3039, 1), -- Beech Green Belt
(58154, 57915, 63, 0, 3039, 1), -- Belt of Barred Clouds
(58154, 57916, 64, 0, 3039, 1), -- Belt of the Dim Forest
(58154, 57921, 65, 0, 3039, 1), -- Incense Infused Cummerbund
(58154, 57919, 66, 0, 3039, 1), -- Thatch Eave Vines
(58154, 58194, 67, 0, 3035, 1), -- Heavenly Breeze
(58154, 58190, 68, 0, 3035, 1), -- Floating Web
(58154, 58193, 69, 0, 3035, 1), -- Haunt of Flies
(58154, 58192, 70, 0, 3035, 1), -- Gray Hair Cloak
(58154, 58191, 71, 0, 3035, 1), -- Viewless Wings
(58154, 58486, 72, 0, 3034, 1), -- Slippers of Moving Waters
(58154, 58485, 73, 0, 3034, 1), -- Melodious Slippers
(58154, 58484, 74, 0, 3034, 1), -- Fading Violet Sandals
(58154, 58482, 75, 0, 3034, 1), -- Treads of Fleeting Joy
(58154, 58481, 76, 0, 3034, 1), -- Boots of the Perilous Seas
(58154, 58199, 77, 0, 3034, 1), -- Moccasins of Verdurous Glooms
(58154, 58198, 78, 0, 3034, 1), -- Eternal Pathfinders
(58154, 58197, 79, 0, 3034, 1), -- Rock Furrow Boots
(58154, 58195, 80, 0, 3034, 1), -- Woe Breeder's Boots
(58154, 58189, 81, 0, 3035, 1), -- Twined Band of Flowers
(58154, 58188, 82, 0, 3035, 1), -- Band of Secret Names
(58154, 58187, 83, 0, 3035, 1), -- Ring of the Battle Anthem
(58154, 58185, 84, 0, 3035, 1), -- Band of Bees
(58154, 68812, 85, 0, 3035, 1), -- Hornet-Sting Band
(58154, 64676, 86, 0, 3037, 1), -- Relic of Khaz'goroth
(58154, 64674, 87, 0, 3037, 1), -- Relic of Aggramar
(58154, 64673, 88, 0, 3037, 1), -- Relic of Eonar
(58154, 64672, 89, 0, 3037, 1), -- Relic of Norgannon
(58154, 64671, 90, 0, 3037, 1), -- Relic of Golganneth
(58154, 58184, 91, 0, 3034, 1), -- Core of Ripeness
(58154, 58183, 92, 0, 3034, 1), -- Soul Casket
(58154, 58182, 93, 0, 3034, 1), -- Bedrock Talisman
(58154, 58181, 94, 0, 3034, 1), -- Fluid Death
(58154, 58180, 95, 0, 3034, 1), -- License to Slay
(58154, 60329, 100, 0, 3033, 1), -- Earthen Chestguard
(58154, 60323, 102, 0, 3033, 1), -- Earthen Battleplate
(58154, 60332, 119, 0, 3034, 1), -- Earthen Handguards
(58154, 60326, 121, 0, 3034, 1), -- Earthen Gauntlets
(58154, 60328, 139, 0, 3051, 1), -- Earthen Faceguard
(58154, 60325, 141, 0, 3051, 1), -- Earthen Helmet
(58154, 60330, 158, 0, 3033, 1), -- Earthen Legguards
(58154, 60324, 159, 0, 3033, 1), -- Earthen Legplates
(58154, 60331, 184, 0, 3045, 1), -- Earthen Shoulderguards
(58154, 60327, 185, 0, 3045, 1), -- Earthen Pauldrons
(58154, 67424, 193, 0, 3329, 1), -- Chest of the Forlorn Protector
(58154, 65087, 196, 0, 3329, 1), -- Shoulders of the Forlorn Protector
(58154, 67430, 199, 0, 3329, 1), -- Gauntlets of the Forlorn Protector
(58154, 65000, 202, 0, 3329, 1), -- Crown of the Forlorn Protector
(58154, 67427, 205, 0, 3329, 1), -- Leggings of the Forlorn Protector
(58154, 65264, 291, 0, 3087, 1), -- Earthen Battleplate
(58154, 65265, 292, 0, 3160, 1), -- Earthen Gauntlets
(58154, 65266, 293, 0, 3056, 1), -- Earthen Helmet
(58154, 65267, 294, 0, 3115, 1), -- Earthen Legplates
(58154, 65268, 295, 0, 3048, 1), -- Earthen Pauldrons
(58154, 65269, 296, 0, 3086, 1), -- Earthen Chestguard
(58154, 65270, 297, 0, 3161, 1), -- Earthen Handguards
(58154, 65271, 298, 0, 3056, 1), -- Earthen Faceguard
(58154, 65272, 299, 0, 3097, 1), -- Earthen Legguards
(58154, 65273, 300, 0, 3120, 1), -- Earthen Shoulderguards

(58155, 60244, 96, 0, 3033, 1), -- Firelord's Robes
(58155, 60247, 97, 0, 3034, 1), -- Firelord's Gloves
(58155, 60243, 98, 0, 3049, 1), -- Firelord's Hood
(58155, 60245, 99, 0, 3033, 1), -- Firelord's Leggings
(58155, 60246, 101, 0, 3043, 1), -- Firelord's Mantle

(58155, 60301, 103, 0, 3033, 1), -- Wind Dancer's Tunic
(58155, 60298, 104, 0, 3034, 1), -- Wind Dancer's Gloves
(58155, 60299, 105, 0, 3049, 1), -- Wind Dancer's Helmet
(58155, 60300, 106, 0, 3033, 1), -- Wind Dancer's Legguards
(58155, 60302, 107, 0, 3043, 1), -- Wind Dancer's Spaulders

(58155, 60339, 108, 0, 3033, 1), -- Magma Plated Battleplate
(58155, 60349, 109, 0, 3033, 1), -- Magma Plated Chestguard
(58155, 60340, 110, 0, 3034, 1), -- Magma Plated Gauntiets
(58155, 60350, 111, 0, 3034, 1), -- Magma Plated Handguards
(58155, 60341, 112, 0, 3049, 1), -- Magma Plated Helmet
(58155, 60351, 113, 0, 3049, 1), -- Magma Plated Faceguard
(58155, 60342, 114, 0, 3033, 1), -- Magma Plated Legplates
(58155, 60352, 115, 0, 3033, 1), -- Magma Plated Legguards
(58155, 60343, 116, 0, 3043, 1), -- Magma Plated Pauldrons
(58155, 60353, 117, 0, 3043, 1), -- Magma Plated Shoulderguards

(58155, 60276, 118, 0, 3033, 1), -- Stormrider's Robes
(58155, 60281, 120, 0, 3033, 1), -- Stormrider's Vestment
(58155, 60287, 122, 0, 3033, 1), -- Stormrider's Raiment
(58155, 60280, 123, 0, 3034, 1), -- Stormrider's Handwraps
(58155, 60285, 124, 0, 3034, 1), -- Stormrider's Gloves
(58155, 60290, 125, 0, 3034, 1), -- Stormrider's Grips
(58155, 60277, 126, 0, 3049, 1), -- Stormrider's Helm
(58155, 60282, 127, 0, 3049, 1), -- Stormrider's Cover
(58155, 60286, 128, 0, 3049, 1), -- Stormrider's Headpiece
(58155, 60278, 129, 0, 3033, 1), -- Stormrider's Legwraps
(58155, 60283, 130, 0, 3033, 1), -- Stormrider's Leggings
(58155, 60288, 131, 0, 3033, 1), -- Stormrider's Legguards
(58155, 60279, 132, 0, 3043, 1), -- Stormrider's Mantle
(58155, 60284, 133, 0, 3043, 1), -- Stormrider's Shoulderwraps
(58155, 60289, 134, 0, 3043, 1), -- Stormrider's Spaulders

(58155, 60304, 135, 0, 3033, 1), -- Lightning-Charged Tunic
(58155, 60307, 137, 0, 3034, 1), -- Lightning-Charged Gloves
(58155, 60303, 136, 0, 3051, 1), -- Lightning-Charged Headguard
(58155, 60305, 138, 0, 3033, 1), -- Lightning-Charged Legguards
(58155, 60306, 140, 0, 3045, 1), -- Lightning-Charged Spaulders

(58155, 60309, 142, 0, 3033, 1), -- Tunic of the Raging Elements
(58155, 60313, 143, 0, 3033, 1), -- Hauberk of the Raging Elements
(58155, 60318, 144, 0, 3033, 1), -- Cuirass of the Raging Elements
(58155, 60312, 145, 0, 3034, 1), -- Handwraps of the Raging Elements
(58155, 60314, 146, 0, 3034, 1), -- Gloves of the Raging Elements
(58155, 60319, 147, 0, 3034, 1), -- Grips of the Raging Elements
(58155, 60308, 148, 0, 3051, 1), -- Faceguard of the Raging Elements 
(58155, 60315, 149, 0, 3051, 1), -- Headpiece of the Raging Elements
(58155, 60320, 150, 0, 3051, 1), -- Helmet of the Raging Elements
(58155, 60310, 151, 0, 3033, 1), -- Legwraps of the Raging Elements
(58155, 60316, 152, 0, 3033, 1), -- Kilt of the Raging Elements
(58155, 60321, 153, 0, 3033, 1), -- Legguards of the Raging Elements
(58155, 60311, 154, 0, 3045, 1), -- Mantle of the Raging Elements
(58155, 60317, 155, 0, 3045, 1), -- Shoulderwraps of the Raging Elements
(58155, 60322, 156, 0, 3045, 1), -- Spaulders of the Raging Elements

(58155, 60360, 157, 0, 3033, 1), -- Reinforced Sapphirium Breastplate
(58155, 60344, 158, 0, 3033, 1), -- Reinforced Sapphirium Battleplate
(58155, 60354, 160, 0, 3033, 1), -- Reinforced Sapphirium Chestguard
(58155, 60363, 161, 0, 3034, 1), -- Reinforced Sapphirium Gloves
(58155, 60345, 162, 0, 3034, 1), -- Reinforced Sapphirium Gauntiets
(58155, 60355, 163, 0, 3034, 1), -- Reinforced Sapphirium Handguards
(58155, 60359, 164, 0, 3050, 1), -- Reinforced Sapphirium Headguard  
(58155, 60346, 165, 0, 3050, 1), -- Reinforced Sapphirium Helmet
(58155, 60356, 166, 0, 3050, 1), -- Reinforced Sapphirium Faceguard
(58155, 60361, 167, 0, 3033, 1), -- Reinforced Sapphirium Greaves
(58155, 60347, 168, 0, 3033, 1), -- Reinforced Sapphirium Legplates
(58155, 60357, 169, 0, 3033, 1), -- Reinforced Sapphirium Legguards 
(58155, 60362, 170, 0, 3044, 1), -- Reinforced Sapphirium Mantle
(58155, 60348, 171, 0, 3044, 1), -- Reinforced Sapphirium Pauldrons
(58155, 60358, 172, 0, 3044, 1), -- Reinforced Sapphirium Shoulderguards

(58155, 60259, 173, 0, 3033, 1), -- Mercurial Robes
(58155, 60254, 174, 0, 3033, 1), -- Mercurial Vestment
(58155, 60275, 175, 0, 3034, 1), -- Mercurial Handwraps
(58155, 60257, 176, 0, 3034, 1), -- Mercurial Gloves
(58155, 60258, 177, 0, 3050, 1), -- Mercurial Cowl
(58155, 60256, 178, 0, 3050, 1), -- Mercurial Hood
(58155, 60261, 179, 0, 3033, 1), -- Mercurial legwraps
(58155, 60255, 180, 0, 3033, 1), -- Mercurial Leggings
(58155, 60262, 181, 0, 3044, 1), -- Mercurial Mantle
(58155, 60253, 182, 0, 3044, 1), -- Mercurial Shoulderwra

(58155, 60251, 183, 0, 3033, 1), -- Shadowflame Robes
(58155, 60248, 186, 0, 3034, 1), -- Shadowflame Handwraps
(58155, 60249, 187, 0, 3050, 1), -- Shadowflame Hood
(58155, 60250, 188, 0, 3033, 1), -- Shadowflame Leggings
(58155, 60252, 189, 0, 3044, 1), -- Shadowflame Mantle

(58155, 67425, 190, 0, 3329, 1), -- Chest of the Forlorn Vanquisher
(58155, 65089, 191, 0, 3329, 1), -- Shoulders of the Forlorn Vanquisher
(58155, 67431, 192, 0, 3329, 1), -- Gauntlets of the Forlorn Vanquisher
(58155, 65002, 194, 0, 3329, 1), -- Crown of the Forlorn Vanquisher
(58155, 67426, 195, 0, 3329, 1), -- Leggings of the Forlorn Vanquisher

(58155, 67423, 197, 0, 3329, 1), -- Chest of the Forlorn Conqueror
(58155, 65088, 198, 0, 3329, 1), -- Shoulders of the Forlorn Conqueror
(58155, 67429, 201, 0, 3329, 1), -- Gauntlets of the Forlorn Conqueror
(58155, 65001, 203, 0, 3329, 1), -- Crown of the Forlorn Conqueror
(58155, 67428, 204, 0, 3329, 1), -- Leggings of the Forlorn Conqueror

(58155, 65212, 206, 0, 3090, 1), -- Firelord's Robes
(58155, 65209, 207, 0, 3151, 1), -- Firelord's Gloves
(58155, 65210, 209, 0, 3054, 1), -- Firelord's Hood
(58155, 65211, 210, 0, 3107, 1), -- Firelord's Leggings
(58155, 65213, 211, 0, 3118, 1), -- Firelord's Mantle

(58155, 65239, 212, 0, 3079, 1), -- Wind Dancer's Tunic
(58155, 65240, 213, 0, 3157, 1), -- Wind Dancer's Gloves
(58155, 65241, 214, 0, 3054, 1), -- Wind Dancer's Helmet
(58155, 65242, 215, 0, 3101, 1), -- Wind Dancer's Legguards
(58155, 65243, 216, 0, 3118, 1), -- Wind Dancer's Spaulders

(58155, 65179, 217, 0, 3085, 1), -- Magma Plated Battleplate
(58155, 65184, 218, 0, 3084, 1), -- Magma Plated Chestguard
(58155, 65180, 219, 0, 3145, 1), -- Magma Plated Gauntiets
(58155, 65185, 220, 0, 3146, 1), -- Magma Plated Handguards
(58155, 65181, 221, 0, 3054, 1), -- Magma Plated Helmet
(58155, 65186, 222, 0, 3054, 1), -- Magma Plated Faceguard
(58155, 65182, 223, 0, 3113, 1), -- Magma Plated Legplates
(58155, 65187, 224, 0, 3112, 1), -- Magma Plated Legguards
(58155, 65183, 225, 0, 3118, 1), -- Magma Plated Pauldrons
(58155, 65188, 226, 0, 3118, 1), -- Magma Plated Shoulderguards

(58155, 65197, 227, 0, 3092, 1), -- Stormrider's Robes
(58155, 65202, 228, 0, 3091, 1), -- Stormrider's Vestment
(58155, 65192, 229, 0, 3093, 1), -- Stormrider's Raiment
(58155, 65194, 230, 0, 3148, 1), -- Stormrider's Handwraps
(58155, 65199, 231, 0, 3149, 1), -- Stormrider's Gloves
(58155, 65189, 232, 0, 3147, 1), -- Stormrider's Grips
(58155, 65195, 233, 0, 3054, 1), -- Stormrider's Helm
(58155, 65200, 234, 0, 3054, 1), -- Stormrider's Cover
(58155, 65190, 235, 0, 3054, 1), -- Stormrider's Headpiece
(58155, 65196, 236, 0, 3110, 1), -- Stormrider's Legwraps
(58155, 65201, 237, 0, 3109, 1), -- Stormrider's Leggings
(58155, 65191, 238, 0, 3111, 1), -- Stormrider's Legguards
(58155, 65198, 239, 0, 3118, 1), -- Stormrider's Mantle
(58155, 65203, 240, 0, 3118, 1), -- Stormrider's Shoulderwraps
(58155, 65193, 241, 0, 3118, 1), -- Stormrider's Spaulders

(58155, 65204, 242, 0, 3083, 1), -- Lightning-Charged Tunic
(58155, 65205, 243, 0, 3150, 1), -- Lightning-Charged Gloves
(58155, 65206, 244, 0, 3056, 1), -- Lightning-Charged Headguard
(58155, 65207, 245, 0, 3108, 1), -- Lightning-Charged Legguards
(58155, 65208, 246, 0, 3120, 1), -- Lightning-Charged Spaulders

(58155, 65244, 247, 0, 3078, 1), -- Tunic of the Raging Elements
(58155, 65254, 248, 0, 3076, 1), -- Hauberk of the Raging Elements
(58155, 65249, 249, 0, 3077, 1), -- Cuirass of the Raging Elements
(58155, 65245, 250, 0, 3158, 1), -- Handwraps of the Raging Elements
(58155, 65255, 251, 0, 3144, 1), -- Gloves of the Raging Elements
(58155, 65250, 252, 0, 3159, 1), -- Grips of the Raging Elements
(58155, 65246, 253, 0, 3056, 1), -- Faceguard of the Raging Elements 
(58155, 65256, 254, 0, 3056, 1), -- Headpiece of the Raging Elements
(58155, 65251, 255, 0, 3056, 1), -- Helmet of the Raging Elements
(58155, 65247, 256, 0, 3100, 1), -- Legwraps of the Raging Elements
(58155, 65257, 257, 0, 3098, 1), -- Kilt of the Raging Elements
(58155, 65252, 258, 0, 3099, 1), -- Legguards of the Raging Elements
(58155, 65248, 259, 0, 3120, 1), -- Mantle of the Raging Elements
(58155, 65258, 260, 0, 3120, 1), -- Shoulderwraps of the Raging Elements
(58155, 65253, 261, 0, 3120, 1), -- Spaulders of the Raging Elements

(58155, 65219, 262, 0, 3081, 1), -- Reinforced Sapphirium Breastplate
(58155, 65214, 263, 0, 3082, 1), -- Reinforced Sapphirium Battleplate
(58155, 65224, 264, 0, 3080, 1), -- Reinforced Sapphirium Chestguard
(58155, 65220, 265, 0, 3153, 1), -- Reinforced Sapphirium Gloves
(58155, 65215, 266, 0, 3152, 1), -- Reinforced Sapphirium Gauntiets
(58155, 65225, 267, 0, 3154, 1), -- Reinforced Sapphirium Handguards
(58155, 65221, 268, 0, 3055, 1), -- Reinforced Sapphirium Headguard  
(58155, 65216, 269, 0, 3055, 1), -- Reinforced Sapphirium Helmet
(58155, 65226, 270, 0, 3055, 1), -- Reinforced Sapphirium Faceguard
(58155, 65222, 271, 0, 3105, 1), -- Reinforced Sapphirium Greaves
(58155, 65217, 272, 0, 3106, 1), -- Reinforced Sapphirium Legplates
(58155, 65227, 273, 0, 3104, 1), -- Reinforced Sapphirium Legguards 
(58155, 65223, 274, 0, 3119, 1), -- Reinforced Sapphirium Mantle
(58155, 65218, 275, 0, 3119, 1), -- Reinforced Sapphirium Pauldrons
(58155, 65228, 276, 0, 3119, 1), -- Reinforced Sapphirium Shoulderguards

(58155, 65232, 277, 0, 3089, 1), -- Mercurial Robes
(58155, 65237, 278, 0, 3088, 1), -- Mercurial Vestment
(58155, 65229, 279, 0, 3155, 1), -- Mercurial Handwraps
(58155, 65234, 280, 0, 3156, 1), -- Mercurial Gloves
(58155, 65230, 281, 0, 3055, 1), -- Mercurial Cowl
(58155, 65235, 282, 0, 3055, 1), -- Mercurial Hood
(58155, 65231, 283, 0, 3103, 1), -- Mercurial legwraps
(58155, 65236, 284, 0, 3102, 1), -- Mercurial Leggings
(58155, 65233, 285, 0, 3119, 1), -- Mercurial Mantle
(58155, 65238, 286, 0, 3119, 1), -- Mercurial Shoulderwra

(58155, 65262, 287, 0, 3094, 1), -- Shadowflame Robes
(58155, 65259, 288, 0, 3143, 1), -- Shadowflame Handwraps
(58155, 65260, 289, 0, 3055, 1), -- Shadowflame Hood
(58155, 65261, 290, 0, 3116, 1), -- Shadowflame Leggings
(58155, 65263, 301, 0, 3119, 1), -- Shadowflame Mantle

(58155, 58126, 1, 0, 3038, 1), -- Vest of the Waking Dream
(58155, 58131, 2, 0, 3038, 1), -- Tunic of Sinking Envy
(58155, 58101, 3, 0, 3038, 1), -- Chestplate of the Steadfast
(58155, 58096, 4, 0, 3038, 1), -- Breastplate of Raging Fury
(58155, 58106, 5, 0, 3038, 1), -- Chestguard of Dancing Waves
(58155, 58121, 6, 0, 3038, 1), -- Vest of the True Companion
(58155, 58130, 7, 0, 3039, 1), -- Gleaning Gloves
(58155, 58138, 8, 0, 3039, 1), -- Sticky Fingers
(58155, 58163, 9, 0, 3039, 1), -- Gloves of Purification
(58155, 58105, 10, 0, 3039, 1), -- Numbing Handguards
(58155, 58099, 11, 0, 3039, 1), -- Reaping Gauntlets
(58155, 58110, 12, 0, 3039, 1), -- Gloves of Curious Conscience
(58155, 58125, 13, 0, 3039, 1), -- Gloves of the Passing Night
(58155, 58152, 14, 0, 3039, 1), -- Blessed Hands of Elune
(58155, 58158, 15, 0, 3039, 1), -- Gloves of the Painless Midnight
(58155, 58128, 16, 0, 3038, 1), -- Helm of the Inward Eye
(58155, 58133, 17, 0, 3038, 1), -- Mask of Vines
(58155, 58161, 18, 0, 3038, 1), -- Mask of New Snow
(58155, 58103, 19, 0, 3038, 1), -- Helm of the Proud
(58155, 58098, 20, 0, 3038, 1), -- Helm of Easeful Death
(58155, 58108, 21, 0, 3038, 1), -- Crown of the Blazing Sun
(58155, 58123, 22, 0, 3038, 1), -- Willow Mask
(58155, 58150, 23, 0, 3038, 1), -- Cluster of Stars
(58155, 58155, 24, 0, 3038, 1), -- Cowl of Pleasant Gloom
(58155, 57924, 25, 0, 3041, 1), -- Apple-Bent Bough
(58155, 57923, 26, 0, 3041, 1), -- Hermit's Lamp
(58155, 58127, 27, 0, 3038, 1), -- Leggings of Soothing Silence
(58155, 58132, 28, 0, 3038, 1), -- Leggings of the Burrowing Mole
(58155, 58160, 29, 0, 3038, 1), -- Leggings of Charity
(58155, 58102, 30, 0, 3038, 1), -- Greaves of Splendor
(58155, 58097, 31, 0, 3038, 1), -- Greaves of Gallantry
(58155, 58107, 32, 0, 3038, 1), -- Legguards of the Gentle
(58155, 58122, 33, 0, 3038, 1), -- Hillside Striders
(58155, 58140, 34, 0, 3038, 1), -- Leggings of Late Blooms
(58155, 58154, 35, 0, 3038, 1), -- Pensive Legwraps
(58155, 57932, 36, 0, 3040, 1), -- The Lustrous Eye
(58155, 57930, 37, 0, 3040, 1), -- Pendant of Quiet Breath
(58155, 57934, 38, 0, 3040, 1), -- Celadon Pendant
(58155, 57933, 39, 0, 3040, 1), -- String of Beaded Bubbles
(58155, 57931, 40, 0, 3040, 1), -- Amulet of Dull Dreaming
(58155, 57929, 41, 0, 3041, 1), -- Dawnblaze Blade
(58155, 57928, 42, 0, 3041, 1), -- Windslicer
(58155, 57927, 43, 0, 3041, 1), -- Throat Slasher
(58155, 58159, 44, 0, 3038, 1), -- Musk Rose Robes
(58155, 58139, 45, 0, 3038, 1), -- Chestguard of Forgetfulness
(58155, 58153, 46, 0, 3038, 1), -- Robes of Embalmed Darkness
(58155, 57926, 47, 0, 3041, 1), -- Shield of the Four Grey Towers
(58155, 57925, 48, 0, 3041, 1), -- Shield of the Mists
(58155, 58129, 49, 0, 3039, 1), -- Seafoam Mantle
(58155, 58134, 50, 0, 3039, 1), -- Embrace of the Night
(58155, 58162, 51, 0, 3039, 1), -- Summer Song Shoulderwraps
(58155, 58104, 52, 0, 3039, 1), -- Sunburnt Pauldrons
(58155, 58100, 53, 0, 3039, 1), -- Pauldrons of the High Requiem
(58155, 58109, 54, 0, 3039, 1), -- Pauldrons of the Forlorn
(58155, 58124, 55, 0, 3039, 1), -- Wrap of the Valley Glades
(58155, 58151, 56, 0, 3039, 1), -- Somber Shawl
(58155, 58157, 57, 0, 3039, 1), -- Meadow Mantle
(58155, 57917, 58, 0, 3039, 1), -- Belt of the Still Stream
(58155, 57918, 59, 0, 3039, 1), -- Sash of Musing
(58155, 57922, 60, 0, 3039, 1), -- Belt of the Falling Rain
(58155, 57914, 61, 0, 3039, 1), -- Girdle of the Mountains
(58155, 57913, 62, 0, 3039, 1), -- Beech Green Belt
(58155, 57915, 63, 0, 3039, 1), -- Belt of Barred Clouds
(58155, 57916, 64, 0, 3039, 1), -- Belt of the Dim Forest
(58155, 57921, 65, 0, 3039, 1), -- Incense Infused Cummerbund
(58155, 57919, 66, 0, 3039, 1), -- Thatch Eave Vines
(58155, 58194, 67, 0, 3035, 1), -- Heavenly Breeze
(58155, 58190, 68, 0, 3035, 1), -- Floating Web
(58155, 58193, 69, 0, 3035, 1), -- Haunt of Flies
(58155, 58192, 70, 0, 3035, 1), -- Gray Hair Cloak
(58155, 58191, 71, 0, 3035, 1), -- Viewless Wings
(58155, 58486, 72, 0, 3034, 1), -- Slippers of Moving Waters
(58155, 58485, 73, 0, 3034, 1), -- Melodious Slippers
(58155, 58484, 74, 0, 3034, 1), -- Fading Violet Sandals
(58155, 58482, 75, 0, 3034, 1), -- Treads of Fleeting Joy
(58155, 58481, 76, 0, 3034, 1), -- Boots of the Perilous Seas
(58155, 58199, 77, 0, 3034, 1), -- Moccasins of Verdurous Glooms
(58155, 58198, 78, 0, 3034, 1), -- Eternal Pathfinders
(58155, 58197, 79, 0, 3034, 1), -- Rock Furrow Boots
(58155, 58195, 80, 0, 3034, 1), -- Woe Breeder's Boots
(58155, 58189, 81, 0, 3035, 1), -- Twined Band of Flowers
(58155, 58188, 82, 0, 3035, 1), -- Band of Secret Names
(58155, 58187, 83, 0, 3035, 1), -- Ring of the Battle Anthem
(58155, 58185, 84, 0, 3035, 1), -- Band of Bees
(58155, 68812, 85, 0, 3035, 1), -- Hornet-Sting Band
(58155, 64676, 86, 0, 3037, 1), -- Relic of Khaz'goroth
(58155, 64674, 87, 0, 3037, 1), -- Relic of Aggramar
(58155, 64673, 88, 0, 3037, 1), -- Relic of Eonar
(58155, 64672, 89, 0, 3037, 1), -- Relic of Norgannon
(58155, 64671, 90, 0, 3037, 1), -- Relic of Golganneth
(58155, 58184, 91, 0, 3034, 1), -- Core of Ripeness
(58155, 58183, 92, 0, 3034, 1), -- Soul Casket
(58155, 58182, 93, 0, 3034, 1), -- Bedrock Talisman
(58155, 58181, 94, 0, 3034, 1), -- Fluid Death
(58155, 58180, 95, 0, 3034, 1), -- License to Slay
(58155, 60329, 100, 0, 3033, 1), -- Earthen Chestguard
(58155, 60323, 102, 0, 3033, 1), -- Earthen Battleplate
(58155, 60332, 119, 0, 3034, 1), -- Earthen Handguards
(58155, 60326, 121, 0, 3034, 1), -- Earthen Gauntlets
(58155, 60328, 139, 0, 3051, 1), -- Earthen Faceguard
(58155, 60325, 141, 0, 3051, 1), -- Earthen Helmet
(58155, 60330, 158, 0, 3033, 1), -- Earthen Legguards
(58155, 60324, 159, 0, 3033, 1), -- Earthen Legplates
(58155, 60331, 184, 0, 3045, 1), -- Earthen Shoulderguards
(58155, 60327, 185, 0, 3045, 1), -- Earthen Pauldrons
(58155, 67424, 193, 0, 3329, 1), -- Chest of the Forlorn Protector
(58155, 65087, 196, 0, 3329, 1), -- Shoulders of the Forlorn Protector
(58155, 67430, 199, 0, 3329, 1), -- Gauntlets of the Forlorn Protector
(58155, 65000, 202, 0, 3329, 1), -- Crown of the Forlorn Protector
(58155, 67427, 205, 0, 3329, 1), -- Leggings of the Forlorn Protector
(58155, 65264, 291, 0, 3087, 1), -- Earthen Battleplate
(58155, 65265, 292, 0, 3160, 1), -- Earthen Gauntlets
(58155, 65266, 293, 0, 3056, 1), -- Earthen Helmet
(58155, 65267, 294, 0, 3115, 1), -- Earthen Legplates
(58155, 65268, 295, 0, 3048, 1), -- Earthen Pauldrons
(58155, 65269, 296, 0, 3086, 1), -- Earthen Chestguard
(58155, 65270, 297, 0, 3161, 1), -- Earthen Handguards
(58155, 65271, 298, 0, 3056, 1), -- Earthen Faceguard
(58155, 65272, 299, 0, 3097, 1), -- Earthen Legguards
(58155, 65273, 300, 0, 3120, 1); -- Earthen Shoulderguards