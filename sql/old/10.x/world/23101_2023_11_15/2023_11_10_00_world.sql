-- Sepulcher of the First Ones
SET @CGUID := 8000002; -- Insert highest based on your db
SET @OGUID := 8000012; -- Insert highest based on your db
SET @ATID := 49;
SET @ATSPAWNID := 49;

-- Instance
DELETE FROM `access_requirement` WHERE `mapId`=2481;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES 
(2481, 16, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones - Mythic Mode'),
(2481, 15, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones - Heroic Mode'),
(2481, 14, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones - Normal Mode'),
(2481, 17, 60, 0, 0, 0, 0, 0, 0, NULL, 'Sepulcher of the First Ones - Looking for Raid Mode');

DELETE FROM `instance_template` WHERE `map`=2481;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2481, 0, 'instance_sepulcher_of_the_first_ones');

DELETE FROM `world_state` WHERE `ID` IN (20839, 21302);
INSERT INTO `world_state` (`ID`, `DefaultValue`, `MapIDs`, `AreaIDs`, `ScriptName`, `Comment`) VALUES 
(20839, 1, NULL, NULL, '', 'Sepulcher of the First Ones - Normal and Heroic Difficulty Open'),
(21302, 1, NULL, NULL, '', 'Sepulcher of the First Ones - Mythic Difficulty Open');

-- Game Objects
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (375110, 375035, 375901);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(375110, 0, 16, 0, 0), -- Bridge to Anduin
(375035, 0, 16, 0, 0), -- Bridge after Anduin
(375901, 94, 2113568, 0, 0); -- Anduin Chest loot

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 375110, 2481, 13742, 13965, '14,15,16,17', '0', 0, -3824.822265625, -2658.32080078125, 83.4433746337890625, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 604800, 255, 1, 50747),
(@OGUID+1, 375035, 2481, 13742, 13965, '14,15,16,17', '0', 0, -3825.06591796875, -2785.4755859375, 88.5488128662109375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 604800, 255, 0, 50747);

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 1, -0.00000004371138828, 0, 0), -- Bridge to Anduin
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0); -- Bridge after Anduin

