/*
-- Quest "Divine Retribution"
DELETE FROM `quest_details` WHERE `ID`=3441;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3441,1,0,0,0,1000,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `RewardText`="Have you heard enough? Are you prepared to act?" WHERE `ID`=3441;

-- Quest "The Flawless Flame"
DELETE FROM `quest_details` WHERE `ID`=3442;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3442,1,1,0,0,2000,1000,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3442;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=3442;

-- Quest "Forging the Shaft"
DELETE FROM `quest_details` WHERE `ID`=3443;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3443,1,1,0,0,500,500,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3443;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3443;

-- Quest "The Flame's Casing"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3452;

-- Quest "The Torch of Retribution"
DELETE FROM `quest_details` WHERE `ID`=3453;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3453,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3453;

-- Quest "Squire Maltrake"
DELETE FROM `quest_details` WHERE `ID`=3462;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3462,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3462;

-- Quest "Set Them Ablaze!"
DELETE FROM `quest_details` WHERE `ID`=3463;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3463,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=5 WHERE `ID`=3463;

-- Quest "Curse These Fat Fingers"
DELETE FROM `quest_details` WHERE `ID`=7723;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7723,1,1,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7723;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=21 WHERE `ID`=7723;

-- Quest "Incendosaurs? Whateverosaur is More Like It"
DELETE FROM `quest_details` WHERE `ID`=7727;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7727,1,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7727;

-- Quest "Fiery Menace!"
DELETE FROM `quest_details` WHERE `ID`=7724;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7724,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7724;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=7724;

-- Quest "What the Flux?"
DELETE FROM `quest_details` WHERE `ID`=7722;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7722,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=7722;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7722;

-- Quest "STOLEN: Smithing Tuyere and Lookout's Spyglass"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7728;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=7728;

-- Quest "WANTED: Overseer Maltorius"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=34 WHERE `ID`=7701;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7701;

-- Quest "Rocknot's Ale"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=4295;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=4 WHERE `ID`=4295;

-- Quest "Restoring Fiery Flux Supplies via Kingsblood"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID` IN (7736,8241,8242);

-- Quest "JOB OPPORTUNITY: Culling the Competition"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7729;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=7729;

-- Quest "Kill 'Em With Sleep Deprivation"
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=7702;

-- Quest "Ledger from Tanaris"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4450;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=4450;

-- Quest "Prayer to Elune"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3378;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3378;

-- Quest "Shadoweaver"
DELETE FROM `quest_details` WHERE `ID`=3379;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3379,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=3379;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=3379;

-- Quest "The Undermarket"
DELETE FROM `quest_details` WHERE `ID`=3385;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3385,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3385;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=3385;

-- Quest "The Undermarket (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=3402;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3402,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=4, `Emote3`=5, `RewardText`="Kovic slain??! This is a glorious day, $N! For years that scoundrel has been running shady undermarket trades, undercutting honest, hard working traders all over the world.$b$bYou deserve a fine reward for this accomplishment! And a fine reward you shall have!" WHERE `ID`=3402;

-- Quest "KILL ON SIGHT: Dark Iron Dwarves"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25 WHERE `ID`=4081;

-- Quest "KILL ON SIGHT: High Ranking Dark Iron Officials"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=4082;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4082;

-- Quest "Dreadmaul Rock"
DELETE FROM `quest_details` WHERE `ID`=3821;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3821,1,1,6,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3821;

-- Quest "Krom'Grul"
DELETE FROM `quest_details` WHERE `ID`=3822;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3822,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=3822;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=18, `EmoteDelay1`=500 WHERE `ID`=3822;

-- Quest "Disharmony of Flame"
DELETE FROM `quest_details` WHERE `ID`=3906;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3906,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `RewardText`="This cannot be... it must not be. The destruction of Pyron has merely lifted a veil. Within the depths of Blackrock is a much more insidious source of corruption." WHERE `ID`=3906;

-- Quest "Disharmony of Flame (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=3907;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3907,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5, `CompletionText`="The flames will soon overtake these lands. Make haste, $N!" WHERE `ID`=3907;
UPDATE `quest_offer_reward` SET `RewardText`="<Thunderheart clutches the Tablet of Kurniya.>$b$bRagnaros... here...$b$bThe elders were right to fear the corruption emanating from Blackrock Mountain. A general of the Old Gods! IN OUR WORLD! We must reassess our position here in Kargath. We must decide on whether we stay and fight or run for fear of a new sundering.$b$bBe weary of any further exploration in Blackrock Mountain, $N. A far greater evil than anything that exists in this world resides in those fiery depths." WHERE `ID`=3907;

-- Quest "The Rise of the Machines"
DELETE FROM `quest_details` WHERE `ID`=4061;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4061,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=4061;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=2000, `RewardText`="<Theodora lays the fragments out before her.>$b$b<Theodora carefully examines the fragments with an enormous monocle.>$b$bInteresting. Etched into the structural foundation of each of these fragments are... initials." WHERE `ID`=4061;

-- Quest "The Rise of the Machines (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4062;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4062,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=4062;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4062;

-- Quest "The Rise of the Machines (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=4063;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4063,6,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4063;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=4063;

-- Quest "The Last Element"
DELETE FROM `quest_details` WHERE `ID`=7201;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7201,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=7201;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=7201;

-- Quest "Badlands Reagent Run"
DELETE FROM `quest_details` WHERE `ID`=2258;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2258,2,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2258;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=2258;

-- Quest "Uldaman Reagent Run"
DELETE FROM `quest_details` WHERE `ID`=2202;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2202,25,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2202;
UPDATE `quest_offer_reward` SET `Emote1`=21, `Emote2`=1 WHERE `ID`=2202;

-- Quest "Badlands Reagent Run II"
DELETE FROM `quest_details` WHERE `ID`=2203;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2203,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2203;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2203;

-- Quest "Coyote Thieves"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1419;

-- Quest "Broken Alliances"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=782;

-- Quest "Unclaimed Baggage"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=9439;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9439;

-- Quest "Solution to Doom"
DELETE FROM `quest_details` WHERE `ID`=709;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(709,5,274,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=709;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=709;

-- Quest "To Ironforge for Yagyin's Digest"
DELETE FROM `quest_details` WHERE `ID`=727;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(727,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=3, `EmoteOnComplete`=3 WHERE `ID`=727;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=727;

-- Quest "To the Undercity for Yagyin's Digest"
DELETE FROM `quest_details` WHERE `ID`=728;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(728,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=728;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=728;

-- Quest "The Star, the Hand and the Heart"
DELETE FROM `quest_details` WHERE `ID` IN (735,736);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(735,6,1,1,0,0,0,0,0,0),
(736,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID` IN (735,736);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID` IN (735,736);

-- Quest "Forbidden Knowledge"
DELETE FROM `quest_details` WHERE `ID`=737;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(737,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=737;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `Emote4`=5 WHERE `ID`=737;

-- Quest "Dragonscale Leatherworking"
DELETE FROM `quest_details` WHERE `ID`=5145;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5145,1,25,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=5145;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=5145;

-- Quest "Power Stones"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2418;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=2418;

-- Quest "Barbecued Buzzard Wings"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=703;

-- Quest "Pearl Diving"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=705;

-- Quest "Necklace Recovery"
DELETE FROM `quest_details` WHERE `ID`=2283;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2283,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2283;

-- Quest "Necklace Recovery, Take 2"
DELETE FROM `quest_details` WHERE `ID`=2284;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2284,1,0,0,0,0,0,0,0,0);

-- Quest "Translating the Journal"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2318;

-- Quest "Translating the Journal (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=2338;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2338,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=2338;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2338;

-- Quest "Find the Gems and Power Source"
DELETE FROM `quest_details` WHERE `ID`=2339;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2339,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2339;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2339;

-- Quest "Deliver the Gems"
DELETE FROM `quest_details` WHERE `ID`=2340;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2340,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=2340;

-- Quest "Necklace Recovery, Take 3"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=2341;

-- Quest "Study of the Elements: Rock"
DELETE FROM `quest_details` WHERE `ID`=710;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(710,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=710;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=710;

-- Quest "Study of the Elements: Rock (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=711;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(711,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=711;

-- Quest "Study of the Elements: Rock (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=712;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(712,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=712;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=712;

-- Quest "Coolant Heads Prevail"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=713;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=713;

-- Quest "Gyro... What?"
DELETE FROM `quest_details` WHERE `ID`=714;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(714,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`="Yes, yes, yes. Just a moment." WHERE `ID`=714;
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=1 WHERE `ID`=714;

-- Quest "This Is Going to Be Hard"
DELETE FROM `quest_details` WHERE `ID`=734;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(734,4,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=734;

-- Quest "This Is Going to Be Hard (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=777;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(777,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=777;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=777;

-- Quest "This Is Going to Be Hard (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=778;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(778,4,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=778;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=778;

-- Quest "Stone Is Better than Cloth"
DELETE FROM `quest_details` WHERE `ID`=716;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(716,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=716;
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=716;

-- Quest "Liquid Stone"
DELETE FROM `quest_details` WHERE `ID`=715;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(715,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=715;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1 WHERE `ID`=715;

-- Quest "Vivian Lagrave"
DELETE FROM `quest_details` WHERE `ID`=4133;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4133,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4133;

-- Quest "Lost Thunderbrew Recipe"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4134;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11 WHERE `ID`=4134;

-- Quest "Vivian Lagrave and the Darkstone Tablet"
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=4769;

-- Quest "The Darkstone Tablet"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4768;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=4768;

-- Quest "The Pack Mistress"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=21 WHERE `ID`=4724;

-- Quest "Broodling Essence"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4726;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4726;

-- Quest "Chillwind Horns"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4809;

-- Quest "Return to Tinkee"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4810;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4810;

-- Quest "Tablet of the Seven"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4296;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4296;

-- Quest "Tinkee Steamboil"
DELETE FROM `quest_details` WHERE `ID`=4907;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4907,3,6,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=25 WHERE `ID`=4907;

-- Quest "Egg Freezing"
DELETE FROM `quest_details` WHERE `ID`=4734;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4734,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4734;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4734;

-- Quest "Egg Collection"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=4735;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=2 WHERE `ID`=4735;

-- Quest "Leonid Barthalomew"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5522;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote2`=1, `Emote3`=1 WHERE `ID`=5522;

-- Quest "Betina Bigglezink"
DELETE FROM `quest_details` WHERE `ID`=5531;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5531,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=5531;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=1, `Emote4`=6 WHERE `ID`=5531;

-- Quest "Dawn's Gambit"
DELETE FROM `quest_details` WHERE `ID`=4771;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4771,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=4771;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=2, `RewardText`="You did it! Vectus is defeated! And Dawn's Gambit... did it work?$B$BHm... maybe my device wasn't the success I had hoped, but I'm glad you were able to handle things anyway. Well done, $n!$B$BThe Argent Dawn, and the good people of Azeroth, are in your debt." WHERE `ID`=4771;

-- Quest "Warlord's Command"
UPDATE `quest_request_items` SET `EmoteOnComplete`=66, `EmoteOnIncomplete`=66 WHERE `ID`=4903;

-- Quest "Mother's Milk"
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6 WHERE `ID`=4866;

-- Quest "Eitrigg's Wisdom"
DELETE FROM `quest_details` WHERE `ID`=4941;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4941,6,5,1,1,0,0,0,0,0);

-- Quest "For The Horde!"
DELETE FROM `quest_details` WHERE `ID`=4974;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4974,1,1,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4974;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4974;

-- Quest "What the Wind Carries"
DELETE FROM `quest_details` WHERE `ID`=6566;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6566,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=6566;

-- Quest "The Champion of the Horde"
DELETE FROM `quest_details` WHERE `ID`=6567;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6567,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6 WHERE `ID`=6567;

-- Quest "Mistress of Deception"
DELETE FROM `quest_details` WHERE `ID`=6568;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6568,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=6, `Emote3`=1, `Emote4`=1 WHERE `ID`=6568;

-- Quest "Oculus Illusions"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=11 WHERE `ID`=6569;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=6569;

-- Quest "Emberstrife"
DELETE FROM `quest_details` WHERE `ID`=6570;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6570,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=6570;

-- Quest "The Test of Skulls, Scryer"
DELETE FROM `quest_details` WHERE `ID`=6582;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6582,1,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6582;

-- Quest "The Test of Skulls, Chronalis"
DELETE FROM `quest_details` WHERE `ID`=6584;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6584,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6584;

-- Quest "The Test of Skulls, Somnus"
DELETE FROM `quest_details` WHERE `ID`=6583;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6583,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=15, `EmoteOnIncomplete`=15 WHERE `ID`=6583;

-- Quest "The Test of Skulls, Axtroz"
DELETE FROM `quest_details` WHERE `ID`=6585;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6585,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6585;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6585;

-- Quest "Ascension..."
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6601;

-- Quest "Blood of the Black Dragon Champion"
DELETE FROM `quest_details` WHERE `ID`=6602;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6602,6,1,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=6602;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=6602;

-- Quest "Operative Bijou"
DELETE FROM `quest_details` WHERE `ID`=4981;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4981,1,1,25,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=5,`Emote3`=1,`Emote4`=11 WHERE `ID`=4981;

-- Quest "Bijou's Belongings"
DELETE FROM `quest_details` WHERE `ID`=4982;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4982,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4982;
UPDATE `quest_offer_reward` SET `Emote1`=4,`Emote2`=1 WHERE `ID`=4982;

-- Quest "Bijou's Reconnaissance Report"
DELETE FROM `quest_details` WHERE `ID`=4983;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4983,1,6,25,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=4983;
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=1 WHERE `ID`=4983;

-- Quest "Grark Lorkrub"
DELETE FROM `quest_details` WHERE `ID`=4122;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4122,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=4122;

-- Quest "Precarious Predicament"
DELETE FROM `quest_details` WHERE `ID`=4121;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4121,6,6,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4121;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4121;

-- Quest "Commander Gor'shak"
DELETE FROM `quest_details` WHERE `ID`=3981;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3981,1,1,1,6,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3981;

-- Quest "What Is Going On?"
DELETE FROM `quest_details` WHERE `ID`=3982;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3982,6,1,11,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=3982;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3982;

-- Quest "What Is Going On? (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=4001;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4001,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1,`Emote2`=25 WHERE `ID`=4001;

-- Quest "The Eastern Kingdoms"
DELETE FROM `quest_details` WHERE `ID`=4002;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4002,1,1,1,0,0,0,0,0,0);

-- Quest "The Royal Rescue"
DELETE FROM `quest_details` WHERE `ID`=4003;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4003,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=18 WHERE `ID`=4003;

-- Quest "The Princess Saved?"
DELETE FROM `quest_details` WHERE `ID`=4004;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4004,5,25,1,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay1`=1000 WHERE `ID`=4004;

-- Quest "A Dwarf and His Tools"
DELETE FROM `quest_details` WHERE `ID`=719;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(719,3,1,1,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=719;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=719;

-- Quest "Fiery Blaze Enchantments"
DELETE FROM `quest_details` WHERE `ID`=706;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(706,1,1,6,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=706;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=706;

-- Quest "Mirages"
DELETE FROM `quest_details` WHERE `ID`=718;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(718,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=718;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=718;

-- Quest "Scrounging"
DELETE FROM `quest_details` WHERE `ID`=733;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(733,1,6,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=733;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=733;

-- Quest "Tremors of the Earth"
DELETE FROM `quest_details` WHERE `ID`=732;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(732,2,1,274,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=732;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=732;

-- Quest "Tremors of the Earth (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=717;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(717,1,1,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=717;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=717;

-- Quest "A Sign of Hope"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=720;

-- Quest "A Sign of Hope (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=721;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(721,6,1,1,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=33, `Emote2`=6 WHERE `ID`=721;

-- Quest "Amulet of Secrets"
DELETE FROM `quest_details` WHERE `ID`=722;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(722,33,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=722;
UPDATE `quest_offer_reward` SET `Emote1`=33, `Emote2`=273 WHERE `ID`=722;

-- Quest "Prospect of Faith"
DELETE FROM `quest_details` WHERE `ID`=723;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(723,1,33,0,0,1500,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=723;

-- Quest "Prospect of Faith (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=724;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(724,6,5,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `CompletionText`="Ah, yes. Another traveler seeking something from the dwarves.$B$B$G Sir : Ma'am;, I'm truly sorry, but I've no time to answer meaningless questions right now." WHERE `ID`=724;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=25 WHERE `ID`=724;

-- Quest "Passing Word of a Threat"
DELETE FROM `quest_details` WHERE `ID`=725;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(725,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=725;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=725;

-- Quest "Passing Word of a Threat (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=726;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(726,5,25,1,0,1500,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=726;

-- Quest "An Ambassador of Evil"
DELETE FROM `quest_details` WHERE `ID`=762;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(762,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=762;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=762;

-- Quest "The Lost Tablets of Will"
DELETE FROM `quest_details` WHERE `ID`=1139;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1139,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=1139;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=2 WHERE `ID`=1139;

-- Quest "Suntara Stones"
UPDATE `quest_request_items` SET `EmoteOnComplete`=18, `EmoteOnIncomplete`=18 WHERE `ID`=3368;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=3368;

-- Quest "Dwarven Justice"
DELETE FROM `quest_details` WHERE `ID`=3371;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3371,1,1,0,0,0,0,0,0,0);

-- Quest "Rise, Obsidion!"
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274 WHERE `ID`=3566;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=18 WHERE `ID`=3566;

-- Quest "Proof of Deed"
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=3182;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=3182;

-- Quest "At Last!"
DELETE FROM `quest_details` WHERE `ID`=3201;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3201,6,1,0,0,0,0,0,0,0);

-- Quest "En-Ay-Es-Tee-Why"
DELETE FROM `quest_details` WHERE `ID`=4862;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4862,25,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4862;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4862;

-- Quest "Kibler's Exotic Pets"
DELETE FROM `quest_details` WHERE `ID`=4729;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4729,6,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4729;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4729;

-- Quest "Libram of Rumination"
UPDATE `quest_request_items` SET `EmoteOnComplete`=25, `EmoteOnIncomplete`=25 WHERE `ID`=4463;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=4463;

-- Quest "Libram of Constitution"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=4481;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=4481;

-- Quest "Libram of Tenacity"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=4482;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=6, `Emote2`=25 WHERE `ID`=4482;

-- Quest "Libram of Resilience"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4483;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=4483;

-- Quest "Libram of Voracity"
UPDATE `quest_request_items` SET `EmoteOnComplete`=274, `EmoteOnIncomplete`=274 WHERE `ID`=4484;
UPDATE `quest_offer_reward` SET `Emote1`=33, `Emote2`=5 WHERE `ID`=4484;

-- Quest "Mor'zul Bloodbringer"
DELETE FROM `quest_details` WHERE `ID`=7562;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7562,1,1,25,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=6, `Emote3`=1 WHERE `ID`=7562;

-- Quest "Rage of Blood"
DELETE FROM `quest_details` WHERE `ID`=7563;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7563,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7563;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7563;

-- Quest "Wildeyes"
DELETE FROM `quest_details` WHERE `ID`=7564;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7564,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=7564;

-- Quest "Lord Banehollow"
DELETE FROM `quest_details` WHERE `ID`=7623;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7623,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=7623;

-- Quest "Ulathek the Traitor"
DELETE FROM `quest_details` WHERE `ID`=7624;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7624,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=15, `EmoteOnComplete`=15 WHERE `ID`=7624;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7624;

-- Quest "Xorothian Stardust"
DELETE FROM `quest_details` WHERE `ID`=7625;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7625,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7625;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=7625;

-- Quest "Bell of Dethmoora"
DELETE FROM `quest_details` WHERE `ID`=7626;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7626,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7626;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7626;

-- Quest "Wheel of the Black March"
DELETE FROM `quest_details` WHERE `ID`=7627;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7627,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7627;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=7627;

-- Quest "Doomsday Candle"
DELETE FROM `quest_details` WHERE `ID`=7628;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7628,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7628;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=7628;

-- Quest "Doomsday Candle"
DELETE FROM `quest_details` WHERE `ID`=7630;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7630,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7630;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=7630;

-- Quest "Imp Delivery"
DELETE FROM `quest_details` WHERE `ID`=7629;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7629,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7629;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=7629;

-- Quest "Dreadsteed of Xoroth"
DELETE FROM `quest_details` WHERE `ID`=7631;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7631,1,1,1,2,0,0,0,0,0);

-- Quest "Put Her Down"
DELETE FROM `quest_details` WHERE `ID`=4701;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4701,1,1,1,2,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=4701;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=4701;

-- Quest "Overmaster Pyron"
DELETE FROM `quest_details` WHERE `ID`=4262;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4262,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=4262;

-- Quest "Incendius!"
DELETE FROM `quest_details` WHERE `ID`=4263;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4263,6,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=4263;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=4263;

-- Quest "Doomrigger's Clasp"
DELETE FROM `quest_details` WHERE `ID`=4764;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4764,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4764;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=4764;

-- Quest "Delivery to Ridgewell"
DELETE FROM `quest_details` WHERE `ID`=4765;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4765,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4765;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4765;

-- Quest "Extinguish the Firegut"
DELETE FROM `quest_details` WHERE `ID`=3823;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3823,5,1,1,51,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=3823;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=3823;

-- Quest "Gor'tesh the Brute Lord"
DELETE FROM `quest_details` WHERE `ID`=3824;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3824,5,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=3824;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=11 WHERE `ID`=3824;

-- Quest "Ogre Head On A Stick = Party"
DELETE FROM `quest_details` WHERE `ID`=3825;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3825,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=3825;
UPDATE `quest_offer_reward` SET `Emote1`=66, `Emote2`=5 WHERE `ID`=3825;

-- Quest "The Matron Protectorate"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=2, `EmoteOnComplete`=2 WHERE `ID`=5160;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5160;

-- Quest "Wrath of the Blue Flight"
DELETE FROM `quest_details` WHERE `ID`=5161;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5161,1,1,1,1,0,0,0,0,0);

-- Quest "Wrath of the Blue Flight (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=5162;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5162,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=5162;

-- Quest "Catalogue of the Wayward"
DELETE FROM `quest_details` WHERE `ID`=5164;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5164,1,1,0,0,0,0,0,0,0);

-- Quest "Breastplate of the Chromatic Flight"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=273, `EmoteOnComplete`=273 WHERE `ID`=5166;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=5166;

-- Quest "Legplates of the Chromatic Defier"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=5167;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=5167;

-- Quest "FIFTY! YEP!"
DELETE FROM `quest_details` WHERE `ID`=4283;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4283,1,5,5,51,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4283;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5 WHERE `ID`=4283;

-- Quest "The Good Stuff"
DELETE FROM `quest_details` WHERE `ID`=4286;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4286,1,22,6,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1 WHERE `ID`=4286;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5, `Emote3`=1 WHERE `ID`=4286;

-- Quest "Bijou's Belongings"
DELETE FROM `quest_details` WHERE `ID`=5001;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5001,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5001;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=5001;

-- Quest "Message to Maxwell"
DELETE FROM `quest_details` WHERE `ID`=5002;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5002,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5002;

-- Quest "Maxwell's Mission"
DELETE FROM `quest_details` WHERE `ID`=5081;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5081,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5081;

-- Quest "General Drakkisath's Command"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5089;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5089;

-- Quest "General Drakkisath's Demise"
DELETE FROM `quest_details` WHERE `ID`=5102;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5102,1,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5102;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=66 WHERE `ID`=5102;
*/
