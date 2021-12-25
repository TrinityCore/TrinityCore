-- 
SET @OGUID := 600016;

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (279608 /*Rift to Telogrus*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(279608, 0, 32, 0, 0); -- Rift to Telogrus

DELETE FROM `gameobject_template` WHERE `entry` IN (279608 /*Rift to Telogrus*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `ContentTuningId`, `VerifiedBuild`) VALUES
(279608, 22, 42710, 'Rift to Telogrus', '', '', '', 0.25, 259377, -1, 0, 1, 1, 55254, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 863, 40593); -- Rift to Telogrus

DELETE FROM `gameobject` WHERE `guid`=@OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 279608, 0, 1519, 9171, '0', 10035, 0, -8173.65283203125, 776.34722900390625, 74.85990142822265625, 6.195094585418701171, 0, 0, -0.04403114318847656, 0.999030172824859619, 120, 255, 1, 40593); -- Rift to Telogrus (Area: Stormwind Embassy - Difficulty: 0)

UPDATE `spell_target_position` SET `VerifiedBuild`=40593 WHERE (`ID`=259377 AND `EffectIndex`=0);

DELETE FROM `phase_area` WHERE `AreaId`=1519 AND `PhaseId`=10035;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(1519, 10035, 'Cosmetic: Telogrus Rift Portal in Stormwind');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=10035 AND `SourceEntry`=1519;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 10035, 1519, 0, 0, 16, 0, 0x10000000, 0, 0, 0, 'Player is race Voidelf');
