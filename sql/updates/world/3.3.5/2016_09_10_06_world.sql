--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=42817;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(17, 0, 42817, 0, 0, 29, 0, 24019, 100, 0, 1, 0, 0, "", "Can cast spell Wyrmcaller's Horn if NPC Glacion is not near");

UPDATE `gameobject` SET `spawntimesecs`=0 WHERE `guid`=6008;
