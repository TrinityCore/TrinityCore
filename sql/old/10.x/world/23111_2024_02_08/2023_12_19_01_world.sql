-- Add spawns to Darkmaul Plains to complete quest "Down with the Quilboar" and "Forbidden Quilboar Necromancy"
SET @CGUID := 8000014;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID,167020,2175,10424,10588,'0',15316,0,-1,0,0,99.48264,-2420.8645,90.37675,0.7511147,120,0,0,1,0,0,NULL,NULL,50000), -- Mithdran Dawntracker
(@CGUID+1,167021,2175,10424,10588,'0',15315,0,-1,0,1,102.61285,-2420.632,90.200554,3.240396,120,0,0,1,0,0,NULL,NULL,50000), -- Warlord Breka Grimaxe
(@CGUID+2,167019,2175,10424,10588,'0',15318,0,-1,0,0,100.56077,-2418.0713,90.41125,4.50382,120,0,0,1,0,0,NULL,NULL,50000), -- Cork Fizzlepop
(@CGUID+3,149915,2175,10424,10588,'0',13780,0,-1,0,0,99.48264,-2420.8645,90.37675,0.7511147,120,0,0,1,0,0,NULL,NULL,50000), -- Austin Huxworth
(@CGUID+4,156280,2175,10424,10588,'0',13779,0,-1,0,1,102.61285,-2420.632,90.200554,3.240396,120,0,0,1,0,0,NULL,NULL,50000), -- Captain Garrick
(@CGUID+5,149899,2175,10424,10588,'0',13776,0,-1,0,0,100.56077,-2418.0713,90.41125,4.50382,120,0,0,1,0,0,NULL,NULL,50000); -- Lindie Springstock

UPDATE `creature_template` SET `unit_flags2`=2048 WHERE `entry` IN (149899);
UPDATE `creature_template` SET `unit_flags2`=4196352 WHERE `entry` IN (149915);
UPDATE `creature_template` SET `npcflag`=2, `faction`=35 WHERE `entry` IN (149915,149899);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (15316, 15315, 15318, 13780, 13779, 13776) AND `SourceEntry` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,15316,0,0,0,47,0,59939,66,0,0,0,0,'','Apply Phase 15316 if Quest 59939 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,15316,0,0,1,47,0,59938,66,0,0,0,0,'','Apply Phase 15316 if Quest 59938 (Down with the Quilboar) is completed or rewarded'),
(26,15315,0,0,0,47,0,59939,66,0,0,0,0,'','Apply Phase 15315 if Quest 59939 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,15318,0,0,0,47,0,59939,66,0,0,0,0,'','Apply Phase 15318 if Quest 59939 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,13780,0,0,0,47,0,55184,66,0,0,0,0,'','Apply Phase 13780 if Quest 55184 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,13780,0,0,1,47,0,55186,66,0,0,0,0,'','Apply Phase 13780 if Quest 55186 (Down with the Quilboar) is completed or rewarded'),
(26,13779,0,0,0,47,0,55184,66,0,0,0,0,'','Apply Phase 13779 if Quest 55184 (Forbidden Quilboar Necromancy) is completed or rewarded'),
(26,13776,0,0,0,47,0,55184,66,0,0,0,0,'','Apply Phase 13776 if Quest 55184 (Forbidden Quilboar Necromancy) is completed or rewarded');

DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (15316,15315,15318,13780,13779,13776);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10424,15316, 'Cosmetic - NPE - Mithdran Dawntracker at Darkmaul Plains'),
(10424,15315, 'Cosmetic - NPE - Warlord Breka Grimaxe at Darkmaul Plains'),
(10424,15318, 'Cosmetic - NPE - Cork Fizzlepop at Darkmaul Plains'),
(10424,13780, 'Cosmetic - NPE - Austin Huxworth at Darkmaul Plains'),
(10424,13779, 'Cosmetic - NPE - Captain Garrick at Darkmaul Plains'),
(10424,13776, 'Cosmetic - NPE - Lindie Springstock at Darkmaul Plains');

DELETE FROM `phase_name` WHERE `ID` IN (15316,15315,15318,13780,13779,13776);
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(15316, 'Cosmetic - See Mithran Dawntracker at Darkmaul Plains'),
(15315, 'Cosmetic - See Warlord Breka Grimaxe at Darkmaul Plains'),
(15318, 'Cosmetic - See Cork Fizzlepop at Darkmaul Plains'),
(13780, 'Cosmetic - See Austin Huxworth at Darkmaul Plains'),
(13779, 'Cosmetic - See Captian Garrick at Darkmaul Plains'),
(13776, 'Cosmetic - See Lindie Springstock at Darkmaul Plains');
