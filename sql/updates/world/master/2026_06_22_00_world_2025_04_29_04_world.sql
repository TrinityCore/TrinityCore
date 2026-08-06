-- The Absent Minded Prospector (729)
UPDATE `quest_details` SET `Emote3`=5,`Emote4`=20 WHERE `ID`=729;
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=6,`Emote4`=6 WHERE `ID`=729;

-- The Absent Minded Prospector (731)
UPDATE `quest_details` SET `Emote2`=6 WHERE `ID`=731;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=731;

-- The Absent Minded Prospector (741)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=741;

-- The Absent Minded Prospector (942)
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=942;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=942;
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=1 WHERE `ID`=942;

-- The Fall of Ameth'Aran (953)
UPDATE `quest_request_items` SET `EmoteOnInComplete`=1 WHERE `ID`=953;

-- Bashal'Aran (954)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=954;

-- Bashal'Aran (955)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=955;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=955;

-- Bashal'Aran (956)
UPDATE `quest_request_items` SET `EmoteOnInComplete`=1,`EmoteOnComplete`=1 WHERE `ID`=956;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=956;

-- Bashal'Aran (957)
UPDATE `quest_request_items` SET `EmoteOnInComplete`=1 WHERE `ID`=957;

-- The Tower of Althalaxx (965)
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=965;

-- The Tower of Althalaxx (967)
UPDATE `quest_details` SET `Emote3`=2 WHERE `ID`=967;
UPDATE `quest_request_items` SET `EmoteOnInComplete`=6 WHERE `ID`=967;

-- Deep Ocean, Vast Sea (982)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=982;

-- How Big a Threat? (984)
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=6 WHERE `ID`=984;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=984;
UPDATE `quest_offer_reward` SET `Emote2`=1,`Emote3`=2 WHERE `ID`=984;

-- How Big a Threat? (985)
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=985;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=985;

-- A Lost Master (986)
UPDATE `quest_request_items` SET `EmoteOnInComplete`=1 WHERE `ID`=986;
UPDATE `quest_offer_reward` SET `Emote1`=21,`Emote2`=1,`Emote3`=1 WHERE `ID`=986;

-- Trek to Ashenvale (990)
UPDATE `quest_details` SET `Emote1`=2,`Emote2`=1 WHERE `ID`=990;

-- A Lost Master (993)
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=993;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=993;

-- Escape Through Force (994)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=994;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=994;

-- Escape Through Stealth (995)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=995;
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=995;

-- Fruit of the Sea (1138)
UPDATE `quest_details` SET `Emote1`=4,`Emote2`=3 WHERE `ID`=1138;
UPDATE `quest_request_items` SET `EmoteOnInComplete`=1,`EmoteOnComplete`=1 WHERE `ID`=1138;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1 WHERE `ID`=1138;

-- Researching the Corruption (1275)
UPDATE `quest_details` SET `Emote1`=396,`Emote2`=396,`Emote3`=396,`Emote4`=396,`EmoteDelay1`=10 WHERE `ID`=1275;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1275;
UPDATE `quest_offer_reward` SET `Emote1`=396,`Emote2`=396,`Emote3`=2,`EmoteDelay1`=10,`EmoteDelay2`=10  WHERE `ID`=1275;


-- Seeking the Kor Gem (1442)
DELETE FROM `quest_details` WHERE `ID`=1442;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1442,2,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1442;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=1442;

-- Gaffer Jacks (1579)
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=5 WHERE `ID`=1579;

-- Plagued Lands (2118)
UPDATE `quest_offer_reward` SET `Emote2`=6 WHERE `ID`=2118;

-- Cleansing of the Infected (2138)
UPDATE `quest_details` SET `Emote2`=1;
UPDATE `quest_request_items` SET `EmoteOnInComplete`=6 WHERE `ID`=2138;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2138;

-- Tharnariun's Hope (2139)
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID`=2139;

-- Gyromast's Revenge (2078)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2078;

-- Gyromast's Retrieval (2098)
UPDATE `quest_details` SET `Emote1`=5,`Emote2`=1 WHERE `ID`=2098;
UPDATE `quest_offer_reward` SET `Emote1`=15 WHERE `ID`=2098;

-- Washed Ashore (3524)
UPDATE `quest_request_items` SET `EmoteOnInComplete`=1 WHERE `ID`=3524;

-- Beached Sea Turtle (4722)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=4722;

-- Beached Sea Creature (4723)
UPDATE `quest_request_items` SET `EmoteOnComplete`=1,`EmoteOnIncomplete`=1 WHERE `ID`=4723;

-- Beached Sea Turtle (4725)
UPDATE `quest_request_items` SET `EmoteOnComplete`=2,`EmoteOnIncomplete`=2 WHERE `ID`=4725;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4725;

-- Beached Sea Turtle (4727)
UPDATE `quest_request_items` SET `EmoteOnComplete`=2,`EmoteOnIncomplete`=2 WHERE `ID`=4727;

-- Beached Sea Turtle (4731)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4731;

-- WANTED: Murkdeep! (4740)
UPDATE `quest_request_items` SET `EmoteOnInComplete`=66,`EmoteOnComplete`=66 WHERE `ID`=4740;

-- The Blackwood Corrupted (4763)
UPDATE `quest_request_items` SET `EmoteOnInComplete`=1,`EmoteOnComplete`=1 WHERE `ID`=4763;
UPDATE `quest_offer_reward` SET `Emote2`=2 WHERE `ID`=4763;

-- The Red Crystal (4811)
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=4811;

-- The Sleeper Has Awakened (5321)
UPDATE `quest_offer_reward` SET `Emote1`=21,`Emote2`=1,`Emote3`=2 WHERE `ID`=5321;

-- Gathering the Cure (6123)
DELETE FROM `quest_details` WHERE `ID`=6123;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6123,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnInComplete`=6,`EmoteOnComplete`=6 WHERE `ID`=6123;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1 WHERE `ID`=6123;


-- Curing the Sick (6124)
DELETE FROM `quest_details` WHERE `ID`=6124;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6124,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnInComplete`=6,`EmoteOnComplete`=6 WHERE `ID`=6124;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6124;

-- Power over Poison (6125)
DELETE FROM `quest_details` WHERE `ID`=6125;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6125,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6125;
