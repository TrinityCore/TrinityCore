UPDATE creature_template SET ScriptName="npc_nithogg_electrical_storm" WHERE entry=107338;
UPDATE creature_template SET ScriptName="npc_nithogg_static_orb" WHERE entry=107353;
UPDATE creature_template SET ScriptName="npc_shroud_hound" WHERE entry=97119;
UPDATE creature_template SET ScriptName="npc_kayn_sunfury_welcome" WHERE entry=93011;
UPDATE creature_template SET ScriptName="npc_seacursed_soulkeeper" WHERE entry=97200;
UPDATE creature_template SET ScriptName="npc_seacursed_slaver" WHERE entry=97043;
UPDATE creature_template SET ScriptName="npc_seacursed_swiftblade" WHERE entry=98919;
UPDATE creature_template SET ScriptName="npc_waterlogged_soul_guard" WHERE entry=99188;
UPDATE creature_template SET ScriptName="npc_helarjar_champion" WHERE entry=97097;
UPDATE creature_template SET ScriptName="npc_skjal_maw" WHERE entry=99307;
UPDATE creature_template SET ScriptName="npc_bane_skeleton" WHERE entry=98246;
UPDATE creature_template SET ScriptName="npc_bane_sphere" WHERE entry=97099;
UPDATE creature_template SET ScriptName="npc_helya_maw_destructor_tentacle" WHERE entry=99801;
UPDATE creature_template SET ScriptName="npc_darkmoon_rabbit_ird" WHERE entry=58336;
UPDATE creature_template SET ScriptName="npc_groog" WHERE entry=80167;
UPDATE creature_template SET ScriptName="npc_gara" WHERE entry=85645;
UPDATE creature_template SET ScriptName="npc_void_gara" WHERE entry=88707;
UPDATE creature_template SET ScriptName="npc_gara_void_creature" WHERE entry=88711;
UPDATE creature_template SET ScriptName="npc_gara_void_creature" WHERE entry=88712;
UPDATE creature_template SET ScriptName="npc_xan_void_realm" WHERE entry=88713;
UPDATE creature_template SET ScriptName="mob_CapturedMiner" WHERE entry=74355;
UPDATE creature_template SET ScriptName="venom_sprayer" WHERE entry=86547;
UPDATE creature_template SET ScriptName="npc_shadowmoon_burial_grounds_creature_carrion_worm" WHERE entry=76057;
UPDATE creature_template SET ScriptName="npc_shadowmoon_burial_grounds_necrotic_pitch" WHERE entry=76191;
UPDATE creature_template SET ScriptName="boss_nerzul" WHERE entry=76407;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_nerzul_prop" WHERE entry=79497;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_initial_teleport" WHERE entry=342521;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_omen_of_death" WHERE entry=76462;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_ritual_of_bones" WHERE entry=76518;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_ritual_of_bones_darkness_trigger" WHERE entry=534556;
UPDATE creature_template SET ScriptName="boss_nhalish" WHERE entry=75829;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_nhalish_prop" WHERE entry=75442;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_soul" WHERE entry=75899;
UPDATE creature_template SET ScriptName="boss_sadana_bloodfury" WHERE entry=75509;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_creature_defiled_spirit" WHERE entry=75966;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_creature_falling_dagger" WHERE entry=75981;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_creature_shadow_rune" WHERE entry=75778;
UPDATE creature_template SET ScriptName="shadowmoon_burial_grounds_creature_eclipse_trigger" WHERE entry=76052;
UPDATE creature_template SET ScriptName="npc_av_marshal_or_warmaster" WHERE entry IN (14762,14763,14764,14765,14772,14773,14776,14777);

