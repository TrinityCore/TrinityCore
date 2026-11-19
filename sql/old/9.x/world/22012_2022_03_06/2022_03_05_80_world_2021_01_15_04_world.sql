--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 19 AND `SourceEntry` IN (8166,8167,8168,8169,8170,8171);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(19,0,8171,0,0,27,0,30,2,0,0,0,0,"","Group 0: Quest 'The Battle for Arathi Basin!' requires level lower than 30"),
(19,0,8168,0,0,27,0,30,2,0,0,0,0,"","Group 0: Quest 'The Battle for Arathi Basin!' requires level lower than 30"),
(19,0,8167,0,0,27,0,40,2,0,0,0,0,"","Group 0: Quest 'The Battle for Arathi Basin!' requires level lower than 40"),
(19,0,8170,0,0,27,0,40,2,0,0,0,0,"","Group 0: Quest 'The Battle for Arathi Basin!' requires level lower than 40"),
(19,0,8169,0,0,27,0,50,2,0,0,0,0,"","Group 0: Quest 'The Battle for Arathi Basin!' requires level lower than 50"),
(19,0,8166,0,0,27,0,50,2,0,0,0,0,"","Group 0: Quest 'The Battle for Arathi Basin!' requires level lower than 50");

-- Disabled in 2.4.0
DELETE FROM `disables` WHERE `sourceType` = 1 AND `entry` IN (8080,8154,8155,8156,8297);
INSERT INTO `disables` (`sourceType`,`entry`,`flags`,`params_0`,`params_1`,`comment`) VALUES
(1,8080,0,'','','Deprecated quest: Arathi Basin Resources!'),
(1,8154,0,'','','Deprecated quest: Arathi Basin Resources!'),
(1,8155,0,'','','Deprecated quest: Arathi Basin Resources!'),
(1,8156,0,'','','Deprecated quest: Arathi Basin Resources!'),
(1,8297,0,'','','Deprecated quest: Arathi Basin Resources!');
