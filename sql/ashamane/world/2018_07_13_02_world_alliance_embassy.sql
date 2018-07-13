DELETE FROM `gossip_menu_option` WHERE MenuId IN(22081,22082);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(22081, 0, 0, 'What can you tell me about the Lightforged draenei?', 0),
(22082, 0, 0, 'What do we know about the void elves?', 0);



DELETE FROM `gossip_menu` WHERE (`MenuId`=22202 AND `TextId`=34012) OR (`MenuId`=22081 AND `TextId`=34010) OR (`MenuId`=22082 AND `TextId`=34006) OR (`MenuId`=22201 AND `TextId`=34011) OR (`MenuId`=22203 AND `TextId`=34013) OR (`MenuId`=22198 AND `TextId`=34007) OR (`MenuId`=22199 AND `TextId`=34008) OR (`MenuId`=22200 AND `TextId`=34009);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(22202, 34012), -- 126323
(22081, 34010), -- 126319
(22082, 34006), -- 126321
(22201, 34011), -- 133197
(22203, 34013), -- 126328
(22198, 34007), -- 126332
(22199, 34008), -- 126326
(22200, 34009); -- 126324

UPDATE creature_template SET gossip_menu_id = 22202 WHERE entry = 126323;
UPDATE creature_template SET gossip_menu_id = 22081 WHERE entry = 126319;
UPDATE creature_template SET gossip_menu_id = 22082 WHERE entry = 126321;
UPDATE creature_template SET gossip_menu_id = 22201 WHERE entry = 133197;
UPDATE creature_template SET gossip_menu_id = 22203 WHERE entry = 126328;
UPDATE creature_template SET gossip_menu_id = 22198 WHERE entry = 126332;
UPDATE creature_template SET gossip_menu_id = 22199 WHERE entry = 126326;
UPDATE creature_template SET gossip_menu_id = 22200 WHERE entry = 126324;

