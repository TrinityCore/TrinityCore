-- Set by TC Devs
-- Fourteen new creature spawns
SET @GUID := 8000021;

-- Add missing Scout-o-Matic 5000 and Choppy Booster Mk. 5 spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+13;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID,156518,2175,10424,10588,'0',0,13766,0,-1,0,0,107.87153,-2414.177,95.44844,0,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'','scout_o_matic',52649),
(@GUID+1,167027,2175,10424,10588,'0',0,15319,0,-1,0,0,107.87153,-2414.177,95.44844,0,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'','choppy_booster',52649),
(@GUID+2,156799,2175,10424,10529,'0',0,13784,0,-1,0,0,230.82812,-2297.0747,83.816696,1.35622859,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Henry Garrick
(@GUID+3,167126,2175,10424,10529,'0',0,15327,0,-1,0,0,230.82812,-2297.0747,83.816696,1.35622859,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Shuja Grimaxe 
(@GUID+4,154300,2175,10424,10588,'0',0,13785,0,-1,0,0,95.635414,-2418.3716,91.11979,6.28133726,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Bjorn Stouthands
(@GUID+5,156800,2175,10424,10588,'0',0,13785,0,-1,0,0,93.15278,-2417.3733,91.79341,6.0155663,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Quartermaster Richter
(@GUID+6,156801,2175,10424,10588,'0',0,13785,0,-1,0,0,95.94097,-2421.5105,91.0058,0.80344587,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Private Cole
(@GUID+7,156803,2175,10424,10588,'0',0,13785,0,-1,0,0,95.66493,-2423.9133,91.00101,0.4256764,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Alaria
(@GUID+8,156804,2175,10424,10588,'0',0,13785,0,-1,0,0,100.55903,-2424.5972,90.237305,1.5070167,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Kee-La
(@GUID+9,167909,2175,10424,10588,'0',0,15553,0,-1,0,0,95.66493,-2423.9133,90.917786,0.425676465,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'','wonsa_darkmaul_plains',52649), -- Won'sa
(@GUID+10,167910,2175,10424,10588,'0',0,15553,0,-1,0,0,100.55903,-2424.5972,90.15397,1.507016778,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'','bo_darkmaul_plains',52649), -- Bo
(@GUID+11,167911,2175,10424,10588,'0',0,15553,0,-1,0,0,95.635414,-2418.3716,91.03652,6.28133726,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'','lana_darkmaul_plains',52649), -- Lana Jordan
(@GUID+12,167912,2175,10424,10588,'0',0,15553,0,-1,0,0,93.15278,-2417.3733,91.710266,6.0155663,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'','jinhake_darkmaul_plains',52649), -- Provisoner Jin'hake
(@GUID+13,167913,2175,10424,10588,'0',0,15553,0,-1,0,0,95.94097,-2421.5105,90.92242,0.8034459,7200,0,0,1,0,0,NULL,NULL,NULL,NULL,'','throg_darkmaul_plains',52649); -- Grunt Throg

UPDATE `creature` SET `StringId`= "lindie_springstock_plains" WHERE `guid`=8000019;
UPDATE `creature` SET `StringId`= "cork_fizzlepop_plains" WHERE `guid`=8000016;

UPDATE `creature_template` SET `npcflag`=16777216 WHERE entry IN (156518,167027);
UPDATE `creature_template` SET `VehicleId`=6843, `ScriptName`="npc_scoutomatic_5000" WHERE `entry`=156526;
UPDATE `creature_template` SET `VehicleId`=6843, `ScriptName`="npc_choppy_booster" WHERE `entry`=167905;
UPDATE `creature_template` SET `ScriptName`="npc_lindie_springstock_plains" WHERE `entry`=149899;
UPDATE `creature_template` SET `ScriptName`="npc_cork_fizzlepop_plains" WHERE `entry`=167019;
UPDATE `creature_template` SET `ScriptName`="npc_horde_crew_plains" WHERE `entry` IN (167909,167910,167911,167912,167913);

DELETE FROM `creature_template_addon` WHERE `entry` IN (156799,167126);
INSERT INTO `creature_template_addon` (`entry`,`visibilityDistanceType`,`auras`) VALUES
(156799,3, '305513 325408'), -- Henry Garrick
(167126,3, '305513 325408'); -- Shuja Grimaxe

DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (156518,167027,156799,167126,156526,167905);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`,`Chase`,`Random`,`InteractionPauseTimer`) VALUES
(156518,0,0,1,0,0,0,0), -- Scout-o-Matic 5000
(167027,0,0,1,0,0,0,0), -- Choppy Booster Mk. 5
(156799,0,0,1,0,0,0,0), -- Henry Garrick
(167126,0,0,1,0,0,0,0), -- Shuja Grimaxe
(156526,0,0,1,0,0,0,0), -- Scout-o-Matic 5000
(167905,0,0,1,0,0,0,0); -- Choppy Booster Mk. 5

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=149899 AND `quest`=55193;
DELETE FROM `creature_queststarter` WHERE `id`=167019 AND `quest`=59940;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(149899, 55193, 52649), -- The Scout-o-Matic 5000 accept from Lindie Springstock
(167019, 59940, 52649); -- The Choppy Booster Mk. 5 accept from Cork Fizzlepop

DELETE FROM `creature_questender` WHERE `id`=149899 AND `quest`=55193;
DELETE FROM `creature_questender` WHERE `id`=167019 AND `quest`=59940;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(149899, 55193, 52649), -- The Scout-o-Matic 5000 turn in to Lindie Springstock
(167019, 59940, 52649); -- The Choppy Booster Mk. 5 turn in to Cork Fizzlepop

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (55193,59940) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 55193, 0, 0, 8, 0, 55186, 0, 0, 0, 0, 0, '', 'AND0 Quest The Scout-o-Matic 5000 available if quest Down with the Quilboar has been rewarded Alliance.'),
(19, 0, 55193, 0, 0, 8, 0, 55184, 0, 0, 0, 0, 0, '', 'AND0 Quest The Scout-o-Matic 5000 available if quest Forbidden Quilboar Necromancy has been rewarded Alliance.'),
(19, 0, 59940, 0, 0, 8, 0, 59938, 0, 0, 0, 0, 0, '', 'AND0 Quest The Choppy Booster Mk. 5 available if quest Down with the Quilboar has been rewarded Horde.'),
(19, 0, 59940, 0, 0, 8, 0, 59939, 0, 0, 0, 0, 0, '', 'AND0 Quest The Choppy Booster Mk. 5 available if quest Forbidden Quilboar Necromancy has been rewarded Horde.');

DELETE FROM `quest_template_addon` WHERE `ID` IN (55193,59940);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(55193,0,0,0,'quest_scout_o_matic_5000'), -- Alliance
(59940,0,0,0,'quest_choppy_booster_mk5'); -- Horde

-- Conversation data for create Scout-O-Matic 5000
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12078);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12078,71345,0,0,0,0,0,0,52649), -- Lindie Springstock
(12078,71344,0,1,0,0,0,0,52649); -- Scout-O-Matic 5000

DELETE FROM `conversation_line_template` WHERE `Id` IN (29391,31498,29394,29392,29395,29393);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29391,0,0,0,52649),
(31498,0,0,1,52649),
(29394,0,1,1,52649),
(29392,0,0,0,52649),
(29395,0,1,1,52649),
(29393,0,0,1,52649);

DELETE FROM `conversation_template` WHERE `Id` IN (12078);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12078,29391,0,'',52649);

-- Conversation data for create Choppy Booster MK 5
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (14516);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14516,76337,0,0,0,0,0,0,52649), -- Cork Fizzlepop
(14516,71344,0,1,0,0,0,0,52649); -- Choppy Booster MK 5

DELETE FROM `conversation_line_template` WHERE `Id` IN (36351,36352,36353,36354,36355,36356);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(36351,0,0,0,52649),
(36352,0,0,1,52649),
(36353,0,1,1,52649),
(36354,0,0,0,52649),
(36355,0,1,1,52649),
(36356,0,0,1,52649);

DELETE FROM `conversation_template` WHERE `Id` IN (14516);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14516,36351,0,'',52649);

-- Conversation data for ride Scout-O-Matic 5000
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12083,12084);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12083,71350,0,0,149899,91998,0,0,52649), -- Lindie Springstock
(12083,71352,0,1,156280,92690,0,0,52649), -- Captain Garrick
(12084,71350,0,0,149899,91998,0,0,52649), -- Lindie Springstock
(12084,71352,0,1,156280,92690,0,0,52649); -- Captain Garrick

DELETE FROM `conversation_line_template` WHERE `Id` IN (29419,31507,29421,29422,29420,34207,29425,29424,29426);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29419,94,0,0,52649),
(31507,85,1,0,52649),
(29421,94,0,0,52649),
(29422,94,0,0,52649),
(29420,85,1,0,52649),
(34207,95,0,0,52649),
(29425,84,1,0,52649),
(29424,95,0,0,52649),
(29426,84,1,0,52649);

DELETE FROM `conversation_template` WHERE `Id` IN (12083,12084);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12083,29419,0,'',52649),
(12084,34207,0,'',52649);

-- Conversation data for ride The Choppy Booster Mk. 5
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (14517,14520);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(14517,76341,0,0,167019,96314,0,0,52649), -- Cork Fizzlepop
(14517,76340,0,1,167021,91669,0,0,52649), -- Warlord Grimaxe
(14520,76341,0,0,167019,96314,0,0,52649), -- Cork Fizzlepop
(14520,76340,0,1,167021,91669,0,0,52649); -- Warlord Grimaxe

DELETE FROM `conversation_line_template` WHERE `Id` IN (36357,36358,36359,36360,36361,36369,36370,36371,36372);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(36357,114,0,0,52649),
(36358,89,1,0,52649),
(36359,114,0,0,52649),
(36360,114,0,0,52649),
(36361,89,1,0,52649),
(36369,115,0,0,52649),
(36370,88,1,0,52649),
(36371,115,0,0,52649),
(36372,88,1,0,52649);

DELETE FROM `conversation_template` WHERE `Id` IN (14517,14520);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(14517,36357,0,'',52649),
(14520,36369,0,'',52649);

-- Phase Area
DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (13784,15327);
DELETE FROM `phase_area` WHERE `AreaId`=10588 AND `PhaseId` IN (13766,15319,13785,15553);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10588,13766, 'Cosmetic - NPE - See The Scout-o-Matic 5000 at Plains'),
(10588,15319, 'Cosmetic - NPE - See The Choppy Booster Mk. 5 at Plains'),
(10424,13784, 'Cosmetic - NPE - See Henry Garrick at Ogre Ruins'),
(10424,15327, 'Cosmetic - NPE - See Shuja Grimaxe at Ogre Ruins'),
(10588,13785, 'Cosmetic - NPE - See Alliance crew at Darkmaul Plains'),
(10588,15553, 'Cosmetic - NPE - See Horde crew at Darkmaul Plains');

-- Phase Names
DELETE FROM `phase_name` WHERE `ID` IN (13766,15319,13784,15327,13785,15553);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(13766,'Cosmetic - NPE - See The Scout-o-Matic 5000 at Plains'),
(15319,'Cosmetic - NPE - See The Choppy Booster Mk. 5 at Plains'),
(13784,'Cosmetic - NPE - See Henry Garrick at Ogre Ruins'),
(15327,'Cosmetic - NPE - See Shuja Grimaxe at Ogre Ruins'),
(13785,'Cosmetic - NPE - See Alliance crew at Darkmaul Plains'),
(15553,'Cosmetic - NPE - See Horde crew at Darkmaul Plains');

-- NPE missing from these names
UPDATE `phase_name` SET `Name`='Cosmetic - NPE - See Lindie Springstock at Darkmaul Plains' WHERE `ID`=13776;
UPDATE `phase_name` SET `Name`='Cosmetic - NPE - See Captian Garrick at Darkmaul Plains' WHERE `ID`=13779;
UPDATE `phase_name` SET `Name`='Cosmetic - NPE - See Austin Huxworth at Darkmaul Plains' WHERE `ID`=13780;
UPDATE `phase_name` SET `Name`='Cosmetic - NPE - See bound Lightspawn' WHERE `ID`=13878;

-- Phase Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13784,15327) AND `SourceEntry`=10424;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13766,15319,13785,15553) AND `SourceEntry`=10588;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13766,10588, 0, 0, 47, 0, 55193, 74, 0, 0, 0, 0, '', 'See The Scout-o-Matic 5000 at Plains if quest The Scout-o-Matic 5000 is inprogress | completed | rewarded Alliance.'),
(26,13766,10588, 0, 0, 1, 0, 305522, 0, 0, 1, 0, 0, '', 'See The Scout-o-Matic 5000 at Plains if player doses not have aura 305522.'),
(26,15319,10588, 0, 0, 47, 0, 59940, 74, 0, 0, 0, 0, '', 'See The Choppy Booster Mk. 5 at Plains if quest The Choppy Booster Mk. 5 is inprogress | completed | rewarded Horde.'),
(26,15319,10588, 0, 0, 1, 0, 326625, 0, 0, 1, 0, 0, '', 'See The Choppy Booster Mk. 5 at Plains if player doses not have aura 326625.'),
(26,13784,10424, 0, 0, 47, 0, 55186, 64, 0, 0, 0, 0, '', 'AND0 See Henry Garrick at Ogre Ruins if quest Down with the Quilboar has been rewarded Alliance.'),
(26,13784,10424, 0, 0, 47, 0, 55184, 64, 0, 0, 0, 0, '', 'AND0 See Henry Garrick at Ogre Ruins if quest Forbidden Quilboar Necromancy has been rewarded Alliance.'),
(26,15327,10424, 0, 0, 47, 0, 59938, 64, 0, 0, 0, 0, '', 'AND0 See Shuja Grimaxe at Ogre Ruins if quest Down with the Quilboar has been rewarded Horde.'),
(26,15327,10424, 0, 0, 47, 0, 59939, 64, 0, 0, 0, 0, '', 'AND0 See Shuja Grimaxe at Ogre Ruins if quest Forbidden Quilboar Necromancy has been rewarded Horde.'),
(26,13785,10588, 0, 0, 47, 0, 55193, 66, 0, 0, 0, 0, '', 'See Alliance Crew at Plains if quest The Scout-o-Matic 5000 is completed | rewarded Alliance.'),
(26,15553,10588, 0, 0, 47, 0, 59940, 66, 0, 0, 0, 0, '', 'See Horde Crew at Plains if quest The Choppy Booster Mk. 5 is completed | rewarded Alliance.');

-- Add Scenes for Darkmaul Ruins Ritual
DELETE FROM `scene_template` WHERE `SceneId` IN (2418,2496);
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2418,16,2932,0,''),
(2496,16,2932,0,'');

-- Spell Trigger
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (-321342,-326626);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-321342,321340,0,'Removing aura Gor''groth Scene (DNT) cast Scout-o-Matic Ping (DNT) on player'),
(-326626,321340,0,'Removing aura Gor''groth Scene (DNT) cast Scout-o-Matic Ping (DNT) on player');

-- Spell Click
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (156518,167027);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(156518,305522,1,0),
(167027,326625,1,0);

-- Condition for Spell click event condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (156518,167027) AND `SourceEntry` IN (305522,326625) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 156518, 305522, 0, 0, 47, 0, 55193, 8, 0, 0, 0, 0, '', 'Spellclick unit Scout-o-Matic 5000 will cast spell Riding Scout O Matic 500 (DNT) on player if quest The Scout-o-Matic 5000 queststate is INCOMPLETE'),
(18, 167027, 326625, 0, 0, 47, 0, 59940, 8, 0, 0, 0, 0, '', 'Spellclick unit Choppy Booster Mk. 5 will cast spell Riding Choppy Booster Mk 5 (DNT) on player if quest The Choppy Booster Mk. 5 queststate is INCOMPLETE');

-- Spell Target Position
DELETE FROM `spell_target_position` WHERE `ID` IN (305523,326624);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(305523,0,2175,107.87153,-2414.177,95.44844,52649),
(326624,0,2175,107.87153,-2414.177,95.44844,52649);

-- Pathing for Won'sa Entry: 167909
SET @PATH := 16790900;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Won\'sa - Path to Plains');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH, 1,35.23047,-2496.2656,76.15068,NULL,0),
(@PATH, 2,36.51172,-2494.7305,76.37278,NULL,0),
(@PATH, 3,37.79297,-2493.1953,76.59488,NULL,0),
(@PATH, 4,38.433594,-2492.4277,76.78395,NULL,0),
(@PATH, 5,40.35547,-2490.125,77.10432,NULL,0),
(@PATH, 6,42.277344,-2487.8223,77.31794,NULL,0),
(@PATH, 7,43.558594,-2486.287,77.5466,NULL,0),
(@PATH, 8,44.839844,-2484.752,77.794556,NULL,0),
(@PATH, 9,46.121094,-2483.2168,78.26145,NULL,0),
(@PATH,10,47.402344,-2481.6816,78.461975,NULL,0),
(@PATH,11,48.04297,-2480.914,78.67813,NULL,0),
(@PATH,12,48.683594,-2480.1465,78.93847,NULL,0),
(@PATH,13,49.964844,-2478.6113,79.17999,NULL,0),
(@PATH,14,51.246094,-2477.0762,79.53442,NULL,0),
(@PATH,15,52.527344,-2475.541,80.06633,NULL,0),
(@PATH,16,53.16797,-2474.7734,80.69311,NULL,0),
(@PATH,17,54.44922,-2473.2383,81.2072,NULL,0),
(@PATH,18,55.089844,-2472.4707,81.69563,NULL,0),
(@PATH,19,55.73047,-2471.7031,82.06888,NULL,0),
(@PATH,20,57.01172,-2470.168,82.387405,NULL,0),
(@PATH,21,57.652344,-2469.4004,82.68654,NULL,0),
(@PATH,22,58.29297,-2468.6328,83.10086,NULL,0),
(@PATH,23,59.57422,-2467.0977,83.603035,NULL,0),
(@PATH,24,60.214844,-2466.33,84.053795,NULL,0),
(@PATH,25,60.85547,-2465.5625,84.65018,NULL,0),
(@PATH,26,62.13672,-2464.0273,85.29573,NULL,0),
(@PATH,27,62.777344,-2463.2598,85.93452,NULL,0),
(@PATH,28,63.41797,-2462.4922,86.4528,NULL,0),
(@PATH,29,64.69922,-2460.957,87.04939,NULL,0),
(@PATH,30,65.33984,-2460.1895,87.599045,NULL,0),
(@PATH,31,66.62109,-2458.6543,88.118324,NULL,0),
(@PATH,32,67.90234,-2457.1191,89.04315,NULL,0),
(@PATH,33,69.18359,-2455.584,89.405785,NULL,0),
(@PATH,34,70.46484,-2454.0488,89.93396,NULL,0),
(@PATH,35,77.51172,-2445.6055,90.18301,NULL,0),
(@PATH,36,78.79297,-2444.0703,90.518875,NULL,0),
(@PATH,37,80.07422,-2442.5352,91.14112,NULL,0),
(@PATH,38,81.99609,-2440.2324,91.35193,NULL,0),
(@PATH,39,85.19922,-2436.3945,91.73271,NULL,0),
(@PATH,40,85.83984,-2435.627,91.5237,NULL,0),
(@PATH,41,87.12109,-2434.0918,91.76771,NULL,0),
(@PATH,42,89.68359,-2431.0215,91.5747,NULL,0),
(@PATH,43,90.96484,-2429.4863,91.38042,NULL,0),
(@PATH,44,91.60547,-2428.7188,91.606064,NULL,0),
(@PATH,45,92.24609,-2427.9512,91.42322,NULL,0),
(@PATH,46,92.88672,-2427.1836,91.12659,NULL,0),
(@PATH,47,93.52734,-2426.416,91.31877,NULL,0),
(@PATH,48,94.80859,-2424.8809,91.00764,NULL,0),
(@PATH,49,95.66493,-2423.9133,90.917786,0.425676465,0);

-- Pathing for Bo Entry: 167910
SET @PATH := 16791000;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Bo - Path to Plains');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH, 1,41.779297,-2500.7227,75.59662,NULL,0),
(@PATH, 2,43.001953,-2499.1406,75.91208,NULL,0),
(@PATH, 3,44.22461,-2497.5586,76.22754,NULL,0),
(@PATH, 4,44.835938,-2496.7676,76.65566,NULL,0),
(@PATH, 5,46.058594,-2495.1855,76.908516,NULL,0),
(@PATH, 6,48.503906,-2492.0215,77.146484,NULL,0),
(@PATH, 7,49.726562,-2490.4395,77.35141,NULL,0),
(@PATH, 8,51.560547,-2488.0664,77.719536,NULL,0),
(@PATH, 9,52.171875,-2487.2754,78.03224,NULL,0),
(@PATH,10,53.39453,-2485.6934,78.31598,NULL,0),
(@PATH,11,54.617188,-2484.1113,78.76373,NULL,0),
(@PATH,12,55.228516,-2483.3203,78.98927,NULL,0),
(@PATH,13,56.45117,-2481.7383,79.24119,NULL,0),
(@PATH,14,57.0625,-2480.9473,79.43339,NULL,0),
(@PATH,15,57.67383,-2480.1562,79.81413,NULL,0),
(@PATH,16,58.896484,-2478.5742,80.22633,NULL,0),
(@PATH,17,59.507812,-2477.7832,80.67,NULL,0),
(@PATH,18,60.11914,-2476.9922,80.88286,NULL,0),
(@PATH,19,61.341797,-2475.4102,81.354126,NULL,0),
(@PATH,20,62.564453,-2473.8281,82.34989,NULL,0),
(@PATH,21,63.78711,-2472.246,82.874084,NULL,0),
(@PATH,22,64.39844,-2471.455,83.129196,NULL,0),
(@PATH,23,65.009766,-2470.664,83.683914,NULL,0),
(@PATH,24,66.23242,-2469.082,84.25187,NULL,0),
(@PATH,25,66.84375,-2468.291,84.807526,NULL,0),
(@PATH,26,68.06641,-2466.709,85.36737,NULL,0),
(@PATH,27,68.677734,-2465.918,85.62689,NULL,0),
(@PATH,28,69.90039,-2464.336,86.55142,NULL,0),
(@PATH,29,71.12305,-2462.754,87.0177,NULL,0),
(@PATH,30,72.3457,-2461.1719,87.5264,NULL,0),
(@PATH,31,72.95703,-2460.3809,87.86322,NULL,0),
(@PATH,32,74.17969,-2458.7988,88.16536,NULL,0),
(@PATH,33,75.40234,-2457.2168,88.643425,NULL,0),
(@PATH,34,76.625,-2455.6348,88.90225,NULL,0),
(@PATH,35,77.23633,-2454.8438,89.07985,NULL,0),
(@PATH,36,79.07031,-2452.4707,89.28867,NULL,0),
(@PATH,37,80.29297,-2450.8887,89.4955,NULL,0),
(@PATH,38,82.12695,-2448.5156,89.74487,NULL,0),
(@PATH,39,84.572266,-2445.3516,89.9191,NULL,0),
(@PATH,40,86.40625,-2442.9785,90.08759,NULL,0),
(@PATH,41,88.240234,-2440.6055,90.378685,NULL,0),
(@PATH,42,90.07422,-2438.2324,90.20039,NULL,0),
(@PATH,43,91.9082,-2435.8594,89.99468,NULL,0),
(@PATH,44,93.13086,-2434.2773,90.21448,NULL,0),
(@PATH,45,96.79883,-2429.5312,90.40429,NULL,0),
(@PATH,46,99.85547,-2425.5762,90.226105,NULL,0),
(@PATH,47,100.55903,-2424.5972,90.15397,1.507016778,0);

-- Pathing for Lana Jordan Entry: 167911
SET @PATH := 16791100;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Lana Jordan - Path to Plains');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH, 1,38.05078,-2497.0703,76.19637,NULL,0),
(@PATH, 2,39.820312,-2494.6504,76.445015,NULL,0),
(@PATH, 3,41.589844,-2492.2305,76.69366,NULL,0),
(@PATH, 4,42.76953,-2490.6172,76.949234,NULL,0),
(@PATH, 5,44.539062,-2488.1973,77.241356,NULL,0),
(@PATH, 6,46.308594,-2485.7773,77.63696,NULL,0),
(@PATH, 7,46.898438,-2484.9707,77.92958,NULL,0),
(@PATH, 8,47.48828,-2484.164,78.1297,NULL,0),
(@PATH, 9,48.66797,-2482.5508,78.352875,NULL,0),
(@PATH,10,49.257812,-2481.7441,78.56903,NULL,0),
(@PATH,11,49.847656,-2480.9375,78.73949,NULL,0),
(@PATH,12,50.4375,-2480.1309,78.98866,NULL,0),
(@PATH,13,51.617188,-2478.5176,79.211685,NULL,0),
(@PATH,14,52.20703,-2477.711,79.42844,NULL,0),
(@PATH,15,53.38672,-2476.0977,79.96034,NULL,0),
(@PATH,16,53.976562,-2475.291,80.25719,NULL,0),
(@PATH,17,55.15625,-2473.6777,81.2072,NULL,0),
(@PATH,18,55.746094,-2472.871,81.598434,NULL,0),
(@PATH,19,56.92578,-2471.2578,81.95367,NULL,0),
(@PATH,20,57.515625,-2470.4512,82.2722,NULL,0),
(@PATH,21,58.10547,-2469.6445,82.68654,NULL,0),
(@PATH,22,59.285156,-2468.0312,83.1065,NULL,0),
(@PATH,23,61.054688,-2465.6113,84.65018,NULL,0),
(@PATH,24,62.234375,-2463.998,85.29573,NULL,0),
(@PATH,25,62.82422,-2463.1914,85.93452,NULL,0),
(@PATH,26,63.414062,-2462.3848,86.4528,NULL,0),
(@PATH,27,64.59375,-2460.7715,87.04939,NULL,0),
(@PATH,28,65.77344,-2459.1582,88.118324,NULL,0),
(@PATH,29,66.953125,-2457.545,88.5997,NULL,0),
(@PATH,30,68.13281,-2455.9316,89.44768,NULL,0),
(@PATH,31,68.72266,-2455.125,89.7714,NULL,0),
(@PATH,32,70.49219,-2452.705,89.98274,NULL,0),
(@PATH,33,75.80078,-2445.4453,90.17747,NULL,0),
(@PATH,34,76.390625,-2444.6387,90.49428,NULL,0),
(@PATH,35,77.57031,-2443.0254,90.830154,NULL,0),
(@PATH,36,78.75,-2441.412,91.52435,NULL,0),
(@PATH,37,80.51953,-2438.9922,91.74478,NULL,0),
(@PATH,38,81.109375,-2438.1855,91.999,NULL,0),
(@PATH,39,84.05859,-2434.1523,92.25275,NULL,0),
(@PATH,40,86.41797,-2430.9258,92.49652,NULL,0),
(@PATH,41,87.59766,-2429.3125,92.31051,NULL,0),
(@PATH,42,88.1875,-2428.5059,92.53616,NULL,0),
(@PATH,43,91.13672,-2424.4727,92.159485,NULL,0),
(@PATH,44,91.72656,-2423.666,91.92435,NULL,0),
(@PATH,45,92.90625,-2422.0527,91.66114,NULL,0),
(@PATH,46,94.08594,-2420.4395,91.40442,NULL,0),
(@PATH,47,95.265625,-2418.8262,91.13356,NULL,0),
(@PATH,48,95.635414,-2418.3716,91.03652,6.28133726,0);

-- Pathing for Provisoner Jin'hake Entry: 167912
SET @PATH := 16791200;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Provisoner Jin\'hake - Path to Plains');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH, 1,31.38208,-2501.5894,75.11702,NULL,0),
(@PATH, 2,32.4635,-2499.91,75.31692,NULL,0),
(@PATH, 3,33.54492,-2498.2305,75.516815,NULL,0),
(@PATH, 4,34.085938,-2497.3906,75.71699,NULL,0),
(@PATH, 5,34.935547,-2496.7168,75.95317,NULL,0),
(@PATH, 6,36.53711,-2495.5176,76.18371,NULL,0),
(@PATH, 7,38.13867,-2494.3184,76.40581,NULL,0),
(@PATH, 8,38.939453,-2493.7188,76.58211,NULL,0),
(@PATH, 9,41.666016,-2491.666,76.69366,NULL,0),
(@PATH,10,43.08008,-2490.252,76.949234,NULL,0),
(@PATH,11,45.20117,-2488.1309,77.20306,NULL,0),
(@PATH,12,45.908203,-2487.4238,77.41345,NULL,0),
(@PATH,13,47.322266,-2486.0098,77.70607,NULL,0),
(@PATH,14,48.029297,-2485.3027,77.975296,NULL,0),
(@PATH,15,49.44336,-2483.8887,78.221115,NULL,0),
(@PATH,16,50,-2483.334,78.221115,NULL,0),
(@PATH,17,51.414062,-2481.92,78.74388,NULL,0),
(@PATH,18,52.121094,-2481.213,78.991806,NULL,0),
(@PATH,19,53.535156,-2479.7988,79.22111,NULL,0),
(@PATH,20,54.242188,-2479.0918,79.49854,NULL,0),
(@PATH,21,55.65625,-2477.6777,79.82413,NULL,0),
(@PATH,22,56.36328,-2476.9707,80.204185,NULL,0),
(@PATH,23,57.777344,-2475.5566,80.638725,NULL,0),
(@PATH,24,58.333984,-2475,80.86495,NULL,0),
(@PATH,25,59.041016,-2474.293,81.08916,NULL,0),
(@PATH,26,60.45508,-2472.879,82.05353,NULL,0),
(@PATH,27,61.86914,-2471.4648,82.58329,NULL,0),
(@PATH,28,62.57617,-2470.7578,83.13916,NULL,0),
(@PATH,29,63.990234,-2469.3438,83.72113,NULL,0),
(@PATH,30,64.697266,-2468.6367,84.28909,NULL,0),
(@PATH,31,66.11133,-2467.2227,84.84305,NULL,0),
(@PATH,32,66.666016,-2466.666,84.84305,NULL,0),
(@PATH,33,67.06641,-2465.75,85.36263,NULL,0),
(@PATH,34,67.4668,-2464.834,85.627464,NULL,0),
(@PATH,35,67.86719,-2463.918,86.11268,NULL,0),
(@PATH,36,68.26758,-2463.002,86.35456,NULL,0),
(@PATH,37,68.66797,-2462.086,86.65648,NULL,0),
(@PATH,38,69.06836,-2461.17,87.215866,NULL,0),
(@PATH,39,69.46875,-2460.254,87.47066,NULL,0),
(@PATH,40,69.86914,-2459.338,87.81572,NULL,0),
(@PATH,41,70.66992,-2457.5059,88.30741,NULL,0),
(@PATH,42,71.07031,-2456.5898,88.635284,NULL,0),
(@PATH,43,71.87109,-2454.7578,89.55542,NULL,0),
(@PATH,44,72.671875,-2452.9258,89.77253,NULL,0),
(@PATH,45,73.958984,-2450,89.75393,NULL,0),
(@PATH,46,75,-2448.959,89.80968,NULL,0),
(@PATH,47,76.48828,-2446.3516,89.99064,NULL,0),
(@PATH,48,76.984375,-2445.4824,90.18024,NULL,0),
(@PATH,49,77.97656,-2443.7441,90.830154,NULL,0),
(@PATH,50,78.96875,-2442.0059,91.18507,NULL,0),
(@PATH,51,79.166016,-2441.666,91.18507,NULL,0),
(@PATH,52,79.61328,-2440.7715,91.40416,NULL,0),
(@PATH,53,80.06055,-2439.877,91.661514,NULL,0),
(@PATH,54,80.95508,-2438.088,91.999,NULL,0),
(@PATH,55,81.84961,-2436.2988,92.20172,NULL,0),
(@PATH,56,83.19141,-2433.6152,92.40908,NULL,0),
(@PATH,57,83.333984,-2433.334,92.25275,NULL,0),
(@PATH,58,83.85742,-2432.4824,92.437325,NULL,0),
(@PATH,59,84.9043,-2430.7793,92.647026,NULL,0),
(@PATH,60,85.95117,-2429.0762,92.839554,NULL,0),
(@PATH,61,88.56836,-2424.8184,92.57365,NULL,0),
(@PATH,62,89.615234,-2423.1152,92.37451,NULL,0),
(@PATH,63,90.66211,-2421.412,92.17143,NULL,0),
(@PATH,64,91.708984,-2419.709,91.95537,NULL,0),
(@PATH,65,92.75586,-2418.0059,91.739525,NULL,0),
(@PATH,66,93.15278,-2417.3733,91.710266,6.0155663,0);

-- Pathing for Grunt Throg Entry: 167913
SET @PATH := 16791300;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Grunt Throg - Path to Plains');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH, 1,35.570312,-2499.2188,75.41057,NULL,0),
(@PATH, 2,36.183594,-2498.4297,75.61734,NULL,0),
(@PATH, 3,36.796875,-2497.6406,75.82411,NULL,0),
(@PATH, 4,37.410156,-2496.8516,76.0252,NULL,0),
(@PATH, 5,38.63672,-2495.2734,76.268715,NULL,0),
(@PATH, 6,39.86328,-2493.6953,76.55202,NULL,0),
(@PATH, 7,41.703125,-2491.3281,76.82607,NULL,0),
(@PATH, 8,43.54297,-2488.961,77.11319,NULL,0),
(@PATH, 9,44.76953,-2487.3828,77.38583,NULL,0),
(@PATH,10,45.996094,-2485.8047,77.63696,NULL,0),
(@PATH,11,46.609375,-2485.0156,77.86047,NULL,0),
(@PATH,12,47.222656,-2484.2266,78.1297,NULL,0),
(@PATH,13,48.44922,-2482.6484,78.352875,NULL,0),
(@PATH,14,49.0625,-2481.8594,78.56903,NULL,0),
(@PATH,15,49.67578,-2481.0703,78.73949,NULL,0),
(@PATH,16,50.902344,-2479.4922,78.98866,NULL,0),
(@PATH,17,52.128906,-2477.914,79.42844,NULL,0),
(@PATH,18,53.35547,-2476.336,79.96034,NULL,0),
(@PATH,19,53.96875,-2475.5469,80.25719,NULL,0),
(@PATH,20,54.58203,-2474.7578,80.718765,NULL,0),
(@PATH,21,55.808594,-2473.1797,81.10999,NULL,0),
(@PATH,22,56.421875,-2472.3906,81.48323,NULL,0),
(@PATH,23,57.035156,-2471.6016,81.95367,NULL,0),
(@PATH,24,57.648438,-2470.8125,82.2722,NULL,0),
(@PATH,25,58.875,-2469.2344,82.69217,NULL,0),
(@PATH,26,59.48828,-2468.4453,83.215675,NULL,0),
(@PATH,27,60.101562,-2467.6562,83.603035,NULL,0),
(@PATH,28,61.328125,-2466.0781,84.136,NULL,0),
(@PATH,29,61.941406,-2465.289,84.756966,NULL,0),
(@PATH,30,62.554688,-2464.5,85.39575,NULL,0),
(@PATH,31,63.78125,-2462.9219,85.94004,NULL,0),
(@PATH,32,65.00781,-2461.3438,87.04939,NULL,0),
(@PATH,33,66.234375,-2459.7656,87.56868,NULL,0),
(@PATH,34,67.46094,-2458.1875,88.5997,NULL,0),
(@PATH,35,68.6875,-2456.6094,89.04315,NULL,0),
(@PATH,36,69.91406,-2455.0312,89.687614,NULL,0),
(@PATH,37,71.75391,-2452.664,89.85864,NULL,0),
(@PATH,38,77.27344,-2445.5625,90.18301,NULL,0),
(@PATH,39,77.88672,-2444.7734,90.497055,NULL,0),
(@PATH,40,79.11328,-2443.1953,90.851974,NULL,0),
(@PATH,41,79.72656,-2442.4062,91.14112,NULL,0),
(@PATH,42,81.56641,-2440.039,91.35193,NULL,0),
(@PATH,43,82.17969,-2439.25,91.56758,NULL,0),
(@PATH,44,85.24609,-2435.3047,91.91708,NULL,0),
(@PATH,45,90.765625,-2428.2031,91.606064,NULL,0),
(@PATH,46,91.37891,-2427.414,91.79823,NULL,0),
(@PATH,47,91.99219,-2426.625,91.61539,NULL,0),
(@PATH,48,92.60547,-2425.836,91.80756,NULL,0),
(@PATH,49,93.21875,-2425.0469,91.50333,NULL,0),
(@PATH,50,93.83203,-2424.2578,91.31187,NULL,0),
(@PATH,51,95.05859,-2422.6797,91.06852,NULL,0),
(@PATH,52,95.94097,-2421.5105,90.92242,0.8034459,0);

-- Pathing for Scout-o-Matic 5000 Entry: 156526
-- Pathing for Choppy Booster Mk. 5 Entry: 167905
SET @PATH := 15652600;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Exile\'s Reach - Copter ride to Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,115.21007,-2420.2239,135.10031,NULL,0),
(@PATH,2,156.11806,-2398.1390,138.27547,NULL,0),
(@PATH,3,182.06944,-2381.7917,138.27547,NULL,0),
(@PATH,4,211.51910,-2379.6284,138.27547,NULL,0);

-- Pathing for Scout-o-Matic 5000 Entry: 156526
-- Pathing for Choppy Booster Mk. 5 Entry: 167905
SET @PATH := 15652601;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,0,0,'Exile\'s Reach - Copter ride from Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,174.54167,-2386.8213,124.66746,NULL,0),
(@PATH,2,107.87153,-2414.177,95.68774,NULL,0);
