DELETE FROM `quest_offer_reward` WHERE `ID` IN (14274 /*Immolate*/, 14273 /*Shady Associates*/, 14279 /*Flash Heal*/, 14278 /*Seek the Sister*/, 14272 /*Eviscerate*/, 14269 /*Someone's Looking for You*/, 14276 /*Steady Shot*/, 14275 /*Someone's Keeping Track of You*/);
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(14274, 0, 0, 0, 0, 0, 0, 0, 0, 'Yes!  You can feel the power, can\'t you?', 60192), -- Immolate
(14273, 0, 0, 0, 0, 0, 0, 0, 0, 'A darkness has descended over our lands.  And not our kind of darkness, if you know what I mean.', 60192), -- Shady Associates
(14279, 0, 0, 0, 0, 0, 0, 0, 0, 'You are blessed, $N.  The Light shines upon you, even in these dark times.', 60192), -- Flash Heal
(14278, 0, 0, 0, 0, 0, 0, 0, 0, 'The Light is with you, $N.  It\'s still quite a relief to see you.', 60192), -- Seek the Sister
(14272, 0, 0, 0, 0, 0, 0, 0, 0, 'Don\'t get ahead of yourself now.  Just remember who taught you everything you know.$B$BAnd now let\'s see if we can get out of this city with our skins attached.', 60192), -- Eviscerate
(14269, 0, 0, 0, 0, 0, 0, 0, 0, 'Oh, hey!  There you are!', 60192), -- Someone's Looking for You
(14276, 0, 0, 0, 0, 0, 0, 0, 0, 'Excellent work, $N.  These worgen will regret ever setting foot in our lands.', 60192), -- Steady Shot
(14275, 0, 0, 0, 0, 0, 0, 0, 0, '$N!  I knew you had to be around here.', 60192); -- Someone's Keeping Track of You

UPDATE `quest_offer_reward` SET `VerifiedBuild`=60192 WHERE `ID` IN (14283, 14280, 14099, 14098, 14093, 14094, 14091, 14078, 14281, 14277, 14266, 14265);

DELETE FROM `quest_details` WHERE `ID` IN (14287 /*Safety in Numbers*/, 14274 /*Immolate*/, 14273 /*Shady Associates*/, 14288 /*Safety in Numbers*/, 14281 /*Arcane Missiles*/, 14277 /*Arcane Inquiries*/, 14289 /*Safety in Numbers*/, 14279 /*Flash Heal*/, 14278 /*Seek the Sister*/, 14290 /*Safety in Numbers*/, 14276 /*Steady Shot*/, 14275 /*Someone's Keeping Track of You*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(14287, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Safety in Numbers
(14274, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Immolate
(14273, 1, 0, 0, 0, 0, 0, 0, 0, 60192), -- Shady Associates
(14288, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Safety in Numbers
(14281, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Arcane Missiles
(14277, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Arcane Inquiries
(14289, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Safety in Numbers
(14279, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Flash Heal
(14278, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Seek the Sister
(14290, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Safety in Numbers
(14276, 0, 0, 0, 0, 0, 0, 0, 0, 60192), -- Steady Shot
(14275, 0, 0, 0, 0, 0, 0, 0, 0, 60192); -- Someone's Keeping Track of You

UPDATE `quest_details` SET `VerifiedBuild`=60192 WHERE `ID` IN (14291, 14283, 14280, 14099, 14094, 14093, 14098, 14091, 14078, 14285, 14272, 14269, 14286, 14266, 14265);

DELETE FROM `quest_request_items` WHERE `ID` IN (14281 /*Arcane Missiles*/, 14279 /*Flash Heal*/, 14276 /*Steady Shot*/, 14274 /*Immolate*/, 14266 /*Charge*/);
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(14281, 0, 0, 0, 0, 'I always knew you were a quick study!', 60192), -- Arcane Missiles
(14279, 0, 0, 0, 0, 'You are learning swiftly, my dear.', 60192), -- Flash Heal
(14276, 0, 0, 0, 0, 'You\'re a fast learner.  We\'ll show these worgen who the real hunters are.', 60192), -- Steady Shot
(14274, 0, 0, 0, 0, 'You\'re doing well, $N.', 60192), -- Immolate
(14266, 0, 0, 0, 0, 'You\'re a quick study, $N.  Don\'t get overconfident, though.', 60192); -- Charge

UPDATE `quest_request_items` SET `VerifiedBuild`=60192 WHERE `ID` IN (14094, 14093, 14098, 14283);
UPDATE `creature_queststarter` SET `VerifiedBuild`=60192 WHERE (`id`=35873 AND `quest` IN (14291,14283)) OR (`id`=35840 AND `quest` IN (14280,14273,14277,14278,14269,14275,14265)) OR (`id`=34913 AND `quest` IN (14099,14093,14098)) OR (`id`=34936 AND `quest`=14094) OR (`id`=34863 AND `quest`=14091) OR (`id`=34850 AND `quest`=14078) OR (`id`=35869 AND `quest` IN (14287,14274)) OR (`id`=35872 AND `quest` IN (14288,14281)) OR (`id`=35870 AND `quest` IN (14289,14279)) OR (`id`=35871 AND `quest` IN (14285,14272)) OR (`id`=35874 AND `quest` IN (14290,14276)) OR (`id`=35839 AND `quest` IN (14286,14266));
UPDATE `creature_questender` SET `VerifiedBuild`=60192 WHERE (`id`=35873 AND `quest` IN (14283,14280)) OR (`id`=35840 AND `quest`=14099) OR (`id`=34913 AND `quest` IN (14098,14093,14091)) OR (`id`=34936 AND `quest`=14094) OR (`id`=34863 AND `quest`=14078) OR (`id`=35869 AND `quest` IN (14274,14273)) OR (`id`=35872 AND `quest` IN (14281,14277)) OR (`id`=35870 AND `quest` IN (14279,14278)) OR (`id`=35871 AND `quest` IN (14272,14269)) OR (`id`=35874 AND `quest` IN (14276,14275)) OR (`id`=35839 AND `quest` IN (14266,14265));
