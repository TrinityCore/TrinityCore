-- Zones spawned:
-- Bastion,Maldraxxus
-- Dungeons spawned:
-- Darkmaul Citadel,The Necrotic Wake,Plaguefall

DELETE FROM `areatrigger_template` WHERE `Id` IN (23463, 3319, 7020, 11420, 10665, 11266, 8352, 23286, 10727, 22375, 23388, 26126, 24257, 10714, 23826, 23823, 24072, 24417, 26240, 23737, 24351, 22123, 23736, 10801, 2947, 9228, 11393, 9482);
REPLACE INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(23463, 0, 4, 5, 5, 0, 0, 0, 0, 36839),
(3319, 0, 0, 3, 3, 0, 0, 0, 0, 36839),
(7020, 0, 0, 3, 3, 0, 0, 0, 0, 36839),
(11420, 0, 4, 8, 8, 0, 0, 0, 0, 36839),
(10665, 0, 0, 6, 6, 0, 0, 0, 0, 36839),
(11266, 0, 0, 6, 6, 0, 0, 0, 0, 36839),
(8352, 0, 0, 8, 8, 0, 0, 0, 0, 36839),
(23286, 0, 2, 10, 10, 0, 0, 0, 0, 36839),
(10727, 0, 0, 8, 8, 0, 0, 0, 0, 36839),
(22375, 0, 0, 8, 8, 0, 0, 0, 0, 36839),
(23388, 0, 0, 4, 4, 0, 0, 0, 0, 36839),
(26126, 0, 0, 2, 2, 0, 0, 0, 0, 36839),
(24257, 0, 0, 3, 3, 0, 0, 0, 0, 36839),
(10714, 0, 0, 8, 8, 0, 0, 0, 0, 36839),
(23826, 0, 0, 3, 3, 0, 0, 0, 0, 36839),
(23823, 0, 0, 3, 3, 0, 0, 0, 0, 36839),
(24072, 0, 66, 3, 20, 0, 0, 0, 0, 36839),
(24417, 4, 4, 3, 3, 10, 10, 0, 0, 36839),
(26240, 0, 16, 2, 2, 0, 0, 0, 0, 36839),
(23737, 0, 0, 6, 6, 0, 0, 0, 0, 36839),
(24351, 0, 0, 2, 2, 0, 0, 0, 0, 36839),
(22123, 0, 0, 5, 5, 0, 0, 0, 0, 36839),
(23736, 0, 0, 8, 8, 0, 0, 0, 0, 36839),
(10801, 4, 0, 8, 8, 4, 4, 0.300000011920928955, 0.300000011920928955, 36839),
(2947, 0, 0, 8, 8, 0, 0, 0, 0, 36839),
(9228, 0, 0, 8, 8, 0, 0, 0, 0, 36839),
(11393, 4, 16, 8, 8, 15, 15, -3, -3, 36839),
(9482, 0, 5, 45, 45, 0, 0, 0, 0, 36839);

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=19481 AND `AreaTriggerId`=23463) OR (`SpellMiscId`=383 AND `AreaTriggerId`=3319) OR (`SpellMiscId`=2442 AND `AreaTriggerId`=7020) OR (`SpellMiscId`=6917 AND `AreaTriggerId`=11420) OR (`SpellMiscId`=5977 AND `AreaTriggerId`=10665) OR (`SpellMiscId`=6710 AND `AreaTriggerId`=11266) OR (`SpellMiscId`=3680 AND `AreaTriggerId`=8352) OR (`SpellMiscId`=19274 AND `AreaTriggerId`=23286) OR (`SpellMiscId`=6039 AND `AreaTriggerId`=10727) OR (`SpellMiscId`=18264 AND `AreaTriggerId`=22375) OR (`SpellMiscId`=19400 AND `AreaTriggerId`=23388) OR (`SpellMiscId`=21944 AND `AreaTriggerId`=26126) OR (`SpellMiscId`=20351 AND `AreaTriggerId`=24257) OR (`SpellMiscId`=6027 AND `AreaTriggerId`=10714) OR (`SpellMiscId`=19869 AND `AreaTriggerId`=23826) OR (`SpellMiscId`=19866 AND `AreaTriggerId`=23823) OR (`SpellMiscId`=20144 AND `AreaTriggerId`=24072) OR (`SpellMiscId`=20531 AND `AreaTriggerId`=24417) OR (`SpellMiscId`=22071 AND `AreaTriggerId`=26240) OR (`SpellMiscId`=19776 AND `AreaTriggerId`=23737) OR (`SpellMiscId`=20456 AND `AreaTriggerId`=24351) OR (`SpellMiscId`=17984 AND `AreaTriggerId`=22123) OR (`SpellMiscId`=19775 AND `AreaTriggerId`=23736) OR (`SpellMiscId`=6122 AND `AreaTriggerId`=10801) OR (`SpellMiscId`=304 AND `AreaTriggerId`=2947) OR (`SpellMiscId`=4488 AND `AreaTriggerId`=9228) OR (`SpellMiscId`=6887 AND `AreaTriggerId`=11393) OR (`SpellMiscId`=4756 AND `AreaTriggerId`=9482);
REPLACE INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(19481, 23463, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36839), -- SpellId : 319935
(383, 3319, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 36839), -- SpellId : 117032
(2442, 7020, 0, 0, 0, 0, 0, 0, 0, 0, 120000, 36839), -- SpellId : 163271
(6917, 11420, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 36839), -- SpellId : 196770
(5977, 10665, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 36839), -- SpellId : 204255
(6710, 11266, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 36839), -- SpellId : 203795
(3680, 8352, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 36839), -- SpellId : 209693
(19274, 23286, 0, 15615, 0, 0, 0, 0, 426, 0, 30000, 36839), -- SpellId : 319076
(6039, 10727, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 36839), -- SpellId : 228973
(18264, 22375, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 36839), -- SpellId : 306830
(19400, 23388, 0, 0, 0, 0, 0, 0, 219, 0, 15000, 36839), -- SpellId : 320068
(21944, 26126, 0, 0, 0, 0, 0, 0, 219, 0, 15000, 36839), -- SpellId : 344002
(20351, 24257, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 36839), -- SpellId : 328013
(6027, 10714, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 36839), -- SpellId : 202137
(19869, 23826, 0, 0, 0, 0, 0, 0, 31, 0, 20000, 36839), -- SpellId : 324218
(19866, 23823, 0, 0, 0, 0, 0, 0, 209, 0, 30000, 36839), -- SpellId : 324209
(20144, 24072, 0, 0, 17394, 0, 0, 0, 351, 19710, 12500, 36839), -- SpellId : 326000
(20531, 24417, 0, 0, 0, 0, 0, 0, 0, 0, 0, 36839), -- SpellId : 325854
(22071, 26240, 0, 0, 0, 0, 0, 0, 0, 959, 20000, 36839), -- SpellId : 345568
(19776, 23737, 0, 0, 0, 0, 0, 0, 232, 0, 30000, 36839), -- SpellId : 323809
(20456, 24351, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 36839), -- SpellId : 328913
(17984, 22123, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 36839), -- SpellId : 307954
(19775, 23736, 0, 0, 0, 0, 0, 0, 219, 0, 30000, 36839), -- SpellId : 323799
(6122, 10801, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 36839), -- SpellId : 205470
(304, 2947, 0, 0, 0, 0, 0, 0, 0, 0, 12000, 36839), -- SpellId : 116011
(4488, 9228, 0, 0, 0, 0, 0, 0, 0, 0, 12000, 36839), -- SpellId : 26573
(6887, 11393, 0, 0, 0, 0, 0, 0, 0, 454, 8000, 36839), -- SpellId : 202770
(4756, 9482, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 36839); -- SpellId : 191034

DELETE FROM `conversation_actors` WHERE (`ConversationId`=15374 AND `Idx`=0) OR (`ConversationId`=13152 AND `Idx`=0) OR (`ConversationId`=14934 AND `Idx`=1) OR (`ConversationId`=14934 AND `Idx`=0) OR (`ConversationId`=13686 AND `Idx`=0) OR (`ConversationId`=12904 AND `Idx`=0) OR (`ConversationId`=13124 AND `Idx`=0) OR (`ConversationId`=13466 AND `Idx`=0) OR (`ConversationId`=13639 AND `Idx`=0) OR (`ConversationId`=13639 AND `Idx`=1) OR (`ConversationId`=15390 AND `Idx`=0) OR (`ConversationId`=15063 AND `ConversationActorId`=0 AND `Idx`=0) OR (`ConversationId`=13575 AND `Idx`=0) OR (`ConversationId`=13575 AND `Idx`=1) OR (`ConversationId`=15155 AND `Idx`=0) OR (`ConversationId`=13111 AND `Idx`=0) OR (`ConversationId`=13102 AND `Idx`=0) OR (`ConversationId`=15277 AND `Idx`=0) OR (`ConversationId`=13157 AND `Idx`=0) OR (`ConversationId`=15065 AND `ConversationActorId`=0 AND `Idx`=0) OR (`ConversationId`=15064 AND `ConversationActorId`=0 AND `Idx`=0) OR (`ConversationId`=14071 AND `Idx`=0) OR (`ConversationId`=15230 AND `ConversationActorId`=0 AND `Idx`=0) OR (`ConversationId`=15066 AND `ConversationActorId`=0 AND `Idx`=0);
REPLACE INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(15374, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C00015D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 22884439
(13152, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C00015D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 22884439
(14934, 0, 1, 36839), -- Full: 0x20420D15C09D2FC000339C00005E70E8 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 160959 Low: 6189288
(14934, 0, 0, 36839), -- Full: 0x0
(13686, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C00005E6AB2 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 6187698
(12904, 0, 0, 36839), -- Full: 0x20420D15C09D9D0000339C00005E5D06 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 161396 Low: 6184198
(13124, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C00005E6E53 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 6188627
(13466, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C00005D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 6107223
(13639, 0, 0, 36839), -- Full: 0x20420D15C09C258000339C00005D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: Baron Vyraz Low: 6107223
(13639, 0, 1, 36839), -- Full: 0x20420D15C0A563C000339C00005D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 169359 Low: 6107223
(15390, 0, 0, 36839), -- Full: 0x0
(15063, 0, 0, 36839),
(13575, 0, 0, 36839), -- Full: 0x0
(13575, 0, 1, 36839), -- Full: 0x20420D15C09C2E8000339C00015D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 22884439
(15155, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C0001DD3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 31273047
(13111, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C00005D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 6107223
(13102, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C00005D3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 6107223
(15277, 0, 0, 36839), -- Full: 0x20420D15C0A46F4000339C00005D3058 Creature/0 R4227/S13212 Map: The Shadowlands Entry: Baroness Draka Low: 6107224
(13157, 0, 0, 36839), -- Full: 0x20420D15C09C2E8000339C0001DD3057 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 159930 Low: 31273047
(15065, 0, 0, 36839),
(15064, 0, 0, 36839),
(14071, 0, 0, 36839), -- Full: 0x20420D15C09A3E4000339C00005D3058 Creature/0 R4227/S13212 Map: The Shadowlands Entry: 157945 Low: 6107224
(15230, 0, 0, 36839),
(15066, 0, 0, 36839);

DELETE FROM `conversation_actor_template` WHERE `Id`=0;
REPLACE INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(0, 159930, 94122, 36839);

DELETE FROM `conversation_line_template` WHERE `Id` IN (38534, 32597, 37513, 37451, 34118, 31781, 32484, 33496, 37445, 37444, 34033, 38567, 37792, 33818, 33817, 33814, 37575, 33813, 38023, 32442, 32415, 38325, 32607, 37794, 37793, 35276, 38179, 38178, 37795);
REPLACE INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(38534, 0, 0, 0, 0, 36839),
(32597, 0, 0, 0, 0, 36839),
(37513, 6239, 0, 1, 0, 36839),
(37451, 0, 0, 0, 0, 36839),
(34118, 0, 0, 0, 0, 36839),
(31781, 0, 0, 0, 0, 36839),
(32484, 0, 0, 0, 0, 36839),
(33496, 0, 0, 0, 0, 36839),
(37445, 16200, 0, 0, 0, 36839),
(37444, 7217, 0, 1, 0, 36839),
(34033, 0, 0, 0, 0, 36839),
(38567, 0, 0, 0, 0, 36839),
(37792, 0, 1541, 0, 0, 36839),
(33818, 38398, 0, 0, 0, 36839),
(33817, 25148, 0, 0, 0, 36839),
(33814, 13618, 0, 1, 0, 36839),
(37575, 7720, 0, 0, 0, 36839),
(33813, 0, 0, 0, 0, 36839),
(38023, 0, 0, 0, 0, 36839),
(32442, 0, 0, 0, 0, 36839),
(32415, 0, 0, 0, 0, 36839),
(38325, 0, 0, 0, 0, 36839),
(32607, 0, 0, 0, 0, 36839),
(37794, 0, 1541, 0, 0, 36839),
(37793, 0, 1541, 0, 0, 36839),
(35276, 0, 0, 0, 0, 36839),
(38179, 8790, 1558, 0, 0, 36839),
(38178, 0, 1558, 0, 0, 36839),
(37795, 0, 1541, 0, 0, 36839);

DELETE FROM `conversation_template` WHERE `Id` IN (14934, 15230, 13640, 13639, 12904, 13124, 15390, 13575, 15374, 13152, 14071, 16561, 13686, 13157, 15155, 15066, 15065, 15064, 15063, 13102, 13466, 13111, 15277);
REPLACE INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `TextureKitId`, `VerifiedBuild`) VALUES
(14934, 37451, 9820, 0, 36839),
(15230, 38178, 16826, 0, 36839),
(13640, 0, 0, 0, 36839),
(13639, 34033, 20495, 0, 36839),
(12904, 31781, 5400, 0, 36839),
(13124, 32484, 10626, 0, 36839),
(15390, 38567, 8020, 0, 36839),
(13575, 33813, 47022, 0, 36839),
(15374, 38534, 5340, 0, 36839),
(13152, 32597, 9160, 0, 36839),
(14071, 35276, 3850, 0, 36839),
(16561, 0, 0, 0, 36839),
(13686, 34118, 13391, 0, 36839),
(13157, 32607, 7554, 0, 36839),
(15155, 38023, 3830, 0, 36839),
(15066, 37795, 16136, 0, 36839),
(15065, 37794, 15930, 0, 36839),
(15064, 37793, 15370, 0, 36839),
(15063, 37792, 16830, 0, 36839),
(13102, 32415, 5217, 0, 36839),
(13466, 33496, 10295, 0, 36839),
(13111, 32442, 7262, 0, 36839),
(15277, 38325, 8802, 0, 36839);

DELETE FROM `scene_template` WHERE (`SceneId`=2602 AND `ScriptPackageID`=2990) OR (`SceneId`=2519 AND `ScriptPackageID`=2923);
REPLACE INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(2602, 16, 2990),
(2519, 17, 2923);

DELETE FROM `quest_offer_reward` WHERE `ID` IN (58268 /*58268*/, 60557 /*60557*/, 57976 /*57976*/, 57912 /*57912*/, 59231 /*59231*/, 60831 /*60831*/, 59223 /*59223*/, 58431 /*58431*/, 59430 /*59430*/, 58031 /*58031*/, 58045 /*58045*/, 58036 /*58036*/, 58027 /*58027*/, 58011 /*58011*/, 58016 /*58016*/, 59130 /*59130*/);
REPLACE INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(58268, 0, 0, 0, 0, 0, 0, 0, 0, 'With that ridge clear, we\'ll be safe to advance.', 36839), -- 58268
(60557, 1, 0, 0, 0, 0, 0, 0, 0, 'Our forces stand ready to fight once more!', 36839), -- 60557
(57976, 1, 0, 0, 0, 0, 0, 0, 0, 'That should strike fear into their stolen hearts.', 36839), -- 57976
(57912, 1, 0, 0, 0, 0, 0, 0, 0, 'I expect much of you, mortal. Help lead our frontal assault on the construct forces!', 36839), -- 57912
(59231, 6, 0, 0, 0, 0, 0, 0, 0, 'I see you\'ve made a new ally... of a sort. And another rune has been empowered.', 36839), -- 59231
(60831, 6, 0, 0, 0, 0, 0, 0, 0, 'Ah... apprentice? Are you there? I feel... strange.', 36839), -- 60831
(59223, 21, 0, 0, 0, 0, 0, 0, 0, 'Come, my apprentice! Our efforts nearly bear fruit!', 36839), -- 59223
(58431, 0, 0, 0, 0, 0, 0, 0, 0, 'We shall all share in this fabulous brew you have created!', 36839), -- 58431
(59430, 1, 0, 0, 0, 0, 0, 0, 0, 'Working together will benefit both of us greatly!', 36839), -- 59430
(58031, 6, 0, 0, 0, 0, 0, 0, 0, 'Oh--and what are these?', 36839), -- 58031
(58045, 21, 0, 0, 0, 0, 0, 0, 0, 'Our slimes will be safe, my dear apprentice!', 36839), -- 58045
(58036, 5, 0, 0, 0, 0, 0, 0, 0, 'You and your slime are bonding!', 36839), -- 58036
(58027, 5, 0, 0, 0, 0, 0, 0, 0, 'What a precious slime!', 36839), -- 58027
(58011, 5, 0, 0, 0, 0, 0, 0, 0, 'You found my venom sacs! What a helpful apprentice you are!', 36839), -- 58011
(58016, 21, 0, 0, 0, 0, 0, 0, 0, 'Such marvelous spores, my apprentice!', 36839), -- 58016
(59130, 1, 0, 0, 0, 0, 0, 0, 0, 'My apprentice! I have been searching everywhere for you!', 36839); -- 59130


DELETE FROM `quest_poi` WHERE (`QuestID`=57979 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=57979 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57979 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=7) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58268 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60557 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=60557 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60557 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60557 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=57976 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=57976 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=57976 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57976 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59231 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59231 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59231 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60831 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=60831 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=60831 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=60831 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=60831 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60831 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58431 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=58431 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58431 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58431 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59430 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=59430 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=59430 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59430 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59430 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59223 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=59223 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59223 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58031 AND `BlobIndex`=0 AND `Idx1`=6) OR (`QuestID`=58031 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=58031 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=58031 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=58031 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58031 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=58031 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58045 AND `BlobIndex`=1 AND `Idx1`=3) OR (`QuestID`=58045 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58045 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58045 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58036 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58036 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58036 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58027 AND `BlobIndex`=0 AND `Idx1`=5) OR (`QuestID`=58027 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=58027 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=58027 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58027 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58027 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58016 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58016 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58016 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58011 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58011 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58011 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=57912 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57912 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=59130 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=59130 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=58751 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=58751 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=58751 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50606 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60466 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=60316 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=60316 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=60316 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=57743 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57743 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=57538 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=57538 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=57538 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50602 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=50598 AND `BlobIndex`=0 AND `Idx1`=0);
REPLACE INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(57979, 0, 2, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 1857293, 0, 36839), -- 57979
(57979, 0, 1, 0, 393514, 160095, 2222, 1536, 0, 0, 0, 0, 1858276, 0, 36839), -- 57979
(57979, 0, 0, -1, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 57979
(58268, 0, 7, 32, 0, 0, 2222, 1536, 0, 2, 0, 80768, 0, 0, 36839), -- 58268
(58268, 0, 6, 5, 394047, 160955, 2222, 1536, 0, 0, 0, 0, 1864666, 0, 36839), -- 58268
(58268, 0, 5, 4, 394036, 160983, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58268
(58268, 0, 4, 3, 394035, 160954, 2222, 1536, 0, 0, 0, 0, 1864665, 0, 36839), -- 58268
(58268, 0, 3, 2, 394046, 160981, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58268
(58268, 0, 2, 1, 394038, 160948, 2222, 1536, 0, 0, 0, 0, 1864664, 0, 36839), -- 58268
(58268, 0, 1, 0, 394034, 160971, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58268
(58268, 0, 0, -1, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58268
(60557, 0, 3, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 1857293, 0, 36839), -- 60557
(60557, 0, 2, 0, 398801, 169065, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 60557
(60557, 0, 1, -1, 0, 0, 2222, 1536, 0, 0, 0, 81922, 1965768, 0, 36839), -- 60557
(60557, 0, 0, -1, 0, 0, 2222, 1536, 0, 2, 0, 81923, 0, 0, 36839), -- 60557
(57976, 0, 3, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 57976
(57976, 0, 2, 0, 393444, 156591, 2222, 1536, 0, 0, 0, 0, 0, 0, 36839), -- 57976
(57976, 0, 1, -1, 0, 0, 2222, 1536, 0, 2, 0, 81922, 1965768, 0, 36839), -- 57976
(57976, 0, 0, -1, 0, 0, 2222, 1536, 0, 2, 0, 81923, 0, 0, 36839), -- 57976
(59231, 0, 2, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1914758, 0, 36839), -- 59231
(59231, 0, 1, 0, 405080, 170900, 2222, 1536, 0, 0, 0, 0, 1987294, 0, 36839), -- 59231
(59231, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1958509, 0, 36839), -- 59231
(60831, 0, 5, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1914758, 0, 36839), -- 60831
(60831, 0, 4, 2, 405021, 170770, 2222, 1536, 0, 0, 0, 0, 1917192, 0, 36839), -- 60831
(60831, 0, 3, 1, 404762, 345431, 2222, 1536, 0, 0, 0, 0, 1914714, 0, 36839), -- 60831
(60831, 1, 2, 0, 404761, 353760, 2222, 1536, 0, 0, 0, 0, 1914788, 0, 36839), -- 60831
(60831, 0, 1, 0, 404761, 353760, 2222, 1536, 0, 0, 0, 0, 1914792, 0, 36839), -- 60831
(60831, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1914758, 0, 36839), -- 60831
(58431, 0, 3, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 1835179, 0, 36839), -- 58431
(58431, 0, 2, 31, 0, 0, 2222, 1536, 0, 0, 0, 0, 1829312, 0, 36839), -- 58431
(58431, 0, 1, 0, 394257, 161250, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58431
(58431, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1835179, 0, 36839), -- 58431
(59430, 0, 4, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1922800, 0, 36839), -- 59430
(59430, 0, 3, 2, 396450, 157945, 2222, 1536, 0, 0, 0, 0, 1835179, 0, 36839), -- 59430
(59430, 0, 2, 1, 396449, 157313, 2222, 1536, 0, 0, 0, 0, 1869656, 0, 36839), -- 59430
(59430, 0, 1, 0, 396444, 165052, 2222, 1536, 0, 0, 0, 0, 1922839, 0, 36839), -- 59430
(59430, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1835179, 0, 36839), -- 59430
(59223, 0, 2, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1914758, 0, 36839), -- 59223
(59223, 0, 1, 0, 396172, 175410, 2222, 1536, 0, 0, 0, 0, 1920857, 0, 36839), -- 59223
(59223, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1914758, 0, 36839), -- 59223
(58031, 0, 6, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1980808, 0, 36839), -- 58031
(58031, 0, 5, 3, 404417, 170054, 2222, 1536, 0, 0, 0, 0, 0, 0, 36839), -- 58031
(58031, 0, 4, 2, 404416, 170053, 2222, 1536, 0, 0, 0, 0, 0, 0, 36839), -- 58031
(58031, 0, 3, 1, 404415, 170052, 2222, 1536, 0, 0, 0, 0, 0, 0, 36839), -- 58031
(58031, 0, 2, 0, 393500, 170050, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58031
(58031, 1, 1, -1, 0, 0, 2222, 1536, 0, 0, 0, 75738, 1882894, 0, 36839), -- 58031
(58031, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 77014, 1982659, 0, 36839), -- 58031
(58045, 1, 3, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1882894, 0, 36839), -- 58045
(58045, 0, 2, 32, 0, 0, 2222, 1536, 0, 2, 0, 0, 1914758, 0, 36839), -- 58045
(58045, 0, 1, 0, 393516, 161613, 2222, 1536, 0, 0, 0, 0, 1858042, 0, 36839), -- 58045
(58045, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1982659, 0, 36839), -- 58045
(58036, 0, 2, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1857581, 0, 36839), -- 58036
(58036, 0, 1, 0, 393510, 173536, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58036
(58036, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1982659, 0, 36839), -- 58036
(58027, 0, 5, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1857581, 0, 36839), -- 58027
(58027, 0, 4, 3, 394715, 159996, 2222, 1536, 0, 0, 0, 0, 1857618, 0, 36839), -- 58027
(58027, 0, 3, 2, 394687, 162131, 2222, 1536, 0, 0, 0, 0, 1857618, 0, 36839), -- 58027
(58027, 0, 2, 1, 394686, 162130, 2222, 1536, 0, 0, 0, 0, 1877179, 0, 36839), -- 58027
(58027, 0, 1, 0, 393480, 162129, 2222, 1536, 0, 0, 0, 0, 1877178, 0, 36839), -- 58027
(58027, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1857581, 0, 36839), -- 58027
(58016, 0, 2, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1857581, 0, 36839), -- 58016
(58016, 0, 1, 0, 393473, 176097, 2222, 1536, 0, 2, 0, 0, 0, 0, 36839), -- 58016
(58016, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1882894, 0, 36839), -- 58016
(58011, 0, 2, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1857581, 0, 36839), -- 58011
(58011, 0, 1, 0, 393467, 173368, 2222, 1536, 0, 0, 0, 0, 0, 0, 36839), -- 58011
(58011, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1857581, 0, 36839), -- 58011
(57912, 0, 1, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1958509, 0, 36839), -- 57912
(57912, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1857293, 0, 36839), -- 57912
(59130, 0, 1, 32, 0, 0, 2222, 1698, 0, 0, 0, 0, 1958509, 0, 36839), -- 59130
(59130, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1882894, 0, 36839), -- 59130
(58751, 0, 2, 32, 0, 0, 2222, 1536, 0, 0, 0, 0, 1958509, 0, 36839), -- 58751
(58751, 0, 1, 0, 395990, 162505, 2222, 1536, 0, 0, 0, 0, 1883201, 0, 36839), -- 58751
(58751, 0, 0, -1, 0, 0, 2222, 1536, 0, 0, 0, 0, 1883201, 0, 36839), -- 58751
(50606, 0, 0, -1, 0, 0, 1642, 862, 0, 0, 0, 0, 1480298, 0, 36839), -- 50606
(60466, 0, 4, 32, 0, 0, 2222, 1533, 0, 0, 0, 0, 1861577, 0, 36839), -- 60466
(60466, 0, 3, 2, 398287, 178890, 2222, 1533, 0, 0, 0, 0, 0, 0, 36839), -- 60466
(60466, 0, 2, 1, 398285, 178885, 2222, 1533, 0, 0, 0, 0, 0, 0, 36839), -- 60466
(60466, 0, 1, 0, 398288, 178891, 2222, 1533, 0, 0, 0, 0, 1861603, 0, 36839), -- 60466
(60466, 0, 0, -1, 0, 0, 2222, 1533, 0, 0, 0, 0, 1861577, 0, 36839), -- 60466
(60316, 0, 2, 32, 0, 0, 2222, 1533, 0, 0, 0, 0, 1956783, 0, 36839), -- 60316
(60316, 0, 1, 0, 398169, 168244, 2222, 1533, 0, 0, 0, 0, 1956781, 0, 36839), -- 60316
(60316, 0, 0, -1, 0, 0, 2222, 1533, 0, 0, 0, 0, 1861557, 0, 36839), -- 60316
(57743, 0, 1, -1, 0, 0, 1642, 862, 0, 0, 0, 923, 1603266, 0, 36839), -- 57743
(57743, 0, 0, -1, 0, 0, 1643, 1161, 0, 0, 0, 924, 1603576, 0, 36839), -- 57743
(57538, 0, 2, 32, 0, 0, 2222, 1533, 0, 0, 0, 0, 1837475, 0, 36839), -- 57538
(57538, 0, 1, 0, 392595, 158130, 2222, 1533, 0, 0, 0, 0, 0, 0, 36839), -- 57538
(57538, 0, 0, -1, 0, 0, 2222, 1533, 0, 0, 0, 0, 1837475, 0, 36839), -- 57538
(50602, 0, 0, -1, 0, 0, 1642, 863, 0, 0, 0, 0, 1480361, 0, 36839), -- 50602
(50598, 0, 0, -1, 0, 0, 1642, 1165, 0, 0, 0, 0, 1429777, 0, 36839); -- 50598

DELETE FROM `quest_poi_points` WHERE (`QuestID`=57979 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=57979 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57979 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58268 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60557 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=11) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=60557 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60557 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60557 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=57976 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=57976 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=57976 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57976 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59231 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59231 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59231 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60831 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=60831 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=60831 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=60831 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60831 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60831 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58431 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=58431 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=58431 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58431 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59430 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=59430 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=59430 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59430 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59430 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59223 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=59223 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59223 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58031 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=9) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=8) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=7) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=6) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=5) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=4) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=3) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=2) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=1) OR (`QuestID`=58031 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=9) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=8) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=7) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=6) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=5) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=4) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=3) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=2) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=1) OR (`QuestID`=58031 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=9) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=8) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=58031 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=58031 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58031 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58031 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58045 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=58045 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58045 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58045 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58036 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=58036 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58036 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58027 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=58027 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=58027 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=58027 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58027 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58027 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58016 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=58016 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58016 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58011 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=58011 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58011 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=57912 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57912 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=59130 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=59130 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=58751 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=58751 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=58751 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50606 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=7) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=6) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=5) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=4) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=3) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=2) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=1) OR (`QuestID`=60466 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=1) OR (`QuestID`=60466 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60466 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=60316 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=60316 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=60316 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=57743 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57743 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=57538 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=57538 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=57538 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50602 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=50598 AND `Idx1`=0 AND `Idx2`=0);
REPLACE INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(57979, 2, 0, 2861, -1867, 36839), -- 57979
(57979, 1, 0, 2994, -1709, 36839), -- 57979
(57979, 0, 0, 2856, -1866, 36839), -- 57979
(58268, 7, 0, 2493, -1859, 36839), -- 58268
(58268, 6, 0, 2867, -1648, 36839), -- 58268
(58268, 5, 0, 2873, -1645, 36839), -- 58268
(58268, 4, 0, 2783, -1645, 36839), -- 58268
(58268, 3, 0, 2777, -1639, 36839), -- 58268
(58268, 2, 0, 2702, -1627, 36839), -- 58268
(58268, 1, 0, 2703, -1619, 36839), -- 58268
(58268, 0, 0, 2856, -1849, 36839), -- 58268
(60557, 3, 0, 2469, -1847, 36839), -- 60557
(60557, 2, 11, 2550, -1838, 36839), -- 60557
(60557, 2, 10, 2555, -1718, 36839), -- 60557
(60557, 2, 9, 2600, -1570, 36839), -- 60557
(60557, 2, 8, 2680, -1565, 36839), -- 60557
(60557, 2, 7, 2777, -1588, 36839), -- 60557
(60557, 2, 6, 2907, -1639, 36839), -- 60557
(60557, 2, 5, 2981, -1679, 36839), -- 60557
(60557, 2, 4, 2998, -1738, 36839), -- 60557
(60557, 2, 3, 2986, -1798, 36839), -- 60557
(60557, 2, 2, 2913, -1854, 36839), -- 60557
(60557, 2, 1, 2662, -1928, 36839), -- 60557
(60557, 2, 0, 2578, -1889, 36839), -- 60557
(60557, 1, 0, 2855, -1858, 36839), -- 60557
(60557, 0, 0, 2487, -1855, 36839), -- 60557
(57976, 3, 0, 2510, -1827, 36839), -- 57976
(57976, 2, 9, 2442, -1745, 36839), -- 57976
(57976, 2, 8, 2630, -1574, 36839), -- 57976
(57976, 2, 7, 2637, -1569, 36839), -- 57976
(57976, 2, 6, 2842, -1596, 36839), -- 57976
(57976, 2, 5, 2880, -1607, 36839), -- 57976
(57976, 2, 4, 2978, -1699, 36839), -- 57976
(57976, 2, 3, 3008, -1731, 36839), -- 57976
(57976, 2, 2, 3027, -1866, 36839), -- 57976
(57976, 2, 1, 2862, -1916, 36839), -- 57976
(57976, 2, 0, 2649, -1965, 36839), -- 57976
(57976, 1, 0, 2860, -1858, 36839), -- 57976
(57976, 0, 0, 2504, -1826, 36839), -- 57976
(59231, 2, 0, 1806, -3184, 36839), -- 59231
(59231, 1, 0, 1971, -2548, 36839), -- 59231
(59231, 0, 0, 1973, -2542, 36839), -- 59231
(60831, 5, 0, 1806, -3183, 36839), -- 60831
(60831, 4, 0, 1819, -3195, 36839), -- 60831
(60831, 3, 0, 1819, -3195, 36839), -- 60831
(60831, 2, 0, 1827, -3178, 36839), -- 60831
(60831, 1, 0, 1801, -3188, 36839), -- 60831
(60831, 0, 0, 1806, -3183, 36839), -- 60831
(58431, 3, 0, 1719, -3094, 36839), -- 58431
(58431, 2, 0, 1701, -3093, 36839), -- 58431
(58431, 1, 11, 1528, -3285, 36839), -- 58431
(58431, 1, 10, 1464, -3251, 36839), -- 58431
(58431, 1, 9, 1438, -3148, 36839), -- 58431
(58431, 1, 8, 1446, -3014, 36839), -- 58431
(58431, 1, 7, 1601, -2955, 36839), -- 58431
(58431, 1, 6, 1747, -3007, 36839), -- 58431
(58431, 1, 5, 1798, -3029, 36839), -- 58431
(58431, 1, 4, 1837, -3079, 36839), -- 58431
(58431, 1, 3, 1841, -3132, 36839), -- 58431
(58431, 1, 2, 1820, -3157, 36839), -- 58431
(58431, 1, 1, 1636, -3294, 36839), -- 58431
(58431, 1, 0, 1566, -3315, 36839), -- 58431
(58431, 0, 0, 1719, -3094, 36839), -- 58431
(59430, 4, 0, 1788, -3031, 36839), -- 59430
(59430, 3, 0, 1714, -3096, 36839), -- 59430
(59430, 2, 0, 1732, -3060, 36839), -- 59430
(59430, 1, 0, 1752, -3117, 36839), -- 59430
(59430, 0, 0, 1714, -3096, 36839), -- 59430
(59223, 2, 0, 1806, -3183, 36839), -- 59223
(59223, 1, 0, 1437, -3018, 36839), -- 59223
(59223, 0, 0, 1806, -3183, 36839), -- 59223
(58031, 6, 0, 2414, -2935, 36839), -- 58031
(58031, 5, 9, 2055, -3043, 36839), -- 58031
(58031, 5, 8, 2037, -3001, 36839), -- 58031
(58031, 5, 7, 2059, -2985, 36839), -- 58031
(58031, 5, 6, 2091, -2969, 36839), -- 58031
(58031, 5, 5, 2197, -2926, 36839), -- 58031
(58031, 5, 4, 2265, -2911, 36839), -- 58031
(58031, 5, 3, 2301, -2947, 36839), -- 58031
(58031, 5, 2, 2315, -3020, 36839), -- 58031
(58031, 5, 1, 2291, -3251, 36839), -- 58031
(58031, 5, 0, 2202, -3305, 36839), -- 58031
(58031, 4, 9, 2055, -3043, 36839), -- 58031
(58031, 4, 8, 2037, -3001, 36839), -- 58031
(58031, 4, 7, 2059, -2985, 36839), -- 58031
(58031, 4, 6, 2091, -2969, 36839), -- 58031
(58031, 4, 5, 2197, -2926, 36839), -- 58031
(58031, 4, 4, 2265, -2911, 36839), -- 58031
(58031, 4, 3, 2301, -2947, 36839), -- 58031
(58031, 4, 2, 2315, -3020, 36839), -- 58031
(58031, 4, 1, 2291, -3251, 36839), -- 58031
(58031, 4, 0, 2202, -3305, 36839), -- 58031
(58031, 3, 9, 2055, -3043, 36839), -- 58031
(58031, 3, 8, 2037, -3001, 36839), -- 58031
(58031, 3, 7, 2059, -2985, 36839), -- 58031
(58031, 3, 6, 2091, -2969, 36839), -- 58031
(58031, 3, 5, 2197, -2926, 36839), -- 58031
(58031, 3, 4, 2265, -2911, 36839), -- 58031
(58031, 3, 3, 2301, -2947, 36839), -- 58031
(58031, 3, 2, 2315, -3020, 36839), -- 58031
(58031, 3, 1, 2291, -3251, 36839), -- 58031
(58031, 3, 0, 2202, -3305, 36839), -- 58031
(58031, 2, 9, 2138, -3209, 36839), -- 58031
(58031, 2, 8, 2037, -3043, 36839), -- 58031
(58031, 2, 7, 2059, -2985, 36839), -- 58031
(58031, 2, 6, 2091, -2969, 36839), -- 58031
(58031, 2, 5, 2164, -2902, 36839), -- 58031
(58031, 2, 4, 2265, -2911, 36839), -- 58031
(58031, 2, 3, 2301, -2947, 36839), -- 58031
(58031, 2, 2, 2315, -3020, 36839), -- 58031
(58031, 2, 1, 2317, -3283, 36839), -- 58031
(58031, 2, 0, 2192, -3336, 36839), -- 58031
(58031, 1, 0, 2410, -2930, 36839), -- 58031
(58031, 0, 0, 1806, -3046, 36839), -- 58031
(58045, 3, 0, 2410, -2936, 36839), -- 58045
(58045, 2, 0, 1806, -3184, 36839), -- 58045
(58045, 1, 0, 2167, -3284, 36839), -- 58045
(58045, 0, 0, 1806, -3046, 36839), -- 58045
(58036, 2, 0, 2410, -2931, 36839), -- 58036
(58036, 1, 11, 2198, -3313, 36839), -- 58036
(58036, 1, 10, 2008, -3050, 36839), -- 58036
(58036, 1, 9, 2031, -2985, 36839), -- 58036
(58036, 1, 8, 2180, -2892, 36839), -- 58036
(58036, 1, 7, 2212, -2892, 36839), -- 58036
(58036, 1, 6, 2267, -2902, 36839), -- 58036
(58036, 1, 5, 2323, -2938, 36839), -- 58036
(58036, 1, 4, 2323, -2957, 36839), -- 58036
(58036, 1, 3, 2323, -3193, 36839), -- 58036
(58036, 1, 2, 2323, -3244, 36839), -- 58036
(58036, 1, 1, 2295, -3286, 36839), -- 58036
(58036, 1, 0, 2249, -3323, 36839), -- 58036
(58036, 0, 0, 1806, -3046, 36839), -- 58036
(58027, 5, 0, 2416, -2934, 36839), -- 58027
(58027, 4, 0, 2420, -2932, 36839), -- 58027
(58027, 3, 0, 2420, -2932, 36839), -- 58027
(58027, 2, 0, 2422, -2928, 36839), -- 58027
(58027, 1, 0, 2417, -2930, 36839), -- 58027
(58027, 0, 0, 2416, -2934, 36839), -- 58027
(58016, 2, 0, 2410, -2931, 36839), -- 58016
(58016, 1, 11, 2180, -2849, 36839), -- 58016
(58016, 1, 10, 2185, -2763, 36839), -- 58016
(58016, 1, 9, 2192, -2740, 36839), -- 58016
(58016, 1, 8, 2237, -2610, 36839), -- 58016
(58016, 1, 7, 2283, -2576, 36839), -- 58016
(58016, 1, 6, 2356, -2576, 36839), -- 58016
(58016, 1, 5, 2425, -2582, 36839), -- 58016
(58016, 1, 4, 2446, -2666, 36839), -- 58016
(58016, 1, 3, 2498, -2770, 36839), -- 58016
(58016, 1, 2, 2463, -2837, 36839), -- 58016
(58016, 1, 1, 2356, -2923, 36839), -- 58016
(58016, 1, 0, 2345, -2923, 36839), -- 58016
(58016, 0, 0, 2410, -2930, 36839), -- 58016
(58011, 2, 0, 2416, -2934, 36839), -- 58011
(58011, 1, 10, 2220, -2837, 36839), -- 58011
(58011, 1, 9, 2210, -2805, 36839), -- 58011
(58011, 1, 8, 2227, -2677, 36839), -- 58011
(58011, 1, 7, 2284, -2616, 36839), -- 58011
(58011, 1, 6, 2289, -2611, 36839), -- 58011
(58011, 1, 5, 2380, -2625, 36839), -- 58011
(58011, 1, 4, 2390, -2631, 36839), -- 58011
(58011, 1, 3, 2476, -2795, 36839), -- 58011
(58011, 1, 2, 2432, -2841, 36839), -- 58011
(58011, 1, 1, 2373, -2860, 36839), -- 58011
(58011, 1, 0, 2337, -2872, 36839), -- 58011
(58011, 0, 0, 2416, -2934, 36839), -- 58011
(57912, 1, 0, 1972, -2542, 36839), -- 57912
(57912, 0, 0, 2487, -1850, 36839), -- 57912
(59130, 1, 0, 1972, -2542, 36839), -- 59130
(59130, 0, 0, 2409, -2936, 36839), -- 59130
(58751, 2, 0, 1972, -2542, 36839), -- 58751
(58751, 1, 0, 2888, -3636, 36839), -- 58751
(58751, 0, 0, 2886, -3636, 36839), -- 58751
(50606, 0, 0, -2154, 795, 36839), -- 50606
(60466, 4, 0, -4130, -4614, 36839), -- 60466
(60466, 3, 7, -3996, -4917, 36839), -- 60466
(60466, 3, 6, -4191, -4778, 36839), -- 60466
(60466, 3, 5, -4245, -4585, 36839), -- 60466
(60466, 3, 4, -4237, -4579, 36839), -- 60466
(60466, 3, 3, -4194, -4606, 36839), -- 60466
(60466, 3, 2, -3814, -4888, 36839), -- 60466
(60466, 3, 1, -3867, -4922, 36839), -- 60466
(60466, 3, 0, -3950, -4931, 36839), -- 60466
(60466, 2, 6, -4024, -4925, 36839), -- 60466
(60466, 2, 5, -4143, -4795, 36839), -- 60466
(60466, 2, 4, -4196, -4646, 36839), -- 60466
(60466, 2, 3, -4011, -4672, 36839), -- 60466
(60466, 2, 2, -3936, -4771, 36839), -- 60466
(60466, 2, 1, -3969, -4908, 36839), -- 60466
(60466, 2, 0, -3985, -4958, 36839), -- 60466
(60466, 1, 0, -4106, -4628, 36839), -- 60466
(60466, 0, 0, -4130, -4614, 36839), -- 60466
(60316, 2, 0, -4100, -4698, 36839), -- 60316
(60316, 1, 0, -4207, -4832, 36839), -- 60316
(60316, 0, 0, -4078, -4686, 36839), -- 60316
(57743, 1, 0, -1906, 1340, 36839), -- 57743
(57743, 0, 0, 1049, -280, 36839), -- 57743
(57538, 2, 0, -3508, -4844, 36839), -- 57538
(57538, 1, 9, -3453, -4980, 36839), -- 57538
(57538, 1, 8, -3533, -4730, 36839), -- 57538
(57538, 1, 7, -3533, -4695, 36839), -- 57538
(57538, 1, 6, -3495, -4565, 36839), -- 57538
(57538, 1, 5, -3488, -4542, 36839), -- 57538
(57538, 1, 4, -3479, -4542, 36839), -- 57538
(57538, 1, 3, -3379, -4545, 36839), -- 57538
(57538, 1, 2, -3312, -4740, 36839), -- 57538
(57538, 1, 1, -3333, -4860, 36839), -- 57538
(57538, 1, 0, -3433, -5000, 36839), -- 57538
(57538, 0, 0, -3508, -4844, 36839), -- 57538
(50602, 0, 0, 742, 1393, 36839), -- 50602
(50598, 0, 0, -1126, 771, 36839); -- 50598

DELETE FROM `quest_greeting` WHERE (`Type`=0 AND `ID` IN (160959,169359,159894,168381));
REPLACE INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(160959, 0, 0, 0, 'Let\'s keep moving.', 36839), -- 160959
(169359, 0, 1, 0, 'Many will fall before the day is done.', 36839), -- 169359
(159894, 0, 0, 0, 'We will crush their lines through sheer force!', 36839), -- 159894
(168381, 0, 0, 0, 'Victory will be ours.', 36839); -- 168381

DELETE FROM `quest_details` WHERE `ID` IN (57979 /*57979*/, 58268 /*58268*/, 60557 /*60557*/, 57976 /*57976*/, 59520 /*59520*/, 59231 /*59231*/, 60831 /*60831*/, 57301 /*57301*/, 58431 /*58431*/, 59430 /*59430*/, 59223 /*59223*/, 58031 /*58031*/, 58045 /*58045*/, 58036 /*58036*/, 58027 /*58027*/, 58016 /*58016*/, 58011 /*58011*/, 57912 /*57912*/, 59130 /*59130*/, 58751 /*58751*/);
REPLACE INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(57979, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 57979
(58268, 0, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58268
(60557, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 60557
(57976, 5, 0, 0, 0, 0, 0, 0, 0, 36839), -- 57976
(59520, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 59520
(59231, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 59231
(60831, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 60831
(57301, 0, 0, 0, 0, 0, 0, 0, 0, 36839), -- 57301
(58431, 0, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58431
(59430, 1, 25, 0, 0, 0, 0, 0, 0, 36839), -- 59430
(59223, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 59223
(58031, 0, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58031
(58045, 6, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58045
(58036, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58036
(58027, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58027
(58016, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58016
(58011, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 58011
(57912, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 57912
(59130, 1, 0, 0, 0, 0, 0, 0, 0, 36839), -- 59130
(58751, 1, 1, 0, 0, 0, 0, 0, 0, 36839); -- 58751

DELETE FROM `quest_request_items` WHERE `ID` IN (57976 /*57976*/, 59231 /*59231*/, 59223 /*59223*/, 58431 /*58431*/, 58036 /*58036*/, 58011 /*58011*/);
REPLACE INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`) VALUES
(57976, 0, 0, 0, 0, 'What?'), -- 57976
(59231, 0, 0, 0, 0, ''), -- 59231
(59223, 0, 0, 0, 0, 'Have you found it?'), -- 59223
(58431, 0, 0, 0, 0, 'Have you brought enough oil?'), -- 58431
(58036, 0, 0, 0, 0, 'Has your slime been useful? I\'m sure it has!'), -- 58036
(58011, 0, 0, 0, 0, 'Now where did I put my venom sacs...'); -- 58011

SET @CGUID := 210456408;
REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2017.28125, -2496.357666015625, 3343.381103515625, 4.197738170623779296, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1976.6788330078125, -2623.592041015625, 3343.4228515625, 1.187410354614257812, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+2, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2000.521484375, -2561.978515625, 3346.52880859375, 2.012320995330810546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+3, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1999.3206787109375, -2633.978515625, 3343.77392578125, 0.20966002345085144, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+4, 166423, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1905.8563232421875, -2573.52294921875, 3567.72802734375, 5.624324798583984375, 120, 10, 0, 5260, 0, 1, 0, 0, 0, 36839), -- 166423 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+5, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2045.82470703125, -2520.19091796875, 3347.123779296875, 3.594330072402954101, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+6, 164833, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1968.0347900390625, -2642.18408203125, 3343.383544921875, 4.923091888427734375, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164833 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+7, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2011.6317138671875, -2631.35888671875, 3340.489013671875, 4.922724246978759765, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+8, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2035.57470703125, -2564.627197265625, 3344.2783203125, 5.843483448028564453, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+9, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1977.954833984375, -2598.354248046875, 3343.4228515625, 5.081158638000488281, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+10, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1994.68310546875, -2529.545166015625, 3344.166259765625, 1.776147007942199707, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+11, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2045.46142578125, -2569.278076171875, 3346.30615234375, 4.781548500061035156, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+12, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1958.6822509765625, -2493.364501953125, 3343.381103515625, 0.118784442543983459, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+13, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2033.232666015625, -2535.677001953125, 3343.40380859375, 5.823954582214355468, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+14, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1943.75, -2616.666015625, 3348.0478515625, 1.154556155204772949, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+15, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2008.4561767578125, -2515.566650390625, 3343.3017578125, 1.527637124061584472, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+16, 167743, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1966.0521240234375, -2450.376708984375, 3346.068603515625, 1.861667275428771972, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 167743 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+17, 160424, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2027.3316650390625, -2585.197998046875, 3343.945556640625, 3.933727502822875976, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+18, 167737, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2011.420166015625, -2610.460205078125, 3343.381103515625, 2.918777704238891601, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 167737 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+19, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2009.1656494140625, -2557.236572265625, 3343.8212890625, 4.076238632202148437, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+20, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2033.8680419921875, -2529.473876953125, 3343.4169921875, 3.838748455047607421, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+21, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2016.6180419921875, -2490.0244140625, 3343.4091796875, 4.151630401611328125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+22, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2020.3472900390625, -2499.751708984375, 3343.381103515625, 4.206606864929199218, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+23, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2050.779541015625, -2489.322998046875, 3347.02685546875, 1.124118685722351074, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+24, 166423, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1961.1363525390625, -2605.513671875, 3527.9013671875, 2.504010200500488281, 120, 10, 0, 5260, 0, 1, 0, 0, 0, 36839), -- 166423 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+25, 160424, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2021.1510009765625, -2596.960205078125, 3343.381103515625, 1.76176309585571289, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+26, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2027.648193359375, -2472.457763671875, 3344.999755859375, 5.256648540496826171, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+27, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2063.53515625, -2555.42236328125, 3329.98876953125, 2.906686305999755859, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+28, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2045.703125, -2572.767333984375, 3347.40625, 1.958233237266540527, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+29, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2011.2672119140625, -2521.076171875, 3343.3017578125, 1.579207539558410644, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+30, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1986.9569091796875, -2519.96044921875, 3347.17919921875, 5.308321952819824218, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+31, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2005.7332763671875, -2552.70361328125, 3343.6298828125, 2.179738044738769531, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2020.2291259765625, -2493.3369140625, 3343.4091796875, 4.197738170623779296, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+33, 167747, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1970.951416015625, -2450.751708984375, 3345.737548828125, 2.071324586868286132, 120, 0, 0, 23582, 0, 0, 0, 0, 0, 36839), -- 167747 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+34, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2023.5416259765625, -2502.873291015625, 3343.381103515625, 4.266652584075927734, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+35, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2029.545166015625, -2475.592041015625, 3345.1484375, 1.715995550155639648, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+36, 168381, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1972.3072509765625, -2542.157958984375, 3372.173828125, 3.460573196411132812, 120, 0, 0, 2254500, 0, 0, 0, 0, 0, 36839), -- Baroness Draka (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+37, 160424, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2014.5694580078125, -2595.9306640625, 3343.381103515625, 4.943387985229492187, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+38, 160415, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1993.6353759765625, -2535.52783203125, 3343.830078125, 6.147209644317626953, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- 160415 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+39, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1997.3642578125, -2533.1171875, 3343.9677734375, 2.879836320877075195, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+40, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2052.047607421875, -2550.908935546875, 3336.060791015625, 5.860053062438964843, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+41, 160424, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2008.5052490234375, -2602.720458984375, 3343.381103515625, 0.121874772012233734, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+42, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2013.670166015625, -2493.048583984375, 3343.4091796875, 4.151630401611328125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+43, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2050.37353515625, -2552.2724609375, 3336.88232421875, 2.907014369964599609, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+44, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2045.9617919921875, -2484.704833984375, 3347.00830078125, 1.122493624687194824, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+45, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1952.205322265625, -2614.70361328125, 3346.50830078125, 5.067156791687011718, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+46, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2036.015625, -2540.46875, 3343.70068359375, 5.982035636901855468, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+47, 142668, 0, 11462, 11466, '0', '0', 0, 0, 0, 0.100000001490116119, -0.20000000298023223, 0.200000002980232238, 0, 120, 10, 0, 11791, 0, 1, 0, 0, 0, 36839), -- 142668 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) (possible waypoints or random movement)
(@CGUID+48, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1986.458984375, -2585.416015625, 3344.2978515625, 4.712388992309570312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+49, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1997.209716796875, -2519.5087890625, 3343.4228515625, 1.72362065315246582, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 142666, 0, 11462, 11466, '0', '0', 0, 0, 0, 0.100000001490116119, 0.200000002980232238, 0.200000002980232238, 0, 120, 10, 0, 14150, 8626, 1, 0, 0, 0, 36839), -- 142666 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak) (possible waypoints or random movement)
(@CGUID+51, 167741, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1965.4583740234375, -2642.260498046875, 3343.38330078125, 2.85714578628540039, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 167741 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+52, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2047.1922607421875, -2551.51220703125, 3338.521240234375, 6.048619747161865234, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+53, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2011.0592041015625, -2515.24755859375, 3343.3017578125, 1.138341784477233886, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+54, 170971, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1975.7535400390625, -2639.78125, 3343.381103515625, 0.593529105186462402, 120, 0, 0, 235820, 0, 0, 0, 0, 0, 36839), -- 170971 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+55, 170971, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1997.4305419921875, -2473.788330078125, 3343.381103515625, 3.30942392349243164, 120, 0, 0, 235820, 0, 0, 0, 0, 0, 36839), -- 170971 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+56, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2009.984130859375, -2628.40283203125, 3342.308837890625, 5.220864295959472656, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+57, 166423, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1972.5462646484375, -2496.39453125, 3542.59423828125, 0.463556587696075439, 120, 10, 0, 5260, 0, 1, 0, 0, 0, 36839), -- 166423 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+58, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2009.5086669921875, -2629.322998046875, 3342.255615234375, 5.2736663818359375, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+59, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1943.1180419921875, -2560.717041015625, 3375.19580078125, 2.36722111701965332, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+60, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1921.638916015625, -2524.619873046875, 3379.347412109375, 4.819623947143554687, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+61, 167209, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1874.93408203125, -2562.88720703125, 3388.121826171875, 2.945458173751831054, 120, 0, 0, 117910, 2434, 0, 0, 0, 0, 36839), -- 167209 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+62, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1899.9722900390625, -2535.045166015625, 3383.49658203125, 5.409454345703125, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+63, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1943.5035400390625, -2533.57470703125, 3375.185546875, 4.02690744400024414, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+64, 158339, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1875.079833984375, -2533.204833984375, 3388.121826171875, 3.88163924217224121, 120, 0, 0, 58955, 0, 0, 0, 0, 0, 36839), -- 158339 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 344880 - Carry Candle)
(@CGUID+65, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1921.439208984375, -2571.66845703125, 3379.347412109375, 1.439418792724609375, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+66, 164667, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1899.329833984375, -2561.07470703125, 3383.49658203125, 0.866145730018615722, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- Prime Shieldguard (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+67, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2038.861083984375, -2541.3525390625, 3342.942138671875, 2.93044447898864746, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+68, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1989.5830078125, -2449.478515625, 3343.37841796875, 3.255756616592407226, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+69, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1955.7015380859375, -2444.409423828125, 3341.68994140625, 4.839650154113769531, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+70, 175021, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1964.6387939453125, -2442.756591796875, 3337.9345703125, 0.172692671418190002, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+71, 62821, 0, 11462, 11466, '0', '0', 0, 0, 0, -0.20000000298023223, 0, -0.20000000298023223, 0, 120, 0, 0, 14150, 8626, 0, 0, 0, 0, 36839), -- 62821 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak, 123236 - Grummle Booth A)
(@CGUID+72, 62822, 0, 11462, 11466, '0', '0', 0, 0, 0, -0.20000000298023223, 0, -0.20000000298023223, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 62822 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 122729 - Grand Expedition Yak)
(@CGUID+73, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1918.2869873046875, -2664.029296875, 3336.8671875, 5.38168954849243164, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+74, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1915.90380859375, -2658.876220703125, 3338.815673828125, 3.114255666732788085, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+75, 157843, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1885.1197509765625, -2731.1962890625, 3339.352783203125, 6.050756454467773437, 120, 0, 0, 1179100, 0, 0, 0, 0, 0, 36839), -- 157843 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314898 - Visectus, 247866 - Set Health % (Uses Override Points) (No Health Regen))
(@CGUID+76, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2038.7052001953125, -2634.072998046875, 3323.56787109375, 5.925952911376953125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+77, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2026.428955078125, -2649.760986328125, 3328.437744140625, 5.660286903381347656, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+78, 157514, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1975.4149169921875, -2678.458251953125, 3337.81689453125, 3.776234626770019531, 120, 0, 0, 294775, 0, 0, 0, 0, 0, 36839), -- 157514 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+79, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1971.3836669921875, -2662.343994140625, 3337.1923828125, 5.905835628509521484, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+80, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1978.49609375, -2660.615234375, 3338.408447265625, 4.199504852294921875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+81, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2041.58837890625, -2635.81201171875, 3322.4697265625, 2.105183362960815429, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+82, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2040.095458984375, -2638.90283203125, 3321.51025390625, 3.485710382461547851, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+83, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2017.1710205078125, -2647.0791015625, 3332.77880859375, 2.94066476821899414, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+84, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2014.048583984375, -2646.27783203125, 3334.263916015625, 5.383721828460693359, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+85, 157803, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1886.8472900390625, -2732.34375, 3339.670654296875, 0, 120, 0, 0, 75150000, 0, 0, 0, 0, 0, 36839), -- 157803 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 307830 - Archon Fragment)
(@CGUID+86, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1993.2222900390625, -2687.161376953125, 3338.717529296875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+87, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1989.392333984375, -2691.651123046875, 3340.08203125, 6.215439796447753906, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+88, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1984.695556640625, -2679.5146484375, 3339.162109375, 1.485578775405883789, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+89, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1989.953125, -2688.420166015625, 3340.20947265625, 0.390409827232360839, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+90, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1910.552978515625, -2664.42578125, 3341.339111328125, 0.958515286445617675, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+91, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1993.9635009765625, -2689.907958984375, 3339.31982421875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+92, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2028.27783203125, -2674.442626953125, 3321.300048828125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+93, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2010.546875, -2681.501708984375, 3325.46044921875, 3.671384334564208984, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+94, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2036.1632080078125, -2664.194580078125, 3319.23779296875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+95, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1927.1973876953125, -2686.953857421875, 3333.59765625, 4.950263023376464843, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+96, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2031.592041015625, -2675.40625, 3319.148681640625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343800 - [DNT] - Flavor 2)
(@CGUID+97, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1903.2916259765625, -2669.9833984375, 3348.130615234375, 1.561607956886291503, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+98, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1993.9635009765625, -2703.119873046875, 3337.464111328125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+99, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1928.495361328125, -2694.426025390625, 3333.346923828125, 2.01589512825012207, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+100, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2056.771484375, -2652.603515625, 3312.47802734375, 5.435537338256835937, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+101, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2073.038330078125, -2598.423583984375, 3322.22509765625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343329 - [DNT] - Flavor 2)
(@CGUID+102, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2057.03173828125, -2663.086181640625, 3313.07177734375, 4.709901809692382812, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+103, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2081.654541015625, -2600.72314453125, 3319.6181640625, 3.415428638458251953, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+104, 164833, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1954.4254150390625, -2705.270751953125, 3333.04345703125, 2.732350111007690429, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164833 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+105, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2083.320068359375, -2599.9365234375, 3319.301025390625, 2.033410549163818359, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+106, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2077.185791015625, -2596.232666015625, 3322.26611328125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343800 - [DNT] - Flavor 2)
(@CGUID+107, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2081.9052734375, -2597.103515625, 3320.30126953125, 6.215342044830322265, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+108, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2010.2742919921875, -2708.786376953125, 3319.810302734375, 3.27124190330505371, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+109, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2085.449462890625, -2596.327392578125, 3319.77099609375, 0.642865717411041259, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+110, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2084.96044921875, -2599.060302734375, 3319.109375, 0.833506882190704345, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+111, 161881, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2084.807373046875, -2626.2275390625, 3314.162109375, 5.115702152252197265, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161881 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+112, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2085.437255859375, -2597.343505859375, 3319.414794921875, 6.212669849395751953, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+113, 167273, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1962.6597900390625, -2716.208251953125, 3338.997802734375, 3.856135845184326171, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167273 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+114, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1964.842041015625, -2726.15966796875, 3333.06298828125, 0.504369676113128662, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+115, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2028.4923095703125, -2723.180419921875, 3313.173583984375, 1.863188982009887695, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+116, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2090.625, -2687.5, 3312.74951171875, 3.063702344894409179, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+117, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2091.6669921875, -2685.416015625, 3312.74951171875, 3.067731380462646484, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+118, 161676, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1958.8697509765625, -2725.604248046875, 3333.05908203125, 3.825467824935913085, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 161676 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+119, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2012.3541259765625, -2735.482666015625, 3315.147705078125, 0.198879584670066833, 120, 10, 0, 9018, 0, 1, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+120, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2091.85302734375, -2644.220458984375, 3309.36669921875, 2.420465707778930664, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+121, 167642, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1951.203125, -2719.045166015625, 3333.079345703125, 5.097023963928222656, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 167642 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+122, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2022.4827880859375, -2725.41650390625, 3313.302001953125, 4.149187088012695312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+123, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1974.342041015625, -2762.1806640625, 3331.531005859375, 6.225484371185302734, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+124, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2004.4073486328125, -2751.88720703125, 3318.5849609375, 3.08680891990661621, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+125, 161679, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1890.87158203125, -2718.038330078125, 3339.26806640625, 5.446991443634033203, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 36839), -- 161679 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+126, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1980.671875, -2755.11279296875, 3327.947021484375, 6.225484371185302734, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+127, 160415, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1969.9288330078125, -2740.850830078125, 3337.3349609375, 5.400506019592285156, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- 160415 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+128, 167641, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1952.9375, -2728.76904296875, 3333.03759765625, 2.276464223861694335, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 167641 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+129, 161679, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1902.5382080078125, -2723.635498046875, 3339.236328125, 4.132448673248291015, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 36839), -- 161679 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+130, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1917.805908203125, -2697.02099609375, 3338.151611328125, 2.065711498260498046, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+131, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1957.826416015625, -2753.22216796875, 3334.204345703125, 6.247388839721679687, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+132, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2000.765625, -2751.6875, 3318.962158203125, 4.20342874526977539, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+133, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1899.7969970703125, -2677.940673828125, 3350.419677734375, 3.027600288391113281, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+134, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1917.7080078125, -2692.1875, 3338.079345703125, 4.48409128189086914, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+135, 168045, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1929.4461669921875, -2753.085205078125, 3334.392822265625, 5.869208812713623046, 120, 0, 0, 117910, 2434, 0, 0, 0, 0, 36839), -- 168045 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+136, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1988.7314453125, -2767.082275390625, 3323.762451171875, 0.889510750770568847, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+137, 161395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1990.65087890625, -2769.814453125, 3322.719482421875, 2.840318202972412109, 120, 0, 0, 15030, 0, 0, 0, 0, 0, 36839), -- 161395 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 330574 - Deathbolt Rift)
(@CGUID+138, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1896.34033203125, -2736.776123046875, 3351.19873046875, 0.058591142296791076, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+139, 161668, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1906.986083984375, -2742.079833984375, 3339.232421875, 1.138158917427062988, 120, 0, 0, 117910, 100, 0, 0, 0, 0, 36839), -- 161668 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+140, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2039.904541015625, -2636.170166015625, 3322.61669921875, 3.485710382461547851, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+141, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2062.4501953125, -2770.779296875, 3312.76171875, 1.857490897178649902, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+142, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2004.3975830078125, -2775.78125, 3332.248779296875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+143, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2058.719482421875, -2773.843017578125, 3312.78857421875, 3.089009523391723632, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+144, 161395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2066.301025390625, -2769.69921875, 3313.123291015625, 1.857950091361999511, 120, 0, 0, 15030, 0, 0, 0, 0, 0, 36839), -- 161395 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+145, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2093.4375, -2690.5, 3314.0234375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343329 - [DNT] - Flavor 2)
(@CGUID+146, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2004.3975830078125, -2781.600830078125, 3333.705810546875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+147, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2064.253662109375, -2786.187744140625, 3312.75341796875, 0.868824124336242675, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+148, 169634, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2066.382080078125, -2790.05029296875, 3312.73095703125, 4.40022897720336914, 120, 0, 0, 20265, 0, 0, 0, 0, 0, 36839), -- 169634 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+149, 162258, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2218.685791015625, -2793.741455078125, 3312.016357421875, 5.514188766479492187, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+150, 161390, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2062.569580078125, -2785.350830078125, 3312.75341796875, 5.490456104278564453, 120, 0, 0, 11273, 0, 0, 0, 0, 0, 36839), -- 161390 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+151, 161390, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2065.37353515625, -2784.667724609375, 3312.75341796875, 4.447387218475341796, 120, 0, 0, 11273, 0, 0, 0, 0, 0, 36839), -- 161390 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+152, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2063.799072265625, -2807.490234375, 3316.1162109375, 5.693767547607421875, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+153, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2066.901611328125, -2809.56494140625, 3315.758056640625, 2.552175045013427734, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+154, 161395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2057.7080078125, -2831.857421875, 3314.701171875, 0.214103877544403076, 120, 0, 0, 15030, 0, 0, 0, 0, 0, 36839), -- 161395 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+155, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2058.19580078125, -2829.13427734375, 3314.701171875, 5.709872722625732421, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+156, 161396, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2054.752685546875, -2832.407470703125, 3314.701171875, 1.319049358367919921, 120, 0, 0, 52605, 0, 0, 0, 0, 0, 36839), -- 161396 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+157, 170456, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2055.6982421875, -2948.866943359375, 3287.322021484375, 3.136948823928833007, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+158, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1962.6072998046875, -2838.7177734375, 3343.763916015625, 1.552674174308776855, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+159, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2098.8203125, -2885.394287109375, 3286.016845703125, 0.605122327804565429, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+160, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2108.349609375, -2879.01513671875, 3285.80712890625, 6.169547080993652343, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+161, 170456, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2082.14013671875, -3030.156982421875, 3288.85302734375, 6.217403411865234375, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+162, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2101.0244140625, -2905.1875, 3285.9287109375, 1.484757542610168457, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+163, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2106.609375, -2904.486083984375, 3285.92041015625, 2.49511122703552246, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+164, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2030.52783203125, -2928.220458984375, 3266.302978515625, 1.49242401123046875, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+165, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2031.74658203125, -2920.70654296875, 3268.35595703125, 5.131856918334960937, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+166, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2066.15283203125, -2922.21875, 3273.413330078125, 3.260222673416137695, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+167, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2104.71533203125, -2903.600830078125, 3285.933349609375, 4.038171768188476562, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+168, 167949, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2028.923583984375, -2921.307373046875, 3267.95654296875, 5.64362192153930664, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+169, 167356, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2049.94482421875, -2944.92333984375, 3268.080810546875, 4.087513446807861328, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+170, 170456, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2206.792236328125, -3005.018310546875, 3258.346435546875, 1.523935198783874511, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+171, 167948, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2093.423583984375, -2970.994873046875, 3238.87744140625, 5.984332084655761718, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 167948 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+172, 160048, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2196.701416015625, -2925.916748046875, 3245.981689453125, 1.342139959335327148, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+173, 170191, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2208.0625, -2833.810791015625, 3262.111328125, 4.71624612808227539, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+174, 167935, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2193.60693359375, -2939.124755859375, 3244.724853515625, 2.830030202865600585, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+175, 176023, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2205.519775390625, -2826.494140625, 3267.12744140625, 2.353205442428588867, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+176, 160048, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2187.478515625, -2954.861572265625, 3244.2001953125, 3.460696935653686523, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+177, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2197.525634765625, -2951.16552734375, 3242.267822265625, 2.486373424530029296, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+178, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2198.1181640625, -2922.75341796875, 3245.7080078125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+179, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2183.928955078125, -2950.28466796875, 3244.31884765625, 0.909604787826538085, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+180, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2233.643310546875, -2920.8466796875, 3240.50927734375, 2.229704856872558593, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+181, 162258, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2340.33740234375, -2866.728515625, 3296.52734375, 4.58116769790649414, 120, 10, 0, 9018, 0, 1, 0, 0, 0, 36839), -- 162258 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+182, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2229.1298828125, -2927.688232421875, 3240.044677734375, 5.110485076904296875, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+183, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2240.085205078125, -2859.95654296875, 3254.347900390625, 6.166468620300292968, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 154470 - Permanent Feign Death (Flies))
(@CGUID+184, 162258, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2276.017333984375, -2739.986083984375, 3323.4345703125, 1.359341382980346679, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+185, 170191, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2206.34033203125, -2812.458251953125, 3263.758056640625, 2.094174146652221679, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+186, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2238.939208984375, -2898.14208984375, 3244.96337890625, 1.6520538330078125, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+187, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2209.501708984375, -2804.74658203125, 3264.848388671875, 2.069040775299072265, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+188, 162258, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2293.865234375, -2749.099609375, 3294.768310546875, 0.913706898689270019, 120, 10, 0, 9018, 0, 1, 0, 0, 0, 36839), -- 162258 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+189, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2239.40283203125, -2824.05908203125, 3260.260498046875, 2.29669046401977539, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+190, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2248.544189453125, -2843.199951171875, 3260.343017578125, 4.24346160888671875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+191, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2179.82666015625, -2969.533935546875, 3241.757568359375, 0.028082503005862236, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+192, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2234.486083984375, -2820.173583984375, 3293.5244140625, 0, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+193, 162258, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2311.361083984375, -2755.814208984375, 3333.1455078125, 0.455417573451995849, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+194, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2226.29833984375, -2934.432373046875, 3239.44189453125, 3.79192972183227539, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+195, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2254.544921875, -2897.25390625, 3249.113037109375, 6.261911869049072265, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+196, 170191, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2238.317626953125, -2838.850830078125, 3256.200439453125, 6.213176250457763671, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+197, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2233.3330078125, -2941.666015625, 3238.38623046875, 4.92838287353515625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+198, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2246.669921875, -2845.873046875, 3257.8974609375, 3.984477043151855468, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+199, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2251.097412109375, -2905.932373046875, 3247.15771484375, 2.964883804321289062, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+200, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2234.9990234375, -2925.7451171875, 3239.27587890625, 4.778882980346679687, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+201, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2244.43896484375, -2848.37646484375, 3257.603759765625, 0.842884302139282226, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+202, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2245.869873046875, -2851.58154296875, 3256.94091796875, 4.294834136962890625, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 154470 - Permanent Feign Death (Flies))
(@CGUID+203, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2246.055419921875, -2876.157470703125, 3251.363037109375, 1.396165251731872558, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+204, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2233.07470703125, -2817.859375, 3293.765869140625, 0.980610013008117675, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+205, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2257.6494140625, -2810.03759765625, 3264.39013671875, 2.769791126251220703, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+206, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2275.656982421875, -2884.593017578125, 3252.57177734375, 0.969988584518432617, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+207, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2257.394775390625, -2931.79052734375, 3241.898193359375, 1.464706301689147949, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+208, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2255.7275390625, -2939.317626953125, 3240.23193359375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+209, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2256.9931640625, -2942.257080078125, 3240.85888671875, 2.17063760757446289, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+210, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2216.6806640625, -2967.288330078125, 3246.623291015625, 0.909604787826538085, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+211, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2228.578369140625, -2964.14111328125, 3248.854248046875, 1.926676750183105468, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+212, 173200, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2278.16748046875, -2815.033203125, 3261.903076171875, 0.984936118125915527, 120, 10, 0, 27, 0, 1, 0, 0, 0, 36839), -- Bleak Skitterer (Area: Blighted Scar - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+213, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2280.9765625, -2923.817138671875, 3249.875732421875, 1.690369606018066406, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+214, 169751, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2298.9853515625, -2824.010009765625, 3266.192626953125, 2.29151773452758789, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 169751 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+215, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2295.77783203125, -2825.48095703125, 3261.5634765625, 1.766286015510559082, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+216, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2228.76513671875, -2967.7333984375, 3245.859375, 5.642128944396972656, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+217, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2315.799560546875, -2914.642822265625, 3253.079345703125, 2.970995903015136718, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+218, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2322.147705078125, -2849.854248046875, 3255.40087890625, 2.684131860733032226, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+219, 170191, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2292.4775390625, -2804.2275390625, 3258.716796875, 2.582122564315795898, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+220, 168216, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2422.2587890625, -2913.139892578125, 3299.3115234375, 4.568684101104736328, 120, 10, 0, 60120, 0, 1, 0, 0, 0, 36839), -- 168216 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+221, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2236.520751953125, -2967.43408203125, 3242.2412109375, 4.353937625885009765, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+222, 169751, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2294.036865234375, -2797.794921875, 3265.475830078125, 0.045861829072237014, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 169751 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+223, 170191, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2327.2744140625, -2858.248291015625, 3253.50244140625, 4.9617919921875, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+224, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2315.432373046875, -2852.095458984375, 3255.53271484375, 3.318004846572875976, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+225, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2312.503173828125, -2846.485595703125, 3259.68212890625, 1.182038664817810058, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+226, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2307.943359375, -2907.949951171875, 3252.80126953125, 2.347651004791259765, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+227, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2312.913330078125, -2819.8125, 3261.37158203125, 4.525880336761474609, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+228, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2311.083251953125, -2821.56591796875, 3258.611572265625, 2.069040775299072265, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt) (possible waypoints or random movement)
(@CGUID+229, 137744, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2317.1650390625, -2841.647705078125, 3256.448486328125, 5.460045814514160156, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+230, 159930, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2410.4619140625, -2930.53466796875, 3271.01220703125, 1.240787029266357421, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 159930 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+231, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2316.6669921875, -2839.583984375, 3256.44873046875, 3.060869693756103515, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+232, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2337.0869140625, -2872.27783203125, 3251.6884765625, 6.015443801879882812, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+233, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2297.204833984375, -2949.576416015625, 3238.31787109375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+234, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2329.259033203125, -2882.811767578125, 3252.036376953125, 1.738075852394104003, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+235, 169751, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2310.5615234375, -2805.403076171875, 3267.913330078125, 0.910709321498870849, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 169751 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+236, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2314.1494140625, -2816.2744140625, 3257.9267578125, 2.766138076782226562, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt) (possible waypoints or random movement)
(@CGUID+237, 173200, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2290.779296875, -2788.351806640625, 3261.63134765625, 5.176036834716796875, 120, 10, 0, 27, 0, 1, 0, 0, 0, 36839), -- Bleak Skitterer (Area: Blighted Scar - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+238, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2322.800537109375, -2900.20849609375, 3252.55126953125, 1.973911881446838378, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+239, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2343.07080078125, -2925.652587890625, 3254.632080078125, 3.962690114974975585, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+240, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2343.639892578125, -2867.91015625, 3251.4384765625, 5.07247781753540039, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+241, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2235.666748046875, -2970.0244140625, 3242.24658203125, 2.163031578063964843, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+242, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2234.79345703125, -2969.079833984375, 3242.3037109375, 0.235479891300201416, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+243, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2273.646240234375, -2971.7724609375, 3238.434814453125, 1.869317293167114257, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+244, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2314.5830078125, -2953.125, 3245.821533203125, 2.034443855285644531, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+245, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2261.60009765625, -2966.23974609375, 3238.2626953125, 5.355446815490722656, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+246, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2332.885498046875, -2928.567626953125, 3254.42626953125, 3.939928531646728515, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+247, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2248.341552734375, -2968.574462890625, 3239.576416015625, 0.619454145431518554, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+248, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2264.257080078125, -2978.029541015625, 3239.7763671875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+249, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2358.76904296875, -2846.166748046875, 3253.888427734375, 0.567053556442260742, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839); -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%; 276684 - Churning Dirt)

REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2347.3671875, -2824.27734375, 3250.458740234375, 3.241358757019042968, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+251, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2340.117431640625, -2816.049560546875, 3253.76611328125, 1.501073002815246582, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+252, 137744, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2343.90625, -2814.921875, 3250.1103515625, 1.383555293083190917, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+253, 170191, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2360.576416015625, -2843.036376953125, 3254.137451171875, 0.305875241756439208, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+254, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2282.447021484375, -2980.8369140625, 3238.35302734375, 4.999672889709472656, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+255, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2366.44677734375, -2875.70166015625, 3260.966796875, 5.843714237213134765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0)
(@CGUID+256, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2362.8740234375, -2835.591796875, 3257.43310546875, 0.064966797828674316, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+257, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2366.7080078125, -2835.3671875, 3256.049072265625, 1.663152337074279785, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+258, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2345.1962890625, -2815.625, 3250.03515625, 3.38190770149230957, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+259, 169751, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2374.80224609375, -2840.535400390625, 3260.934814453125, 1.329696297645568847, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 169751 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+260, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2381.28466796875, -2895.3681640625, 3278.09912109375, 4.905645370483398437, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+261, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2351.4375, -2990.26904296875, 3262.2861328125, 2.889139890670776367, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+262, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2373.581298828125, -2855.36962890625, 3252.221435546875, 0.211448460817337036, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+263, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2339.963623046875, -2956.37158203125, 3248.827880859375, 3.970084667205810546, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+264, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2404.354248046875, -2891.734375, 3284.630126953125, 4.905645370483398437, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+265, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2303.897705078125, -2986.806640625, 3241.04931640625, 1.137915730476379394, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+266, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2271.447509765625, -2991.638427734375, 3240.228759765625, 3.967080116271972656, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+267, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2395.018310546875, -2927.9091796875, 3290.986328125, 3.071582794189453125, 120, 10, 0, 5260, 0, 1, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+268, 170191, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2394.592041015625, -2863.585205078125, 3255.785888671875, 5.032810211181640625, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+269, 169751, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2365.2529296875, -2834.718505859375, 3259.47314453125, 2.137642860412597656, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 169751 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+270, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2326.06591796875, -2983.39697265625, 3241.24658203125, 0.468455284833908081, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+271, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2341, -2958.45654296875, 3248.48046875, 3.898364543914794921, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+272, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2354.7431640625, -2988.876708984375, 3263.55224609375, 2.360275506973266601, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+273, 162258, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2447.526123046875, -2761.897705078125, 3290.900146484375, 3.578351020812988281, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+274, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2374.395751953125, -2865.307373046875, 3254.934326171875, 1.851683735847473144, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+275, 137744, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2349.423583984375, -2816.670166015625, 3249.81103515625, 4.538360595703125, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+276, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2393.388916015625, -2857.715576171875, 3258.134765625, 0.86182260513305664, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+277, 162258, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2514.16748046875, -2894.96875, 3279.0458984375, 0.23496536910533905, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+278, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2400.26904296875, -2863.302001953125, 3254.25537109375, 4.328539371490478515, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+279, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2277.057373046875, -2999.6962890625, 3239.244384765625, 6.054770946502685546, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+280, 162256, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2414.166748046875, -2928.84033203125, 3270.992919921875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: Blighted Scar - Difficulty: 0)
(@CGUID+281, 162257, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2416.451416015625, -2927.876708984375, 3271.076904296875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: Blighted Scar - Difficulty: 0)
(@CGUID+282, 165034, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2424.2255859375, -2932.2265625, 3271.773681640625, 2.714308738708496093, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- 165034 (Area: Blighted Scar - Difficulty: 0) (Auras: )
(@CGUID+283, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2382.625, -2834.47216796875, 3249.79443359375, 4.432050704956054687, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+284, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2315.142333984375, -3014.866455078125, 3239.7099609375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+285, 168196, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2404.541748046875, -2849.553955078125, 3254.79833984375, 3.753757238388061523, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168196 (Area: Blighted Scar - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+286, 168196, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2402.90283203125, -2842.8681640625, 3251.808837890625, 5.289970874786376953, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168196 (Area: Blighted Scar - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+287, 176024, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2390.071533203125, -2835.4814453125, 3254.394287109375, 4.690823078155517578, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+288, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2435.807373046875, -2862.201416015625, 3257.230712890625, 5.855019092559814453, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+289, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2448.8125, -2891.05029296875, 3277.375, 0.660175263881683349, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+290, 168196, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2414.84033203125, -2844.192626953125, 3255.95556640625, 2.313682317733764648, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168196 (Area: Blighted Scar - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+291, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2443.01220703125, -2877.50830078125, 3287.931640625, 6.151170253753662109, 120, 10, 0, 5260, 0, 1, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+292, 176024, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2426.996826171875, -2855.880615234375, 3261.428955078125, 2.420492172241210937, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+293, 168192, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2419.3056640625, -2856.132080078125, 3256.460205078125, 1.934009432792663574, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 168192 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+294, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2428.8056640625, -2862.623291015625, 3256.88427734375, 5.56825113296508789, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+295, 168196, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2419.70654296875, -2841.791748046875, 3256.02294921875, 0, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168196 (Area: Blighted Scar - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+296, 158642, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2754.611572265625, -3010.896484375, 3309.811279296875, 5.69518280029296875, 120, 10, 0, 213570, 0, 1, 0, 0, 0, 36839), -- 158642 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+297, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2378.064208984375, -2827.935791015625, 3250.31640625, 3.958032608032226562, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+298, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2430.447021484375, -2855.621337890625, 3259.880126953125, 3.005191564559936523, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+299, 176024, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2439.597900390625, -2857.575439453125, 3262.93603515625, 5.651319503784179687, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+300, 170191, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2433.3056640625, -2846.484375, 3256.591796875, 1.025191307067871093, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Blighted Scar - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+301, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2436.30078125, -2861.087890625, 3257.0947265625, 2.38381195068359375, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+302, 168196, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2428.50341796875, -2845.765625, 3256.60205078125, 2.056501388549804687, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168196 (Area: Blighted Scar - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+303, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2398.463623046875, -2829.657958984375, 3249.917236328125, 5.763590335845947265, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+304, 174653, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2449.36865234375, -2856.0322265625, 3257.72509765625, 5.701679229736328125, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+305, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2442.29296875, -2837.34619140625, 3254.9013671875, 3.382529735565185546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+306, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2408.543212890625, -2822.803955078125, 3249.57275390625, 4.374713897705078125, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+307, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2380.533935546875, -2817.974609375, 3249.393798828125, 0.348681211471557617, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+308, 168196, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2432.41845703125, -2828.833251953125, 3255.427490234375, 0, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168196 (Area: Blighted Scar - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+309, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2359.183837890625, -2818.567138671875, 3249.794189453125, 3.951188564300537109, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+310, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2289.1650390625, -2946.78125, 3238.9951171875, 3.305803775787353515, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+311, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2366.51318359375, -2809.75048828125, 3249.206298828125, 3.115473508834838867, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+312, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2352.3125, -2808.451171875, 3248.75048828125, 6.208885669708251953, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+313, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2400.083251953125, -2805.220458984375, 3250.0634765625, 3.673630475997924804, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+314, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2345.279296875, -2807.8671875, 3248.833740234375, 2.920820951461791992, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+315, 176024, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2329.8642578125, -2798.326171875, 3254.373046875, 1.142183542251586914, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+316, 162258, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2326.080810546875, -2696.083984375, 3307.63232421875, 2.091886520385742187, 120, 10, 0, 9018, 0, 1, 0, 0, 0, 36839), -- 162258 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+317, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2340.1708984375, -2793.900146484375, 3247.96240234375, 3.870343446731567382, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+318, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2395.74951171875, -2797.326416015625, 3251.078857421875, 5.692710399627685546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+319, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2325.06396484375, -2804.87646484375, 3252.077392578125, 2.615907669067382812, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+320, 175021, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2348.31396484375, -2796.3251953125, 3247.243896484375, 5.274785518646240234, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+321, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2362.963134765625, -2791.975341796875, 3247.45458984375, 0.046161141246557235, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+322, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2394.811767578125, -2791.714599609375, 3251.134765625, 3.21854257583618164, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+323, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2352.380126953125, -2786.486328125, 3247.724609375, 4.284271240234375, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+324, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2389.950927734375, -2790.0068359375, 3254.693115234375, 3.705686569213867187, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+325, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2388.710205078125, -2801.4931640625, 3251.884521484375, 3.245243549346923828, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+326, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2324.640625, -2800.11474609375, 3251.449951171875, 4.574222087860107421, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+327, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2321.598388671875, -2790.3154296875, 3249.988525390625, 1.161521673202514648, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+328, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2330.875, -2792.126708984375, 3248.4970703125, 3.44615793228149414, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+329, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2324.2841796875, -2795.6259765625, 3250.01318359375, 4.908060073852539062, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+330, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2321.107421875, -2792.7900390625, 3250.5498046875, 0.013671022839844226, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+331, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2347.143798828125, -2787.983154296875, 3247.994140625, 0.967165887355804443, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+332, 160048, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2294.345458984375, -2949.569580078125, 3238.191162109375, 0.687188208103179931, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+333, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2380.004638671875, -2774.12353515625, 3254.639404296875, 3.153614044189453125, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+334, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2355.832275390625, -2770.953857421875, 3248.92578125, 0.404732197523117065, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+335, 169751, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2375.48046875, -2776.21923828125, 3254.61865234375, 5.124756813049316406, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 169751 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+336, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2325.312255859375, -2779.340576171875, 3250.986572265625, 5.373860359191894531, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+337, 137744, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2392.3994140625, -2801.001708984375, 3251.634033203125, 1.55271613597869873, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+338, 137744, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2297.7119140625, -2779.848876953125, 3261.081787109375, 2.778716802597045898, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+339, 167356, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2287.911865234375, -2951.978515625, 3238.718505859375, 4.297332763671875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+340, 137744, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2315.526123046875, -2771.54345703125, 3253.417724609375, 6.137176036834716796, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+341, 167356, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2292.421142578125, -2959.051513671875, 3238.8349609375, 4.165462017059326171, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+342, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2289.962890625, -2778.8251953125, 3264.631591796875, 4.461243629455566406, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+343, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2320.1962890625, -2768.8779296875, 3253.859130859375, 5.70926666259765625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+344, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2324.2060546875, -2770.24072265625, 3260.767822265625, 4.424268245697021484, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+345, 160048, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2256.830078125, -2933.0166015625, 3241.2783203125, 0.21259358525276184, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+346, 167356, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2298.232666015625, -2945.59716796875, 3238.79736328125, 3.524274587631225585, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+347, 137744, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2379.725830078125, -2772.927001953125, 3250.5849609375, 1.363084673881530761, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+348, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2342.208984375, -2759.676025390625, 3252.4580078125, 1.008698105812072753, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+349, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2374.322998046875, -2764.84375, 3252.48095703125, 5.698212146759033203, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+350, 173200, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2303.319580078125, -2750.951904296875, 3265.328125, 5.54885721206665039, 120, 10, 0, 27, 0, 1, 0, 0, 0, 36839), -- Bleak Skitterer (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+351, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2284.248291015625, -2758.85009765625, 3269.26220703125, 4.511319160461425781, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+352, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2345.8173828125, -2744.95703125, 3255.111083984375, 4.7333831787109375, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+353, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2277.593017578125, -2750.93701171875, 3266.7568359375, 0.818535208702087402, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+354, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2345.77685546875, -2743.04833984375, 3255.30126953125, 6.010251998901367187, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+355, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2287.267333984375, -2741.607666015625, 3267.3017578125, 2.062731742858886718, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+356, 167949, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2331.736083984375, -2925.882080078125, 3254.399658203125, 1.095873236656188964, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+357, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2350.779541015625, -2738.26806640625, 3257.190185546875, 3.221884727478027343, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+358, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2405.074951171875, -2774.956787109375, 3252.74072265625, 2.348834991455078125, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+359, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2350.065185546875, -2734.02001953125, 3255.68359375, 1.525594830513000488, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+360, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2363.76025390625, -2738.12890625, 3252.842529296875, 0.762413740158081054, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+361, 137744, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2285.319580078125, -2738.954833984375, 3267.916748046875, 1.234597206115722656, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+362, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2434.979248046875, -2791.4931640625, 3252.321533203125, 0.821720480918884277, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+363, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2349.686279296875, -2724.98291015625, 3255.17529296875, 1.17079317569732666, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+364, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2397.1552734375, -2737.777099609375, 3260.739013671875, 2.993640422821044921, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+365, 173200, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2321.578857421875, -2721.163818359375, 3262.361572265625, 4.740701675415039062, 120, 10, 0, 27, 0, 1, 0, 0, 0, 36839), -- Bleak Skitterer (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+366, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2399.899169921875, -2733.506591796875, 3258.28173828125, 1.376034855842590332, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+367, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2418.221435546875, -2746.489501953125, 3263.788818359375, 3.234544992446899414, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+368, 169751, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2435.266845703125, -2770.957275390625, 3268.516845703125, 2.502473354339599609, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 169751 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+369, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2421.005126953125, -2748.895751953125, 3260.6103515625, 2.35412144660949707, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+370, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2418.4306640625, -2746.507080078125, 3260.532958984375, 0.815209031105041503, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+371, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2345.079345703125, -2715.6171875, 3258.83203125, 5.711437225341796875, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+372, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2445.3125, -2792.701416015625, 3251.190673828125, 4.9617919921875, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+373, 176024, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2354.4580078125, -2716.03955078125, 3260.095703125, 4.846096515655517578, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+374, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2323.60009765625, -2713.16015625, 3267.693603515625, 2.764106035232543945, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+375, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2352.6650390625, -2711.005859375, 3257.94677734375, 1.418058753013610839, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+376, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2328.947998046875, -2708.96533203125, 3262.23779296875, 5.504957199096679687, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+377, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2399.105712890625, -2724.737548828125, 3257.00146484375, 3.175555706024169921, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+378, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2370.376708984375, -2713.579833984375, 3256.45751953125, 6.226756095886230468, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+379, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2328.953125, -2708.82470703125, 3262.197509765625, 1.062417984008789062, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+380, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2376.825439453125, -2713.891845703125, 3257.84765625, 5.783167839050292968, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+381, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2332.078125, -2709.46826171875, 3268.325439453125, 4.550196170806884765, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+382, 169751, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2430.819091796875, -2752.13916015625, 3269.050048828125, 2.39530181884765625, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169751 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+383, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2450.22021484375, -2797.35595703125, 3251.158447265625, 5.378139019012451171, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+384, 169751, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2449.37939453125, -2776.492919921875, 3274.8251953125, 1.153174400329589843, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169751 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+385, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2453.888916015625, -2801.69091796875, 3252.30419921875, 0.669051051139831542, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+386, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2420.458251953125, -2736.404541015625, 3260.42919921875, 4.156490802764892578, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+387, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2417.52783203125, -2736.5244140625, 3260.401123046875, 4.980162620544433593, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+388, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2410.182373046875, -2726.697998046875, 3258.49462890625, 4.530360221862792968, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+389, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2444.5625, -2745.14404296875, 3264.333740234375, 5.048801422119140625, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+390, 162259, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2455.171875, -2756.09716796875, 3292.74462890625, 5.886641502380371093, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+391, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2464.100830078125, -2772.069580078125, 3264.64013671875, 2.375732898712158203, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 264867 - Churning Dirt)
(@CGUID+392, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2461.760498046875, -2769.819580078125, 3264.43212890625, 2.484794139862060546, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+393, 162259, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2454.8349609375, -2761.3671875, 3292.9013671875, 0.293903470039367675, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+394, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2442.32470703125, -2746.357666015625, 3264.014404296875, 0.153688356280326843, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+395, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2466.3837890625, -2765.069580078125, 3266.059326171875, 5.533658027648925781, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+396, 162259, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2458.642333984375, -2758.532958984375, 3292.1884765625, 2.344778060913085937, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+397, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2448.226318359375, -2747.9833984375, 3267.908447265625, 3.369851589202880859, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+398, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2451.280517578125, -2744.3017578125, 3265.680419921875, 2.115331649780273437, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+399, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2419.770263671875, -2716.94580078125, 3259.51708984375, 0.257275909185409545, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+400, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2410.458740234375, -2714.262939453125, 3258.438232421875, 2.186999320983886718, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+401, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2426.613037109375, -2714.0712890625, 3261.070068359375, 3.732433080673217773, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+402, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2467.61328125, -2755.0771484375, 3267.00146484375, 5.219717979431152343, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+403, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2466.197021484375, -2757.605224609375, 3266.77294921875, 5.816840171813964843, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+404, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2445.109619140625, -2724.551025390625, 3266.32666015625, 0.033223353326320648, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+405, 169751, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2466.69873046875, -2757.638427734375, 3273.33837890625, 4.780231475830078125, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169751 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+406, 169751, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2416.7421875, -2705.21337890625, 3264.241455078125, 4.16581583023071289, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169751 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+407, 169751, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2402.5771484375, -2693.57763671875, 3267.447998046875, 4.911267280578613281, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169751 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+408, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2409.833984375, -2686.820068359375, 3265.247802734375, 4.341908931732177734, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+409, 166908, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2381.656982421875, -2378.41845703125, 3273.161376953125, 5.346814155578613281, 120, 0, 0, 135100, 0, 0, 0, 0, 0, 36839), -- 166908 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 326001 - Summon Creep Area Trigger)
(@CGUID+410, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2346.8525390625, -2704.43408203125, 3259.50146484375, 4.811113357543945312, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+411, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2326.826416015625, -2702.889892578125, 3263.7236328125, 2.378290414810180664, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+412, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2334.361083984375, -2697, 3262.1162109375, 3.296376705169677734, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+413, 162258, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2275.76220703125, -2614.23779296875, 3292.3251953125, 5.936771869659423828, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+414, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2387.710693359375, -2689.1708984375, 3260.51318359375, 5.644536495208740234, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+415, 162767, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2241.30908203125, -2758.3837890625, 3266.324462890625, 5.524352550506591796, 120, 0, 0, 48053, 0, 0, 0, 0, 0, 36839), -- 162767 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+416, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2291.86962890625, -2689.1640625, 3272.936279296875, 4.041920661926269531, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+417, 176024, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2271.66796875, -2690.861328125, 3286.9443359375, 3.749753236770629882, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+418, 173200, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2289.22802734375, -2685.048828125, 3272.89501953125, 4.944247245788574218, 120, 10, 0, 27, 0, 1, 0, 0, 0, 36839), -- Bleak Skitterer (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic) (possible waypoints or random movement)
(@CGUID+419, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2274.138916015625, -2687.451416015625, 3279.314453125, 2.97616124153137207, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt)
(@CGUID+420, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2270.440185546875, -2687.832275390625, 3280.311767578125, 0.678707003593444824, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+421, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2285.45703125, -2678.889404296875, 3283.891357421875, 3.940446853637695312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+422, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2269.36279296875, -2683.517333984375, 3280.35205078125, 0.487572580575942993, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+423, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2280.92626953125, -2664.85791015625, 3277.466796875, 1.004881501197814941, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+424, 170191, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2280.041748046875, -2662.7119140625, 3278.141845703125, 1.405751705169677734, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 170191 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 322272 - Stringy Growth)
(@CGUID+425, 174653, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2274.524658203125, -2667.734619140625, 3279.7900390625, 5.582835674285888671, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+426, 159856, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2227.213623046875, -2678.04345703125, 3306.15234375, 0, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+427, 162259, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2316.041015625, -2653.366455078125, 3285.08642578125, 3.74934244155883789, 120, 10, 0, 5260, 0, 1, 0, 0, 0, 36839), -- 162259 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+428, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2338.015380859375, -2661.585205078125, 3262.833984375, 3.587158441543579101, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+429, 162259, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2300.296875, -2650.583251953125, 3274.550537109375, 1.337518811225891113, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+430, 162259, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2304.170166015625, -2647.18408203125, 3276.601318359375, 3.346794605255126953, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+431, 168196, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2301.314208984375, -2647.838623046875, 3275.78271484375, 0, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168196 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+432, 173200, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2300.354736328125, -2649.456787109375, 3274.798583984375, 5.435788154602050781, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- Bleak Skitterer (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 308853 - Battle Pet Periodic)
(@CGUID+433, 176023, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2351.0517578125, -2662.05078125, 3268.9453125, 2.620229959487915039, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Crawbat (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+434, 167355, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2344.923583984375, -2656.78271484375, 3262.583251953125, 3.635398387908935546, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Valley of a Thousand Legs - Difficulty: 0)
(@CGUID+435, 167356, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2295.947265625, -2956.828369140625, 3238.766357421875, 5.728291988372802734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+436, 167949, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2303.420166015625, -2977.013916015625, 3241.3896484375, 0.491728723049163818, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Valley of a Thousand Legs - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+437, 174650, 2222, 11462, 13406, '0', '0', 0, 0, 0, 2261.970458984375, -2963.895751953125, 3238.63330078125, 3.330562353134155273, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Valley of a Thousand Legs - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+438, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2275.344482421875, -2988.114990234375, 3238.69091796875, 1.141540765762329101, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+439, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2268.432373046875, -2980.173583984375, 3240.0068359375, 2.858007431030273437, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+440, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2373.026123046875, -2860.71875, 3252.84423828125, 5.00153207778930664, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+441, 162259, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2507.462646484375, -2897.456787109375, 3288.635009765625, 2.411278009414672851, 120, 10, 0, 5260, 0, 1, 0, 0, 0, 36839), -- 162259 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+442, 175021, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2501.801025390625, -2880.53271484375, 3277.69189453125, 4.125199317932128906, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0)
(@CGUID+443, 159930, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2410.4619140625, -2930.53466796875, 3271.095458984375, 1.240787029266357421, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 159930 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+444, 160029, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2416.28125, -2927.967041015625, 3271.076904296875, 1.828624963760375976, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 160029 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+445, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2250.864990234375, -2961.110107421875, 3239.28759765625, 5.435960769653320312, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+446, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2277.057373046875, -2999.6962890625, 3239.244384765625, 5.91418313980102539, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+447, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2258.278564453125, -2989.988525390625, 3238.470458984375, 4.997148036956787109, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+448, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2242.60986328125, -2979.719482421875, 3239.431396484375, 2.543834209442138671, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+449, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2260.288330078125, -3022.616455078125, 3242.427734375, 3.90570831298828125, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+450, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2235.666748046875, -2970.0244140625, 3242.24658203125, 2.163031578063964843, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+451, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2246.13037109375, -3029.2080078125, 3241.4873046875, 2.221196889877319335, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+452, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2234.79345703125, -2969.079833984375, 3242.3037109375, 0.235479891300201416, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+453, 176023, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2362.717041015625, -2887.03125, 3260.966796875, 2.518933057785034179, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Crawbat (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+454, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2221.277587890625, -2978.574951171875, 3244.374267578125, 3.101681232452392578, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+455, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2253.678955078125, -3057.30908203125, 3240.8623046875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+456, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2224.68701171875, -2991.8671875, 3238.085693359375, 0.678755462169647216, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+457, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2298.232666015625, -2945.59716796875, 3238.79736328125, 5.113529205322265625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+458, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2188.641845703125, -3001.945068359375, 3240.7333984375, 2.278787136077880859, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+459, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2194.029296875, -2992.046875, 3241.089111328125, 3.640627861022949218, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+460, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2248.87890625, -3071.82421875, 3239.218994140625, 2.889038324356079101, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+461, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2197.074951171875, -2977.960693359375, 3240.48583984375, 5.699197292327880859, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+462, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2192.8525390625, -3016.37841796875, 3241.22607421875, 3.41883397102355957, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+463, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2213.651123046875, -3056.552001953125, 3239.96240234375, 4.997530460357666015, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+464, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2183.3330078125, -3000, 3240.95458984375, 2.661179780960083007, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+465, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2214.217041015625, -3059.236083984375, 3240, 0.944614708423614501, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+466, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2197.97705078125, -3034.663330078125, 3241.101318359375, 5.479703426361083984, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+467, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2208.115234375, -3051.071044921875, 3239.20947265625, 4.464534759521484375, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+468, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2172.9169921875, -3006.25, 3239.45458984375, 2.836849212646484375, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+469, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2288.185791015625, -2950.416748046875, 3238.853271484375, 2.465399503707885742, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+470, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2300.928955078125, -2991.1025390625, 3240.982421875, 1.044954299926757812, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+471, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2262.395751953125, -2979.986083984375, 3239.772216796875, 1.123498201370239257, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+472, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2256.9931640625, -2942.257080078125, 3240.85888671875, 2.17063760757446289, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+473, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2337.0869140625, -2872.27783203125, 3251.70947265625, 6.015443801879882812, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%, 276684 - Churning Dirt) (possible waypoints or random movement)
(@CGUID+474, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2236.520751953125, -2967.43408203125, 3242.2412109375, 4.353937625885009765, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+475, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2300.53466796875, -2946.854248046875, 3238.63720703125, 0.747105121612548828, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+476, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2252.083251953125, -2936.548583984375, 3239.40576171875, 5.896138668060302734, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+477, 159856, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2322.147705078125, -2849.854248046875, 3255.3818359375, 2.684131860733032226, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 159856 (Area: Blighted Scar - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+478, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2164.267333984375, -2976.265625, 3245.195556640625, 2.922295093536376953, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+479, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2294.345458984375, -2949.569580078125, 3238.191162109375, 0.687188208103179931, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+480, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2156.251708984375, -2994.10595703125, 3241.110107421875, 1.021167755126953125, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+481, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2211.838623046875, -3015.84375, 3241.71875, 6.06859588623046875, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+482, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2133.02978515625, -2994.2021484375, 3240.036865234375, 0.007812341209501028, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+483, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2139.4130859375, -3008.14794921875, 3238.85400390625, 6.268449306488037109, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+484, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2130.2744140625, -2995.880126953125, 3239.594482421875, 0.909604787826538085, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+485, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2164.81494140625, -3025.6943359375, 3240.10400390625, 2.48514103889465332, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+486, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2177.3154296875, -3032.4072265625, 3240.203125, 1.326038122177124023, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331108 - Slimy Coating)
(@CGUID+487, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2168.9130859375, -3032.303955078125, 3239.95458984375, 0.226508006453514099, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+488, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2264.257080078125, -2978.029541015625, 3239.7763671875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+489, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2101.8486328125, -3000.363037109375, 3239.49853515625, 6.140740394592285156, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+490, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2127.984130859375, -3028.664794921875, 3239.16943359375, 6.262780189514160156, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+491, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2083.521240234375, -2996.814208984375, 3248.30126953125, 4.174296379089355468, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+492, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2133.375, -3057.19091796875, 3240.577392578125, 4.952961921691894531, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+493, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2166.44091796875, -3036.458984375, 3239.85400390625, 2.73099064826965332, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+494, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2137.354248046875, -3043.298583984375, 3240.1044921875, 0.291701495647430419, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+495, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2171.345458984375, -3036.157958984375, 3240.07763671875, 0.956598937511444091, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+496, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2115.30029296875, -3025.46533203125, 3240.161865234375, 3.130707740783691406, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+497, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2128.197998046875, -3052.296875, 3240.888671875, 1.737714767456054687, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+498, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2133.44970703125, -3059.3994140625, 3240.624755859375, 1.131687879562377929, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+499, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2110.873291015625, -3053.02783203125, 3240.412841796875, 4.217693805694580078, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839); -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)

REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2113.416748046875, -3027.645751953125, 3239.90234375, 2.356740474700927734, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+501, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2172.010498046875, -3037.59716796875, 3240.07763671875, 2.372547864913940429, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+502, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2164.8525390625, -3038.06591796875, 3239.85400390625, 1.680850386619567871, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+503, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2098.151123046875, -3035.0625, 3239.65283203125, 2.714302301406860351, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+504, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2094.564208984375, -2998.43408203125, 3239.970947265625, 4.726877689361572265, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+505, 167948, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2093.423583984375, -2970.994873046875, 3238.87744140625, 5.984332084655761718, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 167948 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+506, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2087.982666015625, -2983.4580078125, 3238.901123046875, 1.728363990783691406, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+507, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2081.91943359375, -2996.375244140625, 3245.97509765625, 1.851055502891540527, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+508, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2255.7275390625, -2939.317626953125, 3240.23193359375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+509, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2150.241943359375, -3070.706787109375, 3240.323486328125, 1.731025099754333496, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+510, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2071.198974609375, -2984.146240234375, 3239.989990234375, 2.507632255554199218, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+511, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2069.41845703125, -2982.640625, 3239.828369140625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+512, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2090.391845703125, -3037.955810546875, 3239.515625, 6.0666351318359375, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+513, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2077.7275390625, -2928.357666015625, 3273.30126953125, 1.718587398529052734, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+514, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2115.927734375, -3057.792236328125, 3240.50146484375, 0.678102552890777587, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+515, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2107.50390625, -3056.50537109375, 3240.50146484375, 2.253128290176391601, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+516, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2149.828125, -3075.260498046875, 3240.909912109375, 2.676600456237792968, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+517, 170456, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2262.435791015625, -3067.65966796875, 3255.12939453125, 5.675691127777099609, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 170456 (Area: Blighted Scar - Difficulty: 0) (Auras: )
(@CGUID+518, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2260.173583984375, -3019.864501953125, 3242.427734375, 4.286366462707519531, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+519, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2198.1181640625, -2922.75341796875, 3245.7080078125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+520, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2183.928955078125, -2950.28466796875, 3244.31884765625, 0.909604787826538085, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+521, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2308.484375, -2946.413330078125, 3242.86181640625, 5.564538955688476562, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+522, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2316.669677734375, -3009.92333984375, 3240.460205078125, 1.521693944931030273, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+523, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2318.368896484375, -2984.875, 3240.849609375, 2.006952285766601562, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+524, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2164.267333984375, -2976.265625, 3245.195556640625, 2.922295093536376953, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+525, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2310.626708984375, -3015.69970703125, 3239.500732421875, 2.795244216918945312, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+526, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2225.61181640625, -2864.444580078125, 3252.784423828125, 5.992196559906005859, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+527, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2258.1875, -3056.25, 3239.93408203125, 0, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 255051 - Vomit)
(@CGUID+528, 167923, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2216.614501953125, -2953.232666015625, 3243.72314453125, 1.156146526336669921, 120, 0, 0, 15662, 0, 0, 0, 0, 0, 36839), -- 167923 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+529, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2255.64208984375, -3075.53125, 3239.357666015625, 1.320932865142822265, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+530, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2229.9990234375, -3079.7431640625, 3240.8837890625, 5.466741561889648437, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+531, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2217.070068359375, -3077.90283203125, 3239.69189453125, 4.402983665466308593, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+532, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2257.776123046875, -3085.3720703125, 3239.698974609375, 6.271467208862304687, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+533, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2192.27587890625, -3077.25732421875, 3238.898681640625, 1.460004448890686035, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+534, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2151.34033203125, -3017.543212890625, 3240.639404296875, 6.206990718841552734, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+535, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2208.07958984375, -3096.345947265625, 3239.7001953125, 2.905607223510742187, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+536, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2259.90185546875, -3089.785400390625, 3241.104736328125, 1.512805819511413574, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+537, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2205.001708984375, -3102.359375, 3239.146240234375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+538, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2233.638427734375, -3103.056396484375, 3239.383544921875, 1.392169117927551269, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+539, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2234.734375, -3103.170166015625, 3239.2900390625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+540, 32638, 0, 11462, 12899, '0', '0', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 32638 (Area: Blighted Scar - Difficulty: 0) (Auras: 61424 - Traveler's Tundra Mammoth)
(@CGUID+541, 32639, 0, 11462, 12899, '0', '0', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 32639 (Area: Blighted Scar - Difficulty: 0) (Auras: 61424 - Traveler's Tundra Mammoth)
(@CGUID+542, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2233.85595703125, -3098.545166015625, 3239.04931640625, 0.687188208103179931, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+543, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2191.19873046875, -3094.342041015625, 3239.023681640625, 0.252798408269882202, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+544, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2255.7275390625, -2939.317626953125, 3240.23193359375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+545, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2241.262939453125, -3109.862548828125, 3238.905517578125, 1.093875885009765625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+546, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2119.537841796875, -3048.809326171875, 3240.550048828125, 3.279463768005371093, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+547, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2120.194091796875, -3046.77490234375, 3240.522216796875, 3.832781076431274414, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+548, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2177.29248046875, -3113.65771484375, 3239.1484375, 2.581751585006713867, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+549, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2141.92138671875, -3088.22119140625, 3240.7919921875, 0.589774370193481445, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+550, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2138.529541015625, -3099.373291015625, 3240.412841796875, 1.222747802734375, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+551, 167923, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2212.329833984375, -3120.694580078125, 3239.1337890625, 2.488151788711547851, 120, 10, 0, 15662, 0, 1, 0, 0, 0, 36839), -- 167923 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+552, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2226.435546875, -3123.442626953125, 3239.22265625, 1.483761787414550781, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+553, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2140.5869140625, -3100.953125, 3240.77734375, 3.105280876159667968, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+554, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2184.95654296875, -3126.916748046875, 3239.04443359375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+555, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2150.173095703125, -3111.359130859375, 3239.96484375, 5.433454513549804687, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+556, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2242.54150390625, -3117.949462890625, 3240.724609375, 2.094790935516357421, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+557, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2148.9326171875, -3126.68505859375, 3238.96484375, 6.082575798034667968, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+558, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2110.497802734375, -3088.68212890625, 3256.625244140625, 3.876600980758666992, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+559, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2183.2197265625, -3138.511474609375, 3239.06884765625, 1.503538489341735839, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+560, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2170.084228515625, -3137.408935546875, 3242.49072265625, 2.329048871994018554, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+561, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2138.189208984375, -3126.916748046875, 3239.04443359375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+562, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2167.1630859375, -3135.64404296875, 3245.7470703125, 1.487192034721374511, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+563, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2104.27880859375, -3101.234375, 3265.625244140625, 0.733617842197418212, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+564, 167948, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2145.986083984375, -3139.942626953125, 3238.92578125, 1.320019245147705078, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 167948 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+565, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2100.28173828125, -3000.286376953125, 3239.659912109375, 1.562728643417358398, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+566, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2098.240478515625, -3104.7568359375, 3270.447265625, 0.734450221061706542, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+567, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2082.288818359375, -3052.233154296875, 3238.9912109375, 5.267334461212158203, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+568, 167923, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2169.994873046875, -3168.46533203125, 3240.438232421875, 0, 120, 0, 0, 15662, 0, 0, 0, 0, 0, 36839), -- 167923 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+569, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2194.572021484375, -3166.096435546875, 3239.09521484375, 5.796428680419921875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+570, 170456, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2274.824951171875, -3270.965576171875, 3292.476806640625, 0.729268252849578857, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 170456 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+571, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2224.47216796875, -3188.953125, 3250.468505859375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+572, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2266.14404296875, -3129.1875, 3250.911376953125, 1.760039925575256347, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+573, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2254.64794921875, -3142.222412109375, 3256.220947265625, 2.764846086502075195, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+574, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2256.454345703125, -3138.969482421875, 3255.987548828125, 3.066456556320190429, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+575, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2250.70849609375, -3141.1494140625, 3256.895751953125, 0.076338611543178558, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+576, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2251.395751953125, -3136.6494140625, 3253.0810546875, 0.947201192378997802, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+577, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2196.01904296875, -3186.954833984375, 3248.923583984375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+578, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2176.231689453125, -3185.244140625, 3248.249755859375, 5.18220376968383789, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+579, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2253.58154296875, -3137.470458984375, 3253.46435546875, 2.046714305877685546, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+580, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2264.54345703125, -3127.9306640625, 3250.322265625, 0.514087557792663574, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+581, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2192.657958984375, -3228.201416015625, 3259.81689453125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+582, 171375, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2439.411376953125, -3565.614501953125, 3313.03955078125, 3.851413726806640625, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 171375 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+583, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2175.1806640625, -3099.157958984375, 3240.004638671875, 0.121904067695140838, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+584, 161613, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2172.40283203125, -3282.388916015625, 3263.61962890625, 3.483080625534057617, 120, 0, 0, 18036, 5013, 0, 0, 0, 0, 36839), -- 161613 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued, 144140 - Vertex Color Lime Green)
(@CGUID+585, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2257.692626953125, -3247.5244140625, 3267.09033203125, 6.278033733367919921, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+586, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2261.944580078125, -3247.907958984375, 3267.98095703125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+587, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2270.85986328125, -3135.983642578125, 3252.819580078125, 1.374982714653015136, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+588, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2213.953125, -3276.7900390625, 3262.978271484375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+589, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2282.915283203125, -3158.492919921875, 3258.421630859375, 2.047543525695800781, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+590, 174813, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2166.947998046875, -3283.9462890625, 3263.61962890625, 5.362988471984863281, 120, 0, 0, 35373, 0, 0, 0, 0, 0, 36839), -- 174813 (Area: Blighted Scar - Difficulty: 0) (Auras: 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+591, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2265.579833984375, -3248.736083984375, 3268.8583984375, 2.795244216918945312, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+592, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2249.868408203125, -3272.7041015625, 3268.448974609375, 4.76907968521118164, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+593, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2290.18408203125, -3165.55322265625, 3260.4169921875, 1.989020705223083496, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+594, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2210.32470703125, -3291.5927734375, 3268.8955078125, 4.137650489807128906, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+595, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2286.881103515625, -3238.66064453125, 3271.643798828125, 3.002952814102172851, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+596, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2213.6005859375, -3299.0205078125, 3269.484375, 1.600444674491882324, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+597, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2197.345458984375, -3343.483154296875, 3271.70458984375, 1.278403639793395996, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+598, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2203.8935546875, -3345.986328125, 3270.571533203125, 4.22120523452758789, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+599, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2261.868408203125, -3295.099365234375, 3288.495361328125, 2.005221366882324218, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+600, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2149.75732421875, -3369.1279296875, 3272.13232421875, 0.79980546236038208, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+601, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2290.29736328125, -3276.1806640625, 3291.237548828125, 3.860924005508422851, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+602, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2285.96337890625, -3277.6982421875, 3291.340576171875, 1.682674884796142578, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+603, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2291.52197265625, -3252.53955078125, 3274.20947265625, 4.636216163635253906, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+604, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2302.20849609375, -3272.390625, 3287.837158203125, 4.141571044921875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+605, 167359, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2303.134033203125, -3275.422119140625, 3287.696044921875, 6.191229820251464843, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+606, 169129, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2307.8974609375, -3269.367431640625, 3292.899658203125, 5.366782188415527343, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+607, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2304.12646484375, -3235.87353515625, 3275.383056640625, 5.668616294860839843, 120, 0, 0, 2255, 0, 0, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+608, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2173.020751953125, -3100.963623046875, 3240.06103515625, 1.630301952362060546, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+609, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2149.99658203125, -3078.104248046875, 3240.705078125, 5.851229190826416015, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+610, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2191.4462890625, -3059.640869140625, 3240.852294921875, 3.576213598251342773, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+611, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2182.84716796875, -3042.486083984375, 3240.20263671875, 5.163601875305175781, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+612, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2170.604248046875, -3043.5, 3240.052001953125, 4.559974193572998046, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+613, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2189.73779296875, -3014.960205078125, 3241.213134765625, 4.729034423828125, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 255051 - Vomit)
(@CGUID+614, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2077.850830078125, -3037.451416015625, 3239.8662109375, 4.286366462707519531, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+615, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2096.22412109375, -3029.281005859375, 3239.85302734375, 3.321134805679321289, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+616, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2070.1806640625, -3036.935791015625, 3239.752685546875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+617, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2161.6494140625, -2984.34033203125, 3244.81689453125, 1.547030210494995117, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+618, 167923, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2141.06298828125, -2985.334228515625, 3244.854248046875, 0.109578929841518402, 120, 10, 0, 15662, 0, 1, 0, 0, 0, 36839), -- 167923 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+619, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2213.651123046875, -3056.552001953125, 3239.96240234375, 4.997530460357666015, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+620, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2058.722412109375, -3041.238037109375, 3238.93017578125, 3.145726203918457031, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+621, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2064.3125, -3010.14404296875, 3240.29248046875, 4.65280771255493164, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+622, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2049.385498046875, -3024.48779296875, 3240.603759765625, 2.115032196044921875, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+623, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2042.927978515625, -3019.707275390625, 3240.296875, 4.165600299835205078, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+624, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2032.143310546875, -3029.166015625, 3242.473876953125, 0, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+625, 167923, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2059.451416015625, -2984.5087890625, 3238.8056640625, 4.547935009002685546, 120, 0, 0, 15662, 0, 0, 0, 0, 0, 36839), -- 167923 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+626, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2054.36767578125, -3009.219482421875, 3239.26806640625, 5.001761913299560546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+627, 160048, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2037.234375, -3002.192626953125, 3239.58740234375, 5.933974742889404296, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 160048 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+628, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2060.8203125, -2985.469482421875, 3239.046875, 0.064489707350730896, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+629, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2040.653076171875, -2997.9755859375, 3239.193359375, 2.199467182159423828, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+630, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2034.1346435546875, -2994.91259765625, 3240.203857421875, 6.064516544342041015, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+631, 160060, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2033.9461669921875, -2994.835205078125, 3240.25146484375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 160060 (Area: Blighted Scar - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+632, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2036.423583984375, -2957.444580078125, 3264.911865234375, 4.801699638366699218, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+633, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2020.079833984375, -3020.6494140625, 3242.06494140625, 1.07444918155670166, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+634, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2012, -3010.595458984375, 3241.92919921875, 5.968111991882324218, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+635, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2026.7135009765625, -2998.95654296875, 3242.020751953125, 4.65280771255493164, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+636, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2014.5660400390625, -3007.4462890625, 3241.363525390625, 0.109169363975524902, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+637, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2039.5225830078125, -2959.835205078125, 3265.1337890625, 4.110213279724121093, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+638, 170456, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1889.2060546875, -3033.55859375, 3320.852783203125, 0.176257118582725524, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+639, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2006.2825927734375, -2960.015625, 3260.36572265625, 0.919285178184509277, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+640, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1972.6307373046875, -2965.84375, 3257.539794921875, 1.553423643112182617, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+641, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2017.0321044921875, -2938.5517578125, 3264.560791015625, 5.787304401397705078, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+642, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1955.7552490234375, -3037.08154296875, 3263.5576171875, 1.509188294410705566, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+643, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2028.923583984375, -2921.307373046875, 3267.95654296875, 5.64362192153930664, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+644, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1906.971923828125, -3006.776611328125, 3268.69384765625, 3.748463630676269531, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+645, 159930, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1807.0728759765625, -3046.170166015625, 3278.00634765625, 0.320696800947189331, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 159930 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+646, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1906.5689697265625, -3041.361572265625, 3269.943603515625, 1.217516303062438964, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+647, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1949.263916015625, -3024.17529296875, 3263.75244140625, 3.040054082870483398, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+648, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1946.0364990234375, -3021.116455078125, 3262.98095703125, 3.350733518600463867, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+649, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1953.6754150390625, -3022.04345703125, 3263.770751953125, 3.610658645629882812, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+650, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1897.445068359375, -3007.7919921875, 3266.658203125, 0.118583835661411285, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+651, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1882.2843017578125, -3014.0234375, 3265.2841796875, 0.739128530025482177, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+652, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1868.488525390625, -3002.898681640625, 3265.619384765625, 5.787618637084960937, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+653, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1888.5362548828125, -2987.4248046875, 3265.705078125, 2.205638408660888671, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+654, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1864.038330078125, -3035.64453125, 3269.0634765625, 4.742083549499511718, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+655, 165034, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1837.423583984375, -3046.927001953125, 3278.929443359375, 0.638934612274169921, 120, 10, 0, 176865, 0, 1, 0, 0, 0, 36839), -- 165034 (Area: Blighted Scar - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+656, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1844.7342529296875, -2990.007568359375, 3264.800048828125, 3.632933616638183593, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+657, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1838.7845458984375, -3004.71337890625, 3264.92138671875, 5.802731990814208984, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+658, 170456, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1759.7615966796875, -3130.471435546875, 3309.643310546875, 1.494728326797485351, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+659, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1834.7701416015625, -3069.8017578125, 3271.81689453125, 2.732695341110229492, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+660, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1846.8143310546875, -3089.49658203125, 3265.336669921875, 6.0666351318359375, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+661, 167356, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1835.0299072265625, -3004.134521484375, 3264.8330078125, 0.028585961088538169, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+662, 165034, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1824.2257080078125, -3080.529541015625, 3267.20703125, 5.589539051055908203, 120, 10, 0, 176865, 0, 1, 0, 0, 0, 36839), -- 165034 (Area: Blighted Scar - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+663, 167935, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1807.967041015625, -3038.1904296875, 3278.006103515625, 5.056905746459960937, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Blighted Scar - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+664, 165032, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1801.1771240234375, -3031.657958984375, 3277.91259765625, 3.774418115615844726, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 165032 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+665, 157226, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1699.7100830078125, -3040.12841796875, 3261.47119140625, 6.038839340209960937, 120, 0, 0, 75150000, 100, 0, 0, 0, 0, 36839), -- 157226 (Area: Blighted Scar - Difficulty: 0) (Auras: 306664 - Mixing Pool, 306713 - Miscible Ooze, 306722 - Viscous Oil)
(@CGUID+666, 170456, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1756.562744140625, -3174.91943359375, 3274.05078125, 5.632388114929199218, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+667, 171112, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1800.1011962890625, -3043.800537109375, 3277.98095703125, 5.819444179534912109, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 171112 (Area: Blighted Scar - Difficulty: 0) (Auras: 333495 - Carry Crate) (possible waypoints or random movement)
(@CGUID+668, 165017, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1788.6163330078125, -3023.819580078125, 3277.91259765625, 2.41428232192993164, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+669, 165034, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1788.2447509765625, -3050.072998046875, 3278.123291015625, 4.404665470123291015, 120, 10, 0, 176865, 0, 1, 0, 0, 0, 36839), -- 165034 (Area: Blighted Scar - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+670, 165049, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1788.1441650390625, -3030.638916015625, 3277.91259765625, 5.736878395080566406, 120, 0, 0, 71190, 100, 0, 0, 0, 0, 36839), -- 165049 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+671, 171112, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1795.390625, -3057.916748046875, 3279.54833984375, 4.385855674743652343, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 171112 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+672, 165017, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1800.2569580078125, -3101.723876953125, 3257.24853515625, 3.466717481613159179, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+673, 157515, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1773.625, -3035.892333984375, 3277.91259765625, 5.956479549407958984, 120, 0, 0, 294775, 0, 0, 0, 0, 0, 36839), -- 157515 (Area: Blighted Scar - Difficulty: 0) (Auras: )
(@CGUID+674, 170456, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1681.69140625, -3011.293701171875, 3335.9384765625, 4.955570697784423828, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: Blighted Scar - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+675, 171135, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1784.1788330078125, -3102.880126953125, 3257.548583984375, 0.033373668789863586, 120, 0, 0, 30060, 0, 0, 0, 0, 0, 36839), -- 171135 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+676, 165017, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1785.767333984375, -3102.51220703125, 3257.451904296875, 3.496729850769042968, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+677, 172141, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1796.5416259765625, -3103.895751953125, 3257.32763671875, 0.769565105438232421, 120, 0, 0, 6012, 5013, 0, 0, 0, 0, 36839), -- 172141 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+678, 167935, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1764.1790771484375, -3096.356201171875, 3258.703369140625, 0.853858768939971923, 120, 10, 0, 2255, 0, 1, 0, 0, 0, 36839), -- 167935 (Area: Plague Watch - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+679, 171112, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1759.055419921875, -3101.93408203125, 3257.7783203125, 2.494405269622802734, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 171112 (Area: Plague Watch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+680, 171112, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1747.58837890625, -3078.75537109375, 3258.481201171875, 5.672302722930908203, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 171112 (Area: Plague Watch - Difficulty: 0) (Auras: 333495 - Carry Crate) (possible waypoints or random movement)
(@CGUID+681, 171112, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1767.9791259765625, -3102.036376953125, 3258.00634765625, 1.723648428916931152, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 171112 (Area: Plague Watch - Difficulty: 0)
(@CGUID+682, 166579, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1729.0225830078125, -3051.069580078125, 3257.59228515625, 4.341775894165039062, 120, 0, 0, 75150, 100, 0, 0, 0, 0, 36839), -- 166579 (Area: Plague Watch - Difficulty: 0) (Auras: 315493 - Cosmetic - Offhand Book)
(@CGUID+683, 171112, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1762.2257080078125, -3100.623291015625, 3257.73291015625, 1.474973678588867187, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 171112 (Area: Plague Watch - Difficulty: 0)
(@CGUID+684, 171130, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1787.310791015625, -3115.795166015625, 3256.377197265625, 2.377449274063110351, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 171130 (Area: Plague Watch - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+685, 171133, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1784.3004150390625, -3119.09033203125, 3257.638427734375, 1.022739648818969726, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 171133 (Area: Plague Watch - Difficulty: 0)
(@CGUID+686, 171112, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1745.7664794921875, -3103.9296875, 3257.897216796875, 2.194466590881347656, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 171112 (Area: Plague Watch - Difficulty: 0) (Auras: 333495 - Carry Crate) (possible waypoints or random movement)
(@CGUID+687, 161841, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1827.298583984375, -3134.9462890625, 3248.497314453125, 4.148271560668945312, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 161841 (Area: Plague Watch - Difficulty: 0)
(@CGUID+688, 157313, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1731.5660400390625, -3060.0400390625, 3257.69775390625, 4.271632194519042968, 120, 0, 0, 75150, 100, 0, 0, 0, 0, 36839), -- 157313 (Area: Plague Watch - Difficulty: 0)
(@CGUID+689, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1762.2447509765625, -3129.7119140625, 3258.542724609375, 2.278612852096557617, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 259900 - Stirring)
(@CGUID+690, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1761.6734619140625, -3123.976806640625, 3258.0283203125, 5.120369434356689453, 120, 10, 0, 7515, 100, 1, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 321236 - Carry Barrel, Orange Goo, With Kneeling) (possible waypoints or random movement)
(@CGUID+691, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1757.9583740234375, -3126.041015625, 3258.0283203125, 0, 120, 10, 0, 7515, 100, 1, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 321241 - Carry Barrel, Empty, With Kneeling End) (possible waypoints or random movement)
(@CGUID+692, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1721.49462890625, -3044.522216796875, 3257.553955078125, 6.024870872497558593, 120, 10, 0, 7515, 100, 1, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 321241 - Carry Barrel, Empty, With Kneeling End) (possible waypoints or random movement)
(@CGUID+693, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1759.032958984375, -3130.47216796875, 3258.542724609375, 0.924469470977783203, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 259900 - Stirring)
(@CGUID+694, 161380, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1710.890625, -3049.194580078125, 3257.47705078125, 3.187958717346191406, 120, 0, 0, 75150, 100, 0, 0, 0, 0, 36839), -- 161380 (Area: Plague Watch - Difficulty: 0) (Auras: 259900 - Stirring)
(@CGUID+695, 165052, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1751.6041259765625, -3118.423583984375, 3257.967529296875, 1.37939453125, 120, 0, 0, 71190, 100, 0, 0, 0, 0, 36839), -- 165052 (Area: Plague Watch - Difficulty: 0) (Auras: 315493 - Cosmetic - Offhand Book)
(@CGUID+696, 159930, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1807.0728759765625, -3046.170166015625, 3278.089599609375, 0.320696800947189331, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 159930 (Area: Plague Watch - Difficulty: 0)
(@CGUID+697, 159930, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1807.1597900390625, -3184.064208984375, 3243.5615234375, 5.830643653869628906, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 159930 (Area: Plague Watch - Difficulty: 0)
(@CGUID+698, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1691.43798828125, -3058.04443359375, 3259.080810546875, 4.417365550994873046, 120, 10, 0, 7515, 100, 1, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 321241 - Carry Barrel, Empty, With Kneeling End) (possible waypoints or random movement)
(@CGUID+699, 167949, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1822.748291015625, -3034.567626953125, 3280.231689453125, 5.163906097412109375, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Plague Watch - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+700, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1698.6639404296875, -3089.8427734375, 3257.44091796875, 2.289539337158203125, 120, 10, 0, 7515, 100, 1, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 321236 - Carry Barrel, Orange Goo, With Kneeling) (possible waypoints or random movement)
(@CGUID+701, 164833, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1728.1632080078125, -3122.29345703125, 3257.17333984375, 0.323131978511810302, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164833 (Area: Plague Watch - Difficulty: 0)
(@CGUID+702, 171133, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1713.5382080078125, -3111.020751953125, 3257.671630859375, 4.942963600158691406, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 171133 (Area: Plague Watch - Difficulty: 0) (Auras: 315493 - Cosmetic - Offhand Book)
(@CGUID+703, 161380, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1697.234375, -3025.40283203125, 3256.9609375, 4.584897041320800781, 120, 0, 0, 75150, 100, 0, 0, 0, 0, 36839), -- 161380 (Area: Plague Watch - Difficulty: 0) (Auras: 259900 - Stirring)
(@CGUID+704, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1689.4444580078125, -3052.6494140625, 3258.805419921875, 4.346553325653076171, 120, 10, 0, 7515, 100, 1, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 321241 - Carry Barrel, Empty, With Kneeling End) (possible waypoints or random movement)
(@CGUID+705, 171129, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1725.1875, -3115.585205078125, 3257.372314453125, 5.84753274917602539, 120, 0, 0, 30060, 0, 0, 0, 0, 0, 36839), -- 171129 (Area: Plague Watch - Difficulty: 0) (Auras: 319502 - Cosmetic - Slime Cauldron)
(@CGUID+706, 171112, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1727, -3121.319580078125, 3257.1396484375, 5.784420490264892578, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 171112 (Area: Plague Watch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+707, 161380, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1684.6024169921875, -3045.154541015625, 3256.58837890625, 5.913051605224609375, 120, 0, 0, 75150, 100, 0, 0, 0, 0, 36839), -- 161380 (Area: Plague Watch - Difficulty: 0) (Auras: 259900 - Stirring)
(@CGUID+708, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1686.5103759765625, -3036.2119140625, 3259.56884765625, 6.065453529357910156, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 321236 - Carry Barrel, Orange Goo, With Kneeling)
(@CGUID+709, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1724.3785400390625, -3117.263916015625, 3257.313720703125, 1.426731586456298828, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0)
(@CGUID+710, 171112, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1718.79345703125, -3111.4150390625, 3257.457275390625, 5.088608741760253906, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 171112 (Area: Plague Watch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+711, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1753.1875, -3135.3125, 3257.9013671875, 1.857510089874267578, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0)
(@CGUID+712, 171217, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1713.6041259765625, -3115.51904296875, 3257.748779296875, 0.533332645893096923, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 171217 (Area: Plague Watch - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+713, 161380, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1702.0052490234375, -3053.6875, 3257.10986328125, 1.127515316009521484, 120, 0, 0, 75150, 100, 0, 0, 0, 0, 36839), -- 161380 (Area: Plague Watch - Difficulty: 0) (Auras: 259900 - Stirring)
(@CGUID+714, 157945, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1713.8697509765625, -3096.302001953125, 3257.758544921875, 0.847951531410217285, 120, 0, 0, 75150, 100, 0, 0, 0, 0, 36839), -- 157945 (Area: Plague Watch - Difficulty: 0)
(@CGUID+715, 165017, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1699.173583984375, -3094.225830078125, 3258.05810546875, 0.039751939475536346, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Plague Watch - Difficulty: 0) (Auras: 259900 - Stirring)
(@CGUID+716, 167359, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1648.193359375, -3018.504150390625, 3261.291259765625, 3.801813602447509765, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: Plague Watch - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+717, 171142, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1589.2852783203125, -3174.4052734375, 3248.850341796875, 1.113476395606994628, 120, 0, 0, 64071, 0, 0, 0, 0, 0, 36839), -- 171142 (Area: Plague Watch - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk)
(@CGUID+718, 165027, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1635.18408203125, -3022.25, 3252.7978515625, 3.029329538345336914, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: Plague Watch - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+719, 170456, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1527.4852294921875, -3145.449462890625, 3295.629638671875, 2.502748966217041015, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+720, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1588.410888671875, -3084.86083984375, 3244.407958984375, 0.20257347822189331, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+721, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1589.3359375, -3040.950927734375, 3247.188232421875, 6.274316310882568359, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+722, 167354, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1607.6343994140625, -3029.865966796875, 3244.641357421875, 3.92792820930480957, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+723, 167354, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1590.296875, -3026.2216796875, 3253.501708984375, 3.517627954483032226, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+724, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1593.5616455078125, -3041.4150390625, 3247.136962890625, 0.286199867725372314, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+725, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1591.098876953125, -3044.340087890625, 3246.31640625, 2.562801361083984375, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+726, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1602.6302490234375, -3095.695068359375, 3244.602783203125, 4.52265787124633789, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+727, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1630.8729248046875, -3137.6923828125, 3237.183349609375, 4.306470870971679687, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+728, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1683.4637451171875, -3159.470947265625, 3240.705322265625, 0.755690217018127441, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+729, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1622.706787109375, -3140.3251953125, 3237.538818359375, 0.231998622417449951, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+730, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1640.0904541015625, -3146.751953125, 3239.5244140625, 3.634251832962036132, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+731, 160417, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1805.28271484375, -3183.5537109375, 3243.701171875, 1.288924694061279296, 120, 10, 0, 3758, 0, 1, 0, 0, 0, 36839), -- 160417 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+732, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1756.7005615234375, -3215.709228515625, 3223.51318359375, 5.655106544494628906, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+733, 160418, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1798.5885009765625, -3189.4150390625, 3244.12060546875, 5.984707832336425781, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 160418 (Area: House of Plagues - Difficulty: 0) (Auras: 144140 - Vertex Color Lime Green)
(@CGUID+734, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1767.114501953125, -3211.641845703125, 3224.161865234375, 1.626511573791503906, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+735, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1767.241943359375, -3205.94091796875, 3225.2841796875, 0.278565168380737304, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+736, 160253, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1826.640625, -3172.7587890625, 3243.61376953125, 2.65969252586364746, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 160253 (Area: House of Plagues - Difficulty: 0)
(@CGUID+737, 170456, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1574.2847900390625, -3204.04345703125, 3280.13671875, 5.875169754028320312, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 170456 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+738, 167949, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1817.7947998046875, -3035.461669921875, 3281.202880859375, 2.530247211456298828, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 167949 (Area: House of Plagues - Difficulty: 0) (Auras: 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+739, 156558, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1701.0711669921875, -3092.757080078125, 3258.06298828125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: House of Plagues - Difficulty: 0) (Auras: 292177 - Turn In Circle Visual)
(@CGUID+740, 165145, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1700.967041015625, -3092.8369140625, 3262.252685546875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 165145 (Area: House of Plagues - Difficulty: 0) (Auras: 321653 - White Arrow)
(@CGUID+741, 157317, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1700.9896240234375, -3092.73095703125, 3257.6103515625, 0.616861581802368164, 120, 0, 0, 179, 100, 0, 0, 0, 0, 36839), -- 157317 (Area: House of Plagues - Difficulty: 0) (Auras: 306781 - Mixing Pool)
(@CGUID+742, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1644.9556884765625, -3171.332275390625, 3236.667724609375, 5.977899551391601562, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+743, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1625.2977294921875, -3050.510498046875, 3244.6884765625, 0.329116702079772949, 120, 10, 0, 8543, 0, 1, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+744, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1588.8062744140625, -3110.96142578125, 3243.8388671875, 0.355426669120788574, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+745, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1602.5255126953125, -3124.133544921875, 3241.29296875, 1.128979325294494628, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+746, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1587.78125, -3033.040283203125, 3250.5400390625, 4.423467636108398437, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+747, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1609.031005859375, -3144.215087890625, 3243.4873046875, 4.499256134033203125, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+748, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1590.89990234375, -3151.870849609375, 3248.6728515625, 6.012150287628173828, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+749, 171599, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1561.30908203125, -3073.87158203125, 3248.783203125, 4.649475574493408203, 120, 0, 0, 9008, 0, 0, 0, 0, 0, 36839); -- 171599 (Area: House of Plagues - Difficulty: 0)

REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+750, 167359, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1580.8892822265625, -3141.034912109375, 3251.755615234375, 6.146927356719970703, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+751, 167359, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1577.2989501953125, -3135.599365234375, 3252.79541015625, 0.852567911148071289, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+752, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1571.53466796875, -3115.477783203125, 3249.149658203125, 5.070497512817382812, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+753, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1559.5191650390625, -3050.03125, 3248.67724609375, 4.736340999603271484, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+754, 158406, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1633.326416015625, -3286.619873046875, 3237.0576171875, 2.570510149002075195, 120, 0, 0, 471640, 0, 0, 0, 0, 0, 36839), -- 158406 (Area: House of Plagues - Difficulty: 0) (Auras: 308850 - Vile Emission)
(@CGUID+755, 167359, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1574.614990234375, -3140.791015625, 3253.070556640625, 2.842900991439819335, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+756, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1575.10009765625, -3157.967529296875, 3248.6728515625, 6.17801523208618164, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+757, 165015, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1547.4566650390625, -3259.824951171875, 3260.06201171875, 1.041460871696472167, 120, 10, 0, 21357, 0, 1, 0, 0, 0, 36839), -- 165015 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+758, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1553.602783203125, -3130.378662109375, 3248.778076171875, 2.78506016731262207, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+759, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1558.1954345703125, -3149.864013671875, 3248.765869140625, 2.394150972366333007, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+760, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1524.57421875, -3093.547607421875, 3252.61376953125, 5.500549793243408203, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+761, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1585.86279296875, -3166.702880859375, 3248.701904296875, 0.638087153434753417, 120, 10, 0, 8543, 0, 1, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+762, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1529.117431640625, -3122.437255859375, 3248.787841796875, 6.110492706298828125, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+763, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1523.7037353515625, -3121.404052734375, 3248.34619140625, 0.27458229660987854, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+764, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1577.927978515625, -3179.40380859375, 3248.725341796875, 1.709882974624633789, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+765, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1613.3115234375, -3185.703125, 3243.301025390625, 5.8671417236328125, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+766, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1629.1041259765625, -3187.750732421875, 3241.205810546875, 4.908060073852539062, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+767, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1526.2484130859375, -3132.171142578125, 3248.682861328125, 0.114467829465866088, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+768, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1551.079833984375, -3175.190185546875, 3248.532958984375, 4.039174556732177734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+769, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1526.885498046875, -3148.400390625, 3248.7236328125, 5.372778892517089843, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+770, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1516.97216796875, -3129.978515625, 3248.392578125, 2.645994901657104492, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+771, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1511.5338134765625, -3124.809326171875, 3248.267578125, 3.229687690734863281, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+772, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1508.951416015625, -3066.548583984375, 3256.89404296875, 0.139134004712104797, 120, 10, 0, 8543, 0, 1, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+773, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1594.7730712890625, -3191.511474609375, 3244.9150390625, 4.843852996826171875, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+774, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1539.4749755859375, -3175.12451171875, 3248.350341796875, 6.150576114654541015, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+775, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1522.829345703125, -3158.957275390625, 3248.7236328125, 0.776473283767700195, 120, 0, 0, 8543, 0, 0, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+776, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1493.9132080078125, -3097.71533203125, 3256.952392578125, 0.630457520484924316, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+777, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1512.6251220703125, -3175.384521484375, 3248.728515625, 0.844528734683990478, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+778, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1557.072265625, -3188.634521484375, 3248.124755859375, 1.892172455787658691, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+779, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1504.0728759765625, -3158.901123046875, 3248.7236328125, 0.367031902074813842, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+780, 167359, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1496.7156982421875, -3169.961669921875, 3252.571533203125, 5.015942573547363281, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+781, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1520.8067626953125, -3191.569580078125, 3252.896240234375, 1.001242756843566894, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+782, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1563.8583984375, -3202.693359375, 3248.77978515625, 0.825735032558441162, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+783, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1558.266845703125, -3203.1728515625, 3248.848388671875, 5.723113059997558593, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+784, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1553.5823974609375, -3214.37646484375, 3252.482666015625, 3.789783239364624023, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+785, 164758, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1453.9461669921875, -3039.4462890625, 3264.14453125, 1.986567378044128417, 120, 0, 0, 2349, 0, 0, 0, 0, 0, 36839), -- 164758 (Area: House of Plagues - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+786, 164758, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1451.90283203125, -3042.583251953125, 3264.14453125, 2.204747915267944335, 120, 0, 0, 2349, 0, 0, 0, 0, 0, 36839), -- 164758 (Area: House of Plagues - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+787, 164758, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1404.8385009765625, -3181.03125, 3294.007568359375, 4.732324123382568359, 120, 0, 0, 2349, 0, 0, 0, 0, 0, 36839), -- 164758 (Area: House of Plagues - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+788, 167354, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1484.838134765625, -3241.58056640625, 3260.867919921875, 3.784944057464599609, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+789, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1506.306884765625, -3244.9287109375, 3260.55810546875, 0.526175498962402343, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+790, 171415, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1592.6619873046875, -3206.953125, 3243.641845703125, 2.770441293716430664, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 171415 (Area: House of Plagues - Difficulty: 0) (Auras: 334479 - On Spawn Slime Perimeter (DNT)) (possible waypoints or random movement)
(@CGUID+791, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1630.4600830078125, -3112.37158203125, 3248.642578125, 2.216094493865966796, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+792, 164758, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1439.5364990234375, -3037.12158203125, 3264.14453125, 1.37378096580505371, 120, 0, 0, 2349, 0, 0, 0, 0, 0, 36839), -- 164758 (Area: House of Plagues - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+793, 164758, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1454.3819580078125, -3011.87158203125, 3264.592529296875, 3.95720529556274414, 120, 0, 0, 2349, 0, 0, 0, 0, 0, 36839), -- 164758 (Area: House of Plagues - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+794, 164758, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1452.107666015625, -3009.67529296875, 3264.14453125, 3.95720529556274414, 120, 0, 0, 2349, 0, 0, 0, 0, 0, 36839), -- 164758 (Area: House of Plagues - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+795, 164759, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1437.079833984375, -3019.960205078125, 3264.14501953125, 5.757536888122558593, 120, 0, 0, 21357, 2041, 0, 0, 0, 0, 36839), -- 164759 (Area: House of Plagues - Difficulty: 0) (Auras: 203315 - Plagued)
(@CGUID+796, 164758, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1435.234375, -3033.967041015625, 3264.14453125, 0.989596545696258544, 120, 0, 0, 2349, 0, 0, 0, 0, 0, 36839), -- 164758 (Area: House of Plagues - Difficulty: 0) (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+797, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1621.3638916015625, -3121.69482421875, 3244.440185546875, 1.356219172477722167, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+798, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1638.3189697265625, -3151.311279296875, 3237.631591796875, 0.160814836621284484, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+799, 167359, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1563.0462646484375, -3239.84228515625, 3261.811767578125, 2.681393384933471679, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+800, 167359, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1577.90087890625, -3246.386962890625, 3254.512939453125, 3.766687870025634765, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+801, 167359, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1582.1651611328125, -3249.132080078125, 3251.4697265625, 5.77738809585571289, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+802, 165015, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1568.1171875, -3353.20751953125, 3220.24267578125, 0.833046913146972656, 120, 10, 0, 21357, 0, 1, 0, 0, 0, 36839), -- 165015 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+803, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1645.640869140625, -3219.46484375, 3217.1923828125, 2.712361335754394531, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+804, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1666.971435546875, -3151.5673828125, 3241.269287109375, 5.35713958740234375, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+805, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1649.531494140625, -3223.323974609375, 3214.8779296875, 2.135871648788452148, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+806, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1559.9495849609375, -3292.66650390625, 3249.062255859375, 5.452897071838378906, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+807, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1526.90234375, -3265.365478515625, 3259.92578125, 2.724590301513671875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0)
(@CGUID+808, 165015, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1454.1910400390625, -3355.814208984375, 3261.868408203125, 2.883165836334228515, 120, 10, 0, 21357, 0, 1, 0, 0, 0, 36839), -- 165015 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+809, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1515.547119140625, -3276.1318359375, 3260.22802734375, 2.689656734466552734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+810, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1644.763916015625, -3031.260498046875, 3251.9013671875, 4.97487640380859375, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+811, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1617.9010009765625, -3054.407958984375, 3244.7373046875, 3.212484359741210937, 120, 0, 0, 8543, 0, 0, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+812, 166438, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1558.609375, -3206.671875, 3248.817626953125, 1.969342231750488281, 120, 10, 0, 21357, 0, 1, 0, 0, 0, 36839), -- 166438 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+813, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1586.5501708984375, -3037.126953125, 3249.452880859375, 4.822938442230224609, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+814, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1558.8922119140625, -3059.22998046875, 3248.67724609375, 5.049088001251220703, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+815, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1556.6859130859375, -3104.713623046875, 3248.778076171875, 1.838884472846984863, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+816, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1531.1873779296875, -3120.63525390625, 3249.0341796875, 5.154963493347167968, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+817, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1553.3524169921875, -3131.015625, 3248.73876953125, 2.249707698822021484, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+818, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1572.576416015625, -3156.201416015625, 3248.73876953125, 5.145524501800537109, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+819, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1595.935791015625, -3189.701416015625, 3244.8935546875, 3.848297119140625, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+820, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1554.1669921875, -3198.958984375, 3249.2265625, 3.605802774429321289, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+821, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1551.7955322265625, -3213.9716796875, 3253.217041015625, 4.100543022155761718, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+822, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1604.666748046875, -3212.35888671875, 3241.67919921875, 4.109680652618408203, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+823, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1596.3697509765625, -3217.989501953125, 3241.98681640625, 5.072226524353027343, 120, 10, 0, 8543, 0, 1, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+824, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1583.7017822265625, -3234.093017578125, 3245.9501953125, 5.659632682800292968, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+825, 157226, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1699.7100830078125, -3040.12841796875, 3261.47119140625, 6.038839340209960937, 120, 0, 0, 75150000, 100, 0, 0, 0, 0, 36839), -- 157226 (Area: House of Plagues - Difficulty: 0) (Auras: 306666 - Mixing Pool)
(@CGUID+826, 171142, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1587.5347900390625, -3051.322998046875, 3244.84619140625, 5.74100494384765625, 120, 0, 0, 64071, 0, 0, 0, 0, 0, 36839), -- 171142 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk)
(@CGUID+827, 157294, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1689.7763671875, -3053.3876953125, 3258.722412109375, 4.534353256225585937, 120, 0, 0, 185614, 0, 0, 0, 0, 0, 36839), -- 157294 (Area: House of Plagues - Difficulty: 0) (Auras: 340292 - Blood Clone Cosmetic)
(@CGUID+828, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1518.3782958984375, -3284.753662109375, 3260.093994140625, 1.349052786827087402, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+829, 175784, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1507.138916015625, -3272.901123046875, 3260.587890625, 1.530652880668640136, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- Gelatinous (Area: House of Plagues - Difficulty: 0)
(@CGUID+830, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1561.6588134765625, -3302.8212890625, 3247.20068359375, 4.1962738037109375, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+831, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1589.1771240234375, -3164.189208984375, 3248.73876953125, 3.783303737640380859, 120, 10, 0, 8543, 0, 1, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+832, 165015, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1501.078125, -3158.151123046875, 3248.73876953125, 4.086271286010742187, 120, 10, 0, 21357, 0, 1, 0, 0, 0, 36839), -- 165015 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+833, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1613.2586669921875, -3150.66845703125, 3243.187744140625, 0.429835796356201171, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+834, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1631.8958740234375, -3109.661376953125, 3248.730712890625, 5.288469791412353515, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+835, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1663.607666015625, -3138.34033203125, 3243.67626953125, 2.970677614212036132, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+836, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1637.488037109375, -3156.46728515625, 3236.673828125, 5.467016220092773437, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+837, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1531.9400634765625, -3100.882568359375, 3249.34130859375, 5.493372440338134765, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+838, 165014, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1529.404541015625, -3152.498291015625, 3248.7236328125, 0.776473283767700195, 120, 10, 0, 8543, 0, 1, 0, 0, 0, 36839), -- 165014 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+839, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1519.28857421875, -3125.327880859375, 3248.267578125, 0.578385353088378906, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+840, 165015, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1472.9305419921875, -3104.248291015625, 3257.30322265625, 5.712100982666015625, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 165015 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk)
(@CGUID+841, 166438, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1626.9132080078125, -3190.51220703125, 3241.228515625, 0.338676482439041137, 120, 10, 0, 21357, 0, 1, 0, 0, 0, 36839), -- 166438 (Area: House of Plagues - Difficulty: 0) (Auras: 282999 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+842, 165027, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1687.224609375, -3156.15576171875, 3241.622314453125, 2.499857902526855468, 120, 10, 0, 7119, 0, 1, 0, 0, 0, 36839), -- 165027 (Area: House of Plagues - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+843, 164482, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1818.48095703125, -3196.27783203125, 3246.8974609375, 1.952665925025939941, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0)
(@CGUID+844, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1861.458984375, -3164.583984375, 3224.83251953125, 3.141592741012573242, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0)
(@CGUID+845, 160419, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1824.6129150390625, -3193.079833984375, 3243.701171875, 4.045978546142578125, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 160419 (Area: House of Plagues - Difficulty: 0)
(@CGUID+846, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1847.9169921875, -3189.583984375, 3217.1435546875, 4.94639444351196289, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0)
(@CGUID+847, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1856.5166015625, -3175.4453125, 3222.159912109375, 0.608726143836975097, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0)
(@CGUID+848, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1869.06884765625, -3177.701171875, 3217.466796875, 2.932840824127197265, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0)
(@CGUID+849, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1874.10107421875, -3165.93994140625, 3218.19189453125, 2.581751585006713867, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0)
(@CGUID+850, 167358, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1858.06787109375, -3183.1015625, 3217.5029296875, 1.418332576751708984, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167358 (Area: House of Plagues - Difficulty: 0)
(@CGUID+851, 170443, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1800.6632080078125, -3188.427001953125, 3245.832763671875, 3.48475050926208496, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 332174 - Anima Catalyst)
(@CGUID+852, 170443, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1827.0347900390625, -3178.625, 3245.86181640625, 3.48475050926208496, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 332174 - Anima Catalyst)
(@CGUID+853, 164482, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1818.48095703125, -3196.27783203125, 3246.980712890625, 1.952665925025939941, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 319972 - Diffusing Flower)
(@CGUID+854, 170751, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1825.3333740234375, -3186.814208984375, 3243.704833984375, 1.930944681167602539, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 333012 - Plague Cloud)
(@CGUID+855, 170751, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1808.0625, -3168.260498046875, 3244.025146484375, 1.930944681167602539, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 333012 - Plague Cloud)
(@CGUID+856, 170751, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1819.8211669921875, -3173.671875, 3243.704833984375, 1.930944681167602539, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 333012 - Plague Cloud)
(@CGUID+857, 170757, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1862.8629150390625, -3222.86279296875, 3209.0703125, 2.422795295715332031, 120, 0, 0, 498330, 0, 0, 0, 0, 0, 36839), -- 170757 (Area: House of Plagues - Difficulty: 0) (Auras: 333016 - Stradama's Aura)
(@CGUID+858, 163958, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1823.5694580078125, -3213.302001953125, 3226.069580078125, 1.930944681167602539, 120, 0, 0, 526050, 0, 0, 0, 0, 0, 36839), -- 163958 (Area: House of Plagues - Difficulty: 0) (Auras: 333016 - Stradama's Aura)
(@CGUID+859, 170751, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1803.1961669921875, -3181.53466796875, 3243.70458984375, 1.930944681167602539, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 333012 - Plague Cloud)
(@CGUID+860, 170757, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1810.0694580078125, -3249.015625, 3209.18212890625, 1.709232807159423828, 120, 0, 0, 498330, 0, 0, 0, 0, 0, 36839), -- 170757 (Area: House of Plagues - Difficulty: 0) (Auras: 333016 - Stradama's Aura)
(@CGUID+861, 170751, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1805.5972900390625, -3197.59033203125, 3243.810546875, 1.930944681167602539, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 333012 - Plague Cloud)
(@CGUID+862, 170751, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1833.4461669921875, -3182.223876953125, 3243.863037109375, 1.930944681167602539, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: House of Plagues - Difficulty: 0) (Auras: 333012 - Plague Cloud)
(@CGUID+863, 159930, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1807.1597900390625, -3184.064208984375, 3243.644775390625, 5.830643653869628906, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 159930 (Area: House of Plagues - Difficulty: 0)
(@CGUID+864, 167949, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1834.013916015625, -3032.65625, 3276.644287109375, 1.361554980278015136, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: House of Plagues - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+865, 167949, 2222, 11462, 12775, '0', '0', 0, 0, 0, 1853.001708984375, -3057.451416015625, 3281.22509765625, 3.012193918228149414, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: House of Plagues - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+866, 167949, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1863.6302490234375, -3008.729248046875, 3266.489013671875, 5.440202713012695312, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Plague Watch - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+867, 167949, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1954.51220703125, -3012.338623046875, 3263.332763671875, 1.372047305107116699, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Plague Watch - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+868, 167949, 2222, 11462, 13305, '0', '0', 0, 0, 0, 1954.423583984375, -3010.498291015625, 3262.970703125, 6.235248565673828125, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Plague Watch - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+869, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1978.27783203125, -3027.598876953125, 3258.4423828125, 4.025014400482177734, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+870, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1975.904541015625, -3025.482666015625, 3259.21630859375, 5.644423961639404296, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+871, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1991.404541015625, -2981.3681640625, 3259.562255859375, 5.917014598846435546, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+872, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1993.454833984375, -2980.29345703125, 3259.42626953125, 5.57669830322265625, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+873, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1976.388916015625, -3026.880126953125, 3259.0087890625, 4.730731010437011718, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+874, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2010.173583984375, -3015.016845703125, 3243.883056640625, 3.809524297714233398, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+875, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2037.3072509765625, -2959.87158203125, 3264.802001953125, 1.484757542610168457, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+876, 174650, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2055.970458984375, -3040.5595703125, 3238.942138671875, 2.684825897216796875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174650 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+877, 167923, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2054.96533203125, -3042.98779296875, 3238.842529296875, 0, 120, 0, 0, 15662, 0, 0, 0, 0, 0, 36839), -- 167923 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+878, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2038.1016845703125, -2937.846435546875, 3266.62109375, 2.289466381072998046, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague)
(@CGUID+879, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2031.74658203125, -2920.70654296875, 3268.35595703125, 5.131856918334960937, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+880, 167354, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1967.9481201171875, -2869.7275390625, 3345.224365234375, 1.431666970252990722, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+881, 167354, 2222, 11462, 12899, '0', '0', 0, 0, 0, 1966.99951171875, -2866.900390625, 3344.815673828125, 2.977666854858398437, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+882, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2104.71533203125, -2903.600830078125, 3285.933349609375, 4.038171768188476562, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+883, 167949, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2106.609375, -2904.486083984375, 3285.92041015625, 2.49511122703552246, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 167949 (Area: Blighted Scar - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+884, 161388, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2065.103271484375, -2810.739013671875, 3315.859375, 1.952545881271362304, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+885, 161388, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2066.901611328125, -2809.56494140625, 3315.758056640625, 2.552175045013427734, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+886, 161396, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2027.986083984375, -2811.64404296875, 3316.62353515625, 2.024199962615966796, 120, 0, 0, 52605, 0, 0, 0, 0, 0, 36839), -- 161396 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+887, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2066.774658203125, -2790.078369140625, 3312.772705078125, 5.415962696075439453, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0)
(@CGUID+888, 167355, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2060.0380859375, -2777.974609375, 3312.75341796875, 4.597599029541015625, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Blighted Scar - Difficulty: 0)
(@CGUID+889, 161388, 2222, 11462, 12899, '0', '0', 0, 0, 0, 2062.62255859375, -2766.167724609375, 3312.970458984375, 1.326158046722412109, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Blighted Scar - Difficulty: 0)
(@CGUID+890, 161390, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2068.066650390625, -2731.755859375, 3314.538330078125, 1.415920138359069824, 120, 0, 0, 11273, 0, 0, 0, 0, 0, 36839), -- 161390 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+891, 161395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2065.1787109375, -2731.761962890625, 3313.521484375, 1.267480731010437011, 120, 0, 0, 15030, 0, 0, 0, 0, 0, 36839), -- 161395 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 330574 - Deathbolt Rift)
(@CGUID+892, 161395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2006.1087646484375, -2753.492919921875, 3317.19091796875, 2.815865278244018554, 120, 0, 0, 15030, 0, 0, 0, 0, 0, 36839), -- 161395 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 330574 - Deathbolt Rift)
(@CGUID+893, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2002.66015625, -2752.328125, 3318.397705078125, 5.95839691162109375, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+894, 161390, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2069.798828125, -2725.21826171875, 3313.07470703125, 1.513374209403991699, 120, 0, 0, 11273, 0, 0, 0, 0, 0, 36839), -- 161390 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+895, 161390, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2030.2569580078125, -2724.458740234375, 3312.975341796875, 1.416225910186767578, 120, 0, 0, 11273, 0, 0, 0, 0, 0, 36839), -- 161390 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+896, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1974.342041015625, -2762.1806640625, 3331.531005859375, 6.225484371185302734, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+897, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2010.2742919921875, -2708.786376953125, 3319.810302734375, 3.27124190330505371, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+898, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1980.671875, -2755.11279296875, 3327.947021484375, 6.225484371185302734, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+899, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2024.6781005859375, -2723.032958984375, 3313.2490234375, 4.518313407897949218, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+900, 161395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2075.572998046875, -2670.79345703125, 3311.137451171875, 0.519146144390106201, 120, 0, 0, 15030, 0, 0, 0, 0, 0, 36839), -- 161395 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+901, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2059.896484375, -2661.458984375, 3311.728271484375, 6.104678630828857421, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+902, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2089.614501953125, -2680.34375, 3312.74951171875, 1.968824028968811035, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+903, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2050.72998046875, -2658.44921875, 3314.855224609375, 1.39002084732055664, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+904, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2051.326171875, -2655.187255859375, 3313.290283203125, 4.531613826751708984, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+905, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2040.3275146484375, -2639.81982421875, 3321.17822265625, 3.403677225112915039, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+906, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2052.02392578125, -2652.098388671875, 3313.8056640625, 4.489861011505126953, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+907, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2041.6669921875, -2631.25, 3324.262939453125, 1.088188886642456054, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+908, 161395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2004.9949951171875, -2626.58935546875, 3343.773681640625, 2.679440021514892578, 120, 0, 0, 15030, 0, 0, 0, 0, 0, 36839), -- 161395 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+909, 161388, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2002.943603515625, -2626.61181640625, 3343.773681640625, 5.31947946548461914, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 161388 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+910, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2004.6875, -2620.833984375, 3343.305908203125, 5.173602104187011718, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+911, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2090.81787109375, -2612.9013671875, 3315.333740234375, 0.997682869434356689, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+912, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1951.703369140625, -2610.73046875, 3347.422119140625, 5.639761924743652343, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+913, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2085.085205078125, -2599.454833984375, 3318.969970703125, 2.547672510147094726, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+914, 170693, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1971.1597900390625, -2547.710205078125, 3371.9970703125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- Invisible Stalker (Area: Bleak Redoubt - Difficulty: 0) (Auras: 318119 - Necromancy Ring)
(@CGUID+915, 170806, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1977.6944580078125, -2550.630126953125, 3372.00439453125, 2.908559560775756835, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 170806 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+916, 170807, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1977.704833984375, -2548.036376953125, 3371.997802734375, 3.337609767913818359, 120, 0, 0, 30060, 0, 0, 0, 0, 0, 36839), -- 170807 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 333140 - Cosmetic - Slime Party Hat and Cake)
(@CGUID+917, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2036.015625, -2540.46875, 3343.70068359375, 5.941868305206298828, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+918, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2036.860595703125, -2568.11181640625, 3345.504638671875, 2.35553598403930664, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+919, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2046.8802490234375, -2551.4375, 3338.6826171875, 0.290997207164764404, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+920, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2033.8680419921875, -2529.473876953125, 3343.4169921875, 3.838748455047607421, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+921, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2033.232666015625, -2535.677001953125, 3343.40380859375, 5.856778144836425781, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+922, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2066.578125, -2556.217041015625, 3328.515625, 1.404675841331481933, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+923, 164915, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1870.375, -2568.9775390625, 3388.121826171875, 3.500125646591186523, 120, 0, 0, 67550, 0, 0, 0, 0, 0, 36839), -- 164915 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+924, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2066.214111328125, -2543.937744140625, 3328.61962890625, 0.605192542076110839, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+925, 170806, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1977.6944580078125, -2550.630126953125, 3372.087646484375, 2.908559560775756835, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 170806 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+926, 167273, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1988.6754150390625, -2450.92529296875, 3343.4091796875, 1.939600944519042968, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167273 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+927, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2071.307373046875, -2536.543212890625, 3327.41552734375, 5.340929031372070312, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+928, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2008.9097900390625, -2454.111083984375, 3342.72607421875, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343329 - [DNT] - Flavor 2)
(@CGUID+929, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2068.954833984375, -2542.041748046875, 3327.090576171875, 5.60605621337890625, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+930, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2071.089111328125, -2539.702392578125, 3326.124755859375, 3.972771406173706054, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+931, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1988.955810546875, -2448.181884765625, 3343.30908203125, 5.586359024047851562, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+932, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2054.57470703125, -2479.510986328125, 3331.7333984375, 4.998373031616210937, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+933, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2056.755859375, -2482.667724609375, 3335.82275390625, 4.498919963836669921, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+934, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1956.694580078125, -2452.189208984375, 3343.51025390625, 4.838657855987548828, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+935, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2046.4375, -2524.717041015625, 3347.024169921875, 0.770157396793365478, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+936, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2068.179443359375, -2552.29296875, 3327.641845703125, 1.580917119979858398, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+937, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2071.92333984375, -2557.20361328125, 3327.2978515625, 3.165802001953125, 120, 10, 0, 8267, 0, 1, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts) (possible waypoints or random movement)
(@CGUID+938, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2038.861083984375, -2541.3525390625, 3342.942138671875, 2.93044447898864746, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+939, 166423, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1867.32958984375, -2549.5771484375, 3555.459716796875, 4.501973628997802734, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 166423 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+940, 161994, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1869.03125, -2528.048583984375, 3388.121826171875, 5.37213897705078125, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161994 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+941, 175021, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1952.42236328125, -2443.34033203125, 3341.397705078125, 2.49887251853942871, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+942, 170806, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1977.6944580078125, -2550.630126953125, 3372.087646484375, 2.908559560775756835, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 170806 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+943, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2046.796875, -2470.375, 3327.78466796875, 0.275197863578796386, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+944, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2063.34033203125, -2489.50341796875, 3340.238037109375, 0.545510351657867431, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+945, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2072.80908203125, -2506.33154296875, 3342.943359375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+946, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2041.017333984375, -2520.46533203125, 3347.34423828125, 0.057472597807645797, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+947, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2011.501708984375, -2631.229248046875, 3340.491943359375, 3.397875785827636718, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+948, 161399, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2079.942626953125, -2541.3369140625, 3323.52001953125, 3.28699803352355957, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 161399 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+949, 32638, 0, 11462, 11466, '0', '0', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 32638 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 61424 - Traveler's Tundra Mammoth)
(@CGUID+950, 32639, 0, 11462, 11466, '0', '0', 0, 0, 0, 0, 0, 0, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 32639 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 61424 - Traveler's Tundra Mammoth)
(@CGUID+951, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2046.796875, -2470.375, 3327.677001953125, 1.028216719627380371, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+952, 161881, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2080.0078125, -2558.740478515625, 3322.660400390625, 2.951048851013183593, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161881 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+953, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1973.314453125, -2448.50830078125, 3344.875732421875, 4.954051017761230468, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+954, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1938.3382568359375, -2456.088623046875, 3345.963623046875, 5.315279483795166015, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+955, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2078.9306640625, -2544.927490234375, 3322.378662109375, 3.600763797760009765, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+956, 170806, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1977.6944580078125, -2550.630126953125, 3372.087646484375, 2.908559560775756835, 120, 0, 0, 47165, 5751, 0, 0, 0, 0, 36839), -- 170806 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+957, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2066.578125, -2556.217041015625, 3328.455322265625, 1.119107007980346679, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+958, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2009.5242919921875, -2445.46533203125, 3337.8564453125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343329 - [DNT] - Flavor 2)
(@CGUID+959, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1987.037109375, -2439.201171875, 3340.00341796875, 1.804403662681579589, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+960, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1996.98095703125, -2440.697998046875, 3343.140625, 3.439143657684326171, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+961, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2005.736572265625, -2442.238525390625, 3337.716796875, 3.725681304931640625, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+962, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1993.5247802734375, -2441.89453125, 3343.406982421875, 0.333286762237548828, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+963, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1951.0775146484375, -2427.09326171875, 3335.97509765625, 4.332607269287109375, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+964, 162259, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2022.620849609375, -2437.443359375, 3341.72265625, 3.156125307083129882, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+965, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1995.557373046875, -2426.105712890625, 3330.57421875, 4.799423694610595703, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+966, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2004.1669921875, -2438.541015625, 3338.05029296875, 4.873267173767089843, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+967, 169634, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2030.3819580078125, -2414.927001953125, 3318.5478515625, 1.731662392616271972, 120, 0, 0, 20265, 0, 0, 0, 0, 0, 36839), -- 169634 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+968, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2067.900146484375, -2486.725830078125, 3338.0625, 2.93107461929321289, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+969, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2050.261474609375, -2469.578857421875, 3326.77880859375, 3.367465019226074218, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+970, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1996.064208984375, -2394.59033203125, 3329.30517578125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+971, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2051.522705078125, -2459.484375, 3324.802001953125, 4.302974224090576171, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 314093 - Useful Parts)
(@CGUID+972, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2020.0972900390625, -2447.76904296875, 3345.92626953125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+973, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2022.3472900390625, -2445.772705078125, 3337.84375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+974, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1977.51220703125, -2394.069580078125, 3337.02685546875, 1.754992246627807617, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+975, 169634, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1960.611083984375, -2395.375, 3335.083740234375, 1.731662392616271972, 120, 0, 0, 20265, 0, 0, 0, 0, 0, 36839), -- 169634 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+976, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1954.6298828125, -2418.218017578125, 3335.12548828125, 2.407768726348876953, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+977, 157671, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2064.5673828125, -2486.013671875, 3338.485107421875, 0.366305470466613769, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+978, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1914.0850830078125, -2400.364501953125, 3351.926513671875, 5.190942287445068359, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+979, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1991.27783203125, -2391.07470703125, 3336.37939453125, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+980, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2026.734375, -2470.947998046875, 3345.019287109375, 5.250810146331787109, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+981, 161881, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2050.392333984375, -2425.501708984375, 3318.296630859375, 5.115702152252197265, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161881 (Area: Bleak Redoubt - Difficulty: 0) (Auras: )
(@CGUID+982, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1994.791015625, -2372.916015625, 3314.795654296875, 3.423743486404418945, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+983, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2025.052978515625, -2386.9638671875, 3315.105712890625, 4.530659198760986328, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+984, 165017, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1866.7882080078125, -2467.572998046875, 3395.10546875, 4.836562633514404296, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+985, 165017, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1863.392333984375, -2468.86279296875, 3395.10546875, 4.353006362915039062, 120, 0, 0, 7515, 100, 0, 0, 0, 0, 36839), -- 165017 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 212171 - Read Scroll)
(@CGUID+986, 160417, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1864.412841796875, -2480.62255859375, 3394.983154296875, 4.836226940155029296, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 160417 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+987, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2024.3333740234375, -2391.407958984375, 3316.372314453125, 4.554553031921386718, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+988, 162259, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2038.1676025390625, -2399.0205078125, 3332.141845703125, 2.773538589477539062, 120, 0, 0, 5260, 0, 0, 0, 0, 0, 36839), -- 162259 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+989, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1953.3873291015625, -2370.567138671875, 3335.125, 4.69492959976196289, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+990, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1944.4998779296875, -2358.619384765625, 3335.12548828125, 4.419237613677978515, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+991, 164221, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1861.185791015625, -2465.720458984375, 3395.10546875, 2.578293085098266601, 120, 0, 0, 30060, 0, 0, 0, 0, 0, 36839), -- 164221 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 319502 - Cosmetic - Slime Cauldron)
(@CGUID+992, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1944.3125, -2353.708251953125, 3336.33447265625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343329 - [DNT] - Flavor 2)
(@CGUID+993, 160418, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1857.2847900390625, -2464.4619140625, 3395.10546875, 4.357306957244873046, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 160418 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 144140 - Vertex Color Lime Green)
(@CGUID+994, 160419, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1856.91845703125, -2467.375, 3395.237060546875, 4.577907562255859375, 120, 0, 0, 3758, 0, 0, 0, 0, 0, 36839), -- 160419 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+995, 169634, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1999.373291015625, -2358.041748046875, 3315.650390625, 3.066086769104003906, 120, 0, 0, 20265, 0, 0, 0, 0, 0, 36839), -- 169634 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+996, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2004.427734375, -2347.27197265625, 3315.560546875, 5.386367321014404296, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839), -- 161376 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+997, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1948.4097900390625, -2334.513671875, 3335.44384765625, 2.379230022430419921, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+998, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1954.422119140625, -2331.974365234375, 3335.125, 2.092480659484863281, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+999, 161376, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2035.3946533203125, -2333.39013671875, 3319.350341796875, 3.288599729537963867, 120, 0, 0, 8267, 0, 0, 0, 0, 0, 36839); -- 161376 (Area: Bleak Redoubt - Difficulty: 0)

REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1000, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2046.5250244140625, -2340.71142578125, 3318.8349609375, 3.493918180465698242, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1001, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2054.1669921875, -2345.3125, 3318.939453125, 4.712388992309570312, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1002, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2048.94091796875, -2336.59375, 3322.79833984375, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343329 - [DNT] - Flavor 2)
(@CGUID+1003, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2052.2119140625, -2341.45654296875, 3320.015625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343800 - [DNT] - Flavor 2)
(@CGUID+1004, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 1930.4305419921875, -2431.588623046875, 3345.29248046875, 4.316307544708251953, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1005, 167355, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2068.9248046875, -2430.197265625, 3315.090576171875, 3.427265644073486328, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1006, 166908, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2379.189697265625, -2373.4658203125, 3272.648193359375, 1.970599532127380371, 120, 10, 0, 135100, 0, 1, 0, 0, 0, 36839), -- 166908 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 326001 - Summon Creep Area Trigger) (possible waypoints or random movement)
(@CGUID+1007, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2075.08349609375, -2419.850341796875, 3315.090576171875, 1.714224696159362792, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1008, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2072.9169921875, -2445.3125, 3315.590576171875, 5.290545463562011718, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1009, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2070.482177734375, -2451.7802734375, 3316.279296875, 3.037042617797851562, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1010, 161398, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2076.598876953125, -2417.453125, 3315.048828125, 4.272404670715332031, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 161398 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1011, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2072.68408203125, -2448.79345703125, 3316.12744140625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343800 - [DNT] - Flavor 2)
(@CGUID+1012, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2065.78759765625, -2447.374755859375, 3317.635498046875, 0.631091177463531494, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1013, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2080.34130859375, -2425.46533203125, 3315.090576171875, 3.195128440856933593, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1014, 156558, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2069.9306640625, -2444.814208984375, 3316.80322265625, 0, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 156558 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 343329 - [DNT] - Flavor 2)
(@CGUID+1015, 161397, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2100.2900390625, -2416.795166015625, 3315.0859375, 4.528763771057128906, 120, 0, 0, 60120, 0, 0, 0, 0, 0, 36839), -- 161397 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1016, 167435, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2236.400390625, -2359.0908203125, 3298.662353515625, 2.486373424530029296, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167435 (Area: Bleak Redoubt - Difficulty: 0) (Auras: 325854 - Bone Tornado)
(@CGUID+1017, 162258, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2225.58935546875, -2186.400390625, 3299.996826171875, 3.993411540985107421, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1018, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2139.5830078125, -2218.75, 3297.490478515625, 4.374995231628417968, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1019, 167354, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2136.7802734375, -2222.44921875, 3298.460693359375, 3.827322244644165039, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1020, 162258, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2262.760986328125, -2281.13818359375, 3315.233154296875, 1.509435892105102539, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1021, 167353, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2145.314697265625, -2204.052490234375, 3294.586669921875, 3.432769060134887695, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1022, 167395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2139.703125, -2206.17529296875, 3297.87890625, 3.412284612655639648, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1023, 167353, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2150.6162109375, -2220.1044921875, 3294.85546875, 4.012653350830078125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1024, 167395, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2131.5712890625, -2190.647705078125, 3299.58251953125, 3.263870954513549804, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1025, 162258, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2302.281982421875, -2236.093994140625, 3318.368896484375, 2.335532426834106445, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1026, 158040, 2222, 11462, 11466, '0', '0', 0, 0, 0, 2135.085205078125, -2167.498291015625, 3298.33056640625, 1.583847880363464355, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Bleak Redoubt - Difficulty: 0)
(@CGUID+1027, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2190.729248046875, -2203.44775390625, 3274.290283203125, 5.924205780029296875, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1028, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2163.884033203125, -2170.42822265625, 3282.4853515625, 6.136178493499755859, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1029, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2190.611083984375, -2199.5, 3270.89501953125, 4.887232780456542968, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0) (Auras: 319620 - Siphon Anima)
(@CGUID+1030, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2209.41845703125, -2245.965087890625, 3274.665771484375, 5.457226276397705078, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1031, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2189.426513671875, -2197.34521484375, 3274.86328125, 0.486353188753128051, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1032, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2191.56591796875, -2155.66162109375, 3271.2109375, 0.164134979248046875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1033, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2215.48095703125, -2233.12841796875, 3268.89794921875, 2.121612071990966796, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0) (Auras: 319620 - Siphon Anima)
(@CGUID+1034, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2212.934326171875, -2248.141357421875, 3278.630126953125, 1.355497241020202636, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1035, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2216.436767578125, -2197.409423828125, 3273.5966796875, 1.879271864891052246, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1036, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2223.876708984375, -2237.380126953125, 3268.77294921875, 0, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0) (Auras: 319620 - Siphon Anima)
(@CGUID+1037, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2227.350341796875, -2269.31787109375, 3278.41845703125, 0.628652632236480712, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1038, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2226.216064453125, -2236.6494140625, 3272.28369140625, 2.890655517578125, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1039, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2139.624267578125, -2156.842041015625, 3297.89599609375, 3.539886236190795898, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1040, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2191.282470703125, -2164.525146484375, 3271.017578125, 2.264285087585449218, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1041, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2218.09765625, -2232.867431640625, 3271.4892578125, 5.222846031188964843, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1042, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2236.5869140625, -2167.583251953125, 3272.443115234375, 0.883556008338928222, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1043, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2178.385498046875, -2143.458251953125, 3273.693115234375, 2.769351005554199218, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1044, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2205.466552734375, -2141.313720703125, 3269.018310546875, 3.796217679977416992, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1045, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2213.494873046875, -2137.463623046875, 3270.2822265625, 1.935804367065429687, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1046, 162258, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2308.486328125, -2082.27685546875, 3335.823974609375, 5.260205268859863281, 120, 10, 0, 9018, 0, 1, 0, 0, 0, 36839), -- 162258 (Area: Iron Trench - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1047, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2262.493408203125, -2242.297607421875, 3272.521484375, 3.089387893676757812, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1048, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2236.443115234375, -2152.38916015625, 3277.537109375, 2.120249032974243164, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1049, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2261.633056640625, -2190.025146484375, 3272.234619140625, 5.896511077880859375, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1050, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2253.283447265625, -2257.0234375, 3270.670654296875, 5.648076057434082031, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1051, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2233.701171875, -2145.937255859375, 3279.195068359375, 0.472886532545089721, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1052, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2230.802490234375, -2277.860107421875, 3282.53271484375, 0.442234814167022705, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1053, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2259.670166015625, -2194.26220703125, 3272.18896484375, 1.420073509216308593, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0) (Auras: 330574 - Deathbolt Rift)
(@CGUID+1054, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2237.65478515625, -2276.395263671875, 3279.658935546875, 3.85445404052734375, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1055, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2270.270751953125, -2199.4619140625, 3275.91064453125, 0, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1056, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2232.543701171875, -2138.187744140625, 3277.8388671875, 3.92206120491027832, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1057, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2281.84716796875, -2214.439208984375, 3277.12890625, 0, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1058, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2271.510498046875, -2204.263916015625, 3275.6748046875, 0, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1059, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2273.85791015625, -2200.09912109375, 3276.72119140625, 2.684063196182250976, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1060, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2277.354736328125, -2205.127197265625, 3277.473388671875, 3.594551801681518554, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1061, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2227.6865234375, -2297.2265625, 3290.63330078125, 5.938585281372070312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1062, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2268.545166015625, -2183.932373046875, 3272.58837890625, 2.077303886413574218, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0) (Auras: 319620 - Siphon Anima)
(@CGUID+1063, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2260.759521484375, -2143.233642578125, 3273.99755859375, 5.630703926086425781, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1064, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2290.5625, -2231.944580078125, 3274.03173828125, 3.990951061248779296, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1065, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2289.75341796875, -2243.1806640625, 3276.74951171875, 6.175545692443847656, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1066, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2289.21533203125, -2209.882080078125, 3278.58447265625, 1.809125304222106933, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1067, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2300.55029296875, -2202.73779296875, 3275.767333984375, 3.948077678680419921, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1068, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2292.908935546875, -2239.08740234375, 3274.2177734375, 1.22305309772491455, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1069, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2318.626220703125, -2207.91845703125, 3273.25146484375, 3.381084918975830078, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1070, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2273.49560546875, -2283.769287109375, 3273.160888671875, 0.610990881919860839, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1071, 167354, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2297.29931640625, -2261.93896484375, 3274.99365234375, 1.980943083763122558, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1072, 167354, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2301.21923828125, -2257.022216796875, 3276.10107421875, 4.109803676605224609, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1073, 167354, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2297.98193359375, -2258.01123046875, 3275.93115234375, 5.967304229736328125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1074, 162258, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2334.46875, -2356.414794921875, 3296.616455078125, 1.522966504096984863, 120, 0, 0, 9018, 0, 0, 0, 0, 0, 36839), -- 162258 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1075, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2327.0234375, -2208.87109375, 3272.5634765625, 0.45780453085899353, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1076, 167354, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2305.172607421875, -2256.336669921875, 3275.08203125, 1.999583959579467773, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1077, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2308.209716796875, -2256.262939453125, 3273.92626953125, 4.356852054595947265, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1078, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2262.56640625, -2294.77734375, 3272.045166015625, 0.523925244808197021, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1079, 167395, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2308.8681640625, -2259.4931640625, 3273.71923828125, 2.799649238586425781, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167395 (Area: Iron Trench - Difficulty: 0) (Auras: 244867 - 8.0 Carry Sack New Anim)
(@CGUID+1080, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2301.438720703125, -2127.931884765625, 3297.13427734375, 4.762249946594238281, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0) (Auras: 330574 - Deathbolt Rift)
(@CGUID+1081, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2288.029052734375, -2274.68017578125, 3267.101318359375, 2.417525529861450195, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1082, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2316.957275390625, -2240.979736328125, 3273.15478515625, 0.117451041936874389, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1083, 167435, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2242.973876953125, -2244.944580078125, 3270.26220703125, 3.917630195617675781, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 167435 (Area: Iron Trench - Difficulty: 0) (Auras: 325854 - Bone Tornado)
(@CGUID+1084, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2337.728515625, -2179.83935546875, 3276.61962890625, 3.288784742355346679, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1085, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2332.636474609375, -2227.305908203125, 3272.73583984375, 2.641906499862670898, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1086, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2330.93408203125, -2231.208251953125, 3270.692626953125, 0.478644609451293945, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0) (Auras: 319620 - Siphon Anima)
(@CGUID+1087, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2342.81298828125, -2182.095703125, 3275.5087890625, 3.004222869873046875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1088, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2297.109619140625, -2279.274658203125, 3266.098388671875, 2.784649610519409179, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1089, 174654, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2334.393310546875, -2230.384521484375, 3273.593017578125, 2.63556075096130371, 120, 0, 0, 27, 0, 0, 0, 0, 0, 36839), -- 174654 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1090, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2332.878173828125, -2267.5478515625, 3264.076171875, 4.089094161987304687, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1091, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2311.741455078125, -2288.829833984375, 3262.107421875, 3.737230539321899414, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1092, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2364.113525390625, -2200.54296875, 3271.122802734375, 0.056690659373998641, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1093, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2356.19287109375, -2233.947021484375, 3272.441650390625, 0.361284971237182617, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1094, 168677, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2387.515625, -2153.125, 3309.9775390625, 3.821690797805786132, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168677 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1095, 167354, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2380.32763671875, -2260.76220703125, 3269.65234375, 2.847905397415161132, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1096, 169055, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2394.545166015625, -2156.657958984375, 3308.936767578125, 6.220369815826416015, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169055 (Area: Iron Trench - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1097, 167353, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2370.786865234375, -2231.514892578125, 3268.40185546875, 2.568133831024169921, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167353 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1098, 169055, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2333.27783203125, -2100.522705078125, 3309.03271484375, 3.882153272628784179, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169055 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1099, 169055, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2390.798583984375, -2161.928955078125, 3309.205078125, 2.582235574722290039, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169055 (Area: Iron Trench - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1100, 169055, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2385.4619140625, -2149.40283203125, 3310.333251953125, 1.875012397766113281, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169055 (Area: Iron Trench - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1101, 169184, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2377.657470703125, -2139.290771484375, 3311.1640625, 2.471123933792114257, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169184 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1102, 158040, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2376.453857421875, -2258.26953125, 3269.56005859375, 5.675176143646240234, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 158040 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1103, 168677, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2385.614501953125, -2158.84716796875, 3309.77392578125, 1.65732884407043457, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 168677 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1104, 175021, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2346.17919921875, -2099.614990234375, 3309.173828125, 2.464107036590576171, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Iron Trench - Difficulty: 0)
(@CGUID+1105, 167354, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2367.225830078125, -2263.02587890625, 3268.605224609375, 2.339621543884277343, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1106, 164830, 0, 11462, 12241, '0', '0', 0, 0, 0, -0.10577797889709472, -0.00096166133880615, 1.521515130996704101, 0, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164830 (Area: Iron Trench - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+1107, 164829, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2285.255126953125, -1986.046875, 3342.308349609375, 5.433526039123535156, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 164829 (Area: Iron Trench - Difficulty: 0) (Auras: )
(@CGUID+1108, 175021, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2300.115478515625, -2087.52294921875, 3306.6044921875, 0.724340498447418212, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Iron Trench - Difficulty: 0)
(@CGUID+1109, 169055, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2378.1181640625, -2115.453125, 3313.06103515625, 5.204877853393554687, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169055 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1110, 164830, 0, 11462, 12241, '0', '0', 0, 0, 0, -0.10577797889709472, -0.00096166133880615, 1.521515130996704101, 0, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 164830 (Area: Iron Trench - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) (possible waypoints or random movement)
(@CGUID+1111, 167355, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2344.302001953125, -2075.0390625, 3309.027587890625, 2.496138572692871093, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Iron Trench - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1112, 164829, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2264.046630859375, -1975.06103515625, 3348.552978515625, 0.723551034927368164, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 164829 (Area: Iron Trench - Difficulty: 0) (Auras: )
(@CGUID+1113, 175021, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2345.824462890625, -2062.255859375, 3311.46142578125, 2.874473094940185546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Iron Trench - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1114, 169055, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2395.1962890625, -2091.720458984375, 3314.08349609375, 5.204877853393554687, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 169055 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1115, 171419, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2302.053955078125, -2028.68408203125, 3325.449462890625, 6.172318935394287109, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 171419 (Area: Iron Trench - Difficulty: 0) (Auras: 323554 - Keen Eyes)
(@CGUID+1116, 173944, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2255.427001953125, -2034.73095703125, 3340.9375, 6.030716419219970703, 120, 0, 0, 54040, 0, 0, 0, 0, 0, 36839), -- 173944 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1117, 171358, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2269.5966796875, -2030.6640625, 3325.17626953125, 5.6050872802734375, 120, 0, 0, 8106, 0, 0, 0, 0, 0, 36839), -- 171358 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1118, 170901, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2281.6962890625, -2019.171875, 3324.80859375, 5.507256507873535156, 120, 10, 0, 60120, 0, 1, 0, 0, 0, 36839), -- 170901 (Area: Iron Trench - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1119, 171358, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2282.942626953125, -2000.6597900390625, 3324.7998046875, 5.716549873352050781, 120, 0, 0, 8106, 0, 0, 0, 0, 0, 36839), -- 171358 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1120, 171419, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2328.760498046875, -1988.28125, 3325.485107421875, 5.021538257598876953, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 171419 (Area: Iron Trench - Difficulty: 0) (Auras: 323554 - Keen Eyes)
(@CGUID+1121, 171358, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2298.010498046875, -1982.1754150390625, 3324.826171875, 5.486040592193603515, 120, 0, 0, 8106, 0, 0, 0, 0, 0, 36839), -- 171358 (Area: Iron Trench - Difficulty: 0)
(@CGUID+1122, 167355, 2222, 11462, 12241, '0', '0', 0, 0, 0, 2415.363525390625, -2081.4248046875, 3309.83203125, 5.331891059875488281, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- Pulsating Maggot (Area: Iron Trench - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1123, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2295.3125, -1985.9166259765625, 3324.82275390625, 5.486040592193603515, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1124, 164860, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2301.020751953125, -1980.6978759765625, 3325.030517578125, 3.106362819671630859, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164860 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1125, 157708, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2237.90625, -2023.7742919921875, 3332.198974609375, 1.517159223556518554, 120, 0, 0, 54040, 0, 0, 0, 0, 0, 36839), -- 157708 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1126, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2334.40283203125, -1957.7586669921875, 3324.65869140625, 4.327922344207763671, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1127, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2257.1396484375, -2020.2283935546875, 3328.1591796875, 2.453732728958129882, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1128, 164829, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2285.255126953125, -1986.046875, 3342.308349609375, 5.433526039123535156, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 164829 (Area: House of the Chosen - Difficulty: 0) (Auras: )
(@CGUID+1129, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2298.010498046875, -1982.1754150390625, 3324.82470703125, 5.486040592193603515, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1130, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2272.569580078125, -2035.1458740234375, 3324.74658203125, 0.841950893402099609, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1131, 164825, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2302.053955078125, -2028.68408203125, 3325.449462890625, 6.172318935394287109, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164825 (Area: House of the Chosen - Difficulty: 0) (Auras: 323554 - Keen Eyes)
(@CGUID+1132, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2282.942626953125, -2000.6597900390625, 3324.8115234375, 5.716549873352050781, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1133, 164825, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2290.017333984375, -2037.8472900390625, 3325.33740234375, 6.002702713012695312, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164825 (Area: House of the Chosen - Difficulty: 0) (Auras: 323554 - Keen Eyes)
(@CGUID+1134, 162816, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2000.6353759765625, -1971.111083984375, 3394.935546875, 4.193350791931152343, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 162816 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1135, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2286.24658203125, -1997.34033203125, 3324.825439453125, 5.716549873352050781, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1136, 164830, 0, 11462, 12783, '0', '0', 0, 0, 0, -0.10577797889709472, -0.00096166133880615, 1.521515130996704101, 0, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164830 (Area: House of the Chosen - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+1137, 162816, 2222, 11462, 12783, '0', '0', 0, 0, 0, 1989.763916015625, -1995.779541015625, 3394.98388671875, 0.877689480781555175, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 162816 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1138, 164825, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2336.40185546875, -1971.38037109375, 3325.53759765625, 4.061667919158935546, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164825 (Area: House of the Chosen - Difficulty: 0) (Auras: 323554 - Keen Eyes)
(@CGUID+1139, 162816, 2222, 11462, 12783, '0', '0', 0, 0, 0, 1982.5694580078125, -1977.998291015625, 3395.350341796875, 5.593545913696289062, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 162816 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1140, 164825, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2328.760498046875, -1988.28125, 3325.485107421875, 5.021538257598876953, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164825 (Area: House of the Chosen - Difficulty: 0) (Auras: 323554 - Keen Eyes)
(@CGUID+1141, 157708, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2255.427001953125, -2034.73095703125, 3340.91455078125, 6.030716419219970703, 120, 0, 0, 54040, 0, 0, 0, 0, 0, 36839), -- 157708 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1142, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2292.4931640625, -1989.3211669921875, 3324.7880859375, 5.748167991638183593, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1143, 164829, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2305.764404296875, -1895.1951904296875, 3386.82470703125, 1.002599835395812988, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 164829 (Area: House of the Chosen - Difficulty: 0) (Auras: )
(@CGUID+1144, 164830, 0, 11462, 12783, '0', '0', 0, 0, 0, -0.10577797889709472, -0.00096166133880615, 1.521515130996704101, 0, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164830 (Area: House of the Chosen - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+1145, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2289.03466796875, -1993.59033203125, 3324.80908203125, 5.716549873352050781, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1146, 162816, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2007.4791259765625, -1989.109375, 3394.999267578125, 2.566263437271118164, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 162816 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1147, 170901, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2305.15478515625, -1988.4964599609375, 3324.746337890625, 0.92805635929107666, 120, 0, 0, 60120, 0, 0, 0, 0, 0, 36839), -- 170901 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1148, 164831, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2277.697265625, -1966.6806640625, 3341.937744140625, 2.569047212600708007, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 164831 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1149, 164830, 0, 11462, 12783, '0', '0', 0, 0, 0, -0.10577797889709472, -0.00096166133880615, 1.521515130996704101, 0, 120, 0, 0, 6755, 0, 0, 0, 0, 0, 36839), -- 164830 (Area: House of the Chosen - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded)
(@CGUID+1150, 164829, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2281.76123046875, -1861.728271484375, 3419.70751953125, 3.998256683349609375, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 164829 (Area: House of the Chosen - Difficulty: 0) (Auras: )
(@CGUID+1151, 157708, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2329.088623046875, -1937.326416015625, 3341.53515625, 5.041985034942626953, 120, 0, 0, 54040, 0, 0, 0, 0, 0, 36839), -- 157708 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1152, 164824, 2222, 11462, 12783, '0', '0', 0, 0, 0, 2329.83154296875, -1954.8004150390625, 3325.1201171875, 4.295540809631347656, 120, 0, 0, 10133, 0, 0, 0, 0, 0, 36839), -- 164824 (Area: House of the Chosen - Difficulty: 0)
(@CGUID+1153, 173944, 2222, 11462, 0, '0', '0', 0, 0, 0, 2329.088623046875, -1937.326416015625, 3341.53515625, 5.041985034942626953, 120, 0, 0, 54040, 0, 0, 0, 0, 0, 36839), -- 173944 (Area: 0 - Difficulty: 0)
(@CGUID+1154, 164830, 0, 11462, 0, '0', '0', 0, 0, 0, -0.10577797889709472, -0.00096166133880615, 1.521515130996704101, 0, 120, 10, 0, 6755, 0, 1, 0, 0, 0, 36839), -- 164830 (Area: 0 - Difficulty: 0) (Auras: 46598 - Ride Vehicle Hardcoded) (possible waypoints or random movement)
(@CGUID+1155, 164829, 2222, 11462, 0, '0', '0', 0, 0, 0, 2228.259765625, -1872.634765625, 3419.707763671875, 2.689405441284179687, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 164829 (Area: 0 - Difficulty: 0) (Auras: )
(@CGUID+1156, 171358, 2222, 11462, 0, '0', '0', 0, 0, 0, 2329.83154296875, -1954.8004150390625, 3325.1201171875, 4.295540809631347656, 120, 0, 0, 8106, 0, 0, 0, 0, 0, 36839), -- 171358 (Area: 0 - Difficulty: 0)
(@CGUID+1157, 144929, 2222, 11462, 0, '0', '0', 0, 0, 0, 2606.0322265625, -1777.1007080078125, 3235.8369140625, 0, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 36839), -- 144929 (Area: 0 - Difficulty: 0)
(@CGUID+1158, 144929, 2222, 11462, 0, '0', '0', 0, 0, 0, 2620.19970703125, -1722.1910400390625, 3236.41064453125, 5.943772792816162109, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 36839), -- 144929 (Area: 0 - Difficulty: 0)
(@CGUID+1159, 167359, 2222, 11462, 0, '0', '0', 0, 0, 0, 2385.294189453125, -1871.963623046875, 3304.560302734375, 1.284020781517028808, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1160, 168972, 2222, 11462, 0, '0', '0', 0, 0, 0, 2439.263916015625, -1876.467041015625, 3279.200439453125, 3.970074892044067382, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 168972 (Area: 0 - Difficulty: 0)
(@CGUID+1161, 167359, 2222, 11462, 0, '0', '0', 0, 0, 0, 2407.0517578125, -1886.2998046875, 3293.426513671875, 3.217792034149169921, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1162, 167359, 2222, 11462, 0, '0', '0', 0, 0, 0, 2408.228759765625, -1857.7340087890625, 3297.255126953125, 3.436686515808105468, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: 0 - Difficulty: 0)
(@CGUID+1163, 157671, 2222, 11462, 0, '0', '0', 0, 0, 0, 2486.2265625, -1890.7100830078125, 3274.29443359375, 2.713392019271850585, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: 0 - Difficulty: 0)
(@CGUID+1164, 169129, 2222, 11462, 0, '0', '0', 0, 0, 0, 2405.08984375, -1850.3946533203125, 3306.531494140625, 3.308188915252685546, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: 0 - Difficulty: 0)
(@CGUID+1165, 159894, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2469.423583984375, -1846.84033203125, 3273.010009765625, 5.81352090835571289, 120, 0, 0, 117910, 0, 0, 0, 0, 0, 36839), -- Baron Vyraz (Area: The Spearhead - Difficulty: 0)
(@CGUID+1166, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2497.396484375, -1890.2745361328125, 3274.54443359375, 2.685247659683227539, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1167, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2490.781982421875, -1892.770263671875, 3274.474609375, 2.699373960494995117, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1168, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2492.84228515625, -1888.2154541015625, 3274.41943359375, 2.698230743408203125, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1169, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2488.290771484375, -1886.1573486328125, 3274.326904296875, 2.711681365966796875, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1170, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2494.802001953125, -1894.5677490234375, 3274.54443359375, 2.718535900115966796, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1171, 168941, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2464.654541015625, -1853.203125, 3274.017578125, 0.963898241519927978, 120, 0, 0, 117910, 0, 0, 0, 0, 0, 36839), -- 168941 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1172, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2438.470947265625, -1832.397705078125, 3280.49853515625, 3.286000728607177734, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1173, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2466.925048828125, -1829.285400390625, 3278.309814453125, 2.995408535003662109, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1174, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2461.359375, -1840.703125, 3278.497802734375, 3.083958864212036132, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1175, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2440.583251953125, -1821.5833740234375, 3280.22314453125, 4.058223724365234375, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1176, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2443.294921875, -1824.3568115234375, 3280.4384765625, 1.280176043510437011, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1177, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2461.9814453125, -1827.0665283203125, 3278.350341796875, 2.634458065032958984, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1178, 168951, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2500.135498046875, -1864.62158203125, 3273.010498046875, 3.032643795013427734, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 168951 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1179, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2524.83984375, -1872.885986328125, 3284.526611328125, 1.453211426734924316, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1180, 168951, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2502.796875, -1874.3507080078125, 3273.015380859375, 3.131211519241333007, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 168951 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1181, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2487.771484375, -1826.9986572265625, 3270.20654296875, 2.476007699966430664, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1182, 168951, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2498.678955078125, -1876.9757080078125, 3273.010498046875, 2.150187492370605468, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 168951 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1183, 157519, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2496.592041015625, -1831.4757080078125, 3270.46044921875, 4.532752513885498046, 120, 0, 0, 187875, 0, 0, 0, 0, 0, 36839), -- 157519 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1184, 168952, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2498.298583984375, -1868.84375, 3273.059814453125, 3.28540968894958496, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 168952 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1185, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2527.328857421875, -1879.463623046875, 3282.48828125, 2.424596071243286132, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1186, 160415, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2506.247314453125, -1857.34033203125, 3271.912353515625, 2.285305500030517578, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- 160415 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1187, 160415, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2458.423583984375, -1842.4271240234375, 3276.655029296875, 4.216404914855957031, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- 160415 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1188, 169359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2483.30908203125, -1857.5625, 3273.010498046875, 2.873178005218505859, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1189, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2453.83203125, -1802.8419189453125, 3274.13134765625, 4.261841297149658203, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1190, 168946, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2613.584716796875, -1925.2630615234375, 3282.2998046875, 3.284049272537231445, 120, 10, 0, 13510, 0, 1, 0, 0, 0, 36839), -- 168946 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1191, 160415, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2468.609375, -1806.701416015625, 3271.5224609375, 3.272811412811279296, 120, 0, 0, 176865, 0, 0, 0, 0, 0, 36839), -- 160415 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1192, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2460.31298828125, -1800.078857421875, 3273.450439453125, 4.171802520751953125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1193, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2451.449951171875, -1808.1839599609375, 3274.56982421875, 4.400527000427246093, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1194, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2455.757568359375, -1798.1419677734375, 3273.617919921875, 4.178833961486816406, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1195, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2456.96435546875, -1808.649169921875, 3274.271484375, 4.3186492919921875, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1196, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2527.9013671875, -1863.435546875, 3284.348388671875, 0.816223859786987304, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1197, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2458.427490234375, -1804.69140625, 3273.864013671875, 4.261841297149658203, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1198, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2528.57958984375, -1857.1534423828125, 3280.586181640625, 5.496860980987548828, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1199, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2547, -1885.1055908203125, 3285.912841796875, 6.060423851013183593, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1200, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2494.515625, -1799.102294921875, 3285.54931640625, 1.05966651439666748, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1201, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2511.3349609375, -1803.68212890625, 3281.82861328125, 4.764328479766845703, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1202, 167483, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2529.40625, -1814.826416015625, 3266.760009765625, 0.257139921188354492, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167483 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1203, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2510.95458984375, -1795.05029296875, 3282.80322265625, 5.296320438385009765, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1204, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2546.497314453125, -1883.8292236328125, 3287.156494140625, 0.327209711074829101, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1205, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2495.53173828125, -1796.64990234375, 3285.585205078125, 5.373364925384521484, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1206, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2515.24462890625, -1801.161865234375, 3286.33837890625, 3.750585556030273437, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1207, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2556.00927734375, -1877.9869384765625, 3280.645751953125, 0.766837716102600097, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1208, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2550.362548828125, -1852.6964111328125, 3284.1572265625, 2.490181446075439453, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1209, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2459.538330078125, -1765.66455078125, 3282.830078125, 5.364113330841064453, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1210, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2538.6298828125, -1774.5802001953125, 3264.493408203125, 2.371446609497070312, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1211, 167458, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2514.68701171875, -1760.3985595703125, 3261.983642578125, 3.232608318328857421, 120, 0, 0, 42714, 0, 0, 0, 0, 0, 36839), -- 167458 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1212, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2545.648681640625, -1781.99609375, 3251.573486328125, 3.769244194030761718, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1213, 160424, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2590.1572265625, -1840.814453125, 3233.241455078125, 1.016494512557983398, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1214, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2532.672119140625, -1773.421630859375, 3257.479736328125, 6.179406166076660156, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1215, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2556.13525390625, -1769.3773193359375, 3251.496826171875, 2.801139116287231445, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1216, 167273, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2564.869873046875, -1797.111083984375, 3239.437255859375, 6.274851799011230468, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167273 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1217, 167483, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2553.385498046875, -1909.6822509765625, 3269.09814453125, 0.318207263946533203, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167483 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1218, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2563.36962890625, -1782.443603515625, 3244.093994140625, 3.064876317977905273, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1219, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2542.35400390625, -1778.2779541015625, 3257.51611328125, 1.14396977424621582, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1220, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2508.2509765625, -1760.9859619140625, 3264.3154296875, 0.091015577316284179, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1221, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2556.666015625, -1764.68994140625, 3248.949462890625, 3.810679912567138671, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1222, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2582.117919921875, -1825.2906494140625, 3232.07470703125, 0.390915721654891967, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1223, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2523.435791015625, -1752.9461669921875, 3256.372802734375, 3.229628801345825195, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1224, 160424, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2588.055419921875, -1833.6927490234375, 3232.373779296875, 5.077947616577148437, 120, 10, 0, 21357, 0, 1, 0, 0, 0, 36839), -- 160424 (Area: The Spearhead - Difficulty: 0) (Auras: 325562 - 9.0 Carry Ballista Ammo) (possible waypoints or random movement)
(@CGUID+1225, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2497.46533203125, -1751.6978759765625, 3267.993408203125, 4.415119647979736328, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1226, 167273, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2557.02783203125, -1830.54345703125, 3249.527099609375, 0.400085628032684326, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167273 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1227, 167273, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2563.5234375, -1762.1458740234375, 3243.540283203125, 0.034469828009605407, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167273 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1228, 160424, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2593.174560546875, -1831.8125, 3231.9150390625, 4.739267826080322265, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1229, 168941, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2554.279541015625, -1853.4879150390625, 3266.836669921875, 1.939340949058532714, 120, 0, 0, 117910, 0, 0, 0, 0, 0, 36839), -- 168941 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1230, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2420.446044921875, -1762.1505126953125, 3359.242431640625, 4.569507598876953125, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1231, 168946, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2642.18505859375, -1752.8775634765625, 3270.776123046875, 2.842603445053100585, 120, 10, 0, 13510, 0, 1, 0, 0, 0, 36839), -- 168946 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1232, 168941, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2427.673583984375, -1826.3211669921875, 3281.201904296875, 3.389978647232055664, 120, 0, 0, 117910, 0, 0, 0, 0, 0, 36839), -- 168941 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1233, 167273, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2563.65625, -1897.3021240234375, 3265.85546875, 0.034469828009605407, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 167273 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1234, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2602.6533203125, -1894.349609375, 3241.343994140625, 4.005140304565429687, 120, 10, 0, 10679, 0, 1, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1235, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2610.10595703125, -1875.21240234375, 3235.9013671875, 4.697548866271972656, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1236, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2601.454345703125, -1848.550048828125, 3232.448486328125, 0.177372574806213378, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1237, 160479, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2606.329833984375, -1853.4444580078125, 3231.87548828125, 1.810274004936218261, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 160479 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1238, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2604.98046875, -1847.91796875, 3231.666748046875, 3.318688631057739257, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1239, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2608.159912109375, -1849.7181396484375, 3231.38916015625, 2.626404047012329101, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1240, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2612.003173828125, -1964.586181640625, 3265.11181640625, 2.950989961624145507, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1241, 144929, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2906.30908203125, -1769.4427490234375, 3236.604736328125, 2.568418502807617187, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 36839), -- 144929 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1242, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2621.525390625, -1884.21875, 3235.38427734375, 0.188737764954566955, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1243, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2616.5498046875, -1964.673828125, 3264.7373046875, 4.030861854553222656, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1244, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2628.327392578125, -1889.0052490234375, 3234.798828125, 0.172207847237586975, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1245, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2640.30859375, -1857.056640625, 3248.237060546875, 3.704126596450805664, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1246, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2640.498779296875, -2004.1553955078125, 3330.659912109375, 5.697942256927490234, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1247, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2666.146484375, -1895.1241455078125, 3237.845947265625, 4.712388992309570312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1248, 160479, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2634.484375, -1886.857666015625, 3235.630126953125, 3.477202177047729492, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 160479 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1249, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2643.342041015625, -1963.404541015625, 3255.311279296875, 5.88080596923828125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839); -- 157671 (Area: The Spearhead - Difficulty: 0)

REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1250, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2649.199462890625, -1864.6864013671875, 3252.37158203125, 1.06994640827178955, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1251, 174653, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2569.038330078125, -2021.2760009765625, 3317.7236328125, 1.616688847541809082, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1252, 162498, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2570.27880859375, -2026.6009521484375, 3315.18701171875, 1.839444756507873535, 120, 0, 0, 2848, 0, 0, 0, 0, 0, 36839), -- 162498 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1253, 174653, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2607.2529296875, -2023.1748046875, 3326.21826171875, 3.901461601257324218, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1254, 144929, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2915.866455078125, -1728.5347900390625, 3237.9833984375, 3.000754117965698242, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 36839), -- 144929 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1255, 174653, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2595.94091796875, -2010.1640625, 3324.34326171875, 4.011980056762695312, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1256, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2641.9306640625, -1862.43701171875, 3251.25537109375, 3.5244293212890625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1257, 174653, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2596.051025390625, -2010.236083984375, 3324.357177734375, 4.266248226165771484, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1258, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2645.577392578125, -1864.54296875, 3251.008544921875, 4.806403160095214843, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1259, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2660.74658203125, -1885.490966796875, 3307.984130859375, 2.875295400619506835, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1260, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2664.775634765625, -1865.5380859375, 3252.181640625, 3.882600307464599609, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1261, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2683.6220703125, -1903.56787109375, 3239.331298828125, 4.664686203002929687, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1262, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2686.978515625, -1908.333984375, 3239.090576171875, 3.926990985870361328, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1263, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2640.44677734375, -1849.2384033203125, 3254.937744140625, 5.787224292755126953, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1264, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2676.706787109375, -1902.1676025390625, 3239.055419921875, 5.382857799530029296, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1265, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2674.560791015625, -1976.6055908203125, 3260.185546875, 5.694925308227539062, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1266, 162498, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2559.35302734375, -2027.9083251953125, 3314.40234375, 5.348077774047851562, 120, 0, 0, 2848, 0, 0, 0, 0, 0, 36839), -- 162498 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1267, 174653, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2591.2587890625, -2032.3551025390625, 3315.920654296875, 5.108683586120605468, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 174653 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1268, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2664.042236328125, -1864.776123046875, 3252.449951171875, 3.409688949584960937, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1269, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2683.10302734375, -1891.809326171875, 3238.665283203125, 4.953556060791015625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1270, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2647.997802734375, -1842.587890625, 3254.552734375, 1.896224141120910644, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1271, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2691.40283203125, -1908.954833984375, 3238.633544921875, 0.819774746894836425, 120, 10, 0, 10679, 0, 1, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1272, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2691.27685546875, -1889.5709228515625, 3238.90478515625, 5.082623481750488281, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1273, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2671.272216796875, -1859.493408203125, 3252.570556640625, 1.85159158706665039, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1274, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2625.826416015625, -1829.6353759765625, 3234.928955078125, 3.058618783950805664, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1275, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2651.600341796875, -1842.4398193359375, 3253.72119140625, 4.231984138488769531, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1276, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2673.36279296875, -1857.139892578125, 3251.956787109375, 1.960392117500305175, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1277, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2671.8671875, -1854.93408203125, 3251.266845703125, 5.352902412414550781, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1278, 169117, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2620.01220703125, -1820.795166015625, 3231.11328125, 5.464911937713623046, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169117 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1279, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2657.814208984375, -1834.0382080078125, 3250.38525390625, 1.745442509651184082, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1280, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2654.71728515625, -1830.4100341796875, 3253.405517578125, 0.763020217418670654, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1281, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2654.123779296875, -1826.0498046875, 3247.47998046875, 1.910553693771362304, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1282, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2655.4267578125, -1828.0118408203125, 3251.303955078125, 0.42968490719795227, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1283, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2687.4873046875, -1845.427001953125, 3249.98486328125, 1.586098790168762207, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1284, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2659.353515625, -1820.596923828125, 3252.132080078125, 1.915174841880798339, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1285, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2658.8857421875, -1826.4739990234375, 3251.625244140625, 1.833176136016845703, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1286, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2658.31591796875, -1823.3802490234375, 3249.01025390625, 2.134203910827636718, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1287, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2713.74853515625, -1903.2401123046875, 3243.02587890625, 4.83648538589477539, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1288, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2689.959716796875, -1850.271728515625, 3250.16015625, 2.831936359405517578, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1289, 144929, 2222, 11462, 11467, '0', '0', 0, 0, 0, 3007.5634765625, -1850.8228759765625, 3230.47998046875, 2.889199495315551757, 120, 0, 0, 4579, 0, 0, 0, 0, 0, 36839), -- 144929 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1290, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2674.069091796875, -1839.27978515625, 3281.117919921875, 3.367762088775634765, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1291, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2714.28466796875, -1907.5382080078125, 3242.67041015625, 1.295339703559875488, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1292, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2684.131591796875, -1832.3900146484375, 3251.72998046875, 3.627209663391113281, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1293, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2684.68798828125, -1837.1298828125, 3253.14892578125, 0.248363181948661804, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1294, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2662.711669921875, -1821.1944580078125, 3252.225830078125, 2.512403249740600585, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1295, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2676.547119140625, -1818.7532958984375, 3248.27490234375, 4.994340419769287109, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1296, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2678.26953125, -1819.184814453125, 3247.589599609375, 0.140901386737823486, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1297, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2715.48193359375, -1858.33984375, 3239.82373046875, 1.647110581398010253, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1298, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2728.391845703125, -1908.140625, 3261.322509765625, 2.044628620147705078, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1299, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2727.823974609375, -1897.950927734375, 3254.214599609375, 3.65883183479309082, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1300, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2597.2646484375, -1805.205810546875, 3231.991455078125, 0.362843841314315795, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1301, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2680.716796875, -1820.10205078125, 3248.382568359375, 2.642132997512817382, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1302, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2730.365234375, -1897.9913330078125, 3255.437744140625, 0.565737128257751464, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1303, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2686.37841796875, -1813.5792236328125, 3333.50927734375, 2.801574468612670898, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1304, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2686.506103515625, -1826.1649169921875, 3246.296875, 2.134203910827636718, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1305, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2704.00439453125, -1826.0816650390625, 3237.10595703125, 2.079010009765625, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1306, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2624.638916015625, -1793.203125, 3231.372314453125, 0.425266951322555541, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1307, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2730.852294921875, -1905.6558837890625, 3256.53857421875, 4.427530288696289062, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1308, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2628.282958984375, -1791.5035400390625, 3231.000732421875, 3.379998207092285156, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1309, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2533.47021484375, -1901.6773681640625, 3273.114990234375, 6.234348297119140625, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1310, 168941, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2554.279541015625, -1853.4879150390625, 3266.836669921875, 1.939340949058532714, 120, 0, 0, 117910, 0, 0, 0, 0, 0, 36839), -- 168941 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1311, 168216, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2635.7236328125, -2090.217041015625, 3336.798095703125, 0.949700713157653808, 120, 0, 0, 60120, 0, 0, 0, 0, 0, 36839), -- 168216 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1312, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2568.188232421875, -1821.516357421875, 3235.88916015625, 5.780455589294433593, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1313, 169063, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2734.2978515625, -1878.34033203125, 3240.490966796875, 1.999355435371398925, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169063 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1314, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2722.1337890625, -1841.5035400390625, 3238.605224609375, 0.604759454727172851, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1315, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2719.575439453125, -1837.790283203125, 3238.537109375, 4.835774898529052734, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1316, 167273, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2563.65625, -1897.3021240234375, 3265.85546875, 0.034469828009605407, 120, 10, 0, 14238, 0, 1, 0, 0, 0, 36839), -- 167273 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1317, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2737.3564453125, -1906.3822021484375, 3253.442138671875, 0.888701498508453369, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1318, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2737.686767578125, -1875.1458740234375, 3239.797119140625, 0.457131057977676391, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1319, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2732.714111328125, -1844.8795166015625, 3238.03369140625, 0.037128582596778869, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1320, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2727.6455078125, -1829.969970703125, 3237.43359375, 5.19873046875, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1321, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2751.405517578125, -1902.1932373046875, 3250.895263671875, 1.150708436965942382, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1322, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2754.739990234375, -1903.2132568359375, 3251.105712890625, 4.673502922058105468, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1323, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2726.923095703125, -1982.6951904296875, 3328.56005859375, 2.319835186004638671, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1324, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2755.809814453125, -1934.0694580078125, 3248.190673828125, 0.497859328985214233, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1325, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2759.133544921875, -1929.8934326171875, 3246.995361328125, 4.040148735046386718, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1326, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2781.50341796875, -1832.944580078125, 3316.53466796875, 1.57487344741821289, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1327, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2793.337646484375, -1858.892333984375, 3232.24169921875, 0.622122943401336669, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1328, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2763.071044921875, -1825.794677734375, 3235.53857421875, 3.424722671508789062, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1329, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2749.46484375, -1831.3919677734375, 3233.024658203125, 1.67995154857635498, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1330, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2709.15869140625, -1805.3013916015625, 3232.00830078125, 4.400527000427246093, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1331, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2747.002685546875, -1841.286376953125, 3235.28955078125, 4.259230613708496093, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1332, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2739.07177734375, -1815.62158203125, 3233.889892578125, 2.856587886810302734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1333, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.569580078125, -1860.9305419921875, 3232.042236328125, 1.365099668502807617, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1334, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2724.81982421875, -1825.32568359375, 3236.8330078125, 5.258977890014648437, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1335, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2787.169189453125, -1905.87158203125, 3238.45556640625, 5.347335338592529296, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1336, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2725.826171875, -1826.513671875, 3236.899658203125, 2.055342435836791992, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1337, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2774.216064453125, -1836.7916259765625, 3235.87158203125, 0.587330341339111328, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1338, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2788.229248046875, -1861.0225830078125, 3232.90283203125, 0.654239475727081298, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1339, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2780.640625, -1860.4375, 3234.177978515625, 5.669179439544677734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1340, 165366, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2766.74658203125, -1828.3072509765625, 3235.95166015625, 0.229050487279891967, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 165366 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1341, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2812.445068359375, -1905.208740234375, 3235.893310546875, 3.583409786224365234, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1342, 168424, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2902.20751953125, -1843.409912109375, 3268.10302734375, 2.488152027130126953, 120, 10, 0, 20265, 0, 1, 0, 0, 0, 36839), -- 168424 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1343, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2743.82275390625, -1799.1617431640625, 3230.53662109375, 2.905911684036254882, 120, 10, 0, 10679, 0, 1, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1344, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2778.1689453125, -1822.025390625, 3235.934814453125, 5.592005252838134765, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1345, 168946, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2904.219482421875, -1849.0743408203125, 3258.93798828125, 2.819683313369750976, 120, 10, 0, 13510, 0, 1, 0, 0, 0, 36839), -- 168946 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1346, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2765.8916015625, -1808.6085205078125, 3233.068359375, 0.233531743288040161, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1347, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2708.941650390625, -1791.175537109375, 3230.50048828125, 1.209302186965942382, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1348, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2765.213623046875, -1801.6922607421875, 3231.505126953125, 1.805353760719299316, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1349, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2668.233154296875, -1791.8763427734375, 3232.251708984375, 6.086556434631347656, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1350, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2797.1484375, -1830.8726806640625, 3234.93505859375, 2.476610660552978515, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1351, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2779.060546875, -1807.853515625, 3233.319580078125, 0.301111757755279541, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1352, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2675.0830078125, -1783.9976806640625, 3230.942626953125, 2.667777776718139648, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1353, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2666.810302734375, -1779.420166015625, 3230.50048828125, 5.96569061279296875, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1354, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2708.496826171875, -1765.6666259765625, 3231.637939453125, 0.411138176918029785, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1355, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2747.286376953125, -1770.28857421875, 3231.76611328125, 4.220672130584716796, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1356, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2738.694580078125, -1768.423583984375, 3231.596923828125, 0.978622794151306152, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1357, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2781.798583984375, -1792.486083984375, 3230.635498046875, 5.938997745513916015, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1358, 169103, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2690.8515625, -1773.16845703125, 3230.594482421875, 0.400152206420898437, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169103 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1359, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2698.369873046875, -1771.906982421875, 3231.55126953125, 5.544789791107177734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1360, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2706.622314453125, -1768.66845703125, 3231.910888671875, 0.040781516581773757, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1361, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2726.525146484375, -1827.8524169921875, 3237.2041015625, 4.102122306823730468, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1362, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2813.21875, -1848.8170166015625, 3241.841552734375, 4.281960487365722656, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1363, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2759.587646484375, -1929.3228759765625, 3247.05908203125, 4.040158271789550781, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1364, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2718.8994140625, -1758.33447265625, 3230.503173828125, 2.861298322677612304, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1365, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2815.41064453125, -1820.2919921875, 3318.885009765625, 2.475987911224365234, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1366, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2741.40966796875, -1873.96875, 3238.752685546875, 2.073815345764160156, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1367, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2640.62158203125, -1777.204833984375, 3230.459228515625, 2.194861173629760742, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1368, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2798.73095703125, -1782.6666259765625, 3231.723388671875, 4.784269332885742187, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1369, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2784.5634765625, -1765.056396484375, 3230.502197265625, 3.624736785888671875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1370, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2801.237060546875, -1789.0660400390625, 3231.775390625, 4.005843639373779296, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1371, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2815.736328125, -1835.1837158203125, 3250.57763671875, 4.151471614837646484, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1372, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.643310546875, -1800.140625, 3232.06005859375, 2.46091628074645996, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1373, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2761.653564453125, -1764.0625, 3231.394287109375, 4.590629100799560546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1374, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2754.891845703125, -1755.0562744140625, 3231.24462890625, 4.606884002685546875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1375, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2726.064208984375, -1750.216064453125, 3230.53857421875, 4.712854385375976562, 120, 10, 0, 10679, 0, 1, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1376, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2700.388671875, -1748.981201171875, 3232.409912109375, 4.217457294464111328, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1377, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2809.866455078125, -1813.421875, 3240.055419921875, 5.278681278228759765, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1378, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2687.048095703125, -1756.517333984375, 3233.4462890625, 3.116997480392456054, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1379, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2793.55126953125, -1787.93359375, 3231.3173828125, 3.829896450042724609, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1380, 169063, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2788.3916015625, -1790.9896240234375, 3230.921630859375, 0.395466625690460205, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169063 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1381, 169068, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2757.639892578125, -1757.201416015625, 3231.18603515625, 1.052136063575744628, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169068 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1382, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2799.760498046875, -1787.5, 3231.760498046875, 5.046422004699707031, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1383, 161016, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2674.15283203125, -1645.4930419921875, 3252.09423828125, 3.812935113906860351, 120, 0, 0, 60120, 0, 0, 0, 0, 0, 36839), -- 161016 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1384, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2814.91259765625, -1812.4161376953125, 3250.18408203125, 0.119794823229312896, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1385, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2833.0830078125, -1838.042724609375, 3246.493408203125, 1.855854392051696777, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1386, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2817.638916015625, -1899.1180419921875, 3234.484375, 5.88080596923828125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1387, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2756.241455078125, -1933.52734375, 3248.326171875, 0.89858400821685791, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1388, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2828.50732421875, -1841.1015625, 3249.40771484375, 2.66763472557067871, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1389, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2806.1103515625, -1781.6114501953125, 3232.549560546875, 0.441817015409469604, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1390, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2820.281494140625, -1841.3038330078125, 3247.24462890625, 1.040564179420471191, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1391, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2810.86962890625, -1764.0106201171875, 3232.811279296875, 3.397565841674804687, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1392, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2825.387939453125, -1880.8489990234375, 3234.964111328125, 3.418991804122924804, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1393, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2841.172607421875, -1818.5775146484375, 3254.8759765625, 2.562477827072143554, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1394, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2842.174560546875, -1852.52783203125, 3237.9453125, 3.62628793716430664, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1395, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2829.833251953125, -1867.978759765625, 3232.689697265625, 0.74740678071975708, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1396, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2827.761474609375, -1808.2354736328125, 3249.26806640625, 2.491396427154541015, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1397, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2836.74853515625, -1836.43212890625, 3251.44873046875, 5.551857948303222656, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1398, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2822.951416015625, -1900.5035400390625, 3234.671875, 2.541856288909912109, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1399, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2809.982421875, -1756.421875, 3232.953125, 3.217054128646850585, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1400, 169103, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2846.248291015625, -1807.3194580078125, 3242.80029296875, 1.041137218475341796, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169103 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1401, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2848.913818359375, -1817.1927490234375, 3247.03662109375, 4.894731521606445312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1402, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2841.65087890625, -1805.76513671875, 3245.15185546875, 0.923214077949523925, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1403, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2831.25, -1772.916015625, 3230.92431640625, 4.032776832580566406, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1404, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2850.964599609375, -1788.9970703125, 3232.9208984375, 1.391204714775085449, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1405, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2845.843017578125, -1781.576416015625, 3232.54931640625, 0.665659308433532714, 120, 10, 0, 10679, 0, 1, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1406, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2862.232666015625, -1810.310791015625, 3237.730712890625, 0.85355311632156372, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1407, 168972, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2845.434814453125, -1899.6597900390625, 3235.063232421875, 2.437199831008911132, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 168972 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1408, 167273, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2849.09716796875, -1899.095458984375, 3235.229736328125, 5.853693485260009765, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167273 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1409, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2827.28125, -1756.5347900390625, 3230.921630859375, 5.788380622863769531, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1410, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2818.45703125, -1748.52734375, 3231.828369140625, 2.060436248779296875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1411, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2872.119140625, -1851.603515625, 3235.216064453125, 2.904907703399658203, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1412, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2870.049560546875, -1855.079833984375, 3235.75390625, 1.15758979320526123, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1413, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2774.216064453125, -1836.7916259765625, 3235.954833984375, 0.587330341339111328, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1414, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2693.725830078125, -1848.892333984375, 3246.0400390625, 2.134203910827636718, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1415, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2761.57666015625, -1734.1212158203125, 3231.894287109375, 3.084902048110961914, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1416, 169063, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2734.2978515625, -1878.34033203125, 3240.57421875, 1.999355435371398925, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169063 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1417, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2759.587646484375, -1929.3228759765625, 3247.05908203125, 4.040202140808105468, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1418, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2755.809814453125, -1934.0694580078125, 3248.190673828125, 0.497859328985214233, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1419, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2628.327392578125, -1889.0052490234375, 3234.798828125, 0.172207847237586975, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1420, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2741.40966796875, -1873.96875, 3238.752685546875, 2.073815345764160156, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1421, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2715.15966796875, -1731.3489990234375, 3230.510498046875, 4.387000083923339843, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1422, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2659.349853515625, -1747.6075439453125, 3232.218994140625, 3.434920787811279296, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1423, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2610.216064453125, -1792.255859375, 3232.00048828125, 5.954596996307373046, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1424, 160479, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2623.71875, -1767.26220703125, 3230.614501953125, 3.29991316795349121, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 160479 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1425, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2639.154541015625, -1775.6666259765625, 3230.459716796875, 0.457131057977676391, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1426, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2682.828125, -1737.6422119140625, 3236.5126953125, 3.87828993797302246, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1427, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2674.14208984375, -1739.923095703125, 3235.84521484375, 2.141781568527221679, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1428, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2640.7587890625, -1773.73095703125, 3230.458740234375, 2.544906139373779296, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1429, 165366, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2678.314208984375, -1734.1927490234375, 3236.09375, 5.301975727081298828, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 165366 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1430, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2699.614501953125, -1730.1690673828125, 3231.48779296875, 1.64278411865234375, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1431, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2681.26123046875, -1744.65625, 3236.28515625, 1.532701373100280761, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1432, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2651.875, -1744.7728271484375, 3231.0966796875, 0.011718213558197021, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1433, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2704.00439453125, -1826.0816650390625, 3237.189208984375, 2.079010009765625, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1434, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2724.819091796875, -1728.00390625, 3231.010986328125, 5.799435615539550781, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1435, 169088, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2726.546875, -1728.93408203125, 3231.251708984375, 0.268054604530334472, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169088 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1436, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2651.982421875, -1735.232421875, 3231.09130859375, 1.421358585357666015, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1437, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2616.65478515625, -1768.3900146484375, 3231.2314453125, 0.15832027792930603, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1438, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2616.68994140625, -1768.674560546875, 3231.23876953125, 6.086245536804199218, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1439, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2617.070068359375, -1764.5572509765625, 3230.82373046875, 5.89679574966430664, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1440, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2698.40576171875, -1721.16259765625, 3230.494873046875, 2.903660774230957031, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1441, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2616.3896484375, -1770.5767822265625, 3231.5029296875, 0.207647636532783508, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1442, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2663.37646484375, -1722.0250244140625, 3232.13232421875, 5.482975006103515625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1443, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2729.85595703125, -1717.65625, 3231.135498046875, 5.154378890991210937, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1444, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2760.40478515625, -1727.1162109375, 3231.895751953125, 1.24839639663696289, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1445, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2765.6650390625, -1724.107666015625, 3231.830078125, 4.878940582275390625, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1446, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2766.537353515625, -1726.2430419921875, 3231.9072265625, 3.229628801345825195, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1447, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2770.36279296875, -1724.763916015625, 3231.712646484375, 3.617299318313598632, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1448, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2787.2041015625, -1727.2265625, 3231.09130859375, 0.460723638534545898, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1449, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2823.978271484375, -1745.2569580078125, 3231.76904296875, 5.292632579803466796, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1450, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2822.009521484375, -1746.513916015625, 3231.83154296875, 0.217814624309539794, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1451, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.786376953125, -1731.84033203125, 3231.365966796875, 1.8118363618850708, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1452, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.92529296875, -1725.7525634765625, 3232.064453125, 3.732439756393432617, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1453, 169117, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2783.23095703125, -1721.8819580078125, 3230.921630859375, 1.455354094505310058, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169117 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1454, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2830.16943359375, -1736.6666259765625, 3230.855224609375, 4.607617378234863281, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1455, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2834.896484375, -1730.728515625, 3231.07275390625, 4.81143045425415039, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1456, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2815.473876953125, -1720.83837890625, 3232.55029296875, 0.023372234776616096, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1457, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2859.64697265625, -1759.7337646484375, 3231.52001953125, 2.325817108154296875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1458, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2794.870849609375, -1705.265625, 3233.636474609375, 3.875859737396240234, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1459, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2852.717529296875, -1738.9661865234375, 3230.550048828125, 5.676116943359375, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1460, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2859.698486328125, -1750, 3231.5263671875, 3.141592741012573242, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1461, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2885.736083984375, -1810.0347900390625, 3232.100830078125, 3.145551443099975585, 120, 10, 0, 10679, 0, 1, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1462, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2883.9501953125, -1814.4173583984375, 3232.03662109375, 5.500917434692382812, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1463, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2860.978759765625, -1745.7049560546875, 3231.17822265625, 3.998633384704589843, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1464, 169063, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2788.3916015625, -1790.9896240234375, 3231.0048828125, 0.395466625690460205, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169063 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1465, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2726.525146484375, -1827.8524169921875, 3237.2041015625, 5.030045032501220703, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1466, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2870.572998046875, -1748.4271240234375, 3231.769287109375, 3.254249334335327148, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1467, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2865.04052734375, -1733.145751953125, 3231.355224609375, 1.145869135856628417, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1468, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2899.0634765625, -1839.16796875, 3235.552978515625, 6.170399188995361328, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1469, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2897.506103515625, -1789.1910400390625, 3231.7978515625, 3.229452371597290039, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1470, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2854.932373046875, -1697.873046875, 3231.609375, 1.246615886688232421, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1471, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2814.503662109375, -1677.1461181640625, 3231.23828125, 5.075692653656005859, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1472, 165366, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2808.1875, -1699.1910400390625, 3233.92431640625, 4.53231048583984375, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 165366 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1473, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2865.60302734375, -1712.6866455078125, 3231.48779296875, 3.859045982360839843, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1474, 169063, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2846.8681640625, -1685.5816650390625, 3231.141357421875, 5.850583553314208984, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169063 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1475, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2847.2744140625, -1684.896484375, 3231.185791015625, 0, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1476, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2846.20751953125, -1707.265625, 3231.57275390625, 3.476916790008544921, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1477, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2897.3837890625, -1738.1978759765625, 3231.873046875, 3.073719501495361328, 120, 10, 0, 10679, 0, 1, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1478, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2774.26904296875, -1688.18408203125, 3230.582763671875, 2.010508060455322265, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1479, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2775.232666015625, -1684.8697509765625, 3231.427490234375, 3.229628801345825195, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1480, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2836.85595703125, -1685.0875244140625, 3231.0498046875, 6.127751827239990234, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1481, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2808.189453125, -1701.846435546875, 3234.095458984375, 4.82443094253540039, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1482, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2908.2119140625, -1763.064208984375, 3232.111328125, 3.185055017471313476, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1483, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2773.333251953125, -1685.4913330078125, 3231.29150390625, 0.104640394449234008, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1484, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2849.91064453125, -1687.7742919921875, 3231.34814453125, 3.229628801345825195, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1485, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2855.22119140625, -1702.6260986328125, 3231.63671875, 1.883854031562805175, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1486, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2778.6328125, -1686.640625, 3230.90380859375, 3.169352054595947265, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1487, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2875, -1696.353515625, 3232.8671875, 5.354069709777832031, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1488, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2915.23779296875, -1775.05908203125, 3232.385986328125, 1.921741962432861328, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1489, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2912.00634765625, -1747.486572265625, 3233.43505859375, 1.778342843055725097, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1490, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2881.741943359375, -1694.2138671875, 3233.07421875, 5.510498046875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1491, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2915.27587890625, -1770.9871826171875, 3232.68017578125, 0.095824599266052246, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1492, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2827.87158203125, -1660.1163330078125, 3239.560546875, 1.573487758636474609, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1493, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2900.768798828125, -1702.027099609375, 3231.929931640625, 2.675356864929199218, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1494, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2909.2265625, -1715.625, 3232.026123046875, 2.999430656433105468, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1495, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2827.28125, -1756.5347900390625, 3231.0048828125, 5.788380622863769531, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1496, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2832.234375, -1662.0029296875, 3239.5712890625, 4.869206428527832031, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1497, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2839.393310546875, -1660.390380859375, 3241.88525390625, 4.781749248504638671, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1498, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2733.654541015625, -1698.0086669921875, 3231.25634765625, 0.467463076114654541, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1499, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2750.85791015625, -1681.50634765625, 3233.427734375, 5.664298534393310546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839); -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)

REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1500, 160883, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2856.951416015625, -1660.91845703125, 3255.524169921875, 4.304347515106201171, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 160883 (Area: The Spearhead - Difficulty: 0) (Auras: 313127 - Abomination - Visual - Extra - Maps)
(@CGUID+1501, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2821.353515625, -1646.875, 3247.10302734375, 3.383309841156005859, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1502, 160884, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2858.838623046875, -1657.96875, 3254.2314453125, 3.581765174865722656, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 160884 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1503, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2791.9091796875, -1641.712890625, 3253.614501953125, 5.472295761108398437, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1504, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2726.43408203125, -1690.6978759765625, 3234.23779296875, 0.385281085968017578, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1505, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2726.4287109375, -1691.5584716796875, 3233.8251953125, 4.864351749420166015, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1506, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.859375, -1647.248291015625, 3252.718505859375, 2.886987209320068359, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+1507, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2729.69970703125, -1674.1868896484375, 3260.521728515625, 2.59043121337890625, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1508, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2731.38623046875, -1663.22021484375, 3254.4228515625, 1.290208816528320312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1509, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2739.6884765625, -1649.4896240234375, 3256.19580078125, 5.990007400512695312, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1510, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2740.76708984375, -1659.7794189453125, 3254.314697265625, 3.80432748794555664, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1511, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2744.395263671875, -1644.762451171875, 3283.92822265625, 5.186009407043457031, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1512, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2743.224609375, -1657.0631103515625, 3254.784423828125, 3.51777195930480957, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1513, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2758.479248046875, -1645.236083984375, 3248.175537109375, 1.301566123962402343, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1514, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2891.968017578125, -1688.375, 3233.4697265625, 4.069571495056152343, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1515, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2699.5517578125, -1700.3045654296875, 3231.12841796875, 3.754654407501220703, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1516, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2802.95751953125, -1623.9432373046875, 3253.6298828125, 3.691948890686035156, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1517, 169117, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2783.23095703125, -1721.8819580078125, 3231.0048828125, 1.455354094505310058, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169117 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1518, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2783.548828125, -1620.7701416015625, 3253.724853515625, 4.95770263671875, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1519, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2865.70166015625, -1649.1688232421875, 3253.70458984375, 2.808237075805664062, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1520, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2913.2138671875, -1654.69580078125, 3244.7451171875, 5.382098197937011718, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1521, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2851.797607421875, -1598.319091796875, 3262.923095703125, 3.100781202316284179, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1522, 169068, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2861.970458984375, -1601.7447509765625, 3264.672607421875, 4.698396682739257812, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169068 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1523, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2881.48681640625, -1632.744140625, 3253.37255859375, 3.231545448303222656, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1524, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2858.03564453125, -1601.0003662109375, 3265.720458984375, 4.876462936401367187, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1525, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2911.12109375, -1645.1907958984375, 3253.403564453125, 5.629814624786376953, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1526, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2837.634033203125, -1618.0859375, 3253.18359375, 3.041826725006103515, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1527, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2846.70703125, -1618.064453125, 3253.54150390625, 6.148975849151611328, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1528, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2921.3212890625, -1741.272705078125, 3234.805419921875, 0.117662623524665832, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1529, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2924.089111328125, -1726.2789306640625, 3234.93505859375, 0.279104799032211303, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1530, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2928.657958984375, -1725.953125, 3234.73876953125, 3.658900737762451171, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1531, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2801.041015625, -1612.5, 3254.91845703125, 1.231984615325927734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1532, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2809.720703125, -1614.0546875, 3254.918701171875, 0.992538928985595703, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1533, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2907.3837890625, -1654.0865478515625, 3252.91650390625, 2.616593360900878906, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1534, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2810.026123046875, -1603.920166015625, 3256.337158203125, 3.243003368377685546, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1535, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2804.975830078125, -1604.43408203125, 3257.322021484375, 5.948276996612548828, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1536, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2841.07861328125, -1593.2332763671875, 3255.4794921875, 1.818877935409545898, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction, 319935 - Disease Cloud)
(@CGUID+1537, 169063, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2846.8681640625, -1685.5816650390625, 3231.224609375, 5.850583553314208984, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169063 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1538, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2840.017333984375, -1589.04345703125, 3254.941162109375, 5.086214542388916015, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1539, 160996, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2921.438232421875, -1754.5206298828125, 3233.0107421875, 2.165841102600097656, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 160996 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1540, 165644, 2222, 11462, 11467, '0', '0', 0, 0, 0, 3209.48583984375, -1505.2764892578125, 3170.185546875, 2.359170436859130859, 120, 10, 0, 589550, 0, 1, 0, 0, 0, 36839), -- 165644 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1541, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2934.9384765625, -1742.32861328125, 3234.5986328125, 2.53030705451965332, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (Auras: 326019 - 9.0 Carry Ballista Ammo)
(@CGUID+1542, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2679.4912109375, -1703.1529541015625, 3231.115966796875, 2.35964512825012207, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1543, 169117, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2692.807373046875, -1693.2413330078125, 3231.278564453125, 5.805405616760253906, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169117 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1544, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2729.043212890625, -1635.286376953125, 3255.700927734375, 3.447796106338500976, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1545, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2731.753662109375, -1635.1669921875, 3258.720703125, 1.370317459106445312, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1546, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2727.18603515625, -1638.370361328125, 3259.5283203125, 0.447046726942062377, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1547, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2660.861083984375, -1715.02294921875, 3230.796875, 2.944963455200195312, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1548, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2696.885498046875, -1634.71533203125, 3253.432373046875, 0.210019543766975402, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (Auras: 328701 - 9.0 Carry Maldraxxus Bomb) (possible waypoints or random movement)
(@CGUID+1549, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2649.17236328125, -1672.5355224609375, 3234.082275390625, 5.039353847503662109, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1550, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2737.5908203125, -1605.12109375, 3253.7001953125, 5.164720535278320312, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1551, 160976, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2700.882080078125, -1625.60595703125, 3257.42041015625, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 160976 (Area: The Spearhead - Difficulty: 0) (Auras: 292177 - Turn In Circle Visual)
(@CGUID+1552, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2696.1943359375, -1628.848876953125, 3253.322021484375, 3.028845787048339843, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (Auras: 328701 - 9.0 Carry Maldraxxus Bomb) (possible waypoints or random movement)
(@CGUID+1553, 161026, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2702.04248046875, -1626.7117919921875, 3253.60986328125, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 161026 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1554, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2644.626708984375, -1674.4478759765625, 3233.608642578125, 4.66855621337890625, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1555, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2643.880126953125, -1677.189208984375, 3233.104248046875, 2.19888472557067871, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1556, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2764.872314453125, -1603.52783203125, 3263.40478515625, 0, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1557, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2644.66845703125, -1661.05908203125, 3235.23486328125, 3.173815011978149414, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1558, 169096, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2733.654541015625, -1698.0086669921875, 3231.339599609375, 0.467463076114654541, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169096 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1559, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2637.979248046875, -1697.3472900390625, 3230.631103515625, 3.229628801345825195, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1560, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2632.373046875, -1719.3612060546875, 3231.806640625, 2.555911540985107421, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1561, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2641.709228515625, -1661.142333984375, 3235.103759765625, 1.832332015037536621, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1562, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2639.267333984375, -1659.6771240234375, 3235.444091796875, 5.890241146087646484, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1563, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2623.123779296875, -1688.6195068359375, 3230.883056640625, 1.267838478088378906, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1564, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2623.225341796875, -1687.928466796875, 3231.0771484375, 1.24379730224609375, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1565, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2623.928466796875, -1685.965087890625, 3231.25537109375, 4.398369312286376953, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1566, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2660.764892578125, -1622.7115478515625, 3250.701904296875, 3.684566497802734375, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1567, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2625.032470703125, -1682.5701904296875, 3232.092529296875, 4.397980690002441406, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1568, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2629.386474609375, -1719.893310546875, 3232.00390625, 1.912091255187988281, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1569, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2629.878173828125, -1721.2684326171875, 3231.890869140625, 5.054229736328125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1570, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2624.404052734375, -1684.523681640625, 3231.56396484375, 1.257075190544128417, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1571, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2622.203857421875, -1684.4522705078125, 3231.960205078125, 3.99187779426574707, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1572, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2622.559814453125, -1687.6820068359375, 3231.302734375, 1.042277455329895019, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1573, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2633.226806640625, -1666.606201171875, 3235.0869140625, 2.330982446670532226, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1574, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2640.346435546875, -1623.9722900390625, 3246.933837890625, 6.185529232025146484, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1575, 160424, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2609.794189453125, -1714.0260009765625, 3234.01611328125, 5.654284954071044921, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1576, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2701.59521484375, -1592.3897705078125, 3253.675537109375, 3.196004390716552734, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1577, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2631.20361328125, -1624.6273193359375, 3244.969482421875, 5.059489727020263671, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1578, 160424, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2613.4150390625, -1725.109375, 3232.630859375, 1.389381170272827148, 120, 0, 0, 21357, 0, 0, 0, 0, 0, 36839), -- 160424 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1579, 168946, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2578.0625, -1537.7135009765625, 3277.970703125, 4.81413125991821289, 120, 0, 0, 13510, 0, 0, 0, 0, 0, 36839), -- 168946 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1580, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2609.2099609375, -1720.509033203125, 3233.8486328125, 3.492365598678588867, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1581, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2642.84228515625, -1602.4564208984375, 3250.71337890625, 5.257603645324707031, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1582, 160479, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2625.03271484375, -1590.927001953125, 3251.36767578125, 3.432930707931518554, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 160479 (Area: The Spearhead - Difficulty: 0) (Auras: 320013 - Massacre)
(@CGUID+1583, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2611.561767578125, -1616.7552490234375, 3249.601806640625, 0.943973422050476074, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1584, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2611.611572265625, -1622.3162841796875, 3248.843994140625, 6.118297100067138671, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1585, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2649.512451171875, -1583.549560546875, 3250.782958984375, 0.853171586990356445, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1586, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2611.978515625, -1622.916015625, 3248.576904296875, 3.925114870071411132, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1587, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2758.7978515625, -1599.6192626953125, 3262.8642578125, 4.029170036315917968, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1588, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2624.767822265625, -1607.4530029296875, 3249.288330078125, 0.921877145767211914, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1589, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2592.632568359375, -1650.800537109375, 3264.030517578125, 5.063823699951171875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1590, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2592.964111328125, -1652.5399169921875, 3264.380859375, 4.879351615905761718, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1591, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2616.8271484375, -1602.670166015625, 3250.4794921875, 6.241477012634277343, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1592, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2621.752197265625, -1594.705810546875, 3251.30029296875, 2.603687286376953125, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1593, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2776.08544921875, -1600.0943603515625, 3259.805908203125, 3.272853374481201171, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1594, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2618.63427734375, -1592.845703125, 3251.813232421875, 0.29117622971534729, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1595, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2635.60498046875, -1569.3143310546875, 3252.9296875, 3.151534318923950195, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1596, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2630.202392578125, -1569.3680419921875, 3253.88134765625, 5.88080596923828125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1597, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2629.9931640625, -1574.34375, 3253.098876953125, 2.541856288909912109, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1598, 160948, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2702.0390625, -1626.69970703125, 3253.63330078125, 4.563908100128173828, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 160948 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1599, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2719.78564453125, -1595.263916015625, 3253.65380859375, 3.955832958221435546, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1600, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2686.997314453125, -1595.263916015625, 3253.65380859375, 2.61985015869140625, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1601, 160978, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2782.22216796875, -1645.876708984375, 3273.958984375, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 160978 (Area: The Spearhead - Difficulty: 0) (Auras: 292177 - Turn In Circle Visual)
(@CGUID+1602, 160948, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2702.0390625, -1626.69970703125, 3253.716552734375, 4.563908100128173828, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 160948 (Area: The Spearhead - Difficulty: 0) (Auras: 329598 - Explosive Charge)
(@CGUID+1603, 161027, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2783.294189453125, -1645.123291015625, 3253.521728515625, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 161027 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1604, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2814.576416015625, -1572.23095703125, 3257.43701171875, 3.723912954330444335, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1605, 169395, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2818.630126953125, -1557.673583984375, 3256.62890625, 5.198146343231201171, 120, 10, 0, 2848, 0, 1, 0, 0, 0, 36839), -- 169395 (Area: The Spearhead - Difficulty: 0) (Auras: 331874 - Touch of Plague) (possible waypoints or random movement)
(@CGUID+1606, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.5078125, -1604.7066650390625, 3256.239013671875, 2.61985015869140625, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1607, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2812.41845703125, -1605.123291015625, 3255.708984375, 3.867728233337402343, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1608, 160954, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2783.30908203125, -1645.1197509765625, 3253.5205078125, 4.563908100128173828, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 160954 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1609, 160979, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2864.015625, -1645.4010009765625, 3280.412353515625, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 160979 (Area: The Spearhead - Difficulty: 0) (Auras: 292177 - Turn In Circle Visual)
(@CGUID+1610, 161028, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2866.725830078125, -1647.828125, 3253.67578125, 0, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 161028 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1611, 70483, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2783.30908203125, -1645.1197509765625, 3253.603759765625, 4.563908100128173828, 120, 0, 0, 118, 0, 0, 0, 0, 0, 36839), -- 160954 (Area: The Spearhead - Difficulty: 0) (Auras: 329598 - Explosive Charge)
(@CGUID+1612, 169999, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2767.413330078125, -1406.28125, 3229.43017578125, 2.569593667984008789, 120, 0, 0, 707460, 2434, 0, 0, 0, 0, 36839), -- 169999 (Area: Ossein Foundry - Difficulty: 0) (Auras: 315067 - Ghost)
(@CGUID+1613, 169395, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2774.9033203125, -1464.20458984375, 3252.26513671875, 0.793685317039489746, 120, 0, 0, 2848, 0, 0, 0, 0, 0, 36839), -- 169395 (Area: Ossein Foundry - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+1614, 174024, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2858.201416015625, -1394.0625, 3214.05517578125, 4.209084510803222656, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 174024 (Area: Ossein Foundry - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1615, 169395, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2784.05224609375, -1503.5845947265625, 3257.912109375, 4.90439605712890625, 120, 0, 0, 2848, 0, 0, 0, 0, 0, 36839), -- 169395 (Area: Ossein Foundry - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+1616, 169395, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2775.04296875, -1475.040283203125, 3254.992919921875, 0.065878823399543762, 120, 0, 0, 2848, 0, 0, 0, 0, 0, 36839), -- 169395 (Area: Ossein Foundry - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+1617, 174024, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2831.771728515625, -1425.171875, 3262.799072265625, 2.782546281814575195, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 174024 (Area: Ossein Foundry - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1618, 169395, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2785.680419921875, -1492.4854736328125, 3256.177734375, 4.929775238037109375, 120, 0, 0, 2848, 0, 0, 0, 0, 0, 36839), -- 169395 (Area: Ossein Foundry - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+1619, 174024, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2891.692626953125, -1379.6011962890625, 3233.822265625, 1.227903604507446289, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 174024 (Area: Ossein Foundry - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1620, 169395, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2796.842529296875, -1507.9495849609375, 3258.07470703125, 0.47873041033744812, 120, 0, 0, 2848, 0, 0, 0, 0, 0, 36839), -- 169395 (Area: Ossein Foundry - Difficulty: 0) (Auras: 331874 - Touch of Plague)
(@CGUID+1621, 174024, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2852.107666015625, -1440.640625, 3213.332763671875, 2.669349193572998046, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 174024 (Area: Ossein Foundry - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1622, 169129, 2222, 11462, 12777, '0', '0', 0, 0, 0, 2788.60498046875, -1486.6319580078125, 3259.889892578125, 3.723912954330444335, 120, 0, 0, 7515, 0, 0, 0, 0, 0, 36839), -- 169129 (Area: Ossein Foundry - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1623, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1902.7847900390625, -3305.62841796875, 3247.519775390625, 1.96895754337310791, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1624, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1905.1197509765625, -3328.30029296875, 3257.256591796875, 4.80870676040649414, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1625, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2068.02783203125, -3474.61279296875, 3271.9404296875, 5.0815582275390625, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk)
(@CGUID+1626, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2028.7864990234375, -3329.3837890625, 3270.2021484375, 4.255447864532470703, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1627, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1874.857666015625, -3303.635498046875, 3216.779052734375, 3.969291448593139648, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1628, 168315, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2376.860595703125, -3531.725830078125, 3558.52734375, 0.511709988117218017, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 168315 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1629, 169696, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1998.1510009765625, -3441.3525390625, 3258.070068359375, 5.15737771987915039, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 169696 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1630, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1961.9757080078125, -3212.8994140625, 3256.196044921875, 4.334368705749511718, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk, 328964 - Slimed Cosmetic)
(@CGUID+1631, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1980.439208984375, -3455.845458984375, 3261.732666015625, 4.425445556640625, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1632, 168574, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1984.9791259765625, -3440.779541015625, 3258.883544921875, 1.806345939636230468, 7200, 0, 0, 37800, 0, 0, 0, 0, 0, 36839), -- 168574 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1633, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1894.0399169921875, -3318.01220703125, 3254.243408203125, 3.813268423080444335, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1634, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2081.116455078125, -3454.385498046875, 3269.701171875, 2.363879919052124023, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1635, 174877, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1851.9600830078125, -3163.185791015625, 3229.16796875, 3.927038431167602539, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 174877 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1636, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1912.76220703125, -3266.619873046875, 3228.631591796875, 3.12309122085571289, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1637, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1947.986083984375, -3330.90625, 3255.77099609375, 2.035583972930908203, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1638, 168153, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1960.4879150390625, -3454.342041015625, 3257.02001953125, 1.636479496955871582, 7200, 0, 0, 44100, 0, 0, 0, 0, 0, 36839), -- 168153 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1639, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1962.392333984375, -3447.786376953125, 3256.8212890625, 3.81445622444152832, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1640, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2047.3326416015625, -3347.6337890625, 3281.52587890625, 1.431530475616455078, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1641, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2082.53125, -3477.307373046875, 3271.70361328125, 3.386830091476440429, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1642, 169696, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1952.3211669921875, -3373.329833984375, 3257.7109375, 1.221040725708007812, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 169696 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1643, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1818.2083740234375, -3290.407958984375, 3216.537841796875, 0.423091083765029907, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1644, 168578, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1992.3941650390625, -3438.536376953125, 3259.715576171875, 3.116389274597167968, 7200, 0, 0, 37800, 0, 0, 0, 0, 0, 36839), -- 168578 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1645, 168364, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1853.923583984375, -3194.489501953125, 3211.8505859375, 2.229368448257446289, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168364 (Area: Plaguefall - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1646, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1892.984375, -3286.076416015625, 3224.45947265625, 4.929356575012207031, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1647, 168153, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1910.220458984375, -3311.814208984375, 3250.931640625, 0.625703275203704833, 7200, 0, 0, 44100, 0, 0, 0, 0, 0, 36839), -- 168153 (Area: Plaguefall - Difficulty: 0) (Auras: 327881 - Cosmetic - Sleep Zzz)
(@CGUID+1648, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1949.5677490234375, -3497.920166015625, 3277.13330078125, 0.78539818525314331, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1649, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1892.0625, -3292.40625, 3225.18798828125, 3.707114934921264648, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1650, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1978.28125, -3189.157958984375, 3264.018310546875, 5.378468036651611328, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 328964 - Slimed Cosmetic)
(@CGUID+1651, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1967.9757080078125, -3450.036376953125, 3260.1884765625, 1.088284254074096679, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1652, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1978.796875, -3458.361083984375, 3260.016845703125, 3.81445622444152832, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1653, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1925.892333984375, -3287.046875, 3247.8681640625, 0.769082546234130859, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1654, 174877, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1874.203125, -3301.90283203125, 3217.1123046875, 1.337127327919006347, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 174877 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1655, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1982.5069580078125, -3457.944580078125, 3261.15673828125, 0.652186810970306396, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1656, 169218, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1816.545166015625, -3450.86279296875, 3216.611083984375, 1.331338763236999511, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 169218 (Area: Plaguefall - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1657, 168580, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1998.4288330078125, -3334.1962890625, 3257.222412109375, 5.497786998748779296, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168580 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1658, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2058.9619140625, -3401.104248046875, 3261.142333984375, 0.78539818525314331, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1659, 172335, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1842.173583984375, -3185.932373046875, 3217.6171875, 1.576022982597351074, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 172335 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death)
(@CGUID+1660, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1967.0867919921875, -3453.282958984375, 3259.23876953125, 3.799348831176757812, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1661, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1962.9254150390625, -3214.401123046875, 3255.8095703125, 2.906078577041625976, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327484 - Plague Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1662, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2001.6632080078125, -3496.3369140625, 3259.882080078125, 5.323053836822509765, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1663, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1958.46875, -3436.895751953125, 3261.94873046875, 2.809500694274902343, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1664, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2102.84375, -3415.214111328125, 3269.821044921875, 3.022488117218017578, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1665, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2088.838623046875, -3474.682373046875, 3270.796875, 4.301310539245605468, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1666, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1949.234375, -3220.052001953125, 3235.588623046875, 3.12309122085571289, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1667, 168314, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2323.327392578125, -3808.75146484375, 3731.309814453125, 1.845441699028015136, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 168314 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1668, 168298, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1232.63037109375, -3739.388916015625, 3217.98095703125, 2.409918069839477539, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 168298 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1669, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1989.7568359375, -3264.505126953125, 3250.109130859375, 5.770772933959960937, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1670, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1851.657958984375, -3162.210205078125, 3229.111328125, 5.610337734222412109, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1671, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1920.4869384765625, -3232.303955078125, 3215.96875, 4.438690662384033203, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: 0) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1672, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1980.404541015625, -3459.07470703125, 3260.15087890625, 0.350313812494277954, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1673, 168310, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1965.704833984375, -3346.085205078125, 3272.108642578125, 2.160178661346435546, 7200, 0, 0, 44100, 0, 0, 0, 0, 0, 36839), -- 168310 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1674, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1981.3177490234375, -3451.725830078125, 3258.472412109375, 0.977444589138031005, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1675, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1929.649169921875, -3371.843505859375, 3268.829833984375, 0.196887299418449401, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1676, 168572, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1977.4617919921875, -3409.713623046875, 3258.116455078125, 1.157851934432983398, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168572 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 323486 - Dual Wield)
(@CGUID+1677, 169696, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1981.0225830078125, -3402.625, 3258.80517578125, 4.082405567169189453, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 169696 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1678, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1968.921875, -3453.130126953125, 3259.37451171875, 3.110103368759155273, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1679, 168298, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1343.383544921875, -3987.20361328125, 3167.654541015625, 4.697522163391113281, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 168298 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1680, 168574, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1944.517333984375, -3414.975830078125, 3260.449951171875, 3.144681692123413085, 7200, 0, 0, 37800, 0, 0, 0, 0, 0, 36839), -- 168574 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1681, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1981.41845703125, -3274.663330078125, 3249.43017578125, 0.78539818525314331, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1682, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1954.9635009765625, -3212.814208984375, 3254.246826171875, 3.076366424560546875, 7200, 10, 0, 6300, 0, 1, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk, 328963 - Vomit) (possible waypoints or random movement)
(@CGUID+1683, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1970.8541259765625, -3453.75341796875, 3259.569580078125, 5.547232627868652343, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1684, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2003.29150390625, -3334.46728515625, 3257.486328125, 4.08971261978149414, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1685, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1961.420166015625, -3453.307373046875, 3257.15869140625, 6.206200599670410156, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1686, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1969.5069580078125, -3455.279541015625, 3259.23291015625, 1.088284254074096679, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1687, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1976.7725830078125, -3458.94970703125, 3259.64892578125, 3.81445622444152832, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1688, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2087.942626953125, -3416.458251953125, 3273.68994140625, 6.185618877410888671, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1689, 168153, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1998.203125, -3388.928955078125, 3263.396728515625, 5.576921939849853515, 7200, 0, 0, 44100, 0, 0, 0, 0, 0, 36839), -- 168153 (Area: Plaguefall - Difficulty: 0) (Auras: 327881 - Cosmetic - Sleep Zzz)
(@CGUID+1690, 169696, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1940.8489990234375, -3402.3212890625, 3258.43408203125, 5.129292011260986328, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 169696 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1691, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1976.8489990234375, -3461.479248046875, 3259.68701171875, 3.81445622444152832, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1692, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1955.7291259765625, -3327.4306640625, 3256.275146484375, 2.035583972930908203, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1693, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1932.132080078125, -3411.04638671875, 3269.21728515625, 2.034273624420166015, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0) (Auras: )
(@CGUID+1694, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1872.2882080078125, -3307.916748046875, 3216.983642578125, 0.633313536643981933, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1695, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1919.920166015625, -3258.291748046875, 3226.832275390625, 1.66814124584197998, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk)
(@CGUID+1696, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1856.25, -3172.723876953125, 3223.1513671875, 0.527224957942962646, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1697, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2006.037841796875, -3408.06494140625, 3264.389404296875, 2.131832122802734375, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0) (Auras: )
(@CGUID+1698, 168572, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1957.9600830078125, -3370.8994140625, 3258.02783203125, 3.299662113189697265, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168572 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 323486 - Dual Wield)
(@CGUID+1699, 172336, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1866.390625, -3180.05908203125, 3217.73095703125, 1.251652121543884277, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 172336 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death)
(@CGUID+1700, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1927.0830078125, -3215.873291015625, 3228.18505859375, 2.49122929573059082, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk, 255051 - Vomit)
(@CGUID+1701, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1879.701416015625, -3287.416748046875, 3220.482666015625, 3.076366424560546875, 7200, 10, 0, 6300, 0, 1, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk) (possible waypoints or random movement)
(@CGUID+1702, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2021.7257080078125, -3318.717041015625, 3266.29833984375, 2.610754251480102539, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1703, 168578, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1974.8975830078125, -3404.859375, 3258.333251953125, 0.564472973346710205, 7200, 0, 0, 37800, 0, 0, 0, 0, 0, 36839), -- 168578 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1704, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1958.798583984375, -3442.37841796875, 3259.23486328125, 6.019904613494873046, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1705, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1939.6024169921875, -3467.623291015625, 3273.73828125, 5.352545738220214843, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1706, 172335, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1851.953125, -3284.770751953125, 3221.56591796875, 3.285216808319091796, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 172335 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death)
(@CGUID+1707, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1973.4271240234375, -3451.923583984375, 3263.075439453125, 4.696995258331298828, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1708, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1967.0885009765625, -3454.913330078125, 3259.11572265625, 1.424681425094604492, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1709, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1852.3541259765625, -3161.116455078125, 3229.200927734375, 6.246865749359130859, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1710, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1968.0069580078125, -3451.84375, 3259.407958984375, 5.624653816223144531, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1711, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2058.484375, -3353.260498046875, 3281.134765625, 5.193673610687255859, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1712, 169218, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1666.4271240234375, -3216.666748046875, 3215.8984375, 0.380371838808059692, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 169218 (Area: Plaguefall - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1713, 168153, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2085.79345703125, -3475.59375, 3272.064208984375, 4.670502185821533203, 7200, 0, 0, 44100, 0, 0, 0, 0, 0, 36839), -- 168153 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1714, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1982.6649169921875, -3447.407958984375, 3255.79345703125, 1.96895754337310791, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1715, 169843, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1884.65283203125, -3247.701416015625, 3215.79248046875, 3.375524759292602539, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169843 (Area: Plaguefall - Difficulty: 0) (Auras: 330738 - Test Swim Animation)
(@CGUID+1716, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1819.01220703125, -3287.49658203125, 3216.982666015625, 5.369243144989013671, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1717, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1990.7379150390625, -3188.072998046875, 3263.32861328125, 5.320889949798583984, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1718, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1977.7437744140625, -3385.854248046875, 3267.188720703125, 1.311792492866516113, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1719, 168965, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2372.395751953125, -3578.14404296875, 3592.62158203125, 2.320275306701660156, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 168965 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1720, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2039.7977294921875, -3361.3076171875, 3262.111572265625, 3.575521469116210937, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1721, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1969.9410400390625, -3198.2119140625, 3262.75048828125, 1.229967117309570312, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 328964 - Slimed Cosmetic)
(@CGUID+1722, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1909.782958984375, -3299.678955078125, 3247.1533203125, 4.142572402954101562, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1723, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1942.688720703125, -3427.83984375, 3267.563232421875, 1.612480044364929199, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0) (Auras: )
(@CGUID+1724, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1995.4373779296875, -3234.06103515625, 3260.755859375, 0.499089598655700683, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1725, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1915.6510009765625, -3225.951416015625, 3216.57470703125, 2.113110780715942382, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1726, 168364, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1853.013916015625, -3194.40625, 3211.93603515625, 2.193620204925537109, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168364 (Area: Plaguefall - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1727, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2090.625, -3445.685791015625, 3269.4130859375, 0.78539818525314331, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1728, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1941.5191650390625, -3232.970458984375, 3235.353759765625, 3.023139476776123046, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1729, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2052.507080078125, -3399.354248046875, 3263.278564453125, 0.753418922424316406, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1730, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1983.6978759765625, -3460.60595703125, 3254.7236328125, 3.549928665161132812, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1731, 168580, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2044.25, -3443.397705078125, 3258.0009765625, 1.832595705986022949, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168580 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328020 - Plagueborer Base)
(@CGUID+1732, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1921.5208740234375, -3297.90283203125, 3247.38623046875, 0.568988621234893798, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1733, 168364, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1699.7430419921875, -3266.06591796875, 3215.68798828125, 4.510493755340576171, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168364 (Area: Plaguefall - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1734, 163882, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2026.4097900390625, -3469.10595703125, 3260.265625, 1.835495829582214355, 7200, 0, 0, 56700, 0, 0, 0, 0, 0, 36839), -- 163882 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 18950 - Invisibility and Stealth Detection, 343918 - Oozing Slime, 320040 - Plagued Carrion)
(@CGUID+1735, 169218, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1725.126708984375, -3222.11279296875, 3217.562255859375, 5.309059619903564453, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 169218 (Area: Plaguefall - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1736, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2023.3348388671875, -3319.60791015625, 3268.49951171875, 2.554151535034179687, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1737, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2081.677001953125, -3472.65625, 3271.0732421875, 0.063569121062755584, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1738, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1980.7222900390625, -3453.907958984375, 3259.82421875, 5.356244564056396484, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1739, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1937.76220703125, -3217.420166015625, 3231.845703125, 4.161909103393554687, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1740, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1988.982177734375, -3398.266845703125, 3282.016845703125, 5.540711879730224609, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0) (Auras: )
(@CGUID+1741, 169696, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1984.359375, -3272.7587890625, 3249.67724609375, 4.637966156005859375, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 169696 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1742, 168314, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2287.627685546875, -3822.335205078125, 3863.94482421875, 2.338579416275024414, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 168314 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1743, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2086.0625, -3477.723876953125, 3271.9833984375, 1.043359875679016113, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1744, 168315, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2325.830078125, -3543.37841796875, 3580.180908203125, 0.787849247455596923, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 168315 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1745, 168580, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2094.244873046875, -3403.454833984375, 3268.32666015625, 1.534243345260620117, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168580 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328020 - Plagueborer Base)
(@CGUID+1746, 168153, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1977.8333740234375, -3375.46533203125, 3268.7890625, 0.625703275203704833, 7200, 0, 0, 44100, 0, 0, 0, 0, 0, 36839), -- 168153 (Area: Plaguefall - Difficulty: 0) (Auras: 327881 - Cosmetic - Sleep Zzz)
(@CGUID+1747, 172335, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1775.967041015625, -3209.9931640625, 3220.999267578125, 1.576022982597351074, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 172335 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death)
(@CGUID+1748, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1914.46875, -3262.482666015625, 3228.01953125, 0.984025239944458007, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1749, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1968.329833984375, -3455.064208984375, 3259.12353515625, 5.356244564056396484, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839); -- 163931 (Area: Plaguefall - Difficulty: 0)

REPLACE INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1750, 168364, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1699.0711669921875, -3265.291748046875, 3213.85595703125, 1.467610597610473632, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168364 (Area: Plaguefall - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1751, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1921.922119140625, -3402.581298828125, 3274.42333984375, 3.605240345001220703, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1752, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1970.2586669921875, -3488.5712890625, 3271.748046875, 5.379167556762695312, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk)
(@CGUID+1753, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1988.689208984375, -3189.869873046875, 3263.42626953125, 1.580340504646301269, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1754, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1980.9427490234375, -3457.81591796875, 3260.32080078125, 5.356244564056396484, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1755, 168580, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2036.9617919921875, -3356.31591796875, 3259.35302734375, 0.440691590309143066, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168580 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1756, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2001.98095703125, -3338.24658203125, 3257.622802734375, 5.343226432800292968, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1757, 169218, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1269.8680419921875, -3948.895751953125, 3138.185791015625, 0.482523232698440551, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 169218 (Area: Plaguefall - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1758, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2083.1806640625, -3413.465576171875, 3275.098876953125, 2.954128503799438476, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1759, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2059.12353515625, -3445.41845703125, 3260.253662109375, 3.161121606826782226, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1760, 174877, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1853.41845703125, -3161.463623046875, 3228.7119140625, 0.805711686611175537, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 174877 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1761, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1967.0255126953125, -3384.267333984375, 3266.60205078125, 5.5283050537109375, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0) (Auras: )
(@CGUID+1762, 169218, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1893.142333984375, -3200.73779296875, 3215.745849609375, 2.482550382614135742, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 169218 (Area: Plaguefall - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1763, 168364, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1853.685791015625, -3195.1806640625, 3212.150146484375, 2.198387861251831054, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168364 (Area: Plaguefall - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1764, 169696, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1985.6510009765625, -3274.8056640625, 3249.399169921875, 1.49180912971496582, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 169696 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 330271 - Cosmetic - Sleep Zzz)
(@CGUID+1765, 168578, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1949.109375, -3366.932373046875, 3257.1708984375, 4.626312732696533203, 7200, 0, 0, 37800, 0, 0, 0, 0, 0, 36839), -- 168578 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1766, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1977.0694580078125, -3457.661376953125, 3259.86767578125, 1.088284254074096679, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1767, 168580, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2062.744873046875, -3428.567626953125, 3261.590576171875, 1.518436431884765625, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168580 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1768, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2052.455078125, -3399.23974609375, 3265.719970703125, 3.701915264129638671, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1769, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1969.638916015625, -3457.713623046875, 3259.013671875, 3.81445622444152832, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1770, 174877, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1874.5399169921875, -3303.90966796875, 3216.931884765625, 1.100384116172790527, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 174877 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1771, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2065.329833984375, -3489.607666015625, 3259.728759765625, 4.418760299682617187, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1772, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1974.328125, -3456.390625, 3259.64208984375, 3.81445622444152832, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1773, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1928.9542236328125, -3266.7685546875, 3243.91015625, 6.058644294738769531, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk)
(@CGUID+1774, 168364, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1699.98095703125, -3265.375, 3214.76416015625, 1.467610597610473632, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168364 (Area: Plaguefall - Difficulty: 0) (Auras: 151051 - Mod Scale 70-130%)
(@CGUID+1775, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2089.48779296875, -3477.748291015625, 3271.9833984375, 0.085346855223178863, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1776, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2080.819580078125, -3425.62158203125, 3270.98193359375, 1.570796370506286621, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1777, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1988.046875, -3481.767333984375, 3272.156005859375, 4.238413333892822265, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 328964 - Slimed Cosmetic)
(@CGUID+1778, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2101.73779296875, -3421.02783203125, 3270.429931640625, 4.457673549652099609, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1779, 168572, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1942.9322509765625, -3409.204833984375, 3259.060546875, 1.821264982223510742, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168572 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 323486 - Dual Wield)
(@CGUID+1780, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2031.3291015625, -3326.03857421875, 3274.666015625, 6.188852310180664062, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1781, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1861.125, -3164.28125, 3225.119384765625, 0.633313536643981933, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1782, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1968.5694580078125, -3456.819580078125, 3258.96142578125, 1.088284254074096679, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1783, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1976.6964111328125, -3378.452880859375, 3268.421630859375, 2.677194833755493164, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1784, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1873.3038330078125, -3307, 3217.078857421875, 5.369243144989013671, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1785, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1982.671630859375, -3438.2841796875, 3261.61279296875, 3.012135505676269531, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0) (Auras: )
(@CGUID+1786, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2039.171875, -3359.161376953125, 3259.49658203125, 3.654038429260253906, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1787, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1951.111083984375, -3325.958251953125, 3255.4638671875, 2.035583972930908203, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1788, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1959.7239990234375, -3448.369873046875, 3257.92431640625, 5.336896896362304687, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1789, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1859.35595703125, -3168.282958984375, 3223.98388671875, 2.010120868682861328, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1790, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1929.6944580078125, -3265.048583984375, 3243.60205078125, 3.707114934921264648, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1791, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1893.9271240234375, -3291.671875, 3225.55908203125, 3.12309122085571289, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1792, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1939.9444580078125, -3248.263916015625, 3240.9873046875, 2.155879974365234375, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1793, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2083.24658203125, -3443.23779296875, 3269.36474609375, 0.163888797163963317, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1794, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1976.94970703125, -3450.453125, 3256.00439453125, 1.887515902519226074, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1795, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1948.748291015625, -3217.263916015625, 3235.67529296875, 2.564375877380371093, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1796, 168361, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2059.296875, -3440.161376953125, 3261.228271484375, 0.134935975074768066, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168361 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1797, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1986.62158203125, -3463.333251953125, 3253.50341796875, 5.356244564056396484, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1798, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2069.703125, -3359.604248046875, 3286.61572265625, 4.70115518569946289, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1799, 169218, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1171.6041259765625, -3941.623291015625, 3133.1455078125, 2.015719413757324218, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 169218 (Area: Plaguefall - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1800, 169201, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1538.1007080078125, -3564.09375, 3208.901123046875, 4.857228279113769531, 7200, 0, 0, 252000, 0, 0, 0, 0, 0, 36839), -- 169201 (Area: Plaguefall - Difficulty: 0) (Auras: 244807 - Anim Replacement - New Drunk, 329078 - Vomit)
(@CGUID+1801, 168968, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1923.0711669921875, -3233.685791015625, 3216.333740234375, 6.2742156982421875, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168968 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 331874 - Touch of Plague)
(@CGUID+1802, 169450, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1978.2763671875, -3384.52880859375, 3269.281494140625, 4.380994796752929687, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 169450 (Area: Plaguefall - Difficulty: 0) (Auras: )
(@CGUID+1803, 168580, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2047.7257080078125, -3397.298583984375, 3259.47265625, 5.621517181396484375, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168580 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 328020 - Plagueborer Base)
(@CGUID+1804, 164255, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2036.204833984375, -3596.0087890625, 3263.586669921875, 5.108221054077148437, 7200, 0, 0, 220500, 100, 0, 0, 0, 0, 36839), -- 164255 (Area: Plaguefall - Difficulty: 0) (Auras: 324366 - Living Slime Flesh, 324304 - Slime Energy Bar, 346098 - Festive Globgrog, 324284 - Slime Infused Bones)
(@CGUID+1805, 168572, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2002.27783203125, -3448.453125, 3257.99267578125, 2.141621351242065429, 7200, 0, 0, 25200, 0, 0, 0, 0, 0, 36839), -- 168572 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 323486 - Dual Wield)
(@CGUID+1806, 163931, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1966.4149169921875, -3451.9619140625, 3255.033447265625, 3.110103368759155273, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163931 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1807, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1973.79345703125, -3448.87158203125, 3259.93017578125, 3.329225540161132812, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1808, 163915, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2062.092041015625, -3436.71875, 3258.6318359375, 6.114463329315185546, 7200, 0, 0, 31500, 0, 0, 0, 0, 0, 36839), -- 163915 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 311242 - Lively Eggs)
(@CGUID+1809, 168153, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1729.3992919921875, -3393.39501953125, 3283.584716796875, 4.845487117767333984, 7200, 0, 0, 44100, 0, 0, 0, 0, 0, 36839), -- 168153 (Area: Plaguefall - Difficulty: 0)
(@CGUID+1810, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1961.8125, -3433.411376953125, 3260.93994140625, 1.96895754337310791, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1811, 168155, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1971.6129150390625, -3458.26220703125, 3259.210693359375, 6.01990509033203125, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168155 (Area: Plaguefall - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death)
(@CGUID+1812, 172063, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1763.859375, -3348.654541015625, 3211.76806640625, 0.250424504280090332, 7200, 0, 0, 252000, 0, 0, 0, 0, 0, 36839), -- 172063 (Area: Plaguefall - Difficulty: Normal) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1813, 169201, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1647.8802490234375, -3372.182373046875, 3210.9228515625, 3.52348184585571289, 7200, 0, 0, 252000, 0, 0, 0, 0, 0, 36839), -- 169201 (Area: Plaguefall - Difficulty: Normal) (Auras: 244807 - Anim Replacement - New Drunk)
(@CGUID+1814, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2019.301025390625, -3516.742919921875, 3260.307861328125, 4.275053977966308593, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1815, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2047.43408203125, -3526.6806640625, 3260.390380859375, 3.664870262145996093, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1816, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1986.467041015625, -3535.326416015625, 3259.689208984375, 0, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1817, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2018.553955078125, -3527.489013671875, 3260.307861328125, 2.034503459930419921, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1818, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2034.9833984375, -3525.048583984375, 3260.390380859375, 4.060580730438232421, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1819, 171573, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2097.673583984375, -3499.642333984375, 3263.66455078125, 2.488037347793579101, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 171573 (Area: Plaguefall - Difficulty: Normal) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1820, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2055.1611328125, -3527.142578125, 3260.390380859375, 3.685796022415161132, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1821, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2080.114501953125, -3501.203125, 3259.46337890625, 4.344142436981201171, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1822, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1986.3507080078125, -3514.569580078125, 3259.451904296875, 0, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1823, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2023.9788818359375, -3538.34375, 3260.376708984375, 0.898135364055633544, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1824, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2041.1505126953125, -3521.790283203125, 3260.390380859375, 1.774880170822143554, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1825, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2040.564453125, -3515.2490234375, 3260.390380859375, 1.280553102493286132, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1826, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2027.5958251953125, -3513.41748046875, 3260.307861328125, 0.728278696537017822, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1827, 171572, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2093.375, -3508.236083984375, 3261.08447265625, 4.613596916198730468, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 171572 (Area: Plaguefall - Difficulty: Normal) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1828, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2052.5859375, -3516.0244140625, 3260.390380859375, 0.147006645798683166, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1829, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2042.093017578125, -3534.31005859375, 3260.390625, 3.91226053237915039, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1830, 171572, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2101.64404296875, -3489.892333984375, 3261.34521484375, 4.60903167724609375, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 171572 (Area: Plaguefall - Difficulty: Normal) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1831, 168391, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1981.6666259765625, -3521.76220703125, 3261.7509765625, 6.194222927093505859, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168391 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1832, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2012.1942138671875, -3535.992431640625, 3260.376708984375, 5.416902065277099609, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1833, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1954.1669921875, -3525, 3271.38427734375, 0.78539818525314331, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: Normal) (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+1834, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2023.591552734375, -3545.29931640625, 3260.376708984375, 5.971007347106933593, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1835, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2088.338623046875, -3521.80029296875, 3259.458984375, 3.311464786529541015, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1836, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2016.2291259765625, -3540.78662109375, 3260.376708984375, 4.889394760131835937, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1837, 171574, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2097.51220703125, -3518.923583984375, 3265.022216796875, 1.227686405181884765, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 171574 (Area: Plaguefall - Difficulty: Normal) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1838, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2058.902099609375, -3535.211181640625, 3260.390625, 4.290091991424560546, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1839, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2037.322265625, -3542.669921875, 3260.390625, 3.064419031143188476, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1840, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2049.83203125, -3543.251953125, 3260.390625, 5.444762706756591796, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1841, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2046.52685546875, -3542.375244140625, 3260.390625, 1.292803645133972167, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1842, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1986.295166015625, -3556.33154296875, 3259.406494140625, 0.417013734579086303, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1843, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2033.90869140625, -3552.599365234375, 3260.390625, 5.087448596954345703, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1844, 168365, 2289, 13228, 13228, '0', '0', 0, 0, 0, 1955.2667236328125, -3572.40576171875, 3260.458984375, 1.533011913299560546, 7200, 0, 0, 4725, 0, 0, 0, 0, 0, 36839), -- 168365 (Area: Plaguefall - Difficulty: Normal) (Auras: 123169 - Mod Scale 105-110%, 328965 - Fertilizer)
(@CGUID+1845, 171572, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2095.171875, -3529.795166015625, 3260.12939453125, 3.503742933273315429, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 171572 (Area: Plaguefall - Difficulty: Normal) (Auras: 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death)
(@CGUID+1846, 168969, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2047.57763671875, -3554.619873046875, 3260.390625, 5.024950981140136718, 7200, 0, 0, 9450, 0, 0, 0, 0, 0, 36839), -- 168969 (Area: Plaguefall - Difficulty: Normal) (Auras: 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime)
(@CGUID+1847, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2089.20654296875, -3550.02783203125, 3259.4208984375, 2.60940098762512207, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1848, 168386, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2090.982666015625, -3549.772705078125, 3259.380859375, 0.536629080772399902, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 168386 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1849, 168393, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2023.66845703125, -3579.201416015625, 3259.96923828125, 6.016633987426757812, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 168393 (Area: Plaguefall - Difficulty: Normal) (Auras: 244807 - Anim Replacement - New Drunk, 327591 - Slimy Morsel)
(@CGUID+1850, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2028.78125, -3582.810791015625, 3259.513671875, 1.888534903526306152, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1851, 168396, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2068.776123046875, -3568.029052734375, 3260.32568359375, 0.585270881652832031, 7200, 0, 0, 50400, 0, 0, 0, 0, 0, 36839), -- 168396 (Area: Plaguefall - Difficulty: Normal) (Auras: 244807 - Anim Replacement - New Drunk, 327595 - Slimy Morsel)
(@CGUID+1852, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2001.2569580078125, -3580.640625, 3259.760498046875, 1.018098831176757812, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1853, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2054.375, -3583.257080078125, 3259.46630859375, 1.897548079490661621, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1854, 166480, 2289, 13228, 13228, '0', '0', 0, 0, 0, 2075.007080078125, -3575.5869140625, 3259.41162109375, 2.214966058731079101, 7200, 0, 0, 6300, 0, 0, 0, 0, 0, 36839), -- 166480 (Area: Plaguefall - Difficulty: Normal)
(@CGUID+1855, 171474, 2289, 13228, 13427, '0', '0', 0, 0, 0, 1983.5867919921875, -3639.486083984375, 3258.98193359375, 0, 7200, 0, 0, 97650, 0, 0, 0, 0, 0, 36839), -- 171474 (Area: Putrified Forest - Difficulty: Normal) (Auras: 334640 - Appetizer)
(@CGUID+1856, 73400, 2289, 13228, 13427, '0', '0', 0, 0, 0, 2025.593994140625, -3468.39501953125, 3260.265625, 0, 7200, 0, 0, 11791, 2434, 0, 0, 0, 0, 36839), -- 73400 (Area: Putrified Forest - Difficulty: Normal) (Auras: 147490 - Healing Rain Visual)
(@CGUID+1857, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2693.01416015625, -1639.0523681640625, 3252.095703125, 3.984047651290893554, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: Normal) (Auras: 328701 - 9.0 Carry Maldraxxus Bomb) (possible waypoints or random movement)
(@CGUID+1858, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2706.1025390625, -1598.7379150390625, 3253.677001953125, 4.2999114990234375, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: Normal) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1859, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2846.20751953125, -1707.265625, 3231.57275390625, 3.476916790008544921, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: Normal) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1860, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2859.144775390625, -1692.18994140625, 3231.7958984375, 0.50440150499343872, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: Normal)
(@CGUID+1861, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2682.1015625, -1638.3221435546875, 3251.647705078125, 4.035807609558105468, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: Normal) (Auras: 328701 - 9.0 Carry Maldraxxus Bomb) (possible waypoints or random movement)
(@CGUID+1862, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.859375, -1647.248291015625, 3252.718505859375, 2.886987209320068359, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: Normal) (Auras: )
(@CGUID+1863, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2789.1904296875, -1641.060302734375, 3253.70703125, 0.094018563628196716, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: Normal) (Auras: )
(@CGUID+1864, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2846.125, -1684.8837890625, 3231.033203125, 4.210603237152099609, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: Normal)
(@CGUID+1865, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2761.410400390625, -1661.15869140625, 3241.396728515625, 1.932081222534179687, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: Normal) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1866, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2842.358154296875, -1692.641357421875, 3230.560791015625, 5.054315567016601562, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: Normal) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1867, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2784.912353515625, -1602.93408203125, 3259.2548828125, 5.722022056579589843, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: Normal) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1868, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.786376953125, -1731.84033203125, 3231.365966796875, 1.8118363618850708, 120, 10, 0, 7831, 0, 1, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction) (possible waypoints or random movement)
(@CGUID+1869, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2879.7431640625, -1606.91845703125, 3262.19140625, 4.343848228454589843, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1870, 160955, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2866.7421875, -1647.875, 3253.67578125, 3.42039036750793457, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 36839), -- 160955 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1871, 70483, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2866.7421875, -1647.875, 3253.759033203125, 3.42039036750793457, 120, 0, 0, 118, 0, 0, 0, 0, 0, 36839), -- 160955 (Area: The Spearhead - Difficulty: 0) (Auras: 329598 - Explosive Charge)
(@CGUID+1872, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2825.272705078125, -1673.0538330078125, 3233.35791015625, 2.61985015869140625, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1873, 161105, 2222, 11462, 11467, '0', '0', 0, 0, 0, 3027.6796875, -1814.43408203125, 3224.3291015625, 3.113831758499145507, 120, 0, 0, 96816, 0, 0, 0, 0, 0, 36839), -- 161105 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1874, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2959.709228515625, -1742.03515625, 3228.47998046875, 5.884738922119140625, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1875, 160996, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2932.3828125, -1774.6475830078125, 3234.192626953125, 2.230392694473266601, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 160996 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1876, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2933.629638671875, -1801.125732421875, 3248.193603515625, 1.328176021575927734, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1877, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2940.85205078125, -1789.522705078125, 3245.732666015625, 4.174060344696044921, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1878, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2924.382568359375, -1810.4630126953125, 3246.39306640625, 4.439654827117919921, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1879, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2931.435546875, -1803.241455078125, 3246.8798828125, 2.83325815200805664, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1880, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2942.430419921875, -1792.1614990234375, 3246.48046875, 1.610251188278198242, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1881, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2913.3525390625, -1818.72802734375, 3245.093017578125, 1.035946607589721679, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1882, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2809.866455078125, -1813.421875, 3240.055419921875, 5.278681278228759765, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1883, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2925.126220703125, -1802.8253173828125, 3246.19970703125, 2.181463956832885742, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1884, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2795.643310546875, -1800.140625, 3232.143798828125, 2.46091628074645996, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1885, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2947.149169921875, -1815.37841796875, 3246.416748046875, 3.861597299575805664, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1886, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2947.6982421875, -1816.3150634765625, 3248.118408203125, 3.646506786346435546, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1887, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2917.88427734375, -1826.4095458984375, 3248.659423828125, 0.976151466369628906, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1888, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2943.63427734375, -1827.3787841796875, 3259.466552734375, 3.7098388671875, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1889, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2948.52734375, -1811.6055908203125, 3247.752197265625, 0.619737029075622558, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1890, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2941.871826171875, -1827.6009521484375, 3249.083740234375, 1.402522921562194824, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1891, 169223, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2859.951416015625, -1868.482666015625, 3236.163330078125, 5.747056961059570312, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169223 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1892, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2941.34521484375, -1804.15087890625, 3247.40966796875, 2.420971155166625976, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1893, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2943.9365234375, -1828.0430908203125, 3253.165283203125, 0.012486343272030353, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1894, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2946.643798828125, -1798.8406982421875, 3245.81689453125, 4.175638198852539062, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1895, 160474, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2903.458251953125, -1835.8489990234375, 3236.10107421875, 4.518187522888183593, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 160474 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1896, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2783.25537109375, -1811.6375732421875, 3233.799560546875, 2.118419647216796875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1897, 169226, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2854.85595703125, -1857.9271240234375, 3236.114501953125, 4.318113327026367187, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 169226 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1898, 169223, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2858.724853515625, -1855.578125, 3236.185302734375, 1.00360262393951416, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169223 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1899, 169223, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2863.373291015625, -1863.9461669921875, 3236.146240234375, 0.223913252353668212, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169223 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1900, 169223, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2861.575439453125, -1856.4461669921875, 3236.181884765625, 1.593029499053955078, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169223 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1901, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2781.798583984375, -1792.486083984375, 3230.635498046875, 5.938997745513916015, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1902, 169223, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2859.875, -1851.7708740234375, 3236.253662109375, 0.535652220249176025, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169223 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1903, 169223, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2852.4072265625, -1853.18408203125, 3236.184814453125, 3.105731487274169921, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169223 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1904, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2902.857666015625, -1839.795166015625, 3236.141845703125, 6.185529232025146484, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1905, 167273, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2904.568603515625, -1872.861083984375, 3238.56591796875, 1.533230781555175781, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 167273 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1906, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2933.493896484375, -1857.74658203125, 3237.11376953125, 1.524883389472961425, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: 154470 - Permanent Feign Death (Flies))
(@CGUID+1907, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2883.960205078125, -1879.015625, 3236.366455078125, 1.130733132362365722, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1908, 167354, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2884.2529296875, -1876.2159423828125, 3236.603759765625, 4.852213382720947265, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167354 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1909, 160479, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2925.408447265625, -1870.6654052734375, 3237.1533203125, 2.856757640838623046, 120, 0, 0, 56952, 0, 0, 0, 0, 0, 36839), -- 160479 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1910, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2919.69091796875, -1868.9913330078125, 3238.1064453125, 5.926288604736328125, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1911, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2868.703369140625, -1908.6898193359375, 3235.777099609375, 4.490594863891601562, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1912, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2764.89794921875, -1808.794921875, 3233.00927734375, 3.480395078659057617, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1913, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2939.372314453125, -1879.451904296875, 3241.523193359375, 0.610172688961029052, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1914, 157671, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2862.927734375, -1911.00341796875, 3235.35693359375, 4.619997024536132812, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 157671 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1915, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2934.140869140625, -1882.820556640625, 3243.2353515625, 2.793830633163452148, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1916, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2862.476318359375, -1915.8753662109375, 3235.5283203125, 1.478388309478759765, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1917, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2935.3876953125, -1888.16259765625, 3245.32080078125, 5.274879932403564453, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1918, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2838.05126953125, -1928.2181396484375, 3253.190673828125, 2.455876827239990234, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1919, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2840.768310546875, -1927.4427490234375, 3253.659423828125, 5.171231269836425781, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1920, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2954.714599609375, -1875.2010498046875, 3244.595458984375, 3.444851875305175781, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1921, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2817.4482421875, -1932.176025390625, 3253.679443359375, 1.509495496749877929, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1922, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2959.091796875, -1894.3905029296875, 3243.520263671875, 4.800164222717285156, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1923, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2961.18408203125, -1891.845703125, 3240.620361328125, 4.662955284118652343, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1924, 169129, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2959.048583984375, -1875.6630859375, 3245.671630859375, 3.960007429122924804, 120, 10, 0, 7515, 0, 1, 0, 0, 0, 36839), -- 169129 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1925, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2961.84423828125, -1889.0931396484375, 3239.41015625, 3.512558221817016601, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1926, 167359, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2968.369140625, -1880.0787353515625, 3235.833251953125, 3.359750747680664062, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167359 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1927, 160996, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2932.3828125, -1774.6475830078125, 3234.192626953125, 2.230392694473266601, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 160996 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1928, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2984.396728515625, -1835.416015625, 3225.799560546875, 2.631729364395141601, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (Auras: 326019 - 9.0 Carry Ballista Ammo) (possible waypoints or random movement)
(@CGUID+1929, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2983.33251953125, -1805.9617919921875, 3226.7998046875, 3.10029911994934082, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1930, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2991.784912109375, -1788.293701171875, 3224.6318359375, 4.555209159851074218, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1931, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2995.2451171875, -1830.3751220703125, 3225.549560546875, 3.436132192611694335, 120, 10, 0, 5, 0, 1, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1932, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2976.993896484375, -1814.09375, 3227.90966796875, 6.253987312316894531, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1933, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2987.655517578125, -1750.653564453125, 3227.25146484375, 5.210099697113037109, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1934, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2997.7958984375, -1782.8006591796875, 3224.47412109375, 2.661789178848266601, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (Auras: 326019 - 9.0 Carry Ballista Ammo) (possible waypoints or random movement)
(@CGUID+1935, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2920.864501953125, -1741.4322509765625, 3234.834716796875, 0.129482701420783996, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1936, 167356, 2222, 11462, 11467, '0', '0', 0, 0, 0, 3005.565673828125, -1802.0159912109375, 3225.00634765625, 2.666142225265502929, 120, 0, 0, 5, 0, 0, 0, 0, 0, 36839), -- 167356 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1937, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2948.108642578125, -1735.9010009765625, 3232.116455078125, 0.483949393033981323, 120, 10, 0, 9255, 0, 1, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1938, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2942.817626953125, -1720.420166015625, 3234.0927734375, 0.202590957283973693, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0) (Auras: )
(@CGUID+1939, 169170, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2957.6494140625, -1745.9288330078125, 3228.75927734375, 0.79555058479309082, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 169170 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1940, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2969.35498046875, -1757.123291015625, 3227.29345703125, 1.179674386978149414, 120, 10, 0, 9255, 0, 1, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1941, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2978.270751953125, -1758.5399169921875, 3226.376220703125, 1.329575777053833007, 120, 10, 0, 9255, 0, 1, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1942, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2991.767333984375, -1760.1163330078125, 3225.578857421875, 1.737517118453979492, 120, 0, 0, 9255, 0, 0, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1943, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2952.032958984375, -1740.2760009765625, 3230.78369140625, 0, 120, 10, 0, 9255, 0, 1, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1944, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2947.028564453125, -1731.607666015625, 3232.73974609375, 0.224894866347312927, 120, 10, 0, 9255, 0, 1, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1945, 169147, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2993.393310546875, -1762.9288330078125, 3225.459228515625, 0, 120, 10, 0, 9255, 0, 1, 0, 0, 0, 36839), -- 169147 (Area: The Spearhead - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1946, 169170, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2974.099853515625, -1758.63720703125, 3226.795166015625, 1.179970026016235351, 120, 0, 0, 14238, 0, 0, 0, 0, 0, 36839), -- 169170 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1947, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2976.993896484375, -1817.5694580078125, 3227.90966796875, 6.253987312316894531, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1948, 169161, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2968.08544921875, -1712.9774169921875, 3233.592529296875, 4.738750457763671875, 120, 0, 0, 7119, 0, 0, 0, 0, 0, 36839), -- 169161 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1949, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2976.993896484375, -1810.4879150390625, 3227.90966796875, 6.253987312316894531, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1950, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2976.993896484375, -1807.326416015625, 3227.90966796875, 6.253987312316894531, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1951, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2957.9931640625, -1720.1771240234375, 3234.09375, 2.005109310150146484, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1952, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 3005.189453125, -1782.2894287109375, 3224.651123046875, 3.275228023529052734, 120, 10, 0, 3560, 0, 1, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0) (Auras: 326019 - 9.0 Carry Ballista Ammo) (possible waypoints or random movement)
(@CGUID+1953, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2870.060791015625, -1813.9427490234375, 3235.141357421875, 2.68951725959777832, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839), -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1954, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2841.670166015625, -1734.032958984375, 3230.5400390625, 4.540428638458251953, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1955, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2909.953125, -1755.82470703125, 3232.62158203125, 6.010761260986328125, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1956, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2915.62158203125, -1774.8819580078125, 3232.44091796875, 2.403082609176635742, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1957, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2910.5166015625, -1714.9739990234375, 3232.200927734375, 4.862460136413574218, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1958, 167271, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2921.623291015625, -1721.8541259765625, 3234.54541015625, 5.013782978057861328, 120, 0, 0, 3560, 0, 0, 0, 0, 0, 36839), -- 167271 (Area: The Spearhead - Difficulty: 0)
(@CGUID+1959, 157669, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2864.366455078125, -1811.2274169921875, 3237.072265625, 1.925874948501586914, 120, 0, 0, 7831, 0, 0, 0, 0, 0, 36839), -- 157669 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)
(@CGUID+1960, 156591, 2222, 11462, 11467, '0', '0', 0, 0, 0, 2899.8916015625, -1738.1771240234375, 3231.9306640625, 3.232179641723632812, 120, 0, 0, 10679, 0, 0, 0, 0, 0, 36839); -- 156591 (Area: The Spearhead - Difficulty: 0) (Auras: 99203 - 100% Threat Reduction)

SET @CGUID := 210456408;
REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+4, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 166423
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164833
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161399 - 314093 - Useful Parts
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+9, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+12, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+16, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 167743
(@CGUID+17, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 160424
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167737
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+23, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 157671
(@CGUID+24, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 166423
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160424
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+33, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167747 - 99203 - 100% Threat Reduction
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Baroness Draka
(@CGUID+37, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 160424
(@CGUID+38, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 160415
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160424
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161376 - 314093 - Useful Parts
(@CGUID+44, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 157671
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- 142668 - 122729 - Grand Expedition Yak
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- 142666 - 122729 - Grand Expedition Yak
(@CGUID+51, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 167741
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170971
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170971
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+57, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 166423
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+59, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+60, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167209
(@CGUID+62, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+63, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+64, 0, 0, 0, 0, 0, 0, 0, 0, '344880'), -- 158339 - 344880 - Carry Candle
(@CGUID+65, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+66, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161376 - 314093 - Useful Parts
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, '122729 123236'), -- 62821 - 122729 - Grand Expedition Yak, 123236 - Grummle Booth A
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- 62822 - 122729 - Grand Expedition Yak
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, '314898 247866'), -- 157843 - 314898 - Visectus, 247866 - Set Health % (Uses Override Points) (No Health Regen)
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+78, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 157514
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161399 - 314093 - Useful Parts
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, '307830'), -- 157803 - 307830 - Archon Fragment
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+87, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 157671
(@CGUID+88, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 157671
(@CGUID+89, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 157671
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '343800'), -- 156558 - 343800 - [DNT] - Flavor 2
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, '343329'), -- 156558 - 343329 - [DNT] - Flavor 2
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164833
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, '343800'), -- 156558 - 343800 - [DNT] - Flavor 2
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161881
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167273
(@CGUID+114, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 157671
(@CGUID+115, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+118, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161676
(@CGUID+119, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+120, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167642
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+124, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161679
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+127, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 160415
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167641
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161679
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+132, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168045
(@CGUID+136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '330574'), -- 161395 - 330574 - Deathbolt Rift
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161668
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161395
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, '343329'), -- 156558 - 343329 - [DNT] - Flavor 2
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+148, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169634 - 154470 - Permanent Feign Death (Flies)
(@CGUID+149, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161390
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161390
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161395
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161388 - 314093 - Useful Parts
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161396
(@CGUID+157, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+161, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+162, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+167, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+168, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+170, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+171, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167948 - 244807 - Anim Replacement - New Drunk
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+175, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+176, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+181, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+182, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+183, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 154470'), -- 167935 - 123169 - Mod Scale 105-110%, 154470 - Permanent Feign Death (Flies)
(@CGUID+184, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+186, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+187, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+188, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+190, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+192, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+193, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+200, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+202, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 154470'), -- 167935 - 123169 - Mod Scale 105-110%, 154470 - Permanent Feign Death (Flies)
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+204, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+208, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+211, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- Bleak Skitterer - 308853 - Battle Pet Periodic
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+214, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+216, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+220, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168216
(@CGUID+221, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+222, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+225, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+226, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+227, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159930
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+233, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+235, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- Bleak Skitterer - 308853 - Battle Pet Periodic
(@CGUID+238, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+242, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'); -- 159856 - 214567 - Mod Scale 90-110%; 276684 - Churning Dirt

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+251, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+255, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+256, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+257, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+259, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+260, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+263, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+264, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+267, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+269, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+273, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+276, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+280, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Invisible Stalker
(@CGUID+281, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Invisible Stalker
(@CGUID+282, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 165034
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+285, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - 154470 - Permanent Feign Death (Flies)
(@CGUID+286, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - 154470 - Permanent Feign Death (Flies)
(@CGUID+287, 0, 0, 50331648, 1, 0, 0, 0, 0, '308853'), -- Crawbat - 308853 - Battle Pet Periodic
(@CGUID+288, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+289, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+290, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - 154470 - Permanent Feign Death (Flies)
(@CGUID+291, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+292, 0, 0, 50331648, 1, 0, 0, 0, 0, '308853'), -- Crawbat - 308853 - Battle Pet Periodic
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168192
(@CGUID+294, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+295, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - 154470 - Permanent Feign Death (Flies)
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158642
(@CGUID+297, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+298, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+299, 0, 0, 50331648, 1, 0, 0, 0, 0, '308853'), -- Crawbat - 308853 - Battle Pet Periodic
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+301, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+302, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - 154470 - Permanent Feign Death (Flies)
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+304, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+305, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+308, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - 154470 - Permanent Feign Death (Flies)
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+315, 0, 0, 50331648, 1, 0, 0, 0, 0, '308853'), -- Crawbat - 308853 - Battle Pet Periodic
(@CGUID+316, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+319, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+320, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+324, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+326, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+327, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+328, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+330, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+332, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+333, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+335, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+344, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+349, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- Bleak Skitterer - 308853 - Battle Pet Periodic
(@CGUID+351, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+352, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+354, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+355, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+356, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+357, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+364, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- Bleak Skitterer - 308853 - Battle Pet Periodic
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+367, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+368, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+369, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+373, 0, 0, 50331648, 1, 0, 0, 0, 0, '308853'), -- Crawbat - 308853 - Battle Pet Periodic
(@CGUID+374, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+381, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+382, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+384, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+385, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+391, 0, 0, 0, 1, 0, 0, 0, 0, '214567 264867'), -- 159856 - 214567 - Mod Scale 90-110%, 264867 - Churning Dirt
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+394, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+397, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+405, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+406, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+407, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, '326001'), -- 166908 - 326001 - Summon Creep Area Trigger
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162767
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+417, 0, 0, 50331648, 1, 0, 0, 0, 0, '308853'), -- Crawbat - 308853 - Battle Pet Periodic
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- Bleak Skitterer - 308853 - Battle Pet Periodic
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+421, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+424, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - 322272 - Stringy Growth
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+426, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+427, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+428, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+430, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+431, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - 154470 - Permanent Feign Death (Flies)
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- Bleak Skitterer - 308853 - Battle Pet Periodic
(@CGUID+433, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+434, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+436, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+438, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+439, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+440, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+441, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+442, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159930
(@CGUID+444, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160029
(@CGUID+445, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+446, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+450, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+452, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+453, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(@CGUID+454, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+456, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+458, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+459, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+460, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+461, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+462, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+463, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+466, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+470, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 167935 - 123169 - Mod Scale 105-110%
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+472, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - 214567 - Mod Scale 90-110%, 276684 - Churning Dirt
(@CGUID+474, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 159856 - 214567 - Mod Scale 90-110%
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+483, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+484, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+485, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331108'), -- 160048 - 244807 - Anim Replacement - New Drunk, 331108 - Slimy Coating
(@CGUID+487, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+488, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+489, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+490, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+491, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+492, 0, 0, 8, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+493, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+495, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+496, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+497, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, '203315'); -- 160060 - 203315 - Plagued

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+500, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+501, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+502, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+503, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+504, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167948 - 244807 - Anim Replacement - New Drunk
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+507, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+510, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+516, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+517, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+519, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+520, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+521, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 167935 - 123169 - Mod Scale 105-110%
(@CGUID+522, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+523, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+524, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+525, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+526, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+527, 0, 0, 0, 1, 0, 0, 0, 0, '244807 255051'), -- 160048 - 244807 - Anim Replacement - New Drunk, 255051 - Vomit
(@CGUID+528, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167923 - 244807 - Anim Replacement - New Drunk
(@CGUID+529, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+532, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+533, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+534, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+535, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+536, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+537, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+539, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+540, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- 32638 - 61424 - Traveler's Tundra Mammoth
(@CGUID+541, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- 32639 - 61424 - Traveler's Tundra Mammoth
(@CGUID+542, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+544, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+546, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167949
(@CGUID+547, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160048
(@CGUID+548, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+549, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+550, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+551, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167923 - 244807 - Anim Replacement - New Drunk
(@CGUID+552, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+553, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+554, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+555, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+556, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+557, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+558, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+559, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+560, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+561, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+562, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+563, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+564, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167948 - 244807 - Anim Replacement - New Drunk
(@CGUID+565, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+566, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+567, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+568, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167923 - 244807 - Anim Replacement - New Drunk
(@CGUID+569, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+570, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+571, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+572, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+573, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+574, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+575, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+576, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+577, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+578, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+579, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+580, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+581, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+582, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171375
(@CGUID+583, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+584, 0, 0, 0, 1, 0, 0, 0, 0, '203315 144140'), -- 161613 - 203315 - Plagued, 144140 - Vertex Color Lime Green
(@CGUID+585, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+586, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+587, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+588, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+589, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+590, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 174813 - 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+591, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+592, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+593, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+594, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+595, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+596, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+597, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+598, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+599, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+600, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+601, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+602, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+603, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+604, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+605, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+606, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+607, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+608, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+609, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+610, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+611, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+612, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+613, 0, 0, 0, 1, 0, 0, 0, 0, '244807 255051'), -- 160048 - 244807 - Anim Replacement - New Drunk, 255051 - Vomit
(@CGUID+614, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+615, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+616, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+617, 0, 0, 8, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+618, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167923 - 244807 - Anim Replacement - New Drunk
(@CGUID+619, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+620, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+621, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+622, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 167935 - 123169 - Mod Scale 105-110%
(@CGUID+623, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+624, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+625, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167923 - 244807 - Anim Replacement - New Drunk
(@CGUID+626, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+627, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - 244807 - Anim Replacement - New Drunk
(@CGUID+628, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+629, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+630, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+631, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - 203315 - Plagued
(@CGUID+632, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+633, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+634, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+635, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+636, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+637, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+638, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+639, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+640, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+641, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+642, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+643, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+644, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+645, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159930
(@CGUID+646, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+647, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167949 - 244807 - Anim Replacement - New Drunk
(@CGUID+648, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167949 - 244807 - Anim Replacement - New Drunk
(@CGUID+649, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167949 - 244807 - Anim Replacement - New Drunk
(@CGUID+650, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+651, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+652, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+653, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+654, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+655, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 165034
(@CGUID+656, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+657, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+658, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+659, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+660, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+661, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+662, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 165034
(@CGUID+663, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+664, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165032
(@CGUID+665, 0, 0, 0, 1, 0, 0, 0, 0, '306664 306713 306722'), -- 157226 - 306664 - Mixing Pool, 306713 - Miscible Ooze, 306722 - Viscous Oil
(@CGUID+666, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+667, 0, 0, 0, 0, 0, 0, 0, 0, '333495'), -- 171112 - 333495 - Carry Crate
(@CGUID+668, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165017
(@CGUID+669, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 165034
(@CGUID+670, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165049
(@CGUID+671, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171112
(@CGUID+672, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165017
(@CGUID+673, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 157515
(@CGUID+674, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+675, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171135
(@CGUID+676, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 165017
(@CGUID+677, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172141
(@CGUID+678, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+679, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171112
(@CGUID+680, 0, 0, 0, 0, 0, 0, 0, 0, '333495'), -- 171112 - 333495 - Carry Crate
(@CGUID+681, 0, 0, 8, 0, 0, 0, 0, 0, ''), -- 171112
(@CGUID+682, 0, 0, 0, 1, 0, 0, 0, 0, '315493'), -- 166579 - 315493 - Cosmetic - Offhand Book
(@CGUID+683, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171112
(@CGUID+684, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 171130 - 244807 - Anim Replacement - New Drunk
(@CGUID+685, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171133
(@CGUID+686, 0, 0, 0, 0, 0, 0, 0, 0, '333495'), -- 171112 - 333495 - Carry Crate
(@CGUID+687, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161841
(@CGUID+688, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157313
(@CGUID+689, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 165017 - 259900 - Stirring
(@CGUID+690, 0, 0, 0, 1, 0, 0, 0, 0, '321236'), -- 165017 - 321236 - Carry Barrel, Orange Goo, With Kneeling
(@CGUID+691, 0, 0, 0, 1, 0, 0, 0, 0, '321241'), -- 165017 - 321241 - Carry Barrel, Empty, With Kneeling End
(@CGUID+692, 0, 0, 0, 1, 0, 0, 0, 0, '321241'), -- 165017 - 321241 - Carry Barrel, Empty, With Kneeling End
(@CGUID+693, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 165017 - 259900 - Stirring
(@CGUID+694, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 161380 - 259900 - Stirring
(@CGUID+695, 0, 0, 0, 1, 0, 0, 0, 0, '315493'), -- 165052 - 315493 - Cosmetic - Offhand Book
(@CGUID+696, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159930
(@CGUID+697, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159930
(@CGUID+698, 0, 0, 0, 1, 0, 0, 0, 0, '321241'), -- 165017 - 321241 - Carry Barrel, Empty, With Kneeling End
(@CGUID+699, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+700, 0, 0, 0, 1, 0, 0, 0, 0, '321236'), -- 165017 - 321236 - Carry Barrel, Orange Goo, With Kneeling
(@CGUID+701, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164833
(@CGUID+702, 0, 0, 0, 1, 0, 0, 0, 0, '315493'), -- 171133 - 315493 - Cosmetic - Offhand Book
(@CGUID+703, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 161380 - 259900 - Stirring
(@CGUID+704, 0, 0, 0, 1, 0, 0, 0, 0, '321241'), -- 165017 - 321241 - Carry Barrel, Empty, With Kneeling End
(@CGUID+705, 0, 0, 0, 1, 0, 0, 0, 0, '319502'), -- 171129 - 319502 - Cosmetic - Slime Cauldron
(@CGUID+706, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171112
(@CGUID+707, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 161380 - 259900 - Stirring
(@CGUID+708, 0, 0, 0, 1, 0, 0, 0, 0, '321236'), -- 165017 - 321236 - Carry Barrel, Orange Goo, With Kneeling
(@CGUID+709, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165017
(@CGUID+710, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171112
(@CGUID+711, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165017
(@CGUID+712, 0, 0, 1, 1, 0, 0, 0, 0, '244807'), -- 171217 - 244807 - Anim Replacement - New Drunk
(@CGUID+713, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 161380 - 259900 - Stirring
(@CGUID+714, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157945
(@CGUID+715, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 165017 - 259900 - Stirring
(@CGUID+716, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+717, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 171142 - 282999 - Anim Replacement - New Drunk
(@CGUID+718, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+719, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+720, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+721, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+722, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+723, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+724, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+725, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+726, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+727, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+728, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+729, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+730, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+731, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160417
(@CGUID+732, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+733, 0, 0, 0, 1, 0, 0, 0, 0, '144140'), -- 160418 - 144140 - Vertex Color Lime Green
(@CGUID+734, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+735, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+736, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160253
(@CGUID+737, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(@CGUID+738, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+739, 0, 0, 0, 1, 0, 0, 0, 0, '292177'), -- 156558 - 292177 - Turn In Circle Visual
(@CGUID+740, 0, 0, 0, 1, 0, 0, 0, 0, '321653'), -- 165145 - 321653 - White Arrow
(@CGUID+741, 0, 0, 50331648, 1, 0, 0, 0, 0, '306781'), -- 157317 - 306781 - Mixing Pool
(@CGUID+742, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+743, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+744, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+745, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+746, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+747, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+748, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+749, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 171599

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+750, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+751, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+752, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+753, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+754, 0, 0, 0, 1, 0, 0, 0, 0, '308850'), -- 158406 - 308850 - Vile Emission
(@CGUID+755, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+756, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+757, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 165015 - 282999 - Anim Replacement - New Drunk
(@CGUID+758, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+759, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+760, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+761, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+762, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+763, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+764, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+765, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+766, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+767, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+768, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+769, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+770, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+771, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+772, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+773, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+774, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+775, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+776, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+777, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+778, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+779, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+780, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+781, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+782, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+783, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+784, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+785, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - 214567 - Mod Scale 90-110%
(@CGUID+786, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - 214567 - Mod Scale 90-110%
(@CGUID+787, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - 214567 - Mod Scale 90-110%
(@CGUID+788, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+789, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+790, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - 334479 - On Spawn Slime Perimeter (DNT)
(@CGUID+791, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+792, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - 214567 - Mod Scale 90-110%
(@CGUID+793, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - 214567 - Mod Scale 90-110%
(@CGUID+794, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - 214567 - Mod Scale 90-110%
(@CGUID+795, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 164759 - 203315 - Plagued
(@CGUID+796, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - 214567 - Mod Scale 90-110%
(@CGUID+797, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+798, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+799, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+800, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+801, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+802, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 165015 - 282999 - Anim Replacement - New Drunk
(@CGUID+803, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+804, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+805, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+806, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+807, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+808, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 165015 - 282999 - Anim Replacement - New Drunk
(@CGUID+809, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+810, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+811, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+812, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 166438 - 282999 - Anim Replacement - New Drunk
(@CGUID+813, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+814, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+815, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+816, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+817, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+818, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+819, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+820, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+821, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+822, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+823, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+824, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+825, 0, 0, 0, 1, 0, 0, 0, 0, '306666'), -- 157226 - 306666 - Mixing Pool
(@CGUID+826, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 171142 - 282999 - Anim Replacement - New Drunk
(@CGUID+827, 0, 0, 0, 1, 0, 0, 0, 0, '340292'), -- 157294 - 340292 - Blood Clone Cosmetic
(@CGUID+828, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+829, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gelatinous
(@CGUID+830, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+831, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+832, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 165015 - 282999 - Anim Replacement - New Drunk
(@CGUID+833, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+834, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+835, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+836, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+837, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+838, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - 123169 - Mod Scale 105-110%
(@CGUID+839, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+840, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 165015 - 282999 - Anim Replacement - New Drunk
(@CGUID+841, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 166438 - 282999 - Anim Replacement - New Drunk
(@CGUID+842, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - 123169 - Mod Scale 105-110%
(@CGUID+843, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Invisible Stalker
(@CGUID+844, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+845, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160419
(@CGUID+846, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+847, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+848, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+849, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+850, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(@CGUID+851, 0, 0, 0, 1, 0, 0, 0, 0, '332174'), -- Invisible Stalker - 332174 - Anima Catalyst
(@CGUID+852, 0, 0, 0, 1, 0, 0, 0, 0, '332174'), -- Invisible Stalker - 332174 - Anima Catalyst
(@CGUID+853, 0, 0, 0, 1, 0, 0, 0, 0, '319972'), -- Invisible Stalker - 319972 - Diffusing Flower
(@CGUID+854, 0, 0, 0, 1, 0, 0, 0, 0, '333012'), -- Invisible Stalker - 333012 - Plague Cloud
(@CGUID+855, 0, 0, 0, 1, 0, 0, 0, 0, '333012'), -- Invisible Stalker - 333012 - Plague Cloud
(@CGUID+856, 0, 0, 0, 1, 0, 0, 0, 0, '333012'), -- Invisible Stalker - 333012 - Plague Cloud
(@CGUID+857, 0, 0, 0, 1, 0, 0, 0, 0, '333016'), -- 170757 - 333016 - Stradama's Aura
(@CGUID+858, 0, 0, 33554432, 1, 0, 0, 0, 0, '333016'), -- 163958 - 333016 - Stradama's Aura
(@CGUID+859, 0, 0, 0, 1, 0, 0, 0, 0, '333012'), -- Invisible Stalker - 333012 - Plague Cloud
(@CGUID+860, 0, 0, 0, 1, 0, 0, 0, 0, '333016'), -- 170757 - 333016 - Stradama's Aura
(@CGUID+861, 0, 0, 0, 1, 0, 0, 0, 0, '333012'), -- Invisible Stalker - 333012 - Plague Cloud
(@CGUID+862, 0, 0, 0, 1, 0, 0, 0, 0, '333012'), -- Invisible Stalker - 333012 - Plague Cloud
(@CGUID+863, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159930
(@CGUID+864, 0, 0, 1, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+865, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+866, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+867, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+868, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+869, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+870, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+871, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+872, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+873, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+874, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+875, 0, 0, 1, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+876, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(@CGUID+877, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167923 - 244807 - Anim Replacement - New Drunk
(@CGUID+878, 0, 0, 0, 1, 0, 0, 0, 0, '244807 331874'), -- 167949 - 244807 - Anim Replacement - New Drunk, 331874 - Touch of Plague
(@CGUID+879, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+880, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+881, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+882, 0, 0, 3, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+883, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - 331874 - Touch of Plague
(@CGUID+884, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+885, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+886, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161396
(@CGUID+887, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+888, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+889, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+890, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161390
(@CGUID+891, 0, 0, 0, 1, 0, 0, 0, 0, '330574'), -- 161395 - 330574 - Deathbolt Rift
(@CGUID+892, 0, 0, 0, 1, 0, 0, 0, 0, '330574'), -- 161395 - 330574 - Deathbolt Rift
(@CGUID+893, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+894, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161390
(@CGUID+895, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161390
(@CGUID+896, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+897, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(@CGUID+898, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+899, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+900, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161395
(@CGUID+901, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+902, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+903, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+905, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+906, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+907, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+908, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161395
(@CGUID+909, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161388 - 314093 - Useful Parts
(@CGUID+910, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+911, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+912, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+913, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+914, 0, 0, 0, 1, 0, 0, 0, 0, '318119'), -- Invisible Stalker - 318119 - Necromancy Ring
(@CGUID+915, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170806
(@CGUID+916, 0, 0, 0, 1, 0, 0, 0, 0, '333140'), -- 170807 - 333140 - Cosmetic - Slime Party Hat and Cake
(@CGUID+917, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+918, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+919, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+920, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+921, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+922, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+923, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 164915
(@CGUID+924, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+925, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170806
(@CGUID+926, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+927, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+928, 0, 0, 0, 1, 0, 0, 0, 0, '343329'), -- 156558 - 343329 - [DNT] - Flavor 2
(@CGUID+929, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+930, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+931, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+932, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+933, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+934, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+935, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161376 - 314093 - Useful Parts
(@CGUID+936, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+937, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161376 - 314093 - Useful Parts
(@CGUID+938, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161376 - 314093 - Useful Parts
(@CGUID+939, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 166423
(@CGUID+940, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161994
(@CGUID+941, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+942, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170806
(@CGUID+943, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+944, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+945, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+946, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161376 - 314093 - Useful Parts
(@CGUID+947, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+948, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161399
(@CGUID+949, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- 32638 - 61424 - Traveler's Tundra Mammoth
(@CGUID+950, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- 32639 - 61424 - Traveler's Tundra Mammoth
(@CGUID+951, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+952, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161881
(@CGUID+953, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+954, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+955, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+956, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170806
(@CGUID+957, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+958, 0, 0, 0, 1, 0, 0, 0, 0, '343329'), -- 156558 - 343329 - [DNT] - Flavor 2
(@CGUID+959, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+960, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+961, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+962, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+963, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+964, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+965, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+966, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+967, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169634 - 154470 - Permanent Feign Death (Flies)
(@CGUID+968, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+969, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161398 - 314093 - Useful Parts
(@CGUID+970, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+971, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161398 - 314093 - Useful Parts
(@CGUID+972, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+973, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+974, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+975, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169634 - 154470 - Permanent Feign Death (Flies)
(@CGUID+976, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+977, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+978, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+979, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(@CGUID+980, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+981, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161881
(@CGUID+982, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+983, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+984, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165017
(@CGUID+985, 0, 0, 0, 1, 0, 0, 0, 0, '212171'), -- 165017 - 212171 - Read Scroll
(@CGUID+986, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160417
(@CGUID+987, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+988, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(@CGUID+989, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+990, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+991, 0, 0, 0, 1, 0, 0, 0, 0, '319502'), -- 164221 - 319502 - Cosmetic - Slime Cauldron
(@CGUID+992, 0, 0, 0, 1, 0, 0, 0, 0, '343329'), -- 156558 - 343329 - [DNT] - Flavor 2
(@CGUID+993, 0, 0, 0, 1, 0, 0, 0, 0, '144140'), -- 160418 - 144140 - Vertex Color Lime Green
(@CGUID+994, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160419
(@CGUID+995, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169634 - 154470 - Permanent Feign Death (Flies)
(@CGUID+996, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(@CGUID+997, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+998, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+999, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 161376

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+1000, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1001, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1002, 0, 0, 0, 1, 0, 0, 0, 0, '343329'), -- 156558 - 343329 - [DNT] - Flavor 2
(@CGUID+1003, 0, 0, 0, 1, 0, 0, 0, 0, '343800'), -- 156558 - 343800 - [DNT] - Flavor 2
(@CGUID+1004, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+1005, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+1006, 0, 0, 0, 1, 0, 0, 0, 0, '326001'), -- 166908 - 326001 - Summon Creep Area Trigger
(@CGUID+1007, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1008, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1009, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1010, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(@CGUID+1011, 0, 0, 0, 1, 0, 0, 0, 0, '343800'), -- 156558 - 343800 - [DNT] - Flavor 2
(@CGUID+1012, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1013, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1014, 0, 0, 0, 1, 0, 0, 0, 0, '343329'), -- 156558 - 343329 - [DNT] - Flavor 2
(@CGUID+1015, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161397
(@CGUID+1016, 0, 0, 0, 1, 0, 0, 0, 0, '325854'), -- 167435 - 325854 - Bone Tornado
(@CGUID+1017, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+1018, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1019, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1020, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+1021, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1022, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1023, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1024, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1025, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+1026, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1027, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1028, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1029, 0, 0, 0, 1, 0, 0, 0, 0, '319620'), -- 158040 - 319620 - Siphon Anima
(@CGUID+1030, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1031, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1032, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1033, 0, 0, 0, 1, 0, 0, 0, 0, '319620'), -- 158040 - 319620 - Siphon Anima
(@CGUID+1034, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1035, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1036, 0, 0, 0, 1, 0, 0, 0, 0, '319620'), -- 158040 - 319620 - Siphon Anima
(@CGUID+1037, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1038, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1039, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1040, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1041, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1042, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1043, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1044, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1045, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1046, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+1047, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1048, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1049, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1050, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1051, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1052, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1053, 0, 0, 0, 1, 0, 0, 0, 0, '330574'), -- 158040 - 330574 - Deathbolt Rift
(@CGUID+1054, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1055, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1056, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1057, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1058, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1059, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1060, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1061, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1062, 0, 0, 0, 1, 0, 0, 0, 0, '319620'), -- 158040 - 319620 - Siphon Anima
(@CGUID+1063, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1064, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1065, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1066, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1067, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1068, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1069, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1070, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1071, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1072, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1073, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1074, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(@CGUID+1075, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1076, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1077, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1078, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(@CGUID+1079, 0, 0, 0, 0, 0, 0, 0, 0, '244867'), -- 167395 - 244867 - 8.0 Carry Sack New Anim
(@CGUID+1080, 0, 0, 0, 1, 0, 0, 0, 0, '330574'), -- 158040 - 330574 - Deathbolt Rift
(@CGUID+1081, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1082, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1083, 0, 0, 0, 1, 0, 0, 0, 0, '325854'), -- 167435 - 325854 - Bone Tornado
(@CGUID+1084, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1085, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1086, 0, 0, 0, 1, 0, 0, 0, 0, '319620'), -- 158040 - 319620 - Siphon Anima
(@CGUID+1087, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1088, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1089, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(@CGUID+1090, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1091, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1092, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1093, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1094, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168677
(@CGUID+1095, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1096, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169055 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1097, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(@CGUID+1098, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169055
(@CGUID+1099, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169055 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1100, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169055 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1101, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169184
(@CGUID+1102, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(@CGUID+1103, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168677
(@CGUID+1104, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+1105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1106, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 164830 - 46598 - Ride Vehicle Hardcoded
(@CGUID+1107, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164829
(@CGUID+1108, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+1109, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169055
(@CGUID+1110, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 164830 - 46598 - Ride Vehicle Hardcoded
(@CGUID+1111, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+1112, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 164829
(@CGUID+1113, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+1114, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169055
(@CGUID+1115, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 171419 - 323554 - Keen Eyes
(@CGUID+1116, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173944
(@CGUID+1117, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171358
(@CGUID+1118, 0, 96469, 0, 1, 0, 0, 0, 0, ''), -- 170901
(@CGUID+1119, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171358
(@CGUID+1120, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 171419 - 323554 - Keen Eyes
(@CGUID+1121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171358
(@CGUID+1122, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(@CGUID+1123, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1124, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164860
(@CGUID+1125, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 157708
(@CGUID+1126, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1127, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1128, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164829
(@CGUID+1129, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1130, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1131, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 164825 - 323554 - Keen Eyes
(@CGUID+1132, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1133, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 164825 - 323554 - Keen Eyes
(@CGUID+1134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162816
(@CGUID+1135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1136, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 164830 - 46598 - Ride Vehicle Hardcoded
(@CGUID+1137, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162816
(@CGUID+1138, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 164825 - 323554 - Keen Eyes
(@CGUID+1139, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162816
(@CGUID+1140, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 164825 - 323554 - Keen Eyes
(@CGUID+1141, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 157708
(@CGUID+1142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1143, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 164829
(@CGUID+1144, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 164830 - 46598 - Ride Vehicle Hardcoded
(@CGUID+1145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162816
(@CGUID+1147, 0, 96469, 0, 1, 0, 0, 0, 0, ''), -- 170901
(@CGUID+1148, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 164831
(@CGUID+1149, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 164830 - 46598 - Ride Vehicle Hardcoded
(@CGUID+1150, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 164829
(@CGUID+1151, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 157708
(@CGUID+1152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(@CGUID+1153, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173944
(@CGUID+1154, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 164830 - 46598 - Ride Vehicle Hardcoded
(@CGUID+1155, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 164829
(@CGUID+1156, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171358
(@CGUID+1157, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144929
(@CGUID+1158, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144929
(@CGUID+1159, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1160, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168972
(@CGUID+1161, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1162, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1163, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1164, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1165, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Baron Vyraz
(@CGUID+1166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1167, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1168, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1169, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1170, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1171, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 168941
(@CGUID+1172, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1173, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1174, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1175, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1176, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1177, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1178, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 168951
(@CGUID+1179, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1180, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 168951
(@CGUID+1181, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1182, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 168951
(@CGUID+1183, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 157519
(@CGUID+1184, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168952
(@CGUID+1185, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1186, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 160415
(@CGUID+1187, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 160415
(@CGUID+1188, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169359
(@CGUID+1189, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1190, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168946
(@CGUID+1191, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 160415
(@CGUID+1192, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1193, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1194, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1195, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1196, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1197, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1198, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1199, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1200, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1201, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1202, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167483
(@CGUID+1203, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1204, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1205, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1206, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1207, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1208, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1209, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1210, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1211, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 167458 - 99203 - 100% Threat Reduction
(@CGUID+1212, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160424
(@CGUID+1214, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1215, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1216, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+1217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167483
(@CGUID+1218, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1219, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1220, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1221, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1222, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1223, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1224, 0, 0, 0, 1, 0, 0, 0, 0, '325562'), -- 160424 - 325562 - 9.0 Carry Ballista Ammo
(@CGUID+1225, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1226, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+1227, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+1228, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160424
(@CGUID+1229, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 168941
(@CGUID+1230, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1231, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168946
(@CGUID+1232, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 168941
(@CGUID+1233, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+1234, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1235, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1236, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1237, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160479 - 99203 - 100% Threat Reduction
(@CGUID+1238, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1239, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1240, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1241, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144929
(@CGUID+1242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1243, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1244, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1245, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1246, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1248, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160479 - 99203 - 100% Threat Reduction
(@CGUID+1249, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 157671

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+1250, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1251, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+1252, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162498
(@CGUID+1253, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+1254, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144929
(@CGUID+1255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+1256, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1257, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+1258, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1259, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1260, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1261, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1263, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1265, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1266, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162498
(@CGUID+1267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(@CGUID+1268, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1270, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1271, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1272, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1273, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1274, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1275, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1276, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1277, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1278, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 169117
(@CGUID+1279, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1280, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1281, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1282, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1283, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1284, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1285, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1286, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1287, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1288, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1289, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144929
(@CGUID+1290, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1291, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1292, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1293, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1294, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1295, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1296, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1297, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1298, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1299, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1301, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1302, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1303, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1304, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1305, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1306, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1307, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1308, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1309, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1310, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 168941
(@CGUID+1311, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168216
(@CGUID+1312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1313, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 169063
(@CGUID+1314, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1315, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1316, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+1317, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1318, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1319, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1320, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1321, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1322, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1323, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1324, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1325, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1326, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1327, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1328, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1329, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1330, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1332, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1333, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1334, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1335, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1336, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1337, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1338, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1339, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1340, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165366
(@CGUID+1341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1342, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168424
(@CGUID+1343, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1344, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1345, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168946
(@CGUID+1346, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1347, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1348, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1349, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1350, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1351, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1352, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1353, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1354, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1355, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1356, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1357, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1358, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 169103
(@CGUID+1359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1360, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1361, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1362, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1363, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1364, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1365, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1366, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1367, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1368, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1369, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1370, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1371, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1372, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1373, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1374, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1375, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1376, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1377, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1379, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1380, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169063
(@CGUID+1381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169068
(@CGUID+1382, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161016
(@CGUID+1384, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1385, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1387, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1388, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1389, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1390, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1391, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1392, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1393, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1394, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1396, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1397, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1398, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1399, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169103
(@CGUID+1401, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1402, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1403, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1404, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1405, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1406, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1407, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168972
(@CGUID+1408, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+1409, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1410, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1412, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1414, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1416, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169063
(@CGUID+1417, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1418, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1420, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1421, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1422, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1424, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160479 - 99203 - 100% Threat Reduction
(@CGUID+1425, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1426, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1427, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1428, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1429, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165366
(@CGUID+1430, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1431, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1432, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1433, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1434, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169088
(@CGUID+1436, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1437, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1438, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1439, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1440, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1441, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1442, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1443, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1444, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1445, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1446, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1447, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1448, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1449, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1450, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1451, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1452, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1453, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 169117
(@CGUID+1454, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1455, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1456, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1457, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1458, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1459, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1460, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1461, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1462, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1463, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1464, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169063
(@CGUID+1465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1466, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1468, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1469, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1470, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1472, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165366
(@CGUID+1473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1474, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 169063
(@CGUID+1475, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1476, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1477, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1478, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1479, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1480, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1481, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1482, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1483, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1484, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1485, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1486, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1487, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1488, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1489, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1490, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1491, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1492, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1493, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1494, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1495, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1496, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1497, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1498, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1499, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 167356

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+1500, 0, 0, 0, 1, 0, 0, 0, 0, '313127'), -- 160883 - 313127 - Abomination - Visual - Extra - Maps
(@CGUID+1501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1502, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160884
(@CGUID+1503, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1504, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1505, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1507, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1508, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1510, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1511, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1512, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1513, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1514, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1515, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1516, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1517, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169117
(@CGUID+1518, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1519, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1520, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1521, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1522, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169068
(@CGUID+1523, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1524, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1525, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1526, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1527, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1528, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1529, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1532, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1533, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1534, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1535, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1536, 0, 0, 0, 1, 0, 0, 0, 0, '99203 319935'), -- 156591 - 99203 - 100% Threat Reduction, 319935 - Disease Cloud
(@CGUID+1537, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169063
(@CGUID+1538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160996
(@CGUID+1540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165644
(@CGUID+1541, 0, 0, 0, 1, 0, 0, 0, 0, '326019'), -- 167271 - 326019 - 9.0 Carry Ballista Ammo
(@CGUID+1542, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1543, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 169117
(@CGUID+1544, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1545, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1546, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1547, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1548, 0, 0, 0, 1, 0, 0, 0, 0, '328701'), -- 167271 - 328701 - 9.0 Carry Maldraxxus Bomb
(@CGUID+1549, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1550, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1551, 0, 0, 50331648, 1, 0, 0, 0, 0, '292177'), -- 160976 - 292177 - Turn In Circle Visual
(@CGUID+1552, 0, 0, 0, 1, 0, 0, 0, 0, '328701'), -- 167271 - 328701 - 9.0 Carry Maldraxxus Bomb
(@CGUID+1553, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161026
(@CGUID+1554, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1555, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1556, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1557, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1558, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(@CGUID+1559, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1560, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1561, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1562, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1563, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1564, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1565, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1566, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1567, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1568, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1569, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1570, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1571, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1572, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1573, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1574, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1575, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160424
(@CGUID+1576, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1577, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1578, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160424
(@CGUID+1579, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168946
(@CGUID+1580, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1581, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1582, 0, 0, 0, 1, 0, 0, 0, 0, '320013'), -- 160479 - 320013 - Massacre
(@CGUID+1583, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1584, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1585, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1586, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1587, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1588, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1589, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1590, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1591, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1592, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1593, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1594, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1595, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1596, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1597, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1598, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160948
(@CGUID+1599, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1600, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1601, 0, 0, 50331648, 1, 0, 0, 0, 0, '292177'), -- 160978 - 292177 - Turn In Circle Visual
(@CGUID+1602, 0, 0, 0, 1, 0, 0, 0, 0, '329598'), -- 160948 - 329598 - Explosive Charge
(@CGUID+1603, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161027
(@CGUID+1604, 0, 0, 50593792, 1, 0, 0, 0, 0, '154470'), -- 169129 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1605, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 169395 - 331874 - Touch of Plague
(@CGUID+1606, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1607, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1608, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160954
(@CGUID+1609, 0, 0, 50331648, 1, 0, 0, 0, 0, '292177'), -- 160979 - 292177 - Turn In Circle Visual
(@CGUID+1610, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161028
(@CGUID+1611, 0, 0, 0, 1, 0, 0, 0, 0, '329598'), -- 160954 - 329598 - Explosive Charge
(@CGUID+1612, 0, 0, 50397184, 1, 0, 0, 0, 0, '315067'), -- 169999 - 315067 - Ghost
(@CGUID+1613, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 169395 - 331874 - Touch of Plague
(@CGUID+1614, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 174024 - 151051 - Mod Scale 70-130%
(@CGUID+1615, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 169395 - 331874 - Touch of Plague
(@CGUID+1616, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 169395 - 331874 - Touch of Plague
(@CGUID+1617, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 174024 - 151051 - Mod Scale 70-130%
(@CGUID+1618, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 169395 - 331874 - Touch of Plague
(@CGUID+1619, 0, 0, 50331648, 1, 0, 0, 0, 0, '151051'), -- 174024 - 151051 - Mod Scale 70-130%
(@CGUID+1620, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 169395 - 331874 - Touch of Plague
(@CGUID+1621, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 174024 - 151051 - Mod Scale 70-130%
(@CGUID+1622, 0, 0, 50593792, 1, 0, 0, 0, 0, '154470'), -- 169129 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1623, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1624, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1625, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk
(@CGUID+1626, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1627, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1628, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168315 - 123169 - Mod Scale 105-110%
(@CGUID+1629, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 169696 - 123169 - Mod Scale 105-110%
(@CGUID+1630, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807 328964'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk, 328964 - Slimed Cosmetic
(@CGUID+1631, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1632, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168574 - 123169 - Mod Scale 105-110%
(@CGUID+1633, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1634, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1635, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 174877 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1636, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1637, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168155 - 123169 - Mod Scale 105-110%
(@CGUID+1638, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168153
(@CGUID+1639, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1640, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1641, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1642, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 169696 - 123169 - Mod Scale 105-110%
(@CGUID+1643, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1644, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168578 - 123169 - Mod Scale 105-110%
(@CGUID+1645, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 168364 - 151051 - Mod Scale 70-130%
(@CGUID+1646, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327494 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1647, 0, 0, 3, 1, 0, 0, 0, 0, '327881'), -- 168153 - 327881 - Cosmetic - Sleep Zzz
(@CGUID+1648, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1649, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1650, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874 328964'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 328964 - Slimed Cosmetic
(@CGUID+1651, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1652, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1653, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1654, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 174877 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1655, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1656, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169218 - 244807 - Anim Replacement - New Drunk
(@CGUID+1657, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168580 - 123169 - Mod Scale 105-110%
(@CGUID+1658, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168365 - 123169 - Mod Scale 105-110%
(@CGUID+1659, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 337684'), -- 172335 - 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death
(@CGUID+1660, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1661, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327484 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327484 - Plague Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1662, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1663, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1664, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1665, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327494 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1666, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1667, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168314 - 123169 - Mod Scale 105-110%
(@CGUID+1668, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168298 - 123169 - Mod Scale 105-110%
(@CGUID+1669, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1670, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1671, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1672, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1673, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168310 - 123169 - Mod Scale 105-110%
(@CGUID+1674, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1675, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1676, 0, 0, 0, 1, 0, 0, 0, 0, '123169 323486'), -- 168572 - 123169 - Mod Scale 105-110%, 323486 - Dual Wield
(@CGUID+1677, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 169696 - 123169 - Mod Scale 105-110%
(@CGUID+1678, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1679, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168298 - 123169 - Mod Scale 105-110%
(@CGUID+1680, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168574 - 123169 - Mod Scale 105-110%
(@CGUID+1681, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1682, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807 328963'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk, 328963 - Vomit
(@CGUID+1683, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1684, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1685, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1686, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1687, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1688, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1689, 0, 0, 0, 1, 0, 0, 0, 0, '327881'), -- 168153 - 327881 - Cosmetic - Sleep Zzz
(@CGUID+1690, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 169696 - 123169 - Mod Scale 105-110%
(@CGUID+1691, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1692, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168155 - 123169 - Mod Scale 105-110%
(@CGUID+1693, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1694, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1695, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk
(@CGUID+1696, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1697, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1698, 0, 0, 0, 1, 0, 0, 0, 0, '123169 323486'), -- 168572 - 123169 - Mod Scale 105-110%, 323486 - Dual Wield
(@CGUID+1699, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 337684'), -- 172336 - 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death
(@CGUID+1700, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807 255051'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk, 255051 - Vomit
(@CGUID+1701, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk
(@CGUID+1702, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1703, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168578 - 123169 - Mod Scale 105-110%
(@CGUID+1704, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1705, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168365 - 123169 - Mod Scale 105-110%
(@CGUID+1706, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 337684'), -- 172335 - 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death
(@CGUID+1707, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1708, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327494 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1709, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1710, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1711, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1712, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169218 - 244807 - Anim Replacement - New Drunk
(@CGUID+1713, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168153
(@CGUID+1714, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1715, 0, 0, 50331648, 1, 0, 0, 0, 0, '330738'), -- 169843 - 330738 - Test Swim Animation
(@CGUID+1716, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1717, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327494 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1718, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1719, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168965 - 123169 - Mod Scale 105-110%
(@CGUID+1720, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1721, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874 328964'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 328964 - Slimed Cosmetic
(@CGUID+1722, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1723, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1724, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1725, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1726, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 168364 - 151051 - Mod Scale 70-130%
(@CGUID+1727, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168365 - 123169 - Mod Scale 105-110%
(@CGUID+1728, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1729, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1730, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1731, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328020'), -- 168580 - 123169 - Mod Scale 105-110%, 328020 - Plagueborer Base
(@CGUID+1732, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1733, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 168364 - 151051 - Mod Scale 70-130%
(@CGUID+1734, 0, 0, 0, 1, 0, 0, 0, 0, '123169 18950 343918 320040'), -- 163882 - 123169 - Mod Scale 105-110%, 18950 - Invisibility and Stealth Detection, 343918 - Oozing Slime, 320040 - Plagued Carrion
(@CGUID+1735, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169218 - 244807 - Anim Replacement - New Drunk
(@CGUID+1736, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1737, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327494 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1738, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1739, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327494 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1740, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1741, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 169696 - 123169 - Mod Scale 105-110%
(@CGUID+1742, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168314 - 123169 - Mod Scale 105-110%
(@CGUID+1743, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1744, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168315 - 123169 - Mod Scale 105-110%
(@CGUID+1745, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328020'), -- 168580 - 123169 - Mod Scale 105-110%, 328020 - Plagueborer Base
(@CGUID+1746, 0, 0, 3, 1, 0, 0, 0, 0, '327881'), -- 168153 - 327881 - Cosmetic - Sleep Zzz
(@CGUID+1747, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 337684'), -- 172335 - 123169 - Mod Scale 105-110%, 337684 - Spawn Feign Death
(@CGUID+1748, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327494 35356'), -- 168155 - 123169 - Mod Scale 105-110%, 327494 - Slimed Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1749, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 163931

REPLACE INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+1750, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 168364 - 151051 - Mod Scale 70-130%
(@CGUID+1751, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1752, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk
(@CGUID+1753, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1754, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1755, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168580 - 123169 - Mod Scale 105-110%
(@CGUID+1756, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1757, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169218 - 244807 - Anim Replacement - New Drunk
(@CGUID+1758, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1759, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1760, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 174877 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1761, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1762, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169218 - 244807 - Anim Replacement - New Drunk
(@CGUID+1763, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 168364 - 151051 - Mod Scale 70-130%
(@CGUID+1764, 0, 0, 7, 1, 0, 0, 0, 0, '123169 330271'), -- 169696 - 123169 - Mod Scale 105-110%, 330271 - Cosmetic - Sleep Zzz
(@CGUID+1765, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168578 - 123169 - Mod Scale 105-110%
(@CGUID+1766, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1767, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168580 - 123169 - Mod Scale 105-110%
(@CGUID+1768, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1769, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1770, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 174877 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1771, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1772, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1773, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 244807 - Anim Replacement - New Drunk
(@CGUID+1774, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 168364 - 151051 - Mod Scale 70-130%
(@CGUID+1775, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1776, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168365 - 123169 - Mod Scale 105-110%
(@CGUID+1777, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874 328964'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague, 328964 - Slimed Cosmetic
(@CGUID+1778, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1779, 0, 0, 0, 1, 0, 0, 0, 0, '123169 323486'), -- 168572 - 123169 - Mod Scale 105-110%, 323486 - Dual Wield
(@CGUID+1780, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1781, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1782, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1783, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1784, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1785, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1786, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1787, 0, 0, 7, 1, 0, 0, 0, 0, '123169'), -- 168155 - 123169 - Mod Scale 105-110%
(@CGUID+1788, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1789, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1790, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1791, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1792, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1793, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1794, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1795, 0, 0, 1, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1796, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - 123169 - Mod Scale 105-110%
(@CGUID+1797, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1798, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1799, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169218 - 244807 - Anim Replacement - New Drunk
(@CGUID+1800, 0, 0, 0, 1, 0, 0, 0, 0, '244807 329078'), -- 169201 - 244807 - Anim Replacement - New Drunk, 329078 - Vomit
(@CGUID+1801, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 168968 - 123169 - Mod Scale 105-110%, 331874 - Touch of Plague
(@CGUID+1802, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(@CGUID+1803, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328020'), -- 168580 - 123169 - Mod Scale 105-110%, 328020 - Plagueborer Base
(@CGUID+1804, 0, 0, 0, 1, 0, 0, 0, 0, '324366 324304 346098 324284'), -- 164255 - 324366 - Living Slime Flesh, 324304 - Slime Energy Bar, 346098 - Festive Globgrog, 324284 - Slime Infused Bones
(@CGUID+1805, 0, 0, 0, 1, 0, 0, 0, 0, '123169 323486'), -- 168572 - 123169 - Mod Scale 105-110%, 323486 - Dual Wield
(@CGUID+1806, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(@CGUID+1807, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1808, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - 123169 - Mod Scale 105-110%, 311242 - Lively Eggs
(@CGUID+1809, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168153
(@CGUID+1810, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1811, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 70628 - Permanent Feign Death
(@CGUID+1812, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 172063 - 244807 - Anim Replacement - New Drunk
(@CGUID+1813, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169201 - 244807 - Anim Replacement - New Drunk
(@CGUID+1814, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1815, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1816, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1817, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1818, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1819, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171573 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1820, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1821, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1822, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1823, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1824, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1825, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1826, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1827, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171572 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1828, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1829, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1830, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171572 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1831, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168391
(@CGUID+1832, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1833, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168365 - 123169 - Mod Scale 105-110%
(@CGUID+1834, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1835, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1836, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1837, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171574 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1838, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1839, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1840, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1841, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1842, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1843, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1844, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - 123169 - Mod Scale 105-110%, 328965 - Fertilizer
(@CGUID+1845, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171572 - 123169 - Mod Scale 105-110%, 327480 - Blood Cosmetic, 35356 - Spawn Feign Death
(@CGUID+1846, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - 346989 - Reactive Slimeflesh, 328662 - Slime Coated, 333740 - Slime, 328661 - Gushing Slime
(@CGUID+1847, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1848, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168386
(@CGUID+1849, 0, 0, 0, 1, 0, 0, 0, 0, '244807 327591'), -- 168393 - 244807 - Anim Replacement - New Drunk, 327591 - Slimy Morsel
(@CGUID+1850, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1851, 0, 0, 0, 1, 0, 0, 0, 0, '244807 327595'), -- 168396 - 244807 - Anim Replacement - New Drunk, 327595 - Slimy Morsel
(@CGUID+1852, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1853, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1854, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(@CGUID+1855, 0, 0, 0, 1, 0, 0, 0, 0, '334640'), -- 171474 - 334640 - Appetizer
(@CGUID+1856, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - 147490 - Healing Rain Visual
(@CGUID+1857, 0, 0, 0, 1, 0, 0, 0, 0, '328701'), -- 167271 - 328701 - 9.0 Carry Maldraxxus Bomb
(@CGUID+1858, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1859, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1860, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1861, 0, 0, 0, 1, 0, 0, 0, 0, '328701'), -- 167271 - 328701 - 9.0 Carry Maldraxxus Bomb
(@CGUID+1862, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1863, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1864, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1865, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1866, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1867, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1868, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1869, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1870, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160955
(@CGUID+1871, 0, 0, 0, 1, 0, 0, 0, 0, '329598'), -- 160955 - 329598 - Explosive Charge
(@CGUID+1872, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1873, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161105
(@CGUID+1874, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1875, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160996
(@CGUID+1876, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1877, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1878, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1879, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1880, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1881, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1882, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1883, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1884, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1885, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1886, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1887, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1888, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1889, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1890, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1891, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169223
(@CGUID+1892, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1893, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1894, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1895, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 99203 - 100% Threat Reduction
(@CGUID+1896, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1897, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169226
(@CGUID+1898, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169223
(@CGUID+1899, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169223
(@CGUID+1900, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169223
(@CGUID+1901, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1902, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169223
(@CGUID+1903, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169223
(@CGUID+1904, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1905, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167273 - 99203 - 100% Threat Reduction
(@CGUID+1906, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 157671 - 154470 - Permanent Feign Death (Flies)
(@CGUID+1907, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1908, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(@CGUID+1909, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160479 - 99203 - 100% Threat Reduction
(@CGUID+1910, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1911, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1912, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1913, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1914, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157671
(@CGUID+1915, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1916, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1917, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1918, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1919, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1920, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1921, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1922, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1923, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1924, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(@CGUID+1925, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1926, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(@CGUID+1927, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160996
(@CGUID+1928, 0, 0, 0, 1, 0, 0, 0, 0, '326019'), -- 167271 - 326019 - 9.0 Carry Ballista Ammo
(@CGUID+1929, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1930, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1931, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1932, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1933, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1934, 0, 0, 0, 1, 0, 0, 0, 0, '326019'), -- 167271 - 326019 - 9.0 Carry Ballista Ammo
(@CGUID+1935, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1936, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(@CGUID+1937, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1938, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1939, 0, 0, 0, 0, 0, 0, 0, 0, '99203'), -- 169170 - 99203 - 100% Threat Reduction
(@CGUID+1940, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1941, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1942, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1943, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1944, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1945, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(@CGUID+1946, 0, 0, 0, 0, 0, 0, 0, 0, '99203'), -- 169170 - 99203 - 100% Threat Reduction
(@CGUID+1947, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1948, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169161
(@CGUID+1949, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1950, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1951, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1952, 0, 0, 0, 1, 0, 0, 0, 0, '326019'), -- 167271 - 326019 - 9.0 Carry Ballista Ammo
(@CGUID+1953, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 99203 - 100% Threat Reduction
(@CGUID+1954, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1955, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1956, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1957, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1958, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(@CGUID+1959, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 99203 - 100% Threat Reduction
(@CGUID+1960, 0, 0, 0, 1, 0, 0, 0, 0, '99203'); -- 156591 - 99203 - 100% Threat Reduction

SET @OGUID := 25347557;
REPLACE INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 353391, 2222, 11462, 11466, '0', '0', 0, 1610.39306640625, -1880.748046875, 3414.51123046875, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353391 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+1, 350775, 2222, 11462, 11466, '0', '0', 0, 1720.657958984375, -3421.585205078125, 3231.952392578125, 4.511682033538818359, 0.166051387786865234, -0.11202812194824218, -0.76579475402832031, 0.611093342304229736, 120, 255, 1, 36839), -- 350775 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+2, 355424, 2222, 11462, 11466, '0', '0', 0, 1029.6214599609375, -3669.460693359375, 3066.897705078125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 36839), -- 355424 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+3, 354927, 2222, 11462, 11466, '0', '0', 0, 931.85418701171875, -2238.91845703125, 3653.73876953125, 2.312558174133300781, 0, 0, 0.915310859680175781, 0.402748137712478637, 120, 255, 1, 36839), -- 354927 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+4, 353633, 2222, 11462, 11466, '0', '0', 0, 1056.7315673828125, -3688.344482421875, 3078.095458984375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 0, 36839), -- 353633 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+5, 353392, 2222, 11462, 11466, '0', '0', 0, 1604.9605712890625, -1859.101318359375, 3414.51123046875, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353392 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+6, 364864, 2222, 11462, 11466, '0', '0', 0, 1433.345703125, -1490.1754150390625, 3474.117919921875, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 36839), -- 364864 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+7, 364865, 2222, 11462, 11466, '0', '0', 0, 2422.298828125, -3573.500244140625, 3313.175048828125, 3.143882274627685546, 0, 0.02617645263671875, -0.99965667724609375, 0.001145121059380471, 120, 255, 1, 36839), -- 364865 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+8, 353389, 2222, 11462, 11466, '0', '0', 0, 1521.06640625, -1814.4742431640625, 3414.6806640625, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353389 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+9, 353390, 2222, 11462, 11466, '0', '0', 0, 1534.5711669921875, -1821.37158203125, 3414.485595703125, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353390 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+10, 352577, 2222, 11462, 11466, '0', '0', 0, 1959.328125, -2547.807373046875, 3371.955322265625, 6.248591899871826171, 0.000445365905761718, -0.00007343292236328, -0.01729583740234375, 0.999850332736968994, 120, 255, 1, 36839), -- 352577 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+11, 356600, 2222, 11462, 11466, '0', '0', 0, 1709.3072509765625, -2547.951416015625, 3529.5517578125, 6.245278358459472656, 0, 0, -0.0189523696899414, 0.999820411205291748, 120, 255, 1, 36839), -- 356600 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+12, 355424, 2222, 11462, 11466, '0', '0', 0, 1029.6214599609375, -3669.460693359375, 3066.897705078125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 36839), -- 355424 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+13, 353616, 2222, 11462, 11466, '0', '0', 0, 1459.8038330078125, -3307.388916015625, 3417.548828125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 353616 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+14, 353601, 2222, 11462, 11466, '0', '0', 0, 3026.954833984375, -2687.614501953125, 3449.813720703125, 0.031194044277071952, 0, 0, 0.015596389770507812, 0.999878346920013427, 120, 255, 1, 36839), -- 353601 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+15, 364864, 2222, 11462, 11466, '0', '0', 0, 1433.345703125, -1490.1754150390625, 3474.117919921875, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 120, 255, 1, 36839), -- 364864 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+16, 364865, 2222, 11462, 11466, '0', '0', 0, 2422.298828125, -3573.500244140625, 3313.175048828125, 3.143882274627685546, 0, 0.02617645263671875, -0.99965667724609375, 0.001145121059380471, 120, 255, 1, 36839), -- 364865 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+17, 336675, 2222, 11462, 11466, '0', '0', 0, 1937.03125, -1700.4166259765625, 3489.624755859375, 2.797574281692504882, 0, 0, 0.985242843627929687, 0.171162247657775878, 120, 255, 1, 36839), -- 336675 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+18, 354927, 2222, 11462, 11466, '0', '0', 0, 931.85418701171875, -2238.91845703125, 3653.73876953125, 2.312558174133300781, 0, 0, 0.915310859680175781, 0.402748137712478637, 120, 255, 1, 36839), -- 354927 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+19, 353601, 2222, 11462, 11466, '0', '0', 0, 2004.984375, -1590.126708984375, 3556.466796875, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 353601 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+20, 353633, 2222, 11462, 11466, '0', '0', 0, 1056.7315673828125, -3688.344482421875, 3078.095458984375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 0, 36839), -- 353633 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+21, 350775, 2222, 11462, 11466, '0', '0', 0, 1720.657958984375, -3421.585205078125, 3231.952392578125, 4.511682033538818359, 0.166051387786865234, -0.11202812194824218, -0.76579475402832031, 0.611093342304229736, 120, 255, 1, 36839), -- 350775 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+22, 353392, 2222, 11462, 11466, '0', '0', 0, 1604.9605712890625, -1859.101318359375, 3414.51123046875, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353392 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+23, 353389, 2222, 11462, 11466, '0', '0', 0, 1521.06640625, -1814.4742431640625, 3414.6806640625, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353389 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+24, 353390, 2222, 11462, 11466, '0', '0', 0, 1534.5711669921875, -1821.37158203125, 3414.485595703125, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353390 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+25, 353391, 2222, 11462, 11466, '0', '0', 0, 1610.39306640625, -1880.748046875, 3414.51123046875, 1.064651846885681152, 0, 0, 0.507538795471191406, 0.861628890037536621, 120, 255, 1, 36839), -- 353391 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+26, 356599, 2222, 11462, 11466, '0', '0', 0, 1901.7274169921875, -2612.072998046875, 3398.223876953125, 3.131633520126342773, 0, 0, 0.999987602233886718, 0.004979511257261037, 120, 255, 1, 36839), -- 356599 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+27, 355042, 2222, 11462, 11466, '0', '0', 0, 1851.8160400390625, -2547.890625, 3384.128173828125, 3.163862228393554687, 0, 0, -0.99993801116943359, 0.011134525761008262, 120, 255, 1, 36839), -- 355042 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+28, 357089, 2222, 11462, 11466, '0', '0', 0, 1724.50537109375, -2547.724609375, 3386.95947265625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 36839), -- 357089 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+29, 351447, 2222, 11462, 11466, '0', '0', 0, 1849.52783203125, -2460.307373046875, 3395.186767578125, 4.711261749267578125, 0, 0, -0.7075052261352539, 0.706708133220672607, 120, 255, 1, 36839), -- 351447 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+30, 355451, 2222, 11462, 11466, '0', '0', 0, 1876.8681640625, -2538.2890625, 3388.03857421875, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 120, 255, 1, 36839), -- 355451 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+31, 358871, 2222, 11462, 11466, '0', '0', 0, 1833.8687744140625, -2572.810302734375, 3390.80419921875, 2.240999937057495117, 0, 0, 0.900318145751953125, 0.435232430696487426, 120, 255, 1, 36839), -- 358871 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+32, 364892, 2222, 11462, 11466, '0', '0', 0, 1830.140625, -2569.439208984375, 3384.97998046875, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 364892 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+33, 358872, 2222, 11462, 11466, '0', '0', 0, 1829.6005859375, -2574.700439453125, 3389.037841796875, 1.692405223846435546, 0, 0, 0.748768806457519531, 0.662831246852874755, 120, 255, 1, 36839), -- 358872 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+34, 358873, 2222, 11462, 11466, '0', '0', 0, 1835.9671630859375, -2568.83544921875, 3389.037841796875, 5.751413822174072265, 0, 0, -0.26276397705078125, 0.964860141277313232, 120, 255, 1, 36839), -- 358873 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+35, 353764, 2222, 11462, 11466, '0', '0', 0, 1952.203125, -2680.901123046875, 3332.95556640625, 5.323255538940429687, 0, 0, -0.46174812316894531, 0.887011110782623291, 120, 255, 1, 36839), -- 353764 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+36, 353378, 2222, 11462, 11466, '0', '0', 0, 1954.890625, -2972.880126953125, 3257.919921875, 2.708066701889038085, 0, 0, 0.976598739624023437, 0.21506945788860321, 120, 255, 1, 36839), -- 353378 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+37, 252245, 2222, 11462, 11466, '0', '0', 0, 2081.96875, -3118.607666015625, 3274.980712890625, 0.747357308864593505, 0, 0, 0.365042686462402343, 0.930990755558013916, 120, 255, 1, 36839), -- 252245 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+38, 353614, 2222, 11462, 11466, '0', '0', 0, 3387.661376953125, -3639.007080078125, 3607.530517578125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 353614 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+39, 349981, 2222, 11462, 11466, '0', '0', 0, 2200.114501953125, -2836.085205078125, 3266.339111328125, 0.128338396549224853, 0.21289825439453125, 0.195097923278808593, 0.018836021423339843, 0.957212805747985839, 120, 255, 1, 36839), -- 349981 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+40, 353602, 2222, 11462, 12899, '0', '0', 0, 3753.595458984375, -2643.947998046875, 3492.723388671875, 3.183300256729125976, 0, 0, -0.99978256225585937, 0.020852239802479743, 120, 255, 1, 36839), -- 353602 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+41, 336691, 2222, 11462, 12899, '0', '0', 0, 2268.194580078125, -2811.380126953125, 3264.581298828125, 6.113981246948242187, 0, 0, -0.08450126647949218, 0.99642336368560791, 120, 255, 1, 36839), -- 336691 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+42, 252145, 2222, 11462, 12899, '0', '0', 0, 2595.97216796875, -2718.4375, 3291.812744140625, 3.797177553176879882, 0, 0, -0.94675540924072265, 0.321953743696212768, 120, 255, 1, 36839), -- 252145 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+43, 353378, 2222, 11462, 12899, '0', '0', 0, 2563, -2641.880126953125, 3305.6298828125, 2.575614452362060546, 0, 0, 0.960225105285644531, 0.279227077960968017, 120, 255, 1, 36839), -- 353378 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+44, 353645, 2222, 11462, 12899, '0', '0', 0, 2413.2431640625, -2933.94091796875, 3272.073974609375, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 353645 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+45, 338858, 2222, 11462, 12899, '0', '0', 0, 2414.048583984375, -2928.826416015625, 3270.90966796875, 4.73419046401977539, 0, 0, -0.6993570327758789, 0.714772522449493408, 120, 255, 1, 36839), -- 338858 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+46, 351470, 2222, 11462, 13406, '0', '0', 0, 2331.4619140625, -2887.767333984375, 3252.0126953125, 1.581584811210632324, 0, 0, 0.710910797119140625, 0.703282177448272705, 120, 255, 1, 36839), -- 351470 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@OGUID+47, 351470, 2222, 11462, 13406, '0', '0', 0, 2404.30908203125, -2772.498291015625, 3252.51953125, 6.044415473937988281, 0, 0, -0.11910152435302734, 0.992882072925567626, 120, 255, 1, 36839), -- 351470 (Area: Valley of a Thousand Legs - Difficulty: 0)
(@OGUID+48, 340712, 2222, 11462, 12899, '0', '0', 0, 2415.178955078125, -2935.236083984375, 3272.235595703125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 340712 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+49, 340713, 2222, 11462, 12899, '0', '0', 0, 2420.303955078125, -2935.541748046875, 3271.177001953125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 340713 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+50, 346054, 2222, 11462, 12899, '0', '0', 0, 2414.048583984375, -2928.826416015625, 3270.90966796875, 4.73419046401977539, 0, 0, -0.6993570327758789, 0.714772522449493408, 120, 255, 0, 36839), -- 346054 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+51, 351470, 2222, 11462, 12899, '0', '0', 0, 2178.729248046875, -2988.822998046875, 3243.04052734375, 3.694653987884521484, 0, 0, -0.96200847625732421, 0.273019641637802124, 120, 255, 1, 36839), -- 351470 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+52, 336689, 2222, 11462, 12899, '0', '0', 0, 2178.729248046875, -2988.822998046875, 3243.04052734375, 3.694653987884521484, 0, 0, -0.96200847625732421, 0.273019641637802124, 120, 255, 1, 36839), -- 336689 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+53, 351470, 2222, 11462, 12899, '0', '0', 0, 2280.38720703125, -2946.9462890625, 3243.022705078125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 351470 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+54, 354969, 2222, 11462, 12899, '0', '0', 0, 2165.755126953125, -3106.826416015625, 3240.544189453125, 1.335176706314086914, 0, 0, 0.619093894958496093, 0.785317003726959228, 120, 255, 1, 36839), -- 354969 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+55, 349898, 2222, 11462, 12899, '0', '0', 0, 2273.23095703125, -3234.0244140625, 3272.60595703125, 2.889994621276855468, 0.070490360260009765, -0.12530994415283203, 0.980485916137695312, 0.134074106812477111, 120, 255, 1, 36839), -- 349898 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+56, 351470, 2222, 11462, 12899, '0', '0', 0, 2242.166748046875, -3296.326416015625, 3277.40673828125, 0.677294552326202392, 0, 0, 0.332211494445800781, 0.943204939365386962, 120, 255, 1, 36839), -- 351470 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+57, 353399, 2222, 11462, 12899, '0', '0', 0, 3691.83203125, -3908.101806640625, 3430.197265625, 2.015851974487304687, 0, 0, 0.845726966857910156, 0.533615827560424804, 120, 255, 1, 36839), -- 353399 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+58, 336689, 2222, 11462, 12899, '0', '0', 0, 2246.220458984375, -3140.423583984375, 3252.50439453125, 4.432201385498046875, 0, 0, -0.79891681671142578, 0.601441562175750732, 120, 255, 1, 36839), -- 336689 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+59, 179944, 2222, 11462, 12899, '0', '0', 0, 2164.224609375, -3098.605224609375, 3239.997802734375, 4.473245620727539062, 0, 0, -0.78640651702880859, 0.617709338665008544, 120, 255, 0, 36839), -- 179944 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+60, 179944, 2222, 11462, 12899, '0', '0', 0, 2164.224609375, -3098.605224609375, 3239.997802734375, 4.473245620727539062, 0, 0, -0.78640651702880859, 0.617709338665008544, 120, 255, 0, 36839), -- 179944 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+61, 355921, 2222, 11462, 12899, '0', '0', 0, 1564.7691650390625, -3008.239501953125, 3310.32958984375, 0.511433005332946777, 0.094694137573242187, 0.523952484130859375, 0.086386680603027343, 0.842047572135925292, 120, 255, 1, 36839), -- 355921 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+62, 349898, 2222, 11462, 12899, '0', '0', 0, 1892.296875, -2974.505126953125, 3271.068359375, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 349898 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+63, 340666, 2222, 11462, 12899, '0', '0', 0, 1827.064208984375, -3178.598876953125, 3243.538330078125, 3.489941358566284179, 0, 0, -0.98486995697021484, 0.17329496145248413, 120, 255, 1, 36839), -- 340666 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+64, 346058, 2222, 11462, 12899, '0', '0', 0, 1796.40283203125, -3184.876708984375, 3243.52197265625, 0.136297807097434997, 0, 0, 0.068096160888671875, 0.997678756713867187, 120, 255, 1, 36839), -- 346058 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+65, 340666, 2222, 11462, 12899, '0', '0', 0, 1800.689208984375, -3188.442626953125, 3243.538330078125, 3.444812536239624023, 0, 0, -0.98852920532226562, 0.151029735803604125, 120, 255, 1, 36839), -- 340666 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+66, 354469, 2222, 11462, 12899, '0', '0', 0, 1795.7413330078125, -3029.97216796875, 3277.829345703125, 3.167797565460205078, 0, 0, -0.99991416931152343, 0.013101960532367229, 120, 255, 1, 36839), -- 354469 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+67, 349109, 2222, 11462, 12899, '0', '0', 0, 1786.1666259765625, -3036.45654296875, 3277.829833984375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 36839), -- 349109 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+68, 365130, 2222, 11462, 12899, '0', '0', 0, 1795.8211669921875, -3099.75, 3257.19091796875, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 365130 (Area: Blighted Scar - Difficulty: 0)
(@OGUID+69, 358579, 2222, 11462, 13305, '0', '0', 0, 1823.4322509765625, -3138.1181640625, 3248.51953125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 358579 (Area: Plague Watch - Difficulty: 0)
(@OGUID+70, 365130, 2222, 11462, 13305, '0', '0', 0, 1789.2603759765625, -3112.70654296875, 3257.48291015625, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 365130 (Area: Plague Watch - Difficulty: 0)
(@OGUID+71, 349810, 2222, 11462, 13305, '0', '0', 0, 1825.704833984375, -3139.671875, 3248.818115234375, 1.024119973182678222, 0, 0, 0.489974021911621093, 0.871737062931060791, 120, 255, 1, 36839), -- 349810 (Area: Plague Watch - Difficulty: 0)
(@OGUID+72, 365130, 2222, 11462, 13305, '0', '0', 0, 1739.74658203125, -3054.8525390625, 3258.723876953125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 365130 (Area: Plague Watch - Difficulty: 0)
(@OGUID+73, 354678, 2222, 11462, 13305, '0', '0', 0, 1758.701416015625, -3131.39404296875, 3257.89013671875, 4.265032768249511718, 0, 0, -0.84634017944335937, 0.532642722129821777, 120, 255, 1, 36839), -- 354678 (Area: Plague Watch - Difficulty: 0)
(@OGUID+74, 354678, 2222, 11462, 13305, '0', '0', 0, 1762.892333984375, -3130.279541015625, 3257.907470703125, 5.755410194396972656, 0, 0, -0.26083564758300781, 0.96538323163986206, 120, 255, 1, 36839), -- 354678 (Area: Plague Watch - Difficulty: 0)
(@OGUID+75, 293675, 2222, 11462, 13305, '0', '0', 0, 1704.21875, -3094.45654296875, 3257.438720703125, 0, 0, 0, 0, 1, 120, 255, 0, 36839), -- 293675 (Area: Plague Watch - Difficulty: 0)
(@OGUID+76, 355917, 2222, 11462, 13305, '0', '0', 0, 1580.720458984375, -3137.72216796875, 3247.741455078125, 0.102427423000335693, 0, 0, 0.051191329956054687, 0.998688876628875732, 120, 255, 1, 36839), -- 355917 (Area: Plague Watch - Difficulty: 0)
(@OGUID+77, 365130, 2222, 11462, 13305, '0', '0', 0, 1716.670166015625, -3113.342041015625, 3257.1328125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 365130 (Area: Plague Watch - Difficulty: 0)
(@OGUID+78, 354470, 2222, 11462, 13305, '0', '0', 0, 1749.7257080078125, -3136.255126953125, 3258.816162109375, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 354470 (Area: Plague Watch - Difficulty: 0)
(@OGUID+79, 354678, 2222, 11462, 13305, '0', '0', 0, 1698.295166015625, -3094.569580078125, 3257.380126953125, 3.852961063385009765, 0, 0, -0.937408447265625, 0.348231822252273559, 120, 255, 1, 36839), -- 354678 (Area: Plague Watch - Difficulty: 0)
(@OGUID+80, 355916, 2222, 11462, 13305, '0', '0', 0, 1553.5504150390625, -3066.09375, 3248.333251953125, 0.077095046639442443, 0, 0, 0.038537979125976562, 0.999257147312164306, 120, 255, 1, 36839), -- 355916 (Area: Plague Watch - Difficulty: 0)
(@OGUID+81, 353760, 2222, 11462, 12775, '0', '0', 0, 1827.0347900390625, -3178.625, 3245.778564453125, 3.484752416610717773, 0, 0, -0.98531627655029296, 0.170739144086837768, 120, 255, 1, 36839), -- 353760 (Area: House of Plagues - Difficulty: 0)
(@OGUID+82, 353760, 2222, 11462, 12775, '0', '0', 0, 1800.6632080078125, -3188.427001953125, 3245.74951171875, 3.484752416610717773, 0, 0, -0.98531627655029296, 0.170739144086837768, 120, 255, 1, 36839), -- 353760 (Area: House of Plagues - Difficulty: 0)
(@OGUID+83, 355916, 2222, 11462, 12775, '0', '0', 0, 1579.736083984375, -3242.986083984375, 3246.446533203125, 0.909949839115142822, 0, 0, 0.439439773559570312, 0.898272037506103515, 120, 255, 1, 36839), -- 355916 (Area: House of Plagues - Difficulty: 0)
(@OGUID+84, 334654, 2222, 11462, 12775, '0', '0', 0, 1645.6610107421875, -3031.461181640625, 3252.2001953125, 0.420586943626403808, 0, 0, 0.208746910095214843, 0.977969706058502197, 120, 255, 0, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+85, 355862, 2222, 11462, 12775, '0', '0', 0, 1497.482666015625, -3149.194580078125, 3248.655517578125, 0.462126195430755615, 0, 0, 0.229012489318847656, 0.973423480987548828, 120, 255, 1, 36839), -- 355862 (Area: House of Plagues - Difficulty: 0)
(@OGUID+86, 355863, 2222, 11462, 12775, '0', '0', 0, 1497.3194580078125, -3149.670166015625, 3249.774658203125, 0.603555977344512939, 0, 0, 0.29721832275390625, 0.954809546470642089, 120, 255, 1, 36839), -- 355863 (Area: House of Plagues - Difficulty: 0)
(@OGUID+87, 355870, 2222, 11462, 12775, '0', '0', 0, 1497.8941650390625, -3149.038330078125, 3249.73486328125, 0.499927461147308349, 0, 0, 0.247368812561035156, 0.968921422958374023, 120, 255, 1, 36839), -- 355870 (Area: House of Plagues - Difficulty: 0)
(@OGUID+88, 355439, 2222, 11462, 12775, '0', '0', 0, 1575.0347900390625, -3138.71875, 3249.632568359375, 3.345405817031860351, 0, 0, -0.99481201171875, 0.101730205118656158, 120, 255, 1, 36839), -- 355439 (Area: House of Plagues - Difficulty: 0)
(@OGUID+89, 355865, 2222, 11462, 12775, '0', '0', 0, 1495.90625, -3144.350830078125, 3247.762939453125, 5.786481857299804687, 0, 0, -0.24580669403076171, 0.969318866729736328, 120, 255, 1, 36839), -- 355865 (Area: House of Plagues - Difficulty: 0)
(@OGUID+90, 355867, 2222, 11462, 12775, '0', '0', 0, 1497.4271240234375, -3147.760498046875, 3249.788330078125, 0.171826899051666259, 0, 0, 0.08580780029296875, 0.996311724185943603, 120, 255, 0, 36839), -- 355867 (Area: House of Plagues - Difficulty: 0)
(@OGUID+91, 355866, 2222, 11462, 12775, '0', '0', 0, 1495.90625, -3144.348876953125, 3247.762939453125, 5.786481857299804687, 0, 0, -0.24580669403076171, 0.969318866729736328, 120, 255, 1, 36839), -- 355866 (Area: House of Plagues - Difficulty: 0)
(@OGUID+92, 334654, 2222, 11462, 12775, '0', '0', 0, 1485.063232421875, -3103.27490234375, 3257.0361328125, 0.250290393829345703, 0, 0, 0.124818801879882812, 0.992179512977600097, 120, 255, 1, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+93, 334654, 2222, 11462, 12775, '0', '0', 0, 1624.890869140625, -3197.1943359375, 3240.771484375, 1.173887133598327636, 0, 0, 0.553818702697753906, 0.832637310028076171, 120, 255, 0, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+94, 334654, 2222, 11462, 12775, '0', '0', 0, 1664.14599609375, -3151.43994140625, 3241.080078125, 3.303169012069702148, 0, 0, -0.99673843383789062, 0.080700203776359558, 120, 255, 1, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+95, 266354, 2222, 11462, 12775, '0', '0', 0, 1781.594482421875, -3040.4501953125, 3277.829345703125, 3.85159611701965332, 0, 0, -0.93764591217041015, 0.347591936588287353, 120, 255, 1, 36839), -- 266354 (Area: House of Plagues - Difficulty: 0)
(@OGUID+96, 334654, 2222, 11462, 12775, '0', '0', 0, 1644.763916015625, -3031.260498046875, 3251.9013671875, 4.87537240982055664, 0, 0, -0.64720058441162109, 0.762319743633270263, 120, 255, 1, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+97, 334654, 2222, 11462, 12775, '0', '0', 0, 1557.233154296875, -3102.03662109375, 3248.778076171875, 5.930331230163574218, 0, 0, -0.17551326751708984, 0.984477043151855468, 120, 255, 0, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+98, 334654, 2222, 11462, 12775, '0', '0', 0, 1572.7469482421875, -3162.564208984375, 3248.6728515625, 5.996447086334228515, 0, 0, -0.14287853240966796, 0.989740192890167236, 120, 255, 0, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+99, 334654, 2222, 11462, 12775, '0', '0', 0, 1598.5518798828125, -3176.759521484375, 3245.942626953125, 1.57354891300201416, 0, 0, 0.708079338073730468, 0.706132888793945312, 120, 255, 0, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+100, 334654, 2222, 11462, 12775, '0', '0', 0, 1567.11669921875, -3198.87158203125, 3248.728515625, 3.899380922317504882, 0, 0, -0.92907428741455078, 0.369893193244934082, 120, 255, 0, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+101, 334653, 2222, 11462, 12775, '0', '0', 0, 1588.0684814453125, -3112.556884765625, 3244.54248046875, 4.958377838134765625, 0, 0, -0.61501407623291015, 0.788516104221343994, 120, 255, 0, 36839), -- 334653 (Area: House of Plagues - Difficulty: 0)
(@OGUID+102, 334654, 2222, 11462, 12775, '0', '0', 0, 1655.6634521484375, -3139.23486328125, 3243.00146484375, 0.718729853630065917, 0, 0, 0.351679801940917968, 0.936120331287384033, 120, 255, 0, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+103, 334654, 2222, 11462, 12775, '0', '0', 0, 1655.5859375, -3137.1015625, 3243.42578125, 6.276834011077880859, 0, 0, -0.00317573547363281, 0.999994933605194091, 120, 255, 1, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+104, 334654, 2222, 11462, 12775, '0', '0', 0, 1657.80859375, -3134.646484375, 3243.955078125, 5.146150112152099609, 0, 0, -0.53838348388671875, 0.842699944972991943, 120, 255, 1, 36839), -- 334654 (Area: House of Plagues - Difficulty: 0)
(@OGUID+105, 345431, 2222, 11462, 12775, '0', '0', 0, 1818.5885009765625, -3196.09716796875, 3243.338134765625, 1.889477014541625976, 0, 0, 0.810343742370605468, 0.585954785346984863, 120, 255, 1, 36839), -- 345431 (Area: House of Plagues - Difficulty: 0)
(@OGUID+106, 365233, 2222, 11462, 12775, '0', '0', 0, 1818.1285400390625, -3194.734375, 3241.802001953125, 5.018609523773193359, 0, 0, -0.59099197387695312, 0.806677401065826416, 120, 255, 1, 36839), -- 365233 (Area: House of Plagues - Difficulty: 0)
(@OGUID+107, 365234, 2222, 11462, 12775, '0', '0', 0, 1819.157958984375, -3197.85595703125, 3241.802001953125, 5.018609523773193359, 0, 0, -0.59099197387695312, 0.806677401065826416, 120, 255, 1, 36839), -- 365234 (Area: House of Plagues - Difficulty: 0)
(@OGUID+108, 365233, 2222, 11462, 12775, '0', '0', 0, 1820.0103759765625, -3196.04345703125, 3241.802001953125, 0.330320894718170166, 0, 0, 0.164410591125488281, 0.986392021179199218, 120, 255, 1, 36839), -- 365233 (Area: House of Plagues - Difficulty: 0)
(@OGUID+109, 365233, 2222, 11462, 12775, '0', '0', 0, 1817.23095703125, -3196.703125, 3241.802001953125, 0.330320894718170166, 0, 0, 0.164410591125488281, 0.986392021179199218, 120, 255, 1, 36839), -- 365233 (Area: House of Plagues - Difficulty: 0)
(@OGUID+110, 345434, 2222, 11462, 12775, '0', '0', 0, 1818.970458984375, -3195.991455078125, 3248.116943359375, 0.758027911186218261, -0.01995658874511718, 0.0038909912109375, 0.370102882385253906, 0.928768277168273925, 120, 255, 0, 36839), -- 345434 (Area: House of Plagues - Difficulty: 0)
(@OGUID+111, 191083, 2222, 11462, 12775, '0', '0', 0, 1692.8582763671875, -3072.012451171875, 3257.4130859375, 0.63574981689453125, 0, 0, 0.312548637390136718, 0.949901759624481201, 120, 255, 1, 36839), -- 191083 (Area: House of Plagues - Difficulty: 0)
(@OGUID+112, 349898, 2222, 11462, 13305, '0', '0', 0, 1892.296875, -2974.505126953125, 3271.068359375, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 349898 (Area: Plague Watch - Difficulty: 0)
(@OGUID+113, 357964, 2222, 11462, 11466, '0', '0', 0, 1898.5244140625, -2475.375, 3398.333984375, 3.604105949401855468, 0, 0, -0.97337913513183593, 0.229200854897499084, 120, 255, 1, 36839), -- 357964 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+114, 357963, 2222, 11462, 11466, '0', '0', 0, 1895.6806640625, -2478.349609375, 3398.359619140625, 1.823868632316589355, 0, 0, 0.790689468383789062, 0.612217426300048828, 120, 255, 1, 36839), -- 357963 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+115, 357966, 2222, 11462, 11466, '0', '0', 0, 1895.7294921875, -2473.294921875, 3398.333740234375, 4.110253810882568359, 0, 0, -0.88498687744140625, 0.46561598777770996, 120, 255, 1, 36839), -- 357966 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+116, 357965, 2222, 11462, 11466, '0', '0', 0, 1893.4599609375, -2473.578125, 3398.333740234375, 5.218535900115966796, 0, 0, -0.507537841796875, 0.861629426479339599, 120, 255, 1, 36839), -- 357965 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+117, 190942, 2222, 11462, 11466, '0', '0', 0, 1978.205810546875, -2628.083740234375, 3343.4228515625, 0.54160088300704956, 0, 0, 0.267502784729003906, 0.963557064533233642, 120, 255, 1, 36839), -- 190942 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+118, 338855, 2222, 11462, 11466, '0', '0', 0, 2951.263916015625, -1236.1510009765625, 3312.775390625, 2.211329460144042968, -0.00328922271728515, 0.001135826110839843, 0.893757820129394531, 0.44853636622428894, 120, 255, 1, 36839), -- 338855 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+119, 353378, 2222, 11462, 11466, '0', '0', 0, 2405.819580078125, -2058.960205078125, 3311.06005859375, 3.768620252609252929, 0, 0, -0.95125579833984375, 0.308402955532073974, 120, 255, 1, 36839), -- 353378 (Area: Bleak Redoubt - Difficulty: 0)
(@OGUID+120, 349898, 2222, 11462, 12241, '0', '0', 0, 2208.319580078125, -2292.28466796875, 3299.85107421875, 1.318046808242797851, 0.159608840942382812, 0.044391632080078125, 0.611556053161621093, 0.773662447929382324, 120, 255, 1, 36839), -- 349898 (Area: Iron Trench - Difficulty: 0)
(@OGUID+121, 351478, 2222, 11462, 12241, '0', '0', 0, 2222.810791015625, -2262.6025390625, 3275.2197265625, 0.241710573434829711, -0.1777653694152832, -0.02637672424316406, 0.11773681640625, 0.976648271083831787, 120, 255, 1, 36839), -- 351478 (Area: Iron Trench - Difficulty: 0)
(@OGUID+122, 351475, 2222, 11462, 12241, '0', '0', 0, 2221.770751953125, -2262.701416015625, 3275.25927734375, 0.258542776107788085, -0.13858652114868164, 0.101517677307128906, 0.141819000244140625, 0.974871933460235595, 120, 255, 1, 36839), -- 351475 (Area: Iron Trench - Difficulty: 0)
(@OGUID+123, 351475, 2222, 11462, 12241, '0', '0', 0, 2235.10595703125, -2142.3525390625, 3278.734375, 4.476450920104980468, -0.01526927947998046, -0.01875686645507812, -0.78510856628417968, 0.618885755538940429, 120, 255, 1, 36839), -- 351475 (Area: Iron Trench - Difficulty: 0)
(@OGUID+124, 351479, 2222, 11462, 12241, '0', '0', 0, 2234.510498046875, -2144.270751953125, 3278.760498046875, 1.235301971435546875, -0.03278541564941406, -0.00480461120605468, 0.579166412353515625, 0.81453561782836914, 120, 255, 1, 36839), -- 351479 (Area: Iron Trench - Difficulty: 0)
(@OGUID+125, 352110, 2222, 11462, 12241, '0', '0', 0, 3799.587158203125, -2039.7357177734375, 3291.91357421875, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 36839), -- 352110 (Area: Iron Trench - Difficulty: 0)
(@OGUID+126, 353615, 2222, 11462, 12241, '0', '0', 0, 3351.71875, -1052.357666015625, 3338.21484375, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 353615 (Area: Iron Trench - Difficulty: 0)
(@OGUID+127, 349898, 2222, 11462, 12241, '0', '0', 0, 2336.27783203125, -2177.189208984375, 3278.6298828125, 6.2709808349609375, 0.194567203521728515, -0.04657745361328125, 0.003047943115234375, 0.979777991771697998, 120, 255, 1, 36839), -- 349898 (Area: Iron Trench - Difficulty: 0)
(@OGUID+128, 348935, 2222, 11462, 12241, '0', '0', 0, 2352.85595703125, -2213.40625, 3272.981689453125, 0.01037018559873104, -0.02153539657592773, 0.022573471069335937, 0.00566864013671875, 0.999497115612030029, 120, 255, 1, 36839), -- 348935 (Area: Iron Trench - Difficulty: 0)
(@OGUID+129, 351474, 2222, 11462, 12241, '0', '0', 0, 2368.9150390625, -2196.720458984375, 3270.97412109375, 4.129331588745117187, 0.00571441650390625, -0.0813446044921875, -0.87638473510742187, 0.474657982587814331, 120, 255, 1, 36839), -- 351474 (Area: Iron Trench - Difficulty: 0)
(@OGUID+130, 351475, 2222, 11462, 12241, '0', '0', 0, 2369.40283203125, -2195.517333984375, 3271.36572265625, 4.179369449615478515, 0, 0, -0.86837100982666015, 0.495915114879608154, 120, 255, 1, 36839), -- 351475 (Area: Iron Trench - Difficulty: 0)
(@OGUID+131, 353378, 2222, 11462, 0, '0', '0', 0, 2476, -1589.140625, 3280.989990234375, 2.540303707122802734, 0, 0, 0.955145835876464843, 0.29613584280014038, 120, 255, 1, 36839), -- 353378 (Area: 0 - Difficulty: 0)
(@OGUID+132, 348541, 2222, 11462, 11467, '0', '0', 0, 2474.265625, -1870.923583984375, 3273.482421875, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 120, 255, 1, 36839), -- 348541 (Area: The Spearhead - Difficulty: 0)
(@OGUID+133, 353762, 2222, 11462, 11467, '0', '0', 0, 2487.802001953125, -1861.1024169921875, 3272.92724609375, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 120, 255, 1, 36839), -- 353762 (Area: The Spearhead - Difficulty: 0)
(@OGUID+134, 364863, 2222, 11462, 11467, '0', '0', 0, 3794.086669921875, -1127.2186279296875, 3192.216796875, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 36839), -- 364863 (Area: The Spearhead - Difficulty: 0)
(@OGUID+135, 334123, 2222, 11462, 11467, '0', '0', 0, 2772.493896484375, -1827.3819580078125, 3235.652587890625, 1.989475846290588378, -0.01058006286621093, 0.073306083679199218, 0.834824562072753906, 0.545510947704315185, 120, 255, 1, 36839), -- 334123 (Area: The Spearhead - Difficulty: 0)
(@OGUID+136, 334123, 2222, 11462, 11467, '0', '0', 0, 2680.866455078125, -1739.3836669921875, 3236.16064453125, 0.899340927600860595, 0.01250457763671875, -0.02589130401611328, 0.434489250183105468, 0.900217950344085693, 120, 255, 1, 36839), -- 334123 (Area: The Spearhead - Difficulty: 0)
(@OGUID+137, 336689, 2222, 11462, 11467, '0', '0', 0, 2714.772705078125, -1882.23095703125, 3240.332763671875, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 336689 (Area: The Spearhead - Difficulty: 0)
(@OGUID+138, 351470, 2222, 11462, 11467, '0', '0', 0, 2689.9150390625, -1823.9913330078125, 3243.749755859375, 1.362126946449279785, 0, 0, 0.629619598388671875, 0.77690356969833374, 120, 255, 1, 36839), -- 351470 (Area: The Spearhead - Difficulty: 0)
(@OGUID+139, 334123, 2222, 11462, 11467, '0', '0', 0, 2807.099853515625, -1707.32470703125, 3234.0185546875, 1.083623051643371582, 0, 0, 0.515688896179199218, 0.856775879859924316, 120, 255, 1, 36839), -- 334123 (Area: The Spearhead - Difficulty: 0)
(@OGUID+140, 339638, 2222, 11462, 11467, '0', '0', 0, 2790.776123046875, -1643.328125, 3253.319580078125, 5.677797317504882812, 0, 0, -0.29809284210205078, 0.954536914825439453, 120, 255, 1, 36839), -- 339638 (Area: The Spearhead - Difficulty: 0)
(@OGUID+141, 349898, 2222, 11462, 11467, '0', '0', 0, 2644.611083984375, -1922.40625, 3248.47119140625, 5.725069046020507812, -0.18707942962646484, 0.052678108215332031, -0.27036762237548828, 0.942935645580291748, 120, 255, 1, 36839), -- 349898 (Area: The Spearhead - Difficulty: 0)
(@OGUID+142, 339564, 2222, 11462, 11467, '0', '0', 0, 2705.997314453125, -1632.220458984375, 3253.603759765625, 3.857934474945068359, 0, 0, -0.9365396499633789, 0.350561708211898803, 120, 255, 1, 36839), -- 339564 (Area: The Spearhead - Difficulty: 0)
(@OGUID+143, 339637, 2222, 11462, 11467, '0', '0', 0, 2873.940185546875, -1657.7117919921875, 3253.592529296875, 5.624614238739013671, 0, 0, -0.32336711883544921, 0.946273624897003173, 120, 255, 1, 36839), -- 339637 (Area: The Spearhead - Difficulty: 0)
(@OGUID+144, 351470, 2222, 11462, 11467, '0', '0', 0, 2800.447021484375, -1722.10595703125, 3232.72998046875, 2.218383550643920898, 0, 0, 0.895339012145996093, 0.445385307073593139, 120, 255, 1, 36839), -- 351470 (Area: The Spearhead - Difficulty: 0)
(@OGUID+145, 353378, 2222, 11462, 11467, '0', '0', 0, 2767.407958984375, -1406.282958984375, 3229.35009765625, 2.569593667984008789, 0, 0, 0.959380149841308593, 0.282116502523422241, 120, 255, 1, 36839), -- 353378 (Area: The Spearhead - Difficulty: 0)
(@OGUID+146, 350778, 2222, 11462, 11467, '0', '0', 0, 2911.60498046875, -1770.704833984375, 3232.28076171875, 4.508923530578613281, 0, 0, -0.77526283264160156, 0.631638765335083007, 120, 255, 1, 36839), -- 350778 (Area: The Spearhead - Difficulty: 0)
(@OGUID+147, 336689, 2222, 11462, 11467, '0', '0', 0, 2881.434814453125, -1694.515625, 3233.000244140625, 3.844799041748046875, 0, 0, -0.93882179260253906, 0.344403326511383056, 120, 255, 1, 36839), -- 336689 (Area: The Spearhead - Difficulty: 0)
(@OGUID+148, 349981, 2222, 11462, 11467, '0', '0', 0, 2713.88720703125, -1707.0989990234375, 3230.7275390625, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 349981 (Area: The Spearhead - Difficulty: 0)
(@OGUID+149, 350085, 2222, 11462, 11467, '0', '0', 0, 2771.276123046875, -1653.8125, 3250.71630859375, 5.797387599945068359, 0.042795181274414062, -0.1417093276977539, -0.22841072082519531, 0.962245106697082519, 120, 255, 1, 36839), -- 350085 (Area: The Spearhead - Difficulty: 0)
(@OGUID+150, 352582, 2222, 11462, 11467, '0', '0', 0, 2862.91845703125, -1654.5069580078125, 3253.592529296875, 1.240896463394165039, 0, 0, 0.581399917602539062, 0.813617944717407226, 120, 255, 1, 36839), -- 352582 (Area: The Spearhead - Difficulty: 0)
(@OGUID+151, 352583, 2222, 11462, 11467, '0', '0', 0, 2853.63623046875, -1627.6649169921875, 3253.559814453125, 3.11184239387512207, 0, 0, 0.999889373779296875, 0.01487455703318119, 120, 255, 1, 36839), -- 352583 (Area: The Spearhead - Difficulty: 0)
(@OGUID+152, 350778, 2222, 11462, 11467, '0', '0', 0, 2921.8369140625, -1728.3802490234375, 3234.495361328125, 4.818332672119140625, 0.000658035278320312, -0.02536296844482421, -0.66822147369384765, 0.743529677391052246, 120, 255, 1, 36839), -- 350778 (Area: The Spearhead - Difficulty: 0)
(@OGUID+153, 348935, 2222, 11462, 11467, '0', '0', 0, 2879.5869140625, -1650.953125, 3252.916259765625, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 348935 (Area: The Spearhead - Difficulty: 0)
(@OGUID+154, 339646, 2222, 11462, 11467, '0', '0', 0, 2867.080810546875, -1620.920166015625, 3253.610595703125, 1.185082197189331054, 0, 0, 0.558470726013183593, 0.829524219036102294, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+155, 352576, 2222, 11462, 11467, '0', '0', 0, 2708.77685546875, -1631.498291015625, 3256.73779296875, 5.396278858184814453, 0.508761405944824218, -0.13816738128662109, -0.41544342041015625, 0.741268098354339599, 120, 255, 1, 36839), -- 352576 (Area: The Spearhead - Difficulty: 0)
(@OGUID+156, 339652, 2222, 11462, 11467, '0', '0', 0, 2698.374267578125, -1635.6285400390625, 3253.471923828125, 3.051919221878051757, -0.16272354125976562, 0.211058616638183593, 0.960550308227539062, 0.079488299787044525, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+157, 339652, 2222, 11462, 11467, '0', '0', 0, 2679.86279296875, -1640.236083984375, 3251.886474609375, 2.604330778121948242, 0, 0, 0.964135169982910156, 0.265411734580993652, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+158, 339652, 2222, 11462, 11467, '0', '0', 0, 2678.65283203125, -1641.420166015625, 3252.081298828125, 3.051919221878051757, -0.16272354125976562, 0.211058616638183593, 0.960550308227539062, 0.079488299787044525, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+159, 352576, 2222, 11462, 11467, '0', '0', 0, 2709.2900390625, -1627.734375, 3256.745849609375, 0.394424527883529663, 0.466354846954345703, 0.149984359741210937, 0.140192985534667968, 0.860443949699401855, 120, 255, 1, 36839), -- 352576 (Area: The Spearhead - Difficulty: 0)
(@OGUID+160, 339646, 2222, 11462, 11467, '0', '0', 0, 2712.26220703125, -1636.5660400390625, 3254.397705078125, 1.701413273811340332, 0.062494754791259765, 0.00312042236328125, 0.751564979553222656, 0.656684696674346923, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+161, 339652, 2222, 11462, 11467, '0', '0', 0, 2674.41845703125, -1640.279541015625, 3252.507080078125, 3.051919221878051757, -0.16272354125976562, 0.211058616638183593, 0.960550308227539062, 0.079488299787044525, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+162, 339646, 2222, 11462, 11467, '0', '0', 0, 2714.49658203125, -1628.16845703125, 3253.74462890625, 1.185082197189331054, 0, 0, 0.558470726013183593, 0.829524219036102294, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+163, 352576, 2222, 11462, 11467, '0', '0', 0, 2705.838623046875, -1631.3160400390625, 3256.599853515625, 5.17606210708618164, 0.09835052490234375, -0.08004951477050781, -0.51970767974853515, 0.844880580902099609, 120, 255, 1, 36839), -- 352576 (Area: The Spearhead - Difficulty: 0)
(@OGUID+164, 339652, 2222, 11462, 11467, '0', '0', 0, 2698.15625, -1630.6180419921875, 3253.471923828125, 4.388563156127929687, 0.190999507904052734, 0.235667228698730468, -0.75902175903320312, 0.576078176498413085, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+165, 352576, 2222, 11462, 11467, '0', '0', 0, 2708.94091796875, -1630.0052490234375, 3256.837646484375, 1.793958306312561035, 0.250682353973388671, 0.463773727416992187, 0.626827239990234375, 0.573724627494812011, 120, 255, 1, 36839), -- 352576 (Area: The Spearhead - Difficulty: 0)
(@OGUID+166, 339646, 2222, 11462, 11467, '0', '0', 0, 2714.486083984375, -1630.154541015625, 3253.69775390625, 2.791273117065429687, 0.053218841552734375, 0.030956268310546875, 0.983155250549316406, 0.172090739011764526, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+167, 352576, 2222, 11462, 11467, '0', '0', 0, 2705.9775390625, -1629.703125, 3256.714111328125, 0.489468723535537719, 0.480721473693847656, 0.216414451599121093, 0.149919509887695312, 0.836418449878692626, 120, 255, 1, 36839), -- 352576 (Area: The Spearhead - Difficulty: 0)
(@OGUID+168, 339652, 2222, 11462, 11467, '0', '0', 0, 2699.940185546875, -1637.0694580078125, 3253.471923828125, 4.388563156127929687, 0.190999507904052734, 0.235667228698730468, -0.75902175903320312, 0.576078176498413085, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+169, 339646, 2222, 11462, 11467, '0', '0', 0, 2699.611083984375, -1636.1875, 3253.3740234375, 1.185082197189331054, 0, 0, 0.558470726013183593, 0.829524219036102294, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+170, 339652, 2222, 11462, 11467, '0', '0', 0, 2679.779541015625, -1640.9444580078125, 3252.0390625, 3.091713905334472656, 0.090496540069580078, -0.41064834594726562, 0.904743194580078125, 0.067956224083900451, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+171, 336689, 2222, 11462, 11467, '0', '0', 0, 2670.981689453125, -1629.2535400390625, 3250.920166015625, 3.38017582893371582, 0, 0, -0.99289321899414062, 0.119008727371692657, 120, 255, 1, 36839), -- 336689 (Area: The Spearhead - Difficulty: 0)
(@OGUID+172, 357464, 2222, 11462, 11467, '0', '0', 0, 2698.990478515625, -1595.4375, 3253.58837890625, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 36839), -- 357464 (Area: The Spearhead - Difficulty: 0)
(@OGUID+173, 339646, 2222, 11462, 11467, '0', '0', 0, 2708.60595703125, -1594.2603759765625, 3253.723876953125, 1.185082197189331054, 0, 0, 0.558470726013183593, 0.829524219036102294, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+174, 350778, 2222, 11462, 11467, '0', '0', 0, 2614.16064453125, -1720.01220703125, 3232.935791015625, 1.214587688446044921, 0.050132274627685546, 0.034836769104003906, 0.569582939147949218, 0.819663584232330322, 120, 255, 1, 36839), -- 350778 (Area: The Spearhead - Difficulty: 0)
(@OGUID+175, 351470, 2222, 11462, 11467, '0', '0', 0, 2603.84033203125, -1684.2603759765625, 3238.520751953125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 351470 (Area: The Spearhead - Difficulty: 0)
(@OGUID+176, 348935, 2222, 11462, 11467, '0', '0', 0, 2634.197021484375, -1588.564208984375, 3250.796142578125, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 348935 (Area: The Spearhead - Difficulty: 0)
(@OGUID+177, 352569, 2222, 11462, 11467, '0', '0', 0, 2705.997314453125, -1632.220458984375, 3253.603759765625, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, 36839), -- 352569 (Area: The Spearhead - Difficulty: 0)
(@OGUID+178, 336689, 2222, 11462, 11467, '0', '0', 0, 2756.59375, -1657.701416015625, 3244.0791015625, 5.076227188110351562, 0, 0, -0.56751060485839843, 0.823366105556488037, 120, 255, 1, 36839), -- 336689 (Area: The Spearhead - Difficulty: 0)
(@OGUID+179, 352571, 2222, 11462, 11467, '0', '0', 0, 2790.776123046875, -1643.328125, 3253.319580078125, 5.603702545166015625, 0, 0, -0.33324337005615234, 0.942840814590454101, 120, 255, 1, 36839), -- 352571 (Area: The Spearhead - Difficulty: 0)
(@OGUID+180, 349899, 2222, 11462, 12777, '0', '0', 0, 2791.10498046875, -1467.0069580078125, 3256.802001953125, 0.535896360874176025, 0.061156749725341796, -0.26473712921142578, 0.251768112182617187, 0.928863227367401123, 120, 255, 1, 36839), -- 349899 (Area: Ossein Foundry - Difficulty: 0)
(@OGUID+181, 353752, 2289, 13228, 13228, '0', '', 0, 1186.1910400390625, -3680.65625, 3144.43994140625, 3.237619400024414062, 0.012489795684814453, 0.071032524108886718, -0.99619197845458984, 0.04898899421095848, 7200, 255, 1, 36839), -- 353752 (Area: Plaguefall - Difficulty: 0)
(@OGUID+182, 353633, 2289, 13228, 13228, '0', '', 0, 1056.7315673828125, -3688.344482421875, 3078.095458984375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 36839), -- 353633 (Area: Plaguefall - Difficulty: 0)
(@OGUID+183, 252247, 2289, 13228, 13228, '0', '', 0, 2030.9757080078125, -3169.517333984375, 3274.312744140625, 3.835698843002319335, 0, 0, -0.94037914276123046, 0.340128034353256225, 7200, 255, 1, 36839), -- 252247 (Area: Plaguefall - Difficulty: 0)
(@OGUID+184, 355424, 2289, 13228, 13228, '0', '', 0, 1029.6214599609375, -3669.460693359375, 3066.897705078125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 36839), -- 355424 (Area: Plaguefall - Difficulty: 0)
(@OGUID+185, 351470, 2222, 11462, 11467, '0', '0', 0, 2881.434814453125, -1694.515625, 3233.000244140625, 3.844799041748046875, 0, 0, -0.93882179260253906, 0.344403326511383056, 120, 255, 1, 36839), -- 351470 (Area: The Spearhead - Difficulty: 0)
(@OGUID+186, 352585, 2222, 11462, 11467, '0', '0', 0, 2864.059814453125, -1654.51220703125, 3253.592529296875, 0.997398734092712402, 0.572217941284179687, -0.22995567321777343, 0.576665878295898437, 0.535857677459716796, 120, 255, 1, 36839), -- 352585 (Area: The Spearhead - Difficulty: 0)
(@OGUID+187, 352585, 2222, 11462, 11467, '0', '0', 0, 2861.6259765625, -1653.2413330078125, 3253.592529296875, 2.32930755615234375, 0, 0, 0.918651580810546875, 0.395068705081939697, 120, 255, 1, 36839), -- 352585 (Area: The Spearhead - Difficulty: 0)
(@OGUID+188, 352574, 2222, 11462, 11467, '0', '0', 0, 2873.940185546875, -1657.7117919921875, 3253.592529296875, 5.624614238739013671, 0, 0, -0.32336711883544921, 0.946273624897003173, 120, 255, 1, 36839), -- 352574 (Area: The Spearhead - Difficulty: 0)
(@OGUID+189, 352584, 2222, 11462, 11467, '0', '0', 0, 2853.587646484375, -1627.685791015625, 3253.58349609375, 2.678623676300048828, 0.116558551788330078, -0.01410388946533203, 0.966944694519042968, 0.226347327232360839, 120, 255, 1, 36839), -- 352584 (Area: The Spearhead - Difficulty: 0)
(@OGUID+190, 353378, 2222, 11462, 11467, '0', '0', 0, 3165.47998046875, -2003.8507080078125, 3260.159912109375, 0.79290705919265747, 0, 0, 0.386149406433105468, 0.922436237335205078, 120, 255, 1, 36839), -- 353378 (Area: The Spearhead - Difficulty: 0)
(@OGUID+191, 336689, 2222, 11462, 11467, '0', '0', 0, 2786.47216796875, -1843.4896240234375, 3232.490478515625, 0.938387989997863769, 0, 0, 0.452167510986328125, 0.891933023929595947, 120, 255, 1, 36839), -- 336689 (Area: The Spearhead - Difficulty: 0)
(@OGUID+192, 339652, 2222, 11462, 11467, '0', '0', 0, 2982.1025390625, -1829.7291259765625, 3225.428466796875, 0.399957478046417236, 0.337862491607666015, -0.03306293487548828, 0.220404624938964843, 0.914427459239959716, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+193, 339652, 2222, 11462, 11467, '0', '0', 0, 2975.62060546875, -1797.02783203125, 3227.897705078125, 1.137902617454528808, -0.40871191024780273, 0.022263526916503906, 0.562951087951660156, 0.718014657497406005, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+194, 339652, 2222, 11462, 11467, '0', '0', 0, 2975.114501953125, -1802.13720703125, 3228.540283203125, 5.253633499145507812, 0.017227649688720703, 0.174852371215820312, -0.47454738616943359, 0.862516462802886962, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+195, 339646, 2222, 11462, 11467, '0', '0', 0, 2975.859375, -1803.3524169921875, 3228.635986328125, 6.094915390014648437, 0, 0, -0.09399604797363281, 0.995572566986083984, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+196, 339652, 2222, 11462, 11467, '0', '0', 0, 2983.744873046875, -1829.28125, 3225.235107421875, 0, 0, 0, 0, 1, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+197, 339652, 2222, 11462, 11467, '0', '0', 0, 2984.155517578125, -1828.076416015625, 3225.428466796875, 1.10010838508605957, 0.328710079193115234, 0.084817886352539062, 0.520656585693359375, 0.783372461795806884, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+198, 339652, 2222, 11462, 11467, '0', '0', 0, 2983.278564453125, -1828.017333984375, 3225.338623046875, 3.155403614044189453, 0, 0, -0.99997615814208984, 0.006905339658260345, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+199, 339646, 2222, 11462, 11467, '0', '0', 0, 2983.833251953125, -1828.5242919921875, 3226.07568359375, 1.75678718090057373, 0, 0, 0.76971435546875, 0.638388454914093017, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+200, 339646, 2222, 11462, 11467, '0', '0', 0, 2973.349853515625, -1792.4254150390625, 3226.427001953125, 1.185082197189331054, 0, 0, 0.558470726013183593, 0.829524219036102294, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+201, 339646, 2222, 11462, 11467, '0', '0', 0, 2976.3759765625, -1797.5694580078125, 3227.909423828125, 1.185082197189331054, 0, 0, 0.558470726013183593, 0.829524219036102294, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+202, 339652, 2222, 11462, 11467, '0', '0', 0, 2975.225830078125, -1797.8228759765625, 3227.825927734375, 4.873134613037109375, 0.049982070922851562, 0.168439865112304687, -0.6290903091430664, 0.757215440273284912, 120, 255, 1, 36839), -- 339652 (Area: The Spearhead - Difficulty: 0)
(@OGUID+203, 339646, 2222, 11462, 11467, '0', '0', 0, 2979.963623046875, -1800.0555419921875, 3227.638671875, 6.094915390014648437, 0, 0, -0.09399604797363281, 0.995572566986083984, 120, 255, 1, 36839), -- 339646 (Area: The Spearhead - Difficulty: 0)
(@OGUID+204, 339652, 2222, 11462, 11467, '0', '0', 0, 2979.243896484375, -1800.1129150390625, 3227.798828125, 1.518403410911560058, -0.405548095703125, -0.05542659759521484, 0.688573837280273437, 0.598602294921875, 120, 255, 1, 36839); -- 339652 (Area: The Spearhead - Difficulty: 0)
SET @OGUID := 25347557;
REPLACE INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+0, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353391
(@OGUID+2, 0, 0, 1, -0.00000004371138828), -- 355424
(@OGUID+4, 0, 0, 1, -0.00000004371138828), -- 353633
(@OGUID+5, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353392
(@OGUID+6, 0, 0, 0.984807789325714111, 0.17364811897277832), -- 364864
(@OGUID+7, 0.00000000114423071, -0.02617694810032844, 0.999657332897186279, -0.00000004369640649), -- 364865
(@OGUID+8, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353389
(@OGUID+9, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353390
(@OGUID+12, 0, 0, 1, -0.00000004371138828), -- 355424
(@OGUID+15, 0, 0, 0.984807789325714111, 0.17364811897277832), -- 364864
(@OGUID+16, 0.00000000114423071, -0.02617694810032844, 0.999657332897186279, -0.00000004369640649), -- 364865
(@OGUID+20, 0, 0, 1, -0.00000004371138828), -- 353633
(@OGUID+22, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353392
(@OGUID+23, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353389
(@OGUID+24, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353390
(@OGUID+25, 0, 0, -0.24192140996456146, 0.970295846462249755), -- 353391
(@OGUID+28, 0, 0, 1, -0.00000004371138828), -- 357089
(@OGUID+30, 0, 0, 1, -0.00000004371138828), -- 355451
(@OGUID+31, 0, 0, 1, -0.00000004371138828), -- 358871
(@OGUID+33, 0, 0, 1, -0.00000004371138828), -- 358872
(@OGUID+34, 0, 0, 1, -0.00000004371138828), -- 358873
(@OGUID+57, 0, 0, 0.220697447657585144, 0.975342333316802978), -- 353399
(@OGUID+113, 0, 0, 1, -0.00000004371138828), -- 357964
(@OGUID+114, 0, 0, 1, -0.00000004371138828), -- 357963
(@OGUID+115, 0, 0, 1, -0.00000004371138828), -- 357966
(@OGUID+116, 0, 0, 1, -0.00000004371138828), -- 357965
(@OGUID+125, 0, 0, 0.190808489918708801, 0.981627285480499267), -- 352110
(@OGUID+134, 0, 0, 0.382683455944061279, 0.923879563808441162), -- 364863
(@OGUID+182, 0, 0, 1, -0.00000004371138828), -- 353633
(@OGUID+184, 0, 0, 1, -0.00000004371138828); -- 355424

DELETE FROM `spell_target_position` WHERE (`ID`=53822 AND `EffectIndex`=1) OR (`ID`=187753 AND `EffectIndex`=0);
REPLACE INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(53822, 1, 0, 2359.639892578125, -5662.41015625, 382.279998779296875, 36839), -- Spell: Death Gate Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(187753, 0, 1220, -1444.030029296875, 1158.030029296875, 275.260009765625, 36839); -- Spell: Death Gate Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (169161 /*169161*/, 169170 /*169170 - 100% Threat Reduction*/, 169147 /*169147*/, 169226 /*169226*/, 169223 /*169223*/, 161105 /*161105*/, 160955 /*160955*/, 73400 /*73400 - Healing Rain Visual*/, 171474 /*171474 - Appetizer*/, 168396 /*168396 - Anim Replacement - New Drunk, Slimy Morsel*/, 168393 /*168393 - Anim Replacement - New Drunk, Slimy Morsel*/, 168386 /*168386*/, 171574 /*171574 - Mod Scale 105-110%, Blood Cosmetic, Spawn Feign Death*/, 168391 /*168391*/, 171572 /*171572 - Mod Scale 105-110%, Blood Cosmetic, Spawn Feign Death*/, 171573 /*171573 - Mod Scale 105-110%, Blood Cosmetic, Spawn Feign Death*/, 172063 /*172063 - Anim Replacement - New Drunk*/, 164255 /*164255 - Living Slime Flesh, Slime Energy Bar, Festive Globgrog, Slime Infused Bones*/, 169201 /*169201 - Anim Replacement - New Drunk, Vomit*/, 163882 /*163882 - Mod Scale 105-110%, Invisibility and Stealth Detection, Oozing Slime, Plagued Carrion*/, 168965 /*168965 - Mod Scale 105-110%*/, 169843 /*169843 - Test Swim Animation*/, 172336 /*172336 - Mod Scale 105-110%, Spawn Feign Death*/, 168572 /*168572 - Mod Scale 105-110%, Dual Wield*/, 169450 /*169450*/, 168310 /*168310 - Mod Scale 105-110%*/, 168969 /*168969 - Reactive Slimeflesh, Slime Coated, Slime, Gushing Slime*/, 168298 /*168298 - Mod Scale 105-110%*/, 168314 /*168314 - Mod Scale 105-110%*/, 166480 /*166480*/, 172335 /*172335 - Mod Scale 105-110%, Spawn Feign Death*/, 168580 /*168580 - Mod Scale 105-110%*/, 169218 /*169218 - Anim Replacement - New Drunk*/, 168365 /*168365 - Mod Scale 105-110%, Fertilizer*/, 168364 /*168364 - Mod Scale 70-130%*/, 168578 /*168578 - Mod Scale 105-110%*/, 168153 /*168153*/, 174877 /*174877 - Mod Scale 105-110%, Touch of Plague*/, 168361 /*168361 - Mod Scale 105-110%*/, 168574 /*168574 - Mod Scale 105-110%*/, 163931 /*163931*/, 169696 /*169696 - Mod Scale 105-110%*/, 168315 /*168315 - Mod Scale 105-110%*/, 163915 /*163915 - Mod Scale 105-110%, Lively Eggs*/, 168968 /*168968 - Mod Scale 105-110%, Touch of Plague, Anim Replacement - New Drunk*/, 168155 /*168155 - Mod Scale 105-110%, Blood Cosmetic, Permanent Feign Death*/, 174024 /*174024 - Mod Scale 70-130%*/, 169999 /*169999 - Ghost*/, 161028 /*161028*/, 160979 /*160979 - Turn In Circle Visual*/, 160954 /*160954*/, 169395 /*169395 - Touch of Plague*/, 161027 /*161027*/, 160978 /*160978 - Turn In Circle Visual*/, 160948 /*160948*/, 161026 /*161026*/, 160976 /*160976 - Turn In Circle Visual*/, 165644 /*165644*/, 160996 /*160996*/, 160884 /*160884*/, 160883 /*160883 - Abomination - Visual - Extra - Maps*/, 167271 /*167271*/, 169088 /*169088*/, 161016 /*161016*/, 169068 /*169068*/, 169103 /*169103*/, 168424 /*168424*/, 165366 /*165366*/, 160474 /*160474 - 100% Threat Reduction*/, 169063 /*169063*/, 169096 /*169096*/, 169117 /*169117*/, 162498 /*162498*/, 160479 /*160479 - 100% Threat Reduction*/, 157669 /*157669 - 100% Threat Reduction*/, 156591 /*156591 - 100% Threat Reduction*/, 167458 /*167458 - 100% Threat Reduction*/, 167483 /*167483*/, 168946 /*168946*/, 169359 /*169359*/, 168952 /*168952*/, 157519 /*157519*/, 168951 /*168951*/, 168941 /*168941*/, 159894 /*Baron Vyraz*/, 168972 /*168972*/, 144929 /*144929*/, 164831 /*164831*/, 162816 /*162816*/, 164825 /*164825 - Keen Eyes*/, 157708 /*157708*/, 164860 /*164860*/, 164824 /*164824*/, 170901 /*170901*/, 171358 /*171358*/, 173944 /*173944*/, 171419 /*171419 - Keen Eyes*/, 164829 /*164829*/, 164830 /*164830 - Ride Vehicle Hardcoded*/, 169184 /*169184*/, 169055 /*169055 - Permanent Feign Death (Flies)*/, 168677 /*168677*/, 174654 /*174654*/, 158040 /*158040*/, 167395 /*167395*/, 167353 /*167353*/, 167435 /*167435 - Bone Tornado*/, 161397 /*161397*/, 164221 /*164221 - Cosmetic - Slime Cauldron*/, 161398 /*161398*/, 161994 /*161994*/, 164915 /*164915*/, 170807 /*170807 - Cosmetic - Slime Party Hat and Cake*/, 170806 /*170806*/, 170693 /*Invisible Stalker - Necromancy Ring*/, 163958 /*163958 - Stradama's Aura*/, 170757 /*170757 - Stradama's Aura*/, 170751 /*Invisible Stalker - Plague Cloud*/, 170443 /*Invisible Stalker - Anima Catalyst*/, 160419 /*160419*/, 164482 /*Invisible Stalker*/, 175784 /*Gelatinous*/, 157294 /*157294 - Blood Clone Cosmetic*/, 166438 /*166438 - Anim Replacement - New Drunk*/, 164759 /*164759 - Plagued*/, 164758 /*164758 - Mod Scale 90-110%*/, 165015 /*165015 - Anim Replacement - New Drunk*/, 158406 /*158406 - Vile Emission*/, 171599 /*171599*/, 171415 /*171415 - On Spawn Slime Perimeter (DNT)*/, 165014 /*165014 - Mod Scale 105-110%*/, 157317 /*157317 - Mixing Pool*/, 165145 /*165145 - White Arrow*/, 160253 /*160253*/, 160418 /*160418 - Vertex Color Lime Green*/, 160417 /*160417*/, 167358 /*167358*/, 165027 /*165027 - Mod Scale 105-110%*/, 171142 /*171142 - Anim Replacement - New Drunk*/, 157945 /*157945*/, 171217 /*171217 - Anim Replacement - New Drunk*/, 171129 /*171129 - Cosmetic - Slime Cauldron*/, 165052 /*165052 - Cosmetic - Offhand Book*/, 161380 /*161380 - Stirring*/, 157313 /*157313*/, 161841 /*161841*/, 171133 /*171133*/, 171130 /*171130 - Anim Replacement - New Drunk*/, 166579 /*166579 - Cosmetic - Offhand Book*/, 172141 /*172141*/, 171135 /*171135*/, 157515 /*157515*/, 165049 /*165049*/, 165017 /*165017*/, 171112 /*171112 - Carry Crate*/, 157226 /*157226 - Mixing Pool, Miscible Ooze, Viscous Oil*/, 165032 /*165032*/, 169129 /*169129*/, 174813 /*174813 - Permanent Feign Death (Stun, Untrackable, Immune)*/, 161613 /*161613 - Plagued, Vertex Color Lime Green*/, 171375 /*171375*/, 32639 /*32639 - Traveler's Tundra Mammoth*/, 32638 /*32638 - Traveler's Tundra Mammoth*/, 167923 /*167923 - Anim Replacement - New Drunk*/, 160029 /*160029*/, 162767 /*162767*/, 166908 /*166908 - Summon Creep Area Trigger*/, 158642 /*158642*/, 168192 /*168192*/, 176024 /*Crawbat - Battle Pet Periodic*/, 168196 /*168196 - Permanent Feign Death (Flies)*/, 165034 /*165034*/, 162257 /*Invisible Stalker*/, 162256 /*Invisible Stalker*/, 174650 /*174650*/, 159930 /*159930*/, 168216 /*168216*/, 174653 /*174653*/, 169751 /*169751*/, 173200 /*Bleak Skitterer - Battle Pet Periodic*/, 167359 /*167359*/, 162259 /*162259*/, 159856 /*159856 - Mod Scale 90-110%, Churning Dirt*/, 160060 /*160060 - Plagued*/, 176023 /*Crawbat*/, 167935 /*167935 - Mod Scale 105-110%, Touch of Plague*/, 170191 /*170191 - Stringy Growth*/, 160048 /*160048 - Anim Replacement - New Drunk*/, 167948 /*167948 - Anim Replacement - New Drunk*/, 167356 /*167356*/, 167949 /*167949 - Touch of Plague*/, 170456 /*170456*/, 161396 /*161396*/, 161390 /*161390*/, 162258 /*162258*/, 169634 /*169634 - Permanent Feign Death (Flies)*/, 161668 /*161668*/, 161395 /*161395 - Deathbolt Rift*/, 168045 /*168045*/, 167641 /*167641*/, 161679 /*161679*/, 167642 /*167642*/, 161676 /*161676*/, 167355 /*Pulsating Maggot*/, 167273 /*167273*/, 161881 /*161881*/, 161388 /*161388*/, 156558 /*156558*/, 157803 /*157803 - Archon Fragment*/, 157514 /*157514*/, 157843 /*157843 - Visectus, Set Health % (Uses Override Points) (No Health Regen)*/, 62822 /*62822 - Grand Expedition Yak*/, 62821 /*62821 - Grand Expedition Yak, Grummle Booth A*/, 175021 /*Pulsating Maggot*/, 158339 /*158339 - Carry Candle*/, 167209 /*167209*/, 170971 /*170971*/, 167741 /*167741*/, 142666 /*142666 - Grand Expedition Yak*/, 142668 /*142668 - Grand Expedition Yak*/, 160415 /*160415*/, 168381 /*Baroness Draka*/, 167747 /*167747 - 100% Threat Reduction*/, 167737 /*167737*/, 160424 /*160424*/, 167743 /*167743*/, 161376 /*161376*/, 164667 /*Prime Shieldguard*/, 161399 /*161399 - Useful Parts*/, 164833 /*164833*/, 166423 /*166423*/, 167354 /*167354*/, 157671 /*157671*/);
REPLACE INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(169161, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169161
(169170, 0, 0, 0, 0, 0, 0, 0, 0, '99203'), -- 169170 - 100% Threat Reduction
(169147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169147
(169226, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169226
(169223, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169223
(161105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161105
(160955, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160955
(73400, 0, 0, 50331648, 1, 0, 0, 0, 0, '147490'), -- 73400 - Healing Rain Visual
(171474, 0, 0, 0, 1, 0, 0, 0, 0, '334640'), -- 171474 - Appetizer
(168396, 0, 0, 0, 1, 0, 0, 0, 0, '244807 327595'), -- 168396 - Anim Replacement - New Drunk, Slimy Morsel
(168393, 0, 0, 0, 1, 0, 0, 0, 0, '244807 327591'), -- 168393 - Anim Replacement - New Drunk, Slimy Morsel
(168386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168386
(171574, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171574 - Mod Scale 105-110%, Blood Cosmetic, Spawn Feign Death
(168391, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168391
(171572, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171572 - Mod Scale 105-110%, Blood Cosmetic, Spawn Feign Death
(171573, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 35356'), -- 171573 - Mod Scale 105-110%, Blood Cosmetic, Spawn Feign Death
(172063, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 172063 - Anim Replacement - New Drunk
(164255, 0, 0, 0, 1, 0, 0, 0, 0, '324366 324304 346098 324284'), -- 164255 - Living Slime Flesh, Slime Energy Bar, Festive Globgrog, Slime Infused Bones
(169201, 0, 0, 0, 1, 0, 0, 0, 0, '244807 329078'), -- 169201 - Anim Replacement - New Drunk, Vomit
(163882, 0, 0, 0, 1, 0, 0, 0, 0, '123169 18950 343918 320040'), -- 163882 - Mod Scale 105-110%, Invisibility and Stealth Detection, Oozing Slime, Plagued Carrion
(168965, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168965 - Mod Scale 105-110%
(169843, 0, 0, 50331648, 1, 0, 0, 0, 0, '330738'), -- 169843 - Test Swim Animation
(172336, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 337684'), -- 172336 - Mod Scale 105-110%, Spawn Feign Death
(168572, 0, 0, 0, 1, 0, 0, 0, 0, '123169 323486'), -- 168572 - Mod Scale 105-110%, Dual Wield
(169450, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169450
(168310, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168310 - Mod Scale 105-110%
(168969, 0, 0, 0, 1, 0, 0, 0, 0, '346989 328662 333740 328661'), -- 168969 - Reactive Slimeflesh, Slime Coated, Slime, Gushing Slime
(168298, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168298 - Mod Scale 105-110%
(168314, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168314 - Mod Scale 105-110%
(166480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 166480
(172335, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 337684'), -- 172335 - Mod Scale 105-110%, Spawn Feign Death
(168580, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168580 - Mod Scale 105-110%
(169218, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 169218 - Anim Replacement - New Drunk
(168365, 0, 0, 0, 1, 0, 0, 0, 0, '123169 328965'), -- 168365 - Mod Scale 105-110%, Fertilizer
(168364, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 168364 - Mod Scale 70-130%
(168578, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168578 - Mod Scale 105-110%
(168153, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168153
(174877, 0, 0, 3, 1, 0, 0, 0, 0, '123169 331874'), -- 174877 - Mod Scale 105-110%, Touch of Plague
(168361, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168361 - Mod Scale 105-110%
(168574, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 168574 - Mod Scale 105-110%
(163931, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 163931
(169696, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 169696 - Mod Scale 105-110%
(168315, 0, 0, 50331648, 1, 0, 0, 0, 0, '123169'), -- 168315 - Mod Scale 105-110%
(163915, 0, 0, 0, 1, 0, 0, 0, 0, '123169 311242'), -- 163915 - Mod Scale 105-110%, Lively Eggs
(168968, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874 244807'), -- 168968 - Mod Scale 105-110%, Touch of Plague, Anim Replacement - New Drunk
(168155, 0, 0, 0, 1, 0, 0, 0, 0, '123169 327480 70628'), -- 168155 - Mod Scale 105-110%, Blood Cosmetic, Permanent Feign Death
(174024, 0, 0, 0, 1, 0, 0, 0, 0, '151051'), -- 174024 - Mod Scale 70-130%
(169999, 0, 0, 50397184, 1, 0, 0, 0, 0, '315067'), -- 169999 - Ghost
(161028, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161028
(160979, 0, 0, 50331648, 1, 0, 0, 0, 0, '292177'), -- 160979 - Turn In Circle Visual
(160954, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160954
(169395, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 169395 - Touch of Plague
(161027, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161027
(160978, 0, 0, 50331648, 1, 0, 0, 0, 0, '292177'), -- 160978 - Turn In Circle Visual
(160948, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160948
(161026, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161026
(160976, 0, 0, 50331648, 1, 0, 0, 0, 0, '292177'), -- 160976 - Turn In Circle Visual
(165644, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165644
(160996, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160996
(160884, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160884
(160883, 0, 0, 0, 1, 0, 0, 0, 0, '313127'), -- 160883 - Abomination - Visual - Extra - Maps
(167271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167271
(169088, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169088
(161016, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161016
(169068, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169068
(169103, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 169103
(168424, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168424
(165366, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165366
(160474, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160474 - 100% Threat Reduction
(169063, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 169063
(169096, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169096
(169117, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 169117
(162498, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162498
(160479, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 160479 - 100% Threat Reduction
(157669, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 157669 - 100% Threat Reduction
(156591, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 156591 - 100% Threat Reduction
(167458, 0, 0, 0, 1, 0, 0, 0, 0, '99203'), -- 167458 - 100% Threat Reduction
(167483, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167483
(168946, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168946
(169359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169359
(168952, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168952
(157519, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 157519
(168951, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- 168951
(168941, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 168941
(159894, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Baron Vyraz
(168972, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168972
(144929, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 144929
(164831, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 164831
(162816, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162816
(164825, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 164825 - Keen Eyes
(157708, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- 157708
(164860, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164860
(164824, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164824
(170901, 0, 96469, 0, 1, 0, 0, 0, 0, ''), -- 170901
(171358, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171358
(173944, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173944
(171419, 0, 0, 0, 1, 0, 0, 0, 0, '323554'), -- 171419 - Keen Eyes
(164829, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164829
(164830, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 164830 - Ride Vehicle Hardcoded
(169184, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 169184
(169055, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169055 - Permanent Feign Death (Flies)
(168677, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168677
(174654, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 174654
(158040, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158040
(167395, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167395
(167353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167353
(167435, 0, 0, 0, 1, 0, 0, 0, 0, '325854'), -- 167435 - Bone Tornado
(161397, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161397
(164221, 0, 0, 0, 1, 0, 0, 0, 0, '319502'), -- 164221 - Cosmetic - Slime Cauldron
(161398, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161398
(161994, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161994
(164915, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 164915
(170807, 0, 0, 0, 1, 0, 0, 0, 0, '333140'), -- 170807 - Cosmetic - Slime Party Hat and Cake
(170806, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170806
(170693, 0, 0, 0, 1, 0, 0, 0, 0, '318119'), -- Invisible Stalker - Necromancy Ring
(163958, 0, 0, 33554432, 1, 0, 0, 0, 0, '333016'), -- 163958 - Stradama's Aura
(170757, 0, 0, 0, 1, 0, 0, 0, 0, '333016'), -- 170757 - Stradama's Aura
(170751, 0, 0, 0, 1, 0, 0, 0, 0, '333012'), -- Invisible Stalker - Plague Cloud
(170443, 0, 0, 0, 1, 0, 0, 0, 0, '332174'), -- Invisible Stalker - Anima Catalyst
(160419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160419
(164482, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Invisible Stalker
(175784, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gelatinous
(157294, 0, 0, 0, 1, 0, 0, 0, 0, '340292'), -- 157294 - Blood Clone Cosmetic
(166438, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 166438 - Anim Replacement - New Drunk
(164759, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 164759 - Plagued
(164758, 0, 0, 0, 1, 0, 0, 0, 0, '214567'), -- 164758 - Mod Scale 90-110%
(165015, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 165015 - Anim Replacement - New Drunk
(158406, 0, 0, 0, 1, 0, 0, 0, 0, '308850'), -- 158406 - Vile Emission
(171599, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171599
(171415, 0, 0, 0, 1, 0, 0, 0, 0, '334479'), -- 171415 - On Spawn Slime Perimeter (DNT)
(165014, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165014 - Mod Scale 105-110%
(157317, 0, 0, 50331648, 1, 0, 0, 0, 0, '306781'), -- 157317 - Mixing Pool
(165145, 0, 0, 0, 1, 0, 0, 0, 0, '321653'), -- 165145 - White Arrow
(160253, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160253
(160418, 0, 0, 0, 1, 0, 0, 0, 0, '144140'), -- 160418 - Vertex Color Lime Green
(160417, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160417
(167358, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167358
(165027, 0, 0, 0, 1, 0, 0, 0, 0, '123169'), -- 165027 - Mod Scale 105-110%
(171142, 0, 0, 0, 1, 0, 0, 0, 0, '282999'), -- 171142 - Anim Replacement - New Drunk
(157945, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157945
(171217, 0, 0, 1, 1, 0, 0, 0, 0, '244807'), -- 171217 - Anim Replacement - New Drunk
(171129, 0, 0, 0, 1, 0, 0, 0, 0, '319502'), -- 171129 - Cosmetic - Slime Cauldron
(165052, 0, 0, 0, 1, 0, 0, 0, 0, '315493'), -- 165052 - Cosmetic - Offhand Book
(161380, 0, 0, 0, 1, 0, 0, 0, 0, '259900'), -- 161380 - Stirring
(157313, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 157313
(161841, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161841
(171133, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171133
(171130, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 171130 - Anim Replacement - New Drunk
(166579, 0, 0, 0, 1, 0, 0, 0, 0, '315493'), -- 166579 - Cosmetic - Offhand Book
(172141, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 172141
(171135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 171135
(157515, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 157515
(165049, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165049
(165017, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165017
(171112, 0, 0, 0, 0, 0, 0, 0, 0, '333495'), -- 171112 - Carry Crate
(157226, 0, 0, 0, 1, 0, 0, 0, 0, '306664 306713 306722'), -- 157226 - Mixing Pool, Miscible Ooze, Viscous Oil
(165032, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 165032
(169129, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169129
(174813, 0, 0, 262144, 1, 0, 0, 0, 0, '145363'), -- 174813 - Permanent Feign Death (Stun, Untrackable, Immune)
(161613, 0, 0, 0, 1, 0, 0, 0, 0, '203315 144140'), -- 161613 - Plagued, Vertex Color Lime Green
(171375, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 171375
(32639, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- 32639 - Traveler's Tundra Mammoth
(32638, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- 32638 - Traveler's Tundra Mammoth
(167923, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167923 - Anim Replacement - New Drunk
(160029, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 160029
(162767, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 162767
(166908, 0, 0, 0, 1, 0, 0, 0, 0, '326001'), -- 166908 - Summon Creep Area Trigger
(158642, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 158642
(168192, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168192
(176024, 0, 0, 50331648, 1, 0, 0, 0, 0, '308853'), -- Crawbat - Battle Pet Periodic
(168196, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 168196 - Permanent Feign Death (Flies)
(165034, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 165034
(162257, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Invisible Stalker
(162256, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Invisible Stalker
(174650, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174650
(159930, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 159930
(168216, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 168216
(174653, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 174653
(169751, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 169751
(173200, 0, 0, 0, 1, 0, 0, 0, 0, '308853'), -- Bleak Skitterer - Battle Pet Periodic
(167359, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 167359
(162259, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162259
(159856, 0, 0, 0, 1, 0, 0, 0, 0, '214567 276684'), -- 159856 - Mod Scale 90-110%, Churning Dirt
(160060, 0, 0, 0, 1, 0, 0, 0, 0, '203315'), -- 160060 - Plagued
(176023, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Crawbat
(167935, 0, 0, 0, 1, 0, 0, 0, 0, '123169 331874'), -- 167935 - Mod Scale 105-110%, Touch of Plague
(170191, 0, 0, 0, 1, 0, 0, 0, 0, '322272'), -- 170191 - Stringy Growth
(160048, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 160048 - Anim Replacement - New Drunk
(167948, 0, 0, 0, 1, 0, 0, 0, 0, '244807'), -- 167948 - Anim Replacement - New Drunk
(167356, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167356
(167949, 0, 0, 0, 1, 0, 0, 0, 0, '331874'), -- 167949 - Touch of Plague
(170456, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 170456
(161396, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161396
(161390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161390
(162258, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 162258
(169634, 0, 0, 262144, 1, 0, 0, 0, 0, '154470'), -- 169634 - Permanent Feign Death (Flies)
(161668, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161668
(161395, 0, 0, 0, 1, 0, 0, 0, 0, '330574'), -- 161395 - Deathbolt Rift
(168045, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 168045
(167641, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167641
(161679, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161679
(167642, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167642
(161676, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161676
(167355, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(167273, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167273
(161881, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161881
(161388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161388
(156558, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 156558
(157803, 0, 0, 0, 1, 0, 0, 0, 0, '307830'), -- 157803 - Archon Fragment
(157514, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 157514
(157843, 0, 0, 0, 1, 0, 0, 0, 0, '314898 247866'), -- 157843 - Visectus, Set Health % (Uses Override Points) (No Health Regen)
(62822, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- 62822 - Grand Expedition Yak
(62821, 0, 0, 0, 1, 0, 0, 0, 0, '122729 123236'), -- 62821 - Grand Expedition Yak, Grummle Booth A
(175021, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pulsating Maggot
(158339, 0, 0, 0, 0, 0, 0, 0, 0, '344880'), -- 158339 - Carry Candle
(167209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167209
(170971, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 170971
(167741, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 167741
(142666, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- 142666 - Grand Expedition Yak
(142668, 0, 0, 0, 1, 0, 0, 0, 0, '122729'), -- 142668 - Grand Expedition Yak
(160415, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 160415
(168381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Baroness Draka
(167747, 0, 0, 0, 2, 0, 0, 0, 0, '99203'), -- 167747 - 100% Threat Reduction
(167737, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167737
(160424, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 160424
(167743, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- 167743
(161376, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 161376
(164667, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prime Shieldguard
(161399, 0, 0, 0, 1, 0, 0, 0, 0, '314093'), -- 161399 - Useful Parts
(164833, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 164833
(166423, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 166423
(167354, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 167354
(157671, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 157671


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (97387, 94450, 95789, 96240, 96945, 95844, 83589, 92629, 99191, 98002, 97160, 97335, 100527, 83621, 92726, 96751, 96989, 83594, 96865, 96261, 96988, 83592, 99380, 83616, 92627, 63503, 96200, 96887, 96991, 83596, 96771, 99163, 96986, 96752, 97175, 38615, 100155, 26120, 95559, 95839, 94440, 97389, 94422, 94759, 94283, 96441, 45513, 94757, 96772, 31844, 94760, 94913, 94241, 96984, 94245, 76383, 94177, 94243, 96292, 96754, 96209, 95571, 95383, 97655, 98662, 95570, 95943, 95589, 96251, 95944, 95959, 97587, 95590, 98661, 95385, 97894, 96252, 97322, 97079, 95781, 96446, 96444, 96445, 43178, 97852, 96447, 95577, 95387, 97016, 95949, 95545, 70087, 95791, 94761, 95794, 97333, 95792, 85116, 96242, 28619, 69316, 32019, 96241, 93547, 27823, 59245, 91656, 94148, 95786, 95788, 97468, 97464, 95787, 96467, 95550, 94526, 97424, 100459, 95785, 97469, 97425, 97388, 95641, 97654, 94145, 93593, 28282, 28111, 96243, 95790, 34902, 100389, 98673, 96787, 97323, 95947, 95979, 98463, 94122, 98462, 94922, 34901, 61550, 98467, 92246, 99861, 59546, 96239, 11094, 94155, 80245, 98465, 96635, 95797, 96244, 96641, 94921, 15983, 96131, 96132, 94867, 96871, 64471, 94882, 97066, 96223, 97853, 94053, 96211, 95384, 98697, 97968, 11686, 94763, 95223, 94812, 42722, 42720, 99867, 94932, 95687, 96489, 95948, 96469, 96555, 77687, 77690, 95113, 96443, 96561, 95965, 95392, 95969, 96208, 96212, 95376, 95395, 95112, 95511, 94791, 96466, 97893, 95963, 95573, 95964);
REPLACE INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(97387, 0.9576568603515625, 1.20000004768371582, 0, 36839),
(94450, 4.491945266723632812, 4.840000152587890625, 0, 36839),
(95789, 3.67793893814086914, 2.5, 0, 36839),
(96240, 12.68311882019042968, 20, 0, 36839),
(96945, 5.266252040863037109, 4, 0, 36839),
(95844, 3.660829067230224609, 4.6875, 0, 36839),
(83589, 0.753035604953765869, 2.099999904632568359, 0, 36839),
(92629, 0.48092004656791687, 0.5, 0, 36839),
(99191, 5.122570514678955078, 6.800000190734863281, 0, 36839),
(98002, 16.12789726257324218, 12.25, 0, 36839),
(97160, 5.949621200561523437, 4, 0, 36839),
(97335, 9.512338638305664062, 15, 0, 36839),
(100527, 6.026553630828857421, 8, 0, 36839),
(83621, 1.29091811180114746, 3.60000014305114746, 0, 36839),
(92726, 0.5, 1, 0, 36839),
(96751, 5.266252040863037109, 4, 0, 36839),
(96989, 0.559553146362304687, 1, 0, 36839),
(83594, 0.753035604953765869, 2.099999904632568359, 0, 36839),
(96865, 5.266251564025878906, 5.600000381469726562, 0, 36839),
(96261, 9.512338638305664062, 15, 0, 36839),
(96988, 0.559553146362304687, 1, 0, 36839),
(83592, 0.753035604953765869, 2.099999904632568359, 0, 36839),
(99380, 0.980323672294616699, 0.974999964237213134, 0, 36839),
(83616, 2.366683244705200195, 6.599999904632568359, 0, 36839),
(92627, 0.480920016765594482, 0.5, 0, 36839),
(63503, 1.845841288566589355, 0.900000035762786865, 0, 36839),
(96200, 0.699441432952880859, 1.25, 0, 36839),
(96887, 1.936377167701721191, 5.399999618530273437, 0, 36839),
(96991, 0.480427175760269165, 0, 0, 36839),
(83596, 0.968188643455505371, 2.70000004768371582, 0, 36839),
(96771, 5.266252040863037109, 4, 0, 36839),
(99163, 1.925046801567077636, 0, 0, 36839),
(96986, 0.559553146362304687, 1, 0, 36839),
(96752, 5.266251564025878906, 4, 0, 36839),
(97175, 3, 1.5, 0, 36839),
(38615, 0.60000002384185791, 1.20000004768371582, 0, 36839),
(100155, 1.103381752967834472, 0.75, 0, 36839),
(26120, 0.300000011920928955, 0.649999976158142089, 0, 36839),
(95559, 1.211015939712524414, 1.949999928474426269, 0, 36839),
(95839, 12.25076007843017578, 13.20000076293945312, 0, 36839),
(94440, 2.654331207275390625, 2.859999895095825195, 0, 36839),
(97389, 0.9576568603515625, 1.20000004768371582, 0, 36839),
(94422, 2.654331207275390625, 2.859999895095825195, 0, 36839),
(94759, 1.024705886840820312, 1.65000009536743164, 0, 36839),
(94283, 4.491945266723632812, 4.840000152587890625, 0, 36839),
(96441, 7.350456714630126953, 7.920000553131103515, 0, 36839),
(45513, 0.5, 2.5, 0, 36839),
(94757, 1.024705886840820312, 1.65000009536743164, 0, 36839),
(96772, 5.266252040863037109, 4, 0, 36839),
(31844, 0.150000005960464477, 1.5, 0, 36839),
(94760, 1.024705886840820312, 1.65000009536743164, 0, 36839),
(94913, 4.963873863220214843, 7.199999809265136718, 0, 36839),
(94241, 2.919764280319213867, 3.145999908447265625, 0, 36839),
(96984, 0.839329779148101806, 1.5, 0, 36839),
(94245, 2.919764280319213867, 3.145999908447265625, 0, 36839),
(76383, 0.526631593704223632, 0.5, 0, 36839),
(94177, 4.491945266723632812, 4.840000152587890625, 0, 36839),
(94243, 2.919764280319213867, 3.145999908447265625, 0, 36839),
(96292, 4.716542720794677734, 5.081999778747558593, 0, 36839),
(96754, 0.839329779148101806, 1.5, 0, 36839),
(96209, 0.839329779148101806, 1.5, 0, 36839),
(95571, 1.420079946517944335, 1.5, 0, 36839),
(95383, 1.988111853599548339, 4.90000009536743164, 0, 36839),
(97655, 3.07595229148864746, 1.049999952316284179, 0, 36839),
(98662, 1.175700068473815917, 3.948750257492065429, 0, 36839),
(95570, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(95943, 1.420079946517944335, 1.5, 0, 36839),
(95589, 2.108818769454956054, 2.227499961853027343, 0, 36839),
(96251, 0.839329779148101806, 1.5, 0, 36839),
(95944, 0.870888888835906982, 2.925000190734863281, 0, 36839),
(95959, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(97587, 0.870888888835906982, 2.925000190734863281, 0, 36839),
(95590, 1.420079946517944335, 1.5, 0, 36839),
(98661, 2.108818769454956054, 2.227499961853027343, 0, 36839),
(95385, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(97894, 4.963873863220214843, 7.199999809265136718, 0, 36839),
(96252, 0.699441432952880859, 1.25, 0, 36839),
(97322, 2.63054203987121582, 4, 0, 36839),
(97079, 0.526631593704223632, 0.5, 0, 36839),
(95781, 2.63054203987121582, 4, 0, 36839),
(96446, 0.699441432952880859, 1.25, 0, 36839),
(96444, 0.699441432952880859, 1.25, 0, 36839),
(96445, 0.699441432952880859, 1.25, 0, 36839),
(43178, 0.5, 0, 0, 36839),
(97852, 2.022901773452758789, 1.80000007152557373, 0, 36839),
(96447, 0.699441432952880859, 1.25, 0, 36839),
(95577, 0.164499998092651367, 0.699999988079071044, 0, 36839),
(95387, 1.917107939720153808, 2.02500009536743164, 0, 36839),
(97016, 3.675227880477905273, 3.960000038146972656, 0, 36839),
(95949, 0.696711122989654541, 2.340000152587890625, 0, 36839),
(95545, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(70087, 3.68454742431640625, 6, 0, 36839),
(95791, 1.83896946907043457, 1.25, 0, 36839),
(94761, 0.93155074119567871, 1.5, 0, 36839),
(95794, 11.74995708465576171, 40, 0, 36839),
(97333, 11.41480636596679687, 18, 0, 36839),
(95792, 0.919484734535217285, 0.625, 0, 36839),
(85116, 2.807442188262939453, 4, 0, 36839),
(96242, 1.902467727661132812, 3, 0, 36839),
(28619, 2, 3, 0, 36839),
(69316, 0.349999994039535522, 1, 0, 36839),
(32019, 1, 1.5, 0, 36839),
(96241, 1.902467727661132812, 3, 0, 36839),
(93547, 6.026553630828857421, 8, 0, 36839),
(27823, 0.25, 0.5, 0, 36839),
(59245, 0.155000001192092895, 0.5, 0, 36839),
(91656, 2.574557065963745117, 1.399999976158142089, 0, 36839),
(94148, 0.155000001192092895, 0.5, 0, 36839),
(95786, 0.919484734535217285, 0.625, 0, 36839),
(95788, 1.83896946907043457, 1.25, 0, 36839),
(97468, 3.043948650360107421, 4.800000190734863281, 0, 36839),
(97464, 1.902467727661132812, 3, 0, 36839),
(95787, 1.471175551414489746, 1, 0, 36839),
(96467, 1.626700997352600097, 1.80000007152557373, 0, 36839),
(95550, 0.80686497688293457, 1.65000009536743164, 0, 36839),
(94526, 0.80686497688293457, 1.65000009536743164, 0, 36839),
(97424, 0.734413444995880126, 1.3125, 0, 36839),
(100459, 0.697031497955322265, 1.875, 0, 36839),
(95785, 1.103381752967834472, 0.75, 0, 36839),
(97469, 0.880216360092163085, 1.80000007152557373, 0, 36839),
(97425, 0.734413444995880126, 1.3125, 0, 36839),
(97388, 0.9576568603515625, 1.20000004768371582, 0, 36839),
(95641, 1.420079946517944335, 1.5, 0, 36839),
(97654, 3.07595229148864746, 1.049999952316284179, 0, 36839),
(94145, 1.056259632110595703, 2.160000085830688476, 0, 36839),
(93593, 2.361111164093017578, 2.5, 0, 36839),
(28282, 0.465000003576278686, 1.5, 0, 36839),
(28111, 1, 1.5, 0, 36839),
(96243, 1.268311858177185058, 2, 0, 36839),
(95790, 0.919484734535217285, 0.625, 0, 36839),
(34902, 2.56968855857849121, 2.25, 0, 36839),
(100389, 10.11450862884521484, 9, 0, 36839),
(98673, 4.136561870574951171, 6, 0, 36839),
(96787, 12.05310726165771484, 16, 0, 36839),
(97323, 3.261872053146362304, 4.960000038146972656, 0, 36839),
(95947, 0.870888888835906982, 2.925000190734863281, 0, 36839),
(95979, 0.660162210464477539, 1.349999904632568359, 0, 36839),
(98463, 0.063000001013278961, 0.270000010728836059, 0, 36839),
(94122, 0.880216360092163085, 1.80000007152557373, 0, 36839),
(98462, 0.063000001013278961, 0.270000010728836059, 0, 36839),
(94922, 5.239645004272460937, 7.599999904632568359, 0, 36839),
(34901, 1.370500564575195312, 1.20000004768371582, 0, 36839),
(61550, 0.286011546850204467, 0.150000005960464477, 0, 36839),
(98467, 0.100000001490116119, 0.100000001490116119, 0, 36839),
(92246, 1.239107370376586914, 0.60000002384185791, 0, 36839),
(99861, 0.46358346939086914, 0.300000011920928955, 0, 36839),
(59546, 0.286011546850204467, 0.150000005960464477, 0, 36839),
(96239, 0.760987162590026855, 1.20000004768371582, 0, 36839),
(11094, 1.370500564575195312, 1.20000004768371582, 0, 36839),
(94155, 4.5, 9, 0, 36839),
(80245, 0.150000005960464477, 0.25, 0, 36839),
(98465, 0.063000001013278961, 0.270000010728836059, 0, 36839),
(96635, 0.606859922409057617, 0.41250002384185791, 0, 36839),
(95797, 0.267373949289321899, 0, 0, 36839),
(96244, 0.88781827688217163, 1.399999976158142089, 0, 36839),
(96641, 2.536623716354370117, 4, 0, 36839),
(94921, 3.033478736877441406, 4.40000009536743164, 0, 36839),
(15983, 0.150000005960464477, 0.25, 0, 36839),
(96131, 0.615508496761322021, 1.10000002384185791, 0, 36839),
(96132, 0.615508496761322021, 1.10000002384185791, 0, 36839),
(94867, 2.757707834243774414, 4, 0, 36839),
(96871, 3.22971343994140625, 3.375, 0, 36839),
(64471, 0.619832873344421386, 0, 0, 36839),
(94882, 3.860790967941284179, 5.599999904632568359, 0, 36839),
(97066, 3.675227880477905273, 3.960000038146972656, 0, 36839),
(96223, 1.937827825546264648, 2.024999856948852539, 0, 36839),
(97853, 2.022901773452758789, 1.80000007152557373, 0, 36839),
(94053, 0.733513593673706054, 1.5, 0, 36839),
(96211, 0.699441432952880859, 1.25, 0, 36839),
(95384, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(98697, 0.733513593673706054, 1.5, 0, 36839),
(97968, 0.880216360092163085, 1.80000007152557373, 0, 36839),
(11686, 0.5, 1, 0, 36839),
(94763, 0.93155074119567871, 1.5, 0, 36839),
(95223, 0.93155074119567871, 1.5, 0, 36839),
(94812, 29.16666603088378906, 12.25, 0, 36839),
(42722, 0.655764877796173095, 1.20000004768371582, 0, 36839),
(42720, 0.655764877796173095, 1.20000004768371582, 0, 36839),
(99867, 0.179999992251396179, 0.299999982118606567, 0, 36839),
(94932, 1.197071075439453125, 1.5, 0, 36839),
(95687, 1.420079946517944335, 1.5, 0, 36839),
(96489, 0.923262715339660644, 1.65000009536743164, 0, 36839),
(95948, 0.870888888835906982, 2.925000190734863281, 0, 36839),
(96469, 1.355584144592285156, 3, 0, 36839),
(96555, 0.839329779148101806, 1.5, 0, 36839),
(77687, 0.912485718727111816, 1.20000004768371582, 0, 36839),
(77690, 0.912485718727111816, 1.20000004768371582, 0, 36839),
(95113, 1.316778182983398437, 1.65000009536743164, 0, 36839),
(96443, 0.354000002145767211, 2.25, 0, 36839),
(96561, 0.839329779148101806, 1.5, 0, 36839),
(95965, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(95392, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(95969, 0.870888888835906982, 2.925000190734863281, 0, 36839),
(96208, 0.839329779148101806, 1.5, 0, 36839),
(96212, 0.699441432952880859, 1.25, 0, 36839),
(95376, 1.079260706901550292, 1.139999985694885253, 0, 36839),
(95395, 1.136063933372497558, 1.20000004768371582, 0, 36839),
(95112, 1.43648529052734375, 1.80000007152557373, 0, 36839),
(95511, 1.420079946517944335, 1.5, 0, 36839),
(94791, 0.93155074119567871, 1.5, 0, 36839),
(96466, 1.626700997352600097, 1.80000007152557373, 0, 36839),
(97893, 1.737355947494506835, 2.519999980926513671, 0, 36839),
(95963, 0.696711122989654541, 2.340000152587890625, 0, 36839),
(95573, 0.454852879047393798, 0, 0, 36839),
(95964, 0.696711122989654541, 2.340000152587890625, 0, 36839);


DELETE FROM `npc_vendor` WHERE (`entry`=165032 AND `item`=178539 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=165032 AND `item`=178552 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=165032 AND `item`=178534 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=165032 AND `item`=180430 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=165032 AND `item`=178537 AND `ExtendedCost`=0 AND `type`=1);
REPLACE INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(165032, 5, 178539, 0, 0, 1, 0, 0, 36839), -- Lukewarm Tauralus Milk
(165032, 4, 178552, 0, 0, 1, 0, 0, 36839), -- Blood Oranges
(165032, 3, 178534, 0, 0, 1, 0, 0, 36839), -- Corpini Slurry
(165032, 2, 180430, 0, 0, 1, 0, 0, 36839), -- Finger Food
(165032, 1, 178537, 0, 0, 1, 0, 0, 36839); -- Hair-Trussed Fungi


DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (169170,169147,169226,169223,168572,168365,168578,168574,169696,169088,169068,169103,165366,169063,169096,169117,167483,157519,168941,168972,164831,164825,157708,164860,164824,170901,171358,173944,171419,164830,161397,161398,171112,161613,165034,169634,167641,167642,161676,167273,161388,158339,167741,160415,168381,167747,167737,160424,167743,164667,157671)) OR (`ID`=2 AND `CreatureID` IN (160424,157671)) OR (`ID`=3 AND `CreatureID`=157671);
REPLACE INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(169170, 1, 174217, 0, 0, 0, 0, 0, 176576, 0, 0), -- 169170
(169147, 1, 174217, 0, 0, 176724, 0, 0, 176576, 0, 0), -- 169147
(169226, 1, 176551, 0, 0, 0, 0, 0, 176576, 0, 0), -- 169226
(169223, 1, 174217, 0, 0, 176724, 0, 0, 176576, 0, 0), -- 169223
(168572, 1, 176565, 0, 0, 176566, 0, 0, 0, 0, 0), -- 168572
(168365, 1, 118560, 0, 0, 0, 0, 0, 0, 0, 0), -- 168365
(168578, 1, 176580, 0, 0, 0, 0, 0, 0, 0, 0), -- 168578
(168574, 1, 176607, 0, 0, 0, 0, 0, 0, 0, 0), -- 168574
(169696, 1, 176550, 0, 0, 0, 0, 0, 0, 0, 0), -- 169696
(169088, 1, 178918, 0, 0, 0, 0, 0, 176574, 0, 0), -- 169088
(169068, 1, 178918, 0, 0, 0, 0, 0, 176574, 0, 0), -- 169068
(169103, 1, 177264, 0, 0, 176724, 0, 0, 176574, 0, 0), -- 169103
(165366, 1, 157585, 0, 0, 0, 0, 0, 155772, 0, 0), -- 165366
(169063, 1, 176551, 0, 0, 0, 0, 0, 176574, 0, 0), -- 169063
(169096, 1, 178918, 0, 0, 0, 0, 0, 176574, 0, 0), -- 169096
(169117, 1, 176551, 0, 0, 0, 0, 0, 176574, 0, 0), -- 169117
(160424, 2, 0, 0, 0, 0, 0, 0, 155772, 0, 0), -- 160424
(157671, 3, 176595, 0, 0, 0, 0, 0, 176576, 0, 0), -- 157671
(167483, 1, 174217, 0, 0, 0, 0, 0, 176576, 0, 0), -- 167483
(157519, 1, 177264, 0, 0, 0, 0, 0, 0, 0, 0), -- 157519
(168941, 1, 174217, 0, 0, 176724, 0, 0, 0, 0, 0), -- 168941
(168972, 1, 174217, 0, 0, 0, 0, 0, 176576, 0, 0), -- 168972
(164831, 1, 176546, 0, 0, 0, 0, 0, 177048, 0, 0), -- 164831
(164825, 1, 176543, 0, 0, 0, 0, 0, 176575, 0, 0), -- 164825
(157708, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- 157708
(164860, 1, 178925, 0, 0, 0, 0, 0, 0, 0, 0), -- 164860
(164824, 1, 177261, 0, 0, 176722, 0, 0, 0, 0, 0), -- 164824
(170901, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- 170901
(171358, 1, 177261, 0, 0, 176722, 0, 0, 0, 0, 0), -- 171358
(173944, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- 173944
(171419, 1, 176543, 0, 0, 0, 0, 0, 176575, 0, 0), -- 171419
(164830, 1, 174304, 0, 0, 0, 0, 0, 0, 0, 0), -- 164830
(161397, 1, 178916, 0, 0, 0, 0, 0, 0, 0, 0), -- 161397
(157671, 2, 174217, 0, 0, 176724, 0, 0, 0, 0, 0), -- 157671
(161398, 1, 176543, 0, 0, 0, 0, 0, 176574, 0, 0), -- 161398
(171112, 1, 176569, 0, 0, 0, 0, 0, 0, 0, 0), -- 171112
(161613, 1, 180699, 0, 0, 0, 0, 0, 0, 0, 0), -- 161613
(165034, 1, 174216, 0, 0, 0, 0, 0, 0, 0, 0), -- 165034
(169634, 1, 178918, 0, 0, 176724, 0, 0, 0, 0, 0), -- 169634
(167641, 1, 177267, 0, 0, 0, 0, 0, 0, 0, 0), -- 167641
(167642, 1, 176571, 0, 0, 0, 0, 0, 176576, 0, 0), -- 167642
(161676, 1, 157585, 0, 0, 0, 0, 0, 0, 0, 0), -- 161676
(167273, 1, 174217, 0, 0, 0, 0, 0, 176576, 0, 0), -- 167273
(161388, 1, 180700, 0, 0, 0, 0, 0, 0, 0, 0), -- 161388
(158339, 1, 176595, 0, 0, 0, 0, 0, 0, 0, 0), -- 158339
(167741, 1, 176551, 0, 0, 0, 0, 0, 0, 0, 0), -- 167741
(160415, 1, 177264, 0, 0, 176724, 0, 0, 0, 0, 0), -- 160415
(168381, 1, 105037, 0, 0, 105037, 0, 0, 0, 0, 0), -- Baroness Draka
(167747, 1, 174217, 0, 0, 0, 0, 0, 176576, 0, 0), -- 167747
(167737, 1, 176571, 0, 0, 0, 0, 0, 0, 0, 0), -- 167737
(160424, 1, 157585, 0, 0, 0, 0, 0, 155772, 0, 0), -- 160424
(167743, 1, 176551, 0, 0, 0, 0, 0, 177048, 0, 0), -- 167743
(164667, 1, 177264, 0, 0, 176720, 0, 0, 176576, 0, 0), -- Prime Shieldguard
(157671, 1, 174217, 0, 0, 176724, 0, 0, 176576, 0, 0); -- 157671


DELETE FROM `gossip_menu` WHERE (`MenuId`=25770 AND `TextId`=40719) OR (`MenuId`=24706 AND `TextId`=38845) OR (`MenuId`=25331 AND `TextId`=39954) OR (`MenuId`=25330 AND `TextId`=39953) OR (`MenuId`=25329 AND `TextId`=39952) OR (`MenuId`=25328 AND `TextId`=39950) OR (`MenuId`=25327 AND `TextId`=39947) OR (`MenuId`=24852 AND `TextId`=39164);
REPLACE INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(25770, 40719, 36839), -- 169096
(24706, 38845, 36839), -- 157313
(25331, 39954, 36839), -- 157945
(25330, 39953, 36839), -- 157945
(25329, 39952, 36839), -- 157313
(25328, 39950, 36839), -- 165052
(25327, 39947, 36839), -- 165052
(24852, 39164, 36839); -- 159930

DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (24706,25331,25330,25328,25327)) OR (`OptionIndex`=1 AND `MenuId` IN (24706,24852));
REPLACE INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(24706, 0, 0, 'What do you need for your mixing?', 0, 36839),
(25331, 0, 0, 'O.K.', 0, 36839),
(25330, 0, 0, 'Is there any way I can help?', 0, 36839),
(24706, 1, 0, 'Is there any way I can help?', 0, 36839),
(25328, 0, 0, 'O.K.', 0, 36839),
(25327, 0, 0, 'Is there any way I can help?', 0, 36839),
(24852, 1, 0, 'Your \"apprentice\"? What are you talking about?', 0, 36839);

DELETE FROM `gossip_menu_option_action` WHERE (`OptionIndex`=0 AND `MenuId` IN (25330,25327)) OR (`OptionIndex`=1 AND `MenuId`=24706);
REPLACE INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(25330, 0, 25331, 0),
(24706, 1, 25329, 0),
(25327, 0, 25328, 0);



REPLACE INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(157313, 0, 0, 'Come aid me! Bring me the ingredients for my research.', 14, 0, 100, 0, 0, 0, 0, 'Foul-Tongue Cyrlix to Pool of Mixed Monstrosities'),
(157313, 1, 0, 'Excellent, the fruition of our work may come sooner than I expected!', 14, 0, 100, 0, 0, 0, 0, 'Foul-Tongue Cyrlix'),
(157669, 0, 0, 'My... final... battle...', 12, 0, 100, 0, 0, 150141, 0, 'Steelskin Vanguard to Secutor Mevix'),
(157669, 1, 0, 'Face me!', 12, 0, 100, 0, 0, 150133, 0, 'Steelskin Vanguard to Player'),
(157669, 2, 0, 'I... am broken...', 12, 0, 100, 0, 0, 150143, 0, 'Steelskin Vanguard to Player'),
(157669, 3, 0, 'For eternal glory!', 12, 0, 100, 0, 0, 150135, 0, 'Steelskin Vanguard to Secutor Mevix'),
(157669, 4, 0, 'I fought... to... the end...', 12, 0, 100, 0, 0, 150147, 0, 'Steelskin Vanguard to Serafk'),
(157671, 0, 0, 'You have met your match!', 12, 0, 100, 0, 0, 152327, 0, 'Prime Bladeguard to Steelskin Vanguard'),
(159753, 0, 0, 'Who has left me so many juicy spiderling corpses!', 14, 0, 100, 0, 0, 0, 0, 'Ravenomous'),
(159886, 0, 0, 'Whooo isss knocking at my door.', 14, 0, 100, 0, 0, 0, 0, 'Sister Chelicerae to Intricate Webbing'),
(159886, 1, 0, 'Come in... mmmy children are quite hungrrry.', 14, 0, 100, 0, 0, 0, 0, 'Sister Chelicerae to Intricate Webbing'),
(159894, 0, 0, 'Strike them down! Accept nothing but victory!', 14, 0, 100, 66, 0, 0, 0, 'Baron Vyraz to Boneplated Veteran'),
(159930, 0, 0, 'A splash of venom for viscosity!', 12, 0, 100, 5, 0, 167463, 0, 'Plague Deviser Marileth to Player'),
(159930, 1, 0, 'The mixture must not congeal too early!', 12, 0, 100, 6, 0, 167461, 0, 'Plague Deviser Marileth to Player'),
(159930, 2, 0, 'Some spores to act as a catalyst!', 12, 0, 100, 1, 0, 167462, 0, 'Plague Deviser Marileth to Player'),
(159930, 3, 0, 'Excellent! Stir the cauldron once more to complete your work!', 12, 0, 100, 5, 0, 167464, 0, 'Plague Deviser Marileth to Player'),
(159930, 4, 0, 'Plague Deviser Marileth applauds you with pride!', 16, 0, 100, 0, 0, 0, 0, 'Plague Deviser Marileth to Player'),
(159930, 5, 0, 'Meet me in the House of Plagues when you are done, apprentice. Our work continues!', 12, 0, 100, 3, 0, 167465, 0, 'Plague Deviser Marileth to Player'),
(160029, 0, 0, 'Your slime moves towards a pile of refuse!', 16, 0, 100, 0, 0, 0, 0, 'Plagueborn Slime to Player'),
(160029, 1, 0, 'Plagueborn Slime dissolves the refuse and finds a piece of lab equipment!', 16, 0, 100, 0, 0, 0, 0, 'Plagueborn Slime to Player'),
(160474, 0, 0, 'Falling... apart...', 12, 0, 100, 659, 0, 150067, 0, 'Fleshsewn Scavenger to Player'),
(160474, 1, 0, 'I\'m gonna slaughter you!', 12, 0, 100, 659, 0, 150053, 0, 'Fleshsewn Scavenger to Secutor Mevix'),
(160474, 2, 0, 'Can\'t... end... like this...', 12, 0, 100, 659, 0, 150079, 0, 'Fleshsewn Scavenger to Player'),
(160959, 0, 0, 'I\'ll set the charge!', 12, 0, 100, 0, 0, 162615, 0, 'Secutor Mevix to Player'),
(160959, 1, 0, 'Keep them off me, mortal!', 12, 0, 100, 0, 0, 162616, 0, 'Secutor Mevix to Player'),
(160959, 2, 0, 'Done! Get clear!', 12, 0, 100, 0, 0, 162617, 0, 'Secutor Mevix to Player'),
(160959, 3, 0, 'This one should pack a punch!', 12, 0, 100, 0, 0, 162618, 0, 'Secutor Mevix to Player'),
(160959, 4, 0, 'We have incoming!', 12, 0, 100, 0, 0, 162619, 0, 'Secutor Mevix to Player'),
(160959, 5, 0, 'The charge is set! Get back!', 12, 0, 100, 0, 0, 162620, 0, 'Secutor Mevix to Player'),
(160959, 6, 0, 'Time for some mayhem!', 12, 0, 100, 0, 0, 162621, 0, 'Secutor Mevix to Player'),
(160959, 7, 0, 'Cover me!', 12, 0, 100, 0, 0, 162622, 0, 'Secutor Mevix to Player'),
(160959, 8, 0, 'Clock\'s ticking! Move!', 12, 0, 100, 0, 0, 162623, 0, 'Secutor Mevix to Player'),
(160959, 9, 0, 'We\'ve taken the ridge! Meet me on the field below!', 12, 0, 100, 0, 0, 162624, 0, 'Secutor Mevix to Player'),
(161016, 0, 0, 'Hah! How easily the Chosen fall!', 12, 0, 100, 0, 0, 0, 0, 'Lobber Jalrax'),
(161613, 0, 0, 'The plague has gone... and you will follow!', 12, 0, 100, 0, 0, 0, 0, 'Korrim the Cunning to Player'),
(161613, 1, 0, 'The damage... is already done...', 12, 0, 100, 0, 0, 0, 0, 'Korrim the Cunning to Player'),
(163892, 0, 0, '%s attempts to run away in fear!', 16, 0, 100, 0, 0, 0, 0, 'Rotting Slimeclaw'),
(164255, 0, 0, 'Intruders! You will be devoured whole!', 14, 0, 100, 0, 0, 0, 0, 'Globgrog'),
(164255, 1, 0, 'The... hunger... ends...', 14, 0, 100, 0, 0, 0, 0, 'Globgrog to Player'),
(164967, 0, 0, 'You cannot comprehend my genius!', 14, 0, 100, 0, 0, 0, 0, 'Doctor Ickus'),
(164967, 1, 0, '|TInterface\\ICONS\\ability_warlock_burningembers.blp:20|t Doctor Ickus leaps away to cast |cFFFF0000|Hspell:329200|h[Virulent Explosion]|h|r!', 41, 0, 100, 0, 0, 0, 0, 'Doctor Ickus to Doctor Ickus'),
(164967, 2, 0, 'The next procedure will be a real blowout!', 14, 0, 100, 0, 0, 0, 0, 'Doctor Ickus'),
(164967, 3, 0, 'At least you were useful test subjects.', 14, 0, 100, 0, 0, 0, 0, 'Doctor Ickus'),
(165052, 0, 0, 'The destruction of our house only makes us stronger!', 12, 0, 100, 1, 0, 0, 0, 'Vial Master Lurgy'),
(167271, 0, 0, 'Raaagghhh!', 12, 0, 100, 659, 0, 150133, 0, 'Blastsewn Loader to Player'),
(167271, 1, 0, 'Going to... pieces...', 12, 0, 100, 0, 0, 150073, 0, 'Blastsewn Loader to Secutor Mevix'),
(167483, 0, 0, 'Stay alert, $p! They\'ve broken through our lines!', 12, 0, 100, 0, 0, 0, 0, 'Boneplated Sharpshooter to Player'),
(168155, 0, 0, 'It\'s coming for us!', 14, 0, 100, 0, 0, 0, 0, 'Plaguebound to Player'),
(168155, 1, 0, 'Ahhhhhhh!!!!!!!', 14, 0, 100, 0, 0, 0, 0, 'Plaguebound to Player'),
(168155, 2, 0, 'We\'re better off jumping...', 14, 0, 100, 0, 0, 0, 0, 'Plaguebound to Player'),
(168886, 0, 0, 'Wonderful, more test subjects! Unleash the plagueborers!', 14, 0, 100, 0, 0, 0, 0, 'Virulax Blightweaver to Player'),
(168886, 1, 0, 'I will dissect you myself!', 14, 0, 100, 0, 0, 0, 0, 'Virulax Blightweaver to Player'),
(169063, 0, 0, 'This slaughter ends now!', 12, 0, 100, 669, 0, 0, 0, 'Demoralized Soldier to Player'),
(169063, 1, 0, 'They\'re dragging off our wounded!', 12, 0, 100, 669, 0, 0, 0, 'Demoralized Soldier to Player'),
(169096, 0, 0, 'Honor has fled this battle.', 12, 0, 100, 669, 0, 0, 0, 'Demoralized Soldier to Player'),
(169096, 1, 0, 'Never surrender!', 12, 0, 100, 25, 0, 152301, 0, 'Demoralized Soldier to Player'),
(169117, 0, 0, 'Victory for the Chosen!', 12, 0, 100, 0, 0, 0, 0, 'Hesitant Soldier to Player'),
(169147, 0, 0, 'Prepare yourself!', 12, 0, 100, 0, 0, 152318, 0, 'Boneplated Phalanx to Player'),
(169226, 0, 0, 'We strike when you sound the horn. For the Chosen!', 12, 0, 100, 0, 0, 162625, 0, 'Secutor Mevix to Player'),
(169696, 0, 0, 'Yes, I\'d love to guard this place while you take a nap, thank you for asking.', 14, 0, 100, 904, 0, 0, 0, 'Mire Soldier'),
(169696, 1, 0, 'Working hard I see....', 14, 0, 100, 53, 0, 0, 0, 'Mire Soldier'),
(169696, 2, 0, 'Wake up, spore breath!', 14, 0, 100, 0, 0, 0, 0, 'Mire Soldier'),
(170806, 0, 0, 'Plague Deviser Marileth applauds your hard work.', 16, 0, 100, 21, 0, 0, 0, 'Plague Deviser Marileth to Player');

REPLACE INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(164829, 164830, 0, 0, '164829 - 164830', 0, 0); -- 164829 - 164830

REPLACE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(170971, 333494, 0, 0),
(170191, 322254, 0, 0),
(160060, 311710, 0, 0),
(160253, 321337, 0, 0),
(164915, 337459, 0, 0),
(161026, 313289, 0, 0),
(161027, 329601, 0, 0),
(161028, 329602, 0, 0);

DELETE FROM creature WHERE guid>210456407 AND guid<210458369;
DELETE FROM creature_addon WHERE guid>210456407 AND guid<210458369;
DELETE FROM  gameobject WHERE guid>25347556 AND guid<25347762;
DELETE FROM  gameobject_addon WHERE guid>25347556 AND guid<25347741;
