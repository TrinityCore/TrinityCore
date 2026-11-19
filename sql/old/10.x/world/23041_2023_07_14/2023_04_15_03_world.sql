SET @CGUID := 2000011;
SET @OGUID := 2000377;
SET @POOL := 5706;
SET @EVENT := 9;

-- Equipments
UPDATE `creature_equip_template` SET `VerifiedBuild`=48999 WHERE (`ID`=1 AND `CreatureID` IN (43012,17005,16924,16923,16279,16276,16275,16272,16270,16269,16267,16266,16262,16258,16257,16221,16185,15644,15501,15433,15418,15403));

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=48999 WHERE `DisplayID` IN (61763, 16918, 20027, 42722, 42720, 42335, 35615, 33749, 33687, 18335, 18334, 16625, 16626, 17477, 16689, 16686, 16707, 16685, 16683, 16715, 16681, 16680, 16677, 16700, 16705, 16687, 16702, 16703, 89801, 89421, 89419, 89418, 89800, 16690, 16675, 15513, 16350, 15531, 15525, 15530, 15912, 15906, 2958, 1206, 901);

UPDATE `creature_template_model` SET `VerifiedBuild`=48999 WHERE (`Idx`=0 AND `CreatureID` IN (44244,62821,47421,16277,16258,16269,15638,16916,15501,16266,16275,15433,89713,18929,17005,16186,15403,16259,16262,16257,16267,18926,1420,16185,62020,16279,15644,15418,16923,16276,16221,62822,43012,63079,16270,16271,16924,15493,16272,2914,63080)) OR (`Idx`=7 AND `CreatureID`=16221) OR (`Idx`=6 AND `CreatureID`=16221) OR (`Idx`=5 AND `CreatureID`=16221) OR (`Idx`=4 AND `CreatureID`=16221) OR (`Idx`=3 AND `CreatureID` IN (16221,2914)) OR (`Idx`=2 AND `CreatureID` IN (16221,2914)) OR (`Idx`=1 AND `CreatureID` IN (16221,2914));

