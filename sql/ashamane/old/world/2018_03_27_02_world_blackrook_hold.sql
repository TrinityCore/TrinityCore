
SET @CGUID := 21011625;
SET @OGUID := 21002362;

UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10200;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10185;
UPDATE `areatrigger_template` SET `Type`=3, `Data0`=0, `Data1`=0, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0, `VerifiedBuild`=26124 WHERE `Id`=0;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10133;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=12428;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11808;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10403;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=10067;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=3153;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=9899;
UPDATE `areatrigger_template` SET `VerifiedBuild`=26124 WHERE `Id`=11813;

DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=5498 AND `AreaTriggerId`=10200) OR (`SpellMiscId`=5478 AND `AreaTriggerId`=10185) OR (`SpellMiscId`=8234 AND `AreaTriggerId`=12428) OR (`SpellMiscId`=7360 AND `AreaTriggerId`=11808) OR (`SpellMiscId`=5695 AND `AreaTriggerId`=10403) OR (`SpellMiscId`=5352 AND `AreaTriggerId`=10067) OR (`SpellMiscId`=5167 AND `AreaTriggerId`=9899);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(5498, 10200, 0, 0, 0, 0, 0, 0, 0, 26124), -- SpellId : 199092
(5478, 10185, 0, 0, 0, 0, 0, 0, 30000, 26124), -- SpellId : 198782
(8234, 12428, 0, 0, 0, 0, 0, 0, 0, 26124), -- SpellId : 222378
(7360, 11808, 0, 0, 0, 0, 0, 0, 6000, 26124), -- SpellId : 215296
(5695, 10403, 0, 0, 0, 0, 0, 0, 8000, 26124), -- SpellId : 201063
(5352, 10067, 0, 0, 0, 0, 0, 0, 30000, 26124), -- SpellId : 197484
(5167, 9899, 0, 0, 0, 0, 0, 1510, 30000, 26124); -- SpellId : 195254

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=9000, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4366 AND `AreaTriggerId`=9110); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6609, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=337 AND `AreaTriggerId`=3153); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=26124 WHERE (`SpellMiscId`=7349 AND `AreaTriggerId`=11813); -- SpellId : 0
DELETE FROM `conversation_actors` WHERE (`ConversationId`=3625 AND `Idx`=257) OR (`ConversationId`=3625 AND `Idx`=1) OR (`ConversationId`=3625 AND `Idx`=0) OR (`ConversationId`=1403 AND `ConversationActorId`=50605 AND `Idx`=0) OR (`ConversationId`=3823 AND `ConversationActorId`=50312 AND `Idx`=1) OR (`ConversationId`=3823 AND `ConversationActorId`=50605 AND `Idx`=0) OR (`ConversationId`=916 AND `Idx`=256) OR (`ConversationId`=916 AND `Idx`=257) OR (`ConversationId`=916 AND `Idx`=0) OR (`ConversationId`=916 AND `Idx`=1) OR (`ConversationId`=1404 AND `ConversationActorId`=50642 AND `Idx`=1) OR (`ConversationId`=1404 AND `ConversationActorId`=50605 AND `Idx`=0) OR (`ConversationId`=754 AND `Idx`=258) OR (`ConversationId`=754 AND `Idx`=257) OR (`ConversationId`=754 AND `Idx`=256) OR (`ConversationId`=754 AND `Idx`=2) OR (`ConversationId`=754 AND `Idx`=1) OR (`ConversationId`=754 AND `Idx`=0);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
-- (3625, 0, 257, 26124), -- Full: 0x203AECBBA062AF800022D8000074AFDF Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 101054 (Soul of Ravencrest) Low: 7647199
-- (3625, 0, 1, 26124), -- Full: 0x203AECBBA062AF800022D8000074AFDF Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 101054 (Soul of Ravencrest) Low: 7647199
-- (3625, 0, 0, 26124), -- Full: 0x203AECBBA060A6800022D8000074AC8C Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 98970 (Latosius) Low: 7646348
(1403, 50605, 0, 26124),
(3823, 50312, 1, 26124),
(3823, 50605, 0, 26124),
-- (916, 0, 256, 26124), -- Full: 0x203AECBBA060A6800022D8000074AC8C Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 98970 (Latosius) Low: 7646348
-- (916, 0, 257, 26124), -- Full: 0x0
-- (916, 0, 0, 26124), -- Full: 0x203AECBBA060A6800022D8000074AC8C Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 98970 (Latosius) Low: 7646348
-- (916, 0, 1, 26124), -- Full: 0x0
(1404, 50642, 1, 26124),
(1404, 50605, 0, 26124);
-- (754, 0, 258, 26124), -- Full: 0x203AECBBA06184400022D8000074AD38 Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 99857 (Lord Etheldrin Ravencrest) Low: 7646520
-- (754, 0, 257, 26124), -- Full: 0x203AECBBA06184800022D8000074AD38 Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 99858 (Lady Velandras Ravencrest) Low: 7646520
-- (754, 0, 256, 26124), -- Full: 0x203AECBBA06118800022D8000074AD38 Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 99426 (Staellis Rivermoor) Low: 7646520
-- (754, 0, 2, 26124), -- Full: 0x203AECBBA06184400022D8000074AD38 Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 99857 (Lord Etheldrin Ravencrest) Low: 7646520
-- (754, 0, 1, 26124), -- Full: 0x203AECBBA06184800022D8000074AD38 Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 99858 (Lady Velandras Ravencrest) Low: 7646520
-- (754, 0, 0, 26124); -- Full: 0x203AECBBA06118800022D8000074AD38 Creature/0 R3771/S8920 Map: Bastion du Freux Entry: 99426 (Staellis Rivermoor) Low: 7646520


DELETE FROM `conversation_actor_template` WHERE `Id` IN (50605, 50312, 50642);
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(50605, 98970, 66032, 26124),
(50312, 98696, 65951, 26124),
(50642, 98965, 66853, 26124);


DELETE FROM `conversation_line_template` WHERE `Id` IN (8127, 8126, 8125, 8123, 8122, 3198, 8599, 8598, 8597, 8596, 8757, 2281, 2280, 2279, 2278, 2277, 2276, 2275, 2274, 2273, 3200, 3199, 3190, 3189, 3188, 1792, 1791, 1790);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(8127, 29864, 3588584756, 257, 0, 26124),
(8126, 16318, 3588584756, 257, 0, 26124),
(8125, 11549, 3588584756, 1, 0, 26124),
(8123, 2932, 3588584756, 1, 0, 26124),
(8122, 0, 3588584756, 0, 0, 26124),
(3198, 0, 99, 0, 0, 26124),
(8599, 14493, 583, 1, 0, 26124),
(8598, 10035, 583, 1, 0, 26124),
(8597, 5856, 99, 0, 0, 26124),
(8596, 0, 99, 0, 0, 26124),
(8757, 39798, 0, 256, 0, 26124),
(2281, 34568, 0, 257, 0, 26124),
(2280, 30270, 0, 0, 0, 26124),
(2279, 27534, 0, 1, 0, 26124),
(2278, 21917, 0, 1, 0, 26124),
(2277, 18399, 0, 1, 0, 26124),
(2276, 15147, 0, 1, 0, 26124),
(2275, 12956, 0, 0, 0, 26124),
(2274, 2556, 0, 0, 8250, 26124),
(2273, 0, 0, 256, 0, 26124),
(3200, 1917, 98, 1, 0, 26124),
(3199, 0, 99, 0, 0, 26124),
(3190, 14941, 0, 258, 0, 26124),
(3189, 14941, 0, 257, 0, 26124),
(3188, 14941, 0, 256, 0, 26124),
(1792, 9907, 0, 2, 0, 26124),
(1791, 4594, 0, 1, 0, 26124),
(1790, 0, 0, 0, 0, 26124);


