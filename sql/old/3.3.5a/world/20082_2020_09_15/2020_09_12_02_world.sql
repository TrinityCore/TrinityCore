--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 47939;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,47939,0,0,31,0,5,188539,0,0,0,0,"","Group 0: Spell 'Gather Lumber' (Effect 1) targets object 'Coldwind Tree'"),
(13,1,47939,0,1,31,0,5,190353,0,0,0,0,"","Group 1: Spell 'Gather Lumber' (Effect 1) targets object 'Poster Knife'");
