-- All emotes, mostly ONESHOT_TALK
DELETE FROM `creature_addon` WHERE `guid` IN (49115,49114,49742,49741,49754,49120,49121,49122,49738,49105,49104,49737,91479,91478,91511,91512,91465,91464,49702,49701,91477,91476,91495,91496,49703,49704,91491,91490,91442,91443,49753,49314,49313,49310,49784,49785,49778,49779,49780,51459,51456,51457,51966,51965,49273,49272,49786,49787,49280,49281,49279,49799,49798,49797,49796,49795,49793,49794);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(49115,0,0,0,0,1,''),(49114,0,0,0,0,1,''),(49742,0,0,0,0,1,''),(49741,0,0,0,0,1,''),(49754,0,0,0,0,1,''),(49120,0,0,0,0,1,''),
(49121,0,0,0,0,1,''),(49122,0,0,0,0,1,''),(49738,0,0,0,0,1,''),(49105,0,0,0,0,1,''),(49104,0,0,0,0,1,''),(49737,0,0,0,0,1,''),
(91479,0,0,0,0,1,''),(91478,0,0,0,0,1,''),(91511,0,0,0,0,1,''),(91512,0,0,0,0,1,''),(91465,0,0,0,0,1,''),(91464,0,0,0,0,1,''),
(91496,0,0,0,0,1,''),(91495,0,0,0,0,1,''),(91476,0,0,0,0,1,''),(91477,0,0,0,0,1,''),(49701,0,0,0,0,1,''),(49702,0,0,0,0,1,''),
(49703,0,0,0,0,1,''),(49704,0,0,0,0,1,''),(91491,0,0,0,0,1,''),(91490,0,0,0,0,1,''),(91442,0,0,0,0,1,''),(91443,0,0,0,0,1,''),
(49784,0,0,0,0,1,''),(49785,0,0,0,0,1,''),(49778,0,0,0,0,1,''),(49779,0,0,0,0,1,''),(49780,0,0,0,0,1,''),(51459,0,0,0,0,1,''),
(51456,0,0,0,0,1,''),(51457,0,0,0,0,1,''),(51966,0,0,0,0,1,''),(51965,0,0,0,0,1,''),(49273,0,0,0,0,1,''),(49272,0,0,0,0,1,''),
(49786,0,0,0,0,1,''),(49787,0,0,0,0,1,''),(49280,0,0,0,0,1,''),(49281,0,0,0,0,1,''),(49279,0,0,0,0,1,''),(49799,0,0,0,0,1,''),
(49798,0,0,0,0,1,''),(49797,0,0,0,0,1,''),(49753,0,0,0,0,1,''),(49314,0,0,8,0,0,''),(49313,0,0,8,0,0,''),(49310,0,0,0,0,1,''),
(49794,0,0,0,0,333,''),(49796,0,0,0,0,333,''),(49795,0,0,0,0,333,''),(49793,0,0,0,0,333,'');

