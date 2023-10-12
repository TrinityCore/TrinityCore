-- LFR
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=17 AND `Entry` IN (93094,100733,101459,109795,114263,114323,114341,114343,114344,114360,114361,114523,114532,114534,114535,114537,114538,114539,114546,114547,114548,114553,114560,114566,114568,114614,114672,114709,114784,114785,114786,114787,114788,114789,114791,114809,114811,114812,114813,114900,114901,114905,114922,114923,114932,115166,115941,116122,116214,116268,116269,116270,116271,116760,116761,116762,116763,116818,116830,117783,117784));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(93094, 17, 0, 0, 633, 6, 0.85000002384185791, 1, 92517, 0, 0, 50791), -- Restless Ancestor
(100733, 17, 0, 0, 1155, 6, 1, 1, 101244, 1024, 0, 50791), -- Charge
(101459, 17, 0, 0, 486, 6, 7, 1, 101978, 2097224, 0, 50791), -- Spoils
(109795, 17, 0, 0, 334, 6, 1, 1, 111858, 2097224, 0, 50791), -- Neglected Bones
(114263, 17, 3, 3, 636, 6, 270, 1, 118550, 2097260, 128, 50791), -- Odyn
(114323, 17, 3, 3, 636, 6, 297, 0, 118988, 2097261, 128, 50791), -- Guarm
(114341, 17, 0, 0, 622, 6, 70, 0, 117708, 1361052712, 16, 50791), -- Guarm
(114343, 17, 0, 0, 622, 6, 70, 0, 117711, 1361052712, 16, 50791), -- Guarm
(114344, 17, 0, 0, 622, 6, 70, 0, 117712, 1361052712, 16, 50791), -- Guarm
(114360, 17, 2, 2, 636, 6, 84, 1, 118554, 2097224, 128, 50791), -- Hyrja
(114361, 17, 2, 2, 636, 6, 84, 1, 118558, 2097224, 128, 50791), -- Hymdall
(114523, 17, 0, 0, 622, 6, 1, 1, 117928, 16778240, 16, 50791), -- Orb of Corruption
(114532, 17, 2, 2, 636, 6, 10.80000019073486328, 1, 119991, 2097224, 0, 50791), -- Bonespeaker Soulbinder
(114534, 17, 2, 2, 636, 6, 9.600000381469726562, 1, 119995, 2097224, 0, 50791), -- Helhound
(114535, 17, 0, 0, 636, 6, 0.60000002384185791, 1, 122711, 16778240, 16, 50791), -- Orb of Corrosion
(114537, 17, 2, 2, 636, 6, 448.20001220703125, 1, 119432, 2097260, 128, 50791), -- Helya
(114538, 17, 2, 2, 636, 6, 8.399999618530273437, 1, 119999, 2097224, 0, 50791), -- Kvaldir Spiritrender
(114539, 17, 2, 2, 636, 6, 9.600000381469726562, 10, 120003, 2097224, 0, 50791), -- Kvaldir Reefcaller
(114546, 17, 2, 2, 636, 6, 9.600000381469726562, 1, 120007, 2097224, 0, 50791), -- Risen Bonethrall
(114547, 17, 2, 2, 636, 6, 9.600000381469726562, 1, 120011, 2097224, 0, 50791), -- Ancient Bonethrall
(114548, 17, 2, 2, 636, 6, 28.79999923706054687, 1, 120015, 2097224, 0, 50791), -- Rotsoul Giant
(114553, 17, 0, 0, 636, 6, 1.20000004768371582, 0, 119420, 2097160, 128, 50791), -- Bilewater Slime
(114560, 17, 0, 0, 622, 6, 0.009999999776482582, 1, 117982, 268435464, 128, 50791), -- Dancing Blade
(114566, 17, 0, 0, 622, 6, 1, 1, 117988, 16778240, 16, 50791), -- Orb of Corrosion
(114568, 17, 0, 0, 636, 6, 0.75, 1, 119416, 2097224, 128, 50791), -- Decaying Minion
(114614, 17, 2, 2, 636, 6, 9.600000381469726562, 1, 120019, 2097224, 0, 50791), -- Kvaldir Spiritrender
(114672, 17, 0, 0, 622, 6, 1, 1, 118141, 1610612752, 6, 50791), -- Brazier Stalker
(114709, 17, 2, 2, 636, 6, 10.19999980926513671, 1, 119408, 270532680, 128, 50791), -- Grimelord
(114784, 17, 0, 0, 622, 6, 3.5, 1, 118280, 2097224, 0, 50791), -- Valarjar Champion
(114785, 17, 0, 0, 622, 6, 4.90000009536743164, 1, 118281, 2097256, 0, 50791), -- Valarjar Marksman
(114786, 17, 0, 0, 622, 6, 5, 1, 118282, 2097256, 0, 50791), -- Valarjar Mystic
(114787, 17, 0, 0, 622, 6, 5, 1, 118283, 2097256, 0, 50791), -- Valarjar Runecarver
(114788, 17, 0, 0, 622, 6, 5, 1, 118284, 2097224, 0, 50791), -- Valarjar Thundercaller
(114789, 17, 1, 1, 622, 6, 8, 1, 118285, 2097224, 0, 50791), -- Stormforged Sentinel
(114791, 17, 0, 0, 622, 6, 10, 1, 118287, 2097224, 0, 50791), -- Chosen of Eyir
(114809, 17, 2, 2, 636, 6, 4.157999992370605468, 1, 119412, 270532680, 128, 50791), -- Night Watch Mariner
(114811, 17, 2, 2, 636, 6, 9.600000381469726562, 1, 120040, 2097224, 0, 50791), -- Kvaldir Coral Maiden
(114812, 17, 0, 0, 622, 6, 1, 1, 118315, 16778240, 16, 50791), -- Night Watch Mariner
(114813, 17, 2, 2, 636, 6, 9.600000381469726562, 1, 120044, 2097224, 0, 50791), -- Kvaldir Tide Witch
(114900, 17, 2, 2, 636, 6, 6, 1, 119428, 104, 128, 50791), -- Gripping Tentacle
(114901, 17, 0, 0, 622, 6, 1, 1, 118413, 0, 128, 50791), -- Gripping Tentacle
(114905, 17, 1, 1, 622, 6, 1, 1, 118417, 0, 128, 50791), -- Gripping Tentacle
(114922, 17, 2, 2, 636, 6, 9.600000381469726562, 1, 120048, 2097224, 0, 50791), -- Dark Seraph
(114923, 17, 2, 2, 636, 6, 1.20000004768371582, 1, 120052, 2097224, 0, 50791), -- Shatterbone Skeleton
(114932, 17, 2, 2, 636, 6, 19.20000076293945312, 1, 120056, 2097224, 0, 50791), -- Deepbrine Monstrosity
(115166, 17, 0, 0, 636, 6, 0.60000002384185791, 1, 122707, 16778240, 16, 50791), -- Orb of Corruption
(115941, 17, 2, 2, 622, 6, 1, 1, 119554, 16778240, 16, 50791), -- Kvaldir Longboat
(116122, 17, 2, 2, 622, 6, 10000, 1, 119761, 2097256, 0, 50791), -- Sky Jump
(116214, 17, 0, 0, 622, 6, 1, 1, 119857, 16778240, 16, 50791), -- Orb of Corruption
(116268, 17, 0, 0, 347, 6, 1, 1, 119939, 1610612752, 6, 50791), -- Aspiring Champion of the Chosen Dead
(116269, 17, 0, 0, 347, 6, 1, 1, 119940, 1610612752, 6, 50791), -- Heroic Champion of the Chosen Dead
(116270, 17, 0, 0, 347, 6, 1, 1, 119941, 1610612752, 6, 50791), -- Mythical Champion of the Chosen Dead
(116271, 17, 0, 0, 347, 6, 1, 1, 119942, 1610612752, 6, 50791), -- Champion of the Chosen Dead
(116760, 17, 3, 3, 636, 6, 300, 1, 120686, 2097260, 0, 50791), -- Odyn
(116761, 17, 2, 2, 636, 6, 66, 1, 120691, 2097224, 0, 50791), -- Hymdall
(116762, 17, 0, 0, 622, 6, 10, 1, 120692, 2097224, 0, 50791), -- Chosen of Eyir
(116763, 17, 1, 1, 622, 6, 8, 1, 120693, 2097224, 0, 50791), -- Stormforged Sentinel
(116818, 17, 2, 2, 622, 6, 300, 1, 120752, 64, 0, 50791), -- Eyir
(116830, 17, 2, 2, 636, 6, 66, 1, 120768, 2097224, 0, 50791), -- Hyrja
(117783, 17, 0, 0, 622, 6, 1, 1, 121757, 0, 0, 50791), -- Gripping Tentacle
(117784, 17, 0, 0, 622, 6, 1, 1, 121758, 0, 0, 50791); -- Gripping Tentacle

