/*
-- Battle of Hillsbrad (7) Progress gossip text (missing)
DELETE FROM `quest_request_items` WHERE `ID`=14351;
INSERT INTO `quest_request_items` (`ID`,`EmoteOnComplete`,`EmoteOnIncomplete`,`CompletionText`,`VerifiedBuild`) VALUES
(14351, 1, 0, "Why aren't you out on the battlefield, $c?", 12340);

-- Battle of Hillsbrad (7) Reward gossip text (missing)
DELETE FROM `quest_offer_reward` WHERE `ID`=14351;
INSERT INTO `quest_offer_reward` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`RewardText`,`VerifiedBuild`) VALUES
(14351, 0, 0, 0, 0, 0, 0, 0, 0, "So you're the $c who tore through the Alliance forces in the Hillsbrad Foothills? I've heard your name already. Word travels fast.$B$BThe Horde can use someone like you if you keep this up, $N.$B$BWe need to keep our eyes on all threats around us, but with that king leading them, the humans will continue to be a problem. You've confirmed that there's strength enough in the Horde to end that threat in time.", 12340);
*/

