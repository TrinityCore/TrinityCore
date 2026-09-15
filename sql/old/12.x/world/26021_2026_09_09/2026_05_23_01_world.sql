-- Update creature spawns to createobject2 positions

-- Coyote
UPDATE `creature` SET `position_x`=-10112.2919921875, `position_y`=1257.9410400390625, `position_z`=38.7079925537109375, `orientation`=5.972020626068115234 WHERE `guid` = 275667;
UPDATE `creature` SET `position_x`=-10284.5400390625, `position_y`=1150.21875, `position_z`=38.8421630859375, `orientation`=0.415150463581085205 WHERE `guid` = 275481;
UPDATE `creature` SET `position_x`=-10217.171875, `position_y`=1216.953125, `position_z`=43.1945953369140625, `orientation`=3.949086666107177734 WHERE `guid` = 275518;
UPDATE `creature` SET `position_x`=-9884.3369140625, `position_y`=852.013916015625, `position_z`=31.84584999084472656, `orientation`=5.217483997344970703 WHERE `guid` = 275797;
UPDATE `creature` SET `position_x`=-9950.0712890625, `position_y`=849.67706298828125, `position_z`=31.97866630554199218, `orientation`=4.304910659790039062 WHERE `guid` = 275792;
UPDATE `creature` SET `position_x`=-10051.0087890625, `position_y`=949.27081298828125, `position_z`=36.65061187744140625, `orientation`=5.31670379638671875 WHERE `guid` = 275688;
UPDATE `creature` SET `position_x`=-10084.7587890625, `position_y`=850.66143798828125, `position_z`=33.3445892333984375, `orientation`=5.123446464538574218 WHERE `guid` = 275624;
UPDATE `creature` SET `position_x`=-10020.9892578125, `position_y`=850.5399169921875, `position_z`=33.247344970703125, `orientation`=1.827679157257080078 WHERE `guid` = 275689;
UPDATE `creature` SET `position_x`=-10121.03515625, `position_y`=956.42364501953125, `position_z`=36.19438552856445312, `orientation`=5.954511642456054687 WHERE `guid` = 275620;
UPDATE `creature` SET `position_x`=-10185.5244140625, `position_y`=884.73956298828125, `position_z`=40.25575637817382812, `orientation`=5.553556442260742187 WHERE `guid` = 275537;
UPDATE `creature` SET `position_x`=-10150.2431640625, `position_y`=849.125, `position_z`=25.1642303466796875, `orientation`=4.190216541290283203 WHERE `guid` = 275535;
UPDATE `creature` SET `position_x`=-10297.1826171875, `position_y`=924.34375, `position_z`=38.05178451538085937, `orientation`=0.939201772212982177 WHERE `guid` = 275531;
UPDATE `creature` SET `position_x`=-10251.4892578125, `position_y`=820.49652099609375, `position_z`=50.11504745483398437, `orientation`=2.384792804718017578 WHERE `guid` = 275529;

UPDATE `creature` SET `wander_distance` = 8, `MovementType` = 1 WHERE `guid` IN (275667,275481,275518,275797,275792,275688,275624,275689,275620,275537,275535,275531,275529);

-- Young Goretusk
UPDATE `creature` SET `position_x`=-9917.078125, `position_y`=849.0694580078125, `position_z`=32.4301605224609375, `orientation`=0.236416608095169067 WHERE `guid` = 275798;
UPDATE `creature` SET `position_x`=-9981.4501953125, `position_y`=812.88232421875, `position_z`=33.01144790649414062, `orientation`=4.4719085693359375 WHERE `guid` = 275692;
UPDATE `creature` SET `position_x`=-10050.6142578125, `position_y`=885.8125, `position_z`=34.56714630126953125, `orientation`=2.421432018280029296 WHERE `guid` = 275630;
UPDATE `creature` SET `position_x`=-10083.69140625, `position_y`=918.2882080078125, `position_z`=36.40305709838867187, `orientation`=0.719702780246734619 WHERE `guid` = 275629;
UPDATE `creature` SET `position_x`=-10151.271484375, `position_y`=944.1805419921875, `position_z`=37.7889251708984375, `orientation`=0.711530804634094238 WHERE `guid` = 275619;
UPDATE `creature` SET `position_x`=-10171.626953125, `position_y`=868.97918701171875, `position_z`=35.7053375244140625, `orientation`=1.437640070915222167 WHERE `guid` = 275534;
UPDATE `creature` SET `position_x`=-10221.6357421875, `position_y`=938.63714599609375, `position_z`=42.136260986328125, `orientation`=0.531850874423980712 WHERE `guid` = 275527;
UPDATE `creature` SET `position_x`=-10250.6005859375, `position_y`=881.25347900390625, `position_z`=37.28864669799804687, `orientation`=0.815001606941223144 WHERE `guid` = 275530;

UPDATE `creature` SET `wander_distance` = 6, `MovementType` = 1 WHERE `guid` IN (275798,275692,275630,275629,275619,275534,275527,275530);