-- Set correct positions
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11960.496094,`position_y`=-1558.178711,`position_z`=41.212128,`orientation`=2.233450 WHERE `guid`=49097; -- Razzashi Serpent
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11971.704102,`position_y`=-1549.167236,`position_z`=41.434246,`orientation`=5.631021 WHERE `guid`=49096; -- Razzashi Adder
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-12010.169922,`position_y`=-1485.053101,`position_z`=79.251274,`orientation`=5.129887 WHERE `guid`=49121; -- Gurubashi Headhunter
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-12006.965820,`position_y`=-1484.825195,`position_z`=79.190865,`orientation`=4.628802 WHERE `guid`=49122; -- Hakkari Witch Doctor
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11981.070313,`position_y`=-1475.364746,`position_z`=79.736366,`orientation`=0.874606 WHERE `guid`=49193; -- Gurubashi Bat Rider
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11988.361328,`position_y`=-1621.758301,`position_z`=33.236633,`orientation`=2.167352 WHERE `guid`=49104; -- Gurubashi Axe Thrower
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-12054.768555,`position_y`=-1685.999512,`position_z`=43.074993,`orientation`=1.606618 WHERE `guid`=49752; -- Hakkari Priest
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11929.511719,`position_y`=-1844.217651,`position_z`=57.701702,`orientation`=0.172101 WHERE `guid`=49056; -- Mad Servant
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11596.799805,`position_y`=-1757.020020,`position_z`=39.871101,`orientation`=5.515240 WHERE `guid`=91464; -- Gurubashi Axe Thrower
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`position_x`=-11649.000000,`position_y`=-1568.680054,`position_z`=39.392300,`orientation`=4.206240 WHERE `guid`=91476; -- Gurubashi Axe Thrower
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`orientation`=0.382538 WHERE `guid` IN (51396,51395); -- Gurubashi Berserker
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`orientation`=1.396260 WHERE `guid`=49120; -- Gurubashi Headhunter
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`orientation`=5.497790 WHERE `guid`=49105; -- Gurubashi Axe Thrower
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`orientation`=3.388120 WHERE `guid`=49059; -- Mad Servant
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`orientation`=0.000000 WHERE `guid`=49060; -- Mad Servant
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`orientation`=2.460910 WHERE `guid`=49285; -- Razzashi Raptor
UPDATE `creature` SET `MovementType`=0,`spawndist`=0,`orientation`=5.284594 WHERE `guid`=51576; -- Razzashi Raptor
UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `guid` IN (51382,51375,51381,51383,51372,51370,51369,49359,49361,49362,49218,49219,49234,49235,49259,49260,91463,91462,91461,91459,91460,91439,49140,49139);

-- Double spawned creatures. Removing addon data to prevent errors
DELETE FROM `creature` WHERE `guid`=49806 AND `id`=11360; 
DELETE FROM `creature_addon` WHERE `guid`=49806;
DELETE FROM `creature` WHERE `guid`=49056 AND `id`=15111;
DELETE FROM `creature_addon` WHERE `guid` IN (15111,49056);
DELETE FROM `creature` WHERE `guid` IN (49221,49220) AND `id` IN (14880);
DELETE FROM `creature_addon` WHERE `guid` IN (49221,49220);
DELETE FROM `creature` WHERE `guid` IN (49142,49141,49149) AND `id` IN (14750);
DELETE FROM `creature_addon` WHERE `guid` IN (49142,49141,49149);
DELETE FROM `creature` WHERE `guid` IN (49138,49137) AND `id` IN (11368);
DELETE FROM `creature_addon` WHERE `guid` IN (49138,49137);

-- Missing spawns
-- Hakkari Priest
DELETE FROM `creature` WHERE `guid`=200616 AND `id`=11830;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES 
(200616,11830,309,1,1,11758,0,-11942.391602,-1640.220825,42.506130,2.932328,7200,0,0,17094,12170,0,0,0,0);
-- Razzashi Adder
DELETE FROM `creature` WHERE `guid` IN (200617,200618) AND `id` IN (11372);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(200617,11372,309,1,1,15150,0,-11997.982422,-1650.174438,34.328613,1.432994,7200,0,0,15260,0,2,0,0,0),
(200618,11372,309,1,1,15150,0,-11986.670898,-1651.959961,33.775238,1.432994,7200,0,0,15260,0,2,0,0,0);
-- Gurubashi Blood Drinker (this guid was used by a double-spawned NPC)
DELETE FROM `creature` WHERE `guid` IN (200619,200620) AND `id` IN (11353);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(200619,11353,309,1,1,11080,0,-11609.610352,-1631.155518,39.957348,3.214375,7200,0,0,18312,0,0,0,0,0),
(200620,11353,309,1,1,11081,0,-11608.893555,-1609.535156,40.082027,2.992088,7200,0,0,18312,0,0,0,0,0);

