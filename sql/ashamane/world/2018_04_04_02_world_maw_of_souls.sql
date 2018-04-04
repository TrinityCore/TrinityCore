SET @CGUID := 21014000;
SET @OGUID := 21003050;

UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12921;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9852;
UPDATE `areatrigger_template` SET `Type`=0, `Data0`=1, `Data1`=1, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9790;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10407;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=8090;
UPDATE `areatrigger_template` SET `Flags`=16, `VerifiedBuild`=26124 WHERE `Id`=10460;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11869;

DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=9790) OR (`SpellMiscId`=3468 AND `AreaTriggerId`=8090);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5069, 9790, 0, 0, 0, 0, 22, 0, 60000, 26124), -- SpellId : 194101
(3468, 8090, 0, 0, 0, 0, 0, 0, 600000, 26124); -- SpellId : 176595
-- (0, 11869, 0, 0, 0, 0, 0, 0, 0, 26124); -- SpellId : 0

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=8856 AND `AreaTriggerId`=12921); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5070 AND `AreaTriggerId`=9852); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4500, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=1697 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5428 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=21134, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=18278, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=26846, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=38270, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=41126, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=35415, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=23990, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=15422, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=32559, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=29702, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5838 AND `AreaTriggerId`=10407); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5224, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5748 AND `AreaTriggerId`=10460); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=1697 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=6866, `TimeToTargetScale`=750, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5748 AND `AreaTriggerId`=10460); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=10063, `TimeToTargetScale`=750, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5748 AND `AreaTriggerId`=10460); -- SpellId : 0

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (246985 /*Barnacled Cage*/, 246986 /*Barnacled Cage*/, 253993 /*Crusty Kvaldir Chest*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(246985, 0, 16), -- Barnacled Cage
(246986, 0, 16), -- Barnacled Cage
(253993, 0, 278560); -- Crusty Kvaldir Chest

UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=249729; -- The Masterful Miller's Manual

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+215;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7309.118, 7276.359, 57.28724, 0.8094178, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 196024 - Helheim)
(@CGUID+1, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7259.193, 7242.631, 31.04458, 5.153076, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 196024 - Helheim)
(@CGUID+2, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7299.171, 7284.519, 66.06635, 3.68415, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+3, 102108, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7266.526, 7283.823, 27.31654, 1.75255, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Captured Shieldmaiden (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+4, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7255.303, 7245.213, 32.08395, 5.147708, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 196024 - Helheim)
-- (@CGUID+5, 97208, UNKNOWN, 7812, 7812, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Spear (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 191903 - Lance) - !!! on transport - transport template not found !!!
(@CGUID+6, 102104, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7276.833, 7294.208, 30.54294, 0.2447417, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enslaved Shieldmaiden (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+7, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7318.976, 7320.529, 53.02057, 3.743758, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+8, 102896, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7272.857, 7288.393, 33.83196, 2.237862, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enslaved Shieldmaiden (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+9, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7229.134, 7267.433, 46.96513, 1.432974, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+10, 97043, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7278.266, 7304.166, 32.06875, 3.123117, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Esclavagiste maudit par les flots (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+11, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7254.615, 7246.831, 27.89255, 4.938305, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 196024 - Helheim)
(@CGUID+12, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7305.249, 7303.804, 47.45605, 6.08239, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+13, 97200, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7345.695, 7301.239, 42.85762, 6.12024, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Soulkeeper (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+14, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7287.996, 7261.157, 58.82544, 6.200471, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 196024 - Helheim)
(@CGUID+15, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7304.203, 7278.18, 48.78083, 1.937044, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+16, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7316.836, 7244.78, 18.60527, 5.505509, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+17, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7278.056, 7262.933, 49.56294, 4.121214, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+18, 114712, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7386.745, 7292.162, 43.86743, 0.05482224, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
-- (@CGUID+19, 97208, UNKNOWN, 7812, 7812, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Spear (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 191903 - Lance) - !!! on transport - transport template not found !!!
(@CGUID+20, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7349.78, 7260.906, 69.42625, 1.482801, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+21, 114712, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7386.509, 7304.949, 43.923, 5.692231, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
-- (@CGUID+22, 97208, UNKNOWN, 7812, 7812, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Spear (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 191903 - Lance) - !!! on transport - transport template not found !!!
(@CGUID+23, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7345.139, 7266.312, 70.70763, 1.111571, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+24, 102104, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7366.313, 7275.135, 43.95937, 2.03835, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enslaved Shieldmaiden (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+25, 114712, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7381.978, 7295.842, 43.8563, 0.2121703, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+26, 102375, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7370.083, 7273.213, 44.02735, 2.03835, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+27, 97043, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7363.89, 7278.892, 43.87113, 6.018615, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Esclavagiste maudit par les flots (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+28, 102894, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7362.337, 7317.049, 43.86743, 4.486273, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+29, 114712, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7384.608, 7286.067, 43.86743, 0.510936, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+30, 102375, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7374.147, 7275.221, 43.88184, 2.03835, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
-- (@CGUID+31, 102375, UNKNOWN, 7812, 7812, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+32, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7333.883, 7237.311, 86.50366, 6.248771, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+33, 102896, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7348.624, 7315.28, 43.86743, 5.018372, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enslaved Shieldmaiden (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
-- (@CGUID+34, 97208, UNKNOWN, 7812, 7812, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Spear (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 191903 - Lance) - !!! on transport - transport template not found !!!
(@CGUID+35, 97200, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7371.015, 7282.063, 43.86824, 4.821636, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Soulkeeper (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+36, 111374, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7427.319, 7277.133, 43.23317, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+37, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7396.434, 7278.526, 91.90795, 3.977866, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+38, 114712, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7393.358, 7306.038, 43.91209, 5.583257, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+39, 114712, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7393.052, 7312.54, 43.86743, 5.583257, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+40, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7394.725, 7186.672, 40.58971, 6.126225, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+41, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7402.854, 7320.853, 73.86744, 2.923058, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+42, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7361.366, 7193.775, 26.34376, 1.695675, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+43, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7417.659, 7286.854, 100.2641, 2.923874, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@CGUID+44, 96756, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7407.954, 7265.255, 51.08705, 5.549542, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ymiron, the Fallen King (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 118357 - Puissance à zéro + régénération à zéro, 197227 - Agenouillé)
(@CGUID+45, 97163, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7396.699, 7181.069, 40.50397, 4.511701, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+46, 114712, 1492, 7812, 7812, 8388870, '0', 0, 0, 0, 7390.375, 7285.93, 43.86743, 0.328258, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Runecarver Slave (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque) (Auras: )
(@CGUID+47, 103115, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2945.721, 874.7188, 515.2433, 3.447548, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helheim (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 204001 - Cage kvaldir)
(@CGUID+48, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2950.148, 799.0247, 515.3503, 4.708594, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+49, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2946.576, 793.6931, 515.3504, 5.916994, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+50, 102327, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2952.944, 832.2327, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+51, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2903.462, 825.8333, 515.2433, 2.370274, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil, 197227 - Agenouillé, 42459 - Ambidextrie)
(@CGUID+52, 97365, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2905.726, 831.0504, 515.2433, 2.246976, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Mistmender (Area: Le Naglfar - Difficulty: Héroïque)
-- (@CGUID+53, 98291, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, -1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 193667 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+54, 111221, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.238, 692.9913, 553.5659, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Le Naglfar - Difficulty: Héroïque)
(@CGUID+55, 97200, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2905.609, 836.3733, 515.2433, 3.811235, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Soulkeeper (Area: Le Naglfar - Difficulty: Héroïque)
(@CGUID+56, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2952.564, 725.4011, 574.1972, 0.7621754, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191835 - Helheim)
(@CGUID+57, 103115, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2943.061, 868.9514, 515.2433, 3.082287, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helheim (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 204001 - Cage kvaldir)
(@CGUID+58, 111374, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.455, 927.2795, 512.4943, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+59, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2948.383, 791.5029, 515.3503, 0.6012135, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+60, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2902.056, 741.4029, 515.2227, 3.613761, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil, 42459 - Ambidextrie)
(@CGUID+61, 102742, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2900.484, 832.3768, 515.2433, 0.3137651, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fallen Shieldmaiden (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 203038 - Cadavre vrykul)
(@CGUID+62, 102327, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2953.834, 811.5625, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+63, 102325, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2910.147, 833.0243, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+64, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2898.324, 817.125, 519.0612, 5.937058, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
(@CGUID+65, 99188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2958.225, 822.7979, 515.3869, 4.415527, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Waterlogged Soul Guard (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+66, 102326, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 202034 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+67, 97182, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2961.375, 740.4375, 515.2292, 4.999093, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Night Watch Mariner (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 199867 - Casque, 203605 - Escrime, 67236 - Détection de l'invisibilité et du camouflage)
(@CGUID+68, 103115, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.596, 876.4236, 515.2433, 5.736162, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helheim (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 204001 - Cage kvaldir)
(@CGUID+69, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2949.513, 789.2717, 515.3503, 1.486242, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+70, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2949.59, 796.0051, 515.3503, 4.766274, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil, 42459 - Ambidextrie)
(@CGUID+71, 102830, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2904.111, 820.0347, 515.2433, 3.710789, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Deceased Sorcerer (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 70628 - Feindre la mort permanent)
(@CGUID+72, 104906, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2944.066, 720.743, 555.2134, 3.97919, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Captured Val'kyr (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 207772 - Siphon d’âme)
(@CGUID+73, 111833, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.047, 848.6094, 515.2433, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Thal'kiel (Area: Le Naglfar - Difficulty: Héroïque)
(@CGUID+74, 102327, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2953.642, 752.059, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+75, 102327, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2955.675, 771.2257, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+76, 98291, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, -1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 193667 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+77, 99188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2911.404, 784.1945, 515.2433, 0.7950303, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Waterlogged Soul Guard (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 203602 - Blocage)
(@CGUID+78, 102325, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2911.36, 773.1337, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+79, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2978.531, 779.6736, 544.7955, 1.58504, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191835 - Helheim)
(@CGUID+80, 103115, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.235, 870.1996, 515.2433, 6.280761, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helheim (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 204001 - Cage kvaldir)
(@CGUID+81, 97182, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2917.062, 774.4025, 515.3503, 1.710853, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Night Watch Mariner (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 199867 - Casque, 203605 - Escrime, 67236 - Détection de l'invisibilité et du camouflage)
-- (@CGUID+82, 102326, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 202034 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+83, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2952.537, 801.9525, 515.3503, 4.555758, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+84, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2913.538, 743.8542, 515.2194, 1.647367, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil, 42459 - Ambidextrie)
(@CGUID+85, 98973, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2906.268, 753.4844, 515.2433, 4.668108, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+86, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2949.3, 795.9516, 515.3503, 4.797192, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+87, 102327, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2955.652, 791.9288, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+88, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2903.607, 821.2344, 515.2433, 4.086382, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
-- (@CGUID+89, 98291, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, -1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 193667 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+90, 102325, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2910.782, 793.1893, 510.6331, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+91, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2952.7, 709.8055, 565.6466, 1.172448, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191835 - Helheim)
(@CGUID+92, 97185, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2947.95, 758.559, 515.2433, 1.086106, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- The Grimewalker (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194583 - Marteau en os)
-- (@CGUID+93, 102326, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 202034 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+94, 102769, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2964.29, 837.8594, 515.2433, 4.118559, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Decrepit Runecarver (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 203058 - Cadavre vrykul)
(@CGUID+95, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2950.445, 797.0134, 515.3503, 4.679619, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+96, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2950.075, 797.3006, 515.3503, 4.714784, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil, 42459 - Ambidextrie)
(@CGUID+97, 98973, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2904.208, 750.493, 515.2433, 0.4564339, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+98, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2940.363, 728.1007, 571.9398, 1.074731, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191835 - Helheim)
(@CGUID+99, 103115, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2942.407, 879.7691, 515.2433, 4.018917, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helheim (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 204001 - Cage kvaldir)
(@CGUID+100, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2950.167, 800.8161, 515.3503, 5.277935, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+101, 97119, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2949.979, 795.4565, 515.3503, 4.726106, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Shroud Hound (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+102, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2902.226, 817.1215, 515.2433, 1.342426, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191889 - Plongeon)
-- (@CGUID+103, 98291, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, -1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 193667 - Rame) - !!! on transport - transport template not found !!!
-- (@CGUID+104, 98291, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, -1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 193667 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+105, 99188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2921.481, 780.441, 515.2433, 1.812805, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Waterlogged Soul Guard (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 203602 - Blocage)
-- (@CGUID+106, 102326, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 1, -9, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Rower (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded, 202034 - Rame) - !!! on transport - transport template not found !!!
(@CGUID+107, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2923.781, 724.2708, 558.2221, 2.31174, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191835 - Helheim)
(@CGUID+108, 97163, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2891.002, 695.5191, 132.2333, 1.172448, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cursed Falke (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 191835 - Helheim)
(@CGUID+109, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2937.323, 700.0623, 553.6962, 3.739763, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+110, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
(@CGUID+111, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2929.06, 694.431, 553.6338, 3.739763, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+112, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
-- (@CGUID+113, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
(@CGUID+114, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2916.664, 685.9839, 554.1036, 3.739763, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+115, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
-- (@CGUID+116, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
-- (@CGUID+117, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
-- (@CGUID+118, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
-- (@CGUID+119, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
-- (@CGUID+120, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
(@CGUID+121, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2927.891, 701.004, 553.9653, 1.379395, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+122, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2928.842, 705.9127, 554.0415, 1.379395, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+123, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2929.793, 710.8214, 554.2336, 1.379395, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+124, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
(@CGUID+125, 98761, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2916.812, 697.2688, 553.6337, 2.234098, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Soul Fragment (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+126, 98761, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2916.933, 696.4113, 553.6337, 4.328482, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Soul Fragment (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+127, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2932.022, 697.1939, 554.0336, 3.469719, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+128, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
(@CGUID+129, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.555, 693.9712, 553.6337, 3.469719, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+130, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2917.822, 692.3599, 553.6337, 3.469719, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+131, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
(@CGUID+132, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2894.156, 684.3031, 501.6337, 3.469719, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+133, 100839, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2889.422, 682.6918, 501.6337, 3.469719, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+134, 98989, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Cosmic Scythe (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198580 - Faux cosmique) - !!! on transport - transport template not found !!!
(@CGUID+135, 99307, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.65, 874.5573, 537.3766, 4.651583, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skjal (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195517 - Voile)
(@CGUID+136, 97097, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2957.076, 744.3143, 538.6071, 5.072854, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helarjar Champion (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 42459 - Ambidextrie)
(@CGUID+137, 97097, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2949.207, 798.0052, 535.4015, 5.090273, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helarjar Champion (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 42459 - Ambidextrie)
(@CGUID+138, 97097, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2918.532, 803.5972, 535.6491, 5.090273, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helarjar Champion (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 42459 - Ambidextrie)
(@CGUID+139, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2940.283, 918.507, 512.6249, 4.373073, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil)
(@CGUID+140, 99033, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2925.457, 919.1545, 512.6249, 5.076292, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helarjar Mistcaller (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 239777 - Soigne-mer kvaldir)
(@CGUID+141, 99033, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2940.283, 918.507, 512.6249, 4.3069, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helarjar Mistcaller (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 239777 - Soigne-mer kvaldir)
(@CGUID+142, 97200, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2925.457, 919.1545, 512.6249, 5.146553, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Soulkeeper (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+143, 97365, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2925.457, 919.1545, 512.6249, 4.740427, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Mistmender (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+144, 97200, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2940.283, 918.507, 512.6249, 4.777414, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Soulkeeper (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+145, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2925.457, 919.1545, 512.6249, 5.169266, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil)
(@CGUID+146, 97365, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2940.283, 918.507, 512.6249, 4.777414, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Mistmender (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+147, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2926.09, 896.5629, 538.1902, 4.740427, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil, 42459 - Ambidextrie)
(@CGUID+148, 98919, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2932.68, 896.967, 537.9398, 4.373073, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Seacursed Swiftblade (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195219 - Couvre-œil, 42459 - Ambidextrie)
(@CGUID+149, 99033, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2938.593, 896.1962, 538.3311, 4.636765, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helarjar Mistcaller (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 239777 - Soigne-mer kvaldir)
(@CGUID+150, 99033, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.626, 897.7036, 537.9101, 5.076292, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helarjar Mistcaller (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 239777 - Soigne-mer kvaldir)
(@CGUID+151, 114288, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2924.017, 887.9161, 538.483, 4.861817, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+152, 114288, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2940.227, 888.0155, 538.2805, 4.693444, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+153, 114288, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2919.595, 917.2899, 512.4025, 4.926863, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+154, 114288, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2927.744, 918.5799, 512.3472, 4.744232, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+155, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2923.298, 861.1009, 537.6047, 1.796391, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+156, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.917, 862.7635, 537.7944, 1.796391, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+157, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.535, 864.4263, 537.8997, 1.796391, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+158, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.154, 866.089, 538.0438, 1.796391, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+159, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2921.772, 867.7516, 537.6118, 1.796391, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+160, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.662, 868.3027, 537.2336, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+161, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2923.934, 867.191, 537.2336, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+162, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2925.206, 866.0793, 537.2337, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+163, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2926.478, 864.9676, 537.2337, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+164, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2927.75, 863.8559, 537.2337, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+165, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2929.021, 862.7441, 537.2337, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+166, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2930.293, 861.6324, 537.2337, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+167, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2931.565, 860.5208, 537.9847, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+168, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2932.837, 859.4091, 538.3741, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+169, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2934.109, 858.2974, 537.9463, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+170, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2935.381, 857.1857, 537.9126, 5.564877, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+171, 114288, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2919.595, 917.2899, 512.4025, 5.249017, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+172, 114288, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2940.784, 917.4288, 512.3472, 4.281193, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+173, 114288, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2927.744, 918.5799, 512.3472, 5.072357, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Warrior (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198395 - Rage)
(@CGUID+174, 114289, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2919.595, 917.2899, 512.4025, 5.287576, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Skeletal Sorcerer (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198404 - Mana)
(@CGUID+175, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2926.023, 853.7467, 538.1561, 5.117855, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+176, 101504, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2895.88, 926.6337, 515.0833, 5.113815, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198180 - Helya)
(@CGUID+177, 101814, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2974.353, 926.6337, 515.0833, 4.310963, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 196450 - Helya)
(@CGUID+178, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2926.669, 852.2407, 538.2935, 5.117855, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+179, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2927.316, 850.7346, 538.1469, 5.117855, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+180, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2927.962, 849.2285, 538.2336, 5.117855, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+181, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2928.609, 847.7224, 538.2256, 5.117855, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+182, 100733, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2929.255, 846.2164, 538.1514, 5.117855, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Charge (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 198270 - Charge de pirate)
(@CGUID+183, 96759, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.499, 1055.943, 510.5183, 4.799655, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helya (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194603 - Cri sans âme)
(@CGUID+184, 100361, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2919.81, 959.984, 513.2063, 5.852089, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+185, 100362, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2919.81, 959.984, 513.2896, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+186, 101502, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 3023.577, 1233.932, 459.822, 4.002816, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helya's Tentacle (Area: Le Naglfar - Difficulty: Héroïque)
(@CGUID+187, 101502, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2838.495, 1233.932, 457.564, 5.052534, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Helya's Tentacle (Area: Le Naglfar - Difficulty: Héroïque)
(@CGUID+188, 99800, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2942.16, 967.024, 513.7823, 4.080632, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+189, 98363, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+190, 97099, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.245, 960.4375, 512.4185, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195167 - Bassin tourbillonnant)
-- (@CGUID+191, 99801, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Destructor Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+192, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.2, 937.078, 512.4183, 5.8294, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+193, 99800, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2949.951, 951.9184, 513.7823, 3.647738, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+194, 98363, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2949.951, 951.9184, 513.8657, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+195, 97099, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.387, 941.0712, 512.4183, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195167 - Bassin tourbillonnant)
(@CGUID+196, 99803, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.282, 960.3768, 512.4185, 4.712389, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Destructor Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
(@CGUID+197, 99801, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.282, 960.3768, 512.5018, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Destructor Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+198, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.4, 941.155, 512.4183, 6.056293, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197112 - Tentacule perforant)
(@CGUID+199, 100361, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2919.81, 959.984, 513.2063, 5.852089, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: )
-- (@CGUID+200, 100362, UNKNOWN, 7812, 7811, 8388870, '0', 0, 0, 0, 0, 0, 0, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Grasping Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+201, 102306, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.4, 941.155, 512.4183, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197753 - Eaux turbulentes)
(@CGUID+202, 102306, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.2, 937.078, 512.4183, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197753 - Eaux turbulentes)
(@CGUID+203, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.4, 941.155, 512.4183, 0.8377581, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197112 - Tentacule perforant)
(@CGUID+204, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.282, 960.3768, 512.4185, 4.049164, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197112 - Tentacule perforant)
(@CGUID+205, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.2, 937.078, 512.4183, 2.740167, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+206, 102306, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.4, 941.155, 512.4183, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197753 - Eaux turbulentes)
(@CGUID+207, 102306, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.282, 960.3768, 512.4185, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197753 - Eaux turbulentes)
(@CGUID+208, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.4, 941.155, 512.4183, 2.670354, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197112 - Tentacule perforant)
(@CGUID+209, 102306, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.2, 937.078, 512.4183, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197753 - Eaux turbulentes)
(@CGUID+210, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.282, 960.3768, 512.4185, 1.43117, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 194414 - Cage aux âmes)
(@CGUID+211, 97099, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2948.531, 921.4896, 512.4183, 1.570796, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 195167 - Bassin tourbillonnant)
(@CGUID+212, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2948.52, 921.457, 512.4183, 1.832596, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197112 - Tentacule perforant)
(@CGUID+213, 100188, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2922.2, 937.078, 512.4183, 1.745329, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Piercing Tentacle (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197112 - Tentacule perforant)
(@CGUID+214, 102306, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.4, 941.155, 512.4183, 0, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Swirling Pool (Area: Le Naglfar - Difficulty: Héroïque) (Auras: 197753 - Eaux turbulentes)
(@CGUID+215, 96754, 1492, 7812, 7811, 8388870, '0', 0, 0, 0, 2933.464844, 709.300171, 553.769897, 4.679447, 86400, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Harbaron (Area: Le Naglfar - Difficulty: Héroïque)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+215;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 50331648, 1, 0, 0, 0, 0, '196024'), -- Cursed Falke - 196024 - Helheim
(@CGUID+1, 0, 0, 50331648, 1, 0, 0, 0, 0, '196024'), -- Cursed Falke - 196024 - Helheim
(@CGUID+2, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+3, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Captured Shieldmaiden
(@CGUID+4, 0, 0, 50331648, 1, 0, 0, 0, 0, '196024'), -- Cursed Falke - 196024 - Helheim
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, '46598 191903'), -- Spear - 46598 - Ride Vehicle Hardcoded, 191903 - Lance
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Enslaved Shieldmaiden
(@CGUID+7, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Enslaved Shieldmaiden
(@CGUID+9, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Esclavagiste maudit par les flots
(@CGUID+11, 0, 0, 50331648, 1, 0, 0, 0, 0, '196024'), -- Cursed Falke - 196024 - Helheim
(@CGUID+12, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Seacursed Soulkeeper
(@CGUID+14, 0, 0, 50331648, 1, 0, 0, 0, 0, '196024'), -- Cursed Falke - 196024 - Helheim
(@CGUID+15, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+16, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+17, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+18, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, '46598 191903'), -- Spear - 46598 - Ride Vehicle Hardcoded, 191903 - Lance
(@CGUID+20, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+21, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '46598 191903'), -- Spear - 46598 - Ride Vehicle Hardcoded, 191903 - Lance
(@CGUID+23, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Enslaved Shieldmaiden
(@CGUID+25, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Esclavagiste maudit par les flots
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+29, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Runecarver Slave - 46598 - Ride Vehicle Hardcoded
(@CGUID+32, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Enslaved Shieldmaiden
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, '46598 191903'), -- Spear - 46598 - Ride Vehicle Hardcoded, 191903 - Lance
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Seacursed Soulkeeper
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+37, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+38, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+39, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+40, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+41, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+42, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+43, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cursed Falke
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, '118357 197227'), -- Ymiron, the Fallen King - 118357 - Puissance à zéro + régénération à zéro, 197227 - Agenouillé
(@CGUID+45, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+46, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Runecarver Slave
(@CGUID+47, 0, 0, 50331648, 1, 0, 0, 0, 0, '204001'), -- Helheim - 204001 - Cage kvaldir
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+50, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, '195219 197227 42459'), -- Seacursed Swiftblade - 195219 - Couvre-œil, 197227 - Agenouillé, 42459 - Ambidextrie
(@CGUID+52, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Seacursed Mistmender
(@CGUID+53, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 193667'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 193667 - Rame
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Seacursed Soulkeeper
(@CGUID+56, 0, 0, 50331648, 1, 0, 0, 0, 0, '191835'), -- Cursed Falke - 191835 - Helheim
(@CGUID+57, 0, 0, 50331648, 1, 0, 0, 0, 0, '204001'), -- Helheim - 204001 - Cage kvaldir
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Xal'atath - 194414 - Cage aux âmes
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade - 195219 - Couvre-œil, 42459 - Ambidextrie
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, '203038'), -- Fallen Shieldmaiden - 203038 - Cadavre vrykul
(@CGUID+62, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+63, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+64, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Waterlogged Soul Guard
(@CGUID+66, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 202034'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 202034 - Rame
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '199867 203605 67236'), -- Night Watch Mariner - 199867 - Casque, 203605 - Escrime, 67236 - Détection de l'invisibilité et du camouflage
(@CGUID+68, 0, 0, 50331648, 1, 0, 0, 0, 0, '204001'), -- Helheim - 204001 - Cage kvaldir
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade - 195219 - Couvre-œil, 42459 - Ambidextrie
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- Deceased Sorcerer - 70628 - Feindre la mort permanent
(@CGUID+72, 0, 0, 50331648, 1, 0, 0, 0, 0, '207772'), -- Captured Val'kyr - 207772 - Siphon d’âme
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+74, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+75, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+76, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 193667'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 193667 - Rame
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '203602'), -- Waterlogged Soul Guard - 203602 - Blocage
(@CGUID+78, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+79, 0, 0, 50331648, 1, 0, 0, 0, 0, '191835'), -- Cursed Falke - 191835 - Helheim
(@CGUID+80, 0, 0, 50331648, 1, 0, 0, 0, 0, '204001'), -- Helheim - 204001 - Cage kvaldir
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, '199867 203605 67236'), -- Night Watch Mariner - 199867 - Casque, 203605 - Escrime, 67236 - Détection de l'invisibilité et du camouflage
(@CGUID+82, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 202034'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 202034 - Rame
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade - 195219 - Couvre-œil, 42459 - Ambidextrie
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+87, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+88, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+89, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 193667'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 193667 - Rame
(@CGUID+90, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Seacursed Rower
(@CGUID+91, 0, 0, 50331648, 1, 0, 0, 0, 0, '191835'), -- Cursed Falke - 191835 - Helheim
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, '194583'), -- The Grimewalker - 194583 - Marteau en os
(@CGUID+93, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 202034'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 202034 - Rame
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, '203058'), -- Decrepit Runecarver - 203058 - Cadavre vrykul
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade - 195219 - Couvre-œil, 42459 - Ambidextrie
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+98, 0, 0, 50331648, 1, 0, 0, 0, 0, '191835'), -- Cursed Falke - 191835 - Helheim
(@CGUID+99, 0, 0, 50331648, 1, 0, 0, 0, 0, '204001'), -- Helheim - 204001 - Cage kvaldir
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Shroud Hound
(@CGUID+102, 0, 0, 50331648, 1, 0, 0, 0, 0, '191889'), -- Cursed Falke - 191889 - Plongeon
(@CGUID+103, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 193667'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 193667 - Rame
(@CGUID+104, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 193667'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 193667 - Rame
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, '203602'), -- Waterlogged Soul Guard - 203602 - Blocage
(@CGUID+106, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598 202034'), -- Seacursed Rower - 46598 - Ride Vehicle Hardcoded, 202034 - Rame
(@CGUID+107, 0, 0, 50331648, 1, 0, 0, 0, 0, '191835'), -- Cursed Falke - 191835 - Helheim
(@CGUID+108, 0, 0, 50331648, 1, 0, 0, 0, 0, '191835'), -- Cursed Falke - 191835 - Helheim
(@CGUID+109, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+110, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+111, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+112, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+113, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+114, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+115, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+116, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+117, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+118, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+119, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+120, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+121, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+122, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+123, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+124, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soul Fragment
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Soul Fragment
(@CGUID+127, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+128, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+129, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+130, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+131, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+132, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+133, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Cosmic Scythe
(@CGUID+134, 0, 0, 50331648, 1, 0, 0, 0, 0, '198580'), -- Cosmic Scythe - 198580 - Faux cosmique
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, '195517'), -- Skjal - 195517 - Voile
(@CGUID+136, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Helarjar Champion - 42459 - Ambidextrie
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Helarjar Champion - 42459 - Ambidextrie
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Helarjar Champion - 42459 - Ambidextrie
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, '195219'), -- Seacursed Swiftblade - 195219 - Couvre-œil
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '239777'), -- Helarjar Mistcaller - 239777 - Soigne-mer kvaldir
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, '239777'), -- Helarjar Mistcaller - 239777 - Soigne-mer kvaldir
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Seacursed Soulkeeper - 194414 - Cage aux âmes
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Seacursed Mistmender - 194414 - Cage aux âmes
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Seacursed Soulkeeper - 194414 - Cage aux âmes
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, '195219'), -- Seacursed Swiftblade - 195219 - Couvre-œil
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Seacursed Mistmender - 194414 - Cage aux âmes
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade - 195219 - Couvre-œil, 42459 - Ambidextrie
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, '195219 42459'), -- Seacursed Swiftblade - 195219 - Couvre-œil, 42459 - Ambidextrie
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, '239777'), -- Helarjar Mistcaller - 239777 - Soigne-mer kvaldir
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, '239777'), -- Helarjar Mistcaller - 239777 - Soigne-mer kvaldir
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+162, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+167, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+168, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+170, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+171, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, '198395'), -- Skeletal Warrior - 198395 - Rage
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '198404'), -- Skeletal Sorcerer - 198404 - Mana
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+176, 0, 0, 50331648, 1, 0, 0, 0, 0, '198180'), -- Grasping Tentacle - 198180 - Helya
(@CGUID+177, 0, 0, 50331648, 1, 0, 0, 0, 0, '196450'), -- Grasping Tentacle - 196450 - Helya
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+182, 0, 0, 0, 1, 0, 0, 0, 0, '198270'), -- Charge - 198270 - Charge de pirate
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, '194603'), -- Helya - 194603 - Cri sans âme
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Grasping Tentacle
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Grasping Tentacle - 46598 - Ride Vehicle Hardcoded
(@CGUID+186, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Helya's Tentacle
(@CGUID+187, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Helya's Tentacle
(@CGUID+188, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Grasping Tentacle
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Grasping Tentacle - 46598 - Ride Vehicle Hardcoded
(@CGUID+190, 0, 0, 50331648, 1, 0, 0, 0, 0, '195167'), -- Swirling Pool - 195167 - Bassin tourbillonnant
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Destructor Tentacle - 46598 - Ride Vehicle Hardcoded
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Piercing Tentacle - 194414 - Cage aux âmes
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Grasping Tentacle
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Grasping Tentacle - 46598 - Ride Vehicle Hardcoded
(@CGUID+195, 0, 0, 50331648, 1, 0, 0, 0, 0, '195167'), -- Swirling Pool - 195167 - Bassin tourbillonnant
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Destructor Tentacle
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Destructor Tentacle - 46598 - Ride Vehicle Hardcoded
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '197112'), -- Piercing Tentacle - 197112 - Tentacule perforant
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Grasping Tentacle
(@CGUID+200, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Grasping Tentacle - 46598 - Ride Vehicle Hardcoded
(@CGUID+201, 0, 0, 50331648, 1, 0, 0, 0, 0, '197753'), -- Swirling Pool - 197753 - Eaux turbulentes
(@CGUID+202, 0, 0, 50331648, 1, 0, 0, 0, 0, '197753'), -- Swirling Pool - 197753 - Eaux turbulentes
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, '197112'), -- Piercing Tentacle - 197112 - Tentacule perforant
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, '197112'), -- Piercing Tentacle - 197112 - Tentacule perforant
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Piercing Tentacle - 194414 - Cage aux âmes
(@CGUID+206, 0, 0, 50331648, 1, 0, 0, 0, 0, '197753'), -- Swirling Pool - 197753 - Eaux turbulentes
(@CGUID+207, 0, 0, 50331648, 1, 0, 0, 0, 0, '197753'), -- Swirling Pool - 197753 - Eaux turbulentes
(@CGUID+208, 0, 0, 0, 1, 0, 0, 0, 0, '197112'), -- Piercing Tentacle - 197112 - Tentacule perforant
(@CGUID+209, 0, 0, 50331648, 1, 0, 0, 0, 0, '197753'), -- Swirling Pool - 197753 - Eaux turbulentes
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, '194414'), -- Piercing Tentacle - 194414 - Cage aux âmes
(@CGUID+211, 0, 0, 50331648, 1, 0, 0, 0, 0, '195167'), -- Swirling Pool - 195167 - Bassin tourbillonnant
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, '197112'), -- Piercing Tentacle - 197112 - Tentacule perforant
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, '197112'), -- Piercing Tentacle - 197112 - Tentacule perforant
(@CGUID+214, 0, 0, 50331648, 1, 0, 0, 0, 0, '197753'); -- Swirling Pool - 197753 - Eaux turbulentes

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+47;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 245063, 1492, 7812, 7812, 8388870, '0', 0, 7273.168, 7287.924, 33.72406, 2.286379, 0, 0, 0.9099607, 0.4146944, 86400, 255, 1, 26124), -- Kvaldir Cage (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+1, 245064, 1492, 7812, 7812, 8388870, '0', 0, 7266.36, 7283.658, 26.68779, 1.003559, 0, 0, 0.4809866, 0.8767279, 86400, 255, 0, 26124), -- Kvaldir Cage (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+2, 245065, 1492, 7812, 7812, 8388870, '0', 0, 7260.633, 7284.174, 25.8094, 0.4974239, 0, 0, 0.2461557, 0.9692303, 86400, 255, 1, 26124), -- Kvaldir Cage (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+3, 252145, 1492, 7812, 7812, 8388870, '0', 0, 7162.329, 7317.961, 20.86309, 0.2037807, 0, 0, 0.1017141, 0.9948137, 86400, 255, 1, 26124), -- Instance Portal (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+4, 245062, 1492, 7812, 7812, 8388870, '0', 0, 7355.401, 7315.599, 47.93732, 4.424408, 0, 0, -0.8012543, 0.598324, 86400, 255, 1, 26124), -- Kvaldir Cage (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+5, 245066, 1492, 7812, 7812, 8388870, '0', 0, 7362.204, 7316.752, 43.68834, 4.276065, -0.02543831, 0.01067924, -0.8432598, 0.5367976, 86400, 255, 1, 26124), -- Kvaldir Cage (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+6, 245067, 1492, 7812, 7812, 8388870, '0', 0, 7348.616, 7314.836, 43.69791, 4.633855, 0, 0, -0.7343206, 0.6788027, 86400, 255, 1, 26124), -- Kvaldir Cage (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+7, 247041, 1492, 7812, 7812, 8388870, '0', 0, 7420.499, 7245.048, 53.57076, 5.139995, -0.01649523, -0.03176975, -0.5405283, 0.840564, 86400, 255, 1, 26124), -- Echoing Horn of the Damned (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
(@OGUID+8, 253001, 1492, 7812, 7812, 8388870, '0', 0, 7509.893, 7286.906, -6.652445, 4.255993, -0.04124069, -0.03155231, -0.8474579, 0.5283169, 86400, 255, 1, 26124), -- Rune-etched Archway (Area: Falaises de l’embouchure de Hel - Difficulty: Héroïque)
-- (@OGUID+9, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2943.061, 868.9514, 513.2433, 3.082284, 0, 0, 0.9995604, 0.02964977, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+10, 224697, 1492, 7812, 7811, 8388870, '0', 0, 2902.404, 818.9393, 515.16, 1.592046, 0, 0, 0.7145796, 0.6995541, 86400, 255, 1, 26124), -- Fresh Carcass (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+11, 251963, 1492, 7812, 7811, 8388870, '0', 0, 2905.206, 778.7761, 514.7967, 4.501196, 0, 0, -0.7776976, 0.6286386, 86400, 255, 1, 26124), -- 7VR_VRYKUL_RITUALROCKS02 [scale x3] (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+12, 251960, 1492, 7812, 7811, 8388870, '0', 0, 2906.655, 779.3055, 514.7413, 4.826448, -0.07831383, -0.1981573, -0.6390667, 0.7390497, 86400, 255, 1, 26124), -- The Raven's Eye Tablet (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+13, 246947, 1492, 7812, 7811, 8388870, '0', 0, 2959.168, 705.1895, 553.0551, 4.478926, 0, 0, -0.7846489, 0.6199404, 86400, 255, 1, 26124), -- Wall of Souls (Area: Le Naglfar - Difficulty: Héroïque)
-- (@OGUID+14, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2922.596, 876.4236, 513.2433, 5.736163, 0, 0, -0.2701139, 0.9628283, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
-- (@OGUID+15, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2943.061, 868.9514, 517.2433, 3.082284, 0, 0, 0.9995604, 0.02964977, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+16, 265476, 1492, 7812, 7811, 8388870, '0', 0, 2917.944, 890.4429, 537.483, 4.625124, 0, 0, -0.737277, 0.6755905, 86400, 255, 1, 26124), -- Murky Fog (Area: Le Naglfar - Difficulty: Héroïque)
-- (@OGUID+17, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2942.407, 879.7691, 513.2433, 4.018919, 0, 0, -0.9053202, 0.4247298, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+18, 251963, 1492, 7812, 7811, 8388870, '0', 0, 2907.83, 779.2552, 514.847, 5.624163, 0, 0, -0.3235807, 0.9462005, 86400, 255, 1, 26124), -- 7VR_VRYKUL_RITUALROCKS02 [scale x3] (Area: Le Naglfar - Difficulty: Héroïque)
-- (@OGUID+19, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2922.596, 876.4236, 517.2433, 5.736163, 0, 0, -0.2701139, 0.9628283, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+20, 253993, 1492, 7812, 7811, 8388870, '0', 0, 2966.815, 724.1406, 515.0558, 3.207945, 0, 0, -0.9994497, 0.0331699, 86400, 255, 1, 26124), -- Crusty Kvaldir Chest (Area: Le Naglfar - Difficulty: Héroïque)
-- (@OGUID+21, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2942.407, 879.7691, 517.2433, 4.018919, 0, 0, -0.9053202, 0.4247298, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+22, 246888, 1492, 7812, 7811, 8388870, '0', 0, 2933.655, 662.9053, 550.6401, 4.745909, 0, 0, -0.6951571, 0.7188579, 86400, 255, 0, 26124), -- Heavy Barnacled Door (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+24, 246889, 1492, 7812, 7811, 8388870, '0', 0, 2961.13, 737.2842, 515.1832, 1.550618, 0, 0, 0.6999369, 0.7142047, 86400, 255, 1, 26124), -- Heavy Barnacled Door (Area: Le Naglfar - Difficulty: Héroïque)
-- (@OGUID+26, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2922.235, 870.1996, 513.2433, 6.280763, 0, 0, -0.001211166, 0.9999992, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+28, 243403, 1492, 7812, 7811, 8388870, '0', 0, 2908.367, 704.7882, 552.8664, 4.971017, 0, 0, -0.6100187, 0.7923869, 86400, 255, 1, 26124), -- Collision Wall (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+47, 246840, 1492, 7812, 7811, 8388870, '0', 0, 2939.466, 928.6776, 511.5006, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 001 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+31, 246842, 1492, 7812, 7811, 8388870, '0', 0, 2927.263, 928.6776, 511.5012, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 002 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+32, 246843, 1492, 7812, 7811, 8388870, '0', 0, 2918.251, 921.3049, 511.8901, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 003 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+36, 246844, 1492, 7812, 7811, 8388870, '0', 0, 2948.415, 921.3049, 511.8901, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 004 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+27, 246839, 1492, 7812, 7811, 8388870, '0', 0, 2944.44,  936.7287, 512.0367, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 005 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+23, 246834, 1492, 7812, 7811, 8388870, '0', 0, 2922.226, 936.7287, 512.0367, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 007 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+29, 246836, 1492, 7812, 7811, 8388870, '0', 0, 2926.742, 952.1555, 512.0009, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 008 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+25, 246835, 1492, 7812, 7811, 8388870, '0', 0, 2933.335, 960.275,  511.9407, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 009 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+30, 246837, 1492, 7812, 7811, 8388870, '0', 0, 2939.924, 952.1554, 512.0009, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 010 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+35, 246841, 1492, 7812, 7811, 8388870, '0', 0, 2933.194, 920.6995, 512.0448, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- Trap Door 011 (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+33, 246919, 1492, 7812, 7811, 8388870, '0', 0, 2933.333, 800, 500, 3.141593, 0, 0, -1, 0, 86400, 255, 1, 26124), -- The Naglfar (Area: Le Naglfar - Difficulty: Héroïque)
-- (@OGUID+34, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2945.721, 874.7188, 513.2433, 3.447554, 0, 0, -0.9883213, 0.1523844, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
-- (@OGUID+37, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2922.235, 870.1996, 517.2433, 6.280763, 0, 0, -0.001211166, 0.9999992, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+38, 243403, 1492, 7812, 7811, 8388870, '0', 0, 2959.033, 705.4774, 552.8295, 4.496197, 0, 0, -0.7792664, 0.6266929, 86400, 255, 1, 26124), -- Collision Wall (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+39, 246987, 1492, 7812, 7811, 8388870, '0', 0, 2942.028, 879.5232, 514.9936, 3.64565, 0, 0, -0.9684086, 0.2493688, 86400, 255, 1, 26124), -- Barnacled Cage (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+40, 246985, 1492, 7812, 7811, 8388870, '0', 0, 2942.772, 868.9544, 514.9936, 2.253714, 0, 0, 0.9030666, 0.4295005, 86400, 255, 1, 26124), -- Barnacled Cage (Area: Le Naglfar - Difficulty: Héroïque)
-- (@OGUID+41, 245609, 1492, 7812, 7811, 8388870, '0', 0, 2945.721, 874.7188, 517.2433, 3.447554, 0, 0, -0.9883213, 0.1523844, 86400, 255, 1, 26124), -- Invisible Door (Area: Le Naglfar - Difficulty: Héroïque) - !!! might be temporary spawn !!!
(@OGUID+42, 246125, 1492, 7812, 7811, 8388870, '0', 0, 2904.342, 724.7257, 515.0734, 0.3083335, 0, 0, 0.1535568, 0.9881398, 86400, 255, 1, 26124), -- Musty Crate (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+43, 249462, 1492, 7812, 7811, 8388870, '0', 0, 2933.641, 911.5938, 513.2538, 3.179568, -0.0893178, -0.3506889, -0.9306793, 0.05362431, 86400, 255, 1, 26124), -- Crate of Dragur Dust (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+44, 246989, 1492, 7812, 7811, 8388870, '0', 0, 2922.661, 876.207, 514.9936, 5.46361, 0, 0, -0.3984146, 0.9172055, 86400, 255, 1, 26124), -- Barnacled Cage (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+45, 246036, 1492, 7812, 7811, 8388870, '0', 0, 2934.025, 935.5243, 512.6249, 4.685884, 0, 0, -0.7164154, 0.697674, 86400, 255, 1, 26124), -- Waterlogged Cache of Ancient Relics (Area: Le Naglfar - Difficulty: Héroïque)
(@OGUID+46, 267034, 1492, 7812, 7811, 8388870, '0', 0, 2940.787, 915.6528, 513.0204, 1.615085, 0, 0, 0.7225904, 0.6912764, 86400, 255, 1, 26124); -- Portal to Stormheim (Area: Le Naglfar - Difficulty: Héroïque)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+47;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+9, 0, 0, 1, -0.00000004371139), -- The Maw of Souls
(@OGUID+13, 0, 0, 1, -0.00000004371139), -- Wall of Souls
(@OGUID+14, 0, 0, 1, -0.00000004371139), -- Wall of Souls
(@OGUID+16, 0, 0, 1, -0.00000004371139), -- Murky Fog
(@OGUID+17, 0, 0, 1, -0.00000004371139), -- Murky Fog
(@OGUID+21, 0, 0, 1, -0.00000004371139), -- Heavy Barnacled Door
(@OGUID+22, 0, 0, 1, -0.00000004371139), -- Heavy Barnacled Door
(@OGUID+23, 0, 0, 1, -0.00000004371139), -- Trap Door 007
(@OGUID+24, 0, 0, 1, -0.00000004371139), -- Heavy Barnacled Door
(@OGUID+25, 0, 0, 1, -0.00000004371139), -- Trap Door 009
(@OGUID+26, 0, 0, 1, -0.00000004371139), -- Trap Door 006
(@OGUID+27, 0, 0, 1, -0.00000004371139), -- Trap Door 005
(@OGUID+29, 0, 0, 1, -0.00000004371139), -- Trao Door 008
(@OGUID+30, 0, 0, 1, -0.00000004371139), -- Trap Door 010
(@OGUID+31, 0, 0, 1, -0.00000004371139), -- Trap Door 002
(@OGUID+32, 0, 0, 1, -0.00000004371139), -- Trap Door 003
(@OGUID+33, 0, 0, 0, 1), -- The Naglfar
(@OGUID+34, 0, 0, 1, -0.00000004371139), -- Trap Door 001
(@OGUID+35, 0, 0, 1, -0.00000004371139), -- Trap Door 011
(@OGUID+36, 0, 0, 1, -0.00000004371139), -- Trap Door 004
(@OGUID+37, 0, 0, 1, -0.00000004371139), -- Barnacled Cage
(@OGUID+39, 0, 0, 1, -0.00000004371139), -- Barnacled Cage
(@OGUID+40, 0, 0, 1, -0.00000004371139), -- Barnacled Cage
(@OGUID+41, 0, 0, 1, -0.00000004371139), -- Barnacled Cage
(@OGUID+44, 0, 0, 1, -0.00000004371139), -- Barnacled Cage
(@OGUID+47, 0, 0, 1, -0.00000004371139); -- Trap Door 001


UPDATE `spell_target_position` SET `PositionX`=2942.407, `PositionY`=879.7691, `VerifiedBuild`=26124 WHERE (`ID`=191558 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=205814 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=225219 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=191474 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=216016 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=132624 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=245992 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=192295 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=192293 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=193753 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=215792 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=121862 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=210064 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=241271 AND `EffectIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=49359 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (100362 /*100362 (Grasping Tentacle) - Ride Vehicle Hardcoded*/, 100361 /*100361 (Grasping Tentacle)*/, 107987 /*Hymdall*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(100362, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 100362 (Grasping Tentacle) - Ride Vehicle Hardcoded
(100361, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 100361 (Grasping Tentacle)
(107987, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Hymdall

UPDATE `creature_template_addon` SET `auras`='195219 42459' WHERE `entry`=98919; -- 98919 (Seacursed Swiftblade)
UPDATE `creature_template_addon` SET `auras`='145953' WHERE `entry`=97119; -- 97119 (Shroud Hound)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=99188; -- 99188 (Waterlogged Soul Guard)
UPDATE `creature_template_addon` SET `auras`='196024 196025' WHERE `entry`=97163; -- 97163 (Cursed Falke)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=116420; -- 116420 (Glowing Blue Gem)
UPDATE `creature_template_addon` SET `auras`='232268' WHERE `entry`=116408; -- 116408 (Glowing Red Gem)
UPDATE `creature_template_addon` SET `auras`='226952' WHERE `entry`=113900; -- 113900 (Liyana)
UPDATE `creature_template_addon` SET `auras`='210063' WHERE `entry`=96782; -- 96782 (Lucian Trias)
UPDATE `creature_template_addon` SET `bytes1`=3 WHERE `entry`=34330; -- 34330 (Jones)
UPDATE `creature_template_addon` SET `auras`='122729' WHERE `entry`=62821; -- 62821 (Mystic Birdhat)
UPDATE `creature_template_addon` SET `auras`='122729' WHERE `entry`=62822; -- 62822 (Cousin Slowhands)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (119437, 113270, 113268, 108628, 112543, 119396, 119436, 119438, 114946, 119226, 107772, 103092, 107994, 106415, 100635, 112545, 112392, 106263, 106262);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(119437, 0, 26124),
(113270, 0, 26124),
(113268, 0, 26124),
(108628, 0, 26124),
(112543, 0, 26124),
(119396, 0, 26124),
(119436, 0, 26124),
(119438, 0, 26124),
(114946, 0, 26124),
(119226, 0, 26124),
(107772, 0, 26124),
(103092, 0, 26124),
(107994, 0, 26124),
(106415, 0, 26124),
(100635, 0, 26124),
(112545, 0, 26124),
(112392, 0, 26124),
(106263, 0, 26124),
(106262, 0, 26124);



UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67923;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72036;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65778;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66619;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66495;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66346;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66348;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66680;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66681;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66618;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66345;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65043;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67211;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70528;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66121;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=985;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66852;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67556;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64200;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67179;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70529;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66184;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66183;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66181;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=30710;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66103;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65823;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64467;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66102;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65079;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66119;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27824;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66090;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25630;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66091;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69052;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72034;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=73429;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8902088, `CombatReach`=1.1, `VerifiedBuild`=26124 WHERE `DisplayID`=40994;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71252;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67773;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65680;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25800;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25801;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65679;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25204;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65681;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25799;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67230;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72035;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65678;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70110;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74255;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67161;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67938;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72055;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67937;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67361;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69151;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69153;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1595;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=38800;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25880;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=29834;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26321;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25604;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25608;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65164;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25609;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25878;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=29835;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69780;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36893;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36894;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=23672;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65163;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=47056;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26310;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69528;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25594;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65172;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65174;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70701;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27449;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36883;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66838;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=29735;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64782;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27958;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25602;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25621;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27962;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65453;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25620;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27782;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=17200;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=63051;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25610;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25635;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69575;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27999;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=60845;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65413;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75276;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25650;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=45425;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28433;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=38804;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25618;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75277;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75274;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75278;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68547;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28149;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28153;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=3058;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65106;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28150;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28154;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68004;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68021;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65256;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27956;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68022;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=30415;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68020;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=46696;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=30358;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=56737;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26300;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65228;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65345;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=73438;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=63488;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72235;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=46694;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68019;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25655;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65083;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65171;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26347;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26311;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=19744;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72952;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65173;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65243;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=48278;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65229;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65371;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70638;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=55989;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=15918;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27882;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=3585;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65227;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=54441;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27667;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=41930;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=6295;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=40674;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=29056;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=59729;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67162;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65239;

DELETE FROM `npc_vendor` WHERE (`entry`=92489 AND `item`=44234 AND `ExtendedCost`=5835 AND `type`=1) OR (`entry`=92489 AND `item`=44231 AND `ExtendedCost`=5836 AND `type`=1) OR (`entry`=92489 AND `item`=44690 AND `ExtendedCost`=5837 AND `type`=1) OR (`entry`=92489 AND `item`=44226 AND `ExtendedCost`=5838 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(92489, 8, 44234, 0, 5835, 1, 0, 0, 26124), -- Rênes de mammouth de voyage de la toundra
(92489, 7, 44231, 0, 5836, 1, 0, 0, 26124), -- Rênes de mammouth laineux
(92489, 6, 44690, 0, 5837, 1, 0, 0, 26124), -- Coursier du vent bleu cuirassé
(92489, 5, 44226, 0, 5838, 1, 0, 0, 26124); -- Rênes d'ours brun cuirassé

UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=143727 AND `ExtendedCost`=6183 AND `type`=1); -- Salut de champion
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140985 AND `ExtendedCost`=6102 AND `type`=1); -- Renfort d'armure supérieur de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140946 AND `ExtendedCost`=6101 AND `type`=1); -- Renfort d'armure de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140984 AND `ExtendedCost`=5952 AND `type`=1); -- Renfort d'armure inférieur de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139686 AND `ExtendedCost`=6125 AND `type`=1); -- Espauliers de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139687 AND `ExtendedCost`=6125 AND `type`=1); -- Ceinturon de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139682 AND `ExtendedCost`=6125 AND `type`=1); -- Bottes de guerre de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139681 AND `ExtendedCost`=6125 AND `type`=1); -- Pansière de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139685 AND `ExtendedCost`=6125 AND `type`=1); -- Cuissards de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139683 AND `ExtendedCost`=6125 AND `type`=1); -- Gantelets de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139688 AND `ExtendedCost`=6125 AND `type`=1); -- Garde-poignets de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139684 AND `ExtendedCost`=6125 AND `type`=1); -- Grand heaume de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140537 AND `ExtendedCost`=0 AND `type`=1); -- Rempart du Séjour céleste
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140557 AND `ExtendedCost`=0 AND `type`=1); -- Prestelame du Séjour céleste
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140559 AND `ExtendedCost`=0 AND `type`=1); -- Claymore du Séjour céleste
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=124124 AND `ExtendedCost`=6214 AND `type`=1); -- Sang de Sargeras
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=143727 AND `ExtendedCost`=6183 AND `type`=1); -- Salut de champion
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140985 AND `ExtendedCost`=6102 AND `type`=1); -- Renfort d'armure supérieur de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140946 AND `ExtendedCost`=6101 AND `type`=1); -- Renfort d'armure de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140984 AND `ExtendedCost`=5952 AND `type`=1); -- Renfort d'armure inférieur de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139686 AND `ExtendedCost`=6125 AND `type`=1); -- Espauliers de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139687 AND `ExtendedCost`=6125 AND `type`=1); -- Ceinturon de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139682 AND `ExtendedCost`=6125 AND `type`=1); -- Bottes de guerre de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139681 AND `ExtendedCost`=6125 AND `type`=1); -- Pansière de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139685 AND `ExtendedCost`=6125 AND `type`=1); -- Cuissards de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139683 AND `ExtendedCost`=6125 AND `type`=1); -- Gantelets de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139688 AND `ExtendedCost`=6125 AND `type`=1); -- Garde-poignets de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=139684 AND `ExtendedCost`=6125 AND `type`=1); -- Grand heaume de seigneur de bataille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140537 AND `ExtendedCost`=0 AND `type`=1); -- Rempart du Séjour céleste
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140557 AND `ExtendedCost`=0 AND `type`=1); -- Prestelame du Séjour céleste
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=140559 AND `ExtendedCost`=0 AND `type`=1); -- Claymore du Séjour céleste
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=112392 AND `item`=124124 AND `ExtendedCost`=6214 AND `type`=1); -- Sang de Sargeras
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1); -- Bois simple
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=60335 AND `ExtendedCost`=0 AND `type`=1); -- Sac en peau épaisse
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1); -- Eau de source
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35953 AND `ExtendedCost`=0 AND `type`=1); -- Caribou arrosé d'hydromel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35947 AND `ExtendedCost`=0 AND `type`=1); -- Chapegivre étincelant
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35948 AND `ExtendedCost`=0 AND `type`=1); -- Prune des neiges savoureuse
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35951 AND `ExtendedCost`=0 AND `type`=1); -- Saumon empereur poché
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35952 AND `ExtendedCost`=0 AND `type`=1); -- Vieux salé
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35950 AND `ExtendedCost`=0 AND `type`=1); -- Pain de patates douces
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33454 AND `ExtendedCost`=0 AND `type`=1); -- Venaison salée
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33452 AND `ExtendedCost`=0 AND `type`=1); -- Lichen épicé au miel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35949 AND `ExtendedCost`=0 AND `type`=1); -- Baies de la toundra
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33451 AND `ExtendedCost`=0 AND `type`=1); -- Filet de nageglace
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33443 AND `ExtendedCost`=0 AND `type`=1); -- Fromage de chèvre aigre
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33449 AND `ExtendedCost`=0 AND `type`=1); -- Galette croustillante
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33445 AND `ExtendedCost`=0 AND `type`=1); -- Thé à la menthe au miel
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=33444 AND `ExtendedCost`=0 AND `type`=1); -- Petit-lait de phoque aigre
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=35954 AND `ExtendedCost`=0 AND `type`=1); -- Lait de chèvre sucré
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=44574 AND `ExtendedCost`=0 AND `type`=1); -- Outre d'eau-de-feu de Mulgore
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=44573 AND `ExtendedCost`=0 AND `type`=1); -- Tasse de philtre au venin de grenouille
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=44575 AND `ExtendedCost`=0 AND `type`=1); -- Flacon de cidre de cactus amer
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=44571 AND `ExtendedCost`=0 AND `type`=1); -- Bouteille de porto de Lune-d'Argent
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32642 AND `item`=44570 AND `ExtendedCost`=0 AND `type`=1); -- Verre de vin des Chants éternels
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=4565 AND `ExtendedCost`=0 AND `type`=1); -- Dague simple
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1); -- Poussière évanescente
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1); -- Coffret de calligraphie de virtuose
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1); -- Trousse de joaillier
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1); -- Parchemin léger
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=6532 AND `ExtendedCost`=0 AND `type`=1); -- Verroterie
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1); -- Fiole de cristal
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=38426 AND `ExtendedCost`=0 AND `type`=1); -- Fil d'éternium
UPDATE `npc_vendor` SET `VerifiedBuild`=26124 WHERE (`entry`=32641 AND `item`=14341 AND `ExtendedCost`=0 AND `type`=1); -- Fil runique
UPDATE `npc_vendor` SET `slot`=23, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=63251 AND `ExtendedCost`=0 AND `type`=1); -- Bière magistrale de Mei
UPDATE `npc_vendor` SET `slot`=22, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=25532 AND `ExtendedCost`=0 AND `type`=1); -- Coursier du vent jaune rapide
UPDATE `npc_vendor` SET `slot`=21, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=25477 AND `ExtendedCost`=0 AND `type`=1); -- Coursier du vent rouge rapide
UPDATE `npc_vendor` SET `slot`=20, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=25533 AND `ExtendedCost`=0 AND `type`=1); -- Coursier du vent violet rapide
UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=25531 AND `ExtendedCost`=0 AND `type`=1); -- Coursier du vent vert rapide
UPDATE `npc_vendor` SET `slot`=18, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=25476 AND `ExtendedCost`=0 AND `type`=1); -- Coursier du vent vert
UPDATE `npc_vendor` SET `slot`=17, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=25475 AND `ExtendedCost`=0 AND `type`=1); -- Coursier du vent bleu
UPDATE `npc_vendor` SET `slot`=16, `VerifiedBuild`=26124 WHERE (`entry`=92489 AND `item`=25474 AND `ExtendedCost`=0 AND `type`=1); -- Coursier du vent fauve

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=113270 AND `ID`=1) OR (`CreatureID`=106843 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(113270, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- Vierge guerrière
(106843, 1, 13753, 0, 0, 0, 0, 0, 0, 0, 0); -- Prince Farondis

UPDATE `creature_equip_template` SET `ItemID1`=122078, `ItemID2`=126883 WHERE (`CreatureID`=110437 AND `ID`=1); -- Haklang Ulfsson

DELETE FROM `gossip_menu` WHERE (`MenuID`=20375 AND `TextId`=30468) OR (`MenuID`=20344 AND `TextId`=30432) OR (`MenuID`=20007 AND `TextId`=29823) OR (`MenuID`=18747 AND `TextId`=27251) OR (`MenuID`=18383 AND `TextId`=14127);
INSERT INTO `gossip_menu` (`MenuID`, `TextId`) VALUES
(20375, 30468), -- 112392 (Quartermaster Durnolf)
(20344, 30432), -- 110437 (Haklang Ulfsson)
(20007, 29823), -- Capitaine Hjalmar Stahlstrom
(18747, 27251), -- 97389 (Eye of Odyn)
(18383, 14127); -- 92489 (Mei Francis)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=20007 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(20007, 1, 28, 'The Valarjar await.', 0);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=20375 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=20344 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=20344 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=20375 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE (`MenuId`=18383 AND `OptionIndex`=0);





UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=37750784 WHERE `entry`=100362; -- Grasping Tentacle
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=4496 WHERE `entry`=100361; -- Grasping Tentacle
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.3571429 WHERE `entry`=98761; -- Soul Fragment
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=114712; -- Runecarver Slave
UPDATE `creature_template` SET `unit_flags`=33587200, `unit_flags3`=1 WHERE `entry`=97163; -- Cursed Falke
UPDATE `creature_template` SET `gossip_menu_id`=20007 WHERE `entry`=106459; -- Capitaine Hjalmar Stahlstrom
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=103810; -- Renfield
UPDATE `creature_template` SET `minlevel`=100, `maxlevel`=110, `faction`=1665, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=107987; -- Hymdall
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113 WHERE `entry`=114558; -- Greater Sparring Partner
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=96679; -- Aerylia
UPDATE `creature_template` SET `gossip_menu_id`=20375 WHERE `entry`=112392; -- Quartermaster Durnolf
UPDATE `creature_template` SET `npcflag`=83 WHERE `entry`=92464; -- Kuhuine Tenderstride
UPDATE `creature_template` SET `npcflag`=17179869184, `unit_flags3`=32 WHERE `entry`=97491; -- Prêtresse de la lune Nici
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `gossip_menu_id`=18383 WHERE `entry`=92489; -- Mei Francis
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=101, `maxlevel`=101 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=102, `maxlevel`=102 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `HoverHeight`=2.4 WHERE `entry`=93819; -- Val’kyr d’Odyn

SET @GROUP_ID := 0;
SET @ID := 0;

DELETE FROM `creature_text` WHERE CreatureID IN (96754, 96756, 96759, 97043, 97097, 97200, 99188, 99307, 99801, 101013, 102108, 106843);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(96754, @GROUP_ID+0, @ID+0, 'The spirits grow hungry from the scent of blood.', 14, 0, 100, 11, 0, 54387, 0, 'Harbaron to Player'),
(96754, @GROUP_ID+1, @ID+0, 'New passengers... New souls. I will guide you to the depths of Helheim for a small price: your flesh and blood.', 14, 0, 100, 0, 0, 54373, 0, 'Harbaron to Player'),
(96754, @GROUP_ID+2, @ID+0, 'The flesh burdens the soul. A nuisance that must be flayed from your bones!', 14, 0, 100, 0, 0, 54384, 0, 'Harbaron to Player'),
(96754, @GROUP_ID+3, @ID+0, '|TInterface\\Icons\\Ability_Warlock_ImprovedSoulLeech:20|t %s begins to |cFFFF0000|Hspell:194325|h[Fragment]|h|r $n.', 41, 0, 100, 0, 0, 54384, 0, 'Harbaron to Player'),
(96754, @GROUP_ID+4, @ID+0, 'Arise, servitor! Claim our blood debt!', 14, 0, 100, 0, 0, 54388, 0, 'Harbaron'),
(96754, @GROUP_ID+5, @ID+0, 'Life... death... I am but one ripple in the eternal ebb and flow...', 14, 0, 100, 0, 0, 54376, 0, 'Harbaron to Player'),
(96756, @GROUP_ID+0, @ID+0, 'Your souls will drift for eternity in the tides of the underworld!', 14, 0, 100, 0, 0, 54404, 0, 'Ymiron, the Fallen King to Player'),
(96756, @GROUP_ID+1, @ID+0, 'Another drop in the sea of souls!', 14, 0, 100, 66, 0, 54367, 0, 'Ymiron, the Fallen King to Player'),
(96756, @GROUP_ID+2, @ID+0, 'Mortals... I fell to your wretched kind once before. It WILL NOT happen again!', 14, 0, 100, 0, 0, 54403, 0, 'Ymiron, the Fallen King to Player'),
(96756, @GROUP_ID+3, @ID+0, 'Know the bitter chill of death as I have!', 14, 0, 100, 0, 0, 54362, 0, 'Ymiron, the Fallen King'),
(96756, @GROUP_ID+4, @ID+0, 'The shadows of the underworld bend to me!', 14, 0, 100, 0, 0, 54357, 0, 'Ymiron, the Fallen King'),
(96756, @GROUP_ID+5, @ID+0, 'FLEE, COWARDS!', 14, 0, 100, 0, 0, 54360, 0, 'Ymiron, the Fallen King'),
(96756, @GROUP_ID+6, @ID+0, 'Not... again... HARBARON! CAST THEIR SOULS INTO THE TIDES!', 14, 0, 100, 0, 0, 54360, 0, 'Ymiron, the Fallen King to Player'),
(96759, @GROUP_ID+0, @ID+0, 'You ALL will regret trespassing in my realm.', 14, 0, 100, 0, 0, 54395, 0, 'Helya to Player'),
(96759, @GROUP_ID+1, @ID+0, 'You have come far enough. Time to die.', 14, 0, 100, 0, 0, 54180, 0, 'Helya to Player'),
(96759, @GROUP_ID+2, @ID+0, 'You will pay for that.', 14, 0, 100, 0, 0, 54244, 0, 'Helya to Helya'),
(96759, @GROUP_ID+3, @ID+0, 'I am losing my patience.', 14, 0, 100, 0, 0, 54245, 0, 'Helya to Helya'),
(96759, @GROUP_ID+4, @ID+0, 'Your fate rains down!', 14, 0, 100, 0, 0, 54392, 0, 'Helya'),
(96759, @GROUP_ID+5, @ID+0, 'Embrace your fate, fools!', 14, 0, 100, 0, 0, 54391, 0, 'Helya to Helya'),
(96759, @GROUP_ID+6, @ID+0, 'No! This is not possible!', 14, 0, 100, 0, 0, 54389, 0, 'Helya to Helya'),
(96759, @GROUP_ID+7, @ID+0, 'What manner of creatures ARE you??', 14, 0, 100, 0, 0, 54390, 0, 'Helya to Helya'),
(96759, @GROUP_ID+8, @ID+0, '|TInterface\\Icons\\Spell_Shadow_Possession:20|t %s begins to cast |cFFFF0000|Hspell:227233|h[Corrupted Bellow]|h|r. Look out!', 41, 0, 100, 0, 0, 54400, 0, 'Helya'),
(96759, @GROUP_ID+9, @ID+0, 'I will drown you all like rats.', 14, 0, 100, 0, 0, 54400, 0, 'Helya'),
(96759, @GROUP_ID+10, @ID+0, 'Do you think you have won? You have merely survived the storm... The seas are unstoppable.', 14, 0, 100, 0, 0, 54396, 0, 'Helya'),
(97043, @GROUP_ID+0, @ID+0, 'Want to live? Kill these fools.', 14, 0, 100, 0, 0, 0, 0, 'Seacursed Slaver'),
(97043, @GROUP_ID+1, @ID+0, 'Fool. Our curse will be your undoing...', 14, 0, 100, 11, 0, 0, 0, 'Seacursed Slaver to Player'),
(97043, @GROUP_ID+2, @ID+0, 'Fight them. Earn your freedom!', 14, 0, 100, 0, 0, 0, 0, 'Seacursed Slaver'),
(97097, @GROUP_ID+0, @ID+0, 'Harbaron won''t have your kind around here, mortal.', 14, 0, 100, 0, 0, 0, 0, 'Helarjar Champion to Player'),
(97200, @GROUP_ID+0, @ID+0, 'I will sharpen my blade with your bones!', 14, 0, 100, 0, 0, 0, 0, 'Seacursed Soulkeeper to Player'),
(97200, @GROUP_ID+1, @ID+0, 'Vrykul dogs, get over here and fight or I''ll kill you myself!', 14, 0, 100, 0, 0, 0, 0, 'Seacursed Soulkeeper'),
(97200, @GROUP_ID+2, @ID+0, 'I will flay you!', 14, 0, 100, 0, 0, 0, 0, 'Seacursed Soulkeeper to Player'),
(99188, @GROUP_ID+0, @ID+0, 'What are you doing out of your cage, $c?', 14, 0, 100, 0, 0, 0, 0, 'Waterlogged Soul Guard to Player'),
(99307, @GROUP_ID+0, @ID+0, 'Intruders on the Naglfar! Give no quarter to these scallywags!', 14, 0, 100, 0, 0, 57461, 0, 'Skjal to Player'),
(99307, @GROUP_ID+1, @ID+0, 'All hands on deck!', 14, 0, 100, 0, 0, 57456, 0, 'Skjal to Player'),
(99307, @GROUP_ID+2, @ID+0, 'Belay these bilge rats!', 14, 0, 100, 0, 0, 57462, 0, 'Skjal'),
(99307, @GROUP_ID+3, @ID+0, 'Nothing sweeter... than to die at sea...', 14, 0, 100, 0, 0, 57459, 0, 'Skjal to Player'),
(99801, @GROUP_ID+0, @ID+0, '|TInterface\\Icons\\inv_misc_monsterhorn_03.blp:20|t A %s emerges!', 41, 0, 100, 0, 0, 54391, 0, 'Destructor Tentacle to Destructor Tentacle'),
(101013, @GROUP_ID+0, @ID+0, 'Runes curse you. I will send you to the bottom of the sea where you belong!', 14, 0, 100, 0, 0, 0, 0, 'Captured Runecarver to Seacursed Slaver'),
(102108, @GROUP_ID+0, @ID+0, 'You may take my soul, cursed, but you will never take my will.', 14, 0, 100, 0, 0, 0, 0, 'Captured Shieldmaiden to Seacursed Slaver'),
(106843, @GROUP_ID+0, @ID+0, 'It has been ages since I have seen the Tidestone whole, but there it stands.', 12, 0, 100, 0, 0, 63265, 0, 'Prince Farondis to Player'),
(106843, @GROUP_ID+1, @ID+0, 'I and my people owe you a debt of gratitude that we can never repay.', 12, 0, 100, 0, 0, 63266, 0, 'Prince Farondis to Player'),
(106843, @GROUP_ID+2, @ID+0, 'Please return to Azsuna as soon as you can. There is much yet left to do, $n.', 12, 0, 100, 0, 0, 63264, 0, 'Prince Farondis to Player');

INSERT IGNORE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(107772, 234590, 0, 0),
(113901, 234595, 0, 0),
(116408, 231849, 0, 0),
(116419, 231849, 0, 0),
(116420, 231849, 0, 0),
(92438, 103583, 0, 0),
(112947, 234593, 0, 0),
(68232, 75648, 0, 0),
(68239, 75648, 0, 0),
(68238, 75648, 0, 0),
(119437, 237066, 0, 0),
(119436, 237066, 0, 0),
(119396, 237066, 0, 0),
(119438, 237066, 0, 0),
(106359, 210857, 0, 0);


UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102306; -- Swirling Pool
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98363; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99800; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100362; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100361; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100188; -- Piercing Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99801; -- Destructor Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97099; -- Swirling Pool
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99803; -- Destructor Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100354; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100353; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101502; -- Helya's Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100360; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100359; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96759; -- Helya
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101814; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101504; -- Grasping Tentacle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100733; -- Charge
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=114289; -- Skeletal Sorcerer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=114288; -- Skeletal Warrior
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99033; -- Helarjar Mistcaller
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99307; -- Skjal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98761; -- Soul Fragment
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=62982; -- Mindbender
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98693; -- Shackled Servitor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98989; -- Cosmic Scythe
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100839; -- Cosmic Scythe
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98973; -- Skeletal Warrior
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97097; -- Helarjar Champion
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96754; -- Harbaron
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111833; -- Thal'kiel
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102830; -- Deceased Sorcerer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102769; -- Decrepit Runecarver
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102742; -- Fallen Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102327; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102326; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97185; -- The Grimewalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102325; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98291; -- Seacursed Rower
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111221; -- Xal'atath
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99188; -- Waterlogged Soul Guard
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98919; -- Seacursed Swiftblade
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97365; -- Seacursed Mistmender
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97182; -- Night Watch Mariner
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97119; -- Shroud Hound
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103115; -- Helheim
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110609; -- Throwing Grain
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110605; -- Throwing Veggies
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110608; -- Throwing Crabs
UPDATE `creature_template` SET `HealthScalingExpansion`=4, `VerifiedBuild`=26124 WHERE `entry`=88443; -- Firefury Totem
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=76168; -- Ravager
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111374; -- Xal'atath
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96756; -- Ymiron, the Fallen King
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=114712; -- Runecarver Slave
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102894; -- Runecarver Slave
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102375; -- Runecarver Slave
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101013; -- Captured Runecarver
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97200; -- Seacursed Soulkeeper
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102896; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102104; -- Enslaved Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102108; -- Captured Shieldmaiden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97208; -- Spear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97043; -- Esclavagiste maudit par les flots
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97163; -- Cursed Falke
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112577; -- Weaponmaster Asvard
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107494; -- Maîtresse de l’arène val’kyr
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106415; -- Valarjar forge-foudre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97389; -- Eye of Odyn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111741; -- Fjornson Stonecarver
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103810; -- Renfield
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113300; -- Image de Thorim
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113270; -- Vierge guerrière
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96401; -- Aspirant valarjar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=114558; -- Greater Sparring Partner
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112420; -- Ymirjar Lord's Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112353; -- Battlegear of Might Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112418; -- Hellscream's Conquest Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112416; -- Wrynn's Conquest Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112356; -- Battlegear of Wrath Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112413; -- Valorous Siegebreaker Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112357; -- Conqueror's Battlegear Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112408; -- Heroes' Dreadnaught Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112361; -- Warbringer Armor Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112390; -- Destroyer Armor Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112400; -- Onslaught Set
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110437; -- Haklang Ulfsson
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96679; -- Aerylia
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=116609; -- Battlelord's Armor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112392; -- Quartermaster Durnolf
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96572; -- Valarjar forge-foudre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113268; -- Valarjar forge-foudre
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=43084; -- Forest Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107477; -- N.U.T.Z.
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113785; -- Hugh Mann
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=85290; -- Vaultkeeper Sarniv
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96789; -- Caliel Brightwillow
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97012; -- Abra Cadabra
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96999; -- Susana Averoy
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96980; -- Matilda Brightlink
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96979; -- Bragund Brightlink
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97331; -- Icks
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97004; -- "Red" Jack Findle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96978; -- Rafael Langrom
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96977; -- Valerie Langrom
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106930; -- Lieutenant Surtees
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96944; -- Muran Fairden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96949; -- Farseer Lopaa
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96947; -- Matron Nessa
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96987; -- Norvin Alderman
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96948; -- Pathstalker Gilen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97332; -- Richard Hatstock
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96950; -- Summoner Mazek
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96976; -- Cloth Merchant
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96975; -- Paldesse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97342; -- Salan Sunthread
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96945; -- Ranger Bodine
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93534; -- Katherine Lee
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96951; -- Naseev
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93545; -- Bradford Duncan
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96946; -- Varlean
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96792; -- Inzi Charmlight
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108792; -- Jenny McCree
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96793; -- Stefen Cotter
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119226; -- Danath Trollbane
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96791; -- Marcella Bloom
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106720; -- Svergan Stormcloak
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107987; -- Hymdall
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107994; -- Einar the Runecaster
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106459; -- Capitaine Hjalmar Stahlstrom
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100635; -- Skyseer Ghrent
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107984; -- Ragnvald Drake-Né
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107985; -- Finna Bjornsdottir
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96469; -- Odyn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112663; -- Danica the Reclaimer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103098; -- Conjured Rabbit
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=29238; -- Hantise du Fléau
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108327; -- Undulating Boneslime
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109304; -- Khardon Timberdawn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108304; -- Guviena Bladesong
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106359; -- Runed Ladder
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93533; -- Theresa Wolf
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97718; -- Vanessa Sellers
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93531; -- Enchanter Nalthanis
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93530; -- Ildine Sorrowspear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=79861; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103326; -- Mana Saber
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=68267; -- Chaton de braise
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92464; -- Kuhuine Tenderstride
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92459; -- Dorothy Egan
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=50058; -- Terrorpene
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=88869; -- Prince Farondis
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119438; -- BAD HANDWRITING
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119396; -- RETURN TO SENDER
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93544; -- Jang Quillpaw
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93532; -- Jessica Sellers
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92460; -- Edward Egan
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99867; -- Warpweaver Tuviss
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92195; -- Professor Pallin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119436; -- NO ADDRESS
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119437; -- NOT ENOUGH STAMPS
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=104230; -- Postier-lémentaire
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96838; -- Kitz Proudbreeze
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96839; -- The Magnificent Merleaux
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113782; -- Hannis Shoalwalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96790; -- Isirami Fairwind
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96990; -- Applebough
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96832; -- Crafticus Mindbender
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103092; -- Le grand Akazamzarak
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96833; -- Grezla the Hag
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103119; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103120; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97213; -- Windle Sparkshine
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=35845; -- Dave's Industrial Light and Magic Bunny (Small)(Sessile)
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103118; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=68238; -- Carousel Rocket
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96968; -- Aquanos
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96967; -- Shandy Glossgleam
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96483; -- Jepetto Joybuzz
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112716; -- Rasil Fireborne
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112720; -- Jemma Wilson
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=68232; -- Carousel Gryphon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=114730; -- Caeli
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97685; -- Gnolie
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108323; -- Gilnean Guard
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97490; -- Halga Char-d’acier
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103116; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111243; -- Archmage Lan'dalock
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=95844; -- Marcia Chase
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97002; -- Ninsianna
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97339; -- Cho Ironpalm
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97011; -- Valaden Silverblade
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97007; -- Kerta the Bold
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113779; -- Sister Might
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97009; -- Jawknee
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97513; -- Juwanamana
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=36871; -- Chiot du magma
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=17447; -- The Kurken
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112717; -- Ginger Blockgear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=16085; -- Colportecœur
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=17252; -- Gangregarde
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32640; -- Traveler's Tundra Mammoth
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97491; -- Prêtresse de la lune Nici
UPDATE `creature_template` SET `RequiredExpansion`=0, `type_flags`=1, `VerifiedBuild`=26124 WHERE `entry`=111463; -- Bulvinkel
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32752; -- Tabitha
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97489; -- Garl Mornegrise
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108853; -- Great Eagle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=46910; -- Core Hound
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106848; -- Abomination
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=5494; -- Catherine Leland
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=78116; -- Water Elemental
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109751; -- Lightsworn Anchorite
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93819; -- Val’kyr d’Odyn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=114946; -- Muninn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97507; -- Disidra Foudregloire
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=14020; -- Chromaggus


UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=103326 AND `Idx`=2); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=103326 AND `Idx`=1); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=103326 AND `Idx`=0); -- Mana Saber
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=17447 AND `Idx`=0); -- The Kurken
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=46910 AND `Idx`=0); -- Core Hound


UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=267034; -- Portal to Stormheim
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246036; -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=265477; -- Murky Fog
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=265476; -- Murky Fog
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246948; -- Wall of Souls
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246947; -- Wall of Souls
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246890; -- Heavy Barnacled Door
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246889; -- Heavy Barnacled Door
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246888; -- Heavy Barnacled Door
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246435; -- Wall of Souls
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245609; -- Invisible Door
UPDATE `gameobject_template` SET `type`=50, `displayId`=7763, `IconName`='openhand', `Data0`=43, `Data1`=68489, `Data6`=120, `Data12`=105, `Data15`=1, `Data17`=1628, `Data18`=5, `Data19`=1, `VerifiedBuild`=26124 WHERE `entry`=253993; -- Crusty Kvaldir Chest
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246763; -- The Maw of Souls
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246839; -- Trap Door 005
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246838; -- Trap Door 006
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246837; -- Trap Door 010
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246835; -- Trap Door 009
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246836; -- Trao Door 008
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246834; -- Trap Door 007
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246987; -- Barnacled Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246986; -- Barnacled Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246985; -- Barnacled Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246844; -- Trap Door 004
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246840; -- Trap Door 001
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246989; -- Barnacled Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246988; -- Barnacled Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246843; -- Trap Door 003
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246842; -- Trap Door 002
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246841; -- Trap Door 011
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=224697; -- Fresh Carcass
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251963; -- 7VR_VRYKUL_RITUALROCKS02 [scale x3]
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251960; -- The Raven's Eye Tablet
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246125; -- Musty Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=243403; -- Collision Wall
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246919; -- The Naglfar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=253001; -- Rune-etched Archway
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=247041; -- Echoing Horn of the Damned
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245066; -- Kvaldir Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245062; -- Kvaldir Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245067; -- Kvaldir Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245063; -- Kvaldir Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245064; -- Kvaldir Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245065; -- Kvaldir Cage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259095; -- [DNT] Command Table Collision Cylinder
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250878; -- Training Troops
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=267923; -- The Legend of Odyn
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=248980; -- The Legend of Odyn
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250879; -- Training Troops
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=252801; -- Artifact Research Notes
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=248979; -- Saga of the Valarjar
UPDATE `gameobject_template` SET `name`='Grand Challenger''s Bounty', `VerifiedBuild`=26124 WHERE `entry`=252064; -- Grand Challenger's Bounty
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245726; -- Forge of Odyn
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250880; -- Training Troops
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=252887; -- Blessing of Mjolnir
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=248981; -- The Favored of Odyn
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=267922; -- The Favored of Odyn
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244516; -- Valhallas Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=191605; -- Portable Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=252016; -- Requisitioned Armaments
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246280; -- Cylinder Collision (2 Scale)
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250310; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250261; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250302; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250259; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250258; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268052; -- Exile of the High Elves
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250476; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250454; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250301; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250453; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=247337; -- Collision Wall
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242128; -- Dalaran Merchant's Bank
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242127; -- Dalaran Merchant's Bank
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=249362; -- Lever
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250455; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250456; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268046; -- Arathor and the Troll Wars
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242130; -- Langrom's Leather & Links
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242129; -- The Militant Mystic
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246003; -- Portal to Exodar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242132; -- Glorious Goods
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259285; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242131; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259351; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259834; -- Fireplace
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245997; -- Portal to Darnassus
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242220; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259284; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259390; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245998; -- Portal to Ironforge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250509; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259387; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242126; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259380; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250510; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250511; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250522; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250435; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250523; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250514; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268065; -- Sunwell - The Fall of Quel'Thalas
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250513; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250521; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250512; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246002; -- Portal to Stormwind
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242125; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250525; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250524; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250528; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250526; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250527; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259382; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259383; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250501; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250503; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250515; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250502; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250516; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250517; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268061; -- Sargeras and the Betrayal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250217; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242037; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=280797; -- Mail Tube
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259384; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259381; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259288; -- Couch
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=247858; -- Mail Tube
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241959; -- The Threads of Fate
UPDATE `gameobject_template` SET `type`=3, `displayId`=8128, `Data3`=1, `Data30`=71643, `VerifiedBuild`=26124 WHERE `entry`=268083; -- The Seven Kingdoms
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259297; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259445; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=7706, `size`=0.75, `Data3`=1, `Data30`=71637, `VerifiedBuild`=26124 WHERE `entry`=268077; -- The Last Guardian
UPDATE `gameobject_template` SET `type`=3, `displayId`=1128, `size`=0.75, `Data3`=1, `Data30`=71636, `VerifiedBuild`=26124 WHERE `entry`=268076; -- The Kaldorei and the Well of Eternity
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259458; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259457; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259456; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259455; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259454; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259453; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259452; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259451; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259450; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259449; -- Bench
UPDATE `gameobject_template` SET `name`='Couch', `VerifiedBuild`=26124 WHERE `entry`=259448; -- Couch
UPDATE `gameobject_template` SET `name`='Couch', `VerifiedBuild`=26124 WHERE `entry`=259447; -- Couch
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259446; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259444; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259443; -- Bench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259442; -- Chair
UPDATE `gameobject_template` SET `name`='Couch', `VerifiedBuild`=26124 WHERE `entry`=259441; -- Couch
UPDATE `gameobject_template` SET `name`='Couch', `VerifiedBuild`=26124 WHERE `entry`=259440; -- Couch
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259439; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259302; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259301; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259300; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259299; -- Chair
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=259298; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242366; -- Hay Bale
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250218; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=249729; -- The Masterful Miller's Manual
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242216; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=249730; -- Runes of the Aqir
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259334; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=249732; -- Verdigris or Malachite? Selecting the Proper Green Ink
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250216; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259262; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259286; -- Couch
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259287; -- Couch
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259341; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242042; -- Shard up for some enchanting materials? Come inside!
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242041; -- Simply Enchanting
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=249731; -- Scrolls, Scrolls, Scrolls
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250506; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250219; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244651; -- Steamy Romance Novel
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242215; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241951; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242040; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242039; -- The Scribe's Sacellum
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246013; -- Portal to Wyrmrest Temple
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246008; -- Portal to Dalaran Crater
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246708; -- WARNING: Drop
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246009; -- Portal to Karazhan
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250505; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250507; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250508; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250504; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=278574; -- Hero's Call Board
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250518; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250520; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250519; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241968; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=247015; -- Luggage
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241952; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=248079; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=247013; -- Stairs
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=247019; -- Sack
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=247018; -- Tip Bucket
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241965; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241972; -- The Wonderworks
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241961; -- A Hero's Welcome
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=200296; -- Washing Tub
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241943; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259311; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259317; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=200297; -- Shandy's Clothesline
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259312; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259310; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259309; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=258327; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250438; -- Photonic Playground
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246258; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246262; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246257; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=269037; -- Loose Pebble
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246011; -- Portal to Shattrath
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246005; -- Portal to Caverns of Time
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259268; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241960; -- Curiosities & Moore
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250464; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259296; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250457; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241966; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241953; -- The Arsenal Absolute


UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246036 AND `Idx`=5); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246036 AND `Idx`=4); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246036 AND `Idx`=3); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246036 AND `Idx`=2); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246036 AND `Idx`=1); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246036 AND `Idx`=0); -- Waterlogged Cache of Ancient Relics
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246125 AND `Idx`=0); -- Musty Crate
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=249729 AND `Idx`=0); -- The Masterful Miller's Manual


UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=30432; -- 30432
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=29823; -- 29823
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=27251; -- 27251
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=30468; -- 30468
UPDATE `npc_text` SET `VerifiedBuild`=26124 WHERE `ID`=14127; -- 14127

UPDATE creature_template SET inhabitType = 4 WHERE entry IN (96759, 97163);
DELETE FROM creature WHERE id = 111221;

UPDATE instance_template SET scriptname = "instance_maw_of_souls" WHERE map = 1492;
UPDATE creature_template SET scriptname = "boss_harbaron_maw" WHERE entry = ;
UPDATE creature_template SET scriptname = "npc_shackled_servitor" WHERE entry = 98693:

