-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceGroup`=0 AND `SourceEntry`=23301 AND `ConditionTypeOrReference`=30;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,23301,0,0,30,1,192180,1,0,1,0,0,'','Do not cast Ebon Blade Banner if Ebon Blade Banner is planted'),
(17,0,23301,0,1,30,1,192180,1,0,1,0,0,'','Do not cast Ebon Blade Banner if Ebon Blade Banner is planted'),
(17,0,23301,0,2,30,1,192180,1,0,1,0,0,'','Do not cast Ebon Blade Banner if Ebon Blade Banner is planted'),
(17,0,23301,0,3,30,1,192180,1,0,1,0,0,'','Do not cast Ebon Blade Banner if Ebon Blade Banner is planted');