DELETE FROM spell_script_names WHERE spell_id IN (212889,212837,212841,212867,212836,102112,46668,101260,101604,101612,169421,148852,177297,177301,188520,158564,150004,149941,150324,149975,150032,150045,150011,167738,164615,151990,151581,150759,150801,151698,152809,164546,167967,168375,168376,168378,166562,177733,177732,164294,164556,169382,169267,169390,169125,169120,169251,165113,169486,172576,164967,170411,172610,169847,170016,170665,170400,153686,169233,153689,154010,153068,153623,152962,152792,152801,153153,164685,164686,153268,156682,150007,150306,169563,165578,153224);
INSERT INTO spell_script_names (spell_id, ScriptName) VALUES 
(212889, "spell_nithogg_static_charge_summon"),
(212837, "spell_nithogg_crackling_jolt_target"),
(212841, "spell_nithogg_crackling_jolt_damage"),
(212867, "spell_nithogg_electrical_storm_target"),
(212836, "spell_nithogg_tail_lash"),
(102112, "spell_darkmoon_canon_preparation"),
(46668,  "spell_darkmoon_carousel_whee"),
(101260, "spell_darkmoon_staging_area_teleport"),
(101604, "spell_whack_gnoll_whack"),
(101612, "spell_whack_gnoll_override_action"),
(169421, "spell_frostridge_claiming"),
(148852, "spell_groog_rampage"),
(177301, "spell_use_effigy"),
(177297, "spell_aura_void_realm"),
(188520, "spell_tanaan_fel_sludge"),
(158564, "spell_deathtalon_quills"),
(150004, "spell_magma_barrage"),
(149941, "spell_rough_smash"),
(150324, "spell_shatter_earth"),
(149975, "spell_dancing_flames"),
(150032, "spell_withering_flames"),
(150045, "spell_molten_impact"),
(150011, "spell_magma_barrage_damage"),
(167738, "spell_roltall_scorching_aura"),
(164615, "spell_bloodmaul_channel_flames"),
(151990, "spell_ChainGrip"),
(151581, "spell_SuppressionField"),
(150759, "spell_FerociousYell"),
(150801, "spell_RaiseTheMiners"),
(151698, "spell_VolcanicEruption"),
(152809, "spell_LavaSplash"),
(164546, "spell_pilar_of_flames"),
(167967, "spell_bramble_patch"),
(168375, "spell_grasping_vine"),
(168376, "aura_grasping_vine"),
(168378, "spell_grasping_vine_jump"),
(166562, "spell_firebloom_target"),
(177733, "spell_agitated_water_trig"),
(177732, "spell_agitated_water"),
(164294, "spell_unchecked_growth"),
(169382, "spell_gaseous_volley"),
(169267, "spell_toxic_blood"),
(169125, "spell_genesis"),
(169390, "spell_genesis_missile"),
(169120, "spell_font_life"),
(169251, "spell_entanglement_missile"),
(165113, "spell_barrage_of_leaves"),
(169563, "spell_growth"),
(169486, "spell_enraged_growth"),
(172576, "spell_bounding_whirl"),
(164967, "spell_choking_vines"),
(170411, "spell_spore_breath"),
(172610, "spell_black_hole"),
(169847, "spell_frozen_snap"),
(170016, "aura_glowbulb_pollen"),
(170665, "aura_barrier"),
(170400, "spell_vine_pull"),
(153686, "spell_shadowmoon_burial_grounds_body_slam"),
(169233, "spell_inhale"),
(153689, "spell_shadowmoon_burial_grounds_necrotic_pitch"),
(165578, "spell_shadowmoon_burial_grounds_corpse_breath"),
(154010, "spell_shadowmoon_burial_grounds_drowned"),
(153068, "spell_shadowmoon_burial_grounds_void_devestation_trigger"),
(153623, "spell_shadowmoon_burial_grounds_planar_shift"),
(152962, "spell_shadowmoon_burial_grounds_soul_steal"),
(152792, "spell_shadowmoon_burial_grounds_void_blast"),
(152801, "spell_shadowmoon_burial_grounds_void_vortex"),
(153153, "spell_shadowmoon_burial_grounds_dark_communion"),
(164685, "spell_shadowmoon_burial_grounds_dark_eclipse"),
(164686, "spell_shadowmoon_burial_grounds_dark_eclipse_damage"),
(153224, "spell_shadowmoon_burial_grounds_shadow_burn"),
(153268, "spell_exhume_the_crypts"),
(156682, "spell_water_burst_targeting"),
(150007, "spell_magma_barrage_trigger"),
(150306, "spell_magma_barrage_trigger");

UPDATE gameobject_template SET ScriptName="go_tonk_console" WHERE entry=209342;
UPDATE gameobject_template SET ScriptName="go_spirit_effigy" WHERE entry=237944;
UPDATE gameobject_template SET ScriptName="go_shadowmoon_voidblade" WHERE entry=238853;
UPDATE gameobject_template SET ScriptName="go_shadowmoon_voidblade" WHERE entry=238853;

DELETE FROM areatrigger_scripts WHERE entry IN (172189,164556,169224,183790,153072,152684,152691,170038);
INSERT INTO areatrigger_scripts (entry, ScriptName) VALUES
(172189, "areatrigger_aqualir_submerge"),
(164556, "at_unchecked_growth"),
(169224, "at_toxic_gas"),
(183790, "areatrigger_black_hole"),
(153072, "areatrigger_void_devestation"),
(152684, "at_shadow_rune1"),
(152691, "at_shadow_rune2"),
(170038, "at_shadow_rune3");
