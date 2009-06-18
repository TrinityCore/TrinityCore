DELETE FROM `spell_bonus_data` where entry in (31893, 32221, 31898, 32220, 53719, 53718, 53726, 53725);
INSERT INTO `spell_bonus_data` VALUES
(31893, 0, 0, 0, "Paladin - Seal of Blood Proc Enemy"),
(32221, 0, 0, 0, "Paladin - Seal of Blood Proc Self"),
(31898, 0.25, 0, 0.16, "Paladin - Judgement of Blood Enemy"), 
(32220, 0.0833, 0, 0.0533, "Paladin - Judgement of Blood Self"),
(53719, 0, 0, 0, "Paladin - Seal of the Martyr Proc Enemy"),
(53718, 0, 0, 0, "Paladin - Seal of the Martyr Proc Self"),
(53726, 0.25, 0, 0.16, "Paladin - Judgement of the Martyr Enemy"),
(53725, 0.0833, 0, 0.0533, "Paladin - Judgement of the Martyr Self");
