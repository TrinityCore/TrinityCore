SET @CGUID := 3000067;
SET @OGUID := 3001442;
SET @POOL := 5699;
SET @EVENT := 9;

-- Creature templates
DELETE FROM `creature_template_addon` WHERE `entry` IN (32836, 32799);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(32836, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 32836 (Noblegarden Vendor)
(32799, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 32799 (Spring Collector)

-- Gossips
UPDATE `creature_template_gossip` SET `VerifiedBuild`=48999 WHERE (`CreatureID`=32836 AND `MenuID`=10257);

-- Equipments
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=32836 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(32836, 1, 0, 0, 0, 45073, 0, 0, 0, 0, 0, 48999); -- Noblegarden Vendor

UPDATE `creature_equip_template` SET `VerifiedBuild`=48999 WHERE (`ID`=1 AND `CreatureID` IN (46983,6374,6306,3935,2046,1430,1423,927,917,913,906,794,514,465,377,328,241,240,151,68)) OR (`ID`=2 AND `CreatureID`=42218);

-- Models
DELETE FROM `creature_model_info` WHERE `DisplayID`=104798;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(104798, 0.338548988103866577, 0, 0, 48999);

UPDATE `creature_model_info` SET `VerifiedBuild`=48999 WHERE `DisplayID` IN (29819, 61764, 13091, 23767, 35576, 35369, 30301, 3263, 29284, 32729, 28312, 28282, 28111, 24898, 1924, 11898, 5527, 9257, 5092, 5365, 4866, 2408, 2410, 3234, 3236, 1060, 1296, 3340, 856, 857, 3335, 1293, 3258, 134, 1299, 1297, 1300, 3271, 654, 347, 221, 338, 903, 1288, 3266, 1295, 1294, 1291, 5038, 3254, 1985, 1292, 503, 1289, 99389, 1298, 1287, 366);
UPDATE `creature_model_info` SET `BoundingRadius`=0.138684809207916259, `CombatReach`=0.5, `VerifiedBuild`=48999 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=48999 WHERE `DisplayID`=28303;
UPDATE `creature_model_info` SET `BoundingRadius`=1.316326498985290527, `CombatReach`=1.096938729286193847, `VerifiedBuild`=48999 WHERE `DisplayID`=18156;

UPDATE `creature_template_model` SET `VerifiedBuild`=48999 WHERE (`Idx`=3 AND `CreatureID` IN (68,32836,13321)) OR (`Idx`=2 AND `CreatureID` IN (68,143622,32836,13321)) OR (`Idx`=1 AND `CreatureID` IN (68,143622,115141,46985,32836,1933,32799,13321,1423)) OR (`Idx`=0 AND `CreatureID` IN (68,165189,30,927,6121,795,2046,253,796,32638,906,151,11940,6749,74,42260,143622,416,115141,377,46983,42983,2442,113,46985,797,3937,514,43499,32836,89715,883,6374,299,295,241,54,66,1412,465,6778,5403,42218,6306,328,5406,54741,47384,18362,794,1933,913,1430,32799,32639,184600,13321,308,60199,63015,63014,525,1632,3935,890,917,1423,2329,46982,240));

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (183708,115141,42260,32836,32799));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183708, 0, 0, 0, 371, 48999),
(115141, 0, 0, 0, 371, 48999),
(42260, 0, 0, 0, 73, 48999),
(32836, 0, 0, 0, 390, 48999),
(32799, 0, 0, 0, 390, 48999);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48999 WHERE (`DifficultyID`=0 AND `Entry` IN (143622,89715,63015,63014,60199,47384,46985,46983,46982,43499,42983,42218,32639,32638,13321,11940,6778,6749,6374,6306,6121,5406,5403,3937,3935,2442,2329,2046,1933,1632,1430,1423,1412,927,917,913,906,890,883,797,796,795,794,525,514,465,377,328,299,295,253,241,240,151,113,74,68,66,54,30));
UPDATE `creature_template_scaling` SET `ContentTuningID`=73 WHERE (`Entry`=12922 AND `DifficultyID`=0);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=32836 AND `item`=6835 AND `ExtendedCost`=2572 AND `type`=1) OR (`entry`=32836 AND `item`=19028 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32836 AND `item`=116359 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32836 AND `item`=116358 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32836 AND `item`=116357 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=32836 AND `item`=165802 AND `ExtendedCost`=6454 AND `type`=1) OR (`entry`=32836 AND `item`=204675 AND `ExtendedCost`=6131 AND `type`=1) OR (`entry`=32836 AND `item`=164924 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32836 AND `item`=164923 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32836 AND `item`=164922 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32836 AND `item`=74283 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32836 AND `item`=74282 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32836 AND `item`=72145 AND `ExtendedCost`=3689 AND `type`=1) OR (`entry`=32836 AND `item`=116258 AND `ExtendedCost`=2574 AND `type`=1) OR (`entry`=32836 AND `item`=141532 AND `ExtendedCost`=6131 AND `type`=1) OR (`entry`=32836 AND `item`=151806 AND `ExtendedCost`=2573 AND `type`=1) OR (`entry`=32836 AND `item`=151804 AND `ExtendedCost`=2572 AND `type`=1) OR (`entry`=32836 AND `item`=188694 AND `ExtendedCost`=2573 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(32836, 24, 116359, 0, 0, 1, 0, 0, 48999), -- Magnificently-Painted Egg
(32836, 23, 116358, 0, 0, 1, 0, 0, 48999), -- Intricately-Painted Egg
(32836, 22, 116357, 0, 0, 1, 0, 0, 48999), -- Poorly-Painted Egg
(32836, 21, 165802, 0, 6454, 1, 0, 0, 48999), -- Noble Gardener's Hearthstone
(32836, 20, 204675, 0, 6131, 1, 0, 0, 48999), -- -Unknown-
(32836, 18, 164924, 0, 2573, 1, 0, 0, 48999), -- Yellow Spring Circlet
(32836, 17, 164923, 0, 2573, 1, 0, 0, 48999), -- Brown Spring Circlet
(32836, 16, 164922, 0, 2573, 1, 0, 0, 48999), -- Blue Spring Circlet
(32836, 15, 74283, 0, 2573, 1, 0, 0, 48999), -- Pink Spring Circlet
(32836, 14, 74282, 0, 2573, 1, 0, 0, 48999), -- Black Spring Circlet
(32836, 13, 72145, 0, 3689, 1, 0, 0, 48999), -- Swift Springstrider
(32836, 12, 116258, 0, 2574, 1, 0, 0, 48999), -- Mystical Spring Bouquet
(32836, 11, 141532, 0, 6131, 1, 0, 0, 48999), -- Noblegarden Bunny
(32836, 8, 151806, 0, 2573, 1, 0, 0, 48999), -- Elegant Dress
(32836, 7, 151804, 0, 2572, 1, 0, 0, 48999), -- Black Tuxedo Pants
(32836, 5, 188694, 0, 2573, 1, 0, 0, 48999); -- Spring Florist's Pouch

UPDATE `npc_vendor` SET `slot`=19, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=44793 AND `ExtendedCost`=2574 AND `type`=1); -- Tome of Polymorph: Rabbit
UPDATE `npc_vendor` SET `slot`=10, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=44794 AND `ExtendedCost`=2574 AND `type`=1); -- Spring Rabbit's Foot
UPDATE `npc_vendor` SET `slot`=9, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=44803 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Circlet
UPDATE `npc_vendor` SET `slot`=6, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=6833 AND `ExtendedCost`=2572 AND `type`=1); -- White Tuxedo Shirt
UPDATE `npc_vendor` SET `slot`=4, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=44800 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Robes
UPDATE `npc_vendor` SET `slot`=3, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=45073 AND `ExtendedCost`=2573 AND `type`=1); -- Spring Flowers
UPDATE `npc_vendor` SET `slot`=2, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=44792 AND `ExtendedCost`=2571 AND `type`=1); -- Blossoming Branch
UPDATE `npc_vendor` SET `slot`=1, `VerifiedBuild`=48999 WHERE (`entry`=32836 AND `item`=44818 AND `ExtendedCost`=2575 AND `type`=1); -- Noblegarden Egg

