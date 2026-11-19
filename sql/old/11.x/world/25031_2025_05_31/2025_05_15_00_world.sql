-- Quest
DELETE FROM `quest_details` WHERE `ID`=47961;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47961, 0, 0, 0, 0, 0, 0, 0, 0, 60822); -- Drustvar

DELETE FROM `creature_questender` WHERE (`id`=121235 AND `quest`=47961);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(121235, 47961, 60822); -- Drustvar ended by Taelia
