SET @CGUID := 6005871;
SET @OGUID := 6002937;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 111166, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, 1, 309.00347900390625, 3112.57470703125, 226.8973388671875, 5.497786998748779296, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Resolute Courtesan (Area: The Nighthold - Difficulty: Normal) CreateObject1 (Auras: 190299 - Warden Salute)
(@CGUID+1, 111170, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, 1, 292.92535400390625, 3146.1171875, 226.8973388671875, 3.926990747451782226, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Astral Farseer (Area: The Nighthold - Difficulty: Normal) CreateObject1 (Auras: 225958 - Spellcaster, 221485 - Spellcasting, 221529 - Commune with the Stars)
(@CGUID+2, 106643, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, 0, 282.317718505859375, 3135.51123046875, 236.7103424072265625, 5.497786998748779296, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Elisande (Area: The Nighthold - Difficulty: Normal) CreateObject1 (Auras: 208861 - Etched in Time)
(@CGUID+3, 111151, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, 0, 303.52777099609375, 3156.721435546875, 226.935760498046875, 3.938802957534790039, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Midnight Siphoner (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@CGUID+4, 111151, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, 0, 261.098968505859375, 3114.290771484375, 226.935760498046875, 0.773556172847747802, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Midnight Siphoner (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@CGUID+5, 111166, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, 1, 305.305572509765625, 3108.876708984375, 226.8973388671875, 5.497786998748779296, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 61967), -- Resolute Courtesan (Area: The Nighthold - Difficulty: Normal) CreateObject1 (Auras: 190299 - Warden Salute)
(@CGUID+6, 111170, 1530, 8025, 8025, '14,15,16,17', 0, 0, 0, 1, 271.711822509765625, 3124.904541015625, 226.8973236083984375, 0.78539818525314331, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 61967); -- Astral Farseer (Area: The Nighthold - Difficulty: Normal) CreateObject1 (Auras: 225958 - Spellcaster, 221485 - Spellcasting, 221529 - Commune with the Stars)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, '190299'), -- Resolute Courtesan - 190299 - Warden Salute
(@CGUID+1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Astral Farseer - 225958 - Spellcaster, 221485 - Spellcasting, 221529 - Commune with the Stars
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Midnight Siphoner
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Midnight Siphoner
(@CGUID+5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, '190299'), -- Resolute Courtesan - 190299 - Warden Salute
(@CGUID+6, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- Astral Farseer - 225958 - Spellcaster, 221485 - Spellcasting, 221529 - Commune with the Stars

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 255927, 1530, 8025, 8025, '14,15,16,17', 0, 0, 365.853240966796875, 3052.300048828125, 216.210906982421875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 604800, 255, 1, 61967), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002 (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+1, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 339.12152099609375, 3079.109375, 289.4146728515625, 5.488924026489257812, 0, 0, -0.38677406311035156, 0.922174513339996337, 604800, 255, 1, 61967), -- Nightborne Teleporter (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+2, 251330, 1530, 8025, 8025, '14,15,16,17', 0, 0, 282.5057373046875, 3135.57470703125, 226.8587646484375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 604800, 255, 1, 61967), -- Doodad_7sr_suramar_nightwellfx004 (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+3, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 314.076385498046875, 3104.135498046875, 146.8001708984375, 5.505530357360839843, 0, 0, -0.37910366058349609, 0.925354242324829101, 604800, 255, 1, 61967), -- Nightborne Teleporter (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+4, 258843, 1530, 8025, 8025, '14,15,16,17', 0, 0, 333.97674560546875, 3186.937255859375, 227.00927734375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 604800, 255, 1, 61967), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003 (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+5, 266835, 1530, 8025, 8025, '14,15,16,17', 0, 0, 250.9965362548828125, 3166.856689453125, 146.8096160888671875, 5.488924026489257812, 0, 0, -0.38677406311035156, 0.922174513339996337, 604800, 255, 1, 61967), -- Nightborne Teleporter (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+6, 252317, 1530, 8025, 8025, '14,15,16,17', 0, 0, 282.481597900390625, 3135.583984375, 145.195556640625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 604800, 255, 1, 61967), -- Doodad_7sr_suramar_nightwellfx003 (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+7, 255926, 1530, 8025, 8025, '14,15,16,17', 0, 0, 386.622283935546875, 3031.554931640625, 171.2769775390625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 604800, 255, 1, 61967), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER001 (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+8, 255925, 1530, 8025, 8025, '14,15,16,17', 0, 0, 199.175201416015625, 3218.97802734375, 216.210906982421875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 604800, 255, 1, 61967), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001 (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+9, 256892, 1530, 8025, 8025, '14,15,16,17', 0, 0, 458.493072509765625, 3030.241455078125, 143.9758148193359375, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 604800, 255, 1, 61967), -- Bench (Area: The Nighthold - Difficulty: Normal) CreateObject1
(@OGUID+10, 256893, 1530, 8025, 8025, '14,15,16,17', 0, 0, 453.24652099609375, 3028.29345703125, 143.9747161865234375, 1.099554181098937988, 0, 0, 0.522497177124023437, 0.852640986442565917, 604800, 255, 1, 61967); -- Bench (Area: The Nighthold - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+10;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 9340), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002
(@OGUID+2, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Doodad_7sr_suramar_nightwellfx004
(@OGUID+4, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE003
(@OGUID+6, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Doodad_7sr_suramar_nightwellfx003
(@OGUID+7, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Doodad_7NB_NIGHTBORN_CITYTELEPORTER001
(@OGUID+8, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0); -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE001

-- Template Addon
UPDATE `gameobject_template_addon` SET `flags`=0x20 WHERE `entry` IN (251397, 251398); -- Trilliax Portcullis Entrance
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=12317 WHERE `entry`=252318; -- The Eye of Aman'thul
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=12318 WHERE `entry` IN (266181, 266180, 266183, 266182); -- Statue Energy Conduit
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=10418 WHERE `entry`=252319; -- Nighthold Focusing Statue
UPDATE `gameobject_template_addon` SET `AIAnimKitID`=9340 WHERE `entry`=255927; -- Doodad_7NB_NIGHTBORN_TELEPORTER_BASE002
