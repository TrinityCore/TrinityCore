-- Wolf's Den Area
SET @PHASE := 11407;
SET @CGUID := 850661;
SET @OGUID := 501824;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- Phase 11407
(@CGUID+0,133331,1643,8567,9796,0,@PHASE,0,-1,0,0,1639.8837,380.15625,88.040016,6.081426143646240234,300,0,0,1,0,0,0,0,0,0), -- Narkalt <Flight Master>
(@CGUID+1,133340,1643,8567,9796,0,@PHASE,0,-1,0,1,1607.8298,303.21182,75.434135,3.864402055740356445,300,0,0,1,0,0,0,0,0,0), -- Horde Vanguard
(@CGUID+2,133340,1643,8567,9796,0,@PHASE,0,-1,0,1,1625.2274,328.59897,79.28655,5.046163082122802734,300,0,0,1,0,0,0,0,0,0), -- Horde Vanguard
(@CGUID+3,133340,1643,8567,9796,0,@PHASE,0,-1,0,1,1614.2969,294.02258,76.0142,3.611890077590942382,300,0,0,1,0,0,0,0,0,0), -- Horde Vanguard
(@CGUID+4,133340,1643,8567,9796,0,@PHASE,0,-1,0,1,1598.7205,337.625,79.61486,2.763387441635131835,300,0,0,1,0,0,0,0,0,0), -- Horde Vanguard
(@CGUID+5,133341,1643,8567,9796,0,@PHASE,0,-1,0,0,1603.651,328.0712,79.663795,1.56121528148651123,300,0,0,1,0,0,0,0,0,0), -- Ferix Glintzap <Engineering Supplies>
(@CGUID+6,139567,1643,8567,9796,0,@PHASE,0,-1,0,0,1606.066,337.7361,79.6642,4.409983634948730468,300,0,0,1,0,0,0,0,0,0), -- Joon Cloudgazer <Innkeeper>
(@CGUID+7,139575,1643,8567,9796,0,11712,0,-1,0,0,1671.974,353,89.37316,3.70809793472290039,300,0,0,1,0,0,0,0,0,0), -- Highland Alpha
(@CGUID+8,139576,1643,8567,9796,0,11712,0,-1,0,0,1653.7644,331.95297,83.915405,0.900327563285827636,300,0,0,1,0,0,0,0,0,0), -- Highland Adolescent
(@CGUID+9,139576,1643,8567,9796,0,11712,0,-1,0,0,1647.8851,361.2458,85.9575,3.715511798858642578,300,0,0,1,0,0,0,0,0,0), -- Highland Adolescent
(@CGUID+10,139576,1643,8567,9796,0,11712,0,-1,0,0,1635.2458,353.0708,82.405525,3.717580318450927734,300,0,0,1,0,0,0,0,0,0), -- Highland Adolescent
(@CGUID+11,139578,1643,8567,9796,0,11712,0,-1,0,0,1670.7812,355.80557,89.17664,3.708098173141479492,300,0,0,1,0,0,0,0,0,0), -- Highland Matriarch
(@CGUID+12,139561,1643,8567,9796,0,@PHASE,0,-1,0,1,1693.8438,352.2639,87.69748,3.975407838821411132,300,0,0,1,0,0,0,0,0,0), -- Mukkral Blackvein <Outpost Commander>
(@CGUID+13,133340,1643,8567,9796,0,@PHASE,0,-1,0,1,1641.5642,409.02777,86.934204,2.411156177520751953,300,0,0,1,0,0,0,0,0,0); -- Horde Vanguard

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+13;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`MountCreatureID`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`visibilityDistanceType`,`auras`) VALUES
(@CGUID+1,0,0,0,0,1,716,0,0,0,0,''),
(@CGUID+2,0,0,0,1,1,0,0,0,0,0,''),
(@CGUID+3,0,0,0,0,1,716,0,0,0,0,''),
(@CGUID+4,0,0,0,0,1,375,0,0,0,0,''),
(@CGUID+7,0,0,0,1,1,0,0,0,0,0,''),
(@CGUID+11,0,0,0,1,1,0,0,0,0,0,''),
(@CGUID+13,0,0,0,0,1,716,0,0,0,0,'');

