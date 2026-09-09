-- Shard of a Felhound
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=4962;

-- The Binding
DELETE FROM `quest_details` WHERE `ID`=1795;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1795,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1,`EmoteOncomplete`=1 WHERE `ID`=1795;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=2 WHERE `ID`=1795;

-- The Orb of Soran'ruk
DELETE FROM `quest_details` WHERE `ID`=1740;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1740,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1,`EmoteOncomplete`=1 WHERE `ID`=1740;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=1740;

-- The Affray
UPDATE `quest_details` SET `Emote3`=25 WHERE `ID`=1719;

-- Tome of the Cabal
DELETE FROM `quest_details` WHERE `ID`=1758;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1758,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1758;

-- A Host of Evil
DELETE FROM `quest_details` WHERE `ID`=6626;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(6626,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6626;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=6626;

-- Blueleaf Tubers
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6,`EmoteOncomplete`=6 WHERE `ID`=1221;

-- Passage to Booty Bay
DELETE FROM `quest_details` WHERE `ID`=1040;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(1040,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=1040;

-- Mission: Possible But Not Probable
DELETE FROM `quest_details` WHERE `ID`=2478;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(2478,1,1,1,1,0,0,0,0,0);
