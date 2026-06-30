-- Journey to Undercity (9180)
DELETE FROM `quest_details` WHERE `ID`=9180;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9180,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9180;
UPDATE `quest_offer_reward` SET `Emote1`=396 WHERE `ID`=9180;

-- The Lady's Necklace (9175)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9175;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9175;

-- Deactivate An'owyn (9169)
DELETE FROM `quest_details` WHERE `ID`=9169;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9169,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9169;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=2 WHERE `ID`=9169;

-- Deliver the Plans to An'telas (9166)
DELETE FROM `quest_details` WHERE `ID`=9166;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9166,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=5 WHERE `ID`=9166;

-- Windrunner Village (9140)
DELETE FROM `quest_details` WHERE `ID`=9140;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9140,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=9140;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=9140;

-- Into Occupied Territory (9163)
DELETE FROM `quest_details` WHERE `ID`=9163;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9163,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=9163;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9163;

-- Underlight Ore Samples (9207)
DELETE FROM `quest_details` WHERE `ID`=9207;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9207,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9207;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9207;

-- Assault on Zeb'Nowa (9277)
DELETE FROM `quest_details` WHERE `ID`=9277;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9277,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9277;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1 WHERE `ID`=9277;

-- Bring Me Kel'gash's Head! (9215)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=9215;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9215;

-- Attack on Zeb'Tela (9276)
DELETE FROM `quest_details` WHERE `ID`=9276;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9276,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9276;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9276;

-- A Little Dash of Seasoning (9275)
DELETE FROM `quest_details` WHERE `ID`=9275;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9275,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9275;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1 WHERE `ID`=9275;

-- Shadowpine Weaponry (9214)
DELETE FROM `quest_details` WHERE `ID`=9214;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9214,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=9214;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9214;

-- Report to Captain Helios (9146)
DELETE FROM `quest_details` WHERE `ID`=9146;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9146,6,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9146;

-- Dealing with Zeb'Sora (9143)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9143;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9143;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9143;

-- Goldenmist Village (9139)
DELETE FROM `quest_details` WHERE `ID`=9139;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9139,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9139;

-- Culinary Crunch (9171)
DELETE FROM `quest_details` WHERE `ID`=9171;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9171,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=9171;

-- Retaking Windrunner Spire (9173)
DELETE FROM `quest_details` WHERE `ID`=9173;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9173,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9173;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9173;

-- Trouble at the Underlight Mines (9192)
DELETE FROM `quest_details` WHERE `ID`=9192;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9192,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9192;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9192;

-- Investigate An'daroth (9160)
DELETE FROM `quest_details` WHERE `ID`=9160;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9160,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9160;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9160;

-- Help Ranger Valanna! (9145)
DELETE FROM `quest_details` WHERE `ID`=9145;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9145,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9145;

-- The Sad Truth (10548)
DELETE FROM `quest_details` WHERE `ID`=10548;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10548,1,5,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=5 WHERE `ID`=10548;

-- Tomber's Supplies (9152)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9152;

-- Return the Reports (9618)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9618;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=5,`Emote3`=1 WHERE `ID`=9618;

-- Combining Forces (9460)
DELETE FROM `quest_details` WHERE `ID`=9460;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9460,66,6,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6,`EmoteOnComplete`=6 WHERE `ID`=9460;
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=25 WHERE `ID`=9460;

-- Anok'suten (9315)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=9315;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9315;

-- Escape from the Catacombs (9212)
DELETE FROM `quest_details` WHERE `ID`=9212;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9212,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9212;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9212;

-- Return to Quartermaster Lymel (9135)
DELETE FROM `quest_details` WHERE `ID`=9135;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9135,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9135;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9135;

-- Skymistress Gloaming (9134)
DELETE FROM `quest_details` WHERE `ID`=9134;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9134,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9134;
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=1 WHERE `ID`=9134; 

-- Suncrown Village (9138)
DELETE FROM `quest_details` WHERE `ID`=9138;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9138,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9138; 

-- Return to Arcanist Vandril (9758)
DELETE FROM `quest_details` WHERE `ID`=9758;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9758,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9758; 

-- Fly to Silvermoon City (9133)
DELETE FROM `quest_details` WHERE `ID`=9133;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9133,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=6 WHERE `ID`=9133; 

-- Goods from Silvermoon City (9130)
DELETE FROM `quest_details` WHERE `ID`=9130;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9130,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9130;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9130; 

-- Troll Juju (9199)
DELETE FROM `quest_details` WHERE `ID`=9199;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9199,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9199; 

-- Investigate the Amani Catacombs (9193)
DELETE FROM `quest_details` WHERE `ID`=9193;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9193,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9193; 

-- Greed (9491)
DELETE FROM `quest_details` WHERE `ID`=9491;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9491,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=5 WHERE `ID`=9491; 

-- The Forsaken (9327)
DELETE FROM `quest_details` WHERE `ID`=9327;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9327,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9327;