-- Normal
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=14 AND `Entry` IN (110973,110976,114523,114553,114560,114881,115166,116122));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(110973, 14, 0, 0, 334, 6, 4.5, 1, 113110, 2097224, 0, 50791), -- Worthy Vrykul
(110976, 14, 0, 0, 334, 6, 0.009999999776482582, 1, 113113, 268435464, 0, 50791), -- Chosen Stalker
(114523, 14, 0, 0, 622, 6, 1, 1, 117928, 16778240, 16, 50791), -- Orb of Corruption
(114553, 14, 0, 0, 622, 6, 3.20000004768371582, 0, 119417, 2097160, 128, 50791), -- Bilewater Slime
(114560, 14, 0, 0, 622, 6, 0.009999999776482582, 1, 117982, 268435464, 128, 50791), -- Dancing Blade
(114881, 14, 2, 2, 622, 6, 1, 1, 118393, 16778240, 144, 50791), -- Striking Tentacle
(115166, 14, 0, 0, 622, 6, 0.800000011920928955, 1, 122704, 16778240, 16, 50791), -- Orb of Corruption
(116122, 14, 2, 2, 622, 6, 10000, 1, 119761, 2097256, 0, 50791); -- Sky Jump

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50791 WHERE (`DifficultyID`=14 AND `Entry` IN (93094,101459,109795,114341,114343,114344,114672,114784,114785,114786,114787,114788,114789,114791,114901,114905,115941,116214,116268,116269,116270,116271,116404,116762,116763,116818,117783,117784));
UPDATE `creature_template_difficulty` SET `HealthModifier`=360, `CreatureDifficultyID`=118547, `VerifiedBuild`=50791 WHERE (`Entry`=114263 AND `DifficultyID`=14); -- Odyn
UPDATE `creature_template_difficulty` SET `HealthModifier`=360, `CreatureDifficultyID`=118985, `VerifiedBuild`=50791 WHERE (`Entry`=114323 AND `DifficultyID`=14); -- Guarm
UPDATE `creature_template_difficulty` SET `HealthModifier`=112, `CreatureDifficultyID`=118551, `VerifiedBuild`=50791 WHERE (`Entry`=114360 AND `DifficultyID`=14); -- Hyrja
UPDATE `creature_template_difficulty` SET `HealthModifier`=112, `CreatureDifficultyID`=118555, `VerifiedBuild`=50791 WHERE (`Entry`=114361 AND `DifficultyID`=14); -- Hymdall
UPDATE `creature_template_difficulty` SET `HealthModifier`=14.39999961853027343, `CreatureDifficultyID`=119988, `VerifiedBuild`=50791 WHERE (`Entry`=114532 AND `DifficultyID`=14); -- Bonespeaker Soulbinder
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=119992, `TypeFlags`=2097224, `VerifiedBuild`=50791 WHERE (`Entry`=114534 AND `DifficultyID`=14); -- Helhound
UPDATE `creature_template_difficulty` SET `HealthModifier`=597.5999755859375, `CreatureDifficultyID`=119429, `VerifiedBuild`=50791 WHERE (`Entry`=114537 AND `DifficultyID`=14); -- Helya
UPDATE `creature_template_difficulty` SET `HealthModifier`=11.19999980926513671, `CreatureDifficultyID`=119996, `VerifiedBuild`=50791 WHERE (`Entry`=114538 AND `DifficultyID`=14); -- Kvaldir Spiritrender
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=120000, `VerifiedBuild`=50791 WHERE (`Entry`=114539 AND `DifficultyID`=14); -- Kvaldir Reefcaller
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=120004, `VerifiedBuild`=50791 WHERE (`Entry`=114546 AND `DifficultyID`=14); -- Risen Bonethrall
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=120008, `VerifiedBuild`=50791 WHERE (`Entry`=114547 AND `DifficultyID`=14); -- Ancient Bonethrall
UPDATE `creature_template_difficulty` SET `HealthModifier`=38.40000152587890625, `CreatureDifficultyID`=120012, `VerifiedBuild`=50791 WHERE (`Entry`=114548 AND `DifficultyID`=14); -- Rotsoul Giant
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=120016, `VerifiedBuild`=50791 WHERE (`Entry`=114614 AND `DifficultyID`=14); -- Kvaldir Spiritrender
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.75, `CreatureDifficultyID`=119405, `VerifiedBuild`=50791 WHERE (`Entry`=114709 AND `DifficultyID`=14); -- Grimelord
UPDATE `creature_template_difficulty` SET `HealthModifier`=7.920000076293945312, `CreatureDifficultyID`=119409, `VerifiedBuild`=50791 WHERE (`Entry`=114809 AND `DifficultyID`=14); -- Night Watch Mariner
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=120037, `VerifiedBuild`=50791 WHERE (`Entry`=114811 AND `DifficultyID`=14); -- Kvaldir Coral Maiden
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=120041, `VerifiedBuild`=50791 WHERE (`Entry`=114813 AND `DifficultyID`=14); -- Kvaldir Tide Witch
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.600000381469726562, `CreatureDifficultyID`=119425, `VerifiedBuild`=50791 WHERE (`Entry`=114900 AND `DifficultyID`=14); -- Gripping Tentacle
UPDATE `creature_template_difficulty` SET `HealthModifier`=12.80000019073486328, `CreatureDifficultyID`=120045, `VerifiedBuild`=50791 WHERE (`Entry`=114922 AND `DifficultyID`=14); -- Dark Seraph
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.60000002384185791, `CreatureDifficultyID`=120049, `VerifiedBuild`=50791 WHERE (`Entry`=114923 AND `DifficultyID`=14); -- Shatterbone Skeleton
UPDATE `creature_template_difficulty` SET `HealthModifier`=25.60000038146972656, `CreatureDifficultyID`=120053, `VerifiedBuild`=50791 WHERE (`Entry`=114932 AND `DifficultyID`=14); -- Deepbrine Monstrosity
UPDATE `creature_template_difficulty` SET `HealthModifier`=400, `CreatureDifficultyID`=120683, `VerifiedBuild`=50791 WHERE (`Entry`=116760 AND `DifficultyID`=14); -- Odyn
UPDATE `creature_template_difficulty` SET `HealthModifier`=88, `CreatureDifficultyID`=120688, `VerifiedBuild`=50791 WHERE (`Entry`=116761 AND `DifficultyID`=14); -- Hymdall
UPDATE `creature_template_difficulty` SET `HealthModifier`=88, `CreatureDifficultyID`=120765, `VerifiedBuild`=50791 WHERE (`Entry`=116830 AND `DifficultyID`=14); -- Hyrja