-- Goretusk
UPDATE `creature` SET `position_x`=-10156.716796875, `position_y`=1228.4010009765625, `position_z`=35.82923126220703125, `orientation`=4.195333480834960937 WHERE `guid` = 275606;
UPDATE `creature` SET `position_x`=-10089.7587890625, `position_y`=1191.13720703125, `position_z`=37.23752212524414062, `orientation`=2.990307807922363281 WHERE `guid` = 275669;
UPDATE `creature` SET `position_x`=-10125.326171875, `position_y`=1218.35595703125, `position_z`=34.92719268798828125, `orientation`=3.635154008865356445 WHERE `guid` = 275609;
UPDATE `creature` SET `position_x`=-10195.9736328125, `position_y`=1210.7447509765625, `position_z`=38.43616867065429687, `orientation`=4.825494766235351562 WHERE `guid` = 275545;
UPDATE `creature` SET `position_x`=-10223.0419921875, `position_y`=1207.02783203125, `position_z`=42.30506515502929687, `orientation`=0 WHERE `guid` = 275519;
UPDATE `creature` SET `position_x`=-10182.55078125, `position_y`=1185.6197509765625, `position_z`=36.96110153198242187, `orientation`=0 WHERE `guid` = 275549;
UPDATE `creature` SET `position_x`=-10248.2373046875, `position_y`=1249.681396484375, `position_z`=38.31702804565429687, `orientation`=3.49864816665649414 WHERE `guid` = 275478;
UPDATE `creature` SET `position_x`=-10202.4619140625, `position_y`=1152.1458740234375, `position_z`=36.00730514526367187, `orientation`=0 WHERE `guid` = 275522;
UPDATE `creature` SET `position_x`=-10317.41796875, `position_y`=1183.10888671875, `position_z`=39.922393798828125, `orientation`=0.944585442543029785 WHERE `guid` = 275420;
UPDATE `creature` SET `position_x`=-10218.3486328125, `position_y`=1172.157958984375, `position_z`=36.1107330322265625, `orientation`=0 WHERE `guid` = 275521;
UPDATE `creature` SET `position_x`=-10184.810546875, `position_y`=1231.8629150390625, `position_z`=35.80158233642578125, `orientation`=0 WHERE `guid` = 275544;
UPDATE `creature` SET `position_x`=-10389.1162109375, `position_y`=1115.91845703125, `position_z`=34.17665863037109375, `orientation`=3.015480756759643554 WHERE `guid` = 275319;
UPDATE `creature` SET `position_x`=-10448.8017578125, `position_y`=1185.578125, `position_z`=38.65456008911132812, `orientation`=4.223866462707519531 WHERE `guid` = 275279;
UPDATE `creature` SET `position_x`=-10351.423828125, `position_y`=1147.935791015625, `position_z`=36.42644882202148437, `orientation`=5.291047096252441406 WHERE `guid` = 275320;
UPDATE `creature` SET `position_x`=-10383.974609375, `position_y`=1188.2945556640625, `position_z`=41.59771728515625, `orientation`=5.8113250732421875 WHERE `guid` = 275318;
UPDATE `creature` SET `position_x`=-10315.1611328125, `position_y`=1052.6754150390625, `position_z`=41.00365829467773437, `orientation`=0.825018167495727539 WHERE `guid` = 275418;

UPDATE `creature` SET `wander_distance` = 8, `MovementType` = 1 WHERE `guid` IN (275606,275669,275609,275545,275519,275549,275478,275522,275420,275521,275544,275319,275279,275320,275318,275418);

-- Young Fleshripper
UPDATE `creature` SET `position_x`= -10119.6337890625, `position_y`=1316.984375, `position_z`=39.73633193969726562, `orientation`=0.693411588668823242 WHERE `guid` = 275671;
UPDATE `creature` SET `position_x`=-10071.8037109375, `position_y`=1171.4114990234375, `position_z`=38.68895721435546875, `orientation`=2.600074052810668945 WHERE `guid` = 275660;
UPDATE `creature` SET `position_x`=-10252.361328125, `position_y`=1184.0538330078125, `position_z`=34.03143310546875, `orientation`=2.307207822799682617 WHERE `guid` = 275480;
UPDATE `creature` SET `position_x`=-10049.6630859375, `position_y`=883.65802001953125, `position_z`=34.52642822265625, `orientation`=4.17992401123046875 WHERE `guid` = 275690;
UPDATE `creature` SET `position_x`=-10051.4033203125, `position_y`=824.24481201171875, `position_z`=33.06116867065429687, `orientation`=5.475196361541748046 WHERE `guid` = 275625;
UPDATE `creature` SET `position_x`=-10118.5859375, `position_y`=883.97845458984375, `position_z`=32.17874908447265625, `orientation`=3.457170724868774414 WHERE `guid` = 275623;
UPDATE `creature` SET `position_x`=-9982.6044921875, `position_y`=914.7257080078125, `position_z`=36.70961761474609375, `orientation`=0.345296263694763183 WHERE `guid` = 275696;
UPDATE `creature` SET `position_x`=-10209.6923828125, `position_y`=837.00518798828125, `position_z`=36.19669342041015625, `orientation`=2.07704019546508789 WHERE `guid` = 275533;
UPDATE `creature` SET `position_x`=-10182.125, `position_y`=917.8819580078125, `position_z`=38.52907562255859375, `orientation`=4.004416465759277343 WHERE `guid` = 275538;

UPDATE `creature` SET `wander_distance` = 12, `MovementType` = 1 WHERE `guid` IN (275671,275660,275480,275690,275625,275623,275696,275533,275538);