-- Quests
UPDATE `quest_poi` SET `VerifiedBuild`=48999 WHERE (`QuestID`=13502 AND `BlobIndex`=3 AND `Idx1`=7) OR (`QuestID`=13502 AND `BlobIndex`=2 AND `Idx1`=6) OR (`QuestID`=13502 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=13502 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=13502 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=13502 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=13502 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=13502 AND `BlobIndex`=0 AND `Idx1`=0) OR (`QuestID`=13480 AND `BlobIndex`=3 AND `Idx1`=7) OR (`QuestID`=13480 AND `BlobIndex`=2 AND `Idx1`=6) OR (`QuestID`=13480 AND `BlobIndex`=1 AND `Idx1`=5) OR (`QuestID`=13480 AND `BlobIndex`=0 AND `Idx1`=4) OR (`QuestID`=13480 AND `BlobIndex`=3 AND `Idx1`=3) OR (`QuestID`=13480 AND `BlobIndex`=2 AND `Idx1`=2) OR (`QuestID`=13480 AND `BlobIndex`=1 AND `Idx1`=1) OR (`QuestID`=13480 AND `BlobIndex`=0 AND `Idx1`=0);

UPDATE `quest_poi_points` SET `VerifiedBuild`=48999 WHERE (`QuestID`=13502 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=13502 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=13502 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=13502 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=13502 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=13502 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13502 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13502 AND `Idx1`=0 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=7 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=6 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=5 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=4 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=13480 AND `Idx1`=0 AND `Idx2`=0);

