DELETE FROM `quest_offer_reward` WHERE `ID` IN (26968 /*Arcane Missiles*/, 26969 /*Primal Strike*/, 26970 /*Aiding the Injured*/, 26963 /*Steadying Your Shot*/, 26958 /*Your First Lesson*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(26968, 1, 1, 0, 0, 0, 0, 0, 0, 'You\'ve mastered the use of this new spell quickly, $N. I only wish all of my students were as talented. Return to me when you find yourself in need of further training.', 60192), -- Arcane Missiles
(26969, 1, 1, 0, 0, 0, 0, 0, 0, 'It is a pleasure to teach such a capable student. As long as you continue the traditons faithfully, the shamanic arts will never be lost to our people again. Return to me when you need further training.', 60192), -- Primal Strike
(26970, 1, 1, 0, 0, 0, 0, 0, 0, 'You\'ll often find your skills as a healer in demand, $N. Do not hesitate to return when you need more training.', 60192), -- Aiding the Injured
(26963, 1, 1, 0, 0, 0, 0, 0, 0, 'Keep that technique handy, $N. I find myself using it all the time. Return when you\'re ready for further training.', 60192), -- Steadying Your Shot
(26958, 1, 1, 0, 0, 0, 0, 0, 0, 'Keep that technique handy, $N. I find myself using it all the time. Return when you\'re ready for further training.', 60192); -- Your First Lesson

UPDATE `quest_offer_reward` SET `Emote2`=0, `VerifiedBuild`=60192 WHERE `ID`=10302; -- Volatile Mutations
UPDATE `quest_offer_reward` SET `VerifiedBuild`=60192 WHERE `ID` IN (9371, 9409, 9280, 9283);
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=60192 WHERE `ID`=9279; -- You Survived!
UPDATE `quest_offer_reward` SET `Emote2`=0, `VerifiedBuild`=60192 WHERE `ID`=10302; -- Volatile Mutations
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=60192 WHERE `ID`=9279; -- You Survived!
UPDATE `quest_offer_reward` SET `Emote2`=0, `VerifiedBuild`=60192 WHERE `ID`=10302; -- Volatile Mutations
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=60192 WHERE `ID`=9279; -- You Survived!
UPDATE `quest_offer_reward` SET `Emote2`=0, `VerifiedBuild`=60192 WHERE `ID`=10302; -- Volatile Mutations
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=60192 WHERE `ID`=9279; -- You Survived!
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `VerifiedBuild`=60192 WHERE `ID`=26966; -- The Light's Power
UPDATE `quest_offer_reward` SET `Emote2`=0, `VerifiedBuild`=60192 WHERE `ID`=10302; -- Volatile Mutations
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=60192 WHERE `ID`=9279; -- You Survived!
UPDATE `quest_offer_reward` SET `Emote2`=0, `VerifiedBuild`=60192 WHERE `ID`=10302; -- Volatile Mutations
UPDATE `quest_offer_reward` SET `EmoteDelay2`=1000, `VerifiedBuild`=60192 WHERE `ID`=9279; -- You Survived!

DELETE FROM `quest_details` WHERE `ID` IN (26968 /*Arcane Missiles*/, 9279 /*You Survived!*/, 26969 /*Primal Strike*/, 26970 /*Aiding the Injured*/, 26963 /*Steadying Your Shot*/, 26966 /*The Light's Power*/, 26958 /*Your First Lesson*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(26968, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- Arcane Missiles
(9279, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- You Survived!
(26969, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- Primal Strike
(26970, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- Aiding the Injured
(26963, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- Steadying Your Shot
(26966, 1, 1, 0, 0, 0, 0, 0, 0, 60192), -- The Light's Power
(26958, 1, 1, 0, 0, 0, 0, 0, 0, 60192); -- Your First Lesson

UPDATE `quest_details` SET `VerifiedBuild`=60192 WHERE `ID` IN (9293, 10302, 9371, 9283, 9409, 9280, 9799);

DELETE FROM `quest_request_items` WHERE `ID` IN (26970 /*Aiding the Injured*/, 26969 /*Primal Strike*/, 26968 /*Arcane Missiles*/, 26963 /*Steadying Your Shot*/, 26958 /*Your First Lesson*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(26970, 0, 1, 0, 0, 'Have you seen to the wounds of the crash survivors?', 60192), -- Aiding the Injured
(26969, 0, 1, 0, 0, 'Have you familiarized yourself with Primal Strike?', 60192), -- Primal Strike
(26968, 0, 1, 0, 0, 'Have you practiced your charge?', 60192), -- Arcane Missiles
(26963, 0, 1, 0, 0, 'Have you gotten a feel for the shot that I showed you?', 60192), -- Steadying Your Shot
(26958, 0, 1, 0, 0, 'Have you practiced your charge?', 60192); -- Your First Lesson

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=1, `VerifiedBuild`=60192 WHERE `ID`=9283; -- Rescue the Survivors!
UPDATE `quest_request_items` SET `VerifiedBuild`=60192 WHERE `ID` IN (9280, 10302);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `VerifiedBuild`=60192 WHERE `ID`=26966; -- The Light's Power
UPDATE `creature_queststarter` SET `VerifiedBuild`=60192 WHERE (`id`=16500 AND `quest`=26968) OR (`id`=16514 AND `quest` IN (9293,10302)) OR (`id`=16477 AND `quest` IN (9371,9409,9280)) OR (`id`=16502 AND `quest` IN (9283,26970)) OR (`id`=16475 AND `quest`=9279) OR (`id`=17089 AND `quest`=26969) OR (`id`=20233 AND `quest`=9799) OR (`id`=16499 AND `quest`=26963) OR (`id`=16501 AND `quest`=26966) OR (`id`=16503 AND `quest`=26958);
UPDATE `creature_questender` SET `VerifiedBuild`=60192 WHERE (`id`=16500 AND `quest`=26968) OR (`id`=16514 AND `quest` IN (10302,9371,9293)) OR (`id`=16502 AND `quest` IN (9283,9409,26970)) OR (`id`=16477 AND `quest` IN (9280,9279)) OR (`id`=17089 AND `quest`=26969) OR (`id`=16499 AND `quest`=26963) OR (`id`=16501 AND `quest`=26966) OR (`id`=16503 AND `quest`=26958) OR (`id`=20233 AND `quest`=9799);
