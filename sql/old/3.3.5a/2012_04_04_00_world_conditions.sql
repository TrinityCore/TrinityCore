-- Will of Sartharion should only target the drakes and Sartharion
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=61254;
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13, 1, 61254, 0, 0, 31, 0, 3, 30449, 0, 0, 0, '', 'Will of Sartharion'),
(13, 1, 61254, 0, 1, 31, 0, 3, 30451, 0, 0, 0, '', 'Will of Sartharion'),
(13, 1, 61254, 0, 2, 31, 0, 3, 30452, 0, 0, 0, '', 'Will of Sartharion'),
(13, 1, 61254, 0, 3, 31, 0, 3, 28860, 0, 0, 0, '', 'Will of Sartharion');