DELETE FROM `quest_details` WHERE `ID` IN (13502 /*A Tisket, a Tasket, a Noblegarden Basket*/, 13480 /*The Great Egg Hunt*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(13502, 1, 0, 0, 0, 0, 0, 0, 0, 48999), -- A Tisket, a Tasket, a Noblegarden Basket
(13480, 0, 0, 0, 0, 0, 0, 0, 0, 48999); -- The Great Egg Hunt

UPDATE `quest_request_items` SET `VerifiedBuild`=48999 WHERE `ID`=13480;
UPDATE `quest_request_items` SET `EmoteOnComplete`=6, `EmoteOnIncomplete`=6, `VerifiedBuild`=48999 WHERE `ID`=13502; -- A Tisket, a Tasket, a Noblegarden Basket

UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=48999 WHERE `ID`=13480; -- The Great Egg Hunt
UPDATE `quest_offer_reward` SET `Emote1`=1, `VerifiedBuild`=48999 WHERE `ID`=13502; -- A Tisket, a Tasket, a Noblegarden Basket

DELETE FROM `creature_queststarter` WHERE (`id`=32836 AND `quest`=13502) OR (`id`=32799 AND `quest`=13480);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(32836, 13502, 48999), -- A Tisket, a Tasket, a Noblegarden Basket offered Noblegarden Vendor
(32799, 13480, 48999); -- The Great Egg Hunt offered Spring Collector

DELETE FROM `game_event_creature_quest` WHERE (`id`=32836 AND `quest`=13502) OR (`id`=32799 AND `quest`=13480);

UPDATE `creature_questender` SET `VerifiedBuild`=48999 WHERE (`id`=32799 AND `quest`=13480) OR (`id`=32836 AND `quest`=13502);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32799, 0, 12, 87, '0', 0, 0, 0, 0, -9453.4013671875, 43.5556640625, 56.9488983154296875, 0.820304751396179199, 120, 0, 0, 361340, 28784, 0, 0, 0, 0, 48999), -- Spring Collector (Area: Goldshire - Difficulty: 0) CreateObject1
(@CGUID+1, 32836, 0, 12, 87, '0', 0, 0, 0, 1, -9451.5791015625, 41.67638015747070312, 57.13817596435546875, 0.698131680488586425, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999); -- Noblegarden Vendor (Area: Goldshire - Difficulty: 0) CreateObject1

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+59;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113768, 0, 12, 87, '0', 0, 0, -9427.1923828125, 91.4727935791015625, 61.21803665161132812, 4.939284324645996093, 0, 0, -0.6225137710571289, 0.78260880708694458, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+1, 113768, 0, 12, 87, '0', 0, 0, -9464.0654296875, 81.3900299072265625, 57.09015655517578125, 2.67034769058227539, 0, 0, 0.972369194030761718, 0.233448356389999389, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+2, 113768, 0, 12, 87, '0', 0, 0, -9455.0009765625, 39.21593093872070312, 56.560028076171875, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+3, 113768, 0, 12, 87, '0', 0, 0, -9438.0205078125, 39.95573043823242187, 61.09588623046875, 5.515241622924804687, 0, 0, -0.37460613250732421, 0.927184045314788818, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+4, 113768, 0, 12, 87, '0', 0, 0, -9457.9970703125, 153.0222930908203125, 55.9447174072265625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+5, 113768, 0, 12, 87, '0', 0, 0, -9481.8125, 19.87120246887207031, 56.71354293823242187, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+6, 113768, 0, 12, 87, '0', 0, 0, -9476.4013671875, 7.092448234558105468, 56.79965972900390625, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+7, 113768, 0, 12, 87, '0', 0, 0, -9499.2626953125, 18.69297981262207031, 57.23841094970703125, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+8, 113768, 0, 12, 87, '0', 0, 0, -9426.9453125, 114.7942733764648437, 58.42198944091796875, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+9, 113768, 0, 12, 87, '0', 0, 0, -9480.4248046875, 32.35883331298828125, 56.87048721313476562, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+10, 113768, 0, 12, 87, '0', 0, 0, -9455.3583984375, 81.647705078125, 56.94331741333007812, 6.14356088638305664, 0, 0, -0.06975555419921875, 0.997564136981964111, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 0, 12, 87, '0', 0, 0, -9440.6845703125, 147.3583221435546875, 55.94527435302734375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+12, 113768, 0, 12, 87, '0', 0, 0, -9475.3212890625, 5.740613937377929687, 56.799102783203125, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+13, 113768, 0, 12, 87, '0', 0, 0, -9504.1220703125, 67.5321197509765625, 56.66607666015625, 5.166176319122314453, 0, 0, -0.52991867065429687, 0.84804844856262207, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+14, 113768, 0, 12, 87, '0', 0, 0, -9474.0048828125, 119.0806198120117187, 61.16604995727539062, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+15, 113768, 0, 12, 87, '0', 0, 0, -9481.19140625, 25.92350196838378906, 56.667816162109375, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+16, 113768, 0, 12, 87, '0', 0, 0, -9456.140625, 45.11393356323242187, 56.59143829345703125, 1.448621988296508789, 0, 0, 0.662619590759277343, 0.748956084251403808, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+17, 113768, 0, 12, 87, '0', 0, 0, -9484.3369140625, 45.25434112548828125, 57.34398269653320312, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+18, 113768, 0, 12, 87, '0', 0, 0, -9455.783203125, 14.86138153076171875, 61.39904022216796875, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+19, 113768, 0, 12, 87, '0', 0, 0, -9425.24609375, 56.1703033447265625, 57.14700698852539062, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+20, 113768, 0, 12, 87, '0', 0, 0, -9447.38671875, 121.5978775024414062, 58.34397506713867187, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+21, 113768, 0, 12, 87, '0', 0, 0, -9479.3603515625, 25.92648696899414062, 60.92392349243164062, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+22, 113768, 0, 12, 87, '0', 0, 0, -9418.30078125, 50.16276168823242187, 57.67116165161132812, 0.383971005678176879, 0, 0, 0.190808296203613281, 0.981627285480499267, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+23, 113768, 0, 12, 87, '0', 0, 0, -9473.6669921875, 41.13194656372070312, 58.04854202270507812, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+24, 113768, 0, 12, 87, '0', 0, 0, -9456.5126953125, -6.74994611740112304, 56.52862167358398437, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+25, 113768, 0, 12, 87, '0', 0, 0, -9470.6708984375, -9.53401660919189453, 56.47237014770507812, 2.687806606292724609, 0, 0, 0.974370002746582031, 0.224951311945915222, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+26, 113768, 0, 12, 87, '0', 0, 0, -9475.91015625, 82.3177032470703125, 57.33209991455078125, 5.532694816589355468, 0, 0, -0.3665008544921875, 0.93041771650314331, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+27, 113768, 0, 12, 87, '0', 0, 0, -9464.390625, 40.13606643676757812, 56.57317733764648437, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+28, 113768, 0, 12, 87, '0', 0, 0, -9464.6533203125, 42.49153518676757812, 56.67975234985351562, 1.972219824790954589, 0, 0, 0.83388519287109375, 0.55193793773651123, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+29, 113768, 0, 12, 87, '0', 0, 0, -9479.4765625, 10.19829654693603515, 56.53090286254882812, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+30, 113768, 0, 12, 87, '0', 0, 0, -9413.67578125, 102.2490768432617187, 58.97899627685546875, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+31, 113768, 0, 12, 87, '0', 0, 0, -9498.7939453125, 93.2223052978515625, 57.46051025390625, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+32, 113768, 0, 12, 87, '0', 0, 0, -9497.642578125, 83.65937042236328125, 57.02725601196289062, 4.729844093322753906, 0, 0, -0.70090866088867187, 0.713251054286956787, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+33, 113768, 0, 12, 87, '0', 0, 0, -9478.8818359375, 39.21875, 56.77740859985351562, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+34, 113768, 0, 12, 87, '0', 0, 0, -9460.0244140625, -10.7960071563720703, 56.4792022705078125, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+35, 113768, 0, 12, 87, '0', 0, 0, -9473.4365234375, -4.50596809387207031, 56.47398757934570312, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+36, 113768, 0, 12, 87, '0', 0, 0, -9452.013671875, 35.95703125, 56.557098388671875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+37, 113768, 0, 12, 87, '0', 0, 0, -9424.7890625, 63.39501953125, 57.61668014526367187, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+38, 113768, 0, 12, 87, '0', 0, 0, -9482.205078125, 13.31000423431396484, 56.59750747680664062, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+39, 113768, 0, 12, 87, '0', 0, 0, -9471.685546875, 9.245442390441894531, 56.46634292602539062, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+40, 113768, 0, 12, 87, '0', 0, 0, -9454.0849609375, 77.8565521240234375, 57.1008453369140625, 4.345870018005371093, 0, 0, -0.82412624359130859, 0.566406130790710449, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+41, 113768, 0, 12, 87, '0', 0, 0, -9475.6298828125, 41.67426300048828125, 56.55297088623046875, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+42, 113768, 0, 12, 87, '0', 0, 0, -9500.7216796875, 61.15163803100585937, 60.55394363403320312, 1.361356139183044433, 0, 0, 0.629320144653320312, 0.77714616060256958, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+43, 113768, 0, 12, 87, '0', 0, 0, -9450.4365234375, 85.74774932861328125, 56.887786865234375, 3.420850038528442382, 0, 0, -0.99026775360107421, 0.139175355434417724, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+44, 113768, 0, 12, 87, '0', 0, 0, -9454.0048828125, 18.51627540588378906, 56.52930831909179687, 4.031712055206298828, 0, 0, -0.90258502960205078, 0.430511653423309326, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+45, 113768, 0, 12, 87, '0', 0, 0, -9462.0380859375, 126.9747161865234375, 58.97404098510742187, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+46, 113768, 0, 12, 87, '0', 0, 0, -9471.2060546875, 43.40961456298828125, 56.56018829345703125, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+47, 113768, 0, 12, 87, '0', 0, 0, -9473.2080078125, 77.1795806884765625, 57.27287673950195312, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+48, 113768, 0, 12, 87, '0', 0, 0, -9463.6669921875, 144.8678436279296875, 57.6059112548828125, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+49, 113768, 0, 12, 87, '0', 0, 0, -9435.9736328125, 148.226837158203125, 56.1290740966796875, 2.513273954391479492, 0, 0, 0.951056480407714843, 0.309017121791839599, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+50, 113768, 0, 12, 87, '0', 0, 0, -9501.3310546875, 77.87619781494140625, 57.33635330200195312, 0, 0, 0, 0, 1, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+51, 113768, 0, 12, 87, '0', 0, 0, -9437.6044921875, 39.91292190551757812, 57.04927444458007812, 0.314158439636230468, 0, 0, 0.156434059143066406, 0.987688362598419189, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+52, 113768, 0, 12, 87, '0', 0, 0, -9423.0029296875, 109.6742095947265625, 58.81770706176757812, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+53, 113768, 0, 12, 87, '0', 0, 0, -9417.96484375, 114.415283203125, 59.97459793090820312, 1.151916384696960449, 0, 0, 0.544638633728027343, 0.838670849800109863, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+54, 113768, 0, 12, 87, '0', 0, 0, -9437.6552734375, 113.321533203125, 57.51654052734375, 5.916667938232421875, 0, 0, -0.18223476409912109, 0.98325502872467041, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+55, 113768, 0, 12, 87, '0', 0, 0, -9459.9599609375, 106.1653671264648437, 57.489990234375, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+56, 113768, 0, 12, 87, '0', 0, 0, -9453.1181640625, 27.43283462524414062, 56.52930831909179687, 4.363324165344238281, 0, 0, -0.81915187835693359, 0.573576688766479492, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+57, 113768, 0, 12, 87, '0', 0, 0, -9477.541015625, 52.1982421875, 61.03461456298828125, 5.95157480239868164, 0, 0, -0.16504669189453125, 0.986285746097564697, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject1
(@OGUID+58, 113768, 0, 12, 87, '0', 0, 0, -9470.9482421875, 44.38764190673828125, 56.50810623168945312, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2
(@OGUID+59, 113768, 0, 12, 87, '0', 0, 0, -9430.13671875, 63.52734375, 56.78419876098632812, 3.019413232803344726, 0, 0, 0.998134613037109375, 0.061051756143569946, 300, 255, 1, 48999); -- Brightly Colored Egg (Area: Goldshire - Difficulty: 0) CreateObject2

UPDATE `pool_template` SET `description`='Noblegarden - Goldshire - Brightly Colored Egg' WHERE `entry`=@POOL;

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+59;
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
(1, @OGUID+59, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);
