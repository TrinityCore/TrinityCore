-- The Crusader's Pinnacle
-- The Purging Of Scourgeholme 13118 / The Restless Dead 13110 / The Stone That Started A Revolution 13130 / It Could Kill Us All 13135 / The Scourgestone 13122
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13118,13110,13130,13135,13122);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
-- The Purging Of Scourgeholme 13118
(19,13118,0,8,13104,'Accepting The Purging Of Scourgeholme requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(20,13118,0,8,13104,'Quest mark for The Purging Of Scourgeholme requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(19,13118,1,8,13105,'Accepting The Purging Of Scourgeholme requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
(20,13118,1,8,13105,'Quest mark for The Purging Of Scourgeholme requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
-- The Restless Dead 13110
(19,13110,0,8,13104,'Accepting The Restless Dead requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(20,13110,0,8,13104,'Quest mark for The Restless Dead requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(19,13110,1,8,13105,'Accepting The Restless Dead requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
(20,13110,1,8,13105,'Quest mark for The Restless Dead requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
-- The Stone That Started A Revolution 13130
(19,13130,0,8,13104,'Accepting The Stone That Started A Revolution requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(20,13130,0,8,13104,'Quest mark for The Stone That Started A Revolution requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(19,13130,1,8,13105,'Accepting The Stone That Started A Revolution requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
(20,13130,1,8,13105,'Quest mark for The Stone That Started A Revolution requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
-- It Could Kill Us All 13135
(19,13135,0,8,13104,'Accepting It Could Kill Us All requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(20,13135,0,8,13104,'Quest mark for It Could Kill Us All requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(19,13135,1,8,13105,'Accepting It Could Kill Us All requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
(20,13135,1,8,13105,'Quest mark for It Could Kill Us All requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
-- The Scourgestone 13122
(19,13122,0,8,13104,'Accepting The Scourgestone requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(20,13122,0,8,13104,'Quest mark for The Scourgestone requires Once More Unto The Breach, Hero (DK only) to be rewarded'),
(19,13122,1,8,13105,'Accepting The Scourgestone requires Once More Unto The Breach, Hero (Non-DK) to be rewarded'),
(20,13122,1,8,13105,'Quest mark for The Scourgestone requires Once More Unto The Breach, Hero (Non-DK) to be rewarded');

-- Handled in a different way now...
UPDATE `quest_template` SET `PrevQuestId`=0 WHERE `Id` IN (13118,13122,13110,13130,13135,13125);

-- The Purging Of Scourgeholme 13118 / The Scourgestone 13122
UPDATE `quest_template` SET `NextQuestId`=13125,`ExclusiveGroup`=-13125 WHERE `Id` IN (13118,13122);

-- The Restless Dead 13110 / The Stone That Started A Revolution 13130 / It Could Kill Us All 13135 / The Air Stands Still 13125
UPDATE `quest_template` SET `NextQuestId`=13139,`ExclusiveGroup`=-13139 WHERE `Id` IN (13110,13130,13135,13125);
