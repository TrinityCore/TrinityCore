-- Halls of Origination work
SET @SpellEffectID := 1000000; -- 12 entries needed (1000000 - 1000011)

-- Spells, Spell Effects --
-- server-side spell Summon Quicksand
DELETE FROM `spell_dbc` WHERE `Id` = 75550;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `SpellInterruptsId`, `Comment`) VALUES
(75550, 128, 0, 4, 262144, 128, 8, 0, 0, 0, 0, 0, 1, 18, 6, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Summon Quicksand');

-- TO-DO: Recheck types!
DELETE FROM `spelleffect_dbc` WHERE `Id` BETWEEN @SpellEffectID+0 AND @SpellEffectID+11;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectValueMultiplier`, `EffectApplyAuraName`, `EffectAmplitude`, `EffectBasePoints`, `EffectBonusMultiplier`, `EffectDamageMultiplier`, `EffectChainTarget`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectRealPointsPerLevel`, `EffectSpellClassMaskA`, `EffectSpellClassMaskB`, `EffectSpellClassMaskC`, `EffectTriggerSpell`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`) VALUES
(@SpellEffectID+0,  28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40503, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 75550, 0), -- Summon Quicksand
(@SpellEffectID+1,  77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     0,  0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 75621, 0), -- Script Effect: Summon Seedling Pod 40550 (normal) or 51329 (heroic)
(@SpellEffectID+2,  77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40592, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 75688, 0), -- Summon Seedling Pod 
(@SpellEffectID+3,  28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40585, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 75695, 0), -- Summon Spore
(@SpellEffectID+4,  28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40622, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 75769, 0), -- Summon Bloodpetal Blossom Visual
(@SpellEffectID+5,  28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40620, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 75771, 0), -- Bloodpetal Blossom
(@SpellEffectID+6,  28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40630, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 75791, 0), -- Summon Bloodpetal Sprout
(@SpellEffectID+7,   3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,     0,  0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 76737, 0), -- Chaos Blast Me (dummy)
(@SpellEffectID+8,  28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41212, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 77272, 0), -- Summon Void Wyrm 1
(@SpellEffectID+9,  28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41212, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 79439, 0), -- Summon Void Wyrm 2
(@SpellEffectID+10, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41148, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 77271, 0), -- Summon Void Seeker
(@SpellEffectID+11, 28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 41208, 64, 0, 0, 0, 0, 0, 0, 0, 18, 0, 77242, 0); -- Summon Void Sentinel

-- General: Elevator, trash mobs --
-- script names, sniff corrections
UPDATE `gameobject_template` SET `ScriptName` = 'go_hoo_the_makers_lift_controller' WHERE `entry` = 207669;

UPDATE `creature_template` SET `ScriptName` = 'npc_hoo_aggro_stalker' WHERE `entry` = 40790;
UPDATE `creature_template` SET `ScriptName` = 'npc_hoo_spatial_flux', `unit_flags` = 33554496 WHERE `entry` IN (39612, 48707);
UPDATE `creature_template` SET `ScriptName` = 'npc_hoo_energy_flux', `unit_flags` = 33554496, `speed_walk` = 5.5/2.5, `speed_run` = 5.5/2.5 WHERE `entry` IN (44015, 48709);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hoo_emerge', 'spell_hoo_energy_flux_target_selector', 'spell_hoo_arcane_energy_check', 'spell_hoo_fixate');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75764, 'spell_hoo_emerge'),
(82382, 'spell_hoo_energy_flux_target_selector'),
(74880, 'spell_hoo_arcane_energy_check'),
(73686, 'spell_hoo_fixate');

-- criteria script
DELETE FROM `criteria_data` WHERE `criteria_id` IN (15989);
INSERT INTO `criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(15989, 11, 0, 0, 'achievement_straw_broke_camels_back');

-- transit device that teleports to the upper floor
UPDATE `gameobject_template` SET `Data10` = 82900 WHERE `entry` = 204972;
DELETE FROM `spell_target_position` WHERE `ID` = 82900;
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(82900, 0, 644, -477.742, 193.255, 330.658, -1);

-- gameobject rotation of lightmachines, glass star 2
UPDATE `gameobject` SET `rotation0` = -0.150109,  `rotation1` = -0.150108, `rotation2` = -0.690989,  `rotation3` = 0.690991 WHERE `guid` IN (220756, 220763);
UPDATE `gameobject` SET `rotation0` =  0.150109,  `rotation1` = -0.150108, `rotation2` =  0.690989,  `rotation3` = 0.690991 WHERE `guid` IN (220757, 220764);
UPDATE `gameobject` SET `rotation0` =  0.7071066, `rotation1` =  0,        `rotation2` = -0.7071066, `rotation3` = 0        WHERE `guid` = 220755;

-- set correct spawnMask to Beacons - normal (4) and heroic (2)
UPDATE `gameobject` SET `spawnMask` = 4 WHERE `guid` IN (200968, 200969);
UPDATE `gameobject` SET `spawnMask` = 2 WHERE `guid` IN (220773, 220775); 

-- emote for Dustbone Horror
DELETE FROM `creature_text` WHERE `CreatureID` = 40808 AND `GroupID` = 0;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(40808, 0, 0, '%s buries itself in the sand!', 16, 0, 100, 0, 0, 0, 42474, 0, 'Dustbone Horror - submerge'); 

-- inhabitType 12 (root + disable gravity): Rune of Healing, Cave In Stalker, Dust Cloud Stalker, Searing Light, Spatial Flux, Isiset's Spatial Flux, 
--   Budding Spore, Aqua Bomb, Alpha Beam, Omega Stance, Aggro Stalker, Beetle Stalker, Quick Sand, Living Vine, Chaos Portal, Void Rift, Chaos Blast, 
--   Add Stalker, Starry Sky, Ammunae's Seedling Pod, Seedling Pod, Bloodpetal Blossom, Seedling Pod
UPDATE `creature_template` SET `InhabitType` = 12 WHERE `entry` IN (39258, 39612, 40202, 40283, 40183, 48707, 40669, 
41264, 41144, 41194, 40790, 40459, 40503, 40668, 41055, 39266, 41041, 41479, 39681, 40592, 40716, 40622, 40550); 

-- camels do not respawn if they die
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `map` = 644 AND `id` = 39443;

-- Boss: Temple Guardian Anhuur --
-- heroic entry
UPDATE `creature_template` SET `difficulty_entry_1` = 49262 WHERE `entry` = 39425;

-- Pit Viper snakes respawn in 36 seconds.
UPDATE `creature` SET `spawntimesecs` = 36 WHERE `map` = 644 AND `id` = 39444;

-- broadcast text ids for Anhuur
UPDATE `creature_text` SET `BroadcastTextId` = 40968 WHERE `CreatureID` = 39425 AND `GroupID` = 2;
UPDATE `creature_text` SET `BroadcastTextId` = 50665 WHERE `CreatureID` = 39425 AND `GroupID` = 3;

-- script names ("spell_anhuur_activate_beacons" rewritten into "spell_anhuur_handle_beacons")
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_anhuur_reverberating_hymn', 'spell_anhuur_activate_beacons', 'spell_anhuur_handle_beacons');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75322, 'spell_anhuur_reverberating_hymn'),
(76599, 'spell_anhuur_handle_beacons'),
(76600, 'spell_anhuur_handle_beacons');

-- spell condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (76599, 76600);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 76599, 0, 0, 31, 0, 5, 207218, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76599, 0, 1, 31, 0, 5, 207219, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76599, 0, 2, 31, 0, 5, 203133, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76599, 0, 3, 31, 0, 5, 203136, 0, 0, 0, 0, '', 'Activate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 0, 31, 0, 5, 207218, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 1, 31, 0, 5, 207219, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 2, 31, 0, 5, 203133, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light'),
(13, 1, 76600, 0, 3, 31, 0, 5, 203136, 0, 0, 0, 0, '', 'Deactivate Beacons targets Beacon of Light');

