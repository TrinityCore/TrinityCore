-- Quest "What Argus Means to Me" should not be availably when you have quest "Report to Exarch Admetius" in your log (Not Breadcrumb)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`= 19 AND `SourceEntry`=9693;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,9693,0,0,28,0,9668,0,0,1,0,0,'',"Don't show quest 'What Argus Means to Me' if quest 'Report To Exarch Admetius' is taken");
