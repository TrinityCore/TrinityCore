DELETE FROM `spell_custom_attr` WHERE `entry`=207194;
INSERT INTO `spell_custom_attr` (`entry`,`attributes`) VALUES
(207194,0x8);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_army_periodic_taunt','spell_dk_death_grip','spell_dk_glyph_of_deaths_embrace','spell_dk_glyph_of_runic_power','spell_dk_icebound_fortitude','spell_dk_soul_reaper','spell_dk_will_of_the_necropolis');