-- Boss: Earthrager Ptah
UPDATE `creature_template` SET `ScriptName` = 'npc_ptah_beetle_stalker' WHERE `entry` = 40459;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_earthrager_ptah_sandstorm');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75491, 'spell_earthrager_ptah_sandstorm');

-- text
DELETE FROM `creature_text` WHERE `CreatureID` = 39428;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39428, 0, 0, 'Ptah... is... no more...',       14, 0, 100, 0, 0, 18905, 44780, 0, 'Earthrager Ptah - SAY_DEATH'),
(39428, 1, 0, 'More carrion for the swarm...',  14, 0, 100, 0, 0, 18906, 44778, 0, 'Earthrager Ptah - SAY_AGGRO'),
(39428, 2, 0, 'Dust to dust.',                  14, 0, 100, 0, 0, 18907, 44779, 0, 'Earthrager Ptah - SAY_PLAYER_KILL'),
(39428, 3, 0, 'The earth TREMBLES!',            14, 0, 100, 0, 0, 18908, 44781, 0, 'Earthrager Ptah - SAY_SPECIAL');

-- Boss: Anraphet --
-- respawn time of wardens set to one day
UPDATE `creature` SET `spawntimesecs` = 86400 WHERE `map` = 644 AND `id` in (39800, 39801, 39802, 39803);

-- spell positions for wardens
DELETE FROM `spell_target_position` WHERE `ID` IN (82329, 82330, 82331, 82332);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(82329, 0, 644, -329.727, 481.142, 89.2101, -1), -- SW 
(82330, 0, 644, -329.962, 246.302, 89.2102, -1), -- SE
(82331, 0, 644, -223.26,  488.222, 89.2101, -1), -- NW
(82332, 0, 644, -223.049, 243.161, 89.2102, -1); -- NE

-- Water Warden gets Aqua Bomb aura on aggro.
DELETE FROM `creature_template_addon` WHERE `entry` = 39802;

-- Flame Warden spell script for Lava Eruption dummy
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hoo_platform_teleport', 'spell_flame_warden_lava_eruption', 'spell_whirling_winds_movement', 'spell_anraphet_destruction_protocol');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82329, 'spell_hoo_platform_teleport'),
(82330, 'spell_hoo_platform_teleport'),
(82331, 'spell_hoo_platform_teleport'),
(82332, 'spell_hoo_platform_teleport'),
(77273, 'spell_flame_warden_lava_eruption'),
(77333, 'spell_whirling_winds_movement'),
(77437, 'spell_anraphet_destruction_protocol');

-- Vault of Lights achievement check spell not in dbc
DELETE FROM `spell_dbc` WHERE `Id` = 94067;
INSERT INTO `spell_dbc` (`Id`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `CastingTimeIndex`, `DurationIndex`, `RangeIndex`, `SchoolMask`, `SpellAuraOptionsId`, `SpellCastingRequirementsId`, `SpellCategoriesId`, `SpellClassOptionsId`, `SpellEquippedItemsId`, `SpellLevelsId`, `SpellTargetRestrictionsId`, `SpellInterruptsId`, `Comment`) VALUES
(94067, 384, 0, 5, 256, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Vault of Lights achievement credit');

DELETE FROM `spelleffect_dbc` WHERE `Id` = @SpellEffectID+1;
INSERT INTO `spelleffect_dbc` (`Id`, `Effect`, `EffectValueMultiplier`, `EffectApplyAuraName`, `EffectAmplitude`, `EffectBasePoints`, `EffectBonusMultiplier`, `EffectDamageMultiplier`, `EffectChainTarget`, `EffectDieSides`, `EffectItemType`, `EffectMechanic`, `EffectMiscValue`, `EffectMiscValueB`, `EffectRadiusIndex`, `EffectRadiusIndexMax`, `EffectRealPointsPerLevel`, `EffectSpellClassMaskA`, `EffectSpellClassMaskB`, `EffectSpellClassMaskC`, `EffectTriggerSpell`, `EffectImplicitTargetA`, `EffectImplicitTargetB`, `EffectSpellId`, `EffectIndex`) VALUES
(@SpellEffectID+1, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 94067, 0);

-- area trigger for Brann's emote
DELETE FROM `areatrigger_scripts` WHERE `entry` = 5811;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(5811, 'at_hoo_brann_idle_emote');

-- speed corrections for Brann
UPDATE `creature_template` SET `speed_walk` = 2.5/2.5, `speed_run` = 7/2.5 WHERE `entry` = 39908;

-- delete menu condition (that is not even working)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 14 AND `SourceGroup` = 12512 AND `SourceEntry` = 17600;

-- broadcast text ids for Brann
UPDATE `creature_text` SET `BroadcastTextId` = 40231 WHERE `CreatureID` = 39908 AND `GroupID` = 0;
UPDATE `creature_text` SET `BroadcastTextId` = 40232 WHERE `CreatureID` = 39908 AND `GroupID` = 1;
UPDATE `creature_text` SET `BroadcastTextId` = 40233 WHERE `CreatureID` = 39908 AND `GroupID` = 2;
UPDATE `creature_text` SET `BroadcastTextId` = 40234 WHERE `CreatureID` = 39908 AND `GroupID` = 3;
UPDATE `creature_text` SET `BroadcastTextId` = 40240 WHERE `CreatureID` = 39908 AND `GroupID` = 4;
UPDATE `creature_text` SET `BroadcastTextId` = 40235 WHERE `CreatureID` = 39908 AND `GroupID` = 5;
UPDATE `creature_text` SET `BroadcastTextId` = 40236 WHERE `CreatureID` = 39908 AND `GroupID` = 6;
UPDATE `creature_text` SET `BroadcastTextId` = 40270 WHERE `CreatureID` = 39908 AND `GroupID` = 7;
UPDATE `creature_text` SET `BroadcastTextId` = 40271 WHERE `CreatureID` = 39908 AND `GroupID` = 8;
UPDATE `creature_text` SET `BroadcastTextId` = 40272 WHERE `CreatureID` = 39908 AND `GroupID` = 9;
UPDATE `creature_text` SET `BroadcastTextId` = 40273 WHERE `CreatureID` = 39908 AND `GroupID` = 10;
UPDATE `creature_text` SET `BroadcastTextId` = 49687 WHERE `CreatureID` = 39908 AND `GroupID` = 11;
UPDATE `creature_text` SET `BroadcastTextId` = 49688 WHERE `CreatureID` = 39908 AND `GroupID` = 12;

-- idle text lines of Brann
DELETE FROM `creature_text` WHERE `CreatureID` = 39908 AND `GroupID` IN (13, 14);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39908, 13, 0, 'Blasted titans... Why do they use a different set of mechanisms at each of their installations?', 12, 0, 100, 432, 0, 0, 39940, 0, 'Brann Bronzebeard - idle'),
(39908, 14, 0, 'This symbol, I think I''ve seen this before...', 12, 0, 100, 432, 0, 0, 40104, 0, 'Brann Bronzebeard - idle'); 

