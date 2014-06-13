UPDATE `creature_template` SET `speed_walk` = 1.66667, `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'TW_boss_thorim' WHERE `entry` = 32865;
UPDATE `creature_template` SET `speed_walk` = 1.66667, `baseattacktime` = 1500, `mechanic_immune_mask` = 650854239 WHERE `entry` = 33147;
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62042;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
('62042','62470','1','Thorim: Deafening Thunder');

-- Charge Orb
UPDATE `creature_template` SET `unit_flags` = 33685508 WHERE `entry` = 33378;

-- Gate
DELETE FROM `gameobject_template` WHERE `entry`=194265;
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `ScriptName`, `WDBVerified`) VALUES
('194265','1','295','Lever','','','','35','48','3','0','0','0','0','0','0','0','0','6000','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','TW_go_thorim_lever','0');
UPDATE `gameobject` SET `id` = 194265, `rotation2` = 1, `rotation3` = 0, `spawntimesecs` = 7200, `animprogress` = 100 WHERE `guid` = 55194;

-- Cleanup
DELETE FROM `creature` WHERE `id` IN (32885, 32883, 32908, 32907, 32882, 33110, 32886, 32879, 32892, 33140, 33141, 33378, 32874, 32875)
OR guid IN (136694, 136695, 136666, 136706, 136754, 136653, 136756, 136757, 136725, 136718);

-- Pre adds
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_thorim_pre_phase' WHERE `entry` = 32885;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_thorim_pre_phase' WHERE `entry` = 32883;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_thorim_pre_phase' WHERE `entry` = 32908;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_thorim_pre_phase' WHERE `entry` = 32907;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_thorim_pre_phase' WHERE `entry` = 32882;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_thorim_pre_phase' WHERE `entry` = 32886;
UPDATE `creature_template` SET `modelid1` = 16925, `modelid2` = 0 WHERE `entry`IN (33378, 32892);

-- Thorim Mini bosses
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'TW_npc_runic_colossus' WHERE `entry` = 32872;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'TW_npc_ancient_rune_giant' WHERE `entry` = 32873;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854239, `flags_extra` = 1, `ScriptName` = 'TW_npc_sif' WHERE `entry` = 33196;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_thorim_arena_phase' WHERE `entry` IN (32876, 32904, 32878, 32877, 32874, 32875, 33110);
DELETE FROM `creature_addon` WHERE `guid`IN (136059, 136816);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
('136059','0','0','0','1','0','40775 0'),
('136816','0','0','0','1','0','40775 0');

DELETE FROM `conditions` WHERE `SourceEntry` = 62016 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`)VALUES
(13, 1, 62016, 0, 0, 31, 0, 3, 33378, 0, 0, 0, 0,'','Thorim - Charge Orb');

DELETE FROM `spell_script_names` WHERE `spell_id`=62560;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62560, 'TW_spell_thorim_berserk');

UPDATE `creature_template` SET `ScriptName` = 'TW_npc_runic_smash' WHERE `entry` = 33140; -- Creature had no ScriptName set