-- Smart Scripts
DELETE FROM `smart_scripts` WHERE `entryorguid`=184297;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(184297, 0, 0, 1, 62, 0, 100, 0, 27524, 0, 0, 0, 0, '', 85, 364475, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Dominated Translocator - Teleport to Cosmic Hub'),
(184297, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Dominated Translocator - On Gossip Option selected - Close Menu');

DELETE FROM `smart_scripts` WHERE `entryorguid`=185843;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(185843, 0, 0, 1, 62, 0, 100, 0, 27687, 0, 0, 0, 0, '', 85, 368563, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Ancient Console - Teleport to Domination Grasp'),
(185843, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Ancient Console - On Gossip Option selected - Close Menu');

-- Creature Templates
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=524289 WHERE `entry`=184585; -- Befouled Barrier
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_uther', `faction`=35, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=183665; -- Uther the Lightbringer
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_jaina', `faction`=35, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=183664; -- Lady Jaina Proudmoore
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_sylvanas', `faction`=35, `speed_walk`=1.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=32832 WHERE `entry`=183666; -- Sylvanas Windrunner
UPDATE `creature_template` SET `faction`=1665, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=33088, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=186785; -- Quartermaster Rahm
UPDATE `creature_template` SET `faction`=1665, `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=184601; -- Highlord Bolvar Fordragon
UPDATE `creature_template` SET `faction`=1665, `BaseAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=184613; -- Knight of the Ebon Blade
UPDATE `creature_template` SET `faction`=1665, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=184599; -- Thrall
UPDATE `creature_template` SET `ScriptName`='', `faction`=1665, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=184589; -- Firim
UPDATE `creature_template` SET `faction`=35, `npcflag`=8192, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67143680, `unit_flags3`=16777217 WHERE `entry` IN (182431, 184354); -- Ancient Translocator
UPDATE `creature_template` SET `AIName` = 'SmartAI', `faction`=14, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=71354368, `unit_flags3`=16777217 WHERE `entry`=184297; -- Dominated Translocator
UPDATE `creature_template` SET `ScriptName`='boss_anduin_wrynn', `faction`=16, `speed_walk`=4.40000009536743164, `speed_run`=1.571428537368774414, `BaseAttackTime`=2000, `unit_flags`=262208, `mechanic_immune_mask`=617299827, `flags_extra` = 0x1 | 0x80000 WHERE `entry`=181954; -- Anduin Wrynn
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_anduin_despair', `faction`=14, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags2`=2048 WHERE `entry`=184520; -- Anduin's Despair
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_anduin_soul', `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67108864, `unit_flags3`=23068672 WHERE `entry`=184519; -- Anduin's Soul
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_anduin_doubt', `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=4194304 WHERE `entry`=184494; -- Anduin's Doubt
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_anduin_hope', `faction`=35, `speed_walk`=0.219999998807907104, `speed_run`=0.078571431338787078, `BaseAttackTime`=2000, `unit_flags3`=6291456 WHERE `entry`=184493; -- Anduin's Hope
UPDATE `creature_template` SET `ScriptName`='boss_remnant_of_a_fallen_king', `faction`=14, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1250, `unit_flags3`=4194304 WHERE `entry`=183463; -- Remnant of a Fallen King
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=183793; -- March of the Damned
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_monstrous_soul', `faction`=14, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=0 WHERE `entry`=183671; -- Monstrous Soul
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_fiendish_soul', `faction`=14, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=4718592 WHERE `entry`=183669; -- Fiendish Soul
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_lost_soul', `faction`=14, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=32816, `unit_flags3`=4718592 WHERE `entry`=185607; -- Lost Soul
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_beacon_of_hope', `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554432, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=184830; -- Beacon of Hope
UPDATE `creature_template` SET `AIName` = 'SmartAI', `faction`=35, `npcflag`=1, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67160064, `unit_flags3`=16777217 WHERE `entry` IN (185843); -- Ancient Console
UPDATE `creature_template` SET `ScriptName`='npc_anduin_wrynn_grim_reflection', `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2080, `unit_flags3`=4718592 WHERE `entry`=183033; -- Grim Reflection

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (184830,183671,183669,183793,183463,184519,184494,184493,183452,184585,184297,183033,181954);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(184830, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 184830 (Beacon of Hope) - 362702
(183671, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '362719'), -- 183671 (Monstrous Soul) - 362719
(183669, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '368977'), -- 183669 (Fiendish Soul) - 368977
(183793, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '363116'), -- 183793 (March of the Damned) - 363116
(183463, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '362490'), -- 183463 (Remnant of a Fallen King) - 362490
(184519, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '369016'), -- 184519 (Anduin's Soul) - 369016
(184494, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '370833'), -- 184494 (Anduin's Doubt) - 370833
(184493, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '365218'), -- 184493 (Anduin's Hope) - 365218
(183452, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '362473'), -- 183452 (Empty Vessel) - 362473
(184585, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '365633'), -- 184585 (Befouled Barrier) - 365633
(184297, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184297 (Dominated Translocator)
(183033, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '361685'), -- 183033 (Grim Reflection) - 361685
(181954, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '365177'); -- 181954 (Anduin Wrynn) - 365177

-- Equip Template
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (183463,183666,181954,183665,183664,184601,184599,184589,176332,184613,186785)) 
OR (`ID`=7 AND `CreatureID`=184613) OR (`ID`=6 AND `CreatureID`=184613) OR (`ID`=5 AND `CreatureID`=184613) OR (`ID`=3 AND `CreatureID`=184613) OR (`ID`=2 AND `CreatureID`=184613);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(183463, 1, 124542, 0, 0, 0, 0, 0, 0, 0, 0, 50747), -- Remnant of a Fallen King
(183666, 1, 0, 0, 0, 0, 0, 0, 42775, 0, 0, 50747), -- Sylvanas Windrunner
(181954, 1, 183938, 0, 0, 0, 0, 0, 0, 0, 0, 50747), -- Anduin Wrynn
(183665, 1, 173369, 0, 0, 0, 0, 0, 0, 0, 0, 50747), -- Uther the Lightbringer
(183664, 1, 153575, 0, 0, 0, 0, 0, 0, 0, 0, 50747), -- Lady Jaina Proudmoore
(184601, 1, 177838, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Highlord Bolvar Fordragon
(184599, 1, 168268, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Thrall
(184589, 1, 185331, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Firim
(176332, 1, 117049, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Knight of the Ebon Blade
(184613, 1, 75223, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Knight of the Ebon Blade
(186785, 1, 117049, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Quartermaster Rahm
(184613, 7, 171617, 0, 0, 0, 0, 0, 0, 0, 0, 50747), -- Knight of the Ebon Blade
(184613, 6, 75223, 0, 0, 0, 0, 0, 0, 0, 0, 50747), -- Knight of the Ebon Blade
(184613, 5, 174488, 0, 0, 0, 0, 0, 0, 0, 0, 50747), -- Knight of the Ebon Blade
(184613, 3, 164981, 0, 0, 0, 0, 0, 0, 0, 0, 43206), -- Knight of the Ebon Blade
(184613, 2, 117049, 0, 0, 0, 0, 0, 0, 0, 0, 43206); -- Knight of the Ebon Blade

-- Model Info
UPDATE `creature_model_info` SET `BoundingRadius`=0.373567014932632446, `CombatReach`=2, `VerifiedBuild`=50747 WHERE `DisplayID`=105386;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1, `VerifiedBuild`=50747 WHERE `DisplayID`=22234;
UPDATE `creature_model_info` SET `BoundingRadius`=0.875744104385375976, `CombatReach`=1, `VerifiedBuild`=50747 WHERE `DisplayID`=105398;
UPDATE `creature_model_info` SET `BoundingRadius`=1.842974543571472167, `CombatReach`=2.20000004768371582, `VerifiedBuild`=50747 WHERE `DisplayID`=105399;
UPDATE `creature_model_info` SET `BoundingRadius`=0.453419983386993408, `VerifiedBuild`=50747 WHERE `DisplayID`=105282;
UPDATE `creature_model_info` SET `BoundingRadius`=0.498761951923370361, `VerifiedBuild`=50747 WHERE `DisplayID`=105380;
UPDATE `creature_model_info` SET `BoundingRadius`=0.410923719406127929, `VerifiedBuild`=50747 WHERE `DisplayID`=105384;

-- Summon groups
DELETE FROM `creature_summon_groups` WHERE `summonerId`=181954;
INSERT INTO `creature_summon_groups` (`summonerId`, `summonerType`, `groupId`, `entry`, `position_x`, `position_y`, `position_z`, `orientation`, `summonType`, `summonTime`, `Comment`) VALUES 
(181954, 0, 0, 183666, -3819.48, -2687.19, 91.3485, 4.5587, 8, 0, 'Sylvanas - Anduin Wrynn Encounter'),
(181954, 0, 0, 183665, -3828.03, -2688.25, 91.3485, 5.46062, 8, 0, 'Uther - Anduin Wrynn Encounter'),
(181954, 0, 0, 183664, -3824.65, -2692.2, 91.3485, 4.64412, 8, 0, 'Jaina - Anduin Wrynn Encounter');

-- Mythic Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=16 AND `Entry` IN (183666,183665,183664,184589,184613,184599,184601,186785,181954,184520,184519,184494,184493,183033,184830,183671,183669,183793,183463,183452,185607,184585,182431,184297,185843));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(183666, 16, 0, 0, 2167, 8, 100, 1, 207512, 4, 128, 50747), -- Sylvanas Windrunner
(183665, 16, 0, 0, 2167, 8, 100, 1, 207511, 4, 128, 50747), -- Uther the Lightbringer
(183664, 16, 0, 0, 2167, 8, 100, 1, 207510, 4, 128, 50747), -- Lady Jaina Proudmoore
(184589, 16, 0, 0, 2057, 8, 5, 1, 208644, 4, 16448, 50747), -- Firim
(184613, 16, 1, 1, 2167, 8, 10, 1, 208668, 0, 64, 50747), -- Knight of the Ebon Blade
(184599, 16, 2, 2, 2167, 8, 30, 1, 208654, 4, 16448, 50747), -- Thrall
(184601, 16, 2, 2, 2167, 8, 30, 1, 208656, 4, 16448, 50747), -- Highlord Bolvar Fordragon
(186785, 16, 1, 1, 2167, 8, 20, 1, 211194, 0, 64, 50747), -- Quartermaster Rahm
(181954, 16, 3, 3, 2167, 8, 1361.3499755859375, 1, 209716, 2097260, 65664, 50747), -- Anduin Wrynn
(184520, 16, 2, 2, 2167, 8, 15.84000015258789062, 1, 208851, 2097256, 128, 50747), -- Anduin's Despair
(184519, 16, 3, 3, 2167, 8, 1500, 1, 208570, 1612714108, 119537798, 50747), -- Anduin's Soul
(184494, 16, 1, 1, 2167, 8, 3.15000009536743164, 1, 208843, 18874376, 67109008, 50747), -- Anduin's Doubt
(184493, 16, 0, 0, 2167, 8, 1.399999976158142089, 1, 208847, 2101368, 69206144, 50747), -- Anduin's Hope
(183033, 16, 1, 1, 2166, 8, 28.5500004321999968, 1, 209637, 2097224, 128, 46366), -- Grim Reflection
(184830, 16, 0, 0, 2167, 8, 1, 1, 208911, 0, 128, 50747), -- Beacon of Hope
(183671, 16, 2, 2, 2167, 8, 86.6399993896484375, 1, 209643, 104, 128, 50747), -- Monstrous Soul
(183669, 16, 1, 1, 2167, 8, 13.5, 1, 209648, 16777320, 144, 50747), -- Fiendish Soul
(183793, 16, 0, 0, 2167, 8, 1, 1, 210438, 0, 128, 50747), -- March of the Damned
(183463, 16, 3, 3, 2167, 8, 1200, 1, 213556, 2097260, 128, 50747), -- Remnant of a Fallen King
(183452, 16, 0, 0, 2167, 8, 1, 1, 207292, 1610612752, 117457030, 50747), -- Empty Vessel
(185607, 16, 0, 0, 2167, 8, 4.5, 1, 209849, 2097224, 67108992, 50747), -- Lost Soul
(184585, 16, 0, 0, 2167, 8, 1, 1, 208640, 0, 128, 50747), -- Befouled Barrier
(182431, 16, 0, 0, 2165, 8, 1, 1, 206245, 1610612752, 117440582, 50747), -- Ancient Translocator
(184297, 16, 0, 0, 2165, 8, 1, 1, 208317, 1610612752, 117440582, 50747), -- Dominated Translocator
(185843, 16, 0, 0, 2165, 8, 1, 1, 210103, 1610612752, 117440582, 50747); -- Ancient Console

-- Heroic Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=15 AND `Entry` IN (183666,183665,183664,184589,184613,184599,184601,186785,181954,184520,184519,184494,184493,183033,184830,183671,183669,183793,183463,183452,185607,184585,182431,184297,185843));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(183666, 15, 0, 0, 2166, 8, 100, 1, 207512, 4, 128, 49570), -- Sylvanas Windrunner
(183665, 15, 0, 0, 2166, 8, 100, 1, 207511, 4, 128, 49570), -- Uther the Lightbringer
(183664, 15, 0, 0, 2166, 8, 100, 1, 207510, 4, 128, 49570), -- Lady Jaina Proudmoore
(184589, 15, 0, 0, 2057, 8, 5, 1, 208644, 4, 16448, 46366), -- Firim
(184613, 15, 1, 1, 2166, 8, 10, 1, 208668, 0, 64, 46366), -- Knight of the Ebon Blade
(184599, 15, 2, 2, 2166, 8, 30, 1, 208654, 4, 16448, 46366), -- Thrall
(184601, 15, 2, 2, 2166, 8, 30, 1, 208656, 4, 16448, 46366), -- Highlord Bolvar Fordragon
(186785, 15, 1, 1, 2166, 8, 20, 1, 211194, 0, 64, 46366), -- Quartermaster Rahm
(181954, 15, 3, 3, 2166, 8, 996.3599853515625, 1, 209715, 2097260, 65664, 46366), -- Anduin Wrynn
(184520, 15, 2, 2, 2166, 8, 9.539999961853027343, 1, 208850, 2097256, 128, 46366), -- Anduin's Despair
(184519, 15, 3, 3, 2166, 8, 1500, 1, 208570, 1612714108, 119537798, 46366), -- Anduin's Soul
(184494, 15, 1, 1, 2166, 8, 1.360000014305114746, 1, 208842, 18874376, 67109008, 46366), -- Anduin's Doubt
(184493, 15, 0, 0, 2166, 8, 0.920000016689300537, 1, 208846, 2101368, 69206144, 46366), -- Anduin's Hope
(183033, 15, 1, 1, 2166, 8, 10.07999992370605468, 1, 209636, 2097224, 128, 46366), -- Grim Reflection
(184830, 15, 0, 0, 2166, 8, 1, 1, 208911, 0, 128, 46366), -- Beacon of Hope
(183671, 15, 2, 2, 2166, 8, 85.7375030517578125, 1, 209642, 104, 128, 46366), -- Monstrous Soul
(183669, 15, 1, 1, 2166, 8, 10.125, 1, 209647, 16777320, 144, 46366), -- Fiendish Soul
(183793, 15, 0, 0, 2166, 8, 1, 1, 210437, 0, 128, 46366), -- March of the Damned
(183463, 15, 3, 3, 2166, 8, 1162, 1, 213555, 2097260, 128, 46366), -- Remnant of a Fallen King
(183452, 15, 0, 0, 2166, 8, 1, 1, 207292, 1610612752, 117457030, 46366), -- Empty Vessel
-- HEROIC has no Lost Soul
(184585, 15, 0, 0, 2166, 8, 1, 1, 208640, 0, 128, 46366), -- Befouled Barrier
(182431, 15, 0, 0, 2165, 8, 1, 1, 206245, 1610612752, 117440582, 49570), -- Ancient Translocator
(184297, 15, 0, 0, 2165, 8, 1, 1, 208317, 1610612752, 117440582, 46366), -- Dominated Translocator
(185843, 15, 0, 0, 2165, 8, 1, 1, 210103, 1610612752, 117440582, 46366); -- Ancient Console

-- Normal Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=14 AND `Entry` IN (183666,183665,183664,184589,184613,184599,184601,186785,181954,184520,184519,184494,184493,183033,184830,183671,183669,183793,183463,183452,185607,184585,182431,184297,185843));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(183666, 14, 0, 0, 2165, 8, 100, 1, 207512, 4, 128, 46549), -- Sylvanas Windrunner
(183665, 14, 0, 0, 2165, 8, 100, 1, 207511, 4, 128, 46549), -- Uther the Lightbringer
(183664, 14, 0, 0, 2165, 8, 100, 1, 207510, 4, 128, 46549), -- Lady Jaina Proudmoore
(184589, 14, 0, 0, 2057, 8, 5, 1, 208644, 4, 16448, 46549), -- Firim
(184613, 14, 1, 1, 2165, 8, 10, 1, 208668, 0, 64, 46549), -- Knight of the Ebon Blade
(184599, 14, 2, 2, 2165, 8, 30, 1, 208654, 4, 16448, 46549), -- Thrall
(184601, 14, 2, 2, 2165, 8, 30, 1, 208656, 4, 16448, 46549), -- Highlord Bolvar Fordragon
(186785, 14, 1, 1, 2165, 8, 20, 1, 211194, 0, 64, 46549), -- Quartermaster Rahm
(181954, 14, 3, 3, 2165, 8, 992.75, 1, 209714, 2097260, 65664, 46549), -- Anduin Wrynn
(184520, 14, 2, 2, 2165, 8, 9.720000267028808593, 1, 208849, 2097256, 128, 46549), -- Anduin's Despair
(184519, 14, 3, 3, 2165, 8, 1500, 1, 208570, 1612714108, 119537798, 46549), -- Anduin's Soul
(184494, 14, 1, 1, 2165, 8, 1.279999971389770507, 1, 208841, 18874376, 67109008, 46549), -- Anduin's Doubt
(184493, 14, 0, 0, 2165, 8, 0.920000016689300537, 1, 208845, 2101368, 69206144, 46549), -- Anduin's Hope
(183033, 14, 1, 1, 2165, 8, 10.07999992370605468, 1, 209635, 2097224, 128, 51485), -- Grim Reflection
(184830, 14, 0, 0, 2165, 8, 1, 1, 208911, 0, 128, 51485), -- Beacon of Hope
-- Normal has no Monstrous Soul
(183669, 14, 1, 1, 2165, 8, 9.75, 1, 209646, 16777320, 144, 46549), -- Fiendish Soul
(183793, 14, 0, 0, 2165, 8, 1, 1, 210436, 0, 128, 51485), -- March of the Damned
(183463, 14, 3, 3, 2165, 8, 1100, 1, 213554, 2097260, 128, 46549), -- Remnant of a Fallen King
(183452, 14, 0, 0, 2165, 8, 1, 1, 207292, 1610612752, 117457030, 46549), -- Empty Vessel
-- Normal has no Lost Soul
(184585, 14, 0, 0, 2165, 8, 1, 1, 208640, 0, 128, 46549), -- Befouled Barrier
(182431, 14, 0, 0, 2165, 8, 1, 1, 206245, 1610612752, 117440582, 46549), -- Ancient Translocator
(184297, 14, 0, 0, 2165, 8, 1, 1, 208317, 1610612752, 117440582, 46549), -- Dominated Translocator
(185843, 14, 0, 0, 2165, 8, 1, 1, 210103, 1610612752, 117440582, 51485); -- Ancient Console

-- LFR Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=17 AND `Entry` IN (183666,183665,183664,184589,184613,184599,184601,186785,181954,184520,184519,184494,184493,183033,184830,183671,183669,183793,183463,183452,185607,184585,182431,184297,185843));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(183666, 17, 0, 0, 2168, 8, 100, 1, 207512, 4, 128, 46597), -- Sylvanas Windrunner
(183665, 17, 0, 0, 2168, 8, 100, 1, 207511, 4, 128, 46597), -- Uther the Lightbringer
(183664, 17, 0, 0, 2168, 8, 100, 1, 207510, 4, 128, 46597), -- Lady Jaina Proudmoore
(184589, 17, 0, 0, 2057, 8, 5, 1, 208644, 4, 16448, 46597), -- Firim
(184613, 17, 1, 1, 2168, 8, 10, 1, 208668, 0, 64, 46597), -- Knight of the Ebon Blade
(184599, 17, 2, 2, 2168, 8, 30, 1, 208654, 4, 16448, 46597), -- Thrall
(184601, 17, 2, 2, 2168, 8, 30, 1, 208656, 4, 16448, 46597), -- Highlord Bolvar Fordragon
(186785, 17, 1, 1, 2168, 8, 20, 1, 211194, 0, 64, 46597), -- Quartermaster Rahm
(181954, 17, 3, 3, 2168, 8, 992.75, 1, 209717, 2097260, 65664, 46597), -- Anduin Wrynn
-- LFR has no Anduin's Despair
(184519, 17, 3, 3, 2168, 8, 1500, 1, 208570, 1612714108, 119537798, 46597), -- Anduin's Soul
-- LFR has no Anduin's Doubt
-- LFR has no Anduin's Hope
(183033, 17, 1, 1, 2168, 8, 8, 1, 209638, 2097224, 128, 46597), -- Grim Reflection
(184830, 17, 0, 0, 2168, 8, 1, 1, 208911, 0, 128, 46597), -- Beacon of Hope
-- LFR has no Monstrous Soul
(183669, 17, 1, 1, 2168, 8, 8, 1, 209649, 16777320, 144, 46597), -- Fiendish Soul
(183793, 17, 0, 0, 2168, 8, 1, 1, 210439, 0, 128, 51485), -- March of the Damned
(183463, 17, 3, 3, 2168, 8, 1045, 1, 213557, 2097260, 128, 46597), -- Remnant of a Fallen King
-- LFR has no Empty Vessel
-- LFR has no Lost Soul
(184585, 17, 0, 0, 2168, 8, 1, 1, 208640, 0, 128, 46597), -- Befouled Barrier
-- Ancient Translocator exists correct in DB
(184297, 17, 0, 0, 2165, 8, 1, 1, 208317, 1610612752, 117440582, 46597), -- Dominated Translocator
(185843, 17, 0, 0, 2165, 8, 1, 1, 210103, 1610612752, 117440582, 51485); -- Ancient Console

-- Creatures INSERT
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 181954, 2481, 13742, 13965, '14,15,16,17', '0', 0, 0, 1, -3825.05908203125, -2715.45654296875, 91.356658935546875, 1.626035571098327636, 604800, 0, 0, 149357790, 100, 0, NULL, NULL, 50747), -- Anduin Wrynn (Area: Domination's Grasp - Difficulty: Mythic) CreateObject1 (Auras: 365177 - Willpower)
(@CGUID+1, 184519, 2481, 13742, 13965, '14,15,16,17', '17797', 0, 0, 0, -3824.513916015625, -2715.24658203125, 91.35655975341796875, 1.59902, 604800, 0, 0, 164569500, 0, 0, NULL, NULL, 50747), -- Anduin's Soul (Area: Domination's Grasp - Difficulty: Mythic) CreateObject1 (Auras: 369016 - Ghost Visual Cosmetics)
(@CGUID+2, 184354, 2481, 13742, 13965, '14,15,16,17', '0', 0, 0, 0, -3824.87158203125, -2620.020751953125, 79.05169677734375, 1.562330603599548339, 604800, 0, 0, 34998, 0, 0, NULL, NULL, 50747), -- Ancient Translocator (Area: Domination's Grasp - Difficulty: Mythic) CreateObject1 Translocator Before Anduin
(@CGUID+3, 184297, 2481, 13742, 13965, '14,15,16,17', '0', 0, 0, 0, -3824.897705078125, -2885.59716796875, 96.2000732421875, 1.572753190994262695, 604800, 0, 0, 34998, 0, 0, NULL, NULL, 50747), -- Dominated Translocator (Area: Domination's Grasp - Difficulty: Mythic) CreateObject1 Dominated Translocator
(@CGUID+4, 182431, 2481, 13742, 13965, '14,15,16,17', '0', 0, 0, 0, -3830.3056640625, -2417.88720703125, 111.1949081420898437, 1.569366693496704101, 604800, 0, 0, 34998, 0, 0, NULL, NULL, 50747), -- Ancient Translocator (Area: Domination's Grasp - Difficulty: Mythic) CreateObject1 Translocator Immortal Hearth
(@CGUID+5, 184589, 2481, 13742, 13957, '14,15,16,17', '0', 0, 0, 1, -3840.5087890625, -2615.826416015625, 79.00555419921875, 5.047886848449707031, 604800, 0, 0, 181150, 0, 0, NULL, NULL, 49570), -- Firim (Area: Immortal Hearth - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+6, 185843, 2481, 13742, 13969, '14,15,16,17', '0', 0, 0, 0, -5485.4287109375, -3870.298583984375, 128.5279388427734375, 6.061259746551513671, 604800, 0, 0, 34998, 0, 0, NULL, NULL, 50747), -- Ancient Console (Area: The Grand Design - Difficulty: Mythic) CreateObject1
(@CGUID+7, 186785, 2481, 13742, 13957, '14,15,16,17', '0', 0, 0, 1, -3825.13720703125, -2627.935791015625, 79.021240234375, 4.63619089126586914, 604800, 0, 0, 868880, 0, 0, NULL, NULL, 49570), -- Quartermaster Rahm (Area: Immortal Hearth - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+8, 184613, 2481, 13742, 13957, '14,15,16,17', '0', 0, 0, 7, -3816.84716796875, -2629.2587890625, 79.02005767822265625, 4.63619089126586914, 604800, 0, 0, 434440, 0, 0, NULL, NULL, 49570), -- Knight of the Ebon Blade (Area: Immortal Hearth - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+9, 184599, 2481, 13742, 13957, '14,15,16,17', '0', 0, 0, 1, -3838.53466796875, -2625.407958984375, 79.0087432861328125, 5.201615810394287109, 604800, 0, 0, 1303320, 0, 0, NULL, NULL, 49570), -- Thrall (Area: Immortal Hearth - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+10, 184601, 2481, 13742, 13957, '14,15,16,17', '0', 0, 0, 1, -3810.704833984375, -2624.717041015625, 79.0092010498046875, 4.327321052551269531, 604800, 0, 0, 1303320, 0, 0, NULL, NULL, 49570), -- Highlord Bolvar Fordragon (Area: Immortal Hearth - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+11, 184613, 2481, 13742, 13957, '14,15,16,17', '0', 0, 0, 3, -3833.8837890625, -2629.6806640625, 79.02220916748046875, 4.63619089126586914, 604800, 0, 0, 434440, 0, 0, NULL, NULL, 49570); -- Knight of the Ebon Blade (Area: Immortal Hearth - Difficulty: Heroic) CreateObject1 (Auras: )

UPDATE `creature` SET `StringId`='left_knight' WHERE `guid`=@CGUID+8;
UPDATE `creature` SET `StringId`='right_knight' WHERE `guid`=@CGUID+11;

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Anduin Wrynn
(@CGUID+1, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '369016 365650'), -- Anduin's Soul - 369016 - 369016, 365650 - 365650
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Quartermaster Rahm
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Knight of the Ebon Blade
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Thrall
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Highlord Bolvar Fordragon
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''); -- Knight of the Ebon Blade

-- Spell Target Positions
DELETE FROM `spell_target_position` WHERE (`EffectIndex`=0 AND `ID` IN (368563,364475));
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(368563, 0, 2481, -3824.679931640625, -2865.5400390625, 95.98999786376953125, 46366), -- Spell: 368563 (Teleport: Domination's Grasp) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)
(364475, 0, 2481, -5477.43017578125, -3877.3798828125, 128.25, 46366); -- Spell: 364475 (Teleport: Cosmic Hub) Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)

-- Jump Charge Parameters
DELETE FROM `jump_charge_params` WHERE `id`=626;
INSERT INTO `jump_charge_params` (`id`, `speed`, `treatSpeedAsMoveTimeSeconds`, `jumpGravity`, `spellVisualId`, `progressCurveId`, `parabolicCurveId`) VALUES 
(626, 0.751, 1, 70.9219, NULL, NULL, NULL); -- Necrotic Claws

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=363023 AND `SourceId`=0 AND `ElseGroup`=0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 363023, 0, 0, 31, 0, 3, 181954, 0, 0, 0, 0, '', 'Anduin Wrynn Encounter - Return to Kingsmourne'); -- Return to Kingsmourne

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=365220 AND `SourceId`=0 AND `ElseGroup`=0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 365220, 0, 0, 31, 0, 3, 184519, 0, 0, 0, 0, '', 'Despair Anduin\'s Soul');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup` IN(1, 2) AND `SourceEntry` = 365217 AND `SourceId`=0 AND `ElseGroup` IN(1, 2));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 365217, 0, 1, 31, 0, 3, 181954, 0, 0, 0, 0, '', 'Anduin Wrynn Encounter- Willpower'),
(13, 2, 365217, 0, 2, 31, 0, 3, 184519, 0, 0, 0, 0, '', 'Anduin Wrynn Encounter- Willpower');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup` IN(1, 2) AND `SourceEntry` = 365228 AND `SourceId`=0 AND `ElseGroup` IN(1, 2));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 365228, 0, 1, 31, 0, 3, 181954, 0, 0, 0, 0, '', 'Anduin Wrynn Encounter- Willpower 2'),
(13, 2, 365228, 0, 2, 31, 0, 3, 184519, 0, 0, 0, 0, '', 'Anduin Wrynn Encounter- Willpower 2');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=364239 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=4 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 364239, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Anduin Wrynn Blasphemy Pre Hit Players Only'); -- Blasphemy

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup`= (1 | 2 | 4) AND `SourceEntry`=368986 AND `SourceId`=0 AND `ElseGroup`=0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1 | 2 | 4, 368986, 0, 0, 31, 0, 3, 183033, 0, 0, 0, 0, '', 'Dark Presence hit only Grim Reflections'); -- Dark Presence

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=13 AND `SourceGroup`= (1 | 2 ) AND `SourceEntry`=367932 AND `SourceId`=0 AND `ElseGroup`=0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1 | 2, 367932, 0, 0, 31, 0, 3, 183033, 0, 0, 0, 0, '', 'Grim Fate hit only Grim Reflections'); -- Grim Fate

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=14 AND `SourceGroup`=27524 AND `SourceEntry`=43880);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(14, 27524, 43880, 0, 0, 13, 0, 7, 3, 2, 0, 0, 0, '', 'Show option teleport to Cosmic Hub if Anduin Wrynn is done');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=362405 AND `SourceId`=0 AND `ElseGroup`=0 AND `ConditionTypeOrReference`=31 AND `ConditionTarget`=0 AND `ConditionValue1`=4 AND `ConditionValue2`=0 AND `ConditionValue3`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 362405, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Anduin Wrynn Kingsmourne Hungers hit Players only'); -- Kingsmourne Hungers

