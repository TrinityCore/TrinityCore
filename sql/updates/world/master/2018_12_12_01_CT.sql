DELETE FROM `gameobject_template_addon` WHERE `entry` IN (284419 /*Treasure Chest*/, 273193 /*Prickly Plum*/, 296583 /*Navarro's Flask*/, 296588 /*Portrait of Commander Martens*/, 284420 /*Treasure Chest*/, 293315 /*Zandalari Hut*/, 290770 /*Treasure Chest*/, 282667 /*Mysterious Trashpile*/, 276460 /*Shrine of Thunder*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(284419, 0, 278528), -- Treasure Chest
(273193, 0, 2113540), -- Prickly Plum
(296583, 0, 2113568), -- Navarro's Flask
(296588, 0, 2113568), -- Portrait of Commander Martens
(284420, 0, 278528), -- Treasure Chest
(293315, 0, 1048608), -- Zandalari Hut
(290770, 0, 278528), -- Treasure Chest
(282667, 0, 262144), -- Mysterious Trashpile
(276460, 0, 262144); -- Shrine of Thunder

DELETE FROM `scene_template` WHERE (`SceneId`=1937 AND `ScriptPackageID`=2073) OR (`SceneId`=2000 AND `ScriptPackageID`=2199) OR (`SceneId`=1996 AND `ScriptPackageID`=2194) OR (`SceneId`=1995 AND `ScriptPackageID`=2193) OR (`SceneId`=1993 AND `ScriptPackageID`=2189);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(1937, 17, 2073),
(2000, 27, 2199),
(1996, 27, 2194),
(1995, 27, 2193),
(1993, 27, 2189);


DELETE FROM `quest_offer_reward` WHERE `ID` IN (47716 /*-Unknown-*/, 48896 /*-Unknown-*/, 47874 /*-Unknown-*/, 50913 /*-Unknown-*/, 48996 /*-Unknown-*/, 48889 /*-Unknown-*/, 49005 /*-Unknown-*/, 48988 /*-Unknown-*/, 48987 /*-Unknown-*/, 48715 /*-Unknown-*/, 48894 /*-Unknown-*/, 48888 /*-Unknown-*/, 48887 /*-Unknown-*/, 48991 /*-Unknown-*/, 48992 /*-Unknown-*/, 48993 /*-Unknown-*/, 48895 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(47716, 1, 0, 0, 0, 0, 0, 0, 0, 'Serrik is weak from poison. We\'re running out of time.', 27843), -- -Unknown-
(48896, 1, 0, 0, 0, 0, 0, 0, 0, 'It\'s clear dat Jakra\'zet won\'t stop until I\'m dead.', 27843), -- -Unknown-
(47874, 1, 0, 0, 0, 0, 0, 0, 0, 'Talanji was right not to trust de general. If he succeeds in finding de weapon, our great city will fall.', 27843), -- -Unknown-
(50913, 1, 0, 0, 0, 0, 0, 0, 0, 'If at any time you require my gift, commune at a shrine built in my honor to receive my boon.', 27843), -- -Unknown-
(48996, 1, 0, 0, 0, 0, 0, 0, 0, 'You wield my gift well, $n. \n\nNow that my power has returned, I can heal the minds of my children.', 27843), -- -Unknown-
(48889, 1, 0, 0, 0, 0, 0, 0, 0, 'I seek your help, $n.', 27843), -- -Unknown-
(49005, 1, 0, 0, 0, 0, 0, 0, 0, 'You did what was right. Memories like those have no place in dis world.', 27843), -- -Unknown-
(48988, 1, 0, 0, 0, 0, 0, 0, 0, 'It is as I feared. De loa\'s own memories have been taken from him.', 27843), -- -Unknown-
(48987, 1, 0, 0, 0, 0, 0, 0, 0, 'Who are you? Have we met before?', 27843), -- -Unknown-
(48715, 1, 0, 0, 0, 0, 0, 0, 0, 'Dis is Rakera. I have no doubt. But for some reason, she does not remember me... or herself, it would seem...', 27843), -- -Unknown-
(48894, 1, 0, 0, 0, 0, 0, 0, 0, 'You have proven worthy of entering our temple, Akunda.', 27843), -- -Unknown-
(48888, 1, 0, 0, 0, 0, 0, 0, 0, 'De spring is a gift from de loa and must be preserved at all costs.', 27843), -- -Unknown-
(48887, 1, 0, 0, 0, 0, 0, 0, 0, 'I can tell you found success. You are at peace.', 27843), -- -Unknown-
(48991, 1, 0, 0, 0, 0, 0, 0, 0, 'Akunda smiles upon you. He knows what you have done here today.', 27843), -- -Unknown-
(48992, 1, 0, 0, 0, 0, 0, 0, 0, 'Dese bones still resonate with power.', 27843), -- -Unknown-
(48993, 1, 0, 0, 0, 0, 0, 0, 0, 'Yes... dis will work well.', 27843), -- -Unknown-
(48895, 1, 0, 0, 0, 0, 0, 0, 0, 'Dis is a generous offering, but a gift alone isn\'t enough to enter our temple. \n\nRedemption can\'t be bought, it must be earned. \n\nLucky for you, dere is much work to be done.', 27843); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=47716 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47716 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47716 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=47716 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48896 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=48896 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48896 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48896 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48896 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47874 AND `BlobIndex`=3 AND `Idx1`=1) OR (`QuestID`=47874 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50913 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50913 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50913 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48996 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48996 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48996 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48889 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48889 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48889 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49005 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49005 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49005 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49005 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48988 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48988 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48988 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48987 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48987 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48715 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48715 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48715 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48894 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48894 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48894 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=48894 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48888 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48888 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48888 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48887 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48887 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48887 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48887 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49040 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49040 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48991 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48991 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48991 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48992 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48992 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48992 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48993 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48993 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=48993 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48993 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48895 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48895 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(47716, 0, 3, 32, 0, 0, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(47716, 0, 2, 0, 291182, 124769, 1642, 864, 0, 0, 0, 0, 1525187, 0, 27843), -- -Unknown-
(47716, 1, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1470295, 0, 27843), -- -Unknown-
(47716, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1470295, 0, 27843), -- -Unknown-
(48896, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1423493, 0, 27843), -- -Unknown-
(48896, 0, 3, 2, 293816, 128209, 1642, 864, 0, 0, 0, 0, 1397141, 0, 27843), -- -Unknown-
(48896, 0, 2, 1, 293241, 127742, 1642, 864, 0, 0, 0, 0, 1391378, 0, 27843), -- -Unknown-
(48896, 0, 1, 0, 293240, 126235, 1642, 864, 0, 0, 0, 0, 1396883, 0, 27843), -- -Unknown-
(48896, 0, 0, -1, 0, 0, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(47874, 3, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1423354, 0, 27843), -- -Unknown-
(47874, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1423493, 0, 27843), -- -Unknown-
(50913, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1396680, 0, 27843), -- -Unknown-
(50913, 0, 1, 0, 334264, 290773, 1642, 864, 0, 0, 0, 0, 1483293, 0, 27843), -- -Unknown-
(50913, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1396680, 0, 27843), -- -Unknown-
(48996, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1522104, 0, 27843), -- -Unknown-
(48996, 0, 1, 0, 293623, 128147, 1642, 864, 0, 0, 0, 0, 1396676, 0, 27843), -- -Unknown-
(48996, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1396680, 0, 27843), -- -Unknown-
(48889, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1395436, 0, 27843), -- -Unknown-
(48889, 0, 1, 0, 293281, 138413, 1642, 864, 0, 0, 0, 0, 1522105, 0, 27843), -- -Unknown-
(48889, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1522104, 0, 27843), -- -Unknown-
(49005, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1395436, 0, 27843), -- -Unknown-
(49005, 0, 2, 1, 336620, 138199, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49005, 0, 1, 0, 293599, 138198, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49005, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1395436, 0, 27843), -- -Unknown-
(48988, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1395436, 0, 27843), -- -Unknown-
(48988, 0, 1, 0, 293542, 138412, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48988, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1395436, 0, 27843), -- -Unknown-
(48987, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1394848, 0, 27843), -- -Unknown-
(48987, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1395436, 0, 27843), -- -Unknown-
(48715, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1422076, 0, 27843), -- -Unknown-
(48715, 0, 1, 0, 293523, 130570, 1642, 864, 0, 0, 0, 0, 1422463, 0, 27843), -- -Unknown-
(48715, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1422558, 0, 27843), -- -Unknown-
(48894, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48894, 0, 2, 0, 293438, 127992, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48894, 1, 1, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1394665, 0, 27843), -- -Unknown-
(48894, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1394807, 0, 27843), -- -Unknown-
(48888, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48888, 0, 1, 0, 293385, 134718, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(48888, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48887, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48887, 0, 2, 1, 336508, 138292, 1642, 864, 0, 0, 0, 0, 1522237, 0, 27843), -- -Unknown-
(48887, 0, 1, 0, 293348, 127840, 1642, 864, 0, 0, 0, 0, 1522237, 0, 27843), -- -Unknown-
(48887, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(49040, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1391360, 0, 27843), -- -Unknown-
(49040, 0, 0, -1, 0, 0, 1642, 862, 0, 0, 0, 0, 1391852, 0, 27843), -- -Unknown-
(48991, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48991, 0, 1, 0, 293649, 133565, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48991, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48992, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48992, 0, 1, 0, 293693, 153028, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48992, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48993, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48993, 1, 2, 0, 293695, 153029, 1642, 864, 0, 2, 0, 61615, 0, 0, 27843), -- -Unknown-
(48993, 0, 1, 0, 293695, 153029, 1642, 864, 0, 0, 0, 61616, 1463794, 0, 27843), -- -Unknown-
(48993, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843), -- -Unknown-
(48895, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1391360, 0, 27843), -- -Unknown-
(48895, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1390336, 0, 27843); -- -Unknown-

UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=47251 AND `BlobIndex`=0 AND `Idx1`=0); -- Interesting Times
DELETE FROM `quest_poi_points` WHERE (`QuestID`=47716 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47716 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47716 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47716 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48896 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=48896 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48896 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48896 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48896 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47874 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47874 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50913 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50913 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50913 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48996 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48996 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48996 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48889 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48889 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48889 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49005 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49005 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=49005 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=49005 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=49005 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=49005 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=49005 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49005 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=49005 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=49005 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=49005 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=49005 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49005 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48988 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48988 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48988 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48987 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48987 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48715 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48715 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48715 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48894 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48894 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48894 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48894 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48888 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48888 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48888 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48887 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48887 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48887 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48887 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49040 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49040 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48991 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48991 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48991 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48992 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48992 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48992 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48992 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48992 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48992 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48992 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48992 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48993 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48993 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48993 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48993 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48895 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48895 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(47716, 3, 0, 604, 3437, 27843), -- -Unknown-
(47716, 2, 0, 898, 3521, 27843), -- -Unknown-
(47716, 1, 0, 901, 3483, 27843), -- -Unknown-
(47716, 0, 0, 901, 3483, 27843), -- -Unknown-
(48896, 4, 0, 282, 3096, 27843), -- -Unknown-
(48896, 3, 0, 616, 3449, 27843), -- -Unknown-
(48896, 2, 0, 282, 3102, 27843), -- -Unknown-
(48896, 1, 0, 277, 3102, 27843), -- -Unknown-
(48896, 0, 0, 614, 3458, 27843), -- -Unknown-
(47874, 1, 0, 175, 3054, 27843), -- -Unknown-
(47874, 0, 0, 282, 3096, 27843), -- -Unknown-
(50913, 2, 0, 175, 3066, 27843), -- -Unknown-
(50913, 1, 0, 147, 3066, 27843), -- -Unknown-
(50913, 0, 0, 175, 3066, 27843), -- -Unknown-
(48996, 2, 0, 709, 3132, 27843), -- -Unknown-
(48996, 1, 0, 193, 3066, 27843), -- -Unknown-
(48996, 0, 0, 175, 3066, 27843), -- -Unknown-
(48889, 2, 0, 760, 3077, 27843), -- -Unknown-
(48889, 1, 0, 718, 3124, 27843), -- -Unknown-
(48889, 0, 0, 709, 3132, 27843), -- -Unknown-
(49005, 3, 0, 760, 3077, 27843), -- -Unknown-
(49005, 2, 5, 790, 3082, 27843), -- -Unknown-
(49005, 2, 4, 807, 3104, 27843), -- -Unknown-
(49005, 2, 3, 909, 3167, 27843), -- -Unknown-
(49005, 2, 2, 1019, 2998, 27843), -- -Unknown-
(49005, 2, 1, 995, 2957, 27843), -- -Unknown-
(49005, 2, 0, 896, 2925, 27843), -- -Unknown-
(49005, 1, 4, 875, 2954, 27843), -- -Unknown-
(49005, 1, 3, 775, 3107, 27843), -- -Unknown-
(49005, 1, 2, 893, 3164, 27843), -- -Unknown-
(49005, 1, 1, 1011, 2975, 27843), -- -Unknown-
(49005, 1, 0, 925, 2951, 27843), -- -Unknown-
(49005, 0, 0, 760, 3077, 27843), -- -Unknown-
(48988, 2, 0, 760, 3077, 27843), -- -Unknown-
(48988, 1, 7, 785, 3049, 27843), -- -Unknown-
(48988, 1, 6, 793, 3089, 27843), -- -Unknown-
(48988, 1, 5, 871, 3125, 27843), -- -Unknown-
(48988, 1, 4, 939, 3093, 27843), -- -Unknown-
(48988, 1, 3, 959, 3080, 27843), -- -Unknown-
(48988, 1, 2, 1012, 2990, 27843), -- -Unknown-
(48988, 1, 1, 944, 2959, 27843), -- -Unknown-
(48988, 1, 0, 886, 2948, 27843), -- -Unknown-
(48988, 0, 0, 760, 3077, 27843), -- -Unknown-
(48987, 1, 0, 189, 3040, 27843), -- -Unknown-
(48987, 0, 0, 760, 3077, 27843), -- -Unknown-
(48715, 2, 0, 241, 3068, 27843), -- -Unknown-
(48715, 1, 0, 175, 3037, 27843), -- -Unknown-
(48715, 0, 0, 175, 3037, 27843), -- -Unknown-
(48894, 3, 0, 237, 3067, 27843), -- -Unknown-
(48894, 2, 0, 237, 3067, 27843), -- -Unknown-
(48894, 1, 0, 237, 3067, 27843), -- -Unknown-
(48894, 0, 0, 150, 3067, 27843), -- -Unknown-
(48888, 2, 0, 237, 3067, 27843), -- -Unknown-
(48888, 1, 11, 467, 3057, 27843), -- -Unknown-
(48888, 1, 10, 346, 3123, 27843), -- -Unknown-
(48888, 1, 9, 309, 3223, 27843), -- -Unknown-
(48888, 1, 8, 355, 3316, 27843), -- -Unknown-
(48888, 1, 7, 422, 3335, 27843), -- -Unknown-
(48888, 1, 6, 476, 3335, 27843), -- -Unknown-
(48888, 1, 5, 548, 3300, 27843), -- -Unknown-
(48888, 1, 4, 597, 3245, 27843), -- -Unknown-
(48888, 1, 3, 614, 3174, 27843), -- -Unknown-
(48888, 1, 2, 613, 3133, 27843), -- -Unknown-
(48888, 1, 1, 597, 3063, 27843), -- -Unknown-
(48888, 1, 0, 553, 3042, 27843), -- -Unknown-
(48888, 0, 0, 237, 3067, 27843), -- -Unknown-
(48887, 3, 0, 237, 3066, 27843), -- -Unknown-
(48887, 2, 0, 553, 3135, 27843), -- -Unknown-
(48887, 1, 0, 553, 3135, 27843), -- -Unknown-
(48887, 0, 0, 237, 3066, 27843), -- -Unknown-
(49040, 1, 0, 283, 3096, 27843), -- -Unknown-
(49040, 0, 0, -621, 1075, 27843), -- -Unknown-
(48991, 2, 0, 237, 3066, 27843), -- -Unknown-
(48991, 1, 9, 423, 2887, 27843), -- -Unknown-
(48991, 1, 8, 347, 2929, 27843), -- -Unknown-
(48991, 1, 7, 296, 2971, 27843), -- -Unknown-
(48991, 1, 6, 300, 3031, 27843), -- -Unknown-
(48991, 1, 5, 342, 3056, 27843), -- -Unknown-
(48991, 1, 4, 404, 3055, 27843), -- -Unknown-
(48991, 1, 3, 440, 3041, 27843), -- -Unknown-
(48991, 1, 2, 533, 2974, 27843), -- -Unknown-
(48991, 1, 1, 549, 2902, 27843), -- -Unknown-
(48991, 1, 0, 505, 2872, 27843), -- -Unknown-
(48991, 0, 0, 237, 3066, 27843), -- -Unknown-
(48992, 2, 0, 237, 3066, 27843), -- -Unknown-
(48992, 1, 5, 349, 2944, 27843), -- -Unknown-
(48992, 1, 4, 308, 3006, 27843), -- -Unknown-
(48992, 1, 3, 394, 3033, 27843), -- -Unknown-
(48992, 1, 2, 422, 3013, 27843), -- -Unknown-
(48992, 1, 1, 532, 2927, 27843), -- -Unknown-
(48992, 1, 0, 482, 2880, 27843), -- -Unknown-
(48992, 0, 0, 237, 3066, 27843), -- -Unknown-
(48993, 3, 0, 237, 3066, 27843), -- -Unknown-
(48993, 2, 0, 416, 2941, 27843), -- -Unknown-
(48993, 1, 0, 547, 2866, 27843), -- -Unknown-
(48993, 0, 0, 237, 3066, 27843), -- -Unknown-
(48895, 1, 0, 285, 3091, 27843), -- -Unknown-
(48895, 0, 0, 237, 3067, 27843); -- -Unknown-

DELETE FROM `quest_details` WHERE `ID` IN (47716 /*-Unknown-*/, 48896 /*-Unknown-*/, 47874 /*-Unknown-*/, 50913 /*-Unknown-*/, 48996 /*-Unknown-*/, 48889 /*-Unknown-*/, 49005 /*-Unknown-*/, 48988 /*-Unknown-*/, 47251 /*Interesting Times*/, 48987 /*-Unknown-*/, 48715 /*-Unknown-*/, 48894 /*-Unknown-*/, 48888 /*-Unknown-*/, 48887 /*-Unknown-*/, 49040 /*-Unknown-*/, 48991 /*-Unknown-*/, 48992 /*-Unknown-*/, 48993 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47716, 1, 1, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(48896, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47874, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50913, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48996, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48889, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49005, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48988, 1, 1, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(47251, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Interesting Times
(48987, 1, 1, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(48715, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48894, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48888, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48887, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49040, 1, 11, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(48991, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48992, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48993, 1, 0, 0, 0, 0, 0, 0, 0, 27843); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (48992 /*-Unknown-*/, 48993 /*-Unknown-*/, 48895 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(48992, 6, 0, 0, 0, 'Have you found de ancient bones?', 27843), -- -Unknown-
(48993, 1, 0, 0, 0, 'Do you have de antennae?', 27843), -- -Unknown-
(48895, 1, 0, 0, 0, 'Do you come bearing gifts to our loa?', 27843); -- -Unknown-


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (128316, 129260, 136601, 134089, 134169, 134544, 134162, 134532, 135154, 138908, 138523, 134019, 126502, 128848, 128849, 128807, 134103, 139521, 138252, 139274, 138253, 130233, 128209, 128296, 128295, 124648, 124639, 124635, 128553, 128418, 135807, 128540, 128421, 128327, 128322, 128335, 128339, 128325, 139895, 128334, 139840, 138907, 130667, 128331, 128333, 128328, 128323, 128340, 138801, 128332, 128321, 135478, 128336, 139853, 128329, 128330, 128324, 139900, 141490, 135477, 135479, 130660, 128147, 128039, 140463, 138414, 127989, 135853, 135066, 127966, 135852, 128547, 133831, 124566, 134052);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(128316, 110, 120, 0, 0, 27843),
(129260, 110, 120, 0, 0, 27843),
(136601, 110, 120, 0, 0, 27843),
(134089, 110, 120, 0, 0, 27843),
(134169, 110, 120, 0, 0, 27843),
(134544, 110, 120, 0, 0, 27843),
(134162, 110, 120, 0, 0, 27843),
(134532, 110, 120, 0, 0, 27843),
(135154, 110, 120, 0, 0, 27843),
(138908, 110, 120, 0, 0, 27843),
(138523, 110, 120, 0, 0, 27843),
(134019, 110, 120, 0, 0, 27843),
(126502, 110, 120, 0, 0, 27843),
(128848, 110, 120, 0, 0, 27843),
(128849, 110, 120, 0, 0, 27843),
(128807, 110, 120, 0, 0, 27843),
(134103, 110, 120, 0, 0, 27843),
(139521, 110, 120, 0, 0, 27843),
(138252, 110, 120, 0, 0, 27843),
(139274, 110, 120, 0, 0, 27843),
(138253, 110, 120, 0, 0, 27843),
(130233, 110, 120, 0, 0, 27843),
(128209, 110, 120, 0, 0, 27843),
(128296, 110, 120, 0, 0, 27843),
(128295, 110, 120, 0, 0, 27843),
(124648, 110, 120, 0, 0, 27843),
(124639, 110, 120, 0, 0, 27843),
(124635, 110, 120, 0, 0, 27843),
(128553, 110, 120, 0, 0, 27843),
(128418, 110, 120, 0, 0, 27843),
(135807, 110, 120, 0, 0, 27843),
(128540, 110, 120, 0, 0, 27843),
(128421, 110, 120, 0, 0, 27843),
(128327, 110, 120, 0, 0, 27843),
(128322, 110, 120, 0, 0, 27843),
(128335, 110, 120, 0, 0, 27843),
(128339, 110, 120, 0, 0, 27843),
(128325, 110, 120, 0, 0, 27843),
(139895, 110, 120, 0, 0, 27843),
(128334, 110, 120, 0, 0, 27843),
(139840, 110, 120, 0, 0, 27843),
(138907, 110, 120, 0, 0, 27843),
(130667, 110, 120, 0, 0, 27843),
(128331, 110, 120, 0, 0, 27843),
(128333, 110, 120, 0, 0, 27843),
(128328, 110, 120, 0, 0, 27843),
(128323, 110, 120, 0, 0, 27843),
(128340, 110, 120, 0, 0, 27843),
(138801, 110, 120, 0, 0, 27843),
(128332, 110, 120, 0, 0, 27843),
(128321, 110, 120, 0, 0, 27843),
(135478, 110, 120, 0, 0, 27843),
(128336, 110, 120, 0, 0, 27843),
(139853, 110, 120, 0, 0, 27843),
(128329, 110, 120, 0, 0, 27843),
(128330, 110, 120, 0, 0, 27843),
(128324, 110, 120, 0, 0, 27843),
(139900, 110, 120, 0, 0, 27843),
(141490, 110, 120, 0, 0, 27843),
(135477, 110, 120, 0, 0, 27843),
(135479, 110, 120, 0, 0, 27843),
(130660, 110, 120, 0, 0, 27843),
(128147, 110, 120, 0, 0, 27843),
(128039, 110, 120, 0, 0, 27843),
(140463, 110, 120, 0, 0, 27843),
(138414, 110, 120, 0, 0, 27843),
(127989, 110, 120, 0, 0, 27843),
(135853, 110, 120, 0, 0, 27843),
(135066, 110, 120, 0, 0, 27843),
(127966, 110, 120, 0, 0, 27843),
(135852, 110, 120, 0, 0, 27843),
(128547, 110, 120, 0, 0, 27843),
(133831, 110, 120, 0, 0, 27843),
(124566, 110, 120, 0, 0, 27843),
(134052, 110, 120, 0, 0, 27843);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (84840, 83322, 84728, 78617, 87362, 83348, 84327, 84387, 79933, 84326, 79934, 84389, 79990, 82998, 84378, 80006, 79989, 79913, 80739, 80065, 79715, 76792, 87330, 76667, 79995, 78162, 80003, 77955, 83818, 83308);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(84840, 0.520833, 2.25, 0, 27843),
(83322, 3.737638, 1.5, 0, 27843),
(84728, 0.306, 1.5, 0, 27843),
(78617, 0.3124998, 1.35, 0, 27843),
(87362, 0.9811299, 1.5, 0, 27843),
(83348, 0.9344095, 1.5, 0, 27843),
(84327, 0.208, 1.5, 0, 27843),
(84387, 0.21424, 1.545, 0, 27843),
(79933, 0.3213, 1.575, 0, 27843),
(84326, 0.306, 1.5, 0, 27843),
(79934, 0.208, 1.5, 0, 27843),
(79990, 0.208, 1.5, 0, 27843),
(82998, 2.843665, 3.125, 0, 27843),
(84378, 0.3576387, 1.545, 0, 27843),
(80006, 0.1917909, 0.75, 0, 27843),
(79989, 0.306, 1.5, 0, 27843),
(79913, 0.306, 1.5, 0, 27843),
(80739, 0.3645831, 1.575, 0, 27843),
(80065, 1.806657, 3, 0, 27843),
(79715, 0.347222, 1.5, 0, 27843),
(76792, 1.806657, 3, 0, 27843),
(87330, 0.4166664, 1.8, 0, 27843),
(76667, 6.02219, 10, 0, 27843),
(79995, 2.17467, 1.26, 0, 27843),
(78162, 0.6345452, 1.5, 0, 27843),
(80003, 0.8501121, 0.6, 0, 27843),
(77955, 1, 7, 0, 27843),
(83818, 0.564, 0.4, 0, 27843),
(83308, 1.053263, 1, 0, 27843);

UPDATE `creature_model_info` SET `BoundingRadius`=1.866102, `CombatReach`=1.5 WHERE `DisplayID`=77899;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8592955, `CombatReach`=0.4, `VerifiedBuild`=27843 WHERE `DisplayID`=46898;
UPDATE `creature_model_info` SET `BoundingRadius`=2.148239, `CombatReach`=1, `VerifiedBuild`=27843 WHERE `DisplayID`=26760;
UPDATE `creature_model_info` SET `BoundingRadius`=1.718591, `CombatReach`=0.8, `VerifiedBuild`=27843 WHERE `DisplayID`=26774;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8592955, `CombatReach`=0.4, `VerifiedBuild`=27843 WHERE `DisplayID`=35132;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=128316 AND `ID`=1) OR (`CreatureID`=129260 AND `ID`=1) OR (`CreatureID`=136601 AND `ID`=1) OR (`CreatureID`=134089 AND `ID`=1) OR (`CreatureID`=138908 AND `ID`=1) OR (`CreatureID`=134103 AND `ID`=1) OR (`CreatureID`=128209 AND `ID`=1) OR (`CreatureID`=128296 AND `ID`=1) OR (`CreatureID`=128295 AND `ID`=1) OR (`CreatureID`=124639 AND `ID`=1) OR (`CreatureID`=124648 AND `ID`=1) OR (`CreatureID`=124635 AND `ID`=1) OR (`CreatureID`=128418 AND `ID`=1) OR (`CreatureID`=128540 AND `ID`=1) OR (`CreatureID`=128421 AND `ID`=1) OR (`CreatureID`=128327 AND `ID`=1) OR (`CreatureID`=128322 AND `ID`=1) OR (`CreatureID`=138907 AND `ID`=1) OR (`CreatureID`=130667 AND `ID`=1) OR (`CreatureID`=128333 AND `ID`=1) OR (`CreatureID`=138801 AND `ID`=1) OR (`CreatureID`=128330 AND `ID`=1) OR (`CreatureID`=139900 AND `ID`=1) OR (`CreatureID`=130660 AND `ID`=1) OR (`CreatureID`=135066 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(128316, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(129260, 1, 95790, 0, 0, 94194, 0, 0, 0, 0, 0), -- Warguard Rakera
(136601, 1, 124379, 0, 0, 0, 0, 0, 0, 0, 0), -- Za'roco the Grifter
(134089, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Keeper Korthek
(138908, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Nisha
(134103, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Site Guardian
(128209, 1, 0, 0, 0, 0, 0, 0, 111783, 0, 0), -- Sandfury Assassin
(128296, 1, 116644, 0, 0, 116644, 0, 0, 0, 0, 0), -- Sandfury Assassin
(128295, 1, 116644, 0, 0, 116644, 0, 0, 0, 0, 0), -- Sandfury Assassin
(124639, 1, 1901, 0, 0, 0, 0, 0, 0, 0, 0), -- Redrock Laborer
(124648, 1, 155762, 0, 0, 155762, 0, 0, 0, 0, 0), -- Boatswain Hendricks
(124635, 1, 155761, 0, 0, 155761, 0, 0, 0, 0, 0), -- Ashvane Enforcer
(128418, 1, 155801, 0, 0, 155789, 0, 0, 0, 0, 0), -- Overseer Morrison
(128540, 1, 155799, 0, 0, 155790, 0, 0, 0, 0, 0), -- Ashvane Taskmaster
(128421, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- Vulpera Captive
(128327, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Vinaya
(128322, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Zaluzibo
(138907, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(130667, 1, 95790, 0, 0, 94194, 0, 0, 0, 0, 0), -- Warguard Rakera
(128333, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Zuaji
(138801, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(128330, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Vanoza
(139900, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Maz'taka
(130660, 1, 95790, 0, 0, 94194, 0, 0, 0, 0, 0), -- Warguard Rakera
(135066, 1, 94106, 0, 0, 94194, 0, 0, 0, 0, 0); -- Bladeguard Kaja


DELETE FROM `gossip_menu` WHERE (`MenuId`=21437 AND `TextId`=32859) OR (`MenuId`=21604 AND `TextId`=32948) OR (`MenuId`=21617 AND `TextId`=32951) OR (`MenuId`=21601 AND `TextId`=32939) OR (`MenuId`=21655 AND `TextId`=32980) OR (`MenuId`=21645 AND `TextId`=32969) OR (`MenuId`=21646 AND `TextId`=32970);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(21437, 32859, 27843), -- 126235
(21604, 32948, 27843), -- 127989 (Meijani)
(21617, 32951, 27843), -- Akunda the Blessed
(21601, 32939, 27843), -- 127992
(21655, 32980, 27843), -- 127992
(21645, 32969, 27843), -- 127691
(21646, 32970, 27843); -- 127691

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=21437 AND `OptionIndex`=2) OR (`MenuId`=21601 AND `OptionIndex`=3) OR (`MenuId`=21601 AND `OptionIndex`=2) OR (`MenuId`=21601 AND `OptionIndex`=1) OR (`MenuId`=21601 AND `OptionIndex`=0) OR (`MenuId`=21655 AND `OptionIndex`=0) OR (`MenuId`=21645 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(21437, 2, 0, 'We\'re ready to leave.', 136153, 27843),
(21601, 3, 0, 'My name remains unchanged.', 137447, 27843),
(21601, 2, 0, 'My name is Akunda the Courageous.', 137448, 27843),
(21601, 1, 0, 'My name is Akunda the Serene.', 137449, 27843),
(21601, 0, 0, 'My name is Akunda the Nimble.', 137450, 27843),
(21655, 0, 0, 'On second thought...', 147907, 27843),
(21645, 0, 0, 'What did you do to end up here?', 137517, 27843);

DELETE FROM `gossip_menu_option_action` WHERE (`MenuId`=21655 AND `OptionIndex`=0) OR (`MenuId`=21601 AND `OptionIndex`=3) OR (`MenuId`=21645 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(21655, 0, 21601, 0),
(21601, 3, 21655, 1),
(21645, 0, 21646, 0);





UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128316; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=129260; -- Warguard Rakera
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=136601; -- Za'roco the Grifter
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=94, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67667968, `unit_flags3`=128 WHERE `entry`=134089; -- Keeper Korthek
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=134169; -- Ahjani Excavator
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `speed_walk`=1.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=116736, `VehicleId`=5856 WHERE `entry`=134544; -- Serrik's Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=32768 WHERE `entry`=134162; -- Julwaba
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2028, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=32768, `dynamicflags`=128 WHERE `entry`=134532; -- Serrik
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135154; -- Kiro
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138908; -- Nisha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67110912 WHERE `entry`=138523; -- Kiro's Mount
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=537166080, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=134019; -- Scorpashi Venomtail
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=126502; -- Fattened Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128848; -- Dolly
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128849; -- Dot
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=128807; -- Meerah
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134103; -- Sethrak Site Guardian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2573, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139521; -- Sandspinner Weaver
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138252; -- Withered Lasher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680 WHERE `entry`=139274; -- Sandspinner Egg
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138253; -- Withered Lashling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2573, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130233; -- Sandspinner Hunter
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.4, `speed_run`=0.2857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=139303; -- Sandspinner Hatchling
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108, `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=128223; -- Meerah's Caravan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128209; -- Sandfury Assassin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1771, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128296; -- Sandfury Assassin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1771, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128295; -- Sandfury Assassin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=3006, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=124648; -- Boatswain Hendricks
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2937, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124639; -- Redrock Laborer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2937, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124635; -- Ashvane Enforcer
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128553; -- Azer'tor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2937, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128418; -- Overseer Morrison
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135807; -- Bubbling Azerite
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128574; -- Cave Toad
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=3006, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128540; -- Ashvane Taskmaster
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128421; -- Vulpera Captive
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128327; -- Vinaya
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128322; -- Zaluzibo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=65665, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128335; -- Ziaeja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128339; -- Jorak
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128325; -- Kunojin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139895; -- Zabanji
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=8193, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128334; -- Sejiju
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=129, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139840; -- Janraja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138907; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=130667; -- Warguard Rakera
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128331; -- Taszae
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128333; -- Zuaji
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=128328; -- Shakaeja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=128323; -- Juma
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128340; -- Zenjibo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=138801; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128332; -- Tusajia
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=128321; -- Janena
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135478; -- Za'mala
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=4225, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128336; -- Xanlaji
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139853; -- Moaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128329; -- Vanashi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128330; -- Vanoza
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=128324; -- Tesinjo
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139900; -- Maz'taka
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=141490; -- Tasha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135477; -- Hozzul
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135479; -- Drekal
UPDATE `creature_template` SET `minlevel`=121, `maxlevel`=121, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=128152; -- Akunda
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=130660; -- Warguard Rakera
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=128147; -- Akunda the Exalted
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=128039; -- Akunda the Unburdened
UPDATE `creature_template` SET `minlevel`=121, `maxlevel`=121, `faction`=35, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=138382; -- Akunda
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33914944, `unit_flags2`=2048 WHERE `entry`=140463; -- Distorted Memory
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33914880, `unit_flags2`=2048 WHERE `entry`=138414; -- Fractured Memory
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=126817; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=32784 WHERE `entry`=127152; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21604, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127989; -- Meijani
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135853; -- Slateclaw Whelp
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135066; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127966; -- Akunda the Exalted
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=135852; -- Ak'tar
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=133829; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128547; -- Redrock Screecher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2028, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133831; -- Child of Jani
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=128567; -- Redrock Widow
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=4229120, `VehicleId`=5488 WHERE `entry`=124566; -- Randall's Boat
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=126893; -- -Unknown-
UPDATE `creature_template` SET `unit_flags`=67141632 WHERE `entry`=134744; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=127742; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=134052; -- Rorgog the Devourer
UPDATE `creature_template` SET `faction`=2980, `unit_flags2`=2048 WHERE `entry`=126219; -- -Unknown-
UPDATE `creature_template` SET `faction`=2980, `unit_flags2`=2048 WHERE `entry`=126217; -- -Unknown-
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=133566; -- -Unknown-
UPDATE `creature_template` SET `gossip_menu_id`=21617 WHERE `entry`=127438; -- Akunda the Blessed

DELETE FROM `quest_template` WHERE `ID` IN (47716 /*-Unknown-*/, 48896 /*-Unknown-*/, 47874 /*-Unknown-*/, 50913 /*-Unknown-*/, 48996 /*-Unknown-*/, 48889 /*-Unknown-*/, 49005 /*-Unknown-*/, 48988 /*-Unknown-*/, 51905 /*-Unknown-*/, 48987 /*-Unknown-*/, 48715 /*-Unknown-*/, 48894 /*-Unknown-*/, 48888 /*-Unknown-*/, 48887 /*-Unknown-*/, 49040 /*-Unknown-*/, 48991 /*-Unknown-*/, 48992 /*-Unknown-*/, 48993 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `ScalingFactionGroup`, `MaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(47716, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Searching the Ruins', 'Find Julwaba within Zul\'Ahjin.', 'Dese dunes are crawling with assassins. Nowhere is safe, but we must press on.\n\nDe ruins aren\'t far from here. \n\nLet\'s continue our search on foot.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48896, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 254370, 0, 0, 0, 0, 1, 0, 39845896, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Knowledge of the Past', 'Travel with Meerah\'s Caravan in search of Julwaba.', 'An old friend of mine came to de sands willingly to gain knowledge of de past. \n\nIf anyone can locate dis weapon, it would be Julwaba. \n\nLast I heard, she planned to excavate de ruins surrounding de great pyramid.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47874, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 4202496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Clearing the Fog', 'Follow Warguard Rakera.', 'Did you lead Kaja here? I told her not to come after me. It isn\'t safe...\n\nMy mind remains fogged, but de memories are slowly returning. Jakra\'zet... de weapon...\n\nCome, let us find some fresh air. I will tell you what I\'ve discovered.', '', '', 1560, 0, 0, 0, 50, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50913, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 278471, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Akunda\'s Blessing', 'Commune at Akunda\'s Shrine.', 'You have proven worthy of my blessing, $n.\n\nThis means should you choose me as your loa, you can call upon my power when needed.\n\nCommune at my shrine to receive my gift.\n\nKnow that whatever you choose, you will always be welcome within these walls.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48996, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 7, 1, 594000, 7, 1, 61200, 0, 0, 0, 258470, 0, 0, 0, 0, 1, 0, 174063624, 8192, 0, 0, 0, 79716, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 1102, 7, 'Ending the Madness', 'Defeat Akunda the Exalted.', 'Akunda the Exalted is not who he seems. \n\nHe poisoned the eternal spring, sickening all who drank from it. Even I was not immune to his abhorrent alchemy.  \n\nNow he drains my power, abusing my gift to wipe the minds of all who might try to stop him. \n\nWe will not let him succeed. \n\nWhat little power I have left, I will lend to you. \n\nUse it to call the storm and end the madness that has taken over my temple.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Exile and usurper who has been siphoning the loa\'s power.', 'Akunda the Exalted', '', '', 890, 878, 27843), -- -Unknown-
(48889, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 396000, 6, 1, 51000, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 4202496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Repairing the Past', 'Protect Meijani while she repairs Akunda\'s mind.', 'Dis explains why de loa has been silent. Akunda himself has forgotten who he is!\n\nSomeone or something must be abusing his power. \n\nWe won\'t know how to help without speaking to de loa.\n\nI can perform a ritual dat may repair Akunda\'s mind, but it is not without risk.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49005, 2, -1, 5, 120, 18784, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Shattered and Broken', 'Kill Fractured and Distorted Memories.', 'Something is terribly wrong.\n\nUnwanted memories have been released from their magical confines. \n\nAkunda\'s power is supposed to keep dem sealed away...\n\nDe physical manifestation of our most haunting memories have no place in dis world. \n\nDey must be destroyed.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48988, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Memory Breach', 'Look for clues within Unwanted Memories.', 'De memories of Akunda\'s followers rest within dis valley. \n\nMost are best left forgotten, but dey may be our only chance to find out what happened to Akunda. \n\nLook back upon de memories here. See if you can find any clues about what happened to our loa. \n\nBe warned. Dis task is not for de weak. What you witness in dese memories can\'t be unseen.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51905, 3, -1, 0, 120, 0, 120, 9042, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 37290048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2162, 2157, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7500, 7500, 0, 0, 0, 0, 0, 0, 18446744073709551615, 562, 7, 'Reinforced Hullbreaker', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48987, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19800, 1, 1, 4100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Valley of Sorrows', 'Find Meijani in the Valley of Sorrows.', 'Your friend\'s memories are gone. \n\nDat is Akunda\'s gift to us. He takes away our painful memories, but a lot more than dat has gone missing lately. \n\nI can\'t even remember what I had for breakfast, and it\'s getting worse by de day. \n\nSomething\'s not right. \n\nMeijani and I had a plan. We were going to do... something... in de Valley of Sorrows. It\'s where Akunda keeps de forgotten memories. \n\nIf you\'re looking for answers, finding Meijani is de best place to start.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48715, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 4194304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Akunda Awaits', 'Investigate the Temple of Akunda.', 'I\'ve spoken to every troll out here, asking if they\'ve seen Rakera. As you might have guessed, Akunda is de only name dey know. \n\nLet\'s hope someone within de temple will be able to tell us something useful.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48894, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 99000, 3, 1, 20400, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 4202496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Trial of Truth', 'Speak your name to Akunda the Exalted.', 'Those within our temple have left their past lives behind. They devote themselves entirely to Akunda. \n\nDis final test is perhaps de most important. \n\nDis is de moment of truth. \n\nYou will speak your name, as you will be known from dis day forth.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48888, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 4194304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'It Springs Eternal', 'Kill Redrock Scavengers and Redrock Howlers near The Eternal Spring.', 'Water is a sacred resource in dese dunes, but those within dis temple never know thirst. \n\nAkunda commands de storm, allowing de nearby spring to never run empty. \n\nUnfortunately, our eternal water source attracts a variety of animals dat are a plague upon our temple. \n\nRid de valley of their presence before you return.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48887, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 198000, 5, 1, 40800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 4194304, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Cleanse the Mind', 'Meditate at the Shrine of Thunder and confront your inner demons.', 'If you wish to invite Akunda into your mind, it can\'t be bogged down by fear or regret. \n\nMeditate at de Shrine of Thunder and confront whatever demons linger in de dark recesses of your mind.', '', '', 1553, 0, 0, 0, 100, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49040, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 194000, 5, 1, 1100, 0, 0, 0, 0, 0, 0, 153016, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Fond Farewells', 'Deliver Jorak\'s Note to B\'wizati in Zuldazar.', 'Dis is where we part ways, $n.\n\nI\'m going to take de name Akunda, and start a new life here. \n\nWhen you find Rakera, and I know you will, give her my thanks. \n\nShe saved my life, and I\'m going to make sure to live a life dat was worth saving. \n\nIf you find yourself back in de city, could you deliver dis note for me? I trust you not to open it, though I doubt you could read my scrawls anyway.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48991, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 4218880, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Vile Infestation', 'Slay $1oa ranishu in Redrock Mesa.', 'Redemption must be earned. \n\nWe do good works to show Akunda we are worthy of his blessing. \n\nDe ranishu are a plague upon these lands. Dey devour everything in sight, with no regard for taste or texture. \n\nIf dey go unchecked, those vile pests will eat their way straight to de temple.\n\nRid de mesa of their presence. Show Akunda you are worthy of his gift.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48992, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 4202496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Sacred Remains', 'Collect $1oa Sacred Remains.', 'Dis area was once a lush jungle, home to many great and powerful thunder lizards.\n\nDe bones of those ancient and powerful creatures are still buried around de temple.\n\nGreat power lingers within those ancient remains... you will need such power to call upon Akunda.\n\nSearch de area and return to me with de ancient bones of de thunder lizards.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48993, 2, -1, 5, 120, 18792, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 173015048, 4202496, 0, 0, 0, 83308, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Powerful Conductors', 'Retrieve Rorgog\'s Antennae.', 'Akunda offers us a chance to start anew. \n\nThrough a sacred ritual, de loa enters our mind and removes de memories dat cause us pain. \n\nIf you seek Akunda\'s blessing, den you must first prepare for de ritual. \n\nDe pests dat feed on de wildlife here have antennae dat are great conductors for magic. De larger, de better. \n\nTheir leader\'s antennae should do de trick. He\'s easily three times de size of de normal ranishu.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'An unusually large ranishu with equally large and powerful antennae.', 'Rorgog the Devourer', '', '', 890, 878, 27843); -- -Unknown-

UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=43623; -- WANTED: Hannval the Butcher
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=43474; -- Experimental Potion: Test Subjects Needed
UPDATE `quest_template` SET `RewardHonor`=30, `AllowableRaces`=12261800583900083122, `VerifiedBuild`=27843 WHERE `ID`=43598; -- Warden Tower Assault: Blackhawk's Bulwark
UPDATE `quest_template` SET `MaxScalingLevel`=110, `MinLevel`=110, `VerifiedBuild`=27843 WHERE `ID`=49097; -- -Unknown-
UPDATE `quest_template` SET `RewardHonor`=50, `VerifiedBuild`=27843 WHERE `ID`=42025; -- Bareback Brawl
UPDATE `quest_template` SET `FlagsEx2`=2, `VerifiedBuild`=27843 WHERE `ID`=41857; -- Neltharion's Lair: Stonedark Slaves
UPDATE `quest_template` SET `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=45032; -- Like the Wind
UPDATE `quest_template` SET `FlagsEx2`=2, `AllowableRaces`=18446744073709551615, `VerifiedBuild`=27843 WHERE `ID`=43642; -- Black Rook Hold: The Sorrow
UPDATE `quest_template` SET `FlagsEx2`=2, `VerifiedBuild`=27843 WHERE `ID`=42924; -- Vault of the Wardens: A Grim Matter
UPDATE `quest_template` SET `MaxScalingLevel`=120, `RewardMoney`=198000, `RewardBonusMoney`=40800, `AllowableRaces`=12261800583900083122, `VerifiedBuild`=27843 WHERE `ID`=47251; -- Interesting Times

DELETE FROM `quest_objectives` WHERE `ID` IN (291182 /*291182*/, 293816 /*293816*/, 293241 /*293241*/, 293240 /*293240*/, 334264 /*334264*/, 293623 /*293623*/, 338258 /*338258*/, 336683 /*336683*/, 293281 /*293281*/, 336620 /*336620*/, 293599 /*293599*/, 293542 /*293542*/, 337497 /*337497*/, 293523 /*293523*/, 293438 /*293438*/, 293385 /*293385*/, 336508 /*336508*/, 293348 /*293348*/, 293638 /*293638*/, 293649 /*293649*/, 293693 /*293693*/, 293695 /*293695*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(291182, 47716, 0, 0, 1, 124769, 1, 0, 0, 0, 'Search for Julwaba', 27843), -- 291182
(293816, 48896, 0, 2, 2, 128209, 3, 2, 0, 0, '', 27843), -- 293816
(293241, 48896, 0, 1, 1, 127742, 1, 3, 0, 0, 'Ride Meerah\'s Caravan', 27843), -- 293241
(293240, 48896, 0, 0, 0, 126235, 1, 1, 0, 0, 'Speak to Meerah', 27843), -- 293240
(334264, 50913, 2, 0, 1, 290773, 1, 0, 0, 0, 'Visit the Altar of Akunda', 27843), -- 334264
(293623, 48996, 0, 0, 0, 128147, 1, 1, 0, 0, '', 27843), -- 293623
(338258, 48889, 0, 2, 2, 140463, 1, 24, 0, 0, '', 27843), -- 338258
(336683, 48889, 0, 1, 1, 138414, 3, 28, 0, 0, '', 27843), -- 336683
(293281, 48889, 0, 0, 0, 138413, 1, 0, 0, 0, 'Meijani protected', 27843), -- 293281
(336620, 49005, 0, 1, 1, 138199, 8, 0, 0, 0, '', 27843), -- 336620
(293599, 49005, 0, 0, 0, 138198, 4, 0, 0, 0, '', 27843), -- 293599
(293542, 48988, 0, 0, 0, 138412, 8, 0, 0, 0, 'Search Unwanted Memories', 27843), -- 293542
(337497, 51905, 0, 0, 0, 132047, 1, 1, 0, 0, '', 27843), -- 337497
(293523, 48715, 0, 0, 0, 130570, 1, 0, 0, 0, 'Investigate the Temple of Akunda', 27843), -- 293523
(293438, 48894, 0, 0, 0, 127992, 1, 0, 0, 0, 'Speak your true name to Akunda the Exalted', 27843), -- 293438
(293385, 48888, 0, 0, 0, 134718, 8, 0, 0, 0, 'Scavengers or Howlers slain', 27843), -- 293385
(336508, 48887, 0, 1, 1, 138292, 1, 2, 0, 0, '', 27843), -- 336508
(293348, 48887, 0, 0, 0, 127840, 1, 0, 0, 0, 'Meditate at the Shrine of Thunder', 27843), -- 293348
(293638, 49040, 1, 0, 0, 153016, 1, 0, 1, 0, '', 27843), -- 293638
(293649, 48991, 0, 0, 0, 133565, 12, 0, 0, 0, '', 27843), -- 293649
(293693, 48992, 1, 0, 0, 153028, 6, 0, 1, 0, '', 27843), -- 293693
(293695, 48993, 1, 0, 0, 153029, 1, 1, 1, 0, '', 27843); -- 293695

DELETE FROM `quest_visual_effect` WHERE (`ID`=293241 AND `Index`=0) OR (`ID`=293240 AND `Index`=0) OR (`ID`=334264 AND `Index`=0) OR (`ID`=293542 AND `Index`=0) OR (`ID`=293438 AND `Index`=0) OR (`ID`=293385 AND `Index`=0) OR (`ID`=293348 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(293241, 0, 8130, 27843),
(293240, 0, 2100, 27843),
(334264, 0, 10184, 27843),
(293542, 0, 9494, 27843),
(293438, 0, 2100, 27843),
(293385, 0, 9750, 27843),
(293348, 0, 8024, 27843);

UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=50850 AND `CreatureDisplayID`=40719); -- Savage
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=77942 AND `CreatureDisplayID`=54195); -- Primal Storm Elemental

DELETE FROM `gameobject_template` WHERE `entry` IN (284419 /*Treasure Chest*/, 297476 /*Stool*/, 297477 /*Campfire*/, 273193 /*Prickly Plum*/, 296583 /*Navarro's Flask*/, 293424 /*Anvil*/, 293423 /*Forge*/, 296588 /*Portrait of Commander Martens*/, 284420 /*Treasure Chest*/, 293315 /*Zandalari Hut*/, 293553 /*Campfire*/, 290770 /*Treasure Chest*/, 282667 /*Mysterious Trashpile*/, 293904 /*The Eternal Spring*/, 293741 /*The Eternal Spring*/, 293902 /*The Eternal Spring*/, 276460 /*Shrine of Thunder*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `RequiredLevel`, `VerifiedBuild`) VALUES
(284419, 50, 46516, 'Treasure Chest', '', '', '', 0.5, 1690, 87485, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2823, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(297476, 7, 49215, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(297477, 8, 33316, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(273193, 3, 9935, 'Prickly Plum', 'questinteract', 'Collecting', '', 0.1, 1691, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 75482, 0, 0, 0, 0, 27843), -- Prickly Plum
(296583, 3, 10298, 'Navarro\'s Flask', '', 'Collecting', '', 1, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90589, 0, 0, 0, 0, 27843), -- Navarro's Flask
(293424, 8, 49368, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(293423, 8, 14649, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(296588, 3, 51823, 'Portrait of Commander Martens', '', 'Collecting', '', 0.5, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90594, 0, 0, 0, 0, 27843), -- Portrait of Commander Martens
(284420, 50, 46516, 'Treasure Chest', '', '', '', 0.5, 1690, 87486, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2824, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(293315, 43, 50611, 'Zandalari Hut', '', '', '', 1, -1, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Zandalari Hut
(293553, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(290770, 50, 46516, 'Treasure Chest', '', '', '', 0.5, 1690, 88170, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2969, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(282667, 10, 29547, 'Mysterious Trashpile', 'questinteract', 'Rummaging', '', 2, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 266189, 0, 0, 0, 103044, 0, 0, 0, 0, 0, 1, 0, 56346, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mysterious Trashpile
(293904, 8, 9145, 'The Eternal Spring', '', '', '', 1, 1929, 22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- The Eternal Spring
(293741, 8, 9145, 'The Eternal Spring', '', '', '', 1, 1929, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- The Eternal Spring
(293902, 8, 9145, 'The Eternal Spring', '', '', '', 1, 1929, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- The Eternal Spring
(276460, 10, 49810, 'Shrine of Thunder', 'questinteract', '', '', 0.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 253810, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 61423, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843); -- Shrine of Thunder


DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=273193 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(273193, 0, 152393, 27843); -- Prickly Plum


DELETE FROM `npc_text` WHERE `ID` IN (32859 /*32859*/, 32948 /*32948*/, 32951 /*32951*/, 32980 /*32980*/, 32939 /*32939*/, 32970 /*32970*/, 32969 /*32969*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(32859, 1, 0, 0, 0, 0, 0, 0, 0, 137240, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32859
(32948, 1, 0, 0, 0, 0, 0, 0, 0, 137482, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32948
(32951, 1, 0, 0, 0, 0, 0, 0, 0, 137497, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32951
(32980, 1, 0, 0, 0, 0, 0, 0, 0, 137549, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32980
(32939, 1, 0, 0, 0, 0, 0, 0, 0, 137446, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32939
(32970, 1, 0, 0, 0, 0, 0, 0, 0, 137523, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32970
(32969, 1, 0, 0, 0, 0, 0, 0, 0, 137516, 0, 0, 0, 0, 0, 0, 0, 27843); -- 32969


