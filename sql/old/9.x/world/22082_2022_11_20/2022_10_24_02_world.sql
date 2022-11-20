SET @CGUID := 222573;
SET @OGUID := 166055;

-- Creature templates
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23537; -- Headless Horseman - Fire (DND)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=23543; -- Shade of the Horseman
UPDATE `creature_template` SET `minlevel`=1 WHERE `entry`=23712; -- Touring Orphan
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=24519; -- Costumed Orphan Matron

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23537; -- 23537 (Headless Horseman - Fire (DND))
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23543; -- 23543 (Shade of the Horseman)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=23712; -- 23712 (Touring Orphan)
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=24519; -- 24519 (Costumed Orphan Matron)

DELETE FROM `creature_template_movement` WHERE `CreatureId`=23543;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(23543, 0, 0, 1, 0, 0, 0, NULL);

-- Gossips
UPDATE `gossip_menu_option` SET `ActionMenuID`=8880, `VerifiedBuild`=45745 WHERE `MenuID`=9468 AND `OptionID`=0;

-- Scaling
DELETE FROM `creature_template_scaling` WHERE `DifficultyID`=0 AND `Entry` IN (23543, 23537, 23712, 24519);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(23537, 0, 0, 0, 425, 45745),
(23543, 0, 0, 0, 425, 45745),
(23712, 0, -4, -2, 1723, 45745),
(24519, 0, 0, 0, 425, 45745);

-- Gameobject templates
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=45745 WHERE `entry`=186887; -- Large Jack-o'-Lantern
UPDATE `gameobject_template` SET `ContentTuningId`=425, `VerifiedBuild`=45745 WHERE `entry`=190036; -- Candy Bucket

UPDATE `gameobject_template_addon` SET `flags`=262176 WHERE `entry`=186234; -- Water Barrel
UPDATE `gameobject_template_addon` SET `faction`=1732 WHERE `entry`=190036; -- Candy Bucket

