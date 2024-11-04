SET @CGUID := 3990023;

DELETE FROM `creature_template` WHERE `entry`=234135;
INSERT INTO `creature_template` (`entry`, `Civilian`, `KillCredit1`, `KillCredit2`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `RequiredExpansion`, `VignetteID`, `unit_class`, `WidgetSetID`, `WidgetSetUnitConditionID`, `Classification`, `family`, `type`, `PetSpellDataId`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(234135, 0, 0, 0, 'Kyanite Stonetender', NULL, 'Fissure Stone Fragment Exchange', NULL, NULL, 0, 0, 4, 0, 0, 0, 0, 7, 0, 0, 0, 57294); -- Kyanite Stonetender

DELETE FROM `creature_template_model` WHERE (`CreatureID`=234135 AND `Idx`=0);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(234135, 0, 35488, 0.60000002384185791, 1, 57294); -- Kyanite Stonetender

DELETE FROM `creature_template_difficulty` WHERE `Entry`= 234135;
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(234135, 0, 3, 1, 1, 0, 0x0, 0); -- Kyanite Stonetender

UPDATE `creature_template_difficulty` SET `MinLevel`=83, `MaxLevel`=83, `StaticFlags1`=0x20000000, `VerifiedBuild`=57294 WHERE (`Entry`=234135 AND `DifficultyID`=0); -- 234135 (Kyanite Stonetender) - Floating
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `speed_walk`=1.555556058883666992, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=234135; -- Kyanite Stonetender

DELETE FROM `creature_template_movement` WHERE `CreatureId`= 234135;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`) VALUES
(234135, 1);

DELETE FROM `npc_vendor` WHERE `entry`= 234135;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(234135, 98, 396, 1000, 9680, 2, 0, 0, 57294), -- 396
(234135, 97, 234446, 0, 9676, 1, 0, 0, 57294), -- -Unknown-
(234135, 96, 60232, 0, 9640, 1, 0, 0, 57294), -- Shroud of Endless Grief
(234135, 95, 60234, 0, 9640, 1, 0, 0, 57294), -- Bindings of Bleak Betrayal
(234135, 94, 60233, 0, 9640, 1, 0, 0, 57294), -- Shard of Woe
(234135, 93, 60235, 0, 9640, 1, 0, 0, 57294), -- Boots of Az'galada
(234135, 92, 60238, 0, 9640, 1, 0, 0, 57294), -- Bracers of the Dark Mother
(234135, 91, 60237, 0, 9640, 1, 0, 0, 57294), -- Crown of the Twilight Queen
(234135, 90, 60236, 0, 9640, 1, 0, 0, 57294), -- Nightmare Rider's Boots
(234135, 89, 60228, 0, 9640, 1, 0, 0, 57294), -- Bracers of the Mat'redor
(234135, 88, 60230, 0, 9640, 1, 0, 0, 57294), -- Twilight Scale Leggings
(234135, 87, 60229, 0, 9640, 1, 0, 0, 57294), -- War-Torn Crushers
(234135, 86, 60231, 0, 9640, 1, 0, 0, 57294), -- Belt of the Fallen Brood
(234135, 85, 60227, 0, 9640, 1, 0, 0, 57294), -- Caelestrasz's Will
(234135, 84, 60226, 0, 9640, 1, 0, 0, 57294), -- Dargonax's Signet
(234135, 83, 65029, 0, 9639, 1, 0, 0, 57294), -- Jar of Ancient Remedies
(234135, 82, 65109, 0, 9639, 1, 0, 0, 57294), -- Vial of Stolen Memories
(234135, 81, 65110, 0, 9639, 1, 0, 0, 57294), -- Heart of Ignacious
(234135, 80, 65118, 0, 9639, 1, 0, 0, 57294), -- Crushing Weight
(234135, 79, 65048, 0, 9639, 1, 0, 0, 57294), -- Symbiotic Worm
(234135, 78, 65072, 0, 9639, 1, 0, 0, 57294), -- Heart of Rage
(234135, 77, 65124, 0, 9639, 1, 0, 0, 57294), -- Fall of Mortality
(234135, 76, 65105, 0, 9639, 1, 0, 0, 57294), -- Theralion's Mirror
(234135, 75, 65140, 0, 9639, 1, 0, 0, 57294), -- Essence of the Cyclone
(234135, 74, 65053, 0, 9639, 1, 0, 0, 57294), -- Bell of Enraging Resonance
(234135, 73, 65026, 0, 9639, 1, 0, 0, 57294), -- Prestor's Talisman of Machination
(234135, 72, 65019, 0, 9638, 1, 0, 0, 57294), -- Shadowblaze Robes
(234135, 71, 65043, 0, 9638, 1, 0, 0, 57294), -- Mantle of Nefarius
(234135, 70, 65022, 0, 9639, 1, 0, 0, 57294), -- Belt of the Blackhand
(234135, 69, 65057, 0, 9639, 1, 0, 0, 57294), -- Belt of the Nightmare
(234135, 68, 65018, 0, 9637, 1, 0, 0, 57294), -- Shadow of Dread
(234135, 67, 65025, 0, 9637, 1, 0, 0, 57294), -- Rage of Ages
(234135, 66, 65027, 0, 9638, 1, 0, 0, 57294), -- Pauldrons of the Apocalypse
(234135, 65, 65074, 0, 9638, 1, 0, 0, 57294), -- Spaulders of the Scarred Lady
(234135, 64, 65138, 0, 9637, 1, 0, 0, 57294), -- Bracers of the Bronze Flight
(234135, 63, 65056, 0, 9637, 1, 0, 0, 57294), -- Bracers of the Burningeye
(234135, 62, 65050, 0, 9637, 1, 0, 0, 57294), -- Parasitic Bands
(234135, 61, 65021, 0, 9637, 1, 0, 0, 57294), -- Manacles of the Sleeping Beast
(234135, 60, 65068, 0, 9637, 1, 0, 0, 57294), -- Chaos Beast Bracers
(234135, 59, 65028, 0, 9637, 1, 0, 0, 57294), -- Chimaeron Armguards
(234135, 58, 65127, 0, 9637, 1, 0, 0, 57294), -- Shackles of the End of Days
(234135, 57, 65143, 0, 9637, 1, 0, 0, 57294), -- Bracers of Impossible Strength
(234135, 56, 65085, 0, 9637, 1, 0, 0, 57294), -- Electron Inductor Coils
(234135, 55, 63532, 0, 9672, 1, 0, 0, 57294), -- Dragonheart Piercer
(234135, 54, 59314, 0, 9674, 1, 0, 0, 57294), -- Finkle's Mixer Upper
(234135, 53, 59320, 0, 9672, 1, 0, 0, 57294), -- Themios the Darkbringer
(234135, 52, 59513, 0, 9674, 1, 0, 0, 57294), -- Scepter of Ice
(234135, 51, 59484, 0, 9674, 1, 0, 0, 57294), -- Book of Binding Will
(234135, 50, 59474, 0, 9672, 1, 0, 0, 57294), -- Malevolence
(234135, 49, 63679, 0, 9672, 1, 0, 0, 57294), -- Reclaimed Ashkandi, Greatsword of the Brotherhood
(234135, 48, 59492, 0, 9672, 1, 0, 0, 57294), -- Akirus the Worm-Breaker
(234135, 47, 59444, 0, 9673, 1, 0, 0, 57294), -- Akmin-Kurai, Dominion's Shield
(234135, 46, 59327, 0, 9673, 1, 0, 0, 57294), -- Kingdom's Heart
(234135, 45, 63680, 0, 9675, 1, 0, 0, 57294), -- Twilight's Hammer
(234135, 44, 63536, 0, 9675, 1, 0, 0, 57294), -- Blade of the Witching Hour
(234135, 43, 59459, 0, 9675, 1, 0, 0, 57294), -- Andoros, Fist of the Dragon King
(234135, 42, 59341, 0, 9675, 1, 0, 0, 57294), -- Incineratus
(234135, 41, 59330, 0, 9672, 1, 0, 0, 57294), -- Shalug'doom, the Axe of Unmaking
(234135, 40, 59494, 0, 9673, 1, 0, 0, 57294), -- "Uhn'agh Fash, the Darkest Betrayal"
(234135, 39, 63533, 0, 9673, 1, 0, 0, 57294), -- Fang of Twilight
(234135, 38, 59443, 0, 9673, 1, 0, 0, 57294), -- Crul'korak, the Lightning's Arc
(234135, 37, 59347, 0, 9673, 1, 0, 0, 57294), -- Mace of Acrid Death
(234135, 36, 59333, 0, 9673, 1, 0, 0, 57294), -- Lava Spine
(234135, 35, 59122, 0, 9673, 1, 0, 0, 57294), -- Organic Lifeform Inverter
(234135, 34, 232974, 0, 9669, 1, 0, 0, 57294), -- -Unknown-
(234135, 33, 232973, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 32, 232972, 0, 9670, 1, 0, 0, 57294), -- -Unknown-
(234135, 31, 232971, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 30, 232970, 0, 9669, 1, 0, 0, 57294), -- -Unknown-
(234135, 29, 232969, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 28, 232968, 0, 9669, 1, 0, 0, 57294), -- -Unknown-
(234135, 27, 232967, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 26, 232966, 0, 9669, 1, 0, 0, 57294), -- -Unknown-
(234135, 25, 232965, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 24, 232964, 0, 9670, 1, 0, 0, 57294), -- -Unknown-
(234135, 23, 232963, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 22, 232962, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 21, 232961, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 20, 232960, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 19, 232959, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 18, 232958, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 17, 232957, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 16, 232956, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 15, 232955, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 14, 232954, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 13, 232953, 0, 9669, 1, 0, 0, 57294), -- -Unknown-
(234135, 12, 232952, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 11, 232951, 0, 9669, 1, 0, 0, 57294), -- -Unknown-
(234135, 10, 232950, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 9, 232949, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 8, 232948, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 7, 232947, 0, 9671, 1, 0, 0, 57294), -- -Unknown-
(234135, 4, 64316, 0, 9668, 1, 0, 0, 57294), -- Mantle of the Forlorn Protector
(234135, 2, 63684, 0, 9668, 1, 0, 0, 57294), -- Helm of the Forlorn Protector
(234135, 3, 64315, 0, 9668, 1, 0, 0, 57294), -- Mantle of the Forlorn Conqueror
(234135, 1, 63683, 0, 9668, 1, 0, 0, 57294), -- Helm of the Forlorn Conqueror
(234135, 6, 63682, 0, 9668, 1, 0, 0, 57294), -- Helm of the Forlorn Vanquisher
(234135, 5, 64314, 0, 9668, 1, 0, 0, 57294); -- Mantle of the Forlorn Vanquisher

-- Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
--  Orgrimmar
(@CGUID+0, 17213, 1, 1637, 5170, '0', 169, 0, 0, 0, 1684.0208740234375, -4344, 63.66823196411132812, 4.827580928802490234, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Broom (Area: Valley of Strength - Difficulty: 0) CreateObject1
(@CGUID+1, 17213, 1, 1637, 5170, '0', 169, 0, 0, 0, 1685.5103759765625, -4350.52978515625, 63.66823196411132812, 1.658502697944641113, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Broom (Area: Valley of Strength - Difficulty: 0) CreateObject1
(@CGUID+2, 234135, 1, 1637, 5170, '0', 169, 0, 0, 0, 1685.1041259765625, -4347.05712890625, 62.66751861572265625, 3.198068141937255859, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Kyanite Stonetender (Area: Valley of Strength - Difficulty: 0) CreateObject1
-- Stormwind
(@CGUID+3, 17213, 0, 1519, 5149, '0', 169, 0, 0, 0, -8819.3681640625, 353.24652099609375, 107.13250732421875, 3.831870079040527343, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Broom (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+4, 17213, 0, 1519, 5149, '0', 169, 0, 0, 0, -8822.9306640625, 349.703125, 107.1323394775390625, 0.67846691608428955, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294), -- Broom (Area: Old Town - Difficulty: 0) CreateObject1
(@CGUID+5, 234135, 0, 1519, 5149, '0', 169, 0, 0, 0, -8821.69140625, 351.8125, 106.1323394775390625, 5.414412498474121093, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57294); -- Kyanite Stonetender (Area: Old Town - Difficulty: 0) CreateObject1
