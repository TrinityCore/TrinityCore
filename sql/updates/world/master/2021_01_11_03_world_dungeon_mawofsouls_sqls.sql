-- Ymiron
update creature_template set scriptname='boss_ymiron_the_fallen_king' where entry=96756;
update creature_template set scriptname='npc_ymiron_risen_warrior' where entry=98246;
update creature_template set scriptname='npc_ymiron_cursed_falke' where entry=97163;
update creature_template set scriptname='npc_ymiron_seacursed_slaver' where entry=97043;
update creature_template set scriptname='npc_mos_seacursed_soulkeeper' where entry=97200;
update creature_template set scriptname='npc_mos_runecarver_slave' where entry=102375;

replace into spell_script_names values (167922,'spell_ymiron_power_regen');
replace into spell_script_names values (191560,'spell_ymiron_helheim_teleport');
replace into spell_script_names values (193460,'spell_ymiron_bane');
replace into spell_script_names values (194640,'spell_mos_curse_of_hope');
replace into spell_script_names values (195031,'spell_mos_defiant_strike');

replace into criteria_data values (29680,0,0,0,'achievement_instant_karma');

-- Harbaron
update creature_template set scriptname='boss_harbaron' where entry=96754;
update creature_template set scriptname='npc_harbaron_scythe' where entry=100839;
update creature_template set scriptname='npc_harbaron_shackled_servitor' where entry=98693;
update creature_template set scriptname='npc_harbaron_captured_valkyr' where entry=104906;
update creature_template set scriptname='npc_harbaron_soul_fragment' where entry=98761;
update creature_template set scriptname='npc_mos_seacursed_swiftblade' where entry=98919;

replace into spell_script_names values (194668,'spell_harbaron_nether_rip');

replace into criteria_data values (29683,0,0,0,'achievement_helheim_hath_no_fury');

-- Helya
update creature_template set scriptname='boss_helya' where entry=96759;
update creature_template set scriptname='npc_helya_tentacle' where entry in (98363,99801,100354,100360,100362,100188);
update creature_template set scriptname='npc_helya_destructor_tentacle_veh' where entry=99803;
update creature_template set scriptname='npc_helya_tentacle_veh' where entry=97099;
update creature_template set scriptname='npc_skyal' where entry=99307;
update creature_template set scriptname='npc_mos_seacursed_mistmender' where entry=97365;
update creature_template set scriptname='npc_mos_helarjar_mistcaller' where entry=99033;

replace into spell_script_names values (195309,'spell_helya_swirling_water');
replace into spell_script_names values (200208,'spell_brackwater');
replace into spell_script_names values (197752,'spell_helya_turbulent_waters');
replace into spell_script_names values (197262,'spell_helya_taint_of_the_sea');
replace into spell_script_names values (199589,'spell_whirpool_of_souls');
replace into spell_script_names values (199514,'spell_torrent_of_souls');
