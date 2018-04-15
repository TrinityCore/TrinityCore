-- 
DELETE FROM `quest_offer_reward` WHERE `ID`=14011;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(14011, 4, 0, 0, 0, 0, 0, 0, 0, "There you go, boss!$B$BCome back anytime you want more training. I'll teach you what I know.", 15595); -- Primal Strike
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=5, `Emote3`=11 WHERE `ID`=14126; -- Life Savings
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=25 WHERE `ID`=14125; -- 447
UPDATE `quest_offer_reward` SET `Emote1`=4  WHERE `ID`=14122; -- The Great Bank Heist
UPDATE `quest_offer_reward` SET `Emote1`=6  WHERE `ID`=14121; -- Robbing Hoods
UPDATE `quest_offer_reward` SET `Emote1`=5  WHERE `ID`=14123; -- Waltz Right In
UPDATE `quest_offer_reward` SET `Emote1`=21 WHERE `ID`=14124; -- Liberate the Kaja'mite
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=14120; -- A Bazillion Macaroons?!
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=14116; -- The Uninvited Guest
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=14115; -- Pirate Party Crashers
UPDATE `quest_offer_reward` SET `Emote1`=4, `Emote2`=6 WHERE `ID`=14153; -- Life of the Party
UPDATE `quest_offer_reward` SET `Emote1`=4  WHERE `ID`=14070; -- Do it Yourself
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=14110; -- The New You
UPDATE `quest_offer_reward` SET `Emote1`=25, `Emote2`=5 WHERE `ID`=26711; -- Off to the Bank
UPDATE `quest_offer_reward` SET `Emote1`=5, `Emote2`=273, `EmoteDelay2`=1000 WHERE `ID`=24520; -- Give Sassy the News
UPDATE `quest_offer_reward` SET `Emote1`=5, `EmoteDelay1`=1000 WHERE `ID`=24503; -- Fourth and Goal
UPDATE `quest_offer_reward` SET `Emote1`=71 WHERE `ID`=24488; -- The Replacements
UPDATE `quest_offer_reward` SET `Emote1`=5 WHERE `ID`=24567; -- Report for Tryouts
UPDATE `quest_offer_reward` SET `Emote1`=4 WHERE `ID`=14071; -- Rolling with my Homies
UPDATE `quest_offer_reward` SET `Emote1`=3 WHERE `ID`=28349; -- Megs in Marketing
UPDATE `quest_offer_reward` SET `Emote1`=1, `Emote2`=25, `EmoteDelay2`=1000 WHERE `ID`=25473; -- Kaja'Cola
UPDATE `quest_offer_reward` SET `Emote1`=2 WHERE `ID`=14069; -- Good Help is Hard to Find
UPDATE `quest_offer_reward` SET `Emote1`=1 WHERE `ID`=14075; -- Trouble in the Mines
UPDATE `quest_offer_reward` SET `Emote1`=6 WHERE `ID`=14138; -- Taking Care of Business

UPDATE `quest_poi` SET `VerifiedBuild`=15595 WHERE (`QuestID`=14011 AND `id`=1); -- Primal Strike
UPDATE `quest_poi` SET `VerifiedBuild`=15595 WHERE (`QuestID`=14011 AND `id`=0); -- Primal Strike
UPDATE `quest_poi_points` SET `VerifiedBuild`=15595 WHERE (`QuestID`=14011 AND `Idx1`=1 AND `Idx2`=3); -- Primal Strike
UPDATE `quest_poi_points` SET `VerifiedBuild`=15595 WHERE (`QuestID`=14011 AND `Idx1`=1 AND `Idx2`=2); -- Primal Strike
UPDATE `quest_poi_points` SET `VerifiedBuild`=15595 WHERE (`QuestID`=14011 AND `Idx1`=1 AND `Idx2`=1); -- Primal Strike
UPDATE `quest_poi_points` SET `VerifiedBuild`=15595 WHERE (`QuestID`=14011 AND `Idx1`=1 AND `Idx2`=0); -- Primal Strike
UPDATE `quest_poi_points` SET `VerifiedBuild`=15595 WHERE (`QuestID`=14011 AND `Idx1`=0 AND `Idx2`=0); -- Primal Strike

UPDATE `quest_request_items` SET `EmoteOnComplete`=1 WHERE `ID`=14126; -- Life Savings
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=14121; -- Robbing Hoods
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=14123; -- Waltz Right In
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=14124; -- Liberate the Kaja'mite
UPDATE `quest_request_items` SET `EmoteOnComplete`=6 WHERE `ID`=14110; -- The New You
UPDATE `quest_request_items` SET `EmoteOnComplete`=397 WHERE `ID`=24488; -- The Replacements
UPDATE `quest_request_items` SET `EmoteOnComplete`=5 WHERE `ID`=25473; -- Kaja'Cola
UPDATE `quest_request_items` SET `EmoteOnComplete`=3 WHERE `ID`=14138; -- Taking Care of Business

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `map`=648);
DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `map`=648);
DELETE FROM `creature` WHERE `map`=648;
DELETE FROM `gameobject` WHERE `map`=648;

SET @CGUID:=251576;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2194;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 37804, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8384.379, 1753.526, 193.101, 4.031815, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kaja'Cola Balloon (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+1, 34878, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8468.401, 1566.158, 47.48344, 0.3490658, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Sudsy Magee (Area: -Unknown- - Difficulty: 0) (Auras: 66146 - Do it Yourself: Cat's Mark - Sudsy) (possible waypoints or random movement)
(@CGUID+2, 49774, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8505.4, 1290.414, 102.5733, 4.219358, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: -Unknown- - Difficulty: 0)
(@CGUID+3, 35304, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8452.25, 1248.42, 56.93103, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brute Enforcer (Area: -Unknown- - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+4, 35304, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8447.596, 1243.498, 56.54166, 3.892084, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brute Enforcer (Area: -Unknown- - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+5, 35239, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8482.129, 1256.389, 59.02859, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: -Unknown- - Difficulty: 0)
(@CGUID+6, 35239, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8430.875, 1228.696, 50.34428, 1.37881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: -Unknown- - Difficulty: 0)
(@CGUID+7, 35239, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8420.636, 1219.646, 53.42688, 1.029744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: -Unknown- - Difficulty: 0)
(@CGUID+8, 34830, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8472.779, 1236.781, 52.6249, 0.6806784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: -Unknown- - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep)
(@CGUID+9, 35239, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8471.181, 1227.925, 47.43909, 2.373648, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: -Unknown- - Difficulty: 0)
(@CGUID+10, 34830, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8471.495, 1217.075, 46.22297, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: -Unknown- - Difficulty: 0) (Auras: 45111 - Enrage) (possible waypoints or random movement)
(@CGUID+11, 35239, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8487.71, 1226.361, 45.47562, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: -Unknown- - Difficulty: 0)
(@CGUID+12, 35239, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8431.933, 1218.451, 46.16586, 0.7330383, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: -Unknown- - Difficulty: 0)
(@CGUID+13, 34830, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8439.386, 1213.819, 45.25401, 4.066617, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: -Unknown- - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+14, 35239, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8413.004, 1212.781, 53.49294, 0.2094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: -Unknown- - Difficulty: 0)
-- (@CGUID+15, 34835, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8403.81, 1517.438, 50.81741, 1.954769, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Bruno Flameretardant (Area: -Unknown- - Difficulty: 0) (Auras: 90317 - Do it Yourself: Cat's Mark - Bruno, 75773 - Burning Weapon) (possible waypoints or random movement)
(@CGUID+16, 49774, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8337.101, 1449.88, 46.8319, 3.677952, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: -Unknown- - Difficulty: 0)
(@CGUID+17, 35063, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8349.681, 1457.118, 47.95893, 1.32645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0)
(@CGUID+18, 35075, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8338.298, 1444.147, 46.48925, 3.368485, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+19, 35075, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8355.154, 1443.384, 48.52741, 0.8901179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0)
(@CGUID+20, 35075, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8326.382, 1472.715, 46.06821, 0.1745329, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 35222, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8270.277, 1446.66, 40.39114, 6.028785, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Trade Prince Gallywix (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+22, 35063, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8357.791, 1483.951, 47.50119, 6.003932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0)
(@CGUID+23, 35063, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8365.741, 1470.828, 47.48645, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0)
(@CGUID+24, 35063, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8278.646, 1425.521, 39.47568, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0)
(@CGUID+25, 35063, 648, 0, 0, 1, 1, 169, 0, 0, 0, -8255.196, 1434.913, 40.25389, 1.48353, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: -Unknown- - Difficulty: 0)
(@CGUID+26, 34673, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8429.455, 1311.641, 103.5002, 4.093115, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Bamm Megabomb (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+27, 34695, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8415.516, 1321.444, 103.8445, 0.6981317, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Maxx Avalanche (Area: KTC Headquarters - Difficulty: 0) (Auras: 78273 - Flametongue Weapon) (possible waypoints or random movement)
(@CGUID+28, 48304, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer) (possible waypoints or random movement)
(@CGUID+29, 34668, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8423.816, 1366.066, 104.8147, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sassy Hardwrench (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+30, 48305, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8427.96, 1342.02, 102.3393, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Injured Employee (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+31, 34692, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8425.401, 1347.615, 105.1465, 5.009095, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sister Goldskimmer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+32, 35053, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8425.201, 1367.755, 104.7604, 5.078908, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Candy Cane (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+33, 48304, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8430.86, 1302.59, 102.7883, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+34, 35054, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8422.143, 1367.708, 104.7585, 4.572762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Chip Endale (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+35, 34872, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8402.308, 1314.974, 102.3311, 4.485496, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Foreman Dampwick (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+36, 34697, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8431.764, 1313.502, 103.0257, 0.8726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warrior-Matic NX-01 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+37, 48304, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8432.97, 1306.71, 102.5413, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+38, 48305, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8437.77, 1333.63, 102.2233, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Injured Employee (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+39, 34874, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8419.259, 1341.816, 102.9996, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Megs Dreadshredder (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+40, 48305, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8436.32, 1315.49, 102.3183, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Injured Employee (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+41, 48304, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8436.88, 1305.78, 102.5663, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+42, 49773, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8437.366, 1310.728, 103.0158, 1.412372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+43, 48304, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8436.39, 1310.16, 102.4263, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+44, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8385.563, 1146.713, 36.50817, 4.416492, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+45, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8426.907, 1184.876, 40.72876, 3.67384, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+46, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8387.101, 1147.323, 36.49709, 5.972198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+47, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8472.373, 1189.135, 42.01694, 0.1570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+48, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8413.41, 1203.432, 45.22784, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+49, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8426.341, 1167.413, 40.52151, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+50, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8495.29, 1173.333, 42.01693, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+51, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8425.79, 1189.443, 40.78189, 0.9948376, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+52, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8479.413, 1210.085, 42.01694, 6.091199, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+53, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8463.582, 1190.373, 42.01607, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+54, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8465.205, 1118.858, 42.71806, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+55, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8406.583, 1154.205, 38.38482, 3.423771, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+56, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8472.389, 1178.661, 42.01386, 2.827433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage) (possible waypoints or random movement)
(@CGUID+57, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8448.729, 1175.344, 40.92472, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+58, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8439.622, 1136.01, 47.04106, 5.480334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+59, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8463.627, 1185.345, 42.01415, 0.03490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep)
(@CGUID+60, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8472.122, 1183.648, 42.01694, 0.08726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+61, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8413.04, 1183.441, 45.2278, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+62, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8470.625, 1159.264, 40.7509, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep) (possible waypoints or random movement)
(@CGUID+63, 2110, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8488.992, 1211.117, 42.0018, 0.2901407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+64, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8430.582, 1164.851, 40.81522, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep) (possible waypoints or random movement)
(@CGUID+65, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8436.028, 1153.007, 44.04847, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage) (possible waypoints or random movement)
(@CGUID+66, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8433.752, 1148.226, 44.05191, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+67, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8492.042, 1163.483, 41.92026, 0.5061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+68, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8445.007, 1124.243, 44.92519, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+69, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8460.159, 1130.551, 39.81519, 3.936177, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+70, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8462.332, 1179.326, 41.93526, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+71, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8467.061, 1194.146, 42.01694, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage) (possible waypoints or random movement)
(@CGUID+72, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8416.636, 1169.106, 41.71442, 2.303835, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+73, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8436.922, 1198.668, 40.63494, 5.001286, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+74, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8452.643, 1148.592, 40.80893, 2.059489, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep) (possible waypoints or random movement)
(@CGUID+75, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8453.372, 1142.042, 40.34196, 4.869469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+76, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8392.185, 1145.642, 37.07203, 2.024582, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+77, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8430.651, 1195.91, 40.74375, 3.665191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage) (possible waypoints or random movement)
(@CGUID+78, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8500.326, 1140.743, 47.37446, 2.426008, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+79, 2110, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8488.736, 1137.469, 43.33307, 4.915623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+80, 2110, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8361.997, 1117.696, 32.33604, 3.576422, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+81, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8499.922, 1151.96, 46.19245, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+82, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8358.229, 1135.194, 34.20668, 5.947082, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+83, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8508.935, 1180.597, 46.30149, 3.839724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+84, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8509.286, 1147.597, 54.30568, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+85, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8355.357, 1117.606, 32.42305, 3.32776, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+86, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8486.167, 1131.972, 41.44668, 0.8552113, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+87, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8509.21, 1174.983, 51.47308, 0.08726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+88, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8492.962, 1108.518, 42.52382, 1.980941, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+89, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8499.486, 1155.337, 46.19245, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+90, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8458.745, 1113.299, 47.7154, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+91, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8365.942, 1117.443, 32.35616, 0.2567212, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+92, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8498.656, 1221.043, 50.52885, 6.143559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+93, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8485.79, 1117.722, 43.56778, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep)
(@CGUID+94, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8357.528, 1144.276, 34.91758, 2.478368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep)
(@CGUID+95, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8501.585, 1145.943, 54.30568, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+96, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8514.286, 1175.776, 51.47308, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+97, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8519.849, 1158.2, 58.11637, 2.408554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+98, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8363.256, 1150.896, 34.65276, 0.5113582, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+99, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8511.837, 1161.444, 51.32607, 3.01942, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+100, 49132, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8376.433, 1339.108, 102.0984, 1.37881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: Kaja'mine - Difficulty: 0)
(@CGUID+101, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8539.34, 1263.03, 52.88164, 3.843817, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+102, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8502.641, 1095.635, 42.0255, 0.9250245, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep)
(@CGUID+103, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8526.223, 1214.399, 61.06351, 2.513274, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+104, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8497.14, 1070.28, 41.61939, 2.217692, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+105, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8500.54, 1088.95, 41.72147, 0.783173, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+106, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8517.734, 1243.852, 54.93032, 2.478368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+107, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8534.192, 1264.155, 54.16807, 5.026548, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage, 62248 - Sleeping Sleep)
(@CGUID+108, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8530.319, 1227.163, 59.5932, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+109, 35239, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8516.576, 1234.373, 54.18729, 2.094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Slave (Area: Kaja'mine - Difficulty: 0)
(@CGUID+110, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8558.904, 1266.892, 47.94035, 0.03490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+111, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8510.34, 1061.68, 42.59779, 5.354827, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+112, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8499.215, 1062.066, 41.74364, 1.005222, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+113, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8497.201, 1064.302, 41.74564, 1.48353, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+114, 2110, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8529.044, 1070.011, 42.95057, 5.412134, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+115, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8534.054, 1046.875, 42.10005, 3.947016, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+116, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8531.741, 1064.495, 42.56243, 0.0394726, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+117, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8562.604, 1268.057, 46.92116, 5.162828, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+118, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8582.371, 1253.29, 46.0441, 5.800467, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+119, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8560.717, 1279.79, 46.74131, 5.891298, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+120, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8587.05, 1265.22, 45.05152, 4.740019, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+121, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8599.64, 1231.68, 46.74301, 5.865192, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+122, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8608.594, 1270.207, 42.49811, 2.063577, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+123, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8608.693, 1297.68, 40.66618, 2.327989, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+124, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8597.976, 1291.807, 42.09294, 1.137739, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+125, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8598.79, 1250.61, 45.29898, 5.467868, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+126, 2110, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8618.83, 1277.145, 41.15717, 3.020114, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+127, 34830, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8585.906, 1270.894, 44.83153, 5.986479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+128, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8624.77, 1282.61, 40.39154, 0.4482048, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+129, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8618.274, 1308.932, 38.12619, 5.899973, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+130, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8633.698, 1327.254, 33.86401, 2.863152, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+131, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8654.27, 1317.71, 29.54049, 0.8881197, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+132, 4076, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8635.247, 1351.333, 33.87107, 0.493388, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+133, 2110, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8644.867, 1323.442, 31.58741, 2.345451, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+134, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8631.16, 1348.94, 34.17592, 3.942148, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+135, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8647.39, 1364.09, 32.07354, 4.544248, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+136, 2110, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8661.378, 1355.21, 29.21053, 3.722074, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+137, 34865, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8670.509, 1354.121, 27.13829, 3.695598, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+138, 37762, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8381.931, 1319.274, 103.9861, 4.066617, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brett "Coins" McQuid (Area: Kaja'mine - Difficulty: 0)
(@CGUID+139, 37761, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8382.889, 1318.104, 104.1712, 0.9075712, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sally "Salvager" Sandscrew (Area: Kaja'mine - Difficulty: 0)
(@CGUID+140, 34689, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8394.614, 1325.67, 103.0017, 2.268928, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Fizz Lighter (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+141, 34693, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8416.872, 1332.5, 102.375, 3.241643, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: Kaja'mine - Difficulty: 0) (Auras: 80264 - Stealth) (possible waypoints or random movement)
(@CGUID+142, 49150, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8402.134, 1363.582, 105.1978, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Subject Nine (Area: Kaja'mine - Difficulty: 0) (Auras: 91603 - Subject Nine: Gizmo Helmet)
(@CGUID+143, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8403.802, 1356.153, 109.954, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+144, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8411.185, 1356.425, 110.5265, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+145, 34696, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8399.56, 1346.439, 103.0947, 5.183628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Evol Fingers (Area: Kaja'mine - Difficulty: 0) (Auras: )
(@CGUID+146, 48305, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8405.74, 1343.66, 102.3913, 3.926991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Injured Employee (Area: Kaja'mine - Difficulty: 0)
(@CGUID+147, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8402.79, 1355.908, 110.1566, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+148, 24288, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8407.071, 1363.757, 104.1039, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Hide Body (Area: Kaja'mine - Difficulty: 0)
(@CGUID+149, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8411.011, 1356.238, 109.9257, 5.148721, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+150, 48496, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8405.351, 1360.282, 104.0212, 3.857178, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Assistant Greely (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+151, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8402.844, 1356.281, 111.4267, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+152, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8411.56, 1356.08, 111.2718, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+153, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8410.723, 1356.769, 110.1166, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+154, 48494, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8406.944, 1359.194, 104.4312, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hobart Grapplehammer (Area: Kaja'mine - Difficulty: 0)
(@CGUID+155, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8403.348, 1356.62, 110.3372, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+156, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8403.198, 1356.283, 109.4929, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+157, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8410.484, 1356.29, 110.2317, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+158, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8402.857, 1356.431, 110.7395, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+159, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8411.212, 1357.012, 111.7263, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+160, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8402.645, 1356.01, 111.3591, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+161, 24021, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8411.069, 1356.46, 111.7041, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Kaja'mine - Difficulty: 0)
(@CGUID+162, 49132, 648, 4737, 4766, 1, 1, 169, 0, 0, 0, -8297.386, 1427.033, 39.91657, 1.029744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: Kaja'mine - Difficulty: 0)
(@CGUID+163, 49132, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8369.714, 1467.391, 47.73921, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+164, 34890, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8507.65, 1342.85, 101.7803, 6.265732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Izzy (Area: KTC Headquarters - Difficulty: 0) (Auras: 66405 - Rolling with my Homies: Invisibility 03 - ""Izzy"")
(@CGUID+165, 48519, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8406.926, 1356.2, 104.8625, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Micro Mechachicken (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+166, 34954, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8179.48, 1321.38, 27.68263, 5.253441, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gobber (Area: KTC Headquarters - Difficulty: 0) (Auras: 66404 - Rolling with my Homies: Invisibility 02 - ""Gobber"")
(@CGUID+167, 49772, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8235.732, 1260.393, 26.61925, 1.548566, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+168, 35075, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8173.016, 1322.708, 27.60278, 3.071779, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+169, 49774, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8212.367, 1370.794, 36.08688, 2.461361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+170, 49773, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8148.869, 1238.555, 19.60593, 5.729507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+171, 35075, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8188.021, 1309.896, 27.60278, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+172, 35075, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8173.563, 1264.556, 25.35967, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+173, 35063, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8174.318, 1322.825, 27.60278, 6.178465, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+174, 35063, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8180.184, 1274.618, 25.91235, 1.658063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+175, 49774, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8158.595, 1331.955, 25.72901, 1.32416, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+176, 35075, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8167.696, 1258.462, 24.66135, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+177, 35063, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8123.075, 1368.962, 12.9586, 0.5585054, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0)
(@CGUID+178, 35063, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8109.257, 1359.1, 14.07059, 6.253659, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+179, 35063, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8119.526, 1369.663, 12.80686, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0)
(@CGUID+180, 49772, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8108.283, 1270.753, 21.07929, 5.181139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: 0 - Difficulty: 0)
(@CGUID+181, 34892, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8068.13, 1482.03, 9.014693, 3.595378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ace (Area: 0 - Difficulty: 0) (Auras: 66403 - Rolling with my Homies: Invisibility 01 - ""Ace"")
(@CGUID+182, 6827, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8054.636, 1339.092, 6.395264, 3.296469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+183, 35075, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8049.394, 1354.59, 5.584659, 6.056293, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0)
(@CGUID+184, 35075, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8036.721, 1322.17, 4.123469, 1.827505, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+185, 35063, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8053.206, 1340.686, 6.191504, 5.515063, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+186, 6827, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8051.021, 1363.183, 5.132202, 4.682251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+187, 35075, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8034.79, 1322.691, 3.727473, 1.834371, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+188, 49131, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8063.356, 1495.401, 9.345519, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+189, 49133, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8033.382, 1494.304, 10.10497, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Epic Trike (Area: 0 - Difficulty: 0)
(@CGUID+190, 6827, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8051.278, 1393.347, 2.99471, 2.980621, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+191, 49773, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8109.925, 1411.087, 9.977329, 1.104681, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: 0 - Difficulty: 0)
(@CGUID+192, 49132, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8063.472, 1503.656, 9.164498, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+193, 49772, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8087.11, 1438.514, 9.849239, 3.173991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: 0 - Difficulty: 0)
(@CGUID+194, 35063, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8047.499, 1381.169, 2.84655, 2.280913, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+195, 35063, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8047.496, 1418.422, 0.5518493, 5.917129, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+196, 49774, 648, 4737, 0, 1, 1, 169, 0, 0, 0, -8128.85, 1429.948, 10.87674, 4.787131, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: 0 - Difficulty: 0)
(@CGUID+197, 37046, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8071.353, 1482.762, 8.934028, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Not Floating) (Area: Bilgewater Port - Difficulty: 0) (Auras: )
(@CGUID+198, 37046, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8076.524, 1491.274, 8.914551, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Not Floating) (Area: Bilgewater Port - Difficulty: 0) (Auras: )
(@CGUID+199, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8082.95, 1469.076, 8.926544, 2.373648, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+200, 24021, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8067.885, 1485.495, 10.51868, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+201, 37056, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8072.689, 1483.768, 8.926544, 3.169561, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+202, 37057, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8075.775, 1493.195, 8.926544, 3.206854, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+203, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8084.092, 1470.198, 8.926544, 5.550147, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+204, 37055, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8078.214, 1490.073, 8.926544, 3.648844, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+205, 37046, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8072.045, 1494.718, 8.926544, 2.924321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Not Floating) (Area: Bilgewater Port - Difficulty: 0) (Auras: )
(@CGUID+206, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8065.549, 1464.684, 9.55556, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+207, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8063.222, 1517.561, 9.190204, 1.692969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+208, 49132, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8225.313, 1608.523, 33.63165, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+209, 4076, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8029.166, 1466.146, 9.053576, 0.3221255, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+210, 49774, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8162.084, 1496.248, 41.57534, 0.3750731, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+211, 49772, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8082.987, 1542.18, 8.996634, 3.73678, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+212, 37046, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8072.115, 1503.684, 8.914551, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Not Floating) (Area: Bilgewater Port - Difficulty: 0) (Auras: )
(@CGUID+213, 24021, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8067.618, 1494.582, 10.49888, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+214, 37054, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8072.236, 1502.243, 8.868902, 4.898082, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Bilgewater Port - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+215, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8119.42, 1521.849, 10.61598, 5.951573, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+216, 24021, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8067.641, 1494.582, 10.52287, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+217, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8031.101, 1487.311, 10.10813, 6.265732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+218, 24021, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8067.288, 1503.156, 10.37352, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (scale x0.01) (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+219, 4076, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8052.309, 1514.439, 9.357403, 0.7533859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+220, 49773, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8070.989, 1562.546, 6.888236, 5.737632, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+221, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8110.416, 1560.938, 9.067751, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+222, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8008.241, 1550.231, 1.675241, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+223, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8008.941, 1554.51, 1.79982, 4.974188, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+224, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8006.647, 1547.405, 1.587714, 1.291544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+225, 6827, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8019.947, 1543.136, 2.074095, 6.230525, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+226, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8039.599, 1563.758, 1.939747, 1.761119, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+227, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -7994.693, 1521.264, 1.862897, 0.54682, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+228, 6827, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -7979.914, 1511.697, -0.5628843, 1.109332, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+229, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8125.269, 1588.13, 12.75527, 0.1396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+230, 6827, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8015.394, 1593.199, 2.277824, 1.920104, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+231, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8037.753, 1590.943, 2.124179, 5.689773, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+232, 6827, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -7969.23, 1508.682, -2.990066, 0.3109318, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+233, 6827, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -7989.128, 1550.904, -0.4845156, 4.700469, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+234, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8122.347, 1588.16, 12.74023, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+235, 4076, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8132.46, 1603.747, 14.57723, 5.976161, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+236, 2110, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8132.291, 1605.208, 14.26717, 1.227079, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+237, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8013.772, 1610.662, 2.502736, 3.247251, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+238, 6827, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8008.887, 1599.456, 2.646641, 0.1304542, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+239, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8134.205, 1583.165, 14.2966, 4.764749, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+240, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8003.921, 1587.67, 2.516392, 2.747885, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+241, 35130, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8143.078, 1583.531, 16.94905, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Missa Spekkies (Area: Bilgewater Port - Difficulty: 0) (Auras: 90818 - The New You: Cat's Mark - Missa Spekkies)
(@CGUID+242, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8038.055, 1646.133, 2.210083, 3.543422, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+243, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8038.548, 1649.674, 2.817026, 2.91699, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+244, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7995.803, 1651.112, 2.360153, 5.314476, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+245, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7979.604, 1654.502, 0.1945046, 6.122214, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+246, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8003.99, 1668, 2.910762, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+247, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8119.791, 1633.333, 13.32967, 4.694936, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+248, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7989.744, 1684.604, 1.99873, 4.671013, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+249, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7990.157, 1694.797, 1.591181, 0.7881606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+250, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7988.676, 1690.056, 1.492383, 4.585316, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+251, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8119.791, 1630.208, 13.70467, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+252, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8145.67, 1652.188, 16.3551, 2.96706, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+253, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8142.353, 1628.819, 15.11128, 3.996804, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+254, 35126, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8142.792, 1658.632, 16.73927, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gappy Silvertooth (Area: The Slick - Difficulty: 0) (Auras: 90814 - The New You: Cat's Mark - Gappy Silvertooth)
(@CGUID+255, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8129.323, 1626.632, 15.07492, 6.195919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+256, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8135.512, 1626.111, 15.30948, 6.038839, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+257, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8118.188, 1654.214, 12.21747, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+258, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8000.194, 1713.023, 2.539295, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+259, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7978.563, 1717.451, -2.985126, 5.222379, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+260, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8027.273, 1718.602, 1.719939, 2.5075, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+261, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8014.2, 1746.177, 1.601897, 1.9587, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+262, 49131, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8038.452, 1860.379, 52.59888, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: The Slick - Difficulty: 0)
(@CGUID+263, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7996.843, 1774.57, -6.821191, 0.7072486, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+264, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7999.635, 1711.233, 2.570553, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+265, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8031.887, 1781.601, 1.15147, 2.315443, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+266, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8030.114, 1737.639, 0.9605393, 5.1336, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+267, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8016.051, 1745.421, 1.710539, 1.958676, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+268, 35623, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7971.874, 1833.807, 12.7881, 3.333579, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: The Slick - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+269, 35623, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8098.186, 1809.922, 33.54742, 4.206244, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: The Slick - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+270, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8119.483, 1734.219, 18.98853, 2.094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+271, 35623, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7971.128, 1825.84, 11.57353, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: The Slick - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+272, 49772, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8093.994, 1825.684, 37.72233, 1.771449, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: The Slick - Difficulty: 0)
(@CGUID+273, 35623, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8087.019, 1806.361, 34.80576, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: The Slick - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+274, 49773, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8122.654, 1739.454, 19.85637, 4.707916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: The Slick - Difficulty: 0)
(@CGUID+275, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8121.075, 1735.776, 19.25174, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+276, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8119.068, 1736.613, 19.37153, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+277, 35623, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8047.698, 1850.649, 52.27689, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: The Slick - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+278, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8044.345, 1783.447, 1.457795, 6.040576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+279, 35623, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8074.365, 1829.589, 42.77965, 3.735005, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: The Slick - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+280, 49772, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8197.364, 1754.226, 43.35272, 0.02100378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+281, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8179.257, 1788.021, 30.21052, 4.171337, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+282, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8180.62, 1786.031, 30.26515, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+283, 49772, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8139.796, 1788.9, 23.09365, 5.009186, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+284, 4076, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8134.076, 1755.148, 21.3077, 0.5073281, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+285, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8142.327, 1893.328, 68.69312, 4.660029, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+286, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8040.354, 1890.977, 53.35822, 0.3141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+287, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8123.031, 1895.425, 54.59142, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+288, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8122.302, 1885.582, 54.59142, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+289, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8043.033, 1890.865, 53.35851, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+290, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8068.813, 1883.79, 54.52212, 0.1047198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+291, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8032.736, 1867.427, 52.60769, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+292, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8043.05, 1917.356, 53.35838, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+293, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8144.372, 1909.469, 70.19218, 2.897247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (Auras: 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+294, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8022.774, 1906.24, 51.58494, 5.289565, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+295, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8004.653, 1891.245, 53.3581, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+296, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8038.797, 1890.906, 53.35835, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+297, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8028.422, 1926.531, 52.59875, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+298, 49774, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -7993.449, 1875.347, 54.05229, 5.064032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+299, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8008.016, 1904.274, 52.97827, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+300, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8015.394, 1949.004, 53.6531, 4.08407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+301, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -7999.851, 1900.627, 52.59884, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+302, 49774, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8120.705, 1912.732, 54.84854, 5.924382, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+303, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8020.358, 1884.137, 53.00055, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (Auras: 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+304, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8042.535, 1906.257, 53.35592, 5.585053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (Auras: 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+305, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8148.338, 1906.427, 55.85408, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+306, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8022.953, 1898.741, 51.55669, 3.623772, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+307, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8042.363, 1902.957, 53.35597, 0.1047198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+308, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8013.823, 1916.444, 53.35815, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (Auras: 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+309, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8039.043, 1903.276, 51.75874, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+310, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8147.085, 1905.351, 55.85381, 2.879793, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+311, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -7984.94, 1896.23, 52.58443, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+312, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8000.49, 1898.995, 52.59884, 0.4886922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+313, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8004.658, 1917.142, 53.35815, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+314, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8016.478, 1884.141, 53.04156, 1.832596, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (Auras: 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+315, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -7998.76, 1899.241, 52.59884, 2.391101, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+316, 49773, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8121.004, 1930.836, 55.80008, 0.1059723, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+317, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -7985.2, 1909.491, 52.59883, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+318, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8026.611, 1926.533, 52.59884, 0.06981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+319, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8013.844, 1902.89, 51.48701, 0.3260266, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+320, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8048.278, 1946.269, 52.59726, 4.468043, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+321, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8021.704, 1892.913, 51.58512, 5.547575, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+322, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8146.372, 1893.354, 68.70734, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+323, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8125.257, 1904.002, 54.59565, 1.22173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+324, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8030.422, 1902.247, 53.70908, 0.1396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (Auras: 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+325, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8148.502, 1904.613, 55.85389, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+326, 49773, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8003.656, 1946.047, 53.58823, 1.612024, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+327, 51411, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8124.137, 1905.212, 54.643, 3.420845, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Neill Penny (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+328, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8030.022, 1926.415, 52.59869, 6.108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+329, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8013.823, 1899.97, 51.42781, 4.789865, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+330, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8145.814, 1909.524, 70.21295, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (Auras: 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+331, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8023.957, 1925.823, 52.58398, 5.654867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+332, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8031.262, 1914.707, 52.0965, 2.030274, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+333, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8068.075, 1912.323, 54.30494, 6.248279, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+334, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8025.198, 1926.533, 52.59884, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+335, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8125.549, 1905.481, 54.59901, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+336, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8008.026, 1867.12, 52.5988, 1.605703, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+337, 35623, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8149.647, 1890.585, 56.49559, 0.03490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+338, 48949, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -7967.24, 1906.58, 52.64168, 0.06981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+339, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -7967.21, 1899.712, 52.68159, 0.03490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+340, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8022.168, 1921.17, 63.58039, 4.590216, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+341, 48961, 648, 4737, 4768, 1, 1, 169, 0, 0, 0, -8022.168, 1921.17, 63.58039, 4.722027, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+342, 49132, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8313.889, 1673.74, 50.86127, 0.7504916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+343, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8181.893, 1656.811, 24.3811, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+344, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8176.816, 1652.417, 24.34236, 5.305801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+345, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8231.066, 1709.085, 44.6785, 3.071779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+346, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8175.238, 1651.271, 24.34236, 2.548181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+347, 49774, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8264.443, 1772.739, 39.55586, 5.818099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+348, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8240.518, 1727.363, 44.88368, 2.80998, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+349, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8352.982, 1725.293, 44.64584, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+350, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8347.639, 1725.469, 48.70489, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+351, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8341.431, 1725.484, 50.96034, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+352, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8248.087, 1714.21, 44.90006, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+353, 49774, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8320.802, 1802.219, 42.2018, 1.346194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+354, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8332.047, 1725.493, 50.8057, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+355, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8333.538, 1725.441, 50.94132, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+356, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8354.332, 1725.319, 43.62127, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
-- (@CGUID+357, 34876, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8360.79, 1631.094, 49.63328, 3.228859, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Frankie Gearslipper (Area: Bilgewater Port - Difficulty: 0) (Auras: 90318 - Do it Yourself: Cat's Mark - Frankie) (possible waypoints or random movement)
(@CGUID+358, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8336.486, 1725.422, 50.8068, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+359, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8293.732, 1672.201, 50.87298, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+360, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8289.063, 1658.401, 50.86112, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
-- (@CGUID+361, 34877, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8431.757, 1655.161, 45.87711, 5.759586, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Jack the Hammer (Area: Bilgewater Port - Difficulty: 0) (Auras: 90316 - Do it Yourself: Cat's Mark - Jack, 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+362, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8297.917, 1659.34, 50.86127, 2.234021, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+363, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8300.774, 1669.677, 50.86127, 3.054326, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+364, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8286.183, 1669.95, 50.8177, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+365, 4076, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8297.129, 1655.557, 50.85513, 1.423496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+366, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8351.721, 1725.299, 45.6042, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+367, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8299.817, 1658.701, 50.86127, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+368, 2110, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8271.673, 1657.163, 50.83456, 3.484375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+369, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8345.991, 1725.483, 49.95572, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+370, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8277.83, 1693.757, 48.54052, 4.817109, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+371, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8344.561, 1725.474, 50.91994, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+372, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8299.288, 1661.21, 50.86127, 5.393067, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+373, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8343.009, 1725.505, 50.95009, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+374, 49773, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8242.735, 1703.116, 44.81077, 3.594133, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+375, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8247.828, 1716.472, 44.90566, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+376, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8287.482, 1668.911, 50.84631, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+377, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8330.401, 1725.576, 50.79847, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+378, 49132, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8350.933, 1628.976, 49.63328, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+379, 2110, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8267.096, 1659.773, 50.49389, 0.5761559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+380, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8338.035, 1725.464, 50.8068, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+381, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8340.104, 1725.521, 50.8068, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+382, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8335.094, 1725.418, 50.8068, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+383, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8349.052, 1725.382, 47.63127, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+384, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8350.344, 1725.345, 46.65023, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+385, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8328.741, 1725.347, 50.8057, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+386, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8327.109, 1725.349, 50.8057, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+387, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8325.066, 1670.91, 50.85534, 1.169371, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+388, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8193.741, 1629.855, 28.63666, 0.839298, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+389, 35128, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8231.323, 1620.245, 34.7084, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Szabo (Area: Bilgewater Port - Difficulty: 0) (Auras: 90816 - The New You: Cat's Mark - Szabo)
(@CGUID+390, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8197.372, 1625.215, 29.13456, 1.064651, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+391, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8208.854, 1636.979, 31.70392, 2.286381, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+392, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8220.967, 1623.991, 33.54927, 3.473205, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+393, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8223.348, 1629.038, 33.79893, 5.654867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+394, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8223.042, 1616.302, 33.67985, 0.7679449, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+395, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8195.759, 1579.12, 28.82303, 0.5061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+396, 4076, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8186.919, 1614.82, 27.15918, 6.145018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Swindle Street - Difficulty: 0)
(@CGUID+397, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8178.188, 1584.432, 23.93777, 4.974188, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+398, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8235.401, 1591.837, 33.63165, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+399, 4076, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8174.503, 1617.955, 24.64402, 4.297032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Swindle Street - Difficulty: 0)
(@CGUID+400, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8194.192, 1579.911, 28.42221, 3.525565, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+401, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8176.041, 1600, 23.96091, 3.682645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+402, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8222.448, 1583.259, 33.50971, 4.389456, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+403, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8176.563, 1599.479, 23.96091, 5.358161, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+404, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8222.685, 1600.29, 33.53198, 0.06981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+405, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8173.438, 1586.979, 23.83591, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+406, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8222.997, 1581.757, 33.50971, 1.256637, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+407, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8228.646, 1604.688, 33.65698, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+408, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8230.882, 1579.7, 33.63165, 5.916666, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+409, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8194.271, 1577.083, 28.08591, 1.570796, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+410, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8177.316, 1598.26, 23.96091, 1.256637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+411, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8178.463, 1582.618, 23.93645, 1.396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+412, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8229.688, 1570.313, 33.63471, 3.560472, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+413, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8192.419, 1548.72, 30.84817, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+414, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8117.419, 1563.021, 10.37333, 3.141593, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+415, 49774, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8227.258, 1522.114, 40.10861, 0.4095283, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Swindle Street - Difficulty: 0)
(@CGUID+416, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8229.156, 1527.677, 40.27511, 1.919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+417, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8208.685, 1500.389, 40.59566, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+418, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8201.828, 1548.064, 32.39112, 4.258604, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+419, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8217.971, 1523.517, 40.47274, 3.857178, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+420, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8229.906, 1507.465, 40.67648, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+421, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8259.896, 1525.521, 42.42424, 1.570796, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+422, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8269.271, 1547.396, 41.2813, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+423, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8259.451, 1508.981, 42.54924, 4.415926, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+424, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8258.38, 1507.882, 42.54924, 3.525565, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+425, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8260.677, 1507.01, 42.54924, 0.296706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+426, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8300.085, 1548.556, 48.15693, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+427, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8260.416, 1526.563, 42.42424, 4.904375, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+428, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8302.66, 1548.542, 48.13654, 0.1047198, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+429, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8358.316, 1725.276, 40.59477, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+430, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8363.257, 1727.205, 39.95514, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+431, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8370.36, 1727.96, 39.95681, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+432, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8361.639, 1723.75, 39.94618, 3.612832, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+433, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8367.08, 1722.457, 39.98008, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+434, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8371.85, 1728.06, 39.94406, 3.106686, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+435, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8356.955, 1725.278, 41.62854, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+436, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8360.083, 1724.434, 39.94632, 3.682645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+437, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8368.69, 1728, 39.9828, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+438, 48984, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8479.052, 1802.205, 33.16816, 1.745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+439, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8355.663, 1725.278, 42.61019, 3.006149, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+440, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8365.109, 1722.556, 39.95269, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+441, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8361.56, 1726.668, 39.94616, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+442, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8365.058, 1727.748, 39.96828, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+443, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8366.795, 1727.996, 39.98146, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+444, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8363.341, 1723.12, 39.94175, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+445, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8360.099, 1726.09, 39.9463, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+446, 48984, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8485.316, 1803.047, 17.69212, 0.6806784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+447, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8398.83, 1687.762, 49.82022, 3.490659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+448, 4076, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8427.543, 1687.103, 49.65466, 4.66985, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: The Pipe - Difficulty: 0)
(@CGUID+449, 35120, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8378.46, 1728.24, 40.01683, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- FBoK Bank Teller (Area: The Pipe - Difficulty: 0)
(@CGUID+450, 35075, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8405.91, 1681.629, 49.80421, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+451, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8535.377, 1793.944, 51.60147, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0)
(@CGUID+452, 35075, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8373.3, 1728.14, 39.94388, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+453, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8537.795, 1801.788, 50.13264, 3.543018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0)
(@CGUID+454, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8525.63, 1779.931, 38.46641, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0)
(@CGUID+455, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8372.014, 1722.108, 39.94233, 3.263766, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+456, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8401.165, 1687.115, 49.80624, 0.2617994, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+457, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8521.103, 1788.215, 43.29808, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0)
(@CGUID+458, 35075, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8390.226, 1686.78, 49.73609, 4.13643, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+459, 4076, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8395.345, 1688, 49.76198, 5.492104, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: The Pipe - Difficulty: 0)
(@CGUID+460, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8368.819, 1722.406, 39.94239, 3.246312, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+461, 35120, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8378.52, 1722.11, 39.80603, 0.122173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- FBoK Bank Teller (Area: The Pipe - Difficulty: 0)
(@CGUID+462, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8373.349, 1722.102, 39.9438, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+463, 35075, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8370.536, 1722.248, 39.95739, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+464, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8511.489, 1794.556, 38.46641, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0)
(@CGUID+465, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8507.426, 1817.785, 35.1536, 3.165871, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+466, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8375.361, 1722.031, 39.94595, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+467, 35075, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8375.226, 1728.38, 39.94691, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+468, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8565.569, 1796.905, 51.32169, 3.647738, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0)
(@CGUID+469, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8541.788, 1774.174, 47.80805, 5.782778, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+470, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8538.482, 1819.568, 50.13264, 1.32645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0)
(@CGUID+471, 48984, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8605.232, 1801.365, 55.74076, 2.476528, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Troll Worker (Area: The Pipe - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+472, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8423.033, 1648.767, 45.77428, 2.70526, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+473, 2110, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8419.689, 1673.233, 49.5988, 4.711219, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+474, 35075, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8424.944, 1669.677, 49.6142, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+475, 35075, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8425.33, 1649.854, 45.52501, 5.846853, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+476, 35063, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8488.518, 1624.024, 47.32784, 5.5676, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0)
(@CGUID+477, 2110, 648, 4737, 4840, 1, 1, 169, 0, 0, 0, -8454.383, 1629.498, 44.89462, 4.993701, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+478, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8481.646, 1590.036, 45.74834, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+479, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8422.73, 1574.76, 42.57003, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+480, 2110, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8488.051, 1614.908, 47.28629, 0.05197213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+481, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8472.806, 1572.155, 47.37334, 2.600541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+482, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8440.519, 1601.509, 43.45655, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+483, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8475.241, 1573.632, 47.21465, 5.794493, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+484, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8438.43, 1623.94, 41.48393, 5.759586, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+485, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8438.858, 1560.501, 45.71069, 2.676066, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+486, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8451.575, 1589.045, 44.54092, 1.01999, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+487, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8478.125, 1581.25, 45.87334, 4.910001, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+488, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8451.879, 1548.181, 49.33716, 2.96706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+489, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8438.897, 1599.99, 43.48652, 2.199115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+490, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8453.764, 1550.08, 49.45667, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+491, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8481.895, 1597.95, 45.80682, 4.400187, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+492, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8445.776, 1568.674, 45.30158, 1.797689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+493, 2110, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8446.15, 1596.575, 43.51479, 4.209992, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+494, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8485.926, 1594.55, 45.95143, 5.480334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+495, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8462.361, 1551.135, 49.83156, 6.178465, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+496, 2110, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8397.916, 1527.604, 50.44727, 5.497475, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+497, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8423.88, 1553.025, 46.74526, 5.506386, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+498, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8421.732, 1526.372, 50.85731, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+499, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8463.021, 1545.239, 51.48539, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+500, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8438.936, 1543.278, 48.22369, 2.827433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+501, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8386.623, 1624.438, 44.02576, 2.146755, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+502, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8391.573, 1534.715, 50.48037, 2.827433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+503, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8453.587, 1535.58, 50.44369, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+504, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8420.69, 1576.01, 42.51373, 3.752458, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+505, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8419.521, 1526.135, 50.85731, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+506, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8454.13, 1547.46, 49.80627, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+507, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8414.462, 1522.336, 50.85731, 0.912069, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+508, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8388.541, 1540.625, 50.17296, 0.8003617, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+509, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8338.933, 1640.542, 50.32461, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+510, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8340.625, 1584.375, 50.48627, 2.158799, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+511, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8353.639, 1581.049, 50.37075, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+512, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8351.563, 1632.282, 49.66825, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+513, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8349.33, 1624.418, 49.63328, 2.408554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+514, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8341.146, 1536.979, 46.73015, 1.099557, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+515, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8372.143, 1634.424, 49.51611, 0.9948376, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+516, 2110, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8335.904, 1599.479, 50.23627, 6.041955, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+517, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8338.21, 1585.686, 50.53703, 3.473205, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+518, 2110, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8359.298, 1560.898, 50.35515, 4.036039, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+519, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8330.989, 1542.259, 47.0348, 5.393067, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+520, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8329.741, 1540.139, 47.0052, 2.094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+521, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8371.389, 1636.078, 49.51611, 4.24115, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+522, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8351.27, 1581.828, 50.37265, 4.13643, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+523, 2110, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8360.743, 1599.472, 48.93291, 2.597488, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+524, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8345.823, 1575.707, 50.40417, 2.75762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+525, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8361.658, 1644.174, 49.63718, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+526, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8351.806, 1579.3, 50.38209, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+527, 49773, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8327.131, 1527.13, 47.20916, 3.153311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Drudgetown - Difficulty: 0)
(@CGUID+528, 2110, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8376.464, 1678.84, 49.79062, 1.662622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+529, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8339.403, 1508.09, 46.41598, 2.809781, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+530, 35075, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8341.781, 1508.752, 46.52096, 6.265732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0)
(@CGUID+531, 4076, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8351.861, 1655.835, 49.96424, 4.623031, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+532, 35063, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8373.098, 1668.958, 49.68557, 4.361536, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+533, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8259.165, 1506.217, 42.54924, 1.780236, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+534, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8214.076, 1478.025, 40.46267, 3.543018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0)
(@CGUID+535, 35075, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8257.83, 1504.95, 42.40153, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis)
(@CGUID+536, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -7991.666, 1325, -3.534776, 6.06054, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+537, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8017.401, 1307.029, 2.542169, 0.8176255, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+538, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8014.645, 1314.72, 2.133104, 6.222578, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+539, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8015.287, 1202.236, 0.3007426, 5.022092, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+540, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8016.542, 1233.629, 1.455065, 4.714917, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+541, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8040.582, 1204.163, 3.286282, 5.550147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+542, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8042.712, 1200.698, 3.363556, 5.986479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+543, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8037.545, 1222.589, 2.582205, 2.597488, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+544, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8018.322, 1205.791, 0.7650948, 6.176519, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+545, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8027.957, 1195.796, 1.333086, 4.429259, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+546, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8013.755, 1234.883, 1.615428, 5.506074, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+547, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8014.542, 1233.634, 1.455554, 4.717156, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+548, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8055.146, 1224.929, 3.301455, 3.921161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+549, 35063, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8035.878, 1199.08, 2.491407, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+550, 35075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8052.802, 1166.549, 2.911988, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0)
(@CGUID+551, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8063.128, 1138.049, 2.459265, 3.096529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+552, 40071, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8054.438, 1161.443, 3.058544, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Julia Scrabblewrench (Area: The Slick - Difficulty: 0)
(@CGUID+553, 40075, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8051.518, 1164.312, 2.827227, 0.453417, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Avarua (Area: The Slick - Difficulty: 0)
(@CGUID+554, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8046.235, 1140.807, 1.897418, 4.89102, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+555, 40074, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8051.573, 1159.41, 2.952227, 1.481628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Atiu (Area: The Slick - Difficulty: 0)
(@CGUID+556, 40073, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8054.502, 1158.595, 3.255572, 5.896394, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Funafuti (Area: The Slick - Difficulty: 0)
(@CGUID+557, 40076, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8050.417, 1161.952, 2.952227, 3.313828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rima (Area: The Slick - Difficulty: 0)
(@CGUID+558, 40077, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8052.21, 1155.36, 3.029864, 4.665587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Mata (Area: The Slick - Difficulty: 0)
(@CGUID+559, 6827, 648, 4737, 4772, 1, 1, 169, 0, 0, 0, -8054.86, 1155.128, 3.077227, 6.094599, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+560, 48519, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8406.926, 1356.2, 104.8625, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Micro Mechachicken (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+561, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8253.692, 1460.127, 41.37889, 3.612832, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+562, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8320.174, 1492.778, 45.86167, 1.703759, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+563, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8301.618, 1497.08, 44.81042, 4.433136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+564, 37106, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8250.009, 1469.979, 42.84219, 2.478368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Coach Crosscheck (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+565, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8255.603, 1459.292, 41.50389, 0.3490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+566, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8242.771, 1440.241, 39.75389, 5.253441, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+567, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8228.665, 1462.786, 39.86687, 3.981287, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+568, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8302.382, 1494.675, 44.90021, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+569, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8275.941, 1508.087, 43.43732, 3.752458, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+570, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8277.739, 1506.879, 43.49518, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+571, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8291.666, 1505.729, 44.47882, 4.921828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+572, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8215.54, 1472.533, 39.80046, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+573, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8225.151, 1476.414, 39.80046, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+574, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8296.332, 1503.281, 45.3794, 5.951573, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+575, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8287.35, 1499.54, 45.40237, 5.201081, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+576, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8267.55, 1467.81, 44.12965, 1.48353, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+577, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8279.44, 1470.01, 43.80896, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+578, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8269.11, 1468.74, 43.713, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+579, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8278.26, 1498.89, 44.53803, 4.555309, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+580, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8285.02, 1498.79, 44.49432, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+581, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8261.66, 1466.83, 44.03222, 1.710423, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+582, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8277.35, 1497.94, 43.93104, 4.555309, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+583, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8283.854, 1465.104, 43.35681, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+584, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8276.079, 1469.513, 43.69057, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+585, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8265.677, 1469.501, 43.06087, 1.58825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+586, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8277.83, 1469.81, 43.73247, 1.466077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+587, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8285.87, 1468.57, 45.2255, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+588, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8276.7, 1467.06, 44.92647, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+589, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8260.13, 1467.99, 43.71585, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+590, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8276.96, 1468.81, 44.22559, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+591, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8286.13, 1498.65, 44.58982, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+592, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8254.39, 1469.45, 41.6481, 2.007129, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+593, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8278.56, 1467.19, 44.96773, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+594, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8285.09, 1466.74, 43.61583, 6.143559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+595, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8279.525, 1498.257, 44.09952, 5.131268, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+596, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8258.5, 1469.14, 43.19616, 1.727876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+597, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8266.21, 1467.08, 44.33913, 1.58825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+598, 48526, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8250.91, 1484.29, 41.49993, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bilgewater Buccaneer (Area: Kajaro Field - Difficulty: 0) (Auras: 90366 - Necessary Roughness: Spawned Bilgewater Buccaneer Invisibility)
(@CGUID+599, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8261.334, 1468.716, 43.40854, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+600, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8286.79, 1501.13, 46.00978, 5.166174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+601, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8264.54, 1498.16, 43.12047, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+602, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8257.614, 1498.624, 43.21495, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+603, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8259.55, 1499.01, 43.44315, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+604, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8284.1, 1500.81, 45.422, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+605, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8263.73, 1500.527, 44.32575, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+606, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8266.81, 1499.16, 43.93388, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+607, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8279.04, 1499.84, 45.09669, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+608, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8276.26, 1500.57, 45.11092, 4.590216, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+609, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8256.73, 1500.45, 43.98374, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+610, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8259.143, 1498.392, 42.99366, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+611, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8285.35, 1501.35, 45.82481, 4.729842, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+612, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8257.77, 1500.6, 44.10004, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+613, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8258.18, 1498.03, 42.79768, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+614, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8265.57, 1497.39, 42.69448, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+615, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8278.02, 1499.67, 44.95286, 4.502949, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+616, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8267.8, 1499.19, 44.03326, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: )
(@CGUID+617, 35063, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8285.02, 1498.79, 44.45593, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis)
(@CGUID+618, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8258.18, 1498.03, 42.59953, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis)
(@CGUID+619, 35063, 648, 4737, 4773, 1, 1, 169, 0, 0, 0, -8260.13, 1467.99, 43.58053, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis)
(@CGUID+620, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8272.54, 1482.99, 42.85653, 1.727876, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+621, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8276.96, 1468.81, 44.04883, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis)
(@CGUID+622, 37203, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8385.2, 1482.47, 126.7303, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fourth And Goal Target (Area: Kajaro Field - Difficulty: 0) (Auras: 70086 - Fourth and Goal: Cat's Mark Aura & Invis, 89476 - Cosmetic - Freeze at Stand 0.0 sec Anim Kit)
(@CGUID+623, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8267.55, 1467.81, 43.99583, 1.48353, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+624, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8282.955, 1459.122, 42.9212, 5.695039, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+625, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8278.361, 1480.053, 43.26739, 3.113715, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+626, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8264.435, 1460.754, 42.10692, 3.182935, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+627, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8267.801, 1483.275, 42.57978, 5.172922, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+628, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8253.492, 1479.37, 41.5231, 5.521691, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+629, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8270.155, 1491.193, 42.77408, 1.167984, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+630, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8273.959, 1496.875, 42.98283, 3.008995, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+631, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8269.72, 1462.357, 42.33536, 5.175756, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+632, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8264.854, 1484.356, 42.43861, 2.767329, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+633, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8288.262, 1489.63, 43.90341, 6.194205, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+634, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8262.638, 1493.449, 42.38613, 0.02050494, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+635, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8250.669, 1487.07, 41.60336, 5.010989, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+636, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8278.897, 1481.814, 43.26878, 4.844212, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+637, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8255.499, 1477.111, 41.69212, 4.529719, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+638, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8281.362, 1477.883, 43.38452, 3.178685, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+639, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8287.916, 1487.35, 43.82825, 6.092681, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+640, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8253.286, 1496.555, 41.79284, 2.601123, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+641, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8256.676, 1470.278, 41.6481, 1.410821, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+642, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8260.959, 1479.395, 42.12461, 2.87457, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+643, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8280.29, 1488.192, 43.35872, 6.224545, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+644, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8249.479, 1495.544, 41.6481, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+645, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8281.995, 1491.237, 43.51632, 1.205935, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+646, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8271.371, 1493.095, 42.90336, 0.5777132, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+647, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8292.2, 1512.999, 44.60382, 0.01410322, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+648, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8293.304, 1498.091, 44.42033, 4.517271, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+649, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8302.459, 1498.686, 44.89072, 0.4260244, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+650, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8293.756, 1481.705, 44.10062, 4.576598, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+651, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8292.634, 1478.349, 44.0794, 2.082308, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+652, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8291.028, 1468.307, 43.92033, 4.286482, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+653, 35063, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8294.218, 1490.143, 44.28898, 0.2710384, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis) (possible waypoints or random movement)
(@CGUID+654, 35075, 648, 4737, 4822, 1, 1, 169, 0, 0, 0, -8285.02, 1498.79, 44.45593, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis)
(@CGUID+655, 48519, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8406.926, 1356.2, 104.8625, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Micro Mechachicken (Area: KTC Headquarters - Difficulty: 0) (Auras: )
-- (@CGUID+656, 34830, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8471.495, 1217.075, 46.22297, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Defiant Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 45111 - Enrage)
(@CGUID+657, 48304, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+658, 34835, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8403.81, 1517.438, 50.81741, 1.954769, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bruno Flameretardant (Area: Drudgetown - Difficulty: 0) (Auras: 90317 - Do it Yourself: Cat's Mark - Bruno)
(@CGUID+659, 34878, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8468.401, 1566.158, 47.48344, 0.3490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sudsy Magee (Area: Drudgetown - Difficulty: 0) (Auras: 66146 - Do it Yourself: Cat's Mark - Sudsy)
(@CGUID+660, 34877, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8431.757, 1655.161, 45.87711, 5.759586, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Jack the Hammer (Area: Drudgetown - Difficulty: 0) (Auras: 90316 - Do it Yourself: Cat's Mark - Jack)
(@CGUID+661, 34876, 648, 4737, 4771, 1, 1, 169, 0, 0, 0, -8360.79, 1631.094, 49.63328, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Frankie Gearslipper (Area: Drudgetown - Difficulty: 0) (Auras: 90318 - Do it Yourself: Cat's Mark - Frankie)
(@CGUID+662, 35075, 648, 4737, 4767, 1, 1, 169, 0, 0, 0, -8267.55, 1467.81, 43.99583, 1.48353, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 90636 - Fourth and Goal: Panicked Citizen Invis)
(@CGUID+663, 48519, 648, 4737, 4765, 1, 1, 169, 0, 0, 0, -8406.926, 1356.2, 104.8625, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Micro Mechachicken (Area: KTC Headquarters - Difficulty: 0)
-- (@CGUID+664, 48343, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+665, 48341, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.0363, -0.2704, 0.2682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+666, 48343, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.2263, -0.3404, 0.2682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+667, 48342, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.0763, -0.3604, 0.06819999, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+668, 48342, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.1231, -0.3463, 0.01819998, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+669, 48342, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.0763, -0.3604, 0.06819999, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+670, 48341, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, 0.0337, -0.2804, 0.1682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+671, 48719, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8453.311, 1347.033, 102.1245, 5.085926, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+672, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8459.014, 1368.944, 101.78, 4.08407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+673, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8455.087, 1360.155, 101.8783, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+674, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8478.264, 1360.132, 101.2122, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+675, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8458.83, 1346.292, 101.78, 1.151917, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+676, 34673, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8429.521, 1311.611, 103.4305, 5.01859, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Bamm Megabomb (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+677, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8449.004, 1334.818, 102.0365, 3.700098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+678, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8472.754, 1377.009, 101.78, 4.380776, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+679, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8458.217, 1327.042, 101.78, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+680, 34872, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8402.283, 1314.986, 102.3333, 4.485496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Foreman Dampwick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+681, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8450.014, 1335.898, 102.0208, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+682, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8455.395, 1325.795, 101.78, 3.106686, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket)
(@CGUID+683, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8462.208, 1373.198, 101.78, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+684, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8451.895, 1332.773, 101.8269, 0.6806784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+685, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8473.613, 1374.936, 101.78, 1.204277, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+686, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8458.045, 1324.469, 101.78, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+687, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8456.201, 1347.521, 101.8333, 2.583087, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+688, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8459.484, 1349.177, 101.78, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+689, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8470.129, 1350.864, 100.8781, 2.012589, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+690, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8478.877, 1362.766, 102.6142, 5.078908, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+691, 34693, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8398.679, 1334.172, 102.1039, 0.08373935, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: KTC Headquarters - Difficulty: 0) (Auras: 80264 - Stealth) (possible waypoints or random movement)
(@CGUID+692, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8460.625, 1372.42, 101.78, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+693, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8465.089, 1378.741, 101.8437, 4.328416, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+694, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8452.948, 1333.819, 101.8001, 0.6806784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+695, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8460.792, 1367.3, 101.78, 0.5934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+696, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8477.576, 1344.268, 101.2835, 0.3516762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+697, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8483.389, 1379.094, 101.78, 5.951573, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+698, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8452.196, 1313.129, 102.0914, 1.291544, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks) (possible waypoints or random movement)
(@CGUID+699, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8478.188, 1352.017, 102.9674, 5.61996, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+700, 48304, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8430.86, 1302.59, 102.7883, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+701, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8450.529, 1315.144, 102.042, 3.769911, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance) (possible waypoints or random movement)
(@CGUID+702, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8460.974, 1314.608, 101.8217, 3.157347, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+703, 48304, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8432.97, 1306.71, 102.5413, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+704, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8483.252, 1350.646, 102.9673, 2.96706, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+705, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8485.021, 1363.321, 102.6141, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+706, 24110, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8482.854, 1341.462, 112.348, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Large (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+707, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8462.522, 1315.236, 101.78, 6.265732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket)
(@CGUID+708, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8482.826, 1355.566, 101.1656, 5.410521, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+709, 49773, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8437.152, 1302.359, 102.6967, 3.400562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+710, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8481.061, 1330.12, 100.8878, 5.264635, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+711, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8479.769, 1338.752, 101.0224, 2.758377, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+712, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8481.741, 1378.748, 101.7857, 2.949606, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+713, 48304, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+714, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8484.007, 1363.212, 102.6141, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+715, 48304, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8436.88, 1305.78, 102.5663, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+716, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8484.625, 1359.97, 101.249, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+717, 48304, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8436.39, 1310.16, 102.4263, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+718, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8485.005, 1350.997, 102.9674, 6.178465, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
-- (@CGUID+719, 48343, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+720, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8516.92, 1368.925, 101.78, 4.625123, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+721, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8481.639, 1307.821, 101.78, 4.049164, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres) (possible waypoints or random movement)
(@CGUID+722, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8515.308, 1380.696, 101.78, 6.178465, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+723, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8502.427, 1311.337, 101.823, 0.9773844, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+724, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8484.335, 1307.943, 101.78, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket)
(@CGUID+725, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8492.278, 1380.137, 101.78, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+726, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8493.723, 1378.502, 101.7857, 0.3141593, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+727, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8514.453, 1354.825, 101.8143, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+728, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8472.604, 1306.856, 101.8188, 2.216568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+729, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8506.654, 1342.813, 101.8303, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+730, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8509.476, 1364.359, 101.78, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+731, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8508.078, 1327.757, 101.78, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+732, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8505.136, 1377.04, 101.8095, 0.9424778, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+733, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8483.194, 1305.743, 101.78, 0.9250245, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+734, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8489.721, 1335.775, 100.8787, 1.697877, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+735, 48719, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8502.101, 1320.737, 101.8217, 4.781222, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+736, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8508.441, 1325.889, 101.78, 1.902409, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+737, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8503.373, 1379.101, 101.871, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+738, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8505.401, 1338.488, 101.78, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket)
(@CGUID+739, 35209, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8453.205, 1295.806, 102.4846, 1.396263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gobber (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+740, 35185, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8489.388, 1350.013, 100.8786, 5.076612, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+741, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8513.254, 1353.313, 101.78, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+742, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8509.264, 1368.149, 101.78, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+743, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8480.814, 1305.313, 101.78, 2.897247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket)
(@CGUID+744, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8472.319, 1308.208, 101.7833, 4.29351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+745, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8509.67, 1326.78, 101.78, 6.056293, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+746, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8517.139, 1366.8, 101.7801, 1.37881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75050 - Hors D'oeuvres)
(@CGUID+747, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8506.136, 1366.97, 101.78, 2.792527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+748, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8503.13, 1339.528, 101.78, 3.612832, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket)
-- (@CGUID+749, 48341, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.1231, -0.2463, 0.2682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+750, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8509.189, 1352.641, 101.78, 1.256637, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
-- (@CGUID+751, 48340, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.1231, -0.3163, 0.1382, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+752, 35207, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8451.596, 1297.693, 102.5288, 3.176499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ace (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+753, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8506.333, 1378.901, 101.8217, 5.602507, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+754, 35210, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8454.502, 1297.872, 102.1744, 6.161012, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Izzy (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+755, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8509.009, 1356.71, 101.78, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+756, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8495.786, 1308.122, 101.8576, 1.37881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+757, 35201, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8506.929, 1335.375, 101.8664, 0.3665192, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+758, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8491.551, 1377.58, 101.78, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+759, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8506.913, 1316.486, 101.78, 3.926991, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly) (possible waypoints or random movement)
-- (@CGUID+760, 48343, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
-- (@CGUID+761, 48340, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.1231, -0.3163, 0.1382, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+762, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8504.134, 1300.224, 102.304, 2.286381, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance) (possible waypoints or random movement)
(@CGUID+763, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8514.078, 1310.49, 101.8217, 3.831526, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+764, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8505.639, 1302.102, 102.2481, 5.340707, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+765, 49774, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8502.824, 1296.435, 102.3605, 5.658205, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
-- (@CGUID+766, 48342, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.1231, -0.3463, 0.01819998, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+767, 48719, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8515, 1304.991, 101.843, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray)
(@CGUID+768, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8522.726, 1303.392, 102.5137, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
-- (@CGUID+769, 48343, UNKNOWN, 4737, 4765, 1, 1, 379, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+770, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8450.529, 1315.144, 102.042, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+771, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8452.196, 1313.129, 102.0914, 1.291544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 46957 - Cosmetic - Stun (Permanent))
(@CGUID+772, 34865, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8544.75, 1266.25, 51.61913, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+773, 34865, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8568.19, 1273.19, 46.08613, 4.590216, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+774, 2110, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8489.366, 1211.006, 42.02657, 4.710858, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+775, 2110, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8560.794, 1279.57, 46.7538, 0.08930172, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+776, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8452.196, 1313.129, 102.0914, 1.291544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+777, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8481.639, 1307.821, 101.78, 4.049164, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+778, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8484.335, 1307.943, 101.78, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+779, 34865, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8588.94, 1262.87, 45.07813, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+780, 2110, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8588.553, 1255.166, 45.43423, 2.606577, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+781, 34865, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8601.22, 1286.03, 42.20393, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+782, 2110, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8606.47, 1299.244, 40.67929, 1.737485, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+783, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8480.814, 1305.313, 101.78, 2.897247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75048 - Fireworks)
(@CGUID+784, 34865, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8607.04, 1268.57, 42.79563, 2.268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+785, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8504.134, 1300.224, 102.304, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+786, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8515.764, 1309.214, 102.0573, 0.4537856, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+787, 35186, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8506.913, 1316.486, 101.78, 3.926991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75046 - Dance)
(@CGUID+788, 35175, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8503.13, 1339.528, 101.78, 3.612832, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 75042 - Bubbly)
(@CGUID+789, 2110, 648, 4737, 4765, 1, 1, 379, 0, 0, 0, -8439.794, 1201.647, 40.65892, 3.973919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+790, 34668, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8423.83, 1366.009, 104.8148, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sassy Hardwrench (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+791, 34874, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8419.247, 1341.823, 103, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Megs Dreadshredder (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+792, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.394, 1373.907, 102.3045, 3.202171, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+793, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0363, -0.2704, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+794, 34692, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8425.399, 1347.554, 105.1462, 5.009095, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sister Goldskimmer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+795, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8448.103, 1352.411, 102.2727, 0.7022759, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+796, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8447.89, 1356.73, 102.049, 3.299699, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+797, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2263, -0.3404, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+798, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8453.864, 1376.823, 102.2789, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+799, 34693, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8434.451, 1334.655, 102.9479, 5.462881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+800, 34696, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8399.567, 1346.457, 103.1184, 5.183628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Evol Fingers (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+801, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8455.535, 1358.778, 101.8414, 6.230825, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+802, 48342, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0763, -0.3604, 0.06819999, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+803, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.692, 1368.191, 102.1555, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+804, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8461.993, 1347.344, 101.78, 0.05235988, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+805, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8452.808, 1333.918, 101.8013, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+806, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8460.143, 1367.321, 101.78, 5.77704, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+807, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8442.851, 1321.849, 101.8217, 3.481742, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+808, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8451.42, 1333.42, 101.8526, 5.72468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+809, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8461.201, 1372.064, 101.78, 3.647738, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+810, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8470.781, 1375.696, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+811, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.454, 1389.275, 103.0647, 0.318069, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+812, 34695, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8415.52, 1321.422, 103.8445, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Maxx Avalanche (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+813, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8454.598, 1352.918, 101.8852, 2.001462, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+814, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8452.304, 1330.974, 101.8217, 3.168349, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+815, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.232, 1346.422, 101.78, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+816, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.146, 1341.925, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+817, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8466.112, 1372.15, 101.7891, 5.560458, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+818, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8452.933, 1348.173, 102.1245, 2.594842, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+819, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8462.739, 1376.267, 101.78, 3.700098, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+820, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8468.04, 1386.47, 102.291, 5.119892, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+821, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8463.708, 1370.03, 101.7891, 3.350946, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+822, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+823, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.976, 1343.174, 102.1548, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+824, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8465.433, 1378.384, 101.8154, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+825, 34689, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8394.598, 1325.667, 103.0036, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fizz Lighter (Area: KTC Headquarters - Difficulty: 0)
-- (@CGUID+826, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2263, -0.3404, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+827, 34872, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8402.283, 1314.936, 102.3337, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Foreman Dampwick (Area: KTC Headquarters - Difficulty: 0)
-- (@CGUID+828, 48342, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0763, -0.3604, 0.06819999, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+829, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8447.469, 1313.565, 102.4379, 6.264327, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
-- (@CGUID+830, 48342, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3463, 0.01819998, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+831, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.2463, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+832, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.368, 1376.179, 101.78, 4.118977, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+833, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0363, -0.2704, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+834, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8478.786, 1383.269, 101.781, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+835, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8460.416, 1331.25, 101.8217, 0.2665418, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+836, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.251, 1318.903, 101.8217, 4.507848, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+837, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8454.086, 1321.486, 101.8217, 4.626302, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+838, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.567, 1325.813, 101.78, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+839, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.201, 1329.41, 101.78, 5.846853, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+840, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8475.101, 1389.885, 102.5509, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+841, 48304, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8436.389, 1310.16, 102.4263, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+842, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8472.774, 1300.521, 102.0243, 2.423969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+843, 35211, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8451.691, 1297.719, 102.5155, 2.391101, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ace (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+844, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8476.607, 1338.365, 101.3476, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+845, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8509.146, 1369.024, 101.8217, 1.77257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+846, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8453.66, 1309.49, 102.147, 3.043496, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+847, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3163, 0.1382, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+848, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8486.085, 1385.446, 101.7784, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+849, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8506.813, 1353.766, 101.78, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+850, 48304, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+851, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.341, 1380.542, 101.78, 1.064651, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+852, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8498.954, 1313.812, 101.7743, 5.528046, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+853, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8505.175, 1336.524, 101.8217, 5.054356, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+854, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8515.701, 1373.196, 101.78, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 55664 - Cosmetic - Drunken Intoxication (Visual Only))
(@CGUID+855, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8497.248, 1313.703, 101.78, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+856, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8481.13, 1305.384, 101.78, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+857, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.007, 1357.189, 99.57272, 0.5343066, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+858, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.2463, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+859, 49774, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8435.151, 1301.872, 102.7846, 3.344696, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+860, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8486.993, 1326.14, 100.8881, 4.665827, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+861, 37762, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8381.933, 1319.307, 103.9862, 2.286381, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brett "Coins" McQuid (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+862, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8502.785, 1387.78, 102.1656, 4.531005, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+863, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8507.576, 1327.837, 101.78, 5.305801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+864, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8499.339, 1312.72, 101.78, 5.77704, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+865, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8490.61, 1313.678, 101.7743, 1.692156, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+866, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8492.982, 1377.373, 101.78, 0.7330383, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+867, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8508.254, 1369.095, 101.8217, 4.669494, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+868, 37761, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8382.889, 1318.104, 104.1712, 2.373648, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sally "Salvager" Sandscrew (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+869, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8484.401, 1355.694, 100.8728, 4.669713, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+870, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.275, 1339.857, 100.8569, 6.108505, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+871, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8508.411, 1365.432, 101.78, 4.747295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+872, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8480.904, 1300.019, 101.8148, 1.466077, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+873, 48304, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8436.88, 1305.78, 102.5663, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+874, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8489.646, 1309.681, 101.7743, 0.2682555, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+875, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8505.224, 1327.028, 101.78, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+876, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.957, 1379.302, 101.78, 5.235988, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+877, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8489.422, 1369.204, 101.7857, 0.9605916, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+878, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8517.146, 1367.632, 101.78, 6.073746, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+879, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.308, 1312.829, 101.8217, 0.2586135, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+880, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8507.407, 1368.958, 101.8681, 4.434977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+881, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8509.232, 1351.833, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+882, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8506.594, 1335.467, 101.853, 6.003932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+883, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.681, 1308.229, 101.7828, 0.6981317, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+884, 48304, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8430.861, 1302.59, 102.7883, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+885, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8507.278, 1347.182, 101.78, 5.811946, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+886, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8487.185, 1336.311, 99.66886, 3.116245, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+887, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.942, 1309.016, 101.7743, 3.31999, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+888, 35212, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8453.224, 1295.889, 102.4761, 2.059489, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gobber (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+889, 35213, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8454.489, 1297.899, 102.1731, 2.007129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Izzy (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+890, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.814, 1382.504, 101.7857, 1.177342, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+891, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0231, -0.2463, 0.1682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+892, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.946, 1328.88, 100.841, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+893, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8487.67, 1297.09, 102.028, 1.5622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+894, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8501.439, 1373.441, 101.78, 2.016842, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+895, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8478.805, 1301.36, 101.8453, 0.7169952, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+896, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.533, 1315.509, 101.8217, 3.454154, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+897, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8461.75, 1314.995, 101.78, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+898, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.677, 1354.885, 101.818, 1.308997, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+899, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8508.415, 1366.92, 101.78, 1.710423, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+900, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+901, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8506.545, 1342.802, 101.824, 0.6457718, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+902, 48304, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8432.969, 1306.71, 102.5413, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+903, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8479.685, 1332.97, 100.4745, 2.992301, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+904, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+905, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8518.37, 1356.846, 101.8217, 3.71358, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+906, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8521.868, 1369.275, 102.2188, 4.292803, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray)
(@CGUID+907, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8518.589, 1343.422, 101.8075, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+908, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.333, 1388.833, 102.5211, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+909, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0231, -0.2463, 0.1682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+910, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3163, 0.1382, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+911, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8523.277, 1366.116, 103.0198, 1.023124, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+912, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8485.168, 1293.093, 102.3605, 5.771275, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+913, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8508.484, 1315.083, 101.78, 2.932153, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+914, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8523.281, 1355.245, 102.0946, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+915, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+916, 48342, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3463, 0.01819998, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+917, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8518.092, 1323.014, 101.8217, 2.193142, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+918, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8505.33, 1297.63, 102.305, 1.435274, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+919, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8505.528, 1302.057, 102.249, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+920, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8523.939, 1332.175, 102.2734, 1.865068, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+921, 49772, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8510.987, 1292.579, 101.8547, 4.87556, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+922, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8513.389, 1309.182, 101.8003, 3.525565, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+923, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8522.84, 1332.246, 102.1607, 4.659061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+924, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8522.531, 1304.568, 102.5149, 0.5235988, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+925, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8511.641, 1298.071, 102.0225, 2.993165, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+926, 35200, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8517.91, 1318.69, 101.698, 5.734895, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+927, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+928, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8479.457, 1374.898, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+929, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8476.607, 1338.365, 101.3476, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+930, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8521.181, 1327.901, 102.2744, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+931, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8521.719, 1367.727, 101.8038, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+932, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8508.411, 1365.432, 101.78, 4.747295, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+933, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.146, 1341.925, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+934, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8470.781, 1375.696, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+935, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+936, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8486.085, 1385.446, 101.7784, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+937, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8523.281, 1355.245, 102.0946, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+938, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8517.717, 1312.554, 102.1107, 0.4014257, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
(@CGUID+939, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+940, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8479.457, 1374.898, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+941, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8509.232, 1351.833, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+942, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8470.781, 1375.696, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+943, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0763, -0.3204, 0.2182, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+944, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.146, 1341.925, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+945, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.957, 1379.302, 101.78, 5.235988, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+946, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8465.433, 1378.384, 101.8154, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+947, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8443.531, 1316.257, 102.3689, 2.844887, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+948, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8523.281, 1355.245, 102.0946, 0.06932281, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+949, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.976, 1343.174, 102.1548, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+950, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8470.781, 1375.696, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+951, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3163, 0.1382, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+952, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8518.589, 1343.422, 101.8075, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+953, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8453.864, 1376.823, 102.2789, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+954, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8521.181, 1327.901, 102.2744, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+955, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8509.232, 1351.833, 101.78, 1.946963, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+956, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8479.457, 1374.898, 101.78, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+957, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8483.061, 1310.707, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+958, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8475.101, 1389.885, 102.5509, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+959, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0231, -0.2463, 0.1682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+960, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8509.232, 1351.833, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+961, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8517.146, 1367.632, 101.78, 6.073746, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+962, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+963, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8523.281, 1355.245, 102.0946, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+964, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.333, 1388.833, 102.5211, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+965, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+966, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8517.717, 1312.554, 102.1107, 0.4014257, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+967, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8455.535, 1358.778, 101.8414, 6.230825, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+968, 48342, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3463, 0.01819998, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+969, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8470.781, 1375.696, 101.78, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+970, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8486.085, 1385.446, 101.7784, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+971, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8501.439, 1373.441, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+972, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.946, 1328.88, 100.841, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+973, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+974, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.341, 1380.542, 101.78, 1.064651, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+975, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.368, 1376.179, 101.78, 4.118977, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+976, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.677, 1354.885, 101.818, 1.308997, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+977, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.333, 1388.833, 102.5211, 1.409842, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+978, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+979, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8505.086, 1388.528, 102.3998, 2.827186, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+980, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8506.545, 1342.802, 101.824, 0.6457718, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+981, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.976, 1343.174, 102.1548, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+982, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8455.535, 1358.778, 101.8414, 6.230825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+983, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.873, 1373.689, 101.8217, 3.0403, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+984, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8452.004, 1376.189, 102.3552, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
(@CGUID+985, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8517.146, 1367.632, 101.78, 6.073746, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+986, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+987, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8478.786, 1383.269, 101.781, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
(@CGUID+988, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8465.433, 1378.384, 101.8154, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+989, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.957, 1379.302, 101.78, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+990, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8476.607, 1338.365, 101.3476, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+991, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.976, 1343.174, 102.1548, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+992, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2263, -0.3404, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+993, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8465.433, 1378.384, 101.8154, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+994, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8501.439, 1373.441, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+995, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.957, 1379.302, 101.78, 5.235988, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+996, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+997, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8492.982, 1377.373, 101.78, 0.7330383, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+998, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.368, 1376.179, 101.78, 4.118977, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+999, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8506.545, 1342.802, 101.824, 0.6457718, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1000, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.146, 1341.925, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1001, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8518.589, 1343.422, 101.8075, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1002, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8509.232, 1351.833, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1003, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8521.719, 1367.727, 101.8038, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+1004, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8508.411, 1365.432, 101.78, 4.747295, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1005, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.692, 1368.191, 102.1555, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1006, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1007, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8478.786, 1383.269, 101.781, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
-- (@CGUID+1008, 48342, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3463, 0.01819998, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1009, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.677, 1354.885, 101.818, 1.308997, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1010, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1011, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.946, 1328.88, 100.841, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1012, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8507.732, 1351.445, 101.8217, 6.029812, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1013, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8506.545, 1342.802, 101.824, 0.6457718, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1014, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1015, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8463.708, 1370.03, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+1016, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0763, -0.3204, 0.2182, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1017, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8518.589, 1343.422, 101.8075, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1018, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8479.457, 1374.898, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1019, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8486.085, 1385.446, 101.7784, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1020, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1021, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8452.004, 1376.189, 102.3552, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
(@CGUID+1022, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8476.607, 1338.365, 101.3476, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1023, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8508.415, 1366.92, 101.78, 1.710423, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+1024, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0763, -0.3204, 0.2182, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1025, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8501.439, 1373.441, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1026, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.333, 1388.833, 102.5211, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1027, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.368, 1376.179, 101.78, 4.118977, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1028, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8506.545, 1342.802, 101.824, 0.6457718, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1029, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.341, 1380.542, 101.78, 1.064651, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1030, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8521.719, 1367.727, 101.8038, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+1031, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8475.101, 1389.885, 102.5509, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+1032, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.2463, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1033, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8483.061, 1310.707, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
(@CGUID+1034, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8492.982, 1377.373, 101.78, 0.7330383, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1035, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8453.864, 1376.823, 102.2789, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1036, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1037, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8470.781, 1375.696, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1038, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8509.232, 1351.833, 101.78, 1.717548, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1039, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8523.281, 1355.245, 102.0946, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+1040, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2263, -0.3404, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1041, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8456.906, 1349.602, 101.8103, 5.358161, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1042, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8502.785, 1387.78, 102.1656, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1043, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8524.972, 1356.082, 102.1259, 2.681964, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1044, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8470.781, 1375.696, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1045, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1046, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8521.719, 1367.727, 101.8038, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+1047, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.368, 1376.179, 101.78, 4.118977, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
-- (@CGUID+1048, 48341, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.2463, 0.2682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1049, 35075, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8355.154, 1443.384, 48.52741, 0.8901179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1050, 35075, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8365.741, 1470.828, 47.47344, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1051, 35063, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8349.681, 1457.118, 47.94818, 1.32645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1052, 35063, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8357.935, 1484.123, 47.56668, 6.003932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1053, 35075, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8318.302, 1478.781, 45.63706, 1.95104, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1054, 35063, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8326.382, 1472.715, 46.33663, 0.1745329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1055, 35075, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8285.091, 1466.741, 43.61581, 6.143559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1056, 35075, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8283.976, 1466.635, 43.49206, 3.089233, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1057, 49774, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8337.756, 1454.256, 46.8819, 0.3393034, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1058, 35075, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8279.31, 1424.09, 39.62046, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1059, 35063, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8285.872, 1468.571, 45.15239, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1060, 35075, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8255.196, 1434.913, 40.42197, 1.48353, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1061, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8459.146, 1341.925, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1062, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8452.004, 1376.189, 102.3552, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
(@CGUID+1063, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8465.433, 1378.384, 101.8154, 4.18879, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1064, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.692, 1368.191, 102.1555, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1065, 48805, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8443.531, 1316.257, 102.3689, 2.844887, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 90909 - Drink Tray) (possible waypoints or random movement)
-- (@CGUID+1066, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3163, 0.1382, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1067, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8502.785, 1387.78, 102.1656, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
-- (@CGUID+1068, 48340, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.1231, -0.3163, 0.1382, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Drink Tray (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+1069, 48343, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.2731, -0.3463, 0.1682, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1070, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8473.946, 1328.88, 100.841, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1071, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8455.535, 1358.778, 101.8414, 6.230825, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1072, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1073, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8463.708, 1370.03, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1074, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8514.341, 1380.542, 101.78, 1.064651, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1075, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8517.146, 1367.632, 101.78, 6.073746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1076, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8518.589, 1343.422, 101.8075, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1077, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8476.607, 1338.365, 101.3476, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1078, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8503.505, 1378.941, 101.8702, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1079, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8450.976, 1343.174, 102.1548, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1080, 48806, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8478.786, 1383.269, 101.781, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 89842 - Drink Tray) (possible waypoints or random movement)
(@CGUID+1081, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8482.957, 1379.302, 101.78, 5.235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1082, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8475.101, 1389.885, 102.5509, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1083, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8502.785, 1387.78, 102.1656, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1084, 35202, 648, 4737, 4765, 1, 1, 380, 0, 0, 0, -8501.439, 1373.441, 101.78, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
-- (@CGUID+1085, 48342, UNKNOWN, 4737, 4765, 1, 1, 380, 0, 0, 0, -0.0763, -0.3604, 0.06819999, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Cocktail (Area: KTC Headquarters - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+1086, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8453.545, 1357.776, 101.9492, 3.944444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1087, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8450.792, 1338.88, 102.0025, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1088, 49339, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8461.346, 1355.283, 101.78, 0.03490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1089, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8461.979, 1371.354, 101.7891, 1.564381, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1090, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8481.255, 1355.849, 100.573, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1091, 34668, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8423.83, 1366.009, 104.8148, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sassy Hardwrench (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1092, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8479.056, 1377, 101.78, 5.323254, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1093, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8459.772, 1363.795, 101.78, 5.323254, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1094, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8457.348, 1351.642, 101.78, 2.687807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1095, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8456.658, 1359.545, 101.7921, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1096, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8457.639, 1347.708, 101.78, 0.418879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1097, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8461.781, 1371.641, 101.78, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1098, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8456.279, 1349.17, 101.816, 4.014257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1099, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8449.384, 1334.755, 102.0055, 5.5676, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1100, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8455.114, 1328.422, 101.78, 1.867502, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1101, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8473.238, 1376.37, 101.78, 4.433136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1102, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8445.226, 1320.342, 101.8759, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1103, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8452.701, 1333.911, 101.8044, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1104, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8465.745, 1378.649, 101.8315, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1105, 37709, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8420.422, 1318.998, 102.5643, 1.867502, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ace (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1106, 37708, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8423.946, 1319.012, 102.5287, 1.53589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Izzy (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1107, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8464.872, 1374.95, 101.78, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1108, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8451.066, 1332.174, 101.8331, 0.8377581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1109, 34693, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8398.679, 1334.172, 102.1039, 3.736393, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: KTC Headquarters - Difficulty: 0) (Auras: 80264 - Stealth) (possible waypoints or random movement)
(@CGUID+1110, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8449.922, 1325.387, 101.78, 0.05235988, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1111, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8482.271, 1336.392, 100.4898, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1112, 37710, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8422.018, 1317.403, 102.7292, 1.658063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gobber (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1113, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8444.589, 1322.799, 101.78, 0.08726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1114, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8458.272, 1329.252, 101.78, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1115, 49338, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8465.073, 1373.299, 101.78, 3.996804, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1116, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8458.424, 1326.918, 101.78, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1117, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8445.768, 1328.413, 101.78, 6.178465, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1118, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8471.917, 1351.004, 100.4931, 4.729842, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1119, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8460.465, 1348.507, 101.7495, 3.983749, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1120, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8458.08, 1324.363, 101.78, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1121, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8464.061, 1309.845, 101.78, 0.6283185, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1122, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8476.953, 1330.424, 100.4574, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1123, 48304, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8436.389, 1310.16, 102.4263, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1124, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8506.063, 1375.55, 101.78, 5.078908, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1125, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8492.232, 1377.083, 101.78, 3.926991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1126, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8477.346, 1344.809, 100.6108, 5.218534, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1127, 48304, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8432.969, 1306.71, 102.5413, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1128, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8506.643, 1339.212, 101.78, 6.056293, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1129, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8458.591, 1309.411, 101.8117, 2.426008, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1130, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8483.545, 1363.443, 102.6141, 3.211406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1131, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8478.154, 1381.2, 101.78, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1132, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8485.264, 1363.5, 102.6141, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1133, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8473.349, 1307.665, 101.7976, 0.9599311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1134, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8484.261, 1350.774, 102.9673, 6.143559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1135, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8481.261, 1308.415, 101.78, 4.153883, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1136, 34673, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8429.522, 1311.616, 103.4402, 3.812207, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Bamm Megabomb (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1137, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8489.984, 1331.946, 100.7126, 0.3490658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1138, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8486.212, 1337.851, 100.4427, 3.420845, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1139, 49338, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8446.566, 1316.252, 102.3158, 2.460914, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1140, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8490.181, 1344.115, 100.5747, 4.049164, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1141, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8453.792, 1313.337, 102.0051, 2.059489, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1142, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8455.011, 1317.104, 101.8532, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1143, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8479.924, 1358.5, 100.3688, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1144, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8450.609, 1315.214, 102.0347, 2.530727, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1145, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8484.811, 1360.05, 100.3525, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1146, 48304, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8436.88, 1305.78, 102.5663, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1147, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8484.25, 1308.172, 101.78, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1148, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8503.514, 1378.887, 101.8689, 5.550147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1149, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8477.306, 1339.094, 100.4758, 5.061455, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1150, 48304, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1151, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8492.982, 1379.453, 101.78, 4.904375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1152, 48304, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8430.861, 1302.59, 102.7883, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1153, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8485.478, 1326.884, 100.7146, 6.126106, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 87259 - Permanent Feign Death (Drowned Anim Kit))
(@CGUID+1154, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8481.524, 1305.604, 101.78, 2.356194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1155, 49774, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8432.081, 1306.758, 102.5371, 0.9497334, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1156, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8476.552, 1312.278, 101.78, 5.8294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1157, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8463.643, 1303.97, 101.9069, 2.111848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1158, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8483.067, 1378.993, 101.78, 1.762783, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1159, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8515.614, 1373.222, 101.78, 5.846853, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1160, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8461.337, 1314.799, 101.78, 5.009095, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1161, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8475.114, 1310.304, 101.78, 6.126106, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1162, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8518.583, 1343.785, 101.7879, 5.637414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1163, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8501.041, 1309.375, 101.8217, 3.266113, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1164, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8507.645, 1349.216, 101.8217, 5.323025, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1165, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8510.229, 1366.491, 101.78, 0.9773844, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1166, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8507.583, 1315.542, 101.78, 1.029744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1167, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8506.529, 1342.957, 101.828, 5.550147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1168, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8516.038, 1368.014, 101.78, 5.166174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1169, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8485.604, 1302.908, 101.78, 1.117011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1170, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8512.67, 1380.613, 101.8126, 5.445427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1171, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8506.366, 1335.406, 101.8383, 3.508112, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1172, 49339, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8516.021, 1371.436, 101.78, 5.707227, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1173, 49339, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8490.826, 1312.394, 101.78, 4.328416, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1174, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8509.587, 1369.097, 101.78, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1175, 49338, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8510.658, 1345.594, 101.78, 3.909538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waitress (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1176, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8506.035, 1325.743, 101.78, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1177, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8480.516, 1299.573, 101.8611, 1.762783, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1178, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8508.335, 1371.46, 101.78, 4.328416, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1179, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8497.505, 1313.913, 101.78, 2.373648, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1180, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8503.705, 1339.609, 101.78, 3.490659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1181, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8506.882, 1355.764, 101.78, 5.969026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1182, 35237, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8506.573, 1312.3, 101.78, 1.919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pirate Party Crasher (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1183, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8513.689, 1354.785, 101.78, 0.1919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1184, 37490, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8322.196, 1466.432, 153.2475, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1185, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8505.389, 1301.809, 102.2567, 0.4363323, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1186, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8513.698, 1309.316, 101.8218, 0.9250245, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1187, 35238, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8512.973, 1313.108, 101.7825, 0.4886922, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: )
(@CGUID+1188, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8521.451, 1328.625, 102.2446, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1189, 49773, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8505.209, 1290.625, 102.548, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1190, 49339, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8516.179, 1311.595, 102.0586, 0.8552113, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- KTC Waiter (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1191, 35235, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8522.563, 1304.375, 102.5146, 2.338741, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1192, 35063, 648, 4737, 4765, 1, 1, 381, 0, 0, 0, -8355.154, 1443.384, 48.52741, 0.8901179, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1193, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8377.486, 1347.776, 102.0865, 3.671292, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1194, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8435.157, 1323.358, 101.8217, 6.253329, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1195, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8453.801, 1360.556, 101.9809, 1.248091, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1196, 34668, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8424.748, 1322.33, 102.9292, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sassy Hardwrench (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1197, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8395.075, 1336.325, 102.1039, 4.521272, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1198, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8453.68, 1362.412, 102.1723, 0.2879919, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1199, 34673, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8429.521, 1311.62, 103.4365, 5.0182, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Bamm Megabomb (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1200, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8448.343, 1321.763, 101.8217, 3.985041, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1201, 34874, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8435.328, 1316.877, 102.6322, 0.9599311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Megs Dreadshredder (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1202, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8448.032, 1338.827, 102.1245, 0.3317491, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1203, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8419.16, 1341.484, 102.5234, 0.6463443, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1204, 34692, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8414.114, 1329.385, 102.6462, 2.129302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sister Goldskimmer (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1205, 34693, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8398.679, 1334.172, 102.1039, 3.736393, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: KTC Headquarters - Difficulty: 0) (Auras: 80264 - Stealth) (possible waypoints or random movement)
(@CGUID+1206, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8471.56, 1382.628, 101.7857, 1.839271, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1207, 35053, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8377.747, 1333.648, 102.5298, 1.343904, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Candy Cane (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1208, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8542.863, 1538.403, 307.0921, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1209, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8552.938, 1322.004, 363.8578, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1210, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8539.879, 1500.194, 310.2728, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1211, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8506.049, 1319.295, 101.8217, 2.225603, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1212, 48304, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8436.389, 1310.16, 102.4263, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1213, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8590.689, 1226.58, 304.8886, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1214, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8404.044, 1312.26, 100.4283, 5.069427, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1215, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8560.712, 1412.368, 316.2466, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1216, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8508.967, 1341.256, 101.8217, 2.581415, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1217, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8510.109, 1389.889, 102.6709, 0.0253786, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1218, 48304, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8432.969, 1306.71, 102.5413, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1219, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8506.274, 1377.352, 102.033, 0.8400227, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1220, 37490, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8322.243, 1466.443, 153.2475, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1221, 49772, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8429.652, 1302.689, 102.7399, 4.77121, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1222, 35054, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8377.304, 1335.127, 102.3967, 4.415683, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Chip Endale (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1223, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8476.584, 1305.75, 101.7743, 1.063744, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1224, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8464.447, 1293.771, 102.168, 6.039911, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1225, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8590.938, 1255.109, 271.2761, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1226, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8512.736, 1362.146, 101.8217, 0.7742996, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1227, 48304, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8436.88, 1305.78, 102.5663, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1228, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8487.52, 1387.897, 101.7857, 1.908706, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1229, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8423.325, 1298.424, 103.0768, 0.3915693, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1230, 48304, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1231, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8460.169, 1309.994, 101.8217, 4.716386, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1232, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8552.268, 1361.21, 304.1276, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1233, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8545.906, 1464.111, 272.6907, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1234, 48304, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8430.861, 1302.59, 102.7883, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1235, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8592.328, 1246.359, 324.6682, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1236, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8555.018, 1583.484, 270.1007, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1237, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8570.441, 1293.002, 356.7974, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1238, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8636.703, 1349.189, 367.2697, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1239, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8604.377, 1438.92, 348.8145, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1240, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8649.674, 1373.155, 329.037, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1241, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8613.292, 1549.122, 311.9237, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1242, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8627.372, 1525.681, 372.4441, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1243, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8634.647, 1492.347, 327.5305, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1244, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8600.366, 1595.582, 340.6983, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1245, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8637.863, 1307.517, 365.6885, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1246, 43359, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8662.484, 1626.635, 365.3527, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Infinite Hide Body (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1247, 49773, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8509.029, 1290.394, 102.2145, 3.847259, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1248, 35236, 648, 4737, 4765, 1, 1, 382, 0, 0, 0, -8507.291, 1290.625, 102.548, 3.574775, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Partygoer (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1249, 49772, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8437.072, 1302.632, 102.6967, 3.273636, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1250, 34872, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8431.545, 1276.95, 103.5937, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Foreman Dampwick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1251, 34693, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8424.881, 1329.173, 102.0833, 3.781168, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: KTC Headquarters - Difficulty: 0) (Auras: 80264 - Stealth) (possible waypoints or random movement)
(@CGUID+1252, 23837, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8431.844, 1278.694, 102.6772, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1253, 48304, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8436.88, 1305.78, 102.5663, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1254, 48304, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8430.861, 1302.59, 102.7883, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1255, 48304, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1256, 49773, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8507.901, 1296.241, 102.1233, 6.21628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1257, 48304, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8432.969, 1306.71, 102.5413, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1258, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8447.252, 1246.847, 57.86066, 0.6457718, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1259, 48304, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8436.389, 1310.16, 102.4263, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1260, 34668, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8424.748, 1322.33, 102.9292, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sassy Hardwrench (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1261, 34673, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8429.518, 1311.618, 103.4296, 5.017861, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Bamm Megabomb (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1262, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8472.611, 1237.101, 52.66944, 0.8203048, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1263, 35304, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8455.424, 1236.934, 51.56467, 4.555309, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brute Enforcer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1264, 35304, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8452.12, 1248.4, 56.95643, 6.213372, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Brute Enforcer (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1265, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8511.361, 1241.063, 54.91471, 5.77704, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1266, 4076, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8439.868, 1197.892, 40.61861, 4.326378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1267, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8484.254, 1198.823, 41.97269, 0.8726646, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1268, 2110, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8489.667, 1214.591, 41.92929, 0.6303928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1269, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8433.984, 1215.997, 45.3097, 3.228859, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1270, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8448.951, 1193.96, 40.99962, 2.164208, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1271, 4076, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8424.061, 1186.587, 40.80664, 0.5181354, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1272, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8469.007, 1159.337, 40.71927, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1273, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8490.114, 1170.33, 42.01693, 0.7330383, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1274, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8423.176, 1174.887, 41.07613, 2.460914, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1275, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8433.451, 1149.618, 44.05191, 2.251475, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1276, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8406.976, 1156.738, 39.15038, 2.129302, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1277, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8516.52, 1199.943, 50.89582, 0.2268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1278, 34865, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8384.58, 1150.02, 36.39843, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1279, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8506.172, 1151.068, 54.30568, 0.6108652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1280, 34865, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8366.11, 1149.97, 33.58693, 3.665191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1281, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8456.326, 1137.726, 39.8261, 2.042035, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1282, 4076, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8456.024, 1130.775, 39.81519, 0.6980885, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1283, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8361.786, 1151.373, 34.81727, 3.036873, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1284, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8382.406, 1151.236, 36.4759, 3.193953, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1285, 2110, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8484.695, 1136.564, 41.16633, 3.861933, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1286, 2110, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8385.79, 1148.151, 36.3544, 4.431467, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1287, 34865, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8400.08, 1153.27, 37.01333, 3.822271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1288, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8481.976, 1122.767, 42.70755, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1289, 34865, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8492.97, 1108.77, 42.84613, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1290, 34865, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8360.6, 1136.02, 34.25563, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1291, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8358.877, 1131.125, 33.79317, 1.727876, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1292, 34865, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8368.5, 1116.25, 33.19993, 1.937315, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1293, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8368.33, 1114.977, 33.0887, 1.186824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1294, 34865, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8352.719, 1118.181, 32.04005, 3.665191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1295, 4076, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8362.195, 1117.685, 32.33672, 3.457835, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1296, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8346.424, 1111.943, 29.96926, 2.094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1297, 39660, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8394.489, 1291.908, 93.23702, 5.88176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Spirit Healer (Area: Kaja'mine - Difficulty: 0) (Auras: 10848 - Shroud of Death)
(@CGUID+1298, 35294, 648, 4737, 4766, 1, 1, 383, 0, 0, 0, -8537.982, 1260.816, 53.39698, 5.550147, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1299, 35075, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8272.319, 1421.402, 39.98496, 4.144852, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1300, 35075, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8292.596, 1434.624, 40.24829, 4.935783, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1301, 49774, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8236.585, 1252.9, 26.38866, 5.01264, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1302, 49774, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8204.389, 1361.881, 33.68127, 5.255731, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1303, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8247.801, 1431.477, 39.73723, 2.357447, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1304, 35075, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8256.425, 1413.972, 40.02874, 5.186715, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1305, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8191.178, 1307.8, 27.61328, 2.410257, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1306, 35234, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8273.446, 1438.337, 39.65483, 4.29351, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1307, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8163.338, 1313.074, 26.81088, 1.746189, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1308, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8161.977, 1262.796, 24.37742, 3.957381, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1309, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8128.692, 1329.949, 17.85976, 4.989867, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1310, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8154.637, 1344.942, 23.31608, 3.262069, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1311, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8139.034, 1327.062, 19.73386, 5.300962, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1312, 49774, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8158.783, 1334.921, 25.54927, 4.77298, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1313, 49773, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8157.473, 1241.171, 21.8397, 5.994288, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1314, 35075, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8169.079, 1276.365, 25.22778, 4.501584, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1315, 35063, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8140.005, 1271.026, 20.79645, 5.081367, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1316, 35234, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8170.936, 1317.656, 27.61307, 2.513274, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1317, 35075, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8171.778, 1314.034, 27.60278, 2.957702, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1318, 35075, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8128.142, 1307.946, 19.26233, 0.4469866, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1319, 35075, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8140.244, 1299.572, 20.76056, 1.423265, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1320, 35234, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8166.521, 1267.405, 24.87732, 3.525565, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1321, 35063, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8152.931, 1396.412, 16.59634, 2.545947, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1322, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8114.063, 1323.994, 17.78624, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1323, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8116.146, 1375.521, 12.00206, 5.961341, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1324, 35063, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8139.169, 1234.042, 18.86801, 4.690318, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1325, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8109.684, 1266.274, 20.94285, 4.615887, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1326, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8114.979, 1308.745, 18.56444, 1.225618, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1327, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8134.673, 1377.167, 13.42775, 5.428646, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1328, 49773, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8108.063, 1264.928, 20.97593, 3.083927, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: 0 - Difficulty: 0)
(@CGUID+1329, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8098.743, 1397.166, 11.73276, 1.848909, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1330, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8102.225, 1427.405, 9.647739, 3.405938, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1331, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8138.021, 1447.396, 11.42797, 2.159376, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1332, 35063, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8188.487, 1416.134, 24.72188, 3.153996, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1333, 49774, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8125.974, 1421.446, 10.24182, 4.421213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: 0 - Difficulty: 0)
(@CGUID+1334, 49772, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8111.771, 1405.056, 10.10233, 4.891082, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: 0 - Difficulty: 0)
(@CGUID+1335, 35063, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8080.069, 1414.408, 10.89299, 2.538063, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1336, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8216.087, 1435.969, 35.95596, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1337, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8269.095, 1457.814, 41.7323, 3.785169, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1338, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8260.976, 1467.686, 43.64375, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1339, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8244.676, 1470.876, 41.07169, 6.106477, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1340, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8243.247, 1438.926, 39.75389, 4.324169, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1341, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8249.434, 1474.532, 41.51773, 5.892176, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1342, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8252.518, 1441.865, 39.95237, 5.253441, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1343, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8234.375, 1457.292, 40.25389, 1.248671, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1344, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8215.731, 1480.382, 39.80046, 0.9064686, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1345, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8223.68, 1481.375, 39.80046, 4.504522, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1346, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8259.889, 1468.826, 43.10676, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1347, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8226.165, 1472.385, 39.7753, 0.3839724, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1348, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8244.285, 1463.733, 40.91832, 4.299512, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1349, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8228.485, 1494.122, 40.38847, 4.54823, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1350, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8270.347, 1439.262, 39.86072, 0.3543046, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1351, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8235.271, 1449.233, 40.40086, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1352, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8252.084, 1460.417, 41.25389, 1.325983, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1353, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8266.701, 1468.986, 43.49382, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1354, 49774, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8177.4, 1490.094, 42.41028, 4.038362, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1355, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8269.363, 1479.463, 42.68156, 1.570796, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1356, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8287.176, 1469.646, 44.89082, 2.954353, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1357, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8259.556, 1498.962, 43.2802, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1358, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8265.207, 1505.872, 42.86801, 3.169906, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1359, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8251.49, 1493.104, 41.63956, 1.047149, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1360, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8287.831, 1478.069, 43.77238, 1.250598, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1361, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8257.859, 1499.641, 43.63325, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1362, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8273.959, 1498.958, 43.17033, 4.541627, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1363, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8109.866, 1455.145, 9.92585, 0.9333189, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1364, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8281.813, 1459.949, 42.98181, 3.129874, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1365, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8119.089, 1473.568, 10.28987, 1.016564, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1366, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8268.612, 1493.71, 42.84122, 2.414184, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1367, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8279.277, 1480.313, 43.24625, 2.23528, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1368, 49774, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8228.367, 1524.053, 40.31564, 2.303714, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1369, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8236.974, 1515.354, 40.97399, 6.161012, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1370, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8265.342, 1499.111, 43.59169, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1371, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8277.67, 1497.08, 43.27457, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1372, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8284.359, 1469.01, 44.55949, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1373, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8327.244, 1477.751, 46.08506, 0.1069858, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1374, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8265.779, 1538.569, 41.04611, 1.27409, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1375, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8303.125, 1491.057, 44.80503, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1376, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8280.173, 1530.234, 44.73224, 3.188225, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1377, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8299.026, 1537.533, 47.1394, 1.605703, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1378, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8295.23, 1526.484, 44.82477, 6.165012, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1379, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8315.104, 1511.979, 45.9594, 4.092431, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1380, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8321.16, 1479.77, 45.87827, 6.020992, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1381, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8310.82, 1459.585, 44.15078, 1.666277, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1382, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8288.768, 1506.881, 44.22882, 3.089438, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1383, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8324.52, 1503.404, 46.33928, 0.8298241, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1384, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8293.896, 1485.289, 44.1254, 2.89834, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1385, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8273.438, 1513.021, 43.22882, 1.459405, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1386, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8245.374, 1527.342, 41.54924, 1.135113, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1387, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8288.521, 1493.809, 44.21394, 1.989675, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1388, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8284.904, 1501.424, 45.96696, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1389, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8291.237, 1505.858, 44.35382, 1.250703, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1390, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8234.512, 1525.286, 40.65641, 0.1976841, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1391, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8268.656, 1534.094, 41.71125, 1.447927, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1392, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8286.286, 1498.863, 44.58114, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1393, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8329.062, 1459.455, 46.46706, 0.5388598, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1394, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8279.451, 1499.814, 45.0539, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1395, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8304.528, 1493.184, 44.99834, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1396, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8269.271, 1549.479, 41.1563, 2.198787, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1397, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8298.977, 1532.836, 46.22882, 1.735624, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1398, 49774, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8339.53, 1453.027, 46.93451, 4.093366, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1399, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8229.285, 1553.495, 37.36817, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1400, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8361.807, 1506.085, 46.332, 2.965023, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1401, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8318.877, 1549.295, 47.53657, 1.083827, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1402, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8299.934, 1543.838, 47.92461, 6.027683, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1403, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8356.746, 1572.49, 50.36127, 4.208511, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1404, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8348.4, 1446.981, 47.75544, 5.233716, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1405, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8319.464, 1525.123, 47.35044, 2.199115, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1406, 49773, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8323.885, 1526.483, 47.32476, 6.211034, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1407, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8349.014, 1467.641, 47.86145, 5.013561, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1408, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8324.612, 1518.125, 46.7094, 4.47366, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1409, 4076, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8338.434, 1580.525, 50.43671, 2.410427, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1410, 2110, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8356.017, 1564.759, 50.35515, 4.770808, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1411, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8350.627, 1504.122, 46.34292, 2.460914, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1412, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8343.526, 1476.484, 47.40012, 2.96706, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1413, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8344.326, 1503.922, 46.332, 2.578062, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1414, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8339.435, 1589.377, 50.46313, 0.483405, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1415, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8412.245, 1531.55, 50.64792, 4.572762, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1416, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8356.018, 1584.495, 50.31331, 5.8294, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1417, 4076, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8403.22, 1524.023, 50.60731, 4.168407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1418, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8400, 1529.688, 50.48231, 1.35226, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1419, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8358.107, 1596.483, 49.87202, 0.4014257, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1420, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8397.997, 1521.435, 50.81262, 5.497787, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1421, 4076, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8355.729, 1602.604, 50.13836, 0.7714543, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1422, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8404.17, 1538.193, 50.3163, 2.538702, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1423, 4076, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8335.904, 1599.479, 50.23627, 6.041955, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1424, 2110, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8415.251, 1523.019, 50.85731, 1.541016, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1425, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8396.354, 1560.417, 45.92296, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1426, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8411.18, 1572.02, 42.07473, 3.054326, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1427, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8418.812, 1547.293, 47.0851, 0.6564963, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1428, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8418.38, 1528.377, 50.85731, 5.723232, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1429, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8185.159, 1552.851, 30.40284, 2.593136, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1430, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8190.655, 1556.304, 28.82138, 4.45059, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1431, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8186.675, 1556.977, 28.05127, 1.117638, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1432, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8201.455, 1553.318, 30.91108, 1.076533, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1433, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8222.558, 1580.441, 33.38862, 1.496067, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1434, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8175.591, 1583.148, 23.83591, 0.9746556, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1435, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8178.125, 1586.458, 24.08591, 5.394696, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1436, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8220.778, 1620.186, 33.37411, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1437, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8190.463, 1580.351, 27.17185, 5.414985, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1438, 35075, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8223.707, 1597.051, 33.50971, 0.4944986, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1439, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8220.885, 1587.413, 33.50971, 4.840789, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1440, 35234, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8225.06, 1588.224, 33.63165, 3.508112, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Kajaro Field - Difficulty: 0)
(@CGUID+1441, 35063, 648, 4737, 4822, 1, 1, 383, 0, 0, 0, -8226.063, 1619.563, 33.75668, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1442, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8161.378, 1593.519, 19.43488, 3.90771, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1443, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8170.91, 1592.691, 23.90358, 1.727876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1444, 2110, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8190.1, 1615.335, 28.01297, 1.953303, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1445, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8193.153, 1632.33, 28.61611, 4.206244, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1446, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8155.884, 1578.457, 18.95589, 0.810702, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1447, 4076, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8173.298, 1614.283, 24.42145, 4.460765, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1448, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8142.709, 1580.208, 16.04477, 3.464524, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1449, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8172.35, 1597.886, 23.83591, 2.553446, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1450, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8208.112, 1634.294, 31.73981, 2.423182, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1451, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8143.25, 1575.807, 15.94239, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1452, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8148.996, 1586.521, 17.55404, 4.897253, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1453, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8184.847, 1629.428, 25.84549, 1.031047, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1454, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8124.374, 1576.026, 12.26384, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1455, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8111.459, 1559.375, 9.130251, 5.03339, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1456, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8119.499, 1529.999, 10.51762, 0.7885056, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1457, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8088.518, 1544.762, 8.725637, 2.929154, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1458, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8111.918, 1580.557, 9.423011, 0.05181269, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1459, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8119.155, 1564.264, 10.57602, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1460, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8175.632, 1649.743, 24.34534, 1.64061, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1461, 2110, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8134.411, 1605.935, 14.78384, 3.988622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Swindle Street - Difficulty: 0)
(@CGUID+1462, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8139.983, 1649.014, 15.73413, 1.815142, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1463, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8100.84, 1542.493, 9.205022, 4.051878, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1464, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8144.791, 1655.208, 16.01996, 3.013595, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1465, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8120.094, 1637.786, 12.57421, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1466, 2110, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8134.664, 1602.409, 14.89491, 2.611551, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Swindle Street - Difficulty: 0)
(@CGUID+1467, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8172.387, 1649.47, 24.08943, 5.497601, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1468, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8173.384, 1648.958, 23.90522, 6.282883, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1469, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8118.993, 1506.192, 10.34132, 6.232349, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1470, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8128.125, 1635.938, 14.06539, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1471, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8181.453, 1646.807, 25.09186, 1.441003, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1472, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8117.781, 1647.861, 11.8488, 1.623156, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1473, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8143.316, 1627.273, 15.33949, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1474, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8139.323, 1633.707, 15.10637, 4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1475, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8139.182, 1581.814, 15.16977, 0.2695891, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1476, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8156.383, 1634.933, 19.04914, 3.945841, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1477, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8097.183, 1604.216, 8.715613, 5.058945, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1478, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8074.743, 1592.153, 8.533772, 0.5271487, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1479, 49772, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8074.337, 1544.816, 7.643363, 5.896191, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Swindle Street - Difficulty: 0)
(@CGUID+1480, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8103.39, 1493.954, 10.00006, 6.278074, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1481, 49772, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8076.581, 1563.885, 8.08367, 0.4123841, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Swindle Street - Difficulty: 0)
(@CGUID+1482, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8055.587, 1506.203, 9.517092, 5.899213, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1483, 37054, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8071.958, 1503.802, 8.914551, 4.694936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Swindle Street - Difficulty: 0) (Auras: 70112 - Permanent Feign Death (On Fire))
(@CGUID+1484, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8106.25, 1652.604, 10.56539, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1485, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8046.792, 1502.658, 10.03489, 2.177344, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1486, 6827, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8031.468, 1598.406, 2.152455, 0.4287821, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Swindle Street - Difficulty: 0)
(@CGUID+1487, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8073.732, 1506.463, 8.868902, 5.19623, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1488, 37055, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8076.479, 1491.387, 8.914551, 5.288348, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Swindle Street - Difficulty: 0) (Auras: 70112 - Permanent Feign Death (On Fire))
(@CGUID+1489, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8095.825, 1649.523, 10.01218, 0.8371839, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1490, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8045.537, 1590.615, 2.532824, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1491, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8040.415, 1589.084, 2.303409, 2.338456, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1492, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8095.354, 1639.521, 9.348015, 3.657992, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1493, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8022.639, 1545.412, 2.086058, 4.389435, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1494, 6827, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8003.271, 1580.288, 2.275547, 2.352744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Swindle Street - Difficulty: 0)
(@CGUID+1495, 4076, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8052.043, 1510.466, 9.606426, 3.890435, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Swindle Street - Difficulty: 0)
(@CGUID+1496, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8100.135, 1493.494, 9.999575, 4.325397, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1497, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -7998.007, 1581.157, 1.875609, 1.225344, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1498, 37057, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8072.143, 1494.74, 8.917638, 1.658063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Swindle Street - Difficulty: 0) (Auras: 70112 - Permanent Feign Death (On Fire))
(@CGUID+1499, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -7969.136, 1644.084, -1.915726, 0.1941173, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1500, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -7987.295, 1569.095, -0.2115488, 1.205908, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1501, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8001.303, 1685.721, 3.194439, 2.300198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1502, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -7998.267, 1555.63, 0.5220709, 5.623682, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1503, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -7995.737, 1544.125, 0.7382871, 0.1301654, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1504, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8019.584, 1662.863, 2.95623, 0.1677165, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1505, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8068.118, 1695.36, 14.88923, 2.112298, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1506, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8003.865, 1653.978, 3.705497, 1.978509, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1507, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8009.35, 1632.153, 2.377736, 4.998527, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1508, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -7996.353, 1676.958, 2.960156, 4.363531, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1509, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -7992.587, 1535.849, 1.09043, 6.103055, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1510, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -7982.282, 1721.182, -2.332867, 2.556297, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1511, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -7990.305, 1709.18, 1.724713, 3.391001, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1512, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -7996.776, 1719.854, 1.851911, 3.266917, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1513, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8012.18, 1746.597, 1.455534, 5.906221, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1514, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -7985.993, 1721.426, -0.9537535, 4.661602, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1515, 35075, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -7991.055, 1714.06, 1.540631, 0.7761644, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1516, 35075, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8028.999, 1745.577, 1.210539, 2.964037, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1517, 49774, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8115.472, 1728.702, 18.38653, 1.382209, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: The Slick - Difficulty: 0)
(@CGUID+1518, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8123.383, 1712.849, 16.31496, 3.607206, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1519, 35075, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8105.872, 1687.531, 14.83163, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1520, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8016.061, 1779.896, -1.243184, 0.621223, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1521, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8064.401, 1781.946, 4.455431, 0.3114244, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1522, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8103.021, 1706.361, 17.43264, 2.579274, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1523, 35075, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8115.235, 1735.193, 19.20891, 5.835288, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1524, 35234, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8118.922, 1738.684, 19.72861, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: The Slick - Difficulty: 0)
(@CGUID+1525, 4076, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8135.317, 1748.096, 22.02901, 4.958762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1526, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8237.918, 1719.686, 44.81077, 4.483714, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1527, 49772, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8202.668, 1750.984, 43.00098, 4.867292, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Swindle Street - Difficulty: 0)
(@CGUID+1528, 35609, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8098.309, 1809.821, 33.51874, 4.206244, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Swindle Street - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1529, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8186.749, 1796.445, 28.98811, 6.091473, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1530, 49773, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8140.915, 1795.402, 23.29958, 4.359447, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Swindle Street - Difficulty: 0)
(@CGUID+1531, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8231.647, 1734.784, 44.80379, 4.20137, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1532, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8236.332, 1747.562, 45.94228, 3.90424, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1533, 35609, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8086.981, 1806.406, 34.82932, 4.153883, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Swindle Street - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1534, 35063, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8180.23, 1787.307, 30.21052, 4.682052, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1535, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8179.627, 1792.889, 30.06972, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0)
(@CGUID+1536, 35609, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8114.487, 1882.476, 54.87271, 3.637403, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Bilgewater Port - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1537, 35609, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8074.457, 1829.549, 42.74871, 3.717551, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Bilgewater Port - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1538, 49774, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8095.979, 1829.111, 37.91182, 3.36905, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1539, 35613, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8123.16, 1872.958, 55.74195, 3.974215, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Keensnout Potbelly (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+1540, 48925, UNKNOWN, 4737, 4768, 1, 1, 383, 0, 0, 0, 0, 0, 0, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Mook Disguise (Area: Gallywix's Villa - Difficulty: 0) (Auras: 75098 - Waltz Right In: Mook Disguise) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1541, 35075, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8289.063, 1787.5, 38.97979, 0.675427, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1542, 35075, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8264.584, 1743.75, 44.94909, 4.939573, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1543, 35063, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8262.41, 1786.823, 34.89709, 3.325168, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1544, 49773, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8281.25, 1785.417, 38.10479, 2.229858, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1545, 35234, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8257.426, 1728.622, 45.10446, 2.949606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1546, 35234, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8263.264, 1757.457, 42.53016, 3.508112, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1547, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8289.365, 1737.085, 47.59241, 4.672767, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1548, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8295.044, 1692.287, 51.00938, 2.346752, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1549, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8321.781, 1724.997, 50.84024, 3.141593, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1550, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8355.33, 1777.538, 45.53531, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1551, 37500, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8311.114, 1733.42, 51.54177, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Vinny Slapchop (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1552, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8296.822, 1705.702, 50.45953, 4.416254, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1553, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8322.782, 1735.315, 50.8197, 2.65071, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1554, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8293.104, 1701.872, 49.44961, 4.725869, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1555, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8303.361, 1724.389, 50.82278, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1556, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8238.476, 1710.34, 44.80164, 6.248279, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1557, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8251.743, 1718.37, 45.10204, 4.856748, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1558, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8339.379, 1744.828, 50.61301, 0.457478, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1559, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8302.882, 1752.55, 50.77023, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1560, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8261.316, 1724.969, 45.0377, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1561, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8331.61, 1702.26, 51.69974, 6.002385, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1562, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8313.613, 1722.87, 50.69486, 6.269197, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1563, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8330.815, 1723.962, 50.8057, 1.87794, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1564, 35120, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8369.686, 1722.438, 40.06365, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- FBoK Bank Teller (Area: Bilgewater Port - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1565, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8398.577, 1685.176, 49.63552, 2.131459, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1566, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8401.354, 1683.109, 49.65466, 2.341059, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1567, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8407.521, 1784.246, 45.50944, 3.183549, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1568, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8466.963, 1775.748, 45.98005, 2.454255, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1569, 4076, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8402.757, 1688.315, 49.94006, 3.382322, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1570, 35120, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8378.89, 1728.37, 40.03213, 4.590216, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- FBoK Bank Teller (Area: Bilgewater Port - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1571, 4076, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8428.125, 1682.292, 49.65466, 4.100647, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: The Pipe - Difficulty: 0)
(@CGUID+1572, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8489.379, 1717.74, 45.71572, 4.687588, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1573, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8478.468, 1672.479, 45.11134, 5.090841, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1574, 2110, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8420.846, 1675.679, 49.54234, 6.23999, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+1575, 2110, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8482.346, 1598.945, 45.68755, 3.719759, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+1576, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8477.212, 1614.501, 45.16544, 2.396548, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1577, 4076, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8489.626, 1613.847, 47.47379, 5.48611, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: The Pipe - Difficulty: 0)
(@CGUID+1578, 35234, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8470.082, 1602.392, 48.4777, 3.769911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: The Pipe - Difficulty: 0)
(@CGUID+1579, 35234, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8398.035, 1675.097, 49.63328, 1.884956, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: The Pipe - Difficulty: 0)
(@CGUID+1580, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8470.361, 1613.42, 44.68784, 4.309647, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1581, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8423.274, 1664.571, 49.11583, 0.8054091, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1582, 35234, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8446.14, 1612.18, 42.40793, 6.003932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: The Pipe - Difficulty: 0)
(@CGUID+1583, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8454.298, 1620.627, 43.53609, 3.375654, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1584, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8420.197, 1670.431, 49.52966, 5.89187, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1585, 2110, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8452.781, 1629.246, 44.58871, 4.206398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+1586, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8419.456, 1573.263, 42.77245, 6.113918, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1587, 2110, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8479.973, 1580.771, 46.00998, 3.426838, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+1588, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8479.13, 1590.845, 45.55669, 5.439032, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1589, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8446.01, 1574.252, 43.87087, 2.547582, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1590, 35234, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8453.482, 1552.422, 48.58144, 5.462881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: The Pipe - Difficulty: 0)
(@CGUID+1591, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8418.907, 1576.907, 41.89758, 1.070199, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1592, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8457.668, 1567.469, 46.42043, 0.04391706, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1593, 4076, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8463.187, 1542.566, 50.83508, 4.593359, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: The Pipe - Difficulty: 0)
(@CGUID+1594, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8415.463, 1612.925, 42.93784, 4.377408, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1595, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8475.976, 1574.243, 47.15166, 2.306968, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1596, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8464.979, 1581.977, 45.28921, 3.196333, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1597, 2110, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8439.713, 1562.118, 45.42529, 2.423623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+1598, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8401.041, 1646.875, 46.72997, 2.223349, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1599, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8454.771, 1546.625, 49.97314, 2.992472, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1600, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8394.997, 1600, 71.73109, 4.698128, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1601, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8451.85, 1539.384, 50.12646, 5.212498, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1602, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8393.302, 1620.174, 42.63135, 5.049867, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1603, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8452.084, 1539.583, 50.13062, 3.064312, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1604, 4076, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8450, 1585.938, 44.16421, 5.497787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: The Pipe - Difficulty: 0)
(@CGUID+1605, 35234, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8454.127, 1586.845, 44.92337, 4.956735, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: The Pipe - Difficulty: 0)
(@CGUID+1606, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8482.337, 1596.787, 45.82134, 4.65882, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1607, 2110, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8428.058, 1554.087, 46.7958, 5.088183, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+1608, 35063, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8392.386, 1604.712, 71.57146, 4.246325, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1609, 2110, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8443.228, 1597.504, 43.41421, 0.6392682, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: The Pipe - Difficulty: 0)
(@CGUID+1610, 35075, 648, 4737, 4840, 1, 1, 383, 0, 0, 0, -8445.927, 1603.256, 43.35116, 4.059326, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1611, 35234, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8369.967, 1631.302, 49.34315, 6.178465, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Drudgetown - Difficulty: 0)
(@CGUID+1612, 35075, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8356.454, 1631.89, 49.63836, 0.7295408, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1613, 35063, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8354.431, 1629.984, 49.63836, 5.884907, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1614, 2110, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8354.143, 1632.448, 49.63836, 2.954099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+1615, 35063, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8369.776, 1648.423, 48.36346, 4.095077, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1616, 35063, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8367.188, 1623.958, 48.53077, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1617, 35075, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8293.711, 1669.47, 50.87298, 5.721254, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1618, 35075, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8296.911, 1665.869, 50.85513, 5.233717, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1619, 35063, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8294.606, 1665.447, 50.85513, 6.022388, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1620, 35075, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8360.416, 1667.188, 49.92495, 3.926991, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1621, 35234, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8289.884, 1664.656, 50.86034, 5.934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Drudgetown - Difficulty: 0)
(@CGUID+1622, 35234, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8324.069, 1677.818, 52.09499, 4.502949, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Drudgetown - Difficulty: 0)
(@CGUID+1623, 35075, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8318.831, 1672.958, 50.85534, 0.3285211, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1624, 2110, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8295.391, 1650.539, 50.85513, 5.369958, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+1625, 35063, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8301.351, 1665.102, 50.8397, 1.616501, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1626, 4076, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8351.881, 1655.626, 49.9618, 2.561425, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+1627, 2110, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8379.573, 1674.693, 49.64893, 0.7310414, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+1628, 35234, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8300.728, 1680.2, 50.86127, 4.991642, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Drudgetown - Difficulty: 0)
(@CGUID+1629, 35063, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8369.755, 1668.423, 49.92099, 5.917629, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1630, 35075, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8290.104, 1655.208, 50.85513, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1631, 35075, 648, 4737, 4771, 1, 1, 383, 0, 0, 0, -8309.938, 1690.821, 50.98034, 4.124963, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1632, 49773, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8080.312, 1442.833, 9.416054, 4.818302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1633, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8046.141, 1405.732, 2.258759, 2.698877, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1634, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8031.573, 1322.54, 3.106792, 0.8621701, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1635, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8044.257, 1351.589, 5.150146, 5.317783, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1636, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8040.177, 1373.961, 2.605294, 4.079431, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1637, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8025.116, 1344.199, 1.261057, 0.02538517, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1638, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8009.507, 1329.975, -0.6110368, 1.557621, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1639, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8009.007, 1319.288, 0.8921371, 5.608445, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1640, 6827, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8012.379, 1373.69, -5.6178, 6.089011, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1641, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8012.959, 1237.879, 1.815783, 0.3532509, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1642, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8052.288, 1231.617, 2.891047, 5.754076, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1643, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8028.402, 1196.07, 1.430281, 4.235153, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1644, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8038.25, 1198.756, 2.654778, 2.78692, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1645, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8017.423, 1208, 0.6571846, 0.4461821, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1646, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8048.435, 1206.132, 3.386904, 0.07969495, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1647, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8013.594, 1206.681, 0.1415596, 0.6559931, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1648, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8051.351, 1210.965, 3.762148, 2.309139, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1649, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8134.094, 1205.523, 16.9562, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1650, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8046.516, 1140.671, 1.914752, 4.778828, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1651, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8057.064, 1136.015, 2.211627, 5.752765, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1652, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8056.157, 1148.542, 3.077227, 5.697968, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1653, 35063, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8051.956, 1160.436, 2.952227, 5.35795, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Slick - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1654, 6827, 648, 4737, 4772, 1, 1, 383, 0, 0, 0, -8030.25, 1154.462, -3.398467, 6.237356, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: The Slick - Difficulty: 0)
(@CGUID+1655, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8224.357, 1662.951, 38.05064, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit)
(@CGUID+1656, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8236.519, 1690.126, 43.83071, 4.622437, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1657, 49774, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8235.494, 1703.306, 44.8419, 4.960181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Swindle Street - Difficulty: 0)
(@CGUID+1658, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8241.666, 1689.063, 44.20058, 2.734173, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1659, 4076, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8269.379, 1660.92, 50.59928, 2.907635, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Swindle Street - Difficulty: 0)
(@CGUID+1660, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8263.084, 1680.751, 48.95058, 0.2502484, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1661, 35234, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8278.623, 1682.72, 49.93077, 1.518436, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Hired Looter (Area: Swindle Street - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1662, 35075, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8237.226, 1671.869, 42.10513, 6.257289, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1663, 4076, 648, 4737, 4773, 1, 1, 383, 0, 0, 0, -8266.479, 1657.391, 50.52008, 0.1079436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Swindle Street - Difficulty: 0)
(@CGUID+1664, 35609, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8122.262, 1885.552, 54.59142, 0.06981317, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Bilgewater Port - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1665, 35609, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8146.356, 1893.328, 68.70734, 4.764749, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Bilgewater Port - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1666, 35609, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8142.363, 1893.29, 68.69327, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Bilgewater Port - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1667, 35609, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8149.712, 1890.53, 56.49559, 6.161012, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Bilgewater Port - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
-- (@CGUID+1668, 48925, UNKNOWN, 4737, 4768, 1, 1, 383, 0, 0, 0, 0, 0, 0, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Mook Disguise (Area: Gallywix's Villa - Difficulty: 0) (Auras: 75098 - Waltz Right In: Mook Disguise) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1669, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8047.764, 1850.599, 52.25754, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+1670, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8068.772, 1883.821, 54.51051, 6.248279, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1671, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8007.962, 1867.139, 52.5988, 1.675516, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1672, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8067.897, 1912.328, 54.27574, 6.232172, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1673, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8043.038, 1917.368, 53.35839, 2.286381, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1674, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8082.492, 1908.555, 54.87659, 5.498874, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1675, 35613, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8080.368, 1906.436, 54.78748, 5.49888, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Keensnout Potbelly (Area: Gallywix's Villa - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1676, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8004.486, 1891.113, 53.35826, 5.480334, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1677, 48949, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8022.047, 1913.03, 62.81053, 4.732318, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1678, 49773, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -7998.294, 1880.218, 53.57082, 1.706732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1679, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8042.971, 1890.873, 53.3585, 3.857178, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1680, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8032.75, 1867.613, 52.61173, 1.480995, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1681, 49773, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8123.229, 1913.13, 55.16276, 2.843658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1682, 49773, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8004.478, 1936.405, 53.37421, 3.989337, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1683, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -7985.304, 1909.595, 52.59883, 3.298672, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1684, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -7984.94, 1896.24, 52.58443, 3.089233, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1685, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8004.443, 1917.335, 53.35836, 0.715585, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1686, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8048.344, 1946.219, 52.59726, 4.729842, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+1687, 35222, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -7965.832, 1903.352, 52.62671, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trade Prince Gallywix (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1688, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -7971.736, 1833.842, 12.75121, 3.281219, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+1689, 49772, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8120.18, 1934.667, 55.79753, 1.143442, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+1690, 35609, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -7971.274, 1825.872, 11.62702, 2.86234, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+1691, 48961, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8022.168, 1921.17, 63.58039, 4.590216, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Socialite (Area: Gallywix's Villa - Difficulty: 0) (possible waypoints or random movement)
-- (@CGUID+1692, 48925, UNKNOWN, 4737, 4768, 1, 1, 383, 0, 0, 0, 0, 0, 0, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Mook Disguise (Area: Gallywix's Villa - Difficulty: 0) (Auras: 75098 - Waltz Right In: Mook Disguise) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+1693, 48925, UNKNOWN, 4737, 4768, 1, 1, 383, 0, 0, 0, 0, 0, 0, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Mook Disguise (Area: Gallywix's Villa - Difficulty: 0) (Auras: 75098 - Waltz Right In: Mook Disguise) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
-- (@CGUID+1694, 48925, UNKNOWN, 4737, 4768, 1, 1, 383, 0, 0, 0, 0, 0, 0, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Mook Disguise (Area: Gallywix's Villa - Difficulty: 0) (Auras: 75098 - Waltz Right In: Mook Disguise) - !!! on transport - transport template not found !!! (possible waypoints or random movement)
(@CGUID+1695, 35063, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8095.62, 1709.667, 16.67037, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1696, 35063, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8105.872, 1687.531, 14.83163, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1697, 35075, 648, 4737, 4768, 1, 1, 383, 0, 0, 0, -8176.528, 1641.747, 23.36979, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1698, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8102.132, 1642.526, 9.639325, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1699, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8158.641, 1569.55, 19.53168, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1700, 35075, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8055.557, 1482.044, 9.496839, 4.511989, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1701, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8077.17, 1475.599, 8.926544, 4.873407, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1702, 35234, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8068.106, 1473.049, 9.028589, 5.602507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Hired Looter (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1703, 4076, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8032.291, 1463.542, 9.366076, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1704, 37056, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8071.526, 1482.724, 8.931467, 2.268928, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Supermodel (Area: Bilgewater Port - Difficulty: 0) (Auras: 70112 - Permanent Feign Death (On Fire))
(@CGUID+1705, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8153.393, 1395.79, 17.00088, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1706, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8118.978, 1375.741, 12.17748, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1707, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8136.868, 1280.62, 20.6901, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1708, 35063, 648, 4737, 4767, 1, 1, 383, 0, 0, 0, -8114.89, 1334.914, 16.64261, 0.08551589, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1709, 35075, 648, 4737, 0, 1, 1, 383, 0, 0, 0, -8138.127, 1236.545, 18.66534, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1710, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8447.252, 1246.847, 57.86066, 0.6457718, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1711, 35294, 648, 4737, 4765, 1, 1, 383, 0, 0, 0, -8433.984, 1215.997, 45.3097, 3.228859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1712, 34673, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8429.511, 1311.616, 103.4428, 3.350217, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Bamm Megabomb (Area: KTC Headquarters - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1713, 49774, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8428.225, 1307.96, 102.4495, 0.6760393, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1714, 48304, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8436.88, 1305.78, 102.5663, 0.6632251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1715, 48304, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8432.969, 1306.71, 102.5413, 1.012291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1716, 34668, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8424.748, 1322.33, 102.9292, 1.553343, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sassy Hardwrench (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1717, 34874, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8435.328, 1316.877, 102.6322, 0.9599311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Megs Dreadshredder (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1718, 48304, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8436.389, 1310.16, 102.4263, 0.2443461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1719, 48304, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8430.861, 1302.59, 102.7883, 1.413717, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1720, 34693, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8398.679, 1334.172, 102.1039, 3.736393, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: KTC Headquarters - Difficulty: 0) (Auras: 80264 - Stealth) (possible waypoints or random movement)
(@CGUID+1721, 48304, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8427.5, 1305.22, 102.4173, 1.850049, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Training Dummy (Area: KTC Headquarters - Difficulty: 0) (Auras: 83470 - Arcane Missiles Trainer)
(@CGUID+1722, 49773, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8505.967, 1290.128, 102.6077, 6.174626, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1723, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8472.531, 1236.774, 52.63137, 2.094395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1724, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8447.201, 1246.738, 57.8442, 0.5934119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1725, 37804, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8104.13, 1488.54, 22.24953, 4.29351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kaja'Cola Balloon (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1726, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8433.857, 1216.278, 45.30939, 5.375614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1727, 2110, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8436.078, 1197.252, 40.61861, 4.820912, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1728, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8490.596, 1171.179, 42.01693, 2.408554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1729, 2110, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8488.849, 1210.004, 42.05413, 1.79791, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1730, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8537.514, 1259.681, 53.5423, 1.239184, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1731, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8511.13, 1241.116, 54.9388, 0.9773844, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1732, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8516.518, 1199.802, 50.92175, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1733, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8434.153, 1151.519, 44.05191, 3.735005, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1734, 4076, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8429.113, 1179.621, 40.72876, 4.596957, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1735, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8484.363, 1200.91, 41.9501, 3.385939, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1736, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8449.679, 1194.71, 41.08184, 2.6529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1737, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8423.348, 1174.995, 41.01904, 5.51524, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1738, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8406.774, 1157.755, 39.39668, 0.541052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1739, 35294, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8468.973, 1159.984, 40.77166, 1.047198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: KTC Headquarters - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1740, 2110, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8563.978, 1281.116, 46.07076, 1.346181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1741, 35294, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8505.795, 1151.672, 54.29784, 3.124139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1742, 35294, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8561.192, 1278.998, 46.82899, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1743, 2110, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8582.81, 1253.815, 45.97859, 2.244389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1744, 2110, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8607.894, 1298.536, 40.65024, 3.598929, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1745, 35294, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8598.099, 1234.129, 46.62732, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1746, 34865, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8598.8, 1226.81, 47.15413, 1.518436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1747, 34865, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8599.02, 1243.01, 45.78713, 2.687807, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1748, 2110, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8612.836, 1275.697, 41.8638, 5.421896, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kaja'mine - Difficulty: 0)
(@CGUID+1749, 35294, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8584.134, 1264.427, 45.36959, 4.782202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1750, 35294, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8599.464, 1292.042, 42.13031, 5.113815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rebellious Troll (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1751, 34865, 648, 4737, 4766, 1, 1, 384, 0, 0, 0, -8620.33, 1282.25, 40.89793, 5.183628, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Tunneling Worm (Area: Kaja'mine - Difficulty: 0) (Auras: 29266 - Permanent Feign Death)
(@CGUID+1752, 49774, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8245.584, 1255.101, 28.33434, 3.085164, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1753, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8347.072, 1447.791, 47.65436, 3.54934, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1754, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8276.717, 1427.169, 39.72568, 4.893815, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1755, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8309.725, 1447.17, 42.56679, 4.820564, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1756, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8284.758, 1440.269, 40.53825, 1.518059, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1757, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8269.543, 1439.6, 39.76453, 4.662146, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1758, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8256.21, 1427.385, 39.98723, 3.216966, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1759, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8252.084, 1414.583, 40.17473, 3.631857, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1760, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8211.089, 1288.319, 31.11943, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1761, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8209.444, 1291.219, 30.67967, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1762, 49772, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8205.251, 1365.03, 34.40454, 5.305268, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1763, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8168.159, 1273.601, 25.33325, 1.478724, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1764, 49773, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8168.785, 1335.086, 27.66148, 5.525404, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1765, 49774, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8165.532, 1244.805, 22.99862, 2.461361, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: KTC Headquarters - Difficulty: 0)
(@CGUID+1766, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8125.37, 1307.078, 19.01196, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1767, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8145.974, 1334.08, 21.96241, 1.880499, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1768, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8186.002, 1294.03, 27.73427, 5.914796, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1769, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8169.196, 1305.916, 26.38891, 3.926239, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1770, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8190.94, 1305.604, 28.08349, 1.955983, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1771, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8131.246, 1305.907, 19.69755, 0.5355265, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1772, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8162.906, 1264.208, 24.50242, 1.087048, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1773, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8168.857, 1299.79, 24.82425, 3.995962, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1774, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8155.906, 1296.814, 23.86696, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1775, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8139.951, 1282.419, 21.06584, 1.474106, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1776, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8197.549, 1291.879, 28.96826, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1777, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8140.922, 1237.828, 19.18586, 2.401006, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1778, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8121.206, 1263.315, 20.63462, 2.659463, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1779, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8164.047, 1295.455, 24.93436, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1780, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8133.678, 1298.812, 20.32806, 2.090295, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1781, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8124.349, 1323.84, 18.02275, 5.706114, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1782, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8140.464, 1292.869, 21.01414, 0.7034749, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1783, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8153.723, 1343.409, 22.86469, 3.329221, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1784, 35063, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8124.243, 1337.266, 17.34306, 1.98598, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1785, 49131, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8105.865, 1481.101, 11.78764, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+1786, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8105.116, 1480.629, 11.3364, 4.276057, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1787, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8126.118, 1362.481, 15.4615, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1788, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8102.716, 1309.53, 17.95226, 0.4566643, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1789, 49131, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8103.906, 1480.872, 11.96017, 2.426008, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+1790, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8125.521, 1353.646, 14.74393, 4.802818, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1791, 49131, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8102.66, 1480.885, 10.19081, 5.009095, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+1792, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8095.368, 1385.438, 13.48752, 4.997244, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1793, 49773, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8109.519, 1267.407, 20.9123, 1.263251, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: 0 - Difficulty: 0)
(@CGUID+1794, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8101.272, 1478.403, 10.19917, 2.670354, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1795, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8130.792, 1376.753, 12.63487, 5.035682, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1796, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8133.301, 1375.851, 13.20192, 5.252277, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1797, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8104.306, 1480.247, 12.49105, 6.038839, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1798, 49131, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8105.127, 1481.156, 13.10256, 0.1919862, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+1799, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8129.003, 1209.731, 17.46084, 0.2330159, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1800, 6827, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8054.609, 1342.709, 6.48131, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+1801, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8103.698, 1374.993, 13.24401, 0.1911653, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1802, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8110.416, 1340.168, 16.67382, 1.570796, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1803, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8122.599, 1343.938, 15.56925, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit)
(@CGUID+1804, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8101.835, 1480.951, 10.19054, 3.577925, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1805, 49131, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8107.668, 1478.983, 10.19757, 0.7853982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+1806, 49131, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8104.731, 1479.365, 10.1961, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+1807, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8105.189, 1478.941, 11.48717, 4.433136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1808, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8124.716, 1385.512, 11.83738, 3.306, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1809, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8104.828, 1478.042, 10.2006, 1.448623, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1810, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8104.026, 1483.67, 10.18145, 4.433136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1811, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8108.375, 1482.531, 10.18557, 5.67232, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1812, 49131, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8106.809, 1481.99, 10.18732, 3.979351, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: 0 - Difficulty: 0)
(@CGUID+1813, 49132, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8101.585, 1483.24, 10.18276, 3.857178, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Trike (Area: 0 - Difficulty: 0)
(@CGUID+1814, 6827, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8034.027, 1225.453, 1.9684, 1.217854, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+1815, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8055.588, 1204.092, 3.578908, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1816, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8038.269, 1198.429, 2.686324, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1817, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8042.662, 1212.438, 3.158079, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1818, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8052.309, 1165.597, 2.954614, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1819, 6827, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8063.503, 1137.903, 2.438067, 3.147452, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+1820, 6827, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8046.416, 1140.729, 1.909747, 4.818084, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+1821, 6827, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8055.067, 1155.534, 3.077227, 6.230397, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+1822, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8051.608, 1156.927, 3.020235, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1823, 6827, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8027.804, 1195.753, 1.290422, 4.487787, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: 0 - Difficulty: 0)
(@CGUID+1824, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8042.156, 1391.461, 2.206169, 4.895391, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1825, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8194.289, 1419.934, 27.09471, 5.228397, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1826, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8110.005, 1442.892, 10.30476, 3.64156, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1827, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8121.584, 1462.875, 10.40109, 4.919665, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1828, 49772, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8106.672, 1403.543, 10.43005, 5.048649, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1829, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8112.34, 1423.78, 14.55338, 4.019588, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1830, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8125.323, 1397.028, 10.62388, 0.2542596, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1831, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8043.749, 1356.84, 5.151611, 1.717786, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1832, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8153.393, 1395.79, 17.00088, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1833, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8113.19, 1440.17, 10.83843, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1834, 49774, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8087.553, 1436.979, 9.958614, 3.665834, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1835, 6827, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8059.142, 1394.303, 5.721046, 6.246093, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1836, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8107.104, 1412.233, 17.85814, 4.499182, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1837, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8113.713, 1428.194, 13.39501, 0.7242381, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1838, 49773, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8138.763, 1424.337, 11.83978, 6.058583, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1839, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8078.125, 1414.108, 11.11247, 5.43413, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1840, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8092.569, 1434.63, 10.24047, 1.874251, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1841, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8127.916, 1443.574, 10.98041, 4.152427, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1842, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8119.66, 1479.705, 10.47372, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1843, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8107.061, 1470.097, 10.11373, 2.722573, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1844, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8128.85, 1479.598, 11.67873, 3.918854, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1845, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8117.522, 1471.064, 10.20665, 2.18317, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1846, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8106.26, 1482.691, 24.17676, 1.239184, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1847, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8090.357, 1476.666, 8.926544, 5.31893, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1848, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8106.431, 1463.478, 10.092, 1.659204, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1849, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8129.08, 1478.658, 11.09499, 3.099416, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1850, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8109.823, 1465.914, 10.09908, 2.806127, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1851, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8104.494, 1468.058, 10.10772, 3.761484, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1852, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8096.755, 1481.531, 10.15458, 1.463428, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1853, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8106.155, 1470.459, 10.11519, 1.318666, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1854, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8093.535, 1468.949, 9.213409, 3.299739, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1855, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8096.695, 1468.933, 10.11288, 6.077849, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1856, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8092.479, 1474.366, 8.975006, 4.804404, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1857, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8131.041, 1472.258, 12.17336, 4.217819, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1858, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8114.876, 1477.958, 10.11821, 2.400124, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1859, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8106.2, 1482.701, 22.44057, 1.239184, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1860, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8125.468, 1466.853, 10.94679, 4.615735, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1861, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8119.43, 1466.096, 10.23745, 2.008432, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1862, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8124.722, 1488.046, 11.24929, 1.12881, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1863, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8104.443, 1467.579, 10.10615, 6.14433, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1864, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8115.881, 1484.05, 10.06326, 5.026324, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1865, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8107.417, 1464.549, 10.09525, 1.754274, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1866, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8114.71, 1506.644, 10.04839, 1.371636, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1867, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8116.136, 1503.144, 9.953782, 2.050747, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1868, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8122.118, 1503.052, 10.45073, 2.826602, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1869, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8121.966, 1494.139, 11.24197, 5.311761, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1870, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8067.077, 1483.884, 8.926544, 1.11443, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1871, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8091.666, 1484.375, 9.051544, 3.961163, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1872, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8125.076, 1498.128, 11.2571, 5.061719, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1873, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8087.494, 1479.064, 8.926544, 4.756948, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1874, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8097.626, 1490.23, 10.04736, 5.184771, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1875, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8129.916, 1500.626, 13.25591, 2.709268, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1876, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8128.609, 1496.2, 11.52325, 6.007367, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1877, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8077.961, 1486.179, 8.926544, 4.176798, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1878, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8089.214, 1490.05, 9.28303, 2.927619, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1879, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8122.027, 1501.577, 10.59685, 5.391259, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1880, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8086.791, 1488.688, 8.926544, 0.72425, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1881, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8101.91, 1505.443, 9.955032, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1882, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8122.442, 1493.258, 11.34841, 5.441331, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1883, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8126.842, 1490.437, 11.53689, 1.959451, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1884, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8085.138, 1491.429, 8.982503, 5.539243, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1885, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8134.491, 1495.106, 16.28726, 2.381259, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1886, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8127.514, 1498.758, 11.59499, 2.231497, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1887, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8085.849, 1480.078, 8.926544, 2.777515, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1888, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8115.549, 1498.649, 9.597679, 0.9786056, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1889, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8116.171, 1509.601, 10.2708, 0.2121905, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1890, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8114.309, 1519.095, 10.17217, 4.869269, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1891, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8107.137, 1511.91, 9.861835, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1892, 4076, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8032.379, 1463.19, 9.376574, 0.4015538, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1893, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8048.987, 1509.973, 9.657085, 0.6950659, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1894, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8087.186, 1503.359, 8.868902, 5.75912, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1895, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8073.118, 1506.072, 8.868902, 5.461095, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1896, 2110, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8050.618, 1514.972, 9.361431, 2.092971, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1897, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8095.518, 1521.148, 9.607487, 0.9742279, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1898, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8114.223, 1508.758, 9.892625, 0.5256851, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1899, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8048.564, 1489.62, 9.917859, 0.3950597, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1900, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8111.844, 1511.361, 9.78884, 3.732668, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1901, 49774, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8179.777, 1496.119, 44.25574, 6.235277, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1902, 49772, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8084.428, 1539.976, 9.100637, 3.937454, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1903, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8010.416, 1553.646, 1.824095, 3.141593, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1904, 49772, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8082.789, 1559.923, 8.597219, 3.373709, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1905, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8075.169, 1540.173, 8.300222, 0.09647378, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1906, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8119.856, 1578.089, 11.67655, 3.693292, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1907, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8132.024, 1576.816, 13.51444, 5.49788, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1908, 6827, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8023.125, 1542.305, 1.949095, 0.06249176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1909, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8085.416, 1587.348, 8.108845, 4.712389, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1910, 2110, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8137.591, 1602.504, 15.10733, 5.136634, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1911, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8095.646, 1609.433, 8.724047, 1.115939, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1912, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8142.709, 1581.771, 16.16977, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1913, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8015.391, 1556.351, 2.199095, 1.040601, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1914, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8180.294, 1544.462, 31.27491, 4.931732, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1915, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8195.184, 1554.942, 29.82325, 2.989595, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1916, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8188.589, 1550.5, 30.52979, 4.340362, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1917, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8168.269, 1589.555, 23.83591, 5.573634, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1918, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8040.355, 1573.71, 2.589664, 0.4196897, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1919, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8100.208, 1547.96, 9.097002, 5.874549, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1920, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8142.471, 1580.204, 15.79477, 3.132804, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1921, 4076, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8136.522, 1607.111, 14.97891, 2.69329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1922, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8159.003, 1569.164, 19.85191, 0.3955878, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1923, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8154.798, 1590.029, 18.77018, 5.386764, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1924, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8111.629, 1559.275, 9.233767, 6.138048, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1925, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8178.646, 1578.646, 24.08591, 3.06863, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1926, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8176.899, 1598.776, 23.96091, 2.356123, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1927, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8143.316, 1627.273, 15.33949, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1928, 49131, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8102.243, 1723.155, 19.61651, 5.585053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1929, 49131, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8097.827, 1719.533, 18.9725, 2.460914, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+1930, 2110, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8188.345, 1614.224, 27.392, 3.219864, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Swindle Street - Difficulty: 0)
(@CGUID+1931, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8110.938, 1660.842, 11.55391, 2.074744, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1932, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8229.285, 1553.495, 37.0932, 3.687123, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1933, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8095.17, 1640.888, 9.403494, 0.3911598, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1934, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8102.132, 1642.526, 9.639325, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1935, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8184.622, 1634.201, 25.12727, 1.561756, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1936, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8138.576, 1653.998, 15.58661, 3.540556, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1937, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8226.806, 1596.354, 33.63471, 3.141593, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1938, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8193.25, 1587.17, 28.49118, 1.34645, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1939, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8154.419, 1642.846, 19.14707, 1.252354, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1940, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8200.586, 1629.946, 29.93042, 5.745207, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1941, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8180.274, 1655.078, 24.34236, 3.268132, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1942, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8176.515, 1642.893, 24.02005, 1.559721, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1943, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8226.142, 1578.292, 33.63471, 2.996239, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1944, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8181.578, 1654.835, 24.34236, 2.347265, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1945, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8132.76, 1635.825, 14.58614, 1.085753, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1946, 2110, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8174.488, 1614.836, 24.53967, 3.940824, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Swindle Street - Difficulty: 0)
(@CGUID+1947, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8265.342, 1499.111, 43.59169, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1948, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8259.167, 1496.354, 42.1481, 3.141593, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1949, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8264.445, 1530.593, 41.83195, 3.008467, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1950, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8278.723, 1506.204, 43.6131, 6.18016, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1951, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8276.538, 1491.449, 43.17033, 4.332951, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit)
(@CGUID+1952, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8249.025, 1478.208, 41.46866, 5.217716, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1953, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8250.98, 1485.636, 41.5231, 5.382018, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1954, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8277.67, 1497.08, 43.27457, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1955, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8228.759, 1493.375, 40.33158, 4.489374, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1956, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8269.278, 1510.367, 42.9798, 3.149685, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1957, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8236.865, 1595.143, 33.67331, 3.52347, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1958, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8222.916, 1477.083, 39.80046, 3.142062, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1959, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8259.82, 1507.374, 42.54924, 1.708974, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1960, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8246.511, 1527.639, 41.56388, 1.231919, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1961, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8284.904, 1501.424, 45.96696, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1962, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8226.692, 1618.223, 33.78198, 5.067475, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1963, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8223.342, 1476.736, 39.80046, 4.653922, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1964, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8274.132, 1496.657, 43.00907, 4.38958, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1965, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8298.779, 1533.621, 46.37834, 2.819754, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1966, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8280.453, 1530.012, 44.59406, 3.734444, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1967, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8269.271, 1549.479, 41.1563, 3.058136, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1968, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8259.556, 1498.962, 43.2802, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1969, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8234.954, 1519.355, 40.83055, 3.209384, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1970, 49772, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8226.041, 1526.042, 40.08761, 0.1286182, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Swindle Street - Difficulty: 0)
(@CGUID+1971, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8290.341, 1501.651, 44.13239, 6.132064, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1972, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8311.021, 1526.313, 46.34441, 3.183136, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1973, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8306.388, 1491.844, 45.1824, 1.690393, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1974, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8247.106, 1469.585, 41.15115, 3.026839, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1975, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8248.611, 1464.342, 41.14989, 3.591041, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1976, 49774, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8322.85, 1527.435, 47.4594, 0.01685321, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Swindle Street - Difficulty: 0)
(@CGUID+1977, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8259.889, 1468.826, 43.10676, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1978, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8286.286, 1498.863, 44.58114, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1979, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8226.595, 1457.064, 39.59649, 2.645761, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1980, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8271.582, 1473.918, 42.79533, 4.47154, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1981, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8317.355, 1515.897, 46.57488, 3.883979, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1982, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8284.359, 1469.01, 44.55949, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1983, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8289.349, 1493.069, 44.04533, 3.136736, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1984, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8260.448, 1468.897, 43.27324, 6.194438, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1985, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8306.943, 1504.894, 45.20537, 1.66411, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1986, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8306.055, 1543.252, 47.76423, 3.341676, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1987, 35075, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8278.525, 1487.102, 43.28092, 3.004103, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1988, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8322.864, 1540.076, 47.13984, 5.294219, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1989, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8276.489, 1467.903, 44.56942, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1990, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8281.221, 1472.847, 43.42033, 3.198538, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1991, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8279.291, 1479.303, 43.24772, 0.3293143, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1992, 35063, 648, 4737, 4773, 1, 1, 384, 0, 0, 0, -8260.976, 1467.686, 43.64375, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Swindle Street - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1993, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8315.625, 1476.042, 45.50327, 5.804236, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1994, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8243.239, 1448.274, 40.25389, 1.572032, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1995, 35075, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8231.75, 1444.646, 39.65243, 5.314309, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1996, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8277.95, 1462.841, 42.87708, 0.3217506, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1997, 35075, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8253.069, 1455.426, 41.18456, 6.161369, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1998, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8328.386, 1454.192, 46.45815, 5.177601, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1999, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8267.933, 1459.919, 42.07397, 3.224135, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2000, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8322.103, 1502.062, 46.17424, 5.182765, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2001, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8216.087, 1435.969, 35.95596, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2002, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8347.754, 1497.752, 46.56873, 4.273787, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2003, 49774, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8336.89, 1453.622, 46.94965, 4.991831, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Kajaro Field - Difficulty: 0)
(@CGUID+2004, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8352.287, 1467.796, 48.08214, 5.330449, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2005, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8335.355, 1478.414, 46.91663, 2.98318, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2006, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8361.939, 1509.708, 46.332, 0.4984494, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2007, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8327.54, 1526.747, 47.11406, 2.551048, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2008, 4076, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8399.158, 1529.31, 50.44727, 4.81952, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+2009, 4076, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8415.083, 1521.842, 50.85731, 1.745605, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+2010, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8391.132, 1535.98, 50.42296, 5.614081, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2011, 4076, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8356.351, 1564.151, 50.35515, 5.58906, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+2012, 4076, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8358.714, 1602.13, 49.6019, 0.1371997, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+2013, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8393.61, 1571.32, 42.43743, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2014, 35075, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8406.645, 1522.399, 50.72908, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2015, 35075, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8340.646, 1584.082, 50.48627, 5.07131, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2016, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8400.988, 1535.672, 50.34982, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2017, 2110, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8339.908, 1606.769, 50.26336, 0.6185364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Kajaro Field - Difficulty: 0)
(@CGUID+2018, 4076, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8339.584, 1581.25, 50.29877, 4.972687, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Kajaro Field - Difficulty: 0)
(@CGUID+2019, 35063, 648, 4737, 4822, 1, 1, 384, 0, 0, 0, -8362.689, 1580.16, 48.88971, 2.215127, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Kajaro Field - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2020, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8459.728, 1591.075, 45.33168, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2021, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8450.124, 1586.184, 44.15168, 5.917984, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2022, 4076, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8441.827, 1561.424, 45.92742, 2.834978, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+2023, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8442.323, 1621.203, 42.15334, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2024, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8417.009, 1530.05, 50.85703, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2025, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8354.431, 1629.984, 49.63328, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2026, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8439.05, 1602.37, 43.40423, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2027, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8420.72, 1570.52, 42.75393, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2028, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8409.092, 1614.111, 41.72029, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2029, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8457.071, 1549.004, 49.94436, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2030, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8398.174, 1610.222, 72.36791, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2031, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8471.071, 1573.295, 47.23859, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2032, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8417.46, 1548.91, 46.29363, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2033, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8441.674, 1544.504, 48.02182, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2034, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8396.232, 1632.927, 43.99229, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2035, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8417.22, 1574.62, 42.21663, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2036, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8449.455, 1538.755, 49.87267, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2037, 4076, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8443.402, 1595.503, 43.41421, 0.9323038, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+2038, 4076, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8427.812, 1548.985, 46.95522, 4.512496, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+2039, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8372.891, 1632.696, 49.42769, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2040, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8463.055, 1544.305, 50.62659, 1.884631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2041, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8445.837, 1574.413, 43.73639, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2042, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8397.082, 1637.46, 44.13096, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2043, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8394.264, 1602.672, 71.49812, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2044, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8465.188, 1569.019, 47.25749, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2045, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8351.571, 1631.84, 49.63836, 6.050981, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2046, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8366.147, 1647.833, 49.37479, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2047, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8480.631, 1600.133, 46.61736, 3.896081, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2048, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8449.064, 1630.81, 43.88961, 5.914821, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2049, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8481.183, 1589.63, 45.71301, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2050, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8482.808, 1596.637, 45.91446, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2051, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8356.654, 1633.076, 49.63328, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2052, 4076, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8478.488, 1579.944, 45.94866, 1.19624, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+2053, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8468.232, 1616.773, 44.43034, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2054, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8428.13, 1653.123, 45.84929, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2055, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8379.413, 1665.722, 49.64859, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2056, 4076, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8489.912, 1619.469, 47.28629, 3.763833, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+2057, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8401.357, 1681.688, 49.68243, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2058, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8423.972, 1688.29, 49.74805, 5.615022, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2059, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8482.573, 1619.976, 46.87614, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2060, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8397.377, 1690.217, 50.01052, 5.495792, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2061, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8354.969, 1669.839, 50.28992, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2062, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8429.778, 1672.014, 49.72691, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2063, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8420.169, 1675.99, 49.58539, 6.064271, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2064, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8351.841, 1653.952, 49.86861, 1.424493, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2065, 4076, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8377.67, 1676.398, 49.67588, 3.878153, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+2066, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8396.598, 1685.533, 49.58962, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2067, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8482.261, 1668.056, 46.39735, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2068, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8290.158, 1736.845, 47.82446, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2069, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8299.667, 1651.273, 50.85513, 4.295529, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2070, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8291.346, 1659.88, 50.86124, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2071, 2110, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8265.453, 1653.443, 50.56316, 5.217023, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Black Rat (Area: Drudgetown - Difficulty: 0)
(@CGUID+2072, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8301.145, 1662.097, 50.86127, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2073, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8303.361, 1724.389, 50.82278, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2074, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8291.701, 1704.998, 49.10064, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2075, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8335.587, 1748.219, 50.74755, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2076, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8318.563, 1730.882, 50.71561, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2077, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8301.158, 1674.594, 50.86127, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2078, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8288.489, 1669.679, 50.84917, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2079, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8313.857, 1723.465, 50.75271, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2080, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8321.413, 1672.214, 50.86127, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2081, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8308.337, 1690.274, 50.95203, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2082, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8291.701, 1704.998, 49.10064, 5.323254, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2083, 4076, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8267.829, 1660.029, 50.53072, 5.669139, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Drudgetown - Difficulty: 0)
(@CGUID+2084, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8262.91, 1680.899, 49.02222, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2085, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8331.314, 1724.347, 50.82882, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2086, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8295.479, 1687.964, 50.26979, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2087, 35063, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8302.882, 1752.55, 50.77023, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2088, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8298.826, 1674.755, 50.86127, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2089, 35075, 648, 4737, 4771, 1, 1, 384, 0, 0, 0, -8329.389, 1705.814, 51.38834, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Drudgetown - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2090, 49772, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8274.946, 1777.923, 39.65313, 5.246363, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: First Bank of Kezan - Difficulty: 0)
(@CGUID+2091, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8232.291, 1686.458, 43.5051, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2092, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8261.316, 1724.969, 45.0377, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2093, 49773, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8323.154, 1794.053, 42.21745, 5.02611, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: First Bank of Kezan - Difficulty: 0)
(@CGUID+2094, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8250.571, 1714.918, 45.04721, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2095, 49773, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8240.042, 1703.693, 44.81524, 0.7773619, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: First Bank of Kezan - Difficulty: 0)
(@CGUID+2096, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8293.167, 1783.986, 40.90273, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2097, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8245.596, 1669.471, 47.0043, 6.090765, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2098, 35075, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8254.688, 1792.188, 32.84273, 0.4948701, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2099, 49774, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8209.897, 1751.179, 43.34242, 5.47017, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: First Bank of Kezan - Difficulty: 0)
(@CGUID+2100, 35075, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8224.357, 1662.951, 38.05064, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit)
(@CGUID+2101, 35075, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8355.33, 1777.538, 45.53531, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2102, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8231.165, 1747.124, 45.64221, 4.461411, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2103, 35075, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8238.518, 1699.479, 44.70058, 3.140993, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2104, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8266.243, 1757.63, 42.69201, 1.890707, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2105, 35075, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8238.571, 1716.75, 44.80049, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2106, 35063, 648, 4737, 4770, 1, 1, 384, 0, 0, 0, -8231.724, 1736.038, 44.92318, 4.501582, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: First Bank of Kezan - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2107, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8410.122, 1780.646, 47.34195, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2108, 35063, 648, 4737, 4840, 1, 1, 384, 0, 0, 0, -8489.076, 1726.681, 45.76929, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2109, 35075, 648, 4737, 4840, 1, 1, 384, 0, 0, 0, -8455.436, 1777.601, 46.0641, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: The Pipe - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2110, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8188.303, 1782.278, 30.1125, 5.215053, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2111, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8178.383, 1800.828, 29.3944, 1.314251, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2112, 4076, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8135.913, 1748.177, 21.98507, 4.47137, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Roach (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+2113, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8121.582, 1745.155, 20.74346, 2.193641, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2114, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8116.396, 1781.326, 28.33523, 0.7544712, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2115, 49774, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8092.548, 1822.238, 37.27374, 1.048983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+2116, 49773, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8138.541, 1801.042, 23.63059, 3.194775, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+2117, 49218, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7958.762, 1833.286, 10.06933, 3.508112, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2118, 49218, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7957.026, 1834.627, 9.643387, 3.351032, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2119, 49218, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7954.236, 1831.879, 8.4144, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2120, 6827, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8017.563, 1789.584, 2.706211, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2121, 49218, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7954.405, 1834.269, 9.046707, 3.193953, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2122, 49218, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7956.736, 1832.643, 9.347389, 3.455752, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2123, 6827, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8060.416, 1778.381, 3.125714, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2124, 49772, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8127.619, 1911.242, 54.83133, 2.186094, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2125, 49218, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7954.785, 1836.361, 9.138016, 3.577925, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat) (possible waypoints or random movement)
(@CGUID+2126, 49773, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8121.076, 1729.855, 18.204, 5.128433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Robo-Chick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2127, 49772, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8004.939, 1934.655, 53.21592, 4.662439, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2128, 49772, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7999.687, 1875.558, 53.31517, 1.286987, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabbot (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2129, 49774, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8122.367, 1933.704, 55.67253, 0.6202936, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Rabid Nut Varmint 5000 (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2130, 35075, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8095.776, 1707.85, 17.11005, 5.792731, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2131, 35075, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8062.288, 1696.933, 14.16795, 1.547268, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2132, 35075, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8112.114, 1715.647, 17.76918, 0.2121287, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2133, 35075, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -8102.007, 1684.659, 14.3711, 4.62008, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Gallywix's Villa - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2134, 6827, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8024.556, 1717.417, 3.14572, 3.405531, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+2135, 6827, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8020.818, 1604.526, 2.268762, 0.880808, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+2136, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8008.272, 1641.445, 2.816041, 1.244722, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2137, 6827, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8007.171, 1648.046, 2.33123, 0.1252518, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+2138, 6827, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8005.265, 1585.628, 2.400547, 2.615461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Bilgewater Port - Difficulty: 0)
(@CGUID+2139, 37682, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8431.91, 1358.271, 133.8549, 4.764749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 447 Fireworks Bunny (Area: KTC Headquarters - Difficulty: 0) (Auras: 70268 - 447: Claims Adjuster Quest Invis 1)
(@CGUID+2140, 37682, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8406.944, 1353.835, 113.3013, 4.502949, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 447 Fireworks Bunny (Area: KTC Headquarters - Difficulty: 0) (Auras: 70268 - 447: Claims Adjuster Quest Invis 1)
(@CGUID+2141, 37682, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8422.502, 1347.507, 114.5695, 4.677482, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 447 Fireworks Bunny (Area: KTC Headquarters - Difficulty: 0) (Auras: 70268 - 447: Claims Adjuster Quest Invis 1)
(@CGUID+2142, 37682, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8419.153, 1355.212, 134.7274, 4.834562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 447 Fireworks Bunny (Area: KTC Headquarters - Difficulty: 0) (Auras: 70268 - 447: Claims Adjuster Quest Invis 1)
(@CGUID+2143, 37602, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8419.556, 1323.385, 104.5969, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Claims Adjuster (Area: KTC Headquarters - Difficulty: 0) (Auras: 70268 - 447: Claims Adjuster Quest Invis 1)
(@CGUID+2144, 37682, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8405.054, 1362.967, 129.4254, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 447 Fireworks Bunny (Area: KTC Headquarters - Difficulty: 0) (Auras: 70268 - 447: Claims Adjuster Quest Invis 1)
(@CGUID+2145, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8211.089, 1288.319, 31.11943, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2146, 35075, 648, 4737, 4765, 1, 1, 384, 0, 0, 0, -8209.444, 1291.219, 30.67967, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: KTC Headquarters - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2147, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8115.745, 1330.994, 17.6412, 5.892399, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2148, 35075, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8155.906, 1296.814, 23.86696, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2149, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8134.094, 1205.523, 16.9562, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2150, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8126.118, 1362.481, 15.4615, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2151, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8117.307, 1382.269, 11.87951, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2152, 35063, 648, 4737, 0, 1, 1, 384, 0, 0, 0, -8125.37, 1307.078, 19.01196, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2153, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8189.219, 1414.934, 24.98451, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2154, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8122.327, 1473.866, 9.905486, 0, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2155, 35075, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8027.348, 1743.962, 1.266629, 2.380036, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2156, 35063, 648, 4737, 4767, 1, 1, 384, 0, 0, 0, -8002.084, 1714.583, 2.436736, 3.926874, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Kezan Citizen (Area: Bilgewater Port - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2157, 24110, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7850.168, 1843.309, 7.407844, 4.660029, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Large (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2158, 49131, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7849.288, 1844.601, 0.7404743, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Hot Rod (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2159, 6827, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7998.403, 1727.425, 0.7327268, 5.48934, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Strand Crab (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2160, 24288, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7893.043, 1834.071, 4.685856, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- ELM General Purpose Bunny Hide Body (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2161, 37683, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7858.7, 1838.418, 7.876031, 0.4537856, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2162, 37683, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7850.538, 1827.311, 13.24759, 1.43117, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2163, 37683, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7854.799, 1835.764, 8.08342, 1.343904, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2164, 35222, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7854.503, 1847.41, 7.218571, 5.427974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Trade Prince Gallywix (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2165, 34874, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7847.406, 1836.906, 7.860241, 1.500983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Megs Dreadshredder (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2166, 37683, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7845.115, 1835.269, 8.089192, 1.570796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2167, 35054, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7852.356, 1846.076, 7.386139, 5.305801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Chip Endale (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2168, 37708, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7848.03, 1848.634, 7.119463, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Izzy (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2169, 34673, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7844.594, 1849.17, 7.078383, 4.18879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Bamm Megabomb (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2170, 37710, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7849.372, 1849.134, 7.110757, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Gobber (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2171, 37709, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7850.688, 1848.939, 7.107933, 4.642576, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Ace (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2172, 34872, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7852.503, 1836.703, 7.933952, 1.692969, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Foreman Dampwick (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2173, 34668, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7857.325, 1842.981, 7.504481, 6.003932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Sassy Hardwrench (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2174, 34693, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7843.837, 1848.122, 7.1345, 3.926991, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Slinky Sharpshiv (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2175, 35053, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7854.03, 1844.731, 7.557488, 5.67232, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Candy Cane (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2176, 34696, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7841.243, 1837.17, 7.89402, 2.827433, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Evol Fingers (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2177, 34697, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7842.101, 1846.889, 7.197418, 3.804818, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Warrior-Matic NX-01 (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2178, 34695, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7841.257, 1839.535, 7.677128, 3.141593, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Maxx Avalanche (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2179, 37683, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7842.268, 1843.944, 7.374776, 3.490659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Villa Mook (Area: Gallywix's Villa - Difficulty: 0) (Auras: 76136 - Acidic Sweat)
(@CGUID+2180, 34689, 648, 4737, 4768, 1, 1, 384, 0, 0, 0, -7840.938, 1841.813, 7.512396, 3.682645, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Fizz Lighter (Area: Gallywix's Villa - Difficulty: 0)
(@CGUID+2181, 34763, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 586.5731, 3354.885, -1.804653, 1.381432, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Daggertooth Shark (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast) (possible waypoints or random movement)
(@CGUID+2182, 34763, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 515.5326, 3218.43, -1.408944, 6.260624, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Daggertooth Shark (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast) (possible waypoints or random movement)
(@CGUID+2183, 36719, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 625.5627, 3220.974, 15.81668, 4.157162, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pterrordax Scavenger (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast)
(@CGUID+2184, 36719, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 520.9172, 3231.281, 15.85448, 4.354567, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pterrordax Scavenger (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast)
(@CGUID+2185, 34763, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 569.8334, 3240.514, -1.873459, 1.7295, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Daggertooth Shark (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast) (possible waypoints or random movement)
(@CGUID+2186, 34763, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 511.9438, 3350.394, -1.711968, 4.470571, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Daggertooth Shark (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast) (possible waypoints or random movement)
(@CGUID+2187, 36600, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 534.8264, 3270.589, 0.2805953, 1.675516, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Geargrinder Gizmo (Area: Shipwreck Shore - Difficulty: 0) (Auras: 68327 - Infrared = Infradead: Heat Signature Aura - Humanoid (80%), 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+2188, 34763, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 583.3896, 3286.715, -1.884753, 2.037713, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Daggertooth Shark (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast) (possible waypoints or random movement)
(@CGUID+2189, 34763, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 447.7713, 3284.04, -1.963381, 5.062718, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Daggertooth Shark (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast) (possible waypoints or random movement)
(@CGUID+2190, 36719, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 596.4336, 3156.724, 10.92434, 3.850761, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pterrordax Scavenger (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast)
(@CGUID+2191, 36735, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 804.684, 2997.07, 97.03528, 0.9046282, 120, 10, 0, 0, 0, 1, 0, 0, 0, 15595), -- Teraptor Matriarch (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast) (possible waypoints or random movement)
(@CGUID+2192, 36719, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 679.2274, 3142.475, 31.69419, 6.140682, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pterrordax Scavenger (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast)
(@CGUID+2193, 36719, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 597.3998, 3091.178, 33.60537, 6.018698, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Pterrordax Scavenger (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast)
(@CGUID+2194, 36719, 648, 4720, 4721, 1, 1, 170, 0, 0, 0, 706.1749, 3204.673, 21.66377, 2.724743, 120, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Pterrordax Scavenger (Area: Shipwreck Shore - Difficulty: 0) (Auras: 76354 - Infrared = Infradead: Heat Signature Aura - Beast)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2194;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+0, 0, 0, 50331648, 1, 0, ''), -- Kaja'Cola Balloon
-- (@CGUID+1, 0, 0, 0, 1, 0, '66146'), -- Sudsy Magee - 66146 - Do it Yourself: Cat's Mark - Sudsy
(@CGUID+2, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+3, 0, 0, 0, 1, 375, '76136'), -- Brute Enforcer - 76136 - Acidic Sweat
(@CGUID+4, 0, 0, 0, 1, 375, '76136'), -- Brute Enforcer - 76136 - Acidic Sweat
(@CGUID+5, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+6, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+7, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+8, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
(@CGUID+9, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+10, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+11, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+12, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+13, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+14, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+15, 0, 0, 0, 1, 0, '90317 75773'), -- Bruno Flameretardant - 90317 - Do it Yourself: Cat's Mark - Bruno, 75773 - Burning Weapon
(@CGUID+16, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+17, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+18, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+19, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+20, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+21, 0, 29681, 0, 1, 0, ''), -- Trade Prince Gallywix
(@CGUID+22, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+23, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+24, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+25, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+26, 0, 0, 0, 2, 0, ''), -- Bamm Megabomb
(@CGUID+27, 0, 0, 0, 1, 0, '78273'), -- Maxx Avalanche - 78273 - Flametongue Weapon
(@CGUID+28, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+29, 0, 0, 0, 1, 0, ''), -- Sassy Hardwrench
(@CGUID+30, 0, 0, 8, 1, 0, ''), -- Injured Employee
(@CGUID+31, 0, 0, 0, 1, 0, ''), -- Sister Goldskimmer
(@CGUID+32, 0, 0, 0, 1, 0, ''), -- Candy Cane
(@CGUID+33, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+34, 0, 0, 0, 1, 0, ''), -- Chip Endale
(@CGUID+35, 0, 0, 0, 1, 0, ''), -- Foreman Dampwick
(@CGUID+36, 0, 0, 0, 1, 0, ''), -- Warrior-Matic NX-01
(@CGUID+37, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+38, 0, 0, 8, 1, 0, ''), -- Injured Employee
(@CGUID+39, 0, 0, 0, 1, 0, ''), -- Megs Dreadshredder
(@CGUID+40, 0, 0, 8, 1, 0, ''), -- Injured Employee
(@CGUID+41, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+42, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+43, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+44, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+45, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+46, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+47, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+48, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+49, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+50, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+51, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+52, 0, 0, 1, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+53, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+54, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+55, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
-- (@CGUID+56, 0, 0, 1, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+57, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+58, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+59, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
(@CGUID+60, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+61, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+62, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
(@CGUID+63, 0, 0, 0, 1, 0, ''), -- Black Rat
-- (@CGUID+64, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
-- (@CGUID+65, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+66, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+67, 0, 0, 1, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
-- (@CGUID+68, 0, 0, 1, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+69, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+70, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+71, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
-- (@CGUID+72, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+73, 0, 0, 0, 1, 0, ''), -- Roach
-- (@CGUID+74, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
(@CGUID+75, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+76, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
-- (@CGUID+77, 0, 0, 1, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+78, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+79, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+80, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+81, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+82, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+83, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+84, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+85, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
-- (@CGUID+86, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
-- (@CGUID+87, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+88, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
-- (@CGUID+89, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+90, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+91, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
-- (@CGUID+92, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
-- (@CGUID+93, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
-- (@CGUID+94, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
-- (@CGUID+95, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+96, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+97, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+98, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+99, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+100, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+101, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
-- (@CGUID+102, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
(@CGUID+103, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+104, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+105, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
-- (@CGUID+106, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
-- (@CGUID+107, 0, 0, 0, 1, 0, '45111 62248'), -- Defiant Troll - 45111 - Enrage, 62248 - Sleeping Sleep
(@CGUID+108, 0, 0, 0, 1, 0, ''), -- Troll Slave
(@CGUID+109, 0, 0, 0, 1, 0, ''), -- Troll Slave
-- (@CGUID+110, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+111, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+112, 0, 0, 0, 1, 0, ''), -- Roach
-- (@CGUID+113, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+114, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+115, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+116, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+117, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+118, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+119, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+120, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+121, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+122, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+123, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+124, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+125, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+126, 0, 0, 0, 1, 0, ''), -- Black Rat
-- (@CGUID+127, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+128, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+129, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+130, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+131, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+132, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+133, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+134, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+135, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+136, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+137, 0, 0, 0, 1, 0, ''), -- Tunneling Worm
(@CGUID+138, 0, 0, 0, 1, 0, ''), -- Brett "Coins" McQuid
(@CGUID+139, 0, 0, 0, 1, 0, ''), -- Sally "Salvager" Sandscrew
(@CGUID+140, 0, 0, 0, 1, 0, ''), -- Fizz Lighter
(@CGUID+141, 0, 0, 0, 1, 0, '80264'), -- Slinky Sharpshiv - 80264 - Stealth
(@CGUID+142, 0, 0, 0, 1, 0, '91603'), -- Subject Nine - 91603 - Subject Nine: Gizmo Helmet
(@CGUID+143, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+144, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+145, 0, 0, 0, 1, 0, ''), -- Evol Fingers
(@CGUID+146, 0, 0, 8, 1, 0, ''), -- Injured Employee
(@CGUID+147, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+148, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Hide Body
(@CGUID+149, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+150, 0, 0, 0, 1, 0, ''), -- Assistant Greely
(@CGUID+151, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+152, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+153, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+154, 0, 0, 0, 1, 0, ''), -- Hobart Grapplehammer
(@CGUID+155, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+156, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+157, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+158, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+159, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+160, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+161, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+162, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+163, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+164, 0, 0, 65537, 1, 0, '66405'), -- Izzy - 66405 - Rolling with my Homies: Invisibility 03 - ""Izzy""
(@CGUID+166, 0, 0, 65536, 1, 0, '66404'), -- Gobber - 66404 - Rolling with my Homies: Invisibility 02 - ""Gobber""
(@CGUID+167, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+168, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+169, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+170, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+171, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+172, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+173, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+174, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+175, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+176, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+177, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+178, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+179, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+180, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+181, 0, 0, 65536, 1, 0, '66403'), -- Ace - 66403 - Rolling with my Homies: Invisibility 01 - ""Ace""
(@CGUID+182, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+183, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+184, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+185, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+186, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+187, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+188, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+189, 0, 0, 0, 1, 0, ''), -- Goblin Epic Trike
(@CGUID+190, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+191, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+192, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+193, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+194, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+195, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+196, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+197, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (Not Floating)
(@CGUID+198, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (Not Floating)
(@CGUID+199, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+200, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+201, 0, 0, 0, 1, 0, ''), -- Goblin Supermodel
(@CGUID+202, 0, 0, 0, 1, 0, ''), -- Goblin Supermodel
(@CGUID+203, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+204, 0, 0, 0, 1, 0, ''), -- Goblin Supermodel
(@CGUID+205, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (Not Floating)
(@CGUID+206, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+207, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+208, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+209, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+210, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+211, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+212, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (Not Floating)
(@CGUID+213, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+214, 0, 0, 0, 1, 0, ''), -- Goblin Supermodel
(@CGUID+215, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+216, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+217, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+218, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny (scale x0.01)
(@CGUID+219, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+220, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+221, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+222, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+223, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+224, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+225, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+226, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+227, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+228, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+229, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+230, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+231, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+232, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+233, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+234, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+235, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+236, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+237, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+238, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+239, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+240, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+241, 0, 0, 0, 1, 0, '90818'), -- Missa Spekkies - 90818 - The New You: Cat's Mark - Missa Spekkies
(@CGUID+242, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+243, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+244, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+245, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+246, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+247, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+248, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+249, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+250, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+251, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+252, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+253, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+254, 0, 0, 0, 1, 0, '90814'), -- Gappy Silvertooth - 90814 - The New You: Cat's Mark - Gappy Silvertooth
(@CGUID+255, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+256, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+257, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+258, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+259, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+260, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+261, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+262, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+263, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+264, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+265, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+266, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+267, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+268, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+269, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+270, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+271, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+272, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+273, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+274, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+275, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+276, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+277, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+278, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+279, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+280, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+281, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+282, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+283, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+284, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+285, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+286, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+287, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+288, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+289, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+290, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+291, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+292, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+293, 0, 0, 0, 1, 0, '91298'), -- Kezan Socialite - 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+294, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+295, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+296, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+297, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+298, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+299, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+300, 0, 0, 1, 1, 0, ''), -- Kezan Socialite
(@CGUID+301, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+302, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+303, 0, 0, 0, 1, 0, '91298'), -- Kezan Socialite - 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+304, 0, 0, 0, 1, 0, '91298'), -- Kezan Socialite - 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+305, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+306, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+307, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+308, 0, 0, 0, 1, 0, '91298'), -- Kezan Socialite - 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+309, 0, 0, 50331648, 1, 0, ''), -- Kezan Socialite
(@CGUID+310, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+311, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+312, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+313, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+314, 0, 0, 0, 1, 0, '91298'), -- Kezan Socialite - 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+315, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+316, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+317, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+318, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+319, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+320, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+321, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+322, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+323, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+324, 0, 0, 0, 1, 0, '91298'), -- Kezan Socialite - 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+325, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+326, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+327, 0, 0, 0, 1, 0, ''), -- Neill Penny
(@CGUID+328, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+329, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+330, 0, 0, 0, 1, 0, '91298'), -- Kezan Socialite - 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+331, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+332, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+333, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+334, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+335, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+336, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+337, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+338, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+339, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+340, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+341, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+342, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+343, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+344, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+345, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+346, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+347, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+348, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+349, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+350, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+351, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+352, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+353, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+354, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+355, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+356, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
-- (@CGUID+357, 0, 0, 0, 1, 0, '90318'), -- Frankie Gearslipper - 90318 - Do it Yourself: Cat's Mark - Frankie
(@CGUID+358, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+359, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+360, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
-- (@CGUID+361, 0, 0, 0, 1, 0, '90316 76136'), -- Jack the Hammer - 90316 - Do it Yourself: Cat's Mark - Jack, 76136 - Acidic Sweat
(@CGUID+362, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+363, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+364, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+365, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+366, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+367, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+368, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+369, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+370, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+371, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+372, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+373, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+374, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+375, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+376, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+377, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+378, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+379, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+380, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+381, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+382, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+383, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+384, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+385, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+386, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+387, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+388, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+389, 0, 0, 0, 1, 0, '90816'), -- Szabo - 90816 - The New You: Cat's Mark - Szabo
(@CGUID+390, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+391, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+392, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+393, 0, 0, 0, 1, 0, '29266'), -- Kezan Citizen - 29266 - Permanent Feign Death
(@CGUID+394, 0, 0, 0, 1, 0, '29266'), -- Kezan Citizen - 29266 - Permanent Feign Death
(@CGUID+395, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+396, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+397, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+398, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+399, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+400, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+401, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+402, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+403, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+404, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+405, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+406, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+407, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+408, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+409, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+410, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+411, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+412, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+413, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+414, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+415, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+416, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+417, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+418, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+419, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+420, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+421, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+422, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+423, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+424, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+425, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+426, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+427, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+428, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+429, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+430, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+431, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+432, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+433, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+434, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+435, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+436, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+437, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+438, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+439, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+440, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+441, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+442, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+443, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+444, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+445, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+446, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+447, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+448, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+449, 0, 0, 0, 1, 0, ''), -- FBoK Bank Teller
(@CGUID+450, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+451, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+452, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+453, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+454, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+455, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+456, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+457, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+458, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+459, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+460, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+461, 0, 0, 0, 1, 0, ''), -- FBoK Bank Teller
(@CGUID+462, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+463, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+464, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+465, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+466, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+467, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+468, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+469, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+470, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+471, 0, 0, 0, 1, 0, ''), -- Troll Worker
(@CGUID+472, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+473, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+474, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+475, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+476, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+477, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+478, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+479, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+480, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+481, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+482, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+483, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+484, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+485, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+486, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+487, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+488, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+489, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+490, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+491, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+492, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+493, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+494, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+495, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+496, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+497, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+498, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+499, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+500, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+501, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+502, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+503, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+504, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+505, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+506, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+507, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+508, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+509, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+510, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+511, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+512, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+513, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+514, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+515, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+516, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+517, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+518, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+519, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+520, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+521, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+522, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+523, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+524, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+525, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+526, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+527, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+528, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+529, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+530, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+531, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+532, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+533, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+534, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+535, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+536, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+537, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+538, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+539, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+540, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+541, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+542, 0, 0, 1, 1, 0, ''), -- Kezan Citizen
(@CGUID+543, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+544, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+545, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+546, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+547, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+548, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+549, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+550, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+551, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+552, 0, 0, 1, 1, 0, ''), -- Julia Scrabblewrench
(@CGUID+553, 0, 0, 0, 1, 0, ''), -- Avarua
(@CGUID+554, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+555, 0, 0, 0, 1, 0, ''), -- Atiu
(@CGUID+556, 0, 0, 0, 1, 0, ''), -- Funafuti
(@CGUID+557, 0, 0, 0, 1, 0, ''), -- Rima
(@CGUID+558, 0, 0, 0, 1, 0, ''), -- Mata
(@CGUID+559, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+561, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+562, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+563, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+564, 0, 0, 0, 1, 0, ''), -- Coach Crosscheck
(@CGUID+565, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+566, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+567, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+568, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+569, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+570, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+571, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+572, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+573, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+574, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+575, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+576, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+577, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+578, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+579, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+580, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+581, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+582, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+583, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+584, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+585, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+586, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+587, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+588, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+589, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+590, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+591, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+592, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+593, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+594, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+595, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+596, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+597, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+598, 0, 0, 65536, 1, 0, '90366'), -- Bilgewater Buccaneer - 90366 - Necessary Roughness: Spawned Bilgewater Buccaneer Invisibility
(@CGUID+599, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+600, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+601, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+602, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+603, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+604, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+605, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+606, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+607, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+608, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+609, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+610, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+611, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+612, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+613, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+614, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+615, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+616, 0, 0, 65536, 1, 0, ''), -- Kezan Citizen
(@CGUID+617, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+618, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+619, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+620, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+621, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+622, 0, 0, 50397184, 1, 0, '70086 89476'), -- Fourth And Goal Target - 70086 - Fourth and Goal: Cat's Mark Aura & Invis, 89476 - Cosmetic - Freeze at Stand 0.0 sec Anim Kit
(@CGUID+623, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+624, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+625, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+626, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+627, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+628, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+629, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+630, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+631, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+632, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+633, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+634, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+635, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+636, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+637, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+638, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+639, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+640, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+641, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+642, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+643, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+644, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+645, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+646, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+647, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+648, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+649, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+650, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+651, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+652, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+653, 0, 0, 65536, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+654, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
-- (@CGUID+656, 0, 0, 0, 1, 0, '45111'), -- Defiant Troll - 45111 - Enrage
(@CGUID+657, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+658, 0, 0, 0, 1, 0, '90317 75773'), -- Bruno Flameretardant - 90317 - Do it Yourself: Cat's Mark - Bruno
(@CGUID+659, 0, 0, 0, 1, 0, '66146'), -- Sudsy Magee - 66146 - Do it Yourself: Cat's Mark - Sudsy
(@CGUID+660, 0, 0, 0, 1, 0, '90316'), -- Jack the Hammer - 90316 - Do it Yourself: Cat's Mark - Jack
(@CGUID+661, 0, 0, 0, 1, 0, '90318'), -- Frankie Gearslipper - 90318 - Do it Yourself: Cat's Mark - Frankie
(@CGUID+662, 0, 0, 0, 1, 0, '90636'), -- Kezan Citizen - 90636 - Fourth and Goal: Panicked Citizen Invis
(@CGUID+671, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+672, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+673, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+674, 0, 0, 50331648, 1, 0, ''), -- Kezan Partygoer
(@CGUID+675, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+676, 0, 0, 0, 2, 0, ''), -- Bamm Megabomb
(@CGUID+677, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+678, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+679, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+680, 0, 0, 0, 1, 0, ''), -- Foreman Dampwick
(@CGUID+681, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+682, 0, 0, 0, 1, 0, '46957 55664 75044'), -- Kezan Partygoer - 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket
(@CGUID+683, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+684, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+685, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+686, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+687, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+688, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+689, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+690, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+691, 0, 0, 0, 1, 0, '80264'), -- Slinky Sharpshiv - 80264 - Stealth
(@CGUID+692, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+693, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+694, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+695, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+696, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+697, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+698, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+699, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+700, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+701, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+702, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+703, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+704, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+705, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+706, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Large
(@CGUID+707, 0, 0, 0, 1, 0, '46957 55664 75044'), -- Kezan Partygoer - 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket
(@CGUID+708, 0, 0, 50331648, 1, 0, ''), -- Kezan Partygoer
(@CGUID+709, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+710, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+711, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+712, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+713, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+714, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+715, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+716, 0, 0, 50331648, 1, 0, ''), -- Kezan Partygoer
(@CGUID+717, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+718, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+720, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+721, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+722, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+723, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+724, 0, 0, 0, 1, 0, '46957 55664 75044'), -- Kezan Partygoer - 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket
(@CGUID+725, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+726, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+727, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+728, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+729, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+730, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+731, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+732, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+733, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+734, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+735, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+736, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+737, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+738, 0, 0, 0, 1, 0, '46957 55664 75044'), -- Kezan Partygoer - 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket
(@CGUID+739, 0, 0, 0, 1, 0, ''), -- Gobber
(@CGUID+740, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+741, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+742, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+743, 0, 0, 0, 1, 0, '46957 55664 75044'), -- Kezan Partygoer - 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket
(@CGUID+744, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+745, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+746, 0, 0, 0, 1, 0, '75050'), -- Kezan Partygoer - 75050 - Hors D'oeuvres
(@CGUID+747, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+748, 0, 0, 0, 1, 0, '46957 55664 75044'), -- Kezan Partygoer - 46957 - Cosmetic - Stun (Permanent), 55664 - Cosmetic - Drunken Intoxication (Visual Only), 75044 - Bucket
(@CGUID+750, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+752, 0, 0, 0, 1, 0, ''), -- Ace
(@CGUID+753, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+754, 0, 0, 0, 1, 0, ''), -- Izzy
(@CGUID+755, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+756, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+757, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+758, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+759, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+762, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+763, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+764, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+765, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+767, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+768, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+770, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+771, 0, 0, 0, 1, 0, '46957'), -- Kezan Partygoer - 46957 - Cosmetic - Stun (Permanent)
(@CGUID+772, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+773, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+774, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+775, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+776, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+777, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+778, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+779, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+780, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+781, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+782, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+783, 0, 0, 0, 1, 0, '75048'), -- Kezan Partygoer - 75048 - Fireworks
(@CGUID+784, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+785, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+786, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+787, 0, 0, 0, 1, 0, '75046'), -- Kezan Partygoer - 75046 - Dance
(@CGUID+788, 0, 0, 0, 1, 0, '75042'), -- Kezan Partygoer - 75042 - Bubbly
(@CGUID+789, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+790, 0, 0, 0, 1, 0, ''), -- Sassy Hardwrench
(@CGUID+791, 0, 0, 0, 1, 0, ''), -- Megs Dreadshredder
(@CGUID+792, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+794, 0, 0, 0, 1, 0, ''), -- Sister Goldskimmer
(@CGUID+795, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+796, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+798, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+799, 0, 0, 0, 1, 0, ''), -- Slinky Sharpshiv
(@CGUID+800, 0, 0, 0, 1, 0, ''), -- Evol Fingers
(@CGUID+801, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+803, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+804, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+805, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+806, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+807, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+808, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+809, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+810, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+811, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+812, 0, 0, 0, 1, 0, ''), -- Maxx Avalanche
(@CGUID+813, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+814, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+815, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+816, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+817, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+818, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+819, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+820, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+821, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+822, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+823, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+824, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+825, 0, 0, 0, 1, 0, ''), -- Fizz Lighter
(@CGUID+827, 0, 0, 0, 1, 0, ''), -- Foreman Dampwick
(@CGUID+829, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+832, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+834, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+835, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+836, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+837, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+838, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+839, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+840, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+841, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+842, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+843, 0, 0, 0, 1, 0, ''), -- Ace
(@CGUID+844, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+845, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+846, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+848, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+849, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+850, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+851, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+852, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+853, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+854, 0, 0, 0, 1, 0, '55664'), -- Pirate Party Crasher - 55664 - Cosmetic - Drunken Intoxication (Visual Only)
(@CGUID+855, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+856, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+857, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+859, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+860, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+861, 0, 0, 0, 1, 0, ''), -- Brett "Coins" McQuid
(@CGUID+862, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+863, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+864, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+865, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+866, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+867, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+868, 0, 0, 0, 1, 0, ''), -- Sally "Salvager" Sandscrew
(@CGUID+869, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+870, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+871, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+872, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+873, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+874, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+875, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+876, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+877, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+878, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+879, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+880, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+881, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+882, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+883, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+884, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+885, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+886, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+887, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+888, 0, 0, 0, 1, 0, ''), -- Gobber
(@CGUID+889, 0, 0, 0, 1, 0, ''), -- Izzy
(@CGUID+890, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+892, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+893, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+894, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+895, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+896, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+897, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+898, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+899, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+900, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+901, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+902, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+903, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+905, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+906, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+907, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+908, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+911, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+912, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+913, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+914, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+917, 0, 25871, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+918, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+919, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+920, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+921, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+922, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+923, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+924, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+925, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+926, 0, 0, 0, 1, 0, ''), -- Pirate Party Crasher
(@CGUID+927, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+928, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+929, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+930, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+931, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+932, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+933, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+934, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+936, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+937, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+938, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+939, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+940, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+941, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+942, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+944, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+945, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+946, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+947, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+948, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+949, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+950, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+952, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+953, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+954, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+955, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+956, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+957, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+958, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+960, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+961, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+962, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+963, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+964, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+965, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+966, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+967, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+969, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+970, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+971, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+972, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+973, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+974, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+975, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+976, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+977, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+978, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+979, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+980, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+981, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+982, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+983, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+984, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+985, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+986, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+987, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+988, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+989, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+990, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+991, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+993, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+994, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+995, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+996, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+997, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+998, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+999, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1000, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1001, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1002, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1003, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+1004, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1005, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1006, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1007, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+1009, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1010, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1011, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1012, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1013, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1014, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1015, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1017, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1018, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1019, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1020, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1021, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+1022, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1023, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1025, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1026, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1027, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1028, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1029, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1030, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+1031, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1033, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+1034, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1035, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1036, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1037, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1038, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1039, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1041, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1042, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1043, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1044, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1045, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1046, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+1047, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1049, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1050, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1051, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1052, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1053, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1054, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1055, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1056, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1057, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1058, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1059, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1060, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1061, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1062, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+1063, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1064, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1065, 0, 0, 0, 1, 0, '90909'), -- KTC Waiter - 90909 - Drink Tray
(@CGUID+1067, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1070, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1071, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1072, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1073, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1074, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1075, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1076, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1077, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1078, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1079, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1080, 0, 0, 0, 1, 0, '89842'), -- KTC Waitress - 89842 - Drink Tray
(@CGUID+1081, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1082, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1083, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1084, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1086, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1087, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1088, 0, 0, 0, 1, 0, '29266'), -- KTC Waiter - 29266 - Permanent Feign Death
(@CGUID+1089, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1090, 0, 0, 0, 1, 0, '87259'), -- Pirate Party Crasher - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1091, 0, 0, 0, 1, 0, ''), -- Sassy Hardwrench
(@CGUID+1092, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1093, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1094, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1095, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1096, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1097, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1098, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1099, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1100, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1101, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1102, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1103, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1104, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1105, 0, 0, 0, 1, 0, ''), -- Ace
(@CGUID+1106, 0, 0, 0, 1, 0, ''), -- Izzy
(@CGUID+1107, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1108, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1109, 0, 0, 0, 1, 0, '80264'), -- Slinky Sharpshiv - 80264 - Stealth
(@CGUID+1110, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1111, 0, 0, 0, 1, 0, '87259'), -- Pirate Party Crasher - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1112, 0, 0, 0, 1, 0, ''), -- Gobber
(@CGUID+1113, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1114, 0, 0, 8, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1115, 0, 0, 0, 1, 0, '29266'), -- KTC Waitress - 29266 - Permanent Feign Death
(@CGUID+1116, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1117, 0, 0, 8, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1118, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1119, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1120, 0, 0, 8, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1121, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1122, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1123, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1124, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1125, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1126, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1127, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1128, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1129, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1130, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1131, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1132, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1133, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1134, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1135, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1136, 0, 0, 0, 2, 0, ''), -- Bamm Megabomb
(@CGUID+1137, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1138, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1139, 0, 0, 0, 1, 0, '29266'), -- KTC Waitress - 29266 - Permanent Feign Death
(@CGUID+1140, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1141, 0, 0, 8, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1142, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1143, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1144, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1145, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1146, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1147, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1148, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1149, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1150, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1151, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1152, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1153, 0, 0, 0, 1, 0, '87259'), -- Kezan Partygoer - 87259 - Permanent Feign Death (Drowned Anim Kit)
(@CGUID+1154, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1155, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1156, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1157, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1158, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1159, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1160, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1161, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1162, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1163, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1164, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1165, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1166, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1167, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1168, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1169, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1170, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1171, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1172, 0, 0, 0, 1, 0, '29266'), -- KTC Waiter - 29266 - Permanent Feign Death
(@CGUID+1173, 0, 0, 0, 1, 0, '29266'), -- KTC Waiter - 29266 - Permanent Feign Death
(@CGUID+1174, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1175, 0, 0, 0, 1, 0, '29266'), -- KTC Waitress - 29266 - Permanent Feign Death
(@CGUID+1176, 0, 0, 1, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1177, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1178, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1179, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1180, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1181, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1182, 0, 0, 0, 1, 0, '29266'), -- Pirate Party Crasher - 29266 - Permanent Feign Death
(@CGUID+1183, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1184, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite
(@CGUID+1185, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1186, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1187, 0, 0, 0, 1, 0, ''), -- Kezan Partygoer
(@CGUID+1188, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1189, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1190, 0, 0, 0, 1, 0, '29266'), -- KTC Waiter - 29266 - Permanent Feign Death
(@CGUID+1191, 0, 0, 0, 1, 0, '29266'), -- Kezan Partygoer - 29266 - Permanent Feign Death
(@CGUID+1192, 0, 0, 0, 1, 0, ''), -- Kezan Citizen
(@CGUID+1193, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1194, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1195, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1196, 0, 0, 0, 1, 0, ''), -- Sassy Hardwrench
(@CGUID+1197, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1198, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1199, 0, 0, 0, 2, 0, ''), -- Bamm Megabomb
(@CGUID+1200, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1201, 0, 0, 0, 1, 0, ''), -- Megs Dreadshredder
(@CGUID+1202, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1203, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1204, 0, 0, 0, 1, 0, ''), -- Sister Goldskimmer
(@CGUID+1205, 0, 0, 0, 1, 0, '80264'), -- Slinky Sharpshiv - 80264 - Stealth
(@CGUID+1206, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1207, 0, 0, 0, 1, 0, ''), -- Candy Cane
(@CGUID+1208, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1209, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1210, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1211, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1212, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1213, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1214, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1215, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1216, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1217, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1218, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1219, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1220, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite
(@CGUID+1221, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1222, 0, 0, 0, 1, 0, ''), -- Chip Endale
(@CGUID+1223, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1224, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1225, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1226, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1227, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1228, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1229, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1230, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1231, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1232, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1233, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1234, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1235, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1236, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1237, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1238, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1239, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1240, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1241, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1242, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1243, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1244, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1245, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1246, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Infinite Hide Body
(@CGUID+1247, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1248, 0, 0, 0, 1, 0, '78087'), -- Kezan Partygoer - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1249, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1250, 0, 0, 0, 1, 0, ''), -- Foreman Dampwick
(@CGUID+1251, 0, 0, 0, 1, 0, '80264'), -- Slinky Sharpshiv - 80264 - Stealth
(@CGUID+1252, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny
(@CGUID+1253, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1254, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1255, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1256, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1257, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1258, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1259, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1260, 0, 0, 0, 1, 0, ''), -- Sassy Hardwrench
(@CGUID+1261, 0, 0, 0, 2, 0, ''), -- Bamm Megabomb
(@CGUID+1262, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1263, 0, 0, 0, 1, 0, '29266'), -- Brute Enforcer - 29266 - Permanent Feign Death
(@CGUID+1264, 0, 0, 0, 1, 0, '29266'), -- Brute Enforcer - 29266 - Permanent Feign Death
(@CGUID+1265, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1266, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1267, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1268, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1269, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1270, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1271, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1272, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1273, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1274, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1275, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1276, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1277, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1278, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1279, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1280, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1281, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1282, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1283, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1284, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1285, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1286, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1287, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1288, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1289, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1290, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1291, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1292, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1293, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1294, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1295, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1296, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1297, 0, 0, 65536, 1, 0, '10848'), -- Spirit Healer - 10848 - Shroud of Death
(@CGUID+1298, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1299, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1300, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1301, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1302, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1303, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1304, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1305, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1306, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1307, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1308, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1309, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1310, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1311, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1312, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1313, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1314, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1315, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1316, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1317, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1318, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1319, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1320, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1321, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1322, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1323, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1324, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1325, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1326, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1327, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1328, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1329, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1330, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1331, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1332, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1333, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1334, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1335, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1336, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1337, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1338, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1339, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1340, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1341, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1342, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1343, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1344, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1345, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1346, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1347, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1348, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1349, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1350, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1351, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1352, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1353, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1354, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1355, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1356, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1357, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1358, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1359, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1360, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1361, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1362, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1363, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1364, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1365, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1366, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1367, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1368, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1369, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1370, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1371, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1372, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1373, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1374, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1375, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1376, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1377, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1378, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1379, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1380, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1381, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1382, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1383, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1384, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1385, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1386, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1387, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1388, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1389, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1390, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1391, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1392, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1393, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1394, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1395, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1396, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1397, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1398, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1399, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1400, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1401, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1402, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1403, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1404, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1405, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1406, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1407, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1408, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1409, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1410, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1411, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1412, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1413, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1414, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1415, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1416, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1417, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1418, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1419, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1420, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1421, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1422, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1423, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1424, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1425, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1426, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1427, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1428, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1429, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1430, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1431, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1432, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1433, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1434, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1435, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1436, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1437, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1438, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1439, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1440, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1441, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1442, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1443, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1444, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1445, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1446, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1447, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1448, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1449, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1450, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1451, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1452, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1453, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1454, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1455, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1456, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1457, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1458, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1459, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1460, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1461, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1462, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1463, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1464, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1465, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1466, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1467, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1468, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1469, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1470, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1471, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1472, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1473, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1474, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1475, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1476, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1477, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1478, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1479, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1480, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1481, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1482, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1483, 0, 0, 0, 1, 0, '70112'), -- Goblin Supermodel - 70112 - Permanent Feign Death (On Fire)
(@CGUID+1484, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1485, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1486, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1487, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1488, 0, 0, 0, 1, 0, '70112'), -- Goblin Supermodel - 70112 - Permanent Feign Death (On Fire)
(@CGUID+1489, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1490, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1491, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1492, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1493, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1494, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1495, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1496, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1497, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1498, 0, 0, 0, 1, 0, '70112'), -- Goblin Supermodel - 70112 - Permanent Feign Death (On Fire)
(@CGUID+1499, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1500, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1501, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1502, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1503, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1504, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1505, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1506, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1507, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1508, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1509, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1510, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1511, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1512, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1513, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1514, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1515, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1516, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1517, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1518, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1519, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1520, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1521, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1522, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1523, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1524, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1525, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1526, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1527, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1528, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1529, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1530, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1531, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1532, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1533, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1534, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1535, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1536, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1537, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1538, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1539, 0, 0, 0, 1, 0, ''), -- Keensnout Potbelly
(@CGUID+1540, 0, 0, 0, 1, 0, '75098'), -- Mook Disguise - 75098 - Waltz Right In: Mook Disguise
(@CGUID+1541, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1542, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1543, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1544, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1545, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1546, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1547, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1548, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1549, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1550, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1551, 0, 0, 0, 1, 0, ''), -- Vinny Slapchop
(@CGUID+1552, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1553, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1554, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1555, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1556, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1557, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1558, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1559, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1560, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1561, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1562, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1563, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1564, 0, 0, 0, 1, 0, '29266'), -- FBoK Bank Teller - 29266 - Permanent Feign Death
(@CGUID+1565, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1566, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1567, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1568, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1569, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1570, 0, 0, 0, 1, 0, '29266'), -- FBoK Bank Teller - 29266 - Permanent Feign Death
(@CGUID+1571, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1572, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1573, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1574, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1575, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1576, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1577, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1578, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1579, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1580, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1581, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1582, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1583, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1584, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1585, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1586, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1587, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1588, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1589, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1590, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1591, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1592, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1593, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1594, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1595, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1596, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1597, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1598, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1599, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1600, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1601, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1602, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1603, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1604, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1605, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1606, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1607, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1608, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1609, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1610, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1611, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1612, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1613, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1614, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1615, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1616, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1617, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1618, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1619, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1620, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1621, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1622, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1623, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1624, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1625, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1626, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1627, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1628, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1629, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1630, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1631, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1632, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1633, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1634, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1635, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1636, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1637, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1638, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1639, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1640, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1641, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1642, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1643, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1644, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1645, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1646, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1647, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1648, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1649, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1650, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1651, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1652, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1653, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1654, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1655, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1656, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1657, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1658, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1659, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1660, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1661, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1662, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1663, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1664, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1665, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1666, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1667, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1668, 0, 0, 0, 1, 0, '75098'), -- Mook Disguise - 75098 - Waltz Right In: Mook Disguise
(@CGUID+1669, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1670, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1671, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1672, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1673, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1674, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1675, 0, 0, 0, 1, 0, ''), -- Keensnout Potbelly
(@CGUID+1676, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1677, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+1678, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1679, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1680, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1681, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1682, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1683, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1684, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1685, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1686, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1687, 0, 29681, 0, 1, 0, ''), -- Trade Prince Gallywix
(@CGUID+1688, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1689, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1690, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+1691, 0, 0, 0, 1, 0, ''), -- Kezan Socialite
(@CGUID+1692, 0, 0, 0, 1, 0, '75098'), -- Mook Disguise - 75098 - Waltz Right In: Mook Disguise
(@CGUID+1693, 0, 0, 0, 1, 0, '75098'), -- Mook Disguise - 75098 - Waltz Right In: Mook Disguise
(@CGUID+1694, 0, 0, 0, 1, 0, '75098'), -- Mook Disguise - 75098 - Waltz Right In: Mook Disguise
(@CGUID+1695, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1696, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1697, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1698, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1699, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1700, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1701, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1702, 0, 0, 0, 1, 0, ''), -- Hired Looter
(@CGUID+1703, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1704, 0, 0, 0, 1, 0, '70112'), -- Goblin Supermodel - 70112 - Permanent Feign Death (On Fire)
(@CGUID+1705, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1706, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1707, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1708, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1709, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1710, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1711, 0, 0, 0, 1, 0, ''), -- Rebellious Troll
(@CGUID+1712, 0, 0, 0, 2, 0, ''), -- Bamm Megabomb
(@CGUID+1713, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1714, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1715, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1716, 0, 0, 0, 1, 0, ''), -- Sassy Hardwrench
(@CGUID+1717, 0, 0, 0, 1, 0, ''), -- Megs Dreadshredder
(@CGUID+1718, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1719, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1720, 0, 0, 0, 1, 0, '80264'), -- Slinky Sharpshiv - 80264 - Stealth
(@CGUID+1721, 0, 0, 0, 1, 0, '83470'), -- Training Dummy - 83470 - Arcane Missiles Trainer
(@CGUID+1722, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1723, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1724, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1725, 0, 0, 50331648, 1, 0, ''), -- Kaja'Cola Balloon
(@CGUID+1726, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1727, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1728, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1729, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1730, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1731, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1732, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1733, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1734, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1735, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1736, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1737, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1738, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1739, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1740, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1741, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1742, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1743, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1744, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1745, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1746, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1747, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1748, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1749, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1750, 0, 0, 0, 1, 0, '29266'), -- Rebellious Troll - 29266 - Permanent Feign Death
(@CGUID+1751, 0, 0, 0, 1, 0, '29266'), -- Tunneling Worm - 29266 - Permanent Feign Death
(@CGUID+1752, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1753, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1754, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1755, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1756, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1757, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1758, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1759, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1760, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1761, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1762, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1763, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1764, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1765, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1766, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1767, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1768, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1769, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1770, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1771, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1772, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1773, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1774, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1775, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1776, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1777, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1778, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1779, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1780, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1781, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1782, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1783, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1784, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1785, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1786, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1787, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1788, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1789, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1790, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1791, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1792, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1793, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1794, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1795, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1796, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1797, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1798, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1799, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1800, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1801, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1802, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1803, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1804, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1805, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1806, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1807, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1808, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1809, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1810, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1811, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1812, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1813, 0, 0, 50331648, 1, 0, ''), -- Goblin Trike
(@CGUID+1814, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1815, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1816, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1817, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1818, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1819, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1820, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1821, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1822, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1823, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1824, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1825, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1826, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1827, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1828, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1829, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1830, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1831, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1832, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1833, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1834, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1835, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1836, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1837, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1838, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+1839, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1840, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1841, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1842, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1843, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1844, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1845, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1846, 0, 0, 50331648, 1, 0, ''), -- Kezan Citizen
(@CGUID+1847, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1848, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1849, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1850, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1851, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1852, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1853, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1854, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1855, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1856, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1857, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1858, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1859, 0, 0, 50331648, 1, 0, ''), -- Kezan Citizen
(@CGUID+1860, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1861, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1862, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1863, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1864, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1865, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1866, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1867, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1868, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1869, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1870, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1871, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1872, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1873, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1874, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1875, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1876, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1877, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1878, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1879, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1880, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1881, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1882, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1883, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1884, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1885, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1886, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1887, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1888, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1889, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1890, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1891, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1892, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1893, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1894, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1895, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1896, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1897, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1898, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1899, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1900, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1901, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1902, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1903, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1904, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1905, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1906, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1907, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1908, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+1909, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1910, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1911, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1912, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1913, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1914, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1915, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1916, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1917, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1918, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1919, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1920, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1921, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+1922, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1923, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1924, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1925, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1926, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1927, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1928, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1929, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+1930, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1931, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1932, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1933, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1934, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1935, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1936, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1937, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1938, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1939, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1940, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1941, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1942, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1943, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1944, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1945, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1946, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+1947, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1948, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1949, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1950, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1951, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1952, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1953, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1954, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1955, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1956, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1957, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1958, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1959, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1960, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1961, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1962, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1963, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1964, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1965, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1966, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1967, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1968, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1969, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1970, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+1971, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1972, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1973, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1974, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1975, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1976, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+1977, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1978, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1979, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1980, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1981, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1982, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1983, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1984, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1985, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1986, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1987, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1988, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1989, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1990, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1991, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1992, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1993, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1994, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1995, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1996, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1997, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1998, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+1999, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2000, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2001, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2002, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2003, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+2004, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2005, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2006, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2007, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2008, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2009, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2010, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2011, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2012, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2013, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2014, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2015, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2016, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2017, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2018, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2019, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2020, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2021, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2022, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2023, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2024, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2025, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2026, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2027, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2028, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2029, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2030, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2031, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2032, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2033, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2034, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2035, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2036, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2037, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2038, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2039, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2040, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2041, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2042, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2043, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2044, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2045, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2046, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2047, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2048, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2049, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2050, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2051, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2052, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2053, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2054, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2055, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2056, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2057, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2058, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2059, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2060, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2061, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2062, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2063, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2064, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2065, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2066, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2067, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2068, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2069, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2070, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2071, 0, 0, 0, 1, 0, ''), -- Black Rat
(@CGUID+2072, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2073, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2074, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2075, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2076, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2077, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2078, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2079, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2080, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2081, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2082, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2083, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2084, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2085, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2086, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2087, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2088, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2089, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2090, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+2091, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2092, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2093, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+2094, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2095, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+2096, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2097, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2098, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2099, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+2100, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2101, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2102, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2103, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2104, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2105, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2106, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2107, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2108, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2109, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2110, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2111, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2112, 0, 0, 0, 1, 0, ''), -- Roach
(@CGUID+2113, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2114, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2115, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+2116, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+2117, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2118, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2119, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2120, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+2121, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2122, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2123, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+2124, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+2125, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2126, 0, 0, 0, 1, 0, ''), -- Robo-Chick
(@CGUID+2127, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+2128, 0, 0, 0, 1, 0, ''), -- Rabbot
(@CGUID+2129, 0, 0, 0, 1, 0, ''), -- Rabid Nut Varmint 5000
(@CGUID+2130, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2131, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2132, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2133, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2134, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+2135, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+2136, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2137, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+2138, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+2139, 0, 0, 65536, 1, 0, '70268'), -- 447 Fireworks Bunny - 70268 - 447: Claims Adjuster Quest Invis 1
(@CGUID+2140, 0, 0, 65536, 1, 0, '70268'), -- 447 Fireworks Bunny - 70268 - 447: Claims Adjuster Quest Invis 1
(@CGUID+2141, 0, 0, 65536, 1, 0, '70268'), -- 447 Fireworks Bunny - 70268 - 447: Claims Adjuster Quest Invis 1
(@CGUID+2142, 0, 0, 65536, 1, 0, '70268'), -- 447 Fireworks Bunny - 70268 - 447: Claims Adjuster Quest Invis 1
(@CGUID+2143, 0, 0, 65536, 1, 0, '70268'), -- Claims Adjuster - 70268 - 447: Claims Adjuster Quest Invis 1
(@CGUID+2144, 0, 0, 65536, 1, 0, '70268'), -- 447 Fireworks Bunny - 70268 - 447: Claims Adjuster Quest Invis 1
(@CGUID+2145, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2146, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2147, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2148, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2149, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2150, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2151, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2152, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2153, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2154, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2155, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2156, 0, 0, 0, 1, 0, '78087'), -- Kezan Citizen - 78087 - Cosmetic - Cower (Upper Body) Anim Kit
(@CGUID+2157, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Large
(@CGUID+2158, 0, 0, 0, 1, 0, ''), -- Goblin Hot Rod
(@CGUID+2159, 0, 0, 0, 1, 0, ''), -- Strand Crab
(@CGUID+2160, 0, 0, 0, 1, 0, ''), -- ELM General Purpose Bunny Hide Body
(@CGUID+2161, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2162, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2163, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2164, 0, 29681, 0, 1, 0, ''), -- Trade Prince Gallywix
(@CGUID+2165, 0, 0, 0, 1, 0, ''), -- Megs Dreadshredder
(@CGUID+2166, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2167, 0, 0, 0, 1, 0, ''), -- Chip Endale
(@CGUID+2168, 0, 0, 0, 1, 0, ''), -- Izzy
(@CGUID+2169, 0, 0, 0, 1, 0, ''), -- Bamm Megabomb
(@CGUID+2170, 0, 0, 0, 1, 0, ''), -- Gobber
(@CGUID+2171, 0, 0, 0, 1, 0, ''), -- Ace
(@CGUID+2172, 0, 0, 0, 1, 0, ''), -- Foreman Dampwick
(@CGUID+2173, 0, 0, 0, 1, 0, ''), -- Sassy Hardwrench
(@CGUID+2174, 0, 0, 0, 1, 0, ''), -- Slinky Sharpshiv
(@CGUID+2175, 0, 0, 0, 1, 0, ''), -- Candy Cane
(@CGUID+2176, 0, 0, 0, 1, 0, ''), -- Evol Fingers
(@CGUID+2177, 0, 0, 0, 1, 0, ''), -- Warrior-Matic NX-01
(@CGUID+2178, 0, 0, 0, 1, 0, ''), -- Maxx Avalanche
(@CGUID+2179, 0, 0, 0, 1, 0, '76136'), -- Villa Mook - 76136 - Acidic Sweat
(@CGUID+2180, 0, 0, 0, 1, 0, ''), -- Fizz Lighter
(@CGUID+2181, 0, 0, 0, 1, 0, '76354'), -- Daggertooth Shark - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2182, 0, 0, 0, 1, 0, '76354'), -- Daggertooth Shark - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2183, 0, 0, 50331648, 1, 0, '76354'), -- Pterrordax Scavenger - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2184, 0, 0, 50331648, 1, 0, '76354'), -- Pterrordax Scavenger - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2185, 0, 0, 0, 1, 0, '76354'), -- Daggertooth Shark - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2186, 0, 0, 0, 1, 0, '76354'), -- Daggertooth Shark - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2187, 0, 0, 0, 1, 0, '68327 91298'), -- Geargrinder Gizmo - 68327 - Infrared = Infradead: Heat Signature Aura - Humanoid (80%), 91298 - Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(@CGUID+2188, 0, 0, 0, 1, 0, '76354'), -- Daggertooth Shark - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2189, 0, 0, 0, 1, 0, '76354'), -- Daggertooth Shark - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2190, 0, 0, 50331648, 1, 0, '76354'), -- Pterrordax Scavenger - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2191, 0, 0, 0, 1, 0, '76354'), -- Teraptor Matriarch - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2192, 0, 0, 50331648, 1, 0, '76354'), -- Pterrordax Scavenger - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2193, 0, 0, 50331648, 1, 0, '76354'), -- Pterrordax Scavenger - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
(@CGUID+2194, 0, 0, 50331648, 1, 0, '76354'); -- Pterrordax Scavenger - 76354 - Infrared = Infradead: Heat Signature Aura - Beast
SET @OGUID:=222425;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+769;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 201798, 648, 0, 0, 1, 1, 169, 0, -8506.67, 1344.04, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: -Unknown- - Difficulty: 0)
(@OGUID+1, 201798, 648, 0, 0, 1, 1, 169, 0, -8516.9, 1371.94, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: -Unknown- - Difficulty: 0)
(@OGUID+2, 201798, 648, 0, 0, 1, 1, 169, 0, -8501.29, 1310.49, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: -Unknown- - Difficulty: 0)
(@OGUID+3, 195489, 648, 0, 0, 1, 1, 169, 0, -8482.578, 1257.651, 58.94526, 4.555311, 0, 0, -0.7604055, 0.6494485, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: -Unknown- - Difficulty: 0)
(@OGUID+4, 207627, 648, 0, 0, 1, 1, 169, 0, -8350.158, 1725.259, 69.08379, 1.623156, 0, 0, 0.7253742, 0.6883547, 120, 255, 1, 15595), -- First Bank of Kezan (Area: -Unknown- - Difficulty: 0)
(@OGUID+5, 195489, 648, 0, 0, 1, 1, 169, 0, -8430.045, 1220.238, 46.95245, 0.8377575, 0, 0, 0.4067364, 0.9135455, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: -Unknown- - Difficulty: 0)
(@OGUID+6, 195489, 648, 0, 0, 1, 1, 169, 0, -8487.297, 1229.226, 45.74479, 1.117009, 0, 0, 0.5299187, 0.8480484, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: -Unknown- - Difficulty: 0)
(@OGUID+7, 207238, 648, 0, 0, 1, 1, 169, 0, -8305.66, 1693.637, 50.59976, 1.474801, 0, 0, 0.6723661, 0.7402188, 120, 255, 1, 15595), -- First Bank of Kezan (Area: -Unknown- - Difficulty: 0)
(@OGUID+8, 207245, 648, 0, 0, 1, 1, 169, 0, -8258.689, 1685.625, 52.24165, 4.310966, 0, 0, -0.8338852, 0.5519379, 120, 255, 1, 15595), -- Swindle Street (Area: -Unknown- - Difficulty: 0)
(@OGUID+9, 207244, 648, 0, 0, 1, 1, 169, 0, -8258.646, 1685.767, 55.28058, 1.570796, 0, 0, 0.7071066, 0.7071069, 120, 255, 1, 15595), -- First Bank of Kezan (Area: -Unknown- - Difficulty: 0)
(@OGUID+10, 201798, 648, 0, 0, 1, 1, 169, 0, -8339.45, 1446.13, 46.7236, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: -Unknown- - Difficulty: 0)
(@OGUID+11, 207242, 648, 0, 0, 1, 1, 169, 0, -8109.455, 1687.394, 14.2077, 5.715955, 0, 0, -0.2798281, 0.9600501, 120, 255, 1, 15595), -- Gallywix's Villa (Area: -Unknown- - Difficulty: 0)
(@OGUID+12, 201798, 648, 0, 0, 1, 1, 169, 0, -8260.33, 1420.41, 39.9713, 0.7155849, 0, 0, 0.3502073, 0.9366722, 120, 255, 1, 15595), -- Kaja'Cola (Area: -Unknown- - Difficulty: 0)
(@OGUID+13, 188215, 648, 4737, 4765, 1, 1, 169, 0, -8429.455, 1311.641, 103.4168, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+14, 202594, 648, 4737, 4765, 1, 1, 169, 0, -8416.567, 1342.156, 102.5007, 4.747299, 0, 0, -0.6946573, 0.7193408, 120, 255, 1, 15595), -- Mailbox (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+15, 188215, 648, 4737, 4765, 1, 1, 169, 0, -8402.308, 1314.974, 102.2478, 4.485497, 0, 0, -0.782608, 0.6225148, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+16, 188215, 648, 4737, 4765, 1, 1, 169, 0, -8419.259, 1341.816, 102.9163, 4.642576, 0, 0, -0.7313538, 0.6819983, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+17, 188215, 648, 4737, 4765, 1, 1, 169, 0, -8431.764, 1313.502, 102.9424, 0.8726639, 0, 0, 0.4226179, 0.9063079, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+18, 207253, 648, 4737, 4765, 1, 1, 169, 0, -8426.886, 1372.811, 104.6669, 5.340709, 0, 0, -0.45399, 0.8910068, 120, 255, 1, 15595), -- Goblin BBQ 01 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+19, 207252, 648, 4737, 4765, 1, 1, 169, 0, -8424.507, 1374.672, 110.0497, 4.642576, 0, 0, -0.7313538, 0.6819983, 120, 255, 1, 15595), -- Goblin Hanging Banner 01 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+20, 188215, 648, 4737, 4765, 1, 1, 169, 0, -8425.401, 1347.615, 105.0631, 5.009095, 0, 0, -0.5948229, 0.8038568, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+21, 188215, 648, 4737, 4765, 1, 1, 169, 0, -8415.516, 1321.444, 103.7612, 0.6981314, 0, 0, 0.34202, 0.9396927, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+22, 207261, 648, 4737, 4765, 1, 1, 169, 0, -8425.729, 1368.734, 104.6755, 5.305802, 0, 0, -0.469471, 0.8829479, 120, 255, 1, 15595), -- Goblin Bean Bag 02 (scale x1.5) (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+23, 201798, 648, 4737, 4765, 1, 1, 169, 0, -8460.44, 1374.2, 101.704, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+24, 201798, 648, 4737, 4765, 1, 1, 169, 0, -8472.8, 1305.1, 101.758, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+25, 204125, 648, 4737, 4766, 1, 1, 169, 0, -8497.36, 1173.23, 41.9336, 4.921427, 0.01710081, 0.003994942, -0.6294956, 0.7768056, 120, 255, 1, 15595), -- Anvil (Area: Kaja'mine - Difficulty: 0)
(@OGUID+26, 204124, 648, 4737, 4766, 1, 1, 169, 0, -8494.3, 1162.67, 41.8646, 2.521594, 0.01064777, -0.02142334, 0.9519739, 0.305243, 120, 255, 1, 15595), -- Anvil (Area: Kaja'mine - Difficulty: 0)
(@OGUID+27, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8386.424, 1143.887, 37.02956, 4.468043, 0, 0, -0.7880106, 0.6156617, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+28, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8451.361, 1145.917, 40.0183, 5.916668, 0, 0, -0.1822348, 0.983255, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+29, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8479.295, 1196.295, 44.37675, 1.117009, 0, 0, 0.5299187, 0.8480484, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+30, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8423.308, 1167.413, 41.34653, 0.5934101, 0, 0, 0.2923708, 0.956305, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+31, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8409.457, 1153.372, 38.59242, 3.38594, 0, 0, -0.9925461, 0.12187, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+32, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8445.186, 1187.561, 43.60526, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+33, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8434.361, 1146.823, 43.99479, 2.18166, 0, 0, 0.8870106, 0.4617491, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+34, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8487.91, 1129.688, 41.42708, 1.97222, 0, 0, 0.8338852, 0.5519379, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+35, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8490.979, 1103.957, 42.57484, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+36, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8501.153, 1151.872, 46.10912, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+37, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8516.038, 1176.748, 51.38974, 1.186823, 0, 0, 0.5591927, 0.8290377, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+38, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8360.646, 1152.361, 34.85401, 3.368496, 0, 0, -0.9935713, 0.1132084, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+39, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8375.639, 1119.392, 34.20597, 3.124123, 0, 0, 0.9999619, 0.008734641, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+40, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8355.403, 1134.207, 34.31122, 0.7330382, 0, 0, 0.3583679, 0.9335805, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+41, 207258, 648, 4737, 4766, 1, 1, 169, 0, -8256.02, 1531.859, 41.66555, 4.153885, 0, 0, -0.8746195, 0.4848101, 120, 255, 1, 15595), -- Kajaro Field (Area: Kaja'mine - Difficulty: 0)
(@OGUID+42, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8535.245, 1266.493, 53.76676, 3.804818, 0, 0, -0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+43, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8504.474, 1085.036, 42.44266, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+44, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8518.028, 1236.543, 54.21556, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+45, 207240, 648, 4737, 4766, 1, 1, 169, 0, -8133.62, 1393.41, 12.31211, 2.652894, 0, 0, 0.970295, 0.241925, 120, 255, 1, 15595), -- KTC Headquarters (Area: Kaja'mine - Difficulty: 0)
(@OGUID+46, 203423, 648, 4737, 4766, 1, 1, 169, 0, -8132.597, 1386.155, 33.02825, 1.169212, -0.02128077, 0.02313232, 0.5517273, 0.8334321, 120, 255, 1, 15595), -- Kajaro Field (Area: Kaja'mine - Difficulty: 0)
(@OGUID+47, 203425, 648, 4737, 4766, 1, 1, 169, 0, -8132.587, 1385.934, 29.20991, 1.195393, -0.02158165, 0.0228529, 0.5625896, 0.8261386, 120, 255, 1, 15595), -- Drudgetown (Area: Kaja'mine - Difficulty: 0)
(@OGUID+48, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8561.302, 1265.363, 47.14125, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+49, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8493.207, 1065.073, 41.89872, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+50, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8513.118, 1065.392, 43.02658, 5.689774, 0, 0, -0.2923717, 0.9563047, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+51, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8536.08, 1044.766, 41.41335, 3.124123, 0, 0, 0.9999619, 0.008734641, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+52, 207241, 648, 4737, 4766, 1, 1, 169, 0, -8116.931, 1304.891, 18.43361, 1.439896, 0, 0, 0.6593456, 0.7518399, 120, 255, 1, 15595), -- KTC Headquarters (Area: Kaja'mine - Difficulty: 0)
(@OGUID+53, 207239, 648, 4737, 4766, 1, 1, 169, 0, -8233.861, 1455.17, 39.73429, 2.155482, 0, 0, 0.8808908, 0.4733195, 120, 255, 1, 15595), -- Kajaro Field (Area: Kaja'mine - Difficulty: 0)
(@OGUID+54, 207243, 648, 4737, 4766, 1, 1, 169, 0, -8320.005, 1501.821, 53.22072, 0.9424766, 0, 0, 0.45399, 0.8910068, 120, 255, 1, 15595), -- Drudgetown (Area: Kaja'mine - Difficulty: 0)
(@OGUID+55, 207236, 648, 4737, 4766, 1, 1, 169, 0, -8463.67, 1620.2, 43.48851, 1.919862, 0.005413532, 0.0180521, 0.8189459, 0.5735612, 120, 255, 1, 15595), -- The Pipe (Area: Kaja'mine - Difficulty: 0)
(@OGUID+56, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8587.243, 1272.247, 44.69148, 5.026549, 0, 0, -0.5877848, 0.8090174, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+57, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8602.493, 1254.549, 44.34371, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+58, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8596.716, 1294.533, 41.39431, 0.7853968, 0, 0, 0.3826828, 0.9238798, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+59, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8605.212, 1234.155, 46.42229, 1.221729, 0, 0, 0.573576, 0.8191524, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+60, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8630.111, 1314.462, 36.34804, 2.91469, 0, 0, 0.9935713, 0.1132084, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+61, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8630.161, 1280.016, 39.81154, 0.3490652, 0, 0, 0.1736479, 0.9848078, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+62, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8657.738, 1313.53, 29.70736, 1.989672, 0, 0, 0.8386698, 0.5446402, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+63, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8626.297, 1353.953, 35.42797, 1.012289, 0, 0, 0.4848089, 0.8746201, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+64, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8646.476, 1369.481, 32.18092, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+65, 195489, 648, 4737, 4766, 1, 1, 169, 0, -8673.028, 1352.563, 26.66664, 3.42085, 0, 0, -0.9902678, 0.1391754, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+66, 203420, 648, 4737, 4766, 1, 1, 169, 0, -8217.306, 1572.559, 40.8788, 2.626562, 0.02132463, 0.03262806, 0.9664068, 0.2540444, 120, 255, 1, 15595), -- Kajaro Field (Area: Kaja'mine - Difficulty: 0)
(@OGUID+67, 203422, 648, 4737, 4766, 1, 1, 169, 0, -8217.549, 1572.366, 37.35582, 5.707257, 0.9577103, -0.2820454, -0.04569244, 0.03396539, 120, 255, 1, 15595), -- Drudgetown (Area: Kaja'mine - Difficulty: 0)
(@OGUID+68, 201798, 648, 4737, 4766, 1, 1, 169, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kaja'mine - Difficulty: 0)
(@OGUID+69, 188215, 648, 4737, 4766, 1, 1, 169, 0, -8382.889, 1318.104, 104.0879, 0.9075702, 0, 0, 0.4383707, 0.8987942, 120, 255, 1, 15595), -- Collision PC Size (Area: Kaja'mine - Difficulty: 0)
(@OGUID+70, 188215, 648, 4737, 4766, 1, 1, 169, 0, -8394.614, 1325.67, 102.9184, 2.268925, 0, 0, 0.9063072, 0.4226195, 120, 255, 1, 15595), -- Collision PC Size (Area: Kaja'mine - Difficulty: 0)
(@OGUID+71, 201798, 648, 4737, 4766, 1, 1, 169, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kaja'mine - Difficulty: 0)
(@OGUID+72, 203421, 648, 4737, 4766, 1, 1, 169, 0, -8217.172, 1572.517, 41.55719, 6.274487, -0.007025719, 0.01754379, -0.004223824, 0.9998125, 120, 255, 1, 15595), -- First Bank Of Kezan (Area: Kaja'mine - Difficulty: 0)
(@OGUID+73, 188215, 648, 4737, 4766, 1, 1, 169, 0, -8381.931, 1319.274, 103.9028, 4.06662, 0, 0, -0.8949337, 0.4461992, 120, 255, 1, 15595), -- Collision PC Size (Area: Kaja'mine - Difficulty: 0)
(@OGUID+74, 188215, 648, 4737, 4766, 1, 1, 169, 0, -8399.56, 1346.439, 103.0114, 5.183629, 0, 0, -0.5224981, 0.8526405, 120, 255, 1, 15595), -- Collision PC Size (Area: Kaja'mine - Difficulty: 0)
(@OGUID+75, 207262, 648, 4737, 4766, 1, 1, 169, 0, -8401.964, 1363.563, 104.7212, 3.124123, 0, 0, 0.9999619, 0.008734641, 120, 255, 1, 15595), -- Goblin Bean Bag 04 (scale x1.5) (Area: Kaja'mine - Difficulty: 0)
(@OGUID+76, 207260, 648, 4737, 4766, 1, 1, 169, 0, -8421.207, 1368.615, 104.6644, 3.961899, 0, 0, -0.9170599, 0.3987495, 120, 255, 1, 15595), -- Goblin Bean Bag 01 (scale x1.5) (Area: Kaja'mine - Difficulty: 0)
(@OGUID+77, 201733, 648, 4737, 4766, 1, 1, 169, 0, -8402.41, 1371.37, 104.6859, 3.106652, 0, 0, 0.9998474, 0.01746928, 120, 255, 1, 15595), -- Leaky Stove (Area: Kaja'mine - Difficulty: 0)
(@OGUID+78, 203424, 648, 4737, 4766, 1, 1, 169, 0, -8114.703, 1500.733, 17.201, 6.143589, -0.005863667, 0.01796532, -0.06960487, 0.9973956, 120, 255, 1, 15595), -- Swindle Street (Area: Kaja'mine - Difficulty: 0)
(@OGUID+79, 201734, 648, 4737, 4766, 1, 1, 169, 0, -8404.295, 1363.684, 117.2706, 3.141593, 0, 0, -1, 0, 120, 255, 1, 15595), -- Flammable Bed (Area: Kaja'mine - Difficulty: 0)
(@OGUID+80, 203426, 648, 4737, 4765, 1, 1, 169, 0, -8328.786, 1667.309, 61.44577, 1.24794, -0.07023954, 0.04919052, 0.583972, 0.807232, 120, 255, 1, 15595), -- Drudgetown (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+81, 201735, 648, 4737, 4765, 1, 1, 169, 0, -8420.857, 1372.618, 104.6627, 4.66003, 0, 0, -0.7253742, 0.6883547, 120, 255, 1, 15595), -- Defective Generator (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+82, 201798, 648, 4737, 4765, 1, 1, 169, 0, -8176.97, 1323.55, 29.0534, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+83, 201603, 648, 4737, 4765, 1, 1, 169, 0, -8172.4, 1261.54, 25.0824, 0.7853968, 0, 0, 0.3826828, 0.9238798, 120, 255, 1, 15595), -- Replacement Parts (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+84, 201798, 648, 4737, 4765, 1, 1, 169, 0, -8180.6, 1276.37, 26.9604, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+85, 201603, 648, 4737, 4765, 1, 1, 169, 0, -8182.295, 1320.613, 27.54046, 5.410522, 0, 0, -0.4226179, 0.9063079, 120, 255, 1, 15595), -- Replacement Parts (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+86, 201798, 648, 4737, 0, 1, 1, 169, 0, -8049.07, 1357.74, 5.37202, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: 0 - Difficulty: 0)
(@OGUID+87, 201603, 648, 4737, 0, 1, 1, 169, 0, -8051.167, 1359.068, 5.333935, 6.003934, 0, 0, -0.1391726, 0.9902682, 120, 255, 1, 15595), -- Replacement Parts (Area: 0 - Difficulty: 0)
(@OGUID+88, 201798, 648, 4737, 0, 1, 1, 169, 0, -8049.07, 1357.74, 5.37202, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: 0 - Difficulty: 0)
(@OGUID+89, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8068.35, 1464.13, 9.47734, 1.361356, 0, 0, 0.6293201, 0.7771462, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+90, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8064.47, 1463.38, 12.8306, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+91, 201591, 648, 4737, 4767, 1, 1, 169, 0, -8074.304, 1494.684, 8.831218, 4.136433, 0, 0, -0.8788166, 0.4771597, 120, 255, 1, 15595), -- Disco Ball (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+92, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8029.42, 1491.578, 10.6867, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+93, 207246, 648, 4737, 4767, 1, 1, 169, 0, -8308.056, 1783.644, 49.06589, 3.316144, 0, 0, -0.9961939, 0.08716504, 120, 255, 1, 15595), -- First Bank of Kezan (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+94, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8049.069, 1495.84, 11.31489, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+95, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8065.587, 1517.957, 9.112565, 4.049168, 0, 0, -0.8987932, 0.4383728, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+96, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8050.52, 1495.86, 10.0882, 3.351047, 0, 0, -0.9945211, 0.1045355, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+97, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8122.08, 1554.29, 11.031, 1.186823, 0, 0, 0.5591927, 0.8290377, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+98, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8008.03, 1545.59, 1.6474, 3.839725, 0, 0, -0.9396925, 0.3420205, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+99, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8009.467, 1544.446, 1.750096, 0.9599299, 0, 0, 0.4617481, 0.8870111, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+100, 207237, 648, 4737, 4767, 1, 1, 169, 0, -8340.389, 1785.479, 43.15758, 3.499387, -0.001303196, 0.02583885, -0.983696, 0.1779686, 120, 255, 1, 15595), -- Drudgetown (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+101, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8037.667, 1587.675, 2.741817, 5.061456, 0, 0, -0.573576, 0.8191524, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+102, 188215, 648, 4737, 4767, 1, 1, 169, 0, -8143.082, 1583.526, 16.86593, 4.572764, 0, 0, -0.7547092, 0.6560594, 120, 255, 1, 15595), -- Collision PC Size (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+103, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8005.349, 1665.547, 2.75316, 5.061456, 0, 0, -0.573576, 0.8191524, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+104, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8113.509, 1652.41, 11.27472, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+105, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8142.97, 1620.96, 15.0279, 1.53589, 0, 0, 0.6946583, 0.7193398, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+106, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8129.49, 1631.65, 14.9989, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+107, 188215, 648, 4737, 4772, 1, 1, 169, 0, -8142.792, 1658.632, 16.65594, 4.956738, 0, 0, -0.6156607, 0.7880114, 120, 255, 1, 15595), -- Collision PC Size (Area: The Slick - Difficulty: 0)
(@OGUID+108, 201798, 648, 4737, 4772, 1, 1, 169, 0, -8133.31, 1630.79, 15.6747, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Slick - Difficulty: 0)
(@OGUID+109, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8145.05, 1659.32, 15.9256, 5.009095, 0, 0, -0.5948229, 0.8038568, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+110, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8000.444, 1709.207, 2.53732, 0.3665176, 0, 0, 0.1822348, 0.983255, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+111, 201798, 648, 4737, 4772, 1, 1, 169, 0, -7994.57, 1707.53, 2.11572, 4.32842, 0, 0, -0.8290367, 0.5591941, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Slick - Difficulty: 0)
(@OGUID+112, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8124.764, 1748.917, 21.13151, 5.061456, 0, 0, -0.573576, 0.8191524, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+113, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8175.702, 1781.762, 30.18302, 2.33874, 0, 0, 0.9205046, 0.3907318, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+114, 201798, 648, 4737, 4768, 1, 1, 169, 0, -8040.44, 1864.26, 52.5156, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+115, 201798, 648, 4737, 4768, 1, 1, 169, 0, -8128.6, 1903.54, 55.4167, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+116, 201798, 648, 4737, 4768, 1, 1, 169, 0, -8018.01, 1885.35, 52.5155, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+117, 195522, 648, 4737, 4768, 1, 1, 169, 0, -8148.203, 1903.42, 69.76933, 5.951575, 0, 0, -0.1650467, 0.9862857, 120, 255, 1, 15595), -- Maldy's Falcon (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+118, 195523, 648, 4737, 4768, 1, 1, 169, 0, -8048.059, 1955.545, 54.96981, 4.694937, 0, 0, -0.7132502, 0.7009096, 120, 255, 1, 15595), -- The Goblin Lisa (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+119, 195524, 648, 4737, 4768, 1, 1, 169, 0, -8007.021, 1858.755, 54.21757, 0.1047193, 0, 0, 0.05233574, 0.9986296, 120, 255, 1, 15595), -- The Ultimate Bomb (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+120, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8173.37, 1662.06, 24.2815, 4.625124, 0, 0, -0.737277, 0.6755905, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+121, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8171.65, 1663.96, 25.5727, 0.5934101, 0, 0, 0.2923708, 0.956305, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+122, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8181.34, 1657.91, 24.9972, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+123, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8228.66, 1706.81, 44.5952, 4.101525, 0, 0, -0.8870106, 0.4617491, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+124, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8286.47, 1659.76, 50.7752, 2.303831, 0, 0, 0.9135447, 0.4067384, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+125, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8265.98, 1733.23, 45.1925, 0.1919852, 0, 0, 0.09584522, 0.9953963, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+126, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8285.41, 1666.72, 50.7429, 3.38594, 0, 0, -0.9925461, 0.12187, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+127, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8274.507, 1697.104, 47.87308, 4.537859, 0, 0, -0.7660437, 0.6427886, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+128, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8270.61, 1747, 45.1715, 5.375615, 0, 0, -0.4383707, 0.8987942, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+129, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8301.79, 1669.87, 51.6481, 0.802851, 0, 0, 0.3907309, 0.920505, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+130, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8245.031, 1726.295, 44.70731, 5.323256, 0, 0, -0.4617481, 0.8870111, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+131, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8293.58, 1662.63, 51.6436, 5.323256, 0, 0, -0.4617481, 0.8870111, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+132, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8337.65, 1717.94, 50.7271, 0.5759573, 0, 0, 0.2840147, 0.9588199, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+133, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8242.58, 1726.86, 44.7803, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+134, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8343.62, 1729, 51.8053, 5.777041, 0, 0, -0.2503796, 0.9681478, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+135, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8227.778, 1637.609, 35.2783, 5.375615, 0, 0, -0.4383707, 0.8987942, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+136, 207235, 648, 4737, 4767, 1, 1, 169, 0, -8350.841, 1337.391, 91.37822, 2.556902, 0.1312761, 0.02041626, 0.9510584, 0.2789941, 120, 255, 1, 15595), -- KTC Headquarters (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+137, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8232.21, 1633.07, 34.6871, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+138, 188215, 648, 4737, 4767, 1, 1, 169, 0, -8231.323, 1620.245, 34.62507, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Collision PC Size (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+139, 201798, 648, 4737, 4773, 1, 1, 169, 0, -8175.11, 1588.12, 24.8921, 2.635444, 0, 0, 0.9681473, 0.2503814, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+140, 201603, 648, 4737, 4773, 1, 1, 169, 0, -8234.41, 1581.26, 33.5483, 0.6108634, 0, 0, 0.300705, 0.9537172, 120, 255, 1, 15595), -- Replacement Parts (Area: Swindle Street - Difficulty: 0)
(@OGUID+141, 201798, 648, 4737, 4773, 1, 1, 169, 0, -8237.16, 1592.51, 34.2934, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+142, 201603, 648, 4737, 4773, 1, 1, 169, 0, -8195.448, 1622.405, 28.73305, 1.308995, 0, 0, 0.6087608, 0.7933538, 120, 255, 1, 15595), -- Replacement Parts (Area: Swindle Street - Difficulty: 0)
(@OGUID+143, 207760, 648, 4737, 4773, 1, 1, 169, 0, -8425.566, 1347.729, 104.6624, 2.321287, 0, 0, 0.9170599, 0.3987495, 120, 255, 1, 15595), -- Sister Goldskimmer's Gold Pile (Area: Swindle Street - Difficulty: 0)
(@OGUID+144, 207756, 648, 4737, 4773, 1, 1, 169, 0, -8402.231, 1314.929, 100.7437, 1.500983, 0, 0, 0.6819983, 0.7313538, 120, 255, 1, 15595), -- Dampwick's Barrel (Area: Swindle Street - Difficulty: 0)
(@OGUID+145, 201798, 648, 4737, 4773, 1, 1, 169, 0, -8179.73, 1582.63, 25.0378, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+146, 207757, 648, 4737, 4773, 1, 1, 169, 0, -8419.228, 1341.884, 102.4896, 4.694937, 0, 0, -0.7132502, 0.7009096, 120, 255, 1, 15595), -- Megs Dreadshredder's Bean Bag (Area: Swindle Street - Difficulty: 0)
(@OGUID+147, 201603, 648, 4737, 4773, 1, 1, 169, 0, -8186.39, 1545.91, 31.1462, 0.1745321, 0, 0, 0.08715534, 0.9961947, 120, 255, 1, 15595), -- Replacement Parts (Area: Swindle Street - Difficulty: 0)
(@OGUID+148, 201603, 648, 4737, 4773, 1, 1, 169, 0, -8221.86, 1523.3, 40.567, 4.01426, 0, 0, -0.9063072, 0.4226195, 120, 255, 1, 15595), -- Replacement Parts (Area: Swindle Street - Difficulty: 0)
(@OGUID+149, 201603, 648, 4737, 4773, 1, 1, 169, 0, -8204.99, 1549.47, 31.7765, 1.099556, 0, 0, 0.5224981, 0.8526405, 120, 255, 1, 15595), -- Replacement Parts (Area: Swindle Street - Difficulty: 0)
(@OGUID+150, 201798, 648, 4737, 4773, 1, 1, 169, 0, -8226.97, 1506.95, 40.6273, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+151, 201603, 648, 4737, 4773, 1, 1, 169, 0, -8294.616, 1549.47, 48.04599, 5.288348, 0, 0, -0.4771585, 0.8788173, 120, 255, 1, 15595), -- Replacement Parts (Area: Swindle Street - Difficulty: 0)
(@OGUID+152, 195525, 648, 4737, 4767, 1, 1, 169, 0, -8364.422, 1731.951, 39.94388, 0.1396245, 0, 0, 0.06975555, 0.9975641, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+153, 195525, 648, 4737, 4767, 1, 1, 169, 0, -8373.446, 1730.269, 39.93898, 0.1745321, 0, 0, 0.08715534, 0.9961947, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+154, 195525, 648, 4737, 4767, 1, 1, 169, 0, -8364.021, 1717.573, 39.80462, 3.246347, 0, 0, -0.9986286, 0.05235322, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+155, 195525, 648, 4737, 4767, 1, 1, 169, 0, -8358.676, 1717.519, 50.95889, 1.692969, 0, 0, 0.7489557, 0.6626201, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+156, 195525, 648, 4737, 4767, 1, 1, 169, 0, -8358.611, 1732.385, 50.9572, 1.692969, 0, 0, 0.7489557, 0.6626201, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+157, 195525, 648, 4737, 4840, 1, 1, 169, 0, -8373.045, 1720.226, 39.93892, 3.263772, 0, 0, -0.9981346, 0.06105176, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: The Pipe - Difficulty: 0)
(@OGUID+158, 201798, 648, 4737, 4840, 1, 1, 169, 0, -8376.63, 1724.52, 40.8208, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Pipe - Difficulty: 0)
(@OGUID+159, 201603, 648, 4737, 4840, 1, 1, 169, 0, -8396.239, 1691.557, 49.94482, 4.502952, 0, 0, -0.7771454, 0.6293211, 120, 255, 1, 15595), -- Replacement Parts (Area: The Pipe - Difficulty: 0)
(@OGUID+160, 201798, 648, 4737, 4840, 1, 1, 169, 0, -8394.341, 1688.87, 49.86174, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Pipe - Difficulty: 0)
(@OGUID+161, 201603, 648, 4737, 4840, 1, 1, 169, 0, -8434.768, 1652.668, 45.62479, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: The Pipe - Difficulty: 0)
(@OGUID+162, 201798, 648, 4737, 4840, 1, 1, 169, 0, -8431.93, 1653.76, 45.7783, 3.892087, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Pipe - Difficulty: 0)
(@OGUID+163, 201798, 648, 4737, 4771, 1, 1, 169, 0, -8486.51, 1591.25, 47.3394, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+164, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8483.849, 1583.247, 45.8385, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+165, 201798, 648, 4737, 4771, 1, 1, 169, 0, -8468.48, 1567.79, 47.3571, 5.480334, 0, 0, -0.3907309, 0.920505, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+166, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8464.67, 1593.18, 45.2483, 0.8726639, 0, 0, 0.4226179, 0.9063079, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+167, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8447.522, 1588.637, 43.7086, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+168, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8485.107, 1612.504, 46.84386, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+169, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8435.8, 1620.26, 41.1154, 3.525572, 0, 0, -0.9816265, 0.1908124, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+170, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8465.797, 1538.526, 51.88137, 0.4537851, 0, 0, 0.2249508, 0.9743701, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+171, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8418.18, 1519.76, 50.7413, 0.5235979, 0, 0, 0.2588186, 0.9659259, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+172, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8401.6, 1518.33, 50.7504, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+173, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8402.31, 1565.76, 42.5794, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+174, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8362.368, 1648.847, 49.48537, 3.700105, 0, 0, -0.9612608, 0.2756405, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+175, 201798, 648, 4737, 4771, 1, 1, 169, 0, -8336.12, 1582.26, 50.8842, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+176, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8336.616, 1579.865, 50.48424, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+177, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8364.328, 1627.269, 49.54995, 2.460913, 0, 0, 0.9426413, 0.3338076, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+178, 201798, 648, 4737, 4771, 1, 1, 169, 0, -8362.05, 1629.85, 49.5499, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+179, 201798, 648, 4737, 4771, 1, 1, 169, 0, -8400.91, 1516.62, 51.4958, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+180, 201603, 648, 4737, 4771, 1, 1, 169, 0, -8352.576, 1603.661, 50.23549, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Drudgetown - Difficulty: 0)
(@OGUID+181, 201798, 648, 4737, 4771, 1, 1, 169, 0, -8311.52, 1553.15, 48.9103, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+182, 201798, 648, 4737, 4772, 1, 1, 169, 0, -8040.54, 1201.39, 2.80035, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Slick - Difficulty: 0)
(@OGUID+183, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8039.344, 1206.434, 2.8057, 0.122173, 0, 0, 0.06104851, 0.9981348, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+184, 201603, 648, 4737, 4772, 1, 1, 169, 0, -8055.749, 1165.335, 2.861948, 3.47321, 0, 0, -0.9862852, 0.1650499, 120, 255, 1, 15595), -- Replacement Parts (Area: The Slick - Difficulty: 0)
(@OGUID+185, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8262.29, 1468.74, 43.2355, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+186, 188215, 648, 4737, 4767, 1, 1, 169, 0, -8250.009, 1469.979, 42.75886, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Collision PC Size (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+187, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8286.16, 1499.72, 44.955, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+188, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8278.5, 1468.89, 44.0705, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+189, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8273, 1467.22, 42.7515, 5.009095, 0, 0, -0.5948229, 0.8038568, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+190, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8353.33, 1488.43, 47.3447, 4.572764, 0, 0, -0.7547092, 0.6560594, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+191, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8251.46, 1470.42, 41.4199, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+192, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8299.34, 1504.9, 46.0026, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+193, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8264.92, 1500.9, 44.6297, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+194, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8305.22, 1505.73, 44.9375, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+195, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8347.616, 1458.766, 47.65825, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+196, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8378.45, 1508.24, 46.2612, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+197, 201603, 648, 4737, 4822, 1, 1, 169, 0, -8221.86, 1523.3, 40.567, 4.01426, 0, 0, -0.9063072, 0.4226195, 120, 255, 1, 15595), -- Replacement Parts (Area: Kajaro Field - Difficulty: 0)
(@OGUID+198, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8126.69, 1587.68, 12.7065, 4.694937, 0, 0, -0.7132502, 0.7009096, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+199, 201603, 648, 4737, 4765, 1, 1, 169, 0, -8361.1, 1464.16, 47.8511, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Replacement Parts (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+200, 201603, 648, 4737, 4767, 1, 1, 169, 0, -8397.29, 1531.96, 50.3405, 1.186823, 0, 0, 0.5591927, 0.8290377, 120, 255, 1, 15595), -- Replacement Parts (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+201, 201798, 648, 4737, 4767, 1, 1, 169, 0, -8251.46, 1470.42, 41.4199, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+202, 188215, 648, 4737, 4765, 1, 1, 379, 0, -8429.521, 1311.611, 103.3472, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+203, 188215, 648, 4737, 4765, 1, 1, 379, 0, -8402.283, 1314.986, 102.25, 4.485497, 0, 0, -0.782608, 0.6225148, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+204, 201798, 648, 4737, 4765, 1, 1, 379, 0, -8460.44, 1374.2, 101.704, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+205, 201798, 648, 4737, 4765, 1, 1, 379, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+206, 201798, 648, 4737, 4765, 1, 1, 379, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+207, 201798, 648, 4737, 4765, 1, 1, 379, 0, -8516.9, 1371.94, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+208, 201798, 648, 4737, 4765, 1, 1, 379, 0, -8472.8, 1305.1, 101.758, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+209, 201798, 648, 4737, 4765, 1, 1, 379, 0, -8506.67, 1344.04, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+210, 201798, 648, 4737, 4765, 1, 1, 379, 0, -8501.29, 1310.49, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
-- (@OGUID+211, 195373, 648, 4737, 4765, 1, 1, 379, 0, -8452.844, 1297.585, 102.3022, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Disco Ball (Area: KTC Headquarters - Difficulty: 0)
-- (@OGUID+212, 195373, 648, 4737, 4765, 1, 1, 379, 0, -8451.338, 1314.556, 102.0717, 3.769912, 0, 0, -0.9510565, 0.3090171, 120, 255, 1, 15595), -- Disco Ball (Area: KTC Headquarters - Difficulty: 0) - !!! might be temporary spawn !!!
(@OGUID+213, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8434.451, 1334.655, 102.8931, 5.462882, 0, 0, -0.3987484, 0.9170604, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+214, 207762, 648, 4737, 4765, 1, 1, 380, 0, -8434.436, 1334.74, 102.1569, 5.372694, -0.007871151, -0.02491379, -0.4394426, 0.8978906, 120, 255, 1, 15595), -- Slinky Sharpshiv's Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+215, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8399.567, 1346.457, 103.0351, 5.183629, 0, 0, -0.5224981, 0.8526405, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+216, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8425.399, 1347.554, 105.0628, 5.009095, 0, 0, -0.5948229, 0.8038568, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+217, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8460.44, 1374.2, 101.704, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+218, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8394.598, 1325.667, 102.9202, 2.33874, 0, 0, 0.9205046, 0.3907318, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+219, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8415.52, 1321.422, 103.7612, 0.6981314, 0, 0, 0.34202, 0.9396927, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+220, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8402.283, 1314.936, 102.2503, 1.53589, 0, 0, 0.6946583, 0.7193398, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+221, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8429.573, 1311.599, 103.3375, 0.8203033, 0, 0, 0.3987484, 0.9170604, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+222, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+223, 195401, 648, 4737, 4765, 1, 1, 380, 0, -8452.846, 1297.571, 102.3032, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Disco Ball (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+224, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8506.67, 1344.04, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+225, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8472.8, 1305.1, 101.758, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+226, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8381.933, 1319.307, 103.9029, 2.286379, 0, 0, 0.9099607, 0.4146944, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+227, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8516.9, 1371.94, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+228, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+229, 188215, 648, 4737, 4765, 1, 1, 380, 0, -8382.889, 1318.104, 104.0879, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+230, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8501.29, 1310.49, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+231, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8339.45, 1446.13, 46.7236, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+232, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8260.33, 1420.41, 39.9713, 0.7155849, 0, 0, 0.3502073, 0.9366722, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+233, 201798, 648, 4737, 4765, 1, 1, 380, 0, -8353.33, 1488.43, 47.3447, 4.572764, 0, 0, -0.7547092, 0.6560594, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+234, 201798, 648, 4737, 4765, 1, 1, 381, 0, -8460.44, 1374.2, 101.704, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+235, 201798, 648, 4737, 4765, 1, 1, 381, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+236, 188215, 648, 4737, 4765, 1, 1, 381, 0, -8429.522, 1311.616, 103.3569, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+237, 201798, 648, 4737, 4765, 1, 1, 381, 0, -8472.8, 1305.1, 101.758, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+238, 201798, 648, 4737, 4765, 1, 1, 381, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+239, 201798, 648, 4737, 4765, 1, 1, 381, 0, -8506.67, 1344.04, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+240, 201798, 648, 4737, 4765, 1, 1, 381, 0, -8501.29, 1310.49, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+241, 201798, 648, 4737, 4765, 1, 1, 381, 0, -8516.9, 1371.94, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+242, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8394.826, 1407.915, 123.692, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+243, 207761, 648, 4737, 4765, 1, 1, 382, 0, -8414.005, 1329.163, 102.2103, 4.956738, 0, 0, -0.6156607, 0.7880114, 120, 255, 1, 15595), -- Sister Goldskimmer's Gold Pile (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+244, 188215, 648, 4737, 4765, 1, 1, 382, 0, -8435.328, 1316.877, 102.5489, 0.9599299, 0, 0, 0.4617481, 0.8870111, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+245, 188215, 648, 4737, 4765, 1, 1, 382, 0, -8429.521, 1311.62, 103.3532, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+246, 207759, 648, 4737, 4765, 1, 1, 382, 0, -8424.816, 1322.345, 102.7871, 3.141616, -0.00001478195, -0.9997778, -0.02104282, 0.001244878, 120, 255, 1, 15595), -- Sassy's Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+247, 202850, 648, 4737, 4765, 1, 1, 382, 0, -8422.514, 1325.675, 101.9162, 4.677484, 0, 0, -0.7193394, 0.6946588, 120, 255, 1, 15595), -- Gasbot Control Panel (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+248, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8450.426, 1363.882, 120.385, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+249, 188215, 648, 4737, 4765, 1, 1, 382, 0, -8414.114, 1329.385, 102.5629, 2.129301, 0, 0, 0.8746195, 0.4848101, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+250, 207758, 648, 4737, 4765, 1, 1, 382, 0, -8435.342, 1316.943, 102.1328, 1.055924, 0, 0, 0.5037737, 0.8638357, 120, 255, 1, 15595), -- Megs Dreadshredder's Beanbag (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+251, 188215, 648, 4737, 4765, 1, 1, 382, 0, -8424.748, 1322.33, 102.8459, 1.553341, 0, 0, 0.7009087, 0.7132511, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+252, 201798, 648, 4737, 4765, 1, 1, 382, 0, -8460.44, 1374.2, 101.704, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+253, 201798, 648, 4737, 4765, 1, 1, 382, 0, -8506.67, 1344.04, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+254, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8429.826, 1302.184, 132.5716, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+255, 201798, 648, 4737, 4765, 1, 1, 382, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+256, 201798, 648, 4737, 4765, 1, 1, 382, 0, -8472.8, 1305.1, 101.758, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+257, 201798, 648, 4737, 4765, 1, 1, 382, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+258, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8492.814, 1293.007, 102.4367, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+259, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8523.011, 1296.663, 126.489, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+260, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8389.096, 1170.748, 84.73647, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+261, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8257.882, 1211.986, 65.10143, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+262, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8546.201, 1597.819, 116.0115, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+263, 201720, 648, 4737, 4765, 1, 1, 382, 0, -8488.354, 1392.313, 127.1468, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+264, 201798, 648, 4737, 4765, 1, 1, 382, 0, -8501.29, 1310.49, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+265, 201798, 648, 4737, 4765, 1, 1, 382, 0, -8516.9, 1371.94, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+266, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8450.248, 1294.467, 106.6042, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+267, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8489.957, 1292.481, 119.6125, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+268, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8385.151, 1409.314, 119.6607, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+269, 201720, 648, 4737, 4765, 1, 1, 382, 0, -8104.703, 1481.514, 10.10553, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+270, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8068.46, 1485.045, 11.92525, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+271, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8070.41, 1490.326, 12.82507, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+272, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8086.213, 1494.139, 8.831218, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+273, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8486.098, 1666.373, 55.46402, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+274, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8545.853, 1634.297, 115.9994, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+275, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8102.509, 1399.368, 44.66325, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+276, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8108.663, 1349.641, 19.92092, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+277, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8491.361, 1748.087, 57.0923, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+278, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8481.531, 1713.448, 50.68074, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+279, 201720, 648, 4737, 4765, 1, 1, 382, 0, -8342.433, 1701.754, 80.66709, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+280, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8113.526, 1287.757, 54.29553, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+281, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8107.257, 1349.705, 44.60596, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+282, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8486.75, 1674.087, 46.41031, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+283, 201720, 648, 4737, 4765, 1, 1, 382, 0, -8089.944, 1559.194, 41.18849, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+284, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8063.596, 1499.694, 13.00662, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+285, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8072.396, 1518.83, 9.268525, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+286, 201719, 648, 4737, 4765, 1, 1, 382, 0, -8342.724, 1752.201, 80.73012, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+287, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8149.181, 1637.688, 31.57202, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+288, 201720, 648, 4737, 4765, 1, 1, 382, 0, -8536.552, 1749.311, 42.4128, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+289, 201721, 648, 4737, 4765, 1, 1, 382, 0, -8056.337, 1518.045, 24.53892, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+290, 188215, 648, 4737, 4765, 1, 1, 383, 0, -8429.518, 1311.618, 103.3462, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+291, 188215, 648, 4737, 4765, 1, 1, 383, 0, -8431.545, 1276.95, 103.5104, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+292, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8506.67, 1344.04, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+293, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8460.44, 1374.2, 101.704, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+294, 188215, 648, 4737, 4765, 1, 1, 383, 0, -8424.748, 1322.33, 102.8459, 1.553341, 0, 0, 0.7009087, 0.7132511, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+295, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+296, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8472.8, 1305.1, 101.758, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+297, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8501.29, 1310.49, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+298, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8381.276, 1318.373, 104.6633, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+299, 195488, 648, 4737, 4765, 1, 1, 383, 0, -8482.573, 1257.651, 58.94526, 4.555311, 0, 0, -0.7604055, 0.6494485, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+300, 195488, 648, 4737, 4765, 1, 1, 383, 0, -8430.052, 1220.238, 46.95063, 0.8203033, 0, 0, 0.3987484, 0.9170604, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+301, 201719, 648, 4737, 4765, 1, 1, 383, 0, -8029.721, 1463.892, 9.18588, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+302, 201720, 648, 4737, 4765, 1, 1, 383, 0, -8045.707, 1488.733, 9.743194, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+303, 195449, 648, 4737, 4765, 1, 1, 383, 0, -8358.676, 1717.519, 50.95889, 1.692969, 0, 0, 0.7489557, 0.6626201, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+304, 195449, 648, 4737, 4765, 1, 1, 383, 0, -8364.011, 1717.589, 39.80497, 3.281239, 0, 0, -0.9975634, 0.06976615, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+305, 195449, 648, 4737, 4765, 1, 1, 383, 0, -8373.045, 1720.215, 39.93889, 3.228859, 0, 0, -0.9990482, 0.04361926, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+306, 195449, 648, 4737, 4765, 1, 1, 383, 0, -8373.446, 1730.3, 39.93903, 0.157079, 0, 0, 0.07845879, 0.9969174, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+307, 195488, 648, 4737, 4765, 1, 1, 383, 0, -8518.035, 1236.401, 54.19437, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+308, 195488, 648, 4737, 4765, 1, 1, 383, 0, -8487.304, 1229.227, 45.7357, 1.117009, 0, 0, 0.5299187, 0.8480484, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+309, 195488, 648, 4737, 4765, 1, 1, 383, 0, -8479.373, 1196.333, 44.35003, 1.239183, 0, 0, 0.5807028, 0.8141156, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+310, 195488, 648, 4737, 4765, 1, 1, 383, 0, -8445.189, 1187.543, 43.60566, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+311, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8423.317, 1167.398, 41.34667, 0.5934101, 0, 0, 0.2923708, 0.956305, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+312, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8409.486, 1153.363, 38.59461, 3.38594, 0, 0, -0.9925461, 0.12187, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+313, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8434.339, 1146.821, 43.98102, 2.18166, 0, 0, 0.8870106, 0.4617491, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+314, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8386.436, 1143.891, 37.01731, 4.485497, 0, 0, -0.782608, 0.6225148, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+315, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8501.17, 1151.924, 46.10912, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+316, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8451.372, 1145.927, 39.99265, 5.916668, 0, 0, -0.1822348, 0.983255, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+317, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8516.04, 1176.738, 51.38974, 1.186823, 0, 0, 0.5591927, 0.8290377, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+318, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8360.641, 1152.365, 34.85747, 3.368496, 0, 0, -0.9935713, 0.1132084, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
-- (@OGUID+319, 195492, 648, 4737, 4766, 1, 1, 383, 0, -8430.903, 1216.694, 46.10237, 0.261525, 0, 0, 0.1303902, 0.9914628, 120, 255, 1, 15595), -- Kaja'mite Chunk (Area: Kaja'mine - Difficulty: 0) - !!! might be temporary spawn !!!
-- (@OGUID+320, 195492, 648, 4737, 4766, 1, 1, 383, 0, -8441.646, 1189.382, 41.54499, 4.266275, 0, 0, -0.8460093, 0.5331682, 120, 255, 1, 15595), -- Kaja'mite Chunk (Area: Kaja'mine - Difficulty: 0) - !!! might be temporary spawn !!!
(@OGUID+321, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8490.982, 1103.979, 42.5746, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
(@OGUID+322, 195488, 648, 4737, 4766, 1, 1, 383, 0, -8355.399, 1134.207, 34.31204, 0.7504908, 0, 0, 0.3665009, 0.9304177, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: Kaja'mine - Difficulty: 0)
-- (@OGUID+323, 195492, 648, 4737, 4766, 1, 1, 383, 0, -8425.792, 1165.755, 40.59349, 5.310069, 0, 0, -0.4675865, 0.8839473, 120, 255, 1, 15595), -- Kaja'mite Chunk (Area: Kaja'mine - Difficulty: 0) - !!! might be temporary spawn !!!
(@OGUID+324, 201719, 648, 4737, 4765, 1, 1, 383, 0, -8077.874, 1612.688, 40.8413, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+325, 201721, 648, 4737, 4765, 1, 1, 383, 0, -8083.745, 1656.281, 43.57653, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+326, 195449, 648, 4737, 4765, 1, 1, 383, 0, -8364.426, 1731.944, 39.94385, 0.122173, 0, 0, 0.06104851, 0.9981348, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+327, 195449, 648, 4737, 4765, 1, 1, 383, 0, -8358.611, 1732.385, 50.9572, 1.692969, 0, 0, 0.7489557, 0.6626201, 120, 255, 1, 15595), -- First Bank of Kezan Vault (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+328, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8339.45, 1446.13, 46.7236, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+329, 201719, 648, 4737, 4765, 1, 1, 383, 0, -8024.788, 1582.375, 2.109835, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+330, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8260.33, 1420.41, 39.9713, 0.7155849, 0, 0, 0.3502073, 0.9366722, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+331, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8180.6, 1276.37, 26.9604, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+332, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8176.97, 1323.55, 29.0534, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+333, 201719, 648, 4737, 0, 1, 1, 383, 0, -8134.463, 1730.629, 38.25383, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: 0 - Difficulty: 0)
(@OGUID+334, 201719, 648, 4737, 0, 1, 1, 383, 0, -8100.213, 1721.299, 19.23569, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: 0 - Difficulty: 0)
(@OGUID+335, 201719, 648, 4737, 0, 1, 1, 383, 0, -8192.091, 1742.267, 69.33064, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: 0 - Difficulty: 0)
(@OGUID+336, 201720, 648, 4737, 0, 1, 1, 383, 0, -8081.528, 1722.879, 54.61061, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: 0 - Difficulty: 0)
(@OGUID+337, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8251.46, 1470.42, 41.4199, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+338, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8262.29, 1468.74, 43.2355, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+339, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8226.97, 1506.95, 40.6273, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+340, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8278.5, 1468.89, 44.0705, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+341, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8264.92, 1500.9, 44.6297, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+342, 201719, 648, 4737, 4767, 1, 1, 383, 0, -8369.031, 1784.965, 58.52719, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+343, 201719, 648, 4737, 4767, 1, 1, 383, 0, -8338.004, 1786.913, 67.82098, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+344, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8286.16, 1499.72, 44.955, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+345, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8299.34, 1504.9, 46.0026, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+346, 201720, 648, 4737, 4822, 1, 1, 383, 0, -8479.601, 1770.988, 47.06443, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: Kajaro Field - Difficulty: 0)
(@OGUID+347, 201719, 648, 4737, 4822, 1, 1, 383, 0, -8435.535, 1786.238, 54.91433, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 5 6 7 (Area: Kajaro Field - Difficulty: 0)
(@OGUID+348, 201720, 648, 4737, 4822, 1, 1, 383, 0, -8521.226, 1788.181, 43.21481, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: Kajaro Field - Difficulty: 0)
(@OGUID+349, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8311.52, 1553.15, 48.9103, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+350, 201720, 648, 4737, 4822, 1, 1, 383, 0, -8355.802, 1838.807, 110.1541, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: Kajaro Field - Difficulty: 0)
(@OGUID+351, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8336.12, 1582.26, 50.8842, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+352, 201720, 648, 4737, 4822, 1, 1, 383, 0, -8538.455, 1793.627, 51.52261, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: Kajaro Field - Difficulty: 0)
(@OGUID+353, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8353.33, 1488.43, 47.3447, 4.572764, 0, 0, -0.7547092, 0.6560594, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+354, 201720, 648, 4737, 4822, 1, 1, 383, 0, -8568.118, 1793.634, 51.07738, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: Kajaro Field - Difficulty: 0)
(@OGUID+355, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8400.91, 1516.62, 51.4958, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+356, 201720, 648, 4737, 4822, 1, 1, 383, 0, -8588.558, 1786.509, 42.57923, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 5 6 7 (Area: Kajaro Field - Difficulty: 0)
(@OGUID+357, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8237.16, 1592.51, 34.2934, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+358, 201798, 648, 4737, 4822, 1, 1, 383, 0, -8179.73, 1582.63, 25.0378, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Kajaro Field - Difficulty: 0)
(@OGUID+359, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8232.21, 1633.07, 34.6871, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+360, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8175.11, 1588.12, 24.8921, 2.635444, 0, 0, 0.9681473, 0.2503814, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+361, 201798, 648, 4737, 4773, 1, 1, 383, 0, -8133.31, 1630.79, 15.6747, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+362, 201798, 648, 4737, 4773, 1, 1, 383, 0, -8171.66, 1663.97, 25.5727, 0.5934101, 0, 0, 0.2923708, 0.956305, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+363, 201798, 648, 4737, 4773, 1, 1, 383, 0, -8181.34, 1657.91, 24.9972, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+364, 201798, 648, 4737, 4773, 1, 1, 383, 0, -8008.03, 1545.59, 1.6474, 3.839725, 0, 0, -0.9396925, 0.3420205, 120, 255, 1, 15595), -- Kaja'Cola (Area: Swindle Street - Difficulty: 0)
(@OGUID+365, 201798, 648, 4737, 4772, 1, 1, 383, 0, -7994.57, 1707.53, 2.11572, 4.32842, 0, 0, -0.8290367, 0.5591941, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Slick - Difficulty: 0)
(@OGUID+366, 201798, 648, 4737, 4768, 1, 1, 383, 0, -8242.58, 1726.86, 44.7803, 5.550147, 0, 0, -0.3583679, 0.9335805, 120, 255, 1, 15595), -- Kaja'Cola (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+367, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8343.62, 1729, 51.8053, 5.777041, 0, 0, -0.2503796, 0.9681478, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+368, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8376.63, 1724.52, 40.8208, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+369, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8394.34, 1688.87, 49.9799, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+370, 201798, 648, 4737, 4840, 1, 1, 383, 0, -8431.93, 1653.76, 45.7783, 3.892087, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Pipe - Difficulty: 0)
(@OGUID+371, 201798, 648, 4737, 4840, 1, 1, 383, 0, -8486.51, 1591.24, 47.3394, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Pipe - Difficulty: 0)
(@OGUID+372, 201798, 648, 4737, 4840, 1, 1, 383, 0, -8468.48, 1567.79, 47.3571, 5.480334, 0, 0, -0.3907309, 0.920505, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Pipe - Difficulty: 0)
(@OGUID+373, 201798, 648, 4737, 4771, 1, 1, 383, 0, -8362.05, 1629.85, 49.5499, 1.274088, 0, 0, 0.5948219, 0.8038574, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+374, 201798, 648, 4737, 4771, 1, 1, 383, 0, -8293.58, 1662.63, 51.6436, 5.323256, 0, 0, -0.4617481, 0.8870111, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+375, 201798, 648, 4737, 4771, 1, 1, 383, 0, -8301.79, 1669.87, 51.6481, 0.802851, 0, 0, 0.3907309, 0.920505, 120, 255, 1, 15595), -- Kaja'Cola (Area: Drudgetown - Difficulty: 0)
(@OGUID+376, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8049.07, 1357.74, 5.37202, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+377, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8049.07, 1357.74, 5.37202, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+378, 201798, 648, 4737, 4772, 1, 1, 383, 0, -8040.54, 1201.39, 2.80035, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: The Slick - Difficulty: 0)
(@OGUID+379, 195515, 648, 4737, 4767, 1, 1, 383, 0, -8148.207, 1903.425, 69.76457, 5.881761, 0, 0, -0.1993675, 0.9799248, 120, 255, 1, 15595), -- Maldy's Falcon (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+380, 201798, 648, 4737, 4768, 1, 1, 383, 0, -8128.6, 1903.54, 55.4167, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+381, 201798, 648, 4737, 4768, 1, 1, 383, 0, -8040.44, 1864.26, 52.5156, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+382, 195518, 648, 4737, 4768, 1, 1, 383, 0, -8007.024, 1858.786, 54.2221, 0.087266, 0, 0, 0.04361916, 0.9990482, 120, 255, 1, 15595), -- The Ultimate Bomb (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+383, 201798, 648, 4737, 4768, 1, 1, 383, 0, -8018.01, 1885.35, 52.5155, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+384, 195516, 648, 4737, 4768, 1, 1, 383, 0, -8048.052, 1955.571, 54.98042, 4.677484, 0, 0, -0.7193394, 0.6946588, 120, 255, 1, 15595), -- The Goblin Lisa (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+385, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8064.47, 1463.38, 12.8306, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+386, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8049.08, 1495.84, 11.31512, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+387, 201798, 648, 4737, 4767, 1, 1, 383, 0, -8029.42, 1491.578, 10.6867, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kaja'Cola (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+388, 195488, 648, 4737, 4765, 1, 1, 383, 0, -8430.052, 1220.238, 46.95063, 0.8203033, 0, 0, 0.3987484, 0.9170604, 120, 255, 1, 15595), -- Kaja'mite Deposit (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+389, 201798, 648, 4737, 4765, 1, 1, 383, 0, -8516.9, 1371.94, 101.697, 0.2268925, 0, 0, 0.113203, 0.9935719, 120, 255, 1, 15595), -- Kaja'Cola (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+390, 188215, 648, 4737, 4765, 1, 1, 384, 0, -8422.514, 1325.675, 101.9162, 4.677484, 0, 0, -0.7193394, 0.6946588, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+391, 207312, 648, 4737, 4765, 1, 1, 384, 0, -8424.323, 1351.219, 104.5385, 3.673924, 0, 0, -0.9647865, 0.2630341, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+392, 207313, 648, 4737, 4765, 1, 1, 384, 0, -8415.729, 1349.894, 102.292, 2.434732, -0.01668978, 0.00671196, 0.938036, 0.3460707, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+393, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8424.224, 1346.332, 117.5592, 4.031712, 0, 0, -0.902585, 0.4305117, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+394, 201736, 648, 4737, 4765, 1, 1, 384, 0, -8422.514, 1325.675, 101.9162, 4.677484, 0, 0, -0.7193394, 0.6946588, 120, 255, 1, 15595), -- Gasbot Control Panel (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+395, 207311, 648, 4737, 4765, 1, 1, 384, 0, -8430.653, 1343.031, 102.0168, 4.677485, 0.01346159, -0.01771069, -0.719121, 0.6945287, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+396, 188215, 648, 4737, 4765, 1, 1, 384, 0, -8435.328, 1316.877, 102.5489, 0.9599299, 0, 0, 0.4617481, 0.8870111, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+397, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8409.576, 1353.953, 104.6859, 0.8726639, 0, 0, 0.4226179, 0.9063079, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+398, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8434.632, 1352.804, 112.3905, 2.094393, 0, 0, 0.866025, 0.5000008, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+399, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8405.181, 1353.861, 104.6859, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+400, 188215, 648, 4737, 4765, 1, 1, 384, 0, -8424.748, 1322.33, 102.8459, 1.553341, 0, 0, 0.7009087, 0.7132511, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+401, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8412.656, 1351.879, 113.5379, 2.757613, 0, 0, 0.9816265, 0.1908124, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+402, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8406.944, 1353.835, 113.3013, 4.502952, 0, 0, -0.7771454, 0.6293211, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+403, 207314, 648, 4737, 4765, 1, 1, 384, 0, -8397.958, 1348.891, 102.4515, 4.852015, 0.02533436, 0.01915169, -0.6558819, 0.7541952, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+404, 188215, 648, 4737, 4765, 1, 1, 384, 0, -8429.511, 1311.616, 103.3594, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 15595), -- Collision PC Size (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+405, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8400.031, 1355.507, 114.5021, 3.996807, 0, 0, -0.9099607, 0.4146944, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+406, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8407.797, 1365.198, 117.2703, 0.7504908, 0, 0, 0.3665009, 0.9304177, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+407, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8415.073, 1367.682, 117.241, 0.8552105, 0, 0, 0.4146929, 0.9099615, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+408, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8409.149, 1367.495, 117.2703, 0.2792516, 0, 0, 0.1391726, 0.9902682, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+409, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8419.643, 1361.321, 116.8672, 3.874631, 0, 0, -0.9335804, 0.358368, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+410, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.528, 1364.892, 104.7084, 2.792518, 0, 0, 0.984807, 0.1736523, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+411, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.732, 1363.479, 104.7198, 1.396262, 0, 0, 0.642787, 0.766045, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+412, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8404.665, 1360.024, 117.2669, 3.42085, 0, 0, -0.9902678, 0.1391754, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+413, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8430.799, 1357.429, 133.856, 4.031712, 0, 0, -0.902585, 0.4305117, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+414, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8423.214, 1357.967, 117.706, 3.787367, 0, 0, -0.9483232, 0.3173059, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+415, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8420.953, 1367.361, 116.8769, 4.76475, 0, 0, -0.6883545, 0.7253745, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+416, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8415.601, 1359.661, 104.6858, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+417, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8402.607, 1361.026, 117.2417, 3.42085, 0, 0, -0.9902678, 0.1391754, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+418, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8426.377, 1359.865, 104.6744, 0.7155849, 0, 0, 0.3502073, 0.9366722, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+419, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8406.982, 1356.168, 104.6987, 2.652894, 0, 0, 0.970295, 0.241925, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+420, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8415.446, 1360.87, 104.6888, 1.291542, 0, 0, 0.6018143, 0.7986361, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+421, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8415.107, 1368.092, 104.6856, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+422, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8421.02, 1360.231, 116.8558, 3.822273, 0, 0, -0.9426413, 0.3338076, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+423, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.497, 1366.342, 104.694, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+424, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8409.491, 1359.957, 117.2703, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+425, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8417.042, 1370.415, 104.6724, 1.745327, 0, 0, 0.7660437, 0.6427886, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+426, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8427.92, 1366.852, 116.8782, 0.1047193, 0, 0, 0.05233574, 0.9986296, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+427, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8415.21, 1359.948, 117.2411, 1.361356, 0, 0, 0.6293201, 0.7771462, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+428, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8411.261, 1358.847, 104.7071, 1.099556, 0, 0, 0.5224981, 0.8526405, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+429, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8408.167, 1359.913, 117.2703, 2.879789, 0, 0, 0.9914446, 0.1305283, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+430, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8410.386, 1367.566, 117.2703, 3.892087, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+431, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8420.857, 1368.844, 116.8497, 3.647741, 0, 0, -0.9681473, 0.2503814, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+432, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8421.87, 1357.852, 117.7059, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+433, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8428.045, 1361.208, 116.8584, 0.8726639, 0, 0, 0.4226179, 0.9063079, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+434, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8416.413, 1366.502, 117.2534, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+435, 207319, 648, 4737, 4765, 1, 1, 384, 0, -8435.17, 1363.281, 104.6206, 4.092797, 0, 0, -0.8890171, 0.457874, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+436, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8407.776, 1367.422, 117.2703, 0.4537851, 0, 0, 0.2249508, 0.9743701, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+437, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8417.361, 1356.858, 134.5368, 2.199115, 0, 0, 0.8910065, 0.4539906, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+438, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8426.701, 1360.259, 116.8567, 2.007128, 0, 0, 0.8433914, 0.5372996, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+439, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8407.724, 1362.064, 117.2703, 3.892087, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+440, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.649, 1360.72, 104.6926, 3.316144, 0, 0, -0.9961939, 0.08716504, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+441, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8424.596, 1358.014, 117.7061, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+442, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.639, 1361.995, 104.7054, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+443, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8427.875, 1367.262, 104.6824, 5.602507, 0, 0, -0.333807, 0.9426414, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+444, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8418.516, 1371.273, 104.6639, 5.567601, 0, 0, -0.3502073, 0.9366722, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+445, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8416.611, 1361.08, 117.2546, 2.216565, 0, 0, 0.8949337, 0.4461992, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+446, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8419.576, 1366.818, 116.8786, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+447, 207316, 648, 4737, 4765, 1, 1, 384, 0, -8399.397, 1357.724, 104.5925, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+448, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8402.014, 1355.181, 104.6859, 2.600535, 0, 0, 0.9636297, 0.267241, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+449, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8416.618, 1360.325, 104.6858, 2.897245, 0, 0, 0.9925461, 0.12187, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+450, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.486, 1361.556, 120.701, 3.839725, 0, 0, -0.9396925, 0.3420205, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+451, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8420.505, 1359.556, 104.6765, 2.879789, 0, 0, 0.9914446, 0.1305283, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+452, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.837, 1356.616, 104.6859, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+453, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8406.783, 1359.97, 117.2703, 5.096362, 0, 0, -0.5591927, 0.8290377, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+454, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8425.948, 1357.988, 117.706, 2.879789, 0, 0, 0.9914446, 0.1305283, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+455, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8405.739, 1367.497, 117.2703, 0.8726639, 0, 0, 0.4226179, 0.9063079, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+456, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8424.518, 1373.497, 104.6644, 5.602507, 0, 0, -0.333807, 0.9426414, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+457, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8404.174, 1363.342, 129.6652, 4.031712, 0, 0, -0.902585, 0.4305117, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+458, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8427.625, 1372.321, 113.9997, 0.9424766, 0, 0, 0.45399, 0.8910068, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+459, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8401.639, 1365.71, 120.6722, 4.97419, 0, 0, -0.6087608, 0.7933538, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+460, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8404.359, 1367.363, 117.2646, 4.694937, 0, 0, -0.7132502, 0.7009096, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+461, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8418.118, 1373.286, 104.6659, 0.01745246, 0, 0, 0.00872612, 0.9999619, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+462, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8529.54, 1339.48, 171.177, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+463, 207318, 648, 4737, 4765, 1, 1, 384, 0, -8419.554, 1379.139, 104.5288, 2.818698, 0, 0, 0.9869957, 0.1607467, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+464, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8427.674, 1373.658, 113.9997, 0.6108634, 0, 0, 0.300705, 0.9537172, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+465, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8476.12, 1234.73, 53.2293, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+466, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8426.439, 1373.5, 113.9997, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+467, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8403.278, 1373.184, 104.6859, 4.729844, 0, 0, -0.7009087, 0.7132511, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+468, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8404.951, 1373.608, 104.6859, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+469, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8417.191, 1372.398, 104.6717, 1.745327, 0, 0, 0.7660437, 0.6427886, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+470, 207317, 648, 4737, 4765, 1, 1, 384, 0, -8404.857, 1376.486, 104.6187, 1.021017, 0, 0, 0.4886208, 0.8724963, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+471, 207315, 648, 4737, 4765, 1, 1, 384, 0, -8395.596, 1369.309, 101.9896, 3.141593, 0, 0, -1, 0, 120, 255, 1, 15595), -- Oil Puddle (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+472, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8423.299, 1372.703, 104.6624, 4.293513, 0, 0, -0.8386698, 0.5446402, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+473, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8403.274, 1369.224, 104.7038, 1.239183, 0, 0, 0.5807028, 0.8141156, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+474, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8409.283, 1373.363, 104.6916, 4.468043, 0, 0, -0.7880106, 0.6156617, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+475, 201739, 648, 4737, 4765, 1, 1, 384, 0, -8423.252, 1361.172, 139.1262, 4.031712, 0, 0, -0.902585, 0.4305117, 120, 255, 1, 15595), -- Oil Dripping Balloon (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+476, 201740, 648, 4737, 4765, 1, 1, 384, 0, -8427.302, 1371.245, 104.6816, 1.710422, 0, 0, 0.7547092, 0.6560594, 120, 255, 1, 15595), -- Explosives Crate (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+477, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8520.01, 1506.13, 83.5913, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+478, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8411.25, 1101.77, 113.816, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+479, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8430.12, 1197.43, 43.2253, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+480, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8527.17, 1511.18, 133.344, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+481, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8455.19, 1472.99, 102.658, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+482, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8550.06, 1412.52, 141.271, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+483, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8573.46, 1222.55, 133.344, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+484, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8484.07, 1119.92, 43.1011, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+485, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8556.83, 1171.09, 117.328, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+486, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8527.28, 1362.62, 171.136, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+487, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8582.01, 1276.64, 135.26, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+488, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8502.57, 1223.94, 50.3505, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+489, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8417.13, 1169.33, 41.6187, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+490, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8527.17, 1511.18, 133.344, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+491, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8487.92, 1136.13, 41.4238, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+492, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8480.92, 1123.31, 54.7205, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+493, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8450.88, 1173.2, 43.3912, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+494, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8550.21, 1449.38, 141.685, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+495, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8481.75, 1211.66, 44.5404, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+496, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8501.05, 1482.08, 90.2853, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+497, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8409.5, 1504.06, 168.901, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+498, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8421.83, 1190.98, 43.3088, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+499, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8419.57, 1125.48, 49.1232, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+500, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8540.98, 1412.72, 160.021, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+501, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8208.82, 1249.74, 60.9617, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+502, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8493.66, 1163.39, 44.294, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+503, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8538.19, 1459.41, 94.3475, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+504, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8385.88, 1453.26, 80.4564, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+505, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8451.95, 1144.84, 39.7249, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+506, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8567.9, 1310.36, 135.269, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+507, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8573.21, 1231.98, 170.832, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+508, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8505.731, 1216.061, 50.47108, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+509, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8386.3, 1468.97, 65.4448, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+510, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8529.87, 1504, 111.116, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+511, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8452.4, 1493.31, 97.2187, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+512, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8519.22, 1244.65, 54.9609, 2.478367, 0, 0, 0.9455185, 0.3255684, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+513, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8452.27, 1492.48, 87.3986, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+514, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8541.06, 1448.7, 160.163, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+515, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8349.69, 1199.09, 130.602, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+516, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8404.71, 1462.77, 175.91, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+517, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8573.85, 1273.36, 153.981, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+518, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8480.92, 1123.31, 54.7205, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+519, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8560.29, 1306.24, 154.102, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+520, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8493.63, 1167.79, 42.4108, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+521, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8330.96, 1179.69, 71.6398, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+522, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8386.8, 1486.57, 68.9794, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+523, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8505.58, 1486.91, 87.6635, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+524, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8445.15, 1152.34, 41.854, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+525, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8418.32, 1170.93, 52.2379, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+526, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8579.76, 1209.88, 170.796, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+527, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8312.15, 1595.17, 87.8427, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+528, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8096.94, 1344.28, 18.4538, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+529, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8459.7, 1087.03, 87.7305, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+530, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8206.82, 1478.13, 75.6213, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+531, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8172.74, 1326.13, 58.705, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+532, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8192.48, 1541.15, 66.4104, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+533, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8625.63, 1142.29, 128.299, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+534, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8196.63, 1485.04, 65.1115, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+535, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8173.85, 1091.69, 46.0304, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+536, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8213.46, 1470.11, 71.5263, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+537, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8615.02, 1177.29, 128.312, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+538, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8278.91, 1595.79, 87.8427, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+539, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8115.92, 1459.51, 13.4476, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+540, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8172.7, 1258.49, 34.4995, 3.42085, 0, 0, -0.9902678, 0.1391754, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+541, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8149.51, 1289.03, 23.2686, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+542, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8209.69, 1392.14, 39.8588, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+543, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8113.17, 1491.01, 42.6571, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+544, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8305.58, 1591.61, 112.734, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+545, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8163.51, 1474.68, 38.0554, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+546, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8282.9, 1592, 112.55, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+547, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8296.46, 1622.57, 85.4847, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+548, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8160.84, 1475.39, 38.1894, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+549, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8112.59, 1487.5, 26.1734, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+550, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8176.18, 1268.4, 35.1964, 3.42085, 0, 0, -0.9902678, 0.1391754, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+551, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8312.68, 1622.13, 99.3196, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+552, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8560.91, 1093.94, 110.091, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+553, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8423.95, 1085.38, 77.1356, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+554, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8143.97, 1336.75, 21.2843, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+555, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8179.49, 1575.25, 38.4339, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+556, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8283.24, 1626.34, 112.62, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+557, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8183.77, 1328.04, 63.1528, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+558, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8191.22, 1107.63, 66.2196, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+559, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8119.94, 1475.92, 72.5913, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+560, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8606.57, 1176.09, 146.485, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+561, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8617.03, 1141.73, 146.77, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+562, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8314.57, 1590.14, 170.3, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+563, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8161.19, 1099.49, 13.077, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+564, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8192.28, 1545.73, 44.4937, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+565, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8553.89, 1126.62, 109.247, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+566, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8214.22, 1440.72, 36.2468, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+567, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8266.64, 1608.88, 100.755, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+568, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8306.13, 1625.93, 112.724, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+569, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8547.01, 1559.89, 115.987, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+570, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8520.28, 1551.83, 101.775, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+571, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8296.14, 1595.46, 80.7134, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+572, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8285.5, 1148.59, 18.6321, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+573, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8176.59, 1303.73, 36.2794, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+574, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8185.21, 1260.3, 35.7717, 3.42085, 0, 0, -0.9902678, 0.1391754, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+575, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8132.31, 1466.31, 13.1365, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+576, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8279.4, 1622.73, 87.8427, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+577, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8087.22, 1496.2, 8.83122, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+578, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8392.72, 1720.06, 90.4604, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+579, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8106.158, 1482.785, 26.36062, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+580, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8113.39, 1548.03, 13.4325, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+581, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8407.44, 1715.68, 73.7148, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+582, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8113.96, 1538.14, 12.7949, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+583, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8088.1, 1468.35, 8.83333, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+584, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8203.04, 1636.86, 38.795, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+585, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8142.87, 1591.36, 51.7262, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+586, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8421.23, 1711.58, 80.1311, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+587, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8523.63, 1688.88, 121.85, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+588, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8254.39, 1008.88, 40.7356, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+589, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8106.42, 1482.238, 17.68075, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+590, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8118.92, 1555.94, 28.1113, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+591, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8148.28, 1576.58, 24.9414, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+592, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8099.87, 1490.07, 9.24494, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+593, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8119.22, 1555.94, 20.5665, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+594, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8112.21, 1541.81, 35.6833, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+595, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8431.91, 1358.271, 133.8549, 4.76475, 0, 0, -0.6883545, 0.7253745, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+596, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8431.91, 1358.271, 133.8549, 4.76475, 0, 0, -0.6883545, 0.7253745, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+597, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8125.07, 1595.14, 40.7286, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+598, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8195.26, 1648.44, 36.8608, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+599, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8405.054, 1362.967, 129.4254, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+600, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8406.944, 1353.835, 113.3013, 4.502952, 0, 0, -0.7771454, 0.6293211, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+601, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8117.88, 1592.18, 20.1704, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+602, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8181.04, 1666.41, 59.4982, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+603, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8117.2, 1607.05, 16.9092, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+604, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8117.61, 1594.38, 15.905, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+605, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8123.43, 1589.5, 12.758, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+606, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8120.26, 1628.2, 14.1154, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+607, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8119.83, 1628.47, 19.3913, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+608, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8206.32, 1692.57, 68.214, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+609, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8119.71, 1615.4, 34.1414, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+610, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8116.24, 1625.92, 25.9126, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+611, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8029.29, 1481.41, 37.9844, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+612, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8028.59, 1506.26, 35.701, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+613, 201770, 648, 4737, 4765, 1, 1, 384, 0, -7997.62, 1256.68, 4.23036, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+614, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8118.67, 1652.61, 23.8197, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+615, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8004.32, 1258.25, 5.07571, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+616, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8107.96, 1649.04, 26.3122, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+617, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8112.4, 1659.87, 22.2255, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+618, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8205.77, 1719.81, 62.0192, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+619, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8118.14, 1657.77, 12.0872, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+620, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8112.54, 1674.2, 22.57, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+621, 201770, 648, 4737, 4765, 1, 1, 384, 0, -8112.24, 1661.87, 15.8769, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+622, 201769, 648, 4737, 4765, 1, 1, 384, 0, -8115.49, 1681.31, 35.4185, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+623, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8198.16, 1706.32, 105.366, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+624, 201768, 648, 4737, 4765, 1, 1, 384, 0, -7880.89, 1268.89, 33.904, 3.665196, 0, 0, -0.9659252, 0.2588213, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+625, 201768, 648, 4737, 4765, 1, 1, 384, 0, -7882.46, 1266.11, 56.6643, 3.665196, 0, 0, -0.9659252, 0.2588213, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+626, 201768, 648, 4737, 4765, 1, 1, 384, 0, -7884.28, 1241.43, 26.1854, 3.665196, 0, 0, -0.9659252, 0.2588213, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+627, 201768, 648, 4737, 4765, 1, 1, 384, 0, -7875.01, 1243.1, 52.9341, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+628, 201768, 648, 4737, 4765, 1, 1, 384, 0, -8081.22, 935.99, 30.5997, 1.06465, 0, 0, 0.5075378, 0.8616294, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+629, 201768, 648, 4737, 0, 1, 1, 384, 0, -7895.17, 980.639, 35.5421, 5.969027, 0, 0, -0.1564341, 0.9876884, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+630, 201768, 648, 4737, 0, 1, 1, 384, 0, -7859.15, 1028.24, 38.8969, 5.969027, 0, 0, -0.1564341, 0.9876884, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+631, 201768, 648, 4737, 0, 1, 1, 384, 0, -8063.98, 904.816, 58.114, 1.06465, 0, 0, 0.5075378, 0.8616294, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+632, 201768, 648, 4737, 0, 1, 1, 384, 0, -8068.46, 900.446, 35.2994, 1.06465, 0, 0, 0.5075378, 0.8616294, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+633, 201768, 648, 4737, 0, 1, 1, 384, 0, -7894.77, 982.557, 35.566, 5.969027, 0, 0, -0.1564341, 0.9876884, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+634, 201768, 648, 4737, 0, 1, 1, 384, 0, -7871.83, 1010.94, 69.7457, 5.969027, 0, 0, -0.1564341, 0.9876884, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+635, 201768, 648, 4737, 0, 1, 1, 384, 0, -7843.45, 1022.67, 30.6574, 5.969027, 0, 0, -0.1564341, 0.9876884, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+636, 201768, 648, 4737, 0, 1, 1, 384, 0, -7876.16, 1009.95, 56.2238, 5.969027, 0, 0, -0.1564341, 0.9876884, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+637, 201768, 648, 4737, 0, 1, 1, 384, 0, -8064.3, 904.569, 58.0798, 1.06465, 0, 0, 0.5075378, 0.8616294, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+638, 201768, 648, 4737, 0, 1, 1, 384, 0, -7965.4, 1612.62, 5.47604, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+639, 201768, 648, 4737, 0, 1, 1, 384, 0, -7857.46, 981.755, 77.7687, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: 0 - Difficulty: 0)
(@OGUID+640, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8114.33, 1759.96, 64.0751, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+641, 201770, 648, 4737, 4767, 1, 1, 384, 0, -8124.87, 1736.53, 44.9768, 0.8901166, 0, 0, 0.4305105, 0.9025856, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+642, 201770, 648, 4737, 4767, 1, 1, 384, 0, -8130.97, 1730.75, 41.2185, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+643, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8121.81, 1750.12, 22.8008, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+644, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8122.86, 1753.45, 58.1477, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+645, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8178.83, 1754.13, 51.6, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+646, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8123.2, 1749.89, 36.634, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+647, 201770, 648, 4737, 4767, 1, 1, 384, 0, -8086.96, 1710.03, 20.0666, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+648, 207289, 648, 4737, 4767, 1, 1, 384, 0, -8106.054, 1482.87, 17.45187, 1.117009, 0, 0, 0.5299187, 0.8480484, 120, 255, 1, 15595), -- Rope Ladder (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+649, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8171.15, 1765.33, 32.4411, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+650, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8177.53, 1773.19, 56.7635, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+651, 201770, 648, 4737, 4767, 1, 1, 384, 0, -8073.33, 1829.81, 42.9984, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+652, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8179.46, 1781.76, 47.1648, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+653, 201770, 648, 4737, 4767, 1, 1, 384, 0, -8098.51, 1809.24, 33.3281, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+654, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8152.9, 1881.96, 94.9805, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+655, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8241.08, 1879.78, 82.2322, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+656, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8005.61, 1862.17, 76.3666, 4.76475, 0, 0, -0.6883545, 0.7253745, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+657, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8128.49, 1889.51, 56.4122, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+658, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8237.12, 1884.06, 91.2492, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+659, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8143.07, 1907.61, 80.4084, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+660, 207355, 648, 4737, 4767, 1, 1, 384, 0, -7880.948, 1827.925, 4.155282, 0.3490652, 0, 0, 0.1736479, 0.9848078, 120, 255, 1, 15595), -- Last Chance Yacht Boarding Mortar (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+661, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8033.61, 1862.21, 56.2971, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+662, 201791, 648, 4737, 4767, 1, 1, 384, 0, -7863.338, 1831.325, -3.090933, 6.265733, 0, 0, -0.00872612, 0.9999619, 120, 255, 1, 15595), -- Rope Ladder (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+663, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8137.5, 1883.51, 85.6234, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+664, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8144.22, 1884.16, 78.9673, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+665, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8237.12, 1884.06, 91.2492, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+666, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8246.99, 1885.39, 95.9738, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+667, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8044.64, 1910.23, 55.1578, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+668, 201769, 648, 4737, 4767, 1, 1, 384, 0, -8243.98, 1877.65, 90.6216, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Medium Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+669, 201768, 648, 4737, 4767, 1, 1, 384, 0, -8252.23, 1882.45, 109.362, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+670, 201768, 648, 4737, 4767, 1, 1, 384, 0, -7965.52, 1897.6, 52.5057, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Bilgewater Port - Difficulty: 0)
(@OGUID+671, 201768, 648, 4737, 4773, 1, 1, 384, 0, -8344, 1862.51, 135.656, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+672, 201768, 648, 4737, 4773, 1, 1, 384, 0, -8048.2, 1948.01, 52.708, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Large Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+673, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8528.83, 1734.97, 151.617, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+674, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8515.2, 1770.21, 151.597, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+675, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8357.13, 1867.29, 180.516, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+676, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8409.69, 1873.02, 155.904, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+677, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8452.55, 1853.5, 155.906, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+678, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8502.04, 1804.33, 151.61, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+679, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8453.02, 1853.63, 155.886, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+680, 201770, 648, 4737, 4773, 1, 1, 384, 0, -8410.06, 1873.23, 155.994, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- Kezan Small Fire - Phase 7 (Area: Swindle Street - Difficulty: 0)
(@OGUID+681, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8431.91, 1358.271, 133.8549, 4.76475, 0, 0, -0.6883545, 0.7253745, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+682, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8405.054, 1362.967, 129.4254, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+683, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8428.973, 1380.368, 112.3636, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+684, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8417.77, 1374.505, 134.5619, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+685, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8425.448, 1348.561, 114.7826, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+686, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8425.505, 1372.167, 113.9997, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+687, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8419.529, 1364.068, 116.8689, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+688, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8410.708, 1352.564, 108.0799, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+689, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8405.658, 1362.576, 129.0589, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+690, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8431.052, 1356.361, 133.9016, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+691, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8435.665, 1355.816, 104.6626, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+692, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8423.728, 1359.307, 117.7051, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+693, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8423.707, 1374.991, 125.6296, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+694, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8404.12, 1374.842, 108.2554, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+695, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8423.966, 1365.488, 104.6762, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+696, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8399.953, 1364.208, 124.0039, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+697, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8426.998, 1377.477, 148.7926, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+698, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8423.842, 1376.5, 130.3349, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+699, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8424.219, 1352.505, 131.3072, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+700, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8407.382, 1364.278, 104.0208, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+701, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8424.323, 1350.474, 104.6626, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+702, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8424.029, 1358.387, 125.1079, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+703, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8417.583, 1356.238, 134.5496, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+704, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8406.051, 1363.655, 117.2703, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+705, 207751, 648, 4737, 4765, 1, 1, 384, 0, -8419.772, 1323.259, 101.9808, 3.141593, 0, 0, -1, 0, 120, 255, 1, 15595), -- Claim's Adjuster's Shredder (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+706, 201745, 648, 4737, 4765, 1, 1, 384, 0, -8434.335, 1357.259, 112.3967, 0, 0, 0, 0, 1, 120, 255, 1, 15595), -- 447 Fire (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+707, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8406.944, 1353.835, 113.3013, 4.502952, 0, 0, -0.7771454, 0.6293211, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+708, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8405.054, 1362.967, 129.4254, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+709, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8405.054, 1362.967, 129.4254, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+710, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8431.91, 1358.271, 133.8549, 4.76475, 0, 0, -0.6883545, 0.7253745, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+711, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8419.153, 1355.212, 134.7274, 4.834563, 0, 0, -0.6626196, 0.7489561, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+712, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8406.944, 1353.835, 113.3013, 4.502952, 0, 0, -0.7771454, 0.6293211, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+713, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8405.054, 1362.967, 129.4254, 4.71239, 0, 0, -0.7071066, 0.7071069, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+714, 181886, 648, 4737, 4765, 1, 1, 384, 0, -8419.153, 1355.212, 134.7274, 4.834563, 0, 0, -0.6626196, 0.7489561, 120, 255, 1, 15595), -- Purple Firework Rocket (Area: KTC Headquarters - Difficulty: 0)
(@OGUID+715, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7853.717, 1836.682, 7.970508, 5.218536, 0, 0, -0.5075378, 0.8616294, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+716, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7847.075, 1849.476, 6.978344, 2.495818, 0, 0, 0.9483232, 0.3173059, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+717, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7857.974, 1842.057, 7.487597, 6.178466, 0, 0, -0.05233574, 0.9986296, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+718, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7846.397, 1836.227, 7.965293, 1.518436, 0, 0, 0.6883545, 0.7253745, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+719, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7851.729, 1849.444, 6.99513, 4.642576, 0, 0, -0.7313538, 0.6819983, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+720, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7845.542, 1849.694, 6.969073, 4.677484, 0, 0, -0.7193394, 0.6946588, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+721, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7843.561, 1847.141, 7.105835, 0.3316107, 0, 0, 0.1650467, 0.9862857, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+722, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7850.384, 1849.313, 7.01502, 4.642576, 0, 0, -0.7313538, 0.6819983, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+723, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7842.622, 1845.814, 7.183758, 0.1745321, 0, 0, 0.08715534, 0.9961947, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+724, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7848.167, 1849.488, 6.996207, 2.024579, 0, 0, 0.8480473, 0.5299206, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+725, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7840.543, 1840.283, 7.560513, 2.583081, 0, 0, 0.9612608, 0.2756405, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+726, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7841.097, 1836.102, 7.849866, 0.6108634, 0, 0, 0.300705, 0.9537172, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+727, 201790, 648, 4737, 4768, 1, 1, 384, 0, -7840.462, 1842.896, 7.366406, 3.001947, 0, 0, 0.9975634, 0.06976615, 120, 255, 1, 15595), -- Ball and Chain (Area: Gallywix's Villa - Difficulty: 0)
(@OGUID+728, 195188, 648, 4720, 4721, 1, 1, 170, 0, 548.6962, 3327.155, 0, 4.310966, 0, 0, -0.8338852, 0.5519379, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+729, 195188, 648, 4720, 4721, 1, 1, 170, 0, 454.7465, 3274.634, 0, 0.1047193, 0, 0, 0.05233574, 0.9986296, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+730, 195188, 648, 4720, 4721, 1, 1, 170, 0, 606.2292, 3317.63, 0, 1.029743, 0, 0, 0.4924231, 0.870356, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+731, 195188, 648, 4720, 4721, 1, 1, 170, 0, 550.8958, 3248.118, 0, 1.727875, 0, 0, 0.7604055, 0.6494485, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+732, 195188, 648, 4720, 4721, 1, 1, 170, 0, 574.8264, 3294.393, 0, 3.892087, 0, 0, -0.9304171, 0.3665025, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+733, 195188, 648, 4720, 4721, 1, 1, 170, 0, 477.0521, 3327.461, 0, 5.253442, 0, 0, -0.4924231, 0.870356, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+734, 195188, 648, 4720, 4721, 1, 1, 170, 0, 503.1528, 3345.603, 0, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+735, 195188, 648, 4720, 4721, 1, 1, 170, 0, 580.0261, 3343.371, 0, 5.148723, 0, 0, -0.5372992, 0.8433917, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+736, 195188, 648, 4720, 4721, 1, 1, 170, 0, 485.5313, 3240.849, 0, 1.117009, 0, 0, 0.5299187, 0.8480484, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+737, 195188, 648, 4720, 4721, 1, 1, 170, 0, 486.2899, 3201.208, 0, 4.537859, 0, 0, -0.7660437, 0.6427886, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+738, 195188, 648, 4720, 4721, 1, 1, 170, 0, 621.8438, 3262.851, 0, 3.665196, 0, 0, -0.9659252, 0.2588213, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+739, 195188, 648, 4720, 4721, 1, 1, 170, 0, 590.3316, 3221.278, 0, 5.235988, 0, 0, -0.5, 0.8660254, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+740, 195188, 648, 4720, 4721, 1, 1, 170, 0, 512.4167, 3220.306, 0, 1.308995, 0, 0, 0.6087608, 0.7933538, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+741, 207484, 648, 4720, 4721, 1, 1, 170, 0, 546.6563, 3198.964, -8.176452, 5.846854, 0, 0, -0.2164392, 0.9762961, 120, 255, 1, 15595), -- Sturdy Treasure Chest (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+742, 195188, 648, 4720, 4721, 1, 1, 170, 0, 551.0903, 3181.908, 0, 4.921829, 0, 0, -0.6293201, 0.7771462, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+743, 195188, 648, 4720, 4721, 1, 1, 170, 0, 510.8403, 3281.251, 0, 1.937312, 0, 0, 0.8241253, 0.5664076, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+744, 195188, 648, 4720, 4721, 1, 1, 170, 0, 308.7899, 3206.192, 0, 4.921829, 0, 0, -0.6293201, 0.7771462, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+745, 195188, 648, 4720, 4721, 1, 1, 170, 0, 406.4097, 3257.612, 0, 5.183629, 0, 0, -0.5224981, 0.8526405, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+746, 195188, 648, 4720, 4721, 1, 1, 170, 0, 366.2431, 3233.604, 0, 4.81711, 0, 0, -0.6691303, 0.743145, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+747, 195188, 648, 4720, 4721, 1, 1, 170, 0, 554.8229, 3435.682, 0, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+748, 195188, 648, 4720, 4721, 1, 1, 170, 0, 318.911, 3271.23, 0, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+749, 202494, 648, 4720, 4721, 1, 1, 170, 0, 900.3542, 3275.425, 13.45322, 3.143686, 0.02537394, 0.00182724, -0.9996758, 0.00109183, 120, 255, 1, 15595), -- Campfire (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+750, 195188, 648, 4720, 4721, 1, 1, 170, 0, 434.533, 3222.872, 0, 1.727875, 0, 0, 0.7604055, 0.6494485, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+751, 195188, 648, 4720, 4721, 1, 1, 170, 0, 432.4601, 3186.178, 0, 4.32842, 0, 0, -0.8290367, 0.5591941, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+752, 195188, 648, 4720, 4721, 1, 1, 170, 0, 457.276, 3157.988, 0, 1.989672, 0, 0, 0.8386698, 0.5446402, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+753, 195188, 648, 4720, 4721, 1, 1, 170, 0, 349.3212, 3181.99, 0, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+754, 195188, 648, 4720, 4721, 1, 1, 170, 0, 384.9774, 3199.773, 0, 1.745327, 0, 0, 0.7660437, 0.6427886, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+755, 195188, 648, 4720, 4721, 1, 1, 170, 0, 369.8333, 3148.738, 0, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+756, 195188, 648, 4720, 4721, 1, 1, 170, 0, 418.4323, 3142.503, 0, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+757, 195188, 648, 4720, 4721, 1, 1, 170, 0, 376.59, 3297.09, 0, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+758, 195188, 648, 4720, 4721, 1, 1, 170, 0, 588.6163, 3409.43, 0, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+759, 195188, 648, 4720, 4721, 1, 1, 170, 0, 632.7917, 3379.958, 0, 4.572764, 0, 0, -0.7547092, 0.6560594, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+760, 195188, 648, 4720, 4721, 1, 1, 170, 0, 484.358, 3386.83, 0, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+761, 195188, 648, 4720, 4721, 1, 1, 170, 0, 367.4931, 3096.531, 0, 4.921829, 0, 0, -0.6293201, 0.7771462, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+762, 202495, 648, 4720, 4721, 1, 1, 170, 0, 880.8264, 3317.732, 10.50565, 3.143686, 0.02537394, 0.00182724, -0.9996758, 0.00109183, 120, 255, 1, 15595), -- Campfire (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+763, 195188, 648, 4720, 4721, 1, 1, 170, 0, 632.684, 3225.135, 0, 0.9075702, 0, 0, 0.4383707, 0.8987942, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+764, 195188, 648, 4720, 4721, 1, 1, 170, 0, 563.316, 3381.815, 0, 3.246347, 0, 0, -0.9986286, 0.05235322, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+765, 195188, 648, 4720, 4721, 1, 1, 170, 0, 318.911, 3271.23, 0, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+766, 195188, 648, 4720, 4721, 1, 1, 170, 0, 619.5989, 3199.653, 0, 1.53589, 0, 0, 0.6946583, 0.7193398, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+767, 195188, 648, 4720, 4721, 1, 1, 170, 0, 520.4167, 3407.221, 0, 4.921829, 0, 0, -0.6293201, 0.7771462, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+768, 195188, 648, 4720, 4721, 1, 1, 170, 0, 318.911, 3271.23, 0, 2.373644, 0, 0, 0.9271832, 0.3746083, 120, 255, 1, 15595), -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
(@OGUID+769, 195188, 648, 4720, 4721, 1, 1, 170, 0, 432.816, 3310.579, 0, 3.159062, 0, 0, -0.9999619, 0.008734641, 120, 255, 1, 15595); -- Goblin Escape Pod (Area: Shipwreck Shore - Difficulty: 0)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+769;

DELETE FROM `creature_template_addon` WHERE `entry` IN (36735 /*36735 (Teraptor Matriarch) - Infrared = Infradead: Heat Signature Aura - Beast*/, 36600 /*36600 (Geargrinder Gizmo) - Infrared = Infradead: Heat Signature Aura - Humanoid (80%), Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)*/, 36719 /*36719 (Pterrordax Scavenger) - Infrared = Infradead: Heat Signature Aura - Beast*/, 34763 /*34763 (Daggertooth Shark) - Infrared = Infradead: Heat Signature Aura - Beast*/, 37683 /*37683 (Villa Mook) - Acidic Sweat*/, 37602 /*37602 (Claims Adjuster) - 447: Claims Adjuster Quest Invis 1*/, 37682 /*37682 (447 Fireworks Bunny) - 447: Claims Adjuster Quest Invis 1*/, 49218 /*49218 (Villa Mook) - Acidic Sweat*/, 37500 /*37500 (Vinny Slapchop)*/, 48925 /*48925 (Mook Disguise) - Waltz Right In: Mook Disguise*/, 35613 /*35613 (Keensnout Potbelly)*/, 35609 /*35609 (Villa Mook) - Acidic Sweat*/, 35234 /*35234 (Hired Looter)*/, 39660 /*39660 (Spirit Healer) - Shroud of Death*/, 35294 /*35294 (Rebellious Troll)*/, 35236 /*35236 (Kezan Partygoer) - Cosmetic - Cower (Upper Body) Anim Kit*/, 49338 /*49338 (KTC Waitress) - Permanent Feign Death*/, 37710 /*37710 (Gobber)*/, 37708 /*37708 (Izzy)*/, 37709 /*37709 (Ace)*/, 35237 /*35237 (Pirate Party Crasher) - Permanent Feign Death (Drowned Anim Kit)*/, 49339 /*49339 (KTC Waiter) - Permanent Feign Death*/, 35238 /*35238 (Kezan Partygoer)*/, 35235 /*35235 (Kezan Partygoer) - Permanent Feign Death*/, 35213 /*35213 (Izzy)*/, 35212 /*35212 (Gobber)*/, 35211 /*35211 (Ace)*/, 48805 /*48805 (KTC Waiter) - Drink Tray*/, 35202 /*35202 (Kezan Partygoer)*/, 48806 /*48806 (KTC Waitress) - Drink Tray*/, 35200 /*35200 (Pirate Party Crasher)*/, 35210 /*35210 (Izzy)*/, 35207 /*35207 (Ace)*/, 35209 /*35209 (Gobber)*/, 35201 /*35201 (Kezan Partygoer)*/, 35185 /*35185 (Kezan Partygoer)*/, 48719 /*48719 (KTC Waiter) - Drink Tray*/, 35186 /*35186 (Kezan Partygoer) - Fireworks*/, 35175 /*35175 (Kezan Partygoer)*/, 48721 /*48721 (KTC Waitress) - Drink Tray*/, 37203 /*37203 (Fourth And Goal Target) - Fourth and Goal: Cat's Mark Aura & Invis, Cosmetic - Freeze at Stand 0.0 sec Anim Kit*/, 34892 /*34892 (Ace) - Rolling with my Homies: Invisibility 01 - ""Ace""*/, 4076 /*4076 (Roach)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(36735, 0, 0, 0, 1, 0, '76354'), -- 36735 (Teraptor Matriarch) - Infrared = Infradead: Heat Signature Aura - Beast
(36600, 0, 0, 0, 1, 0, '68327 91298'), -- 36600 (Geargrinder Gizmo) - Infrared = Infradead: Heat Signature Aura - Humanoid (80%), Cosmetic - Sit (Lower/Upper Body - High/Low Priority) (Anim Kit)
(36719, 0, 0, 50331648, 1, 0, '76354'), -- 36719 (Pterrordax Scavenger) - Infrared = Infradead: Heat Signature Aura - Beast
(34763, 0, 0, 0, 1, 0, '76354'), -- 34763 (Daggertooth Shark) - Infrared = Infradead: Heat Signature Aura - Beast
(37683, 0, 0, 0, 1, 0, '76136'), -- 37683 (Villa Mook) - Acidic Sweat
(37602, 0, 0, 65536, 1, 0, '70268'), -- 37602 (Claims Adjuster) - 447: Claims Adjuster Quest Invis 1
(37682, 0, 0, 65536, 1, 0, '70268'), -- 37682 (447 Fireworks Bunny) - 447: Claims Adjuster Quest Invis 1
(49218, 0, 0, 0, 1, 0, '76136'), -- 49218 (Villa Mook) - Acidic Sweat
(37500, 0, 0, 0, 1, 0, ''), -- 37500 (Vinny Slapchop)
(48925, 0, 0, 0, 1, 0, '75098'), -- 48925 (Mook Disguise) - Waltz Right In: Mook Disguise
(35613, 0, 0, 0, 1, 0, ''), -- 35613 (Keensnout Potbelly)
(35609, 0, 0, 0, 1, 0, '76136'), -- 35609 (Villa Mook) - Acidic Sweat
(35234, 0, 0, 0, 1, 0, ''), -- 35234 (Hired Looter)
(39660, 0, 0, 65536, 1, 0, '10848'), -- 39660 (Spirit Healer) - Shroud of Death
(35294, 0, 0, 0, 1, 0, ''), -- 35294 (Rebellious Troll)
(35236, 0, 0, 0, 1, 0, '78087'), -- 35236 (Kezan Partygoer) - Cosmetic - Cower (Upper Body) Anim Kit
(49338, 0, 0, 0, 1, 0, '29266'), -- 49338 (KTC Waitress) - Permanent Feign Death
(37710, 0, 0, 0, 1, 0, ''), -- 37710 (Gobber)
(37708, 0, 0, 0, 1, 0, ''), -- 37708 (Izzy)
(37709, 0, 0, 0, 1, 0, ''), -- 37709 (Ace)
(35237, 0, 0, 0, 1, 0, '87259'), -- 35237 (Pirate Party Crasher) - Permanent Feign Death (Drowned Anim Kit)
(49339, 0, 0, 0, 1, 0, '29266'), -- 49339 (KTC Waiter) - Permanent Feign Death
(35238, 0, 0, 0, 1, 0, ''), -- 35238 (Kezan Partygoer)
(35235, 0, 0, 0, 1, 0, '29266'), -- 35235 (Kezan Partygoer) - Permanent Feign Death
(35213, 0, 0, 0, 1, 0, ''), -- 35213 (Izzy)
(35212, 0, 0, 0, 1, 0, ''), -- 35212 (Gobber)
(35211, 0, 0, 0, 1, 0, ''), -- 35211 (Ace)
(48805, 0, 0, 0, 1, 0, '90909'), -- 48805 (KTC Waiter) - Drink Tray
(35202, 0, 0, 0, 1, 0, ''), -- 35202 (Kezan Partygoer)
(48806, 0, 0, 0, 1, 0, '89842'), -- 48806 (KTC Waitress) - Drink Tray
(35200, 0, 0, 0, 1, 0, ''), -- 35200 (Pirate Party Crasher)
(35210, 0, 0, 0, 1, 0, ''), -- 35210 (Izzy)
(35207, 0, 0, 0, 1, 0, ''), -- 35207 (Ace)
(35209, 0, 0, 0, 1, 0, ''), -- 35209 (Gobber)
(35201, 0, 0, 1, 1, 0, ''), -- 35201 (Kezan Partygoer)
(35185, 0, 0, 50331648, 1, 0, ''), -- 35185 (Kezan Partygoer)
(48719, 0, 0, 0, 1, 0, '90909'), -- 48719 (KTC Waiter) - Drink Tray
(35186, 0, 0, 0, 1, 0, '75048'), -- 35186 (Kezan Partygoer) - Fireworks
(35175, 0, 0, 0, 1, 0, ''), -- 35175 (Kezan Partygoer)
(48721, 0, 0, 0, 1, 0, '89842'), -- 48721 (KTC Waitress) - Drink Tray
(37203, 0, 0, 50397184, 1, 0, '70086 89476'), -- 37203 (Fourth And Goal Target) - Fourth and Goal: Cat's Mark Aura & Invis, Cosmetic - Freeze at Stand 0.0 sec Anim Kit
(34892, 0, 0, 65536, 1, 0, '66403'), -- 34892 (Ace) - Rolling with my Homies: Invisibility 01 - ""Ace""
(4076, 0, 0, 0, 1, 0, ''); -- 4076 (Roach)

UPDATE `creature_template_addon` SET `auras`='91298' WHERE `entry`=48961; -- 48961 (Kezan Socialite)
UPDATE `creature_template_addon` SET `auras`='71423 89125' WHERE `entry`=48519; -- 48519 (Micro Mechachicken)
UPDATE `creature_template_addon` SET `mount`=29681 WHERE `entry`=35222; -- 35222 (Trade Prince Gallywix)
UPDATE `creature_template_addon` SET `auras`='45111' WHERE `entry`=34830; -- 34830 (Defiant Troll)
UPDATE `creature_model_info` SET `BoundingRadius`=0.7, `CombatReach`=0.875 WHERE `DisplayID`=5560;
UPDATE `creature_model_info` SET `BoundingRadius`=0.145, `CombatReach`=0.5 WHERE `DisplayID`=36372;
UPDATE `npc_trainer` SET `MoneyCost`=48, `ReqLevel`=0 WHERE (`ID`=34695 AND `SpellID`=73899); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=78 WHERE (`ID`=34695 AND `SpellID`=8075); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=114 WHERE (`ID`=34695 AND `SpellID`=8042); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=48 WHERE (`ID`=34695 AND `SpellID`=73899); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=78 WHERE (`ID`=34695 AND `SpellID`=8075); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=114 WHERE (`ID`=34695 AND `SpellID`=8042); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=48 WHERE (`ID`=34695 AND `SpellID`=73899); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=78 WHERE (`ID`=34695 AND `SpellID`=8075); -- Maxx Avalanche
UPDATE `npc_trainer` SET `MoneyCost`=114 WHERE (`ID`=34695 AND `SpellID`=8042); -- Maxx Avalanche

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=35237 AND `ID`=2) OR (`CreatureID`=35200 AND `ID`=2) OR (`CreatureID`=35186 AND `ID`=3) OR (`CreatureID`=35175 AND `ID`=3) OR (`CreatureID`=35175 AND `ID`=2) OR (`CreatureID`=35186 AND `ID`=2) OR (`CreatureID`=35186 AND `ID`=1) OR (`CreatureID`=35063 AND `ID`=4) OR (`CreatureID`=35063 AND `ID`=3) OR (`CreatureID`=35063 AND `ID`=2) OR (`CreatureID`=35075 AND `ID`=4) OR (`CreatureID`=35063 AND `ID`=1) OR (`CreatureID`=35075 AND `ID`=3) OR (`CreatureID`=35075 AND `ID`=2) OR (`CreatureID`=34830 AND `ID`=2) OR (`CreatureID`=35075 AND `ID`=1) OR (`CreatureID`=34830 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `ItemID2`, `ItemID3`) VALUES
(35237, 2, 2704, 0, 0), -- Pirate Party Crasher
(35200, 2, 2704, 0, 0), -- Pirate Party Crasher
(35186, 3, 2718, 0, 0), -- Kezan Partygoer
(35175, 3, 2718, 0, 0), -- Kezan Partygoer
(35175, 2, 9701, 0, 0), -- Kezan Partygoer
(35186, 2, 2202, 0, 0), -- Kezan Partygoer
(35186, 1, 9701, 0, 0), -- Kezan Partygoer
(35063, 4, 31824, 0, 0), -- Kezan Citizen
(35063, 3, 1903, 0, 0), -- Kezan Citizen
(35063, 2, 2704, 0, 0), -- Kezan Citizen
(35075, 4, 2704, 0, 0), -- Kezan Citizen
(35063, 1, 1910, 0, 0), -- Kezan Citizen
(35075, 3, 3346, 0, 0), -- Kezan Citizen
(35075, 2, 31824, 0, 0), -- Kezan Citizen
(34830, 2, 2704, 0, 0), -- Defiant Troll
(35075, 1, 1910, 0, 0), -- Kezan Citizen
(34830, 1, 2202, 0, 0); -- Defiant Troll

DELETE FROM `vehicle_template_accessory` WHERE `entry`IN (37598,48806,48805,48719,48721,34830);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(37598, 37599, 3, 1, 'Gasbot - Gasbot Gas Target', 8, 0), -- Gasbot - Gasbot Gas Target
(37598, 37599, 2, 1, 'Gasbot - Gasbot Gas Target', 8, 0), -- Gasbot - Gasbot Gas Target
(37598, 37599, 1, 1, 'Gasbot - Gasbot Gas Target', 8, 0), -- Gasbot - Gasbot Gas Target
(37598, 37599, 0, 1, 'Gasbot - Gasbot Gas Target', 8, 0), -- Gasbot - Gasbot Gas Target
(48806, 48343, 4, 1, 'KTC Waitress - Goblin Cocktail', 8, 0), -- KTC Waitress - Goblin Cocktail
(48806, 48342, 3, 1, 'KTC Waitress - Goblin Cocktail', 8, 0), -- KTC Waitress - Goblin Cocktail
(48806, 48341, 2, 1, 'KTC Waitress - Goblin Cocktail', 8, 0), -- KTC Waitress - Goblin Cocktail
(48806, 48341, 1, 1, 'KTC Waitress - Goblin Cocktail', 8, 0), -- KTC Waitress - Goblin Cocktail
(48806, 48340, 0, 1, 'KTC Waitress - Drink Tray', 8, 0), -- KTC Waitress - Drink Tray
(48805, 48343, 4, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48805, 48342, 3, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48805, 48341, 2, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48805, 48341, 1, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48805, 48340, 0, 1, 'KTC Waiter - Drink Tray', 8, 0), -- KTC Waiter - Drink Tray
(48719, 48343, 4, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48719, 48342, 3, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48719, 48341, 2, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48719, 48341, 1, 1, 'KTC Waiter - Goblin Cocktail', 8, 0), -- KTC Waiter - Goblin Cocktail
(48719, 48340, 0, 1, 'KTC Waiter - Drink Tray', 8, 0), -- KTC Waiter - Drink Tray
(48721, 48342, 3, 1, 'KTC Waitress - Goblin Cocktail', 8, 0), -- KTC Waitress - Goblin Cocktail
(48721, 48341, 2, 1, 'KTC Waitress - Goblin Cocktail', 8, 0), -- KTC Waitress - Goblin Cocktail
(48721, 48341, 1, 1, 'KTC Waitress - Goblin Cocktail', 8, 0), -- KTC Waitress - Goblin Cocktail
(48721, 48340, 0, 1, 'KTC Waitress - Drink Tray', 8, 0), -- KTC Waitress - Drink Tray
(48721, 48343, 4, 1, 'KTC Waitress - Goblin Cocktail', 8, 0); -- KTC Waitress - Goblin Cocktail

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (37598,48806,48805,48719,48721,34830);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`,`cast_flags`,`user_type`) VALUES
(37598, 46598, 1, 0),
(48806, 46598, 1, 0),
(48805, 46598, 1, 0),
(48719, 46598, 1, 0),
(48721, 46598, 1, 0),
(34830, 66306, 1, 0);

DELETE FROM `gossip_menu` WHERE (`MenuID`=12674 AND `TextID`=17818) OR (`MenuID`=10685 AND `TextID`=14601) OR (`MenuID`=10683 AND `TextID`=14805) OR (`MenuID`=10681 AND `TextID`=14595) OR (`MenuID`=10686 AND `TextID`=14811) OR (`MenuID`=12494 AND `TextID`=17576) OR (`MenuID`=12469 AND `TextID`=17541) OR (`MenuID`=12470 AND `TextID`=17542) OR (`MenuID`=12468 AND `TextID`=17540) OR (`MenuID`=12493 AND `TextID`=17575) OR (`MenuID`=10684 AND `TextID`=14808) OR (`MenuID`=10595 AND `TextID`=14657) OR (`MenuID`=10653 AND `TextID`=14762) OR (`MenuID`=12492 AND `TextID`=17574) OR (`MenuID`=10636 AND `TextID`=14732) OR (`MenuID`=12491 AND `TextID`=17573) OR (`MenuID`=12476 AND `TextID`=17552) OR (`MenuID`=10821 AND `TextID`=15000) OR (`MenuID`=10612 AND `TextID`=14683) OR (`MenuID`=12490 AND `TextID`=17572) OR (`MenuID`=10632 AND `TextID`=14725) OR (`MenuID`=10634 AND `TextID`=14727) OR (`MenuID`=10633 AND `TextID`=14726) OR (`MenuID`=10547 AND `TextID`=14590) OR (`MenuID`=10623 AND `TextID`=14705) OR (`MenuID`=10624 AND `TextID`=14703) OR (`MenuID`=10619 AND `TextID`=14698) OR (`MenuID`=10620 AND `TextID`=14697) OR (`MenuID`=10621 AND `TextID`=14702) OR (`MenuID`=10622 AND `TextID`=14700) OR (`MenuID`=10618 AND `TextID`=14695) OR (`MenuID`=10611 AND `TextID`=14693) OR (`MenuID`=11358 AND `TextID`=15829) OR (`MenuID`=10884 AND `TextID`=17551) OR (`MenuID`=10884 AND `TextID`=15121) OR (`MenuID`=10620 AND `TextID`=14699) OR (`MenuID`=11360 AND `TextID`=15831) OR (`MenuID`=10622 AND `TextID`=14701) OR (`MenuID`=11346 AND `TextID`=15807) OR (`MenuID`=12475 AND `TextID`=17549) OR (`MenuID`=10613 AND `TextID`=14684) OR (`MenuID`=10675 AND `TextID`=14796);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(12674, 17818), -- 35222 (Trade Prince Gallywix)
(10685, 14601), -- 34692 (Sister Goldskimmer)
(10683, 14805), -- 34689 (Fizz Lighter)
(10681, 14595), -- 34696 (Evol Fingers)
(10686, 14811), -- 34693 (Slinky Sharpshiv)
(12494, 17576), -- 34668 (Sassy Hardwrench)
(12469, 17541), -- 37708 (Izzy)
(12470, 17542), -- 37710 (Gobber)
(12468, 17540), -- 37709 (Ace)
(12493, 17575), -- 34668 (Sassy Hardwrench)
(10684, 14808), -- 34695 (Maxx Avalanche)
(10595, 14657), -- 34874 (Megs Dreadshredder)
(10653, 14762), -- 34872 (Foreman Dampwick)
(12492, 17574), -- 34668 (Sassy Hardwrench)
(10636, 14732), -- 35238 (Kezan Partygoer)
(12491, 17573), -- 34668 (Sassy Hardwrench)
(12476, 17552), -- 49150 (Subject Nine)
(10821, 15000), -- 34697 (Warrior-Matic NX-01)
(10612, 14683), -- 35054 (Chip Endale)
(12490, 17572), -- 34668 (Sassy Hardwrench)
(10632, 14725), -- 35207 (Ace)
(10634, 14727), -- 35210 (Izzy)
(10633, 14726), -- 35209 (Gobber)
(10547, 14590), -- 34668 (Sassy Hardwrench)
(10623, 14705), -- 35130 (Missa Spekkies)
(10624, 14703), -- 35130 (Missa Spekkies)
(10619, 14698), -- 35126 (Gappy Silvertooth)
(10620, 14697), -- 35126 (Gappy Silvertooth)
(10621, 14702), -- 35128 (Szabo)
(10622, 14700), -- 35128 (Szabo)
(10618, 14695), -- 35120 (FBoK Bank Teller)
(10611, 14693), -- 35053 (Candy Cane)
(11358, 15829), -- 34957 (Ace)
(10884, 17551), -- 37106 (Coach Crosscheck)
(10884, 15121), -- 37106 (Coach Crosscheck)
(10620, 14699), -- 35126 (Gappy Silvertooth)
(11360, 15831), -- 34959 (Izzy)
(10622, 14701), -- 35128 (Szabo)
(11346, 15807), -- 35222 (Trade Prince Gallywix)
(12475, 17549), -- 48961 (Kezan Socialite)
(10613, 14684), -- 34872 (Foreman Dampwick)
(10675, 14796); -- 34673 (Bamm Megabomb)

UPDATE `creature_template` SET `speed_run`=1.190476 WHERE `entry`=35234; -- Hired Looter
UPDATE `creature_template` SET `unit_flags`=33280 WHERE `entry`=35202; -- Kezan Partygoer
UPDATE `creature_template` SET `npcflag`=0, `speed_run`=1.142857 WHERE `entry`=35200; -- Pirate Party Crasher
UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry`=24110; -- ELM General Purpose Bunny Large
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=35175; -- Kezan Partygoer
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=37203; -- Fourth And Goal Target
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.8571429 WHERE `entry`=40077; -- Mata
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.8571429 WHERE `entry`=40076; -- Rima
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.8571429 WHERE `entry`=40073; -- Funafuti
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.8571429 WHERE `entry`=40074; -- Atiu
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=0.8571429 WHERE `entry`=40075; -- Avarua
UPDATE `creature_template` SET `speed_walk`=1, `speed_run`=1.142857 WHERE `entry`=40071; -- Julia Scrabblewrench
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry` IN (34835,34876,34877,34878);
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=34865; -- Tunneling Worm
UPDATE `creature_template` SET `npcflag`=16777216 WHERE `entry`=34830; -- Tunneling Worm

DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (35239));
UPDATE `creature_template_addon` SET `emote`=233  WHERE `entry` IN (35239); -- Troll Slave

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+75,@CGUID+51,@CGUID+57,@CGUID+53,@CGUID+70,@CGUID+60,@CGUID+47,@CGUID+50,@CGUID+3,@CGUID+4);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(@CGUID+75, 0, 0, 0, 1, 69, ''), -- Troll Slave -- 147035
(@CGUID+51, 0, 0, 0, 1, 69, ''), -- Troll Slave
(@CGUID+57, 0, 0, 0, 1, 69, ''), -- Troll Slave
(@CGUID+53, 0, 0, 0, 1, 69, ''), -- Troll Slave
(@CGUID+70, 0, 0, 0, 1, 69, ''), -- Troll Slave
(@CGUID+60, 0, 0, 0, 1, 69, ''), -- Troll Slave
(@CGUID+47, 0, 0, 0, 1, 69, ''), -- Troll Slave
(@CGUID+50, 0, 0, 0, 1, 69, ''), -- Troll Slave
(@CGUID+3, 0, 0, 0, 1, 375, '76136'), -- Troll Slave
(@CGUID+4, 0, 0, 0, 1, 375, '76136'); -- Troll Slave

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3483000,3483001,3483002,3483003,3483004) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(3483001,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defiant Troll - actionlist - emote stat dance'"),
(3483002,9,0,0,0,0,100,0,0,0,0,0,0,11,62248,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defiant Troll - actionlist - cast sleep'"),
(3483003,9,0,0,0,0,100,0,0,0,0,0,0,17,7,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defiant Troll - actionlist - emote stat eat'"),
(3483004,9,0,0,0,0,100,0,0,0,0,0,0,17,455,0,0,0,0,0,1,0,0,0,0,0,0,0,"Defiant Troll - actionlist - emote stat sit'"),
(3483000, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0,0, 83, 16777216, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Defiant Troll - actionlist - remove npc_spellclick_spells flag"),
(3483000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0,0, 28, 45111, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Defiant Troll - actionlist - remove Enrage (45111)"),
(3483000, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0,0, 28, 62248, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Defiant Troll - actionlist - remove sleep (62248)"),
(3483000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0,0, 17, 26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Defiant Troll - actionlist - set emote state (26)"),
(3483000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0,0, 33, 34830, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, "Defiant Troll - actionlist - give quest credit (34830)"),
(3483000, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0,0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Defiant Troll - actionlist - say text 0"),
(3483000, 9, 6, 0, 0, 0, 100, 0, 2000, 2000,0, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 30, 0, 0, "Defiant Troll - actionlist - set random movement"),
(3483000, 9, 7, 0, 0, 0, 100, 0, 4000, 4000,0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Defiant Troll - actionlist - despawn");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup`=34830 AND `SourceEntry`=66306;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`Comment`) VALUES
(18,34830,66306,0,9,0,14069,0,0,0,'Required quest active for spellclick');

UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+795;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+798;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+801;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+803;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+805;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+806;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+808;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+809;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+810;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+811;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+815;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+816;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+821;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+822;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+823;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+824;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+832;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+835;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+836;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+837;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+838;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+840;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+844;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+848;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+849;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+851;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+852;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+853;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+855;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+856;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+860;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+862;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+863;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+865;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+866;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+869;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+870;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+871;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+874;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+876;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+877;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+878;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+879;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+881;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+882;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+883;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+892;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+894;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+895;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+897;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+898;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+899;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+900;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+901;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+905;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+907;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+908;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+912;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+913;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+914;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+919;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+920;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+922;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+925;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+927;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+928;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+929;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+930;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+932;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+933;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+934;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+936;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+937;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+939;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+940;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+941;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+942;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+944;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+945;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+946;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+948;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+949;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+950;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+952;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+953;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+954;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+955;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+956;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+958;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+960;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+961;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+962;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+963;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+964;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+965;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+967;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+969;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+970;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+971;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+972;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+973;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+974;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+975;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+976;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+977;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+978;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+979;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+980;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+981;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+982;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+983;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+985;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+986;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+988;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+989;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+990;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+991;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+993;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+994;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+995;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+996;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+997;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+998;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+999;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1000;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1001;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1002;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1004;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1005;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1006;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1009;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1010;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1011;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1012;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1013;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1014;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1015;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1017;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1018;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1019;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1020;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1022;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1023;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1025;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1026;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1027;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1028;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1029;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1031;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1034;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1035;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1036;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1037;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1038;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1039;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1041;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1042;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1043;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1044;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1045;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1047;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1061;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1063;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1064;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1067;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1070;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1071;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1072;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1073;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1074;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1075;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1076;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1077;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1078;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1079;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1081;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1082;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1083;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1084;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1095;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1096;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1097;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1098;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1099;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1101;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1103;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1104;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1108;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1113;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1116;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1118;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1122;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1125;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1126;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1129;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1130;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1132;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1133;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1134;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1137;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1138;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1140;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1142;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1143;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1144;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1145;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1147;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1148;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1149;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1153;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1154;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1156;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1158;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1160;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1162;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1166;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1167;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1168;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1170;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1171;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1174;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1177;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1179;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1180;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1181;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1183;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1185;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1186;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1188;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1191;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1193;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1194;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1195;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1197;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1198;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1200;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1202;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1203;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1206;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1211;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1214;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1216;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1217;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1219;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1223;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1224;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1226;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1228;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1229;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1231;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1248;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1086;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1087;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1089;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1102;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1107;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1110;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1114;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1117;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1119;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1120;
UPDATE `creature` SET `modelid`=29667 WHERE `guid`=@CGUID+1131;
UPDATE `creature` SET `modelid`=29668 WHERE `guid`=@CGUID+1141;
UPDATE `creature` SET `modelid`=29669 WHERE `guid`=@CGUID+1151;
UPDATE `creature` SET `modelid`=29630 WHERE `guid`=@CGUID+1157;
UPDATE `creature` SET `modelid`=29631 WHERE `guid`=@CGUID+1161;
UPDATE `creature` SET `modelid`=29632 WHERE `guid`=@CGUID+1163;
UPDATE `creature` SET `modelid`=29633 WHERE `guid`=@CGUID+1164;
UPDATE `creature` SET `modelid`=29662 WHERE `guid`=@CGUID+1165;
UPDATE `creature` SET `modelid`=29663 WHERE `guid`=@CGUID+1169;
UPDATE `creature` SET `modelid`=29664 WHERE `guid`=@CGUID+1176;
UPDATE `creature` SET `modelid`=29665 WHERE `guid`=@CGUID+1178;
UPDATE `creature` SET `modelid`=29666 WHERE `guid`=@CGUID+1187;