-- Zulian Panther pathing: 11365
SET @GUID := 49320;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-11626.807617,`position_y`=-1701.435425,`position_z`=38.823635 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-11626.807617,-1701.435425,38.823635,0,1,0,100,0),
(@PATH,2,-11627.707031,-1727.870483,40.333164,0,1,0,100,0),
(@PATH,3,-11629.434570,-1760.955322,38.754513,0,1,0,100,0),
(@PATH,4,-11653.967773,-1807.740723,43.086334,0,1,0,100,0),
(@PATH,5,-11629.434570,-1760.955322,38.754513,0,1,0,100,0),
(@PATH,6,-11627.707031,-1727.870483,40.333164,0,1,0,100,0),
(@PATH,7,-11630.115234,-1687.330566,39.997681,0,1,0,100,0),
(@PATH,8,-11634.075195,-1596.245239,39.645630,0,0,0,100,0);

-- Make the two other panthers follow 49320 (leader)
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49320,49319,49318);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49320;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49320,49320,0,0,2),
(49320,49319,3,225,2),
(49320,49318,3,90,2);

-- Hakkari Priest pathing: 11830
SET @GUID := 49752; -- Hakkari Priest leads
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12054.799805,`position_y`=-1686.000000,`position_z`=43.075001 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12059.555664,-1691.853027,43.423206,0,0,0,100,0),
(@PATH,2,-12059.799805,-1701.031494,44.344296,0,0,0,100,0),
(@PATH,3,-12053.253906,-1720.945435,48.184185,0,0,0,100,0),
(@PATH,4,-12043.537109,-1733.467651,51.260815,0,0,0,100,0),
(@PATH,5,-12034.110352,-1742.581421,53.809147,0,0,0,100,0),
(@PATH,6,-12043.537109,-1733.467651,51.260815,0,0,0,100,0),
(@PATH,7,-12053.253906,-1720.945435,48.184185,0,0,0,100,0),
(@PATH,8,-12059.799805,-1701.031494,44.344296,0,0,0,100,0),
(@PATH,9,-12059.555664,-1691.853027,43.423206,0,0,0,100,0),
(@PATH,10,-12058.425781,-1681.930420,42.665642,0,0,0,100,0),
(@PATH,11,-12042.879883,-1650.618164,40.627056,0,0,0,100,0),
(@PATH,12,-12034.342773,-1643.789551,39.795006,0,0,0,100,0),
(@PATH,13,-12009.803711,-1642.433350,35.999470,0,0,0,100,0),
(@PATH,14,-11992.014648,-1646.609253,34.173782,0,0,0,100,0),
(@PATH,15,-11962.285156,-1644.002441,36.924133,0,0,0,100,0),
(@PATH,16,-11951.910156,-1638.948730,38.838421,0,0,0,100,0),
(@PATH,17,-11949.411133,-1628.985229,39.359371,0,0,0,100,0),
(@PATH,18,-11946.486328,-1619.823486,41.083221,0,0,0,100,0),
(@PATH,19,-11947.083984,-1614.833984,39.48743,0,0,0,100,0),
(@PATH,20,-11943.375000,-1576.649292,38.514889,0,0,0,100,0),
(@PATH,21,-11942.552734,-1568.465454,41.119324,0,0,0,100,0),
(@PATH,23,-11941.658203,-1559.485596,39.735973,0,0,0,100,0),
(@PATH,24,-11938.247070,-1554.563354,39.750710,0,0,0,100,0),
(@PATH,25,-11918.897461,-1550.056152,38.295830,0,0,0,100,0),
(@PATH,26,-11903.013672,-1537.574463,31.093979,0,0,0,100,0),
(@PATH,27,-11900.709961,-1530.430054,28.203531,10000,0,0,100,0),
(@PATH,28,-11903.013672,-1537.574463,31.093979,0,0,0,100,0),
(@PATH,29,-11918.897461,-1550.056152,38.295830,0,0,0,100,0),
(@PATH,30,-11938.247070,-1554.563354,39.750710,0,0,0,100,0),
(@PATH,31,-11941.658203,-1559.485596,39.735973,0,0,0,100,0),
(@PATH,32,-11943.507813,-1569.661377,40.848972,0,0,0,100,0),
(@PATH,33,-11943.375000,-1576.649292,38.514889,0,0,0,100,0),
(@PATH,34,-11947.083984,-1614.833984,39.48743,0,0,0,100,0),
(@PATH,36,-11946.486328,-1619.823486,41.083221,0,0,0,100,0),
(@PATH,37,-11949.411133,-1628.985229,39.359371,0,0,0,100,0),
(@PATH,38,-11951.910156,-1638.948730,38.838421,0,0,0,100,0),
(@PATH,39,-11962.285156,-1644.002441,36.924133,0,0,0,100,0),
(@PATH,40,-11992.014648,-1646.609253,34.173782,0,0,0,100,0),
(@PATH,41,-12009.803711,-1642.433350,35.999470,0,0,0,100,0),
(@PATH,42,-12034.342773,-1643.789551,39.795006,0,0,0,100,0),
(@PATH,43,-12042.879883,-1650.618164,40.627056,0,0,0,100,0),
(@PATH,44,-12058.425781,-1681.930420,42.665642,0,0,0,100,0),
(@PATH,45,-12059.555664,-1691.853027,43.423206,0,0,0,100,0),
(@PATH,46,-12059.799805,-1701.031494,44.344296,0,0,0,100,0),
(@PATH,47,-12053.253906,-1720.945435,48.184185,0,0,0,100,0),
(@PATH,48,-12043.537109,-1733.467651,51.260815,0,0,0,100,0),
(@PATH,49,-12034.110352,-1742.581421,53.809147,0,0,0,100,0),
(@PATH,50,-12043.537109,-1733.467651,51.260815,0,0,0,100,0),
(@PATH,51,-12053.253906,-1720.945435,48.184185,0,0,0,100,0),
(@PATH,52,-12059.799805,-1701.031494,44.344296,0,0,0,100,0),
(@PATH,53,-12059.555664,-1691.853027,43.423206,0,0,0,100,0);

