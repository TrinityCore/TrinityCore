-- Alliance
DELETE FROM `npc_vendor` WHERE `entry` IN (52027, 44245, 44246, 58154, 52028, 234135, 241468);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(52027, 1, 69889, 0, 3318, 1, 0, 0, 60192), -- Burnished Breastplate of Might
(52027, 2, 69890, 0, 3318, 1, 0, 0, 60192), -- Burnished Pauldrons of Might
(52027, 3, 48685, 0, 3318, 1, 0, 0, 60192), -- Polished Breastplate of Valor
(52027, 4, 42949, 0, 3318, 1, 0, 0, 60192), -- Polished Spaulders of Valor
(52027, 5, 42950, 0, 3318, 1, 0, 0, 60192), -- Champion Herod's Shoulder
(52027, 6, 48677, 0, 3318, 1, 0, 0, 60192), -- Champion's Deathdealer Breastplate
(52027, 7, 42951, 0, 3318, 1, 0, 0, 60192), -- Mystical Pauldrons of Elements
(52027, 8, 48683, 0, 3318, 1, 0, 0, 60192), -- Mystical Vest of Elements
(52027, 9, 48687, 0, 3318, 1, 0, 0, 60192), -- Preened Ironfeather Breastplate
(52027, 10, 42984, 0, 3318, 1, 0, 0, 60192), -- Preened Ironfeather Shoulders
(52027, 11, 42952, 0, 3318, 1, 0, 0, 60192), -- Stained Shadowcraft Spaulders
(52027, 12, 48689, 0, 3318, 1, 0, 0, 60192), -- Stained Shadowcraft Tunic
(52027, 13, 42985, 0, 3318, 1, 0, 0, 60192), -- Tattered Dreadmist Mantle
(52027, 14, 48691, 0, 3318, 1, 0, 0, 60192), -- Tattered Dreadmist Robe
(52027, 15, 42944, 0, 3318, 1, 0, 0, 60192), -- Balanced Heartseeker
(52027, 16, 42943, 0, 2551, 1, 0, 0, 60192), -- Bloodied Arcanite Reaper
(52027, 17, 42946, 0, 2551, 1, 0, 0, 60192), -- Charmed Ancient Bone Bow
(52027, 18, 42948, 0, 3319, 1, 0, 0, 60192), -- Devout Aurastone Hammer
(52027, 19, 42947, 0, 2551, 1, 0, 0, 60192), -- Dignified Headmaster's Charge
(52027, 20, 48718, 0, 2551, 1, 0, 0, 60192), -- Repurposed Lava Dredger
(52027, 21, 42945, 0, 3318, 1, 0, 0, 60192), -- Venerable Dal'Rend's Sacred Charge
(52027, 22, 48716, 0, 3318, 1, 0, 0, 60192), -- Venerable Mass of McGowan
(52027, 23, 69893, 0, 3318, 1, 0, 0, 60192), -- Bloodsoaked Skullforge Reaver
(52027, 24, 42992, 0, 3319, 1, 0, 0, 60192), -- Discerning Eye of the Beast
(52027, 25, 42991, 0, 3319, 1, 0, 0, 60192), -- Swift Hand of Justice
-- 
(44245, 1, 78659, 0, 3857, 1, 0, 0, 60192), -- Necrotic Boneplate Breastplate
(44245, 2, 78670, 0, 3859, 1, 0, 0, 60192), -- Necrotic Boneplate Gauntlets
(44245, 3, 78687, 0, 3858, 1, 0, 0, 60192), -- Necrotic Boneplate Helmet
(44245, 4, 78707, 0, 3860, 1, 0, 0, 60192), -- Necrotic Boneplate Greaves
(44245, 5, 78736, 0, 3861, 1, 0, 0, 60192), -- Necrotic Boneplate Pauldrons
(44245, 6, 78663, 0, 3857, 1, 0, 0, 60192), -- Necrotic Boneplate Chestguard
(44245, 7, 78678, 0, 3859, 1, 0, 0, 60192), -- Necrotic Boneplate Handguards
(44245, 8, 78697, 0, 3858, 1, 0, 0, 60192), -- Necrotic Boneplate Faceguard
(44245, 9, 78716, 0, 3860, 1, 0, 0, 60192), -- Necrotic Boneplate Legguards
(44245, 10, 78751, 0, 3861, 1, 0, 0, 60192), -- Necrotic Boneplate Shoulderguards
(44245, 11, 78665, 0, 3857, 1, 0, 0, 60192), -- Deep Earth Raiment
(44245, 12, 78684, 0, 3859, 1, 0, 0, 60192), -- Deep Earth Grips
(44245, 13, 78694, 0, 3858, 1, 0, 0, 60192), -- Deep Earth Headpiece
(44245, 14, 78713, 0, 3860, 1, 0, 0, 60192), -- Deep Earth Legguards
(44245, 15, 78743, 0, 3861, 1, 0, 0, 60192), -- Deep Earth Spaulders
(44245, 16, 78660, 0, 3857, 1, 0, 0, 60192), -- Deep Earth Robes
(44245, 17, 78680, 0, 3859, 1, 0, 0, 60192), -- Deep Earth Handwraps
(44245, 18, 78690, 0, 3858, 1, 0, 0, 60192), -- Deep Earth Helm
(44245, 19, 78710, 0, 3860, 1, 0, 0, 60192), -- Deep Earth Legwraps
(44245, 20, 78740, 0, 3861, 1, 0, 0, 60192), -- Deep Earth Mantle
(44245, 21, 78662, 0, 3857, 1, 0, 0, 60192), -- Deep Earth Vestment
(44245, 22, 78676, 0, 3859, 1, 0, 0, 60192), -- Deep Earth Gloves
(44245, 23, 78696, 0, 3858, 1, 0, 0, 60192), -- Deep Earth Cover
(44245, 24, 78714, 0, 3860, 1, 0, 0, 60192), -- Deep Earth Leggings
(44245, 25, 78744, 0, 3861, 1, 0, 0, 60192), -- Deep Earth Shoulderwraps
(44245, 26, 78661, 0, 3867, 1, 0, 0, 60192), -- Wyrmstalker's Tunic
(44245, 27, 78674, 0, 3869, 1, 0, 0, 60192), -- Wyrmstalker's Gloves
(44245, 28, 78698, 0, 3868, 1, 0, 0, 60192), -- Wyrmstalker's Headguard
(44245, 29, 78709, 0, 3870, 1, 0, 0, 60192), -- Wyrmstalker's Legguards
(44245, 30, 78737, 0, 3871, 1, 0, 0, 60192), -- Wyrmstalker's Spaulders
(44245, 31, 78671, 0, 3859, 1, 0, 0, 60192), -- Time Lord's Gloves
(44245, 32, 78701, 0, 3858, 1, 0, 0, 60192), -- Time Lord's Hood
(44245, 33, 78720, 0, 3860, 1, 0, 0, 60192), -- Time Lord's Leggings
(44245, 34, 78729, 0, 3857, 1, 0, 0, 60192), -- Time Lord's Robes
(44245, 35, 78748, 0, 3861, 1, 0, 0, 60192), -- Time Lord's Mantle
(44245, 36, 78727, 0, 3862, 1, 0, 0, 60192), -- Battleplate of Radiant Glory
(44245, 37, 78675, 0, 3864, 1, 0, 0, 60192), -- Gauntlets of Radiant Glory
(44245, 38, 78693, 0, 3863, 1, 0, 0, 60192), -- Helmet of Radiant Glory
(44245, 39, 78712, 0, 3865, 1, 0, 0, 60192), -- Legplates of Radiant Glory
(44245, 40, 78742, 0, 3866, 1, 0, 0, 60192), -- Pauldrons of Radiant Glory
(44245, 41, 78726, 0, 3862, 1, 0, 0, 60192), -- Breastplate of Radiant Glory
(44245, 42, 78673, 0, 3864, 1, 0, 0, 60192), -- Gloves of Radiant Glory
(44245, 43, 78692, 0, 3863, 1, 0, 0, 60192), -- Headguard of Radiant Glory
(44245, 44, 78717, 0, 3865, 1, 0, 0, 60192), -- Greaves of Radiant Glory
(44245, 45, 78746, 0, 3866, 1, 0, 0, 60192), -- Mantle of Radiant Glory
(44245, 46, 78732, 0, 3862, 1, 0, 0, 60192), -- Chestguard of Radiant Glory
(44245, 47, 78677, 0, 3864, 1, 0, 0, 60192), -- Handguards of Radiant Glory
(44245, 48, 78695, 0, 3863, 1, 0, 0, 60192), -- Faceguard of Radiant Glory
(44245, 49, 78715, 0, 3865, 1, 0, 0, 60192), -- Legguards of Radiant Glory
(44245, 50, 78745, 0, 3866, 1, 0, 0, 60192), -- Shoulderguards of Radiant Glory
(44245, 51, 78683, 0, 3864, 1, 0, 0, 60192), -- Handwraps of Dying Light
(44245, 52, 78700, 0, 3863, 1, 0, 0, 60192), -- Cowl of Dying Light
(44245, 53, 78719, 0, 3865, 1, 0, 0, 60192), -- Legwraps of Dying Light
(44245, 54, 78728, 0, 3862, 1, 0, 0, 60192), -- Robes of Dying Light
(44245, 55, 78747, 0, 3866, 1, 0, 0, 60192), -- Mantle of Dying Light
(44245, 56, 78682, 0, 3864, 1, 0, 0, 60192), -- Gloves of Dying Light
(44245, 57, 78703, 0, 3863, 1, 0, 0, 60192), -- Hood of Dying Light
(44245, 58, 78722, 0, 3865, 1, 0, 0, 60192), -- Leggings of Dying Light
(44245, 59, 78731, 0, 3862, 1, 0, 0, 60192), -- Robes of Dying Light
(44245, 60, 78750, 0, 3866, 1, 0, 0, 60192), -- Mantle of Dying Light
(44245, 61, 78664, 0, 3857, 1, 0, 0, 60192), -- Blackfang Battleweave Tunic
(44245, 62, 78679, 0, 3859, 1, 0, 0, 60192), -- Blackfang Battleweave Gloves
(44245, 63, 78699, 0, 3858, 1, 0, 0, 60192), -- Blackfang Battleweave Helmet
(44245, 64, 78708, 0, 3860, 1, 0, 0, 60192), -- Blackfang Battleweave Legguards
(44245, 65, 78738, 0, 3861, 1, 0, 0, 60192), -- Blackfang Battleweave Spaulders
(44245, 66, 78725, 0, 3867, 1, 0, 0, 60192), -- Spiritwalker's Tunic
(44245, 67, 78672, 0, 3869, 1, 0, 0, 60192), -- Spiritwalker's Handwraps
(44245, 68, 78691, 0, 3868, 1, 0, 0, 60192), -- Spiritwalker's Faceguard
(44245, 69, 78718, 0, 3870, 1, 0, 0, 60192), -- Spiritwalker's Legwraps
(44245, 70, 78739, 0, 3871, 1, 0, 0, 60192), -- Spiritwalker's Mantle
(44245, 71, 78724, 0, 3867, 1, 0, 0, 60192), -- Spiritwalker's Cuirass
(44245, 72, 78667, 0, 3869, 1, 0, 0, 60192), -- Spiritwalker's Grips
(44245, 73, 78686, 0, 3868, 1, 0, 0, 60192), -- Spiritwalker's Helmet
(44245, 74, 78704, 0, 3870, 1, 0, 0, 60192), -- Spiritwalker's Legguards
(44245, 75, 78733, 0, 3871, 1, 0, 0, 60192), -- Spiritwalker's Spaulders
(44245, 76, 78723, 0, 3867, 1, 0, 0, 60192), -- Spiritwalker's Hauberk
(44245, 77, 78666, 0, 3869, 1, 0, 0, 60192), -- Spiritwalker's Gloves
(44245, 78, 78685, 0, 3868, 1, 0, 0, 60192), -- Spiritwalker's Headpiece
(44245, 79, 78711, 0, 3870, 1, 0, 0, 60192), -- Spiritwalker's Kilt
(44245, 80, 78741, 0, 3871, 1, 0, 0, 60192), -- Spiritwalker's Shoulderwraps
(44245, 81, 78681, 0, 3864, 1, 0, 0, 60192), -- Gloves of the Faceless Shroud
(44245, 82, 78702, 0, 3863, 1, 0, 0, 60192), -- Hood of the Faceless Shroud
(44245, 83, 78721, 0, 3865, 1, 0, 0, 60192), -- Leggings of the Faceless Shroud
(44245, 84, 78730, 0, 3862, 1, 0, 0, 60192), -- Robes of the Faceless Shroud
(44245, 85, 78749, 0, 3866, 1, 0, 0, 60192), -- Mantle of the Faceless Shroud
(44245, 86, 78657, 0, 3867, 1, 0, 0, 60192), -- Colossal Dragonplate Battleplate
(44245, 87, 78668, 0, 3869, 1, 0, 0, 60192), -- Colossal Dragonplate Gauntlets
(44245, 88, 78688, 0, 3868, 1, 0, 0, 60192), -- Colossal Dragonplate Helmet
(44245, 89, 78706, 0, 3870, 1, 0, 0, 60192), -- Colossal Dragonplate Legplates
(44245, 90, 78735, 0, 3871, 1, 0, 0, 60192), -- Colossal Dragonplate Pauldrons
(44245, 91, 78658, 0, 3867, 1, 0, 0, 60192), -- Colossal Dragonplate Chestguard
(44245, 92, 78669, 0, 3869, 1, 0, 0, 60192), -- Colossal Dragonplate Handguards
(44245, 93, 78689, 0, 3868, 1, 0, 0, 60192), -- Colossal Dragonplate Faceguard
(44245, 94, 78705, 0, 3870, 1, 0, 0, 60192), -- Colossal Dragonplate Legguards
(44245, 95, 78734, 0, 3871, 1, 0, 0, 60192), -- Colossal Dragonplate Shoulderguards
(44245, 96, 76974, 0, 3856, 1, 0, 0, 60192), -- Necrotic Boneplate Breastplate
(44245, 97, 76975, 0, 3855, 1, 0, 0, 60192), -- Necrotic Boneplate Gauntlets
(44245, 98, 76976, 0, 3853, 1, 0, 0, 60192), -- Necrotic Boneplate Helmet
(44245, 99, 76977, 0, 3852, 1, 0, 0, 60192), -- Necrotic Boneplate Greaves
(44245, 100, 76978, 0, 3851, 1, 0, 0, 60192), -- Necrotic Boneplate Pauldrons
(44245, 101, 77008, 0, 3856, 1, 0, 0, 60192), -- Necrotic Boneplate Chestguard
(44245, 102, 77009, 0, 3855, 1, 0, 0, 60192), -- Necrotic Boneplate Handguards
(44245, 103, 77010, 0, 3853, 1, 0, 0, 60192), -- Necrotic Boneplate Faceguard
(44245, 104, 77011, 0, 3852, 1, 0, 0, 60192), -- Necrotic Boneplate Legguards
(44245, 105, 77012, 0, 3851, 1, 0, 0, 60192), -- Necrotic Boneplate Shoulderguards
(44245, 106, 77013, 0, 3856, 1, 0, 0, 60192), -- Deep Earth Raiment
(44245, 107, 77014, 0, 3855, 1, 0, 0, 60192), -- Deep Earth Grips
(44245, 108, 77015, 0, 3853, 1, 0, 0, 60192), -- Deep Earth Headpiece
(44245, 109, 77016, 0, 3852, 1, 0, 0, 60192), -- Deep Earth Legguards
(44245, 110, 77017, 0, 3851, 1, 0, 0, 60192), -- Deep Earth Spaulders
(44245, 111, 76752, 0, 3856, 1, 0, 0, 60192), -- Deep Earth Robes
(44245, 112, 76749, 0, 3855, 1, 0, 0, 60192), -- Deep Earth Handwraps
(44245, 113, 76750, 0, 3853, 1, 0, 0, 60192), -- Deep Earth Helm
(44245, 114, 76751, 0, 3852, 1, 0, 0, 60192), -- Deep Earth Legwraps
(44245, 115, 76753, 0, 3851, 1, 0, 0, 60192), -- Deep Earth Mantle
(44245, 116, 77021, 0, 3856, 1, 0, 0, 60192), -- Deep Earth Vestment
(44245, 117, 77018, 0, 3855, 1, 0, 0, 60192), -- Deep Earth Gloves
(44245, 118, 77019, 0, 3853, 1, 0, 0, 60192), -- Deep Earth Cover
(44245, 119, 77020, 0, 3852, 1, 0, 0, 60192), -- Deep Earth Leggings
(44245, 120, 77022, 0, 3851, 1, 0, 0, 60192), -- Deep Earth Shoulderwraps
(44245, 121, 77028, 0, 3850, 1, 0, 0, 60192), -- Wyrmstalker's Tunic
(44245, 122, 77029, 0, 3849, 1, 0, 0, 60192), -- Wyrmstalker's Gloves
(44245, 123, 77030, 0, 3848, 1, 0, 0, 60192), -- Wyrmstalker's Headguard
(44245, 124, 77031, 0, 3847, 1, 0, 0, 60192), -- Wyrmstalker's Legguards
(44245, 125, 77032, 0, 3846, 1, 0, 0, 60192), -- Wyrmstalker's Spaulders
(44245, 126, 76212, 0, 3855, 1, 0, 0, 60192), -- Time Lord's Gloves
(44245, 127, 76213, 0, 3853, 1, 0, 0, 60192), -- Time Lord's Hood
(44245, 128, 76214, 0, 3852, 1, 0, 0, 60192), -- Time Lord's Leggings
(44245, 129, 76215, 0, 3856, 1, 0, 0, 60192), -- Time Lord's Robes
(44245, 130, 76216, 0, 3851, 1, 0, 0, 60192), -- Time Lord's Mantle
(44245, 131, 76874, 0, 3845, 1, 0, 0, 60192), -- Battleplate of Radiant Glory
(44245, 132, 76875, 0, 3844, 1, 0, 0, 60192), -- Gauntlets of Radiant Glory
(44245, 133, 76876, 0, 3843, 1, 0, 0, 60192), -- Helmet of Radiant Glory
(44245, 134, 76877, 0, 3842, 1, 0, 0, 60192), -- Legplates of Radiant Glory
(44245, 135, 76878, 0, 3841, 1, 0, 0, 60192), -- Pauldrons of Radiant Glory
(44245, 136, 76765, 0, 3845, 1, 0, 0, 60192), -- Breastplate of Radiant Glory
(44245, 137, 76766, 0, 3844, 1, 0, 0, 60192), -- Gloves of Radiant Glory
(44245, 138, 76767, 0, 3843, 1, 0, 0, 60192), -- Headguard of Radiant Glory
(44245, 139, 76768, 0, 3842, 1, 0, 0, 60192), -- Greaves of Radiant Glory
(44245, 140, 76769, 0, 3841, 1, 0, 0, 60192), -- Mantle of Radiant Glory
(44245, 141, 77003, 0, 3845, 1, 0, 0, 60192), -- Chestguard of Radiant Glory
(44245, 142, 77004, 0, 3844, 1, 0, 0, 60192), -- Handguards of Radiant Glory
(44245, 143, 77005, 0, 3843, 1, 0, 0, 60192), -- Faceguard of Radiant Glory
(44245, 144, 77006, 0, 3842, 1, 0, 0, 60192), -- Legguards of Radiant Glory
(44245, 145, 77007, 0, 3841, 1, 0, 0, 60192), -- Shoulderguards of Radiant Glory
(44245, 146, 76357, 0, 3844, 1, 0, 0, 60192), -- Handwraps of Dying Light
(44245, 147, 76358, 0, 3843, 1, 0, 0, 60192), -- Cowl of Dying Light
(44245, 148, 76359, 0, 3842, 1, 0, 0, 60192), -- Legwraps of Dying Light
(44245, 149, 76360, 0, 3845, 1, 0, 0, 60192), -- Robes of Dying Light
(44245, 150, 76361, 0, 3841, 1, 0, 0, 60192), -- Mantle of Dying Light
(44245, 151, 76348, 0, 3844, 1, 0, 0, 60192), -- Gloves of Dying Light
(44245, 152, 76347, 0, 3843, 1, 0, 0, 60192), -- Hood of Dying Light
(44245, 153, 76346, 0, 3842, 1, 0, 0, 60192), -- Leggings of Dying Light
(44245, 154, 76345, 0, 3845, 1, 0, 0, 60192), -- Robes of Dying Light
(44245, 155, 76344, 0, 3841, 1, 0, 0, 60192), -- Mantle of Dying Light
(44245, 156, 77023, 0, 3856, 1, 0, 0, 60192), -- Blackfang Battleweave Tunic
(44245, 157, 77024, 0, 3855, 1, 0, 0, 60192), -- Blackfang Battleweave Gloves
(44245, 158, 77025, 0, 3853, 1, 0, 0, 60192), -- Blackfang Battleweave Helmet
(44245, 159, 77026, 0, 3852, 1, 0, 0, 60192), -- Blackfang Battleweave Legguards
(44245, 160, 77027, 0, 3851, 1, 0, 0, 60192), -- Blackfang Battleweave Spaulders
(44245, 161, 76756, 0, 3850, 1, 0, 0, 60192), -- Spiritwalker's Tunic
(44245, 162, 76757, 0, 3849, 1, 0, 0, 60192), -- Spiritwalker's Handwraps
(44245, 163, 76758, 0, 3848, 1, 0, 0, 60192), -- Spiritwalker's Faceguard
(44245, 164, 76759, 0, 3847, 1, 0, 0, 60192), -- Spiritwalker's Legwraps
(44245, 165, 76760, 0, 3846, 1, 0, 0, 60192), -- Spiritwalker's Mantle
(44245, 166, 77040, 0, 3850, 1, 0, 0, 60192), -- Spiritwalker's Cuirass
(44245, 167, 77041, 0, 3849, 1, 0, 0, 60192), -- Spiritwalker's Grips
(44245, 168, 77042, 0, 3848, 1, 0, 0, 60192), -- Spiritwalker's Helmet
(44245, 169, 77043, 0, 3847, 1, 0, 0, 60192), -- Spiritwalker's Legguards
(44245, 170, 77044, 0, 3846, 1, 0, 0, 60192), -- Spiritwalker's Spaulders
(44245, 171, 77039, 0, 3850, 1, 0, 0, 60192), -- Spiritwalker's Hauberk
(44245, 172, 77038, 0, 3849, 1, 0, 0, 60192), -- Spiritwalker's Gloves
(44245, 173, 77037, 0, 3848, 1, 0, 0, 60192), -- Spiritwalker's Headpiece
(44245, 174, 77036, 0, 3847, 1, 0, 0, 60192), -- Spiritwalker's Kilt
(44245, 175, 77035, 0, 3846, 1, 0, 0, 60192), -- Spiritwalker's Shoulderwraps
(44245, 176, 76343, 0, 3844, 1, 0, 0, 60192), -- Gloves of the Faceless Shroud
(44245, 177, 76342, 0, 3843, 1, 0, 0, 60192), -- Hood of the Faceless Shroud
(44245, 178, 76341, 0, 3842, 1, 0, 0, 60192), -- Leggings of the Faceless Shroud
(44245, 179, 76340, 0, 3845, 1, 0, 0, 60192), -- Robes of the Faceless Shroud
(44245, 180, 76339, 0, 3841, 1, 0, 0, 60192), -- Mantle of the Faceless Shroud
(44245, 181, 76984, 0, 3850, 1, 0, 0, 60192), -- Colossal Dragonplate Battleplate
(44245, 182, 76985, 0, 3849, 1, 0, 0, 60192), -- Colossal Dragonplate Gauntlets
(44245, 183, 76983, 0, 3848, 1, 0, 0, 60192), -- Colossal Dragonplate Helmet
(44245, 184, 76986, 0, 3847, 1, 0, 0, 60192), -- Colossal Dragonplate Legplates
(44245, 185, 76987, 0, 3846, 1, 0, 0, 60192), -- Colossal Dragonplate Pauldrons
(44245, 186, 76988, 0, 3850, 1, 0, 0, 60192), -- Colossal Dragonplate Chestguard
(44245, 187, 76989, 0, 3849, 1, 0, 0, 60192), -- Colossal Dragonplate Handguards
(44245, 188, 76990, 0, 3848, 1, 0, 0, 60192), -- Colossal Dragonplate Faceguard
(44245, 189, 76991, 0, 3847, 1, 0, 0, 60192), -- Colossal Dragonplate Legguards
(44245, 190, 76992, 0, 3846, 1, 0, 0, 60192), -- Colossal Dragonplate Shoulderguards
(44245, 191, 78754, 0, 3826, 1, 0, 0, 60192), -- Necrotic Boneplate Breastplate
(44245, 192, 78765, 0, 3829, 1, 0, 0, 60192), -- Necrotic Boneplate Gauntlets
(44245, 193, 78782, 0, 3827, 1, 0, 0, 60192), -- Necrotic Boneplate Helmet
(44245, 194, 78802, 0, 3828, 1, 0, 0, 60192), -- Necrotic Boneplate Greaves
(44245, 195, 78831, 0, 3830, 1, 0, 0, 60192), -- Necrotic Boneplate Pauldrons
(44245, 196, 78758, 0, 3826, 1, 0, 0, 60192), -- Necrotic Boneplate Chestguard
(44245, 197, 78773, 0, 3829, 1, 0, 0, 60192), -- Necrotic Boneplate Handguards
(44245, 198, 78792, 0, 3827, 1, 0, 0, 60192), -- Necrotic Boneplate Faceguard
(44245, 199, 78811, 0, 3828, 1, 0, 0, 60192), -- Necrotic Boneplate Legguards
(44245, 200, 78846, 0, 3830, 1, 0, 0, 60192), -- Necrotic Boneplate Shoulderguards
(44245, 201, 78760, 0, 3826, 1, 0, 0, 60192), -- Deep Earth Raiment
(44245, 202, 78779, 0, 3829, 1, 0, 0, 60192), -- Deep Earth Grips
(44245, 203, 78789, 0, 3827, 1, 0, 0, 60192), -- Deep Earth Headpiece
(44245, 204, 78808, 0, 3828, 1, 0, 0, 60192), -- Deep Earth Legguards
(44245, 205, 78838, 0, 3830, 1, 0, 0, 60192), -- Deep Earth Spaulders
(44245, 206, 78755, 0, 3826, 1, 0, 0, 60192), -- Deep Earth Robes
(44245, 207, 78775, 0, 3829, 1, 0, 0, 60192), -- Deep Earth Handwraps
(44245, 208, 78785, 0, 3827, 1, 0, 0, 60192), -- Deep Earth Helm
(44245, 209, 78805, 0, 3828, 1, 0, 0, 60192), -- Deep Earth Legwraps
(44245, 210, 78835, 0, 3830, 1, 0, 0, 60192), -- Deep Earth Mantle
(44245, 211, 78757, 0, 3826, 1, 0, 0, 60192), -- Deep Earth Vestment
(44245, 212, 78771, 0, 3829, 1, 0, 0, 60192), -- Deep Earth Gloves
(44245, 213, 78791, 0, 3827, 1, 0, 0, 60192), -- Deep Earth Cover
(44245, 214, 78809, 0, 3828, 1, 0, 0, 60192), -- Deep Earth Leggings
(44245, 215, 78839, 0, 3830, 1, 0, 0, 60192), -- Deep Earth Shoulderwraps
(44245, 216, 78756, 0, 3840, 1, 0, 0, 60192), -- Wyrmstalker's Tunic
(44245, 217, 78769, 0, 3839, 1, 0, 0, 60192), -- Wyrmstalker's Gloves
(44245, 218, 78793, 0, 3837, 1, 0, 0, 60192), -- Wyrmstalker's Headguard
(44245, 219, 78804, 0, 3838, 1, 0, 0, 60192), -- Wyrmstalker's Legguards
(44245, 220, 78832, 0, 3836, 1, 0, 0, 60192), -- Wyrmstalker's Spaulders
(44245, 221, 78766, 0, 3829, 1, 0, 0, 60192), -- Time Lord's Gloves
(44245, 222, 78796, 0, 3827, 1, 0, 0, 60192), -- Time Lord's Hood
(44245, 223, 78815, 0, 3828, 1, 0, 0, 60192), -- Time Lord's Leggings
(44245, 224, 78824, 0, 3826, 1, 0, 0, 60192), -- Time Lord's Robes
(44245, 225, 78843, 0, 3830, 1, 0, 0, 60192), -- Time Lord's Mantle
(44245, 226, 78822, 0, 3832, 1, 0, 0, 60192), -- Battleplate of Radiant Glory
(44245, 227, 78770, 0, 3834, 1, 0, 0, 60192), -- Gauntlets of Radiant Glory
(44245, 228, 78788, 0, 3831, 1, 0, 0, 60192), -- Helmet of Radiant Glory
(44245, 229, 78807, 0, 3833, 1, 0, 0, 60192), -- Legplates of Radiant Glory
(44245, 230, 78837, 0, 3835, 1, 0, 0, 60192), -- Pauldrons of Radiant Glory
(44245, 231, 78821, 0, 3832, 1, 0, 0, 60192), -- Breastplate of Radiant Glory
(44245, 232, 78768, 0, 3834, 1, 0, 0, 60192), -- Gloves of Radiant Glory
(44245, 233, 78787, 0, 3831, 1, 0, 0, 60192), -- Headguard of Radiant Glory
(44245, 234, 78812, 0, 3833, 1, 0, 0, 60192), -- Greaves of Radiant Glory
(44245, 235, 78841, 0, 3835, 1, 0, 0, 60192), -- Mantle of Radiant Glory
(44245, 236, 78827, 0, 3832, 1, 0, 0, 60192), -- Chestguard of Radiant Glory
(44245, 237, 78772, 0, 3834, 1, 0, 0, 60192), -- Handguards of Radiant Glory
(44245, 238, 78790, 0, 3831, 1, 0, 0, 60192), -- Faceguard of Radiant Glory
(44245, 239, 78810, 0, 3833, 1, 0, 0, 60192), -- Legguards of Radiant Glory
(44245, 240, 78840, 0, 3835, 1, 0, 0, 60192), -- Shoulderguards of Radiant Glory
(44245, 241, 78778, 0, 3834, 1, 0, 0, 60192), -- Handwraps of Dying Light
(44245, 242, 78795, 0, 3831, 1, 0, 0, 60192), -- Cowl of Dying Light
(44245, 243, 78814, 0, 3833, 1, 0, 0, 60192), -- Legwraps of Dying Light
(44245, 244, 78823, 0, 3832, 1, 0, 0, 60192), -- Robes of Dying Light
(44245, 245, 78842, 0, 3835, 1, 0, 0, 60192), -- Mantle of Dying Light
(44245, 246, 78777, 0, 3834, 1, 0, 0, 60192), -- Gloves of Dying Light
(44245, 247, 78798, 0, 3831, 1, 0, 0, 60192), -- Hood of Dying Light
(44245, 248, 78817, 0, 3833, 1, 0, 0, 60192), -- Leggings of Dying Light
(44245, 249, 78826, 0, 3832, 1, 0, 0, 60192), -- Robes of Dying Light
(44245, 250, 78845, 0, 3835, 1, 0, 0, 60192), -- Mantle of Dying Light
(44245, 251, 78759, 0, 3826, 1, 0, 0, 60192), -- Blackfang Battleweave Tunic
(44245, 252, 78774, 0, 3829, 1, 0, 0, 60192), -- Blackfang Battleweave Gloves
(44245, 253, 78794, 0, 3827, 1, 0, 0, 60192), -- Blackfang Battleweave Helmet
(44245, 254, 78803, 0, 3828, 1, 0, 0, 60192), -- Blackfang Battleweave Legguards
(44245, 255, 78833, 0, 3830, 1, 0, 0, 60192), -- Blackfang Battleweave Spaulders
(44245, 256, 78820, 0, 3840, 1, 0, 0, 60192), -- Spiritwalker's Tunic
(44245, 257, 78767, 0, 3839, 1, 0, 0, 60192), -- Spiritwalker's Handwraps
(44245, 258, 78786, 0, 3837, 1, 0, 0, 60192), -- Spiritwalker's Faceguard
(44245, 259, 78813, 0, 3838, 1, 0, 0, 60192), -- Spiritwalker's Legwraps
(44245, 260, 78834, 0, 3836, 1, 0, 0, 60192), -- Spiritwalker's Mantle
(44245, 261, 78819, 0, 3840, 1, 0, 0, 60192), -- Spiritwalker's Cuirass
(44245, 262, 78762, 0, 3839, 1, 0, 0, 60192), -- Spiritwalker's Grips
(44245, 263, 78781, 0, 3837, 1, 0, 0, 60192), -- Spiritwalker's Helmet
(44245, 264, 78799, 0, 3838, 1, 0, 0, 60192), -- Spiritwalker's Legguards
(44245, 265, 78828, 0, 3836, 1, 0, 0, 60192), -- Spiritwalker's Spaulders
(44245, 266, 78818, 0, 3840, 1, 0, 0, 60192), -- Spiritwalker's Hauberk
(44245, 267, 78761, 0, 3839, 1, 0, 0, 60192), -- Spiritwalker's Gloves
(44245, 268, 78780, 0, 3837, 1, 0, 0, 60192), -- Spiritwalker's Headpiece
(44245, 269, 78806, 0, 3838, 1, 0, 0, 60192), -- Spiritwalker's Kilt
(44245, 270, 78836, 0, 3836, 1, 0, 0, 60192), -- Spiritwalker's Shoulderwraps
(44245, 271, 78776, 0, 3834, 1, 0, 0, 60192), -- Gloves of the Faceless Shroud
(44245, 272, 78797, 0, 3831, 1, 0, 0, 60192), -- Hood of the Faceless Shroud
(44245, 273, 78816, 0, 3833, 1, 0, 0, 60192), -- Leggings of the Faceless Shroud
(44245, 274, 78825, 0, 3832, 1, 0, 0, 60192), -- Robes of the Faceless Shroud
(44245, 275, 78844, 0, 3835, 1, 0, 0, 60192), -- Mantle of the Faceless Shroud
(44245, 276, 78752, 0, 3840, 1, 0, 0, 60192), -- Colossal Dragonplate Battleplate
(44245, 277, 78763, 0, 3839, 1, 0, 0, 60192), -- Colossal Dragonplate Gauntlets
(44245, 278, 78783, 0, 3837, 1, 0, 0, 60192), -- Colossal Dragonplate Helmet
(44245, 279, 78801, 0, 3838, 1, 0, 0, 60192), -- Colossal Dragonplate Legplates
(44245, 280, 78830, 0, 3836, 1, 0, 0, 60192), -- Colossal Dragonplate Pauldrons
(44245, 281, 78753, 0, 3840, 1, 0, 0, 60192), -- Colossal Dragonplate Chestguard
(44245, 282, 78764, 0, 3839, 1, 0, 0, 60192), -- Colossal Dragonplate Handguards
(44245, 283, 78784, 0, 3837, 1, 0, 0, 60192), -- Colossal Dragonplate Faceguard
(44245, 284, 78800, 0, 3838, 1, 0, 0, 60192), -- Colossal Dragonplate Legguards
(44245, 285, 78829, 0, 3836, 1, 0, 0, 60192), -- Colossal Dragonplate Shoulderguards
(44245, 286, 77091, 0, 3555, 1, 0, 0, 60192), -- Cameo of Terrible Memories
(44245, 287, 77090, 0, 3555, 1, 0, 0, 60192), -- Necklace of Black Dragon's Teeth
(44245, 288, 77092, 0, 3555, 1, 0, 0, 60192), -- Guardspike Choker
(44245, 289, 77089, 0, 3555, 1, 0, 0, 60192), -- Threadlinked Chain
(44245, 290, 77088, 0, 3555, 1, 0, 0, 60192), -- Opal of the Secret Order
(44245, 291, 77111, 0, 3555, 1, 0, 0, 60192), -- Emergency Descent Loop
(44245, 292, 77112, 0, 3555, 1, 0, 0, 60192), -- Signet of the Resolute
(44245, 293, 77110, 0, 3555, 1, 0, 0, 60192), -- Ring of Torn Flesh
(44245, 294, 77109, 0, 3555, 1, 0, 0, 60192), -- Band of Reconstruction
(44245, 295, 77108, 0, 3555, 1, 0, 0, 60192), -- Seal of the Grand Architect
(44245, 296, 77115, 0, 3556, 1, 0, 0, 60192), -- Reflection of the Light
(44245, 297, 77116, 0, 3556, 1, 0, 0, 60192), -- Rotting Skull
(44245, 298, 77113, 0, 3556, 1, 0, 0, 60192), -- Kiroptyric Sigil
(44245, 299, 77114, 0, 3556, 1, 0, 0, 60192), -- Bottled Wishes
(44245, 300, 77117, 0, 3556, 1, 0, 0, 60192), -- Fire of the Deep
(44245, 301, 77095, 0, 3555, 1, 0, 0, 60192), -- Batwing Cloak
(44245, 302, 77099, 0, 3555, 1, 0, 0, 60192), -- Indefatigable Greatcloak
(44245, 303, 77097, 0, 3555, 1, 0, 0, 60192), -- Dreamcrusher Drape
(44245, 304, 77096, 0, 3555, 1, 0, 0, 60192), -- Woundlicker Cover
(44245, 305, 77098, 0, 3555, 1, 0, 0, 60192), -- Nanoprecise Cape
(44245, 306, 77146, 0, 3557, 1, 0, 0, 60192), -- Soulgaze Cowl
(44245, 307, 77147, 0, 3557, 1, 0, 0, 60192), -- Hood of Hidden Flesh
(44245, 308, 77187, 0, 3556, 1, 0, 0, 60192), -- Vestal's Irrepressible Girdle
(44245, 309, 77179, 0, 3556, 1, 0, 0, 60192), -- Tentacular Belt
(44245, 310, 77177, 0, 3556, 1, 0, 0, 60192), -- Splinterfoot Sandals
(44245, 311, 77176, 0, 3556, 1, 0, 0, 60192), -- Kavan's Forsaken Treads
(44245, 312, 77323, 0, 3555, 1, 0, 0, 60192), -- Bracers of the Black Dream
(44245, 313, 77324, 0, 3555, 1, 0, 0, 60192), -- Chronoboost Bracers
(44245, 314, 77157, 0, 3556, 1, 0, 0, 60192), -- The Hands of Gilly
(44245, 315, 77159, 0, 3556, 1, 0, 0, 60192), -- Clockwinder's Immaculate Gloves
(44245, 316, 77121, 0, 3557, 1, 0, 0, 60192), -- Lightwarper Vestments
(44245, 317, 77122, 0, 3557, 1, 0, 0, 60192), -- Robes of Searing Shadow
(44245, 318, 77148, 0, 3557, 1, 0, 0, 60192), -- Nocturnal Gaze
(44245, 319, 77149, 0, 3557, 1, 0, 0, 60192), -- Helmet of Perpetual Rebirth
(44245, 320, 77126, 0, 3557, 1, 0, 0, 60192), -- Shadowbinder Chestguard
(44245, 321, 77180, 0, 3556, 1, 0, 0, 60192), -- Belt of Hidden Keys
(44245, 322, 77181, 0, 3556, 1, 0, 0, 60192), -- Belt of Universal Curing
(44245, 323, 77173, 0, 3556, 1, 0, 0, 60192), -- Rooftop Griptoes
(44245, 324, 77172, 0, 3556, 1, 0, 0, 60192), -- Boots of Fungoid Growth
(44245, 325, 77322, 0, 3555, 1, 0, 0, 60192), -- Bracers of Manifold Pockets
(44245, 326, 77320, 0, 3555, 1, 0, 0, 60192), -- Luminescent Bracers
(44245, 327, 77161, 0, 3556, 1, 0, 0, 60192), -- Lightfinger Handwraps
(44245, 328, 77160, 0, 3556, 1, 0, 0, 60192), -- Fungus-Born Gloves
(44245, 329, 77127, 0, 3557, 1, 0, 0, 60192), -- Decaying Herbalist's Robes
(44245, 330, 77150, 0, 3557, 1, 0, 0, 60192), -- Zeherah's Dragonskull Crown
(44245, 331, 77151, 0, 3557, 1, 0, 0, 60192), -- Wolfdream Circlet
(44245, 332, 77124, 0, 3557, 1, 0, 0, 60192), -- Dragonflayer Vest
(44245, 333, 77125, 0, 3557, 1, 0, 0, 60192), -- Ghostworld Chestguard
(44245, 334, 77182, 0, 3556, 1, 0, 0, 60192), -- Cord of Dragon Sinew
(44245, 335, 77183, 0, 3556, 1, 0, 0, 60192), -- Girdle of Shamanic Fury
(44245, 336, 77175, 0, 3556, 1, 0, 0, 60192), -- Boneshard Boots
(44245, 337, 77174, 0, 3556, 1, 0, 0, 60192), -- Sabatons of the Graceful Spirit
(44245, 338, 77321, 0, 3555, 1, 0, 0, 60192), -- Dragonbelly Bracers
(44245, 339, 77319, 0, 3555, 1, 0, 0, 60192), -- Bracers of the Spectral Wolf
(44245, 340, 77162, 0, 3556, 1, 0, 0, 60192), -- Arrowflick Gauntlets
(44245, 341, 77163, 0, 3556, 1, 0, 0, 60192), -- Gloves of Ghostly Dreams
(44245, 342, 77156, 0, 3557, 1, 0, 0, 60192), -- Jaw of Repudiation
(44245, 343, 77155, 0, 3557, 1, 0, 0, 60192), -- Visage of Petrification
(44245, 344, 77153, 0, 3557, 1, 0, 0, 60192), -- Glowing Wings of Hope
(44245, 345, 77120, 0, 3557, 1, 0, 0, 60192), -- Chestplate of the Unshakable Titan
(44245, 346, 77119, 0, 3557, 1, 0, 0, 60192), -- Bones of the Damned
(44245, 347, 77123, 0, 3557, 1, 0, 0, 60192), -- Shining Carapace of Glory
(44245, 348, 77186, 0, 3556, 1, 0, 0, 60192), -- Forgesmelter Waistplate
(44245, 349, 77185, 0, 3556, 1, 0, 0, 60192), -- Demonbone Waistguard
(44245, 350, 77184, 0, 3556, 1, 0, 0, 60192), -- Blinding Girdle of Truth
(44245, 351, 77171, 0, 3556, 1, 0, 0, 60192), -- Bladeshatter Treads
(44245, 352, 77170, 0, 3556, 1, 0, 0, 60192), -- Kneebreaker Boots
(44245, 353, 77169, 0, 3556, 1, 0, 0, 60192), -- Silver Sabatons of Fury
(44245, 354, 77318, 0, 3555, 1, 0, 0, 60192), -- Bracers of Unrelenting Excellence
(44245, 355, 77317, 0, 3555, 1, 0, 0, 60192), -- Heartcrusher Wristplates
(44245, 356, 77316, 0, 3555, 1, 0, 0, 60192), -- Flashing Bracers of Warmth
(44245, 357, 77166, 0, 3556, 1, 0, 0, 60192), -- Gauntlets of Feathery Blows
(44245, 358, 77165, 0, 3556, 1, 0, 0, 60192), -- Grimfist Crushers
(44245, 359, 77164, 0, 3556, 1, 0, 0, 60192), -- Gleaming Grips of Mending
(44245, 360, 77080, 0, 3553, 1, 0, 0, 60192), -- Ripfang Relic
(44245, 361, 77081, 0, 3553, 1, 0, 0, 60192), -- Gutripper Shard
(44245, 362, 77084, 0, 3553, 1, 0, 0, 60192), -- Stoutheart Talisman
(44245, 363, 77083, 0, 3553, 1, 0, 0, 60192), -- Lightning Spirit in a Bottle
(44245, 364, 77082, 0, 3553, 1, 0, 0, 60192), -- Mindbender Lens
(44245, 365, 77086, 0, 3553, 1, 0, 0, 60192), -- Windslicer Boomerang
(44245, 366, 77085, 0, 3553, 1, 0, 0, 60192), -- Unexpected Backup
(44245, 367, 77087, 0, 3553, 1, 0, 0, 60192), -- Darting Chakram
(44245, 368, 77078, 0, 3553, 1, 0, 0, 60192), -- Scintillating Rods
(44245, 369, 77079, 0, 3553, 1, 0, 0, 60192), -- Hungermouth Wand
(44245, 823, 390, 25000, 3411, 2, 0, 0, 60192), -- 390
-- 
(44246, 1, 71476, 0, 3609, 1, 0, 0, 60192), -- Elementium Deathplate Breastplate
(44246, 2, 71477, 0, 3589, 1, 0, 0, 60192), -- Elementium Deathplate Gauntlets
(44246, 3, 71478, 0, 3563, 1, 0, 0, 60192), -- Elementium Deathplate Helmet
(44246, 4, 71479, 0, 3570, 1, 0, 0, 60192), -- Elementium Deathplate Greaves
(44246, 5, 71480, 0, 3560, 1, 0, 0, 60192), -- Elementium Deathplate Pauldrons
(44246, 6, 71481, 0, 3610, 1, 0, 0, 60192), -- Elementium Deathplate Chestguard
(44246, 7, 71482, 0, 3590, 1, 0, 0, 60192), -- Elementium Deathplate Handguards
(44246, 8, 71483, 0, 3563, 1, 0, 0, 60192), -- Elementium Deathplate Faceguard
(44246, 9, 71484, 0, 3571, 1, 0, 0, 60192), -- Elementium Deathplate Legguards
(44246, 10, 71485, 0, 3560, 1, 0, 0, 60192), -- Elementium Deathplate Shoulderguards
(44246, 11, 71486, 0, 3611, 1, 0, 0, 60192), -- Obsidian Arborweave Raiment
(44246, 12, 71487, 0, 3591, 1, 0, 0, 60192), -- Obsidian Arborweave Grips
(44246, 13, 71488, 0, 3563, 1, 0, 0, 60192), -- Obsidian Arborweave Headpiece
(44246, 14, 71489, 0, 3572, 1, 0, 0, 60192), -- Obsidian Arborweave Legguards
(44246, 15, 71490, 0, 3560, 1, 0, 0, 60192), -- Obsidian Arborweave Spaulders
(44246, 16, 71491, 0, 3592, 1, 0, 0, 60192), -- Obsidian Arborweave Handwraps
(44246, 17, 71492, 0, 3563, 1, 0, 0, 60192), -- Obsidian Arborweave Helm
(44246, 18, 71493, 0, 3573, 1, 0, 0, 60192), -- Obsidian Arborweave Legwraps
(44246, 19, 71494, 0, 3613, 1, 0, 0, 60192), -- Obsidian Arborweave Tunic
(44246, 20, 71495, 0, 3560, 1, 0, 0, 60192), -- Obsidian Arborweave Mantle
(44246, 21, 71496, 0, 3593, 1, 0, 0, 60192), -- Obsidian Arborweave Gloves
(44246, 22, 71497, 0, 3563, 1, 0, 0, 60192), -- Obsidian Arborweave Cover
(44246, 23, 71498, 0, 3574, 1, 0, 0, 60192), -- Obsidian Arborweave Leggings
(44246, 24, 71499, 0, 3614, 1, 0, 0, 60192), -- Obsidian Arborweave Vestment
(44246, 25, 71500, 0, 3560, 1, 0, 0, 60192), -- Obsidian Arborweave Shoulderwraps
(44246, 26, 71501, 0, 3622, 1, 0, 0, 60192), -- Flamewaker's Tunic
(44246, 27, 71502, 0, 3596, 1, 0, 0, 60192), -- Flamewaker's Gloves
(44246, 28, 71503, 0, 3562, 1, 0, 0, 60192), -- Flamewaker's Headguard
(44246, 29, 71504, 0, 3577, 1, 0, 0, 60192), -- Flamewaker's Legguards
(44246, 30, 71505, 0, 3559, 1, 0, 0, 60192), -- Flamewaker's Spaulders
(44246, 31, 71507, 0, 3594, 1, 0, 0, 60192), -- Firehawk Gloves
(44246, 32, 71508, 0, 3563, 1, 0, 0, 60192), -- Firehawk Hood
(44246, 33, 71509, 0, 3575, 1, 0, 0, 60192), -- Firehawk Leggings
(44246, 34, 71510, 0, 3615, 1, 0, 0, 60192), -- Firehawk Robes
(44246, 35, 71511, 0, 3560, 1, 0, 0, 60192), -- Firehawk Mantle
(44246, 36, 71512, 0, 3628, 1, 0, 0, 60192), -- Immolation Battleplate
(44246, 37, 71513, 0, 3602, 1, 0, 0, 60192), -- Immolation Gauntlets
(44246, 38, 71514, 0, 3561, 1, 0, 0, 60192), -- Immolation Helmet
(44246, 39, 71515, 0, 3583, 1, 0, 0, 60192), -- Immolation Legplates
(44246, 40, 71516, 0, 3558, 1, 0, 0, 60192), -- Immolation Pauldrons
(44246, 41, 71517, 0, 3621, 1, 0, 0, 60192), -- Immolation Breastplate
(44246, 42, 71518, 0, 3603, 1, 0, 0, 60192), -- Immolation Gloves
(44246, 43, 71519, 0, 3561, 1, 0, 0, 60192), -- Immolation Headguard
(44246, 44, 71520, 0, 3584, 1, 0, 0, 60192), -- Immolation Greaves
(44246, 45, 71521, 0, 3558, 1, 0, 0, 60192), -- Immolation Mantle
(44246, 46, 71522, 0, 3616, 1, 0, 0, 60192), -- Immolation Chestguard
(44246, 47, 71523, 0, 3604, 1, 0, 0, 60192), -- Immolation Handguards
(44246, 48, 71524, 0, 3561, 1, 0, 0, 60192), -- Immolation Faceguard
(44246, 49, 71525, 0, 3585, 1, 0, 0, 60192), -- Immolation Legguards
(44246, 50, 71526, 0, 3558, 1, 0, 0, 60192), -- Immolation Shoulderguards
(44246, 51, 71527, 0, 3605, 1, 0, 0, 60192), -- Handwraps of the Cleansing Flame
(44246, 52, 71528, 0, 3561, 1, 0, 0, 60192), -- Cowl of the Cleansing Flame
(44246, 53, 71529, 0, 3586, 1, 0, 0, 60192), -- Legwraps of the Cleansing Flame
(44246, 54, 71530, 0, 3617, 1, 0, 0, 60192), -- Robes of the Cleansing Flame
(44246, 55, 71531, 0, 3558, 1, 0, 0, 60192), -- Mantle of the Cleansing Flame
(44246, 56, 71532, 0, 3608, 1, 0, 0, 60192), -- Gloves of the Cleansing Flame
(44246, 57, 71533, 0, 3561, 1, 0, 0, 60192), -- Hood of the Cleansing Flame
(44246, 58, 71534, 0, 3587, 1, 0, 0, 60192), -- Leggings of the Cleansing Flame
(44246, 59, 71535, 0, 3618, 1, 0, 0, 60192), -- Vestment of the Cleansing Flame
(44246, 60, 71536, 0, 3558, 1, 0, 0, 60192), -- Shoulderwraps of the Cleansing Flame
(44246, 61, 71537, 0, 3612, 1, 0, 0, 60192), -- Dark Phoenix Tunic
(44246, 62, 71538, 0, 3595, 1, 0, 0, 60192), -- Dark Phoenix Gloves
(44246, 63, 71539, 0, 3563, 1, 0, 0, 60192), -- Dark Phoenix Helmet
(44246, 64, 71540, 0, 3576, 1, 0, 0, 60192), -- Dark Phoenix Legguards
(44246, 65, 71541, 0, 3560, 1, 0, 0, 60192), -- Dark Phoenix Spaulders
(44246, 66, 71542, 0, 3623, 1, 0, 0, 60192), -- Erupting Volcanic Tunic
(44246, 67, 71543, 0, 3597, 1, 0, 0, 60192), -- Erupting Volcanic Handwraps
(44246, 68, 71544, 0, 3562, 1, 0, 0, 60192), -- Erupting Volcanic Faceguard
(44246, 69, 71545, 0, 3578, 1, 0, 0, 60192), -- Erupting Volcanic Legwraps
(44246, 70, 71546, 0, 3559, 1, 0, 0, 60192), -- Erupting Volcanic Mantle
(44246, 71, 71547, 0, 3624, 1, 0, 0, 60192), -- Erupting Volcanic Cuirass
(44246, 72, 71548, 0, 3598, 1, 0, 0, 60192), -- Erupting Volcanic Grips
(44246, 73, 71549, 0, 3562, 1, 0, 0, 60192), -- Erupting Volcanic Helmet
(44246, 74, 71550, 0, 3579, 1, 0, 0, 60192), -- Erupting Volcanic Legguards
(44246, 75, 71551, 0, 3559, 1, 0, 0, 60192), -- Erupting Volcanic Spaulders
(44246, 76, 71552, 0, 3625, 1, 0, 0, 60192), -- Erupting Volcanic Hauberk
(44246, 77, 71553, 0, 3599, 1, 0, 0, 60192), -- Erupting Volcanic Gloves
(44246, 78, 71554, 0, 3562, 1, 0, 0, 60192), -- Erupting Volcanic Headpiece
(44246, 79, 71555, 0, 3580, 1, 0, 0, 60192), -- Erupting Volcanic Kilt
(44246, 80, 71556, 0, 3559, 1, 0, 0, 60192), -- Erupting Volcanic Shoulderwraps
(44246, 81, 71594, 0, 3607, 1, 0, 0, 60192), -- Balespider's Handwraps
(44246, 82, 71595, 0, 3561, 1, 0, 0, 60192), -- Balespider's Hood
(44246, 83, 71596, 0, 3588, 1, 0, 0, 60192), -- Balespider's Leggings
(44246, 84, 71597, 0, 3619, 1, 0, 0, 60192), -- Balespider's Robes
(44246, 85, 71598, 0, 3558, 1, 0, 0, 60192), -- Balespider's Mantle
(44246, 86, 71599, 0, 3562, 1, 0, 0, 60192), -- Helmet of the Molten Giant
(44246, 87, 71600, 0, 3626, 1, 0, 0, 60192), -- Battleplate of the Molten Giant
(44246, 88, 71601, 0, 3600, 1, 0, 0, 60192), -- Gauntlets of the Molten Giant
(44246, 89, 71602, 0, 3581, 1, 0, 0, 60192), -- Legplates of the Molten Giant
(44246, 90, 71603, 0, 3559, 1, 0, 0, 60192), -- Pauldrons of the Molten Giant
(44246, 91, 71604, 0, 3627, 1, 0, 0, 60192), -- Chestguard of the Molten Giant
(44246, 92, 71605, 0, 3601, 1, 0, 0, 60192), -- Handguards of the Molten Giant
(44246, 93, 71606, 0, 3562, 1, 0, 0, 60192), -- Faceguard of the Molten Giant
(44246, 94, 71607, 0, 3582, 1, 0, 0, 60192), -- Legguards of the Molten Giant
(44246, 95, 71608, 0, 3559, 1, 0, 0, 60192), -- Shoulderguards of the Molten Giant
(44246, 96, 71058, 0, 3033, 1, 0, 0, 60192), -- Elementium Deathplate Breastplate
(44246, 97, 71059, 0, 3034, 1, 0, 0, 60192), -- Elementium Deathplate Gauntlets
(44246, 98, 71060, 0, 3566, 1, 0, 0, 60192), -- Elementium Deathplate Helmet
(44246, 99, 71061, 0, 3033, 1, 0, 0, 60192), -- Elementium Deathplate Greaves
(44246, 100, 71062, 0, 3569, 1, 0, 0, 60192), -- Elementium Deathplate Pauldrons
(44246, 101, 70955, 0, 3033, 1, 0, 0, 60192), -- Elementium Deathplate Chestguard
(44246, 102, 70953, 0, 3034, 1, 0, 0, 60192), -- Elementium Deathplate Handguards
(44246, 103, 70954, 0, 3566, 1, 0, 0, 60192), -- Elementium Deathplate Faceguard
(44246, 104, 70952, 0, 3033, 1, 0, 0, 60192), -- Elementium Deathplate Legguards
(44246, 105, 70951, 0, 3569, 1, 0, 0, 60192), -- Elementium Deathplate Shoulderguards
(44246, 106, 71100, 0, 3033, 1, 0, 0, 60192), -- Obsidian Arborweave Raiment
(44246, 107, 71097, 0, 3034, 1, 0, 0, 60192), -- Obsidian Arborweave Grips
(44246, 108, 71098, 0, 3566, 1, 0, 0, 60192), -- Obsidian Arborweave Headpiece
(44246, 109, 71099, 0, 3033, 1, 0, 0, 60192), -- Obsidian Arborweave Legguards
(44246, 110, 71101, 0, 3569, 1, 0, 0, 60192), -- Obsidian Arborweave Spaulders
(44246, 111, 71102, 0, 3034, 1, 0, 0, 60192), -- Obsidian Arborweave Handwraps
(44246, 112, 71103, 0, 3566, 1, 0, 0, 60192), -- Obsidian Arborweave Helm
(44246, 113, 71104, 0, 3033, 1, 0, 0, 60192), -- Obsidian Arborweave Legwraps
(44246, 114, 71105, 0, 3033, 1, 0, 0, 60192), -- Obsidian Arborweave Tunic
(44246, 115, 71106, 0, 3569, 1, 0, 0, 60192), -- Obsidian Arborweave Mantle
(44246, 116, 71107, 0, 3034, 1, 0, 0, 60192), -- Obsidian Arborweave Gloves
(44246, 117, 71108, 0, 3566, 1, 0, 0, 60192), -- Obsidian Arborweave Cover
(44246, 118, 71109, 0, 3033, 1, 0, 0, 60192), -- Obsidian Arborweave Leggings
(44246, 119, 71110, 0, 3033, 1, 0, 0, 60192), -- Obsidian Arborweave Vestment
(44246, 120, 71111, 0, 3569, 1, 0, 0, 60192), -- Obsidian Arborweave Shoulderwraps
(44246, 121, 71054, 0, 3033, 1, 0, 0, 60192), -- Flamewaker's Tunic
(44246, 122, 71050, 0, 3034, 1, 0, 0, 60192), -- Flamewaker's Gloves
(44246, 123, 71051, 0, 3565, 1, 0, 0, 60192), -- Flamewaker's Headguard
(44246, 124, 71052, 0, 3033, 1, 0, 0, 60192), -- Flamewaker's Legguards
(44246, 125, 71053, 0, 3568, 1, 0, 0, 60192), -- Flamewaker's Spaulders
(44246, 126, 71286, 0, 3034, 1, 0, 0, 60192), -- Firehawk Gloves
(44246, 127, 71287, 0, 3566, 1, 0, 0, 60192), -- Firehawk Hood
(44246, 128, 71288, 0, 3033, 1, 0, 0, 60192), -- Firehawk Leggings
(44246, 129, 71289, 0, 3033, 1, 0, 0, 60192), -- Firehawk Robes
(44246, 130, 71290, 0, 3569, 1, 0, 0, 60192), -- Firehawk Mantle
(44246, 131, 71063, 0, 3033, 1, 0, 0, 60192), -- Immolation Battleplate
(44246, 132, 71064, 0, 3034, 1, 0, 0, 60192), -- Immolation Gauntlets
(44246, 133, 71065, 0, 3564, 1, 0, 0, 60192), -- Immolation Helmet
(44246, 134, 71066, 0, 3033, 1, 0, 0, 60192), -- Immolation Legplates
(44246, 135, 71067, 0, 3567, 1, 0, 0, 60192), -- Immolation Pauldrons
(44246, 136, 71091, 0, 3033, 1, 0, 0, 60192), -- Immolation Breastplate
(44246, 137, 71092, 0, 3034, 1, 0, 0, 60192), -- Immolation Gloves
(44246, 138, 71093, 0, 3564, 1, 0, 0, 60192), -- Immolation Headguard
(44246, 139, 71094, 0, 3033, 1, 0, 0, 60192), -- Immolation Greaves
(44246, 140, 71095, 0, 3567, 1, 0, 0, 60192), -- Immolation Mantle
(44246, 141, 70950, 0, 3033, 1, 0, 0, 60192), -- Immolation Chestguard
(44246, 142, 70949, 0, 3034, 1, 0, 0, 60192), -- Immolation Handguards
(44246, 143, 70948, 0, 3564, 1, 0, 0, 60192), -- Immolation Faceguard
(44246, 144, 70947, 0, 3033, 1, 0, 0, 60192), -- Immolation Legguards
(44246, 145, 70946, 0, 3567, 1, 0, 0, 60192), -- Immolation Shoulderguards
(44246, 146, 71271, 0, 3034, 1, 0, 0, 60192), -- Handwraps of the Cleansing Flame
(44246, 147, 71272, 0, 3564, 1, 0, 0, 60192), -- Cowl of the Cleansing Flame
(44246, 148, 71273, 0, 3033, 1, 0, 0, 60192), -- Legwraps of the Cleansing Flame
(44246, 149, 71274, 0, 3033, 1, 0, 0, 60192), -- Robes of the Cleansing Flame
(44246, 150, 71275, 0, 3567, 1, 0, 0, 60192), -- Mantle of the Cleansing Flame
(44246, 151, 71276, 0, 3034, 1, 0, 0, 60192), -- Gloves of the Cleansing Flame
(44246, 152, 71277, 0, 3564, 1, 0, 0, 60192), -- Hood of the Cleansing Flame
(44246, 153, 71278, 0, 3033, 1, 0, 0, 60192), -- Leggings of the Cleansing Flame
(44246, 154, 71279, 0, 3033, 1, 0, 0, 60192), -- Vestment of the Cleansing Flame
(44246, 155, 71280, 0, 3567, 1, 0, 0, 60192), -- Shoulderwraps of the Cleansing Flame
(44246, 156, 71045, 0, 3033, 1, 0, 0, 60192), -- Dark Phoenix Tunic
(44246, 157, 71046, 0, 3034, 1, 0, 0, 60192), -- Dark Phoenix Gloves
(44246, 158, 71047, 0, 3566, 1, 0, 0, 60192), -- Dark Phoenix Helmet
(44246, 159, 71048, 0, 3033, 1, 0, 0, 60192), -- Dark Phoenix Legguards
(44246, 160, 71049, 0, 3569, 1, 0, 0, 60192), -- Dark Phoenix Spaulders
(44246, 161, 71296, 0, 3033, 1, 0, 0, 60192), -- Erupting Volcanic Tunic
(44246, 162, 71297, 0, 3034, 1, 0, 0, 60192), -- Erupting Volcanic Handwraps
(44246, 163, 71298, 0, 3565, 1, 0, 0, 60192), -- Erupting Volcanic Faceguard
(44246, 164, 71299, 0, 3033, 1, 0, 0, 60192), -- Erupting Volcanic Legwraps
(44246, 165, 71300, 0, 3568, 1, 0, 0, 60192), -- Erupting Volcanic Mantle
(44246, 166, 71301, 0, 3033, 1, 0, 0, 60192), -- Erupting Volcanic Cuirass
(44246, 167, 71302, 0, 3034, 1, 0, 0, 60192), -- Erupting Volcanic Grips
(44246, 168, 71303, 0, 3565, 1, 0, 0, 60192), -- Erupting Volcanic Helmet
(44246, 169, 71304, 0, 3033, 1, 0, 0, 60192), -- Erupting Volcanic Legguards
(44246, 170, 71305, 0, 3568, 1, 0, 0, 60192), -- Erupting Volcanic Spaulders
(44246, 171, 71291, 0, 3033, 1, 0, 0, 60192), -- Erupting Volcanic Hauberk
(44246, 172, 71292, 0, 3034, 1, 0, 0, 60192), -- Erupting Volcanic Gloves
(44246, 173, 71293, 0, 3565, 1, 0, 0, 60192), -- Erupting Volcanic Headpiece
(44246, 174, 71294, 0, 3033, 1, 0, 0, 60192), -- Erupting Volcanic Kilt
(44246, 175, 71295, 0, 3568, 1, 0, 0, 60192), -- Erupting Volcanic Shoulderwraps
(44246, 176, 71281, 0, 3034, 1, 0, 0, 60192), -- Balespider's Handwraps
(44246, 177, 71282, 0, 3564, 1, 0, 0, 60192), -- Balespider's Hood
(44246, 178, 71283, 0, 3033, 1, 0, 0, 60192), -- Balespider's Leggings
(44246, 179, 71284, 0, 3033, 1, 0, 0, 60192), -- Balespider's Robes
(44246, 180, 71285, 0, 3567, 1, 0, 0, 60192), -- Balespider's Mantle
(44246, 181, 71070, 0, 3565, 1, 0, 0, 60192), -- Helmet of the Molten Giant
(44246, 182, 71068, 0, 3033, 1, 0, 0, 60192), -- Battleplate of the Molten Giant
(44246, 183, 71069, 0, 3034, 1, 0, 0, 60192), -- Gauntlets of the Molten Giant
(44246, 184, 71071, 0, 3033, 1, 0, 0, 60192), -- Legplates of the Molten Giant
(44246, 185, 71072, 0, 3568, 1, 0, 0, 60192), -- Pauldrons of the Molten Giant
(44246, 186, 70945, 0, 3033, 1, 0, 0, 60192), -- Chestguard of the Molten Giant
(44246, 187, 70943, 0, 3034, 1, 0, 0, 60192), -- Handguards of the Molten Giant
(44246, 188, 70944, 0, 3565, 1, 0, 0, 60192), -- Faceguard of the Molten Giant
(44246, 189, 70942, 0, 3033, 1, 0, 0, 60192), -- Legguards of the Molten Giant
(44246, 190, 70941, 0, 3568, 1, 0, 0, 60192), -- Shoulderguards of the Molten Giant
(44246, 191, 71210, 0, 3035, 1, 0, 0, 60192), -- Crystalline Brimstone Ring
(44246, 192, 70940, 0, 3035, 1, 0, 0, 60192), -- Deflecting Brimstone Band
(44246, 193, 71208, 0, 3035, 1, 0, 0, 60192), -- Serrated Brimstone Signet
(44246, 194, 71211, 0, 3035, 1, 0, 0, 60192), -- Soothing Brimstone Circle
(44246, 195, 71209, 0, 3035, 1, 0, 0, 60192), -- Splintered Brimstone Seal
(44246, 196, 71213, 0, 3035, 1, 0, 0, 60192), -- Amulet of Burning Brilliance
(44246, 197, 71214, 0, 3035, 1, 0, 0, 60192), -- Firemind Pendant
(44246, 198, 71129, 0, 3035, 1, 0, 0, 60192), -- Necklace of Smoke Signals
(44246, 199, 71212, 0, 3035, 1, 0, 0, 60192), -- Stoneheart Choker
(44246, 200, 70935, 0, 3035, 1, 0, 0, 60192), -- Stoneheart Necklace
(44246, 201, 71264, 0, 3035, 1, 0, 0, 60192), -- Bracers of Forked Lightning
(44246, 202, 71260, 0, 3035, 1, 0, 0, 60192), -- Bracers of Imperious Truths
(44246, 203, 71263, 0, 3035, 1, 0, 0, 60192), -- Bracers of Misting Ash
(44246, 204, 70937, 0, 3035, 1, 0, 0, 60192), -- Bracers of Regal Force
(44246, 205, 71265, 0, 3035, 1, 0, 0, 60192), -- Emberflame Bracers
(44246, 206, 71266, 0, 3035, 1, 0, 0, 60192), -- Firesoul Wristguards
(44246, 207, 71130, 0, 3035, 1, 0, 0, 60192), -- Flamebinder Bracers
(44246, 208, 71261, 0, 3035, 1, 0, 0, 60192), -- Gigantiform Bracers
(44246, 209, 71262, 0, 3035, 1, 0, 0, 60192), -- Smolderskull Bindings
(44246, 210, 71146, 0, 3037, 1, 0, 0, 60192), -- Covenant of the Flame
(44246, 211, 70939, 0, 3037, 1, 0, 0, 60192), -- Deathclutch Figurine
(44246, 212, 71147, 0, 3037, 1, 0, 0, 60192), -- Relic of the Elemental Lords
(44246, 213, 71149, 0, 3037, 1, 0, 0, 60192), -- Singed Plume of Aviana
(44246, 214, 71148, 0, 3037, 1, 0, 0, 60192), -- Soulflame Vial
(44246, 215, 71150, 0, 3037, 1, 0, 0, 60192), -- Scorchvine Wand
(44246, 216, 71151, 0, 3037, 1, 0, 0, 60192), -- Trail of Embers
(44246, 217, 71218, 0, 3037, 1, 0, 0, 60192), -- Deflecting Star
(44246, 218, 71154, 0, 3037, 1, 0, 0, 60192), -- Giantslicer
(44246, 219, 71152, 0, 3037, 1, 0, 0, 60192), -- Morningstar Shard
--
(58154, 1, 58126, 0, 3038, 1, 0, 0, 60192), -- Vest of the Waking Dream
(58154, 2, 58131, 0, 3038, 1, 0, 0, 60192), -- Tunic of Sinking Envy
(58154, 3, 58101, 0, 3038, 1, 0, 0, 60192), -- Chestplate of the Steadfast
(58154, 4, 58096, 0, 3038, 1, 0, 0, 60192), -- Breastplate of Raging Fury
(58154, 5, 58106, 0, 3038, 1, 0, 0, 60192), -- Chestguard of Dancing Waves
(58154, 6, 58121, 0, 3038, 1, 0, 0, 60192), -- Vest of the True Companion
(58154, 7, 58130, 0, 3039, 1, 0, 0, 60192), -- Gleaning Gloves
(58154, 8, 58138, 0, 3039, 1, 0, 0, 60192), -- Sticky Fingers
(58154, 9, 58163, 0, 3039, 1, 0, 0, 60192), -- Gloves of Purification
(58154, 10, 58105, 0, 3039, 1, 0, 0, 60192), -- Numbing Handguards
(58154, 11, 58099, 0, 3039, 1, 0, 0, 60192), -- Reaping Gauntlets
(58154, 12, 58110, 0, 3039, 1, 0, 0, 60192), -- Gloves of Curious Conscience
(58154, 13, 58125, 0, 3039, 1, 0, 0, 60192), -- Gloves of the Passing Night
(58154, 14, 58152, 0, 3039, 1, 0, 0, 60192), -- Blessed Hands of Elune
(58154, 15, 58158, 0, 3039, 1, 0, 0, 60192), -- Gloves of the Painless Midnight
(58154, 16, 58128, 0, 3038, 1, 0, 0, 60192), -- Helm of the Inward Eye
(58154, 17, 58133, 0, 3038, 1, 0, 0, 60192), -- Mask of Vines
(58154, 18, 58161, 0, 3038, 1, 0, 0, 60192), -- Mask of New Snow
(58154, 19, 58103, 0, 3038, 1, 0, 0, 60192), -- Helm of the Proud
(58154, 20, 58098, 0, 3038, 1, 0, 0, 60192), -- Helm of Easeful Death
(58154, 21, 58108, 0, 3038, 1, 0, 0, 60192), -- Crown of the Blazing Sun
(58154, 22, 58123, 0, 3038, 1, 0, 0, 60192), -- Willow Mask
(58154, 23, 58150, 0, 3038, 1, 0, 0, 60192), -- Cluster of Stars
(58154, 24, 58155, 0, 3038, 1, 0, 0, 60192), -- Cowl of Pleasant Gloom
(58154, 25, 57924, 0, 3041, 1, 0, 0, 60192), -- Apple-Bent Bough
(58154, 26, 57923, 0, 3041, 1, 0, 0, 60192), -- Hermit's Lamp
(58154, 27, 58127, 0, 3038, 1, 0, 0, 60192), -- Leggings of Soothing Silence
(58154, 28, 58132, 0, 3038, 1, 0, 0, 60192), -- Leggings of the Burrowing Mole
(58154, 29, 58160, 0, 3038, 1, 0, 0, 60192), -- Leggings of Charity
(58154, 30, 58102, 0, 3038, 1, 0, 0, 60192), -- Greaves of Splendor
(58154, 31, 58097, 0, 3038, 1, 0, 0, 60192), -- Greaves of Gallantry
(58154, 32, 58107, 0, 3038, 1, 0, 0, 60192), -- Legguards of the Gentle
(58154, 33, 58122, 0, 3038, 1, 0, 0, 60192), -- Hillside Striders
(58154, 34, 58140, 0, 3038, 1, 0, 0, 60192), -- Leggings of Late Blooms
(58154, 35, 58154, 0, 3038, 1, 0, 0, 60192), -- Pensive Legwraps
(58154, 36, 57932, 0, 3040, 1, 0, 0, 60192), -- The Lustrous Eye
(58154, 37, 57930, 0, 3040, 1, 0, 0, 60192), -- Pendant of Quiet Breath
(58154, 38, 57934, 0, 3040, 1, 0, 0, 60192), -- Celadon Pendant
(58154, 39, 57933, 0, 3040, 1, 0, 0, 60192), -- String of Beaded Bubbles
(58154, 40, 57931, 0, 3040, 1, 0, 0, 60192), -- Amulet of Dull Dreaming
(58154, 41, 57929, 0, 3041, 1, 0, 0, 60192), -- Dawnblaze Blade
(58154, 42, 57928, 0, 3041, 1, 0, 0, 60192), -- Windslicer
(58154, 43, 57927, 0, 3041, 1, 0, 0, 60192), -- Throat Slasher
(58154, 44, 58159, 0, 3038, 1, 0, 0, 60192), -- Musk Rose Robes
(58154, 45, 58139, 0, 3038, 1, 0, 0, 60192), -- Chestguard of Forgetfulness
(58154, 46, 58153, 0, 3038, 1, 0, 0, 60192), -- Robes of Embalmed Darkness
(58154, 47, 57926, 0, 3041, 1, 0, 0, 60192), -- Shield of the Four Grey Towers
(58154, 48, 57925, 0, 3041, 1, 0, 0, 60192), -- Shield of the Mists
(58154, 49, 58129, 0, 3039, 1, 0, 0, 60192), -- Seafoam Mantle
(58154, 50, 58134, 0, 3039, 1, 0, 0, 60192), -- Embrace of the Night
(58154, 51, 58162, 0, 3039, 1, 0, 0, 60192), -- Summer Song Shoulderwraps
(58154, 52, 58104, 0, 3039, 1, 0, 0, 60192), -- Sunburnt Pauldrons
(58154, 53, 58100, 0, 3039, 1, 0, 0, 60192), -- Pauldrons of the High Requiem
(58154, 54, 58109, 0, 3039, 1, 0, 0, 60192), -- Pauldrons of the Forlorn
(58154, 55, 58124, 0, 3039, 1, 0, 0, 60192), -- Wrap of the Valley Glades
(58154, 56, 58151, 0, 3039, 1, 0, 0, 60192), -- Somber Shawl
(58154, 57, 58157, 0, 3039, 1, 0, 0, 60192), -- Meadow Mantle
(58154, 58, 57917, 0, 3039, 1, 0, 0, 60192), -- Belt of the Still Stream
(58154, 59, 57918, 0, 3039, 1, 0, 0, 60192), -- Sash of Musing
(58154, 60, 57922, 0, 3039, 1, 0, 0, 60192), -- Belt of the Falling Rain
(58154, 61, 57914, 0, 3039, 1, 0, 0, 60192), -- Girdle of the Mountains
(58154, 62, 57913, 0, 3039, 1, 0, 0, 60192), -- Beech Green Belt
(58154, 63, 57915, 0, 3039, 1, 0, 0, 60192), -- Belt of Barred Clouds
(58154, 64, 57916, 0, 3039, 1, 0, 0, 60192), -- Belt of the Dim Forest
(58154, 65, 57921, 0, 3039, 1, 0, 0, 60192), -- Incense Infused Cummerbund
(58154, 66, 57919, 0, 3039, 1, 0, 0, 60192), -- Thatch Eave Vines
(58154, 67, 58194, 0, 3035, 1, 0, 0, 60192), -- Heavenly Breeze
(58154, 68, 58190, 0, 3035, 1, 0, 0, 60192), -- Floating Web
(58154, 69, 58193, 0, 3035, 1, 0, 0, 60192), -- Haunt of Flies
(58154, 70, 58192, 0, 3035, 1, 0, 0, 60192), -- Gray Hair Cloak
(58154, 71, 58191, 0, 3035, 1, 0, 0, 60192), -- Viewless Wings
(58154, 72, 58486, 0, 3034, 1, 0, 0, 60192), -- Slippers of Moving Waters
(58154, 73, 58485, 0, 3034, 1, 0, 0, 60192), -- Melodious Slippers
(58154, 74, 58484, 0, 3034, 1, 0, 0, 60192), -- Fading Violet Sandals
(58154, 75, 58482, 0, 3034, 1, 0, 0, 60192), -- Treads of Fleeting Joy
(58154, 76, 58481, 0, 3034, 1, 0, 0, 60192), -- Boots of the Perilous Seas
(58154, 77, 58199, 0, 3034, 1, 0, 0, 60192), -- Moccasins of Verdurous Glooms
(58154, 78, 58198, 0, 3034, 1, 0, 0, 60192), -- Eternal Pathfinders
(58154, 79, 58197, 0, 3034, 1, 0, 0, 60192), -- Rock Furrow Boots
(58154, 80, 58195, 0, 3034, 1, 0, 0, 60192), -- Woe Breeder's Boots
(58154, 81, 58189, 0, 3035, 1, 0, 0, 60192), -- Twined Band of Flowers
(58154, 82, 58188, 0, 3035, 1, 0, 0, 60192), -- Band of Secret Names
(58154, 83, 58187, 0, 3035, 1, 0, 0, 60192), -- Ring of the Battle Anthem
(58154, 84, 58185, 0, 3035, 1, 0, 0, 60192), -- Band of Bees
(58154, 85, 68812, 0, 3035, 1, 0, 0, 60192), -- Hornet-Sting Band
(58154, 86, 64676, 0, 3037, 1, 0, 0, 60192), -- Relic of Khaz'goroth
(58154, 87, 64674, 0, 3037, 1, 0, 0, 60192), -- Relic of Aggramar
(58154, 88, 64673, 0, 3037, 1, 0, 0, 60192), -- Relic of Eonar
(58154, 89, 64672, 0, 3037, 1, 0, 0, 60192), -- Relic of Norgannon
(58154, 90, 64671, 0, 3037, 1, 0, 0, 60192), -- Relic of Golganneth
(58154, 91, 58184, 0, 3034, 1, 0, 0, 60192), -- Core of Ripeness
(58154, 92, 58183, 0, 3034, 1, 0, 0, 60192), -- Soul Casket
(58154, 93, 58182, 0, 3034, 1, 0, 0, 60192), -- Bedrock Talisman
(58154, 94, 58181, 0, 3034, 1, 0, 0, 60192), -- Fluid Death
(58154, 95, 58180, 0, 3034, 1, 0, 0, 60192), -- License to Slay
(58154, 96, 60360, 0, 3033, 1, 0, 0, 60192), -- Reinforced Sapphirium Breastplate
(58154, 97, 60354, 0, 3033, 1, 0, 0, 60192), -- Reinforced Sapphirium Chestguard
(58154, 98, 60349, 0, 3033, 1, 0, 0, 60192), -- Magma Plated Chestguard
(58154, 99, 60339, 0, 3033, 1, 0, 0, 60192), -- Magma Plated Battleplate
(58154, 100, 60329, 0, 3033, 1, 0, 0, 60192), -- Earthen Chestguard
(58154, 101, 60344, 0, 3033, 1, 0, 0, 60192), -- Reinforced Sapphirium Battleplate
(58154, 102, 60323, 0, 3033, 1, 0, 0, 60192), -- Earthen Battleplate
(58154, 103, 60318, 0, 3033, 1, 0, 0, 60192), -- Cuirass of the Raging Elements
(58154, 104, 60309, 0, 3033, 1, 0, 0, 60192), -- Tunic of the Raging Elements
(58154, 105, 60313, 0, 3033, 1, 0, 0, 60192), -- Hauberk of the Raging Elements
(58154, 106, 60304, 0, 3033, 1, 0, 0, 60192), -- Lightning-Charged Tunic
(58154, 107, 60301, 0, 3033, 1, 0, 0, 60192), -- Wind Dancer's Tunic
(58154, 108, 60280, 0, 3034, 1, 0, 0, 60192), -- Stormrider's Handwraps
(58154, 109, 60275, 0, 3034, 1, 0, 0, 60192), -- Mercurial Handwraps
(58154, 110, 60290, 0, 3034, 1, 0, 0, 60192), -- Stormrider's Grips
(58154, 111, 60285, 0, 3034, 1, 0, 0, 60192), -- Stormrider's Gloves
(58154, 112, 60248, 0, 3034, 1, 0, 0, 60192), -- Shadowflame Handwraps
(58154, 113, 60257, 0, 3034, 1, 0, 0, 60192), -- Mercurial Gloves
(58154, 114, 60247, 0, 3034, 1, 0, 0, 60192), -- Firelord's Gloves
(58154, 115, 60363, 0, 3034, 1, 0, 0, 60192), -- Reinforced Sapphirium Gloves
(58154, 116, 60355, 0, 3034, 1, 0, 0, 60192), -- Reinforced Sapphirium Handguards
(58154, 117, 60350, 0, 3034, 1, 0, 0, 60192), -- Magma Plated Handguards
(58154, 118, 60345, 0, 3034, 1, 0, 0, 60192), -- Reinforced Sapphirium Gauntlets
(58154, 119, 60332, 0, 3034, 1, 0, 0, 60192), -- Earthen Handguards
(58154, 120, 60340, 0, 3034, 1, 0, 0, 60192), -- Magma Plated Gauntlets
(58154, 121, 60326, 0, 3034, 1, 0, 0, 60192), -- Earthen Gauntlets
(58154, 122, 60319, 0, 3034, 1, 0, 0, 60192), -- Grips of the Raging Elements
(58154, 123, 60314, 0, 3034, 1, 0, 0, 60192), -- Gloves of the Raging Elements
(58154, 124, 60307, 0, 3034, 1, 0, 0, 60192), -- Lightning-Charged Gloves
(58154, 125, 60312, 0, 3034, 1, 0, 0, 60192), -- Handwraps of the Raging Elements
(58154, 126, 60298, 0, 3034, 1, 0, 0, 60192), -- Wind Dancer's Gloves
(58154, 127, 60282, 0, 3049, 1, 0, 0, 60192), -- Stormrider's Cover
(58154, 128, 60277, 0, 3049, 1, 0, 0, 60192), -- Stormrider's Helm
(58154, 129, 60286, 0, 3049, 1, 0, 0, 60192), -- Stormrider's Headpiece
(58154, 130, 60249, 0, 3050, 1, 0, 0, 60192), -- Shadowflame Hood
(58154, 131, 60243, 0, 3049, 1, 0, 0, 60192), -- Firelord's Hood
(58154, 132, 60258, 0, 3050, 1, 0, 0, 60192), -- Mercurial Cowl
(58154, 133, 60256, 0, 3050, 1, 0, 0, 60192), -- Mercurial Hood
(58154, 134, 60359, 0, 3050, 1, 0, 0, 60192), -- Reinforced Sapphirium Headguard
(58154, 135, 60356, 0, 3050, 1, 0, 0, 60192), -- Reinforced Sapphirium Faceguard
(58154, 136, 60351, 0, 3049, 1, 0, 0, 60192), -- Magma Plated Faceguard
(58154, 137, 60346, 0, 3050, 1, 0, 0, 60192), -- Reinforced Sapphirium Helmet
(58154, 138, 60341, 0, 3049, 1, 0, 0, 60192), -- Magma Plated Helmet
(58154, 139, 60328, 0, 3051, 1, 0, 0, 60192), -- Earthen Faceguard
(58154, 140, 60320, 0, 3051, 1, 0, 0, 60192), -- Helmet of the Raging Elements
(58154, 141, 60325, 0, 3051, 1, 0, 0, 60192), -- Earthen Helmet
(58154, 142, 60315, 0, 3051, 1, 0, 0, 60192), -- Headpiece of the Raging Elements
(58154, 143, 60303, 0, 3051, 1, 0, 0, 60192), -- Lightning-Charged Headguard
(58154, 144, 60308, 0, 3051, 1, 0, 0, 60192), -- Faceguard of the Raging Elements
(58154, 145, 60299, 0, 3049, 1, 0, 0, 60192), -- Wind Dancer's Helmet
(58154, 146, 60278, 0, 3033, 1, 0, 0, 60192), -- Stormrider's Legwraps
(58154, 147, 60288, 0, 3033, 1, 0, 0, 60192), -- Stormrider's Legguards
(58154, 148, 60283, 0, 3033, 1, 0, 0, 60192), -- Stormrider's Leggings
(58154, 149, 60250, 0, 3033, 1, 0, 0, 60192), -- Shadowflame Leggings
(58154, 150, 60245, 0, 3033, 1, 0, 0, 60192), -- Firelord's Leggings
(58154, 151, 60261, 0, 3033, 1, 0, 0, 60192), -- Mercurial Legwraps
(58154, 152, 60255, 0, 3033, 1, 0, 0, 60192), -- Mercurial Leggings
(58154, 153, 60361, 0, 3033, 1, 0, 0, 60192), -- Reinforced Sapphirium Greaves
(58154, 154, 60357, 0, 3033, 1, 0, 0, 60192), -- Reinforced Sapphirium Legguards
(58154, 155, 60352, 0, 3033, 1, 0, 0, 60192), -- Magma Plated Legguards
(58154, 156, 60347, 0, 3033, 1, 0, 0, 60192), -- Reinforced Sapphirium Legplates
(58154, 157, 60342, 0, 3033, 1, 0, 0, 60192), -- Magma Plated Legplates
(58154, 158, 60330, 0, 3033, 1, 0, 0, 60192), -- Earthen Legguards
(58154, 159, 60324, 0, 3033, 1, 0, 0, 60192), -- Earthen Legplates
(58154, 160, 60321, 0, 3033, 1, 0, 0, 60192), -- Legguards of the Raging Elements
(58154, 161, 60316, 0, 3033, 1, 0, 0, 60192), -- Kilt of the Raging Elements
(58154, 162, 60310, 0, 3033, 1, 0, 0, 60192), -- Legwraps of the Raging Elements
(58154, 163, 60305, 0, 3033, 1, 0, 0, 60192), -- Lightning-Charged Legguards
(58154, 164, 60300, 0, 3033, 1, 0, 0, 60192), -- Wind Dancer's Legguards
(58154, 165, 60281, 0, 3033, 1, 0, 0, 60192), -- Stormrider's Vestment
(58154, 166, 60276, 0, 3033, 1, 0, 0, 60192), -- Stormrider's Robes
(58154, 167, 60287, 0, 3033, 1, 0, 0, 60192), -- Stormrider's Raiment
(58154, 168, 60254, 0, 3033, 1, 0, 0, 60192), -- Mercurial Vestment
(58154, 169, 60251, 0, 3033, 1, 0, 0, 60192), -- Shadowflame Robes
(58154, 170, 60244, 0, 3033, 1, 0, 0, 60192), -- Firelord's Robes
(58154, 171, 60259, 0, 3033, 1, 0, 0, 60192), -- Mercurial Robes
(58154, 172, 60279, 0, 3043, 1, 0, 0, 60192), -- Stormrider's Mantle
(58154, 173, 60289, 0, 3043, 1, 0, 0, 60192), -- Stormrider's Spaulders
(58154, 174, 60284, 0, 3043, 1, 0, 0, 60192), -- Stormrider's Shoulderwraps
(58154, 175, 60253, 0, 3044, 1, 0, 0, 60192), -- Mercurial Shoulderwraps
(58154, 176, 60252, 0, 3044, 1, 0, 0, 60192), -- Shadowflame Mantle
(58154, 177, 60246, 0, 3043, 1, 0, 0, 60192), -- Firelord's Mantle
(58154, 178, 60262, 0, 3044, 1, 0, 0, 60192), -- Mercurial Mantle
(58154, 179, 60362, 0, 3044, 1, 0, 0, 60192), -- Reinforced Sapphirium Mantle
(58154, 180, 60358, 0, 3044, 1, 0, 0, 60192), -- Reinforced Sapphirium Shoulderguards
(58154, 181, 60353, 0, 3043, 1, 0, 0, 60192), -- Magma Plated Shoulderguards
(58154, 182, 60348, 0, 3044, 1, 0, 0, 60192), -- Reinforced Sapphirium Pauldrons
(58154, 183, 60343, 0, 3043, 1, 0, 0, 60192), -- Magma Plated Pauldrons
(58154, 184, 60331, 0, 3045, 1, 0, 0, 60192), -- Earthen Shoulderguards
(58154, 185, 60327, 0, 3045, 1, 0, 0, 60192), -- Earthen Pauldrons
(58154, 186, 60322, 0, 3045, 1, 0, 0, 60192), -- Spaulders of the Raging Elements
(58154, 187, 60317, 0, 3045, 1, 0, 0, 60192), -- Shoulderwraps of the Raging Elements
(58154, 188, 60311, 0, 3045, 1, 0, 0, 60192), -- Mantle of the Raging Elements
(58154, 189, 60306, 0, 3045, 1, 0, 0, 60192), -- Lightning-Charged Spaulders
(58154, 190, 60302, 0, 3043, 1, 0, 0, 60192), -- Wind Dancer's Spaulders
(58154, 191, 67425, 0, 3329, 1, 0, 0, 60192), -- Chest of the Forlorn Vanquisher
(58154, 192, 67423, 0, 3329, 1, 0, 0, 60192), -- Chest of the Forlorn Conqueror
(58154, 193, 67424, 0, 3329, 1, 0, 0, 60192), -- Chest of the Forlorn Protector
(58154, 194, 65089, 0, 3329, 1, 0, 0, 60192), -- Shoulders of the Forlorn Vanquisher
(58154, 195, 65088, 0, 3329, 1, 0, 0, 60192), -- Shoulders of the Forlorn Conqueror
(58154, 196, 65087, 0, 3329, 1, 0, 0, 60192), -- Shoulders of the Forlorn Protector
(58154, 197, 67431, 0, 3329, 1, 0, 0, 60192), -- Gauntlets of the Forlorn Vanquisher
(58154, 198, 67429, 0, 3329, 1, 0, 0, 60192), -- Gauntlets of the Forlorn Conqueror
(58154, 199, 67430, 0, 3329, 1, 0, 0, 60192), -- Gauntlets of the Forlorn Protector
(58154, 200, 65002, 0, 3329, 1, 0, 0, 60192), -- Crown of the Forlorn Vanquisher
(58154, 201, 65001, 0, 3329, 1, 0, 0, 60192), -- Crown of the Forlorn Conqueror
(58154, 202, 65000, 0, 3329, 1, 0, 0, 60192), -- Crown of the Forlorn Protector
(58154, 203, 67426, 0, 3329, 1, 0, 0, 60192), -- Leggings of the Forlorn Vanquisher
(58154, 204, 67428, 0, 3329, 1, 0, 0, 60192), -- Leggings of the Forlorn Conqueror
(58154, 205, 67427, 0, 3329, 1, 0, 0, 60192), -- Leggings of the Forlorn Protector
(58154, 206, 65179, 0, 3085, 1, 0, 0, 60192), -- Magma Plated Battleplate
(58154, 207, 65180, 0, 3145, 1, 0, 0, 60192), -- Magma Plated Gauntlets
(58154, 208, 65181, 0, 3069, 1, 0, 0, 60192), -- Magma Plated Helmet
(58154, 209, 65182, 0, 3113, 1, 0, 0, 60192), -- Magma Plated Legplates
(58154, 210, 65183, 0, 3136, 1, 0, 0, 60192), -- Magma Plated Pauldrons
(58154, 211, 65184, 0, 3084, 1, 0, 0, 60192), -- Magma Plated Chestguard
(58154, 212, 65185, 0, 3146, 1, 0, 0, 60192), -- Magma Plated Handguards
(58154, 213, 65186, 0, 3068, 1, 0, 0, 60192), -- Magma Plated Faceguard
(58154, 214, 65187, 0, 3112, 1, 0, 0, 60192), -- Magma Plated Legguards
(58154, 215, 65188, 0, 3135, 1, 0, 0, 60192), -- Magma Plated Shoulderguards
(58154, 216, 65189, 0, 3147, 1, 0, 0, 60192), -- Stormrider's Grips
(58154, 217, 65190, 0, 3067, 1, 0, 0, 60192), -- Stormrider's Headpiece
(58154, 218, 65191, 0, 3111, 1, 0, 0, 60192), -- Stormrider's Legguards
(58154, 219, 65192, 0, 3093, 1, 0, 0, 60192), -- Stormrider's Raiment
(58154, 220, 65193, 0, 3134, 1, 0, 0, 60192), -- Stormrider's Spaulders
(58154, 221, 65194, 0, 3148, 1, 0, 0, 60192), -- Stormrider's Handwraps
(58154, 222, 65195, 0, 3066, 1, 0, 0, 60192), -- Stormrider's Helm
(58154, 223, 65196, 0, 3110, 1, 0, 0, 60192), -- Stormrider's Legwraps
(58154, 224, 65197, 0, 3092, 1, 0, 0, 60192), -- Stormrider's Robes
(58154, 225, 65198, 0, 3133, 1, 0, 0, 60192), -- Stormrider's Mantle
(58154, 226, 65199, 0, 3149, 1, 0, 0, 60192), -- Stormrider's Gloves
(58154, 227, 65200, 0, 3065, 1, 0, 0, 60192), -- Stormrider's Cover
(58154, 228, 65201, 0, 3109, 1, 0, 0, 60192), -- Stormrider's Leggings
(58154, 229, 65202, 0, 3091, 1, 0, 0, 60192), -- Stormrider's Vestment
(58154, 230, 65203, 0, 3132, 1, 0, 0, 60192), -- Stormrider's Shoulderwraps
(58154, 231, 65204, 0, 3083, 1, 0, 0, 60192), -- Lightning-Charged Tunic
(58154, 232, 65205, 0, 3150, 1, 0, 0, 60192), -- Lightning-Charged Gloves
(58154, 233, 65206, 0, 3064, 1, 0, 0, 60192), -- Lightning-Charged Headguard
(58154, 234, 65207, 0, 3108, 1, 0, 0, 60192), -- Lightning-Charged Legguards
(58154, 235, 65208, 0, 3131, 1, 0, 0, 60192), -- Lightning-Charged Spaulders
(58154, 236, 65209, 0, 3151, 1, 0, 0, 60192), -- Firelord's Gloves
(58154, 237, 65210, 0, 3063, 1, 0, 0, 60192), -- Firelord's Hood
(58154, 238, 65211, 0, 3107, 1, 0, 0, 60192), -- Firelord's Leggings
(58154, 239, 65212, 0, 3090, 1, 0, 0, 60192), -- Firelord's Robes
(58154, 240, 65213, 0, 3130, 1, 0, 0, 60192), -- Firelord's Mantle
(58154, 241, 65214, 0, 3082, 1, 0, 0, 60192), -- Reinforced Sapphirium Battleplate
(58154, 242, 65215, 0, 3152, 1, 0, 0, 60192), -- Reinforced Sapphirium Gauntlets
(58154, 243, 65216, 0, 3062, 1, 0, 0, 60192), -- Reinforced Sapphirium Helmet
(58154, 244, 65217, 0, 3106, 1, 0, 0, 60192), -- Reinforced Sapphirium Legplates
(58154, 245, 65218, 0, 3129, 1, 0, 0, 60192), -- Reinforced Sapphirium Pauldrons
(58154, 246, 65219, 0, 3081, 1, 0, 0, 60192), -- Reinforced Sapphirium Breastplate
(58154, 247, 65220, 0, 3153, 1, 0, 0, 60192), -- Reinforced Sapphirium Gloves
(58154, 248, 65221, 0, 3061, 1, 0, 0, 60192), -- Reinforced Sapphirium Headguard
(58154, 249, 65222, 0, 3105, 1, 0, 0, 60192), -- Reinforced Sapphirium Greaves
(58154, 250, 65223, 0, 3128, 1, 0, 0, 60192), -- Reinforced Sapphirium Mantle
(58154, 251, 65224, 0, 3080, 1, 0, 0, 60192), -- Reinforced Sapphirium Chestguard
(58154, 252, 65225, 0, 3154, 1, 0, 0, 60192), -- Reinforced Sapphirium Handguards
(58154, 253, 65226, 0, 3060, 1, 0, 0, 60192), -- Reinforced Sapphirium Faceguard
(58154, 254, 65227, 0, 3104, 1, 0, 0, 60192), -- Reinforced Sapphirium Legguards
(58154, 255, 65228, 0, 3127, 1, 0, 0, 60192), -- Reinforced Sapphirium Shoulderguards
(58154, 256, 65229, 0, 3155, 1, 0, 0, 60192), -- Mercurial Handwraps
(58154, 257, 65230, 0, 3117, 1, 0, 0, 60192), -- Mercurial Cowl
(58154, 258, 65231, 0, 3103, 1, 0, 0, 60192), -- Mercurial Legwraps
(58154, 259, 65232, 0, 3089, 1, 0, 0, 60192), -- Mercurial Robes
(58154, 260, 65233, 0, 3126, 1, 0, 0, 60192), -- Mercurial Mantle
(58154, 261, 65234, 0, 3156, 1, 0, 0, 60192), -- Mercurial Gloves
(58154, 262, 65235, 0, 3059, 1, 0, 0, 60192), -- Mercurial Hood
(58154, 263, 65236, 0, 3102, 1, 0, 0, 60192), -- Mercurial Leggings
(58154, 264, 65237, 0, 3088, 1, 0, 0, 60192), -- Mercurial Vestment
(58154, 265, 65238, 0, 3125, 1, 0, 0, 60192), -- Mercurial Shoulderwraps
(58154, 266, 65239, 0, 3079, 1, 0, 0, 60192), -- Wind Dancer's Tunic
(58154, 267, 65240, 0, 3157, 1, 0, 0, 60192), -- Wind Dancer's Gloves
(58154, 268, 65241, 0, 3058, 1, 0, 0, 60192), -- Wind Dancer's Helmet
(58154, 269, 65242, 0, 3101, 1, 0, 0, 60192), -- Wind Dancer's Legguards
(58154, 270, 65243, 0, 3124, 1, 0, 0, 60192), -- Wind Dancer's Spaulders
(58154, 271, 65244, 0, 3078, 1, 0, 0, 60192), -- Tunic of the Raging Elements
(58154, 272, 65245, 0, 3158, 1, 0, 0, 60192), -- Handwraps of the Raging Elements
(58154, 273, 65246, 0, 3057, 1, 0, 0, 60192), -- Faceguard of the Raging Elements
(58154, 274, 65247, 0, 3100, 1, 0, 0, 60192), -- Legwraps of the Raging Elements
(58154, 275, 65248, 0, 3123, 1, 0, 0, 60192), -- Mantle of the Raging Elements
(58154, 276, 65249, 0, 3077, 1, 0, 0, 60192), -- Cuirass of the Raging Elements
(58154, 277, 65250, 0, 3159, 1, 0, 0, 60192), -- Grips of the Raging Elements
(58154, 278, 65251, 0, 3053, 1, 0, 0, 60192), -- Helmet of the Raging Elements
(58154, 279, 65252, 0, 3099, 1, 0, 0, 60192), -- Legguards of the Raging Elements
(58154, 280, 65253, 0, 3122, 1, 0, 0, 60192), -- Spaulders of the Raging Elements
(58154, 281, 65254, 0, 3076, 1, 0, 0, 60192), -- Hauberk of the Raging Elements
(58154, 282, 65255, 0, 3144, 1, 0, 0, 60192), -- Gloves of the Raging Elements
(58154, 283, 65256, 0, 3052, 1, 0, 0, 60192), -- Headpiece of the Raging Elements
(58154, 284, 65257, 0, 3098, 1, 0, 0, 60192), -- Kilt of the Raging Elements
(58154, 285, 65258, 0, 3121, 1, 0, 0, 60192), -- Shoulderwraps of the Raging Elements
(58154, 286, 65259, 0, 3143, 1, 0, 0, 60192), -- Shadowflame Handwraps
(58154, 287, 65260, 0, 3072, 1, 0, 0, 60192), -- Shadowflame Hood
(58154, 288, 65261, 0, 3116, 1, 0, 0, 60192), -- Shadowflame Leggings
(58154, 289, 65262, 0, 3094, 1, 0, 0, 60192), -- Shadowflame Robes
(58154, 290, 65263, 0, 3139, 1, 0, 0, 60192), -- Shadowflame Mantle
(58154, 291, 65264, 0, 3087, 1, 0, 0, 60192), -- Earthen Battleplate
(58154, 292, 65265, 0, 3160, 1, 0, 0, 60192), -- Earthen Gauntlets
(58154, 293, 65266, 0, 3071, 1, 0, 0, 60192), -- Earthen Helmet
(58154, 294, 65267, 0, 3115, 1, 0, 0, 60192), -- Earthen Legplates
(58154, 295, 65268, 0, 3138, 1, 0, 0, 60192), -- Earthen Pauldrons
(58154, 296, 65269, 0, 3086, 1, 0, 0, 60192), -- Earthen Chestguard
(58154, 297, 65270, 0, 3161, 1, 0, 0, 60192), -- Earthen Handguards
(58154, 298, 65271, 0, 3070, 1, 0, 0, 60192), -- Earthen Faceguard
(58154, 299, 65272, 0, 3097, 1, 0, 0, 60192), -- Earthen Legguards
(58154, 300, 65273, 0, 3137, 1, 0, 0, 60192), -- Earthen Shoulderguards
--
(52028, 1, 52722, 0, 9326, 1, 0, 0, 60192), -- Maelstrom Crystal
(52028, 2, 52555, 0, 9332, 1, 0, 0, 60192), -- Hypnotic Dust
(52028, 3, 52719, 0, 9330, 1, 0, 0, 60192), -- Greater Celestial Essence
(52028, 4, 52721, 0, 9328, 1, 0, 0, 60192), -- Heavenly Shard
(52028, 5, 52976, 0, 9324, 1, 0, 0, 60192), -- Savage Leather
(52028, 6, 53010, 0, 9322, 1, 0, 0, 60192), -- Embersilk Cloth
(52028, 7, 52185, 0, 9334, 1, 0, 0, 60192), -- Elementium Ore
(52028, 8, 68813, 0, 9337, 1, 0, 0, 60192), -- Satchel of Freshly-Picked Herbs
(52028, 9, 1901, 25000, 3408, 2, 0, 0, 60192), -- 1901
-- 
(234135, 1, 63683, 0, 9668, 1, 0, 0, 60192), -- Helm of the Forlorn Conqueror
(234135, 2, 63684, 0, 9668, 1, 0, 0, 60192), -- Helm of the Forlorn Protector
(234135, 3, 64315, 0, 9668, 1, 0, 0, 60192), -- Mantle of the Forlorn Conqueror
(234135, 4, 64316, 0, 9668, 1, 0, 0, 60192), -- Mantle of the Forlorn Protector
(234135, 5, 64314, 0, 9668, 1, 0, 0, 60192), -- Mantle of the Forlorn Vanquisher
(234135, 6, 63682, 0, 9668, 1, 0, 0, 60192), -- Helm of the Forlorn Vanquisher
(234135, 7, 232947, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 8, 232948, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 9, 232949, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 10, 232950, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 11, 232951, 0, 9669, 1, 0, 0, 60192), -- -Unknown-
(234135, 12, 232952, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 13, 232953, 0, 9669, 1, 0, 0, 60192), -- -Unknown-
(234135, 14, 232954, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 15, 232955, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 16, 232956, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 17, 232957, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 18, 232958, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 19, 232959, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 20, 232960, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 21, 232961, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 22, 232962, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 23, 232963, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 24, 232964, 0, 9670, 1, 0, 0, 60192), -- -Unknown-
(234135, 25, 232965, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 26, 232966, 0, 9669, 1, 0, 0, 60192), -- -Unknown-
(234135, 27, 232967, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 28, 232968, 0, 9669, 1, 0, 0, 60192), -- -Unknown-
(234135, 29, 232969, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 30, 232970, 0, 9669, 1, 0, 0, 60192), -- -Unknown-
(234135, 31, 232971, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 32, 232972, 0, 9670, 1, 0, 0, 60192), -- -Unknown-
(234135, 33, 232973, 0, 9671, 1, 0, 0, 60192), -- -Unknown-
(234135, 34, 232974, 0, 9669, 1, 0, 0, 60192), -- -Unknown-
(234135, 35, 59122, 0, 9673, 1, 0, 0, 60192), -- Organic Lifeform Inverter
(234135, 36, 59333, 0, 9673, 1, 0, 0, 60192), -- Lava Spine
(234135, 37, 59347, 0, 9673, 1, 0, 0, 60192), -- Mace of Acrid Death
(234135, 38, 59443, 0, 9673, 1, 0, 0, 60192), -- Crul'korak, the Lightning's Arc
(234135, 39, 63533, 0, 9673, 1, 0, 0, 60192), -- Fang of Twilight
(234135, 40, 59494, 0, 9673, 1, 0, 0, 60192), -- "Uhn'agh Fash, the Darkest Betrayal"
(234135, 41, 59330, 0, 9672, 1, 0, 0, 60192), -- Shalug'doom, the Axe of Unmaking
(234135, 42, 59341, 0, 9675, 1, 0, 0, 60192), -- Incineratus
(234135, 43, 59459, 0, 9675, 1, 0, 0, 60192), -- Andoros, Fist of the Dragon King
(234135, 44, 63536, 0, 9675, 1, 0, 0, 60192), -- Blade of the Witching Hour
(234135, 45, 63680, 0, 9675, 1, 0, 0, 60192), -- Twilight's Hammer
(234135, 46, 59327, 0, 9673, 1, 0, 0, 60192), -- Kingdom's Heart
(234135, 47, 59444, 0, 9673, 1, 0, 0, 60192), -- Akmin-Kurai, Dominion's Shield
(234135, 48, 59492, 0, 9672, 1, 0, 0, 60192), -- Akirus the Worm-Breaker
(234135, 49, 63679, 0, 9672, 1, 0, 0, 60192), -- Reclaimed Ashkandi, Greatsword of the Brotherhood
(234135, 50, 59474, 0, 9672, 1, 0, 0, 60192), -- Malevolence
(234135, 51, 59484, 0, 9674, 1, 0, 0, 60192), -- Book of Binding Will
(234135, 52, 59513, 0, 9674, 1, 0, 0, 60192), -- Scepter of Ice
(234135, 53, 59320, 0, 9672, 1, 0, 0, 60192), -- Themios the Darkbringer
(234135, 54, 59314, 0, 9674, 1, 0, 0, 60192), -- Finkle's Mixer Upper
(234135, 55, 63532, 0, 9672, 1, 0, 0, 60192), -- Dragonheart Piercer
(234135, 56, 65085, 0, 9637, 1, 0, 0, 60192), -- Electron Inductor Coils
(234135, 57, 65143, 0, 9637, 1, 0, 0, 60192), -- Bracers of Impossible Strength
(234135, 58, 65127, 0, 9637, 1, 0, 0, 60192), -- Shackles of the End of Days
(234135, 59, 65028, 0, 9637, 1, 0, 0, 60192), -- Chimaeron Armguards
(234135, 60, 65068, 0, 9637, 1, 0, 0, 60192), -- Chaos Beast Bracers
(234135, 61, 65021, 0, 9637, 1, 0, 0, 60192), -- Manacles of the Sleeping Beast
(234135, 62, 65050, 0, 9637, 1, 0, 0, 60192), -- Parasitic Bands
(234135, 63, 65056, 0, 9637, 1, 0, 0, 60192), -- Bracers of the Burningeye
(234135, 64, 65138, 0, 9637, 1, 0, 0, 60192), -- Bracers of the Bronze Flight
(234135, 65, 65074, 0, 9638, 1, 0, 0, 60192), -- Spaulders of the Scarred Lady
(234135, 66, 65027, 0, 9638, 1, 0, 0, 60192), -- Pauldrons of the Apocalypse
(234135, 67, 65025, 0, 9637, 1, 0, 0, 60192), -- Rage of Ages
(234135, 68, 65018, 0, 9637, 1, 0, 0, 60192), -- Shadow of Dread
(234135, 69, 65057, 0, 9639, 1, 0, 0, 60192), -- Belt of the Nightmare
(234135, 70, 65022, 0, 9639, 1, 0, 0, 60192), -- Belt of the Blackhand
(234135, 71, 65043, 0, 9638, 1, 0, 0, 60192), -- Mantle of Nefarius
(234135, 72, 65019, 0, 9638, 1, 0, 0, 60192), -- Shadowblaze Robes
(234135, 73, 65026, 0, 9639, 1, 0, 0, 60192), -- Prestor's Talisman of Machination
(234135, 74, 65053, 0, 9639, 1, 0, 0, 60192), -- Bell of Enraging Resonance
(234135, 75, 65140, 0, 9639, 1, 0, 0, 60192), -- Essence of the Cyclone
(234135, 76, 65105, 0, 9639, 1, 0, 0, 60192), -- Theralion's Mirror
(234135, 77, 65124, 0, 9639, 1, 0, 0, 60192), -- Fall of Mortality
(234135, 78, 65072, 0, 9639, 1, 0, 0, 60192), -- Heart of Rage
(234135, 79, 65048, 0, 9639, 1, 0, 0, 60192), -- Symbiotic Worm
(234135, 80, 65118, 0, 9639, 1, 0, 0, 60192), -- Crushing Weight
(234135, 81, 65110, 0, 9639, 1, 0, 0, 60192), -- Heart of Ignacious
(234135, 82, 65109, 0, 9639, 1, 0, 0, 60192), -- Vial of Stolen Memories
(234135, 83, 65029, 0, 9639, 1, 0, 0, 60192), -- Jar of Ancient Remedies
(234135, 84, 60226, 0, 9640, 1, 0, 0, 60192), -- Dargonax's Signet
(234135, 85, 60227, 0, 9640, 1, 0, 0, 60192), -- Caelestrasz's Will
(234135, 86, 60231, 0, 9640, 1, 0, 0, 60192), -- Belt of the Fallen Brood
(234135, 87, 60229, 0, 9640, 1, 0, 0, 60192), -- War-Torn Crushers
(234135, 88, 60230, 0, 9640, 1, 0, 0, 60192), -- Twilight Scale Leggings
(234135, 89, 60228, 0, 9640, 1, 0, 0, 60192), -- Bracers of the Mat'redor
(234135, 90, 60236, 0, 9640, 1, 0, 0, 60192), -- Nightmare Rider's Boots
(234135, 91, 60237, 0, 9640, 1, 0, 0, 60192), -- Crown of the Twilight Queen
(234135, 92, 60238, 0, 9640, 1, 0, 0, 60192), -- Bracers of the Dark Mother
(234135, 93, 60235, 0, 9640, 1, 0, 0, 60192), -- Boots of Az'galada
(234135, 94, 60233, 0, 9640, 1, 0, 0, 60192), -- Shard of Woe
(234135, 95, 60234, 0, 9640, 1, 0, 0, 60192), -- Bindings of Bleak Betrayal
(234135, 96, 60232, 0, 9640, 1, 0, 0, 60192), -- Shroud of Endless Grief
(234135, 97, 234446, 0, 9676, 1, 0, 0, 60192), -- -Unknown-
--
(241468, 1, 71668, 0, 10249, 1, 0, 0, 60192), -- Helm of the Fiery Vanquisher
(241468, 2, 71675, 0, 10249, 1, 0, 0, 60192), -- Helm of the Fiery Conqueror
(241468, 3, 71682, 0, 10249, 1, 0, 0, 60192), -- Helm of the Fiery Protector
(241468, 4, 71674, 0, 10249, 1, 0, 0, 60192), -- Mantle of the Fiery Vanquisher
(241468, 5, 71681, 0, 10249, 1, 0, 0, 60192), -- Mantle of the Fiery Conqueror
(241468, 6, 71688, 0, 10249, 1, 0, 0, 60192), -- Mantle of the Fiery Protector
(241468, 7, 78862, 0, 10250, 1, 0, 0, 60192), -- Chest of the Corrupted Vanquisher
(241468, 8, 78863, 0, 10250, 1, 0, 0, 60192), -- Chest of the Corrupted Conqueror
(241468, 9, 78864, 0, 10250, 1, 0, 0, 60192), -- Chest of the Corrupted Protector
(241468, 10, 78865, 0, 10251, 1, 0, 0, 60192), -- Gauntlets of the Corrupted Vanquisher
(241468, 11, 78866, 0, 10251, 1, 0, 0, 60192), -- Gauntlets of the Corrupted Conqueror
(241468, 12, 78867, 0, 10251, 1, 0, 0, 60192), -- Gauntlets of the Corrupted Protector
(241468, 13, 78868, 0, 10250, 1, 0, 0, 60192), -- Crown of the Corrupted Vanquisher
(241468, 14, 78869, 0, 10250, 1, 0, 0, 60192), -- Crown of the Corrupted Conqueror
(241468, 15, 78870, 0, 10250, 1, 0, 0, 60192), -- Crown of the Corrupted Protector
(241468, 16, 78871, 0, 10250, 1, 0, 0, 60192), -- Leggings of the Corrupted Vanquisher
(241468, 17, 78872, 0, 10250, 1, 0, 0, 60192), -- Leggings of the Corrupted Conqueror
(241468, 18, 78873, 0, 10250, 1, 0, 0, 60192), -- Leggings of the Corrupted Protector
(241468, 19, 78874, 0, 10251, 1, 0, 0, 60192), -- Shoulders of the Corrupted Vanquisher
(241468, 20, 78875, 0, 10251, 1, 0, 0, 60192), -- Shoulders of the Corrupted Conqueror
(241468, 21, 78876, 0, 10251, 1, 0, 0, 60192), -- Shoulders of the Corrupted Protector
(241468, 22, 239111, 0, 10276, 1, 0, 0, 60192), -- -Unknown-
(241468, 23, 239112, 0, 10278, 1, 0, 0, 60192), -- -Unknown-
(241468, 24, 239220, 0, 10278, 1, 0, 0, 60192), -- -Unknown-
(241468, 25, 239113, 0, 10277, 1, 0, 0, 60192), -- -Unknown-
(241468, 26, 239114, 0, 10278, 1, 0, 0, 60192), -- -Unknown-
(241468, 27, 78382, 0, 10264, 1, 0, 0, 60192), -- Petrified Fungal Heart
(241468, 28, 78381, 0, 10264, 1, 0, 0, 60192), -- Mosswrought Shoulderguards
(241468, 29, 78443, 0, 10264, 1, 0, 0, 60192), -- Imperfect Specimens 27 and 28
(241468, 30, 78378, 0, 10264, 1, 0, 0, 60192), -- Brackenshell Shoulderplates
(241468, 31, 78375, 0, 10264, 1, 0, 0, 60192), -- Underdweller's Spaulders
(241468, 32, 78395, 0, 10265, 1, 0, 0, 60192), -- Belt of Flayed Skin
(241468, 33, 78444, 0, 10265, 1, 0, 0, 60192), -- Dragonfracture Belt
(241468, 34, 78398, 0, 10265, 1, 0, 0, 60192), -- Cord of the Slain Champion
(241468, 35, 78385, 0, 10265, 1, 0, 0, 60192), -- Girdle of Shattered Stone
(241468, 36, 78455, 0, 10265, 1, 0, 0, 60192), -- Belt of the Beloved Companion
(241468, 37, 78460, 0, 10265, 1, 0, 0, 60192), -- Goriona's Collar
(241468, 38, 78424, 0, 10265, 1, 0, 0, 60192), -- Runescriven Demon Collar
(241468, 39, 78428, 0, 10265, 1, 0, 0, 60192), -- Girdle of the Grotesque
(241468, 40, 78423, 0, 10265, 1, 0, 0, 60192), -- Treads of Dormant Dreams
(241468, 41, 78439, 0, 10265, 1, 0, 0, 60192), -- Stillheart Warboots
(241468, 42, 78411, 0, 10265, 1, 0, 0, 60192), -- Mindstrainer Treads
(241468, 43, 78442, 0, 10265, 1, 0, 0, 60192), -- Treads of Sordid Screams
(241468, 44, 78408, 0, 10265, 1, 0, 0, 60192), -- Interrogator's Bloody Footpads
(241468, 45, 78457, 0, 10265, 1, 0, 0, 60192), -- Janglespur Jackboots
(241468, 46, 78386, 0, 10265, 1, 0, 0, 60192), -- Pillarfoot Greaves
(241468, 47, 78396, 0, 10265, 1, 0, 0, 60192), -- Treads of Crushed Flesh
(241468, 48, 78397, 0, 10264, 1, 0, 0, 60192), -- Graveheart Bracers
(241468, 49, 78377, 0, 10264, 1, 0, 0, 60192), -- Rockhide Bracers
(241468, 50, 78425, 0, 10264, 1, 0, 0, 60192), -- Bracers of the Banished
(241468, 51, 78400, 0, 10264, 1, 0, 0, 60192), -- Grotesquely Writhing Bracers
(241468, 52, 78438, 0, 10264, 1, 0, 0, 60192), -- Bracers of Looming Darkness
(241468, 53, 78454, 0, 10264, 1, 0, 0, 60192), -- Shadow Wing Armbands
(241468, 54, 78384, 0, 10264, 1, 0, 0, 60192), -- Mycosynth Wristguards
(241468, 55, 78412, 0, 10264, 1, 0, 0, 60192), -- Heartblood Wristplates
(241468, 56, 78376, 0, 10264, 1, 0, 0, 60192), -- Sporebeard Gauntlets
(241468, 57, 78440, 0, 10264, 1, 0, 0, 60192), -- Curled Twilight Claw
(241468, 58, 78494, 0, 10264, 1, 0, 0, 60192), -- Seal of Primordial Shadow
(241468, 59, 78497, 0, 10264, 1, 0, 0, 60192), -- Breathstealer Band
(241468, 60, 78421, 0, 10264, 1, 0, 0, 60192), -- Signet of Grasping Mouths
(241468, 61, 78496, 0, 10264, 1, 0, 0, 60192), -- Signet of Suturing
(241468, 62, 78498, 0, 10264, 1, 0, 0, 60192), -- Hardheart Ring
(241468, 63, 78427, 0, 10264, 1, 0, 0, 60192), -- Ring of the Riven
(241468, 64, 78495, 0, 10264, 1, 0, 0, 60192), -- Infinite Loop
(241468, 65, 77982, 0, 10265, 1, 0, 0, 60192), -- Bone-Link Fetish
(241468, 66, 77972, 0, 10265, 1, 0, 0, 60192), -- Creche of the Final Dragon
(241468, 67, 77973, 0, 10265, 1, 0, 0, 60192), -- Starcatcher Compass
(241468, 68, 77971, 0, 10265, 1, 0, 0, 60192), -- Insignia of the Corrupted Mind
(241468, 69, 77969, 0, 10265, 1, 0, 0, 60192), -- Seal of the Seven Signs
(241468, 70, 77983, 0, 10265, 1, 0, 0, 60192), -- Indomitable Pride
(241468, 71, 77981, 0, 10265, 1, 0, 0, 60192), -- Windward Heart
(241468, 72, 77980, 0, 10265, 1, 0, 0, 60192), -- Cunning of the Cruel
(241468, 73, 77970, 0, 10265, 1, 0, 0, 60192), -- Soulshifter Vortex
(241468, 74, 77979, 0, 10265, 1, 0, 0, 60192), -- Vial of Shadows
(241468, 75, 78422, 0, 10265, 1, 0, 0, 60192), -- Electrowing Dagger
(241468, 76, 78458, 0, 10265, 1, 0, 0, 60192), -- Timepiece of the Bronze Flight
(241468, 77, 78456, 0, 10265, 1, 0, 0, 60192), -- Blackhorn's Mighty Bulwark
(241468, 78, 78380, 0, 10266, 1, 0, 0, 60192), -- Robe of Glowing Stone
(241468, 79, 78441, 0, 10261, 1, 0, 0, 60192), -- Ledger of Revolting Rituals
(241468, 80, 78374, 0, 10261, 1, 0, 0, 60192), -- Razor Saronite Chip
(241468, 81, 78399, 0, 10263, 1, 0, 0, 60192), -- Finger of Zon'ozz
(241468, 82, 78470, 0, 10272, 1, 0, 0, 60192), -- Backbreaker Spaulders
(241468, 83, 78468, 0, 10267, 1, 0, 0, 60192), -- Belt of Shattered Elementium
(241468, 84, 78467, 0, 10267, 1, 0, 0, 60192), -- Molten Blood Footpads
(241468, 85, 78469, 0, 10272, 1, 0, 0, 60192), -- Gauntlets of the Golden Thorn
(241468, 86, 78466, 0, 10272, 1, 0, 0, 60192), -- Gloves of Liquid Smoke
(241468, 87, 77978, 0, 10267, 1, 0, 0, 60192), -- Resolve of Undying
(241468, 88, 77975, 0, 10267, 1, 0, 0, 60192), -- Will of Unbinding
(241468, 89, 77977, 0, 10267, 1, 0, 0, 60192), -- Eye of Unmaking
(241468, 90, 77976, 0, 10267, 1, 0, 0, 60192), -- Heart of Unliving
(241468, 91, 77974, 0, 10267, 1, 0, 0, 60192), -- Wrath of Unchaining
(241468, 92, 78488, 0, 10268, 1, 0, 0, 60192), -- Souldrinker
(241468, 93, 78481, 0, 10268, 1, 0, 0, 60192), -- No'Kaled, the Elements of Death
(241468, 94, 78483, 0, 10268, 1, 0, 0, 60192), -- Blade of the Unmaker
(241468, 95, 78480, 0, 10271, 1, 0, 0, 60192), -- Vishanka, Jaws of the Earth
(241468, 96, 78482, 0, 10271, 1, 0, 0, 60192), -- Kiril, Fury of Beasts
(241468, 97, 78486, 0, 10271, 1, 0, 0, 60192), -- Ti'tahk, the Steps of Time
(241468, 98, 78487, 0, 10271, 1, 0, 0, 60192), -- Gurthalak, Voice of the Deeps
(241468, 99, 78485, 0, 10270, 1, 0, 0, 60192), -- Maw of the Dragonlord
(241468, 100, 78484, 0, 10270, 1, 0, 0, 60192), -- Rathrak, the Poisonous Mind
(241468, 101, 71312, 0, 10252, 1, 0, 0, 60192), -- Gatecrasher
(241468, 102, 71013, 0, 10252, 1, 0, 0, 60192), -- Feeding Frenzy
(241468, 103, 71785, 0, 10258, 1, 0, 0, 60192), -- Firethorn Mindslicer
(241468, 104, 71776, 0, 10258, 1, 0, 0, 60192), -- Eye of Purification
(241468, 105, 71782, 0, 10252, 1, 0, 0, 60192), -- Shatterskull Bonecrusher
(241468, 106, 71779, 0, 10252, 1, 0, 0, 60192), -- Avool's Incendiary Shanker
(241468, 107, 71787, 0, 10252, 1, 0, 0, 60192), -- Entrail Disgorger
(241468, 108, 70922, 0, 10252, 1, 0, 0, 60192), -- Mandible of Beth'tilac
(241468, 109, 70733, 0, 10252, 1, 0, 0, 60192), -- Alysra's Razor
(241468, 110, 70915, 0, 10252, 1, 0, 0, 60192), -- Shard of Torment
(241468, 111, 69897, 0, 10255, 1, 0, 0, 60192), -- Fandral's Flamescythe
(241468, 112, 71780, 0, 10255, 1, 0, 0, 60192), -- Zoid's Firelit Greatsword
(241468, 113, 71014, 0, 10255, 1, 0, 0, 60192), -- Skullstealer Greataxe
(241468, 114, 71775, 0, 10255, 1, 0, 0, 60192), -- Smoldering Censer of Purity
(241468, 115, 71039, 0, 10255, 1, 0, 0, 60192), -- Funeral Pyre
(241468, 116, 71323, 0, 10253, 1, 0, 0, 60192), -- Molten Scream
(241468, 117, 70991, 0, 10255, 1, 0, 0, 60192), -- Arbalest of Erupting Fury
(241468, 118, 71347, 0, 10255, 1, 0, 0, 60192), -- Stinger of the Flaming Scorpion
(241468, 119, 71355, 0, 10256, 1, 0, 0, 60192), -- Ko'gun, Hammer of the Firelord
(241468, 120, 71352, 0, 10257, 1, 0, 0, 60192), -- Sulfuras, the Extinguished Hand
(241468, 121, 71798, 0, 10257, 1, 0, 0, 60192), -- Sho'ravon, Greatstaff of Annihilation
(241468, 122, 71353, 0, 10257, 1, 0, 0, 60192), -- Arathar, the Eye of Flame
(241468, 123, 69109, 0, 10259, 1, 0, 0, 60192), -- Scales of Life
(241468, 124, 69111, 0, 10259, 1, 0, 0, 60192), -- Jaws of Defeat
(241468, 125, 69112, 0, 10259, 1, 0, 0, 60192), -- The Hungerer
(241468, 126, 69139, 0, 10259, 1, 0, 0, 60192), -- Necromantic Focus
(241468, 127, 69113, 0, 10259, 1, 0, 0, 60192), -- Apparatus of Khaz'goroth
(241468, 128, 69138, 0, 10259, 1, 0, 0, 60192), -- Spidersilk Spindle
(241468, 129, 69149, 0, 10259, 1, 0, 0, 60192), -- Eye of Blazing Power
(241468, 130, 69110, 0, 10260, 1, 0, 0, 60192), -- Variable Pulse Lightning Capacitor
(241468, 131, 69150, 0, 10260, 1, 0, 0, 60192), -- Matrix Restabilizer
(241468, 132, 69167, 0, 10260, 1, 0, 0, 60192), -- Vessel of Acceleration
(241468, 133, 239110, 0, 10273, 1, 0, 0, 60192), -- -Unknown-
(241468, 134, 71617, 0, 10274, 1, 0, 0, 60192), -- Crystallized Firestone
(241468, 135, 3148, 1, 10280, 2, 0, 0, 60192), -- 3148
(241468, 136, 396, 1000, 10275, 2, 0, 0, 60192); -- 396
