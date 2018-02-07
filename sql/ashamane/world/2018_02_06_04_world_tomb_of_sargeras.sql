SET @CGUID := 21004592;
SET @OGUID := 21001519;

DELETE FROM `areatrigger_template` WHERE `Id` IN (15028, 14886, 13069, 15226, 15286, 15243, 15115);
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(15028, 0, 0, 200, 200, 0, 0, 0, 0, 25961),
(14886, 0, 0, 50, 50, 0, 0, 0, 0, 25961),
(13069, 0, 0, 8, 8, 0, 0, 0, 0, 25961),
(15226, 0, 4, 8, 8, 0, 0, 0, 0, 25961),
(15286, 0, 4, 300, 300, 0, 0, 0, 0, 25961),
(15243, 0, 4, 300, 300, 0, 0, 0, 0, 25961),
(15115, 0, 4, 3, 3, 0, 0, 0, 0, 25961);

UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=12367;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=11420;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10205;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=9225;
UPDATE `areatrigger_template` SET `Type`=0, `Data0`=4, `Data1`=4, `Data2`=0, `Data3`=0, `Data4`=0, `Data5`=0 WHERE `Id`=6197;
UPDATE `areatrigger_template` SET `Data2`=7.5, `Data5`=7.5, `VerifiedBuild`=25961 WHERE `Id`=9448;
UPDATE `areatrigger_template` SET `Flags`=2 WHERE `Id`=9397;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10693;
UPDATE `areatrigger_template` SET `VerifiedBuild`=25961 WHERE `Id`=10665;

DELETE FROM `spell_areatrigger` WHERE (`AreaTriggerId`=5300) OR (`AreaTriggerId`=5302) OR (`SpellMiscId`=5503 AND `AreaTriggerId`=10205) OR (`AreaTriggerId`=14886) OR (`AreaTriggerId`=15028) OR (`SpellMiscId`=9025 AND `AreaTriggerId`=13069) OR (`SpellMiscId`=8430 AND `AreaTriggerId`=6197) OR (`SpellMiscId`=4714 AND `AreaTriggerId`=9448) OR (`SpellMiscId`=10366 AND `AreaTriggerId`=15226) OR (`AreaTriggerId`=15243) OR (`AreaTriggerId`=15286) OR (`SpellMiscId`=10237 AND `AreaTriggerId`=15115) OR (`AreaTriggerId`=16670);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(1315, 5300, 392, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(1316, 5302, 393, 0, 0, 0, 0, 1550, 1000, 25961), -- SpellId : 123986
(5503, 10205, 0, 0, 0, 0, 0, 1932, 3000, 25961), -- SpellId : 199121
(10003, 14886, 0, 0, 0, 0, 0, 0, 60000, 25961), -- SpellId : 239130
(10160, 15028, 0, 0, 0, 0, 0, 0, 60000, 25961), -- SpellId : 239130
(9025, 13069, 0, 0, 0, 0, 0, 0, 20000, 25961), -- SpellId : 225126
(8430, 6197, 0, 0, 0, 0, 70, 0, 1000, 25961), -- SpellId : 224399
(4714, 9448, 0, 0, 0, 0, 0, 1500, 10000, 25961), -- SpellId : 190778
(10366, 15226, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 241768
(10383, 15243, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 241983
(10430, 15286, 0, 0, 0, 0, 0, 0, 0, 25961), -- SpellId : 241983
(10237, 15115, 0, 0, 0, 0, 0, 0, 0, 25961); -- SpellId : 234295
-- (UNKNOWN, 16670, 0, 0, 0, 0, 0, 1910, 6000, 25961); -- SpellId : 256948

UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=8140 AND `AreaTriggerId`=12367); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2800, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7267 AND `AreaTriggerId`=11721); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=3000 WHERE (`SpellMiscId`=10533 AND `AreaTriggerId`=15386); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=6026 AND `AreaTriggerId`=10713); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=8284 AND `AreaTriggerId`=6197); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6878 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=4485 AND `AreaTriggerId`=9225); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7478 AND `AreaTriggerId`=11908); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5847 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2271, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4569 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5940 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=304 AND `AreaTriggerId`=2947); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=30000 WHERE (`SpellMiscId`=373 AND `AreaTriggerId`=3282); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=2329 AND `AreaTriggerId`=6870); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=10000 WHERE (`SpellMiscId`=1524 AND `AreaTriggerId`=5972); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=14000 WHERE (`SpellMiscId`=7044 AND `AreaTriggerId`=11513); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=7240 AND `AreaTriggerId`=11692); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2940, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2849, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2267, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2113, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2110, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2485, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2484, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1818, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7999, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=5290 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2488, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1800, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2486, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2507, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3789, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3808, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2700, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=7998, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6917 AND `AreaTriggerId`=11420); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=4498 WHERE (`SpellMiscId`=4658 AND `AreaTriggerId`=9397); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1950, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=6607 WHERE (`SpellMiscId`=5420 AND `AreaTriggerId`=10133); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2803, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1764, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=3069, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=45, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=2801, `TimeToTargetScale`=15000 WHERE (`SpellMiscId`=8661 AND `AreaTriggerId`=12740); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=1541, `TimeToTargetScale`=0 WHERE (`SpellMiscId`=10415 AND `AreaTriggerId`=15273); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=6711 AND `AreaTriggerId`=10693); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=0, `VerifiedBuild`=25961 WHERE (`SpellMiscId`=5977 AND `AreaTriggerId`=10665); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12204 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=2000 WHERE (`SpellMiscId`=6039 AND `AreaTriggerId`=10727); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=0, `TimeToTargetScale`=12935 WHERE (`SpellMiscId`=4488 AND `AreaTriggerId`=9228); -- SpellId : 0
UPDATE `spell_areatrigger` SET `DecalPropertiesId`=0, `TimeToTarget`=5000, `TimeToTargetScale`=5000 WHERE (`SpellMiscId`=6006 AND `AreaTriggerId`=10698); -- SpellId : 0

DELETE FROM `conversation_actors` WHERE (`ConversationId`=5170 AND `ConversationActorId`=58365 AND `Idx`=0) OR (`ConversationId`=5048 AND `Idx`=0) OR (`ConversationId`=5048 AND `Idx`=1);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `VerifiedBuild`) VALUES
(5170, 58365, 0, 25961);
-- (5048, UNKNOWN, 0, 25961), -- Full: 0x0
-- (5048, UNKNOWN, 1, 25961); -- Full: 0x0


DELETE FROM `conversation_actor_template` WHERE `Id`=58365;
INSERT INTO `conversation_actor_template` (`Id`, `CreatureId`, `CreatureModelId`, `VerifiedBuild`) VALUES
(58365, 121227, 27571, 25961);


DELETE FROM `conversation_line_template` WHERE `Id` IN (11566, 11268, 11267, 11266, 11265, 11264, 11263, 11262);
INSERT INTO `conversation_line_template` (`Id`, `StartTime`, `UiCameraID`, `ActorIdx`, `Unk`, `VerifiedBuild`) VALUES
(11566, 0, 297, 0, 0, 25961),
(11268, 52534, 3, 0, 0, 25961),
(11267, 40369, 3, 1, 0, 25961),
(11266, 37086, 3, 0, 0, 25961),
(11265, 23260, 3, 1, 0, 25961),
(11264, 14929, 3, 0, 0, 25961),
(11263, 7890, 3, 1, 0, 25961),
(11262, 0, 3, 0, 0, 25961);