-- delayed emotes not implemented :(
-- UPDATE `creature_text` SET `EmoteID1` = 432, `EmoteDelay1` = 4000 WHERE `CreatureID` = 39908 AND `GroupID` = 0;
-- UPDATE `creature_text` SET `EmoteID1` = 1, `EmoteDelay1` = 3500 WHERE `CreatureID` = 39908 AND `GroupID` = 2;
-- UPDATE `creature_text` SET `EmoteID1` = 5, `EmoteDelay1` = 9500 WHERE `CreatureID` = 39908 AND `GroupID` = 2;
-- UPDATE `creature_text` SET `EmoteID1` = 25, `EmoteDelay1` = 12000 WHERE `CreatureID` = 39908 AND `GroupID` = 6;

-- missing npc text of Brann
DELETE FROM `npc_text` WHERE `ID` IN (15794);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextID0`, `BroadcastTextID1`, `BroadcastTextID2`, `BroadcastTextID3`, `BroadcastTextID4`, `BroadcastTextID5`, `BroadcastTextID6`, `BroadcastTextID7`, `VerifiedBuild`) VALUES
(15794, 1, 0, 0, 0, 0, 0, 0, 0, 40129, 0, 0, 0, 0, 0, 0, 0, -1);

-- gossip menus of Brann
DELETE FROM `gossip_menu` WHERE (`MenuID` = 11339 AND `TextID` = 15794) OR (`MenuID` = 11348 AND `TextID` = 15815) OR (`MenuID` = 12512 AND `TextID` = 17600);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(11339, 15794, 0),
(11348, 15815, 0),
(12512, 17600, 0);

-- Boss: Isiset --
-- script names, sniff corrections
UPDATE `creature_template` SET `ScriptName` = 'boss_isiset', `difficulty_entry_1` = 48710 WHERE `entry` = 39587;
UPDATE `creature_template` SET `ScriptName` = 'npc_celestial_familiar' WHERE `entry` = 39795;
UPDATE `creature_template` SET `ScriptName` = '', `unit_flags` = 33554752 WHERE `entry` = 39787;
UPDATE `creature_template` SET `ScriptName` = '', `unit_flags` = 33554752 WHERE `entry` = 39681;
UPDATE `creature_template` SET `ScriptName` = 'npc_isiset_mirror_image' WHERE `entry` IN (39720, 39721, 39722);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_isiset_veil_of_sky', 'spell_isiset_supernova_filter', 'spell_isiset_mirror_image_starry_sky_spawner', 'spell_isiset_mirror_image_spawner', 'spell_isiset_image_explosion', 'spell_isiset_astral_rain_controller', 'spell_isiset_mana_shield_controller', 'spell_isiset_astral_familiar_controller', 'spell_isiset_call_of_sky', 'spell_isiset_energy_flux_target_selector');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74133, 'spell_isiset_veil_of_sky'),
(74372, 'spell_isiset_veil_of_sky'),
(74373, 'spell_isiset_veil_of_sky'),
(74137, 'spell_isiset_supernova_filter'),
(76670, 'spell_isiset_supernova_filter'),
(69941, 'spell_isiset_mirror_image_starry_sky_spawner'),
(74264, 'spell_isiset_mirror_image_spawner'),
(74301, 'spell_isiset_image_explosion'),
(74381, 'spell_isiset_astral_rain_controller'),
(74382, 'spell_isiset_mana_shield_controller'),
(74383, 'spell_isiset_astral_familiar_controller'),
(90755, 'spell_isiset_call_of_sky'),
(90735, 'spell_isiset_energy_flux_target_selector');

-- spell target position for Call of Sky (90750)
DELETE FROM `spell_target_position` WHERE `ID` IN (90750);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(90750, 0, 644, -490.5087, 415.5035, 344.0261, 0);

-- spell condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (82377, 90741, 74043);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 82377, 0, 0, 31, 0, 3, 39612, 0, 0, 0, 0, '', 'Energy Flux Spawn Trigger targets NPC_SPATIAL_FLUX_TRASH'),
(13, 1, 90741, 0, 0, 31, 0, 3, 48707, 0, 0, 0, 0, '', 'Energy Flux Spawn Trigger targets NPC_SPATIAL_FLUX_ISISET'),
(13, 1, 74043, 0, 0, 31, 0, 3, 44015, 0, 0, 0, 0, '', 'Energy Flux Visual targets NPC_ENERGY_FLUX_TRASH'),
(13, 1, 74043, 0, 1, 31, 0, 3, 48709, 0, 0, 0, 0, '', 'Energy Flux Visual targets NPC_ENERGY_FLUX_ISISET');

-- text
DELETE FROM `creature_text` WHERE `CreatureID` IN (39587);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39587, 0, 0, 'Gaze to the heavens! What do you see?', 14, 0, 100, 0, 0, 18843, 0, 0, 'Isiset - aggro'),
(39587, 1, 0, 'Bask in my radiance!', 14, 0, 100, 0, 0, 18845, 0, 0, 'Isiset - cast Supernova'),
(39587, 2, 0, '%s begins to channel a Supernova. Look away!', 41, 0, 100, 0, 0, 0, 0, 0, 'Isiset - cast Supernova'),
(39587, 3, 0, 'Insignificant!', 14, 0, 100, 0, 0, 18847, 0, 0, 'Isiset - player death'),
(39587, 3, 1, 'The glimmer of your life, extinguished.', 14, 0, 100, 0, 0, 18846, 0, 0, 'Isiset - player death'),
(39587, 4, 0, 'Eons of darkness... by your hand.', 14, 0, 100, 0, 0, 18842, 0, 0, 'Isiset - death'),
(39587, 4, 1, 'My luster... wanes.', 14, 0, 100, 0, 0, 18844, 0, 0, 'Isiset - death');

-- loot
DELETE FROM `reference_loot_template` WHERE `Entry` IN (39587, 48710);
INSERT INTO `reference_loot_template` (`Entry`, `Item`, `Reference`, `Chance`, `QuestRequired`, `LootMode`, `GroupId`, `MinCount`, `MaxCount`, `Comment`) VALUES
(39587, 55992, 0, 0, 0, 1, 1, 1, 1, NULL),
(39587, 55993, 0, 0, 0, 1, 1, 1, 1, NULL),
(39587, 55994, 0, 0, 0, 1, 1, 1, 1, NULL),
(39587, 55995, 0, 0, 0, 1, 1, 1, 1, NULL),
(39587, 55996, 0, 0, 0, 1, 1, 1, 1, NULL),
(48710, 56412, 0, 0, 0, 1, 1, 1, 1, NULL),
(48710, 56413, 0, 0, 0, 1, 1, 1, 1, NULL),
(48710, 56414, 0, 0, 0, 1, 1, 1, 1, NULL),
(48710, 56415, 0, 0, 0, 1, 1, 1, 1, NULL),
(48710, 56416, 0, 0, 0, 1, 1, 1, 1, NULL);

-- Boss: Ammunae --
-- script names
UPDATE `creature_template` SET `ScriptName` = 'boss_ammunae', `difficulty_entry_1` = 48715 WHERE `entry` = 39731;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_ammunae_consume_life_energy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75725, 'spell_ammunae_consume_life_energy');

-- text
DELETE FROM `creature_text` WHERE `CreatureID` = 39731;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39731, 0, 0, 'The cycle continues...',                             14, 0, 100, 0, 0, 18569, 44770, 0, 'Ammunae - SAY_DEATH'),
(39731, 1, 0, 'This chamber will flourish with your life energy!',  14, 0, 100, 0, 0, 18671, 44767, 0, 'Ammunae - SAY_AGGRO'),
(39731, 2, 0, 'Your life, UNLEASHED!',                              14, 0, 100, 0, 0, 18572, 44771, 0, 'Ammunae - SAY_SPECIAL'),
(39731, 3, 0, 'Wither away!',                                       14, 0, 100, 0, 0, 18573, 44768, 0, 'Ammunae - SAY_PLAYER_KILL'),
(39731, 3, 1, 'Waste of energy.',                                   14, 0, 100, 0, 0, 18574, 44769, 0, 'Ammunae - SAY_PLAYER_KILL');

-- spell condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (75702, 89124);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 2, 75702, 0, 0, 31, 0, 3, 40620, 0, 0, 0, 0, '', 'Noxious Spores (EFFECT_1) targets Bloodpetal Blossom'),
(13, 2, 75702, 0, 0, 31, 0, 3, 40630, 0, 0, 0, 0, '', 'Noxious Spores (EFFECT_1) targets Bloodpetal Sprout'),
(13, 2, 75702, 0, 0, 31, 0, 3, 40550, 0, 0, 0, 0, '', 'Noxious Spores (EFFECT_1) targets Seedling Pod (n)'),
(13, 2, 75702, 0, 0, 31, 0, 3, 51329, 0, 0, 0, 0, '', 'Noxious Spores (EFFECT_1) targets Seedling Pod (h)'),   
(13, 2, 75702, 0, 0, 31, 0, 3, 40716, 0, 0, 0, 0, '', 'Noxious Spores (EFFECT_1) targets Seedling Pod (trash)'),
(13, 2, 75702, 0, 0, 31, 0, 3, 40668, 0, 0, 0, 0, '', 'Noxious Spores (EFFECT_1) targets Living Vine'),
(13, 2, 75702, 0, 0, 31, 0, 3, 40715, 0, 0, 0, 0, '', 'Noxious Spores (EFFECT_1) targets Lifewarden Nymph'),
(13, 1, 89124, 0, 0, 31, 0, 3, 39731, 0, 0, 0, 0, '', 'Energizing Growth (EFFECT_0) targets Ammunae');

-- Boss: Setesh <Construct of Destruction> --
-- script names
UPDATE `creature_template` SET `ScriptName` = 'boss_setesh', `difficulty_entry_1` = 48776 WHERE `entry` = 39732;
UPDATE `creature_template` SET `ScriptName` = 'npc_setesh_chaos_blast' WHERE `entry` = 41041;
UPDATE `creature_template` SET `ScriptName` = 'npc_setesh_chaos_seed' WHERE `entry` = 41126;
UPDATE `creature_template` SET `ScriptName` = 'npc_setesh_chaos_portal' WHERE `entry` = 41055;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_setesh_chaos_blast');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(74372, 'spell_setesh_chaos_blast');

-- text
DELETE FROM `creature_text` WHERE `CreatureID` = 39732;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39732, 0, 0, 'Yes! Harness... your... hatred.',                                        14, 0, 100, 0, 0, 18552, 44765, 0, 'Setesh - SAY_DEATH'),
(39732, 1, 0, 'You fear that which you cannot control. But can you control your fear?', 14, 0, 100, 0, 0, 18553, 44762, 0, 'Setesh - SAY_AGGRO'),
(39732, 2, 0, 'Behold as infinite darkness befalls your world!',                        14, 0, 100, 0, 0, 18554, 44766, 0, 'Setesh - SAY_SPECIAL'),
(39732, 3, 0, 'Embrace the end!',                                                       14, 0, 100, 0, 0, 18555, 44763, 0, 'Setesh - SAY_PLAYER_KILL'),
(39732, 3, 1, 'Do you understand now?',                                                 14, 0, 100, 0, 0, 18556, 44764, 0, 'Setesh - SAY_PLAYER_KILL');

-- Boss: Rajh --
-- script names
UPDATE `creature_template` SET `ScriptName` = 'boss_rajh', `difficulty_entry_1` = 48815 WHERE `entry` = 39378;

-- text
DELETE FROM `creature_text` WHERE `CreatureID` = 39378;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(39378, 0, 0, 'Blazing rays of light, take me!',                    14, 0, 100, 0, 0, 18910, 44760, 0, 'Rajh - SAY_DEATH'),
(39378, 1, 0, 'Defilers! Wretches! Fiends! Begone from here!',      14, 0, 100, 0, 0, 18911, 44757, 0, 'Rajh - SAY_AGGRO'),
(39378, 2, 0, 'Can you feel it? The blessed warmth of the sun?',    14, 0, 100, 0, 0, 18912, 44761, 0, 'Rajh - SAY_SPECIAL'),
(39378, 3, 0, 'I send you to your deity.',                          14, 0, 100, 0, 0, 18913, 44758, 0, 'Rajh - SAY_PLAYER_KILL'),
(39378, 3, 1, 'I take this life as an offering!',                   14, 0, 100, 0, 0, 18914, 44759, 0, 'Rajh - SAY_PLAYER_KILL');

-- To-do: Whole Rajh script ...

-- SmartAI, HC entries --
-- Temple Fireshaper SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49310 WHERE `entry` = 48143;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (48143,-322519) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48143, 0, 0, 0, 0, 0, 100, 0, 0, 0, 500, 500, '', 11, 89538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Temple Fireshaper - In Combat - Cast \'Fireball\''),
(48143, 0, 1, 0, 0, 0, 100, 0, 12000, 12000, 22000, 26000, '', 11, 84032, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Fireshaper - In Combat - Cast \'Meteor\''),
(48143, 0, 2, 0, 0, 0, 100, 0, 10000, 10000, 30000, 30000, '', 11, 89542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temple Fireshaper - In Combat - Cast \'Molten Barrier\''),
(-322519, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 89547, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temple Fireshaper - On Aggro - Cast \'Blazing Eruption\''),
(-322519, 0, 1, 0, 0, 0, 100, 0, 0, 0, 500, 500, '', 11, 89538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Temple Fireshaper - In Combat - Cast \'Fireball\''),
(-322519, 0, 2, 0, 0, 0, 100, 0, 12000, 12000, 22000, 26000, '', 11, 84032, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Fireshaper - In Combat - Cast \'Meteor\''),
(-322519, 0, 3, 0, 0, 0, 100, 0, 10000, 10000, 30000, 30000, '', 11, 89542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temple Fireshaper - In Combat - Cast \'Molten Barrier\'');

-- Temple Swiftstalker SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49307 WHERE `entry` = 48139;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 48139 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48139, 0, 0, 0, 0, 0, 100, 0, 0, 0, 1500, 1500, '', 11, 83877, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Temple Swiftstalker - In Combat - Cast \'Shoot\''),
(48139, 0, 1, 0, 0, 0, 100, 0, 12000, 12000, 22000, 26000, '', 11, 84836, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Swiftstalker - In Combat - Cast \'Multi-Shot\''),
(48139, 0, 2, 0, 0, 0, 100, 0, 10000, 10000, 24000, 27000, '', 11, 89571, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Swiftstalker - In Combat - Cast \'Charged Shot\'');

-- Temple Shadowlancer SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49309 WHERE `entry` = 48141;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 48141 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48141, 0, 0, 0, 0, 0, 100, 0, 8000, 12000, 18000, 22000, '', 11, 89555, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temple Shadowlancer - In Combat - Cast \'Shadowlance\''),
(48141, 0, 1, 0, 0, 0, 100, 0, 4000, 6000, 21000, 25000, '', 11, 89560, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Shadowlancer - In Combat - Cast \'Pact of Darkness\'');

-- Temple Runecaster SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49308 WHERE `entry` = 48140;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 48140 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48140, 0, 0, 0, 0, 0, 100, 0, 3000, 5000, 10000, 10000, '', 11, 89554, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Temple Runecaster - In Combat - Cast \'Runic Cleave\''),
(48140, 0, 1, 0, 0, 0, 100, 0, 7000, 9000, 32000, 36000, '', 11, 89551, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Runecaster - In Combat - Cast \'Curse of the Runecaster\''),
(48140, 0, 2, 0, 0, 0, 100, 0, 12000, 12000, 33000, 35000, '', 11, 89549, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temple Runecaster - In Combat - Cast \'Rune of Healing\'');

-- Rune of Healing SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `unit_flags` = 34080832 WHERE `entry` = 39258;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39258 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39258, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 8, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rune of Healing - On Reset - Set react state to passive'),
(39258, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 73695, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rune of Healing - Linked - Cast \'Rune of Healing\' on self');

-- Pit Viper SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48891 WHERE `entry` = 39444;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39444 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39444, 0, 0, 0, 0, 0, 100, 0, 8500, 8500, 8500, 8500, '', 11, 74538, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Pit Viper - In Combat - Cast \'Poison-tipped Fangs\'');

-- Blistering Scarab SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49294 WHERE `entry` = 40310;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40310 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40310, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - On Reset - Add byte for submerged'),
(40310, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 76084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - Linked - Cast \'Submerge\' on self'),
(40310, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - Linked - Set not-selectable flag'),
(40310, 0, 3, 4, 4, 0, 100, 0, 0, 0, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - On Aggro - Remove byte for submerged'),
(40310, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - Linked - Cast \'Emerge\' on self'),
(40310, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - Linked - Remove not-selectable flag'),
(40310, 0, 6, 0, 9, 0, 100, 0, 10, 40, 10000, 10000, '', 11, 74399, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - On Target In Range (10-40 yards) - Cast \'Charge\' on victim'),
(40310, 0, 7, 0, 0, 0, 100, 0, 3000, 4000, 3000, 4000, '', 11, 74122, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - In Combat - Cast \'Corrosive Spray\' on victim'),
(40310, 0, 8, 0, 0, 0, 100, 0, 5000, 5000, 12000, 12000, '', 11, 74542, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Blistering Scarab - In Combat - Cast \'Serrated Slash\' on self');

-- Jeweled Scarab SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49306 WHERE `entry` = 42556;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 42556 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(42556, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - On Reset - Add byte for submerged'),
(42556, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 76084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Cast \'Submerge\' on self'),
(42556, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Set not-selectable flag'),
(42556, 0, 3, 4, 4, 0, 100, 0, 0, 0, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - On Aggro - Remove byte for submerged'),
(42556, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Cast \'Emerge\' on self'),
(42556, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Remove not-selectable flag'),
(42556, 0, 6, 0, 0, 0, 100, 0, 1500, 1500, 10000, 10000, '', 11, 83233, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - In Combat - Cast \'Surge\' on random player');

-- Venomous Skitterer SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49286 WHERE `entry` = 39440;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39440 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39440, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - On Reset - Add byte for submerged'),
(39440, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 76084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - Linked - Cast \'Submerge\' on self'),
(39440, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - Linked - Set not-selectable flag'),
(39440, 0, 3, 4, 4, 0, 100, 0, 0, 0, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - On Aggro - Remove byte for submerged'),
(39440, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - Linked - Cast \'Emerge\' on self'),
(39440, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - Linked - Remove not-selectable flag'),
(39440, 0, 6, 0, 0, 0, 100, 0, 1500, 1500, 12000, 12000, '', 11, 75158, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - In Combat - Cast \'Surge\' on random player'),
(39440, 0, 7, 0, 0, 0, 100, 0, 3000, 5000, 10000, 12000, '', 11, 74121, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - In Combat - Cast \'Debilitating Venom\' on victim'),
(39440, 0, 8, 0, 0, 0, 100, 0, 8000, 9000, 10000, 12000, '', 11, 73963, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - In Combat - Cast \'Blinding Toxin\' on self');

-- Dustbone Horror SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49301, `unit_flags` = 64 WHERE `entry` IN (40787);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (40787, -307452) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-307452, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - On Reset - Add byte for submerged'),
(-307452, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 76084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Cast \'Submerge\' on self'),
(-307452, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - Linked - Set not-selectable flag'),
(-307452, 0, 3, 4, 4, 0, 100, 0, 0, 0, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - On Aggro - Remove byte for submerged'),
(-307452, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Cast \'Emerge\' on self'),
(-307452, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Venomous Skitterer - Linked - Remove not-selectable flag'),
(-307452, 0, 6, 0, 0, 0, 100, 0, 1500, 1500, 10000, 10000, '', 11, 75453, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - In Combat - Cast \'Smash\' on victim'),
(40787,   0, 0, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, '', 11, 75453, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - In Combat - Cast \'Smash\' on victim');

-- Dustbone Tormentor SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49295, `unit_flags` = 64 WHERE `entry` = 40311;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (40311, -307679) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-307679, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - On Reset - Add byte for submerged'),
(-307679, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 76084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - Linked - Cast \'Submerge\' on self'),
(-307679, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - Linked - Set not-selectable flag'),
(-307679, 0, 3, 4, 4, 0, 100, 0, 0, 0, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - On Aggro - Remove byte for submerged'),
(-307679, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - Linked - Cast \'Emerge\' on self'),
(-307679, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - Linked - Remove not-selectable flag'),
(-307679, 0, 6, 0, 0, 0, 100, 0, 1500, 1500, 2000, 2000, '', 11, 77570, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - In Combat - Cast \'Shadow Bolt\' on victim'),
(-307679, 0, 7, 0, 0, 0, 100, 0, 10000, 10000, 10000, 10000, '', 11, 77357, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - In Combat - Cast \'Curse of Exhaustion\' on victim'),
(40311,   0, 0, 0, 0, 0, 100, 0, 0, 0, 2000, 2000, '', 11, 77570, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - In Combat - Cast \'Shadow Bolt\' on victim'),
(40311,   0, 1, 0, 0, 0, 100, 0, 10000, 10000, 10000, 10000, '', 11, 77357, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Tormentor - In Combat - Cast \'Curse of Exhaustion\' on victim');

-- Dustbone Horror 2 SAI 
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49302 WHERE `entry` = 40808;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40808 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40808, 0, 0, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, '', 11, 75453, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - In Combat - Cast \'Smash\' on victim'),
(40808, 0, 1, 2, 2, 0, 100, 1, 0, 15, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Health Percentage (under 15%) - Add byte for submerged'),
(40808, 0, 2, 3, 61, 0, 100, 1, 0, 0, 0, 0, '', 11, 76084, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Cast \'Submerge\' on self'),
(40808, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Set not-selectable flag'),
(40808, 0, 4, 5, 61, 0, 100, 1, 0, 0, 0, 0, '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Say text 0 (emote)'),
(40808, 0, 5, 0, 61, 0, 100, 1, 0, 0, 0, 0, '', 41, 2500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Despawn in 2500 ms');

-- Ptah's Dustbone Horror SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49296 WHERE `entry` = 40450;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40450 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40450, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - On Reset - Remove byte for submerged'),
(40450, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Cast \'Emerge\' on self'),
(40450, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Remove not-selectable flag'),
(40450, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - Linked - Attack Random Player'),
(40450, 0, 4, 0, 0, 0, 100, 0, 1500, 1500, 10000, 10000, '', 11, 75453, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Dustbone Horror - In Combat - Cast \'Smash\' on victim');

-- Ptah's Jeweled Scarab SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49297 WHERE `entry` = 40458;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40458 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40458, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - On Reset - Remove byte for submerged'),
(40458, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75764, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Cast \'Emerge\' on self'),
(40458, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Remove not-selectable flag'),
(40458, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 49, 0, 0, 0, 0, 0, 0, 18, 100, 0, 0, 0, 0, 0, 0, 'Jeweled Scarab - Linked - Attack Random Player');

-- Stone Trogg Brute SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48899 WHERE `entry` = 40251;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40251 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40251, 0, 0, 0, 33, 0, 100, 0, 0, 0, 0, 0, '', 11, 77373, 32, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Stone Trogg Rock Flinger - Damaged Target - Cast \'Clobber\'');

-- Stone Trogg Rock Flinger SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48897 WHERE `entry` = 40252;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40252 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40252, 0, 0, 0, 0, 0, 100, 0, 10000, 15000, 10000, 15000, '', 11, 77389, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Stone Trogg Rock Flinger - In Combat - Cast \'Stone Throw\'');

-- Stone Trogg Pillager heroic entry
UPDATE `creature_template` SET `difficulty_entry_1` = 48900 WHERE `entry` = 39804;

-- Flame Warden SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48894 WHERE `entry` = 39800;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39800 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39800, 0, 0, 0, 0, 0, 100, 0,  6500,  6500, 13000, 13000, '', 11, 77241, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Flame Warden - In Combat - Cast \'Raging Inferno\''),
(39800, 0, 1, 0, 0, 0, 100, 0, 13000, 13000, 13000, 13000, '', 11, 77273, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Flame Warden - In Combat - Cast \'Lava Eruption\'');

-- Earth Warden SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48895 WHERE `entry` = 39801;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39801 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39801, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 13000, 15000, '', 11, 77234, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Earth Warden - In Combat - Cast \'Rockwave\''),
(39801, 0, 1, 0, 0, 0, 100, 0, 9000, 9000, 20000, 20000, '', 11, 77235, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Earth Warden - In Combat - Cast \'Impale\'');

-- Water Warden SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48892 WHERE `entry` = 39802;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39802 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39802, 0, 0, 0, 25, 0, 100, 0,     0,     0,     0,     0, '', 28, 77349, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Water Warden - On Reset - Remove \'Aqua Bomb\' aura'),
(39802, 0, 1, 0,  4, 0, 100, 0,     0,     0,     0,     0, '', 11, 77349, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Water Warden - On Aggro - Cast \'Aqua Bomb\' on self'),
(39802, 0, 2, 0,  0, 0, 100, 0, 10000, 10000, 15000, 15000, '', 11, 77335, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Water Warden - In Combat - Cast \'Bubble Bound\'');

-- Aqua Bomb SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 41264;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41264 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41264, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 77354, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aqua Bomb - On Reset - Cast \'Auto Grow\' on self'),
(41264, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 77350, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Aqua Bomb - Linked - Cast \'Aqua Bomb\' on self');

-- Air Warden SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48896 WHERE `entry` = 39803;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39803 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39803, 0, 0, 0, 0, 0, 100, 0, 6000, 6000, 12000, 12000, '', 11, 77316, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Air Warden - In Combat - Cast \'Whirling Winds\''),
(39803, 0, 1, 0, 0, 0, 100, 0, 6000, 6000, 10000, 10000, '', 11, 77334, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Air Warden - In Combat - Cast \'Wind Shear\'');

-- Whirling Winds SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 41245;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41245 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41245, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 77321, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whirling Winds - On Reset - Cast \'Whirling Winds\' on self'),
(41245, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 10000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Whirling Winds - Linked - Despawn after 10 seconds');

-- Spatial Anomaly SAI (cannot critically hit)
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 40170, `flags_extra` = `flags_extra` | 131072 WHERE `entry` = 40170;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40170 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40170, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 72242, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spatial Anomaly - On Aggro - Cast \'Arcane Barrage\' on self'),
(40170, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 74869, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spatial Anomaly - Linked - Cast \'Arcane Form Dummy\' on self'),
(40170, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 74880, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spatial Anomaly - Linked - Cast \'Arcane Energy Periodic\' on self');

-- Flux Animator SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49291 WHERE `entry` = 40033;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40033 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40033, 0, 0, 0, 0, 0, 100, 0, 0, 0, 7000, 11000, '', 11, 81013, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Flux Animator - In Combat - Cast \'Arcane Barrage\'');

-- Star Shard SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49292 WHERE `entry` = 40106;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40106 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40106, 0, 0, 0, 0, 0, 100, 0, 0, 0, 1200, 1200, '', 11, 74791, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Star Shard - In Combat - Cast \'Star Shock\'');

-- Starry Sky (dummy)
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 39681;
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 39681 AND `source_type` = 0) OR (`entryorguid` = 3968100 AND `source_type` = 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39681,   0, 0, 1, 25, 0, 100, 0,   0,   0, 0, 0, '', 41,    3600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Starry Sky dummy - On Reset - Despawn in 2400 ms'),
(39681,   0, 1, 0, 61, 0, 100, 0,   0,   0, 0, 0, '', 80, 3968100, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Starry Sky dummy - Linked - Call Actionlist'),
(3968100, 9, 0, 0,  0, 0, 100, 0, 800, 800, 0, 0, '', 11,   74149, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Starry Sky dummy - Actionlist - Cast \'Starry Sky Add Visual\' on self');

-- Astral Shift Explosion Visual (dummy)
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 39787;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39787 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39787, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 74331, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astral Shift Explosion Visual dummy - On Reset - Cast \'Seedling Pod Visual\' on self'),
(39787, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 21000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Astral Shift Explosion Visual dummy - Linked - Despawn in 21 s');

-- Ammunae's Bloodpetal Blossom 
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48716 WHERE `entry` = 40620;
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 40620 AND `source_type` = 0) OR (`entryorguid` = 4062000 AND `source_type` = 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40620, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - On Reset - Add byte for submerged'),
(40620, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 76486, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Linked - Cast \'Submerge\' on self'),
(40620, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Linked - Set not-selectable flag'),
(40620, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 80, 4062000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Linked - Call Actionlist'),
(4062000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 11, 75795, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Linked - Cast \'Summon Bloodpetal Sprout\' on self'),
(4062000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 11, 75769, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Linked - Cast \'Summon Bloodpetal Blossom Visual\' on self'),
(4062000, 9, 2, 0, 0, 0, 100, 0, 3600, 3600, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Actionlist - Remove byte for submerged'),
(4062000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 11, 76485, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Actionlist - Cast \'Emerge\' on self'),
(4062000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Actionlist - Remove not-selectable flag'),
(40620, 0, 4, 0, 0, 0, 100, 0, 5000, 5000, 6000, 6000, '', 11, 76044, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - In Combat - Cast \'Thorn Slash\'');

-- Spore (trash) SAI 
-- Budding Spore SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (40585, 40669);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (40585, 40669) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40585, 0, 0, 1,  6, 0, 100, 0, 0, 0, 0, 0, '', 11, 75701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spore - On Death - Cast \'Spore Cloud\''),
(40585, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 11000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spore - Linked - Despawn in 11 s'),
(40669, 0, 0, 1,  6, 0, 100, 0, 0, 0, 0, 0, '', 11, 75701, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Budding Spore - On Death - Cast \'Spore Cloud\''),
(40669, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 11000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - Linked - Despawn in 11 s');

-- Ammunae's Seedling Pod (normal, heroic)
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` IN (40550, 51329);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (40550, 51329) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40550, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 75688, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - On Reset - Cast \'Summon Seedling Pod (dummy)\' on self'),
(40550, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75657, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - Linked - Cast \'Energize\' on self'),
(40550, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75624, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - Linked - Cast \'Energizing Growth\' on self'),
(51329, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 75688, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - On Reset - Cast \'Summon Seedling Pod (dummy)\' on self'),
(51329, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75657, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - Linked - Cast \'Energize\' on self'),
(51329, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 75624, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - Linked - Cast \'Energizing Growth\' on self');

