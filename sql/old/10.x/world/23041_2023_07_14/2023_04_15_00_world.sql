SET @CGUID := 3000061;
SET @OGUID := 3001259;
SET @POOL := 5703;
SET @EVENT := 9;

-- Creature templates
UPDATE `creature_template` SET `speed_run`=0.571428596973419189, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=33556480, `unit_flags3`=524288 WHERE `entry`=130907; -- Egg
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=85773; -- Mystical Spring Bouquet
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `unit_flags`=768 WHERE `entry`=33975; -- Noblegarden Bunny
UPDATE `creature_template` SET `speed_walk`=0.400000005960464477, `unit_flags`=256, `unit_flags3`=524288 WHERE `entry`=32793; -- Baby Bunny
UPDATE `creature_template` SET `speed_run`=0.857142865657806396, `unit_flags`=768 WHERE `entry`=32791; -- Spring Rabbit
UPDATE `creature_template` SET `unit_flags`=33554432, `unit_flags3`=524288 WHERE `entry`=32784; -- Noblegarden Bunny Controller
UPDATE `creature_template` SET `unit_flags3`=524288 WHERE `entry`=32781; -- Noblegarden Rabbit

DELETE FROM `creature_template_addon` WHERE `entry` IN (130907, 85773, 33975, 32837, 32798, 32793, 32791, 32784, 32781);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(130907, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 130907 (Egg)
(85773, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 85773 (Mystical Spring Bouquet)
(33975, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 33975 (Noblegarden Bunny)
(32837, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 32837 (Noblegarden Merchant)
(32798, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 32798 (Spring Gatherer)
(32793, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 32793 (Baby Bunny)
(32791, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '61723'), -- 32791 (Spring Rabbit) - Spring Rabbit Periodic
(32784, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 32784 (Noblegarden Bunny Controller)
(32781, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 32781 (Noblegarden Rabbit)

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (130907, 85773);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(130907, 0, 0, 1, 1, 0, 0, NULL),
(85773, 0, 0, 1, 0, 0, 0, NULL);

-- Gossips
UPDATE `creature_template_gossip` SET `VerifiedBuild`=48999 WHERE (`CreatureID`=32837 AND `MenuID`=10257);

UPDATE `gossip_menu` SET `VerifiedBuild`=48999 WHERE (`MenuID`=10257 AND `TextID`=14239);

UPDATE `gossip_menu_option` SET `GossipOptionID`=37187, `VerifiedBuild`=48999 WHERE (`MenuID`=10257 AND `OptionID`=0);

-- Equipments
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID`=32837);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(32837, 1, 0, 0, 0, 45073, 0, 0, 0, 0, 0, 48966); -- Noblegarden Merchant

UPDATE `creature_equip_template` SET `VerifiedBuild`=48966 WHERE (`ID`=1 AND `CreatureID` IN (75687,75686,75685,12430,11025,9987,6928,6027,5880,3881,3706,3620,3336,3294,3175,3174,3173,3172,3171,3170,3169,3168,3167,3165,3164,3163,3142,3139));

-- Models
DELETE FROM `creature_model_info` WHERE `DisplayID`=111675;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(111675, 0.372000008821487426, 1.5, 0, 48966);

UPDATE `creature_model_info` SET `VerifiedBuild`=48966 WHERE `DisplayID` IN (101523, 1132, 100727, 81472, 66220, 84680, 61763, 59099, 49781, 31738, 31737, 9799, 9801, 9800, 9798, 1206, 42722, 42720, 46940, 36585, 36584, 7511, 35611, 33829, 32324, 1973, 32226, 31446, 1139, 28726, 28304, 28998, 28288, 29000, 6302, 4626, 328, 28118, 28120, 12477, 11901, 10570, 9262, 5705, 5730, 4728, 1560, 4611, 10171, 3755, 1897, 4296, 3884, 1986, 1654, 3751, 3748, 3747, 3746, 3745, 3744, 3749, 3743, 3741, 3742, 3740, 3739, 3737, 3738, 1877, 3736, 2487, 2486, 381);
UPDATE `creature_model_info` SET `BoundingRadius`=0.382999986410140991, `CombatReach`=1.5, `VerifiedBuild`=48966 WHERE `DisplayID`=28309;

UPDATE `creature_template_model` SET `VerifiedBuild`=48966 WHERE (`Idx`=2 AND `CreatureID` IN (3300,49743,130907,32837,99541,75685,32793,75686,26125,32781,49837)) OR (`Idx`=1 AND `CreatureID` IN (3300,32798,49743,130907,32837,99541,75687,75685,32793,75686,26125,32781,49837,32784)) OR (`Idx`=0 AND `CreatureID` IN (3300,3191,3173,3881,32798,3175,85773,62116,64993,417,62821,3142,305,3164,40625,40970,49743,3169,71486,3706,61751,59072,39323,6787,130907,32837,3166,47654,174170,11943,356,99541,3620,9987,25064,3125,3139,18379,41140,28363,3099,416,165189,68288,12430,3170,5943,14505,62822,32642,75687,3167,304,3126,3294,3336,75685,1860,32793,32641,43239,63063,175156,33975,75686,6928,5880,65011,32791,58960,89713,26125,47418,5951,3168,3163,3171,32781,40971,6027,202517,44380,35362,3165,49837,39423,180016,63061,43499,32784,3174,97285,3172,11025)) OR (`Idx`=3 AND `CreatureID` IN (49743,32837,99541,75685,75686,26125,49837));

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (202517,175156,130907,85773,33975,32837,32798,32793,32791,32784,32781));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(202517, 0, 0, 0, 1281, 48966),
(175156, 0, 0, 0, 70, 48966),
(130907, 0, 0, 0, 390, 48966),
(85773, 0, 0, 0, 371, 48966),
(33975, 0, 0, 0, 371, 48966),
(32837, 0, 0, 0, 390, 48966),
(32798, 0, 0, 0, 390, 48966),
(32793, 0, 0, 0, 390, 48966),
(32791, 0, 0, 0, 371, 48966),
(32784, 0, 0, 0, 390, 48966),
(32781, 0, 0, 0, 390, 48966);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48966 WHERE (`DifficultyID`=0 AND `Entry` IN (180016,174170,99541,97285,89713,75687,75686,75685,63063,63061,62822,62821,62116,61751,49837,49743,47418,44380,43499,41140,40971,40970,39423,39323,32642,32641,12430,11943,11025,9987,6928,6787,6027,5951,5943,5880,3881,3706,3620,3336,3300,3294,3191,3175,3174,3173,3172,3171,3170,3169,3168,3167,3166,3165,3164,3163,3142,3139,3126,3125,3099));

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=32837 AND `item`=6835 AND `ExtendedCost`=2572 AND `type`=1) OR (`entry`=32837 AND `item`=19028 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32837 AND `item`=116359 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32837 AND `item`=116358 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32837 AND `item`=116357 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32837 AND `item`=165802 AND `ExtendedCost`=6454 AND `type`=1) OR (`entry`=32837 AND `item`=204675 AND `ExtendedCost`=6131 AND `type`=1) OR (`entry`=32837 AND `item`=164924 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32837 AND `item`=164923 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32837 AND `item`=164922 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32837 AND `item`=74283 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32837 AND `item`=74282 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32837 AND `item`=72145 AND `ExtendedCost`=3689 AND `type`=1) OR (`entry`=32837 AND `item`=116258 AND `ExtendedCost`=2574 AND `type`=1) OR (`entry`=32837 AND `item`=141532 AND `ExtendedCost`=6131 AND `type`=1) OR (`entry`=32837 AND `item`=151806 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32837 AND `item`=151804 AND `ExtendedCost`=2572 AND `type`=1) OR (`entry`=32837 AND `item`=188694 AND `ExtendedCost`=2573 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32837, 24, 116359, 0, 0, 1, 0, 0, 48966), -- Magnificently-Painted Egg
(32837, 23, 116358, 0, 0, 1, 0, 0, 48966), -- Intricately-Painted Egg
(32837, 22, 116357, 0, 0, 1, 0, 0, 48966), -- Poorly-Painted Egg
(32837, 21, 165802, 0, 6454, 1, 0, 0, 48966), -- Noble Gardener's Hearthstone
(32837, 20, 204675, 0, 6131, 1, 0, 0, 48966), -- -Unknown-
(32837, 18, 164924, 0, 2573, 1, 0, 0, 48966), -- Yellow Spring Circlet
(32837, 17, 164923, 0, 2573, 1, 0, 0, 48966), -- Brown Spring Circlet
(32837, 16, 164922, 0, 2573, 1, 0, 0, 48966), -- Blue Spring Circlet
(32837, 15, 74283, 0, 2573, 1, 0, 0, 48966), -- Pink Spring Circlet
(32837, 14, 74282, 0, 2573, 1, 0, 0, 48966), -- Black Spring Circlet
(32837, 13, 72145, 0, 3689, 1, 0, 0, 48966), -- Swift Springstrider
(32837, 12, 116258, 0, 2574, 1, 0, 0, 48966), -- Mystical Spring Bouquet
(32837, 11, 141532, 0, 6131, 1, 0, 0, 48966), -- Noblegarden Bunny
(32837, 8, 151806, 0, 2573, 1, 0, 0, 48966), -- Elegant Dress
(32837, 7, 151804, 0, 2572, 1, 0, 0, 48966), -- Black Tuxedo Pants
(32837, 5, 188694, 0, 2573, 1, 0, 0, 48966); -- Spring Florist's Pouch

UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=48999 WHERE (`entry`=32837 AND `item`=44793 AND `ExtendedCost`=2574 AND `type`=1); -- Tome of Polymorph: Rabbit
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=48966 WHERE (`entry`=32837 AND `item`=44794 AND `ExtendedCost`=2574 AND `type`=1); -- Spring Rabbit's Foot
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=48966 WHERE (`entry`=32837 AND `item`=44803 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Circlet
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=48966 WHERE (`entry`=32837 AND `item`=6833 AND `ExtendedCost`=2572 AND `type`=1); -- White Tuxedo Shirt
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=48966 WHERE (`entry`=32837 AND `item`=44800 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Robes
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=48966 WHERE (`entry`=32837 AND `item`=45073 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Flowers
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=48966 WHERE (`entry`=32837 AND `item`=44792 AND `ExtendedCost`=2571 AND `type`=1); -- Blossoming Branch
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=48966 WHERE (`entry`=32837 AND `item`=44818 AND `ExtendedCost`=2575 AND `type`=1); -- Noblegarden Egg

-- Gameobject templates
UPDATE `gameobject_template` SET `VerifiedBuild`=48966 WHERE `entry` IN (31580, 272677, 221517, 1618, 221519, 203850, 31574, 3849, 18079, 106327, 31577, 186238, 207207, 174859, 3847, 3851, 106336, 194054, 221516, 190549, 143981, 106326, 18075, 31578, 31575, 3658, 31573, 21680, 55250, 51703, 3848, 3850, 221518, 31579, 278457, 50983, 3719, 18076, 149038, 31572, 375041, 106325, 106335, 51702, 191164, 203471);
UPDATE `gameobject_template` SET `type`=50, `Data1`=26884, `Data3`=0, `Data6`=300, `Data7`=0, `Data14`=61712, `Data18`=10, `Data19`=1, `Data30`=0, `VerifiedBuild`=48966 WHERE `entry`=113771; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `type`=50, `Data1`=26884, `Data3`=0, `Data6`=300, `Data7`=0, `Data14`=61712, `Data18`=10, `Data19`=1, `Data30`=0, `VerifiedBuild`=48966 WHERE `entry`=113768; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `type`=50, `Data1`=26884, `Data3`=0, `Data6`=300, `Data7`=0, `Data14`=61712, `Data18`=10, `Data19`=1, `Data30`=0, `VerifiedBuild`=48966 WHERE `entry`=113770; -- Brightly Colored Egg
UPDATE `gameobject_template` SET `type`=50, `Data1`=26884, `Data3`=0, `Data6`=300, `Data7`=0, `Data14`=61712, `Data18`=10, `Data19`=1, `Data30`=0, `VerifiedBuild`=48966 WHERE `entry`=113769; -- Brightly Colored Egg

UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry` IN (113771, 113770, 113769, 113768); -- Brightly Colored Egg

DELETE FROM `gameobject_loot_template` WHERE `Entry`=26884;
INSERT INTO `gameobject_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(26884, 45072, 0, 100, 0, 1, 0, 1, 1, 'Brightly Colored Egg - Brightly Colored Egg');

-- Quests
UPDATE `quest_poi` SET `VerifiedBuild`=48966 WHERE (`QuestID`=13479 AND `BlobIndex`=4 AND `Idx1`=8) OR (`QuestID`=13479 AND `BlobIndex`=3 AND `Idx1`=7) OR (`QuestID`=13479 AND `BlobIndex`=2 AND `Idx1`=6) OR (`QuestID`=13479 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=13479 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=13479 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=13479 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=13479 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=13479 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=13503 AND `BlobIndex`=4 AND `Idx1`=8) OR (`QuestID`=13503 AND `BlobIndex`=3 AND `Idx1`=7) OR (`QuestID`=13503 AND `BlobIndex`=2 AND `Idx1`=6) OR (`QuestID`=13503 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=13503 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=13503 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=13503 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=13503 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=13503 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=13483 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=13483 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=13483 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=13483 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=48966 WHERE (`QuestID`=13479 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13479 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=8 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13503 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=13483 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=13483 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13483 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13483 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID`=13503;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(13503, 1, 0, 0, 0, 0, 0, 0, 0, 48966); -- A Tisket, a Tasket; a Noblegarden Basket

UPDATE `quest_details` SET `VerifiedBuild`=48966 WHERE `ID`=13479;

UPDATE `quest_request_items` SET `VerifiedBuild`=48966 WHERE `ID`=13479;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=48966 WHERE `ID`=13503; -- A Tisket, a Tasket, a Noblegarden Basket

UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=48966 WHERE `ID`=13479; -- The Great Egg Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=48966 WHERE `ID`=13503; -- A Tisket, a Tasket, a Noblegarden Basket
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=48966 WHERE `ID`=13483; -- Spring Gatherers

DELETE FROM `creature_queststarter` WHERE (`id`=32798 AND `quest`=13479) OR (`id`=32837 AND `quest`=13503);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(32798, 13479, 48966), -- The Great Egg Hunt offered Spring Gatherer
(32837, 13503, 48966); -- A Tisket, a Tasket; a Noblegarden Basket offered Noblegarden Merchant

DELETE FROM `game_event_creature_quest` WHERE (`id`=32798 AND `quest`=13479) OR (`id`=32837 AND `quest`=13503);

UPDATE `creature_questender` SET `VerifiedBuild`=48966 WHERE (`id`=32798 AND `quest` IN (13479,13483)) OR (`id`=32837 AND `quest`=13503);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32798, 1, 14, 362, '0', 0, 0, 0, 0, 325.455963134765625, -4702.5595703125, 16.25337600708007812, 4.398229598999023437, 120, 0, 0, 361340, 28784, 0, 0, 0, 0, 48966), -- Spring Gatherer (Area: Razor Hill - Difficulty: 0) CreateObject1
(@CGUID+1, 32837, 1, 14, 362, '0', 0, 0, 0, 1, 332.42694091796875, -4706.69384765625, 16.10466957092285156, 4.24114990234375, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48966); -- Noblegarden Merchant (Area: Razor Hill - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113768, 1, 14, 362, '0', 0, 0, 355.270172119140625, -4747.91552734375, 11.87413978576660156, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+1, 113768, 1, 14, 362, '0', 0, 0, 334.039947509765625, -4715.2412109375, 14.46225833892822265, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+2, 113768, 1, 14, 362, '0', 0, 0, 291.97198486328125, -4769.19482421875, 11.78971004486083984, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+3, 113768, 1, 14, 362, '0', 0, 0, 283.290008544921875, -4640.93017578125, 19.03820037841796875, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+4, 113768, 1, 14, 362, '0', 0, 0, 303.12200927734375, -4648.72998046875, 18.23189926147460937, 1.396261811256408691, 0, 0, 0.642786979675292968, 0.766044974327087402, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+5, 113768, 1, 14, 362, '0', 0, 0, 334.5162353515625, -4771.11572265625, 12.6344451904296875, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+6, 113768, 1, 14, 362, '0', 0, 0, 301.93438720703125, -4870.2822265625, 10.22832775115966796, 6.178466320037841796, 0, 0, -0.05233573913574218, 0.998629570007324218, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+7, 113768, 1, 14, 362, '0', 0, 0, 346.7109375, -4851.771484375, 10.36444759368896484, 1.727874636650085449, 0, 0, 0.760405540466308593, 0.649448513984680175, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+8, 113768, 1, 14, 362, '0', 0, 0, 360.94140625, -4771.21826171875, 12.4835662841796875, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+9, 113768, 1, 14, 362, '0', 0, 0, 340.698150634765625, -4711.13916015625, 14.79842281341552734, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+10, 113768, 1, 14, 362, '0', 0, 0, 276.00299072265625, -4770.0498046875, 11.5141000747680664, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 1, 14, 362, '0', 0, 0, 337.99017333984375, -4857.97509765625, 10.31077861785888671, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+12, 113768, 1, 14, 362, '0', 0, 0, 352.032135009765625, -4839.193359375, 10.81149482727050781, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+13, 113768, 1, 14, 362, '0', 0, 0, 290.459869384765625, -4840.1337890625, 10.22612476348876953, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+14, 113768, 1, 14, 362, '0', 0, 0, 363.89556884765625, -4700.451171875, 14.53150272369384765, 3.124123096466064453, 0, 0, 0.99996185302734375, 0.008734640665352344, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+15, 113768, 1, 14, 362, '0', 0, 0, 330.67724609375, -4863.697265625, 10.59202289581298828, 3.24634718894958496, 0, 0, -0.99862861633300781, 0.052353221923112869, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+16, 113768, 1, 14, 362, '0', 0, 0, 328.954010009765625, -4769.869140625, 12.58316326141357421, 3.159062385559082031, 0, 0, -0.99996185302734375, 0.008734640665352344, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+17, 113768, 1, 14, 362, '0', 0, 0, 316.161041259765625, -4769.37451171875, 11.73401832580566406, 4.886923789978027343, 0, 0, -0.64278697967529296, 0.766044974327087402, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+18, 113768, 1, 14, 362, '0', 0, 0, 268.51910400390625, -4690.78466796875, 15.13873100280761718, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+19, 113768, 1, 14, 362, '0', 0, 0, 324.217254638671875, -4854.93896484375, 10.40522098541259765, 5.567600727081298828, 0, 0, -0.35020732879638671, 0.936672210693359375, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+20, 113768, 1, 14, 362, '0', 0, 0, 321.19964599609375, -4696.80908203125, 16.92251014709472656, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+21, 113768, 1, 14, 362, '0', 0, 0, 317.043609619140625, -4880.7587890625, 11.80964279174804687, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+22, 113768, 1, 14, 362, '0', 0, 0, 385.884429931640625, -4708.232421875, 13.39989757537841796, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+23, 113768, 1, 14, 362, '0', 0, 0, 344.142913818359375, -4778.52978515625, 12.51441574096679687, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+24, 113768, 1, 14, 362, '0', 0, 0, 323.1534423828125, -4883.08984375, 12.9871225357055664, 1.099556446075439453, 0, 0, 0.522498130798339843, 0.852640450000762939, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+25, 113768, 1, 14, 362, '0', 0, 0, 339.025177001953125, -4710.0556640625, 15.1651611328125, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+26, 113768, 1, 14, 362, '0', 0, 0, 275.167999267578125, -4773.33984375, 13.87380027770996093, 1.692969322204589843, 0, 0, 0.748955726623535156, 0.662620067596435546, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+27, 113768, 1, 14, 362, '0', 0, 0, 328.2882080078125, -4662.6181640625, 16.56503677368164062, 3.630291461944580078, 0, 0, -0.97029495239257812, 0.241925001144409179, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+28, 113768, 1, 14, 362, '0', 0, 0, 389.870025634765625, -4706.98876953125, 13.30764484405517578, 2.007128477096557617, 0, 0, 0.84339141845703125, 0.537299633026123046, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+29, 113768, 1, 14, 362, '0', 0, 0, 303.072998046875, -4646.64990234375, 17.48959922790527343, 1.902408957481384277, 0, 0, 0.814115524291992187, 0.580702960491180419, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+30, 113768, 1, 14, 362, '0', 0, 0, 306.1719970703125, -4741.7001953125, 14.6801004409790039, 2.338739633560180664, 0, 0, 0.920504570007324218, 0.3907318115234375, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+31, 113768, 1, 14, 362, '0', 0, 0, 364.1470947265625, -4755.33251953125, 12.16670894622802734, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+32, 113768, 1, 14, 362, '0', 0, 0, 332.496002197265625, -4763.7216796875, 12.64983558654785156, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+33, 113768, 1, 14, 362, '0', 0, 0, 298.308929443359375, -4846.50830078125, 10.15275859832763671, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+34, 113768, 1, 14, 362, '0', 0, 0, 336.808258056640625, -4835.126953125, 9.985502243041992187, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+35, 113768, 1, 14, 362, '0', 0, 0, 319.55029296875, -4699.10009765625, 15.94217586517333984, 4.415683269500732421, 0, 0, -0.80385684967041015, 0.594822824001312255, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+36, 113768, 1, 14, 362, '0', 0, 0, 311.713531494140625, -4860.96337890625, 10.5355844497680664, 3.141592741012573242, 0, 0, -1, 0, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+37, 113768, 1, 14, 362, '0', 0, 0, 296.473968505859375, -4784.9462890625, 10.68887805938720703, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+38, 113768, 1, 14, 362, '0', 0, 0, 293.0069580078125, -4709.486328125, 13.10925769805908203, 4.677483558654785156, 0, 0, -0.71933937072753906, 0.694658815860748291, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+39, 113768, 1, 14, 362, '0', 0, 0, 273.9288330078125, -4690.83837890625, 14.2204437255859375, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+40, 113768, 1, 14, 362, '0', 0, 0, 312.223968505859375, -4690.0380859375, 15.92078971862792968, 4.764749526977539062, 0, 0, -0.6883544921875, 0.725374460220336914, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+41, 113768, 1, 14, 362, '0', 0, 0, 322.0186767578125, -4706.11474609375, 15.05232429504394531, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+42, 113768, 1, 14, 362, '0', 0, 0, 337.672088623046875, -4791.3291015625, 11.25179100036621093, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+43, 113768, 1, 14, 362, '0', 0, 0, 335.92633056640625, -4807.642578125, 10.0479888916015625, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+44, 113768, 1, 14, 362, '0', 0, 0, 275.355987548828125, -4777.60009765625, 11.21770000457763671, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+45, 113768, 1, 14, 362, '0', 0, 0, 273.6390380859375, -4729.33349609375, 13.6144256591796875, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+46, 113768, 1, 14, 362, '0', 0, 0, 360.844512939453125, -4837.46533203125, 11.54411888122558593, 3.78736734390258789, 0, 0, -0.94832324981689453, 0.317305892705917358, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+47, 113768, 1, 14, 362, '0', 0, 0, 334.89483642578125, -4708.2578125, 15.73802661895751953, 3.961898565292358398, 0, 0, -0.91705989837646484, 0.398749500513076782, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+48, 113768, 1, 14, 362, '0', 0, 0, 369.17138671875, -4767.84912109375, 12.46781158447265625, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+49, 113768, 1, 14, 362, '0', 0, 0, 285.003173828125, -4813.873046875, 10.23443126678466796, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+50, 113768, 1, 14, 362, '0', 0, 0, 366.177093505859375, -4687.220703125, 16.71437263488769531, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+51, 113768, 1, 14, 362, '0', 0, 0, 366.759429931640625, -4720.51806640625, 13.57157516479492187, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+52, 113768, 1, 14, 362, '0', 0, 0, 365.129852294921875, -4765.50537109375, 12.51550865173339843, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+53, 113768, 1, 14, 362, '0', 0, 0, 290.7449951171875, -4649.580078125, 19.20910072326660156, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+54, 113768, 1, 14, 362, '0', 0, 0, 318.375152587890625, -4782.64404296875, 10.1410064697265625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+55, 113768, 1, 14, 362, '0', 0, 0, 355.703125, -4660.28466796875, 16.75362586975097656, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+56, 113768, 1, 14, 362, '0', 0, 0, 311.033050537109375, -4850.38427734375, 10.24135208129882812, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1
(@OGUID+57, 113768, 1, 14, 362, '0', 0, 0, 329.909454345703125, -4774.55517578125, 12.36009693145751953, 1.85004889965057373, 0, 0, 0.798635482788085937, 0.60181504487991333, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+58, 113768, 1, 14, 362, '0', 0, 0, 360.73687744140625, -4753.80712890625, 12.40971088409423828, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+59, 113768, 1, 14, 362, '0', 0, 0, 330.09954833984375, -4843.18115234375, 10.02168083190917968, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 300, 255, 1, 48966), -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject2
(@OGUID+60, 113768, 1, 14, 362, '0', 0, 0, 362.3165283203125, -4839.447265625, 11.79933643341064453, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 300, 255, 1, 48966); -- Brightly Colored Egg (Area: Razor Hill - Difficulty: 0) CreateObject1

UPDATE `pool_template` SET `description`='Noblegarden - Razor Hill - Brightly Colored Egg' WHERE `entry`=@POOL;

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(1, @OGUID+0, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+1, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+2, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+3, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+4, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+5, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+6, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+7, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+8, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+9, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+10, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+11, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+12, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+13, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+14, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+15, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+16, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+17, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+18, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+19, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+20, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+21, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+22, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+23, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+24, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+25, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+26, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+27, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+28, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+29, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+30, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+31, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+32, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+33, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+34, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+35, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+36, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+37, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+38, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+39, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+40, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+41, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+42, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+43, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+44, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+45, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+46, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+47, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+48, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+49, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+50, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+51, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+52, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+53, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+54, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+55, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+56, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+57, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+58, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+59, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+60, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);
