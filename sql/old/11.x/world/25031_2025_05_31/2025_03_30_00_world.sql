SET @OGUID := 7000379;

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+4;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 272422, 1643, 8721, 9032, '0', 0, 0, 61.21701431274414062, 1828.4322509765625, 48.01830673217773437, 5.595108509063720703, 0, 0, -0.33729171752929687, 0.94140017032623291, 120, 255, 1, 59888), -- Gentle's Spellbook (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+1, 272558, 1643, 8721, 9032, '0', 0, 0, 113.5555572509765625, 2002.7274169921875, 100.5130386352539062, 5.773361682891845703, 0, 0, -0.25216007232666015, 0.967685520648956298, 120, 255, 1, 59888), -- Lesser Effigy (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+2, 272557, 1643, 8721, 9032, '0', 0, 0, 181.6319427490234375, 1887.2447509765625, 92.73592376708984375, 0.976935863494873046, 0, 0, 0.469273567199707031, 0.883052825927734375, 120, 255, 1, 59888), -- Lesser Effigy (Area: Fallhaven - Difficulty: 0) CreateObject1
(@OGUID+3, 290428, 1643, 8721, 0, '0', 0, 0, 201.2569427490234375, 1996.5399169921875, 102.1331787109375, 4.133141994476318359, 0, 0, -0.87960052490234375, 0.475713074207305908, 120, 255, 1, 59888), -- Lesser Effigy (Area: 0 - Difficulty: 0) CreateObject1
(@OGUID+4, 272559, 1643, 8721, 9033, '0', 0, 0, 150.423614501953125, 2082.029541015625, 99.2021636962890625, 3.520479202270507812, -0.07776784896850585, -0.00521278381347656, -0.97926044464111328, 0.187013313174247741, 120, 255, 1, 59888); -- Lesser Effigy (Area: Shrouded Foothills - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (272422 /*Gentle's Spellbook*/, 272559 /*Lesser Effigy*/, 290428 /*Lesser Effigy*/, 272557 /*Lesser Effigy*/, 272558 /*Lesser Effigy*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(272422, 0, 0x4, 0, 0), -- Gentle's Spellbook
(272559, 0, 0x40000, 0, 0), -- Lesser Effigy
(290428, 0, 0x40000, 0, 0), -- Lesser Effigy
(272557, 0, 0x40000, 0, 0), -- Lesser Effigy
(272558, 0, 0x40000, 0, 0); -- Lesser Effigy

-- Spawntracking
DELETE FROM `spawn_tracking` WHERE (`SpawnType`=1 AND `SpawnId` IN (@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4));
INSERT INTO `spawn_tracking` (`SpawnTrackingId`, `SpawnType`, `SpawnId`, `QuestObjectiveId`) VALUES
(1350541, 1, @OGUID+1, 291376), -- Lesser Effigy
(1350540, 1, @OGUID+2, 291375), -- Lesser Effigy
(1510634, 1, @OGUID+3, 336232), -- Lesser Effigy
(1350542, 1, @OGUID+4, 291377); -- Lesser Effigy

DELETE FROM `spawn_tracking_state` WHERE `SpawnType` = 1 AND `SpawnId` IN (@OGUID+1,@OGUID+2,@OGUID+3,@OGUID+4);
INSERT INTO `spawn_tracking_state` (`SpawnType`, `SpawnId`, `State`, `Visible`, `StateSpellVisualId`, `StateAnimId`, `StateAnimKitId`, `StateWorldEffects`) VALUES
(1, @OGUID+1, 0, 0, NULL, NULL, NULL, ''),
(1, @OGUID+1, 1, 1, NULL, NULL, NULL, ''),
(1, @OGUID+1, 2, 0, NULL, NULL, NULL, ''),
(1, @OGUID+2, 0, 0, NULL, NULL, NULL, ''),
(1, @OGUID+2, 1, 1, NULL, NULL, NULL, ''),
(1, @OGUID+2, 2, 0, NULL, NULL, NULL, ''),
(1, @OGUID+3, 0, 0, NULL, NULL, NULL, ''),
(1, @OGUID+3, 1, 1, NULL, NULL, NULL, ''),
(1, @OGUID+3, 2, 0, NULL, NULL, NULL, ''),
(1, @OGUID+4, 0, 0, NULL, NULL, NULL, ''),
(1, @OGUID+4, 1, 1, NULL, NULL, NULL, ''),
(1, @OGUID+4, 2, 0, NULL, NULL, NULL, '');

-- Quest
DELETE FROM `quest_details` WHERE `ID`=47981;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(47981, 0, 0, 0, 0, 0, 0, 0, 0, 59888); -- Cracking the Curse

DELETE FROM `gameobject_queststarter` WHERE (`id`=272422 AND `quest`=47981);
INSERT INTO `gameobject_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(272422, 47981, 59888); -- Cracking the Curse offered by Gentle's Spellbook

DELETE FROM `gameobject_questender` WHERE (`id`=278675 AND `quest`=47981);
INSERT INTO `gameobject_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(278675, 47981, 59888); -- Cracking the Curse ended by Cursed Effigy

DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (291375, 291376, 291377, 336232);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(291375, NULL, 248462, NULL, 1, 0),
(291376, NULL, 248462, NULL, 1, 0),
(291377, NULL, 248462, NULL, 1, 0),
(336232, NULL, 248462, NULL, 1, 0);
