--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=14 AND `SourceGroup`=1467;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 1467, 2135, 0, 0, 9, 0, 836, 0, 0, 1, 0, 0, '', 'Show gossip text if player has not completed Rescue OOX-09/HL!'), -- AND
(14, 1467, 2135, 0, 0, 9, 0, 648, 0, 0, 1, 0, 0, '', 'Show gossip text if player has not completed Rescue OOX-09/TN!'), -- AND
(14, 1467, 2135, 0, 0, 9, 0, 2767, 0, 0, 1, 0, 0, '', 'Show gossip text if player has not completed Rescue OOX-09/FE!'), -- AND
(14, 1467, 2136, 0, 0, 9, 0, 836, 0, 0, 0, 0, 0, '', 'Show gossip text if player has completed Rescue OOX-09/HL!'), -- OR
(14, 1467, 2136, 0, 1, 9, 0, 648, 0, 0, 0, 0, 0, '', 'Show gossip text if player has completed Rescue OOX-09/TN!'),  -- OR
(14, 1467, 2136, 0, 2, 9, 0, 2767, 0, 0, 0, 0, 0, '', 'Show gossip text if player has completed Rescue OOX-09/FE!'); -- OR
