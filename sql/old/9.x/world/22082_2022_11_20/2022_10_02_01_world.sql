-- Phasing
DELETE FROM `phase_area` WHERE `AreaId` = 4737 AND `PhaseId` IN (378, 379, 380, 381, 382, 383, 384);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(4737, 378, 'Kezan - Chapter 1'),
(4737, 379, 'Kezan - Chapter 2'),
(4737, 380, 'Kezan - Chapter 3'),
(4737, 381, 'Kezan - Chapter 4'),
(4737, 382, 'Kezan - Chapter 5'),
(4737, 383, 'Kezan - Chapter 6'),
(4737, 384, 'Kezan - Chapter 7');

-- Condition Phase 378
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 378 AND `SourceEntry` = 4737);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 378, 4737, 0, 0, 8, 0, 24520, 0, 0, 1, 'Apply Phase 378 if Quest 24520 is not rewarded'),
(26, 378, 4737, 0, 1, 8, 0, 14070, 0, 0, 1, 'Apply Phase 378 if Quest 14070 is not rewarded'),
(26, 378, 4737, 0, 2, 8, 0, 14109, 0, 0, 1, 'Apply Phase 378 if Quest 14109 is not rewarded');

-- Condition Phase 379
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 379 AND `SourceEntry` = 4737);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 379, 4737, 0, 0, 8, 0, 24520, 0, 0, 0, 'Apply Phase 379 if Quest 24520 is rewarded'),
(26, 379, 4737, 0, 0, 8, 0, 14070, 0, 0, 0, 'Apply Phase 379 if Quest 14070 is rewarded'),
(26, 379, 4737, 0, 0, 8, 0, 14109, 0, 0, 0, 'Apply Phase 379 if Quest 14109 is rewarded'),
(26, 379, 4737, 0, 0, 20, 0, 1, 0, 0, 0, 'Apply Phase 379 if Player is Female'),
(26, 379, 4737, 0, 0, 8, 0, 14153, 0, 0, 1, 'Apply Phase 379 if Quest 14153 (Female) is not rewarded'),
(26, 379, 4737, 0, 1, 8, 0, 24520, 0, 0, 0, 'Apply Phase 379 if Quest 24520 is rewarded'),
(26, 379, 4737, 0, 1, 8, 0, 14070, 0, 0, 0, 'Apply Phase 379 if Quest 14070 is rewarded'),
(26, 379, 4737, 0, 1, 8, 0, 14109, 0, 0, 0, 'Apply Phase 379 if Quest 14109 is rewarded'),
(26, 379, 4737, 0, 1, 20, 0, 0, 0, 0, 0, 'Apply Phase 379 if Player is Male'),
(26, 379, 4737, 0, 1, 8, 0, 14113, 0, 0, 1, 'Apply Phase 379 if Quest 14113 (Male) is not rewarded');

-- Condition Phase 380
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 380 AND `SourceEntry` = 4737);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 380, 4737, 0, 0, 8, 0, 14153, 0, 0, 0, 'Apply Phase 380 if Quest 14153 (Female) is rewarded'),
(26, 380, 4737, 0, 0, 8, 0, 14115, 0, 0, 1, 'Apply Phase 380 if Quest 14115 not is rewarded'),
(26, 380, 4737, 0, 1, 8, 0, 14113, 0, 0, 0, 'Apply Phase 380 if Quest 14113 (Male) is rewarded'),
(26, 380, 4737, 0, 1, 8, 0, 14115, 0, 0, 1, 'Apply Phase 380 if Quest 14115 is not rewarded');

-- Condition Phase 381
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 381 AND `SourceEntry` = 4737);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 381, 4737, 0, 0, 8, 0, 14115, 0, 0, 0, 'Apply Phase 381 if Quest 14115 is rewarded'),
(26, 381, 4737, 0, 0, 8, 0, 14116, 0, 0, 1, 'Apply Phase 381 if Quest 14116 is not rewarded');

-- Condition Phase 382
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 382 AND `SourceEntry` = 4737);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 382, 4737, 0, 0, 8, 0, 14116, 0, 0, 0, 'Apply Phase 382 if Quest 14116 is rewarded'),
(26, 382, 4737, 0, 0, 8, 0, 14120, 0, 0, 1, 'Apply Phase 382 if Quest 14120 is not rewarded');

-- Condition Phase 383
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 383 AND `SourceEntry` = 4737);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 383, 4737, 0, 0, 8, 0, 14120, 0, 0, 0, 'Apply Phase 382 if Quest 14120 is rewarded'),
(26, 383, 4737, 0, 0, 8, 0, 14123, 0, 0, 1, 'Apply Phase 383 if Quest 14123 is not rewarded'),
(26, 383, 4737, 0, 1, 8, 0, 14120, 0, 0, 0, 'Apply Phase 382 if Quest 14120 is rewarded'),
(26, 383, 4737, 0, 1, 8, 0, 14122, 0, 0, 1, 'Apply Phase 383 if Quest 14122 is not rewarded'),
(26, 383, 4737, 0, 2, 8, 0, 14120, 0, 0, 0, 'Apply Phase 382 if Quest 14120 is rewarded'),
(26, 383, 4737, 0, 2, 8, 0, 14121, 0, 0, 1, 'Apply Phase 383 if Quest 14121 is not rewarded'),
(26, 383, 4737, 0, 3, 8, 0, 14120, 0, 0, 0, 'Apply Phase 382 if Quest 14120 is rewarded'),
(26, 383, 4737, 0, 3, 8, 0, 14124, 0, 0, 1, 'Apply Phase 383 if Quest 14124 is not rewarded');

-- Condition Phase 384
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26 AND `SourceGroup` = 384 AND `SourceEntry` = 4737);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 384, 4737, 0, 0, 8, 0, 14123, 0, 0, 0, 'Apply Phase 384 if Quest 14123 is rewarded'),
(26, 384, 4737, 0, 0, 8, 0, 14122, 0, 0, 0, 'Apply Phase 384 if Quest 14122 is rewarded'),
(26, 384, 4737, 0, 0, 8, 0, 14121, 0, 0, 0, 'Apply Phase 384 if Quest 14121 is rewarded'),
(26, 384, 4737, 0, 0, 8, 0, 14124, 0, 0, 0, 'Apply Phase 384 if Quest 14124 is rewarded');
