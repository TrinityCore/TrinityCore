-- Template Updates
-- Ascendant Council Controller
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `ScriptName`= 'boss_ascendant_council_controller' WHERE `entry`= 43691;
-- Feludius
UPDATE `creature_template` SET `difficulty_entry_1`= 49612, `difficulty_entry_2`= 49613, `difficulty_entry_3`= 49614, `ScriptName`= 'npc_feludius' WHERE `entry`= 43687;
UPDATE `creature_template` SET `flags_extra`= 0, `movementId`= 187, `BaseAttackTime`= 1500, `speed_walk`= 3.2, `speed_run`= 2, `unit_class`= 2, `minlevel`= 88, `maxlevel`= 88, `exp`= 3,`faction`= 16, `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 80297855, `unit_flags`= 64 WHERE `entry` IN (43687, 49612, 49613, 49614);
-- Ignacious
UPDATE `creature_template` SET `difficulty_entry_1`= 49615, `difficulty_entry_2`= 49616, `difficulty_entry_3`= 49617, `ScriptName`= 'npc_ignacious' WHERE `entry`= 43686;
UPDATE `creature_template` SET `flags_extra`= 0, `movementId`= 187, `BaseAttackTime`= 1500, `speed_walk`= 3.2, `speed_run`= 2, `unit_class`= 2, `minlevel`= 88, `maxlevel`= 88, `exp`= 3,`faction`= 16, `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 80297855 WHERE `entry` IN (43686, 49615, 49616, 49617);
-- Arion
UPDATE `creature_template` SET `difficulty_entry_1`= 49606, `difficulty_entry_2`= 49607, `difficulty_entry_3`= 49608, `ScriptName`= 'npc_arion' WHERE `entry`= 43688;
UPDATE `creature_template` SET `flags_extra`= 0, `movementId`= 187, `BaseAttackTime`= 1500, `speed_walk`= 3.2, `speed_run`= 2, `unit_class`= 2, `minlevel`= 88, `maxlevel`= 88, `exp`= 3,`faction`= 16, `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 80297855 WHERE `entry` IN (43688, 49606, 49607, 49608);
-- Terrastra
UPDATE `creature_template` SET `difficulty_entry_1`= 49609, `difficulty_entry_2`= 49610, `difficulty_entry_3`= 49611, `ScriptName`= 'npc_terrastra' WHERE `entry`= 43689;
UPDATE `creature_template` SET `flags_extra`= 0, `movementId`= 187, `BaseAttackTime`= 1500, `speed_walk`= 3.2, `speed_run`= 2, `unit_class`= 2, `minlevel`= 88, `maxlevel`= 88, `exp`= 3,`faction`= 16, `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (43689, 49609, 49610, 49611);
-- Elementium Monstrosity
UPDATE `creature_template` SET `difficulty_entry_1`= 49619, `difficulty_entry_2`= 49620, `difficulty_entry_3`= 49621, `ScriptName`= 'npc_elementium_monstrosity' WHERE `entry`= 43735;
UPDATE `creature_template` SET `flags_extra`= 0, `movementId`= 187, `BaseAttackTime`= 1500, `speed_walk`= 3.2, `speed_run`= 2, `unit_class`= 2, `minlevel`= 88, `maxlevel`= 88, `exp`= 3,`faction`= 16, `DamageModifier`= 60, `BaseVariance`= 0.5, `mechanic_immune_mask`= 617299839 WHERE `entry` IN (43735, 49619, 49620, 49621);
-- Ascendant Council Target Stalker
UPDATE `creature_template` SET `flags_extra`= 128 WHERE `entry`= 44553;
-- Water Bomb
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 44201;
-- Inferno Rush
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 47501;
-- Violent Cyclone
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `ScriptName`= 'npc_ascendant_council_violent_cyclone' WHERE `entry`= 44747;
-- Gravity Well
UPDATE `creature_template` SET `unit_flags`= 33554432, `unit_flags2`= 2099200, `flags_extra`= 128, `ScriptName`= 'npc_ascendant_council_gravity_well' WHERE `entry`= 44824;
-- Eruption Target
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `ScriptName`= 'npc_ascendant_council_eruption_target' WHERE `entry`= 44845;
-- Ascendant Council Plume Stalker
UPDATE `creature_template` SET `ScriptName`= 'npc_ascendant_council_plume_stalker' WHERE `entry`= 45420;
-- Liquid Ice
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128 WHERE `entry`= 45452;
-- Gravity Crush
UPDATE `creature_template` SET `unit_flags`= 34079232, `flags_extra`= 128, `VehicleId`= 1110, `InhabitType`= 4, `ScriptName`= 'npc_ascendant_council_gravity_crush' WHERE `entry`= 45476;
-- Frozen Orb Spawner
UPDATE `creature_template` SET `unit_flags`= 33554688, `flags_extra`= 128 WHERE `entry`= 49517;
-- Frozen Orb
UPDATE `creature_template` SET `unit_flags`= 34080768, `speed_run`= 0.714, `ScriptName`= 'npc_ascendant_council_frozen_orb'  WHERE `entry`= 49518;
-- Flame Strike
UPDATE `creature_template` SET `unit_flags`= 33554432, `flags_extra`= 128, `ScriptName`= 'npc_ascendant_council_flame_strike' WHERE `entry`= 49432;