-- Make the Gurubashi Axe Thrower follow the Hakkari Priest
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49752,49751);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49752;
DELETE FROM `creature_formations` WHERE `memberGUID`=49751;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49752,49752,0,0,2),
(49752,49751,3,200,2);

-- Note: those should go faster but it's not possible. The `move_flag` column is limited!
-- Razzashi Skitterer pathing: 14880
SET @GUID := 49763;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12121.770508,`position_y`=-1781.804077,`position_z`=80.251060 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12121.770508,-1781.804077,80.251060,1000,1,0,100,0),
(@PATH,2,-12107.982422,-1754.442871,81.616844,1000,1,0,100,0),
(@PATH,3,-12106.101563,-1742.353638,80.255928,1000,1,0,100,0),
(@PATH,4,-12126.319336,-1719.959229,80.978317,1000,1,0,100,0),
(@PATH,5,-12107.717773,-1699.646362,81.238678,1000,1,0,100,0),
(@PATH,6,-12133.279297,-1669.547363,82.450058,1000,1,0,100,0),
(@PATH,7,-12138.102539,-1669.364258,85.529083,1000,1,0,100,0),
(@PATH,8,-12161.593750,-1692.840698,95.234123,1000,1,0,100,0),
(@PATH,9,-12165.793945,-1692.938721,97.776299,1000,1,0,100,0),
(@PATH,10,-12191.083008,-1669.304321,111.627693,1000,1,0,100,0),
(@PATH,11,-12195.055664,-1669.150146,113.257439,1000,1,0,100,0),
(@PATH,12,-12215.911133,-1692.359497,122.447922,1000,1,0,100,0),
(@PATH,13,-12220.180664,-1692.659546,124.706985,1000,1,0,100,0),
(@PATH,14,-12221.366211,-1670.207275,126.270119,1000,1,0,100,0),
(@PATH,15,-12215.528320,-1669.463379,122.749390,1000,1,0,100,0),
(@PATH,16,-12183.934570,-1689.368286,106.393227,1000,1,0,100,0),
(@PATH,17,-12164.437500,-1681.142578,95.410744,1000,1,0,100,0),
(@PATH,18,-12145.658203,-1670.292603,89.038513,1000,1,0,100,0),
(@PATH,19,-12134.544922,-1682.580444,82.284355,1000,1,0,100,0),
(@PATH,20,-12126.685547,-1692.754028,81.543770,1000,1,0,100,0),
(@PATH,21,-12108.330078,-1725.148071,80.870346,1000,1,0,100,0),
(@PATH,22,-12123.732422,-1739.145386,80.321144,1000,1,0,100,0),
(@PATH,23,-12111.660156,-1760.424561,80.601723,1000,1,0,100,0);

