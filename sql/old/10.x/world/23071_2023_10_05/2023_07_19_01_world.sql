SET @CGUID := 9003916;
SET @OGUID := 9000370;

SET @NPCTEXTID := 590101;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 18.77951431274414062, -355.66839599609375, 781.14276123046875, 5.756275653839111328, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+1, 195680, 2444, 13862, 14096, '0', 0, 0, 0, 0, 36.05034637451171875, -384.986114501953125, 780.98492431640625, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Playful Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+2, 185563, 2444, 13862, 14096, '0', 0, 0, 0, 1, 83.7881927490234375, -346.279510498046875, 780.6495361328125, 4.819812774658203125, 120, 0, 0, 112919, 0, 0, 0, 0, 50469), -- Jyhanna (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+3, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 29.57118034362792968, -362.842010498046875, 779.44708251953125, 2.685949087142944335, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+4, 195683, 2444, 13862, 14096, '0', 0, 0, 0, 0, 145.4739532470703125, -415.614593505859375, 778.66943359375, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Studious Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+5, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 30.45659828186035156, -359.689239501953125, 779.38861083984375, 2.931650400161743164, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+6, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 25.02951431274414062, -364.97222900390625, 779.1842041015625, 2.326507091522216796, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+7, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 22.50868034362792968, -367.12847900390625, 779.11102294921875, 2.018104076385498046, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+8, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 26.64930534362792968, -361.43402099609375, 779.1666259765625, 2.70387125015258789, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+9, 182082, 2444, 13862, 14096, '0', 0, 0, 0, 0, 94.88715362548828125, -382.2413330078125, 779.7489013671875, 4.438313007354736328, 120, 0, 0, 229028, 0, 0, 0, 0, 50469), -- Agapanthus (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 382554 - Arcane Empowerment)
(@CGUID+10, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 28.39409828186035156, -360.8507080078125, 779.27703857421875, 2.794935226440429687, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+11, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 24.96527862548828125, -358.883697509765625, 778.99053955078125, 2.922655105590820312, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+12, 195680, 2444, 13862, 14096, '0', 0, 0, 0, 0, 39.23263931274414062, -384.927093505859375, 780.47222900390625, 3.896425247192382812, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Playful Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 386407 - Dragonwhelp Wear Hat: Explorer's League [DNT])
(@CGUID+13, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 28.59548568725585937, -364.951385498046875, 779.45684814453125, 2.529507637023925781, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+14, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 23.66493034362792968, -361.90972900390625, 778.956787109375, 2.475105762481689453, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+15, 197756, 2444, 13862, 14096, '0', 0, 0, 0, 0, 17.86979103088378906, -357.322906494140625, 780.6671142578125, 5.857810020446777343, 120, 0, 0, 112919, 0, 0, 0, 0, 50469), -- Kalithumos (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 391680 - Channel: Read Dragon Book (SitChair) [DNT])
(@CGUID+16, 190288, 2444, 13862, 14096, '0', 0, 0, 0, 0, 97.08159637451171875, -383.875, 779.7489013671875, 4.386375904083251953, 120, 0, 0, 53729, 0, 0, 0, 0, 50469), -- Sir Pringly (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 373765 - Dapper)
(@CGUID+17, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 27.87673568725585937, -358.220489501953125, 779.1319580078125, 3.04928755760192871, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+18, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 26.65451431274414062, -366.625, 779.387451171875, 2.346173524856567382, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+19, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 24.91666603088378906, -355.40625, 778.98114013671875, 3.399449110031127929, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+20, 195683, 2444, 13862, 14096, '0', 0, 0, 0, 0, 82.2725677490234375, -329.923614501953125, 782.52569580078125, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Studious Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+21, 197766, 2444, 13862, 14096, '0', 0, 0, 0, 0, 20.90972328186035156, -363.868072509765625, 778.85137939453125, 2.01379561424255371, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Attentive Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+22, 195686, 2444, 13862, 14096, '0', 0, 0, 0, 0, 90.017364501953125, -346.986114501953125, 780.9844970703125, 3.754456281661987304, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Napping Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 381710 - Cosmetic - Sleep Zzz - Very Small Zs)
(@CGUID+23, 195686, 2444, 13862, 14096, '0', 0, 0, 0, 0, 88.21353912353515625, -341.743072509765625, 781.1231689453125, 2.373271703720092773, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Napping Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 381710 - Cosmetic - Sleep Zzz - Very Small Zs)
(@CGUID+24, 195687, 2444, 13862, 14096, '0', 0, 0, 0, 0, 51.34572982788085937, -345.429534912109375, 780.6827392578125, 6.182157039642333984, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Playful Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+25, 195686, 2444, 13862, 14096, '0', 0, 0, 0, 0, 88.5243072509765625, -347.3975830078125, 780.7322998046875, 0, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Napping Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 381710 - Cosmetic - Sleep Zzz - Very Small Zs)
(@CGUID+26, 195687, 2444, 13862, 14096, '0', 0, 0, 0, 0, 44.607208251953125, -347.94091796875, 780.68280029296875, 0.856101691722869873, 120, 0, 0, 33876, 0, 0, 0, 0, 50469), -- Playful Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@CGUID+27, 195686, 2444, 13862, 14096, '0', 0, 0, 0, 0, 88.814239501953125, -348.401031494140625, 780.732177734375, 3.754456043243408203, 120, 0, 0, 33876, 0, 0, 0, 0, 50469); -- Napping Whelp (Area: Little Scales Daycare - Difficulty: 0) CreateObject1 (Auras: 381710 - Cosmetic - Sleep Zzz - Very Small Zs)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+27;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+1, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Playful Whelp
(@CGUID+2, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Jyhanna
(@CGUID+3, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+4, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Studious Whelp
(@CGUID+5, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+7, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '382554'), -- Agapanthus - 382554 - Arcane Empowerment
(@CGUID+10, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, '386407'), -- Playful Whelp - 386407 - Dragonwhelp Wear Hat: Explorer's League [DNT]
(@CGUID+13, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+14, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '391680'), -- Kalithumos - 391680 - Channel: Read Dragon Book (SitChair) [DNT]
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '373765'), -- Sir Pringly - 373765 - Dapper
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+18, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Studious Whelp
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 18310, 0, 0, 0, ''), -- Attentive Whelp
(@CGUID+22, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '381710'), -- Napping Whelp - 381710 - Cosmetic - Sleep Zzz - Very Small Zs
(@CGUID+23, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '381710'), -- Napping Whelp - 381710 - Cosmetic - Sleep Zzz - Very Small Zs
(@CGUID+24, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Playful Whelp
(@CGUID+25, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '381710'), -- Napping Whelp - 381710 - Cosmetic - Sleep Zzz - Very Small Zs
(@CGUID+26, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Playful Whelp
(@CGUID+27, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '381710'); -- Napping Whelp - 381710 - Cosmetic - Sleep Zzz - Very Small Zs

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 379026, 2444, 13862, 14096, '0', 0, 0, 77.48264312744140625, -481.086822509765625, 774.3447265625, 4.398232460021972656, 0, 0, -0.80901622772216796, 0.587786316871643066, 120, 255, 1, 50469), -- Brazier (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@OGUID+1, 379025, 2444, 13862, 14096, '0', 0, 0, 100.0815963745117187, -493.961822509765625, 774.3447265625, 2.286378860473632812, 0, 0, 0.909960746765136718, 0.414694398641586303, 120, 255, 1, 50469), -- Brazier (Area: Little Scales Daycare - Difficulty: 0) CreateObject1
(@OGUID+2, 376389, 2444, 13862, 14096, '0', 0, 0, 83.77777862548828125, -329.822906494140625, 781.6217041015625, 2.827991247177124023, 0, 0, 0.98773193359375, 0.156158998608589172, 120, 255, 1, 50469); -- Magical Book (Area: Little Scales Daycare - Difficulty: 0) CreateObject1

-- Creature Template data
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=190288; -- Sir Pringly
UPDATE `creature_template` SET `faction`=534, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=197756; -- Kalithumos
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry` IN (195687, 195680); -- Playful Whelp
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=182082; -- Agapanthus
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=195686; -- Napping Whelp
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33587968, `unit_flags2`=2048 WHERE `entry`=201429; -- Hungry Whelp
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=195683; -- Studious Whelp
UPDATE `creature_template` SET `faction`=35, `npcflag`=4194467, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=185563; -- Jyhanna
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=197766; -- Attentive Whelp

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (190288, 197756, 182082, 185563);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(190288, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '373765'), -- 190288 (Sir Pringly) - Dapper
(197756, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '391680'), -- 197756 (Kalithumos) - Channel: Read Dragon Book (SitChair) [DNT]
(182082, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '382554'), -- 182082 (Agapanthus) - Arcane Empowerment
(185563, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- 185563 (Jyhanna)

-- NPC Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 190288;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(190288, 224326, 1, 0);

-- Gossip & Text data
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=197766 AND `MenuID`=30472) OR (`CreatureID`=195680 AND `MenuID`=30603) OR (`CreatureID`=195683 AND `MenuID`=30470) OR (`CreatureID`=185563 AND `MenuID`=29540) OR (`CreatureID`=182082 AND `MenuID`=29294);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(197766, 30472, 50469), -- Attentive Whelp
(195680, 30603, 50469), -- Playful Whelp
(195683, 30470, 50469), -- Studious Whelp
(185563, 29540, 50469), -- Jyhanna
(182082, 29294, 50469); -- Agapanthus

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+4;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 234679, 0, 0, 0, 0, 0, 0, 0, 50469), -- 195680 (Playful Whelp)
(@NPCTEXTID+1, 1, 1, 1, 0, 0, 0, 0, 0, 234674, 234673, 234678, 0, 0, 0, 0, 0, 50469), -- 195683 (Studious Whelp)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 229911, 0, 0, 0, 0, 0, 0, 0, 50469), -- 185563 (Jyhanna)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 234595, 0, 0, 0, 0, 0, 0, 0, 50469), -- 197766 (Attentive Whelp)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 228374, 0, 0, 0, 0, 0, 0, 0, 50469); -- 182082 (Agapanthus)

DELETE FROM `gossip_menu` WHERE (`MenuID`=30603 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=30470 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=29540 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=30472 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=29294 AND `TextID`=@NPCTEXTID+4);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(30603, @NPCTEXTID+0, 50469), -- 195680 (Playful Whelp)
(30470, @NPCTEXTID+1, 50469), -- 195683 (Studious Whelp)
(29540, @NPCTEXTID+2, 50469), -- 185563 (Jyhanna)
(30472, @NPCTEXTID+3, 50469), -- 197766 (Attentive Whelp)
(29294, @NPCTEXTID+4, 50469); -- 182082 (Agapanthus)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=29540 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(106777, 29540, 0, 1, 'Want to trade some pet charms?', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 50469);

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=185563 AND `item`=122457 AND `ExtendedCost`=7237 AND `type`=1) OR (`entry`=185563 AND `item`=98715 AND `ExtendedCost`=6433 AND `type`=1) OR (`entry`=185563 AND `item`=86143 AND `ExtendedCost`=6435 AND `type`=1) OR (`entry`=185563 AND `item`=116429 AND `ExtendedCost`=6436 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(185563, 4, 122457, 0, 7237, 1, 0, 0, 50469), -- Ultimate Battle-Training Stone
(185563, 3, 98715, 0, 6433, 1, 0, 0, 50469), -- Marked Flawless Battle-Stone
(185563, 2, 86143, 0, 6435, 1, 0, 0, 50469), -- Battle Pet Bandage
(185563, 1, 116429, 0, 6436, 1, 0, 0, 50469); -- Flawless Battle-Training Stone

-- Creature Equip data
DELETE FROM `creature_equip_template` WHERE (`CreatureID`=185563 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(185563, 1, 1908, 0, 0, 0, 0, 0, 0, 0, 0, 50469); -- Jyhanna

-- Creature Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (197756,195687,195686,201429,185563,195680,203777));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(197756, 0, 0, 0, 864, 9, 1, 1, 226114, 0, 0, 50469),
(195687, 0, 0, 0, 2078, 9, 0.300000011920928955, 1, 223932, 0, 0, 50469),
(195686, 0, 0, 0, 2078, 9, 0.300000011920928955, 1, 223931, 0, 0, 50469),
(201429, 0, 0, 0, 371, 9, 0.200000002980232238, 1, 230030, 0, 0, 50469),
(185563, 0, 0, 0, 373, 9, 1, 1, 209802, 0, 0, 50469),
(195680, 0, 0, 0, 2078, 9, 0.300000011920928955, 1, 223925, 0, 0, 50469),
(203777, 0, 0, 0, 2078, 9, 1, 1, 232874, 1073742848, 0, 50469);
