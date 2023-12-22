-- Filled in by Trinity team for new areatrigger
SET @ID := 54;
SET @SPAWNID := 54;

-- Enhanced Combat Tactics and Northbound quest
DELETE FROM `creature_queststarter` WHERE `id`=156651 AND `quest` IN (59254,59339);
DELETE FROM `creature_queststarter` WHERE `id`=175031 AND `quest` = 55173;
DELETE FROM `creature_queststarter` WHERE `id`=166906 AND `quest` IN (59933,59934);
DELETE FROM `creature_queststarter` WHERE `id`=175030 AND `quest` = 59935;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(156651, 59254, 45745), -- Enhanced Combat Tactics Alliance accept from Captain Garrick
(156651, 59339, 45745), -- Enhanced Combat Tactics Alliance Monk accept from Captain Garrick
(175031, 55173, 45745), -- Northbound Alliance accept from Alaria
(166906, 59933, 45745), -- Enhanced Combat Tactics Horde accept from Warlord Breka Grimaxe
(166906, 59934, 45745), -- Enhanced Combat Tactics Horde Monk accept from Warlord Breka Grimaxe
(175030, 59935, 45745); -- Northbound Horde accept from Won'sa

DELETE FROM `creature_questender` WHERE `id`=156651 AND `quest` IN (59254,59339);
DELETE FROM `creature_questender` WHERE `id`=154327 AND `quest`=55173;
DELETE FROM `creature_questender` WHERE `id`=166906 AND `quest` IN (59933,59934);
DELETE FROM `creature_questender` WHERE `id`=166996 AND `quest`=59935;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156651, 59254, 45745), -- Enhanced Combat Tactics Alliance turn in to Captain Garrick
(156651, 59339, 45745), -- Enhanced Combat Tactics Alliance Monk turn in to Captain Garrick
(154327, 55173, 45745), -- Northbound Alliance turn in to Austin Huxworth
(166906, 59933, 45745), -- Enhanced Combat Tactics Horde turn in to Warlord Breka Grimaxe
(166906, 59934, 45745), -- Enhanced Combat Tactics Horde Monk turn in to Warlord Breka Grimaxe
(166996, 59935, 45745); -- Northbound Horde turn in to Mithdran Dawntracker

DELETE FROM `quest_template_addon` WHERE `ID` IN (59254,59339,59933,59934);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(59254,1499,55174,0,'quest_enhanced_combat_tactics'), -- Alliance
(59339,512,55174,0,'quest_enhanced_combat_tactics'), -- Alliance Monk
(59933,1499,59932,0,'quest_enhanced_combat_tactics'), -- Horde
(59934,512,59932,0,'quest_enhanced_combat_tactics'); -- Horde Monk

