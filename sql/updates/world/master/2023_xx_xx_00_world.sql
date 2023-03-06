-- Sepulcher of the First Ones

SET @CGUID := 1600000; -- Insert highest based on your db
SET @OGUID := 700000; -- Insert highest based on your db

-- Instance
DELETE FROM `access_requirement` WHERE `mapId`=2481;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES 
(2481, 16, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones - Mythic Mode'),
(2481, 15, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones- Heroic Mode'),
(2481, 14, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones - Normal Mode'),
(2481, 17, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones - Looking for Raid Mode');

DELETE FROM `instance_template` WHERE `map`=2481;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2481, 0, 'instance_sepulcher_of_the_first_ones');

-- Game Objects
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (375110, 375035, 375901);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(375110, 0, 16, 0, 0), -- 375110
(375035, 0, 16, 0, 0), -- 375035
(375901, 94, 2113568, 0, 0);

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+3;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 375110, 2481, 13742, 13965, '14,15,16,17', '0', 0, -3824.822265625, -2658.32080078125, 83.4433746337890625, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 46366),
(@OGUID+1, 375035, 2481, 13742, 13965, '14,15,16,17', '0', 0, -3825.06591796875, -2785.4755859375, 88.5488128662109375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 46366);

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- 375110
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0); -- 375035

-- Anduin Wrynn
UPDATE `creature_template` SET `faction`=35, `speed_walk`=4.40000009536743164, `speed_run`=1.571428537368774414, `unit_flags`=80, `ScriptName`='boss_anduin_wrynn' WHERE `entry`=181954; -- Anduin Wrynn
UPDATE `creature_template` SET `type_flags`=2097260, `type_flags2`=65664, `HealthModifier`=996.3599853515625, `CreatureDifficultyID`=209715, `VerifiedBuild`=46366 WHERE `entry`=181954; -- Anduin Wrynn

DELETE FROM `creature_template_addon` WHERE `entry` IN (181954);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(181954, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (181954);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(181954, 1, 183938, 0, 0, 0, 0, 0, 0, 0, 0, 46366); -- 181954

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (181954);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(181954, 14, 3, 3, 2165, 43206),
(181954, 15, 3, 3, 2166, 43206),
(181954, 16, 3, 3, 2167, 43206),
(181954, 17, 3, 3, 2168, 43206);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (181954);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(181954, 0, 105386, 2.65000009536743164, 1, 46366); -- 181954

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (105386);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(105386, 0.989952623844146728, 5.300000190734863281, 0, 46366);

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 181954, 2481, 13742, 13965, '0', '0', 0, 0, 1, -3825.05908203125, -2715.45654296875, 91.356658935546875, 1.626035571098327636, 7200, 0, 0, 44483488, 100, 0, 0, 0, 0, 46366);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=181954;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES 
(181954, 0, 0, 183666, -3819.48, -2687.19, 91.3485, 4.5587, 8, 0, 'Sylvanas - Anduin Wrynn Encounter'),
(181954, 0, 0, 183665, -3828.03, -2688.25, 91.3485, 5.46062, 8, 0, 'Uther - Anduin Wrynn Encounter'),
(181954, 0, 0, 183664, -3824.65, -2692.2, 91.3485, 4.64412, 8, 0, 'Jaina - Anduin Wrynn Encounter');

DELETE FROM `creature_text` WHERE `CreatureID`=181954;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(181954, 0, 0, 'Your reality ends here!', 14, 0, 100, 0, 0, 190135, 0, 214636, 0, 'Aggro'),
(181954, 1, 0, 'Break!', 14, 0, 100, 0, 0, 190054, 0, 214962, 0, 'Hopebreaker'),
(181954, 2, 0, 'Darkness consumes light!', 14, 0, 100, 0, 0, 190056, 0, 214961, 0, 'Befouled Barrier'),
(181954, 3, 0, 'There is no balance!', 14, 0, 100, 0, 0, 190055, 0, 214960, 0, 'Blasphemy'),
(181954, 4, 0, '|TInterface\\ICONS\\Ability_Priest_FocusedWill.blp:20|t Anduin begins casting |cFFFF0000|Hspell:361989|h[Blasphemy]|h|r!', 41, 0, 100, 0, 0, 53980, 0, 0, 0, 'Blasphemy Warning'),
(181954, 5, 0, '|TInterface\\ICONS\\Ability_Deathknight_HungeringRuneblade.BLP:20|t Anduin begins casting |cFFFF0000|Hspell:362405|h[Kingsmourne Hungers]|h|r!', 41, 0, 100, 0, 0, 190057, 0, 0, 0, 'Kingsmourne Warning'),
(181954, 6, 0, 'Kingsmourne hungers!', 14, 0, 100, 0, 0, 190057, 0, 214963, 0, 'Kingsmourne Hungers'),
(181954, 7, 0, 'Your end has come!', 14, 0, 100, 0, 0, 190052, 0, 214954, 0, 'Wicked Star'),
(181954, 8, 0, '|TInterface\\ICONS\\Spell_Priest_DivineStar_Shadow2.blp:20|t Anduin targets you with |cFFFF0000|Hspell:365017|h[Wicked Star]|h|r!', 14, 0, 100, 0, 0, 0, 0, 0, 0, 'Wicked Star Warning'),
(181954, 9, 0, 'Terrors, arise and obey!', 14, 0, 100, 0, 0, 190058, 0, 214966, 0, 'Summoning'),
(181954, 10, 0, 'Kneel!', 14, 0, 100, 0, 0, 190120, 0, 214637, 0, 'Slay 01'),
(181954, 10, 1, 'Submit!', 14, 0, 100, 0, 0, 190121, 0, 214638, 0, 'Slay 02'),
(181954, 11, 0, 'Fall!', 14, 0, 100, 0, 0, 190053, 0, 214955, 0, 'Empowered Hopebreaker'),
(181954, 12, 0, 'The Light has abandoned you.', 14, 0, 100, 0, 0, 190122, 0, 214639, 0, 'Reset');

-- Jaina Proudmoore
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=32832, `ScriptName`='npc_anduin_wrynn_jaina' WHERE `entry`=183664; -- Lady Jaina Proudmoore

DELETE FROM `creature_template_addon` WHERE `entry` IN (183664);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(183664, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''); -- 183664

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (183664);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183664, 14, 3, 3, 2165, 43206),
(183664, 15, 3, 3, 2166, 43206),
(183664, 16, 3, 3, 2167, 43206),
(183664, 17, 3, 3, 2168, 43206);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183664);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183664, 0, 104817, 1.5, 1, 43206);

