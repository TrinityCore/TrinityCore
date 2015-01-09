DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN(66661,66642,30015,3678);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(17, 0, 66661, 0, 0, 29, 0, 35012, 40, 0, 1, 0, 0, '', 'Cant use Captured Kvaldir Banner within 40 yards of Ornolf The Scarred'),
(17, 0, 66642, 0, 0, 29, 0, 34980, 40, 0, 1, 0, 0, '', 'Cant use Kvaldir War Horn within 40 yards of Drottinn Hrothgar'),
(17, 0, 30015, 0, 0, 29, 0, 17207, 100, 0, 1, 0, 0, '', 'Cant use Gift of Naias within 100 yards of Naias'),
(17, 0, 3678, 0, 0, 29, 0, 2624, 100, 0, 1, 0, 0, '', 'Cant use Catelyns Blade within 100 yards of Gazban');
