-- Phase 23936
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23936 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23936, 0, 0, 0, 47, 0, 82797, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82797 is taken | complete | rewarded'),
(26, 23936, 0, 0, 0, 47, 0, 82799, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82799 is not taken | complete | rewarded'),
(26, 23936, 0, 0, 0, 47, 0, 82798, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82798 is not taken | complete | rewarded'),
--
(26, 23936, 0, 0, 1, 47, 0, 82797, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82797 is taken | complete | rewarded'),
(26, 23936, 0, 0, 1, 47, 0, 82799, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82799 is taken | complete | rewarded'),
(26, 23936, 0, 0, 1, 47, 0, 82798, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82798 is not taken | complete | rewarded'),
--
(26, 23936, 0, 0, 2, 47, 0, 82797, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82797 is taken | complete | rewarded'),
(26, 23936, 0, 0, 2, 47, 0, 82799, 2|8|64, 0, 1, 'Apply Phase 23936 if Quest 82799 is not taken | complete | rewarded'),
(26, 23936, 0, 0, 2, 47, 0, 82798, 2|8|64, 0, 0, 'Apply Phase 23936 if Quest 82798 is taken | complete | rewarded');

-- Phase 24032
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 24032 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 24032, 0, 0, 0, 47, 0, 82799, 2|8|64, 0, 0, 'Apply Phase 24032 if Quest 82799 is taken | complete | rewarded'),
(26, 24032, 0, 0, 0, 47, 0, 82798, 2|8|64, 0, 0, 'Apply Phase 24032 if Quest 82798 is taken | complete | rewarded');
