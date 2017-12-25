-- Halls of Origination work
SET @CGUID := 999999; -- 1 entry needed

-- General: Elevator, trash mobs --
-- spawn missing Temple Fireshaper (not in old sniffs)
DELETE FROM `creature` WHERE `guid` = @CGUID;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `dynamicflags`, `ScriptName`, `VerifiedBuild`) VALUES
(@CGUID, 48143, 644, 0, 0, 6, 0, 0, 0, 0, -640.624, 396.364, 83.8651, 1.54741, 7200, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, '', -1);

-- script names, sniff corrections
UPDATE `gameobject_template` SET `ScriptName` = 'go_hoo_the_makers_lift_controller' WHERE `entry` = 207669;
UPDATE `creature_template` SET `ScriptName` = 'npc_hoo_spatial_flux', `unit_flags` = 33554496 WHERE `entry` = 39612;
UPDATE `creature_template` SET `ScriptName` = 'npc_hoo_energy_flux', `unit_flags` = 33554496, `speed_walk` = 5.5/2.5, `speed_run` = 5.5/2.5 WHERE `entry` = 44015;
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hoo_energy_flux_target_selector', 'spell_hoo_arcane_energy_check');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(82382, 'spell_hoo_energy_flux_target_selector'),
(74880, 'spell_hoo_arcane_energy_check');

-- gameobject rotation of lightmachines, glass star 2
UPDATE `gameobject` SET `rotation0` = -0.150109,  `rotation1` = -0.150108, `rotation2` = -0.690989,  `rotation3` = 0.690991 WHERE `guid` IN (220756, 220763);
UPDATE `gameobject` SET `rotation0` =  0.150109,  `rotation1` = -0.150108, `rotation2` =  0.690989,  `rotation3` = 0.690991 WHERE `guid` IN (220757, 220764);
UPDATE `gameobject` SET `rotation0` =  0.7071066, `rotation1` =  0,        `rotation2` = -0.7071066, `rotation3` = 0        WHERE `guid` = 220755;

-- set correct spawnMask to Beacons - normal (4) and heroic (2)
UPDATE `gameobject` SET `spawnMask` = 4 WHERE `guid` IN (200968, 200969);
UPDATE `gameobject` SET `spawnMask` = 2 WHERE `guid` IN (220773, 220775); 

-- inhabitType 12 (root + disable gravity): Rune of Healing, Cave In Stalker, Dust Cloud Stalker, Searing Light, Spatial Flux, Isiset's Spatial Flux, 
--   Budding Spore, Aqua Bomb, Alpha Beam, Omega Stance, Aggro Stalker, Beetle Stalker, Quick Sand, Living Vine, Chaos Portal, Void Rift, Chaos Blast, 
--   Add Stalker, Starry Sky, Ammunae's Seedling Pod, Seedling Pod, Bloodpetal Blossom, Seedling Pod
UPDATE `creature_template` SET `InhabitType` = 12 WHERE `entry` IN (39258, 39612, 40202, 40283, 40183, 48707, 40669, 
41264, 41144, 41194, 40790, 40459, 40503, 40668, 41055, 39266, 41041, 41479, 39681, 40592, 40716, 40622, 40550); 

-- random movement for trash at Seat of Magic
UPDATE `creature` SET `MovementType` = 1, `spawndist` = 10 WHERE `guid` IN (317535, 313950, 313951, 313952, 320781, 320754, 313949, 313953);

-- Boss: Temple Guardian Anhuur --
-- heroic entry
UPDATE `creature_template` SET `difficulty_entry_1` = 49262 WHERE `entry` = 39425;

-- script names ("spell_anhuur_activate_beacons" rewritten into "spell_anhuur_handle_beacons")
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_anhuur_reverberating_hymn', 'spell_anhuur_activate_beacons', 'spell_anhuur_handle_beacons');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(75322, 'spell_anhuur_reverberating_hymn'),
(76599, 'spell_anhuur_handle_beacons'),
(76600, 'spell_anhuur_handle_beacons');

-- Boss: Anraphet --
-- speed corrections for Brann
UPDATE `creature_template` SET `speed_walk` = 2.5/2.5, `speed_run` = 7/2.5 WHERE `entry` = 39908;

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
UPDATE `creature_template` SET `ScriptName` = 'npc_astral_shift_explosion_visual', `unit_flags` = 33554752 WHERE `entry` = 39787;
UPDATE `creature_template` SET `ScriptName` = 'npc_starry_sky' WHERE `entry` = 39681;
UPDATE `creature_template` SET `ScriptName` = 'npc_isiset_mirror_image' WHERE `entry` IN (39720, 39721, 39722);
UPDATE `creature_template` SET `ScriptName` = 'npc_isiset_spatial_flux', `unit_flags` = 33554496 WHERE `entry` = 48707;
UPDATE `creature_template` SET `ScriptName` = 'npc_isiset_energy_flux', `unit_flags` = 33554496, `speed_walk` = 5.5/2.5, `speed_run` = 5.5/2.5 WHERE `entry` = 48709;

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
(90750, 'spell_isiset_call_of_sky'),
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

