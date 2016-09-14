DELETE FROM `spell_proc` WHERE `SpellId` IN (70672, 72455, 72832, 72833, 71564, 71756, 72782, 72783, 72784, 59915, 59906);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(70672,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72455,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72832,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72833,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(71564,126, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x3, 0x2,    2, 0, 0, 0,      0, 5), -- Deadly Precision
(71756,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x2,    0, 0, 0, 0,      0,20), -- Ball of Flames Proc
(72782,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x2,    0, 0, 0, 0,      0,20), -- Ball of Flames Proc
(72783,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x2,    0, 0, 0, 0,      0,20), -- Ball of Flames Proc
(72784,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x2,    0, 0, 0, 0,      0,20), -- Ball of Flames Proc
(59915,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0), -- Discerning Eye of the Beast
(59906,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x0, 0x0,    0, 0, 0, 0,      0, 0); -- Swift Hand of Justice

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_deadly_precision','spell_item_deadly_precision_dummy','spell_item_discerning_eye_beast_dummy','spell_item_swift_hand_justice_dummy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71564,'spell_item_deadly_precision'),
(71563,'spell_item_deadly_precision_dummy'),
(59915,'spell_item_discerning_eye_beast_dummy'),
(59906,'spell_item_swift_hand_justice_dummy');
