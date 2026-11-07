SET @CGUID := 6003035;
SET @OGUID := 6002443;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+558;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5436.05908203125, 10771.2001953125, 20.19542503356933593, 2.050997734069824218, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+1, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5474.5966796875, 10825.3662109375, 17.16739845275878906, 3.077997207641601562, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+2, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5467.12548828125, 10779.25, 19.18004989624023437, 3.461336851119995117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+3, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5484.31787109375, 10829.5478515625, 17.16739845275878906, 4.407246589660644531, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+4, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5483.52490234375, 10788.3447265625, 17.16739845275878906, 4.985115528106689453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+5, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5449.85595703125, 10751.2001953125, 20.19640541076660156, 2.849298954010009765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+6, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5441.6728515625, 10873.1806640625, 20.4089813232421875, 5.512402057647705078, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+7, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5432.54345703125, 10779.947265625, 20.11156272888183593, 5.0386810302734375, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+8, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5468.85791015625, 10813.3994140625, 17.25173759460449218, 4.093652248382568359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+9, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5441.666015625, 10864.5830078125, 20.90224456787109375, 5.91237497329711914, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+10, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5467.2763671875, 10850.654296875, 20.25787925720214843, 4.527997016906738281, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+11, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5466.91845703125, 10808.6298828125, 17.25347328186035156, 1.006228566169738769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+12, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5457.65283203125, 10856.1728515625, 20.11155891418457031, 5.159465789794921875, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+13, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5448.3505859375, 10758.78515625, 20.19640541076660156, 4.524558544158935546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+14, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5448.2197265625, 10845.4765625, 34.09303665161132812, 5.307834625244140625, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+15, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5440.78076171875, 10777.7490234375, 20.11155891418457031, 2.973696708679199218, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+16, 122398, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5447.37353515625, 10754.1123046875, 20.19640541076660156, 0.131273597478866577, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sapped Voidlord (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245753 - Override Energy Bar Color)
(@CGUID+17, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5481.271484375, 10792.765625, 17.16739845275878906, 4.923216819763183593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+18, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5467.14990234375, 10779.25390625, 19.17272567749023437, 3.285389900207519531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+19, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5464.494140625, 10859.185546875, 20.13431358337402343, 1.559043526649475097, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+20, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5482.81640625, 10793.91015625, 17.16739845275878906, 4.901750087738037109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5470.61474609375, 10809.4658203125, 17.26447296142578125, 2.837985992431640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+22, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5457.943359375, 10905.9111328125, 11.23598289489746093, 4.634194374084472656, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+23, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5497.7802734375, 10788.732421875, 17.25, 0.757463753223419189, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+24, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5479.35595703125, 10891.5009765625, 17.74333763122558593, 4.933747291564941406, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+25, 122398, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5500.8359375, 10879.1337890625, 20.19488525390625, 3.937280178070068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sapped Voidlord (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245753 - Override Energy Bar Color)
(@CGUID+26, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5523.91796875, 10797.34375, 17.16863059997558593, 1.326326251029968261, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic))
(@CGUID+27, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5493.1328125, 10723.8056640625, 21.25807571411132812, 2.050396442413330078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+28, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5507.47314453125, 10815.1318359375, 17.250732421875, 4.941376209259033203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+29, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5512.4453125, 10783.5576171875, 17.24610710144042968, 1.747417211532592773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+30, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5476.6552734375, 10872.0625, 20.406890869140625, 5.881014823913574218, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+31, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5495.57373046875, 10725.17578125, 20.71478652954101562, 3.766457557678222656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 249133 - Famished Broken Cannibalize Ooze Cosmetic)
(@CGUID+32, 122398, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5498.2978515625, 10910.232421875, 13.92234134674072265, 0.131273597478866577, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sapped Voidlord (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245753 - Override Energy Bar Color)
(@CGUID+33, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5482.904296875, 10728.3701171875, 21.02389717102050781, 4.390638351440429687, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5471.4853515625, 10897.873046875, 27.74837875366210937, 0.90803605318069458, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+35, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5493.0693359375, 10875.908203125, 20.74521636962890625, 0.372119754552841186, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+36, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5502.5439453125, 10872.8837890625, 40.27688980102539062, 4.464483261108398437, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+37, 122313, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5510.3427734375, 10800.2236328125, 21.61537933349609375, 1.309549808502197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Zuraal the Ascended (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic), 246913 - Void Phased)
(@CGUID+38, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5522.22607421875, 10793.3056640625, 17.16436767578125, 1.074313759803771972, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic))
(@CGUID+39, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5491.2724609375, 10722.7548828125, 21.53644943237304687, 0.066711120307445526, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 249133 - Famished Broken Cannibalize Ooze Cosmetic)
(@CGUID+40, 122398, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5469.6005859375, 10734.15625, 20.19640541076660156, 1.451270461082458496, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sapped Voidlord (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245753 - Override Energy Bar Color)
(@CGUID+41, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5473.9375, 10732.8974609375, 20.22517013549804687, 3.307774305343627929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+42, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5523.775390625, 10793.091796875, 17.16683197021484375, 1.568609118461608886, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic))
(@CGUID+43, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5503.8916015625, 10872.9287109375, 20.19488525390625, 1.865605592727661132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+44, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5464.2880859375, 10736.71875, 20.19640541076660156, 5.027326583862304687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+45, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5463.92138671875, 10748.21484375, 40.23978042602539062, 4.942824363708496093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5522.38623046875, 10810.732421875, 17.260406494140625, 3.951421499252319335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+47, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5544.37060546875, 10720.5029296875, 21.74585723876953125, 2.65234231948852539, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+48, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5538.21044921875, 10886.404296875, 20.11154937744140625, 4.200395107269287109, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+49, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5541.9892578125, 10761.3818359375, 18.05603790283203125, 5.885089397430419921, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+50, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5643.03564453125, 10679.4814453125, 35.64670562744140625, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+51, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5586.46435546875, 10819.6572265625, 20.11208534240722656, 5.216933727264404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic)) (possible waypoints or random movement)
(@CGUID+52, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5647.7490234375, 10683.689453125, 33.20461273193359375, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+53, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5592.60302734375, 10888.3486328125, 32.78468704223632812, 2.755517005920410156, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+54, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5496.18212890625, 10913.875, 13.67601871490478515, 5.064742088317871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+55, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5611.9697265625, 10821.697265625, 20.11158561706542968, 5.993669033050537109, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+56, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5492.2001953125, 10925.5244140625, 27.06912422180175781, 1.887616515159606933, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+57, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5578.13037109375, 10905.912109375, 10.00018596649169921, 2.285674571990966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+58, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5585.5849609375, 10755.2421875, 20.19845390319824218, 4.291010379791259765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 249133 - Famished Broken Cannibalize Ooze Cosmetic)
(@CGUID+59, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5554.56689453125, 10754.68359375, 36.44212722778320312, 0.752711594104766845, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+60, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5544.775390625, 10864.875, 20.7352294921875, 5.661303520202636718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+61, 122560, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5532.75439453125, 10719.220703125, 20.49324989318847656, 1.085383534431457519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic))
(@CGUID+62, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5528.80322265625, 10887.89453125, 19.93746757507324218, 3.717681407928466796, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+63, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5547.09375, 10853.6474609375, 20.31756973266601562, 0.429649919271469116, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+64, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5542.18701171875, 10770.1298828125, 17.21176910400390625, 2.103758573532104492, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+65, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5588.66259765625, 10819.6044921875, 20.11155891418457031, 5.151608943939208984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic)) (possible waypoints or random movement)
(@CGUID+66, 125855, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5561.4111328125, 10902.7470703125, 27.6627960205078125, 3.744454860687255859, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+67, 122398, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5566.5068359375, 10731.765625, 20.38776016235351562, 5.719316482543945312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sapped Voidlord (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245753 - Override Energy Bar Color)
(@CGUID+68, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5575.29150390625, 10727.66015625, 20.59967041015625, 2.389254331588745117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+69, 122398, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5551.4296875, 10859.8095703125, 20.23494529724121093, 3.120896577835083007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sapped Voidlord (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245753 - Override Energy Bar Color)
(@CGUID+70, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5577.40966796875, 10765.10546875, 20.11330223083496093, 4.29894113540649414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic)) (possible waypoints or random movement)
(@CGUID+71, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5527.5078125, 10894.857421875, 16.81202316284179687, 1.552403807640075683, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+72, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5583.51318359375, 10752.4345703125, 20.216461181640625, 4.291010379791259765, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+73, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5566.3291015625, 10902.013671875, 12.23963356018066406, 3.489342212677001953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+74, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5644.6083984375, 10675.8408203125, 39.29032135009765625, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+75, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5644.4833984375, 10682.65625, 42.176361083984375, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+76, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5582.2744140625, 10750.8525390625, 20.22183799743652343, 1.24800419807434082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 249133 - Famished Broken Cannibalize Ooze Cosmetic)
(@CGUID+77, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5586.3125, 10852.0732421875, 20.48796653747558593, 3.160720348358154296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+78, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5531.708984375, 10906.8740234375, 15.02075481414794921, 6.167014122009277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+79, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5602.16796875, 10887.3740234375, 13.39928245544433593, 2.662415504455566406, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+80, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5577.9443359375, 10889.060546875, 16.38891983032226562, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+81, 122560, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5535.77587890625, 10721.2744140625, 20.78404426574707031, 1.085383534431457519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic))
(@CGUID+82, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5581.5849609375, 10853.34375, 20.31042671203613281, 5.999904632568359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+83, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5599.65625, 10840.3837890625, 21.47185134887695312, 3.733407020568847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+84, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5575.8876953125, 10761.6328125, 20.11128425598144531, 4.302718162536621093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic)) (possible waypoints or random movement)
(@CGUID+85, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5590.54833984375, 10814.3095703125, 20.1118011474609375, 5.280153751373291015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic)) (possible waypoints or random movement)
(@CGUID+86, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5570.3330078125, 10904.8193359375, 10.76241397857666015, 0.787324905395507812, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+87, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5565.900390625, 10724.6943359375, 21.38036346435546875, 1.454069972038269042, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+88, 122398, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5593.77001953125, 10836.3994140625, 20.3920440673828125, 2.779870271682739257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sapped Voidlord (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245753 - Override Energy Bar Color)
(@CGUID+89, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5502.29150390625, 10913.1513671875, 13.42431354522705078, 4.584032535552978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+90, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5590.458984375, 10746.2099609375, 20.99286270141601562, 2.367243766784667968, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5531.78662109375, 10907.140625, 14.58330631256103515, 5.856106758117675781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+92, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5570.73388671875, 10895.767578125, 14.3990631103515625, 3.730511426925659179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5527.4775390625, 10906.2822265625, 15.29391670227050781, 5.526784896850585937, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+94, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5589.59033203125, 10833.4033203125, 20.19521903991699218, 0.70819634199142456, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+95, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5534.6279296875, 10905.626953125, 16.10025978088378906, 5.740109920501708984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+96, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5504.880859375, 10919.75390625, 11.78621768951416015, 5.066416740417480468, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+97, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5645.4833984375, 10674.9580078125, 29.21300315856933593, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+98, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5573.73291015625, 10584.771484375, 43.17229080200195312, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+99, 123767, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5570.30126953125, 10590.5712890625, 5.795360565185546875, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Event Portal Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+100, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5651.8427734375, 10678.0595703125, 31.74680709838867187, 5.210605144500732421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+101, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5761.68603515625, 10698.482421875, 28.189117431640625, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+102, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5570.95068359375, 10595.4228515625, 34.5423736572265625, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+103, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5762.1337890625, 10692.1064453125, 30.18537521362304687, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+104, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5573.78125, 10592.794921875, 46.38359451293945312, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+105, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5759.51318359375, 10697.4140625, 33.53005599975585937, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+106, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5651.0712890625, 10682.783203125, 36.87661361694335937, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+107, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5565.2802734375, 10593.109375, 36.6891021728515625, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+108, 123767, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5647.6640625, 10678.3876953125, 5.024188995361328125, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Event Portal Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+109, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5759.5390625, 10691.1474609375, 31.647796630859375, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+110, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5569.65185546875, 10586.322265625, 32.13634109497070312, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+111, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5650.4521484375, 10674.408203125, 34.4434967041015625, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+112, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5574.30712890625, 10588.3701171875, 37.83183670043945312, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+113, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5758.85498046875, 10694.455078125, 36.55643844604492187, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+114, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5568.85400390625, 10596.6494140625, 44.42821121215820312, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+115, 123767, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5761.1806640625, 10694.9169921875, 5.347890377044677734, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Event Portal Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+116, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5647.6640625, 10678.3876953125, 30.63877105712890625, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+117, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5565.1162109375, 10588.5595703125, 40.28465652465820312, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+118, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5573.79443359375, 10590.6318359375, 29.48134803771972656, 5.790679454803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+119, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5761.1806640625, 10694.9169921875, 24.3736572265625, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+120, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5764.572265625, 10695.4208984375, 25.32891082763671875, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+121, 122056, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6140.166015625, 10391.4345703125, 19.86436653137207031, 3.054518938064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Viceroy Nezhar (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245029 - Override Energy Bar Color, 246913 - Void Phased)
(@CGUID+122, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5763.734375, 10692.916015625, 34.83604812622070312, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+123, 122832, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6142.80908203125, 10388.21875, 19.87155532836914062, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Center Point (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+124, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5763.52001953125, 10696.6025390625, 38.07613754272460937, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+125, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5559.375, 10665.3173828125, 6.090862274169921875, 2.149982452392578125, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+126, 122410, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5600.306640625, 10575.3798828125, 38.92660903930664062, 4.891654491424560546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+127, 122410, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5600.42431640625, 10573.869140625, 41.071624755859375, 2.880080223083496093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+128, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5616.3740234375, 10682.5205078125, 5.296487808227539062, 4.938243389129638671, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+129, 122403, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 1, 5603.1572265625, 10693.9658203125, 5.866319656372070312, 3.720093011856079101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+130, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5590.923828125, 10651.908203125, 6.184028148651123046, 1.174715518951416015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+131, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5594.884765625, 10657.5888671875, 5.767601966857910156, 4.849805355072021484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+132, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5608.70166015625, 10695.8984375, 5.914886474609375, 1.727319598197937011, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+133, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5643.34375, 10844.23828125, 15.76006031036376953, 5.016618728637695312, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic), 245746 - Corrupting Touch)
(@CGUID+134, 122421, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5588.40380859375, 10655.7392578125, 6.310764312744140625, 5.86324310302734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Umbral War-Adept (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+135, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5591.9384765625, 10657.8251953125, 5.967014312744140625, 4.363107681274414062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+136, 122322, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5643.00341796875, 10852.984375, 14.34267139434814453, 5.016618728637695312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Famished Broken (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic))
(@CGUID+137, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5636.0166015625, 10846.8349609375, 16.97347831726074218, 5.016618728637695312, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244087 - Physical Realm (Cosmetic), 245746 - Corrupting Touch)
(@CGUID+138, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5600.6416015625, 10692.9345703125, 5.7760467529296875, 5.992110252380371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+139, 126211, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5634.6796875, 10683.546875, 6.22564554214477539, 1.200306653976440429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+140, 122410, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5685.1982421875, 10580.3955078125, 16.87164115905761718, 3.83761143684387207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+141, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5611.46142578125, 10634.5634765625, 5.391779422760009765, 3.980808973312377929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5875.05126953125, 10467.55078125, 37.81123733520507812, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+143, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5870.91650390625, 10463.6884765625, 34.19254684448242187, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+144, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5695.80908203125, 10772.70703125, 41.39465713500976562, 0.492151737213134765, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+145, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5867.35498046875, 10460.423828125, 35.71686935424804687, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+146, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5978.57275390625, 10642.021484375, 36.96878433227539062, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+147, 125493, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5695.42724609375, 10807.2197265625, 18.40069580078125, 0.657386302947998046, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+148, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5611.89013671875, 10633.3115234375, 5.388002872467041015, 5.212298870086669921, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+149, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5624.40087890625, 10656.205078125, 4.907336235046386718, 4.016971111297607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+150, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5867.822265625, 10467.490234375, 43.34559249877929687, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+151, 126211, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5698.40185546875, 10819.6923828125, 10.58808803558349609, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+152, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5872.97900390625, 10469.732421875, 45.7306671142578125, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+153, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5866.611328125, 10463.783203125, 48.17124557495117187, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+154, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5631.63720703125, 10654.728515625, 4.933362483978271484, 1.523473501205444335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+155, 123767, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5870.91650390625, 10463.6884765625, 8.770592689514160156, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Event Portal Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+156, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5975.6884765625, 10640.4736328125, 44.10972976684570312, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+157, 127008, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5700.97216796875, 10763.1650390625, 29.29532241821289062, 1.297518372535705566, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Assault Door Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+158, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5557.16064453125, 10607.3349609375, 7.184192657470703125, 3.800094842910766601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+159, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5870.9130859375, 10459.810546875, 49.87741851806640625, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+160, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5632.765625, 10646.6943359375, 5.022923946380615234, 4.904652118682861328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+161, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5706.44970703125, 10826.220703125, 9.579895973205566406, 5.259006977081298828, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+162, 122403, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 1, 5678.47900390625, 10695.9609375, 5.347877025604248046, 5.099031448364257812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+163, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5705.859375, 10780.806640625, 19.05904006958007812, 4.764156341552734375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+164, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5693.0224609375, 10727.9599609375, 19.07623291015625, 2.176382064819335937, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+165, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5978.27978515625, 10635.3994140625, 53.98371124267578125, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+166, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5874.29345703125, 10463.5830078125, 52.18624114990234375, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+167, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5601.92236328125, 10624.6005859375, 5.429785728454589843, 0.841909527778625488, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+168, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5631.89599609375, 10639.259765625, 5.005502700805664062, 2.505320072174072265, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+169, 122410, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5751.625, 10609.8359375, 78.96917724609375, 1.226174354553222656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+170, 125493, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5683.2890625, 10664.5478515625, 7.56194305419921875, 2.73990941047668457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+171, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5621.52587890625, 10622.443359375, 5.487290382385253906, 6.066493988037109375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+172, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5985.86279296875, 10641.1708984375, 41.51535797119140625, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+173, 122410, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5816.31005859375, 10676.9970703125, 8.723784446716308593, 3.138390541076660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+174, 125780, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5728.1025390625, 10852.9345703125, 15.53864669799804687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Generic Bunny (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+175, 125493, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5676.91796875, 10672.767578125, 8.621423721313476562, 4.68903350830078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+176, 125493, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5734.5185546875, 10769.7431640625, 6.394937992095947265, 5.80511474609375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+177, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5985.49462890625, 10636.5517578125, 56.76542282104492187, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+178, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5984.29150390625, 10633.6181640625, 42.24612045288085937, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+179, 123767, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5982.6416015625, 10637.7177734375, 12.64009284973144531, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Event Portal Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+180, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5982.0078125, 10633.2392578125, 49.85466384887695312, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+181, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5876.07666015625, 10457.2451171875, 40.31922149658203125, 5.138988018035888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+182, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5695.8037109375, 10666.66015625, 7.193976402282714843, 4.551321029663085937, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+183, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5553.923828125, 10604.201171875, 7.184192657470703125, 1.86273193359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+184, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5700.36767578125, 10663.9736328125, 6.8434600830078125, 3.61409926414489746, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+185, 125493, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5745.5625, 10825.4091796875, 8.351970672607421875, 2.164928197860717773, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+186, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5981.3759765625, 10637.6025390625, 34.72852325439453125, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+187, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5982.8447265625, 10641.5986328125, 46.69135284423828125, 5.188050270080566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+188, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5681.0087890625, 10693.2783203125, 5.359211921691894531, 2.120209455490112304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+189, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5710.408203125, 10665.6455078125, 6.20908355712890625, 5.079286098480224609, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+190, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5692.248046875, 10641.8525390625, 7.455675125122070312, 3.180673599243164062, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+191, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6018.15087890625, 10588.7568359375, 40.62226486206054687, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+192, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5666.01806640625, 10620.7626953125, 6.235362052917480468, 1.704512596130371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+193, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5690.033203125, 10639.5302734375, 7.482344627380371093, 5.590656757354736328, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+194, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5684.9228515625, 10634.44140625, 7.6336212158203125, 0.939776003360748291, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+195, 122407, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5661.7412109375, 10619.6845703125, 6.984691619873046875, 1.704512596130371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Warp Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+196, 126211, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5761.751953125, 10801.552734375, 13.71005916595458984, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+197, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5761.28564453125, 10793.2939453125, 5.634589672088623046, 0.93904656171798706, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+198, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5715.3994140625, 10660.048828125, 5.995448589324951171, 0.575484812259674072, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+199, 126211, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5766.705078125, 10797.3173828125, 16.324066162109375, 0.167637467384338378, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+200, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5699.1083984375, 10642.1494140625, 7.433079719543457031, 2.644693851470947265, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+201, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5764.06298828125, 10800.0546875, 5.9408416748046875, 4.617287158966064453, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+202, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6015.89404296875, 10580.9912109375, 48.7225341796875, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+203, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6023.953125, 10578.171875, 53.76139450073242187, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+204, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6023.38525390625, 10580.28125, 65.44225311279296875, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+205, 126211, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5769.0380859375, 10795.640625, 6.945275306701660156, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+206, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6018.44775390625, 10573.671875, 59.15406417846679687, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+207, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5748.85400390625, 10701.521484375, 5.264556884765625, 5.40595102310180664, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+208, 123767, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6023.38525390625, 10580.28125, 19.65815925598144531, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Event Portal Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+209, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5775.76220703125, 10769.01953125, 6.207336902618408203, 3.507522106170654296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+210, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5740.060546875, 10678.5029296875, 5.264546871185302734, 0.39183935523033142, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+211, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5759.59912109375, 10709.3291015625, 5.26455545425415039, 2.136242866516113281, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+212, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5771.05810546875, 10768.6728515625, 5.685945987701416015, 0.665757715702056884, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+213, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5730.728515625, 10659.8955078125, 6.126157283782958984, 5.284276962280273437, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+214, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6029.85791015625, 10582.0380859375, 56.03403854370117187, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+215, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6024.86279296875, 10571.6943359375, 48.61631393432617187, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+216, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5779.89599609375, 10767.0556640625, 7.215633869171142578, 5.420219898223876953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+217, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6031.91162109375, 10577.140625, 53.00791549682617187, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+218, 122403, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 1, 5778.6083984375, 10779.037109375, 6.956828594207763671, 5.735137939453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+219, 124266, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 6029.81591796875, 10569.65625, 39.66547775268554687, 4.33654022216796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Wave Rift Target Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+220, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5780.66748046875, 10779.498046875, 7.067185878753662109, 5.760232448577880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+221, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5733.00244140625, 10653.4521484375, 5.628672599792480468, 1.539317727088928222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+222, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5737.19091796875, 10652.9970703125, 5.628672599792480468, 1.539317727088928222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+223, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5782.8349609375, 10769.4814453125, 7.2446441650390625, 1.571069002151489257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+224, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5786.109375, 10793.125, 6.066957950592041015, 5.841084003448486328, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+225, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5761.07763671875, 10682.28125, 5.264558315277099609, 1.184253931045532226, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+226, 122403, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 1, 5737.25341796875, 10655.6748046875, 5.672817707061767578, 4.225536346435546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+227, 126211, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5786.25830078125, 10762.7509765625, 7.791719436645507812, 5.343560218811035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+228, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5784.19677734375, 10775.658203125, 7.072039127349853515, 5.471818923950195312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+229, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5779.9619140625, 10729.6982421875, 6.841028213500976562, 4.510384559631347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+230, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5788.3232421875, 10772.8154296875, 6.798820018768310546, 4.468831062316894531, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+231, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5762.68408203125, 10695.7255859375, 5.264556884765625, 3.789059877395629882, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+232, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5777.111328125, 10726.3642578125, 6.803819656372070312, 0.626280665397644042, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+233, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5783.1943359375, 10763.908203125, 7.381380081176757812, 5.320489883422851562, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+234, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5791.51611328125, 10774.7861328125, 6.321233272552490234, 0.966270804405212402, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+235, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5774.76318359375, 10706.0283203125, 5.364642143249511718, 3.469958782196044921, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+236, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5790.33203125, 10747.884765625, 21.19747734069824218, 5.712696552276611328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+237, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5772.27099609375, 10702.9111328125, 5.416342735290527343, 3.703841209411621093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+238, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5783.8759765625, 10726.619140625, 6.96227884292602539, 1.535974383354187011, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+239, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5786.96875, 10812.1533203125, 0.065342903137207031, 3.141592741012573242, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+240, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5776.5947265625, 10686.865234375, 5.264550209045410156, 4.329177379608154296, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+241, 122421, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5807.31982421875, 10741.8701171875, 7.934891700744628906, 4.929893016815185546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Umbral War-Adept (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+242, 122410, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5646.171875, 10480.1904296875, 19.40703582763671875, 0.912736773490905761, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+243, 125504, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5758.15869140625, 10615.6650390625, -3.26215291023254394, 5.611711025238037109, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+244, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5819.861328125, 10722.81640625, 8.619057655334472656, 1.318825006484985351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+245, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5819.4443359375, 10680, 7.75210428237915039, 3.311168432235717773, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+246, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5799.75439453125, 10860.111328125, -15.9469528198242187, 3.141592741012573242, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+247, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5824.283203125, 10724.111328125, 8.48429107666015625, 1.318825006484985351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+248, 125504, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5734.84765625, 10611.03515625, -13.3101892471313476, 2.277229070663452148, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+249, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5824.5732421875, 10776.119140625, 3.280088663101196289, 3.963163375854492187, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+250, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5814.95068359375, 10673.2041015625, 8.130492210388183593, 0.578173339366912841, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+251, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5802.05224609375, 10811.0498046875, -3.89707422256469726, 3.141592741012573242, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+252, 124171, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5812.3125, 10680.0576171875, 8.020959854125976562, 5.951668739318847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+253, 125504, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5724.77685546875, 10614.541015625, -13.7242975234985351, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+254, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5832.3798828125, 10788.7255859375, 0.92263108491897583, 5.471330642700195312, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+255, 125493, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5819.23974609375, 10809.7548828125, -66.9522857666015625, 4.608980178833007812, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+256, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5816.484375, 10668.236328125, 8.120442390441894531, 1.24146127700805664, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+257, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5824.7685546875, 10678.7275390625, 7.688205718994140625, 2.075092792510986328, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+258, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5738.04345703125, 10584.6650390625, -15.9897880554199218, 5.811933040618896484, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+259, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5842.7158203125, 10699.462890625, 12.52796077728271484, 1.181879878044128417, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+260, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5831.703125, 10841.5107421875, -45.4439544677734375, 3.141592741012573242, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+261, 125495, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5853.2412109375, 10799.947265625, -5.40574502944946289, 1.570796370506286621, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+262, 125504, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5775.193359375, 10606.5029296875, -5.95315074920654296, 3.129219293594360351, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+263, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5829.70166015625, 10665.015625, 9.784073829650878906, 5.019934654235839843, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+264, 125505, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5850.5576171875, 10713.091796875, 10.49284934997558593, 2.189683437347412109, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+265, 125504, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5765.4619140625, 10603.7060546875, -12.7444686889648437, 3.791982889175415039, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+266, 122413, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5791.65869140625, 10621.197265625, 4.508100509643554687, 0.707066595554351806, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+267, 122408, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5794, 10617.34375, 4.475020408630371093, 6.202781200408935546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+268, 125504, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5796.2333984375, 10614.09765625, 5.224976062774658203, 3.418081283569335937, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+269, 122403, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 1, 5796.41748046875, 10614.6015625, 4.549900054931640625, 1.539317727088928222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@CGUID+270, 125504, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5803.9560546875, 10625.728515625, 6.138295173645019531, 0.533819735050201416, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+271, 122478, 1753, 8910, 8907, '2,8,23', 0, 0, 0, 0, 5841.69580078125, 10682.7021484375, 12.42100906372070312, 4.331852436065673828, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+272, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5867.16748046875, 10740.904296875, 14.65241718292236328, 3.912096261978149414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+273, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5851.13134765625, 10682.755859375, 13.7259368896484375, 4.296751976013183593, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+274, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5746.39501953125, 10579.8994140625, -14.6299991607666015, 5.439881324768066406, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+275, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5821.2294921875, 10635.59765625, 7.831920146942138671, 0.705122172832489013, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+276, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5859.44482421875, 10683.060546875, 13.67442607879638671, 3.549966812133789062, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+277, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5816.3896484375, 10627.4609375, 5.842313766479492187, 0.438934028148651123, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+278, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5736.24853515625, 10573.8203125, -14.2204446792602539, 3.853618621826171875, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+279, 126312, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5869.8447265625, 10669.197265625, 13.70773983001708984, 0.230383679270744323, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sealed Void Cache (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 250745 - Sealed Void Cache Visual)
(@CGUID+280, 122408, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5864.158203125, 10689.6181640625, 13.74705696105957031, 5.607583045959472656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+281, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5867.5947265625, 10691.7470703125, 13.74706459045410156, 3.047367811203002929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+282, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5772.427734375, 10584.5966796875, -15.0579376220703125, 3.960302114486694335, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+283, 125493, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5835.59228515625, 10858.6240234375, -54.4878501892089843, 1.288138031959533691, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+284, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5865.390625, 10684.7470703125, 13.74706363677978515, 2.137674331665039062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+285, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5873.236328125, 10720.2998046875, 13.66362857818603515, 4.451290607452392578, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch, 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+286, 122407, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5880.40869140625, 10727.7939453125, 13.74696254730224609, 5.24517679214477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Warp Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+287, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5883.63037109375, 10719.23828125, 13.74703025817871093, 1.7752685546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+288, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5887.96240234375, 10728.3349609375, 13.66366481781005859, 2.40755009651184082, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch, 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+289, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5888.984375, 10723.84765625, 13.74707984924316406, 2.684962749481201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+290, 125493, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5857.20361328125, 10837.669921875, -55.4878463745117187, 3.50247049331665039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin Juvenile (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+291, 126312, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5892.57275390625, 10735.5498046875, 13.74706363677978515, 5.085784912109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sealed Void Cache (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 250745 - Sealed Void Cache Visual)
(@CGUID+292, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5891.666015625, 10741.666015625, 13.70569992065429687, 2.291652202606201171, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+293, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5807.58544921875, 10598.7373046875, 4.351091861724853515, 1.950032949447631835, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+294, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5892.509765625, 10724.3125, 13.66373062133789062, 0.970407187938690185, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+295, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5767.9287109375, 10569.4580078125, -15.3226604461669921, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+296, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5897.70947265625, 10727.515625, 13.66373062133789062, 0.478284060955047607, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+297, 122571, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5760.103515625, 10679.2548828125, 5.348301887512207031, 1.641392946243286132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rift Warden (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+298, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5900.01220703125, 10735.1669921875, 13.74706363677978515, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+299, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5900.1787109375, 10754.4365234375, 14.45538616180419921, 5.130869865417480468, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+300, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5860.27587890625, 10620.9384765625, 12.91165065765380859, 2.311333656311035156, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+301, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5863.08984375, 10617.861328125, 13.08295059204101562, 1.171673893928527832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+302, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5717.52001953125, 10538.037109375, -16.0579395294189453, 6.276903629302978515, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+303, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5550.1005859375, 10561.3095703125, 7.75305938720703125, 2.00624847412109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+304, 126249, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5545.8359375, 10562.96875, 7.607554435729980468, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Orb Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+305, 122407, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5865.78173828125, 10629.919921875, 12.22949600219726562, 1.150390982627868652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Warp Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+306, 122413, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5865.78173828125, 10629.919921875, 12.22949600219726562, 1.150390982627868652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+307, 122401, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5709.12744140625, 10682.87109375, 5.968325614929199218, 2.555520534515380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Trickster (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 246284 - Stealth, 245655 - Arcing Void) (possible waypoints or random movement)
(@CGUID+308, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5831.89599609375, 10541.9072265625, 3.8110809326171875, 0.323325872421264648, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+309, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5813.89306640625, 10561.861328125, 0.520833313465118408, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+310, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5752.07958984375, 10514.91796875, -15.4962921142578125, 1.343276500701904296, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+311, 124276, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5858.61962890625, 10603.3330078125, 39.22848892211914062, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Conversation Controller (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+312, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5687.95068359375, 10504.423828125, 49.21274948120117187, 4.712388992309570312, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+313, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5745.1513671875, 10492.6826171875, -13.8428678512573242, 5.24619293212890625, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+314, 122421, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5543.86962890625, 10560.3623046875, 7.657486915588378906, 1.336207032203674316, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Umbral War-Adept (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+315, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5541.6572265625, 10565.9072265625, 7.535705089569091796, 6.089834213256835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+316, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5703.05126953125, 10474.1923828125, 46.58638381958007812, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+317, 128171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5741.66259765625, 10477.943359375, -16.0048084259033203, 3.68189096450805664, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+318, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5714.5498046875, 10444.7333984375, -16.577402114868164, 5.236311912536621093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+319, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5781.17236328125, 10483.1884765625, -16.8606452941894531, 4.305610179901123046, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+320, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5722.9501953125, 10440.2685546875, -15.6014509201049804, 6.138577938079833984, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+321, 122408, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5690.3349609375, 10422.3291015625, -48.4353828430175781, 2.852972030639648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+322, 127911, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5940.54150390625, 10504.2626953125, 14.88410758972167968, 0.954904079437255859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void-Blade Zedaat (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 42459 - Dual Wield, 244300 - Void Infusion)
(@CGUID+323, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5893.12939453125, 10620.3896484375, 12.72169017791748046, 0.045449506491422653, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+324, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5898.22900390625, 10619.1357421875, 12.90097808837890625, 3.485881805419921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+325, 122413, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5895.30029296875, 10612.935546875, 12.82151508331298828, 0.945768415927886962, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+326, 126211, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5922.40283203125, 10719.8681640625, 21.68865585327148437, 0.436352550983428955, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+327, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5919.06689453125, 10728.0732421875, 13.74706363677978515, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+328, 126211, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5927.861328125, 10717.8095703125, 24.11660575866699218, 0.603990018367767333, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+329, 122410, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5761.81298828125, 10633.9541015625, 73.8961181640625, 2.377415180206298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+330, 122410, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5942.47900390625, 10526.56640625, 63.95124435424804687, 2.274402856826782226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Skyfin (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+331, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5839.37255859375, 10532.3466796875, 12.20122432708740234, 4.346905231475830078, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+332, 122408, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5901.064453125, 10614.3720703125, 13.01441192626953125, 3.485881805419921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+333, 122413, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5924.43017578125, 10641.466796875, 13.44174003601074218, 3.9888153076171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+334, 126211, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5930.4208984375, 10717.09765625, 15.58051013946533203, 0.436352550983428955, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+335, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5926.6015625, 10640.19140625, 13.57901954650878906, 2.828320503234863281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+336, 126211, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5930.7900390625, 10725.9072265625, 23.8824310302734375, 0.603990018367767333, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+337, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5926.52685546875, 10636.8818359375, 13.60532760620117187, 2.448574781417846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+338, 122408, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5928.76171875, 10638.619140625, 13.60961341857910156, 2.821295976638793945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+339, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5933.55517578125, 10699.486328125, 13.66373062133789062, 5.482451438903808593, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+340, 122408, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5914.66943359375, 10560.5673828125, 14.66595077514648437, 2.260747909545898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+341, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5939.51171875, 10717.060546875, 13.66373062133789062, 0.902315855026245117, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+342, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5917.72900390625, 10562.0078125, 15.02023601531982421, 4.37492227554321289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+343, 126211, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5933.76416015625, 10724.7080078125, 21.56414794921875, 0.436352550983428955, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Channel Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+344, 122421, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5916.08349609375, 10566.92578125, 15.1286773681640625, 2.260747909545898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Umbral War-Adept (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+345, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5916.09228515625, 10570.6240234375, 15.11535930633544921, 2.260747909545898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+346, 122413, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5915.02685546875, 10563.1240234375, 14.98034477233886718, 2.260747909545898437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+347, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5940.8251953125, 10682.22265625, 13.66373062133789062, 5.810940742492675781, 7200, 0, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+348, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5836.83642578125, 10486.6240234375, 5.136880874633789062, 2.819533109664916992, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+349, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5901.31689453125, 10532.166015625, 9.895975112915039062, 4.123303413391113281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+350, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5965.11181640625, 10622.5283203125, 14.20985603332519531, 2.941123485565185546, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+351, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5941.2373046875, 10756.6953125, 4.403399944305419921, 0.030946964398026466, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+352, 126312, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5962.4921875, 10682.7001953125, 13.67162799835205078, 3.564450979232788085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sealed Void Cache (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 250745 - Sealed Void Cache Visual)
(@CGUID+353, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5965.82958984375, 10699.4375, 14.01100063323974609, 0.614895880222320556, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+354, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5958.6123046875, 10703.5029296875, 13.66095256805419921, 3.504755735397338867, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+355, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5952.0830078125, 10725.5205078125, 13.66283893585205078, 3.018584489822387695, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+356, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5787.90380859375, 10452.6708984375, -23.6644744873046875, 3.104578018188476562, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+357, 122413, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5760.8037109375, 10446.3349609375, -29.0327186584472656, 4.935923099517822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Riftstalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+358, 126312, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5973.76806640625, 10641.1494140625, 12.56366348266601562, 2.627470970153808593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Sealed Void Cache (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 250745 - Sealed Void Cache Visual)
(@CGUID+359, 128171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5849.017578125, 10459.8759765625, 6.217238903045654296, 4.514126777648925781, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+360, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5981.75146484375, 10639.1884765625, 12.93276214599609375, 5.465317726135253906, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch, 244300 - Void Infusion)
(@CGUID+361, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5966.4326171875, 10709.8447265625, 16.56895828247070312, 1.125790119171142578, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+362, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5980.287109375, 10620.2763671875, 14.35613918304443359, 5.959355831146240234, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+363, 122405, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5968.67626953125, 10724.974609375, 9.971856117248535156, 1.9658128023147583, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Conjurer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+364, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5969.251953125, 10730.2490234375, 9.217749595642089843, 1.527052164077758789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+365, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5940.79541015625, 10783.7314453125, -0.40262532234191894, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+366, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5938.453125, 10776.5361328125, -2.31679916381835937, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+367, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5963.23876953125, 10746.439453125, 4.174108505249023437, 3.828702688217163085, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+368, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5958.5849609375, 10751.25390625, 4.345679759979248046, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+369, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5974.06591796875, 10722.185546875, 10.26355552673339843, 0.980627477169036865, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+370, 122421, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5959.61572265625, 10526.7783203125, 14.39990997314453125, 2.688033819198608398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Umbral War-Adept (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+371, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5967.40625, 10768.9169921875, -0.3491983413696289, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+372, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5959.71875, 10778.69140625, 1.015908002853393554, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+373, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5984.7470703125, 10744.484375, 5.137216567993164062, 1.159812092781066894, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+374, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6002.89111328125, 10653.16796875, 29.87580680847167968, 4.972773551940917968, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+375, 125504, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6014.65234375, 10688.1845703125, 28.87580490112304687, 1.972328782081604003, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Shardling (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+376, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5961.68701171875, 10529.1865234375, 13.91109180450439453, 2.618768930435180664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+377, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5958.22900390625, 10523.263671875, 14.98120021820068359, 2.650476694107055664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion) (possible waypoints or random movement)
(@CGUID+378, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5872.9921875, 10458.056640625, 8.662278175354003906, 0.137392565608024597, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion, 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+379, 125495, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6018.82275390625, 10746.2314453125, 4.365597248077392578, 0, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Voidstalker Runt (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+380, 122401, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5872.970703125, 10672.4384765625, 13.61356735229492187, 4.423998832702636718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Trickster (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 246284 - Stealth, 245655 - Arcing Void)
(@CGUID+381, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5973.64697265625, 10494.5615234375, 19.34757423400878906, 0.724469780921936035, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion, 245746 - Corrupting Touch)
(@CGUID+382, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5983.3330078125, 10497.916015625, 18.77062225341796875, 4.437398910522460937, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion, 245746 - Corrupting Touch)
(@CGUID+383, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5983.861328125, 10486.9462890625, 20.30192756652832031, 1.828484416007995605, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion, 245746 - Corrupting Touch)
(@CGUID+384, 124171, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6028.1318359375, 10520.775390625, 17.52709388732910156, 1.373452305793762207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Subjugator (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+385, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5971.716796875, 10480.34375, 20.95504188537597656, 2.77742314338684082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+386, 122421, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6031.75, 10522.34765625, 17.5437774658203125, 1.373452305793762207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Umbral War-Adept (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+387, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5878.5009765625, 10454.26953125, 8.862707138061523437, 6.099361419677734375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion, 245746 - Corrupting Touch)
(@CGUID+388, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6034.619140625, 10524.689453125, 17.1816864013671875, 1.373452305793762207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+389, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5870.87890625, 10449.216796875, 8.196470260620117187, 1.771809697151184082, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion, 245746 - Corrupting Touch)
(@CGUID+390, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5818.01513671875, 10443.0087890625, 3.10696578025817871, 0.320574045181274414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+391, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6016.5439453125, 10496.1083984375, 20.12151336669921875, 5.640573501586914062, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+392, 122405, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5986.7578125, 10461.2900390625, 20.14509963989257812, 2.48136138916015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Conjurer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+393, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5857.47802734375, 10410.6796875, 29.37317657470703125, 3.802735090255737304, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+394, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6024.34326171875, 10487.744140625, 21.1392059326171875, 4.31081247329711914, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+395, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5837.61328125, 10423.01953125, 3.395533561706542968, 0.098446160554885864, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+396, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5884.359375, 10386.2021484375, 2.464193582534790039, 0.519146144390106201, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+397, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6050.5576171875, 10495.326171875, 20.10002517700195312, 5.481521129608154296, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+398, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6053.984375, 10467.97265625, 20.87271308898925781, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+399, 125505, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5792.29150390625, 10424.9736328125, -2.09747052192687988, 5.901519298553466796, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+400, 122408, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5813.4287109375, 10418.2216796875, -38.7461624145507812, 3.350849866867065429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+401, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6057.287109375, 10504.1162109375, 19.86213874816894531, 5.064273834228515625, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+402, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6007.96875, 10453.095703125, 20.05151557922363281, 4.855483531951904296, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch, 244300 - Void Infusion)
(@CGUID+403, 122408, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 5814.60498046875, 10415.01953125, -38.7901649475097656, 3.041694164276123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadow Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+404, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6023.16748046875, 10448.4345703125, 19.24925994873046875, 1.891023874282836914, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+405, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6048.23974609375, 10471.9404296875, 21.1250152587890625, 6.218331813812255859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+406, 124947, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6048.72314453125, 10477.7001953125, 20.6785736083984375, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Flayer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+407, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6073.6630859375, 10468.384765625, 23.42107963562011718, 5.19045257568359375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+408, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6085.15966796875, 10502.5908203125, 24.1930389404296875, 4.743277549743652343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+409, 122405, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6085.330078125, 10496.7392578125, 23.98544692993164062, 3.530579328536987304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Conjurer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+410, 126249, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6087.56689453125, 10498.083984375, 24.58295440673828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Orb Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 250640 - Periodic Void Missile, 250643 - Periodic Void Missile, 250644 - Periodic Void Missile)
(@CGUID+411, 124947, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6058.08349609375, 10463.1162109375, 21.29290580749511718, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Flayer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+412, 122405, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6056.59716796875, 10446.7314453125, 23.45233154296875, 5.495825767517089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Conjurer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+413, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6091.8203125, 10496.126953125, 25.27573204040527343, 2.335672616958618164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+414, 122405, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6098.962890625, 10481.673828125, 23.97002029418945312, 5.132033348083496093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Conjurer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+415, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6085.59716796875, 10474.095703125, 23.77896308898925781, 3.703841209411621093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+416, 126249, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6062.494140625, 10445.3583984375, 24.57729148864746093, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Orb Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 250640 - Periodic Void Missile, 250643 - Periodic Void Missile, 250644 - Periodic Void Missile)
(@CGUID+417, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6069.5068359375, 10450.59765625, 24.62907791137695312, 3.543079137802124023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+418, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6065.0322265625, 10440.4814453125, 25.16714096069335937, 2.075032949447631835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+419, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6083.10986328125, 10462.291015625, 24.47559738159179687, 3.4304046630859375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+420, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6104.1416015625, 10479.888671875, 24.1649322509765625, 2.180161237716674804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+421, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6100.47412109375, 10476.294921875, 24.72222328186035156, 2.180161237716674804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+422, 122401, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6026.3349609375, 10399.4658203125, 20.87476158142089843, 1.380270004272460937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Trickster (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 244300 - Void Infusion)
(@CGUID+423, 127466, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6098.23193359375, 10435.537109375, 29.39315605163574218, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+424, 127451, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6098.90380859375, 10437.9306640625, 28.921173095703125, 5.37461709976196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Thal'kiel (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+425, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6095.0537109375, 10402.533203125, 20.10940170288085937, 1.267983913421630859, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+426, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6083.64404296875, 10399.0166015625, 20.41124916076660156, 0.249710485339164733, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+427, 122826, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6115.791015625, 10405.6064453125, 20.01736259460449218, 6.229828357696533203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+428, 122404, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 6138.7724609375, 10423.5107421875, 19.75576019287109375, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+429, 122826, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6107.25, 10399.1533203125, 19.71840286254882812, 6.229828357696533203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+430, 124947, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6139.00341796875, 10428.1484375, 19.740570068359375, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Flayer (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+431, 122826, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6129.953125, 10414.779296875, 19.824249267578125, 5.038817882537841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+432, 122826, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6122.84228515625, 10411.5283203125, 19.82465362548828125, 5.038817882537841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1
(@CGUID+433, 122478, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 0, 6095.40966796875, 10392.365234375, 19.79533958435058593, 4.353618621826171875, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: Shadowguard Incursion - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch) (possible waypoints or random movement)
(@CGUID+434, 122423, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6120.24560546875, 10415.3798828125, 19.73696327209472656, 0.944067537784576416, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Grand Shadow-Weaver (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+435, 122404, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 1, 6117.01953125, 10416.5927734375, 19.76976203918457031, 0.878580570220947265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+436, 122404, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 1, 6132.69921875, 10423.814453125, 19.68475532531738281, 0.619480490684509277, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+437, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6157.2255859375, 10441.1416015625, 19.89771080017089843, 0.539165914058685302, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+438, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6106.15625, 10388.7626953125, 19.83587837219238281, 0.721143007278442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+439, 124947, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6151.19189453125, 10419.34375, 19.75342369079589843, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Flayer (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+440, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6145, 10401.974609375, 19.84833526611328125, 3.808900833129882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+441, 124947, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6145.4921875, 10424.9599609375, 19.73090362548828125, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Flayer (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+442, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6152.9931640625, 10408.9345703125, 19.81597328186035156, 4.264319419860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+443, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6128.85791015625, 10400.279296875, 19.85788154602050781, 3.808900833129882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+444, 122405, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 1, 6150.17626953125, 10424.529296875, 19.720794677734375, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Conjurer (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+445, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6136.4306640625, 10406.591796875, 19.8440704345703125, 3.808900833129882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+446, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6185.62890625, 10462.4765625, 29.70200347900390625, 0.360321998596191406, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+447, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6109.0244140625, 10381.5068359375, 19.97617340087890625, 0.721143007278442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+448, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6166.7802734375, 10433.630859375, 20.85885810852050781, 0.517814099788665771, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+449, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6134.6650390625, 10393.2470703125, 19.87643241882324218, 4.264319419860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+450, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6125.7119140625, 10391.6318359375, 19.878082275390625, 5.038817882537841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+451, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6173.3271484375, 10455.978515625, 25.43490028381347656, 3.976855754852294921, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+452, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6117.62353515625, 10393.3037109375, 19.79049491882324218, 0.721143007278442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+453, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6140.90185546875, 10413.9345703125, 19.81716346740722656, 5.038817882537841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+454, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6126.390625, 10359.5439453125, 19.87160491943359375, 1.176561713218688964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+455, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6134.5009765625, 10364.7568359375, 19.9025726318359375, 1.176561713218688964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+456, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6118.78564453125, 10381.208984375, 19.9118499755859375, 1.176561713218688964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+457, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6145.64599609375, 10379.5439453125, 19.91244888305664062, 5.038817882537841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+458, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6156.63623046875, 10382.333984375, 19.88228034973144531, 3.034401416778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+459, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6168.68310546875, 10382.5126953125, 19.7849273681640625, 3.034401416778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+460, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6153.06591796875, 10369.755859375, 19.97915458679199218, 1.951060175895690917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+461, 122404, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 1, 6125.62060546875, 10354.150390625, 19.88862991333007812, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+462, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6118.728515625, 10367.4033203125, 19.8955841064453125, 1.176561713218688964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+463, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6164.97216796875, 10391.107421875, 19.80512046813964843, 3.034401416778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+464, 124947, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6118.8662109375, 10350.630859375, 19.85580062866210937, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Flayer (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+465, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6140.53564453125, 10367.1845703125, 19.92583465576171875, 1.951060175895690917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+466, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6132.5625, 10376.974609375, 19.9044036865234375, 5.038817882537841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+467, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6132.6181640625, 10384.7255859375, 19.89744758605957031, 6.229828357696533203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+468, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6160.21875, 10400.6689453125, 19.78125, 4.264319419860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+469, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6125.150390625, 10370.451171875, 19.91313743591308593, 6.229828357696533203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+470, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6114.40478515625, 10372.240234375, 19.90320777893066406, 0.721143007278442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+471, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6152.31103515625, 10395.591796875, 19.85557937622070312, 3.808900833129882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+472, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6144.2900390625, 10391.5126953125, 19.8788299560546875, 4.264319419860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+473, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6149.7119140625, 10354.935546875, 19.76215362548828125, 1.951060175895690917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+474, 124947, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6128.5458984375, 10351.4423828125, 19.9122161865234375, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Void Flayer (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+475, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6153.984375, 10359.115234375, 20.13020896911621093, 3.034401416778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+476, 122404, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 1, 6121.978515625, 10345.705078125, 19.89357185363769531, 2.687363862991333007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Voidbender (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+477, 125104, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6076.18994140625, 10319.400390625, 34.11213302612304687, 0.865414440631866455, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- L'ura Door Barrier Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 248453 - Door Barrier Visual)
(@CGUID+478, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6138.73291015625, 10355.1943359375, 19.74652862548828125, 1.951060175895690917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+479, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6166.47119140625, 10371.943359375, 19.74131965637207031, 3.034401416778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+480, 122826, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6161.09814453125, 10362.3662109375, 19.90798759460449218, 3.034401416778564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tentacle Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+481, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6140.109375, 10305.3798828125, 20.50337982177734375, 1.044561624526977539, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+482, 125855, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6218.52685546875, 10360.677734375, 48.35999679565429687, 3.942159175872802734, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+483, 125855, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6204.70947265625, 10346.6845703125, 43.44348907470703125, 1.180145978927612304, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+484, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6137.5419921875, 10299.90625, 21.00506591796875, 1.662926077842712402, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+485, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6168.365234375, 10306.12109375, 21.70152473449707031, 3.542767047882080078, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+486, 127465, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6037.91943359375, 10281.0595703125, 19.00732803344726562, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+487, 125505, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5912.8134765625, 10366.0380859375, 1.870427370071411132, 2.670089006423950195, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+488, 127450, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6038.7568359375, 10279.2548828125, 18.91118621826171875, 5.37461709976196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Thal'kiel (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+489, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6179.89453125, 10299.177734375, 25.03311538696289062, 3.852337837219238281, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+490, 122478, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6145.13427734375, 10290.216796875, 22.21829605102539062, 5.474963188171386718, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Void Discharge (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245746 - Corrupting Touch)
(@CGUID+491, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6004.6806640625, 10247.853515625, 14.54757022857666015, 1.079034090042114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+492, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5993.93212890625, 10251.8251953125, 15.0205078125, 0.365992903709411621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+493, 127464, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6005.7197265625, 10248.2099609375, 14.62825679779052734, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+494, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5989.91650390625, 10261.1630859375, 16.07469558715820312, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+495, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5997.75341796875, 10251.142578125, 15.24345684051513671, 0.365992903709411621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+496, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6003.97900390625, 10254.21875, 15.16561222076416015, 0.446965783834457397, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+497, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6007.931640625, 10243.6845703125, 14.39028549194335937, 0.28644534945487976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+498, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6010.44091796875, 10247.9970703125, 14.84273147583007812, 0.147275477647781372, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+499, 127448, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6004.62353515625, 10246.4619140625, 14.4409942626953125, 5.37461709976196289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Thal'kiel (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+500, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5988.17431640625, 10259.4423828125, 15.68375778198242187, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+501, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5997.62353515625, 10242.544921875, 13.79505348205566406, 0.924668192863464355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+502, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5985.2255859375, 10248.78515625, 13.69626522064208984, 5.592793941497802734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+503, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6018.95068359375, 10228.9453125, 15.02211475372314453, 5.204419136047363281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+504, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6006.462890625, 10235.0234375, 13.82611656188964843, 4.960330486297607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+505, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5991.32666015625, 10244.013671875, 13.64613723754882812, 0.924668192863464355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+506, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6010.59375, 10236.6494140625, 14.79665470123291015, 4.960330486297607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+507, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6000.6494140625, 10245.8095703125, 14.19301891326904296, 1.079034090042114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+508, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6009.65478515625, 10232.0361328125, 13.97311592102050781, 5.285391807556152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+509, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5980.10693359375, 10251.3056640625, 13.63575553894042968, 4.528699874877929687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+510, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6000.98095703125, 10238.1591796875, 13.62657928466796875, 0.132079467177391052, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+511, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6004.12939453125, 10241.7861328125, 14.05821800231933593, 0.28644534945487976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+512, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5983.822265625, 10255.0908203125, 14.10737133026123046, 5.673766613006591796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+513, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6018.8671875, 10231.3408203125, 15.21498394012451171, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+514, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5992.95751953125, 10247.2080078125, 13.96997833251953125, 0.446965783834457397, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+515, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6014.5400390625, 10230.6591796875, 14.54857540130615234, 5.285391807556152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+516, 124734, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5978.5634765625, 10258.869140625, 14.13577175140380859, 5.585053443908691406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Call to the Void Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+517, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5981.97216796875, 10254.2744140625, 13.48005485534667968, 5.348706722259521484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+518, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5990.16748046875, 10248.1376953125, 13.90312576293945312, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+519, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5992.345703125, 10240.4833984375, 13.37762069702148437, 0.924668192863464355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+520, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6012.236328125, 10226.685546875, 13.34541034698486328, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+521, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6005.244140625, 10232.552734375, 13.45967960357666015, 5.204419136047363281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+522, 124734, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6018.16064453125, 10221.212890625, 13.22071647644042968, 2.486375093460083007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Call to the Void Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+523, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6002.28466796875, 10232.578125, 13.31555843353271484, 0.132079467177391052, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+524, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6009.05029296875, 10226.0576171875, 13.14033699035644531, 6.105399131774902343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+525, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5995.484375, 10235.9287109375, 13.34092330932617187, 0.132079467177391052, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+526, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5979.3369140625, 10250.1005859375, 13.48005485534667968, 5.592793941497802734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+527, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5987.56591796875, 10243.1064453125, 13.57770538330078125, 0.924668192863464355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+528, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5995.62841796875, 10235.91015625, 13.34578418731689453, 0.132079467177391052, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+529, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5981.90966796875, 10247.84375, 13.46102428436279296, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+530, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6013.572265625, 10223.9111328125, 13.19990730285644531, 5.285391807556152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+531, 125855, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6074.1328125, 10199.943359375, 1.398030638694763183, 3.752042770385742187, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+532, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5997.2744140625, 10223.2568359375, 14.527984619140625, 6.105399131774902343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+533, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6008.39404296875, 10220.708984375, 12.99744224548339843, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+534, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5990.0634765625, 10232.0615234375, 14.76193046569824218, 0.792588710784912109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+535, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5991.87255859375, 10228.201171875, 13.48005485534667968, 0.924668192863464355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+536, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5981.2578125, 10239.3408203125, 13.48005485534667968, 0.924668192863464355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+537, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5975.1650390625, 10238.9619140625, 13.48005485534667968, 5.348706722259521484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+538, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5984.23974609375, 10237.638671875, 13.48005485534667968, 5.348706722259521484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+539, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6011.40087890625, 10220.095703125, 12.89851570129394531, 0.066302590072154998, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+540, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5982.82373046875, 10233.6474609375, 14.95905685424804687, 0.792588710784912109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+541, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5997.43212890625, 10230.6494140625, 13.82593345642089843, 0.132079467177391052, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+542, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6002.6181640625, 10223.654296875, 12.77553749084472656, 0.066302590072154998, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+543, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6006.3193359375, 10224.4775390625, 12.88529682159423828, 0.147275477647781372, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+544, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5978.07470703125, 10237.0830078125, 14.53017330169677734, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+545, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5988.6640625, 10233.8818359375, 13.48005485534667968, 0.924668192863464355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+546, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6010.51416015625, 10222.9619140625, 12.97672080993652343, 0.121904067695140838, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+547, 125855, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6151.49755859375, 10227.486328125, -92.020294189453125, 3.22042083740234375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+548, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5993.1328125, 10221.1650390625, 13.48005485534667968, 0.132079467177391052, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+549, 125855, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6156.45166015625, 10222.5810546875, -91.8803939819335937, 2.755240201950073242, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+550, 125855, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 6153.44921875, 10220.927734375, -91.8911209106445312, 2.980879783630371093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Argus Moth (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+551, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5970.91162109375, 10233.7021484375, 14.38075447082519531, 0.792588710784912109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+552, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5990.1884765625, 10222.876953125, 14.54332160949707031, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+553, 122401, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 1, 6114.9609375, 10346.556640625, 19.85560417175292968, 5.538751125335693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shadowguard Trickster (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1 (Auras: 245655 - Arcing Void, 246284 - Stealth)
(@CGUID+554, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5966.14501953125, 10236.4736328125, 13.89531993865966796, 0.792588710784912109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+555, 124729, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5979.27587890625, 10220.3798828125, 14.28613471984863281, 0.79385155439376831, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- L'ura (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+556, 123008, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5992.2333984375, 10211.5673828125, 13.74750232696533203, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crash/Voidling Stalker (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+557, 125505, 1753, 8910, 8909, '2,8,23', 0, 0, 0, 0, 5888.84814453125, 10358.365234375, -0.22550825774669647, 3.768829345703125, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Chaotic Runoff (Area: The Seat of the Triumvirate - Difficulty: Heroic) CreateObject1
(@CGUID+558, 122403, 1753, 8910, 8905, '2,8,23', 0, 0, 0, 1, 5984.197265625, 10740.515625, 6.153494834899902343, 0.322059482336044311, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265); -- Shadowguard Champion (Area: Shadowguard Incursion - Difficulty: Mythic) CreateObject1 (Auras: 244300 - Void Infusion)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+558;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '249133'), -- Famished Broken - 249133 - Famished Broken Cannibalize Ooze Cosmetic
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '249133'), -- Famished Broken - 249133 - Famished Broken Cannibalize Ooze Cosmetic
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '249133'), -- Famished Broken - 249133 - Famished Broken Cannibalize Ooze Cosmetic
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '249133'); -- Famished Broken - 249133 - Famished Broken Cannibalize Ooze Cosmetic

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 273789, 1753, 8910, 8907, '2,8,23', 0, 0, 5701.00146484375, 10754.2314453125, 18.94998550415039062, 2.888511419296264648, 0, 0, 0.99200439453125, 0.126203224062919616, 7200, 255, 1, 61265), -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001 (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@OGUID+1, 272950, 1753, 8910, 8907, '2,8,23', 0, 0, 5727.298828125, 10852.8505859375, 10.844818115234375, 4.842249870300292968, -0.12843084335327148, 0.000522613525390625, -0.66044044494628906, 0.739813268184661865, 7200, 255, 1, 61265), -- Collision Wall (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@OGUID+2, 272062, 1753, 8910, 8907, '2,8,23', 0, 0, 6074.82275390625, 10317.9912109375, 23.67830848693847656, 0.79474794864654541, 0.02548074722290039, -0.03737926483154296, 0.386971473693847656, 0.920981287956237792, 7200, 255, 1, 61265), -- Doodad_6dr_draenei_karabor_bigdoor001 (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@OGUID+3, 273661, 1753, 8910, 8907, '2,8,23', 0, 0, 6020.54345703125, 10262.4833984375, 16.75821495056152343, 0.79474794864654541, 0.02548074722290039, -0.03737926483154296, 0.386971473693847656, 0.920981287956237792, 7200, 255, 0, 61265), -- Hallway Door (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@OGUID+4, 272918, 1753, 8910, 8907, '2,8,23', 0, 0, 5718.306640625, 10924.4736328125, -6.57266139984130859, 4.742766857147216796, -0.10724449157714843, 0.026304244995117187, -0.69585704803466796, 0.709640562534332275, 7200, 255, 1, 61265), -- Gilded Triumvirate Chest (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
(@OGUID+5, 272954, 1753, 8910, 8907, '2,8,23', 0, 0, 5728.26416015625, 10852.8876953125, 14.74089527130126953, 4.815954208374023437, -0.07929277420043945, 0.058583259582519531, -0.66699886322021484, 0.738507390022277832, 7200, 255, 1, 61265); -- Armory Seal (Area: Triad's Conservatory - Difficulty: Heroic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.992004930973052978, 0.126198962330818176, 0, 0), -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001
(@OGUID+2, 0.025480857118964195, -0.03737971931695938, 0.386971980333328247, 0.920981109142303466, 0, 0), -- Doodad_6dr_draenei_karabor_bigdoor001
(@OGUID+3, 0.025480857118964195, -0.03737971931695938, 0.386971980333328247, 0.920981109142303466, 0, 0); -- Hallway Door

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (125104 /*125104 (L'ura Door Barrier Stalker) - Door Barrier Visual*/, 126249 /*126249 (Void Orb Stalker) - Periodic Void Missile, Periodic Void Missile, Periodic Void Missile*/, 122404 /*122404 (Shadowguard Voidbender) - Void Infusion*/, 122405 /*122405 (Shadowguard Conjurer) - Void Infusion*/, 122412 /*122412 (Bound Voidlord) - Void Infusion*/, 127911 /*127911 (Void-Blade Zedaat) - Dual Wield, Void Infusion*/, 128171 /*128171 (Void Shardling)*/, 122401 /*122401 (Shadowguard Trickster) - Stealth, Arcing Void*/, 125981 /*125981 (Fragmented Voidling) - Void Infusion*/, 122407 /*122407 (Warp Stalker) - Void Infusion*/, 126312 /*126312 (Sealed Void Cache) - Sealed Void Cache Visual*/, 125504 /*125504 (Void Shardling)*/, 122421 /*122421 (Umbral War-Adept) - Void Infusion*/, 122408 /*122408 (Shadow Stalker) - Void Infusion*/, 122413 /*122413 (Shadowguard Riftstalker) - Void Infusion*/, 122403 /*122403 (Shadowguard Champion) - Void Infusion*/, 124264 /*124264 (Move Alleria Stalker) - Move Alleria Area Trigger*/, 127008 /*127008 (Assault Door Stalker)*/, 125493 /*125493 (Skyfin Juvenile)*/, 126211 /*126211 (Void Channel Stalker)*/, 122410 /*122410 (Skyfin)*/, 122832 /*122832 (Center Point)*/, 122056 /*122056 (Viceroy Nezhar) - Override Energy Bar Color, Void Phased*/, 122058 /*122058 (Void Tentacle) - Ride Vehicle*/, 122482 /*122482 (Dark Aberration) - Dark Lashing, Void Realm*/, 123767 /*123767 (Wave Event Portal Stalker)*/, 122560 /*122560 (Shadow Stalker) - Physical Realm (Cosmetic)*/, 124266 /*124266 (Wave Rift Target Stalker)*/, 122313 /*122313 (Zuraal the Ascended) - Physical Realm (Cosmetic), Void Phased*/, 124171 /*124171 (Shadowguard Subjugator) - Void Infusion*/, 122398 /*122398 (Sapped Voidlord) - Override Energy Bar Color*/, 125855 /*125855 (Argus Moth)*/, 122322 /*122322 (Famished Broken) - Void Infusion*/, 122478 /*122478 (Void Discharge) - Corrupting Touch*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(125104, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '248453'), -- 125104 (L'ura Door Barrier Stalker) - Door Barrier Visual
(126249, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '250640 250643 250644'), -- 126249 (Void Orb Stalker) - Periodic Void Missile, Periodic Void Missile, Periodic Void Missile
(122404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122404 (Shadowguard Voidbender) - Void Infusion
(122405, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122405 (Shadowguard Conjurer) - Void Infusion
(122412, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122412 (Bound Voidlord) - Void Infusion
(127911, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '42459 244300'), -- 127911 (Void-Blade Zedaat) - Dual Wield, Void Infusion
(128171, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 128171 (Void Shardling)
(122401, 0, 0, 0, 0, 2, 1, 0, 0, 0, 0, 0, 0, '246284 245655'), -- 122401 (Shadowguard Trickster) - Stealth, Arcing Void
(125981, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 125981 (Fragmented Voidling) - Void Infusion
(122407, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122407 (Warp Stalker) - Void Infusion
(126312, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '250745'), -- 126312 (Sealed Void Cache) - Sealed Void Cache Visual
(125504, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 125504 (Void Shardling)
(122421, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122421 (Umbral War-Adept) - Void Infusion
(122408, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122408 (Shadow Stalker) - Void Infusion
(122413, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122413 (Shadowguard Riftstalker) - Void Infusion
(122403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122403 (Shadowguard Champion) - Void Infusion
(124264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '246858'), -- 124264 (Move Alleria Stalker) - Move Alleria Area Trigger
(127008, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 127008 (Assault Door Stalker)
(125493, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 125493 (Skyfin Juvenile)
(126211, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 126211 (Void Channel Stalker)
(122410, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 122410 (Skyfin)
(122832, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''), -- 122832 (Center Point)
(122056, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, '245029 246913'), -- 122056 (Viceroy Nezhar) - Override Energy Bar Color, Void Phased
(122058, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 122058 (Void Tentacle) - Ride Vehicle
(122482, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '254732 244061'), -- 122482 (Dark Aberration) - Dark Lashing, Void Realm
(123767, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 123767 (Wave Event Portal Stalker)
(122560, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244087'), -- 122560 (Shadow Stalker) - Physical Realm (Cosmetic)
(124266, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 124266 (Wave Rift Target Stalker)
(122313, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '244087 246913'), -- 122313 (Zuraal the Ascended) - Physical Realm (Cosmetic), Void Phased
(124171, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 124171 (Shadowguard Subjugator) - Void Infusion
(122398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '245753'), -- 122398 (Sapped Voidlord) - Override Energy Bar Color
(125855, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 125855 (Argus Moth)
(122322, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '244300'), -- 122322 (Famished Broken) - Void Infusion
(122478, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '245746'); -- 122478 (Void Discharge) - Corrupting Touch

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (272954 /*Armory Seal*/, 272918 /*Gilded Triumvirate Chest*/, 273661 /*Hallway Door*/, 272062 /*Doodad_6dr_draenei_karabor_bigdoor001*/, 272950 /*Collision Wall*/, 273789 /*Doodad_7FX_ArgusDungeon_AlleriaVoidWall001*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(272954, 0, 0x10, 0, 0), -- Armory Seal
(272918, 0, 0x2004, 0, 0), -- Gilded Triumvirate Chest
(273661, 0, 0x30, 0, 0), -- Hallway Door
(272062, 0, 0x30, 0, 0), -- Doodad_6dr_draenei_karabor_bigdoor001
(272950, 0, 0x2010, 0, 0), -- Collision Wall
(273789, 0, 0x30, 0, 0); -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001

-- Template
DELETE FROM `gameobject_template` WHERE `entry` IN (272918 /*Gilded Triumvirate Chest*/, 272954 /*Armory Seal*/, 272950 /*Collision Wall*/, 273789 /*Doodad_7FX_ArgusDungeon_AlleriaVoidWall001*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(272918, 3, 23883, 'Gilded Triumvirate Chest', 'questinteract', '', '', 1, 1634, 0, 0, 1, 0, 0, 0, 0, 48231, 0, 1, 1, 1, 1, 0, 0, 0, 51600, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 1, 0, 75420, 1, 0, 0, 0, 337, 61265), -- Gilded Triumvirate Chest
(272954, 8, 43866, 'Armory Seal', '', '', '', 1.20000004768371582, 1925, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 337, 61265), -- Armory Seal
(272950, 5, 6391, 'Collision Wall', '', '', '', 0.649999976158142089, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 337, 61265), -- Collision Wall
(273789, 0, 44277, 'Doodad_7FX_ArgusDungeon_AlleriaVoidWall001', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 61265); -- Doodad_7FX_ArgusDungeon_AlleriaVoidWall001

UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=124729; -- L'ura
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x40000000, `flags_extra` = 128 WHERE `entry`=124734; -- Call to the Void Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x800, `unit_flags3`=0x1000001, `flags_extra` = 128 WHERE `entry` IN (127448, 127450, 127451); -- Thal'kiel
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x800, `unit_flags3`=0x1000001, `flags_extra` = 128 WHERE `entry` IN (127464, 127465, 127466); -- Xal'atath
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=123008; -- Crash/Voidling Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x40000000, `flags_extra` = 128 WHERE `entry`=125104; -- L'ura Door Barrier Stalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122423; -- Grand Shadow-Weaver
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x1, `flags_extra` = 128 WHERE `entry`=122826; -- Tentacle Stalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=124947; -- Void Flayer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122405; -- Shadowguard Conjurer
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122412; -- Bound Voidlord
UPDATE `creature_template` SET `faction`=14, `speed_walk`=6, `speed_run`=2.142857074737548828, `BaseAttackTime`=1500 WHERE `entry`=127911; -- Void-Blade Zedaat
UPDATE `creature_template` SET `faction`=190, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=128171; -- Void Shardling
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `flags_extra` = 128 WHERE `entry`=124276; -- Conversation Controller
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122401; -- Shadowguard Trickster
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x80000 WHERE `entry`=125981; -- Fragmented Voidling
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x1000000, `flags_extra` = 128 WHERE `entry`=126249; -- Void Orb Stalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122404; -- Shadowguard Voidbender
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122571; -- Rift Warden
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `unit_flags3`=0x41000000 WHERE `entry`=126312; -- Sealed Void Cache
UPDATE `creature_template` SET `faction`=2916, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=125836; -- Alleria Windrunner
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=122407; -- Warp Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `flags_extra` = 128 WHERE `entry`=125780; -- Generic Bunny
UPDATE `creature_template` SET `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=123744; -- Locus-Walker
UPDATE `creature_template` SET `faction`=2916, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=123743; -- Alleria Windrunner
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `flags_extra` = 128 WHERE `entry`=124264; -- Move Alleria Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `flags_extra` = 128 WHERE `entry`=127008; -- Assault Door Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `flags_extra` = 128 WHERE `entry`=126211; -- Void Channel Stalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122413; -- Shadowguard Riftstalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122421; -- Umbral War-Adept
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=122408; -- Shadow Stalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122403; -- Shadowguard Champion
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=122410; -- Skyfin
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x1, `flags_extra` = 128 WHERE `entry`=122832; -- Center Point
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags3`=0x1, `VehicleId`=5408 WHERE `entry`=122056; -- Viceroy Nezhar
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x20800, `unit_flags3`=0x1 WHERE `entry`=122058; -- Void Tentacle
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122482; -- Dark Aberration
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x40000000, `flags_extra` = 128 WHERE `entry`=123767; -- Wave Event Portal Stalker
UPDATE `creature_template` SET `faction`=2156, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=122560; -- Shadow Stalker
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `flags_extra` = 128 WHERE `entry`=124266; -- Wave Rift Target Stalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=122313; -- Zuraal the Ascended
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=124171; -- Shadowguard Subjugator
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000 WHERE `entry`=122398; -- Sapped Voidlord
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122322; -- Famished Broken
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=122478; -- Void Discharge

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (128171,125504,125505,125495,125855));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(128171, 2, 0, 0, 371, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 128171 (Void Shardling) - CanSwim, Floating
(125504, 2, 0, 0, 81, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125504 (Void Shardling) - Floating
(125505, 2, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125505 (Chaotic Runoff) - 
(125495, 2, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125495 (Voidstalker Runt) - 
(125855, 2, 0, 0, 81, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265); -- 125855 (Argus Moth) - Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=133639 WHERE (`Entry`=128171 AND `DifficultyID`=2); -- Void Shardling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=130734 WHERE (`Entry`=125504 AND `DifficultyID`=2); -- Void Shardling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=130725 WHERE (`Entry`=125495 AND `DifficultyID`=2); -- Voidstalker Runt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=130735 WHERE (`Entry`=125505 AND `DifficultyID`=2); -- Chaotic Runoff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=131148 WHERE (`Entry`=125855 AND `DifficultyID`=2); -- Argus Moth

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000 WHERE (`Entry` IN (125104, 124266, 126211) AND `DifficultyID` = 2);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=124729 AND `DifficultyID`=2); -- 124729 (L'ura) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61265 WHERE (`DifficultyID`=2 AND `Entry` IN (127448,127464,127450,127465,127451,127466,125780));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122423 AND `DifficultyID`=2); -- 122423 (Grand Shadow-Weaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=124947 AND `DifficultyID`=2); -- 124947 (Void Flayer) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122405 AND `DifficultyID`=2); -- 122405 (Shadowguard Conjurer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122412 AND `DifficultyID`=2); -- 122412 (Bound Voidlord) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=127911 AND `DifficultyID`=2); -- 127911 (Void-Blade Zedaat) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122401 AND `DifficultyID`=2); -- 122401 (Shadowguard Trickster) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=125981 AND `DifficultyID`=2); -- 125981 (Fragmented Voidling) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=61265 WHERE (`Entry`=122404 AND `DifficultyID`=2); -- 122404 (Shadowguard Voidbender) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122571 AND `DifficultyID`=2); -- 122571 (Rift Warden) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122407 AND `DifficultyID`=2); -- 122407 (Warp Stalker) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61265 WHERE (`Entry`=125493 AND `DifficultyID`=2); -- 125493 (Skyfin Juvenile) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122413 AND `DifficultyID`=2); -- 122413 (Shadowguard Riftstalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122421 AND `DifficultyID`=2); -- 122421 (Umbral War-Adept) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=61265 WHERE (`Entry`=122408 AND `DifficultyID`=2); -- 122408 (Shadow Stalker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122403 AND `DifficultyID`=2); -- 122403 (Shadowguard Champion) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=122410 AND `DifficultyID`=2); -- 122410 (Skyfin) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122056 AND `DifficultyID`=2); -- 122056 (Viceroy Nezhar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122482 AND `DifficultyID`=2); -- 122482 (Dark Aberration) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `VerifiedBuild`=61265 WHERE (`Entry`=122560 AND `DifficultyID`=2); -- 122560 (Shadow Stalker) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=122313 AND `DifficultyID`=2); -- 122313 (Zuraal the Ascended) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=124171 AND `DifficultyID`=2); -- 124171 (Shadowguard Subjugator) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122398 AND `DifficultyID`=2); -- 122398 (Sapped Voidlord) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122322 AND `DifficultyID`=2); -- 122322 (Famished Broken) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122478 AND `DifficultyID`=2); -- 122478 (Void Discharge) - CanSwim

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (127464,127448,127465,127450,127466,127451,128171,125504,125780,125493,125505,125495,125855));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(127464, 23, 0, 0, 337, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 127464 (Xal'atath) - 
(127448, 23, 0, 0, 337, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 127448 (Thal'kiel) - 
(127465, 23, 0, 0, 337, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 127465 (Xal'atath) - 
(127450, 23, 0, 0, 337, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 127450 (Thal'kiel) - 
(127466, 23, 0, 0, 337, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 127466 (Xal'atath) - 
(127451, 23, 0, 0, 337, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 127451 (Thal'kiel) - 
(128171, 23, 0, 0, 371, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 128171 (Void Shardling) - CanSwim, Floating
(125504, 23, 0, 0, 81, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125504 (Void Shardling) - Floating
(125780, 23, 0, 0, 773, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125780 (Generic Bunny) - 
(125493, 23, 0, 0, 81, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125493 (Skyfin Juvenile) - Floating
(125505, 23, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125505 (Chaotic Runoff) - 
(125495, 23, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 125495 (Voidstalker Runt) - 
(125855, 23, 0, 0, 81, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265); -- 125855 (Argus Moth) - Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=132858 WHERE (`Entry`=127464 AND `DifficultyID`=23); -- Xal'atath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=132842 WHERE (`Entry`=127448 AND `DifficultyID`=23); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=132859 WHERE (`Entry`=127465 AND `DifficultyID`=23); -- Xal'atath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=132844 WHERE (`Entry`=127450 AND `DifficultyID`=23); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=132860 WHERE (`Entry`=127466 AND `DifficultyID`=23); -- Xal'atath
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=132845 WHERE (`Entry`=127451 AND `DifficultyID`=23); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=133639 WHERE (`Entry`=128171 AND `DifficultyID`=23); -- Void Shardling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=130734 WHERE (`Entry`=125504 AND `DifficultyID`=23); -- Void Shardling
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=131067, `TypeFlags`=0x40000400 WHERE (`Entry`=125780 AND `DifficultyID`=23); -- Generic Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=130723 WHERE (`Entry`=125493 AND `DifficultyID`=23); -- Skyfin Juvenile
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=130725 WHERE (`Entry`=125495 AND `DifficultyID`=23); -- Voidstalker Runt
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=130735 WHERE (`Entry`=125505 AND `DifficultyID`=23); -- Chaotic Runoff
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=131148 WHERE (`Entry`=125855 AND `DifficultyID`=23); -- Argus Moth

UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000 WHERE (`Entry` IN (125104, 124266, 126211) AND `DifficultyID` = 23);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122423 AND `DifficultyID`=23); -- 122423 (Grand Shadow-Weaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122401 AND `DifficultyID`=23); -- 122401 (Shadowguard Trickster) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=124947 AND `DifficultyID`=23); -- 124947 (Void Flayer) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122405 AND `DifficultyID`=23); -- 122405 (Shadowguard Conjurer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=122404 AND `DifficultyID`=23); -- 122404 (Shadowguard Voidbender) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122412 AND `DifficultyID`=23); -- 122412 (Bound Voidlord) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=127911 AND `DifficultyID`=23); -- 127911 (Void-Blade Zedaat) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122571 AND `DifficultyID`=23); -- 122571 (Rift Warden) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122403 AND `DifficultyID`=23); -- 122403 (Shadowguard Champion) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122413 AND `DifficultyID`=23); -- 122413 (Shadowguard Riftstalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=122408 AND `DifficultyID`=23); -- 122408 (Shadow Stalker) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122421 AND `DifficultyID`=23); -- 122421 (Umbral War-Adept) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122056 AND `DifficultyID`=23); -- 122056 (Viceroy Nezhar) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=126283 AND `DifficultyID`=23); -- 126283 (Urjad) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122482 AND `DifficultyID`=23); -- 122482 (Dark Aberration) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=122560 AND `DifficultyID`=23); -- 122560 (Shadow Stalker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=122410 AND `DifficultyID`=23); -- 122410 (Skyfin) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x30000000, `VerifiedBuild`=61265 WHERE (`Entry`=122313 AND `DifficultyID`=23); -- 122313 (Zuraal the Ascended) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=124171 AND `DifficultyID`=23); -- 124171 (Shadowguard Subjugator) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122398 AND `DifficultyID`=23); -- 122398 (Sapped Voidlord) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122322 AND `DifficultyID`=23); -- 122322 (Famished Broken) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=122478 AND `DifficultyID`=23); -- 122478 (Void Discharge) - CanSwim

-- Path for Shadowguard Subjugator
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+84;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+84, @CGUID+84, 0, 0, 515, 0, 0),
(@CGUID+84, @CGUID+70, 4, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+84;
SET @ENTRY := 124171;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Subjugator - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5547.134, 10739.776, 20.112633, NULL, 0),
(@PATH, 1, 5525.488, 10729.68, 20.11308, NULL, 407),
(@PATH, 2, 5547.134, 10739.776, 20.112633, NULL, 0),
(@PATH, 3, 5574.2944, 10757.964, 20.113478, NULL, 0),
(@PATH, 4, 5583.645, 10779.497, 20.100603, NULL, 0),
(@PATH, 5, 5586.972, 10799.058, 20.11075, NULL, 0),
(@PATH, 6, 5586.8267, 10813.744, 20.111567, NULL, 0),
(@PATH, 7, 5570.723, 10835.62, 20.114004, NULL, 0),
(@PATH, 8, 5557.934, 10846.772, 20.521254, NULL, 0),
(@PATH, 9, 5532.693, 10857.732, 20.11155, NULL, 0),
(@PATH, 10, 5509.014, 10866.494, 20.111551, NULL, 0),
(@PATH, 11, 5479.4116, 10863.08, 20.111584, NULL, 0),
(@PATH, 12, 5459.9985, 10856.37, 20.111559, NULL, 30),
(@PATH, 13, 5479.4116, 10863.08, 20.111584, NULL, 0),
(@PATH, 14, 5509.014, 10866.494, 20.111551, NULL, 0),
(@PATH, 15, 5532.693, 10857.732, 20.11155, NULL, 0),
(@PATH, 16, 5557.934, 10846.772, 20.521254, NULL, 0),
(@PATH, 17, 5570.723, 10835.62, 20.114004, NULL, 0),
(@PATH, 18, 5586.8267, 10813.744, 20.111567, NULL, 0),
(@PATH, 19, 5586.972, 10799.058, 20.11075, NULL, 0),
(@PATH, 20, 5583.645, 10779.497, 20.100603, NULL, 0),
(@PATH, 21, 5574.2944, 10757.964, 20.113478, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shadowguard Subjugator
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+85;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+85, @CGUID+85, 0, 0, 515, 0, 0),
(@CGUID+85, @CGUID+65, 4, 40, 515, 2, 11),
(@CGUID+85, @CGUID+51, 4, 320, 515, 2, 11);

SET @MOVERGUID := @CGUID+85;
SET @ENTRY := 124171;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Subjugator - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5590.7344, 10788.53, 20.118088, NULL, 0),
(@PATH, 1, 5581.389, 10759.654, 20.113483, NULL, 0),
(@PATH, 2, 5572.993, 10747.565, 20.113077, NULL, 295),
(@PATH, 3, 5581.389, 10759.654, 20.113483, NULL, 0),
(@PATH, 4, 5590.7344, 10788.53, 20.118088, NULL, 0),
(@PATH, 5, 5594.5625, 10808.016, 20.11159, NULL, 0),
(@PATH, 6, 5579.585, 10831.498, 20.112381, NULL, 0),
(@PATH, 7, 5551.147, 10844.927, 20.394697, NULL, 0),
(@PATH, 8, 5537.928, 10862.732, 20.144264, NULL, 0),
(@PATH, 9, 5527.598, 10869.382, 20.11155, NULL, 0),
(@PATH, 10, 5510.9497, 10870.822, 20.11155, NULL, 0),
(@PATH, 11, 5484.772, 10867.573, 20.425707, NULL, 176),
(@PATH, 12, 5510.9497, 10870.822, 20.11155, NULL, 0),
(@PATH, 13, 5527.598, 10869.382, 20.11155, NULL, 0),
(@PATH, 14, 5537.928, 10862.732, 20.144264, NULL, 0),
(@PATH, 15, 5551.147, 10844.927, 20.394697, NULL, 0),
(@PATH, 16, 5579.585, 10831.498, 20.112381, NULL, 0),
(@PATH, 17, 5594.5625, 10808.016, 20.11159, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Famished Broken
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+4;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+4, @CGUID+4, 0, 0, 515, 0, 0),
(@CGUID+4, @CGUID+20, 4, 40, 515, 0, 0),
(@CGUID+4, @CGUID+17, 4, 320, 515, 0, 0);

SET @MOVERGUID := @CGUID+4;
SET @ENTRY := 122322;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Famished Broken - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5484.2007, 10781.258, 17.167398, NULL, 0),
(@PATH, 1, 5486.085, 10779.245, 17.167398, NULL, 0),
(@PATH, 2, 5492.626, 10777.029, 17.167398, NULL, 0),
(@PATH, 3, 5496.869, 10776.982, 17.167398, NULL, 0),
(@PATH, 4, 5500.9985, 10776.704, 17.167398, NULL, 0),
(@PATH, 5, 5504.808, 10776.187, 17.167398, NULL, 0),
(@PATH, 6, 5508.3213, 10775.597, 17.167398, NULL, 0),
(@PATH, 7, 5511.5, 10776.843, 17.167398, NULL, 0),
(@PATH, 8, 5514.563, 10778.196, 17.167398, NULL, 0),
(@PATH, 9, 5517.7754, 10779.504, 17.167398, NULL, 0),
(@PATH, 10, 5519.026, 10783.204, 17.167398, NULL, 0),
(@PATH, 11, 5519.8057, 10786.586, 17.164032, NULL, 0),
(@PATH, 12, 5520.693, 10790.172, 17.163553, NULL, 0),
(@PATH, 13, 5521.689, 10793.71, 17.166092, NULL, 0),
(@PATH, 14, 5522.778, 10797.223, 17.167908, NULL, 0),
(@PATH, 15, 5523.902, 10800.672, 17.168064, NULL, 0),
(@PATH, 16, 5524.796, 10804.189, 17.167398, NULL, 0),
(@PATH, 17, 5525.6143, 10807.714, 17.167398, NULL, 0),
(@PATH, 18, 5526.4385, 10811.289, 17.167398, NULL, 0),
(@PATH, 19, 5525.707, 10814.928, 17.167398, NULL, 0),
(@PATH, 20, 5524.012, 10818.264, 17.1669, NULL, 0),
(@PATH, 21, 5522.294, 10821.627, 17.165562, NULL, 0),
(@PATH, 22, 5517.951, 10824.189, 17.153595, NULL, 0),
(@PATH, 23, 5513.2173, 10823.167, 17.167398, NULL, 0),
(@PATH, 24, 5509.896, 10823.568, 17.167404, NULL, 0),
(@PATH, 25, 5506.383, 10824.501, 17.167406, NULL, 0),
(@PATH, 26, 5502.848, 10825.592, 17.167398, NULL, 0),
(@PATH, 27, 5499.4004, 10826.74, 17.167398, NULL, 0),
(@PATH, 28, 5495.877, 10825.808, 17.167398, NULL, 0),
(@PATH, 29, 5492.845, 10822.8, 17.167398, NULL, 0),
(@PATH, 30, 5490.183, 10819.907, 17.167398, NULL, 0),
(@PATH, 31, 5487.204, 10817.32, 17.167398, NULL, 0),
(@PATH, 32, 5484.034, 10814.96, 17.167398, NULL, 0),
(@PATH, 33, 5485.53, 10814.293, 17.167398, NULL, 0),
(@PATH, 34, 5483.8555, 10810.944, 17.167398, NULL, 0),
(@PATH, 35, 5482.896, 10807.266, 17.167398, NULL, 0),
(@PATH, 36, 5482, 10803.557, 17.167398, NULL, 0),
(@PATH, 37, 5481.0703, 10799.876, 17.167398, NULL, 0),
(@PATH, 38, 5481.21, 10797.478, 17.167398, NULL, 0),
(@PATH, 39, 5481.6196, 10793.585, 17.167398, NULL, 0),
(@PATH, 40, 5482.2847, 10789.963, 17.167398, NULL, 0),
(@PATH, 41, 5483.089, 10786.361, 17.1674, NULL, 0),
(@PATH, 42, 5484.2583, 10782.836, 17.167398, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Famished Broken
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+26;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+26, @CGUID+26, 0, 0, 515, 0, 0),
(@CGUID+26, @CGUID+38, 4, 40, 515, 0, 0),
(@CGUID+26, @CGUID+42, 4, 320, 515, 0, 0);

SET @MOVERGUID := @CGUID+26;
SET @ENTRY := 122322;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Famished Broken - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5521.7676, 10821.198, 17.16634, NULL, 0),
(@PATH, 1, 5500.6294, 10827.149, 17.167398, NULL, 0),
(@PATH, 2, 5484.5347, 10819.426, 17.167398, NULL, 0),
(@PATH, 3, 5477.172, 10793.203, 17.167398, NULL, 0),
(@PATH, 4, 5485.8696, 10780.439, 17.167398, NULL, 0),
(@PATH, 5, 5505.5723, 10776.033, 17.167398, NULL, 0),
(@PATH, 6, 5518.377, 10780.878, 17.167398, NULL, 0),
(@PATH, 7, 5523.855, 10797.091, 17.168652, NULL, 0),
(@PATH, 8, 5527.6875, 10812.454, 17.167397, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Famished Broken
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+95;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+95, @CGUID+95, 0, 0, 515, 0, 0),
(@CGUID+95, @CGUID+78, 4, 40, 515, 0, 0),
(@CGUID+95, @CGUID+91, 4, 320, 515, 0, 0);

SET @MOVERGUID := @CGUID+95;
SET @ENTRY := 122322;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Famished Broken - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5524.303, 10922.778, 10.290958, NULL, 0),
(@PATH, 1, 5510.6704, 10922.091, 10.943047, NULL, 0),
(@PATH, 2, 5495.127, 10923.68, 10.956851, NULL, 0),
(@PATH, 3, 5475.954, 10924.981, 9.593056, NULL, 0),
(@PATH, 4, 5467.993, 10916.099, 10.709787, NULL, 0),
(@PATH, 5, 5467.6196, 10903.418, 12.487696, NULL, 0),
(@PATH, 6, 5472.9087, 10893.04, 16.514975, NULL, 0),
(@PATH, 7, 5485.133, 10893.13, 17.23922, NULL, 0),
(@PATH, 8, 5491.5566, 10918.658, 12.936686, NULL, 0),
(@PATH, 9, 5513.366, 10916.136, 13.044166, NULL, 0),
(@PATH, 10, 5525.5254, 10908.218, 14.207041, NULL, 0),
(@PATH, 11, 5537.724, 10903.759, 16.656364, NULL, 0),
(@PATH, 12, 5545.3145, 10911.209, 12.115213, NULL, 0),
(@PATH, 13, 5539.9697, 10918.406, 10.5520935, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Void Channel Stalker
SET @MOVERGUID := @CGUID+139;
SET @ENTRY := 126211;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Void Channel Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5645.5747, 10692.918, 7.005354, NULL, 0),
(@PATH, 1, 5648.283, 10688.317, 6.869829, NULL, 0),
(@PATH, 2, 5655.7056, 10689.481, 6.7934494, NULL, 0),
(@PATH, 3, 5655.422, 10664.165, 6.2966933, NULL, 0),
(@PATH, 4, 5646.9956, 10658.776, 6.1653433, NULL, 0),
(@PATH, 5, 5646.9956, 10658.776, 6.1653433, NULL, 0),
(@PATH, 6, 5637.9443, 10659.238, 5.9130526, NULL, 0),
(@PATH, 7, 5637.369, 10665.959, 6.045182, NULL, 0),
(@PATH, 8, 5633.8257, 10667.547, 6.0473723, NULL, 0),
(@PATH, 9, 5635.384, 10673.03, 6.0068808, NULL, 0),
(@PATH, 10, 5633.585, 10680.729, 6.1411867, NULL, 0),
(@PATH, 11, 5636.502, 10688.238, 6.366224, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Void Channel Stalker
SET @MOVERGUID := @CGUID+227;
SET @ENTRY := 126211;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 1.8801, 'Void Channel Stalker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5786.3247, 10754.007, 15.546007, NULL, 0),
(@PATH, 1, 5782.1494, 10753.031, 20.496529, NULL, 0),
(@PATH, 2, 5780.297, 10753.138, 19.154514, NULL, 0),
(@PATH, 3, 5777.6875, 10753.123, 15.600695, NULL, 0),
(@PATH, 4, 5775.779, 10753.333, 6.5121527, NULL, 0),
(@PATH, 5, 5774.7017, 10756.547, 6.4230237, NULL, 0),
(@PATH, 6, 5778.1504, 10762.552, 6.8552103, NULL, 0),
(@PATH, 7, 5784.923, 10763.763, 7.444904, NULL, 0),
(@PATH, 8, 5787.4575, 10759.882, 8.623662, NULL, 0),
(@PATH, 9, 5787.0366, 10756.112, 10.524526, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Umbral War-Adept
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+241;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+241, @CGUID+241, 0, 0, 515, 0, 0),
(@CGUID+241, @CGUID+220, 4, 0, 515, 0, 0),
(@CGUID+241, @CGUID+228, 8, 10, 515, 0, 0),
(@CGUID+241, @CGUID+218, 8, 350, 515, 0, 0);

SET @MOVERGUID := @CGUID+241;
SET @ENTRY := 122421;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Umbral War-Adept - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5798.5063, 10720.573, 6.78291, NULL, 0),
(@PATH, 1, 5787.692, 10710.587, 5.955208, NULL, 0),
(@PATH, 2, 5785.7456, 10689.254, 5.271132, NULL, 0),
(@PATH, 3, 5767.905, 10674.491, 5.4581165, NULL, 0),
(@PATH, 4, 5747.0513, 10677.826, 5.2645583, NULL, 4362),
(@PATH, 5, 5767.905, 10674.491, 5.4581165, NULL, 0),
(@PATH, 6, 5785.7456, 10689.254, 5.271132, NULL, 0),
(@PATH, 7, 5787.692, 10710.587, 5.955208, NULL, 0),
(@PATH, 8, 5798.5063, 10720.573, 6.78291, NULL, 0),
(@PATH, 9, 5809.2476, 10733.155, 8.373151, NULL, 0),
(@PATH, 10, 5802.7944, 10762.346, 5.789566, NULL, 0),
(@PATH, 11, 5791.0625, 10782.357, 6.295975, NULL, 0),
(@PATH, 12, 5790.0635, 10782.396, 6.4532337, NULL, 0),
(@PATH, 13, 5789.0645, 10782.436, 6.610492, NULL, 0),
(@PATH, 14, 5788.0654, 10782.474, 6.7805004, NULL, 0),
(@PATH, 15, 5785.0684, 10782.59, 6.9635453, NULL, 0),
(@PATH, 16, 5780.073, 10782.782, 6.739551, NULL, 0),
(@PATH, 17, 5778.075, 10782.859, 6.4097767, NULL, 0),
(@PATH, 18, 5777.076, 10782.898, 6.205461, NULL, 0),
(@PATH, 19, 5775.078, 10782.975, 6.001146, NULL, 0),
(@PATH, 20, 5773.08, 10783.053, 5.445153, NULL, 0),
(@PATH, 21, 5771.082, 10783.129, 4.8631907, NULL, 0),
(@PATH, 22, 5767.086, 10783.283, 5.1142735, NULL, 0),
(@PATH, 23, 5742.7173, 10782.29, 5.401951, NULL, 0),
(@PATH, 24, 5731.139, 10805.241, 5.792185, NULL, 4241),
(@PATH, 25, 5742.7173, 10782.29, 5.401951, NULL, 0),
(@PATH, 26, 5767.069, 10783.285, 5.0943403, NULL, 0),
(@PATH, 27, 5790.046, 10782.398, 6.4404845, NULL, 0),
(@PATH, 28, 5802.7944, 10762.346, 5.789566, NULL, 0),
(@PATH, 29, 5809.2476, 10733.155, 8.373151, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Umbral War-Adept
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+370;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+370, @CGUID+370, 0, 0, 515, 0, 0),
(@CGUID+370, @CGUID+377, 4, 90, 515, 4, 10),
(@CGUID+370, @CGUID+376, 4, 270, 515, 4, 10);

SET @MOVERGUID := @CGUID+370;
SET @ENTRY := 122421;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Umbral War-Adept - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5971.9443, 10519.424, 14.015003, NULL, 0),
(@PATH, 1, 5945.8325, 10537.066, 12.086751, NULL, 0),
(@PATH, 2, 5911.1284, 10534.384, 8.663467, NULL, 0),
(@PATH, 3, 5883.8047, 10531.772, 14.3453045, NULL, 0),
(@PATH, 4, 5859.658, 10529.332, 16.434544, NULL, 267),
(@PATH, 5, 5883.8047, 10531.772, 14.3453045, NULL, 0),
(@PATH, 6, 5911.1284, 10534.384, 8.663467, NULL, 0),
(@PATH, 7, 5945.8325, 10537.066, 12.086751, NULL, 0),
(@PATH, 8, 5971.9443, 10519.424, 14.015003, NULL, 0),
(@PATH, 9, 5991.7334, 10510.197, 17.180231, NULL, 0),
(@PATH, 10, 6016.577, 10511.328, 17.109587, NULL, 166),
(@PATH, 11, 5991.7334, 10510.197, 17.180231, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shadowguard Riftstalker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+141;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+141, @CGUID+141, 0, 0, 515, 0, 0),
(@CGUID+141, @CGUID+167, 4, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+141;
SET @ENTRY := 122413;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Riftstalker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5626.7256, 10628.346, 5.5964475, NULL, 0),
(@PATH, 1, 5646.436, 10627.694, 5.43669, NULL, 0),
(@PATH, 2, 5663.508, 10642.044, 5.5288944, NULL, 0),
(@PATH, 3, 5683.856, 10659.004, 6.0937457, NULL, 0),
(@PATH, 4, 5708.863, 10671.131, 7.0250854, NULL, 0),
(@PATH, 5, 5683.856, 10659.004, 6.0937457, NULL, 0),
(@PATH, 6, 5663.508, 10642.044, 5.5288944, NULL, 0),
(@PATH, 7, 5646.436, 10627.694, 5.43669, NULL, 0),
(@PATH, 8, 5626.7256, 10628.346, 5.5964475, NULL, 0),
(@PATH, 9, 5613.489, 10636.821, 5.384872, NULL, 0),
(@PATH, 10, 5599.7847, 10621.557, 5.4315624, NULL, 0),
(@PATH, 11, 5587.635, 10609.417, 5.4307384, NULL, 0),
(@PATH, 12, 5599.7847, 10621.557, 5.4315624, NULL, 0),
(@PATH, 13, 5613.489, 10636.821, 5.384872, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shadowguard Riftstalker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+333;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+333, @CGUID+333, 0, 0, 515, 0, 0),
(@CGUID+333, @CGUID+335, 4, 0, 515, 0, 0),
(@CGUID+333, @CGUID+338, 8, 10, 515, 0, 0),
(@CGUID+333, @CGUID+337, 8, 350, 515, 0, 0);

SET @MOVERGUID := @CGUID+333;
SET @ENTRY := 122413;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Riftstalker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5948.0034, 10657.29, 13.368997, NULL, 0),
(@PATH, 1, 5961.721, 10650.189, 13.1711, NULL, 0),
(@PATH, 2, 5969.6494, 10640.271, 12.689367, NULL, 0),
(@PATH, 3, 5993.501, 10609.87, 16.086176, NULL, 0),
(@PATH, 4, 5973.764, 10587.231, 15.412764, NULL, 0),
(@PATH, 5, 5944.6597, 10584.456, 16.17963, NULL, 0),
(@PATH, 6, 5928.8633, 10602.515, 14.040958, NULL, 0),
(@PATH, 7, 5918.3716, 10631.661, 13.504726, NULL, 0),
(@PATH, 8, 5922.085, 10640.007, 13.524205, NULL, 0),
(@PATH, 9, 5925.752, 10645.943, 13.536765, NULL, 0),
(@PATH, 10, 5933.7993, 10652.072, 13.527929, NULL, 0),
(@PATH, 11, 5902.7876, 10616.967, 12.981399, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shadowguard Champion
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+301;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+301, @CGUID+301, 0, 0, 515, 0, 0),
(@CGUID+301, @CGUID+305, 4, 10, 515, 0, 0),
(@CGUID+301, @CGUID+306, 4, 350, 515, 0, 0);

SET @MOVERGUID := @CGUID+301;
SET @ENTRY := 122403;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Champion - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5825.46, 10640.185, 7.2846756, NULL, 0),
(@PATH, 1, 5789.1284, 10650.174, 5.313901, NULL, 0),
(@PATH, 2, 5777.2095, 10658.167, 5.2645435, NULL, 0),
(@PATH, 3, 5777.2354, 10666.138, 5.2645435, NULL, 0),
(@PATH, 4, 5788.875, 10664.955, 5.325177, NULL, 0),
(@PATH, 5, 5806.4834, 10653.459, 5.8433867, NULL, 0),
(@PATH, 6, 5827.8887, 10645.036, 7.481103, NULL, 0),
(@PATH, 7, 5842.2656, 10646.986, 10.611318, NULL, 0),
(@PATH, 8, 5872.6406, 10647.732, 11.749607, NULL, 0),
(@PATH, 9, 5894.9956, 10637.66, 12.68732, NULL, 0),
(@PATH, 10, 5909.817, 10627.304, 13.187662, NULL, 0),
(@PATH, 11, 5908.213, 10599.759, 14.284409, NULL, 0),
(@PATH, 12, 5908.0127, 10599.358, 14.391315, NULL, 0),
(@PATH, 13, 5907.8125, 10598.958, 14.498222, NULL, 0),
(@PATH, 14, 5907.8125, 10597.916, 14.622435, NULL, 0),
(@PATH, 15, 5906.4907, 10595.833, 14.852663, NULL, 0),
(@PATH, 16, 5906.25, 10596.875, 14.693599, NULL, 0),
(@PATH, 17, 5904.166, 10596.875, 14.739505, NULL, 0),
(@PATH, 18, 5902.083, 10596.875, 14.805161, NULL, 0),
(@PATH, 19, 5900, 10596.875, 14.867798, NULL, 0),
(@PATH, 20, 5897.916, 10596.875, 14.989789, NULL, 0),
(@PATH, 21, 5895.833, 10596.875, 15.108572, NULL, 0),
(@PATH, 22, 5893.75, 10596.875, 15.287323, NULL, 0),
(@PATH, 23, 5891.666, 10596.875, 15.446679, NULL, 0),
(@PATH, 24, 5890.674, 10596.751, 15.642207, NULL, 0),
(@PATH, 25, 5887.6973, 10596.379, 15.884834, NULL, 0),
(@PATH, 26, 5883.333, 10595.833, 16.057524, NULL, 0),
(@PATH, 27, 5877.333, 10595.833, 15.87579, NULL, 0),
(@PATH, 28, 5875, 10595.833, 15.721196, NULL, 0),
(@PATH, 29, 5872.6953, 10596.432, 15.525087, NULL, 0),
(@PATH, 30, 5859.9585, 10610.438, 13.77681, NULL, 0),
(@PATH, 31, 5865.9595, 10624.663, 12.306669, NULL, 0),
(@PATH, 32, 5870.671, 10640.864, 11.910952, NULL, 0),
(@PATH, 33, 5848.1587, 10640.449, 10.552026, NULL, 0);

UPDATE `creature` SET `position_x`=5825.46, `position_y`=10640.185, `position_z`=7.2846756 WHERE `guid` IN (@CGUID+305, @CGUID+306);
UPDATE `creature` SET `position_x`=5825.46, `position_y`=10640.185, `position_z`=7.2846756, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shadowguard Champion
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+349;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+349, @CGUID+349, 0, 0, 515, 0, 0),
(@CGUID+349, @CGUID+342, 4, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+349;
SET @ENTRY := 122403;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Champion - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5851.482, 10518.624, 16.180882, NULL, 0),
(@PATH, 1, 5860.644, 10543.046, 17.116238, NULL, 0),
(@PATH, 2, 5873.1973, 10563.433, 14.391741, NULL, 0),
(@PATH, 3, 5892.3223, 10575.404, 14.418362, NULL, 0),
(@PATH, 4, 5917.1953, 10577.842, 15.150321, NULL, 0),
(@PATH, 5, 5944.705, 10575.729, 16.894146, NULL, 0),
(@PATH, 6, 5952.749, 10562.104, 11.121536, NULL, 0),
(@PATH, 7, 5926.514, 10556.678, 14.12022, NULL, 0),
(@PATH, 8, 5904.691, 10537.216, 9.436149, NULL, 0),
(@PATH, 9, 5888.768, 10513.386, 11.436992, NULL, 0),
(@PATH, 10, 5875.074, 10496.88, 9.497419, NULL, 0),
(@PATH, 11, 5874.3394, 10497.558, 9.998404, NULL, 0),
(@PATH, 12, 5873.6045, 10498.235, 10.499388, NULL, 0),
(@PATH, 13, 5870.663, 10500.946, 11.3550415, NULL, 0),
(@PATH, 14, 5869.9277, 10501.624, 12.200584, NULL, 0),
(@PATH, 15, 5869.1924, 10502.302, 13.89131, NULL, 0),
(@PATH, 16, 5866.9863, 10504.335, 14.187188, NULL, 0),
(@PATH, 17, 5865.5156, 10505.69, 14.409327, NULL, 0),
(@PATH, 18, 5863.3096, 10507.724, 14.737329, NULL, 0),
(@PATH, 19, 5861.1035, 10509.757, 15.063248, NULL, 0),
(@PATH, 20, 5858.8975, 10511.79, 15.358144, NULL, 0),
(@PATH, 21, 5856.6914, 10513.823, 15.617209, NULL, 0),
(@PATH, 22, 5854.4854, 10515.856, 15.863611, NULL, 0),
(@PATH, 23, 5853.0146, 10517.212, 16.039257, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shadowguard Champion
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+558;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+558, @CGUID+558, 0, 0, 515, 0, 0),
(@CGUID+558, @CGUID+364, 4, 10, 515, 0, 0),
(@CGUID+558, @CGUID+363, 4, 350, 515, 0, 0);

SET @MOVERGUID := @CGUID+558;
SET @ENTRY := 122403;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Champion - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5998.019, 10701.459, 15.797149, NULL, 0),
(@PATH, 1, 5991.125, 10683.2, 14.447688, NULL, 0),
(@PATH, 2, 5984.521, 10677.576, 14.164192, NULL, 0),
(@PATH, 3, 5975.56, 10681.497, 14.501272, NULL, 0),
(@PATH, 4, 5970.684, 10691.064, 14.377489, NULL, 0),
(@PATH, 5, 5974.059, 10699.98, 13.98828, NULL, 0),
(@PATH, 6, 5974.3955, 10714.973, 11.519441, NULL, 0),
(@PATH, 7, 5966.7085, 10731.63, 9.114838, NULL, 0),
(@PATH, 8, 5977.085, 10738.139, 7.7411265, NULL, 0),
(@PATH, 9, 5994.2476, 10743.872, 4.4747863, NULL, 0),
(@PATH, 10, 5994.421, 10742.887, 4.7327404, NULL, 0),
(@PATH, 11, 5994.7666, 10740.918, 5.4975996, NULL, 0),
(@PATH, 12, 5994.9395, 10739.933, 5.741297, NULL, 0),
(@PATH, 13, 5995.458, 10736.979, 6.666846, NULL, 0),
(@PATH, 14, 5995.8037, 10735.008, 7.193161, NULL, 0),
(@PATH, 15, 5995.9766, 10734.023, 7.4066205, NULL, 0),
(@PATH, 16, 5996.3223, 10732.054, 7.9298763, NULL, 0),
(@PATH, 17, 5996.668, 10730.084, 8.455428, NULL, 0),
(@PATH, 18, 5996.841, 10729.1, 8.710713, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Shadowguard Voidbender
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+385;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+385, @CGUID+385, 0, 0, 515, 0, 0),
(@CGUID+385, @CGUID+392, 4, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+385;
SET @ENTRY := 122404;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Shadowguard Voidbender - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5954.366, 10486.783, 19.983624, NULL, 4137),
(@PATH, 1, 5967.1245, 10482.092, 20.934425, NULL, 0),
(@PATH, 2, 5993.3647, 10469.576, 20.113848, NULL, 0),
(@PATH, 3, 5987.921, 10448.599, 18.937664, NULL, 0),
(@PATH, 4, 5999.137, 10436.106, 19.312859, NULL, 0),
(@PATH, 5, 6026.369, 10437.674, 21.118582, NULL, 0),
(@PATH, 6, 6045.093, 10430.683, 20.626287, NULL, 4799),
(@PATH, 7, 6026.369, 10437.674, 21.118582, NULL, 0),
(@PATH, 8, 5999.137, 10436.106, 19.312859, NULL, 0),
(@PATH, 9, 5987.921, 10448.599, 18.937664, NULL, 0),
(@PATH, 10, 5993.3647, 10469.576, 20.113848, NULL, 0),
(@PATH, 11, 5967.2554, 10482.044, 20.93524, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Skyfin
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+242;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+242, @CGUID+242, 0, 0, 515, 0, 0),
(@CGUID+242, @CGUID+140, 6, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+242;
SET @ENTRY := 122410;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.8449, 'Skyfin - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5772.5723, 10368.618, 17.028917, NULL, 0),
(@PATH, 1, 5789.943, 10415.558, 17.028917, NULL, 0),
(@PATH, 2, 5789.8228, 10501.936, 19.826876, NULL, 0),
(@PATH, 3, 5741.972, 10558.143, 23.106363, NULL, 0),
(@PATH, 4, 5706.4673, 10589.33, 17.028917, NULL, 0),
(@PATH, 5, 5675.0913, 10572.224, 17.028917, NULL, 0),
(@PATH, 6, 5617.397, 10521.868, 17.028917, NULL, 0),
(@PATH, 7, 5589.7065, 10417.048, 17.028917, NULL, 0),
(@PATH, 8, 5666.796, 10345.323, 17.028917, NULL, 0),
(@PATH, 9, 5729.6963, 10332.306, 17.280844, NULL, 0),
(@PATH, 10, 5731.134, 10332.603, 17.028917, NULL, 0);

UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Skyfin
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+330;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+330, @CGUID+330, 0, 0, 515, 0, 0),
(@CGUID+330, @CGUID+329, 6, 90, 515, 0, 0),
(@CGUID+330, @CGUID+169, 6, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+330;
SET @ENTRY := 122410;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.7774, 'Skyfin - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5875.632, 10468.181, 72.78422, NULL, 0),
(@PATH, 1, 5952.8853, 10550.536, 84.88412, NULL, 0),
(@PATH, 2, 5947.0415, 10655.458, 76.07419, NULL, 0),
(@PATH, 3, 5773.2725, 11035.038, 81.430214, NULL, 0),
(@PATH, 4, 5704.752, 11075.232, 81.430214, NULL, 0),
(@PATH, 5, 5590.71, 11018.71, 81.430214, NULL, 0),
(@PATH, 6, 5457.855, 10874.02, 81.430214, NULL, 0),
(@PATH, 7, 5436.9243, 10714.403, 67.118385, NULL, 0),
(@PATH, 8, 5477.0244, 10540.925, 60.977444, NULL, 0),
(@PATH, 9, 5537.953, 10409.908, 81.430214, NULL, 0),
(@PATH, 10, 5651.455, 10329.223, 81.430214, NULL, 0),
(@PATH, 11, 5767.8115, 10386.974, 81.430214, NULL, 0),
(@PATH, 12, 5814.9385, 10434.997, 82.98849, NULL, 0),
(@PATH, 13, 5816.2803, 10436.026, 82.93512, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Skyfin
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+126;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+126, @CGUID+126, 0, 0, 515, 0, 0),
(@CGUID+126, @CGUID+127, 6, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+126;
SET @ENTRY := 122410;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 9.8082, 'Skyfin - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5552.619, 10634.909, 39.84834, NULL, 0),
(@PATH, 1, 5453.03, 10673.66, 39.84834, NULL, 0),
(@PATH, 2, 5401.455, 10722.042, 39.84834, NULL, 0),
(@PATH, 3, 5371.191, 10799.084, 39.84834, NULL, 0),
(@PATH, 4, 5396.6304, 10873.929, 39.84834, NULL, 0),
(@PATH, 5, 5470.7275, 10928.123, 39.84834, NULL, 0),
(@PATH, 6, 5539.9697, 10918.876, 39.84834, NULL, 0),
(@PATH, 7, 5676.797, 10895.212, 63.582466, NULL, 0),
(@PATH, 8, 5731.5444, 10807.254, 59.03921, NULL, 0),
(@PATH, 9, 5754.018, 10701.699, 48.15163, NULL, 0),
(@PATH, 10, 5785.559, 10637.188, 51.68166, NULL, 0),
(@PATH, 11, 5735.268, 10546.412, 52.858406, NULL, 0),
(@PATH, 12, 5679.2056, 10532.643, 52.858406, NULL, 0),
(@PATH, 13, 5605.5825, 10572.884, 39.898148, NULL, 0),
(@PATH, 14, 5600.2935, 10578.16, 39.84834, NULL, 0);

UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Skyfin Juvenile
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+170;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+170, @CGUID+170, 0, 0, 515, 0, 0),
(@CGUID+170, @CGUID+175, 6, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+170;
SET @ENTRY := 125493;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.5512, 'Skyfin Juvenile - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5686.6787, 10679.643, 7.569285, NULL, 0),
(@PATH, 1, 5692.3354, 10677.3, 7.9719324, NULL, 0),
(@PATH, 2, 5694.6787, 10671.643, 8.315542, NULL, 0),
(@PATH, 3, 5692.3354, 10665.985, 8.022724, NULL, 0),
(@PATH, 4, 5686.727, 10663.787, 7.8009033, NULL, 0),
(@PATH, 5, 5681.022, 10665.985, 7.4411764, NULL, 0),
(@PATH, 6, 5678.6787, 10671.643, 7.7161646, NULL, 0),
(@PATH, 7, 5681.022, 10677.3, 7.596936, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Skyfin Juvenile
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+283;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+283, @CGUID+283, 0, 0, 515, 0, 0),
(@CGUID+283, @CGUID+290, 6, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+283;
SET @ENTRY := 125493;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.5527, 'Skyfin Juvenile - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5852.066, 10866.631, -55.48785, NULL, 0),
(@PATH, 1, 5862.6724, 10862.237, -55.48785, NULL, 0),
(@PATH, 2, 5867.066, 10851.631, -55.48785, NULL, 0),
(@PATH, 3, 5862.6724, 10841.024, -55.48785, NULL, 0),
(@PATH, 4, 5852.066, 10836.631, -55.48785, NULL, 0),
(@PATH, 5, 5841.4595, 10841.024, -55.48785, NULL, 0),
(@PATH, 6, 5837.066, 10851.631, -55.48785, NULL, 0),
(@PATH, 7, 5841.4595, 10862.237, -55.48785, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
