/*
-- Quest "A Call to Arms: The Plaguelands!"
DELETE FROM `quest_details` WHERE `ID` IN (5094,5066,5090,5091,10373,5093,10374,5095);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5094,5,0,0,0,0,0,0,0,0),
(5066,5,0,0,0,0,0,0,0,0),
(5090,5,0,0,0,0,0,0,0,0),
(5091,5,0,0,0,0,0,0,0,0),
(10373,5,0,0,0,0,0,0,0,0),
(5093,5,0,0,0,0,0,0,0,0),
(10374,5,0,0,0,0,0,0,0,0),
(5095,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID` IN (5094,5066,5090,5091,10373,5093,10374,5095);

-- Quest "Scarlet Diversions"
DELETE FROM `quest_details` WHERE `ID`=5096;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5096,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5096;

-- Quest "The Scourge Cauldrons"
DELETE FROM `quest_details` WHERE `ID`=5228;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5228,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=5228;

-- Quest "Target: Felstone Field"
DELETE FROM `quest_details` WHERE `ID`=5229;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5229,1,0,0,0,0,0,0,0,0);

-- Quest "Return to the Bulwark"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5230;

-- Quest "Target: Dalson's Tears"
DELETE FROM `quest_details` WHERE `ID`=5231;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5231,1,0,0,0,0,0,0,0,0);

-- Quest "Target: Writhing Haunt"
DELETE FROM `quest_details` WHERE `ID`=5233;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5233,1,0,0,0,0,0,0,0,0);

-- Quest "Target: Gahrron's Withering"
DELETE FROM `quest_details` WHERE `ID`=5235;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5235,1,0,0,0,0,0,0,0,0);

-- Quest "Mission Accomplished!"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=5237;

-- Quest "All Along the Watchtowers"
DELETE FROM `quest_details` WHERE `ID`=5098;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5098,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`="My warlocks are reporting that our beacon trackers are picking up extremely strong signals on all four towers!  You've executed my orders with the skill and precision of a seasoned veteran.  Your service to the Horde is duly noted once more, $N!$B$BWith the towers marked, our preparations for the attack are now in place.  The time has come to take the fight to the Scourge!" WHERE `ID`=5098;

-- Quest "Alas, Andorhal"
DELETE FROM `quest_details` WHERE `ID`=105;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(105,5,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=105;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=105;

-- Quest "Scholomance"
DELETE FROM `quest_details` WHERE `ID`=838;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(838,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=838;

-- Quest "Skeletal Fragments"
DELETE FROM `quest_details` WHERE `ID`=964;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(964,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=964;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=964;

-- Quest "Mold Rhymes With..."
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=5514;

-- Quest "Fire Plume Forged"
DELETE FROM `quest_details` WHERE `ID`=5802;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5802,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5802;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=5802;

-- Quest "Araj's Scarab"
DELETE FROM `quest_details` WHERE `ID`=5804;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5804,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5804;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5804;

-- Quest "The Key to Scholomance"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5511;

-- Quest "A Plague Upon Thee"
DELETE FROM `quest_details` WHERE `ID`=5901;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5901,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=5901;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5901;

-- Quest "A Plague Upon Thee (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=5902;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5902,1,1,0,0,0,0,0,0,0);

-- Quest "A Plague Upon Thee (Part 3)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=6390;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=6390;

-- Quest "Barov Family Fortune"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=5341;

-- Quest "The Last Barov"
DELETE FROM `quest_details` WHERE `ID`=5342;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5342,1,1,0,0,3500,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5342;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=5342;

-- Quest "Better Late Than Never"
DELETE FROM `quest_details` WHERE `ID`=5021;

-- Quest "Better Late Than Never (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5023;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5023;

-- Quest "The Jeremiah Blues"
DELETE FROM `quest_details` WHERE `ID`=5049;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5049,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=18 WHERE `ID`=5049;

-- Quest "Good Natured Emma"
DELETE FROM `quest_details` WHERE `ID`=5048;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5048,1,0,0,0,0,0,0,0,0);

-- Quest "Good Luck Charm"
DELETE FROM `quest_details` WHERE `ID`=5050;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5050,2,0,0,0,0,0,0,0,0);

-- Quest "Two Halves Become One"
DELETE FROM `quest_details` WHERE `ID`=5051;

-- Quest "Unfinished Business"
DELETE FROM `quest_details` WHERE `ID`=6004;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6004,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6004;

-- Quest "Unfinished Business (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=6023;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6023,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=6023;

-- Quest "Unfinished Business (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=6025;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6025,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6025;

-- Quest "The So-Called Mark of the Lightbringer"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9443;
UPDATE `quest_template` SET `RewardNextQuest`=0 WHERE `ID`=9443;

-- Quest "Defiling Uther's Tomb"
DELETE FROM `quest_details` WHERE `ID`=9444;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9444,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9444;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=15, `Emote3`=5 WHERE `ID`=9444;

-- Quest "Glyphed Oaken Branch (Horde)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=4987;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4987;

-- Quest "Glyphed Oaken Branch (Alliance)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=4986;

-- Quest "To The Bulwark"
DELETE FROM `quest_details` WHERE `ID`=9601;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9601,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=9601;

-- Quest "Prove Your Hatred"
DELETE FROM `quest_details` WHERE `ID`=10590;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10590,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=10590;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=10590;

-- Quest "Wisdom of the Banshee Queen"
DELETE FROM `quest_details` WHERE `ID`=10592;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10592,1,1,0,0,0,2000,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=10592;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=10592;

-- Quest "Ancient Evil"
DELETE FROM `quest_details` WHERE `ID`=10593;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10593,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=10593;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `EmoteDelay2`=2000 WHERE `ID`=10593;

-- Quest "Clear the Way"
DELETE FROM `quest_details` WHERE `ID`=5092;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5092,1,0,0,0,0,0,0,0,0);

-- Quest "All Along the Watchtowers"
DELETE FROM `quest_details` WHERE `ID`=5097;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5097,1,0,0,0,0,0,0,0,0);

-- Quest "The Scourge Cauldrons"
DELETE FROM `quest_details` WHERE `ID`=5215;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5215,1,0,0,0,0,0,0,0,0);

-- Quest "Target: Felstone Field"
DELETE FROM `quest_details` WHERE `ID`=5216;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5216,1,0,0,0,0,0,0,0,0);

-- Quest "Target: Dalson's Tears"
DELETE FROM `quest_details` WHERE `ID`=5219;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5219,1,0,0,0,0,0,0,0,0);

-- Quest "Target: Writhing Haunt"
DELETE FROM `quest_details` WHERE `ID`=5222;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5222,1,0,0,0,0,0,0,0,0);

-- Quest "Return to Chillwind Camp"
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=5223;

-- Quest "Target: Gahrron's Withering"
DELETE FROM `quest_details` WHERE `ID`=5225;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5225,1,0,0,0,0,0,0,0,0);

-- Quest "Barov Family Fortune"
DELETE FROM `quest_details` WHERE `ID`=5343;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5343,1,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25, `EmoteOnComplete`=25 WHERE `ID`=5343;

-- Quest "The Last Barov"
DELETE FROM `quest_details` WHERE `ID`=5344;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5344,1,1,0,0,3500,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=5344;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=5344;

-- Quest "Scholomance"
DELETE FROM `quest_details` WHERE `ID`=5533;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5533,1,0,0,0,0,0,0,0,0);

-- Quest "Skeletal Fragments"
DELETE FROM `quest_details` WHERE `ID`=5537;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5537,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5537;

-- Quest "Mold Rhymes With..."
DELETE FROM `quest_details` WHERE `ID`=5538;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5538,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `RewardText`="Arbington said you'd deliver the goods, and deliver you have! A deal is a deal; let me pack the fragments into the mold for you.$b$bDid Arbington imbue them already? Excellent... otherwise, it would have been a long trip back to the Chillwind Camp for you." WHERE `ID`=5538;

-- Quest "Fire Plume Forged"
DELETE FROM `quest_details` WHERE `ID`=5801;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5801,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5801;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=5801;

-- Quest "Araj's Scarab"
DELETE FROM `quest_details` WHERE `ID`=5803;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5803,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5803;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5803;

-- Quest "The Key to Scholomance"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5505;

-- Quest "Alas, Andorhal"
DELETE FROM `quest_details` WHERE `ID`=211;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(211,5,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=211;

-- Quest "A Plague Upon Thee"
DELETE FROM `quest_details` WHERE `ID`=5903;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5903,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5903;

-- Quest "A Plague Upon Thee (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=5904;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5904,1,1,0,0,0,0,0,0,0);

-- Quest "The Eastern Plagues"
DELETE FROM `quest_details` WHERE `ID`=6185;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6185,1,1,1,1,0,0,1000,2000,0);

-- Quest "The Blightcaller Cometh"
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=35, `Emote3`=6, `Emote4`=274, `EmoteDelay1`=1000, `EmoteDelay2`=1000, `EmoteDelay3`=2000, `EmoteDelay4`=1000, `RewardText`="No. It... NO! How? An agent of the Forsaken? The CHAMPION of the Banshee Queen???$B$B<King Varian Wrynn slumps in defeat.>" WHERE `ID`=6186;

-- Quest "Order Must Be Restored"
DELETE FROM `quest_details` WHERE `ID`=6187;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6187,1,1,1,25,1000,2000,3000,3500,0);
UPDATE `quest_request_items` SET `CompletionText`="<King Varian Wrynn is lost in thought.>" WHERE `ID`=6187;

-- Quest "Chillwind Camp"
DELETE FROM `quest_details` WHERE `ID`=8415;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8415,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8415;

-- Quest "Dispelling Evil"
DELETE FROM `quest_details` WHERE `ID`=8414;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8414,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8414;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8414;

-- Quest "Inert Scourgestones"
DELETE FROM `quest_details` WHERE `ID`=8416;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8416,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8416;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8416;

-- Quest "Forging the Mightstone"
DELETE FROM `quest_details` WHERE `ID`=8418;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8418,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=8418;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=8418;

-- Quest "Minion's Scourgestones" / "Invader's Scourgestones" / "Corruptor's Scourgestones"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID` IN (5402,5408,5510,5403,5407,5509,5404,5406,5508);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID` IN (5402,5408,5510,5403,5407,5509,5404,5406,5508);

-- Quest "Doctor Theolen Krastinov, the Butcher"
DELETE FROM `quest_details` WHERE `ID`=5382;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5382,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=5382;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5382;

-- Quest "Krastinov's Bag of Horrors"
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=5515;

-- Quest "Kirtonos the Herald"
DELETE FROM `quest_details` WHERE `ID`=5384;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5384,5,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5384;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=5384;

-- Quest "The Human, Ras Frostwhisper"
DELETE FROM `quest_details` WHERE `ID`=5461;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5461,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5461;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=5461;

-- Quest "The Dying, Ras Frostwhisper"
DELETE FROM `quest_details` WHERE `ID`=5462;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5462,1,1,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=274 WHERE `ID`=5462;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=500 WHERE `ID`=5462;

-- Quest "Menethil's Gift"
DELETE FROM `quest_details` WHERE `ID`=5463;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5463,1,1,51,25,0,0,0,0,0);

-- Quest "Menethil's Gift (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=5464;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5464;

-- Quest "Soulbound Keepsake"
DELETE FROM `quest_details` WHERE `ID`=5465;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5465,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=5465;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5465;

-- Quest "The Lich, Ras Frostwhisper"
DELETE FROM `quest_details` WHERE `ID`=5466;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5466,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5466;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5466;

-- Quest "A Matter of Time"
DELETE FROM `quest_details` WHERE `ID`=4971;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4971,1,0,0,0,0,0,0,0,0);

-- Quest "Counting Out Time"
DELETE FROM `quest_details` WHERE `ID`=4972;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4972,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4972;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=4972;

-- Quest "Counting Out Time (Repeatable)"
DELETE FROM `quest_details` WHERE `ID`=4973;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4973,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=4973;
UPDATE `quest_offer_reward` SET `Emote1`=2, `RewardText`="Again, I thank you for your assistance.  Please accept this gift.  While you still may not know when to use such an item, perhaps in the future the path of time will reveal its true intentions to you.  You could say that I've seen as such happening to you, $N."  WHERE `ID`=4973;

-- Quest "The Everlook Report"
DELETE FROM `quest_details` WHERE `ID`=6029;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6029,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=66 WHERE `ID`=6029;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6029;

-- Quest "Demon Dogs"
DELETE FROM `quest_details` WHERE `ID`=5542;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5542,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote2`=5, `Emote3`=0 WHERE `ID`=5542;

-- Quest "Blood Tinged Skies"
DELETE FROM `quest_details` WHERE `ID`=5543;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5543,1,1,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote3`=5, `Emote4`=0 WHERE `ID`=5543;

-- Quest "Carrion Grubbage"
DELETE FROM `quest_details` WHERE `ID`=5544;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5544,1,6,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5544;

-- Quest "Redemption"
DELETE FROM `quest_details` WHERE `ID`=5742;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5742,1,0,0,0,0,0,0,0,0);
UPDATE `quest_template_addon` SET `PrevQuestID`=0 WHERE `ID`=5742;
UPDATE `quest_template_addon` SET `NextQuestID`=5742 WHERE `ExclusiveGroup`=-5542;

-- Quest "Of Forgotten Memories"
DELETE FROM `quest_details` WHERE `ID`=5781;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5781,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=5781;

-- Quest "Of Lost Honor"
DELETE FROM `quest_details` WHERE `ID`=5845;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5845,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5845;

-- Quest "Of Love and Family"
DELETE FROM `quest_details` WHERE `ID`=5846;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5846,1,1,1,1,0,0,0,0,0);

-- Quest "Of Love and Family (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=5848;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5848,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5848;

-- Quest "Find Myranda"
DELETE FROM `quest_details` WHERE `ID`=5861;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5861,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=5861;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=6 WHERE `ID`=5861;

-- Quest "Scarlet Subterfuge"
DELETE FROM `quest_details` WHERE `ID`=5862;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5862,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=5862;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=16, `EmoteDelay2`=1000 WHERE `ID`=5862;

-- Quest "In Dreams"
DELETE FROM `quest_details` WHERE `ID`=5944;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5944,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1, `Emote4`=1 WHERE `ID`=5944;

-- Quest "The Restless Souls"
DELETE FROM `quest_details` WHERE `ID`=5281;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5281,1,1,1,1,0,0,0,0,0);

-- Quest "The Restless Souls (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=5282;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5282,1,1,1,1,0,0,0,0,0);

-- Quest "Zaeldarr the Outcast"
DELETE FROM `quest_details` WHERE `ID`=6021;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6021,5,0,0,0,0,0,0,0,0);

-- Quest "Duke Nicholas Zverenhoff"
DELETE FROM `quest_details` WHERE `ID`=6030;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6030,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2 WHERE `ID`=6030;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6030;

-- Quest "The Archivist"
DELETE FROM `quest_details` WHERE `ID`=5251;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5251,1,6,5,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=5251;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=5251;

-- Quest "Augustus' Receipt Book"
DELETE FROM `quest_details` WHERE `ID`=6164;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6164,1,6,1,5,0,0,0,0,0);

-- Quest "Sister Pamela"
DELETE FROM `quest_details` WHERE `ID`=5601;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5601,5,18,20,0,0,1000,2000,0,0);

-- Quest "Little Pamela"
DELETE FROM `quest_details` WHERE `ID`=5142;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5142,1,20,0,0,0,0,0,0,0);

-- Quest "A Strange Historian"
DELETE FROM `quest_details` WHERE `ID`=5153;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5153,1,0,0,0,0,0,0,0,0);

-- Quest "The Annals of Darrowshire"
DELETE FROM `quest_details` WHERE `ID`=5154;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5154,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5154;

-- Quest "Brother Carlin"
DELETE FROM `quest_details` WHERE `ID`=5210;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5210,1,0,0,0,0,0,0,0,0);

-- Quest "Defenders of Darrowshire"
DELETE FROM `quest_details` WHERE `ID`=5211;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5211,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=5211;

-- Quest "The Champion of the Banshee Queen"
DELETE FROM `quest_details` WHERE `ID`=5961;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5961,1,25,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=5961;

-- Quest "To Kill With Purpose"
DELETE FROM `quest_details` WHERE `ID`=6022;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6022,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=6022;
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote2`=1 WHERE `ID`=6022;

-- Quest "Un-Life's Little Annoyances"
DELETE FROM `quest_details` WHERE `ID`=6042;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6042,1,1,6,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6042;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6042;

-- Quest "The Ranger Lord's Behest"
DELETE FROM `quest_details` WHERE `ID`=6133;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6133,1,1,25,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=6133;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=6133;

-- Quest "The Corpulent One"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=6136;
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=6136;

-- Quest "Duskwing, Oh How I Hate Thee..."
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6135;
UPDATE `quest_offer_reward` SET `Emote1`=273, `RewardText`="Excellent work, imbecile. I shall fashion this fur into something you can use." WHERE `ID`=6135;

-- Quest "Ramstein"
DELETE FROM `quest_details` WHERE `ID`=6163;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6163,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6163;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1, `Emote3`=1, `Emote4`=66, `EmoteDelay2`=1000 WHERE `ID`=6163;

-- Quest "The Call to Command"
DELETE FROM `quest_details` WHERE `ID`=6144;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6144,1,1,25,5,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=25 WHERE `ID`=6144;

-- Quest "The Crimson Courier"
DELETE FROM `quest_details` WHERE `ID`=14350;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14350,1,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=14350;
UPDATE `quest_offer_reward` SET `Emote1`=11 WHERE `ID`=14350;

-- Quest "Nathanos' Ruse"
DELETE FROM `quest_details` WHERE `ID`=6146;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6146,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=6146;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=6146;

-- Quest "Return to Nathanos"
DELETE FROM `quest_details` WHERE `ID`=6147;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6147,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=5 WHERE `ID`=6147;

-- Quest "The Scarlet Oracle, Demetria"
DELETE FROM `quest_details` WHERE `ID`=6148;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6148,1,1,1,25,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=66 WHERE `ID`=6148;

-- Quest "Heroes of Darrowshire"
DELETE FROM `quest_details` WHERE `ID`=5168;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5168,1,0,0,0,0,0,0,0,0);

-- Quest "Villains of Darrowshire"
DELETE FROM `quest_details` WHERE `ID`=5181;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5181,1,0,0,0,0,0,0,0,0);

-- Quest "Marauders of Darrowshire"
DELETE FROM `quest_details` WHERE `ID`=5206;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5206,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=5206;

-- Quest "Return to Chromie"
DELETE FROM `quest_details` WHERE `ID`=5941;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5941,1,0,0,0,0,0,0,0,0);

-- Quest "The Battle of Darrowshire"
DELETE FROM `quest_details` WHERE `ID`=5721;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5721,1,0,0,0,0,0,0,0,0);

-- Quest "The Ice Guard"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9211;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000 WHERE `ID`=9211;

-- Quest "The Shadow Guard"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=274 WHERE `ID`=9213;
UPDATE `quest_offer_reward` SET `Emote1`=6, `EmoteDelay1`=1000 WHERE `ID`=9213;

-- Quest "Savage Flora"
DELETE FROM `quest_details` WHERE `ID`=9136;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9136,1,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9136;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=9136;

-- Quest "Savage Fronds"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9137;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9137;

-- Quest "Houses of the Holy"
DELETE FROM `quest_details` WHERE `ID`=5243;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5243,1,1,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `CompletionText`="Be wary, not all supply crates will have survived the destruction of the city. The Scourge dare not touch the water but surely the holy water will not prevent vermin infestations." WHERE `ID`=5243;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `RewardText`="Well done, $R. You have proven that while you are tolerant of others, you will stop at nothing to destroy the minions of Kel'Thuzad." WHERE `ID`=5243;

-- Quest "Bonescythe Digs"
DELETE FROM `quest_details` WHERE `ID`=9126;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9126,1,1,1,6,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9126;

-- Quest "Bone Fragments"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9127;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9127;

-- Quest "Cryptstalker Armor Doesn't Make Itself..."
DELETE FROM `quest_details` WHERE `ID`=9124;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9124,6,1,1,0,0,1000,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9124;

-- Quest "Crypt Fiend Parts"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9125;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=9125;

-- Quest "The Elemental Equation"
DELETE FROM `quest_details` WHERE `ID`=9128;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9128,2,6,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9128;

-- Quest "Core of Elements"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9129;
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=9129;

-- Quest "Binding the Dreadnaught"
DELETE FROM `quest_details` WHERE `ID`=9131;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9131,6,1,1,25,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9131;

-- Quest "Dark Iron Scraps"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=25 WHERE `ID`=9132;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5 WHERE `ID`=9132;

-- Quest "The Great Fras Siabi"
DELETE FROM `quest_details` WHERE `ID`=5214;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5214,1,1,5,20,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=5214;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5214;

-- Quest "That's Asking A Lot"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6026;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=6026;

-- Quest "When Smokey Sings, I Get Violent"
DELETE FROM `quest_details` WHERE `ID`=6041;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(6041,1,1,1,5,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=6041;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=11 WHERE `ID`=6041;

-- Quest "They Call Me "The Rooster""
DELETE FROM `quest_details` WHERE `ID`=9141;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9141,6,1,1,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=9141;

-- Quest "Craftsman's Writ"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9142;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9142;

-- Quest "Glacial Wrists"
DELETE FROM `quest_details` WHERE `ID`=9238;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9238,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=9238;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9238;

-- Quest "Glacial Gloves"
DELETE FROM `quest_details` WHERE `ID`=9239;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9239,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9239;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=9239;

-- Quest "The Flesh Does Not Lie"
DELETE FROM `quest_details` WHERE `ID`=5212;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5212,1,1,5,1,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=5212;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5212;

-- Quest "The Active Agent"
DELETE FROM `quest_details` WHERE `ID`=5213;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5213,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=5213;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=5213;

-- Quest "Plagued Hatchlings"
DELETE FROM `quest_details` WHERE `ID`=5529;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5529,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=5529;

-- Quest "Superior Armaments of Battle - Friend of the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9221;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9221,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9221;

-- Quest "Epic Armaments of Battle - Friend of the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9222;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9222,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9222;

-- Quest "Superior Armaments of Battle - Honored Amongst the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9223;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9223,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9223;

-- Quest "Epic Armaments of Battle - Honored Amongst the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9224;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9224,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9224;

-- Quest "Superior Armaments of Battle - Revered Amongst the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9226;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9226,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9226;

-- Quest "Epic Armaments of Battle - Revered Amongst the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9225;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9225,1,6,1,1,0,0,0,0,0);
-- 
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9225;

-- Quest "Superior Armaments of Battle - Exalted Amongst the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9228;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9228,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9228;

-- Quest "Epic Armaments of Battle - Exalted Amongst the Dawn"
DELETE FROM `quest_details` WHERE `ID`=9227;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9227,1,6,1,1,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9227;

-- Quest "The Truth Comes Crashing Down"
UPDATE `quest_request_items` SET `EmoteOnComplete`=25 WHERE `ID`=5262;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6 WHERE `ID`=5262;

-- Quest "Above and Beyond"
DELETE FROM `quest_details` WHERE `ID`=5263;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5263,1,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=5263;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25 WHERE `ID`=5263;

-- Quest "Lord Maxwell Tyrosus"
DELETE FROM `quest_details` WHERE `ID`=5264;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5264,1,1,5,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=5264;

-- Quest "The Argent Hold"
DELETE FROM `quest_details` WHERE `ID`=5265;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5265,1,1,2,0,0,0,0,0,0);

-- Quest "The Balance of Light and Shadow"
DELETE FROM `quest_details` WHERE `ID`=7622;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7622,1,1,1,2,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7622;

-- Quest "Bolstering Our Defenses"
DELETE FROM `quest_details` WHERE `ID`=9665;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9665,66,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9665;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9665;

-- Quest "Establishing New Outposts"
DELETE FROM `quest_details` WHERE `ID`=9664;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9664,66,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=9664;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=9664;
*/
