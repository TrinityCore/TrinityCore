UPDATE `quest_template` SET `PrevQuestId`=28735 WHERE `id`=28737;
UPDATE `quest_template` SET `PrevQuestId`=28735 WHERE `id`=28738;
UPDATE `quest_template` SET `PrevQuestId`=28735 WHERE `id`=28740;
UPDATE `quest_template` SET `PrevQuestId`=28735 WHERE `id`=28741;

DELETE FROM `creature_queststarter` WHERE `id` IN (49526,49529,49530,49531);
DELETE FROM `creature_queststarter` WHERE `id`=49476 AND `quest` IN (28737,28738,28740,28741);
INSERT INTO `creature_queststarter` (`id`,`quest`) VALUES
(49476,28737),(49476,28738),(49476,28740),(49476,28741);
