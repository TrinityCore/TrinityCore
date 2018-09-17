/*
-- 
-- Quest "Deadmire"
DELETE FROM `quest_details` WHERE `ID`=1205;
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1205;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1205;

-- Quest "The Brood of Onyxia"
DELETE FROM `quest_details` WHERE `ID`=1171;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1171,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote2`=0, `Emote3`=0 WHERE `ID`=1170;

-- Quest "The Theramore Docks"
UPDATE `quest_offer_reward` SET `Emote1`=66 WHERE `ID`=1202;

-- Quest "This Old Lighthouse"
DELETE FROM `quest_details` WHERE `ID`=11191;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11191,1,1,0,0,0,0,0,0,0);

-- Quest "Challenge Overlord Mok'Morokk"
DELETE FROM `quest_details` WHERE `ID`=1173;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1173,11,15,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1 WHERE `ID`=1173;

-- Quest "The Witch's Bane"
DELETE FROM `quest_details` WHERE `ID`=11181;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11181,1,1,0,0,0,0,0,0,0);

-- Quest "Cleansing Witch Hill"
DELETE FROM `quest_details` WHERE `ID`=11183;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11183,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=5, `Emote3`=1 WHERE `ID`=11183;

-- Quest "The Lost Report"
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1238;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1238;

-- Quest "The Severed Head"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1239;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1239;

-- Quest "The Troll Witchdoctor"
DELETE FROM `quest_details` WHERE `ID`=1240;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1240,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=1240;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1240;

-- Quest "Marg Speaks"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1261;
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=66 WHERE `ID`=1261;

-- Quest "Report to Zor"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1262;

-- Quest "Service to the Horde"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=7541;

-- Quest "Marsh Frog Legs"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6 WHERE `ID`=1218;
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=1218;

-- Quest "Jarl Needs Eyes"
DELETE FROM `quest_details` WHERE `ID`=1206;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1206,1,6,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1206;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1, `Emote3`=3 WHERE `ID`=1206;

-- Quest "Jarl Needs a Blade"
DELETE FROM `quest_details` WHERE `ID`=1203;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1203,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1203;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=36, `Emote3`=4 WHERE `ID`=1203;

-- Quest "Secure the Cargo!"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11207;

-- Quest "Delivery for Drazzit"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11208;

-- Quest "Catch a Dragon by the Tail"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11217;
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=0 WHERE `ID`=11217;

-- Banner of the Stonemaul
UPDATE `quest_details` SET `Emote3`=1 WHERE `ID` IN (11158,11160,11159,11162,11201,11203);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=15, `EmoteOnComplete`=15 WHERE `ID`=11162;
UPDATE `quest_offer_reward` SET `Emote2`=0 WHERE `ID`=11160;

-- Quest "Return to Krog"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=11204;

-- Quest "The Grimtotem Plot"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11201;
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1500 WHERE `ID`=11201;

-- Quest "More than Coincidence"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11200;
UPDATE `quest_offer_reward` SET `Emote2`=0, `EmoteDelay1`=2000 WHERE `ID`=11200;

-- Quest "Seek Out Tabetha"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=11203;

-- Quest "Raze Direhorn Post!"
UPDATE `quest_details` SET `Emote2`=5 WHERE `ID`=11205;
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11205;

-- Quest "Justice Dispensed"
UPDATE `quest_offer_reward` SET `Emote3`=66, `EmoteDelay1`=2000 WHERE `ID`=11206;

-- Quest "Thresher Oil"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11192;

-- Quest "They Call Him Smiling Jim"
DELETE FROM `quest_details` WHERE `ID`=1282;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1282,1,1,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=1, `Emote3`=1 WHERE `ID`=1282;

-- Quest "Inspecting the Ruins"
DELETE FROM `quest_details` WHERE `ID`=11123;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11123,1,1,1,0,0,0,0,0,0);

-- Quest "Traitors Among Us"
UPDATE `quest_details` SET `Emote2`=1 WHERE `ID` IN (11126,11128,11194,11133,11134,11177,11214,11136,11209,11210,11137,11146,11147,11145,11212,11138,11139,11140,11142,11149,11150,11151,11152);

-- Quest "Discrediting the Deserters"
UPDATE `quest_offer_reward` SET `EmoteDelay1`=2000 WHERE `ID`=11133;

-- Quest "The End of the Deserters"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1, `Emote3`=1 WHERE `ID`=11134;

-- Quest "Lieutenant Paval Reethe"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1252;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1252;

-- Quest "Lieutenant Paval Reethe"
DELETE FROM `quest_details` WHERE `ID`=1259;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1259,1,0,0,0,0,0,0,0,0);

-- Quest "Daelin's Men"
DELETE FROM `quest_details` WHERE `ID`=1285;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1285,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1285;

-- Quest "The Deserters"
DELETE FROM `quest_details` WHERE `ID`=1286;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1286,1,0,0,0,0,0,0,0,0);

-- Quest "Suspicious Hoofprints"
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=1284;

-- Quest "The Black Shield"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1253;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1253;

-- Quest "The Black Shield (Part 2)"
DELETE FROM `quest_details` WHERE `ID`=1319;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1319,1,0,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1319;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1319;

-- Quest "The Black Shield (Part 3)"
DELETE FROM `quest_details` WHERE `ID`=1320;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1320,1,3,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1320;

-- Quest "Oh, It's Real"
UPDATE `quest_offer_reward` SET `EmoteDelay1`=2000 WHERE `ID`=11210;

-- Quest "Raptor Captor"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11146;

-- Quest "What's Haunting Witch Hill?"
UPDATE `quest_offer_reward` SET `EmoteDelay1`=2000, `Emote2`=1 WHERE `ID`=11180;

-- Quest "The Orc Report"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1219;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1219;

-- Quest "Captain Vimes"
UPDATE `quest_request_items` SET `EmoteOnComplete`=0 WHERE `ID`=1220;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1220;

-- Quest "Stinky's Escape"
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=1222;

-- Quest "Prisoners of the Grimtotems"
UPDATE `quest_offer_reward` SET `Emote1`=2, `Emote2`=1 WHERE `ID`=11145;

-- Quest "Defias in Dustwallow?"
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1000, `Emote2`=1 WHERE `ID`=11137;

-- Quest "Renn McGill"
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1000 WHERE `ID`=11138;

-- Quest "Mudrock Soup and Bugs"
DELETE FROM `quest_details` WHERE `ID`=1204;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1204,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1204;
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=1 WHERE `ID`=1204;

-- Quest "... and Bugs"
DELETE FROM `quest_details` WHERE `ID`=1258;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1258,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=1258;
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1258;

-- Quest "Secondhand Diving Gear"
UPDATE `quest_offer_reward` SET `Emote2`=1 WHERE `ID`=11139;

-- Quest "Jaina Must Know"
UPDATE `quest_details` SET `Emote1`=5, `Emote2`=1 WHERE `ID`=11141;

-- Quest "The Deserters"
DELETE FROM `quest_details` WHERE `ID`=1287;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(1287,1,0,0,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=1287;

-- Quest "A Grim Connection"
DELETE FROM `quest_details` WHERE `ID`=11143;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11143,1,1,1,0,0,0,0,0,0);
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=11143;

-- Quest "Confirming the Suspicion"
DELETE FROM `quest_details` WHERE `ID`=11144;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11144,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11144;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=1000 WHERE `ID`=11144;

-- Quest "Arms of the Grimtotems"
DELETE FROM `quest_details` WHERE `ID`=11148;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11148,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11148;
UPDATE `quest_offer_reward` SET `Emote1`=1, `EmoteDelay1`=2000 WHERE `ID`=11148;

-- Quest "Direhorn Raiders"
UPDATE `quest_offer_reward` SET `Emote1`=273 WHERE `ID`=11156;

-- Quest "The Reagent Thief"
UPDATE `quest_offer_reward` SET `Emote2`=0, `EmoteDelay1`=1000 WHERE `ID`=11173;

-- Quest "The Grimtotem Weapon"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11169;
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1500 WHERE `ID`=11169;

-- Quest "The Zeppelin Crash"
UPDATE `quest_offer_reward` SET `Emote1`=6, `Emote2`=1 WHERE `ID`=11172;

-- Quest "Corrosion Prevention"
DELETE FROM `quest_details` WHERE `ID`=11174;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11174,5,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11174;

-- Quest "Secure the Cargo!"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11207;

-- Quest "The Apothecary's Letter"
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=11185;
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1500, `Emote2`=1 WHERE `ID`=11185;

-- Quest "Justice for the Hyals"
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1000 WHERE `ID`=11151;

-- Quest "Peace at Last"
UPDATE `quest_offer_reward` SET `EmoteDelay1`=1000, `Emote2`=1 WHERE `ID`=11152;

-- Quest "Shadowshard Fragments"
DELETE FROM `quest_details` WHERE `ID`=7070;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(7070,1,1,0,0,0,0,0,0,0);
UPDATE `quest_request_items` SET `EmoteOnIncomplete`=6, `EmoteOnComplete`=6 WHERE `ID`=7070;
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=2 WHERE `ID`=7070;
*/
