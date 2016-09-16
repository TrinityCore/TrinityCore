DELETE FROM `spell_proc` WHERE `SpellId` IN (70672, 72455, 72832, 72833, 71564, 71756, 72782, 72783, 72784, 59915, 59906, -53569, -53695, 54939, 11129, -31656, -11119, -44546, -54639, -49208, -49467);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(70672,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72455,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72832,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72833,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(71564, 126,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x3, 0x2,    2, 0, 0, 0,      0, 5), -- Deadly Precision
(71756,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Ball of Flames Proc
(72782,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Ball of Flames Proc
(72783,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Ball of Flames Proc
(72784,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Ball of Flames Proc
(59915,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Discerning Eye of the Beast
(59906,   0,  0, 0x00000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Swift Hand of Justice
(-53569,  0, 10, 0x40200000, 0x00010000, 0x00000000,     0, 0x3, 0x2,    0, 0, 0, 0,      0, 0), -- Infusion of Light
(-53695,  0, 10, 0x00800000, 0x00000000, 0x00000008,    16, 0x5, 0x2,    0, 2, 0, 0,      0, 0), -- Judgements of the Just
(54939,   0, 10, 0x00008000, 0x00000000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Glyph of Divinity
(11129,   4,  3, 0x08C00017, 0x00031048, 0x00000000,     0, 0x1, 0x2,    0, 0, 0, 0,      0, 0), -- Combustion
(-31656,  4,  3, 0x08000000, 0x00000000, 0x00000000,     0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Empowered Fire
(-11119,  4,  3, 0x00000000, 0x00000000, 0x00000000,     0, 0x1, 0x2,    2, 0, 0, 0,      0, 0), -- Ignite
(-44546,  0,  3, 0x000002E0, 0x00001000, 0x00000000, 69632, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Brain Freeze
(-54639,  0, 15, 0x00400000, 0x00010000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Blood of the North
(-49208,  0, 15, 0x00400000, 0x00010000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0), -- Reaping
(-49467,  0, 15, 0x00000010, 0x00020000, 0x00000000,     0, 0x0, 0x2,    0, 0, 0, 0,      0, 0); -- Death Rune Mastery

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_deadly_precision','spell_item_deadly_precision_dummy','spell_item_discerning_eye_beast_dummy','spell_item_swift_hand_justice_dummy','spell_pal_infusion_of_light','spell_pal_judgements_of_the_just','spell_pal_glyph_of_divinity','spell_mage_combustion','spell_mage_empowered_fire','spell_mage_gen_extra_effects','spell_dk_death_rune');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71564,  'spell_item_deadly_precision'),
(71563,  'spell_item_deadly_precision_dummy'),
(59915,  'spell_item_discerning_eye_beast_dummy'),
(59906,  'spell_item_swift_hand_justice_dummy'),
(-53569, 'spell_pal_infusion_of_light'),
(-53695, 'spell_pal_judgements_of_the_just'),
(54939,  'spell_pal_glyph_of_divinity'),
(11129,  'spell_mage_combustion'),
(-31656, 'spell_mage_empowered_fire'),
(44401,  'spell_mage_gen_extra_effects'),
(48108,  'spell_mage_gen_extra_effects'),
(57761,  'spell_mage_gen_extra_effects'),
(-54639, 'spell_dk_death_rune'),
(-49208, 'spell_dk_death_rune'),
(-49467, 'spell_dk_death_rune');
