SET @CGUID := 7000546;
SET @OGUID := 7000196;

DELETE FROM `phase_name` WHERE `ID`=12875;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(12875, 'Cosmetic: Kul Tiran Unlock Questline - Princess Ritual Circle');

DELETE FROM `phase_area` WHERE `PhaseId`=12875;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(9500, 12875, 'Cosmetic: Kul Tiran Unlock Questline - Princess Ritual Circle - Bleak Hills Mine'),
(9432, 12875, 'Cosmetic: Kul Tiran Unlock Questline - Princess Ritual Circle - Watchman''s Rise');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 26) AND (`SourceGroup` IN (12875));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(26, 12875, 0, 0, 0, 47, 0, 54729, 66, 0, '', 0, 'Player have The Bleak Hills (54729) in state complete, rewarded');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 122675, 1643, 8721, 9500, '0', 12875, 0, 0, 0, 158.14410400390625, 3203.5703125, 283.26190185546875, 1.059980154037475585, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Mayor Striggs (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@CGUID+1, 122674, 1643, 8721, 9500, '0', 12875, 0, 0, 0, 159.8194427490234375, 3206.41748046875, 283.436004638671875, 4.174034595489501953, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Trunksy (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@CGUID+2, 122676, 1643, 8721, 9500, '0', 12875, 0, 0, 0, 157.78472900390625, 3205.729248046875, 283.305145263671875, 6.135634422302246093, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847), -- Mr. Munchykins (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@CGUID+3, 150931, 1643, 8721, 9500, '0', 12875, 0, 0, 0, 160.609375, 3203.78564453125, 283.396942138671875, 4.181849002838134765, 120, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54847); -- Princess (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1 (Auras: 35356 - Spawn Feign Death, 167641 - Blood Splatter)

DELETE FROM `creature_template_addon` WHERE `entry` IN (150931);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(150931, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '35356 167641'); -- 150931 (Princess) - Spawn Feign Death, Blood Splatter

UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=122674 AND `DifficultyID`=0); -- 122674 (Trunksy) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=122675 AND `DifficultyID`=0); -- 122675 (Mayor Striggs) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=54847 WHERE (`Entry`=122676 AND `DifficultyID`=0); -- 122676 (Mr. Munchykins) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=674, `StaticFlags1`=268435456, `VerifiedBuild`=54847 WHERE (`Entry`=150931 AND `DifficultyID`=0); -- 150931 (Princess) - CanSwim

