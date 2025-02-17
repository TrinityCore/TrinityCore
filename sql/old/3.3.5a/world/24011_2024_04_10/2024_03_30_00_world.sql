-- Cleansing the Scar (9489)
DELETE FROM `quest_details` WHERE `ID`=9489;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9489,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9489;

-- Rogues of the Shattered Hand (10794)
DELETE FROM `quest_details` WHERE `ID`=10794;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10794,1,1,1,0,0,0,0,0,0);

-- A Discreet Inquiry (10372)
DELETE FROM `quest_details` WHERE `ID`=10372;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10372,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10372; 

-- Find Keltus Darkleaf (9532)
DELETE FROM `quest_details` WHERE `ID`=9532;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9532,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=9532; 

-- Powering our Defenses (8490)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8490; 

-- Old Whitebark's Pendant (8474)
UPDATE `quest_offer_reward` SET `Emote1`=18 WHERE `ID`=8474; 

-- Abandoned Investigations (8891)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=8891; 

-- Word from the Spire (8890)
DELETE FROM `quest_details` WHERE `ID`=8890;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8890,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=18 WHERE `ID`=8890;

-- Cleaning up the Grounds (8894)
DELETE FROM `quest_details` WHERE `ID`=8894;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8894,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=8894;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=8894;

-- Where's Wyllithen? (9394)
DELETE FROM `quest_details` WHERE `ID`=9394;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9394,1,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=5 WHERE `ID`=9394;

-- Deactivating the Spire (8889)
DELETE FROM `quest_details` WHERE `ID`=8889;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8889,1,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=8889;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=8889;

-- The Magister's Apprentice (8888)
DELETE FROM `quest_details` WHERE `ID`=8888;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8888,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=1 WHERE `ID`=8888;

-- The Spearcrafter's Hammer (8477)
DELETE FROM `quest_details` WHERE `ID`=8477;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8477,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8477;

-- The Party Never Ends (9067)
DELETE FROM `quest_details` WHERE `ID`=9067;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9067,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=9067;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9067;

-- Saltheril's Haven (9395)
DELETE FROM `quest_details` WHERE `ID`=9395;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9395,5,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=6 WHERE `ID`=9395;

-- Unexpected Results (8488)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8488;

-- Corrupted Soil (8487)
DELETE FROM `quest_details` WHERE `ID`=8487;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8487,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8487;

-- Captain Kelisendra's Lost Rutters (8887)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8887;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8887;

-- Lost Armaments (8480)
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=8480;

-- Grimscale Pirates! (8886)
DELETE FROM `quest_details` WHERE `ID`=8886;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8886,5,1,6,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=8886;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1,`Emote3`=1 WHERE `ID`=8886;

-- The Dwarven Spy (8483)
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=8483;

-- Incriminating Documents (8482)
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=8482;

-- The Ring of Mmmrrrggglll (8885)
DELETE FROM `quest_details` WHERE `ID`=8885;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8885,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=8885;

-- Fish Heads, Fish Heads... (8884)
DELETE FROM `quest_details` WHERE `ID`=8884;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8884,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=8884;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=8884;

-- Arcane Instability (8486)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8486;

-- Completing the Delivery (8350)
DELETE FROM `quest_details` WHERE `ID`=8350;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8350,1,1,0,0,0,0,0,0,0);

-- Aiding the Outrunners (8347)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=8347;

-- Tainted Arcane Sliver (8338)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8338;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=8338;

-- Aiding the Outrunners (8347)
DELETE FROM `quest_details` WHERE `ID`=8347;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8347,2,1,0,0,0,0,0,0,0);

-- Felendren the Banished (8335)
DELETE FROM `quest_details` WHERE `ID`=8335;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8335,1,5,0,0,0,0,0,0,0);

-- Aggression (8334)
UPDATE `quest_details` SET `Emote3`=1 WHERE `ID`=8334;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=8334;

-- Report to Lanthan Perilon (8327)
DELETE FROM `quest_details` WHERE `ID`=8327;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8327,1,2,0,0,0,0,0,0,0);

-- A Fistful of Slivers (8336)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=8336;

-- Solanian's Belongings (8330)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8330;
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote2`=1 WHERE `ID`=8330;

-- Thirst Unending (8346)
DELETE FROM `quest_details` WHERE `ID`=8346;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8346,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=8346;

-- The Shrine of Dath'Remar (8345)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=8345;
UPDATE `quest_offer_reward` SET `Emote3`=1 WHERE `ID`=8345;

-- Solanian's Belongings (8330)
DELETE FROM `quest_details` WHERE `ID`=8330;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8330,1,1,1,0,0,0,0,0,0);

-- Well Watcher Solanian (10071)
DELETE FROM `quest_details` WHERE `ID`=10071;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10071,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10071;

-- Unfortunate Measures (8326)
DELETE FROM `quest_details` WHERE `ID`=8326;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(8326,1,1,0,0,0,0,0,0,0);

-- Rogue Training (9392)
DELETE FROM `quest_details` WHERE `ID`=9392;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9392,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9392;