-- Quest
DELETE FROM `quest_poi` WHERE (`QuestID`=11131 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=11439 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=11439 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=32009 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=25255 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=25255 AND `BlobIndex`=1 AND `Idx1`=2) OR (`QuestID`=25255 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=25255 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(11131, 0, 0, -1, 0, 0, 0, 37, 0, 1, 0, 0, 0, 0, 0, 45745), -- Stop the Fires!
(11439, 0, 1, 0, 254721, 23537, 0, 27, 0, 3, 0, 0, 0, 0, 0, 45745), -- Fire Brigade Practice
(11439, 0, 0, -1, 0, 0, 0, 27, 0, 1, 0, 0, 0, 0, 0, 45745); -- Fire Brigade Practice
 
UPDATE `quest_poi` SET `VerifiedBuild`=45745 WHERE (`QuestID`=12133 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi` SET `VerifiedBuild`=45745 WHERE (`QuestID`=12135 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=12135 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=12135 AND `BlobIndex`=0 AND `Idx1`=0);

DELETE FROM `quest_poi_points` WHERE (`QuestID`=11131 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=11439 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=11439 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(11131, 0, 0, -9430, 56, 57, 45745), -- Stop the Fires!
(11439, 1, 11, -5716, -563, 0, 45745), -- Fire Brigade Practice
(11439, 1, 10, -5730, -554, 0, 45745), -- Fire Brigade Practice
(11439, 1, 9, -5743, -545, 0, 45745), -- Fire Brigade Practice
(11439, 1, 8, -5743, -527, 0, 45745), -- Fire Brigade Practice
(11439, 1, 7, -5743, -509, 0, 45745), -- Fire Brigade Practice
(11439, 1, 6, -5743, -491, 404, 45745), -- Fire Brigade Practice
(11439, 1, 5, -5725, -482, 399, 45745), -- Fire Brigade Practice
(11439, 1, 4, -5707, -482, 414, 45745), -- Fire Brigade Practice
(11439, 1, 3, -5680, -491, 414, 45745), -- Fire Brigade Practice
(11439, 1, 2, -5676, -514, 414, 45745), -- Fire Brigade Practice
(11439, 1, 1, -5676, -545, 413, 45745), -- Fire Brigade Practice
(11439, 1, 0, -5689, -568, 404, 45745), -- Fire Brigade Practice
(11439, 0, 0, -5622, -473, 397, 45745); -- Fire Brigade Practice
 
UPDATE `quest_poi_points` SET `VerifiedBuild`=45745 WHERE (`QuestID`=12133 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=45745 WHERE (`QuestID`=12135 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=12135 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=12135 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (11131, 12133, 12135);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(11131, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Stop the Fires!
(12133, 0, 0, 0, 0, 0, 0, 0, 0, 45745), -- Smash the Pumpkin
(12135, 0, 0, 0, 0, 0, 0, 0, 0, 45745); -- "Let the Fires Come!"

UPDATE `quest_details` SET `VerifiedBuild`=45745 WHERE `ID`=11439;
 
UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `CompletionText`='$n, you promised to save the children!', `VerifiedBuild`=45745 WHERE `ID`=11131; -- Stop the Fires!
UPDATE `quest_request_items` SET `CompletionText`='Yes, $n?', `VerifiedBuild`=45745 WHERE `ID`=12133; -- Smash the Pumpkin
UPDATE `quest_request_items` SET `CompletionText`='$n, you promised to save the children!', `VerifiedBuild`=45745 WHERE `ID`=12135; -- "Let the Fires Come!"

UPDATE `quest_offer_reward` SET `Emote1`=0, `RewardText`='Oh, thank you!  May the Light bless your good works, kind $gsir:lady;.  The shadow of the Dark Horseman yet looms, but at least, for now, the village is safe from his flames.', `VerifiedBuild`=45745 WHERE `ID`=11131; -- Stop the Fires!
UPDATE `quest_offer_reward` SET `RewardText`='You''re smudged with soot!  You must have been extinguishing fires!$B$BWell done!  As an honorary member of the Fire Brigade, I beg you to return here if ever the village needs you!', `VerifiedBuild`=45745 WHERE `ID`=11439; -- Fire Brigade Practice
UPDATE `quest_offer_reward` SET `RewardText`='Oh, thank you!  May the Light bless your good works, kind $gsir:lady;.  The shadow of the Dark Horseman yet looms, but at least, for now, the village is safe from his flames.', `VerifiedBuild`=45745 WHERE `ID`=12135; -- "Let the Fires Come!"
UPDATE `quest_offer_reward` SET `Emote1`=1, `RewardText`='You found this inside the Headless Horseman''s jack-o-lantern?  It is an old symbol of the Light.  It must have been the Horseman''s, before he was cursed and turned into the monster he is today.  Thank you, $n.  This symbol deserves to be with paladins.  I will make sure they get it.$B$BOh, and I almost forgot!  You have a secret admirer...$B$BOne of the children wanted you to have this.  $gShe:He; was too shy to give it to you $gherself:himself;.', `VerifiedBuild`=45745 WHERE `ID`=12133; -- Smash the Pumpkin
UPDATE `quest_offer_reward` SET `VerifiedBuild`=45745 WHERE `ID`=12332;

DELETE FROM `creature_queststarter` WHERE `id`=24519 AND `quest`=12135;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(24519, 12135, 45745); -- "Let the Fires Come!" offered Costumed Orphan Matron

UPDATE `creature_queststarter` SET `VerifiedBuild`=45745 WHERE `id`=24519 AND `quest` IN (11131, 11439);

UPDATE `creature_questender` SET `VerifiedBuild`=45745 WHERE `id`=24519 AND `quest` IN (11131, 11439, 12133, 12135);

DELETE FROM `game_event_creature_quest` WHERE `id`=24519;

DELETE FROM `gameobject_queststarter` WHERE `id`=190036 AND `quest`=12332;
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(190036, 12332, 45745);

UPDATE `gameobject_queststarter` SET `VerifiedBuild`=45745 WHERE `id`=186887 AND `quest`=12133;

UPDATE `gameobject_questender` SET `VerifiedBuild`=45745 WHERE `id`=190036 AND `quest`=12332;

DELETE FROM `game_event_gameobject_quest` WHERE `id`=190036;

UPDATE `conditions` SET `Comment`='Show quest ''Fire Brigade Practice'' if player is located in Kharanos' WHERE `SourceTypeOrReferenceId`=19 AND `SourceEntry`=11439;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+46;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 727, 0, 1, 131, '0', 0, 0, 0, 1, -5753.5478515625, -486.14599609375, 397.446533203125, 4.764749050140380859, 120, 0, 0, 3208, 0, 0, 0, 0, 0, 45745), -- Ironforge Mountaineer (Area: Kharanos - Difficulty: 0)
(@CGUID+1, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5592.62939453125, -513.1434326171875, 413.200286865234375, 0.418879032135009765, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+2, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5569.30029296875, -453.50531005859375, 413.957122802734375, 0.244346097111701965, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire, 42091 - Headless Horseman - Fire Size)
(@CGUID+3, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5602.48876953125, -512.93988037109375, 413.349609375, 4.555309295654296875, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+4, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5591.30908203125, -451.56011962890625, 414.119140625, 6.195918560028076171, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+5, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5576.232421875, -528.524658203125, 413.310516357421875, 4.415682792663574218, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+6, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5610.64404296875, -513.148681640625, 413.48809814453125, 3.124139308929443359, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+7, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5600.7197265625, -513.49688720703125, 409.49169921875, 5.410520553588867187, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+8, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5561.84130859375, -445.294921875, 413.864013671875, 4.729842185974121093, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+9, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5577.59716796875, -462.362640380859375, 414.413116455078125, 2.234021425247192382, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+10, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5570.11767578125, -459.232330322265625, 414.162139892578125, 6.056292533874511718, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire, 42091 - Headless Horseman - Fire Size)
(@CGUID+11, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5576.17626953125, -506.083984375, 413.802886962890625, 0.314159274101257324, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+12, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5611.57666015625, -517.38531494140625, 413.508026123046875, 4.066617012023925781, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+13, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5590.50634765625, -503.79644775390625, 413.6107177734375, 0.541052043437957763, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+14, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5578.97119140625, -515.63604736328125, 418.2305908203125, 3.071779489517211914, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+15, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5587.3701171875, -456.188690185546875, 414.337158203125, 3.577924966812133789, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+16, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5579.26025390625, -504.0714111328125, 413.870361328125, 2.687807083129882812, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+17, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5606.1171875, -513.9608154296875, 413.425750732421875, 1.239183783531188964, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+18, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5592.69775390625, -508.243499755859375, 413.198577880859375, 1.117010712623596191, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+19, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5591.3349609375, -506.9825439453125, 416.902099609375, 3.298672199249267578, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42091 - Headless Horseman - Fire Size, 42154 - Headless Horseman - Dim Fire)
(@CGUID+20, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5576.13818359375, -520.48175048828125, 413.36090087890625, 3.50811171531677246, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+21, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5590.603515625, -512.17742919921875, 417.089080810546875, 2.460914134979248046, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+22, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5573.0166015625, -462.277130126953125, 414.32763671875, 1.553343057632446289, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire, 42091 - Headless Horseman - Fire Size)
(@CGUID+23, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5586.5224609375, -462.394744873046875, 414.571014404296875, 5.759586334228515625, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+24, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5565.75927734375, -450.4853515625, 413.891448974609375, 3.892084121704101562, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire, 42091 - Headless Horseman - Fire Size)
(@CGUID+25, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5597.5849609375, -513.343994140625, 413.274566650390625, 1.361356854438781738, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+26, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5578.8701171875, -510.202484130859375, 418.157562255859375, 0.959931075572967529, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+27, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5576.0546875, -511.168304443359375, 413.390380859375, 1.989675283432006835, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+28, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5581.982421875, -462.513336181640625, 414.499481201171875, 5.497786998748779296, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+29, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5565.82080078125, -445.305572509765625, 414.1419677734375, 0.122173048555850982, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+30, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5581.326171875, -520.92547607421875, 413.45751953125, 4.450589656829833984, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+31, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5595.66650390625, -513.594970703125, 409.415008544921875, 2.775073528289794921, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+32, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5605.53125, -513.3857421875, 409.533447265625, 1.448623299598693847, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+33, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5576.083984375, -524.460205078125, 413.22607421875, 0.366519153118133544, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+34, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5576.19140625, -515.56134033203125, 413.4317626953125, 2.076941728591918945, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+35, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5595.75341796875, -447.16253662109375, 414.118377685546875, 2.408554315567016601, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+36, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5581.23291015625, -527.37664794921875, 415.252410888671875, 0.383972436189651489, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42154 - Headless Horseman - Dim Fire)
(@CGUID+37, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5747.29638671875, -527.312744140625, 400.115203857421875, 1.274090290069580078, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42096 - Headless Horseman - Fire onSpawn, Size, 42091 - Headless Horseman - Fire Size, 42074 - Headless Horseman - Fire)
(@CGUID+38, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5754.14794921875, -526.8839111328125, 402.474517822265625, 1.047197580337524414, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42112 - Headless Horseman - Update Size)
(@CGUID+39, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5758.3759765625, -522.03582763671875, 399.287109375, 2.199114799499511718, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0) (Auras: 42112 - Headless Horseman - Update Size)
(@CGUID+40, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5753.0244140625, -532.90118408203125, 404.06353759765625, 0.663225114345550537, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0)
(@CGUID+41, 23537, 0, 1, 131, '0', 0, 0, 0, 0, -5761.04443359375, -528.05767822265625, 403.967010498046875, 1.064650893211364746, 120, 0, 0, 9433, 5751, 0, 0, 0, 0, 45745), -- Headless Horseman - Fire (DND) (Area: Kharanos - Difficulty: 0)
(@CGUID+42, 23712, 0, 1, 131, '0', 0, 0, 0, 0, -5622.77587890625, -470.675445556640625, 397.39288330078125, 5.340707302093505859, 120, 0, 0, 41, 0, 0, 0, 0, 0, 45745), -- Touring Orphan (Area: Kharanos - Difficulty: 0)
(@CGUID+43, 23712, 0, 1, 131, '0', 0, 0, 0, 0, -5623.98876953125, -472.76129150390625, 397.1551513671875, 5.934119224548339843, 120, 0, 0, 34, 0, 0, 0, 0, 0, 45745), -- Touring Orphan (Area: Kharanos - Difficulty: 0)
(@CGUID+44, 23712, 0, 1, 131, '0', 0, 0, 0, 0, -5620.98828125, -471.1534423828125, 397.332916259765625, 5.480333805084228515, 120, 0, 0, 34, 0, 0, 0, 0, 0, 45745), -- Touring Orphan (Area: Kharanos - Difficulty: 0)
(@CGUID+45, 23712, 0, 1, 131, '0', 0, 0, 0, 0, -5622.87353515625, -474.229705810546875, 397.0635986328125, 5.916666030883789062, 120, 0, 0, 34, 0, 0, 0, 0, 0, 45745), -- Touring Orphan (Area: Kharanos - Difficulty: 0)
(@CGUID+46, 24519, 0, 1, 131, '0', 0, 0, 0, 0, -5621.9462890625, -472.836700439453125, 397.14019775390625, 5.672319889068603515, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45745); -- Costumed Orphan Matron (Area: Kharanos - Difficulty: 0)

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+40;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180405, 0, 1, 131, '0', 0, 0, -5636.83349609375, -498.25, 399.752410888671875, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Kharanos - Difficulty: 0)
(@OGUID+1, 180405, 0, 1, 131, '0', 0, 0, -5585.7587890625, -461.76458740234375, 414.433380126953125, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Kharanos - Difficulty: 0)
(@OGUID+2, 180405, 0, 1, 131, '0', 0, 0, -5636.26708984375, -530.2227783203125, 404.7664794921875, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 120, 255, 1, 45745), -- G_Pumpkin_01 (Area: Kharanos - Difficulty: 0)
(@OGUID+3, 180406, 0, 1, 131, '0', 0, 0, -5611.35205078125, -513.34161376953125, 413.419525146484375, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Kharanos - Difficulty: 0)
(@OGUID+4, 180406, 0, 1, 131, '0', 0, 0, -5576.09375, -504.130218505859375, 413.209136962890625, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Kharanos - Difficulty: 0)
(@OGUID+5, 180406, 0, 1, 131, '0', 0, 0, -5579.09228515625, -461.78570556640625, 414.31842041015625, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 120, 255, 1, 45745), -- G_Pumpkin_02 (Area: Kharanos - Difficulty: 0)
(@OGUID+6, 180407, 0, 1, 131, '0', 0, 0, -5591.71728515625, -507.606109619140625, 405.010467529296875, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Kharanos - Difficulty: 0)
(@OGUID+7, 180407, 0, 1, 131, '0', 0, 0, -5587.2744140625, -531.5355224609375, 399.651641845703125, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Kharanos - Difficulty: 0)
(@OGUID+8, 180407, 0, 1, 131, '0', 0, 0, -5572.81689453125, -461.663787841796875, 414.200958251953125, 0.261798173189163208, 0, 0, 0.130525588989257812, 0.991444945335388183, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Kharanos - Difficulty: 0)
(@OGUID+9, 180407, 0, 1, 131, '0', 0, 0, -5477.36962890625, -459.368011474609375, 398.4930419921875, 0.837757468223571777, 0, 0, 0.406736373901367187, 0.913545548915863037, 120, 255, 1, 45745), -- G_Pumpkin_03 (Area: Kharanos - Difficulty: 0)
(@OGUID+10, 180410, 0, 1, 131, '0', 0, 0, -5600.61083984375, -519.86065673828125, 401.59832763671875, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 120, 255, 1, 45745), -- G_HangingSkeleton_01 (Area: Kharanos - Difficulty: 0)
(@OGUID+11, 180411, 0, 1, 131, '0', 0, 0, -5579.19091796875, -436.064239501953125, 402.61480712890625, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 120, 255, 1, 45745), -- G_Ghost_01 (Area: Kharanos - Difficulty: 0)
(@OGUID+12, 180415, 0, 1, 131, '0', 0, 0, -5586.52978515625, -534.69964599609375, 404.420013427734375, 3.90954136848449707, 0, 0, -0.92718315124511718, 0.37460830807685852, 120, 255, 1, 45745), -- CandleBlack01 (Area: Kharanos - Difficulty: 0)
(@OGUID+13, 180415, 0, 1, 131, '0', 0, 0, -5594.556640625, -526.07012939453125, 400.373809814453125, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 120, 255, 1, 45745), -- CandleBlack01 (Area: Kharanos - Difficulty: 0)
(@OGUID+14, 180425, 0, 1, 131, '0', 0, 0, -5586.76025390625, -534.98089599609375, 404.455078125, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 120, 255, 1, 45745), -- SkullCandle01 (Area: Kharanos - Difficulty: 0)
(@OGUID+15, 180425, 0, 1, 131, '0', 0, 0, -5601.1630859375, -525.24481201171875, 400.5550537109375, 0.174532130360603332, 0, 0, 0.087155342102050781, 0.996194720268249511, 120, 255, 1, 45745), -- SkullCandle01 (Area: Kharanos - Difficulty: 0)
(@OGUID+16, 180471, 0, 1, 131, '0', 0, 0, -5585.8818359375, -462.482635498046875, 411.03558349609375, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Kharanos - Difficulty: 0)
(@OGUID+17, 180471, 0, 1, 131, '0', 0, 0, -5572.96875, -462.4913330078125, 410.719879150390625, 6.021387100219726562, 0, 0, -0.13052558898925781, 0.991444945335388183, 120, 255, 1, 45745), -- HangingSkullLight01 (Area: Kharanos - Difficulty: 0)
(@OGUID+18, 180472, 0, 1, 131, '0', 0, 0, -5578.98974609375, -462.439239501953125, 412.27301025390625, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Kharanos - Difficulty: 0)
(@OGUID+19, 180472, 0, 1, 131, '0', 0, 0, -5605.22216796875, -531.842041015625, 402.5753173828125, 1.535889506340026855, 0, 0, 0.694658279418945312, 0.719339847564697265, 120, 255, 1, 45745), -- HangingSkullLight02 (Area: Kharanos - Difficulty: 0)
(@OGUID+20, 180523, 0, 1, 131, '0', 0, 0, -5584.79052734375, -539.92950439453125, 404.089324951171875, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 45745), -- Apple Bob (Area: Kharanos - Difficulty: 0)
(@OGUID+21, 180700, 0, 1, 131, '0', 0, 0, -5747.55810546875, -527.714599609375, 400.000579833984375, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+22, 180700, 0, 1, 131, '0', 0, 0, -5746.9794921875, -529.003662109375, 399.285064697265625, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+23, 180700, 0, 1, 131, '0', 0, 0, -5753.1630859375, -533.396240234375, 403.65386962890625, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+24, 180700, 0, 1, 131, '0', 0, 0, -5752.77197265625, -533.24114990234375, 403.9241943359375, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+25, 180700, 0, 1, 131, '0', 0, 0, -5757.09326171875, -522.66571044921875, 398.45355224609375, 0.872663915157318115, 0, 0, 0.422617912292480468, 0.906307935714721679, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+26, 180700, 0, 1, 131, '0', 0, 0, -5758.15673828125, -521.982666015625, 399.159027099609375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+27, 180700, 0, 1, 131, '0', 0, 0, -5753.9140625, -526.596435546875, 402.29656982421875, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+28, 180700, 0, 1, 131, '0', 0, 0, -5752.87939453125, -527.554931640625, 402.026458740234375, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+29, 180700, 0, 1, 131, '0', 0, 0, -5760.94287109375, -528.08416748046875, 403.882415771484375, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 45745), -- Hay Bale 1 (Area: Kharanos - Difficulty: 0)
(@OGUID+30, 186234, 0, 1, 131, '0', 0, 0, -5751.90087890625, -483.79339599609375, 396.50201416015625, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, 45745), -- Water Barrel (Area: Kharanos - Difficulty: 0)
(@OGUID+31, 186234, 0, 1, 131, '0', 0, 0, -5624.01611328125, -478.673828125, 396.980255126953125, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 45745), -- Water Barrel (Area: Kharanos - Difficulty: 0)
(@OGUID+32, 186614, 0, 1, 131, '0', 0, 0, -5622.24609375, -478.1807861328125, 396.980255126953125, 0.296705186367034912, 0, 0, 0.147809028625488281, 0.989015936851501464, 120, 255, 1, 45745), -- Water Bucket (Area: Kharanos - Difficulty: 0)
(@OGUID+33, 186614, 0, 1, 131, '0', 0, 0, -5623.4853515625, -477.085845947265625, 396.980255126953125, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 45745), -- Water Bucket (Area: Kharanos - Difficulty: 0)
(@OGUID+34, 186615, 0, 1, 131, '0', 0, 0, -5625.37158203125, -477.26605224609375, 396.862213134765625, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 120, 255, 1, 45745), -- Water Buckets (Area: Kharanos - Difficulty: 0)
(@OGUID+35, 186720, 0, 1, 131, '0', 0, 0, -5747.51708984375, -527.633544921875, 400.29693603515625, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 120, 255, 1, 45745), -- Fire Effigy (Area: Kharanos - Difficulty: 0)
(@OGUID+36, 186720, 0, 1, 131, '0', 0, 0, -5753.23779296875, -533.6519775390625, 404.02215576171875, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 120, 255, 1, 45745), -- Fire Effigy (Area: Kharanos - Difficulty: 0)
(@OGUID+37, 186720, 0, 1, 131, '0', 0, 0, -5754.20556640625, -527.0972900390625, 402.495208740234375, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, 45745), -- Fire Effigy (Area: Kharanos - Difficulty: 0)
(@OGUID+38, 186720, 0, 1, 131, '0', 0, 0, -5758.470703125, -521.98565673828125, 399.218231201171875, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 120, 255, 1, 45745), -- Fire Effigy (Area: Kharanos - Difficulty: 0)
(@OGUID+39, 186720, 0, 1, 131, '0', 0, 0, -5761.1650390625, -528.19342041015625, 403.854522705078125, 1.169368624687194824, 0, 0, 0.551936149597167968, 0.833886384963989257, 120, 255, 1, 45745), -- Fire Effigy (Area: Kharanos - Difficulty: 0)
(@OGUID+40, 190036, 0, 1, 131, '0', 0, 0, -5598.9833984375, -531.22772216796875, 399.65155029296875, 2.408554315567016601, 0, 0, 0.933580398559570312, 0.358368009328842163, 120, 255, 1, 45745); -- Candy Bucket (Area: Kharanos - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+46;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0), 
(12, @CGUID+1), 
(12, @CGUID+2), 
(12, @CGUID+3), 
(12, @CGUID+4), 
(12, @CGUID+5), 
(12, @CGUID+6), 
(12, @CGUID+7), 
(12, @CGUID+8), 
(12, @CGUID+9), 
(12, @CGUID+10),
(12, @CGUID+11),
(12, @CGUID+12),
(12, @CGUID+13),
(12, @CGUID+14),
(12, @CGUID+15),
(12, @CGUID+16),
(12, @CGUID+17),
(12, @CGUID+18),
(12, @CGUID+19),
(12, @CGUID+20),
(12, @CGUID+21),
(12, @CGUID+22),
(12, @CGUID+23),
(12, @CGUID+24),
(12, @CGUID+25),
(12, @CGUID+26),
(12, @CGUID+27),
(12, @CGUID+28),
(12, @CGUID+29),
(12, @CGUID+30),
(12, @CGUID+31),
(12, @CGUID+32),
(12, @CGUID+33),
(12, @CGUID+34),
(12, @CGUID+35),
(12, @CGUID+36),
(12, @CGUID+37),
(12, @CGUID+38),
(12, @CGUID+39),
(12, @CGUID+40),
(12, @CGUID+41),
(12, @CGUID+42),
(12, @CGUID+43),
(12, @CGUID+44),
(12, @CGUID+45),
(12, @CGUID+46);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+40;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12),
(12, @OGUID+13),
(12, @OGUID+14),
(12, @OGUID+15),
(12, @OGUID+16),
(12, @OGUID+17),
(12, @OGUID+18),
(12, @OGUID+19),
(12, @OGUID+20),
(12, @OGUID+21),
(12, @OGUID+22),
(12, @OGUID+23),
(12, @OGUID+24),
(12, @OGUID+25),
(12, @OGUID+26),
(12, @OGUID+27),
(12, @OGUID+28),
(12, @OGUID+29),
(12, @OGUID+30),
(12, @OGUID+31),
(12, @OGUID+32),
(12, @OGUID+33),
(12, @OGUID+34),
(12, @OGUID+35),
(12, @OGUID+36),
(12, @OGUID+37),
(12, @OGUID+38),
(12, @OGUID+39),
(12, @OGUID+40);
