-- Quest "Nothing But The Truth"
DELETE FROM `quest_details` WHERE `ID`=1372;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1372,1,0,0,0,0,0,0,0,0);

-- Quest "Nothing But The Truth (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1383;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1383,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=11, `EmoteOnIncomplete`=11 WHERE `ID`=1383;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1383;

-- Quest "Nothing But The Truth (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1388;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1388,1,11,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1388;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1388;

-- Quest "Nothing But The Truth (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=1391;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1391,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=20 WHERE `ID`=1391;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1391;

-- Quest "Draenethyst Crystals"
DELETE FROM `quest_details` WHERE `ID`=1389;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1389,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1389;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1389;

-- Quest "Report to Helgrum"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1420;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1420;

-- Quest "Pool of Tears"
DELETE FROM `quest_details` WHERE `ID`=1424;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1424,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1424;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1424;

-- Quest "The Atal'ai Exile"
DELETE FROM `quest_details` WHERE `ID`=1429;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1429,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=1429;

-- Quest "Return to Fel'Zerul"
DELETE FROM `quest_details` WHERE `ID`=1444;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1444,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6 WHERE `ID`=1444;

-- Quest "The Temple of Atal'Hakkar"
DELETE FROM `quest_details` WHERE `ID`=1445;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1445,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=1445;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5 WHERE `ID`=1445;

-- Quest "Lack of Surplus"
UPDATE `quest_request_items` SET `EmoteOnComplete`=66, `EmoteOnIncomplete`=66 WHERE `ID`=698;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=698;

-- Quest "Lack of Surplus (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=699;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(699,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=699;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=699;

-- Quest "Threat From the Sea"
DELETE FROM `quest_details` WHERE `ID`=1422;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1422,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1422;

-- Quest "Threat From the Sea (Part 2)"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1426;

-- Quest "Threat From the Sea (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1427;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1427,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1427;

-- Quest "Continued Threat"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=1428;

-- Quest "Fresh Meat"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=1430;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1430;

-- Quest "Neeka Bloodscar"
DELETE FROM `quest_details` WHERE `ID`=1418;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1418,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1418;

-- Quest "The Sunken Temple"
DELETE FROM `quest_details` WHERE `ID`=3380;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3380,1,0,0,0,0,0,0,0,0);

-- Quest "The Sunken Temple"
DELETE FROM `quest_details` WHERE `ID`=3445;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3445,1,0,0,0,0,0,0,0,0);

-- Quest "The Disgraced One"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2621;

-- Quest "The Missing Orders"
DELETE FROM `quest_details` WHERE `ID`=2622;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2622,6,5,0,0,0,0,0,0,0);

-- Quest "The Swamp Talker"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2623;
UPDATE `quest_offer_reward` SET `Emote1`=18 WHERE `ID`=2623;

-- Quest "Little Morsels"
DELETE FROM `quest_details` WHERE `ID`=9440;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9440,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9440;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=9440;

-- Quest "The Essence of Eranikus"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3374;

-- Quest "In Eranikus' Own Words"
DELETE FROM `quest_details` WHERE `ID`=3512;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3512,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3512;

-- Quest "Pool of Tears"
DELETE FROM `quest_details` WHERE `ID`=9610;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9610,1,1,1,0,0,1000,1000,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=9610;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6 WHERE `ID`=9610;

-- Quest "Mercy for the Cursed"
DELETE FROM `quest_details` WHERE `ID`=9448;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9448,5,1,1,0,0,1000,1000,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=9448;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9448;

-- Quest "Help Watcher Biggs"
DELETE FROM `quest_details` WHERE `ID`=9609;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9609,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9609;

-- Quest "Encroaching Wildlife"
DELETE FROM `quest_details` WHERE `ID`=1396;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1396,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1396;

-- Quest "The Lost Caravan"
DELETE FROM `quest_details` WHERE `ID`=1421;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1421,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1421;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1421;

-- Quest "Mercy for the Cursed"
DELETE FROM `quest_details` WHERE `ID`=1398;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1398,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1398;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1398;

-- Quest "Deliver the Shipment"
DELETE FROM `quest_details` WHERE `ID`=1425;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1425,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1425;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=2 WHERE `ID`=1425;

-- Quest "The Lost Supplies"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1423;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=1423;

-- Quest "Return the Comb"
DELETE FROM `quest_details` WHERE `ID`=154;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(154,34,0,0,0,0,0,0,0,0);

-- Quest "Petty Squabbles"
DELETE FROM `quest_details` WHERE `ID`=2783;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2783,1,6,0,0,0,0,0,0,0);

-- Quest "Heroes of Old"
DELETE FROM `quest_details` WHERE `ID`=2702;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2702,2,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2702;

-- Quest "Kirith"
DELETE FROM `quest_details` WHERE `ID`=2721;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2721,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2721;