-- Areatriggers Create Properties
DELETE FROM `areatrigger_create_properties` WHERE `Id`IN (25025,24741,24740,24616,24599,24443,24429,24332,24322,24247,24093);
INSERT INTO `areatrigger_create_properties` (`Id`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `VerifiedBuild`) VALUES 
(25025, 28469, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_beacon_of_hope', 50747),
(24741, 28391, 0, 0, 0, 0, -1, 0, 0, 5228, 0, 4, 1.75, 1.75, 8, 8, 2, 2, 0, 0, 'at_anduin_wrynn_wicked_star', 43206),
(24740, 28391, 0, 0, 0, 0, -1, 0, 0, 5228, 0, 4, 1.75, 1.75, 8, 8, 2, 2, 0, 0, 'at_anduin_wrynn_wicked_star', 43206),
(24616, 28622, 0, 0, 0, 0, -1, 0, 0, 0, 10000, 0, 4, 4, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_blasphemy', 43206),
(24599, 28391, 0, 0, 0, 0, -1, 0, 0, 5228, 0, 4, 1.75, 1.75, 8, 8, 2, 2, 0, 0, 'at_anduin_wrynn_empowered_wicked_star', 43206),
(24443, 28483, 0, 0, 0, 0, -1, 0, 0, 0, 29999, 0, 3, 3, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_hopelessness', 43206),
(24429, 28470, 0, 0, 0, 0, -1, 0, 0, 0, 2750, 0, 3, 3, 0, 0, 0, 0, 0, 0, '', 50747),
(24332, 28422, 0, 0, 0, 0, -1, 0, 0, 0, 30000, 0, 1, 1, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_befouled_barrier', 43206),
(24322, 28391, 0, 0, 0, 0, -1, 0, 0, 5228, 0, 4, 1.75, 1.75, 8, 8, 2, 2, 0, 0, 'at_anduin_wrynn_wicked_star', 43206),
(24247, 28469, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 'at_anduin_wrynn_beacon_of_hope', 43206),
(24093, @ATID+1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 1, 2, 16, 2.3, 2, 16, 2.3, 0, 0, 'at_anduin_wrynn_march_of_the_damned', 0);

-- Areatrigger Template
DELETE FROM `areatrigger_template` WHERE ((`Id` IN (28391,28422,28469,28470,28483,28622,@ATID+1) AND `IsServerSide`=0) OR (`Id`=@ATID+0 AND `IsServerSide`=1));
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES 
(28391, 0, 4, 0, 1.75, 1.75, 8, 8, 2, 2, 0, 0, 43206), -- Wicked Star
(28422, 0, 0, 4, 1, 1, 0, 0, 0, 0, 0, 0, 43206), -- Befouled Barrier
(28469, 0, 0, 4, 1, 1, 0, 0, 0, 0, 0, 0, 50747), -- Beacon of Hope
(28470, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 50747), -- Fragment of Hope
(28483, 0, 0, 4, 3, 3, 0, 0, 0, 0, 0, 0, 43206), -- Hopelessness
(28622, 0, 0, 4, 4, 4, 0, 0, 0, 0, 0, 0, 43206), -- Blasphemy
(@ATID+1, 0, 1, 4, 2, 16, 2.3, 2, 16, 2.3, 0, 0, 0), -- Custom AT March of the Damned
(@ATID+0, 1, 1, 0, 30, 50, 5, 30, 50, 5, 0, 0, 0); -- Introduction

DELETE FROM `areatrigger` WHERE `SpawnId`=@ATSPAWNID+0;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `SpellForVisuals`, `ScriptName`, `Comment`, `VerifiedBuild`) VALUES 
(@ATSPAWNID+0, @ATID+0, 1, 2481, '14,15,16,17', -3824.87, -2620.02, 79.0517, 1.56233, 1, 0, 0, 1, 30, 50, 5, 30, 50, 5, 0, 0, NULL, 'at_anduin_wrynn_pre_introduction', '', 0); -- Introduction

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (181954, 183671);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `SoundPlayType`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(181954, 0, 0, 'Your reality ends here!', 14, 0, 100, 0, 0, 190135, 0, 214636, 0, 'Aggro'),
(181954, 1, 0, 'Break!', 14, 0, 100, 0, 0, 190054, 0, 214962, 0, 'Hopebreaker'),
(181954, 2, 0, 'Darkness consumes light!', 14, 0, 100, 0, 0, 190056, 0, 214961, 0, 'Befouled Barrier'),
(181954, 3, 0, 'There is no balance!', 14, 0, 100, 0, 0, 190055, 0, 214960, 0, 'Blasphemy'),
(181954, 4, 0, '|TInterface\\ICONS\\Ability_Priest_FocusedWill.blp:20|t Anduin begins casting |cFFFF0000|Hspell:361989|h[Blasphemy]|h|r!', 41, 0, 100, 0, 0, 53980, 0, 0, 0, 'Blasphemy Warning'),
(181954, 5, 0, '|TInterface\\ICONS\\Ability_Deathknight_HungeringRuneblade.BLP:20|t Anduin begins casting |cFFFF0000|Hspell:362405|h[Kingsmourne Hungers]|h|r!', 41, 0, 100, 0, 0, 190057, 0, 0, 0, 'Kingsmourne Warning'),
(181954, 6, 0, 'Kingsmourne hungers!', 14, 0, 100, 0, 0, 190057, 0, 214963, 0, 'Kingsmourne Hungers'),
(181954, 7, 0, 'Your end has come!', 14, 0, 100, 0, 0, 190052, 0, 214954, 0, 'Wicked Star'),
(181954, 8, 0, '|TInterface\\ICONS\\Spell_Priest_DivineStar_Shadow2.blp:20|t Anduin targets you with |cFFFF0000|Hspell:365017|h[Wicked Star]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Wicked Star Warning'),
(181954, 9, 0, 'Terrors, arise and obey!', 14, 0, 100, 0, 0, 190058, 0, 214966, 0, 'Summoning'),
(181954, 10, 0, 'Kneel!', 14, 0, 100, 0, 0, 190120, 0, 214637, 0, 'Slay 01'),
(181954, 10, 1, 'Submit!', 14, 0, 100, 0, 0, 190121, 0, 214638, 0, 'Slay 02'),
(181954, 11, 0, 'Fall!', 14, 0, 100, 0, 0, 190053, 0, 214955, 0, 'Empowered Hopebreaker'),
(181954, 12, 0, 'The Light has abandoned you.', 14, 0, 100, 0, 0, 190122, 0, 214639, 0, 'Reset'),
(183671, 13, 0, '|TInterface\\\\ICONS\\\\Tradeskill_AbominationStitching_Abominations_Mid.BLP:20|t %s begins casting |cFFFF0000|Hspell:363024|h[Necrotic Detonation]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Monstrous Soul Detonation'),
(181954, 14, 0, '|TInterface\\ICONS\\Spell_Priest_DivineStar_Shadow2.blp:20|t Anduin targets you with |cFFFF0000|Hspell:367631|h[Empowered Wicked Star]|h|r!', 41, 0, 100, 0, 0, 0, 0, 0, 0, 'Empowered Wicked Star Warning');

-- Conversations Template
DELETE FROM `conversation_template` WHERE `Id` IN (17921, 17923, 17924, 17835, 17836);
INSERT INTO `conversation_template` (`Id`, `FirstLineId`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES 
(17921, 45676, 0, '', 46366), -- First Intermission
(17923, 45757, 0, '', 46366), -- Second Intermission
(17924, 45674, 0, '', 43206), -- Anduin Phase 3
(17835, 45384, 0, '', 46549), -- Introduction
(17836, 45390, 0, '', 46597); -- Outroduction

-- Conversation Actors
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
(17924, 82831, @CGUID+0, 0, 181954, 0, 0, 0, 50747);

DELETE FROM `conversation_actors` WHERE `ConversationId`=17835;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES 
(17835, 83274, 0, 3, 183664, 0, 0, 0, 46549),
(17835, 83276, 0, 2, 183666, 0, 0, 0, 46549),
(17835, 83275, 0, 1, 183665, 0, 0, 0, 46549),
(17835, 83809, 0, 0, 181411, 100456, 0, 0, 46549);

DELETE FROM `conversation_actors` WHERE `ConversationId`=17836;
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES 
(17836, 83787, 0, 4, 184589, 0, 0, 0, 46597),
(17836, 83275, 0, 3, 183665, 0, 0, 0, 46597),
(17836, 83276, 0, 2, 183666, 0, 0, 0, 46597),
(17836, 83274, 0, 1, 183664, 0, 0, 0, 46597),
(17836, 82831, @CGUID+0, 0, 181954, 0, 0, 0, 46597);

-- Conversatoin Lines
DELETE FROM `conversation_line_template` WHERE `Id` IN (45665, 45664, 45663, 45662, 45676, 45389, 45388, 45387, 45386, 45385, 45384, 45399, 45398, 45397, 45396, 45675, 45674, 45673, 45672, 45671, 45670, 45757, 45988, 45987, 45986, 45336, 45335, 45334, 45333, 45353, 45352, 45351);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(45665, 0, 0, 0, 1, 51485),
(45664, 0, 0, 0, 1, 51485),
(45663, 0, 0, 0, 1, 51485),
(45662, 0, 1, 0, 1, 51485),
(45676, 0, 0, 0, 1, 51485),
(45389, 0, 3, 1, 0, 51485),
(45388, 0, 2, 1, 0, 51485),
(45387, 0, 1, 1, 0, 51485),
(45386, 1547, 0, 0, 0, 51485),
(45385, 1547, 0, 0, 0, 51485),
(45384, 1547, 0, 0, 0, 51485),
(45399, 0, 2, 1, 0, 51485),
(45398, 0, 0, 1, 0, 51485),
(45397, 0, 1, 1, 0, 51485),
(45396, 0, 0, 1, 0, 51485),
(45675, 0, 0, 0, 1, 51485),
(45674, 0, 0, 0, 1, 51485),
(45673, 0, 0, 0, 1, 51485),
(45672, 0, 0, 0, 1, 51485),
(45671, 0, 0, 0, 1, 51485),
(45670, 0, 1, 0, 1, 51485),
(45757, 0, 0, 0, 1, 51485),
(45988, 1547, 1, 0, 0, 51485),
(45987, 1547, 1, 0, 0, 51485),
(45986, 1547, 1, 0, 0, 51485),
(45336, 0, 0, 0, 0, 51485),
(45335, 0, 0, 0, 0, 51485),
(45334, 0, 0, 0, 0, 51485),
(45333, 0, 0, 0, 0, 51485),
(45353, 0, 0, 0, 0, 51485),
(45352, 0, 0, 0, 0, 51485),
(45351, 0, 0, 0, 0, 51485);

-- Template Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=184297 AND `MenuID`=27524) OR (`CreatureID`=185843 AND `MenuID`=27687);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(184297, 27524, 51485), -- Dominated Translocator
(185843, 27687, 51485); -- Ancient Console

-- Gossip Menu
DELETE FROM `gossip_menu` WHERE (`MenuID`=27524 AND `TextID`=43880) OR (`MenuID`=27687 AND `TextID`=44097);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(27524, 43880, 51485), -- 184297 (Dominated Translocator)
(27687, 44097, 51485); -- 185843 (Ancient Console)

-- Gossip Menu Option
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (27524,27687));
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(52440, 27524, 0, 0, 'Proceed.', 19484, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 51485),
(54619, 27687, 0, 0, 'Proceed.', 19484, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 51485);

UPDATE `npc_text` SET `Probability0`=1 WHERE `ID`=43880;

-- Sylvanas Waypoints
SET @WPID := 183666 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@WPID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@WPID, 0, -3819.6, -2631.98, 79.3011, 0, 0, 1, 0, 100, 0),
(@WPID, 1, -3817.85, -2636.98, 77.5977, 0, 0, 1, 0, 100, 0),
(@WPID, 2, -3815.1, -2638.98, 77.9912, 0, 0, 1, 0, 100, 0),
(@WPID, 3, -3814.62, -2641.23, 78.034, 0, 0, 1, 0, 100, 0),
(@WPID, 4, -3814.1, -2642.98, 78.3127, 0, 0, 1, 0, 100, 0),
(@WPID, 5, -3813.85, -2644.23, 78.3127, 0, 0, 1, 0, 100, 0),
(@WPID, 6, -3813.35, -2645.73, 78.3119, 0, 0, 1, 0, 100, 0),
(@WPID, 7, -3814.1, -2658.98, 85.1276, 0, 0, 1, 0, 100, 0),
(@WPID, 8, -3814.1, -2667.23, 89.5433, 0, 0, 1, 0, 100, 0),
(@WPID, 9, -3814.1, -2668.98, 90.478, 0, 0, 1, 0, 100, 0),
(@WPID, 10, -3814.85, -2670.23, 90.7048, 0, 0, 1, 0, 100, 0),
(@WPID, 11, -3816.6, -2672.98, 90.7669, 0, 0, 1, 0, 100, 0),
(@WPID, 12, -3816.35, -2677.23, 91.4469, 0, 0, 1, 0, 100, 0),
(@WPID, 13, -3819.48, -2687.19, 91.2658, 0, 0, 1, 0, 100, 0);

-- Uther Waypoints
SET @WPID := 183665 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@WPID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@WPID, 0, -3831.11, -2632.01, 79.6914, 0, 0, 1, 0, 100, 0),
(@WPID, 1, -3831.61, -2633.76, 78.9414, 0, 0, 1, 0, 100, 0),
(@WPID, 2, -3832.11, -2637.26, 78.1914, 0, 0, 1, 0, 100, 0),
(@WPID, 3, -3831.36, -2646.26, 78.1914, 0, 0, 1, 0, 100, 0),
(@WPID, 4, -3830.86, -2651.76, 81.1914, 0, 0, 1, 0, 100, 0),
(@WPID, 5, -3830.36, -2658.01, 84.6914, 0, 0, 1, 0, 100, 0),
(@WPID, 6, -3829.86, -2670.26, 91.1914, 0, 0, 1, 0, 100, 0),
(@WPID, 7, -3832.61, -2676.51, 91.6914, 0, 0, 1, 0, 100, 0),
(@WPID, 8, -3831.61, -2679.01, 91.4414, 0, 0, 1, 0, 100, 0),
(@WPID, 9, -3828.03, -2688.25, 91.4532, 0, 0, 1, 0, 100, 0);

