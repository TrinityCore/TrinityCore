--
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (269966,248956);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(269966, 94, 0, 0, 0), -- Large Crate
(248956, 0, 4, 0, 0); -- Compendium of Ancient Weapons Volume V

UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=176583; -- Golden Sansam
UPDATE `gameobject_template_addon` SET `flags`=1 WHERE `entry`=184255; -- Long Neck Spectrum Analyzer
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181569; -- Rich Adamantite Deposit
UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=184310; -- Suspicious Outhouse
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181270; -- Felweed
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=181280; -- Nightmare Vine
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183045; -- Dreaming Glory
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=183044; -- Felweed
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=176584; -- Dreamfoil
UPDATE `gameobject_template_addon` SET `WorldEffectID`=8830 WHERE `entry`=278676; -- Adventurer's Taskboard

DELETE FROM `quest_details` WHERE `ID` IN (10315,10334);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10315, 1, 1, 15, 0, 0, 1000, 1000, 0, 40966), -- Neutralizing the Nethermancers
(10334, 18, 18, 1, 0, 0, 0, 0, 0, 40966); -- Needs More Cowbell

UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `npcflag`=1125899906842625 WHERE `entry`=29145; -- Pulik Swiftsnip

DELETE FROM `creature_template_addon` WHERE `entry`=29145;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(29145, 0, 0, 0, 257, 0, 0, 0, 0, ''); -- 29145 (Pulik Swiftsnip)

DELETE FROM `creature` WHERE `guid`=86804;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(86804, 29145, 530, 3523, 3712, '0', 0, 0, 0, 0, 2971.42041015625, 3752.674560546875, 144.251556396484375, 4.817108631134033203, 300, 0, 0, 0, 0, 0, 0, 0, 0, 40966); -- Pulik Swiftsnip (Area: Area 52 - Difficulty: 0)

DELETE FROM `gameobject` WHERE `guid`=6516;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(6516, 191817, 530, 3523, 3712, '0', 0, 0, 2969.6787109375, 3752.763427734375, 144.5045928955078125, 1.998400807380676269, 0, 0, 0.841038703918457031, 0.540974974632263183, 120, 255, 1, 40966); -- Barber Chair (Area: Area 52 - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid`=6516;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(6516, 0, 0, 0.069756560027599334, 0.99756401777267456, 0, 0); -- Barber Chair

DELETE FROM `gameobject` WHERE `guid` IN (24148,39519); -- remove incorrect object in barbershop building)
DELETE FROM `gameobject_addon` WHERE `guid` IN (24148,39519);
