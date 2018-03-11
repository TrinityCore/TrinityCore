-- Emotes for Quest "For Love Eternal"
DELETE FROM `quest_details` WHERE `ID`=963;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(963,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=963;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=963;

-- Emotes for Quest "Cave Mushrooms"
DELETE FROM `quest_details` WHERE `ID`=947;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(947,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6  WHERE `ID`=947;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=947;

-- Emotes for Quest "Onu"
DELETE FROM `quest_details` WHERE `ID`=948;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(948,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "Buzzbox 827"
DELETE FROM `quest_details` WHERE `ID`=983;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(983,5,0,0,0,0,0,0,0,0);

-- Emotes for Quest "Washed Ashore"
DELETE FROM `quest_details` WHERE `ID`=3524;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3524,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3524;

-- Emotes for Quest "Washed Ashore (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4681;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4681,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4681;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4681;

-- Emotes for Quest "The Family and the Fishing Pole"
DELETE FROM `quest_details` WHERE `ID`=1141;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1141,4,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1141;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1141;

-- Emotes for Quest "Fruit of the Sea"
DELETE FROM `quest_details` WHERE `ID`=1138;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1138,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1138;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=1138;

-- Emotes for Quest "The Red Crystal"
DELETE FROM `quest_details` WHERE `ID`=4811;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4811,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=4811;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4811;

-- Emotes for Quest "As Water Cascades"
DELETE FROM `quest_details` WHERE `ID`=4812;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4812,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "The Fragments Within"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=4813;

-- Emotes for Quest "Tools of the Highborne"
DELETE FROM `quest_details` WHERE `ID`=958;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(958,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=958;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=958;

-- Emotes for Quest "BashalAran"
DELETE FROM `quest_details` WHERE `ID`=954;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(954,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=954;

-- Emotes for Quest "BashalAran (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=955;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(955,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "BashalAran (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=956;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(956,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=956;

-- Emotes for Quest "BashalAran (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=957;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(957,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=15 WHERE `ID`=957;

-- Emotes for Quest "Beached Sea Creature"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=4723;

-- Emotes for Quest "Beached Sea Creature"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=4728;

-- Emotes for Quest "Beached Sea Creature"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=4730;

-- Emotes for Quest "Beached Sea Turtle"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=4722;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4722;

-- Emotes for Quest "Beached Sea Turtle"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=4727;

-- Emotes for Quest "Beached Sea Turtle"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=4731;

-- Emotes for Quest "WANTED: Murkdeep!"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=4740;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4740;

-- Emotes for Quest "Gaffer Jacks"
DELETE FROM `quest_details` WHERE `ID`=1579;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1579,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1579;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=1579;

-- Emotes for Quest "Electropellers"
DELETE FROM `quest_details` WHERE `ID`=1580;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1580,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1580;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1580;

-- Emotes for Quest "Trouble In Darkshore?"
DELETE FROM `quest_details` WHERE `ID`=730;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(730,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=730;

-- Emotes for Quest "The Absent Minded Prospector"
DELETE FROM `quest_details` WHERE `ID`=729;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(729,1,1,20,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=729;

-- Emotes for Quest "The Absent Minded Prospector (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=731;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(731,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=731;

-- Emotes for Quest "The Absent Minded Prospector (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=741;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(741,6,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=741;

-- Emotes for Quest "The Absent Minded Prospector (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=942;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(942,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=942;

-- Emotes for Quest "The Absent Minded Prospector (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=943;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(943,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=943;

-- Emotes for Quest "Deep Ocean, Vast Sea"
DELETE FROM `quest_details` WHERE `ID`=982;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(982,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=982;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=982;

-- Emotes for Quest "Plagued Lands"
DELETE FROM `quest_details` WHERE `ID`=2118;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2118,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=2118;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2118;

-- Emotes for Quest "Cleansing of the Infected"
DELETE FROM `quest_details` WHERE `ID`=2138;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2138,274,0,0,0,0,0,0,0,0);

-- Emotes for Quest "Tharnariun's Hope"
DELETE FROM `quest_details` WHERE `ID`=2139;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2139,1,0,0,0,0,0,0,0,0);

-- Emotes for Quest "How Big a Threat?"
DELETE FROM `quest_details` WHERE `ID`=984;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(984,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=18 WHERE `ID`=984;

-- Emotes for Quest "How Big a Threat? (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=985;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(985,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=985;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=985;

-- Emotes for Quest "A Lost Master (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=993;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(993,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=993;

-- Emotes for Quest "Escape Through Force"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=994;

-- Emotes for Quest "Escape Through Stealth"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=995;

-- Emotes for Quest "Thundris Windweaver"
DELETE FROM `quest_details` WHERE `ID`=4761;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4761,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4761;

-- Emotes for Quest "The Cliffspring River"
DELETE FROM `quest_details` WHERE `ID`=4762;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4762,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4762;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=4762;

-- Emotes for Quest "The Blackwood Corrupted"
DELETE FROM `quest_details` WHERE `ID`=4763;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4763,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4763;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4763;

-- Emotes for Quest "Easy Strider Living"
DELETE FROM `quest_details` WHERE `ID`=2178;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2178,273,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=2178;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2178;

-- Emotes for Quest "The Tower of Althalaxx"
DELETE FROM `quest_details` WHERE `ID`=965;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(965,2,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=965;

-- Emotes for Quest "The Tower of Althalaxx (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=966;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(966,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=966;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=966;

-- Emotes for Quest "The Tower of Althalaxx (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=967;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(967,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=967;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=967;

-- Emotes for Quest "The Tower of Althalaxx (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=970;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(970,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=970;

-- Emotes for Quest "The Tower of Althalaxx (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=973;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(973,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=973;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=973;

-- Emotes for Quest "The Tower of Althalaxx (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=1140;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1140,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1140;

-- Emotes for Quest "The Tower of Althalaxx (Part 7)"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=1167;

-- Emotes for Quest "The Tower of Althalaxx (Part 8)"
DELETE FROM `quest_details` WHERE `ID`=1143;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1143,273,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1143;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1143;

-- Emotes for Quest "The Tower of Althalaxx (Part 9)"
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=981;

-- Emotes for Quest "Gyromast's Retrieval"
DELETE FROM `quest_details` WHERE `ID`=2098;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2098,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2098;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2098;

-- Emotes for Quest "Gyromast's Revenge"
DELETE FROM `quest_details` WHERE `ID`=2078;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2078,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=397 WHERE `ID`=2078;

-- Emotes for Quest "The Fall of Ameth'Aran"
DELETE FROM `quest_details` WHERE `ID`=953;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(953,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=953;

-- Emotes for Quest "One Shot.  One Kill"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=5713;

-- Emotes for Quest "The Powers Below"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=968;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=968;

-- Emotes for Quest "The Sleeper Has Awakened"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5321;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5321;

-- Emotes for Quest "Onward to Ashenvale"
DELETE FROM `quest_details` WHERE `ID`=10752;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10752,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=10752;

-- Emotes for Quest "Trek to Ashenvale"
DELETE FROM `quest_details` WHERE `ID`=990;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(990,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=990;
