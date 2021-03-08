UPDATE `gameobject` SET `PhaseId`= 226 WHERE `guid`= 222402;
UPDATE `spell_area` SET `quest_start`= 26322 WHERE `spell`= 80005 AND `area`= 108;

DELETE FROM `phase_area` WHERE `AreaId`= 108;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(108, 226, 'Sentinel Hill - Rise of the Brotherhood');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 26 AND `SourceEntry`= 108;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `NegativeCondition`, `Comment`, `ScriptName`) VALUES 
(26, 226, 108, 8, 26322, 0, 'Phase 226: active when rewarded quest 26322', '');