-- Condition for source Quest available condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry` IN (55173,59935) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 55173, 0, 0, 8, 0, 59254, 0, 0, 0, 0, 0, '', 'Quest Northbound available if quest Enhanced Combat Tactics has been rewarded Alliance.'),
(19, 0, 55173, 0, 1, 8, 0, 59339, 0, 0, 0, 0, 0, '', 'Quest Northbound available if quest Enhanced Combat Tactics has been rewarded Alliance.'),
(19, 0, 55173, 0, 2, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Quest Northbound available if player is a Hunter Alliance.'),
(19, 0, 59935, 0, 0, 8, 0, 59933, 0, 0, 0, 0, 0, '', 'Quest Northbound available if quest Enhanced Combat Tactics has been rewarded Horde.'),
(19, 0, 59935, 0, 1, 8, 0, 59934, 0, 0, 0, 0, 0, '', 'Quest Northbound available if quest Enhanced Combat Tactics has been rewarded Horde.'),
(19, 0, 59935, 0, 2, 15, 0, 4, 0, 0, 0, 0, 0, '', 'Quest Northbound available if player is a Hunter Horde.');

-- Alaria is missing questgiver flag
UPDATE `creature_template` SET `npcflag`=2 WHERE entry=175031;

-- Enhanced Combat Tactics Quest

UPDATE `creature_template` SET `ScriptName`="npc_sparring_partner_combat_training" WHERE `entry` IN (164577,166916);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (320175,325181);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(320175,'spell_summon_combat_trainer'),
(325181,'spell_summon_combat_trainer');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (320605,320767, 320583);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(320605,'spell_knockback_charge_enhanced_training'),
(320767,'spell_knockback_charge_enhanced_training'),
(320583,'spell_knockback_charge_enhanced_training');

DELETE FROM `areatrigger_template` WHERE `Id` IN (19470,19479,19461,19457,19482);
INSERT INTO `areatrigger_template` (`Id`,`IsServerSide`,`Type`,`Flags`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`Data6`,`Data7`,`VerifiedBuild`) VALUES
(19470,0,4,0,10,10,4,4,0,0,0,0,0),
(19479,0,4,0,10,10,4,4,0,0,0,0,0),
(19461,0,4,0,10,10,4,4,0,0,0,0,0),
(19457,0,4,0,10,10,4,4,0,0,0,0,0),
(19482,0,4,0,10,10,4,4,0,0,0,0,0);

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (19470,19479,19461,19457,19482);
INSERT INTO `areatrigger_create_properties` (`Id`,`AreaTriggerId`,`MoveCurveId`,`ScaleCurveId`,`MorphCurveId`,`FacingCurveId`,`AnimId`,`AnimKitId`,`DecalPropertiesId`,`TimeToTarget`,`TimeToTargetScale`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`VerifiedBuild`) VALUES
(19470,19479,0,0,0,0,-1,0,0,0,0,4,10,10,4,4,0,0,0,0,'at_aggro_radius_check_enhanced_combat_tactics',0),
(19479,19479,0,0,0,0,-1,0,0,0,0,4,10,10,4,4,0,0,0,0,'at_aggro_radius_check_enhanced_combat_tactics',0),
(19461,19461,0,0,0,0,-1,0,0,0,0,4,10,10,4,4,0,0,0,0,'at_aggro_radius_check_enhanced_combat_tactics',0),
(19457,19457,0,0,0,0,-1,0,0,0,0,4,10,10,4,4,0,0,0,0,'at_aggro_radius_check_enhanced_combat_tactics',0),
(19482,19482,0,0,0,0,-1,0,0,0,0,4,10,10,4,4,0,0,0,0,'at_aggro_radius_check_enhanced_combat_tactics',0);

DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (164577,166916);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(164577,164605,NULL,NULL),
(166916,166918,NULL,NULL);

UPDATE `creature_template` SET `RequiredExpansion` = 9, `unit_flags`=33554496 WHERE `entry` IN (164577,166916);
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=5, `HealthScalingExpansion`=9 WHERE `Entry` IN (164577,166916);

-- Phase conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13758,15298) AND `SourceEntry`=10452;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13758,10452,0,0,47,0,59254,8,0,1,0,0,'','Allow Phase 13758 if Quest 59254 (Enhanced Combat Tactics) is not inprogress'),
(26,13758,10452,0,0,47,0,59339,8,0,1,0,0,'','Allow Phase 13758 if Quest 59339 (Enhanced Combat Tactics) is not inprogress'),
(26,15298,10452,0,0,47,0,59933,8,0,1,0,0,'','Allow Phase 15298 if Quest 59933 (Enhanced Combat Tactics) is not inprogress'),
(26,15298,10452,0,0,47,0,59934,8,0,1,0,0,'','Allow Phase 15298 if Quest 59934 (Enhanced Combat Tactics) is not inprogress');

-- Enhanced combat partner run back
SET @PATH := 10512100;
DELETE FROM `waypoint_data` WHERE `id` IN (@PATH);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`wpguid`) VALUES
(@PATH,1,-228.04771,-2480.6504,19.245068,NULL,0,1,0),
(@PATH,2,-240.67244,-2477.7002,18.045225,NULL,0,1,0),
(@PATH,3,-252.58533,-2487.7651,17.4671,NULL,0,1,0),
(@PATH,4,-249.05904,-2492.5227,17.971006,NULL,0,1,0);

-- Conversation for Sparring Partner
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (13611,13630,13631,13632,13633,13634,13635,13710,13892,13893,13895,14440,14441,14444,14447,14448,14449,14452,14453,14454,14455,14456,14457,14458,14459);
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (14460,14461,14462,14463,14465,14466,14467,14468,14471,14472,14473,14474,14475,14476,14477,14486,14487,14488,14489,14490,14491,14492,14493,14494,14495);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(13611,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13611,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13630,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13630,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13631,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13631,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13632,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13632,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13633,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13633,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13634,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13634,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13635,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13635,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13710,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13710,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13892,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13892,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13893,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13893,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(13895,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(13895,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14440,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14440,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14441,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14441,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14444,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14444,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14447,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14447,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14448,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14448,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14449,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14449,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14452,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14452,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14453,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14453,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14454,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14454,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14455,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14455,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14456,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14456,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14457,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14457,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14458,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14458,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14459,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14459,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14460,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14460,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14461,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14461,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14462,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14462,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14463,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14463,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14465,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14465,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14466,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14466,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14467,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14467,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14468,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14468,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14471,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14471,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14472,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14472,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14473,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14473,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14474,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14474,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14475,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14475,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14476,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14476,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14477,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14477,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14486,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14486,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14487,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14487,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14488,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14488,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14489,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14489,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14490,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14490,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14491,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14491,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14492,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14492,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14493,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14493,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14494,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14494,76285,0,1,0,0,0,0,45745), -- Horde Sparring Partner
(14495,74771,0,0,0,0,0,0,45745), -- Alliance Sparring Partner
(14495,76285,0,1,0,0,0,0,45745); -- Horde Sparring Partner

DELETE FROM `conversation_line_template` WHERE `Id` IN (34011,34012,34013,34014,34015,34016,34017,34018,34019,34020,34021,34022,34024,34025,36204,34173,36160,34690,34691,34692,34693,34697,34698,36206,36207,36163,36164,36170,36171,36175,36176,36177,36178,36179,36180,33931,33932,33933,36181,36182,36183,36161,36162);
DELETE FROM `conversation_line_template` WHERE `Id` IN (36188,36189,36190,36191,36192,36193,36194,36195,36196,36197,36198,36199,36200,36201,36202,36203,36208,36209,36210,36211,36212,36213,36214,36215,36218,36219,36222,36223,36224,36225,36226,36227,36228,36229,36231,36232,36233,36234,36235,36236,36237,36238,36242,36243,36244,36245,36246,36247,36248,36249,36250,36251,36252,36253,36254,36255,36256,36257,36258);
DELETE FROM `conversation_line_template` WHERE `Id` IN (36259,36260,36261,36262,36275,36276,36277,36278,36279,36280,36281,36282,36283,36284,36285,36286,36287,36288,36289,36290,36291,36292,36293,36294);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(33931,0,0,0,45745), -- Alliance
(33932,0,0,0,45745), -- Alliance
(33933,0,0,0,45745), -- Alliance
(34011,0,0,0,45745), -- Alliance
(34012,0,0,0,45745), -- Alliance
(34013,0,0,0,45745), -- Alliance
(34014,0,0,0,45745), -- Alliance
(34015,0,0,0,45745), -- Alliance
(34016,0,0,0,45745), -- Alliance
(34017,0,0,0,45745), -- Alliance
(34018,0,0,0,45745), -- Alliance
(34019,0,0,0,45745), -- Alliance
(34020,0,0,0,45745), -- Alliance
(34021,0,0,0,45745), -- Alliance
(34022,0,0,0,45745), -- Alliance
(34024,0,0,0,45745), -- Alliance
(34025,0,0,0,45745), -- Alliance
(34173,0,0,0,45745), -- Alliance
(34690,0,0,0,45745), -- Alliance
(34691,0,0,0,45745), -- Alliance
(34692,0,0,0,45745), -- Alliance
(34693,0,0,0,45745), -- Alliance
(34697,0,0,0,45745), -- Alliance
(34698,0,0,0,45745), -- Alliance
(36160,0,1,0,45745), -- Horde
(36161,0,0,0,45745), -- Alliance
(36162,0,1,0,45745), -- Horde
(36163,0,0,0,45745), -- Alliance
(36164,0,1,0,45745), -- Horde
(36170,0,0,0,45745), -- Alliance
(36171,0,1,0,45745), -- Horde
(36175,0,0,0,45745), -- Alliance
(36176,0,1,0,45745), -- Horde
(36177,0,0,0,45745), -- Alliance
(36178,0,1,0,45745), -- Horde
(36179,0,0,0,45745), -- Alliance
(36180,0,1,0,45745), -- Horde
(36181,0,1,0,45745), -- Horde
(36182,0,1,0,45745), -- Horde
(36183,0,1,0,45745), -- Horde
(36188,0,0,0,45745), -- Alliance
(36189,0,1,0,45745), -- Horde
(36190,0,0,0,45745), -- Alliance
(36191,0,1,0,45745), -- Horde
(36192,0,0,0,45745), -- Alliance
(36193,0,1,0,45745), -- Horde
(36194,0,0,0,45745), -- Alliance
(36195,0,1,0,45745), -- Horde
(36196,0,0,0,45745), -- Alliance
(36197,0,1,0,45745), -- Horde
(36198,0,0,0,45745), -- Alliance
(36199,0,1,0,45745), -- Horde
(36200,0,0,0,45745), -- Alliance
(36201,0,1,0,45745), -- Horde
(36202,0,0,0,45745), -- Alliance
(36203,0,1,0,45745), -- Horde
(36204,0,1,0,45745), -- Horde
(36206,0,1,0,45745), -- Horde
(36207,0,1,0,45745), -- Horde
(36208,0,0,0,45745), -- Alliance
(36209,0,1,0,45745), -- Horde
(36210,0,0,0,45745), -- Alliance
(36211,0,1,0,45745), -- Horde
(36212,0,0,0,45745), -- Alliance
(36213,0,1,0,45745), -- Horde
(36214,0,0,0,45745), -- Alliance
(36215,0,1,0,45745), -- Horde
(36218,0,1,0,45745), -- Horde
(36219,0,1,0,45745), -- Horde
(36222,0,0,0,45745), -- Alliance
(36223,0,1,0,45745), -- Horde
(36224,0,0,0,45745), -- Alliance
(36225,0,1,0,45745), -- Horde
(36226,0,0,0,45745), -- Alliance
(36227,0,1,0,45745), -- Horde
(36228,0,0,0,45745), -- Alliance
(36229,0,1,0,45745), -- Horde
(36231,0,1,0,45745), -- Horde
(36232,0,1,0,45745), -- Horde
(36233,0,0,0,45745), -- Alliance
(36234,0,1,0,45745), -- Horde
(36235,0,0,0,45745), -- Alliance
(36236,0,1,0,45745), -- Horde
(36237,0,0,0,45745), -- Alliance
(36238,0,1,0,45745), -- Horde
(36242,0,0,0,45745), -- Alliance
(36243,0,1,0,45745), -- Horde
(36244,0,1,0,45745), -- Horde
(36245,0,1,0,45745), -- Horde
(36246,0,1,0,45745), -- Horde
(36247,0,1,0,45745), -- Horde
(36248,0,1,0,45745), -- Horde
(36249,0,1,0,45745), -- Horde
(36250,0,1,0,45745), -- Horde
(36251,0,1,0,45745), -- Horde
(36252,0,0,0,45745), -- Alliance
(36253,0,1,0,45745), -- Horde
(36254,0,1,0,45745), -- Horde
(36255,0,1,0,45745), -- Horde
(36256,0,1,0,45745), -- Horde
(36257,0,1,0,45745), -- Horde
(36258,0,1,0,45745), -- Horde
(36259,0,0,0,45745), -- Alliance
(36260,0,1,0,45745), -- Horde
(36261,0,0,0,45745), -- Alliance
(36262,0,1,0,45745), -- Horde
(36275,0,0,0,45745), -- Alliance
(36276,0,1,0,45745), -- Horde
(36277,0,0,0,45745), -- Alliance
(36278,0,1,0,45745), -- Horde
(36279,0,0,0,45745), -- Alliance
(36280,0,1,0,45745), -- Horde
(36281,0,0,0,45745), -- Alliance
(36282,0,1,0,45745), -- Horde
(36283,0,0,0,45745), -- Alliance
(36284,0,1,0,45745), -- Horde
(36285,0,0,0,45745), -- Alliance
(36286,0,1,0,45745), -- Horde
(36287,0,0,0,45745), -- Alliance
(36288,0,1,0,45745), -- Horde
(36289,0,0,0,45745), -- Alliance
(36290,0,1,0,45745), -- Horde
(36291,0,0,0,45745), -- Alliance
(36292,0,1,0,45745), -- Horde
(36293,0,0,0,45745), -- Alliance
(36294,0,1,0,45745); -- Horde

DELETE FROM `conversation_template` WHERE `Id` IN (13630,13631,13632,13633,13634,13635,13710,13892,13893,13895,14441,14444,14447,14448,14449,13611,14440);
DELETE FROM `conversation_template` WHERE `Id` IN (14452,14453,14454,14455,14456,14457,14458,14459,14460,14461,14462,14463,14465,14466,14467,14468,14471,14472,14473,14474,14475,14476,14477);
DELETE FROM `conversation_template` WHERE `Id` IN (14486,14487,14488,14489,14490,14491,14492,14493,14494,14495);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(13630,34011,0,'',45745),
(13631,34012,0,'',45745),
(13632,34015,0,'',45745),
(13633,34018,0,'',45745),
(13634,34020,0,'',45745),
(13635,34024,0,'',45745),
(13710,34173,0,'',45745),
(13892,34690,0,'',45745),
(13893,34692,0,'',45745),
(13895,34697,0,'',45745),
(14441,36163,0,'',45745),
(14444,36170,0,'',45745),
(14447,36175,0,'',45745),
(14448,36177,0,'',45745),
(14449,36179,0,'',45745),
(13611,33931,0,'',45745),
(14440,36161,0,'',45745),
(14452,36188,0,'',45745),
(14453,36190,0,'',45745),
(14454,36192,0,'',45745),
(14455,36194,0,'',45745),
(14456,36196,0,'',45745),
(14457,36198,0,'',45745),
(14458,36200,0,'',45745),
(14459,36202,0,'',45745),
(14460,36208,0,'',45745),
(14461,36210,0,'',45745),
(14462,36212,0,'',45745),
(14463,36214,0,'',45745),
(14465,36222,0,'',45745),
(14466,36224,0,'',45745),
(14467,36226,0,'',45745),
(14468,36228,0,'',45745),
(14471,36233,0,'',45745),
(14472,36235,0,'',45745),
(14473,36237,0,'',45745),
(14474,36242,0,'',45745),
(14475,36252,0,'',45745),
(14476,36259,0,'',45745),
(14477,36261,0,'',45745),
(14486,36275,0,'',45745),
(14487,36277,0,'',45745),
(14488,36279,0,'',45745),
(14489,36281,0,'',45745),
(14490,36283,0,'',45745),
(14491,36285,0,'',45745),
(14492,36287,0,'',45745),
(14493,36289,0,'',45745),
(14494,36291,0,'',45745),
(14495,36293,0,'',45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (34011,36204,34173,36160,36163,36164,36170,36171,36175,36176,36177,36178,36179,36180,33931,33932,33933,36181,36182,36183,36161,36162);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (36188,36189,36190,36191,36192,36193,36194,36195,36196,36197,36198,36199,36200,36201,36202,36203,36208,36209,36210,36211,36212,36213,36214,36215);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (36275,36276,36277,36278,36279,36280,36281,36282,36283,36284,36285,36286,36287,36288,36289,36290,36291,36292,36293,36294,34690,34691,36206,36207,34012,34013,34014,36249,36250,36251,34015,34016,34017,36246,36247,36248,34018,34019,36244,36245,36252,36253);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (34020,34021,34022,36256,36257,36258,34024,34025,36254,36255,36259,36260,36261,36262,34697,34698,36218,36219,36224,36225,36226,36227,36228,36229,34692,34693,36231,36232,36235,36236,36237,36238,36242,36243,36222,36223,36233,36234);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,34011,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34011 if team is Alliance'),
(29,0,36204,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36204 if team is Horde'),
(29,0,34173,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34173 if team is Alliance'),
(29,0,36160,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36160 if team is Horde'),
(29,0,36163,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36163 if team is Alliance'),
(29,0,36164,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36164 if team is Horde'),
(29,0,36170,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36170 if team is Alliance'),
(29,0,36171,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36171 if team is Horde'),
(29,0,36175,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36175 if team is Alliance'),
(29,0,36176,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36176 if team is Horde'),
(29,0,36177,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36177 if team is Alliance'),
(29,0,36178,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36178 if team is Horde'),
(29,0,36179,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36179 if team is Alliance'),
(29,0,36180,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36180 if team is Horde'),
(29,0,33931,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 33931 if team is Alliance'),
(29,0,33932,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 33932 if team is Alliance'),
(29,0,33933,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 33933 if team is Alliance'),
(29,0,33931,0,0,48,0,396220,1,0,0,0,0,'','Allow conversation line 33931 if objective count 0'),
(29,0,33932,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 33931 if objective count 1'),
(29,0,33933,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 33931 if objective count 2'),
(29,0,36181,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36181 if team is Horde'),
(29,0,36182,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36182 if team is Horde'),
(29,0,36183,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36183 if team is Horde'),
(29,0,36181,0,0,48,0,397255,1,0,0,0,0,'','Allow conversation line 36181 if objective count 0'),
(29,0,36182,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36182 if objective count 1'),
(29,0,36183,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36183 if objective count 2'),
(29,0,36161,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36161 if team is Alliance'),
(29,0,36162,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36162 if team is Horde'),
(29,0,36188,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36188 if team is Alliance'),
(29,0,36189,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36189 if team is Horde'),
(29,0,36190,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36190 if team is Alliance'),
(29,0,36191,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36191 if team is Horde'),
(29,0,36192,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36192 if team is Alliance'),
(29,0,36193,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36193 if team is Horde'),
(29,0,36194,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36194 if team is Alliance'),
(29,0,36195,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36195 if team is Horde'),
(29,0,36196,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36196 if team is Alliance'),
(29,0,36197,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36197 if team is Horde'),
(29,0,36198,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36198 if team is Alliance'),
(29,0,36199,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36199 if team is Horde'),
(29,0,36200,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36200 if team is Alliance'),
(29,0,36201,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36201 if team is Horde'),
(29,0,36202,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36202 if team is Alliance'),
(29,0,36203,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36203 if team is Horde'),
(29,0,36208,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36208 if team is Alliance'),
(29,0,36209,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36209 if team is Horde'),
(29,0,36210,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36210 if team is Alliance'),
(29,0,36211,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36211 if team is Horde'),
(29,0,36212,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36212 if team is Alliance'),
(29,0,36213,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36213 if team is Horde'),
(29,0,36214,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36214 if team is Alliance'),
(29,0,36215,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36215 if team is Horde'),
(29,0,36275,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36275 if team is Alliance'),
(29,0,36276,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36276 if team is Horde'),
(29,0,36277,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36277 if team is Alliance'),
(29,0,36278,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36278 if team is Horde'),
(29,0,36279,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36279 if team is Alliance'),
(29,0,36280,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36280 if team is Horde'),
(29,0,36281,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36281 if team is Alliance'),
(29,0,36282,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36282 if team is Horde'),
(29,0,36283,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36283 if team is Alliance'),
(29,0,36284,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36284 if team is Horde'),
(29,0,36285,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36285 if team is Alliance'),
(29,0,36286,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36286 if team is Horde'),
(29,0,36287,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36287 if team is Alliance'),
(29,0,36288,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36288 if team is Horde'),
(29,0,36289,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36289 if team is Alliance'),
(29,0,36290,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36290 if team is Horde'),
(29,0,36291,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36291 if team is Alliance'),
(29,0,36292,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36292 if team is Horde'),
(29,0,36293,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36293 if team is Alliance'),
(29,0,36294,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36294 if team is Horde'),
(29,0,34690,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34690 if team is Alliance'),
(29,0,34691,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34691 if team is Alliance'),
(29,0,34690,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34690 if objective count 1'),
(29,0,34691,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34691 if objective count 2'),
(29,0,36206,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36206 if team is Horde'),
(29,0,36207,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36207 if team is Horde'),
(29,0,36206,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36206 if objective count 1'),
(29,0,36207,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36207 if objective count 2'),
(29,0,34012,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34012 if team is Alliance'),
(29,0,34013,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34013 if team is Alliance'),
(29,0,34014,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34014 if team is Alliance'),
(29,0,34012,0,0,48,0,396220,1,0,0,0,0,'','Allow conversation line 34012 if objective count 0'),
(29,0,34013,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34013 if objective count 1'),
(29,0,34014,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34014 if objective count 2'),
(29,0,36249,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36249 if team is Horde'),
(29,0,36250,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36250 if team is Horde'),
(29,0,36251,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36251 if team is Horde'),
(29,0,36249,0,0,48,0,397255,1,0,0,0,0,'','Allow conversation line 36249 if objective count 0'),
(29,0,36250,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36250 if objective count 1'),
(29,0,36251,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36251 if objective count 2'),
(29,0,34015,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34015 if team is Alliance'),
(29,0,34016,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34016 if team is Alliance'),
(29,0,34017,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34017 if team is Alliance'),
(29,0,34015,0,0,48,0,396220,1,0,0,0,0,'','Allow conversation line 34015 if objective count 0'),
(29,0,34016,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34016 if objective count 1'),
(29,0,34017,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34017 if objective count 2'),
(29,0,36246,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36246 if team is Horde'),
(29,0,36247,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36247 if team is Horde'),
(29,0,36248,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36248 if team is Horde'),
(29,0,36246,0,0,48,0,397255,1,0,0,0,0,'','Allow conversation line 36246 if objective count 0'),
(29,0,36247,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36247 if objective count 1'),
(29,0,36248,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36248 if objective count 2'),
(29,0,34018,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34018 if team is Alliance'),
(29,0,34019,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34019 if team is Alliance'),
(29,0,34018,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34018 if objective count 1'),
(29,0,34019,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34019 if objective count 2'),
(29,0,36244,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36244 if team is Horde'),
(29,0,36245,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36245 if team is Horde'),
(29,0,36244,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36244 if objective count 1'),
(29,0,36245,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36245 if objective count 2'),
(29,0,36252,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36252 if team is Alliance'),
(29,0,36253,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36253 if team is Horde'),
(29,0,34020,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34020 if team is Alliance'),
(29,0,34021,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34021 if team is Alliance'),
(29,0,34022,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34022 if team is Alliance'),
(29,0,34020,0,0,48,0,396220,1,0,0,0,0,'','Allow conversation line 34020 if objective count 0'),
(29,0,34021,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34021 if objective count 1'),
(29,0,34022,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34022 if objective count 2'),
(29,0,36256,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36256 if team is Horde'),
(29,0,36257,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36257 if team is Horde'),
(29,0,36258,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36258 if team is Horde'),
(29,0,36256,0,0,48,0,397255,1,0,0,0,0,'','Allow conversation line 36256 if objective count 0'),
(29,0,36257,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36257 if objective count 1'),
(29,0,36258,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36258 if objective count 2'),
(29,0,34024,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34024 if team is Alliance'),
(29,0,34025,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34025 if team is Alliance'),
(29,0,34024,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34024 if objective count 1'),
(29,0,34025,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34025 if objective count 2'),
(29,0,36254,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36254 if team is Horde'),
(29,0,36255,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36255 if team is Horde'),
(29,0,36254,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36254 if objective count 1'),
(29,0,36255,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36255 if objective count 2'),
(29,0,36259,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36259 if team is Alliance'),
(29,0,36260,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36260 if team is Horde'),
(29,0,36261,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36261 if team is Alliance'),
(29,0,36262,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36262 if team is Horde'),
(29,0,34697,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34697 if team is Alliance'),
(29,0,34698,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34698 if team is Alliance'),
(29,0,34697,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34697 if objective count 1'),
(29,0,34698,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34698 if objective count 2'),
(29,0,36218,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36218 if team is Horde'),
(29,0,36219,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36219 if team is Horde'),
(29,0,36218,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36218 if objective count 1'),
(29,0,36219,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36219 if objective count 2'),
(29,0,36224,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36224 if team is Alliance'),
(29,0,36225,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36225 if team is Horde'),
(29,0,36226,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36226 if team is Alliance'),
(29,0,36227,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36227 if team is Horde'),
(29,0,36228,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36228 if team is Alliance'),
(29,0,36229,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36229 if team is Horde'),
(29,0,34692,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34692 if team is Alliance'),
(29,0,34693,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 34693 if team is Alliance'),
(29,0,34692,0,0,48,0,396220,1,1,0,0,0,'','Allow conversation line 34692 if objective count 1'),
(29,0,34693,0,0,48,0,396220,1,2,0,0,0,'','Allow conversation line 34693 if objective count 2'),
(29,0,36231,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36231 if team is Horde'),
(29,0,36232,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36232 if team is Horde'),
(29,0,36231,0,0,48,0,397255,1,1,0,0,0,'','Allow conversation line 36231 if objective count 1'),
(29,0,36232,0,0,48,0,397255,1,2,0,0,0,'','Allow conversation line 36232 if objective count 2'),
(29,0,36235,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36235 if team is Alliance'),
(29,0,36236,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36236 if team is Horde'),
(29,0,36237,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36237 if team is Alliance'),
(29,0,36238,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36238 if team is Horde'),
(29,0,36242,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36242 if team is Alliance'),
(29,0,36243,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36243 if team is Horde'),
(29,0,36222,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36222 if team is Alliance'),
(29,0,36223,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36223 if team is Horde'),
(29,0,36233,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 36233 if team is Alliance'),
(29,0,36234,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36234 if team is Horde');

-- Northbound Quest

-- Create new serverside areatrigger for approching Quillboar Briarpatch for follower spawn
DELETE FROM `areatrigger` WHERE `SpawnId`=@SPAWNID;
INSERT INTO `areatrigger` (`SpawnId`,`AreaTriggerId`,`IsServerSide`,`MapId`,`PosX`,`PosY`,`PosZ`,`Orientation`,`PhaseUseFlags`,`PhaseId`,`PhaseGroup`,`Shape`,`ShapeData0`,`ShapeData1`,`ShapeData2`,`ShapeData3`,`ShapeData4`,`ShapeData5`,`ShapeData6`,`ShapeData7`,`ScriptName`,`Comment`) VALUES
(@SPAWNID,@ID,1,2175,-175,-2585,33.567165,2.361945,0,0,0,1,2,60,30,8,60,30,0,0,'at_northbound_linger','Exiles Reach - Northbound check');
-- Add new serverside areatrigger for approching Quillboar Brarpatch to template
DELETE FROM `areatrigger_template` WHERE `Id`=@ID;
INSERT INTO `areatrigger_template` (`Id`,`IsServerSide`,`Type`,`Flags`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`Data6`,`Data7`,`VerifiedBuild`) VALUES
(@ID,1,1,0,2,60,30,8,60,30,0,0,0);

UPDATE `creature` SET `StringId`="huxworth_briarpatch" WHERE `guid`=1051267;
UPDATE `creature` SET `StringId`="dawntracker_briarpatch" WHERE `guid`=1051270;

DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (165360,175034);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`) VALUES
(165360,164605,NULL,NULL),
(175034,166918,NULL,NULL);

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (165360,175034);
INSERT INTO `creature_equip_template` (`CreatureID`,`ID`,`ItemID1`,`AppearanceModID1`,`ItemVisual1`,`ItemID2`,`AppearanceModID2`,`ItemVisual2`,`ItemID3`,`AppearanceModID3`,`ItemVisual3`,`VerifiedBuild`) VALUES
(165360,1,163887,0,0,163891,0,0,0,0,0,50000),
(175034,1,165616,0,0,0,0,0,0,0,0,50000);