-- Scaling
UPDATE `creature_template_scaling` SET `VerifiedBuild`=48999 WHERE (`DifficultyID`=0 AND `Entry` IN (89713,63080,62822,62821,62020,47421,44244,43012,18929,18926,17005,16924,16923,16916,16279,16277,16276,16275,16272,16271,16270,16269,16267,16266,16262,16259,16258,16257,16221,16186,16185,15644,15638,15501,15493,15433,15418,15403,2914,1420));
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `VerifiedBuild`=48999 WHERE (`Entry`=63079 AND `DifficultyID`=0);

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (152263, 152275);
DELETE FROM `game_event_creature` WHERE `guid` IN (152263, 152275);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32798, 530, 3430, 3665, '0', 0, 0, 0, 0, 9494.3193359375, -6840.35400390625, 17.06127166748046875, 0.977384388446807861, 120, 0, 0, 361340, 28784, 0, 0, 0, 0, 48999), -- Spring Gatherer (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@CGUID+1, 32837, 530, 3430, 3665, '0', 0, 0, 0, 1, 9488.0693359375, -6834.07177734375, 17.06610488891601562, 0.767944872379302978, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999); -- Noblegarden Merchant (Area: Falconwing Square - Difficulty: 0) CreateObject1

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 151982 AND 152001;
DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN 151982 AND 152001;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113768, 530, 3430, 3665, '0', 0, 0, 9482.1640625, -6833.26025390625, 17.44304656982421875, 1.029743075370788574, 0, 0, 0.492423057556152343, 0.870355963706970214, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+1, 113768, 530, 3430, 3665, '0', 0, 0, 9475.8251953125, -6802.6904296875, 16.49495124816894531, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+2, 113768, 530, 3430, 3665, '0', 0, 0, 9491.375, -6766.29150390625, 16.49406814575195312, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+3, 113768, 530, 3430, 3665, '0', 0, 0, 9480.9208984375, -6818.58984375, 16.70401763916015625, 4.188792228698730468, 0, 0, -0.86602497100830078, 0.50000077486038208, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+4, 113768, 530, 3430, 3665, '0', 0, 0, 9501.7158203125, -6844.98974609375, 16.67441940307617187, 5.131268978118896484, 0, 0, -0.54463863372802734, 0.838670849800109863, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+5, 113768, 530, 3430, 3665, '0', 0, 0, 9521.6435546875, -6816.15478515625, 16.48992347717285156, 4.293513298034667968, 0, 0, -0.8386697769165039, 0.544640243053436279, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+6, 113768, 530, 3430, 3665, '0', 0, 0, 9512.5, -6851.67578125, 16.92402076721191406, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+7, 113768, 530, 3430, 3665, '0', 0, 0, 9557.2041015625, -6835.95166015625, 16.53261756896972656, 0.331610709428787231, 0, 0, 0.16504669189453125, 0.986285746097564697, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+8, 113768, 530, 3430, 3665, '0', 0, 0, 9541.005859375, -6791.65625, 16.47096633911132812, 1.186823248863220214, 0, 0, 0.559192657470703125, 0.829037725925445556, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+9, 113768, 530, 3430, 3665, '0', 0, 0, 9542.0224609375, -6853.79150390625, 17.39933013916015625, 5.427974700927734375, 0, 0, -0.41469287872314453, 0.909961462020874023, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+10, 113768, 530, 3430, 3665, '0', 0, 0, 9543.6142578125, -6786.87060546875, 16.21173667907714843, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 530, 3430, 3533, '0', 0, 0, 9477.9296875, -6806.37353515625, 16.49356460571289062, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+12, 113768, 530, 3430, 3533, '0', 0, 0, 9555.583984375, -6825.9541015625, 16.49430656433105468, 3.333590030670166015, 0, 0, -0.99539566040039062, 0.095851235091686248, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+13, 113768, 530, 3430, 3665, '0', 0, 0, 9502.6474609375, -6842.96630859375, 16.54372978210449218, 4.1538848876953125, 0, 0, -0.8746194839477539, 0.484810054302215576, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+14, 113768, 530, 3430, 3665, '0', 0, 0, 9520.5126953125, -6769.96240234375, 16.46599578857421875, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+15, 113768, 530, 3430, 3665, '0', 0, 0, 9552.9208984375, -6815.78662109375, 16.37353515625, 3.194002151489257812, 0, 0, -0.99965667724609375, 0.026201646775007247, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+16, 113768, 530, 3430, 3533, '0', 0, 0, 9517.8701171875, -6809.6748046875, 17.32817268371582031, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+17, 113768, 530, 3430, 3665, '0', 0, 0, 9483.5869140625, -6825.03515625, 16.76105880737304687, 2.426007747650146484, 0, 0, 0.936672210693359375, 0.350207358598709106, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+18, 113768, 530, 3430, 3665, '0', 0, 0, 9481.080078125, -6815.55712890625, 16.54894065856933593, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+19, 113768, 530, 3430, 3665, '0', 0, 0, 9505.6328125, -6800.7177734375, 16.49178695678710937, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+20, 113768, 530, 3430, 3665, '0', 0, 0, 9495.4658203125, -6846.54931640625, 17.44208908081054687, 5.113816738128662109, 0, 0, -0.55193614959716796, 0.833886384963989257, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+21, 113768, 530, 3430, 3665, '0', 0, 0, 9551.2763671875, -6828.86669921875, 16.4930419921875, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+22, 113768, 530, 3430, 3665, '0', 0, 0, 9536.599609375, -6850.8671875, 16.52987098693847656, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+23, 113768, 530, 3430, 3665, '0', 0, 0, 9502.2998046875, -6762.97021484375, 17.01189994812011718, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+24, 113768, 530, 3430, 3665, '0', 0, 0, 9549.0673828125, -6848.283203125, 17.22985267639160156, 4.852017402648925781, 0, 0, -0.65605831146240234, 0.754710197448730468, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+25, 113768, 530, 3430, 3665, '0', 0, 0, 9555.3203125, -6831.57177734375, 16.4930572509765625, 3.43830275535583496, 0, 0, -0.98901557922363281, 0.147811368107795715, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+26, 113768, 530, 3430, 3665, '0', 0, 0, 9551.388671875, -6831.77734375, 16.49342536926269531, 0.122172988951206207, 0, 0, 0.061048507690429687, 0.998134791851043701, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+27, 113768, 530, 3430, 3665, '0', 0, 0, 9549.1708984375, -6806.85986328125, 16.44730186462402343, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+28, 113768, 530, 3430, 3665, '0', 0, 0, 9556.2744140625, -6847.72412109375, 17.26838493347167968, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+29, 113768, 530, 3430, 3665, '0', 0, 0, 9513.88671875, -6792.2490234375, 16.49246025085449218, 3.822272777557373046, 0, 0, -0.94264125823974609, 0.333807557821273803, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+30, 113768, 530, 3430, 3665, '0', 0, 0, 9543.0654296875, -6858.04443359375, 17.3531036376953125, 4.241150379180908203, 0, 0, -0.85264015197753906, 0.522498607635498046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+31, 113768, 530, 3430, 3665, '0', 0, 0, 9473.0537109375, -6814.23828125, 16.96545600891113281, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+32, 113768, 530, 3430, 3665, '0', 0, 0, 9545.62109375, -6850.70849609375, 17.35140419006347656, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+33, 113768, 530, 3430, 3665, '0', 0, 0, 9528.9765625, -6806.951171875, 16.49247932434082031, 0.698131442070007324, 0, 0, 0.342020034790039062, 0.939692676067352294, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+34, 113768, 530, 3430, 3665, '0', 0, 0, 9476.580078125, -6803.029296875, 17.40802955627441406, 6.195919513702392578, 0, 0, -0.04361915588378906, 0.999048233032226562, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+35, 113768, 530, 3430, 3533, '0', 0, 0, 9515.3251953125, -6849.64697265625, 16.58533477783203125, 3.071766138076782226, 0, 0, 0.999390602111816406, 0.034906134009361267, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+36, 113768, 530, 3430, 3665, '0', 0, 0, 9483.8017578125, -6827.62841796875, 16.69309425354003906, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+37, 113768, 530, 3430, 3665, '0', 0, 0, 9552.7314453125, -6830.08056640625, 17.609283447265625, 4.049167633056640625, 0, 0, -0.89879322052001953, 0.438372820615768432, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+38, 113768, 530, 3430, 3665, '0', 0, 0, 9519.1904296875, -6804.69189453125, 17.32817268371582031, 0.034906249493360519, 0, 0, 0.017452239990234375, 0.999847710132598876, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+39, 113768, 530, 3430, 3665, '0', 0, 0, 9465.041015625, -6770.330078125, 16.55310630798339843, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+40, 113768, 530, 3430, 3665, '0', 0, 0, 9485.275390625, -6829.40185546875, 16.59279823303222656, 0.925023794174194335, 0, 0, 0.446197509765625, 0.894934535026550292, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+41, 113768, 530, 3430, 3665, '0', 0, 0, 9516.333984375, -6771.748046875, 16.49357795715332031, 0.27925160527229309, 0, 0, 0.139172554016113281, 0.990268170833587646, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+42, 113768, 530, 3430, 3665, '0', 0, 0, 9515.3515625, -6857.80712890625, 16.58345222473144531, 3.682650327682495117, 0, 0, -0.96362972259521484, 0.26724100112915039, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+43, 113768, 530, 3430, 3665, '0', 0, 0, 9546.796875, -6839.79541015625, 16.49825668334960937, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+44, 113768, 530, 3430, 3665, '0', 0, 0, 9468.7314453125, -6813.2080078125, 16.87607192993164062, 3.508116960525512695, 0, 0, -0.98325443267822265, 0.182238012552261352, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+45, 113768, 530, 3430, 3665, '0', 0, 0, 9481.3212890625, -6769.88427734375, 16.50426864624023437, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+46, 113768, 530, 3430, 3665, '0', 0, 0, 9512.7314453125, -6804.7919921875, 17.32817268371582031, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+47, 113768, 530, 3430, 3665, '0', 0, 0, 9516.9736328125, -6806.08203125, 17.32817268371582031, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+48, 113768, 530, 3430, 3665, '0', 0, 0, 9465.3388671875, -6789.05126953125, 16.54677009582519531, 1.012289404869079589, 0, 0, 0.484808921813964843, 0.87462007999420166, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+49, 113768, 530, 3430, 3665, '0', 0, 0, 9507.724609375, -6846.98681640625, 16.99977302551269531, 4.380776405334472656, 0, 0, -0.81411552429199218, 0.580702960491180419, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+50, 113768, 530, 3430, 3665, '0', 0, 0, 9475.248046875, -6809.73876953125, 16.58126640319824218, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+51, 113768, 530, 3430, 3665, '0', 0, 0, 9529.376953125, -6765.759765625, 15.29880237579345703, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+52, 113768, 530, 3430, 3665, '0', 0, 0, 9555.13671875, -6828.63671875, 16.49392318725585937, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+53, 113768, 530, 3430, 3665, '0', 0, 0, 9516.921875, -6803.25537109375, 17.32817268371582031, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+54, 113768, 530, 3430, 3533, '0', 0, 0, 9511.4794921875, -6770.26513671875, 16.49357795715332031, 4.084071159362792968, 0, 0, -0.8910064697265625, 0.453990638256072998, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Ruins of Silvermoon - Difficulty: 0) CreateObject2
(@OGUID+55, 113768, 530, 3430, 3665, '0', 0, 0, 9545.3935546875, -6777.9873046875, 14.78086566925048828, 2.70525527000427246, 0, 0, 0.97629547119140625, 0.216442063450813293, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+56, 113768, 530, 3430, 3665, '0', 0, 0, 9517.7041015625, -6799.71533203125, 17.32817268371582031, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+57, 113768, 530, 3430, 3665, '0', 0, 0, 9477.859375, -6794.8310546875, 16.49660873413085937, 3.368495941162109375, 0, 0, -0.99357128143310546, 0.113208353519439697, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+58, 113768, 530, 3430, 3665, '0', 0, 0, 9535.8505859375, -6858.06494140625, 16.67221450805664062, 1.954769015312194824, 0, 0, 0.829037666320800781, 0.559192776679992675, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject1
(@OGUID+59, 113768, 530, 3430, 3665, '0', 0, 0, 9543.541015625, -6796.333984375, 16.48163414001464843, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2
(@OGUID+60, 113768, 530, 3430, 3665, '0', 0, 0, 9522.673828125, -6804.63916015625, 17.32817268371582031, 3.22885894775390625, 0, 0, -0.99904823303222656, 0.043619260191917419, 300, 255, 1, 48999); -- Brightly Colored Egg (Area: Falconwing Square - Difficulty: 0) CreateObject2

UPDATE `pool_template` SET `description`='Noblegarden - Falconwing Square - Brightly Colored Egg' WHERE `entry`=@POOL;

DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN @OGUID+0 AND @OGUID+60;
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
(1, @OGUID+59, @POOL, 0, 'Noblegarden - Brightly Colored Egg'),
(1, @OGUID+60, @POOL, 0, 'Noblegarden - Brightly Colored Egg');

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(@EVENT, @CGUID+0),
(@EVENT, @CGUID+1);
