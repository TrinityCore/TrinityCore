-- dresaron
update creature_template set scriptname='boss_dresaron' where entry=99200;
update creature_template set scriptname='npc_dresaron_corrupted_dragon_egg' where entry in (101072,100533);
update creature_template set scriptname='npc_dresaron_acid_breath_stalker' where entry=101078;
update creature_template set scriptname='npc_dresaron_hatespawn_whelpling' where entry=101074;
update creature_template set scriptname='npc_dresaron_hatespawn_abomination' where entry=111008;

-- archdruid glaidalis
update creature_template set scriptname='npc_glaidalis_nightmare_abomination' where entry=102962;
update creature_template set scriptname='boss_arch_druid_glaidalis' where entry=96512;

replace into spell_script_names values (196376,'spell_glaidalis_grievous_tear');
replace into spell_script_names values (196346,'spell_glaidalis_grievous_leap');
replace into spell_script_names values (200684,'spell_nightmare_toxin');
replace into spell_script_names values (225484,'spell_nightclaw_grievous_rip');

-- oakheart
update creature_template set scriptname='boss_oakheart' where entry=103344;
update creature_template set scriptname='npc_oakheart_strangling_roots' where entry=100991;

-- shade of xavius
update creature_template set scriptname='boss_shade_of_xavius' where entry=99192;
update creature_template set scriptname='npc_xavius_malfurion_stormrage' where entry=100652;

replace into spell_script_names values (200243,'spell_xavius_waking_nightmare');
