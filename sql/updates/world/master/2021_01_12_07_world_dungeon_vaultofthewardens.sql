-- ashgolm
update creature_template set scriptname='boss_ashgolm' where entry=95886;
update creature_template set scriptname='npc_ashgolm_ember' where entry=99233;
update creature_template set scriptname='npc_ashgolm_countermeasures' where entry=99240;

replace into spell_script_names values (192517,'spell_brittle');
replace into spell_script_names values (200354,'spell_ashgolm_frozen');

-- cordana
update creature_template set scriptname='boss_cordana' where entry=95888;
update creature_template set scriptname='npc_cordana_glowing_sentry' where entry=100525;
update creature_template set scriptname='npc_cordana_spirit_of_vengeance' where entry=100364;
update creature_template set scriptname='npc_cordana_creeping' where entry=100336;

-- glazer
update creature_template set scriptname='boss_glazer' where entry=95887;
update creature_template set scriptname='npc_glazer_beam' where entry=102310;
update creature_template set scriptname='npc_glazer_lens' where entry=98082;

replace into spell_script_names values (194468,'spell_glazer_beam');
replace into spell_script_names values (194463,'spell_glazer_beam');
replace into spell_script_names values (195032,'spell_glazer_radiation');

-- tormentorum
update creature_template set scriptname='boss_inquisitor_tormentorum' where entry=96015;

replace into spell_script_names values (200904,'spell_tormentorum_sap_soul');
replace into spell_script_names values (196992,'spell_tormentorum_open_prisons');
replace into spell_script_names values (206019,'spell_tormentorum_corrupted_touch');

-- tirathon saltheril
update creature_template set scriptname='boss_tirathon_saltheril' where entry=95885;
update creature_template set scriptname='npc_tirathon_beam_target' where entry=96241;
update creature_template set scriptname='npc_glayvianna_soulrender' where entry=98177;

replace into spell_script_names values (190833,'spell_tirathon_beam_dmg');
replace into spell_script_names values (191941,'spell_tirathon_darkstrikes');
replace into spell_script_names values (191948,'spell_tirathon_darkstrike');