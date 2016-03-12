DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceGroup` IN (2, 3) AND `SourceEntry`=27743;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`, `ErrorTextId`,`ScriptName`,`Comment`, `NegativeCondition`) VALUES
(22,2,27743,0,31,3,27743,0,0,'','event will not trigger if the spell is casted by 27743', 1),
(22,3,27743,0,31,3,27743,0,0,'','event will not trigger if the spell is casted by 27743', 1);
