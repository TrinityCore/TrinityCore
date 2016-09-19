DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (15290, 59725);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 59725, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Improved Spell Reflection (effect 0) will hit the potential target of the spell if target is not the same as condition target.'),
(13, 1, 15290, 0, 0, 33, 0, 1, 0, 0, 1, 0, 0, '', 'Spell Vampiric Embrace (effect 0) will hit the potential target of the spell if target is not the same as condition target.');

-- Threat of Thassarian triggered spells, for easier script access
DELETE FROM `spell_ranks` WHERE `first_spell_id` IN (59133,66198,66196,66216,66188,66215);
INSERT INTO `spell_ranks` (`first_spell_id`, `spell_id`, `rank`) VALUES
(66198, 66198, 1),
(66198, 66972, 2),
(66198, 66973, 3),
(66198, 66974, 4),

(66196, 66196, 1),
(66196, 66958, 2),
(66196, 66959, 3),
(66196, 66960, 4),
(66196, 66961, 5),
(66196, 66962, 6),

(66216, 66216, 1),
(66216, 66988, 2),
(66216, 66989, 3),
(66216, 66990, 4),
(66216, 66991, 5),
(66216, 66992, 6),

(66188, 66188, 1),
(66188, 66950, 2),
(66188, 66951, 3),
(66188, 66952, 4),
(66188, 66953, 5),

(66215, 66215, 1),
(66215, 66975, 2),
(66215, 66976, 3),
(66215, 66977, 4),
(66215, 66978, 5),
(66215, 66979, 6);

DELETE FROM `command` WHERE `name`='reload spell_proc_event';
-- Charges drop (previously hardcoded in SpellMgr::LoadSpellInfoCorrections)
DELETE FROM `spell_proc` WHERE `SpellId` IN (17941, 18820, 22008, 28200, 31834, 32216, 34477, 34936, 44401, 48108, 51124, 54741, 57761, 64823);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(17941,   0,  5, 0x00000001, 0x00000000, 0x00000000,   65536, 0x1, 0x1,     0, 0x0,  0,   0,      0, 1), -- Shadow Trance
(18820,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x7, 0x1,     0, 0x0,  0,   0,      0, 1), -- Insight
(22008,   0,  3, 0x61400035, 0x00000000, 0x00000000,   69632, 0x5, 0x1,     0, 0x0,  0,   0,      0, 1), -- Netherwind Focus
(28200,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x3, 0x1,     0, 0x0,  0,   0,      0, 6), -- Ascendance
(31834,   0, 10, 0x80000000, 0x00000000, 0x00000000,   16384, 0x2, 0x1,     0, 0x0,  0,   0,      0, 1), -- Light's Grace
(32216,   0,  4, 0x00000000, 0x00000100, 0x00000000,      16, 0x1, 0x4,     0, 0x0,  0,   0,      0, 1), -- Victorious (drop charge on Victory rush cast)
(34477,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x5, 0x2,     0, 0x0,  0,   0,      0, 1), -- Misdirection
(34936,   0,  5, 0x00000001, 0x00000040, 0x00000000,   65536, 0x1, 0x1,     0, 0x0,  0,   0,      0, 1), -- Backlash
(44401,   0,  3, 0x00000800, 0x00000000, 0x00000000,    4096, 0x5, 0x1,     0, 0x0,  0,   0,      0, 1), -- Missile Barrage
(48108,   0,  3, 0x00400000, 0x00000000, 0x00000000,   65536, 0x1, 0x1,     0, 0x0,  0,   0,      0, 1), -- Hot Streak
(51124,   0, 15, 0x00000002, 0x00000006, 0x00000000,   65552, 0x1, 0x2,     0, 0x0,  0,   0,      0, 1), -- Killing Machine
(54741,   0,  3, 0x00000004, 0x00000000, 0x00000000,   65536, 0x5, 0x1,     0, 0x0,  0,   0,      0, 1), -- Firestarter
(57761,   0,  3, 0x00000001, 0x00001000, 0x00000000,   65536, 0x1, 0x1,     0, 0x0,  0,   0,      0, 1), -- Fireball!
(64823,   0,  7, 0x00000004, 0x00000000, 0x00000000,   65536, 0x1, 0x1,     0, 0x0,  0,   0,      0, 1); -- Elune's Wrath

