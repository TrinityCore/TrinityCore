SET @CGUID := 6000060;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+63;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 106788, 1220, 7334, 7633, '0', 0, 0, 0, 0, -373.409, 5448.317, 45.64336, 2.476745367050170898, 120, 0, 0, 7846, 0, 1, 0, 0, 46597), -- Animated Construct (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -266.479156494140625, 5559.63525390625, 52.14516067504882812, 1.409039139747619628, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+2, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -352.982635498046875, 5441.21337890625, 46.6714630126953125, 3.716156482696533203, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+3, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -332.920135498046875, 5449.59033203125, 46.67163848876953125, 0.125734224915504455, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+4, 105838, 1220, 7334, 7633, '0', 0, 0, 0, 0, -455.109375, 5629.90283203125, 28.24384307861328125, 4.415099143981933593, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Redcrested Heron (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+5, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -357.5469, 5479.935, 42.50586, 0.225232899188995361, 120, 0, 0, 3138, 3801, 2, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 106788, 1220, 7334, 7633, '0', 0, 0, 0, 0, -354.3142, 5480.985, 42.28173, 5.916042327880859375, 120, 0, 0, 7846, 0, 0, 0, 0, 46597), -- Animated Construct (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+7, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -329.6944580078125, 5450.30126953125, 46.67163848876953125, 3.137869596481323242, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+8, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -354.821197509765625, 5439.7978515625, 46.66346359252929687, 0.577104866504669189, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+9, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -317.7882080078125, 5539.41064453125, 38.78015899658203125, 3.401261568069458007, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+10, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -340.09722900390625, 5551.96875, 40.12644195556640625, 1.312368631362915039, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+11, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -319.664947509765625, 5544.0634765625, 38.8217620849609375, 4.99699258804321289, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 39550 - Arcane Channeling)
(@CGUID+12, 109349, 1220, 7334, 7633, '0', 0, 0, 0, 0, -253.7210693359375, 5519.22998046875, 51.08248138427734375, 5.706237316131591796, 120, 10, 0, 3923, 0, 1, 0, 0, 46597), -- Veil Shadowrunner (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 221736 - Aura of Lethargy) (possible waypoints or random movement)
(@CGUID+13, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -343.611114501953125, 5553.16162109375, 40.12653732299804687, 4.394257545471191406, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+14, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -376.4288330078125, 5490.40283203125, 42.03472137451171875, 6.239305019378662109, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+15, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -265.80902099609375, 5563.34228515625, 52.1451568603515625, 4.119869709014892578, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 39550 - Arcane Channeling)
(@CGUID+16, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -343.142364501953125, 5549.22314453125, 40.22283935546875, 1.587201952934265136, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 174127 - UseKneeling)
(@CGUID+17, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -373.5069580078125, 5490.376953125, 41.93836212158203125, 3.156121730804443359, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+18, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -297.467010498046875, 5403.5869140625, 44.86187744140625, 1.851032853126525878, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+19, 106788, 1220, 7334, 7633, '0', 0, 0, 0, 0, -363.857635498046875, 5465.08154296875, 45.64453125, 1.198774576187133789, 120, 0, 0, 7846, 0, 0, 0, 0, 46597), -- Animated Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+20, 109349, 1220, 7334, 7633, '0', 0, 0, 0, 0, -261.85540771484375, 5517.3134765625, 50.72237396240234375, 2.577557802200317382, 120, 10, 0, 3923, 0, 1, 0, 0, 46597), -- Veil Shadowrunner (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 221736 - Aura of Lethargy) (possible waypoints or random movement)
(@CGUID+21, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -323.3663330078125, 5539.05810546875, 38.8217620849609375, 6.228006839752197265, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 174127 - UseKneeling)
(@CGUID+22, 93725, 1220, 7334, 7633, '0', 0, 0, 0, 0, -321.620941162109375, 5389.572265625, 46.33839797973632812, 0.595044732093811035, 120, 10, 0, 27, 0, 1, 0, 0, 46597), -- Slithering Brownscale (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+23, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -297.4913330078125, 5408.39599609375, 44.86187744140625, 4.765684127807617187, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+24, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -369.0608, 5449.991, 45.64336, 2.476617336273193359, 120, 0, 0, 3138, 3801, 2, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+25, 64782, 1220, 7334, 7633, '0', 0, 0, 0, 0, -251.983535766601562, 5491.134765625, 47.83051300048828125, 5.276004314422607421, 120, 10, 0, 5, 0, 1, 0, 0, 46597), -- Bandicoon (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+26, 106873, 1220, 7334, 7633, '0', 0, 0, 0, 0, -393.78125, 5398.84375, 66.44329833984375, 1.444271683692932128, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Font of Arcane Energy (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 212102 - Arcane Font Area Aura)
(@CGUID+27, 106788, 1220, 7334, 7633, '0', 0, 0, 0, 0, -373.921875, 5398.15966796875, 55.68677520751953125, 1.887563228607177734, 120, 0, 0, 7846, 0, 0, 0, 0, 46597), -- Animated Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+28, 106873, 1220, 7334, 7633, '0', 0, 0, 0, 0, -401.732635498046875, 5427.95068359375, 59.65628433227539062, 1.444271683692932128, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Font of Arcane Energy (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 212102 - Arcane Font Area Aura)
(@CGUID+29, 62050, 1220, 7334, 7633, '0', 0, 0, 0, 0, -381.25, 5376.5625, 56.14982223510742187, 5.588589191436767578, 120, 10, 0, 27, 0, 1, 0, 0, 46597), -- Grey Moth (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+30, 64782, 1220, 7334, 7633, '0', 0, 0, 0, 0, -403.125, 5478.125, 45.07278060913085937, 3.926990985870361328, 120, 10, 0, 5, 0, 1, 0, 0, 46597), -- Bandicoon (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+31, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -394.673614501953125, 5359.767578125, 73.20037841796875, 0.576232433319091796, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 174127 - UseKneeling)
(@CGUID+32, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -412.3350830078125, 5380.6474609375, 67.73580169677734375, 0.879569649696350097, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+33, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -390.8194580078125, 5362.1025390625, 73.20037841796875, 4.473836421966552734, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+34, 93725, 1220, 7334, 7633, '0', 0, 0, 0, 0, -418.802398681640625, 5462.2919921875, 49.68837356567382812, 1.171420812606811523, 120, 10, 0, 27, 0, 1, 0, 0, 46597), -- Slithering Brownscale (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+35, 106873, 1220, 7334, 7633, '0', 0, 0, 0, 0, -363.782989501953125, 5358.05908203125, 59.54906463623046875, 1.444271683692932128, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Font of Arcane Energy (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 212102 - Arcane Font Area Aura)
(@CGUID+36, 106873, 1220, 7334, 7633, '0', 0, 0, 0, 0, -420.703125, 5432.31787109375, 71.13942718505859375, 1.444271683692932128, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Font of Arcane Energy (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 212102 - Arcane Font Area Aura)
(@CGUID+37, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -409.4444580078125, 5380.42626953125, 67.8154144287109375, 2.847146034240722656, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 39550 - Arcane Channeling)
(@CGUID+38, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -421.317718505859375, 5477.27978515625, 45.15039825439453125, 2.618922233581542968, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 39550 - Arcane Channeling)
(@CGUID+39, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -440.704864501953125, 5340.587890625, 67.00826263427734375, 6.082457542419433593, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+40, 90507, 1220, 7334, 7633, '0', 0, 0, 0, 0, -452.888885498046875, 5409.24755859375, 70.34777069091796875, 5.255496978759765625, 120, 0, 0, 39230, 1534, 0, 0, 0, 46597), -- Leodrath (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+41, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -439.701385498046875, 5343.431640625, 67.21117401123046875, 4.436843395233154296, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 39550 - Arcane Channeling)
(@CGUID+42, 90505, 1220, 7334, 7633, '0', 0, 0, 0, 0, -462.54339599609375, 5407.1396484375, 70.297393798828125, 6.20104074478149414, 120, 0, 0, 23538, 1534, 0, 0, 0, 46597), -- Syphonus (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 221001 - Syphonus - Level 3)
(@CGUID+43, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -426.463531494140625, 5475.15283203125, 45.26630401611328125, 1.024442911148071289, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 174127 - UseKneeling)
(@CGUID+44, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -419.6788330078125, 5482.095703125, 44.82660675048828125, 5.140187263488769531, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+45, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -424.477447509765625, 5479.09033203125, 45.0054931640625, 4.238976955413818359, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+46, 105838, 1220, 7334, 7633, '0', 0, 0, 0, 0, -447.342010498046875, 5611.1484375, 27.67786788940429687, 1.379690051078796386, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Redcrested Heron (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+47, 105838, 1220, 7334, 7633, '0', 0, 0, 0, 0, -419.1389, 5624.253, 27.71463, 5.177506923675537109, 120, 0, 0, 3923, 0, 2, 0, 0, 46597), -- Redcrested Heron (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+48, 106873, 1220, 7334, 7633, '0', 0, 0, 0, 0, -295.119781494140625, 5577.97998046875, 51.54800796508789062, 1.444271683692932128, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Font of Arcane Energy (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 212102 - Arcane Font Area Aura)
(@CGUID+49, 105838, 1220, 7334, 7633, '0', 0, 0, 0, 0, -344.845489501953125, 5627.7099609375, 39.14465713500976562, 5.989673137664794921, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Redcrested Heron (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+50, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -299.3056, 5590.456, 47.23318, 3.31734013557434082, 120, 0, 0, 3138, 3801, 2, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+51, 105838, 1220, 7334, 7633, '0', 0, 0, 0, 0, -348.0382080078125, 5591.4599609375, 40.88550567626953125, 5.982347965240478515, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Redcrested Heron (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+52, 106788, 1220, 7334, 7633, '0', 0, 0, 0, 0, -290.4627, 5591.55, 49.2366, 2.99190688133239746, 120, 0, 0, 7846, 0, 0, 0, 0, 46597), -- Animated Construct (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+53, 106873, 1220, 7334, 7633, '0', 0, 0, 0, 0, -314.12152099609375, 5597.37353515625, 51.3441925048828125, 1.444271683692932128, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Font of Arcane Energy (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 212102 - Arcane Font Area Aura)
(@CGUID+54, 93725, 1220, 7334, 7633, '0', 0, 0, 0, 0, -212.88958740234375, 5530.93603515625, 55.32502365112304687, 2.820768356323242187, 120, 10, 0, 27, 0, 1, 0, 0, 46597), -- Slithering Brownscale (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+55, 109349, 1220, 7334, 7633, '0', 0, 0, 0, 0, -347.954864501953125, 5617.2509765625, 39.2241058349609375, 5.811745166778564453, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Veil Shadowrunner (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 123169 - Mod Scale 105-110%, 221736 - Aura of Lethargy)
(@CGUID+56, 105838, 1220, 7334, 7633, '0', 0, 0, 0, 0, -391.767364501953125, 5592.14404296875, 28.17432403564453125, 3.782689094543457031, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Redcrested Heron (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+57, 105838, 1220, 7334, 7633, '0', 0, 0, 0, 0, -417.289947509765625, 5617.65185546875, 28.00778007507324218, 0.471877515316009521, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Redcrested Heron (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+58, 106788, 1220, 7334, 7633, '0', 0, 0, 0, 0, -232.548614501953125, 5599.69091796875, 61.58097076416015625, 3.354843616485595703, 120, 0, 0, 7846, 0, 0, 0, 0, 46597), -- Animated Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+59, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -232.078125, 5624.2724609375, 61.4494476318359375, 3.889101505279541015, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+60, 106782, 1220, 7334, 7633, '0', 0, 0, 0, 1, -233.78125, 5622.61474609375, 61.4494476318359375, 0.802744925022125244, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Nightborne Foehunter (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+61, 106689, 1220, 7334, 7633, '0', 0, 0, 0, 0, -215.864578247070312, 5598.7412109375, 61.18210220336914062, 1.044608473777770996, 120, 0, 0, 3923, 0, 0, 0, 0, 46597), -- Inactive Construct (Area: The Ruined Sanctum - Difficulty: 0)
(@CGUID+62, 106695, 1220, 7334, 7633, '0', 0, 0, 0, 0, -218.154510498046875, 5599.97314453125, 61.22283935546875, 6.006204605102539062, 120, 0, 0, 3138, 3801, 0, 0, 0, 46597), -- Nightborne Animator (Area: The Ruined Sanctum - Difficulty: 0) (Auras: 174127 - UseKneeling)
(@CGUID+63, 91079, 1220, 7334, 7633, '0', 0, 0, 0, 0, -354.2062, 5484.907, 41.42001, 2.919419527053833007, 120, 0, 0, 39230, 0, 2, 0, 0, 46597); -- Vashti the Wandering Merchant (Area: The Ruined Sanctum - Difficulty: 0) (possible waypoints or random movement)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+63;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+9, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+12, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 221736'),
(@CGUID+13, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+16, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'),
(@CGUID+17, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+18, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+20, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 221736'),
(@CGUID+21, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'),
(@CGUID+26, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '212102'),
(@CGUID+28, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '212102'),
(@CGUID+29, 0, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+31, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'),
(@CGUID+32, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+33, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '212102'),
(@CGUID+36, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '212102'),
(@CGUID+39, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+40, 0, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, ''),
(@CGUID+42, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '221001'),
(@CGUID+43, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127'),
(@CGUID+44, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+45, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+48, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '212102'),
(@CGUID+53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '212102'),
(@CGUID+55, 0, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169 221736'),
(@CGUID+60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''),
(@CGUID+61, 0, 0, 0, 0, 0, 0, 1, 0, 0, 10630, 0, 0, 0, ''),
(@CGUID+62, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '174127');

-- Creature Template
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (106695, 106782);
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=106689; -- Inactive Construct
UPDATE `creature_template` SET `unit_flags3`=16777217 WHERE `entry`=106873; -- Font of Arcane Energy

-- Creature movement
DELETE FROM `creature_template_movement` WHERE `CreatureId`=105838;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(105838, 1, 1, 0, 0, 0, 0, NULL);

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+60), -(@CGUID+59), -(@CGUID+17), -(@CGUID+14), -(@CGUID+2), -(@CGUID+8), -(@CGUID+7), -(@CGUID+3)) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+59), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self'),
(-(@CGUID+60), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self'),
(-(@CGUID+17), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self'),
(-(@CGUID+14), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self'),
(-(@CGUID+2), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self'),
(-(@CGUID+8), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self'),
(-(@CGUID+3), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self'),
(-(@CGUID+7), 0, 0, 0, 1, 0, 100, 0, 0, 0, 4000, 8000, 0, '', 5, 6, 273, 274, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 4s to 8s - Play Random Emote - to self');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+11), -(@CGUID+15), -(@CGUID+37), -(@CGUID+38), -(@CGUID+41)) AND `source_type`=0 AND `id`=0 AND `link`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+11), 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, '', 11, 39550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nightborne Animator - After Combat, On Respawn or Spawn - Cast spell "Arcane Channeling" - to self'),
(-(@CGUID+15), 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, '', 11, 39550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nightborne Animator - After Combat, On Respawn or Spawn - Cast spell "Arcane Channeling" - to self'),
(-(@CGUID+37), 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, '', 11, 39550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nightborne Animator - After Combat, On Respawn or Spawn - Cast spell "Arcane Channeling" - to self'),
(-(@CGUID+38), 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, '', 11, 39550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nightborne Animator - After Combat, On Respawn or Spawn - Cast spell "Arcane Channeling" - to self'),
(-(@CGUID+41), 0, 0, 0, 25, 0, 100, 1, 0, 0, 0, 0, 0, '', 11, 39550, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Nightborne Animator - After Combat, On Respawn or Spawn - Cast spell "Arcane Channeling" - to self');

-- Waypoints for CGUID+50
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+50;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+50, @CGUID+50, 0, 0, 515, 0, 0),
(@CGUID+50, @CGUID+52, 4, 270, 515, 2, 11);

SET @ENTRY := 106695;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -299.3056, 5590.456, 47.23318, 0),
(@PATH, 1, -307.5451, 5583.423, 45.45624, 0),
(@PATH, 2, -313.7309, 5577.147, 43.46735, 0),
(@PATH, 3, -318.9254, 5566.355, 40.01341, 6330),
(@PATH, 4, -313.7309, 5577.147, 43.46735, 0),
(@PATH, 5, -307.5451, 5583.423, 45.45624, 0),
(@PATH, 6, -299.377, 5590.365, 47.14907, 0),
(@PATH, 7, -289.416, 5597.057, 50.27407, 0),
(@PATH, 8, -280.1667, 5598.71, 52.28432, 0),
(@PATH, 9, -269.6441, 5595.191, 55.30923, 0),
(@PATH, 10, -259.5538, 5593.95, 58.14986, 0),
(@PATH, 11, -250.9913, 5594.636, 60.59626, 6587),
(@PATH, 12, -259.5538, 5593.95, 58.14986, 0),
(@PATH, 13, -269.6441, 5595.191, 55.30923, 0),
(@PATH, 14, -280.1667, 5598.71, 52.28432, 0),
(@PATH, 15, -289.3871, 5597.075, 50.15786, 0);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+50;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+50, @PATH, 1);

-- Waypoints for CGUID+24
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+24;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+24, @CGUID+24, 0, 0, 515, 0, 0),
(@CGUID+24, @CGUID+0, 4, 270, 515, 6, 14);

SET @ENTRY := 106695;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -369.0608, 5449.991, 45.64336, 0),
(@PATH, 1, -363.4792, 5447.36, 45.8112, 0),
(@PATH, 2, -356.8281, 5447.413, 46.30436, 0),
(@PATH, 3, -345.842, 5444.789, 46.6862, 0),
(@PATH, 4, -337.2882, 5441.077, 46.6862, 0),
(@PATH, 5, -330.3698, 5435.118, 46.68224, 0),
(@PATH, 6, -327.6354, 5428.725, 46.61489, 0),
(@PATH, 7, -324.7795, 5424.231, 46.61489, 7001),
(@PATH, 8, -327.6354, 5428.725, 46.61489, 0),
(@PATH, 9, -330.3698, 5435.118, 46.68224, 0),
(@PATH, 10, -337.2882, 5441.077, 46.6862, 0),
(@PATH, 11, -345.842, 5444.789, 46.6862, 0),
(@PATH, 12, -356.8281, 5447.413, 46.30436, 0),
(@PATH, 13, -363.4792, 5447.36, 45.8112, 0),
(@PATH, 14, -369.0608, 5449.991, 45.64336, 0),
(@PATH, 15, -374.1858, 5454.01, 45.64336, 6985);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+24;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+24, @PATH, 1);

-- Waypoints for CGUID+5
DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+5;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+5, @CGUID+5, 0, 0, 515, 0, 0),
(@CGUID+5, @CGUID+6, 4, 270, 515, 3, 11);

SET @ENTRY := 106695;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -357.5469, 5479.935, 42.50586, 0),
(@PATH, 1, -364.9201, 5479.281, 43.78851, 0),
(@PATH, 2, -373.1615, 5479.533, 45.43231, 0),
(@PATH, 3, -378.6198, 5478.004, 45.63371, 0),
(@PATH, 4, -383.1007, 5471.745, 45.69182, 3911),
(@PATH, 5, -397.6163, 5457.258, 46.27642, 7575),
(@PATH, 6, -391.1337, 5462.859, 45.64336, 0),
(@PATH, 7, -383.1007, 5471.745, 45.69182, 5128),
(@PATH, 8, -378.6198, 5478.004, 45.63371, 0),
(@PATH, 9, -373.1615, 5479.533, 45.43231, 0),
(@PATH, 10, -364.9201, 5479.281, 43.78851, 0),
(@PATH, 11, -357.6797, 5479.876, 42.56763, 0),
(@PATH, 12, -351.0816, 5482.036, 42.0576, 9510);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+5;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+5, @PATH, 1);

-- Waypoints for CGUID+63
SET @ENTRY := 91079;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -323.1181, 5488.401, 39.18419, 0),
(@PATH, 1, -309.8299, 5478.066, 39.81639, 0),
(@PATH, 2, -300.0139, 5473.016, 40.74877, 0),
(@PATH, 3, -285.0174, 5469.624, 42.67219, 0),
(@PATH, 4, -269.7847, 5451.196, 43.29009, 0),
(@PATH, 5, -244.7795, 5446.602, 43.13038, 0),
(@PATH, 6, -213.1129, 5448.566, 41.40346, 0),
(@PATH, 7, -177.3281, 5444.233, 38.88076, 0),
(@PATH, 8, -146.7795, 5427.411, 37.44186, 0),
(@PATH, 9, -124.2448, 5421.178, 36.37791, 0),
(@PATH, 10, -110.7535, 5422.314, 36.75291, 0),
(@PATH, 11, -92.51389, 5430.403, 36.37395, 0),
(@PATH, 12, -76.21702, 5441.951, 36.33125, 0),
(@PATH, 13, -50.30729, 5451.575, 36.68463, 0),
(@PATH, 14, -31.11806, 5449.493, 36.46262, 0),
(@PATH, 15, -18.36285, 5447.395, 36.71079, 0),
(@PATH, 16, -8.118055, 5446.931, 36.67429, 0),
(@PATH, 17, 3.4375, 5448.47, 37.32616, 0),
(@PATH, 18, 37.51223, 5454.67, 39.31726, 0),
(@PATH, 19, 64.38021, 5458.758, 39.52039, 0),
(@PATH, 20, 80.94271, 5461.274, 38.68176, 0),
(@PATH, 21, 101.3368, 5465.957, 37.3343, 0),
(@PATH, 22, 121.3073, 5472.413, 37.75285, 0),
(@PATH, 23, 154.816, 5489.641, 39.92801, 0),
(@PATH, 24, 178.0938, 5499.305, 40.79088, 0),
(@PATH, 25, 199.0898, 5512.879, 41.48894, 0),
(@PATH, 26, 208.8073, 5532.159, 41.58424, 0),
(@PATH, 27, 230.8767, 5552.397, 40.25124, 0),
(@PATH, 28, 239.1424, 5559.527, 39.95077, 0),
(@PATH, 29, 241.7326, 5567.951, 39.02272, 0),
(@PATH, 30, 250.7569, 5576.34, 38.96755, 0),
(@PATH, 31, 266.9688, 5599.284, 39.85987, 0),
(@PATH, 32, 278.9826, 5615.006, 39.966, 0),
(@PATH, 33, 298.007, 5629.406, 39.23797, 0),
(@PATH, 34, 313.0695, 5636.312, 40.67963, 0),
(@PATH, 35, 328.0191, 5644.69, 41.60443, 0),
(@PATH, 36, 347.8299, 5646.351, 45.05851, 0),
(@PATH, 37, 373.6615, 5643.768, 51.51994, 0),
(@PATH, 38, 396.1163, 5645.524, 55.66056, 0),
(@PATH, 39, 427.2422, 5652.962, 60.69233, 0),
(@PATH, 40, 456.9722, 5654.959, 65.85608, 0),
(@PATH, 41, 483.4566, 5656.037, 70.94289, 0),
(@PATH, 42, 518.0833, 5657.992, 74.85265, 0),
(@PATH, 43, 549.8965, 5654.492, 78.07094, 0),
(@PATH, 44, 568.0434, 5644.987, 80.82555, 0),
(@PATH, 45, 588.2518, 5631.596, 83.21295, 0),
(@PATH, 46, 609.9149, 5619.464, 84.27079, 0),
(@PATH, 47, 625.7952, 5605.567, 84.41691, 0),
(@PATH, 48, 649.5903, 5586.772, 83.96583, 0),
(@PATH, 49, 663.2309, 5573.207, 83.59083, 0),
(@PATH, 50, 663.2587, 5559.8, 83.69006, 0),
(@PATH, 51, 670.6649, 5551.746, 83.61244, 0),
(@PATH, 52, 677.5989, 5548.604, 83.61244, 0),
(@PATH, 53, 689.2691, 5554.502, 83.61244, 0),
(@PATH, 54, 696.7587, 5558.381, 83.36244, 0),
(@PATH, 55, 721.9896, 5548.842, 82.14772, 0),
(@PATH, 56, 740.7882, 5543.169, 82.00462, 0),
(@PATH, 57, 767.0452, 5526.348, 83.361, 0),
(@PATH, 58, 790.9132, 5508.617, 84.22733, 0),
(@PATH, 59, 816.9184, 5480.697, 81.44561, 0),
(@PATH, 60, 843.5833, 5463.092, 77.80033, 0),
(@PATH, 61, 877.2847, 5444.03, 70.39445, 60885),
(@PATH, 62, 843.5833, 5463.092, 77.80033, 0),
(@PATH, 63, 816.9184, 5480.697, 81.44561, 0),
(@PATH, 64, 790.9132, 5508.617, 84.22733, 0),
(@PATH, 65, 767.0452, 5526.348, 83.361, 0),
(@PATH, 66, 740.7882, 5543.169, 82.00462, 0),
(@PATH, 67, 721.9896, 5548.842, 82.14772, 0),
(@PATH, 68, 696.7587, 5558.381, 83.36244, 0),
(@PATH, 69, 689.2691, 5554.502, 83.61244, 0),
(@PATH, 70, 677.5989, 5548.604, 83.61244, 0),
(@PATH, 71, 670.6649, 5551.746, 83.61244, 0),
(@PATH, 72, 663.2587, 5559.8, 83.69006, 0),
(@PATH, 73, 663.2309, 5573.207, 83.59083, 0),
(@PATH, 74, 649.5903, 5586.772, 83.96583, 0),
(@PATH, 75, 625.7952, 5605.567, 84.41691, 0),
(@PATH, 76, 609.9149, 5619.464, 84.27079, 0),
(@PATH, 77, 588.2518, 5631.596, 83.21295, 0),
(@PATH, 78, 568.0434, 5644.987, 80.82555, 0),
(@PATH, 79, 550.0226, 5654.468, 78.13625, 0),
(@PATH, 80, 518.0833, 5657.992, 74.85265, 0),
(@PATH, 81, 483.4566, 5656.037, 70.94289, 0),
(@PATH, 82, 456.9722, 5654.959, 65.85608, 0),
(@PATH, 83, 427.375, 5652.983, 60.63739, 0),
(@PATH, 84, 396.1163, 5645.524, 55.66056, 0),
(@PATH, 85, 373.6615, 5643.768, 51.51994, 0),
(@PATH, 86, 347.8299, 5646.351, 45.05851, 0),
(@PATH, 87, 328.0191, 5644.69, 41.60443, 0),
(@PATH, 88, 313.0695, 5636.312, 40.67963, 0),
(@PATH, 89, 298.007, 5629.406, 39.23797, 0),
(@PATH, 90, 278.9826, 5615.006, 39.966, 0),
(@PATH, 91, 266.9688, 5599.284, 39.85987, 0),
(@PATH, 92, 250.7569, 5576.34, 38.96755, 0),
(@PATH, 93, 241.7326, 5567.951, 39.02272, 0),
(@PATH, 94, 239.1424, 5559.527, 39.95077, 0),
(@PATH, 95, 230.8767, 5552.397, 40.25124, 0),
(@PATH, 96, 208.8073, 5532.159, 41.58424, 0),
(@PATH, 97, 199.2153, 5512.966, 41.48894, 0),
(@PATH, 98, 178.0938, 5499.305, 40.79088, 0),
(@PATH, 99, 154.816, 5489.641, 39.92801, 0),
(@PATH, 100, 121.3073, 5472.413, 37.75285, 0),
(@PATH, 101, 101.3368, 5465.957, 37.3343, 0),
(@PATH, 102, 80.94271, 5461.274, 38.68176, 0),
(@PATH, 103, 64.38021, 5458.758, 39.52039, 0),
(@PATH, 104, 37.61632, 5454.689, 39.31726, 0),
(@PATH, 105, 3.4375, 5448.47, 37.32616, 0),
(@PATH, 106, -8.118055, 5446.931, 36.67429, 0),
(@PATH, 107, -18.36285, 5447.395, 36.71079, 0),
(@PATH, 108, -31.11806, 5449.493, 36.46262, 0),
(@PATH, 109, -50.30729, 5451.575, 36.68463, 0),
(@PATH, 110, -76.21702, 5441.951, 36.33125, 0),
(@PATH, 111, -92.51389, 5430.403, 36.37395, 0),
(@PATH, 112, -110.7535, 5422.314, 36.75291, 0),
(@PATH, 113, -124.2448, 5421.178, 36.37791, 0),
(@PATH, 114, -146.7795, 5427.411, 37.44186, 0),
(@PATH, 115, -177.3281, 5444.233, 38.88076, 0),
(@PATH, 116, -213.1129, 5448.566, 41.40346, 0),
(@PATH, 117, -244.7795, 5446.602, 43.13038, 0),
(@PATH, 118, -269.7847, 5451.196, 43.29009, 0),
(@PATH, 119, -285.0174, 5469.624, 42.67219, 0),
(@PATH, 120, -300.0139, 5473.016, 40.74877, 0),
(@PATH, 121, -309.8299, 5478.066, 39.81639, 0),
(@PATH, 122, -323.1181, 5488.401, 39.18419, 0),
(@PATH, 123, -339.5382, 5505.313, 38.76248, 60406);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+63;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+63, @PATH, 1);

-- waypoints for CGUID+47
SET @ENTRY := 105838;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `delay`) VALUES
(@PATH, 0, -419.1389, 5624.253, 27.71463, 0),
(@PATH, 1, -410.5746, 5615.692, 27.47765, 0),
(@PATH, 2, -407.3559, 5609.792, 27.62821, 0),
(@PATH, 3, -400.9392, 5599.213, 26.71984, 0),
(@PATH, 4, -393.4271, 5591.073, 27.34663, 0),
(@PATH, 5, -390.5538, 5585.287, 27.18698, 10055),
(@PATH, 6, -400.8828, 5599.161, 26.5736, 0),
(@PATH, 7, -407.3559, 5609.792, 27.62821, 0),
(@PATH, 8, -410.5746, 5615.692, 27.47765, 0),
(@PATH, 9, -419.1389, 5624.253, 27.71463, 0),
(@PATH, 10, -430.3368, 5626.479, 27.6646, 23062);

DELETE FROM `creature_addon` WHERE `guid`= @CGUID+47;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+47, @PATH, 1);
