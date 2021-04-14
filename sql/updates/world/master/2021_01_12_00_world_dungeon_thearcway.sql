-- ivanyr
update creature_template set scriptname='boss_ivanyr' where entry=98203;

replace into spell_script_names values (196392,'spell_ivanyr_overcharge_mana');
replace into spell_script_names values (220581,'spell_ivanyr_charged_bolt');

replace into criteria_data values (31372,0,0,0,'achievement_arcanic_cling');

-- naltira
update creature_template set scriptname='boss_naltira' where entry=98207;
update creature_template set scriptname='npc_naltira_vicious_manafang' where entry=110966;
update creature_template set scriptname='npc_naltira_vicious_manafang_intro' where entry=105876;

replace into spell_script_names values (200227,'spell_naltira_tangled_web');
replace into spell_script_names values (200251,'spell_naltira_tangled_web_check_dist');

-- general xakal
update creature_template set scriptname='boss_general_xakal' where entry=98206;
update creature_template set scriptname='npc_xakal_fissure' where entry=100342;
update creature_template set scriptname='npc_xakal_dread_felbat' where entry=100393;

replace into spell_script_names values (197786,'spell_xakal_bombardment');
replace into spell_script_names values (211950,'spell_throw_staff');

-- advisor vandros
update creature_template set scriptname='boss_advisor_vandros' where entry=98208;
update creature_template set scriptname='npc_vandros_chrono_shard' where entry=102849;
update creature_template set scriptname='npc_unstable_amalgamation' where entry in (98425,98426);

replace into spell_script_names values (203883,'spell_vandros_teleport_plr');
replace into spell_script_names values (220871,'spell_vandros_unstable_mana');
replace into spell_script_names values (203914,'spell_vandros_banish_in_time_timer');

-- corstilax
update creature_template set scriptname='boss_corstilax' where entry=98205;
update creature_template set scriptname='npc_corstilax_suppression_protocol' where entry=99628;
update creature_template set scriptname='npc_corstilax_quarantine' where entry=99560;

replace into spell_script_names values (196115,'spell_corstilax_cleansing_force');