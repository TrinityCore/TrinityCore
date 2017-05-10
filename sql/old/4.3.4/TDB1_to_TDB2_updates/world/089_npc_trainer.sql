-- ----------------------------------------
-- -- Professions Trainers for Cataclysm --
-- ----------------------------------------
SET @Alchemy := 200400;
SET @Blacksmithing := 200401;
SET @Enchanting := 200402;
SET @Engineering := 200403;
SET @Herbalism := 200404;
SET @Inscription := 200405;
SET @Jewelcrafting := 200406;
SET @Leatherworking := 200407;
SET @Mining := 200408;
SET @Skinning := 200409;
SET @Tailoring := 200410;
DELETE FROM `npc_trainer` WHERE `entry` IN (@Alchemy, @Blacksmithing, @Enchanting, @Engineering, @Herbalism, @Inscription, @Jewelcrafting, @Leatherworking, @Mining, @Skinning, @Tailoring);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
-- Alchemy
(@Alchemy, 53840, 120000, 171, 395, 0), -- Elixir of Mighty Agility
(@Alchemy, 53847, 65000, 171, 385, 0), -- Elixir of Spirit
(@Alchemy, 53905, 120000, 171, 395, 0), -- Indestructible Potion
(@Alchemy, 62213, 120000, 171, 385, 0), -- Lesser Flask of Resistance
(@Alchemy, 58868, 150000, 171, 410, 0), -- Endless Mana Potion
(@Alchemy, 67025, 100000, 171, 425, 0), -- Flask of the North
(@Alchemy, 51303, 350000, 171, 350, 65), -- Grand Master Alchemist
(@Alchemy, 58871, 150000, 171, 410, 0), -- Endless Healing Potion
(@Alchemy, 66663, 200000, 171, 450, 0), -- Transmute: Majestic Zircon
(@Alchemy, 66658, 200000, 171, 450, 0), -- Transmute: Ametrine
(@Alchemy, 66664, 200000, 171, 450, 0), -- Transmute: Eye of Zul
(@Alchemy, 66662, 200000, 171, 450, 0), -- Transmute: Dreadstone
(@Alchemy, 66660, 200000, 171, 450, 0), -- Transmute: King's Amber
(@Alchemy, 53848, 60000, 171, 375, 0), -- Guru's Elixir
(@Alchemy, 53841, 40000, 171, 355, 0), -- Wrath Elixir
(@Alchemy, 62409, 60000, 171, 375, 0), -- Ethereal Oil
(@Alchemy, 53842, 40000, 171, 365, 0), -- Spellpower Elixir
(@Alchemy, 53899, 60000, 171, 375, 0), -- Lesser Flask of Toughness
(@Alchemy, 53812, 60000, 171, 375, 0), -- Pygmy Oil
(@Alchemy, 53838, 40000, 171, 350, 0), -- Resurgent Healing Potion
(@Alchemy, 53839, 40000, 171, 360, 0), -- Icy Mana Potion
(@Alchemy, 53900, 120000, 171, 380, 0), -- Potion of Nightmares
(@Alchemy, 54218, 120000, 171, 385, 0), -- Elixir of Mighty Strength
(@Alchemy, 53898, 120000, 171, 390, 0), -- Elixir of Mighty Fortitude
(@Alchemy, 60367, 120000, 171, 395, 0), -- Elixir of Mighty Thoughts
(@Alchemy, 60350, 150000, 171, 395, 0), -- Transmute: Titanium
(@Alchemy, 60893, 200000, 171, 400, 0), -- Northrend Alchemy Research
(@Alchemy, 60396, 200000, 171, 400, 0), -- Mercurial Alchemist Stone
(@Alchemy, 60403, 200000, 171, 400, 0), -- Indestructible Alchemist Stone
(@Alchemy, 60405, 200000, 171, 400, 0), -- Mighty Alchemist Stone
(@Alchemy, 53836, 150000, 171, 405, 0), -- Runic Healing Potion
(@Alchemy, 53837, 150000, 171, 410, 0), -- Runic Mana Potion
(@Alchemy, 57427, 150000, 171, 425, 0), -- Transmute: Earthsiege Diamond
(@Alchemy, 57425, 150000, 171, 430, 0), -- Transmute: Skyflare Diamond
(@Alchemy, 53901, 180000, 171, 435, 0), -- Flask of the Frost Wyrm
(@Alchemy, 53902, 150000, 171, 435, 0), -- Flask of Stoneblood
(@Alchemy, 53903, 180000, 171, 435, 0), -- Flask of Endless Rage
(@Alchemy, 54213, 150000, 171, 435, 0), -- Flask of Pure Mojo
(@Alchemy, 39636, 25000, 171, 310, 0), -- Elixir of Major Fortitude
(@Alchemy, 39638, 30000, 171, 320, 0), -- Elixir of Draenic Wisdom
(@Alchemy, 33733, 25000, 171, 310, 0), -- Unstable Mana Potion
(@Alchemy, 33741, 30000, 171, 315, 0), -- Elixir of Mastery
(@Alchemy, 28597, 100000, 171, 275, 50), -- Master Alchemist
(@Alchemy, 33738, 20000, 171, 300, 0), -- Onslaught Elixir
(@Alchemy, 33732, 20000, 171, 300, 0), -- Volatile Healing Potion
(@Alchemy, 33740, 20000, 171, 300, 0), -- Adept's Elixir
(@Alchemy, 28544, 25000, 171, 305, 0), -- Elixir of Major Strength
(@Alchemy, 28545, 25000, 171, 310, 0), -- Elixir of Healing Power
(@Alchemy, 28551, 50000, 171, 325, 0), -- Super Healing Potion
(@Alchemy, 45061, 35000, 171, 325, 0), -- Mad Alchemist's Potion
(@Alchemy, 38070, 20000, 171, 325, 0), -- Mercurial Stone
(@Alchemy, 17551, 15000, 171, 250, 0), -- Stonescale Oil
(@Alchemy, 11612, 50000, 171, 200, 35), -- Artisan Alchemist
(@Alchemy, 15833, 10000, 171, 230, 0), -- Dreamless Sleep Potion
(@Alchemy, 11460, 5000, 171, 230, 0), -- Elixir of Detect Undead
(@Alchemy, 11461, 10000, 171, 235, 0), -- Arcane Elixir
(@Alchemy, 11465, 12000, 171, 235, 0), -- Elixir of Greater Intellect
(@Alchemy, 11467, 12000, 171, 240, 0), -- Elixir of Greater Agility
(@Alchemy, 11478, 14000, 171, 250, 0), -- Elixir of Detect Demon
(@Alchemy, 17552, 15000, 171, 255, 0), -- Mighty Rage Potion
(@Alchemy, 17553, 15000, 171, 260, 0), -- Superior Mana Potion
(@Alchemy, 17555, 15000, 171, 270, 0), -- Elixir of the Sages
(@Alchemy, 17556, 20000, 171, 275, 0), -- Major Healing Potion
(@Alchemy, 17557, 20000, 171, 275, 0), -- Elixir of Brute Force
(@Alchemy, 17572, 20000, 171, 285, 0), -- Purification Potion
(@Alchemy, 17573, 20000, 171, 285, 0), -- Greater Arcane Elixir
(@Alchemy, 22808, 10000, 171, 215, 0), -- Elixir of Greater Water Breathing
(@Alchemy, 3465, 5000, 171, 125, 20), -- Expert Alchemist
(@Alchemy, 3449, 5000, 171, 165, 0), -- Shadow Oil
(@Alchemy, 3450, 6000, 171, 175, 0), -- Elixir of Fortitude
(@Alchemy, 3448, 5000, 171, 165, 0), -- Lesser Invisibility Potion
(@Alchemy, 3452, 5000, 171, 160, 0), -- Mana Potion
(@Alchemy, 11449, 6500, 171, 185, 0), -- Elixir of Agility
(@Alchemy, 11450, 7500, 171, 195, 0), -- Elixir of Greater Defense
(@Alchemy, 11451, 8000, 171, 205, 0), -- Oil of Immolation
(@Alchemy, 11448, 9000, 171, 205, 0), -- Greater Mana Potion
(@Alchemy, 11457, 10000, 171, 215, 0), -- Superior Healing Potion
(@Alchemy, 12609, 8000, 171, 200, 0), -- Catseye Elixir
(@Alchemy, 7181, 5000, 171, 155, 0), -- Greater Healing Potion
(@Alchemy, 7841, 1000, 171, 100, 0), -- Swim Speed Potion
(@Alchemy, 7845, 3000, 171, 140, 0), -- Elixir of Firepower
(@Alchemy, 2280, 500, 171, 50, 10), -- Journeyman Alchemist
(@Alchemy, 63732, 2000, 171, 135, 0), -- Elixir of Minor Accuracy
(@Alchemy, 3171, 500, 171, 90, 0), -- Elixir of Wisdom
(@Alchemy, 3173, 1500, 171, 120, 0), -- Lesser Mana Potion
(@Alchemy, 3176, 1500, 171, 125, 0), -- Strong Troll's Blood Elixir
(@Alchemy, 3177, 2000, 171, 130, 0), -- Elixir of Defense
(@Alchemy, 3447, 4000, 171, 110, 0), -- Healing Potion
(@Alchemy, 7179, 450, 171, 90, 0), -- Elixir of Water Breathing
(@Alchemy, 7837, 1000, 171, 130, 0), -- Fire Oil
(@Alchemy, 7836, 250, 171, 80, 0), -- Blackmouth Oil
(@Alchemy, 2275, 10, 0, 0, 5), -- Apprentice Alchemist
(@Alchemy, 2331, 100, 171, 25, 0), -- Minor Mana Potion
(@Alchemy, 2332, 150, 171, 40, 0), -- Minor Rejuvenation Potion
(@Alchemy, 2337, 1000, 171, 55, 0), -- Lesser Healing Potion
(@Alchemy, 3170, 50, 171, 15, 0), -- Weak Troll's Blood Elixir
(@Alchemy, 2334, 250, 171, 50, 0), -- Elixir of Minor Fortitude
(@Alchemy, 94162, 200000, 171, 500, 0), -- Flask of Flowing Water
(@Alchemy, 80479, 150000, 171, 455, 0), -- Deathblood Venom
(@Alchemy, 80480, 150000, 171, 455, 0), -- Elixir of the Naga
(@Alchemy, 80481, 160000, 171, 460, 0), -- Volcanic Potion
(@Alchemy, 80269, 160000, 171, 460, 0), -- Potion of Illusion
(@Alchemy, 80482, 160000, 171, 465, 0), -- Potion of Concentration
(@Alchemy, 80484, 160000, 171, 465, 0), -- Elixir of the Cobra
(@Alchemy, 80486, 160000, 171, 470, 0), -- Deepstone Oil
(@Alchemy, 80487, 160000, 171, 470, 0), -- Mysterious Potion
(@Alchemy, 80488, 160000, 171, 475, 0), -- Elixir of Deep Earth
(@Alchemy, 80490, 160000, 171, 475, 0), -- Mighty Rejuvenation Potion
(@Alchemy, 80491, 175000, 171, 480, 0), -- Elixir of Impossible Accuracy
(@Alchemy, 80492, 175000, 171, 480, 0), -- Prismatic Elixir
(@Alchemy, 80495, 175000, 171, 485, 0), -- Potion of the Tol'vir
(@Alchemy, 80494, 175000, 171, 485, 0), -- Mythical Mana Potion
(@Alchemy, 80493, 175000, 171, 490, 0), -- Elixir of Mighty Speed
(@Alchemy, 80496, 175000, 171, 490, 0), -- Golemblood Potion
(@Alchemy, 80497, 175000, 171, 495, 0), -- Elixir of the Master
(@Alchemy, 80498, 175000, 171, 495, 0), -- Mythical Healing Potion
(@Alchemy, 80719, 200000, 171, 500, 0), -- Flask of Steelskin
(@Alchemy, 80720, 200000, 171, 505, 0), -- Flask of the Draconic Mind
(@Alchemy, 80721, 200000, 171, 510, 0), -- Flask of the Winds
(@Alchemy, 80723, 200000, 171, 510, 0), -- Flask of Titanic Strength
(@Alchemy, 80724, 200000, 171, 500, 0), -- Flask of Enhancement
(@Alchemy, 78866, 175000, 171, 485, 0), -- Transmute: Living Elements
(@Alchemy, 80237, 250000, 171, 525, 0), -- Transmute: Shadowspirit Diamond
(@Alchemy, 80243, 250000, 171, 525, 0), -- Transmute: Truegold
(@Alchemy, 80244, 200000, 171, 520, 0), -- Transmute: Pyrium Bar
(@Alchemy, 80245, 250000, 171, 525, 0), -- Transmute: Inferno Ruby
(@Alchemy, 80246, 200000, 171, 515, 0), -- Transmute: Ocean Sapphire
(@Alchemy, 80247, 200000, 171, 520, 0), -- Transmute: Amberjewel
(@Alchemy, 80248, 200000, 171, 515, 0), -- Transmute: Demonseye
(@Alchemy, 80250, 200000, 171, 510, 0), -- Transmute: Ember Topaz
(@Alchemy, 80251, 200000, 171, 505, 0), -- Transmute: Dream Emerald
(@Alchemy, 80508, 100000, 171, 500, 0), -- Lifebound Alchemist Stone
(@Alchemy, 80725, 250000, 171, 525, 0), -- Potion of Deepholm
(@Alchemy, 80726, 250000, 171, 525, 0), -- Potion of Treasure Finding
(@Alchemy, 80732, 500000, 171, 425, 75), -- Illustrious Grand Master Alchemist
(@Alchemy, 96253, 100000, 171, 500, 0), -- Quicksilver Alchemist Stone
(@Alchemy, 96254, 100000, 171, 500, 0), -- Vibrant Alchemist Stone
(@Alchemy, 96252, 100000, 171, 500, 0), -- Volatile Alchemist Stone
(@Alchemy, 93935, 150000, 171, 425, 0), -- Draught of War
(@Alchemy, 80478, 150000, 171, 450, 0), -- Earthen Potion
(@Alchemy, 80477, 150000, 171, 450, 0), -- Ghost Elixir
-- Blacksmithing
(@Blacksmithing, 29550, 25000, 164, 325, 0), -- Fel Iron Breastplate
(@Blacksmithing, 29547, 15000, 164, 305, 0), -- Fel Iron Plate Belt
(@Blacksmithing, 29565, 22000, 164, 320, 0), -- Fel Iron Greatsword
(@Blacksmithing, 29549, 20000, 164, 315, 0), -- Fel Iron Plate Pants
(@Blacksmithing, 29558, 20000, 164, 315, 0), -- Fel Iron Hammer
(@Blacksmithing, 34983, 50000, 164, 350, 0), -- Felsteel Whisper Knives
(@Blacksmithing, 32284, 25000, 164, 325, 0), -- Lesser Rune of Warding
(@Blacksmithing, 29552, 18000, 164, 310, 0), -- Fel Iron Chain Gloves
(@Blacksmithing, 29557, 18000, 164, 310, 0), -- Fel Iron Hatchet
(@Blacksmithing, 29553, 20000, 164, 315, 0), -- Fel Iron Chain Bracers
(@Blacksmithing, 29548, 20000, 164, 315, 0), -- Fel Iron Plate Boots
(@Blacksmithing, 29556, 22000, 164, 320, 0), -- Fel Iron Chain Tunic
(@Blacksmithing, 29845, 100000, 164, 275, 50), -- Master Blacksmith
(@Blacksmithing, 29551, 15000, 164, 300, 0), -- Fel Iron Chain Coif
(@Blacksmithing, 32655, 10000, 164, 300, 0), -- Fel Iron Rod
(@Blacksmithing, 34607, 15000, 164, 300, 0), -- Fel Weightstone
(@Blacksmithing, 29545, 15000, 164, 300, 0), -- Fel Iron Plate Gloves
(@Blacksmithing, 29654, 15000, 164, 300, 0), -- Fel Sharpening Stone
(@Blacksmithing, 16639, 10000, 164, 250, 0), -- Dense Grinding Stone
(@Blacksmithing, 19669, 10000, 164, 275, 0), -- Arcanite Skeleton Key
(@Blacksmithing, 10001, 15000, 164, 230, 0), -- Big Black Mace
(@Blacksmithing, 34982, 10000, 164, 300, 0), -- Enchanted Thorium Blades
(@Blacksmithing, 16971, 15000, 164, 280, 0), -- Huge Thorium Battleaxe
(@Blacksmithing, 16652, 10000, 164, 280, 0), -- Thorium Boots
(@Blacksmithing, 16653, 10000, 164, 280, 0), -- Thorium Helm
(@Blacksmithing, 16662, 12000, 164, 300, 0), -- Thorium Leggings
(@Blacksmithing, 16640, 10000, 164, 250, 0), -- Dense Weightstone
(@Blacksmithing, 16641, 10000, 164, 250, 0), -- Dense Sharpening Stone
(@Blacksmithing, 9786, 50000, 164, 200, 35), -- Artisan Blacksmith
(@Blacksmithing, 9959, 15000, 164, 230, 0), -- Heavy Mithril Breastplate
(@Blacksmithing, 9961, 15000, 164, 230, 0), -- Mithril Coif
(@Blacksmithing, 20201, 10000, 164, 275, 0), -- Arcanite Rod
(@Blacksmithing, 16649, 10000, 164, 270, 0), -- Imperial Plate Bracers
(@Blacksmithing, 16657, 10000, 164, 295, 0), -- Imperial Plate Boots
(@Blacksmithing, 16658, 10000, 164, 295, 0), -- Imperial Plate Helm
(@Blacksmithing, 16730, 12000, 164, 300, 0), -- Imperial Plate Leggings
(@Blacksmithing, 16646, 10000, 164, 265, 0), -- Imperial Plate Shoulders
(@Blacksmithing, 16647, 10000, 164, 265, 0), -- Imperial Plate Belt
(@Blacksmithing, 16663, 12000, 164, 300, 0), -- Imperial Plate Chest
(@Blacksmithing, 9968, 20000, 164, 235, 0), -- Heavy Mithril Boots
(@Blacksmithing, 16642, 10000, 164, 250, 0), -- Thorium Armor
(@Blacksmithing, 16643, 10000, 164, 250, 0), -- Thorium Belt
(@Blacksmithing, 16644, 10000, 164, 255, 0), -- Thorium Bracers
(@Blacksmithing, 16969, 15000, 164, 275, 0), -- Ornate Thorium Handaxe
(@Blacksmithing, 3501, 1000, 164, 165, 0), -- Green Iron Bracers
(@Blacksmithing, 7223, 1000, 164, 185, 0), -- Golden Scale Bracers
(@Blacksmithing, 34981, 7500, 164, 200, 0), -- Whirling Steel Axes
(@Blacksmithing, 9993, 10000, 164, 210, 0), -- Heavy Mithril Axe
(@Blacksmithing, 9916, 2500, 164, 200, 0), -- Steel Breastplate
(@Blacksmithing, 3539, 5000, 164, 125, 20), -- Expert Blacksmith
(@Blacksmithing, 9921, 2500, 164, 200, 0), -- Solid Weightstone
(@Blacksmithing, 9920, 2500, 164, 200, 0), -- Solid Grinding Stone
(@Blacksmithing, 3502, 1250, 164, 170, 0), -- Green Iron Helm
(@Blacksmithing, 3506, 5000, 164, 155, 0), -- Green Iron Leggings
(@Blacksmithing, 3508, 7500, 164, 180, 0), -- Green Iron Hauberk
(@Blacksmithing, 19668, 2500, 164, 200, 0), -- Truesilver Skeleton Key
(@Blacksmithing, 9918, 2500, 164, 200, 0), -- Solid Sharpening Stone
(@Blacksmithing, 14380, 2500, 164, 200, 0), -- Truesilver Rod
(@Blacksmithing, 15972, 7500, 164, 180, 0), -- Glinting Steel Dagger
(@Blacksmithing, 9928, 5000, 164, 205, 0), -- Heavy Mithril Gauntlet
(@Blacksmithing, 9931, 5000, 164, 210, 0), -- Mithril Scale Pants
(@Blacksmithing, 9926, 5000, 164, 205, 0), -- Heavy Mithril Shoulder
(@Blacksmithing, 9935, 5000, 164, 215, 0), -- Steel Plate Helm
(@Blacksmithing, 2664, 500, 164, 90, 0), -- Runed Copper Bracers
(@Blacksmithing, 2740, 200, 164, 110, 0), -- Bronze Mace
(@Blacksmithing, 2741, 200, 164, 115, 0), -- Bronze Axe
(@Blacksmithing, 2742, 200, 164, 120, 0), -- Bronze Shortsword
(@Blacksmithing, 2668, 300, 164, 105, 0), -- Rough Bronze Leggings
(@Blacksmithing, 2670, 500, 164, 105, 0), -- Rough Bronze Cuirass
(@Blacksmithing, 2672, 500, 164, 120, 0), -- Patterned Bronze Bracers
(@Blacksmithing, 2674, 1000, 164, 125, 0), -- Heavy Sharpening Stone
(@Blacksmithing, 2675, 1000, 164, 145, 0), -- Shining Silver Breastplate
(@Blacksmithing, 3117, 1000, 164, 125, 0), -- Heavy Weightstone
(@Blacksmithing, 3292, 500, 164, 95, 0), -- Heavy Copper Broadsword
(@Blacksmithing, 3328, 500, 164, 110, 0), -- Rough Bronze Shoulders
(@Blacksmithing, 3331, 500, 164, 130, 0), -- Silvered Bronze Boots
(@Blacksmithing, 7818, 100, 164, 100, 0), -- Silver Rod
(@Blacksmithing, 8768, 250, 164, 150, 0), -- Iron Buckle
(@Blacksmithing, 6517, 800, 164, 110, 0), -- Pearl-handled Dagger
(@Blacksmithing, 7817, 200, 164, 95, 0), -- Rough Bronze Boots
(@Blacksmithing, 19666, 100, 164, 100, 0), -- Silver Skeleton Key
(@Blacksmithing, 9985, 250, 164, 125, 0), -- Bronze Warhammer
(@Blacksmithing, 9986, 500, 164, 130, 0), -- Bronze Greatsword
(@Blacksmithing, 9987, 500, 164, 135, 0), -- Bronze Battle Axe
(@Blacksmithing, 2021, 500, 164, 50, 10), -- Journeyman Blacksmith
(@Blacksmithing, 3333, 1000, 164, 135, 0), -- Silvered Bronze Gauntlets
(@Blacksmithing, 3337, 1000, 164, 125, 0), -- Heavy Grinding Stone
(@Blacksmithing, 3491, 600, 164, 105, 0), -- Big Bronze Knife
(@Blacksmithing, 19667, 250, 164, 150, 0), -- Golden Skeleton Key
(@Blacksmithing, 34979, 600, 164, 100, 0), -- Thick Bronze Darts
(@Blacksmithing, 14379, 250, 164, 150, 0), -- Golden Rod
(@Blacksmithing, 3296, 1000, 164, 130, 0), -- Heavy Bronze Mace
(@Blacksmithing, 2661, 100, 164, 35, 0), -- Copper Chain Belt
(@Blacksmithing, 2665, 100, 164, 65, 0), -- Coarse Sharpening Stone
(@Blacksmithing, 2666, 200, 164, 70, 0), -- Runed Copper Belt
(@Blacksmithing, 3116, 100, 164, 65, 0), -- Coarse Weightstone
(@Blacksmithing, 3293, 250, 164, 35, 0), -- Copper Battle Axe
(@Blacksmithing, 3323, 100, 164, 40, 0), -- Runed Copper Gauntlets
(@Blacksmithing, 3324, 200, 164, 45, 0), -- Runed Copper Pants
(@Blacksmithing, 3326, 250, 164, 75, 0), -- Coarse Grinding Stone
(@Blacksmithing, 7408, 300, 164, 65, 0), -- Heavy Copper Maul
(@Blacksmithing, 8880, 100, 164, 30, 0), -- Copper Dagger
(@Blacksmithing, 2738, 50, 164, 20, 0), -- Copper Axe
(@Blacksmithing, 2739, 50, 164, 25, 0), -- Copper Shortsword
(@Blacksmithing, 9983, 100, 164, 30, 0), -- Copper Claymore
(@Blacksmithing, 2020, 10, 0, 0, 5), -- Apprentice Blacksmith
(@Blacksmithing, 2662, 50, 164, 1, 0), -- Copper Chain Pants
(@Blacksmithing, 2737, 50, 164, 15, 0), -- Copper Mace
(@Blacksmithing, 3320, 100, 164, 25, 0), -- Rough Grinding Stone
(@Blacksmithing, 3294, 500, 164, 70, 0), -- Thick War Axe
(@Blacksmithing, 3319, 50, 164, 20, 0), -- Copper Chain Boots
(@Blacksmithing, 76179, 40000, 164, 440, 0), -- Hardened Obsidium Bracers
(@Blacksmithing, 76181, 55000, 164, 460, 0), -- Hardened Obsidium Belt
(@Blacksmithing, 76182, 60000, 164, 470, 0), -- Hardened Obsidium Boots
(@Blacksmithing, 76258, 65000, 164, 480, 0), -- Hardened Obsidium Shoulders
(@Blacksmithing, 76259, 65000, 164, 490, 0), -- Hardened Obsidium Legguards
(@Blacksmithing, 76260, 65000, 164, 490, 0), -- Hardened Obsidium Helm
(@Blacksmithing, 76261, 75000, 164, 500, 0), -- Hardened Obsidium Breastplate
(@Blacksmithing, 76264, 55000, 164, 460, 0), -- Redsteel Belt
(@Blacksmithing, 76265, 60000, 164, 470, 0), -- Redsteel Boots
(@Blacksmithing, 76266, 65000, 164, 480, 0), -- Redsteel Shoulders
(@Blacksmithing, 76267, 65000, 164, 490, 0), -- Redsteel Legguards
(@Blacksmithing, 76269, 75000, 164, 500, 0), -- Redsteel Helm
(@Blacksmithing, 76270, 75000, 164, 500, 0), -- Redsteel Breastplate
(@Blacksmithing, 76283, 55000, 164, 460, 0), -- Stormforged Belt
(@Blacksmithing, 76285, 60000, 164, 470, 0), -- Stormforged Boots
(@Blacksmithing, 76286, 65000, 164, 480, 0), -- Stormforged Shoulders
(@Blacksmithing, 76287, 65000, 164, 480, 0), -- Stormforged Legguards
(@Blacksmithing, 76288, 65000, 164, 490, 0), -- Stormforged Helm
(@Blacksmithing, 76289, 75000, 164, 500, 0), -- Stormforged Breastplate
(@Blacksmithing, 76293, 60000, 164, 470, 0), -- Stormforged Shield
(@Blacksmithing, 76433, 50000, 164, 460, 0), -- Decapitator's Razor
(@Blacksmithing, 76434, 60000, 164, 470, 0), -- Cold-Forged Shank
(@Blacksmithing, 76435, 65000, 164, 480, 0), -- Fire-Etched Dagger
(@Blacksmithing, 76436, 65000, 164, 480, 0), -- Lifeforce Hammer
(@Blacksmithing, 76437, 65000, 164, 480, 0), -- Obsidium Executioner
(@Blacksmithing, 76438, 60000, 164, 475, 0), -- Obsidium Skeleton Key
(@Blacksmithing, 76441, 65000, 164, 490, 0), -- Elementium Shield Spike
(@Blacksmithing, 76474, 60000, 164, 470, 0), -- Obsidium Bladespear
(@Blacksmithing, 76291, 50000, 164, 450, 0), -- Hardened Obsidium Shield
(@Blacksmithing, 76263, 50000, 164, 450, 0), -- Redsteel Gauntlets
(@Blacksmithing, 76180, 50000, 164, 450, 0), -- Hardened Obsidium Gauntlets
(@Blacksmithing, 76280, 40000, 164, 440, 0), -- Stormforged Bracers
(@Blacksmithing, 76281, 50000, 164, 450, 0), -- Stormforged Gauntlets
(@Blacksmithing, 76262, 40000, 164, 440, 0), -- Redsteel Bracers
(@Blacksmithing, 92375, 60000, 164, 475, 0), -- Elementium Rod
(@Blacksmithing, 76667, 500000, 164, 425, 75), -- Illustrious Grand Master Blacksmith
(@Blacksmithing, 76178, 15000, 164, 425, 0), -- Folded Obsidium
(@Blacksmithing, 54918, 30000, 164, 380, 0), -- Spiked Cobalt Boots
(@Blacksmithing, 54941, 30000, 164, 385, 0), -- Spiked Cobalt Shoulders
(@Blacksmithing, 54944, 30000, 164, 385, 0), -- Spiked Cobalt Chestpiece
(@Blacksmithing, 54945, 35000, 164, 390, 0), -- Spiked Cobalt Gauntlets
(@Blacksmithing, 54946, 30000, 164, 395, 0), -- Spiked Cobalt Belt
(@Blacksmithing, 54947, 35000, 164, 395, 0), -- Spiked Cobalt Legplates
(@Blacksmithing, 55058, 45000, 164, 415, 0), -- Brilliant Saronite Breastplate
(@Blacksmithing, 55302, 45000, 164, 425, 0), -- Helm of Command
(@Blacksmithing, 55303, 45000, 164, 425, 0), -- Daunting Legplates
(@Blacksmithing, 55304, 45000, 164, 425, 0), -- Righteous Greaves
(@Blacksmithing, 55305, 45000, 164, 420, 0), -- Savage Saronite Bracers
(@Blacksmithing, 55306, 45000, 164, 420, 0), -- Savage Saronite Pauldrons
(@Blacksmithing, 55307, 45000, 164, 420, 0), -- Savage Saronite Waistguard
(@Blacksmithing, 55308, 45000, 164, 420, 0), -- Savage Saronite Walkers
(@Blacksmithing, 59438, 40000, 164, 400, 0), -- Brilliant Saronite Bracers
(@Blacksmithing, 55300, 45000, 164, 420, 0), -- Righteous Gauntlets
(@Blacksmithing, 55301, 45000, 164, 420, 0), -- Daunting Handguards
(@Blacksmithing, 55298, 45000, 164, 420, 0), -- Vengeance Bindings
(@Blacksmithing, 55309, 45000, 164, 420, 0), -- Savage Saronite Gauntlets
(@Blacksmithing, 55310, 45000, 164, 425, 0), -- Savage Saronite Legplates
(@Blacksmithing, 55311, 45000, 164, 425, 0), -- Savage Saronite Hauberk
(@Blacksmithing, 55312, 45000, 164, 425, 0), -- Savage Saronite Skullshield
(@Blacksmithing, 56234, 150000, 164, 440, 0), -- Titansteel Shanker
(@Blacksmithing, 55839, 42000, 164, 420, 0), -- Titanium Weapon Chain
(@Blacksmithing, 55174, 50000, 164, 390, 0), -- Honed Cobalt Cleaver
(@Blacksmithing, 55177, 50000, 164, 395, 0), -- Savage Cobalt Slicer
(@Blacksmithing, 55179, 50000, 164, 400, 0), -- Saronite Ambusher
(@Blacksmithing, 55181, 50000, 164, 405, 0), -- Saronite Shiv
(@Blacksmithing, 55182, 40000, 164, 410, 0), -- Furious Saronite Beatstick
(@Blacksmithing, 55200, 35000, 164, 380, 0), -- Sturdy Cobalt Quickblade
(@Blacksmithing, 55201, 35000, 164, 380, 0), -- Cobalt Tenderizer
(@Blacksmithing, 55203, 35000, 164, 385, 0), -- Forged Cobalt Claymore
(@Blacksmithing, 55204, 35000, 164, 390, 0), -- Notched Cobalt War Axe
(@Blacksmithing, 55202, 35000, 164, 385, 0), -- Sure-fire Shuriken
(@Blacksmithing, 55206, 40000, 164, 405, 0), -- Deadly Saronite Dirk
(@Blacksmithing, 63182, 150000, 164, 440, 0), -- Titansteel Spellblade
(@Blacksmithing, 51298, 350000, 164, 350, 65), -- Grand Master Blacksmith
(@Blacksmithing, 52569, 30000, 164, 350, 0), -- Cobalt Boots
(@Blacksmithing, 52568, 30000, 164, 350, 0), -- Cobalt Belt
(@Blacksmithing, 52570, 30000, 164, 375, 0), -- Cobalt Chestpiece
(@Blacksmithing, 55834, 30000, 164, 360, 0), -- Cobalt Bracers
(@Blacksmithing, 52572, 30000, 164, 360, 0), -- Cobalt Shoulders
(@Blacksmithing, 54917, 30000, 164, 375, 0), -- Spiked Cobalt Helm
(@Blacksmithing, 52567, 30000, 164, 370, 0), -- Cobalt Legplates
(@Blacksmithing, 54948, 30000, 164, 400, 0), -- Spiked Cobalt Bracers
(@Blacksmithing, 54949, 30000, 164, 400, 0), -- Horned Cobalt Helm
(@Blacksmithing, 56280, 40000, 164, 410, 0), -- Cudgel of Saronite Justice
(@Blacksmithing, 56357, 42000, 164, 420, 0), -- Titanium Shield Spike
(@Blacksmithing, 56400, 150000, 164, 440, 0), -- Titansteel Shield Wall
(@Blacksmithing, 56549, 45000, 164, 420, 0), -- Ornate Saronite Bracers
(@Blacksmithing, 56550, 45000, 164, 420, 0), -- Ornate Saronite Pauldrons
(@Blacksmithing, 56551, 45000, 164, 420, 0), -- Ornate Saronite Waistguard
(@Blacksmithing, 56552, 45000, 164, 420, 0), -- Ornate Saronite Walkers
(@Blacksmithing, 56553, 45000, 164, 420, 0), -- Ornate Saronite Gauntlets
(@Blacksmithing, 56554, 45000, 164, 425, 0), -- Ornate Saronite Legplates
(@Blacksmithing, 56555, 45000, 164, 425, 0), -- Ornate Saronite Hauberk
(@Blacksmithing, 56556, 45000, 164, 425, 0), -- Ornate Saronite Skullshield
(@Blacksmithing, 55055, 40000, 164, 395, 0), -- Brilliant Saronite Legplates
(@Blacksmithing, 55056, 40000, 164, 400, 0), -- Brilliant Saronite Gauntlets
(@Blacksmithing, 55057, 40000, 164, 405, 0), -- Brilliant Saronite Boots
(@Blacksmithing, 54551, 40000, 164, 395, 0), -- Tempered Saronite Belt
(@Blacksmithing, 54552, 40000, 164, 400, 0), -- Tempered Saronite Boots
(@Blacksmithing, 55375, 120000, 164, 440, 0), -- Spiked Titansteel Treads
(@Blacksmithing, 55376, 120000, 164, 440, 0), -- Tempered Titansteel Treads
(@Blacksmithing, 55369, 180000, 164, 440, 0), -- Titansteel Destroyer
(@Blacksmithing, 55370, 150000, 164, 440, 0), -- Titansteel Bonecrusher
(@Blacksmithing, 55377, 120000, 164, 440, 0), -- Brilliant Titansteel Treads
(@Blacksmithing, 55185, 45000, 164, 415, 0), -- Saronite Mindcrusher
(@Blacksmithing, 52571, 30000, 164, 370, 0), -- Cobalt Helm
(@Blacksmithing, 55835, 30000, 164, 370, 0), -- Cobalt Gauntlets
(@Blacksmithing, 59405, 30000, 164, 350, 0), -- Cobalt Skeleton Key
(@Blacksmithing, 54550, 30000, 164, 360, 0), -- Cobalt Triangle Shield
(@Blacksmithing, 55371, 150000, 164, 440, 0), -- Titansteel Guardian
(@Blacksmithing, 55372, 120000, 164, 440, 0), -- Spiked Titansteel Helm
(@Blacksmithing, 55373, 120000, 164, 440, 0), -- Tempered Titansteel Helm
(@Blacksmithing, 55374, 120000, 164, 440, 0), -- Brilliant Titansteel Helm
(@Blacksmithing, 55013, 40000, 164, 390, 0), -- Saronite Protector
(@Blacksmithing, 55017, 40000, 164, 410, 0), -- Tempered Saronite Bracers
(@Blacksmithing, 55014, 35000, 164, 410, 0), -- Saronite Bulwark
(@Blacksmithing, 55015, 40000, 164, 415, 0), -- Tempered Saronite Gauntlets
(@Blacksmithing, 55628, 45000, 164, 400, 0), -- Socket Bracer
(@Blacksmithing, 55641, 45000, 164, 400, 0), -- Socket Gloves
(@Blacksmithing, 55656, 50000, 164, 415, 0), -- Eternal Belt Buckle
(@Blacksmithing, 55732, 42000, 164, 420, 0), -- Titanium Rod
(@Blacksmithing, 59442, 40000, 164, 410, 0), -- Saronite Spellblade
(@Blacksmithing, 61008, 120000, 164, 425, 0), -- Icebane Chestguard
(@Blacksmithing, 61009, 120000, 164, 420, 0), -- Icebane Girdle
(@Blacksmithing, 61010, 120000, 164, 420, 0), -- Icebane Treads
(@Blacksmithing, 54553, 40000, 164, 400, 0), -- Tempered Saronite Breastplate
(@Blacksmithing, 54554, 40000, 164, 395, 0), -- Tempered Saronite Legplates
(@Blacksmithing, 54555, 40000, 164, 405, 0), -- Tempered Saronite Helm
(@Blacksmithing, 54556, 40000, 164, 405, 0), -- Tempered Saronite Shoulders
(@Blacksmithing, 54557, 40000, 164, 390, 0), -- Saronite Defender
(@Blacksmithing, 59406, 45000, 164, 430, 0), -- Titanium Skeleton Key
(@Blacksmithing, 59436, 40000, 164, 395, 0), -- Brilliant Saronite Belt
(@Blacksmithing, 59440, 40000, 164, 405, 0), -- Brilliant Saronite Pauldrons
(@Blacksmithing, 59441, 45000, 164, 415, 0), -- Brilliant Saronite Helm
-- Enchanting Trainers
(@Enchanting, 69412, 150000, 333, 445, 0), -- Abyssal Shatter
(@Enchanting, 62959, 90000, 333, 385, 0), -- Enchant Staff - Spellpower
(@Enchanting, 60621, 80000, 333, 380, 0), -- Enchant Weapon - Greater Potency
(@Enchanting, 60623, 90000, 333, 385, 0), -- Enchant Boots - Icewalker
(@Enchanting, 44630, 80000, 333, 390, 0), -- Enchant 2H Weapon - Greater Savagery
(@Enchanting, 44500, 100000, 333, 395, 0), -- Enchant Cloak - Superior Agility
(@Enchanting, 44492, 100000, 333, 395, 0), -- Enchant Chest - Mighty Health
(@Enchanting, 44513, 100000, 333, 395, 0), -- Enchant Gloves - Greater Assault
(@Enchanting, 60653, 100000, 333, 395, 0), -- Enchant Shield - Greater Intellect
(@Enchanting, 44629, 100000, 333, 395, 0), -- Enchant Weapon - Exceptional Spellpower
(@Enchanting, 44635, 100000, 333, 395, 0), -- Enchant Bracer - Greater Spellpower
(@Enchanting, 47766, 100000, 333, 400, 0), -- Enchant Chest - Greater Dodge
(@Enchanting, 44645, 100000, 333, 400, 0), -- Enchant Ring - Assault
(@Enchanting, 51312, 350000, 333, 350, 65), -- Grand Master Enchanter
(@Enchanting, 44592, 50000, 333, 360, 0), -- Enchant Gloves - Exceptional Spellpower
(@Enchanting, 44506, 50000, 333, 375, 0), -- Enchant Gloves - Gatherer
(@Enchanting, 44555, 50000, 333, 375, 0), -- Enchant Bracer - Exceptional Intellect
(@Enchanting, 27958, 50000, 333, 350, 0), -- Enchant Chest - Exceptional Mana
(@Enchanting, 60606, 50000, 333, 375, 0), -- Enchant Boots - Assault
(@Enchanting, 44623, 50000, 333, 370, 0), -- Enchant Chest - Super Stats
(@Enchanting, 60616, 50000, 333, 360, 0), -- Enchant Bracer - Assault
(@Enchanting, 60609, 50000, 333, 350, 0), -- Enchant Cloak - Speed
(@Enchanting, 44508, 150000, 333, 410, 0), -- Enchant Boots - Greater Spirit
(@Enchanting, 44484, 150000, 333, 405, 0), -- Enchant Gloves - Expertise
(@Enchanting, 44584, 150000, 333, 405, 0), -- Enchant Boots - Greater Vitality
(@Enchanting, 44509, 150000, 333, 420, 0), -- Enchant Chest - Greater Mana Restoration
(@Enchanting, 44488, 150000, 333, 410, 0), -- Enchant Gloves - Precision
(@Enchanting, 44528, 90000, 333, 385, 0), -- Enchant Boots - Greater Fortitude
(@Enchanting, 44582, 100000, 333, 395, 0), -- Enchant Cloak - Spell Piercing
(@Enchanting, 47900, 150000, 333, 425, 0), -- Enchant Chest - Super Health
(@Enchanting, 44636, 100000, 333, 400, 0), -- Enchant Ring - Greater Spellpower
(@Enchanting, 59636, 100000, 333, 400, 0), -- Enchant Ring - Stamina
(@Enchanting, 44616, 100000, 333, 400, 0), -- Enchant Bracer - Greater Stats
(@Enchanting, 44510, 150000, 333, 410, 0), -- Enchant Weapon - Exceptional Spirit
(@Enchanting, 44633, 150000, 333, 410, 0), -- Enchant Weapon - Exceptional Agility
(@Enchanting, 44589, 150000, 333, 415, 0), -- Enchant Boots - Superior Agility
(@Enchanting, 44529, 150000, 333, 415, 0), -- Enchant Gloves - Major Agility
(@Enchanting, 44598, 150000, 333, 415, 0), -- Enchant Bracer - Expertise
(@Enchanting, 60663, 150000, 333, 420, 0), -- Enchant Cloak - Major Agility
(@Enchanting, 44489, 150000, 333, 420, 0), -- Enchant Shield - Dodge
(@Enchanting, 44593, 150000, 333, 420, 0), -- Enchant Bracer - Major Spirit
(@Enchanting, 60668, 150000, 333, 425, 0), -- Enchant Gloves - Crusher
(@Enchanting, 60619, 150000, 333, 425, 0), -- Runed Titanium Rod
(@Enchanting, 27961, 15000, 333, 310, 0), -- Enchant Cloak - Major Armor
(@Enchanting, 32667, 50000, 333, 375, 0), -- Runed Eternium Rod
(@Enchanting, 33990, 20000, 333, 320, 0), -- Enchant Chest - Major Spirit
(@Enchanting, 33993, 12500, 333, 305, 0), -- Enchant Gloves - Blasting
(@Enchanting, 33995, 25000, 333, 340, 0), -- Enchant Gloves - Major Strength
(@Enchanting, 33996, 15000, 333, 310, 0), -- Enchant Gloves - Assault
(@Enchanting, 34001, 12500, 333, 305, 0), -- Enchant Bracer - Major Intellect
(@Enchanting, 34004, 15000, 333, 310, 0), -- Enchant Cloak - Greater Agility
(@Enchanting, 42615, 40000, 333, 335, 0), -- Small Prismatic Shard
(@Enchanting, 28030, 100000, 333, 275, 50), -- Master Enchanter
(@Enchanting, 33991, 20000, 333, 300, 0), -- Enchant Chest - Restore Mana Prime
(@Enchanting, 32664, 10000, 333, 300, 0), -- Runed Fel Iron Rod
(@Enchanting, 42613, 10000, 333, 300, 35), -- Nexus Transformation
(@Enchanting, 34002, 12500, 333, 300, 0), -- Enchant Bracer - Lesser Assault
(@Enchanting, 32665, 80000, 333, 350, 0), -- Runed Adamantite Rod
(@Enchanting, 28027, 40000, 333, 325, 0), -- Prismatic Sphere
(@Enchanting, 28028, 80000, 333, 350, 0), -- Void Sphere
(@Enchanting, 44383, 25000, 333, 330, 0), -- Enchant Shield - Resilience
(@Enchanting, 27899, 12500, 333, 305, 0), -- Enchant Bracer - Brawn
(@Enchanting, 27905, 12500, 333, 315, 0), -- Enchant Bracer - Stats
(@Enchanting, 27944, 15000, 333, 310, 0), -- Enchant Shield - Lesser Dodge
(@Enchanting, 27957, 17500, 333, 315, 0), -- Enchant Chest - Exceptional Health
(@Enchanting, 13941, 6200, 333, 245, 0), -- Enchant Chest - Stats
(@Enchanting, 13943, 6200, 333, 245, 0), -- Enchant Weapon - Greater Striking
(@Enchanting, 13948, 6500, 333, 250, 0), -- Enchant Gloves - Minor Haste
(@Enchanting, 13921, 50000, 333, 200, 35), -- Artisan Enchanter
(@Enchanting, 20051, 15000, 333, 290, 0), -- Runed Arcanite Rod
(@Enchanting, 17180, 10000, 333, 250, 0), -- Enchanted Thorium Bar
(@Enchanting, 17181, 10000, 333, 250, 0), -- Enchanted Leather
(@Enchanting, 13905, 5400, 333, 230, 0), -- Enchant Shield - Greater Spirit
(@Enchanting, 13917, 5400, 333, 230, 0), -- Enchant Chest - Superior Mana
(@Enchanting, 13935, 5800, 333, 235, 0), -- Enchant Boots - Agility
(@Enchanting, 13937, 6200, 333, 240, 0), -- Enchant 2H Weapon - Greater Impact
(@Enchanting, 13939, 6200, 333, 240, 0), -- Enchant Bracer - Greater Strength
(@Enchanting, 20008, 10000, 333, 255, 0), -- Enchant Bracer - Greater Intellect
(@Enchanting, 20014, 10000, 333, 265, 0), -- Enchant Cloak - Greater Resistance
(@Enchanting, 20012, 10000, 333, 270, 0), -- Enchant Gloves - Greater Agility
(@Enchanting, 20016, 15000, 333, 280, 0), -- Enchant Shield - Vitality
(@Enchanting, 20028, 15000, 333, 290, 0), -- Enchant Chest - Major Mana
(@Enchanting, 20013, 20000, 333, 295, 0), -- Enchant Gloves - Greater Strength
(@Enchanting, 20023, 20000, 333, 295, 0), -- Enchant Boots - Greater Agility
(@Enchanting, 63746, 5000, 333, 225, 0), -- Enchant Boots - Lesser Accuracy
(@Enchanting, 7416, 5000, 333, 125, 20), -- Expert Enchanter
(@Enchanting, 13646, 2800, 333, 170, 0), -- Enchant Bracer - Lesser Dodge
(@Enchanting, 13659, 3200, 333, 180, 0), -- Enchant Shield - Spirit
(@Enchanting, 14809, 2600, 333, 155, 0), -- Lesser Mystic Wand
(@Enchanting, 14810, 3000, 333, 175, 0), -- Greater Mystic Wand
(@Enchanting, 13635, 2600, 333, 155, 0), -- Enchant Cloak - Defense
(@Enchanting, 13631, 2600, 333, 155, 0), -- Enchant Shield - Lesser Stamina
(@Enchanting, 13637, 2800, 333, 160, 0), -- Enchant Boots - Lesser Agility
(@Enchanting, 13640, 2700, 333, 160, 0), -- Enchant Chest - Greater Health
(@Enchanting, 13642, 2800, 333, 165, 0), -- Enchant Bracer - Spirit
(@Enchanting, 13644, 2800, 333, 170, 0), -- Enchant Boots - Lesser Stamina
(@Enchanting, 13648, 2800, 333, 170, 0), -- Enchant Bracer - Stamina
(@Enchanting, 13657, 3000, 333, 175, 0), -- Enchant Cloak - Fire Resistance
(@Enchanting, 13661, 3600, 333, 180, 0), -- Enchant Bracer - Strength
(@Enchanting, 13663, 3800, 333, 185, 0), -- Enchant Chest - Greater Mana
(@Enchanting, 13693, 4000, 333, 195, 0), -- Enchant Weapon - Striking
(@Enchanting, 13695, 4000, 333, 200, 0), -- Enchant 2H Weapon - Impact
(@Enchanting, 13700, 4000, 333, 200, 0), -- Enchant Chest - Lesser Stats
(@Enchanting, 13702, 4000, 333, 200, 0), -- Runed Truesilver Rod
(@Enchanting, 13746, 4200, 333, 205, 0), -- Enchant Cloak - Greater Defense
(@Enchanting, 13794, 4200, 333, 205, 0), -- Enchant Cloak - Resistance
(@Enchanting, 13815, 4400, 333, 210, 0), -- Enchant Gloves - Agility
(@Enchanting, 13822, 4400, 333, 210, 0), -- Enchant Bracer - Intellect
(@Enchanting, 13836, 4600, 333, 215, 0), -- Enchant Boots - Stamina
(@Enchanting, 13858, 4800, 333, 220, 0), -- Enchant Chest - Superior Health
(@Enchanting, 13887, 5000, 333, 225, 0), -- Enchant Gloves - Strength
(@Enchanting, 13890, 5000, 333, 225, 0), -- Enchant Boots - Minor Speed
(@Enchanting, 7415, 500, 333, 50, 10), -- Journeyman Enchanter
(@Enchanting, 7745, 500, 333, 100, 0), -- Enchant 2H Weapon - Minor Impact
(@Enchanting, 7795, 1000, 333, 100, 0), -- Runed Silver Rod
(@Enchanting, 7788, 500, 333, 90, 0), -- Enchant Weapon - Minor Striking
(@Enchanting, 7857, 1000, 333, 120, 0), -- Enchant Chest - Health
(@Enchanting, 7861, 1250, 333, 125, 0), -- Enchant Cloak - Lesser Fire Resistance
(@Enchanting, 7779, 400, 333, 80, 0), -- Enchant Bracer - Minor Agility
(@Enchanting, 13378, 600, 333, 105, 0), -- Enchant Shield - Minor Stamina
(@Enchanting, 13607, 2400, 333, 145, 0), -- Enchant Chest - Mana
(@Enchanting, 13622, 2500, 333, 150, 0), -- Enchant Bracer - Lesser Intellect
(@Enchanting, 13626, 2500, 333, 150, 0), -- Enchant Chest - Minor Stats
(@Enchanting, 7863, 1400, 333, 125, 0), -- Enchant Boots - Minor Stamina
(@Enchanting, 13421, 800, 333, 115, 0), -- Enchant Cloak - Lesser Protection
(@Enchanting, 13485, 1500, 333, 130, 0), -- Enchant Shield - Lesser Spirit
(@Enchanting, 13501, 1500, 333, 130, 0), -- Enchant Bracer - Lesser Stamina
(@Enchanting, 13503, 2000, 333, 140, 0), -- Enchant Weapon - Lesser Striking
(@Enchanting, 13529, 2400, 333, 145, 0), -- Enchant 2H Weapon - Lesser Impact
(@Enchanting, 13538, 2500, 333, 140, 0), -- Enchant Chest - Lesser Absorption
(@Enchanting, 13628, 2500, 333, 150, 0), -- Runed Golden Rod
(@Enchanting, 14293, 50, 333, 10, 0), -- Lesser Magic Wand
(@Enchanting, 14807, 200, 333, 70, 0), -- Greater Magic Wand
(@Enchanting, 7420, 50, 333, 15, 0), -- Enchant Chest - Minor Health
(@Enchanting, 7454, 100, 333, 45, 0), -- Enchant Cloak - Minor Resistance
(@Enchanting, 7771, 200, 333, 70, 0), -- Enchant Cloak - Minor Protection
(@Enchanting, 7457, 250, 333, 50, 0), -- Enchant Bracer - Minor Stamina
(@Enchanting, 7748, 250, 333, 60, 0), -- Enchant Chest - Lesser Health
(@Enchanting, 7414, 10, 0, 0, 5), -- Apprentice Enchanter
(@Enchanting, 7426, 100, 333, 40, 0), -- Enchant Chest - Minor Absorption
(@Enchanting, 74199, 30000, 333, 455, 0), -- Enchant Boots - Haste
(@Enchanting, 74215, 30000, 333, 475, 0), -- Enchant Ring - Strength
(@Enchanting, 74231, 30000, 333, 495, 0), -- Enchant Chest - Exceptional Spirit
(@Enchanting, 74192, 30000, 333, 435, 0), -- Enchant Cloak - Greater Spell Piercing
(@Enchanting, 74240, 30000, 333, 510, 0), -- Enchant Cloak - Greater Intellect
(@Enchanting, 95471, 30000, 333, 470, 0), -- Enchant 2H Weapon - Mighty Agility
(@Enchanting, 74201, 30000, 333, 460, 0), -- Enchant Bracer - Critical Strike
(@Enchanting, 74217, 30000, 333, 475, 0), -- Enchant Ring - Intellect
(@Enchanting, 74226, 30000, 333, 485, 0), -- Enchant Shield - Mastery
(@Enchanting, 74195, 30000, 333, 450, 0), -- Enchant Weapon - Mending
(@Enchanting, 74211, 30000, 333, 470, 0), -- Enchant Weapon - Elemental Slayer
(@Enchanting, 74235, 30000, 333, 500, 0), -- Enchant Off-Hand - Superior Intellect
(@Enchanting, 74132, 30000, 333, 425, 0), -- Enchant Gloves - Mastery
(@Enchanting, 74212, 30000, 333, 470, 0), -- Enchant Gloves - Exceptional Strength
(@Enchanting, 74220, 30000, 333, 480, 0), -- Enchant Gloves - Greater Expertise
(@Enchanting, 74236, 30000, 333, 505, 0), -- Enchant Boots - Precision
(@Enchanting, 74189, 30000, 333, 425, 0), -- Enchant Boots - Earthen Vitality
(@Enchanting, 74197, 30000, 333, 450, 0), -- Enchant Weapon - Avalanche
(@Enchanting, 74213, 30000, 333, 475, 0), -- Enchant Boots - Major Agility
(@Enchanting, 74229, 30000, 333, 490, 0), -- Enchant Bracer - Superior Dodge
(@Enchanting, 74237, 30000, 333, 505, 0), -- Enchant Bracer - Exceptional Spirit
(@Enchanting, 74198, 30000, 333, 455, 0), -- Enchant Gloves - Haste
(@Enchanting, 74214, 30000, 333, 475, 0), -- Enchant Chest - Mighty Resilience
(@Enchanting, 74230, 30000, 333, 490, 0), -- Enchant Cloak - Critical Strike
(@Enchanting, 74238, 30000, 333, 510, 0), -- Enchant Boots - Mastery
(@Enchanting, 74191, 30000, 333, 425, 0), -- Enchant Chest - Mighty Stats
(@Enchanting, 74207, 30000, 333, 465, 0), -- Enchant Shield - Protection
(@Enchanting, 74223, 30000, 333, 480, 0), -- Enchant Weapon - Hurricane
(@Enchanting, 74239, 30000, 333, 510, 0), -- Enchant Bracer - Greater Expertise
(@Enchanting, 74200, 30000, 333, 460, 0), -- Enchant Chest - Stamina
(@Enchanting, 74216, 30000, 333, 475, 0), -- Enchant Ring - Agility
(@Enchanting, 74232, 30000, 333, 495, 0), -- Enchant Bracer - Precision
(@Enchanting, 74193, 30000, 333, 435, 0), -- Enchant Bracer - Speed
(@Enchanting, 74225, 30000, 333, 485, 0), -- Enchant Weapon - Heartsong
(@Enchanting, 74202, 30000, 333, 465, 0), -- Enchant Cloak - Intellect
(@Enchanting, 74218, 30000, 333, 475, 0), -- Enchant Ring - Greater Stamina
(@Enchanting, 74234, 30000, 333, 500, 0), -- Enchant Cloak - Protection
(@Enchanting, 104698, 30000, 333, 515, 0), -- Maelstrom Shatter
(@Enchanting, 74259, 500000, 333, 425, 75), -- Illustrious Grand Master Enchanter
-- Engineering
(@Engineering, 19792, 10000, 202, 260, 0), -- Thorium Rifle
(@Engineering, 23071, 5000, 202, 260, 0), -- Truesilver Transformer
(@Engineering, 19794, 20000, 202, 270, 0), -- Spellpower Goggles Xtreme Plus
(@Engineering, 19795, 10000, 202, 275, 0), -- Thorium Tube
(@Engineering, 19825, 20000, 202, 290, 0), -- Master Engineer's Goggles
(@Engineering, 19790, 10000, 202, 260, 0), -- Thorium Grenade
(@Engineering, 19791, 5000, 202, 260, 0), -- Thorium Widget
(@Engineering, 23070, 5000, 202, 250, 0), -- Dense Dynamite
(@Engineering, 12618, 2200, 202, 230, 0), -- Rose Colored Goggles
(@Engineering, 12619, 2400, 202, 235, 0), -- Hi-Explosive Bomb
(@Engineering, 12622, 2800, 202, 245, 0), -- Green Lens
(@Engineering, 63750, 5000, 202, 250, 0), -- High-powered Flashlight
(@Engineering, 12617, 2200, 202, 230, 0), -- Deepdive Helmet
(@Engineering, 19567, 4000, 202, 250, 0), -- Salt Shaker
(@Engineering, 19788, 4000, 202, 250, 0), -- Dense Blasting Powder
(@Engineering, 12657, 50000, 202, 200, 35), -- Artisan Engineer
(@Engineering, 12584, 1000, 202, 150, 0), -- Gold Power Core
(@Engineering, 6458, 400, 202, 135, 0), -- Ornate Spyglass
(@Engineering, 8334, 300, 202, 100, 0), -- Clockwork Box
(@Engineering, 9271, 500, 202, 150, 0), -- Aquadynamic Fish Attractor
(@Engineering, 3956, 750, 202, 150, 0), -- Green Tinted Goggles
(@Engineering, 3939, 500, 202, 120, 0), -- Lovingly Crafted Boomstick
(@Engineering, 3973, 300, 202, 90, 0), -- Silver Contact
(@Engineering, 3932, 300, 202, 85, 0), -- Target Dummy
(@Engineering, 3934, 400, 202, 100, 0), -- Flying Tiger Goggles
(@Engineering, 3936, 420, 202, 105, 0), -- Deadly Blunderbuss
(@Engineering, 3937, 450, 202, 105, 0), -- Large Copper Bomb
(@Engineering, 3938, 450, 202, 105, 0), -- Bronze Tube
(@Engineering, 3978, 475, 202, 110, 0), -- Standard Scope
(@Engineering, 3941, 500, 202, 120, 0), -- Small Bronze Bomb
(@Engineering, 3942, 500, 202, 125, 0), -- Whirring Bronze Gizmo
(@Engineering, 3945, 500, 202, 125, 0), -- Heavy Blasting Powder
(@Engineering, 3946, 500, 202, 125, 0), -- Heavy Dynamite
(@Engineering, 3949, 550, 202, 130, 0), -- Silver-plated Shotgun
(@Engineering, 3950, 600, 202, 140, 0), -- Big Bronze Bomb
(@Engineering, 3953, 600, 202, 145, 0), -- Bronze Framework
(@Engineering, 3955, 750, 202, 150, 0), -- Explosive Sheep
(@Engineering, 4040, 500, 202, 50, 10), -- Journeyman Engineer
(@Engineering, 61471, 100000, 202, 390, 0), -- Diamond-cut Refractor Scope
(@Engineering, 60874, 200000, 202, 450, 0), -- Nesingwary 4000
(@Engineering, 67839, 100000, 202, 410, 0), -- Mind Amplification Dish
(@Engineering, 67326, 100000, 202, 410, 0), -- Goblin Beam Welder
(@Engineering, 67920, 150000, 202, 435, 0), -- Wormhole Generator: Northrend
(@Engineering, 63770, 125000, 202, 400, 0), -- Reticulated Armor Webbing
(@Engineering, 55002, 100000, 202, 380, 0), -- Flexweave Underlay
(@Engineering, 56465, 125000, 202, 420, 0), -- Mechanized Snow Goggles
(@Engineering, 54736, 100000, 202, 390, 0), -- Personal Electromagnetic Pulse Generator
(@Engineering, 55016, 125000, 202, 405, 0), -- Nitro Boosts
(@Engineering, 54793, 100000, 202, 380, 0), -- Frag Belt
(@Engineering, 56471, 100000, 202, 390, 0), -- Froststeel Tube
(@Engineering, 56466, 125000, 202, 420, 0), -- Sonic Booster
(@Engineering, 56467, 125000, 202, 420, 0), -- Noise Machine
(@Engineering, 56468, 125000, 202, 405, 0), -- Box of Bombs
(@Engineering, 54353, 125000, 202, 400, 0), -- Mark "S" Boomstick
(@Engineering, 56470, 150000, 202, 425, 0), -- Sun Scope
(@Engineering, 56472, 150000, 202, 425, 0), -- MOLL-E
(@Engineering, 56462, 150000, 202, 435, 0), -- Gnomish Army Knife
(@Engineering, 54998, 125000, 202, 400, 0), -- Hand-Mounted Pyro Rocket
(@Engineering, 54999, 125000, 202, 400, 0), -- Hyperspeed Accelerators
(@Engineering, 56476, 125000, 202, 410, 0), -- Healing Injector Kit
(@Engineering, 56477, 125000, 202, 415, 0), -- Mana Injector Kit
(@Engineering, 56469, 150000, 202, 425, 0), -- Gnomish Lightning Generator
(@Engineering, 56478, 200000, 202, 430, 0), -- Heartseeker Scope
(@Engineering, 56479, 200000, 202, 450, 0), -- Armor Plated Combat Shotgun
(@Engineering, 56484, 150000, 202, 440, 0), -- Visage Liquification Goggles
(@Engineering, 56463, 100000, 202, 375, 0), -- Explosive Decoy
(@Engineering, 53281, 50000, 202, 350, 0), -- Volatile Blasting Trigger
(@Engineering, 51305, 350000, 202, 350, 65), -- Grand Master Engineer
(@Engineering, 56459, 100000, 202, 375, 0), -- Hammer Pick
(@Engineering, 56460, 50000, 202, 350, 0), -- Cobalt Frag Bomb
(@Engineering, 56349, 50000, 202, 350, 0), -- Handful of Cobalt Bolts
(@Engineering, 56461, 100000, 202, 375, 0), -- Bladed Pickaxe
(@Engineering, 56464, 100000, 202, 375, 0), -- Overcharged Capacitor
(@Engineering, 39973, 50000, 202, 335, 0), -- Frost Grenade
(@Engineering, 39971, 20000, 202, 335, 0), -- Icy Blasting Primers
(@Engineering, 30306, 20000, 202, 325, 0), -- Adamantite Frame
(@Engineering, 41320, 50000, 202, 350, 0), -- Destruction Holo-gogs
(@Engineering, 30307, 50000, 202, 340, 0), -- Hardened Adamantite Tube
(@Engineering, 30308, 50000, 202, 340, 0), -- Khorium Power Core
(@Engineering, 30309, 50000, 202, 340, 0), -- Felsteel Stabilizer
(@Engineering, 30311, 25000, 202, 325, 0), -- Adamantite Grenade
(@Engineering, 30312, 20000, 202, 320, 0), -- Fel Iron Musket
(@Engineering, 41307, 50000, 202, 375, 0), -- Gyro-balanced Khorium Destroyer
(@Engineering, 44157, 180000, 202, 375, 70), -- Turbo-Charged Flying Machine
(@Engineering, 30304, 10000, 202, 300, 0), -- Fel Iron Casing
(@Engineering, 30305, 10000, 202, 300, 0), -- Handful of Fel Iron Bolts
(@Engineering, 44155, 60000, 202, 300, 0), -- Flying Machine
(@Engineering, 30310, 15000, 202, 300, 0), -- Fel Iron Bomb
(@Engineering, 30303, 10000, 202, 300, 0), -- Elemental Blasting Powder
(@Engineering, 30351, 100000, 202, 275, 50), -- Master Engineer
(@Engineering, 12615, 2500, 202, 225, 0), -- Spellpower Goggles Xtreme
(@Engineering, 3963, 1000, 202, 175, 0), -- Compact Harvest Reaper Kit
(@Engineering, 3965, 1200, 202, 185, 0), -- Advanced Target Dummy
(@Engineering, 3967, 1400, 202, 190, 0), -- Big Iron Bomb
(@Engineering, 12585, 1000, 202, 175, 0), -- Solid Blasting Powder
(@Engineering, 12586, 1000, 202, 175, 0), -- Solid Dynamite
(@Engineering, 12590, 1000, 202, 175, 0), -- Gyromatic Micro-Adjustor
(@Engineering, 12589, 1300, 202, 195, 0), -- Mithril Tube
(@Engineering, 12591, 1500, 202, 200, 0), -- Unstable Trigger
(@Engineering, 12594, 1600, 202, 205, 0), -- Fire Goggles
(@Engineering, 12595, 1600, 202, 205, 0), -- Mithril Blunderbuss
(@Engineering, 12599, 1800, 202, 215, 0), -- Mithril Casing
(@Engineering, 12603, 1800, 202, 215, 0), -- Mithril Frag Bomb
(@Engineering, 15255, 1500, 202, 200, 0), -- Mechanical Repair Kit
(@Engineering, 3958, 800, 202, 160, 0), -- Iron Strut
(@Engineering, 3961, 900, 202, 170, 0), -- Gyrochronatom
(@Engineering, 3962, 1000, 202, 175, 0), -- Iron Grenade
(@Engineering, 4041, 5000, 202, 125, 20), -- Expert Engineer
(@Engineering, 3922, 115, 202, 30, 0), -- Handful of Copper Bolts
(@Engineering, 3923, 130, 202, 30, 0), -- Rough Copper Bomb
(@Engineering, 7430, 150, 202, 50, 0), -- Arclight Spanner
(@Engineering, 4039, 10, 0, 0, 5), -- Apprentice Engineer
(@Engineering, 3925, 150, 202, 50, 0), -- Rough Boomstick
(@Engineering, 3977, 200, 202, 60, 0), -- Crude Scope
(@Engineering, 3929, 250, 202, 65, 0), -- Coarse Blasting Powder
(@Engineering, 3931, 250, 202, 65, 0), -- Coarse Dynamite
(@Engineering, 84412, 160000, 202, 475, 0), -- Personal World Destroyer
(@Engineering, 95707, 200000, 202, 500, 0), -- Big Daddy
(@Engineering, 95705, 200000, 202, 500, 0), -- Gnomish Gravity Well
(@Engineering, 84413, 160000, 202, 475, 0), -- De-Weaponized Mechanical Companion
(@Engineering, 12755, 2400, 202, 230, 0), -- Goblin Bomb Dispenser
(@Engineering, 12754, 2600, 202, 235, 0), -- The Big One
(@Engineering, 12758, 3000, 202, 245, 0), -- Goblin Rocket Helmet
(@Engineering, 12908, 2800, 202, 240, 0), -- Goblin Dragon Gun
(@Engineering, 12906, 2400, 202, 230, 0), -- Gnomish Battle Chicken
(@Engineering, 12759, 2800, 202, 240, 0), -- Gnomish Death Ray
(@Engineering, 12907, 2600, 202, 235, 0), -- Gnomish Mind Control Cap
(@Engineering, 30558, 25000, 202, 325, 0), -- The Bigger One
(@Engineering, 30563, 50000, 202, 350, 0), -- Goblin Rocket Launcher
(@Engineering, 30565, 100000, 202, 375, 0), -- Foreman's Enchanted Helmet
(@Engineering, 30560, 35000, 202, 340, 0), -- Super Sapper Charge
(@Engineering, 30566, 100000, 202, 375, 0), -- Foreman's Reinforced Helmet
(@Engineering, 30568, 25000, 202, 325, 0), -- Gnomish Flame Turret
(@Engineering, 30569, 35000, 202, 340, 0), -- Gnomish Poultryizer
(@Engineering, 30575, 100000, 202, 375, 0), -- Gnomish Battle Goggles
(@Engineering, 30570, 50000, 202, 350, 0), -- Nigh-Invulnerability Belt
(@Engineering, 30574, 100000, 202, 375, 0), -- Gnomish Power Goggles
(@Engineering, 56473, 150000, 202, 425, 0), -- Gnomish X-Ray Specs
(@Engineering, 56514, 150000, 202, 425, 0), -- Global Thermal Sapper Charge
(@Engineering, 12895, 1500, 202, 205, 0), -- Inlaid Mithril Cylinder Plans
(@Engineering, 12897, 2200, 202, 215, 0), -- Gnomish Goggles
(@Engineering, 12899, 1500, 202, 205, 0), -- Gnomish Shrink Ray
(@Engineering, 12903, 2000, 202, 215, 0), -- Gnomish Harm Prevention Belt
(@Engineering, 12905, 1500, 202, 210, 0), -- Gnomish Rocket Boots
(@Engineering, 12902, 1800, 202, 210, 0), -- Gnomish Net-o-Matic Projector
(@Engineering, 12715, 1000, 202, 205, 0), -- Goblin Rocket Fuel Recipe
(@Engineering, 8895, 2200, 202, 225, 0), -- Goblin Rocket Boots
(@Engineering, 12717, 1500, 202, 205, 0), -- Goblin Mining Helmet
(@Engineering, 12716, 1500, 202, 205, 0), -- Goblin Mortar
(@Engineering, 12718, 1500, 202, 205, 0), -- Goblin Construction Helmet
(@Engineering, 12760, 1500, 202, 205, 0), -- Goblin Sapper Charge
(@Engineering, 84420, 170000, 202, 490, 0), -- Finely-Tuned Throat Needler
(@Engineering, 84428, 200000, 202, 515, 0), -- Gnomish X-Ray Scope
(@Engineering, 81725, 240000, 202, 525, 0), -- Lightweight Bio-Optic Killshades
(@Engineering, 84421, 170000, 202, 490, 0), -- Loot-a-Rang
(@Engineering, 84429, 200000, 202, 505, 0), -- Goblin Barbecue
(@Engineering, 84406, 150000, 202, 440, 0), -- Authentic Jr. Engineer Goggles
(@Engineering, 84430, 200000, 202, 510, 0), -- Heat-Treated Spinning Lure
(@Engineering, 84415, 170000, 202, 475, 0), -- Lure Master Tackle Box
(@Engineering, 84431, 240000, 202, 525, 0), -- Overpowered Chicken Splitter
(@Engineering, 84408, 150000, 202, 450, 0), -- R19 Threatfinder
(@Engineering, 94748, 150000, 202, 445, 0), -- Electrified Ether
(@Engineering, 95703, 150000, 202, 440, 0), -- Electrostatic Condenser
(@Engineering, 84411, 160000, 202, 465, 0), -- High-Powered Bolt Gun
(@Engineering, 84416, 170000, 202, 475, 0), -- Elementium Toolbox
(@Engineering, 84432, 240000, 202, 525, 0), -- Kickback 5000
(@Engineering, 84409, 160000, 202, 455, 0), -- Volatile Seaforium Blastpack
(@Engineering, 84417, 170000, 202, 495, 0), -- Volatile Thunderstick
(@Engineering, 84410, 150000, 202, 450, 0), -- Safety Catch Removal Kit
(@Engineering, 84418, 170000, 202, 475, 0), -- Elementium Dragonling
(@Engineering, 84403, 150000, 202, 425, 0), -- Handful of Obsidium Bolts
(@Engineering, 82775, 500000, 202, 425, 75), -- Illustrious Grand Master Engineer
-- Herbalism
(@Herbalism, 2372, 10, 0, 0, 0), -- Apprentice Herbalist
(@Herbalism, 2373, 500, 182, 50, 0), -- Journeyman Herbalist
(@Herbalism, 3571, 5000, 182, 125, 10), -- Expert Herbalist
(@Herbalism, 11994, 50000, 182, 200, 25), -- Artisan Herbalist
(@Herbalism, 28696, 100000, 182, 275, 40), -- Master Herbalist
(@Herbalism, 50301, 350000, 182, 350, 55), -- Grand Master Herbalist
(@Herbalism, 74520, 500000, 182, 425, 75), -- Illustrious Grand Master Herbalist
-- Inscription
(@Inscription, 57008, 20000, 773, 315, 0), -- Glyph of Rapid Fire
(@Inscription, 57003, 30000, 773, 350, 0), -- Glyph of Ice Trap
(@Inscription, 56984, 30000, 773, 325, 0), -- Glyph of Mage Armor
(@Inscription, 56972, 30000, 773, 335, 0), -- Glyph of Arcane Power
(@Inscription, 56952, 20000, 773, 310, 0), -- Glyph of Pounce
(@Inscription, 56943, 30000, 773, 350, 0), -- Glyph of Frenzied Regeneration
(@Inscription, 57033, 30000, 773, 335, 0), -- Glyph of Rebuke
(@Inscription, 56991, 20000, 773, 315, 0), -- Glyph of Arcane Blast
(@Inscription, 57187, 20000, 773, 315, 0), -- Glyph of Holy Nova
(@Inscription, 57192, 30000, 773, 350, 0), -- Glyph of Shadow Word: Pain
(@Inscription, 57122, 20000, 773, 305, 0), -- Glyph of Feint
(@Inscription, 57113, 30000, 773, 340, 0), -- Glyph of Ambush
(@Inscription, 57252, 30000, 773, 330, 0), -- Glyph of Windfury Weapon
(@Inscription, 57275, 30000, 773, 325, 0), -- Glyph of Seduction
(@Inscription, 57257, 30000, 773, 350, 0), -- Glyph of Incinerate
(@Inscription, 57714, 20000, 773, 325, 0), -- Darkflame Ink
(@Inscription, 59495, 20000, 773, 325, 0), -- Hellfire Tome
(@Inscription, 59496, 20000, 773, 325, 0), -- Book of Clever Tricks
(@Inscription, 59503, 20000, 773, 325, 0), -- Greater Darkmoon Card
(@Inscription, 58489, 20000, 773, 305, 0), -- Scroll of Strength VI
(@Inscription, 58481, 20000, 773, 310, 0), -- Scroll of Agility VI
(@Inscription, 57226, 20000, 773, 305, 0), -- Glyph of Pillar of Frost
(@Inscription, 59338, 20000, 773, 310, 0), -- Glyph of Rune Tap
(@Inscription, 57168, 20000, 773, 320, 0), -- Glyph of Sweeping Strikes
(@Inscription, 59339, 20000, 773, 320, 0), -- Glyph of Blood Boil
(@Inscription, 57224, 30000, 773, 330, 0), -- Glyph of Scourge Strike
(@Inscription, 59340, 30000, 773, 340, 0), -- Glyph of Death Strike
(@Inscription, 57227, 30000, 773, 345, 0), -- Glyph of Vampiric Blood
(@Inscription, 57172, 30000, 773, 345, 0), -- Glyph of Raging Blow
(@Inscription, 57222, 30000, 773, 350, 0), -- Glyph of Raise Dead
(@Inscription, 94402, 30000, 773, 330, 0), -- Glyph of Lacerate
(@Inscription, 57236, 20000, 773, 300, 0), -- Glyph of Earthliving Weapon
(@Inscription, 57221, 20000, 773, 300, 0), -- Glyph of Pestilence
(@Inscription, 50602, 20000, 773, 300, 0), -- Scroll of Intellect VI
(@Inscription, 45379, 100000, 773, 275, 50), -- Master Scribe
(@Inscription, 57026, 20000, 773, 300, 0), -- Glyph of Word of Glory
(@Inscription, 57713, 20000, 773, 290, 0), -- Ethereal Ink
(@Inscription, 57002, 10000, 773, 260, 0), -- Glyph of Freezing Trap
(@Inscription, 57025, 10000, 773, 265, 0), -- Glyph of Exorcism
(@Inscription, 57024, 6000, 773, 230, 0), -- Glyph of Crusader Strike
(@Inscription, 57183, 6000, 773, 230, 0), -- Glyph of Dispel Magic
(@Inscription, 57132, 6000, 773, 235, 0), -- Glyph of Slice and Dice
(@Inscription, 57244, 6000, 773, 235, 0), -- Glyph of Totemic Recall
(@Inscription, 57274, 7500, 773, 240, 0), -- Glyph of Soulstone
(@Inscription, 56957, 10000, 773, 260, 0), -- Glyph of Bloodletting
(@Inscription, 57185, 10000, 773, 270, 0), -- Glyph of Fear Ward
(@Inscription, 57133, 15000, 773, 285, 0), -- Glyph of Sprint
(@Inscription, 57251, 10000, 773, 275, 0), -- Glyph of Water Shield
(@Inscription, 57272, 10000, 773, 275, 0), -- Glyph of Shadowburn
(@Inscription, 64261, 10000, 773, 250, 0), -- Glyph of Earth Shield
(@Inscription, 64258, 10000, 773, 250, 0), -- Glyph of Monsoon
(@Inscription, 64260, 10000, 773, 255, 0), -- Glyph of Mutilate
(@Inscription, 64259, 10000, 773, 255, 0), -- Glyph of Desperation
(@Inscription, 64262, 10000, 773, 255, 0), -- Glyph of Shamanistic Rage
(@Inscription, 64266, 10000, 773, 275, 0), -- Glyph of Death Coil
(@Inscription, 57154, 7500, 773, 240, 0), -- Glyph of Cleaving
(@Inscription, 59493, 10000, 773, 275, 0), -- Stormbound Tome
(@Inscription, 59494, 10000, 773, 275, 0), -- Manual of Clouds
(@Inscription, 59502, 10000, 773, 275, 0), -- Darkmoon Card
(@Inscription, 50617, 10000, 773, 250, 0), -- Scroll of Stamina V
(@Inscription, 50608, 10000, 773, 255, 0), -- Scroll of Spirit V
(@Inscription, 50601, 10000, 773, 260, 0), -- Scroll of Intellect V
(@Inscription, 58488, 10000, 773, 265, 0), -- Scroll of Strength V
(@Inscription, 58480, 10000, 773, 270, 0), -- Scroll of Agility V
(@Inscription, 57210, 10000, 773, 265, 0), -- Glyph of Bone Shield
(@Inscription, 57216, 10000, 773, 270, 0), -- Glyph of Frost Strike
(@Inscription, 57219, 10000, 773, 280, 0), -- Glyph of Icy Touch
(@Inscription, 57213, 15000, 773, 285, 0), -- Glyph of Death Grip
(@Inscription, 57156, 15000, 773, 285, 0), -- Glyph of Bloodthirst
(@Inscription, 50618, 20000, 773, 290, 0), -- Scroll of Stamina VI
(@Inscription, 50609, 20000, 773, 295, 0), -- Scroll of Spirit VI
(@Inscription, 94406, 10000, 773, 250, 0), -- Glyph of Intercept
(@Inscription, 57711, 10000, 773, 250, 0), -- Shimmering Ink
(@Inscription, 57712, 10000, 773, 275, 0), -- Ink of the Sky
(@Inscription, 45378, 50000, 773, 200, 35), -- Artisan Scribe
(@Inscription, 96284, 10000, 773, 275, 0), -- Glyph of Dark Succor
(@Inscription, 59487, 750, 773, 175, 0), -- Arcane Tarot
(@Inscription, 59491, 6000, 773, 225, 0), -- Shadowy Tarot
(@Inscription, 59484, 750, 773, 175, 0), -- Tome of Kings
(@Inscription, 59486, 750, 773, 175, 0), -- Royal Guide of Escape Routes
(@Inscription, 50614, 750, 773, 155, 0), -- Scroll of Stamina III
(@Inscription, 50606, 750, 773, 160, 0), -- Scroll of Spirit III
(@Inscription, 50599, 750, 773, 165, 0), -- Scroll of Intellect III
(@Inscription, 58486, 750, 773, 170, 0), -- Scroll of Strength III
(@Inscription, 58476, 750, 773, 175, 0), -- Scroll of Agility III
(@Inscription, 56974, 750, 773, 155, 0), -- Glyph of Evocation
(@Inscription, 57197, 750, 773, 160, 0), -- Glyph of Renew
(@Inscription, 57125, 750, 773, 160, 0), -- Glyph of Gouge
(@Inscription, 57249, 750, 773, 165, 0), -- Glyph of Lava Lash
(@Inscription, 57271, 750, 773, 165, 0), -- Glyph of Shadow Bolt
(@Inscription, 57161, 1000, 773, 170, 0), -- Glyph of Overpower
(@Inscription, 56953, 1000, 773, 170, 0), -- Glyph of Rebirth
(@Inscription, 56994, 1000, 773, 175, 0), -- Glyph of Aimed Shot
(@Inscription, 56981, 1000, 773, 175, 0), -- Glyph of Icy Veins
(@Inscription, 57020, 1000, 773, 180, 0), -- Glyph of Cleansing
(@Inscription, 57200, 1000, 773, 180, 0), -- Glyph of Mind Flay
(@Inscription, 57129, 3000, 773, 185, 0), -- Glyph of Sap
(@Inscription, 57241, 3000, 773, 185, 0), -- Glyph of Frost Shock
(@Inscription, 57277, 3000, 773, 190, 0), -- Glyph of Voidwalker
(@Inscription, 57165, 3000, 773, 190, 0), -- Glyph of Revenge
(@Inscription, 59387, 3000, 773, 200, 0), -- Certificate of Ownership
(@Inscription, 60336, 3000, 773, 200, 0), -- Scroll of Recall II
(@Inscription, 59489, 6000, 773, 225, 0), -- Fire Eater's Guide
(@Inscription, 56956, 3000, 773, 200, 0), -- Glyph of Rip
(@Inscription, 57000, 3000, 773, 200, 0), -- Glyph of Deterrence
(@Inscription, 57023, 4500, 773, 205, 0), -- Glyph of Consecration
(@Inscription, 57201, 4500, 773, 210, 0), -- Glyph of Smite
(@Inscription, 57131, 4500, 773, 210, 0), -- Glyph of Sinister Strike
(@Inscription, 57242, 4500, 773, 215, 0), -- Glyph of Healing Stream Totem
(@Inscription, 57270, 4500, 773, 215, 0), -- Glyph of Soul Swap
(@Inscription, 56959, 4500, 773, 220, 0), -- Glyph of Starfire
(@Inscription, 57001, 6000, 773, 225, 0), -- Glyph of Disengage
(@Inscription, 56979, 6000, 773, 225, 0), -- Glyph of Ice Block
(@Inscription, 59490, 6000, 773, 225, 0), -- Book of Stars
(@Inscription, 50616, 4500, 773, 205, 0), -- Scroll of Stamina IV
(@Inscription, 50607, 4500, 773, 210, 0), -- Scroll of Spirit IV
(@Inscription, 50600, 4500, 773, 215, 0), -- Scroll of Intellect IV
(@Inscription, 58487, 4500, 773, 220, 0), -- Scroll of Strength IV
(@Inscription, 58478, 4500, 773, 225, 0), -- Scroll of Agility IV
(@Inscription, 57708, 750, 773, 175, 0), -- Royal Ink
(@Inscription, 57709, 3000, 773, 200, 0), -- Celestial Ink
(@Inscription, 57710, 6000, 773, 225, 0), -- Fiery Ink
(@Inscription, 45377, 5000, 773, 125, 20), -- Expert Scribe
(@Inscription, 92579, 1000, 773, 180, 0), -- Glyph of Blind
(@Inscription, 59480, 750, 773, 125, 0), -- Strange Tarot
(@Inscription, 57245, 750, 773, 140, 0), -- Glyph of Lightning Bolt
(@Inscription, 57269, 750, 773, 140, 0), -- Glyph of Imp
(@Inscription, 57167, 750, 773, 140, 0), -- Glyph of Sunder Armor
(@Inscription, 56948, 750, 773, 150, 0), -- Glyph of Insect Swarm
(@Inscription, 57007, 750, 773, 150, 0), -- Glyph of Silencing Shot
(@Inscription, 58344, 300, 773, 80, 0), -- Glyph of Long Charge
(@Inscription, 58346, 300, 773, 80, 0), -- Glyph of Thunder Clap
(@Inscription, 67600, 400, 773, 100, 0), -- Glyph of Ferocious Bite
(@Inscription, 59326, 400, 773, 100, 0), -- Glyph of Ghost Wolf
(@Inscription, 57703, 400, 773, 85, 0), -- Hunter's Ink
(@Inscription, 57704, 400, 773, 100, 0), -- Lion's Ink
(@Inscription, 57706, 750, 773, 125, 0), -- Dawnstar Ink
(@Inscription, 57707, 750, 773, 150, 0), -- Jadefire Ink
(@Inscription, 58485, 400, 773, 80, 0), -- Scroll of Strength II
(@Inscription, 58473, 400, 773, 85, 0), -- Scroll of Agility II
(@Inscription, 48247, 500, 773, 85, 0), -- Mysterious Tarot
(@Inscription, 56955, 300, 773, 80, 0), -- Glyph of Rejuvenation
(@Inscription, 57004, 300, 773, 80, 0), -- Glyph of Misdirection
(@Inscription, 56976, 300, 773, 80, 0), -- Glyph of Frost Nova
(@Inscription, 57022, 300, 773, 80, 0), -- Glyph of Divine Protection
(@Inscription, 57194, 300, 773, 80, 0), -- Glyph of Power Word: Shield
(@Inscription, 57114, 300, 773, 80, 0), -- Glyph of Backstab
(@Inscription, 57239, 300, 773, 85, 0), -- Glyph of Flame Shock
(@Inscription, 57259, 300, 773, 85, 0), -- Glyph of Corruption
(@Inscription, 57162, 300, 773, 85, 0), -- Glyph of Rapid Charge
(@Inscription, 56963, 300, 773, 85, 0), -- Glyph of Wrath
(@Inscription, 56961, 400, 773, 90, 0), -- Glyph of Maul
(@Inscription, 57009, 400, 773, 90, 0), -- Glyph of Serpent Sting
(@Inscription, 56978, 400, 773, 90, 0), -- Glyph of Pyroblast
(@Inscription, 57027, 400, 773, 90, 0), -- Glyph of Hammer of Justice
(@Inscription, 57196, 400, 773, 95, 0), -- Glyph of Psychic Scream
(@Inscription, 57119, 400, 773, 95, 0), -- Glyph of Evasion
(@Inscription, 57246, 400, 773, 95, 0), -- Glyph of Lightning Shield
(@Inscription, 57266, 400, 773, 95, 0), -- Glyph of Healthstone
(@Inscription, 57158, 400, 773, 95, 0), -- Glyph of Heroic Throw
(@Inscription, 59475, 750, 773, 125, 0), -- Tome of the Dawn
(@Inscription, 59478, 750, 773, 125, 0), -- Book of Survival
(@Inscription, 48121, 400, 773, 100, 0), -- Glyph of Entangling Roots
(@Inscription, 56995, 400, 773, 100, 0), -- Glyph of Arcane Shot
(@Inscription, 57029, 500, 773, 105, 0), -- Glyph of Divine Favor
(@Inscription, 57184, 500, 773, 105, 0), -- Glyph of Fade
(@Inscription, 57120, 500, 773, 105, 0), -- Glyph of Eviscerate
(@Inscription, 57238, 500, 773, 110, 0), -- Glyph of Fire Nova
(@Inscription, 57265, 500, 773, 110, 0), -- Glyph of Health Funnel
(@Inscription, 57163, 500, 773, 110, 0), -- Glyph of Slam
(@Inscription, 56945, 500, 773, 115, 0), -- Glyph of Healing Touch
(@Inscription, 56997, 500, 773, 115, 0), -- Glyph of Mending
(@Inscription, 56971, 500, 773, 115, 0), -- Glyph of Arcane Missiles
(@Inscription, 57030, 500, 773, 120, 0), -- Glyph of Judgement
(@Inscription, 57186, 500, 773, 120, 0), -- Glyph of Flash Heal
(@Inscription, 57121, 500, 773, 120, 0), -- Glyph of Expose Armor
(@Inscription, 57240, 750, 773, 125, 0), -- Glyph of Flametongue Weapon
(@Inscription, 57262, 750, 773, 125, 0), -- Glyph of Fear
(@Inscription, 57157, 750, 773, 125, 0), -- Glyph of Piercing Howl
(@Inscription, 56951, 750, 773, 130, 0), -- Glyph of Moonfire
(@Inscription, 57005, 750, 773, 130, 0), -- Glyph of Immolation Trap
(@Inscription, 56973, 750, 773, 130, 0), -- Glyph of Blink
(@Inscription, 57031, 750, 773, 135, 0), -- Glyph of Divinity
(@Inscription, 57188, 750, 773, 135, 0), -- Glyph of Inner Fire
(@Inscription, 57123, 750, 773, 135, 0), -- Glyph of Garrote
(@Inscription, 45376, 500, 773, 50, 10), -- Journeyman Scribe
(@Inscription, 94403, 500, 773, 120, 0), -- Glyph of Faerie Fire
(@Inscription, 94401, 500, 773, 120, 0), -- Glyph of Tiger's Fury
(@Inscription, 94404, 750, 773, 150, 0), -- Glyph of Feral Charge
(@Inscription, 94405, 750, 773, 150, 0), -- Glyph of Death Wish
(@Inscription, 58565, 500, 773, 85, 0), -- Mystic Tome
(@Inscription, 92026, 400, 773, 75, 0), -- Vanishing Powder
(@Inscription, 45375, 10, 0, 0, 5), -- Apprentice Scribe
(@Inscription, 61288, 1000, 773, 75, 0), -- Minor Inscription Research
(@Inscription, 53462, 300, 773, 75, 0), -- Midnight Ink
(@Inscription, 48248, 50, 773, 35, 0), -- Scroll of Recall
(@Inscription, 52843, 50, 773, 35, 0), -- Moonglow Ink
(@Inscription, 52739, 150, 773, 35, 0), -- Enchanting Vellum
(@Inscription, 50612, 400, 773, 75, 0), -- Scroll of Stamina II
(@Inscription, 50605, 400, 773, 75, 0), -- Scroll of Spirit II
(@Inscription, 50598, 400, 773, 75, 0), -- Scroll of Intellect II
(@Inscription, 58472, 50, 773, 15, 0), -- Scroll of Agility
(@Inscription, 58484, 50, 773, 15, 0), -- Scroll of Strength
(@Inscription, 57248, 50000, 773, 375, 0), -- Glyph of Stormstrike
(@Inscription, 50610, 50000, 773, 355, 0), -- Scroll of Spirit VII
(@Inscription, 58482, 50000, 773, 370, 0), -- Scroll of Agility VII
(@Inscription, 58490, 50000, 773, 365, 0), -- Scroll of Strength VII
(@Inscription, 50603, 50000, 773, 360, 0), -- Scroll of Intellect VII
(@Inscription, 50619, 50000, 773, 350, 0), -- Scroll of Stamina VII
(@Inscription, 57715, 50000, 773, 350, 0), -- Ink of the Sea
(@Inscription, 61177, 100000, 773, 385, 0), -- Northrend Inscription Research
(@Inscription, 50620, 60000, 773, 400, 0), -- Scroll of Stamina VIII
(@Inscription, 50611, 60000, 773, 405, 0), -- Scroll of Spirit VIII
(@Inscription, 50604, 60000, 773, 410, 0), -- Scroll of Intellect VIII
(@Inscription, 58491, 60000, 773, 415, 0), -- Scroll of Strength VIII
(@Inscription, 58483, 60000, 773, 420, 0), -- Scroll of Agility VIII
(@Inscription, 57198, 50000, 773, 375, 0), -- Glyph of Scourge Imprisonment
(@Inscription, 62162, 50000, 773, 375, 0), -- Glyph of Focus
(@Inscription, 56980, 50000, 773, 375, 0), -- Glyph of Ice Lance
(@Inscription, 57225, 50000, 773, 375, 0), -- Glyph of Strangulate
(@Inscription, 57036, 50000, 773, 375, 0), -- Glyph of Turn Evil
(@Inscription, 57716, 50000, 773, 375, 0), -- Snowfall Ink
(@Inscription, 61117, 75000, 773, 400, 0), -- Master's Inscription of the Axe
(@Inscription, 61119, 75000, 773, 400, 0), -- Master's Inscription of the Pinnacle
(@Inscription, 61120, 75000, 773, 400, 0), -- Master's Inscription of the Storm
(@Inscription, 61118, 75000, 773, 400, 0), -- Master's Inscription of the Crag
(@Inscription, 64053, 50000, 773, 350, 0), -- Twilight Tome
(@Inscription, 57006, 50000, 773, 375, 0), -- Glyph of the Dazzled Prey
(@Inscription, 56987, 60000, 773, 400, 0), -- Glyph of Polymorph
(@Inscription, 69385, 120000, 773, 440, 0), -- Runescroll of Fortitude
(@Inscription, 59497, 60000, 773, 400, 0), -- Iron-bound Tome
(@Inscription, 59498, 60000, 773, 400, 0), -- Faces of Doom
(@Inscription, 59504, 60000, 773, 400, 0), -- Darkmoon Card of the North
(@Inscription, 60337, 50000, 773, 350, 0), -- Scroll of Recall III
(@Inscription, 45380, 350000, 773, 350, 65), -- Grand Master Scribe
(@Inscription, 92027, 90000, 773, 475, 0), -- Dust of Disappearance
(@Inscription, 86616, 90000, 773, 475, 0), -- Book of Blood
(@Inscription, 86640, 90000, 773, 475, 0), -- Lord Rottington's Pressed Wisp Book
(@Inscription, 86648, 90000, 773, 480, 0), -- Manual of the Planes
(@Inscription, 89368, 80000, 773, 445, 0), -- Scroll of Intellect IX
(@Inscription, 85785, 120000, 773, 500, 0), -- Runescroll of Fortitude II
(@Inscription, 86401, 75000, 773, 500, 0), -- Lionsmane Inscription
(@Inscription, 86609, 80000, 773, 450, 0), -- Mysterious Fortune Card
(@Inscription, 86641, 120000, 773, 510, 0), -- Dungeoneering Guide
(@Inscription, 86649, 120000, 773, 505, 0), -- Runed Dragonscale
(@Inscription, 89369, 80000, 773, 465, 0), -- Scroll of Strength IX
(@Inscription, 86402, 75000, 773, 500, 0), -- Inscription of the Earth Prince
(@Inscription, 86642, 120000, 773, 510, 0), -- Divine Companion
(@Inscription, 86650, 150000, 773, 515, 0), -- Notched Jawbone
(@Inscription, 89370, 80000, 773, 470, 0), -- Scroll of Agility IX
(@Inscription, 86403, 75000, 773, 500, 0), -- Felfire Inscription
(@Inscription, 86643, 120000, 773, 510, 0), -- Battle Tome
(@Inscription, 89371, 80000, 773, 455, 0), -- Scroll of Spirit IX
(@Inscription, 86652, 150000, 773, 515, 0), -- Tattooed Eyeball
(@Inscription, 89244, 100000, 773, 500, 0), -- Forged Documents
(@Inscription, 89372, 80000, 773, 460, 0), -- Scroll of Stamina IX
(@Inscription, 86653, 150000, 773, 515, 0), -- Silver Inlaid Leaf
(@Inscription, 89373, 80000, 773, 450, 0), -- Scroll of Protection IX
(@Inscription, 86375, 75000, 773, 500, 0), -- Swiftsteel Inscription
(@Inscription, 86615, 200000, 773, 525, 0), -- Darkmoon Card of Destruction
(@Inscription, 86647, 90000, 773, 480, 0), -- Etched Horn
(@Inscription, 89367, 80000, 773, 460, 0), -- Adventurer's Journal
(@Inscription, 86004, 80000, 773, 425, 0), -- Blackfallow Ink
(@Inscription, 86005, 90000, 773, 475, 0), -- Inferno Ink
(@Inscription, 86009, 500000, 773, 425, 75), -- Illustrious Grand Master Scribe
(@Inscription, 99547, 120000, 773, 510, 0), -- Vicious Charm of Triumph
(@Inscription, 99548, 120000, 773, 510, 0), -- Vicious Eyeball of Dominance
(@Inscription, 99549, 120000, 773, 510, 0), -- Vicious Jawbone of Conquest
-- Jewelcrafting
(@Jewelcrafting, 51310, 350000, 755, 350, 65), -- Grand Master Jewelcrafter
(@Jewelcrafting, 53892, 10000, 755, 350, 0), -- Accurate Shadow Crystal
(@Jewelcrafting, 53831, 10000, 755, 350, 0), -- Bold Bloodstone
(@Jewelcrafting, 53872, 10000, 755, 350, 0), -- Inscribed Huge Citrine
(@Jewelcrafting, 56208, 10000, 755, 350, 0), -- Shadow Jade Focusing Lens
(@Jewelcrafting, 53922, 10000, 755, 350, 0), -- Misty Dark Jade
(@Jewelcrafting, 56194, 10000, 755, 350, 0), -- Sun Rock Ring
(@Jewelcrafting, 53844, 10000, 755, 350, 0), -- Flashing Bloodstone
(@Jewelcrafting, 53876, 10000, 755, 350, 0), -- Fierce Huge Citrine
(@Jewelcrafting, 58141, 30000, 755, 350, 0), -- Crystal Citrine Necklace
(@Jewelcrafting, 53894, 10000, 755, 350, 0), -- Timeless Shadow Crystal
(@Jewelcrafting, 62242, 150000, 755, 425, 0), -- Icy Prism
(@Jewelcrafting, 53871, 10000, 755, 350, 0), -- Guardian's Shadow Crystal
(@Jewelcrafting, 58143, 30000, 755, 350, 0), -- Earthshadow Ring
(@Jewelcrafting, 53832, 10000, 755, 350, 0), -- Delicate Bloodstone
(@Jewelcrafting, 53873, 10000, 755, 350, 0), -- Etched Shadow Crystal
(@Jewelcrafting, 54017, 10000, 755, 350, 0), -- Precise Bloodstone
(@Jewelcrafting, 56531, 100000, 755, 390, 0), -- Enchanted Tear
(@Jewelcrafting, 56193, 10000, 755, 350, 0), -- Bloodstone Band
(@Jewelcrafting, 53882, 10000, 755, 350, 0), -- Potent Huge Citrine
(@Jewelcrafting, 53843, 10000, 755, 350, 0), -- Subtle Sun Crystal
(@Jewelcrafting, 53859, 10000, 755, 350, 0), -- Sovereign Shadow Crystal
(@Jewelcrafting, 53891, 10000, 755, 350, 0), -- Stalwart Huge Citrine
(@Jewelcrafting, 53923, 10000, 755, 350, 0), -- Lightning Dark Jade
(@Jewelcrafting, 53852, 10000, 755, 350, 0), -- Brilliant Bloodstone
(@Jewelcrafting, 53845, 10000, 755, 350, 0), -- Smooth Sun Crystal
(@Jewelcrafting, 53861, 10000, 755, 350, 0), -- Glinting Shadow Crystal
(@Jewelcrafting, 53893, 10000, 755, 350, 0), -- Resolute Huge Citrine
(@Jewelcrafting, 53925, 10000, 755, 350, 0), -- Energized Dark Jade
(@Jewelcrafting, 53941, 10000, 755, 350, 0), -- Sparkling Chalcedony
(@Jewelcrafting, 53854, 10000, 755, 350, 0), -- Rigid Chalcedony
(@Jewelcrafting, 53870, 10000, 755, 350, 0), -- Jagged Dark Jade
(@Jewelcrafting, 53918, 10000, 755, 350, 0), -- Regal Dark Jade
(@Jewelcrafting, 53934, 10000, 755, 350, 0), -- Solid Chalcedony
(@Jewelcrafting, 56206, 10000, 755, 350, 0), -- Shadow Crystal Focusing Lens
(@Jewelcrafting, 64725, 100000, 755, 420, 0), -- Emerald Choker
(@Jewelcrafting, 64726, 100000, 755, 420, 0), -- Sky Sapphire Amulet
(@Jewelcrafting, 64728, 100000, 755, 420, 0), -- Scarlet Signet
(@Jewelcrafting, 64727, 100000, 755, 420, 0), -- Runed Mana Band
(@Jewelcrafting, 58145, 50000, 755, 390, 0), -- Stoneguard Band
(@Jewelcrafting, 58146, 50000, 755, 390, 0), -- Shadowmight Ring
(@Jewelcrafting, 58142, 30000, 755, 350, 0), -- Crystal Chalcedony Amulet
(@Jewelcrafting, 53856, 10000, 755, 350, 0), -- Quick Sun Crystal
(@Jewelcrafting, 53920, 10000, 755, 350, 0), -- Forceful Dark Jade
(@Jewelcrafting, 58144, 30000, 755, 350, 0), -- Jade Ring of Slaying
(@Jewelcrafting, 53874, 10000, 755, 350, 0), -- Champion's Huge Citrine
(@Jewelcrafting, 56530, 10000, 755, 350, 0), -- Enchanted Pearl
(@Jewelcrafting, 53883, 10000, 755, 350, 0), -- Veiled Shadow Crystal
(@Jewelcrafting, 53860, 10000, 755, 350, 0), -- Shifting Shadow Crystal
(@Jewelcrafting, 56205, 10000, 755, 350, 0), -- Dark Jade Focusing Lens
(@Jewelcrafting, 55394, 120000, 755, 420, 0), -- Swift Skyflare Diamond
(@Jewelcrafting, 55386, 120000, 755, 420, 0), -- Tireless Skyflare Diamond
(@Jewelcrafting, 55402, 120000, 755, 420, 0), -- Persistent Earthsiege Diamond
(@Jewelcrafting, 55399, 120000, 755, 420, 0), -- Powerful Earthsiege Diamond
(@Jewelcrafting, 59759, 150000, 755, 400, 0), -- Figurine - Monarch Crab
(@Jewelcrafting, 56195, 120000, 755, 380, 0), -- Jade Dagger Pendant
(@Jewelcrafting, 56196, 80000, 755, 380, 0), -- Blood Sun Necklace
(@Jewelcrafting, 56197, 100000, 755, 420, 0), -- Dream Signet
(@Jewelcrafting, 56199, 150000, 755, 400, 0), -- Figurine - Ruby Hare
(@Jewelcrafting, 56201, 150000, 755, 400, 0), -- Figurine - Twilight Serpent
(@Jewelcrafting, 56202, 150000, 755, 400, 0), -- Figurine - Sapphire Owl
(@Jewelcrafting, 56203, 150000, 755, 400, 0), -- Figurine - Emerald Boar
(@Jewelcrafting, 53880, 10000, 755, 350, 0), -- Deft Huge Citrine
(@Jewelcrafting, 73495, 30000, 755, 450, 0), -- Hessonite Band
(@Jewelcrafting, 73497, 30000, 755, 460, 0), -- Nightstone Choker
(@Jewelcrafting, 73621, 30000, 755, 490, 0), -- The Perforator
(@Jewelcrafting, 73478, 30000, 755, 500, 0), -- Fire Prism
(@Jewelcrafting, 73494, 30000, 755, 425, 0), -- Jasper Ring
(@Jewelcrafting, 73496, 30000, 755, 435, 0), -- Alicite Pendant
(@Jewelcrafting, 73620, 30000, 755, 460, 0), -- Carnelian Spikes
(@Jewelcrafting, 73319, 500000, 755, 425, 75), -- Illustrious Grand Master Jewelcrafter
(@Jewelcrafting, 73266, 30000, 755, 425, 0), -- Reckless Hessonite
(@Jewelcrafting, 99539, 40000, 755, 510, 0), -- Vicious Sapphire Ring
(@Jewelcrafting, 99540, 40000, 755, 510, 0), -- Vicious Amberjewel Band
(@Jewelcrafting, 99541, 40000, 755, 510, 0), -- Vicious Ruby Signet
(@Jewelcrafting, 99542, 45000, 755, 520, 0), -- Vicious Sapphire Necklace
(@Jewelcrafting, 99543, 45000, 755, 520, 0), -- Vicious Amberjewel Pendant
(@Jewelcrafting, 99544, 45000, 755, 520, 0), -- Vicious Ruby Choker
(@Jewelcrafting, 73622, 30000, 755, 435, 0), -- Stardust
(@Jewelcrafting, 73223, 30000, 755, 425, 0), -- Delicate Carnelian
(@Jewelcrafting, 73227, 30000, 755, 425, 0), -- Solid Zephyrite
(@Jewelcrafting, 73228, 30000, 755, 425, 0), -- Sparkling Zephyrite
(@Jewelcrafting, 73232, 30000, 755, 425, 0), -- Smooth Alicite
(@Jewelcrafting, 73225, 30000, 755, 425, 0), -- Brilliant Carnelian
(@Jewelcrafting, 73222, 30000, 755, 425, 0), -- Bold Carnelian
(@Jewelcrafting, 73226, 30000, 755, 425, 0), -- Precise Carnelian
(@Jewelcrafting, 73230, 30000, 755, 425, 0), -- Rigid Zephyrite
(@Jewelcrafting, 73239, 30000, 755, 425, 0), -- Fractured Alicite
(@Jewelcrafting, 73247, 30000, 755, 425, 0), -- Glinting Nightstone
(@Jewelcrafting, 73279, 30000, 755, 425, 0), -- Puissant Jasper
(@Jewelcrafting, 73240, 30000, 755, 425, 0), -- Sovereign Nightstone
(@Jewelcrafting, 73241, 30000, 755, 425, 0), -- Shifting Nightstone
(@Jewelcrafting, 73249, 30000, 755, 425, 0), -- Veiled Nightstone
(@Jewelcrafting, 73281, 30000, 755, 425, 0), -- Sensei's Jasper
(@Jewelcrafting, 73234, 30000, 755, 425, 0), -- Quick Alicite
(@Jewelcrafting, 73250, 30000, 755, 425, 0), -- Accurate Nightstone
(@Jewelcrafting, 73274, 30000, 755, 425, 0), -- Jagged Jasper
(@Jewelcrafting, 73243, 30000, 755, 425, 0), -- Timeless Nightstone
(@Jewelcrafting, 73267, 30000, 755, 425, 0), -- Skillful Hessonite
(@Jewelcrafting, 73268, 30000, 755, 425, 0), -- Adept Hessonite
(@Jewelcrafting, 73246, 30000, 755, 425, 0), -- Etched Nightstone
(@Jewelcrafting, 73270, 30000, 755, 425, 0), -- Artful Hessonite
(@Jewelcrafting, 28901, 100000, 755, 275, 50), -- Master Jewelcrafter
(@Jewelcrafting, 28953, 10000, 755, 300, 0), -- Sparkling Azure Moonstone
(@Jewelcrafting, 41418, 30000, 755, 365, 0), -- Crown of the Sea Witch
(@Jewelcrafting, 47280, 30000, 755, 350, 0), -- Brilliant Glass
(@Jewelcrafting, 41414, 10000, 755, 325, 0), -- Brilliant Pearl Band
(@Jewelcrafting, 41415, 10000, 755, 330, 0), -- The Black Pearl
(@Jewelcrafting, 40514, 8500, 755, 340, 0), -- Necklace of the Deep
(@Jewelcrafting, 26916, 20000, 755, 310, 0), -- Band of Natural Fire
(@Jewelcrafting, 31048, 20000, 755, 305, 0), -- Fel Iron Blood Ring
(@Jewelcrafting, 31049, 20000, 755, 305, 0), -- Golden Draenite Ring
(@Jewelcrafting, 31050, 25000, 755, 320, 0), -- Azure Moonstone Ring
(@Jewelcrafting, 31051, 30000, 755, 335, 0), -- Thick Adamantite Necklace
(@Jewelcrafting, 31052, 30000, 755, 335, 0), -- Heavy Adamantite Ring
(@Jewelcrafting, 38068, 20000, 755, 325, 0), -- Mercurial Adamantite
(@Jewelcrafting, 41420, 8500, 755, 325, 0), -- Purified Jaggal Pearl
(@Jewelcrafting, 41429, 10000, 755, 350, 0), -- Purified Shadow Pearl
(@Jewelcrafting, 28916, 10000, 755, 300, 0), -- Radiant Deep Peridot
(@Jewelcrafting, 28950, 10000, 755, 300, 0), -- Solid Azure Moonstone
(@Jewelcrafting, 28925, 10000, 755, 300, 0), -- Timeless Shadow Draenite
(@Jewelcrafting, 28910, 10000, 755, 300, 0), -- Inscribed Flame Spessarite
(@Jewelcrafting, 34590, 10000, 755, 300, 0), -- Delicate Blood Garnet
(@Jewelcrafting, 28905, 10000, 755, 300, 0), -- Bold Blood Garnet
(@Jewelcrafting, 28914, 10000, 755, 315, 0), -- Glinting Shadow Draenite
(@Jewelcrafting, 28917, 10000, 755, 300, 0), -- Jagged Deep Peridot
(@Jewelcrafting, 28936, 10000, 755, 325, 0), -- Sovereign Shadow Draenite
(@Jewelcrafting, 28948, 10000, 755, 325, 0), -- Rigid Azure Moonstone
(@Jewelcrafting, 28899, 50000, 755, 200, 35), -- Artisan Jewelcrafter
(@Jewelcrafting, 36525, 4000, 755, 230, 0), -- Red Ring of Destruction
(@Jewelcrafting, 36526, 10000, 755, 265, 0), -- Diamond Focus Ring
(@Jewelcrafting, 34960, 10000, 755, 280, 0), -- Glowing Thorium Band
(@Jewelcrafting, 34961, 10000, 755, 290, 0), -- Emerald Lion Ring
(@Jewelcrafting, 62941, 10000, 755, 300, 0), -- Prismatic Black Diamond
(@Jewelcrafting, 26883, 4000, 755, 235, 0), -- Ruby Pendant of Fire
(@Jewelcrafting, 26885, 5000, 755, 240, 0), -- Truesilver Healing Ring
(@Jewelcrafting, 26902, 10000, 755, 260, 0), -- Simple Opal Ring
(@Jewelcrafting, 26903, 10000, 755, 275, 0), -- Sapphire Signet
(@Jewelcrafting, 26907, 10000, 755, 280, 0), -- Onslaught Ring
(@Jewelcrafting, 26908, 12000, 755, 280, 0), -- Sapphire Pendant of Winter Night
(@Jewelcrafting, 26911, 15000, 755, 290, 0), -- Living Emerald Pendant
(@Jewelcrafting, 28896, 5000, 755, 125, 20), -- Expert Jewelcrafter
(@Jewelcrafting, 32808, 2000, 755, 175, 0), -- Solid Stone Statue
(@Jewelcrafting, 32809, 3500, 755, 225, 0), -- Dense Stone Statue
(@Jewelcrafting, 25620, 2000, 755, 170, 0), -- Engraved Truesilver Ring
(@Jewelcrafting, 25621, 2000, 755, 180, 0), -- Citrine Ring of Rapid Healing
(@Jewelcrafting, 26872, 2500, 755, 200, 0), -- Figurine - Jade Owl
(@Jewelcrafting, 26874, 5000, 755, 210, 0), -- Aquamarine Signet
(@Jewelcrafting, 26876, 3000, 755, 220, 0), -- Aquamarine Pendant of the Warrior
(@Jewelcrafting, 26880, 3500, 755, 225, 0), -- Thorium Setting
(@Jewelcrafting, 34955, 2500, 755, 180, 0), -- Golden Ring of Power
(@Jewelcrafting, 34959, 3000, 755, 200, 0), -- Truesilver Commander's Ring
(@Jewelcrafting, 63743, 3000, 755, 200, 0), -- Amulet of Truesight
(@Jewelcrafting, 25246, 500, 755, 50, 10), -- Journeyman Jewelcrafter
(@Jewelcrafting, 32807, 600, 755, 110, 0), -- Heavy Stone Statue
(@Jewelcrafting, 25305, 1000, 755, 90, 0), -- Heavy Silver Ring
(@Jewelcrafting, 25317, 600, 755, 80, 0), -- Ring of Silver Might
(@Jewelcrafting, 25318, 800, 755, 100, 0), -- Ring of Twilight Shadows
(@Jewelcrafting, 25321, 1500, 755, 120, 0), -- Moonsoul Crown
(@Jewelcrafting, 25498, 600, 755, 110, 0), -- Barbaric Iron Collar
(@Jewelcrafting, 25613, 1200, 755, 135, 0), -- Golden Dragon Ring
(@Jewelcrafting, 25615, 1500, 755, 150, 0), -- Mithril Filigree
(@Jewelcrafting, 36524, 800, 755, 105, 0), -- Heavy Jade Ring
(@Jewelcrafting, 25610, 1500, 755, 120, 0), -- Pendant of the Agate Shield
(@Jewelcrafting, 25612, 1500, 755, 125, 0), -- Heavy Iron Knuckles
(@Jewelcrafting, 25617, 1500, 755, 150, 0), -- Blazing Citrine Ring
(@Jewelcrafting, 38175, 650, 755, 80, 0), -- Bronze Torc
(@Jewelcrafting, 32801, 200, 755, 50, 0), -- Coarse Stone Statue
(@Jewelcrafting, 25245, 10, 0, 0, 5), -- Apprentice Jewelcrafter
(@Jewelcrafting, 25283, 100, 755, 30, 0), -- Inlaid Malachite Ring
(@Jewelcrafting, 25284, 400, 755, 60, 0), -- Simple Pearl Ring
(@Jewelcrafting, 25287, 400, 755, 70, 0), -- Gloom Band
(@Jewelcrafting, 25490, 300, 755, 50, 0), -- Solid Bronze Ring
(@Jewelcrafting, 25278, 200, 755, 50, 0), -- Bronze Setting
(@Jewelcrafting, 25280, 200, 755, 50, 0), -- Elegant Silver Ring
(@Jewelcrafting, 26926, 50, 755, 5, 0), -- Heavy Copper Ring
(@Jewelcrafting, 26927, 300, 755, 50, 0), -- Thick Bronze Necklace
(@Jewelcrafting, 26928, 100, 755, 30, 0), -- Ornate Tigerseye Necklace
(@Jewelcrafting, 36523, 600, 755, 75, 0), -- Brilliant Necklace
(@Jewelcrafting, 37818, 500, 755, 65, 0), -- Bronze Band of Force
(@Jewelcrafting, 31252, 100, 755, 20, 5), -- Prospecting
(@Jewelcrafting, 32179, 100, 755, 20, 0), -- Tigerseye Band
(@Jewelcrafting, 32178, 100, 755, 20, 0), -- Malachite Pendant
-- Leatherworking
(@Leatherworking, 36077, 40000, 165, 330, 0), -- Primalstorm Breastplate
(@Leatherworking, 32550, 100000, 165, 275, 50), -- Master Leatherworker
(@Leatherworking, 32455, 20000, 165, 325, 0), -- Heavy Knothide Leather
(@Leatherworking, 32471, 18000, 165, 315, 0), -- Thick Draenic Pants
(@Leatherworking, 32464, 20000, 165, 320, 0), -- Felscale Pants
(@Leatherworking, 32480, 20000, 165, 320, 0), -- Wild Draenish Leggings
(@Leatherworking, 32473, 25000, 165, 330, 0), -- Thick Draenic Vest
(@Leatherworking, 32466, 15000, 165, 300, 0), -- Scaled Draenic Pants
(@Leatherworking, 44770, 50000, 165, 350, 0), -- Glove Reinforcements
(@Leatherworking, 32467, 18000, 165, 310, 0), -- Scaled Draenic Gloves
(@Leatherworking, 32468, 20000, 165, 325, 0), -- Scaled Draenic Vest
(@Leatherworking, 35540, 20000, 165, 340, 0), -- Drums of War
(@Leatherworking, 45100, 15000, 165, 300, 0), -- Leatherworker's Satchel
(@Leatherworking, 32469, 25000, 165, 335, 0), -- Scaled Draenic Boots
(@Leatherworking, 32454, 10000, 165, 300, 0), -- Knothide Leather
(@Leatherworking, 32462, 15000, 165, 300, 0), -- Felscale Gloves
(@Leatherworking, 32470, 15000, 165, 300, 0), -- Thick Draenic Gloves
(@Leatherworking, 32478, 15000, 165, 300, 0), -- Wild Draenish Boots
(@Leatherworking, 36078, 40000, 165, 330, 0), -- Living Crystal Breastplate
(@Leatherworking, 32463, 18000, 165, 310, 0), -- Felscale Boots
(@Leatherworking, 32479, 18000, 165, 310, 0), -- Wild Draenish Gloves
(@Leatherworking, 36079, 40000, 165, 330, 0), -- Golden Dragonstrike Breastplate
(@Leatherworking, 32456, 15000, 165, 300, 0), -- Knothide Armor Kit
(@Leatherworking, 32472, 20000, 165, 320, 0), -- Thick Draenic Boots
(@Leatherworking, 32465, 25000, 165, 335, 0), -- Felscale Breastplate
(@Leatherworking, 32481, 25000, 165, 330, 0), -- Wild Draenish Vest
(@Leatherworking, 44970, 50000, 165, 350, 0), -- Heavy Knothide Armor Kit
(@Leatherworking, 51571, 30000, 165, 385, 0), -- Arctic Wristguards
(@Leatherworking, 51572, 30000, 165, 385, 0), -- Arctic Helm
(@Leatherworking, 51570, 80000, 165, 395, 0), -- Dark Arctic Chestpiece
(@Leatherworking, 51569, 80000, 165, 395, 0), -- Dark Arctic Leggings
(@Leatherworking, 51568, 100000, 165, 400, 0), -- Black Chitinguard Boots
(@Leatherworking, 50953, 30000, 165, 380, 0), -- Frostscale Gloves
(@Leatherworking, 50954, 30000, 165, 380, 0), -- Frostscale Boots
(@Leatherworking, 60599, 30000, 165, 385, 0), -- Frostscale Bracers
(@Leatherworking, 60600, 30000, 165, 385, 0), -- Frostscale Helm
(@Leatherworking, 60601, 80000, 165, 395, 0), -- Dark Frostscale Leggings
(@Leatherworking, 60604, 80000, 165, 395, 0), -- Dark Frostscale Breastplate
(@Leatherworking, 60605, 100000, 165, 400, 0), -- Dragonstompers
(@Leatherworking, 50943, 30000, 165, 380, 0), -- Iceborne Belt
(@Leatherworking, 62448, 80000, 165, 425, 0), -- Earthen Leg Armor
(@Leatherworking, 50936, 80000, 165, 390, 0), -- Heavy Borean Leather
(@Leatherworking, 50963, 80000, 165, 395, 0), -- Heavy Borean Armor Kit
(@Leatherworking, 50946, 30000, 165, 380, 0), -- Arctic Shoulderpads
(@Leatherworking, 50949, 30000, 165, 380, 0), -- Arctic Belt
(@Leatherworking, 69386, 200000, 165, 450, 0), -- Drums of Forgotten Kings
(@Leatherworking, 69388, 200000, 165, 450, 0), -- Drums of the Wild
(@Leatherworking, 51301, 350000, 165, 350, 65), -- Grand Master Leatherworker
(@Leatherworking, 50951, 30000, 165, 370, 0), -- Frostscale Leggings
(@Leatherworking, 50962, 50000, 165, 350, 0), -- Borean Armor Kit
(@Leatherworking, 50939, 30000, 165, 370, 0), -- Iceborne Leggings
(@Leatherworking, 50940, 30000, 165, 380, 0), -- Iceborne Shoulderpads
(@Leatherworking, 60608, 30000, 165, 385, 0), -- Iceborne Helm
(@Leatherworking, 60607, 30000, 165, 385, 0), -- Iceborne Wristguards
(@Leatherworking, 60611, 80000, 165, 395, 0), -- Dark Iceborne Leggings
(@Leatherworking, 60613, 80000, 165, 395, 0), -- Dark Iceborne Chestguard
(@Leatherworking, 60620, 100000, 165, 400, 0), -- Bugsquashers
(@Leatherworking, 50960, 30000, 165, 380, 0), -- Nerubian Boots
(@Leatherworking, 50958, 30000, 165, 380, 0), -- Nerubian Shoulders
(@Leatherworking, 60622, 30000, 165, 385, 0), -- Nerubian Bracers
(@Leatherworking, 60624, 30000, 165, 385, 0), -- Nerubian Helm
(@Leatherworking, 60627, 80000, 165, 395, 0), -- Dark Nerubian Leggings
(@Leatherworking, 60629, 80000, 165, 395, 0), -- Dark Nerubian Chestpiece
(@Leatherworking, 60630, 80000, 165, 400, 0), -- Scaled Icewalkers
(@Leatherworking, 60631, 80000, 165, 380, 0), -- Cloak of Harsh Winds
(@Leatherworking, 55199, 80000, 165, 395, 0), -- Cloak of Tormented Skies
(@Leatherworking, 60637, 200000, 165, 440, 0), -- Ice Striker's Cloak
(@Leatherworking, 60640, 200000, 165, 440, 0), -- Durable Nerubhide Cape
(@Leatherworking, 50966, 50000, 165, 400, 0), -- Nerubian Leg Armor
(@Leatherworking, 50964, 50000, 165, 405, 0), -- Jormungar Leg Armor
(@Leatherworking, 60583, 50000, 165, 405, 0), -- Jormungar Leg Reinforcements
(@Leatherworking, 60584, 50000, 165, 400, 0), -- Nerubian Leg Reinforcements
(@Leatherworking, 50965, 80000, 165, 425, 0), -- Frosthide Leg Armor
(@Leatherworking, 50967, 80000, 165, 425, 0), -- Icescale Leg Armor
(@Leatherworking, 60643, 50000, 165, 415, 0), -- Pack of Endless Pockets
(@Leatherworking, 60649, 100000, 165, 425, 0), -- Razorstrike Breastplate
(@Leatherworking, 60651, 100000, 165, 420, 0), -- Virulent Spaulders
(@Leatherworking, 60652, 100000, 165, 420, 0), -- Eaglebane Bracers
(@Leatherworking, 60655, 200000, 165, 425, 0), -- Nightshock Hood
(@Leatherworking, 60658, 200000, 165, 420, 0), -- Nightshock Girdle
(@Leatherworking, 60660, 100000, 165, 425, 0), -- Leggings of Visceral Strikes
(@Leatherworking, 60665, 100000, 165, 420, 0), -- Seafoam Gauntlets
(@Leatherworking, 60666, 80000, 165, 420, 0), -- Jormscale Footpads
(@Leatherworking, 60669, 100000, 165, 425, 0), -- Wildscale Breastplate
(@Leatherworking, 60671, 100000, 165, 420, 0), -- Purehorn Spaulders
(@Leatherworking, 57683, 70000, 165, 400, 0), -- Fur Lining - Attack Power
(@Leatherworking, 57690, 70000, 165, 400, 0), -- Fur Lining - Stamina
(@Leatherworking, 57691, 70000, 165, 400, 0), -- Fur Lining - Spell Power
(@Leatherworking, 50955, 30000, 165, 370, 0), -- Frostscale Belt
(@Leatherworking, 50948, 30000, 165, 370, 0), -- Arctic Boots
(@Leatherworking, 50941, 30000, 165, 370, 0), -- Iceborne Gloves
(@Leatherworking, 50957, 30000, 165, 370, 0), -- Nerubian Legguards
(@Leatherworking, 50950, 30000, 165, 375, 0), -- Frostscale Chestguard
(@Leatherworking, 50959, 30000, 165, 370, 0), -- Nerubian Gloves
(@Leatherworking, 50952, 30000, 165, 375, 0), -- Frostscale Shoulders
(@Leatherworking, 50945, 30000, 165, 375, 0), -- Arctic Leggings
(@Leatherworking, 50961, 30000, 165, 375, 0), -- Nerubian Belt
(@Leatherworking, 50938, 30000, 165, 375, 0), -- Iceborne Chestguard
(@Leatherworking, 50947, 30000, 165, 375, 0), -- Arctic Gloves
(@Leatherworking, 50956, 30000, 165, 375, 0), -- Nerubian Chestguard
(@Leatherworking, 64661, 50000, 165, 350, 0), -- Borean Leather
(@Leatherworking, 50942, 30000, 165, 375, 0), -- Iceborne Boots
(@Leatherworking, 50944, 30000, 165, 370, 0), -- Arctic Chestpiece
(@Leatherworking, 78432, 85000, 165, 485, 0), -- Tsunami Helm
(@Leatherworking, 85010, 100000, 165, 500, 0), -- Draconic Embossment - Intellect
(@Leatherworking, 78427, 85000, 165, 480, 0), -- Tsunami Leggings
(@Leatherworking, 78436, 85000, 165, 485, 0), -- Heavy Savage Leather
(@Leatherworking, 84950, 75000, 165, 425, 0), -- Savage Leather
(@Leatherworking, 78439, 85000, 165, 495, 0), -- Cloak of War
(@Leatherworking, 78416, 75000, 165, 455, 0), -- Darkbrand Belt
(@Leatherworking, 85008, 100000, 165, 500, 0), -- Draconic Embossment - Agility
(@Leatherworking, 78379, 75000, 165, 425, 0), -- Savage Armor Kit
(@Leatherworking, 78411, 85000, 165, 475, 0), -- Darkbrand Shoulders
(@Leatherworking, 85067, 75000, 165, 465, 0), -- Dragonbone Leg Reinforcements
(@Leatherworking, 78388, 75000, 165, 460, 0), -- Tsunami Bracers
(@Leatherworking, 78420, 85000, 165, 480, 0), -- Twilight Leg Armor
(@Leatherworking, 78406, 85000, 165, 475, 0), -- Tsunami Gloves
(@Leatherworking, 78438, 85000, 165, 495, 0), -- Cloak of Beasts
(@Leatherworking, 78399, 75000, 165, 465, 0), -- Darkbrand Gloves
(@Leatherworking, 78415, 75000, 165, 455, 0), -- Tsunami Shoulders
(@Leatherworking, 85007, 100000, 165, 500, 0), -- Draconic Embossment - Stamina
(@Leatherworking, 78424, 85000, 165, 490, 0), -- Darkbrand Helm
(@Leatherworking, 78433, 85000, 165, 485, 0), -- Darkbrand Leggings
(@Leatherworking, 85009, 100000, 165, 500, 0), -- Draconic Embossment - Strength
(@Leatherworking, 78410, 75000, 165, 450, 0), -- Tsunami Boots
(@Leatherworking, 78419, 85000, 165, 475, 0), -- Scorched Leg Armor
(@Leatherworking, 78380, 75000, 165, 460, 0), -- Savage Cloak
(@Leatherworking, 78396, 75000, 165, 470, 0), -- Tsunami Belt
(@Leatherworking, 78428, 85000, 165, 480, 0), -- Darkbrand Chestguard
(@Leatherworking, 85068, 75000, 165, 465, 0), -- Charscale Leg Reinforcements
(@Leatherworking, 78405, 75000, 165, 470, 0), -- Hardened Scale Cloak
(@Leatherworking, 78437, 85000, 165, 485, 0), -- Heavy Savage Armor Kit
(@Leatherworking, 78398, 75000, 165, 450, 0), -- Darkbrand Bracers
(@Leatherworking, 78423, 85000, 165, 490, 0), -- Tsunami Chestguard
(@Leatherworking, 99535, 100000, 165, 500, 0), -- Vicious Hide Cloak
(@Leatherworking, 99536, 100000, 165, 500, 0), -- Vicious Fur Cloak
(@Leatherworking, 101600, 75000, 165, 465, 0), -- Drakehide Leg Reinforcements
(@Leatherworking, 78407, 75000, 165, 465, 0), -- Darkbrand Boots
(@Leatherworking, 81200, 500000, 165, 425, 75), -- Illustrious Grand Master Leatherworker
(@Leatherworking, 19055, 10000, 165, 270, 0), -- Runic Leather Gauntlets
(@Leatherworking, 19065, 10000, 165, 275, 0), -- Runic Leather Bracers
(@Leatherworking, 19071, 10000, 165, 280, 0), -- Wicked Leather Headband
(@Leatherworking, 19072, 10000, 165, 280, 0), -- Runic Leather Belt
(@Leatherworking, 19082, 15000, 165, 290, 0), -- Runic Leather Headband
(@Leatherworking, 19083, 15000, 165, 290, 0), -- Wicked Leather Pants
(@Leatherworking, 19091, 15000, 165, 300, 0), -- Runic Leather Pants
(@Leatherworking, 19092, 15000, 165, 300, 0), -- Wicked Leather Belt
(@Leatherworking, 19098, 15000, 165, 300, 0), -- Wicked Leather Armor
(@Leatherworking, 19102, 15000, 165, 300, 0), -- Runic Leather Armor
(@Leatherworking, 19103, 15000, 165, 300, 0), -- Runic Leather Shoulders
(@Leatherworking, 22331, 5000, 165, 250, 0), -- Rugged Leather
(@Leatherworking, 10632, 10000, 165, 250, 0), -- Helm of Fire
(@Leatherworking, 10630, 10000, 165, 230, 0), -- Gauntlets of the Sea
(@Leatherworking, 36074, 10000, 165, 260, 0), -- Blackstorm Leggings
(@Leatherworking, 10663, 50000, 165, 200, 35), -- Artisan Leatherworker
(@Leatherworking, 10647, 10000, 165, 250, 0), -- Feathered Breastplate
(@Leatherworking, 24655, 30000, 165, 280, 0), -- Green Dragonscale Gauntlets
(@Leatherworking, 10650, 10000, 165, 255, 0), -- Dragonscale Breastplate
(@Leatherworking, 36075, 10000, 165, 260, 0), -- Wildfeather Leggings
(@Leatherworking, 36076, 10000, 165, 260, 0), -- Dragonstrike Leggings
(@Leatherworking, 24654, 50000, 165, 300, 0), -- Blue Dragonscale Leggings
(@Leatherworking, 19047, 5000, 165, 250, 0), -- Cured Rugged Hide
(@Leatherworking, 19058, 5000, 165, 250, 0), -- Rugged Armor Kit
(@Leatherworking, 10548, 4000, 165, 230, 0), -- Nightscape Pants
(@Leatherworking, 10552, 4000, 165, 230, 0), -- Turtle Scale Helm
(@Leatherworking, 10556, 4500, 165, 235, 0), -- Turtle Scale Leggings
(@Leatherworking, 10558, 4500, 165, 235, 0), -- Nightscape Boots
(@Leatherworking, 19052, 10000, 165, 265, 0), -- Wicked Leather Bracers
(@Leatherworking, 20650, 4000, 165, 200, 0), -- Thick Leather
(@Leatherworking, 3812, 5000, 165, 125, 20), -- Expert Leatherworker
(@Leatherworking, 3774, 1000, 165, 160, 0), -- Green Leather Belt
(@Leatherworking, 3776, 1200, 165, 180, 0), -- Green Leather Bracers
(@Leatherworking, 10482, 2000, 165, 200, 0), -- Cured Thick Hide
(@Leatherworking, 10487, 2000, 165, 200, 0), -- Thick Armor Kit
(@Leatherworking, 10499, 3000, 165, 205, 0), -- Nightscape Tunic
(@Leatherworking, 10507, 3000, 165, 205, 0), -- Nightscape Headband
(@Leatherworking, 10511, 3000, 165, 210, 0), -- Turtle Scale Breastplate
(@Leatherworking, 10518, 3500, 165, 210, 0), -- Turtle Scale Bracers
(@Leatherworking, 6661, 2000, 165, 190, 0), -- Barbaric Harness
(@Leatherworking, 7147, 1000, 165, 160, 0), -- Guardian Pants
(@Leatherworking, 7151, 1200, 165, 175, 0), -- Barbaric Shoulders
(@Leatherworking, 7156, 2400, 165, 190, 0), -- Guardian Gloves
(@Leatherworking, 9196, 1500, 165, 175, 0), -- Dusky Leather Armor
(@Leatherworking, 9198, 2000, 165, 180, 0), -- Frost Leather Cloak
(@Leatherworking, 9201, 2000, 165, 185, 0), -- Dusky Bracers
(@Leatherworking, 9206, 2500, 165, 195, 0), -- Dusky Belt
(@Leatherworking, 20648, 500, 165, 100, 0), -- Medium Leather
(@Leatherworking, 20649, 1000, 165, 150, 0), -- Heavy Leather
(@Leatherworking, 2154, 500, 165, 50, 10), -- Journeyman Leatherworker
(@Leatherworking, 3763, 300, 165, 80, 0), -- Fine Leather Belt
(@Leatherworking, 2159, 250, 165, 85, 0), -- Fine Leather Cloak
(@Leatherworking, 3761, 350, 165, 85, 0), -- Fine Leather Tunic
(@Leatherworking, 3817, 200, 165, 100, 0), -- Cured Medium Hide
(@Leatherworking, 2165, 250, 165, 100, 0), -- Medium Armor Kit
(@Leatherworking, 2167, 350, 165, 100, 0), -- Dark Leather Boots
(@Leatherworking, 3766, 400, 165, 125, 0), -- Dark Leather Belt
(@Leatherworking, 2168, 350, 165, 110, 0), -- Dark Leather Cloak
(@Leatherworking, 3764, 500, 165, 145, 0), -- Hillman's Leather Gloves
(@Leatherworking, 2166, 450, 165, 120, 0), -- Toughened Leather Armor
(@Leatherworking, 3768, 500, 165, 130, 0), -- Hillman's Shoulders
(@Leatherworking, 3770, 500, 165, 135, 0), -- Toughened Leather Gloves
(@Leatherworking, 3818, 500, 165, 150, 0), -- Cured Heavy Hide
(@Leatherworking, 3760, 600, 165, 150, 0), -- Hillman's Cloak
(@Leatherworking, 3780, 750, 165, 150, 0), -- Heavy Armor Kit
(@Leatherworking, 7135, 400, 165, 115, 0), -- Dark Leather Pants
(@Leatherworking, 9068, 400, 165, 95, 0), -- Light Leather Pants
(@Leatherworking, 9074, 500, 165, 120, 0), -- Nimble Leather Gloves
(@Leatherworking, 9145, 500, 165, 125, 0), -- Fletcher's Gloves
(@Leatherworking, 2153, 50, 165, 15, 0), -- Handstitched Leather Pants
(@Leatherworking, 3753, 75, 165, 25, 0), -- Handstitched Leather Belt
(@Leatherworking, 3816, 50, 165, 35, 0), -- Cured Light Hide
(@Leatherworking, 2160, 100, 165, 40, 0), -- Embossed Leather Vest
(@Leatherworking, 3756, 150, 165, 55, 0), -- Embossed Leather Gloves
(@Leatherworking, 2161, 100, 165, 55, 0), -- Embossed Leather Boots
(@Leatherworking, 2162, 100, 165, 60, 0), -- Embossed Leather Cloak
(@Leatherworking, 3759, 200, 165, 75, 0), -- Embossed Leather Pants
(@Leatherworking, 9065, 150, 165, 70, 0), -- Light Leather Bracers
(@Leatherworking, 2155, 10, 0, 0, 5), -- Apprentice Leatherworker
-- Mining
(@Mining, 29686, 100000, 186, 375, 0), -- Smelt Hardened Adamantite
(@Mining, 29360, 40000, 186, 350, 0), -- Smelt Felsteel
(@Mining, 29361, 100000, 186, 375, 0), -- Smelt Khorium
(@Mining, 29358, 40000, 186, 325, 0), -- Smelt Adamantite
(@Mining, 29359, 40000, 186, 350, 0), -- Smelt Eternium
(@Mining, 29355, 100000, 186, 275, 40), -- Master Miner
(@Mining, 35751, 10000, 186, 300, 0), -- Fire Sunder
(@Mining, 29356, 40000, 186, 275, 0), -- Smelt Fel Iron
(@Mining, 35750, 10000, 186, 300, 0), -- Earth Shatter
(@Mining, 70524, 10000, 186, 250, 0), -- Enchanted Thorium Bar
(@Mining, 10249, 50000, 186, 200, 25), -- Artisan Miner
(@Mining, 10097, 5000, 186, 150, 0), -- Smelt Mithril
(@Mining, 3568, 5000, 186, 125, 10), -- Expert Miner
(@Mining, 16153, 20000, 186, 200, 0), -- Smelt Thorium
(@Mining, 10098, 10000, 186, 165, 0), -- Smelt Truesilver
(@Mining, 3307, 500, 186, 100, 0), -- Smelt Iron
(@Mining, 2582, 500, 186, 50, 0), -- Journeyman Miner
(@Mining, 3308, 600, 186, 115, 0), -- Smelt Gold
(@Mining, 3569, 750, 186, 125, 0), -- Smelt Steel
(@Mining, 2658, 200, 186, 65, 0), -- Smelt Silver
(@Mining, 3304, 50, 186, 50, 0), -- Smelt Tin
(@Mining, 2659, 200, 186, 50, 0), -- Smelt Bronze
(@Mining, 2581, 10, 0, 0, 0), -- Apprentice Miner
(@Mining, 49258, 150000, 186, 400, 0), -- Smelt Saronite
(@Mining, 55211, 200000, 186, 450, 0), -- Smelt Titanium
(@Mining, 55208, 200000, 186, 450, 0), -- Smelt Titansteel
(@Mining, 50309, 350000, 186, 350, 55), -- Grand Master Miner
(@Mining, 49252, 100000, 186, 350, 0), -- Smelt Cobalt
(@Mining, 74518, 500000, 186, 425, 75), -- Illustrious Grand Master Miner
(@Mining, 74529, 50000, 186, 525, 0), -- Smelt Pyrite
(@Mining, 74530, 50000, 186, 475, 0), -- Smelt Elementium
(@Mining, 74537, 50000, 186, 500, 0), -- Smelt Hardened Elementium
(@Mining, 84038, 50000, 186, 425, 0), -- Smelt Obsidium
-- Skinning
(@Skinning, 8615, 10, 0, 0, 0), -- Apprentice Skinner
(@Skinning, 8619, 500, 393, 50, 0), -- Journeyman Skinner
(@Skinning, 8620, 5000, 393, 125, 10), -- Expert Skinner
(@Skinning, 10769, 50000, 393, 200, 25), -- Artisan Skinner
(@Skinning, 32679, 100000, 393, 275, 40), -- Master Skinner
(@Skinning, 74523, 500000, 393, 425, 75), -- Illustrious Grand Master Skinner
(@Skinning, 50307, 350000, 393, 350, 55), -- Grand Master Skinner
-- Tailoring
(@Tailoring, 26746, 15000, 197, 315, 0), -- Netherweave Bag
(@Tailoring, 26764, 15000, 197, 310, 0), -- Netherweave Bracers
(@Tailoring, 26765, 15000, 197, 310, 0), -- Netherweave Belt
(@Tailoring, 26770, 20000, 197, 320, 0), -- Netherweave Gloves
(@Tailoring, 26771, 20000, 197, 325, 0), -- Netherweave Pants
(@Tailoring, 26772, 20000, 197, 335, 0), -- Netherweave Boots
(@Tailoring, 26791, 100000, 197, 275, 50), -- Master Tailor
(@Tailoring, 31460, 15000, 197, 300, 0), -- Netherweave Net
(@Tailoring, 26745, 15000, 197, 300, 0), -- Bolt of Netherweave
(@Tailoring, 60969, 15000, 197, 300, 0), -- Flying Carpet
(@Tailoring, 18406, 10000, 197, 260, 0), -- Runecloth Robe
(@Tailoring, 18409, 10000, 197, 265, 0), -- Runecloth Cloak
(@Tailoring, 18410, 10000, 197, 265, 0), -- Ghostweave Belt
(@Tailoring, 18413, 10000, 197, 270, 0), -- Ghostweave Gloves
(@Tailoring, 18414, 10000, 197, 270, 0), -- Brightcloth Robe
(@Tailoring, 12072, 6000, 197, 230, 0), -- Black Mageweave Headband
(@Tailoring, 12073, 6000, 197, 230, 0), -- Black Mageweave Boots
(@Tailoring, 12074, 6000, 197, 230, 0), -- Black Mageweave Shoulders
(@Tailoring, 12077, 5000, 197, 235, 0), -- Simple Black Dress
(@Tailoring, 12079, 6500, 197, 235, 0), -- Red Mageweave Bag
(@Tailoring, 12088, 7500, 197, 245, 0), -- Cindercloth Boots
(@Tailoring, 12092, 7500, 197, 250, 0), -- Dreamweave Circlet
(@Tailoring, 18401, 10000, 197, 250, 0), -- Bolt of Runecloth
(@Tailoring, 18402, 10000, 197, 255, 0), -- Runecloth Belt
(@Tailoring, 18415, 10000, 197, 270, 0), -- Brightcloth Gloves
(@Tailoring, 18416, 12500, 197, 275, 0), -- Ghostweave Vest
(@Tailoring, 18417, 12500, 197, 275, 0), -- Runecloth Gloves
(@Tailoring, 18420, 12500, 197, 275, 0), -- Brightcloth Cloak
(@Tailoring, 18421, 12500, 197, 275, 0), -- Wizardweave Leggings
(@Tailoring, 18438, 15000, 197, 285, 0), -- Runecloth Pants
(@Tailoring, 18441, 15000, 197, 290, 0), -- Ghostweave Pants
(@Tailoring, 18444, 15000, 197, 295, 0), -- Runecloth Headband
(@Tailoring, 18446, 15000, 197, 300, 0), -- Wizardweave Robe
(@Tailoring, 12076, 6500, 197, 235, 0), -- Shadoweave Shoulders
(@Tailoring, 12082, 7000, 197, 240, 0), -- Shadoweave Boots
(@Tailoring, 18403, 10000, 197, 255, 0), -- Frostweave Tunic
(@Tailoring, 18407, 10000, 197, 260, 0), -- Runecloth Tunic
(@Tailoring, 18411, 10000, 197, 265, 0), -- Frostweave Gloves
(@Tailoring, 18423, 15000, 197, 280, 0), -- Runecloth Boots
(@Tailoring, 18424, 15000, 197, 280, 0), -- Frostweave Pants
(@Tailoring, 18437, 15000, 197, 285, 0), -- Felcloth Boots
(@Tailoring, 18442, 15000, 197, 290, 0), -- Felcloth Hood
(@Tailoring, 18451, 15000, 197, 300, 0), -- Felcloth Robe
(@Tailoring, 18453, 15000, 197, 300, 0), -- Felcloth Shoulders
(@Tailoring, 12181, 50000, 197, 200, 35), -- Artisan Tailor
(@Tailoring, 18449, 15000, 197, 300, 0), -- Runecloth Shoulders
(@Tailoring, 18450, 15000, 197, 300, 0), -- Wizardweave Turban
(@Tailoring, 8483, 500, 197, 160, 0), -- White Swashbuckler's Shirt
(@Tailoring, 8489, 750, 197, 175, 0), -- Red Swashbuckler's Shirt
(@Tailoring, 12048, 4000, 197, 205, 0), -- Black Mageweave Vest
(@Tailoring, 12050, 4000, 197, 210, 0), -- Black Mageweave Robe
(@Tailoring, 12049, 4000, 197, 205, 0), -- Black Mageweave Leggings
(@Tailoring, 12053, 5000, 197, 215, 0), -- Black Mageweave Gloves
(@Tailoring, 12061, 2500, 197, 215, 0), -- Orange Mageweave Shirt
(@Tailoring, 12065, 5000, 197, 225, 0), -- Mageweave Bag
(@Tailoring, 12067, 5000, 197, 225, 0), -- Dreamweave Gloves
(@Tailoring, 12069, 5000, 197, 225, 0), -- Cindercloth Robe
(@Tailoring, 12070, 5000, 197, 225, 0), -- Dreamweave Vest
(@Tailoring, 8766, 1000, 197, 175, 0), -- Azure Silk Belt
(@Tailoring, 8770, 1000, 197, 190, 0), -- Robe of Power
(@Tailoring, 8772, 1000, 197, 175, 0), -- Crimson Silk Belt
(@Tailoring, 8774, 1000, 197, 180, 0), -- Green Silken Shoulders
(@Tailoring, 8799, 3000, 197, 195, 0), -- Crimson Silk Pantaloons
(@Tailoring, 8804, 5000, 197, 210, 0), -- Crimson Silk Gloves
(@Tailoring, 8791, 2500, 197, 185, 0), -- Crimson Silk Vest
(@Tailoring, 3871, 500, 197, 170, 0), -- Formal White Shirt
(@Tailoring, 8764, 900, 197, 170, 0), -- Earthen Vest
(@Tailoring, 8762, 750, 197, 160, 0), -- Silk Headband
(@Tailoring, 3865, 1000, 197, 175, 0), -- Bolt of Mageweave
(@Tailoring, 3861, 1000, 197, 185, 0), -- Long Silken Cloak
(@Tailoring, 12052, 5000, 197, 210, 0), -- Shadoweave Pants
(@Tailoring, 12055, 5500, 197, 215, 0), -- Shadoweave Robe
(@Tailoring, 12071, 6000, 197, 225, 0), -- Shadoweave Gloves
(@Tailoring, 3913, 5000, 197, 125, 20), -- Expert Tailor
(@Tailoring, 3845, 300, 197, 80, 0), -- Soft-soled Linen Boots
(@Tailoring, 6521, 400, 197, 90, 0), -- Pearl-clasped Cloak
(@Tailoring, 3813, 800, 197, 150, 0), -- Small Silk Pack
(@Tailoring, 3757, 200, 197, 80, 0), -- Woolen Bag
(@Tailoring, 6690, 1000, 197, 135, 0), -- Lesser Wizard's Robe
(@Tailoring, 8467, 250, 197, 110, 0), -- White Woolen Dress
(@Tailoring, 8758, 600, 197, 140, 0), -- Azure Silk Pants
(@Tailoring, 8760, 600, 197, 145, 0), -- Azure Silk Hood
(@Tailoring, 3859, 750, 197, 150, 0), -- Azure Silk Vest
(@Tailoring, 3839, 500, 197, 125, 0), -- Bolt of Silk Cloth
(@Tailoring, 3852, 750, 197, 130, 0), -- Gloves of Meditation
(@Tailoring, 63742, 750, 197, 125, 0), -- Spidersilk Drape
(@Tailoring, 3912, 500, 197, 50, 10), -- Journeyman Tailor
(@Tailoring, 3843, 400, 197, 85, 0), -- Heavy Woolen Gloves
(@Tailoring, 2399, 300, 197, 85, 0), -- Green Woolen Vest
(@Tailoring, 2401, 300, 197, 95, 0), -- Woolen Boots
(@Tailoring, 2406, 200, 197, 100, 0), -- Gray Woolen Shirt
(@Tailoring, 3848, 500, 197, 110, 0), -- Double-stitched Woolen Shoulders
(@Tailoring, 3850, 500, 197, 110, 0), -- Heavy Woolen Pants
(@Tailoring, 3866, 250, 197, 110, 0), -- Stylish Red Shirt
(@Tailoring, 3855, 750, 197, 125, 0), -- Spidersilk Boots
(@Tailoring, 2395, 300, 197, 70, 0), -- Barbaric Linen Vest
(@Tailoring, 2397, 200, 197, 60, 0), -- Reinforced Linen Cape
(@Tailoring, 3842, 300, 197, 70, 0), -- Handstitched Linen Britches
(@Tailoring, 2396, 200, 197, 70, 0), -- Green Linen Shirt
(@Tailoring, 2964, 100, 197, 75, 0), -- Bolt of Woolen Cloth
(@Tailoring, 2402, 250, 197, 75, 0), -- Woolen Cape
(@Tailoring, 12045, 50, 197, 20, 0), -- Simple Linen Boots
(@Tailoring, 12046, 300, 197, 75, 0), -- Simple Kilt
(@Tailoring, 3755, 100, 197, 45, 0), -- Linen Bag
(@Tailoring, 7623, 50, 197, 30, 0), -- Brown Linen Robe
(@Tailoring, 7624, 50, 197, 30, 0), -- White Linen Robe
(@Tailoring, 8465, 50, 197, 40, 0), -- Simple Dress
(@Tailoring, 8776, 50, 197, 15, 0), -- Linen Belt
(@Tailoring, 3914, 50, 197, 30, 0), -- Brown Linen Pants
(@Tailoring, 2385, 50, 197, 10, 0), -- Brown Linen Vest
(@Tailoring, 3840, 100, 197, 35, 0), -- Heavy Linen Gloves
(@Tailoring, 2386, 200, 197, 65, 0), -- Linen Boots
(@Tailoring, 2392, 50, 197, 40, 0), -- Red Linen Shirt
(@Tailoring, 2393, 25, 197, 1, 0), -- White Linen Shirt
(@Tailoring, 2394, 50, 197, 40, 0), -- Blue Linen Shirt
(@Tailoring, 3841, 200, 197, 60, 0), -- Green Linen Bracers
(@Tailoring, 3911, 10, 0, 0, 5), -- Apprentice Tailor
(@Tailoring, 60971, 150000, 197, 425, 0), -- Magnificent Flying Carpet
(@Tailoring, 56030, 50000, 197, 380, 0), -- Frostwoven Leggings
(@Tailoring, 55907, 50000, 197, 380, 0), -- Frostwoven Cowl
(@Tailoring, 55910, 80000, 197, 385, 0), -- Mystic Frostwoven Shoulders
(@Tailoring, 55911, 80000, 197, 390, 0), -- Mystic Frostwoven Robe
(@Tailoring, 55913, 80000, 197, 385, 0), -- Mystic Frostwoven Wristwraps
(@Tailoring, 56034, 100000, 197, 405, 0), -- Master's Spellthread
(@Tailoring, 59582, 100000, 197, 415, 0), -- Frostsavage Belt
(@Tailoring, 59583, 100000, 197, 415, 0), -- Frostsavage Bracers
(@Tailoring, 59584, 100000, 197, 420, 0), -- Frostsavage Shoulders
(@Tailoring, 59585, 100000, 197, 420, 0), -- Frostsavage Boots
(@Tailoring, 59586, 100000, 197, 420, 0), -- Frostsavage Gloves
(@Tailoring, 59587, 100000, 197, 420, 0), -- Frostsavage Robe
(@Tailoring, 59588, 120000, 197, 420, 0), -- Frostsavage Leggings
(@Tailoring, 59589, 120000, 197, 420, 0), -- Frostsavage Cowl
(@Tailoring, 64729, 100000, 197, 400, 0), -- Frostguard Drape
(@Tailoring, 64730, 100000, 197, 405, 0), -- Cloak of Crimson Snow
(@Tailoring, 51308, 350000, 197, 350, 65), -- Grand Master Tailor
(@Tailoring, 55904, 50000, 197, 360, 0), -- Frostwoven Gloves
(@Tailoring, 55906, 50000, 197, 375, 0), -- Frostwoven Boots
(@Tailoring, 55899, 50000, 197, 350, 0), -- Bolt of Frostweave
(@Tailoring, 55908, 50000, 197, 370, 0), -- Frostwoven Belt
(@Tailoring, 55903, 50000, 197, 360, 0), -- Frostwoven Robe
(@Tailoring, 56031, 50000, 197, 350, 0), -- Frostwoven Wristwraps
(@Tailoring, 55898, 50000, 197, 360, 0), -- Frostweave Net
(@Tailoring, 55902, 50000, 197, 350, 0), -- Frostwoven Shoulders
(@Tailoring, 56002, 100000, 197, 415, 0), -- Ebonweave
(@Tailoring, 56001, 100000, 197, 415, 0), -- Moonshroud
(@Tailoring, 56003, 100000, 197, 415, 0), -- Spellweave
(@Tailoring, 56018, 100000, 197, 425, 0), -- Hat of Wintry Doom
(@Tailoring, 56019, 100000, 197, 420, 0), -- Silky Iceshard Boots
(@Tailoring, 55642, 125000, 197, 420, 0), -- Lightweave Embroidery
(@Tailoring, 55769, 125000, 197, 420, 0), -- Darkglow Embroidery
(@Tailoring, 55777, 125000, 197, 420, 0), -- Swordguard Embroidery
(@Tailoring, 56014, 100000, 197, 390, 0), -- Cloak of the Moon
(@Tailoring, 56015, 100000, 197, 395, 0), -- Cloak of Frozen Spirits
(@Tailoring, 56007, 80000, 197, 410, 0), -- Frostweave Bag
(@Tailoring, 55900, 125000, 197, 400, 0), -- Bolt of Imbued Frostweave
(@Tailoring, 55901, 50000, 197, 395, 0), -- Duskweave Leggings
(@Tailoring, 55914, 50000, 197, 395, 0), -- Duskweave Belt
(@Tailoring, 55921, 100000, 197, 405, 0), -- Duskweave Robe
(@Tailoring, 55922, 100000, 197, 405, 0), -- Duskweave Gloves
(@Tailoring, 55919, 100000, 197, 395, 0), -- Duskweave Cowl
(@Tailoring, 55924, 125000, 197, 410, 0), -- Duskweave Boots
(@Tailoring, 55925, 125000, 197, 415, 0), -- Black Duskweave Leggings
(@Tailoring, 55920, 50000, 197, 400, 0), -- Duskweave Wristwraps
(@Tailoring, 55923, 100000, 197, 410, 0), -- Duskweave Shoulders
(@Tailoring, 55941, 125000, 197, 420, 0), -- Black Duskweave Robe
(@Tailoring, 55943, 125000, 197, 415, 0), -- Black Duskweave Wristwraps
(@Tailoring, 56008, 100000, 197, 400, 0), -- Shining Spellthread
(@Tailoring, 56010, 100000, 197, 400, 0), -- Azure Spellthread
(@Tailoring, 56039, 100000, 197, 405, 0), -- Sanctified Spellthread
(@Tailoring, 56020, 100000, 197, 420, 0), -- Deep Frozen Cord
(@Tailoring, 56021, 100000, 197, 425, 0), -- Frostmoon Pants
(@Tailoring, 56022, 100000, 197, 420, 0), -- Light Blessed Mittens
(@Tailoring, 56023, 100000, 197, 420, 0), -- Aurora Slippers
(@Tailoring, 56024, 200000, 197, 440, 0), -- Moonshroud Robe
(@Tailoring, 56025, 200000, 197, 435, 0), -- Moonshroud Gloves
(@Tailoring, 56026, 200000, 197, 440, 0), -- Ebonweave Robe
(@Tailoring, 56027, 200000, 197, 435, 0), -- Ebonweave Gloves
(@Tailoring, 56028, 200000, 197, 440, 0), -- Spellweave Robe
(@Tailoring, 56029, 200000, 197, 435, 0), -- Spellweave Gloves
(@Tailoring, 55995, 50000, 197, 400, 0), -- Yellow Lumberjack Shirt
(@Tailoring, 56000, 50000, 197, 400, 0), -- Green Workman's Shirt
(@Tailoring, 60993, 180000, 197, 425, 0), -- Glacial Robe
(@Tailoring, 60994, 180000, 197, 420, 0), -- Glacial Slippers
(@Tailoring, 60990, 180000, 197, 420, 0), -- Glacial Waistband
(@Tailoring, 75175, 60000, 197, 500, 0), -- Darkglow Embroidery
(@Tailoring, 75172, 60000, 197, 500, 0), -- Lightweave Embroidery
(@Tailoring, 75178, 60000, 197, 500, 0), -- Swordguard Embroidery
(@Tailoring, 75257, 120000, 197, 465, 0), -- Deathsilk Robe
(@Tailoring, 75256, 120000, 197, 465, 0), -- Deathsilk Cowl
(@Tailoring, 75254, 120000, 197, 460, 0), -- Deathsilk Leggings
(@Tailoring, 75253, 120000, 197, 460, 0), -- Deathsilk Gloves
(@Tailoring, 75252, 120000, 197, 455, 0), -- Deathsilk Boots
(@Tailoring, 75251, 120000, 197, 455, 0), -- Deathsilk Shoulders
(@Tailoring, 75146, 150000, 197, 500, 0), -- Dream of Azshara
(@Tailoring, 75144, 150000, 197, 500, 0), -- Dream of Hyjal
(@Tailoring, 75145, 150000, 197, 510, 0), -- Dream of Ragnaros
(@Tailoring, 75142, 150000, 197, 505, 0), -- Dream of Deepholm
(@Tailoring, 75141, 150000, 197, 515, 0), -- Dream of Skywall
(@Tailoring, 75293, 180000, 197, 510, 0), -- Vicious Embersilk Belt
(@Tailoring, 75297, 180000, 197, 520, 0), -- Vicious Embersilk Boots
(@Tailoring, 75270, 150000, 197, 500, 0), -- Vicious Embersilk Bracers
(@Tailoring, 75295, 180000, 197, 515, 0), -- Vicious Embersilk Gloves
(@Tailoring, 75291, 180000, 197, 505, 0), -- Vicious Embersilk Shoulders
(@Tailoring, 75269, 180000, 197, 510, 0), -- Vicious Fireweave Belt
(@Tailoring, 75294, 180000, 197, 515, 0), -- Vicious Fireweave Boots
(@Tailoring, 75290, 150000, 197, 500, 0), -- Vicious Fireweave Bracers
(@Tailoring, 75296, 180000, 197, 520, 0), -- Vicious Fireweave Gloves
(@Tailoring, 75292, 180000, 197, 510, 0), -- Vicious Fireweave Shoulders
(@Tailoring, 75255, 120000, 197, 460, 0), -- Ghostly Spellthread
(@Tailoring, 75265, 150000, 197, 480, 0), -- Otherworldly Bag
(@Tailoring, 75258, 120000, 197, 470, 0), -- Spiritmend Belt
(@Tailoring, 75261, 120000, 197, 475, 0), -- Spiritmend Boots
(@Tailoring, 75259, 120000, 197, 470, 0), -- Spiritmend Bracers
(@Tailoring, 75262, 150000, 197, 480, 0), -- Spiritmend Gloves
(@Tailoring, 75266, 150000, 197, 485, 0), -- Spiritmend Cowl
(@Tailoring, 75263, 150000, 197, 480, 0), -- Spiritmend Leggings
(@Tailoring, 75267, 150000, 197, 485, 0), -- Spiritmend Robe
(@Tailoring, 75260, 120000, 197, 475, 0), -- Spiritmend Shoulders
(@Tailoring, 75268, 150000, 197, 490, 0), -- Hyjal Expedition Bag
(@Tailoring, 75248, 120000, 197, 445, 0), -- Deathsilk Belt
(@Tailoring, 74964, 100000, 197, 425, 0), -- Bolt of Embersilk Cloth
(@Tailoring, 75247, 100000, 197, 425, 0), -- Embersilk Net
(@Tailoring, 75249, 120000, 197, 445, 0), -- Deathsilk Bracers
(@Tailoring, 75264, 150000, 197, 480, 0), -- Embersilk Bag
(@Tailoring, 75250, 120000, 197, 450, 0), -- Enchanted Spellthread
(@Tailoring, 99537, 150000, 197, 490, 0), -- Vicious Embersilk Cape
(@Tailoring, 94743, 240000, 197, 525, 0), -- Dream of Destruction
(@Tailoring, 75155, 40000, 197, 475, 0), -- Sanctified Spellthread
(@Tailoring, 75154, 40000, 197, 475, 0), -- Master's Spellthread
(@Tailoring, 75157, 500000, 197, 425, 75); -- Illustrious Grand Master Tailor
-- -------------------------------------------
-- -- Engineering Trainers Specialisations  --
-- -------------------------------------------
SET @EngineeringGoblin := 200433;
SET @EngineeringGnome := 200434;
DELETE FROM `npc_trainer` WHERE `entry` IN (@EngineeringGoblin, @EngineeringGnome);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
-- Goblin Engineering Trainer
(@EngineeringGoblin, 12755, 2040, 202, 230, 0), -- Goblin Bomb Dispenser
(@EngineeringGoblin, 12754, 2210, 202, 235, 0), -- The Big One
(@EngineeringGoblin, 12758, 2550, 202, 245, 0), -- Goblin Rocket Helmet
(@EngineeringGoblin, 12908, 2380, 202, 240, 0), -- Goblin Dragon Gun
(@EngineeringGoblin, 12715, 850, 202, 205, 0), -- Goblin Rocket Fuel Recipe
(@EngineeringGoblin, 8895, 1870, 202, 225, 0), -- Goblin Rocket Boots
(@EngineeringGoblin, 12717, 1275, 202, 205, 0), -- Goblin Mining Helmet
(@EngineeringGoblin, 12716, 1275, 202, 205, 0), -- Goblin Mortar
(@EngineeringGoblin, 12718, 1275, 202, 205, 0), -- Goblin Construction Helmet
(@EngineeringGoblin, 12760, 1275, 202, 205, 0), -- Goblin Sapper Charge
(@EngineeringGoblin, 56514, 127500, 202, 425, 0), -- Global Thermal Sapper Charge
(@EngineeringGoblin, 30558, 21250, 202, 325, 0), -- The Bigger One
(@EngineeringGoblin, 30563, 42500, 202, 350, 0), -- Goblin Rocket Launcher
(@EngineeringGoblin, 30565, 85000, 202, 375, 0), -- Foreman's Enchanted Helmet
(@EngineeringGoblin, 30560, 29750, 202, 340, 0), -- Super Sapper Charge
(@EngineeringGoblin, 30566, 85000, 202, 375, 0), -- Foreman's Reinforced Helmet
(@EngineeringGoblin, 84412, 136000, 202, 475, 0), -- Personal World Destroyer
(@EngineeringGoblin, 95707, 170000, 202, 500, 0), -- Big Daddy
-- Gnomish Engineering Trainer
(@EngineeringGnome, 56473, 127500, 202, 425, 0), -- Gnomish X-Ray Specs
(@EngineeringGnome, 12906, 2040, 202, 230, 0), -- Gnomish Battle Chicken
(@EngineeringGnome, 12759, 2380, 202, 240, 0), -- Gnomish Death Ray
(@EngineeringGnome, 12907, 2210, 202, 235, 0), -- Gnomish Mind Control Cap
(@EngineeringGnome, 30568, 21250, 202, 325, 0), -- Gnomish Flame Turret
(@EngineeringGnome, 30569, 29750, 202, 340, 0), -- Gnomish Poultryizer
(@EngineeringGnome, 30575, 85000, 202, 375, 0), -- Gnomish Battle Goggles
(@EngineeringGnome, 30570, 42500, 202, 350, 0), -- Nigh-Invulnerability Belt
(@EngineeringGnome, 30574, 85000, 202, 375, 0), -- Gnomish Power Goggles
(@EngineeringGnome, 12895, 1275, 202, 205, 0), -- Inlaid Mithril Cylinder Plans
(@EngineeringGnome, 12897, 1870, 202, 215, 0), -- Gnomish Goggles
(@EngineeringGnome, 12899, 1275, 202, 205, 0), -- Gnomish Shrink Ray
(@EngineeringGnome, 12903, 1700, 202, 215, 0), -- Gnomish Harm Prevention Belt
(@EngineeringGnome, 12905, 1275, 202, 210, 0), -- Gnomish Rocket Boots
(@EngineeringGnome, 12902, 1530, 202, 210, 0), -- Gnomish Net-o-Matic Projector
(@EngineeringGnome, 95705, 170000, 202, 500, 0), -- Gnomish Gravity Well
(@EngineeringGnome, 84413, 136000, 202, 475, 0); -- De-Weaponized Mechanical Companion
-- ----------------------------------------
-- -- Assign Professions to the Trainers --
-- ----------------------------------------
DELETE FROM `npc_trainer` WHERE `entry` IN (514, 812, 908, 996, 1103, 1215, 1218, 1241, 1292, 1317, 1346, 1384, 1385, 1386, 1458, 1470, 1473, 1546, 1632, 1676, 1681, 1701, 1702, 2114, 2132, 2133, 2222, 2390, 2391, 2399, 2627, 2836, 2837, 2856, 2998, 3001, 3004, 3007, 3009, 3011, 3013, 3069, 3071, 3136, 3137, 3174, 3175, 3184, 3185, 3290, 3345, 3347, 3355, 3357, 3363, 3365, 3404, 3478, 3484, 3494, 3523, 3549, 3555, 3557, 3603, 3604, 3605, 3606, 3703, 3704, 3964, 3965, 3967, 4159, 4160, 4193, 4204, 4212, 4213, 4254, 4258, 4576, 4578, 4588, 4596, 4598, 4611, 4614, 4616, 4888, 4898, 4900, 4941, 4998, 4999, 5032, 5033, 5037, 5038, 5040, 5041, 5127, 5137, 5153, 5157, 5164, 5174, 5177, 5392, 5499, 5502, 5511, 5513, 5518, 5564, 5566, 5695, 5784, 6242, 6287, 6288, 6289, 6290, 6291, 6292, 6295, 6297, 6299, 6306, 6387, 7087, 7088, 7089, 7174, 7230, 7231, 7232, 7525, 7526, 7528, 7866, 7867, 7868, 7869, 7870, 7871, 7948, 7949, 8128, 8144, 8146, 8153, 8736, 8777, 9584, 10993, 11017, 11025, 11031, 11037, 11052, 11072, 11073, 11074, 11097, 11098, 11177, 11178, 12020, 12025, 12030, 12035, 15400, 15465, 15501, 16000, 16160, 16161, 16190, 16265, 16273, 16278, 16366, 16487, 16527, 16583, 16588, 16633, 16640, 16642, 16644, 16663, 16667, 16669, 16688, 16692, 16723, 16724, 16725, 16726, 16728, 16729, 16736, 16752, 16763, 16823, 17215, 17222, 17434, 17441, 17442, 17487, 17488, 17634, 17637, 17983, 18747, 18748, 18749, 18751, 18752, 18753, 18754, 18755, 18771, 18772, 18773, 18774, 18775, 18776, 18777, 18779, 18802, 19052, 19063, 19180, 19187, 19251, 19252, 19341, 19539, 19540, 19576, 19775, 19778, 20124, 20125, 21087, 21209, 24868, 25099, 25263, 25277, 26564, 26903, 26904, 26906, 26907, 26910, 26911, 26912, 26913, 26914, 26915, 26916, 26951, 26952, 26954, 26955, 26958, 26959, 26960, 26961, 26962, 26963, 26964, 26969, 26974, 26975, 26976, 26977, 26980, 26981, 26982, 26986, 26987, 26988, 26990, 26991, 26994, 26995, 26996, 26997, 26998, 26999, 27000, 27001, 27023, 27029, 27034, 28400, 28693, 28694, 28696, 28697, 28698, 28699, 28700, 28701, 28702, 28703, 28704, 29505, 29506, 29507, 29508, 29509, 29924, 30706, 30709, 30710, 30711, 30713, 30715, 30716, 30717, 30721, 30722, 33580, 33581, 33583, 33586, 33588, 33590, 33591, 33603, 33630, 33631, 33633, 33634, 33635, 33636, 33637, 33638, 33639, 33640, 33641, 33674, 33675, 33676, 33677, 33678, 33679, 33680, 33681, 33682, 33683, 33684, 37072, 43428, 43429, 43431, 44582, 44781, 44782, 44783, 45545, 45548, 45559, 46357, 46675, 46716, 46741, 48685, 52170, 52586, 52587, 52636, 52640, 52642, 52645, 52651, 52657, 53437, 8126, 8738, 29513, 7406, 7944, 29514);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
-- Alchemy Trainers
(1215, -@Alchemy, 0, 0, 0, 0),
(1386, -@Alchemy, 0, 0, 0, 0),
(1470, -@Alchemy, 0, 0, 0, 0),
(2132, -@Alchemy, 0, 0, 0, 0),
(2391, -@Alchemy, 0, 0, 0, 0),
(2837, -@Alchemy, 0, 0, 0, 0),
(3009, -@Alchemy, 0, 0, 0, 0),
(3184, -@Alchemy, 0, 0, 0, 0),
(3347, -@Alchemy, 0, 0, 0, 0),
(3603, -@Alchemy, 0, 0, 0, 0),
(3964, -@Alchemy, 0, 0, 0, 0),
(4160, -@Alchemy, 0, 0, 0, 0),
(4611, -@Alchemy, 0, 0, 0, 0),
(4900, -@Alchemy, 0, 0, 0, 0),
(5177, -@Alchemy, 0, 0, 0, 0),
(5499, -@Alchemy, 0, 0, 0, 0),
(7948, -@Alchemy, 0, 0, 0, 0),
(16161, -@Alchemy, 0, 0, 0, 0),
(16588, -@Alchemy, 0, 0, 0, 0),
(16642, -@Alchemy, 0, 0, 0, 0),
(16723, -@Alchemy, 0, 0, 0, 0),
(18802, -@Alchemy, 0, 0, 0, 0),
(19052, -@Alchemy, 0, 0, 0, 0),
(5032, -@Alchemy, 0, 0, 0, 0),
(12020, -@Alchemy, 0, 0, 0, 0),
(16487, -@Alchemy, 0, 0, 0, 0),
(26987, -@Alchemy, 0, 0, 0, 0),
(26903, -@Alchemy, 0, 0, 0, 0),
(26951, -@Alchemy, 0, 0, 0, 0),
(26975, -@Alchemy, 0, 0, 0, 0),
(27023, -@Alchemy, 0, 0, 0, 0),
(27029, -@Alchemy, 0, 0, 0, 0),
(28703, -@Alchemy, 0, 0, 0, 0),
(33588, -@Alchemy, 0, 0, 0, 0),
(33630, -@Alchemy, 0, 0, 0, 0),
(33674, -@Alchemy, 0, 0, 0, 0),
-- Blacksmithing Trainers
(514, -@Blacksmithing, 0, 0, 0, 0),
(1241, -@Blacksmithing, 0, 0, 0, 0),
(2836, -@Blacksmithing, 0, 0, 0, 0),
(2998, -@Blacksmithing, 0, 0, 0, 0),
(3136, -@Blacksmithing, 0, 0, 0, 0),
(3174, -@Blacksmithing, 0, 0, 0, 0),
(3355, -@Blacksmithing, 0, 0, 0, 0),
(3478, -@Blacksmithing, 0, 0, 0, 0),
(3557, -@Blacksmithing, 0, 0, 0, 0),
(4258, -@Blacksmithing, 0, 0, 0, 0),
(4596, -@Blacksmithing, 0, 0, 0, 0),
(4888, -@Blacksmithing, 0, 0, 0, 0),
(5164, -@Blacksmithing, 0, 0, 0, 0),
(5511, -@Blacksmithing, 0, 0, 0, 0),
(6299, -@Blacksmithing, 0, 0, 0, 0),
(7230, -@Blacksmithing, 0, 0, 0, 0),
(7231, -@Blacksmithing, 0, 0, 0, 0),
(7232, -@Blacksmithing, 0, 0, 0, 0),
(11177, -@Blacksmithing, 0, 0, 0, 0),
(11178, -@Blacksmithing, 0, 0, 0, 0),
(15400, -@Blacksmithing, 0, 0, 0, 0),
(16583, -@Blacksmithing, 0, 0, 0, 0),
(16669, -@Blacksmithing, 0, 0, 0, 0),
(16724, -@Blacksmithing, 0, 0, 0, 0),
(16823, -@Blacksmithing, 0, 0, 0, 0),
(19341, -@Blacksmithing, 0, 0, 0, 0),
(20124, -@Blacksmithing, 0, 0, 0, 0),
(20125, -@Blacksmithing, 0, 0, 0, 0),
(21209, -@Blacksmithing, 0, 0, 0, 0),
(5033, -@Blacksmithing, 0, 0, 0, 0),
(7174, -@Blacksmithing, 0, 0, 0, 0),
(16265, -@Blacksmithing, 0, 0, 0, 0),
(26988, -@Blacksmithing, 0, 0, 0, 0),
(26564, -@Blacksmithing, 0, 0, 0, 0),
(26904, -@Blacksmithing, 0, 0, 0, 0),
(26952, -@Blacksmithing, 0, 0, 0, 0),
(26981, -@Blacksmithing, 0, 0, 0, 0),
(27034, -@Blacksmithing, 0, 0, 0, 0),
(28694, -@Blacksmithing, 0, 0, 0, 0),
(29505, -@Blacksmithing, 0, 0, 0, 0),
(29506, -@Blacksmithing, 0, 0, 0, 0),
(29924, -@Blacksmithing, 0, 0, 0, 0),
(33591, -@Blacksmithing, 0, 0, 0, 0),
(33631, -@Blacksmithing, 0, 0, 0, 0),
(33675, -@Blacksmithing, 0, 0, 0, 0),
(37072, -@Blacksmithing, 0, 0, 0, 0),
(44781, -@Blacksmithing, 0, 0, 0, 0),
(45548, -@Blacksmithing, 0, 0, 0, 0),
(52640, -@Blacksmithing, 0, 0, 0, 0),
-- Enchanting Trainers
(1317, -@Enchanting, 0, 0, 0, 0),
(3011, -@Enchanting, 0, 0, 0, 0),
(3345, -@Enchanting, 0, 0, 0, 0),
(3606, -@Enchanting, 0, 0, 0, 0),
(4213, -@Enchanting, 0, 0, 0, 0),
(4616, -@Enchanting, 0, 0, 0, 0),
(5157, -@Enchanting, 0, 0, 0, 0),
(5695, -@Enchanting, 0, 0, 0, 0),
(7949, -@Enchanting, 0, 0, 0, 0),
(11072, -@Enchanting, 0, 0, 0, 0),
(11073, -@Enchanting, 0, 0, 0, 0),
(11074, -@Enchanting, 0, 0, 0, 0),
(16160, -@Enchanting, 0, 0, 0, 0),
(16633, -@Enchanting, 0, 0, 0, 0),
(16725, -@Enchanting, 0, 0, 0, 0),
(18753, -@Enchanting, 0, 0, 0, 0),
(18773, -@Enchanting, 0, 0, 0, 0),
(19251, -@Enchanting, 0, 0, 0, 0),
(19252, -@Enchanting, 0, 0, 0, 0),
(19540, -@Enchanting, 0, 0, 0, 0),
(5038, -@Enchanting, 0, 0, 0, 0),
(16190, -@Enchanting, 0, 0, 0, 0),
(26990, -@Enchanting, 0, 0, 0, 0),
(26906, -@Enchanting, 0, 0, 0, 0),
(26954, -@Enchanting, 0, 0, 0, 0),
(26980, -@Enchanting, 0, 0, 0, 0),
(28693, -@Enchanting, 0, 0, 0, 0),
(33583, -@Enchanting, 0, 0, 0, 0),
(33633, -@Enchanting, 0, 0, 0, 0),
(33676, -@Enchanting, 0, 0, 0, 0),
(48685, -@Enchanting, 0, 0, 0, 0),
-- Engineering Trainers
(1676, -@Engineering, 0, 0, 0, 0),
(1702, -@Engineering, 0, 0, 0, 0),
(3290, -@Engineering, 0, 0, 0, 0),
(3494, -@Engineering, 0, 0, 0, 0),
(4941, -@Engineering, 0, 0, 0, 0),
(5174, -@Engineering, 0, 0, 0, 0),
(5518, -@Engineering, 0, 0, 0, 0),
(8736, -@Engineering, 0, 0, 0, 0),
(10993, -@Engineering, 0, 0, 0, 0),
(11017, -@Engineering, 0, 0, 0, 0),
(11025, -@Engineering, 0, 0, 0, 0),
(11031, -@Engineering, 0, 0, 0, 0),
(11037, -@Engineering, 0, 0, 0, 0),
(16667, -@Engineering, 0, 0, 0, 0),
(16726, -@Engineering, 0, 0, 0, 0),
(17222, -@Engineering, 0, 0, 0, 0),
(17634, -@Engineering, 0, 0, 0, 0),
(17637, -@Engineering, 0, 0, 0, 0),
(18752, -@Engineering, 0, 0, 0, 0),
(18775, -@Engineering, 0, 0, 0, 0),
(19576, -@Engineering, 0, 0, 0, 0),
(5037, -@Engineering, 0, 0, 0, 0),
(24868, -@Engineering, 0, 0, 0, 0),
(25099, -@Engineering, 0, 0, 0, 0),
(26991, -@Engineering, 0, 0, 0, 0),
(25277, -@Engineering, 0, 0, 0, 0),
(26907, -@Engineering, 0, 0, 0, 0),
(26955, -@Engineering, 0, 0, 0, 0),
(28697, -@Engineering, 0, 0, 0, 0),
(33586, -@Engineering, 0, 0, 0, 0),
(33634, -@Engineering, 0, 0, 0, 0),
(33677, -@Engineering, 0, 0, 0, 0),
(45545, -@Engineering, 0, 0, 0, 0),
(52636, -@Engineering, 0, 0, 0, 0),
(52651, -@Engineering, 0, 0, 0, 0),
-- Herbalism Trainers
(812, -@Herbalism, 0, 0, 0, 0),
(908, -@Herbalism, 0, 0, 0, 0),
(1218, -@Herbalism, 0, 0, 0, 0),
(1458, -@Herbalism, 0, 0, 0, 0),
(1473, -@Herbalism, 0, 0, 0, 0),
(2114, -@Herbalism, 0, 0, 0, 0),
(2390, -@Herbalism, 0, 0, 0, 0),
(2856, -@Herbalism, 0, 0, 0, 0),
(3013, -@Herbalism, 0, 0, 0, 0),
(3185, -@Herbalism, 0, 0, 0, 0),
(3404, -@Herbalism, 0, 0, 0, 0),
(3604, -@Herbalism, 0, 0, 0, 0),
(3965, -@Herbalism, 0, 0, 0, 0),
(4204, -@Herbalism, 0, 0, 0, 0),
(4614, -@Herbalism, 0, 0, 0, 0),
(4898, -@Herbalism, 0, 0, 0, 0),
(5137, -@Herbalism, 0, 0, 0, 0),
(5502, -@Herbalism, 0, 0, 0, 0),
(5566, -@Herbalism, 0, 0, 0, 0),
(8146, -@Herbalism, 0, 0, 0, 0),
(12025, -@Herbalism, 0, 0, 0, 0),
(16644, -@Herbalism, 0, 0, 0, 0),
(16736, -@Herbalism, 0, 0, 0, 0),
(17434, -@Herbalism, 0, 0, 0, 0),
(17983, -@Herbalism, 0, 0, 0, 0),
(18748, -@Herbalism, 0, 0, 0, 0),
(18776, -@Herbalism, 0, 0, 0, 0),
(4998, -@Herbalism, 0, 0, 0, 0),
(16527, -@Herbalism, 0, 0, 0, 0),
(1546, -@Herbalism, 0, 0, 0, 0),
(2133, -@Herbalism, 0, 0, 0, 0),
(3071, -@Herbalism, 0, 0, 0, 0),
(26994, -@Herbalism, 0, 0, 0, 0),
(26910, -@Herbalism, 0, 0, 0, 0),
(26958, -@Herbalism, 0, 0, 0, 0),
(26974, -@Herbalism, 0, 0, 0, 0),
(28704, -@Herbalism, 0, 0, 0, 0),
(33639, -@Herbalism, 0, 0, 0, 0),
(33678, -@Herbalism, 0, 0, 0, 0),
(46741, -@Herbalism, 0, 0, 0, 0),
-- Inscription Trainers
(30721, -@Inscription, 0, 0, 0, 0),
(30713, -@Inscription, 0, 0, 0, 0),
(26995, -@Inscription, 0, 0, 0, 0),
(25263, -@Inscription, 0, 0, 0, 0),
(26916, -@Inscription, 0, 0, 0, 0),
(26959, -@Inscription, 0, 0, 0, 0),
(26977, -@Inscription, 0, 0, 0, 0),
(28702, -@Inscription, 0, 0, 0, 0),
(30706, -@Inscription, 0, 0, 0, 0),
(30709, -@Inscription, 0, 0, 0, 0),
(30710, -@Inscription, 0, 0, 0, 0),
(30711, -@Inscription, 0, 0, 0, 0),
(30715, -@Inscription, 0, 0, 0, 0),
(30716, -@Inscription, 0, 0, 0, 0),
(30717, -@Inscription, 0, 0, 0, 0),
(30722, -@Inscription, 0, 0, 0, 0),
(33603, -@Inscription, 0, 0, 0, 0),
(33638, -@Inscription, 0, 0, 0, 0),
(33679, -@Inscription, 0, 0, 0, 0),
(46716, -@Inscription, 0, 0, 0, 0),
-- Jewelcrafting Trainers
(15501, -@Jewelcrafting, 0, 0, 0, 0),
(18751, -@Jewelcrafting, 0, 0, 0, 0),
(18774, -@Jewelcrafting, 0, 0, 0, 0),
(19063, -@Jewelcrafting, 0, 0, 0, 0),
(19539, -@Jewelcrafting, 0, 0, 0, 0),
(19775, -@Jewelcrafting, 0, 0, 0, 0),
(19778, -@Jewelcrafting, 0, 0, 0, 0),
(15465, -@Jewelcrafting, 0, 0, 0, 0),
(26997, -@Jewelcrafting, 0, 0, 0, 0),
(26915, -@Jewelcrafting, 0, 0, 0, 0),
(26960, -@Jewelcrafting, 0, 0, 0, 0),
(26982, -@Jewelcrafting, 0, 0, 0, 0),
(28701, -@Jewelcrafting, 0, 0, 0, 0),
(33590, -@Jewelcrafting, 0, 0, 0, 0),
(33637, -@Jewelcrafting, 0, 0, 0, 0),
(33680, -@Jewelcrafting, 0, 0, 0, 0),
(44582, -@Jewelcrafting, 0, 0, 0, 0),
(46675, -@Jewelcrafting, 0, 0, 0, 0),
(52586, -@Jewelcrafting, 0, 0, 0, 0),
(52587, -@Jewelcrafting, 0, 0, 0, 0),
(52645, -@Jewelcrafting, 0, 0, 0, 0),
(52657, -@Jewelcrafting, 0, 0, 0, 0),
-- Leatherworking Trainers
(1385, -@Leatherworking, 0, 0, 0, 0),
(1632, -@Leatherworking, 0, 0, 0, 0),
(3007, -@Leatherworking, 0, 0, 0, 0),
(3069, -@Leatherworking, 0, 0, 0, 0),
(3365, -@Leatherworking, 0, 0, 0, 0),
(3549, -@Leatherworking, 0, 0, 0, 0),
(3605, -@Leatherworking, 0, 0, 0, 0),
(3703, -@Leatherworking, 0, 0, 0, 0),
(3967, -@Leatherworking, 0, 0, 0, 0),
(4212, -@Leatherworking, 0, 0, 0, 0),
(4588, -@Leatherworking, 0, 0, 0, 0),
(5127, -@Leatherworking, 0, 0, 0, 0),
(5564, -@Leatherworking, 0, 0, 0, 0),
(5784, -@Leatherworking, 0, 0, 0, 0),
(7866, -@Leatherworking, 0, 0, 0, 0),
(7867, -@Leatherworking, 0, 0, 0, 0),
(7868, -@Leatherworking, 0, 0, 0, 0),
(7869, -@Leatherworking, 0, 0, 0, 0),
(7870, -@Leatherworking, 0, 0, 0, 0),
(7871, -@Leatherworking, 0, 0, 0, 0),
(8153, -@Leatherworking, 0, 0, 0, 0),
(11097, -@Leatherworking, 0, 0, 0, 0),
(11098, -@Leatherworking, 0, 0, 0, 0),
(16278, -@Leatherworking, 0, 0, 0, 0),
(16688, -@Leatherworking, 0, 0, 0, 0),
(16728, -@Leatherworking, 0, 0, 0, 0),
(17442, -@Leatherworking, 0, 0, 0, 0),
(18754, -@Leatherworking, 0, 0, 0, 0),
(18771, -@Leatherworking, 0, 0, 0, 0),
(19187, -@Leatherworking, 0, 0, 0, 0),
(21087, -@Leatherworking, 0, 0, 0, 0),
(5040, -@Leatherworking, 0, 0, 0, 0),
(7525, -@Leatherworking, 0, 0, 0, 0),
(7526, -@Leatherworking, 0, 0, 0, 0),
(7528, -@Leatherworking, 0, 0, 0, 0),
(26998, -@Leatherworking, 0, 0, 0, 0),
(26911, -@Leatherworking, 0, 0, 0, 0),
(26961, -@Leatherworking, 0, 0, 0, 0),
(26996, -@Leatherworking, 0, 0, 0, 0),
(28400, -@Leatherworking, 0, 0, 0, 0),
(28700, -@Leatherworking, 0, 0, 0, 0),
(29507, -@Leatherworking, 0, 0, 0, 0),
(29508, -@Leatherworking, 0, 0, 0, 0),
(29509, -@Leatherworking, 0, 0, 0, 0),
(33581, -@Leatherworking, 0, 0, 0, 0),
(33635, -@Leatherworking, 0, 0, 0, 0),
(33681, -@Leatherworking, 0, 0, 0, 0),
-- Mining Trainers
(1681, -@Mining, 0, 0, 0, 0),
(1701, -@Mining, 0, 0, 0, 0),
(3001, -@Mining, 0, 0, 0, 0),
(3137, -@Mining, 0, 0, 0, 0),
(3175, -@Mining, 0, 0, 0, 0),
(3357, -@Mining, 0, 0, 0, 0),
(3555, -@Mining, 0, 0, 0, 0),
(4254, -@Mining, 0, 0, 0, 0),
(4598, -@Mining, 0, 0, 0, 0),
(5392, -@Mining, 0, 0, 0, 0),
(5513, -@Mining, 0, 0, 0, 0),
(6297, -@Mining, 0, 0, 0, 0),
(8128, -@Mining, 0, 0, 0, 0),
(16663, -@Mining, 0, 0, 0, 0),
(16752, -@Mining, 0, 0, 0, 0),
(17488, -@Mining, 0, 0, 0, 0),
(18747, -@Mining, 0, 0, 0, 0),
(18779, -@Mining, 0, 0, 0, 0),
(1384, -@Mining, 0, 0, 0, 0),
(2222, -@Mining, 0, 0, 0, 0),
(4999, -@Mining, 0, 0, 0, 0),
(12035, -@Mining, 0, 0, 0, 0),
(26999, -@Mining, 0, 0, 0, 0),
(26912, -@Mining, 0, 0, 0, 0),
(26962, -@Mining, 0, 0, 0, 0),
(26976, -@Mining, 0, 0, 0, 0),
(28698, -@Mining, 0, 0, 0, 0),
(33640, -@Mining, 0, 0, 0, 0),
(33682, -@Mining, 0, 0, 0, 0),
(43431, -@Mining, 0, 0, 0, 0),
(46357, -@Mining, 0, 0, 0, 0),
(52170, -@Mining, 0, 0, 0, 0),
(52642, -@Mining, 0, 0, 0, 0),
-- Skinning Trainers
(1292, -@Skinning, 0, 0, 0, 0),
(6287, -@Skinning, 0, 0, 0, 0),
(6288, -@Skinning, 0, 0, 0, 0),
(6289, -@Skinning, 0, 0, 0, 0),
(6290, -@Skinning, 0, 0, 0, 0),
(6291, -@Skinning, 0, 0, 0, 0),
(6292, -@Skinning, 0, 0, 0, 0),
(6295, -@Skinning, 0, 0, 0, 0),
(6306, -@Skinning, 0, 0, 0, 0),
(6387, -@Skinning, 0, 0, 0, 0),
(7087, -@Skinning, 0, 0, 0, 0),
(7088, -@Skinning, 0, 0, 0, 0),
(7089, -@Skinning, 0, 0, 0, 0),
(8144, -@Skinning, 0, 0, 0, 0),
(12030, -@Skinning, 0, 0, 0, 0),
(16273, -@Skinning, 0, 0, 0, 0),
(16692, -@Skinning, 0, 0, 0, 0),
(16763, -@Skinning, 0, 0, 0, 0),
(17441, -@Skinning, 0, 0, 0, 0),
(18755, -@Skinning, 0, 0, 0, 0),
(18777, -@Skinning, 0, 0, 0, 0),
(19180, -@Skinning, 0, 0, 0, 0),
(6242, -@Skinning, 0, 0, 0, 0),
(8777, -@Skinning, 0, 0, 0, 0),
(27000, -@Skinning, 0, 0, 0, 0),
(26913, -@Skinning, 0, 0, 0, 0),
(26963, -@Skinning, 0, 0, 0, 0),
(26986, -@Skinning, 0, 0, 0, 0),
(28696, -@Skinning, 0, 0, 0, 0),
(33641, -@Skinning, 0, 0, 0, 0),
(33683, -@Skinning, 0, 0, 0, 0),
(44782, -@Skinning, 0, 0, 0, 0),
(53437, -@Skinning, 0, 0, 0, 0),
-- Tailoring Trainers
(1103, -@Tailoring, 0, 0, 0, 0),
(1346, -@Tailoring, 0, 0, 0, 0),
(2399, -@Tailoring, 0, 0, 0, 0),
(2627, -@Tailoring, 0, 0, 0, 0),
(3004, -@Tailoring, 0, 0, 0, 0),
(3363, -@Tailoring, 0, 0, 0, 0),
(3484, -@Tailoring, 0, 0, 0, 0),
(3523, -@Tailoring, 0, 0, 0, 0),
(3704, -@Tailoring, 0, 0, 0, 0),
(4159, -@Tailoring, 0, 0, 0, 0),
(4193, -@Tailoring, 0, 0, 0, 0),
(4576, -@Tailoring, 0, 0, 0, 0),
(4578, -@Tailoring, 0, 0, 0, 0),
(5153, -@Tailoring, 0, 0, 0, 0),
(9584, -@Tailoring, 0, 0, 0, 0),
(11052, -@Tailoring, 0, 0, 0, 0),
(16366, -@Tailoring, 0, 0, 0, 0),
(16640, -@Tailoring, 0, 0, 0, 0),
(16729, -@Tailoring, 0, 0, 0, 0),
(17487, -@Tailoring, 0, 0, 0, 0),
(18749, -@Tailoring, 0, 0, 0, 0),
(18772, -@Tailoring, 0, 0, 0, 0),
(996, -@Tailoring, 0, 0, 0, 0),
(5041, -@Tailoring, 0, 0, 0, 0),
(16000, -@Tailoring, 0, 0, 0, 0),
(27001, -@Tailoring, 0, 0, 0, 0),
(26914, -@Tailoring, 0, 0, 0, 0),
(26964, -@Tailoring, 0, 0, 0, 0),
(26969, -@Tailoring, 0, 0, 0, 0),
(28699, -@Tailoring, 0, 0, 0, 0),
(33580, -@Tailoring, 0, 0, 0, 0),
(33636, -@Tailoring, 0, 0, 0, 0),
(33684, -@Tailoring, 0, 0, 0, 0),
(44783, -@Tailoring, 0, 0, 0, 0),
(45559, -@Tailoring, 0, 0, 0, 0),
-- Goblin Engineering Trainers
(8126, -@EngineeringGoblin, 0, 0, 0, 0),
(8738, -@EngineeringGoblin, 0, 0, 0, 0),
(29513, -@EngineeringGoblin, 0, 0, 0, 0),
-- Gnomish Engineering Trainers
(7406, -@EngineeringGnome, 0, 0, 0, 0),
(7944, -@EngineeringGnome, 0, 0, 0, 0),
(29514, -@EngineeringGnome, 0, 0, 0, 0);
-- -------------------------------------
-- -- Journeyman Professions Trainers --
-- -------------------------------------
DELETE FROM `npc_trainer` WHERE `entry` IN (17215, 43429, 43428);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
-- Alchemy
(17215, 7841, 1000, 171, 100, 0), -- Swim Speed Potion
(17215, 7845, 3000, 171, 140, 0), -- Elixir of Firepower
(17215, 2280, 500, 171, 50, 10), -- Journeyman Alchemist
(17215, 63732, 2000, 171, 135, 0), -- Elixir of Minor Accuracy
(17215, 3171, 500, 171, 90, 0), -- Elixir of Wisdom
(17215, 3173, 1500, 171, 120, 0), -- Lesser Mana Potion
(17215, 3176, 1500, 171, 125, 0), -- Strong Troll's Blood Elixir
(17215, 3177, 2000, 171, 130, 0), -- Elixir of Defense
(17215, 3447, 4000, 171, 110, 0), -- Healing Potion
(17215, 7179, 450, 171, 90, 0), -- Elixir of Water Breathing
(17215, 7837, 1000, 171, 130, 0), -- Fire Oil
(17215, 7836, 250, 171, 80, 0), -- Blackmouth Oil
(17215, 2275, 10, 0, 0, 5), -- Apprentice Alchemist
(17215, 2331, 100, 171, 25, 0), -- Minor Mana Potion
(17215, 2332, 150, 171, 40, 0), -- Minor Rejuvenation Potion
(17215, 2337, 1000, 171, 55, 0), -- Lesser Healing Potion
(17215, 3170, 50, 171, 15, 0), -- Weak Troll's Blood Elixir
(17215, 2334, 250, 171, 50, 0), -- Elixir of Minor Fortitude
-- Blacksmithing
(43429, 2664, 500, 164, 90, 0), -- Runed Copper Bracers
(43429, 2740, 200, 164, 110, 0), -- Bronze Mace
(43429, 2741, 200, 164, 115, 0), -- Bronze Axe
(43429, 2742, 200, 164, 120, 0), -- Bronze Shortsword
(43429, 2668, 300, 164, 105, 0), -- Rough Bronze Leggings
(43429, 2670, 500, 164, 105, 0), -- Rough Bronze Cuirass
(43429, 2672, 500, 164, 120, 0), -- Patterned Bronze Bracers
(43429, 2674, 1000, 164, 125, 0), -- Heavy Sharpening Stone
(43429, 2675, 1000, 164, 145, 0), -- Shining Silver Breastplate
(43429, 3117, 1000, 164, 125, 0), -- Heavy Weightstone
(43429, 3292, 500, 164, 95, 0), -- Heavy Copper Broadsword
(43429, 3328, 500, 164, 110, 0), -- Rough Bronze Shoulders
(43429, 3331, 500, 164, 130, 0), -- Silvered Bronze Boots
(43429, 7818, 100, 164, 100, 0), -- Silver Rod
(43429, 8768, 250, 164, 150, 0), -- Iron Buckle
(43429, 6517, 800, 164, 110, 0), -- Pearl-handled Dagger
(43429, 7817, 200, 164, 95, 0), -- Rough Bronze Boots
(43429, 19666, 100, 164, 100, 0), -- Silver Skeleton Key
(43429, 9985, 250, 164, 125, 0), -- Bronze Warhammer
(43429, 9986, 500, 164, 130, 0), -- Bronze Greatsword
(43429, 9987, 500, 164, 135, 0), -- Bronze Battle Axe
(43429, 2021, 500, 164, 50, 10), -- Journeyman Blacksmith
(43429, 3333, 1000, 164, 135, 0), -- Silvered Bronze Gauntlets
(43429, 3337, 1000, 164, 125, 0), -- Heavy Grinding Stone
(43429, 3491, 600, 164, 105, 0), -- Big Bronze Knife
(43429, 19667, 250, 164, 150, 0), -- Golden Skeleton Key
(43429, 34979, 600, 164, 100, 0), -- Thick Bronze Darts
(43429, 14379, 250, 164, 150, 0), -- Golden Rod
(43429, 3296, 1000, 164, 130, 0), -- Heavy Bronze Mace
(43429, 2661, 100, 164, 35, 0), -- Copper Chain Belt
(43429, 2665, 100, 164, 65, 0), -- Coarse Sharpening Stone
(43429, 2666, 200, 164, 70, 0), -- Runed Copper Belt
(43429, 3116, 100, 164, 65, 0), -- Coarse Weightstone
(43429, 3293, 250, 164, 35, 0), -- Copper Battle Axe
(43429, 3323, 100, 164, 40, 0), -- Runed Copper Gauntlets
(43429, 3324, 200, 164, 45, 0), -- Runed Copper Pants
(43429, 3326, 250, 164, 75, 0), -- Coarse Grinding Stone
(43429, 7408, 300, 164, 65, 0), -- Heavy Copper Maul
(43429, 8880, 100, 164, 30, 0), -- Copper Dagger
(43429, 2738, 50, 164, 20, 0), -- Copper Axe
(43429, 2739, 50, 164, 25, 0), -- Copper Shortsword
(43429, 9983, 100, 164, 30, 0), -- Copper Claymore
(43429, 2020, 10, 0, 0, 5), -- Apprentice Blacksmith
(43429, 2662, 50, 164, 1, 0), -- Copper Chain Pants
(43429, 2737, 50, 164, 15, 0), -- Copper Mace
(43429, 3320, 100, 164, 25, 0), -- Rough Grinding Stone
(43429, 3294, 500, 164, 70, 0), -- Thick War Axe
(43429, 3319, 50, 164, 20, 0), -- Copper Chain Boots
-- Tailoring
(43428, 3845, 300, 197, 80, 0), -- Soft-soled Linen Boots
(43428, 6521, 400, 197, 90, 0), -- Pearl-clasped Cloak
(43428, 3813, 800, 197, 150, 0), -- Small Silk Pack
(43428, 3757, 200, 197, 80, 0), -- Woolen Bag
(43428, 6690, 1000, 197, 135, 0), -- Lesser Wizard's Robe
(43428, 8467, 250, 197, 110, 0), -- White Woolen Dress
(43428, 8758, 600, 197, 140, 0), -- Azure Silk Pants
(43428, 8760, 600, 197, 145, 0), -- Azure Silk Hood
(43428, 3859, 750, 197, 150, 0), -- Azure Silk Vest
(43428, 3839, 500, 197, 125, 0), -- Bolt of Silk Cloth
(43428, 3852, 750, 197, 130, 0), -- Gloves of Meditation
(43428, 63742, 750, 197, 125, 0), -- Spidersilk Drape
(43428, 3912, 500, 197, 50, 10), -- Journeyman Tailor
(43428, 3843, 400, 197, 85, 0), -- Heavy Woolen Gloves
(43428, 2399, 300, 197, 85, 0), -- Green Woolen Vest
(43428, 2401, 300, 197, 95, 0), -- Woolen Boots
(43428, 2406, 200, 197, 100, 0), -- Gray Woolen Shirt
(43428, 3848, 500, 197, 110, 0), -- Double-stitched Woolen Shoulders
(43428, 3850, 500, 197, 110, 0), -- Heavy Woolen Pants
(43428, 3866, 250, 197, 110, 0), -- Stylish Red Shirt
(43428, 3855, 750, 197, 125, 0), -- Spidersilk Boots
(43428, 2395, 300, 197, 70, 0), -- Barbaric Linen Vest
(43428, 2397, 200, 197, 60, 0), -- Reinforced Linen Cape
(43428, 3842, 300, 197, 70, 0), -- Handstitched Linen Britches
(43428, 2396, 200, 197, 70, 0), -- Green Linen Shirt
(43428, 2964, 100, 197, 75, 0), -- Bolt of Woolen Cloth
(43428, 2402, 250, 197, 75, 0), -- Woolen Cape
(43428, 12045, 50, 197, 20, 0), -- Simple Linen Boots
(43428, 12046, 300, 197, 75, 0), -- Simple Kilt
(43428, 3755, 100, 197, 45, 0), -- Linen Bag
(43428, 7623, 50, 197, 30, 0), -- Brown Linen Robe
(43428, 7624, 50, 197, 30, 0), -- White Linen Robe
(43428, 8465, 50, 197, 40, 0), -- Simple Dress
(43428, 8776, 50, 197, 15, 0), -- Linen Belt
(43428, 3914, 50, 197, 30, 0), -- Brown Linen Pants
(43428, 2385, 50, 197, 10, 0), -- Brown Linen Vest
(43428, 3840, 100, 197, 35, 0), -- Heavy Linen Gloves
(43428, 2386, 200, 197, 65, 0), -- Linen Boots
(43428, 2392, 50, 197, 40, 0), -- Red Linen Shirt
(43428, 2393, 25, 197, 1, 0), -- White Linen Shirt
(43428, 2394, 50, 197, 40, 0), -- Blue Linen Shirt
(43428, 3841, 200, 197, 60, 0), -- Green Linen Bracers
(43428, 3911, 10, 0, 0, 5); -- Apprentice Tailor
