SET @LEGION_CGUID	:= 6006076; -- Set by TDB Team (Need 1 from the Legion expansion range)
SET @BFA_CGUID		:= 7003756; -- Set by TDB Team (Need 1 from the Battle for Azeroth expansion range)

SET @OGUID			:= 7000726; -- Set by TDB Team (Need 2 from the Battle for Azeroth expansion range)

-- Creature
UPDATE `creature` SET `zoneId`=1637, `VerifiedBuild`=68974 WHERE `guid`=310980; -- Frezza (Area: 0 - Difficulty: 0) CreateObject1

-- Legion creature spawn
DELETE FROM `creature` WHERE `guid`=@LEGION_CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@LEGION_CGUID+0, 130911, 1, 1637, 0, '0', '0', 0, 0, 0, 1847.935791015625, -4390.57275390625, 135.3160858154296875, 4.90349578857421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68974); -- Charles Gastly (Area: 0 - Difficulty: 0) CreateObject1

-- Battle for Azeroth creature spawn
DELETE FROM `creature` WHERE `guid`=@BFA_CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@BFA_CGUID+0, 141528, 1, 1637, 0, '0', '0', 0, 0, 0, 1844.4947509765625, -4389.32470703125, 135.3163299560546875, 4.533868312835693359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 68974); -- Clara Spelldriver (Area: 0 - Difficulty: 0) CreateObject1

-- Template addon
DELETE FROM `creature_template_addon` WHERE `entry`=141528;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(141528, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 141528 (Clara Spelldriver)

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=68974 WHERE `Entry`=141528 AND `DifficultyID`=0; -- 141528 (Clara Spelldriver) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x0, `VerifiedBuild`=68974 WHERE `Entry`=9564 AND `DifficultyID`=0; -- 9564 (Frezza) - 

-- Gameobject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 205056, 1, 1637, 5170, '0', '0', 0, 1838.7725830078125, -4388.72412109375, 135.2330169677734375, 5.570709228515625, 0, 0, -0.34875106811523437, 0.937215387821197509, 120, 255, 1, 68974), -- Construction Blockade (Area: Valley of Strength - Difficulty: 0) CreateObject1
(@OGUID+1, 293684, 1, 1637, 5170, '0', '0', 0, 1842.263916015625, -4389.0224609375, 135.2330169677734375, 0.286221921443939208, 0, 0, 0.142622947692871093, 0.989777088165283203, 120, 255, 1, 68974); -- Portal to Undercity (Area: Valley of Strength - Difficulty: 0) CreateObject1

-- Gossip
UPDATE `creature_template_gossip` SET `MenuID`=22952, `VerifiedBuild`=68974 WHERE  `CreatureID`=9564 AND `MenuID`=1969; -- Frezza

DELETE FROM `gossip_menu` WHERE `MenuID`=22952 AND `TextID`=35513;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(22952, 35513, 68974); -- 9564 (Frezza)

-- Gossip option
DELETE FROM `gossip_menu_option` WHERE `OptionID`=0 AND `MenuID`=22952;
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(22952, 49001, 0, 0, 'How can I get to Tirisfal Glades?', 159401, 0, 0, 22954, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 68974);

-- Vendor
DELETE FROM `npc_vendor` WHERE `entry`=130911 AND `item` IN (155909, 155910, 155907) AND `ExtendedCost`=0 AND `type`=1;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(130911, 3, 155909, 0, 0, 1, 0, 0, 68974), -- Bottled Stillwater
(130911, 2, 155910, 0, 0, 1, 0, 0, 68974), -- Tirisfal Sourdough
(130911, 1, 155907, 0, 0, 1, 0, 0, 68974); -- Undercity "Skull Shocker"

-- Spell target position
UPDATE `spell_target_position` SET `MapID`=2532, `PositionX`=1948.69, `PositionY`=-101.71, `PositionZ`=41.29, `VerifiedBuild`=68974 WHERE `ID`=121862;
