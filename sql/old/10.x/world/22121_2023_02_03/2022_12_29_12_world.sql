SET @CGUID := 1251118;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+29;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1018.0103759765625, 5159.01318359375, 27.5674285888671875, 4.0232086181640625, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+1, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1186.3853759765625, 5093.6005859375, 19.22164344787597656, 3.752039194107055664, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+2, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1284.123291015625, 5170.556640625, 22.89354705810546875, 4.524219989776611328, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+3, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1048.173583984375, 5111.6337890625, 24.9290008544921875, 3.655796289443969726, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+4, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1093.1197509765625, 5160.69091796875, 24.35462188720703125, 0, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+5, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1172.4774169921875, 5200.5322265625, 26.44371986389160156, 0.697422206401824951, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+6, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1249.7066650390625, 5128.33056640625, 26.68115615844726562, 5.573595523834228515, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+7, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1250.751708984375, 5179.875, 26.53284454345703125, 3.752038955688476562, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+8, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1304.0208740234375, 5114.77978515625, 10.06836223602294921, 6.050899982452392578, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+9, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1343.451416015625, 5179.37158203125, 11.70077800750732421, 3.431823492050170898, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+10, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1355.1441650390625, 5140.1787109375, 0.312387824058532714, 1.385220885276794433, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+11, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1400.7117919921875, 5184.150390625, 1.698825955390930175, 2.442755699157714843, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+12, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1080.98095703125, 5016.96533203125, 4.713837146759033203, 0.507442414760589599, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+13, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1037.4774169921875, 5049.462890625, 13.53896808624267578, 3.389827966690063476, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+14, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -1045.720458984375, 4962.9462890625, 0.130689084529876708, 4.118122100830078125, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+15, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -990.09375, 5047.822265625, 3.962612628936767578, 0.597186148166656494, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+16, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -973.732666015625, 5151.8525390625, 29.33787155151367187, 1.742122769355773925, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+17, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -935.26910400390625, 5104.150390625, 3.954495191574096679, 2.729682683944702148, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+18, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -900.4600830078125, 5127.265625, 4.815399646759033203, 5.432677268981933593, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+19, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -934.8194580078125, 5166.54541015625, 22.9687347412109375, 5.69853067398071289, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+20, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -983.85589599609375, 5197.390625, 29.5055389404296875, 1.156187891960144042, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+21, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -887.5382080078125, 5181.05029296875, 20.03584671020507812, 1.705313086509704589, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+22, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -906.65802001953125, 5201.84814453125, 23.18822288513183593, 2.605974912643432617, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+23, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -840.69964599609375, 5145.18505859375, 3.693361759185791015, 0.027358120307326316, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+24, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -784.3055419921875, 5173.62353515625, 1.812939882278442382, 2.341206312179565429, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+25, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -908.3350830078125, 5241.09130859375, 26.73818206787109375, 5.453258514404296875, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+26, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -851.8507080078125, 5263.353515625, 23.39945602416992187, 1.406502127647399902, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+27, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -786.01910400390625, 5277.8203125, 5.810230255126953125, 0.3047066330909729, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+28, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -784.3055419921875, 5303.27001953125, 5.131944656372070312, 4.987233638763427734, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213), -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)
(@CGUID+29, 189870, 2444, 13645, 13921, '0', 18612, 0, 0, 0, -843.7899169921875, 5315.4365234375, 12.92424201965332031, 2.392990827560424804, 120, 0, 0, 53729, 2790, 0, 0, 0, 0, 47213); -- Suspicious Permafrost (Area: Ancient Bough - Difficulty: 0) (Auras: 374005 - Frozen)

DELETE FROM `creature_template_addon` WHERE `entry` = 189870;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(189870, 0, 0, 0, 1, 0, 0, 0, 0, 0, '374005'); -- 189870 (Suspicious Permafrost) - Frozen

UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=65, `faction`=14, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=18432, `unit_flags3`=16777216 WHERE `entry`=189870; -- Suspicious Permafrost

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=189870 AND `spell_id`=374011;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(189870, 374011, 0, 0);

DELETE FROM `creature_model_info` WHERE `DisplayID` = 107018;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(107018, 1, 7, 0, 47213);

