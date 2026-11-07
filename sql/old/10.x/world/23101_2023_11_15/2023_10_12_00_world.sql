SET @CGUID := 222699;
SET @OGUID := 166313;
SET @POOLID := 800005;
SET @SPAWN_GROUP := 1020;
SET @TRIGGER_ID_NEUTRAL := 33;
SET @TRIGGER_SPAWN_ID :=  38;

DELETE FROM `areatrigger_template` WHERE `Id` IN (@TRIGGER_ID_NEUTRAL) AND `IsServerSide` = 1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Data0`, `Data1`) VALUES
(@TRIGGER_ID_NEUTRAL, 1, 0, 3.0, 3.0);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @TRIGGER_SPAWN_ID+0 AND @TRIGGER_SPAWN_ID+4 AND `IsServerSide` = 1;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `ShapeData0`, `ShapeData1`, `ScriptName`, `Comment`) VALUES
(@TRIGGER_SPAWN_ID+0, @TRIGGER_ID_NEUTRAL, 1, 566, 2043.9499511719, 1729.7800292969, 1190.0400390625, 0.0, 1.5, 1.5, 'areatrigger_action_capture_flag', 'Eye of the Storm - Capture Flag - Fel Reaver'),
(@TRIGGER_SPAWN_ID+1, @TRIGGER_ID_NEUTRAL, 1, 566, 2048.4699707031, 1393.5899658203, 1194.5400390625, 0.0, 1.5, 1.5, 'areatrigger_action_capture_flag', 'Eye of the Storm - Capture Flag - Blood Elf'),
(@TRIGGER_SPAWN_ID+2, @TRIGGER_ID_NEUTRAL, 1, 566, 2284.7700195312, 1731.1099853516, 1190.0799560547, 0.0, 1.5, 1.5, 'areatrigger_action_capture_flag', 'Eye of the Storm - Capture Flag - Mage Tower'),
(@TRIGGER_SPAWN_ID+3, @TRIGGER_ID_NEUTRAL, 1, 566, 2286.5600585938, 1402.3399658203, 1197.2900390625, 0.0, 1.5, 1.5, 'areatrigger_action_capture_flag', 'Eye of the Storm - Capture Flag - Horde');

UPDATE `gameobject_template` SET `StringId` = 'bg_eye_of_the_storm_control_zone' WHERE `entry` IN (184080, 184081, 184082, 184083);

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (228508 /*Eye of the Storm Flag*/, 245854 /*Large Collision Wall*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(228508, 2059, 0, 0, 0), -- Eye of the Storm Flag
(245854, 1375, 0, 0, 0); -- Large Collision Wall

UPDATE `gameobject_template_addon` SET `faction`=2059, `flags`=32 WHERE `entry`=208977; -- Eye of the Storm Flag

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 15384, 566, 3820, 3820, '0', '0', 0, 0, 0, 1807.920166015625, 1539.640625, 1259.7191162109375, 4.433136463165283203, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- OLDWorld Trigger (DO NOT DELETE) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@CGUID+1, 15384, 566, 3820, 3820, '0', '0', 0, 0, 0, 2523.897705078125, 1596.935791015625, 1262.95751953125, 0.48869219422340393, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- OLDWorld Trigger (DO NOT DELETE) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@CGUID+2, 15384, 566, 3820, 3820, '0', '0', 0, 0, 0, 2249.007568359375, 1531.8736572265625, 1500.9945068359375, 5.445427417755126953, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- OLDWorld Trigger (DO NOT DELETE) (Area: Eye of the Storm - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+3, 20212, 566, 3820, 3869, '0', '0', 0, 0, 0, 2284.876708984375, 1731.3350830078125, 1189.906982421875, 1.570796370506286621, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Horde Friendly + Invis Man) (Area: Mage Tower - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
(@CGUID+4, 20212, 566, 3820, 3869, '0', '0', 0, 0, 0, 2044.28, 1729.68, 1189.96, 0.017453, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Horde Friendly + Invis Man); Fel Reaver; Taken from C++ Script
(@CGUID+5, 20212, 566, 3820, 3869, '0', '0', 0, 0, 0, 2048.83, 1393.65, 1194.49, 0.20944, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Horde Friendly + Invis Man); Blood Elf; Taken from C++ Script
(@CGUID+6, 20212, 566, 3820, 3869, '0', '0', 0, 0, 0, 2286.56, 1402.36, 1197.11, 3.72381, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Horde Friendly + Invis Man); Draenei Ruins; Taken from C++ Script
(@CGUID+7, 20213, 566, 3820, 3869, '0', '0', 0, 0, 0, 2284.876708984375, 1731.3350830078125, 1189.906982421875, 1.570796370506286621, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Alliance Friendly + Invis Man) (Area: Mage Tower - Difficulty: 0) CreateObject2 (Auras: 66157 - Honorable Defender)
(@CGUID+8, 20213, 566, 3820, 3869, '0', '0', 0, 0, 0, 2044.28, 1729.68, 1189.96, 0.017453, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Alliance Friendly + Invis Man); Fel Reaver; Taken from C++ Script
(@CGUID+9, 20213, 566, 3820, 3869, '0', '0', 0, 0, 0, 2048.83, 1393.65, 1194.49, 0.20944, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Alliance Friendly + Invis Man); Blood Elf; Taken from C++ Script
(@CGUID+10, 20213, 566, 3820, 3869, '0', '0', 0, 0, 0, 2286.56, 1402.36, 1197.11, 3.72381, 7200, 0, 0, 152441, 0, 0, NULL, NULL, NULL, NULL, 50791), -- World Trigger (Alliance Friendly + Invis Man); Draenei Ruins; Taken from C++ Script
(@CGUID+11, 13117, 566, 3820, 0, '0', '0', 0, 0, 1, 2008.588134765625, 1458.1363525390625, 1172.3004150390625, 5.707226753234863281, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791), -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+12, 13116, 566, 3820, 3870, '0', '0', 0, 0, 1, 2008.46484375, 1458.080078125, 1172.3017578125, 5.654866695404052734, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791), -- Alliance Spirit Guide (Area: Blood Elf Tower - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)(@CGUID+ZZZZZZ252, 13117, 566, 3820, 0, '0', '0', 0, 0, 1, 2008.588134765625, 1458.1363525390625, 1172.3004150390625, 5.707226753234863281, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791); -- Horde Spirit Guide (Area: 0 - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+13, 13116, 566, 3820, 3872, '0', '0', 0, 0, 1, 2008.0699462890625, 1673.3131103515625, 1182.20654296875, 0.523598790168762207, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Alliance Spirit Guide (Area: Fel Reaver Ruins - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+14, 13117, 566, 3820, 3872, '0', '0', 0, 0, 1, 2357.619140625, 1457.8212890625, 1185.417724609375, 3.630284786224365234, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: Fel Reaver Ruins - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+15, 13117, 566, 3820, 3870, '0', '0', 0, 0, 1, 2358.76220703125, 1680.4056396484375, 1173.237060546875, 2.373647689819335937, 7200, 0, 0, 10392670, 533108, 0, NULL, NULL, NULL, NULL, 26365), -- Horde Spirit Guide (Area: Blood Elf Tower - Difficulty: 0) CreateObject2 (Auras: 9036 - Ghost)
(@CGUID+16, 13116, 566, 3820, 3820, '0', '0', 0, 0, 1, 2358.496826171875, 1680.3402099609375, 1173.237060546875, 2.076941728591918945, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791), -- Alliance Spirit Guide (Area: Eye of the Storm - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+17, 13116, 566, 3820, 3820, '0', '0', 0, 0, 1, 2357.604248046875, 1457.8045654296875, 1185.417724609375, 3.455751895904541015, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791), -- Alliance Spirit Guide (Area: Eye of the Storm - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)
(@CGUID+18, 13117, 566, 3820, 3820, '0', '0', 0, 0, 1, 1805.5521240234375, 1539.5572509765625, 1248.2933349609375, 0.087266460061073303, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791), -- Horde Spirit Guide (Area: Eye of the Storm - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+19, 13116, 566, 3820, 3820, '0', '0', 0, 0, 1, 2526.2734375, 1596.498291015625, 1248.6959228515625, 3.106686115264892578, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791), -- Alliance Spirit Guide (Area: Eye of the Storm - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost, 9617 - Ghost Visual)
(@CGUID+20, 13117, 566, 3820, 3820, '0', '0', 0, 0, 1, 2007.931396484375, 1673.318115234375, 1182.2069091796875, 0.558505356311798095, 7200, 0, 0, 1129190, 6310, 0, NULL, NULL, NULL, NULL, 50791); -- Horde Spirit Guide (Area: Eye of the Storm - Difficulty: 0) CreateObject1 (Auras: 9036 - Ghost)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+20;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'), -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '66157'); -- World Trigger (Horde Friendly + Invis Man) - 66157 - Honorable Defender

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+54;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 184720, 566, 3820, 3820, '0', '0', 0, 1803.2066650390625, 1539.486083984375, 1238.4544677734375, 3.13898324966430664, 0.173647880554199218, 0, 0.984807014465332031, 0.001244877814315259, 7200, 255, 1, 50791), -- Forcefield 001 (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+1, 184719, 566, 3820, 3820, '0', '0', 0, 2527.59716796875, 1596.90625, 1238.4544677734375, 3.159139871597290039, 0.173641681671142578, 0.001514434814453125, -0.98476982116699218, 0.008638577535748481, 7200, 255, 1, 50791), -- Forcefield 000 (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+2, 184978, 566, 3820, 3820, '0', '0', 0, 2302.4765625, 1391.244873046875, 1197.7364501953125, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 7200, 255, 1, 50791), -- Berserk Buff (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+3, 184964, 566, 3820, 3820, '0', '0', 0, 2050.46826171875, 1372.2020263671875, 1194.5634765625, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 50791), -- Speed Buff (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+4, 184971, 566, 3820, 3820, '0', '0', 0, 2046.462646484375, 1749.1666259765625, 1190.010498046875, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 7200, 255, 1, 50791), -- Restoration Buff (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+5, 184975, 566, 3820, 3820, '0', '0', 0, 2283.7099609375, 1748.8699951171875, 1189.7071533203125, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 50791), -- Berserk Buff (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+6, 184382, 566, 3820, 3820, '0', '0', 0, 2025.13720703125, 1386.1336669921875, 1192.5482177734375, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+7, 184382, 566, 3820, 3820, '0', '0', 0, 2057.4931640625, 1735.111083984375, 1187.675537109375, 5.340708732604980468, 0, 0, -0.45398998260498046, 0.891006767749786376, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+8, 184382, 566, 3820, 3820, '0', '0', 0, 2092.395751953125, 1775.451416015625, 1186.965576171875, 5.89921426773071289, 0, 0, -0.19080829620361328, 0.981627285480499267, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+9, 184382, 566, 3820, 3820, '0', '0', 0, 2074.3212890625, 1385.76220703125, 1194.362060546875, 0.488691210746765136, 0, 0, 0.241921424865722656, 0.970295846462249755, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+10, 184382, 566, 3820, 3820, '0', '0', 0, 2032.2569580078125, 1729.5572509765625, 1191.0802001953125, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+11, 184382, 566, 3820, 3820, '0', '0', 0, 2047.1875, 1349.1944580078125, 1188.5731201171875, 4.642575740814208984, 0, 0, -0.731353759765625, 0.681998312473297119, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+12, 184382, 566, 3820, 3820, '0', '0', 0, 2245.40966796875, 1366.4410400390625, 1195.1107177734375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+13, 184382, 566, 3820, 3820, '0', '0', 0, 2270.84033203125, 1784.1197509765625, 1186.1473388671875, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+14, 184382, 566, 3820, 3820, '0', '0', 0, 2305.77783203125, 1404.5364990234375, 1199.246337890625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+15, 184382, 566, 3820, 3820, '0', '0', 0, 2268.46533203125, 1736.8385009765625, 1186.742919921875, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+16, 184382, 566, 3820, 3820, '0', '0', 0, 2276.833251953125, 1400.4375, 1196.146728515625, 2.478367090225219726, 0, 0, 0.94551849365234375, 0.325568377971649169, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+17, 184382, 566, 3820, 3820, '0', '0', 0, 2300.9931640625, 1741.5504150390625, 1187.10693359375, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 7200, 255, 1, 50791), -- Visual Banner (Neutral) (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+18, 208977, 566, 3820, 3820, '0', '0', 0, 2174.444580078125, 1569.421875, 1159.852783203125, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 7200, 255, 1, 50791), -- Eye of the Storm Flag (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+19, 184381, 566, 3820, 3820, '0', '0', 0, 2245.395751953125, 1366.4132080078125, 1195.27880859375, 2.216565132141113281, 0, 0, 0.894933700561523437, 0.44619917869567871, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+20, 184381, 566, 3820, 3820, '0', '0', 0, 2305.776123046875, 1404.5572509765625, 1199.384765625, 1.745326757431030273, 0, 0, 0.766043663024902343, 0.642788589000701904, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+21, 184381, 566, 3820, 3820, '0', '0', 0, 2276.796875, 1400.407958984375, 1196.333740234375, 2.44346022605895996, 0, 0, 0.939692497253417968, 0.34202045202255249, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+22, 184380, 566, 3820, 3820, '0', '0', 0, 2025.09375, 1386.12158203125, 1192.6536865234375, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+23, 184380, 566, 3820, 3820, '0', '0', 0, 2047.1978759765625, 1349.1875, 1188.5650634765625, 4.625123500823974609, 0, 0, -0.73727703094482421, 0.67559051513671875, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+24, 184380, 566, 3820, 3820, '0', '0', 0, 2074.3056640625, 1385.7725830078125, 1194.4686279296875, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+25, 184381, 566, 3820, 3820, '0', '0', 0, 2300.85595703125, 1741.24658203125, 1187.793212890625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+26, 184381, 566, 3820, 3820, '0', '0', 0, 2269.126708984375, 1737.703125, 1186.8145751953125, 0.994837164878845214, 0, 0, 0.477158546447753906, 0.878817260265350341, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+27, 184381, 566, 3820, 3820, '0', '0', 0, 2270.8359375, 1784.080322265625, 1186.757080078125, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+28, 184380, 566, 3820, 3820, '0', '0', 0, 2092.354248046875, 1775.4583740234375, 1187.079345703125, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+29, 184380, 566, 3820, 3820, '0', '0', 0, 2032.251708984375, 1729.532958984375, 1190.3251953125, 1.867502212524414062, 0, 0, 0.803856849670410156, 0.594822824001312255, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+30, 184380, 566, 3820, 3820, '0', '0', 0, 2057.45654296875, 1735.07470703125, 1187.9063720703125, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Eye of the Storm - Difficulty: 0) CreateObject2
(@OGUID+31, 184973, 566, 3820, 0, '0', '0', 0, 2283.7099609375, 1748.8699951171875, 1189.7071533203125, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 50791), -- Speed Buff (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+32, 184965, 566, 3820, 0, '0', '0', 0, 2050.46826171875, 1372.2020263671875, 1194.5634765625, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 50791), -- Restoration Buff (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+33, 184381, 566, 3820, 0, '0', '0', 0, 2074.319580078125, 1385.779541015625, 1194.7203369140625, 0.488691210746765136, 0, 0, 0.241921424865722656, 0.970295846462249755, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+34, 184381, 566, 3820, 0, '0', '0', 0, 2047.1910400390625, 1349.1927490234375, 1189.0032958984375, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+35, 184381, 566, 3820, 0, '0', '0', 0, 2025.125, 1386.123291015625, 1192.7354736328125, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: 0 - Difficulty: 0) CreateObject2
(@OGUID+36, 184977, 566, 3820, 0, '0', '0', 0, 2302.4765625, 1391.244873046875, 1197.7364501953125, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 7200, 255, 1, 50791), -- Restoration Buff (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+37, 184380, 566, 3820, 3869, '0', '0', 0, 2301.01904296875, 1741.4930419921875, 1187.48974609375, 5.375615119934082031, 0, 0, -0.4383707046508789, 0.898794233798980712, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Mage Tower - Difficulty: 0) CreateObject2
(@OGUID+38, 184380, 566, 3820, 3869, '0', '0', 0, 2270.869873046875, 1784.0989990234375, 1186.4384765625, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Mage Tower - Difficulty: 0) CreateObject2
(@OGUID+39, 184380, 566, 3820, 3869, '0', '0', 0, 2268.59716796875, 1737.0191650390625, 1186.75390625, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 7200, 255, 1, 50791), -- Visual Banner (Horde) (Area: Mage Tower - Difficulty: 0) CreateObject2
(@OGUID+40, 184974, 566, 3820, 0, '0', '0', 0, 2283.7099609375, 1748.8699951171875, 1189.7071533203125, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 50791), -- Restoration Buff (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+41, 184381, 566, 3820, 3871, '0', '0', 0, 2032.248291015625, 1729.546875, 1191.2296142578125, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Draenei Ruins - Difficulty: 0) CreateObject2
(@OGUID+42, 184381, 566, 3820, 3871, '0', '0', 0, 2057.47265625, 1735.109130859375, 1188.065673828125, 5.305802345275878906, 0, 0, -0.46947097778320312, 0.882947921752929687, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Draenei Ruins - Difficulty: 0) CreateObject2
(@OGUID+43, 184381, 566, 3820, 3871, '0', '0', 0, 2092.338623046875, 1775.4739990234375, 1187.504150390625, 5.811946868896484375, 0, 0, -0.2334451675415039, 0.972369968891143798, 7200, 255, 1, 50791), -- Visual Banner (Alliance) (Area: Draenei Ruins - Difficulty: 0) CreateObject2
(@OGUID+44, 184972, 566, 3820, 3871, '0', '0', 0, 2046.462646484375, 1749.1666259765625, 1190.010498046875, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 7200, 255, 1, 50791), -- Berserk Buff (Area: Draenei Ruins - Difficulty: 0) CreateObject2
(@OGUID+45, 184080, 566, 3820, 3871, '0', '0', 0, 2050.493164, 1372.235962, 1194.563477, 1.710423, 0, 0, 0, 0, 7200, 255, 1, 50791), -- Blood Elf Control Zone
(@OGUID+46, 184081, 566, 3820, 3871, '0', '0', 0, 2024.600708, 1742.819580, 1195.157715, 2.443461, 0, 0, 0, 0, 7200, 255, 1, 50791), -- Fel Reaver Control Zone
(@OGUID+47, 184082, 566, 3820, 3871, '0', '0', 0, 2282.121582, 1760.006958, 1189.707153, 1.919862, 0, 0, 0.0, 0, 7200, 255, 1, 50791), -- Mage Tower Control Zone
(@OGUID+48, 184083, 566, 3820, 3871, '0', '0', 0, 2301.010498, 1386.931641, 1197.183472, 1.570796, 0, 0, 0, 0, 7200, 255, 1, 50791), -- Draenei Ruins Control Zone
(@OGUID+49, 184970, 566, 3820, 3820, '0', '0', 0, 2046.462646484375, 1749.1666259765625, 1190.010498046875, 5.410521507263183593, 0, 0, -0.42261791229248046, 0.906307935714721679, 7200, 255, 1, 51485), -- Speed Buff (Area: Eye of the Storm - Difficulty: 0) CreateObject1
(@OGUID+50, 184976, 566, 3820, 0, '0', '0', 0, 2302.4765625, 1391.244873046875, 1197.7364501953125, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 7200, 255, 1, 26365), -- Speed Buff (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+51, 184966, 566, 3820, 3869, '0', '0', 0, 2050.46826171875, 1372.2020263671875, 1194.5634765625, 1.675513744354248046, 0, 0, 0.743144035339355468, 0.669131457805633544, 7200, 255, 1, 26365), -- Berserk Buff (Area: Mage Tower - Difficulty: 0) CreateObject1
(@OGUID+52, 184380, 566, 3820, 3871, '0', '0', 0, 2276.798583984375, 1400.4410400390625, 1196.2200927734375, 2.495818138122558593, 0, 0, 0.948323249816894531, 0.317305892705917358, 7200, 255, 1, 51485), -- Visual Banner (Horde) (Area: Draenei Ruins - Difficulty: 0) CreateObject2
(@OGUID+53, 184380, 566, 3820, 3871, '0', '0', 0, 2305.763916015625, 1404.5972900390625, 1199.3333740234375, 1.640606880187988281, 0, 0, 0.731352806091308593, 0.6819993257522583, 7200, 255, 1, 51485), -- Visual Banner (Horde) (Area: Draenei Ruins - Difficulty: 0) CreateObject2
(@OGUID+54, 184380, 566, 3820, 3871, '0', '0', 0, 2245.382080078125, 1366.454833984375, 1195.1815185546875, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 7200, 255, 1, 51485); -- Visual Banner (Horde) (Area: Draenei Ruins - Difficulty: 0) CreateObject2

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+54;

-- Graveyards
DELETE FROM `graveyard_zone` WHERE `ID` IN (1103, 1104, 1105, 1106, 1107, 1108);
INSERT INTO `graveyard_zone` (`ID`, `GhostZone`,`Comment`) VALUES
(1103, 3820, 'Eye of the Storm - Alliance Base'),
(1104, 3820, 'Eye of the Storm - Horde Base'),
(1105, 3820, 'Eye of the Storm - Fel Reaver'),
(1106, 3820, 'Eye of the Storm - Blood Elf'),
(1107, 3820, 'Eye of the Storm - Draenei Ruins'),
(1108, 3820, 'Eye of the Storm - Mage Tower');

-- Graveyard conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 27 AND `SourceEntry` IN (1103, 1104, 1105, 1106, 1107, 1108);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `Comment`) VALUES
-- Bases
(27, 1103, 3820, 0, 6, 469, 0, 'Graveyard - Eye of the Storm - Alliance Base - Team Alliance'),
(27, 1104, 3820, 0, 6, 67, 0, 'Graveyard - Eye of the Storm - Horde Base - Team Horde'),
-- Fel Reaver
(27, 1105, 3820, 0, 6, 469, 0, 'Graveyard - Eye of the Storm - Fel Reaver - Team Alliance'),
(27, 1105, 3820, 0, 11, 2726, 1, 'Graveyard - Eye of the Storm - Fel Reaver - Alliance Controlled'),
(27, 1105, 3820, 1, 6, 67, 0, 'Graveyard - Eye of the Storm - Fel Reaver - Team Horde'),
(27, 1105, 3820, 1, 11, 2727, 1, 'Graveyard - Eye of the Storm - Fel Reaver - Horde Controlled'),
-- Blood Elf
(27, 1106, 3820, 0, 6, 469, 0, 'Graveyard - Eye of the Storm - Blood Elf - Team Alliance'),
(27, 1106, 3820, 0, 11, 2723, 1, 'Graveyard - Eye of the Storm - Blood Elf - Alliance Controlled'),
(27, 1106, 3820, 1, 6, 67, 0, 'Graveyard - Eye of the Storm - Blood Elf - Team Horde'),
(27, 1106, 3820, 1, 11, 2724, 1, 'Graveyard - Eye of the Storm - Blood Elf - Horde Controlled'),
-- Draenei Ruins
(27, 1107, 3820, 0, 6, 469, 0, 'Graveyard - Eye of the Storm - Draenei Ruins - Team Alliance'),
(27, 1107, 3820, 0, 11, 2732, 1, 'Graveyard - Eye of the Storm - Draenei Ruins - Alliance Controlled'),
(27, 1107, 3820, 1, 6, 67, 0, 'Graveyard - Eye of the Storm - Draenei Ruins - Team Horde'),
(27, 1107, 3820, 1, 11, 2733, 1, 'Graveyard - Eye of the Storm - Draenei Ruins - Horde Controlled'),
-- Mage Tower
(27, 1108, 3820, 0, 6, 469, 0, 'Graveyard - Eye of the Storm - Mage Tower - Team Alliance'),
(27, 1108, 3820, 0, 11, 2730, 1, 'Graveyard - Eye of the Storm - Mage Tower - Alliance Controlled'),
(27, 1108, 3820, 1, 6, 67, 0, 'Graveyard - Eye of the Storm - Mage Tower - Team Horde'),
(27, 1108, 3820, 1, 11, 2729, 1, 'Graveyard - Eye of the Storm - Mage Tower - Horde Controlled');

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID+0 AND @POOLID+3;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOLID+0, 1, 'Battleground Eye of the Storm - Buffs - Blood Elf'),
(@POOLID+1, 1, 'Battleground Eye of the Storm - Buffs - Fel Reaver'),
(@POOLID+2, 1, 'Battleground Eye of the Storm - Buffs - Mage Tower'),
(@POOLID+3, 1, 'Battleground Eye of the Storm - Buffs - Draenei Ruins');

DELETE FROM `areatrigger_scripts` WHERE `entry` IN (4568, 4569, 4570, 4571);
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4568, 'at_battleground_buffs'),
(4569, 'at_battleground_buffs'),
(4570, 'at_battleground_buffs'),
(4571, 'at_battleground_buffs');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOLID+0 AND @POOLID+3;
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
-- blood elf
(1, @OGUID+3, @POOLID+0, 0, 'Battleground Eye of the Storm - Speed Buff - Blood Elf'),
(1, @OGUID+32, @POOLID+0, 0, 'Battleground Eye of the Storm - Restoration Buff - Blood Elf'),
(1, @OGUID+51, @POOLID+0, 0, 'Battleground Eye of the Storm - Berserker Buff - Blood Elf'),
-- fel reaver
(1, @OGUID+49, @POOLID+1, 0, 'Battleground Eye of the Storm - Speed Buff - Fel Reaver'),
(1, @OGUID+4, @POOLID+1, 0, 'Battleground Eye of the Storm - Restoration Buff - Fel Reaver'),
(1, @OGUID+44, @POOLID+1, 0, 'Battleground Eye of the Storm - Berserker Buff - Fel Reaver'),
-- mage tower
(1, @OGUID+31, @POOLID+2, 0, 'Battleground Eye of the Storm - Speed Buff - Mage Tower'),
(1, @OGUID+40, @POOLID+2, 0, 'Battleground Eye of the Storm - Restoration Buff - Mage Tower'),
(1, @OGUID+5, @POOLID+2, 0, 'Battleground Eye of the Storm - Berserker Buff - Mage Tower'),
-- draenei ruins
(1, @OGUID+50, @POOLID+3, 0, 'Battleground Eye of the Storm - Speed Buff - Draenei Ruins'),
(1, @OGUID+36, @POOLID+3, 0, 'Battleground Eye of the Storm - Restoration Buff - Draenei Ruins'),
(1, @OGUID+2, @POOLID+3, 0, 'Battleground Eye of the Storm - Berserker Buff - Draenei Ruins');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+24;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Eye of the Storm - Blood Elf Tower - Horde Controlled', 0x20),
(@SPAWN_GROUP+1, 'Eye of the Storm - Blood Elf Tower - Neutral Controlled', 0x20),
(@SPAWN_GROUP+2, 'Eye of the Storm - Blood Elf Tower - Alliance Controlled', 0x20),
(@SPAWN_GROUP+3, 'Eye of the Storm - Fel Reaver - Horde Controlled', 0x20),
(@SPAWN_GROUP+4, 'Eye of the Storm - Fel Reaver - Neutral Controlled', 0x20),
(@SPAWN_GROUP+5, 'Eye of the Storm - Fel Reaver - Alliance Controlled', 0x20),
(@SPAWN_GROUP+6, 'Eye of the Storm - Mage Tower - Horde Controlled', 0x20),
(@SPAWN_GROUP+7, 'Eye of the Storm - Mage Tower - Neutral Controlled', 0x20),
(@SPAWN_GROUP+8, 'Eye of the Storm - Nage Tower - Alliance Controlled', 0x20),
(@SPAWN_GROUP+9, 'Eye of the Storm - Draenei Ruins - Horde Controlled', 0x20),
(@SPAWN_GROUP+10, 'Eye of the Storm - Draenei Ruins - Neutral Controlled', 0x20),
(@SPAWN_GROUP+11, 'Eye of the Storm - Draenei Ruins - Alliance Controlled', 0x20);

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN  @SPAWN_GROUP+0 AND @SPAWN_GROUP+24;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
-- Blood Elf
-- -- Horde
(@SPAWN_GROUP+0, 1, @OGUID+24),
(@SPAWN_GROUP+0, 1, @OGUID+23),
(@SPAWN_GROUP+0, 1, @OGUID+22),
(@SPAWN_GROUP+0, 0, @CGUID+11),
(@SPAWN_GROUP+0, 0, @CGUID+5),
-- -- Neutral
(@SPAWN_GROUP+1, 1, @OGUID+9),
(@SPAWN_GROUP+1, 1, @OGUID+11),
(@SPAWN_GROUP+1, 1, @OGUID+6),
-- -- Alliance
(@SPAWN_GROUP+2, 1, @OGUID+33),
(@SPAWN_GROUP+2, 1, @OGUID+34),
(@SPAWN_GROUP+2, 1, @OGUID+35),
(@SPAWN_GROUP+2, 0, @CGUID+12),
(@SPAWN_GROUP+2, 0, @CGUID+9),
-- Fel Reaver
-- -- Horde
(@SPAWN_GROUP+3, 1, @OGUID+29),
(@SPAWN_GROUP+3, 1, @OGUID+30),
(@SPAWN_GROUP+3, 1, @OGUID+28),
(@SPAWN_GROUP+3, 0, @CGUID+20),
(@SPAWN_GROUP+3, 0, @CGUID+4),
-- -- Neutral
(@SPAWN_GROUP+4, 1, @OGUID+10),
(@SPAWN_GROUP+4, 1, @OGUID+7),
(@SPAWN_GROUP+4, 1, @OGUID+8),
-- -- Alliance
(@SPAWN_GROUP+5, 1, @OGUID+41),
(@SPAWN_GROUP+5, 1, @OGUID+42),
(@SPAWN_GROUP+5, 1, @OGUID+43),
(@SPAWN_GROUP+5, 0, @CGUID+13),
(@SPAWN_GROUP+5, 0, @CGUID+8),
-- Mage Tower
-- -- Horde
(@SPAWN_GROUP+6, 1, @OGUID+38),
(@SPAWN_GROUP+6, 1, @OGUID+39),
(@SPAWN_GROUP+6, 1, @OGUID+37),
(@SPAWN_GROUP+6, 0, @CGUID+15),
(@SPAWN_GROUP+6, 0, @CGUID+3),
-- -- Neutral
(@SPAWN_GROUP+7, 1, @OGUID+13),
(@SPAWN_GROUP+7, 1, @OGUID+15),
(@SPAWN_GROUP+7, 1, @OGUID+17),
-- -- Alliance
(@SPAWN_GROUP+8, 1, @OGUID+27),
(@SPAWN_GROUP+8, 1, @OGUID+26),
(@SPAWN_GROUP+8, 1, @OGUID+25),
(@SPAWN_GROUP+8, 0, @CGUID+16),
(@SPAWN_GROUP+8, 0, @CGUID+7),
-- Draenei Ruins
-- -- Horde
(@SPAWN_GROUP+9, 1, @OGUID+52),
(@SPAWN_GROUP+9, 1, @OGUID+53),
(@SPAWN_GROUP+9, 1, @OGUID+54),
(@SPAWN_GROUP+9, 0, @CGUID+14),
(@SPAWN_GROUP+9, 0, @CGUID+6),
-- -- Neutral
(@SPAWN_GROUP+10, 1, @OGUID+16),
(@SPAWN_GROUP+10, 1, @OGUID+14),
(@SPAWN_GROUP+10, 1, @OGUID+12),
-- -- Alliance
(@SPAWN_GROUP+11, 1, @OGUID+21),
(@SPAWN_GROUP+11, 1, @OGUID+20),
(@SPAWN_GROUP+11, 1, @OGUID+19),
(@SPAWN_GROUP+11, 0, @CGUID+17),
(@SPAWN_GROUP+11, 0, @CGUID+10);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+11;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWN_GROUP+0, 0, 0, 11, 0, 2724, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Blood Elf - Horde Controlled'),
(33, 0, @SPAWN_GROUP+1, 0, 0, 11, 0, 2722, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Blood Elf - Neutral Controlled'),
(33, 0, @SPAWN_GROUP+2, 0, 0, 11, 0, 2723, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Blood Elf - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+3, 0, 0, 11, 0, 2727, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Fel Reaver - Horde Controlled'),
(33, 0, @SPAWN_GROUP+4, 0, 0, 11, 0, 2725, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Fel Reaver - Neutral Controlled'),
(33, 0, @SPAWN_GROUP+5, 0, 0, 11, 0, 2726, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Fel Reaver - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+6, 0, 0, 11, 0, 2729, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Mage Tower - Horde Controlled'),
(33, 0, @SPAWN_GROUP+7, 0, 0, 11, 0, 2728, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Mage Tower - Neutral Controlled'),
(33, 0, @SPAWN_GROUP+8, 0, 0, 11, 0, 2730, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Mage Tower - Alliance Controlled'),
(33, 0, @SPAWN_GROUP+9, 0, 0, 11, 0, 2733, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Draenei Ruins - Horde Controlled'),
(33, 0, @SPAWN_GROUP+10, 0, 0, 11, 0, 2731, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Draenei Ruins - Neutral Controlled'),
(33, 0, @SPAWN_GROUP+11, 0, 0, 11, 0, 2732, 1, 0, 0, 0, 0, '', 'Eye of the Storm - Draenei Ruins - Alliance Controlled');
