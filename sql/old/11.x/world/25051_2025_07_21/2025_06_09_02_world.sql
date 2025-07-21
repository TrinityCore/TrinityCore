SET @CGUID := 6002717;
SET @OGUID := 6002339;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+317;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4224.46337890625, -662.9149169921875, 257.58148193359375, 4.198483943939208984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+1, 111833, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4184.0771484375, -748.44793701171875, 269.875457763671875, 4.766232013702392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Thal'kiel (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+2, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4148.1171875, -728.63714599609375, 266.763336181640625, 0.47010013461112976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+3, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4220.47998046875, -664.1163330078125, 257.58148193359375, 4.198484420776367187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+4, 98926, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4199.24658203125, -691.9913330078125, 262.793060302734375, 4.024574756622314453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Hunter (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194580 - Replace Unarmed with 1H, 42459 - Dual Wield)
(@CGUID+5, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4221.048828125, -728.69268798828125, 266.763336181640625, 2.679080486297607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+6, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4144.5546875, -658.388916015625, 257.58148193359375, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+7, 96584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4145.275390625, -665.52606201171875, 257.58148193359375, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191541 - Melee Override, 42459 - Dual Wield)
(@CGUID+8, 98926, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4214.76025390625, -665.1788330078125, 257.58148193359375, 4.198483943939208984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Hunter (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194580 - Replace Unarmed with 1H, 42459 - Dual Wield)
(@CGUID+9, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4166.173828125, -693.28302001953125, 262.66131591796875, 5.929347038269042968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+10, 96584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4162.7275390625, -699.16668701171875, 262.7930908203125, 0.188525706529617309, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191541 - Melee Override, 42459 - Dual Wield)
(@CGUID+11, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4152.55029296875, -659.234375, 257.58148193359375, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+12, 96584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4153.92822265625, -665.08160400390625, 257.58148193359375, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191541 - Melee Override, 42459 - Dual Wield)
(@CGUID+13, 98926, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4225.03125, -667.1961669921875, 257.58148193359375, 4.325592041015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Hunter (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194580 - Replace Unarmed with 1H, 42459 - Dual Wield)
(@CGUID+14, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4202.07275390625, -696.90106201171875, 262.7930908203125, 3.544911861419677734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+15, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4195.025390625, -648.70489501953125, 255.3704376220703125, 2.386733531951904296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+16, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4154.25341796875, -628.25347900390625, 255.355377197265625, 0.871429443359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+17, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4170.49462890625, -640.61285400390625, 255.334716796875, 5.89548492431640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+18, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4219.0556640625, -624.02777099609375, 255.240478515625, 4.138759136199951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+19, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4148.75, -592.991943359375, 257.59130859375, 4.237095832824707031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+20, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4197.41943359375, -607.28643798828125, 255.374908447265625, 4.332086563110351562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+21, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4221.05224609375, -624.95831298828125, 255.2069244384765625, 0.871429443359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+22, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4172.34716796875, -609.484375, 255.542144775390625, 1.914776563644409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+23, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4175.3515625, -603.2742919921875, 255.36273193359375, 4.138759136199951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+24, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4174.47998046875, -640.420166015625, 255.3428802490234375, 4.871129512786865234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+25, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4146.35595703125, -598.28521728515625, 257.59130859375, 4.502069473266601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+26, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4198.54345703125, -602.08856201171875, 255.355377197265625, 0.940525710582733154, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+27, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4177.611328125, -644.51739501953125, 255.3285064697265625, 3.174367904663085937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+28, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4172.111328125, -602.92535400390625, 255.355377197265625, 5.345836639404296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+29, 98177, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4184.54345703125, -626.8975830078125, 268.286285400390625, 4.72802591323852539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Glayvianna Soulrender (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 200888 - Demon Hunter Wings, 204879 - Infusion, 42459 - Dual Wield)
(@CGUID+30, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4194.60009765625, -642.6163330078125, 255.3263092041015625, 1.515560269355773925, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+31, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4156.13525390625, -627.44793701171875, 255.355377197265625, 5.345836639404296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+32, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4212.0380859375, -564.14581298828125, 260.52191162109375, 4.881194591522216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+33, 114354, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4184.07275390625, -644.25347900390625, 255.326202392578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+34, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4148.88525390625, -625.68231201171875, 255.21429443359375, 2.483635902404785156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+35, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4192.90185546875, -647.48785400390625, 255.38275146484375, 1.552234053611755371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+36, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4198.66162109375, -642.62677001953125, 255.5421295166015625, 3.712970733642578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+37, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4199.27880859375, -605.029541015625, 255.3563385009765625, 6.129665851593017578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+38, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4215.19775390625, -624.41668701171875, 255.355377197265625, 5.345836639404296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+39, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4214.72314453125, -629.1875, 255.355377197265625, 2.483635902404785156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+40, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4195.408203125, -601.51043701171875, 255.3553314208984375, 5.396098136901855468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+41, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4196.0390625, -604.6805419921875, 255.365264892578125, 4.513163089752197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+42, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4177.720703125, -640.76910400390625, 255.3430938720703125, 1.398252248764038085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+43, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4172.90185546875, -605.984375, 255.3726959228515625, 2.483635902404785156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+44, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4211.8427734375, -626.67535400390625, 255.3553314208984375, 0.035803537815809249, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+45, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4172.9228515625, -644.4149169921875, 255.542144775390625, 6.201092720031738281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+46, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4198.87548828125, -564.2352294921875, 262.805633544921875, 3.5507049560546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4197.07470703125, -646.27777099609375, 255.377716064453125, 3.536645889282226562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+48, 98272, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4170.55224609375, -606.920166015625, 255.3689422607421875, 0.871429443359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+49, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4150.7646484375, -622.48785400390625, 255.262725830078125, 4.977793216705322265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+50, 98271, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4153.05908203125, -625.64581298828125, 255.361328125, 4.138759136199951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+51, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4416.71728515625, -706.61981201171875, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+52, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4155.6279296875, -532.632080078125, 266.197479248046875, 1.928626775741577148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+53, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4408.40966796875, -733.3507080078125, 116.23333740234375, 3.821759462356567382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+54, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4397.40625, -681.90972900390625, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+55, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4203.86474609375, -558.5035400390625, 262.761962890625, 5.490464687347412109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+56, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.2412109375, -655.9757080078125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+57, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4159.7265625, -533.333984375, 266.197479248046875, 4.328584671020507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+58, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4184.56396484375, -531.8302001953125, 265.799041748046875, 0.75931406021118164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+59, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.31787109375, -690.5555419921875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+60, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4397.0791015625, -673.263916015625, 116.23333740234375, 3.882943153381347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+61, 96584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4191.68994140625, -551.1007080078125, 262.793060302734375, 5.796487331390380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191541 - Melee Override, 42459 - Dual Wield)
(@CGUID+62, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4400.6328125, -658.78125, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+63, 99956, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4184.46630859375, -499.0372314453125, 269.89080810546875, 4.707573890686035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel-Infused Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194580 - Replace Unarmed with 1H, 42459 - Dual Wield) (possible waypoints or random movement)
(@CGUID+64, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4156.39990234375, -529.431396484375, 266.197479248046875, 3.580718517303466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 98954, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4188.515625, -554.00518798828125, 262.793060302734375, 4.196229457855224609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Myrmidon (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+66, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4416.63037109375, -732.4930419921875, 116.23333740234375, 3.821759700775146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+67, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4406.12841796875, -718.342041015625, 116.23333740234375, 3.842889070510864257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+68, 98926, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4179.96630859375, -499.010040283203125, 270.888641357421875, 4.707524776458740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Hunter (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194580 - Replace Unarmed with 1H, 42459 - Dual Wield) (possible waypoints or random movement)
(@CGUID+69, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4221.048828125, -525.51739501953125, 266.75335693359375, 3.567184925079345703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+70, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4412.125, -694.34027099609375, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+71, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4203.39306640625, -531.11114501953125, 266.197509765625, 0.833565950393676757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+72, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4402.7412109375, -686.2569580078125, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+73, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4156.13525390625, -530.95355224609375, 266.197479248046875, 6.030405521392822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+74, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.14599609375, -699.19793701171875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+75, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4156.84228515625, -527.36322021484375, 266.197479248046875, 6.102269172668457031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+76, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4185.3828125, -550.19097900390625, 262.7930908203125, 4.196229457855224609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+77, 96584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4180.42041015625, -550.48614501953125, 262.7930908203125, 3.452721118927001953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191541 - Melee Override, 42459 - Dual Wield)
(@CGUID+78, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4175.58251953125, -474.776031494140625, 269.89697265625, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+79, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4398.8115234375, -673.17364501953125, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+80, 96584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4181.8603515625, -480.185760498046875, 269.74053955078125, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Immoliant Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191541 - Melee Override, 42459 - Dual Wield)
(@CGUID+81, 99956, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4187.13818359375, -479.664947509765625, 269.7392578125, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel-Infused Fury (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194580 - Replace Unarmed with 1H, 42459 - Dual Wield)
(@CGUID+82, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4390.68310546875, -707.84375, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+83, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4158.07373046875, -538.24322509765625, 266.2154541015625, 0.767130136489868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+84, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.41650390625, -694.4774169921875, 116.23333740234375, 3.882943153381347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+85, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4429.5400390625, -711.4930419921875, 134.75030517578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+86, 98954, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4193.91845703125, -474.28472900390625, 269.897003173828125, 5.146504402160644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Myrmidon (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+87, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4160.931640625, -533.5697021484375, 266.206390380859375, 1.090647816658020019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+88, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4391.751953125, -715.185791015625, 116.23333740234375, 3.862006902694702148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+89, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.0625, -651.69793701171875, 116.23333740234375, 2.247875690460205078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+90, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4397.2265625, -664.62152099609375, 116.23333740234375, 3.862006902694702148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+91, 98926, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4183.4912109375, -554.21875, 262.7930908203125, 4.7158050537109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Hunter (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194580 - Replace Unarmed with 1H, 42459 - Dual Wield)
(@CGUID+92, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4148.1171875, -525.4617919921875, 266.75335693359375, 5.82428741455078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+93, 96480, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4159.2783203125, -529.4093017578125, 266.197479248046875, 1.95492720603942871, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viletongue Belcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+94, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4392.0400390625, -631.38543701171875, 116.23333740234375, 2.286196470260620117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+95, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.01220703125, -725.77777099609375, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+96, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.57373046875, -647.33331298828125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+97, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4431.1962890625, -727.8524169921875, 116.23333740234375, 3.805888652801513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+98, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4425.27001953125, -727.59375, 116.23333740234375, 3.80588841438293457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+99, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4438.431640625, -719.89239501953125, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+100, 99277, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4248.73876953125, -527.63714599609375, 109.7261428833007812, 1.697455167770385742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Freeze Statue (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 195189 - Countermeasure)
(@CGUID+101, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4409.44091796875, -650.2430419921875, 134.75030517578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+102, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4393.890625, -638.6875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+103, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4404.57470703125, -626.63018798828125, 116.23333740234375, 2.331859588623046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+104, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4433.92041015625, -726.69097900390625, 116.23333740234375, 3.842889308929443359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+105, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4418.9287109375, -641.23956298828125, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+106, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4405.3515625, -490.182281494140625, 258.516357421875, 2.301342487335205078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+107, 99013, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4281.97314453125, -451.3125, 259.602508544921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Drelanim Whisperwind (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194814 - Drelanim Whisperwind, 42459 - Dual Wield)
(@CGUID+108, 95886, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4239.1416015625, -451.33160400390625, 105.9471359252929687, 6.270169734954833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Ash'Golm (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat, 200354 - Frozen)
(@CGUID+109, 95887, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.98095703125, -673.27777099609375, 116.2355422973632812, 1.570236563682556152, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Glazer (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+110, 95885, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4325.1083984375, -451.51910400390625, 280.827880859375, 3.154026508331298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tirathon Saltheril (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat, 42459 - Dual Wield)
(@CGUID+111, 100525, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4482.63623046875, -334.072906494140625, -240.316680908203125, 2.417795419692993164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Glowing Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197941 - Elune's Light, 197897 - Elune's Light, 204294 - Elune's Light)
(@CGUID+112, 100525, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4078.4541015625, -325.234375, -281.273651123046875, 2.354482650756835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Glowing Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197941 - Elune's Light, 197897 - Elune's Light, 204294 - Elune's Light)
(@CGUID+113, 100525, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4404.76025390625, -229.340286254882812, -258.501617431640625, 3.84001922607421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Glowing Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197941 - Elune's Light, 197897 - Elune's Light, 204294 - Elune's Light)
(@CGUID+114, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4427.70654296875, -633.4617919921875, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+115, 98954, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4229.259765625, -449.177093505859375, 266.878204345703125, 3.345702648162841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Myrmidon (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+116, 111221, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4184.19189453125, -451.01910400390625, 269.73992919921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+117, 96587, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4229.15283203125, -453.7257080078125, 266.87823486328125, 2.958193540573120117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Felsworn Infester (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191585 - Melee Override)
(@CGUID+118, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4405.25, -412.17535400390625, 258.516357421875, 3.929503679275512695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+119, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4410.03662109375, -614.8038330078125, 116.23333740234375, 2.376553297042846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+120, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4442.56005859375, -726.81427001953125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+121, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4416.63037109375, -614.8055419921875, 116.23333740234375, 2.247875690460205078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+122, 100894, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4280.71630859375, -451.282989501953125, 290.085113525390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Referee (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+123, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4425.27001953125, -622.5625, 116.23333740234375, 2.286196470260620117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+124, 99277, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4162.67041015625, -452.588531494140625, 109.726165771484375, 6.283088207244873046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Freeze Statue (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 195189 - Countermeasure)
(@CGUID+125, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4438.97119140625, -625.77777099609375, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+126, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4471.33056640625, -471.85589599609375, 120.50433349609375, 2.348340272903442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual, 191297 - Owl Statue Visual)
(@CGUID+127, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4433.92041015625, -622.82293701171875, 116.23333740234375, 2.331859588623046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+128, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4435.439453125, -622.91839599609375, 116.23333740234375, 2.416324377059936523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+129, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4400.36572265625, -485.2474365234375, 256.59130859375, 3.529957532882690429, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+130, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4394.73046875, -483.98358154296875, 256.59130859375, 3.24258732795715332, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+131, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4451.0087890625, -620.35589599609375, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+132, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4378.4384765625, -451.2100830078125, 258.516357421875, 6.275421619415283203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+133, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4463.22900390625, -719.90277099609375, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+134, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4451.2099609375, -726.53472900390625, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+135, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4442.56005859375, -611.40972900390625, 116.23333740234375, 2.376553297042846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+136, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4471.8818359375, -710.9757080078125, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+137, 111833, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4451.744140625, -638.21527099609375, 117.2356185913085937, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Thal'kiel (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+138, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.74560546875, -608.90277099609375, 116.23333740234375, 2.416324377059936523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+139, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4394.44873046875, -482.52490234375, 256.51580810546875, 3.28331303596496582, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+140, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4463.58349609375, -628.40625, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+141, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4459.8505859375, -726.71356201171875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+142, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4471.5078125, -430.588531494140625, 120.50433349609375, 3.92939615249633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual, 191297 - Owl Statue Visual)
(@CGUID+143, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4471.90283203125, -636.90277099609375, 134.75030517578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+144, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4480.18408203125, -645.74652099609375, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+145, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4471, -727.6007080078125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+146, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4468.5, -726.34722900390625, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+147, 230547, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4451.0537109375, -599.43231201171875, 121.6988677978515625, 4.715647220611572265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- [DNT] Bunny (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+148, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4459.8505859375, -609.38018798828125, 116.23333740234375, 0.70505380630493164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+149, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4376.390625, -452.685760498046875, 192.7250823974609375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+150, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4377.94091796875, -447.421875, 192.7145233154296875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+151, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4385.9462890625, -448.618072509765625, 192.5357513427734375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+152, 111221, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.2587890625, -564.451416015625, 126.224365234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+153, 114349, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4446.17431640625, -515.00177001953125, 159.260772705078125, 0.972284436225891113, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+154, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4391.28955078125, -433.250457763671875, 256.469146728515625, 4.628522872924804687, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+155, 114348, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4378.4677734375, -451.267364501953125, 159.4653472900390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+156, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4467.68310546875, -622.2117919921875, 116.23333740234375, 0.70505380630493164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+157, 98533, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4405.15478515625, -452.125, 256.420379638671875, 3.186280488967895507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Foul Mother (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 194806 - Imp Mother)
(@CGUID+158, 114347, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4388.0380859375, -454.861114501953125, 159.2595672607421875, 2.923318862915039062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+159, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4422.037109375, -501.412109375, 132.79443359375, 2.103279590606689453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+160, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4391.6318359375, -451.243072509765625, 192.635772705078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+161, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4398.0556640625, -480.12628173828125, 132.79443359375, 0.617123961448669433, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+162, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4468.5, -622.71356201171875, 116.23333740234375, 0.740506291389465332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+163, 114347, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4434.7021484375, -506.3194580078125, 158.9489593505859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+164, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4411.85791015625, -450.90972900390625, 188.57073974609375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+165, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.78466796875, -512.7742919921875, 159.258331298828125, 4.177878856658935546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+166, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4391.2763671875, -422.63531494140625, 256.54864501953125, 2.763010501861572265, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+167, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4388.0224609375, -447.94097900390625, 159.25909423828125, 3.357495307922363281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+168, 101548, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4238.2509765625, -451.296875, 50.08333206176757812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Updraft (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+169, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4438.74560546875, -464.3350830078125, 185.82244873046875, 5.726259231567382812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+170, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4394.85693359375, -419.41131591796875, 256.554443359375, 5.006586074829101562, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+171, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4396.0732421875, -414.635772705078125, 256.59130859375, 0.059555023908615112, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+172, 114353, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4440.61181640625, -468.03472900390625, 185.8224639892578125, 5.425789833068847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+173, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4477.140625, -623.12677001953125, 116.23333740234375, 0.782566666603088378, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+174, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4420.01220703125, -479.4588623046875, 132.813385009765625, 2.468628644943237304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+175, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4423.64697265625, -453.8663330078125, 186.74017333984375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+176, 114351, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4451.31689453125, -475.557281494140625, 186.74017333984375, 1.3381425142288208, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+177, 114347, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4415.09814453125, -450.3819580078125, 154.3563995361328125, 3.087843656539916992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+178, 99277, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4250.5556640625, -377.432281494140625, 109.726165771484375, 4.555450916290283203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Freeze Statue (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 195189 - Countermeasure)
(@CGUID+179, 109362, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4430.08154296875, -471.66839599609375, 120.50433349609375, 0.782969355583190917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+180, 114352, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4457.36279296875, -471.180572509765625, 185.82244873046875, 3.899865150451660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+181, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4399.0556640625, -421.907867431640625, 132.79443359375, 0.350826293230056762, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+182, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4461.52197265625, -466.546875, 185.82244873046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+183, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4393.49560546875, -451.401031494140625, 256.420654296875, 1.648683786392211914, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+184, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4440.27880859375, -431.5225830078125, 185.8224639892578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+185, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4468.90625, -461.232635498046875, 185.8224334716796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+186, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4421.8388671875, -416.139129638671875, 132.9266510009765625, 3.512539386749267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+187, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.078125, -421.32464599609375, 186.7744598388671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+188, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4441.935546875, -433.51934814453125, 132.962646484375, 5.389492988586425781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+189, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4459.76318359375, -429.87847900390625, 185.822479248046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+190, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4462.03125, -436.383697509765625, 185.8224639892578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+191, 109755, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4430.2666015625, -430.43402099609375, 120.50433349609375, 5.493587493896484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 191235 - Owl Statue Visual)
(@CGUID+192, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4466.12255859375, -440.23785400390625, 185.8224334716796875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+193, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4452.5703125, -408.2569580078125, 189.9046478271484375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+194, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4420.787109375, -400.005859375, 132.891082763671875, 1.853606820106506347, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+195, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4392.02001953125, -443.95086669921875, 256.419921875, 1.766309976577758789, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+196, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4394.53125, -482.374481201171875, 256.514801025390625, 3.250476598739624023, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+197, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.775390625, -418.18402099609375, 256.674072265625, 3.246725082397460937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+198, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4390.595703125, -482.07537841796875, 256.4822998046875, 3.160775661468505859, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+199, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4394.69970703125, -482.18682861328125, 256.5140380859375, 3.20836949348449707, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+200, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4392.14990234375, -443.95758056640625, 256.4193115234375, 1.749657630920410156, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+201, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4433.88720703125, -412.193359375, 126.080810546875, 4.244947433471679687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+202, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4448.017578125, -389.1319580078125, 192.535797119140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+203, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4448.9443359375, -416.401031494140625, 154.120635986328125, 1.553273797035217285, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+204, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4453.8583984375, -381.392364501953125, 192.7113800048828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+205, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4439.32568359375, -416.21832275390625, 130.8299407958984375, 3.886588335037231445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+206, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4447.56982421875, -417.24609375, 132.60552978515625, 4.820950508117675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+207, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4453.4521484375, -389.1875, 159.258453369140625, 3.114603042602539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+208, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4440.26171875, -399.96533203125, 132.295501708984375, 1.462028861045837402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+209, 114347, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4466.79248046875, -440.180572509765625, 152.545196533203125, 0.444666415452957153, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+210, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4453.01513671875, -412.013092041015625, 134.947052001953125, 0.073494933545589447, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+211, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4461.1142578125, -417.411865234375, 127.0335464477539062, 4.9708251953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+212, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4391.64599609375, -418.238128662109375, 256.57965087890625, 3.154692649841308593, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+213, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4461.26171875, -399.4998779296875, 132.295501708984375, 4.971734046936035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+214, 104341, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4461.88134765625, -412.705963134765625, 128.894927978515625, 4.093503952026367187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Torment (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+215, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4494.390625, -451.289947509765625, 190.1451416015625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+216, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4481.171875, -422.30621337890625, 132.8278045654296875, 0.982561469078063964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+217, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4479.88916015625, -491.598114013671875, 132.79443359375, 5.197659492492675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+218, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4479.7568359375, -401.604156494140625, 132.871063232421875, 5.301032066345214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+219, 109453, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4496.5400390625, -418.625, 133.07769775390625, 4.781448841094970703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Cell Door 3-5x1 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+220, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4513.1015625, -453.329864501953125, 159.258331298828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+221, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4512.9228515625, -448.317718505859375, 159.25860595703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+222, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4514.01904296875, -454.56597900390625, 192.536651611328125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+223, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4514.33251953125, -447.614593505859375, 192.53680419921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+224, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4501.85498046875, -481.481536865234375, 132.795196533203125, 3.372051477432250976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+225, 96524, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4378.4384765625, -451.2100830078125, 258.516357421875, 6.275421619415283203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 191235 - Owl Statue Visual)
(@CGUID+226, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4503.81884765625, -421.17340087890625, 132.8552703857421875, 6.109858989715576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+227, 114346, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4520.275390625, -450.802093505859375, 159.442474365234375, 3.15875864028930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+228, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4503.59375, -479.77386474609375, 132.8195037841796875, 2.346629858016967773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+229, 106196, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4527.78125, -451.15277099609375, 126.151885986328125, 6.232479572296142578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Generic Bunny - QUEST - SCS (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+230, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4390.33740234375, -482.558563232421875, 256.485595703125, 3.217899322509765625, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+231, 99837, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4302.298828125, -454.789947509765625, 260.750396728515625, 1.452261090278625488, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Qiraji Mindslayer (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 194816 - Drelanim Whisperwind)
(@CGUID+232, 99872, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4303.095703125, -446.83160400390625, 260.750396728515625, 4.657116413116455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Marin Bladewing (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 194816 - Drelanim Whisperwind)
(@CGUID+233, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4393.89501953125, -447.97454833984375, 256.395294189453125, 1.454639315605163574, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+234, 99806, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4302.298828125, -452.35589599609375, 260.750396728515625, 1.439885377883911132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Ozruk (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 194816 - Drelanim Whisperwind)
(@CGUID+235, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4394.54248046875, -482.3963623046875, 256.515106201171875, 3.255974292755126953, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+236, 99870, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4303.095703125, -446.83160400390625, 260.750396728515625, 4.657116413116455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malace Shade (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 194816 - Drelanim Whisperwind)
(@CGUID+237, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4485.77978515625, -614.8975830078125, 116.23333740234375, 0.824303209781646728, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+238, 99018, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4303.095703125, -446.83160400390625, 260.750396728515625, 4.657116413116455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Drelanim Whisperwind (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 194816 - Drelanim Whisperwind)
(@CGUID+239, 99198, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4303.298828125, -452.560760498046875, 260.750396728515625, 1.452261090278625488, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tirathon Saltheril (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 194816 - Drelanim Whisperwind)
(@CGUID+240, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4398.6875, -481.920135498046875, 256.674072265625, 3.228146553039550781, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+241, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4390.61865234375, -482.46112060546875, 256.48663330078125, 3.208541631698608398, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+242, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4393.21923828125, -447.654266357421875, 256.398895263671875, 1.644409537315368652, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+243, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4393.06005859375, -443.716552734375, 256.416229248046875, 1.627436637878417968, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+244, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4508.9599609375, -632.80035400390625, 116.23333740234375, 0.824303209781646728, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+245, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4496.78125, -627.69097900390625, 116.23333740234375, 0.782566666603088378, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+246, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4492.73193359375, -614.44964599609375, 116.23333740234375, 0.740506291389465332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+247, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4489.1787109375, -654.40277099609375, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+248, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4499.1474609375, -662.30206298828125, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+249, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4505.9375, -653.109375, 116.23333740234375, 0.861664175987243652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+250, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4505.8974609375, -647.33331298828125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+251, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4510.20068359375, -638.6875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+252, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4512.876953125, -681.90972900390625, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+253, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4512.59130859375, -673.263916015625, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+254, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4509.58154296875, -673.045166015625, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+255, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4485.40869140625, -707.79168701171875, 134.75030517578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+256, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4513.0224609375, -664.62152099609375, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+257, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4498.25439453125, -685.1492919921875, 134.7503662109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+258, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4506.02783203125, -655.9757080078125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+259, 103093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4490.08837890625, -692.8680419921875, 134.75030517578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Safety Net (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+260, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4395.775390625, -418.18402099609375, 256.674072265625, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@CGUID+261, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4506.0947265625, -699.19793701171875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+262, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4506.30029296875, -693.80035400390625, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+263, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4505.84228515625, -690.5555419921875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+264, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4511.033203125, -707.84375, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+265, 105824, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4664.5146484375, -451.001739501953125, 122.111114501953125, 3.141592741012573242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Grimoira (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+266, 98963, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4393.49560546875, -451.401031494140625, 256.420654296875, 1.837938427925109863, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Blazing Imp (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@CGUID+267, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4496.80029296875, -718.8367919921875, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+268, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4511.1005859375, -715.8507080078125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+269, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4477.140625, -727.20660400390625, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+270, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4485.77978515625, -731.14410400390625, 116.23333740234375, 0.861664175987243652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+271, 98118, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4492.73193359375, -732.078125, 116.23333740234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lens (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+272, 96015, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.8203125, -393.625, 126.0522232055664062, 4.714906692504882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Inquisitor Tormentorum (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 206470 - Torment)
(@CGUID+273, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4455.69775390625, -533.35418701171875, 126.2641067504882812, 2.02295684814453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+274, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4444.32470703125, -532.482666015625, 126.1617584228515625, 1.171630024909973144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+275, 102583, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4444.923828125, -521.5382080078125, 125.9844131469726562, 1.747561454772949218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fel Scorcher (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+276, 102584, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4455.703125, -523.8819580078125, 126.14581298828125, 1.63492739200592041, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Malignant Defiler (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+277, 99649, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4375.8759765625, -450.80035400390625, 126.170654296875, 0.022161761298775672, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadlord Mendacius (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+278, 96657, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4450.70654296875, -527.40625, 126.1603622436523437, 1.659780025482177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Blade Dancer Illianna (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2 (Auras: 42459 - Dual Wield)
(@CGUID+279, 111833, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4295.87060546875, -451.6319580078125, 105.715606689453125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Thal'kiel (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@CGUID+280, 102566, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4450.779296875, -375.453643798828125, 126.08489990234375, 4.719326496124267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Grimhorn the Enslaver (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+281, 97689, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4410.05712890625, -305.482635498046875, -216.260650634765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Web (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 134529 - Ambient Corpse Anchor Spawn)
(@CGUID+282, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4423.7978515625, -294.9288330078125, -247.469406127929687, 1.914776563644409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+283, 100364, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4424.02978515625, -295.170135498046875, -247.502639770507812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Spirit of Vengeance (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197442 - Spirit of Vengeance, 192750 - Veiled in Shadow)
(@CGUID+284, 97689, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4413.353515625, -248.288192749023437, -225.296051025390625, 3.000208616256713867, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Web (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 134529 - Ambient Corpse Anchor Spawn)
(@CGUID+285, 97689, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4370.619140625, -255.203125, -249.020248413085937, 4.77556610107421875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Web (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 134529 - Ambient Corpse Anchor Spawn)
(@CGUID+286, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4386.3046875, -349.7569580078125, -256.479827880859375, 0.997535467147827148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+287, 97678, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4391.3515625, -302.133697509765625, -260.33709716796875, 2.755429983139038085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Aranasi Broodmother (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+288, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4389.5244140625, -355.15625, -255.937789916992187, 1.051756858825683593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+289, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4394.1630859375, -352.364593505859375, -255.6607666015625, 1.337766051292419433, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+290, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4391.298828125, -347.13714599609375, -256.25738525390625, 1.283524274826049804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+291, 97678, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4354.6396484375, -288.32464599609375, -259.99798583984375, 5.611803531646728515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Aranasi Broodmother (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+292, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4352.59228515625, -299.0069580078125, -260.36553955078125, 1.914776563644409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+293, 100364, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4352.70166015625, -299.213531494140625, -260.39410400390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Spirit of Vengeance (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197442 - Spirit of Vengeance, 192750 - Veiled in Shadow)
(@CGUID+294, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4323.78662109375, -307.180572509765625, -283.64300537109375, 0.997535467147827148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+295, 100364, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4337.29248046875, -306.4288330078125, -283.93634033203125, 3.188891172409057617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Spirit of Vengeance (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197442 - Spirit of Vengeance, 192750 - Veiled in Shadow)
(@CGUID+296, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4339.60302734375, -278.757232666015625, -279.616363525390625, 1.313701152801513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+297, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4331.64404296875, -309.7882080078125, -283.882720947265625, 1.337766051292419433, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+298, 100364, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4328.16162109375, -330.88714599609375, -283.49676513671875, 1.377109408378601074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Spirit of Vengeance (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197442 - Spirit of Vengeance, 192750 - Veiled in Shadow)
(@CGUID+299, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4333.31982421875, -281.7901611328125, -279.616363525390625, 1.2512284517288208, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+300, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4328.490234375, -276.76336669921875, -279.62109375, 1.300102472305297851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+301, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4327.00537109375, -312.579864501953125, -283.67333984375, 1.051756858825683593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+302, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4331.7919921875, -270.617156982421875, -279.62109375, 1.399624109268188476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+303, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4328.77978515625, -304.5625, -284.154510498046875, 1.283524274826049804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+304, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4338.65966796875, -271.84442138671875, -279.616363525390625, 1.399124026298522949, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+305, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4337.01123046875, -268.1927490234375, -277.74481201171875, 1.554039239883422851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+306, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4337.27587890625, -306.751739501953125, -283.92974853515625, 1.914776563644409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+307, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4334.66943359375, -314.302093505859375, -283.671905517578125, 1.051756858825683593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+308, 97677, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4321.26318359375, -312.97222900390625, -283.545501708984375, 1.051756858825683593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Barbed Spiderling (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+309, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4327.71728515625, -331.1632080078125, -283.491668701171875, 1.914776563644409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+310, 97678, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4266.89599609375, -301.380218505859375, -283.81793212890625, 6.197954177856445312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Aranasi Broodmother (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 192750 - Veiled in Shadow)
(@CGUID+311, 99953, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4225.1181640625, -296.9132080078125, -281.11138916015625, 1.914776563644409179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Fallen Warden (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 70628 - Permanent Feign Death)
(@CGUID+312, 100364, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4226.09716796875, -297.08160400390625, -281.11138916015625, 6.277769088745117187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Spirit of Vengeance (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 197442 - Spirit of Vengeance, 192750 - Veiled in Shadow)
(@CGUID+313, 111221, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4202.18505859375, -295.680572509765625, -281.346893310546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+314, 95888, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 1, 4033.203125, -297.17535400390625, -281.5067138671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Cordana Felsong (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat, 192750 - Veiled in Shadow)
(@CGUID+315, 120300, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4078.440185546875, -269.567718505859375, -281.02923583984375, 3.936600446701049804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Glowing Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+316, 120300, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4022.8828125, -269.68402099609375, -281.02923583984375, 5.495715141296386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Glowing Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@CGUID+317, 120300, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 0, 0, 4022.931396484375, -325.170135498046875, -281.02923583984375, 0.810118675231933593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265); -- Glowing Sentry (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+317;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- Shadow Hunter - 194580 - Replace Unarmed with 1H, 42459 - Dual Wield
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191541 42459'), -- Immoliant Fury - 191541 - Melee Override, 42459 - Dual Wield
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- Shadow Hunter - 194580 - Replace Unarmed with 1H, 42459 - Dual Wield
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191541 42459'), -- Immoliant Fury - 191541 - Melee Override, 42459 - Dual Wield
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191541 42459'), -- Immoliant Fury - 191541 - Melee Override, 42459 - Dual Wield
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- Shadow Hunter - 194580 - Replace Unarmed with 1H, 42459 - Dual Wield
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+18, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Immoliant Fury - 70628 - Permanent Feign Death
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Felsworn Infester - 70628 - Permanent Feign Death
(@CGUID+61, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191541 42459'), -- Immoliant Fury - 191541 - Melee Override, 42459 - Dual Wield
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- Shadow Hunter - 194580 - Replace Unarmed with 1H, 42459 - Dual Wield
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191541 42459'), -- Immoliant Fury - 191541 - Melee Override, 42459 - Dual Wield
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+80, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191541 42459'), -- Immoliant Fury - 191541 - Melee Override, 42459 - Dual Wield
(@CGUID+81, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- Fel-Infused Fury - 194580 - Replace Unarmed with 1H, 42459 - Dual Wield
(@CGUID+91, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- Shadow Hunter - 194580 - Replace Unarmed with 1H, 42459 - Dual Wield
(@CGUID+117, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'), -- Felsworn Infester - 191585 - Melee Override
(@CGUID+149, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+151, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+153, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+155, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+158, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+163, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+164, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+165, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+169, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+172, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+175, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+176, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+177, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+180, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+182, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+184, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+185, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+187, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+189, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+190, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+193, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+202, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+203, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+204, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+207, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+209, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+215, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+220, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+221, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+222, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+223, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+227, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+278, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '42459'), -- Blade Dancer Illianna - 42459 - Dual Wield
(@CGUID+282, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+287, 0, 0, 0, 0, 0, 1, 0, 468, 0, 0, 0, 0, '192750'), -- Aranasi Broodmother - 192750 - Veiled in Shadow
(@CGUID+291, 0, 0, 0, 0, 0, 1, 0, 468, 0, 0, 0, 0, '192750'), -- Aranasi Broodmother - 192750 - Veiled in Shadow
(@CGUID+292, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+306, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+309, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'), -- Fallen Warden - 70628 - Permanent Feign Death
(@CGUID+310, 0, 0, 0, 0, 0, 1, 0, 468, 0, 0, 0, 0, '192750'), -- Aranasi Broodmother - 192750 - Veiled in Shadow
(@CGUID+311, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '70628'); -- Fallen Warden - 70628 - Permanent Feign Death

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+103;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 243922, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4183.81884765625, -670.123291015625, 255.3121185302734375, 6.072298049926757812, 0, 0, -0.10524845123291015, 0.994445979595184326, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+1, 243921, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4181.94287109375, -659.27081298828125, 255.3121185302734375, 0.267753511667251586, 0, 0, 0.133477210998535156, 0.991051852703094482, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+2, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4167.1328125, -713.6336669921875, 271.416473388671875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+3, 243922, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4191.18212890625, -666.6319580078125, 255.3121185302734375, 1.554328322410583496, 0, 0, 0.701260566711425781, 0.712905049324035644, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+4, 246042, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4184.517578125, -745.05810546875, 269.949920654296875, 1.57079315185546875, 0, 0, 0.707105636596679687, 0.707107901573181152, 7200, 255, 0, 61265), -- Doodad_7DU_Warden_DoorMedium01_010 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+5, 243921, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4179.9697265625, -669.013916015625, 255.3121185302734375, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+6, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4215.15380859375, -694.685791015625, 269.062896728515625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+7, 243921, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4177.5009765625, -662.5382080078125, 255.3121185302734375, 2.933842182159423828, 0, 0, 0.994609832763671875, 0.10368850827217102, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+8, 243922, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4191.09912109375, -587.33856201171875, 255.3121185302734375, 2.352996349334716796, 0, 0, 0.923266410827636718, 0.38416031002998352, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+9, 243921, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4184.75244140625, -596.2413330078125, 255.3121185302734375, 0.798667192459106445, 0, 0, 0.388804435729980468, 0.921320319175720214, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+10, 243922, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4183.17626953125, -582.7257080078125, 255.3121185302734375, 4.633821010589599609, 0, 0, -0.73433208465576171, 0.678790390491485595, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+11, 243921, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4178.3916015625, -593.498291015625, 255.3121185302734375, 2.657010793685913085, 0, 0, 0.970790863037109375, 0.239927262067794799, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+12, 243922, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4189.63916015625, -593.93231201171875, 255.3121185302734375, 0.587778091430664062, 0, 0, 0.289676666259765625, 0.957124590873718261, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+13, 243921, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4178.60693359375, -588.25, 255.3121185302734375, 1.066421031951904296, 0, 0, 0.50830078125, 0.861179590225219726, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+14, 243922, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4189.189453125, -658.6024169921875, 255.3121185302734375, 2.933842182159423828, 0, 0, 0.994609832763671875, 0.10368850827217102, 7200, 255, 1, 61265), -- Fish (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+15, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4225.86181640625, -602.40802001953125, 264.5556640625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+16, 246059, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4416.5546875, -673.23828125, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile024 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+17, 268231, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4184.517578125, -508.46728515625, 269.875274658203125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium008 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+18, 246074, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4442.52392578125, -699.2073974609375, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile009 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+19, 246073, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4451.25244140625, -690.5626220703125, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile010 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+20, 246055, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4208.89501953125, -451.198486328125, 269.76434326171875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 61265), -- Doodad_7DU_Warden_DoorMedium01_065 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+21, 246058, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4425.283203125, -664.593505859375, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile025 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+22, 246063, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4433.92529296875, -673.2359619140625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile020 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+23, 246060, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4433.9697265625, -655.9068603515625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile023 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+24, 247081, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4323.02392578125, -472.862640380859375, 259.740631103515625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 61265), -- Firewall (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+25, 246082, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4451.29638671875, -673.2335205078125, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile001 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+26, 246080, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4433.88134765625, -690.56494140625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile003 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+27, 246081, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4442.60986328125, -681.920166015625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile002 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+28, 246064, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4425.197265625, -681.8807373046875, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile019 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+29, 246065, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4442.6123046875, -664.54931640625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile018 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+30, 246069, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4451.166015625, -707.84979248046875, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile014 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+31, 246075, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4459.93896484375, -681.8759765625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile008 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+32, 246072, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4485.87109375, -673.2283935546875, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile011 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+33, 246078, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4468.58642578125, -655.943603515625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile005 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+34, 246079, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4459.93408203125, -664.5960693359375, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile004 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+35, 246076, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4468.576171875, -673.23846435546875, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile007 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+36, 246077, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4477.22900390625, -664.58599853515625, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile006 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+37, 246053, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4357.34375, -484.381011962890625, 256.5572509765625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_063 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+38, 246062, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4451.259765625, -638.61688232421875, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile021 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+39, 246061, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4442.607421875, -647.2694091796875, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile022 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+40, 247082, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4321.7119140625, -428.31927490234375, 259.740631103515625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Firewall (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+41, 246083, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4324.54150390625, -451.141326904296875, 126.1960296630859375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 61265), -- Doodad_7DU_Warden_DoorMedium01_066 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+42, 246086, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4184.52978515625, -434.4334716796875, 269.722259521484375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium006 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+43, 246084, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.791015625, -577.280029296875, 126.1479034423828125, 4.7123870849609375, 0, 0, -0.7071075439453125, 0.707105994224548339, 7200, 255, 0, 61265), -- Doodad_7DU_Warden_DoorMedium01_067 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+44, 246091, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.791015625, -535.3687744140625, 192.0502471923828125, 4.7123870849609375, 0, 0, -0.7071075439453125, 0.707105994224548339, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_051 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+45, 246095, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.791015625, -535.3687744140625, 158.7729949951171875, 4.7123870849609375, 0, 0, -0.7071075439453125, 0.707105994224548339, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_055 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+46, 246066, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4451.24951171875, -655.91180419921875, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile017 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+47, 246067, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4459.90234375, -647.25927734375, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile016 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+48, 246070, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4468.5810546875, -690.51837158203125, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile013 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+49, 246071, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4477.21875, -681.880859375, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile012 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+50, 246068, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4459.89453125, -699.20501708984375, 117.078033447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_OwlStatue02Tile015 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+51, 246113, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4535.0185546875, -451.147491455078125, 125.4957733154296875, 6.283183574676513671, 0, 0, -0.0000009536743164, 1, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_018 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+52, 246506, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4405.2177734375, -417.82940673828125, 120.0739212036132812, 4.627656936645507812, 0, 0, -0.7364206314086914, 0.676523923873901367, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_115 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+53, 246507, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4416.37060546875, -416.72052001953125, 120.2274932861328125, 5.497786521911621093, 0, 0, -0.38268375396728515, 0.923879444599151611, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_119 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+54, 246054, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4357.34375, -418.005950927734375, 256.5572509765625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_064 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+55, 246510, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4485.21826171875, -416.720672607421875, 120.2274932861328125, 3.926990509033203125, 0.000000476837158203, 0, -0.92387962341308593, 0.382683247327804565, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_131 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+56, 246511, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4496.2509765625, -417.560394287109375, 120.0739517211914062, 4.819643974304199218, 0, 0, -0.66818809509277343, 0.743992388248443603, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_133 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+57, 246508, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4417.21044921875, -405.68756103515625, 120.0739517211914062, 0.10725201666355133, 0, 0, 0.053600311279296875, 0.998562455177307128, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_121 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+58, 246098, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4535.0185546875, -451.147491455078125, 158.7729949951171875, 6.283183574676513671, 0, 0, -0.0000009536743164, 1, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_058 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+59, 246099, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.791015625, -535.3687744140625, 92.218536376953125, 4.7123870849609375, 0, 0, -0.7071075439453125, 0.707105994224548339, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_059 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+60, 246096, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4366.56982421875, -451.14129638671875, 158.7729949951171875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_056 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+61, 246097, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.79736328125, -366.919952392578125, 158.7729949951171875, 1.57079315185546875, 0, 0, 0.707105636596679687, 0.707107901573181152, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_057 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+62, 246100, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4366.56982421875, -451.14129638671875, 92.218536376953125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_060 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+63, 247080, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4414.14697265625, -451.1995849609375, 256.277618408203125, 6.283183574676513671, 0, 0, -0.0000009536743164, 1, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_069 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+64, 246110, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.791015625, -535.3687744140625, 125.4957733154296875, 4.7123870849609375, 0, 0, -0.7071075439453125, 0.707105994224548339, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_015 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+65, 246111, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4366.56982421875, -451.14129638671875, 125.4957733154296875, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_016 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+66, 246047, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.763671875, -451.19366455078125, 253.484649658203125, 0, 0, 0, 0, 1, 7200, 255, 25, 61265), -- Doodad_7WD_Warden_Elevator004 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+67, 246514, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4484.37841796875, -496.601165771484375, 120.0739517211914062, 3.248867273330688476, 0, 0, -0.99856185913085937, 0.053611524403095245, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_145 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+68, 246515, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4417.4794921875, -496.720977783203125, 120.0739212036132812, 6.198452949523925781, 0, 0, -0.04235363006591796, 0.999102711677551269, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_151 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+69, 246094, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4535.0185546875, -451.147491455078125, 192.0502471923828125, 6.283183574676513671, 0, 0, -0.0000009536743164, 1, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_054 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+70, 246512, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4496.37109375, -484.459320068359375, 120.0739212036132812, 1.486062288284301757, 0, 0, 0.676523208618164062, 0.736421287059783935, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_139 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+71, 246513, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4485.2177734375, -485.568206787109375, 120.2274932861328125, 2.356189966201782226, -0.0000004768371582, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_143 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+72, 246092, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4366.56982421875, -451.14129638671875, 192.0502471923828125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_052 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+73, 246093, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.79736328125, -366.919952392578125, 192.0502471923828125, 1.57079315185546875, 0, 0, 0.707105636596679687, 0.707107901573181152, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_053 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+74, 246516, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4416.37060546875, -485.568084716796875, 120.2274932861328125, 0.785394728183746337, 0, 0, 0.382681846618652343, 0.923880219459533691, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_155 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+75, 246517, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4405.33740234375, -484.72833251953125, 120.0739517211914062, 1.678049564361572265, 0, 0, 0.743991851806640625, 0.668188691139221191, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_157 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+76, 246112, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.79736328125, -366.919952392578125, 125.4957733154296875, 1.57079315185546875, 0, 0, 0.707105636596679687, 0.707107901573181152, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_017 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+77, 246049, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4216.83203125, -297.15838623046875, -281.589202880859375, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_IllidanDoor001 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+78, 246509, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4484.109375, -405.567779541015625, 120.0739212036132812, 3.056856393814086914, 0, 0, 0.999102592468261718, 0.042355407029390335, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_CellDoor02_127 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+79, 246102, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4535.0185546875, -451.147491455078125, 92.218536376953125, 6.283183574676513671, 0, 0, -0.0000009536743164, 1, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_062 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+80, 246101, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.79736328125, -366.919952392578125, 92.218536376953125, 1.57079315185546875, 0, 0, 0.707105636596679687, 0.707107901573181152, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_061 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+81, 246048, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4451.0419921875, -321.52996826171875, -240.945022583007812, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 24, 61265), -- Doodad_7WD_Warden_Elevator005 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+82, 246087, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4241.62353515625, -492.742431640625, -348.881988525390625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_029 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+83, 246085, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4577.5263671875, -451.147491455078125, 126.1183929443359375, 6.283183574676513671, 0, 0, -0.0000009536743164, 1, 7200, 255, 0, 61265), -- Doodad_7DU_Warden_DoorMedium01_068 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+84, 246090, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4325.8447265625, -576.969970703125, -348.881988525390625, 4.7123870849609375, 0, 0, -0.7071075439453125, 0.707105994224548339, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_038 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+85, 246088, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4325.8505859375, -408.52105712890625, -348.881988525390625, 1.57079315185546875, 0, 0, 0.707105636596679687, 0.707107901573181152, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_030 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+86, 246089, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4410.072265625, -492.74859619140625, -348.881988525390625, 6.283183574676513671, 0, 0, -0.0000009536743164, 1, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_DoorMedium01_037 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+87, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4149.58154296875, -634.875, 259.285064697265625, 3.144355058670043945, 0, 0, -0.99999904632568359, 0.001381067908369004, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+88, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4215.048828125, -559.07464599609375, 269.081207275390625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+89, 246418, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4238.5771484375, -451.158355712890625, 105.8637771606445312, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7DU_Warden_PlatformIcicles001 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+90, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4169.3525390625, -552.2882080078125, 267.049224853515625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+91, 246727, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4450.7744140625, -608.680419921875, 115.8616867065429687, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_Bridge001 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+92, 246057, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4293.65869140625, -451.204681396484375, 104.5212173461914062, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 61265), -- Doodad_7WD_Warden_Bridge001 (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+93, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4225.86181640625, -602.40802001953125, 264.5556640625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@OGUID+94, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4153.86181640625, -559.171875, 269.062896728515625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@OGUID+95, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4215.048828125, -559.07464599609375, 269.081207275390625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@OGUID+96, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4169.3525390625, -552.2882080078125, 267.049224853515625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@OGUID+97, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4199.87060546875, -552.2413330078125, 266.940826416015625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject2
(@OGUID+98, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4219.62060546875, -634.9305419921875, 259.285064697265625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+99, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4201.876953125, -540.19964599609375, 271.416473388671875, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+100, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4153.86181640625, -559.171875, 269.062896728515625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+101, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4167.02001953125, -540.2413330078125, 271.474700927734375, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+102, 243907, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4199.87060546875, -552.2413330078125, 266.940826416015625, 0, 0, 0, 0, 1, 7200, 255, 1, 61265), -- Orb Light (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
(@OGUID+103, 258979, 1493, 7787, 7787, '1,2,8,23,24', 0, 0, 4329.923828125, -346.8194580078125, -283.168975830078125, 5.182311058044433593, 0, 0, -0.52305984497070312, 0.852295935153961181, 7200, 255, 1, 61265); -- Fel-Ravaged Tome (Area: Vault of the Wardens - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+103;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_010
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile024
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium008
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile009
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile010
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_065
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile025
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile020
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile023
(@OGUID+24, 0, 0, 1, -0.00000004371138828, 0, 0), -- Firewall
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile001
(@OGUID+26, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile003
(@OGUID+27, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile002
(@OGUID+28, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile019
(@OGUID+29, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile018
(@OGUID+30, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile014
(@OGUID+31, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile008
(@OGUID+32, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile011
(@OGUID+33, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile005
(@OGUID+34, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile004
(@OGUID+35, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile007
(@OGUID+36, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile006
(@OGUID+37, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_063
(@OGUID+38, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile021
(@OGUID+39, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile022
(@OGUID+40, 0, 0, 1, -0.00000004371138828, 0, 0), -- Firewall
(@OGUID+41, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_066
(@OGUID+42, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium006
(@OGUID+43, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_067
(@OGUID+44, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_051
(@OGUID+45, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_055
(@OGUID+46, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile017
(@OGUID+47, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile016
(@OGUID+48, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile013
(@OGUID+49, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile012
(@OGUID+50, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_OwlStatue02Tile015
(@OGUID+51, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_018
(@OGUID+52, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_115
(@OGUID+53, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_119
(@OGUID+54, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_064
(@OGUID+55, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_131
(@OGUID+56, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_133
(@OGUID+57, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_121
(@OGUID+58, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_058
(@OGUID+59, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_059
(@OGUID+60, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_056
(@OGUID+61, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_057
(@OGUID+62, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_060
(@OGUID+63, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_069
(@OGUID+64, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_015
(@OGUID+65, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_016
(@OGUID+66, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_Elevator004
(@OGUID+67, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_145
(@OGUID+68, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_151
(@OGUID+69, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_054
(@OGUID+70, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_139
(@OGUID+71, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_143
(@OGUID+72, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_052
(@OGUID+73, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_053
(@OGUID+74, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_155
(@OGUID+75, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_157
(@OGUID+76, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_017
(@OGUID+77, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_IllidanDoor001
(@OGUID+78, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_CellDoor02_127
(@OGUID+79, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_062
(@OGUID+80, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_061
(@OGUID+81, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_Elevator005
(@OGUID+82, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_029
(@OGUID+83, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_068
(@OGUID+84, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_038
(@OGUID+85, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_030
(@OGUID+86, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_DoorMedium01_037
(@OGUID+89, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7DU_Warden_PlatformIcicles001
(@OGUID+91, 0, 0, 1, -0.00000004371138828, 0, 0), -- Doodad_7WD_Warden_Bridge001
(@OGUID+92, 0, 0, 1, -0.00000004371138828, 0, 0); -- Doodad_7WD_Warden_Bridge001

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (95888 /*95888 (Cordana Felsong) - [DNT] Send Event <Points> On Enter Combat, Veiled in Shadow*/, 97678 /*97678 (Aranasi Broodmother) - Veiled in Shadow*/, 97677 /*97677 (Barbed Spiderling) - Veiled in Shadow*/, 100364 /*100364 (Spirit of Vengeance) - Spirit of Vengeance, Veiled in Shadow*/, 97689 /*97689 (Web) - Ambient Corpse Anchor Spawn*/, 97681 /*97681 (Demon Spider) - Veiled in Shadow*/, 96657 /*96657 (Blade Dancer Illianna) - Dual Wield*/, 96015 /*96015 (Inquisitor Tormentorum) - Torment*/, 99198 /*99198 (Tirathon Saltheril) - Drelanim Whisperwind*/, 99018 /*99018 (Drelanim Whisperwind) - Drelanim Whisperwind*/, 99870 /*99870 (Malace Shade) - Drelanim Whisperwind*/, 99806 /*99806 (Ozruk) - Drelanim Whisperwind*/, 99873 /*99873 (Moonbeak) - Drelanim Whisperwind*/, 99872 /*99872 (Marin Bladewing) - Drelanim Whisperwind*/, 99837 /*99837 (Qiraji Mindslayer) - Drelanim Whisperwind*/, 106196 /*106196 (Generic Bunny - QUEST - SCS)*/, 114346 /*114346 (Fallen Warden) - Permanent Feign Death*/, 109755 /*109755 (Sentry) - Owl Statue Visual*/, 104341 /*104341 (Torment)*/, 114352 /*114352 (Fallen Warden) - Permanent Feign Death*/, 109362 /*109362 (Sentry) - Owl Statue Visual*/, 114351 /*114351 (Fallen Warden) - Permanent Feign Death*/, 114353 /*114353 (Fallen Warden) - Permanent Feign Death*/, 101548 /*101548 (Updraft)*/, 114347 /*114347 (Fallen Warden) - Permanent Feign Death*/, 98533 /*98533 (Foul Mother) - Imp Mother*/, 114348 /*114348 (Fallen Warden) - Permanent Feign Death*/, 114349 /*114349 (Fallen Warden) - Permanent Feign Death*/, 230547 /*230547 ([DNT] Bunny)*/, 100894 /*100894 (Referee)*/, 100525 /*100525 (Glowing Sentry) - Elune's Light, Elune's Light, Elune's Light*/, 95885 /*95885 (Tirathon Saltheril) - [DNT] Send Event <Points> On Enter Combat, Dual Wield*/, 95887 /*95887 (Glazer)*/, 95886 /*95886 (Ash'Golm) - [DNT] Send Event <Points> On Enter Combat, Frozen*/, 99013 /*99013 (Drelanim Whisperwind) - Drelanim Whisperwind, Dual Wield*/, 99277 /*99277 (Freeze Statue) - Countermeasure*/, 99956 /*99956 (Fel-Infused Fury) - Replace Unarmed with 1H, Dual Wield*/, 98118 /*98118 (Lens)*/, 103093 /*103093 (Safety Net)*/, 114354 /*114354 (Immoliant Fury) - Permanent Feign Death*/, 98177 /*98177 (Glayvianna Soulrender) - Demon Hunter Wings, Infusion, Dual Wield*/, 99953 /*99953 (Fallen Warden) - Permanent Feign Death*/, 98272 /*98272 (Immoliant Fury) - Permanent Feign Death*/, 98271 /*98271 (Felsworn Infester) - Permanent Feign Death*/, 96584 /*96584 (Immoliant Fury) - Melee Override, Dual Wield*/, 98926 /*98926 (Shadow Hunter) - Replace Unarmed with 1H, Dual Wield*/, 96524 /*96524 (Sentry) - Owl Statue Visual*/, 96587 /*96587 (Felsworn Infester) - Melee Override*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(95888, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '355784 192750'), -- 95888 (Cordana Felsong) - [DNT] Send Event <Points> On Enter Combat, Veiled in Shadow
(97678, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '192750'), -- 97678 (Aranasi Broodmother) - Veiled in Shadow
(97677, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '192750'), -- 97677 (Barbed Spiderling) - Veiled in Shadow
(100364, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '197442 192750'), -- 100364 (Spirit of Vengeance) - Spirit of Vengeance, Veiled in Shadow
(97689, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '134529'), -- 97689 (Web) - Ambient Corpse Anchor Spawn
(97681, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '192750'), -- 97681 (Demon Spider) - Veiled in Shadow
(96657, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '42459'), -- 96657 (Blade Dancer Illianna) - Dual Wield
(96015, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '206470'), -- 96015 (Inquisitor Tormentorum) - Torment
(99198, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194816'), -- 99198 (Tirathon Saltheril) - Drelanim Whisperwind
(99018, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194816'), -- 99018 (Drelanim Whisperwind) - Drelanim Whisperwind
(99870, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194816'), -- 99870 (Malace Shade) - Drelanim Whisperwind
(99806, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194816'), -- 99806 (Ozruk) - Drelanim Whisperwind
(99873, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '194816'), -- 99873 (Moonbeak) - Drelanim Whisperwind
(99872, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194816'), -- 99872 (Marin Bladewing) - Drelanim Whisperwind
(99837, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194816'), -- 99837 (Qiraji Mindslayer) - Drelanim Whisperwind
(106196, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 106196 (Generic Bunny - QUEST - SCS)
(114346, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114346 (Fallen Warden) - Permanent Feign Death
(109755, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191235'), -- 109755 (Sentry) - Owl Statue Visual
(104341, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 104341 (Torment)
(114352, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114352 (Fallen Warden) - Permanent Feign Death
(109362, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191235'), -- 109362 (Sentry) - Owl Statue Visual
(114351, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114351 (Fallen Warden) - Permanent Feign Death
(114353, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114353 (Fallen Warden) - Permanent Feign Death
(101548, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 101548 (Updraft)
(114347, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114347 (Fallen Warden) - Permanent Feign Death
(98533, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194806'), -- 98533 (Foul Mother) - Imp Mother
(114348, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114348 (Fallen Warden) - Permanent Feign Death
(114349, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114349 (Fallen Warden) - Permanent Feign Death
(230547, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 230547 ([DNT] Bunny)
(100894, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 100894 (Referee)
(100525, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '197941 197897 204294'), -- 100525 (Glowing Sentry) - Elune's Light, Elune's Light, Elune's Light
(95885, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '355784 42459'), -- 95885 (Tirathon Saltheril) - [DNT] Send Event <Points> On Enter Combat, Dual Wield
(95887, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 95887 (Glazer)
(95886, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '355784 200354'), -- 95886 (Ash'Golm) - [DNT] Send Event <Points> On Enter Combat, Frozen
(99013, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '194814 42459'), -- 99013 (Drelanim Whisperwind) - Drelanim Whisperwind, Dual Wield
(99277, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '195189'), -- 99277 (Freeze Statue) - Countermeasure
(99956, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- 99956 (Fel-Infused Fury) - Replace Unarmed with 1H, Dual Wield
(98118, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 98118 (Lens)
(103093, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 103093 (Safety Net)
(114354, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 114354 (Immoliant Fury) - Permanent Feign Death
(98177, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '200888 204879 42459'), -- 98177 (Glayvianna Soulrender) - Demon Hunter Wings, Infusion, Dual Wield
(99953, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 99953 (Fallen Warden) - Permanent Feign Death
(98272, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 98272 (Immoliant Fury) - Permanent Feign Death
(98271, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 98271 (Felsworn Infester) - Permanent Feign Death
(96584, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191541 42459'), -- 96584 (Immoliant Fury) - Melee Override, Dual Wield
(98926, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '194580 42459'), -- 98926 (Shadow Hunter) - Replace Unarmed with 1H, Dual Wield
(96524, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '191235'), -- 96524 (Sentry) - Owl Statue Visual
(96587, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191585'); -- 96587 (Felsworn Infester) - Melee Override

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (246047,246048);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `artkit0`, `artkit1`, `artkit2`, `artkit3`, `artkit4`, `WorldEffectID`, `AIAnimKitID`) VALUES
(246047, 0, 0x00000008, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(246048, 0, 0x00000008, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000, `flags_extra` = 128 WHERE `entry`=230547; -- [DNT] Bunny
UPDATE `creature_template` SET `flags_extra` = 128 WHERE `entry` IN (98118,101548,104341);

-- Difficulty (Normal)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=120300 AND `DifficultyID`=1); -- 120300 (Glowing Sentry) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95888 AND `DifficultyID`=1); -- 95888 (Cordana Felsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=97678 AND `DifficultyID`=1); -- 97678 (Aranasi Broodmother) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=97677 AND `DifficultyID`=1); -- 97677 (Barbed Spiderling) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100364 AND `DifficultyID`=1); -- 100364 (Spirit of Vengeance) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=97689 AND `DifficultyID`=1); -- 97689 (Web) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=97681 AND `DifficultyID`=1); -- 97681 (Demon Spider) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=485, `VerifiedBuild`=61265 WHERE (`Entry`=102566 AND `DifficultyID`=1); -- 102566 (Grimhorn the Enslaver) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96657 AND `DifficultyID`=1); -- 96657 (Blade Dancer Illianna) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=485, `VerifiedBuild`=61265 WHERE (`Entry`=99649 AND `DifficultyID`=1); -- 99649 (Dreadlord Mendacius) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96015 AND `DifficultyID`=1); -- 96015 (Inquisitor Tormentorum) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=354, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=105824 AND `DifficultyID`=1); -- 105824 (Grimoira) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99198 AND `DifficultyID`=1); -- 99198 (Tirathon Saltheril) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99018 AND `DifficultyID`=1); -- 99018 (Drelanim Whisperwind) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99870 AND `DifficultyID`=1); -- 99870 (Malace Shade) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99806 AND `DifficultyID`=1); -- 99806 (Ozruk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99873 AND `DifficultyID`=1); -- 99873 (Moonbeak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99360 AND `DifficultyID`=1); -- 99360 (Vilethorn Blossom) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99872 AND `DifficultyID`=1); -- 99872 (Marin Bladewing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99837 AND `DifficultyID`=1); -- 99837 (Qiraji Mindslayer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=106196 AND `DifficultyID`=1); -- 106196 (Generic Bunny - QUEST - SCS) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114346 AND `DifficultyID`=1); -- 114346 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61265 WHERE (`Entry`=109453 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=109755 AND `DifficultyID`=1); -- 109755 (Sentry) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=104341 AND `DifficultyID`=1); -- 104341 (Torment) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114352 AND `DifficultyID`=1); -- 114352 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=109362 AND `DifficultyID`=1); -- 109362 (Sentry) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114351 AND `DifficultyID`=1); -- 114351 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `VerifiedBuild`=61265 WHERE (`Entry`=102584 AND `DifficultyID`=1); -- 102584 (Malignant Defiler) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114353 AND `DifficultyID`=1); -- 114353 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=101548 AND `DifficultyID`=1); -- 101548 (Updraft) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `VerifiedBuild`=61265 WHERE (`Entry`=102583 AND `DifficultyID`=1); -- 102583 (Fel Scorcher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114347 AND `DifficultyID`=1); -- 114347 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=98533 AND `DifficultyID`=1); -- 98533 (Foul Mother) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114348 AND `DifficultyID`=1); -- 114348 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114349 AND `DifficultyID`=1); -- 114349 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=230547 AND `DifficultyID`=0); -- 230547 ([DNT] Bunny) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98963 AND `DifficultyID`=1); -- 98963 (Blazing Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=100894 AND `DifficultyID`=1); -- 100894 (Referee) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100525 AND `DifficultyID`=1); -- 100525 (Glowing Sentry) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95885 AND `DifficultyID`=1); -- 95885 (Tirathon Saltheril) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95887 AND `DifficultyID`=1); -- 95887 (Glazer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95886 AND `DifficultyID`=1); -- 95886 (Ash'Golm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99013 AND `DifficultyID`=1); -- 99013 (Drelanim Whisperwind) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=99277 AND `DifficultyID`=1); -- 99277 (Freeze Statue) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98954 AND `DifficultyID`=1); -- 98954 (Felsworn Myrmidon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99956 AND `DifficultyID`=1); -- 99956 (Fel-Infused Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=98118 AND `DifficultyID`=1); -- 98118 (Lens) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=103093 AND `DifficultyID`=1); -- 103093 (Safety Net) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114354 AND `DifficultyID`=1); -- 114354 (Immoliant Fury) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=98177 AND `DifficultyID`=1); -- 98177 (Glayvianna Soulrender) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96480 AND `DifficultyID`=1); -- 96480 (Viletongue Belcher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=99953 AND `DifficultyID`=1); -- 99953 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=98272 AND `DifficultyID`=1); -- 98272 (Immoliant Fury) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=98271 AND `DifficultyID`=1); -- 98271 (Felsworn Infester) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96584 AND `DifficultyID`=1); -- 96584 (Immoliant Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98926 AND `DifficultyID`=1); -- 98926 (Shadow Hunter) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=96524 AND `DifficultyID`=1); -- 96524 (Sentry) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96587 AND `DifficultyID`=1); -- 96587 (Felsworn Infester) - CanSwim

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (106196,114346,109453,109755,104341,109362,114351,114349,230547,114348,108996,109006));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(106196, 2, 0, 0, 181, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 106196 (Generic Bunny - QUEST - SCS) - CanSwim, Floating
(114346, 2, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114346 (Fallen Warden) - Sessile, Floating
(109453, 2, 2, 2, 1159, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 109453 (Cell Door 3-5x1) - 
(109755, 2, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 109755 (Sentry) - Sessile, Floating
(104341, 2, 2, 2, 1159, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 104341 (Torment) - Floating
(109362, 2, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 109362 (Sentry) - Sessile, Floating
(114351, 2, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114351 (Fallen Warden) - Sessile, Floating
(114349, 2, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114349 (Fallen Warden) - Sessile, Floating
(230547, 2, 0, 0, 328, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 230547 ([DNT] Bunny) - Sessile, Floating
(114348, 2, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114348 (Fallen Warden) - Sessile, Floating
(108996, 2, 2, 2, 1159, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 108996 (Specter of Vengeance) - CanSwim
(109006, 2, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265); -- 109006 (Fallen Warden) - Sessile, Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=107445, `TypeFlags`=0x40000000 WHERE (`Entry`=106196 AND `DifficultyID`=2); -- Generic Bunny - QUEST - SCS
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117714, `TypeFlags`=0x40000000 WHERE (`Entry`=114346 AND `DifficultyID`=2); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=11.53849983215332031, `CreatureDifficultyID`=111511, `TypeFlags`=0x40000000, `TypeFlags2`=64 WHERE (`Entry`=109453 AND `DifficultyID`=2); -- Cell Door 3-5x1
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=11.53849983215332031, `CreatureDifficultyID`=111818, `TypeFlags`=0x40000000, `TypeFlags2`=64 WHERE (`Entry`=109755 AND `DifficultyID`=2); -- Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=34.61539840698242187, `CreatureDifficultyID`=105445, `TypeFlags`=0x40000000, `TypeFlags2`=70 WHERE (`Entry`=104341 AND `DifficultyID`=2); -- Torment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=11.53849983215332031, `CreatureDifficultyID`=111416, `TypeFlags`=0x40000000, `TypeFlags2`=64 WHERE (`Entry`=109362 AND `DifficultyID`=2); -- Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117721, `TypeFlags`=0x40000000 WHERE (`Entry`=114351 AND `DifficultyID`=2); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117719, `TypeFlags`=0x40000000 WHERE (`Entry`=114349 AND `DifficultyID`=2); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=281851, `TypeFlags`=0x60000410, `TypeFlags2`=117440518 WHERE (`Entry`=230547 AND `DifficultyID`=2); -- [DNT] Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117718, `TypeFlags`=0x40000000 WHERE (`Entry`=114348 AND `DifficultyID`=2); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=10, `CreatureDifficultyID`=110992, `TypeFlags`=0x50200058, `TypeFlags2`=6 WHERE (`Entry`=108996 AND `DifficultyID`=2); -- Specter of Vengeance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=111004, `TypeFlags`=0x40000000 WHERE (`Entry`=109006 AND `DifficultyID`=2); -- Fallen Warden

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61265 WHERE (`Entry`=120300 AND `DifficultyID`=2); -- 120300 (Glowing Sentry) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95888 AND `DifficultyID`=2); -- 95888 (Cordana Felsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=97678 AND `DifficultyID`=2); -- 97678 (Aranasi Broodmother) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=97677 AND `DifficultyID`=2); -- 97677 (Barbed Spiderling) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100364 AND `DifficultyID`=2); -- 100364 (Spirit of Vengeance) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=97681 AND `DifficultyID`=2); -- 97681 (Demon Spider) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=97689 AND `DifficultyID`=2); -- 97689 (Web) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `VerifiedBuild`=61265 WHERE (`Entry`=102566 AND `DifficultyID`=2); -- 102566 (Grimhorn the Enslaver) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96657 AND `DifficultyID`=2); -- 96657 (Blade Dancer Illianna) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `VerifiedBuild`=61265 WHERE (`Entry`=99649 AND `DifficultyID`=2); -- 99649 (Dreadlord Mendacius) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96015 AND `DifficultyID`=2); -- 96015 (Inquisitor Tormentorum) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=105824 AND `DifficultyID`=2); -- 105824 (Grimoira) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99018 AND `DifficultyID`=2); -- 99018 (Drelanim Whisperwind) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99198 AND `DifficultyID`=2); -- 99198 (Tirathon Saltheril) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99870 AND `DifficultyID`=2); -- 99870 (Malace Shade) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99806 AND `DifficultyID`=2); -- 99806 (Ozruk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99873 AND `DifficultyID`=2); -- 99873 (Moonbeak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99360 AND `DifficultyID`=2); -- 99360 (Vilethorn Blossom) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99837 AND `DifficultyID`=2); -- 99837 (Qiraji Mindslayer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99872 AND `DifficultyID`=2); -- 99872 (Marin Bladewing) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114352 AND `DifficultyID`=2); -- 114352 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114353 AND `DifficultyID`=2); -- 114353 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=61265 WHERE (`Entry`=102583 AND `DifficultyID`=2); -- 102583 (Fel Scorcher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=61265 WHERE (`Entry`=102584 AND `DifficultyID`=2); -- 102584 (Malignant Defiler) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=101548 AND `DifficultyID`=2); -- 101548 (Updraft) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114347 AND `DifficultyID`=2); -- 114347 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=98533 AND `DifficultyID`=2); -- 98533 (Foul Mother) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98963 AND `DifficultyID`=2); -- 98963 (Blazing Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=100894 AND `DifficultyID`=2); -- 100894 (Referee) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=99277 AND `DifficultyID`=2); -- 99277 (Freeze Statue) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98954 AND `DifficultyID`=2); -- 98954 (Felsworn Myrmidon) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99013 AND `DifficultyID`=2); -- 99013 (Drelanim Whisperwind) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=98177 AND `DifficultyID`=2); -- 98177 (Glayvianna Soulrender) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99956 AND `DifficultyID`=2); -- 99956 (Fel-Infused Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61265 WHERE (`Entry`=100525 AND `DifficultyID`=2); -- 100525 (Glowing Sentry) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114354 AND `DifficultyID`=2); -- 114354 (Immoliant Fury) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=99953 AND `DifficultyID`=2); -- 99953 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=98272 AND `DifficultyID`=2); -- 98272 (Immoliant Fury) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96584 AND `DifficultyID`=2); -- 96584 (Immoliant Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95885 AND `DifficultyID`=2); -- 95885 (Tirathon Saltheril) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96587 AND `DifficultyID`=2); -- 96587 (Felsworn Infester) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95887 AND `DifficultyID`=2); -- 95887 (Glazer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=98271 AND `DifficultyID`=2); -- 98271 (Felsworn Infester) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95886 AND `DifficultyID`=2); -- 95886 (Ash'Golm) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=96524 AND `DifficultyID`=2); -- 96524 (Sentry) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=103093 AND `DifficultyID`=2); -- 103093 (Safety Net) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x20000100, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=98118 AND `DifficultyID`=2); -- 98118 (Lens) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96480 AND `DifficultyID`=2); -- 96480 (Viletongue Belcher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98926 AND `DifficultyID`=2); -- 98926 (Shadow Hunter) - CanSwim

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (105824,106196,114346,109453,108996,109755,104341,109362,114351,114349,114348,230547,109006));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(105824, 23, 1, 1, 628, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 105824 (Grimoira) - Sessile, CanSwim, Floating
(106196, 23, 0, 0, 181, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 106196 (Generic Bunny - QUEST - SCS) - CanSwim, Floating
(114346, 23, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114346 (Fallen Warden) - Sessile, Floating
(109453, 23, 2, 2, 1159, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 109453 (Cell Door 3-5x1) - 
(108996, 23, 2, 2, 1159, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 108996 (Specter of Vengeance) - CanSwim
(109755, 23, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 109755 (Sentry) - Sessile, Floating
(104341, 23, 2, 2, 1159, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 104341 (Torment) - Floating
(109362, 23, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 109362 (Sentry) - Sessile, Floating
(114351, 23, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114351 (Fallen Warden) - Sessile, Floating
(114349, 23, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114349 (Fallen Warden) - Sessile, Floating
(114348, 23, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 114348 (Fallen Warden) - Sessile, Floating
(230547, 23, 0, 0, 328, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 230547 ([DNT] Bunny) - Sessile, Floating
(109006, 23, 2, 2, 1159, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265); -- 109006 (Fallen Warden) - Sessile, Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=24.75, `CreatureDifficultyID`=107040, `TypeFlags`=0x80200048 WHERE (`Entry`=105824 AND `DifficultyID`=23); -- Grimoira
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=107445, `TypeFlags`=0x40000000 WHERE (`Entry`=106196 AND `DifficultyID`=23); -- Generic Bunny - QUEST - SCS
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117714, `TypeFlags`=0x40000000 WHERE (`Entry`=114346 AND `DifficultyID`=23); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=11.53849983215332031, `CreatureDifficultyID`=111511, `TypeFlags`=0x40000000, `TypeFlags2`=64 WHERE (`Entry`=109453 AND `DifficultyID`=23); -- Cell Door 3-5x1
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=10, `CreatureDifficultyID`=110992, `TypeFlags`=0x50200058, `TypeFlags2`=6 WHERE (`Entry`=108996 AND `DifficultyID`=23); -- Specter of Vengeance
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=11.53849983215332031, `CreatureDifficultyID`=111818, `TypeFlags`=0x40000000, `TypeFlags2`=64 WHERE (`Entry`=109755 AND `DifficultyID`=23); -- Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=34.61539840698242187, `CreatureDifficultyID`=105445, `TypeFlags`=0x40000000, `TypeFlags2`=70 WHERE (`Entry`=104341 AND `DifficultyID`=23); -- Torment
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=11.53849983215332031, `CreatureDifficultyID`=111416, `TypeFlags`=0x40000000, `TypeFlags2`=64 WHERE (`Entry`=109362 AND `DifficultyID`=23); -- Sentry
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117721, `TypeFlags`=0x40000000 WHERE (`Entry`=114351 AND `DifficultyID`=23); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117719, `TypeFlags`=0x40000000 WHERE (`Entry`=114349 AND `DifficultyID`=23); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=117718, `TypeFlags`=0x40000000 WHERE (`Entry`=114348 AND `DifficultyID`=23); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=281851, `TypeFlags`=0x60000410, `TypeFlags2`=117440518 WHERE (`Entry`=230547 AND `DifficultyID`=23); -- [DNT] Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=111004, `TypeFlags`=0x40000000 WHERE (`Entry`=109006 AND `DifficultyID`=23); -- Fallen Warden
UPDATE `creature_template_difficulty` SET `CreatureDifficultyID`=273194 WHERE (`Entry`=120652 AND `DifficultyID`=23); -- Global Affix Stalker

UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61265 WHERE (`Entry`=120300 AND `DifficultyID`=23); -- 120300 (Glowing Sentry) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95888 AND `DifficultyID`=23); -- 95888 (Cordana Felsong) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=97678 AND `DifficultyID`=23); -- 97678 (Aranasi Broodmother) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=97677 AND `DifficultyID`=23); -- 97677 (Barbed Spiderling) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100364 AND `DifficultyID`=23); -- 100364 (Spirit of Vengeance) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=97681 AND `DifficultyID`=23); -- 97681 (Demon Spider) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=97689 AND `DifficultyID`=23); -- 97689 (Web) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=102566 AND `DifficultyID`=23); -- 102566 (Grimhorn the Enslaver) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=99649 AND `DifficultyID`=23); -- 99649 (Dreadlord Mendacius) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96657 AND `DifficultyID`=23); -- 96657 (Blade Dancer Illianna) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96015 AND `DifficultyID`=23); -- 96015 (Inquisitor Tormentorum) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99018 AND `DifficultyID`=23); -- 99018 (Drelanim Whisperwind) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99198 AND `DifficultyID`=23); -- 99198 (Tirathon Saltheril) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99806 AND `DifficultyID`=23); -- 99806 (Ozruk) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99870 AND `DifficultyID`=23); -- 99870 (Malace Shade) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99873 AND `DifficultyID`=23); -- 99873 (Moonbeak) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99872 AND `DifficultyID`=23); -- 99872 (Marin Bladewing) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99837 AND `DifficultyID`=23); -- 99837 (Qiraji Mindslayer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114352 AND `DifficultyID`=23); -- 114352 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114353 AND `DifficultyID`=23); -- 114353 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=102584 AND `DifficultyID`=23); -- 102584 (Malignant Defiler) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=101548 AND `DifficultyID`=23); -- 101548 (Updraft) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114347 AND `DifficultyID`=23); -- 114347 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=98533 AND `DifficultyID`=23); -- 98533 (Foul Mother) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=102583 AND `DifficultyID`=23); -- 102583 (Fel Scorcher) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98963 AND `DifficultyID`=23); -- 98963 (Blazing Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99360 AND `DifficultyID`=23); -- 99360 (Vilethorn Blossom) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=100894 AND `DifficultyID`=23); -- 100894 (Referee) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61265 WHERE (`Entry`=100525 AND `DifficultyID`=23); -- 100525 (Glowing Sentry) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95886 AND `DifficultyID`=23); -- 95886 (Ash'Golm) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95885 AND `DifficultyID`=23); -- 95885 (Tirathon Saltheril) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95887 AND `DifficultyID`=23); -- 95887 (Glazer) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99013 AND `DifficultyID`=23); -- 99013 (Drelanim Whisperwind) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=99277 AND `DifficultyID`=23); -- 99277 (Freeze Statue) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99956 AND `DifficultyID`=23); -- 99956 (Fel-Infused Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=103093 AND `DifficultyID`=23); -- 103093 (Safety Net) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `StaticFlags3`=0x40000, `VerifiedBuild`=61265 WHERE (`Entry`=98118 AND `DifficultyID`=23); -- 98118 (Lens) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98954 AND `DifficultyID`=23); -- 98954 (Felsworn Myrmidon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96480 AND `DifficultyID`=23); -- 96480 (Viletongue Belcher) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=114354 AND `DifficultyID`=23); -- 114354 (Immoliant Fury) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=98271 AND `DifficultyID`=23); -- 98271 (Felsworn Infester) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=99953 AND `DifficultyID`=23); -- 99953 (Fallen Warden) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=98177 AND `DifficultyID`=23); -- 98177 (Glayvianna Soulrender) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=98272 AND `DifficultyID`=23); -- 98272 (Immoliant Fury) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96584 AND `DifficultyID`=23); -- 96584 (Immoliant Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=98926 AND `DifficultyID`=23); -- 98926 (Shadow Hunter) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=96524 AND `DifficultyID`=23); -- 96524 (Sentry) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96587 AND `DifficultyID`=23); -- 96587 (Felsworn Infester) - CanSwim

-- Model
UPDATE `creature_model_info` SET `VerifiedBuild`=61265 WHERE `DisplayID` IN (75726, 75725, 66480, 65926, 65922, 64805, 58479, 66917, 64719, 65646, 64442, 36475, 15740, 63527, 68307, 61906, 66774, 61910, 63165, 65542, 66773, 61909, 62511, 60087, 67347, 62572, 62374, 65890, 67001, 65074, 65155, 67798, 70673, 64727, 70674, 46710, 66806, 70670, 73258, 73260, 73259, 66403, 70678, 65666, 70680, 66736, 11686, 64253);
UPDATE `creature_model_info` SET `BoundingRadius`=2.085362434387207031, `VerifiedBuild`=61265 WHERE `DisplayID`=64331;
UPDATE `creature_model_info` SET `BoundingRadius`=0.682237327098846435, `CombatReach`=2.024999856948852539, `VerifiedBuild`=61265 WHERE `DisplayID`=64432;
UPDATE `creature_model_info` SET `BoundingRadius`=4.277837753295898437, `CombatReach`=14.5, `VerifiedBuild`=61265 WHERE `DisplayID`=66204;
UPDATE `creature_model_info` SET `BoundingRadius`=0.732773482799530029, `CombatReach`=2.175000190734863281, `VerifiedBuild`=61265 WHERE `DisplayID`=64441;

-- Template movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (98963,95887);
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(98963, NULL, 0, 2, NULL),
(95887, 1, 0, 0, NULL);

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (193619));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 193619, 0, 0, 51, 0, 5, 98272, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 98272'),
(13, 1, 193619, 0, 1, 51, 0, 5, 98271, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 98271');

-- Path for Fel-Infused Fury
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+63;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+63, @CGUID+63, 0, 0, 515, 0, 0),
(@CGUID+63, @CGUID+68, 3, 270, 515, 2, 5);

SET @MOVERGUID := @CGUID+63;
SET @ENTRY := 99956;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Fel-Infused Fury - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4184.6006, -470.94098, 269.89285, NULL, 0),
(@PATH, 1, 4184.789, -466.75696, 269.9944, NULL, 0),
(@PATH, 2, 4184.8975, -450.5382, 269.8169, NULL, 5494),
(@PATH, 3, 4184.7896, -466.67773, 269.9996, NULL, 0),
(@PATH, 4, 4184.6006, -470.94098, 269.89285, NULL, 0),
(@PATH, 5, 4184.4307, -506.4809, 269.95923, NULL, 5479);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '194580 42459');

-- Path for Barbed Spiderling
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+305;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+305, @CGUID+305, 0, 0, 515, 0, 0),
(@CGUID+305, @CGUID+296, 5, 60, 515, 6, 17),
(@CGUID+305, @CGUID+299, 7, 30, 515, 6, 17),
(@CGUID+305, @CGUID+300, 5, 300, 515, 6, 17),
(@CGUID+305, @CGUID+302, 7, 330, 515, 6, 17);

SET @MOVERGUID := @CGUID+305;
SET @ENTRY := 97677;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Barbed Spiderling - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4345.152, -237.5868, -267.32388, NULL, 0),
(@PATH, 1, 4350.9673, -223.38368, -265.16254, NULL, 0),
(@PATH, 2, 4365.5537, -226.06598, -263.27353, NULL, 0),
(@PATH, 3, 4383.4946, -232.07466, -260.89676, NULL, 0),
(@PATH, 4, 4393.9575, -242.16841, -260.5531, NULL, 0),
(@PATH, 5, 4380.598, -271.7795, -261.98727, NULL, 0),
(@PATH, 6, 4377.2466, -302.3611, -260.25027, NULL, 9472),
(@PATH, 7, 4380.598, -271.7795, -261.98727, NULL, 0),
(@PATH, 8, 4393.9336, -242.2218, -260.57083, NULL, 0),
(@PATH, 9, 4383.645, -232.125, -260.8774, NULL, 0),
(@PATH, 10, 4365.5537, -226.06598, -263.27353, NULL, 0),
(@PATH, 11, 4350.9673, -223.38368, -265.16254, NULL, 0),
(@PATH, 12, 4345.152, -237.5868, -267.32388, NULL, 0),
(@PATH, 13, 4337.224, -255.49654, -272.94757, NULL, 0),
(@PATH, 14, 4336.962, -271.09897, -278.62582, NULL, 0),
(@PATH, 15, 4329.9165, -292.0729, -284.94992, NULL, 0),
(@PATH, 16, 4323.703, -310.18924, -283.5743, NULL, 0),
(@PATH, 17, 4328.8506, -323.90103, -283.51926, NULL, 8724),
(@PATH, 18, 4323.703, -310.18924, -283.5743, NULL, 0),
(@PATH, 19, 4329.9165, -292.0729, -284.94992, NULL, 0),
(@PATH, 20, 4336.962, -271.09897, -278.62582, NULL, 0),
(@PATH, 21, 4337.224, -255.49654, -272.94757, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '192750');

-- Path for Torment
SET @MOVERGUID := @CGUID+188;
SET @ENTRY := 104341;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2890, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4447.0356, -430.48218, 132.96263, NULL, 0),
(@PATH, 1, 4446.3853, -429.5089, 132.96263, NULL, 0),
(@PATH, 2, 4445.412, -428.85858, 132.96263, NULL, 0),
(@PATH, 3, 4444.264, -428.63022, 132.96263, NULL, 0),
(@PATH, 4, 4443.116, -428.85858, 132.96263, NULL, 0),
(@PATH, 5, 4442.143, -429.5089, 132.96263, NULL, 0),
(@PATH, 6, 4441.4927, -430.48218, 132.96263, NULL, 0),
(@PATH, 7, 4441.264, -431.63022, 132.96263, NULL, 0),
(@PATH, 8, 4441.4927, -432.77826, 132.96263, NULL, 0),
(@PATH, 9, 4442.143, -433.75153, 132.96263, NULL, 0),
(@PATH, 10, 4443.116, -434.40186, 132.96263, NULL, 0),
(@PATH, 11, 4444.264, -434.63022, 132.96263, NULL, 0),
(@PATH, 12, 4445.412, -434.40186, 132.96263, NULL, 0),
(@PATH, 13, 4446.3853, -433.75153, 132.96263, NULL, 0),
(@PATH, 14, 4447.0356, -432.77826, 132.96263, NULL, 0),
(@PATH, 15, 4447.264, -431.63022, 132.96263, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+201;
SET @ENTRY := 104341;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2886, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4433.9746, -412.0022, 126.0808, NULL, 0),
(@PATH, 1, 4433.324, -412.97546, 126.0808, NULL, 0),
(@PATH, 2, 4432.351, -413.6258, 126.0808, NULL, 0),
(@PATH, 3, 4431.203, -413.85416, 126.0808, NULL, 0),
(@PATH, 4, 4430.055, -413.6258, 126.0808, NULL, 0),
(@PATH, 5, 4429.082, -412.97546, 126.0808, NULL, 0),
(@PATH, 6, 4428.4316, -412.0022, 126.0808, NULL, 0),
(@PATH, 7, 4428.203, -410.85416, 126.0808, NULL, 0),
(@PATH, 8, 4428.4316, -409.70612, 126.0808, NULL, 0),
(@PATH, 9, 4429.082, -408.73285, 126.0808, NULL, 0),
(@PATH, 10, 4430.055, -408.08252, 126.0808, NULL, 0),
(@PATH, 11, 4431.203, -407.85416, 126.0808, NULL, 0),
(@PATH, 12, 4432.351, -408.08252, 126.0808, NULL, 0),
(@PATH, 13, 4433.324, -408.73285, 126.0808, NULL, 0),
(@PATH, 14, 4433.9746, -409.70612, 126.0808, NULL, 0),
(@PATH, 15, 4434.203, -410.85416, 126.0808, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+205;
SET @ENTRY := 104341;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2886, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4444.1377, -417.26862, 130.82994, NULL, 0),
(@PATH, 1, 4443.4873, -416.29535, 130.82994, NULL, 0),
(@PATH, 2, 4442.514, -415.64502, 130.82994, NULL, 0),
(@PATH, 3, 4441.366, -415.41666, 130.82994, NULL, 0),
(@PATH, 4, 4440.2183, -415.64502, 130.82994, NULL, 0),
(@PATH, 5, 4439.245, -416.29535, 130.82994, NULL, 0),
(@PATH, 6, 4438.5947, -417.26862, 130.82994, NULL, 0),
(@PATH, 7, 4438.366, -418.41666, 130.82994, NULL, 0),
(@PATH, 8, 4438.5947, -419.5647, 130.82994, NULL, 0),
(@PATH, 9, 4439.245, -420.53796, 130.82994, NULL, 0),
(@PATH, 10, 4440.2183, -421.1883, 130.82994, NULL, 0),
(@PATH, 11, 4441.366, -421.41666, 130.82994, NULL, 0),
(@PATH, 12, 4442.514, -421.1883, 130.82994, NULL, 0),
(@PATH, 13, 4443.4873, -420.53796, 130.82994, NULL, 0),
(@PATH, 14, 4444.1377, -419.5647, 130.82994, NULL, 0),
(@PATH, 15, 4444.366, -418.41666, 130.82994, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+208;
SET @ENTRY := 104341;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2890, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4446.016, -401.4258, 132.2955, NULL, 0),
(@PATH, 1, 4445.3657, -402.39908, 132.2955, NULL, 0),
(@PATH, 2, 4444.3926, -403.0494, 132.2955, NULL, 0),
(@PATH, 3, 4443.2446, -403.27777, 132.2955, NULL, 0),
(@PATH, 4, 4442.0967, -403.0494, 132.2955, NULL, 0),
(@PATH, 5, 4441.1235, -402.39908, 132.2955, NULL, 0),
(@PATH, 6, 4440.473, -401.4258, 132.2955, NULL, 0),
(@PATH, 7, 4440.2446, -400.27777, 132.2955, NULL, 0),
(@PATH, 8, 4440.473, -399.12973, 132.2955, NULL, 0),
(@PATH, 9, 4441.1235, -398.15646, 132.2955, NULL, 0),
(@PATH, 10, 4442.0967, -397.50613, 132.2955, NULL, 0),
(@PATH, 11, 4443.2446, -397.27777, 132.2955, NULL, 0),
(@PATH, 12, 4444.3926, -397.50613, 132.2955, NULL, 0),
(@PATH, 13, 4445.3657, -398.15646, 132.2955, NULL, 0),
(@PATH, 14, 4446.016, -399.12973, 132.2955, NULL, 0),
(@PATH, 15, 4446.2446, -400.27777, 132.2955, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+206;
SET @ENTRY := 104341;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2890, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4453.3237, -415.78598, 132.60553, NULL, 0),
(@PATH, 1, 4452.6733, -414.8127, 132.60553, NULL, 0),
(@PATH, 2, 4451.7, -414.16238, 132.60553, NULL, 0),
(@PATH, 3, 4450.5522, -413.93402, 132.60553, NULL, 0),
(@PATH, 4, 4449.4043, -414.16238, 132.60553, NULL, 0),
(@PATH, 5, 4448.431, -414.8127, 132.60553, NULL, 0),
(@PATH, 6, 4447.781, -415.78598, 132.60553, NULL, 0),
(@PATH, 7, 4447.5522, -416.93402, 132.60553, NULL, 0),
(@PATH, 8, 4447.781, -418.08206, 132.60553, NULL, 0),
(@PATH, 9, 4448.431, -419.05533, 132.60553, NULL, 0),
(@PATH, 10, 4449.4043, -419.70566, 132.60553, NULL, 0),
(@PATH, 11, 4450.5522, -419.93402, 132.60553, NULL, 0),
(@PATH, 12, 4451.7, -419.70566, 132.60553, NULL, 0),
(@PATH, 13, 4452.6733, -419.05533, 132.60553, NULL, 0),
(@PATH, 14, 4453.3237, -418.08206, 132.60553, NULL, 0),
(@PATH, 15, 4453.5522, -416.93402, 132.60553, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+210;
SET @ENTRY := 104341;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2890, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4455.5786, -407.8728, 134.94705, NULL, 0),
(@PATH, 1, 4454.928, -406.89954, 134.94705, NULL, 0),
(@PATH, 2, 4453.955, -406.2492, 134.94705, NULL, 0),
(@PATH, 3, 4452.807, -406.02084, 134.94705, NULL, 0),
(@PATH, 4, 4451.659, -406.2492, 134.94705, NULL, 0),
(@PATH, 5, 4450.686, -406.89954, 134.94705, NULL, 0),
(@PATH, 6, 4450.0356, -407.8728, 134.94705, NULL, 0),
(@PATH, 7, 4449.807, -409.02084, 134.94705, NULL, 0),
(@PATH, 8, 4450.0356, -410.16888, 134.94705, NULL, 0),
(@PATH, 9, 4450.686, -411.14215, 134.94705, NULL, 0),
(@PATH, 10, 4451.659, -411.79248, 134.94705, NULL, 0),
(@PATH, 11, 4452.807, -412.02084, 134.94705, NULL, 0),
(@PATH, 12, 4453.955, -411.79248, 134.94705, NULL, 0),
(@PATH, 13, 4454.928, -411.14215, 134.94705, NULL, 0),
(@PATH, 14, 4455.5786, -410.16888, 134.94705, NULL, 0),
(@PATH, 15, 4455.807, -409.02084, 134.94705, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+211;
SET @ENTRY := 104341;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2885, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4460.9893, -419.33554, 127.03355, NULL, 0),
(@PATH, 1, 4460.339, -420.3088, 127.03355, NULL, 0),
(@PATH, 2, 4459.3657, -420.95914, 127.03355, NULL, 0),
(@PATH, 3, 4458.218, -421.1875, 127.03355, NULL, 0),
(@PATH, 4, 4457.07, -420.95914, 127.03355, NULL, 0),
(@PATH, 5, 4456.0967, -420.3088, 127.03355, NULL, 0),
(@PATH, 6, 4455.4463, -419.33554, 127.03355, NULL, 0),
(@PATH, 7, 4455.218, -418.1875, 127.03355, NULL, 0),
(@PATH, 8, 4455.4463, -417.03946, 127.03355, NULL, 0),
(@PATH, 9, 4456.0967, -416.0662, 127.03355, NULL, 0),
(@PATH, 10, 4457.07, -415.41586, 127.03355, NULL, 0),
(@PATH, 11, 4458.218, -415.1875, 127.03355, NULL, 0),
(@PATH, 12, 4459.3657, -415.41586, 127.03355, NULL, 0),
(@PATH, 13, 4460.339, -416.0662, 127.03355, NULL, 0),
(@PATH, 14, 4460.9893, -417.03946, 127.03355, NULL, 0),
(@PATH, 15, 4461.218, -418.1875, 127.03355, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+213;
SET @ENTRY := 104341;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2885, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4461.1377, -401.4258, 132.2955, NULL, 0),
(@PATH, 1, 4460.4873, -402.39908, 132.2955, NULL, 0),
(@PATH, 2, 4459.514, -403.0494, 132.2955, NULL, 0),
(@PATH, 3, 4458.366, -403.27777, 132.2955, NULL, 0),
(@PATH, 4, 4457.2183, -403.0494, 132.2955, NULL, 0),
(@PATH, 5, 4456.245, -402.39908, 132.2955, NULL, 0),
(@PATH, 6, 4455.5947, -401.4258, 132.2955, NULL, 0),
(@PATH, 7, 4455.366, -400.27777, 132.2955, NULL, 0),
(@PATH, 8, 4455.5947, -399.12973, 132.2955, NULL, 0),
(@PATH, 9, 4456.245, -398.15646, 132.2955, NULL, 0),
(@PATH, 10, 4457.2183, -397.50613, 132.2955, NULL, 0),
(@PATH, 11, 4458.366, -397.27777, 132.2955, NULL, 0),
(@PATH, 12, 4459.514, -397.50613, 132.2955, NULL, 0),
(@PATH, 13, 4460.4873, -398.15646, 132.2955, NULL, 0),
(@PATH, 14, 4461.1377, -399.12973, 132.2955, NULL, 0),
(@PATH, 15, 4461.366, -400.27777, 132.2955, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Torment
SET @MOVERGUID := @CGUID+214;
SET @ENTRY := 104341;
SET @PATHOFFSET := 8;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.2886, 'Torment - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 4467.092, -413.3016, 128.89491, NULL, 0),
(@PATH, 1, 4466.4414, -412.32834, 128.89491, NULL, 0),
(@PATH, 2, 4465.4683, -411.678, 128.89491, NULL, 0),
(@PATH, 3, 4464.3203, -411.44965, 128.89491, NULL, 0),
(@PATH, 4, 4463.1724, -411.678, 128.89491, NULL, 0),
(@PATH, 5, 4462.199, -412.32834, 128.89491, NULL, 0),
(@PATH, 6, 4461.549, -413.3016, 128.89491, NULL, 0),
(@PATH, 7, 4461.3203, -414.44965, 128.89491, NULL, 0),
(@PATH, 8, 4461.549, -415.5977, 128.89491, NULL, 0),
(@PATH, 9, 4462.199, -416.57095, 128.89491, NULL, 0),
(@PATH, 10, 4463.1724, -417.22128, 128.89491, NULL, 0),
(@PATH, 11, 4464.3203, -417.44965, 128.89491, NULL, 0),
(@PATH, 12, 4465.4683, -417.22128, 128.89491, NULL, 0),
(@PATH, 13, 4466.4414, -416.57095, 128.89491, NULL, 0),
(@PATH, 14, 4467.092, -415.5977, 128.89491, NULL, 0),
(@PATH, 15, 4467.3203, -414.44965, 128.89491, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
