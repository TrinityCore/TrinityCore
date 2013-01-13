-- Do your worst
UPDATE `quest_template` SET `PrevQuestId`=13393 WHERE `Id`=13394;
-- Where dragons fell
UPDATE `quest_template` SET `PrevQuestId`=13397 WHERE `Id`=13398;
-- Argent aid
UPDATE `quest_template` SET `PrevQuestId`=13362 WHERE `Id`=13363;
-- Where dragons fell
UPDATE `quest_template` SET `PrevQuestId`=13349 WHERE `Id`=13359;
-- Time for answers
UPDATE `quest_template` SET `PrevQuestId`=13359 WHERE `Id`=13360;
-- Do your worst 
UPDATE `quest_template` SET `PrevQuestId`=13304 WHERE `Id`=13305;
-- A short fuse
UPDATE `quest_template` SET `NextQuestId`=13168 WHERE `Id` IN (13389,13263);
-- Several quest group conditions...
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13172,13174);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(19,13172,0,8,13169,'Accepting Seeds of Chaos requires An Undeads Best Friend to be rewarded'),
(19,13172,1,8,13170,'Accepting Seeds of Chaos requires Honor is for the Weak to be rewarded'),
(19,13172,2,8,13171,'Accepting Seeds of Chaos requires From Whence They Came to be rewarded'),
(20,13172,0,8,13169,'Seeing quest mark for Seeds of Chaos requires An Undeads Best Friend to be rewarded'),
(20,13172,1,8,13170,'Seeing quest mark for Seeds of Chaos requires Honor is for the Weak to be rewarded'),
(20,13172,2,8,13171,'Seeing quest mark for Seeds of Chaos requires From Whence They Came to be rewarded'),
(19,13174,0,8,13169,'Accepting Amidst the Confusion requires An Undeads Best Friend to be rewarded'),
(19,13174,1,8,13170,'Accepting Amidst the Confusion requires Honor is for the Weak to be rewarded'),
(19,13174,2,8,13171,'Accepting Amidst the Confusion requires From Whence They Came to be rewarded'),
(20,13174,0,8,13169,'Seeing quest mark for Amidst the Confusion requires An Undeads Best Friend to be rewarded'),
(20,13174,1,8,13170,'Seeing quest mark for Amidst the Confusion requires Honor is for the Weak to be rewarded'),
(20,13174,2,8,13171,'Seeing quest mark for Amidst the Confusion requires From Whence They Came to be rewarded');
-- Seeds of Chaos / Admist the Confusion
UPDATE `quest_template` SET `NextQuestId`=13155,`ExclusiveGroup`=-13155 WHERE `Id` IN (13172,13174);
-- Generosity Abounds / Matchmaker / Stunning View
UPDATE `quest_template` SET `PrevQuestId`=13145 WHERE `Id` IN (13146,13160,13147);
-- Several quest group conditions...
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13161,13163,13162);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(19,13161,0,8,13146,'Accepting The Rider of the Unholy requires Generosity Abounds to be rewarded'),
(19,13161,1,8,13160,'Accepting The Rider of the Unholy requires Stunning View to be rewarded'),
(19,13161,2,8,13147,'Accepting The Rider of the Unholy requires Matchmaker to be rewarded'),
(20,13161,0,8,13146,'Seeing quest mark for The Rider of the Unholy requires Generosity Abounds to be rewarded'),
(20,13161,1,8,13160,'Seeing quest mark for The Rider of the Unholy requires Stunning View to be rewarded'),
(20,13161,2,8,13147,'Seeing quest mark for The Rider of the Unholy requires Matchmaker to be rewarded'),
(19,13163,0,8,13146,'Accepting The Rider of Blood requires Generosity Abounds to be rewarded'),
(19,13163,1,8,13160,'Accepting The Rider of Blood requires Stunning View to be rewarded'),
(19,13163,2,8,13147,'Accepting The Rider of Blood requires Matchmaker to be rewarded'),
(20,13163,0,8,13146,'Seeing quest mark for The Rider of Blood requires Generosity Abounds to be rewarded'),
(20,13163,1,8,13160,'Seeing quest mark for The Rider of Blood requires Stunning View to be rewarded'),
(20,13163,2,8,13147,'Seeing quest mark for The Rider of Blood requires Matchmaker to be rewarded'),
(19,13162,0,8,13146,'Accepting The Rider of Frost requires Generosity Abounds to be rewarded'),
(19,13162,1,8,13160,'Accepting The Rider of Frost requires Stunning View to be rewarded'),
(19,13162,2,8,13147,'Accepting The Rider of Frost requires Matchmaker to be rewarded'),
(20,13162,0,8,13146,'Seeing quest mark for The Rider of Frost requires Generosity Abounds to be rewarded'),
(20,13162,1,8,13160,'Seeing quest mark for The Rider of Frost requires Stunning View to be rewarded'),
(20,13162,2,8,13147,'Seeing quest mark for The Rider of Frost requires Matchmaker to be rewarded');
-- The Rider of Blood / ... Frost / ... the Unholy
UPDATE `quest_template` SET `NextQuestId`=13164,`ExclusiveGroup`=-13164 WHERE `Id` IN (13161,13163,13162);
-- Where Are They Coming From?
UPDATE `quest_template` SET `PrevQuestId`=13106 WHERE `Id`=13117;
-- Destroying the Altars / Death's Gaze
UPDATE `quest_template` SET `PrevQuestId`=13117,`NextQuestId`=13134,`ExclusiveGroup`=-13134 WHERE `Id` IN (13119,13120);
-- Jagged Shards
UPDATE `quest_template` SET `PrevQuestId`=13134 WHERE `Id`=13136;
-- Several quest group conditions...
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (19,20) AND `SourceEntry` IN (13211,13152);
INSERT INTO `conditions`(`SourceTypeOrReferenceId`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionValue1`,`Comment`) VALUES
(19,13152,0,8,13140,'Accepting A Visit to the Doctor requires The Runesmiths of Malykriss to be rewarded'),
(19,13152,1,8,13138,'Accepting A Visit to the Doctor requires Im Smelting... Smelting! to be rewarded'),
(20,13152,0,8,13140,'Seeing quest mark for A Visit to the Doctor requires The Runesmiths of Malykriss to be rewarded'),
(20,13152,1,8,13138,'Seeing quest mark for A Visit to the Doctor requires Im Smelting... Smelting! to be rewarded'),
(19,13211,0,8,13140,'Accepting By Fire Be Purged requires The Runesmiths of Malykriss to be rewarded'),
(19,13211,1,8,13138,'Accepting By Fire Be Purged requires Im Smelting... Smelting! to be rewarded'),
(20,13211,0,8,13140,'Seeing quest mark for By Fire Be Purged requires The Runesmiths of Malykriss to be rewarded'),
(20,13211,1,8,13138,'Seeing quest mark for By Fire Be Purged requires Im Smelting... Smelting! to be rewarded');
-- A Visit to the Doctor / By Fire Be Purged
UPDATE `quest_template` SET `NextQuestId`=13144,`ExclusiveGroup`=-13144 WHERE `Id` IN (13211,13152);
-- Let's Get Out of Here! / Let's Get Out of Here / He's Gone to Pieces
UPDATE `quest_template` SET `PrevQuestId`=13144 WHERE `Id` IN (13481,13482,13212);
