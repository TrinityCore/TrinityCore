DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (20761,17051,17022,17018,17023,19444);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (19219,17017,17025,19330,19448,17059,17060,17049,19206);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (19220,19332,19333,19331,19449,19209,19208,19207,17053,17052);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=23 AND `SourceGroup`=12944 AND `SourceEntry` IN (19211,19210,19212,20040);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
-- Conditon rep Friendly
(23,12944,20761,0,0,5,0,59,16|32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17051,0,0,5,0,59,16|32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17022,0,0,5,0,59,16|32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17018,0,0,5,0,59,16|32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,17023,0,0,5,0,59,16|32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
(23,12944,19444,0,0,5,0,59,16|32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Friendly with Thorium Brotherhood'),
-- Conditon rep Honored
(23,12944,19219,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17017,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17025,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,19330,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,19448,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17059,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17060,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,17049,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
(23,12944,19206,0,0,5,0,59,32|64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Honored with Thorium Brotherhood'),
-- Conditon rep Revered
(23,12944,19220,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19332,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19333,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19331,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19449,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19209,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19208,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,19207,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,17053,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
(23,12944,17052,0,0,5,0,59,64|128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Revered with Thorium Brotherhood'),
-- Conditon rep Exalted
(23,12944,19211,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood'),
(23,12944,19210,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood'),
(23,12944,19212,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood'),
(23,12944,20040,0,0,5,0,59,128,0,0,0, '', 'Lokhtos Darkbargainer - Only sell item if Exalted with Thorium Brotherhood');
