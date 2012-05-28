-- Quest: Blending In (11633)
-- Spell from Cape only Appliable in City Area
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=45614;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,45614,11633,23,4125,0,0,0, '', 'Shroud of the Scourge - Temple City of En''kilah');
