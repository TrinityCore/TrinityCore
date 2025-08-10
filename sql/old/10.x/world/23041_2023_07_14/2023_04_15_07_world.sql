SET @CGUID := 2000013;
SET @OGUID := 2000438;
SET @POOL := 5702;
SET @EVENT := 9;

-- Equipments
UPDATE `creature_equip_template` SET `VerifiedBuild`=48999 WHERE (`ID`=1 AND `CreatureID` IN (18810,18038,17930,17483,17482,17481,17480,17228,17215,17212,16551)) OR (`ID`=2 AND `CreatureID`=17228);

-- Models
UPDATE `creature_model_info` SET `VerifiedBuild`=48999 WHERE `DisplayID` IN (36640, 17327, 42343, 35616, 33600, 18214, 17372, 17375, 17385, 17333, 17334, 17230, 17235, 17231, 17229, 17234, 17232, 17233, 17215, 16997, 16945, 16928, 16922, 16924, 16912, 16911, 17599, 16873, 16872, 17009, 16864, 16862, 16861, 16860, 16785, 16260, 16202, 4878);

UPDATE `creature_template_model` SET `VerifiedBuild`=48999 WHERE (`Idx`=0 AND `CreatureID` IN (17212,17488,17484,17215,17268,17232,17110,17486,17214,18038,17483,17930,17983,17360,17482,17114,17117,17196,17480,6145,17116,16476,17228,17485,18810,43991,17929,47431,17201,16551,63078,17481,17200,62050,16553,17222,63077)) OR (`Idx`=3 AND `CreatureID` IN (18038,17228)) OR (`Idx`=2 AND `CreatureID` IN (18038,17228)) OR (`Idx`=1 AND `CreatureID` IN (18038,17228));