-- Heroic
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=15 AND `Entry` IN (93094,100733,101459,109795,114263,114323,114341,114343,114344,114360,114361,114523,114532,114534,114535,114537,114538,114539,114546,114547,114548,114553,114560,114566,114568,114614,114672,114709,114784,114785,114786,114787,114788,114789,114791,114809,114811,114812,114813,114881,114900,114901,114905,114922,114923,114932,115166,115941,116122,116214,116268,116269,116270,116271,116404,116760,116761,116762,116763,116818,116830,117783,117784));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(93094, 15, 0, 0, 633, 6, 0.85000002384185791, 1, 92517, 0, 0, 50791), -- Restless Ancestor
(100733, 15, 0, 0, 1155, 6, 1, 1, 101244, 1024, 0, 50791), -- Charge
(101459, 15, 0, 0, 486, 6, 7, 1, 101978, 2097224, 0, 50791), -- Spoils
(109795, 15, 0, 0, 334, 6, 1, 1, 111858, 2097224, 0, 50791), -- Neglected Bones
(114263, 15, 3, 3, 634, 6, 450, 1, 118548, 2097260, 128, 50791), -- Odyn
(114323, 15, 3, 3, 634, 6, 495, 0, 118986, 2097261, 128, 50791), -- Guarm
(114341, 15, 0, 0, 622, 6, 70, 0, 117708, 1361052712, 16, 50791), -- Guarm
(114343, 15, 0, 0, 622, 6, 70, 0, 117711, 1361052712, 16, 50791), -- Guarm
(114344, 15, 0, 0, 622, 6, 70, 0, 117712, 1361052712, 16, 50791), -- Guarm
(114360, 15, 2, 2, 634, 6, 140, 1, 118552, 2097224, 128, 50791), -- Hyrja
(114361, 15, 2, 2, 634, 6, 140, 1, 118556, 2097224, 128, 50791), -- Hymdall
(114523, 15, 0, 0, 622, 6, 1, 1, 117928, 16778240, 16, 50791), -- Orb of Corruption
(114532, 15, 2, 2, 634, 6, 18, 1, 119989, 2097224, 0, 50791), -- Bonespeaker Soulbinder
(114534, 15, 2, 2, 634, 6, 16, 1, 119993, 2097224, 0, 50791), -- Helhound
(114535, 15, 0, 0, 634, 6, 1, 1, 122709, 16778240, 16, 50791), -- Orb of Corrosion
(114537, 15, 2, 2, 634, 6, 747, 1, 119430, 2097260, 128, 50791), -- Helya
(114538, 15, 2, 2, 634, 6, 14, 1, 119997, 2097224, 0, 50791), -- Kvaldir Spiritrender
(114539, 15, 2, 2, 634, 6, 16, 10, 120001, 2097224, 0, 50791), -- Kvaldir Reefcaller
(114546, 15, 2, 2, 634, 6, 16, 1, 120005, 2097224, 0, 50791), -- Risen Bonethrall
(114547, 15, 2, 2, 634, 6, 16, 1, 120009, 2097224, 0, 50791), -- Ancient Bonethrall
(114548, 15, 2, 2, 634, 6, 48, 1, 120013, 2097224, 0, 50791), -- Rotsoul Giant
(114553, 15, 0, 0, 634, 6, 4, 0, 119418, 2097160, 128, 50791), -- Bilewater Slime
(114560, 15, 0, 0, 622, 6, 0.009999999776482582, 1, 117982, 268435464, 128, 50791), -- Dancing Blade
(114566, 15, 0, 0, 622, 6, 1, 1, 117988, 16778240, 16, 50791), -- Orb of Corrosion
(114568, 15, 0, 0, 634, 6, 4, 1, 119414, 2097224, 128, 50791), -- Decaying Minion
(114614, 15, 2, 2, 634, 6, 16, 1, 120017, 2097224, 0, 50791), -- Kvaldir Spiritrender
(114672, 15, 0, 0, 622, 6, 1, 1, 118141, 1610612752, 6, 50791), -- Brazier Stalker
(114709, 15, 2, 2, 634, 6, 17.85000038146972656, 1, 119406, 270532680, 128, 50791), -- Grimelord
(114784, 15, 0, 0, 622, 6, 3.5, 1, 118280, 2097224, 0, 50791), -- Valarjar Champion
(114785, 15, 0, 0, 622, 6, 4.90000009536743164, 1, 118281, 2097256, 0, 50791), -- Valarjar Marksman
(114786, 15, 0, 0, 622, 6, 5, 1, 118282, 2097256, 0, 50791), -- Valarjar Mystic
(114787, 15, 0, 0, 622, 6, 5, 1, 118283, 2097256, 0, 50791), -- Valarjar Runecarver
(114788, 15, 0, 0, 622, 6, 5, 1, 118284, 2097224, 0, 50791), -- Valarjar Thundercaller
(114789, 15, 1, 1, 622, 6, 8, 1, 118285, 2097224, 0, 50791), -- Stormforged Sentinel
(114791, 15, 0, 0, 622, 6, 10, 1, 118287, 2097224, 0, 50791), -- Chosen of Eyir
(114809, 15, 2, 2, 634, 6, 13.5, 1, 119410, 270532680, 128, 50791), -- Night Watch Mariner
(114811, 15, 2, 2, 634, 6, 16, 1, 120038, 2097224, 0, 50791), -- Kvaldir Coral Maiden
(114812, 15, 0, 0, 622, 6, 1, 1, 118315, 16778240, 16, 50791), -- Night Watch Mariner
(114813, 15, 2, 2, 634, 6, 16, 1, 120042, 2097224, 0, 50791), -- Kvaldir Tide Witch
(114881, 15, 2, 2, 622, 6, 1, 1, 118393, 16778240, 144, 50791), -- Striking Tentacle
(114900, 15, 2, 2, 634, 6, 12, 1, 119426, 104, 128, 50791), -- Gripping Tentacle
(114901, 15, 0, 0, 622, 6, 1, 1, 118413, 0, 128, 50791), -- Gripping Tentacle
(114905, 15, 1, 1, 622, 6, 1, 1, 118417, 0, 128, 50791), -- Gripping Tentacle
(114922, 15, 2, 2, 634, 6, 16, 1, 120046, 2097224, 0, 50791), -- Dark Seraph
(114923, 15, 2, 2, 634, 6, 2, 1, 120050, 2097224, 0, 50791), -- Shatterbone Skeleton
(114932, 15, 2, 2, 634, 6, 32, 1, 120054, 2097224, 0, 50791), -- Deepbrine Monstrosity
(115166, 15, 0, 0, 634, 6, 1, 1, 122705, 16778240, 16, 50791), -- Orb of Corruption
(115941, 15, 2, 2, 622, 6, 1, 1, 119554, 16778240, 16, 50791), -- Kvaldir Longboat
(116122, 15, 2, 2, 622, 6, 10000, 1, 119761, 2097256, 0, 50791), -- Sky Jump
(116214, 15, 0, 0, 622, 6, 1, 1, 119857, 16778240, 16, 50791), -- Orb of Corruption
(116268, 15, 0, 0, 347, 6, 1, 1, 119939, 1610612752, 6, 50791), -- Aspiring Champion of the Chosen Dead
(116269, 15, 0, 0, 347, 6, 1, 1, 119940, 1610612752, 6, 50791), -- Heroic Champion of the Chosen Dead
(116270, 15, 0, 0, 347, 6, 1, 1, 119941, 1610612752, 6, 50791), -- Mythical Champion of the Chosen Dead
(116271, 15, 0, 0, 347, 6, 1, 1, 119942, 1610612752, 6, 50791), -- Champion of the Chosen Dead
(116404, 15, 3, 3, 622, 6, 1, 1, 120159, 1610612752, 6, 50791), -- Guarm's Chew Toy
(116760, 15, 3, 3, 634, 6, 500, 1, 120684, 2097260, 0, 50791), -- Odyn
(116761, 15, 2, 2, 634, 6, 110, 1, 120689, 2097224, 0, 50791), -- Hymdall
(116762, 15, 0, 0, 622, 6, 10, 1, 120692, 2097224, 0, 50791), -- Chosen of Eyir
(116763, 15, 1, 1, 622, 6, 8, 1, 120693, 2097224, 0, 50791), -- Stormforged Sentinel
(116818, 15, 2, 2, 622, 6, 300, 1, 120752, 64, 0, 50791), -- Eyir
(116830, 15, 2, 2, 634, 6, 110, 1, 120766, 2097224, 0, 50791), -- Hyrja
(117783, 15, 0, 0, 622, 6, 1, 1, 121757, 0, 0, 50791), -- Gripping Tentacle
(117784, 15, 0, 0, 622, 6, 1, 1, 121758, 0, 0, 50791); -- Gripping Tentacle

