--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=5962;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 5962, 7115, 0, 0, 28, 0, 7722, 0, 0, 0, 0, 0, '', 'Show Gossip Menu - If Quest: What the Flux? is Completed'),
(14, 5962, 7115, 0, 1, 5, 0, 59, 128, 0, 0, 0, 0, '', 'Show Gossip Menu - If player is exalted with Thorium Brotherhood (59)');