-- Jaina Waypoints
SET @WPID := 183664 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@WPID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@WPID, 0, -3825.8, -2630.24, 79.7114, 0, 0, 1, 0, 100, 0),
(@WPID, 1, -3825.3, -2631.99, 79.7114, 0, 0, 1, 0, 100, 0),
(@WPID, 2, -3824.55, -2633.74, 78.9614, 0, 0, 1, 0, 100, 0),
(@WPID, 3, -3824.8, -2636.99, 78.2114, 0, 0, 1, 0, 100, 0),
(@WPID, 4, -3824.8, -2646.24, 78.2114, 0, 0, 1, 0, 100, 0),
(@WPID, 5, -3824.8, -2651.74, 81.2114, 0, 0, 1, 0, 100, 0),
(@WPID, 6, -3824.55, -2659.49, 85.4614, 0, 0, 1, 0, 100, 0),
(@WPID, 7, -3825.05, -2670.24, 91.2114, 0, 0, 1, 0, 100, 0),
(@WPID, 8, -3824.65, -2692.2, 91.4932, 0, 0, 1, 0, 100, 0);

-- Firim Waypoints
SET @WPID := 184589 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@WPID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@WPID, 0, -3833, -2627.62, 79.4742, 0, 0, 1, 0, 100, 0),
(@WPID, 1, -3829.5, -2630.37, 79.7242, 0, 0, 1, 0, 100, 0),
(@WPID, 2, -3829.5, -2631.87, 79.7242, 0, 0, 1, 0, 100, 0),
(@WPID, 3, -3832, -2633.62, 78.9742, 0, 0, 1, 0, 100, 0),
(@WPID, 4, -3832.25, -2637.37, 78.2242, 0, 0, 1, 0, 100, 0),
(@WPID, 5, -3831.75, -2646.12, 78.2242, 0, 0, 1, 0, 100, 0),
(@WPID, 6, -3831.5, -2651.62, 81.2242, 0, 0, 1, 0, 100, 0),
(@WPID, 7, -3831, -2657.87, 84.7242, 0, 0, 1, 0, 100, 0),
(@WPID, 8, -3830.25, -2670.37, 91.2242, 0, 0, 1, 0, 100, 0),
(@WPID, 9, -3832.75, -2676.37, 91.7242, 0, 0, 1, 0, 100, 0),
(@WPID, 10,-3830.1892, -2688.1267, 91.43489, 0, 0, 1, 0, 100, 0);