UPDATE `creature_template` SET `faction`=2908, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=150931; -- Princess
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=122676; -- Mr. Munchykins
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=122674; -- Trunksy
UPDATE `creature_template` SET `unit_flags3`=16777216 WHERE `entry`=122675; -- Mayor Striggs

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 270959, 1643, 8721, 9500, '0', 12875, 0, 158.1961822509765625, 3205.5625, 283.238739013671875, 0, 0, 0, 0, 1, 120, 255, 1, 54847), -- Tea Cup (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+1, 270959, 1643, 8721, 9500, '0', 12875, 0, 159.513885498046875, 3205.887939453125, 283.318511962890625, 0.070231571793556213, 0, 0, 0.035108566284179687, 0.999383509159088134, 120, 255, 1, 54847), -- Tea Cup (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+2, 270959, 1643, 8721, 9500, '0', 12875, 0, 160.9635467529296875, 3205.267333984375, 283.359893798828125, 0, 0, 0, 0, 1, 120, 255, 1, 54847), -- Tea Cup (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+3, 270959, 1643, 8721, 9500, '0', 12875, 0, 158.4461822509765625, 3204.0947265625, 283.2071533203125, 6.05180215835571289, 0, 0, -0.1154336929321289, 0.99331521987915039, 120, 255, 1, 54847), -- Tea Cup (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+4, 270959, 1643, 8721, 9500, '0', 12875, 0, 159.69097900390625, 3202.924560546875, 283.237945556640625, 0, 0, 0, 0, 1, 120, 255, 1, 54847), -- Tea Cup (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1
(@OGUID+5, 270961, 1643, 8721, 9500, '0', 12875, 0, 158.548614501953125, 3205.1572265625, 283.295440673828125, 2.537331819534301757, -0.01258182525634765, -0.01857185363769531, 0.95450592041015625, 0.297346949577331542, 120, 255, 1, 54847); -- Summoning Circle (Area: Bleak Hills Mine - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (270961 /*Summoning Circle*/, 270959 /*Tea Cup*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(270961, 0, 16, 0, 0), -- Summoning Circle
(270959, 0, 16, 0, 0); -- Tea Cup

UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54847 WHERE `entry`=270959; -- Tea Cup
UPDATE `gameobject_template` SET `ContentTuningId`=186, `VerifiedBuild`=54847 WHERE `entry`=270961; -- Summoning Circle

-- 
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (76045, 90959);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(76045, 1, 0, 0, 54847),
(90959, 0.208000004291534423, 1.5, 0, 54847);

UPDATE `creature_model_info` SET `VerifiedBuild`=54847 WHERE `DisplayID` IN (85031, 80768, 80734, 80767, 85177, 81872, 85178, 83050, 81868, 4602, 58145, 85311, 76674, 11686, 58170, 76677, 84850, 16358, 16356, 62863, 81890, 81079, 84041, 90950, 21342, 34168, 83309, 82393, 27823, 26774, 21072, 82382);
UPDATE `creature_model_info` SET `BoundingRadius`=0.579470038414001464, `VerifiedBuild`=54847 WHERE `DisplayID`=62862;
UPDATE `creature_model_info` SET `BoundingRadius`=0.829031646251678466, `CombatReach`=1.5, `VerifiedBuild`=54847 WHERE `DisplayID`=79807;
UPDATE `creature_model_info` SET `BoundingRadius`=1.847487092018127441, `VerifiedBuild`=54847 WHERE `DisplayID`=80962;
UPDATE `creature_model_info` SET `BoundingRadius`=1.288943290710449218, `CombatReach`=0.60000002384185791, `VerifiedBuild`=54847 WHERE `DisplayID`=35688;

DELETE FROM `gameobject_template` WHERE `entry` IN (322651 /*Storage Crate*/, 322641 /*[DNT] Dog House*/, 322642 /*[DNT] Scattered Hay*/, 322640 /*[DNT] Dog Ball*/, 322654 /*[DNT] Ore*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(322651, 2, 47100, 'Storage Crate', '', '', '', 2, 1634, 21951, 0, 0, 0, 0, 0, 0, 0, 0, 68034, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 674, 54847), -- Storage Crate
(322641, 5, 15511, '[DNT] Dog House', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- [DNT] Dog House
(322642, 5, 51280, '[DNT] Scattered Hay', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- [DNT] Scattered Hay
(322640, 5, 32607, '[DNT] Dog Ball', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54847), -- [DNT] Dog Ball
(322654, 5, 43646, '[DNT] Ore', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 54847); -- [DNT] Ore

UPDATE `gameobject_template` SET `ContentTuningId`=467, `VerifiedBuild`=54847 WHERE `entry`=289331; -- Perfect Telescope Location
UPDATE `gameobject_template` SET `VerifiedBuild`=54847 WHERE `entry` IN (276617, 276622, 284422, 278399, 276618, 325418, 281079, 288175, 288174, 288170, 288166, 288164, 288162, 288161, 278848, 288490, 288489, 293438, 281137, 277419, 276239, 276236, 288198, 322639, 281356, 281174, 276616, 322643, 278475, 276238, 276619, 294125, 288491, 288488);
UPDATE `gameobject_template` SET `ContentTuningId`=805, `VerifiedBuild`=54847 WHERE `entry`=297947; -- Falconer's Whistle
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=298858; -- Wanted Poster
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=281326; -- Falcon Cage
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=54847 WHERE `entry`=287255; -- Anvil
UPDATE `gameobject_template` SET `Data19`=2, `ContentTuningId`=705, `VerifiedBuild`=54847 WHERE `entry`=297825; -- Web-Covered Chest
UPDATE `gameobject_template` SET `ContentTuningId`=187, `VerifiedBuild`=54847 WHERE `entry`=280802; -- Silver Nugget
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=54847 WHERE `entry`=290464; -- Forge