DELETE FROM `conversation_template` WHERE `Id` IN (5170, 5048);
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `LastLineEndTime`, `VerifiedBuild`) VALUES
(5170, 11566, 5409, 25961),
(5048, 11262, 68025, 25961);


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (268969 /*Porte ancienne*/, 271099 /*Butin de la chute de la Légion*/, 269255 /*269255*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(268969, 0, 32), -- Porte ancienne
(271099, 94, 2113568), -- Butin de la chute de la Légion
(269255, 0, 48); -- 269255


DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+289;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 117744, 1220, 0, 0, 1, '0', 0, 0, 0, -1340.535, 3185.095, 11.45956, 0.4766193, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fel Slime (Area: -Unknown- - Difficulty: Normal) (Auras: 234156 -)
(@CGUID+1, 120667, 1220, 0, 0, 1, '0', 0, 0, 0, -1390.38, 3160.897, 21.8239, 5.178132, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legion Venomretcher (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+2, 120674, 1220, 0, 0, 1, '0', 0, 0, 0, -1263.087, 3185.81, 8.532261, 0.603483, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Rotwing Ripper (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+3, 120666, 1220, 0, 0, 1, '0', 0, 0, 0, -1390.38, 3160.897, 21.8239, 2.292402, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legion Webspewer (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+4, 120575, 1220, 0, 0, 1, '0', 0, 0, 0, -1356.099, 3219.542, 16.48162, 5.447063, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Hungering Stalker (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+5, 120667, 1220, 0, 0, 1, '0', 0, 0, 0, -1390.38, 3160.897, 21.8239, 0.237358, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legion Venomretcher (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+6, 120668, 1220, 0, 0, 1, '0', 0, 0, 0, -1390.38, 3160.897, 21.8239, 4.647319, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spellstalker (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+7, 120666, 1220, 0, 0, 1, '0', 0, 0, 0, -1390.38, 3160.897, 21.8239, 1.08144, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legion Webspewer (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+8, 120667, 1220, 0, 0, 1, '0', 0, 0, 0, -1390.38, 3160.897, 21.8239, 2.292402, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Legion Venomretcher (Area: -Unknown- - Difficulty: Normal) (Auras: 241418 - Sentinax Portal Dissolve In)
(@CGUID+9, 117793, 1220, 0, 0, 1, '0', 0, 0, 0, -1251.429, 3273.335, 37.16622, 1.792547, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fledgling Fel Bat (Area: -Unknown- - Difficulty: Normal)
(@CGUID+10, 117793, 1220, 0, 0, 1, '0', 0, 0, 0, -1254.181, 3275.307, 37.16622, 4.327013, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fledgling Fel Bat (Area: -Unknown- - Difficulty: Normal)
(@CGUID+11, 119605, 1220, 0, 0, 1, '0', 0, 0, 0, -1288.296, 3295.127, 20.36378, 3.727003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Racleur-d'os des clos (Area: -Unknown- - Difficulty: Normal)
(@CGUID+12, 117793, 1220, 0, 0, 1, '0', 0, 0, 0, -1255.796, 3277.379, 37.16622, 4.980424, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fledgling Fel Bat (Area: -Unknown- - Difficulty: Normal)
(@CGUID+13, 117744, 1220, 0, 0, 1, '0', 0, 0, 0, -1250.741, 3126.702, 0.9697781, 0.6199192, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fel Slime (Area: -Unknown- - Difficulty: Normal) (Auras: 234156 -)
(@CGUID+14, 117793, 1220, 0, 0, 1, '0', 0, 0, 0, -1338.454, 3083.717, 19.58806, 2.740663, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fledgling Fel Bat (Area: -Unknown- - Difficulty: Normal)
(@CGUID+15, 117793, 1220, 0, 0, 1, '0', 0, 0, 0, -1344.644, 3082.454, 19.58806, 5.924117, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fledgling Fel Bat (Area: -Unknown- - Difficulty: Normal)
(@CGUID+16, 117793, 1220, 0, 0, 1, '0', 0, 0, 0, -1353.268, 3085.258, 19.58806, 4.795359, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fledgling Fel Bat (Area: -Unknown- - Difficulty: Normal)
(@CGUID+17, 117502, 1220, 0, 0, 1, '0', 0, 0, 0, -1334.4, 3072.675, 2.175197, 3.308296, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Resilient Roach (Area: -Unknown- - Difficulty: Normal) (Auras: 233898 -)
(@CGUID+18, 117502, 1220, 0, 0, 1, '0', 0, 0, 0, -1331.987, 3072.954, 2.257737, 4.682261, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Resilient Roach (Area: -Unknown- - Difficulty: Normal) (Auras: 233898 -)
(@CGUID+19, 117744, 1220, 0, 0, 1, '0', 0, 0, 0, -1358.594, 3074.346, 2.469414, 4.004539, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fel Slime (Area: -Unknown- - Difficulty: Normal) (Auras: 234156 -)
(@CGUID+20, 117502, 1220, 0, 0, 1, '0', 0, 0, 0, -1331.277, 3074.343, 2.431356, 4.529229, 120, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Resilient Roach (Area: -Unknown- - Difficulty: Normal) (Auras: 233898 -)
(@CGUID+21, 121790, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4482.105, -1144.714, 5335.589, 1.440132, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
(@CGUID+22, 121790, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4516.259, -1142.462, 5335.698, 2.249489, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
(@CGUID+23, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4498.442, -1191.349, 5335.589, 1.54833, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+24, 117782, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4489.932, -1209.13, 5335.796, 1.571218, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eredar Bloodmage (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+25, 121790, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4519.99, -1242.01, 5335.613, 1.928955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
(@CGUID+26, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4483.114, -1150.552, 5335.589, 1.396303, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+27, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4492.552, -1243.979, 5335.589, 1.251166, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+28, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4505.845, -1189.365, 5335.589, 1.610156, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+29, 117782, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4494.804, -1214.411, 5335.589, 1.639367, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eredar Bloodmage (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+30, 121790, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4479.742, -1243.168, 5335.501, 1.271495, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
(@CGUID+31, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4492.269, -1155.623, 5335.589, 1.650733, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+32, 117782, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4488.268, -1179.995, 5335.826, 0.7300619, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eredar Bloodmage (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+33, 117769, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4499.286, -1209.573, 5335.589, 1.550394, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felborne Spellbreaker (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+34, 118930, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4500.417, -1260.648, 5335.589, 1.605967, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ixallon the Soulbreaker (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+35, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4508.486, -1246.852, 5335.589, 1.535786, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+36, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4492.331, -1188.076, 5335.589, 1.501203, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+37, 111221, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4500.309, -1129.993, 5336.051, 6.257005, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Xal'atath (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+38, 117782, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4504.074, -1214.352, 5335.589, 1.46816, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eredar Bloodmage (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+39, 121790, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4501.226, -1238.295, 5335.589, 1.575078, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
(@CGUID+40, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4516.993, -1152.186, 5335.589, 2.0019, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+41, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4508.543, -1234.913, 5335.99, 1.76075, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+42, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4507.589, -1155.16, 5335.589, 1.791319, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+43, 117782, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4509.694, -1179.031, 5335.589, 2.668085, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eredar Bloodmage (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+44, 117769, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4499.376, -1180.064, 5335.589, 1.578493, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Felborne Spellbreaker (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+45, 117782, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4507.823, -1209.852, 5335.589, 1.727725, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eredar Bloodmage (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+46, 117776, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4494.275, -1233.931, 5335.589, 1.456186, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadow Council Warlock (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+47, 121789, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4517.087, -1471.94, 5392.369, 0.006137203, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Beam Target Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 243291 -)
(@CGUID+48, 121788, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4470.776, -1472.106, 5395.536, 0.008966863, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Kil'jaeden (Area: Néant distordu - Difficulty: Outil Raids)
(@CGUID+49, 118052, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4535.912, -1471.825, 5385.613, 3.125709, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Prophète Velen (Area: Néant distordu - Difficulty: Outil Raids)
-- (@CGUID+50, 32639, UNKNOWN, 8524, 8541, 245760, '0', 0, 0, 0, 0, 0, 0, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Gnimo (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 61424 - Mammouth de voyage de la toundra) - !!! on transport - transport template not found !!!
(@CGUID+51, 117269, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4498.629, -1562.2, 5433.555, 1.614597, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Kil'jaeden (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
-- (@CGUID+52, 32639, UNKNOWN, 8524, 8541, 245760, '0', 0, 0, 0, 0, 0, 0, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Gnimo (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 61424 - Mammouth de voyage de la toundra) - !!! on transport - transport template not found !!!
(@CGUID+53, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4547.418, -1415.125, 5387.061, 4.353286, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+54, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+55, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4493.547, -1483.677, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+56, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4534.465, -1488.385, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+57, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4531.458, -1537.094, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+58, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4497.648, -1510.65, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+59, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4512.885, -1517.006, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+60, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4467.389, -1476.175, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+61, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4545.475, -1420.304, 5387.06, 4.353286, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+62, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+63, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4548.733, -1417.153, 5386.957, 4.240216, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+64, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+65, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4475.604, -1528.401, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+66, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4473.56, -1497.837, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+67, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4511.496, -1489.634, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+68, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4500.878, -1492.53, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+69, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4517.839, -1481.179, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+70, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4492.229, -1537.269, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+71, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4545.519, -1420.186, 5387.06, 4.353286, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+72, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+73, 92870, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4511.94, -1534.646, 5395.729, 2.627344, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Sindragosa's Fury (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
(@CGUID+74, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4547.418, -1415.125, 5387.061, 4.353286, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+75, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+76, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4548.959, -1409.591, 5387.06, 4.261624, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+77, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+78, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4527.975, -1513.946, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+79, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4481.153, -1488.133, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+80, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4503.913, -1528.833, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+81, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4502.453, -1504.554, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+82, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4466.346, -1477.59, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+83, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4487.312, -1523.672, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+84, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+85, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4543.125, -1416.404, 5387.06, 4.394163, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+86, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+87, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4496.355, -1543.04, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+88, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4487.477, -1480.984, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+89, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4470.688, -1534.708, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+90, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4475.089, -1484.667, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+91, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4509.224, -1518.975, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+92, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4501.467, -1531.943, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+93, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4546.392, -1414.896, 5387.061, 4.261686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+94, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+95, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4540.212, -1425.248, 5387.061, 4.394098, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+96, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+97, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4540.212, -1425.248, 5387.061, 4.394098, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+98, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+99, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+100, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4541.367, -1421.742, 5387.06, 4.394184, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+101, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+102, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4543.099, -1416.483, 5387.06, 4.394163, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+103, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+104, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4542.322, -1426.272, 5387.061, 4.099434, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+105, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+106, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4483.136, -1534.979, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+107, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4498.619, -1486.786, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+108, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4506.2, -1519.555, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+109, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4469.399, -1515.554, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+110, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4488.919, -1518.53, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+111, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4465.924, -1495.166, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+112, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+113, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+114, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4485.666, -1489.888, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+115, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4533.027, -1504.864, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+116, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4501.604, -1522.626, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+117, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4480.605, -1489.244, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+118, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4493.661, -1488.876, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+119, 120839, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4468.235, -1530.469, 5385.993, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Armageddon Stalker (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 234295 - Pluie d'armageddon)
(@CGUID+120, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4541.362, -1421.755, 5387.06, 4.394184, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+121, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+122, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4546.435, -1414.808, 5387.061, 4.261686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+123, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+124, 121193, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4471.054, -1504.927, 5385.743, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadowsoul (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 241905 -)
(@CGUID+125, 121193, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4490.624, -1512.307, 5385.744, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadowsoul (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 241905 -)
(@CGUID+126, 121193, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4508.988, -1512.8, 5385.744, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadowsoul (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 241905 -)
(@CGUID+127, 121193, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4483.716, -1552.947, 5385.744, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadowsoul (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 241905 -)
(@CGUID+128, 121193, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4518.058, -1533.235, 5385.744, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Shadowsoul (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 241905 -)
(@CGUID+129, 121227, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4485.779, -1480.31, 5385.743, 0.08619744, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Illidan Hurlorage (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 241768 - Vision maudite)
(@CGUID+130, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4548.733, -1417.153, 5386.957, 4.240216, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+131, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 5.17837, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+132, 92870, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4484.968, -1483.741, 5395.728, 5.217893, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Sindragosa's Fury (Area: Néant distordu - Difficulty: Outil Raids) (Auras: )
(@CGUID+133, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+134, 120390, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4545.661, -1451.322, 5385.993, 0.07082967, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nether Rift (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 240020 - Ouverture de faille)
(@CGUID+135, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4544.527, -1425.388, 5387.06, 4.240211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+136, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+137, 120270, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4524, -1543.536, 5385.744, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fulminating Sphere (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 239785 - Obélisque démoniaque)
(@CGUID+138, 120270, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4542.951, -1552.984, 5385.743, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fulminating Sphere (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 239785 - Obélisque démoniaque)
(@CGUID+139, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+140, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+141, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4544.527, -1425.388, 5387.06, 4.240211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+142, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+143, 120270, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4542.951, -1552.984, 5385.743, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fulminating Sphere (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 239785 - Obélisque démoniaque)
(@CGUID+144, 120270, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4467.146, -1496.295, 5385.743, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fulminating Sphere (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 239785 - Obélisque démoniaque)
(@CGUID+145, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+146, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4542.829, -1422.092, 5387.06, 4.528864, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+147, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4456.675, -1419.558, 5387.06, 4.568561, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+148, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4542.803, -1422.229, 5387.06, 4.528864, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+149, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+150, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4544.527, -1425.388, 5387.06, 4.240211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+151, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+152, 120390, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4439.598, -1479.194, 5385.993, 0.1013605, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nether Rift (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 240020 - Ouverture de faille)
(@CGUID+153, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4551.353, -1404.646, 5386.804, 4.353405, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+154, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+155, 120270, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4533.475, -1477.398, 5385.743, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fulminating Sphere (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 239785 - Obélisque démoniaque)
(@CGUID+156, 120270, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4495.573, -1524.639, 5385.744, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fulminating Sphere (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 239785 - Obélisque démoniaque)
(@CGUID+157, 120270, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4486.098, -1467.95, 5385.744, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fulminating Sphere (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 239785 - Obélisque démoniaque)
(@CGUID+158, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4548.733, -1417.153, 5386.957, 4.240216, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+159, 124598, 1676, 8524, 8541, 245760, '0', 0, 0, 0, 4457.01, -1417.241, 5386.957, 4.568571, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Fleetlord Dominator (Area: Néant distordu - Difficulty: Outil Raids) (Auras: 235664 - Dissolution de gangrène)
(@CGUID+160, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -319.2257, 6165.409, 47.70812, 4.028192, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 197644 - Prison de givre)
(@CGUID+161, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -370.4514, 5748.969, 52.75683, 5.282787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+162, 89802, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -106.3385, 5919.382, 10.53101, 5.838396, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Skrog glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+163, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -93.90972, 6172.157, 4.750755, 2.905671, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+164, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -256.4462, 5837.866, 87.49183, 3.341101, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+165, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -60.30382, 6130.637, 25.81359, 6.117375, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+166, 62050, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -452.842, 5814.615, 47.80593, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Phalène gris (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+167, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -265.474, 5828.315, 83.26563, 3.676737, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+168, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -264.9566, 6188.304, 41.26854, 0.20535, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+169, 64782, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -388.7049, 5778.684, 48.00536, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Raton voleur (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+170, 55370, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -114.0365, 5780.39, 0.993989, 4.381642, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- General Purpose Bunny ZTO (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+171, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -60.96875, 6129.318, 25.81358, 6.214316, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+172, 89025, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -141.6667, 5755.331, 6.6925, 2.185618, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Persifide glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+173, 120265, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -249.8455, 5946.56, 166.2993, 1.614195, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Spirit of Netrezaar (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+174, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -319.2639, 6162.542, 47.70889, 3.721499, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 197644 - Prison de givre)
(@CGUID+175, 89811, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -75.70834, 5733.48, -0.8559028, 3.923505, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Subjugated Murloc (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+176, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -157.6302, 6005.299, 48.52044, 5.8344, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+177, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -299.2066, 6175.686, 48.19957, 4.700284, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+178, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -188.6754, 5794.611, 29.41686, 3.935445, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+179, 89891, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -152.7674, 5793.538, 13.68773, 5.598835, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tortue-dragon (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+180, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -119.3837, 6155.938, 8.330256, 1.561145, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+181, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -107.6615, 6209.556, 2.421896, 3.030115, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+182, 91756, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -115.6649, 5985.446, 52.20134, 2.193023, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+183, 93725, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -370.0139, 5706.14, 49.78021, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Slithering Brownscale (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+184, 88087, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -149.2882, 6147.877, 15.18658, 1.412955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Imploratrice des tempêtes glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 179090 - Appeler la tempête)
(@CGUID+185, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -146.0729, 6028.429, 50.02313, 5.014557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+186, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -123.1233, 6031.619, 49.64745, 4.561609, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+187, 93714, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -153.6059, 5777.218, 11.46774, 6.279168, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Blog the Pale (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+188, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -54.46528, 6183.212, 5.917857, 2.967437, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+189, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -65.51041, 5806.345, 3.570446, 1.613016, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+190, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -402.3212, 5733.153, 42.14939, 5.14878, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+191, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -156.7674, 6011.658, 48.89611, 5.8344, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+192, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -81.60069, 6159.016, 5.562014, 2.872916, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+193, 89891, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -161.7118, 5783.417, 14.83689, 5.142713, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tortue-dragon (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+194, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -64.25174, 6127.656, 25.81359, 0.03685495, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+195, 89025, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -9.666667, 5877.406, 0.128956, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Persifide glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+196, 89811, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -180.7743, 5677.028, 18.1214, 0.5727586, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Subjugated Murloc (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: )
(@CGUID+197, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -148.0955, 6023.283, 48.89611, 5.23521, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+198, 122799, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -236.099, 5933.616, 166.0337, 2.369905, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Archmage Khadgar (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+199, 89811, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -181.6163, 5682.685, 18.25383, 5.301397, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Subjugated Murloc (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+200, 109351, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -390.6806, 5866.806, 51.8406, 0.2668796, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Veil Prowler (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+201, 117974, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -230.3889, 5936.467, 166.0337, 2.455797, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Illidan Hurlorage (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+202, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -233.4583, 6141.777, 42.51389, 3.448129, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+203, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -356.474, 5796.608, 62.41159, 0.9054538, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+204, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -121.7309, 6156.67, 8.580898, 1.505268, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+205, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -378.1788, 5722.104, 47.43474, 0.904964, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+206, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, 14.59549, 5920.833, -0.1002427, 0.7729686, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+207, 91756, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -102.1229, 5999.377, 52.06459, 5.475634, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+208, 91756, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -141.4583, 5995.662, 47.71333, 2.091338, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+209, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -326.0729, 6146.066, 48.04157, 1.201483, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+210, 89802, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -35.47396, 5899.313, -0.5394122, 1.071326, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Skrog glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+211, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -94.78472, 6157.456, 6.207642, 2.855665, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+212, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -278.9531, 5847.868, 87.95898, 5.975357, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+213, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -58.2882, 6128.878, 25.81358, 6.235681, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+214, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -325.5642, 5760.289, 65.62311, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+215, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -348.1094, 5927.683, 101.6573, 1.845928, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+216, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -125.816, 6029.643, 48.52044, 4.598037, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+217, 64782, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -296.0625, 5682.924, 63.14046, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Raton voleur (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+218, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -73.4184, 5775.286, 0.1413899, 2.706556, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+219, 89025, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -169.4653, 5735.214, 17.58333, 3.381696, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Persifide glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+220, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -62.38715, 6126.719, 25.81359, 0.09968638, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+221, 89811, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -78.26215, 5735.688, -0.8732639, 4.368237, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Subjugated Murloc (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+222, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -125.1545, 5756.416, 0.7569444, 1.457573, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+223, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -258.125, 6169.338, 41.27933, 0.2184133, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+224, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -159.5347, 5997.656, 49.27178, 0.2426821, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+225, 121728, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -249.8455, 5946.562, 166.2998, 5.610395, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Thal'kiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+226, 109351, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -358.3906, 5762.448, 55.31261, 4.55813, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Veil Prowler (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+227, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -315.1354, 6159.845, 47.7085, 3.366868, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 197644 - Prison de givre)
(@CGUID+228, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -60.82813, 5916.057, 2.813562, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+229, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -390.8767, 5831.698, 51.2268, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+230, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -333.4983, 6165.297, 48.04157, 0.06631271, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+231, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -75.31424, 6220.663, 2.480364, 3.079198, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+232, 122800, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -239.0295, 5928.674, 166.0337, 2.411677, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Prophète Velen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+233, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -388.5382, 5866.485, 52.55313, 4.58253, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie, 130966 - Feindre la mort permanent)
(@CGUID+234, 89025, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -96.42709, 5901.844, 5.988443, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Persifide glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+235, 91756, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -118.7344, 6010.531, 47.46583, 2.232679, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+236, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -294.6962, 6166.122, 48.19957, 2.821771, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+237, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -34.49479, 6185.238, 3.84602, 2.983352, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+238, 93725, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -309.1892, 5832.202, 83.58832, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Slithering Brownscale (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+239, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -294.6823, 6149.437, 48.04157, 2.868199, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+240, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -238.6545, 5692.392, 63.40128, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+241, 91459, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -197.6563, 6170.272, 3.42742, 3.831769, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Brute naga (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 217193 - Cogner le mur)
(@CGUID+242, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -225.1615, 6170.452, 41.1559, 2.024049, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+243, 89025, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -89.30209, 5875.472, 1.567682, 0.8356552, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Persifide glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+244, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -60.2309, 6125.255, 25.81359, 0.2179946, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+245, 62050, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -275.0191, 5700.821, 72.41766, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Phalène gris (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+246, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -272.8316, 5806.729, 82.34492, 3.041336, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+247, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -203.2726, 6181.108, 41.45826, 6.214541, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+248, 89891, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -161.2917, 5771.473, 13.55128, 0.4328404, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tortue-dragon (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+249, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -307.7986, 5814.46, 82.7869, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%; 221736 - Aura de léthargie)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -308.7101, 6154.42, 47.70896, 3.317421, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 197644 - Prison de givre)
(@CGUID+251, 55370, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -118.5521, 5782.088, 1.74369, 4.381642, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- General Purpose Bunny ZTO (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+252, 89025, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -176.4601, 5680.32, 17.97769, 2.75779, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Persifide glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+253, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -316.1684, 6154.654, 47.70838, 2.72482, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 197644 - Prison de givre)
(@CGUID+254, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -50.05035, 5811.752, 3.911055, 1.716058, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+255, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -239.2639, 6147.543, 42.1461, 3.574631, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+256, 109351, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -389.4306, 5930.24, 50.15389, 3.657763, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Veil Prowler (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+257, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -131.7969, 6027.03, 47.37604, 5.014557, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+258, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -234.0851, 5831.344, 90.90279, 4.488173, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+259, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -333.5833, 5829.038, 79.58211, 0, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+260, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -140.4774, 6025.159, 47.76917, 5.181767, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+261, 89891, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -79.79514, 5732.081, -0.8841279, 1.183369, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tortue-dragon (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 130966 - Feindre la mort permanent)
(@CGUID+262, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -84.92709, 6209.122, 2.705663, 3.037357, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+263, 89811, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -156.3142, 5738.434, 13.30382, 3.052975, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Subjugated Murloc (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+264, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -278.2066, 5825.984, 82.46712, 5.47688, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+265, 88087, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -189.4254, 6145.635, 41.42107, 1.879764, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Imploratrice des tempêtes glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 179090 - Appeler la tempête)
(@CGUID+266, 91756, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -142.3429, 6034.422, 51.9397, 3.660126, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+267, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -55.80556, 6210.76, 0.9193076, 3.051984, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+268, 89024, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -8.296875, 5945.601, -0.257939, 0.8500043, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Traqueur des fonds glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+269, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -289.7326, 5776.015, 80.2489, 1.590615, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+270, 105838, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -294.8021, 5790.721, 79.79837, 5.650218, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Redcrested Heron (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+271, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -61.56076, 6123.344, 25.81359, 0.3172448, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+272, 89811, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -82.21181, 5734.603, -0.9079862, 5.264056, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Subjugated Murloc (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+273, 109351, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -385.25, 5758.382, 47.31355, 4.55813, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Veil Prowler (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+274, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -300.4722, 6161.624, 47.70879, 3.408282, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+275, 89811, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -177.3837, 5674.837, 18.29585, 1.636481, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Subjugated Murloc (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+276, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -392.1059, 5824.078, 50.50047, 5.282787, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+277, 107447, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -38.8559, 6199.362, 1.6193, 3.022758, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Harponneur glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 213117 - Aura de canon glissefiel)
(@CGUID+278, 89891, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -154.9826, 5762.903, 11.25146, 0.3575038, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Tortue-dragon (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+279, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -391.2448, 5928.378, 49.50526, 2.234211, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie, 130966 - Feindre la mort permanent)
(@CGUID+280, 91756, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -191.4896, 6106.909, 41.31919, 1.584955, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Eternal Guardian (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+281, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -173.9066, 6172.279, 2.647958, 4.122855, 604800, 10, 0, 0, 0, 1, 0, 0, 0, 25961), -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids) (possible waypoints or random movement)
(@CGUID+282, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -215.3455, 6208.074, 41.45826, 1.347801, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+283, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -116.9618, 6162.152, 7.26071, 3.817031, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+284, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -480.6493, 5813.147, 32.61012, 3.33208, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+285, 109351, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -463.2847, 5777.998, 38.45946, 4.676489, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Veil Prowler (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+286, 88087, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -161.7674, 6172.676, 5.377944, 5.344304, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Imploratrice des tempêtes glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+287, 109349, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -480.6493, 5813.147, 32.61012, 3.33208, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Ombrecavale du voile (Area: Tombe de Sargeras - Difficulty: Outil Raids) (Auras: 123169 - Échelle : 105-110%, 221736 - Aura de léthargie)
(@CGUID+288, 88086, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -122.2674, 6164.356, 7.64131, 4.591702, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Caudelame glissefiel (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@CGUID+289, 89634, 1676, 7334, 8720, 245760, '0', 0, 0, 0, -147.0851, 6176.24, 4.919891, 1.709049, 604800, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- Nar'thalas Citizen (Area: Tombe de Sargeras - Difficulty: Outil Raids)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+289;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, '234156'), -- Fel Slime - 234156 -
(@CGUID+1, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- Legion Venomretcher - 241418 - Sentinax Portal Dissolve In
(@CGUID+2, 0, 0, 50331648, 1, 0, 0, 0, 0, '241418'), -- Rotwing Ripper - 241418 - Sentinax Portal Dissolve In
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- Legion Webspewer - 241418 - Sentinax Portal Dissolve In
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- Hungering Stalker - 241418 - Sentinax Portal Dissolve In
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- Legion Venomretcher - 241418 - Sentinax Portal Dissolve In
(@CGUID+6, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- Spellstalker - 241418 - Sentinax Portal Dissolve In
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- Legion Webspewer - 241418 - Sentinax Portal Dissolve In
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- Legion Venomretcher - 241418 - Sentinax Portal Dissolve In
(@CGUID+9, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fledgling Fel Bat
(@CGUID+10, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fledgling Fel Bat
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Racleur-d'os des clos
(@CGUID+12, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fledgling Fel Bat
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, '234156'), -- Fel Slime - 234156 -
(@CGUID+14, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fledgling Fel Bat
(@CGUID+15, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fledgling Fel Bat
(@CGUID+16, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Fledgling Fel Bat
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, '233898'), -- Resilient Roach - 233898 -
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, '233898'), -- Resilient Roach - 233898 -
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, '234156'), -- Fel Slime - 234156 -
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, '233898'), -- Resilient Roach - 233898 -
(@CGUID+21, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Fleetlord Dominator
(@CGUID+22, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Fleetlord Dominator
(@CGUID+23, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+24, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Eredar Bloodmage
(@CGUID+25, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Fleetlord Dominator
(@CGUID+26, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+27, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+28, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+29, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Eredar Bloodmage
(@CGUID+30, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Fleetlord Dominator
(@CGUID+31, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+32, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Eredar Bloodmage
(@CGUID+33, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Felborne Spellbreaker
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ixallon the Soulbreaker
(@CGUID+35, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+36, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xal'atath
(@CGUID+38, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Eredar Bloodmage
(@CGUID+39, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Fleetlord Dominator
(@CGUID+40, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+41, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+42, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+43, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Eredar Bloodmage
(@CGUID+44, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Felborne Spellbreaker
(@CGUID+45, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Eredar Bloodmage
(@CGUID+46, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Shadow Council Warlock
(@CGUID+47, 0, 0, 50331648, 1, 0, 0, 0, 0, '243291'), -- Beam Target Stalker - 243291 -
(@CGUID+48, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Kil'jaeden
(@CGUID+49, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prophète Velen
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Gnimo - 61424 - Mammouth de voyage de la toundra
(@CGUID+51, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Kil'jaeden
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, '61424'), -- Gnimo - 61424 - Mammouth de voyage de la toundra
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+68, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+69, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+73, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+80, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+81, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+88, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+89, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+92, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+99, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+100, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+102, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+103, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+104, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+107, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+110, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+115, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+118, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+119, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- Armageddon Stalker - 234295 - Pluie d'armageddon
(@CGUID+120, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+124, 0, 0, 0, 1, 0, 0, 0, 0, '241905'), -- Shadowsoul - 241905 -
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, '241905'), -- Shadowsoul - 241905 -
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, '241905'), -- Shadowsoul - 241905 -
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, '241905'), -- Shadowsoul - 241905 -
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, '241905'), -- Shadowsoul - 241905 -
(@CGUID+129, 0, 0, 0, 1, 0, 0, 0, 0, '241768'), -- Illidan Hurlorage - 241768 - Vision maudite
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+132, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Sindragosa's Fury
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+134, 0, 0, 50331648, 1, 0, 0, 0, 0, '240020'), -- Nether Rift - 240020 - Ouverture de faille
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+136, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- Fulminating Sphere - 239785 - Obélisque démoniaque
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- Fulminating Sphere - 239785 - Obélisque démoniaque
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- Fulminating Sphere - 239785 - Obélisque démoniaque
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- Fulminating Sphere - 239785 - Obélisque démoniaque
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+152, 0, 0, 50331648, 1, 0, 0, 0, 0, '240020'), -- Nether Rift - 240020 - Ouverture de faille
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- Fulminating Sphere - 239785 - Obélisque démoniaque
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- Fulminating Sphere - 239785 - Obélisque démoniaque
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- Fulminating Sphere - 239785 - Obélisque démoniaque
(@CGUID+158, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- Fleetlord Dominator - 235664 - Dissolution de gangrène
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, '197644'), -- Nar'thalas Citizen - 197644 - Prison de givre
(@CGUID+161, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+162, 0, 0, 1, 1, 0, 0, 0, 0, ''), -- Skrog glissefiel
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+166, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- Phalène gris
(@CGUID+167, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+168, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Raton voleur
(@CGUID+170, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- General Purpose Bunny ZTO
(@CGUID+171, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Persifide glissefiel
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spirit of Netrezaar
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, '197644'), -- Nar'thalas Citizen - 197644 - Prison de givre
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Subjugated Murloc
(@CGUID+176, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+178, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tortue-dragon
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+181, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+182, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Eternal Guardian
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Slithering Brownscale
(@CGUID+184, 0, 0, 0, 1, 0, 0, 0, 0, '179090'), -- Imploratrice des tempêtes glissefiel - 179090 - Appeler la tempête
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+186, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+187, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Blog the Pale
(@CGUID+188, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+189, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+190, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+192, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+193, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tortue-dragon
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+195, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Persifide glissefiel
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Subjugated Murloc
(@CGUID+197, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Archmage Khadgar
(@CGUID+199, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Subjugated Murloc
(@CGUID+200, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Veil Prowler
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+207, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Eternal Guardian
(@CGUID+208, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Eternal Guardian
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skrog glissefiel
(@CGUID+211, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+215, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Raton voleur
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Persifide glissefiel
(@CGUID+220, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+221, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Subjugated Murloc
(@CGUID+222, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Thal'kiel
(@CGUID+226, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Veil Prowler
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, '197644'), -- Nar'thalas Citizen - 197644 - Prison de givre
(@CGUID+228, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+230, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Prophète Velen
(@CGUID+233, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 221736 130966'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie, 130966 - Feindre la mort permanent
(@CGUID+234, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Persifide glissefiel
(@CGUID+235, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Eternal Guardian
(@CGUID+236, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+237, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+238, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Slithering Brownscale
(@CGUID+239, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+240, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, '217193'), -- Brute naga - 217193 - Cogner le mur
(@CGUID+242, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Persifide glissefiel
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+245, 0, 0, 33554432, 1, 0, 0, 0, 0, ''), -- Phalène gris
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tortue-dragon
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'); -- Ombrecavale du voile - 123169 - Échelle : 105-110%; 221736 - Aura de léthargie

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, '197644'), -- Nar'thalas Citizen - 197644 - Prison de givre
(@CGUID+251, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- General Purpose Bunny ZTO
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Persifide glissefiel
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, '197644'), -- Nar'thalas Citizen - 197644 - Prison de givre
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Veil Prowler
(@CGUID+257, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+258, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+259, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+261, 0, 0, 262144, 1, 0, 0, 0, 0, '130966'), -- Tortue-dragon - 130966 - Feindre la mort permanent
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Subjugated Murloc
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+265, 0, 0, 0, 1, 0, 0, 0, 0, '179090'), -- Imploratrice des tempêtes glissefiel - 179090 - Appeler la tempête
(@CGUID+266, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Eternal Guardian
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Traqueur des fonds glissefiel
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Redcrested Heron
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Subjugated Murloc
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Veil Prowler
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Subjugated Murloc
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, '213117'), -- Harponneur glissefiel - 213117 - Aura de canon glissefiel
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tortue-dragon
(@CGUID+279, 0, 0, 262144, 1, 0, 0, 0, 0, '123169 221736 130966'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie, 130966 - Feindre la mort permanent
(@CGUID+280, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Eternal Guardian
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nar'thalas Citizen
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Veil Prowler
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Imploratrice des tempêtes glissefiel
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, '123169 221736'), -- Ombrecavale du voile - 123169 - Échelle : 105-110%, 221736 - Aura de léthargie
(@CGUID+288, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Caudelame glissefiel
(@CGUID+289, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Nar'thalas Citizen

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 269255, 1676, 8524, 8541, 245760, '0', 0, 4522.835, -1301.726, 5335.888, 0.01745246, 0, 0, 0.00872612, 0.9999619, 604800, 255, 0, 25961), -- 269255 (Area: Néant distordu - Difficulty: Outil Raids)
-- (@OGUID+1, 233282, 1676, 8524, 8541, 245760, '0', 0, 4495.809, -1102.945, 5336.06, 4.758136, 0, 0, -0.6907492, 0.7230945, 604800, 255, 1, 25961), -- Refreshment Table (Area: Néant distordu - Difficulty: Outil Raids) - !!! might be temporary spawn !!!
(@OGUID+2, 271126, 1676, 8524, 8541, 245760, '0', 0, 4469.374, -1448.353, 5382.328, 3.141593, 0, 0.02733326, -0.9996262, 0, 604800, 255, 1, 25961), -- Doodad_7DU_TombofSargeras_RetractingBridge_Mirrored001 (Area: Néant distordu - Difficulty: Outil Raids)
(@OGUID+3, 249468, 1676, 7334, 8720, 245760, '0', 0, -165.6732, 5976.998, 3.087193, 0.2175326, 0, 0, 0.108552, 0.9940908, 604800, 255, 1, 25961), -- Campfire (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+4, 271099, 1676, 7334, 8720, 245760, '0', 0, -254.316, 5950.063, 165.6831, 5.570261, 0, 0, -0.3489609, 0.9371373, 604800, 255, 1, 25961), -- Butin de la chute de la Légion (Area: Tombe de Sargeras - Difficulty: Outil Raids)
(@OGUID+5, 268969, 1676, 7334, 8720, 245760, '0', 0, 381.6788, 5467.836, 46.42681, 1.832595, 0, 0, 0.7933531, 0.6087617, 604800, 255, 1, 25961); -- Porte ancienne (Area: Tombe de Sargeras - Difficulty: Outil Raids)
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+1, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_TombofSargeras_RetractingBridge003
(@OGUID+2, 0, 0, 1, -0.00000004371139), -- Doodad_7DU_TombofSargeras_RetractingBridge_Mirrored001
(@OGUID+3, 0, 0, -0.2376859, 0.9713421); -- Campfire

DELETE FROM `spell_target_position` WHERE (`ID`=241442 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(241442, 0, 1676, 4506.15, -1485.4, 5385.72, 25961); -- Spell: Suicide silencieux Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (122800 /*Prophète Velen*/, 121728 /*121728 (Thal'kiel)*/, 117974 /*Illidan Hurlorage*/, 122799 /*122799 (Archmage Khadgar)*/, 120265 /*120265 (Spirit of Netrezaar)*/, 120270 /*120270 (Fulminating Sphere) - Obélisque démoniaque*/, 120390 /*120390 (Nether Rift) - Ouverture de faille*/, 121227 /*Illidan Hurlorage - Vision maudite*/, 121193 /*121193 (Shadowsoul)*/, 92870 /*92870 (Sindragosa's Fury)*/, 120839 /*120839 (Armageddon Stalker) - Pluie d'armageddon*/, 124598 /*124598 (Fleetlord Dominator) - Dissolution de gangrène*/, 124590 /*Seigneur Illidan Hurlorage*/, 117269 /*117269 (Kil'jaeden)*/, 121721 /*121721 (Thal'kiel)*/, 118052 /*Prophète Velen*/, 121788 /*121788 (Kil'jaeden)*/, 121789 /*121789 (Beam Target Stalker)*/, 118930 /*118930 (Ixallon the Soulbreaker)*/, 117769 /*117769 (Felborne Spellbreaker)*/, 117782 /*117782 (Eredar Bloodmage)*/, 117776 /*117776 (Shadow Council Warlock)*/, 121790 /*121790 (Fleetlord Dominator)*/, 117502 /*117502 (Resilient Roach)*/, 119605 /*Racleur-d'os des clos*/, 117793 /*117793 (Fledgling Fel Bat)*/, 120668 /*120668 (Spellstalker) - Sentinax Portal Dissolve In*/, 120575 /*120575 (Hungering Stalker) - Sentinax Portal Dissolve In*/, 120666 /*120666 (Legion Webspewer) - Sentinax Portal Dissolve In*/, 120674 /*120674 (Rotwing Ripper) - Sentinax Portal Dissolve In*/, 120667 /*120667 (Legion Venomretcher) - Sentinax Portal Dissolve In*/, 117744 /*117744 (Fel Slime)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(122800, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Prophète Velen
(121728, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121728 (Thal'kiel)
(117974, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Illidan Hurlorage
(122799, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 122799 (Archmage Khadgar)
(120265, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 120265 (Spirit of Netrezaar)
(120270, 0, 0, 0, 1, 0, 0, 0, 0, '239785'), -- 120270 (Fulminating Sphere) - Obélisque démoniaque
(120390, 0, 0, 50331648, 1, 0, 0, 0, 0, '240020'), -- 120390 (Nether Rift) - Ouverture de faille
(121227, 0, 0, 0, 1, 0, 0, 0, 0, '241768'), -- Illidan Hurlorage - Vision maudite
(121193, 0, 0, 0, 1, 0, 0, 0, 0, '241905'), -- 121193 (Shadowsoul)
(92870, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 92870 (Sindragosa's Fury)
(120839, 0, 0, 0, 1, 0, 0, 0, 0, '234295'), -- 120839 (Armageddon Stalker) - Pluie d'armageddon
(124598, 0, 0, 0, 1, 0, 0, 0, 0, '235664'), -- 124598 (Fleetlord Dominator) - Dissolution de gangrène
(124590, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- Seigneur Illidan Hurlorage
(117269, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 117269 (Kil'jaeden)
(121721, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 121721 (Thal'kiel)
(118052, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Prophète Velen
(121788, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 121788 (Kil'jaeden)
(121789, 0, 0, 50331648, 1, 0, 0, 0, 0, '243291'), -- 121789 (Beam Target Stalker)
(118930, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 118930 (Ixallon the Soulbreaker)
(117769, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- 117769 (Felborne Spellbreaker)
(117782, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- 117782 (Eredar Bloodmage)
(117776, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- 117776 (Shadow Council Warlock)
(121790, 0, 0, 0, 1, 0, 13530, 0, 0, ''), -- 121790 (Fleetlord Dominator)
(117502, 0, 0, 0, 1, 0, 0, 0, 0, '233898'), -- 117502 (Resilient Roach)
(119605, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Racleur-d'os des clos
(117793, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 117793 (Fledgling Fel Bat)
(120668, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- 120668 (Spellstalker) - Sentinax Portal Dissolve In
(120575, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- 120575 (Hungering Stalker) - Sentinax Portal Dissolve In
(120666, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- 120666 (Legion Webspewer) - Sentinax Portal Dissolve In
(120674, 0, 0, 50331648, 1, 0, 0, 0, 0, '241418'), -- 120674 (Rotwing Ripper) - Sentinax Portal Dissolve In
(120667, 0, 0, 0, 1, 0, 0, 0, 0, '241418'), -- 120667 (Legion Venomretcher) - Sentinax Portal Dissolve In
(117744, 0, 0, 0, 1, 0, 0, 0, 0, '234156'); -- 117744 (Fel Slime)

UPDATE `creature_template_addon` SET `auras`='217193' WHERE `entry`=91459; -- Brute naga
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=109351; -- 109351 (Veil Prowler)
UPDATE `creature_template_addon` SET `auras`='179090' WHERE `entry`=88087; -- Imploratrice des tempêtes glissefiel
UPDATE `creature_template_addon` SET `bytes1`=0, `auras`='' WHERE `entry`=89891; -- Tortue-dragon
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=55370; -- 55370 (General Purpose Bunny ZTO)
UPDATE `creature_template_addon` SET `auras`='197644' WHERE `entry`=89634; -- 89634 (Nar'thalas Citizen)
UPDATE `creature_template_addon` SET `auras`='61424' WHERE `entry`=32638; -- 32638 (Hakmud of Argus)
UPDATE `creature_template_addon` SET `auras`='61424' WHERE `entry`=32639; -- 32639 (Gnimo)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (91756, 109349, 89891, 107447, 89811, 109351, 88086, 105838, 120575, 89024, 88087, 120668, 120674, 89025, 119605, 91459, 89802, 93714);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingDelta`, `VerifiedBuild`) VALUES
(91756, 0, 25961),
(109349, 0, 25961),
(89891, 0, 25961),
(107447, 0, 25961),
(89811, 0, 25961),
(109351, 0, 25961),
(88086, 0, 25961),
(105838, 0, 25961),
(120575, 0, 25961),
(89024, 0, 25961),
(88087, 0, 25961),
(120668, 0, 25961),
(120674, 0, 25961),
(89025, 0, 25961),
(119605, 0, 25961),
(91459, 0, 25961),
(89802, 0, 25961),
(93714, 0, 25961);


DELETE FROM `creature_model_info` WHERE `DisplayID` IN (76582, 76353, 74504, 74655, 74973, 74596, 74598, 74597, 75659, 74608, 76087, 74590);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(76582, 3.427399, 1.5, 0, 25961),
(76353, 3.003747, 3, 0, 25961),
(74504, 4.624731, 9, 0, 25961),
(74655, 1, 2, 0, 25961),
(74973, 4.024177, 1.5, 0, 25961),
(74596, 1.958016, 3.45, 0, 25961),
(74598, 2, 3, 0, 25961),
(74597, 1.526981, 1.5, 0, 25961),
(75659, 2.21477, 6, 0, 25961),
(74608, 0.07, 0.3, 0, 25961),
(76087, 3.808196, 2.7, 0, 25961),
(74590, 0.186, 0.6, 0, 25961);

UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=66813;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=61101;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=68603;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=66815;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7159426, `VerifiedBuild`=25961 WHERE `DisplayID`=28515;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=63674;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=66620;
UPDATE `creature_model_info` SET `BoundingRadius`=2.610634, `VerifiedBuild`=25961 WHERE `DisplayID`=46043;
UPDATE `creature_model_info` SET `BoundingRadius`=1.429294, `VerifiedBuild`=25961 WHERE `DisplayID`=31291;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=540;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=61099;
UPDATE `creature_model_info` SET `BoundingRadius`=0.8591311, `VerifiedBuild`=25961 WHERE `DisplayID`=22590;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=40094;
UPDATE `creature_model_info` SET `BoundingRadius`=1.429294, `VerifiedBuild`=25961 WHERE `DisplayID`=31018;
UPDATE `creature_model_info` SET `BoundingRadius`=0.0525, `CombatReach`=0.15, `VerifiedBuild`=25961 WHERE `DisplayID`=42343;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=61100;
UPDATE `creature_model_info` SET `BoundingRadius`=0.7599955, `VerifiedBuild`=25961 WHERE `DisplayID`=39553;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=68659;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=66811;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=69275;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=61102;
UPDATE `creature_model_info` SET `BoundingRadius`=3.829555, `VerifiedBuild`=25961 WHERE `DisplayID`=27710;
UPDATE `creature_model_info` SET `BoundingRadius`=3.906734, `CombatReach`=1.5, `VerifiedBuild`=25961 WHERE `DisplayID`=27571;
UPDATE `creature_model_info` SET `BoundingRadius`=0.511788, `VerifiedBuild`=25961 WHERE `DisplayID`=45898;
UPDATE `creature_model_info` SET `BoundingRadius`=0.639735, `VerifiedBuild`=25961 WHERE `DisplayID`=3233;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=68859;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=10950;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=62511;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=65920;
UPDATE `creature_model_info` SET `VerifiedBuild`=25961 WHERE `DisplayID`=65919;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=122800 AND `ID`=1) OR (`CreatureID`=117974 AND `ID`=1) OR (`CreatureID`=122799 AND `ID`=1) OR (`CreatureID`=121227 AND `ID`=1) OR (`CreatureID`=124598 AND `ID`=1) OR (`CreatureID`=124590 AND `ID`=1) OR (`CreatureID`=118052 AND `ID`=1) OR (`CreatureID`=117769 AND `ID`=1) OR (`CreatureID`=117782 AND `ID`=1) OR (`CreatureID`=121790 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(122800, 1, 35714, 0, 0, 0, 0, 0, 0, 0, 0), -- Prophète Velen
(117974, 1, 150732, 0, 0, 150732, 0, 0, 0, 0, 0), -- Illidan Hurlorage
(122799, 1, 28067, 0, 0, 0, 0, 0, 0, 0, 0), -- Archmage Khadgar
(121227, 1, 150732, 0, 0, 150732, 0, 0, 0, 0, 0), -- Illidan Hurlorage
(124598, 1, 128278, 0, 0, 0, 0, 0, 0, 0, 0), -- Fleetlord Dominator
(124590, 1, 150732, 0, 0, 150732, 0, 0, 0, 0, 0), -- Seigneur Illidan Hurlorage
(118052, 1, 35714, 0, 0, 0, 0, 0, 0, 0, 0), -- Prophète Velen
(117769, 1, 137257, 0, 0, 137260, 0, 0, 0, 0, 0), -- Felborne Spellbreaker
(117782, 1, 94955, 0, 0, 0, 0, 0, 0, 0, 0), -- Eredar Bloodmage
(121790, 1, 128278, 0, 0, 0, 0, 0, 0, 0, 0); -- Fleetlord Dominator



UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=91459; -- Brute naga
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=3, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=33554432, `unit_flags3`=3 WHERE `entry`=122800; -- Prophète Velen
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=121728; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=117974; -- Illidan Hurlorage
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109351; -- Veil Prowler
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=3, `speed_walk`=3.2, `speed_run`=1.857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=122799; -- Archmage Khadgar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=93714; -- Blog the Pale
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=88087; -- Imploratrice des tempêtes glissefiel
UPDATE `creature_template` SET `speed_run`=1.142857, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=89891; -- Tortue-dragon
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=89024; -- Traqueur des fonds glissefiel
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=120265; -- Spirit of Netrezaar
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=89025; -- Persifide glissefiel
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `unit_flags3`=1 WHERE `entry`=55370; -- General Purpose Bunny ZTO
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=88086; -- Caudelame glissefiel
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.8571429, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=62050; -- Phalène gris
UPDATE `creature_template` SET `speed_walk`=1 WHERE `entry`=105838; -- Redcrested Heron
UPDATE `creature_template` SET `unit_flags2`=35653632 WHERE `entry`=107447; -- Harponneur glissefiel
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=89802; -- Skrog glissefiel
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=109349; -- Ombrecavale du voile
UPDATE `creature_template` SET `unit_flags`=294912 WHERE `entry`=89634; -- Nar'thalas Citizen
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=4196352 WHERE `entry`=120270; -- Fulminating Sphere
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2099200 WHERE `entry`=120390; -- Nether Rift
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=2580, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=121227; -- Illidan Hurlorage
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=1.6, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587200, `unit_flags2`=2099200 WHERE `entry`=121193; -- Shadowsoul
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `HoverHeight`=3.5 WHERE `entry`=92870; -- Sindragosa's Fury
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2099200 WHERE `entry`=120839; -- Armageddon Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=14, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=33556480 WHERE `entry`=124598; -- Fleetlord Dominator
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=33556480 WHERE `entry`=124590; -- Seigneur Illidan Hurlorage
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=6293504 WHERE `entry`=117269; -- Kil'jaeden
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=121721; -- Thal'kiel
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=1111492608 WHERE `entry`=118052; -- Prophète Velen
UPDATE `creature_template` SET `minlevel`=113, `maxlevel`=113, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=256, `unit_flags2`=1111492608 WHERE `entry`=121788; -- Kil'jaeden
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=1077970944 WHERE `entry`=121789; -- Beam Target Stalker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=118930; -- Ixallon the Soulbreaker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=117769; -- Felborne Spellbreaker
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=117782; -- Eredar Bloodmage
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=4196352 WHERE `entry`=117776; -- Shadow Council Warlock
UPDATE `creature_template` SET `minlevel`=112, `maxlevel`=112, `faction`=16, `speed_walk`=2.8, `speed_run`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2099200 WHERE `entry`=121790; -- Fleetlord Dominator
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=117502; -- Resilient Roach
UPDATE `creature_template` SET `minlevel`=111, `maxlevel`=111, `faction`=90, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=119605; -- Racleur-d'os des clos
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=117793; -- Fledgling Fel Bat
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=90, `speed_walk`=0.5, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=8, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120668; -- Spellstalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=90, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120575; -- Hungering Stalker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=90, `speed_walk`=0.5, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120666; -- Legion Webspewer
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=16, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120674; -- Rotwing Ripper
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=90, `speed_walk`=0.5, `speed_run`=0.5714286, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=120667; -- Legion Venomretcher
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.4, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=117744; -- Fel Slime


UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=107447; -- Harponneur glissefiel
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=89802; -- Skrog glissefiel
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=91459; -- Brute naga
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=88087; -- Imploratrice des tempêtes glissefiel
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=88086; -- Caudelame glissefiel
UPDATE `creature_template` SET `modelid1`=75801, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=262212, `HealthModifier`=200, `ManaModifier`=15, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=122800; -- Prophète Velen
UPDATE `creature_template` SET `modelid1`=61871, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=200, `ManaModifier`=80, `movementId`=179, `VerifiedBuild`=25961 WHERE `entry`=122799; -- Archmage Khadgar
UPDATE `creature_template` SET `modelid1`=29297, `modelid2`=11686, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121728; -- Thal'kiel
UPDATE `creature_template` SET `modelid1`=63040, `modelid2`=65995, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=120265; -- Spirit of Netrezaar
UPDATE `creature_template` SET `modelid1`=27571, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=2000, `VerifiedBuild`=25961 WHERE `entry`=117974; -- Illidan Hurlorage
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=91756; -- Eternal Guardian
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=89634; -- Nar'thalas Citizen
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=55370; -- General Purpose Bunny ZTO
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=93714; -- Blog the Pale
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=89024; -- Traqueur des fonds glissefiel
UPDATE `creature_template` SET `family`=160, `type_flags`=1, `VerifiedBuild`=25961 WHERE `entry`=109351; -- Veil Prowler
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=89891; -- Tortue-dragon
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=109349; -- Ombrecavale du voile
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=89811; -- Subjugated Murloc
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=89025; -- Persifide glissefiel
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=93725; -- Slithering Brownscale
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=64782; -- Raton voleur
UPDATE `creature_template` SET `family`=0, `movementId`=100, `VerifiedBuild`=25961 WHERE `entry`=62050; -- Phalène gris
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=105838; -- Redcrested Heron
UPDATE `creature_template` SET `modelid1`=76582, `HealthScalingExpansion`=5, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=120270; -- Fulminating Sphere
UPDATE `creature_template` SET `modelid1`=11686, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=120390; -- Nether Rift
UPDATE `creature_template` SET `modelid1`=27571, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=2000, `VerifiedBuild`=25961 WHERE `entry`=121227; -- Illidan Hurlorage
UPDATE `creature_template` SET `modelid1`=76353, `HealthScalingExpansion`=6, `type`=15, `type_flags`=2097224, `HealthModifier`=15.00938, `movementId`=84, `VerifiedBuild`=25961 WHERE `entry`=121193; -- Shadowsoul
UPDATE `creature_template` SET `modelid1`=55719, `HealthScalingExpansion`=6, `rank`=1, `type`=15, `type_flags`=2097256, `type_flags2`=128, `HealthModifier`=30.01876, `VerifiedBuild`=25961 WHERE `entry`=119206; -- Erupting Reflection
UPDATE `creature_template` SET `type_flags`=1074790400, `VerifiedBuild`=25961 WHERE `entry`=100868; -- Chi-Ji
UPDATE `creature_template` SET `modelid1`=27710, `rank`=0, `type`=2, `type_flags`=16778240, `type_flags2`=16, `HealthModifier`=1, `VerifiedBuild`=25961 WHERE `entry`=92870; -- Sindragosa's Fury
UPDATE `creature_template` SET `modelid1`=11686, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048608, `VerifiedBuild`=25961 WHERE `entry`=120839; -- Armageddon Stalker
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=24207; -- Army of the Dead
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=100876; -- Val'kyr Battlemaiden
UPDATE `creature_template` SET `modelid1`=75659, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=1076887624, `HealthModifier`=100, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=124598; -- Fleetlord Dominator
UPDATE `creature_template` SET `modelid1`=27571, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=4, `HealthModifier`=2000, `VerifiedBuild`=25961 WHERE `entry`=124590; -- Seigneur Illidan Hurlorage
UPDATE `creature_template` SET `modelid1`=74504, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097260, `type_flags2`=128, `HealthModifier`=2240.27, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=117269; -- Kil'jaeden
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25961 WHERE `entry`=61245; -- Lightning Surge Totem
UPDATE `creature_template` SET `modelid1`=29297, `modelid2`=11686, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121721; -- Thal'kiel
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=95160; -- Vrykul
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=100820; -- Spirit Wolf
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=105850; -- Akaari's Soul
UPDATE `creature_template` SET `HealthScalingExpansion`=-1, `VerifiedBuild`=25961 WHERE `entry`=108655; -- Spawn of Serpentrix
UPDATE `creature_template` SET `VerifiedBuild`=25961 WHERE `entry`=97055; -- Horreur titubante
UPDATE `creature_template` SET `type`=12, `movementId`=121, `VerifiedBuild`=25961 WHERE `entry`=16085; -- Colportecœur
UPDATE `creature_template` SET `HealthScalingExpansion`=0, `VerifiedBuild`=25961 WHERE `entry`=57239; -- Wise Turtle
UPDATE `creature_template` SET `KillCredit1`=119383, `modelid1`=75935, `modelid2`=75936, `modelid3`=75938, `modelid4`=75939, `HealthScalingExpansion`=6, `type`=3, `HealthModifier`=3, `VerifiedBuild`=25961 WHERE `entry`=120723; -- Fanatique annihiléenne
UPDATE `creature_template` SET `KillCredit1`=119383, `modelid1`=77118, `HealthScalingExpansion`=6, `rank`=6, `type`=3, `HealthModifier`=0.5, `VerifiedBuild`=25961 WHERE `entry`=120638; -- Charognard gangreflamme
UPDATE `creature_template` SET `modelid1`=74655, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=262220, `HealthModifier`=500, `ManaModifier`=15, `VerifiedBuild`=25961 WHERE `entry`=118052; -- Prophète Velen
UPDATE `creature_template` SET `modelid1`=169, `modelid2`=11686, `HealthScalingExpansion`=6, `type`=10, `type_flags`=1048576, `VerifiedBuild`=25961 WHERE `entry`=121789; -- Beam Target Stalker
UPDATE `creature_template` SET `modelid1`=76011, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097260, `HealthModifier`=1684.31, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=121788; -- Kil'jaeden
UPDATE `creature_template` SET `modelid1`=74973, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097256, `HealthModifier`=175, `VerifiedBuild`=25961 WHERE `entry`=118930; -- Ixallon the Soulbreaker
UPDATE `creature_template` SET `modelid1`=74598, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=70, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=117782; -- Eredar Bloodmage
UPDATE `creature_template` SET `modelid1`=74596, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=90, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=117769; -- Felborne Spellbreaker
UPDATE `creature_template` SET `modelid1`=74597, `HealthScalingExpansion`=6, `rank`=1, `type`=7, `type_flags`=2097224, `HealthModifier`=75, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=117776; -- Shadow Council Warlock
UPDATE `creature_template` SET `modelid1`=75659, `HealthScalingExpansion`=6, `rank`=1, `type`=3, `type_flags`=2097256, `HealthModifier`=100, `movementId`=186, `VerifiedBuild`=25961 WHERE `entry`=121790; -- Fleetlord Dominator
UPDATE `creature_template` SET `modelid1`=61909, `modelid2`=61910, `modelid3`=61911, `modelid4`=61912, `HealthScalingExpansion`=6, `type`=7, `HealthModifier`=4, `VerifiedBuild`=25961 WHERE `entry`=119818; -- Demon Hunter


UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=91459 AND `Idx`=5); -- Brute naga
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=91459 AND `Idx`=4); -- Brute naga
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=91459 AND `Idx`=3); -- Brute naga
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=91459 AND `Idx`=2); -- Brute naga
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=91459 AND `Idx`=1); -- Brute naga
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=91459 AND `Idx`=0); -- Brute naga
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=9); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=8); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=7); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=6); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=5); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=4); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=3); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=2); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=1); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88087 AND `Idx`=0); -- Imploratrice des tempêtes glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=7); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=6); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=5); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=4); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=3); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=2); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=1); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=88086 AND `Idx`=0); -- Caudelame glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=93714 AND `Idx`=1); -- Blog the Pale
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=93714 AND `Idx`=0); -- Blog the Pale
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89024 AND `Idx`=5); -- Traqueur des fonds glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89024 AND `Idx`=4); -- Traqueur des fonds glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89024 AND `Idx`=3); -- Traqueur des fonds glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89024 AND `Idx`=2); -- Traqueur des fonds glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89024 AND `Idx`=1); -- Traqueur des fonds glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89024 AND `Idx`=0); -- Traqueur des fonds glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=109351 AND `Idx`=3); -- Veil Prowler
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=109351 AND `Idx`=2); -- Veil Prowler
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=109351 AND `Idx`=1); -- Veil Prowler
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=109351 AND `Idx`=0); -- Veil Prowler
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89891 AND `Idx`=0); -- Tortue-dragon
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=109349 AND `Idx`=2); -- Ombrecavale du voile
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=109349 AND `Idx`=1); -- Ombrecavale du voile
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=109349 AND `Idx`=0); -- Ombrecavale du voile
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89811 AND `Idx`=0); -- Subjugated Murloc
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=7); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=6); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=5); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=4); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=3); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=2); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=1); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=89025 AND `Idx`=0); -- Persifide glissefiel
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=105838 AND `Idx`=1); -- Redcrested Heron
UPDATE `creature_questitem` SET `VerifiedBuild`=25961 WHERE (`CreatureEntry`=105838 AND `Idx`=0); -- Redcrested Heron

DELETE FROM `gameobject_template` WHERE `entry` IN (268969 /*Porte ancienne*/, 271127 /*Doodad_7DU_TombofSargeras_RetractingBridge003*/, 271126 /*Doodad_7DU_TombofSargeras_RetractingBridge_Mirrored001*/, 269255 /*269255*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `VerifiedBuild`) VALUES
(268969, 0, 31374, 'Ancient door', 'interact', '', '', 0.42, 0, 0, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Porte ancienne
(271127, 35, 42565, 'Doodad_7DU_TombofSargeras_RetractingBridge003', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_7DU_TombofSargeras_RetractingBridge003
(271126, 35, 42748, 'Doodad_7DU_TombofSargeras_RetractingBridge_Mirrored001', '', '', '', 0.9999999, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961), -- Doodad_7DU_TombofSargeras_RetractingBridge_Mirrored001
(269255, 1, 41969, '', '', '', '', 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25961); -- 269255

UPDATE `gameobject_template` SET `type`=3, `displayId`=43365, `Data0`=1634, `Data1`=72256, `Data3`=1, `Data10`=1, `Data11`=1, `Data12`=1, `Data13`=1, `Data15`=1, `Data20`=100, `Data25`=2051, `Data27`=1, `Data30`=72362, `Data32`=2, `RequiredLevel`=110, `VerifiedBuild`=25961 WHERE `entry`=271099; -- Butin de la chute de la Légion
UPDATE `gameobject_template` SET `VerifiedBuild`=25961 WHERE `entry`=249468; -- Campfire

-- Delete spells effects creature + duplicates
DELETE FROM creature WHERE `map` = 1676 AND id IN (92870, 73400, 105422, 121717, 121633);
DELETE FROM creature WHERE guid IN (21003217, 21003760, 21003209, 21003218, 21003769, 21003206, 21004062, 21003205, 21004036, 21003747, 21004052, 21004042, 21004058, 21003765, 21003203, 21003767, 21004057, 21003220, 21004061, 21003201, 21003219, 21003215, 21003738, 21004039, 21004059, 21003758, 21003759, 21003761, 21003762, 21003764, 21003202, 21003200, 21003815, 21003418, 21003967);
DELETE FROM creature WHERE guid IN (21003976, 21004879, 21004026, 21004010, 21003959, 21004022, 21003478, 21003480, 21003479, 21003481, 21003264, 21004307, 21004311, 21004312, 21004310, 21004313, 21004315, 21004246, 21004251, 21004247, 21004248, 21004249, 21004244, 21004314, 21004299, 21004269, 21004316, 21004302, 21004309, 21004252, 21004245, 21004253, 21004230, 21004242, 21004250, 21004577, 21004579, 21004578, 21003566, 21003576, 21003589, 21004521, 21004536, 21004513, 21004459, 21004530, 21004555, 21004551, 21004469, 21004464, 21004478, 21004542, 21004498, 21004549, 21004466, 21004553, 21004547, 21004540, 21004503, 21004548, 21004552, 21004532, 21004534, 21004494, 21004550, 21004506, 21004525, 21004554, 21004465, 21004545, 21004539, 21004468, 21004524, 21004538, 21004533, 21004497, 21004544, 21004481, 21004529, 21004546, 21004537, 21004419, 21004510, 21004508, 21004535, 21004518, 21004487, 21004500, 21004541, 21004504, 21004543, 21004531, 21004528, 21003952, 21003974, 21003873, 21004735, 21003445, 21003876, 21003865, 21004034, 21004028, 21004000, 21003830, 21004009, 21004047, 21004037, 21004046, 21004054, 21004044, 21004051, 21004035, 21004025, 21004030, 21004019, 21004031, 21004024, 21004021, 21004006, 21004011, 21004018, 21004016, 21004012, 21004014, 21004008, 21004005, 21004004, 21003989, 21003991, 21003994, 21004003, 21004001, 21003996, 21003998, 21003993, 21004048, 21004049, 21004055, 21004041, 21004040, 21004023, 21004033, 21004020, 21004029, 21004032, 21004017, 21004007, 21004015, 21004013, 21003997, 21003999, 21004002, 21003992, 21003990, 21003995, 21003987, 21003809, 21003881, 21004027, 21003956, 21004739, 21004751, 21004689, 21004712, 21004740, 21004694, 21004742, 21004714, 21004666, 21004750);
DELETE FROM creature WHERE guid IN (21003531, 21003713, 21003665, 21003530, 21003473, 21003472, 21003474, 21004301, 21004305, 21004306, 21004297, 21004308, 21004303, 21004216, 21004227, 21004229, 21004243, 21004231, 21004289, 21004292, 21004176, 21004304, 21004282, 21004296, 21004240, 21004239, 21004241, 21004219, 21004236, 21004238, 21004572, 21004571, 21004573, 21004501, 21004480, 21004405, 21004519, 21004420, 21004425, 21004402, 21004509, 21004443, 21004523, 21004423, 21004490, 21004527, 21004453, 21004517, 21004471, 21004482, 21004520, 21004463, 21004473, 21004437, 21004446, 21004454, 21004514, 21004445, 21004439, 21004522, 21004512, 21004406, 21004467, 21004511, 21004502, 21004470, 21004417, 21004395, 21004472, 21004515, 21004448, 21004516, 21004526, 21004507, 21003862, 21003659, 21003547, 21003579, 21003851, 21003852, 21003848, 21003846, 21003757, 21003744, 21003741, 21003755, 21003746, 21003737, 21003711, 21003707, 21003703, 21003634, 21003599, 21003594, 21003588, 21003583, 21003581, 21003596, 21003571, 21003570, 21003560, 21003556, 21003557, 21003551, 21003548, 21003528, 21003523, 21003526, 21003853, 21003850, 21003756, 21003751, 21003752, 21003742, 21003749, 21003694, 21003625, 21003631, 21003608, 21003591, 21003597, 21003577, 21003573, 21003540, 21003546, 21003537, 21003525, 21003521, 21003533, 21003520, 21004715, 21004746, 21004733, 21004722);
DELETE FROM creature WHERE guid IN (21003469, 21003470, 21004294, 21004286, 21004300, 21004285, 21004295, 21004290, 21004210, 21004191, 21004223, 21004237, 21004194, 21004275, 21004280, 21004170, 21004291, 21004277, 21004284, 21004234, 21004233, 21004235, 21004213, 21004224, 21004232, 21004569, 21004570, 21004568, 21004493, 21004457, 21004438, 21004476, 21004403, 21004436, 21004393, 21004455, 21004451, 21004462, 21004416, 21004426, 21004422, 21004414, 21004442, 21004499, 21004428, 21004475, 21004444, 21004450, 21004424, 21004477, 21004495, 21004496, 21004690, 21004743);
DELETE FROM creature WHERE guid IN (21004283, 21004262, 21004293, 21004266, 21004288, 21004278, 21004204, 21004205, 21004225, 21004270, 21004274, 21004152, 21004279, 21004172, 21004267, 21004228, 21004221, 21004217, 21004195, 21004218, 21004226, 21004563, 21004564, 21004565, 21004415, 21004413, 21004407, 21004440, 21004429, 21004418, 21004447, 21004461, 21004401, 21004458, 21004485, 21004489, 21004688, 21004741);
DELETE FROM creature WHERE guid IN (21004177, 21004256, 21004287, 21004180, 21004271, 21004272, 21004207, 21004264, 21004268, 21004146, 21004273, 21004160, 21004260, 21004222, 21004215, 21004211, 21004212, 21004220, 21004391, 21004392, 21004474, 21004452, 21004686, 21004737);
DELETE FROM creature WHERE guid IN (21004171, 21004169, 21004281, 21004174, 21004265, 21004179, 21004201, 21004258, 21004175, 21004140, 21004261, 21004148, 21004161, 21004198, 21004209, 21004193, 21004206, 21004214, 21004382, 21004390, 21004430, 21004441, 21004678, 21004734);
DELETE FROM creature WHERE guid IN (21004165, 21004157, 21004276, 21004162, 21004259, 21004173, 21004141, 21004163, 21004134, 21004168, 21004149, 21004203, 21004200, 21004208, 21004355, 21004330, 21004377, 21004370, 21004669, 21004732);
DELETE FROM creature WHERE guid IN (21004159, 21004139, 21004263, 21004150, 21004178, 21004167, 21004151, 21004155, 21004137, 21004202, 21004345, 21004327, 21004342, 21004356, 21004667, 21004731);
DELETE FROM creature WHERE guid IN (21004153, 21004257, 21004144, 21004166, 21004156, 21004145, 21004138, 21004196, 21004343, 21004326, 21004329, 21004664, 21004728);
DELETE FROM creature WHERE guid IN (21004147, 21004164, 21004154, 21004143, 21004133, 21004341, 21004325, 21004656, 21004725, 21004333, 21004705);
DELETE FROM creature WHERE guid IN (21004128, 21004158, 21004136, 21004338, 21004323, 21004723, 21004130, 21004337, 21004322, 21004713);
DELETE FROM creature WHERE guid IN (21004704, 21004697, 21004695, 21004693, 21004691, 21004676);

DELETE FROM gameobject WHERE guid IN (21001489, 21001493, 21001475, 21001492, 21001491, 21001477, 21001495, 21001494, 21001476, 21001480, 21001479, 21001496, 21001478, 21001481, 21001499, 21001498, 21001497, 21001482, 21001502, 21001501, 21001500, 21001504, 21001503, 21001484, 21001483, 21001485, 21001474, 21001463, 21001462, 21001453, 21001457, 21001488, 21001445, 21001446, 21001458, 21001467, 21001452, 21001466, 21001470, 21001461, 21001459, 21001469, 21001444, 21001471, 21001460, 21001441, 21001487, 21001486, 21001468, 21001447, 21001465, 21001438, 21001451, 21001450, 21001456, 21001455, 21001449, 21001454, 21001464, 21001443, 21001472, 21001490, 21001442, 21001473, 21001440, 21001437, 21001436, 21001448);
DELETE FROM gameobject WHERE guid IN (21001409, 21001416, 21001403, 21001415, 21001414, 21001419, 21001418, 21001417, 21001404, 21001422, 21001405, 21001421, 21001420, 21001426, 21001425, 21001424, 21001423, 21001410, 21001429, 21001428, 21001427, 21001432, 21001431, 21001411, 21001430, 21001412, 21001406, 21001395, 21001392, 21001384, 21001385, 21001413, 21001376, 21001377, 21001382, 21001390, 21001381, 21001400, 21001398, 21001388, 21001391, 21001397, 21001373, 21001399, 21001408, 21001407, 21001396, 21001372, 21001394, 21001383, 21001375, 21001389, 21001386, 21001374, 21001379, 21001393, 21001371, 21001401, 21001433, 21001378, 21001402, 21001380);

UPDATE creature_template SET InhabitType = 4 WHERE entry IN (118894, 125542, 120449);