-- Thrall Waypoints
SET @WPID := 184599 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@WPID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@WPID, 0, -3832.8462, -2626.8916, 79.4441, 0, 0, 1, 0, 100, 0),
(@WPID, 1, -3832.5962, -2631.8916, 79.6941, 0, 0, 1, 0, 100, 0),
(@WPID, 2, -3832.0962, -2633.6416, 78.9441, 0, 0, 1, 0, 100, 0),
(@WPID, 3, -3832.3462, -2637.3916, 78.1941, 0, 0, 1, 0, 100, 0),
(@WPID, 4, -3834.5962, -2641.1416, 78.4441, 0, 0, 1, 0, 100, 0),
(@WPID, 5, -3835.0962, -2645.6416, 78.9441, 0, 0, 1, 0, 100, 0),
(@WPID, 6, -3836.3462, -2646.1416, 78.9441, 0, 0, 1, 0, 100, 0),
(@WPID, 7, -3835.5962, -2662.1416, 87.4441, 0, 0, 1, 0, 100, 0),
(@WPID, 8, -3833.8462, -2670.1416, 91.1941, 0, 0, 1, 0, 100, 0),
(@WPID, 9, -3832.8462, -2672.3916, 91.1941, 0, 0, 1, 0, 100, 0),
(@WPID, 10, -3833.0962, -2676.3916, 91.6941, 0, 0, 1, 0, 100, 0),
(@WPID, 11, -3833.0962, -2679.1416, 91.6941, 0, 0, 1, 0, 100, 0),
(@WPID, 12, -3833.0962, -2681.8916, 91.4441, 0, 0, 1, 0, 100, 0),
(@WPID, 13, -3833.2378, -2684.1145, 91.2652, 0, 0, 1, 0, 100, 0);

