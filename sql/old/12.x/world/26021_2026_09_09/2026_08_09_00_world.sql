SET @CGUID := 10006983; -- Need 1
SET @OGUID := 10001996; -- Need 7

-- Quest
UPDATE `creature_queststarter` SET `VerifiedBuild`=68887 WHERE `id`=252312 AND `quest`=92572;
UPDATE `creature_questender` SET `VerifiedBuild`=68887 WHERE `id`=252312 AND `quest`=92572;

DELETE FROM `quest_offer_reward` WHERE `ID`=92572;
INSERT INTO `quest_offer_reward` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `RewardText`, `VerifiedBuild`) VALUES
(92572, 1, 0, 0, 0, 0, 0, 0, 0, 'Oh my, the crate you describe does indeed seem quite great. The joy of placing them will know no bounds.\n\nThank you for finding this! For your time, might I present you with this rare piece from our collection.\n\nIt is no ordinary barrel, to be sure! I hope that you enjoy it thoroughly.', 68887); -- Furniture Favor

-- Creature
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 252312, 1, 1637, 11386, '0', '0', 0, 0, 0, 1454.7586669921875, -4426.79541015625, 25.53692436218261718, 1.721196174621582031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68887); -- Second Chair Pawdo (Area: -Unknown- - Difficulty: 0) CreateObject1

-- Gameobject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+6;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 576463, 1, 1637, 11386, '0', '0', 0, 1458.2586669921875, -4425.6630859375, 26.3734130859375, 2.192635536193847656, 0.430280685424804687, -0.21508693695068359, 0.781162261962890625, 0.397971987724304199, 120, 255, 1, 68887), -- Fishing Pole (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+1, 576391, 1, 1637, 11386, '0', '0', 0, 1452.467041015625, -4426.87841796875, 25.45359039306640625, 1.449574708938598632, 0, 0, 0.662976264953613281, 0.748640418052673339, 120, 255, 1, 68887), -- Bookshelf (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+2, 576392, 1, 1637, 11386, '0', '0', 0, 1458.1961669921875, -4425.8505859375, 26.16607284545898437, 4.14076089859008789, 0, 0, -0.87778186798095703, 0.479060530662536621, 120, 255, 1, 68887), -- Keg (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+3, 576393, 1, 1637, 11386, '0', '0', 0, 1452.3941650390625, -4426.955078125, 26.62620353698730468, 1.430541396141052246, 0, 0, 0.655821800231933593, 0.754915714263916015, 120, 255, 1, 68887), -- Coil (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+4, 576394, 1, 1637, 11386, '0', '0', 0, 1454.5989990234375, -4425.3056640625, 25.45358657836914062, 1.684096932411193847, 0, 0, 0.746008872985839843, 0.665935993194580078, 120, 255, 1, 68887), -- Table (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+5, 576395, 1, 1637, 11386, '0', '0', 0, 1457.4288330078125, -4424.548828125, 26.15361404418945312, 4.14076089859008789, 0, 0, -0.87778186798095703, 0.479060530662536621, 120, 255, 1, 68887), -- Chandelier (Area: -Unknown- - Difficulty: 0) CreateObject1
(@OGUID+6, 576396, 1, 1637, 11386, '0', '0', 0, 1458.1961669921875, -4425.8505859375, 25.45359992980957031, 2.442975282669067382, 0, 0, 0.939609527587890625, 0.342248320579528808, 120, 255, 1, 68887); -- Furniture Cart (Area: -Unknown- - Difficulty: 0) CreateObject1

-- Gameobject template addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (576396 /*Furniture Cart*/, 576463 /*Fishing Pole*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(576396, 1375, 0x0, 0, 0), -- Furniture Cart
(576463, 1375, 0x0, 0, 0); -- Fishing Pole

-- Creature difficulty update
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=68887 WHERE `DifficultyID`=0 AND `Entry`=252312;

-- Gossip update
UPDATE `creature_template_gossip` SET `VerifiedBuild`=68887 WHERE `CreatureID`=252312 AND `MenuID`=40669;

-- Vendor update
UPDATE `npc_vendor` SET `VerifiedBuild`=68887 WHERE (`entry`=252312 AND `item`=247915 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=247908 AND `ExtendedCost`=10726 AND `type`=1) OR (`entry`=252312 AND `item`=246487 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=246601 AND `ExtendedCost`=10727 AND `type`=1) OR (`entry`=252312 AND `item`=248116 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=256168 AND `ExtendedCost`=7827 AND `type`=1) OR (`entry`=252312 AND `item`=245259 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=252312 AND `item`=245655 AND `ExtendedCost`=10723 AND `type`=1);
