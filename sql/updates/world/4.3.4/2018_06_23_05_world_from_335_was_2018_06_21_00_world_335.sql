/*
-- 
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID` IN
(118, -- Quest "The Price of Shoes"
119,  -- Quest "Return to Verner"
122,  -- Quest "Underbelly Scales"
126,  -- Quest "Howling in the Hills"
150,  -- Quest "Murloc Poachers"
127,  -- Quest "Selling Fish"
20,   -- Quest "Blackrock Menace"
131,  -- Quest "Delivering Daffodils"
129); -- Quest "A Free Lunch"

-- Quest "Blackrock Bounty"
DELETE FROM `quest_details` WHERE `ID`=128;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(128,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=128;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=128;

-- Quest "Tharil'zun"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=19;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=19;

-- Quest "Shadow Magic"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=115;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=115;

-- Quest "The Lost Tools"
DELETE FROM `quest_details` WHERE `ID`=125;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(125,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=125;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=125;

-- Quest "The Everstill Bridge"
DELETE FROM `quest_details` WHERE `ID`=89;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(89,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=89;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=89;

-- Quest "Hilary's Necklace"
DELETE FROM `quest_details` WHERE `ID`=3741;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3741,5,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=24, `EmoteOnComplete`=24 WHERE `ID`=3741;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=6 WHERE `ID`=3741;

-- Quest "Solomon's Law"
DELETE FROM `quest_details` WHERE `ID`=91;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(91,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=91;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=91;

-- Quest "Wanted: Gath'Ilzogg"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=169;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=169;

-- Quest "Messenger to Stormwind"
DELETE FROM `quest_details` WHERE `ID`=120;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(120,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=120;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=120;

-- Quest "Messenger to Stormwind (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=121;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(121,25,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=121;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=121;

-- Quest "Messenger to Westfall"
DELETE FROM `quest_details` WHERE `ID`=143;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(143,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=143;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=143;

-- Quest "Messenger to Westfall (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=144;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(144,1,25,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=144;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=144;

-- Quest "Messenger to Darkshire"
DELETE FROM `quest_details` WHERE `ID`=145;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(145,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=145;

-- Quest "Messenger to Darkshire (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=146;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(146,1,1,29,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=146;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6, `Emote3`=1 WHERE `ID`=146;

-- Quest "What Comes Around..."
DELETE FROM `quest_details` WHERE `ID`=386;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(386,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=386;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=386;

-- Quest "Wanted: Lieutenant Fangore"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=180;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2 WHERE `ID`=180;

-- Quest "Dry Times"
DELETE FROM `quest_details` WHERE `ID`=116;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(116,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=116;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=116;

-- Quest "Learn to Ride in Elwynn Forest / Dun Morogh / Orgrimmar / Eversong Woods / Darnassus / Tirisfal Glades / Mulgore / Durotar"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID` IN (14079,14081,14082,14083,14084,14085,14086,14087,14088,14089);

-- Quest "An Unwelcome Guest"
DELETE FROM `quest_details` WHERE `ID`=34;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(34,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=34;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=34;

-- Quest "Redridge Goulash"
DELETE FROM `quest_details` WHERE `ID`=92;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(92,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=92;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=92;

-- Quest "Missing In Action"
DELETE FROM `quest_details` WHERE `ID`=219;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(219,5,1,20,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=219;

-- Quest "Theocritus' Retrieval"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=178;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=178;

-- Quest "Morganth"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=249;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1, `Emote3`=2 WHERE `ID`=249;

-- Quest "Horns of Nez'ra"
DELETE FROM `quest_details` WHERE `ID`=2358;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2358,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=2358;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=2358;
*/
