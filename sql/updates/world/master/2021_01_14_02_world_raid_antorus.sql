-- aggramar 
update creature_template set scriptname='boss_aggramar' where entry=121975;
update creature_template set scriptname='npc_aggramar_ember_of_taeshalach' where entry=122532;
update creature_template set scriptname='npc_aggramar_flame_of_taeshalach' where entry=121985;

replace into spell_script_names values (244792,'spell_aggramar_energize_periodic');
replace into spell_script_names values (245911,'spell_aggramar_wrought_in_flame');
replace into spell_script_names values (244678,'spell_aggramar_meteor_swarm');
replace into spell_script_names values (254452,'spell_aggramar_ravenous_blaze');
replace into spell_script_names values (245458,'spell_aggramar_foe_breaker_filter');
replace into spell_script_names values (255059,'spell_aggramar_foe_breaker_filter');
replace into spell_script_names values (244033,'spell_aggramar_flame_rend_filter');
replace into spell_script_names values (247079,'spell_aggramar_flame_rend_filter');
replace into spell_script_names values (245993,'spell_aggramar_scorching_blaze_filter');
replace into spell_script_names values (246037,'spell_aggramar_flare_filter');
replace into spell_script_names values (245983,'spell_aggramar_flare_filter');
replace into spell_script_names values (246054,'spell_aggramar_command_empowered_flare');
replace into spell_script_names values (246055,'spell_aggramar_command_empowered_flare');
replace into spell_script_names values (246056,'spell_aggramar_command_empowered_flare');

-- antoran
update creature_template set scriptname='boss_antoran_high_command' where entry=122637;
update creature_template set scriptname='boss_antoran_high_command_generic' where entry=122367;
update creature_template set scriptname='npc_command_entropic_mine' where entry=122992;
update creature_template set scriptname='npc_command_reinforcements' where entry in (122890, 122718);
update creature_template set scriptname='npc_command_legion_cruiser' where entry=122867;
update creature_template set scriptname='npc_command_felshield_emitter' where entry=122867;
update creature_template set scriptname='npc_command_disruptor_beacon' where entry=122884;
update creature_template set scriptname='npc_command_screaming_shrike' where entry=128069;

replace into spell_script_names values (245027,'spell_command_withering_fire');
replace into spell_script_names values (244418,'spell_command_player_chaos_pulse');
replace into spell_script_names values (257976,'spell_command_chaos_pulse_filter');
replace into spell_script_names values (245304,'spell_command_entropic_mine');
replace into spell_script_names values (255140,'spell_command_felshield_or_beacon');
replace into spell_script_names values (255147,'spell_command_felshield_or_beacon');
replace into spell_script_names values (244627,'spell_command_fusillade');
replace into spell_script_names values (244172,'spell_command_psychic_assault');

-- argus
update creature_template set scriptname='boss_argus' where entry=124828;
update creature_template set scriptname='npc_argus_titans_generic' where entry in (126268, 125886, 125893, 126266, 126267);
update creature_template set scriptname='npc_argus_soulblight_orb' where entry=125008;
update creature_template set scriptname='npc_arugs_edge_of_obliteration' where entry in (126828, 130842);
update creature_template set scriptname='npc_argus_constellar_designate' where entry=127192;
update creature_template set scriptname='npc_argus_gift_of_the_lifebinder' where entry=129386;
update creature_template set scriptname='npc_argus_hungering_soul' where entry=129635;
update creature_template set scriptname='npc_argus_reorigination_module' where entry in (127809, 130179);
update creature_template set scriptname='npc_argus_mote_of_titanic_power' where entry=129722;
update creature_template set scriptname='npc_argus_chains_of_sargeras' where entry=130202;

replace into spell_script_names values (258041,'spell_argus_p1_energize_periodic');
replace into spell_script_names values (258042,'spell_argus_p2_energize_periodic');
replace into spell_script_names values (258044,'spell_argus_p4_energize_periodic');
replace into spell_script_names values (256388,'spell_argus_initialization_sequence_periodic');
replace into spell_script_names values (258029,'spell_argus_initialization_sequence_periodic');
replace into spell_script_names values (255200,'spell_argus_aggramar_boon');
replace into spell_script_names values (257214,'spell_argus_titanforging_energize_periodic');
replace into spell_script_names values (257213,'spell_argus_titanforging_energize_periodic');
replace into spell_script_names values (253026,'spell_argus_impending_inevitability');
replace into spell_script_names values (255594,'spell_argus_sky_and_sea');
replace into spell_script_names values (256674,'spell_argus_golganneth_wrath');
replace into spell_script_names values (255646,'spell_argus_golganneth_wrath_filter');
replace into spell_script_names values (258043,'spell_argus_volatile_soul_filter');
replace into spell_script_names values (252280,'spell_argus_volatile_soul_filter');
replace into spell_script_names values (251571,'spell_argus_soul_detonation');
replace into spell_script_names values (251572,'spell_argus_soul_detonation');
replace into spell_script_names values (258068,'spell_argus_sargeras_gaze');
replace into spell_script_names values (258207,'spell_argus_apocalypsis_module');
replace into spell_script_names values (258838,'spell_argus_soulrending_scythe_script');
replace into spell_script_names values (258839,'spell_argus_rent_soul');

