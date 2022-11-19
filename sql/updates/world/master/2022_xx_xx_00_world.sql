-- Sanctum of Domination
 
SET @CGUID := 1200000;
SET @OGUID := 650000;

-- Instance stuff
DELETE FROM `access_requirement` WHERE `mapId`=2450;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES 
(2450, 17, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sanctum of Domination - Looking for Raid Mode'),
(2450, 14, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sanctum of Domination - Normal Mode'),
(2450, 15, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sanctum of Domination - Heroic Mode'),
(2450, 16, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sanctum of Domination - Mythic Mode');

DELETE FROM `instance_template` WHERE `map`=2450;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2450, 0, 'instance_sanctum_of_domination');

-- TODO: find out if her encounter ends with her npcId or a spell on players, most likely a spell since she's feigning death.
DELETE FROM `instance_encounters` WHERE `entry`=2435;
INSERT INTO `instance_encounters` (`entry`, `creditType`, `creditEntry`, `lastEncounterDungeon`, `comment`) VALUES 
(2435, 0, 0, 2224, 'Sylvanas Windrunner');

-- TODO: find out why even after setting the correct worldstates, it won't allow entrance without GM on.
-- Not entirely sure if Testing State is correct. It might refer to Closed instead and Open State could be Week of Release reached.
DELETE FROM `world_state` WHERE `ID` IN (20348, 20346, 20545, 20546, 20547, 20549, 20550, 20551, 20552, 20554, 20555, 20556, 20557, 20558);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES 
(20348, 1, '2450', NULL, '', 'Sanctum of Domination - Sylvanas Windrunner - Encounter phase'),
(20346, 0, '2450', NULL, '', 'Sanctum of Domination - Sylvanas Windrunner - Encounter started'),
(20545, 0, '2450', NULL, '', 'Sanctum of Domination - Normal difficulty - Testing State'),
(20546, 0, '2450', NULL, '', 'Sanctum of Domination - Heroic difficulty - Testing State'),
(20547, 0, '2450', NULL, '', 'Sanctum of Domination - Mythic difficulty - Testing State'),
(20549, 0, '2450', NULL, '', 'Sanctum of Domination - LFR difficulty: The Jailer\'s Vanguard - Testing State'),
(20550, 0, '2450', NULL, '', 'Sanctum of Domination - LFR difficulty: The Dark Bastille - Testing State'),
(20551, 0, '2450', NULL, '', 'Sanctum of Domination - LFR difficulty: Shackles of Fate - Testing State'),
(20552, 0, '2450', NULL, '', 'Sanctum of Domination - LFR difficulty: The Reckoning - Testing State'),
(20554, 1, '2450', NULL, '', 'Sanctum of Domination - Normal and Heroic difficulties - Open State'),
(20555, 1, '2450', NULL, '', 'Sanctum of Domination - Mythic difficulty and LFR difficulty: The Jailer\'s Vanguard - Open State'),
(20556, 1, '2450', NULL, '', 'Sanctum of Domination - LFR difficulty: The Dark Bastille - Open State'),
(20557, 1, '2450', NULL, '', 'Sanctum of Domination - LFR difficulty: Shackles of Fate - Open State'),
(20558, 1, '2450', NULL, '', 'Sanctum of Domination - LFR difficulty: The Reckoning - Open State');

-- Spikes (Pinnacle of Domination)
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (368743, 368744, 368745, 368746, 368747, 368748, 368749, 368750, 368751, 368752, 368753, 368754);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `WorldEffectID`, `AIAnimKitID`) VALUES 
(368743, 1375, 0, 0, 0, 0, 0),
(368744, 1375, 0, 0, 0, 0, 0),
(368745, 1375, 0, 0, 0, 0, 0),
(368746, 1375, 0, 0, 0, 0, 0),
(368747, 1375, 0, 0, 0, 0, 0),
(368748, 1375, 0, 0, 0, 0, 0),
(368749, 1375, 0, 0, 0, 0, 0),
(368750, 1375, 0, 0, 0, 0, 0),
(368751, 1375, 0, 0, 0, 0, 0),
(368752, 1375, 0, 0, 0, 0, 0),
(368753, 1375, 0, 0, 0, 0, 0),
(368754, 1375, 0, 0, 0, 0, 0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 368743, 2450, 13561, 13653, '14,15,16,17', 0, 0, 305.796173095703125, -801.1678466796875, 4105.228515625, 3.535023689270019531, 0, 0, -0.9807138442993164, 0.19544917345046997, 7200, 255, 1, 41079),
(@OGUID+1, 368744, 2450, 13561, 13653, '14,15,16,17', 0, 0, 289.4208984375, -775.50555419921875, 4105.228515625, 3.957568168640136718, 0, 0, -0.91792106628417968, 0.396763056516647338, 7200, 255, 1, 41079),
(@OGUID+2, 368745, 2450, 13561, 13653, '14,15,16,17', 0, 0, 263.83319091796875, -759.12677001953125, 4105.228515625, 4.214824676513671875, 0, 0, -0.85944366455078125, 0.51123046875, 7200, 255, 1, 41079),
(@OGUID+3, 368746, 2450, 13561, 13653, '14,15,16,17', 0, 0, 206.823974609375, -759.0166015625, 4105.228515625, 5.038183212280273437, 0, 0, -0.58306884765625, 0.812422752380371093, 7200, 255, 1, 41079),
(@OGUID+4, 368747, 2450, 13561, 13653, '14,15,16,17', 0, 0, 181.166412353515625, -776.0484619140625, 4105.228515625, 5.486774444580078125, 0, 0, -0.38776493072509765, 0.921758294105529785, 7200, 255, 1, 41079),
(@OGUID+5, 368748, 2450, 13561, 13653, '14,15,16,17', 0, 0, 164.420166015625, -801.205810546875, 4105.228515625, 5.90371561050415039, 0, 0, -0.1885986328125, 0.98205423355102539, 7200, 255, 1, 41079),
(@OGUID+6, 368749, 2450, 13561, 13653, '14,15,16,17', 0, 0, 164.071502685546875, -858.43328857421875, 4105.228515625, 0.348650813102722167, 0, 0, 0.173443794250488281, 0.984843790531158447, 7200, 255, 1, 41079),
(@OGUID+7, 368750, 2450, 13561, 13653, '14,15,16,17', 0, 0, 181.0986328125, -884.01446533203125, 4105.22900390625, 0.774075925350189208, 0, 0, 0.377447128295898437, 0.926031172275543212, 7200, 255, 1, 41079),
(@OGUID+8, 368751, 2450, 13561, 13653, '14,15,16,17', 0, 0, 206.4611053466796875, -900.602294921875, 4105.22900390625, 1.173270940780639648, 0, 0, 0.553562164306640625, 0.832807838916778564, 7200, 255, 1, 41079),
(@OGUID+9, 368752, 2450, 13561, 13653, '14,15,16,17', 0, 0, 263.236236572265625, -900.9161376953125, 4105.22900390625, 1.914117217063903808, 0, 0, 0.817501068115234375, 0.57592707872390747, 7200, 255, 1, 41079),
(@OGUID+10, 368753, 2450, 13561, 13653, '14,15,16,17', 0, 0, 288.707855224609375, -884.2554931640625, 4105.22900390625, 2.352296829223632812, 0, 0, 0.923131942749023437, 0.384483277797698974, 7200, 255, 1, 41079), 
(@OGUID+11, 368754, 2450, 13561, 13653, '14,15,16,17', 0, 0, 305.86798095703125, -858.4576416015625, 4105.22900390625, 2.739951372146606445, 0, 0, 0.979903221130371093, 0.199473500251770019, 7200, 255, 1, 41079);
 
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+1, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+2, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+3, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+4, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+5, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+6, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+7, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+8, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+9, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+10, 0, 0, 0.000000087422776573, 1, 0, 0),
(@OGUID+11, 0, 0, 0.000000087422776573, 1, 0, 0);

-- Areatrigger Check Z
DELETE FROM `areatrigger_template` WHERE `Id`=7 AND `IsServerSide`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES 
(7, 1, 1, 0, 250, 250, 5, 0, 0, 0, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId` IN (7, 8, 9, 10);
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES 
(7, 7, 1, 2450, 235.217, -830.563, 4094.99, 2.6387, 0, 0, 0, 1, 250, 250, 3, 5, 0, 0, 0, 0, 'at_sylvanas_windrunner_z_check', 'Sanctum of Domination - Pinnacle of Dominance (Z Check)'),
(8, 7, 1, 2450, -115.461, -1102.84, 4976.29, 0.7831, 0, 0, 0, 1, 250, 250, 3, 5, 0, 0, 0, 0, 'at_sylvanas_windrunner_z_check', 'Sanctum of Domination - Edge of the Abyss (Z Check)'),
(9, 7, 1, 2450, 225.434, -766.006, 4983.74, 3.9239, 0, 0, 0, 1, 250, 250, 3, 5, 0, 0, 0, 0, 'at_sylvanas_windrunner_z_check', 'Sanctum of Domination - Edge of the Abyss (Z Check)'),
(10, 7, 1, 2450, -249.124, -1277.07, 5605.18, 5.48411, 0, 0, 0, 1, 250, 250, 3, 5, 0, 0, 0, 0, 'at_sylvanas_windrunner_z_check', 'Sanctum of Domination - The Crucible (Z Check)');

-- Areatrigger Introduction Conversation
DELETE FROM `areatrigger_template` WHERE `Id`=8 AND `IsServerSide`=1;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES 
(8, 1, 0, 0, 75, 75, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `areatrigger` WHERE `SpawnId`=11;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES 
(11, 8, 1, 2450, 234.9542, -829.9804, 4104.986, 0.0, 0, 0, 0, 0, 75, 75, 0, 0, 0, 0, 0, 0, 'at_sylvanas_windrunner_introduction', 'Sanctum of Domination - Pinnacle of Dominance (Conv. Introduction)');

-- Throne of the Damned (Teleporter from Pinnacle of Domination to Throne of the Damned)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=190, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=1, `CreatureDifficultyID`=204469 WHERE `entry`=180803;

DELETE FROM `creature_template_addon` WHERE `entry`=180803;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(180803, 0, 0, 0, 1, 0, 0, 0, 4, 0, '355809');

DELETE FROM `creature_template_scaling` WHERE `Entry`=180803;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(180803, 14, 0, 0, 2104, 41488),
(180803, 15, 0, 0, 2105, 41488),
(180803, 16, 0, 0, 2106, 41488),
(180803, 17, 0, 0, 2107, 41488);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=180803;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(180803, 0, 0, 1, 1, 0, 0);

DELETE FROM `creature` WHERE `guid`=@CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+1, 180803, 2450, 13561, 13653, '14,15,16,17', 0, 0, 0, -1, 0, 1, 284.060760498046875, -781.0867919921875, 4105.0224609375, 3.911483526229858398, 7200, 0, 0, 46116, 0, 0, 0, 0, 0, 0, 0, '', 41079);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=180803 AND `spell_id`=358839;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(180803, 358839, 1, 0);

DELETE FROM `spell_target_position` WHERE `ID`=358839 AND `EffectIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES 
(358839, 0, 2450, 233.3006, -540.5422, 3707.7519, 41079);

-- Sylvanas Windrunner
UPDATE `creature_template` SET `minlevel`=63, `maxlevel`=63, `faction`=16, `BaseAttackTime`=1000, `unit_flags`=832, `unit_flags3`=0, `VehicleId`=7461, `CreatureDifficultyID`=204624, `mechanic_immune_mask`=617299839, `ScriptName`='boss_sylvanas_windrunner' WHERE `entry`=175732; 

DELETE FROM `creature_template_addon` WHERE `entry`=175732;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(175732, 0, 0, 0, 0, 0, 0, 0, 0, 5, '');

DELETE FROM `creature_equip_template` WHERE `CreatureID`=175732;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(175732, 1, 185997, 0, 0, 185997, 0, 0, 181374, 0, 41079);

DELETE FROM `creature_template_scaling` WHERE `Entry`=175732;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(175732, 14, 3, 3, 2104, 41079),
(175732, 15, 3, 3, 2105, 41079),
(175732, 16, 3, 3, 2106, 41079),
(175732, 17, 3, 3, 2107, 41079);

DELETE FROM `creature_model_info` WHERE `DisplayID`=101311;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101311, 1.15358, 4, 1, 41359);

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+0, 175732, 2450, 13561, 13653, '14,15,16,17', 0, 0, 0, -1, 0, 1, 225.432, -843.832, 4105.07, 4.05589, 7200, 0, 0, 33925767, 100, 0, 0, 0, 0, 0, 0, '', 41079);

