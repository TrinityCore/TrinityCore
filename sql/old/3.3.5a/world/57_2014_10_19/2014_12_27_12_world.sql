UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id` IN(10995,10996,10997);
UPDATE `quest_template` SET `ExclusiveGroup`=10983 WHERE  `Id` IN(10983,10989);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(19,20) AND `SourceEntry` IN(10995,10996,10997);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(19, 0, 10995, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(20, 0, 10995, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(19, 0, 10995, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(20, 0, 10995, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Grulloc Has Two Skulls after Mog dorg the Wizened'),
(19, 0, 10996, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(20, 0, 10996, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(19, 0, 10996, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(20, 0, 10996, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Maggocs Treasure Chest after Mog dorg the Wizened'),
(19, 0, 10997, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened'),
(20, 0, 10997, 0, 0, 8, 0, 10989, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened'),
(19, 0, 10997, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened'),
(20, 0, 10997, 0, 1, 8, 0, 10983, 0, 0, 0, 0, 0, '', 'Even Gronn Have Standards after Mog dorg the Wizened');