-- Wolf's Den Area
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnDifficulties`,`phaseUseFlags`,`PhaseId`,`PhaseGroup`,`terrainSwapMap`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`ScriptName`,`VerifiedBuild`) VALUES
-- Phase 0
(@OGUID+0,295791,1643,8567,0,'0',0,0,0,-1,1600.5796,332.77338,79.58055,4.712433,0,0,-0.70709133,0.7071222,120,255,1,'',45745), -- Stool
(@OGUID+1,295792,1643,8567,0,'0',0,0,0,-1,1603.0184,332.20267,79.58038,3.7525005,0,0,-0.95371056,0.30072606,120,255,1,'',45745), -- Stool
(@OGUID+2,295793,1643,8567,0,'0',0,0,0,-1,1608.7189,334.1857,79.58141,1.2304978,0,0,0.5771618,0.8166298,120,255,1,'',45745), -- Stool
(@OGUID+3,295778,1643,8567,0,'0',0,0,0,-1,1610.3127,336.27765,79.47259,0.6852636,0,0,0.33596706,0.9418737,120,255,1,'',45745), -- Fire
(@OGUID+4,295794,1643,8567,0,'0',0,0,0,-1,1607.294,336.5553,79.581055,6.073788,0,0,-0.10450745,0.99452406,120,255,1,'',45745), -- Stool
-- Phase 11407
(@OGUID+5,294923,1643,8567,9796,'0',0,@PHASE,0,-1,1626.2361,326.47223,79.25647,5.6985016,0,0,-0.2881956,0.95757157,120,255,1,'',45745), -- Campfire
(@OGUID+6,296105,1643,8567,9796,'0',0,@PHASE,0,-1,1616.1736,332.13196,79.392265,6.0126605,0,0,-0.1348505,0.99086595,120,255,1,'',45745), -- Mailbox
(@OGUID+7,298778,1643,8567,9796,'0',0,@PHASE,0,-1,1615.6997,325.30728,81.00852,5.9758115,-0.009302139,-0.054502487,-0.15289497,0.9866945,120,255,1,'',45745), -- Wanted Poster
(@OGUID+8,297139,1643,8567,9796,'0',0,@PHASE,0,-1,1685.2712,348.30164,88.75685,0.8007461,0,0,0.38976192,0.92091566,120,255,1,'',45745); -- Campfire

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+8;
INSERT INTO `gameobject_addon` (`guid`,`parent_rotation0`,`parent_rotation1`,`parent_rotation2`,`parent_rotation3`,`invisibilityType`,`invisibilityValue`,`WorldEffectID`,`AIAnimKitID`) VALUES
(@OGUID+0,0,0,-0.793341,0.6087776,0,0,0,0),
(@OGUID+1,0,0,-0.793341,0.6087776,0,0,0,0),
(@OGUID+2,0,0,-0.793341,0.6087776,0,0,0,0),
(@OGUID+3,0,0,-0.793341,0.6087776,0,0,0,0),
(@OGUID+4,0,0,-0.793341,0.6087776,0,0,0,0),
(@OGUID+8,0,0,1,-4.371139,0,0,0,0);

-- Pathing for Highland Adolescent Entry: 139576
SET @NPC := @CGUID+8;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1659.717,339.47223,86.30818,NULL,0,1,0,100,0),
(@PATH,2,1666.3473,348.967,88.045975,NULL,0,1,0,100,0),
(@PATH,3,1664.5555,357.24826,87.98909,NULL,0,1,0,100,0),
(@PATH,4,1653.2535,364.717,86.701126,NULL,0,1,0,100,0),
(@PATH,5,1634.1771,352.37674,81.99336,NULL,0,1,0,100,0),
(@PATH,6,1632.2865,337.19965,79.55618,NULL,0,1,0,100,0),
(@PATH,7,1629.3038,321.2986,79.28655,NULL,0,1,0,100,0),
(@PATH,8,1645.8541,321.97916,83.37972,NULL,0,1,0,100,0);
-- 0x202F38CD60884E00000D9100004F5B4F .go xyz 1659.717 339.47223 86.30818

-- Pathing for Highland Adolescent Entry: 139576
SET @NPC := @CGUID+9;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1634.1771,352.37674,81.99336,NULL,0,1,0,100,0),
(@PATH,2,1632.2865,337.19965,79.55618,NULL,0,1,0,100,0),
(@PATH,3,1629.3038,321.2986,79.28655,NULL,0,1,0,100,0),
(@PATH,4,1645.8541,321.97916,83.37972,NULL,0,1,0,100,0),
(@PATH,5,1659.717,339.47223,86.30818,NULL,0,1,0,100,0),
(@PATH,6,1666.3473,348.967,88.045975,NULL,0,1,0,100,0),
(@PATH,7,1664.5555,357.24826,87.98909,NULL,0,1,0,100,0),
(@PATH,8,1653.2535,364.717,86.701126,NULL,0,1,0,100,0);
-- 0x202F38CD60884E00000D9100014F5B4F .go xyz 1634.1771 352.37674 81.99336

-- Pathing for Highland Adolescent Entry: 139576
SET @NPC := @CGUID+10;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1632.2865,337.19965,79.55618,NULL,0,1,0,100,0),
(@PATH,2,1629.3038,321.2986,79.28655,NULL,0,1,0,100,0),
(@PATH,3,1645.8541,321.97916,83.37972,NULL,0,1,0,100,0),
(@PATH,4,1659.717,339.47223,86.30818,NULL,0,1,0,100,0),
(@PATH,5,1666.3473,348.967,88.045975,NULL,0,1,0,100,0),
(@PATH,6,1664.5555,357.24826,87.98909,NULL,0,1,0,100,0),
(@PATH,7,1653.2535,364.717,86.701126,NULL,0,1,0,100,0),
(@PATH,8,1634.1771,352.37674,81.99336,NULL,0,1,0,100,0);
-- 0x202F38CD60884E00000D910000CF5B4F .go xyz 1632.2865 337.19965 79.55618

DELETE FROM `phase_area` WHERE `AreaId`=9796 AND `PhaseId` IN (11407,11712);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(9796,11407, 'Cosmetic - Tiragarde Sound - Show Wolf\'s Den Outpost'),
(9796,11712, 'Cosmetic - Tiragarde Sound - Show Wolf\'s Den Outpost Upgrade');

DELETE FROM  `phase_name` WHERE `ID` IN (11407,11712);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(11407, 'Cosmetic - Wolf\'s Den Outpost'),
(11712, 'Cosmetic - Wolf\'s Den Outpost Upgrade');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (11407,11712) AND `SourceEntry`=9796 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26, 11407, 9796, 0, 1, 8, 0, 51803, 0, 0, 0, 0, 0, '', 'Show Phase 11407 for area 9358 if quest The Kul Tiras Campaign is Rewarded'),
(26, 11712, 9796, 0, 1, 47, 0, 53152, 74, 0, 0, 0, 0, '', 'Show Phase 11712 for area 9358 if Wolves for the Den is in progress/complete/rewarded'),
(26, 11407, 9796, 0, 2, 6, 0, 469, 0, 0, 0, 0, 0, '', 'Show Phase 11407 for area 9358 if team is alliance'),
(26, 11712, 9796, 0, 2, 6, 0, 469, 0, 0, 0, 0, 0, '', 'Show Phase 11712 for area 9358 if team is alliance');

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (133331,133341,139561,139567,139575,139576,139578);
INSERT INTO `creature_template_scaling` (`Entry`,`DifficultyID`,`LevelScalingDeltaMin`,`LevelScalingDeltaMax`,`ContentTuningID`,`VerifiedBuild`) VALUES
(133331,0,0,0,2117,45745),
(133341,0,0,0,186,45745),
(139561,0,0,0,186,45745),
(139567,0,0,0,189,45745),
(139575,0,0,0,187,45745),
(139576,0,0,0,187,45745),
(139578,0,0,0,187,45745);

UPDATE `creature_model_info` SET `VerifiedBuild`=45745 WHERE `DisplayID` IN (77489, 42408, 79059, 82858, 6302, 4626, 30256, 42744, 86395, 64329, 70446, 59949, 82851);

DELETE FROM `npc_vendor` WHERE (`entry`=139567 AND `item`=163784 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139567 AND `item`=163783 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139567 AND `item`=160518 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139567 AND `item`=162556 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139567 AND `item`=161373 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139567 AND `item`=162554 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139567 AND `item`=161347 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=139567 AND `item`=162555 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133341 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133341 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133341 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133341 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133341 AND `item`=180733 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133341 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=133341 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(139567, 8, 163784, 0, 0, 1, 0, 0, 45745), -- Seafoam Coconut Water
(139567, 7, 163783, 0, 0, 1, 0, 0, 45745), -- Mount Mugamba Spring Water
(139567, 6, 160518, 0, 0, 1, 0, 0, 45745), -- Great Turtle Soup
(139567, 5, 162556, 0, 0, 1, 0, 0, 45745), -- Zeb'ahari Kiwi
(139567, 4, 161373, 0, 0, 1, 0, 0, 45745), -- Seared Simmerfin
(139567, 3, 162554, 0, 0, 1, 0, 0, 45745), -- Rootway Papaya
(139567, 2, 161347, 0, 0, 1, 0, 0, 45745), -- Riverbeast Stew
(139567, 1, 162555, 0, 0, 1, 0, 0, 45745), -- Zocalo Cheddar
(133341, 7, 3857, 0, 0, 1, 0, 0, 45745), -- Coal
(133341, 6, 18567, 0, 0, 1, 0, 0, 45745), -- Elemental Flux
(133341, 5, 3466, 0, 0, 1, 0, 0, 45745), -- Strong Flux
(133341, 4, 2880, 0, 0, 1, 0, 0, 45745), -- Weak Flux
(133341, 3, 180733, 0, 0, 1, 0, 0, 45745), -- Luminous Flux
(133341, 2, 5956, 0, 0, 1, 0, 0, 45745), -- Blacksmith Hammer
(133341, 1, 2901, 0, 0, 1, 0, 0, 45745); -- Mining Pick

UPDATE `gossip_menu` SET `VerifiedBuild`=45745 WHERE (`MenuID`=22729 AND `TextID`=35152) OR (`MenuID`=22728 AND `TextID`=35150);

UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=139578; -- Highland Matriarch
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=139576; -- Highland Adolescent
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=139575; -- Highland Alpha
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=50 WHERE `entry`=133341; -- Ferix Glintzap
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `unit_flags3`=8388608 WHERE `entry`=133340; -- Horde Vanguard
UPDATE `creature_template` SET `gossip_menu_id`=22729, `minlevel`=50, `maxlevel`=50 WHERE `entry`=139567; -- Joon Cloudgazer
UPDATE `creature_template` SET `gossip_menu_id`=22728, `minlevel`=50, `maxlevel`=50, `unit_flags3`=1048576 WHERE `entry`=139561; -- Mukkral Blackvein
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60 WHERE `entry`=133331; -- Narkalt
