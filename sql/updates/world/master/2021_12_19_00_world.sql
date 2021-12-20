 -- Sanctum of Domination
SET @CGUID := 1200000;
SET @OGUID := 650000;

DELETE FROM `access_requirement` WHERE `mapId` IN (2450);
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES 
(2450, 14, 60, 65, 0, 0, 0, 0, 0, NULL, 'Sanctum of Domination - Normal Mode'),
(2450, 15, 60, 65, 0, 0, 0, 0, 0, NULL, 'Sanctum of Domination - Heroic Mode'),
(2450, 16, 60, 65, 0, 0, 0, 0, 0, NULL, 'Sanctum of Domination - Mythic Mode');

DELETE FROM `instance_template` WHERE `map` IN (2450);
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2450, 0, 'instance_sanctum_of_domination');

DELETE FROM `instance_encounters` WHERE `entry`=2435;
INSERT INTO `instance_encounters` (`entry`, `creditType`, `creditEntry`, `lastEncounterDungeon`, `comment`) VALUES 
(2435, 0, 0, 0, 'Sylvanas Windrunner'); -- TODO: find if her encounter ends with her Id or a spell on players

DELETE FROM `scene_template` WHERE `SceneId` IN (2798, 2723, 2799);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`, `Encrypted`) VALUES
(2798, 20, 3301, 0),
(2723, 20, 3218, 0),
(2799, 16, 3314, 0);

DELETE FROM `conversation_template` WHERE `Id` IN (17368, 17375);
INSERT INTO `conversation_template` (`Id`, `FirstLineId`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES 
(17368, 44215, 0, '', 41079),
(17375, 54141, 0, '', 41079);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (17368, 17375);
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `VerifiedBuild`) VALUES 
(17368, 80339, 1200000, 0, 0, 0, 41079),
(17368, 81173, 1200001, 1, 0, 0, 41079),
(17375, 81173, 0, 0, 0, 0, 41079),
(17375, 80411, 0, 1, 0, 0, 41079),
(17375, 80412, 0, 2, 0, 0, 41079);

DELETE FROM `conversation_line_template` WHERE `Id` IN (44219, 44218, 44217, 44216, 44215, 44244, 44245, 44246, 44247, 44248, 44249, 44250, 44251);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `VerifiedBuild`) VALUES
(44219, 0, 0, 1, 41079),
(44218, 0, 0, 1, 41079),
(44217, 0, 1, 1, 41079),
(44216, 0, 0, 1, 41079),
(44215, 0, 0, 1, 41079),
(44244, 0, 0, 0, 41079),
(44245, 0, 1, 0, 41079),
(44246, 0, 0, 0, 41079),
(44247, 0, 2, 0, 41079),
(44248, 0, 1, 0, 41079),
(44249, 0, 2, 0, 41079),
(44250, 0, 0, 0, 41079),
(44251, 0, 0, 1, 41079);

 -- Throne of the Damned
DELETE FROM `creature_template` WHERE `entry`=180803;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(180803, 'Throne of the Damned', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 190, 16777216, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 768, 67143680, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=180803 AND `spell_id`=358839;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(180803, 358839, 3, 3);

DELETE FROM `spell_target_position` WHERE `ID`=358839 AND `EffectIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES 
(358839, 0, 0, 0, 0, 0, 41079);

 -- Sylvanas Windrunner
DELETE FROM `creature_template` WHERE `entry`=175732;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(175732, 'Sylvanas Windrunner', NULL, NULL, NULL, NULL, 0, 63, 63, 8, 0, 0, 16, 0, 1.6, 2, 1, 3, 0, 1000, 1750, 1, 1, 4, 64, 1073741824, 8388610, 0, 0, 0, 0, 4, 0, 0, 0, 0, 7461, 0, 0, '', 0, 1, 1443.76, 1, 1, 1, 1, 1, 1, 0, 183, 204626, 0, 0, 1, 0, 0, 0, 'boss_sylvanas_windrunner', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=175732;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(175732, 0, 0, 0, 1, 0, 0, 0, 0, '42459 352311');

DELETE FROM `creature_equip_template` WHERE `CreatureID`=175732;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(175732, 1, 185997, 0, 0, 185997, 0, 0, 181374, 0, 41079);

DELETE FROM `creature_template_scaling` WHERE `Entry`=175732;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(175732, 14, 3, 3, 2104, 41079);

DELETE FROM `creature_model_info` WHERE `DisplayID`=101311;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101311, 1.15358, 4, 1, 41359);

DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+0, 175732, 2450, 13561, 13653, '14', 0, 0, 0, -1, 0, 1, 225.432, -843.832, 4105.07, 4.05589, 7200, 0, 0, 33925767, 100, 0, 0, 0, 0, 0, 0, '', 41079);

