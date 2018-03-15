/*
-- Quest "Escorting Erland"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=435;

-- Quest "Return to Quinn"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=430;

-- Quest "Ivar the Foul"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=425;

-- Quest "Wand to Bethor"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=491;

-- Quest "Supplying the Sepulcher"
DELETE FROM `quest_details` WHERE `ID`=6321;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6321,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6321;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6321;

-- Quest "Ride to the Undercity"
DELETE FROM `quest_details` WHERE `ID`=6323;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6323,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6323;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6323;

-- Quest "Michael Garrett"
DELETE FROM `quest_details` WHERE `ID`=6322;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6322,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=6322;

-- Quest "Return to Podrig"
DELETE FROM `quest_details` WHERE `ID`=6324;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6324,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6324;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6324;

-- Quest "The Deathstalkers' Report"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=449;

-- Quest "Speak with Renferrel"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3221;

-- Quest "Delivery to Silverpine Forest"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=445;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=445;

-- Quest "Zinge's Delivery"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1359;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1359;

-- Quest "Sample for Helbrim"
DELETE FROM `quest_details` WHERE `ID`=1358;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1358,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1358;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1358;

-- Quest "The Dead Fields"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=437;

-- Quest "Rot Hide Clues"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=439;

-- Quest "Rot Hide Ichor"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=443;

-- Quest "Rot Hide Origins"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=444;

-- Quest "Thule Ravenclaw"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=446;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=446;

-- Quest "Assault on Fenris Isle"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=442;

-- Quest "The Engraved Ring"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=440;

-- Quest "Raleigh and the Undercity"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=441;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=441;

-- Quest "A Husband's Revenge"
DELETE FROM `quest_details` WHERE `ID`=530;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(530,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=530;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=530;

-- Quest "Prove Your Worth"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=421;

-- Quest "Arugal's Folly"
DELETE FROM `quest_details` WHERE `ID`=422;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(422,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=422;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=422;

-- Quest "Arugal's Folly (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=423;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=423;

-- Quest "Arugal's Folly (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=424;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(424,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=424;

-- Quest "Arugal's Folly (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=99;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(99,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=99;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=99;

-- Quest "Maps and Runes"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=478;

-- Quest "Dalar's Analysis"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=481;

-- Quest "Ambermill Investigations"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=479;

-- Quest "The Weaver"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=480;

-- Quest "A Recipe For Death"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=66, `EmoteOnComplete`=66 WHERE `ID`=447;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=447;

-- Quest "A Recipe For Death (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=450;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(450,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=450;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=450;

-- Quest "A Recipe For Death (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=451;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(451,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=451;

-- Quest "Arugal Must Die"
DELETE FROM `quest_details` WHERE `ID`=1014;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1014,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=1014;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1014;

-- Quest "Journey to Hillsbrad Foothills"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=493;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=493;

-- Quest "Time To Strike"
DELETE FROM `quest_details` WHERE `ID`=494;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(494,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=494;

-- Quest "Helcular's Revenge"
DELETE FROM `quest_details` WHERE `ID`=552;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(552,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=552;

-- Quest "Helcular's Revenge (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=553;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(553,1,0,0,0,0,0,0,0,0);

-- Quest "Battle of Hillsbrad"
DELETE FROM `quest_details` WHERE `ID`=527;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(527,25,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=527;

-- Quest "Battle of Hillsbrad (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=528;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(528,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=528;

-- Quest "Battle of Hillsbrad (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=529;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(529,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=529;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=529;

-- Quest "Battle of Hillsbrad (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=532;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(532,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=532;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=532;

-- Quest "Battle of Hillsbrad (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=539;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(539,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=539;

-- Quest "Battle of Hillsbrad (Part 6)"
DELETE FROM `quest_details` WHERE `ID`=541;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(541,6,5,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=541;

-- Quest "Battle of Hillsbrad (Part 7)"
DELETE FROM `quest_details` WHERE `ID`=14351;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14351,1,66,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=14351;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=14351;

-- Quest "Bracers of Binding"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=557;

-- Quest "Frostmaw"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1136;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1136;

-- Quest "The Rescue"
DELETE FROM `quest_details` WHERE `ID`=498;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(498,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1 WHERE `ID`=498;

-- Quest "Infiltration"
DELETE FROM `quest_details` WHERE `ID`=533;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(533,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=533;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=533;

-- Quest "Gol'dir"
DELETE FROM `quest_details` WHERE `ID`=503;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(503,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=503;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=503;

-- Quest "Blackmoore's Legacy"
DELETE FROM `quest_details` WHERE `ID`=506;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(506,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=506;

-- Quest "Lord Aliden Perenolde"
DELETE FROM `quest_details` WHERE `ID`=507;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(507,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=20 WHERE `ID`=507;

-- Quest "Taretha's Gift"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=508;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=508;

-- Quest "WANTED: Syndicate Personnel"
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=549;

-- Quest "WANTED: Baron Vardus"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=566;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=566;

-- Quest "Dangerous!"
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=567;

-- Quest "Souvenirs of Death"
DELETE FROM `quest_details` WHERE `ID`=546;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(546,1,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=546;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=546;

-- Quest "Humbert's Sword"
DELETE FROM `quest_details` WHERE `ID`=547;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(547,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=547;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=547;

-- Quest "Soothing Turtle Bisque"
DELETE FROM `quest_details` WHERE `ID`=7321;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7321,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7321;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7321;

-- Quest "Elixir of Suffering"
DELETE FROM `quest_details` WHERE `ID`=496;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(496,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=496;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=496;

-- Quest "Elixir of Suffering (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=499;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(499,1,11,0,0,0,0,0,0,0);

-- Quest "Elixir of Pain"
DELETE FROM `quest_details` WHERE `ID`=501;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(501,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=501;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=501;

-- Quest "Elixir of Pain (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=502;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(502,5,1,11,0,0,0,0,0,0);

-- Quest "Elixir of Agony"
DELETE FROM `quest_details` WHERE `ID`=509;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(509,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=509;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11 WHERE `ID`=509;

-- Quest "Elixir of Agony (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=513;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(513,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=513;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=513;

-- Quest "Elixir of Agony (Part 3)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=515;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=515;

-- Quest "Elixir of Agony (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=517;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(517,1,1,11,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=517;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=517;

-- Quest "Elixir of Agony (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=524;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(524,1,1,11,0,0,0,0,0,0);
*/