-- SmartAI --
-- Spatial Anomaly SAI (cannot critically hit)
UPDATE `creature_template` SET `AIName` = "SmartAI", `flags_extra` = `flags_extra` | 131072 WHERE `entry` = 40170;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40170 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40170, 0, 0, 1, 4, 0, 100, 0, 0, 0, 0, 0, '', 11, 72242, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spatial Anomaly - On Aggro - Cast \'Arcane Barrage\' on self'),
(40170, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 74869, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spatial Anomaly - Linked - Cast \'Arcane Form Dummy\' on self'),
(40170, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 74880, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spatial Anomaly - Linked - Cast \'Arcane Energy Periodic\' on self');

-- Flux Animator SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 40033;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40033 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40033, 0, 0, 0, 0, 0, 100, 0, 0, 0, 7000, 11000, '', 11, 81013, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Flux Animator - In Combat - Cast \'Arcane Barrage\'');

-- Star Shard SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 40106;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 40106 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(40106, 0, 0, 0, 0, 0, 100, 0, 0, 0, 1200, 1200, '', 11, 74791, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Star Shard - In Combat - Cast \'Star Shock\'');

-- Temple Fireshaper SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 48143;
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
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 48139;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 48139 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48139, 0, 0, 0, 0, 0, 100, 0, 0, 0, 1500, 1500, '', 11, 83877, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Temple Swiftstalker - In Combat - Cast \'Shoot\''),
(48139, 0, 1, 0, 0, 0, 100, 0, 12000, 12000, 22000, 26000, '', 11, 84836, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Swiftstalker - In Combat - Cast \'Multi-Shot\''),
(48139, 0, 2, 0, 0, 0, 100, 0, 10000, 10000, 24000, 27000, '', 11, 89571, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Swiftstalker - In Combat - Cast \'Charged Shot\'');

-- Temple Shadowlancer SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 48141;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 48141 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(48141, 0, 0, 0, 0, 0, 100, 0, 8000, 12000, 18000, 22000, '', 11, 89555, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Temple Shadowlancer - In Combat - Cast \'Shadowlance\''),
(48141, 0, 1, 0, 0, 0, 100, 0, 4000, 6000, 21000, 25000, '', 11, 89560, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 'Temple Shadowlancer - In Combat - Cast \'Pact of Darkness\'');

-- Temple Runecaster SAI
UPDATE `creature_template` SET `AIName` = "SmartAI" WHERE `entry` = 48140;
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
(39258, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, '', 11, 73695, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Rune of Healing - On Reset - Cast \'Rune of Healing\' on self');

-- Creature Formations --
-- trash groups
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (313971,313972,322519,322466,322210,@CGUID,317604,317458);
INSERT INTO `creature_formations` (`leaderGUID`,`memberGUID`,`dist`,`angle`,`groupAI`,`point_1`,`point_2`) VALUES
-- Isiset trash right-side formation
(313971,313971,0,0,3,0,0),
(313971,317535,0,0,3,0,0),
(313971,313950,0,0,3,0,0),
(313971,313951,0,0,3,0,0),
(313971,313952,0,0,3,0,0),
-- Isiset trash left-side formation
(313972,313972,0,0,3,0,0),
(313972,320781,0,0,3,0,0),
(313972,320754,0,0,3,0,0),
(313972,313949,0,0,3,0,0),
(313972,313953,0,0,3,0,0),
-- First group, on the beginning
(322519,322519,0,0,3,0,0),
(322519,322579,0,0,3,0,0),
(322519,322520,0,0,3,0,0),
(322519,322578,0,0,3,0,0),
-- Second right-side group
(322466,322466,0,0,3,0,0),
(322466,322211,13,150,515,5,10),
(322466,322053,13,210,515,5,10),
(322466,322465,7,180,515,5,10),
-- Second left-side group
(322210,322210,0,0,3,0,0),
(322210,321936,13,150,515,5,10),
(322210,321868,13,210,515,5,10),
(322210,321867,7,180,515,5,10),
-- Third group
(@CGUID,@CGUID,0,0,3,0,0),
(@CGUID,320942,0,0,3,0,0),
(@CGUID,321479,0,0,3,0,0),
-- Group before elevator
(317604,317604,0,0,3,0,0),
(317604,317603,9,140,515,0,0),
(317604,317601,9,220,515,0,0),
(317604,317570,11,90,515,0,0),
-- Group west from elevator
(317458,317458,0,0,3,0,0),
(317458,320150,8,150,515,2,5),
(317458,317381,8,210,515,2,5),
(317458,317382,8,270,515,2,5);

