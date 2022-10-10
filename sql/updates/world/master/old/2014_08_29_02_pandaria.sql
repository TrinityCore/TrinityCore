UPDATE `creature_addon` SET `auras` = '117326 83305' WHERE `guid` = 803083+6231;
UPDATE `creature_addon` SET `auras` = '83305' WHERE `guid` = 803073+6231;
DELETE FROM `creature` WHERE `guid` = 809316 AND id = 56416;

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND SourceGroup = 5736;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `Comment`, `ScriptName`) VALUES
(23, 5736, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Pandaren Start loc: world area', ''),
(23, 5736, 3, 0, 1, 8, 0, 29799, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 976', ''),
(23, 5736, 2, 0, 0, 8, 0, 29799, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 and not rewarded 29799', ''),
(23, 5736, 2, 0, 0, 28, 0, 30767, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975', ''),
(23, 5736, 2, 0, 1, 8, 0, 29799, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 and not rewarded 29799', ''),
(23, 5736, 2, 0, 1, 8, 0, 30767, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975', ''),
(23, 5736, 4, 0, 0, 8, 0, 29785, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 while not reward 29785', ''),
(23, 5736, 5, 0, 0, 9, 0, 29786, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975 while taken 29786', ''),
(23, 5736, 6, 0, 0, 8, 0, 29665, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 while not rewarded 29665', ''),
(23, 5736, 6, 0, 0, 8, 0, 29786, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975 while rewarded 29786', ''),
(23, 5736, 6, 0, 1, 28, 0, 29786, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975 while rewarded 29786', ''),
(23, 5736, 7, 0, 0, 28, 0, 29790, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 while not rewarded 29790', ''),
(23, 5736, 7, 0, 0, 8, 0, 29790, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 or not complete 29790', ''),
(23, 5736, 7, 0, 0, 9, 0, 29790, 0, 0, 1, 0, 'Pandaren Start loc: tarrain 975 or not taken 29790', ''),
(23, 5736, 8, 0, 0, 8, 0, 29790, 0, 0, 1, 0, 'Pandaren Start loc: tarrain not rewarded 29790', ''),
(23, 5736, 9, 0, 0, 8, 0, 29793, 0, 0, 0, 0, 'Pandaren Start loc: phase 3 while rewarded 29793', ''),
(23, 5736, 9, 0, 0, 8, 0, 29665, 0, 0, 1, 0, 'Pandaren Start loc: phase 3 while not rewarded 29665', '');

UPDATE `gameobject` SET `state` = '0' WHERE  `id` = 210965;
UPDATE `gameobject` SET `state` = '0' WHERE  `id` = 210964;
-- ----------------------------------------
-- Q: 30988 The Alliance Way. HACK!
-- ----------------------------------------
UPDATE `quest_template` SET `RequiredIdCount1` = '0' WHERE `quest_template`.`Id` = 30988;
DELETE FROM `creature_involvedrelation` WHERE `id` = 29611;
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES ('29611', '30988');