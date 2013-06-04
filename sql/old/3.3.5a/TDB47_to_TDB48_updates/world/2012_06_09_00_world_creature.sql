UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry`=36725; -- Nerub'ar Broodkeeper

DELETE FROM `creature` WHERE `guid` IN (200939,200949,200956,201106,201127,201170);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`MovementType`) VALUES
(200939,36725,631,15,1,-210.3750,2202.675,75.09233,0.13962630,7200,0,0), -- Nerub'ar Broodkeeper
(200949,36725,631,15,1,-220.3819,2177.068,81.70050,0.85521130,7200,0,0), -- Nerub'ar Broodkeeper
(200956,36725,631,15,1,-216.4861,2245.405,81.70050,5.18362800,7200,0,0), -- Nerub'ar Broodkeeper
(201106,36725,631,15,1,-211.2899,2219.420,75.09233,0.15707960,7200,0,0), -- Nerub'ar Broodkeeper
(201127,36725,631,15,1,-249.8542,2219.672,86.27979,5.95157300,7200,0,0), -- Nerub'ar Broodkeeper
(201170,36725,631,15,1,-250.6129,2203.800,86.27979,0.03490658,7200,0,0); -- Nerub'ar Broodkeeper

DELETE FROM `creature_addon` WHERE `guid` IN (200912,200934,200939,200949,200956,201106,201127,201170);
INSERT INTO `creature_addon` (`guid`,`mount`,`bytes1`,`bytes2`,`auras`) VALUES
(200912,0,0x3000000,0x1,''), -- Nerub'ar Broodkeeper
(200934,0,0x3000000,0x1,''), -- Nerub'ar Broodkeeper
(200939,0,0x3000000,0x1,''), -- Nerub'ar Broodkeeper
(200949,0,0x3000000,0x1,''), -- Nerub'ar Broodkeeper
(200956,0,0x3000000,0x1,''), -- Nerub'ar Broodkeeper
(201106,0,0x3000000,0x1,''), -- Nerub'ar Broodkeeper
(201127,0,0x3000000,0x1,''), -- Nerub'ar Broodkeeper
(201170,0,0x3000000,0x1,''); -- Nerub'ar Broodkeeper
