--
SET @OGUID := 48873; -- SET BY THE TDB TEAM (Need 24)
SET @EVENT := 12;

-- Cursed Darkhound - No such spawn exists on 1.15.4 (57134) and Wotlk classic (51739) at that location, even after Hallow's End
DELETE FROM `creature` WHERE `guid`=45217;

-- Wickerman Guardian
UPDATE `creature_template` SET `gossip_menu_id`=6536, `npcflag`=1, `BaseAttackTime`=3000, `RangeAttackTime`=3000, `unit_flags`=32832 WHERE `entry`=15195;

DELETE FROM `creature_template_addon` WHERE `entry`=15195;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES 
(15195, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, '12187');

DELETE FROM `gossip_menu` WHERE `MenuID`=6536 AND `TextID`=7739;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES 
(6536, 7739, 0);

-- Darkcaller Yanka
UPDATE `broadcast_text` SET `Text1`='Welcome to the Wickerman Festival, $c!$B$BOn the observance of Hallow''s End, the Forsaken burn a wickerman in honor of this, the most revered of occasions.  It was on this day that the Banshee Queen herself delivered us from the clutches of the Lich King and the Scourge.  We have remained free ever since.  Those who would have seen us fall are repaid in full... with vengeance!$B$BThe burning of the Wickerman begins at 8:00 PM!', `VerifiedBuild`=0 WHERE `ID`=10671;
UPDATE `npc_text` SET `text0_1`='Welcome to the Wickerman Festival, $c!$B$BOn the observance of Hallow''s End, the Forsaken burn a wickerman in honor of this, the most revered of occasions.  It was on this day that the Banshee Queen herself delivered us from the clutches of the Lich King and the Scourge.  We have remained free ever since.  Those who would have seen us fall are repaid in full... with vengeance!$B$BThe burning of the Wickerman begins at 8:00 PM!', `VerifiedBuild`=0  WHERE `ID`=7740;

DELETE FROM `creature_template_addon` WHERE `entry`=15197;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `visibilityDistanceType`, `auras`) VALUES 
(15197, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, '');

DELETE FROM `gossip_menu` WHERE `MenuID`=6537 AND `TextID`=7740;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES 
(6537, 7740, 0);

-- Existing spawn updates
UPDATE `creature` SET `zoneId`=85, `areaId`=153, `position_x`=1751.79833984375, `position_y`=512.40234375, `position_z`=37.38980865478515625, `orientation`=1.431169986724853515, `spawntimesecs`=0 WHERE `guid`=85633; -- Instant respawn on Wrath classic
UPDATE `creature` SET `zoneId`=85, `areaId`=153, `position_x`=1728.943603515625, `position_y`=548.496337890625, `position_z`=34.24716949462890625, `orientation`=4.537856101989746093, `spawntimesecs`=0 WHERE `guid`=85634; -- Instant respawn on Wrath classic
UPDATE `creature` SET `zoneId`=85, `areaId`=153, `position_x`=1712.1248779296875, `position_y`=512.95538330078125, `position_z`=36.6183013916015625, `orientation`=1.588249564170837402, `spawntimesecs`=0 WHERE `guid`=85632; -- Instant respawn on Wrath classic
UPDATE `creature` SET `zoneId`=85, `areaId`=153, `position_x`=1731.7572021484375, `position_y`=521.96514892578125, `position_z`=35.98299407958984375, `orientation`=1.588249564170837402 WHERE `guid`=85635;

UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1731.435546875, `position_y`=508.8170166015625, `position_z`=41.35896682739257812, `orientation`=1.500982880592346191, `rotation2`=0.681998252868652343, `rotation3`=0.731353819370269775 WHERE `guid`=17870;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1746.1051025390625, `position_y`=517.218017578125, `position_z`=38.87208938598632812, `orientation`=3.52557229995727539, `rotation2`=-0.98162651062011718, `rotation3`=0.190812408924102783 WHERE `guid`=17879;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1750.8131103515625, `position_y`=509.61712646484375, `position_z`=38.33571243286132812, `orientation`=1.535889506340026855, `rotation2`=0.694658279418945312, `rotation3`=0.719339847564697265 WHERE `guid`=17868;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1759.492431640625, `position_y`=515.94879150390625, `position_z`=35.30905914306640625, `orientation`=5.253442287445068359, `rotation2`=-0.49242305755615234, `rotation3`=0.870355963706970214 WHERE `guid`=17871;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1744.9915771484375, `position_y`=475.503570556640625, `position_z`=61.65636444091796875, `orientation`=5.183629035949707031, `rotation2`=-0.52249813079833984, `rotation3`=0.852640450000762939 WHERE `guid`=17873;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1719.737060546875, `position_y`=523.3734130859375, `position_z`=36.81510162353515625, `orientation`=3.490667104721069335, `rotation2`=-0.98480701446533203, `rotation3`=0.173652306199073791 WHERE `guid`=17881;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1727.8775634765625, `position_y`=475.36956787109375, `position_z`=63.6461334228515625, `orientation`=3.543023586273193359, `rotation2`=-0.97992420196533203, `rotation3`=0.199370384216308593 WHERE `guid`=17880;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1707.3563232421875, `position_y`=519.654052734375, `position_z`=34.97322845458984375, `orientation`=5.654868602752685546, `rotation2`=-0.30901622772216796, `rotation3`=0.95105677843093872 WHERE `guid`=17872;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1709.513916015625, `position_y`=509.67730712890625, `position_z`=36.90455245971679687, `orientation`=1.431168079376220703, `rotation2`=0.656058311462402343, `rotation3`=0.754710197448730468 WHERE `guid`=17869;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1714.2874755859375, `position_y`=473.915802001953125, `position_z`=61.64679718017578125, `orientation`=2.251473426818847656, `rotation2`=0.902585029602050781, `rotation3`=0.430511653423309326 WHERE `guid`=17874;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1741.1187744140625, `position_y`=505.332916259765625, `position_z`=41.39785385131835937, `orientation`=4.642575740814208984, `rotation2`=-0.731353759765625, `rotation3`=0.681998312473297119 WHERE `guid`=17875;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1731.564208984375, `position_y`=514.59552001953125, `position_z`=39.34745407104492187, `orientation`=5.70722818374633789, `rotation2`=-0.28401470184326171, `rotation3`=0.958819925785064697 WHERE `guid`=17876;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1722.21875, `position_y`=512.33160400390625, `position_z`=39.15671920776367187, `orientation`=0.209439441561698913, `rotation2`=0.104528427124023437, `rotation3`=0.994521915912628173 WHERE `guid`=17877;
UPDATE `gameobject` SET `zoneId`=85, `areaId`=153, `position_x`=1731.5814208984375, `position_y`=500.1231689453125, `position_z`=42.50485992431640625, `orientation`=4.502951622009277343, `rotation2`=-0.7771453857421875, `rotation3`=0.629321098327636718 WHERE `guid`=17878;

