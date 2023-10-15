-- Add missing Alliance and Horde spawns to Exile's Reach Beach
SET @CGUID := 1052006;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+0,156626,2175,10424,10453,'0',13845,0,-1,0,1,-435.15277,-2610.9915,0.66789305,0.70219886302947998,300,0,0,1,0,0,0,0,'q54952_garrick',45745), -- Captain Garrick
(@CGUID+1,149917,2175,10424,10453,'0',13845,0,-1,0,0,-434.24652,-2609.7415,0.59088486,0,300,0,0,12,0,0,0,0,'private_cole_beach',45745), -- Private Cole
(@CGUID+2,156622,2175,10424,10453,'0',13845,0,-1,0,0,-411.89062,-2604.6145,1.0036093,3.944462299346923828,300,0,0,60,0,0,0,0,'quartermaster_richter_beach',45745), -- Quartermaster Richter
(@CGUID+3,156612,2175,10424,10453,'0',13845,0,-1,0,0,-448.9184,-2606.019,0.6024305,1.22242283821105957,300,0,0,12,0,0,0,0,'',45745), -- Kee-La Laying
(@CGUID+4,156609,2175,10424,10453,'0',13845,0,-1,0,0,-420.58682,-2600.0364,0.5516572,3.633042335510253906,300,0,0,48,0,0,0,0,'',45745), -- Bjorn Stouthands Laying
(@CGUID+5,156610,2175,10424,10453,'0',13845,0,-1,0,0,-428.67188,-2593.8767,0.15131068,1.439171195030212402,300,0,0,38,0,0,0,0,'',45745), -- Austin Huxworth Laying
(@CGUID+6,151088,2175,10424,10453,'0',13845,0,-1,0,0,-448.74826,-2606.0122,0.5972222,5.880968093872070312,300,0,0,1,0,0,0,0,'kee_la_beach',45745), -- Kee-La Standing
(@CGUID+7,151089,2175,10424,10453,'0',13845,0,-1,0,0,-420.58853,-2600,0.55103314,3.633042335510253906,300,0,0,1,0,0,0,0,'bjorn_stouthands_beach',45745), -- Bjorn Stouthands Standing
(@CGUID+8,154170,2175,10424,10453,'0',13845,0,-1,0,0,-428.57986,-2593.802,0.14932014,4.289614677429199218,300,0,0,1,0,0,0,0,'austin_huxworth_beach',45745), -- Austin Huxworth Standing
(@CGUID+9,166782,2175,10424,10453,'0',15279,0,-1,0,1,-435.10416,-2611,0.6689798,0.3949451744556427,300,0,0,1,0,0,0,0,'q59931_grimaxe',45745), -- Warlord Breka Grimaxe
(@CGUID+10,166784,2175,10424,10453,'0',15279,0,-1,0,0,-434.3316,-2609.7727,0.5939314,0,300,0,0,36,0,0,0,0,'grunt_throg_beach',45745), -- Grunt Throg
(@CGUID+11,166800,2175,10424,10453,'0',15279,0,-1,0,0,-411.87326,-2604.6946,1.0082067,3.414293289184570312,300,0,0,60,0,0,0,0,'jin_hake_beach',45745), -- Provisioner Jin'hake
(@CGUID+12,166786,2175,10424,10453,'0',15279,0,-1,0,0,-448.7309,-2606.0261,0.60243523,0.183310702443122863,300,0,0,60,0,0,0,0,'',45745), -- Bo Laying
(@CGUID+13,166791,2175,10424,10453,'0',15279,0,-1,0,0,-428.5764,-2593.9307,0.15283203,4.849575996398925781,300,0,0,48,0,0,0,0,'',45745), -- Mithdran Laying
(@CGUID+14,166796,2175,10424,10453,'0',15279,0,-1,0,0,-420.65625,-2600.2847,0.5566463,3.23506474494934082,300,0,0,60,0,0,0,0,'',45745), -- Lana Jordan Laying
(@CGUID+15,166787,2175,10424,10453,'0',15279,0,-1,0,0,-437.55035,-2610.1511,0.5750057,6.174409866333007812,300,0,0,1,0,0,0,0,'bo_beach', 45745), -- Bo Standing
(@CGUID+16,166792,2175,10424,10453,'0',15279,0,-1,0,0,-436.05557,-2607.8057,0.44101235,4.849575996398925781,300,0,0,1,0,0,0,0,'mithran_beach', 45745), -- Mithdran Dawntracker Standing
(@CGUID+17,166797,2175,10424,10453,'0',15279,0,-1,0,0,-433.9479,-2608.7449,0.5250714,4.046853065490722656,300,0,0,1,0,0,0,0,'lana_jordan_beach', 45745); -- Lana Jordan Standing

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`MountCreatureID`,`Standstate`,`SheathState`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`visibilityDistanceType`,`auras`) VALUES
(@CGUID+0,0,0,0,0,1,0,0,0,0,0,'313220'),
(@CGUID+1,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+2,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+3,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+4,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+5,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+9,0,0,0,0,1,0,0,0,0,0,'325061'),
(@CGUID+10,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+11,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+12,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+13,0,0,0,3,1,0,0,0,0,0,''),
(@CGUID+14,0,0,0,3,1,0,0,0,0,0,'');

