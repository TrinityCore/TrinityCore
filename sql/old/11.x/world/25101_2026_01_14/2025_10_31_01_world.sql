SET @CGUID := 6005969;
SET @OGUID := 6003048;
SET @SPAWN_GROUP := 1279;

DELETE FROM `battleground_scripts` WHERE `MapId` = 1552 AND `BattlemasterListId` = 0;
INSERT INTO `battleground_scripts` (`MapId`, `BattlemasterListId`, `ScriptName`) VALUES
(1552, 0, 'arena_ashamanes_fall');

DELETE FROM `battleground_template` WHERE `ID` = 816;
INSERT INTO `battleground_template` (`ID`, `AllianceStartLoc`, `HordeStartLoc`, `StartMaxDist`, `Weight`, `Comment`) VALUES
(816, 5308, 5307, 0, 1, 'Ashamanes Fall Arena');

DELETE FROM `spawn_group_template` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWN_GROUP+0, 'Ashamanes Fall - Shadow sight', 0x20);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+61;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 114570, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3566.59716796875, 5482.6181640625, 349.549407958984375, 2.348224639892578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ashamane Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+1, 114575, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3524.892333984375, 5435.3896484375, 308.139404296875, 0.209348410367965698, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Stag (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+2, 114574, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3714.002685546875, 5513.001953125, 323.7884521484375, 2.71767282485961914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Val'sharah Druid (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 191779 - Mod Scale 200%)
(@CGUID+3, 114575, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3588.306396484375, 5409.78125, 325.114288330078125, 1.991013288497924804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Stag (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+4, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3417.23779296875, 5483.009765625, 337.715423583984375, 0.022950712591409683, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+5, 114573, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3680.725830078125, 5564.13623046875, 304.436279296875, 4.952549934387207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Bear (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+6, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3627.900146484375, 5685.39306640625, 344.26544189453125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+7, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3579.713134765625, 5448.796875, 341.028472900390625, 5.446562767028808593, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+8, 114572, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3534.5, 5477.15087890625, 332.36285400390625, 0.746128618717193603, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Vale Flitter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+9, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3474.677978515625, 5555.5869140625, 332.458740234375, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+10, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3533.48193359375, 5659.869140625, 317.437408447265625, 0.022975897416472435, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+11, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3481.13525390625, 5683.60009765625, 319.048095703125, 6.270677566528320312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+12, 114572, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3576.113037109375, 5567.59375, 333.7896728515625, 1.173004865646362304, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Vale Flitter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+13, 114577, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3645.893310546875, 5497.51416015625, 310.78704833984375, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking)
(@CGUID+14, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3623.14404296875, 5481.21142578125, 314.567901611328125, 1.321498394012451171, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+15, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3725.5908203125, 5544.41064453125, 334.8209228515625, 0.386281400918960571, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+16, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3578.8369140625, 5687.58984375, 327.59228515625, 0.038545060902833938, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+17, 114577, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3470.21875, 5668.962890625, 308.47906494140625, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking)
(@CGUID+18, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3650.512939453125, 5502.97998046875, 328.696929931640625, 1.248853206634521484, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+19, 114580, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3536.828125, 5414.6015625, 314.70245361328125, 6.255576133728027343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Fawn (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+20, 114575, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3449.43310546875, 5681.494140625, 308.378662109375, 5.221735477447509765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Stag (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+21, 114574, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3695.038330078125, 5473.20166015625, 325.553985595703125, 1.30809175968170166, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Val'sharah Druid (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 191779 - Mod Scale 200%)
(@CGUID+22, 114572, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3543.11376953125, 5595.3349609375, 331.510284423828125, 4.17545938491821289, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Vale Flitter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+23, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3369.75341796875, 5593.24365234375, 323.353851318359375, 6.270665168762207031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+24, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3675.827392578125, 5581.76416015625, 313.905242919921875, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+25, 114577, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3668.3359375, 5451.63525390625, 307.818603515625, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking)
(@CGUID+26, 114580, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3524.100830078125, 5428.353515625, 308.922454833984375, 1.056080222129821777, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Fawn (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+27, 114611, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3568.795166015625, 5569.92529296875, 326.390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Elfin Rabbit (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+28, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3645.4345703125, 5577.521484375, 314.6214599609375, 5.270051002502441406, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+29, 114575, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3471.5234375, 5681.494140625, 308.095184326171875, 4.807647228240966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Stag (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+30, 114577, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3550, 5433.3330078125, 307.70001220703125, 3.014180183410644531, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking)
(@CGUID+31, 114570, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3527.880126953125, 5473.3583984375, 357.841949462890625, 1.327366352081298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ashamane Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+32, 114575, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3618.608642578125, 5453.73095703125, 312.67779541015625, 2.816527128219604492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Stag (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+33, 114569, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3531.474853515625, 5472.9765625, 358.91900634765625, 1.3126220703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Ashamane Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+34, 114574, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3689.0166015625, 5510.60791015625, 312.502685546875, 2.469567298889160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Val'sharah Druid (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 191779 - Mod Scale 200%)
(@CGUID+35, 114573, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3691.520751953125, 5554.275390625, 305.063507080078125, 2.997097969055175781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Bear (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+36, 114575, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3597.880126953125, 5439.392578125, 313.45977783203125, 1.991013288497924804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Stag (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+37, 114572, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3590.776123046875, 5511.234375, 334.070343017578125, 3.623198270797729492, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Vale Flitter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+38, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3448.345947265625, 5648.869140625, 327.518829345703125, 6.244733333587646484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+39, 114573, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3703.615478515625, 5608.90283203125, 314.83673095703125, 2.75619053840637207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Bear (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+40, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3515.24169921875, 5453.9853515625, 337.085357666015625, 3.629119873046875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+41, 114572, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3525.283203125, 5521.8095703125, 335.735992431640625, 3.901186943054199218, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Vale Flitter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+42, 114577, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3479.13037109375, 5616.26025390625, 307.31829833984375, 5.859136104583740234, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking)
(@CGUID+43, 114611, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3558.8681640625, 5493.6083984375, 325.328033447265625, 0.162741750478744506, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Elfin Rabbit (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+44, 114576, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3538.4453125, 5418.24462890625, 312.430633544921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Doe (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+45, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3467.78271484375, 5511.35400390625, 337.883514404296875, 2.926533460617065429, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+46, 114577, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3513.359375, 5650.39892578125, 307.70001220703125, 0.568886041641235351, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking)
(@CGUID+47, 114581, 1552, 8008, 8008, '0', '0', 0, 0, 1, 3568.24658203125, 5420.5146484375, 311.51690673828125, 1.717264890670776367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Nat Pagle (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+48, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3678.978271484375, 5523.60888671875, 326.374664306640625, 4.479571819305419921, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+49, 114575, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3455.760498046875, 5483.35693359375, 317.388031005859375, 0.917567670345306396, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Stag (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+50, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3646.794677734375, 5596.8740234375, 328.595428466796875, 0.022975854575634002, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+51, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3608.611083984375, 5610.302734375, 333.926544189453125, 4.674623489379882812, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+52, 114573, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3692.950439453125, 5639.896484375, 331.3941650390625, 3.544946193695068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Bear (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+53, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3378.453369140625, 5530.15771484375, 334.429656982421875, 0.038442760705947875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+54, 114572, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3565.921142578125, 5578.99560546875, 332.101226806640625, 4.829363346099853515, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Vale Flitter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+55, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3611.813232421875, 5517.74951171875, 344.128662109375, 3.734572649002075195, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+56, 114579, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3713.670166015625, 5563.21142578125, 336.975250244140625, 6.244760513305664062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Sylvan Owl (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+57, 114578, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3619.833740234375, 5557.17626953125, 339.33697509765625, 3.620345115661621093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Fey Darter (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+58, 114577, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3609.82275390625, 5479.4150390625, 307.70001220703125, 2.652393102645874023, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject1 (Auras: 113160 - Water Walking)
(@CGUID+59, 114576, 1552, 8008, 8008, '0', '0', 0, 0, 0, 3523.171142578125, 5430.2958984375, 308.669036865234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305), -- Gleamhoof Doe (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@CGUID+60, 114577, 1552, 8008, 8008, '0', '170', 0, 0, 0, 3577.381103515625, 5449.7353515625, 310.374481201171875, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 63305), -- Sylvan Strider (Area: Ashamane's Fall - Difficulty: 0) CreateObject2
(@CGUID+61, 114573, 1552, 8008, 8008, '0', '170', 0, 0, 0, 3645.815185546875, 5649.59375, 323.54937744140625, 2.011730432510375976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 63305); -- Sylvan Bear (Area: Ashamane's Fall - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+61;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 4782, 0, 0, 0, ''), -- Ashamane Owl
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Gleamhoof Stag
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191779'), -- Val'sharah Druid - 191779 - Mod Scale 200%
(@CGUID+4, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+6, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+7, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+8, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Flitter
(@CGUID+9, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+10, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+11, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+12, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Flitter
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'), -- Sylvan Strider - 113160 - Water Walking
(@CGUID+14, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+15, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+16, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'), -- Sylvan Strider - 113160 - Water Walking
(@CGUID+18, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Gleamhoof Stag
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191779'), -- Val'sharah Druid - 191779 - Mod Scale 200%
(@CGUID+22, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Flitter
(@CGUID+23, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+24, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'), -- Sylvan Strider - 113160 - Water Walking
(@CGUID+28, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Gleamhoof Stag
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'), -- Sylvan Strider - 113160 - Water Walking
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 0, 4782, 0, 0, 0, ''), -- Ashamane Owl
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 0, 4782, 0, 0, 0, ''), -- Ashamane Owl
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191779'), -- Val'sharah Druid - 191779 - Mod Scale 200%
(@CGUID+37, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Flitter
(@CGUID+38, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+40, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+41, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Flitter
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'), -- Sylvan Strider - 113160 - Water Walking
(@CGUID+45, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'), -- Sylvan Strider - 113160 - Water Walking
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 0, 2171, 0, 0, 0, ''), -- Nat Pagle
(@CGUID+48, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+50, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+51, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+53, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+54, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Vale Flitter
(@CGUID+55, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+56, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Sylvan Owl
(@CGUID+57, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Fey Darter
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '113160'); -- Sylvan Strider - 113160 - Water Walking

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 250431, 1552, 8008, 8008, '0', '0', 0, 3539.869873046875, 5488.70068359375, 323.581939697265625, 1.553341388702392578, 0, 0, 0.700908660888671875, 0.713251054286956787, 7200, 255, 1, 63305), -- Roots (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@OGUID+1, 250430, 1552, 8008, 8008, '0', '0', 0, 3548.342041015625, 5584.77880859375, 323.6123046875, 1.544615507125854492, 0, 0, 0.697790145874023437, 0.716302275657653808, 7200, 255, 1, 63305), -- Roots (Area: Ashamane's Fall - Difficulty: 0) CreateObject1
(@OGUID+2, 184663, 1552, 8008, 8008, '0', '0', 0, 3579.07470703125, 5575.9375, 326.891265869140625, 2.460912704467773437, 0, 0, 0.942641258239746093, 0.333807557821273803, 360, 255, 1, 63305), -- Shadow Sight (Area: Ashamane's Fall - Difficulty: 0) CreateObject2
(@OGUID+3, 184664, 1552, 8008, 8008, '0', '0', 0, 3503.2822265625, 5502.15087890625, 325.707183837890625, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 360, 255, 1, 63305); -- Shadow Sight (Area: Ashamane's Fall - Difficulty: 0) CreateObject2
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;

DELETE FROM `spawn_group` WHERE `groupId` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWN_GROUP, 1, @OGUID+2),
(@SPAWN_GROUP, 1, @OGUID+3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 33 AND `SourceEntry` BETWEEN @SPAWN_GROUP+0 AND @SPAWN_GROUP+0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `SourceGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ScriptName`) VALUES
(33, @SPAWN_GROUP, 0, 0, 0, 'condition_is_shadow_sight_enabled');

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114576 AND `DifficultyID`=0); -- 114576 (Gleamhoof Doe) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114577 AND `DifficultyID`=0); -- 114577 (Sylvan Strider) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=114572 AND `DifficultyID`=0); -- 114572 (Vale Flitter) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=63305 WHERE (`Entry`=114578 AND `DifficultyID`=0); -- 114578 (Fey Darter) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114573 AND `DifficultyID`=0); -- 114573 (Sylvan Bear) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=63305 WHERE (`Entry`=114579 AND `DifficultyID`=0); -- 114579 (Sylvan Owl) - Floating - CannotSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114574 AND `DifficultyID`=0); -- 114574 (Val'sharah Druid) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=63305 WHERE (`Entry`=114575 AND `DifficultyID`=0); -- 114575 (Gleamhoof Stag) - CanSwim

UPDATE `creature_template` SET `unit_flags`=0x0 WHERE `entry`=114581; -- Nat Pagle
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x4000000 WHERE `entry`=114576; -- Gleamhoof Doe
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry` IN (114569, 114570); -- Ashamane Owl
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114611; -- Elfin Rabbit
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114580; -- Gleamhoof Fawn
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x8000000 WHERE `entry`=114577; -- Sylvan Strider
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114572; -- Vale Flitter
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114578; -- Fey Darter
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114573; -- Sylvan Bear
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114579; -- Sylvan Owl
UPDATE `creature_template` SET `unit_flags`=0x2000000 WHERE `entry`=114574; -- Val'sharah Druid
UPDATE `creature_template` SET `unit_flags`=0x2000000, `unit_flags3`=0x4000000 WHERE `entry`=114575; -- Gleamhoof Stag

UPDATE `creature_model_info` SET `BoundingRadius`=4.170724868774414062, `VerifiedBuild`=63305 WHERE `DisplayID`=73328;
UPDATE `creature_model_info` SET `BoundingRadius`=0.249518632888793945, `CombatReach`=0.300000011920928955, `VerifiedBuild`=63305 WHERE `DisplayID`=71224;
UPDATE `creature_model_info` SET `BoundingRadius`=2.085362434387207031, `VerifiedBuild`=63305 WHERE `DisplayID`=64330;

SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 114579;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6749, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3657.9001, 5685.393, 344.26544, NULL, 0),
(@PATH, 1, 3655.6165, 5696.8735, 344.26544, NULL, 0),
(@PATH, 2, 3649.1133, 5706.6064, 344.26544, NULL, 0),
(@PATH, 3, 3639.3806, 5713.1094, 344.26544, NULL, 0),
(@PATH, 4, 3627.9001, 5715.393, 344.26544, NULL, 0),
(@PATH, 5, 3616.4197, 5713.1094, 344.26544, NULL, 0),
(@PATH, 6, 3606.687, 5706.6064, 344.26544, NULL, 0),
(@PATH, 7, 3600.1838, 5696.8735, 344.26544, NULL, 0),
(@PATH, 8, 3597.9001, 5685.393, 344.26544, NULL, 0),
(@PATH, 9, 3600.1838, 5673.9126, 344.26544, NULL, 0),
(@PATH, 10, 3606.687, 5664.1797, 344.26544, NULL, 0),
(@PATH, 11, 3616.4197, 5657.677, 344.26544, NULL, 0),
(@PATH, 12, 3627.9001, 5655.393, 344.26544, NULL, 0),
(@PATH, 13, 3639.3806, 5657.677, 344.26544, NULL, 0),
(@PATH, 14, 3649.1133, 5664.1797, 344.26544, NULL, 0),
(@PATH, 15, 3655.6165, 5673.9126, 344.26544, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+10;
SET @ENTRY := 114579;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6749, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3561.2449, 5659.8413, 317.43744, NULL, 0),
(@PATH, 1, 3558.9612, 5648.361, 317.43744, NULL, 0),
(@PATH, 2, 3552.458, 5638.628, 317.43744, NULL, 0),
(@PATH, 3, 3542.7253, 5632.125, 317.43744, NULL, 0),
(@PATH, 4, 3531.2449, 5629.8413, 317.43744, NULL, 0),
(@PATH, 5, 3519.7644, 5632.125, 317.43744, NULL, 0),
(@PATH, 6, 3510.0317, 5638.628, 317.43744, NULL, 0),
(@PATH, 7, 3503.5286, 5648.361, 317.43744, NULL, 0),
(@PATH, 8, 3501.2449, 5659.8413, 317.43744, NULL, 0),
(@PATH, 9, 3503.5286, 5671.322, 317.43744, NULL, 0),
(@PATH, 10, 3510.0317, 5681.0547, 317.43744, NULL, 0),
(@PATH, 11, 3519.7644, 5687.5576, 317.43744, NULL, 0),
(@PATH, 12, 3531.2449, 5689.8413, 317.43744, NULL, 0),
(@PATH, 13, 3542.7253, 5687.5576, 317.43744, NULL, 0),
(@PATH, 14, 3552.458, 5681.0547, 317.43744, NULL, 0),
(@PATH, 15, 3558.9612, 5671.322, 317.43744, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+50;
SET @ENTRY := 114579;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6749, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3674.5574, 5596.846, 328.5954, NULL, 0),
(@PATH, 1, 3672.2737, 5585.3657, 328.5954, NULL, 0),
(@PATH, 2, 3665.7705, 5575.633, 328.5954, NULL, 0),
(@PATH, 3, 3656.0378, 5569.13, 328.5954, NULL, 0),
(@PATH, 4, 3644.5574, 5566.846, 328.5954, NULL, 0),
(@PATH, 5, 3633.077, 5569.13, 328.5954, NULL, 0),
(@PATH, 6, 3623.3442, 5575.633, 328.5954, NULL, 0),
(@PATH, 7, 3616.841, 5585.3657, 328.5954, NULL, 0),
(@PATH, 8, 3614.5574, 5596.846, 328.5954, NULL, 0),
(@PATH, 9, 3616.841, 5608.3267, 328.5954, NULL, 0),
(@PATH, 10, 3623.3442, 5618.0596, 328.5954, NULL, 0),
(@PATH, 11, 3633.077, 5624.5625, 328.5954, NULL, 0),
(@PATH, 12, 3644.5574, 5626.846, 328.5954, NULL, 0),
(@PATH, 13, 3656.0378, 5624.5625, 328.5954, NULL, 0),
(@PATH, 14, 3665.7705, 5618.0596, 328.5954, NULL, 0),
(@PATH, 15, 3672.2737, 5608.3267, 328.5954, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+56;
SET @ENTRY := 114579;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6747, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3739.0774, 5563.3125, 336.97525, NULL, 0),
(@PATH, 1, 3736.7937, 5574.793, 336.97525, NULL, 0),
(@PATH, 2, 3731.1033, 5584.1953, 338.1513, NULL, 0),
(@PATH, 3, 3720.5579, 5591.029, 336.97525, NULL, 0),
(@PATH, 4, 3709.0774, 5593.3125, 336.97525, NULL, 0),
(@PATH, 5, 3697.597, 5591.029, 336.97525, NULL, 0),
(@PATH, 6, 3687.8643, 5584.526, 336.97525, NULL, 0),
(@PATH, 7, 3681.361, 5574.793, 336.97525, NULL, 0),
(@PATH, 8, 3679.0774, 5563.3125, 336.97525, NULL, 0),
(@PATH, 9, 3681.361, 5551.832, 336.97525, NULL, 0),
(@PATH, 10, 3687.8643, 5542.099, 336.97525, NULL, 0),
(@PATH, 11, 3697.597, 5535.596, 336.97525, NULL, 0),
(@PATH, 12, 3709.0774, 5533.3125, 336.97525, NULL, 0),
(@PATH, 13, 3720.5579, 5535.596, 336.97525, NULL, 0),
(@PATH, 14, 3730.2905, 5542.099, 336.97525, NULL, 0),
(@PATH, 15, 3736.7937, 5551.832, 336.97525, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 114579;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6749, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3510.0408, 5683.607, 319.0481, NULL, 0),
(@PATH, 1, 3507.757, 5695.0874, 319.0481, NULL, 0),
(@PATH, 2, 3501.254, 5704.8203, 319.0481, NULL, 0),
(@PATH, 3, 3491.5212, 5711.323, 319.0481, NULL, 0),
(@PATH, 4, 3480.0408, 5713.607, 319.0481, NULL, 0),
(@PATH, 5, 3468.5603, 5711.323, 319.0481, NULL, 0),
(@PATH, 6, 3458.8276, 5704.8203, 319.0481, NULL, 0),
(@PATH, 7, 3452.3245, 5695.0874, 319.0481, NULL, 0),
(@PATH, 8, 3450.0408, 5683.607, 319.0481, NULL, 0),
(@PATH, 9, 3452.3245, 5672.1265, 319.0481, NULL, 0),
(@PATH, 10, 3458.8276, 5662.3936, 319.0481, NULL, 0),
(@PATH, 11, 3468.5603, 5655.8906, 319.0481, NULL, 0),
(@PATH, 12, 3480.0408, 5653.607, 319.0481, NULL, 0),
(@PATH, 13, 3491.5212, 5655.8906, 319.0481, NULL, 0),
(@PATH, 14, 3501.254, 5662.3936, 319.0481, NULL, 0),
(@PATH, 15, 3507.757, 5672.1265, 319.0481, NULL, 0);

UPDATE `creature` SET /*`position_x`=3510.0408, `position_y`=5683.607, `position_z`=319.0481, `orientation`=0,*/ `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+38;
SET @ENTRY := 114579;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6749, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3473.7527, 5648.9707, 327.51883, NULL, 0),
(@PATH, 1, 3471.469, 5660.451, 327.51883, NULL, 0),
(@PATH, 2, 3464.9658, 5670.184, 327.51883, NULL, 0),
(@PATH, 3, 3455.2332, 5676.687, 327.51883, NULL, 0),
(@PATH, 4, 3443.7527, 5678.9707, 327.51883, NULL, 0),
(@PATH, 5, 3432.2722, 5676.687, 327.51883, NULL, 0),
(@PATH, 6, 3422.5396, 5670.184, 327.51883, NULL, 0),
(@PATH, 7, 3416.0364, 5660.451, 327.51883, NULL, 0),
(@PATH, 8, 3413.7527, 5648.9707, 327.51883, NULL, 0),
(@PATH, 9, 3416.0364, 5637.49, 327.51883, NULL, 0),
(@PATH, 10, 3422.5396, 5627.7573, 327.51883, NULL, 0),
(@PATH, 11, 3432.2722, 5621.2544, 327.51883, NULL, 0),
(@PATH, 12, 3443.7527, 5618.9707, 327.51883, NULL, 0),
(@PATH, 13, 3455.2332, 5621.2544, 327.51883, NULL, 0),
(@PATH, 14, 3464.9658, 5627.7573, 327.51883, NULL, 0),
(@PATH, 15, 3471.469, 5637.49, 327.51883, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+4;
SET @ENTRY := 114579;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6750, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3445.0034, 5482.982, 337.71542, NULL, 0),
(@PATH, 1, 3442.7197, 5471.5015, 337.71542, NULL, 0),
(@PATH, 2, 3436.2166, 5461.7686, 337.71542, NULL, 0),
(@PATH, 3, 3426.484, 5455.2656, 338.96393, NULL, 0),
(@PATH, 4, 3415.0034, 5452.982, 337.71542, NULL, 0),
(@PATH, 5, 3403.523, 5455.2656, 337.71542, NULL, 0),
(@PATH, 6, 3393.7903, 5461.7686, 337.71542, NULL, 0),
(@PATH, 7, 3387.287, 5471.5015, 337.71542, NULL, 0),
(@PATH, 8, 3385.0034, 5482.982, 337.71542, NULL, 0),
(@PATH, 9, 3387.287, 5494.4624, 337.71542, NULL, 0),
(@PATH, 10, 3393.7903, 5504.1953, 337.71542, NULL, 0),
(@PATH, 11, 3403.523, 5510.698, 337.71542, NULL, 0),
(@PATH, 12, 3415.0034, 5512.982, 337.71542, NULL, 0),
(@PATH, 13, 3426.484, 5510.698, 337.71542, NULL, 0),
(@PATH, 14, 3436.2166, 5504.1953, 337.71542, NULL, 0),
(@PATH, 15, 3442.7197, 5494.4624, 337.71542, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+53;
SET @ENTRY := 114579;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6749, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3403.8604, 5530.0557, 334.42966, NULL, 0),
(@PATH, 1, 3401.5767, 5518.575, 334.42966, NULL, 0),
(@PATH, 2, 3395.0735, 5508.8423, 334.42966, NULL, 0),
(@PATH, 3, 3385.3408, 5502.3394, 334.42966, NULL, 0),
(@PATH, 4, 3373.8604, 5500.0557, 334.42966, NULL, 0),
(@PATH, 5, 3362.38, 5502.3394, 334.42966, NULL, 0),
(@PATH, 6, 3352.6472, 5508.8423, 334.42966, NULL, 0),
(@PATH, 7, 3346.144, 5518.575, 334.42966, NULL, 0),
(@PATH, 8, 3343.8604, 5530.0557, 334.42966, NULL, 0),
(@PATH, 9, 3346.144, 5541.536, 334.42966, NULL, 0),
(@PATH, 10, 3352.6472, 5551.269, 334.42966, NULL, 0),
(@PATH, 11, 3362.38, 5557.772, 334.42966, NULL, 0),
(@PATH, 12, 3373.8604, 5560.0557, 334.42966, NULL, 0),
(@PATH, 13, 3385.3408, 5557.772, 334.42966, NULL, 0),
(@PATH, 14, 3395.0735, 5551.269, 334.42966, NULL, 0),
(@PATH, 15, 3401.5767, 5541.536, 334.42966, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+16;
SET @ENTRY := 114579;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6872, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3604.2214, 5687.488, 327.5923, NULL, 0),
(@PATH, 1, 3601.9377, 5676.0073, 327.5923, NULL, 0),
(@PATH, 2, 3595.4346, 5666.2744, 327.5923, NULL, 0),
(@PATH, 3, 3585.702, 5659.7715, 327.5923, NULL, 0),
(@PATH, 4, 3574.2214, 5657.488, 327.5923, NULL, 0),
(@PATH, 5, 3562.741, 5659.7715, 327.5923, NULL, 0),
(@PATH, 6, 3553.0083, 5666.2744, 327.5923, NULL, 0),
(@PATH, 7, 3546.5051, 5676.0073, 327.5923, NULL, 0),
(@PATH, 8, 3544.2214, 5687.488, 327.5923, NULL, 0),
(@PATH, 9, 3546.5051, 5698.9683, 327.5923, NULL, 0),
(@PATH, 10, 3553.0083, 5708.701, 327.5923, NULL, 0),
(@PATH, 11, 3562.741, 5715.204, 327.5923, NULL, 0),
(@PATH, 12, 3574.2214, 5717.488, 327.5923, NULL, 0),
(@PATH, 13, 3585.702, 5715.204, 329.96155, NULL, 0),
(@PATH, 14, 3595.4346, 5708.701, 331.30746, NULL, 0),
(@PATH, 15, 3601.9377, 5698.9683, 332.34436, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+23;
SET @ENTRY := 114579;
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6751, 'Sylvan Owl - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3398.659, 5593.251, 323.35388, NULL, 0),
(@PATH, 1, 3396.3752, 5604.7314, 323.35388, NULL, 0),
(@PATH, 2, 3389.872, 5614.4644, 323.35388, NULL, 0),
(@PATH, 3, 3380.1394, 5620.9673, 323.35388, NULL, 0),
(@PATH, 4, 3368.659, 5623.251, 323.35388, NULL, 0),
(@PATH, 5, 3357.1785, 5620.9673, 323.35388, NULL, 0),
(@PATH, 6, 3347.4458, 5614.4644, 323.35388, NULL, 0),
(@PATH, 7, 3340.9426, 5604.7314, 323.35388, NULL, 0),
(@PATH, 8, 3338.659, 5593.251, 323.35388, NULL, 0),
(@PATH, 9, 3340.9426, 5581.7705, 324.62292, NULL, 0),
(@PATH, 10, 3347.4458, 5572.0376, 326.52487, NULL, 0),
(@PATH, 11, 3357.1785, 5565.5347, 324.91846, NULL, 0),
(@PATH, 12, 3368.659, 5563.251, 323.35388, NULL, 0),
(@PATH, 13, 3380.1394, 5565.5347, 323.35388, NULL, 0),
(@PATH, 14, 3389.872, 5572.0376, 323.35388, NULL, 0),
(@PATH, 15, 3396.3752, 5581.7705, 323.35388, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=@MOVERGUID;

SET @MOVERGUID := @CGUID+39;
SET @ENTRY := 114573;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x01, NULL, 'Sylvan Bear - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3667.207, 5628.134, 313.7098, NULL, 0),
(@PATH, 1, 3667.708, 5627.2686, 312.96313, NULL, 0),
(@PATH, 2, 3668.209, 5626.4033, 312.69702, NULL, 0),
(@PATH, 3, 3668.71, 5625.538, 311.96277, NULL, 0),
(@PATH, 4, 3668.9688, 5625.088, 312.00797, NULL, 0),
(@PATH, 5, 3669.7217, 5624.4297, 311.80792, NULL, 0),
(@PATH, 6, 3671.2275, 5623.1133, 312.18582, NULL, 0),
(@PATH, 7, 3671.9805, 5622.455, 312.01053, NULL, 0),
(@PATH, 8, 3672.7334, 5621.797, 311.4518, NULL, 0),
(@PATH, 9, 3673.4863, 5621.1387, 311.8268, NULL, 0),
(@PATH, 10, 3674.8196, 5619.9707, 311.73743, NULL, 0),
(@PATH, 11, 3685.0618, 5616.428, 312.50446, NULL, 0),
(@PATH, 12, 3696.1592, 5611.869, 313.5752, NULL, 0);

UPDATE `creature` SET `position_x`=3667.207, `position_y`=5628.134, `position_z`=313.7098, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+52;
SET @ENTRY := 114573;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x1, NULL, 'Sylvan Bear - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3676.0217, 5634.4497, 323.7433, NULL, 0),
(@PATH, 1, 3683.3542, 5635.8013, 326.41556, NULL, 0),
(@PATH, 2, 3689.7812, 5634.5757, 329.1674, NULL, 0);

UPDATE `creature` SET `position_x`=3676.0217, `position_y`=5634.4497, `position_z`=323.7433, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

SET @MOVERGUID := @CGUID+61;
SET @ENTRY := 114573;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Sylvan Bear - Idle');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3645.9565, 5668.9946, 333.23322, NULL, 0),
(@PATH, 1, 3645.7214, 5669.9453, 333.28113, NULL, 0),
(@PATH, 2, 3639.567, 5662.8516, 329.802, NULL, 0),
(@PATH, 3, 3640.0676, 5656.335, 326.15958, NULL, 0),
(@PATH, 4, 3639.567, 5662.8516, 329.802, NULL, 0);

UPDATE `creature` SET `position_x`=3645.9565, `position_y`=5668.9946, `position_z`=333.23322, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
