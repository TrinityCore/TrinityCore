DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=61632;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,7,61632,0,0,31,0,3,30449,0,0,0,'','Sartharion Berserk - Only hit Tenebron, Shadron & Vesperon'),
(13,7,61632,0,1,31,0,3,30451,0,0,0,'','Sartharion Berserk - Only hit Tenebron, Shadron & Vesperon'),
(13,7,61632,0,2,31,0,3,30452,0,0,0,'','Sartharion Berserk - Only hit Tenebron, Shadron & Vesperon');
