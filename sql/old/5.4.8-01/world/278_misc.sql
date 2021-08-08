INSERT IGNORE INTO `spell_script_names` VALUES (148187, 'spell_monk_teachings_of_the_monastery');

-- disable battle standarts
UPDATE `item_template` SET `spellid_1`=0, `spelltrigger_1`=0, `spellcharges_1`=0, `spellcooldown_1`=0, `spellcategory_1`=0, `spellcategorycooldown_1`=0 WHERE `entry` IN (19045, 19046);

-- fix Glyph of Telluric Currents
INSERT IGNORE INTO `spell_script_names` VALUES (55453, 'spell_sha_glyph_of_telluric_currents');

-- fix mount up
INSERT IGNORE `disables` VALUES (0, 78633, 16, '489, 529, 30, 566, 607, 628, 761, 726,', '', 'Mount up disable');

-- fix Demonic Call
INSERT IGNORE spell_script_names VALUE (104027, 'spell_warl_demonic_call'); -- Soul fire (demon)
INSERT IGNORE spell_script_names VALUE (114175, 'spell_warl_demonic_call'); -- Demonic Slash (demon)

-- fix Spectral Guise
INSERT IGNORE `spell_script_names` VALUES (112833, 'spell_pri_spectral_guise');
