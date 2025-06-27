-- Quest "Missing Crystals"
DELETE FROM `quest_details` WHERE `ID`=9435;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(9435,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=9435;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=9435;

-- Quest "Down the Coast"
DELETE FROM `quest_details` WHERE `ID`=536;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(536,7,0,0,0,0,0,0,0,0);

-- Quest "Farren's Proof"
DELETE FROM `quest_details` WHERE `ID`=559;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(559,6,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=559;

-- Quest "Farren's Proof (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=560;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(560,6,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=560;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=560;

-- Quest "Stormwind Ho!"
DELETE FROM `quest_details` WHERE `ID`=562;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(562,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=562;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=562;

-- Quest "Reassignment"
DELETE FROM `quest_details` WHERE `ID`=563;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(563,1,0,0,0,0,0,0,0,0);

-- Quest "Costly Menace"
DELETE FROM `quest_details` WHERE `ID`=564;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(564,1,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=564;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=564;

-- Quest "Soothing Turtle Bisque"
DELETE FROM `quest_details` WHERE `ID`=555;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(555,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=555;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=555;

-- Quest "Foreboding Plans"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=510;

-- Quest "Crushridge Bounty"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=500;

-- Quest "In the Name of the Light"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=66 WHERE `ID`=1053;

-- Quest "Encrypted Letter"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=511;

-- Quest "Letter to Stormpike"
DELETE FROM `quest_details` WHERE `ID`=514;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(514,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=514;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=514;

-- Quest "Further Mysteries"
DELETE FROM `quest_details` WHERE `ID`=525;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(525,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=525;

-- Quest "Dark Council"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=537;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=537;

-- Quest "MacKreel's Moonshine"
DELETE FROM `quest_details` WHERE `ID`=647;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(647,5,1,5,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=647;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=647;

-- Quest "Hints of a New Plague?"
DELETE FROM `quest_details` WHERE `ID`=659;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(659,1,1,6,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=659;

-- Quest "Hints of a New Plague? (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=658;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(658,6,1,1,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=658;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=658;

-- Quest "Hints of a New Plague? (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=657;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(657,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=657;

-- Quest "Hints of a New Plague? (Part 4)"
DELETE FROM `quest_details` WHERE `ID`=660;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(660,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=660;

-- Quest "Hints of a New Plague? (Part 5)"
DELETE FROM `quest_details` WHERE `ID`=661;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(661,11,1,6,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=11, `Emote2`=1, `Emote3`=2 WHERE `ID`=661;

-- Quest "Bartolo's Yeti Fur Cloak"
DELETE FROM `quest_details` WHERE `ID`=565;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(565,94,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=94, `EmoteOnComplete`=94 WHERE `ID`=565;
UPDATE `quest_offer_reward` SET `Emote1`=94 WHERE `ID`=565;

-- Quest "Noble Deaths"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=512;

-- Quest "Assassin's Contract"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=522;

-- Quest "Baron's Demise"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=523;
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=523;

-- Quest "The Ensorcelled Parchment"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=551;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=551;

-- Quest "Stormpike's Deciphering"
DELETE FROM `quest_details` WHERE `ID`=554;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(554,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=554;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=554;

-- Quest "Proving Grounds"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5 WHERE `ID`=7162;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7162;

-- Quest "Rise and Be Recognized"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1, `EmoteOnComplete`=1, `CompletionText`="Most do not live long enough to rise above their own mediocrity. You have proven yourself to be an exemplary soldier, $c. The time has come.$B$BPresent your insignia." WHERE `ID`=7168;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=7168;

-- Quest "Honored Amongst the Guard"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5, `CompletionText`="The base buzzes with news of your exploits in the Field of Strife! You have struck mighty blows against our enemy - crushing their morale! For this, you have earned a rank of honor among the Stormpike.$B$BPresent your insignia." WHERE `ID`=7169;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=7169;

-- Quest "Earned Reverence"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6, `CompletionText`="I must know, $n. When you look directly into the eyes of the enemy, do you see fear? Do they now cower in your presence? They must realize that they are defeated!$B$BYou have earned reverence among the Guard. Present your insignia!" WHERE `ID`=7170;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=7170;

-- Quest "Legendary Heroes"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=66, `EmoteOnComplete`=66, `CompletionText`="Before me stands an exalted hero of the Alliance.$B$B<Lieutenant Haggerdin salutes.>$B$BFew have earned such a rank among the Stormpike. I have watched the enemy fall before you. I have seen their resolve crumble in your presence. When you enter the fray, you become the beacon of hope for our forces!$B$BPresent your insignia." WHERE `ID`=7171;
UPDATE `quest_offer_reward` SET `Emote1`=25 WHERE `ID`=7171;

-- Quest "The Eye of Command"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5, `EmoteOnComplete`=5, `CompletionText`="Let them hear your voice, commander $n! Let them know fear. Show them what power the Stormpike holds in their rank!$B$BPresent your insignia." WHERE `ID`=7172;
UPDATE `quest_offer_reward` SET `Emote1`=66, `RewardText`="It is you who must lead our troops to victory, Commander! The soldiers are under your command. They will follow your direct orders. Lead them... Crush the Frostwolf." WHERE `ID`=7172;

-- Quest "Alterac Valley Graveyards"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=7081;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=7081;

-- Quest "Towers and Bunkers"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=7102;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=7102;

-- Quest "Capture a Mine"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=7122;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=7122;