-- Scaling
UPDATE `creature_template_scaling` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `VerifiedBuild`=48999 WHERE (`Entry`=63078 AND `DifficultyID`=0);
UPDATE `creature_template_scaling` SET `VerifiedBuild`=48999 WHERE (`DifficultyID`=0 AND `Entry` IN (63077,62050,47431,43991,18810,18038,17983,17930,17929,17488,17486,17485,17484,17483,17482,17481,17480,17360,17268,17232,17228,17222,17215,17214,17212,17201,17200,17196,17117,17116,17114,17110,16553,16551,16476,6145));

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` IN (152268, 152272);
DELETE FROM `game_event_creature` WHERE `guid` IN (152268, 152272);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 32799, 530, 3524, 3576, '0', 0, 0, 0, 0, -4184.8505859375, -12497.708984375, 44.44465255737304687, 2.530727386474609375, 120, 0, 0, 361340, 28784, 0, 0, 0, 0, 48999), -- Spring Collector (Area: Azure Watch - Difficulty: 0) CreateObject1
(@CGUID+1, 32836, 530, 3524, 3576, '0', 0, 0, 0, 1, -4183.29150390625, -12495.4609375, 44.44465255737304687, 2.635447263717651367, 120, 0, 0, 112919, 0, 0, 0, 0, 0, 48999); -- Noblegarden Vendor (Area: Azure Watch - Difficulty: 0) CreateObject1

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 152002 AND 152023;
DELETE FROM `pool_members` WHERE `type`=1 AND `spawnId` BETWEEN 152002 AND 152023;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+60;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 113768, 530, 3524, 3576, '0', 0, 0, -4208.51416015625, -12519.412109375, 45.92644500732421875, 5.096362113952636718, 0, 0, -0.55919265747070312, 0.829037725925445556, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+1, 113768, 530, 3524, 3576, '0', 0, 0, -4222.3369140625, -12506.958984375, 45.52767181396484375, 0.959929943084716796, 0, 0, 0.461748123168945312, 0.887011110782623291, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+2, 113768, 530, 3524, 3576, '0', 0, 0, -4153.87255859375, -12537.1025390625, 45.58904266357421875, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+3, 113768, 530, 3524, 3576, '0', 0, 0, -4149.34326171875, -12472.0048828125, 45.14905929565429687, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+4, 113768, 530, 3524, 3576, '0', 0, 0, -4203.27880859375, -12435.0439453125, 44.94586181640625, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+5, 113768, 530, 3524, 3576, '0', 0, 0, -4130.310546875, -12487.00390625, 44.01567840576171875, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+6, 113768, 530, 3524, 3576, '0', 0, 0, -4215.51220703125, -12524.1728515625, 45.64808273315429687, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+7, 113768, 530, 3524, 3576, '0', 0, 0, -4179.11181640625, -12499.0126953125, 44.36132049560546875, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+8, 113768, 530, 3524, 3576, '0', 0, 0, -4186.53662109375, -12437.9677734375, 43.41905593872070312, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+9, 113768, 530, 3524, 3576, '0', 0, 0, -4125.05126953125, -12510.56640625, 44.61471939086914062, 2.146752834320068359, 0, 0, 0.878816604614257812, 0.477159708738327026, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+10, 113768, 530, 3524, 3576, '0', 0, 0, -4152.5693359375, -12480.7216796875, 44.78427505493164062, 2.879789113998413085, 0, 0, 0.991444587707519531, 0.130528271198272705, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+11, 113768, 530, 3524, 3576, '0', 0, 0, -4169.34228515625, -12543.484375, 45.19704055786132812, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+12, 113768, 530, 3524, 3576, '0', 0, 0, -4208.2314453125, -12439.9658203125, 45.40089035034179687, 4.502951622009277343, 0, 0, -0.7771453857421875, 0.629321098327636718, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+13, 113768, 530, 3524, 3576, '0', 0, 0, -4204.111328125, -12532.3330078125, 45.79191207885742187, 0.593410074710845947, 0, 0, 0.292370796203613281, 0.95630502700805664, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+14, 113768, 530, 3524, 3576, '0', 0, 0, -4223.697265625, -12482.1318359375, 45.09798812866210937, 5.253442287445068359, 0, 0, -0.49242305755615234, 0.870355963706970214, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+15, 113768, 530, 3524, 3576, '0', 0, 0, -4233.84375, -12534.5517578125, 45.83507537841796875, 5.637413978576660156, 0, 0, -0.31730461120605468, 0.948323667049407958, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+16, 113768, 530, 3524, 3576, '0', 0, 0, -4171.57958984375, -12539.2119140625, 44.8950042724609375, 4.118979454040527343, 0, 0, -0.88294696807861328, 0.469472706317901611, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+17, 113768, 530, 3524, 3576, '0', 0, 0, -4182.41748046875, -12497.8115234375, 44.36132049560546875, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+18, 113768, 530, 3524, 3576, '0', 0, 0, -4107.16357421875, -12484.3095703125, 42.57118606567382812, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+19, 113768, 530, 3524, 3576, '0', 0, 0, -4218.2939453125, -12444.4658203125, 44.77256011962890625, 5.794494152069091796, 0, 0, -0.24192142486572265, 0.970295846462249755, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+20, 113768, 530, 3524, 3576, '0', 0, 0, -4128.91259765625, -12455.61328125, 45.4173126220703125, 1.605701684951782226, 0, 0, 0.719339370727539062, 0.694658815860748291, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+21, 113768, 530, 3524, 3576, '0', 0, 0, -4144.59716796875, -12490.173828125, 44.60271835327148437, 4.694936752319335937, 0, 0, -0.71325016021728515, 0.700909554958343505, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+22, 113768, 530, 3524, 3576, '0', 0, 0, -4159.7255859375, -12451.6943359375, 47.19725418090820312, 3.543023586273193359, 0, 0, -0.97992420196533203, 0.199370384216308593, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+23, 113768, 530, 3524, 3576, '0', 0, 0, -4120.8798828125, -12523.7998046875, 44.01050186157226562, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+24, 113768, 530, 3524, 3576, '0', 0, 0, -4156.12060546875, -12427.064453125, 41.67079544067382812, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+25, 113768, 530, 3524, 3576, '0', 0, 0, -4224.55322265625, -12536.251953125, 45.90106964111328125, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+26, 113768, 530, 3524, 3576, '0', 0, 0, -4175.40185546875, -12501.923828125, 44.36132049560546875, 1.32644820213317871, 0, 0, 0.615660667419433593, 0.788011372089385986, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+27, 113768, 530, 3524, 3576, '0', 0, 0, -4229.93359375, -12539.373046875, 47.32204818725585937, 4.48549652099609375, 0, 0, -0.7826080322265625, 0.622514784336090087, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+28, 113768, 530, 3524, 3576, '0', 0, 0, -4151.11572265625, -12476.2529296875, 44.9427337646484375, 2.042035102844238281, 0, 0, 0.852640151977539062, 0.522498607635498046, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+29, 113768, 530, 3524, 3576, '0', 0, 0, -4177.18310546875, -12504.0283203125, 44.36132049560546875, 0.645771682262420654, 0, 0, 0.317304611206054687, 0.948323667049407958, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+30, 113768, 530, 3524, 3576, '0', 0, 0, -4240.671875, -12536, 46.06270599365234375, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+31, 113768, 530, 3524, 3576, '0', 0, 0, -4178.70361328125, -12506.4892578125, 44.36132049560546875, 1.413715124130249023, 0, 0, 0.649447441101074218, 0.760406434535980224, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+32, 113768, 530, 3524, 3576, '0', 0, 0, -4126.5546875, -12485.4365234375, 44.16746902465820312, 2.565631866455078125, 0, 0, 0.958819389343261718, 0.284016460180282592, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+33, 113768, 530, 3524, 3576, '0', 0, 0, -4244.74462890625, -12516.26171875, 47.49639892578125, 4.223697185516357421, 0, 0, -0.85716724395751953, 0.515038192272186279, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+34, 113768, 530, 3524, 3576, '0', 0, 0, -4154.8544921875, -12432.228515625, 42.12904739379882812, 3.089183330535888671, 0, 0, 0.99965667724609375, 0.026201646775007247, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+35, 113768, 530, 3524, 3576, '0', 0, 0, -4180.6552734375, -12501.15234375, 44.36132049560546875, 3.839725255966186523, 0, 0, -0.93969249725341796, 0.34202045202255249, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+36, 113768, 530, 3524, 3576, '0', 0, 0, -4212.07958984375, -12534.8798828125, 49.40731048583984375, 4.310965538024902343, 0, 0, -0.83388519287109375, 0.55193793773651123, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+37, 113768, 530, 3524, 3576, '0', 0, 0, -4176.45654296875, -12499.5439453125, 44.36132049560546875, 1.518436193466186523, 0, 0, 0.6883544921875, 0.725374460220336914, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+38, 113768, 530, 3524, 3576, '0', 0, 0, -4207.76416015625, -12558.9716796875, 40.88757705688476562, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+39, 113768, 530, 3524, 3576, '0', 0, 0, -4130.71435546875, -12457.6259765625, 44.69279861450195312, 0.15707901120185852, 0, 0, 0.078458786010742187, 0.996917366981506347, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+40, 113768, 530, 3524, 3576, '0', 0, 0, -4119.05859375, -12466.28515625, 44.92216110229492187, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+41, 113768, 530, 3524, 3576, '0', 0, 0, -4187.65478515625, -12441.2529296875, 43.54225921630859375, 0.907570242881774902, 0, 0, 0.438370704650878906, 0.898794233798980712, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+42, 113768, 530, 3524, 3576, '0', 0, 0, -4214.66259765625, -12509.1826171875, 45.62058258056640625, 4.9218292236328125, 0, 0, -0.62932014465332031, 0.77714616060256958, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+43, 113768, 530, 3524, 3576, '0', 0, 0, -4179.55615234375, -12503.681640625, 44.36132049560546875, 3.560472726821899414, 0, 0, -0.97814750671386718, 0.207912087440490722, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+44, 113768, 530, 3524, 3576, '0', 0, 0, -4164.70751953125, -12450.853515625, 43.98172760009765625, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+45, 113768, 530, 3524, 3576, '0', 0, 0, -4226.50830078125, -12461.1337890625, 46.89155197143554687, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+46, 113768, 530, 3524, 3576, '0', 0, 0, -4218.46826171875, -12464.912109375, 45.33121490478515625, 2.775068521499633789, 0, 0, 0.983254432678222656, 0.182238012552261352, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+47, 113768, 530, 3524, 3576, '0', 0, 0, -4138.423828125, -12489.173828125, 43.98773574829101562, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+48, 113768, 530, 3524, 3576, '0', 0, 0, -4174.0458984375, -12499.55078125, 44.35198211669921875, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+49, 113768, 530, 3524, 3576, '0', 0, 0, -4140.8154296875, -12536.91015625, 45.58305740356445312, 5.881760597229003906, 0, 0, -0.19936752319335937, 0.979924798011779785, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+50, 113768, 530, 3524, 3576, '0', 0, 0, -4232.0673828125, -12510.0615234375, 45.498443603515625, 2.530723094940185546, 0, 0, 0.953716278076171875, 0.300707906484603881, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+51, 113768, 530, 3524, 3576, '0', 0, 0, -4238.49365234375, -12511.97265625, 46.19207000732421875, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+52, 113768, 530, 3524, 3576, '0', 0, 0, -4149.318359375, -12451.025390625, 44.22807693481445312, 6.161012649536132812, 0, 0, -0.06104850769042968, 0.998134791851043701, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+53, 113768, 530, 3524, 3576, '0', 0, 0, -4229.58056640625, -12465.6484375, 46.10487747192382812, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+54, 113768, 530, 3524, 3576, '0', 0, 0, -4125.16015625, -12529.400390625, 44.402801513671875, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+55, 113768, 530, 3524, 3576, '0', 0, 0, -4212.9794921875, -12506.271484375, 45.41414642333984375, 2.303830623626708984, 0, 0, 0.913544654846191406, 0.406738430261611938, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+56, 113768, 530, 3524, 3576, '0', 0, 0, -4158.24169921875, -12536.68359375, 45.23476028442382812, 4.572763919830322265, 0, 0, -0.75470924377441406, 0.656059443950653076, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+57, 113768, 530, 3524, 3576, '0', 0, 0, -4184.04833984375, -12563.8427734375, 40.13847732543945312, 4.747295856475830078, 0, 0, -0.69465827941894531, 0.719339847564697265, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+58, 113768, 530, 3524, 3576, '0', 0, 0, -4228.81201171875, -12471.248046875, 45.97747421264648437, 4.101525306701660156, 0, 0, -0.88701057434082031, 0.461749136447906494, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2
(@OGUID+59, 113768, 530, 3524, 3576, '0', 0, 0, -4196.94482421875, -12443.091796875, 45.49990081787109375, 0.890116631984710693, 0, 0, 0.430510520935058593, 0.902585566043853759, 300, 255, 1, 48999), -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject1
(@OGUID+60, 113768, 530, 3524, 3576, '0', 0, 0, -4219.15234375, -12507.3642578125, 45.38512039184570312, 3.752462387084960937, 0, 0, -0.95371627807617187, 0.300707906484603881, 300, 255, 1, 48999); -- Brightly Colored Egg (Area: Azure Watch - Difficulty: 0) CreateObject2

UPDATE `pool_template` SET `description`='Noblegarden - Azure Watch - Brightly Colored Egg' WHERE `entry`=@POOL;

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
