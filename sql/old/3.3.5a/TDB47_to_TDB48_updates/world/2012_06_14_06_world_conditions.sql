DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry` IN (19938,30877);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(17,0,19938,0,0,1,1,17743,0,0,0,0,'','Awaken Peon'),
(17,0,30877,0,0,31,1,3,17326,0,0,0,'','Tag Murloc');

-- Lifebinder's Gift
UPDATE `conditions` SET `SourceGroup`=7 WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (62584,64185);
