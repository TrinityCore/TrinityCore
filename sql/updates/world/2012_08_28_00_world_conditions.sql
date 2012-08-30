-- Quest: I was a lot of things
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=36652;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`Comment`) VALUES 
(13,1,36652,31,3,21347,'Tuber Whistle targets Shadowmoon Valley Tuber Node');
