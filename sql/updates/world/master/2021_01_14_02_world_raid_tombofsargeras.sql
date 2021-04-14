-- demonic inquisition
update creature_template set scriptname='boss_demonic_inquisition' where entry in (116689, 116691);
update creature_template set scriptname='npc_tos_tormented_soul' where entry=117957;

replace into spell_script_names values (233652,'spell_tos_confess');
replace into spell_script_names values (233104,'spell_tos_torment');
replace into spell_script_names values (233435,'spell_tos_calcified_quils');
replace into spell_script_names values (235295,'spell_tos_adherent_fragment');

-- desolate host
update creature_template set scriptname='boss_the_desolate_host_generic' where entry=120988;
update creature_template set scriptname='npc_tos_engine_of_souls' where entry=118460;
update creature_template set scriptname='npc_tos_soul_queen_dejahna' where entry=118462;
update creature_template set scriptname='npc_tos_desolate_host' where entry=119072;
update creature_template set scriptname='npc_tos_spiritual_font' where entry=118701;
update creature_template set scriptname='npc_tos_reanimated_templar' where entry in (118715, 119938);
update creature_template set scriptname='npc_tos_ghastly_bonewarden' where entry in (118728, 119939);
update creature_template set scriptname='npc_tos_fallen_priestess' where entry in (118729, 119940);
update creature_template set scriptname='npc_tos_soul_residue' where entry=118730;
update creature_template set scriptname='npc_tos_tormented_cries' where entry=118924;

replace into spell_script_names values (236673,'spell_tos_quietus_filter');
replace into spell_script_names values (236465,'spell_tos_soulbind_finder');
replace into spell_script_names values (245611,'spell_tos_soulbind_visual_finder');
replace into spell_script_names values (245612,'spell_tos_soulbind_visual_finder');
replace into spell_script_names values (236568,'spell_tos_sundering_doom');
replace into spell_script_names values (236567,'spell_tos_sundering_doom');
replace into spell_script_names values (236564,'spell_tos_sundering_doom');
replace into spell_script_names values (236563,'spell_tos_sundering_doom');
replace into spell_script_names values (239015,'spell_tos_dissonance');
replace into spell_script_names values (239014,'spell_tos_dissonance');
replace into spell_script_names values (239006,'spell_tos_dissonance_filter');
replace into spell_script_names values (239007,'spell_tos_dissonance_filter');
replace into spell_script_names values (235933,'spell_tos_spear_of_anguish');
replace into spell_script_names values (242796,'spell_tos_spear_of_anguish');
replace into spell_script_names values (238585,'spell_tos_bound_essence');
replace into spell_script_names values (235923,'spell_tos_spear_of_anguish_filter');
replace into spell_script_names values (235988,'spell_tos_tormented_cries_filter');
replace into spell_script_names values (236459,'spell_tos_soulbind');
replace into spell_script_names values (236515,'spell_tos_shattering_scream');
replace into spell_script_names values (235113,'spell_tos_spiritual_barrier_dissonance');
replace into spell_script_names values (235620,'spell_tos_spiritual_barrier_dissonance');
replace into spell_script_names values (235732,'spell_tos_spiritual_barrier_dissonance');
replace into spell_script_names values (235734,'spell_tos_spiritual_barrier_dissonance');

