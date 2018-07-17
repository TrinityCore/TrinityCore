UPDATE creature_template SET scriptname = "npc_crowley_horse_35231" WHERE entry = 35231;
UPDATE creature_template SET spell1 = 58859, ScriptName = 'npc_feral_spirit' WHERE entry = 29264;
UPDATE creature_template SET scriptname = "boss_saprish" WHERE entry = 122316;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
UPDATE creature_template SET scriptname = "boss_viceroy_nezhar" WHERE entry = 124309;
replace INTO areatrigger_scripts (entry,ScriptName) VALUES 
(7625,'at_calamir_wrathful_flames'),
(7630,'at_calamir_icy_comet'),
(7650,'at_calamir_arcanopulse'),
(7640,'at_calamir_howling_gale'),
(1520,'at_legion_portal_en_entrance');
replace into `criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) values
('6084','11','0','0','achievement_minutes_to_midnight'),
('6084','11','0','0','achievement_minutes_to_midnight');
UPDATE creature_template SET scriptname = "boss_lura" WHERE entry = 122314;
REPLACE INTO `criteria_data` (`criteria_id`,`type`,`value1`,`value2`,`ScriptName`)
VALUES
(10066,11,0,0,'achievement_iron_dwarf_medium_rare'),
(10067,11,0,0,'achievement_iron_dwarf_medium_rare');
REPLACE INTO spell_script_names VALUES
(342521, "shadowmoon_burial_grounds_initial_teleport"),
(534556, "shadowmoon_burial_grounds_ritual_of_bones_darkness_trigger"),
(45462, 'spell_dk_plague_strike'),
(93202, "spell_corruption_sickness"),
(91436, "spell_springvale_forsaken_ability"),
(91442, "spell_springvale_forsaken_ability"),
(106162, 'spell_ultraxion_last_defender_of_azeroth'),
(70827, 'spell_pos_ice_shards'),
(182346, 'spell_item_piccolo_of_the_flaming_fire'),
(18499, 'spell_warr_berzerker_rage'),
(59725, 'spell_warr_improved_spell_reflection'),
(-84583, 'spell_warr_lambs_to_the_slaughter'),
(94009, 'spell_warr_rend'),
(20230, 'spell_warr_retaliation'),
(-46951, 'spell_warr_sword_and_board'),
(50720, 'spell_warr_vigilance'),
(50725, 'spell_warr_vigilance_trigger'),
(61698,'spell_gen_ds_flush_knockback'),
(47960, 'spell_warl_molten_core_dot'),
(103958, 'spell_warl_metamorphosis_cost'),
(114175, 'spell_warl_demonic_call'),
(39142, 'spell_archimonde_drain_world_tree_dummy'),
(114851, 'spell_dk_blood_charges'),
(50453, 'spell_dk_blood_gorged'),
(108196, 'spell_dk_death_siphon'),
(206967, 'spell_dk_will_of_the_necropolis'),
(196771, 'spell_dk_remorseless_winter'),
(159429, 'spell_dk_glyph_of_runic_power'),
(58677, 'spell_dk_glyph_of_deaths_embrace'),
(20217, 'spell_pal_blessing_of_kings'),
(19740, 'spell_pal_blessing_of_might'),
(1126, 'spell_dru_mark_of_the_wild'),
(21562, 'spell_pri_power_word_fortitude'),
(27683, 'spell_pri_shadow_protection'),
(-19572, 'spell_hun_improved_mend_pet'),
(53412, 'spell_hun_invigoration'),
(115921, 'spell_monk_legacy_of_the_emperor'),
(123766, 'spell_monk_mana_tea_stacks'),
(124336, 'spell_monk_path_of_blossom'),
(140023, 'spell_monk_ring_of_peace_aura'),
(123273, 'spell_monk_surging_mist_glyphed'),
(123980, 'spell_monk_tigereye_brew_stacks'),
(-47509, 'spell_pri_divine_aegis'),
(64904, 'spell_pri_hymn_of_hope'),
(108945, 'spell_priest_angelic_bulwark'),
(7001, 'spell_pri_lightwell_renew'),
(49821, 'spell_pri_mind_sear'),
(47948, 'spell_pri_pain_and_suffering_proc'),
(-47569, 'spell_pri_phantasm'),
(108920, 'spell_pri_void_tendrils'),
(206237, 'spell_rog_enveloping_shadows'),
(974, 'spell_sha_earth_shield'),
(8232, 'spell_shaman_windfury_weapon'),
(2645, 'spell_sha_glyph_of_lakestrider'),
(55440, 'spell_sha_glyph_of_healing_wave'),
(88766, 'spell_sha_fulmination'),
(30823, 'spell_sha_glyph_of_shamanistic_rage'),
(324, 'spell_sha_lightning_shield'),
(30884, 'spell_sha_nature_guardian'),
(72868,'spell_putricide_slime_puddle_aura'),
(25042, 'spell_mark_of_nature'),
(72869,'spell_putricide_slime_puddle_aura'),
(110327, 'spell_ultraxion_last_defender_of_azeroth_dummy'),
(75880, "spell_halion_spawn_living_embers"),
(91444, "spell_springvale_forsaken_ability");
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(58630,'spell_gen_dungeon_credit'),
(59046,'spell_gen_dungeon_credit'),
(59450,'spell_gen_dungeon_credit'),
(61863,'spell_gen_dungeon_credit'),
(64899,'spell_gen_dungeon_credit'),
(64985,'spell_gen_dungeon_credit'),
(65074,'spell_gen_dungeon_credit'),
(65195,'spell_gen_dungeon_credit'),
(68184,'spell_gen_dungeon_credit'),
(68572,'spell_gen_dungeon_credit'),
(68574,'spell_gen_dungeon_credit'),
(68663,'spell_gen_dungeon_credit'),
(72706,'spell_gen_dungeon_credit'),
(72830,'spell_gen_dungeon_credit'),
(72959,'spell_gen_dungeon_credit');
REPLACE INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(62791,'spell_xt002_heart_overload_periodic');
REPLACE INTO spell_script_names VALUES
('93261', 'spell_wind_burst'),
('93262', 'spell_wind_burst'),
('93263', 'spell_wind_burst');
REPLACE INTO `areatrigger_template` (`Id`, `Type`) VALUES ('9757', '3'); 
UPDATE `areatrigger_template` SET `Flags` = '4' , `ScriptName` = 'areatrigger_infernal_flames' WHERE `Id` = '9757'; 
REPLACE INTO `criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
('6180', '11', '1', '0','achievement_chromatic_champion');
UPDATE areatrigger_template SET `ScriptName` = 'areatrigger_aegis_of_aggramar' WHERE `ID` = 9758;
REPLACE INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(11353, 'at_sha_crashing_storm'),
(5029, 'areatrigger_flame_of_woe'),
(9677, 'areatrigger_storm_breath'),
(2200, 'at_arcane_orb'),
(11420, 'areatrigger_black_hole'),
(151582, 'AreaTrigger_SuppresionField'),
(149959, 'areatrigger_shatter_earth'),
(7214, 'Instances::Bloodmaul::areatrigger_roltall_heat_wave'),
(6022, 'Instances::Bloodmaul::areatrigger_roltall_burning_slag'),
(7455, 'Instances::Bloodmaul::areatrigger_magma_barrage'),
(5559, 'Instances::Bloodmaul::areatrigger_volcanic_trantum'),
(5555, 'Instances::Bloodmaul::areatrigger_shatter_earth'),
(983, 'at_dru_solar_beam'),
(314, 'at_dru_ursols_vortex'),
(373, 'at_monk_gift_of_the_ox_sphere'),
(2763, 'at_monk_windwalking'),
(12802, "areatrigger_void_devestation"),
(1489, 'at_pri_power_word_barrier'),
(3691, 'at_sha_earthquake_totem'),
(151582, 'Instances::Bloodmaul::AreaTrigger_SuppresionField');
UPDATE `gameobject_template` SET `ScriptName`='go_mandragore_196394' WHERE `entry`=196394;
REPLACE INTO `criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(6133, 11, 0, 0, 'achievement_maybe_he_ll_get_dizzy');
UPDATE areatrigger_template SET ScriptName='at_shadow_rune3' WHERE Id=11353;