DELETE FROM npc_text WHERE ID IN (34011, 34013, 34007, 34008, 34006, 34010, 34009, 34012);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(34011, 1, 0, 0, 0, 0, 0, 0, 0, 147222, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34011
(34013, 1, 0, 0, 0, 0, 0, 0, 0, 147231, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34013
(34007, 1, 0, 0, 0, 0, 0, 0, 0, 147229, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34007
(34008, 1, 0, 0, 0, 0, 0, 0, 0, 147228, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34008
(34006, 1, 0, 0, 0, 0, 0, 0, 0, 147223, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34006
(34010, 1, 0, 0, 0, 0, 0, 0, 0, 147224, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34010
(34009, 1, 0, 0, 0, 0, 0, 0, 0, 147226, 0, 0, 0, 0, 0, 0, 0, 26972), -- 34009
(34012, 1, 0, 0, 0, 0, 0, 0, 0, 147233, 0, 0, 0, 0, 0, 0, 0, 26972); -- 34012

DELETE FROM `gameobject_template` WHERE entry IN (273855, 273853, 278328, 278326, 278331, 278329, 278330, 278327, 278333, 278332, 278325, 278324);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `ScriptName`, `VerifiedBuild`)VALUES
(273855, 22, 47677, 'Lightforged Draenei', 'inspect', '', '', 0.85, 257990, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_allied_race_infos_draenei', 26972), -- 273855
(273853, 22, 47680, 'Void Elf', 'inspect', '', '', 1.3, 257989, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'go_allied_race_infos_voidelf', 26972), -- 273853
(278328, 5, 15617, 'Chair', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278328
(278326, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278326
(278331, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278331
(278329, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278329
(278330, 7, 15419, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278330
(278327, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278327
(278333, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278333
(278332, 7, 15618, 'Bench', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278332
(278325, 7, 15617, 'Chair', '', '', '', 0.9999999, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972), -- 278325
(278324, 7, 15617, 'Chair', '', '', '', 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 26972); -- 278324

SET @CGUID = 11000000;
SET @OGUID= 2000000;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+1 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+1, 273855, 0, 1519, 5314, 1, 0, 0, -8154.518, 822.092, 75.52975, 3.899293, 0, 0, -0.9290905, 0.3698525, 120, 255, 1, 26972), -- 273855 (Area: 5314 - Difficulty: 0)
(@OGUID+2, 273853, 0, 1519, 9171, 1, 0, 0, -8148.156, 815.2274, 75.41902, 3.899293, 0, 0, -0.9290905, 0.3698525, 120, 255, 1, 26972), -- 273853 (Area: 9171 - Difficulty: 0)
(@OGUID+3, 278326, 0, 1519, 5314, 1, 0, 0, -8155.223, 811.3687, 75.71727, 5.497789, 0, 0, -0.3826828, 0.9238798, 120, 255, 1, 26972), -- 278326 (Area: 5314 - Difficulty: 0)
(@OGUID+4, 278328, 0, 1519, 9171, 1, 0, 0, -8150.182, 823.9144, 75.71727, 4.363327, 0, 0, -0.8191509, 0.5735781, 120, 255, 1, 26972), -- 278328 (Area: 9171 - Difficulty: 0)
(@OGUID+5, 278331, 0, 1519, 9171, 1, 0, 0, -8148.206, 821.507, 75.71727, 3.918267, 0, 0, -0.92554, 0.3786499, 120, 255, 1, 26972), -- 278331 (Area: 9171 - Difficulty: 0)
(@OGUID+6, 278329, 0, 1519, 9171, 1, 0, 0, -8145.367, 819.0809, 75.71727, 3.447027, 0, 0, -0.9883614, 0.1521243, 120, 255, 1, 26972), -- 278329
(@OGUID+7, 278330, 0, 1519, 9171, 1, 0, 0, -8151.375, 805.2385, 75.96646, 1.422443, 0, 0, 0.6527596, 0.7575652, 120, 255, 1, 26972), -- 278330
(@OGUID+8, 278327, 0, 1519, 9171, 1, 0, 0, -8152.151, 808.3145, 75.71727, 2.356195, 0, 0, 0.9238796, 0.3826832, 120, 255, 1, 26972), -- 278327 
(@OGUID+9, 278333, 0, 1519, 5314, 1, 0, 0, -8161.157, 817.7294, 75.71727, 5.393069, 0, 0, -0.4305105, 0.9025856, 120, 255, 1, 26972), -- 278333 (Area: 5314 - Difficulty: 0)
(@OGUID+10, 278332, 0, 1519, 5314, 1, 0, 0, -8158.248, 814.6324, 75.71727, 2.330013, 0, 0, 0.9187908, 0.3947448, 120, 255, 1, 26972), -- 278332 (Area: 5314 - Difficulty: 0)
(@OGUID+11, 278324, 0, 1519, 5314, 1, 0, 0, -8166.54, 818.2576, 75.89896, 3.926996, 0, 0, -0.9238787, 0.3826855, 120, 255, 1, 26972), -- 278324 (Area: 5314 - Difficulty: 0)
(@OGUID+12, 278325, 0, 1519, 5314, 1, 0, 0, -8166.933, 815.5296, 75.89896, 2.591811, 0, 0, 0.9624548, 0.271442, 120, 255, 1, 26972), -- 278325 (Area: 5314 - Difficulty: 0)
(@OGUID+13, 278311, 0, 1519, 5314, 1, 0, 0, -8205.127, 824.0174, 70.47892, 5.576327, 0, 0, -0.346117, 0.9381914, 120, 255, 1, 26972), -- 278311 (Area: 5314 - Difficulty: 0)
(@OGUID+14, 281205, 0, 1519, 5314, 1, 0, 0, -8195.908, 845.1146, 70.04467, 0, 0, 0, 0, 1, 120, 255, 1, 26972), -- 281205 (Area: 5314 - Difficulty: 0)
(@OGUID+15, 281204, 0, 1519, 5314, 1, 0, 0, -8200.955, 838.6163, 70.04467, 5.068156, 0, 0, -0.5708284, 0.8210694, 120, 255, 1, 26972); -- 281204 (Area: 5314 - Difficulty: 0)

-- forgot to make him have gossip --
UPDATE creature_template SET npcflag=1 WHERE entry = 126323;
UPDATE creature_template SET npcflag=1 WHERE entry = 126319;
UPDATE creature_template SET npcflag=1 WHERE entry = 126321;
UPDATE creature_template SET npcflag=1 WHERE entry = 133197;
UPDATE creature_template SET npcflag=1 WHERE entry = 126328;
UPDATE creature_template SET npcflag=1 WHERE entry = 126332;
UPDATE creature_template SET npcflag=1 WHERE entry = 126324;
UPDATE creature_template SET npcflag=1 WHERE entry = 126326;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+1, 126323, 0, 1519, 9171, 1, 0, 0, 0, 0, -8150.293, 823.7083, 75.54014, 4.244734, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126323 (Area: 9171 - Difficulty: 0)
(@CGUID+2, 126319, 0, 1519, 9171, 1, 0, 0, 0, 0, -8154.516, 817.3472, 75.8006, 0.3642006, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126319 (Area: 9171 - Difficulty: 0)
(@CGUID+3, 126321, 0, 1519, 9171, 1, 0, 0, 0, 0, -8152.319, 815.2361, 75.8006, 1.220403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126321 (Area: 9171 - Difficulty: 0)
(@CGUID+4, 133197, 0, 1519, 9171, 1, 0, 0, 0, 0, -8151.033, 810.7239, 76.08612, 1.637619, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133197 (Area: 9171 - Difficulty: 0)
(@CGUID+5, 126328, 0, 1519, 9171, 1, 0, 0, 0, 0, -8154.658, 812.3073, 75.68986, 0.9916472, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126328 (Area: 9171 - Difficulty: 0)
(@CGUID+6, 126332, 0, 1519, 9171, 1, 0, 0, 0, 0, -8153.974, 807.1337, 76.08612, 1.374631, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126332 (Area: 9171 - Difficulty: 0)
(@CGUID+7, 126324, 0, 1519, 9171, 1, 0, 0, 0, 0, -8159.022, 819.6614, 76.08612, 6.089644, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126324 (Area: 9171 - Difficulty: 0)
(@CGUID+8, 126326, 0, 1519, 9171, 1, 0, 0, 0, 0, -8162.304, 813.2205, 76.08612, 0.480675, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 126326 (Area: 9171 - Difficulty: 0) (Auras: )
(@CGUID+9, 133433, 0, 1519, 5314, 1, 0, 0, 0, 0, -8209.656, 822.6614, 70.65031, 1.365126, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133433 (Area: 5314 - Difficulty: 0) @cguid+202
(@CGUID+10, 133441, 0, 1519, 5314, 1, 0, 0, 0, 0, -8209.288, 825.3958, 70.63021, 4.271554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133441 (Area: 5314 - Difficulty: 0) @cguid+194
(@CGUID+11, 133396, 0, 1519, 5314, 1, 0, 0, 0, 0, -8221.839, 815.5121, 70.12801, 1.3472, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133396 (Area: 5314 - Difficulty: 0)
(@CGUID+12, 133363, 0, 1519, 5314, 1, 0, 0, 0, 0, -8221.989, 819.3559, 70.12801, 5.204322, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133363 (Area: 5314 - Difficulty: 0)
(@CGUID+13, 133411, 0, 1519, 5314, 1, 0, 0, 0, 0, -8195.146, 842.9149, 70.16967, 4.479193, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133411 (Area: 5314 - Difficulty: 0) (Auras: 262246 - 262246)
(@CGUID+14, 133431, 0, 1519, 5314, 1, 0, 0, 0, 0, -8197.111, 844.3472, 70.12801, 0.5417498, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133431 (Area: 5314 - Difficulty: 0)
(@CGUID+15, 133509, 0, 1519, 5314, 1, 0, 0, 0, 0, -8215.795, 833.7986, 70.12801, 0.2234989, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133509 (Area: 5314 - Difficulty: 0)
(@CGUID+16, 133672, 0, 1519, 5314, 1, 0, 0, 58463, 0, -8213.988, 835.2205, 70.12801, 3.843382, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133672 (Area: 5314 - Difficulty: 0)
(@CGUID+17, 133672, 0, 1519, 5314, 1, 0, 0, 58463, 0, -8212.514, 833.743, 70.12801, 3.133652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133672 (Area: 5314 - Difficulty: 0)
(@CGUID+18, 129679, 0, 1519, 9171, 1, 0, 0, 0, 0, -8177.859, 856.2049, 70.13373, 4.423724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 129679 (Area: 9171 - Difficulty: 0)
(@CGUID+19, 133326, 0, 1519, 9171, 1, 0, 0, 0, 0, -8149.823, 879.6702, 76.36163, 4.023931, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 133326 (Area: 9171 - Difficulty: 0)
(@CGUID+20, 133332, 0, 1519, 9171, 1, 0, 0, 0, 0, -8152.452, 877.7292, 76.61544, 0.3395786, 120, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 133332 (Area: 9171 - Difficulty: 0)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+1 AND @CGUID+20;
INSERT INTO creature_addon (`guid`, `bytes1`, `bytes2`, `emote`)VALUES
(@CGUID+5, 6, 0, 426),
(@CGUID+1, 4, 0, 0); 

 -- Vehicle fix -- 

DELETE FROM vehicle_template_accessory WHERE entry = 126326;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(126326, 116312, 0, 0, 'gelbin in his suit', 6, 30000);

UPDATE creature_template SET minlevel = 110, maxlevel = 110, VehicleId = 5547, type = 7, faction = 1733 WHERE entry = 126326;
UPDATE creature_template SET minlevel = 98, maxlevel = 110, VehicleId = 5078, type = 7, faction = 1733 WHERE entry = 116312;
DELETE FROM creature_template WHERE entry IN (133433, 133441, 133509, 133672, 133396, 133363, 133431, 133411, 112698, 129679, 133332, 133326);
INSERT INTO `creature_template` (`entry`, `KillCredit1`, `KillCredit2`, `modelid1`, `modelid2`, `modelid3`, `modelid4`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `rank`, `family`, `type`, `type_flags`, `type_flags2`, `HealthModifier`, `ManaModifier`, `RacialLeader`, `movementId`, `VerifiedBuild`) VALUES
(133433, 0, 0, 83231, 83232, 82918, 82919, 'Ghostblade Scout', NULL, NULL, NULL, NULL, -1, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 133433  ONE
(133441, 0, 0, 82925, 82928, 83233, 83234, 'Trained Brightlance', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 4096, 0, 1, 1, 0, 0, 26972), -- 133441 ONE
(133509, 0, 0, 82973, 83108, 83235, 83236, 'Riftwarden Acolyte', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 133509 ONE
(133672, 0, 0, 15813, 47034, 58463, 37884, 'Master Arcanist', NULL, NULL, NULL, NULL, 5, 0, 0, 0, 0, 7, 0, 0, 1, 1, 0, 0, 26972), -- 133672  NEED TWO OF THESE
(133396, 0, 0, 82895, 0, 0, 0, 'Jandros Terres', NULL, 'First Aid Trainer', NULL, NULL, 6, 0, 0, 0, 0, 7, 134217728, 0, 1, 1, 0, 0, 26972), -- 133396 ONE
(133363, 0, 0, 82875, 0, 0, 0, 'Aevedos', NULL, 'Tailoring Trainer', NULL, NULL, -1, 0, 0, 0, 0, 7, 134217728, 0, 1, 1, 0, 0, 26972), -- 133363 ONE
(133431, 0, 0, 80978, 82914, 83229, 83230, 'Lightforged Sunshield', NULL, NULL, NULL, NULL, 6, 0, 0, 0, 0, 7, 0, 0, 1, 10, 0, 0, 26972), -- 133431 ONE
(133411, 0, 0, 82899, 0, 0, 0, 'Dalia Skyblossom', NULL, 'Cooking Trainer', NULL, NULL, 0, 0, 0, 0, 0, 7, 134217728, 0, 1.05, 1, 0, 0, 26972), -- 133411 ONE
(112698, 0, 0, 63716, 72180, 72181, 72183, 'Cat', NULL, NULL, NULL, 'openhandglow', 0, 0, 0, 0, 52, 1, 0, 0, 1, 1, 0, 0, 26972), -- 112698 ONE
(129679, 0, 0, 82867, 0, 0, 0, 'Shani Ward', NULL, 'Innkeeper', NULL, NULL, -1, 0, 0, 0, 0, 7, 134217728, 0, 5, 1, 0, 0, 26972), -- 129679
(133332, 0, 0, 82854, 0, 0, 0, 'Statiks Quikfuse', NULL, 'Engineering Supplies', NULL, NULL, 0, 0, 0, 0, 0, 7, 134217728, 0, 1.05, 1, 0, 0, 26972), -- 133332
(133326, 0, 0, 82847, 0, 0, 0, 'Artificer Farud', NULL, 'Engineering Trainer', NULL, NULL, 6, 0, 0, 0, 0, 7, 134217728, 0, 1, 10, 0, 0, 26972); -- 133326




UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 84, npcflag = 81, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 133326;
UPDATE creature_template SET minlevel = 30, maxlevel = 30, faction = 875, npcflag = 4225, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 512, unit_flags2 = 2048 WHERE entry = 133332;
UPDATE creature_template SET minlevel = 90, maxlevel = 90, faction = 1733, npcflag = 0, speed_walk = 1, speed_run = 1.142857, unit_class = 8, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 133672;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 84, npcflag = 0, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 133431;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 84, npcflag = 0, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 133433;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 84, npcflag = 0, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 133441;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 84, npcflag = 0, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 133509;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 84, npcflag = 81, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 512, unit_flags2 = 2048 WHERE entry = 133396;
UPDATE creature_template SET minlevel = 110, maxlevel = 110, faction = 84, npcflag = 81, speed_walk = 1, speed_run = 1.142857, unit_class = 2, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 133363;
UPDATE creature_template SET minlevel = 30, maxlevel = 30, faction = 84, npcflag = 209, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 512, unit_flags2 = 2048 WHERE entry = 133411;
UPDATE creature_template SET gossip_menu_id = 22173, minlevel = 100, maxlevel = 100, faction = 35, npcflag = 16777216, speed_walk = 1, speed_run = 1.142857, unit_class = 1, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 112698;
UPDATE creature_template SET gossip_menu_id = 341, minlevel = 110, maxlevel = 110, faction = 84, npcflag = 65537, speed_walk = 1, speed_run = 1.142857, unit_class = 8, unit_flags = 32768, unit_flags2 = 2048 WHERE entry = 129679;
UPDATE creature_addon SET auras = 0 WHERE guid = 210119268;


DELETE FROM `npc_vendor` WHERE (`entry`=133332 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4364 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4357 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4361 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4404 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=10647 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=39684 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=40533 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4400 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=4399 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133332 AND `item`=68660 AND `ExtendedCost`=6003 AND `type`=1) OR (`entry`=133332 AND `item`=59489 AND `ExtendedCost`=3310 AND `type`=1) OR (`entry`=133332 AND `item`=59477 AND `ExtendedCost`=3392 AND `type`=1) OR (`entry`=133332 AND `item`=59478 AND `ExtendedCost`=3311 AND `type`=1) OR (`entry`=133332 AND `item`=59479 AND `ExtendedCost`=3311 AND `type`=1) OR (`entry`=133332 AND `item`=59480 AND `ExtendedCost`=3308 AND `type`=1) OR (`entry`=133332 AND `item`=59491 AND `ExtendedCost`=3305 AND `type`=1) OR (`entry`=133332 AND `item`=59493 AND `ExtendedCost`=3307 AND `type`=1) OR (`entry`=133332 AND `item`=59496 AND `ExtendedCost`=3306 AND `type`=1) OR (`entry`=133411 AND `item`=21219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=21099 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=2678 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=30817 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133411 AND `item`=159 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(133332, 165, 39354, 0, 0, 1, 0, 0, 26972), -- 39354
(133332, 164, 4364, 3, 0, 1, 0, 0, 26972), -- 4364
(133332, 163, 4357, 4, 0, 1, 0, 0, 26972), -- 4357
(133332, 162, 4371, 1, 0, 1, 0, 0, 26972), -- 4371
(133332, 161, 4361, 2, 0, 1, 0, 0, 26972), -- 4361
(133332, 160, 4404, 1, 0, 1, 0, 0, 26972), -- 4404
(133332, 159, 10647, 0, 0, 1, 0, 0, 26972), -- 10647
(133332, 158, 3466, 0, 0, 1, 0, 0, 26972), -- 3466
(133332, 157, 2880, 0, 0, 1, 0, 0, 26972), -- 2880
(133332, 156, 39684, 0, 0, 1, 0, 0, 26972), -- 39684
(133332, 155, 40533, 0, 0, 1, 0, 0, 26972), -- 40533
(133332, 154, 4400, 0, 0, 1, 0, 0, 26972), -- 4400
(133332, 153, 4399, 0, 0, 1, 0, 0, 26972), -- 4399
(133332, 152, 90146, 0, 0, 1, 0, 0, 26972), -- 90146
(133332, 151, 2901, 0, 0, 1, 0, 0, 26972), -- 2901
(133332, 150, 5956, 0, 0, 1, 0, 0, 26972), -- 5956
(133332, 22, 68660, 0, 6003, 1, 0, 0, 26972), -- 68660
(133332, 21, 59489, 0, 3310, 1, 0, 0, 26972), -- 59489
(133332, 20, 59477, 0, 3392, 1, 0, 0, 26972), -- 59477
(133332, 19, 59478, 0, 3311, 1, 0, 0, 26972), -- 59478
(133332, 18, 59479, 0, 3311, 1, 0, 0, 26972), -- 59479
(133332, 17, 59480, 0, 3308, 1, 0, 0, 26972), -- 59480
(133332, 16, 59491, 0, 3305, 1, 0, 0, 26972), -- 59491
(133332, 15, 59493, 0, 3307, 1, 0, 0, 26972), -- 59493
(133332, 14, 59496, 0, 3306, 1, 0, 0, 26972), -- 59496
(133411, 5, 21219, 0, 0, 1, 0, 0, 26972), -- 21219
(133411, 4, 21099, 0, 0, 1, 0, 0, 26972), -- 21099
(133411, 3, 2678, 0, 0, 1, 0, 0, 26972), -- 2678
(133411, 2, 30817, 0, 0, 1, 0, 0, 26972), -- 30817
(133411, 1, 159, 0, 0, 1, 0, 0, 26972); -- 159

DELETE FROM `gossip_menu` WHERE (`MenuId`=22176 AND `TextId`=33978) OR (`MenuId`=22177 AND `TextId`=33979) OR (`MenuId`=22173 AND `TextId`=33975) OR (`MenuId`=22172 AND `TextId`=33974) OR (`MenuId`=341 AND `TextId`=820) OR (`MenuId`=22124 AND `TextId`=18046) OR (`MenuId`=22171 AND `TextId`=33973) OR (`MenuId`=22169 AND `TextId`=33971);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`) VALUES
(22176, 33978), -- 133322
(22177, 33979), -- 133369
(22173, 33975), -- 133326
(22172, 33974), -- 133332
(341, 820), -- 129679
(22124, 18046), -- 133411
(22171, 33973), -- 133363
(22169, 33971); -- 133396

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=22176 AND `OptionIndex`=0) OR (`MenuId`=22177 AND `OptionIndex`=0) OR (`MenuId`=22173 AND `OptionIndex`=0) OR (`MenuId`=22172 AND `OptionIndex`=0) OR (`MenuId`=341 AND `OptionIndex`=0) OR (`MenuId`=22124 AND `OptionIndex`=1) OR (`MenuId`=22124 AND `OptionIndex`=0) OR (`MenuId`=22171 AND `OptionIndex`=0) OR (`MenuId`=22169 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`) VALUES
(22176, 0, 3, 'I want to become a blacksmith.', 0),
(22177, 0, 3, 'Tell me about Mining.', 0),
(22173, 0, 3, 'Train me in Engineering.', 0),
(22172, 0, 1, 'Let me browse your goods.', 0),
(341, 0, 5, 'Make this inn your home.', 0),
(22124, 1, 1, 'Let me browse your goods.', 0),
(22124, 0, 3, 'I''m here for cooking training.', 0),
(22171, 0, 3, 'Train me in Tailoring.', 0),
(22169, 0, 3, 'Train me in First Aid.', 0);



DELETE FROM `gossip_menu_option_trainer` WHERE (`MenuId`=22176 AND `OptionIndex`=0) OR (`MenuId`=22177 AND `OptionIndex`=0) OR (`MenuId`=22173 AND `OptionIndex`=0) OR (`MenuId`=22124 AND `OptionIndex`=0) OR (`MenuId`=22171 AND `OptionIndex`=0) OR (`MenuId`=22169 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(22176, 0, 27),
(22177, 0, 91),
(22173, 0, 407),
(22124, 0, 136),
(22171, 0, 163),
(22169, 0, 160);

DELETE FROM `npc_text` WHERE `ID` IN (33978 /*33978*/, 33979 /*33979*/, 33975 /*33975*/, 33974 /*33974*/, 820 /*820*/, 18046 /*18046*/, 33973 /*33973*/, 33971 /*33971*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33978, 1, 0, 0, 0, 0, 0, 0, 0, 147196, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33978
(33979, 1, 0, 0, 0, 0, 0, 0, 0, 147197, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33979
(33975, 1, 0, 0, 0, 0, 0, 0, 0, 147191, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33975
(33974, 1, 0, 0, 0, 0, 0, 0, 0, 147188, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33974
(820, 100, 0, 0, 0, 0, 0, 0, 0, 2821, 0, 0, 0, 0, 0, 0, 0, 26972), -- 820
(18046, 1, 0, 0, 0, 0, 0, 0, 0, 51896, 0, 0, 0, 0, 0, 0, 0, 26972), -- 18046
(33973, 1, 0, 0, 0, 0, 0, 0, 0, 147187, 0, 0, 0, 0, 0, 0, 0, 26972), -- 33973
(33971, 1, 0, 0, 0, 0, 0, 0, 0, 147183, 0, 0, 0, 0, 0, 0, 0, 26972); -- 33971

UPDATE creature_template SET gossip_menu_id = 22124 WHERE entry = 133411;
UPDATE gossip_menu_option SET OptionType = 3, OptionNpcFlag = 209 WHERE MenuId = 22124 AND OptionIndex = 1;
UPDATE gossip_menu_option SET OptionType = 5, OptionNpcFlag = 209 WHERE MenuId = 22124 AND OptionIndex = 0;

UPDATE creature_template SET gossip_menu_id = 22169 WHERE entry = 133396;
UPDATE gossip_menu_option SET OptionType = 5, OptionNpcFlag = 81 WHERE MenuId = 22169 AND OptionIndex = 0;

UPDATE creature_template SET gossip_menu_id = 22171 WHERE entry = 133363;
UPDATE gossip_menu_option SET OptionType = 5, OptionNpcFlag = 81 WHERE MenuId = 22171 AND OptionIndex = 0;

UPDATE creature_template SET gossip_menu_id = 341 WHERE entry = 129679;
UPDATE gossip_menu_option SET OptionType = 8, OptionNpcFlag = 65537 WHERE MenuId = 341 AND OptionIndex = 0;

UPDATE creature_template SET gossip_menu_id = 22173 WHERE entry = 133326;
UPDATE gossip_menu_option SET OptionType = 5, OptionNpcFlag = 81 WHERE MenuId = 22173 AND OptionIndex = 0;

-- GAME OBJECT_TEMPLATE
DELETE FROM `gameobject_template` WHERE entry IN (278311, 281204, 281205);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(278311, 8, 23396, 'Bonfire', '', '', '', 1, 4, 10, 215916, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972),
(281204, 5, 14839, 'Cooking Table', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972), -- 281204
(281205, 5, 7409, 'Simmering Stew', '', '', '', 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26972); -- 281205
