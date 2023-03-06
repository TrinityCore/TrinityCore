-- Anduin Wrynn Encounter

SET @CGUID := 1600000;
SET @OGUID := 700000;

-- Remnant of a Fallen King
UPDATE `creature_template` SET `minlevel`=63, `maxlevel`=63, `faction`=14, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=2708, `unit_flags3`=4194304, `ScriptName`='boss_remnant_of_a_fallen_king'  WHERE `entry`=183463; -- Remnant of a Fallen King
UPDATE `creature_template` SET `HealthModifier`=1162, `CreatureDifficultyID`=213555, `VerifiedBuild`=46366 WHERE `entry`=183463; -- Remnant of a Fallen King

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (183463);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183463, 14, 3, 3, 2165, 43206),
(183463, 15, 3, 3, 2166, 43206),
(183463, 16, 3, 3, 2167, 43206),
(183463, 17, 3, 3, 2168, 43206);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183463);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183463, 0, 22234, 5, 1, 43206); -- 183463

DELETE FROM `creature_equip_template` WHERE `CreatureID` IN (183463);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(183463, 1, 124542, 0, 0, 0, 0, 0, 0, 0, 0, 43206); -- 183463


-- Befouled Barrier
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=524289, `ScriptName`='npc_anduin_wrynn_befouled_barrier'  WHERE `entry`=184585; -- Befouled Barrier

DELETE FROM `creature_template_addon` WHERE `entry`=184585;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(184585, 0, 0, 0, 1, 0, 0, 0, 0, 0, '365633');

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (184585);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(184585, 14, 3, 3, 2165, 43206),
(184585, 15, 3, 3, 2166, 43206),
(184585, 16, 3, 3, 2167, 43206),
(184585, 17, 3, 3, 2168, 43206);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (184585);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(184585, 0, 1126, 1, 0, 43206),
(184585, 1, 11686, 1, 1, 43206);

-- Empty Vessel
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=537133824, `unit_flags2`=67667985, `unit_flags3`=17342464, `dynamicflags`=1, `ScriptName`='npc_anduin_wrynn_empty_vessel' WHERE `entry`=183452; -- Empty Vessel

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183452);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183452, 0, 16925, 1, 1, 46366);

-- Anduin's Despair 184520
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=14, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags2`=2048, `ScriptName`='npc_anduin_wrynn_anduin_despair' WHERE `entry`=184520;
UPDATE `creature_template` SET `HealthModifier`=9.539999961853027343, `CreatureDifficultyID`=208850, `VerifiedBuild`=46366 WHERE `entry`=184520; -- Anduin's Despair

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (184520);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(184520, 0, 105367, 2, 1, 43206);

DELETE FROM `creature_model_info` WHERE `DisplayID`=105367;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES 
(105367, 3.22994, 5, 0, 43206);

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (184520);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(184520, 14, 2, 2, 2165, 43206),
(184520, 15, 2, 2, 2166, 43206),
(184520, 16, 2, 2, 2167, 43206),
(184520, 17, 2, 2, 2168, 43206);


-- Anduin's Doubt 184494
UPDATE `creature_template` SET `minlevel`=61, `maxlevel`=61, `faction`=14, `speed_walk`=0.800000011920928955, `speed_run`=0.914285719394683837, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=4194304, `ScriptName`='npc_anduin_wrynn_anduin_doubt' WHERE `entry`=184494; -- Anduin's Doubt
UPDATE `creature_template` SET `HealthModifier`=1.360000014305114746, `CreatureDifficultyID`=208842, `VerifiedBuild`=46366 WHERE `entry`=184494; -- Anduin's Doubt

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (184494);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(184494, 0, 105380, 2.5, 1, 43206); -- 184494

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (184494);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(184494, 14, 1, 1, 2165, 46366),
(184494, 15, 1, 1, 2166, 46366),
(184494, 16, 1, 1, 2167, 46366),
(184494, 17, 1, 1, 2168, 46366);


-- Anduin's Soul 184519
UPDATE `creature_template` SET `minlevel`=63, `maxlevel`=63, `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67108864, `unit_flags3`=23068672, `dynamicflags`=1, `HoverHeight`=30, `ScriptName`='npc_anduin_wrynn_anduin_soul' WHERE `entry`=184519; -- Anduin's Soul

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (184519);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(184519, 14, 3, 3, 2165, 46366),
(184519, 15, 3, 3, 2166, 46366),
(184519, 16, 3, 3, 2167, 46366),
(184519, 17, 3, 3, 2168, 46366);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (184519);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(184519, 0, 105384, 3.5, 1, 46366); -- 184519

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (105384);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(105384, 1.438233017921447753, 0, 0, 46366);

