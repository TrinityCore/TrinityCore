-- fenryr
update creature_template set scriptname='boss_fenryr' where entry=99868;
update creature_template set scriptname='npc_fenryr' where entry=95674;
update creature_template set scriptname='npc_fenryr_ebonclaw_worg' where entry=99922;
update creature_template set scriptname='npc_trigger_hov_conversation' where entry in (101712,101712);

replace into spell_script_names values (196838,'spell_fenryr_scent_of_blood_fixate');
replace into spell_script_names values (198800,'spell_fenryr_scent_of_blood_filter');

-- godking skovald
update creature_template set scriptname='boss_god_king_skovald' where entry=95675;
update creature_template set scriptname='npc_generic_odyn_kings' where entry in (95843, 97081, 97083, 97084);
update creature_template set scriptname='npc_skovald_aegis_of_aggramar' where entry=98364;
update creature_template set scriptname='npc_skovald_honored_ancestor' where entry=101326;
update creature_template set scriptname='npc_skovald_flame_of_woe' where entry=104822;

replace into spell_script_names values (193826,'spell_skovald_ragnarok');
replace into spell_script_names values (193991,'spell_skovald_drop_aegis');
replace into spell_script_names values (193983,'spell_skovald_aegis_remove');
replace into spell_script_names values (193783,'spell_skovald_aegis_remove');
replace into spell_script_names values (193743,'spell_skovald_aegis_absorb');
replace into spell_script_names values (202711,'spell_skovald_aegis_check_cast');

-- hymdall
update creature_template set scriptname='boss_hymdall' where entry=94960;
update creature_template set scriptname='npc_hymdall_storm_drake' where entry=97788;

replace into spell_script_names values (198599,'spell_thunderstrike');

-- hyrja
update creature_template set scriptname='boss_hyrja' where entry=95833;
update creature_template set scriptname='npc_hyrja_defenders' where entry in (97202,97219);

replace into spell_script_names values (192158,'spell_hyrja_sanctify');
replace into spell_script_names values (203963,'spell_hyrja_eye_storm_absorb');
replace into spell_script_names values (192048,'spell_hyrja_expel_light');
replace into spell_script_names values (192130,'spell_hyrja_empowerment_tracker');

replace into areatrigger_scripts values (4885,'at_sanctify');

-- odyn
update creature_template set scriptname='boss_odyn_hov' where entry=95676;
update creature_template set scriptname='npc_odyn_stormforged_obliterator' where entry=102019;

replace into spell_script_names values (201006,'spell_odyn_radiant_tempest');
replace into spell_script_names values (197963,'spell_odyn_runic_brand');
replace into spell_script_names values (197964,'spell_odyn_runic_brand');
replace into spell_script_names values (197966,'spell_odyn_runic_brand');
replace into spell_script_names values (197965,'spell_odyn_runic_brand');
replace into spell_script_names values (197967,'spell_odyn_runic_brand');