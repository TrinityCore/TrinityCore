-- 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=56922;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,30500,56922,0,0,1,0,56678,1,0,1,0,'','require not having the aura for spellclick'),
(18,30500,56922,0,0,9,0,13045,0,0,0,0,'','Required quest active for spellclick');
