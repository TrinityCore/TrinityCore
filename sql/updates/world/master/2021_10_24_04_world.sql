-- 
SET @CGUID := 1050137;
SET @OGUID := 600017;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (271723 /*Lightforged Beacon*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(271723, 114, 0, 0, 0); -- Lightforged Beacon

UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=34816, `VerifiedBuild`=40593 WHERE `entry`=130758; -- Lightforged Beacon
UPDATE `creature_template_model` SET `VerifiedBuild`=40593 WHERE (`CreatureID`=130758 AND `Idx`=0); -- Lightforged Beacon

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 130758, 0, 1519, 9171, '0', 10034, 0, 0, 0, -8163.1318359375, 777.22918701171875, 76.84771728515625, 6.195094108581542968, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 40593); -- Lightforged Beacon (Area: Stormwind Embassy - Difficulty: 0)

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=130758;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(130758, 258298, 3, 0);

DELETE FROM `spell_target_position` WHERE (`ID`=258297 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(258297, 0, 1860, 459.0889892578125, 1450.1400146484375, 758.01800537109375, 40593); -- Spell: 258297 (Teleport to Vindicaar) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

UPDATE `gameobject_template` SET `ContentTuningId`=293, `VerifiedBuild`=40593 WHERE `entry`=271723; -- Lightforged Beacon

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 271723, 0, 1519, 9171, '0', 10034, 0, -8163.1318359375, 777.22918701171875, 76.76438140869140625, 6.195094585418701171, 0, 0, -0.04403114318847656, 0.999030172824859619, 120, 255, 1, 40593); -- Lightforged Beacon (Area: Stormwind Embassy - Difficulty: 0)

DELETE FROM `phase_area` WHERE `AreaId`=1519 AND `PhaseId`=10034;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 10034, 'Cosmetic: Lightforged Beacon (LF Draenei) in Stormwind');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=10034 AND `SourceEntry`=1519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10034, 1519, 0, 0, 16, 0, 0x20000000, 0, 0, 0, 'Player is race Lightforged Draenei');
