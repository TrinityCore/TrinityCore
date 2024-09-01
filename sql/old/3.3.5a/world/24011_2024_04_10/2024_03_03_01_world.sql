-- Call of Water (9509)
UPDATE `quest_offer_reward` SET `Emote1`=2,`Emote2`=1,`Emote3`=1 WHERE `ID`=9509;

-- Cruelfin's Necklace (9576)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9576;

-- Signs of the Legion (9594)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9594;

-- Razormaw (9689)
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=1,`Emote3`=1,`Emote4`=2 WHERE `ID`=9689;

-- Ending Their World (9759)
DELETE FROM `quest_details` WHERE `ID`=9759;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9759,274,1,1,6,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=5,`Emote4`=1 WHERE `ID`=9759;

-- Clearing the Way (9761)
DELETE FROM `quest_details` WHERE `ID`=9761;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9761,1,1,1,1,0,0,0,0,0);

-- Vindicator's Rest (9760)
DELETE FROM `quest_details` WHERE `ID`=9760;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9760,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9760;

-- What We Don't Know... (9756)
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=6 WHERE `ID`=9756;

-- What We Know... (9753)
DELETE FROM `quest_details` WHERE `ID`=9753;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9753,1,1,1,0,0,0,0,0,0);

-- The Sun Gate (9740)
DELETE FROM `quest_details` WHERE `ID`=9740;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9740,1,1,1,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1,`Emote3`=5 WHERE `ID`=9740;

-- Limits of Physical Exhaustion (9746)
DELETE FROM `quest_details` WHERE `ID`=9746;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9746,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9746;

-- Don't Drink the Water (9748)
DELETE FROM `quest_details` WHERE `ID`=9748;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9748,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=9748;
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=1,`Emote3`=1 WHERE `ID`=9748;

-- The Cryo-Core (9703)
DELETE FROM `quest_details` WHERE `ID`=9703;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9703,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9703;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=9703;

-- They're Alive! Maybe... (9670)
DELETE FROM `quest_details` WHERE `ID`=9670;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9670,1,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=9670;
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=1 WHERE `ID`=9670;

-- Critters of the Void (9741)
DELETE FROM `quest_details` WHERE `ID`=9741;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9741,1,1,1,0,0,0,0,0,0);

-- I Shoot Magic Into the Darkness (9700)
DELETE FROM `quest_details` WHERE `ID`=9700;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9700,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=6,`Emote3`=1 WHERE `ID`=9700;

-- More Irradiated Crystal Shards (9642)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9642;

-- Into the Dream (9688)
DELETE FROM `quest_details` WHERE `ID`=9688;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9688,1,1,1,5,0,0,0,0,0);

-- Matis the Cruel (9711)
DELETE FROM `quest_details` WHERE `ID`=9711;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9711,1,25,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9711;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9711;

-- Newfound Allies (9632)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9632;

-- Galaen's Journal - The Fate of Vindicator Saruan (9706)
UPDATE `quest_offer_reward` SET `Emote1`=18,`Emote2`=1,`Emote3`=15 WHERE `ID`=9706;

-- Galaen's Fate (9579)
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9579;

-- Fouled Water Spirits (10067)
DELETE FROM `quest_details` WHERE `ID`=10067;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10067,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=10067;

-- Oh, the Tangled Webs They Weave (10066)
DELETE FROM `quest_details` WHERE `ID`=10066;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10066,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=10066;

-- The Missing Expedition (9669)
DELETE FROM `quest_details` WHERE `ID`=9669;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9669,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9669;

-- Talk to the Hand (10064)
DELETE FROM `quest_details` WHERE `ID`=10064;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10064,1,1,1,0,0,0,0,0,0);

-- The Final Sample (9585)
DELETE FROM `quest_details` WHERE `ID`=9585;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9585,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9585;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9585;

-- Nolkai's Words (9561)
DELETE FROM `quest_details` WHERE `ID`=9561;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9561,1,0,0,0,0,0,0,0,0);

-- Deciphering the Book (9557)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9557;

-- Culling the Flutterers (9647)
DELETE FROM `quest_details` WHERE `ID`=9647;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9647,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9647;

-- Restoring Sanctity (9687)
DELETE FROM `quest_details` WHERE `ID`=9687;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9687,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9687;
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=1,`Emote3`=274 WHERE `ID`=9687;

-- Ending the Bloodcurse (9683)
DELETE FROM `quest_details` WHERE `ID`=9683;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9683,1,1,1,0,0,0,0,0,0);

-- The Hopeless Ones... (9682)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9682;

-- The Bloodcursed Naga (9674)
DELETE FROM `quest_details` WHERE `ID`=9674;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9674,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9674;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9674;

-- Artifacts of the Blacksilt (9549)
DELETE FROM `quest_details` WHERE `ID`=9549;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9549,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9549;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9549;

-- Pilfered Equipment (9548)
DELETE FROM `quest_details` WHERE `ID`=9548;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9548,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9548;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9548;

