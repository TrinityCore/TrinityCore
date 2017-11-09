DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_eclipse_lunar','spell_dru_eclipse_solar','spell_dru_eclipse_energize','spell_dru_glyph_of_innervate','spell_dru_glyph_of_starfire','spell_dru_glyph_of_starfire_proc','spell_dru_insect_swarm','spell_dru_typhoon');
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_moonfire','spell_dru_sunfire');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(8921,'spell_dru_moonfire'),
(93402,'spell_dru_sunfire');
