SET @DF_CGUID := 9003516;

SET @BFA_CGUID := 850892;
SET @BFA_OGUID := 502192;

-- Creature (Dragonflight)
DELETE FROM `creature` WHERE `guid` BETWEEN @DF_CGUID+0 AND @DF_CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@DF_CGUID+0, 198506, 0, 1519, 5154, '0', 0, 0, 0, 0, -8957.4599609375, 853.5242919921875, 105.4457550048828125, 4.250233650207519531, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999), -- Krenzen (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: )
(@DF_CGUID+1, 198509, 0, 1519, 5154, '0', 0, 0, 0, 0, -8958.453125, 850.638916015625, 105.4063339233398437, 5.002696990966796875, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48999), -- Berkeley (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@DF_CGUID+2, 198505, 0, 1519, 5154, '0', 0, 0, 0, 0, -8957.9423828125, 849.3524169921875, 105.2938156127929687, 2.111641645431518554, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999), -- Blue (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: )
(@DF_CGUID+3, 174146, 0, 1519, 5154, '0', 0, 0, 0, 1, -8988.44140625, 863.4149169921875, 105.75732421875, 5.188758373260498046, 120, 0, 0, 11277, 5751, 0, 0, 0, 0, 48999); -- Archivist Thomas (Area: Mage Quarter - Difficulty: 0) CreateObject1

-- Creature (Battle for Azeroth)
DELETE FROM `creature` WHERE `guid` BETWEEN @BFA_CGUID+0 AND @BFA_CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@BFA_CGUID+0, 158436, 0, 1519, 5154, '0', 0, 0, 0, 0, -8969.404296875, 840.77606201171875, 105.7334060668945312, 2.908312559127807617, 120, 0, 0, 2035, 0, 0, 0, 0, 0, 48999), -- Lisa Schaefer (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: )
(@BFA_CGUID+1, 158440, 0, 1519, 5154, '0', 0, 0, 0, 0, -8970.4794921875, 839.02606201171875, 105.7063140869140625, 1.87994086742401123, 120, 0, 0, 2035, 0, 0, 0, 0, 0, 48999), -- Mikey Schaefer (Area: Mage Quarter - Difficulty: 0) CreateObject1 (Auras: )
(@BFA_CGUID+2, 158753, 0, 1519, 5154, '0', 0, 0, 0, 0, -8971.16015625, 838.842041015625, 105.7097549438476562, 1.842674136161804199, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48999), -- Bella (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+3, 158463, 0, 1519, 5154, '0', 0, 0, 0, 0, -8974.29296875, 836.458984375, 105.5615615844726562, 3.827786922454833984, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48999), -- Wiley (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+4, 158755, 0, 1519, 5154, '0', 0, 0, 0, 0, -8969.0283203125, 839.109375, 105.6865615844726562, 2.347805023193359375, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48999), -- Rufus (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+5, 158456, 0, 1519, 5154, '0', 0, 0, 0, 0, -8969.4658203125, 841.19268798828125, 105.6865615844726562, 3.114154577255249023, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48999), -- Emma (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+6, 140407, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8987.8232421875, 827.24652099609375, 105.38824462890625, 1.498167634010314941, 120, 0, 0, 17621, 0, 0, 0, 0, 0, 48999), -- Stormwind City Clerk (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+7, 140403, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8988.3857421875, 830.02777099609375, 105.515625, 4.749882221221923828, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Displaced Gilnean Refugee (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+8, 140403, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8984.6142578125, 827.86456298828125, 105.61285400390625, 3.347713947296142578, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Displaced Gilnean Refugee (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+9, 140253, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8932.0009765625, 775.70941162109375, 88.6034088134765625, 0.509090721607208251, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+10, 140253, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8990.12890625, 830.72393798828125, 105.4895858764648437, 5.291107177734375, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+11, 140253, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8986.4033203125, 828.90625, 105.5572967529296875, 4.075306415557861328, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+12, 140253, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8990.048828125, 828.34552001953125, 105.359375, 5.735158920288085937, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_CGUID+13, 140253, 0, 1519, 5154, '0', 11595, 0, 0, 0, -8984.25, 830.029541015625, 105.6805572509765625, 3.796868801116943359, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999); -- Darnassian Refugee (Area: Mage Quarter - Difficulty: 0) CreateObject1

-- GameObjects (Battle for Azeroth)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @BFA_OGUID+0 AND @BFA_OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@BFA_OGUID+0, 322639, 0, 1519, 5154, '0', '0', 0, -8969.5673828125, 842.8524169921875, 105.6014328002929687, 5.101047515869140625, 0, 0, -0.55724906921386718, 0.830345392227172851, 120, 255, 1, 48999), -- [DNT] Dog Bowl (Area: Mage Quarter - Difficulty: 0) CreateObject1
(@BFA_OGUID+1, 335930, 0, 1519, 5154, '0', '0', 0, -8969.5537109375, 839.79339599609375, 105.6597137451171875, 5.17418670654296875, 0, 0, -0.52651786804199218, 0.850164055824279785, 120, 255, 1, 48999); -- Picnic Basket (scale x0.75) (Area: Mage Quarter - Difficulty: 0) CreateObject1

-- Creature Template
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198505; -- Blue
UPDATE `creature_template` SET `faction`=1732, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=198506; -- Krenzen
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=198509; -- Berkeley

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (158436, 158440, 158456, 158753, 174146);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(158436, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 158436 (Lisa Schaefer)
(158440, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 158440 (Mikey Schaefer)
(158456, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 158456 (Emma)
(158753, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 158753 (Bella)
(174146, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 174146 (Archivist Thomas)

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=174146 AND `MenuID`=26438);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(174146, 26438, 48999); -- Archivist Thomas

DELETE FROM `gossip_menu` WHERE (`MenuID`=26438 AND `TextID`=30675);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(26438, 30675, 48999); -- 174146 (Archivist Thomas)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=26438 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(52027, 26438, 0, 0, 'I want to experience the Battle for Lordaeron.', 205324, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 48999);

-- NPC SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (198509, 158456, 158753, 158755, 158463);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(198509, 224326, 1, 0),
(158456, 224326, 1, 0),
(158753, 224326, 1, 0),
(158755, 224326, 1, 0),
(158463, 224326, 1, 0);

-- Scaling & Model
DELETE FROM `creature_template_scaling` WHERE (`Entry`=198601 AND `DifficultyID`=0);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(198601, 0, 0, 0, 864, 48999);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=48999 WHERE (`DifficultyID`=0 AND `Entry` IN (149436,198071,149467,140407,1311,151937,149099,1310,158436,1141,3628,1347,1309,82564,1346,149616,84751,198505,1307,3627,148233,198506,84749,4078,158463,174146,140403,158755,150122,5567,85307,142668,85819,2708,23837,5566,84745,158753,85818,149626,89174,51677,142666,1308,2334,85817,5694,1300,1419,147741,5500,1314,149131,198096,103033,85816,5499,148124,149121,158456,2485,149445,5498,52408,198509,149124,331,158440,5497,1429));

DELETE FROM `creature_model_info` WHERE `DisplayID`=110254;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(110254, 0.601749539375305175, 1.5, 0, 48999);
