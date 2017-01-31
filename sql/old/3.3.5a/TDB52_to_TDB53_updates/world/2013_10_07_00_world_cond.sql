UPDATE `quest_template` SET `ExclusiveGroup`=13104 WHERE  `Id` IN (13104,13105);
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE  `Id`IN (13110,13122,13118,13125);
UPDATE `quest_template` SET `RequiredClasses`=1503 WHERE  `Id`=13104;
UPDATE `quest_template` SET `RequiredClasses`=32 WHERE  `Id`=13105;
DELETE FROM  `conditions` WHERE `SourceEntry` IN (13122,13110,13118,13125);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(20, 0, 13110, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Restless Dead after Once More Unto The Breach, Hero'),
(19, 0, 13110, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Restless Dead after Once More Unto The Breach, Hero'),
(20, 0, 13110, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Restless Dead after Once More Unto The Breach, Hero'),
(19, 0, 13110, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Restless Dead after Once More Unto The Breach, Hero'),
(20, 0, 13122, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Scourgestone after Once More Unto The Breach, Hero'),
(19, 0, 13122, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Scourgestone after Once More Unto The Breach, Hero'),
(20, 0, 13122, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Scourgestone after Once More Unto The Breach, Hero'),
(19, 0, 13122, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Scourgestone after Once More Unto The Breach, Hero'),
(20, 0, 13118, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Purging Of Scourgeholme  after Once More Unto The Breach, Hero'),
(19, 0, 13118, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Purging Of Scourgeholme  after Once More Unto The Breach, Hero'),
(20, 0, 13118, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Purging Of Scourgeholme  after Once More Unto The Breach, Hero'),
(19, 0, 13118, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Purging Of Scourgeholme  after Once More Unto The Breach, Hero'),
(20, 0, 13125, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Air Stands Still  after Once More Unto The Breach, Hero'),
(19, 0, 13125, 0, 0, 8, 0, 13104, 0, 0, 0, 0, '', 'The Air Stands Still  after Once More Unto The Breach, Hero'),
(20, 0, 13125, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Air Stands Still  after Once More Unto The Breach, Hero'),
(19, 0, 13125, 0, 1, 8, 0, 13105, 0, 0, 0, 0, '', 'The Air Stands Still  after Once More Unto The Breach, Hero');
