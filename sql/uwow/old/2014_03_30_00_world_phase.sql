DROP TABLE phase_template;
ALTER TABLE  `phase_definitions` ADD  `wmAreaId` SMALLINT( 5 ) UNSIGNED NOT NULL DEFAULT  '0' AFTER  `terrainswapmap`;

DELETE FROM phase_definitions WHERE `zoneId` = 4755 AND entry = 1;
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `flags`, `comment`) VALUES
(4755, 1, 1, 0, 638, 0, 'Worgen Start location');

DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND `SourceEntry`= 1 AND SourceGroup in (4756, 4755);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 4755, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 'shadow-phase for start worgen location');


-- Pandatia
DELETE FROM `conditions` WHERE SourceTypeOrReferenceId = 23 AND `SourceEntry` in(1, 2, 3) AND SourceGroup = 5736;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(23, 5736, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Pandaren Start loc: world area', NULL),
(23, 5736, 3, 0, 0, 28, 0, 29799, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 976', NULL),
(23, 5736, 3, 0, 1, 8, 0, 29799, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 976', NULL),
(23, 5736, 2, 0, 0, 28, 0, 30767, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975', NULL),
(23, 5736, 2, 0, 1, 8, 0, 30767, 0, 0, 0, 0, 'Pandaren Start loc: tarrain 975', NULL);

-- World Map Area Id: 683
DELETE FROM phase_definitions WHERE `zoneId` = 5736 AND entry in(1, 2, 3);
INSERT INTO `phase_definitions` (`zoneId`, `entry`, `phasemask`, `phaseId`, `terrainswapmap`, `wmAreaId`, `comment`) VALUES
(5736, 1, 0, 0, 0, 683, 'Pandaren Start loc: world area'),
(5736, 2, 0, 0, 975, 0, 'Pandaren Start loc: tarrain 975'),
(5736, 3, 0, 0, 976, 0, 'Pandaren Start loc: tarrain976');