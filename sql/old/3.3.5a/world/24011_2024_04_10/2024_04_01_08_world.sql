-- Allegiance to the Horde
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9627;

-- Meeting the Warchief
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9626;

-- Hidden Enemies (5730)
DELETE FROM `quest_details` WHERE `ID`=5730;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5730,6,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=4 WHERE `ID`=5730;

-- Hidden Enemies (5729)
DELETE FROM `quest_details` WHERE `ID`=5729;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5729,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=2 WHERE `ID`=5729;

-- Hidden Enemies (5728)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5728;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1 WHERE `ID`=5728;

-- Hidden Enemies (5727)
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=5727;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5727;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=5727;

-- Hidden Enemies (5726)
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=5726;
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=5726;

-- Slaying the Beast
DELETE FROM `quest_details` WHERE `ID`=5761;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(5761,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=5761;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1 WHERE `ID`=5761;

-- Hinott's Assistance
DELETE FROM `quest_details` WHERE `ID`=2479;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2479,1,1,0,0,0,0,0,0,0);

-- Deep Cover
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=2458;

-- The Shattered Salute
DELETE FROM `quest_details` WHERE `ID`=2460;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2460,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5,`EmoteOnIncomplete`=5 WHERE `ID`=2460;

-- Rogues of the Shattered Hand
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=1 WHERE `ID`=10794;

-- Find the Shattered Hand
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2378;

-- The Admiral's Orders
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=831;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=831;

-- Burning Shadows
UPDATE `quest_request_items` SET `EmoteOnComplete`=2,`EmoteOnComplete`=2 WHERE `ID`=832;
UPDATE `quest_offer_reward` SET `Emote2`=2,`EmoteDelay1`=0 WHERE `ID`=832;

-- Finding the Antidote
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=813;

-- Need for a Cure
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=812;

-- Margoz
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=828;

-- Dark Storms
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=806;

-- Securing the Lines
UPDATE `quest_details` SET `Emote3`=6 WHERE `ID`=835;

-- Lost But Not Forgotten
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=20 WHERE `ID`=816;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=816;

-- Break a Few Eggs
UPDATE `quest_request_items` SET `EmoteOnComplete`=1,`EmoteOnIncomplete`=1 WHERE `ID`=815;

-- The Admiral's Orders
DELETE FROM `quest_details` WHERE `ID`=831;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(831,1,5,0,0,0,0,0,0,0);

-- From The Wreckage....
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=825;

-- Vanquish the Betrayers
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=784;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=784;

-- A Solvent Spirit
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=4 WHERE `ID`=818;

-- Practical Prey
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=817;
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote4`=4 WHERE `ID`=817;

-- Thwarting Kolkar Aggression
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=786;

-- Your Place In The World
UPDATE `quest_offer_reward` SET `Emote3`=1,`Emote4`=4 WHERE `ID`=4641;