-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_feludius_water_bomb_targeting',
'spell_feludius_water_bomb',
'spell_feludius_glaciate',
'spell_feludius_fire_proc_check',
'spell_feludius_heart_of_ice',
'spell_feludius_frost_imbued',
'spell_feludius_frozen_orb_targeting',
'spell_ignacious_rising_flames',
'spell_ignacious_burning_blood',
'spell_ignacious_flame_imbued',
'spell_ignacious_inferno_rush',
'spell_ignacious_flame_strike',
'spell_arion_lashing_winds',
'spell_arion_thundershock',
'spell_arion_lightning_rod',
'spell_arion_chain_lightning_targeting',
'spell_arion_disperse',
'spell_arion_lightning_blast',
'spell_arion_static_overload',
'spell_arion_static_overload_triggered',
'spell_terrastra_gravity_well',
'spell_terrastra_harden_skin',
'spell_terrastra_quake',
'spell_terrastra_eruption',
'spell_terrastra_gravity_core',
'spell_terrastra_gravity_core_triggered',
'spell_elementium_monstrosity_lava_seed',
'spell_elementium_monstrosity_cryogenic_aura',
'spell_elementium_monstrosity_liquid_ice',
'spell_elementium_monstrosity_electric_instability',
'spell_elementium_monstrosity_gravity_crush');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
-- Feludius
(82697, 'spell_feludius_water_bomb_targeting'),
(82699, 'spell_feludius_water_bomb'),
(82746, 'spell_feludius_glaciate'),
(92506, 'spell_feludius_glaciate'),
(92507, 'spell_feludius_glaciate'),
(92508, 'spell_feludius_glaciate'),
(82772, 'spell_feludius_fire_proc_check'),
(92503, 'spell_feludius_fire_proc_check'),
(92504, 'spell_feludius_fire_proc_check'),
(92505, 'spell_feludius_fire_proc_check'),
(82762, 'spell_feludius_fire_proc_check'),
(82665, 'spell_feludius_heart_of_ice'),
(82666, 'spell_feludius_frost_imbued'),
(95883, 'spell_feludius_frozen_orb_targeting'),
-- Ignacious
(82636, 'spell_ignacious_rising_flames'),
(82660, 'spell_ignacious_burning_blood'),
(82663, 'spell_ignacious_flame_imbued'),
(82856, 'spell_ignacious_inferno_rush'),
(92520, 'spell_ignacious_inferno_rush'),
(92521, 'spell_ignacious_inferno_rush'),
(92522, 'spell_ignacious_inferno_rush'),
(92080, 'spell_ignacious_flame_strike'),
-- Arion
(83498, 'spell_arion_lashing_winds'),
(92476, 'spell_arion_lashing_winds'),
(92477, 'spell_arion_lashing_winds'),
(92478, 'spell_arion_lashing_winds'),
(83067, 'spell_arion_thundershock'),
(92469, 'spell_arion_thundershock'),
(92470, 'spell_arion_thundershock'),
(92471, 'spell_arion_thundershock'),
(83099, 'spell_arion_lightning_rod'),
(83300, 'spell_arion_chain_lightning_targeting'),
(83087, 'spell_arion_disperse'),
(83070, 'spell_arion_lightning_blast'),
(92454, 'spell_arion_lightning_blast'),
(92455, 'spell_arion_lightning_blast'),
(92456, 'spell_arion_lightning_blast'),
(92067, 'spell_arion_static_overload'),
(92068, 'spell_arion_static_overload_triggered'),
(92466, 'spell_arion_static_overload_triggered'),
(92467, 'spell_arion_static_overload_triggered'),
(92468, 'spell_arion_static_overload_triggered'),
-- Terrastra
(83578, 'spell_terrastra_gravity_well'),
(83718, 'spell_terrastra_harden_skin'),
(92541, 'spell_terrastra_harden_skin'),
(92542, 'spell_terrastra_harden_skin'),
(92543, 'spell_terrastra_harden_skin'),
(83565, 'spell_terrastra_quake'),
(92544, 'spell_terrastra_quake'),
(92545, 'spell_terrastra_quake'),
(92546, 'spell_terrastra_quake'),
(83675, 'spell_terrastra_eruption'),
(92075, 'spell_terrastra_gravity_core'),
(92076, 'spell_terrastra_gravity_core_triggered'),
(92537, 'spell_terrastra_gravity_core_triggered'),
(92538, 'spell_terrastra_gravity_core_triggered'),
(92539, 'spell_terrastra_gravity_core_triggered'),
-- Elementium Monstrosity
(84913, 'spell_elementium_monstrosity_lava_seed'),
(84918, 'spell_elementium_monstrosity_cryogenic_aura'),
(84914, 'spell_elementium_monstrosity_liquid_ice'),
(84527, 'spell_elementium_monstrosity_electric_instability'),
(84948, 'spell_elementium_monstrosity_gravity_crush'),
(92486, 'spell_elementium_monstrosity_gravity_crush'),
(92487, 'spell_elementium_monstrosity_gravity_crush'),
(92488, 'spell_elementium_monstrosity_gravity_crush');

