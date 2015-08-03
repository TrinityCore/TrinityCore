-- Class Condition update to use flags
UPDATE `conditions` SET `ConditionValue1`=8 WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=21194 AND `ConditionTypeOrReference`=15;
UPDATE `conditions` SET `ConditionValue1`=128 WHERE `SourceTypeOrReferenceId` IN (14,15) AND`SourceGroup`=4486 AND `ConditionTypeOrReference`=15;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=20 AND `SourceEntry` IN (13104,13105) AND `ConditionTypeOrReference`=15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(20,0,13104,1,15,1503,0,0,0,'','Show quest 13104 if player is not a Death Knight'),
(20,0,13105,1,15,32,0,0,0,'','Show quest 13105 if player is a Death Knight');
-- Race Condition update to use flags
UPDATE `conditions` SET `ConditionValue1`=128 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=24101 AND `ConditionTypeOrReference`=16;
UPDATE `conditions` SET `ConditionValue1`=32 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=24102 AND `ConditionTypeOrReference`=16;
UPDATE `conditions` SET `ConditionValue1`=16 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=24103 AND `ConditionTypeOrReference`=16;
UPDATE `conditions` SET `ConditionValue1`=64 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=24106 AND `ConditionTypeOrReference`=16;
UPDATE `conditions` SET `ConditionValue1`=4 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=24107 AND `ConditionTypeOrReference`=16;
UPDATE `conditions` SET `ConditionValue1`=8 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=24108 AND `ConditionTypeOrReference`=16;
UPDATE `conditions` SET `ConditionValue1`=512 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=69530 AND `ConditionTypeOrReference`=16;
UPDATE `conditions` SET `ConditionValue1`=1024 WHERE `SourceTypeOrReferenceId`=17 AND `SourceEntry`=69533 AND `ConditionTypeOrReference`=16;
