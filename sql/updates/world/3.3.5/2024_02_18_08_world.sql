--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 47604;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,47604,0,0,31,1,3,26417,0,0,0,0,'',"Group 0: Spell 'Gavrock's Runebreaker' targets creature 'Runed Giant'"),
(17,0,47604,0,1,31,1,3,26872,0,0,0,0,'',"Group 1: Spell 'Gavrock's Runebreaker' targets creature 'Weakened Giant'");