-- Mythic
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=16 AND `Entry` IN (93094,101459,109795,114323,114341,114343,114344,114467,114532,114534,114537,114538,114539,114546,114547,114548,114560,114614,114672,114811,114813,114922,114923,114932,116122,116268,116269,116270,116271,116404,117783,117784));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(93094, 16, 0, 0, 633, 6, 0.85000002384185791, 1, 92517, 0, 0, 50504), -- Restless Ancestor
(101459, 16, 0, 0, 486, 6, 7, 1, 101978, 2097224, 0, 50504), -- Spoils
(109795, 16, 0, 0, 334, 6, 1, 1, 111858, 2097224, 0, 50504), -- Neglected Bones
(114323, 16, 3, 3, 635, 6, 1248.300048828125, 0, 118987, 2097261, 128, 50504), -- Guarm
(114341, 16, 0, 0, 622, 6, 70, 0, 117708, 1361052712, 16, 50504), -- Guarm
(114343, 16, 0, 0, 622, 6, 70, 0, 117711, 1361052712, 16, 50504), -- Guarm
(114344, 16, 0, 0, 622, 6, 70, 0, 117712, 1361052712, 16, 50504), -- Guarm
(114467, 16, 0, 0, 635, 6, 7.994999885559082031, 1, 121101, 2097224, 0, 50504), -- Spear of Light
(114532, 16, 2, 2, 635, 6, 47.970001220703125, 1, 119990, 2097224, 0, 50504), -- Bonespeaker Soulbinder
(114534, 16, 2, 2, 635, 6, 42.6399993896484375, 1, 119994, 2097224, 0, 50504), -- Helhound
(114537, 16, 2, 2, 635, 6, 2483.4599609375, 1, 119431, 2097260, 128, 50504), -- Helya
(114538, 16, 2, 2, 635, 6, 37.31000137329101562, 1, 119998, 2097224, 0, 50504), -- Kvaldir Spiritrender
(114539, 16, 2, 2, 635, 6, 42.6399993896484375, 10, 120002, 2097224, 0, 50504), -- Kvaldir Reefcaller
(114546, 16, 2, 2, 635, 6, 42.6399993896484375, 1, 120006, 2097224, 0, 50504), -- Risen Bonethrall
(114547, 16, 2, 2, 635, 6, 42.6399993896484375, 1, 120010, 2097224, 0, 50504), -- Ancient Bonethrall
(114548, 16, 2, 2, 635, 6, 127.9199981689453125, 1, 120014, 2097224, 0, 50504), -- Rotsoul Giant
(114560, 16, 0, 0, 622, 6, 0.009999999776482582, 1, 117982, 268435464, 128, 50504), -- Dancing Blade
(114614, 16, 2, 2, 635, 6, 42.6399993896484375, 1, 120018, 2097224, 0, 50504), -- Kvaldir Spiritrender
(114672, 16, 0, 0, 622, 6, 1, 1, 118141, 1610612752, 6, 50504), -- Brazier Stalker
(114811, 16, 2, 2, 635, 6, 42.6399993896484375, 1, 120039, 2097224, 0, 50504), -- Kvaldir Coral Maiden
(114813, 16, 2, 2, 635, 6, 42.6399993896484375, 1, 120043, 2097224, 0, 50504), -- Kvaldir Tide Witch
(114922, 16, 2, 2, 635, 6, 42.6399993896484375, 1, 120047, 2097224, 0, 50504), -- Dark Seraph
(114923, 16, 2, 2, 635, 6, 5.329999923706054687, 1, 120051, 2097224, 0, 50504), -- Shatterbone Skeleton
(114932, 16, 2, 2, 635, 6, 85.279998779296875, 1, 120055, 2097224, 0, 50504), -- Deepbrine Monstrosity
(116122, 16, 2, 2, 622, 6, 10000, 1, 119761, 2097256, 0, 50504), -- Sky Jump
(116268, 16, 0, 0, 347, 6, 1, 1, 119939, 1610612752, 6, 50504), -- Aspiring Champion of the Chosen Dead
(116269, 16, 0, 0, 347, 6, 1, 1, 119940, 1610612752, 6, 50504), -- Heroic Champion of the Chosen Dead
(116270, 16, 0, 0, 347, 6, 1, 1, 119941, 1610612752, 6, 50504), -- Mythical Champion of the Chosen Dead
(116271, 16, 0, 0, 347, 6, 1, 1, 119942, 1610612752, 6, 50504), -- Champion of the Chosen Dead
(116404, 16, 3, 3, 622, 6, 1, 1, 120159, 1610612752, 6, 50504), -- Guarm's Chew Toy
(117783, 16, 0, 0, 622, 6, 1, 1, 121757, 0, 0, 50504), -- Gripping Tentacle
(117784, 16, 0, 0, 622, 6, 1, 1, 121758, 0, 0, 50504); -- Gripping Tentacle

