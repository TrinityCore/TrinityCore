SET @CGUID := 3990090;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 241467, 1, 1637, 5356, '0', 169, 0, 0, 0, 1672.4288330078125, -4327.1337890625, 63.6678466796875, 3.794057607650756835, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 60142), -- Sylstrasza (Area: Grommash Hold - Difficulty: 0) CreateObject1
(@CGUID+1, 241468, 0, 1519, 5149, '0', 169, 0, 0, 0, -8825.6357421875, 342.704864501953125, 107.1320724487304687, 0.854419827461242675, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 60142); -- Zarstrasza (Area: Old Town - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Sylstrasza
(@CGUID+1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Zarstrasza

UPDATE `creature_template_difficulty` SET `MinLevel`=80, `MaxLevel`=80, `StaticFlags1`=0x10000000, `VerifiedBuild`=60142 WHERE (`Entry`=241468 AND `DifficultyID`=0); -- 241468 (Zarstrasza) - CanSwim
UPDATE `creature_template_difficulty` SET `MinLevel`=80, `MaxLevel`=80, `StaticFlags1`=0x10000000, `VerifiedBuild`=60142 WHERE (`Entry`=241467 AND `DifficultyID`=0); -- 241467 (Sylstrasza) - CanSwim

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (127918, 127433, 127435);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(127918, 0.388999998569488525, 1.5, 0, 60142),
(127433, 0.305999994277954101, 1.5, 0, 60142),
(127435, 0.872500002384185791, 3.75, 0, 60142);

UPDATE `creature_template` SET `faction`= 2010, `npcflag`= 0x80, `unit_flags2`= 0x800, `BaseAttackTime`= 2000, `RangeAttackTime`= 2000 WHERE `entry` IN (241468, 241467);

DELETE FROM `npc_vendor`WHERE `entry` IN (241468, 241467);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(241468, 136, 396, 1000, 10275, 2, 0, 0, 60192), -- 396
(241468, 135, 3148, 1, 10280, 2, 0, 0, 60192), -- 3148
(241468, 134, 71617, 0, 10274, 1, 0, 0, 60192), -- Crystallized Firestone
(241468, 133, 239110, 0, 10273, 1, 0, 0, 60192), -- -Unknown-
(241468, 132, 69167, 0, 10260, 1, 0, 0, 60192), -- Vessel of Acceleration
(241468, 131, 69150, 0, 10260, 1, 0, 0, 60192), -- Matrix Restabilizer
(241468, 130, 69110, 0, 10260, 1, 0, 0, 60192), -- Variable Pulse Lightning Capacitor
(241468, 129, 69149, 0, 10259, 1, 0, 0, 60192), -- Eye of Blazing Power
(241468, 128, 69138, 0, 10259, 1, 0, 0, 60192), -- Spidersilk Spindle
(241468, 127, 69113, 0, 10259, 1, 0, 0, 60192), -- Apparatus of Khaz'goroth
(241468, 126, 69139, 0, 10259, 1, 0, 0, 60192), -- Necromantic Focus
(241468, 125, 69112, 0, 10259, 1, 0, 0, 60192), -- The Hungerer
(241468, 124, 69111, 0, 10259, 1, 0, 0, 60192), -- Jaws of Defeat
(241468, 123, 69109, 0, 10259, 1, 0, 0, 60192), -- Scales of Life
(241468, 122, 71353, 0, 10257, 1, 0, 0, 60192), -- Arathar, the Eye of Flame
(241468, 121, 71798, 0, 10257, 1, 0, 0, 60192), -- Sho'ravon, Greatstaff of Annihilation
(241468, 120, 71352, 0, 10257, 1, 0, 0, 60192), -- Sulfuras, the Extinguished Hand
(241468, 119, 71355, 0, 10256, 1, 0, 0, 60192), -- Ko'gun, Hammer of the Firelord
(241468, 118, 71347, 0, 10255, 1, 0, 0, 60192), -- Stinger of the Flaming Scorpion
(241468, 117, 70991, 0, 10255, 1, 0, 0, 60192), -- Arbalest of Erupting Fury
(241468, 116, 71323, 0, 10253, 1, 0, 0, 60192), -- Molten Scream
(241468, 115, 71039, 0, 10255, 1, 0, 0, 60192), -- Funeral Pyre
(241468, 114, 71775, 0, 10255, 1, 0, 0, 60192), -- Smoldering Censer of Purity
(241468, 113, 71014, 0, 10255, 1, 0, 0, 60192), -- Skullstealer Greataxe
(241468, 112, 71780, 0, 10255, 1, 0, 0, 60192), -- Zoid's Firelit Greatsword
(241468, 111, 69897, 0, 10255, 1, 0, 0, 60192), -- Fandral's Flamescythe
(241468, 110, 70915, 0, 10252, 1, 0, 0, 60192), -- Shard of Torment
(241468, 109, 70733, 0, 10252, 1, 0, 0, 60192), -- Alysra's Razor
(241468, 108, 70922, 0, 10252, 1, 0, 0, 60192), -- Mandible of Beth'tilac
(241468, 107, 71787, 0, 10252, 1, 0, 0, 60192), -- Entrail Disgorger
(241468, 106, 71779, 0, 10252, 1, 0, 0, 60192), -- Avool's Incendiary Shanker
(241468, 105, 71782, 0, 10252, 1, 0, 0, 60192), -- Shatterskull Bonecrusher
(241468, 104, 71776, 0, 10258, 1, 0, 0, 60192), -- Eye of Purification
(241468, 103, 71785, 0, 10258, 1, 0, 0, 60192), -- Firethorn Mindslicer
(241468, 102, 71013, 0, 10252, 1, 0, 0, 60192), -- Feeding Frenzy
(241468, 101, 71312, 0, 10252, 1, 0, 0, 60192), -- Gatecrasher
(241468, 98, 78487, 0, 10271, 1, 0, 0, 60192), -- Gurthalak, Voice of the Deeps
(241468, 92, 78488, 0, 10268, 1, 0, 0, 60192), -- Souldrinker
(241468, 89, 77977, 0, 10267, 1, 0, 0, 60192), -- Eye of Unmaking
(241468, 87, 77978, 0, 10267, 1, 0, 0, 60192), -- Resolve of Undying
(241468, 86, 78466, 0, 10272, 1, 0, 0, 60192), -- Gloves of Liquid Smoke
(241468, 85, 78469, 0, 10272, 1, 0, 0, 60192), -- Gauntlets of the Golden Thorn
(241468, 84, 78467, 0, 10267, 1, 0, 0, 60192), -- Molten Blood Footpads
(241468, 83, 78468, 0, 10267, 1, 0, 0, 60192), -- Belt of Shattered Elementium
(241468, 82, 78470, 0, 10272, 1, 0, 0, 60192), -- Backbreaker Spaulders
(241468, 73, 77970, 0, 10265, 1, 0, 0, 60192), -- Soulshifter Vortex
(241468, 70, 77983, 0, 10265, 1, 0, 0, 60192), -- Indomitable Pride
(241468, 66, 77972, 0, 10265, 1, 0, 0, 60192), -- Creche of the Final Dragon
(241468, 65, 77982, 0, 10265, 1, 0, 0, 60192), -- Bone-Link Fetish
(241468, 62, 78498, 0, 10264, 1, 0, 0, 60192), -- Hardheart Ring
(241468, 59, 78497, 0, 10264, 1, 0, 0, 60192), -- Breathstealer Band
(241468, 57, 78440, 0, 10264, 1, 0, 0, 60192), -- Curled Twilight Claw
(241468, 56, 78376, 0, 10264, 1, 0, 0, 60192), -- Sporebeard Gauntlets
(241468, 55, 78412, 0, 10264, 1, 0, 0, 60192), -- Heartblood Wristplates
(241468, 54, 78384, 0, 10264, 1, 0, 0, 60192), -- Mycosynth Wristguards
(241468, 53, 78454, 0, 10264, 1, 0, 0, 60192), -- Shadow Wing Armbands
(241468, 52, 78438, 0, 10264, 1, 0, 0, 60192), -- Bracers of Looming Darkness
(241468, 51, 78400, 0, 10264, 1, 0, 0, 60192), -- Grotesquely Writhing Bracers
(241468, 50, 78425, 0, 10264, 1, 0, 0, 60192), -- Bracers of the Banished
(241468, 49, 78377, 0, 10264, 1, 0, 0, 60192), -- Rockhide Bracers
(241468, 48, 78397, 0, 10264, 1, 0, 0, 60192), -- Graveheart Bracers
(241468, 47, 78396, 0, 10265, 1, 0, 0, 60192), -- Treads of Crushed Flesh
(241468, 46, 78386, 0, 10265, 1, 0, 0, 60192), -- Pillarfoot Greaves
(241468, 45, 78457, 0, 10265, 1, 0, 0, 60192), -- Janglespur Jackboots
(241468, 44, 78408, 0, 10265, 1, 0, 0, 60192), -- Interrogator's Bloody Footpads
(241468, 43, 78442, 0, 10265, 1, 0, 0, 60192), -- Treads of Sordid Screams
(241468, 42, 78411, 0, 10265, 1, 0, 0, 60192), -- Mindstrainer Treads
(241468, 41, 78439, 0, 10265, 1, 0, 0, 60192), -- Stillheart Warboots
(241468, 40, 78423, 0, 10265, 1, 0, 0, 60192), -- Treads of Dormant Dreams
(241468, 39, 78428, 0, 10265, 1, 0, 0, 60192), -- Girdle of the Grotesque
(241468, 38, 78424, 0, 10265, 1, 0, 0, 60192), -- Runescriven Demon Collar
(241468, 37, 78460, 0, 10265, 1, 0, 0, 60192), -- Goriona's Collar
(241468, 36, 78455, 0, 10265, 1, 0, 0, 60192), -- Belt of the Beloved Companion
(241468, 35, 78385, 0, 10265, 1, 0, 0, 60192), -- Girdle of Shattered Stone
(241468, 34, 78398, 0, 10265, 1, 0, 0, 60192), -- Cord of the Slain Champion
(241468, 33, 78444, 0, 10265, 1, 0, 0, 60192), -- Dragonfracture Belt
(241468, 32, 78395, 0, 10265, 1, 0, 0, 60192), -- Belt of Flayed Skin
(241468, 31, 78375, 0, 10264, 1, 0, 0, 60192), -- Underdweller's Spaulders
(241468, 30, 78378, 0, 10264, 1, 0, 0, 60192), -- Brackenshell Shoulderplates
(241468, 29, 78443, 0, 10264, 1, 0, 0, 60192), -- Imperfect Specimens 27 and 28
(241468, 28, 78381, 0, 10264, 1, 0, 0, 60192), -- Mosswrought Shoulderguards
(241468, 26, 239114, 0, 10278, 1, 0, 0, 60192), -- -Unknown-
(241468, 25, 239113, 0, 10277, 1, 0, 0, 60192), -- -Unknown-
(241468, 24, 239220, 0, 10278, 1, 0, 0, 60192), -- -Unknown-
(241468, 23, 239112, 0, 10278, 1, 0, 0, 60192), -- -Unknown-
(241468, 22, 239111, 0, 10276, 1, 0, 0, 60192), -- -Unknown-
(241468, 19, 78874, 0, 10251, 1, 0, 0, 60192), -- Shoulders of the Corrupted Vanquisher
(241468, 16, 78871, 0, 10250, 1, 0, 0, 60192), -- Leggings of the Corrupted Vanquisher
(241468, 13, 78868, 0, 10250, 1, 0, 0, 60192), -- Crown of the Corrupted Vanquisher
(241468, 10, 78865, 0, 10251, 1, 0, 0, 60192), -- Gauntlets of the Corrupted Vanquisher
(241468, 7, 78862, 0, 10250, 1, 0, 0, 60192), -- Chest of the Corrupted Vanquisher
(241468, 4, 71674, 0, 10249, 1, 0, 0, 60192), -- Mantle of the Fiery Vanquisher
(241468, 1, 71668, 0, 10249, 1, 0, 0, 60192), -- Helm of the Fiery Vanquisher
-- 
(241467, 136, 396, 1000, 10275, 2, 0, 0, 60142), -- 396
(241467, 135, 3148, 1, 10280, 2, 0, 0, 60142), -- 3148
(241467, 134, 71617, 0, 10274, 1, 0, 0, 60142), -- Crystallized Firestone
(241467, 133, 239110, 0, 10273, 1, 0, 0, 60142), -- -Unknown-
(241467, 132, 69167, 0, 10260, 1, 0, 0, 60142), -- Vessel of Acceleration
(241467, 131, 69150, 0, 10260, 1, 0, 0, 60142), -- Matrix Restabilizer
(241467, 130, 69110, 0, 10260, 1, 0, 0, 60142), -- Variable Pulse Lightning Capacitor
(241467, 129, 69149, 0, 10259, 1, 0, 0, 60142), -- Eye of Blazing Power
(241467, 128, 69138, 0, 10259, 1, 0, 0, 60142), -- Spidersilk Spindle
(241467, 127, 69113, 0, 10259, 1, 0, 0, 60142), -- Apparatus of Khaz'goroth
(241467, 126, 69139, 0, 10259, 1, 0, 0, 60142), -- Necromantic Focus
(241467, 125, 69112, 0, 10259, 1, 0, 0, 60142), -- The Hungerer
(241467, 124, 69111, 0, 10259, 1, 0, 0, 60142), -- Jaws of Defeat
(241467, 123, 69109, 0, 10259, 1, 0, 0, 60142), -- Scales of Life
(241467, 122, 71353, 0, 10257, 1, 0, 0, 60142), -- Arathar, the Eye of Flame
(241467, 121, 71798, 0, 10257, 1, 0, 0, 60142), -- Sho'ravon, Greatstaff of Annihilation
(241467, 120, 71352, 0, 10257, 1, 0, 0, 60142), -- Sulfuras, the Extinguished Hand
(241467, 119, 71355, 0, 10256, 1, 0, 0, 60142), -- Ko'gun, Hammer of the Firelord
(241467, 118, 71347, 0, 10255, 1, 0, 0, 60142), -- Stinger of the Flaming Scorpion
(241467, 117, 70991, 0, 10255, 1, 0, 0, 60142), -- Arbalest of Erupting Fury
(241467, 116, 71323, 0, 10253, 1, 0, 0, 60142), -- Molten Scream
(241467, 115, 71039, 0, 10255, 1, 0, 0, 60142), -- Funeral Pyre
(241467, 114, 71775, 0, 10255, 1, 0, 0, 60142), -- Smoldering Censer of Purity
(241467, 113, 71014, 0, 10255, 1, 0, 0, 60142), -- Skullstealer Greataxe
(241467, 112, 71780, 0, 10255, 1, 0, 0, 60142), -- Zoid's Firelit Greatsword
(241467, 111, 69897, 0, 10255, 1, 0, 0, 60142), -- Fandral's Flamescythe
(241467, 110, 70915, 0, 10252, 1, 0, 0, 60142), -- Shard of Torment
(241467, 109, 70733, 0, 10252, 1, 0, 0, 60142), -- Alysra's Razor
(241467, 108, 70922, 0, 10252, 1, 0, 0, 60142), -- Mandible of Beth'tilac
(241467, 107, 71787, 0, 10252, 1, 0, 0, 60142), -- Entrail Disgorger
(241467, 106, 71779, 0, 10252, 1, 0, 0, 60142), -- Avool's Incendiary Shanker
(241467, 105, 71782, 0, 10252, 1, 0, 0, 60142), -- Shatterskull Bonecrusher
(241467, 104, 71776, 0, 10258, 1, 0, 0, 60142), -- Eye of Purification
(241467, 103, 71785, 0, 10258, 1, 0, 0, 60142), -- Firethorn Mindslicer
(241467, 102, 71013, 0, 10252, 1, 0, 0, 60142), -- Feeding Frenzy
(241467, 101, 71312, 0, 10252, 1, 0, 0, 60142), -- Gatecrasher
(241467, 99, 78485, 0, 10270, 1, 0, 0, 60142), -- Maw of the Dragonlord
(241467, 98, 78487, 0, 10271, 1, 0, 0, 60142), -- Gurthalak, Voice of the Deeps
(241467, 92, 78488, 0, 10268, 1, 0, 0, 60142), -- Souldrinker
(241467, 90, 77976, 0, 10267, 1, 0, 0, 60142), -- Heart of Unliving
(241467, 89, 77977, 0, 10267, 1, 0, 0, 60142), -- Eye of Unmaking
(241467, 87, 77978, 0, 10267, 1, 0, 0, 60142), -- Resolve of Undying
(241467, 86, 78466, 0, 10272, 1, 0, 0, 60142), -- Gloves of Liquid Smoke
(241467, 85, 78469, 0, 10272, 1, 0, 0, 60142), -- Gauntlets of the Golden Thorn
(241467, 84, 78467, 0, 10267, 1, 0, 0, 60142), -- Molten Blood Footpads
(241467, 83, 78468, 0, 10267, 1, 0, 0, 60142), -- Belt of Shattered Elementium
(241467, 82, 78470, 0, 10272, 1, 0, 0, 60142), -- Backbreaker Spaulders
(241467, 77, 78456, 0, 10265, 1, 0, 0, 60142), -- Blackhorn's Mighty Bulwark
(241467, 76, 78458, 0, 10265, 1, 0, 0, 60142), -- Timepiece of the Bronze Flight
(241467, 73, 77970, 0, 10265, 1, 0, 0, 60142), -- Soulshifter Vortex
(241467, 71, 77981, 0, 10265, 1, 0, 0, 60142), -- Windward Heart
(241467, 70, 77983, 0, 10265, 1, 0, 0, 60142), -- Indomitable Pride
(241467, 69, 77969, 0, 10265, 1, 0, 0, 60142), -- Seal of the Seven Signs
(241467, 66, 77972, 0, 10265, 1, 0, 0, 60142), -- Creche of the Final Dragon
(241467, 65, 77982, 0, 10265, 1, 0, 0, 60142), -- Bone-Link Fetish
(241467, 63, 78427, 0, 10264, 1, 0, 0, 60142), -- Ring of the Riven
(241467, 62, 78498, 0, 10264, 1, 0, 0, 60142), -- Hardheart Ring
(241467, 61, 78496, 0, 10264, 1, 0, 0, 60142), -- Signet of Suturing
(241467, 59, 78497, 0, 10264, 1, 0, 0, 60142), -- Breathstealer Band
(241467, 57, 78440, 0, 10264, 1, 0, 0, 60142), -- Curled Twilight Claw
(241467, 56, 78376, 0, 10264, 1, 0, 0, 60142), -- Sporebeard Gauntlets
(241467, 55, 78412, 0, 10264, 1, 0, 0, 60142), -- Heartblood Wristplates
(241467, 54, 78384, 0, 10264, 1, 0, 0, 60142), -- Mycosynth Wristguards
(241467, 53, 78454, 0, 10264, 1, 0, 0, 60142), -- Shadow Wing Armbands
(241467, 52, 78438, 0, 10264, 1, 0, 0, 60142), -- Bracers of Looming Darkness
(241467, 51, 78400, 0, 10264, 1, 0, 0, 60142), -- Grotesquely Writhing Bracers
(241467, 50, 78425, 0, 10264, 1, 0, 0, 60142), -- Bracers of the Banished
(241467, 49, 78377, 0, 10264, 1, 0, 0, 60142), -- Rockhide Bracers
(241467, 48, 78397, 0, 10264, 1, 0, 0, 60142), -- Graveheart Bracers
(241467, 47, 78396, 0, 10265, 1, 0, 0, 60142), -- Treads of Crushed Flesh
(241467, 46, 78386, 0, 10265, 1, 0, 0, 60142), -- Pillarfoot Greaves
(241467, 45, 78457, 0, 10265, 1, 0, 0, 60142), -- Janglespur Jackboots
(241467, 44, 78408, 0, 10265, 1, 0, 0, 60142), -- Interrogator's Bloody Footpads
(241467, 43, 78442, 0, 10265, 1, 0, 0, 60142), -- Treads of Sordid Screams
(241467, 42, 78411, 0, 10265, 1, 0, 0, 60142), -- Mindstrainer Treads
(241467, 41, 78439, 0, 10265, 1, 0, 0, 60142), -- Stillheart Warboots
(241467, 40, 78423, 0, 10265, 1, 0, 0, 60142), -- Treads of Dormant Dreams
(241467, 39, 78428, 0, 10265, 1, 0, 0, 60142), -- Girdle of the Grotesque
(241467, 38, 78424, 0, 10265, 1, 0, 0, 60142), -- Runescriven Demon Collar
(241467, 37, 78460, 0, 10265, 1, 0, 0, 60142), -- Goriona's Collar
(241467, 36, 78455, 0, 10265, 1, 0, 0, 60142), -- Belt of the Beloved Companion
(241467, 35, 78385, 0, 10265, 1, 0, 0, 60142), -- Girdle of Shattered Stone
(241467, 34, 78398, 0, 10265, 1, 0, 0, 60142), -- Cord of the Slain Champion
(241467, 33, 78444, 0, 10265, 1, 0, 0, 60142), -- Dragonfracture Belt
(241467, 32, 78395, 0, 10265, 1, 0, 0, 60142), -- Belt of Flayed Skin
(241467, 31, 78375, 0, 10264, 1, 0, 0, 60142), -- Underdweller's Spaulders
(241467, 30, 78378, 0, 10264, 1, 0, 0, 60142), -- Brackenshell Shoulderplates
(241467, 29, 78443, 0, 10264, 1, 0, 0, 60142), -- Imperfect Specimens 27 and 28
(241467, 28, 78381, 0, 10264, 1, 0, 0, 60142), -- Mosswrought Shoulderguards
(241467, 27, 78382, 0, 10264, 1, 0, 0, 60142), -- Petrified Fungal Heart
(241467, 26, 239114, 0, 10278, 1, 0, 0, 60142), -- -Unknown-
(241467, 25, 239113, 0, 10277, 1, 0, 0, 60142), -- -Unknown-
(241467, 24, 239220, 0, 10278, 1, 0, 0, 60142), -- -Unknown-
(241467, 23, 239112, 0, 10278, 1, 0, 0, 60142), -- -Unknown-
(241467, 22, 239111, 0, 10276, 1, 0, 0, 60142), -- -Unknown-
(241467, 20, 78875, 0, 10251, 1, 0, 0, 60142), -- Shoulders of the Corrupted Conqueror
(241467, 17, 78872, 0, 10250, 1, 0, 0, 60142), -- Leggings of the Corrupted Conqueror
(241467, 14, 78869, 0, 10250, 1, 0, 0, 60142), -- Crown of the Corrupted Conqueror
(241467, 11, 78866, 0, 10251, 1, 0, 0, 60142), -- Gauntlets of the Corrupted Conqueror
(241467, 8, 78863, 0, 10250, 1, 0, 0, 60142), -- Chest of the Corrupted Conqueror
(241467, 5, 71681, 0, 10249, 1, 0, 0, 60142), -- Mantle of the Fiery Conqueror
(241467, 2, 71675, 0, 10249, 1, 0, 0, 60142); -- Helm of the Fiery Conqueror