-- Seedling Pod (trash) SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 40716;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40716 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40716, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 96278, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - On Reset - Cast \'Seedling Pod\' on self'),
(40716, 0, 1, 0, 6, 0, 100, 0, 0, 0, 0, 0, '', 11, 75994, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod - On Death - Cast \'Flourish\'');

-- Seedling Pod dummy
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 40592;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40592 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40592, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 75687, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod dummy - On Reset - Cast \'Seedling Pod Visual\' on self'),
(40592, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 2400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Seedling Pod dummy - Linked - Despawn in 2400 ms');

-- Bloodpetal Blossom dummy
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 40622;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40622 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40622, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 75770, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom dummy - On Reset - Cast \'Bloodpetal Bloom State\' on self'),
(40622, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 41, 2400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom dummy - Linked - Despawn in 2400 ms');

-- Living Vine SAI, riding aura, vehicle accessory
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49299 WHERE `entry` = 40668;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40668 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40668, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 75864, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Blossom - On Reset - Cast \'Vile Nature Zone\' on self'),
(40668, 0, 1, 0, 0, 0, 100, 0, 3000, 3000, 7000, 7000, '', 11, 75153, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Living Vine - In Combat - Cast \'Spore Blast\'');

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 40668;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(40668, 75867, 1, 0);

