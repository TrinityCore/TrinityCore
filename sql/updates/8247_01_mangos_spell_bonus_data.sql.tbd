ALTER TABLE db_version CHANGE COLUMN required_8237_01_mangos_creature_template required_8247_01_mangos_spell_bonus_data bit;

DELETE FROM `spell_bonus_data` where entry in (49941, 55078, 50444, 52212, 47632, 47633, 55095, 49184, 45477, 45477, 50842, 47476, 50536, 50401, 56903);
INSERT INTO `spell_bonus_data`(`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `comments`) VALUES
(49941, 0, 0, 0.04, "Death Knight - Blood Boil"),
(55078, 0, 0, 0.055, "Death Knight - Blood Plague Dummy Proc"),
(50444, 0, 0, 0.105, "Death Knight - Corpse Explosion Triggered"),
(52212, 0, 0, 0.0475, "Death Knight - Death and Decay Triggered"),
(47632, 0, 0, 0.15, "Death Knight - Death Coil Damage"),
(47633, 0, 0, 0.15, "Death Knight - Death Coil Heal"),
(55095, 0, 0, 0.055, "Death Knight - Frost Fever"),
(49184, 0, 0, 0.1, "Death Knight - Howling Blast"),
(45477, 0, 0, 0.1, "Death Knight - Icy Touch"),
(50842, 0, 0, 0.04, "Death Knight - Pestilence"),
(47476, 0, 0, 0.06, "Death Knight - Strangulate"),
(50536, 0, 0, 0.013, "Death Knight - Unholy Blight Triggered"),
(50401, 0, 0, 0, "Death Knight - Razor Frost"),
(56903, 0, 0, 0, "Death Knight - Lichflame");
