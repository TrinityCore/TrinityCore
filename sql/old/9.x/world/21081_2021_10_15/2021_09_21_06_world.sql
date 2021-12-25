--
DELETE FROM `quest_template_addon` WHERE `ID` IN(37440, 37439);
INSERT INTO `quest_template_addon`(`ID`, `PrevQuestID`) VALUES 
(37440, 8326), -- A Fistful of Slivers
(37439, 8326); -- Thirst Unending

DELETE FROM `creature_queststarter` WHERE (`id`=15296 AND `quest`=37440) OR (`id`=15297 AND `quest`=37439);
INSERT INTO `creature_queststarter` (`id`, `quest`) VALUES
(15296, 37440), -- A Fistful of Slivers
(15297, 37439); -- Thirst Unending

DELETE FROM `creature_questender` WHERE (`id`=15296 AND `quest`=37440) OR (`id`=15297 AND `quest`=37439);
INSERT INTO `creature_questender` (`id`, `quest`) VALUES
(15296, 37440), -- A Fistful of Slivers
(15297, 37439); -- Thirst Unending

DELETE FROM `quest_request_items` WHERE `ID`=37439;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(37439, 0, 25, 0, 0, 'It is not an option or a choice... you must quench your magical thirst.  To fail in this is to fail as a blood elf.  Those who thought they could control their needs without tutoring now find themselves as one of the Wretched.$B$BYou do NOT want to end up as an insane addict.  Believe me.', 40120); -- Thirst Unending
