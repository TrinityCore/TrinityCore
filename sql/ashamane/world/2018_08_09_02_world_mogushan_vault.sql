-- creature_template
UPDATE creature_template SET scriptname = "boss_stone_guard_controler" WHERE entry = 60089;
UPDATE creature_template SET scriptname = "mob_celestial_protector" WHERE entry = 60793;
UPDATE creature_template SET scriptname = "mob_cosmic_spark" WHERE entry = 62618;
UPDATE creature_template SET scriptname = "mob_energy_charge" WHERE entry = 60913;
UPDATE creature_template SET scriptname = "mob_empyreal_focus" WHERE entry = 60776;
UPDATE creature_template SET scriptname = "mob_infinite_energy" WHERE entry = 65293;
UPDATE creature_template SET scriptname = "boss_generic_guardian" WHERE entry IN (59915, 60043, 60047, 50051);

UPDATE creature_template SET scriptname = "boss_spirit_kings_controler" WHERE entry = 60984;
UPDATE creature_template SET scriptname = "boss_spirit_kings" WHERE entry IN (60709, 60710, 60701, 60708);

UPDATE creature_template SET scriptname = "boss_feng" WHERE entry = 60009;

UPDATE creature_template SET scriptname = "boss_garajal" WHERE entry = 60143;

UPDATE creature_template SET scriptname = "boss_elegon" WHERE entry = 60410;

UPDATE creature_template SET scriptname = "mob_empyreal_focus" WHERE entry = 60776;
UPDATE creature_template SET scriptname = "mob_lightning_fist" WHERE entry = 60241;
UPDATE creature_template SET scriptname = "mob_wild_spark" WHERE entry = 60438;
UPDATE creature_template SET scriptname = "mob_siphon_shield" WHERE entry = 60627;
UPDATE creature_template SET scriptname = "mob_soul_fragment" WHERE entry = 60781;
UPDATE creature_template SET scriptname = "mob_spirit_totem" WHERE entry = 60240;
UPDATE creature_template SET scriptname = "mob_shadowy_minion" WHERE entry IN (60184, 60940);
UPDATE creature_template SET scriptname = "mob_spirit_totem_intro" WHERE entry IN (60512, 60513);
UPDATE creature_template SET scriptname = "mob_soul_cutter" WHERE entry = 62003;
UPDATE creature_template SET scriptname = "mob_soul_cutter" WHERE entry = 62003;
UPDATE creature_template SET scriptname = "mob_garajal_ghost" WHERE entry = 61140;
UPDATE creature_template SET scriptname = "mob_ancient_mogu_machine" WHERE entry = 60648;
UPDATE creature_template SET scriptname = "mob_woe_titan_spark" WHERE entry = 60480;

UPDATE creature_template SET scriptname = "mob_enormous_stone_quilen" WHERE entry = 64183;
UPDATE creature_template SET scriptname = "mob_stone_quilen" WHERE entry = 60576;
UPDATE creature_template SET scriptname = "mob_zandalari_skullcharger" WHERE entry = 60375;
UPDATE creature_template SET scriptname = "npc_lorewalker_cho" WHERE entry = 61348;
UPDATE creature_template SET scriptname = "mob_sorcerer_mogu" WHERE entry = 61250;
UPDATE creature_template SET scriptname = "mob_mogu_archer" WHERE entry = 61345;
UPDATE creature_template SET scriptname = "mob_mounted_mogu" WHERE entry = 61341;
UPDATE creature_template SET scriptname = "mob_kingsguard" WHERE entry = 61347;
UPDATE creature_template SET scriptname = "mob_subetai" WHERE entry = 61427;
UPDATE creature_template SET scriptname = "mob_meng" WHERE entry = 61429;
UPDATE creature_template SET scriptname = "mob_zian" WHERE entry = 61421;
UPDATE creature_template SET scriptname = "mob_qiang" WHERE entry = 61423;
UPDATE creature_template SET scriptname = "mob_mogu_secret_keeper" WHERE entry = 61131;
UPDATE creature_template SET scriptname = "mob_mogu_engine_keeper" WHERE entry = 64068;
UPDATE creature_template SET scriptname = "mob_mogu_warden" WHERE entry IN (64061, 64947, 64063);
UPDATE creature_template SET scriptname = "mob_cursed_mogu_sculpture" WHERE entry IN (61334, 61989);


