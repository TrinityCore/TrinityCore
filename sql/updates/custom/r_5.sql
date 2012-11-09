-- Blackrock Caverns
UPDATE `instance_template` SET `script`='instance_blackrock_caverns' WHERE `map`=645;
UPDATE `creature_template` SET `ScriptName`='boss_ascendant_lord_obsidius' WHERE `entry`=39705;
UPDATE `creature_template` SET `ScriptName`='boss_beauty' WHERE `entry`=39700;
UPDATE `creature_template` SET `ScriptName`='boss_corla_herald_of_twilight' WHERE `entry`=39679;
UPDATE `creature_template` SET `ScriptName`='boss_karsh_steelbender' WHERE `entry`=39698;
UPDATE `creature_template` SET `ScriptName`='boss_romogg_bonecrusher' WHERE `entry`=39665;

-- The Stonecore
UPDATE `instance_template` SET `script`='instance_the_stonecore' WHERE `map`=725;
UPDATE `creature_template` SET `ScriptName`='boss_corborus' WHERE `entry`=43438;
UPDATE `creature_template` SET `ScriptName`='boss_ozruk' WHERE `entry`=42188;
UPDATE `creature_template` SET `ScriptName`='boss_priestess_azil' WHERE `entry`=42333;
UPDATE `creature_template` SET `ScriptName`='boss_slabhide' WHERE `entry`=43214;
UPDATE `creature_template` SET `ScriptName`='mob_crystalspawn_giant' WHERE `entry`=42810;
UPDATE `creature_template` SET `ScriptName`='mob_impp' WHERE `entry`=43014;
UPDATE `creature_template` SET `ScriptName`='mob_millhouse_manastorm' WHERE `entry`=43391;
UPDATE `creature_template` SET `ScriptName`='mob_rock_borer' WHERE `entry`=43917;

-- Throne Of The Tides
UPDATE `instance_template` SET `script`='instance_throne_of_the_tides' WHERE `map`=643;
UPDATE `creature_template` SET `ScriptName`='npc_neptulon' WHERE `entry`=40792;
UPDATE `creature_template` SET `ScriptName`='boss_ozumat' WHERE `entry`=42172;
UPDATE `creature_template` SET `ScriptName`='boss_ozumat' WHERE `entry`=44566;
UPDATE `creature_template` SET `ScriptName`='boss_lady_nazjar' WHERE `entry`=40586;
UPDATE `creature_template` SET `ScriptName`='boss_erunak_stonespeaker' WHERE `entry`=40825;
UPDATE `creature_template` SET `ScriptName`='boss_mindbender_ghursha' WHERE `entry`=40788;
UPDATE `creature_template` SET `ScriptName`='boss_commander_ulthok' WHERE `entry`=40765;

-- Halls Of Origination
UPDATE `instance_template` SET `script`='instance_halls_of_origination' WHERE `map`=644;
UPDATE `creature_template` SET `ScriptName`='boss_ammunae' WHERE `entry`=39731;
UPDATE `creature_template` SET `ScriptName`='mob_bloodpetal_blossom' WHERE `entry`=40620;
UPDATE `creature_template` SET `ScriptName`='mob_seed_pod' WHERE `entry`=51329;
UPDATE `creature_template` SET `ScriptName`='mob_spore' WHERE `entry`=40585;
UPDATE `creature_template` SET `ScriptName`='boss_anraphet' WHERE `entry`=39788;
UPDATE `creature_template` SET `ScriptName`='boss_flame_warden' WHERE `entry`=39800;
UPDATE `creature_template` SET `ScriptName`='boss_air_warden' WHERE `entry`=39803;
UPDATE `creature_template` SET `ScriptName`='boss_earth_warden' WHERE `entry`=39801;
UPDATE `creature_template` SET `ScriptName`='boss_water_warden' WHERE `entry`=39802;
UPDATE `creature_template` SET `ScriptName`='boss_ptah' WHERE `entry`=39428;
UPDATE `creature_template` SET `ScriptName`='boss_isiset' WHERE `entry`=39587;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
('74136', 'spell_isiset_supernova'),
('74137', 'spell_isiset_supernova');
UPDATE `creature_template` SET `ScriptName`='boss_rajh' WHERE `entry`=39738;
UPDATE `creature_template` SET `ScriptName`='mob_solar_wind' WHERE `entry`=39634;
UPDATE `creature_template` SET `ScriptName`='mob_solar_wind' WHERE `entry`=39635;
UPDATE `creature_template` SET `ScriptName`='mob_solar_wind' WHERE `entry`=47922;
UPDATE `creature_template` SET `ScriptName`='boss_setesh' WHERE `entry`=39732;
UPDATE `creature_template` SET `ScriptName`='mob_choas_portal' WHERE `entry`=41055;
UPDATE `creature_template` SET `ScriptName`='mob_seed_of_chaos' WHERE `entry`=41126;
UPDATE `creature_template` SET `ScriptName`='mob_void_sentinel' WHERE `entry`=41208;
UPDATE `creature_template` SET `ScriptName`='mob_void_seeker' WHERE `entry`=41731;
UPDATE `creature_template` SET `ScriptName`='boss_temple_guardian_anhuur' WHERE `entry`=39425;
UPDATE `gameobject_template` SET `ScriptName`='go_beacon_of_light' WHERE `entry` IN (203133, 203136);

