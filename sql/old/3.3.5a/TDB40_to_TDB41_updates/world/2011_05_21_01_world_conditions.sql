DELETE FROM `conditions` WHERE `SourceEntry` IN (62385,62386,62387,62521,62525,62524);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`)
VALUES
(13,0,62385,0,18,1,32906,0,0,'','Brightleaf\'s Essence'),
(13,0,62386,0,18,1,32906,0,0,'','Stonebarks\'s Essence'),
(13,0,62387,0,18,1,32906,0,0,'','Ironbranch\'s Essence'),
(13,0,62521,0,18,1,32906,0,0,'','Attuned to Nature 25 Dose Reduction'),
(13,0,62524,0,18,1,32906,0,0,'','Attuned to Nature 2 Dose Reduction'),
(13,0,62525,0,18,1,32906,0,0,'','Attuned to Nature 10 Dose Reduction');