DELETE FROM `creature_model_info` WHERE `DisplayID`=104817;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(104817, 0.435066, 0, 0, 42979);

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (183664);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(183664, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 43206); 

-- Uther the Lightbringer
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=32832, `ScriptName`='npc_anduin_wrynn_uther'  WHERE `entry`=183665; -- Uther the Lightbringer

DELETE FROM `creature_template_addon` WHERE `entry` IN (183665);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(183665, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (183665);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183665, 14, 3, 3, 2165, 43206),
(183665, 15, 3, 3, 2166, 43206),
(183665, 16, 3, 3, 2167, 43206),
(183665, 17, 3, 3, 2168, 43206);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183665);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183665, 0, 105509, 1, 1, 43206);

DELETE FROM `creature_model_info` WHERE `DisplayID`=105509;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(105509, 0.886239, 0.75, 0, 42979);

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (183665);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(183665, 1, 173369, 0, 0, 0, 0, 0, 0, 0, 0, 43206);

-- Sylvanas Windrunner
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=32832, `ScriptName`='npc_anduin_wrynn_sylvanas'  WHERE `entry`=183666; -- Sylvanas Windrunner

DELETE FROM `creature_template_addon` WHERE `entry` IN (183666);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(183666, 0, 0, 0, 1, 0, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (183666);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183666, 14, 3, 3, 2165, 43206),
(183666, 15, 3, 3, 2166, 43206),
(183666, 16, 3, 3, 2167, 43206),
(183666, 17, 3, 3, 2168, 43206);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183666);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183666, 0, 102134, 1.70000004768371582, 1, 43206); -- Sylvanas Windrunner

INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(102134, 0.580414, 1.25, 0, 42979);

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (183666);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(183666, 1, 0, 0, 0, 0, 0, 0, 42775, 0, 0, 46366); -- 183666

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (17921, 17923);
INSERT INTO `conversation_template` (`Id`, `FirstLineId`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES 
(17921, 45676, 0, 'conversation_arthas_uther', 46366),
(17923, 45757, 0, 'conversation_arthas_sylvanas', 46366),
(17924, 45674, 0, '', 43206); -- Anduin Phase 3

DELETE FROM `conversation_actors` WHERE `ConversationId`=17921;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES 
(17921, 82831, @CGUID+0, 0, 181954, 0, 0, 0, 43206),
(17921, 83275, 0, 1, 183665, 0, 0, 0, 43206);

DELETE FROM `conversation_actors` WHERE `ConversationId`=17923;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES 
(17923, 82831, @CGUID+0, 0, 181954, 0, 0, 0, 43206),
(17923, 83276, 0, 1, 183666, 0, 0, 0, 43206);

DELETE FROM `conversation_actors` WHERE `ConversationId`=17924;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES 
(17924, 82831, @CGUID+0, 0, 181954, 0, 0, 0, 43206); -- Phase Three Conversation

DELETE FROM `conversation_line_template` WHERE `Id` IN (45395, 45394, 45393, 45392, 45391, 45390, 45399, 45398, 45397, 45396, 45673, 45672, 45671, 45670, 45757, 45665, 45664, 45663, 45662, 45676, 41703, 41702, 41701, 41700, 41699, 41698, 41697, 45675, 45674);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(45395, 0, 4, 1, 43206),
(45394, 0, 3, 1, 43206),
(45393, 0, 0, 1, 43206),
(45392, 0, 2, 1, 43206),
(45391, 0, 1, 1, 43206),
(45390, 0, 0, 1, 43206),
(45399, 0, 2, 1, 43206),
(45398, 0, 0, 1, 43206),
(45397, 0, 1, 1, 43206),
(45396, 0, 0, 1, 43206),
(45673, 0, 0, 0, 43206),
(45672, 0, 0, 0, 43206),
(45671, 0, 0, 0, 43206),
(45670, 0, 1, 0, 43206),
(45757, 0, 0, 0, 43206),
(45665, 0, 0, 0, 43206),
(45664, 0, 0, 0, 43206),
(45663, 0, 0, 0, 43206),
(45662, 0, 1, 0, 43206),
(45676, 0, 0, 0, 43206),
(41703, 0, 1, 0, 43206),
(41702, 0, 0, 0, 43206),
(41701, 0, 1, 0, 43206),
(41700, 0, 1, 0, 43206),
(41699, 0, 0, 0, 43206),
(41698, 0, 1, 0, 43206),
(41697, 0, 0, 0, 43206),
(45675, 0, 0, 0, 43206),
(45674, 0, 0, 0, 43206);



