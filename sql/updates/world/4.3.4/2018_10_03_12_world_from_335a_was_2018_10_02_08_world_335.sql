/*
-- Quest "Ripple Recovery"
DELETE FROM `quest_details` WHERE `ID`=649;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(649,25,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=649;

-- Quest "Ripple Recovery"
DELETE FROM `quest_details` WHERE `ID`=650;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(650,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=650;

-- Quest "A Sticky Situation"
DELETE FROM `quest_details` WHERE `ID`=77;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(77,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=77;

-- Quest "Ripple Delivery"
DELETE FROM `quest_details` WHERE `ID`=81;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(81,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=81;

-- Quest "Vilebranch Hooligans"
DELETE FROM `quest_details` WHERE `ID`=7839;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7839,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7839;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=4 WHERE `ID`=7839;

-- Quest "Message to the Wildhammer"
DELETE FROM `quest_details` WHERE `ID`=7841;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7841,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7841;

-- Quest "Another Message to the Wildhammer"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7842;

-- Quest "The Final Message to the Wildhammer"
DELETE FROM `quest_details` WHERE `ID`=7843;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7843,25,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7843;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=7843;

-- Quest "Hunt the Savages"
DELETE FROM `quest_details` WHERE `ID`=7829;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7829,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=7829;

-- Quest "Avenging the Fallen"
DELETE FROM `quest_details` WHERE `ID`=7830;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7830,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=7830;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000 WHERE `ID`=7830;

-- Quest "Separation Anxiety"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7849;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=7849;

-- Quest "Cannibalistic Cousins"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7844;

-- Quest "Stalking the Stalkers"
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=7828;

-- Quest "Rin'ji's Secret"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=2782;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2782;

-- Quest "Oran's Gratitude"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8273;

-- Quest "Lines of Communication"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2995;

-- Quest "Venom Bottles"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2933;
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=2933;

-- Quest "Undamaged Venom Sac"
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2934;

-- Quest "Consult Master Gadrin"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2935;

-- Quest "The Spider God"
DELETE FROM `quest_details` WHERE `ID`=2936;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2936,1,0,0,0,0,0,0,0,0);

-- Quest "Summoning Shadra"
DELETE FROM `quest_details` WHERE `ID`=2937;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2937,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2937;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2937;

-- Quest "Venom to the Undercity"
DELETE FROM `quest_details` WHERE `ID`=2938;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2938,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2938;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=2 WHERE `ID`=2938;

-- Quest "Snapjaws, Mon!"
DELETE FROM `quest_details` WHERE `ID`=7815;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7815,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7815;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7815;

-- Quest "Gammerita, Mon!"
DELETE FROM `quest_details` WHERE `ID`=7816;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7816,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=7816;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=7816;

-- Quest "Lard Lost His Lunch"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=7840;

-- Quest "Dark Vessels"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=7850;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7850;

-- Quest "Job Opening: Guard Captain of Revantusk Village"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7862;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=7862;

-- Quest "Wanted: Vile Priestess Hexx and Her Minions"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=7861;
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=7861;

-- Quest "Return to Primal Torntusk"
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=7847;

-- Quest "Jammal'an the Prophet"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=1 WHERE `ID`=1446;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1446;

-- Quest "Reclaiming the Eggs"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=9475;

-- Quest "Troll Necklace Bounty"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=5 WHERE `ID`=2880;

-- Quest "The Altar of Zul" / "Thadius Grimshade"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2990;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (2989,2990);

-- Quest "Nekrum's Medallion"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2991;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2991;

-- Quest "The Divination"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2992;

-- Quest "Saving Sharpbeak"
DELETE FROM `quest_details` WHERE `ID`=2994;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2994,5,0,0,0,0,0,0,0,0);

-- Quest "Tran'rek"
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=2864;

-- Quest "Gadgetzan Water Survey"
UPDATE `quest_details` SET `Emote1`=1 WHERE `ID`=992;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=992;

-- Quest "WANTED: Caliph Scorpidsting"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2781;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2781;

-- Quest "Wastewander Justice"
DELETE FROM `quest_details` WHERE `ID`=1690;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1690,25,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1690;

-- Quest "More Wastewander Justice"
DELETE FROM `quest_details` WHERE `ID`=1691;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1691,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=1691;
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=1691;

-- Quest "Water Pouch Bounty"
DELETE FROM `quest_details` WHERE `ID`=1707;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1707,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=1707;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1707;

-- Quest "Water Pouch Bounty (Part 2)"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=1878;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1878;

-- Quest "Screecher Spirits"
DELETE FROM `quest_details` WHERE `ID`=3520;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3520,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=3520;

-- Quest "The Prophecy of Mosh'aru"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3527;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3527;

-- Quest "The Ancient Egg"
DELETE FROM `quest_details` WHERE `ID`=4787;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4787,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=4787;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=2 WHERE `ID`=4787;

-- Quest "The God Hakkar"
DELETE FROM `quest_details` WHERE `ID`=3528;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3528,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=3528;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1, `Emote3`=1 WHERE `ID`=3528;

-- Quest "Southsea Shakedown"
DELETE FROM `quest_details` WHERE `ID`=8366;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8366,5,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=6 WHERE `ID`=8366;

-- Quest "Pirate Hats Ahoy!"
DELETE FROM `quest_details` WHERE `ID`=8365;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8365,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=8365;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=8365;

-- Quest "WANTED: Andre Firebeard"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2875;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2875;

-- Quest "Ship Schedules"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2876;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=2876;

-- Quest "Divino-matic Rod"
DELETE FROM `quest_details` WHERE `ID`=2768;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2768,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=2768;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2768;

-- Quest "Into the Field"
DELETE FROM `quest_details` WHERE `ID`=243;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(243,1,1,0,0,0,0,0,0,0);

-- Quest "Slake That Thirst"
DELETE FROM `quest_details` WHERE `ID`=379;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(379,25,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=379;
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=379;

-- Quest "The Thirsty Goblin"
DELETE FROM `quest_details` WHERE `ID`=2605;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2605,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2605;
UPDATE `quest_offer_reward` SET `Emote1`=7 WHERE `ID`=2605;

-- Quest "In Good Taste"
DELETE FROM `quest_details` WHERE `ID`=2606;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2606,7,5,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2606;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2606;

-- Quest "Sprinkle's Secret Ingredient"
DELETE FROM `quest_details` WHERE `ID`=2641;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2641,1,11,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2641;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=2641;

-- Quest "Thistleshrub Valley"
DELETE FROM `quest_details` WHERE `ID`=3362;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3362,6,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=3362;

-- Quest "Scarab Shells"
DELETE FROM `quest_details` WHERE `ID`=2865;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2865,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2865;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=2865;

-- Quest "Gahz'ridian"
DELETE FROM `quest_details` WHERE `ID`=3161;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3161,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3161;

-- Quest "Noxious Lair Investigation"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=82;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=82;

-- Quest "Tanaris Field Sampling"
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID`=654;

-- Quest "The Scrimshank Redemption"
DELETE FROM `quest_details` WHERE `ID`=10;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(10,5,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=10;

-- Quest "Rise of the Silithid"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=32;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=32;

-- Quest "March of the Silithid"
DELETE FROM `quest_details` WHERE `ID` IN (4493,4494);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4493,1,0,0,0,0,0,0,0,0),
(4494,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (4493,4494);

-- Quest "Return to Apothecary Zinge"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=864;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=864;

-- Quest "The Stone Circle"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3444;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=3444;

-- Quest "Delivery for Marin"
DELETE FROM `quest_details` WHERE `ID`=2661;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2661,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=2661;

-- Quest "Noggenfogger Elixir"
DELETE FROM `quest_details` WHERE `ID`=2662;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(2662,5,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=5, `Emote3`=11 WHERE `ID`=2662;

-- Quest "Handle With Care"
DELETE FROM `quest_details` WHERE `ID`=3022;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3022,4,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3022;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3022;

-- Quest "Troll Temper"
DELETE FROM `quest_details` WHERE `ID`=3042;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(3042,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=3042;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=3042;

-- Quest "Super Sticky"
UPDATE `quest_request_items` SET `EmoteOnComplete`=4, `EmoteOnIncomplete`=4 WHERE `ID`=4504;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4504;

-- Quest "A Bad Egg"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=2750;
UPDATE `quest_offer_reward` SET `Emote1`=274, `Emote1`=1 WHERE `ID`=2750;

-- Quest "An Ordinary Egg"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=2749;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote1`=1 WHERE `ID`=2749;

-- Quest "A Fine Egg"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=2748;
UPDATE `quest_offer_reward` SET `Emote1`=273, `Emote1`=1 WHERE `ID`=2748;

-- Quest "An Extraordinary Egg"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=2747;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote1`=1 WHERE `ID`=2747;

-- Quest "Bungle in the Jungle"
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=4496;

-- Quest "Pawn Captures Queen"
DELETE FROM `quest_details` WHERE `ID`=4507;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4507,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=1, `EmoteOnIncomplete`=1 WHERE `ID`=4507;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=4507;

-- Quest "Calm Before the Storm"
DELETE FROM `quest_details` WHERE `ID` IN (4508,4509);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4508,1,0,0,0,0,0,0,0,0),
(4509,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=5, `EmoteOnIncomplete`=5 WHERE `ID` IN (4508,4509);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (4508,4509);

-- Quest "Calm Before the Storm (Part 2)"
DELETE FROM `quest_details` WHERE `ID` IN (4510,4511);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4510,1,0,0,0,0,0,0,0,0),
(4511,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=2, `EmoteOnIncomplete`=2 WHERE `ID` IN (4510,4511);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID` IN (4510,4511);

-- Quest "Yuka Screwspigot"
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=4324;

-- Quest "The Lost Tablets of Mosh'aru"
DELETE FROM `quest_details` WHERE `ID`=5065;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(5065,274,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=5065;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=5065;

-- Quest "The Final Tablets"
DELETE FROM `quest_details` WHERE `ID`=4788;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(4788,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6 WHERE `ID`=4788;
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=4788;

-- Quest "Confront Yeh'kinya"
DELETE FROM `quest_details` WHERE `ID`=8181;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8181,1,5,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5 WHERE `ID`=8181;

-- Quest "The Hand of Rastakhan"
DELETE FROM `quest_details` WHERE `ID`=8182;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(8182,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=8182;
*/
