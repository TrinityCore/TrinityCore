SET @CGUID := 8000902;

SET @GGUID := 100189;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+19;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 169999, 2222, 10534, 0, '0', 0, 0, 0, 0, -4071.798583984375, -4771.1787109375, 6558.8759765625, 0.012648417614400386, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Aspirant's Crucible - Difficulty: 0)
(@CGUID+1, 169999, 2222, 10534, 13415, '0', 0, 0, 0, 0, -4649.65966796875, -5186.33349609375, 6591.97509765625, 0.913985133171081542, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Aspirant's Awakening - Difficulty: 0)
(@CGUID+2, 169999, 2222, 10534, 11014, '0', 0, 0, 0, 0, -4062.76220703125, -5188.986328125, 6577.92626953125, 0.766506731510162353, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: The Temple of Purity - Difficulty: 0)
(@CGUID+3, 169999, 2222, 10534, 0, '0', 0, 0, 0, 0, -3290.939208984375, -5255.94775390625, 6591.13037109375, 0.861362159252166748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Bastion - Difficulty: 0)
(@CGUID+4, 169999, 2222, 10534, 0, '0', 0, 0, 0, 0, -2643.17529296875, -5517.6005859375, 6565.99609375, 0.651634514331817626, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: The Temple of Purity - Difficulty: 0)
(@CGUID+5, 169999, 2222, 10534, 0, '0', 0, 0, 0, 0, -1913.80908203125, -4897.45654296875, 6641.77783203125, 1.657378315925598144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: The Walk of Recollection - Difficulty: 0)
(@CGUID+6, 169999, 2222, 10534, 11492, '0', 0, 0, 0, 0, -1902.71533203125, -3734.397705078125, 6620.732421875, 2.113438129425048828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Court of Elation - Difficulty: 0)
(@CGUID+7, 169999, 2222, 10534, 11380, '0', 0, 0, 0, 0, -3014.171875, -4210.642578125, 6617.54833984375, 6.029454231262207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Temple of Courage - Difficulty: 0)
(@CGUID+8, 169999, 2222, 10534, 0, '0', 0, 0, 0, 0, -2565.296875, -5043.40625, 6581.04638671875, 1.644359707832336425, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Bastion - Difficulty: 0)
(@CGUID+9, 169999, 2222, 10534, 0, '0', 0, 0, 0, 0, -3704.178955078125, -4273.19091796875, 6734.41259765625, 5.427975177764892578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Spirit Obelisk (Area: Hero's Rest - Difficulty: 0)
(@CGUID+10, 158513, 2222, 10534, 0, '0', 0, 0, 0, 0, -4067.354248046875, -4777.3525390625, 6561.3212890625, 2.110229730606079101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: Aspirant's Crucible - Difficulty: 0)
(@CGUID+11, 158513, 2222, 10534, 13415, '0', 0, 0, 0, 0, -4657.0849609375, -5182.51220703125, 6594.93701171875, 4.710144519805908203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: Aspirant's Awakening - Difficulty: 0)
(@CGUID+12, 158513, 2222, 10534, 11014, '0', 0, 0, 0, 0, -4054.553955078125, -5191.96337890625, 6580.6455078125, 1.749073147773742675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: The Temple of Purity - Difficulty: 0)
(@CGUID+13, 158513, 2222, 10534, 0, '0', 0, 0, 0, 0, -3293.6025390625, -5247.828125, 6594.79296875, 6.24849557876586914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: Bastion - Difficulty: 0)
(@CGUID+14, 158513, 2222, 10534, 0, '0', 0, 0, 0, 0, -2639.850830078125, -5525.43408203125, 6569.6787109375, 3.238456010818481445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: The Temple of Purity - Difficulty: 0)
(@CGUID+15, 158513, 2222, 10534, 0, '0', 0, 0, 0, 0, -1928.40625, -4890.23291015625, 6645.6279296875, 0.004711664747446775, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: The Walk of Recollection - Difficulty: 0)
(@CGUID+16, 158513, 2222, 10534, 11492, '0', 0, 0, 0, 0, -1910.6978759765625, -3735.41845703125, 6625.22119140625, 1.283865213394165039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: Court of Elation - Difficulty: 0)
(@CGUID+17, 158513, 2222, 10534, 11380, '0', 0, 0, 0, 0, -3014.053955078125, -4200.80908203125, 6620.85888671875, 2.97297835350036621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: Temple of Courage - Difficulty: 0)
(@CGUID+18, 158513, 2222, 10534, 0, '0', 0, 0, 0, 0, -2574.22216796875, -5039.626953125, 6585.537109375, 0.994517028331756591, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887), -- Vesiphone (Area: Bastion - Difficulty: 0)
(@CGUID+19, 158513, 2222, 10534, 0, '0', 0, 0, 0, 0, -3700.036376953125, -4264.6787109375, 6738.6142578125, 2.979945182800292968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 68887); -- Vesiphone (Area: Hero's Rest - Difficulty: 0)

DELETE FROM `creature_template_addon` WHERE `entry` = 158513;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(158513, 0, 0, 0, 3, 1, 1, 0, 0, 0, 0, 0, 0, '315067'); -- 158513 (Vesiphone) - Ghost

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=68887 WHERE (`Entry`=158513 AND `DifficultyID`=0); -- 158513 (Vesiphone) - Sessile, Floating - CannotTurn

-- Template
UPDATE `creature_template` SET `unit_flags3`=0x40000000 WHERE `entry`=158513; -- Vesiphone

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=169999 AND `MenuID`=25872) OR (`CreatureID`=158513 AND `MenuID`=83);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(169999, 25872, 68887), -- Spirit Obelisk
(158513, 83, 68887); -- Vesiphone

DELETE FROM `gossip_menu` WHERE (`MenuID`=25872 AND `TextID`=580);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(25872, 580, 68887); -- 169999 (Spirit Obelisk)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=25872 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(25872, 52620, 0, 4, 'Return me to life.', 2547, 0, 0, 0, 0, 32301, 0, 0, NULL, 0, NULL, NULL, 68887);

-- Graveyard
DELETE FROM `graveyard_zone` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+9;
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`, `Comment`) VALUES
(@GGUID+0, 10534, 'Bastion - Aspirant\'s Crucible'),
(@GGUID+1, 10534, 'Bastion - Aspirant\'s Awakening'),
(@GGUID+2, 10534, 'Bastion - Temple of Purity'),
(@GGUID+3, 10534, 'Bastion - Near Mnemonic Locus'),
(@GGUID+4, 10534, 'Bastion - Temple of Purity South'),
(@GGUID+5, 10534, 'Bastion - Walk of Recollection'),
(@GGUID+6, 10534, 'Bastion - Court of Elation'),
(@GGUID+7, 10534, 'Bastion - Temple of Courage'),
(@GGUID+8, 10534, 'Bastion - Central'),
(@GGUID+9, 10534, 'Bastion - Hero\'s Rest');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @GGUID+0 AND @GGUID+9;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@GGUID+0, 2222, -4076.934, -4764.474, 6557.271, 5.334911823272705 / (2 * PI() / 360), 'Bastion - Aspirant\'s Crucible - GY'),
(@GGUID+1, 2222, -4655.1895, -5193.5, 6590.5806, 0.9403547048568726 / (2 * PI() / 360), 'Bastion - Aspirant\'s Awakening - GY'),
(@GGUID+2, 2222, -4055.804, -5181.9062, 6576.358, 4.013831615447998 / (2 * PI() / 360), 'Bastion - Temple of Purity - GY'),
(@GGUID+3, 2222, -3285.2622, -5249.144, 6590.1, 4.029774188995361 / (2 * PI() / 360), 'Bastion - Near Mnemonic Locus - GY'),
(@GGUID+4, 2222, -2648.587, -5522.0156, 6565.4575, 0.7084668874740601 / (2 * PI() / 360), 'Bastion - Temple of Purity South - GY'),
(@GGUID+5, 2222, -1915.2223, -4887.1753, 6641.143, 4.8130903244018555 / (2 * PI() / 360), 'Bastion - Walk of Recollection - GY'),
(@GGUID+6, 2222, -1908.0608, -3725.7222, 6620.264, 5.33215856552124 / (2 * PI() / 360), 'Bastion - Court of Elation - GY'),
(@GGUID+7, 2222, -3022.8438, -4208.6753, 6616.2773, 6.055689334869385 / (2 * PI() / 360), 'Bastion - Temple of Courage - GY'),
(@GGUID+8, 2222, -2565.2344, -5032.2085, 6580.0005, 5.247495174407959 / (2 * PI() / 360), 'Bastion - Central - GY'),
(@GGUID+9, 2222, -3710.717, -4265.144, 6733.321, 5.352766990661621 / (2 * PI() / 360), 'Bastion - Hero\'s Rest - GY');