-- Bolvar Waypoints
SET @WPID := 184601 * 100;
DELETE FROM `waypoint_data` WHERE `id`=@WPID;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES 
(@WPID, 0, -3816.6367, -2631.9243, 79.808624, 0, 0, 1, 0, 100, 0),
(@WPID, 1, -3815.1367, -2639.1743, 78.308624, 0, 0, 1, 0, 100, 0),
(@WPID, 2, -3814.6367, -2641.4243, 78.558624, 0, 0, 1, 0, 100, 0),
(@WPID, 3, -3814.1367, -2643.1743, 78.558624, 0, 0, 1, 0, 100, 0),
(@WPID, 4, -3813.8867, -2644.1743, 78.808624, 0, 0, 1, 0, 100, 0),
(@WPID, 5, -3813.3867, -2645.6743, 78.808624, 0, 0, 1, 0, 100, 0),
(@WPID, 6, -3814.1367, -2658.9243, 85.558624, 0, 0, 1, 0, 100, 0),
(@WPID, 7, -3814.1367, -2667.4243, 90.308624, 0, 0, 1, 0, 100, 0),
(@WPID, 8, -3814.1367, -2669.1743, 91.058624, 0, 0, 1, 0, 100, 0),
(@WPID, 9, -3814.6367, -2670.4243, 91.308624, 0, 0, 1, 0, 100, 0),
(@WPID, 10, -3816.3867, -2672.9243, 91.308624, 0, 0, 1, 0, 100, 0),
(@WPID, 11, -3816.1367, -2677.1743, 91.558624, 0, 0, 1, 0, 100, 0),
(@WPID, 12, -3817.2275, -2682.5625, 91.525320, 0, 0, 1, 0, 100, 0);