DELETE FROM `conditions` WHERE `SourceEntry` IN (82699, 83475, 83087, 82344, 84913, 84915, 92497, 92498, 92499, 92214) AND `SourceTypeOrReferenceId`= 13;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ScriptName`, `Comment`) VALUES
(13, 1, 82699, 0, 0, 31, 0, 3, 44201, 0, 0, 0, '', 'Water Bomb - Target Water Bomb'),
(13, 1, 83475, 0, 0, 31, 0, 3, 44553, 0, 0, 0, '', 'Cyclone Aggro - Target Ascendant Council Target Stalker'),
(13, 1, 83087, 0, 0, 31, 0, 3, 44553, 0, 0, 0, '', 'Disperse - Target Ascendant Council Target Stalker'),
(13, 1, 82344, 0, 0, 31, 0, 3, 43687, 0, 0, 0, '', 'Merge Health - Target Feludius'),
(13, 1, 82344, 0, 1, 31, 0, 3, 43686, 0, 0, 0, '', 'Merge Health - Target Ignacious'),
(13, 1, 82344, 0, 2, 31, 0, 3, 43688, 0, 0, 0, '', 'Merge Health - Target Arion'),
(13, 1, 82344, 0, 3, 31, 0, 3, 43689, 0, 0, 0, '', 'Merge Health - Target Terrastra'),
(13, 1, 84913, 0, 0, 31, 0, 3, 45420, 0, 0, 0, '', 'Lava Seed - Target Ascendant Council Plume Stalker'),
(13, 2, 84915, 0, 0, 31, 0, 3, 43735, 0, 0, 0, '', 'Liquid Ice - Target Elementium Monstrosity'),
(13, 2, 92497, 0, 0, 31, 0, 3, 43735, 0, 0, 0, '', 'Liquid Ice - Target Elementium Monstrosity'),
(13, 2, 92498, 0, 0, 31, 0, 3, 43735, 0, 0, 0, '', 'Liquid Ice - Target Elementium Monstrosity'),
(13, 2, 92499, 0, 0, 31, 0, 3, 43735, 0, 0, 0, '', 'Liquid Ice - Target Elementium Monstrosity'),
(13, 2, 92214, 0, 0, 31, 0, 3, 49518, 0, 0, 0, '', 'Flame Strike - Target Frozen Orb');

-- Texts
DELETE FROM `creature_text` WHERE `CreatureId` IN (43687, 43686, 43688, 43689, 43691, 43735, 49518);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
-- Feludius
(43687, 0, 0, 'You dare invade our lord''s sanctum?', 14, 0, 100, 0, 0, 20162, 47725, 'Feludius - Engage'),
(43687, 1, 0, 'I will freeze the blood in your veins!', 14, 0, 100, 0, 0, 20164, 47671, 'Feludius - Say Glaciate'),
(43687, 2, 0, '%s begins to cast Glaciate!', 41, 0, 100, 0, 0, 0, 47672, 'Feludius - Announce Glaciate'),
(43687, 3, 0, 'Perish!', 14, 0, 100, 0, 0, 20163, 47717, 'Feludius - Slay'),
(43687, 4, 0, 'But now, witness true power...', 14, 0, 100, 0, 0, 20165, 44322, 'Feludius - Merge'),
-- Ignacious
(43686, 0, 0, 'You will die for your insolence!', 14, 0, 100, 0, 0, 20285, 47724, 'Ignacious - Engage'),
(43686, 1, 0, 'BURN!', 14, 0, 100, 0, 0, 20287, 47715, 'Ignacious - Say Aegis of Flame'),
(43686, 2, 0, '%s begins to cast Rising Flames!', 41, 0, 100, 0, 0, 0, 49844, 'Ignacious - Announce Rising Flames'),
(43686, 3, 0, 'More fuel for the fire!', 14, 0, 100, 0, 0, 20286, 47716, 'Ignacious - Slay'),
(43686, 4, 0, '...the fury of the elements!', 14, 0, 100, 0, 0, 20288, 44323, 'Ignacious - Merge'),
-- Arion
(43688, 0, 0, 'Enough of this foolishness!', 14, 0, 100, 0, 0, 20237, 44307, 'Arion - Engage'),
(43688, 1, 0, 'Wind, hear my call!', 14, 0, 100, 0, 0, 20239, 47718, 'Arion - Call Winds'),
(43688, 2, 0, '%s begins to cast Thundershock!', 41, 0, 100, 0, 0, 0, 47719, 'Arion - Announce Thundershock'),
(43688, 3, 0, 'Merely a whisper in the wind....', 14, 0, 100, 0, 0, 20238, 47720, 'Arion - Slay'),
(43688, 4, 0, 'An impressive display...', 14, 0, 100, 0, 0, 20240, 44320, 'Arion - Merge'),
-- Terrastra
(43689, 0, 0, 'We will handle them!', 14, 0, 100, 0, 0, 21843, 44308, 'Terrastra - Engage'),
(43689, 1, 0, 'The earth will devour you!', 14, 0, 100, 0, 0, 21844, 47722, 'Terrastra - Say Quake'),
(43689, 2, 0, '%s begins to cast Quake!', 41, 0, 100, 0, 0, 21844, 47723, 'Terrastra - Say Anounce Quake'),
(43689, 3, 0, 'The soil welcomes your bones!', 14, 0, 100, 0, 0, 21842, 47721, 'Terrastra - Slay'),
(43689, 4, 0, '...to have made it this far.', 14, 0, 100, 0, 0, 21845, 44321, 'Terrastra - Merge'),
-- Ascendant Council Controller
(43691, 0, 0, 'The ground beneath you rumbles ominously....', 41, 0, 100, 0, 0, 0, 47728, 'Ascendant Council Controller - Warn Quake'),
(43691, 1, 0, 'The surrounding air crackles with energy....', 41, 0, 100, 0, 0, 0, 47727, 'Ascendant Council Controller - Warn Thunderstorm'),
-- Elementium Monstrosity
(43735, 0, 0, 'BEHOLD YOUR DOOM!', 14, 0, 100, 0, 0, 20396, 44336, 'Elementium Monstrosity - Merged'),
(43735, 1, 0, 'FEEL THE POWER!', 14, 0, 100, 0, 0, 20400, 47726, 'Elementium Monstrosity - Lava Seed'),
(43735, 2, 0, 'Impossible....', 14, 0, 100, 0, 0, 20399, 44339, 'Elementium Monstrosity - Death'),
(43735, 3, 0, 'Eradicate....', 14, 0, 100, 0, 0, 20398, 44337, 'Elementium Monstrosity - Slay 1'),
(43735, 3, 1, 'Annihilate....', 14, 0, 100, 0, 0, 20397, 44338, 'Elementium Monstrosity - Slay 2'),
-- Frozen Orb
(49518, 0, 0, '%s begins to pursue $n!', 41, 0, 100, 0, 0, 0, 49578, 'Frozen Orb - Pursue Player');

-- Addons
-- Remove auras from bosses
UPDATE `creature_template_addon` SET `auras`= '' WHERE `entry` IN (43686, 43689, 43688);
UPDATE `creature_addon` SET `auras`= '' WHERE `guid` IN (254144, 254133, 254134, 254148);

DELETE FROM `creature_template_addon` WHERE `entry` IN (44747, 45452, 49517, 49518);
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(44747, '83472'),
(45452, '84914'),
(49517, '92269'),
(49518, '92302');

-- Serverside spells
-- Difficulty spell entries
DELETE FROM `spell_dbc` WHERE `Id` IN (82675, 82697, 88578, 84916, 84947, 92080, 92081);
INSERT INTO `spell_dbc`(`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellInterruptsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `Comment`) VALUES
(82675, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Water Bomb'),
(82697, 0, 0, 0, 256, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Water Bomb'),
(88578, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 22, 152, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Inferno Rush'),
(84916, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Liquid Ice'),
(84947, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 589, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Gravity Crush'),
(92080, 0, 0, 4, 256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Flame Strike'),
(92081, 0, 0, 4, 256, 0, 0, 0, 0, 0, 0, 0, 0, 21, 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, '(Serverside/Non-DB2) Flame Strike');

DELETE FROM `spelleffect_dbc` WHERE `Id` IN (160084, 160085, 160086, 160087, 160088, 160089, 160090);
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectBasePoints`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`, `Comment`) VALUES
(160084, 28, 1, 44201, 64, 8, 8, 53, 91, 82675, 0, 'Water Bomb - Summon'),
(160085, 3, 82675, 0, 0 , 12, 12, 22, 15, 82697, 0, 'Water Bomb - Dummy'),
(160086, 28, 1, 47501, 64, 0, 0, 87, 87, 88578, 0, 'Inferno Rush - Summon'),
(160087, 28, 1, 45452, 64, 0, 0, 18, 0, 84916, 0, 'Liquid Ice - Summon'),
(160088, 28, 1, 45476, 64, 0, 0, 18, 0, 84947, 0, 'Gravity Crush - Summon'),
(160089, 3, 92081, 0, 0 , 30, 30, 22, 15, 92080, 0, 'Flame Strike - Dummy'),
(160090, 28, 1, 49432, 64, 0, 0, 53, 0, 92081, 0, 'Flame Strike - Summon');

DELETE FROM `spell_target_position` WHERE `ID` IN (82329, 82330, 82331, 82332);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`) VALUES
(82329, 0, 671, -1029.45, -603.773, 831.901),
(82330, 0, 671, -987.599, -561.885, 831.901),
(82331, 0, 671, -1029.41, -561.885, 831.901),
(82332, 0, 671, -987.599, -603.773, 831.901);

-- Achievement
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 15471;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15471, 11, 0, 0, 'achievement_elementary');

-- Delete Elementium Monstrosity
DELETE FROM `creature` WHERE `guid`= 254260;
DELETE FROM `creature_addon` WHERE `guid`= 254260;

-- Loot
DELETE FROM `creature_loot_template` WHERE `entry` IN (43735, 49619, 49620, 49621);
UPDATE `creature_template` SET `lootid`= `entry` WHERE `entry` IN (43735, 49619, 49620, 49621);
DELETE FROM `reference_loot_template` WHERE `Entry` IN (437350, 437351);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`) VALUES
-- Normal Mode
(437350, 59513, 0, 1, 1, 1, 1), -- Scepter of Ice
(437350, 59504, 0, 1, 1, 1, 1), -- Arion's Crown
(437350, 59509, 0, 1, 1, 1, 1), -- Glaciated Helm
(437350, 59510, 0, 1, 1, 1, 1), -- Feludius' Mantle
(437350, 59507, 0, 1, 1, 1, 1), -- Glittering Epidermis
(437350, 59505, 0, 1, 1, 1, 1), -- Gravitational Pull
(437350, 59511, 0, 1, 1, 1, 1), -- Hydrolance Gloves
(437350, 59502, 0, 1, 1, 1, 1), -- Dispersing Belt
(437350, 59503, 0, 1, 1, 1, 1), -- Terrastra's Legguards
(437350, 59508, 0, 1, 1, 1, 1), -- Treads of Liquid Ice
(437350, 59506, 0, 1, 1, 1, 1), -- Crushing Weight
(437350, 59514, 0, 1, 1, 1, 1), -- Heart of Ignacious
-- Heroic Mode
(437351, 65111, 0, 1, 1, 1, 1), -- Scepter of Ice
(437351, 65120, 0, 1, 1, 1, 1), -- Arion's Crown
(437351, 65115, 0, 1, 1, 1, 1), -- Glaciated Helm
(437351, 65114, 0, 1, 1, 1, 1), -- Feludius' Mantle
(437351, 65117, 0, 1, 1, 1, 1), -- Glittering Epidermis
(437351, 65119, 0, 1, 1, 1, 1), -- Gravitational Pull
(437351, 65113, 0, 1, 1, 1, 1), -- Hydrolance Gloves
(437351, 65122, 0, 1, 1, 1, 1), -- Dispersing Belt
(437351, 65121, 0, 1, 1, 1, 1), -- Terrastra's Legguards
(437351, 65116, 0, 1, 1, 1, 1), -- Treads of Liquid Ice
(437351, 65118, 0, 1, 1, 1, 1), -- Crushing Weight
(437351, 65110, 0, 1, 1, 1, 1); -- Heart of Ignacious

INSERT INTO `creature_loot_template` (`Entry`, `Item`, `Chance`, `LootMode`, `Reference`, `MaxCount`) VALUES
-- 10 Player Normal
(43735, 437350, 100, 1, 437350, 2),
-- 25 Player Normal
(49619, 437350, 100, 1, 437350, 6),
-- 10 Player Heroic
(49620, 437351, 100, 1, 437351, 2),
-- 25 Player Heroic
(49621, 437351, 100, 1, 437351, 6);

-- Gold Loot
-- 10 Player
UPDATE `creature_template` SET `mingold`= 2200000, `maxgold`= 2400000 WHERE `entry` IN (43735, 49620);
-- 25 Player
UPDATE `creature_template` SET `mingold`= 4900000, `maxgold`= 5100000 WHERE `entry` IN (49619, 49621);

-- Currency Loot
DELETE FROM `creature_onkill_reward` WHERE `creature_id` IN (43735, 49619, 49620, 49621);
INSERT INTO `creature_onkill_reward` (`creature_id`, `CurrencyId1`, `CurrencyCount1`) VALUES
(43735, 396, 11500),
(49619, 396, 13500),
(49620, 396, 11500),
(49621, 396, 13500);