DELETE FROM `creature_summon_groups` WHERE `summonerId`=175732;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`) VALUES 
(175732, 0, 0, 178081, 239.795135498046875, -806.06427001953125, 4105.0732421875, 4.772064208984375, 7, 0),
(175732, 0, 0, 176533, 231.595489501953125, -801.5, 4105.07421875, 5.021806240081787109, 7, 0),
(175732, 0, 0, 176532, 243.6614532470703125, -804.61456298828125, 4105.07421875, 4.285292625427246093, 7, 0);

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
(175732, 7, 0, '|TInterface\\Icons\\ABILITY_THEBLACKARROW.BLP:20|t You have been targetted by |cFFFF0000|Hspell:347609|h[Wailing Arrow]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Wailing Arrow tank warning'),
(175732, 8, 0, 'I never miss!', 14, 0, 100, 0, 0, 181474, 0, 210327, 0, 'Wailing Arrow 01'),
(175732, 8, 1, 'I always hit my mark.', 14, 0, 100, 0, 0, 181470, 0, 210339, 0, 'Wailing Arrow 02'),
(175732, 9, 0, '|TInterface\\Icons\\INV_BELT_44.BLP:20|t %s begins to cast |cFFFF0000|Hspell:349458|h[Domination Chains]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Domination Chains warning'),
(175732, 10, 0, 'The past shackles you!', 14, 0, 100, 0, 0, 181344, 0, 210328, 0, 'Domination Chains'),
(175732, 11, 0, '|TInterface\\Icons\\Ability_Argus_DeathFog.blp:20|t %s begins to cast |cFFFF0000|Hspell:347704|h[Veil of Darkness]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Veil of Darkness warning'),
(175732, 12, 0, 'Darkness take you!', 14, 0, 100, 0, 0, 181341, 0, 211262, 0, 'Veil of Darkness'),
(175732, 13, 0, 'You are unfit to stand against me!', 14, 0, 100, 0, 0, 181345, 0, 210329, 0, 'Begin Intermission'),
(175732, 14, 0, 'Your lives end here!', 14, 0, 100, 0, 0, 181337, 0, 210402, 0, 'Finish Intermission'),
(175732, 25, 0, 'Death bends to my will!', 14, 0, 100, 0, 0, 181343, 0, 210354, 0, 'Phase 3 Start');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=175732;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(175732, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=175732;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(175732, 178355, 0, 0, 'Sylvanas Windrunner on top of Sylvanas', 6, 30000);

 -- Sylvanas Copy (Withering and Jump)
DELETE FROM `creature_template` WHERE `entry`=176369;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(176369, 'Sylvanas', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 33554432, 2099200, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_sylvanas_windrunner_sylvanas', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=176369;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(176369, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry`=176369;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(176369, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=176369;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(176369, 1, 0, 1, 0, 0, 0);

 -- Sylvanas Copy (Riding)
DELETE FROM `creature_template` WHERE `entry`=178355;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(178355, 'Sylvanas', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 33554432, 35653664, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7461, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=178355;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(178355, 0, 0, 50331648, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry`=178355;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178355, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=178355;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(178355, 1, 0, 1, 0, 0, 0);

 -- Domination Arrow
DELETE FROM `creature_template` WHERE `entry`=176920;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(176920, 'Domination Arrow', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 0, 4194304, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_sylvanas_windrunner_domination_arrow', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=176920;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(176920, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_model_info` WHERE `DisplayID`=100416;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(100416, 0.75, 1.5, 2, 41359);

DELETE FROM `creature_template_scaling` WHERE `Entry`=176920;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(176920, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=176920;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(176920, 1, 0, 0, 1, 0, 0);

 -- Ranger (Bow)
DELETE FROM `spell_script_names` WHERE `spell_id`=347560 AND `ScriptName`='spell_sylvanas_windrunner_ranger_bow';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(347560, 'spell_sylvanas_windrunner_ranger_bow');

 -- Ranger (Dagger)
DELETE FROM `spell_script_names` WHERE `spell_id`=348010 AND `ScriptName`='spell_sylvanas_windrunner_ranger_dagger';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(348010, 'spell_sylvanas_windrunner_ranger_dagger');

 -- Windrunner
DELETE FROM `jump_charge_params` WHERE `id`=529;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `jumpGravity`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`) VALUES 
(529, 0.501, 1, 47.8086, NULL, 0, NULL);

 -- Withering Fire
DELETE FROM `spell_script_names` WHERE `spell_id`=347928 AND `ScriptName`='spell_sylvanas_windrunner_withering_fire';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(347928, 'spell_sylvanas_windrunner_withering_fire');

 -- Desecrating Shot
DELETE FROM `spell_script_names` WHERE `spell_id`=348627 AND `ScriptName`='spell_sylvanas_windrunner_desecrating_shot';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(348627, 'spell_sylvanas_windrunner_desecrating_shot');

 -- Ranger Heartseeker
DELETE FROM `spell_script_names` WHERE `spell_id`=352663 AND `ScriptName`='spell_sylvanas_windrunner_ranger_heartseeker';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(352663, 'spell_sylvanas_windrunner_ranger_heartseeker');

 -- Ranger Heartseeker (Shadow damage)
DELETE FROM `spell_script_names` WHERE `spell_id`=352652 AND `ScriptName`='spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(352652, 'spell_sylvanas_windrunner_ranger_heartseeker_shadow_damage');

 -- Domination Chains
DELETE FROM `spell_script_names` WHERE `spell_id`=349419 AND `ScriptName`='spell_sylvanas_windrunner_domination_chains';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(349419, 'spell_sylvanas_windrunner_domination_chains');

 -- Domination Arrow (Fall)
DELETE FROM `spell_script_names` WHERE `spell_id`=352317 AND `ScriptName`='spell_sylvanas_windrunner_domination_arrow';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(352317, 'spell_sylvanas_windrunner_domination_arrow');

 -- Domination Arrow (Fall and Spawn)
DELETE FROM `spell_script_names` WHERE `spell_id`=352319 AND `ScriptName`='spell_sylvanas_windrunner_domination_arrow';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(352319, 'spell_sylvanas_windrunner_domination_arrow');

 -- Domination Chain (Player)
DELETE FROM `spell_script_names` WHERE `spell_id`=349451 AND `ScriptName`='spell_sylvanas_windrunner_domination_chain';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(349451, 'spell_sylvanas_windrunner_domination_chain');

 -- Domination Chain (Periodic)
DELETE FROM `spell_script_names` WHERE `spell_id`=349458 AND `ScriptName`='spell_sylvanas_windrunner_domination_chain_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(349458, 'spell_sylvanas_windrunner_domination_chain_periodic');

 -- Wailing Arrow
DELETE FROM `spell_script_names` WHERE `spell_id`=347609 AND `ScriptName`='spell_sylvanas_windrunner_wailing_arrow';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(347609, 'spell_sylvanas_windrunner_wailing_arrow');

 -- Wailing Arrow (Damage)
DELETE FROM `spell_script_names` WHERE `spell_id`=348056 AND `ScriptName`='spell_sylvanas_windrunner_wailing_arrow_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(348056, 'spell_sylvanas_windrunner_wailing_arrow_damage');

 -- Veil of Darkness (Phase 1 - Fade)
DELETE FROM `spell_script_names` WHERE `spell_id`=352470 AND `ScriptName`='spell_sylvanas_windrunner_veil_of_darkness_fade';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(352470, 'spell_sylvanas_windrunner_veil_of_darkness_fade');

 -- Veil of Darkness (Phase 1 - Cast)
DELETE FROM `spell_script_names` WHERE `spell_id`=347726 AND `ScriptName`='spell_sylvanas_windrunner_veil_of_darkness_phase_1';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(347726, 'spell_sylvanas_windrunner_veil_of_darkness_phase_1');

 -- Rive
DELETE FROM `spell_script_names` WHERE `spell_id`=353417 AND `ScriptName`='spell_sylvanas_windrunner_rive';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(353417, 'spell_sylvanas_windrunner_rive');

 -- Rive (Fast)
DELETE FROM `spell_script_names` WHERE `spell_id`=353418 AND `ScriptName`='spell_sylvanas_windrunner_rive_fast';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(353418, 'spell_sylvanas_windrunner_rive_fast');

 -- Banshee Wail
DELETE FROM `spell_script_names` WHERE `spell_id`=348094 AND `ScriptName`='spell_sylvanas_windrunner_banshee_wail';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(348094, 'spell_sylvanas_windrunner_banshee_wail');

 -- Banshee Wail (Marker)
DELETE FROM `spell_script_names` WHERE `spell_id`=357719 AND `ScriptName`='spell_sylvanas_windrunner_banshee_wail_marker';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(357719, 'spell_sylvanas_windrunner_banshee_wail_marker');

 -- Banshee Wail (Missile)
DELETE FROM `spell_script_names` WHERE `spell_id`=348133 AND `ScriptName`='spell_sylvanas_windrunner_banshee_wail_missile';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(348133, 'spell_sylvanas_windrunner_banshee_wail_missile');

 -- Banshee Wail (Triggered Missile)
DELETE FROM `spell_script_names` WHERE `spell_id`=348108 AND `ScriptName`='spell_sylvanas_windrunner_banshee_wail_triggered_missile';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(348108, 'spell_sylvanas_windrunner_banshee_wail_triggered_missile');

 -- Banshee Wail (Interrupt)
DELETE FROM `spell_script_names` WHERE `spell_id`=351252 AND `ScriptName`='spell_sylvanas_windrunner_banshee_wail_interrupt';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(351252, 'spell_sylvanas_windrunner_banshee_wail_interrupt');

 -- Veil of Darkness (Phase 2 - Fade)
DELETE FROM `spell_script_names` WHERE `spell_id`=353273 AND `ScriptName`='spell_sylvanas_windrunner_veil_of_darkness_fade';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(353273, 'spell_sylvanas_windrunner_veil_of_darkness_fade');

 -- Veil of Darkness (Phase 3 - Fade)
DELETE FROM `spell_script_names` WHERE `spell_id`=354168 AND `ScriptName`='spell_sylvanas_windrunner_veil_of_darkness_fade';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(354168, 'spell_sylvanas_windrunner_veil_of_darkness_fade');

 -- Activate Phase Intermission
DELETE FROM `spell_script_names` WHERE `spell_id`=359429 AND `ScriptName`='spell_sylvanas_windrunner_activate_phase_intermission';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(359429, 'spell_sylvanas_windrunner_activate_phase_intermission');

 -- Activate Phase Intermission
DELETE FROM `spell_script_names` WHERE `spell_id`=359431 AND `ScriptName`='spell_sylvanas_windrunner_activate_finish_boss';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(359431, 'spell_sylvanas_windrunner_activate_finish_boss');

 -- Torghast Spike
DELETE FROM `gameobject_template` WHERE `entry` IN (368743, 368744, 368745, 368746, 368747, 368748, 368749, 368750, 368751, 368752, 368753, 368754);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES 
(368743, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368744, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368745, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368746, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368747, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368748, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368749, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368750, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368751, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368752, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368753, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079),
(368754, 10, 69768, 'Torghast Spike', '', '', '', 0.854589, 0, 0, 0, 5000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', 41079);

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
(@OGUID+0, 368743, 2450, 13561, 13653, '14', 0, 0, 305.796173095703125, -801.1678466796875, 4105.228515625, 3.535023689270019531, 0, 0, -0.9807138442993164, 0.19544917345046997, 7200, 255, 1, 41079),
(@OGUID+1, 368744, 2450, 13561, 13653, '14', 0, 0, 289.4208984375, -775.50555419921875, 4105.228515625, 3.957568168640136718, 0, 0, -0.91792106628417968, 0.396763056516647338, 7200, 255, 1, 41079),
(@OGUID+2, 368745, 2450, 13561, 13653, '14', 0, 0, 263.83319091796875, -759.12677001953125, 4105.228515625, 4.214824676513671875, 0, 0, -0.85944366455078125, 0.51123046875, 7200, 255, 1, 41079),
(@OGUID+3, 368746, 2450, 13561, 13653, '14', 0, 0, 206.823974609375, -759.0166015625, 4105.228515625, 5.038183212280273437, 0, 0, -0.58306884765625, 0.812422752380371093, 7200, 255, 1, 41079),
(@OGUID+4, 368747, 2450, 13561, 13653, '14', 0, 0, 181.166412353515625, -776.0484619140625, 4105.228515625, 5.486774444580078125, 0, 0, -0.38776493072509765, 0.921758294105529785, 7200, 255, 1, 41079),
(@OGUID+5, 368748, 2450, 13561, 13653, '14', 0, 0, 164.420166015625, -801.205810546875, 4105.228515625, 5.90371561050415039, 0, 0, -0.1885986328125, 0.98205423355102539, 7200, 255, 1, 41079),
(@OGUID+6, 368749, 2450, 13561, 13653, '14', 0, 0, 164.071502685546875, -858.43328857421875, 4105.228515625, 0.348650813102722167, 0, 0, 0.173443794250488281, 0.984843790531158447, 7200, 255, 1, 41079),
(@OGUID+7, 368750, 2450, 13561, 13653, '14', 0, 0, 181.0986328125, -884.01446533203125, 4105.22900390625, 0.774075925350189208, 0, 0, 0.377447128295898437, 0.926031172275543212, 7200, 255, 1, 41079),
(@OGUID+8, 368751, 2450, 13561, 13653, '14', 0, 0, 206.4611053466796875, -900.602294921875, 4105.22900390625, 1.173270940780639648, 0, 0, 0.553562164306640625, 0.832807838916778564, 7200, 255, 1, 41079),
(@OGUID+9, 368752, 2450, 13561, 13653, '14', 0, 0, 263.236236572265625, -900.9161376953125, 4105.22900390625, 1.914117217063903808, 0, 0, 0.817501068115234375, 0.57592707872390747, 7200, 255, 1, 41079),
(@OGUID+10, 368753, 2450, 13561, 13653, '14', 0, 0, 288.707855224609375, -884.2554931640625, 4105.22900390625, 2.352296829223632812, 0, 0, 0.923131942749023437, 0.384483277797698974, 7200, 255, 1, 41079), 
(@OGUID+11, 368754, 2450, 13561, 13653, '14', 0, 0, 305.86798095703125, -858.4576416015625, 4105.22900390625, 2.739951372146606445, 0, 0, 0.979903221130371093, 0.199473500251770019, 7200, 255, 1, 41079);
 
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

DELETE FROM `areatrigger_template` WHERE `Id` IN (27408, 6197, 27782);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES 
(27408, 0, 1, 32,  5,   2.5, 3.5, 5, 2.5, 3.5, 41079),
(6197,  0, 0, 0, 1, 1, 0, 0, 0, 0, 41079),
(27782, 0, 4, 100, 100, 0, 0, 0, 0, 0, 41079);

DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (23349, 22400, 23034, 23028, 5428, 23694, 23507, 23506, 23117);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ScriptName`, `VerifiedBuild`) VALUES 
(23349, 27663, 0, 0, 0, 0, -1, 0, 0, 0, 15000, 0, 3, 3, 0, 0, 0, 0, 'at_tormented_rack_fragment', 41079), -- Trinket: Tormented Rack Fragment
(22400, 6197, 0, 0, 0, 0, -1, 0, 0, 0, 5000, 0, 6, 6, 0, 0, 0, 0, 'at_sylvanas_windrunner_disecrating_shot', 41079), -- Desecrating Shot (348626)
(23034, 6197, 0, 0, 0, 0, -1, 0, 0, 0, 2500, 0, 1, 1, 0, 0, 0, 0, 'at_sylvanas_windrunner_rive_marker', 41079), -- Rive Marker (353419)
(23028, 27408, 25793, 0, 0, 0, -1, 0, 0, 2653, 4000, 1, 5, 2.5, 3.5, 5, 2.5, 3.5, 'at_sylvanas_windrunner_rive', 41079), -- Rive (353375)
(5428, 6197, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 'at_sylvanas_windrunner_bridges', 41079), -- Channel Ice (354476, 354574, 354573) and Call Earth (354577, 354575, 354576)
(23694, 27929, 0, 28659, 0, 0, -1, 0, 0, 14286, 10000, 1, 1.75, 4, 2, 1.75, 4, 2, 'at_sylvanas_windrunner_haunting_wave', 41079), -- Haunting Wave NM (351869)
(23507, 27783, 0, 0, 0, 0, -1, 0, 0, 0, 7000, 0, 100, 100, 0, 0, 0, 0, 'at_sylvanas_windrunner_blasphemy', 41079), -- Blasphemy (357730)
(23506, 27782, 0, 0, 0, 0, -1, 0, 0, 0, 10000, 0, 100, 100, 0, 0, 0, 0, 'at_sylvanas_windrunner_blasphemy_pre', 41079), -- Blasphemy (357729)
(23117, 27480, 0, 0, 0, 0, -1, 0, 462, 0, 0, 1, 20, 20, 5, 20, 20, 5, 'at_sylvanas_windrunner_raze', 41079); -- Raze (354145)

DELETE FROM `areatrigger_create_properties_spline_point` WHERE `AreaTriggerCreatePropertiesId` IN (23694, 23028);
INSERT INTO `areatrigger_create_properties_spline_point` (`AreaTriggerCreatePropertiesId`, `Idx`, `X`, `Y`, `Z`, `VerifiedBuild`) VALUES
(23694, 0, 0, 0, 0, 41359),
(23694, 1, 0, 0, 0, 41079),
(23694, 2, 100.0000152587890625, -0.00001968324795598, 0, 41079),
(23694, 3, 100.0000152587890625, -0.00001968324795598, 0, 41079),
(23028, 0, 0, 0, 0, 41359),
(23028, 1, 0, 0, 0, 41359),
(23028, 2, -49.9645919799804687, 1.881691813468933105, 0, 41359), 
(23028, 3, -64.953948974609375, 2.446214675903320312, 0, 41359), 
(23028, 4, -72.4486541748046875, 2.728454351425170898, 0, 41359), 
(23028, 5, -79.9433670043945312, 3.010704517364501953, 0, 41359),
(23028, 6, -87.438018798828125, 3.292987823486328125, 0, 41359), 
(23028, 7, -94.9327239990234375, 3.575227260589599609, 0, 41359), 
(23028, 8, -102.427383422851562, 3.857510805130004882, 0, 41359), 
(23028, 9, -109.922080993652343, 4.139750480651855468, 0, 41359), 
(23028, 10, -117.416793823242187, 4.422000408172607421, 0, 41359), 
(23028, 11, -124.911453247070312, 4.704283714294433593, 0, 41359), 
(23028, 12, -132.406158447265625, 4.986523628234863281, 0, 41359), 
(23028, 13, -139.900848388671875, 5.268763065338134765, 0, 41359), 
(23028, 14, -147.3955078125, 5.551046371459960937, 0, 41359), 
(23028, 15, -154.890213012695312, 5.833285808563232421, 0, 41359), 
(23028, 16, -154.890213012695312, 5.833285808563232421, 0, 41359);

 -- Highlord Bolvar Fordragon
DELETE FROM `creature_template` WHERE `entry`=178081;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(178081, 'Highlord Bolvar Fordragon', NULL, 'Knights of the Ebon Blade', NULL, NULL, 0, 60, 60, 0, 0, 0, 2110, 35184372088832, 1.2, 1.42857, 1, 3, 0, 2000, 0, 1, 1, 2, 32768, 1073741828, 65568, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_sylvanas_windrunner_bolvar', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=178081;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(178081, 0, 0, 0, 1, 506, 0, 0, 0, '');

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 178081;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(178081, 1, 177838, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_model_info` WHERE `DisplayID`=101964;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101964, 0.772164, 3.675, 0, 41359);

DELETE FROM `creature_template_scaling` WHERE `Entry` = 178081;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178081, 0, 0, 0, 837, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=178081;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(178081, 1, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid`=@CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+1, 178081, 2450, 13561, 13653, '14', 0, 0, 0, -1, 0, 1, 239.795, -806.064, 4105.07, 4.77206, 30, 0, 0, 1179100, 2434, 0, 0, 0, 0, 0, 0, '', 41079);

 -- Winds of Icecrown
DELETE FROM `spell_script_names` WHERE `spell_id`=356941 AND `ScriptName`='spell_sylvanas_windrunner_winds_of_icecrown';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(356941, 'spell_sylvanas_windrunner_winds_of_icecrown');

 -- Lady Jaina Proudmoore
DELETE FROM `creature_template` WHERE `entry`=176533;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(176533, 'Lady Jaina Proudmoore', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 2110, 35184372088832, 1.6, 1.14286, 1, 1, 0, 2000, 0, 1, 1, 2, 32832, 1073741828, 65568, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_sylvanas_windrunner_jaina', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=176533;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(176533, 0, 0, 0, 1, 654, 0, 0, 0, '');

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 176533;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(176533, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_model_info` WHERE `DisplayID`=101962;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101962, 0.652598, 0, 1, 41359);

DELETE FROM `creature_template_scaling` WHERE `Entry` = 176533;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(176533, 0, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=176533;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(176533, 1, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid`=@CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+2, 176533, 2450, 13561, 13653, '14', 0, 0, 0, -1, 0, 1, 231.595, -801.5, 4105.07, 5.02181, 30, 0, 0, 2249600, 2434, 0, 0, 0, 0, 0, 0, '', 41079);

 -- Frigid Shards
DELETE FROM `spell_script_names` WHERE `spell_id`=354933 AND `ScriptName`='spell_sylvanas_windrunner_frigid_shards';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(354933, 'spell_sylvanas_windrunner_frigid_shards');

 -- Comet Barrage
DELETE FROM `spell_script_names` WHERE `spell_id`=354938 AND `ScriptName`='spell_sylvanas_windrunner_comet_barrage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(354938, 'spell_sylvanas_windrunner_comet_barrage');

 -- Teleport (Master - To Phase 3)
DELETE FROM `spell_script_names` WHERE `spell_id`=350906 AND `ScriptName`='spell_sylvanas_windrunner_teleport_to_phase_3_master';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(350906, 'spell_sylvanas_windrunner_teleport_to_phase_3_master');

 -- Teleport (Random Position)
DELETE FROM `spell_script_names` WHERE `spell_id`=357103 AND `ScriptName`='spell_sylvanas_windrunner_teleport_to_phase_3_random_position';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(357103, 'spell_sylvanas_windrunner_teleport_to_phase_3_random_position');

 -- Teleport to Oribos - Raid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=350906 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=3 AND `ConditionValue2`=176533 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 350906, 0, 0, 31, 0, 3, 176533, 0, 0, 0, 0, '', 'Teleport to Oribos - Target Jaina'); -- TODO: The entry is most likely wrong, we need to find which one uses as target

 -- Thrall
DELETE FROM `creature_template` WHERE `entry`=176532;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(176532, 'Thrall', NULL, NULL, NULL, NULL, 0, 62, 62, 0, 0, 0, 2110, 35184372088832, 1.2, 1.14286, 1, 1, 0, 2000, 0, 1, 1, 1, 32768, 1073741828, 65568, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_sylvanas_windrunner_thrall', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=176532;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(176532, 0, 0, 0, 1, 505, 0, 0, 0, '');

DELETE FROM `creature_equip_template` WHERE `CreatureID` = 176532;
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(176532, 1, 168268, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_model_info` WHERE `DisplayID`=101963;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(101963, 0.998133, 1.5, 0, 41359);

DELETE FROM `creature_template_scaling` WHERE `Entry` = 176532;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(176532, 0, 2, 2, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=176532;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(176532, 1, 0, 0, 0, 0, 0);

DELETE FROM `creature` WHERE `guid`=@CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+3, 176532, 2450, 13561, 13653, '14', 0, 0, 0, -1, 0, 1, 243.661, -804.615, 4105.07, 4.28529, 30, 0, 0, 4611600, 0, 0, 0, 0, 0, 0, 0, '', 41079);

 -- The Jailer
DELETE FROM `creature_template` WHERE `entry`=178079;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(178079, 'The Jailer', NULL, NULL, NULL, NULL, 0, 63, 63, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 32832, 71303168, 32769, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7513, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=178079;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(178079, 0, 0, 0, 1, 0, 0, 0, 0, '355347');

DELETE FROM `creature_template_scaling` WHERE `Entry`=178079;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178079, 14, 3, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=178079;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(178079, 1, 0, 1, 0, 0, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=178079;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(178079, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=178079;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(178079, 179784, 3, 1, 'The Jailer - Soul Leader 3', 6, 30000);

DELETE FROM `creature` WHERE `guid`=@CGUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+4, 178079, 2450, 13561, 13655, '14', 0, 0, 0, -1, 0, 0, -249.634, -1227.17, 5672.13, 4.67994, 7200, 0, 0, 11248000, 0, 0, 0, 0, 0, 0, 0, '', 41079);

 -- Soul Leader 1 (Last Phase - Rides 178079)
DELETE FROM `creature_template` WHERE `entry`=179788;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(179788, 'Sylvanas', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 33554432, 33556512, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7536, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=179788;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(179788, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry`=179788;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(179788, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=179788;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(179788, 1, 0, 1, 0, 0, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=179788;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(179788, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=179788;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(179788, 179787, 0, 1, 'Soul Leader 1 - Soul Leader 2', 6, 30000);

 -- Soul Leader 2 (Last Phase - Rides 179788)
DELETE FROM `creature_template` WHERE `entry`=179787;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(179787, 'Sylvanas', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 33554432, 33556512, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7535, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=179787;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(179787, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry`=179787;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(179787, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=179787;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(179787, 1, 0, 1, 0, 0, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=179787;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(179787, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=179787;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(179787, 179262, 0, 1, 'Soul Leader 2 - Soul Follower 1', 6, 30000),
(179787, 179262, 1, 1, 'Soul Leader 2 - Soul Follower 1', 6, 30000),
(179787, 179262, 2, 1, 'Soul Leader 2 - Soul Follower 1', 6, 30000),
(179787, 179262, 3, 1, 'Soul Leader 2 - Soul Follower 1', 6, 30000),
(179787, 179262, 4, 1, 'Soul Leader 2 - Soul Follower 1', 6, 30000),
(179787, 179262, 5, 1, 'Soul Leader 2 - Soul Follower 1', 6, 30000),
(179787, 179262, 6, 1, 'Soul Leader 2 - Soul Follower 1', 6, 30000);

 -- Soul Leader 3 (Last Phase - Rides 178079)
DELETE FROM `creature_template` WHERE `entry`=179784;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(179784, 'Sylvanas', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 33554432, 33556512, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7533, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=179784;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(179784, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry`=179784;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(179784, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=179784;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(179784, 1, 0, 1, 0, 0, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=179784;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(179784, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=179784;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(179784, 179261, 0, 1, 'Soul Leader 3 - Soul Leader 4', 6, 30000);

 -- Soul Leader 4 (Last Phase - Rides 179784)
DELETE FROM `creature_template` WHERE `entry`=179261;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(179261, 'Sylvanas', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 33554432, 33556512, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7514, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=179261;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(179261, 0, 0, 0, 1, 0, 0, 0, 0, '');

DELETE FROM `creature_template_scaling` WHERE `Entry`=179261;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(179261, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=179261;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(179261, 1, 0, 1, 0, 0, 0);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=179261;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(179261, 46598, 0, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry`=179261;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES 
(179261, 179262, 0, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000),
(179261, 179262, 1, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000),
(179261, 179262, 2, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000),
(179261, 179262, 3, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000),
(179261, 179262, 4, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000),
(179261, 179262, 5, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000),
(179261, 179262, 6, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000),
(179261, 179262, 7, 1, 'Soul Leader 4 - Soul Follower 1', 6, 30000);

 -- Soul Follower 1 (Last Phase - inside 179261)
DELETE FROM `creature_template` WHERE `entry`=179262;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(179262, 'Sylvanas', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 16, 0, 1, 1.14286, 1, 0, 0, 2000, 0, 1, 1, 0, 33554432, 33556512, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=179262;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(179262, 0, 0, 50331648, 1, 0, 0, 0, 0, '353687');

DELETE FROM `creature_template_scaling` WHERE `Entry`=179262;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(179262, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=179262;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(179262, 1, 0, 1, 0, 0, 0);

 -- Anduin Wrynn
DELETE FROM `creature_template` WHERE `entry`=178072;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(178072, 'Anduin Wrynn', NULL, NULL, NULL, NULL, 0, 62, 62, 0, 0, 0, 14, 35184372088832, 1, 1.14286, 1, 1, 0, 2000, 0, 1, 1, 2, 32784, 71303168, 98336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 584, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 'npc_sylvanas_windrunner_anduin', 41079);

DELETE FROM `creature_template_addon` WHERE `entry`=178072;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(178072, 0, 0, 0, 1, 0, 0, 0, 0, '358166');

DELETE FROM `creature_model_info` WHERE `DisplayID`=99092;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(99092, 0.616386, 0, 0, 41359);

DELETE FROM `creature_template_scaling` WHERE `Entry`=178072;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178072, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=178072;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(178072, 1, 0, 1, 0, 0, 0);
 
DELETE FROM `creature` WHERE `guid`=@CGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+5, 178072, 2450, 13561, 13655, '14', 0, 0, 0, -1, 0, 1, -249.161, -1271.62, 5667.08, 4.56334, 7200, 0, 0, 23058000, 2568, 0, 0, 0, 0, 0, 0, '', 41079);

DELETE FROM `spell_script_names` WHERE `spell_id`=357729 AND `ScriptName`='spell_sylvanas_windrunner_blasphemy_pre';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(357729, 'spell_sylvanas_windrunner_blasphemy_pre');

DELETE FROM `spell_script_names` WHERE `spell_id`=357730 AND `ScriptName`='spell_sylvanas_windrunner_blasphemy';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(357730, 'spell_sylvanas_windrunner_blasphemy');

 -- The Arbiter
DELETE FROM `creature_template_addon` WHERE `entry`=178082;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(178082, 0, 0, 50331648, 1, 0, 0, 0, 0, '357738');

DELETE FROM `creature_template_scaling` WHERE `Entry`=178082;
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(178082, 14, 0, 0, 2104, 41079);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=178082;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`) VALUES 
(178082, 1, 0, 1, 0, 0, 0);

DELETE FROM `creature` WHERE `guid`=@CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES 
(@CGUID+6, 178082, 2450, 13561, 13655, '14', 0, 0, 0, -1, 0, 0, -250.247, -1385.28, 5640.44, 1.57011, 7200, 0, 0, 11248000, 0, 0, 0, 0, 0, 0, 0, '', 41079);

 -- Death Gate
DELETE FROM `creature_template` WHERE `entry`=182021;
INSERT INTO `creature_template` (`entry`, `name`, `femaleName`, `subname`, `TitleAlt`, `IconName`, `gossip_menu_id`, `minlevel`, `maxlevel`, `HealthScalingExpansion`, `RequiredExpansion`, `VignetteID`, `faction`, `npcflag`, `speed_walk`, `speed_run`, `scale`, `rank`, `dmgschool`, `BaseAttackTime`, `RangeAttackTime`, `BaseVariance`, `RangeVariance`, `unit_class`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `family`, `trainer_class`, `type`, `type_flags`, `type_flags2`, `lootid`, `pickpocketloot`, `skinloot`, `VehicleId`, `mingold`, `maxgold`, `AIName`, `MovementType`, `HoverHeight`, `HealthModifier`, `HealthModifierExtra`, `ManaModifier`, `ManaModifierExtra`, `ArmorModifier`, `DamageModifier`, `ExperienceModifier`, `RacialLeader`, `movementId`, `CreatureDifficultyID`, `WidgetSetID`, `WidgetSetUnitConditionID`, `RegenHealth`, `mechanic_immune_mask`, `spell_school_immune_mask`, `flags_extra`, `ScriptName`, `VerifiedBuild`) VALUES 
(182021, 'Death Gate', NULL, NULL, NULL, NULL, 0, 60, 60, 0, 0, 0, 190, 16777216, 1, 1, 1, 0, 0, 1000, 0, 1, 1, 0, 768, 101189632, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, '', 41079);

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=182021 AND `spell_id`=360276;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES 
(182021, 360276, 3, 3);

DELETE FROM `spell_target_position` WHERE `ID`=360276 AND `EffectIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES 
(360276, 0, 0, 0, 0, 0, 41079);

 -- Portal to Oribos (appears at -249.77779, -1277.1838, 5667.2383, 5.0943484)
DELETE FROM `gameobject_template` WHERE `entry`=370168;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `AIName`, `ScriptName`, `VerifiedBuild`) VALUES 
(370168, 22, 68190, 'Portal to Oribos', '', '', '', 1, 344603, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 482, '', '', 41079);

DELETE FROM `gameobject_template_addon` WHERE `entry`=370168;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `mingold`, `maxgold`, `WorldEffectID`, `AIAnimKitID`) VALUES 
(370168, 35, 32, 0, 0, 0, 8021);

DELETE FROM `spell_target_position` WHERE `ID`=344598 AND `EffectIndex`=0;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES 
(344598, 0, 2222, -1834.21, 1542.27, 5274.16, 41079);

