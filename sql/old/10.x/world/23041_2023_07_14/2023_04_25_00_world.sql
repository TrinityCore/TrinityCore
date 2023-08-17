SET @SL_CGUID := 1051933;

SET @BFA_CGUID := 850906;
SET @BFA_OGUID := 502194;

-- Creature (Shadowlands)
DELETE FROM `creature` WHERE `guid` = @SL_CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@SL_CGUID+0, 173819, 0, 1519, 5151, '0', 0, 0, 0, 1, -8509.8505859375, 826.20489501953125, 106.6000442504882812, 2.294117689132690429, 120, 0, 0, 112919, 100, 0, 0, 0, 0, 48999); -- Reckful (Area: Cathedral Square - Difficulty: 0) CreateObject1

-- Creature (Battle for Azeroth)
DELETE FROM `creature` WHERE `guid` BETWEEN @BFA_CGUID+0 AND @BFA_CGUID+21;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@BFA_CGUID+0, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8522.9482421875, 830.420166015625, 106.611419677734375, 2.5095062255859375, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+1, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8538.8974609375, 865.37847900390625, 106.6004638671875, 5.614012718200683593, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+2, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8542.4013671875, 855.107666015625, 106.6008224487304687, 1.990334749221801757, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+3, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8566.58203125, 835.99481201171875, 106.6158523559570312, 2.370974063873291015, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+4, 141508, 0, 1519, 5151, '0', 11595, 0, 0, 1, -8517.001953125, 836.685791015625, 106.6098861694335937, 2.137318611145019531, 120, 0, 0, 833, 9550, 0, 0, 0, 0, 48999), -- Stormwind Priest (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_CGUID+5, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8539.4912109375, 816.888916015625, 106.6147384643554687, 2.839437723159790039, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+6, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8519.22265625, 840.17706298828125, 106.6129074096679687, 2.378452062606811523, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+7, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8551.779296875, 847.78125, 106.601043701171875, 5.791043281555175781, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+8, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8533.9775390625, 869.13714599609375, 106.6010894775390625, 5.225872039794921875, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+9, 141508, 0, 1519, 5151, '0', 11595, 0, 0, 1, -8538.50390625, 862.76043701171875, 106.6013565063476562, 0.953504741191864013, 120, 0, 0, 833, 9550, 0, 0, 0, 0, 48999), -- Stormwind Priest (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_CGUID+10, 142816, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8529.88671875, 851.83331298828125, 106.71527099609375, 5.408730983734130859, 120, 0, 0, 11900, 0, 0, 0, 0, 0, 48999), -- Mia Greymane (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244972 - Set Health (Random 65%-85%))
(@BFA_CGUID+11, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8556.5283203125, 843.94097900390625, 106.6012191772460937, 4.247577667236328125, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+12, 141508, 0, 1519, 5151, '0', 11595, 0, 0, 1, -8542.8798828125, 816.375, 106.6105728149414062, 0.150510147213935852, 120, 0, 0, 833, 9550, 0, 0, 0, 0, 48999), -- Stormwind Priest (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_CGUID+13, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8508.37890625, 841.701416015625, 106.6160888671875, 2.034646034240722656, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+14, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8543.220703125, 821.51043701171875, 106.6160430908203125, 5.216535091400146484, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+15, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8567.47265625, 842.12847900390625, 106.6136932373046875, 0.465026795864105224, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+16, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8510.7236328125, 839.90277099609375, 106.61175537109375, 4.509583950042724609, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+17, 141508, 0, 1519, 5151, '0', 11595, 0, 0, 1, -8559.6181640625, 845.03643798828125, 106.6057052612304687, 3.496173858642578125, 120, 0, 0, 833, 9550, 0, 0, 0, 0, 48999), -- Stormwind Priest (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_CGUID+18, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8544.439453125, 813.16668701171875, 106.6119384765625, 2.060442447662353515, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+19, 141504, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8535.126953125, 860.78472900390625, 106.6009979248046875, 2.166921138763427734, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Wounded Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1 (Auras: 244971 - Set Health (Random 15%-55%))
(@BFA_CGUID+20, 140253, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8632.044921875, 775.28125, 97.28206634521484375, 4.064085960388183593, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999), -- Darnassian Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_CGUID+21, 140253, 0, 1519, 5151, '0', 11595, 0, 0, 0, -8633.0712890625, 775.1492919921875, 97.291900634765625, 5.555368900299072265, 120, 0, 0, 119, 0, 0, 0, 0, 0, 48999); -- Darnassian Refugee (Area: Cathedral Square - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @BFA_CGUID+0 AND @BFA_CGUID+21;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@BFA_CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''), -- Darnassian Refugee
(@BFA_CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 16023, 0, 0, 0, ''); -- Darnassian Refugee

