/*
-- Quest "Assisting Arch Druid Runetotem"
DELETE FROM `quest_details` WHERE `ID`=936;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(936,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=936;

-- Quest "Assisting Arch Druid Runetotem"
DELETE FROM `quest_details` WHERE `ID`=3762;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3762,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3762;

-- Quest "Assisting Arch Druid Runetotem"
DELETE FROM `quest_details` WHERE `ID`=3784;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3784,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3784;

-- Quest "Un'Goro Soil"
DELETE FROM `quest_details` WHERE `ID`=3761;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3761,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25 WHERE `ID`=3761;

-- Quest "Morrowgrain Research"
DELETE FROM `quest_details` WHERE `ID`=3782;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3782,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3782;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3782;

-- Quest "Morrowgrain Research (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=3786;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3786,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=3786;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3786;

-- Quest "Morrowgrain to Thunder Bluff"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=3804;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3804;

-- Quest "Assisting Arch Druid Staghelm"
DELETE FROM `quest_details` WHERE `ID` IN (3763,3789,3790,10520);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3763,1,0,0,0,0,0,0,0,0),
(3789,1,0,0,0,0,0,0,0,0),
(3790,1,0,0,0,0,0,0,0,0),
(10520,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (3763,3789,3790,10520);

-- Quest "Un'Goro Soil"
DELETE FROM `quest_details` WHERE `ID`=3764;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3764,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=4, `EmoteOnComplete`=4 WHERE `ID`=3764;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3764;

-- Quest "Morrowgrain Research"
DELETE FROM `quest_details` WHERE `ID`=3781;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3781,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=3781;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3781;

-- Quest "Morrowgrain Research (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=3785;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3785,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=3785;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3785;

-- Quest "Morrowgrain to Darnassus"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=3803;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3803;

-- Quest "Bone-Bladed Weapons"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=4300;

-- Quest "Bungle in the Jungle"
DELETE FROM `quest_details` WHERE `ID`=4496;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4496,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4496;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=4496;

-- Quest "Volcanic Activity"
DELETE FROM `quest_details` WHERE `ID`=4502;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4502,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4502;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=4502;

-- Quest "The Apes of Un'Goro"
DELETE FROM `quest_details` WHERE `ID`=4289;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4289,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2 WHERE `ID`=4289;

-- Quest "The Mighty U'cha"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4301;

-- Quest "The Fare of Lar'korwi"
DELETE FROM `quest_details` WHERE `ID`=4290;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4290,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4290;

-- Quest "The Scent of Lar'korwi"
DELETE FROM `quest_details` WHERE `ID`=4291;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4291,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4291;

-- Quest "The Bait for Lar'korwi"
DELETE FROM `quest_details` WHERE `ID`=4292;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4292,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2, `EmoteOnIncomplete`=2 WHERE `ID`=4292;

-- Quest "Chasing A-Me 01"
DELETE FROM `quest_details` WHERE `ID`=4243;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4243,18,1,1,0,4000,0,0,0,0);

-- Quest "Chasing A-Me 01 (Part 3)"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2 WHERE `ID`=4245;

-- Quest "Roll the Bones"
DELETE FROM `quest_details` WHERE `ID`=3882;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3882,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3882;
UPDATE `quest_offer_reward` SET `Emote2`=22, `Emote3`=1, `EmoteDelay2`=1000, `EmoteDelay3`=1000 WHERE `ID`=3882;

-- Quest "Alien Ecology"
DELETE FROM `quest_details` WHERE `ID`=3883;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3883,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=3883;

-- Quest "Expedition Salvation"
DELETE FROM `quest_details` WHERE `ID`=3881;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3881,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=3881;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3881;

-- Quest "Muigin and Larion"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11 WHERE `ID`=4141;

-- Quest "A Visit to Gregan"
DELETE FROM `quest_details` WHERE `ID`=4142;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4142,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4142;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=4142;

-- Quest "Haze of Evil"
DELETE FROM `quest_details` WHERE `ID`=4143;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4143,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4143;

-- Quest "Bloodpetal Sprouts"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4144;

-- Quest "Larion and Muigin"
DELETE FROM `quest_details` WHERE `ID`=4145;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4145,5,1,6,0,0,0,0,0,0);

-- Quest "Marvon's Workshop"
DELETE FROM `quest_details` WHERE `ID`=4147;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4147,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4147;

-- Quest "Zapper Fuel"
DELETE FROM `quest_details` WHERE `ID`=4146;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4146,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=4146;

-- Quest "Bloodpetal Zapper"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4148;

-- Quest "Finding the Source"
DELETE FROM `quest_details` WHERE `ID`=974;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(974,6,4,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=974;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=974;

-- Quest "The New Springs"
DELETE FROM `quest_details` WHERE `ID`=980;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(980,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=980;

-- Quest "Strange Sources"
DELETE FROM `quest_details` WHERE `ID`=4842;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4842,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4842;

-- Quest "Shizzle's Flyer"
DELETE FROM `quest_details` WHERE `ID`=4503;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4503,4,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4503;
UPDATE `quest_offer_reward` SET `Emote2`=2 WHERE `ID`=4503;

-- Quest "Beware of Pterrordax"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4 WHERE `ID`=4501;

-- Quest "A Little Help From My Friends"
UPDATE `quest_offer_reward` SET `Emote1`=4, `EmoteDelay1`=2000 WHERE `ID`=4491;

-- Quest "Crystals of Power"
DELETE FROM `quest_details` WHERE `ID`=4284;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4284,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=4284;

-- Quest "It's a Secret to Everybody (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3845;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3845;

-- Quest "It's a Secret to Everybody (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=3908;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3908,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3908;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3908;

-- Quest "The Videre Elixir"
DELETE FROM `quest_details` WHERE `ID`=3909;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3909,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3909;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3909;

-- Quest "The Videre Elixir"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4041;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=4041;

-- Quest "Meet at the Grave"
DELETE FROM `quest_details` WHERE `ID`=3912;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3912,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3912;

-- Quest "A Grave Situation"
DELETE FROM `quest_details` WHERE `ID`=3913;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3913,1,1,0,0,0,0,0,0,0);

-- Quest "Linken's Sword"
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=3914;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6 WHERE `ID`=3914;

-- Quest "A Gnome's Assistance"
DELETE FROM `quest_details` WHERE `ID`=3941;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3941,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=3941;

-- Quest "Linken's Memory"
DELETE FROM `quest_details` WHERE `ID`=3942;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3942,6,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=3942;

-- Quest "Silver Heart"
DELETE FROM `quest_details` WHERE `ID`=4084;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4084,274,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4084;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4084;

-- Quest "Aquementas"
DELETE FROM `quest_details` WHERE `ID`=4005;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4005,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4005;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4005;

-- Quest "Linken's Adventure"
DELETE FROM `quest_details` WHERE `ID`=3961;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3961,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=3961;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3961;

-- Quest "It's Dangerous to Go Alone"
DELETE FROM `quest_details` WHERE `ID`=3962;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3962,273,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=3962;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=3962;

-- Quest "Torwa Pathfinder"
DELETE FROM `quest_details` WHERE `ID`=9063;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9063,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9063;

-- Quest "Bloodpetal Poison"
DELETE FROM `quest_details` WHERE `ID`=9052;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9052,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9052;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9052;

-- Quest "Toxic Test"
DELETE FROM `quest_details` WHERE `ID`=9051;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9051,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9051;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6 WHERE `ID`=9051;

-- Quest "A Better Ingredient"
DELETE FROM `quest_details` WHERE `ID`=9053;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9053,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9053;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=9053;
*/