UPDATE `creature_template_difficulty` SET `HealthModifier`=1327.5, `CreatureDifficultyID`=118549, `VerifiedBuild`=50504 WHERE (`Entry`=114263 AND `DifficultyID`=16); -- Odyn
UPDATE `creature_template_difficulty` SET `HealthModifier`=388, `CreatureDifficultyID`=118553, `VerifiedBuild`=50504 WHERE (`Entry`=114360 AND `DifficultyID`=16); -- Hyrja
UPDATE `creature_template_difficulty` SET `HealthModifier`=388, `CreatureDifficultyID`=118557, `VerifiedBuild`=50504 WHERE (`Entry`=114361 AND `DifficultyID`=16); -- Hymdall
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50504 WHERE (`DifficultyID`=16 AND `Entry` IN (114784,114785,114786,114787,114788,114789,114791));
UPDATE `creature_template_difficulty` SET `HealthModifier`=9.200011253356933593, `CreatureDifficultyID`=118565, `VerifiedBuild`=50504 WHERE (`Entry`=114996 AND `DifficultyID`=16); -- Valarjar Runebearer

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=16 AND `Entry` IN (100733,114523,114535,114553,114566,114568,114709,114809,114812,114881,114900,114901,114905,115166,115941,116214,116335,116760,116761,116762,116763,116818,116830));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(100733, 16, 0, 0, 1155, 6, 1, 1, 101244, 1024, 0, 50791), -- Charge
(114523, 16, 0, 0, 622, 6, 1, 1, 117928, 16778240, 16, 50791), -- Orb of Corruption
(114535, 16, 0, 0, 635, 6, 2.664999961853027343, 1, 122710, 16778240, 16, 50791), -- Orb of Corrosion
(114553, 16, 0, 0, 635, 6, 12.15979957580566406, 0, 119419, 2097160, 128, 50791), -- Bilewater Slime
(114566, 16, 0, 0, 622, 6, 1, 1, 117988, 16778240, 16, 50791), -- Orb of Corrosion
(114568, 16, 0, 0, 635, 6, 5, 1, 119415, 2097224, 128, 50791), -- Decaying Minion
(114709, 16, 2, 2, 635, 6, 48, 1, 119407, 270532680, 128, 50791), -- Grimelord
(114809, 16, 2, 2, 635, 6, 35.8748016357421875, 1, 119411, 270532680, 128, 50791), -- Night Watch Mariner
(114812, 16, 0, 0, 622, 6, 1, 1, 118315, 16778240, 16, 50791), -- Night Watch Mariner
(114881, 16, 2, 2, 622, 6, 1, 1, 118393, 16778240, 144, 50791), -- Striking Tentacle
(114900, 16, 2, 2, 635, 6, 58.13050079345703125, 1, 119427, 104, 128, 50791), -- Gripping Tentacle
(114901, 16, 0, 0, 622, 6, 1, 1, 118413, 0, 128, 50791), -- Gripping Tentacle
(114905, 16, 1, 1, 622, 6, 1, 1, 118417, 0, 128, 50791), -- Gripping Tentacle
(115166, 16, 0, 0, 635, 6, 2.664999961853027343, 1, 122706, 16778240, 16, 50791), -- Orb of Corruption
(115941, 16, 2, 2, 622, 6, 1, 1, 119554, 16778240, 16, 50791), -- Kvaldir Longboat
(116214, 16, 0, 0, 622, 6, 1, 1, 119857, 16778240, 16, 50791), -- Orb of Corruption
(116335, 16, 1, 1, 622, 6, 25.77249908447265625, 1, 120078, 2097224, 128, 50791), -- Helarjar Mistwatcher
(116760, 16, 3, 3, 635, 6, 675, 1, 120685, 2097260, 0, 50791), -- Odyn
(116761, 16, 2, 2, 635, 6, 287.5, 1, 120690, 2097224, 0, 50791), -- Hymdall
(116762, 16, 0, 0, 622, 6, 10, 1, 120692, 2097224, 0, 50791), -- Chosen of Eyir
(116763, 16, 1, 1, 622, 6, 8, 1, 120693, 2097224, 0, 50791), -- Stormforged Sentinel
(116818, 16, 2, 2, 622, 6, 300, 1, 120752, 64, 0, 50791), -- Eyir
(116830, 16, 2, 2, 635, 6, 287.5, 1, 120767, 2097224, 0, 50791); -- Hyrja

UPDATE `creature_template_difficulty` SET `VerifiedBuild`=50791 WHERE (`DifficultyID`=16 AND `Entry` IN (93094,101459,109795,114263,114323,114341,114343,114344,114360,114361,114467,114532,114534,114537,114538,114539,114546,114547,114548,114560,114614,114672,114784,114785,114786,114787,114788,114789,114791,114811,114813,114922,114923,114932,114996,116122,116268,116269,116270,116271,116404,117783,117784));
