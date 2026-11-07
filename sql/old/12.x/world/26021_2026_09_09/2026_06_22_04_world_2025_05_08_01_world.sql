--
DELETE FROM `spell_scripts` WHERE `id` = 37013;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_despawn_target' AND `spell_id` = 37013;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37013, 'spell_gen_despawn_target');

DELETE FROM `spell_scripts` WHERE `id` = 32348;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_mana_tombs_summon_arcane_fiends';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32348, 'spell_mana_tombs_summon_arcane_fiends');

DELETE FROM `spell_scripts` WHERE `id` IN (29126,29137,29135,29136,29138,29139,46672,46671);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_midsummer_cleansing_flames_darnassus',
'spell_midsummer_cleansing_flames_stormwind',
'spell_midsummer_cleansing_flames_ironforge',
'spell_midsummer_cleansing_flames_orgrimmar',
'spell_midsummer_cleansing_flames_thunder_bluff',
'spell_midsummer_cleansing_flames_the_undercity',
'spell_midsummer_cleansing_flames_silvermoon',
'spell_midsummer_cleansing_flames_the_exodar');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(29126, 'spell_midsummer_cleansing_flames_darnassus'),
(29137, 'spell_midsummer_cleansing_flames_stormwind'),
(29135, 'spell_midsummer_cleansing_flames_ironforge'),
(29136, 'spell_midsummer_cleansing_flames_orgrimmar'),
(29138, 'spell_midsummer_cleansing_flames_thunder_bluff'),
(29139, 'spell_midsummer_cleansing_flames_the_undercity'),
(46672, 'spell_midsummer_cleansing_flames_silvermoon'),
(46671, 'spell_midsummer_cleansing_flames_the_exodar');

DELETE FROM `spell_scripts` WHERE `id` = 52933;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_rampage_summon_zulaman_gods_master';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52933, 'spell_zuldrak_rampage_summon_zulaman_gods_master');

DELETE FROM `spell_scripts` WHERE `id` = 51862;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_breaking_through_summon_zulaman_gods_master';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51862, 'spell_zuldrak_breaking_through_summon_zulaman_gods_master');

DELETE FROM `spell_scripts` WHERE `id` IN (29182,29188);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_temple_of_ahnqiraj_teleport_to_twin_emperors',
'spell_temple_of_ahnqiraj_teleport_to_final_chamber');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(29182, 'spell_temple_of_ahnqiraj_teleport_to_twin_emperors'),
(29188, 'spell_temple_of_ahnqiraj_teleport_to_final_chamber');

DELETE FROM `spell_scripts` WHERE `id` IN (51864,51889);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_summon_nass';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51864, 'spell_zuldrak_summon_nass'),
(51889, 'spell_zuldrak_summon_nass');

DELETE FROM `spell_scripts` WHERE `id` = 36327;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21186 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = -79409 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21186,0,0,0,8,0,100,0,36327,0,0,0,0,11,36521,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Warder Target - On Spellhit 'Shoot Arcane Explosion Arrow' - Cast 'Summon Arcane Explosion'"),
(-79409,0,2,0,8,0,100,0,36327,0,0,0,0,11,36521,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Warder Target - On Spellhit 'Shoot Arcane Explosion Arrow' - Cast 'Summon Arcane Explosion'");

DELETE FROM `spell_scripts` WHERE `id` = 45030;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25003 AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25003,0,3,0,8,0,100,0,45030,0,0,0,0,11,45088,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Emissary of Hate - On Spellhit 'Impale Emissary' - Cast 'Emissary of Hate Credit'");

DELETE FROM `spell_scripts` WHERE `id` = 53010;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_remove_akalis_stun';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(53010, 'spell_zuldrak_remove_akalis_stun');

DELETE FROM `spell_scripts` WHERE `id` IN (47117,47149,47316,47405,50439);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_grizzly_hills_script_cast_summon_image_of_drakuru_01',
'spell_grizzly_hills_script_cast_summon_image_of_drakuru_02',
'spell_grizzly_hills_script_cast_summon_image_of_drakuru_03',
'spell_grizzly_hills_script_cast_summon_image_of_drakuru_04',
'spell_grizzly_hills_script_cast_summon_image_of_drakuru_05');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47117, 'spell_grizzly_hills_script_cast_summon_image_of_drakuru_01'),
(47149, 'spell_grizzly_hills_script_cast_summon_image_of_drakuru_02'),
(47316, 'spell_grizzly_hills_script_cast_summon_image_of_drakuru_03'),
(47405, 'spell_grizzly_hills_script_cast_summon_image_of_drakuru_04'),
(50439, 'spell_grizzly_hills_script_cast_summon_image_of_drakuru_05');

DELETE FROM `spell_scripts` WHERE `id` IN (58916,58917);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_icecrown_gift_of_the_lich_king',
'spell_icecrown_consume_minions');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(58916, 'spell_icecrown_gift_of_the_lich_king'),
(58917, 'spell_icecrown_consume_minions');

DELETE FROM `spell_scripts` WHERE `id` = 37028;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_bem_dispelling_analysis';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37028, 'spell_bem_dispelling_analysis');

DELETE FROM `spell_scripts` WHERE `id` = 37834;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_shadowmoon_unbanish_azaloth';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37834, 'spell_shadowmoon_unbanish_azaloth');

DELETE FROM `spell_scripts` WHERE `id` = 46550;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_borean_tundra_weakness_to_lightning_on_quest_complete';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46550, 'spell_borean_tundra_weakness_to_lightning_on_quest_complete');