-- Make them follow each other
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49763,49762);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49763;
DELETE FROM `creature_formations` WHERE `memberGUID`=49762;
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49763,49763,0,0,2),
(49763,49762,3,180,2);

-- Gurubashi Bat Rider pathing: 14750
SET @GUID := 49130;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12244.3,`position_y`=-1422.24,`position_z`=130.774 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12274.899414,-1414.912354,130.601059,0,0,0,100,0),
(@PATH,2,-12295.537109,-1443.068726,130.600327,0,0,0,100,0),
(@PATH,3,-12292.955078,-1465.422241,130.604462,0,0,0,100,0),
(@PATH,4,-12263.731445,-1485.708252,130.600510,0,0,0,100,0),
(@PATH,5,-12236.019531,-1462.886475,130.611526,0,0,0,100,0),
(@PATH,6,-12216.861328,-1455.598511,130.600693,0,0,0,100,0),
(@PATH,7,-12219.386719,-1437.946533,130.600693,0,0,0,100,0);

-- Following bats, leader is Gurubashi Bat Rider
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49130,49129,49123,49128,49127,49124,49125);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49130;
DELETE FROM `creature_formations` WHERE `memberGUID` IN (49129,49123,49128,49127,49124,49125);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49130,49130,0,0,2),
(49130,49129,6,0,2),
(49130,49123,6,60,2),
(49130,49128,6,120,2),
(49130,49127,6,180,2),
(49130,49124,6,240,2),
(49130,49125,6,300,2);

-- Gurubashi Bat Rider pathing: 14750
SET @GUID := 49185;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12277.5,`position_y`=-1444.66,`position_z`=130.725 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12279.888672,-1448.802124,130.600830,0,0,0,100,0),
(@PATH,2,-12274.909180,-1430.427979,130.601120,0,0,0,100,0),
(@PATH,3,-12244.499023,-1423.547974,130.601120,0,0,0,100,0),
(@PATH,4,-12224.520508,-1436.454224,130.601135,0,0,0,100,0),
(@PATH,5,-12212.955078,-1451.349609,130.600372,0,0,0,100,0),
(@PATH,6,-12233.332031,-1465.460449,130.600296,0,0,0,100,0),
(@PATH,7,-12255.265625,-1464.750000,130.600754,0,0,0,100,0);

-- Following bats, leader is Gurubashi Bat Rider
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49185,49167,49157,49156,49158);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49185;
DELETE FROM `creature_formations` WHERE `memberGUID` IN (49167,49157,49156,49158);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49185,49185,0,0,2),
(49185,49167,6,0,2),
(49185,49157,6,90,2),
(49185,49156,6,190,2),
(49185,49158,6,270,2);