DELETE FROM `spell_dbc` WHERE `Id` IN (64980);
INSERT INTO `spell_dbc` (`Id`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `Stances`, `StancesNot`, `Targets`, `CastingTimeIndex`, `AuraInterruptFlags`, `ProcFlags`, `ProcChance`, `ProcCharges`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `Effect1`, `Effect2`, `Effect3`, `EffectDieSides1`, `EffectDieSides2`, `EffectDieSides3`, `EffectRealPointsPerLevel1`, `EffectRealPointsPerLevel2`, `EffectRealPointsPerLevel3`, `EffectBasePoints1`, `EffectBasePoints2`, `EffectBasePoints3`, `EffectMechanic1`, `EffectMechanic2`, `EffectMechanic3`, `EffectImplicitTargetA1`, `EffectImplicitTargetA2`, `EffectImplicitTargetA3`, `EffectImplicitTargetB1`, `EffectImplicitTargetB2`, `EffectImplicitTargetB3`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectRadiusIndex3`, `EffectApplyAuraName1`, `EffectApplyAuraName2`, `EffectApplyAuraName3`, `EffectAmplitude1`, `EffectAmplitude2`, `EffectAmplitude3`, `EffectMultipleValue1`, `EffectMultipleValue2`, `EffectMultipleValue3`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectMiscValue3`, `EffectMiscValueB1`, `EffectMiscValueB2`, `EffectMiscValueB3`, `EffectTriggerSpell1`, `EffectTriggerSpell2`, `EffectTriggerSpell3`, `EffectSpellClassMaskA1`, `EffectSpellClassMaskA2`, `EffectSpellClassMaskA3`, `EffectSpellClassMaskB1`, `EffectSpellClassMaskB2`, `EffectSpellClassMaskB3`, `EffectSpellClassMaskC1`, `EffectSpellClassMaskC2`, `EffectSpellClassMaskC3`, `MaxTargetLevel`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `MaxAffectedTargets`, `DmgClass`, `PreventionType`, `DmgMultiplier1`, `DmgMultiplier2`, `DmgMultiplier3`, `AreaGroupId`, `SchoolMask`, `Comment`) VALUES
(64980, 0, 0, 536870912, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 101, 0, 0, 0, 0, 0, 1, 0, -1, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 0, 0, 7, 0, 0, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Achievement Siffed Checker');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10440, 10457, 10314, 10289) AND `type` IN (18, 11);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10440, 11, 0, 0, 'TW_achievement_siffed_and_lose_your_illusion'),
(10457, 11, 0, 0, 'TW_achievement_siffed_and_lose_your_illusion'),
(10289, 11, 0, 0, 'TW_achievement_siffed_and_lose_your_illusion'),
(10314, 11, 0, 0, 'TW_achievement_siffed_and_lose_your_illusion');

DELETE FROM `conditions` WHERE `SourceEntry` = 64098 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`)VALUES
(13, 1, 64098, 0, 0, 31, 0, 3, 32865, 0, 0, 0, 0,'','Thorim Charged Pillar - Lightning Bolt'),
(13, 1, 64098, 0, 1, 31, 0, 3, 33147, 0, 0, 0, 0,'','Thorim Charged Pillar - Lightning Bolt');

DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10305, 10309) AND `type` IN (18, 11);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10305, 11, 0, 0, 'TW_achievement_dont_stand_in_the_lightning'),
(10309, 11, 0, 0, 'TW_achievement_dont_stand_in_the_lightning');

DELETE FROM `conditions` WHERE `SourceEntry` = 62466 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`)VALUES
(13, 4, 62466, 0, 0, 31, 0, 3, 32780, 0, 0, 0, 0,'','Thorim - Lightning Charge');

-- Properly script his trap bunnies
DELETE FROM `creature_addon` WHERE `guid` IN (136059, 136816) AND `auras` = 40775; -- clean up wrong addon data
UPDATE `creature_template` SET `ScriptName` = 'TW_thorim_trap_bunny' WHERE `entry` IN (33725, 33054);

-- Thorim Runic Fortification
DELETE FROM `spell_script_names` WHERE `spell_id`=62942;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62942, 'TW_spell_thorim_runic_fortification');