replace into spell_areatrigger values (966000, 966000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (966000,'at_tos_spirit_presence');
replace into areatrigger_template values (966000, 0, 0, 5, 5, 0, 0, 0, 0, 'at_tos_spirit_presence', 0);

-- fallen avatar
update creature_template set scriptname='boss_fallen_avatar' where entry=116939;
update creature_template set scriptname='npc_avatara_maiden' where entry=117264;
update creature_template set scriptname='npc_avatara_pilones' where entry=117279;
update creature_template set scriptname='npc_tos_touch_of_sargeras' where entry=120838;
update creature_template set scriptname='npc_tos_rain_of_destroyer' where entry=120961;

replace into spell_script_names values (235572,'spell_tos_rupture_realistic');
replace into spell_script_names values (239132,'spell_tos_rupture_realistic');
replace into spell_script_names values (239742,'spell_tos_dark_mark');
replace into spell_script_names values (234873,'spell_tos_avatara_energy');
replace into spell_script_names values (238460,'spell_tos_shadow_blades');
replace into spell_script_names values (239417,'spell_tos_black_winds');
replace into spell_script_names values (236682,'spell_tos_fel_infusion');
replace into spell_script_names values (239739,'spell_tos_black_mark_aura');

-- goroth
update creature_template set scriptname='boss_goroth' where entry=115844;
update creature_template set scriptname='npc_goroth_ember_stalker' where entry=115892;
update creature_template set scriptname='npc_goroth_infernal_spike' where entry=116976;
update creature_template set scriptname='npc_goroth_lava_stalker' where entry=117931;
update creature_template set scriptname='npc_goroth_brimstone_infernal' where entry=119950;

replace into spell_script_names values (233024,'spell_tos_goroth_crashing_comet');
replace into spell_script_names values (238588,'spell_tos_goroth_rain_of_brimstone');
replace into spell_script_names values (237333,'spell_tos_goroth_energy_tracker');
replace into spell_script_names values (234386,'spell_tos_goroth_fel_periodic_trigger');

replace into spell_areatrigger values (13526, 13526, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (13526,'at_goroth_fel_pool');
replace into areatrigger_template values (13526, 0, 0, 5, 5, 0, 0, 0, 0, 'at_goroth_fel_pool', 0);

replace into criteria_data values (36337,0,0,0,'achievement_fel_turkey');

-- harjatan
update creature_template set scriptname='boss_harjatan' where entry=116407;
update creature_template set scriptname='npc_mistress_sasszine' where entry=121184;
update creature_template set scriptname='npc_elder_murk_eye' where entry=121071;
update creature_template set scriptname='npc_tos_tadpole' where entry=121155;

replace into spell_script_names values (231854,'spell_tos_unchecked_rage');
replace into spell_script_names values (234016,'spell_tos_fixate');
replace into spell_script_names values (232061,'spell_tos_draw_in');

-- kiljaeden
update creature_template set scriptname='boss_tos_kiljaeden' where entry=117269;
update creature_template set scriptname='npc_tos_armageddon_stalker' where entry=120839;
update creature_template set scriptname='npc_tos_erupting_reflection' where entry=119206;
update creature_template set scriptname='npc_tos_wailing_reflection' where entry=119107;
update creature_template set scriptname='npc_tos_hopeless_reflection' where entry=119663;
update creature_template set scriptname='npc_tos_shadowsoul' where entry=121193;
update creature_template set scriptname='npc_tos_stage4_illidan_stormrage' where entry=121227;
update creature_template set scriptname='npc_tos_demonic_obelisk' where entry=120270;
update creature_template set scriptname='npc_tos_nether_rift' where entry=120390;
update creature_template set scriptname='npc_tos_flaming_orb' where entry=120082;

replace into spell_script_names values (238502,'spell_tos_focused_dreadflame');
replace into spell_script_names values (242074,'spell_tos_destabilized_shadowsoul');
replace into spell_script_names values (238999,'spell_tos_darkness_thousand_souls');
replace into spell_script_names values (239280,'spell_tos_flaming_orb_fixate');
replace into spell_script_names values (243625,'spell_tos_lingering_wail_jump');
replace into spell_script_names values (237728,'spell_tos_hopelessness');
replace into spell_script_names values (239154,'spell_tos_gravity_squeeze');
replace into spell_script_names values (243536,'spell_tos_lingering_eruption');
replace into spell_script_names values (243624,'spell_tos_lingering_wail');

replace into spell_areatrigger values (15121,15121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (15121,'at_tos_armageddon');
replace into areatrigger_template values (15121, 0, 0, 5, 5, 0, 0, 0, 0, 'at_tos_armageddon', 0);

replace into spell_areatrigger values (14915,14915, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (14915,'at_tos_flaming_detonation');
replace into areatrigger_template values (14915, 0, 0, 5, 5, 0, 0, 0, 0, 'at_tos_flaming_detonation', 0);

replace into spell_areatrigger values (1027000,1027000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (1027000,'at_tos_hopelessness');
replace into areatrigger_template values (1027000, 0, 0, 5, 5, 0, 0, 0, 0, 'at_tos_hopelessness', 0);

replace into criteria_data values (36478,0,0,0,'achievement_dark_souls');

-- maiden of vigilance
update creature_template set scriptname='boss_maiden_of_vigilance' where entry=118289;
update creature_template set scriptname='npc_tos_essences' where entry in (118640,118643);
update creature_template set scriptname='npc_tos_essences_intro' where entry in (120132, 120131);

replace into spell_script_names values (235271,'spell_tos_infusion');
replace into spell_script_names values (248812,'spell_tos_blowback');
replace into spell_script_names values (236432,'spell_tos_wrath_of_the_creators');
replace into spell_script_names values (234896,'spell_tos_wrath_of_the_creators');
replace into spell_script_names values (235117,'spell_tos_unstable_soul');
replace into spell_script_names values (235213,'spell_tos_infusions');
replace into spell_script_names values (235240,'spell_tos_infusions');
replace into spell_script_names values (241593,'spell_egvin_levitation');

-- sasszine
update creature_template set scriptname='boss_mistress_sasszine' where entry=115767;
update creature_template set scriptname='npc_sasszine_abyss_stalker' where entry=115795;
update creature_template set scriptname='npc_sasszine_slicing_tornado' where entry=118286;
update creature_template set scriptname='npc_sasszine_razorjaw_waverunner' where entry=115902;
update creature_template set scriptname='npc_sasszine_electrifying_jellyfish' where entry=115896;
update creature_template set scriptname='npc_sasszine_sarukel' where entry=116843;
update creature_template set scriptname='npc_sasszine_ossunet' where entry=116881;
update creature_template set scriptname='npc_sasszine_piranhado' where entry=116841;
update creature_template set scriptname='npc_sasszine_delicious_bufferfish' where entry=119791;

replace into spell_script_names values (230143,'spell_sasszine_hydra_shot_filter');
replace into spell_script_names values (230201,'spell_sasszine_burden_of_pain');
replace into spell_script_names values (239369,'spell_sasszine_delicious_bufferfish');
replace into spell_script_names values (232913,'spell_sasszine_befouling_ink');

replace into criteria_data values (36143,0,0,0,'achievement_sasszine_hydra');
replace into criteria_data values (36144,0,0,0,'achievement_sasszine_tartar');
replace into criteria_data values (36146,0,0,0,'achievement_sasszine_sauce');
replace into criteria_data values (36145,0,0,0,'achievement_sasszine_murloc');
replace into criteria_data values (36147,0,0,0,'achievement_sasszine_player');

-- sisters of moon
update creature_template set scriptname='boss_sisters_of_the_moon' where entry=118182;
update creature_template set scriptname='npc_sister_kasparian' where entry=118523;
update creature_template set scriptname='npc_sister_lunaspyre' where entry=118518;
update creature_template set scriptname='npc_sister_yathae' where entry=118374;
update creature_template set scriptname='npc_sistersmoon_moontalon' where entry=119054;
update creature_template set scriptname='npc_sistersmoon_glaive_target' where entry=119054;
update creature_template set scriptname='npc_sistersmoon_twilight_soul' where entry=121498;

replace into spell_script_names values (236306,'spell_sistersmoon_incorporeal_shot_filter');
replace into spell_script_names values (239385,'spell_sistersmoon_glaive_storm_filter');
replace into spell_script_names values (239378,'spell_sistersmoon_glaive_storm_filter');
replace into spell_script_names values (239382,'spell_sistersmoon_glaive_storm_filter');
replace into spell_script_names values (234998,'spell_sistersmoon_astral_purge');
replace into spell_script_names values (233263,'spell_sistersmoon_embrace_eclipse');
replace into spell_script_names values (233264,'spell_sistersmoon_embrace_eclipse');
replace into spell_script_names values (234664,'spell_sistersmoon_side_moon');
replace into spell_script_names values (234668,'spell_sistersmoon_side_moon');
replace into spell_script_names values (236717,'spell_sistersmoon_lunar_barrage');


replace into spell_areatrigger values (14930,14930, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (14930,'at_sistersmoon_glaive_storm');
replace into areatrigger_template values (14930, 0, 0, 5, 5, 0, 0, 0, 0, 'at_sistersmoon_glaive_storm', 0);

replace into spell_areatrigger values (14929,14929, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (14929,'at_tos_hopelessness');
replace into areatrigger_template values (14929, 0, 0, 5, 5, 0, 0, 0, 0, 'at_sistersmoon_glaive_storm', 0);

replace into spell_areatrigger values (14928,14928, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (14928,'at_sistersmoon_glaive_storm');
replace into areatrigger_template values (14928, 0, 0, 5, 5, 0, 0, 0, 0, 'at_sistersmoon_glaive_storm', 0);