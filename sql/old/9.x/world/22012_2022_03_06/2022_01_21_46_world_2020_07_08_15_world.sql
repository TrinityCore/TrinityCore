-- Quest "You Survived!"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=9279;

-- Quest "Replenishing the Healing Crystals"
DELETE FROM `quest_details` WHERE `ID`=9280;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9280,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9280;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9280;

-- Quest "Urgent Delivery!"
DELETE FROM `quest_details` WHERE `ID`=9409;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9409,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9409;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9409;

-- Quest "Rescue the Survivors!"
DELETE FROM `quest_details` WHERE `ID`=9283;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9283,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9283;

-- Quest "Botanist Taerix"
DELETE FROM `quest_details` WHERE `ID`=9371;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9371,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9371;

-- Quest "Volatile Mutations"
DELETE FROM `quest_details` WHERE `ID`=10302;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10302,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=10302;

-- Quest "What Must Be Done..."
DELETE FROM `quest_details` WHERE `ID`=9293;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9293,6,1,18,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=9293;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9293;

-- Quest "Botanical Legwork"
DELETE FROM `quest_details` WHERE `ID`=9799;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9799,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9799;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9799;

-- Quest "Spare Parts"
DELETE FROM `quest_details` WHERE `ID`=9305;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9305,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=9305;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9305;

-- Quest "Inoculation"
DELETE FROM `quest_details` WHERE `ID`=9303;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9303,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=9303;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9303;

-- Quest "The Missing Scout"
DELETE FROM `quest_details` WHERE `ID`=9309;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9309,1,0,0,0,0,0,0,0,0);

-- Quest "Healing the Lake"
DELETE FROM `quest_details` WHERE `ID`=9294;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9294,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4 WHERE `ID`=9294;

-- Quest "Vindicator Aldar"
DELETE FROM `quest_details` WHERE `ID`=10304;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10304,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=10304;

-- Quest "Blood Elf Spy"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9311;

-- Quest "Blood Elf Plans"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9798;

-- Quest "The Emitter"
DELETE FROM `quest_details` WHERE `ID`=9312;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9312,1,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=9312;

-- Quest "Travel to Azure Watch"
DELETE FROM `quest_details` WHERE `ID`=9313;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9313,1,1,2,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=9313;

-- Quest "Red Snapper - Very Tasty!"
DELETE FROM `quest_details` WHERE `ID`=9452;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9452,5,6,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=9452;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9452;

-- Quest "Find Acteon!"
DELETE FROM `quest_details` WHERE `ID`=9453;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9453,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9453;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9453;

-- Quest "Shaman Training"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9421;

-- Quest "Call of Earth (Part 1)"
DELETE FROM `quest_details` WHERE `ID`=9449;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9449,1,0,0,0,0,0,0,0,0);

-- Quest "Call of Earth (Part 3)"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9451;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9451;

-- Quest "Warrior Training"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9289;

-- Quest "Strength of One"
DELETE FROM `quest_details` WHERE `ID`=9582;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9582,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9582;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=9582;

-- Quest "Behomat"
DELETE FROM `quest_details` WHERE `ID`=10350;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10350,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10350;

-- Quest "Paladin Training"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9287;

-- Quest "Jol"
DELETE FROM `quest_details` WHERE `ID`=10366;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10366,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10366;

-- Quest "Redemption"
DELETE FROM `quest_details` WHERE `ID`=9598;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9598,2,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=9598;

-- Quest "Redemption (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=9600;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9600,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1 WHERE `ID`=9600;

-- Quest "Hunter Training"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9288;

-- Quest "Seek Huntress Kella Nightbow"
DELETE FROM `quest_details` WHERE `ID`=9757;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9757,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=9757;

-- Quest "Taming the Beast"
DELETE FROM `quest_details` WHERE `ID`=9591;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9591,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9591;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9591;

-- Quest "Taming the Beast (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=9592;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9592,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9592;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9592;

-- Quest "Taming the Beast (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=9593;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9593,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9593;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9593;

-- Quest "Beast Training"
DELETE FROM `quest_details` WHERE `ID`=9675;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9675,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9675;

-- Quest "Mage Training"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9290;

-- Quest "Control"
DELETE FROM `quest_details` WHERE `ID`=9595;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9595,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9595;

-- Quest "The Great Moongraze Hunt"
DELETE FROM `quest_details` WHERE `ID`=9454;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9454,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9454;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9454;

-- Quest "The Great Moongraze Hunt (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=10324;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10324,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=10324;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10324;

-- Quest "Learning the Language"
DELETE FROM `quest_details` WHERE `ID`=9538;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9538,5,1,1,5,0,0,0,0,0);

-- Quest "The Missing Fisherman"
DELETE FROM `quest_details` WHERE `ID`=10428;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10428,1,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10428;

-- Quest "All That Remains"
DELETE FROM `quest_details` WHERE `ID`=9527;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9527,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9527;

-- Quest "Medicinal Purpose"
DELETE FROM `quest_details` WHERE `ID`=9463;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9463,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9463;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=9463;

-- Quest "An Alternative Alternative"
DELETE FROM `quest_details` WHERE `ID`=9473;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9473,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9473;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9473;

-- Quest "The Prophecy of Velen"
DELETE FROM `quest_details` WHERE `ID`=9505;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9505,1,1,1,0,0,0,0,0,0);

-- Quest "Word from Azure Watch"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9314;

-- Quest "Strange Findings"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9455;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9455;

-- Quest "Bandits!"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9616;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=9616;

-- Quest "Nightstalker Clean Up, Isle 2..."
DELETE FROM `quest_details` WHERE `ID`=9456;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9456,1,1,1,25,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9456;

-- Quest "A Small Start"
DELETE FROM `quest_details` WHERE `ID`=9506;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9506,1,1,1,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9506;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9506;

-- Quest "Cookie's Jumbo Gumbo"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9512;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9512;

-- Quest "Reclaiming the Ruins"
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9513;

-- Quest "Rune Covered Tablet"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9514;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9514;

-- Quest "Warlord Sriss'tiz"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9515;

-- Quest "I've Got a Plant"
DELETE FROM `quest_details` WHERE `ID`=9530;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9530,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9530;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9530;

-- Quest "Precious and Fragile Things Need Special Handling"
DELETE FROM `quest_details` WHERE `ID`=9523;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9523,6,6,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=9523;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `Emote4`=273 WHERE `ID`=9523;

-- Quest "Tree's Company"
DELETE FROM `quest_details` WHERE `ID`=9531;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9531,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=9531;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=9531;

-- Quest "Show Gnomercy"
DELETE FROM `quest_details` WHERE `ID`=9537;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9537,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9537;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=5, `Emote3`=1 WHERE `ID`=9537;

-- Quest "Deliver Them From Evil..."
DELETE FROM `quest_details` WHERE `ID`=9602;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9602,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=9602;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9602;

-- Quest "The Prophecy of Akida"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9544;

-- Quest "Warn Your People"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1 WHERE `ID`=9622;
