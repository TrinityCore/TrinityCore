-- Half-Buried Bottles
SET @OID=2560;
SET @OGUID=73440; -- 38 free guid required
SET @POOL=595; -- 2 free id required
DELETE FROM `pool_template` WHERE `entry` IN (@POOL, @POOL+1);
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL, 6, "Half-Buried Bottle Wild Shore"),
(@POOL+1, 3, "Half-Buried Bottle Jaguero Isle");

DELETE FROM `pool_members` WHERE `type`=1 AND `poolSpawnId` IN (@POOL, @POOL+1);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
-- We don't add underground spawns to the pool
-- (1, @OGUID, @POOL, 0, "Half-Buried Bottle Wild Shore"),
(1, @OGUID+1, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+2, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
-- (1, @OGUID+3, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+4, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+5, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+6, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+7, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+8, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+9, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+10, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+11, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+12, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+13, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+14, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+15, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+16, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+17, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+18, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+19, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+20, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+21, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+22, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+23, @POOL, 0, "Half-Buried Bottle - Wild Shore"),
(1, @OGUID+24, @POOL, 0, "Half-Buried Bottle - Wild Shore"),

(1, @OGUID+25, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+26, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+27, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+28, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+29, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+30, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+31, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+32, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+33, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+34, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
-- (1, @OGUID+35, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+36, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle"),
(1, @OGUID+37, @POOL+1, 0, "Half-Buried Bottle - Jaguero Isle");

DELETE FROM `gameobject_addon` WHERE `guid` IN (SELECT `guid` FROM `gameobject` WHERE `id`=@OID);
DELETE FROM `gameobject` WHERE `id`=@OID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@OGUID, @OID, 0, 0, 0, 1, 1, -13734.783203125, -255.342697143554687, 0.004720000084489583, 0.523597896099090576, 0, 0, 0.258818626403808593, 0.965925931930541992, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+1, @OID, 0, 0, 0, 1, 1, -13722.708984375, -295.261688232421875, 0.379433989524841308, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+2, @OID, 0, 0, 0, 1, 1, -13870.6669921875, -211.541671752929687, -1.20754802227020263, 3.996806621551513671, 0, 0, -0.90996074676513671, 0.414694398641586303, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+3, @OID, 0, 0, 0, 1, 1, -13912.5556640625, -166.436141967773437, 0.534211993217468261, 5.986480236053466796, 0, 0, -0.14780902862548828, 0.989015936851501464, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+4, @OID, 0, 0, 0, 1, 1, -14096.0693359375, -142.105911254882812, 2.257411003112792968, 1.48352813720703125, 0, 0, 0.675589561462402343, 0.737277925014495849, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+5, @OID, 0, 0, 0, 1, 1, -14193.1533203125, -78.2309036254882812, 0.308180987834930419, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+6, @OID, 0, 0, 0, 1, 1, -14307.3056640625, 32.82291793823242187, 0.141596004366874694, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+7, @OID, 0, 0, 0, 1, 1, -14400.1552734375, 58.31494140625, 0.486712008714675903, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+8, @OID, 0, 0, 0, 1, 1, -14473.447265625, 64.72260284423828125, -0.96794402599334716, 5.585053920745849609, 0, 0, -0.34202003479003906, 0.939692676067352294, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+9, @OID, 0, 0, 0, 1, 1, -14048.232421875, -144.146926879882812, -0.19740000367164611, 5.35816192626953125, 0, 0, -0.446197509765625, 0.894934535026550292, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+10, @OID, 0, 0, 0, 1, 1, -14279.017578125, 56.4061431884765625, 0.707728028297424316, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+11, @OID, 0, 0, 0, 1, 1, -14331.06640625, 60.69097137451171875, 0.171187996864318847, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+12, @OID, 0, 0, 0, 1, 1, -14483.568359375, 104.4371719360351562, 1.572831034660339355, 6.108653545379638671, 0, 0, -0.08715534210205078, 0.996194720268249511, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+13, @OID, 0, 0, 0, 1, 1, -14456.267578125, 37.46300125122070312, 0.395052999258041381, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+14, @OID, 0, 0, 0, 1, 1, -14274.146484375, 12.35845279693603515, 0.687386989593505859, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+15, @OID, 0, 0, 0, 1, 1, -14170.59765625, -93.0607681274414062, -0.45957198739051818, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+16, @OID, 0, 0, 0, 1, 1, -13704.9306640625, -327.592010498046875, -0.07900399714708328, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+17, @OID, 0, 0, 0, 1, 1, -14434.8505859375, 54.3836822509765625, 0.178829997777938842, 4.537858963012695312, 0, 0, -0.76604366302490234, 0.642788589000701904, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+18, @OID, 0, 0, 0, 1, 1, -14516.8740234375, 126.1961517333984375, 0.021186999976634979, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+19, @OID, 0, 0, 0, 1, 1, -13729.6220703125, -342.87152099609375, 0.453314989805221557, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+20, @OID, 0, 0, 0, 1, 1, -14217.486328125, -54.140625, 0.399392008781433105, 3.211419343948364257, 0, 0, -0.9993906021118164, 0.034906134009361267, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+21, @OID, 0, 0, 0, 1, 1, -13747.55859375, -353.41943359375, 0.344130992889404296, 5.183629035949707031, 0, 0, -0.52249813079833984, 0.852640450000762939, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+22, @OID, 0, 0, 0, 1, 1, -14358.390625, 66.97043609619140625, 0.586006999015808105, 1.989672422409057617, 0, 0, 0.838669776916503906, 0.544640243053436279, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+23, @OID, 0, 0, 0, 1, 1, -14270.0634765625, -17.1996536254882812, 0.675433993339538574, 2.181660413742065429, 0, 0, 0.887010574340820312, 0.461749136447906494, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1
(@OGUID+24, @OID, 0, 0, 0, 1, 1, -14078.486328125, -152.603958129882812, 0.542116999626159667, 3.769911527633666992, 0, 0, -0.95105648040771484, 0.309017121791839599, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Wild Shore- - Difficulty: 0) CreateObject1

(@OGUID+25, @OID, 0, 0, 0, 1, 1, -14532.646484375, -100.203132629394531, -0.20425699651241302, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+26, @OID, 0, 0, 0, 1, 1, -14448.06640625, -112.28125, -1.23729205131530761, 4.97418975830078125, 0, 0, -0.60876083374023437, 0.793353796005249023, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+27, @OID, 0, 0, 0, 1, 1, -14439.646484375, -190.588546752929687, -0.70320802927017211, 4.136432647705078125, 0, 0, -0.87881660461425781, 0.477159708738327026, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+28, @OID, 0, 0, 0, 1, 1, -14418.638671875, -323.416656494140625, -0.06788700073957443, 1.762782454490661621, 0, 0, 0.771624565124511718, 0.636078238487243652, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+29, @OID, 0, 0, 0, 1, 1, -14427.072265625, -422.2598876953125, 1.238023996353149414, 1.221729278564453125, 0, 0, 0.573575973510742187, 0.819152355194091796, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+30, @OID, 0, 0, 0, 1, 1, -14554.96875, -86.4878463745117187, 0.37993699312210083, 2.251473426818847656, 0, 0, 0.902585029602050781, 0.430511653423309326, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+31, @OID, 0, 0, 0, 1, 1, -14449.521484375, -169.776046752929687, 0.403385013341903686, 2.844882726669311523, 0, 0, 0.989015579223632812, 0.147811368107795715, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+32, @OID, 0, 0, 0, 1, 1, -14419.326171875, -385.6475830078125, 1.123703956604003906, 5.270895957946777343, 0, 0, -0.48480892181396484, 0.87462007999420166, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+33, @OID, 0, 0, 0, 1, 1, -14459.576171875, -437.711822509765625, 0.913416028022766113, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+34, @OID, 0, 0, 0, 1, 1, -14616.53515625, -88.2083358764648437, 0.587144970893859863, 4.468043327331542968, 0, 0, -0.7880105972290039, 0.615661680698394775, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+35, @OID, 0, 0, 0, 1, 1, -14592.0849609375, -83.6837539672851562, 0.382618993520736694, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+36, @OID, 0, 0, 0, 1, 1, -14503.5595703125, -316.2413330078125, 0.920786976814270019, 5.602506637573242187, 0, 0, -0.33380699157714843, 0.942641437053680419, 120, 255, 1, '', NULL, 60141), -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject1
(@OGUID+37, @OID, 0, 0, 0, 1, 1, -14462.361328125, -314.703125, 1.220939040184020996, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 120, 255, 1, '', NULL, 60141); -- Half-Buried Bottle (Area: -Jaguero Isle- - Difficulty: 0) CreateObject2