-- GameObject (Battle for Azeroth)
DELETE FROM `gameobject` WHERE `guid` BETWEEN @BFA_OGUID+0 AND @BFA_OGUID+21;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@BFA_OGUID+0, 292771, 0, 1519, 5151, '0', 11595, 0, -8538.9423828125, 865.3125, 106.5171432495117187, 5.3492279052734375, 0, 0, -0.45019054412841796, 0.892932534217834472, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+1, 292771, 0, 1519, 5151, '0', 11595, 0, -8510.783203125, 839.94793701171875, 106.5280380249023437, 3.763466596603393554, 0, 0, -0.95204734802246093, 0.305950760841369628, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+2, 292771, 0, 1519, 5151, '0', 11595, 0, -8551.8232421875, 847.71527099609375, 106.5176773071289062, 5.3492279052734375, 0, 0, -0.45019054412841796, 0.892932534217834472, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+3, 292771, 0, 1519, 5151, '0', 11595, 0, -8508.4599609375, 841.8125, 106.5321197509765625, 2.199450969696044921, 0, 0, 0.891082763671875, 0.453840821981430053, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+4, 292771, 0, 1519, 5151, '0', 11595, 0, -8547.8720703125, 857.90972900390625, 106.5224227905273437, 0.608440041542053222, 0, 0, 0.299549102783203125, 0.954080879688262939, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+5, 292771, 0, 1519, 5151, '0', 11595, 0, -8543.263671875, 821.4375, 106.5326080322265625, 5.369798660278320312, 0, 0, -0.44098281860351562, 0.897515535354614257, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+6, 292771, 0, 1519, 5151, '0', 11595, 0, -8544.3974609375, 813.232666015625, 106.5284423828125, 2.199450969696044921, 0, 0, 0.891082763671875, 0.453840821981430053, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+7, 292771, 0, 1519, 5151, '0', 11595, 0, -8525.513671875, 828.55902099609375, 106.5261764526367187, 5.405657291412353515, 0, 0, -0.4248208999633789, 0.905277431011199951, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+8, 292771, 0, 1519, 5151, '0', 11595, 0, -8511.59765625, 845.98956298828125, 106.5319595336914062, 5.303237438201904296, 0, 0, -0.47060298919677734, 0.882345080375671386, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+9, 292771, 0, 1519, 5151, '0', 11595, 0, -8562.283203125, 846.1649169921875, 106.5213470458984375, 3.8733367919921875, 0, 0, -0.93381214141845703, 0.357763737440109252, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+10, 292771, 0, 1519, 5151, '0', 11595, 0, -8539.4423828125, 816.951416015625, 106.5308609008789062, 2.199450969696044921, 0, 0, 0.891082763671875, 0.453840821981430053, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+11, 292771, 0, 1519, 5151, '0', 11595, 0, -8535.08203125, 860.857666015625, 106.5176773071289062, 2.23638772964477539, 0, 0, 0.899312019348144531, 0.437307506799697875, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+12, 292771, 0, 1519, 5151, '0', 11595, 0, -8537.076171875, 818.7742919921875, 106.5318069458007812, 0.521441936492919921, 0, 0, 0.257777214050292968, 0.966204345226287841, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+13, 292771, 0, 1519, 5151, '0', 11595, 0, -8567.41015625, 842.08331298828125, 106.5303497314453125, 0.630055963993072509, 0, 0, 0.309843063354492187, 0.950787723064422607, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+14, 292771, 0, 1519, 5151, '0', 11595, 0, -8541.298828125, 863.47052001953125, 106.5173110961914062, 3.671227216720581054, 0, 0, -0.96514034271240234, 0.261732876300811767, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+15, 292771, 0, 1519, 5151, '0', 11595, 0, -8542.357421875, 855.1805419921875, 106.5174713134765625, 2.23638772964477539, 0, 0, 0.899312019348144531, 0.437307506799697875, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+16, 292771, 0, 1519, 5151, '0', 11595, 0, -8519.1787109375, 840.23956298828125, 106.5296707153320312, 2.199450969696044921, 0, 0, 0.891082763671875, 0.453840821981430053, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+17, 292771, 0, 1519, 5151, '0', 11595, 0, -8522.908203125, 830.48956298828125, 106.5282135009765625, 2.199450969696044921, 0, 0, 0.891082763671875, 0.453840821981430053, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+18, 292771, 0, 1519, 5151, '0', 11595, 0, -8566.546875, 836.05035400390625, 106.5327529907226562, 2.169827222824096679, 0, 0, 0.884263038635253906, 0.466989129781723022, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+19, 292771, 0, 1519, 5151, '0', 11595, 0, -8534.0224609375, 869.0711669921875, 106.5177383422851562, 5.3492279052734375, 0, 0, -0.45019054412841796, 0.892932534217834472, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+20, 292771, 0, 1519, 5151, '0', 11595, 0, -8556.5986328125, 843.9757080078125, 106.5178985595703125, 3.851963758468627929, 0, 0, -0.93758201599121093, 0.347764253616333007, 120, 255, 1, 48999), -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1
(@BFA_OGUID+21, 292771, 0, 1519, 5151, '0', 11595, 0, -8521.6162109375, 838.14239501953125, 106.5289688110351562, 0.702180325984954833, 0, 0, 0.343921661376953125, 0.938998341560363769, 120, 255, 1, 48999); -- Sleeping Mat A (Area: Cathedral Square - Difficulty: 0) CreateObject1

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (142816 /*142816 (Mia Greymane) - Set Health (Random 65%-85%)*/, 173819 /*173819 (Reckful)*/, 141504 /*141504 (Wounded Refugee) - Set Health (Random 15%-55%)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(142816, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244972'), -- 142816 (Mia Greymane) - Set Health (Random 65%-85%)
(173819, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 173819 (Reckful)
(141504, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244971'); -- 141504 (Wounded Refugee) - Set Health (Random 15%-55%)

-- Vendor data
DELETE FROM `npc_vendor` WHERE `entry` = 1351;
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(1351, 2, 188152, 0, 0, 1, 0, 0, 48999), -- Gateway Control Shard
(1351, 1, 64670, 0, 0, 1, 0, 0, 48999); -- Vanishing Powder

-- Waypoints for CGUID+
SET @PATH := ((@BFA_CGUID+10) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8524.986, 845.0139, 106.7153, NULL, 0),
(@PATH, 1, -8522.462, 841.684, 106.726, NULL, 0),
(@PATH, 2, -8519.886, 838.7066, 106.7994, NULL, 0),
(@PATH, 3, -8514.759, 839.2491, 106.7099, NULL, 0),
(@PATH, 4, -8512.698, 839.6268, 106.7612, NULL, 17797),
(@PATH, 5, -8517.776, 837.2917, 106.7774, NULL, 0),
(@PATH, 6, -8520.116, 835.6511, 106.7477, NULL, 0),
(@PATH, 7, -8522.31, 833.9462, 106.7958, NULL, 0),
(@PATH, 8, -8523.38, 832.0243, 106.774, NULL, 15237),
(@PATH, 9, -8527.482, 829.7761, 106.7872, NULL, 0),
(@PATH, 10, -8531.575, 826.1233, 106.7153, NULL, 0),
(@PATH, 11, -8536.676, 821.8768, 106.7272, NULL, 0),
(@PATH, 12, -8539.404, 820.7604, 106.5699, NULL, 0),
(@PATH, 13, -8541.674, 820.5972, 106.6513, NULL, 17886),
(@PATH, 14, -8543.623, 824.7066, 106.5682, NULL, 0),
(@PATH, 15, -8546.804, 828.75, 106.5683, NULL, 0),
(@PATH, 16, -8550.891, 833.7656, 106.5683, NULL, 0),
(@PATH, 17, -8557.059, 841.8729, 106.6568, NULL, 0),
(@PATH, 18, -8558.545, 843.684, 106.5682, NULL, 0),
(@PATH, 19, -8563.594, 842.6754, 106.5682, NULL, 0),
(@PATH, 20, -8565.729, 842.4393, 106.6401, NULL, 18108),
(@PATH, 21, -8560.835, 844.559, 106.5682, NULL, 0),
(@PATH, 22, -8557.299, 847.592, 106.6376, NULL, 0),
(@PATH, 23, -8554.665, 848.9462, 106.6114, NULL, 0),
(@PATH, 24, -8552.651, 848.9496, 106.5798, NULL, 19434),
(@PATH, 25, -8544.216, 856.4028, 106.5682, NULL, 0),
(@PATH, 26, -8543.645, 856.1858, 106.5682, NULL, 12263),
(@PATH, 27, -8539.816, 860.2552, 106.6487, NULL, 0),
(@PATH, 28, -8536.698, 862.7882, 106.5898, NULL, 0),
(@PATH, 29, -8533.681, 865.8663, 106.5683, NULL, 0),
(@PATH, 30, -8533.625, 867.2535, 106.5683, NULL, 18137),
(@PATH, 31, -8536.391, 863.0938, 106.6017, NULL, 0),
(@PATH, 32, -8536.232, 859.6614, 106.7595, NULL, 0),
(@PATH, 33, -8534.163, 856.8055, 106.5682, NULL, 0),
(@PATH, 34, -8531.191, 853.3941, 106.7153, NULL, 0),
(@PATH, 35, -8527.953, 849.5208, 106.7153, NULL, 0);

UPDATE `creature` SET `position_x`= -8524.986, `position_y`= 845.0139, `position_z`= 106.7153, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @BFA_CGUID+10;
DELETE FROM `creature_addon` WHERE `guid`= @BFA_CGUID+10;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@BFA_CGUID+10, @PATH, 1);

-- Waypoints for 850889
SET @CGUID := 850889;
SET @PATH := ((@CGUID) * 10) << 3;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -8845.349, 639.941, 96.30545, NULL, 0),
(@PATH, 1, -8835.585, 629.132, 94.4088, NULL, 0),
(@PATH, 2, -8817.658, 612.7761, 95.58038, NULL, 0),
(@PATH, 3, -8809.368, 604.2205, 96.32818, NULL, 0),
(@PATH, 4, -8799.75, 594.8108, 97.65174, NULL, 0),
(@PATH, 5, -8790.748, 593.0833, 97.80921, NULL, 0),
(@PATH, 6, -8778.522, 602.0625, 97.40015, NULL, 0),
(@PATH, 7, -8772.622, 607.3438, 97.40015, NULL, 0),
(@PATH, 8, -8768.125, 607.632, 97.15015, NULL, 0),
(@PATH, 9, -8757.004, 596.8438, 97.18454, NULL, 0),
(@PATH, 10, -8746.024, 584.8507, 97.52133, NULL, 0),
(@PATH, 11, -8739.005, 577.9757, 97.64633, NULL, 0),
(@PATH, 12, -8735.406, 576.3264, 97.52133, NULL, 0),
(@PATH, 13, -8729.268, 579.0521, 97.56379, NULL, 0),
(@PATH, 14, -8717.109, 591.2882, 98.65571, NULL, 0),
(@PATH, 15, -8709.904, 595.3143, 98.88874, NULL, 0),
(@PATH, 16, -8704.806, 604.6215, 99.39964, NULL, 0),
(@PATH, 17, -8702.696, 618.1059, 100.1496, NULL, 0),
(@PATH, 18, -8703.683, 632.0851, 100.529, NULL, 0),
(@PATH, 19, -8706.998, 645.2934, 100.3612, NULL, 0),
(@PATH, 20, -8716.596, 668.1094, 98.98618, NULL, 0),
(@PATH, 21, -8728.911, 689.8924, 98.98618, NULL, 0),
(@PATH, 22, -8742.248, 707.5608, 98.7635, NULL, 0),
(@PATH, 23, -8754.929, 725.2587, 98.35701, NULL, 0),
(@PATH, 24, -8764.607, 735.3246, 99.1385, NULL, 0),
(@PATH, 25, -8775.783, 741.4114, 99.52339, NULL, 0),
(@PATH, 26, -8791.264, 745.4271, 98.23225, NULL, 0),
(@PATH, 27, -8809.04, 739.8438, 97.8885, NULL, 0),
(@PATH, 28, -8822.618, 732.4097, 98.3643, NULL, 0),
(@PATH, 29, -8828.754, 728.7309, 98.6143, NULL, 0),
(@PATH, 30, -8834.538, 725.7049, 98.0135, NULL, 0),
(@PATH, 31, -8839.41, 723.3055, 97.72175, NULL, 0),
(@PATH, 32, -8843.002, 720.9948, 97.5135, NULL, 0),
(@PATH, 33, -8843.411, 717.5643, 97.6385, NULL, 0),
(@PATH, 34, -8838.018, 707.2049, 97.7635, NULL, 0),
(@PATH, 35, -8830.661, 690.5816, 97.4527, NULL, 0),
(@PATH, 36, -8826.064, 679.9827, 97.56671, NULL, 0),
(@PATH, 37, -8826.323, 676.5018, 97.8277, NULL, 0),
(@PATH, 38, -8830.779, 674.0035, 98.4588, NULL, 0),
(@PATH, 39, -8840.383, 668.6328, 98.01768, NULL, 0),
(@PATH, 40, -8846.549, 663.7327, 97.69608, NULL, 0),
(@PATH, 41, -8850.228, 657.8316, 97.00443, NULL, 0),
(@PATH, 42, -8849.165, 648.0712, 96.55692, NULL, 0);

UPDATE `creature` SET `position_x`= -8845.349, `position_y`= 639.941, `position_z`= 96.30545, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID, @PATH, 1);
