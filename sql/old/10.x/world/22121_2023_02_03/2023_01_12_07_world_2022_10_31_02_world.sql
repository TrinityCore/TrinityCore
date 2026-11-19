-- Conditions for Trial and Error (10566)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` IN (37221,37320,37322,37323);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,37221,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'"),
(17,0,37320,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'"),
(17,0,37322,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'"),
(17,0,37323,0,0,31,1,3,21254,0,0,0,0,'',"Spell 'Cristal Control' targets creature 'Dullgrom Dredger'");
