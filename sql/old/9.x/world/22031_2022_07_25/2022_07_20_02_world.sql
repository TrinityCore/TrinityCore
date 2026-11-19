SET @CGUID := 850239;

-- Delete old Training Dummys
DELETE FROM `creature` WHERE `guid` IN (314185, 314196, 314192, 314193, 314172, 314164, 314163, 314147, 314150, 314154, 314169);
DELETE FROM `creature_addon` WHERE `guid` IN (314185, 314196, 314192, 314193, 314172, 314164, 314163, 314147, 314150, 314154, 314169);

-- add new one
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 153292, 0, 1519, 1519, '0', 0, 0, 0, 0, -8737.3544921875, 323.482635498046875, 99.962127685546875, 1.867502331733703613, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 44325), -- Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+1, 31146, 0, 1519, 1519, '0', 0, 0, 0, 0, -8716.3037109375, 361.6944580078125, 101.0802154541015625, 4.415682792663574218, 120, 0, 0, 16507400, 0, 0, 0, 0, 0, 44325), -- Raider's Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+2, 153292, 0, 1519, 1519, '0', 0, 0, 0, 0, -8751.330078125, 312.484375, 101.2830963134765625, 0.959931075572967529, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 44325), -- Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 61574 - Banner of the Horde, 98892 - Training Dummy Marker)
(@CGUID+3, 31146, 0, 1519, 1519, '0', 0, 0, 0, 0, -8731.03125, 368.875, 100.912322998046875, 3.926990747451782226, 120, 0, 0, 16507400, 0, 0, 0, 0, 0, 44325), -- Raider's Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+4, 153292, 0, 1519, 1519, '0', 0, 0, 0, 0, -8716.0380859375, 340.060760498046875, 100.7029266357421875, 3.019419670104980468, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 44325), -- Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+5, 31146, 0, 1519, 1519, '0', 0, 0, 0, 0, -8746.201171875, 333.34027099609375, 100.89422607421875, 0.453785598278045654, 120, 0, 0, 16507400, 0, 0, 0, 0, 0, 44325), -- Raider's Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+6, 153292, 0, 1519, 1519, '0', 0, 0, 0, 0, -8724.3212890625, 362.942718505859375, 100.9847564697265625, 4.433136463165283203, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 44325), -- Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+7, 153292, 0, 1519, 1519, '0', 0, 0, 0, 0, -8755.16015625, 318.140625, 100.9178695678710937, 0.366519153118133544, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 44325), -- Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 61574 - Banner of the Horde, 98892 - Training Dummy Marker)
(@CGUID+8, 114832, 0, 1519, 1519, '0', 0, 0, 0, 0, -8717.20703125, 350.6875, 101.1702041625976562, 3.166885852813720703, 120, 0, 0, 1, 0, 0, 0, 0, 0, 44325), -- PvP Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 228687 - Orc Male Mask, 228695 - PvP Rules Enabled for Dummy)
(@CGUID+9, 153292, 0, 1519, 1519, '0', 0, 0, 0, 0, -8730.5908203125, 324.94097900390625, 99.63372802734375, 1.797689080238342285, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 44325), -- Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+10, 31146, 0, 1519, 1519, '0', 0, 0, 0, 0, -8746.263671875, 361.171875, 101.4435272216796875, 5.480333805084228515, 120, 0, 0, 16507400, 0, 0, 0, 0, 0, 44325), -- Raider's Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 98892 - Training Dummy Marker, 61574 - Banner of the Horde)
(@CGUID+11, 153292, 0, 1519, 1519, '0', 0, 0, 0, 0, -8746.1806640625, 309.838531494140625, 100.5484771728515625, 1.431169986724853515, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 44325); -- Training Dummy (Area: Stormwind City - Difficulty: 0) (Auras: 61574 - Banner of the Horde, 98892 - Training Dummy Marker)

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (114832 /*114832 (PvP Training Dummy) - Training Dummy Marker, Orc Male Mask, PvP Rules Enabled for Dummy*/, 153292 /*153292 (Training Dummy) - Training Dummy Marker, Banner of the Horde*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(114832, 0, 0, 0, 1, 0, 0, 0, 0, 0, '98892 228687 228695'), -- 114832 (PvP Training Dummy) - Training Dummy Marker, Orc Male Mask, PvP Rules Enabled for Dummy
(153292, 0, 0, 0, 1, 0, 0, 0, 0, 0, '98892 61574'); -- 153292 (Training Dummy) - Training Dummy Marker; Banner of the Horde

UPDATE `creature_template_addon` SET `auras`='98892 61574' WHERE `entry`=31146; -- 31146 (Raider's Training Dummy) - Training Dummy Marker, Banner of the Horde

-- Update Template
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=8388609 WHERE `entry`=114832; -- PvP Training Dummy
UPDATE `creature_template` SET `minlevel`=63, `maxlevel`=63, `unit_flags`=131072, `unit_flags3`=8388609 WHERE `entry`=31146; -- Raider's Training Dummy
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=8388609 WHERE `entry`=153292; -- Training Dummy

-- Apply Training Dummy Script
UPDATE `creature_template` SET ScriptName = 'npc_training_dummy' WHERE `entry` IN (114832, 31146, 153292);
