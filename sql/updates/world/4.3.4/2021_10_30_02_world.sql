
SET @CGUID := 396671;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 52382, 1, 1637, 5356, 1, 169, 0, 0, 0, 1673.2135009765625, -4354.3974609375, 27.09087944030761718 - 1, 3.001966238021850585, 120, 0, 0, 30951, 0, 0, 0, 0, 0, 15595), -- Ziradormi (Area: Grommash Hold - Difficulty: 0) (Auras: 94223 - Generic Quest Invisibility 25)
(@CGUID+1, 52408, 0, 1519, 5154, 1, 169, 0, 0, 0, -9009.4599609375, 862.2413330078125, 30.45246505737304687 - 1, 1.2042771577835083, 120, 0, 0, 30951, 0, 0, 0, 0, 0, 15595); -- Coridormi (Area: Mage Quarter - Difficulty: 0) (Auras: 94223 - Generic Quest Invisibility 25)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `waypointPathId`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 33619968, 1, 0, '94223'), -- Ziradormi - 94223 - Generic Quest Invisibility 25
(@CGUID+1, 0, 0, 33619968, 1, 0, '94223'); -- Coridormi - 94223 - Generic Quest Invisibility 25

DELETE FROM `spell_area` WHERE `spell` IN (97039, 97041) AND `area` IN (5154, 5356);
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `gender`, `flags`, `quest_start_status`, `quest_end_status`) VALUES
(97039, 5154, 29453, 2, 3, 2 | 8 | 64, 0),
(97041, 5356, 29452, 2, 3, 2 | 8 | 64, 0);

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (52382, 52408);
INSERT INTO `creature_template_movement` (`CreatureID`, `Ground`, `Flight`, `Swim`, `Rooted`) VALUES
(52382, 2, 1, 0, 0),
(52408, 2, 1, 0, 0);