-- Missing Spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+23;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180434, 0, 85, 153, 1, 1, 1735.592041015625, 549.92852783203125, 33.68162918090820312, 0.191985160112380981, 0, 0, 0.095845222473144531, 0.995396256446838378, 120, 255, 1, 0), -- Bonfire (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+1, 180432, 0, 85, 153, 1, 1, 1731.3472900390625, 474.772796630859375, 61.65636444091796875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 0), -- Forsaken Banner (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+2, 180426, 0, 85, 153, 1, 1, 1733.6595458984375, 533.2462158203125, 47.54170608520507812, 5.550147056579589843, 0, 0, -0.358367919921875, 0.933580458164215087, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+3, 180426, 0, 85, 153, 1, 1, 1734.2559814453125, 531.1075439453125, 50.04204940795898437, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+4, 180427, 0, 85, 153, 1, 1, 1734.5611572265625, 531.56109619140625, 57.94888687133789062, 3.036838293075561523, 0, 0, 0.998628616333007812, 0.052353221923112869, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+5, 180427, 0, 85, 153, 1, 1, 1734.66015625, 531.1474609375, 54.41878890991210937, 5.969027042388916015, 0, 0, -0.1564340591430664, 0.987688362598419189, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+6, 180426, 0, 85, 153, 1, 1, 1734.4339599609375, 531.14208984375, 47.4670867919921875, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+7, 180427, 0, 85, 153, 1, 1, 1734.4556884765625, 531.4183349609375, 61.71345901489257812, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+8, 180426, 0, 85, 153, 1, 1, 1734.533203125, 531.1978759765625, 46.06215286254882812, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+9, 180426, 0, 85, 153, 1, 1, 1734.3553466796875, 531.16339111328125, 49.0607147216796875, 5.619962215423583984, 0, 0, -0.32556724548339843, 0.945518851280212402, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+10, 180427, 0, 85, 153, 1, 1, 1734.4178466796875, 531.39447021484375, 52.01569366455078125, 3.385940074920654296, 0, 0, -0.99254608154296875, 0.121869951486587524, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+11, 180427, 0, 85, 153, 1, 1, 1734.52392578125, 531.32806396484375, 57.34672164916992187, 1.134462952613830566, 0, 0, 0.537299156188964843, 0.843391716480255126, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+12, 180426, 0, 85, 153, 1, 1, 1734.533203125, 531.1978759765625, 46.79131698608398437, 2.600535154342651367, 0, 0, 0.963629722595214843, 0.26724100112915039, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+13, 180427, 0, 85, 153, 1, 1, 1734.6168212890625, 531.39324951171875, 55.88604736328125, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+14, 180427, 0, 85, 153, 1, 1, 1734.592041015625, 531.23779296875, 58.59108352661132812, 0.069811686873435974, 0, 0, 0.034898757934570312, 0.999390840530395507, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+15, 180426, 0, 85, 153, 1, 1, 1734.533203125, 531.1978759765625, 50.65242767333984375, 5.026549339294433593, 0, 0, -0.5877847671508789, 0.809017360210418701, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+16, 180427, 0, 85, 153, 1, 1, 1734.4432373046875, 531.34063720703125, 57.0312652587890625, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+17, 180426, 0, 85, 153, 1, 1, 1734.533203125, 531.1978759765625, 45.555206298828125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+18, 180427, 0, 85, 153, 1, 1, 1734.52392578125, 531.32806396484375, 55.53421783447265625, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+19, 180426, 0, 85, 153, 1, 1, 1734.5540771484375, 531.27490234375, 49.49390411376953125, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+20, 180427, 0, 85, 153, 1, 1, 1734.68505859375, 531.302978515625, 54.98458099365234375, 1.117009282112121582, 0, 0, 0.529918670654296875, 0.84804844856262207, 120, 255, 1, 0), -- Bat02 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+21, 180426, 0, 85, 153, 1, 1, 1734.5748291015625, 531.3519287109375, 51.23121261596679687, 0.663223206996917724, 0, 0, 0.325567245483398437, 0.945518851280212402, 120, 255, 1, 0), -- Bat01 (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject1
(@OGUID+22, 180437, 0, 85, 153, 1, 1, 1738.4254150390625, 512.015625, 39.81720733642578125, 4.607671737670898437, 0, 0, -0.74314403533935546, 0.669131457805633544, 120, 255, 1, 0), -- Wickerman Ashes (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject2
(@OGUID+23, 180437, 0, 85, 153, 1, 1, 1721.447265625, 505.14117431640625, 40.88557815551757812, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 120, 255, 1, 0); -- Wickerman Ashes (Area: Ruins of Lordaeron - Difficulty: 0) CreateObject2

DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+23 AND `eventEntry`=@EVENT;
INSERT INTO `game_event_gameobject` SELECT @EVENT, gameobject.guid FROM `gameobject` WHERE gameobject.guid BETWEEN @OGUID+0 AND @OGUID+23;