DELETE FROM `spawn_group` WHERE `spawnId` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `spawn_group` (`groupId`,`spawnType`,`spawnId`) VALUES
(128,0,@CGUID+0),
(128,0,@CGUID+1),
(128,0,@CGUID+2),
(128,0,@CGUID+3),
(128,0,@CGUID+4),
(128,0,@CGUID+5),
(128,0,@CGUID+6),
(128,0,@CGUID+7),
(128,0,@CGUID+8),
(129,0,@CGUID+9),
(129,0,@CGUID+10),
(129,0,@CGUID+11),
(129,0,@CGUID+12),
(129,0,@CGUID+13),
(129,0,@CGUID+14),
(129,0,@CGUID+15),
(129,0,@CGUID+16),
(129,0,@CGUID+17);

-- Phasing

DELETE FROM `phase_area` WHERE `AreaId`=10453 AND `PhaseId` IN (13845,15279);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10453,13845, 'NPE Murloc Hideaway - Alliance Crew'),
(10453,15279, 'NPE Murloc Hideaway - Horde Crew');

DELETE FROM `phase_name` WHERE `ID` IN (13845,15279);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(13845,'Cosmetic - NPE Murloc Hideaway - Alliance Crew'),
(15279,'Cosmetic - NPE Murloc Hideaway - Horde Crew');

-- Conditions

-- Fix condition showing Alliance quest phase
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13845) AND `SourceEntry`=10453;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13845,10453,0,0,47,0,54952,1,0,0,0,0,'','Show phase 13845 if Quest 54952 is not taken'),
(26,13845,10453,0,0,6,0,469,0,0,0,0,0,'','Show phase 13845 if team is alliance');

-- Fix condition showing Horde quest phase
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15279) AND `SourceEntry`=10453;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15279,10453,0,0,47,0,59931,1,0,0,0,0,'','Show phase 15279 if Quest 59931 is not taken'),
(26,15279,10453,0,0,6,0,67,0,0,0,0,0,'','Show phase 15279 if team is Horde');

