UPDATE `spell_proc` SET `SpellPhaseMask`=0x4 WHERE `SpellId` = 63280; -- Glyph of Totem of Wrath
UPDATE `spell_proc` SET `AttributesMask`=0x2 WHERE `SpellId` IN (
-50880, -- Icy Talons
-34753, -- Holy Concentration
-33150  -- Surge of Light
);

UPDATE `spell_proc` SET `AttributesMask`=0x8 WHERE `SpellId` = 31834; -- Light's Grace

UPDATE `spell_proc` SET `ProcFlags`=0x00010000 WHERE `SpellId` IN (
71602,  -- Item - Icecrown 25 Normal Caster Trinket 1 Base
71645   -- Item - Icecrown 25 Heroic Caster Trinket 1 Base
);

DELETE FROM `spell_proc` WHERE `SpellId` IN (71571, 71573, 71865, 71868, 75490, 75495);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(71571, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x2, 0x0, 0x2, 0, 0, 0, 0), -- Item - Icecrown 10 Normal Caster Trinket
(71573, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x2, 0x0, 0x2, 0, 0, 0, 0), -- Item - Icecrown 10 Heroic Caster Trinket
(71865, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x2, 0x2, 0x0, 0x2, 0, 0, 0, 0), -- Item - Icecrown 25 Normal Healer Weapon Proc
(71868, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x2, 0x2, 0x0, 0x2, 0, 0, 0, 0), -- Item - Icecrown 25 Heroic Healer Weapon Proc
(75490, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x2, 0x2, 0x0, 0x2, 0, 0, 0, 0), -- Eyes of Twilight
(75495, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x2, 0x2, 0x0, 0x2, 0, 0, 0, 0); -- Eyes of Twilight
