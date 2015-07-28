--
UPDATE `quest_template` SET `PrevQuestId`=25126 WHERE `Id`=25172;
DELETE FROM `creature_queststarter` WHERE `id` IN (3098, 39317);
UPDATE `creature_template` SET `npcflag`=`npcflag` &~2 WHERE `entry` IN (3098, 39317);
