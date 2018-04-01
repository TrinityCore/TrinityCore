UPDATE `conditions` SET `SourceEntry`=4756 WHERE `SourceTypeOrReferenceId`=26 AND `ConditionValue1`=14078;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `ConditionValue1`=14099;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 170, 4757, 0, 0, 28, 0, 14099, 0, 0, 0, 0, 0, '', '');

DELETE FROM `spell_area` WHERE `area`=4757;
INSERT INTO `spell_area` (`spell`, `area`, `quest_start`, `quest_end`, `aura_spell`, `racemask`, `gender`, `autocast`, `quest_start_status`, `quest_end_status`) VALUES
(59073, 4757, 0, 0, 0, 0, 2, 1, 0, 0);