-- coven shivarres
update creature_template set scriptname='boss_coven_shivarres' where entry=128311;
update creature_template set scriptname='boss_coven_shivarres_generic' where entry in (122467, 122468, 122469, 125436);
update creature_template set scriptname='npc_coven_torment_generic' where entry in (125837, 123503, 124164, 124166);
update creature_template set scriptname='npc_coven_whirling_saber' where entry=123348;
update creature_template set scriptname='npc_coven_shadow_blade' where entry=123086;
update creature_template set scriptname='npc_coven_cosmic_glare' where entry=126320;

replace into spell_script_names values (258069,'spell_coven_fury_subsides');
replace into spell_script_names values (250752,'spell_coven_cosmic_glare');
replace into spell_script_names values (250824,'spell_coven_cosmic_glare_dmg');
replace into spell_script_names values (245586,'spell_coven_chilled_blood');
replace into spell_script_names values (253697,'spell_coven_orb_of_frost');

-- eonar
update creature_template set scriptname='boss_eonar' where entry=122500;
update creature_template set scriptname='npc_eonar_the_paraxis' where entry=124445;
update creature_template set scriptname='npc_eonar_trash_generic' where entry in (123452, 123451, 123191, 124227, 123760, 124207, 123726);
update creature_template set scriptname='npc_eonar_spear_of_doom' where entry=125319;
update creature_template set scriptname='npc_eonar_paraxis_inquisitor' where entry=125429;
update creature_template set scriptname='npc_eonar_focusing_crystal' where entry in (125917, 125918, 125919, 125920);

replace into spell_script_names values (246313,'spell_eonar_paraxis_artillery');
replace into spell_script_names values (249934,'spell_eonar_paraxis_purge_filter');
replace into spell_script_names values (248861,'spell_eonar_spear_of_doom_filter');
replace into spell_script_names values (248326,'spell_eonar_rain_of_fel_filter');
replace into spell_script_names values (249103,'spell_eonar_paraxis_teleport');
replace into spell_script_names values (245781,'spell_eonar_surge_of_life');
replace into spell_script_names values (248225,'spell_eonar_jump_pad');
replace into spell_script_names values (248225,'spell_eonar_dive_down_jump');
replace into spell_script_names values (254497,'spell_eonar_dive_down_jump');
replace into spell_script_names values (246330,'spell_eonar_swift_feet');
replace into spell_script_names values (246301,'spell_eonar_artillery_mode');
replace into spell_script_names values (250081,'spell_eonar_shatter');

-- felhounds
update creature_template set scriptname='npc_felhounds_shatug' where entry=122135;
update creature_template set scriptname='npc_felhounds_fharg' where entry=122477;

replace into spell_script_names values (244441,'spell_felhounds_desolate_path');
replace into spell_script_names values (244069,'spell_felhounds_weight_of_darkness');
replace into spell_script_names values (244071,'spell_felhounds_weight_of_darkness_fear_filter');
replace into spell_script_names values (244471,'spell_felhounds_corruption_filter');
replace into spell_script_names values (244578,'spell_felhounds_corruption_filter');
replace into spell_script_names values (244072,'spell_felhounds_molten_touch_filter');
replace into spell_script_names values (245149,'spell_felhounds_shadowscar_filter');
replace into spell_script_names values (244130,'spell_felhounds_consuming_detonation');
replace into spell_script_names values (244159,'spell_felhounds_consuming_sphere_filter');
replace into spell_script_names values (244054,'spell_felhounds_touched_proc');
replace into spell_script_names values (244055,'spell_felhounds_touched_proc');
replace into spell_script_names values (244072,'spell_felhounds_molten_touch');
replace into spell_script_names values (244086,'spell_felhounds_molten_touch_periodic');
replace into spell_script_names values (254429,'spell_felhounds_weight_of_darkness_periodic');
replace into spell_script_names values (244050,'spell_felhounds_destroyers_boon_energize');
replace into spell_script_names values (246057,'spell_felhounds_sargeras_blessing');

-- hasabel
update creature_template set scriptname='boss_hasabel' where entry=122104;
update creature_template set scriptname='npc_hasabel_gateways' where entry in (122494, 122533, 122543, 122555, 122558, 122559);
update creature_template set scriptname='npc_hasabel_guards' where entry in (122211, 122212, 122213); -- custom?
update creature_template set scriptname='npc_hasabel_collapsing_world' where entry=122425;
update creature_template set scriptname='npc_hasabel_felcrush_portal' where entry=122438;
update creature_template set scriptname='npc_hasabel_transport_portal' where entry=122761;
update creature_template set scriptname='npc_hasabel_portal_summon' where entry in (122783, 123223, 123702);
update creature_template set scriptname='npc_hasabel_everburning_flames' where entry in (122733, 123003);
update creature_template set scriptname='npc_hasabel_felsilk_web' where entry=122897;