UPDATE `creature_template` SET `ScriptName`="npc_leader_northbound" WHERE `entry` IN (165360,175034);

-- Spawn Conditions for 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry`=156651 AND `ConditionValue1`=55173;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry`=166906 AND `ConditionValue1`=59935;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,156651,0,0,47,0,55173,1,0,0,0,0,'','Spawn of creature with entry 156651 requires Quest 55173 not taken'),
(32,5,166906,0,0,47,0,59935,1,0,0,0,0,'','Spawn of creature with entry 166906 requires Quest 59935 not taken');
-- Spawn Conditions for 
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=32 AND `SourceGroup`=5 AND `SourceEntry` IN (156662,166997) AND `SourceId`=0 AND `ElseGroup`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(32,5,156662,0,0,1,0,305660,0,0,1,0,0,'','Spawn of creature with entry 156662 if player does not has aura 305660'),
(32,5,166997,0,0,1,0,344382,0,0,1,0,0,'','Spawn of creature with entry 166997 if player does not has aura 344382');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (305661,344383,305665,344385);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305661,'spell_summon_leader_northbound'),
(344383,'spell_summon_leader_northbound'),
(305665,'spell_scene_linger_northbound'),
(344385,'spell_scene_linger_northbound');

DELETE FROM `quest_template_addon` WHERE `ID` IN (55173,59935);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(55173,0,0,0,'quest_northbound_alliance'), -- Alliance
(59935,0,0,0,'quest_northbound_horde'); -- Horde

