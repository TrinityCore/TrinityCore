--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=21215;

INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 21215, 0, 0, 0, 12, 0, 12, 0, 0, 0, 0, 0, '', 'Only display gossip during Hallows End'),
(15, 21215, 0, 0, 0, 23, 0, 1638, 0, 0, 0, 0, 0, '', 'Only display gossip in Thunderbluff'),
(15, 21215, 0, 0, 0, 1, 0, 24755, 0, 0, 1, 0, 0, '', 'only display gossip if player does not have tricked or treated aura');

UPDATE `smart_scripts` SET `target_type`=7 WHERE `entryorguid`=6740 AND `source_type`=0 AND `id`=1 AND `link`=0; 