/*
    new boss_jin_qin_xi(); -- Qin-Xi - 60399  Jan-Xi - 60400
    new mob_woe_add_generic(); -- Emperor's Rage - 60396 -- Emperor's Strength - 60397 -- Emperor's Courage - 60398
    new mob_general_purpose_bunnyJMF(); -- // General Purpose Bunny JMF - 55091 - Note: this mob is also used in Stormstout Brewery
*/

-- gameobject_templates
UPDATE gameobject_template SET scriptname = "go_celestial_control_console" WHERE entry = 211650;
UPDATE gameobject_template SET scriptname = "go_cancel" WHERE entry = 211626;
UPDATE gameobject_template SET scriptname = "go_inversion" WHERE entry = 211628;
UPDATE gameobject_template SET scriptname = "go_ancien_control_console" WHERE entry = 211584;


UPDATE creature_template SET scriptname = "boss_will_of_emperor" WHERE entry IN (60399, 60400);

UPDATE instance_template SET script = "instance_mogu_shan_vault" WHERE map = 1008 AND parent = 870;


-- areatrigger_teleport
DELETE FROM areatrigger_teleport WHERE ID = 7839 AND PortLocID = 4093;
INSERT INTO areatrigger_teleport (`ID`, `PortLocID`, `Name`)VALUES
(7839, 4093, "Mogu'shan Vaults - Exit Target");


-- spell scripts
DELETE FROM spell_script_names WHERE spell_id IN 
(127785, 127783, 127781, 117874, 118313, 119360, 118024, 127362, 132222, 127911, 116994, 122741, 124967, 115817, 118530, 116434, 116365, 116711, 116816, 116821, 116784, 116583, 116040, 122151, 118469, 120715, 127732, 118165, 117006, 116968, 117485, 117195, 116818, 116779, 118327, 116550, 116556, 116605, 118300, 118302, 118304, 118305, 118307, 118308, 132296, 132297, 132298);

INSERT INTO spell_script_names (`spell_id`, `ScriptName`)VALUES
(127785, "spell_spawn_flash_1_periodic"),
(127783, "spell_spawn_flash_2_periodic"),
(127781, "spell_spawn_flash_3_periodic"),
(117874, "spell_touch_of_titans"),
(118313, "spell_radiating_energies"),
(119360, "spell_draw_power"),
(118024, "spell_core_checker"),
(127362, "spell_grasping_energy_tendrils"),
(132222, "spell_destabilizing_energies"),
(127911, "spell_total_annihilation"),
(116994, "spell_unstable_energy"),
(122741, "spell_radiating_energies"),
(124967, "spell_draw_power"),
(115817, "spell_nullification_barrier"),
(118530, "spell_spirit_bolt"),
(116434, "spell_mogu_arcane_resonance"),
(116365, "spell_mogu_arcane_velocity"),
(116711, "spell_draw_flame"),
(116816, "spell_mogu_wildfire_infusion"),
(116821, "spell_wildfire_infusion_stacks"),
(116784, "spell_wildfire_spark"),
(116583, "spell_mogu_wildfire_spark"),
(116040, "spell_mogu_epicenter"),
(122151, "spell_voodoo_doll"),
(118469, "spell_final_destination"),
(120715, "spell_soul_back"),
(127732, "spell_cosmetic_lightning"),
(118165, "spell_terracota_spawn"),
(117006, "spell_devastating_arc"),
(116968, "spell_arc_visual"),
(117485, "spell_impeding_thrust"),
(117195, "spell_magnetized_jan"),
(116818, "spell_magnetized_qin"),
(116779, "spell_titan_gas"),
(118327, "spell_titan_gas2"),
(116550, "spell_energizing_smash"),
(116556, "spell_energizing_visual"),
(118300, "spell_mogu_inversion"),
(118302, "spell_mogu_inversion"),
(118304, "spell_mogu_inversion"),
(118305, "spell_mogu_inversion"),
(118307, "spell_mogu_inversion"),
(118308, "spell_mogu_inversion"),
(132297, "spell_mogu_inversion"),
(132298, "spell_mogu_inversion"),
(132296, "spell_mogu_inversion"),
(116605, "spell_energized"),
(120764, "spell_ghost_essence"),
(125092, "spell_mogu_petrification");


