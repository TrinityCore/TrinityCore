/*
-- 
DELETE FROM `conditions` WHERE `SourceEntry` IN (6545, 6546, 6547) AND `SourceTypeOrReferenceId` IN (19, 20);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 6545, 0, 0, 9, 0, 6543, 0, 0, 0, 0, 0, "", "Quest 'Warsong Runner Update' - Can accept if player has quest 'The Warsong Reports' in quest log"),
(20, 0, 6545, 0, 0, 9, 0, 6543, 0, 0, 0, 0, 0, "", "Quest 'Warsong Runner Update' - Can accept if player has quest 'The Warsong Reports' in quest log"),
(19, 0, 6546, 0, 0, 9, 0, 6543, 0, 0, 0, 0, 0, "", "Quest 'Warsong Outrider Update' - Can accept if player has quest 'The Warsong Reports' in quest log"),
(20, 0, 6546, 0, 0, 9, 0, 6543, 0, 0, 0, 0, 0, "", "Quest 'Warsong Outrider Update' - Can accept if player has quest 'The Warsong Reports' in quest log"),
(19, 0, 6547, 0, 0, 9, 0, 6543, 0, 0, 0, 0, 0, "", "Quest 'Warsong Scout Update' - Can accept if player has quest 'The Warsong Reports' in quest log"),
(20, 0, 6547, 0, 0, 9, 0, 6543, 0, 0, 0, 0, 0, "", "Quest 'Warsong Scout Update' - Can accept if player has quest 'The Warsong Reports' in quest log");
*/