DELETE FROM `phase_area` WHERE `AreaId`=10452 AND `PhaseId` IN (13846,15312);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10452,13846, 'Cosmetic - NPE - Austin Huxworth scout at Quilboar Briarpatch'),
(10452,15312, 'Cosmetic - NPE - Mithdran Dawntracker scout at Quilboar Briarpatch');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13846,15312) AND `SourceEntry` IN (10452);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13846,10452,0,0,47,0,55173,74,0,0,0,0,'','Apply PHASE 13846 IF Quest 55173 IS in Progress | complete | rewarded'),
(26,13846,10452,0,0,47,0,55186,74,0,1,0,0,'','Apply PHASE 13846 IF Quest 55186 IS NOT in Progress | complete | rewarded'),
(26,13846,10452,0,1,47,0,55173,74,0,0,0,0,'','Apply PHASE 13846 IF Quest 55173 IS in Progress | complete | rewarded'),
(26,13846,10452,0,1,47,0,55184,74,0,1,0,0,'','Apply PHASE 13846 IF Quest 55184 IS NOT in Progress | complete | rewarded'),
(26,15312,10452,0,0,47,0,59935,74,0,0,0,0,'','Apply PHASE 15312 IF Quest 59935 IS in Progress | complete | rewarded'),
(26,15312,10452,0,0,47,0,59938,74,0,1,0,0,'','Apply PHASE 15312 IF Quest 59938 IS NOT in Progress | complete | rewarded'),
(26,15312,10452,0,1,47,0,59935,74,0,0,0,0,'','Apply PHASE 15312 IF Quest 59935 IS in Progress | complete | rewarded'),
(26,15312,10452,0,1,47,0,59939,74,0,1,0,0,'','Apply PHASE 15312 IF Quest 59939 IS NOT in Progress | complete | rewarded');