-- Quest
DELETE FROM `quest_offer_reward` WHERE `ID` = 66395;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(66395, 0, 0, 0, 0, 0, 0, 0, 0, 'I knew there had to be something there. And to think, they were so close to the portal. Now I can contemplate... other things.\n\nWhile you were hunting, Rymek and I had a lovely conversation. He\'s quite undrstanding and sympathetic. In a way, he reminds me of Solethus...\n\nHe asked if he could see the portal to the Emerald Dream with his own eyes. I see no reason why not, especially since you\'ve cleared those spiders away. I\'m sure he\'ll be quite impressed.', 47213); -- The Chittering Rocks

DELETE FROM `quest_details` WHERE `ID` = 66395;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(66395, 0, 0, 0, 0, 0, 0, 0, 0, 47213); -- The Chittering Rocks

DELETE FROM `creature_queststarter` WHERE (`id`=186469 AND `quest`=66395);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(186469, 66395, 47213); -- The Chittering Rocks offered Somnikus

DELETE FROM `creature_questender` WHERE (`id`=186469 AND `quest`=66395);
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(186469, 66395, 47213); -- The Chittering Rocks ended by Somnikus

DELETE FROM `quest_poi` WHERE (`QuestID`=66395 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=66395 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=66395 AND `BlobIndex`=0 AND `Idx1`=0);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `NavigationPlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(66395, 0, 2, 32, 0, 0, 2444, 2023, 0, 0, 0, 0, 0, 2196534, 0, 47213), -- The Chittering Rocks
(66395, 0, 1, 0, 427346, 188360, 2444, 2023, 0, 2, 0, 0, 0, 0, 0, 47213), -- The Chittering Rocks
(66395, 0, 0, -1, 0, 0, 2444, 2023, 0, 0, 0, 0, 0, 2196534, 0, 47213); -- The Chittering Rocks

DELETE FROM `quest_poi_points` WHERE (`QuestID`=66395 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=11) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=10) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=9) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=8) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=7) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=6) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=5) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=4) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=3) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=2) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=1) OR (`QuestID`=66395 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=66395 AND `Idx1`=0 AND `Idx2`=0);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(66395, 2, 0, -1156, 5157, 21, 47213), -- The Chittering Rocks
(66395, 1, 11, -1300, 5041, 21, 47213), -- The Chittering Rocks
(66395, 1, 10, -1370, 5106, 21, 47213), -- The Chittering Rocks
(66395, 1, 9, -1414, 5161, 21, 47213), -- The Chittering Rocks
(66395, 1, 8, -1398, 5226, 21, 47213), -- The Chittering Rocks
(66395, 1, 7, -1044, 5204, 21, 47213), -- The Chittering Rocks
(66395, 1, 6, -929, 5269, 21, 47213), -- The Chittering Rocks
(66395, 1, 5, -793, 5335, 21, 47213), -- The Chittering Rocks
(66395, 1, 4, -717, 5291, 21, 47213), -- The Chittering Rocks
(66395, 1, 3, -744, 5204, 21, 47213), -- The Chittering Rocks
(66395, 1, 2, -886, 5079, 21, 47213), -- The Chittering Rocks
(66395, 1, 1, -984, 5019, 21, 47213), -- The Chittering Rocks
(66395, 1, 0, -1147, 4986, 21, 47213), -- The Chittering Rocks
(66395, 0, 0, -1156, 5157, 21, 47213); -- The Chittering Rocks

DELETE FROM `quest_details` WHERE `ID` = 66395;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(66395, 0, 0, 0, 0, 0, 0, 0, 0, 47213); -- The Chittering Rocks

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 18612;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(18612, 'Cosmetic - See Suspicious Permafrost at Ancient Bough');

DELETE FROM `phase_area` WHERE `AreaId` = 13921 AND `PhaseId` = 18612;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(13921, 18612, 'See Suspicious Permafrost at Ancient Bough');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 18612 AND `SourceEntry` = 13921;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 18612, 13921, 0, 0, 47, 0, 66393, 2 | 64, 0, 0, 'Apply Phase 18612 if Quest 66393 is completed | rewarded'),
(26, 18612, 13921, 0, 0, 47, 0, 66395, 2 | 64, 0, 1, 'Apply Phase 18612 if Quest 66395 is not completed | rewarded');
