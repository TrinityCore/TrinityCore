-- opera
update creature_template set scriptname='npc_rtk_barnes_encounter_starter' where entry=114339;
update creature_template set scriptname='npc_rtk_monkey_king' where entry=115022;
update creature_template set scriptname='boss_rtk_galindre' where entry=114251;
update creature_template set scriptname='boss_rtk_elfyra' where entry=114284;
update creature_template set scriptname='boss_rtk_toe_knee' where entry=114261;
update creature_template set scriptname='boss_rtk_mrrgria' where entry=114260;
update creature_template set scriptname='boss_rtk_coggleston' where entry=114328;
update creature_template set scriptname='boss_rtk_luminore' where entry=114329;
update creature_template set scriptname='boss_rtk_babblet' where entry=114330;
update creature_template set scriptname='boss_rtk_cauldrons' where entry=114522;
update creature_template set scriptname='npc_rtk_west_generic_trash' where entry in (114265, 114266);

-- shade of medivh
update creature_template set scriptname='boss_shade_of_medivh' where entry=114350;
update creature_template set scriptname='npc_medivh_guardian_image' where entry=228582;

replace into spell_script_names values (228582,'spell_medivh_mana_regen');
replace into spell_script_names values (228232,'spell_medivh_ceaseless_winter');

-- attumen
update creature_template set scriptname='boss_rtk_midnight' where entry=114264;
update creature_template set scriptname='npc_attumen_the_huntsman' where entry=114262;
update creature_template set scriptname='npc_rtk_intangible_pressence' where entry=114315;

replace into spell_script_names values (227404,'spell_rtk_intangible_presence');

-- curator
update creature_template set scriptname='boss_the_curator' where entry=114247;
update creature_template set scriptname='npc_curator_volatile_energy' where entry=114249;

replace into spell_script_names values (227257,'spell_curator_arc_lightning');
replace into spell_script_names values (227270,'spell_curator_arc_lightning');

-- maiden of virtue
update creature_template set scriptname='boss_maiden_of_virtue_legion' where entry=113971;

-- mana devourer
update creature_template set scriptname='boss_mana_devourer' where entry=114252;

replace into spell_script_names values (227451,'spell_mana_devourer_energize');
replace into spell_script_names values (227524,'spell_mana_energy_void');
replace into spell_script_names values (227297,'spell_mana_coalesce_power');
replace into spell_script_names values (231499,'spell_rtk_mana_teleport');

-- mores
update creature_template set scriptname='boss_rtk_moroes' where entry=114312;
update creature_template set scriptname='npc_moroes_trash_generic' where entry in (114316, 114317, 114318, 114319, 114320, 114321);
update creature_template set scriptname='npc_moroes_after_scene' where entry in (115427,115426);
update creature_template set scriptname='npc_moroes_whirling_edge' where entry=114327;

-- nightbane
update creature_template set scriptname='boss_rtk_nightbane' where entry=114895;
update creature_template set scriptname='npc_karazhan_nighbane_starter' where entry=115038;
update creature_template set scriptname='npc_karazhan_part_of_soul' where entry in (115013, 115101, 115105, 115113, 115103);

replace into spell_script_names values (228800,'spell_nightbane_ignite_soul');

-- vizaduum
update creature_template set scriptname='boss_vizaduum_the_watcher' where entry=114790;
update creature_template set scriptname='npc_vizaduum_fel_cannon' where entry=115274;
update creature_template set scriptname='npc_vizaduum_shadow_spitter' where entry=115734;
update creature_template set scriptname='npc_vizaduum_demonic_portal' where entry=115493;
update creature_template set scriptname='npc_archmage_khadgar_medivh_vizaduum' where entry in (115497, 114463);

replace into spell_script_names values (229241,'spell_vizaduum_acquiring_target');
replace into spell_script_names values (229599,'spell_vizaduum_demonic_portal');
replace into spell_script_names values (229286,'spell_vizaduum_bombardment');
replace into spell_script_names values (229159,'spell_vizaduum_chaotic_shadows');