replace into spell_script_names values (244021,'spell_hasabel_bursting_darkness');
replace into spell_script_names values (247143,'spell_hasabel_energize');
replace into spell_script_names values (244687,'spell_hasabel_transport_portal');
replace into spell_script_names values (244613,'spell_hasabel_everburning_flames');
replace into spell_script_names values (244949,'spell_hasabel_felsilk_wrap');
replace into spell_script_names values (246316,'spell_hasabel_poison_essence');
replace into spell_script_names values (244915,'spell_hasabel_leech_essence');
replace into spell_script_names values (245118,'spell_hasabel_cloying_shadows');
replace into spell_script_names values (245075,'spell_hasabel_hungering_gloom');
replace into spell_script_names values (244849,'spell_hasabel_caustic_slime');

-- imonar
update creature_template set scriptname='boss_imonar' where entry=124158;
update creature_template set scriptname='npc_imonar_ship_generic' where entry in (124704, 124889);
update creature_template set scriptname='npc_imonar_traps' where entry=124928;

replace into spell_script_names values (250256,'spell_imonar_electrify');
replace into spell_script_names values (250078,'spell_imonar_electrify');
replace into spell_script_names values (248995,'spell_imonar_jetpacks');
replace into spell_script_names values (248194,'spell_imonar_jetpacks');

-- kingaroth
update creature_template set scriptname='boss_kingaroth' where entry=122578;
update creature_template set scriptname='npc_kingaroth_detonation_charge' where entry=122585;
update creature_template set scriptname='npc_kingaroth_ruiner' where entry=124230;
update creature_template set scriptname='npc_kingaroth_incinerator_stalker' where entry=124879;
update creature_template set scriptname='npc_kingaroth_infernal_tower' where entry=122634;
update creature_template set scriptname='npc_kingaroth_apocalypse_blast_stalker' where entry=125462;
update creature_template set scriptname='npc_kingaroth_garothi' where entry in (123906, 123921, 123929);
update creature_template set scriptname='npc_kingaroth_annihilation_trigger' where entry in (124160, 125646);

replace into spell_script_names values (246754,'spell_kingaroth_diabolic_bomb');
replace into spell_script_names values (246779,'spell_kingaroth_diabolic_bomb_dmg');
replace into spell_script_names values (248303,'spell_kingaroth_energize_periodic');
replace into spell_script_names values (246516,'spell_kingaroth_apocalypse_protocol');
replace into spell_script_names values (246504,'spell_kingaroth_initializing');

replace into spell_areatrigger values (11149, 15701, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (11149,'at_kingaroth_annihilation');
replace into areatrigger_template values (11149, 0, 0, 5, 5, 0, 0, 0, 0, 'at_kingaroth_annihilation', 0);

replace into spell_areatrigger values (10875, 15701, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (10875,'at_kingaroth_annihilation');
replace into areatrigger_template values (10875, 0, 0, 5, 5, 0, 0, 0, 0, 'at_kingaroth_annihilation', 0);

-- varimathras
update creature_template set scriptname='boss_varimathras' where entry=122366;
update creature_template set scriptname='npc_shadow_of_varimathras' where entry in (122590, 122643);

replace into spell_script_names values (244697,'spell_varimathras_energy_gain');
replace into spell_script_names values (243957,'spell_varimathras_control_aura');
replace into spell_script_names values (243980,'spell_varimathras_torment_of_fel');
replace into spell_script_names values (244097,'spell_varimathras_necrotic_embrace');

-- worldbreaker
update creature_template set scriptname='boss_worldbreaker' where entry=122450;
update creature_template set scriptname='npc_worldbreaker_annihilation_trigger' where entry in (122818, 124330);
update creature_template set scriptname='npc_worldbreaker_annihilation_decimator' where entry in (122773, 122778);
update creature_template set scriptname='npc_worldbreaker_surging_fel_trigger' where entry in (124167, 128429);
update creature_template set scriptname='npc_atbt_annihilator' where entry=123398;

replace into spell_script_names values (244761,'spell_worldbreaker_annihilation_dmg');
replace into spell_script_names values (247044,'spell_worldbreaker_annihilation_dmg');
replace into spell_script_names values (244969,'spell_worldbreaker_eradication');
replace into spell_script_names values (244399,'spell_worldbreaker_decimation_filter');
replace into spell_script_names values (246919,'spell_worldbreaker_decimation_filter');
replace into spell_script_names values (246360,'spell_worldbreaker_searing_barrage_filter');
replace into spell_script_names values (244536,'spell_worldbreaker_fel_bombardment');
replace into spell_script_names values (244152,'spell_worldbreaker_apocalypse_drive');
replace into spell_script_names values (244106,'spell_worldbreaker_carnage');


replace into spell_areatrigger values (10662, 15496, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
replace into areatrigger_scripts values (10662,'at_worldbreaker_annihilation');
replace into areatrigger_template values (10662, 0, 0, 5, 5, 0, 0, 0, 0, 'at_worldbreaker_annihilation', 0);