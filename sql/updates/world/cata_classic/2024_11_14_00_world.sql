SET @NPCTEXTID := 530006;
SET @OGUID := 3990000;
SET @CGUID := 3990036;

DELETE FROM `gameobject_template` WHERE `entry` IN (494622 /*Protocol Inferno*/, 494621 /*Mysterious Elemental Device*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(494622, 18, 2650, 'Protocol Inferno', '', '', '', 0.200000002980232238, 5, 470574, 470575, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57359), -- Protocol Inferno
(494621, 2, 9416, 'Mysterious Elemental Device', '', '', '', 2.5, 0, 0, 0, 37143, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57359); -- Mysterious Elemental Device

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 494621, 36, 1581, 1581, '2', '0', 0, -9.10416698455810546, -375.80035400390625, 61.51715087890625, 3.138830423355102539, 0, 0, 0.999999046325683593, 0.001381067908369004, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: The Deadmines - Difficulty: 2) CreateObject2
(@OGUID+1, 494621, 670, 4950, 4950, '2', '0', 0, -620.63714599609375, -184.083328247070312, 272.55023193359375, 3.386049509048461914, 0, 0, -0.9925394058227539, 0.121924228966236114, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: Grim Batol - Difficulty: 2) CreateObject2
(@OGUID+2, 494621, 33, 209, 209, '2', '0', 0, -226.210067749023437, 2106.82470703125, 76.89154815673828125, 2.732363224029541015, 0, 0, 0.979139328002929687, 0.203189983963966369, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: Shadowfang Keep - Difficulty: 2) CreateObject2
(@OGUID+3, 494621, 643, 5004, 5004, '2', '0', 0, -624.42535400390625, 793.8524169921875, 247.4562530517578125, 3.170825481414794921, 0, 0, -0.9998931884765625, 0.014615849591791629, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: Throne of the Tides - Difficulty: 2) CreateObject2
(@OGUID+4, 494621, 725, 5088, 5088, '2', '0', 0, 864.296875, 1015.48272705078125, 318.971099853515625, 4.595711231231689453, 0, 0, -0.7471323013305664, 0.664675354957580566, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: The Stonecore - Difficulty: 2) CreateObject2
(@OGUID+5, 494621, 645, 4926, 4926, '2', '0', 0, 228.388885498046875, 1134.454833984375, 205.66851806640625, 3.209255218505859375, 0, 0, -0.99942779541015625, 0.033824712038040161, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: Blackrock Caverns - Difficulty: 2) CreateObject2
(@OGUID+6, 494621, 644, 4945, 4945, '2', '0', 0, -946.50347900390625, 475.708343505859375, 51.93404769897460937, 3.149879217147827148, 0, 0, -0.99999141693115234, 0.004143203608691692, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: Halls of Origination - Difficulty: 2) CreateObject2
(@OGUID+7, 494621, 657, 5035, 5035, '2', '0', 0, -344.4375, 28.93923568725585937, 626.97930908203125, 5.576823234558105468, 0, 0, -0.34588432312011718, 0.938277184963226318, 7200, 255, 1, 57359), -- Mysterious Elemental Device (Area: The Vortex Pinnacle - Difficulty: 2) CreateObject2
(@OGUID+8, 494621, 755, 5396, 5635, '2', '0', 0, -10711.5986328125, -1308.109375, 17.94497489929199218, 0.272142231464385986, 0, 0, 0.135651588439941406, 0.990756630897521972, 7200, 255, 1, 57359); -- Mysterious Elemental Device (Area: The Warlord's Garrison - Difficulty: 2) CreateObject2

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+8;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 233376, 36, 1581, 1581, '2', '0', 0, 0, 0, -9.25, -375.670135498046875, 61.56928634643554687, 3.169472455978393554, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: The Deadmines - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+1, 233376, 670, 4950, 4950, '2', '0', 0, 0, 0, -620.5382080078125, -184.126739501953125, 272.65753173828125, 3.471092700958251953, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: Grim Batol - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+2, 233376, 33, 209, 209, '2', '0', 0, 0, 0, -226.25347900390625, 2107.010498046875, 76.97479248046875, 2.87956094741821289, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: Shadowfang Keep - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+3, 233376, 643, 5004, 5004, '2', '0', 0, 0, 0, -624.203125, 793.93927001953125, 247.458160400390625, 3.127158403396606445, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: Throne of the Tides - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+4, 233376, 725, 5088, 5088, '2', '0', 0, 0, 0, 864.33160400390625, 1015.310791015625, 319.041961669921875, 4.669849872589111328, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: The Stonecore - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+5, 233376, 645, 4926, 4926, '2', '0', 0, 0, 0, 229.454864501953125, 1135.2100830078125, 205.785491943359375, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: Blackrock Caverns - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+6, 233376, 644, 4945, 4945, '2', '0', 0, 0, 0, -946.65972900390625, 475.72222900390625, 52.01934814453125, 3.207694768905639648, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: Halls of Origination - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+7, 233376, 657, 5035, 5035, '2', '0', 0, 0, 0, -344.401031494140625, 28.84027862548828125, 627.0626220703125, 5.531601428985595703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359), -- -Unknown- (Area: The Vortex Pinnacle - Difficulty: 2) CreateObject2 (Auras: )
(@CGUID+8, 233376, 755, 5396, 5635, '2', '0', 0, 0, 0, -10711.2470703125, -1308.013916015625, 18.02759170532226562, 0.249554172158241271, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 57359); -- -Unknown- (Area: The Warlord's Garrison - Difficulty: 2) CreateObject2 (Auras: )

DELETE FROM `creature_template_difficulty` WHERE `Entry`= 233376;
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `MinLevel`, `MaxLevel`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(233376, 2, 60, 60, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 57359); -- 233376 - Sessile, Floating

DELETE FROM `npc_text` WHERE `ID`= @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 278009, 0, 0, 0, 0, 0, 0, 0, 57359); -- 494621 (Mysterious Elemental Device)

DELETE FROM `gossip_menu` WHERE (`MenuID`=37143 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37143, @NPCTEXTID+0, 57359); -- 494621 (Mysterious Elemental Device)

UPDATE `gossip_menu` SET `VerifiedBuild`=57359 WHERE (`MenuID`=12561 AND `TextID`=17638);
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=37143 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37143, 125329, 0, 0, 'Activate Protocol Inferno.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, 470597, NULL, 57359);

DELETE FROM `creature_template` WHERE `entry`=233376;
INSERT INTO `creature_template` (`entry`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `BaseAttackTime`, `RangeAttackTime`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VehicleId`) VALUES
(233376, 94, 0, 1, 1.142857193946838378, 2000, 2000, 0x2000000, 0x800, 0x40000000, 0); -- -Unknown-