DELETE FROM `spell_scripts` WHERE `id` IN (37867,37892,37894);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_shadowmoon_arcano_scorp_control_01',
'spell_shadowmoon_arcano_scorp_control_02',
'spell_shadowmoon_arcano_scorp_control_03');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37867, 'spell_shadowmoon_arcano_scorp_control_01'),
(37892, 'spell_shadowmoon_arcano_scorp_control_02'),
(37894, 'spell_shadowmoon_arcano_scorp_control_03');

DELETE FROM `spell_scripts` WHERE `id` IN (25143,29128,29129,25140);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_terokkar_translocation_firewing_point_building_down',
'spell_terokkar_translocation_firewing_point_building_up',
'spell_terokkar_translocation_firewing_point_tower_down',
'spell_terokkar_translocation_firewing_point_tower_up');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(25143, 'spell_terokkar_translocation_firewing_point_building_down'),
(29128, 'spell_terokkar_translocation_firewing_point_building_up'),
(29129, 'spell_terokkar_translocation_firewing_point_tower_down'),
(25140, 'spell_terokkar_translocation_firewing_point_tower_up');

DELETE FROM `spell_scripts` WHERE `id` IN (25650,25652);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_hellfire_peninsula_translocation_falcon_watch_tower_down',
'spell_hellfire_peninsula_translocation_falcon_watch_tower_up');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(25650, 'spell_hellfire_peninsula_translocation_falcon_watch_tower_down'),
(25652, 'spell_hellfire_peninsula_translocation_falcon_watch_tower_up');

DELETE FROM `spell_scripts` WHERE `id` IN (34448,34452,35376,35727);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_eastern_kingdoms_duskwither_spire_up',
'spell_eastern_kingdoms_duskwither_spire_down',
'spell_eastern_kingdoms_silvermoon_to_undercity',
'spell_eastern_kingdoms_undercity_to_silvermoon');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(34448, 'spell_eastern_kingdoms_duskwither_spire_up'),
(34452, 'spell_eastern_kingdoms_duskwither_spire_down'),
(35376, 'spell_eastern_kingdoms_silvermoon_to_undercity'),
(35727, 'spell_eastern_kingdoms_undercity_to_silvermoon');

DELETE FROM `spell_scripts` WHERE `id` IN (47393,47615,47638);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_dragonblight_focus_on_the_beach_quest_completion_script',
'spell_dragonblight_atop_the_woodlands_quest_completion_script',
'spell_dragonblight_end_of_the_line_quest_completion_script');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(47393, 'spell_dragonblight_focus_on_the_beach_quest_completion_script'),
(47615, 'spell_dragonblight_atop_the_woodlands_quest_completion_script'),
(47638, 'spell_dragonblight_end_of_the_line_quest_completion_script');

DELETE FROM `spell_scripts` WHERE `id` = 24320;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zulgurub_poisonous_blood';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(24320, 'spell_zulgurub_poisonous_blood');

DELETE FROM `spell_scripts` WHERE `id` = 45071;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_eastern_kingdoms_dead_scar_bombing_run';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45071, 'spell_eastern_kingdoms_dead_scar_bombing_run');

DELETE FROM `spell_scripts` WHERE `id` = 57753;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30681 AND `source_type` = 0 AND `id` = 5;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30681,0,5,0,8,0,100,0,57753,0,0,0,0,11,57752,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Onyx Blaze Mistress - On Spellhit 'Conjure Flame Orb' - Cast 'Flame Orb Summon'");

DELETE FROM `spell_scripts` WHERE `id` = 46237;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 25861;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25861 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25861,0,0,0,8,0,100,0,46237,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Orphaned Mammoth Calf - On Spellhit 'Dismiss Orphaned Mammoth' - Delayed Despawn"),
(25861,0,1,0,8,0,100,0,46237,0,0,0,0,28,46233,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Orphaned Mammoth Calf - On Spellhit 'Dismiss Orphaned Mammoth' - Remove Aura 'Call Mammoth Orphan'");

DELETE FROM `spell_scripts` WHERE `id` = 23301;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_icecrown_ebon_blade_banner';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(23301, 'spell_icecrown_ebon_blade_banner');

DELETE FROM `spell_scripts` WHERE `id` IN (54620,58622);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_dalaran_teleport_to_dalaran',
'spell_dalaran_teleport_to_lake_wintergrasp');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(54620, 'spell_dalaran_teleport_to_dalaran'),
(58622, 'spell_dalaran_teleport_to_lake_wintergrasp');

DELETE FROM `spell_scripts` WHERE `id` = 52124;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_chapter1_sky_darkener_assault';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52124, 'spell_chapter1_sky_darkener_assault');

DELETE FROM `spell_scripts` WHERE `id` = 45188;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_eastern_kingdoms_dawnblade_attack';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45188, 'spell_eastern_kingdoms_dawnblade_attack');

DELETE FROM `spell_scripts` WHERE `id` = 45958;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_borean_tundra_signal_alliance';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45958, 'spell_borean_tundra_signal_alliance');

DELETE FROM `spell_scripts` WHERE `id` = 46289;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_muru_negative_energy';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46289, 'spell_muru_negative_energy');

DELETE FROM `spell_scripts` WHERE `id` = 26393;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_lunar_festival_elunes_blessing';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(26393, 'spell_lunar_festival_elunes_blessing');

DELETE FROM `spell_scripts` WHERE `id` = 49466;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_brewfest_mole_machine_portal_schedule';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49466, 'spell_brewfest_mole_machine_portal_schedule');