-- Audience with the Prophet (9698)
DELETE FROM `quest_details` WHERE `ID`=9698;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9698,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9698;

-- Newfound Allies (9632)
DELETE FROM `quest_details` WHERE `ID`=9632;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9632,1,0,0,0,0,0,0,0,0);

-- Searching for Galaen (9578)
DELETE FROM `quest_details` WHERE `ID`=9578;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9578,1,0,0,0,0,0,0,0,0);

-- Urgent Delivery (9671)
UPDATE `quest_offer_reward` SET `Emote1`=6,`Emote2`=1,`Emote3`=5 WHERE `ID`=9671;

-- The Bear Necessities (9580)
DELETE FROM `quest_details` WHERE `ID`=9580;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9580,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9580;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9580;

-- Constrictor Vines (9643)
DELETE FROM `quest_details` WHERE `ID`=9643;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9643,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9643;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9643;

-- Ysera's Tears (9649)
DELETE FROM `quest_details` WHERE `ID`=9649;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9649,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9649;

-- Translations... (9696)
DELETE FROM `quest_details` WHERE `ID`=9696;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9696,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9696;

-- The Second Sample (9584)
DELETE FROM `quest_details` WHERE `ID`=9584;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9584,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9584;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9584;

-- Salvaging the Data (9628)
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9628;

-- The Missing Survey Team (9620)
DELETE FROM `quest_details` WHERE `ID`=9620;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9620,1,0,0,0,0,0,0,0,0);

-- Intercepting the Message (9779)
DELETE FROM `quest_details` WHERE `ID`=9779;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9779,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6,`EmoteOnIncomplete`=6 WHERE `ID`=9779;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9779;

-- Containing the Threat (9569)
DELETE FROM `quest_details` WHERE `ID`=9569;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9569,15,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9569;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9569;

-- Blood Watch (9694)
DELETE FROM `quest_details` WHERE `ID`=9694;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9694,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9694;
UPDATE `quest_offer_reward` SET `Emote1`=5,`Emote2`=1,`Emote1`=3,`Emote4`=1 WHERE `ID`=9694;

-- Learning from the Crystals (9581)
DELETE FROM `quest_details` WHERE `ID`=9581;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9581,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9581;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9581;

-- WANTED: Deathclaw (9646)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9646;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9646;

-- What Argus Means to Me (9693)
DELETE FROM `quest_details` WHERE `ID`=9693;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9693,6,1,1,1,0,0,0,0,0);

-- Victims of Corruption (9574)
DELETE FROM `quest_details` WHERE `ID`=9574;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9574,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9574;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9574;

-- On the Wings of a Hippogryph (9604)
DELETE FROM `quest_details` WHERE `ID`=9604;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9604,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9604;

-- Explorers' League, Is That Something for Gnomes? (10063)
DELETE FROM `quest_details` WHERE `ID`=10063;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(10063,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=10063;

-- Mac'Aree Mushroom Menagerie (9648)
DELETE FROM `quest_details` WHERE `ID`=9648;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9648,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9648;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=9648;

-- Irradiated Crystal Shards (9641)
DELETE FROM `quest_details` WHERE `ID`=9641;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9641,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9641;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9641;

-- Catch and Release (9629)
DELETE FROM `quest_details` WHERE `ID`=9629;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9629,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9629;

-- Know Thine Enemy (9567)
DELETE FROM `quest_details` WHERE `ID`=9567;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9567,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9567;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9567;

-- Beds, Bandages, and Beyond (9603)
DELETE FROM `quest_details` WHERE `ID`=9603;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9603,1,0,0,0,0,0,0,0,0);
UPDATE `quest_details` SET `Emote2`=1,`Emote3`=1 WHERE `ID`=9603;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9603;

-- Report to Exarch Admetius (9668)
DELETE FROM `quest_details` WHERE `ID`=9668;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9668,1,1,274,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=9668;

-- Declaration of Power (9666)
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9666;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1,`Emote3`=1 WHERE `ID`=9666;

-- The Kessel Run (9663)
DELETE FROM `quest_details` WHERE `ID`=9663;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9663,1,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5,`EmoteOnIncomplete`=5 WHERE `ID`=9663;
UPDATE `quest_offer_reward` SET `Emote1`=21,`Emote2`=1,`Emote3`=1 WHERE `ID`=9663;

-- A Favorite Treat (9624)
DELETE FROM `quest_details` WHERE `ID`=9624;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9624,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9624;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9624;

-- Alien Predators (9634)
DELETE FROM `quest_details` WHERE `ID`=9634;
INSERT INTO `quest_details` (`ID`,`Emote1`,`Emote2`,`Emote3`,`Emote4`,`EmoteDelay1`,`EmoteDelay2`,`EmoteDelay3`,`EmoteDelay4`,`VerifiedBuild`) VALUES
(9634,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9634;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9634;
