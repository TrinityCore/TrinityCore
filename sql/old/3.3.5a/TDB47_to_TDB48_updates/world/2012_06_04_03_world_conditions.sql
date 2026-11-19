DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 19 AND `SourceEntry` IN (13408,13409,13410,13411);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 13408, 0, 0, 15, 0, 1503, 0, 0, 0, 0, '', 'Hellfire Fortifications - Alliance -All classes other than dk'),
(19, 0, 13409, 0, 0, 15, 0, 1503, 0, 0, 0, 0, '', 'Hellfire Fortifications - Horde -All classes other than dk'),
(19, 0, 13410, 0, 0, 15, 0, 32, 0, 0, 0, 0, '', 'Hellfire Fortifications - Alliance -Only dk'),
(19, 0, 13411, 0, 0, 15, 0, 32, 0, 0, 0, 0, '', 'Hellfire Fortifications - Horde -Only dk');