-- TODO: mythic lines for Black Arrow are missing.
DELETE FROM `creature_text` WHERE `CreatureID`=175732;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(175732, 0, 0, 'Very well. Death it is!', 14, 0, 100, 0, 0, 181475, 0, 210319, 0, 'Aggro'),
(175732, 1, 0, 'Fall, hero!', 14, 0, 100, 0, 0, 181499, 0, 210320, 0, 'Slay 01'),
(175732, 1, 1, 'Fuel for the Maw!', 14, 0, 100, 0, 0, 181500, 0, 210321, 0, 'Slay 02'),
(175732, 1, 2, 'You always were weak!', 14, 0, 100, 0, 0, 181501, 0, 210322, 0, 'Slay 03'),
(175732, 2, 0, 'The cycle will be broken. At long last, we will have justice.', 14, 0, 100, 0, 0, 181476, 0, 210323, 0, 'Disengage'),
(175732, 3, 0, '|TInterface\\ICONS\\Achievement_Leader_Sylvanas.blp:20|t %s obtains |cFFFF0000|Hspell:347504|h[Windrunner]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Windrunner warning'),
(175732, 4, 0, 'No mercy!', 14, 0, 100, 0, 0, 181471, 0, 210324, 0, 'Shadow Dagger'),
(175732, 5, 0, 'To the death!', 14, 0, 100, 0, 0, 181473, 0, 210326, 0, 'Desecrating Shot'),
(175732, 6, 0, '|TInterface\\Icons\\ABILITY_THEBLACKARROW.BLP:20|t %s begins to cast |cFFFF0000|Hspell:347609|h[Wailing Arrow]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Wailing Arrow warning'),
(175732, 7, 0, '|TInterface\\Icons\\ABILITY_THEBLACKARROW.BLP:20|t You have been targetted by |cFFFF0000|Hspell:347609|h[Wailing Arrow]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 5, 'Wailing Arrow tank warning'),
(175732, 8, 0, 'I never miss!', 14, 0, 100, 0, 0, 181474, 0, 210327, 0, 'Wailing Arrow 01'),
(175732, 8, 1, 'I always hit my mark.', 14, 0, 100, 0, 0, 181470, 0, 210339, 0, 'Wailing Arrow 02'),
(175732, 9, 0, '|TInterface\\Icons\\INV_BELT_44.BLP:20|t %s begins to cast |cFFFF0000|Hspell:349458|h[Domination Chains]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Domination Chains warning'),
(175732, 10, 0, 'The past shackles you!', 14, 0, 100, 0, 0, 181344, 0, 210328, 0, 'Domination Chains'),
(175732, 11, 0, '|TInterface\\Icons\\Ability_Argus_DeathFog.blp:20|t %s begins to cast |cFFFF0000|Hspell:347704|h[Veil of Darkness]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Veil of Darkness warning'),
(175732, 12, 0, 'Darkness take you!', 14, 0, 100, 0, 0, 181341, 0, 211262, 0, 'Veil of Darkness 01 (Phase 1)'),
(175732, 13, 0, 'You are unfit to stand against me!', 14, 0, 100, 0, 0, 181345, 0, 210329, 0, 'Begin Intermission'),
(175732, 14, 0, '|TInterface\\ICONS\\SPELL_SHADOW_SOULLEECH_3.BLP:20|t %s begins to cast |cFFFF0000|Hspell:348109|h[Banshee Wail]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Banshee Wail warning'),
(175732, 15, 0, 'Your lives end here!', 14, 0, 100, 0, 0, 181337, 0, 210402, 0, 'Finish Intermission'),
(175732, 16, 0, '|TInterface\\ICONS\\UI_darkshore_warfront_horde_banshee.BLP:20|t %s begins to cast |cFFFF0000|Hspell:351869|h[Haunting Wave]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Haunting Wave warning'),
(175732, 17, 0, '|TInterface\\ICONS\\Ability_IronMaidens_ConvulsiveShadows.BLP:20|t %s begins to cast |cFFFF0000|Hspell:355540|h[Ruin]|h|r!', 41, 0, 100, 0, 0, 181479, 0, 0, 0, 'Ruin warning'),
(175732, 18, 0, 'I shattered your throne. Now I\'ll break you!', 14, 0, 100, 0, 0, 181529, 0, 210344, 0, 'Winds of Icecrown 01'),
(175732, 19, 0, 'All hope is lost!', 14, 0, 100, 0, 0, 181340, 0, 210338, 0, 'Veil of Darkness 01 (Phase 2-3)'),
(175732, 19, 1, 'Suffer my wrath!', 14, 0, 100, 0, 0, 181339, 0, 210342, 0, 'Veil of Darkness 02 (Phase 2-3)'),
(175732, 19, 2, 'Nothing escapes my wrath!', 14, 0, 100, 0, 0, 181339, 0, 210336, 0, 'Veil of Darkness 03 (Phase 2-3)'),
(175732, 19, 3, 'Fall into oblivion!', 14, 0, 100, 0, 0, 181347, 0, 211258, 0, 'Veil of Darkness 04 (Phase 2-3)'),
(175732, 20, 0, '|TInterface\\ICONS\\ABILITY_WARLOCK_IMPROVEDSOULLEECH.BLP:20|t %s begins to cast |cFFFF0000|Hspell:353955|h[Banshee Scream]|h|r!', 41, 0, 100, 0, 0, 181336, 0, 0, 0, 'Banshee Scream warning'),
(175732, 21, 0, 'Hear the sound of suffering!', 14, 0, 100, 0, 0, 181338, 0, 211266, 0, 'Banshee Wail and Scream 01'),
(175732, 21, 1, 'Death awaits you!', 14, 0, 100, 0, 0, 181336, 0, 210401, 0, 'Banshee Wail and Scream 02'),
(175732, 22, 0, 'You will pay. All of you will pay!', 14, 0, 100, 0, 0, 181530, 0, 210346, 0, 'Winds of Icecrown 02'),
(175732, 23, 0, 'Death bends to my will!', 14, 0, 100, 0, 0, 181343, 0, 210354, 0, 'Phase 3 Start'),
(175732, 24, 0, 'Heed the call of the Banshee Queen!', 14, 0, 100, 0, 0, 181334, 0, 210349, 0, 'Banshee\'s Fury 01'),
(175732, 25, 1, 'Hear my cry and despair!', 14, 0, 100, 0, 0, 181335, 0, 210350, 0, 'Banshee\'s Fury 02'),
(175732, 26, 0, '|TInterface\\ICONS\\Spell_AnimaMaw_GroundState.blp:20|t %s begins to cast |cFFFF0000|Hspell:354145|h[Raze]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Raze warning');

DELETE FROM `creature_text_locale` WHERE `CreatureID`=175732;
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`) VALUES 
(175732, 3, 0, 'esES', '|TInterface\\ICONS\\Achievement_Leader_Sylvanas.blp:20|t ¡%s obtiene |cFFFF0000|Hspell:347504|h[Brisaveloz]|h|r!'),
(175732, 9, 0, 'esES', '|TInterface\\Icons\\INV_BELT_44.BLP:20|t ¡%s empieza a lanzar |cFFFF0000|Hspell:349458|h[Cadenas de dominación]|h|r!'),
(175732, 6, 0, 'esES', '|TInterface\\Icons\\ABILITY_THEBLACKARROW.BLP:20|t ¡%s empieza a lanzar |cFFFF0000|Hspell:347609|h[Flecha lastimera]|h|r!'),
(175732, 7, 0, 'esES', '|TInterface\\Icons\\ABILITY_THEBLACKARROW.BLP:20|t ¡Te han marcado con |cFFFF0000|Hspell:347609|h[Flecha lastimera]|h|r!'),
(175732, 11, 0, 'esES', '|TInterface\\Icons\\Ability_Argus_DeathFog.blp:20|t ¡%s empieza a lanzar |cFFFF0000|Hspell:347704|h[Velo de oscuridad]|h|r!'),
(175732, 14, 0, 'esES', '|TInterface\\ICONS\\SPELL_SHADOW_SOULLEECH_3.BLP:20|t ¡%s empieza a lanzar |cFFFF0000|Hspell:348109|h[Lamento de alma en pena]|h|r!'),
(175732, 16, 0, 'esES', '|TInterface\\ICONS\\UI_darkshore_warfront_horde_banshee.BLP:20|t ¡%s empieza a lanzar |cFFFF0000|Hspell:351869|h[Oleada inquietante]|h|r!'),
(175732, 17, 0, 'esES', '|TInterface\\ICONS\\Ability_IronMaidens_ConvulsiveShadows.BLP:20|t ¡%s empieza a lanzar |cFFFF0000|Hspell:355540|h[Ruina]|h|r!'),
(175732, 20, 0, 'esES', '|TInterface\\ICONS\\ABILITY_WARLOCK_IMPROVEDSOULLEECH.BLP:20|t ¡%s empieza a lanzar |cFFFF0000|Hspell:353955|h[Alarido de alma en pena]|h|r!');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=175732;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(175732, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=175732;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(175732, 178355, 0, 0, 'Sylvanas Windrunner - Shadowcopy (Riding)', 6, 30000);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=175732;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES 
(175732, 0, 0, 176532, 243.661, -804.615, 4105.07, 4.28529, 8, 0, 'Thrall - Sylvanas Windrunner Encounter'),
(175732, 0, 0, 176533, 231.595, -801.5, 4105.07, 5.02181, 8, 0, 'Jaina - Sylvanas Windrunner Encounter'),
(175732, 0, 0, 178081, 239.795, -806.064, 4105.07, 4.77206, 8, 0, 'Bolvar - Sylvanas Windrunner Encounter');

-- Sylvanas Shadowcopy (Riding)
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=35653664, `unit_flags3`=1, `CreatureDifficultyID`=201696, `ScriptName`='npc_sylvanas_windrunner_shadowcopy_riding' WHERE `entry`=178355;

DELETE FROM `creature_template_addon` WHERE `entry`=178355;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(178355, 0, 0, 0, 1, 0, 0, 0, 0, 4, '');

DELETE FROM `creature_template_scaling` WHERE `Entry`=178355;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178355, 14, 0, 0, 2104, 41079),
(178355, 15, 0, 0, 2105, 41079),
(178355, 16, 0, 0, 2106, 41079),
(178355, 17, 0, 0, 2107, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=178355;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(178355, 1, 0, 1, 0, 0, 0);

-- Highlord Bolvar Fordragon
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=0, `speed_walk`=1.20000004768371582, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=0, `unit_flags3`=65568, `CreatureDifficultyID`=201344, `ScriptName`='npc_sylvanas_windrunner_bolvar' WHERE `entry`=178081;

DELETE FROM `creature_template_addon` WHERE `entry`=178081;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(178081, 0, 0, 0, 0, 1, 506, 0, 0, 0, 5, '');

DELETE FROM `creature_model_info` WHERE `DisplayID`=101964;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101964, 0.772164, 3.675, 0, 41359);

DELETE FROM `creature_template_scaling` WHERE `Entry` = 178081;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178081, 14, 0, 0, 837, 41079),
(178081, 15, 0, 0, 837, 41488),
(178081, 16, 0, 0, 837, 41079),
(178081, 17, 0, 0, 837, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=178081;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(178081, 1, 0, 0, 0, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID`=178081;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(178081, 0, 0, 'Behind our quarry. Heroes, with me!', 14, 0, 100, 0, 0, 181488, 0, 210387, 0, ''),
(178081, 1, 0, 'By the Light! He\'s expanding the Maw around Oribos!', 14, 0, 100, 0, 0, 181477, 0, 211265, 0, ''),
(178081, 2, 0, 'The Banshee is aiming at our heads!', 14, 0, 100, 0, 0, 181479, 0, 211259, 0, ''),
(178081, 3, 0, 'This power is not yours to command!', 14, 0, 100, 0, 0, 181602, 0, 210390, 0, ''),
(178081, 4, 0, 'Your crusade ends here, Banshee! ', 14, 0, 100, 0, 0, 181523, 0, 211458, 0, ''),
(178081, 5, 0, 'Thrall, scout ahead. Champions, we\'ll assist the admiral!', 14, 0, 100, 0, 0, 181570, 0, 211261, 0, ''),
(178081, 6, 0, 'Thrall won\'t last much longer on his own. We need to reach him!', 14, 0, 100, 0, 0, 181578, 0, 211270, 0, ''),
(178081, 7, 0, 'Sylvanas means to claim our heads! Stop her!', 14, 0, 100, 0, 0, 181480, 0, 211267, 0, ''),
(178081, 8, 0, 'Press the attack! The Jailer must be stopped.', 14, 0, 100, 0, 0, 181478, 0, 211264, 0, ''),
(178081, 9, 0, 'We\'re done with your games, Sylvanas!', 14, 0, 100, 0, 0, 181603, 0, 210391, 0, ''),
(178081, 10, 0, 'This time you\'ll lose, Sylvanas!', 14, 0, 100, 0, 0, 181524, 0, 211459, 0, ''),
(178081, 11, 0, 'No! The Jailer is going to destroy the Arbiter!', 14, 0, 100, 0, 0, 181604, 0, 211464, 0, '');

-- Thrall
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=35, `npcflag`=0, `speed_walk`=1.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=0, `unit_flags3`=65568, `CreatureDifficultyID`=199181, `ScriptName`='npc_sylvanas_windrunner_thrall' WHERE `entry`=176532;

DELETE FROM `creature_template_addon` WHERE `entry`=176532;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(176532, 0, 0, 0, 0, 1, 505, 0, 0, 0, 5, '');

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 176532;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(176532, 1, 168268, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_model_info` WHERE `DisplayID`=101963;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101963, 0.998133, 1.5, 0, 41359);

DELETE FROM `creature_template_scaling` WHERE `Entry` = 176532;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(176532, 14, 2, 2, 2104, 41079),
(176532, 15, 2, 2, 2105, 41488),
(176532, 16, 2, 2, 2106, 41488),
(176532, 17, 2, 2, 2107, 41488);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=176532;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(176532, 1, 0, 0, 0, 0, 0);

DELETE FROM `creature_text` WHERE `CreatureID`=176532;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(176532, 0, 0, 'Blood and thunder!', 14, 0, 100, 0, 0, 181590, 0, 210382, 0, ''),
(176532, 1, 0, 'I\'ve opened the way! Go! Stop Sylvanas!', 14, 0, 100, 0, 0, 181580, 0, 210371, 0, ''),
(176532, 2, 0, 'Yield, Sylvanas!', 14, 0, 100, 0, 0, 181527, 0, 211453, 0, ''),
(176532, 3, 0, 'With me, champions! Jaina needs our strength!', 14, 0, 100, 0, 0, 181579, 0, 210373, 0, ''),
(176532, 4, 0, 'My defenses falter!', 14, 0, 100, 0, 0, 181577, 0, 210386, 0, ''),
(176532, 5, 0, 'Is there no end to these creatures?!', 14, 0, 100, 0, 0, 181484, 0, 211450, 0, ''),
(176532, 6, 0, 'Their forces are numberless!', 14, 0, 100, 0, 0, 181483, 0, 211449, 0, ''),
(176532, 7, 0, 'I\'m in your debt, Highlord.', 12, 0, 100, 0, 0, 181534, 0, 210383, 0, ''),
(176532, 8, 0, 'Heroes, to me! Let\'s regroup with Jaina!', 14, 0, 100, 0, 0, 181581, 0, 210375, 0, ''),
(176532, 9, 0, 'For Saurfang! For the Horde! ', 14, 0, 100, 0, 0, 181528, 0, 211454, 0, ''),
(176532, 10, 0, 'The Arbiter\'s defenses are weakening! Stop the Jailer while we still can!', 14, 0, 100, 0, 0, 181606, 0, 211463, 0, '');

-- Lady Jaina Proudmoore
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `npcflag`=0, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=0, `unit_flags3`=65568, `CreatureDifficultyID`=199182, `ScriptName`='npc_sylvanas_windrunner_jaina' WHERE `entry`=176533;

DELETE FROM `creature_template_addon` WHERE `entry`=176533;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `MountCreatureID`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(176533, 0, 0, 0, 0, 1, 654, 0, 0, 0, 5, '');

DELETE FROM `creature_template_scaling` WHERE `Entry` = 176533;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(176533, 14, 0, 0, 2104, 41488),
(176533, 15, 0, 0, 2105, 41488),
(176533, 16, 0, 0, 2106, 41488),
(176533, 17, 0, 0, 2107, 41488);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=176533;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(176533, 1, 0, 0, 0, 0, 0);

DELETE FROM `creature_equip_template` WHERE `CreatureID`=176533;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(176533, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_model_info` WHERE `DisplayID`=101962;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101962, 0.652598, 0, 1, 41359);

DELETE FROM `creature_text` WHERE `CreatureID`=176533;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(176533, 0, 0, 'Something is limiting my magic. Where are we?', 12, 0, 100, 0, 0, 181487, 0, 210368, 0, ''),
(176533, 1, 0, 'Is the Jailer trying to break out of the Maw... or something else?', 12, 0, 100, 0, 0, 181489, 0, 211274, 0, ''),
(176533, 2, 0, 'Heroes! I need aid!', 14, 0, 100, 0, 0, 181569, 0, 210366, 0, ''),
(176533, 3, 0, 'There\'s too many of them!', 14, 0, 100, 0, 0, 181482, 0, 211452, 0, ''),
(176533, 4, 0, 'Thank you, Bolvar.', 12, 0, 100, 0, 0, 181533, 0, 210367, 0, ''),
(176533, 5, 0, 'Quickly, champions! Stop Sylvanas!', 14, 0, 100, 0, 0, 181584, 0, 210358, 0, ''),
(176533, 6, 0, 'Hurry! Thrall needs us!', 14, 0, 100, 0, 0, 181583, 0, 210359, 0, ''),
(176533, 7, 0, 'You don\'t have to do this! Surrender! ', 14, 0, 100, 0, 0, 181526, 0, 211456, 0, ''),
(176533, 8, 0, 'Sylvanas! Give Anduin to me!', 14, 0, 100, 0, 0, 181525, 0, 211455, 0, ''),
(176533, 9, 0, 'We\'re out of time! Oribos is being enveloped by the Maw!', 14, 0, 100, 0, 0, 181490, 0, 211271, 0, ''),
(176533, 10, 0, 'Hold them back a little longer. The portal\'s nearly open!', 14, 0, 100, 0, 0, 181491, 0, 210369, 0, ''),
(176533, 11, 0, 'It\'s done! Hurry! ', 14, 0, 100, 0, 0, 181492, 0, 210370, 0, ''),
(176533, 12, 0, 'He\'s done it. The Arbiter falls...', 14, 0, 100, 0, 0, 181499, 0, 211465, 0, '');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=17368;
INSERT INTO `conversation_template` (`Id`, `FirstLineId`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES 
(17368, 44215, 0, 'conversation_sylvanas_windrunner_introduction', 41079);

DELETE FROM `conversation_actors` WHERE `ConversationId`=17368;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES 
(17368, 80339, 1200000, 0, 0, 0, 41079);

DELETE FROM `conversation_line_template` WHERE `Id` IN (44219, 44218, 44217, 44216, 44215);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(44219, 0, 0, 1, 41079),
(44218, 0, 0, 1, 41079),
(44217, 0, 1, 1, 41079),
(44216, 0, 0, 1, 41079),
(44215, 0, 0, 1, 41079);