-- Lost City Of The Tolvir
UPDATE `instance_template` SET `script`='instance_lost_city_of_the_tolvir' WHERE `map`=755;
UPDATE `creature_template` SET `ScriptName`='boss_high_prophet_barim' WHERE `entry`=43612;
UPDATE `creature_template` SET `ScriptName`='npc_blaze_of_heavens' WHERE `entry`=48906;
UPDATE `creature_template` SET `ScriptName`='npc_harbinger_of_darkness' WHERE `entry`=43927;
UPDATE `creature_template` SET `ScriptName`='mob_solar_wind' WHERE `entry`=47922;
UPDATE `creature_template` SET `ScriptName`='boss_lockmaw' WHERE `entry`=43614;
UPDATE `creature_template` SET `ScriptName`='npc_neferset_darkcaster' WHERE `entry`=44982;
UPDATE `creature_template` SET `ScriptName`='npc_neferset_plaguebringer' WHERE `entry`=44976;
UPDATE `creature_template` SET `ScriptName`='npc_neferset_theurgist' WHERE `entry`=44980;
UPDATE `creature_template` SET `ScriptName`='npc_neferset_torturer' WHERE `entry`=44977;
UPDATE `creature_template` SET `ScriptName`='npc_oathsworn_axemaster' WHERE `entry`=44922;
UPDATE `creature_template` SET `ScriptName`='npc_oathsworn_captain' WHERE `entry`=45122;
UPDATE `creature_template` SET `ScriptName`='npc_oathsworn_myrmidon' WHERE `entry`=44924;
UPDATE `creature_template` SET `ScriptName`='npc_oathsworn_pathfinder' WHERE `entry`=44932;
UPDATE `creature_template` SET `ScriptName`='npc_oathsworn_scorpid_keeper' WHERE `entry`=45026;
UPDATE `creature_template` SET `ScriptName`='npc_oathsworn_skinner' WHERE `entry`=44981;
UPDATE `creature_template` SET `ScriptName`='npc_pygmy_brute' WHERE `entry`=44896;
UPDATE `creature_template` SET `ScriptName`='npc_pygmy_firebreather' WHERE `entry`=44898;
UPDATE `creature_template` SET `ScriptName`='npc_pygmy_scout' WHERE `entry`=44897;

-- Vortex Pinnacle
UPDATE `instance_template` SET `script`='instance_vortex_pinnacle' WHERE `map`=657;
UPDATE `creature_template` SET `ScriptName`='boss_altairus' WHERE `entry`=43873;
UPDATE `creature_template` SET `ScriptName`='boss_asaad' WHERE `entry`=43875;
UPDATE `creature_template` SET `ScriptName`='boss_grand_vizier_ertan' WHERE `entry`=43878;
UPDATE `creature_template` SET `ScriptName`='npc_slipstream' WHERE `entry`=47066;








