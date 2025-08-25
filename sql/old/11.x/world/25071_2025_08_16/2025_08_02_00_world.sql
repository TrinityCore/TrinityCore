SET @CGUID := 8000073;
SET @OGUID := 8000047;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+754;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3934.854248046875, -1153.7291259765625, 69.1924591064453125, 3.62255096435546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+1, 180617, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3928.412353515625, -1160.0972900390625, 69.19268798828125, 4.000652790069580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Scoundrel (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+2, 180618, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3934.637939453125, -1160.9097900390625, 69.18817138671875, 1.653245091438293457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Negotiator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+3, 176445, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3931.598876953125, -1123.732666015625, 63.14185714721679687, 2.81323552131652832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Au'myza (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+4, 180618, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3935.62841796875, -1159.5816650390625, 69.19305419921875, 2.305568218231201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Negotiator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+5, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3600.60595703125, -766.2742919921875, 107.0248489379882812, 1.516027331352233886, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+6, 180336, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3737.8984375, -1380.513916015625, 73.8152313232421875, 2.649179935455322265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Wiseguy (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+7, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3733.529541015625, -1379.642333984375, 73.8152313232421875, 0.007587878499180078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+8, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3735.880126953125, -1376.935791015625, 74.00861358642578125, 4.216318607330322265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+9, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3751.903564453125, -1386.2535400390625, 73.8152313232421875, 3.414920806884765625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+10, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3749.096435546875, -1383.3350830078125, 73.8152313232421875, 4.125844955444335937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+11, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3745.951416015625, -1388.9271240234375, 73.8152313232421875, 0.702390611171722412, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+12, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3750.1640625, -1388.63720703125, 73.8152313232421875, 1.843027830123901367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+13, 179982, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3616.7890625, -1793.0677490234375, 92.56435394287109375, 3.289362907409667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+14, 180152, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3643.06689453125, -1804.2257080078125, 92.5643463134765625, 5.461966514587402343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipping Facilitator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+15, 97809, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3621.107666015625, -1813.5242919921875, 108.0196533203125, 1.007775306701660156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Coastal Seagull (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+16, 180153, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3641.1640625, -1798.3853759765625, 92.5643463134765625, 3.683759450912475585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Aqir Impaler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356251 - Hyperlight Containment Cell)
(@CGUID+17, 180510, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3640.748291015625, -1801.3038330078125, 92.5643463134765625, 4.948251247406005859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Toxic Saurid (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 357798 - Hyperlight Containment Cell)
(@CGUID+18, 97809, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3620.338623046875, -1810.80908203125, 104.18243408203125, 0.438014894723892211, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Coastal Seagull (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+19, 180129, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3645.1103515625, -1778.2135009765625, 92.03133392333984375, 6.078980445861816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Toy Vendor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+20, 180322, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3642.757080078125, -1807.732666015625, 92.56435394287109375, 4.3490447998046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Fe'tajid (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 357022 - [DNT] Aura Update Interact)
(@CGUID+21, 97809, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3620.767333984375, -1808.6632080078125, 101.9918060302734375, 5.869781494140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Coastal Seagull (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+22, 179366, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3656.3359375, -1840.4600830078125, 92.55585479736328125, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Damp Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+23, 180510, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3643.5947265625, -1801.30908203125, 92.56435394287109375, 4.142350673675537109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Toxic Saurid (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 357798 - Hyperlight Containment Cell)
(@CGUID+24, 97809, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.953125, -1813.201416015625, 105.5008163452148437, 2.084697961807250976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Coastal Seagull (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+26, 179982, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.0625, -1781.3992919921875, 92.65445709228515625, 0.280170410871505737, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+27, 179983, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3614.846435546875, -1782.7569580078125, 92.56435394287109375, 2.647449493408203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dozing Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+28, 97809, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3627.349853515625, -1825.279541015625, 96.225860595703125, 1.781016111373901367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Coastal Seagull (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+29, 180152, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3649.0625, -1821.359375, 92.56435394287109375, 1.122935175895690917, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipping Facilitator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+30, 97809, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.458251953125, -1811.548583984375, 101.9918060302734375, 1.152400970458984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Coastal Seagull (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+31, 179982, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3617.572998046875, -1794.4774169921875, 92.56435394287109375, 4.326544761657714843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+33, 179011, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3622.0546875, -1804.77783203125, 92.5643463134765625, 4.554454326629638671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipping Facilitator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 353213 - Broker Carry Box Aura)
(@CGUID+34, 179982, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3605.577392578125, -1773.1822509765625, 92.5643463134765625, 0.984280347824096679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+35, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3603.66748046875, -1756.732666015625, 92.55731201171875, 4.955693244934082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+36, 179519, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.69970703125, -1639.404541015625, 106.20904541015625, 0.325696080923080444, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Al'dalil (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+37, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3613.51123046875, -1756.69970703125, 92.55860137939453125, 4.955693244934082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+38, 179982, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3608.015625, -1778.986083984375, 92.5643463134765625, 0.400995343923568725, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+39, 178074, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3610.853271484375, -1770.73095703125, 92.5643463134765625, 1.661841750144958496, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Al'dalil (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: )
(@CGUID+40, 178392, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3609.622314453125, -1761.68408203125, 92.56238555908203125, 4.548117637634277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Gatewarden Zo'mazz (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+41, 179983, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3607.092041015625, -1776.2447509765625, 92.5643463134765625, 0.368400394916534423, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dozing Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+42, 180056, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3630.16845703125, -1824.279541015625, 92.5643463134765625, 4.155396461486816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Empty Hyperspatial Container (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356251 - Hyperlight Containment Cell)
(@CGUID+43, 180056, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3631.44091796875, -1826.5885009765625, 92.5643463134765625, 2.264796972274780273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Empty Hyperspatial Container (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356256 - Hyperspatial Containment Chamber)
(@CGUID+44, 180130, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3652.572021484375, -1787.6163330078125, 91.8899078369140625, 3.042220592498779296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Antique Vendor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+45, 180056, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3629.3447265625, -1823.2864990234375, 92.5643463134765625, 4.842125415802001953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Empty Hyperspatial Container (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356251 - Hyperlight Containment Cell)
(@CGUID+46, 179983, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3627.5625, -1818.8992919921875, 92.5643463134765625, 1.07511913776397705, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dozing Laborer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+47, 180056, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3629.12939453125, -1821.748291015625, 92.5643463134765625, 4.142350673675537109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Empty Hyperspatial Container (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356251 - Hyperlight Containment Cell)
(@CGUID+48, 179981, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.81689453125, -1789.4375, 92.56435394287109375, 4.141889095306396484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Chef (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+49, 176758, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3371.622314453125, -1292.2430419921875, 78.53295135498046875, 0.541052043437957763, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'noc (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+50, 176759, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3361.947021484375, -1276.3160400390625, 78.5329437255859375, 0.581203997135162353, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'nam (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+51, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3637.6181640625, -1792.3541259765625, 92.5643463134765625, 2.09002852439880371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+52, 180056, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3628.697998046875, -1824.19970703125, 92.5643463134765625, 3.572867155075073242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Empty Hyperspatial Container (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356251 - Hyperlight Containment Cell)
(@CGUID+53, 180117, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3617.072021484375, -1798.02783203125, 92.5643463134765625, 1.368078112602233886, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Meat Vendor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+54, 180056, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3627.356689453125, -1821.3853759765625, 92.5643463134765625, 2.001295328140258789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Empty Hyperspatial Container (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356251 - Hyperlight Containment Cell)
(@CGUID+55, 180114, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3613.177001953125, -1794.9288330078125, 92.56435394287109375, 0.478609472513198852, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Fruit Vendor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+56, 180156, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3636.61279296875, -1789.5069580078125, 92.5643463134765625, 5.313712596893310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Enthusiastic Trader (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+57, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3616.079833984375, -1700.10595703125, 106.0837860107421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+58, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3610.2197265625, -1645.90625, 106.20928955078125, 3.01908731460571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+59, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3590.14501953125, -1687.3055419921875, 106.20928955078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+60, 177816, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3640.368896484375, -1654.8646240234375, 106.2564620971679687, 5.2774200439453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Interrogation Specialist (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+61, 177817, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3644.359375, -1654.4254150390625, 106.2090530395507812, 4.243859767913818359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Support Officer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355980 - Refraction Shield, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+62, 180824, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3640.233642578125, -1665.173583984375, 106.1735992431640625, 1.131021022796630859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Waffle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+63, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3624.5810546875, -1640.0013427734375, 106.2028045654296875, 1.237087488174438476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+64, 177817, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3628.36279296875, -1677.763916015625, 106.20904541015625, 4.0172271728515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Support Officer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355980 - Refraction Shield, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+65, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3664.9375, -1662.5242919921875, 106.20904541015625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+66, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3630.484375, -1660.234375, 106.2090530395507812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+67, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3672.017333984375, -1652.62158203125, 106.2090530395507812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+68, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3598.818603515625, -1668.076416015625, 106.2645034790039062, 0.752283334732055664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+69, 177239, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3638.243896484375, -1681.9478759765625, 106.626953125, 3.2017364501953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Collector of Worth (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+70, 178545, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3662.03564453125, -1671.2569580078125, 109.6516189575195312, 1.875281929969787597, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Watch-Agent Summon Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+71, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3625.15283203125, -1681.6319580078125, 106.2090530395507812, 0.812655091285705566, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+72, 177255, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3593.357666015625, -1654.8316650390625, 106.083648681640625, 5.17529916763305664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Contraband Auctioneer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+73, 177255, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3601.239501953125, -1639.3021240234375, 106.08685302734375, 0.0054626758210361, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Contraband Auctioneer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+74, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3590.4384765625, -1675.765625, 106.20928955078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+75, 177817, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3624.586181640625, -1640.881591796875, 106.2024917602539062, 0.608290016651153564, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Support Officer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355980 - Refraction Shield, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+76, 179334, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3671.932373046875, -1639.2291259765625, 106.2093048095703125, 6.271966934204101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Portalmancer Zo'honn (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356319 - Rename Spawn Spell, 355784 - [DNT] Send Event <Points> On Enter Combat, 352411 - Stabilize Portal)
(@CGUID+77, 177816, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3601.763916015625, -1664.796875, 106.20928955078125, 3.994011163711547851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Interrogation Specialist (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+78, 177808, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3625.82421875, -1640.0194091796875, 106.0936126708984375, 0.608297705650329589, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Armored Overseer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat, 323486 - Dual Wield)
(@CGUID+79, 179121, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3682.59716796875, -1639.2083740234375, 109.3067474365234375, 3.194427728652954101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Zo'phex Cosmetic Summon Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+80, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3642.993896484375, -1657.060791015625, 106.2090530395507812, 1.923279047012329101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+81, 178545, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3674.3046875, -1668.263916015625, 109.3335189819335937, 1.875281929969787597, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Watch-Agent Summon Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+82, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3642.125, -1623.44970703125, 106.2090530395507812, 4.404960155487060546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+83, 177255, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3593.80029296875, -1622.8507080078125, 106.4381790161132812, 1.149910330772399902, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Contraband Auctioneer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+84, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3591.572998046875, -1592.7135009765625, 106.2561492919921875, 1.077340245246887207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+85, 177816, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3617.9775390625, -1595.017333984375, 106.0837860107421875, 5.2774200439453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Interrogation Specialist (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+86, 177808, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3615.681396484375, -1563.27783203125, 106.0838088989257812, 5.012495040893554687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Armored Overseer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 323486 - Dual Wield)
(@CGUID+87, 178545, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3661.87841796875, -1607.4947509765625, 109.2349624633789062, 4.698956489562988281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Watch-Agent Summon Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+88, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3629.5546875, -1590.217041015625, 106.2090530395507812, 0.471558481454849243, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+89, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3610.36376953125, -1633.5833740234375, 106.20928955078125, 2.508206605911254882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+90, 177259, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3637.6025390625, -1596.7760009765625, 106.2014236450195312, 3.348679542541503906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Zo'pare (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+91, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3596.984375, -1590.9774169921875, 106.0837860107421875, 2.741656064987182617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+92, 177816, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3641.541748046875, -1618.451416015625, 106.2090530395507812, 4.860768795013427734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Interrogation Specialist (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+93, 177817, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3645.861083984375, -1621.407958984375, 106.2090530395507812, 3.743829011917114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Support Officer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355980 - Refraction Shield)
(@CGUID+94, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3586.704833984375, -1592.7586669921875, 106.20928955078125, 2.016007661819458007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+95, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3602.29248046875, -1612.4722900390625, 106.20928955078125, 2.602420330047607421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+96, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.658935546875, -1623.5382080078125, 106.20928955078125, 2.832314491271972656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+97, 177807, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3620.28466796875, -1598.7708740234375, 106.3189620971679687, 2.035692691802978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customs Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+98, 179367, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3586.05517578125, -1596.3507080078125, 106.0811767578125, 0.878203034400939941, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+99, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3672.421875, -1628.1978759765625, 106.20904541015625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+100, 177817, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3596.1416015625, -1611.109375, 106.2386474609375, 5.985050201416015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Support Officer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355980 - Refraction Shield, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+101, 178545, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3674.299560546875, -1610.9478759765625, 109.6873245239257812, 4.698956489562988281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Watch-Agent Summon Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+102, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.811767578125, -1606.87158203125, 106.1203689575195312, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+103, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3665.17529296875, -1616.4757080078125, 106.2090530395507812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+104, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3607.2822265625, -1638.4305419921875, 106.20928955078125, 3.078369140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+105, 177672, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3631.155517578125, -1598.46875, 106.2090530395507812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Terminal Attendant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+106, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3663.912353515625, -1533.0052490234375, 93.33356475830078125, 5.087529182434082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+107, 179366, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3691.949951171875, -1555.3505859375, 93.273468017578125, 1.881445765495300292, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Damp Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+108, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3665.568603515625, -1535.13720703125, 93.33356475830078125, 2.148313760757446289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+109, 179367, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3661.0546875, -1528.882080078125, 93.39371490478515625, 2.576822519302368164, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+110, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3621.857666015625, -1538.7882080078125, 106.0886993408203125, 6.097062110900878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+111, 178074, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3427.809814453125, -1259.595458984375, 73.708587646484375, 3.63863682746887207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Al'dalil (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+112, 179168, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3590.20947265625, -1523.7445068359375, 106.240203857421875, 1.026233553886413574, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+113, 180161, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3700.14404296875, -1552.9739990234375, 93.33356475830078125, 3.12364816665649414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shopkeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356570 - [DNT] Aura Vendor AreaTrigger)
(@CGUID+114, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3624.545166015625, -1538.5242919921875, 106.08868408203125, 3.157846927642822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+115, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3666.045166015625, -1532.8350830078125, 93.33356475830078125, 3.636849403381347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+116, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3670.322021484375, -1549.296875, 93.33356475830078125, 3.227079153060913085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+117, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3588.07373046875, -1547.9757080078125, 106.0887527465820312, 5.97483062744140625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356716 - Reading)
(@CGUID+118, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3672.3291015625, -1552.984375, 93.33356475830078125, 4.066779136657714843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+119, 177808, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3603.875, -1563.84033203125, 106.0838088989257812, 4.98528146743774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Armored Overseer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 323486 - Dual Wield)
(@CGUID+120, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3584.2109375, -1527.48095703125, 106.0887527465820312, 3.636849403381347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+121, 180267, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3670.223876953125, -1555.263916015625, 93.33356475830078125, 0.765398859977722167, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ta'rex (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+122, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3637.283935546875, -1537.2569580078125, 106.0886383056640625, 1.448504447937011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+123, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3582.078125, -1527.6510009765625, 106.0887527465820312, 5.087529182434082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+124, 180754, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3653.109375, -1561.623291015625, 93.33356475830078125, 1.475718855857849121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Questionable Trader (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+125, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3583.734375, -1529.782958984375, 106.0887527465820312, 2.148313760757446289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+126, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3622.60009765625, -1536.067626953125, 106.1961212158203125, 1.979505062103271484, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+127, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3593.116455078125, -1522.6729736328125, 106.26495361328125, 5.374419212341308593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356711 - Haulin)
(@CGUID+128, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3639.381103515625, -1535.736083984375, 106.088623046875, 4.015954017639160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+129, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3680.96875, -1556.703125, 93.33356475830078125, 4.766122817993164062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+130, 178074, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3718.95849609375, -1222.636474609375, 73.8752288818359375, 4.250856876373291015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Al'dalil (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+131, 180269, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3662.265380859375, -1499.2978515625, 93.2843017578125, 5.069691181182861328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curiosity (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+132, 180244, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3629.70703125, -1492.194580078125, 93.55588531494140625, 6.136537075042724609, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Culinary Assistant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356762 - [DNT] Carry Food Stuffs) (possible waypoints or random movement)
(@CGUID+133, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3585.730712890625, -1499.809326171875, 93.3192291259765625, 4.823344707489013671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356711 - Haulin)
(@CGUID+134, 180249, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3617.502685546875, -1493.96875, 93.2843017578125, 0.024576056748628616, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356765 - [DNT] Serve Food)
(@CGUID+135, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3687.607666015625, -1518.4149169921875, 93.6543121337890625, 6.260349273681640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+136, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3605.818603515625, -1505.0867919921875, 106.0887527465820312, 0.942640244960784912, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356716 - Reading)
(@CGUID+137, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3581.5703125, -1510.28125, 93.33356475830078125, 2.001769781112670898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356756 - [DNT] Carry Stuff)
(@CGUID+138, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3689.908935546875, -1511.732666015625, 93.33356475830078125, 2.148313760757446289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+139, 180249, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.588623046875, -1496.1961669921875, 94.98777008056640625, 5.573925495147705078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+140, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3576.1025390625, -1511.84033203125, 93.33356475830078125, 1.327800989151000976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+141, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3579.876708984375, -1506.232666015625, 93.33356475830078125, 5.720923900604248046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356716 - Reading)
(@CGUID+142, 180243, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3617.158935546875, -1490.66845703125, 93.33356475830078125, 5.566730976104736328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Chef (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+143, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3600.9853515625, -1502.501708984375, 106.922698974609375, 5.189293861389160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+144, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3690.385498046875, -1509.4305419921875, 93.33356475830078125, 3.636849403381347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+145, 180248, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3608.681396484375, -1487.3697509765625, 93.33356475830078125, 5.092763900756835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+146, 180249, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3626.822021484375, -1497.15283203125, 94.98777008056640625, 2.931952953338623046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+147, 179796, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3602.22216796875, -1509.0833740234375, 106.1882095336914062, 4.788799762725830078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ta'leesa (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+148, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3617.296875, -1512.295166015625, 106.0886993408203125, 1.30131685733795166, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+149, 180249, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3631.134521484375, -1488.7864990234375, 93.33356475830078125, 1.880596041679382324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356765 - [DNT] Serve Food)
(@CGUID+150, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3570.3984375, -1509.28125, 94.08294677734375, 0.54665374755859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+151, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3626.73876953125, -1509.842041015625, 106.088623046875, 2.477204322814941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+152, 179795, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3593.44873046875, -1514.2603759765625, 106.1881942749023437, 5.408512592315673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ta'speri (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+153, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3688.252685546875, -1509.6007080078125, 93.33356475830078125, 5.087529182434082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+154, 180268, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3618.431396484375, -1506.842041015625, 106.08868408203125, 4.530706405639648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ta'sam (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+155, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3584.310791015625, -1517.9410400390625, 106.0887527465820312, 5.758768558502197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356756 - [DNT] Carry Stuff)
(@CGUID+156, 180248, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3639.1884765625, -1486.857666015625, 93.33356475830078125, 4.548357963562011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+157, 180247, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3627.645751953125, -1485.2882080078125, 93.33356475830078125, 4.684491634368896484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+158, 180248, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3637.4462890625, -1486.3646240234375, 93.33355712890625, 4.548357963562011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+159, 180295, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3699.76123046875, -1495.9010009765625, 93.33355712890625, 1.746309757232666015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'rihn the Keen (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+160, 180247, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3626.708251953125, -1483.842041015625, 93.33355712890625, 5.154111385345458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+161, 180249, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3634.63720703125, -1485.6771240234375, 93.44995880126953125, 5.653512001037597656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356765 - [DNT] Serve Food)
(@CGUID+162, 180248, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.94970703125, -1485.576416015625, 93.33356475830078125, 5.092763900756835937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+163, 180247, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3627.529541015625, -1487.0347900390625, 93.33356475830078125, 4.473452568054199218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hungry Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+164, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3563.759521484375, -1486.23095703125, 94.0736236572265625, 2.270109415054321289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+165, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3659.98779296875, -1475.921875, 93.33356475830078125, 1.054637908935546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+166, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3680.8828125, -1478.904541015625, 93.33355712890625, 2.394403457641601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+167, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3648.30029296875, -1475.16845703125, 93.33356475830078125, 5.455436229705810546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+168, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3580.47119140625, -1476.3480224609375, 93.2819061279296875, 0.102232463657855987, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356711 - Haulin) (possible waypoints or random movement)
(@CGUID+169, 178074, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3657.263916015625, -1174.2899169921875, 73.8049163818359375, 0.796246290206909179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Al'dalil (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+170, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3649.96875, -1477.7135009765625, 93.33356475830078125, 1.832955718040466308, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+171, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3688.0234375, -1481.3194580078125, 93.33355712890625, 2.095302581787109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+172, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3558.68212890625, -1476.949951171875, 93.2843017578125, 4.626918792724609375, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+173, 180266, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3686.954833984375, -1479.25, 93.34844970703125, 5.0535888671875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ta'ules (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+174, 180241, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3573.302001953125, -1473.767333984375, 93.33356475830078125, 2.231878042221069335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+175, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3545.819580078125, -1478.732666015625, 96.08602142333984375, 6.194256782531738281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+176, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3661.58935546875, -1473.2239990234375, 93.33356475830078125, 1.054637908935546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+177, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3544.49560546875, -1475.842041015625, 95.66037750244140625, 4.41789865493774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356756 - [DNT] Carry Stuff)
(@CGUID+178, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3665.873291015625, -1472.4774169921875, 93.33356475830078125, 1.054637908935546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+179, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3571.474853515625, -1471.779541015625, 93.33355712890625, 5.171093463897705078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+180, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3609.006103515625, -1463.107666015625, 93.33355712890625, 2.221817731857299804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+181, 180260, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3599.587646484375, -1464.28125, 93.33355712890625, 5.333675861358642578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Spice Trader Au'saar (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+182, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3691.6328125, -1475.220458984375, 93.5865631103515625, 1.97806251049041748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+183, 180148, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3666.259521484375, -1465.10595703125, 93.33356475830078125, 4.075719833374023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Coin Changer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+184, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3563.762939453125, -1468.921875, 93.33355712890625, 4.239323139190673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356716 - Reading)
(@CGUID+185, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3660.666748046875, -1468.9600830078125, 93.33356475830078125, 1.054637908935546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+186, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.978271484375, -1454.7725830078125, 93.33355712890625, 3.636849403381347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+187, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3609.845458984375, -1454.9427490234375, 93.33355712890625, 5.087529182434082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+188, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3588.697998046875, -1458.9375, 93.33355712890625, 6.097062110900878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+189, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.501708984375, -1457.07470703125, 93.33355712890625, 2.148313760757446289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+190, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3591.385498046875, -1458.673583984375, 93.33355712890625, 3.157846927642822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+191, 180327, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3726.343017578125, -1479.328125, 85.42444610595703125, 2.07669687271118164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Au'mba (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+192, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3724.22314453125, -1475.68408203125, 85.6726837158203125, 5.185702323913574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+193, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.585205078125, -1447.57470703125, 93.8941802978515625, 2.3243408203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+194, 179367, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3640.08544921875, -1450.0794677734375, 93.28430938720703125, 1.92081153392791748, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+195, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3604.350830078125, -1447.7586669921875, 94.00771331787109375, 0.687480092048645019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+196, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3596.428955078125, -1450.4583740234375, 93.33355712890625, 1.912805795669555664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+197, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3648.401123046875, -1452.109375, 93.33356475830078125, 0.072997242212295532, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+198, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3612.787353515625, -1444.2135009765625, 94.376434326171875, 3.228785514831542968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+199, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3633.630126953125, -1446.5260009765625, 93.33355712890625, 6.097062110900878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+200, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3640.123291015625, -1442.7708740234375, 94.17510986328125, 5.207004070281982421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+201, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3622.439208984375, -1441.2430419921875, 94.13055419921875, 1.12113809585571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+202, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3636.317626953125, -1446.26220703125, 93.33356475830078125, 3.157846927642822265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+203, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3619.861083984375, -1436.2117919921875, 93.87657928466796875, 5.778423786163330078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+204, 179837, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3563.89501953125, -1443.8211669921875, 95.503936767578125, 0.990598440170288085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Tracker Zo'korss (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat, 18950 - Invisibility and Stealth Detection)
(@CGUID+205, 180147, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3566.579833984375, -1438.0521240234375, 95.50392913818359375, 4.295964241027832031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Well-informed Trader (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+206, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.927001953125, -1433.1475830078125, 93.771881103515625, 4.819203853607177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+207, 180822, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3635.70654296875, -1429.46533203125, 93.33356475830078125, 4.157875537872314453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Goblin (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+208, 179948, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3535.002685546875, -1410.734375, 93.32855987548828125, 3.63811659812927246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Impressed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+209, 180091, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3519.3837890625, -1416.920166015625, 93.32855987548828125, 0.701927244663238525, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ancient Core Hound (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356424 - Emanating Heat, 357823 - Heated)
(@CGUID+210, 179947, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3529.795166015625, -1406.5538330078125, 93.32855987548828125, 3.665323972702026367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Impressed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+211, 180149, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3557.4765625, -1405.8211669921875, 93.32855987548828125, 2.723719120025634765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Relaxed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+212, 180336, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3719.6572265625, -1420.10595703125, 73.8152313232421875, 0.103942111134529113, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Wiseguy (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+213, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3633.6572265625, -1419.2413330078125, 93.094451904296875, 4.917345523834228515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+214, 180072, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3519.1328125, -1405.451416015625, 93.2843017578125, 4.734269142150878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Tether Post (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+215, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3529.20751953125, -1424.875, 93.32855987548828125, 1.610649466514587402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+216, 180150, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3554.006103515625, -1405.19970703125, 93.32855987548828125, 6.142426490783691406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Relaxed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+217, 179948, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3533.765625, -1413.4010009765625, 93.32855987548828125, 3.226624727249145507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Impressed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+218, 180215, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3631.580810546875, -1414.9930419921875, 92.66295623779296875, 3.149809122085571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356756 - [DNT] Carry Stuff)
(@CGUID+219, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3626.507080078125, -1415.0052490234375, 93.8218231201171875, 6.257188320159912109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356716 - Reading)
(@CGUID+220, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3720.450439453125, -1422.734375, 73.8152313232421875, 3.069233417510986328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+221, 180390, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3537.401123046875, -1418.5191650390625, 93.3285675048828125, 1.350544333457946777, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dantun (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357150 - Energy Cage)
(@CGUID+222, 180442, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3540.529541015625, -1417.032958984375, 93.3285675048828125, 3.77820897102355957, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Novice Acquirer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+223, 180443, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3536.6181640625, -1414.8228759765625, 93.5774078369140625, 4.679154396057128906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Exotic Reseller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+224, 180320, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3711.533935546875, -1410.376708984375, 81.830291748046875, 1.537731051445007324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Illicit Purveyor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+225, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3746.7900390625, -1428.1944580078125, 73.8152313232421875, 5.987499713897705078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+226, 180149, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3559.59033203125, -1391.7535400390625, 93.32855987548828125, 5.993026256561279296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Relaxed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+227, 180149, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3562.9228515625, -1389.4132080078125, 93.32855224609375, 4.276662349700927734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Relaxed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+228, 180315, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3711.87060546875, -1407.2222900390625, 81.830291748046875, 4.604082584381103515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shady Dealer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+229, 180091, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3511.3203125, -1399.2916259765625, 93.32855987548828125, 0.437718212604522705, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ancient Core Hound (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356424 - Emanating Heat, 357823 - Heated)
(@CGUID+230, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3721.186767578125, -1406.9896240234375, 73.8152313232421875, 0.471870601177215576, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+231, 179948, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3518.368896484375, -1389.623291015625, 93.32855987548828125, 4.013003826141357421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Impressed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+232, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3723.05029296875, -1404.907958984375, 73.8152313232421875, 4.018572330474853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+233, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3743.78125, -1411.28125, 73.8152313232421875, 4.617248058319091796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+234, 179948, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3519.405517578125, -1391.9913330078125, 93.32855987548828125, 4.186849117279052734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Impressed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+235, 180315, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3684.093017578125, -1387.2413330078125, 73.8152313232421875, 1.193002939224243164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shady Dealer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+236, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3745.764892578125, -1412.8177490234375, 73.8152313232421875, 3.414920806884765625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+237, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3743.677001953125, -1414.9478759765625, 73.8152313232421875, 1.805303573608398437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+238, 180314, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3746.454833984375, -1414.703125, 73.87752532958984375, 2.070142984390258789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Patio Waiter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356866 - [DNT] Serve Drink)
(@CGUID+239, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3667.333251953125, -1375.62158203125, 73.8152313232421875, 3.181583404541015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+240, 179948, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3522.634521484375, -1386.7535400390625, 93.32855987548828125, 4.084250926971435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Impressed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+241, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3664.468017578125, -1375.7447509765625, 73.8152313232421875, 0.092259354889392852, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+242, 180314, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3760.130126953125, -1407.9010009765625, 73.8152313232421875, 2.792924165725708007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Patio Waiter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356765 - [DNT] Serve Food)
(@CGUID+243, 180336, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3681.247314453125, -1371.1510009765625, 73.8152313232421875, 0.733828723430633544, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Wiseguy (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+244, 180149, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3543.47998046875, -1372.9722900390625, 93.91449737548828125, 4.070842742919921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Relaxed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+245, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3503.244873046875, -1385.373291015625, 93.5948638916015625, 0.50872129201889038, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+246, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3681.015625, -1372.84033203125, 73.8152313232421875, 3.168516159057617187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+247, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3699.125, -1380.0850830078125, 73.8152313232421875, 5.85832834243774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+248, 180348, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3685.11279296875, -1375.267333984375, 73.8152313232421875, 0.576854526996612548, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Muscle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+249, 180328, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.310791015625, -1374.3472900390625, 73.8152313232421875, 1.546348452568054199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Au'ri (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+250, 180149, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3541.491455078125, -1374.609375, 93.32855987548828125, 0.845469474792480468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Relaxed Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+251, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.45654296875, -1369.482666015625, 74.06232452392578125, 4.735835552215576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+252, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3701.89501953125, -1380.7916259765625, 73.8152313232421875, 2.664467096328735351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+253, 179167, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3666.87646484375, -1371.0960693359375, 73.87804412841796875, 0.455786347389221191, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Damp Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+254, 180348, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3719.08154296875, -1381.761474609375, 73.93074798583984375, 5.619132041931152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Muscle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357099 - Cosmetic - Carry Barrel)
(@CGUID+255, 180336, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3719.931884765625, -1382.4794921875, 73.93128204345703125, 5.525110721588134765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Wiseguy (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357099 - Cosmetic - Carry Barrel)
(@CGUID+256, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3719.359619140625, -1381.3680419921875, 73.9193267822265625, 5.454874038696289062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357100 - Cosmetic - Carry Box)
(@CGUID+257, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3721.274658203125, -1383.6651611328125, 73.9228363037109375, 5.443362236022949218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357100 - Cosmetic - Carry Box)
(@CGUID+258, 180092, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3495.73876953125, -1385.6805419921875, 93.32855987548828125, 1.141377568244934082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Giant Hive Guardian (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356560 - Hyperlight Containment Cell)
(@CGUID+259, 180092, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3489.24560546875, -1381.498291015625, 93.32855987548828125, 1.126158118247985839, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Giant Hive Guardian (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356560 - Hyperlight Containment Cell)
(@CGUID+260, 179366, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3744.123291015625, -1364.453125, 73.87752532958984375, 5.688971996307373046, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Damp Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+261, 179981, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3521.912353515625, -1357.532958984375, 93.32855987548828125, 2.928855180740356445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Chef (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+262, 180261, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3710.624267578125, -1347.939208984375, 73.8152313232421875, 1.870372653007507324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+263, 180320, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3694.95751953125, -1346.2447509765625, 81.73663330078125, 0.438328087329864501, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Illicit Purveyor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+264, 180320, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3690.595458984375, -1345.6007080078125, 81.73663330078125, 1.454470515251159667, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Illicit Purveyor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+265, 180315, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3696.611083984375, -1345.640625, 81.73663330078125, 3.4315185546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shady Dealer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+266, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3741.319580078125, -1358.6336669921875, 73.8152313232421875, 2.179667949676513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+267, 180616, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3930.4453125, -1153.34033203125, 69.49044036865234375, 4.623329639434814453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Trade Prince Gallywix (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+268, 175616, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 0, 0, 0, 3.137067317962646484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Zo'phex (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 348480 - Idle Anim Replacement)
(@CGUID+272, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3737.5244140625, -1355.204833984375, 73.8152313232421875, 5.659920692443847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+273, 180314, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3744.431396484375, -1357.3160400390625, 73.87752532958984375, 2.340169906616210937, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Patio Waiter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356866 - [DNT] Serve Drink) (possible waypoints or random movement)
(@CGUID+274, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3740.8837890625, -1352.5711669921875, 73.8152313232421875, 4.209245204925537109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+275, 180310, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3743.072021484375, -1354.7066650390625, 73.8152313232421875, 3.518111228942871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shop Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356864 - North Side  Rename Spawn Spell)
(@CGUID+276, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3662.15185546875, -1331.5885009765625, 73.8152313232421875, 2.765699148178100585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+277, 180315, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3624.854248046875, -1333.15625, 66.272796630859375, 0.554325282573699951, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shady Dealer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+278, 180228, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3618.575439453125, -1335.0538330078125, 66.1413726806640625, 0.958989918231964111, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Export Supervisor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356716 - Reading)
(@CGUID+279, 180320, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3627.7734375, -1332.298583984375, 66.1411285400390625, 3.642052888870239257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Illicit Purveyor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+280, 180348, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3658.356689453125, -1331.0086669921875, 73.8152313232421875, 4.265420913696289062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Muscle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+281, 180336, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3663.702392578125, -1330.7847900390625, 74.27805328369140625, 4.86971139907836914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Wiseguy (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+282, 180618, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3931.710205078125, -1160.423583984375, 69.20011138916015625, 0.77006685733795166, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Negotiator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+283, 180495, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3481.085205078125, -1373.0191650390625, 93.32855987548828125, 0.439616531133651733, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Enraged Direhorn (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+284, 179165, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3473.357666015625, -1374.067138671875, 93.2843017578125, 5.078992843627929687, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Silver Purrkin (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 96573 - Pet Sit or Sleep) (possible waypoints or random movement)
(@CGUID+285, 180072, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3478.5859375, -1363.345703125, 93.2843017578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Tether Post (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+286, 180317, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3618.5478515625, -1329.8524169921875, 66.1413726806640625, 5.118336200714111328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Illicit Hauler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356756 - [DNT] Carry Stuff)
(@CGUID+287, 165855, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3480.809814453125, -1359.857666015625, 93.32855987548828125, 6.116024971008300781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Moonfrog (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 356251 - Hyperlight Containment Cell)
(@CGUID+288, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3475.632080078125, -1355.5260009765625, 93.32855987548828125, 5.847947597503662109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+289, 180315, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3656.157958984375, -1321.2916259765625, 73.8152313232421875, 2.296780347824096679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shady Dealer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+290, 180848, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3496.825439453125, -1343.02783203125, 74.55507659912109375, 2.126160144805908203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+291, 180348, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3630.8447265625, -1314.4722900390625, 74.062255859375, 6.134155750274658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Muscle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+292, 180855, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3485.01220703125, -1345.954833984375, 76.2347412109375, 1.069377422332763671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Devourer Mite (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+293, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3714.806396484375, -1327.828125, 73.8152313232421875, 2.601474285125732421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+294, 180320, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3654.2900390625, -1319.2708740234375, 73.8152313232421875, 5.280189990997314453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Illicit Purveyor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+295, 180823, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3475.17529296875, -1347.2379150390625, 93.3285675048828125, 6.161075115203857421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Pancake (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+296, 179168, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3491.573974609375, -1335.7708740234375, 73.8780517578125, 5.493617534637451171, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+297, 179797, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3903.069580078125, -1108.3697509765625, 62.93673324584960937, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- [DNT] Spotlight Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+298, 179797, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3915.165771484375, -1130.564208984375, 62.93667221069335937, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- [DNT] Spotlight Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+299, 180755, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3939.146728515625, -1173.48095703125, 69.1937255859375, 2.141137361526489257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- High Roller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+300, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3927.569580078125, -1170.5260009765625, 69.19366455078125, 2.172082185745239257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+301, 180336, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3632.264892578125, -1307.201416015625, 73.8152313232421875, 0.736142456531524658, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Wiseguy (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+302, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3927.569580078125, -1170.5260009765625, 69.19366455078125, 2.172082185745239257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+303, 180618, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3931.710205078125, -1160.423583984375, 69.20011138916015625, 0.77006685733795166, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Negotiator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+304, 180616, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3930.4453125, -1153.34033203125, 69.49044036865234375, 4.623329639434814453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Trade Prince Gallywix (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+305, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3714.5859375, -1326.0833740234375, 73.8152313232421875, 4.531794548034667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+306, 179797, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3914.10498046875, -1117.1197509765625, 62.92864990234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- [DNT] Spotlight Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+307, 180846, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3534.069580078125, -1319.62158203125, 74.35517120361328125, 2.814429759979248046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Sickly Gazelle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 19502 - Sickly Critter Aura)
(@CGUID+308, 176705, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3415.186767578125, -1257.9254150390625, 73.72308349609375, 4.085719108581542968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Venza Goldfuse (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+309, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3633.86376953125, -1310.8836669921875, 73.8152313232421875, 4.242895126342773437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+310, 180852, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3481.009521484375, -1339.7760009765625, 74.6009979248046875, 0.522812604904174804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Infested Bear (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 87966 - Feeding the Brood)
(@CGUID+311, 180072, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3535.32373046875, -1318.0850830078125, 74.0240631103515625, 1.547905921936035156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Tether Post (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 - !!! might be temporary spawn !!!
(@CGUID+312, 176556, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3361.8837890625, -1292.71875, 78.532958984375, 0.335195034742355346, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Alcruux (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 349091 - Energy Cage)
(@CGUID+313, 180348, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3629.513916015625, -1301.611083984375, 73.8152313232421875, 3.883606910705566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Muscle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+314, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3712.959228515625, -1320.779541015625, 73.8152313232421875, 3.409542798995971679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+315, 180848, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3544.99658203125, -1303.9288330078125, 74.7712860107421875, 2.55298614501953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+316, 180095, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3535.5244140625, -1309.3194580078125, 73.8152313232421875, 2.400983572006225585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Ankylodon Bull (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+317, 180567, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3507.18408203125, -1318.1614990234375, 73.81524658203125, 0.789994239807128906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Frenzied Nightclaw (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357832 - Energy Cage) (possible waypoints or random movement)
(@CGUID+318, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3740.782958984375, -1308.7869873046875, 73.877685546875, 6.12357950210571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+319, 176555, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3358.065185546875, -1284.3646240234375, 78.532958984375, 0.749059855937957763, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Achillite (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 349274 - Powered Down)
(@CGUID+320, 179366, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3642.553955078125, -1286.6597900390625, 73.83416748046875, 5.529778957366943359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Damp Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+321, 177757, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3697.575439453125, -1284.185791015625, 73.93377685546875, 0.079560339450836181, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'tadir (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+322, 177752, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3756.083251953125, -1326.0572509765625, 73.93377685546875, 1.576010823249816894, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'ghana (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+323, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3720.855224609375, -1281.451904296875, 73.8780517578125, 5.393700122833251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+324, 180320, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3629.810791015625, -1272.421875, 73.8152313232421875, 3.168647527694702148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Illicit Purveyor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+325, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3692.080810546875, -1276.8194580078125, 74.1020660400390625, 4.923961639404296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+326, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3703.2197265625, -1284.1510009765625, 73.8152313232421875, 3.570488214492797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+327, 180567, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3523.598876953125, -1283.52783203125, 73.81524658203125, 5.030342578887939453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Frenzied Nightclaw (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357832 - Energy Cage) (possible waypoints or random movement)
(@CGUID+328, 180567, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3529.038330078125, -1280.07470703125, 73.81524658203125, 5.156897544860839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Frenzied Nightclaw (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357832 - Energy Cage) (possible waypoints or random movement)
(@CGUID+329, 180348, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3638.3515625, -1257.578125, 74.0654449462890625, 4.193538188934326171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Muscle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+330, 180856, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3508.72314453125, -1288.935791015625, 73.81524658203125, 4.935210227966308593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Deranged Helboar (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+331, 180855, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3546.858642578125, -1272.9635009765625, 76.72564697265625, 3.421529769897460937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Devourer Mite (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+332, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3728.447998046875, -1290.7569580078125, 73.93377685546875, 5.988003730773925781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+333, 179799, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3506.35498046875, -1295.920166015625, 73.8152313232421875, 5.290242195129394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Portal Authority Tunnelmancer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+334, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3691.34375, -1282.140625, 74.2467041015625, 0.885001420974731445, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+335, 180336, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3642.228271484375, -1260.8785400390625, 73.99977874755859375, 3.761574506759643554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Wiseguy (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+336, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3702.6259765625, -1282.0382080078125, 73.8152313232421875, 3.416151046752929687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+337, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3704.276123046875, -1288.1805419921875, 73.8152313232421875, 3.409542798995971679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+338, 180567, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3500.026123046875, -1312.5, 73.81524658203125, 0.789994239807128906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Frenzied Nightclaw (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357832 - Energy Cage) (possible waypoints or random movement)
(@CGUID+339, 180315, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3627.34814453125, -1272.28125, 75.83868408203125, 6.174405574798583984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shady Dealer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+340, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3731.752685546875, -1294.5504150390625, 73.93377685546875, 2.5439605712890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+341, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3733.104248046875, -1290.8072509765625, 73.93377685546875, 3.849369764328002929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+342, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3795.783935546875, -1317.467041015625, 73.8152313232421875, 4.793661117553710937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+343, 177755, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3805.106689453125, -1324.921875, 73.93377685546875, 1.790761709213256835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'jahid (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+344, 180335, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3643.7265625, -1254.6788330078125, 73.8152313232421875, 5.187994956970214843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Smuggler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+345, 178383, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3748.798583984375, -1264.484375, 103.3591232299804687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- [DNT] Controller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 351930 - [DNT] Periodic Wave Spawn Control Aura)
(@CGUID+346, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3811.18994140625, -1318.9000244140625, 74.15560150146484375, 4.712388992309570312, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+347, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3803.369140625, -1308.2742919921875, 73.882080078125, 2.765612602233886718, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+348, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3838.483642578125, -1322.3211669921875, 73.8152313232421875, 0.295504361391067504, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+349, 177753, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3730.372314453125, -1248.9896240234375, 73.93377685546875, 2.844040870666503906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'mal (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+350, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3724.069580078125, -1252.6458740234375, 73.8152313232421875, 6.038558483123779296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+351, 177995, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3696.78125, -1236.9722900390625, 73.93377685546875, 6.204187393188476562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'zaro (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+352, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 2, 3835.026123046875, -1325.29345703125, 73.8152313232421875, 5.426984310150146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+353, 175646, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3711.2587890625, -1131.1597900390625, 73.8747406005859375, 4.732264518737792968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- P.O.S.T. Master (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 346322 - Override Energy Bar Color (Blue))
(@CGUID+354, 179367, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3779.083740234375, -1268.6077880859375, 74.02611541748046875, 2.566650867462158203, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+355, 180563, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3841.973876953125, -1304.861083984375, 73.8152313232421875, 0.651285648345947265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Backalley Schemer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+356, 180563, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3844.819580078125, -1303.7083740234375, 73.8152313232421875, 2.557747840881347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Backalley Schemer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+357, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3781.99609375, -1254.628662109375, 74.001953125, 4.763916969299316406, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+358, 180563, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3841.56689453125, -1302.21533203125, 73.8152313232421875, 6.197319507598876953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Backalley Schemer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+359, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3780.85595703125, -1256.7691650390625, 74.25543212890625, 3.029065608978271484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+360, 177760, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3773.19091796875, -1242.8629150390625, 73.93377685546875, 5.781609535217285156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'kitaab (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+361, 177998, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3752.779541015625, -1227.6754150390625, 73.93377685546875, 1.242502093315124511, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'nara (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+362, 179799, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3660.25341796875, -1201.6024169921875, 73.8152313232421875, 2.244885444641113281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Portal Authority Tunnelmancer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+363, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3773.80126953125, -1231.060791015625, 73.8152313232421875, 3.455841302871704101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+364, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3688.130126953125, -1199.3125, 73.8152313232421875, 1.682036042213439941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+365, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3689.059814453125, -1192.782958984375, 73.8152313232421875, 1.518520116806030273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+366, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3687.442626953125, -1196.0625, 73.8152313232421875, 1.682036042213439941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+367, 177756, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3799.835205078125, -1228.0069580078125, 73.93377685546875, 2.824337720870971679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'aqida (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+368, 177994, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3720.205810546875, -1195.888916015625, 73.93377685546875, 4.613942146301269531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'har (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+369, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3792.221435546875, -1228.46875, 73.8152313232421875, 0.053247243165969848, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+370, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3792.34033203125, -1226.9757080078125, 73.8152313232421875, 5.406521797180175781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+371, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3686.72998046875, -1187.8125, 73.8152313232421875, 1.651520967483520507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+372, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3689.20751953125, -1189.9617919921875, 73.8152313232421875, 1.802944064140319824, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+373, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3681.55126953125, -1185.7135009765625, 73.8152313232421875, 3.931826591491699218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+374, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3684.34033203125, -1185.967041015625, 73.8152313232421875, 1.622325301170349121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+375, 180849, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3471.541748046875, -1242.9427490234375, 73.71744537353515625, 2.896586179733276367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+376, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3927.569580078125, -1170.5260009765625, 69.19366455078125, 2.172082185745239257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+377, 180618, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3931.710205078125, -1160.423583984375, 69.20011138916015625, 0.77006685733795166, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Cartel Negotiator (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+378, 180616, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3930.4453125, -1153.34033203125, 69.49044036865234375, 4.623329639434814453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Trade Prince Gallywix (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+379, 180848, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3469.8291015625, -1248.3333740234375, 73.71744537353515625, 2.343233346939086914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+380, 180849, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3471.947998046875, -1242.40283203125, 73.71744537353515625, 2.896586179733276367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+381, 180849, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3472.056396484375, -1241.69970703125, 73.71744537353515625, 2.896586179733276367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+382, 180849, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3472.638916015625, -1242.673583984375, 73.71744537353515625, 2.896586179733276367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+383, 180616, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3930.4453125, -1153.34033203125, 69.49044036865234375, 4.623329639434814453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Trade Prince Gallywix (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+384, 180859, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3398.835205078125, -1324.2899169921875, 73.71551513671875, 1.531637191772460937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Raging Colossus (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+385, 175600, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3914.5078125, -1117.1875, 62.92864227294921875, 3.730525016784667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Drumset (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+386, 177440, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3916.061767578125, -1116.185791015625, 62.92864227294921875, 3.682644605636596679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Seat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+387, 177327, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3900.486083984375, -1116.8316650390625, 62.92866134643554687, 3.368038654327392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Verethian (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 350319 - Jazzy)
(@CGUID+388, 180849, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3471.593017578125, -1241.892333984375, 73.71744537353515625, 2.896586179733276367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dew Monster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+389, 180852, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3463.637939453125, -1250.1024169921875, 74.85059356689453125, 2.098586320877075195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Infested Bear (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 87966 - Feeding the Brood)
(@CGUID+390, 177325, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3914.9072265625, -1116.920166015625, 62.92864227294921875, 3.524587631225585937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hips (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 350319 - Jazzy)
(@CGUID+391, 180858, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3470.43310546875, -1237.3194580078125, 72.9133453369140625, 2.667684078216552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Nether Beast (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+392, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3678.380126953125, -1182.8228759765625, 73.8152313232421875, 2.812781810760498046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+393, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3407.2197265625, -1292.298583984375, 73.70859527587890625, 2.665205240249633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+394, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3409.239501953125, -1294.296875, 73.70859527587890625, 2.665205240249633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+395, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3408.15625, -1290.5242919921875, 73.70859527587890625, 2.665205240249633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+396, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3411.1962890625, -1293.109375, 73.70859527587890625, 2.665205240249633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+397, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3410.310791015625, -1291.0382080078125, 73.70859527587890625, 2.665205240249633789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+398, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3398.8369140625, -1304.138916015625, 73.70859527587890625, 2.426578521728515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+399, 180858, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3470.731689453125, -1236.85595703125, 73.647369384765625, 2.667684078216552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Nether Beast (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+400, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3415.75, -1282.4774169921875, 73.70859527587890625, 2.762871980667114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+401, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3417.585205078125, -1281.0989990234375, 73.70859527587890625, 2.762871980667114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+402, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3423.412353515625, -1272.0728759765625, 73.70859527587890625, 2.893471240997314453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+403, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3406.728271484375, -1281.6961669921875, 73.7104949951171875, 2.893471240997314453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+404, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.635498046875, -1180.2396240234375, 73.8152313232421875, 4.572253704071044921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+405, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3398.4609375, -1301.9254150390625, 73.70859527587890625, 2.426578521728515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+406, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3396.651123046875, -1304.842041015625, 73.70859527587890625, 2.426578521728515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+407, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3395.16064453125, -1302.421875, 73.70859527587890625, 2.426578521728515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+408, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3416.498291015625, -1279.1302490234375, 73.70859527587890625, 2.762871980667114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+409, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3423.721435546875, -1268.6597900390625, 73.70859527587890625, 2.893471240997314453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+410, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3407.037353515625, -1278.282958984375, 73.78063201904296875, 2.893471240997314453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+411, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3398.1572265625, -1278.4478759765625, 73.76007843017578125, 3.164113283157348632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+412, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3415.454833984375, -1260.49658203125, 73.72308349609375, 3.37217116355895996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+413, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3397.03125, -1283.638916015625, 73.6853790283203125, 3.263765573501586914, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell) (possible waypoints or random movement)
(@CGUID+414, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3397.010498046875, -1280.4322509765625, 73.77099609375, 3.164113283157348632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+415, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3414.73876953125, -1262.673583984375, 73.70859527587890625, 3.37217116355895996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+416, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3392.710205078125, -1289.295166015625, 73.71551513671875, 2.615253448486328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+417, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3391.473876953125, -1292.4896240234375, 73.71551513671875, 2.615253448486328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+418, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3403.6494140625, -1267.625, 73.7380828857421875, 3.427021026611328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+419, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3400.806396484375, -1267.57470703125, 73.7247314453125, 3.427021026611328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+420, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3412.453125, -1262.21533203125, 73.70859527587890625, 3.37217116355895996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+421, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3405.887939453125, -1266.8385009765625, 73.6749267578125, 3.263765573501586914, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell) (possible waypoints or random movement)
(@CGUID+422, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3396.390625, -1277.0572509765625, 73.75984954833984375, 3.164113283157348632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+423, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3413.435791015625, -1259.498291015625, 73.72308349609375, 3.37217116355895996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+424, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3394.00341796875, -1281.779541015625, 73.78183746337890625, 3.164113283157348632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+425, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3404.240478515625, -1265.4132080078125, 73.7491302490234375, 3.427021026611328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+426, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3389.7734375, -1272.0225830078125, 73.762176513671875, 3.518024921417236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+427, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3402.1728515625, -1264.529541015625, 73.7482757568359375, 3.427021026611328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+428, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3388.021728515625, -1269.0694580078125, 73.749359130859375, 3.518024921417236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+429, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3404.741455078125, -1248.5521240234375, 73.70859527587890625, 3.720466375350952148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+430, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3386.939208984375, -1272.23095703125, 73.76593780517578125, 3.518024921417236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+431, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3386.2197265625, -1270.359375, 73.75742340087890625, 3.518024921417236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+432, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3398.107666015625, -1256.3004150390625, 73.75600433349609375, 3.869845151901245117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+433, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3390.165771484375, -1269.767333984375, 73.750701904296875, 3.518024921417236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+434, 180851, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3439.0322265625, -1227.98095703125, 74.855499267578125, 5.491295337677001953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dragonbone Condor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+435, 180846, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3441.53564453125, -1223.3055419921875, 73.71744537353515625, 5.308823585510253906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Sickly Gazelle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 19502 - Sickly Critter Aura)
(@CGUID+436, 180817, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3435.9306640625, -1226.638916015625, 73.71744537353515625, 3.75187993049621582, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Pickle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+437, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3387.756103515625, -1247.796142578125, 73.83980560302734375, 2.774655580520629882, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell) (possible waypoints or random movement)
(@CGUID+438, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3378.66015625, -1252.0126953125, 73.8668365478515625, 5.948993682861328125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell) (possible waypoints or random movement)
(@CGUID+439, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3393.006103515625, -1236.6597900390625, 73.70859527587890625, 4.314668178558349609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+440, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3395.453125, -1254.1336669921875, 73.77193450927734375, 3.869845151901245117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+441, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3389.682373046875, -1235.8507080078125, 73.76866912841796875, 4.314668178558349609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+442, 176896, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3366.314208984375, -1284.888916015625, 78.5329437255859375, 0.526634752750396728, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Edge of Annihilation (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 349296 - Edge of Annhiliation Cosmetic)
(@CGUID+443, 175806, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3568.1328125, -1071.1978759765625, 114.3974685668945312, 4.715946197509765625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+444, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3404.66845703125, -1246.2586669921875, 73.70859527587890625, 3.720466375350952148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+445, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3402.435791015625, -1246.013916015625, 73.70859527587890625, 3.720466375350952148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+446, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3370.067626953125, -1251.9097900390625, 73.8799896240234375, 4.199454307556152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+447, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3368.342041015625, -1250.185791015625, 73.71551513671875, 4.353314399719238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+448, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3384.643310546875, -1244.9114990234375, 73.70859527587890625, 4.353314399719238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+449, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3381.0234375, -1246.4271240234375, 73.70859527587890625, 4.353314399719238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+450, 180858, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3480.06689453125, -1197.3004150390625, 72.2600555419921875, 5.665121078491210937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Nether Beast (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+451, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3366.854248046875, -1250.71533203125, 73.76055908203125, 4.199454307556152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+452, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3386.864501953125, -1260.9791259765625, 73.76966094970703125, 3.720466375350952148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+453, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3386.791748046875, -1258.685791015625, 73.77178955078125, 3.720466375350952148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+454, 179799, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3511.846435546875, -1174.6597900390625, 74.06342315673828125, 0.240123391151428222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Portal Authority Tunnelmancer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+455, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3383.2353515625, -1243.107666015625, 73.70859527587890625, 4.353314399719238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+456, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3381.2822265625, -1244.2291259765625, 73.70859527587890625, 4.353314399719238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+457, 179886, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3384.55810546875, -1258.4410400390625, 73.77728271484375, 3.720466375350952148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Auction Bidder (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 355662 - Auction Rename Spawn Spell)
(@CGUID+458, 176519, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3667.46875, -1163.7274169921875, 73.9532623291015625, 3.896790504455566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Customer VO Controller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 348002 - Ping Random Unique Customer)
(@CGUID+459, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3672.979248046875, -1177.953125, 73.8152313232421875, 3.40758371353149414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+460, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3667.1103515625, -1171.25, 73.8152313232421875, 1.420705318450927734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+461, 176514, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3669.546875, -1173.3038330078125, 73.8152313232421875, 1.471922159194946289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Angry Customer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+462, 180853, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3349.693603515625, -1236.923583984375, 74.07125091552734375, 5.772774696350097656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Skeletal Lasher (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+463, 180854, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3390.014892578125, -1218.7430419921875, 73.9323577880859375, 4.673806190490722656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Proto-Drake (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+464, 180850, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3472.518310546875, -1176.828125, 73.8152313232421875, 4.386975288391113281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Glimmershell Crab (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+465, 180850, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3488.942626953125, -1147.126708984375, 74.24428558349609375, 4.148352622985839843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Glimmershell Crab (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+466, 180850, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3472.3359375, -1177.9566650390625, 73.8152313232421875, 1.553121447563171386, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Glimmershell Crab (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+467, 180858, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3473.991455078125, -1171.2066650390625, 73.63797760009765625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Nether Beast (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+468, 180821, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3465.96435546875, -1156.3524169921875, 73.8152313232421875, 0.300700187683105468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Sassafras (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+469, 179654, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3567.704833984375, -1153.326416015625, 81.19998931884765625, 4.726090431213378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Invis Flee Point (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+470, 176396, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3690.18408203125, -1160.0191650390625, 73.7086181640625, 2.304351329803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Defective Sorter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+471, 176397, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.1416015625, -1157.265625, 73.7086181640625, 3.194020748138427734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Holding Pen (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 86312 - Close)
(@CGUID+472, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3682.78125, -1156.5972900390625, 73.7086181640625, 2.35977482795715332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+473, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3682.638916015625, -1157.3819580078125, 73.7086181640625, 3.747011661529541015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+474, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.670166015625, -1157.579833984375, 73.7086181640625, 1.891525983810424804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+475, 180617, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3925.795166015625, -1155.9254150390625, 69.192138671875, 3.755425214767456054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Scoundrel (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+476, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.298583984375, -1157.7257080078125, 73.7086181640625, 4.806118965148925781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+477, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.0625, -1157.18408203125, 73.7086181640625, 1.891525983810424804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+478, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3682.56591796875, -1156.986083984375, 73.7086181640625, 1.184285879135131835, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+479, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3916.44091796875, -1161.798583984375, 69.188201904296875, 0.290121048688888549, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+480, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3682.866455078125, -1157.736083984375, 73.7086181640625, 1.187803387641906738, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+481, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3923.59033203125, -1163.642333984375, 69.18824005126953125, 3.539071083068847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+482, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.357666015625, -1157.236083984375, 73.7086181640625, 1.891525983810424804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+483, 180158, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3890.611083984375, -1091.1978759765625, 65.46537017822265625, 4.792258739471435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+484, 180158, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3922.009521484375, -1149.470458984375, 69.18817138671875, 1.636680245399475097, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+485, 175736, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3696.5859375, -1169.0989990234375, 74.29671478271484375, 1.605702877044677734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+486, 177609, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3908.233642578125, -1128.9879150390625, 62.92866134643554687, 3.87182021141052246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Dirtwhistle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 350319 - Jazzy)
(@CGUID+487, 177611, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3903.760498046875, -1124.9427490234375, 62.929443359375, 3.69766092300415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Vilt (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 350319 - Jazzy)
(@CGUID+488, 180755, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3919.73876953125, -1183.388916015625, 69.1937255859375, 2.141137361526489257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- High Roller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+489, 180852, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3493.720458984375, -1142.0347900390625, 74.64715576171875, 5.129761695861816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Infested Bear (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 87966 - Feeding the Brood)
(@CGUID+490, 179168, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3619.121826171875, -1137.18994140625, 73.89960479736328125, 2.339664697647094726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+491, 178074, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3580.88720703125, -855.13543701171875, 114.3884963989257812, 1.538545489311218261, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Al'dalil (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+492, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.61279296875, -1156.9132080078125, 73.7086181640625, 3.53795027732849121, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+493, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.829833984375, -1157.107666015625, 73.7086181640625, 0.422734200954437255, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+494, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.6025390625, -1156.59375, 73.7086181640625, 0.795673191547393798, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+495, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3683.236083984375, -1156.4583740234375, 73.7086181640625, 4.15057229995727539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+496, 176394, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3691.885009765625, -1154.247314453125, 73.73084259033203125, 4.799908638000488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- P.O.S.T. Worker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+497, 176395, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3702.877685546875, -1158.8515625, 74.47861480712890625, 5.49094247817993164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Overloaded Mailemental (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+498, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3567.404541015625, -1115.46533203125, 114.38848876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+499, 176397, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3671.264892578125, -1138.498291015625, 73.7086181640625, 1.987503767013549804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Holding Pen (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 86312 - Close)
(@CGUID+500, 175677, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3671.264892578125, -1138.498291015625, 73.7086181640625, 0.491949230432510375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Smuggled Creature (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+501, 176396, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3695.455810546875, -1152.37158203125, 73.7086181640625, 1.983834385871887207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Defective Sorter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+502, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3546.822998046875, -1112.298583984375, 114.38848876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+503, 175736, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3661.84375, -1133.935791015625, 74.93892669677734375, 1.310200691223144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+504, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3586.208251953125, -1108.907958984375, 114.38848876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+505, 176394, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3703.625, -1147.3060302734375, 73.717620849609375, 5.895751476287841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- P.O.S.T. Worker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+506, 176396, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3708.7578125, -1149.032958984375, 73.721435546875, 1.848485708236694335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Defective Sorter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+507, 176396, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3668.739501953125, -1123.5035400390625, 76.09706878662109375, 2.258504390716552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Defective Sorter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+508, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3585.3994140625, -1097.8316650390625, 114.38848876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+509, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3544.928955078125, -1097.8316650390625, 114.38848876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+510, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3762.229248046875, -1196.9166259765625, 73.8152313232421875, 0.330993622541427612, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+511, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3614.15625, -1198.857666015625, 73.7987213134765625, 5.941869258880615234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+512, 179841, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3618.940185546875, -1188.5521240234375, 73.79907989501953125, 5.25092172622680664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Veteran Sparkcaster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+513, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3521.6640625, -1155.1822509765625, 73.93080902099609375, 2.11679697036743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+514, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3618.411376953125, -1159.7291259765625, 73.79822540283203125, 6.127032279968261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+515, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3546.966064453125, -1233.170166015625, 73.78270721435546875, 3.953408241271972656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+516, 179841, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3575.7041015625, -1214.5972900390625, 73.7890625, 2.650994777679443359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Veteran Sparkcaster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+517, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3564.27001953125, -1219.34033203125, 73.786712646484375, 0.785621881484985351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+518, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3618.583251953125, -1195.6129150390625, 73.799163818359375, 5.602745532989501953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+519, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3766.060791015625, -1197.2916259765625, 73.8152313232421875, 0.959691405296325683, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+520, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.710205078125, -1204.0382080078125, 73.83425140380859375, 0.388953596353530883, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+521, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3620.037841796875, -1200.625244140625, 73.9175872802734375, 0.388953596353530883, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+522, 176396, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3672.583251953125, -1115.564208984375, 73.78515625, 5.070631027221679687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Defective Sorter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 347931 - Cosmetic Letter Spit)
(@CGUID+523, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3598.455810546875, -1229.4149169921875, 73.796875, 1.303073048591613769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+524, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3600.836669921875, -1220.735595703125, 73.88021087646484375, 1.303073048591613769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+525, 176397, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3715.630126953125, -1146.6822509765625, 74.0059356689453125, 3.990694761276245117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Holding Pen (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 86312 - Close)
(@CGUID+526, 175677, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3715.630126953125, -1146.6822509765625, 74.0059356689453125, 2.407953500747680664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Smuggled Creature (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+527, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3510.247314453125, -1162.3004150390625, 73.8152313232421875, 5.918046474456787109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+528, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3505.2978515625, -1171.0728759765625, 73.8152313232421875, 0.224288225173950195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+529, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3636.48779296875, -1213.2725830078125, 73.8152313232421875, 2.65616011619567871, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+530, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3613.854248046875, -1235.7708740234375, 73.8152313232421875, 2.514644145965576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+531, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3630.724853515625, -1140.71533203125, 73.8152313232421875, 4.01908731460571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+532, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3634.751708984375, -1164.3055419921875, 73.8152313232421875, 2.457787036895751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+533, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3510.947021484375, -1197.170166015625, 73.8152313232421875, 0.51956939697265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+534, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3639.880126953125, -1199.2760009765625, 73.8152313232421875, 2.775235414505004882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+535, 175736, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3662.092041015625, -1113.21533203125, 75.5945587158203125, 3.412536144256591796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+536, 180566, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3761.346435546875, -1190.7899169921875, 76.48056793212890625, 4.224896907806396484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Rat of Unusual Size (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357798 - Hyperlight Containment Cell)
(@CGUID+537, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3486.1259765625, -1159.1197509765625, 73.8152313232421875, 2.875515222549438476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+538, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3611.872314453125, -1230.6771240234375, 73.8152313232421875, 2.593374490737915039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+539, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3595.395751953125, -1229.064208984375, 73.79534912109375, 5.439699172973632812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+540, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3551.890625, -1237.171875, 73.78247833251953125, 4.909441471099853515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+541, 179841, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3588.90185546875, -1199.4149169921875, 73.79271697998046875, 4.00835418701171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Veteran Sparkcaster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+542, 179841, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3546.162353515625, -1199.329833984375, 73.785888671875, 5.724824905395507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Veteran Sparkcaster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+543, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3594.84716796875, -1220.4739990234375, 73.794921875, 5.609707355499267578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+544, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3515.0869140625, -1162.8680419921875, 73.78436279296875, 2.935159206390380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+545, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3549.3984375, -1195.7708740234375, 73.78676605224609375, 5.724824905395507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+546, 179841, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3585.858642578125, -1195.6927490234375, 73.79222869873046875, 4.00835418701171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Veteran Sparkcaster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+547, 179841, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3520.225830078125, -1195.5364990234375, 73.783447265625, 4.079944610595703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Veteran Sparkcaster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+548, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3571.697021484375, -1219.34375, 73.78704833984375, 1.829690217971801757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+549, 179840, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3515.608642578125, -1192.5555419921875, 73.78326416015625, 4.079944610595703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Market Peacekeeper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 356089 - Broker Energy Shield Cosmetic)
(@CGUID+550, 179841, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3561.7421875, -1214.55908203125, 73.78713226318359375, 0.62737894058227539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Veteran Sparkcaster (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2
(@CGUID+551, 179821, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3567.822021484375, -1162.1458740234375, 81.426239013671875, 4.722424030303955078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Commander Zo'far (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject2 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+552, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3543.607666015625, -1247.2708740234375, 73.8152313232421875, 1.335155010223388671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+553, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3543.265625, -1250.451416015625, 73.8152313232421875, 0.698369264602661132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+554, 179842, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3587.814208984375, -1198.596435546875, 74.06158447265625, 0.499196648597717285, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Commerce Enforcer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+555, 179842, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3569.028564453125, -1211.7396240234375, 73.7884674072265625, 5.001639366149902343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Commerce Enforcer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+556, 179842, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3547.580810546875, -1197.2337646484375, 73.92571258544921875, 2.56507730484008789, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Commerce Enforcer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (possible waypoints or random movement)
(@CGUID+557, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3479.4609375, -1191.7586669921875, 73.93080902099609375, 0.296694248914718627, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+558, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3548.93408203125, -1241.1697998046875, 73.8656768798828125, 5.445343017578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+559, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3542.912353515625, -1234.48095703125, 73.78234100341796875, 5.445343017578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+560, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3512.177978515625, -1252.6978759765625, 73.93080902099609375, 1.007503628730773925, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+561, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3515.2822265625, -1199.7158203125, 73.9175872802734375, 5.212438106536865234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+562, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3510.967041015625, -1191.8177490234375, 73.83425140380859375, 5.212438106536865234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+563, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3488.209228515625, -1214.27783203125, 73.9308013916015625, 0.56307375431060791, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+564, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3610.407958984375, -1233.4410400390625, 73.8152313232421875, 2.52716684341430664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+565, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3503.786376953125, -1195.0538330078125, 73.8152313232421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+566, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3605.19091796875, -1222.0086669921875, 73.8152313232421875, 1.619926810264587402, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+567, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3535.48876953125, -1239.3125, 73.8152313232421875, 0.014089720323681831, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+568, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3600.05126953125, -1231.814208984375, 73.8363189697265625, 2.475097179412841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+569, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3545.670166015625, -1249.2742919921875, 73.8152313232421875, 1.064780235290527343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+570, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3535.579833984375, -1242.7117919921875, 73.8152313232421875, 0.298117458820343017, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+571, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3532.7119140625, -1240.1475830078125, 73.82602691650390625, 0.137247607111930847, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+572, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3628.940185546875, -1211.1978759765625, 73.8152313232421875, 2.008016586303710937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+573, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3507.87841796875, -1207.16845703125, 73.8152313232421875, 1.041226148605346679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+574, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3545.720458984375, -1252.24658203125, 73.8152313232421875, 1.252342939376831054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+575, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3552.421142578125, -1243.765625, 73.8152313232421875, 1.553177952766418457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+576, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3608.37841796875, -1234.93408203125, 73.8152313232421875, 2.457373857498168945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+577, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.955810546875, -1159.5572509765625, 73.8152313232421875, 2.939260482788085937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+578, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3501.6875, -1170.0347900390625, 73.81523895263671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+579, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3473.598876953125, -1163.859375, 73.93080902099609375, 3.434557914733886718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+580, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3509.91357421875, -1174.1326904296875, 73.86727142333984375, 4.459744930267333984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+581, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3626.35302734375, -1187.6192626953125, 73.88335418701171875, 1.303073048591613769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+582, 176394, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3675.741455078125, -1116.1544189453125, 73.842254638671875, 0.149110615253448486, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- P.O.S.T. Worker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%) (possible waypoints or random movement)
(@CGUID+583, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3512.163330078125, -1165.41845703125, 73.783935546875, 4.459744930267333984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+584, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.97216796875, -1196.298583984375, 73.800018310546875, 1.303073048591613769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+585, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3613.892333984375, -1151.0333251953125, 73.88185882568359375, 2.299115896224975585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+586, 177868, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3480.764892578125, -1154.6024169921875, 73.93080902099609375, 5.621838569641113281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Creature Collector (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+587, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3623.412353515625, -1163.6519775390625, 73.9175872802734375, 1.792208552360534667, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+588, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3619.8828125, -1157.75, 73.79852294921875, 2.299115896224975585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+589, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3625.388916015625, -1172.4322509765625, 73.83425140380859375, 1.792208671569824218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+590, 179844, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3516.345458984375, -1158.5726318359375, 74.0141448974609375, 4.025936126708984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+591, 179843, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3522.049560546875, -1151.611083984375, 73.93080902099609375, 4.025936126708984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shocklight Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+592, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3624.42626953125, -1199.7135009765625, 73.8152313232421875, 2.41680002212524414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+593, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3633.6484375, -1150.607666015625, 73.8152313232421875, 3.458876371383666992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+594, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3506.947021484375, -1152.18408203125, 73.8152313232421875, 5.796961307525634765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+595, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3518.762939453125, -1150.1910400390625, 73.8152313232421875, 5.122426986694335937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+596, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3502.87158203125, -1174.15283203125, 73.8152313232421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+597, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3633.405517578125, -1152.2066650390625, 73.8152313232421875, 3.265326261520385742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+598, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3630.017333984375, -1149.63720703125, 73.8152313232421875, 3.630688667297363281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+599, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3639.397705078125, -1192.420166015625, 73.8152313232421875, 3.054996252059936523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+600, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3613.653564453125, -1233.6336669921875, 73.8152313232421875, 2.279381990432739257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+601, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3637.224853515625, -1166.9305419921875, 73.8152313232421875, 2.636124610900878906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+602, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3630.134521484375, -1208.015625, 73.8152313232421875, 2.71343088150024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+603, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3543.5947265625, -1242.71875, 73.8152313232421875, 2.461850643157958984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+604, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3635.666748046875, -1193.6353759765625, 73.8152313232421875, 2.954833745956420898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+605, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3637.515625, -1163.545166015625, 73.8152313232421875, 2.573391675949096679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+606, 176396, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3669.359375, -1110.1458740234375, 73.7086181640625, 1.665791749954223632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Defective Sorter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+607, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3582.4609375, -1076.1771240234375, 114.38848876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+608, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3556.185791015625, -1075.0694580078125, 114.38848876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+609, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3511.568603515625, -1150.9010009765625, 73.8152313232421875, 6.018844127655029296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+610, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3603.895751953125, -1218.6129150390625, 73.8152313232421875, 4.917011260986328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+611, 179909, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3609.00341796875, -1236.453125, 73.8152313232421875, 2.321401834487915039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Curious Onlooker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+612, 179908, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3540.8203125, -1239.8992919921875, 73.8152313232421875, 5.849097251892089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Distressed Merchant (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+613, 176395, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3672.47802734375, -1110.93310546875, 73.7827911376953125, 2.413849353790283203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Overloaded Mailemental (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+614, 176217, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3567.2587890625, -1070.0416259765625, 114.3884735107421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- So'azmi (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+615, 176397, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.3203125, -1100.357666015625, 73.721435546875, 0.826689958572387695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Holding Pen (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 86312 - Close)
(@CGUID+616, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.87060546875, -1100.0208740234375, 73.721435546875, 0.895332396030426025, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+617, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.075439453125, -1099.9583740234375, 73.721435546875, 2.282570838928222656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+618, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3676.056396484375, -1100.4583740234375, 73.721435546875, 2.686130285263061523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+619, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.643310546875, -1100.875, 73.721435546875, 2.073508739471435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+620, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3674.9853515625, -1101.0103759765625, 73.721435546875, 0.42708367109298706, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+621, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.474853515625, -1101.1146240234375, 73.721435546875, 5.241477012634277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+622, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.9609375, -1100.8333740234375, 73.721435546875, 5.614415645599365234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+623, 177999, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3767.7890625, -1193.234375, 74.0637359619140625, 4.730829238891601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'darid (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 352121 - [DNT] Prepurchase Glow)
(@CGUID+624, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3674.806396484375, -1100.65283203125, 73.721435546875, 3.341676950454711914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+625, 179799, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3748.4384765625, -1167.453125, 74.1730804443359375, 0.400919735431671142, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Portal Authority Tunnelmancer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+626, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.3203125, -1100.357666015625, 73.721435546875, 0.42708367109298706, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+627, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.462646484375, -1099.84375, 73.721435546875, 6.003028392791748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+628, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3674.749267578125, -1100.2222900390625, 73.721435546875, 6.006545543670654296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+629, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3675.2978515625, -1100.6597900390625, 73.721435546875, 0.42708367109298706, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+630, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.47314453125, -1090.1163330078125, 74.1463165283203125, 4.265368938446044921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+631, 176384, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3722.6875, -1123.4132080078125, 75.426513671875, 3.089312553405761718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Katy Stampwhistle (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 348066 - Check for Toys & Pets)
(@CGUID+632, 175796, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3719.8369140625, -1123.5242919921875, 84.59516143798828125, 3.106686115264892578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Mailroom Portal (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+633, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3686.262939453125, -1089.998291015625, 74.1019287109375, 5.652605056762695312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+634, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.497314453125, -1089.23095703125, 74.20404052734375, 5.443543910980224609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+635, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3686.108642578125, -1088.94970703125, 74.1683349609375, 3.797120094299316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+636, 176397, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3709.19970703125, -1098.9791259765625, 73.7086181640625, 4.804699897766113281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Holding Pen (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 86312 - Close)
(@CGUID+637, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.608642578125, -1088.9600830078125, 74.20919036865234375, 2.328328132629394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+638, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.200439453125, -1089.342041015625, 74.2205657958984375, 2.701267719268798828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+639, 176397, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.940185546875, -1089.6614990234375, 74.1399688720703125, 0.041587922722101211, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Holding Pen (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 86312 - Close)
(@CGUID+640, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3686.365478515625, -1089.2586669921875, 74.1335601806640625, 0.428527116775512695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+641, 175677, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3709.19970703125, -1098.9791259765625, 73.7086181640625, 3.313729763031005859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Smuggled Creature (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+642, 176395, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3696.405517578125, -1090.79345703125, 73.67438507080078125, 0.958760380744934082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Overloaded Mailemental (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+643, 176394, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3701.194580078125, -1094.68408203125, 73.7086181640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- P.O.S.T. Worker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+644, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.940185546875, -1089.6614990234375, 74.1399688720703125, 3.797120094299316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+645, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.912353515625, -1090.1927490234375, 74.11429595947265625, 3.08988046646118164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+646, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3686.52001953125, -1089.6614990234375, 74.10284423828125, 3.093397855758666992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+647, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.884521484375, -1089.3663330078125, 74.16136932373046875, 3.797120094299316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+648, 176398, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3685.19189453125, -1089.734375, 74.19171142578125, 6.056165695190429687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shipped Livestock (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 214567 - Mod Scale 90-110%)
(@CGUID+649, 176396, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3697.94189453125, -1085.6319580078125, 74.7730865478515625, 2.304351329803466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Defective Sorter (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+650, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3747.5712890625, -1139.27783203125, 73.8152313232421875, 4.37291574478149414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+651, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3756.4853515625, -1132.3160400390625, 74.15301513671875, 2.096359968185424804, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+652, 175736, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3716.017333984375, -1091.4722900390625, 74.0582122802734375, 3.608370304107666015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+653, 180561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3781.549560546875, -1167.673583984375, 76.50621795654296875, 4.813797950744628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Guest (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+654, 180818, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3747.14501953125, -1125.845458984375, 73.8152313232421875, 1.002273797988891601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oswald (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+655, 180561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3801.775146484375, -1203.96875, 76.5238189697265625, 4.813797950744628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Guest (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+656, 178962, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3754.7197265625, -1120.657958984375, 73.93377685546875, 5.178352832794189453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Xy'aro (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 120379 - Mod Scale 95-100%, 351704 - Merchant, 352120 - [DNT] Merchant Trade Area Visuals)
(@CGUID+657, 177996, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3748.234375, -1117.5694580078125, 73.8152313232421875, 2.255879640579223632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Shopper (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+658, 179556, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3398.6796875, -962.0625, 208.03973388671875, 4.459980010986328125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Broker Boat Medium 01 (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 354655 - Broker Boat Wake Effects) (possible waypoints or random movement)
(@CGUID+659, 180561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3804.03125, -1207.6475830078125, 76.4668731689453125, 2.751395940780639648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Guest (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+660, 176564, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3801.15966796875, -1185.467041015625, 75.9394378662109375, 3.908836603164672851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Zo'gron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+661, 180561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3822.618896484375, -1228.1805419921875, 76.26971435546875, 0.290121048688888549, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Guest (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+662, 180561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3827.2431640625, -1224.0035400390625, 76.246826171875, 3.741235256195068359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Guest (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+663, 179556, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3343.9951171875, -982.975830078125, 214.27996826171875, 3.901032209396362304, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Broker Boat Medium 01 (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 354655 - Broker Boat Wake Effects) (possible waypoints or random movement)
(@CGUID+664, 180562, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3822.68408203125, -1206.923583984375, 75.966552734375, 4.251708030700683593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Fruit Vendor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+665, 180565, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3784.522705078125, -1136.7760009765625, 73.98111724853515625, 1.88864445686340332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Vagabond (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+666, 180561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3827.55029296875, -1227.9913330078125, 76.40462493896484375, 2.993122577667236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Guest (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+667, 180563, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3774.507080078125, -1105.1754150390625, 73.8152313232421875, 4.17733001708984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Backalley Schemer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+668, 179556, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3757.04296875, -999.232421875, 230.2649993896484375, 5.486890316009521484, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Broker Boat Medium 01 (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 354655 - Broker Boat Wake Effects) (possible waypoints or random movement)
(@CGUID+669, 180565, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3787.309814453125, -1124.25, 73.98648834228515625, 2.520879507064819335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Bazaar Vagabond (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+670, 180563, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3775.634521484375, -1107.6336669921875, 73.8152313232421875, 3.048493862152099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Backalley Schemer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+671, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3503.233642578125, -891.02777099609375, 114.4000091552734375, 3.491705656051635742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+672, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3636.69091796875, -892.5, 114.39990234375, 6.275897979736328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+673, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3504.1572265625, -884.86114501953125, 114.4000091552734375, 2.595346450805664062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+674, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3514.20654296875, -841.8250732421875, 107.070831298828125, 1.185479998588562011, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 356711 - Haulin) (possible waypoints or random movement)
(@CGUID+675, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3500.5712890625, -840.11114501953125, 107.02490234375, 2.595346450805664062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+676, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3612.6962890625, -863.951416015625, 107.0248641967773437, 4.278838634490966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+677, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3632.5625, -858.4600830078125, 107.0248489379882812, 5.515377998352050781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+678, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3518.609375, -836.65625, 107.0546493530273437, 2.476357698440551757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+679, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3636.989501953125, -884.03125, 114.39990234375, 1.520040750503540039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+680, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3526.59033203125, -833.107666015625, 107.02490234375, 2.588059425354003906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+681, 179556, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3690.049072265625, -885.59423828125, 187.359771728515625, 4.56952524185180664, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Broker Boat Medium 01 (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 354655 - Broker Boat Wake Effects) (possible waypoints or random movement)
(@CGUID+682, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3614.8603515625, -837.201904296875, 107.1475372314453125, 5.689960956573486328, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 356711 - Haulin) (possible waypoints or random movement)
(@CGUID+683, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3634.072998046875, -838.26214599609375, 107.0248260498046875, 0.217831656336784362, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+684, 179556, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3680.734619140625, -880.15032958984375, 209.282012939453125, 5.445313453674316406, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Broker Boat Medium 01 (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 354655 - Broker Boat Wake Effects) (possible waypoints or random movement)
(@CGUID+685, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3524.138671875, -780.30194091796875, 107.078033447265625, 0.877813696861267089, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+686, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3622.54296875, -788.5439453125, 107.0780410766601562, 4.05486297607421875, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+687, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3609.583984375, -780.62652587890625, 107.0785293579101562, 2.428089618682861328, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+688, 179556, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3682.610107421875, -970.35198974609375, 287.93798828125, 1.715317726135253906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Broker Boat Medium 01 (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 354655 - Broker Boat Wake Effects)
(@CGUID+689, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3605.9970703125, -778.67584228515625, 107.0781707763671875, 2.203870773315429687, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%) (possible waypoints or random movement)
(@CGUID+690, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3490.15283203125, -788.93231201171875, 110.3873825073242187, 3.212846994400024414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+691, 180429, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3567.475830078125, -879.9774169921875, 114.7192840576171875, 4.734927177429199218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Adorned Starseer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 357276 - Stargazing)
(@CGUID+692, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3524.81591796875, -775.34375, 107.0248794555664062, 1.945224642753601074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+693, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3511.786376953125, -780.12847900390625, 107.0248794555664062, 2.524173259735107421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+694, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3613.84375, -780.48785400390625, 107.0248260498046875, 1.183002829551696777, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+695, 179799, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3584.213623046875, -897.62677001953125, 114.3999862670898437, 1.512742042541503906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Portal Authority Tunnelmancer (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+696, 180756, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3809.607666015625, -1123.5677490234375, 69.19387054443359375, 3.919121503829956054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Shady Solicitor (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+697, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3811.592041015625, -1127.9739990234375, 69.19387054443359375, 0.323949575424194335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+698, 180613, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3820.3837890625, -1159.4617919921875, 75.98241424560546875, 3.696014881134033203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Host (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+699, 180750, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3804.7119140625, -1127.9791259765625, 69.19387054443359375, 0.574109911918640136, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Au'manal (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+700, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3819.15625, -1140.392333984375, 69.19387054443359375, 0.744719982147216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+701, 180613, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3824.2197265625, -1165.87158203125, 76.84940338134765625, 3.712492227554321289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Host (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+702, 176560, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3929.7900390625, -1129.34375, 62.92864227294921875, 2.918072462081909179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- [DNT] Encounter Controller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 348397 - [DNT] Check Stage Positions)
(@CGUID+703, 179367, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3835.401123046875, -1223.1571044921875, 75.914031982421875, 0.653789818286895751, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Scavenging Skrat (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+704, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3830.93408203125, -1112.4322509765625, 69.19387054443359375, 5.046125411987304687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+705, 180613, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3849.2587890625, -1170.3680419921875, 75.94561767578125, 3.541771888732910156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Host (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+706, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3846.022705078125, -1187.529541015625, 69.2738494873046875, 0.372977852821350097, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+707, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3832.450439453125, -1114.51220703125, 69.19387054443359375, 2.021600723266601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+708, 180614, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3846.587158203125, -1117.4886474609375, 62.87752532958984375, 5.228388786315917968, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 61609), -- Oasis Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 358002 - Serving) (possible waypoints or random movement)
(@CGUID+709, 176616, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3866.482421875, -1193.9522705078125, 69.2837677001953125, 1.075543165206909179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Drinksmith (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+710, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3854.916748046875, -1136.3021240234375, 62.94514846801757812, 1.179960966110229492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+711, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3864.146728515625, -1189.9774169921875, 69.19387054443359375, 5.296068668365478515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+712, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3866.028564453125, -1127.013916015625, 60.39192581176757812, 5.188786983489990234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+713, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3852.241455078125, -1133.0069580078125, 62.94515609741210937, 0.141657263040542602, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+714, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3884.26123046875, -1174.8228759765625, 69.1935577392578125, 3.48922276496887207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+715, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3861.151123046875, -1195.375, 69.19387054443359375, 6.165600299835205078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+716, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3872.100830078125, -1104.029541015625, 65.4733734130859375, 0.675957679748535156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+717, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3882.203125, -1176.3697509765625, 69.19387054443359375, 0.464698165655136108, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+718, 180614, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3878.921875, -1155.52783203125, 69.28377532958984375, 1.230067253112792968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 358002 - Serving)
(@CGUID+719, 180755, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3851.017333984375, -1207.2379150390625, 69.25215911865234375, 0.535562753677368164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- High Roller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+720, 179551, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3862.432373046875, -1102.6319580078125, 65.46539306640625, 3.719045877456665039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+721, 180755, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3853.826416015625, -1210.5728759765625, 69.25215911865234375, 1.310440897941589355, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- High Roller (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+722, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3881.19873046875, -1152.4600830078125, 69.19129180908203125, 2.668851613998413085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+723, 180751, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3853.75, -1199.907958984375, 69.19387054443359375, 0.574469387531280517, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Handler (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+724, 179551, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 1, 3856.25341796875, -1092.529541015625, 65.4653778076171875, 3.795806169509887695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Security (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+725, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3872.236083984375, -1185.576416015625, 69.19387054443359375, 5.482066631317138671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+726, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3878.6640625, -1152.013916015625, 69.1915740966796875, 5.92751312255859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+727, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3869.657958984375, -1129.1441650390625, 60.39192581176757812, 2.614820480346679687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+728, 176615, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3882.98876953125, -1183.84033203125, 70.78118896484375, 2.325521707534790039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Waffles (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 358643 - Levitating Brew)
(@CGUID+729, 180614, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3873.103271484375, -1100.6614990234375, 65.4733734130859375, 5.110651969909667968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Oasis Server (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%, 358002 - Serving)
(@CGUID+730, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3880.96533203125, -1118.3350830078125, 60.39191436767578125, 0.482556790113449096, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+731, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3876.470458984375, -1101.890625, 65.4733734130859375, 3.891882896423339843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+732, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3882.8525390625, -1112.078125, 60.39190673828125, 0.482556790113449096, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+733, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3880.807373046875, -1125.279541015625, 60.39191436767578125, 0.482556790113449096, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+734, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3885.678955078125, -1139.4097900390625, 60.39191436767578125, 0.482556790113449096, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+735, 180158, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3887.278564453125, -1142.8853759765625, 60.39191436767578125, 1.059625983238220214, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+736, 176616, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3894.72314453125, -1178.342041015625, 69.19317626953125, 0.854617953300476074, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Speakeasy Drinksmith (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+737, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3882.078125, -1131.138916015625, 60.39191436767578125, 0.482556790113449096, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+738, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3897.7822265625, -1173.7864990234375, 69.1922607421875, 4.2015838623046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+739, 177329, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3897.27783203125, -1126.76220703125, 62.92865753173828125, 3.487105846405029296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Evaile (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 350319 - Jazzy)
(@CGUID+740, 177438, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3897.34033203125, -1126.7396240234375, 62.9388275146484375, 0.518774211406707763, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Replace Horn (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+741, 179797, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3897.364501953125, -1126.8125, 62.93880844116210937, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- [DNT] Spotlight Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+742, 180444, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3645.1728515625, -781.453125, 111.1327590942382812, 5.382303237915039062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Hired Runner (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1 (Auras: 237007 - Mod Scale 90-100%)
(@CGUID+743, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3888.286376953125, -1092.8367919921875, 65.46537017822265625, 5.415452957153320312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+744, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3894.02783203125, -1144.361083984375, 60.39191436767578125, 0.482556790113449096, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+745, 179785, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3903.069580078125, -1108.3697509765625, 62.93673324584960937, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Replace Saxophone (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+746, 179786, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3914.739501953125, -1130.5, 62.9366302490234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Replace Trumpet (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+747, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3906.237060546875, -1179.826416015625, 69.193359375, 3.503364324569702148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+748, 179797, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3903.322021484375, -1123.3004150390625, 62.93814849853515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- [DNT] Spotlight Stalker (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+749, 176660, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3903.77783203125, -1123.015625, 62.93794631958007812, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Replace Guitar (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+750, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3926.853271484375, -1147.28125, 69.18817138671875, 2.637006282806396484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+751, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3905.986083984375, -1182.203125, 69.193572998046875, 2.041192531585693359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+752, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3904.177978515625, -1181.373291015625, 69.193389892578125, 0.461122065782546997, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+753, 180158, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3902.82470703125, -1147.43408203125, 60.39190673828125, 0.482556790113449096, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609), -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
(@CGUID+754, 176561, 2441, 13577, 13577, '23,2,8', '0', 0, 0, 0, 3920.663330078125, -1159.173583984375, 69.18819427490234375, 3.741235017776489257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61609); -- Unruly Patron (Area: Tazavesh, the Veiled Market - Difficulty: Mythic) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+754;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Cartel Wiseguy
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Cartel Smuggler
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Hungry Laborer
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Shipping Facilitator
(@CGUID+16, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '356251'), -- Aqir Impaler - 356251 - Hyperlight Containment Cell
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Toy Vendor
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, '357022'), -- Fe'tajid - 357022 - [DNT] Aura Update Interact
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Hungry Laborer
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Dozing Laborer
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Shipping Facilitator
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Hungry Laborer
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Hungry Laborer
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Hungry Laborer
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Dozing Laborer
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Antique Vendor
(@CGUID+46, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Dozing Laborer
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Chef
(@CGUID+58, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '237007'), -- Terminal Attendant - 237007 - Mod Scale 90-100%
(@CGUID+86, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '323486'), -- Armored Overseer - 323486 - Dual Wield
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '237007'), -- Terminal Attendant - 237007 - Mod Scale 90-100%
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '237007'), -- Terminal Attendant - 237007 - Mod Scale 90-100%
(@CGUID+104, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, '237007'), -- Terminal Attendant - 237007 - Mod Scale 90-100%
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356570'), -- Shopkeeper - 356570 - [DNT] Aura Vendor AreaTrigger
(@CGUID+117, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356716'), -- Export Supervisor - 356716 - Reading
(@CGUID+119, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '323486'), -- Armored Overseer - 323486 - Dual Wield
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356762'), -- Culinary Assistant - 356762 - [DNT] Carry Food Stuffs
(@CGUID+136, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356716'), -- Export Supervisor - 356716 - Reading
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356756'), -- Export Hauler - 356756 - [DNT] Carry Stuff
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Market Server
(@CGUID+140, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Export Hauler
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356716'), -- Export Supervisor - 356716 - Reading
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Market Chef
(@CGUID+143, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Export Hauler
(@CGUID+145, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Hungry Patron
(@CGUID+146, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Market Server
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Export Hauler
(@CGUID+155, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356756'), -- Export Hauler - 356756 - [DNT] Carry Stuff
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Hungry Patron
(@CGUID+158, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Hungry Patron
(@CGUID+159, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Xy'rihn the Keen
(@CGUID+162, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Hungry Patron
(@CGUID+164, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Export Hauler
(@CGUID+172, 0, 0, 0, 0, 0, 1, 0, 900, 0, 0, 0, 0, ''), -- Export Hauler
(@CGUID+184, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356716'), -- Export Supervisor - 356716 - Reading
(@CGUID+193, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Market Patron
(@CGUID+195, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Market Patron
(@CGUID+197, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, ''), -- Export Hauler
(@CGUID+198, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Market Patron
(@CGUID+200, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Market Patron
(@CGUID+201, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Market Patron
(@CGUID+203, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Market Patron
(@CGUID+206, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Market Patron
(@CGUID+211, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Relaxed Patron
(@CGUID+212, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Cartel Wiseguy
(@CGUID+213, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Export Hauler
(@CGUID+219, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356716'), -- Export Supervisor - 356716 - Reading
(@CGUID+225, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+226, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Relaxed Patron
(@CGUID+227, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, ''), -- Relaxed Patron
(@CGUID+228, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Shady Dealer
(@CGUID+233, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+235, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Shady Dealer
(@CGUID+237, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+242, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356765'), -- Patio Waiter - 356765 - [DNT] Serve Food
(@CGUID+243, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Cartel Wiseguy
(@CGUID+244, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Relaxed Patron
(@CGUID+246, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Cartel Smuggler
(@CGUID+248, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Cartel Muscle
(@CGUID+265, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Shady Dealer
(@CGUID+266, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+272, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+274, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+275, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, '356864'), -- Shop Patron - 356864 - North Side  Rename Spawn Spell
(@CGUID+276, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Cartel Smuggler
(@CGUID+277, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Shady Dealer
(@CGUID+278, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356716'), -- Export Supervisor - 356716 - Reading
(@CGUID+281, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Cartel Wiseguy
(@CGUID+289, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Shady Dealer
(@CGUID+292, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Devourer Mite
(@CGUID+293, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+301, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Cartel Wiseguy
(@CGUID+305, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+309, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, ''), -- Cartel Smuggler
(@CGUID+313, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Cartel Muscle
(@CGUID+314, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+325, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+326, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+331, 0, 0, 0, 0, 0, 1, 0, 0, 8859, 0, 0, 0, ''), -- Devourer Mite
(@CGUID+334, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+335, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Cartel Wiseguy
(@CGUID+336, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+337, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+339, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, ''), -- Shady Dealer 
(@CGUID+344, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Cartel Smuggler
(@CGUID+348, 0, 0, 0, 0, 0, 1, 0, 0, 23134, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+352, 0, 0, 0, 0, 0, 1, 0, 0, 23135, 0, 0, 0, '237007'), -- Bazaar Shopper - 237007 - Mod Scale 90-100%
(@CGUID+356, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, '237007'), -- Backalley Schemer - 237007 - Mod Scale 90-100%
(@CGUID+434, 0, 0, 0, 0, 0, 1, 0, 455, 0, 0, 0, 0, ''),
(@CGUID+463, 0, 0, 0, 3, 0, 1, 0, 455, 0, 0, 0, 0, ''),
(@CGUID+555, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, ''), -- Commerce Enforcer
(@CGUID+653, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Oasis Guest - 237007 - Mod Scale 90-100%
(@CGUID+655, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Oasis Guest - 237007 - Mod Scale 90-100%
(@CGUID+659, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Oasis Guest - 237007 - Mod Scale 90-100%
(@CGUID+660, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Zo'gron
(@CGUID+661, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Oasis Guest - 237007 - Mod Scale 90-100%
(@CGUID+662, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Oasis Guest - 237007 - Mod Scale 90-100%
(@CGUID+666, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '237007'), -- Oasis Guest - 237007 - Mod Scale 90-100%
(@CGUID+667, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, '237007'); -- Backalley Schemer - 237007 - Mod Scale 90-100%

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+56;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 369744, 2441, 13577, 13577, '23,2,8', '0', 0, 3566.266357421875, -819.649658203125, 108.470123291015625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 0, 61967), -- Energy Barrier (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+1, 369316, 2441, 13577, 13577, '23,2,8', '0', 0, 3596.484619140625, -1497.988037109375, 93.56156158447265625, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 86400, 255, 1, 61967), -- Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+2, 369317, 2441, 13577, 13577, '23,2,8', '0', 0, 3588.68115234375, -899.8076171875, 114.3051910400390625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 61967), -- Portal to Customs (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+3, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3492.559814453125, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+4, 369315, 2441, 13577, 13577, '23,2,8', '0', 0, 3596.8046875, -1510.46435546875, 106.0002517700195312, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 86400, 255, 1, 61967), -- Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+5, 369260, 2441, 13577, 13577, '23,2,8', '0', 0, 3655.9736328125, -1202.598876953125, 73.847503662109375, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 86400, 255, 1, 61967), -- Portal to Customs (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+6, 368938, 2441, 13577, 13577, '23,2,8', '0', 0, 3746.939453125, -1162.279541015625, 74.1822357177734375, 3.130894899368286132, 0, 0, 0.999985694885253906, 0.005348853301256895, 86400, 255, 1, 61967), -- Portal to Customs (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+7, 369890, 2441, 13577, 13577, '23,2,8', '0', 0, 3651.575439453125, -1563.5208740234375, 93.2502288818359375, 0.809137582778930664, 0, 0, 0.393622398376464843, 0.919272243976593017, 86400, 255, 1, 61967), -- Expedition Report A37J - Part 2 (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+8, 369258, 2441, 13577, 13577, '23,2,8', '0', 0, 3503.295166015625, -1299.620361328125, 73.84748077392578125, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 86400, 255, 1, 61967), -- Portal to Customs (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+9, 369891, 2441, 13577, 13577, '23,2,8', '0', 0, 3585.30029296875, -1586, 108.8809432983398437, 5.241250038146972656, 0, 0, -0.49771976470947265, 0.86733788251876831, 86400, 255, 1, 61967), -- Expedition Report A37J - Part 3 (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+10, 368246, 2441, 13577, 13577, '23,2,8', '0', 0, 3802.552978515625, -1182.2984619140625, 76.01384735107421875, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 86400, 255, 1, 61967), -- Door (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+11, 365351, 2441, 13577, 13577, '23,2,8', '0', 0, 3609.935791015625, -1555.6185302734375, 106.15667724609375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 61967), -- Door (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+12, 368247, 2441, 13577, 13577, '23,2,8', '0', 0, 3431.483642578125, -1295.3753662109375, 73.7119293212890625, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 86400, 255, 1, 61967), -- Door (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+13, 326155, 2441, 13577, 13577, '23,2,8', '0', 0, 3643.640625, -1801.201416015625, 92.4810028076171875, 4.142352581024169921, 0, 0, -0.87740039825439453, 0.479758828878402709, 86400, 255, 1, 61967), -- Collision Object (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+14, 343702, 2441, 13577, 13577, '23,2,8', '0', 0, 3641.11376953125, -1798.454833984375, 92.48101806640625, 3.683762550354003906, 0, 0, -0.96348094940185546, 0.267776846885681152, 86400, 255, 1, 61967), -- Collision Cylinder (0.80) (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+15, 365352, 2441, 13577, 13577, '23,2,8', '0', 0, 3609.935791015625, -1722.697265625, 106.1566696166992187, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 86400, 255, 1, 61967), -- Customs Enforcement Door (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+16, 368248, 2441, 13577, 13577, '23,2,8', '0', 0, 3431.44189453125, -1246.96484375, 73.7119293212890625, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 86400, 255, 0, 61967), -- Menagerie Door (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+17, 365353, 2441, 13577, 13577, '23,2,8', '0', 0, 3669.245849609375, -1161.827392578125, 73.88088226318359375, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 86400, 255, 0, 61967), -- Mailroom Entrance (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+18, 368249, 2441, 13577, 13577, '23,2,8', '0', 0, 3481.945556640625, -1324.55126953125, 73.709136962890625, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 86400, 255, 1, 61967), -- Door (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+19, 326155, 2441, 13577, 13577, '23,2,8', '0', 0, 3640.7978515625, -1801.1285400390625, 92.4810028076171875, 4.142352581024169921, 0, 0, -0.87740039825439453, 0.479758828878402709, 86400, 255, 1, 61967), -- Collision Object (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+20, 368250, 2441, 13577, 13577, '23,2,8', '0', 0, 3481.939208984375, -1217.8514404296875, 73.70972442626953125, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 86400, 255, 0, 61967), -- Door (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+21, 368580, 2441, 13577, 13577, '23,2,8', '0', 0, 3661.803466796875, -1670.30078125, 106.6638641357421875, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 86400, 255, 1, 61967), -- Portal to Myza's Oasis (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+22, 368581, 2441, 13577, 13577, '23,2,8', '0', 0, 3682.55322265625, -1639.171630859375, 106.7036666870117187, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 61967), -- Portal to the Opulent Nexus (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+23, 368577, 2441, 13577, 13577, '23,2,8', '0', 0, 3674.18603515625, -1611.2802734375, 106.6583023071289062, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 86400, 255, 1, 61967), -- Portal to The Grand Menagerie (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+24, 368578, 2441, 13577, 13577, '23,2,8', '0', 0, 3661.8369140625, -1608.0947265625, 106.6583023071289062, 4.45059061050415039, 0, 0, -0.79335308074951171, 0.608761727809906005, 86400, 255, 1, 61967), -- Portal to the Lap of Luxury (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+25, 368579, 2441, 13577, 13577, '23,2,8', '0', 0, 3674.00537109375, -1667.1512451171875, 106.663848876953125, 1.832594871520996093, 0, 0, 0.793353080749511718, 0.608761727809906005, 86400, 255, 1, 61967), -- Portal to The P.O.S.T. (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+26, 369467, 2441, 13577, 13577, '23,2,8', '0', 0, 3668.8837890625, -1474.2137451171875, 93.23809051513671875, 3.403396368026733398, 0, 0, -0.99144458770751953, 0.130528271198272705, 86400, 255, 1, 61967), -- Mailbox (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+27, 369466, 2441, 13577, 13577, '23,2,8', '0', 0, 3759.882080078125, -1409.46630859375, 73.71128082275390625, 3.141592741012573242, 0, 0, -1, 0, 86400, 255, 1, 61967), -- Mailbox (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+28, 369889, 2441, 13577, 13577, '23,2,8', '0', 0, 3541.432373046875, -1344.9114990234375, 65.81578826904296875, 6.08640146255493164, 0, 0, -0.09823322296142578, 0.995163440704345703, 86400, 255, 1, 61967), -- Expedition Report A37J - Part 1 (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+29, 368937, 2441, 13577, 13577, '23,2,8', '0', 0, 3751.432861328125, -1298.2178955078125, 74.02972412109375, 1.535714507102966308, 0, 0, 0.6945953369140625, 0.719400703907012939, 86400, 255, 1, 61967), -- Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+30, 369887, 2441, 13577, 13577, '23,2,8', '0', 0, 3770.673583984375, -1240.9947509765625, 73.73189544677734375, 5.241250038146972656, 0, 0, -0.49771976470947265, 0.86733788251876831, 86400, 255, 1, 61967), -- Cartel Al Incident Report (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+31, 369464, 2441, 13577, 13577, '23,2,8', '0', 0, 3674.37890625, -1177.577392578125, 73.61466217041015625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 86400, 255, 1, 61967), -- Mailbox (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+32, 368943, 2441, 13577, 13577, '23,2,8', '0', 0, 3696.4072265625, -1168.9923095703125, 74.64334869384765625, 1.57079315185546875, 0, 0, 0.707105636596679687, 0.707107901573181152, 86400, 255, 1, 61967), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+33, 369465, 2441, 13577, 13577, '23,2,8', '0', 0, 3653.58203125, -1156.37890625, 73.61466217041015625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 86400, 255, 1, 61967), -- Mailbox (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+34, 368940, 2441, 13577, 13577, '23,2,8', '0', 0, 3662.011962890625, -1133.775146484375, 74.64333343505859375, 0, 0, 0, 0, 1, 86400, 255, 1, 61967), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+35, 368941, 2441, 13577, 13577, '23,2,8', '0', 0, 3662.011962890625, -1113.0069580078125, 74.64333343505859375, 0, 0, 0, 0, 1, 86400, 255, 1, 61967), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+36, 368939, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.6298828125, -1143.38525390625, 81.0930023193359375, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 86400, 255, 1, 61967), -- Signature Authorization Device and Transport Facility (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+37, 368942, 2441, 13577, 13577, '23,2,8', '0', 0, 3715.25048828125, -1091.744384765625, 74.64334869384765625, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 86400, 255, 1, 61967), -- Delivery Portal (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+38, 369259, 2441, 13577, 13577, '23,2,8', '0', 0, 3512.4111328125, -1178.7630615234375, 73.84749603271484375, 3.665196180343627929, 0, 0, -0.96592521667480468, 0.258821308612823486, 86400, 255, 1, 61967), -- Portal to Customs (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+39, 365063, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.70654296875, -1143.4149169921875, 115.8447265625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+40, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.70654296875, -1143.4149169921875, 115.8447265625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+41, 369888, 2441, 13577, 13577, '23,2,8', '0', 0, 3675.89501953125, -1082.703125, 74.7859954833984375, 1.522884726524353027, 0, 0, 0.689966201782226562, 0.723841607570648193, 86400, 255, 1, 61967), -- Expedition Report A37J - Foreword (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+42, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3617.56005859375, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+43, 370083, 2441, 13577, 13577, '23,2,8', '0', 0, 3893.630126953125, -1128.7742919921875, 63.1267242431640625, 0.539607822895050048, 0, 0, 0.266542434692382812, 0.963823199272155761, 86400, 255, 1, 61967), -- Microphone Stand (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+44, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.559814453125, -1131.6353759765625, 114.3050003051757812, 0, 0, 0, 0, 1, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+45, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3642.56005859375, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+46, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3592.56005859375, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+47, 368990, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.559814453125, -1097.8316650390625, 114.3051605224609375, 0, 0, 0, 0, 1, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+48, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.559814453125, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+49, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.559814453125, -1106.6353759765625, 114.3050003051757812, 0, 0, 0, 0, 1, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+50, 365063, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.559814453125, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+51, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.559814453125, -1081.63720703125, 114.3050003051757812, 0, 0, 0, 0, 1, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+52, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3542.56005859375, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+53, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3517.56005859375, -1097.8316650390625, 114.3051605224609375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 0, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+54, 375002, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.70654296875, -1062.9288330078125, 115.8447265625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+55, 375003, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.70654296875, -1062.9288330078125, 115.8447265625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 86400, 255, 1, 61967), -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
(@OGUID+56, 368991, 2441, 13577, 13577, '23,2,8', '0', 0, 3567.559814453125, -1056.6353759765625, 114.3050003051757812, 0, 0, 0, 0, 1, 86400, 255, 0, 61967); -- Force Field (Area: Tazavesh, the Veiled Market - Difficulty: Heroic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+57;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Energy Barrier
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+8, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal to Customs
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+15, 0, 0, 1, -0.00000004371138828, 0, 0), -- Customs Enforcement Door
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- Menagerie Door
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Mailroom Entrance
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 8414), -- Portal to Myza's Oasis
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 8414), -- Portal to the Opulent Nexus
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 8414), -- Portal to The Grand Menagerie
(@OGUID+24, 0, 0, 1, -0.00000004371138828, 0, 8414), -- Portal to the Lap of Luxury
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 8414), -- Portal to The P.O.S.T.
(@OGUID+26, 0, 0, 1, -0.00000004371138828, 0, 0), -- Mailbox
(@OGUID+27, 0, 0, 1, -0.00000004371138828, 0, 0), -- Mailbox
(@OGUID+29, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal
(@OGUID+31, 0, 0, 1, -0.00000004371138828, 0, 0), -- Mailbox
(@OGUID+32, 0, 0, 1, -0.00000004371138828, 0, 0), -- Delivery Portal
(@OGUID+33, 0, 0, 1, -0.00000004371138828, 0, 0), -- Mailbox
(@OGUID+34, 0, 0, 1, -0.00000004371138828, 0, 0), -- Delivery Portal
(@OGUID+35, 0, 0, 1, -0.00000004371138828, 0, 0), -- Delivery Portal
(@OGUID+36, 0, 0, 1, -0.00000004371138828, 0, 0), -- Signature Authorization Device and Transport Facility
(@OGUID+37, 0, 0, 1, -0.00000004371138828, 0, 0), -- Delivery Portal
(@OGUID+38, 0, 0, 1, -0.00000004371138828, 0, 0); -- Portal to Customs

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (179821,176384,175796,178962,179556,180852,180846,176705,176556,180567,176555,177994,177756,177998,177760,175646,177995,177753,178383,177755,177752,177757,179886,176896,175806,176519,176396,176397,176398,176394,179841, 179840, 177999, 177996, 180565, 176514, 180563, 180566, 180310 /*180310 (Shop Patron) - North Side  Rename Spawn Spell*/, 180390 /*180390 (Dantun) - Energy Cage*/, 180091 /*180091 (Ancient Core Hound) - Emanating Heat, Heated*/, 179837 /*179837 (Tracker Zo'korss) - [DNT] Send Event <Points> On Enter Combat, Invisibility and Stealth Detection*/, 180249 /*180249 (Market Server) - [DNT] Serve Food*/, 180244 /*180244 (Culinary Assistant) - [DNT] Carry Food Stuffs*/, 180161 /*180161 (Shopkeeper) - [DNT] Aura Vendor AreaTrigger*/, 177808 /*177808 (Armored Overseer) - [DNT] Send Event <Points> On Enter Combat, Dual Wield*/, 179334 /*179334 (Portalmancer Zo'honn) - Rename Spawn Spell, [DNT] Send Event <Points> On Enter Combat, Stabilize Portal*/, 177807 /*177807 (Customs Security) - [DNT] Send Event <Points> On Enter Combat*/, 177817 /*177817 (Support Officer) - Refraction Shield, [DNT] Send Event <Points> On Enter Combat*/, 177816 /*177816 (Interrogation Specialist) - Mod Scale 90-100%, [DNT] Send Event <Points> On Enter Combat*/, 177672 /*177672 (Terminal Attendant) - Mod Scale 90-100%*/, 176759 /*176759 (Xy'nam)*/, 176758 /*176758 (Xy'noc)*/, 179983 /*179983 (Dozing Laborer)*/, 180056 /*180056 (Empty Hyperspatial Container) - Hyperlight Containment Cell*/, 178392 /*178392 (Gatewarden Zo'mazz) - Broker Energy Shield Cosmetic*/, 178074 /*178074 (Al'dalil)*/, 179011 /*179011 (Shipping Facilitator) - Broker Carry Box Aura*/, 180322 /*180322 (Fe'tajid) - [DNT] Aura Update Interact*/, 180510 /*180510 (Toxic Saurid) - Hyperlight Containment Cell*/, 180153 /*180153 (Aqir Impaler) - Hyperlight Containment Cell*/, 180092, 165855, 179515 /*179515 (Shipping Facilitator)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(179821, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '18950'), -- 179821 (Commander Zo'far) - Invisibility and Stealth Detection
(176384, 0, 0, 0, 0, 0, 1, 0, 0, 2923, 0, 0, 0, '348066'), -- 176384 (Katy Stampwhistle) - Check for Toys & Pets
(175796, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 175796 (Mailroom Portal)
(178962, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '120379 352120'), -- 178962 (Xy'aro) - Mod Scale 95-100%, Merchant, [DNT] Merchant Trade Area Visuals
(179556, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '354655'), -- 179556 (Broker Boat Medium 01) - Broker Boat Wake Effects
(180852, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '87966'), -- 180852 (Infested Bear) - Feeding the Brood
(180846, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '19502'), -- 180846 (Sickly Gazelle) - Sickly Critter Aura
(176705, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 176705 (Venza Goldfuse)
(176556, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '349091'), -- 176556 (Alcruux) - Energy Cage
(180567, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '357832'), -- 180567 (Frenzied Nightclaw) - Energy Cage
(176555, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '349274'), -- 176555 (Achillite) - Powered Down
(177994, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567 352120'), -- 177994 (Xy'har) - Mod Scale 90-110%, Merchant, [DNT] Merchant Trade Area Visuals
(177756, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '351704 352120'), -- 177756 (Xy'aqida) - Merchant, [DNT] Merchant Trade Area Visuals
(177998, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567 352120'), -- 177998 (Xy'nara) - Mod Scale 90-110%, Merchant, [DNT] Merchant Trade Area Visuals
(177760, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '351704 352120'), -- 177760 (Xy'kitaab) - Merchant, [DNT] Merchant Trade Area Visuals
(175646, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '346322'), -- 175646 (P.O.S.T. Master) - Override Energy Bar Color (Blue)
(177995, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567 352120'), -- 177995 (Xy'zaro) - Mod Scale 90-110%, Merchant, [DNT] Merchant Trade Area Visuals
(177753, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567 352120'), -- 177753 (Xy'mal) - Mod Scale 90-110%, Merchant, [DNT] Merchant Trade Area Visuals
(178383, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '351930'), -- 178383 ([DNT] Controller) - [DNT] Periodic Wave Spawn Control Aura
(177755, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567 352120'), -- 177755 (Xy'jahid) - Mod Scale 90-110%, Merchant, [DNT] Merchant Trade Area Visuals
(177752, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007 352120'), -- 177752 (Xy'ghana) - Mod Scale 90-100%, Merchant, [DNT] Merchant Trade Area Visuals
(177757, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007 352120'), -- 177757 (Xy'tadir) - Mod Scale 90-100%, Merchant, [DNT] Merchant Trade Area Visuals
(179886, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '355662'), -- 179886 (Auction Bidder) - Auction Rename Spawn Spell
(176896, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '349296'), -- 176896 (Edge of Annihilation) - Edge of Annhiliation Cosmetic
(175806, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 175806 (So'azmi)
(176519, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '348002'), -- 176519 (Customer VO Controller) - Ping Random Unique Customer
(176396, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '347931'), -- 176396 (Defective Sorter) - Cosmetic Letter Spit
(176397, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '86312'), -- 176397 (Holding Pen) - Close
(176398, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 176398 (Shipped Livestock) - Mod Scale 90-110%
(176394, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 176394 (P.O.S.T. Worker) - Mod Scale 90-110%
(179841, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 179841 (Veteran Sparkcaster)
(179840, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '356089'), -- 179840 (Market Peacekeeper) - Broker Energy Shield Cosmetic
(177999, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007 352121'), -- 177999 (Xy'darid) - Mod Scale 90-100%, [DNT] Prepurchase Glow
(177996, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007'), -- 177996 (Bazaar Shopper) - Mod Scale 90-100%
(180565, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007'), -- 180565 (Bazaar Vagabond) - Mod Scale 90-100%
(176514, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '214567'), -- 176514 (Angry Customer) - Mod Scale 90-110%
(180563, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007'), -- 180563 (Backalley Schemer) - Mod Scale 90-100%
(180566, 0, 0, 0, 3, 0, 1, 0, 0, 8800, 0, 0, 0, '357798'), -- 180566 (Rat of Unusual Size) - Hyperlight Containment Cell
(180310, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356864'), -- 180310 (Shop Patron) - North Side  Rename Spawn Spell
(180390, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '357150'), -- 180390 (Dantun) - Energy Cage
(180091, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356424 357823'), -- 180091 (Ancient Core Hound) - Emanating Heat, Heated
(179837, 0, 0, 0, 0, 0, 1, 0, 0, 22905, 0, 0, 0, '355784 18950'), -- 179837 (Tracker Zo'korss) - [DNT] Send Event <Points> On Enter Combat, Invisibility and Stealth Detection
(180249, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356765'), -- 180249 (Market Server) - [DNT] Serve Food
(180244, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356762'), -- 180244 (Culinary Assistant) - [DNT] Carry Food Stuffs
(180161, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356570'), -- 180161 (Shopkeeper) - [DNT] Aura Vendor AreaTrigger
(177808, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '355784 323486'), -- 177808 (Armored Overseer) - [DNT] Send Event <Points> On Enter Combat, Dual Wield
(179334, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356319 355784 352411'), -- 179334 (Portalmancer Zo'honn) - Rename Spawn Spell, [DNT] Send Event <Points> On Enter Combat, Stabilize Portal
(177807, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '355784'), -- 177807 (Customs Security) - [DNT] Send Event <Points> On Enter Combat
(177817, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '355980 355784'), -- 177817 (Support Officer) - Refraction Shield, [DNT] Send Event <Points> On Enter Combat
(177816, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007 355784'), -- 177816 (Interrogation Specialist) - Mod Scale 90-100%, [DNT] Send Event <Points> On Enter Combat
(177672, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '237007'), -- 177672 (Terminal Attendant) - Mod Scale 90-100%
(176759, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''), -- 176759 (Xy'nam)
(176758, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 5, ''), -- 176758 (Xy'noc)
(179983, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 179983 (Dozing Laborer)
(180056, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356251'), -- 180056 (Empty Hyperspatial Container) - Hyperlight Containment Cell
(178392, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356089'), -- 178392 (Gatewarden Zo'mazz) - Broker Energy Shield Cosmetic
(178074, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 178074 (Al'dalil)
(179011, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '353213'), -- 179011 (Shipping Facilitator) - Broker Carry Box Aura
(180322, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '357022'), -- 180322 (Fe'tajid) - [DNT] Aura Update Interact
(180510, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '357798'), -- 180510 (Toxic Saurid) - Hyperlight Containment Cell
(180153, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '356251'), -- 180153 (Aqir Impaler) - Hyperlight Containment Cell
(180092, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '356560'), -- 180092 (Giant Hive Guardian) - Hyperlight Containment Cell
(165855, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356251'), -- 165855 (Moonfrog) - Hyperlight Containment Cell
(179515, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 179515 (Shipping Facilitator)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (375003 /*Force Field*/, 375002 /*Force Field*/, 368990 /*Force Field*/, 370083 /*Microphone Stand*/, 368991 /*Force Field*/, 365063 /*Force Field*/, 368939 /*Signature Authorization Device and Transport Facility*/, 368579 /*Portal to The P.O.S.T.*/, 368578 /*Portal to the Lap of Luxury*/, 368577 /*Portal to The Grand Menagerie*/, 368581 /*Portal to the Opulent Nexus*/, 368580 /*Portal to Myza's Oasis*/, 368250 /*Door*/, 368249 /*Door*/, 365353 /*Mailroom Entrance*/, 368248 /*Menagerie Door*/, 365352 /*Customs Enforcement Door*/, 343702 /*Collision Cylinder (0.80)*/, 368247 /*Door*/, 365351 /*Door*/, 368246 /*Door*/, 369258 /*Portal to Customs*/, 368938 /*Portal to Customs*/, 369260 /*Portal to Customs*/, 369317 /*Portal to Customs*/, 369744 /*Energy Barrier*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(375003, 114, 0x0, 0, 0), -- Force Field
(375002, 114, 0x0, 0, 0), -- Force Field
(368990, 114, 0x0, 0, 0), -- Force Field
(370083, 0, 0x10, 0, 0), -- Microphone Stand
(368991, 114, 0x0, 0, 0), -- Force Field
(365063, 114, 0x0, 0, 0), -- Force Field
(368939, 0, 0x10, 0, 0), -- Signature Authorization Device and Transport Facility
(368579, 0, 0x0, 0, 8414), -- Portal to The P.O.S.T.
(368578, 0, 0x0, 0, 8414), -- Portal to the Lap of Luxury
(368577, 0, 0x0, 0, 8414), -- Portal to The Grand Menagerie
(368581, 0, 0x0, 0, 8414), -- Portal to the Opulent Nexus
(368580, 0, 0x0, 0, 8414), -- Portal to Myza's Oasis
(368250, 0, 0x30, 0, 0), -- Door
(368249, 0, 0x30, 0, 0), -- Door
(365353, 0, 0x30, 0, 0), -- Mailroom Entrance
(368248, 0, 0x30, 0, 0), -- Menagerie Door
(365352, 0, 0x30, 0, 0), -- Customs Enforcement Door
(343702, 0, 0x20, 0, 0), -- Collision Cylinder (0.80)
(368247, 0, 0x30, 0, 0), -- Door
(365351, 0, 0x30, 0, 0), -- Door
(368246, 0, 0x32, 0, 0), -- Door
(369258, 0, 0x30, 0, 0), -- Portal to Customs
(368938, 0, 0x30, 0, 0), -- Portal to Customs
(369260, 0, 0x30, 0, 0), -- Portal to Customs
(369317, 0, 0x30, 0, 0), -- Portal to Customs
(369744, 0, 0x30, 0, 0); -- Energy Barrier

-- Templates
UPDATE `creature_template_addon` SET `auras`='87978 84461' WHERE `entry`=47203; -- 47203 (Creeper Egg) - Creeper Egg, Sparkle Aura
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=176514; -- Angry Customer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=180563; -- Backalley Schemer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=180566; -- Rat of Unusual Size
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x800 WHERE `entry`=180495; -- Enraged Direhorn
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=179167; -- Damp Skrat
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180328; -- Au'ri
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.714285731315612792, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=180348; -- Cartel Muscle
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180314; -- Patio Waiter
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180315; -- Shady Dealer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=1500, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180310; -- Shop Patron
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180320; -- Illicit Purveyor
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180443; -- Exotic Reseller
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180442; -- Novice Acquirer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=1500, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180390; -- Dantun
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=180335; -- Cartel Smuggler
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry` IN (180150, 180149); -- Relaxed Patron
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x820, `unit_flags3`=0x41000001, `AIName`='SmartAI' WHERE `entry`=180072; -- Tether Post
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.60000002384185791, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=180336; -- Cartel Wiseguy
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry` IN (179947, 179948); -- Impressed Patron
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180091; -- Ancient Core Hound
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=180822; -- Goblin
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180147; -- Well-informed Trader
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `AIName`='SmartAI' WHERE `entry`=179837; -- Tracker Zo'korss
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180327; -- Au'mba
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180148; -- Coin Changer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180260; -- Spice Trader Au'saar
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry` IN (180241, 180215); -- Export Hauler
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180266; -- Ta'ules
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180295; -- Xy'rihn the Keen
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180247; -- Hungry Hauler
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180268; -- Ta'sam
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179795; -- Ta'speri
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179796; -- Ta'leesa
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180248; -- Hungry Patron
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180243; -- Market Chef
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180249; -- Market Server
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180244; -- Culinary Assistant
UPDATE `creature_template` SET `faction`=31, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=180269; -- Curiosity
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180754; -- Questionable Trader
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180267; -- Ta'rex
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180228; -- Export Supervisor
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=180161; -- Shopkeeper
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=179168; -- Scavenging Skrat
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180261; -- Market Patron
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=179367; -- Scavenging Skrat
UPDATE `creature_template` SET `faction`=16, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=177259; -- Zo'pare
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x800, `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry`=179121; -- Zo'phex Cosmetic Summon Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags2`=0x800 WHERE `entry`=177808; -- Armored Overseer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags2`=0x800 WHERE `entry`=179334; -- Portalmancer Zo'honn
UPDATE `creature_template` SET `faction`=14, `npcflag`=2097152, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=177255; -- Contraband Auctioneer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x800, `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry`=178545; -- Watch-Agent Summon Stalker
UPDATE `creature_template` SET `faction`=16, `npcflag`=131076, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=177239; -- Collector of Worth
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=180824; -- Waffle
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1500, `unit_flags2`=0x800 WHERE `entry`=177817; -- Support Officer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=177816; -- Interrogation Specialist
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=1500, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=177672; -- Terminal Attendant
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `AIName`='SmartAI' WHERE `entry`=180156; -- Enthusiastic Trader
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=0x800, `AIName`='SmartAI' WHERE `entry`=180114; -- Fruit Vendor
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=0x800, `AIName`='SmartAI' WHERE `entry`=180117; -- Meat Vendor
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=1500, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=177868; -- Creature Collector
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176759; -- Xy'nam
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176758; -- Xy'noc
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179981; -- Chef
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=180130; -- Antique Vendor
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x820, `unit_flags3`=0x1000001 WHERE `entry`=180056; -- Empty Hyperspatial Container
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=178392; -- Gatewarden Zo'mazz
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry` IN (178074, 179519); -- Al'dalil
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=1500, `unit_flags2`=0x800 WHERE `entry`=177807; -- Customs Security
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry` IN (179011, 180152); -- Shipping Facilitator
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179983; -- Dozing Laborer
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=179366; -- Damp Skrat
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180322; -- Fe'tajid
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=180129; -- Toy Vendor
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=180510; -- Toxic Saurid
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=180153; -- Aqir Impaler
UPDATE `creature_template` SET `faction`=35, `unit_flags3`=0x4000000 WHERE `entry`=97809; -- Coastal Seagull
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179982; -- Hungry Laborer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180092; -- Giant Hive Guardian
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x800 WHERE `entry`=180567; -- Frenzied Nightclaw
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180095; -- Ankylodon Bull
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x4000800, `unit_flags3`=0x41008001, `AIName`='SmartAI' WHERE `entry` IN (179843, 179844); -- Shocklight Barrier
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179909; -- Curious Onlooker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177996; -- Bazaar Shopper
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180317; -- Illicit Hauler
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=180855; -- Devourer Mite
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=180565; -- Bazaar Vagabond
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177999; -- Xy'darid
UPDATE `creature_template` SET `faction`=190, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x300 WHERE `entry`=176564; -- Zo'gron
UPDATE `creature_template` SET `faction`=35, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=180562; -- Fruit Vendor
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=180561; -- Oasis Guest
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800, `AIName`='SmartAI' WHERE `entry`=179842; -- Commerce Enforcer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `AIName`='SmartAI' WHERE `entry`=179908; -- Distressed Merchant
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179909; -- Curious Onlooker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=179841; -- Veteran Sparkcaster
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=179840; -- Market Peacekeeper
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.699999988079071044, `speed_run`=0.25, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180858; -- Nether Beast
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180848; -- Dew Monster
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000, `VehicleId`=1251 WHERE `entry`=180852; -- Infested Bear
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=175677; -- Smuggled Creature
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000340, `unit_flags2`=0x800, `unit_flags3`=0x41000001 WHERE `entry`=176217; -- So'azmi
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176395; -- Overloaded Mailemental
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176394; -- P.O.S.T. Worker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=175736; -- Delivery Portal
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800 WHERE `entry`=176398; -- Shipped Livestock
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41000000 WHERE `entry`=176397; -- Holding Pen
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176396; -- Defective Sorter
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x800, `unit_flags3`=0x41000000, `flags_extra` = 128 WHERE `entry`=179654; -- Invis Flee Point
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=180821; -- Sassafras
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180850; -- Glimmershell Crab
UPDATE `creature_template` SET `faction`=190, `speed_walk`=1.60000002384185791, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180854; -- Proto-Drake
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180853; -- Skeletal Lasher
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176519; -- Customer VO Controller
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=1000, `unit_flags`=0x40 WHERE `entry`=175806; -- So'azmi
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x41000000 WHERE `entry`=176896; -- Edge of Annihilation
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=180817; -- Pickle
UPDATE `creature_template` SET `faction`=190, `speed_walk`=2.40000009536743164, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180851; -- Dragonbone Condor
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=1500, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179886; -- Auction Bidder
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177994; -- Xy'har
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177756; -- Xy'aqida
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177998; -- Xy'nara
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177760; -- Xy'kitaab
UPDATE `creature_template` SET `faction`=16, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000 WHERE `entry`=175646; -- P.O.S.T. Master
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177995; -- Xy'zaro
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177753; -- Xy'mal
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x4000800, `unit_flags3`=0x40000000, `flags_extra` = 128 WHERE `entry`=178383; -- [DNT] Controller
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177755; -- Xy'jahid
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=179799; -- Portal Authority Tunnelmancer
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=180856; -- Deranged Helboar
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177752; -- Xy'ghana
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=177757; -- Xy'tadir
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=176555; -- Achillite
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=0x140, `unit_flags2`=0x4000800, `unit_flags3`=0x1 WHERE `entry`=176556; -- Alcruux
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176705; -- Venza Goldfuse
UPDATE `creature_template` SET `faction`=190, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180846; -- Sickly Gazelle
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=180823; -- Pancake
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=180859; -- Raging Colossus
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800 WHERE `entry`=180849; -- Dew Monster
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000800, `unit_flags3`=0x1000000 WHERE `entry`=179556; -- Broker Boat Medium 01
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=178962; -- Xy'aro
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=180818; -- Oswald
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1000000 WHERE `entry`=175796; -- Mailroom Portal
UPDATE `creature_template` SET `faction`=35, `npcflag`=67108864, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=176384; -- Katy Stampwhistle
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=179821; -- Commander Zo'far
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x4000800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=176560; -- [DNT] Encounter Controller
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=177329; -- Evaile
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=1500, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180444; -- Hired Runner
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x4000800, `unit_flags3`=0x41008000 WHERE `entry`=177438; -- Replace Horn
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000200, `unit_flags2`=0x4000800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=179797; -- [DNT] Spotlight Stalker
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=0.428571432828903198, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x820, `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry`=179773; -- Invis Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=176615; -- Waffles
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000001 WHERE `entry` IN (180158, 176561); -- Unruly Patron
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000001 WHERE `entry`=179551; -- Speakeasy Security
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=176616; -- Speakeasy Drinksmith
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=180614; -- Oasis Server
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000001 WHERE `entry`=180755; -- High Roller
UPDATE `creature_template` SET `faction`=2028, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x40000001 WHERE `entry`=180756; -- Shady Solicitor
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=180750; -- Au'manal
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=180613; -- Oasis Host
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=180751; -- Speakeasy Handler
UPDATE `creature_template` SET `faction`=190, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=179165; -- Silver Purrkin

-- Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId`=180858;
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(180858, 1, 0, 0, NULL);

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (179843,179844,179778,179954,180072,178074,179519));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(179843, 2, 0, 0, 748, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 179843 (Shocklight Barrier) - Sessile, Floating - CannotTurn
(179844, 2, 0, 0, 748, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 179844 (Shocklight Barrier) - Sessile, Floating - CannotTurn
(179778, 2, 0, 0, 748, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 179778 (Rift Blast Portal) - Sessile, Floating
(179954, 2, 0, 0, 748, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 179954 (Beam Splicer) - Sessile, Floating
(180072, 2, 0, 0, 748, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180072 (Tether Post) - Sessile, Floating
(178074, 2, 0, 0, 783, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 178074 (Al'dalil) - 
(179519, 2, 0, 0, 748, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967); -- 179519 (Al'dalil) - 

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (179844,179843));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(179844, 2, 8, 1, 1, 203380, 0x0, 0), -- Shocklight Barrier
(179843, 2, 8, 1, 1, 203379, 0x0, 0); -- Shocklight Barrier

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203314, `TypeFlags`=0x60000010, `TypeFlags2`=6 WHERE (`Entry`=179778 AND `DifficultyID`=2); -- Rift Blast Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203533 WHERE (`Entry`=179954 AND `DifficultyID`=2); -- Beam Splicer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203705, `TypeFlags`=0x1000400, `TypeFlags2`=16 WHERE (`Entry`=180072 AND `DifficultyID`=2); -- Tether Post
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201337 WHERE (`Entry`=178074 AND `DifficultyID`=2); -- Al'dalil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203042 WHERE (`Entry`=179519 AND `DifficultyID`=2); -- Al'dalil


UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=179773 AND `DifficultyID`=2); -- 179773 (Invis Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=176896 AND `DifficultyID`=2); -- 176896 (Edge of Annihilation) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180853 AND `DifficultyID`=2); -- 180853 (Skeletal Lasher) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180854 AND `DifficultyID`=2); -- 180854 (Proto-Drake) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179821 AND `DifficultyID`=2); -- 179821 (Commander Zo'far) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179842 AND `DifficultyID`=2); -- 179842 (Commerce Enforcer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=748, `StaticFlags1`=0x22000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179843 AND `DifficultyID`=2); -- 179843 (Shocklight Barrier) - Sessile, Floating - CannotTurn, passive
UPDATE `creature_template_difficulty` SET `ContentTuningID`=748, `StaticFlags1`=0x22000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179844 AND `DifficultyID`=2); -- 179844 (Shocklight Barrier) - Sessile, Floating - CannotTurn, passive
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179841 AND `DifficultyID`=2); -- 179841 (Veteran Sparkcaster) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179840 AND `DifficultyID`=2); -- 179840 (Market Peacekeeper) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180444 AND `DifficultyID`=2); -- 180444 (Hired Runner) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180817 AND `DifficultyID`=2); -- 180817 (Pickle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180821 AND `DifficultyID`=2); -- 180821 (Sassafras) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180851 AND `DifficultyID`=2); -- 180851 (Dragonbone Condor) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61967 WHERE (`Entry`=179556 AND `DifficultyID`=2); -- 179556 (Broker Boat Medium 01) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x40000, `VerifiedBuild`=61967 WHERE (`Entry`=175600 AND `DifficultyID`=2); -- 175600 (Drumset) - Sessile, Floating - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179785 AND `DifficultyID`=2); -- 179785 (Replace Saxophone) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176445 AND `DifficultyID`=2); -- 176445 (Au'myza) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177325 AND `DifficultyID`=2); -- 177325 (Hips) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=177440 AND `DifficultyID`=2); -- 177440 (Seat) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180850 AND `DifficultyID`=2); -- 180850 (Glimmershell Crab) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=176660 AND `DifficultyID`=2); -- 176660 (Replace Guitar) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179786 AND `DifficultyID`=2); -- 179786 (Replace Trumpet) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177327 AND `DifficultyID`=2); -- 177327 (Verethian) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177609 AND `DifficultyID`=2); -- 177609 (Dirtwhistle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179551 AND `DifficultyID`=2); -- 179551 (Speakeasy Security) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177329 AND `DifficultyID`=2); -- 177329 (Evaile) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177611 AND `DifficultyID`=2); -- 177611 (Vilt) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179797 AND `DifficultyID`=2); -- 179797 ([DNT] Spotlight Stalker) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=177438 AND `DifficultyID`=2); -- 177438 (Replace Horn) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=180616 AND `DifficultyID`=2); -- 180616 (Trade Prince Gallywix) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180618 AND `DifficultyID`=2); -- 180618 (Cartel Negotiator) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=180617 AND `DifficultyID`=2); -- 180617 (Hired Scoundrel) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=176217 AND `DifficultyID`=2); -- 176217 (So'azmi) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=180158 AND `DifficultyID`=2); -- 180158 (Unruly Patron) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=179654 AND `DifficultyID`=2); -- 179654 (Invis Flee Point) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=180756 AND `DifficultyID`=2); -- 180756 (Shady Solicitor) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180818 AND `DifficultyID`=2); -- 180818 (Oswald) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176384 AND `DifficultyID`=2); -- 176384 (Katy Stampwhistle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61967 WHERE (`Entry`=175796 AND `DifficultyID`=2); -- 175796 (Mailroom Portal) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180614 AND `DifficultyID`=2); -- 180614 (Oasis Server) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=178962 AND `DifficultyID`=2); -- 178962 (Xy'aro) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=175806 AND `DifficultyID`=2); -- 175806 (So'azmi) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180565 AND `DifficultyID`=2); -- 180565 (Bazaar Vagabond) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=176615 AND `DifficultyID`=2); -- 176615 (Waffles) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176616 AND `DifficultyID`=2); -- 176616 (Speakeasy Drinksmith) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180613 AND `DifficultyID`=2); -- 180613 (Oasis Host) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=175677 AND `DifficultyID`=2); -- 175677 (Smuggled Creature) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=176397 AND `DifficultyID`=2); -- 176397 (Holding Pen) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176395 AND `DifficultyID`=2); -- 176395 (Overloaded Mailemental) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176394 AND `DifficultyID`=2); -- 176394 (P.O.S.T. Worker) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176396 AND `DifficultyID`=2); -- 176396 (Defective Sorter) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=176561 AND `DifficultyID`=2); -- 176561 (Unruly Patron) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176398 AND `DifficultyID`=2); -- 176398 (Shipped Livestock) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=175736 AND `DifficultyID`=2); -- 175736 (Delivery Portal) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=176560 AND `DifficultyID`=2); -- 176560 ([DNT] Encounter Controller) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176564 AND `DifficultyID`=2); -- 176564 (Zo'gron) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179893 AND `DifficultyID`=2); -- 179893 (Cartel Skulker) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=180755 AND `DifficultyID`=2); -- 180755 (High Roller) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180562 AND `DifficultyID`=2); -- 180562 (Fruit Vendor) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61967 WHERE (`Entry`=180566 AND `DifficultyID`=2); -- 180566 (Rat of Unusual Size) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177999 AND `DifficultyID`=2); -- 177999 (Xy'darid) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180561 AND `DifficultyID`=2); -- 180561 (Oasis Guest) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177756 AND `DifficultyID`=2); -- 177756 (Xy'aqida) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177994 AND `DifficultyID`=2); -- 177994 (Xy'har) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176514 AND `DifficultyID`=2); -- 176514 (Angry Customer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180563 AND `DifficultyID`=2); -- 180563 (Backalley Schemer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177998 AND `DifficultyID`=2); -- 177998 (Xy'nara) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177760 AND `DifficultyID`=2); -- 177760 (Xy'kitaab) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=175646 AND `DifficultyID`=2); -- 175646 (P.O.S.T. Master) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=180858 AND `DifficultyID`=2); -- 180858 (Nether Beast) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177753 AND `DifficultyID`=2); -- 177753 (Xy'mal) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177995 AND `DifficultyID`=2); -- 177995 (Xy'zaro) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179886 AND `DifficultyID`=2); -- 179886 (Auction Bidder) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180859 AND `DifficultyID`=2); -- 180859 (Raging Colossus) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=178383 AND `DifficultyID`=2); -- 178383 ([DNT] Controller) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177755 AND `DifficultyID`=2); -- 177755 (Xy'jahid) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177757 AND `DifficultyID`=2); -- 177757 (Xy'tadir) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179799 AND `DifficultyID`=2); -- 179799 (Portal Authority Tunnelmancer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176555 AND `DifficultyID`=2); -- 176555 (Achillite) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179167 AND `DifficultyID`=2); -- 179167 (Damp Skrat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180095 AND `DifficultyID`=2); -- 180095 (Ankylodon Bull) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180567 AND `DifficultyID`=2); -- 180567 (Frenzied Nightclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177752 AND `DifficultyID`=2); -- 177752 (Xy'ghana) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180852 AND `DifficultyID`=2); -- 180852 (Infested Bear) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176705 AND `DifficultyID`=2); -- 176705 (Venza Goldfuse) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176556 AND `DifficultyID`=2); -- 176556 (Alcruux) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=47203 AND `DifficultyID`=2); -- 47203 (Creeper Egg) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177996 AND `DifficultyID`=2); -- 177996 (Bazaar Shopper) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180846 AND `DifficultyID`=2); -- 180846 (Sickly Gazelle) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180823 AND `DifficultyID`=2); -- 180823 (Pancake) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180848 AND `DifficultyID`=2); -- 180848 (Dew Monster) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61967 WHERE (`Entry`=180855 AND `DifficultyID`=2); -- 180855 (Devourer Mite) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=165855 AND `DifficultyID`=2); -- 165855 (Moonfrog) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180495 AND `DifficultyID`=2); -- 180495 (Enraged Direhorn) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=175616 AND `DifficultyID`=2); -- 175616 (Zo'phex) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=176540 AND `DifficultyID`=2); -- 176540 (Body Armor Left) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=176534 AND `DifficultyID`=2); -- 176534 (Arm Right) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=61967 WHERE (`Entry`=176438 AND `DifficultyID`=2); -- 176438 (Arm Left) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=179122 AND `DifficultyID`=2); -- 179122 (Body Armor Right) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=179955 AND `DifficultyID`=2); -- 179955 (Sorting Device Visual Stalkers) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179366 AND `DifficultyID`=2); -- 179366 (Damp Skrat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=61967 WHERE (`Entry`=180092 AND `DifficultyID`=2); -- 180092 (Giant Hive Guardian) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180348 AND `DifficultyID`=2); -- 180348 (Cartel Muscle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180390 AND `DifficultyID`=2); -- 180390 (Dantun) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180335 AND `DifficultyID`=2); -- 180335 (Cartel Smuggler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180822 AND `DifficultyID`=2); -- 180822 (Goblin) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180336 AND `DifficultyID`=2); -- 180336 (Cartel Wiseguy) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180310 AND `DifficultyID`=2); -- 180310 (Shop Patron) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180091 AND `DifficultyID`=2); -- 180091 (Ancient Core Hound) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179837 AND `DifficultyID`=2); -- 179837 (Tracker Zo'korss) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180269 AND `DifficultyID`=2); -- 180269 (Curiosity) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176759 AND `DifficultyID`=2); -- 176759 (Xy'nam) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177868 AND `DifficultyID`=2); -- 177868 (Creature Collector) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180114 AND `DifficultyID`=2); -- 180114 (Fruit Vendor) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180824 AND `DifficultyID`=2); -- 180824 (Waffle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179795 AND `DifficultyID`=2); -- 179795 (Ta'speri) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180117 AND `DifficultyID`=2); -- 180117 (Meat Vendor) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179796 AND `DifficultyID`=2); -- 179796 (Ta'leesa) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=178392 AND `DifficultyID`=2); -- 178392 (Gatewarden Zo'mazz) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180161 AND `DifficultyID`=2); -- 180161 (Shopkeeper) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177259 AND `DifficultyID`=2); -- 177259 (Zo'pare) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61967 WHERE (`Entry`=180153 AND `DifficultyID`=2); -- 180153 (Aqir Impaler) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=176758 AND `DifficultyID`=2); -- 176758 (Xy'noc) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179334 AND `DifficultyID`=2); -- 179334 (Portalmancer Zo'honn) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179164 AND `DifficultyID`=2); -- 179164 (Curious Purrkin) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180249 AND `DifficultyID`=2); -- 180249 (Market Server) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=179121 AND `DifficultyID`=2); -- 179121 (Zo'phex Cosmetic Summon Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177808 AND `DifficultyID`=2); -- 177808 (Armored Overseer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177817 AND `DifficultyID`=2); -- 177817 (Support Officer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179367 AND `DifficultyID`=2); -- 179367 (Scavenging Skrat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180248 AND `DifficultyID`=2); -- 180248 (Hungry Patron) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177816 AND `DifficultyID`=2); -- 177816 (Interrogation Specialist) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180130 AND `DifficultyID`=2); -- 180130 (Antique Vendor) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=179168 AND `DifficultyID`=2); -- 179168 (Scavenging Skrat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=180129 AND `DifficultyID`=2); -- 180129 (Toy Vendor) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=178545 AND `DifficultyID`=2); -- 178545 (Watch-Agent Summon Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177807 AND `DifficultyID`=2); -- 177807 (Customs Security) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177239 AND `DifficultyID`=2); -- 177239 (Collector of Worth) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61967 WHERE (`Entry`=177672 AND `DifficultyID`=2); -- 177672 (Terminal Attendant) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=61967 WHERE (`Entry`=97809 AND `DifficultyID`=2); -- 97809 (Coastal Seagull) - CanSwim, Floating

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (178962,180818,175796,176384,179821,179556,180859,180849,180846,180823,176705,176556,176555,180856,179799,177994,177756,177998,177760,180563,175646,177995,177753,178383,177755,177752,177757,179886,180851,180817,176896,175806,176519,180853,180854,180850,180821,179654,176396,176397,176398,175736,176394,176395,176217,175677, 180852,47203, 180848,180858, 179841,179840,179909,179908,179842,180561, 180562, 176564, 177999, 176514, 180566, 180855,177996,179843,179844,165855,180095,179167,180328,180348,180314,180315,180310,180320,180443,180442,180390,180335,180150,180072,180336,180149,179947,180091,179948,180822,180147,179837,180327,180148,180260,180241,180266,180295,180247,180268,179795,179796,180248,180243,180249,180244,180269,180754,180215,180267,180228,180161,179168,180261,179367,177259,179121,177808,179334,177255,178545,177239,180824,177817,177816,177672,180156,180114,180117,177868,176759,176758,179981,180130,180056,178392,178074,179519,177807,179011,179983,179366,180322,180129,180510,180153,97809,180152,180495,180092,180567,179982,176560,177329,180444,177438,179797,179773,176615,180158,179551,176616,180614,180755,176561,180756,180750,180613,180751,180565,180317,179165));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(178962, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 178962 (Xy'aro) - CanSwim
(180818, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180818 (Oswald) - CanSwim
(175796, 23, 0, 0, 2042, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 175796 (Mailroom Portal) - Floating
(176384, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176384 (Katy Stampwhistle) - CanSwim
(179821, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179821 (Commander Zo'far) - CanSwim
(179556, 23, 0, 0, 837, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179556 (Broker Boat Medium 01) - Floating
(180859, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180859 (Raging Colossus) - Sessile, Floating
(180849, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180849 (Dew Monster) - 
(180846, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180846 (Sickly Gazelle) - Sessile, Floating
(180823, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180823 (Pancake) - CanSwim
(176705, 23, 2, 2, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176705 (Venza Goldfuse) - CanSwim
(176556, 23, 2, 2, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176556 (Alcruux) - CanSwim
(176555, 23, 2, 2, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176555 (Achillite) - CanSwim
(180856, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180856 (Deranged Helboar) - 
(179799, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179799 (Portal Authority Tunnelmancer) - CanSwim
(177994, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177994 (Xy'har) - CanSwim
(177756, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177756 (Xy'aqida) - CanSwim
(177998, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177998 (Xy'nara) - CanSwim
(177760, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177760 (Xy'kitaab) - CanSwim
(180563, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180563 (Backalley Schemer) - CanSwim
(175646, 23, 2, 2, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 175646 (P.O.S.T. Master) - CanSwim
(177995, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177995 (Xy'zaro) - CanSwim
(177753, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177753 (Xy'mal) - CanSwim
(178383, 23, 0, 0, 749, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 178383 ([DNT] Controller) - Sessile, Floating - CannotTurn
(177755, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177755 (Xy'jahid) - CanSwim
(177752, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177752 (Xy'ghana) - CanSwim
(177757, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177757 (Xy'tadir) - CanSwim
(179886, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179886 (Auction Bidder) - CanSwim
(180851, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180851 (Dragonbone Condor) - Sessile, Floating
(180817, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180817 (Pickle) - CanSwim
(176896, 23, 0, 0, 2042, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176896 (Edge of Annihilation) - Sessile, Floating - CannotTurn
(175806, 23, 2, 2, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 175806 (So'azmi) - CanSwim
(176519, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176519 (Customer VO Controller) - 
(180853, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180853 (Skeletal Lasher) - Sessile, Floating
(180854, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180854 (Proto-Drake) - Sessile, Floating
(180850, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180850 (Glimmershell Crab) - Sessile, Floating
(180821, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180821 (Sassafras) - CanSwim
(179654, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179654 (Invis Flee Point) - Sessile, Floating
(176396, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176396 (Defective Sorter) - CanSwim
(176397, 23, 0, 0, 2042, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176397 (Holding Pen) - Sessile, Floating - CannotTurn
(176398, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176398 (Shipped Livestock) - CanSwim
(175736, 23, 0, 0, 2042, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 175736 (Delivery Portal) - Sessile, Floating - CannotTurn
(176394, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176394 (P.O.S.T. Worker) - CanSwim
(176395, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176395 (Overloaded Mailemental) - CanSwim
(176217, 23, 2, 2, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176217 (So'azmi) - Sessile, Floating
(175677, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 175677 (Smuggled Creature) - CanSwim
(180852, 23, 0, 0, 2042, 0x00000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180852 (Infested Bear) - Sessile, Floating
(47203, 23, 0, 0, 11, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 47203 (Creeper Egg) - Sessile, Floating
(180848, 23, 0, 0, 2042, 0x00000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180848 (Dew Monster) - Sessile, Floating
(180858, 23, 0, 0, 2042, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180858 (Nether Beast) - Sessile, CanSwim, Floating
(179841, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179841 (Veteran Sparkcaster) - CanSwim
(179840, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179840 (Market Peacekeeper) - CanSwim
(179909, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179909 (Curious Onlooker) - 
(179908, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179908 (Distressed Merchant) - 
(179842, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179842 (Commerce Enforcer) - CanSwim
(180561, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180561 (Oasis Guest) - CanSwim
(180562, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180562 (Fruit Vendor) - CanSwim
(176564, 23, 2, 2, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176564 (Zo'gron) - CanSwim
(177999, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177999 (Xy'darid) - CanSwim
(176514, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176514 (Angry Customer) - CanSwim
(180566, 23, 0, 0, 2042, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180566 (Rat of Unusual Size) - Floating
(180855, 23, 0, 0, 2042, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180855 (Devourer Mite) - Floating
(177996, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177996 (Bazaar Shopper) - CanSwim
(179843, 23, 0, 0, 2042, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179843 (Shocklight Barrier) - Sessile, Floating - CannotTurn
(179844, 23, 0, 0, 2042, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179844 (Shocklight Barrier) - Sessile, Floating - CannotTurn
(165855, 23, 0, 0, 81, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 165855 (Moonfrog) - CanSwim
(180095, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180095 (Ankylodon Bull) - CanSwim
(179167, 23, 0, 0, 371, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179167 (Damp Skrat) - CanSwim
(180328, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180328 (Au'ri) - 
(180348, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180348 (Cartel Muscle) - CanSwim
(180314, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180314 (Patio Waiter) - 
(180315, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180315 (Shady Dealer) - 
(180310, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180310 (Shop Patron) - CanSwim
(180320, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180320 (Illicit Purveyor) - 
(180443, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180443 (Exotic Reseller) - 
(180442, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180442 (Novice Acquirer) - 
(180390, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180390 (Dantun) - CanSwim
(180335, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180335 (Cartel Smuggler) - CanSwim
(180150, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180150 (Relaxed Patron) - 
(180072, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180072 (Tether Post) - Sessile, Floating
(180336, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180336 (Cartel Wiseguy) - CanSwim
(180149, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180149 (Relaxed Patron) - 
(179947, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179947 (Impressed Patron) - 
(180091, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180091 (Ancient Core Hound) - CanSwim
(179948, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179948 (Impressed Patron) - 
(180822, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180822 (Goblin) - CanSwim
(180147, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180147 (Well-informed Trader) - 
(179837, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179837 (Tracker Zo'korss) - CanSwim
(180327, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180327 (Au'mba) - 
(180148, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180148 (Coin Changer) - 
(180260, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180260 (Spice Trader Au'saar) - 
(180241, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180241 (Export Hauler) - 
(180266, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180266 (Ta'ules) - 
(180295, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180295 (Xy'rihn the Keen) - 
(180247, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180247 (Hungry Hauler) - 
(180268, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180268 (Ta'sam) - 
(179795, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179795 (Ta'speri) - CanSwim
(179796, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179796 (Ta'leesa) - CanSwim
(180248, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180248 (Hungry Patron) - Sessile, Floating
(180243, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180243 (Market Chef) - 
(180249, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180249 (Market Server) - 
(180244, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180244 (Culinary Assistant) - 
(180269, 23, 0, 0, 81, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180269 (Curiosity) - CanSwim
(180754, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180754 (Questionable Trader) - 
(180215, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180215 (Export Hauler) - 
(180267, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180267 (Ta'rex) - 
(180228, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180228 (Export Supervisor) - 
(180161, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180161 (Shopkeeper) - CanSwim
(179168, 23, 0, 0, 371, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179168 (Scavenging Skrat) - CanSwim
(180261, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180261 (Market Patron) - 
(179367, 23, 0, 0, 81, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179367 (Scavenging Skrat) - CanSwim
(177259, 23, 0, 0, 783, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177259 (Zo'pare) - CanSwim
(179121, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179121 (Zo'phex Cosmetic Summon Stalker) - Sessile, Floating
(177808, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177808 (Armored Overseer) - CanSwim
(179334, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179334 (Portalmancer Zo'honn) - CanSwim
(177255, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177255 (Contraband Auctioneer) - 
(178545, 23, 0, 0, 2042, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 178545 (Watch-Agent Summon Stalker) - Sessile, Floating
(177239, 23, 0, 0, 783, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177239 (Collector of Worth) - CanSwim
(180824, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180824 (Waffle) - CanSwim
(177817, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177817 (Support Officer) - CanSwim
(177816, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177816 (Interrogation Specialist) - CanSwim
(177672, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177672 (Terminal Attendant) - CanSwim
(180156, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180156 (Enthusiastic Trader) - 
(180114, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180114 (Fruit Vendor) - CanSwim
(180117, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180117 (Meat Vendor) - CanSwim
(177868, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177868 (Creature Collector) - CanSwim
(176759, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176759 (Xy'nam) - CanSwim
(176758, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 176758 (Xy'noc) - CanSwim
(179981, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179981 (Chef) - 
(180130, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180130 (Antique Vendor) - CanSwim
(180056, 23, 0, 0, 1240, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180056 (Empty Hyperspatial Container) - 
(178392, 23, 1, 1, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 178392 (Gatewarden Zo'mazz) - CanSwim
(178074, 23, 0, 0, 783, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 178074 (Al'dalil) - 
(179519, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179519 (Al'dalil) - 
(177807, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 177807 (Customs Security) - CanSwim
(179011, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179011 (Shipping Facilitator) - 
(179983, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179983 (Dozing Laborer) - 
(179366, 23, 0, 0, 81, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179366 (Damp Skrat) - CanSwim
(180322, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180322 (Fe'tajid) - 
(180129, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180129 (Toy Vendor) - CanSwim
(180510, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180510 (Toxic Saurid) - 
(180153, 23, 0, 0, 2042, 0x20000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180153 (Aqir Impaler) - Floating
(97809, 23, 0, 0, 334, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 97809 (Coastal Seagull) - CanSwim, Floating
(180152, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180152 (Shipping Facilitator) - 
(180495, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180495 (Enraged Direhorn) - CanSwim
(180092, 23, 0, 0, 2042, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180092 (Giant Hive Guardian) - CanSwim, Floating
(180567, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 180567 (Frenzied Nightclaw) - CanSwim
(179982, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61609), -- 179982 (Hungry Laborer) - 
(176560, 23, 0, 0, 749, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 176560 ([DNT] Encounter Controller) - Sessile, Floating - CannotTurn
(177329, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 177329 (Evaile) - CanSwim
(180444, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180444 (Hired Runner) - CanSwim
(177438, 23, 0, 0, 749, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 177438 (Replace Horn) - Sessile, Floating - CannotTurn
(179797, 23, 0, 0, 749, 0x20000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 179797 ([DNT] Spotlight Stalker) - Sessile, Floating - CannotTurn
(179773, 23, 0, 0, 1240, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 179773 (Invis Stalker) - Sessile, Floating
(176615, 23, 0, 0, 2042, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 176615 (Waffles) - Sessile, CanSwim, Floating
(180158, 23, 0, 0, 2042, 0x30000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180158 (Unruly Patron) - Sessile, CanSwim, Floating - CannotTurn
(179551, 23, 0, 0, 2042, 0x30000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 179551 (Speakeasy Security) - Sessile, CanSwim, Floating - CannotTurn
(176616, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 176616 (Speakeasy Drinksmith) - CanSwim
(180614, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180614 (Oasis Server) - CanSwim
(180755, 23, 0, 0, 2042, 0x30000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180755 (High Roller) - Sessile, CanSwim, Floating - CannotTurn
(176561, 23, 0, 0, 2042, 0x30000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 176561 (Unruly Patron) - Sessile, CanSwim, Floating - CannotTurn
(180756, 23, 0, 0, 2042, 0x30000100, 0x0, 0x2000000, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180756 (Shady Solicitor) - Sessile, CanSwim, Floating - CannotTurn
(180750, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180750 (Au'manal) - 
(180613, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180613 (Oasis Host) - CanSwim
(180751, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180751 (Speakeasy Handler) - 
(180565, 23, 0, 0, 2042, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180565 (Bazaar Vagabond) - CanSwim
(180317, 23, 0, 0, 2042, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967), -- 180317 (Illicit Hauler) - 
(179165, 23, 0, 0, 371, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61967); -- 179165 (Silver Purrkin) - CanSwim

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (179844,179843));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(179844, 23, 8, 1, 1, 203380, 0x0, 0), -- Shocklight Barrier
(179843, 23, 8, 1, 1, 203379, 0x0, 0); -- Shocklight Barrier

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=7.5, `CreatureDifficultyID`=203998, `TypeFlags`=0x200048 WHERE (`Entry`=180348 AND `DifficultyID`=23); -- Cartel Muscle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203978 WHERE (`Entry`=180328 AND `DifficultyID`=23); -- Au'ri
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=202683 WHERE (`Entry`=179167 AND `DifficultyID`=23); -- Damp Skrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203964 WHERE (`Entry`=180314 AND `DifficultyID`=23); -- Patio Waiter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203965 WHERE (`Entry`=180315 AND `DifficultyID`=23); -- Shady Dealer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203970 WHERE (`Entry`=180320 AND `DifficultyID`=23); -- Illicit Purveyor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203960, `TypeFlags`=0x200068 WHERE (`Entry`=180310 AND `DifficultyID`=23); -- Shop Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=204095 WHERE (`Entry`=180443 AND `DifficultyID`=23); -- Exotic Reseller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=204094 WHERE (`Entry`=180442 AND `DifficultyID`=23); -- Novice Acquirer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=204040, `TypeFlags`=0x200068 WHERE (`Entry`=180390 AND `DifficultyID`=23); -- Dantun
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4, `CreatureDifficultyID`=203986, `TypeFlags`=0x200048 WHERE (`Entry`=180336 AND `DifficultyID`=23); -- Cartel Wiseguy
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4.5, `CreatureDifficultyID`=203985, `TypeFlags`=0x200048 WHERE (`Entry`=180335 AND `DifficultyID`=23); -- Cartel Smuggler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203792 WHERE (`Entry`=180150 AND `DifficultyID`=23); -- Relaxed Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203791 WHERE (`Entry`=180149 AND `DifficultyID`=23); -- Relaxed Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=7.199999809265136718, `CreatureDifficultyID`=203728, `TypeFlags`=0x200048 WHERE (`Entry`=180091 AND `DifficultyID`=23); -- Ancient Core Hound
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203705, `TypeFlags`=0x1000400, `TypeFlags2`=16 WHERE (`Entry`=180072 AND `DifficultyID`=23); -- Tether Post
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203527 WHERE (`Entry`=179948 AND `DifficultyID`=23); -- Impressed Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203526 WHERE (`Entry`=179947 AND `DifficultyID`=23); -- Impressed Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=204488, `TypeFlags2`=2 WHERE (`Entry`=180822 AND `DifficultyID`=23); -- Goblin
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203789 WHERE (`Entry`=180147 AND `DifficultyID`=23); -- Well-informed Trader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=10, `CreatureDifficultyID`=203373, `TypeFlags`=0x200048 WHERE (`Entry`=179837 AND `DifficultyID`=23); -- Tracker Zo'korss
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203977 WHERE (`Entry`=180327 AND `DifficultyID`=23); -- Au'mba
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203910 WHERE (`Entry`=180260 AND `DifficultyID`=23); -- Spice Trader Au'saar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203790 WHERE (`Entry`=180148 AND `DifficultyID`=23); -- Coin Changer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203916 WHERE (`Entry`=180266 AND `DifficultyID`=23); -- Ta'ules
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203891 WHERE (`Entry`=180241 AND `DifficultyID`=23); -- Export Hauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203945 WHERE (`Entry`=180295 AND `DifficultyID`=23); -- Xy'rihn the Keen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203897 WHERE (`Entry`=180247 AND `DifficultyID`=23); -- Hungry Hauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203918 WHERE (`Entry`=180268 AND `DifficultyID`=23); -- Ta'sam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203899 WHERE (`Entry`=180249 AND `DifficultyID`=23); -- Market Server
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203898 WHERE (`Entry`=180248 AND `DifficultyID`=23); -- Hungry Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203893 WHERE (`Entry`=180243 AND `DifficultyID`=23); -- Market Chef
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203332 WHERE (`Entry`=179796 AND `DifficultyID`=23); -- Ta'leesa
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203331 WHERE (`Entry`=179795 AND `DifficultyID`=23); -- Ta'speri
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=203919 WHERE (`Entry`=180269 AND `DifficultyID`=23); -- Curiosity
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203894 WHERE (`Entry`=180244 AND `DifficultyID`=23); -- Culinary Assistant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=204420 WHERE (`Entry`=180754 AND `DifficultyID`=23); -- Questionable Trader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203917 WHERE (`Entry`=180267 AND `DifficultyID`=23); -- Ta'rex
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203865 WHERE (`Entry`=180215 AND `DifficultyID`=23); -- Export Hauler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=202684 WHERE (`Entry`=179168 AND `DifficultyID`=23); -- Scavenging Skrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203878 WHERE (`Entry`=180228 AND `DifficultyID`=23); -- Export Supervisor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=8, `CreatureDifficultyID`=203803, `TypeFlags`=0x200068 WHERE (`Entry`=180161 AND `DifficultyID`=23); -- Shopkeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203911 WHERE (`Entry`=180261 AND `DifficultyID`=23); -- Market Patron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=202890 WHERE (`Entry`=179367 AND `DifficultyID`=23); -- Scavenging Skrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=200314 WHERE (`Entry`=177259 AND `DifficultyID`=23); -- Zo'pare
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=204490, `TypeFlags2`=2 WHERE (`Entry`=180824 AND `DifficultyID`=23); -- Waffle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=10, `CreatureDifficultyID`=202857, `TypeFlags`=0x200068 WHERE (`Entry`=179334 AND `DifficultyID`=23); -- Portalmancer Zo'honn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=202637 WHERE (`Entry`=179121 AND `DifficultyID`=23); -- Zo'phex Cosmetic Summon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=202048 WHERE (`Entry`=178545 AND `DifficultyID`=23); -- Watch-Agent Summon Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4.5, `CreatureDifficultyID`=201076, `TypeFlags`=0x200048 WHERE (`Entry`=177817 AND `DifficultyID`=23); -- Support Officer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4.5, `CreatureDifficultyID`=201075, `TypeFlags`=0x200068 WHERE (`Entry`=177816 AND `DifficultyID`=23); -- Interrogation Specialist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=6.5, `CreatureDifficultyID`=201067, `TypeFlags`=0x200068 WHERE (`Entry`=177808 AND `DifficultyID`=23); -- Armored Overseer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=200928, `TypeFlags`=0x200068 WHERE (`Entry`=177672 AND `DifficultyID`=23); -- Terminal Attendant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=200310 WHERE (`Entry`=177255 AND `DifficultyID`=23); -- Contraband Auctioneer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=200294 WHERE (`Entry`=177239 AND `DifficultyID`=23); -- Collector of Worth
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203798 WHERE (`Entry`=180156 AND `DifficultyID`=23); -- Enthusiastic Trader
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203772 WHERE (`Entry`=180130 AND `DifficultyID`=23); -- Antique Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203758 WHERE (`Entry`=180117 AND `DifficultyID`=23); -- Meat Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203755 WHERE (`Entry`=180114 AND `DifficultyID`=23); -- Fruit Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203685, `TypeFlags`=0x1000400, `TypeFlags2`=16 WHERE (`Entry`=180056 AND `DifficultyID`=23); -- Empty Hyperspatial Container
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203569 WHERE (`Entry`=179981 AND `DifficultyID`=23); -- Chef
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5, `CreatureDifficultyID`=201131, `TypeFlags`=0x200068 WHERE (`Entry`=177868 AND `DifficultyID`=23); -- Creature Collector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=15, `CreatureDifficultyID`=199712, `TypeFlags`=0x200048 WHERE (`Entry`=176759 AND `DifficultyID`=23); -- Xy'nam
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=15, `CreatureDifficultyID`=199711, `TypeFlags`=0x200048 WHERE (`Entry`=176758 AND `DifficultyID`=23); -- Xy'noc
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201337 WHERE (`Entry`=178074 AND `DifficultyID`=23); -- Al'dalil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=8, `CreatureDifficultyID`=201755, `TypeFlags`=0x200068 WHERE (`Entry`=178392 AND `DifficultyID`=23); -- Gatewarden Zo'mazz
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203042 WHERE (`Entry`=179519 AND `DifficultyID`=23); -- Al'dalil
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5.5, `CreatureDifficultyID`=201066, `TypeFlags`=0x200068 WHERE (`Entry`=177807 AND `DifficultyID`=23); -- Customs Security
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=204170 WHERE (`Entry`=180510 AND `DifficultyID`=23); -- Toxic Saurid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203972 WHERE (`Entry`=180322 AND `DifficultyID`=23); -- Fe'tajid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203795, `TypeFlags`=0x1 WHERE (`Entry`=180153 AND `DifficultyID`=23); -- Aqir Impaler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203794 WHERE (`Entry`=180152 AND `DifficultyID`=23); -- Shipping Facilitator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203771 WHERE (`Entry`=180129 AND `DifficultyID`=23); -- Toy Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203571 WHERE (`Entry`=179983 AND `DifficultyID`=23); -- Dozing Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=203570 WHERE (`Entry`=179982 AND `DifficultyID`=23); -- Hungry Laborer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=202889 WHERE (`Entry`=179366 AND `DifficultyID`=23); -- Damp Skrat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=202527 WHERE (`Entry`=179011 AND `DifficultyID`=23); -- Shipping Facilitator
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=98310, `TypeFlags`=0x1 WHERE (`Entry`=97809 AND `DifficultyID`=23); -- Coastal Seagull
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=179469 AND `DifficultyID`=0); -- 179469 (Market Specialist) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=178796 AND `DifficultyID`=0); -- 178796 (Ta'resarra) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=179470 AND `DifficultyID`=0); -- 179470 (Dock Enforcer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=61609 WHERE (`Entry`=179515 AND `DifficultyID`=0); -- 179515 (Shipping Facilitator) - CanSwim
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=204224 WHERE (`Entry`=180562 AND `DifficultyID`=23); -- Fruit Vendor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=45, `CreatureDifficultyID`=199490, `TypeFlags`=0x200068, `TypeFlags2`=64 WHERE (`Entry`=176564 AND `DifficultyID`=23); -- Zo'gron
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5, `CreatureDifficultyID`=204223 WHERE (`Entry`=180561 AND `DifficultyID`=23); -- Oasis Guest
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201262 WHERE (`Entry`=177999 AND `DifficultyID`=23); -- Xy'darid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=7.599999904632568359, `CreatureDifficultyID`=203378, `TypeFlags`=0x200048 WHERE (`Entry`=179842 AND `DifficultyID`=23); -- Commerce Enforcer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=204228, `TypeFlags`=0x1 WHERE (`Entry`=180566 AND `DifficultyID`=23); -- Rat of Unusual Size
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203445 WHERE (`Entry`=179909 AND `DifficultyID`=23); -- Curious Onlooker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203444 WHERE (`Entry`=179908 AND `DifficultyID`=23); -- Distressed Merchant
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203380 WHERE (`Entry`=179844 AND `DifficultyID`=23); -- Shocklight Barrier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203379 WHERE (`Entry`=179843 AND `DifficultyID`=23); -- Shocklight Barrier
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4.5, `CreatureDifficultyID`=203377, `TypeFlags`=0x200048 WHERE (`Entry`=179841 AND `DifficultyID`=23); -- Veteran Sparkcaster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=6, `CreatureDifficultyID`=203376, `TypeFlags`=0x200048 WHERE (`Entry`=179840 AND `DifficultyID`=23); -- Market Peacekeeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.150000005960464477, `CreatureDifficultyID`=204528 WHERE (`Entry`=180858 AND `DifficultyID`=23); -- Nether Beast
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=199163, `TypeFlags`=0x200048 WHERE (`Entry`=176514 AND `DifficultyID`=23); -- Angry Customer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4, `CreatureDifficultyID`=204229, `TypeFlags`=0x200048 WHERE (`Entry`=180567 AND `DifficultyID`=23); -- Frenzied Nightclaw
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=6, `CreatureDifficultyID`=203736, `TypeFlags`=0x200048 WHERE (`Entry`=180095 AND `DifficultyID`=23); -- Ankylodon Bull
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=204525 WHERE (`Entry`=180855 AND `DifficultyID`=23); -- Devourer Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2.5, `CreatureDifficultyID`=204518 WHERE (`Entry`=180848 AND `DifficultyID`=23); -- Dew Monster
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5, `CreatureDifficultyID`=201259 WHERE (`Entry`=177996 AND `DifficultyID`=23); -- Bazaar Shopper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.189934000372886657, `CreatureDifficultyID`=186501 WHERE (`Entry`=165855 AND `DifficultyID`=23); -- Moonfrog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=8, `CreatureDifficultyID`=204155, `TypeFlags`=0x200048 WHERE (`Entry`=180495 AND `DifficultyID`=23); -- Enraged Direhorn
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4, `CreatureDifficultyID`=203729, `TypeFlags`=0x200048 WHERE (`Entry`=180092 AND `DifficultyID`=23); -- Giant Hive Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=4, `CreatureDifficultyID`=198315, `TypeFlags`=0x200048 WHERE (`Entry`=175677 AND `DifficultyID`=23); -- Smuggled Creature
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=3.75, `CreatureDifficultyID`=199044, `TypeFlags`=0x48 WHERE (`Entry`=176395 AND `DifficultyID`=23); -- Overloaded Mailemental
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5, `CreatureDifficultyID`=199043, `TypeFlags`=0x200048 WHERE (`Entry`=176394 AND `DifficultyID`=23); -- P.O.S.T. Worker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=198866, `TypeFlags2`=128 WHERE (`Entry`=176217 AND `DifficultyID`=23); -- So'azmi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=199046, `TypeFlags`=0x60000010, `TypeFlags2`=117440518 WHERE (`Entry`=176397 AND `DifficultyID`=23); -- Holding Pen
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=199047, `TypeFlags`=0x200048 WHERE (`Entry`=176398 AND `DifficultyID`=23); -- Shipped Livestock
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=2, `CreatureDifficultyID`=199045, `TypeFlags`=0x200048 WHERE (`Entry`=176396 AND `DifficultyID`=23); -- Defective Sorter
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=198374 WHERE (`Entry`=175736 AND `DifficultyID`=23); -- Delivery Portal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5, `CreatureDifficultyID`=204524 WHERE (`Entry`=180854 AND `DifficultyID`=23); -- Proto-Drake
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=1.399999976158142089, `CreatureDifficultyID`=204523 WHERE (`Entry`=180853 AND `DifficultyID`=23); -- Skeletal Lasher
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.800000011920928955, `CreatureDifficultyID`=204520 WHERE (`Entry`=180850 AND `DifficultyID`=23); -- Glimmershell Crab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=204487, `TypeFlags2`=2 WHERE (`Entry`=180821 AND `DifficultyID`=23); -- Sassafras
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203186 WHERE (`Entry`=179654 AND `DifficultyID`=23); -- Invis Flee Point
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=199168 WHERE (`Entry`=176519 AND `DifficultyID`=23); -- Customer VO Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.678399980068206787, `CreatureDifficultyID`=199849 WHERE (`Entry`=176896 AND `DifficultyID`=23); -- Edge of Annihilation
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=31.5, `CreatureDifficultyID`=198444, `TypeFlags`=0x200048, `TypeFlags2`=128 WHERE (`Entry`=175806 AND `DifficultyID`=23); -- So'azmi
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=204521 WHERE (`Entry`=180851 AND `DifficultyID`=23); -- Dragonbone Condor
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=204483, `TypeFlags2`=2 WHERE (`Entry`=180817 AND `DifficultyID`=23); -- Pickle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5, `CreatureDifficultyID`=203422, `TypeFlags`=0x200068 WHERE (`Entry`=179886 AND `DifficultyID`=23); -- Auction Bidder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201257 WHERE (`Entry`=177994 AND `DifficultyID`=23); -- Xy'har
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201015 WHERE (`Entry`=177756 AND `DifficultyID`=23); -- Xy'aqida
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201261 WHERE (`Entry`=177998 AND `DifficultyID`=23); -- Xy'nara
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201019 WHERE (`Entry`=177760 AND `DifficultyID`=23); -- Xy'kitaab
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=5, `CreatureDifficultyID`=204225 WHERE (`Entry`=180563 AND `DifficultyID`=23); -- Backalley Schemer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=31.5, `CreatureDifficultyID`=198284, `TypeFlags`=0x200048, `TypeFlags2`=128 WHERE (`Entry`=175646 AND `DifficultyID`=23); -- P.O.S.T. Master
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201258 WHERE (`Entry`=177995 AND `DifficultyID`=23); -- Xy'zaro
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201012 WHERE (`Entry`=177753 AND `DifficultyID`=23); -- Xy'mal
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201746 WHERE (`Entry`=178383 AND `DifficultyID`=23); -- [DNT] Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201014 WHERE (`Entry`=177755 AND `DifficultyID`=23); -- Xy'jahid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201016 WHERE (`Entry`=177757 AND `DifficultyID`=23); -- Xy'tadir
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=203335, `TypeFlags2`=64 WHERE (`Entry`=179799 AND `DifficultyID`=23); -- Portal Authority Tunnelmancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=15, `CreatureDifficultyID`=199481, `TypeFlags`=0x200048, `TypeFlags2`=128 WHERE (`Entry`=176555 AND `DifficultyID`=23); -- Achillite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=201011 WHERE (`Entry`=177752 AND `DifficultyID`=23); -- Xy'ghana
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `CreatureDifficultyID`=204526 WHERE (`Entry`=180856 AND `DifficultyID`=23); -- Deranged Helboar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=1.35000002384185791, `CreatureDifficultyID`=204522 WHERE (`Entry`=180852 AND `DifficultyID`=23); -- Infested Bear
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=204516 WHERE (`Entry`=180846 AND `DifficultyID`=23); -- Sickly Gazelle
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=18, `CreatureDifficultyID`=199658, `TypeFlags`=0x200048, `TypeFlags2`=128 WHERE (`Entry`=176705 AND `DifficultyID`=23); -- Venza Goldfuse
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=12, `CreatureDifficultyID`=199482, `TypeFlags`=0x200048, `TypeFlags2`=128 WHERE (`Entry`=176556 AND `DifficultyID`=23); -- Alcruux
UPDATE `creature_template_difficulty` SET `HealthModifier`=0.023809999227523803, `CreatureDifficultyID`=43895, `TypeFlags`=0x40000040 WHERE (`Entry`=47203 AND `DifficultyID`=23); -- Creeper Egg
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=204489, `TypeFlags2`=2 WHERE (`Entry`=180823 AND `DifficultyID`=23); -- Pancake
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000000, `VerifiedBuild`=61967 WHERE (`Entry`=180215 AND `DifficultyID`=23); -- 180215 (Export Hauler)
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180852 AND `DifficultyID`=23); -- 180852 (Infested Bear) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180848 AND `DifficultyID`=23); -- 180848 (Dew Monster) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180855 AND `DifficultyID`=23); -- 180855 (Devourer Mite) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=61967 WHERE (`Entry`=180315 AND `DifficultyID`=23); -- 180315 (Shady Dealer) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2042, `StaticFlags1`=0x22000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179843 AND `DifficultyID`=23); -- 179843 (Shocklight Barrier) - Sessile, Floating - CannotTurn, passive
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2042, `StaticFlags1`=0x22000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61967 WHERE (`Entry`=179844 AND `DifficultyID`=23); -- 179844 (Shocklight Barrier) - Sessile, Floating - CannotTurn, passive

DELETE FROM `creature_static_flags_override` WHERE `SpawnId`IN (@CGUID+213, @CGUID+277, @CGUID+339);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(@CGUID+339, 23, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+339, 2, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+339, 8, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+213, 23, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+213, 2, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+213, 8, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+277, 23, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+277, 2, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+277, 8, 0x20000100, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- Models
UPDATE `creature_model_info` SET `BoundingRadius`=1.888888955116271972, `CombatReach`=2, `VerifiedBuild`=61609 WHERE `DisplayID` IN (101598, 100874, 99467, 93583, 101541, 101510, 101505, 100873);
UPDATE `creature_model_info` SET `VerifiedBuild`=61609 WHERE `DisplayID` IN (97650, 93591, 100894, 97936, 93592, 100895, 100891, 100878, 100883, 101639, 93597, 93595, 101434, 93576, 93599, 93580, 93585, 93588, 100896, 101570, 100055, 93589, 93577, 92725, 100056, 100876, 100877, 101501, 100872, 101517, 93594, 93586, 93587, 101478, 11686, 93578, 101512, 16925, 100054, 101594, 93579, 34160, 101511, 100880, 101154, 100869, 100888);
UPDATE `creature_model_info` SET `BoundingRadius`=0.497715145349502563, `CombatReach`=1, `VerifiedBuild`=61609 WHERE `DisplayID`=99170;
UPDATE `creature_model_info` SET `BoundingRadius`=1.888888835906982421, `CombatReach`=2, `VerifiedBuild`=61609 WHERE `DisplayID` IN (101595, 101596, 101262);
UPDATE `creature_model_info` SET `BoundingRadius`=1.477756857872009277, `CombatReach`=1.875, `VerifiedBuild`=61609 WHERE `DisplayID`=101474;
UPDATE `creature_model_info` SET `BoundingRadius`=0.539418935775756835, `CombatReach`=0.5, `VerifiedBuild`=61609 WHERE `DisplayID`=98509;
UPDATE `creature_model_info` SET `BoundingRadius`=2.266666889190673828, `CombatReach`=2.40000009536743164, `VerifiedBuild`=61609 WHERE `DisplayID`=100892;
UPDATE `creature_model_info` SET `BoundingRadius`=0.5, `CombatReach`=1, `VerifiedBuild`=61609 WHERE `DisplayID`=95931;
UPDATE `creature_model_info` SET `BoundingRadius`=2.538181066513061523, `VerifiedBuild`=61609 WHERE `DisplayID`=81323;
UPDATE `creature_model_info` SET `BoundingRadius`=0.51841282844543457, `CombatReach`=1.5, `VerifiedBuild`=61609 WHERE `DisplayID`=91811;
UPDATE `creature_model_info` SET `BoundingRadius`=1.888888955116271972, `CombatReach`=2, `VerifiedBuild`=61609 WHERE `DisplayID` IN (101356, 100590, 101544, 94068, 101481, 98510, 98513);
UPDATE `creature_model_info` SET `VerifiedBuild`=61609 WHERE `DisplayID` IN (36665, 95807, 100910, 96716, 93855, 84122, 42109, 100925, 101954, 101270, 101327, 93600, 93581, 93596, 100680, 46710, 68547, 304, 85246, 5369, 48104, 19288, 18274, 19287, 18275, 76760, 76762, 76758, 97651, 92726, 101953, 101951, 93951, 99205, 101952, 76790, 31588, 14951, 100882, 35490, 97649, 76788, 525, 15435, 81964, 93601, 100889);
UPDATE `creature_model_info` SET `BoundingRadius`=0.783462584018707275, `VerifiedBuild`=61609 WHERE `DisplayID`=75730;
UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `VerifiedBuild`=61609 WHERE `DisplayID` IN (100778, 100674);
UPDATE `creature_model_info` SET `BoundingRadius`=1.699999928474426269, `CombatReach`=1.799999833106994628, `VerifiedBuild`=61609 WHERE `DisplayID` IN (101543, 101542);
UPDATE `creature_model_info` SET `BoundingRadius`=2.644444227218627929, `CombatReach`=2.799999952316284179, `VerifiedBuild`=61609 WHERE `DisplayID`=101573;
UPDATE `creature_model_info` SET `BoundingRadius`=1.477756977081298828, `CombatReach`=1.874999880790710449, `VerifiedBuild`=61609 WHERE `DisplayID`=101668;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.5, `VerifiedBuild`=61609 WHERE `DisplayID` IN (102054, 100407, 100564);
UPDATE `creature_model_info` SET `BoundingRadius`=1.477756857872009277, `CombatReach`=1.875, `VerifiedBuild`=61609 WHERE `DisplayID`=101477;
UPDATE `creature_model_info` SET `BoundingRadius`=1.477757096290588378, `CombatReach`=1.875, `VerifiedBuild`=61609 WHERE `DisplayID`=101473;
UPDATE `creature_model_info` SET `BoundingRadius`=0.382819831371307373, `CombatReach`=1, `VerifiedBuild`=61609 WHERE `DisplayID`=101763;
UPDATE `creature_model_info` SET `BoundingRadius`=1.888888835906982421, `CombatReach`=2, `VerifiedBuild`=61609 WHERE `DisplayID` IN (99465, 101476);
UPDATE `creature_model_info` SET `BoundingRadius`=1.888889074325561523, `CombatReach`=2.000000238418579101, `VerifiedBuild`=61609 WHERE `DisplayID`=101475;
UPDATE `creature_model_info` SET `BoundingRadius`=0.942703425884246826, `CombatReach`=2, `VerifiedBuild`=61609 WHERE `DisplayID`=93160;
UPDATE `creature_model_info` SET `BoundingRadius`=0.305999994277954101, `CombatReach`=1.499999880790710449, `VerifiedBuild`=61609 WHERE `DisplayID`=100406;
UPDATE `creature_model_info` SET `BoundingRadius`=1.463631868362426757, `VerifiedBuild`=61609 WHERE `DisplayID`=97658;
UPDATE `creature_model_info` SET `BoundingRadius`=1.671832442283630371, `CombatReach`=1, `VerifiedBuild`=61609 WHERE `DisplayID`=100408;
UPDATE `creature_model_info` SET `BoundingRadius`=2.732410192489624023, `CombatReach`=3.5, `VerifiedBuild`=61609 WHERE `DisplayID`=91330;
UPDATE `creature_model_info` SET `BoundingRadius`=10.19895076751708984, `CombatReach`=5, `VerifiedBuild`=61609 WHERE `DisplayID`=24717;
UPDATE `creature_model_info` SET `BoundingRadius`=0.442157149314880371, `CombatReach`=2, `VerifiedBuild`=61609 WHERE `DisplayID`=99094;
UPDATE `creature_model_info` SET `BoundingRadius`=0.620000004768371582, `VerifiedBuild`=61609 WHERE `DisplayID`=23962;
UPDATE `creature_model_info` SET `BoundingRadius`=1.70000004768371582, `CombatReach`=1.799999952316284179, `VerifiedBuild`=61609 WHERE `DisplayID`=93950;
UPDATE `creature_model_info` SET `BoundingRadius`=1.209403634071350097, `VerifiedBuild`=61609 WHERE `DisplayID`=100722;
UPDATE `creature_model_info` SET `BoundingRadius`=1.266006827354431152, `CombatReach`=1.5, `VerifiedBuild`=61609 WHERE `DisplayID`=101044;
UPDATE `creature_model_info` SET `BoundingRadius`=0.340000003576278686, `CombatReach`=1.5, `VerifiedBuild`=61609 WHERE `DisplayID`=86791;
UPDATE `creature_model_info` SET `BoundingRadius`=2.473866462707519531, `CombatReach`=2.5, `VerifiedBuild`=61609 WHERE `DisplayID`=101039;
UPDATE `creature_model_info` SET `BoundingRadius`=2.138610363006591796, `CombatReach`=2.5, `VerifiedBuild`=61609 WHERE `DisplayID`=94227;
UPDATE `creature_model_info` SET `BoundingRadius`=0.511442422866821289, `CombatReach`=2, `VerifiedBuild`=61609 WHERE `DisplayID`=78850;
UPDATE `creature_model_info` SET `BoundingRadius`=0.800000011920928955, `CombatReach`=4.800000190734863281, `VerifiedBuild`=61609 WHERE `DisplayID`=47441;
UPDATE `creature_model_info` SET `BoundingRadius`=0.270005762577056884, `CombatReach`=1, `VerifiedBuild`=61609 WHERE `DisplayID`=100460;
UPDATE `creature_model_info` SET `BoundingRadius`=0.238976046442985534, `CombatReach`=1, `VerifiedBuild`=61609 WHERE `DisplayID`=100438;
UPDATE `creature_model_info` SET `BoundingRadius`=1.513618111610412597, `CombatReach`=2.25, `VerifiedBuild`=61609 WHERE `DisplayID`=100049;

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=180852 AND `seat_id` IN (7,6,5,4,3,2,1,0));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(180852, 47203, 7, 1, 'Infested Bear - Creeper Egg', 7, 0), -- Infested Bear - Creeper Egg
(180852, 47203, 6, 1, 'Infested Bear - Creeper Egg', 7, 0), -- Infested Bear - Creeper Egg
(180852, 47203, 5, 1, 'Infested Bear - Creeper Egg', 7, 0), -- Infested Bear - Creeper Egg
(180852, 47203, 4, 1, 'Infested Bear - Creeper Egg', 7, 0), -- Infested Bear - Creeper Egg
(180852, 47203, 3, 1, 'Infested Bear - Creeper Egg', 7, 0), -- Infested Bear - Creeper Egg
(180852, 47203, 2, 1, 'Infested Bear - Creeper Egg', 7, 0), -- Infested Bear - Creeper Egg
(180852, 47203, 1, 1, 'Infested Bear - Creeper Egg', 7, 0), -- Infested Bear - Creeper Egg
(180852, 47203, 0, 1, 'Infested Bear - Creeper Egg', 7, 0); -- Infested Bear - Creeper Egg

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 180852;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(180852, 87978, 0, 0);

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=177999 AND `item`=185932 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(177999, 3, 185932, 1, 0, 1, 0, 0, 61609); -- Damaged Flask

DELETE FROM `npc_vendor` WHERE (`entry`=180130 AND `item`=34828 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180130 AND `item`=187179 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180130 AND `item`=161208 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180130 AND `item`=187190 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180130 AND `item`=183596 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180130 AND `item`=187189 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180129 AND `item`=44481 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180129 AND `item`=187178 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180129 AND `item`=104324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180114 AND `item`=187171 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180114 AND `item`=179271 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180114 AND `item`=178252 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180114 AND `item`=173859 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180117 AND `item`=187173 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180117 AND `item`=179276 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180117 AND `item`=179011 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180117 AND `item`=179018 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180117 AND `item`=178224 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180117 AND `item`=177043 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(180130, 6, 34828, 6, 0, 1, 0, 1, 61609), -- Antique Silver Cufflinks
(180130, 5, 187179, 10, 0, 1, 0, 1, 61609), -- Glow Sticks
(180130, 4, 161208, 5, 0, 1, 0, 1, 61609), -- Pirate's Snuff Box
(180130, 3, 187190, 1, 0, 1, 0, 1, 61609), -- Floral Print Button Down
(180130, 2, 183596, 5, 0, 1, 0, 1, 61609), -- Broken Artifact
(180130, 1, 187189, 1, 0, 1, 0, 1, 61609), -- Hyperlight Multitool
(180129, 3, 44481, 0, 0, 1, 0, 1, 61609), -- Grindgear Toy Gorilla
(180129, 2, 187178, 10, 0, 1, 0, 1, 61609), -- Sc'ootie's Favorite Plushie
(180129, 1, 104324, 0, 0, 1, 0, 1, 61609), -- Foot Ball
(180114, 4, 187171, 10, 0, 1, 0, 1, 61609), -- Organic Melon
(180114, 3, 179271, 0, 0, 1, 0, 0, 61609), -- Dredhollow Apple
(180114, 2, 178252, 0, 0, 1, 0, 0, 61609), -- Torchberry Bundle
(180114, 1, 173859, 0, 0, 1, 0, 0, 61609), -- Ethereal Pomegranate
(180117, 6, 187173, 10, 0, 1, 0, 1, 61609), -- Wriggling Tentacle
(180117, 5, 179276, 0, 0, 1, 0, 0, 61609), -- Chimaera Tripe Soup
(180117, 4, 179011, 0, 0, 1, 0, 0, 61609), -- Batloaf
(180117, 3, 179018, 0, 0, 1, 0, 0, 61609), -- Skullboar Chop
(180117, 2, 178224, 0, 0, 1, 0, 0, 61609), -- Steamed Gorm Tail
(180117, 1, 177043, 0, 0, 1, 0, 0, 61609); -- Reaped Larion Flank

DELETE FROM `npc_vendor` WHERE (`entry`=180562 AND `item`=187171 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180562 AND `item`=179271 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180562 AND `item`=178252 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180562 AND `item`=173859 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=185953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=39211 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=38586 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=67256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=25411 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=69772 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=62277 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=60405 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=45200 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=25442 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=62272 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=56162 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=25723 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=118899 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=90057 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=62520 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=45194 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=30478 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=41337 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=5263 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=180754 AND `item`=6297 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(180562, 4, 187171, 10, 0, 1, 0, 1, 61967), -- Organic Melon
(180562, 3, 179271, 0, 0, 1, 0, 0, 61967), -- Dredhollow Apple
(180562, 2, 178252, 0, 0, 1, 0, 0, 61967), -- Torchberry Bundle
(180562, 1, 173859, 0, 0, 1, 0, 0, 61967), -- Ethereal Pomegranate
(180754, 21, 185953, 0, 0, 1, 0, 0, 61967), -- Fraudulent Credentials
(180754, 20, 39211, 0, 0, 1, 0, 0, 61967), -- Serrated Fang
(180754, 19, 38586, 0, 0, 1, 0, 0, 61967), -- Spiny Leg
(180754, 18, 67256, 0, 0, 1, 0, 0, 61967), -- Kaja'mite Dust
(180754, 17, 25411, 0, 0, 1, 0, 0, 61967), -- Worn Hoof
(180754, 16, 69772, 0, 0, 1, 0, 0, 61967), -- Vibrant Petals
(180754, 15, 62277, 0, 0, 1, 0, 0, 61967), -- Revolting Ichor
(180754, 14, 60405, 0, 0, 1, 0, 0, 61967), -- -Unknown-
(180754, 13, 45200, 0, 0, 1, 0, 0, 61967), -- Sickly Fish
(180754, 12, 25442, 0, 0, 1, 0, 0, 61967), -- Mangled Snout
(180754, 11, 62272, 0, 0, 1, 0, 0, 61967), -- Spiny Carapace
(180754, 10, 56162, 0, 0, 1, 0, 0, 61967), -- -Unknown-
(180754, 9, 25723, 0, 0, 1, 0, 0, 61967), -- Bent Antenna
(180754, 8, 118899, 0, 0, 1, 0, 0, 61967), -- Crumbled Gem Shards
(180754, 7, 90057, 0, 0, 1, 0, 0, 61967), -- Hair Ball
(180754, 6, 62520, 0, 0, 1, 0, 0, 61967), -- Rancid Moss
(180754, 5, 45194, 0, 0, 1, 0, 0, 61967), -- Tangled Fishing Line
(180754, 4, 30478, 0, 0, 1, 0, 0, 61967), -- Stringy Ectoplasm
(180754, 3, 41337, 0, 0, 1, 0, 0, 61967), -- Whizzed-Out Gizmo
(180754, 2, 5263, 0, 0, 1, 0, 0, 61967), -- Pocket Lint
(180754, 1, 6297, 0, 0, 1, 0, 0, 61967); -- Old Skull

-- Enthusiastic Trader smart ai
SET @ENTRY := 180156;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 3000, 3000, 3000, 0, 5, 595, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 seconds (OOC) - Self: Play emote 595', '');

-- Meat Vendor smart ai
SET @ENTRY := 180117;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1500, 1500, 1500, 2000, 0, 10, 25, 274, 604, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 1.5 - 2 seconds (1.5 - 1.5s initially) (OOC) - Self: Play random emote: 25, 274, 604,', ''),
(@ENTRY, 0, 1, 0, 10, 0, 100, 1, 1, 14, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk 0 to invoker', '');

-- Fruit Vendor smart ai
SET @ENTRY := 180114;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 1, 1, 8, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk 0 to invoker', '');

-- Ta'ules smart ai
SET @ENTRY := 180266;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 10, 1, 5, 6, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play random emote: 1, 5, 6,', '');

-- Well-informed Trader smart ai
SET @ENTRY := 180147;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play emote 1', '');

-- Relaxed Patron smart ai
SET @ENTRY := 180150;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play emote 1', '');

-- Tracker Zo'korss smart ai
SET @ENTRY := 179837;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play emote 1', '');

-- Market Peacekeeper smart ai
SET @ENTRY := 179840;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 9000, 10000, 9000, 10000, 0, 5, 669, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 9 - 10 seconds (OOC) - Self: Play emote 669', '');

UPDATE `creature` SET `StringId`='CosmeticEmotes' WHERE `guid` IN (@CGUID+514, @CGUID+518, @CGUID+539, @CGUID+540, @CGUID+513);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 179840 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 179840, 0, 0, 58, 1, 0, 0, 0, 'CosmeticEmotes', 0, 'Object has StringID CosmeticEmotes');

-- Shop Patron smart ai
SET @ENTRY := 180310;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play emote 1', '');

UPDATE `creature` SET `StringId`='CosmeticEmotes' WHERE `guid` IN (@CGUID+274, @CGUID+10, @CGUID+9, @CGUID+236);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180310 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180310, 0, 0, 58, 1, 0, 0, 0, 'CosmeticEmotes', 0, 'Object has StringID CosmeticEmotes');

-- Export Supervisor smart ai
SET @ENTRY := 180228;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 4000, 3000, 4000, 0, 5, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 4 seconds (OOC) - Self: Play emote 22', '');

UPDATE `creature` SET `StringId`='CosmeticEmotes' WHERE `guid` IN (@CGUID+170, @CGUID+128);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180228 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180228, 0, 0, 58, 1, 0, 0, 0, 'CosmeticEmotes', 0, 'Object has StringID CosmeticEmotes');

-- Distressed Merchant smart ai
SET @ENTRY := 179908;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 10, 1, 6, 273, 274, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play random emote: 1, 6, 273, 274,', '');

UPDATE `creature` SET `StringId`='CosmeticEmotes' WHERE `guid` IN (@CGUID+533, @CGUID+527, @CGUID+612, @CGUID+566, @CGUID+610, @CGUID+568, @CGUID+592, @CGUID+577);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 179908 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 179908, 0, 0, 58, 1, 0, 0, 0, 'CosmeticEmotes', 0, 'Object has StringID CosmeticEmotes');

 -- Market Patron smart ai
SET @ENTRY := 180261;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 10, 1, 5, 6, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play random emote: 1, 5, 6, 25,', '');

UPDATE `creature` SET `StringId`='CosmeticEmotes' WHERE `guid` IN (@CGUID+120, @CGUID+125, @CGUID+114, @CGUID+110, @CGUID+148, @CGUID+108, @CGUID+106, @CGUID+118, @CGUID+138, @CGUID+153, @CGUID+171, @CGUID+178, @CGUID+185, @CGUID+199, @CGUID+202, @CGUID+186, @CGUID+189, @CGUID+187, @CGUID+188, @CGUID+190, @CGUID+192, @CGUID+230, @CGUID+232, @CGUID+252, @CGUID+247, @CGUID+239, @CGUID+261,  @CGUID+144, @CGUID+241);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180261 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180261, 0, 0, 58, 1, 0, 0, 0, 'CosmeticEmotes', 0, 'Object has StringID CosmeticEmotes');

 -- Illicit Purveyor smart ai
SET @ENTRY := 180320;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 10, 1, 5, 6, 25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play random emote: 1, 5, 6, 25,', '');

UPDATE `creature` SET `StringId`='CosmeticEmotes' WHERE `guid` IN (@CGUID+224, @CGUID+263, @CGUID+324, @CGUID+294, @CGUID+279);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180320 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180320, 0, 0, 58, 1, 0, 0, 0, 'CosmeticEmotes', 0, 'Object has StringID CosmeticEmotes');

-- Commerce Enforcer smart ai
SET @ENTRY := 179842;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 1, 0, 100, 0, 3000, 10000, 3000, 10000, 0, 5, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Play emote 1', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 128, 22905, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 3 - 10 seconds (OOC) - Self: Plays Anim with ID 22905', '');

UPDATE `creature` SET `StringId`='CosmeticScript' WHERE `guid` = @CGUID+555;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 179842 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 179842, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript', 0, 'Object has StringID CosmeticScript');

 -- Culinary Assistant smart ai
SET @ENTRY := 180244;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (18024400, 18024401);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 2, 0, 0, 0, 80, 18024400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Culinary Assistant #0 (18024400) (update out of combat) // -inline', ''),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 28, 356762, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  356762', ''),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 5, 36, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Play emote 36', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 4, 0, 0, 0, 80, 18024401, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list id #Culinary Assistant #1 (18024401) (update out of combat) // -inline', ''),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69', ''),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to 0', ''),
(@ENTRY * 100 + 1, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 85, 356762, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 356762 on self', '');

UPDATE `creature` SET `StringId`='CosmeticScript' WHERE `guid` = @CGUID+132;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180244 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180244, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript', 0, 'Object has StringID CosmeticScript'),
(22, 2, 180244, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript', 0, 'Object has StringID CosmeticScript');

 -- Export Hauler smart ai
SET @ENTRY := 180215;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (18021500, 18021501, 18021502, 18021503, 18021504);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 0, 0, 0, 0, 85, 356711, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform - Self: Cast spell 356711 on self', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 4, 0, 0, 0, 80, 18021500, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Start timed action list id #Export Hauler #0 (18021500) (update out of combat) // -inline', ''),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 28, 356711, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  356711', ''),
(@ENTRY, 0, 2, 0, 34, 0, 100, 0, 2, 19, 0, 0, 0, 85, 356711, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 19 - Self: Cast spell 356711 on self', ''),
(@ENTRY, 0, 3, 0, 34, 0, 100, 0, 2, 8, 0, 0, 0, 80, 18021501, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Start timed action list id #Export Hauler #1 (18021501) (update out of combat) // -inline', ''),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 28, 356711, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  356711', ''),
(@ENTRY, 0, 4, 0, 34, 0, 100, 0, 2, 9, 0, 0, 0, 85, 356711, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Cast spell 356711 on self', ''),
(@ENTRY, 0, 5, 0, 34, 0, 100, 0, 2, 2, 0, 0, 0, 80, 18021502, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #Export Hauler #2 (18021502) (update out of combat) // -inline', ''),
(@ENTRY * 100 + 2, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 28, 356711, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  356711', ''),
(@ENTRY, 0, 6, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, 17, 900, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just created - Self: Set emote state to 900', ''),
(@ENTRY, 0, 7, 0, 34, 0, 100, 0, 2, 1, 0, 0, 0, 80, 18021503, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 1 - Self: Start timed action list id #Export Hauler #3 (18021503) (update out of combat) // -inline', ''),
(@ENTRY * 100 + 3, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 3.47321, 'After 1 seconds - Self: Set orientation to 3.47321', ''),
(@ENTRY * 100 + 3, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 0, 11, 180215, 20, 1, 0, 0, 0, 0, 'After 3 seconds - Creature Export Hauler (180215) in 20 yd: Set creature data #0 to 1', ''),
(@ENTRY, 0, 8, 0, 34, 0, 100, 0, 2, 0, 0, 0, 0, 80, 18021504, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform - Self: Start timed action list id #Export Hauler #4 (18021504) (update out of combat) // -inline', ''),
(@ENTRY * 100 + 4, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 4.29351, 'After 1 seconds - Self: Set orientation to 4.29351', ''),
(@ENTRY * 100 + 4, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 28, 356706, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  356706', ''),
(@ENTRY, 0, 9, 10, 38, 0, 100, 0, 0, 1, 0, 0, 0, 11, 356706, 0, 0, 0, 0, 0, 0, 11, 180215, 20, 1, 0, 0, 0, 0, 'On data[0] set to 1 - Self: Cast spell  356706 on Creature Export Hauler (180215) in 20 yd', ''),
(@ENTRY, 0, 10, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[0] set to 1 - Self: Set data[0] to 0', '');

UPDATE `creature` SET `StringId`='CosmeticScript1' WHERE `guid` = @CGUID+127;
UPDATE `creature` SET `StringId`='CosmeticScript2' WHERE `guid` = @CGUID+168;
UPDATE `creature` SET `StringId`='CosmeticScript3' WHERE `guid` = @CGUID+133;
UPDATE `creature` SET `StringId`='CosmeticScript4' WHERE `guid` = @CGUID+172;
UPDATE `creature` SET `StringId`='CosmeticScript5' WHERE `guid` = @CGUID+175;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180215 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript1', 0, 'Object has StringID CosmeticScript1'),
(22, 2, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript1', 0, 'Object has StringID CosmeticScript1'),
(22, 3, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript2', 0, 'Object has StringID CosmeticScript2'),
(22, 4, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript2', 0, 'Object has StringID CosmeticScript2'),
(22, 5, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript3', 0, 'Object has StringID CosmeticScript3'),
(22, 6, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript3', 0, 'Object has StringID CosmeticScript3'),
(22, 7, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript4', 0, 'Object has StringID CosmeticScript4'),
(22, 8, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript4', 0, 'Object has StringID CosmeticScript4'),
(22, 9, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript4', 0, 'Object has StringID CosmeticScript4'),
(22, 10, 180215, 0, 0, 58, 1, 0, 0, 0, 'CosmeticScript5', 0, 'Object has StringID CosmeticScript5');

-- Cartel Muscle smart ai
SET @ENTRY := 180348;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (18034800, 18034801);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 34, 0, 100, 0, 2, 8, 0, 0, 0, 80, 18034800, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 8 - Self: Start timed action list id #Cartel Muscle #0 (18034800) (update out of combat) // -inline', ''),
(@ENTRY * 100, 9, 0, 0, 0, 0, 100, 0, 12000, 12000, 0, 0, 0, 85, 357099, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 0, 0, 0, 0, 'After 12 seconds - Self: Cast spell 357099 on self', ''),
(@ENTRY * 100, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 0, 1, 0, 0, 0, 0, 0, 11, 0, 15, 0, 0, 'CartelMuscleTarget', 0, 0, 0, 0, 'After 0 seconds - Any creature in 0 yd: Set creature data #0 to 1', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 24, 0, 0, 0, 80, 18034801, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 24 - Self: Start timed action list id #Cartel Muscle #1 (18034801) (update out of combat) // -inline', ''),
(@ENTRY * 100 + 1, 9, 0, 0, 0, 0, 100, 0, 10000, 10000, 0, 0, 0, 28, 357099, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, '', 0, 0, 0, 0, 'After 10 seconds - Self: Remove aura due to spell  357099', ''),
(@ENTRY * 100 + 1, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 45, 0, 0, 0, 0, 0, 0, 0, 11, 0, 15, 0, 0, 'CartelMuscleTarget', 0, 0, 0, 0, 'After 0 seconds - Any creature in 0 yd: Set creature data #0 to 0', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180348 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180348, 0, 0, 58, 1, 0, 0, 0, 'CartelMuscleScript', 0, 'Object has StringID CartelMuscleScript'),
(22, 2, 180348, 0, 0, 58, 1, 0, 0, 0, 'CartelMuscleScript', 0, 'Object has StringID CartelMuscleScript');

UPDATE `creature` SET `StringId`='CartelMuscleScript' WHERE `guid` = @CGUID+254;
UPDATE `creature` SET `StringId`='CartelMuscleTarget' WHERE `guid` IN (@CGUID+255, @CGUID+256, @CGUID+257);

-- Cartel Wiseguy smart ai
SET @ENTRY := 180336;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 0, 0, 0, 0, 0, 28, 357100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[0] set to 0 - Self: Remove aura due to spell  357100', ''),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 0, 1, 0, 0, 0, 11, 357100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[0] set to 1 - Self: Cast spell  357100 on Self', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180336 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180336, 0, 0, 58, 1, 0, 0, 0, 'CartelMuscleTarget', 0, 'Object has StringID CartelMuscleTarget'),
(22, 2, 180336, 0, 0, 58, 1, 0, 0, 0, 'CartelMuscleTarget', 0, 'Object has StringID CartelMuscleTarget');

-- Cartel Smuggler smart ai
SET @ENTRY := 180335;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 38, 0, 100, 0, 0, 0, 0, 0, 0, 28, 357100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[0] set to 0 - Self: Remove aura due to spell  357100', ''),
(@ENTRY, 0, 1, 0, 38, 0, 100, 0, 0, 1, 0, 0, 0, 11, 357100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On data[0] set to 1 - Self: Cast spell  357100 on Self', '');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 180335 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 180335, 0, 0, 58, 1, 0, 0, 0, 'CartelMuscleTarget', 0, 'Object has StringID CartelMuscleTarget'),
(22, 2, 180335, 0, 0, 58, 1, 0, 0, 0, 'CartelMuscleTarget', 0, 'Object has StringID CartelMuscleTarget');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID`IN (180114, 180117);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(180114, 0, 0, 'I wouldn\'t touch that meat, they don\'t call it the Veiled Market for nothing... Allow me to interest you in this fruit before Customs handles it?', 12, 0, 100, 0, 0, 0, 0, 0, 'Fruit Vendor'),
(180117, 0, 0, 'Our meats have not yet passed through Customs, the price cannot be beat!', 12, 0, 100, 274, 0, 0, 0, 0, 'Meat Vendor');

-- Armored Overseer
SET @ENTRY := 177808;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Armored Overseer - Path first boss');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3643.057, -1649.545, 106.2295, NULL, 0),
(@PATH, 1, 3622.485, -1639.094, 106.2189, NULL, 0),
(@PATH, 2, 3641.838, -1628.868, 106.1789, NULL, 0);

UPDATE `creature` SET `position_x`= 3643.057, `position_y`= -1649.545, `position_z`= 106.2295, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+78;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+78;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+78, @PATH, 1);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+78;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+78, @CGUID+78, 0, 0, 515, 0, 0),
(@CGUID+78, @CGUID+75, 3, 0, 515, 0, 0),
(@CGUID+78, @CGUID+63, 3, 90, 515, 0, 0);

-- Market Patron
SET @ENTRY := 180261;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Market Patron - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3623.122, -1536.997, 106.0812, NULL, 10871),
(@PATH, 1, 3621.147, -1532.712, 106.2451, NULL, 0),
(@PATH, 2, 3616.059, -1525.776, 106.0812, NULL, 0),
(@PATH, 3, 3611.753, -1519.981, 106.0812, NULL, 0),
(@PATH, 4, 3610.113, -1516.95, 106.0812, NULL, 0),
(@PATH, 5, 3609.517, -1514.597, 106.0812, NULL, 0),
(@PATH, 6, 3609.042, -1510.918, 106.0927, NULL, 15702),
(@PATH, 7, 3610.113, -1516.95, 106.0812, NULL, 0),
(@PATH, 8, 3611.753, -1519.981, 106.0812, NULL, 0),
(@PATH, 9, 3616.059, -1525.776, 106.0812, NULL, 0),
(@PATH, 10, 3621.147, -1532.712, 106.2451, NULL, 0);

UPDATE `creature` SET `position_x`= 3623.122, `position_y`= -1536.997, `position_z`= 106.0812, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+126;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+126;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+126, @PATH, 1);

-- Export Hauler #1
SET @ENTRY := 180215;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Export Hauler #1 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3591.825, -1546.639, 106.0812, NULL, 2206),
(@PATH, 1, 3595.609, -1540.104, 106.1508, NULL, 0),
(@PATH, 2, 3596.019, -1530.769, 106.0812, NULL, 0),
(@PATH, 3, 3596.154, -1523.304, 106.0812, NULL, 311),
(@PATH, 4, 3587.917, -1516.002, 106.0812, 2.278828, 3682),
(@PATH, 5, 3594.549, -1524.51, 106.1593, NULL, 0),
(@PATH, 6, 3595.111, -1527.477, 106.096, NULL, 0),
(@PATH, 7, 3595.303, -1534.236, 106.0812, NULL, 0),
(@PATH, 8, 3595.317, -1539.896, 106.1537, NULL, 0);

UPDATE `creature` SET `position_x`= 3591.825, `position_y`= -1546.639, `position_z`= 106.0812, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+127;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+127;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+127, @PATH, 1);

-- Export Hauler #2
SET @ENTRY := 180215;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Export Hauler #2 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3594.338, -1474.925, 93.28431, NULL, 0),
(@PATH, 1, 3598.546, -1474.29, 93.28431, NULL, 0),
(@PATH, 2, 3610.245, -1467.863, 93.2843, NULL, 0),
(@PATH, 3, 3618.375, -1466.104, 93.48515, NULL, 0),
(@PATH, 4, 3622.411, -1464.382, 93.28431, NULL, 0),
(@PATH, 5, 3627.892, -1460.497, 93.37067, NULL, 0),
(@PATH, 6, 3631.588, -1459.465, 93.35465, NULL, 0),
(@PATH, 7, 3642.555, -1459.427, 93.2843, NULL, 225),
(@PATH, 8, 3646.49, -1459.139, 93.33517, 0.162106, 5636),
(@PATH, 9, 3631.736, -1459.208, 93.34896, NULL, 0),
(@PATH, 10, 3628.018, -1460.264, 93.37234, NULL, 0),
(@PATH, 11, 3625.304, -1461.778, 93.30709, NULL, 0),
(@PATH, 12, 3622.481, -1464.451, 93.28431, NULL, 0),
(@PATH, 13, 3618.767, -1466.101, 93.45141, NULL, 0),
(@PATH, 14, 3614.74, -1466.068, 93.36626, NULL, 0),
(@PATH, 15, 3610.477, -1467.738, 93.2843, NULL, 0),
(@PATH, 16, 3598.703, -1474.146, 93.28431, NULL, 0),
(@PATH, 17, 3594.558, -1474.773, 93.28431, NULL, 0),
(@PATH, 18, 3583.253, -1475.401, 93.28431, NULL, 0),
(@PATH, 19, 3563.32, -1478.108, 93.2843, NULL, 2368);

UPDATE `creature` SET `position_x`= 3594.338, `position_y`= -1474.925, `position_z`= 93.28431, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+168;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+168;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+168, @PATH, 1);

-- Export Hauler #3
SET @ENTRY := 180215;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Export Hauler #3 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3579.988, -1485.729, 93.28431, NULL, 0),
(@PATH, 1, 3585.193, -1494.97, 93.2843, NULL, 236),
(@PATH, 2, 3586.22, -1504.212, 93.2843, 1.327800, 4696),
(@PATH, 3, 3586.888, -1499.122, 93.58195, NULL, 0),
(@PATH, 4, 3585.332, -1494.554, 93.28429, NULL, 0),
(@PATH, 5, 3580.2, -1485.727, 93.28431, NULL, 0),
(@PATH, 6, 3577.553, -1482.345, 93.28431, NULL, 0),
(@PATH, 7, 3574.518, -1481.493, 93.67493, NULL, 0),
(@PATH, 8, 3567.75, -1480.619, 93.37849, NULL, 0),
(@PATH, 9, 3563.064, -1479.773, 93.35552, NULL, 2463),
(@PATH, 10, 3575.877, -1481.686, 93.45856, NULL, 0),
(@PATH, 11, 3577.423, -1482.295, 93.28431, NULL, 0);

UPDATE `creature` SET `position_x`= 3579.988, `position_y`= -1485.729, `position_z`= 93.28431, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+133;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+133;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+133, @PATH, 1);

-- Export Hauler #4
SET @ENTRY := 180215;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Export Hauler #4 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3558.48, -1479.31, 93.28429, 4.293509, 3500),
(@PATH, 1, 3558.94, -1473.94, 93.2843, 3.473205, 7961);

UPDATE `creature` SET `position_x`= 3558.48, `position_y`= -1479.31, `position_z`= 93.28429, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+172;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+172;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+172, @PATH, 1);

-- Curiosity
SET @ENTRY := 180269;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Tazavesh - Curiosity - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3644.997, -1465.411, 93.67493, NULL, 0),
(@PATH, 1, 3647.531, -1465.01, 93.28036, NULL, 0),
(@PATH, 2, 3653.672, -1467.734, 93.43856, NULL, 0),
(@PATH, 3, 3657.786, -1470.973, 93.28429, NULL, 0),
(@PATH, 4, 3658.073, -1478.379, 93.67493, NULL, 0),
(@PATH, 5, 3661.028, -1495.983, 93.28431, NULL, 0),
(@PATH, 6, 3662.297, -1499.382, 93.2843, NULL, 0),
(@PATH, 7, 3668.025, -1510.686, 93.28429, NULL, 0),
(@PATH, 8, 3672.63, -1516.354, 93.28429, NULL, 0),
(@PATH, 9, 3683.143, -1523.764, 93.28431, NULL, 0),
(@PATH, 10, 3685.832, -1527.733, 93.28431, NULL, 0),
(@PATH, 11, 3686.083, -1531.877, 93.28429, NULL, 0),
(@PATH, 12, 3681.693, -1541.578, 93.2843, NULL, 0),
(@PATH, 13, 3670.49, -1545.797, 93.41192, NULL, 14664),
(@PATH, 14, 3673.623, -1520.635, 93.2843, NULL, 0),
(@PATH, 15, 3672.267, -1515.224, 93.28429, NULL, 0),
(@PATH, 16, 3652.646, -1483.639, 93.2843, NULL, 0),
(@PATH, 17, 3644.136, -1480.625, 93.28429, NULL, 0),
(@PATH, 18, 3630.355, -1479.08, 93.2843, NULL, 0),
(@PATH, 19, 3619.028, -1477.193, 93.28123, NULL, 0),
(@PATH, 20, 3613.191, -1480.095, 93.2843, NULL, 0),
(@PATH, 21, 3614.425, -1485.504, 93.2843, NULL, 11137),
(@PATH, 22, 3600.501, -1481.809, 93.2843, NULL, 0),
(@PATH, 23, 3591.436, -1486.16, 93.28431, NULL, 0),
(@PATH, 24, 3585.992, -1484.189, 93.28431, NULL, 0),
(@PATH, 25, 3587.56, -1465.965, 93.28429, NULL, 0),
(@PATH, 26, 3595.39, -1458.811, 93.2843, NULL, 0),
(@PATH, 27, 3601.235, -1456.306, 93.28431, NULL, 0),
(@PATH, 28, 3618.086, -1454.109, 93.298, NULL, 0),
(@PATH, 29, 3622.926, -1459.818, 93.67493, NULL, 0),
(@PATH, 30, 3630.112, -1465.545, 93.45061, NULL, 152),
(@PATH, 31, 3632.839, -1468.113, 93.46522, NULL, 14233);

UPDATE `creature` SET `position_x`= 3644.997, `position_y`= -1465.411, `position_z`= 93.67493, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+131;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+131;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+131, @PATH, 1);

-- Market Server #1
SET @ENTRY := 180249;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Market Server #1 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3612.099, -1493.316, 93.2843, NULL, 0),
(@PATH, 1, 3608.574, -1492.405, 93.32345, NULL, 0),
(@PATH, 2, 3606.804, -1491.958, 93.36703, NULL, 0),
(@PATH, 3, 3607.523, -1489.311, 93.29504, NULL, 4072),
(@PATH, 4, 3608.574, -1492.405, 93.32345, NULL, 0),
(@PATH, 5, 3612.099, -1493.316, 93.2843, NULL, 0),
(@PATH, 6, 3614.453, -1494.043, 93.2843, NULL, 0),
(@PATH, 7, 3617.503, -1493.969, 93.2843, NULL, 4099);

UPDATE `creature` SET `position_x`= 3612.099, `position_y`= -1493.316, `position_z`= 93.2843, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+134;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+134;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+134, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356765');

-- Market Server #2
SET @ENTRY := 180249;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Market Server #2- Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3624.417, -1481.374, 93.63926, NULL, 0),
(@PATH, 1, 3626.539, -1481.507, 93.67493, NULL, 0),
(@PATH, 2, 3631.055, -1483.066, 93.72887, NULL, 0),
(@PATH, 3, 3634.637, -1485.677, 93.44996, NULL, 5085),
(@PATH, 4, 3628.133, -1481.984, 93.67493, NULL, 0),
(@PATH, 5, 3624.477, -1481.295, 93.67493, NULL, 0),
(@PATH, 6, 3622.613, -1483.757, 93.32465, NULL, 0),
(@PATH, 7, 3619.487, -1488.948, 93.29332, 1.028784, 5059),
(@PATH, 8, 3622.613, -1483.757, 93.32465, NULL, 0);

UPDATE `creature` SET `position_x`= 3624.417, `position_y`= -1481.374, `position_z`= 93.63926, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+161;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+161;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+161, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356765');

-- Culinary Assistant
SET @ENTRY := 180244;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Culinary Assistant - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3630.585, -1492.087, 93.48743, NULL, 0),
(@PATH, 1, 3622.203, -1490.29, 93.48743, NULL, 0),
(@PATH, 2, 3621.325, -1490.957, 93.38052, 3.351032, 3768),
(@PATH, 3, 3631.504, -1492.46, 93.48743, NULL, 0),
(@PATH, 4, 3633.083, -1496.111, 93.28429, 6.00296020, 4898);

UPDATE `creature` SET `position_x`= 3630.585, `position_y`= -1492.087, `position_z`= 93.48743, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+132;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+132;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+132, @PATH, 1);

-- Cartel Muscle
SET @ENTRY := 180348;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Cartel Muscle - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3724.207, -1385.563, 73.90295, NULL, 0),
(@PATH, 1, 3718.684, -1379.892, 73.92036, NULL, 0),
(@PATH, 2, 3711.144, -1373.481, 73.97126, NULL, 0),
(@PATH, 3, 3702.655, -1367.113, 73.94049, NULL, 0),
(@PATH, 4, 3692.103, -1362.429, 74.01305, NULL, 0),
(@PATH, 5, 3682.472, -1360.896, 73.87805, NULL, 0),
(@PATH, 6, 3673.541, -1360.672, 73.92935, NULL, 0),
(@PATH, 7, 3662.045, -1359.684, 73.87805, NULL, 0),
(@PATH, 8, 3649.938, -1359.54, 73.87805, NULL, 13242),
(@PATH, 9, 3661.945, -1359.615, 73.87805, NULL, 0),
(@PATH, 10, 3668.826, -1362.422, 73.87574, NULL, 0),
(@PATH, 11, 3673.948, -1362.882, 73.91201, NULL, 0),
(@PATH, 12, 3678.596, -1362.858, 73.94904, NULL, 0),
(@PATH, 13, 3684.847, -1363.241, 73.87805, NULL, 0),
(@PATH, 14, 3693.767, -1366.958, 73.91072, NULL, 0),
(@PATH, 15, 3699.437, -1370.439, 73.87805, NULL, 0),
(@PATH, 16, 3704.934, -1373.175, 73.92157, NULL, 0),
(@PATH, 17, 3710.678, -1376.372, 73.93414, NULL, 0),
(@PATH, 18, 3716.667, -1379.872, 73.90383, NULL, 0),
(@PATH, 19, 3721.416, -1383.589, 73.92229, NULL, 0),
(@PATH, 20, 3736.286, -1401.879, 73.96745, NULL, 0),
(@PATH, 21, 3742.123, -1402.91, 74.07781, NULL, 0),
(@PATH, 22, 3750.23, -1402.882, 74.08065, NULL, 0),
(@PATH, 23, 3757.7, -1402.642, 74.08065, NULL, 0),
(@PATH, 24, 3760.818, -1402.324, 73.87751, NULL, 11122),
(@PATH, 25, 3744.144, -1403.255, 74.08065, NULL, 0),
(@PATH, 26, 3737.769, -1402.297, 73.99581, NULL, 0),
(@PATH, 27, 3733.358, -1396.868, 73.87753, NULL, 0);

UPDATE `creature` SET `position_x`= 3724.207, `position_y`= -1385.563, `position_z`= 73.90295, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+254;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+254;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+254, @PATH, 1);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+254;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+254, @CGUID+254, 0, 0, 515, 0, 0),
(@CGUID+254, @CGUID+255, 3, 0, 515, 0, 0),
(@CGUID+254, @CGUID+256, 6, 0, 515, 0, 0),
(@CGUID+254, @CGUID+257, 9, 0, 515, 0, 0);

-- Patio Waiter #1
SET @ENTRY := 180314;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Patio Waiter #1 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3747.454, -1422.196, 73.87753, NULL, 0),
(@PATH, 1, 3747.122, -1418.828, 73.87753, NULL, 0),
(@PATH, 2, 3747.095, -1415.877, 74.15359, NULL, 0),
(@PATH, 3, 3746.455, -1414.703, 73.87753, NULL, 14291),
(@PATH, 4, 3747.211, -1420.342, 73.87753, NULL, 0),
(@PATH, 5, 3747.454, -1422.196, 73.87753, NULL, 0),
(@PATH, 6, 3748.316, -1425.524, 73.87753, NULL, 0),
(@PATH, 7, 3748.429, -1427.174, 73.87753, 4.780818, 13039);

UPDATE `creature` SET `position_x`= 3747.454, `position_y`= -1422.196, `position_z`= 73.87753, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+238;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+238;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+238, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356765');

-- Patio Waiter #2
SET @ENTRY := 180314;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Patio Waiter #2 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3746.939, -1362.417, 73.87753, NULL, 0),
(@PATH, 1, 3746.959, -1366.83, 73.87753, NULL, 0),
(@PATH, 2, 3746.671, -1371.068, 73.87753, NULL, 0),
(@PATH, 3, 3746.582, -1376.144, 73.87753, NULL, 0),
(@PATH, 4, 3745.346, -1378.974, 73.87753, NULL, 0),
(@PATH, 5, 3742.99, -1382.715, 73.87753, NULL, 0),
(@PATH, 6, 3742.694, -1384.432, 73.87753, NULL, 0),
(@PATH, 7, 3745.213, -1386.91, 73.87753, NULL, 12236),
(@PATH, 8, 3742.99, -1382.715, 73.87753, NULL, 0),
(@PATH, 9, 3743.767, -1381.118, 73.87753, NULL, 0),
(@PATH, 10, 3746.582, -1376.144, 73.87753, NULL, 0),
(@PATH, 11, 3746.671, -1371.068, 73.87753, NULL, 0),
(@PATH, 12, 3746.959, -1366.83, 73.87753, NULL, 0),
(@PATH, 13, 3746.939, -1362.417, 73.87753, NULL, 0),
(@PATH, 14, 3746.478, -1359.429, 73.87753, NULL, 0),
(@PATH, 15, 3744.431, -1357.316, 73.87753, NULL, 8551);

UPDATE `creature` SET `position_x`= 3746.939, `position_y`= -1362.417, `position_z`= 73.87753, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+273;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+273;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+273, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '356765');

-- Auction Bidder #1
SET @ENTRY := 179886;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Auction Bidder #1 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3397.531, -1294.844, 73.80552, NULL, 0),
(@PATH, 1, 3397.35, -1292.231, 73.69257, NULL, 210),
(@PATH, 2, 3397.365, -1285.715, 73.67068, NULL, 0),
(@PATH, 3, 3397.322, -1285.66, 73.67044, NULL, 138),
(@PATH, 4, 3398.368, -1291.356, 73.68837, NULL, 0),
(@PATH, 5, 3398.432, -1294.757, 73.80866, NULL, 0),
(@PATH, 6, 3397.92, -1297.396, 73.86452, NULL, 0),
(@PATH, 7, 3396.806, -1300.259, 73.84351, NULL, 7775),
(@PATH, 8, 3397.531, -1294.844, 73.80552, NULL, 0),
(@PATH, 9, 3397.35, -1292.231, 73.69257, NULL, 0),
(@PATH, 10, 3397.898, -1288.675, 73.67763, NULL, 0),
(@PATH, 11, 3397.365, -1285.715, 73.67068, NULL, 0),
(@PATH, 12, 3397.031, -1283.639, 73.68538, 3.263765, 6617);

UPDATE `creature` SET `position_x`= 3397.531, `position_y`= -1294.844, `position_z`= 73.80552, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+413;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+413;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+413, @PATH, 1);

-- Auction Bidder #2
SET @ENTRY := 179886;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Auction Bidder #2 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3407.629, -1272.561, 73.80139, NULL, 0),
(@PATH, 1, 3408.451, -1275.665, 73.74483, NULL, 0),
(@PATH, 2, 3408.941, -1279.832, 73.69954, NULL, 6729),
(@PATH, 3, 3408.095, -1273.967, 73.77555, NULL, 0),
(@PATH, 4, 3407.323, -1270.247, 73.84282, NULL, 0),
(@PATH, 5, 3406.403, -1267.802, 73.70541, NULL, 0),
(@PATH, 6, 3405.888, -1266.839, 73.67493, 3.263765, 5526);

UPDATE `creature` SET `position_x`= 3407.629, `position_y`= -1272.561, `position_z`= 73.80139, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+421;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+421;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+421, @PATH, 1);

-- Auction Bidder #3
SET @ENTRY := 179886;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Auction Bidder #3 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3385.168, -1246.665, 73.86291, 3.263765, 8853),
(@PATH, 1, 3391.917, -1248.069, 73.86182, NULL, 0),
(@PATH, 2, 3393.849, -1248.891, 73.84546, NULL, 0),
(@PATH, 3, 3396.653, -1251.99, 73.74873, NULL, 0),
(@PATH, 4, 3396.917, -1252.649, 73.72555, 5.093915, 10166),
(@PATH, 5, 3392.228, -1250.047, 73.78856, NULL, 0),
(@PATH, 6, 3390.012, -1248.663, 73.82423, NULL, 0),
(@PATH, 7, 3387.04, -1247.521, 73.84475, NULL, 0);

UPDATE `creature` SET `position_x`= 3385.168, `position_y`= -1246.665, `position_z`= 73.86291, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+437;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+437;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+437, @PATH, 1);

-- Auction Bidder #4
SET @ENTRY := 179886;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Auction Bidder #4 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3386.17, -1256.986, 73.80865, NULL, 6444),
(@PATH, 1, 3380.309, -1253.644, 73.85813, NULL, 0),
(@PATH, 2, 3378.321, -1252.814, 73.87574, NULL, 0),
(@PATH, 3, 3376.006, -1251.542, 73.83573, NULL, 0),
(@PATH, 4, 3373.246, -1250.528, 73.84431, NULL, 0),
(@PATH, 5, 3370.79, -1249.592, 73.87395, NULL, 0),
(@PATH, 6, 3368.852, -1249.271, 73.84632, 3.263765, 4496),
(@PATH, 7, 3374.033, -1250.111, 73.84032, NULL, 0),
(@PATH, 8, 3376.569, -1251.286, 73.86591, NULL, 0),
(@PATH, 9, 3380.174, -1252.538, 73.85648, NULL, 0),
(@PATH, 10, 3382.986, -1254.222, 73.83295, NULL, 0);

UPDATE `creature` SET `position_x`= 3386.17, `position_y`= -1256.986, `position_z`= 73.80865, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+438;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+438;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+438, @PATH, 1);

-- Bazaar Shopper #1
SET @ENTRY := 177996;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Bazaar Shopper #1 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3791.019, -1275.26, 73.87753, NULL, 0),
(@PATH, 1, 3785.884, -1241.214, 73.87753, NULL, 0),
(@PATH, 2, 3770.589, -1211.906, 73.90927, NULL, 0),
(@PATH, 3, 3754.881, -1180.271, 73.94542, NULL, 0),
(@PATH, 4, 3754.528, -1146.707, 73.87753, NULL, 0),
(@PATH, 5, 3766.551, -1129.509, 73.87925, NULL, 7),
(@PATH, 6, 3754.528, -1146.707, 73.87753, NULL, 0),
(@PATH, 7, 3754.881, -1180.271, 73.94542, NULL, 0),
(@PATH, 8, 3770.589, -1211.906, 73.90927, NULL, 0),
(@PATH, 9, 3785.884, -1241.214, 73.87753, NULL, 0),
(@PATH, 10, 3791.019, -1275.26, 73.87753, NULL, 0),
(@PATH, 11, 3787.616, -1302.056, 73.87753, NULL, 0),
(@PATH, 12, 3808.097, -1310.141, 73.92577, NULL, 84),
(@PATH, 13, 3787.616, -1302.056, 73.87753, NULL, 0);

UPDATE `creature` SET `position_x`= 3790.615, `position_y`= -1275.172, `position_z`= 73.87753, `orientation`= 0, `wander_distance`= 0 WHERE `guid`= @CGUID+323;
UPDATE `creature` SET `position_x`= 3791.019, `position_y`= -1275.26, `position_z`= 73.87753, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+357;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+357;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+357, @PATH, 1);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+357;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+357, @CGUID+357, 0, 0, 515, 0, 0),
(@CGUID+357, @CGUID+323, 3, 0, 515, 0, 0);

-- Bazaar Shopper #2
SET @ENTRY := 177996;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Bazaar Shopper #2 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3818.031, -1318.812, 74.0293, 4.712388, 3297),
(@PATH, 1, 3811.19, -1318.9, 74.1556, 4.712388, 5740);

UPDATE `creature` SET `position_x`= 3818.031, `position_y`= -1318.812, `position_z`= 74.0293, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+346;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+346;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+346, @PATH, 1);

-- Bazaar Shopper #3
SET @ENTRY := 177996;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Bazaar Shopper #3 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3784.848, -1303.283, 73.87753, NULL, 352),
(@PATH, 1, 3756.288, -1311.283, 73.96158, NULL, 0),
(@PATH, 2, 3723.654, -1306.03, 73.87805, NULL, 0),
(@PATH, 3, 3715.878, -1282.521, 73.87805, NULL, 0),
(@PATH, 4, 3710.065, -1260.934, 73.87806, NULL, 0),
(@PATH, 5, 3714.791, -1237.476, 73.87805, NULL, 0),
(@PATH, 6, 3718.523, -1216.262, 73.89397, NULL, 368),
(@PATH, 7, 3714.791, -1237.476, 73.87805, NULL, 0),
(@PATH, 8, 3710.065, -1260.934, 73.87806, NULL, 0),
(@PATH, 9, 3715.878, -1282.521, 73.87805, NULL, 0),
(@PATH, 10, 3723.654, -1306.03, 73.87805, NULL, 0),
(@PATH, 11, 3756.288, -1311.283, 73.96158, NULL, 0);

UPDATE `creature` SET `position_x`= 3782.823, `position_y`= -1303.85, `position_z`= 73.87753, `orientation`= 0, `wander_distance`= 0 WHERE `guid`= @CGUID+318;
UPDATE `creature` SET `position_x`= 3784.848, `position_y`= -1303.283, `position_z`= 73.87753, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+347;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+347;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+347, @PATH, 1);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+347;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+347, @CGUID+347, 0, 0, 515, 0, 0),
(@CGUID+347, @CGUID+318, 3, 0, 515, 0, 0);

-- Commerce Enforcer #1
SET @ENTRY := 179842;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Commerce Enforcer #1 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3526.357, -1182.708, 73.92381, NULL, 0),
(@PATH, 1, 3519.095, -1172.049, 73.92639, NULL, 4990),
(@PATH, 2, 3526.357, -1182.708, 73.92381, NULL, 0),
(@PATH, 3, 3539.863, -1192.215, 73.87805, NULL, 0),
(@PATH, 4, 3549.756, -1198.712, 73.89896, NULL, 4068),
(@PATH, 5, 3539.863, -1192.215, 73.87805, NULL, 0);

UPDATE `creature` SET `position_x`= 3526.357, `position_y`= -1182.708, `position_z`= 73.92381, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+556;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+556;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+556, @PATH, 1);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+556;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+556, @CGUID+556, 0, 0, 515, 0, 0),
(@CGUID+556, @CGUID+542, 5, 45, 515, 0, 3),
(@CGUID+556, @CGUID+545, 5, 315, 515, 0, 3);

-- Commerce Enforcer #3
SET @ENTRY := 179842;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Tazavesh - Commerce Enforcer #2 - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3609.813, -1183.752, 73.91402, NULL, 0),
(@PATH, 1, 3616.038, -1172.441, 73.91499, NULL, 4787),
(@PATH, 2, 3609.813, -1183.752, 73.91402, NULL, 0),
(@PATH, 3, 3599.263, -1192.354, 73.87805, NULL, 0),
(@PATH, 4, 3585.377, -1200.097, 73.87805, NULL, 6126),
(@PATH, 5, 3599.263, -1192.354, 73.87805, NULL, 0);

UPDATE `creature` SET `position_x`= 3609.813, `position_y`= -1183.752, `position_z`= 73.91402, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+554;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+554;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+554, @PATH, 1);

DELETE FROM `creature_formations` WHERE `leaderGUID`=@CGUID+554;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+554, @CGUID+554, 0, 0, 515, 0, 0),
(@CGUID+554, @CGUID+546, 5, 45, 515, 0, 3),
(@CGUID+554, @CGUID+541, 5, 315, 515, 0, 3);
