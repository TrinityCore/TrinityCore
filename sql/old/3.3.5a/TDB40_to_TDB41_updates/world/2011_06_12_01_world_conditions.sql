-- Add condition for Item 38731 "Ahunae's Knife" to target 28600 "Dead Heb'Drakkar Headhunter"
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceEntry`=38731;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(18,0,38731,0,24,2,28600,0,63,'','Item 38731 "Ahunae''s Knife" targets 28600 "Dead Heb''Drakkar Headhunter');
