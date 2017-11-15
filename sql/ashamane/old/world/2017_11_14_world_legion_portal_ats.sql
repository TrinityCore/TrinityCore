SET @ATGUID:=3;

-- LEGION PORTALS TO INSTANCES AND OTHER
DELETE FROM `areatrigger` WHERE `guid` BETWEEN @ATGUID AND @ATGUID+37;
DELETE FROM `areatrigger_template` WHERE `Id` BETWEEN 100001 AND 100010;

INSERT INTO areatrigger_template (`Id`, `Type`, `Data0`, `Data1`) VALUES
(100001, 0, 1, 1),
(100002, 0, 2, 2),
(100003, 0, 3, 3),
(100004, 0, 4, 4),
(100005, 0, 5, 5),
(100006, 0, 6, 6),
(100007, 0, 7, 7),
(100008, 0, 8, 8),
(100009, 0, 9, 9),
(100010, 0, 10, 10);

INSERT INTO `areatrigger` (`guid`, `id`, `map_id`, `spawn_Mask`, `position_x`, `position_y`, `position_z`, `ScriptName`) VALUES

-- VIOLET HOLD ENTRANCE/EXIT
(@ATGUID+0,  100005, 1220, 1,         -972.17,        4310.75,        743.26,         'at_legion_portal_aovh_entrance'),
(@ATGUID+1,  100007, 1544, 8388614,   4541.12,        4015.09,        88.771,         'at_legion_portal_aovh_exit'    ),

-- BLACK ROOK HOLD ENTRANCE/EXIT
(@ATGUID+2,  100005, 1220, 1,         3124.312012,    7564.084473,    35.469097,      'at_legion_portal_brh_entrance'),
(@ATGUID+3,  100005, 1501, 8388614,   3508.144531,    7650.483887,    -2.429438,      'at_legion_portal_brh_exit'    ),

-- CATHEDRAL OF ETERNAL NIGHT ENTRANCE/EXIT
(@ATGUID+4,  100005, 1220, 1,         -422.000000,    2432.389893,    106.294998,     'at_legion_portal_coen_entrance'),
(@ATGUID+5,  100005, 1677, 8388614,   -713.953064,    2528.846436,    334.286469,     'at_legion_portal_coen_exit'    ),

-- COURT OF STARS ENTRANCE/EXIT
(@ATGUID+6,  100005, 1220, 1,         1017.365662,    3826.377197,    8.489392,       'at_legion_portal_cos_entrance'),
(@ATGUID+7,  100005, 1571, 8388614,   1018.085876,    3830.683838,    8.489278,       'at_legion_portal_cos_exit'    ),

-- DARKHEART THINKET ENTRANCE/EXIT
(@ATGUID+8,  100005, 1220, 1,         3822.110840,    6356.569824,    191.034180,     'at_legion_portal_dht_entrance'),
(@ATGUID+9,  100005, 1466, 8388614,   3264.801514,    1831.000122,    244.668106,     'at_legion_portal_dht_exit'    ),

-- EYE OF AZSHARA ENTRANCE/EXIT
(@ATGUID+10, 100005, 1220, 1,         0.308132,       5810.671875,    5.718644,       'at_legion_portal_eoa_entrance'),
(@ATGUID+11, 100005, 1456, 8388614,   -3927.827637,   4550.475098,    93.389465,      'at_legion_portal_eoa_exit'    ),

-- HALLS OF VALOR ENTRANCE/EXIT
(@ATGUID+12, 100005, 1220, 1,         2452.870850,    813.793213,     256.461426,     'at_legion_portal_hov_entrance'),
(@ATGUID+13, 100005, 1477, 8388614,   3817.088623,    528.909424,     606.808594,     'at_legion_portal_hov_exit'    ),

-- MAW OF SOULS ENTRANCE/EXIT
(@ATGUID+14, 100005, 1220, 1,         3434.173096,    1985.098511,    22.777937,      'at_legion_portal_mos_entrance'),
(@ATGUID+15, 100008, 1492, 8388614,   7156.934570,    7317.655762,    25.009018,      'at_legion_portal_mos_exit'    ),