DELETE FROM `conversation_template` WHERE `Id` IN (3625, 916, 1404, 1403, 3823, 754);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(3625, 8122, 29864, 26124),
(916, 2273, 39798, 26124),
(1404, 3199, 5632, 26124),
(1403, 3198, 3132, 26124),
(3823, 8596, 22591, 26124),
(754, 1790, 14941, 26124);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (252266 /*Delayeth's Journal: The Jewels of the Isles*/, 252878 /*The Age of Galakrond*/, 247498 /*Black Rook Hold Dungeon - Boss 4 - Door*/, 247401 /*Black Rook Hold Dungeon - Boss 2 - Door 2*/, 247400 /*Black Rook Hold Dungeon - Boss 2 - Door 3*/, 247399 /*Black Rook Hold Dungeon - Boss 2 - Door 1*/, 245080 /*Doodad_7NE_Blackrook_Portcullis002*/, 245079 /*Doodad_7NE_Blackrook_Portcullis001*/, 253921 /*Rusty Gate*/, 247405 /*Black Rook Hold Dungeon - Boss 1 - Door 3*/, 247404 /*Black Rook Hold Dungeon - Boss 1 - Door 2*/, 247407 /*Black Rook Hold Dungeon - Boss 1 - Post Boss Door*/, 247406 /*Black Rook Hold Dungeon - Boss 1 - Door 4*/, 247403 /*Black Rook Hold Dungeon - Boss 1 - Door 1*/, 247402 /*Black Rook Hold Dungeon - Boss 3 - Door*/, 245105 /*Doodad_7NE_Blackrook_Portcullis003*/, 245104 /*Black Rook Hold Dungeon - Boss 3 Post Door*/, 252328 /*Blackrook Hold Dungeon - Entrance - Right Door*/, 252327 /*Blackrook Hold Dungeon - Entrance - Left Door*/, 250576 /*Powerful Mana Gem*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(252266, 0, 4), -- Delayeth's Journal: The Jewels of the Isles
(252878, 0, 4), -- The Age of Galakrond
(247498, 0, 48), -- Black Rook Hold Dungeon - Boss 4 - Door
(247401, 0, 48), -- Black Rook Hold Dungeon - Boss 2 - Door 2
(247400, 0, 48), -- Black Rook Hold Dungeon - Boss 2 - Door 3
(247399, 0, 48), -- Black Rook Hold Dungeon - Boss 2 - Door 1
(245080, 0, 48), -- Doodad_7NE_Blackrook_Portcullis002
(245079, 0, 48), -- Doodad_7NE_Blackrook_Portcullis001
(253921, 0, 32), -- Rusty Gate
(247405, 0, 48), -- Black Rook Hold Dungeon - Boss 1 - Door 3
(247404, 0, 48), -- Black Rook Hold Dungeon - Boss 1 - Door 2
(247407, 0, 48), -- Black Rook Hold Dungeon - Boss 1 - Post Boss Door
(247406, 0, 48), -- Black Rook Hold Dungeon - Boss 1 - Door 4
(247403, 0, 48), -- Black Rook Hold Dungeon - Boss 1 - Door 1
(247402, 0, 48), -- Black Rook Hold Dungeon - Boss 3 - Door
(245105, 0, 48), -- Doodad_7NE_Blackrook_Portcullis003
(245104, 0, 48), -- Black Rook Hold Dungeon - Boss 3 Post Door
(252328, 0, 48), -- Blackrook Hold Dungeon - Entrance - Right Door
(252327, 0, 48), -- Blackrook Hold Dungeon - Entrance - Left Door
(250576, 0, 2113540); -- Powerful Mana Gem

UPDATE `gameobject_template_addon` SET `flags`=2113540 WHERE `entry`=266619; -- A Mysterious Note


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+306 AND @CGUID+560;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+306, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3440.292, 7610.643, -7.843122, 3.406262, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+307, 98370, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3395.863, 7689.063, -13.30725, 0.8526685, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Councilor (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+308, 98362, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3347.6, 7721.022, 10.1237, 5.163941, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Troubled Soul (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+309, 98368, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3364.257, 7710.176, -7.913946, 2.145155, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Protector (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+310, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3436.786, 7583.594, -8.331825, 4.185817, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+311, 98370, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3433.572, 7587.683, -7.360798, 4.096879, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Councilor (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+312, 98370, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3433.865, 7579.145, -8.116902, 0.9668899, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Councilor (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+313, 98368, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3432.569, 7583.462, -8.410492, 3.172961, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Protector (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+314, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3436.77, 7608.777, -7.114692, 0.1961141, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+315, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3396.74, 7690.04, -13.61074, 4.101123, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+316, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3357.698, 7714.688, -7.556503, 1.260379, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+317, 98370, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3420.786, 7672.897, -13.65297, 4.275094, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Councilor (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+318, 98368, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3431.597, 7587.325, -8.412425, 4.091742, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Protector (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+319, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3430.104, 7677.662, -14.8829, 1.59343, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+320, 98370, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3404.865, 7702.157, -13.38024, 4.373443, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Councilor (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+321, 98362, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3463.358, 7668.222, 0.9229193, 3.436317, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Troubled Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+322, 98368, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3430.288, 7683.26, -13.46991, 5.028598, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Protector (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+323, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3426.724, 7589.372, -8.336851, 2.838457, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+324, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3431.297, 7589.307, -7.360698, 4.086237, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+325, 98370, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3352.575, 7716.557, -7.218928, 0.9832258, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Councilor (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+326, 98538, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3361.131, 7722.025, -6.049527, 1.677187, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lady Velandras Ravencrest (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+327, 111833, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3274.997, 7611.366, 14.92611, 0.8933888, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Thal'kiel (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+328, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3363.274, 7295.204, 244.3183, 4.443244, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+329, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3201.622, 7445.064, 128.3647, 5.040222, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+330, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3329.154, 7356.237, 260.1036, 4.672123, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+331, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3366.868, 7509.273, 15.28484, 4.651039, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+332, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3211.729, 7403.624, 131.266, 0.5242459, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+333, 98362, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3268.9, 7615.76, 17.96057, 1.565291, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Troubled Soul (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+334, 103662, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3221.897, 7534.168, 22.26258, 0.9783016, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Secret Door Stalker (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+335, 98521, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3366.2, 7500.392, 16.57369, 4.675405, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lord Etheldrin Ravencrest (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+336, 103662, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3217.076, 7537.67, 22.50607, 0.7945477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Secret Door Stalker (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+337, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3396.523, 7307.847, 258.1378, 3.464656, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+338, 98366, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3358.036, 7506.444, 15.02857, 5.33756, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ghostly Retainer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+339, 98813, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3199.187, 7448.49, 128.3889, 5.578126, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Bloodscent Felhound (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+340, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3395.492, 7272.271, 257.7462, 3.912477, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+341, 98370, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3374.208, 7505.912, 16.07733, 4.051169, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Ghostly Councilor (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+342, 103662, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3219.341, 7535.944, 24.502, 0.8854926, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Secret Door Stalker (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+343, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3296.744, 7204.445, 299.412, 4.445081, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+344, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3328.218, 7200.851, 270.1862, 4.95528, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+345, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3341.808, 7268.176, 249.2604, 4.443854, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+346, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3197.803, 7209.345, 255.805, 3.464052, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+347, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3224.356, 7193.072, 270.7903, 3.692349, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+348, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3316.955, 7144.83, 255.8437, 3.977315, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+349, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3311.544, 7230.967, 249.1249, 4.727018, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+350, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3347.864, 7174.363, 268.6862, 3.692936, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+351, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3332.017, 7273.133, 266.379, 4.67268, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+352, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3286.322, 7151.029, 248.6638, 1.450841, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+353, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3277.175, 7179.496, 274.8615, 0.969694, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+354, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3293.368, 7168.887, 271.2712, 1.451394, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+355, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3184.628, 7206.162, 245.0743, 0.9105668, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+356, 100759, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3269.691, 7166.738, 257.7139, 1.629111, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+357, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3142.268, 7429.467, 66.88806, 1.13522, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+358, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3147.003, 7421.601, 61.23034, 5.865595, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+359, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3143.604, 7414.572, 56.35261, 2.181595, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+360, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3147.538, 7405.154, 55.36475, 4.827199, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+361, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3151.862, 7402.313, 53.54121, 0.4733955, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+362, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3197.04, 7374.632, 129.7647, 4.467206, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+363, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3126.905, 7442.081, 72.02174, 6.249704, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+364, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3150.11, 7398.642, 52.46988, 4.19684, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+365, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3121.449, 7442.895, 71.83334, 1.293738, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+366, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3141.945, 7409.095, 55.44593, 4.444715, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+367, 98810, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3160.169, 7397.739, 129.8328, 1.7879, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wrathguard Bladelord (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+368, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3132.779, 7407.219, 53.64785, 1.599214, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+369, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3200.444, 7382.248, 133.5365, 4.907593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+370, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3140.391, 7407.597, 55.4449, 0.3590944, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+371, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3199.38, 7393.01, 131.266, 4.525629, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+372, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3120.386, 7419.132, 43.1647, 5.096267, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+373, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3121.022, 7425.326, 39.54274, 0.07503522, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+374, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3139.665, 7407.351, 55.43818, 3.696497, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+375, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3187.472, 7407.876, 129.8328, 5.820454, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: 201244 - Heaume d’elfe de la nuit ancien)
(@CGUID+376, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3181.295, 7408.241, 129.8328, 3.469796, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+377, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3196.843, 7398.979, 131.266, 2.682042, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+378, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3196.189, 7376.974, 129.8328, 2.536192, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+379, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3123.364, 7411.968, 47.0511, 2.004803, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+380, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3143.113, 7407.935, 55.4021, 2.309088, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+381, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3152.744, 7387.573, 46.02428, 5.845921, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+382, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3141.283, 7406.386, 55.41831, 6.119189, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+383, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3197.81, 7380.577, 129.8328, 1.562792, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+384, 98813, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.957, 7351.999, 130.7647, 3.379471, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Bloodscent Felhound (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+385, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3126.765, 7406.709, 50.51776, 5.550756, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+386, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3189.215, 7460.783, 28.37608, 4.459747, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique) (possible waypoints or random movement)
(@CGUID+387, 98677, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3134.055, 7424.386, 123.3647, 1.972888, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spiderling (Area: Bastion du Freux - Difficulty: Normal) (Auras: 225908 - Venin de l’âme)
(@CGUID+388, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3197.82, 7473.989, 28.36475, 1.850287, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique) (possible waypoints or random movement)
(@CGUID+389, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3442.142, 7609.433, -7.990914, 0.0005510102, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+390, 98810, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3176.698, 7356.537, 129.7647, 0.237867, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wrathguard Bladelord (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+391, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3445.575, 7612.535, -7.752574, 0.08359831, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+392, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.259, 7458.21, 27.58601, 3.490012, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+393, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3171.519, 7396.374, 195.7908, 0.1407821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+394, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3191.308, 7464.878, 28.18311, 2.959296, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique)
(@CGUID+395, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3188.004, 7465.026, 28.1829, 6.13273, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+396, 98810, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3151.836, 7394.39, 129.6614, 1.175525, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wrathguard Bladelord (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+397, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3179.872, 7441.236, 28.18303, 3.382771, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+398, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3180.043, 7469.298, 28.2711, 4.644298, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+399, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3158.427, 7456.431, 27.70626, 1.712995, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique) (possible waypoints or random movement)
(@CGUID+400, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3432.644, 7580.881, -8.313581, 0.06790021, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+401, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3428.715, 7582.818, -8.315994, 0.08209845, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+402, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3433.865, 7579.145, -8.033569, 0.05532881, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+403, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3422.275, 7573.944, -6.198866, 0.008218912, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+404, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3163.741, 7428.492, 28.30193, 4.819729, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique)
(@CGUID+405, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.084, 7443.568, 28.18292, 4.550499, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+406, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3171.122, 7456.287, 27.58601, 0.38026, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique)
(@CGUID+407, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3150.043, 7491.222, 28.30292, 5.570551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+408, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3142.16, 7486.237, 28.30307, 2.41465, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+409, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3198.93, 7400.094, 131.3763, 3.455247, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+410, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3176.546, 7439.658, 28.18313, 0.9447287, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique)
(@CGUID+411, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3198.286, 7395.462, 131.266, 3.891574, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+412, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3151.524, 7464.353, 28.26291, 3.989646, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique)
(@CGUID+413, 98949, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3287.538, 7270.679, 231.3336, 2.32791, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Smashspite the Hateful (Area: Bastion du Freux - Difficulty: Normal) (Auras: 72242 - Energie à zéro + régénération à zéro, 198114 - Brutalité)
(@CGUID+414, 98792, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3178.856, 7313.276, 129.8101, 4.416863, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Scavenger (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+415, 98965, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3191.722, 7423.685, 270.4619, 0.5783981, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Kur'talos Ravencrest (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+416, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3153.151, 7490.006, 28.30189, 2.748768, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+417, 98970, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3196.71, 7425.587, 270.4651, 3.667413, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Latosius (Area: Bastion du Freux - Difficulty: Normal) (Auras: 198911 - Foudre)
(@CGUID+418, 103102, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3148.97, 7489.098, 28.3399, 0.2755243, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Lost Soul (Area: Bastion du Freux - Difficulty: Normal) (Auras: 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique)
(@CGUID+419, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3200.12, 7380.394, 130.1667, 1.479226, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+420, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3169.035, 7400.948, 89.75198, 3.628563, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+421, 98696, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3098.552, 7311.781, 103.4037, 0.4495288, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Illysanna Ravencrest (Area: Bastion du Freux - Difficulty: Normal) (Auras: 197367 - Annulation de puissance furieuse, 197394 - Dynamisme périodique, 42459 - Ambidextrie)
(@CGUID+422, 112725, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3220.523, 7353.108, 128.3647, 0.3721197, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Kalyndras (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+423, 98280, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3169.214, 7392.656, 89.60539, 2.891291, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Arcanist (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+424, 98243, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3167.056, 7397.168, 89.75198, 3.564588, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Champion écorchâme (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+425, 98243, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3147.307, 7408.855, 89.67985, 5.865049, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Champion écorchâme (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+426, 98691, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3148.865, 7405.586, 89.57529, 5.600851, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Scout (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+427, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3400.221, 7541.892, 15.47667, 0.03133182, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+428, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3400.376, 7545.779, 14.71237, 0.08911803, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+429, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3402.014, 7546.353, 14.90832, 0.01842864, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+430, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3157.292, 7391.531, 129.8328, 4.325579, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+431, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.499, 7366.329, 129.8328, 2.671717, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+432, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3170.834, 7366.797, 129.8328, 2.349322, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+433, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3161.173, 7392.132, 133.971, 1.721992, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+434, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3166.445, 7361.713, 132.1252, 5.674409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+435, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3147.551, 7368.265, 86.51179, 1.224925, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+436, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3149.403, 7388.239, 132.3095, 1.547498, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+437, 98243, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3141.051, 7370.075, 86.57034, 0.9487426, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Champion écorchâme (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+438, 98691, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3137.563, 7376.766, 86.47598, 0.6421158, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Scout (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+439, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3141.194, 7392.088, 129.867, 3.891541, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+440, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3168.083, 7349.971, 133.091, 0.7731615, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+441, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3140.935, 7396.52, 129.8491, 4.080718, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+442, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3175.743, 7314.627, 129.8101, 4.496102, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+443, 103857, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3195.003, 7397.133, 219.2898, 1.820397, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+444, 98691, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3145.099, 7340.728, 102.7814, 2.632218, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Scout (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+445, 101839, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3126.452, 7355.76, 86.3961, 0.9159413, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Risen Companion (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+446, 98900, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3171.184, 7399.799, 195.7897, 0.2283309, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Wyrmtongue Trickster (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+447, 98691, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3134.716, 7358.288, 86.65026, 0.9225642, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Scout (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+448, 102094, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3185.063, 7397.518, 225.7607, 3.916874, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Swordsman (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+449, 102094, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3180.461, 7399.046, 225.6802, 4.717671, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Swordsman (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+450, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3229.657, 7340.991, 226.2188, 1.706771, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+451, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3205.101, 7364.383, 223.8675, 4.479276, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+452, 102788, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3227.081, 7339.36, 226.0952, 3.324312, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Felspite Dominator (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+453, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3226.916, 7341.545, 226.1684, 0.7555057, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+454, 103857, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.995, 7404.109, 213.5786, 6.282863, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+455, 102788, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3205.516, 7357.854, 223.9304, 2.39765, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Felspite Dominator (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+456, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3202.055, 7360.005, 223.8959, 3.618129, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+457, 98691, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3125.06, 7336.859, 86.46672, 1.684823, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Scout (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+458, 98691, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3110.827, 7365.433, 102.7814, 2.006153, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Scout (Area: Bastion du Freux - Difficulty: Normal) (Auras: 42459 - Ambidextrie)
(@CGUID+459, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3205.271, 7358.023, 223.9107, 3.394315, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+460, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3375.012, 7507.106, 15.69415, 0.02088627, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+461, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3364.004, 7500.861, 16.64808, 0.01444519, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+462, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3372.358, 7502.513, 16.94619, 0.005789867, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+463, 98201, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3367.209, 7504.083, 16.78772, 0.09430609, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Enraged Soul (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+464, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3121.12, 7335.824, 86.37814, 1.180814, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+465, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3140.846, 7399.59, 196.8831, 4.568252, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+466, 98280, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3114.856, 7345.999, 86.50984, 0.2059843, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Arcanist (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+467, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3147.446, 7393.381, 196.9478, 2.466676, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+468, 102788, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3143.786, 7394.434, 196.8361, 2.65282, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Felspite Dominator (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+469, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3114.484, 7340.424, 86.37615, 0.7368924, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+470, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3205.511, 7353.011, 224.3022, 0.6184067, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+471, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3129.635, 7319.189, 102.7814, 2.942788, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+472, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3096.014, 7342.987, 102.7814, 5.24184, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+473, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3142.189, 7377.756, 203.6958, 1.817419, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+474, 98542, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3251.346, 7582.793, 12.75466, 0.6647303, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Amalgam of Souls (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+475, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3141.412, 7382.031, 201.2884, 1.936905, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+476, 98706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3104.325, 7320.22, 95.53854, 0.9169088, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Commander Shemdah'sohn (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+477, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3197.114, 7356.362, 223.8032, 0.6139234, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+478, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3163.479, 7352.637, 215.7648, 4.922734, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+479, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3164.454, 7351.771, 215.7648, 4.903542, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+480, 102788, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3171.947, 7350.318, 215.7647, 3.313728, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Felspite Dominator (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+481, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3170.72, 7350.128, 215.7647, 5.989089, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+482, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3160.885, 7350.994, 215.7648, 4.061912, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+483, 102788, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3162.073, 7350.277, 215.7648, 5.165414, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Felspite Dominator (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+484, 98243, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3039.313, 7336.708, 93.12657, 5.683003, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Champion écorchâme (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+485, 102788, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3225.96, 7332.471, 226.5728, 3.076826, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Felspite Dominator (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+486, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3225.503, 7333.955, 226.2374, 2.209142, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+487, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3218.164, 7332.345, 226.5368, 5.166239, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+488, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3035.937, 7331.059, 92.65316, 5.895597, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+489, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3226.225, 7332.981, 226.5552, 3.512614, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+490, 98275, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3034.146, 7325.243, 93.0897, 0.1552612, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Archer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+491, 111833, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3176.379, 7392.027, 271.6467, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Thal'kiel (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+492, 111221, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3176.379, 7392.027, 271.6467, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+493, 103857, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3192.313, 7356.129, 236.1363, 1.594985, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 26124), -- Fel Bat (Area: Bastion du Freux - Difficulty: Normal) (Auras: ) (possible waypoints or random movement)
(@CGUID+494, 111221, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3080.022, 7286.022, 103.6103, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Xal'atath (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+495, 111833, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3080.022, 7286.022, 103.6103, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Thal'kiel (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+496, 98681, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3121.764, 7444.88, 71.87274, 5.179119, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rook Spinner (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+497, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.606, 7313.834, 129.8101, 4.617497, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+498, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3178.564, 7309.397, 129.6008, 4.213258, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+499, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.303, 7310.65, 129.7297, 4.617497, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3178.955, 7312.581, 129.8101, 4.654608, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+501, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.606, 7313.834, 129.8101, 4.617497, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+502, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3178.955, 7312.581, 129.8101, 4.654608, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+503, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3176.932, 7396.273, 195.3372, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+504, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.296, 7396.42, 195.7945, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+505, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+506, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+507, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.296, 7396.42, 195.7945, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+508, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.296, 7396.42, 195.7945, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+509, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+510, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.123, 7396.263, 195.3042, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+511, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+512, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.08, 7400.806, 195.1039, 0.1277523, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+513, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.109, 7396.264, 195.3066, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+514, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3174.296, 7396.42, 195.7945, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+515, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.094, 7396.265, 195.3091, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+516, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.109, 7396.264, 195.3066, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+517, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.08, 7396.265, 195.3115, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+518, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+519, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+520, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.123, 7396.263, 195.3042, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+521, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+522, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+523, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3173.466, 7400.026, 195.7867, 0.2685775, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+524, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.165, 7396.261, 195.2968, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+525, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.102, 7396.264, 195.3078, 6.227513, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+526, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.115, 7400.81, 195.0895, 0.1277523, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+527, 111706, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3177.133, 7400.812, 195.0822, 0.1277523, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Boulder (Area: Bastion du Freux - Difficulty: Normal) (Auras: 222378 - Ecrasement de rochers)
(@CGUID+528, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3236.863, 7320.938, 231.0745, 0.6814566, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+529, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3240.557, 7325.575, 231.2397, 1.558961, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+530, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3241.514, 7323.298, 231.0813, 4.72771, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+531, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3236.863, 7320.938, 231.0745, 0.6814566, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+532, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3241.514, 7323.298, 231.0813, 4.72771, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+533, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3240.556, 7325.48, 231.2305, 1.558961, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+534, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3239.923, 7331.634, 229.7209, 2.143853, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+535, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3241.565, 7319.979, 231.2182, 4.72771, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+536, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3239.998, 7323.48, 231.1647, 0.681435, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+537, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3240.481, 7319.155, 231.0802, 1.558894, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal)
(@CGUID+538, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3236.863, 7320.938, 231.0745, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+539, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3241.514, 7323.298, 231.0813, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+540, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3236.863, 7320.938, 231.0745, 0.6814566, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+541, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3240.556, 7325.512, 231.2336, 1.558961, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+542, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3241.514, 7323.298, 231.0813, 4.72771, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+543, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3236.863, 7320.938, 231.0745, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+544, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3241.514, 7323.298, 231.0813, 0, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+545, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3240.481, 7319.155, 231.0802, 1.558894, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+546, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3240.556, 7325.448, 231.2274, 1.558961, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+547, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3241.514, 7323.298, 231.0813, 4.72771, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+548, 102781, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3236.863, 7320.938, 231.0745, 0.6814566, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Fel Bat Pup (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+549, 102094, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3191.883, 7364.246, 223.9544, 5.365228, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Swordsman (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+550, 102095, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3196.096, 7367.852, 223.9611, 5.381514, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Lancer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+551, 102094, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3165.323, 7418.004, 231.534, 0.1594051, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Swordsman (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+552, 102095, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3164.143, 7423.417, 230.9856, 6.0147, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Lancer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+553, 102094, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3143.69, 7391.455, 247.3931, 1.381631, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Swordsman (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+554, 102095, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3138.202, 7392.193, 247.7449, 0.9535322, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Lancer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+555, 102094, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3152.482, 7350.256, 264.0049, 1.848211, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Swordsman (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+556, 102095, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3157.277, 7353.015, 264.0049, 2.456878, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Lancer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+557, 102094, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3154.33, 7352.204, 264.0049, 2.351969, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Swordsman (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+558, 102095, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3156.805, 7347.459, 264.0049, 1.972284, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Risen Lancer (Area: Bastion du Freux - Difficulty: Normal) (Auras: )
(@CGUID+559, 100861, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3189.554, 7415.69, 270.6481, 5.580757, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Kur'talos Ravencrest (Area: Bastion du Freux - Difficulty: Normal) (Auras: 198782 - Lame tourbillonnante)
(@CGUID+560, 101054, 1501, 7805, 7805, 8388870, '0', 0, 0, 0, 3188.028, 7416.982, 270.7593, 0.0946374, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Soul of Ravencrest (Area: Bastion du Freux - Difficulty: Normal) (Auras: 199243 -)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+306 AND @CGUID+560;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+306, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Councilor
(@CGUID+308, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Troubled Soul
(@CGUID+309, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Ghostly Protector
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Councilor
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Councilor
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Protector
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+315, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+316, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Councilor
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Protector
(@CGUID+319, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+320, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Councilor
(@CGUID+321, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Troubled Soul
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Protector
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+325, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Ghostly Councilor
(@CGUID+326, 0, 0, 8, 1, 0, 0, 0, 0, '42459'), -- Lady Velandras Ravencrest - 42459 - Ambidextrie
(@CGUID+327, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+328, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+330, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+332, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+333, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Troubled Soul
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Secret Door Stalker
(@CGUID+335, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Lord Etheldrin Ravencrest
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Secret Door Stalker
(@CGUID+337, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Retainer
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bloodscent Felhound
(@CGUID+340, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ghostly Councilor
(@CGUID+342, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Secret Door Stalker
(@CGUID+343, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+344, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+345, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+346, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+347, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+348, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+349, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+350, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+351, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+352, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+353, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+354, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+355, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+356, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+357, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+362, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+366, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Wrathguard Bladelord - 42459 - Ambidextrie
(@CGUID+368, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+369, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+373, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, '201244'), -- Wyrmtongue Scavenger - 201244 - Heaume d’elfe de la nuit ancien
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+380, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+382, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bloodscent Felhound
(@CGUID+385, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- Rook Spiderling - 225908 - Venin de l’âme
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, '204063'), -- Lost Soul - 204063 - Scintillement fantomatique
(@CGUID+389, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Wrathguard Bladelord - 42459 - Ambidextrie
(@CGUID+391, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+394, 0, 0, 0, 1, 0, 0, 0, 0, '204063'), -- Lost Soul - 204063 - Scintillement fantomatique
(@CGUID+395, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Wrathguard Bladelord - 42459 - Ambidextrie
(@CGUID+397, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+400, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+401, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+402, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+403, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+404, 0, 0, 8, 1, 0, 0, 0, 0, '204063'), -- Lost Soul - 204063 - Scintillement fantomatique
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, '204063'), -- Lost Soul - 204063 - Scintillement fantomatique
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+410, 0, 0, 0, 1, 0, 0, 0, 0, '204063'), -- Lost Soul - 204063 - Scintillement fantomatique
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+412, 0, 0, 0, 1, 0, 0, 0, 0, '204063'), -- Lost Soul - 204063 - Scintillement fantomatique
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, '72242 198114'), -- Smashspite the Hateful - 72242 - Energie à zéro + régénération à zéro, 198114 - Brutalité
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Scavenger
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kur'talos Ravencrest
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+417, 0, 0, 0, 1, 0, 0, 0, 0, '198911'), -- Latosius - 198911 - Foudre
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- Lost Soul - 204063 - Scintillement fantomatique, 204064 - Scintillement fantomatique
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+420, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+421, 0, 0, 0, 1, 0, 0, 0, 0, '197367 197394 42459'), -- Illysanna Ravencrest - 197367 - Annulation de puissance furieuse, 197394 - Dynamisme périodique, 42459 - Ambidextrie
(@CGUID+422, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Kalyndras - 42459 - Ambidextrie
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Arcanist
(@CGUID+424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Champion écorchâme
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Champion écorchâme
(@CGUID+426, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Risen Scout - 42459 - Ambidextrie
(@CGUID+427, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+428, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+429, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+430, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+431, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+433, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+434, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+436, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Champion écorchâme
(@CGUID+438, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Risen Scout - 42459 - Ambidextrie
(@CGUID+439, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+440, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+441, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+442, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+443, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+444, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Risen Scout - 42459 - Ambidextrie
(@CGUID+445, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Companion
(@CGUID+446, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wyrmtongue Trickster
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Risen Scout - 42459 - Ambidextrie
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Swordsman
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Swordsman
(@CGUID+450, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+452, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Felspite Dominator
(@CGUID+453, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+454, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Felspite Dominator
(@CGUID+456, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Risen Scout - 42459 - Ambidextrie
(@CGUID+458, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- Risen Scout - 42459 - Ambidextrie
(@CGUID+459, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+460, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+461, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+462, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+463, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Enraged Soul
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+466, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Arcanist
(@CGUID+467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Felspite Dominator
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+470, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+472, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+474, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Amalgam of Souls
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Commander Shemdah'sohn
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Felspite Dominator
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+483, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Felspite Dominator
(@CGUID+484, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Champion écorchâme
(@CGUID+485, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Felspite Dominator
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+487, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+488, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+489, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+490, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Archer
(@CGUID+491, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+493, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fel Bat
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+495, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+496, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Rook Spinner
(@CGUID+497, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, '222378'); -- Boulder - 222378 - Ecrasement de rochers

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+500, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+501, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+502, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+503, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+504, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+507, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+510, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+516, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+519, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+520, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+521, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+522, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+523, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+524, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+525, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+526, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+527, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- Boulder - 222378 - Ecrasement de rochers
(@CGUID+528, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+529, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+531, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+532, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+533, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+534, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+535, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+536, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+537, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+538, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+539, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+540, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+541, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+543, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+544, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+545, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+546, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+547, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+548, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Fel Bat Pup
(@CGUID+549, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Swordsman
(@CGUID+550, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Lancer
(@CGUID+551, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Swordsman
(@CGUID+552, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Lancer
(@CGUID+553, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Swordsman
(@CGUID+554, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Lancer
(@CGUID+555, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Swordsman
(@CGUID+556, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Lancer
(@CGUID+557, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Swordsman
(@CGUID+558, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Risen Lancer
(@CGUID+559, 0, 0, 0, 1, 0, 0, 0, 0, '198782'), -- Kur'talos Ravencrest - 198782 - Lame tourbillonnante
(@CGUID+560, 0, 0, 33554432, 1, 0, 0, 0, 0, '199243'); -- Soul of Ravencrest - 199243 -

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+341 AND @OGUID+370;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+341, 252327, 1501, 7805, 7805, 8388870, '0', 0, 3451.329, 7614.11, -7.326169, 4.084075, 0, 0, -0.8910055, 0.4539925, 7200, 255, 0, 26124), -- Blackrook Hold Dungeon - Entrance - Left Door (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+342, 252328, 1501, 7805, 7805, 8388870, '0', 0, 3443.042, 7665.096, -7.326169, 2.513274, 0, 0, 0.9510565, 0.3090171, 7200, 255, 1, 26124), -- Blackrook Hold Dungeon - Entrance - Right Door (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+343, 252247, 1501, 7805, 7805, 8388870, '0', 0, 3505.714, 7649.45, -3.30042, 3.426656, 0, 0, -0.9898596, 0.1420494, 7200, 255, 1, 26124), -- Instance Portal (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+344, 245104, 1501, 7805, 7805, 8388870, '0', 0, 3186.876, 7375.126, 225.5623, 5.393071, 0, 0, -0.4305096, 0.902586, 7200, 255, 1, 26124), -- Black Rook Hold Dungeon - Boss 3 Post Door (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+345, 245105, 1501, 7805, 7805, 8388870, '0', 0, 3182.923, 7400.556, 225.5312, 4.345873, 0, 0, -0.8241253, 0.5664076, 7200, 255, 0, 26124), -- Doodad_7NE_Blackrook_Portcullis003 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+346, 247402, 1501, 7805, 7805, 8388870, '0', 0, 3248.373, 7311.03, 232.9171, 5.480337, 0, 0, -0.3907299, 0.9205054, 7200, 255, 0, 26124), -- Black Rook Hold Dungeon - Boss 3 - Door (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+347, 247403, 1501, 7805, 7805, 8388870, '0', 0, 3277.842, 7563.882, 10.98412, 5.654869, 0, 0, -0.3090162, 0.9510568, 7200, 255, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 1 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+348, 247406, 1501, 7805, 7805, 8388870, '0', 0, 3271.062, 7606.691, 10.98412, 0.9424788, 0, 0, 0.4539909, 0.8910064, 7200, 255, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 4 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+349, 247407, 1501, 7805, 7805, 8388870, '0', 0, 3218.833, 7534.961, 14.91523, 0.9424766, 0, 0, 0.45399, 0.8910068, 7200, 255, 1, 26124), -- Black Rook Hold Dungeon - Boss 1 - Post Boss Door (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+350, 247404, 1501, 7805, 7805, 8388870, '0', 0, 3235.033, 7557.103, 10.98412, 4.084075, 0, 0, -0.8910055, 0.4539925, 7200, 255, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 2 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+351, 247405, 1501, 7805, 7805, 8388870, '0', 0, 3228.253, 7599.911, 10.98412, 2.513274, 0, 0, 0.9510565, 0.3090171, 7200, 255, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 3 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+352, 253921, 1501, 7805, 7805, 8388870, '0', 0, 3215.201, 7368.48, 129.8136, 5.829402, 0, 0, -0.2249498, 0.9743704, 7200, 255, 1, 26124), -- Rusty Gate (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+353, 245079, 1501, 7805, 7805, 8388870, '0', 0, 3085.019, 7352.04, 84.96606, 5.654869, 0, 0, -0.3090162, 0.9510568, 7200, 255, 1, 26124), -- Doodad_7NE_Blackrook_Portcullis001 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+354, 243007, 1501, 7805, 7805, 8388870, '0', 0, 2565.066, 7486.539, 29.50219, 0.03490249, -0.0003652573, 0.02095127, 0.01744652, 0.9996282, 7200, 255, 1, 26124), -- Heathrow Cellar (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+355, 245080, 1501, 7805, 7805, 8388870, '0', 0, 3100.121, 7372.827, 84.96606, 5.654869, 0, 0, -0.3090162, 0.9510568, 7200, 255, 1, 26124), -- Doodad_7NE_Blackrook_Portcullis002 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+356, 247399, 1501, 7805, 7805, 8388870, '0', 0, 3106.219, 7292.774, 103.2473, 6.032261, 0, 0, -0.1251335, 0.9921399, 7200, 255, 1, 26124), -- Black Rook Hold Dungeon - Boss 2 - Door 1 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+357, 247400, 1501, 7805, 7805, 8388870, '0', 0, 3076.1, 7281.135, 103.2473, 4.078671, 0, 0, -0.8922291, 0.4515831, 7200, 255, 0, 26124), -- Black Rook Hold Dungeon - Boss 2 - Door 3 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+358, 247401, 1501, 7805, 7805, 8388870, '0', 0, 3077.757, 7313.208, 103.2473, 5.28695, 0, 0, -0.4777727, 0.8784835, 7200, 255, 1, 26124), -- Black Rook Hold Dungeon - Boss 2 - Door 2 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+359, 247498, 1501, 7805, 7805, 8388870, '0', 0, 3174.844, 7389.831, 271.4599, 1.076114, 0, 0, 0.5124683, 0.8587061, 7200, 255, 0, 26124), -- Black Rook Hold Dungeon - Boss 4 - Door (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+360, 252878, 1501, 7805, 7805, 8388870, '0', 0, 3196.765, 7460.981, 29.3224, 1.114339, 0, 0, 0.5287857, 0.8487554, 7200, 255, 1, 26124), -- The Age of Galakrond (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+361, 246410, 1501, 7805, 7805, 8388870, '0', 0, 3235.587, 7356.822, 128.1938, 2.251473, 0, 0, 0.902585, 0.4305117, 7200, 255, 1, 26124), -- Ancient Chair (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+362, 246505, 1501, 7805, 7805, 8388870, '0', 0, 3235.477, 7358.237, 129.1142, 6.187326, -0.2185073, -0.6724977, -0.2185068, 0.6724999, 7200, 255, 1, 26124), -- Small Red Button (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+363, 246409, 1501, 7805, 7805, 8388870, '0', 0, 3236.737, 7359.569, 128.1972, 3.036875, 0, 0, 0.9986296, 0.05233501, 7200, 255, 1, 26124), -- Ancient Chair (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+364, 252385, 1501, 7805, 7805, 8388870, '0', 0, 3152.583, 7490.291, 29.31085, 5.280411, 0, 0, -0.4806423, 0.8769167, 7200, 255, 1, 26124), -- Torn Page (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+365, 246669, 1501, 7805, 7805, 8388870, '0', 0, 3173.464, 7413.471, 215.8221, 2.314179, 0, 0, 0.915637, 0.4020061, 7200, 255, 1, 26124), -- Doodad_7KO_Kobold_SackSmall001 (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+366, 252266, 1501, 7805, 7805, 8388870, '0', 0, 3127.291, 7306.146, 85.09615, 3.199004, 0, 0, -0.999588, 0.02870184, 7200, 255, 1, 26124), -- Delayeth's Journal: The Jewels of the Isles (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+367, 205044, 1501, 7805, 7805, 8388870, '0', 0, 2824.847, 7247.29, 23.37994, 4.555313, -0.006564617, -0.01616955, -0.7602081, 0.6494452, 7200, 255, 1, 26124), -- Fire (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+368, 205038, 1501, 7805, 7805, 8388870, '0', 0, 2802.53, 7299.135, 23.96399, 0.6719503, 0, 0, 0.32969, 0.9440892, 7200, 255, 1, 26124), -- Fire (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+369, 205036, 1501, 7805, 7805, 8388870, '0', 0, 2802.617, 7297.662, 23.10232, 3.185267, 0, 0, -0.9997616, 0.02183524, 7200, 255, 1, 26124), -- Stove (Area: Bastion du Freux - Difficulty: Normal)
(@OGUID+370, 205037, 1501, 7805, 7805, 8388870, '0', 0, 2802.769, 7296.469, 23.96399, 0.6283169, 0, 0, 0.3090162, 0.9510568, 7200, 255, 1, 26124); -- Fire (Area: Bastion du Freux - Difficulty: Normal)


UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=247057 AND `EffectIndex`=1);
UPDATE `spell_target_position` SET `VerifiedBuild`=26124 WHERE (`ID`=222695 AND `EffectIndex`=0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (101054 /*101054 (Soul of Ravencrest)*/, 100861 /*100861 (Kur'talos Ravencrest) - Lame tourbillonnante*/, 102095 /*102095 (Risen Lancer)*/, 111706 /*111706 (Boulder) - Ecrasement de rochers*/, 98681 /*98681 (Rook Spinner)*/, 98706 /*98706 (Commander Shemdah'sohn)*/, 98542 /*98542 (Amalgam of Souls)*/, 102788 /*102788 (Felspite Dominator)*/, 102781 /*102781 (Fel Bat Pup)*/, 102094 /*102094 (Risen Swordsman)*/, 101839 /*101839 (Risen Companion)*/, 103857 /*103857 (Fel Bat)*/, 98691 /*98691 (Risen Scout) - Ambidextrie*/, 98243 /*Champion écorchâme*/, 98280 /*98280 (Risen Arcanist)*/, 112725 /*112725 (Kalyndras) - Ambidextrie*/, 98696 /*98696 (Illysanna Ravencrest) - Annulation de puissance furieuse, Dynamisme périodique, Ambidextrie*/, 98275 /*98275 (Risen Archer)*/, 98970 /*98970 (Latosius) - Foudre*/, 98965 /*98965 (Kur'talos Ravencrest)*/, 98949 /*98949 (Smashspite the Hateful) - Energie à zéro + régénération à zéro, Brutalité*/, 98900 /*98900 (Wyrmtongue Trickster)*/, 98201 /*98201 (Enraged Soul)*/, 103102 /*103102 (Lost Soul) - Scintillement fantomatique, Scintillement fantomatique*/, 98810 /*98810 (Wrathguard Bladelord) - Ambidextrie*/, 98677 /*98677 (Rook Spiderling) - Venin de l’âme*/, 98813 /*98813 (Bloodscent Felhound)*/, 98521 /*98521 (Lord Etheldrin Ravencrest)*/, 103662 /*103662 (Secret Door Stalker)*/, 98792 /*98792 (Wyrmtongue Scavenger)*/, 100759 /*100759 (Fel Bat)*/, 98538 /*98538 (Lady Velandras Ravencrest) - Ambidextrie*/, 98368 /*98368 (Ghostly Protector)*/, 98362 /*98362 (Troubled Soul)*/, 98370 /*98370 (Ghostly Councilor)*/, 98366 /*98366 (Ghostly Retainer)*/, 40438 /*40438 (Steamwheedle Shyster)*/, 120215 /*120215 (Archmage Khadgar)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(101054, 0, 0, 33554432, 1, 0, 0, 0, 0, '199243'), -- 101054 (Soul of Ravencrest)
(100861, 0, 0, 0, 1, 0, 0, 0, 0, '198782'), -- 100861 (Kur'talos Ravencrest) - Lame tourbillonnante
(102095, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102095 (Risen Lancer)
(111706, 0, 0, 0, 1, 0, 0, 0, 0, '222378'), -- 111706 (Boulder) - Ecrasement de rochers
(98681, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98681 (Rook Spinner)
(98706, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98706 (Commander Shemdah'sohn)
(98542, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98542 (Amalgam of Souls)
(102788, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102788 (Felspite Dominator)
(102781, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102781 (Fel Bat Pup)
(102094, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 102094 (Risen Swordsman)
(101839, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 101839 (Risen Companion)
(103857, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 103857 (Fel Bat)
(98691, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 98691 (Risen Scout) - Ambidextrie
(98243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Champion écorchâme
(98280, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98280 (Risen Arcanist)
(112725, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 112725 (Kalyndras) - Ambidextrie
(98696, 0, 0, 0, 1, 0, 0, 0, 0, '197367 197394 42459'), -- 98696 (Illysanna Ravencrest) - Annulation de puissance furieuse, Dynamisme périodique, Ambidextrie
(98275, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98275 (Risen Archer)
(98970, 0, 0, 0, 1, 0, 0, 0, 0, '198911'), -- 98970 (Latosius) - Foudre
(98965, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98965 (Kur'talos Ravencrest)
(98949, 0, 0, 0, 1, 0, 0, 0, 0, '72242 198114'), -- 98949 (Smashspite the Hateful) - Energie à zéro + régénération à zéro, Brutalité
(98900, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98900 (Wyrmtongue Trickster)
(98201, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 98201 (Enraged Soul)
(103102, 0, 0, 0, 1, 0, 0, 0, 0, '204063 204064'), -- 103102 (Lost Soul) - Scintillement fantomatique, Scintillement fantomatique
(98810, 0, 0, 0, 1, 0, 0, 0, 0, '42459'), -- 98810 (Wrathguard Bladelord) - Ambidextrie
(98677, 0, 0, 0, 1, 0, 0, 0, 0, '225908'), -- 98677 (Rook Spiderling) - Venin de l’âme
(98813, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98813 (Bloodscent Felhound)
(98521, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 98521 (Lord Etheldrin Ravencrest)
(103662, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 103662 (Secret Door Stalker)
(98792, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98792 (Wyrmtongue Scavenger)
(100759, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 100759 (Fel Bat)
(98538, 0, 0, 8, 1, 0, 0, 0, 0, '42459'), -- 98538 (Lady Velandras Ravencrest) - Ambidextrie
(98368, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 98368 (Ghostly Protector)
(98362, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 98362 (Troubled Soul)
(98370, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98370 (Ghostly Councilor)
(98366, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 98366 (Ghostly Retainer)
(40438, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 40438 (Steamwheedle Shyster)
(120215, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- 120215 (Archmage Khadgar)

UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=106655; -- 106655 (Arcanomancer Vridiel)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=96808; -- 96808 (Sandra Bartan)
UPDATE `creature_template_addon` SET `auras`='232270' WHERE `entry`=116420; -- 116420 (Glowing Blue Gem)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=113900; -- 113900 (Liyana)
UPDATE `creature_template_addon` SET `bytes1`=0 WHERE `entry`=96198; -- 96198 (Catriona Macrae)
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=72587; -- VFX Bunny
UPDATE `creature_template_addon` SET `auras`='60913' WHERE `entry`=96778; -- 96778 (Aemara)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (58237, 112545, 120419, 113646, 107772, 112543, 108401, 106263, 106262, 120424);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(58237, 0, 26124),
(112545, 0, 26124),
(120419, 0, 26124),
(113646, 0, 26124),
(107772, 0, 26124),
(112543, 0, 26124),
(108401, 0, 26124),
(106263, 0, 26124),
(106262, 0, 26124),
(120424, 0, 26124);



UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67478;
UPDATE `creature_model_info` SET `BoundingRadius`=3.307967, `VerifiedBuild`=26124 WHERE `DisplayID`=42742;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65954;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65837;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=5047;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67783;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67488;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64620;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65950;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65762;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65718;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72237;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65951;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65743;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66032;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66853;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65304;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68014;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68012;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67518;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68011;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68013;
UPDATE `creature_model_info` SET `CombatReach`=1.5 WHERE `DisplayID`=64476;
UPDATE `creature_model_info` SET `CombatReach`=1.5 WHERE `DisplayID`=64482;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=35688;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65054;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65814;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64480;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=55150;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65833;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65786;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65812;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65787;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65785;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27853;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27852;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27957;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27854;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27961;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=39555;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26413;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65253;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72956;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=46697;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65242;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28146;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=70532;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28163;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=35280;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=60926;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=60927;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69682;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26437;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=60924;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26339;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64586;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26442;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=3714;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65257;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36904;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=31852;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=73730;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75912;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=32991;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=35818;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65244;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65232;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=23337;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28158;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72465;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26330;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36906;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72945;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71596;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=63038;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25882;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=5556;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71597;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=21342;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26396;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27952;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28144;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28148;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74200;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=251;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74199;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65477;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71942;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74194;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68483;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68484;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72078;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=34635;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25674;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36907;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=16910;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=80;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=78398;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71943;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25955;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27954;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72074;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64759;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74782;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69790;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65355;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65369;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72095;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65412;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67001;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65424;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25041;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=74087;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25673;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75130;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27955;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75301;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28159;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=75302;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71599;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=33542;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26395;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=36905;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25605;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27287;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26440;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27915;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=42872;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28160;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26441;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72104;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72103;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28143;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28161;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26394;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67362;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=72344;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=48000;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25595;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71019;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27448;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27616;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=22003;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27019;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71017;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=15180;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=68480;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=71088;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27960;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=76630;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67016;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=47999;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27959;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=41568;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66672;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67760;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=30869;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27592;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=67043;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65975;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65101;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69542;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=40155;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=34172;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25807;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64939;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25806;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=66159;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69156;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25983;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=61971;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=328;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27883;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1924;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69627;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27680;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=24862;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28147;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69152;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28156;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=16883;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27657;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27719;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28155;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25875;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64049;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25947;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=11709;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=52659;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28162;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=56704;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1206;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26307;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25791;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=25607;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1669;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=5554;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=26299;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28120;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=55376;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28118;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=28157;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5699967, `VerifiedBuild`=26124 WHERE `DisplayID`=43497;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=1072;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=18052;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=5585;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=6296;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=5777;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=27822;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69926;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=65714;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=2954;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=17170;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=47997;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=58842;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=64048;
UPDATE `creature_model_info` SET `VerifiedBuild`=26124 WHERE `DisplayID`=69789;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=102095 AND `ID`=1) OR (`CreatureID`=98706 AND `ID`=1) OR (`CreatureID`=102788 AND `ID`=1) OR (`CreatureID`=102094 AND `ID`=1) OR (`CreatureID`=98691 AND `ID`=1) OR (`CreatureID`=98243 AND `ID`=1) OR (`CreatureID`=112725 AND `ID`=1) OR (`CreatureID`=98696 AND `ID`=1) OR (`CreatureID`=98275 AND `ID`=1) OR (`CreatureID`=98970 AND `ID`=1) OR (`CreatureID`=98965 AND `ID`=1) OR (`CreatureID`=98949 AND `ID`=1) OR (`CreatureID`=98810 AND `ID`=1) OR (`CreatureID`=98521 AND `ID`=1) OR (`CreatureID`=98538 AND `ID`=1) OR (`CreatureID`=98368 AND `ID`=1) OR (`CreatureID`=98370 AND `ID`=1) OR (`CreatureID`=98366 AND `ID`=1) OR (`CreatureID`=120215 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(102095, 1, 109606, 0, 0, 0, 0, 0, 0, 0, 0), -- Risen Lancer
(98706, 1, 128191, 0, 0, 63743, 0, 0, 0, 0, 0), -- Commander Shemdah'sohn
(102788, 1, 125797, 0, 0, 0, 0, 0, 0, 0, 0), -- Felspite Dominator
(102094, 1, 109637, 0, 0, 0, 0, 0, 0, 0, 0), -- Risen Swordsman
(98691, 1, 15215, 0, 0, 53300, 0, 0, 0, 0, 0), -- Risen Scout
(98243, 1, 87510, 0, 0, 0, 0, 0, 0, 0, 0), -- Champion écorchâme
(112725, 1, 116547, 0, 0, 133265, 0, 0, 0, 0, 0), -- Kalyndras
(98696, 1, 128956, 0, 0, 132243, 0, 0, 0, 0, 0), -- Illysanna Ravencrest
(98275, 1, 0, 0, 0, 0, 0, 0, 36613, 0, 0), -- Risen Archer
(98970, 1, 65483, 0, 0, 0, 0, 0, 0, 0, 0), -- Latosius
(98965, 1, 132470, 0, 0, 0, 0, 0, 0, 0, 0), -- Kur'talos Ravencrest
(98949, 1, 128519, 0, 0, 0, 0, 0, 0, 0, 0), -- Smashspite the Hateful
(98810, 1, 118993, 0, 0, 119402, 0, 0, 0, 0, 0), -- Wrathguard Bladelord
(98521, 1, 116571, 0, 0, 0, 0, 0, 0, 0, 0), -- Lord Etheldrin Ravencrest
(98538, 1, 29437, 0, 0, 29437, 0, 0, 0, 0, 0), -- Lady Velandras Ravencrest
(98368, 1, 13182, 0, 0, 54932, 0, 0, 0, 0, 0), -- Ghostly Protector
(98370, 1, 30012, 0, 0, 0, 0, 0, 0, 0, 0), -- Ghostly Councilor
(98366, 1, 40408, 0, 0, 0, 0, 0, 0, 0, 0), -- Ghostly Retainer
(120215, 1, 28067, 0, 0, 0, 0, 0, 0, 0, 0); -- Archmage Khadgar


DELETE FROM `gossip_menu` WHERE (`MenuId`=20737 AND `TextID`=31129);
INSERT INTO `gossip_menu` (`MenuId`, `TextID`) VALUES
(20737, 31129); -- 101054 (Soul of Ravencrest)

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=20737 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(20737, 0, 0, 'We''re ready to leave now.', 0);






UPDATE `creature_template` SET `gossip_menu_id`=20737, `minlevel`=112, `maxlevel`=112, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=101054; -- Soul of Ravencrest
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=100861; -- Kur'talos Ravencrest
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=102095; -- Risen Lancer
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=111706; -- Boulder
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=98681; -- Rook Spinner
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=2048 WHERE `entry`=98706; -- Commander Shemdah'sohn
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98542; -- Amalgam of Souls
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102788; -- Felspite Dominator
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=102781; -- Fel Bat Pup
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `speed_walk`=1.6, `speed_run`=1.571429, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=102094; -- Risen Swordsman
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=101839; -- Risen Companion
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=103857; -- Fel Bat
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=98691; -- Risen Scout
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=98243; -- Champion écorchâme
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=98280; -- Risen Arcanist
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=112725; -- Kalyndras
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32768, `unit_flags2`=2097152, `VehicleId`=4490 WHERE `entry`=98696; -- Illysanna Ravencrest
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=98275; -- Risen Archer
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98970; -- Latosius
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98965; -- Kur'talos Ravencrest
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=4, `unit_flags`=32832, `unit_flags2`=2099200, `VehicleId`=4507 WHERE `entry`=98949; -- Smashspite the Hateful
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=98900; -- Wyrmtongue Trickster
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2099200 WHERE `entry`=98201; -- Enraged Soul
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=103102; -- Lost Soul
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=98810; -- Wrathguard Bladelord
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98677; -- Rook Spiderling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98813; -- Bloodscent Felhound
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98521; -- Lord Etheldrin Ravencrest
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=103662; -- Secret Door Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=98792; -- Wyrmtongue Scavenger
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=4196352 WHERE `entry`=100759; -- Fel Bat
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98538; -- Lady Velandras Ravencrest
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=98368; -- Ghostly Protector
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=98362; -- Troubled Soul
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=98370; -- Ghostly Councilor
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=98366; -- Ghostly Retainer
UPDATE `creature_template` SET `unit_flags`=33554688 WHERE `entry`=54638; -- Generic Bunny
UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=40438; -- Steamwheedle Shyster
UPDATE `creature_template` SET `minlevel`=109, `maxlevel`=109 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111 WHERE `entry`=101846; -- Nomi
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2890, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=120215; -- Archmage Khadgar
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=104, `maxlevel`=104 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=106, `maxlevel`=106 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=104, `maxlevel`=104 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `minlevel`=105, `maxlevel`=105 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=113646; -- Marcheur du bosquet contaminé

SET @GROUP_ID := 0;
SET @ID := 0;

DELETE FROM `creature_text` WHERE `CreatureID` IN (98542, 98696, 98706, 98792, 98810, 98900, 98949, 98965, 98970, 99857);
INSERT INTO `creature_text` (`CreatureID`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `BroadcastTextId`, `comment`) VALUES
(98542, @GROUP_ID+0, @ID+0, 'Consume! Devour!', 14, 0, 100, 0, 0, 54518, 0, 'Amalgam of Souls'),
(98542, @GROUP_ID+1, @ID+0, 'The harvest has come!', 14, 0, 100, 0, 0, 54516, 0, 'Amalgam of Souls to Player'),
(98542, @GROUP_ID+2, @ID+0, 'Leave this meager vessel, and join us...', 14, 0, 100, 0, 0, 54564, 0, 'Amalgam of Souls to Player'),
(98542, @GROUP_ID+3, @ID+0, 'I feed on your essence...', 14, 0, 100, 0, 0, 54522, 0, 'Amalgam of Souls'),
(98696, @GROUP_ID+0, @ID+0, 'We will bury you here, fools.', 14, 0, 100, 0, 0, 54515, 0, 'Illysanna Ravencrest'),
(98696, @GROUP_ID+1, @ID+0, 'You can not escape.', 14, 0, 100, 0, 0, 54561, 0, 'Illysanna Ravencrest to Player'),
(98696, @GROUP_ID+2, @ID+0, 'The hunt is eternal...', 14, 0, 100, 0, 0, 54513, 0, 'Illysanna Ravencrest'),
(98696, @GROUP_ID+3, @ID+0, 'No! I can see now... betrayed...', 14, 0, 100, 0, 0, 54514, 0, 'Illysanna Ravencrest to Player'),
(98706, @GROUP_ID+0, @ID+0, 'Brothers and Sisters, the invaders come for us. Repel them! Attack!', 14, 0, 100, 0, 0, 0, 0, 'Commander Shemdah''sohn to Risen Archer'),
(98792, @GROUP_ID+0, @ID+0, 'Ha! We''ll get ''em wit'' these big rocks!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),
(98792, @GROUP_ID+1, @ID+0, 'Ahh! They coming! RUN!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),
(98792, @GROUP_ID+2, @ID+0, 'Graa.... Ooh... oooWAAAAAHHHH!!!!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),
(98792, @GROUP_ID+3, @ID+0, 'AHHH! WE SORRY! WE PROMISE!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Scavenger to Player'),
(98810, @GROUP_ID+0, @ID+0, '%s becomes enraged!', 16, 0, 100, 0, 0, 0, 0, 'Wrathguard Bladelord'),
(98900, @GROUP_ID+0, @ID+0, 'Ok! We definitely got ''em this time!', 14, 0, 100, 0, 0, 0, 0, 'Wyrmtongue Trickster to Player'),
(98949, @GROUP_ID+0, @ID+0, 'I will paint this keep with your blood!', 14, 0, 100, 0, 0, 54504, 0, 'Smashspite the Hateful'),
(98949, @GROUP_ID+1, @ID+0, 'Tremble beneath me.', 14, 0, 100, 0, 0, 54501, 0, 'Smashspite the Hateful'),
(98949, @GROUP_ID+2, @ID+0, 'But... I can''t... lose...', 14, 0, 100, 0, 0, 54636, 0, 'Smashspite the Hateful to Player'),
(98965, @GROUP_ID+0, @ID+0, 'Fiends, you shall never have our world!', 14, 0, 100, 0, 0, 54536, 0, 'Kur''talos Ravencrest'),
(98965, @GROUP_ID+1, @ID+0, 'I shall cleave you in twain!', 14, 0, 100, 0, 0, 54526, 0, 'Kur''talos Ravencrest to Player'),
(98970, @GROUP_ID+0, @ID+0, 'Burn away!', 14, 0, 100, 0, 0, 54539, 0, 'Latosius'),
(99857, @GROUP_ID+0, @ID+0, 'I... understand now. You... you must find Kur''talos. You must put a stop to this.', 12, 0, 100, 0, 0, 54558, 0, 'Lord Etheldrin Ravencrest to Player');

INSERT IGNORE INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(107772, 234590, 0, 0),
(113901, 234595, 0, 0),
(116408, 231849, 0, 0),
(116419, 231849, 0, 0),
(116420, 231849, 0, 0),
(92438, 103583, 0, 0),
(112947, 234593, 0, 0),
(68239, 75648, 0, 0);


UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100994; -- Cloud of Hypnosis
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99887; -- Shadowy Tear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99611; -- Dantalionax
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101054; -- Soul of Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100861; -- Kur'talos Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102095; -- Risen Lancer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101923; -- Wyrmtongue Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111706; -- Boulder
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121643; -- Flame Rift
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108452; -- Infernal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98681; -- Rook Spinner
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98706; -- Commander Shemdah'sohn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99426; -- Staellis Rivermoor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99858; -- Lady Velandras Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99857; -- Lord Etheldrin Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99090; -- Soul Echoes Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=94584; -- Unstable Tear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108493; -- Chaos Tear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98542; -- Amalgam of Souls
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102788; -- Felspite Dominator
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102781; -- Fel Bat Pup
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=102094; -- Risen Swordsman
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103857; -- Fel Bat
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101839; -- Risen Companion
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98691; -- Risen Scout
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98696; -- Illysanna Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112725; -- Kalyndras
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98280; -- Risen Arcanist
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101549; -- Arcane Minion
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98243; -- Champion écorchâme
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98275; -- Risen Archer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98949; -- Smashspite the Hateful
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98970; -- Latosius
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98965; -- Kur'talos Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98900; -- Wyrmtongue Trickster
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98201; -- Enraged Soul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103102; -- Lost Soul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98810; -- Wrathguard Bladelord
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98677; -- Rook Spiderling
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100759; -- Fel Bat
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98813; -- Bloodscent Felhound
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98792; -- Wyrmtongue Scavenger
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103662; -- Secret Door Stalker
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98521; -- Lord Etheldrin Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98538; -- Lady Velandras Ravencrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98370; -- Ghostly Councilor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98368; -- Ghostly Protector
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98362; -- Troubled Soul
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98366; -- Ghostly Retainer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96804; -- Hamaka
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96801; -- Kyunghee
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32252; -- Wanathan
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32251; -- Shokavis
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96803; -- Mimbihi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=58237; -- Tweek
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96960; -- High Arcanist Savor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97529; -- L’incroyable Zanzo
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113812; -- Randall Goldsprocket
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96841; -- Emeline Fizzlefry
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108401; -- Blacksmith Kyriel
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96840; -- Sabriana Sorrowgaze
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=68239; -- Carousel Wyvern
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93189; -- Mama Diggs
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110019; -- Bruiser Toppleblade
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32751; -- Backbiter
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97512; -- Chasseresse-dimensionnelle Kula
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110020; -- Bruiser Wrenchvolt
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96484; -- Clockwork Assistant
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106655; -- Arcanomancer Vridiel
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110018; -- Gazrix Gearlock
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97003; -- Sheddle Glossgleam
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92184; -- Imindril Spearsong
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=54638; -- Generic Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93188; -- Mongar
UPDATE `creature_template` SET `name`='Illnea Bloodthorn', `subname`='Blood Trader', `VerifiedBuild`=26124 WHERE `entry`=115264; -- Illnea Bloodthorn
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=26124 WHERE `entry`=40438; -- Steamwheedle Shyster
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92185; -- Braeg Stoutbeard
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32451; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32454; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96954; -- Nelur Lightsown
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120687; -- Violet Shadowmend
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96953; -- Ranger Eoss
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96959; -- Vinsun
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=77789; -- Blingtron 5000
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=7544; -- Jeune dragonnet cramoisi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97514; -- Danric l’Audacieux
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97493; -- Narestel Pâlétoile
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32725; -- Warmage Silva
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112947; -- Emilia Baumoon
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92438; -- Glaciela Rimebang
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92936; -- Aimee
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96957; -- Murgha the Tempered
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110621; -- Erika Page
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110623; -- Sunny
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110622; -- Trevor Page
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113775; -- Punchy Lou
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96809; -- Arille Azuregaze
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32639; -- Gnimo
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32638; -- Hakmud of Argus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106843; -- Prince Farondis
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96834; -- Fabioso the Fabulous
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97005; -- Debbi Moore
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96835; -- Grindle Firespark
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96808; -- Sandra Bartan
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=116420; -- Glowing Blue Gem
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112007; -- Mel Lynchen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=116419; -- Glowing Green Gem
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=116408; -- Glowing Red Gem
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97863; -- Bonegrim
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112456; -- Rachele
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113900; -- Liyana
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113901; -- Crixa
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96952; -- Hahna Moonscrest
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96956; -- Pathstalker Rislar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=17213; -- Broom
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32494; -- Dalaran Child
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96812; -- Elizabeth Ross
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=125261; -- Bran Buckbeard
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112437; -- Roscoe
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112012; -- Sir Jonathan Trueheart
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96781; -- Kizi Copperclip
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96807; -- Afsaneh Asrar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96198; -- Catriona Macrae
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=118524; -- Dalaran Crystal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=43359; -- ELM General Purpose Bunny Infinite Hide Body
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97692; -- Frère de la Lumière
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97725; -- Prêtresse d’Élune
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107590; -- Mayla Highmountain
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=34527; -- Dave's Industrial Light and Magic Bunny (Small)
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109739; -- Tyrande Whisperwind
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=72587; -- VFX Bunny
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97767; -- Prêtresse maléficieuse
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106951; -- Advisor Stillwater
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=99350; -- Shannon Noel
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97792; -- Prêtre du soleil
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107772; -- Ol' Toomba
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=116175; -- Karam Magespear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96805; -- Mato
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96811; -- Andrew Matthews
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119486; -- Apothecary Lee
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110409; -- Credit - Portal Taken
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107587; -- "The Hammer of Khaz'goroth" Teleport Used Quest Kill Credit
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106815; -- "The Tidestone of Golganneth" Teleport Used Quest Kill Credit ELM
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119272; -- Sarah the Savage
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97001; -- Orton Bennet
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96958; -- Summoner Calwen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96955; -- Matron Ossela
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=110642; -- Fizzi Liverzapper
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96806; -- Amisi Azuregaze
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=119487; -- Talia Direhorn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96810; -- Archivist Betha
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96827; -- Adorean Lew
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=105904; -- Raven
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96828; -- Bitty Frostflinger
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96785; -- Christi Stockton
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96782; -- Lucian Trias
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112545; -- Zariya
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96837; -- Babagahnoosh the Grumpy
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112543; -- Khronus Lightwarden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96784; -- Fialla Sweetberry
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96836; -- Magus Fansy Goodbringer
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106548; -- Hati
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93536; -- Awilo Lon'gomba
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96813; -- Aludane Whitecloud
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96797; -- Nargut
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101846; -- Nomi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=93537; -- Misensi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=112847; -- Bewdley
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96796; -- Uda the Beast
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109554; -- Altius Maximus
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=26124 WHERE `entry`=45340; -- Jeune raptor fossilisé
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96798; -- Rhukah
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96802; -- Umbiwa
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109390; -- Annie
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=108076; -- "Move Like No Other" Lan'dalock's Area Trigger Quest POI Blob
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=109387; -- Beck
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=114732; -- Winnie
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=100324; -- Hati
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96799; -- Abohba
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111273; -- Lowland Manashell
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=50138; -- Karoma
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120418; -- Havi
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120413; -- Rensar Greathoof
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103630; -- Elite Forsaken Guard
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120420; -- Iron-Body Ponshu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120415; -- Highlord Darion Mograine
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120417; -- Meryl Felstorm
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120423; -- Emmarel Shadewarden
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120421; -- Ritssyn Flamescowl
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=111246; -- Archmage Timear
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120424; -- Alonsus Faol
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106262; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96780; -- Aerith Primrose
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120416; -- Lord Jorach Ravenholdt
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=103626; -- Forsaken Guard
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120419; -- Kor'vas Bloodthorn
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120422; -- Lady Liadrin
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97141; -- Koraud
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96788; -- Jessa Weaver
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96641; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96787; -- Warcaster Fanoraithe
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=120412; -- Farseer Nobundo
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106528; -- Flower Pot
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96636; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=106263; -- Earthen Ring Shaman
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=36979; -- Mini K.T.
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31689; -- Gnome Diver
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96842; -- Archmage Tenaj
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31735; -- Cosmetic Pig
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96592; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=34330; -- Jones
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96843; -- Darthalia Ebonscorch
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=27047; -- Invisible Stalker (Floating Only)
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31741; -- Cosmetic Rabbit
UPDATE `creature_template` SET `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags2`=32768, `HealthModifier`=200, `ManaModifier`=80, `VerifiedBuild`=26124 WHERE `entry`=120215; -- Archmage Khadgar
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31740; -- Cosmetic Turtle
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31728; -- Cosmetic Cat Set 1/2
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31796; -- Cosmetic Worg Pup
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98724; -- Giada Goldleash
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=115287; -- Serr'ah
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96639; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96830; -- Linda Ann Kastinglow
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96786; -- Archmage Celindra
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96829; -- Arcanist Alec
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96778; -- Aemara
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96507; -- Tassia Whisperglen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96779; -- Dagna Flintlock
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32642; -- Mojodishu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=32641; -- Drix Blackwrench
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96635; -- Stabled Hunter Pet
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31729; -- Cosmetic Cat Set 2/2
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96777; -- Jarold Puller
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31710; -- Cosmetic Black Kingsnake
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113780; -- Innocent Jim
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96479; -- Breanni
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=107326; -- Draemus
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31714; -- Cosmetic Ribbon Snake
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=124679; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121602; -- Manapoof
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96983; -- Dalaran Citizen
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=96643; -- Stabled Hunter Pet
UPDATE `creature_template` SET `type`=12, `VerifiedBuild`=26124 WHERE `entry`=128158; -- Ciaileron atteint par la corruption
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=92489; -- Mei Francis
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31730; -- Cosmetic Frog
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=25058; -- Fuzz
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=113783; -- Savash Windcalller
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31742; -- Cosmetic Prairie Dog
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=121541; -- Ban Lu
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=31719; -- Cosmetic Frenzy
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=97212; -- 7.0 Dalaran - Shopkeeper - Dummy
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=104091; -- Gardien du Kirin Tor
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=101436; -- Wormhole
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=78217; -- Infernal
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98723; -- Tiffy Trapspring
UPDATE `creature_template` SET `VerifiedBuild`=26124 WHERE `entry`=98725; -- Lio the Lioness


UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=99611 AND `Idx`=0); -- Dantalionax
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=102095 AND `Idx`=0); -- Risen Lancer
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98542 AND `Idx`=0); -- Amalgam of Souls
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=102094 AND `Idx`=0); -- Risen Swordsman
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98691 AND `Idx`=0); -- Risen Scout
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98280 AND `Idx`=0); -- Risen Arcanist
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98243 AND `Idx`=0); -- Champion écorchâme
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98275 AND `Idx`=0); -- Risen Archer
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98970 AND `Idx`=4); -- Latosius
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98970 AND `Idx`=3); -- Latosius
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98970 AND `Idx`=2); -- Latosius
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98970 AND `Idx`=1); -- Latosius
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98970 AND `Idx`=0); -- Latosius
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98813 AND `Idx`=1); -- Bloodscent Felhound
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98813 AND `Idx`=0); -- Bloodscent Felhound
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98370 AND `Idx`=0); -- Ghostly Councilor
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98368 AND `Idx`=0); -- Ghostly Protector
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=98366 AND `Idx`=0); -- Ghostly Retainer
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=111273 AND `Idx`=2); -- Lowland Manashell
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=111273 AND `Idx`=1); -- Lowland Manashell
UPDATE `creature_questitem` SET `VerifiedBuild`=26124 WHERE (`CreatureEntry`=111273 AND `Idx`=0); -- Lowland Manashell

DELETE FROM `gameobject_template` WHERE `entry` IN (246505 /*Small Red Button*/, 246410 /*Ancient Chair*/, 246409 /*Ancient Chair*/, 247400 /*Black Rook Hold Dungeon - Boss 2 - Door 3*/, 247401 /*Black Rook Hold Dungeon - Boss 2 - Door 2*/, 247399 /*Black Rook Hold Dungeon - Boss 2 - Door 1*/, 245079 /*Doodad_7NE_Blackrook_Portcullis001*/, 247498 /*Black Rook Hold Dungeon - Boss 4 - Door*/, 245080 /*Doodad_7NE_Blackrook_Portcullis002*/, 247402 /*Black Rook Hold Dungeon - Boss 3 - Door*/, 245104 /*Black Rook Hold Dungeon - Boss 3 Post Door*/, 245105 /*Doodad_7NE_Blackrook_Portcullis003*/, 253921 /*Rusty Gate*/, 247407 /*Black Rook Hold Dungeon - Boss 1 - Post Boss Door*/, 247404 /*Black Rook Hold Dungeon - Boss 1 - Door 2*/, 247405 /*Black Rook Hold Dungeon - Boss 1 - Door 3*/, 247403 /*Black Rook Hold Dungeon - Boss 1 - Door 1*/, 247406 /*Black Rook Hold Dungeon - Boss 1 - Door 4*/, 252327 /*Blackrook Hold Dungeon - Entrance - Left Door*/, 252328 /*Blackrook Hold Dungeon - Entrance - Right Door*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(246505, 1, 339, 'Small Red Button', '', '', '', 0.3273501, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Small Red Button
(246410, 7, 31330, 'Ancient Chair', '', '', '', 1.324154, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ancient Chair
(246409, 7, 31330, 'Ancient Chair', '', '', '', 1.324154, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Ancient Chair
(247400, 0, 32125, 'Black Rook Hold Dungeon - Boss 2 - Door 3', '', '', '', 1.1935, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 2 - Door 3
(247401, 0, 32125, 'Black Rook Hold Dungeon - Boss 2 - Door 2', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 2 - Door 2
(247399, 0, 32125, 'Black Rook Hold Dungeon - Boss 2 - Door 1', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 2 - Door 1
(245079, 0, 29598, 'Doodad_7NE_Blackrook_Portcullis001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7NE_Blackrook_Portcullis001
(247498, 0, 32201, 'Black Rook Hold Dungeon - Boss 4 - Door', '', '', '', 0.7506399, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 4 - Door
(245080, 0, 29598, 'Doodad_7NE_Blackrook_Portcullis002', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7NE_Blackrook_Portcullis002
(247402, 0, 32126, 'Black Rook Hold Dungeon - Boss 3 - Door', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 3 - Door
(245104, 0, 29598, 'Black Rook Hold Dungeon - Boss 3 Post Door', '', '', '', 0.8737047, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 3 Post Door
(245105, 0, 29598, 'Black Rook Hold Dungeon - Boss 3 Post Door 2', '', '', '', 0.8737048, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Doodad_7NE_Blackrook_Portcullis003
(253921, 0, 32201, 'Rusty Gate', '', '', '', 0.7438648, 0, 0, 0, 0, 0, 0, 0, 43617, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Rusty Gate
(247407, 0, 32128, 'Black Rook Hold Dungeon - Boss 1 - Post Boss Door', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Post Boss Door
(247404, 0, 32127, 'Black Rook Hold Dungeon - Boss 1 - Door 2', '', '', '', 1.515201, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 2
(247405, 0, 32127, 'Black Rook Hold Dungeon - Boss 1 - Door 3', '', '', '', 1.515201, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 3
(247403, 0, 32127, 'Black Rook Hold Dungeon - Boss 1 - Door 1', '', '', '', 1.515201, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 1
(247406, 0, 32127, 'Black Rook Hold Dungeon - Boss 1 - Door 4', '', '', '', 1.515201, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Black Rook Hold Dungeon - Boss 1 - Door 4
(252327, 0, 32201, 'Blackrook Hold Dungeon - Entrance - Left Door', '', '', '', 0.8732671, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124), -- Blackrook Hold Dungeon - Entrance - Left Door
(252328, 0, 32201, 'Blackrook Hold Dungeon - Entrance - Right Door', '', '', '', 0.8732671, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26124); -- Blackrook Hold Dungeon - Entrance - Right Door

UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=205044; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=205038; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=205037; -- Fire
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=205036; -- Stove
UPDATE `gameobject_template` SET `type`=3, `displayId`=35918, `castBarCaption`='Taking', `size`=1.2, `Data0`=43, `Data14`=96454, `Data16`=1, `Data30`=67598, `Data31`=1, `VerifiedBuild`=26124 WHERE `entry`=252266; -- Delayeth's Journal: The Jewels of the Isles
UPDATE `gameobject_template` SET `type`=10, `displayId`=30845, `size`=0.5772002, `Data3`=3000, `VerifiedBuild`=26124 WHERE `entry`=246669; -- Doodad_7KO_Kobold_SackSmall001
UPDATE `gameobject_template` SET `type`=9, `displayId`=15781, `Data0`=5411, `Data2`=1, `VerifiedBuild`=26124 WHERE `entry`=252385; -- Torn Page
UPDATE `gameobject_template` SET `type`=3, `displayId`=36036, `IconName`='openhandglow', `castBarCaption`='Retrieving', `Data0`=1691, `Data4`=1, `Data5`=1, `Data14`=23645, `Data16`=1, `Data30`=67966, `Data31`=1, `VerifiedBuild`=26124 WHERE `entry`=252878; -- The Age of Galakrond
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=243007; -- Heathrow Cellar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=252247; -- Instance Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259397; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259396; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259398; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250342; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250341; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259391; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250345; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250343; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250344; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250356; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251105; -- Portal out of the Vault
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259392; -- Stool
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=250314; -- Bench
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=250316; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242202; -- Lamp
UPDATE `gameobject_template` SET `type`=3, `displayId`=34276, `IconName`='questinteract', `size`=3, `Data0`=1635, `Data30`=69073, `Data31`=1, `VerifiedBuild`=26124 WHERE `entry`=250576; -- Powerful Mana Gem
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=250320; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=250321; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259395; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259393; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259394; -- Chair
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=250318; -- Chair
UPDATE `gameobject_template` SET `name`='Guild Vault', `VerifiedBuild`=26124 WHERE `entry`=245833; -- Guild Vault
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=250317; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242229; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259304; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259305; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268045; -- Aftermath of the Second War
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259306; -- Chair
UPDATE `gameobject_template` SET `name`='The Bank of Dalaran', `VerifiedBuild`=26124 WHERE `entry`=242199; -- The Bank of Dalaran
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242230; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=181055; -- Hanging, Streamer x3 - Val
UPDATE `gameobject_template` SET `name`='Bench', `VerifiedBuild`=26124 WHERE `entry`=250313; -- Bench
UPDATE `gameobject_template` SET `type`=3, `displayId`=36321, `Data3`=1, `Data30`=71646, `VerifiedBuild`=26124 WHERE `entry`=268087; -- The World Tree and the Emerald Dream
UPDATE `gameobject_template` SET `name`='Alard''s Quenching Trough', `VerifiedBuild`=26124 WHERE `entry`=241512; -- Alard's Quenching Trough
UPDATE `gameobject_template` SET `name`='Alard''s Anvil', `VerifiedBuild`=26124 WHERE `entry`=241511; -- Alard's Anvil
UPDATE `gameobject_template` SET `name`='Portal to Silvermoon', `VerifiedBuild`=26124 WHERE `entry`=246004; -- Portal to Silvermoon
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246260; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=194115; -- Shoeshine Seat
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268078; -- The Lich King Triumphant
UPDATE `gameobject_template` SET `name`='Alard''s Forge', `VerifiedBuild`=26124 WHERE `entry`=241453; -- Alard's Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246261; -- Chair
UPDATE `gameobject_template` SET `name`='Portal to Thunder Bluff', `VerifiedBuild`=26124 WHERE `entry`=245999; -- Portal to Thunder Bluff
UPDATE `gameobject_template` SET `name`='Alard''s Workbench', `VerifiedBuild`=26124 WHERE `entry`=241513; -- Alard's Workbench
UPDATE `gameobject_template` SET `name`='Chair', `VerifiedBuild`=26124 WHERE `entry`=259350; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=266354; -- Basic Campfire
UPDATE `gameobject_template` SET `type`=3, `displayId`=10196, `size`=0.75, `Data3`=1, `Data30`=71619, `VerifiedBuild`=26124 WHERE `entry`=268053; -- Ironforge - the Awakening of the Dwarves
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242043; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259416; -- Stool
UPDATE `gameobject_template` SET `name`='Mailbox', `VerifiedBuild`=26124 WHERE `entry`=242201; -- Mailbox
UPDATE `gameobject_template` SET `name`='The Bank of Dalaran', `VerifiedBuild`=26124 WHERE `entry`=242198; -- The Bank of Dalaran
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259415; -- Stool
UPDATE `gameobject_template` SET `name`='Portal to Undercity', `VerifiedBuild`=26124 WHERE `entry`=246000; -- Portal to Undercity
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250300; -- Bench
UPDATE `gameobject_template` SET `name`='Portal to Orgrimmar', `Data0`=247057, `Data6`=1, `VerifiedBuild`=26124 WHERE `entry`=246001; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241963; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242218; -- Well
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259303; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268074; -- The Guardians of Tirisfal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246007; -- Portal to Vale of Eternal Blossoms
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241958; -- The Legerdemain Lounge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242200; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250458; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268051; -- Empires' Fall
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268044; -- Aegwynn and the Dragon Hunt
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250298; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241944; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=254236; -- Harp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259339; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=266736; -- Levia's Research Journal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250477; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250479; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=267991; -- The Birth of the Lich King
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250478; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250480; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250485; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246465; -- Tidestone of Golganneth
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=266618; -- Mail Pile
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=266619; -- A Mysterious Note
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=235098; -- Skull Candle
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=235100; -- Bones
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=235099; -- Crystal Dust
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241950; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250459; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241922; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268049; -- Charge of the Dragonflights
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259337; -- Coffee Grinder
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250494; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241921; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250492; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250493; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250472; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259335; -- Coffee Press
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259295; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250471; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250487; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=266851; -- Wand of Simulated Life
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259294; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=266705; -- Willem West's Table
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=266761; -- Research Notes
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250214; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250497; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251286; -- Illidari Gateway
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244562; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246463; -- Hammer of Khaz'goroth
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241920; -- Barbershop Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250473; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=252331; -- Traveller Pepe
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259293; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250299; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250495; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250496; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250436; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242237; -- Barbershop
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=269989; -- Mel's Journal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244950; -- Dusty Rug
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259336; -- Coffee Grinder
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250490; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250484; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250491; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259338; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241964; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268059; -- Rise of the Blood Elves
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250481; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250215; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259292; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241945; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250483; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251883; -- Archmage Vargoth's Retreat
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251579; -- Illidari Gateway
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=245249; -- Banner
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=224813; -- Garrison Building Alliance Pet Stable V1
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246944; -- Obliterum Forge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246466; -- Tears of Elune
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251992; -- The Aegis of Aggramar
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259307; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251033; -- Facade
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=252245; -- Instance Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244560; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244561; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259308; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242174; -- Violet Hold Gate
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241480; -- Sword
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250463; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259265; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250470; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=148502; -- Test Object
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268048; -- Beyond the Dark Portal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250482; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250358; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250297; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250499; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250631; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259271; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259289; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259291; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259270; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250500; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259269; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250357; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259290; -- Beanbag
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=270855; -- Inconspicuous Note
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259264; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250460; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250461; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259267; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250474; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244537; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244534; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=244536; -- Teleport Pad
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242177; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250498; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250359; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=269967; -- Ironbound Crate
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250328; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250360; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250462; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250329; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242236; -- One More Glass
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268043; -- Icecrown and the Frozen Throne
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250332; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250355; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250352; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241957; -- The Legerdemain Lounge
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250331; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241954; -- Dalaran Visitor Center
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250354; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250351; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250353; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250336; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259273; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250349; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250348; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242235; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241948; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259272; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250350; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250340; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250346; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259266; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250347; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241969; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250334; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242176; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259835; -- Fireplace
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246664; -- Test Kitchen Results
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250339; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=271739; -- Nomi's Test Kitchen
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259276; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259278; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259279; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259277; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242225; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=246710; -- Nomi's Silver Mackerel
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250333; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259275; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259280; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259426; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259274; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250338; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242224; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242231; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250335; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242232; -- The Filthy Animal
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242233; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250337; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=278457; -- Warchief's Command Board
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241949; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242226; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251594; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=268073; -- The Founding of Quel'Thalas
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251593; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251592; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242227; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251311; -- Portal to the Maelstrom
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251580; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251581; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242223; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251312; -- Shaman Stones
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251624; -- Drape
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251582; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251585; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242234; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250449; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250451; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251584; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=251595; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259281; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242228; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250450; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241955; -- The Hunter's Reach
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250467; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250469; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241970; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259283; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250452; -- Stool
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241947; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=250468; -- Chair
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=259282; -- Bench
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242172; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241946; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=181017; -- Hanging, Streamer - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241971; -- Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=187668; -- Hanging, Tall/Thin, Small - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241956; -- Magical Menagerie
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=241967; -- Mailbox
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=181016; -- Standing, Exterior, Medium - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=187575; -- Hanging, Square, Small - Val
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242169; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=242170; -- Wall Lamp
UPDATE `gameobject_template` SET `VerifiedBuild`=26124 WHERE `entry`=181018; -- Hanging, Tall/Thin, Medium - Val

DELETE FROM `gameobject_questitem` WHERE (`GameObjectEntry`=252878 AND `Idx`=0);
INSERT INTO `gameobject_questitem` (`GameObjectEntry`, `Idx`, `ItemId`, `VerifiedBuild`) VALUES
(252878, 0, 140132, 26124); -- The Age of Galakrond

UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=252266 AND `Idx`=0); -- Delayeth's Journal: The Jewels of the Isles
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=250576 AND `Idx`=0); -- Powerful Mana Gem
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=266619 AND `Idx`=0); -- A Mysterious Note
UPDATE `gameobject_questitem` SET `VerifiedBuild`=26124 WHERE (`GameObjectEntry`=246710 AND `Idx`=0); -- Nomi's Silver Mackerel

DELETE FROM `npc_text` WHERE `ID`=31129;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(31129, 1, 0, 0, 0, 0, 0, 0, 0, 125865, 0, 0, 0, 0, 0, 0, 0, 26124); -- 31129