-- Gurubashi Bat Rider pathing: 14750
SET @GUID := 49189;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12170.500000,`position_y`=-1467.250000,`position_z`=130.725006 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12131.439453,-1464.801758,130.600494,0,0,0,100,0),
(@PATH,2,-12170.894531,-1464.666138,130.602112,0,0,0,100,0),
(@PATH,3,-12196.201172,-1460.112305,131.453781,0,0,0,100,0),
(@PATH,4,-12211.844727,-1477.258057,130.900391,0,0,0,100,0),
(@PATH,5,-12196.201172,-1460.112305,131.453781,0,0,0,100,0),
(@PATH,6,-12170.894531,-1464.666138,130.602112,0,0,0,100,0);

-- Following bats, leader is Gurubashi Bat Rider
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49189,49188,49187,49186);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49189;
DELETE FROM `creature_formations` WHERE `memberGUID` IN (49188,49187,49186);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49189,49189,0,0,2),
(49189,49188,6,0,2),
(49189,49187,6,120,2),
(49189,49186,6,240,2);

-- Gurubashi Bat Rider pathing: 14750
SET @GUID := 49155;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12152.967773,`position_y`=-1487.547241,`position_z`=130.881485 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12186.473633,-1478.295776,130.600891,0,0,0,100,0),
(@PATH,2,-12206.798828,-1462.722656,131.283966,0,0,0,100,0),
(@PATH,3,-12195.971680,-1452.815918,130.631592,0,0,0,100,0),
(@PATH,4,-12175.709961,-1458.300659,130.601974,0,0,0,100,0),
(@PATH,5,-12155.517578,-1455.088135,130.601059,0,0,0,100,0),
(@PATH,6,-12136.959961,-1455.091919,130.601059,0,0,0,100,0),
(@PATH,7,-12125.050781,-1468.265625,130.600433,0,0,0,100,0),
(@PATH,8,-12150.831055,-1484.939819,130.655197,0,0,0,100,0);

-- Following bats, leader is Gurubashi Bat Rider
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49155,49154,49151,49150);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49155;
DELETE FROM `creature_formations` WHERE `memberGUID` IN (49154,49151,49150);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49155,49155,0,0,2),
(49155,49154,6,0,2),
(49155,49151,6,120,2),
(49155,49150,6,240,2);

-- Gurubashi Bat Rider pathing: 14750
SET @GUID := 49147;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12055.000000,`position_y`=-1443.459961,`position_z`=130.014999 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12072.780273,-1448.517334,130.204498,0,0,0,100,0),
(@PATH,2,-12098.666992,-1451.737915,130.774368,20000,0,0,100,0), -- Wait 20 seconds
(@PATH,3,-12072.780273,-1448.517334,130.204498,0,0,0,100,0),
(@PATH,4,-12056.207031,-1442.100464,130.156296,0,0,0,100,0);

-- Following bats, leader is Gurubashi Bat Rider
UPDATE `creature` SET `MovementType`=2 WHERE `guid` IN (49147,49143,49144,49145,49146);
DELETE FROM `creature_formations` WHERE `leaderGUID`=49147;
DELETE FROM `creature_formations` WHERE `memberGUID` IN (49143,49144,49145,49146);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`) VALUES
(49147,49147,0,0,2),
(49147,49143,6,90,2),
(49147,49144,6,180,2),
(49147,49145,6,270,2),
(49147,49146,6,360,2);

-- Bloodseeker Bat pathing: 11368
-- This one is done in move_flag run, makes it look better. Still looks horrible though =/
SET @GUID := 91555;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-12300.099609,`position_y`=-1370.160034,`position_z`=144.891006,`orientation`=5.4159 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-12280.832031,-1391.850098,149.030792,0,1,0,100,0),
(@PATH,2,-12279.230469,-1431.357666,150.007248,0,1,0,100,0),
(@PATH,3,-12263.227539,-1460.766235,147.386337,0,1,0,100,0),
(@PATH,4,-12231.422852,-1469.367920,148.652176,0,1,0,100,0),
(@PATH,5,-12220.394531,-1434.480347,151.252106,0,1,0,100,0),
(@PATH,6,-12246.502930,-1412.346069,152.635223,0,1,0,100,0);