DELETE FROM `vehicle_template_accessory` WHERE `entry` = 40668;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(40668, 40669, 0, 0, 'Living Vine: Budding Spore', 7, 0);

-- Lifewarden Nymph SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49300 WHERE `entry` = 40715;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40715 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40715, 0, 0, 0, 0, 0, 100, 0,     0,     0,  1500,  1500, '', 11, 75958, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Lifewarden Nymph - In Combat - Cast \'Shoot\''),
(40715, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 38000, 38000, '', 11, 75940, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Lifewarden Nymph - In Combat - Cast \'Tranquility\''),
(40715, 0, 2, 0, 0, 0, 100, 0, 15000, 15000, 30000, 30000, '', 11, 75961, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 'Lifewarden Nymph - In Combat - Cast \'Entangling Shot\'');

-- Bloodpetal Sprout SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48717 WHERE `entry` = 40630;
DELETE FROM `smart_scripts` WHERE (`entryorguid` = 40630 AND `source_type` = 0) OR (`entryorguid` = 4063000 AND `source_type` = 9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40630, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '',  90, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - On Reset - Add byte for submerged'),
(40630, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 76486, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Linked - Cast \'Submerge\' on self'),
(40630, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, '', 18, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Linked - Set not-selectable flag'),
(40630, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 80, 4063000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Linked - Call Actionlist'),
(4063000, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, '', 11, 75768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Linked - Cast \'Summon Bloodpetal Blossom\' on self'),
(4063000, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 11, 75769, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Linked - Cast \'Summon Bloodpetal Blossom Visual\' on self'),
(4063000, 9, 2, 0, 0, 0, 100, 0, 3600, 3600, 0, 0, '', 91, 9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Actionlist - Remove byte for submerged'),
(4063000, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 11, 76485, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Actionlist - Cast \'Emerge\' on self'),
(4063000, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, '', 19, 33554432, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - Actionlist - Remove not-selectable flag'),
(40630, 0, 4, 0, 0, 0, 100, 0, 5000, 5000, 4000, 4000, '', 11, 73686, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Bloodpetal Sprout - In Combat - Cast \'Fixate\'');
 
-- Setesh's Void Sentinel SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48888 WHERE `entry` = 41208;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41208 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41208, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 76959, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Void Sentinel - On Aggro - Cast \'Void Barrier\' on self'),
(41208, 0, 1, 0, 0, 0, 100, 0, 4000, 4000, 30000, 30000, '', 11, 77238, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Void Sentinel - In Combat - Cast \'Charged Fists\'');

-- Setesh's Void Seeker SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 48889 WHERE `entry` = 41148;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41148 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41148, 0, 0, 0, 0, 0, 100, 0, 0, 0, 10000, 10000, '', 11, 76146, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Void Seeker - In Combat - Cast \'Shadow Bolt Volley\''),
(41148, 0, 1, 0, 0, 0, 100, 0, 5000, 5000, 20000, 20000, '', 11, 76903, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Void Seeker - In Combat - Cast \'Anti-Magic Prison\'');

-- Setesh's Void Wyrm heroic entry
UPDATE `creature_template` SET `difficulty_entry_1` = 48890 WHERE `entry` = 41212;

-- Void Seeker SAI
UPDATE `creature_template` SET `AIName` = "SmartAI", `difficulty_entry_1` = 49304 WHERE `entry` = 41371;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 41371 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(41371, 0, 0, 0, 0, 0, 100, 0, 3000, 3000, 10000, 10000, '', 11, 76146, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Void Seeker - In Combat - Cast \'Shadow Bolt Volley\''),
(41371, 0, 1, 0, 0, 0, 100, 0, 10000, 10000, 30000, 30000, '', 11, 73698, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Void Seeker - In Combat - Cast \'Void Rift\'');

-- Void Rift dummy SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 39266;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 39266 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(39266, 0, 0, 1, 25, 0, 100, 0, 0, 0, 0, 0, '', 11, 73699, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Void Rift - On Reset - Cast \'Void Rift\'');

-- Void Wyrm heroic entry
UPDATE `creature_template` SET `difficulty_entry_1` = 49305 WHERE `entry` = 41374;
