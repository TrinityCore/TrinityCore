SET @OGUID := 300849;

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 210005, 860, 5736, 5834, '0', 0, 598, 0, -1, 1420.94, 3457.37, 171.185, 0.279252, 0, 0, 0.139173, 0.990268, 120, 255, 1, 50791);

UPDATE `conditions` SET `ConditionValue1`=384, `Comment`='Get phase only if the class is Mage or Warlock' WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup`=593 AND `SourceEntry` =0;

UPDATE `quest_template_addon` SET `AllowableClasses`=384 WHERE `ID`=30033;

UPDATE `gameobject` SET `phaseId`=598 WHERE `guid` IN (300030, 300016, 300011, 300031, 300022, 300007, 300026, 300020, 300017);

UPDATE `playercreateinfo_cast_spell` SET `classmask`=384, `note`='Pandaren - Mage and Warlock - Remove weapon' WHERE `spell` = 108055;
