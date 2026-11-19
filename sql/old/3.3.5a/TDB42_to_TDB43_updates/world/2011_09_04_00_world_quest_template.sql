UPDATE `quest_template` SET `RequiredRaces`=1101 WHERE `entry` IN (4362,4363); -- The Fate of the Kingdom & The Princess's Surprise
UPDATE `quest_template` SET `NextQuestId`=4342 WHERE `entry`=4341; -- Kharan Mighthammer
UPDATE `quest_template` SET `PrevQuestId`=4341 WHERE `entry`=4342; -- Kharan's Tale
UPDATE `quest_template` SET `PrevQuestId`=4342 WHERE `entry`=4361; -- The Bearer of Bad News
UPDATE `quest_template` SET `PrevQuestId`=4361 WHERE `entry`=4362; -- The Fate of the Kingdom
UPDATE `quest_template` SET `PrevQuestId`=4362 WHERE `entry`=4363; -- The Princess's Surprise