-- Waypoints --
-- trash paths
UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (322466);
DELETE FROM `creature_addon` WHERE `guid` IN (322466);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(322466, 3224660, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3224660);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3224660, 1, -749.123, 472.962, 67.20775, 0, 0, 0, 0, 100, 0),
(3224660, 2, -748.2323, 464.9793, 67.19108, 0, 0, 0, 0, 100, 0),
(3224660, 3, -734.168, 459.564, 67.17745, 0, 0, 0, 0, 100, 0),
(3224660, 4, -717.325, 459.96, 67.18442, 0, 0, 0, 0, 100, 0),
(3224660, 5, -697.075, 460.267, 73.2090, 0, 0, 0, 0, 100, 0),
(3224660, 6, -678.781, 460.182, 79.06738, 0, 0, 0, 0, 100, 0), -- turns back
(3224660, 7, -697.075, 460.267, 73.2090, 0, 0, 0, 0, 100, 0),
(3224660, 8, -717.325, 459.96, 67.18442, 0, 0, 0, 0, 100, 0),
(3224660, 9, -734.168, 459.564, 67.17745, 0, 0, 0, 0, 100, 0),
(3224660, 10, -748.2323, 464.9793, 67.19108, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (322210);
DELETE FROM `creature_addon` WHERE `guid` IN (322210);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(322210, 3222100, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3222100);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3222100, 1, -749.771, 499.585, 67.21061, 0, 0, 0, 0, 100, 0),
(3222100, 2, -746.602, 515.061, 67.2137, 0, 0, 0, 0, 100, 0),
(3222100, 3, -722.425, 516.491, 67.18806, 0, 0, 0, 0, 100, 0),
(3222100, 4, -697.958, 516.549, 72.92428, 0, 0, 0, 0, 100, 0),
(3222100, 5, -678.974, 516.177, 78.99928, 0, 0, 0, 0, 100, 0),
(3222100, 6, -664.887, 515.224, 83.51125, 0, 0, 0, 0, 100, 0), -- turns back
(3222100, 7, -678.974, 516.177, 78.99928, 0, 0, 0, 0, 100, 0), 
(3222100, 8, -697.958, 516.549, 72.92428, 0, 0, 0, 0, 100, 0),
(3222100, 9, -722.425, 516.491, 67.18806, 0, 0, 0, 0, 100, 0),
(3222100, 10, -746.602, 515.061, 67.2137, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (317458);
DELETE FROM `creature_addon` WHERE `guid` IN (317458);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(317458, 3174580, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3174580);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3174580, 1, -507.01, 338.422, 95.64893, 0, 0, 0, 0, 100, 0),
(3174580, 2, -506.941, 330.323, 95.65701, 0, 0, 0, 0, 100, 0), 
(3174580, 3, -507.142, 319.997, 95.65394, 0, 0, 0, 0, 100, 0), -- turns back
(3174580, 4, -506.941, 330.323, 95.65701, 0, 0, 0, 0, 100, 0), 
(3174580, 5, -507.01, 338.422, 95.64893, 0, 0, 0, 0, 100, 0),
(3174580, 6, -507.0659, 347.3517, 95.64893, 0, 0, 0, 0, 100, 0);

UPDATE `creature` SET `MovementType` = 2 WHERE `guid` IN (317604);
DELETE FROM `creature_addon` WHERE `guid` IN (317604);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(317604, 3176040, 0, 0, 0, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE `id` IN (3176040);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(3176040, 1, -622.665, 193.2998, 81.75228, 0, 0, 0, 0, 100, 0),
(3176040, 2, -634.005, 193.528, 81.82398, 0, 0, 0, 0, 100, 0),
(3176040, 3, -640.3165, 193.7006, 81.9477, 0, 0, 0, 0, 100, 0),
(3176040, 4, -640.856, 204.708, 81.80561, 0, 0, 0, 0, 100, 0),
(3176040, 5, -640.726, 212.753, 81.82135, 0, 0, 0, 0, 100, 0),
(3176040, 6, -640.714, 224.997, 81.84181, 0, 0, 0, 0, 100, 0), -- turns back
(3176040, 7, -640.726, 212.753, 81.82135, 0, 0, 0, 0, 100, 0),
(3176040, 8, -640.856, 204.708, 81.80561, 0, 0, 0, 0, 100, 0),
(3176040, 9, -640.3165, 193.7006, 81.9477, 0, 0, 0, 0, 100, 0),
(3176040, 10, -634.005, 193.528, 81.82398, 0, 0, 0, 0, 100, 0);
