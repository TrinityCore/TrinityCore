DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=29488 AND `SourceEntry`=54568;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,
`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(18,29488,54568,15,8,0,12670,0,0,0,'Required quest rewarded for spellclick'),
(18,29488,54568,15,9,0,12670,0,0,0,'Required quest active for spellclick');
