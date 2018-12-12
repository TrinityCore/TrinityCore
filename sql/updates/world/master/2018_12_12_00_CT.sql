DELETE FROM `conversation_actors` WHERE (`ConversationId`=5274 AND `ConversationActorId`=123849 AND `Idx`=0) OR (`ConversationId`=5920 AND `Idx`=1) OR (`ConversationId`=5920 AND `Idx`=0) OR (`ConversationId`=5276 AND `ConversationActorId`=123849 AND `Idx`=0) OR (`ConversationId`=6400 AND `Idx`=0) OR (`ConversationId`=6915 AND `Idx`=1) OR (`ConversationId`=6915 AND `Idx`=0) OR (`ConversationId`=8176 AND `Idx`=0) OR (`ConversationId`=8176 AND `Idx`=1) OR (`ConversationId`=6286 AND `Idx`=1) OR (`ConversationId`=6286 AND `Idx`=0) OR (`ConversationId`=6408 AND `Idx`=0) OR (`ConversationId`=6096 AND `Idx`=0) OR (`ConversationId`=6096 AND `Idx`=1) OR (`ConversationId`=5275 AND `ConversationActorId`=123849 AND `Idx`=0) OR (`ConversationId`=5922 AND `Idx`=0) OR (`ConversationId`=6095 AND `Idx`=0) OR (`ConversationId`=5273 AND `ConversationActorId`=123849 AND `Idx`=0) OR (`ConversationId`=5921 AND `Idx`=1) OR (`ConversationId`=5921 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(5274, 123849, 0, 27843),
(5276, 123849, 0, 27843),
(5275, 123849, 0, 27843),
(5273, 123849, 0, 27843);


DELETE FROM `conversation_actor_template` WHERE `Id`=123849;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(123849, 80739, 0, 27843);


DELETE FROM `conversation_line_template` WHERE `Id` IN (11787, 16336, 16335, 13259, 13258, 14458, 11789, 14426, 16337, 15780, 15779, 15778, 18512, 18511, 18510, 19860, 16344, 16343, 16342, 16341, 16340, 18520, 14442, 18808, 15782, 13522, 13521, 13520, 11788, 13267, 13517, 11783, 13262, 13266);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(11787, 0, 1083, 0, 0, 27843),
(16336, 21534, 192, 1, 0, 27843),
(16335, 16546, 192, 1, 0, 27843),
(13259, 6747, 192, 1, 0, 27843),
(13258, 4439, 192, 1, 0, 27843),
(14458, 0, 192, 0, 0, 27843),
(11789, 0, 1083, 0, 0, 27843),
(14426, 0, 192, 0, 0, 27843),
(16337, 20326, 192, 1, 0, 27843),
(15780, 14749, 192, 0, 0, 27843),
(15779, 10913, 192, 1, 0, 27843),
(15778, 0, 192, 0, 0, 27843),
(18512, 7963, 192, 0, 0, 27843),
(18511, 3596, 192, 1, 0, 27843),
(18510, 0, 192, 0, 0, 27843),
(19860, 26580, 192, 1, 0, 27843),
(16344, 19190, 192, 0, 0, 27843),
(16343, 15255, 192, 1, 0, 27843),
(16342, 11262, 192, 0, 0, 27843),
(16341, 7890, 192, 1, 0, 27843),
(16340, 0, 192, 0, 0, 27843),
(18520, 8057, 192, 0, 0, 27843),
(14442, 0, 192, 0, 0, 27843),
(18808, 18225, 192, 0, 0, 27843),
(15782, 14107, 192, 1, 0, 27843),
(13522, 8391, 192, 0, 0, 27843),
(13521, 4504, 192, 1, 0, 27843),
(13520, 0, 192, 0, 0, 27843),
(11788, 0, 1083, 0, 0, 27843),
(13267, 0, 192, 0, 0, 27843),
(13517, 0, 192, 0, 0, 27843),
(11783, 0, 1083, 0, 0, 27843),
(13262, 5127, 192, 1, 0, 27843),
(13266, 0, 192, 0, 0, 27843);


DELETE FROM `conversation_template` WHERE `Id` IN (6286, 6096, 6095, 5921, 5922, 6915, 5920, 6408, 5276, 5275, 5274, 5273, 6400, 8176);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(6286, 16340, 30778, 0, 27843),
(6096, 13520, 25042, 0, 27843),
(6095, 13517, 4680, 0, 27843),
(5921, 13266, 11703, 0, 27843),
(5922, 13267, 3919, 0, 27843),
(6915, 15778, 24468, 0, 27843),
(5920, 14458, 31144, 0, 27843),
(6408, 14442, 13620, 0, 27843),
(5276, 11789, 18102, 0, 27843),
(5275, 11788, 21734, 0, 27843),
(5274, 11787, 20244, 0, 27843),
(5273, 11783, 18007, 0, 27843),
(6400, 14426, 7477, 0, 27843),
(8176, 18510, 12215, 0, 27843);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (290773 /*Altar of Akunda*/, 297883 /*Ancient Gong*/, 276434 /*Temple Entrance*/, 281505 /*Rock Cluster*/, 277285 /*Sacred Remains*/, 296575 /*Julie's Cracked Dish*/, 281608 /*Relic of the Keepers*/, 296584 /*Zach's Canteen*/, 291001 /*Fountain*/, 273995 /*Loose Boulder*/, 291008 /*Terrace Fountain*/, 268635 /*Campfire*/, 287238 /*Ancient Altar*/, 291113 /*Collision Wall*/, 291143 /*Ranah's Wrench*/, 273992 /*Terrace Fountain*/, 291010 /*Broken Fountain*/, 310175 /*Magic Barrier*/, 281867 /*Star Moss*/, 296573 /*Jason's Rusty Blade*/, 281656 /*Faithless War Banner*/, 281643 /*Faithless Cannon*/, 271839 /*Sethrak Cage*/, 271014 /*Tarkaj's Warblade*/, 271840 /*Sethrak Cage*/, 296587 /*Josh's Fang Necklace*/, 271844 /*Rakera's Journal Page*/, 276621 /*Rich Monelite Deposit*/, 288391 /*Bonepicker Nest*/, 284410 /*Treasure Chest*/, 289311 /*Explosives*/, 278685 /*Sethrak Skull*/, 278686 /*Stolen Vulpera Banner*/, 296586 /*Rachel's Flute*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(290773, 0, 262144), -- Altar of Akunda
(297883, 0, 262144), -- Ancient Gong
(276434, 114, 0), -- Temple Entrance
(281505, 0, 8192), -- Rock Cluster
(277285, 0, 2113540), -- Sacred Remains
(296575, 0, 2113568), -- Julie's Cracked Dish
(281608, 0, 2113540), -- Relic of the Keepers
(296584, 0, 2113568), -- Zach's Canteen
(291001, 0, 32), -- Fountain
(273995, 0, 262144), -- Loose Boulder
(291008, 0, 262144), -- Terrace Fountain
(268635, 0, 32), -- Campfire
(287238, 0, 262144), -- Ancient Altar
(291113, 0, 32), -- Collision Wall
(291143, 0, 4), -- Ranah's Wrench
(273992, 0, 262144), -- Terrace Fountain
(291010, 0, 32), -- Broken Fountain
(310175, 0, 32), -- Magic Barrier
(281867, 0, 278528), -- Star Moss
(296573, 0, 2113568), -- Jason's Rusty Blade
(281656, 0, 262144), -- Faithless War Banner
(281643, 35, 262144), -- Faithless Cannon
(271839, 0, 262144), -- Sethrak Cage
(271014, 0, 262144), -- Tarkaj's Warblade
(271840, 0, 262144), -- Sethrak Cage
(296587, 0, 2113568), -- Josh's Fang Necklace
(271844, 0, 2113540), -- Rakera's Journal Page
(276621, 94, 278528), -- Rich Monelite Deposit
(288391, 0, 262144), -- Bonepicker Nest
(284410, 0, 278528), -- Treasure Chest
(289311, 0, 262144), -- Explosives
(278685, 0, 262144), -- Sethrak Skull
(278686, 0, 262144), -- Stolen Vulpera Banner
(296586, 0, 2113568); -- Rachel's Flute

DELETE FROM `quest_offer_reward` WHERE `ID` IN (48684 /*-Unknown-*/, 48554 /*-Unknown-*/, 48553 /*-Unknown-*/, 48551 /*-Unknown-*/, 48555 /*-Unknown-*/, 51829 /*-Unknown-*/, 48550 /*-Unknown-*/, 48549 /*-Unknown-*/, 47959 /*-Unknown-*/, 47316 /*-Unknown-*/, 47317 /*-Unknown-*/, 47321 /*-Unknown-*/, 47322 /*-Unknown-*/, 50755 /*-Unknown-*/, 47320 /*-Unknown-*/, 47319 /*-Unknown-*/, 51574 /*-Unknown-*/, 50739 /*-Unknown-*/, 51364 /*-Unknown-*/, 49677 /*-Unknown-*/, 47327 /*-Unknown-*/, 49676 /*-Unknown-*/, 51357 /*-Unknown-*/, 47315 /*-Unknown-*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(48684, 1, 0, 0, 0, 0, 0, 0, 0, 'Dis temple is not quite what I expected it to be.', 27843), -- -Unknown-
(48554, 1, 0, 0, 0, 0, 0, 0, 0, 'Well then, snakes! That explains it. I\'m glad you cleared up that clog. The gulch looks greener already!', 27843), -- -Unknown-
(48553, 1, 0, 0, 0, 0, 0, 0, 0, 'Hrm, this fountain in front of me still isn\'t functioning? But my work was impeccable!', 27843), -- -Unknown-
(48551, 1, 0, 0, 0, 0, 0, 0, 0, 'Look how happy those plants are! You made that happen.', 27843), -- -Unknown-
(48555, 1, 0, 0, 0, 0, 0, 0, 0, 'Look how much you\'ve helped bring this place to life! You\'ve got quite the green thumb.', 27843), -- -Unknown-
(51829, 1, 0, 0, 0, 0, 0, 0, 0, 'I\'ve been looking everywhere for this!', 27843), -- -Unknown-
(48550, 1, 0, 0, 0, 0, 0, 0, 0, '<Jorak quickly digs through the satchels.>$B$BMuch is missing, but hopefully dere\'s enough here for a worthy offering.', 27843), -- -Unknown-
(48549, 6, 1, 0, 0, 0, 3000, 0, 0, 'You saw Jakra\'zet? What would he be doing trying to break into de old pyramid?\n\nWhatever de reason, it can\'t be good.', 27843), -- -Unknown-
(47959, 1, 0, 0, 0, 0, 0, 0, 0, 'Ah, you\'re looking for de warguard? She\'s de only reason I\'m still breathing.', 27843), -- -Unknown-
(47316, 1, 0, 0, 0, 0, 0, 0, 0, 'Dis is Rakera\'s handwriting. I\'d know it anywhere.', 27843), -- -Unknown-
(47317, 1, 0, 0, 0, 0, 0, 0, 0, 'Jorana knew de risks when she agreed to enter de sands, but I still can\'t help but feel responsible for her death.$B$BI can only hope dat Tarkaj somehow made his way to safety.', 27843), -- -Unknown-
(47321, 1, 0, 0, 0, 0, 0, 0, 0, 'You\'re more resourceful than you look.', 27843), -- -Unknown-
(47322, 1, 0, 0, 0, 0, 0, 0, 0, 'Thanks, $n. We owe you our lives.', 27843), -- -Unknown-
(50755, 6, 1, 0, 0, 0, 3000, 0, 0, 'I don\'t think I\'ve ever seen these buzzards so satiated. How much did you feed them exactly? \n\nDoesn\'t matter. You saved my tail, for sure.', 27843), -- -Unknown-
(47320, 1, 0, 0, 0, 0, 0, 0, 0, 'Did these creatures come to our aid?$B$BDe last thing I remember, we were flying over de sethrak empire. There was a blinding flash of light before things went dark...', 27843), -- -Unknown-
(47319, 6, 0, 0, 0, 0, 0, 0, 0, '<Kiro quickly inspects the glands.>$B$BThese should work well.', 27843), -- -Unknown-
(51574, 1, 0, 0, 0, 0, 0, 0, 0, 'That\'s a lot of juice!', 27843), -- -Unknown-
(50739, 5, 0, 0, 0, 0, 0, 0, 0, 'Oh thank goodness! We\'ll have to keep these little guys away from anything with a big mean stinger out here. Man, I\'m going to be busy. $b$bIf you could protect Coda\'s little brother, that would help us out a lot!$b$bThis is Poda!', 27843), -- -Unknown-
(51364, 1, 0, 0, 0, 0, 0, 0, 0, 'This is the troll you flew in with, is it not? She lives, for now.', 27843), -- -Unknown-
(49677, 1, 0, 0, 0, 0, 0, 0, 0, 'These plans will be our key to taking the fight to the sethrak.', 27843), -- -Unknown-
(47327, 1, 0, 0, 0, 0, 0, 0, 0, 'Their blood flows down the dunes back to their fortress. The sethrak will think twice before attacking our burrows again.', 27843), -- -Unknown-
(49676, 1, 0, 0, 0, 0, 0, 0, 0, 'Now we are ready for a real challenge!', 27843), -- -Unknown-
(51357, 1, 0, 0, 0, 0, 0, 0, 0, 'Using their own weapons against them. I like it.', 27843), -- -Unknown-
(47315, 1, 0, 0, 0, 0, 0, 0, 0, 'These snakemen will pay for what they\'ve done to my home.', 27843); -- -Unknown-


DELETE FROM `quest_poi` WHERE (`QuestID`=48554 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=48554 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=48554 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48554 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48554 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48553 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48553 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48553 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48553 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48551 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48551 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48551 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48555 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48555 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48555 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48555 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48684 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=48684 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48684 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48684 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51829 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51829 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48550 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48550 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48550 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=48549 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=48549 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=48549 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47959 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47959 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47959 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47959 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50755 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50755 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50755 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47322 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47322 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47322 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47322 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47316 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47316 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47316 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47321 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47321 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47321 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47317 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=47317 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47317 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47317 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47320 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47320 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47320 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50739 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=50739 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=50739 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51574 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51574 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47319 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47319 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47319 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51364 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=51364 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=51364 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=51364 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51364 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49677 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49677 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49677 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=47327 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=47327 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=47327 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=49676 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=49676 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=49676 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=49676 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=49676 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=51357 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=51357 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(48554, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48554, 1, 3, 1, 336936, 127169, 1642, 864, 0, 0, 0, 61593, 1525175, 0, 27843), -- -Unknown-
(48554, 0, 2, 1, 336936, 127169, 1642, 864, 0, 0, 0, 61594, 1525132, 0, 27843), -- -Unknown-
(48554, 0, 1, 0, 292768, 127167, 1642, 864, 0, 0, 0, 0, 1457495, 0, 27843), -- -Unknown-
(48554, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48553, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48553, 0, 2, 1, 336926, 138756, 1642, 864, 0, 0, 0, 0, 1524900, 0, 27843), -- -Unknown-
(48553, 0, 1, 0, 292633, 138754, 1642, 864, 0, 0, 0, 0, 1524899, 0, 27843), -- -Unknown-
(48553, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48551, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48551, 0, 1, 0, 292622, 126816, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(48551, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48555, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48555, 0, 2, 26, 0, 0, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48555, 0, 1, 0, 292873, 126886, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48555, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48684, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1391386, 0, 27843), -- -Unknown-
(48684, 0, 2, 1, 292898, 127575, 1642, 864, 0, 0, 0, 0, 1385851, 0, 27843), -- -Unknown-
(48684, 0, 1, 0, 292787, 126235, 1642, 864, 0, 0, 0, 0, 1385852, 0, 27843), -- -Unknown-
(48684, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1391360, 0, 27843), -- -Unknown-
(51829, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1529432, 0, 27843), -- -Unknown-
(51829, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1373025, 0, 27843), -- -Unknown-
(48550, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1391387, 0, 27843), -- -Unknown-
(48550, 0, 1, 0, 292760, 152660, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(48550, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1373020, 0, 27843), -- -Unknown-
(48549, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1373020, 0, 27843), -- -Unknown-
(48549, 0, 1, 0, 292751, 126697, 1642, 864, 0, 0, 0, 0, 1373026, 0, 27843), -- -Unknown-
(48549, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1391386, 0, 27843), -- -Unknown-
(47959, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1416982, 0, 27843), -- -Unknown-
(47959, 0, 2, 1, 292762, 127656, 1642, 864, 0, 0, 0, 0, 1363814, 0, 27843), -- -Unknown-
(47959, 0, 1, 0, 292756, 122583, 1642, 864, 0, 0, 0, 0, 1327199, 0, 27843), -- -Unknown-
(47959, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1373020, 0, 27843), -- -Unknown-
(50755, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1503470, 0, 27843), -- -Unknown-
(50755, 0, 1, 0, 335811, 124016, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50755, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1503470, 0, 27843), -- -Unknown-
(47322, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1505656, 0, 27843), -- -Unknown-
(47322, 0, 2, 1, 290480, 122764, 1642, 864, 0, 0, 0, 0, 1328349, 0, 27843), -- -Unknown-
(47322, 0, 1, 0, 290495, 122762, 1642, 864, 0, 0, 0, 0, 1328347, 0, 27843), -- -Unknown-
(47322, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1505656, 0, 27843), -- -Unknown-
(47316, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1327199, 0, 27843), -- -Unknown-
(47316, 0, 1, 0, 290887, 151346, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(47316, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1416982, 0, 27843), -- -Unknown-
(47321, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1337495, 0, 27843), -- -Unknown-
(47321, 0, 1, 0, 290478, 151273, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47321, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1337495, 0, 27843), -- -Unknown-
(47317, 0, 3, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1416982, 0, 27843), -- -Unknown-
(47317, 0, 2, 1, 290408, 122729, 1642, 864, 0, 0, 0, 0, 1328234, 0, 27843), -- -Unknown-
(47317, 0, 1, 0, 290407, 271014, 1642, 864, 0, 0, 0, 0, 1328245, 0, 27843), -- -Unknown-
(47317, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1416982, 0, 27843), -- -Unknown-
(47320, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1337495, 0, 27843), -- -Unknown-
(47320, 0, 1, 0, 290472, 122741, 1642, 864, 0, 0, 0, 0, 1328567, 0, 27843), -- -Unknown-
(47320, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1416982, 0, 27843), -- -Unknown-
(50739, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1475592, 0, 27843), -- -Unknown-
(50739, 0, 1, 0, 333665, 135004, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50739, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1475592, 0, 27843), -- -Unknown-
(51574, 0, 1, 0, 336297, 160448, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(51574, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1327199, 0, 27843), -- -Unknown-
(47319, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1337495, 0, 27843), -- -Unknown-
(47319, 0, 1, 0, 290427, 160441, 1642, 864, 0, 2, 0, 0, 0, 0, 27843), -- -Unknown-
(47319, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1337495, 0, 27843), -- -Unknown-
(51364, 0, 4, 3, 340548, 137503, 1642, 864, 0, 0, 0, 0, 1503092, 0, 27843), -- -Unknown-
(51364, 0, 3, 2, 335921, 136720, 1642, 864, 0, 0, 0, 0, 1503092, 0, 27843), -- -Unknown-
(51364, 0, 2, 1, 335622, 137492, 1642, 864, 0, 0, 0, 0, 1503092, 0, 27843), -- -Unknown-
(51364, 0, 1, 0, 335551, 137796, 1642, 864, 0, 0, 0, 0, 1503092, 0, 27843), -- -Unknown-
(51364, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1337495, 0, 27843), -- -Unknown-
(49677, 0, 2, 32, 0, 0, 1642, 864, 0, 2, 0, 57224, 0, 0, 27843), -- -Unknown-
(49677, 0, 1, 0, 295044, 158651, 1642, 864, 0, 0, 0, 0, 1456178, 0, 27843), -- -Unknown-
(49677, 0, 0, -1, 0, 0, 1642, 864, 0, 2, 0, 57224, 0, 0, 27843), -- -Unknown-
(47327, 0, 2, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1421753, 0, 27843), -- -Unknown-
(47327, 0, 1, 0, 290889, 123772, 1642, 864, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47327, 0, 0, -1, 0, 0, 1642, 864, 0, 2, 0, 57224, 0, 0, 27843), -- -Unknown-
(49676, 0, 4, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1421753, 0, 27843), -- -Unknown-
(49676, 0, 3, 2, 295042, 289311, 1642, 864, 0, 0, 0, 0, 1502069, 0, 27843), -- -Unknown-
(49676, 0, 2, 1, 295041, 130459, 1642, 864, 0, 0, 0, 0, 1418948, 0, 27843), -- -Unknown-
(49676, 0, 1, 0, 295037, 130460, 1642, 864, 0, 0, 0, 0, 1418940, 0, 27843), -- -Unknown-
(49676, 0, 0, -1, 0, 0, 1642, 864, 0, 2, 0, 57224, 0, 0, 27843), -- -Unknown-
(51357, 0, 1, 32, 0, 0, 1642, 864, 0, 0, 0, 0, 1421753, 0, 27843), -- -Unknown-
(51357, 0, 0, -1, 0, 0, 1642, 864, 0, 0, 0, 0, 1421753, 0, 27843); -- -Unknown-

DELETE FROM `quest_poi_points` WHERE (`QuestID`=48554 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=48554 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48554 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48554 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48554 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48553 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48553 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48553 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48553 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48551 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48551 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48551 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48555 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=48555 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48555 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48555 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48684 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=48684 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48684 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48684 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51829 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51829 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48550 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=48550 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48550 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=48549 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=48549 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=48549 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47959 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47959 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47959 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47959 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50755 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50755 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50755 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47322 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47322 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47322 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47322 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47316 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=47316 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47316 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47321 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=47321 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47321 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47317 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=47317 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47317 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47317 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47320 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47320 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47320 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50739 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=50739 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=50739 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=50739 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=50739 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=50739 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=51574 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51574 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47319 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=47319 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47319 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51364 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=51364 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=51364 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=51364 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51364 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49677 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49677 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49677 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=47327 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=47327 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=47327 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=49676 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=49676 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=49676 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=49676 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=49676 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=51357 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=51357 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(48554, 4, 0, 1186, 3018, 27843), -- -Unknown-
(48554, 3, 0, 1288, 3000, 27843), -- -Unknown-
(48554, 2, 0, 1188, 2916, 27843), -- -Unknown-
(48554, 1, 0, 1187, 2916, 27843), -- -Unknown-
(48554, 0, 0, 1186, 3018, 27843), -- -Unknown-
(48553, 3, 0, 1186, 3018, 27843), -- -Unknown-
(48553, 2, 0, 1067, 3086, 27843), -- -Unknown-
(48553, 1, 0, 1265, 3047, 27843), -- -Unknown-
(48553, 0, 0, 1186, 3018, 27843), -- -Unknown-
(48551, 2, 0, 1186, 3018, 27843), -- -Unknown-
(48551, 1, 11, 1060, 3047, 27843), -- -Unknown-
(48551, 1, 10, 1035, 3073, 27843), -- -Unknown-
(48551, 1, 9, 1040, 3108, 27843), -- -Unknown-
(48551, 1, 8, 1078, 3138, 27843), -- -Unknown-
(48551, 1, 7, 1155, 3144, 27843), -- -Unknown-
(48551, 1, 6, 1230, 3133, 27843), -- -Unknown-
(48551, 1, 5, 1252, 3108, 27843), -- -Unknown-
(48551, 1, 4, 1257, 3073, 27843), -- -Unknown-
(48551, 1, 3, 1230, 3047, 27843), -- -Unknown-
(48551, 1, 2, 1187, 3032, 27843), -- -Unknown-
(48551, 1, 1, 1151, 3032, 27843), -- -Unknown-
(48551, 1, 0, 1109, 3032, 27843), -- -Unknown-
(48551, 0, 0, 1186, 3018, 27843), -- -Unknown-
(48555, 3, 0, 1186, 3018, 27843), -- -Unknown-
(48555, 2, 10, 1064, 3046, 27843), -- -Unknown-
(48555, 2, 9, 1063, 3048, 27843), -- -Unknown-
(48555, 2, 8, 1063, 3113, 27843), -- -Unknown-
(48555, 2, 7, 1064, 3116, 27843), -- -Unknown-
(48555, 2, 6, 1177, 3134, 27843), -- -Unknown-
(48555, 2, 5, 1239, 3124, 27843), -- -Unknown-
(48555, 2, 4, 1242, 3122, 27843), -- -Unknown-
(48555, 2, 3, 1241, 3116, 27843), -- -Unknown-
(48555, 2, 2, 1213, 3055, 27843), -- -Unknown-
(48555, 2, 1, 1185, 3031, 27843), -- -Unknown-
(48555, 2, 0, 1183, 3030, 27843), -- -Unknown-
(48555, 1, 7, 1104, 3091, 27843), -- -Unknown-
(48555, 1, 6, 1209, 3116, 27843), -- -Unknown-
(48555, 1, 5, 1225, 3116, 27843), -- -Unknown-
(48555, 1, 4, 1228, 3099, 27843), -- -Unknown-
(48555, 1, 3, 1228, 3066, 27843), -- -Unknown-
(48555, 1, 2, 1157, 3057, 27843), -- -Unknown-
(48555, 1, 1, 1116, 3057, 27843), -- -Unknown-
(48555, 1, 0, 1102, 3057, 27843), -- -Unknown-
(48555, 0, 0, 1186, 3018, 27843), -- -Unknown-
(48684, 3, 0, 1338, 3065, 27843), -- -Unknown-
(48684, 2, 0, 1342, 3060, 27843), -- -Unknown-
(48684, 1, 0, 1338, 3064, 27843), -- -Unknown-
(48684, 0, 0, 283, 3096, 27843), -- -Unknown-
(51829, 1, 0, 1401, 3234, 27843), -- -Unknown-
(51829, 0, 0, 1186, 3019, 27843), -- -Unknown-
(48550, 2, 0, 1340, 3059, 27843), -- -Unknown-
(48550, 1, 11, 1327, 3209, 27843), -- -Unknown-
(48550, 1, 10, 1283, 3274, 27843), -- -Unknown-
(48550, 1, 9, 1257, 3326, 27843), -- -Unknown-
(48550, 1, 8, 1257, 3365, 27843), -- -Unknown-
(48550, 1, 7, 1298, 3412, 27843), -- -Unknown-
(48550, 1, 6, 1338, 3412, 27843), -- -Unknown-
(48550, 1, 5, 1393, 3396, 27843), -- -Unknown-
(48550, 1, 4, 1450, 3386, 27843), -- -Unknown-
(48550, 1, 3, 1485, 3344, 27843), -- -Unknown-
(48550, 1, 2, 1469, 3274, 27843), -- -Unknown-
(48550, 1, 1, 1445, 3208, 27843), -- -Unknown-
(48550, 1, 0, 1374, 3193, 27843), -- -Unknown-
(48550, 0, 0, 1316, 3079, 27843), -- -Unknown-
(48549, 2, 0, 1316, 3079, 27843), -- -Unknown-
(48549, 1, 0, 1398, 3339, 27843), -- -Unknown-
(48549, 0, 0, 1338, 3065, 27843), -- -Unknown-
(47959, 3, 0, 2041, 2818, 27843), -- -Unknown-
(47959, 2, 0, 2043, 2833, 27843), -- -Unknown-
(47959, 1, 0, 2041, 2823, 27843), -- -Unknown-
(47959, 0, 0, 1316, 3081, 27843), -- -Unknown-
(50755, 2, 0, 2412, 2960, 27843), -- -Unknown-
(50755, 1, 10, 2398, 2507, 27843), -- -Unknown-
(50755, 1, 9, 2296, 2713, 27843), -- -Unknown-
(50755, 1, 8, 2317, 2898, 27843), -- -Unknown-
(50755, 1, 7, 2363, 2924, 27843), -- -Unknown-
(50755, 1, 6, 2508, 2916, 27843), -- -Unknown-
(50755, 1, 5, 2551, 2781, 27843), -- -Unknown-
(50755, 1, 4, 2566, 2727, 27843), -- -Unknown-
(50755, 1, 3, 2574, 2674, 27843), -- -Unknown-
(50755, 1, 2, 2576, 2575, 27843), -- -Unknown-
(50755, 1, 1, 2573, 2533, 27843), -- -Unknown-
(50755, 1, 0, 2490, 2479, 27843), -- -Unknown-
(50755, 0, 0, 2412, 2960, 27843), -- -Unknown-
(47322, 3, 0, 2408, 2963, 27843), -- -Unknown-
(47322, 2, 0, 2508, 2960, 27843), -- -Unknown-
(47322, 1, 0, 2552, 2847, 27843), -- -Unknown-
(47322, 0, 0, 2408, 2963, 27843), -- -Unknown-
(47316, 2, 0, 2042, 2823, 27843), -- -Unknown-
(47316, 1, 11, 2113, 2879, 27843), -- -Unknown-
(47316, 1, 10, 2128, 2966, 27843), -- -Unknown-
(47316, 1, 9, 2174, 3087, 27843), -- -Unknown-
(47316, 1, 8, 2255, 3158, 27843), -- -Unknown-
(47316, 1, 7, 2321, 3183, 27843), -- -Unknown-
(47316, 1, 6, 2432, 3163, 27843), -- -Unknown-
(47316, 1, 5, 2477, 3098, 27843), -- -Unknown-
(47316, 1, 4, 2462, 3002, 27843), -- -Unknown-
(47316, 1, 3, 2422, 2900, 27843), -- -Unknown-
(47316, 1, 2, 2351, 2829, 27843), -- -Unknown-
(47316, 1, 1, 2270, 2794, 27843), -- -Unknown-
(47316, 1, 0, 2174, 2794, 27843), -- -Unknown-
(47316, 0, 0, 2042, 2818, 27843), -- -Unknown-
(47321, 2, 0, 2041, 2821, 27843), -- -Unknown-
(47321, 1, 11, 2503, 2839, 27843), -- -Unknown-
(47321, 1, 10, 2469, 2889, 27843), -- -Unknown-
(47321, 1, 9, 2457, 2922, 27843), -- -Unknown-
(47321, 1, 8, 2458, 3032, 27843), -- -Unknown-
(47321, 1, 7, 2459, 3060, 27843), -- -Unknown-
(47321, 1, 6, 2495, 3094, 27843), -- -Unknown-
(47321, 1, 5, 2547, 3063, 27843), -- -Unknown-
(47321, 1, 4, 2622, 2939, 27843), -- -Unknown-
(47321, 1, 3, 2618, 2870, 27843), -- -Unknown-
(47321, 1, 2, 2602, 2836, 27843), -- -Unknown-
(47321, 1, 1, 2577, 2813, 27843), -- -Unknown-
(47321, 1, 0, 2538, 2809, 27843), -- -Unknown-
(47321, 0, 0, 2041, 2821, 27843), -- -Unknown-
(47317, 3, 0, 2042, 2818, 27843), -- -Unknown-
(47317, 2, 0, 2493, 2777, 27843), -- -Unknown-
(47317, 1, 0, 2549, 2968, 27843), -- -Unknown-
(47317, 0, 0, 2042, 2818, 27843), -- -Unknown-
(47320, 2, 0, 2041, 2821, 27843), -- -Unknown-
(47320, 1, 0, 2042, 2818, 27843), -- -Unknown-
(47320, 0, 0, 2042, 2818, 27843), -- -Unknown-
(50739, 2, 0, 2140, 2927, 27843), -- -Unknown-
(50739, 1, 3, 1994, 3040, 27843), -- -Unknown-
(50739, 1, 2, 2028, 3071, 27843), -- -Unknown-
(50739, 1, 1, 2122, 3082, 27843), -- -Unknown-
(50739, 1, 0, 2060, 2969, 27843), -- -Unknown-
(50739, 0, 0, 2140, 2927, 27843), -- -Unknown-
(51574, 1, 11, 2103, 2920, 27843), -- -Unknown-
(51574, 1, 10, 2041, 2945, 27843), -- -Unknown-
(51574, 1, 9, 2001, 2981, 27843), -- -Unknown-
(51574, 1, 8, 1977, 3037, 27843), -- -Unknown-
(51574, 1, 7, 1972, 3077, 27843), -- -Unknown-
(51574, 1, 6, 2017, 3113, 27843), -- -Unknown-
(51574, 1, 5, 2088, 3118, 27843), -- -Unknown-
(51574, 1, 4, 2144, 3073, 27843), -- -Unknown-
(51574, 1, 3, 2194, 3006, 27843), -- -Unknown-
(51574, 1, 2, 2200, 2961, 27843), -- -Unknown-
(51574, 1, 1, 2194, 2920, 27843), -- -Unknown-
(51574, 1, 0, 2149, 2905, 27843), -- -Unknown-
(51574, 0, 0, 2042, 2823, 27843), -- -Unknown-
(47319, 2, 0, 2041, 2821, 27843), -- -Unknown-
(47319, 1, 11, 2103, 2930, 27843), -- -Unknown-
(47319, 1, 10, 2078, 2941, 27843), -- -Unknown-
(47319, 1, 9, 1981, 2981, 27843), -- -Unknown-
(47319, 1, 8, 1936, 3021, 27843), -- -Unknown-
(47319, 1, 7, 1900, 3113, 27843), -- -Unknown-
(47319, 1, 6, 1951, 3153, 27843), -- -Unknown-
(47319, 1, 5, 2058, 3158, 27843), -- -Unknown-
(47319, 1, 4, 2139, 3148, 27843), -- -Unknown-
(47319, 1, 3, 2214, 3088, 27843), -- -Unknown-
(47319, 1, 2, 2240, 3006, 27843), -- -Unknown-
(47319, 1, 1, 2234, 2936, 27843), -- -Unknown-
(47319, 1, 0, 2174, 2905, 27843), -- -Unknown-
(47319, 0, 0, 2041, 2821, 27843), -- -Unknown-
(51364, 4, 0, 2766, 2598, 27843), -- -Unknown-
(51364, 3, 0, 2766, 2598, 27843), -- -Unknown-
(51364, 2, 0, 2766, 2598, 27843), -- -Unknown-
(51364, 1, 0, 2766, 2598, 27843), -- -Unknown-
(51364, 0, 0, 2041, 2821, 27843), -- -Unknown-
(49677, 2, 0, 2853, 2541, 27843), -- -Unknown-
(49677, 1, 0, 2854, 2543, 27843), -- -Unknown-
(49677, 0, 0, 2853, 2541, 27843), -- -Unknown-
(47327, 2, 0, 2738, 2326, 27843), -- -Unknown-
(47327, 1, 10, 2710, 2234, 27843), -- -Unknown-
(47327, 1, 9, 2698, 2262, 27843), -- -Unknown-
(47327, 1, 8, 2690, 2282, 27843), -- -Unknown-
(47327, 1, 7, 2614, 2580, 27843), -- -Unknown-
(47327, 1, 6, 2631, 2656, 27843), -- -Unknown-
(47327, 1, 5, 2966, 2529, 27843), -- -Unknown-
(47327, 1, 4, 2910, 2371, 27843), -- -Unknown-
(47327, 1, 3, 2878, 2307, 27843), -- -Unknown-
(47327, 1, 2, 2822, 2260, 27843), -- -Unknown-
(47327, 1, 1, 2731, 2234, 27843), -- -Unknown-
(47327, 1, 0, 2713, 2232, 27843), -- -Unknown-
(47327, 0, 0, 2782, 2434, 27843), -- -Unknown-
(49676, 4, 0, 2673, 2195, 27843), -- -Unknown-
(49676, 3, 0, 2803, 2474, 27843), -- -Unknown-
(49676, 2, 0, 2852, 2355, 27843), -- -Unknown-
(49676, 1, 0, 2797, 2285, 27843), -- -Unknown-
(49676, 0, 0, 2812, 2434, 27843), -- -Unknown-
(51357, 1, 0, 2673, 2195, 27843), -- -Unknown-
(51357, 0, 0, 2673, 2195, 27843); -- -Unknown-


DELETE FROM `quest_details` WHERE `ID` IN (48895 /*-Unknown-*/, 48554 /*-Unknown-*/, 48553 /*-Unknown-*/, 48551 /*-Unknown-*/, 48555 /*-Unknown-*/, 48684 /*-Unknown-*/, 51829 /*-Unknown-*/, 48550 /*-Unknown-*/, 48549 /*-Unknown-*/, 47959 /*-Unknown-*/, 50755 /*-Unknown-*/, 47322 /*-Unknown-*/, 47316 /*-Unknown-*/, 47321 /*-Unknown-*/, 47317 /*-Unknown-*/, 47320 /*-Unknown-*/, 50739 /*-Unknown-*/, 51574 /*-Unknown-*/, 47319 /*-Unknown-*/, 51364 /*-Unknown-*/, 49677 /*-Unknown-*/, 47327 /*-Unknown-*/, 49676 /*-Unknown-*/, 51357 /*-Unknown-*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48895, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48554, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48553, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48551, 1, 0, 0, 0, 0, 3, 0, 0, 27843), -- -Unknown-
(48555, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48684, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51829, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(48550, 1, 6, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(48549, 1, 1, 0, 0, 0, 3000, 0, 0, 27843), -- -Unknown-
(47959, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50755, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47322, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47316, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47321, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47317, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47320, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(50739, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51574, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47319, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51364, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49677, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(47327, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(49676, 1, 0, 0, 0, 0, 0, 0, 0, 27843), -- -Unknown-
(51357, 1, 0, 0, 0, 0, 0, 0, 0, 27843); -- -Unknown-


DELETE FROM `quest_request_items` WHERE `ID` IN (51829 /*-Unknown-*/, 48550 /*-Unknown-*/, 47316 /*-Unknown-*/, 47321 /*-Unknown-*/, 47319 /*-Unknown-*/, 51574 /*-Unknown-*/, 49677 /*-Unknown-*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(51829, 6, 0, 0, 0, 'Do you have something for me?', 27843), -- -Unknown-
(48550, 1, 0, 0, 0, 'Have you recovered our belongings?', 27843), -- -Unknown-
(47316, 1, 0, 0, 0, 'What have you found?', 27843), -- -Unknown-
(47321, 1, 0, 0, 0, 'You help us, and we help you. Deal?', 27843), -- -Unknown-
(47319, 1, 0, 0, 0, 'Have you brought the glands? We can\'t heal your friend without them.', 27843), -- -Unknown-
(51574, 1, 0, 0, 0, 'Do you have the juice? Your friend will be thirsty when she wakes.', 27843), -- -Unknown-
(49677, 1, 0, 0, 0, 'My plan for attack is both detailed and dangerous.', 27843); -- -Unknown-


DELETE FROM `creature_template_scaling` WHERE `Entry` IN (127439, 130571, 127438, 127440, 127980, 127570, 127441, 127691, 139901, 127428, 127431, 139864, 127992, 127436, 127434, 127437, 139888, 141491, 127435, 135081, 127427, 127517, 127513, 127515, 127433, 139833, 139841, 139835, 139831, 135069, 127422, 135068, 127420, 134690, 134698, 134699, 134744, 133566, 133560, 134743, 133565, 134718, 133561, 134746, 135494, 138200, 142780, 138198, 138202, 134108, 127406, 125882, 127169, 135061, 130316, 130317, 130321, 138199, 122153, 142755, 126814, 138524, 126697, 133465, 130248, 129276, 126235, 122289, 126817, 127152, 126696, 126893, 142619, 136615, 136613, 136614, 136663, 122726, 135124, 122729, 129652, 134555, 123866, 122762, 122782, 122736, 129538, 123865, 137632, 137633, 122764, 137629, 137631, 122745, 123863, 123864, 124287, 135500, 130341, 130443, 135582, 130348, 130329, 130349, 122678, 135012, 138107, 123876, 126217, 126219, 138717, 138716, 143325, 138258, 122741, 140961, 122583, 123586, 138707, 140887, 139781, 138715, 124108, 139794, 139823, 139789, 139788, 139824, 124111, 138701, 139785, 124642, 127758, 126909, 124654, 122746, 130119, 124019, 136664, 133234, 124016, 129774, 136720, 137799, 130466, 137494, 137495, 133128, 123772, 133078, 123776, 123775, 123773, 124527, 124020, 124021, 123774, 124029, 124194, 130455);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(127439, 110, 120, 0, 0, 27843),
(130571, 110, 120, 0, 0, 27843),
(127438, 110, 120, 0, 0, 27843),
(127440, 110, 120, 0, 0, 27843),
(127980, 110, 120, 0, 0, 27843),
(127570, 110, 120, 0, 0, 27843),
(127441, 110, 120, 0, 0, 27843),
(127691, 110, 120, 0, 0, 27843),
(139901, 110, 120, 0, 0, 27843),
(127428, 110, 120, 0, 0, 27843),
(127431, 110, 120, 0, 0, 27843),
(139864, 110, 120, 0, 0, 27843),
(127992, 110, 120, 0, 0, 27843),
(127436, 110, 120, 0, 0, 27843),
(127434, 110, 120, 0, 0, 27843),
(127437, 110, 120, 0, 0, 27843),
(139888, 110, 120, 0, 0, 27843),
(141491, 110, 120, 0, 0, 27843),
(127435, 110, 120, 0, 0, 27843),
(135081, 110, 120, 0, 0, 27843),
(127427, 110, 120, 0, 0, 27843),
(127517, 110, 120, 0, 0, 27843),
(127513, 110, 120, 0, 0, 27843),
(127515, 110, 120, 0, 0, 27843),
(127433, 110, 120, 0, 0, 27843),
(139833, 110, 120, 0, 0, 27843),
(139841, 110, 120, 0, 0, 27843),
(139835, 110, 120, 0, 0, 27843),
(139831, 110, 120, 0, 0, 27843),
(135069, 110, 120, 0, 0, 27843),
(127422, 110, 120, 0, 0, 27843),
(135068, 110, 120, 0, 0, 27843),
(127420, 110, 120, 0, 0, 27843),
(134690, 110, 120, 0, 0, 27843),
(134698, 110, 120, 0, 0, 27843),
(134699, 110, 120, 0, 0, 27843),
(134744, 110, 120, 0, 0, 27843),
(133566, 110, 120, 0, 0, 27843),
(133560, 110, 120, 0, 0, 27843),
(134743, 110, 120, 0, 0, 27843),
(133565, 110, 120, 0, 0, 27843),
(134718, 110, 120, 0, 0, 27843),
(133561, 110, 120, 0, 0, 27843),
(134746, 110, 120, 0, 0, 27843),
(135494, 110, 120, 0, 0, 27843),
(138200, 110, 120, 0, 0, 27843),
(142780, 110, 120, 0, 0, 27843),
(138198, 110, 120, 0, 0, 27843),
(138202, 110, 120, 0, 0, 27843),
(134108, 110, 120, 0, 0, 27843),
(127406, 110, 120, 0, 0, 27843),
(125882, 110, 120, 0, 0, 27843),
(127169, 110, 120, -1, -1, 27843),
(135061, 110, 120, -1, -1, 27843),
(130316, 110, 120, 0, 0, 27843),
(130317, 110, 120, 0, 0, 27843),
(130321, 110, 120, 0, 0, 27843),
(138199, 110, 120, 0, 0, 27843),
(122153, 110, 120, 0, 0, 27843),
(142755, 110, 120, 0, 0, 27843),
(126814, 110, 120, 0, 0, 27843),
(138524, 110, 120, 0, 0, 27843),
(126697, 110, 120, 0, 0, 27843),
(133465, 110, 120, 0, 0, 27843),
(130248, 110, 120, 0, 0, 27843),
(129276, 110, 120, 0, 0, 27843),
(126235, 110, 120, 0, 0, 27843),
(122289, 110, 120, 0, 0, 27843),
(126817, 110, 120, 0, 0, 27843),
(127152, 110, 120, 0, 0, 27843),
(126696, 110, 120, 0, 0, 27843),
(126893, 110, 120, 0, 0, 27843),
(142619, 110, 120, 0, 0, 27843),
(136615, 110, 120, 0, 0, 27843),
(136613, 110, 120, 0, 0, 27843),
(136614, 110, 120, 0, 0, 27843),
(136663, 110, 120, 0, 0, 27843),
(122726, 110, 120, 0, 0, 27843),
(135124, 110, 120, 0, 0, 27843),
(122729, 110, 120, 0, 0, 27843),
(129652, 110, 120, 0, 0, 27843),
(134555, 110, 120, 0, 0, 27843),
(123866, 110, 120, 0, 0, 27843),
(122762, 110, 120, 0, 0, 27843),
(122782, 110, 120, 0, 0, 27843),
(122736, 110, 120, 0, 0, 27843),
(129538, 110, 120, 0, 0, 27843),
(123865, 110, 120, 0, 0, 27843),
(137632, 110, 120, 0, 0, 27843),
(137633, 110, 120, 0, 0, 27843),
(122764, 110, 120, 0, 0, 27843),
(137629, 110, 120, 0, 0, 27843),
(137631, 110, 120, 0, 0, 27843),
(122745, 110, 120, 0, 0, 27843),
(123863, 110, 120, 0, 0, 27843),
(123864, 110, 120, 0, 0, 27843),
(124287, 110, 120, 0, 0, 27843),
(135500, 110, 120, 0, 0, 27843),
(130341, 110, 120, 0, 0, 27843),
(130443, 110, 120, 0, 0, 27843),
(135582, 110, 120, 0, 0, 27843),
(130348, 110, 120, 0, 0, 27843),
(130329, 110, 120, 0, 0, 27843),
(130349, 110, 120, 0, 0, 27843),
(122678, 110, 120, 0, 0, 27843),
(135012, 110, 120, 0, 0, 27843),
(138107, 110, 120, 0, 0, 27843),
(123876, 110, 120, 0, 0, 27843),
(126217, 110, 120, 0, 0, 27843),
(126219, 110, 120, 0, 0, 27843),
(138717, 120, 120, 0, 0, 27843),
(138716, 120, 120, 0, 0, 27843),
(143325, 110, 120, 0, 0, 27843),
(138258, 110, 120, 0, 0, 27843),
(122741, 110, 120, 0, 0, 27843),
(140961, 110, 120, 0, 0, 27843),
(122583, 110, 120, 0, 0, 27843),
(123586, 110, 120, 0, 0, 27843),
(138707, 120, 120, 0, 0, 27843),
(140887, 110, 120, 0, 0, 27843),
(139781, 110, 120, 0, 0, 27843),
(138715, 120, 120, 0, 0, 27843),
(124108, 110, 120, 0, 0, 27843),
(139794, 110, 120, 0, 0, 27843),
(139823, 110, 120, 0, 0, 27843),
(139789, 110, 120, 0, 0, 27843),
(139788, 110, 120, 0, 0, 27843),
(139824, 110, 120, 0, 0, 27843),
(124111, 110, 120, 0, 0, 27843),
(138701, 110, 120, 0, 0, 27843),
(139785, 110, 120, 0, 0, 27843),
(124642, 110, 120, 0, 0, 27843),
(127758, 110, 120, 0, 0, 27843),
(126909, 110, 120, 0, 0, 27843),
(124654, 110, 120, 0, 0, 27843),
(122746, 110, 120, 0, 0, 27843),
(130119, 110, 120, 0, 0, 27843),
(124019, 110, 120, 0, 0, 27843),
(136664, 110, 120, 0, 0, 27843),
(133234, 110, 120, 0, 0, 27843),
(124016, 110, 120, 0, 0, 27843),
(129774, 110, 120, 0, 0, 27843),
(136720, 110, 120, 0, 0, 27843),
(137799, 110, 120, 0, 0, 27843),
(130466, 110, 120, 0, 0, 27843),
(137494, 110, 120, 0, 0, 27843),
(137495, 110, 120, 0, 0, 27843),
(133128, 110, 120, 0, 0, 27843),
(123772, 110, 120, 0, 0, 27843),
(133078, 110, 120, 0, 0, 27843),
(123776, 110, 120, 0, 0, 27843),
(123775, 110, 120, 0, 0, 27843),
(123773, 110, 120, 0, 0, 27843),
(124527, 110, 120, 0, 0, 27843),
(124020, 110, 120, 0, 0, 27843),
(124021, 110, 120, 0, 0, 27843),
(123774, 110, 120, 0, 0, 27843),
(124029, 110, 120, 0, 0, 27843),
(124194, 110, 120, 0, 0, 27843),
(130455, 110, 120, 0, 0, 27843);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (79433, 87331, 79431, 79432, 79719, 88039, 79434, 79422, 79424, 79716, 79429, 79427, 79430, 86512, 79428, 84079, 79420, 79452, 79450, 79451, 79426, 80972, 86509, 80973, 80970, 79423, 79416, 83817, 83821, 80407, 82993, 86560, 80404, 86559, 75320, 80829, 82159, 88583, 80467, 83346, 80491, 84061, 81121, 81124, 85835, 88582, 79153, 79327, 83242, 82968, 79237, 83240, 84050, 84051, 83239, 83241, 81391, 79490, 83844, 76998, 83756, 83734, 83750, 83753, 84486, 79321, 80641, 80258, 80647, 80660, 82747, 85411, 85412, 80487, 80623, 80740, 81233, 75596, 80465, 80503, 81138, 85251, 80030, 84033, 83699, 80464, 85959, 85956, 87765, 83698, 81120, 87009, 79320, 81018, 81020, 84414, 81019, 85955, 84363, 85958, 81051, 85174, 75324, 84722, 83697, 75323, 75322, 75325, 81021, 85953, 77899, 78127, 77483, 75599, 85248, 80993, 76694, 84822, 85225, 83749, 84494, 80652, 80650, 84495, 80649, 84500, 84484, 81252, 84492, 82881, 88594, 84493, 80662, 84497, 79326, 82710, 80651, 80659, 84481, 84489, 80642, 80654, 80624, 85252, 84499, 80656, 85250, 80661, 84498, 80655, 84488, 80658, 84490, 80657, 79862, 79861, 79877, 84482, 79323, 79912, 79863);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(79433, 0.347222, 1.5, 0, 27843),
(87331, 0.3645831, 1.575, 0, 27843),
(79431, 0.347222, 1.5, 0, 27843),
(79432, 0.347222, 1.5, 0, 27843),
(79719, 0.347222, 1.5, 0, 27843),
(88039, 6.789588, 6, 0, 27843),
(79434, 0.347222, 1.5, 0, 27843),
(79422, 0.347222, 1.5, 0, 27843),
(79424, 0.347222, 1.5, 0, 27843),
(79716, 0.4166664, 1.8, 0, 27843),
(79429, 0.347222, 1.5, 0, 27843),
(79427, 0.347222, 1.5, 0, 27843),
(79430, 0.347222, 1.5, 0, 27843),
(86512, 0.347222, 1.5, 0, 27843),
(79428, 0.347222, 1.5, 0, 27843),
(84079, 0.347222, 1.5, 0, 27843),
(79420, 0.347222, 1.5, 0, 27843),
(79452, 0.347222, 1.5, 0, 27843),
(79450, 0.347222, 1.5, 0, 27843),
(79451, 0.347222, 1.5, 0, 27843),
(79426, 0.347222, 1.5, 0, 27843),
(80972, 2.167988, 3.6, 0, 27843),
(86509, 0.347222, 1.5, 0, 27843),
(80973, 1.806657, 3, 0, 27843),
(80970, 2.318543, 3.85, 0, 27843),
(79423, 0.347222, 1.5, 0, 27843),
(79416, 0.347222, 1.5, 0, 27843),
(83817, 0.705, 0.5, 0, 27843),
(83821, 1.692, 1.2, 0, 27843),
(80407, 0.3949737, 0.375, 0, 27843),
(82993, 2.715835, 1.4, 0, 27843),
(86560, 0.1225, 2.8, 0, 27843),
(80404, 0.5266316, 0.5, 0, 27843),
(86559, 0.1225, 2.8, 0, 27843),
(75320, 0.629891, 1.5, 0, 27843),
(80829, 3.613314, 6, 0, 27843),
(82159, 3.011095, 5, 0, 27843),
(88583, 1.863049, 1.2, 0, 27843),
(80467, 0.175, 0.5, 0, 27843),
(83346, 0.9344095, 1.5, 0, 27843),
(80491, 0.347222, 1.5, 0, 27843),
(84061, 2.5, 3.125, 0, 27843),
(81121, 0.846, 0.6, 0, 27843),
(81124, 1.7625, 1.25, 0, 27843),
(85835, 0.5918992, 1.5, 0, 27843),
(88582, 1.462769, 1, 0, 27843),
(79153, 0.6, 1.5, 0, 27843),
(79327, 0.306, 1.5, 0, 27843),
(83242, 0.306, 1.5, 0, 27843),
(82968, 1.2, 1.8, 0, 27843),
(79237, 0.347222, 1.5, 0, 27843),
(83240, 0.306, 1.5, 0, 27843),
(84050, 0.306, 1.5, 0, 27843),
(84051, 0.306, 1.5, 0, 27843),
(83239, 0.306, 1.5, 0, 27843),
(83241, 0.306, 1.5, 0, 27843),
(81391, 0.21, 0.6, 0, 27843),
(79490, 0.347222, 1.5, 0, 27843),
(83844, 1.199188, 1.05, 0, 27843),
(76998, 0.306, 1.5, 0, 27843),
(83756, 0.9344095, 1.5, 0, 27843),
(83734, 0.8073308, 1, 0, 27843),
(83750, 0.9344095, 1.5, 0, 27843),
(83753, 0.9344095, 1.5, 0, 27843),
(84486, 0.9344095, 1.5, 0, 27843),
(79321, 0.306, 1.5, 0, 27843),
(80641, 0.8073308, 1, 0, 27843),
(80258, 2.107766, 3.5, 0, 27843),
(80647, 1.009162, 1.5, 0, 27843),
(80660, 0.9344095, 1.5, 0, 27843),
(82747, 0.306, 1.5, 0, 27843),
(85411, 0.306, 1.5, 0, 27843),
(85412, 0.306, 1.5, 0, 27843),
(80487, 0.8073308, 1, 0, 27843),
(80623, 0.8073308, 1, 0, 27843),
(80740, 0.347222, 1.5, 0, 27843),
(81233, 3.872211, 1.875, 0, 27843),
(75596, 1.967838, 3, 0, 27843),
(80465, 0.35, 1, 0, 27843),
(80503, 1.239107, 0.6, 0, 27843),
(81138, 0.175, 0.5, 0, 27843),
(85251, 0.175, 0.25, 0, 27843),
(80030, 1.548884, 0.75, 0, 27843),
(84033, 0.2448, 1.2, 0, 27843),
(83699, 0.3238813, 0.3, 0, 27843),
(80464, 0.21, 0.6, 0, 27843),
(85959, 0.3366, 1.65, 0, 27843),
(85956, 0.3366, 1.65, 0, 27843),
(87765, 0.306, 1.5, 0, 27843),
(83698, 0.3238813, 0.3, 0, 27843),
(81120, 0.347222, 1.5, 0, 27843),
(87009, 0.306, 1.5, 0, 27843),
(79320, 0.306, 1.5, 0, 27843),
(81018, 0.3672, 1.8, 0, 27843),
(81020, 0.306, 1.5, 0, 27843),
(84414, 0.33048, 1.62, 0, 27843),
(81019, 0.306, 1.5, 0, 27843),
(85955, 0.3366, 1.65, 0, 27843),
(84363, 3.732205, 3, 0, 27843),
(85958, 0.3366, 1.65, 0, 27843),
(81051, 0.33048, 1.62, 0, 27843),
(85174, 0.221527, 1.5, 0, 27843),
(75324, 0.7491179, 1.5, 0, 27843),
(84722, 0.306, 1.5, 0, 27843),
(83697, 0.3238813, 0.3, 0, 27843),
(75323, 0.7491179, 1.5, 0, 27843),
(75322, 0.7491179, 1.5, 0, 27843),
(75325, 0.7491179, 1.5, 0, 27843),
(81021, 0.306, 1.5, 0, 27843),
(85953, 0.306, 1.5, 0, 27843),
(77899, 3.732205, 3, 0, 27843),
(78127, 1.992649, 2.2, 0, 27843),
(77483, 1.992649, 2.2, 0, 27843),
(75599, 2.623784, 4, 0, 27843),
(85248, 0.175, 0.25, 0, 27843),
(80993, 2.107766, 3.5, 0, 27843),
(76694, 1.199188, 1.05, 0, 27843),
(84822, 1.967838, 3, 0, 27843),
(85225, 1.967838, 3, 0, 27843),
(83749, 0.9344095, 1.5, 0, 27843),
(84494, 0.9344095, 1.5, 0, 27843),
(80652, 0.9344095, 1.5, 0, 27843),
(80650, 0.9344095, 1.5, 0, 27843),
(84495, 0.9344095, 1.5, 0, 27843),
(80649, 0.9344095, 1.5, 0, 27843),
(84500, 0.8073308, 1, 0, 27843),
(84484, 1.009162, 1.5, 0, 27843),
(81252, 0.968797, 1.2, 0, 27843),
(84492, 0.9344095, 1.5, 0, 27843),
(82881, 1, 8, 0, 27843),
(88594, 0.5695243, 1.5, 0, 27843),
(84493, 0.9344095, 1.5, 0, 27843),
(80662, 0.8073308, 1, 0, 27843),
(84497, 0.8073308, 1, 0, 27843),
(79326, 0.306, 1.5, 0, 27843),
(82710, 1.89, 1, 0, 27843),
(80651, 0.9344095, 1.5, 0, 27843),
(80659, 0.9344095, 1.5, 0, 27843),
(84481, 0.9344095, 1.5, 0, 27843),
(84489, 0.8073308, 1, 0, 27843),
(80642, 1.009162, 1.5, 0, 27843),
(80654, 0.9344095, 1.5, 0, 27843),
(80624, 0.8073308, 1, 0, 27843),
(85252, 0.175, 0.25, 0, 27843),
(84499, 0.8073308, 1, 0, 27843),
(80656, 0.9344095, 1.5, 0, 27843),
(85250, 0.4296477, 0.2, 0, 27843),
(80661, 0.9344095, 1.5, 0, 27843),
(84498, 0.8073308, 1, 0, 27843),
(80655, 0.9344095, 1.5, 0, 27843),
(84488, 0.8073308, 1, 0, 27843),
(80658, 0.9344095, 1.5, 0, 27843),
(84490, 0.8073308, 1, 0, 27843),
(80657, 0.9344095, 1.5, 0, 27843),
(79862, 0.347222, 1.5, 0, 27843),
(79861, 0.347222, 1.5, 0, 27843),
(79877, 0.306, 1.5, 0, 27843),
(84482, 0.9344095, 1.5, 0, 27843),
(79323, 0.306, 1.5, 0, 27843),
(79912, 0.306, 1.5, 0, 27843),
(79863, 0.3672, 1.8, 0, 27843);

UPDATE `creature_model_info` SET `BoundingRadius`=0.7243746, `VerifiedBuild`=27843 WHERE `DisplayID`=1536;
UPDATE `creature_model_info` SET `BoundingRadius`=2.715835, `CombatReach`=1.4, `VerifiedBuild`=27843 WHERE `DisplayID`=8184;
UPDATE `creature_model_info` SET `BoundingRadius`=3.904013, `VerifiedBuild`=27843 WHERE `DisplayID`=1539;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199188, `CombatReach`=1.05, `VerifiedBuild`=27843 WHERE `DisplayID`=15468;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8188583, `VerifiedBuild`=27843 WHERE `DisplayID`=2609;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=2, `VerifiedBuild`=27843 WHERE `DisplayID`=43155;
UPDATE `creature_model_info` SET `BoundingRadius`=0.42, `CombatReach`=0.6, `VerifiedBuild`=27843 WHERE `DisplayID`=55697;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=27843 WHERE `DisplayID`=37604;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3426252, `VerifiedBuild`=27843 WHERE `DisplayID`=45645;
UPDATE `creature_model_info` SET `BoundingRadius`=1.119662, `CombatReach`=0.9, `VerifiedBuild`=27843 WHERE `DisplayID`=3248;
UPDATE `creature_model_info` SET `BoundingRadius`=0.629891, `VerifiedBuild`=27843 WHERE `DisplayID`=1534;
UPDATE `creature_model_info` SET `BoundingRadius`=1.866102, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=2305;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2569689, `VerifiedBuild`=27843 WHERE `DisplayID`=38733;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4296477, `CombatReach`=0.2, `VerifiedBuild`=27843 WHERE `DisplayID`=45906;
UPDATE `creature_model_info` SET `BoundingRadius`=2.146018, `CombatReach`=1.725, `VerifiedBuild`=27843 WHERE `DisplayID`=1105;
UPDATE `creature_model_info` SET `BoundingRadius`=2.146018, `CombatReach`=1.725, `VerifiedBuild`=27843 WHERE `DisplayID`=10825;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2165736, `VerifiedBuild`=27843 WHERE `DisplayID`=36599;
UPDATE `creature_model_info` SET `BoundingRadius`=1.866102, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=10824;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1069299, `VerifiedBuild`=27843 WHERE `DisplayID`=1072;
UPDATE `creature_model_info` SET `BoundingRadius`=1.199188, `CombatReach`=1.05, `VerifiedBuild`=27843 WHERE `DisplayID`=31460;

DELETE FROM `npc_vendor` WHERE (`entry`=127431 AND `item`=162566 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127431 AND `item`=162570 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127431 AND `item`=162569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139864 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139864 AND `item`=162563 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139864 AND `item`=162570 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=160712 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=160710 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=160709 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=160400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=160399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=160398 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=160705 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135081 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139841 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=127428 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=127428 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126814 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126814 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126814 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126814 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126814 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=126814 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=138701 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=163203 AND `ExtendedCost`=6426 AND `type`=1) OR (`entry`=124109 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=160502 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124109 AND `item`=163569 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=135804 AND `item`=162772 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162769 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162766 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162763 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162755 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=135804 AND `item`=162727 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162735 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162734 AND `ExtendedCost`=6418 AND `type`=1) OR (`entry`=135804 AND `item`=162719 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162726 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162725 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162705 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162698 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=163313 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=162694 AND `ExtendedCost`=6419 AND `type`=1) OR (`entry`=135804 AND `item`=160548 AND `ExtendedCost`=6306 AND `type`=1) OR (`entry`=135804 AND `item`=161773 AND `ExtendedCost`=6308 AND `type`=1) OR (`entry`=135804 AND `item`=165235 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135804 AND `item`=165241 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135804 AND `item`=165245 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135804 AND `item`=165249 AND `ExtendedCost`=6310 AND `type`=1) OR (`entry`=135804 AND `item`=161999 AND `ExtendedCost`=6314 AND `type`=1) OR (`entry`=135804 AND `item`=163213 AND `ExtendedCost`=6448 AND `type`=1) OR (`entry`=135804 AND `item`=165236 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135804 AND `item`=165238 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135804 AND `item`=165243 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135804 AND `item`=165246 AND `ExtendedCost`=6309 AND `type`=1) OR (`entry`=135804 AND `item`=159753 AND `ExtendedCost`=6422 AND `type`=1) OR (`entry`=135804 AND `item`=163211 AND `ExtendedCost`=6422 AND `type`=1) OR (`entry`=135804 AND `item`=160529 AND `ExtendedCost`=6305 AND `type`=1) OR (`entry`=124108 AND `item`=162566 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=124108 AND `item`=162569 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(127431, 4, 162566, 0, 0, 1, 0, 0, 27843), -- Sun-Turned Curds
(127431, 2, 162570, 0, 0, 1, 0, 0, 27843), -- Pricklevine Juice
(127431, 1, 162569, 0, 0, 1, 0, 0, 27843), -- Sun-Parched Waterskin
(139864, 4, 3371, 0, 0, 1, 0, 0, 27843), -- Crystal Vial
(139864, 2, 162563, 0, 0, 1, 0, 0, 27843), -- Succulent Dunemelon
(139864, 1, 162570, 0, 0, 1, 0, 0, 27843), -- Pricklevine Juice
(135081, 10, 160712, 0, 0, 1, 0, 0, 27843), -- Powdered Sugar
(135081, 9, 160710, 0, 0, 1, 0, 0, 27843), -- Wild Berries
(135081, 8, 160709, 0, 0, 1, 0, 0, 27843), -- Fresh Potato
(135081, 7, 160400, 0, 0, 1, 0, 0, 27843), -- Foosaka
(135081, 6, 160399, 0, 0, 1, 0, 0, 27843), -- Wild Flour
(135081, 5, 160398, 0, 0, 1, 0, 0, 27843), -- Choral Honey
(135081, 4, 160705, 0, 0, 1, 0, 0, 27843), -- Major's Frothy Coffee
(135081, 3, 2678, 0, 0, 1, 0, 0, 27843), -- Mild Spices
(135081, 2, 30817, 0, 0, 1, 0, 0, 27843), -- Simple Flour
(135081, 1, 159, 0, 0, 1, 0, 0, 27843), -- Refreshing Spring Water
(139841, 1, 37460, 0, 0, 1, 0, 0, 27843), -- Rope Pet Leash
(127428, 10, 163203, 0, 6426, 1, 0, 0, 27843), -- Hypersensitive Azeritometer Sensor
(127428, 9, 3857, 0, 0, 1, 0, 0, 27843), -- Coal
(127428, 8, 18567, 0, 0, 1, 0, 0, 27843), -- Elemental Flux
(127428, 7, 160298, 0, 0, 1, 0, 0, 27843), -- Durable Flux
(127428, 6, 3466, 0, 0, 1, 0, 0, 27843), -- Strong Flux
(127428, 5, 2880, 0, 0, 1, 0, 0, 27843), -- Weak Flux
(127428, 4, 5956, 0, 0, 1, 0, 0, 27843), -- Blacksmith Hammer
(127428, 3, 2901, 0, 0, 1, 0, 0, 27843), -- Mining Pick
(127428, 2, 160502, 0, 0, 1, 0, 0, 27843), -- Chemical Blasting Cap
(127428, 1, 163569, 0, 0, 1, 0, 0, 27843), -- Insulated Wiring
(126814, 6, 3857, 0, 0, 1, 0, 0, 27843), -- Coal
(126814, 5, 18567, 0, 0, 1, 0, 0, 27843), -- Elemental Flux
(126814, 4, 3466, 0, 0, 1, 0, 0, 27843), -- Strong Flux
(126814, 3, 2880, 0, 0, 1, 0, 0, 27843), -- Weak Flux
(126814, 2, 5956, 0, 0, 1, 0, 0, 27843), -- Blacksmith Hammer
(126814, 1, 2901, 0, 0, 1, 0, 0, 27843), -- Mining Pick
(138701, 1, 37460, 0, 0, 1, 0, 0, 27843), -- Rope Pet Leash
(124109, 10, 163203, 0, 6426, 1, 0, 0, 27843), -- Hypersensitive Azeritometer Sensor
(124109, 9, 3857, 0, 0, 1, 0, 0, 27843), -- Coal
(124109, 8, 18567, 0, 0, 1, 0, 0, 27843), -- Elemental Flux
(124109, 7, 160298, 0, 0, 1, 0, 0, 27843), -- Durable Flux
(124109, 6, 3466, 0, 0, 1, 0, 0, 27843), -- Strong Flux
(124109, 5, 2880, 0, 0, 1, 0, 0, 27843), -- Weak Flux
(124109, 4, 5956, 0, 0, 1, 0, 0, 27843), -- Blacksmith Hammer
(124109, 3, 2901, 0, 0, 1, 0, 0, 27843), -- Mining Pick
(124109, 2, 160502, 0, 0, 1, 0, 0, 27843), -- Chemical Blasting Cap
(124109, 1, 163569, 0, 0, 1, 0, 0, 27843), -- Insulated Wiring
(135804, 30, 162772, 0, 6419, 1, 0, 0, 27843), -- Pattern: Embroidered Deep Sea Cloak
(135804, 29, 162769, 0, 6419, 1, 0, 0, 27843), -- Pattern: Deep Sea Bag
(135804, 28, 162766, 0, 6419, 1, 0, 0, 27843), -- Recipe: Recurve Bow of the Strands
(135804, 27, 162763, 0, 6419, 1, 0, 0, 27843), -- Design: Royal Quartz Loop
(135804, 26, 162755, 0, 6418, 1, 0, 0, 27843), -- Recipe: Contract: Voldunai
(135804, 25, 162727, 0, 6419, 1, 0, 0, 27843), -- Schematic: Frost-Laced Ammunition
(135804, 24, 162735, 0, 6419, 1, 0, 0, 27843), -- Schematic: AZ3-R1-T3 Orthogonal Optics
(135804, 23, 162734, 0, 6418, 1, 0, 0, 27843), -- Schematic: AZ3-R1-T3 Orthogonal Optics
(135804, 22, 162719, 0, 6419, 1, 0, 0, 27843), -- Formula: Enchant Ring - Pact of Versatility
(135804, 21, 162726, 0, 6419, 1, 0, 0, 27843), -- Formula: Enchant Weapon - Versatile Navigation
(135804, 20, 162725, 0, 6419, 1, 0, 0, 27843), -- Formula: Enchant Weapon - Gale-Force Striking
(135804, 19, 162705, 0, 6419, 1, 0, 0, 27843), -- Recipe: Coastal Rejuvenation Potion
(135804, 18, 162698, 0, 6419, 1, 0, 0, 27843), -- Recipe: Flask of the Undertow
(135804, 17, 163313, 0, 6419, 1, 0, 0, 27843), -- Recipe: Battle Potion of Agility
(135804, 16, 162694, 0, 6419, 1, 0, 0, 27843), -- Recipe: Potion of Rising Death
(135804, 15, 160548, 0, 6306, 1, 0, 0, 27843), -- Tabard of the Voldunai
(135804, 14, 161773, 0, 6308, 1, 0, 0, 27843), -- Reins of the Alabaster Hyena
(135804, 13, 165235, 0, 6310, 1, 0, 0, 27843), -- -Unknown-
(135804, 12, 165241, 0, 6310, 1, 0, 0, 27843), -- -Unknown-
(135804, 11, 165245, 0, 6310, 1, 0, 0, 27843), -- -Unknown-
(135804, 10, 165249, 0, 6310, 1, 0, 0, 27843), -- -Unknown-
(135804, 9, 161999, 0, 6314, 1, 0, 0, 27843), -- Pack of Many Pockets
(135804, 8, 163213, 0, 6448, 1, 0, 0, 27843), -- Ghostly Explorer's Skull
(135804, 7, 165236, 0, 6309, 1, 0, 0, 27843), -- -Unknown-
(135804, 6, 165238, 0, 6309, 1, 0, 0, 27843), -- -Unknown-
(135804, 5, 165243, 0, 6309, 1, 0, 0, 27843), -- -Unknown-
(135804, 4, 165246, 0, 6309, 1, 0, 0, 27843), -- -Unknown-
(135804, 3, 159753, 0, 6422, 1, 0, 0, 27843), -- Desert Flute
(135804, 2, 163211, 0, 6422, 1, 0, 0, 27843), -- Akunda's Firesticks
(135804, 1, 160529, 0, 6305, 1, 0, 0, 27843), -- Dune Shroud
(124108, 4, 162566, 0, 0, 1, 0, 0, 27843), -- Sun-Turned Curds
(124108, 1, 162569, 0, 0, 1, 0, 0, 27843); -- Sun-Parched Waterskin


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=127570 AND `ID`=1) OR (`CreatureID`=139901 AND `ID`=1) OR (`CreatureID`=127513 AND `ID`=1) OR (`CreatureID`=127515 AND `ID`=1) OR (`CreatureID`=127422 AND `ID`=1) OR (`CreatureID`=127420 AND `ID`=1) OR (`CreatureID`=127406 AND `ID`=1) OR (`CreatureID`=126697 AND `ID`=1) OR (`CreatureID`=133465 AND `ID`=1) OR (`CreatureID`=129276 AND `ID`=1) OR (`CreatureID`=122289 AND `ID`=1) OR (`CreatureID`=142619 AND `ID`=1) OR (`CreatureID`=129652 AND `ID`=1) OR (`CreatureID`=134555 AND `ID`=1) OR (`CreatureID`=122782 AND `ID`=1) OR (`CreatureID`=123865 AND `ID`=1) OR (`CreatureID`=122745 AND `ID`=1) OR (`CreatureID`=123863 AND `ID`=1) OR (`CreatureID`=123864 AND `ID`=1) OR (`CreatureID`=130341 AND `ID`=1) OR (`CreatureID`=123876 AND `ID`=1) OR (`CreatureID`=138717 AND `ID`=1) OR (`CreatureID`=138716 AND `ID`=1) OR (`CreatureID`=122741 AND `ID`=1) OR (`CreatureID`=138707 AND `ID`=1) OR (`CreatureID`=138715 AND `ID`=1) OR (`CreatureID`=122746 AND `ID`=1) OR (`CreatureID`=129774 AND `ID`=1) OR (`CreatureID`=136720 AND `ID`=1) OR (`CreatureID`=130466 AND `ID`=1) OR (`CreatureID`=123772 AND `ID`=1) OR (`CreatureID`=133078 AND `ID`=1) OR (`CreatureID`=123776 AND `ID`=1) OR (`CreatureID`=123775 AND `ID`=1) OR (`CreatureID`=123773 AND `ID`=1) OR (`CreatureID`=123774 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(127570, 1, 94106, 0, 0, 94194, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(139901, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Akunda the Lookout
(127513, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Akunda the Stout
(127515, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Akunda the Vigilant
(127422, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Akunda the Protector
(127420, 1, 156511, 0, 0, 0, 0, 0, 0, 0, 0), -- Akunda the Defender
(127406, 1, 157852, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Relic Hunter
(126697, 1, 114915, 0, 0, 0, 0, 0, 0, 0, 0), -- Grozztok the Blackheart
(133465, 1, 163737, 0, 0, 0, 0, 0, 0, 0, 0), -- Sandfury Assassin
(129276, 1, 116644, 0, 0, 116644, 0, 0, 0, 0, 0), -- Sandfury Assassin
(122289, 1, 94106, 0, 0, 94194, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(142619, 1, 160451, 0, 0, 0, 0, 0, 0, 0, 0), -- Zandalari Exile
(129652, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Dervish
(134555, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Gunner
(122782, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Mender
(123865, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Champion
(122745, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Faithless Sandscout
(123863, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Aggressor
(123864, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Ravager
(130341, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(123876, 1, 151334, 0, 0, 151334, 0, 0, 0, 0, 0), -- Nisha
(138717, 1, 128196, 0, 0, 63612, 0, 0, 0, 0, 0), -- Vulpera Guardian
(138716, 1, 128196, 0, 0, 63612, 0, 0, 0, 0, 0), -- Vulpera Guardian
(122741, 1, 94106, 0, 0, 0, 0, 0, 0, 0, 0), -- Bladeguard Kaja
(138707, 1, 128196, 0, 0, 63612, 0, 0, 0, 0, 0), -- Vulpera Guardian
(138715, 1, 128196, 0, 0, 63612, 0, 0, 0, 0, 0), -- Vulpera Guardian
(122746, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Faithless Skycaller
(129774, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- -Unknown-
(136720, 1, 156876, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Ambusher
(130466, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Fangcaller Sraka
(123772, 1, 156876, 0, 0, 156876, 0, 0, 0, 0, 0), -- Sethrak Sandscout
(133078, 1, 156877, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Warbringer
(123776, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Skycaller
(123775, 1, 151335, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Warden
(123773, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0), -- Sethrak Ravager
(123774, 1, 151334, 0, 0, 0, 0, 0, 0, 0, 0); -- Sethrak Aggressor


DELETE FROM `gossip_menu` WHERE (`MenuId`=21616 AND `TextId`=32959) OR (`MenuId`=22746 AND `TextId`=35200) OR (`MenuId`=21094 AND `TextId`=32008) OR (`MenuId`=21437 AND `TextId`=32858) OR (`MenuId`=21620 AND `TextId`=32960) OR (`MenuId`=21601 AND `TextId`=32937) OR (`MenuId`=21651 AND `TextId`=32975) OR (`MenuId`=22423 AND `TextId`=34392) OR (`MenuId`=22860 AND `TextId`=35426) OR (`MenuId`=23063 AND `TextId`=35659) OR (`MenuId`=21246 AND `TextId`=32245) OR (`MenuId`=21877 AND `TextId`=33437) OR (`MenuId`=21875 AND `TextId`=33434);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(21616, 32959, 27843), -- 127431 (Akunda the Bountiful)
(22746, 35200, 27843), -- 127436 (Akunda the Agile)
(21094, 32008, 27843), -- 127570 (Bladeguard Kaja)
(21437, 32858, 27843), -- 126235 (Meerah)
(21620, 32960, 27843), -- 127428 (Akunda the Skilled)
(21601, 32937, 27843), -- 127992 (Akunda the Exalted)
(21651, 32975, 27843), -- 126814 (Ranah)
(22423, 34392, 27843), -- 126696 (Jorak)
(22860, 35426, 27843), -- 123876 (Nisha)
(23063, 35659, 27843), -- Keeyo
(21246, 32245, 27843), -- 124108 (Hagashi)
(21877, 33437, 27843), -- 130474 (Reckless Vulpera)
(21875, 33434, 27843); -- 130455

UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=9821 AND `TextId`=13584); -- 0
UPDATE `gossip_menu` SET `VerifiedBuild`=27843 WHERE (`MenuId`=10182 AND `TextId`=14127); -- 0
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=21616 AND `OptionIndex`=1) OR (`MenuId`=21616 AND `OptionIndex`=0) OR (`MenuId`=21620 AND `OptionIndex`=0) OR (`MenuId`=21437 AND `OptionIndex`=1) OR (`MenuId`=21651 AND `OptionIndex`=0) OR (`MenuId`=21437 AND `OptionIndex`=0) OR (`MenuId`=21246 AND `OptionIndex`=1) OR (`MenuId`=21246 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(21616, 1, 1, 'Let me browse your goods.', 7509, 27843),
(21616, 0, 5, 'Make this inn your home.', 162070, 27843),
(21620, 0, 1, 'Can you repair equipment?', 143334, 27843),
(21437, 1, 0, 'We\'re ready to leave.', 136153, 27843),
(21651, 0, 1, 'Can you repair equipment?', 143334, 27843),
(21437, 0, 0, 'We\'re ready to leave.', 136153, 27843),
(21246, 1, 1, 'Let me browse your goods.', 7509, 27843),
(21246, 0, 5, 'Make this inn your home.', 162070, 27843);

UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=127439; -- Akunda the Divine
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=130571; -- Akunda the Forlorn
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=127438; -- Akunda the Blessed
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=127440; -- Akunda the Revered
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127980; -- Akunda the Sensible
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67143680 WHERE `entry`=135739; -- Akunda
UPDATE `creature_template` SET `gossip_menu_id`=21094, `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127570; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=127441; -- Akunda the Hallowed
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127691; -- Jorak
UPDATE `creature_template` SET `minlevel`=114, `maxlevel`=114, `faction`=1665, `speed_walk`=1.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2164736, `VehicleId`=5612 WHERE `entry`=127742; -- Meerah's Caravan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139901; -- Akunda the Lookout
UPDATE `creature_template` SET `gossip_menu_id`=21620, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=4225, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127428; -- Akunda the Skilled
UPDATE `creature_template` SET `gossip_menu_id`=21616, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=65665, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127431; -- Akunda the Bountiful
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139864; -- Akunda the Resourceful
UPDATE `creature_template` SET `gossip_menu_id`=21601, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127992; -- Akunda the Exalted
UPDATE `creature_template` SET `gossip_menu_id`=22746, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127436; -- Akunda the Agile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127434; -- Akunda the Verbose
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127437; -- Akunda the Silent
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139888; -- Akunda the Fatigued
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=135229; -- Akunda the Serene
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=135228; -- Akunda the Courageous
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=135222; -- Akunda the Nimble
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=141491; -- Akunda the Helpful
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127435; -- Akunda the Patient
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135081; -- Akunda the Cook
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=8193, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127427; -- Akunda the Tamer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127517; -- Akunda the Astute
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127513; -- Akunda the Stout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127515; -- Akunda the Vigilant
UPDATE `creature_template` SET `gossip_menu_id`=22746, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127433; -- Akunda the Sturdy
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=67110912 WHERE `entry`=139833; -- Pterrordax
UPDATE `creature_template` SET `gossip_menu_id`=9821, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=129, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139841; -- Akunda the Calm
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=67110912 WHERE `entry`=139835; -- Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=67110912 WHERE `entry`=139831; -- Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=135069; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127422; -- Akunda the Protector
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=135068; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=127420; -- Akunda the Defender
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134690; -- Ambermane Gazelle
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134698; -- Ambermane Fawn
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=134699; -- Ambermane Buck
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134744; -- Redrock Howler
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `speed_run`=1.714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133566; -- Ranishu Swarmer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=133560; -- Stormhide Calf
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `dynamicflags`=128 WHERE `entry`=134743; -- Stormhide Calf
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133565; -- Ranishu Gorger
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=134700; -- Vale Flutterby
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134718; -- Redrock Scavenger
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=4196352 WHERE `entry`=122530; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536871680, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=133561; -- Ancient Stonehide
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=134746; -- Arid Beetle
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=135494; -- Slateclaw Shrieker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138200; -- Withered Lasher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=142780; -- Dustmane Pack Leader
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138198; -- Distorted Memory
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138202; -- Withered Lashling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134108; -- Ahjani Vulture
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=127406; -- Sethrak Relic Hunter
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=125882; -- Scorpashi Direclaw
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=138766; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=127169; -- Colossal Water Cobra
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135061; -- Water Serpent
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130316; -- Ringhorn Strider
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=188, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130317; -- Ringhorn Fawn
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130321; -- Ringhorn Stag
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=138759; -- Invisible Stalker
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=138758; -- Invisible Stalker
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67110912, `dynamicflags`=128 WHERE `entry`=122683; -- Unwanted Memory
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138199; -- Fractured Memory
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1712, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122153; -- Scorpashi Venomtail
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=126886; -- Fertile Soil
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=142755; -- Dustmane Howler
UPDATE `creature_template` SET `gossip_menu_id`=21651, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=4227, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=126814; -- Ranah
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=133333; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=67176448, `VehicleId`=6025 WHERE `entry`=138524; -- Ranah's Mount
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=14, `speed_walk`=0.4, `speed_run`=0.1428571, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=129304; -- General Jakra'zet
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=18432 WHERE `entry`=126697; -- Grozztok the Blackheart
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133465; -- Sandfury Assassin
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130248; -- Bonebeak Scavenger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129276; -- Sandfury Assassin
UPDATE `creature_template` SET `gossip_menu_id`=21437, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=126235; -- Meerah
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122289; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=1665, `speed_walk`=1.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2164736, `VehicleId`=5588 WHERE `entry`=127575; -- Meerah's Caravan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=67141632, `unit_flags2`=2048 WHERE `entry`=126817; -- Carnivorous Thistlevine
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=126816; -- Withered Thistlevine
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=127152; -- Carnivorous Seedling
UPDATE `creature_template` SET `gossip_menu_id`=22423, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=34816 WHERE `entry`=126696; -- Jorak
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=138595; -- Rakera's Shield
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=132327; -- Blob Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2575, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=126893; -- Dune Beetle
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `VehicleId`=6233 WHERE `entry`=142618; -- Vehicle Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=142619; -- Zandalari Exile
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136615; -- Azerite-Infused Elemental
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=136613; -- Infused Crag
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=67141696, `unit_flags2`=2099200 WHERE `entry`=136614; -- Infused Bedrock
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=136663; -- Bone Beetle
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122726; -- Hakasi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135124; -- Kipp
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2899, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=122729; -- Bladeguard Jorana
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129652; -- Faithless Dervish
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=134555; -- Faithless Gunner
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123866; -- Faithless Flayer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122762; -- Hakasi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122782; -- Faithless Mender
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=122736; -- Faithless Sandscout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=129538; -- Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123865; -- Faithless Champion
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2031, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=137632; -- Ravenous Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2031, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=137633; -- Ravenous Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `dynamicflags`=128 WHERE `entry`=122764; -- Kipp
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137629; -- Mekaru
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137631; -- Neri
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122745; -- Faithless Sandscout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123863; -- Faithless Aggressor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123864; -- Faithless Ravager
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1711, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124287; -- Bonepicker Hyena
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=35653633, `unit_flags3`=8192 WHERE `entry`=135500; -- Krolusk
UPDATE `creature_template` SET `gossip_menu_id`=21094, `minlevel`=120, `maxlevel`=120, `faction`=2361, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=130341; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=130443; -- Hivemother Kraxi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2952, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=135582; -- Krolusk Sandhunter
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137406; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130348; -- Withered Lasher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130329; -- Sandstinger Drone
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=130349; -- Withered Lashling
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `dynamicflags`=128 WHERE `entry`=135004; -- Sable Polecat
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122678; -- Venomous Sandstinger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135012; -- Vivi
UPDATE `creature_template` SET `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=135011; -- Coda
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=69208064 WHERE `entry`=138107; -- Vibrant Pricklevine
UPDATE `creature_template` SET `gossip_menu_id`=22860, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=123876; -- Nisha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=67584 WHERE `entry`=126217; -- Dot
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=67584 WHERE `entry`=126219; -- Dolly
UPDATE `creature_template` SET `minlevel`=108, `maxlevel`=108, `faction`=1665, `speed_walk`=1.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2164736, `VehicleId`=5588 WHERE `entry`=127656; -- Meerah's Caravan
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2983, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138717; -- Vulpera Guardian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2983, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138716; -- Vulpera Guardian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2982, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=143325; -- Jeni
UPDATE `creature_template` SET `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=143326; -- Teel
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `speed_walk`=3.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33570816, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=25 WHERE `entry`=137050; -- Spell Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138258; -- Bonepicker Scavenger
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2361, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536 WHERE `entry`=122741; -- Bladeguard Kaja
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2982, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=140961; -- Hilda
UPDATE `creature_template` SET `gossip_menu_id`=21437, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122583; -- Meerah
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=123586; -- Kiro
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109, `faction`=2982, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124109; -- Raka
UPDATE `creature_template` SET `gossip_menu_id`=10182, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=131, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=135804; -- Hoarder Jena
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2982, `npcflag`=8193, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124107; -- Narishi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2983, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138707; -- Vulpera Guardian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=140887; -- Trained Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912, `HoverHeight`=2 WHERE `entry`=139781; -- Trained Buzzard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2983, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138715; -- Vulpera Guardian
UPDATE `creature_template` SET `gossip_menu_id`=21246, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=65665, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=124108; -- Hagashi
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048, `VehicleId`=6083 WHERE `entry`=140886; -- Buzzard's Vehicle Bunny
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `speed_walk`=0.8, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139794; -- Torra
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=139823; -- Trained Duskmane
UPDATE `creature_template` SET `gossip_menu_id`=23063, `minlevel`=108, `maxlevel`=120, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=141879; -- Keeyo
UPDATE `creature_template` SET `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=139795; -- Nala
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=139789; -- Trained Duskmane
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=139788; -- Trained Duskmane
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=139824; -- Trained Duskmane
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2982, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124111; -- Miri
UPDATE `creature_template` SET `gossip_menu_id`=9821, `minlevel`=120, `maxlevel`=120, `faction`=2982, `npcflag`=4194433, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=138701; -- Teego
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912, `HoverHeight`=2 WHERE `entry`=139785; -- Trained Buzzard
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126903; -- Dune Bug
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126905; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124642; -- Saurolisk Hatchling
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2952, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=127758; -- Thornspine Saurolisk
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1711, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.15 WHERE `entry`=126909; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2952, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=124654; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=122746; -- Faithless Skycaller
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=126901; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=130119; -- Pterrordax
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124019; -- -Unknown-
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=126904; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1712, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `HoverHeight`=1.15 WHERE `entry`=136664; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133234; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1712, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=124016; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=129774; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `speed_walk`=1.6, `speed_run`=2.285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=136720; -- Sethrak Ambusher
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=137799; -- Nisha
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=130466; -- Fangcaller Sraka
UPDATE `creature_template` SET `minlevel`=114, `maxlevel`=114, `faction`=1665, `speed_walk`=1.2, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=69273600, `VehicleId`=5954 WHERE `entry`=137492; -- Nisha's Wagon
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67176448 WHERE `entry`=137494; -- Alpaca
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=1665, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67176448 WHERE `entry`=137495; -- Alpaca
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137417; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=34816 WHERE `entry`=133128; -- Sethrak Cage
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123772; -- Sethrak Sandscout
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=133078; -- Sethrak Warbringer
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=137422; -- -Unknown-
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137416; -- -Unknown-
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137413; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123776; -- Sethrak Skycaller
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137412; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123775; -- Sethrak Warden
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123773; -- Sethrak Ravager
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=124527; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=124020; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=67110912 WHERE `entry`=124021; -- -Unknown-
UPDATE `creature_template` SET `faction`=2575, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137419; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=123774; -- Sethrak Aggressor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `speed_walk`=0.8, `speed_run`=0.4285714, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=124029; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2980, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=124194; -- Vulpera Captive
UPDATE `creature_template` SET `gossip_menu_id`=21875, `minlevel`=120, `maxlevel`=120, `faction`=2980, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=130455; -- -Unknown-

DELETE FROM `quest_template` WHERE `ID` IN (48895 /*-Unknown-*/, 48554 /*-Unknown-*/, 48553 /*-Unknown-*/, 48551 /*-Unknown-*/, 48555 /*-Unknown-*/, 48684 /*-Unknown-*/, 51153 /*-Unknown-*/, 51829 /*-Unknown-*/, 48550 /*-Unknown-*/, 48549 /*-Unknown-*/, 47959 /*-Unknown-*/, 50755 /*-Unknown-*/, 47322 /*-Unknown-*/, 47316 /*-Unknown-*/, 47321 /*-Unknown-*/, 47317 /*-Unknown-*/, 47320 /*-Unknown-*/, 50459 /*-Unknown-*/, 50739 /*-Unknown-*/, 51574 /*-Unknown-*/, 47319 /*-Unknown-*/, 51364 /*-Unknown-*/, 49677 /*-Unknown-*/, 47327 /*-Unknown-*/, 49676 /*-Unknown-*/, 51357 /*-Unknown-*/);
INSERT INTO `quest_template` (`ID`, `QuestType`, `QuestLevel`, `ScalingFactionGroup`, `MaxScalingLevel`, `QuestPackageID`, `MinLevel`, `QuestSortID`, `QuestInfoID`, `SuggestedGroupNum`, `RewardNextQuest`, `RewardXPDifficulty`, `RewardXPMultiplier`, `RewardMoney`, `RewardMoneyDifficulty`, `RewardMoneyMultiplier`, `RewardBonusMoney`, `RewardDisplaySpell1`, `RewardDisplaySpell2`, `RewardDisplaySpell3`, `RewardSpell`, `RewardHonor`, `RewardKillHonor`, `StartItem`, `RewardArtifactXPDifficulty`, `RewardArtifactXPMultiplier`, `RewardArtifactCategoryID`, `Flags`, `FlagsEx`, `FlagsEx2`, `RewardSkillLineID`, `RewardNumSkillUps`, `PortraitGiver`, `PortraitGiverMount`, `PortraitTurnIn`, `RewardItem1`, `RewardItem2`, `RewardItem3`, `RewardItem4`, `RewardAmount1`, `RewardAmount2`, `RewardAmount3`, `RewardAmount4`, `ItemDrop1`, `ItemDrop2`, `ItemDrop3`, `ItemDrop4`, `ItemDropQuantity1`, `ItemDropQuantity2`, `ItemDropQuantity3`, `ItemDropQuantity4`, `RewardChoiceItemID1`, `RewardChoiceItemID2`, `RewardChoiceItemID3`, `RewardChoiceItemID4`, `RewardChoiceItemID5`, `RewardChoiceItemID6`, `RewardChoiceItemQuantity1`, `RewardChoiceItemQuantity2`, `RewardChoiceItemQuantity3`, `RewardChoiceItemQuantity4`, `RewardChoiceItemQuantity5`, `RewardChoiceItemQuantity6`, `RewardChoiceItemDisplayID1`, `RewardChoiceItemDisplayID2`, `RewardChoiceItemDisplayID3`, `RewardChoiceItemDisplayID4`, `RewardChoiceItemDisplayID5`, `RewardChoiceItemDisplayID6`, `POIContinent`, `POIx`, `POIy`, `POIPriority`, `RewardTitle`, `RewardArenaPoints`, `RewardFactionID1`, `RewardFactionID2`, `RewardFactionID3`, `RewardFactionID4`, `RewardFactionID5`, `RewardFactionValue1`, `RewardFactionValue2`, `RewardFactionValue3`, `RewardFactionValue4`, `RewardFactionValue5`, `RewardFactionCapIn1`, `RewardFactionCapIn2`, `RewardFactionCapIn3`, `RewardFactionCapIn4`, `RewardFactionCapIn5`, `RewardFactionOverride1`, `RewardFactionOverride2`, `RewardFactionOverride3`, `RewardFactionOverride4`, `RewardFactionOverride5`, `RewardFactionFlags`, `AreaGroupID`, `TimeAllowed`, `AllowableRaces`, `TreasurePickerID`, `Expansion`, `LogTitle`, `LogDescription`, `QuestDescription`, `AreaDescription`, `QuestCompletionLog`, `RewardCurrencyID1`, `RewardCurrencyID2`, `RewardCurrencyID3`, `RewardCurrencyID4`, `RewardCurrencyQty1`, `RewardCurrencyQty2`, `RewardCurrencyQty3`, `RewardCurrencyQty4`, `PortraitGiverText`, `PortraitGiverName`, `PortraitTurnInText`, `PortraitTurnInName`, `AcceptedSoundKitID`, `CompleteSoundKitID`, `VerifiedBuild`) VALUES
(48895, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 19400, 1, 1, 230, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 34603016, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Perfect Offering', 'Deliver the offering to Akunda the Exalted at the Temple of Akunda.', 'Dis offering is all dat I have to my name, but it wouldn\'t be right for me to use it for myself when I know your friend is in danger. \n\nShe saved my life, now I can save hers.\n\nTake de offering. Don\'t make me ask twice.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48554, 2, -1, 5, 120, 18788, 110, 8501, 0, 0, 0, 6, 1, 194000, 5, 1, 2800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Source of the Problem', 'Help Ranah determine the cause of the malfunctioning fountain within the Withering Terrace.', 'I checked my work twice when working on this fountain. I made no mistakes. \n\nThere must be something wrong at the source. \n\nThe fountain draws water from a modest reservoir above the terrace. \n\nWould you mind checking it out?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48553, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Let it Flow', 'Repair the fountains within Withering Gulch.', 'The fountains here have seen better days. They\'re currently incapable of holding water, but we can fix that!\n\nYou can use my spare tools to repair the cracks. \n\nWith a little luck and elbow grease, the fountains will be flowing again in no time!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48551, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 152630, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152630, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Wither Without Water', 'Use Ranah\'s Watering Can to water $1oa Withered Thistlevines.', 'The flora in this area weren\'t always so aggressive. \n\nWithout water, the thistlevines wither and waste until they become something unrecognizable and angry.\n\nTake my watering can and wet the withering thistlevines to prevent them from becoming carnivorous.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48555, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33685512, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 152644, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'We Can Salvage the Seeds', 'Plant $1oa Thistlevine Seeds in Fertile Soil within the Withering Terrace.', 'I\'ve studied the flora within the terrace extensively. Once a thistlevine completely dries out, it\'s too late for the plant to be saved. \n\nIts seeds are still viable, however. Under the right conditions, they can be used to cultivate new, healthy thistlevines. \n\nSalvage seeds from the carnivorous thistlevines that can no longer be saved, and plant them within the fertile mounds of dirt. \n\nThe thistlevine plant is extremely quick to sprout, so the terrace should be filled with seedlings in no time!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48684, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 48895, 3, 1, 97000, 3, 1, 1100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 4194306, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'On the Move', 'Travel with Meerah\'s Caravan in search of Warguard Rakera.', 'Jorak\'s wounds have healed enough for him to travel.\n\nHe has agreed to guide us to de temple. \n\nDe sooner we leave, de better. Rakera won\'t survive in dis desert for long.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51153, 3, -1, 0, 120, 0, 120, 8501, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 268319, 0, 0, 0, 0, 0, 0, 37290048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2159, 2158, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7500, 7500, 0, 0, 0, 0, 0, 0, 18446744073709551615, 912, 7, 'Mor\'fani the Exile', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51829, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 1, 1, 194000, 5, 1, 230, 0, 0, 0, 0, 0, 0, 160747, 0, 1, 0, 54525960, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Ranah\'s Wrench', 'Deliver the wrench to Ranah in the Withering Gulch.', '<The wrench is worn from repeated use, but otherwise appears to be in good shape. \n\nEngraved on the handle is the name: Ranah.>', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48550, 2, -1, 5, 120, 18783, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Stolen Satchels', 'Collect $1oa Weathered Satchels from Sandfury Assassins.', 'One within our group spoke of a temple in de mountains dat welcomes exiles, though none are permitted to enter without an offering to their loa.\n\nI would have given anything to find some solace in dis wasteland, but now I have nothing, thanks to those thieving assassins.\n\nEach of us had a satchel dat carried de last of our possessions. We didn\'t have much, but it was more than one troll would need. \n\nIf you search de dunes looking for your friend, could you keep an eye out for our satchels?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(48549, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 388000, 6, 1, 2800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 171966472, 8192, 0, 0, 0, 79237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Grozztok the Blackheart', 'Kill Grozztok within Atul\'Aman.', 'A group of us were dropped off here and left to die. \n\nOur first night at camp, I was jolted from sleep by de gurgling cries of my fellow exiles. Jakra\'zet sent assassins to our camp, looking for Rakera. \n\nTheir leader, Grozztok, came for me, but Rakera intervened. \n\nShe chased him into de dunes, but dat was days ago. \n\nIf you cross paths with Grozztok, don\'t hesitate to drive a blade into his black heart.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Hired by General Jakra\'zet to slaughter exiles within Vol\'dun.', 'Grozztok the Blackheart', '', '', 890, 878, 27843), -- -Unknown-
(47959, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 97000, 3, 1, 1100, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 2, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'The Warguard\'s Trail', 'Travel with Meerah\'s Caravan in search of Warguard Rakera.', 'Rakera\'s journal suggested she moved south. It\'s de only lead we have. \n\nMeerah is headed dat way, and has invited us to travel with her. \n\nThese vulpera know de desert better than any troll I\'ve ever met. \n\nOur chances of survival are highest if we travel together.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50755, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'A Meal for Birds', 'Kill wildlife within The Brine Basin so Mekaru\'s buzzards can eat.', 'I don\'t know why I agreed to this. We weren\'t supposed to be scavenging. \n\nKiro gave me specific instructions to head to the basin and feed the buzzards.\n\nI can\'t go back to camp until they eat, but I\'m not heading into that basin while the sethrak are still swarming. \n\nHave you ever fed a buzzard? It\'s easy, I promise. \n\nYou kill it, they eat it. That simple.', '', '', 1553, 0, 0, 0, 100, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47322, 2, -1, 5, 120, 18854, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 262106, 0, 0, 0, 0, 1, 0, 39845896, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Aided Escape', 'Free Hakasi and Kipp from within The Serpent\'s Maw.', 'The sethrak may be strong, but we\'re quick. Well, at least Mekaru and I are.\n\nWe just barely made it back to the wagon with our tails attached. \n\nThe others weren\'t so lucky, I guess. We\'ve been waiting a while, and still no sign of them. \n\nIf you\'re headed into the thick of it, would you mind looking for our friends?', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47316, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 255829, 0, 0, 0, 0, 1, 0, 35651592, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Secrets in the Sand', 'Recover the journal\'s missing pages.', 'I found this journal buried in the sand. \n\nKiro tried to toss it in the fire.\n\n\"Our wagon has no space for a diary, Meerah. What practical use does it have?\"\n\nDon\'t tell him I said so, but I think it\'s fascinating! Can you imagine what kinds of secrets it holds? \n\nQuite a few pages are missing, but I bet you can recover them out on the dunes!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47321, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 265436, 0, 0, 0, 0, 1, 0, 35651592, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Knickknack Takeback', 'Collect $1oa Knickknacks from sethrak within The Serpent\'s Maw.', 'Nisha told me you came here in search of an exile. One named Rakera? \n\nWe don\'t know her, but we might be able to help you find her. \n\nYou help us, and we help you. Deal?\n\nWe survive by scavenging. We trade what we find, but the sethrak that raided our burrows made away with many of our knickknacks.    \n\nI always knew they were ruthless, but never imagined they\'d be so greedy.\n\nTake back what the sethrak have taken, and I\'ll see that you are provided safe passage through the dunes.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47317, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Searching for Survivors', 'Search for survivors near the crash site.', 'It is good to see you are safe, but what of de others? Have dey been lost to de sands?\n\nYou need to head back to de crash site and see if de others survived.\n\nI will ask around and see if these fox people can tell us anything about Rakera.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47320, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 3, 1, 97000, 3, 1, 1100, 0, 0, 0, 0, 0, 0, 150759, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150759, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 1, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'A Balm to Calm', 'Use the Restorative Balm on Bladeguard Kaja.', 'As promised, here is the balm that should remedy your companion\'s injuries. \n\nApply it liberally to any bits of exposed flesh.\n\nIts effects should be felt immediately.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50459, 3, -1, 0, 120, 0, 120, 8500, 136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 263048, 0, 0, 0, 0, 0, 0, 37290048, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2159, 2156, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 7, 7, 7500, 7500, 0, 0, 0, 0, 0, 0, 18446744073709551615, 824, 7, 'Vugthuth', '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(50739, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 159729, 0, 1, 0, 131592, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 159729, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Missing Business', 'Rescue $1oa Sable Polecats.', 'Poor little Coda has been in quite the tizzy since his friends vanished. \n\nI found him here, out cold, after a sting from one of those awful wasps. Just a tiny bit of our sandstinger remedy got Coda right up, though!\n\nTake some with you, and keep an eye out for other little ones out there.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51574, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Freshly Squeezed', 'Collect $1oa Pricklevine Juice.', 'Is this troll a friend of yours? I\'m so glad Kiro let me keep her. \n\nHe\'s a bit wary of outsiders, but he\'s a great healer. \n\nShe\'ll wake up, I promise. And when she does, she\'ll be thirsty.\n\nThe sands are short on water, but you\'re in luck. The grove that surrounds this camp is filled with pricklevines. \n\nYou wouldn\'t want to eat the flesh, but the liquid inside can quench any thirst.\n\nJust give them a good squeeze to collect their juice.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(47319, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 33554440, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Restorative Venom', 'Collect $1oa Sandstinger Venom Glands.', 'Meerah here found your friend in the dunes. The lightning strike nearly killed her. It might still, without treatment. \n\nThe wasps within the grove have a painful sting, but their venom also has restorative properties. \n\nI can extract what I need from their glands.\n\nWith an ample amount of venom, we should be able to soothe your friend\'s wounds.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51364, 2, -1, 5, 120, 18789, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 38797320, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'An Explosive Exit', 'Find Nisha\'s wagon and ride it to safety.', 'Alright, $p. I think it\'s time we make a run for it. \n\nHopefully my wagon\'s still nearby.\n\nI\'ll steer us to our hideaway. I just need you to lob explosives onto any sethrak who are brave enough to follow us.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49677, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 6, 1, 388000, 6, 1, 2800, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 167772168, 0, 0, 0, 0, 81252, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 5, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Plans for Attack', 'Recover Nisha\'s Attack Plans from Fangcaller Sraka.', 'Before we were attacked, I had a plan to take the fight to the sethrak. \n\nIt was devised with flawless intel. I know, because I gathered the information myself. \n\nI surveyed their entire compound and created a map based on my findings. \n\nMy plan relies on that map, but it\'s now in the hands of Fangcaller Sraka, the brute who\'s leading this assault on my home.\n\nHelp me kill her so I can take back what\'s mine!', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 'Leader of the attack on the Abandoned Burrows.', 'Fangcaller Sraka', '', '', 890, 878, 27843), -- -Unknown-
(47327, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Answering Their Attacks', 'Kill sethrak in the Abandoned Burrows.', 'The sethrak\'s attacks on our burrows cannot go unanswered. \n\nThey need to learn that not all within the desert will give up so easily. \n\nThe only thing the sethrak understand is blood, so that\'s the language we\'ll use to teach them.\n\n<Nisha pauses and looks at you, skeptical that you understood her.>\n\nI\'m saying we need to kill the sethrak here. All of them.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(49676, 2, -1, 5, 120, 18853, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Dressed for Battle', 'Help Nisha find a war banner, a helmet, and explosives.', 'Kiro\'s the leader of my caravan. He\'s always been far too passive.\n\nI warned him we needed to make a preemptive strike against the sethrak, but he insisted that we keep our heads down and continue to quietly do business.\n\nLook where that got us.\n\nOur caravan was completely unprepared for their attack. \n\nNow I\'m ready to fight for what\'s ours, but I\'m not exactly dressed for battle.\n\nHelp me scavenge some suitable equipment here among our enemies. We will use their own tools against them.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843), -- -Unknown-
(51357, 2, -1, 5, 120, 0, 110, 8501, 0, 0, 0, 5, 1, 194000, 5, 1, 2250, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 37748744, 8192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2158, 0, 0, 0, 0, 3, 0, 0, 0, 0, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 12261800583900083122, 0, 7, 'Armed and Ready', 'Choose a weapon for Nisha.', 'You must be special if the sethrak didn\'t kill you right away.\n \nEither that, or you\'d fetch a good price at the slave market.\n\nDon\'t worry though. We\'re getting out of here.\n\nI have a wagon at the entrance, but no weapon to fight with.\n \nLuckily, it seems the sethrak have plenty.', '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', 890, 878, 27843); -- -Unknown-


DELETE FROM `quest_objectives` WHERE `ID` IN (293275 /*293275*/, 336936 /*336936*/, 292768 /*292768*/, 336926 /*336926*/, 292633 /*292633*/, 292622 /*292622*/, 292873 /*292873*/, 292898 /*292898*/, 292787 /*292787*/, 334875 /*334875*/, 337307 /*337307*/, 292760 /*292760*/, 292751 /*292751*/, 292762 /*292762*/, 292756 /*292756*/, 335811 /*335811*/, 290885 /*290885*/, 290880 /*290880*/, 290480 /*290480*/, 290495 /*290495*/, 290887 /*290887*/, 338775 /*338775*/, 290478 /*290478*/, 290408 /*290408*/, 290407 /*290407*/, 290472 /*290472*/, 312626 /*312626*/, 333665 /*333665*/, 336300 /*336300*/, 336297 /*336297*/, 290427 /*290427*/, 340548 /*340548*/, 335921 /*335921*/, 335622 /*335622*/, 335551 /*335551*/, 295044 /*295044*/, 290889 /*290889*/, 295042 /*295042*/, 295041 /*295041*/, 295037 /*295037*/, 335530 /*335530*/);
INSERT INTO `quest_objectives` (`ID`, `QuestID`, `Type`, `Order`, `StorageIndex`, `ObjectID`, `Amount`, `Flags`, `Flags2`, `ProgressBarWeight`, `Description`, `VerifiedBuild`) VALUES
(293275, 48895, 1, 0, 0, 152894, 1, 0, 1, 0, '', 27843), -- 293275
(336936, 48554, 0, 1, 0, 127169, 1, 3, 0, 0, '', 27843), -- 336936
(292768, 48554, 0, 0, 1, 127167, 1, 0, 0, 0, 'Reservoir inspected', 27843), -- 292768
(336926, 48553, 0, 1, 1, 138756, 1, 0, 0, 0, 'South fountain fixed', 27843), -- 336926
(292633, 48553, 0, 0, 0, 138754, 1, 0, 0, 0, 'North fountain fixed', 27843), -- 292633
(292622, 48551, 0, 0, 0, 126816, 10, 0, 0, 0, 'Withered Thistlevines watered', 27843), -- 292622
(292873, 48555, 0, 0, 0, 126886, 8, 0, 0, 0, 'Thistlevine Seeds planted', 27843), -- 292873
(292898, 48684, 0, 1, 1, 127575, 1, 3, 0, 0, 'Ride Meerah\'s caravan', 27843), -- 292898
(292787, 48684, 0, 0, 0, 126235, 1, 1, 0, 0, 'Speak to Meerah', 27843), -- 292787
(334875, 51153, 0, 0, 0, 134694, 1, 0, 0, 0, '', 27843), -- 334875
(337307, 51829, 1, 0, 0, 160747, 1, 0, 1, 0, '', 27843), -- 337307
(292760, 48550, 1, 0, 0, 152660, 5, 0, 1, 0, '', 27843), -- 292760
(292751, 48549, 0, 0, 0, 126697, 1, 1, 0, 0, '', 27843), -- 292751
(292762, 47959, 0, 1, 1, 127656, 1, 3, 0, 0, 'Ride Meerah\'s Caravan', 27843), -- 292762
(292756, 47959, 0, 0, 0, 122583, 1, 1, 0, 0, 'Speak to Meerah', 27843), -- 292756
(335811, 50755, 0, 0, 0, 124016, 8, 0, 0, 0, 'Buzzards fed', 27843), -- 335811
(290885, 47322, 2, 3, 1, 271840, 1, 28, 0, 0, '', 27843), -- 290885
(290880, 47322, 2, 2, 0, 271839, 1, 28, 0, 0, '', 27843), -- 290880
(290480, 47322, 0, 1, 5, 122764, 1, 0, 0, 0, 'Kipp rescued', 27843), -- 290480
(290495, 47322, 0, 0, 2, 122762, 1, 0, 0, 0, 'Hakasi rescued', 27843), -- 290495
(290887, 47316, 1, 0, 0, 151346, 4, 1, 1, 0, 'Journal Pages recovered', 27843), -- 290887
(338775, 47321, 1, 1, 1, 151278, 6, 28, 1, 0, '', 27843), -- 338775
(290478, 47321, 1, 0, 0, 151273, 6, 0, 1, 0, 'Knickknacks collected', 27843), -- 290478
(290408, 47317, 0, 1, 1, 122729, 1, 0, 0, 0, 'Jorana found', 27843), -- 290408
(290407, 47317, 2, 0, 2, 271014, 1, 0, 0, 0, 'Tarkaj found', 27843), -- 290407
(290472, 47320, 0, 0, 0, 122741, 1, 0, 0, 0, 'Restorative Balm applied', 27843), -- 290472
(312626, 50459, 0, 0, 0, 128584, 1, 0, 0, 0, '', 27843), -- 312626
(333665, 50739, 0, 0, 0, 135004, 7, 0, 0, 0, 'Sable Polecat revived', 27843), -- 333665
(336300, 51574, 0, 1, 1, 138107, 8, 28, 0, 0, '', 27843), -- 336300
(336297, 51574, 1, 0, 0, 160448, 8, 0, 1, 0, '', 27843), -- 336297
(290427, 47319, 1, 0, 0, 160441, 15, 0, 1, 0, '', 27843), -- 290427
(340548, 51364, 0, 3, 0, 137503, 1, 0, 0, 0, 'Ride to Vulpera Hideaway', 27843), -- 340548
(335921, 51364, 0, 2, 3, 136720, 1, 2, 0, 0, 'Defend Nisha\'s wagon', 27843), -- 335921
(335622, 51364, 0, 1, 1, 137492, 1, 2, 0, 0, 'Board Nisha\'s wagon', 27843), -- 335622
(335551, 51364, 0, 0, 2, 137796, 1, 0, 0, 0, 'Find Nisha\'s wagon', 27843), -- 335551
(295044, 49677, 1, 0, 0, 158651, 1, 1, 1, 0, '', 27843), -- 295044
(290889, 47327, 0, 0, 0, 123772, 12, 0, 0, 0, 'Sethrak slain', 27843), -- 290889
(295042, 49676, 2, 2, 0, 289311, 1, 0, 0, 0, 'Explosives found', 27843), -- 295042
(295041, 49676, 0, 1, 2, 130459, 1, 0, 0, 0, 'Helmet found', 27843), -- 295041
(295037, 49676, 0, 0, 3, 130460, 1, 0, 0, 0, 'Banner found', 27843), -- 295037
(335530, 51357, 0, 0, 1, 130458, 1, 0, 0, 0, 'Weapon chosen', 27843); -- 335530


DELETE FROM `quest_visual_effect` WHERE (`ID`=292768 AND `Index`=0) OR (`ID`=336926 AND `Index`=0) OR (`ID`=292633 AND `Index`=0) OR (`ID`=292873 AND `Index`=2) OR (`ID`=292873 AND `Index`=1) OR (`ID`=292873 AND `Index`=0) OR (`ID`=292898 AND `Index`=0) OR (`ID`=292787 AND `Index`=0) OR (`ID`=292762 AND `Index`=0) OR (`ID`=292756 AND `Index`=0) OR (`ID`=290480 AND `Index`=0) OR (`ID`=290495 AND `Index`=0) OR (`ID`=290478 AND `Index`=6) OR (`ID`=290478 AND `Index`=5) OR (`ID`=290478 AND `Index`=4) OR (`ID`=290478 AND `Index`=3) OR (`ID`=290478 AND `Index`=2) OR (`ID`=290478 AND `Index`=1) OR (`ID`=290478 AND `Index`=0) OR (`ID`=290408 AND `Index`=0) OR (`ID`=290407 AND `Index`=0) OR (`ID`=290472 AND `Index`=0) OR (`ID`=336297 AND `Index`=0) OR (`ID`=335622 AND `Index`=0) OR (`ID`=335551 AND `Index`=0) OR (`ID`=295042 AND `Index`=0) OR (`ID`=295041 AND `Index`=0) OR (`ID`=295037 AND `Index`=0) OR (`ID`=335530 AND `Index`=2) OR (`ID`=335530 AND `Index`=1) OR (`ID`=335530 AND `Index`=0);
INSERT INTO `quest_visual_effect` (`ID`, `Index`, `VisualEffect`, `VerifiedBuild`) VALUES
(292768, 0, 9056, 27843),
(336926, 0, 9569, 27843),
(292633, 0, 9568, 27843),
(292873, 2, 8790, 27843),
(292873, 1, 8789, 27843),
(292873, 0, 2100, 27843),
(292898, 0, 8004, 27843),
(292787, 0, 2100, 27843),
(292762, 0, 8004, 27843),
(292756, 0, 2099, 27843),
(290480, 0, 9589, 27843),
(290495, 0, 9588, 27843),
(290478, 6, 9381, 27843),
(290478, 5, 8748, 27843),
(290478, 4, 8367, 27843),
(290478, 3, 8366, 27843),
(290478, 2, 8365, 27843),
(290478, 1, 8364, 27843),
(290478, 0, 8363, 27843),
(290408, 0, 2099, 27843),
(290407, 0, 2099, 27843),
(290472, 0, 2099, 27843),
(336297, 0, 9836, 27843),
(335622, 0, 9390, 27843),
(335551, 0, 9390, 27843),
(295042, 0, 9358, 27843),
(295041, 0, 8393, 27843),
(295037, 0, 8394, 27843),
(335530, 2, 8392, 27843),
(335530, 1, 8391, 27843),
(335530, 0, 8390, 27843);


DELETE FROM `creature_template_model` WHERE (`CreatureID`=129049 AND `CreatureDisplayID`=87401);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(129049, 0, 87401, 1, 1, 27843); -- Tottle

DELETE FROM `gameobject_template` WHERE `entry` IN (290773 /*Altar of Akunda*/, 297883 /*Ancient Gong*/, 276434 /*Temple Entrance*/, 282732 /*Forge*/, 282731 /*Anvil*/, 292604 /*Campfire*/, 292603 /*Bench*/, 292602 /*Bench*/, 282733 /*Mailbox*/, 281505 /*Rock Cluster*/, 277285 /*Sacred Remains*/, 296575 /*Julie's Cracked Dish*/, 281166 /*Blood Spatter*/, 277858 /*Carcass*/, 281608 /*Relic of the Keepers*/, 296584 /*Zach's Canteen*/, 291001 /*Fountain*/, 282203 /*Vol'dun Reservoir Regrowth*/, 282219 /*Vol'dun Reservoir Regrowth*/, 282210 /*Vol'dun Reservoir Regrowth*/, 282209 /*Vol'dun Reservoir Regrowth*/, 282220 /*Vol'dun Reservoir Regrowth*/, 282211 /*Vol'dun Reservoir Regrowth*/, 282237 /*Vol'dun Reservoir Regrowth*/, 282204 /*Vol'dun Reservoir Regrowth*/, 282198 /*Vol'dun Reservoir Regrowth*/, 282233 /*Vol'dun Reservoir Regrowth*/, 282232 /*Vol'dun Reservoir Regrowth*/, 282224 /*Vol'dun Reservoir Regrowth*/, 282228 /*Vol'dun Reservoir Regrowth*/, 282196 /*Vol'dun Reservoir Regrowth*/, 282225 /*Vol'dun Reservoir Regrowth*/, 282223 /*Vol'dun Reservoir Regrowth*/, 282236 /*Vol'dun Reservoir Regrowth*/, 282202 /*Vol'dun Reservoir Regrowth*/, 282214 /*Vol'dun Reservoir Regrowth*/, 282222 /*Vol'dun Reservoir Regrowth*/, 282227 /*Vol'dun Reservoir Regrowth*/, 282226 /*Vol'dun Reservoir Regrowth*/, 282249 /*Vol'dun Reservoir Regrowth*/, 282248 /*Vol'dun Reservoir Regrowth*/, 282235 /*Vol'dun Reservoir Regrowth*/, 282234 /*Vol'dun Reservoir Regrowth*/, 282231 /*Vol'dun Reservoir Regrowth*/, 282230 /*Vol'dun Reservoir Regrowth*/, 282229 /*Vol'dun Reservoir Regrowth*/, 282221 /*Vol'dun Reservoir Regrowth*/, 282218 /*Vol'dun Reservoir Regrowth*/, 282217 /*Vol'dun Reservoir Regrowth*/, 282216 /*Vol'dun Reservoir Regrowth*/, 282215 /*Vol'dun Reservoir Regrowth*/, 282213 /*Vol'dun Reservoir Regrowth*/, 282212 /*Vol'dun Reservoir Regrowth*/, 282208 /*Vol'dun Reservoir Regrowth*/, 282207 /*Vol'dun Reservoir Regrowth*/, 282206 /*Vol'dun Reservoir Regrowth*/, 282205 /*Vol'dun Reservoir Regrowth*/, 282201 /*Vol'dun Reservoir Regrowth*/, 282200 /*Vol'dun Reservoir Regrowth*/, 282199 /*Vol'dun Reservoir Regrowth*/, 282197 /*Vol'dun Reservoir Regrowth*/, 282195 /*Vol'dun Reservoir Regrowth*/, 282194 /*Vol'dun Reservoir Regrowth*/, 282193 /*Vol'dun Reservoir Regrowth*/, 273995 /*Loose Boulder*/, 291008 /*Terrace Fountain*/, 268635 /*Campfire*/, 281210 /*Scattered Tools*/, 281189 /*Tool Kit*/, 291057 /*Campfire*/, 287256 /*Skeleton*/, 287238 /*Ancient Altar*/, 291058 /*Campfire*/, 291113 /*Collision Wall*/, 291143 /*Ranah's Wrench*/, 276186 /*Terrace Planter*/, 291010 /*Broken Fountain*/, 273992 /*Terrace Fountain*/, 310175 /*Magic Barrier*/, 281867 /*Star Moss*/, 296573 /*Jason's Rusty Blade*/, 281656 /*Faithless War Banner*/, 281643 /*Faithless Cannon*/, 271839 /*Sethrak Cage*/, 294138 /*Fire Pit*/, 271014 /*Tarkaj's Warblade*/, 271840 /*Sethrak Cage*/, 292543 /*Chair*/, 292542 /*Campfire*/, 296587 /*Josh's Fang Necklace*/, 271844 /*Rakera's Journal Page*/, 276621 /*Rich Monelite Deposit*/, 298918 /*Loose Rock*/, 288391 /*Bonepicker Nest*/, 292601 /*Anvil*/, 292600 /*Forge*/, 290480 /*Bench*/, 290479 /*Bench*/, 289694 /*Fire Pit*/, 292599 /*Mailbox*/, 278579 /*Saurolisk Egg (Large + Shaking)*/, 278578 /*Broken Saurolisk Eggs*/, 284410 /*Treasure Chest*/, 288579 /*Campfire*/, 294142 /*Bonfire*/, 296387 /*Fire Pit*/, 289311 /*Explosives*/, 296388 /*Fire Pit*/, 296270 /*Stool*/, 296269 /*Stool*/, 296268 /*Stool*/, 296267 /*Campfire*/, 296386 /*Fire Pit*/, 288581 /*Campfire*/, 278685 /*Sethrak Skull*/, 296389 /*Fire Pit*/, 296266 /*Forge*/, 296264 /*Stool*/, 278686 /*Stolen Vulpera Banner*/, 294143 /*Bonfire*/, 296265 /*Stool*/, 296263 /*Stool*/, 296262 /*Stool*/, 296586 /*Rachel's Flute*/, 296991 /*Bonfire*/, 296990 /*Bonfire*/, 294144 /*Bonfire*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `RequiredLevel`, `VerifiedBuild`) VALUES
(290773, 10, 49846, 'Altar of Akunda', '', 'Honoring', '', 0.65, 43, 0, 0, 0, 0, 0, 0, 0, 0, 0, 272121, 0, 0, 0, 57770, 0, 0, 0, 0, 0, 1, 0, 53444, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Altar of Akunda
(297883, 10, 9806, 'Ancient Gong', 'questinteract', '', '', 1.75, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 281716, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Ancient Gong
(276434, 5, 52069, 'Temple Entrance', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Temple Entrance
(282732, 8, 48585, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(282731, 8, 48031, 'Anvil', '', '', '', 1, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(292604, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(292603, 7, 46157, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bench
(292602, 7, 46157, 'Bench', '', '', '', 1, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bench
(282733, 19, 50361, 'Mailbox', '', '', '', 1, 923, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mailbox
(281505, 5, 45477, 'Rock Cluster', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Rock Cluster
(277285, 3, 44908, 'Sacred Remains', 'questinteract', 'Collecting', '', 0.1, 1690, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 276197, 0, 0, 0, 76404, 0, 0, 0, 0, 27843), -- Sacred Remains
(296575, 3, 51768, 'Julie\'s Cracked Dish', '', 'Collecting', '', 0.75, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90584, 0, 0, 0, 0, 27843), -- Julie's Cracked Dish
(281166, 5, 42959, 'Blood Spatter', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Blood Spatter
(277858, 5, 13840, 'Carcass', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Carcass
(281608, 3, 45539, 'Relic of the Keepers', 'questinteract', 'Collecting', '', 1.2, 1691, 0, 1, 0, 0, 0, 0, 0, 48871, 0, 0, 1, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 76131, 0, 0, 0, 0, 27843), -- Relic of the Keepers
(296584, 3, 33132, 'Zach\'s Canteen', '', 'Collecting', '', 1, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90590, 0, 0, 0, 0, 27843), -- Zach's Canteen
(291001, 5, 49944, 'Fountain', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fountain
(282203, 5, 48340, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282219, 5, 48343, 'Vol\'dun Reservoir Regrowth', '', '', '', 1.21, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282210, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.47, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282209, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.7000002, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282220, 5, 48343, 'Vol\'dun Reservoir Regrowth', '', '', '', 1.49, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282211, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.56, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282237, 5, 48346, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282204, 5, 48341, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282198, 5, 48338, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.79, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282233, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282232, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 1.53, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282224, 5, 48344, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.78, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282228, 5, 48344, 'Vol\'dun Reservoir Regrowth', '', '', '', 1.48, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282196, 5, 48337, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.6600001, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282225, 5, 48344, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282223, 5, 48344, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282236, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.88, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282202, 5, 47424, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282214, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.44, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282222, 5, 48344, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.9400001, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282227, 5, 48344, 'Vol\'dun Reservoir Regrowth', '', '', '', 1.28, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282226, 5, 48344, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282249, 5, 48361, 'Vol\'dun Reservoir Regrowth', '', '', '', 1.43, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282248, 5, 48360, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282235, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282234, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282231, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282230, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 1.17, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282229, 5, 48345, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282221, 5, 48343, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282218, 5, 48343, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.77, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282217, 5, 48343, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.6900001, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282216, 5, 48343, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.82, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282215, 5, 48343, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282213, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.4000003, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282212, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.6899999, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282208, 5, 48342, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282207, 5, 48342, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282206, 5, 48342, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282205, 5, 48342, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.88, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282201, 5, 47424, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282200, 5, 48339, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282199, 5, 48338, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282197, 5, 48337, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282195, 5, 48336, 'Vol\'dun Reservoir Regrowth', '', '', '', 1, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282194, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.66, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(282193, 5, 48334, 'Vol\'dun Reservoir Regrowth', '', '', '', 0.72, 0, 0, 0, 0, 0, 0, 51897, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Vol'dun Reservoir Regrowth
(273995, 10, 47609, 'Loose Boulder', 'questinteract', '', '', 0.5, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 252478, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Loose Boulder
(291008, 10, 49944, 'Terrace Fountain', 'questinteract', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 272814, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Terrace Fountain
(268635, 8, 33316, 'Campfire', '', '', '', 1, 4, 5, 2061, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(281210, 5, 47596, 'Scattered Tools', '', '', '', 0.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Scattered Tools
(281189, 5, 47595, 'Tool Kit', '', '', '', 0.3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Tool Kit
(291057, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(287256, 5, 43302, 'Skeleton', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skeleton
(287238, 10, 48853, 'Ancient Altar', 'questinteract', 'Communing', '', 1, 43, 0, 0, 1, 0, 0, 0, 0, 0, 0, 268094, 0, 0, 0, 152229, 0, 0, 0, 0, 0, 1, 0, 65393, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Ancient Altar
(291058, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(291113, 5, 9199, 'Collision Wall', '', '', '', 0.3, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Collision Wall
(291143, 2, 9329, 'Ranah\'s Wrench', '', '', '', 1, 0, 22186, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Ranah's Wrench
(276186, 5, 44474, 'Terrace Planter', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Terrace Planter
(291010, 5, 49944, 'Broken Fountain', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Broken Fountain
(273992, 10, 49944, 'Terrace Fountain', 'questinteract', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 272812, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Terrace Fountain
(310175, 5, 48795, 'Magic Barrier', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Magic Barrier
(281867, 50, 48202, 'Star Moss', '', '', '', 1, 2862, 76067, 0, 0, 100, 150, 30, 0, 0, 0, 0, 0, 292, 1, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Star Moss
(296573, 3, 51767, 'Jason\'s Rusty Blade', '', 'Collecting', '', 1, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90582, 0, 0, 0, 0, 27843), -- Jason's Rusty Blade
(281656, 10, 45230, 'Faithless War Banner', 'questinteract', 'Burning', '', 1.6, 2742, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 30602, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless War Banner
(281643, 10, 45882, 'Faithless Cannon', 'questinteract', 'Sabotaging', '', 1, 43, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 77147, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Faithless Cannon
(271839, 10, 49138, 'Sethrak Cage', 'questinteract', 'Opening', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 246349, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Cage
(294138, 8, 48976, 'Fire Pit', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(271014, 10, 25615, 'Tarkaj\'s Warblade', 'inspect', '', '', 1.2, 0, 0, 0, 3000, 0, 0, 0, 7193, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Tarkaj's Warblade
(271840, 10, 49138, 'Sethrak Cage', 'questinteract', 'Opening', '', 1, 43, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 246358, 0, 0, 0, 21400, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Cage
(292543, 7, 44320, 'Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Chair
(292542, 8, 39107, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(296587, 3, 45031, 'Josh\'s Fang Necklace', '', 'Collecting', '', 0.5, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90593, 0, 0, 0, 0, 27843), -- Josh's Fang Necklace
(271844, 3, 15781, 'Rakera\'s Journal Page', 'questinteract', 'Collecting', '', 1, 43, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 74374, 0, 0, 0, 0, 27843), -- Rakera's Journal Page
(276621, 50, 50266, 'Rich Monelite Deposit', '', '', '', 1, 2870, 76261, 0, 0, 150, 200, 30, 0, 0, 0, 0, 0, 292, 1, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Rich Monelite Deposit
(298918, 10, 47594, 'Loose Rock', 'questinteract', '', '', 0.1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 280556, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Loose Rock
(288391, 10, 17804, 'Bonepicker Nest', 'questinteract', '', '', 1, 0, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 269109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 57056, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bonepicker Nest
(292601, 8, 23400, 'Anvil', '', '', '', 0.5700002, 1, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Anvil
(292600, 8, 50269, 'Forge', '', '', '', 1, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(290480, 7, 44320, 'Bench', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bench
(290479, 7, 44319, 'Bench', '', '', '', 1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bench
(289694, 8, 49329, 'Fire Pit', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(292599, 19, 50268, 'Mailbox', '', '', '', 1, 923, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mailbox
(278579, 5, 13575, 'Saurolisk Egg (Large + Shaking)', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Saurolisk Egg (Large + Shaking)
(278578, 5, 13575, 'Broken Saurolisk Eggs', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Broken Saurolisk Eggs
(284410, 50, 48632, 'Treasure Chest', '', '', '', 0.5, 1690, 87476, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2814, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 27843), -- Treasure Chest
(288579, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(294142, 8, 16954, 'Bonfire', '', '', '', 0.3800002, 4, 10, 243896, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bonfire
(296387, 8, 49329, 'Fire Pit', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(289311, 10, 32276, 'Explosives', 'questinteract', 'Collecting', '', 1, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27843), -- Explosives
(296388, 8, 49329, 'Fire Pit', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(296270, 7, 44319, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(296269, 7, 44319, 'Stool', '', '', '', 1.06, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(296268, 7, 44318, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(296267, 8, 33316, 'Campfire', '', '', '', 0.17, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(296386, 8, 49329, 'Fire Pit', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(288581, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Campfire
(278685, 10, 46361, 'Sethrak Skull', 'questinteract', 'Collecting', '', 1.5, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 270072, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27843), -- Sethrak Skull
(296389, 8, 49329, 'Fire Pit', '', '', '', 1, 4, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Fire Pit
(296266, 8, 50269, 'Forge', '', '', '', 0.9999998, 3, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Forge
(296264, 7, 44320, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(278686, 10, 46386, 'Stolen Vulpera Banner', 'questinteract', 'Collecting', '', 0.5, 1690, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 270074, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27843), -- Stolen Vulpera Banner
(294143, 8, 16954, 'Bonfire', '', '', '', 0.38, 4, 10, 243896, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bonfire
(296265, 7, 44319, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(296263, 7, 44320, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(296262, 7, 44318, 'Stool', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stool
(296586, 3, 51868, 'Rachel\'s Flute', '', 'Collecting', '', 1, 57, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 19676, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 90592, 0, 0, 0, 0, 27843), -- Rachel's Flute
(296991, 8, 16954, 'Bonfire', '', '', '', 0.1, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bonfire
(296990, 8, 16954, 'Bonfire', '', '', '', 0.1, 4, 10, 2066, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Bonfire
(294144, 8, 16954, 'Bonfire', '', '', '', 0.38, 4, 10, 243896, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 27843); -- Bonfire


DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=277285 AND `Idx`=0) OR (`GameObjectEntry`=281608 AND `Idx`=0) OR (`GameObjectEntry`=271844 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(277285, 0, 153028, 27843), -- Sacred Remains
(281608, 0, 152787, 27843), -- Relic of the Keepers
(271844, 0, 151346, 27843); -- Rakera's Journal Page


DELETE FROM `page_text` WHERE `ID`=7193;
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(7193, 'Covered with fresh blood, this blade has seen recent battle.\n\nWith no corpse nearby, it appears whomever wielded it managed to escape.', 0, 0, 0, 27843); -- 7193


DELETE FROM `npc_text` WHERE `ID` IN (32959 /*32959*/, 32960 /*32960*/, 35200 /*35200*/, 32937 /*32937*/, 32975 /*32975*/, 34392 /*34392*/, 32858 /*32858*/, 32008 /*32008*/, 35426 /*35426*/, 35659 /*35659*/, 32245 /*32245*/, 33437 /*33437*/, 33434 /*33434*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(32959, 1, 0, 0, 0, 0, 0, 0, 0, 137500, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32959
(32960, 1, 0, 0, 0, 0, 0, 0, 0, 137498, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32960
(35200, 1, 1, 1, 1, 0, 0, 0, 0, 137498, 137499, 137497, 137500, 0, 0, 0, 0, 27843), -- 35200
(32937, 1, 0, 0, 0, 0, 0, 0, 0, 137444, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32937
(32975, 1, 0, 0, 0, 0, 0, 0, 0, 137543, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32975
(34392, 1, 0, 0, 0, 0, 0, 0, 0, 150109, 0, 0, 0, 0, 0, 0, 0, 27843), -- 34392
(32858, 1, 0, 0, 0, 0, 0, 0, 0, 137239, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32858
(32008, 1, 0, 0, 0, 0, 0, 0, 0, 131418, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32008
(35426, 1, 0, 0, 0, 0, 0, 0, 0, 158896, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35426
(35659, 1, 0, 0, 0, 0, 0, 0, 0, 160058, 0, 0, 0, 0, 0, 0, 0, 27843), -- 35659
(32245, 1, 0, 0, 0, 0, 0, 0, 0, 132928, 0, 0, 0, 0, 0, 0, 0, 27843), -- 32245
(33437, 1, 0, 0, 0, 0, 0, 0, 0, 156346, 0, 0, 0, 0, 0, 0, 0, 27843), -- 33437
(33434, 1, 0, 0, 0, 0, 0, 0, 0, 141610, 0, 0, 0, 0, 0, 0, 0, 27843); -- 33434