-- Spell Scripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (367524,366848,369317,364247,361815,361817,361818,365293,365173,361989,361993,361992,365021,362405,365652,362055,362402,367769,362392,368913,363233,365120,365872,365806,365958,365966,362500,365291,362862,362863,362771,362543,362545,363021,363022,367632,363029,365816);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(367524, 'spell_anduin_wrynn_pre_introduction'),
(366848, 'spell_anduin_wrynn_energize_willpower_lfr'),
(369317, 'spell_anduin_wrynn_progression_aura'),
(364247, 'spell_anduin_wrynn_dark_zeal'),
(361815, 'spell_anduin_wrynn_hopebreaker'),
(361817, 'spell_anduin_wrynn_hopebreaker_periodic'),
(361818, 'spell_anduin_wrynn_hopebreaker_damage'),
(365293, 'spell_anduin_wrynn_befouled_barrier_absorb'),
(365173, 'spell_anduin_wrynn_befouled_barrier_expire'),
(361989, 'spell_anduin_wrynn_blasphemy'),
(361993, 'spell_anduin_wrynn_hopelessness_overconfidence'),
(361992, 'spell_anduin_wrynn_hopelessness_overconfidence'),
(365021, 'spell_anduin_wrynn_wicked_star_selector'),
(362405, 'spell_anduin_wrynn_kingsmourne_hungers'),
(365652, 'spell_anduin_soul_lost_soul'),
(362055, 'spell_anduin_wrynn_lost_soul'),
(362402, 'spell_anduin_wrynn_lost_soul_mirror_image'),
(367769, 'spell_anduin_wrynn_severed_soul'),
(362392, 'spell_anduin_rain_of_despair_player_selector'),
(368913, 'spell_anduin_wrynn_force_of_will'),
(363233, 'spell_anduin_wrynn_march_of_the_damned'),
(365120, 'spell_anduin_wrynn_grim_reflections'),
(365872, 'spell_anduin_wrynn_beacon_of_hope'),
(365806, 'spell_anduin_wrynn_hopebreaker'),
(365958, 'spell_anduin_wrynn_hopelessness'),
(365966, 'spell_anduin_wrynn_hopelessness_expire'),
(362500, 'spell_remnant_of_a_fallen_king_spawn'),
(365291, 'spell_remnant_of_a_fallen_king_energize_runic_power'),
(362862, 'spell_remnant_of_a_fallen_king_army_of_the_dead'),
(362863, 'spell_remnant_of_a_fallen_king_echoes_of_andorhal'),
(362771, 'spell_remnant_of_a_fallen_king_soul_reaper'),
(362543, 'spell_remnant_of_a_fallen_king_remorseless_winter_periodic'),
(362545, 'spell_remnant_of_a_fallen_king_remorseless_winter_damage'),
(363021, 'spell_remnant_of_a_fallen_king_return_to_kingsmourne'),
(363022, 'spell_remnant_of_a_fallen_king_return_to_kingsmourne_applied'),
(367632, 'spell_anduin_wrynn_empowered_wicked_star_selector'),
(363029, 'spell_friendish_soul_explosion'),
(365816, 'spell_anduin_wrynn_fragment_of_hope');

DELETE FROM `creature_template_sparring` WHERE `Entry` IN(183666, 183664, 183665, 181954, 183669, 183671, 183463, 183033);
INSERT INTO `creature_template_sparring` (`Entry`, `NoNPCDamageBelowHealthPct`) VALUES
(183666, 100), -- Sylvanas Windrunner
(183664, 100), -- Jaina Proudmoore
(183665, 100), -- Uther the Lightbringer
(181954, 100), -- Anduin
(183669, 100), -- Fiendish Soul
(183671, 100), -- Monstrous Soul
(183463, 100), -- Remnant
(183033, 100); -- Grim Reflection
