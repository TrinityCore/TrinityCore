DELETE FROM `spell_proc` WHERE `SpellId` IN (70672, 72455, 72832, 72833, 71564);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(70672, 40, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x1,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72455, 40, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x1,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72832, 40, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x1,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(72833, 40, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x1, 0x1,    0, 0, 0, 0,      0, 0), -- Gaseous Bloat
(71564,  0, 0, 0x00000000, 0x00000000, 0x00000000,      0, 0x4, 0x1,    0, 0, 0, 0,      0, 0); -- Deadly Precision

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_item_deadly_precision','spell_item_deadly_precision_dummy');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(71564,'spell_item_deadly_precision'),
(71563,'spell_item_deadly_precision_dummy');
