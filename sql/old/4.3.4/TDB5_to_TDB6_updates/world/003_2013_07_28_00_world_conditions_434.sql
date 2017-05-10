DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=24 AND `SourceEntry` IN (20138,20139,20140); 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(24, 0, 20138, 0, 0, 33, 1, 0, 0, 0, 1, 0, 0, '', 'Protector of the Innocent (Rank 1) - cannot proc on hit self'), 
(24, 0, 20139, 0, 0, 33, 1, 0, 0, 0, 1, 0, 0, '', 'Protector of the Innocent (Rank 2) - cannot proc on hit self'), 
(24, 0, 20140, 0, 0, 33, 1, 0, 0, 0, 1, 0, 0, '', 'Protector of the Innocent (Rank 3) - cannot proc on hit self');  
