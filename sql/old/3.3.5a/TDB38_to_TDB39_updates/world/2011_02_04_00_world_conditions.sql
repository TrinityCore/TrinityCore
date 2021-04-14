DELETE FROM `conditions` WHERE `SourceEntry` IN (62521,62524,62525);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,0,62524,0,18,1,32906,0,0,'','Attuned to Nature 2 Dose Reduction'),
(13,0,62525,0,18,1,32906,0,0,'','Attuned to Nature 10 Dose Reduction'),
(13,0,62521,0,18,1,32906,0,0,'','Attuned to Nature 25 Dose Reduction');