DELETE FROM `creature_template_addon` WHERE `entry`=184519;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(184519, 0, 0, 33554432, 1, 0, 0, 0, 0, 0, '369016 365650'); -- 184519 - 369016, 365650


-- Anduin's Hope 184493
UPDATE `creature_template` SET `name`='Anduin\'s Hope', `HealthScalingExpansion`=8, `unit_class`=1, `type`=7, `type_flags`=2101368, `type_flags2`=69206144, `HealthModifier`=0.920000016689300537, `movementId`=2081, `CreatureDifficultyID`=208846, `VerifiedBuild`=46366, `ScriptName`='npc_anduin_wrynn_anduin_hope' WHERE `entry`=184493; -- 184493

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (184493);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(184493, 14, 0, 0, 2165, 43206),
(184493, 15, 0, 0, 2166, 43206),
(184493, 16, 0, 0, 2167, 43206),
(184493, 17, 0, 0, 2168, 43206);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (184493);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(184493, 0, 105282, 2.5, 1, 43206); -- 184493

-- Monstrous Soul 183671
UPDATE `creature_template` SET `HealthScalingExpansion`=8, `HealthModifier`=85.7375030517578125, `CreatureDifficultyID`=209642, `VerifiedBuild`=46366 WHERE `entry`=183671; -- Monstrous Soul
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction`=14, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=4718592, `ScriptName`='npc_anduin_wrynn_monstrous_soul' WHERE `entry`=183671; -- Monstrous Soul

DELETE FROM `creature_template_addon` WHERE `entry`=183671;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(183671, 0, 0, 0, 1, 0, 0, 0, 0, 0, '362719'); -- 183671

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (183671);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183671, 14, 2, 2, 2165, 46366),
(183671, 15, 2, 2, 2166, 46366),
(183671, 16, 2, 2, 2167, 46366),
(183671, 17, 2, 2, 2168, 46366);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183671);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183671, 0, 105399, 2.20000004768371582, 1, 46366); -- 183671

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (105399);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(105399, 0, 2.2, 0, 43206);

DELETE FROM `creature_text` WHERE `CreatureID`=183671;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(183671, 0, 0, '|TInterface\\ICONS\\Tradeskill_AbominationStitching_Abominations_Mid.BLP:20|t %s begins casting |cFFFF0000|Hspell:363024|h[Necrotic Detonation]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 'Monstrous Soul');

-- Fiendish Soul 183669
UPDATE `creature_template` SET `minlevel`=61, `maxlevel`=61, `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=4718592, `ScriptName`='npc_anduin_wrynn_fiendish_soul' WHERE `entry`=183669; -- Fiendish Soul
UPDATE `creature_template` SET `HealthModifier`=10.125, `CreatureDifficultyID`=209647, `VerifiedBuild`=46366 WHERE `entry`=183669; -- Fiendish Soul

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (183669);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183669, 14, 1, 1, 2165, 46366),
(183669, 15, 1, 1, 2166, 46366),
(183669, 16, 1, 1, 2167, 46366),
(183669, 17, 1, 1, 2168, 46366);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183669);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183669, 0, 105398, 1.149999976158142089, 1, 46366); -- 183669

DELETE FROM `creature_template_addon` WHERE `entry`=183669;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(183669, 0, 0, 0, 1, 0, 0, 0, 0, 0, '368977'); -- 183669 - 368977

