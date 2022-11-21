-- Delete old Heirloom Vendors
DELETE FROM `creature` WHERE `guid` IN (88108, 85227);

-- Update Magister Arlan position
UPDATE `creature` SET `position_x`=5939.97119140625, `position_y`=505.539947509765625, `position_z`=650.2626953125, `orientation`=2.356194496154785156 WHERE `guid` = 202582;

-- Update Alliance Legacy Quartermaster in Dalaran-Northrend
DELETE FROM `npc_vendor` WHERE `entry` IN (35494, 37942, 33964, 31579, 31580);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(35494, 109, 41959, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Silk Trousers
(35494, 108, 41953, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Silk Raiment
(35494, 107, 41971, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Silk Handguards
(35494, 106, 41946, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Silk Cowl
(35494, 105, 41965, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Silk Amice
(35494, 29, 47735, 0, 0, 1, 0, 0, 45745), -- Glyph of Indomitability
(35494, 28, 47734, 0, 0, 1, 0, 0, 45745), -- Mark of Supremacy
(35494, 27, 48724, 0, 0, 1, 0, 0, 45745), -- Talisman of Resurgence
(35494, 26, 48722, 0, 0, 1, 0, 0, 45745), -- Shard of the Crystal Heart
(35494, 25, 47731, 0, 0, 1, 0, 0, 45745), -- Clutch of Fortification
(35494, 24, 47729, 0, 0, 1, 0, 0, 45745), -- Bloodshed Band
(35494, 23, 47730, 0, 0, 1, 0, 0, 45745), -- Dexterous Brightstone Ring
(35494, 22, 47733, 0, 0, 1, 0, 0, 45745), -- Heartmender Circle
(35494, 21, 47732, 0, 0, 1, 0, 0, 45745), -- Band of the Invoker
(35494, 20, 47707, 0, 0, 1, 0, 0, 45745), -- Mantle of the Groundbreaker
(35494, 19, 47708, 0, 0, 1, 0, 0, 45745), -- Duskstalker Shoulderpads
(35494, 18, 47715, 0, 0, 1, 0, 0, 45745), -- Pauldrons of Revered Mortality
(35494, 17, 47698, 0, 0, 1, 0, 0, 45745), -- Shoulderplates of Enduring Order
(35494, 16, 47697, 0, 0, 1, 0, 0, 45745), -- Pauldrons of Trembling Rage
(35494, 15, 47702, 0, 0, 1, 0, 0, 45745), -- Pauldrons of the Cavalier
(35494, 14, 47704, 0, 0, 1, 0, 0, 45745), -- Epaulets of the Devourer
(35494, 13, 47712, 0, 0, 1, 0, 0, 45745), -- Shoulders of the Fateful Accord
(35494, 12, 47713, 0, 0, 1, 0, 0, 45745), -- Mantle of Catastrophic Emanation
(35494, 11, 47686, 0, 0, 1, 0, 0, 45745), -- Helm of Inner Warmth
(35494, 10, 47689, 0, 0, 1, 0, 0, 45745), -- Hood of Lethal Intent
(35494, 9, 47694, 0, 0, 1, 0, 0, 45745), -- Helm of Clouded Sight
(35494, 8, 47677, 0, 0, 1, 0, 0, 45745), -- Faceplate of the Honorbound
(35494, 7, 47674, 0, 0, 1, 0, 0, 45745), -- Helm of Thunderous Rampage
(35494, 6, 47681, 0, 0, 1, 0, 0, 45745), -- Heaume of the Restless Watch
(35494, 5, 47685, 0, 0, 1, 0, 0, 45745), -- Helm of the Brooding Dragon
(35494, 4, 47690, 0, 0, 1, 0, 0, 45745), -- Helm of Abundant Growth
(35494, 3, 47693, 0, 0, 1, 0, 0, 45745), -- Hood of Fiery Aftermath
(35494, 2, 47658, 0, 0, 1, 0, 0, 45745), -- Brimstone Igniter
(35494, 1, 47556, 0, 0, 1, 0, 0, 45745), -- Crusader Orb
(37942, 102, 41966, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Silk Amice
(37942, 101, 41960, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Silk Trousers
(37942, 100, 41947, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Silk Cowl
(37942, 99, 41972, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Silk Handguards
(37942, 98, 41954, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Silk Raiment
(37942, 37, 49908, 0, 0, 1, 0, 0, 45745), -- Primordial Saronite
(37942, 36, 50997, 0, 0, 1, 0, 0, 45745), -- Circle of Ossus
(37942, 35, 50996, 0, 0, 1, 0, 0, 45745), -- Belt of Omission
(37942, 34, 50995, 0, 0, 1, 0, 0, 45745), -- Vengeful Noose
(37942, 33, 50994, 0, 0, 1, 0, 0, 45745), -- Belt of Petrified Ivy
(37942, 32, 50993, 0, 0, 1, 0, 0, 45745), -- Band of the Night Raven
(37942, 31, 50992, 0, 0, 1, 0, 0, 45745), -- Waistband of Despair
(37942, 30, 50991, 0, 0, 1, 0, 0, 45745), -- Verdigris Chain Belt
(37942, 29, 50989, 0, 0, 1, 0, 0, 45745), -- Lich Killer's Lanyard
(37942, 28, 50987, 0, 0, 1, 0, 0, 45745), -- Malevolent Girdle
(37942, 27, 50984, 0, 0, 1, 0, 0, 45745), -- Gloves of Ambivalence
(37942, 26, 50983, 0, 0, 1, 0, 0, 45745), -- Gloves of False Gestures
(37942, 25, 50982, 0, 0, 1, 0, 0, 45745), -- Cat Burglar's Grips
(37942, 24, 50981, 0, 0, 1, 0, 0, 45745), -- Gloves of the Great Horned Owl
(37942, 23, 50980, 0, 0, 1, 0, 0, 45745), -- Blizzard Keeper's Mitts
(37942, 22, 50979, 0, 0, 1, 0, 0, 45745), -- Logsplitters
(37942, 21, 50978, 0, 0, 1, 0, 0, 45745), -- Gauntlets of the Kraken
(37942, 20, 50977, 0, 0, 1, 0, 0, 45745), -- Gatecrasher's Gauntlets
(37942, 19, 50976, 0, 0, 1, 0, 0, 45745), -- Gauntlets of Overexposure
(37942, 18, 50975, 0, 0, 1, 0, 0, 45745), -- Ermine Coronation Robes
(37942, 17, 50974, 0, 0, 1, 0, 0, 45745), -- Meteor Chaser's Raiment
(37942, 16, 50973, 0, 0, 1, 0, 0, 45745), -- Vestments of Spruce and Fir
(37942, 15, 50972, 0, 0, 1, 0, 0, 45745), -- Shadow Seeker's Tunic
(37942, 14, 50971, 0, 0, 1, 0, 0, 45745), -- Mail of the Geyser
(37942, 13, 50970, 0, 0, 1, 0, 0, 45745), -- Longstrider's Vest
(37942, 12, 50969, 0, 0, 1, 0, 0, 45745), -- Chestplate of Unspoken Truths
(37942, 11, 50968, 0, 0, 1, 0, 0, 45745), -- Cataclysmic Chestguard
(37942, 10, 50965, 0, 0, 1, 0, 0, 45745), -- Castle Breaker's Battleplate
(37942, 9, 50470, 0, 0, 1, 0, 0, 45745), -- Recovered Scarlet Onslaught Cape
(37942, 8, 50469, 0, 0, 1, 0, 0, 45745), -- Volde's Cloak of the Night Sky
(37942, 7, 50468, 0, 0, 1, 0, 0, 45745), -- Drape of the Violet Tower
(37942, 6, 50467, 0, 0, 1, 0, 0, 45745), -- Might of the Ocean Serpent
(37942, 5, 50466, 0, 0, 1, 0, 0, 45745), -- Sentinel's Winter Cloak
(37942, 4, 50358, 0, 0, 1, 0, 0, 45745), -- Purified Lunar Dust
(37942, 3, 50357, 0, 0, 1, 0, 0, 45745), -- Maghia's Misguided Quill
(37942, 2, 50356, 0, 0, 1, 0, 0, 45745), -- Corroded Skeleton Key
(37942, 1, 50355, 0, 0, 1, 0, 0, 45745), -- Herkuml War Token
(33964, 115, 41970, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Silk Handguards
(33964, 99, 41964, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Silk Amice
(33964, 83, 41945, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Silk Cowl
(33964, 67, 41958, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Silk Trousers
(33964, 52, 41951, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Silk Raiment
(33964, 36, 45640, 0, 0, 1, 0, 0, 45745), -- Crown of the Wayward Vanquisher
(33964, 33, 45634, 0, 0, 1, 0, 0, 45745), -- Breastplate of the Wayward Vanquisher
(33964, 30, 45842, 0, 0, 1, 0, 0, 45745), -- Wyrmguard Legplates
(33964, 29, 45841, 0, 0, 1, 0, 0, 45745), -- Legplates of the Violet Champion
(33964, 28, 45843, 0, 0, 1, 0, 0, 45745), -- Legguards of the Peaceful Covenant
(33964, 27, 45845, 0, 0, 1, 0, 0, 45745), -- Leggings of the Weary Mystic
(33964, 26, 45844, 0, 0, 1, 0, 0, 45745), -- Leggings of the Tireless Sentry
(33964, 25, 45846, 0, 0, 1, 0, 0, 45745), -- Leggings of Wavering Shadow
(33964, 24, 45847, 0, 0, 1, 0, 0, 45745), -- Wildstrider Legguards
(33964, 23, 45848, 0, 0, 1, 0, 0, 45745), -- Legwraps of the Master Conjurer
(33964, 22, 45834, 0, 0, 1, 0, 0, 45745), -- Gauntlets of the Royal Watch
(33964, 21, 45833, 0, 0, 1, 0, 0, 45745), -- Bladebreaker Gauntlets
(33964, 20, 45835, 0, 0, 1, 0, 0, 45745), -- Gauntlets of Serene Blessing
(33964, 19, 45837, 0, 0, 1, 0, 0, 45745), -- Gloves of Augury
(33964, 18, 45836, 0, 0, 1, 0, 0, 45745), -- Gloves of Unerring Aim
(33964, 17, 45838, 0, 0, 1, 0, 0, 45745), -- Gloves of the Blind Stalker
(33964, 16, 45839, 0, 0, 1, 0, 0, 45745), -- Grips of the Secret Grove
(33964, 15, 45840, 0, 0, 1, 0, 0, 45745), -- Touch of the Occult
(33964, 14, 45825, 0, 0, 1, 0, 0, 45745), -- Shieldwarder Girdle
(33964, 13, 45824, 0, 0, 1, 0, 0, 45745), -- Belt of the Singing Blade
(33964, 12, 45826, 0, 0, 1, 0, 0, 45745), -- Girdle of Unyielding Trust
(33964, 11, 45828, 0, 0, 1, 0, 0, 45745), -- Windchill Binding
(33964, 10, 45827, 0, 0, 1, 0, 0, 45745), -- Belt of the Ardent Marksman
(33964, 9, 45829, 0, 0, 1, 0, 0, 45745), -- Belt of the Twilight Assassin
(33964, 8, 45830, 0, 0, 1, 0, 0, 45745), -- Belt of the Living Thicket
(33964, 7, 45831, 0, 0, 1, 0, 0, 45745), -- Sash of Potent Incantations
(33964, 6, 45821, 0, 0, 1, 0, 0, 45745), -- Shard of the Crystal Forest
(33964, 5, 45819, 0, 0, 1, 0, 0, 45745), -- Spiked Battleguard Choker
(33964, 4, 45820, 0, 0, 1, 0, 0, 45745), -- Broach of the Wailing Night
(33964, 3, 45823, 0, 0, 1, 0, 0, 45745), -- Frozen Tear of Elune
(33964, 2, 45822, 0, 0, 1, 0, 0, 45745), -- Evoker's Charm
(33964, 1, 45087, 0, 0, 1, 0, 0, 45745), -- Runed Orb
(31579, 37, 41963, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Silk Amice
(31579, 36, 41957, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Silk Trousers
(31579, 35, 41944, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Silk Cowl
(31579, 34, 41969, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Silk Handguards
(31579, 33, 41950, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Silk Raiment
(31579, 32, 40636, 0, 0, 1, 0, 0, 45745), -- Legplates of the Lost Vanquisher
(31579, 29, 40639, 0, 0, 1, 0, 0, 45745), -- Mantle of the Lost Vanquisher
(31579, 26, 40750, 0, 0, 1, 0, 0, 45745), -- Xintor's Expeditionary Boots
(31579, 25, 40747, 0, 0, 1, 0, 0, 45745), -- Treads of Coastal Wandering
(31579, 24, 40751, 0, 0, 1, 0, 0, 45745), -- Slippers of the Holy Light
(31579, 23, 40745, 0, 0, 1, 0, 0, 45745), -- Sabatons of Rapid Recovery
(31579, 22, 40749, 0, 0, 1, 0, 0, 45745), -- Rainey's Chewed Boots
(31579, 21, 40746, 0, 0, 1, 0, 0, 45745), -- Pack-Ice Striders
(31579, 20, 40743, 0, 0, 1, 0, 0, 45745), -- Kyzoc's Ground Stompers
(31579, 19, 40748, 0, 0, 1, 0, 0, 45745), -- Boots of Captain Ellis
(31579, 18, 40742, 0, 0, 1, 0, 0, 45745), -- Bladed Steelboots
(31579, 17, 40735, 0, 0, 1, 0, 0, 45745), -- Zartson's Jungle Vambraces
(31579, 16, 40738, 0, 0, 1, 0, 0, 45745), -- Wristwraps of the Cutthroat
(31579, 15, 40733, 0, 0, 1, 0, 0, 45745), -- Wristbands of the Sentinel Huntress
(31579, 14, 40740, 0, 0, 1, 0, 0, 45745), -- Wraps of the Astral Traveler
(31579, 13, 40737, 0, 0, 1, 0, 0, 45745), -- Pigmented Clan Bindings
(31579, 12, 40741, 0, 0, 1, 0, 0, 45745), -- Cuffs of the Shadow Ascendant
(31579, 11, 40734, 0, 0, 1, 0, 0, 45745), -- Bracers of Dalaran's Parapets
(31579, 10, 40739, 0, 0, 1, 0, 0, 45745), -- Bands of the Great Tree
(31579, 9, 40736, 0, 0, 1, 0, 0, 45745), -- Armguard of the Tower Archer
(31579, 8, 40722, 0, 0, 1, 0, 0, 45745), -- Platinum Mesh Cloak
(31579, 7, 40721, 0, 0, 1, 0, 0, 45745), -- Hammerhead Sharkskin Cloak
(31579, 6, 40723, 0, 0, 1, 0, 0, 45745), -- Disguise of the Kumiho
(31579, 5, 40724, 0, 0, 1, 0, 0, 45745), -- Cloak of Kea Feathers
(31579, 4, 40718, 0, 0, 1, 0, 0, 45745), -- Signet of the Impregnable Fortress
(31579, 3, 40717, 0, 0, 1, 0, 0, 45745), -- Ring of Invincibility
(31579, 2, 40720, 0, 0, 1, 0, 0, 45745), -- Renewal of Life
(31579, 1, 40719, 0, 0, 1, 0, 0, 45745), -- Band of Channeled Magic
(31580, 101, 41968, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Silk Handguards
(31580, 85, 41962, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Silk Amice
(31580, 69, 41943, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Silk Cowl
(31580, 53, 41956, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Silk Trousers
(31580, 41, 41949, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Silk Raiment
(31580, 31, 40612, 0, 0, 1, 0, 0, 45745), -- Chestguard of the Lost Vanquisher
(31580, 28, 40615, 0, 0, 1, 0, 0, 45745), -- Gloves of the Lost Vanquisher
(31580, 25, 40702, 0, 0, 1, 0, 0, 45745), -- Rolfsen's Ripper
(31580, 24, 40704, 0, 0, 1, 0, 0, 45745), -- Pride
(31580, 23, 40703, 0, 0, 1, 0, 0, 45745), -- Grasscutter
(31580, 22, 40700, 0, 0, 1, 0, 0, 45745), -- Protective Barricade of the Light
(31580, 21, 40701, 0, 0, 1, 0, 0, 45745), -- Crygil's Discarded Plate Panel
(31580, 20, 40698, 0, 0, 1, 0, 0, 45745), -- Ward of the Violet Citadel
(31580, 19, 40699, 0, 0, 1, 0, 0, 45745), -- Handbook of Obscure Remedies
(31580, 18, 40689, 0, 0, 1, 0, 0, 45745), -- Waistguard of Living Iron
(31580, 17, 40695, 0, 0, 1, 0, 0, 45745), -- Vine Belt of the Woodland Dryad
(31580, 16, 40692, 0, 0, 1, 0, 0, 45745), -- Vereesa's Silver Chain Belt
(31580, 15, 40688, 0, 0, 1, 0, 0, 45745), -- Verdungo's Barbarian Cord
(31580, 14, 40696, 0, 0, 1, 0, 0, 45745), -- Plush Sash of Guzbah
(31580, 13, 40691, 0, 0, 1, 0, 0, 45745), -- Magroth's Meditative Cincture
(31580, 12, 40694, 0, 0, 1, 0, 0, 45745), -- Jorach's Crocolisk Skin Belt
(31580, 11, 40697, 0, 0, 1, 0, 0, 45745), -- Elegant Temple Gardens' Girdle
(31580, 10, 40693, 0, 0, 1, 0, 0, 45745), -- Beadwork Belt of Shamanic Vision
(31580, 9, 40683, 0, 0, 1, 0, 0, 45745), -- Valor Medal of the First War
(31580, 8, 40685, 0, 0, 1, 0, 0, 45745), -- The Egg of Mortal Essence
(31580, 7, 40682, 0, 0, 1, 0, 0, 45745), -- Sundial of the Exiled
(31580, 6, 40684, 0, 0, 1, 0, 0, 45745), -- Mirror of Truth
(31580, 5, 40678, 0, 0, 1, 0, 0, 45745), -- Pendant of the Outcast Hero
(31580, 4, 40681, 0, 0, 1, 0, 0, 45745), -- Lattice Choker of Light
(31580, 3, 40680, 0, 0, 1, 0, 0, 45745), -- Encircling Burnished Gold Chains
(31580, 2, 40679, 0, 0, 1, 0, 0, 45745), -- Chained Military Gorget
(31580, 1, 43102, 0, 0, 1, 0, 0, 45745); -- Frozen Orb

-- Update Horde Legacy Quartermaster in Dalaran-Northrend
DELETE FROM `npc_vendor` WHERE `entry` IN (35495, 33963, 31581, 37941, 31582);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(35495, 104, 41921, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Satin Robe
(35495, 103, 41934, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Satin Mantle
(35495, 102, 41927, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Satin Leggings
(35495, 101, 41915, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Satin Hood
(35495, 100, 41940, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Satin Gloves
(35495, 99, 41859, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Mooncloth Robe
(35495, 98, 41869, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Mooncloth Mantle
(35495, 97, 41864, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Mooncloth Leggings
(35495, 96, 41854, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Mooncloth Hood
(35495, 95, 41874, 0, 0, 1, 0, 0, 45745), -- Furious Gladiator's Mooncloth Gloves
(35495, 29, 47735, 0, 0, 1, 0, 0, 45745), -- Glyph of Indomitability
(35495, 28, 47734, 0, 0, 1, 0, 0, 45745), -- Mark of Supremacy
(35495, 27, 48724, 0, 0, 1, 0, 0, 45745), -- Talisman of Resurgence
(35495, 26, 48722, 0, 0, 1, 0, 0, 45745), -- Shard of the Crystal Heart
(35495, 25, 47731, 0, 0, 1, 0, 0, 45745), -- Clutch of Fortification
(35495, 24, 47729, 0, 0, 1, 0, 0, 45745), -- Bloodshed Band
(35495, 23, 47730, 0, 0, 1, 0, 0, 45745), -- Dexterous Brightstone Ring
(35495, 22, 47733, 0, 0, 1, 0, 0, 45745), -- Heartmender Circle
(35495, 21, 47732, 0, 0, 1, 0, 0, 45745), -- Band of the Invoker
(35495, 20, 47706, 0, 0, 1, 0, 0, 45745), -- Shoulders of the Groundbreaker
(35495, 19, 47709, 0, 0, 1, 0, 0, 45745), -- Duskstalker Pauldrons
(35495, 18, 47716, 0, 0, 1, 0, 0, 45745), -- Mantle of Revered Mortality
(35495, 17, 47699, 0, 0, 1, 0, 0, 45745), -- Shoulderguards of Enduring Order
(35495, 16, 47696, 0, 0, 1, 0, 0, 45745), -- Shoulderplates of Trembling Rage
(35495, 15, 47701, 0, 0, 1, 0, 0, 45745), -- Shoulderplates of the Cavalier
(35495, 14, 47705, 0, 0, 1, 0, 0, 45745), -- Pauldrons of the Devourer
(35495, 13, 47710, 0, 0, 1, 0, 0, 45745), -- Epaulets of the Fateful Accord
(35495, 12, 47714, 0, 0, 1, 0, 0, 45745), -- Pauldrons of Catastrophic Emanation
(35495, 11, 47687, 0, 0, 1, 0, 0, 45745), -- Headguard of Inner Warmth
(35495, 10, 47688, 0, 0, 1, 0, 0, 45745), -- Mask of Lethal Intent
(35495, 9, 47695, 0, 0, 1, 0, 0, 45745), -- Hood of Clouded Sight
(35495, 8, 47678, 0, 0, 1, 0, 0, 45745), -- Headplate of the Honorbound
(35495, 7, 47675, 0, 0, 1, 0, 0, 45745), -- Faceplate of Thunderous Rampage
(35495, 6, 47682, 0, 0, 1, 0, 0, 45745), -- Helm of the Restless Watch
(35495, 5, 47684, 0, 0, 1, 0, 0, 45745), -- Coif of the Brooding Dragon
(35495, 4, 47691, 0, 0, 1, 0, 0, 45745), -- Mask of Abundant Growth
(35495, 3, 47692, 0, 0, 1, 0, 0, 45745), -- Hood of Smoldering Aftermath
(35495, 2, 47658, 0, 0, 1, 0, 0, 45745), -- Brimstone Igniter
(35495, 1, 47556, 0, 0, 1, 0, 0, 45745), -- Crusader Orb
(33963, 113, 41939, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Satin Gloves
(33963, 109, 41873, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Mooncloth Gloves
(33963, 97, 41933, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Satin Mantle
(33963, 93, 41868, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Mooncloth Mantle
(33963, 81, 41914, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Satin Hood
(33963, 77, 41853, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Mooncloth Hood
(33963, 65, 41926, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Satin Leggings
(33963, 61, 41863, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Mooncloth Leggings
(33963, 51, 41920, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Satin Robe
(33963, 50, 41858, 0, 0, 1, 0, 0, 45745), -- Deadly Gladiator's Mooncloth Robe
(33963, 34, 45638, 0, 0, 1, 0, 0, 45745), -- Crown of the Wayward Conqueror
(33963, 31, 45632, 0, 0, 1, 0, 0, 45745), -- Breastplate of the Wayward Conqueror
(33963, 30, 45842, 0, 0, 1, 0, 0, 45745), -- Wyrmguard Legplates
(33963, 29, 45841, 0, 0, 1, 0, 0, 45745), -- Legplates of the Violet Champion
(33963, 28, 45843, 0, 0, 1, 0, 0, 45745), -- Legguards of the Peaceful Covenant
(33963, 27, 45845, 0, 0, 1, 0, 0, 45745), -- Leggings of the Weary Mystic
(33963, 26, 45844, 0, 0, 1, 0, 0, 45745), -- Leggings of the Tireless Sentry
(33963, 25, 45846, 0, 0, 1, 0, 0, 45745), -- Leggings of Wavering Shadow
(33963, 24, 45847, 0, 0, 1, 0, 0, 45745), -- Wildstrider Legguards
(33963, 23, 45848, 0, 0, 1, 0, 0, 45745), -- Legwraps of the Master Conjurer
(33963, 22, 45834, 0, 0, 1, 0, 0, 45745), -- Gauntlets of the Royal Watch
(33963, 21, 45833, 0, 0, 1, 0, 0, 45745), -- Bladebreaker Gauntlets
(33963, 20, 45835, 0, 0, 1, 0, 0, 45745), -- Gauntlets of Serene Blessing
(33963, 19, 45837, 0, 0, 1, 0, 0, 45745), -- Gloves of Augury
(33963, 18, 45836, 0, 0, 1, 0, 0, 45745), -- Gloves of Unerring Aim
(33963, 17, 45838, 0, 0, 1, 0, 0, 45745), -- Gloves of the Blind Stalker
(33963, 16, 45839, 0, 0, 1, 0, 0, 45745), -- Grips of the Secret Grove
(33963, 15, 45840, 0, 0, 1, 0, 0, 45745), -- Touch of the Occult
(33963, 14, 45825, 0, 0, 1, 0, 0, 45745), -- Shieldwarder Girdle
(33963, 13, 45824, 0, 0, 1, 0, 0, 45745), -- Belt of the Singing Blade
(33963, 12, 45826, 0, 0, 1, 0, 0, 45745), -- Girdle of Unyielding Trust
(33963, 11, 45828, 0, 0, 1, 0, 0, 45745), -- Windchill Binding
(33963, 10, 45827, 0, 0, 1, 0, 0, 45745), -- Belt of the Ardent Marksman
(33963, 9, 45829, 0, 0, 1, 0, 0, 45745), -- Belt of the Twilight Assassin
(33963, 8, 45830, 0, 0, 1, 0, 0, 45745), -- Belt of the Living Thicket
(33963, 7, 45831, 0, 0, 1, 0, 0, 45745), -- Sash of Potent Incantations
(33963, 6, 45821, 0, 0, 1, 0, 0, 45745), -- Shard of the Crystal Forest
(33963, 5, 45819, 0, 0, 1, 0, 0, 45745), -- Spiked Battleguard Choker
(33963, 4, 45820, 0, 0, 1, 0, 0, 45745), -- Broach of the Wailing Night
(33963, 3, 45823, 0, 0, 1, 0, 0, 45745), -- Frozen Tear of Elune
(33963, 2, 45822, 0, 0, 1, 0, 0, 45745), -- Evoker's Charm
(33963, 1, 45087, 0, 0, 1, 0, 0, 45745), -- Runed Orb
(31581, 47, 41931, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Satin Mantle
(31581, 46, 41925, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Satin Leggings
(31581, 45, 41913, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Satin Hood
(31581, 44, 41938, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Satin Gloves
(31581, 43, 41919, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Satin Robe
(31581, 42, 41867, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Mooncloth Mantle
(31581, 41, 41862, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Mooncloth Leggings
(31581, 40, 41852, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Mooncloth Hood
(31581, 39, 41872, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Mooncloth Gloves
(31581, 38, 41857, 0, 0, 1, 0, 0, 45745), -- Hateful Gladiator's Mooncloth Robe
(31581, 30, 40634, 0, 0, 1, 0, 0, 45745), -- Legplates of the Lost Conqueror
(31581, 27, 40637, 0, 0, 1, 0, 0, 45745), -- Mantle of the Lost Conqueror
(31581, 26, 40750, 0, 0, 1, 0, 0, 45745), -- Xintor's Expeditionary Boots
(31581, 25, 40747, 0, 0, 1, 0, 0, 45745), -- Treads of Coastal Wandering
(31581, 24, 40751, 0, 0, 1, 0, 0, 45745), -- Slippers of the Holy Light
(31581, 23, 40745, 0, 0, 1, 0, 0, 45745), -- Sabatons of Rapid Recovery
(31581, 22, 40749, 0, 0, 1, 0, 0, 45745), -- Rainey's Chewed Boots
(31581, 21, 40746, 0, 0, 1, 0, 0, 45745), -- Pack-Ice Striders
(31581, 20, 40743, 0, 0, 1, 0, 0, 45745), -- Kyzoc's Ground Stompers
(31581, 19, 40748, 0, 0, 1, 0, 0, 45745), -- Boots of Captain Ellis
(31581, 18, 40742, 0, 0, 1, 0, 0, 45745), -- Bladed Steelboots
(31581, 17, 40735, 0, 0, 1, 0, 0, 45745), -- Zartson's Jungle Vambraces
(31581, 16, 40738, 0, 0, 1, 0, 0, 45745), -- Wristwraps of the Cutthroat
(31581, 15, 40733, 0, 0, 1, 0, 0, 45745), -- Wristbands of the Sentinel Huntress
(31581, 14, 40740, 0, 0, 1, 0, 0, 45745), -- Wraps of the Astral Traveler
(31581, 13, 40737, 0, 0, 1, 0, 0, 45745), -- Pigmented Clan Bindings
(31581, 12, 40741, 0, 0, 1, 0, 0, 45745), -- Cuffs of the Shadow Ascendant
(31581, 11, 40734, 0, 0, 1, 0, 0, 45745), -- Bracers of Dalaran's Parapets
(31581, 10, 40739, 0, 0, 1, 0, 0, 45745), -- Bands of the Great Tree
(31581, 9, 40736, 0, 0, 1, 0, 0, 45745), -- Armguard of the Tower Archer
(31581, 8, 40722, 0, 0, 1, 0, 0, 45745), -- Platinum Mesh Cloak
(31581, 7, 40721, 0, 0, 1, 0, 0, 45745), -- Hammerhead Sharkskin Cloak
(31581, 6, 40723, 0, 0, 1, 0, 0, 45745), -- Disguise of the Kumiho
(31581, 5, 40724, 0, 0, 1, 0, 0, 45745), -- Cloak of Kea Feathers
(31581, 4, 40718, 0, 0, 1, 0, 0, 45745), -- Signet of the Impregnable Fortress
(31581, 3, 40717, 0, 0, 1, 0, 0, 45745), -- Ring of Invincibility
(31581, 2, 40720, 0, 0, 1, 0, 0, 45745), -- Renewal of Life
(31581, 1, 40719, 0, 0, 1, 0, 0, 45745), -- Band of Channeled Magic
(37941, 112, 41935, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Satin Mantle
(37941, 111, 41928, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Satin Leggings
(37941, 110, 41916, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Satin Hood
(37941, 109, 41941, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Satin Gloves
(37941, 108, 41922, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Satin Robe
(37941, 107, 41870, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Mooncloth Mantle
(37941, 106, 41865, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Mooncloth Leggings
(37941, 105, 41855, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Mooncloth Hood
(37941, 104, 41875, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Mooncloth Gloves
(37941, 103, 41860, 0, 0, 1, 0, 0, 45745), -- Relentless Gladiator's Mooncloth Robe
(37941, 37, 49908, 0, 0, 1, 0, 0, 45745), -- Primordial Saronite
(37941, 36, 50997, 0, 0, 1, 0, 0, 45745), -- Circle of Ossus
(37941, 35, 50996, 0, 0, 1, 0, 0, 45745), -- Belt of Omission
(37941, 34, 50995, 0, 0, 1, 0, 0, 45745), -- Vengeful Noose
(37941, 33, 50994, 0, 0, 1, 0, 0, 45745), -- Belt of Petrified Ivy
(37941, 32, 50993, 0, 0, 1, 0, 0, 45745), -- Band of the Night Raven
(37941, 31, 50992, 0, 0, 1, 0, 0, 45745), -- Waistband of Despair
(37941, 30, 50991, 0, 0, 1, 0, 0, 45745), -- Verdigris Chain Belt
(37941, 29, 50989, 0, 0, 1, 0, 0, 45745), -- Lich Killer's Lanyard
(37941, 28, 50987, 0, 0, 1, 0, 0, 45745), -- Malevolent Girdle
(37941, 27, 50984, 0, 0, 1, 0, 0, 45745), -- Gloves of Ambivalence
(37941, 26, 50983, 0, 0, 1, 0, 0, 45745), -- Gloves of False Gestures
(37941, 25, 50982, 0, 0, 1, 0, 0, 45745), -- Cat Burglar's Grips
(37941, 24, 50981, 0, 0, 1, 0, 0, 45745), -- Gloves of the Great Horned Owl
(37941, 23, 50980, 0, 0, 1, 0, 0, 45745), -- Blizzard Keeper's Mitts
(37941, 22, 50979, 0, 0, 1, 0, 0, 45745), -- Logsplitters
(37941, 21, 50978, 0, 0, 1, 0, 0, 45745), -- Gauntlets of the Kraken
(37941, 20, 50977, 0, 0, 1, 0, 0, 45745), -- Gatecrasher's Gauntlets
(37941, 19, 50976, 0, 0, 1, 0, 0, 45745), -- Gauntlets of Overexposure
(37941, 18, 50975, 0, 0, 1, 0, 0, 45745), -- Ermine Coronation Robes
(37941, 17, 50974, 0, 0, 1, 0, 0, 45745), -- Meteor Chaser's Raiment
(37941, 16, 50973, 0, 0, 1, 0, 0, 45745), -- Vestments of Spruce and Fir
(37941, 15, 50972, 0, 0, 1, 0, 0, 45745), -- Shadow Seeker's Tunic
(37941, 14, 50971, 0, 0, 1, 0, 0, 45745), -- Mail of the Geyser
(37941, 13, 50970, 0, 0, 1, 0, 0, 45745), -- Longstrider's Vest
(37941, 12, 50969, 0, 0, 1, 0, 0, 45745), -- Chestplate of Unspoken Truths
(37941, 11, 50968, 0, 0, 1, 0, 0, 45745), -- Cataclysmic Chestguard
(37941, 10, 50965, 0, 0, 1, 0, 0, 45745), -- Castle Breaker's Battleplate
(37941, 9, 50470, 0, 0, 1, 0, 0, 45745), -- Recovered Scarlet Onslaught Cape
(37941, 8, 50469, 0, 0, 1, 0, 0, 45745), -- Volde's Cloak of the Night Sky
(37941, 7, 50468, 0, 0, 1, 0, 0, 45745), -- Drape of the Violet Tower
(37941, 6, 50467, 0, 0, 1, 0, 0, 45745), -- Might of the Ocean Serpent
(37941, 5, 50466, 0, 0, 1, 0, 0, 45745), -- Sentinel's Winter Cloak
(37941, 4, 50358, 0, 0, 1, 0, 0, 45745), -- Purified Lunar Dust
(37941, 3, 50357, 0, 0, 1, 0, 0, 45745), -- Maghia's Misguided Quill
(37941, 2, 50356, 0, 0, 1, 0, 0, 45745), -- Corroded Skeleton Key
(37941, 1, 50355, 0, 0, 1, 0, 0, 45745), -- Herkuml War Token
(31582, 105, 41937, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Satin Gloves
(31582, 104, 41847, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Mooncloth Gloves
(31582, 89, 41930, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Satin Mantle
(31582, 88, 41850, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Mooncloth Mantle
(31582, 73, 41912, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Satin Hood
(31582, 72, 41848, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Mooncloth Hood
(31582, 57, 41924, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Satin Leggings
(31582, 56, 41849, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Mooncloth Leggings
(31582, 43, 41918, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Satin Robe
(31582, 42, 41851, 0, 0, 1, 0, 0, 45745), -- Savage Gladiator's Mooncloth Robe
(31582, 29, 40610, 0, 0, 1, 0, 0, 45745), -- Chestguard of the Lost Conqueror
(31582, 26, 40613, 0, 0, 1, 0, 0, 45745), -- Gloves of the Lost Conqueror
(31582, 25, 40702, 0, 0, 1, 0, 0, 45745), -- Rolfsen's Ripper
(31582, 24, 40704, 0, 0, 1, 0, 0, 45745), -- Pride
(31582, 23, 40703, 0, 0, 1, 0, 0, 45745), -- Grasscutter
(31582, 22, 40700, 0, 0, 1, 0, 0, 45745), -- Protective Barricade of the Light
(31582, 21, 40701, 0, 0, 1, 0, 0, 45745), -- Crygil's Discarded Plate Panel
(31582, 20, 40698, 0, 0, 1, 0, 0, 45745), -- Ward of the Violet Citadel
(31582, 19, 40699, 0, 0, 1, 0, 0, 45745), -- Handbook of Obscure Remedies
(31582, 18, 40689, 0, 0, 1, 0, 0, 45745), -- Waistguard of Living Iron
(31582, 17, 40695, 0, 0, 1, 0, 0, 45745), -- Vine Belt of the Woodland Dryad
(31582, 16, 40692, 0, 0, 1, 0, 0, 45745), -- Vereesa's Silver Chain Belt
(31582, 15, 40688, 0, 0, 1, 0, 0, 45745), -- Verdungo's Barbarian Cord
(31582, 14, 40696, 0, 0, 1, 0, 0, 45745), -- Plush Sash of Guzbah
(31582, 13, 40691, 0, 0, 1, 0, 0, 45745), -- Magroth's Meditative Cincture
(31582, 12, 40694, 0, 0, 1, 0, 0, 45745), -- Jorach's Crocolisk Skin Belt
(31582, 11, 40697, 0, 0, 1, 0, 0, 45745), -- Elegant Temple Gardens' Girdle
(31582, 10, 40693, 0, 0, 1, 0, 0, 45745), -- Beadwork Belt of Shamanic Vision
(31582, 9, 40683, 0, 0, 1, 0, 0, 45745), -- Valor Medal of the First War
(31582, 8, 40685, 0, 0, 1, 0, 0, 45745), -- The Egg of Mortal Essence
(31582, 7, 40682, 0, 0, 1, 0, 0, 45745), -- Sundial of the Exiled
(31582, 6, 40684, 0, 0, 1, 0, 0, 45745), -- Mirror of Truth
(31582, 5, 40678, 0, 0, 1, 0, 0, 45745), -- Pendant of the Outcast Hero
(31582, 4, 40681, 0, 0, 1, 0, 0, 45745), -- Lattice Choker of Light
(31582, 3, 40680, 0, 0, 1, 0, 0, 45745), -- Encircling Burnished Gold Chains
(31582, 2, 40679, 0, 0, 1, 0, 0, 45745), -- Chained Military Gorget
(31582, 1, 43102, 0, 0, 1, 0, 0, 45745); -- Frozen Orb
