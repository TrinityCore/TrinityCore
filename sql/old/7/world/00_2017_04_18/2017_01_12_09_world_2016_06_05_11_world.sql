--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN(13,17) AND `SourceEntry`=58912;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES 
(17,0,58912,0,0,31,1,3,31254,0,0,0,0,'','Deathstorm requires target Lordaeron Footsoldier'),
(17,0,58912,0,1,31,1,3,32414,0,0,0,0,'','Deathstorm requires target Lordaeron Captain'),
(13,1,58912,0,0,31,0,3,31254,0,0,0,0,'','Deathstorm can hit Lordaeron Footsoldier'),
(13,1,58912,0,1,31,0,3,32414,0,0,0,0,'','Deathstorm can hit Lordaeron Captain');