-- Quest "The Cover of Darkness"
DELETE FROM `quest_details` WHERE `ID`=2743;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2743,274,1,0,0,0,0,0,0,0);

-- Quest "The Demon Hunter"
DELETE FROM `quest_details` WHERE `ID`=2744;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2744,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=2744;

-- Quest "Breaking the Ward"
DELETE FROM `quest_details` WHERE `ID`=3508;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3508,21,0,0,0,0,0,0,0,0);

-- Quest "The Name of the Beast"
DELETE FROM `quest_details` WHERE `ID`=3509;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3509,1,0,0,0,0,0,0,0,0);

-- Quest "The Name of the Beast (Part 2)"
UPDATE `quest_offer_reward` SET `RewardText`="Finally, one worthy of the wisdom of Arkkoroc!" WHERE `ID`=3510;

-- Quest "The Name of the Beast (Part 3)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `CompletionText`="You return! Astounding, $R. Did you discover the true name?" WHERE `ID`=3511;
UPDATE `quest_offer_reward` SET `RewardText`="The temper will add the necessary vitriol we require for the forging of the weapons. There is but one more step in their creation." WHERE `ID`=3511;

-- Quest "Azsharite"
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25 WHERE `ID`=3602;

-- Quest "The Formation of Felbane"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=3621;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=3621;

-- Quest "Enchanted Azsharite Fel Weaponry"
DELETE FROM `quest_details` WHERE `ID`=3625;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3625,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3625;

-- Quest "Return to the Blasted Lands"
DELETE FROM `quest_details` WHERE `ID`=3626;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3626,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3626;

-- Quest "Uniting the Shattered Amulet"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3627;

-- Quest "You Are Rakh'likh, Demon"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`="There is nothing left to fear." WHERE `ID`=3628;
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`="Today is a day that will be remembered for all eternity. The demonic overlord of the Blasted Lands has finally fallen!" WHERE `ID`=3628;

-- Quest "Ragnar Thunderbrew"
DELETE FROM `quest_details` WHERE `ID`=4128;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4128,3,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=4128;

-- Quest "Hurley Blackbreath"
DELETE FROM `quest_details` WHERE `ID`=4126;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4126,1,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=4126;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=4126;

-- Quest "Everything Counts In Large Amounts"
UPDATE `quest_offer_reward` SET `RewardText`="You truly disgust me, $r. A grown $g man : woman; drooling over a pile of junk? Pitiful! Take your reward and get out of my sight." WHERE `ID`=3501;
UPDATE `quest_offer_reward` SET `RewardText`="You truly disgust me, $r. A grown $g man : woman; drooling over a pile of junk? Pitiful! Take your reward and get out of my sight.$B$BSounds familiar? It should, because I say it a thousand times per day.$B$BOh how I loathe this world." WHERE `ID`=3502;

-- Quest "Through the Dark Portal"
DELETE FROM `quest_details` WHERE `ID`=9407;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9407,1,1,1,25,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9407;

-- Quest "The Basilisk's Bite"
DELETE FROM `quest_details` WHERE `ID`=2601;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2601,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2601;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=2601;

-- Quest "Vulture's Vigor"
DELETE FROM `quest_details` WHERE `ID`=2603;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2603,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2603;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=2603;

-- Quest "The Decisive Striker"
DELETE FROM `quest_details` WHERE `ID`=2585;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2585,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `CompletionText`="Where are the organs, $N!?" WHERE `ID`=2585;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2585;

-- Quest "A Boar's Vitality"
DELETE FROM `quest_details` WHERE `ID`=2583;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2583,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2583;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=6 WHERE `ID`=2583;

-- Quest "Snickerfang Jowls"
DELETE FROM `quest_details` WHERE `ID`=2581;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2581,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2581;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=2581;

-- Quest "Rage of Ages"
DELETE FROM `quest_details` WHERE `ID`=2582;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2582,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2582;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2582;

-- Quest "Spirit of the Boar"
DELETE FROM `quest_details` WHERE `ID`=2584;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2584,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2584;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=2584;

-- Quest "Salt of the Scorpok"
DELETE FROM `quest_details` WHERE `ID`=2586;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2586,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2586;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=2586;

-- Quest "Infallible Mind"
DELETE FROM `quest_details` WHERE `ID`=2602;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2602,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2602;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2602;

-- Quest "Spiritual Domination"
DELETE FROM `quest_details` WHERE `ID`=2604;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2604,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=2604;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2604;

-- Quest "The Prison's Bindings"
DELETE FROM `quest_details` WHERE `ID`=7581;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7581,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=7581;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=7581;

-- Quest "The Prison's Casing"
DELETE FROM `quest_details` WHERE `ID`=7582;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7582,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=7582;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7582;

-- Quest "Suppression"
DELETE FROM `quest_details` WHERE `ID`=7583;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7583,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=7583;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=7583;