-- Grim Reflection 183033
UPDATE `creature_template` SET `minlevel`=61, `maxlevel`=61, `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2080, `unit_flags3`=4718592, `ScriptName`='npc_anduin_wrynn_grim_reflection' WHERE `entry`=183033; -- Grim Reflection
UPDATE `creature_template` SET `CreatureDifficultyID`=209636, `VerifiedBuild`=46366 WHERE `entry`=183033; -- Grim Reflection

DELETE FROM `creature_template_addon` WHERE `entry`=183033;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES 
(183033, 0, 0, 0, 1, 0, 0, 0, 0, 0, '361685'); -- 183033 - 361685

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (183033);
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(183033, 14, 1, 1, 2165, 46366),
(183033, 15, 1, 1, 2166, 46366),
(183033, 16, 1, 1, 2167, 46366),
(183033, 17, 1, 1, 2168, 46366);

DELETE FROM `creature_template_model` WHERE `CreatureID` IN (183033);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(183033, 0, 99093, 3, 1, 46366); -- 183033


-- Energize Willpower LFR 33
DELETE FROM `spell_script_names` WHERE `spell_id`=366848 AND `ScriptName`='spell_anduin_wrynn_energize_willpower_lfr';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(366848, 'spell_anduin_wrynn_energize_willpower_lfr');

-- Dark Zeal
DELETE FROM `spell_script_names` WHERE `spell_id`=364247 AND `ScriptName`='spell_anduin_wrynn_dark_zeal';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(364247, 'spell_anduin_wrynn_dark_zeal');

-- Hopebreaker
DELETE FROM `spell_script_names` WHERE `spell_id`=361815 AND `ScriptName`='spell_anduin_wrynn_hopebreaker';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(361815, 'spell_anduin_wrynn_hopebreaker');

-- Hopebreaker Damage
DELETE FROM `spell_script_names` WHERE `spell_id`=361818 AND `ScriptName`='spell_anduin_wrynn_hopebreaker_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(361818, 'spell_anduin_wrynn_hopebreaker_damage');

-- Hopebreaker Periodic
DELETE FROM `spell_script_names` WHERE `spell_id`=361817 AND `ScriptName`='spell_anduin_wrynn_hopebreaker_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(361817, 'spell_anduin_wrynn_hopebreaker_periodic');

-- Empowered Hopebreaker
DELETE FROM `spell_script_names` WHERE `spell_id`=365805 AND `ScriptName`='spell_anduin_wrynn_empowered_hopebreaker';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365805, 'spell_anduin_wrynn_empowered_hopebreaker');

-- Empowered Hopebreaker Periodic
DELETE FROM `spell_script_names` WHERE `spell_id`=365806 AND `ScriptName`='spell_anduin_wrynn_empowered_hopebreaker_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365806, 'spell_anduin_wrynn_empowered_hopebreaker_periodic');

-- Befouled Barrier Absorb
DELETE FROM `spell_script_names` WHERE `spell_id`=365293 AND `ScriptName`='spell_anduin_wrynn_befouled_barrier_absorb';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365293, 'spell_anduin_wrynn_befouled_barrier_absorb');

-- Befouled Barrier Expire
DELETE FROM `spell_script_names` WHERE `spell_id`=365173 AND `ScriptName`='spell_anduin_wrynn_befouled_barrier_expire';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365173, 'spell_anduin_wrynn_befouled_barrier_expire');

-- Blasphemy
DELETE FROM `spell_script_names` WHERE `spell_id`=361989 AND `ScriptName`='spell_anduin_wrynn_blasphemy';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(361989, 'spell_anduin_wrynn_blasphemy');

-- Hopelessness & Overconfidence Expire
DELETE FROM `spell_script_names` WHERE `spell_id`=361993 AND `ScriptName`='spell_anduin_wrynn_hopelessness_overconfidence';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(361993, 'spell_anduin_wrynn_hopelessness_overconfidence');

-- Hopelessness & Overconfidence Expire (there are 2 spells)
DELETE FROM `spell_script_names` WHERE `spell_id`=361992 AND `ScriptName`='spell_anduin_wrynn_hopelessness_overconfidence';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(361992, 'spell_anduin_wrynn_hopelessness_overconfidence');

-- Hopelessness
DELETE FROM `spell_script_names` WHERE `spell_id`=365958 AND `ScriptName`='spell_anduin_wrynn_hopelessness';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365958, 'spell_anduin_wrynn_hopelessness');

-- Hopelessness Expire
DELETE FROM `spell_script_names` WHERE `spell_id`=365966 AND `ScriptName`='spell_anduin_wrynn_hopelessness_expire';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365966, 'spell_anduin_wrynn_hopelessness_expire');

-- Kingsmourne Hungers
DELETE FROM `spell_script_names` WHERE `spell_id`=362405 AND `ScriptName`='spell_anduin_wrynn_kingsmourne_hungers';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362405, 'spell_anduin_wrynn_kingsmourne_hungers');

-- Severed Soul
DELETE FROM `spell_script_names` WHERE `spell_id`=367769 AND `ScriptName`='spell_anduin_wrynn_severed_soul';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(367769, 'spell_anduin_wrynn_severed_soul');

-- Lost Soul Dimension
DELETE FROM `spell_script_names` WHERE `spell_id`=362055 AND `ScriptName`='spell_anduin_wrynn_lost_soul';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362055, 'spell_anduin_wrynn_lost_soul');

-- Lost Soul Mirror Image
DELETE FROM `spell_script_names` WHERE `spell_id`=362402 AND `ScriptName`='spell_anduin_wrynn_lost_soul_mythic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362402, 'spell_anduin_wrynn_lost_soul_mirror_image');

-- Rain of Despair
DELETE FROM `spell_script_names` WHERE `spell_id`=362391 AND `ScriptName`='spell_anduin_despair_rain_of_despair';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362391, 'spell_anduin_despair_rain_of_despair');

-- Big Add Targetting Melee
DELETE FROM `spell_script_names` WHERE `spell_id`=362393 AND `ScriptName`='spell_anduin_despair_rain_of_despair_melee';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362393, 'spell_anduin_despair_rain_of_despair_melee');

-- Big Add Targetting Ranged
DELETE FROM `spell_script_names` WHERE `spell_id`=362396 AND `ScriptName`='spell_anduin_despair_rain_of_despair_ranged';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362396, 'spell_anduin_despair_rain_of_despair_ranged');

-- Wicked Star
DELETE FROM `spell_script_names` WHERE `spell_id`=365030 AND `ScriptName`='spell_anduin_wrynn_wicked_star';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365030, 'spell_anduin_wrynn_wicked_star');

-- Wicked Star Pointer
DELETE FROM `spell_script_names` WHERE `spell_id`=365021 AND `ScriptName`='spell_anduin_wrynn_wicked_star_pointer';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365021, 'spell_anduin_wrynn_wicked_star_pointer');

-- Spawn Remnant
DELETE FROM `spell_script_names` WHERE `spell_id`=362500 AND `ScriptName`='spell_remnant_of_a_fallen_king_spawn';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362500, 'spell_remnant_of_a_fallen_king_spawn');

-- Army of the Dead
DELETE FROM `spell_script_names` WHERE `spell_id`=362862 AND `ScriptName`='spell_remnant_of_a_fallen_king_army_of_the_dead';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362862, 'spell_remnant_of_a_fallen_king_army_of_the_dead');

-- Echoes of Andorhal (Summoning)
DELETE FROM `spell_script_names` WHERE `spell_id`=362863 AND `ScriptName`='spell_remnant_of_a_fallen_king_echoes_of_andorhal';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362863, 'spell_remnant_of_a_fallen_king_echoes_of_andorhal');

-- Soul Reaper
DELETE FROM `spell_script_names` WHERE `spell_id`=362771 AND `ScriptName`='spell_remnant_of_a_fallen_king_soul_reaper';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362771, 'spell_remnant_of_a_fallen_king_soul_reaper');

-- Remorseless Winter Damage
DELETE FROM `spell_script_names` WHERE `spell_id`=362545 AND `ScriptName`='spell_remnant_of_a_fallen_king_remorseless_winter_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362545, 'spell_remnant_of_a_fallen_king_remorseless_winter_damage');

-- Remorseless Winter Periodic
DELETE FROM `spell_script_names` WHERE `spell_id`=362543 AND `ScriptName`='spell_remnant_of_a_fallen_king_remorseless_winter_periodic';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(362543, 'spell_remnant_of_a_fallen_king_remorseless_winter_periodic');

-- March of the Damned
DELETE FROM `spell_script_names` WHERE `spell_id`=363233 AND `ScriptName`='spell_anduin_wrynn_march_of_the_damned';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(363233, 'spell_anduin_wrynn_march_of_the_damned');

-- Dark Presence
DELETE FROM `spell_script_names` WHERE `spell_id`=368986 AND `ScriptName`='spell_anduin_wrynn_dark_presence';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(368986, 'spell_anduin_wrynn_dark_presence');

-- Force of Will
DELETE FROM `spell_script_names` WHERE `spell_id`=368913 AND `ScriptName`='spell_anduin_wrynn_force_of_will';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(368913, 'spell_anduin_wrynn_force_of_will');

-- Grim Fate
DELETE FROM `spell_script_names` WHERE `spell_id`=367932 AND `ScriptName`='spell_anduin_wrynn_grim_fate';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(367932, 'spell_anduin_wrynn_grim_fate');

-- Energize Runic Power
DELETE FROM `spell_script_names` WHERE `spell_id`=365291 AND `ScriptName`='spell_remnant_of_a_fallen_king_energize_runic_power';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365291, 'spell_remnant_of_a_fallen_king_energize_runic_power');

-- Grim Reflections
DELETE FROM `spell_script_names` WHERE `spell_id`=365120 AND `ScriptName`='spell_anduin_wrynn_grim_reflections';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365120, 'spell_anduin_wrynn_grim_reflections');

-- Return to Kingsmourne
DELETE FROM `spell_script_names` WHERE `spell_id`=363021 AND `ScriptName`='spell_remnant_of_a_fallen_king_return_to_kingsmourne';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(363021, 'spell_remnant_of_a_fallen_king_return_to_kingsmourne');

-- Beacon of Hope
DELETE FROM `spell_script_names` WHERE `spell_id`=365872 AND `ScriptName`='spell_anduin_wrynn_beacon_of_hope';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(365872, 'spell_anduin_wrynn_beacon_of_hope');


-- Areatrigger Template

DELETE FROM `areatrigger_template` WHERE `Id` IN (28736, 28622, 28483, 28469, 28422, 28391);
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES 
(28736, 0, 4, 4, 5, 5, 10, 10, 0.3, 0.3, 0, 0, 43206), -- Anduin's Soul
(28622, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 43206), -- Blasphemy
(28483, 0, 0, 4, 3, 3, 0, 0, 0, 0, 0, 0, 43206), -- Hopelessness
(28469, 0, 0, 4, 10, 10, 0, 0, 0, 0, 0, 0, 43206), -- Beacon of Hope
(28422, 0, 0, 4, 1, 1, 0, 0, 0, 0, 0, 0, 43206), -- Befouled Barrier
(28391, 0, 4, 0, 1.75, 1.75, 8, 8, 2, 2, 0, 0, 43206); -- Wicked Star

-- Areatrigger Create Properties
DELETE FROM `areatrigger_create_properties` WHERE `Id` IN (24744, 24741, 24322, 24616, 24443, 24332, 24247);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(24744, 28736, 0, 0, 0, 0, -1, 0, 0, 0, 0, 4, 5, 5, 10, 10, 0.3, 0.3, 0, 0, 'at_anduin_wrynn_anduin_soul', 43206), -- Anduin's Soul
(24741, 28391, 0, 0, 0, 0, -1, 0, 0, 5228, 0, 4, 1.75, 1.75, 8, 8, 2, 2, 0, 0, 'at_anduin_wrynn_wicked_star', 43206), -- Mythic Wicked Star
(24616, 28622, 0, 0, 0, 0, -1, 0, 0, 0, 10000, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_blasphemy', 43206), -- Blasphemy
(24443, 28483, 0, 0, 0, 0, -1, 0, 0, 0, 29999, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_hopelessness', 43206), -- Hopelessness
(24332, 28422, 0, 0, 0, 0, -1, 0, 0, 0, 30000, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_befouled_barrier', 43206), -- Befouled Barrier
(24247, 28469, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_beacon_of_hope', 43206); -- Beacon of Hope



























