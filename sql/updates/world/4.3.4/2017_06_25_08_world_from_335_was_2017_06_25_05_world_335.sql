-- 
/*
DELETE FROM `quest_details` WHERE `ID` IN (363, 3901,3098,3099,6395,380, 3902,381, 382, 365, 427, 367, 368, 369, 5482,590, 1881, 370, 371, 374, 405, 1478,1473,1471);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES 
(363, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(3901, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(3098, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(3099, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(6395, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(380, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(3902, 5, 0, 0, 0, 0, 0, 0, 0, 0),
(381, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(382, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(365, 6, 1, 0, 0, 0, 0, 0, 0, 0),
(427, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(367, 1, 1, 0, 0, 0, 0, 0, 0, 0),
(368, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(369, 1, 1, 0, 0, 0, 0, 0, 0, 0),
(5482, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(590, 6, 1, 14, 0, 0, 0, 0, 0, 0),
(1881, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(370, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(371, 5, 0, 0, 0, 3000, 0, 0, 0, 0),
(374, 1, 1, 0, 0, 0, 0, 0, 0, 0),
(405, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(1478, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(1473, 1, 0, 0, 0, 0, 0, 0, 0, 0),
(1471, 1, 0, 0, 0, 0, 0, 0, 0, 0);

UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=363;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3901;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3098;
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3099;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3099;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=376;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=376;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6395;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=380;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3902;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=381;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=382;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=365;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=365;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=383;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=427;
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=367;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=367;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=368;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=368;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=369;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=369;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5481;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=5481;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5482;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5482;
UPDATE `quest_offer_reward` SET `Emote1`=15 WHERE `ID`=590;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=354;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=362;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1881;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=370;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=371;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=372;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=375;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=375;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=426;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=374;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=374;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=398;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=398;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=358;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=405;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=359;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=408;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=357;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1478;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=409;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=411;
*/