-- Port procs from spell_proc_event table
DELETE FROM `spell_proc` WHERE `SpellId` IN (-1463, -10400, -11119, -11185, -16180, -18094, -20335, -27243, -29441, -29834, -30293, -30675, -31244, -31571, -31656, -31785, -31871, -31876, -34497, -34914, -44404, -44445, -44546, -47569, -48539, -48979, -49015, -49018, -49208, -49217, -49467, -51459, -51525, -51556, -51625, -51664, -53178, -53228, -53290, -53380, -53501, -53569, -53695, -54639, -59088, -61680, -62764, -63373, -64127, -65661, 11129, 15286, 17619, 20185, 20186, 22007, 24658, 24932, 26169, 28716, 28719, 28744, 28789, 28809, 28823, 28847, 28849, 32863, 36123, 38252, 39367, 44141, 70388, 31801, 32409, 33757, 37288, 37295, 37381, 37377, 39437, 39372, 40438, 40442, 40463, 40470, 42770, 44835, 49005, 49028, 49194, 49222, 51209, 51528, 51529, 51530, 51531, 51532, 53601, 53736, 54754, 54815, 54821, 54832, 54845, 54937, 54939, 55198, 55440, 55677, 56218, 56372, 56374, 56375, 56800, 57870, 58375, 58642, 58877, 59906, 59915, 37447, 61062, 61257, 63280, 63320, 64890, 64928, 65032, 67228, 69755, 69739, 70723, 70664, 70770, 70808, 70817, 70844, 70672, 72455, 72832, 72833, 71756, 72782, 72783, 72784, 71406, 71545, 71880, 71892, 71519, 71562, 71564, 71761);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-1463,   0,  3, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,  1024, 0x0,  0,   0,      0, 0), -- Mana Shield.
(-10400,  0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Flametongue Weapon (Passive)
(-11119,  4,  3, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Ignite
(-11185,  0,  3, 0x00000080, 0x00000000, 0x00000000,   65536, 0x1, 0x2,     0, 0x2,  0,   0,      0, 0), -- Improved Blizzard
(-16180,  0, 11, 0x000001C0, 0x00000000, 0x00000010,       0, 0x2, 0x2,     2, 0x0,  0,   0,      0, 0), -- Improved Water Shield
(-18094,  0,  5, 0x0000000A, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Nightfall
(-20335,  0, 10, 0x00800000, 0x00000000, 0x00000000,      16, 0x5, 0x2,     0, 0x0,  0, 100,      0, 0), -- Heart of the Crusader
(-27243,  0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Seed of corruption (Warlock)
(-29441,  0,  3, 0x00000000, 0x00000000, 0x00000000,       0, 0x7, 0x0,     8, 0x0,  0,   0,   1000, 0), -- Magic Absorption
(-29834,  0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x5, 0x0,     0, 0x0,  0,   0,      0, 0), -- Second Wind (Warrior talent)
(-30293,  0,  5, 0x00000181, 0x008200C0, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Soul Leech
(-30675,  0, 11, 0x00000003, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Lightning Overload
(-31244,  0,  8, 0x003A0000, 0x00000009, 0x00000000,       0, 0x5, 0x2, 11196, 0x0,  0,   0,      0, 0), -- Quick Recovery
(-31571,  0,  3, 0x00000000, 0x00000022, 0x00000008,   16384, 0x7, 0x4,     0, 0x0,  0,   0,      0, 0), -- Arcane Potency
(-31656,  4,  3, 0x08000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Empowered Fire
(-31785,  0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x2, 0x0,     0, 0x0,  0,   0,      0, 0), -- Spiritual Attunement
(-31871,  0, 10, 0x00000010, 0x00000000, 0x00000000,   16384, 0x4, 0x2,     0, 0x0,  0,   0,      0, 0), -- Divine Purpose
(-31876,  0, 10, 0x00800000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Judgements of the Wise
(-34497,  0,  9, 0x00060800, 0x00800001, 0x00000201,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Thrill of the Hunt
(-34914,  0,  6, 0x00002000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Vampiric Touch
(-44404,  0,  3, 0x20000021, 0x00009000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Missile Barrage
(-44445,  0,  3, 0x00000013, 0x00011000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Hot Streak
(-44546,  0,  3, 0x000002E0, 0x00001000, 0x00000000,   69632, 0x0, 0x2,     0, 0x0,  0,   0,      0, 0), -- Brain Freeze
(-47569,  0,  6, 0x00004000, 0x00000000, 0x00000000,   16384, 0x4, 0x2,     0, 0x0,  0,   0,      0, 0), -- Improved Shadowform
(-48539,  0,  7, 0x00000010, 0x04000000, 0x00000000,  262144, 0x2, 0x0,     0, 0x0,  0,   0,      0, 0), -- Revitalize
(-48979,  0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x1,  0,   0,      0, 0), -- Butchery
(-49015,  0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x1,  0,   0,      0, 0), -- Vendetta
(-49018,  0, 15, 0x01400000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Sudden Doom
(-49208,  0, 15, 0x00400000, 0x00010000, 0x00000000,       0, 0x0, 0x2,     0, 0x0,  0,   0,      0, 0), -- Reaping
(-49217,  0, 15, 0x00000000, 0x00000000, 0x00000002,       0, 0x0, 0x0,     0, 0x0,  0,   0,   1000, 0), -- Wandering Plague
(-49467,  0, 15, 0x00000010, 0x00020000, 0x00000000,       0, 0x0, 0x2,     0, 0x0,  0,   0,      0, 0), -- Death Rune Mastery
(-51459,  0,  0, 0x00000000, 0x00000000, 0x00000000,       4, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Necrosis
(-51525,  0, 11, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0 ,0x0,  0,   0,      0, 0), -- Static Shock
(-51556,  0, 11, 0x000000C0, 0x00000000, 0x00000010,       0, 0x2, 0x2,     2, 0x0,  0,   0,      0, 0), -- Ancestral Awakening
(-51625,  0,  8, 0x1000A000, 0x00000000, 0x00000000,       0, 0x5, 0x2,     0, 0x0,  0,   0,      0, 0), -- Deadly Brew
(-51664,  0,  8, 0x00020000, 0x00000008, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Cut to the Chase
(-53178,  0,  9, 0x00000000, 0x10000000, 0x00000000,   65536, 0x4, 0x2,     0, 0x0,  0, 100,      0, 0), -- Guard Dog
(-53228,  0,  9, 0x00000020, 0x01000000, 0x00000000,       0, 0x4, 0x2,     0, 0x0,  0,   0,      0, 0), -- Rapid Recuperation
(-53290,  0,  9, 0x00000800, 0x00000001, 0x00000200,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Hunting Party
(-53380,  0, 10, 0x00800000, 0x00028000, 0x00000000,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Righteous Vengeance
(-53501,  0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x2, 0x2,     2, 0x0,  0,   0,      0, 0), -- Sheath of Light
(-53569,  0, 10, 0x40200000, 0x00010000, 0x00000000,       0, 0x3, 0x2,     0, 0x0,  0,   0,      0, 0), -- Infusion of Light
(-53695,  0, 10, 0x00800000, 0x00000000, 0x00000008,      16, 0x5, 0x2,     0, 0x2,  0,   0,      0, 0), -- Judgements of the Just
(-54639,  0, 15, 0x00400000, 0x00010000, 0x00000000,       0, 0x0, 0x2,     0, 0x0,  0,   0,      0, 0), -- Blood of the North
(-59088,  0,  4, 0x00000000, 0x00000002, 0x00000000,    1024, 0x4, 0x4,     0, 0x0,  0,   0,      0, 0), -- Improved Spell Reflection
(-61680,  0,  9, 0x00000000, 0x10000000, 0x00000000,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Culling the Herd
(-62764,  0,  9, 0x00000000, 0x10000000, 0x00000000,   65536, 0x4, 0x2,     0, 0x0,  0, 100,      0, 0), -- Silverback
(-63373,  0, 11, 0x80000000, 0x00000000, 0x00000000,   65536, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Frozen Power
(-64127,  0,  6, 0x00000001, 0x00000001, 0x00000000,       0, 0x6, 0x2,     0, 0x0,  0,   0,      0, 0), -- Body and Soul
(-65661,  0, 15, 0x00400011, 0x20020004, 0x00000000,      16, 0x1, 0x2,     0, 0x0,  0, 100,      0, 0), -- Threat of Thassarian

(11129,   4,  3, 0x08C00017, 0x00031048, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Combustion
(15286,  32,  6, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Vampiric Embrace
(17619,   0, 13, 0x00000000, 0x00000000, 0x00000000,   32768, 0x7, 0x0,     0, 0x0,  0,   0,      0, 0), -- Alchemist's Stone
(20185,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0, 15,   0,      0, 0), -- Judgement of Light
(20186,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0, 15,   0,      0, 0), -- Judgement of Wisdom
(22007,   0,  3, 0x00200021, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Netherwind Focus
(24658,   0,  0, 0x00000000, 0x00000000, 0x00000000,   87376, 0x7, 0x2,     0, 0x0,  0,   0,      0, 0), -- Unstable Power
(24932,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Leader of the Pack
(26169,   0,  6, 0x00000000, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Oracle Healing Bonus
(28716,   0,  7, 0x00000010, 0x00000000, 0x00000000,  262144, 0x2, 0x0,     0, 0x0,  0,   0,      0, 0), -- Rejuvenation - Dreamwalker Raiment 2pc
(28719,   0,  7, 0x00000020, 0x00000000, 0x00000000,       0, 0x2, 0x2,     2, 0x0,  0,   0,      0, 0), -- Healing Touch - Dreamwalker Raiment 8 pc
(28744,   0,  7, 0x00000040, 0x00000000, 0x00000000,  278528, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Regrowth - Dreamwalker Raiment 6pc
(28789,   0, 10, 0xC0000000, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Holy Power
(28809,   0,  6, 0x00001000, 0x00000000, 0x00000000,       0, 0x2, 0x2,     2, 0x0,  0,   0,      0, 0), -- Greater Heal - Vestments of Faith 4pc
(28823,   0, 11, 0x000000C0, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Totemic Power
(28847,   0,  7, 0x00000020, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Healing Touch Refund
(28849,   0, 11, 0x00000080, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Lesser Heealing Wave

(32863,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Seed of Corruption (Monster)
(36123,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Seed of Corruption (Monster)
(38252,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Seed of Corruption (Monster)
(39367,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Seed of Corruption (Monster)
(44141,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Seed of Corruption (Monster)
(70388,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Seed of Corruption (Monster)

(31801,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Seal of Vengeance
(32409,   0,  0, 0x00000000, 0x00002000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Shadow Word: Death - do not require honor target
(33757,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,   3000, 0), -- Windfury Weapon (Passive)
(37288,   0,  7, 0x00000000, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Mana Restore - Malorne Raiment 2pc
(37295,   0,  7, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Mana Restore - Malorne Regalia 2pc
(37381,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Pet Healing

(37377,  32,  5, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Shadowflame
(39437,   4,  5, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Shadowflame Hellfire and RoF

(39372,  48,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Frozen Shadoweave
(40438,   0,  6, 0x00008040, 0x00000000, 0x00000000,       0, 0x3, 0x0,     0, 0x0,  0,   0,      0, 0), -- Priest Tier 6 Trinket
(40442,   0,  7, 0x00000014, 0x00000440, 0x00000000,       0, 0x7, 0x1,     0, 0x0,  0,   0,      0, 0), -- Druid Tier 6 Trinket
(40463,   0, 11, 0x00000081, 0x00000010, 0x00000000,       0, 0x3, 0x2,     0, 0x0,  0,   0,      0, 0), -- Shaman Tier 6 Trinket
(40470,   0, 10, 0xC0800000, 0x00000000, 0x00000000,       0, 0x3, 0x2,     0, 0x0,  0,   0,      0, 0), -- Paladin Tier 6 Trinket
(42770,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x5, 0x0,     0, 0x0,  0,   0,      0, 0), -- Second Wind (NPC aura)
(44835,   0,  7, 0x00000000, 0x00000080, 0x00000000,      16, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Maim Interrupt
(49005,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Mark of Blood
(49028,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x5, 0x2,     0, 0x0,  0,   0,      0, 0), -- Dancing Rune Weapon
(49194,   0, 15, 0x00000000, 0x00000000, 0x00000001,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Unholy Blight
(49222,   0,  0, 0x00000000, 0x00000000, 0x00000000,  139944, 0x0, 0x0,     0, 0x0,  0,   0,   2000, 0), -- Bone Shield
(51209,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Hungering Cold

(51528,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  4,   0,      0, 0), -- Maelstrom Weapon (Rank 1)
(51529,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  8,   0,      0, 0), -- Maelstrom Weapon (Rank 2)
(51530,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0, 12,   0,      0, 0), -- Maelstrom Weapon (Rank 3)
(51531,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0, 16,   0,      0, 0), -- Maelstrom Weapon (Rank 4)
(51532,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0, 20,   0,      0, 0), -- Maelstrom Weapon (Rank 5)

(53601,   0,  0, 0x00000000, 0x00000000, 0x00000000, 1048576, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Sacred Shield
(53736,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Seal of Corruption
(54754,   0,  7, 0x00000010, 0x00000000, 0x00000000,       0, 0x2, 0x0,     0, 0x0,  0,   0,      0, 0), -- Glyph of Rejuvenation
(54815,   0,  7, 0x00008000, 0x00000000, 0x00000000,      16, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Shred
(54821,   0,  7, 0x00001000, 0x00000000, 0x00000000,      16, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Rake
(54832,   0,  7, 0x00000000, 0x00001000, 0x00000000,   16384, 0x4, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Innervate
(54845,   0,  7, 0x00000004, 0x00000000, 0x00000000,   65536, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Starfire
(54937,   0, 10, 0x80000000, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Holy Light
(54939,   0, 10, 0x00008000, 0x00000000, 0x00000000,       0, 0x0, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Divinity
(55198,   0, 11, 0x000001C0, 0x00000000, 0x00000000,   16384, 0x2, 0x2,     2, 0x0,  0,   0,      0, 3), -- Tidal Force
(55440,   0, 11, 0x00000040, 0x00000000, 0x00000000,       0, 0x2, 0x1,     0, 0x0,  0,   0,      0, 0), -- Glyph of Healing Wave
(55677,   0,  6, 0x00000000, 0x00000001, 0x00000000,       0, 0x4, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Dispel Magic
(56218,   0,  5, 0x00000002, 0x00000000, 0x00000000,       0, 0x1, 0x0,     0, 0x0,  0,   0,      0, 0), -- Glyph of Corruption
(56372,   0,  3, 0x00000000, 0x00000080, 0x00000000,   16384, 0x4, 0x4,     0, 0x0,  0,   0,      0, 0), -- Glyph of Ice Block
(56374,   0,  3, 0x00000000, 0x00004000, 0x00000008,   16384, 0x4, 0x4,     0, 0x0,  0,   0,      0, 0), -- Glyph of Icy Veins
(56375,   0,  3, 0x01000000, 0x00000000, 0x00000000,   65536, 0x4, 0x4,     0, 0x0,  0,   0,      0, 0), -- Glyph of Polymorph
(56800,   0,  8, 0x00000004, 0x00000000, 0x00000000,      16, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Backstab
(57870,   0,  9, 0x00800000, 0x00000000, 0x00000000,  262144, 0x2, 0x0,     0, 0x0,  0,   0,      0, 0), -- Glyph of Mend Pet
(58375,   0,  4, 0x00000000, 0x00000200, 0x00000000,      16, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Glyph of Blocking
(58642,   0, 15, 0x00000000, 0x08000000, 0x00000000,      16, 0x1, 0x4,     0, 0x0,  0,   0,      0, 0), -- Glyph of Scourge Strike
(58877,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Spirit Hunt
(59906,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x1,  0,   0,      0, 0), -- Swift Hand of Justice
(59915,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Discerning Eye of the Beast

(37447,   0,  3, 0x00000000, 0x00000100, 0x00000000,   16384, 0x4, 0x2,     0, 0x0,  0,   0,      0, 0), -- Improved Mana Gems
(61062,   0,  3, 0x00000000, 0x00000100, 0x00000000,   16384, 0x4, 0x2,     0, 0x0,  0,   0,      0, 0), -- Improved Mana Gems

(61257,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x5, 0x0,     0, 0x0,  0,   0,      0, 0), -- Runic Power Back on Snare/Root
(63280,   0, 11, 0x20000000, 0x00000000, 0x00000000,       0, 0x0, 0x4,     0, 0x0,  0,   0,      0, 0), -- Glyph of Totem of Wrath
(63320,   0,  5, 0x80040000, 0x00000000, 0x00008000,    1024, 0x7, 0x4,     0, 0x0,  0,   0,      0, 0), -- Glyph of Life Tap
(64890,   0, 10, 0x00000000, 0x00010000, 0x00000000,       0, 0x2, 0x2,     2, 0x0,  0,   0,      0, 0), -- Item - Paladin T8 Holy 2P Bonus
(64928,   0, 11, 0x00000001, 0x00000000, 0x00000000,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Item - Shaman T8 Elemental 4P Bonus
(65032,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- 321-Boombot Aura - do not require experience target
(67228,   0, 11, 0x00000000, 0x00001000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Item - Shaman T9 Elemental 4P Bonus (Lava Burst)
(69755,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x7, 0x4,     0, 0x0,  0,   0,  45000, 0), -- Purified Shard of the Scale
(69739,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x7, 0x4,     0, 0x0,  0,   0,  45000, 0), -- Shiny Shard of the Scale
(70723,   0,  7, 0x00000005, 0x00000000, 0x00000000,       0, 0x1, 0x2,     2, 0x0,  0,   0,      0, 0), -- Item - Druid T10 Balance 4P Bonus
(70664,   0,  7, 0x00000010, 0x00000000, 0x00000000,       0, 0x2, 0x0,     0, 0x0,  0,   0,      0, 0), -- Druid T10 Restoration 4P Bonus (Rejuvenation)
(70770,   0,  6, 0x00000800, 0x00000000, 0x00000000,       0, 0x2, 0x2,     0, 0x0,  0,   0,      0, 0), -- Item - Priest T10 Healer 2P Bonus
(70808,   0, 11, 0x00000100, 0x00000000, 0x00000000,       0, 0x2, 0x2,     2, 0x0,  0,   0,      0, 0), -- Item - Shaman T10 Restoration 4P Bonus
(70817,   0, 11, 0x00000000, 0x00001000, 0x00000000,   65536, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Item - Shaman T10 Elemental 4P Bonus
(70844,   0,  4, 0x00000100, 0x00000000, 0x00000000,       0, 0x0, 0x2,     0, 0x0,  0,   0,      0, 0), -- Item - Warrior T10 Protection 4P Bonus

(70672,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Gaseous Bloat
(72455,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Gaseous Bloat
(72832,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Gaseous Bloat
(72833,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x0, 0x0,     0, 0x0,  0,   0,      0, 0), -- Gaseous Bloat

(71756,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Ball of Flames Proc
(72782,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Ball of Flames Proc
(72783,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Ball of Flames Proc
(72784,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,   0,      0, 0), -- Ball of Flames Proc

(71406,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,  50,      0, 0), -- Anger Capacitor
(71545,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  0,  50,      0, 0), -- Anger Capacitor

(71880,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  1,   0,      0, 0), -- Item - Icecrown 25 Normal Dagger Proc
(71892,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x2,     0, 0x0,  1,   0,      0, 0), -- Item - Icecrown 25 Heroic Dagger Proc

(71519,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x4,     0, 0x0,  0,   0, 105000, 0), -- Deathbringer's Will
(71562,   0,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x1, 0x4,     0, 0x0,  0,   0, 105000, 0), -- Deathbringer's Will (Heroic)
(71564, 126,  0, 0x00000000, 0x00000000, 0x00000000,       0, 0x3, 0x2,     2, 0x0,  0,   0,      0, 5), -- Deadly Precision
(71761,   3,  0, 0x00000000, 0x00100000, 0x00000000,       0, 0x5, 0x2,   256, 0x0,  0,   0,      0, 0); -- Deep Freeze Immunity State

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_flametongue_weapon','spell_mage_imp_blizzard','spell_sha_imp_water_shield','spell_pal_heart_of_the_crusader','spell_warl_seed_of_corruption_dummy','spell_mage_magic_absorption','spell_warr_second_wind','spell_warl_soul_leech','spell_sha_lightning_overload','spell_rog_quick_recovery','spell_mage_arcane_potency','spell_mage_empowered_fire','spell_pal_spiritual_attunement','spell_pal_divine_purpose','spell_pal_judgements_of_the_wise','spell_hun_thrill_of_the_hunt','spell_mage_missile_barrage','spell_mage_hot_streak','spell_pri_imp_shadowform','spell_dk_butchery','spell_item_unstable_power','spell_item_restless_strength','spell_dru_leader_of_the_pack','spell_pri_aq_3p_bonus','spell_dru_revitalize','spell_dk_death_rune','spell_dk_vendetta','spell_dk_sudden_doom','spell_dk_wandering_plague','spell_dk_necrosis','spell_sha_static_shock','spell_sha_maelstrom_weapon','spell_sha_ancestral_awakening','spell_rog_deadly_brew','spell_rog_cut_to_the_chase','spell_pet_guard_dog','spell_hun_rapid_recuperation_trigger','spell_hun_hunting_party','spell_pal_righteous_vengeance','spell_pal_sheath_of_light','spell_pal_infusion_of_light','spell_pal_judgements_of_the_just','spell_warr_improved_spell_reflection','spell_pet_culling_the_herd','spell_pet_silverback','spell_sha_frozen_power','spell_pri_body_and_soul','spell_dk_threat_of_thassarian','spell_warl_seduction','spell_mage_combustion','spell_pri_vampiric_embrace','spell_item_alchemists_stone','spell_pal_judgement_of_light_heal','spell_pal_judgement_of_wisdom_mana','spell_twisted_reflection','spell_dru_t3_2p_bonus','spell_dru_t3_8p_bonus','spell_dru_t3_6p_bonus','spell_pal_t3_6p_bonus','spell_pri_t3_4p_bonus','spell_sha_t3_6p_bonus','spell_item_healing_touch_refund','spell_item_totem_of_flowing_water','spell_pal_seal_of_vengeance','spell_warl_seed_of_corruption_generic','spell_mark_of_malice','spell_sha_windfury_weapon','spell_dru_t4_2p_bonus','spell_anetheron_vampiric_aura','spell_item_frozen_shadoweave','spell_item_aura_of_madness','spell_pri_item_t6_trinket','spell_dru_item_t6_trinket','spell_sha_item_t6_trinket','spell_pal_item_t6_trinket','spell_item_dementia','spell_item_pet_healing','spell_warl_t4_2p_bonus_shadow','spell_warl_t4_2p_bonus_fire','spell_mage_gen_extra_effects','spell_uk_second_wind','spell_dru_maim_interrupt','spell_item_sunwell_exalted_caster_neck','spell_item_sunwell_exalted_melee_neck','spell_item_sunwell_exalted_tank_neck','spell_item_sunwell_exalted_healer_neck','spell_warl_glyph_of_corruption_nightfall','spell_dk_mark_of_blood','spell_dk_dancing_rune_weapon','spell_dk_unholy_blight','spell_dk_hungering_cold','spell_pal_sacred_shield_dummy','spell_pal_seal_of_corruption','spell_dru_glyph_of_rejuvenation','spell_dru_glyph_of_shred','spell_dru_glyph_of_rake','spell_dru_glyph_of_innervate','spell_dru_glyph_of_starfire_dummy','spell_pal_glyph_of_holy_light_dummy','spell_pal_glyph_of_divinity','spell_sha_tidal_force_dummy','spell_sha_glyph_of_healing_wave','spell_pri_glyph_of_dispel_magic','spell_mage_glyph_of_ice_block','spell_mage_glyph_of_icy_veins','spell_mage_glyph_of_polymorph','spell_rog_glyph_of_backstab','spell_hun_glyph_of_mend_pet','spell_pri_shadowfiend_death','spell_warr_glyph_of_blocking','spell_dk_glyph_of_scourge_strike','spell_sha_spirit_hunt','spell_hun_kill_command_pet','spell_item_swift_hand_justice_dummy','spell_item_discerning_eye_beast_dummy','spell_mage_imp_mana_gems','spell_gen_vampiric_touch','spell_dk_pvp_4p_bonus','spell_sha_glyph_of_totem_of_wrath','spell_warl_glyph_of_life_tap','spell_pal_t8_2p_bonus','spell_sha_t8_elemental_4p_bonus','spell_xt002_321_boombot_aura','spell_sha_t9_elemental_4p_bonus','spell_item_purified_shard_of_the_scale','spell_item_shiny_shard_of_the_scale','spell_dru_t10_balance_4p_bonus','spell_dru_t10_restoration_4p_bonus_dummy','spell_pri_t10_heal_2p_bonus','spell_sha_t10_restoration_4p_bonus','spell_sha_t10_elemental_4p_bonus','spell_warr_item_t10_prot_4p_bonus','spell_item_tiny_abomination_in_a_jar','spell_item_tiny_abomination_in_a_jar_hero','spell_item_deadly_precision_dummy','spell_item_deadly_precision','spell_item_heartpierce','spell_item_heartpierce_hero','spell_item_deathbringers_will_normal','spell_item_deathbringers_will_heroic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-10400, 'spell_sha_flametongue_weapon'),
(-11185, 'spell_mage_imp_blizzard'),
(-16180, 'spell_sha_imp_water_shield'),
(-20335, 'spell_pal_heart_of_the_crusader'),
(-27243, 'spell_warl_seed_of_corruption_dummy'),
(-29441, 'spell_mage_magic_absorption'),
(-29834, 'spell_warr_second_wind'),
(-30293, 'spell_warl_soul_leech'),
(-30675, 'spell_sha_lightning_overload'),
(-31244, 'spell_rog_quick_recovery'),
(-31571, 'spell_mage_arcane_potency'),
(-31656, 'spell_mage_empowered_fire'),
(-31785, 'spell_pal_spiritual_attunement'),
(-31871, 'spell_pal_divine_purpose'),
(-31876, 'spell_pal_judgements_of_the_wise'),
(-34497, 'spell_hun_thrill_of_the_hunt'),
(-44404, 'spell_mage_missile_barrage'),
(-44445, 'spell_mage_hot_streak'),
(-47569, 'spell_pri_imp_shadowform'),
(-48979, 'spell_dk_butchery'),
(-48539, 'spell_dru_revitalize'),

(-49208, 'spell_dk_death_rune'),
(-49467, 'spell_dk_death_rune'),
(-54639, 'spell_dk_death_rune'),

(-49015, 'spell_dk_vendetta'),
(-49018, 'spell_dk_sudden_doom'),
(-49217, 'spell_dk_wandering_plague'),
(-51459, 'spell_dk_necrosis'),
(-51525, 'spell_sha_static_shock'),
(-51556, 'spell_sha_ancestral_awakening'),
(-51625, 'spell_rog_deadly_brew'),
(-51664, 'spell_rog_cut_to_the_chase'),
(-53178, 'spell_pet_guard_dog'),
(-53228, 'spell_hun_rapid_recuperation_trigger'),
(-53290, 'spell_hun_hunting_party'),
(-53380, 'spell_pal_righteous_vengeance'),
(-53501, 'spell_pal_sheath_of_light'),
(-53569, 'spell_pal_infusion_of_light'),
(-53695, 'spell_pal_judgements_of_the_just'),
(-59088, 'spell_warr_improved_spell_reflection'),
(-61680, 'spell_pet_culling_the_herd'),
(-62764, 'spell_pet_silverback'),
(-63373, 'spell_sha_frozen_power'),
(-64127, 'spell_pri_body_and_soul'),
(-65661, 'spell_dk_threat_of_thassarian'),
(6358,   'spell_warl_seduction'),
(11129,  'spell_mage_combustion'),
(15286,  'spell_pri_vampiric_embrace'),
(17619,  'spell_item_alchemists_stone'),
(20185,  'spell_pal_judgement_of_light_heal'),
(20186,  'spell_pal_judgement_of_wisdom_mana'),
(21063,  'spell_twisted_reflection'),
(24658,  'spell_item_unstable_power'),
(24661,  'spell_item_restless_strength'),
(24932,  'spell_dru_leader_of_the_pack'),
(26169,  'spell_pri_aq_3p_bonus'),
(28716,  'spell_dru_t3_2p_bonus'),
(28719,  'spell_dru_t3_8p_bonus'),
(28744,  'spell_dru_t3_6p_bonus'),
(28789,  'spell_pal_t3_6p_bonus'),
(28809,  'spell_pri_t3_4p_bonus'),
(28823,  'spell_sha_t3_6p_bonus'),
(28847,  'spell_item_healing_touch_refund'),
(28849,  'spell_item_totem_of_flowing_water'),
(31801,  'spell_pal_seal_of_vengeance'),

(32863,  'spell_warl_seed_of_corruption_generic'),
(36123,  'spell_warl_seed_of_corruption_generic'),
(38252,  'spell_warl_seed_of_corruption_generic'),
(39367,  'spell_warl_seed_of_corruption_generic'),
(44141,  'spell_warl_seed_of_corruption_generic'),
(70388,  'spell_warl_seed_of_corruption_generic'),

(33493,  'spell_mark_of_malice'),
(33757,  'spell_sha_windfury_weapon'),
(37288,  'spell_dru_t4_2p_bonus'),
(37295,  'spell_dru_t4_2p_bonus'),
(38196,  'spell_anetheron_vampiric_aura'),
(39372,  'spell_item_frozen_shadoweave'),
(39446,  'spell_item_aura_of_madness'),
(40438,  'spell_pri_item_t6_trinket'),
(40442,  'spell_dru_item_t6_trinket'),
(40463,  'spell_sha_item_t6_trinket'),
(40470,  'spell_pal_item_t6_trinket'),
(41404,  'spell_item_dementia'),

(37381,  'spell_item_pet_healing'),

(37377,  'spell_warl_t4_2p_bonus_shadow'),
(39437,  'spell_warl_t4_2p_bonus_fire'),

(44401,  'spell_mage_gen_extra_effects'),
(48108,  'spell_mage_gen_extra_effects'),
(57761,  'spell_mage_gen_extra_effects'),

(42770,  'spell_uk_second_wind'),
(44835,  'spell_dru_maim_interrupt'),
(45481,  'spell_item_sunwell_exalted_caster_neck'),
(45482,  'spell_item_sunwell_exalted_melee_neck'),
(45483,  'spell_item_sunwell_exalted_tank_neck'),
(45484,  'spell_item_sunwell_exalted_healer_neck'),

(-18094, 'spell_warl_glyph_of_corruption_nightfall'),
(56218,  'spell_warl_glyph_of_corruption_nightfall'),

(49005,  'spell_dk_mark_of_blood'),
(49028,  'spell_dk_dancing_rune_weapon'),
(49194,  'spell_dk_unholy_blight'),
(51209,  'spell_dk_hungering_cold'),
(53601,  'spell_pal_sacred_shield_dummy'),
(53736,  'spell_pal_seal_of_corruption'),
(53817,  'spell_sha_maelstrom_weapon'),
(54754,  'spell_dru_glyph_of_rejuvenation'),
(54815,  'spell_dru_glyph_of_shred'),
(54821,  'spell_dru_glyph_of_rake'),
(54832,  'spell_dru_glyph_of_innervate'),
(54845,  'spell_dru_glyph_of_starfire_dummy'),
(54937,  'spell_pal_glyph_of_holy_light_dummy'),
(54939,  'spell_pal_glyph_of_divinity'),
(55198,  'spell_sha_tidal_force_dummy'),
(55440,  'spell_sha_glyph_of_healing_wave'),
(55677,  'spell_pri_glyph_of_dispel_magic'),
(56372,  'spell_mage_glyph_of_ice_block'),
(56374,  'spell_mage_glyph_of_icy_veins'),
(56375,  'spell_mage_glyph_of_polymorph'),
(56800,  'spell_rog_glyph_of_backstab'),
(57870,  'spell_hun_glyph_of_mend_pet'),
(57989,  'spell_pri_shadowfiend_death'),
(58375,  'spell_warr_glyph_of_blocking'),
(58642,  'spell_dk_glyph_of_scourge_strike'),
(58877,  'spell_sha_spirit_hunt'),
(58914,  'spell_hun_kill_command_pet'),
(59906,  'spell_item_swift_hand_justice_dummy'),
(59915,  'spell_item_discerning_eye_beast_dummy'),

(37447,  'spell_mage_imp_mana_gems'),
(61062,  'spell_mage_imp_mana_gems'),

(52723,  'spell_gen_vampiric_touch'),
(60501,  'spell_gen_vampiric_touch'),
(61257,  'spell_dk_pvp_4p_bonus'),
(63280,  'spell_sha_glyph_of_totem_of_wrath'),
(63320,  'spell_warl_glyph_of_life_tap'),
(64890,  'spell_pal_t8_2p_bonus'),
(64928,  'spell_sha_t8_elemental_4p_bonus'),
(65032,  'spell_xt002_321_boombot_aura'),
(67228,  'spell_sha_t9_elemental_4p_bonus'),
(69755,  'spell_item_purified_shard_of_the_scale'),
(69739,  'spell_item_shiny_shard_of_the_scale'),
(70723,  'spell_dru_t10_balance_4p_bonus'),
(70664,  'spell_dru_t10_restoration_4p_bonus_dummy'),
(70770,  'spell_pri_t10_heal_2p_bonus'),
(70808,  'spell_sha_t10_restoration_4p_bonus'),
(70817,  'spell_sha_t10_elemental_4p_bonus'),
(70844,  'spell_warr_item_t10_prot_4p_bonus'),

(71406,  'spell_item_tiny_abomination_in_a_jar'),
(71545,  'spell_item_tiny_abomination_in_a_jar_hero'),

(71563,  'spell_item_deadly_precision_dummy'),
(71564,  'spell_item_deadly_precision'),

(71880,  'spell_item_heartpierce'),
(71892,  'spell_item_heartpierce_hero'),

(71519,  'spell_item_deathbringers_will_normal'),
(71562,  'spell_item_deathbringers_will_heroic');