-- Some work around Thorim's speech
DELETE FROM `creature_text` WHERE `entry` = 32865 AND `groupid` IN (20, 21);
INSERT INTO `creature_text` (`entry`,`groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(32865, 20, 0, 'I remember you... In the mountains... But you... what is this? Where am--', 14, 0, 100, 0, 0,  15734, 'Thorim SAY_AGGRO_2'),
(32865,	21, 0, 'Interlopers! You mortals who dare TO interfere WITH my sport will pay... WAIT--you...', 14, 0, 100, 0, 0, 15733, 'Thorim SAY_AGGRO_1');

-- Mimiron SQL

UPDATE `gameobject_template` SET `flags` = 32, `data2` = 3000, `ScriptName` = 'TW_go_call_tram' WHERE `entry` IN (194914, 194912, 194437);
DELETE FROM gameobject WHERE id = '194437';
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
('194437','603','1','1','2306.87','274.237','424.288','1.52255','0','0','0.689847','0.723956','300','0','1');
DELETE FROM gameobject_template WHERE entry = '194438';
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `faction`, `flags`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `ScriptName`, `WDBVerified`) VALUES
('194438','1','8504','Activate Tram','','','','0','32','1','0','0','0','0','0','0','0','0','3000','0','0','1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','TW_go_call_tram','11159');
DELETE FROM gameobject WHERE id = '194438';
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(194438, 603, 1,1,2306.99, 2589.35, 424.382, 4.71676, 0, 0, 0.705559, -0.708651, 300, 0, 1);

-- Mimiron
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `ScriptName` = 'TW_boss_mimiron' WHERE `entry` = 33350;
-- Leviathan MKII
UPDATE `creature_template` SET `vehicleid` = 370, `mechanic_immune_mask` = 650854235, `ScriptName` = 'TW_boss_leviathan_mk' WHERE `entry` = 33432;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` = 34106;
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `ScriptName` = 'TW_boss_leviathan_mk_turret' WHERE `entry` = 34071;
DELETE FROM vehicle_template_accessory WHERE entry = 33432;
INSERT INTO vehicle_template_accessory VALUE (33432, 34071, 3, 1, 'Leviathan Mk II turret', 8, 0);
UPDATE creature_template SET ScriptName = 'TW_npc_proximity_mine' WHERE entry = 34362;
DELETE FROM `creature_model_info` WHERE `modelid`=28831;
INSERT INTO `creature_model_info` (`modelid`, `bounding_radius`, `combat_reach`, `gender`, `modelid_other_gender`) VALUES
(28831, 0.5, 7, 2, 0);
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (33432,33651);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(33432,46598,1,0), -- Leviatan MKII - Ride Vehicle Hardcoded
(33651,46598,1,0); -- VX 001 - Ride Vehicle Hardcoded

-- VX-001
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `flags_extra` = 1, `vehicleid` = 371, `ScriptName` = 'TW_boss_vx_001' WHERE `entry` = 33651;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` = 34108;
UPDATE `creature_template` SET `faction_A` = 35, `faction_H` = 35 WHERE `entry` = 34050;
UPDATE `creature_template` SET `unit_flags` = 33686020, `flags_extra` = 2 WHERE `entry` = 34211;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_rocket_strike' WHERE `entry` = 34047;

-- Aerial Command Unit
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854235, `flags_extra` = 1, `InhabitType` = `InhabitType`|3, `ScriptName` = 'TW_boss_aerial_unit', `vehicleid` = 372 WHERE `entry` = 33670;
UPDATE `creature_template` SET `minlevel` = 83, `maxlevel` = 83, `mechanic_immune_mask` = 650854235, `flags_extra` = 1 WHERE `entry` = 34109;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_magnetic_core' WHERE `entry` = 34068;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_assault_bot' WHERE `entry` = 34057;
UPDATE `creature_template` SET `difficulty_entry_1` = 34148, `ScriptName` = 'TW_npc_emergency_bot' WHERE `entry` = 34147;

-- HardMode
UPDATE `gameobject_template` SET `flags` = 32, `ScriptName` = 'TW_go_not_push_button' WHERE `entry` = 194739;
UPDATE `creature_template` SET `difficulty_entry_1` = 34361, `ScriptName` = 'TW_npc_frost_bomb' WHERE `entry` = 34149;
UPDATE `creature_template` SET `speed_walk` = 0.15, `speed_run` = 0.15, `ScriptName` = 'TW_npc_mimiron_flame_trigger' WHERE `entry` = 34363;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_mimiron_flame_spread' WHERE `entry` = 34121;
UPDATE `creature_template` SET `ScriptName` = 'TW_npc_mimiron_bomb_bot' WHERE `entry` = 33836;

-- CleanUp
DELETE FROM creature WHERE id IN (34071, 33856);
UPDATE `creature_template` SET `flags_extra` = 2 WHERE `entry` = 34143;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'TW_spell_rapid_burst';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63382, 'TW_spell_rapid_burst');

DELETE FROM `disables` WHERE `entry` IN (10450, 10463) AND `SourceType` = 4;
DELETE FROM `achievement_criteria_data` WHERE `ScriptName` = 'TW_achievement_firefighter';
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10450, 11, 0, 0, 'TW_achievement_firefighter'),
(10463, 11, 0, 0, 'TW_achievement_firefighter');

-- Conditions for Mimiron's Frost Bomb (64623)
DELETE FROM `conditions` WHERE `SourceEntry` = 64623 AND `SourceTypeOrReferenceId` = 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`)VALUES
(13, 1, 64623, 0, 0, 31, 0, 3, 34121, 0, 0, 0, 0,'','Mimiron - Frost Bomb on Flame (Spread)'),
(13, 1, 64623, 0, 1, 31, 0, 3, 34149, 0, 0, 0, 0,'','Mimiron - Frost Bomb on Flame (Initial)');

UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14 WHERE `entry` IN (34149, 34361); -- Previous value was 35

-- Implements achievement Not-So-Friendly Fire 
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`='10405' AND `type`='18'; 
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`='10406' AND `type`='18'; 

-- Implements achievement Set Us Up The Bomb
DELETE FROM `achievement_criteria_data` WHERE `criteria_id` IN (10543, 10544, 10545, 10548, 10547, 10546) AND `type` = 11;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(10543, 11, 0, 0, "TW_achievement_set_us_up_the_bomb_mine"),
(10544, 11, 0, 0, "TW_achievement_set_us_up_the_bomb_rocket"),
(10545, 11, 0, 0, "TW_achievement_set_us_up_the_bomb_bot"),
(10546, 11, 0, 0, "TW_achievement_set_us_up_the_bomb_mine"),
(10547, 11, 0, 0, "TW_achievement_set_us_up_the_bomb_rocket"),
(10548, 11, 0, 0, "TW_achievement_set_us_up_the_bomb_bot");

DELETE FROM `disables` WHERE `entry` IN (10543, 10544, 10545, 10548, 10547, 10546) AND `sourceType` = 4;

DELETE FROM `spell_script_names` WHERE `spell_id` IN (62807, 62821, 63711);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(62807, 'TW_spell_starlight'),
(62821, 'TW_spell_toasty_fire'),
(63711, 'TW_spell_storm_power');

-- Implement Can't do it while stunned
DELETE FROM `achievement_criteria_data` WHERE `type` = '18' AND `criteria_id` IN (10424, 10422);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
('10424', '18', 0, 0, ''),
('10422', '18', 0, 0, '');

DELETE FROM `disables` WHERE `entry` IN (10424, 10422) AND `sourceType` = 4;

-- Implement If looks could kill
UPDATE `creature_template` SET `ScriptName`='TW_npc_focused_eyebeam' WHERE `entry` IN (33632, 33802);

DELETE FROM `spell_script_names` WHERE `spell_id` IN (63346, 63976);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(63346, 'TW_spell_kologarn_focused_eyebeam_damage'),
(63976, 'TW_spell_kologarn_focused_eyebeam_damage');

DELETE FROM `achievement_criteria_data` WHERE `type` = 11 AND `criteria_id` IN (10099,10286);
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `ScriptName`) VALUES 
(10099, 11, 'TW_achievement_if_looks_could_kill'),
(10286, 11, 'TW_achievement_if_looks_could_kill');

DELETE FROM `disables` WHERE `entry` IN (10099, 10286) AND `sourceType` = 4;

DELETE FROM `disables` WHERE `sourceType` = '4' AND `entry` IN
(10042, 10352,
10342, 10355,
10340, 10353,
10341, 10354,
10598, 10599,
10348, 10357,
10351, 10363,
10439, 10719,
10403, 10404,
10582, 10583,
10347, 10361,
10349, 10362,
10350, 10364
);
 
DELETE FROM `achievement_criteria_data` WHERE `type` = '11' AND `criteria_id` IN
(10042, 10352,
10342, 10355,
10340, 10353,
10341, 10354,
10598, 10599,
10348, 10357,
10351, 10363,
10439, 10719,
10403, 10404,
10582, 10583,
10347, 10361,
10349, 10362,
10350, 10364
);
 
DELETE FROM `achievement_criteria_data` WHERE `type` = '18' AND `criteria_id` IN
(10042, 10352,
10342, 10355,
10340, 10353,
10341, 10354,
10598, 10599,
10348, 10357,
10351, 10363,
10439, 10719,
10403, 10404,
10582, 10583,
10347, 10361,
10349, 10362,
10350, 10364
);
 
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`) VALUES
('10042', '18'),
('10352', '18'),
('10342', '18'),
('10355', '18'),
('10340', '18'),
('10353', '18'),
('10341', '18'),
('10354', '18'),
('10598', '18'),
('10599', '18'),
('10348', '18'),
('10357', '18'),
('10351', '18'),
('10363', '18'),
('10439', '18'),
('10719', '18'),
('10403', '18'),
('10404', '18'),
('10582', '18'),
('10583', '18'),
('10347', '18'),
('10361', '18'),
('10349', '18'),
('10362', '18'),
('10350', '18'),
('10364', '18');
