-- 
SET @CGUID := 850186;
SET @OGUID := 500391;

DELETE FROM `creature` WHERE `guid` =452763 AND `id`=85307;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+48;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 149131, 0, 1519, 10523, 0, 0, 0, 0, 1, -9005.92578125, 885.86981201171875, 64.82848358154296875, 1.396694779396057128, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- Apprentice Mage (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 290038 - Arcane Power)
(@CGUID+1, 149131, 0, 1519, 10523, 0, 0, 0, 0, 1, -9009.154296875, 892.5069580078125, 64.29975128173828125, 0.396958529949188232, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 149131 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 290038 - Arcane Power)
(@CGUID+2, 149131, 0, 1519, 10523, 0, 0, 0, 0, 1, -9007.484375, 887.95489501953125, 64.5647125244140625, 0.733172476291656494, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 149131 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 290038 - Arcane Power)
(@CGUID+3, 149131, 0, 1519, 10523, 0, 0, 0, 0, 1, -9009.015625, 889.87152099609375, 64.5970916748046875, 0.724288225173950195, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 149131 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 290038 - Arcane Power)
(@CGUID+4, 149131, 0, 1519, 10523, 0, 0, 0, 0, 1, -9003.4755859375, 887.80731201171875, 63.76767349243164062, 1.431073546409606933, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 149131 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 290038 - Arcane Power)
(@CGUID+5, 5498, 0, 1519, 10523, 0, 0, 0, 0, 1, -9003.8798828125, 891.95489501953125, 63.76767349243164062, 3.925480127334594726, 120, 0, 0, 14739, 0, 0, 0, 0, 0, 41488), -- 5498 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 290038 - Arcane Power)
(@CGUID+6, 85307, 0, 1519, 10523, 0, 0, 0, 0, 0, -9004.9423828125, 871.625, 129.77545166015625, 3.151764869689941406, 120, 0, 0, 16040, 8520, 0, 0, 0, 0, 41488), -- Sparkbright (Area: Wizard's Sanctum - Difficulty: 0)
(@CGUID+7, 149124, 0, 1519, 10523, 0, 0, 0, 0, 0, -9015.732421875, 860.91668701171875, 63.76767730712890625, 1.63688051700592041, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 41488), -- 149124 (Area: Wizard's Sanctum - Difficulty: 0)
(@CGUID+8, 149124, 0, 1519, 10523, 0, 0, 0, 0, 0, -8991.4755859375, 878.609375, 63.76767349243164062, 3.214738130569458007, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 41488), -- 149124 (Area: Wizard's Sanctum - Difficulty: 0)
(@CGUID+9, 149124, 0, 1519, 10523, 0, 0, 0, 0, 0, -9014.2392578125, 907.592041015625, 63.76767349243164062, 4.857684612274169921, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 41488), -- 149124 (Area: Wizard's Sanctum - Difficulty: 0)
(@CGUID+10, 149124, 0, 1519, 10523, 0, 0, 0, 0, 0, -9037.8486328125, 889.2117919921875, 63.76767349243164062, 0.136259034276008605, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 41488), -- 149124 (Area: Wizard's Sanctum - Difficulty: 0)
(@CGUID+11, 149121, 0, 1519, 10523, 0, 0, 0, 0, 0, -9001.58203125, 875.8038330078125, 64.9745025634765625, 0, 120, 0, 0, 11791, 0, 1, 0, 0, 0, 41488), -- 149121 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: ) (possible waypoints or random movement) Summoned Guardian
(@CGUID+12, 149121, 0, 1519, 10523, 0, 0, 0, 0, 0, -9039.658203125, 933.9149169921875, 66.24102783203125, 5.21697092056274414, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 41488), -- 149121 (Area: Wizard's Sanctum - Difficulty: 0) Summoned Guardian
(@CGUID+13, 149121, 0, 1519, 10523, 0, 0, 0, 0, 0, -9056.4580078125, 921.279541015625, 66.24102783203125, 5.28158426284790039, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 41488), -- 149121 (Area: Wizard's Sanctum - Difficulty: 0) Summoned Guardian
(@CGUID+14, 2485, 0, 1519, 10523, 0, 0, 0, 0, 1, -9041.888671875, 930.90106201171875, 66.24102783203125, 5.778738975524902343, 120, 0, 0, 14739, 0, 0, 0, 0, 0, 41488), -- 2485 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: ) Larimaine Purdue
(@CGUID+15, 331, 0, 1519, 10523, 0, 0, 0, 0, 1, -9045.4970703125, 923.5242919921875, 66.535980224609375, 5.380890369415283203, 120, 0, 0, 15918, 0, 0, 0, 0, 0, 41488), -- 331 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: ) Maginor Dumas
(@CGUID+16, 5497, 0, 1519, 10523, 0, 0, 0, 0, 0, -9052.326171875, 922.03302001953125, 66.24102783203125, 5.530740737915039062, 120, 0, 0, 13560, 0, 0, 0, 0, 0, 41488), -- 5497 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 56384 - Arcane Momentum) Jennea Cannon
(@CGUID+17, 148233, 0, 1519, 10523, 0, 0, 0, 0, 1, -9060.4443359375, 890.59375, 68.1259613037109375, 4.597506523132324218, 120, 0, 0, 2661, 3191, 0, 0, 0, 0, 41488), -- 148233 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 174827 - Garrison Magus) Kirin Tor Magus
(@CGUID+18, 148233, 0, 1519, 10523, 0, 0, 0, 0, 1, -9065.232421875, 887.14410400390625, 68.12586212158203125, 5.999193191528320312, 120, 0, 0, 2661, 3191, 0, 0, 0, 0, 41488), -- 148233 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 174827 - Garrison Magus) Kirin Tor Magus
(@CGUID+19, 148796, 0, 1519, 10523, 0, 0, 0, 0, 0, -9094.4375, 874.8819580078125, 68.125732421875, 3.059573650360107421, 120, 0, 0, 4945, 4393, 0, 0, 0, 0, 41488), -- 148796 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 287413 - Boralus Portal Channel) Storm"s Wake Tidesage
(@CGUID+20, 148796, 0, 1519, 10523, 0, 0, 0, 0, 0, -9098.607421875, 880.2430419921875, 68.1257171630859375, 4.564074516296386718, 120, 0, 0, 4945, 4393, 0, 0, 0, 0, 41488), -- 148796 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 287413 - Boralus Portal Channel) Storm"s Wake Tidesage
(@CGUID+21, 173545, 0, 1519, 10523, 0, 0, 0, 0, 0, -9097.1220703125, 891.96527099609375, 68.12548828125, 1.6488189697265625, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 173545 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 339689 - [DNT] DK Channel) Ebon Blade Acolyte
(@CGUID+22, 173545, 0, 1519, 10523, 0, 0, 0, 0, 0, -9090.9326171875, 896.435791015625, 68.12548065185546875, 3.178387165069580078, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 173545 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 339689 - [DNT] DK Channel) Ebon Blade Acolyte
(@CGUID+23, 147785, 0, 1519, 10523, 0, 0, 0, 0, 1, -9078.22265625, 905.32464599609375, 68.1258544921875, 1.853898286819458007, 120, 0, 0, 3494, 3801, 0, 0, 0, 0, 41488), -- 147785 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 287193 - Azsuna Portal Channel) Nar"thalas Mage
(@CGUID+24, 147785, 0, 1519, 10523, 0, 0, 0, 0, 1, -9074.1318359375, 908.6961669921875, 68.12567901611328125, 2.86431288719177246, 120, 0, 0, 3494, 3801, 0, 0, 0, 0, 41488), -- 147785 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 287193 - Azsuna Portal Channel) Nar"thalas Mage
(@CGUID+25, 149099, 0, 1519, 10523, 0, 0, 0, 0, 0, -9018.1669921875, 950.640625, 68.12569427490234375, 2.593385696411132812, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 41488), -- 149099 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 289141 - Dalaran Portal Channel) Silver Covenant Mage
(@CGUID+26, 149099, 0, 1519, 10523, 0, 0, 0, 0, 0, -9022.9306640625, 946.88018798828125, 68.12575531005859375, 1.745332956314086914, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 41488), -- 149099 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 289141 - Dalaran Portal Channel) Silver Covenant Mage
(@CGUID+27, 147714, 0, 1519, 10523, 0, 0, 0, 0, 1, -9006.017578125, 960.73614501953125, 68.12577056884765625, 1.710482358932495117, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 147714 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 286636 - Exodar Portal Channel) Exodar Portal-Keeper
(@CGUID+28, 147714, 0, 1519, 10523, 0, 0, 0, 0, 1, -9001.611328125, 964.25347900390625, 68.125701904296875, 2.60289311408996582, 120, 0, 0, 12735, 5751, 0, 0, 0, 0, 41488), -- 147714 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 286636 - Exodar Portal Channel) Exodar Portal-Keeper
(@CGUID+29, 155739, 0, 1519, 10523, 0, 0, 0, 0, 0, -8985.4794921875, 959.72393798828125, 68.57037353515625, 1.391814827919006347, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 41488), -- 155739 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 303508 - [DNT] Caverns of Time Portal Channel) Bronze Chronomancer
(@CGUID+30, 155739, 0, 1519, 10523, 0, 0, 0, 0, 0, -8988.3837890625, 963.09375, 68.570281982421875, 0.295933663845062255, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 41488), -- 155739 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 303508 - [DNT] Caverns of Time Portal Channel) Bronze Chronomancer
(@CGUID+31, 148124, 0, 1519, 10523, 0, 0, 0, 0, 1, -8992.9169921875, 942.873291015625, 68.1258392333984375, 6.139392852783203125, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 41488), -- 148124 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 287187 - Shattrath Portal Channel) Consortium Arcanist
(@CGUID+32, 148124, 0, 1519, 10523, 0, 0, 0, 0, 1, -8987.453125, 946.4444580078125, 68.12579345703125, 4.60310983657836914, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 41488), -- 148124 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 287187 - Shattrath Portal Channel) Consortium Arcanist
(@CGUID+33, 147741, 0, 1519, 10523, 0, 0, 0, 0, 1, -9005.375, 933.8836669921875, 68.12587738037109375, 4.855130195617675781, 120, 0, 0, 2148, 2680, 0, 0, 0, 0, 41488), -- 147741 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 286709 - Pandaria Portal Channel) Tushui Magister
(@CGUID+34, 147741, 0, 1519, 10523, 0, 0, 0, 0, 1, -9010.357421875, 929.8194580078125, 68.12579345703125, 5.963459968566894531, 120, 0, 0, 2148, 2680, 0, 0, 0, 0, 41488), -- 147741 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: 286709 - Pandaria Portal Channel) Tushui Magister
(@CGUID+35, 149626, 0, 1519, 10523, 0, 0, 0, 0, 1, -9007.9013671875, 873.81768798828125, 129.786529541015625, 5.007258415222167968, 120, 0, 0, 2661, 3191, 0, 0, 0, 0, 41488), -- 149626 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: )
(@CGUID+36, 149616, 0, 1519, 10523, 0, 0, 0, 0, 1, -9010.16015625, 871.453125, 129.7754669189453125, 0.034623757004737854, 120, 0, 0, 1921, 3801, 0, 0, 0, 0, 41488), -- 149616 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: ) Kirin Tor Emissary
(@CGUID+37, 150122, 0, 1519, 10523, 0, 0, 0, 0, 1, -9007.5693359375, 869.54339599609375, 129.7754669189453125, 1.660158634185791015, 120, 0, 0, 1732, 2175, 0, 0, 0, 0, 41488), -- 150122 (Area: Wizard's Sanctum - Difficulty: 0) (Auras: )
(@CGUID+38, 103033, 0, 1519, 10523, 0, 0, 0, 0, 0, -9069.8056640625, 894.493408203125, 67.489898681640625, 2.075398683547973632, 120, 10, 0, 3236, 0, 1, 0, 0, 0, 41488), -- Enchanted Broom (Area: Wizard's Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+39, 103033, 0, 1519, 10523, 0, 0, 0, 0, 0, -9077.2607421875, 869.613037109375, 68.16512298583984375, 4.634737968444824218, 120, 10, 0, 3236, 0, 1, 0, 0, 0, 41488), -- Enchanted Broom (Area: Wizard's Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+40, 103033, 0, 1519, 10523, 0, 0, 0, 0, 0, -9005.8115234375, 942.6842041015625, 67.61115264892578125, 0.139945387840270996, 120, 10, 0, 3236, 0, 1, 0, 0, 0, 41488), -- Enchanted Broom (Area: Wizard's Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+41, 103033, 0, 1519, 10523, 0, 0, 0, 0, 0, -9049.0302734375, 913.6859130859375, 66.36513519287109375, 1.11025857925415039, 120, 10, 0, 3236, 0, 1, 0, 0, 0, 41488), -- Enchanted Broom (Area: Wizard's Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+42, 103033, 0, 1519, 10523, 0, 0, 0, 0, 0, -9018.1396484375, 874.50054931640625, 64.8714752197265625, 5.2625579833984375, 120, 10, 0, 3236, 0, 1, 0, 0, 0, 41488), -- Enchanted Broom (Area: Wizard's Sanctum - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+43, 89174, 0, 1519, 10523, 0, 0, 0, 0, 0, -9023.326171875, 924.61114501953125, 66.307708740234375, 0.223169699311256408, 120, 0, 0, 3663, 4393, 0, 0, 0, 0, 41488), -- Laluu (Area: 10523 - Difficulty: 0) (Auras: 290095 - 290095)
(@CGUID+44, 52408, 0, 1519, 10523, 0, 0, 0, 0, 0, -9052.8505859375, 901.95660400390625, 66.24103546142578125, 1.134060859680175781, 120, 0, 0, 1989, 0, 0, 0, 0, 0, 41488), -- Coridormi (Area: 10523 - Difficulty: 0)
(@CGUID+45, 19007, 530, 3483, 3539, 0, 0, 0, 0, 0, -278.142364501953125, 936.09027099609375, 84.4630584716796875, 5.337642669677734375, 120, 0, 0, 16040, 8520, 0, 0, 0, 0, 41488), -- Gnomeregan Conjuror (Area: 3539 - Difficulty: 0) (Auras: 32783 - 32783)
(@CGUID+46, 19007, 530, 3483, 3539, 0, 0, 0, 0, 0, -272.010406494140625, 926.9375, 84.46307373046875, 2.178596735000610351, 120, 0, 0, 16040, 8520, 0, 0, 0, 0, 41488), -- Gnomeregan Conjuror (Area: 3539 - Difficulty: 0) (Auras: 32783 - 32783)
(@CGUID+47, 19006, 530, 3483, 3539, 0, 0, 0, 0, 0, -225.423614501953125, 926.50518798828125, 84.46307373046875, 0.722913980484008789, 120, 0, 0, 16040, 8520, 0, 0, 0, 0, 41488), -- Silvermoon Magister (Area: 3539 - Difficulty: 0) (Auras: 32783 - 32783)
(@CGUID+48, 19006, 530, 3483, 3539, 0, 0, 0, 0, 0, -217.71875, 934.55035400390625, 84.46307373046875, 4.108852386474609375, 120, 0, 0, 16040, 8520, 0, 0, 0, 0, 41488); -- Silvermoon Magister (Area: 3539 - Difficulty: 0) (Auras: 32783 - 32783)

DELETE FROM `creature_template_addon` WHERE `entry` IN (5498, 149131, 2485, 331, 5497, 147714, 147741, 148796, 155739, 148124, 147785, 149626, 149099, 173545, 52408, 89174);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(5498, 0, 0, 0, 256, 0, 0, 0, 0, '290038'), -- 5498 - Arcane Power
(2485, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 2485
(331, 0, 0, 0, 257, 0, 0, 0, 0, '56384'), -- 331 (Maginor Dumas) - Arcane Momentum
(5497, 0, 0, 0, 257, 0, 0, 0, 0, '56384'), -- 5497 - Arcane Momentum
(147714, 0, 0, 0, 257, 0, 0, 0, 0, '286636'), -- 147714 (Exodar Portal-Keeper) - Exodar Portal Channel
(147741, 0, 0, 0, 257, 0, 0, 0, 0, '286709'), -- 147741 (Tushui Magister) - Pandaria Portal Channel
(149099, 0, 0, 0, 257, 0, 0, 0, 0, '289141'), -- 149099 (Silver Covenant Mage) - Dalaran Portal Channel
(148796, 0, 0, 0, 256, 0, 0, 0, 0, '287413'), -- 148796 (Storm's Wake Tidesage) - Boralus Portal Channel
(155739, 0, 0, 0, 257, 0, 0, 0, 0, '303508'), -- 155739 (Bronze Chronomancer) - [DNT] Caverns of Time Portal Channel
(148124, 0, 0, 0, 257, 0, 0, 0, 0, '287187'), -- 148124 (Consortium Arcanist) - Shattrath Portal Channel
(173545, 0, 0, 0, 257, 0, 0, 0, 0, '339689'), -- 173545 (Ebon Blade Acolyte) - [DNT] DK Channel
(147785, 0, 0, 0, 257, 0, 0, 0, 0, '287193'), -- 147785 (Nar'thalas Mage) - Azsuna Portal Channel
(149626, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 149626 (Vanguard Battlemage)
(52408, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- 52408 (Coridormi)
(89174, 0, 0, 0, 257, 0, 0, 0, 0, '290095'); -- 89174 (Laluu) - 290095

DELETE FROM `creature_template_model` WHERE (`Idx`=0 AND `CreatureID` IN (149131, 5498, 68, 85307, 149124, 149121, 2485, 331, 5497, 148233, 149626, 150122, 149616, 103033)) OR (`Idx`=1 AND `CreatureID` IN (149131, 68, 149124, 148233, 149626, 149616)) OR (`Idx`=2 AND `CreatureID` IN (149131, 68, 149124, 149616)) OR (`Idx`=3 AND `CreatureID` IN (149131, 68, 149616)) OR (`Idx`=4 AND `CreatureID` IN (149131));
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(149131, 4, 90209, 1, 1, 41488), -- 149131
(149131, 3, 90208, 1, 1, 41488), -- 149131
(149131, 2, 90207, 1, 1, 41488), -- 149131
(149131, 1, 90206, 1, 1, 41488), -- 149131
(149131, 0, 90201, 1, 1, 41488), -- 149131
(5498, 0, 19803, 1, 1, 41488), -- 5498
(68, 3, 5446, 1, 1, 41488), -- 68
(68, 2, 99391, 1, 1, 41488), -- 68
(68, 1, 99389, 1, 1, 41488), -- 68
(68, 0, 3167, 1, 1, 41488), -- 68
(85307, 0, 58785, 1, 1, 41488), -- 85307
(149124, 2, 46209, 1, 1, 41488), -- 149124
(149124, 1, 18930, 1, 1, 41488), -- 149124
(149124, 0, 67053, 1, 1, 41488), -- 149124
(149121, 0, 90104, 1, 1, 41488), -- 149121
(2485, 0, 99430, 1, 1, 41488), -- 2485
(331, 0, 1484, 1, 1, 41488), -- 331
(5497, 0, 3292, 1, 0, 41488), -- 5497
(148233, 1, 89931, 1, 1, 41488), -- 148233
(148233, 0, 89930, 1, 1, 41488), -- 148233
(149626, 1, 35498, 1, 1, 41488), -- 149626
(149616, 3, 99420, 1, 1, 41488), -- 149616
(149616, 2, 99419, 1, 1, 41488), -- 149616
(149616, 1, 70992, 1, 1, 41488), -- 149616
(149616, 0, 70425, 1, 1, 41488), -- 149616
(149626, 0, 56857, 1, 1, 41488), -- 149626
(150122, 0, 89885, 1, 1, 41488), -- 150122
(103033, 0, 16910, 1, 1, 41488); -- 103033

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (5498, 149131, 68, 2485, 331, 149626, 149616, 150122));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(5498, 1, 5277, 0, 0, 0, 0, 0, 0, 0, 0), -- 5498
(149131, 1, 55936, 0, 0, 0, 0, 0, 0, 0, 0), -- 149131
(68, 1, 1899, 0, 0, 143, 0, 0, 2551, 0, 0), -- 68
(2485, 1, 5304, 0, 0, 0, 0, 0, 0, 0, 0), -- 2485
(331, 1, 2177, 0, 0, 0, 0, 0, 0, 0, 0), -- 331
(149626, 1, 156993, 0, 0, 0, 0, 0, 0, 0, 0), -- 149626
(149616, 1, 156993, 0, 0, 0, 0, 0, 0, 0, 0), -- 149616
(150122, 1, 156993, 0, 0, 0, 0, 0, 0, 0, 0); -- 150122

DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (5498, 149131, 85307, 149124, 149121, 2485, 331, 5497, 149626, 149616, 150122, 103033));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(5498, 0, 0, 0, 378, 41488),
(149131, 0, 0, 0, 847, 41488),
(85307, 0, 0, 0, 37, 41488),
(149124, 0, 0, 0, 847, 41488),
(149121, 0, 0, 0, 847, 41488),
(2485, 0, 0, 0, 864, 41488),
(331, 0, 0, 0, 864, 41488),
(5497, 0, 0, 0, 864, 41488),
(149626, 0, 0, 0, 178, 41488),
(149616, 0, 0, 0, 347, 41488),
(150122, 0, 0, 0, 37, 41488),
(103033, 0, 0, 0, 633, 41488);

DELETE FROM `gameobject` WHERE `guid`=301170;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+26;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 332224, 0, 1519, 10523, 0, 0, 0, -8984.294921875, 963.44635009765625, 68.6575775146484375, 0.654497027397155761, 0, 0, 0.321438789367675781, 0.946930348873138427, 120, 255, 1, 41488), -- Portal to Caverns of Time (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+1, 323840, 0, 1519, 10523, 0, 0, 0, -9060.939453125, 886.84136962890625, 68.32274627685546875, 2.225293636322021484, 0, 0, 0.896872520446777343, 0.442289173603057861, 120, 255, 1, 41488), -- Portal to Stormshield, Ashran (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+2, 323841, 0, 1519, 10523, 0, 0, 0, -9078.080078125, 909.19677734375, 68.32274627685546875, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 41488), -- Portal to Azsuna (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+3, 323842, 0, 1519, 10523, 0, 0, 0, -9023.583984375, 952.49151611328125, 68.32274627685546875, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 41488), -- Portal to Dalaran, Crystalsong Forest (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+4, 323843, 0, 1519, 10523, 0, 0, 0, -9006.185546875, 965.36517333984375, 68.22771453857421875, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 41488), -- Portal to the Exodar (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+5, 323844, 0, 1519, 10523, 0, 0, 0, -9005.126953125, 928.61181640625, 68.17910003662109375, 2.225293636322021484, 0, 0, 0.896872520446777343, 0.442289173603057861, 120, 255, 1, 41488), -- Portal to Jade Forest (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+6, 323845, 0, 1519, 10523, 0, 0, 0, -9098.748046875, 875.74005126953125, 68.24893951416015625, 0.654497027397155761, 0, 0, 0.321438789367675781, 0.946930348873138427, 120, 255, 1, 41488), -- Portal to Boralus (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+7, 323846, 0, 1519, 10523, 0, 0, 0, -8988.783203125, 942.68927001953125, 68.32274627685546875, 2.225293636322021484, 0, 0, 0.896872520446777343, 0.442289173603057861, 120, 255, 1, 41488), -- Portal to Shattrath (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+8, 311875, 0, 1519, 10523, 0, 0, 0, -8999.150390625, 863.50250244140625, 65.7740631103515625, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 41488), -- Doodad_8SW_Stormwind_MagePortal001 (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+9, 355054, 0, 1519, 10523, 0, 0, 0, -9095.7373046875, 896.4017333984375, 68.8061370849609375, 5.366888046264648437, 0, 0, -0.44228839874267578, 0.896872878074645996, 120, 255, 1, 41488), -- Portal to Oribos (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+10, 210805, 870, 5785, 6516, 0, 0, 0, -311.654510498046875, -1776.6302490234375, 62.67050552368164062, 3.603106260299682617, 0, 0, -0.97349357604980468, 0.228714287281036376, 120, 255, 1, 41488), -- Portal to Stormwind (Area: Paw'don Village - Difficulty: 0)
(@OGUID+11, 334109, 1, 440, 2300, 0, 0, 0, -8153.4931640625, -4816.87353515625, 35.79027938842773437, 2.164465665817260742, 0, 0, 0.883008003234863281, 0.469357937574386596, 120, 255, 1, 41488), -- Portal to Stormwind (Area: Caverns of Time - Difficulty: 0)
(@OGUID+12, 325983, 530, 3557, 3557, 0, 0, 0, -4053.03125, -11577.1982421875, -138.584701538085937, 0.079290181398391723, 0, 0, 0.03963470458984375, 0.999214231967926025, 120, 255, 1, 41488), -- Portal to Stormwind (Area: The Exodar - Difficulty: 0)
(@OGUID+13, 293552, 1643, 8717, 10017, 0, 0, 0, 1132.654541015625, -524.607666015625, 17.53291893005371093, 2.781583309173583984, 0, 0, 0.983842849731445312, 0.179034158587455749, 120, 255, 1, 41488), -- Portal to Stormwind (Area: Sanctum of the Sages - Difficulty: 0)
(@OGUID+14, 353823, 2222, 10565, 10565, 0, 0, 0, -1809.1302490234375, 1537.9896240234375, 5274.5244140625, 3.363039016723632812, 0, 0, -0.99387645721435546, 0.110497035086154937, 120, 255, 1, 41488), -- Portal to Stormwind (Area: Oribos - Difficulty: 0)
(@OGUID+15, 325979, 1220, 7334, 7355, 0, 0, 0, -13.4930553436279296, 6756.6083984375, 53.51351165771484375, 4.958148002624511718, 0, 0, -0.61510467529296875, 0.788445472717285156, 120, 255, 1, 41488), -- Portal to Stormwind (Area: Crumbled Palace - Difficulty: 0)
(@OGUID+16, 334110, 1, 440, 2300, 0, 0, 0, -8153.080078125, -4808.19970703125, 36.62251663208007812, 0, 0, 0, 0, 1, 120, 255, 1, 41488), -- Portal to Orgrimmar (Area: Caverns of Time - Difficulty: 0)
(@OGUID+17, 353822, 2222, 10565, 10565, 0, 0, 0, -1858.720458984375, 1538.267333984375, 5274.7470703125, 0.896871626377105712, 0, 0, 0.433556556701660156, 0.901126325130462646, 120, 255, 1, 41488), -- Portal to Orgrimmar (Area: Oribos - Difficulty: 0)
(@OGUID+18, 195139, 530, 3483, 3539, 0, 0, 0, -274.9913330078125, 931.888916015625, 84.37973785400390625, 0.241280794143676757, 0, 0, 0.120347976684570312, 0.992731750011444091, 120, 255, 1, 41488), -- Portal to Stormwind (Area: 3539 - Difficulty: 0)
(@OGUID+19, 195140, 530, 3483, 3539, 0, 0, 0, -221.973953247070312, 931.44268798828125, 84.37973785400390625, 2.276256561279296875, 0, 0, 0.907850265502929687, 0.419294506311416625, 120, 255, 1, 41488), -- Portal to Orgrimmar (Area: 3539 - Difficulty: 0)
(@OGUID+20, 105174, 0, 1519, 5154, 0, 0, 0, -9004.2861328125, 880.56427001953125, 149.7233428955078125, 5.210615158081054687, 0, 0, -0.51094627380371093, 0.859612643718719482, 120, 255, 1, 41488), -- Chest of Containment Coffers (Area: 5154 - Difficulty: 0)
(@OGUID+21, 105174, 0, 1519, 5154, 0, 0, 0, -9003.1943359375, 880.15277099609375, 149.7533721923828125, 4.215656280517578125, 0, 0, -0.85923099517822265, 0.511587798595428466, 120, 255, 1, 41488), -- Chest of Containment Coffers (Area: 5154 - Difficulty: 0)
(@OGUID+22, 105174, 0, 1519, 5154, 0, 0, 0, -9003.388671875, 880.890625, 149.7532196044921875, 4.256138801574707031, 0, 0, -0.84870052337646484, 0.528873741626739501, 120, 255, 1, 41488), -- Chest of Containment Coffers (Area: 5154 - Difficulty: 0)
(@OGUID+23, 105174, 0, 1519, 10523, 0, 0, 0, -9002.3994140625, 880.33856201171875, 149.753875732421875, 3.647741317749023437, 0, 0, -0.96814727783203125, 0.250381410121917724, 120, 255, 1, 41793), -- Chest of Containment Coffers (Area: Wizard's Sanctum - Difficulty: 0)
(@OGUID+24, 105175, 0, 1519, 5154, 0, 0, 0, -8997.283203125, 875.3819580078125, 150.0748443603515625, 3.766265869140625, 0, 0, -0.95161819458007812, 0.307282954454421997, 120, 255, 1, 41488), -- Cantation of Manifestation (Area: 5154 - Difficulty: 0)
(@OGUID+25, 105175, 0, 1519, 5154, 0, 0, 0, -8997.59765625, 875.94964599609375, 150.0814971923828125, 2.72271275520324707, 0, 0, 0.978147506713867187, 0.207912087440490722, 120, 255, 1, 41488), -- Cantation of Manifestation (Area: 5154 - Difficulty: 0)
(@OGUID+26, 105175, 0, 1519, 5154, 0, 0, 0, -8996.716796875, 875.5382080078125, 150.0640411376953125, 4.172649860382080078, 0, 0, -0.87003231048583984, 0.492994695901870727, 120, 255, 1, 41488); -- Cantation of Manifestation (Area: 5154 - Difficulty: 0)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+9;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to Caverns of Time
(@OGUID+1, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to Stormshield, Ashran
(@OGUID+2, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to Azsuna
(@OGUID+3, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to Dalaran, Crystalsong Forest
(@OGUID+4, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to the Exodar
(@OGUID+5, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to Jade Forest
(@OGUID+6, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to Boralus
(@OGUID+7, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503), -- Portal to Shattrath
(@OGUID+8, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 0), -- Doodad_8SW_Stormwind_MagePortal001
(@OGUID+9, 0, 0, -0.44228863716125488, 0.896872758865356445, 0, 3503); -- Portal to Oribos

DELETE FROM `gameobject_template` WHERE `entry` IN (355054, 325979, 353823, 325978, 334110);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(355054, 22, 65524, 'Portal to Oribos', '', '', '', 1, 329132, -1, 0, 0, 0, 85101, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 807, 41488), -- Portal to Oribos
(325979, 22, 4396, 'Portal to Stormwind', '', '', '', 1, 17334, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 864, 41488), -- 325979
(353823, 22, 66650, 'Portal to Stormwind', '', '', '', 1, 332489, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 783, 41488), -- 353823
(325978, 22, 4395, 'Portal to Orgrimmar', '', '', '', 1, 17609, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 866, 41488), -- 325978
(334110, 22, 4395, 'Portal to Orgrimmar', '', '', '', 1, 345469, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 866, 41488); -- 334110

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (353823, 353822, 364419, 357095, 369893, 281609, 325983, 334110, 334109, 335930, 355054, 323840, 332224);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(353823, 1732, 32, 0, 3503), -- Portal to Stormwind
(353822, 1735, 32, 0, 3503), -- Portal to Orgrimmar
(364419, 0, 32816, 0, 12224), -- Gate to Bastion
(357095, 0, 32, 0, 6132), -- Shadowlands Covenant Map
(369893, 0, 4, 0, 0), -- Urgent Missive
(281609, 0, 1048608, 0, 0), -- The Maiden's Virtue
(325983, 1732, 0, 0, 0), -- Portal to Stormwind
(334110, 1735, 0, 0, 0), -- Portal to Orgrimmar
(334109, 1732, 0, 0, 0), -- Portal to Stormwind
(335930, 114, 0, 0, 0), -- Picnic Basket (scale x0.75)
(355054, 1732, 0, 0, 3503), -- Portal to Oribos
(323840, 1732, 33554432, 0, 0), -- Portal to Stormshield, Ashran
(332224, 1732, 33554432, 0, 0); -- Portal to Caverns of Time

DELETE FROM `gossip_menu` WHERE (`TextId`=37253 AND `MenuId`=23796) OR (`TextId`=37250 AND `MenuId`=23795) OR (`TextId`=37367 AND `MenuId`=23838) OR (`TextId`=539 AND `MenuId`=13920) OR (`TextId`=539 AND `MenuId`=14099);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(23796, 37253, 41488), -- 149626 Vanguard Battlemage
(23795, 37250, 41488), -- 149616 Kirin Tor Emissary
(13920, 539, 41488), -- 331 (Maginor Dumas)
(23838, 37367, 41488), -- 150122 Honor Hold Mage
(14099, 539, 41793); -- 5497 (Jennea Cannon)

DELETE FROM `gossip_menu_option` WHERE (`OptionIndex`=0 AND `MenuId` IN (23838));
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(23838, 0, 0, 'I must report to the Dark Portal.', 169448, 41488);

DELETE FROM `npc_text` WHERE `ID`=37253;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(37253, 1, 0, 0, 0, 0, 0, 0, 0, 168995, 0, 0, 0, 0, 0, 0, 0, 41793); -- 37253

DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (222695,228326,332475,332487,311749,225748,121850,121857,110134,33690,171253,303510,53140,329132,280222,130702,296901,123071,131603,347295)) OR (`EffectIndex`=4 AND `ID`=343980) OR (`EffectIndex`=1 AND `ID`=245992);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(222695, 0, 1220, -828.719970703125, 4371.77978515625, 738.6400146484375, 41488), -- Spell: 222695 (Dalaran Hearthstone) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(228326, 0, 0, -11099.2998046875, -2211.6298828125, 757.83001708984375, 41488), -- Spell: 228326 (Teleport) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(343980, 4, 2222, -1834.050048828125, 1541.9100341796875, 5274.16015625, 41488), -- Spell: 343980 (Frozen in Place) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(332475, 0, 1, 1445.2099609375, -4499.56005859375, 18.30999946594238281, 41488), -- Spell: 332475 (Oribos Teleport to Orgrimmar) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(332487, 0, 0, -9041.6103515625, 917.32000732421875, 66.69000244140625, 41488), -- Spell: 332487 (Oribos Teleport to Stormwind) Efffect: 15 (SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL)
(311749, 0, 0, 1111.0799560546875, -1790.469970703125, 61.45000076293945312, 41488), -- Spell: 311749 (Hearth to Uther's Tomb) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(245992, 1, 0, -9041, 917.65997314453125, 66.69000244140625, 41488), -- Spell: 245992 (Portal: Stormwind) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(225748, 0, 1116, 3725.340087890625, -4047.9599609375, 44.09000015258789062, 41488), -- Spell: 225748 (Teleport to Stormshield) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(121850, 0, 530, -4031.239990234375, -11569.599609375, -138.298995971679687, 41488), -- Spell: 121850 (Portal: Exodar) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(121857, 0, 0, -9041, 917.65997314453125, 66.69000244140625, 41488), -- Spell: 121857 (Portal: Stormwind) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(110134, 0, 938, 3731.530029296875, -398.63299560546875, 110.9359970092773437, 41488), -- Spell: 110134 (Time Travel) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(33690, 0, 530, -1824.3199462890625, 5417.22998046875, -12.4300003051757812, 41488), -- Spell: 33690 (Teleport: Shattrath) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(171253, 0, 1159, 1936.9000244140625, 341.350006103515625, 90.279998779296875, 41488), -- Spell: 171253 (Garrison Hearthstone) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(303510, 0, 1, -8164.7998046875, -4768.5, 34.29999923706054687, 41488), -- Spell: 303510 (Portal to Caverns of Time) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(53140, 0, 571, 5807.75, 588.3499755859375, 661.510009765625, 41488), -- Spell: 53140 (Teleport: Dalaran - Northrend) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(329132, 0, 2222, -1834.18994140625, 1542.469970703125, 5274.16015625, 41488), -- Spell: 329132 (Portal to Oribos) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(280222, 0, 1643, 1130.3199462890625, -533.34002685546875, 17.53000068664550781, 41488), -- Spell: 280222 (Teleport to Boralus Harbor) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(130702, 0, 870, -307.160003662109375, -1772.8900146484375, 62.31999969482421875, 41488), -- Spell: 130702 (Portal: Paw'don Village) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(296901, 0, 1220, -11.109999656677246, 6746.18994140625, 55.5800018310546875, 41488), -- Spell: 296901 (Portal to Azsuna) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(123071, 0, 0, -9041, 917.65997314453125, 66.69000244140625, 41488), -- Spell: 123071 (Portal: Stormwind) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(131603, 0, 870, -671.708984375, -1480.72998046875, 130.1999969482421875, 41488), -- Spell: 131603 (Gunship Portal Click) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(347295, 0, 870, -667.8900146484375, -1482.25, 130.1999969482421875, 41488); -- Spell: 347295 (Teleport Player) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Pathing for Summoned Guardian Entry: 149121 'TDB FORMAT' 
SET @NPC := 1050448;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawnDifficulties`=0,`MovementType`=2,`position_x`=-9033.98,`position_y`=911.62683,`position_z`=66.36547 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-9033.98,911.62683,66.36547,0,0,0,0,100,0),
(@PATH,2,-9024.955,928.29865,66.36513,0,0,0,0,100,0),
(@PATH,3,-9021.234,930.6823,67.67302,0,0,0,0,100,0),
(@PATH,4,-9002.014,944.3748,67.58477,0,0,0,0,100,0),
(@PATH,5,-8995.31,949.3299,67.65515,0,0,0,0,100,0),
(@PATH,6,-8989.04,955.7639,67.71188,0,10000,0,0,100,0),
(@PATH,7,-9003.446,943.16144,67.58858,0,0,0,0,100,0),
(@PATH,8,-9007.967,938.8281,67.66206,0,0,0,0,100,0),
(@PATH,9,-9018.306,930.42365,67.70766,0,0,0,0,100,0),
(@PATH,10,-9022.879,927.0434,66.36513,0,0,0,0,100,0),
(@PATH,11,-9032.703,916.80383,66.38743,0,0,0,0,100,0),
(@PATH,12,-9035.311,911.94617,66.36513,0,0,0,0,100,0),
(@PATH,13,-9026.66,901.0781,65.05767,0,0,0,0,100,0),
(@PATH,14,-9017.679,890.72394,64.98259,0,0,0,0,100,0),
(@PATH,15,-9003.127,874.8958,64.9745,0,0,0,0,100,0),
(@PATH,16,-9001.582,875.80383,64.9745,0,0,0,0,100,0),
(@PATH,17,-9001.582,875.80383,64.9745,0,10000,0,0,100,0),
(@PATH,18,-9010.266,879.375,65.04902,0,0,0,0,100,0),
(@PATH,19,-9013.076,883.4184,65.11821,0,0,0,0,100,0),
(@PATH,20,-9017.929,889.72394,64.99534,0,0,0,0,100,0),
(@PATH,21,-9024.042,893.0052,65.04807,0,0,0,0,100,0),
(@PATH,22,-9031.618,892.3472,64.96365,0,6000,0,0,100,0),
(@PATH,23,-9028.044,899.99023,65.04553,0,0,0,0,100,0),
(@PATH,24,-9030.424,906.1059,66.36513,0,0,0,0,100,0);

UPDATE `gameobject_template_addon` SET `AIAnimKitID`=8021 WHERE `entry`=355054; -- Portal to Oribos
UPDATE `gameobject_template_addon` SET `flags`=33554432 WHERE `entry`=323846; -- Portal to Shattrath
UPDATE `gameobject_template_addon` SET `flags`=33554432 WHERE `entry`=323845; -- Portal to Boralus
UPDATE `gameobject_template_addon` SET `flags`=33554432 WHERE `entry`=323844; -- Portal to Jade Forest
UPDATE `gameobject_template_addon` SET `flags`=33554432 WHERE `entry`=323843; -- Portal to the Exodar
UPDATE `gameobject_template_addon` SET `flags`=33554432 WHERE `entry`=323842; -- Portal to Dalaran, Crystalsong Forest
UPDATE `gameobject_template_addon` SET `flags`=33554432 WHERE `entry`=323841; -- Portal to Azsuna

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19007; -- 19007 (Gnomeregan Conjuror) - 32783
UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=19006; -- 19006 (Silvermoon Magister) - 32783

UPDATE `gameobject_template` SET `ContentTuningId`=37, `VerifiedBuild`=41488 WHERE `entry`=195140; -- Portal to Orgrimmar
UPDATE `gameobject_template` SET `ContentTuningId`=37, `VerifiedBuild`=41488 WHERE `entry`=195139; -- Portal to Stormwind

UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=41488 WHERE `DisplayID`=1765;

UPDATE `creature_equip_template` SET `ItemID1`=1905, `ItemID2`=0 WHERE (`CreatureID`=16831 AND `ID`=2); -- Nethergarde Infantry
UPDATE `creature_equip_template` SET `ItemID1`=1903 WHERE (`CreatureID`=19444 AND `ID`=1); -- Peasant Worker
UPDATE `creature_equip_template` SET `ItemID1`=3361, `ItemID2`=0 WHERE (`CreatureID`=16831 AND `ID`=1); -- Nethergarde Infantry
UPDATE `creature_equip_template` SET `ItemID1`=2715 WHERE (`CreatureID`=1976 AND `ID`=1); -- Stormwind City Patroller

UPDATE `creature_template` SET `gossip_menu_id`=23796 WHERE `entry` =149626; -- Vanguard Battlemage 
UPDATE `creature_template` SET `gossip_menu_id`=23795 WHERE `entry`=149616; -- Kirin Tor Emissary
UPDATE `creature_template` SET `gossip_menu_id`=23838, `npcflag`=1 WHERE `entry`=150122; -- Honor Hold Mage
UPDATE `creature_template` SET `gossip_menu_id`=14146 WHERE `entry`=89174; -- Laluu
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=149124; -- Arcane Golem
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=2485; -- Larimaine Purdue
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=5498; -- Elsharin
UPDATE `creature_template` SET `minlevel`=60 WHERE `entry`=149131; -- Apprentice Mage
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=19007; -- Gnomeregan Conjuror
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30 WHERE `entry`=19006; -- Silvermoon Magister
UPDATE `creature_template` SET `gossip_menu_id`=14099, `minlevel`=60 WHERE `entry`=5497; -- Jennea Cannon
UPDATE `creature_template` SET `gossip_menu_id`=13920, `minlevel`=60 WHERE `entry`=331; -- Maginor 
UPDATE `gossip_menu_option` SET `OptionType`=1, `OptionNpcFlag`=1 WHERE (`MenuId`=23838 AND `OptionIndex`=0);

-- Kirin Tor Magus smart ai
SET @ENTRY := 148233;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 174827, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On unit respawn - Self: Cast spell 174827 on Self');
