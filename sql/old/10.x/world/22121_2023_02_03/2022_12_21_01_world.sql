SET @CGUID := 1250038;
SET @OGUID := 700011;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 198096, 0, 1519, 10523, '0', 0, 0, 0, 0, -9078.28515625, 878.998291015625, 67.93842315673828125, 4.995363235473632812, 120, 0, 0, 121952, 7196, 0, 0, 0, 0, 47187), -- Valdrakken Flightmage (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 392617 - Dragonspawn Channel Omni 50%, Blue [DNT])
(@CGUID+1, 198096, 0, 1519, 10523, '0', 0, 0, 0, 0, -9082.9951171875, 875.4600830078125, 68.1085968017578125, 5.818155765533447265, 120, 0, 0, 121952, 7196, 0, 0, 0, 0, 47187); -- Valdrakken Flightmage (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 392617 - Dragonspawn Channel Omni 50%, Blue [DNT])

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 383582, 0, 1519, 10523, '0', 0, 0, -9077.9755859375, 873.447265625, 68.3226165771484375, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 47187); -- Portal to Valdrakken (Area: Wizard's Sanctum - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 257, 0, 0, 0, 0, 0, '392617'), -- Valdrakken Flightmage - 392617 - Dragonspawn Channel Omni 50%, Blue [DNT]
(@CGUID+1, 0, 0, 0, 257, 0, 0, 0, 0, 0, '392617'); -- Valdrakken Flightmage - 392617 - Dragonspawn Channel Omni 50%, Blue [DNT]

DELETE FROM `gameobject_addon` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 8021); -- Portal to Valdrakken

DELETE FROM `gameobject_template_addon` WHERE `entry`=383582;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(383582, 1732, 0, 0, 8021); -- Portal to Valdrakken

UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `faction`=3276, `BaseAttackTime`=1500, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=198096; -- Valdrakken Flightmage

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (393590,370477));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(393590, 0, 2444, 247.8800048828125, -1064.699951171875, 870.91998291015625, 47187), -- Spell: 393590 (Portal to Valdrakken) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(370477, 0, 0, -9041.6103515625, 917.32000732421875, 66.69000244140625, 47187); -- Spell: 370477 (Valdrakken Teleport to Stormwind) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