-- Spawn Conditions for Alliance visibility Murloc Hideaway
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry` IN (156609,156610,156612,151089,154170,151088,149917,156622,156651) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,156609,0,0,48,0,388448,0,0,0,0,0,'','Spawn of creature with entry 156609 requires Quest 54951 objective 388448 not complete'), -- Bjorn Stouthands "Laying"
(32,5,156609,0,1,47,0,54951,1,0,0,0,0,'','OR Spawn of creature with entry 156609 requires Quest 54951 not taken'), -- Bjorn Stouthands "Laying"
(32,5,156610,0,0,48,0,391859,0,0,0,0,0,'','Spawn of creature with entry 156610 requires Quest 54951 objective 391859 not complete'), -- Austin Huxworth "Laying"
(32,5,156610,0,1,47,0,54951,1,0,0,0,0,'','OR Spawn of creature with entry 156610 requires Quest 54951 not taken'), -- Austin Huxworth "Laying"
(32,5,156612,0,0,48,0,391858,0,0,0,0,0,'','Spawn of creature with entry 156612 requires Quest 54951 objective 391858 not complete'), -- Kee-La "Laying"
(32,5,156612,0,1,47,0,54951,1,0,0,0,0,'','OR Spawn of creature with entry 156612 requires Quest 54951 not taken'), -- Kee-La "Laying"
(32,5,151089,0,0,48,0,388448,0,1,0,0,0,'','Spawn of creature with entry 151089 requires Quest 54951 objective 388448 complete'), -- Bjorn Stouthands "Standing"
(32,5,154170,0,0,48,0,391859,0,1,0,0,0,'','Spawn of creature with entry 154170 requires Quest 54951 objective 391859 complete'), -- Austin Huxworth "Standing"
(32,5,151088,0,0,48,0,391858,0,1,0,0,0,'','Spawn of creature with entry 151088 requires Quest 54951 objective 391858 complete'), -- Kee-La "Standing"
(32,5,151089,0,1,47,0,54951,64,0,0,0,0,'','OR Spawn of creature with entry 151089 requires Quest 54951 is Rewarded'), -- Bjorn Stouthands "Standing"
(32,5,154170,0,1,47,0,54951,64,0,0,0,0,'','OR Spawn of creature with entry 154170 requires Quest 54951 is Rewarded'), -- Austin Huxworth "Standing"
(32,5,151088,0,1,47,0,54951,64,0,0,0,0,'','OR Spawn of creature with entry 151088 requires Quest 54951 is Rewarded'), -- Kee-La "Standing"
(32,5,151089,0,1,47,0,54952,64,0,1,0,0,'','OR Spawn of creature with entry 151089 requires Quest 54952 is not Rewarded'), -- Bjorn Stouthands "Standing"
(32,5,154170,0,1,47,0,54952,64,0,1,0,0,'','OR Spawn of creature with entry 154170 requires Quest 54952 is not Rewarded'), -- Austin Huxworth "Standing"
(32,5,151088,0,1,47,0,54952,64,0,1,0,0,'','OR Spawn of creature with entry 151088 requires Quest 54952 is not Rewarded'), -- Kee-La "Standing"
(32,5,149917,0,1,47,0,54951,1,0,0,0,0,'','Spawn of creature with entry 149917 requires Quest 54951 not taken'), -- Private Cole
(32,5,156622,0,1,47,0,54951,1,0,0,0,0,'','Spawn of creature with entry 156622 requires Quest 54951 not taken'), -- Quartermaster Richter
(32,5,156651,0,0,1,0,297295,0,0,1,0,0,'','Spawn of creature with entry 156651 requires Player not have aura 297295'); -- Captain Garrick

-- Spawn Conditions for Horde visibility Murloc Hideaway
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry` IN (166786,166791,166796,166787,166792,166797,166784,156622,166906) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,166786,0,0,48,0,397246,0,0,0,0,0,'','Spawn of creature with entry 166786 requires Quest 59930 objective 397246 not complete'), -- Bo "Laying"
(32,5,166786,0,1,47,0,59930,1,0,0,0,0,'','OR Spawn of creature with entry 166786 requires Quest 59930 not taken'), -- Bo "Laying"
(32,5,166791,0,0,48,0,397247,0,0,0,0,0,'','Spawn of creature with entry 166791 requires Quest 59930 objective 397247 not complete'), -- Mithdran "Laying"
(32,5,166791,0,1,47,0,59930,1,0,0,0,0,'','OR Spawn of creature with entry 166791 requires Quest 59930 not taken'), -- Mithdran "Laying"
(32,5,166796,0,0,48,0,397245,0,0,0,0,0,'','Spawn of creature with entry 166796 requires Quest 59930 objective 397245 not complete'), -- Lana Jordan "Laying"
(32,5,166796,0,1,47,0,59930,1,0,0,0,0,'','OR Spawn of creature with entry 166796 requires Quest 59930 not taken'), -- Lana Jordan "Laying"
(32,5,166787,0,0,48,0,397246,0,1,0,0,0,'','Spawn of creature with entry 166787 requires Quest 59930 objective 397246 complete'), -- Bo "Standing"
(32,5,166792,0,0,48,0,397247,0,1,0,0,0,'','Spawn of creature with entry 166792 requires Quest 59930 objective 397247 complete'), -- Mithdran "Standing"
(32,5,166797,0,0,48,0,397245,0,1,0,0,0,'','Spawn of creature with entry 166797 requires Quest 59930 objective 397245 complete'), -- Lana Jordan "Standing"
(32,5,166787,0,1,47,0,59930,64,0,0,0,0,'','OR Spawn of creature with entry 166787 requires Quest 59930 is Rewarded'), -- Bo "Standing"
(32,5,166792,0,1,47,0,59930,64,0,0,0,0,'','OR Spawn of creature with entry 166792 requires Quest 59930 is Rewarded'), -- Mithdran "Standing"
(32,5,166797,0,1,47,0,59930,64,0,0,0,0,'','OR Spawn of creature with entry 166797 requires Quest 59930 is Rewarded'), -- Lana Jordan "Standing"
(32,5,166787,0,1,47,0,59931,64,0,1,0,0,'','OR Spawn of creature with entry 166787 requires Quest 59931 is not Rewarded'), -- Bo "Standing"
(32,5,166792,0,1,47,0,59931,64,0,1,0,0,'','OR Spawn of creature with entry 166792 requires Quest 59931 is not Rewarded'), -- Mithdran "Standing"
(32,5,166797,0,1,47,0,59931,64,0,1,0,0,'','OR Spawn of creature with entry 166797 requires Quest 59931 is not Rewarded'), -- Lana Jordan "Standing"
(32,5,166784,0,0,47,0,59930,1,0,0,0,0,'','Spawn of creature with entry 166784 requires Quest 59930 not taken'), -- Grunt Throg
(32,5,166800,0,0,47,0,59930,1,0,0,0,0,'','Spawn of creature with entry 166800 requires Quest 59930 not taken'), -- Provisioner Jin'hake
(32,5,166906,0,0,1,0,325075,0,0,1,0,0,'','Spawn of creature with entry 166906 requires Player not have aura 325075'); -- Warlord Grimaxe
