-- A Question of Gluttony
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=9702;

-- Familiar Fungi
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9708;

-- Stealing Back the Mushrooms
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9709;

-- The Orebor Harborage
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9776;

-- Fulgor Spores
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9777;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9777;

-- Umbrafen Eel Filets
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9780;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9780;

-- Too Many Mouths to Feed
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9781;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9781;

-- The Dead Mire
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9782;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9782;

-- An Unnatural Drought
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9783;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9783;

-- The Boha'mu Ruins
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9786;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9786;

-- Idols of the Feralfen
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9787;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9787;

-- Diaphanous Wings
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9790;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9790;

-- Menacing Marshfangs
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9791;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9791;

-- A Message to Telaar
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9792;

-- The Fate of Tuurem
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9793;

-- No Time for Curiosity
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9794;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9794;

-- Gathering the Reagents
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9801;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9801;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9801;

-- Messenger to the Feralfen
DELETE FROM `quest_details` WHERE `ID`=9803;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9803,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9803;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9803;

-- Stinger Venom
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9830;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9830;

-- Lines of Communication
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9833;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9833;

-- Natural Armor
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9834;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9834;

-- Ango'rosh Encroachment
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9835;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9835;

-- Overlord Gorefist
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9839;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9839;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9839;

-- Secrets of the Daggerfen
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9848;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9848;

-- Safeguarding the Watchers
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9894;

-- The Dying Balance
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9895;

-- Blacksting's Bane
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=9896;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9896;

-- Unfinished Business
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9901;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9901;

-- The Terror of Marshlight Lake
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9902;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9902;

-- Maktu's Revenge
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9905;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9905;

-- What's Wrong at Cenarion Thicket?
DELETE FROM `quest_details` WHERE `ID`=9961;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9961,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6 WHERE `ID`=9961;

-- Strange Energy
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9968;

-- Clues in the Thicket
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9971;

-- Stymying the Arakkoa
DELETE FROM `quest_details` WHERE `ID`=9986;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9986,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9986;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9986;

-- Investigate Tuurem
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=9990;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE (ID=9990);

-- Olemba Seeds
DELETE FROM `quest_details` WHERE `ID`=9992;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9992,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9992;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9992;

-- What Are These Things? (Both factions)
DELETE FROM `quest_details` WHERE `ID` IN (9994,9995);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9994,1,1,0,0,0,0,0,0,0),
(9995,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete` = 6 WHERE `ID` IN (9994,9995);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID` IN (9994,9995);

-- Attack on Firewing Point
DELETE FROM `quest_details` WHERE `ID`=9996;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9996,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9996;
UPDATE `quest_offer_reward` SET `Emote1`=1, Emote2=1 WHERE `ID`=9996;

-- Unruly Neighbors
DELETE FROM `quest_details` WHERE `ID`=9998;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9998,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9998;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=9998;

-- The Firewing Liaison
DELETE FROM `quest_details` WHERE `ID`=10002;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10002,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10002;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10002;

-- Letting Earthbinder Tavgren Know
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10005;

-- Thinning the Ranks
DELETE FROM `quest_details` WHERE `ID`=10007;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10007,274,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10007;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10007;

-- Fel Orc Plans
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10012;

-- Timber Worg Tails
DELETE FROM `quest_details` WHERE `ID`=10016;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10016,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10016;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10016;

-- The Elusive Ironjaw
DELETE FROM `quest_details` WHERE `ID`=10022;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10022,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10022;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=10022;

-- Magical Disturbances
UPDATE `quest_details` SET `Emote1`=24, `Emote2`=1, `Emote3`=1 WHERE `ID`=10026;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10026;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=1 WHERE `ID`=10026;

-- Vessels of Power
DELETE FROM `quest_details` WHERE `ID`=10028;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10028,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10028;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10028;

-- Wanted: Bonelashers Dead!
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10033;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=10033;

-- Torgos!
DELETE FROM `quest_details` WHERE `ID`=10035;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10035,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10035;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=10035;

-- Speak with Private Weeks
DELETE FROM `quest_details` WHERE `ID`=10038;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10038,1,25,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=10038;

-- Who Are They?
DELETE FROM `quest_details` WHERE `ID`=10040;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10040,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=10040;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=10040;

-- Kill the Shadow Council!
DELETE FROM `quest_details` WHERE `ID`=10042;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10042,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10042;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=10042;

-- Escape from Firewing Point! (Both factions)
DELETE FROM `quest_details` WHERE `ID` IN (10051,10052);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10051,1,1,1,0,0,0,0,0,0),
(10052,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=10051;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10052;

-- Daggerfen Deviance
DELETE FROM `quest_details` WHERE `ID`=10115;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10115,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10115;

-- Wanted: Chieftain Mummaki
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10116;

-- Withered Flesh
UPDATE `quest_details` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=10355;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10355;

-- Report to the Allerian Post
DELETE FROM `quest_details` WHERE `ID`=10444;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10444,5,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, Emote2=1 WHERE `ID`=10444;

-- The Final Code
DELETE FROM `quest_details` WHERE `ID`=10446;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10446,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=10446;
UPDATE `quest_offer_reward` SET `Emote1`=4, Emote2=1 WHERE `ID`=10446;

-- Before Darkness Falls
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10878;

-- The Infested Protectors
UPDATE `quest_details` SET `Emote1`=0 WHERE `ID`=10896;