-- Conversation leaders
DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12066,14499,12070);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12066,71310,0,1,0,0,0,0,45745), -- Alliance Leader
(12066,71297,0,2,0,0,0,0,45745), -- Alliance Survivor
(14499,79890,0,1,0,0,0,0,45745), -- Horde Leader
(14499,79888,0,2,0,0,0,0,45745), -- Horde Survivor
(12070,71317,0,0,0,0,0,0,45745), -- Alliance guy
(12070,76319,0,1,0,0,0,0,45745); -- Horde guy

DELETE FROM `conversation_line_template` WHERE `Id` IN (29348,29349,29350,29351,36300,36301,36302,36303,29367,36321);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29348,0,0,0,45745), -- Player
(29349,0,1,0,45745), -- Alliance
(29350,0,2,0,45745), -- Alliance
(29351,0,1,0,45745), -- Alliance
(36300,0,0,0,45745), -- Player
(36301,0,1,0,45745), -- Horde
(36302,0,2,0,45745), -- Horde
(36303,0,1,0,45745), -- Horde
(29367,0,0,0,45745), -- Alliance
(36321,0,1,0,45745); -- Horde

DELETE FROM `conversation_template` WHERE `Id` IN (12066,14499,12070);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12066,29348,0,'',45745),
(14499,36300,0,'',45745),
(12070,29367,0,'',45745);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=29 AND `SourceEntry` IN (29348,29349,29350,29351,36300,36301,36302,36303,29367,36321);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(29,0,29367,0,0,6,0,469,0,0,0,0,0,'','Allow conversation line 29367 if team is Alliance'),
(29,0,36321,0,0,6,0,67,0,0,0,0,0,'','Allow conversation line 36321 if team is Horde');
