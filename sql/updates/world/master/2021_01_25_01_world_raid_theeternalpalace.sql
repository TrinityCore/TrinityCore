-- Commander Sivara
-- septic ground
replace into areatrigger_scripts values (17105,'bfa_spell_septic_ground_aura');
replace into areatrigger_template values (17105, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_spell_septic_ground_aura', 0);

-- frozen ground
replace into areatrigger_scripts values (17104,'bfa_at_frozen_ground');
replace into areatrigger_template values (17104, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_frozen_ground', 0);

replace INTO `spell_areatrigger` VALUES 
('17105', '17105', '0', '11895', '0', '0', '0', '0', '373', '0', '2000', '0'),
('17104', '17104', '0', '11894', '0', '0', '0', '0', '374', '0', '2000', '0'),

('299713', '17105', '0', '11895', '0', '0', '0', '0', '373', '0', '2000', '0'),
('299704', '17104', '0', '11894', '0', '0', '0', '0', '374', '0', '2000', '0');

-- overwhelming barrage
replace into spell_areatrigger values (16915, 16915, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16915,'');
replace into areatrigger_template values (16915, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);

replace into spell_areatrigger values (16563, 16563, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16563,'bfa_at_toxic_frost_bolts');
replace into areatrigger_template values (16563, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_toxic_frost_bolts', 0);

replace into spell_areatrigger values (16564, 16564, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16564,'bfa_at_toxic_frost_bolts');
replace into areatrigger_template values (16564, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_toxic_frost_bolts', 0);

update creature_template set scriptname='bfa_boss_commander_sivara' where entry=151881;

replace into spell_script_names values (294726,'bfa_spell_chimeric_marks');
replace into spell_script_names values (295332,'bfa_spell_crushing_reverberation');
replace into spell_script_names values (300698,'bfa_spell_frostvenom_tipped');
replace into spell_script_names values (295606,'bfa_spell_frost_bolt_javelin');
replace into spell_script_names values (294711,'bfa_spell_frost_mark');
replace into spell_script_names values (300961,'bfa_spell_frozen_ground_aura');
replace into spell_script_names values (295791,'bfa_spell_inversion');
replace into spell_script_names values (300883,'bfa_spell_inversion_sickness_venom');
replace into spell_script_names values (300882,'bfa_spell_inversion_sickness_frost');
replace into spell_script_names values (295346,'bfa_spell_overflow');
replace into spell_script_names values (295348,'bfa_spell_overflowing_chill_venom_aura');
replace into spell_script_names values (295415,'bfa_spell_overflowing_chill_venom_damage');
replace into spell_script_names values (295421,'bfa_spell_overflowing_chill_venom_aura');
replace into spell_script_names values (295417,'bfa_spell_overflowing_chill_venom_damage');
replace into spell_script_names values (300701,'bfa_spell_rimefrost_aura');
replace into spell_script_names values (300962,'bfa_spell_septic_ground_aura');
replace into spell_script_names values (300705,'bfa_spell_septic_taint_aura');
replace into spell_script_names values (295607,'bfa_spell_toxic_bolt_javelin');
replace into spell_script_names values (294715,'bfa_spell_toxic_brand');
replace into spell_script_names values (298122,'bfa_spell_overwhelming_barrage');

-- Blackwater Behemoth
replace into areatrigger_scripts values (16226,'bfa_at_bioluminescence');
replace into areatrigger_template values (16226, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_bioluminescence', 0);

replace INTO `spell_areatrigger` VALUES 
('16226', '16226', '0', '0', '0', '0', '0', '0', '373', '0', '2000', '0');

update creature_template set scriptname='bfa_npc_pufferfish' where entry=155278;
update creature_template set scriptname='bfa_npc_darkwater_jellyfish' where entry=153779;
update creature_template set scriptname='bfa_npc_oxygen_rich_membrane' where entry=150585;
update creature_template set scriptname='bfa_boss_blackwater_behemoth' where entry=150653;

replace into spell_script_names values (297932,'bfa_spell_bioelectric_feelers');
replace into spell_script_names values (298424,'bfa_spell_feeding_frenzy');
replace into spell_script_names values (292307,'bfa_spell_gaze_from_below');
replace into spell_script_names values (298595,'bfa_spell_glowing_stinger');
replace into spell_script_names values (301494,'bfa_spell_piercing_barb_beam');
replace into spell_script_names values (301930,'bfa_spell_piercing_barb_damage');
replace into spell_script_names values (295412,'bfa_spell_radiant_biomass');
replace into spell_script_names values (292279,'bfa_spell_shock_pulse_damage');
replace into spell_script_names values (292159,'bfa_spell_toxic_spine');

-- Radiance of Azshara
update creature_template set scriptname='bfa_boss_radiance_of_azshara' where entry=152364;
update creature_template set scriptname='bfa_npc_arcane_bomb_radiance' where entry=155901;
update creature_template set scriptname='bfa_npc_stormlings' where entry=152816;
update creature_template set scriptname='bfa_npc_stormwraith' where entry=152512;

replace into spell_script_names values (295920,'bfa_spell_ancient_tempest_players');
replace into spell_script_names values (304065,'bfa_spell_arcanado_burst_cast');
replace into spell_script_names values (304025,'bfa_spell_arcane_bomb_radiance_dummy');
replace into spell_script_names values (304067,'bfa_spell_arcanado_burst_dummy');
replace into spell_script_names values (304026,'bfa_spell_arcane_bomb_radiance');

replace into spell_areatrigger values (16695, 16695, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16695,'bfa_at_squall_trap');
replace into areatrigger_template values (16695, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_squall_trap', 0);

replace into spell_areatrigger values (17469, 17469, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17469,'bfa_at_arcanado');
replace into areatrigger_template values (17469, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_arcanado', 0);

replace into spell_areatrigger values (16617, 16617, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16617,'');
replace into areatrigger_template values (16617, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);

-- Lady Ashvane
update creature_template set scriptname='bfa_boss_lady_ashvane' where entry=152236;
update creature_template set scriptname='bfa_npc_coral_growth' where entry=152726;
update creature_template set scriptname='bfa_npc_briny_bubble' where entry=153194;

replace into spell_script_names values (296726,'bfa_spell_barnacle_bash');
replace into spell_script_names values (297402,'bfa_spell_briny_bubble');
replace into spell_script_names values (302989,'bfa_spell_briny_bubble_aura');
replace into spell_script_names values (297397,'bfa_spell_briny_bubble_aura_mythic');
replace into spell_script_names values (296650,'bfa_spell_hardened_carapace_aura');
replace into spell_script_names values (297240,'bfa_spell_hardened_carapace_cast');
replace into spell_script_names values (302855,'bfa_spell_regenerative_coral_dummy');
replace into spell_script_names values (296662,'bfa_spell_rippling_wave_cast');
replace into spell_script_names values (296941,'bfa_spell_arcing_azerite_controller_red_yellow_blue');
replace into spell_script_names values (296942,'bfa_spell_arcing_azerite_controller_red_yellow_blue');
replace into spell_script_names values (296943,'bfa_spell_arcing_azerite_controller_red_yellow_blue');

replace into spell_areatrigger values (17366, 17366, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17366,'bfa_at_regenerative_coral');
replace into areatrigger_template values (17366, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_regenerative_coral', 0);

replace into spell_areatrigger values (16727, 16727, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16727,'bfa_at_cutting_coral_ashvane');
replace into areatrigger_template values (16727, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_cutting_coral_ashvane', 0);

replace into spell_areatrigger values (17327, 17327, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17327,'bfa_at_cutting_coral_growth');
replace into areatrigger_template values (17327, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_cutting_coral_growth', 0);

replace into spell_areatrigger values (17357, 17357, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17357,'bfa_at_empowered_rippling_wave');
replace into areatrigger_template values (17357, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_empowered_rippling_wave', 0);

replace into spell_areatrigger values (16715, 16715, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16715,'bfa_at_rippling_wave');
replace into areatrigger_template values (16715, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_rippling_wave', 0);

-- Orgozoa
update creature_template set scriptname='bfa_boss_orgozoa' where entry=152128;
update creature_template set scriptname='bfa_npc_azshari_witch' where entry=156132;
update creature_template set scriptname='bfa_npc_dreadcoil_hulk' where entry=156133;
update creature_template set scriptname='bfa_npc_hattchery_eggs' where entry=154361;
update creature_template set scriptname='bfa_npc_zanjir_myrmidon' where entry=156131;
update creature_template set scriptname='bfa_npc_zoatroid' where entry=156625;

replace into spell_script_names values (298443,'bfa_spell_amniotic_splatter_filter');
replace into spell_script_names values (295808,'bfa_spell_aqua_lance');
replace into spell_script_names values (298156,'bfa_spell_desensiizing_sting');
replace into spell_script_names values (299095,'bfa_spell_dribbling_ichor');
replace into spell_script_names values (298242,'bfa_spell_incubation_fluid');
replace into spell_script_names values (296691,'bfa_spell_powerful_stomp');
replace into spell_script_names values (298548,'bfa_spell_massive_incubator');

replace into spell_areatrigger values (17048, 17048, 0, 0, 0, 0, 0, 0, 390, 0, 0, 0);
replace into areatrigger_scripts values (17048,'bfa_at_aqua_lance');
replace into areatrigger_template values (17048, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_aqua_lance', 0);

-- Queens Court
replace into spell_areatrigger values (17380, 17380, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17380,'bfa_at_flags_spell');
replace into areatrigger_template values (17380, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_flags_spell', 0);

replace into spell_areatrigger values (17397, 17397, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17397,'bfa_at_form_ranks');
replace into areatrigger_template values (17397, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_form_ranks', 0);

replace into spell_areatrigger values (17071, 17071, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17071,'bfa_at_mighty_rupture');
replace into areatrigger_template values (17071, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_mighty_rupture', 0);

replace into spell_areatrigger values (17067, 17067, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17067,'');
replace into areatrigger_template values (17067, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);

update creature_template set scriptname='bfa_boss_pashmar_the_fanatical' where entry=152852;
update creature_template set scriptname='bfa_boss_silivaz_the_zealous' where entry=152853;
update creature_template set scriptname='bfa_npc_potent_spark' where entry=153335;
update creature_template set scriptname='bfa_npc_decree_controller' where entry=154480;

replace into spell_script_names values (296850,'bfa_spell_fanatical_verdict');
replace into spell_script_names values (299563,'bfa_spell_commanders_fury');
replace into spell_script_names values (297564,'spell_deferred_sentence_periodic');
replace into spell_script_names values (297578,'bfa_spell_deferred_sentence_damage');
replace into spell_script_names values (296851,'bfa_spell_fanatical_verdict_aura');
replace into spell_script_names values (303227,'bfa_spell_form_ranks_damage');
replace into spell_script_names values (299917,'bfa_spell_frenetic_charge_at_create');
replace into spell_script_names values (299915,'bfa_spell_frenetic_charge_cast');
replace into spell_script_names values (300550,'bfa_spell_frenetic_charge_damage');
replace into spell_script_names values (301947,'bfa_spell_potent_spark_cast');
replace into spell_script_names values (301244,'bfa_spell_repeat_performance');
replace into spell_script_names values (297648,'bfa_spell_stand_alone_court');
replace into spell_script_names values (301807,'bfa_spell_zealous_eruption_periodic');

-- Zaqul
replace into spell_areatrigger values (16295, 16295, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16295,'');
replace into areatrigger_template values (16295, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);

replace into spell_areatrigger values (17455, 17455, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17455,'bfa_at_nightmare_pool');
replace into areatrigger_template values (17455, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_nightmare_pool', 0);

replace into spell_areatrigger values (17037, 17037, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17037,'bfa_at_delirium_realm');
replace into areatrigger_template values (17037, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_delirium_realm', 0);

replace into spell_areatrigger values (17018, 17018, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17018,'');
replace into areatrigger_template values (17018, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);

replace into spell_areatrigger values (17303, 17303, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17303,'bfa_at_reality_portal');
replace into areatrigger_template values (17303, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_reality_portal', 0);

-- Mind Tether custom proc entry
replace INTO spell_proc VALUES ('295498', '0', '0', '0', '0', '0', '1048576', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0');

update creature_template set scriptname='bfa_boss_zaqul' where entry=150859;
update creature_template set scriptname='bfa_npc_crushing_grasp_trigger' where entry=151034;
update creature_template set scriptname='bfa_npc_first_arcanist_thalyssra' where entry=152604;
update creature_template set scriptname='bfa_npc_horrific_summoner' where entry=154175;
update creature_template set scriptname='bfa_npc_horrific_vision' where entry=151581;
update creature_template set scriptname='bfa_npc_maddening_eruption_trigger' where entry=151586;
update creature_template set scriptname='bfa_npc_tentacle_delirium' where entry=152574;
update creature_template set scriptname='bfa_npc_echo_of_delirium' where entry=154685;
update creature_template set scriptname='bfa_npc_echo_of_fear' where entry=154682;
update creature_template set scriptname='bfa_npc_horrific_summoner_dark_passage' where entry=154174;
update creature_template set scriptname='bfa_npc_fear_gate' where entry=152192;
update creature_template set scriptname='bfa_npc_teleporter_queen_azshara' where entry=156646;

replace into spell_script_names values (295999,'bfa_spell_caustic_delirium_aura');
replace into spell_script_names values (295498,'bfa_spell_mind_tether_damage_share');
replace into spell_script_names values (301427,'bfa_spell_fear_gate_button');
replace into spell_script_names values (299617,'bfa_spell_fear_gate_cast');
replace into spell_script_names values (294652,'bfa_spell_quivering_claws');
replace into spell_script_names values (301141,'bfa_spell_crushing_grasp_cast');
replace into spell_script_names values (296078,'bfa_spell_dark_pulse_shield');
replace into spell_script_names values (301117,'bfa_spell_dark_shield');
replace into spell_script_names values (295249,'bfa_spell_delirium_realm_aura');
replace into spell_script_names values (294515,'bfa_spell_dark_tear_cast');
replace into spell_script_names values (296262,'bfa_spell_delirium_realm_cast');
replace into spell_script_names values (292963,'bfa_spell_dread_aura');
replace into spell_script_names values (296257,'bfa_spell_fear_realm_cast');
replace into spell_script_names values (295173,'bfa_spell_fear_realm_hysteria');
replace into spell_script_names values (296018,'bfa_spell_manic_dread_aura');
replace into spell_script_names values (296022,'bfa_spell_manic_dread_missile');
replace into spell_script_names values (295498,'bfa_spell_mind_tether_aura');
replace into spell_script_names values (302202,'bfa_spell_return_to_reality_button');
replace into spell_script_names values (295444,'bfa_spell_mind_tether_cast');

-- Queen Azshara

replace into spell_areatrigger values (17064, 17064, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17064,'bfa_at_divide_and_conquer');
replace into areatrigger_template values (17064, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_divide_and_conquer', 0);


replace into spell_areatrigger values (17869, 17869, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17869,'bfa_at_divide_and_conquer');
replace into areatrigger_template values (17869, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_divide_and_conquer', 0);


replace into spell_areatrigger values (17417, 17417, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17417,'');
replace into areatrigger_template values (17417, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);


replace into spell_areatrigger values (17618, 17618, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17618,'');
replace into areatrigger_template values (17618, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);


replace into spell_areatrigger values (17204, 17204, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17204,'');
replace into areatrigger_template values (17204, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);


replace into spell_areatrigger values (17112, 17112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17112,'bfa_at_piercing_gaze');
replace into areatrigger_template values (17112, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_piercing_gaze', 0);

replace into spell_areatrigger values (17468, 17468, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17468,'bfa_at_nether_portal');
replace into areatrigger_template values (17468, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_nether_portal', 0);

replace into spell_areatrigger values (17561, 17561, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17561,'');
replace into areatrigger_template values (17561, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);


replace into spell_areatrigger values (16953, 16953, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16953,'bfa_at_arcane_orb');
replace into areatrigger_template values (16953, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_arcane_orb', 0);


replace into spell_areatrigger values (17448, 17448, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17448,'');
replace into areatrigger_template values (17448, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);


replace into spell_areatrigger values (16869, 16869, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16869,'');
replace into areatrigger_template values (16869, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);


replace into spell_areatrigger values (16848, 16848, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (16848,'bfa_at_cursed_heart');
replace into areatrigger_template values (16848, 0, 0, 5, 5, 0, 0, 0, 0, 'bfa_at_cursed_heart', 0);

replace into spell_areatrigger values (17302, 17302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (17302,'');
replace into areatrigger_template values (17302, 0, 0, 5, 5, 0, 0, 0, 0, '', 0);

update creature_template set scriptname='bfa_boss_queen_azshara' where entry=152910;
update creature_template set scriptname='bfa_npc_ancient_ward' where entry=153175;
update creature_template set scriptname='bfa_npc_aethanel' where entry=153059;
update creature_template set scriptname='bfa_npc_azshara_indomitable_devoted' where entry in (155354,154240);
update creature_template set scriptname='bfa_npc_crushing_depths_stalker' where entry=155845;
update creature_template set scriptname='bfa_npc_cyranus' where entry=153060;
update creature_template set scriptname='bfa_npc_loyal_myrmidon' where entry=154565;
update creature_template set scriptname='bfa_npc_overzealous_hulk' where entry=155643;
update creature_template set scriptname='bfa_npc_tidemistresses' where entry in (153090,153091,153092);
update creature_template set scriptname='bfa_npc_titan_console' where entry=154959;

replace into spell_script_names values (303657,'bfa_spell_arcane_burst_aura');
replace into spell_script_names values (300807,'bfa_spell_overload_dummy');
replace into spell_script_names values (303629,'bfa_spell_arcane_burst_dummy');
replace into spell_script_names values (304475,'bfa_spell_arcane_jolt');
replace into spell_script_names values (300502,'bfa_spell_arcane_mastery_periodic');
replace into spell_script_names values (299094,'bfa_spell_beckon_cast');
replace into spell_script_names values (297898,'bfa_spell_cursed_heart');
replace into spell_script_names values (307331,'bfa_spell_divide_and_conquer_cast');
replace into spell_script_names values (305415,'bfa_spell_divide_and_conquer_kill');
replace into spell_script_names values (298531,'bfa_spell_ground_pound');
replace into spell_script_names values (297934,'bfa_spell_longing');
replace into spell_script_names values (304260,'bfa_spell_longing_aura');
replace into spell_script_names values (299252,'bfa_spell_march');
replace into spell_script_names values (299253,'bfa_spell_stay');
replace into spell_script_names values (303987,'bfa_spell_nether_portal_dummy');
replace into spell_script_names values (297937,'bfa_spell_painful_memories');
replace into spell_script_names values (304267,'bfa_spell_painful_memories_aura');