-- NELTARIONS LAIR ENTRANCE/EXIT
(@ATGUID+16, 100008, 1220, 1,         3720.915283,    4184.942383,    892.521851,     'at_legion_portal_nl_entrance'),
(@ATGUID+17, 100005, 1458, 8388614,   2986.282227,    982.742188,     381.305847,     'at_legion_portal_nl_exit'    ),

-- RETURN TO KARAZHAN ENTRANCE/EXIT
(@ATGUID+18, 100003, 1220, 1,         -11040.081055,  -1997.181396,   93.008797,      'at_legion_portal_rtkara_entrance'),
(@ATGUID+19, 100003, 1651, 8388614,   -11074.439453,  -1988.621582,   95.489433,      'at_legion_portal_rtkara_exit'    ),

-- THE ARCWAY ENTRANCE/EXIT
(@ATGUID+20, 100003, 1220, 1,         1155.360718,    4380.972656,    14.957661,      'at_legion_portal_taw_entrance'),
(@ATGUID+21, 100005, 1516, 8388614,   3534.636719,    4806.047363,    596.356812,     'at_legion_portal_taw_exit'    ),

-- VAULT OF THE WARDENS ENTRANCE/EXIT
(@ATGUID+22, 100007, 1220, 1,         -1712.615234,   6648.819824,    128.964203,     'at_legion_portal_votw_entrance'),
(@ATGUID+23, 100004, 1493, 8388614,   4184.080078,    -748.447998,    269.875000,     'at_legion_portal_votw_exit'    ),

-- THE EMERALD NIGHTMARE ENTRANCE/EXIT
(@ATGUID+24, 100007, 1220, 1,         3598.168945,    6476.521973,    177.894821,     'at_legion_portal_en_entrance'),
(@ATGUID+25, 100010, 1520, 65536,     1786.604736,    1421.964111,    350.734680,     'at_legion_portal_en_exit'    ),

-- TRIAL OF VALOR ENTRANCE/EXIT
(@ATGUID+26, 100007, 1220, 1,         2356.122070,    910.199890,     257.336945,     'at_legion_portal_tov_entrance'),
(@ATGUID+27, 100005, 1648, 65536,     3251.981934,    529.118286,     640.022156,     'at_legion_portal_tov_exit'    ),

-- THE NIGHTHOLD ENTRANCE/EXIT
(@ATGUID+28, 100003, 1220, 1,         -1237.211548,   4205.216309,    -65.371849,     'at_legion_portal_tnh_entrance'),
(@ATGUID+29, 100005, 1530, 114688,    -67.611099,     3421.669922,    -255.214005,    'at_legion_portal_tnh_exit'    ),
(@ATGUID+30, 100005, 1530, 114688,    573.605774,     3427.122070,    113.808365,     'at_legion_portal_tnh_maindoors_exit'),

-- TOMB OF SARGERAS ENTRANCE/EXIT
(@ATGUID+31, 100010, 1220, 1,         -536.850830,    2430.068604,    116.415855,     'at_legion_portal_tos_entrance'),
(@ATGUID+32, 100007, 1676, 114688,    5828.209473,    -795.752747,    2958.380859,    'at_legion_portal_tos_exit'    ),

-- DALARAN KHADGAR CHAMBER ENTRANCE/EXIT
(@ATGUID+33, 100001, 1220, 1,         -844.586487,    4467.742188,    736.295227,     'at_legion_portal_dal_chamber_entrance'),
(@ATGUID+34, 100001, 1220, 1,         -779.869629,    4415.298828,    602.882080,     'at_legion_portal_dal_chamber_exit'    ),

-- STORMHEIM HELHEIM ENTRANCE/EXIT
(@ATGUID+35, 100005, 1220, 1,         3657.082275,    757.409546,     -5.635623,      'at_legion_portal_helheim_entrance'),
(@ATGUID+36, 100005, 1463, 1,         333.129456,     339.456757,     35.150623,      'at_legion_portal_helheim_exit'    ),

-- WARLOCK EXIT FROM ORDER HALL
(@ATGUID+37, 100005, 1522, 1,         3084.902344,    820.363098,     247.220001,     'at_legion_portal_warl_oh_exit'    );
