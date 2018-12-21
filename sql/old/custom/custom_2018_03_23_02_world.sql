DELETE FROM `spell_proc` WHERE `SpellId` IN (
90848, -- Item - Proc Spell Power
90886, -- Item - Proc Haste Rating
90888, -- Item - Proc Haste Rating
90892, -- Item - Proc Crit Rating
90897, -- Item - Proc Spell Power
90899, -- Item - Proc Spell Power
90990, -- Item - Proc Spell Power
90993, -- Item - Proc Spell Power
95878, -- Item - Proc Mastery Rating
90943, -- Item - Proc Stacking Spell Power
90986, -- Item - Proc Stacking Spell Power
91011, -- Item - Proc Spell Power On Dmg
91025, -- Item - Proc Mastery
91031, -- Item - Proc Stacking Spell Power
91048, -- Item - Proc Spell Power
91080, -- Item - Proc Wandering DoT
91137, -- Item - Proc Spirit On Crit
91140, -- Item - Proc Spirit On Crit
91142, -- Item - Proc Haste Rating
91144, -- Item - Proc Haste Rating
91148, -- Item - Proc Spirit
91150, -- Item - Proc Spirit
91186, -- Item - Proc Spirit
91193, -- Item - Proc Intellect
91321, -- Item - Proc Stacking Spirit
91339, -- Item - Proc Stacking Strength
91353, -- Item - Proc Haste On Crit
91361, -- Item - Proc Strength
91365, -- Item - Proc Strength
91366, -- Item - Proc Strength On Crit
91369, -- Item - Proc Strength On Crit
91811, -- Item - Proc Stacking Strength
91814, -- Item - Proc Strength
91817, -- Item - Proc Strength
91822, -- Item - Proc Haste Rating
91833, -- Item - Proc Stacking Activator (5)
92044, -- Item - Proc Haste Rating
92054, -- Item - Proc Crit Rating
92056, -- Item - Proc Haste On Crit
92070, -- Item - Proc Agility
92086, -- Item - Proc Stacking Agility
92088, -- Item - Proc Crit Rating
92090, -- Item - Proc Stacking Agility
92093, -- Item - Proc Agility
92095, -- Item - Proc Agility On Crit
92097, -- Item - Proc Agility On Crit
92105, -- Item - Proc Stacking Agility
92114, -- Item - Proc Increased Attack Power
92125, -- Item - Proc Haste Rating
92127, -- Item - Proc Crit Rating
92164, -- Item - Proc Mastery Rating
92175, -- Item - Proc Mastery Rating
92319, -- Item - Proc Spell Power On Dmg
92322, -- Item - Proc Mastery
92326, -- Item - Proc Stacking Spell Power
92330, -- Item - Proc Stacking Spirit
92333, -- Item - Proc Spirit
92343, -- Item - Proc Haste Rating
92346, -- Item - Proc Strength
92350, -- Item - Proc Haste Rating
92353, -- Item - Proc Crit Rating
95763, -- Item - Proc Haste Rating
95873); -- Item - Proc Crit Rating - hw

-- Your melee and ranged critical strikes have a chance to grant stat_value for x seconds.
SET @PROC_FLAG := 0 | 0x00000154;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000002;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(92056, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000), -- Gear Detector 
(92095, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Left Eye of Rajh
(92097, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000);

-- Your melee and ranged attacks have a chance to grant x stat_value for x seconds.
SET @PROC_FLAG := 0 | 0x00000154;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000000;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(92044, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000), -- Bileberry Smelling Salts
(92054, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Grace of the Herald - Heart of the Vile
(92070, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Key to the Endless Chamber
(92093, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000),
(92086, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000), -- Tia's Grace
(92090, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(92088, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Grace of the Herald
(92105, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000), -- Fluid Death
(92125, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Prestor's Talisman of Machination
(92127, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Essence of the Cyclone
(92353, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000),
(95763, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000), -- Agony and Torment
(95873, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000); -- Herald of Doom

-- Your melee critical strikes have a chance to grant x stat_value for x seconds.
SET @PROC_FLAG := 0 | 0x00000014;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000002;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(91353, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000), -- Shrine-Cleansing Purifier - Tank-Commander Insignia
(91366, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Right Eye of Rajh
(91369, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000);

-- Your melee attacks grant / Your melee attacks have a chance to grant x stat_value.
SET @PROC_FLAG := 0 | 0x00000014;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000000;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(91339, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000), -- Petrified Spider Crab
(91361, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000), -- Heart of Solace
(91365, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(91811, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000), -- License to Slay 
(91814, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000), -- Impetuous
(91817, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000), -- Heart of Rage
(92346, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(91822, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Crushing Weight
(92343, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000),
(91833, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 5000), -- Fury of Angerforge
(92114, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Unheeded Warning
(92164, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000), -- Porcelain Crab - Harrison's Insignia of Panache - Schnottz's Medallion of Command 
(92175, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000); -- Porcelain Crab

-- Your healing spells have a chance to grant x stat_value for x seconds.
SET @PROC_FLAG := 0 | 0x00044000;
SET @TYPE_MASK := 0 | 0x00000002;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000000;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(91142, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Rainsong
(91144, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000),
(91148, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000), -- Blood of Isiset
(91150, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(91186, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Fall of Morality
(92333, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000),
(91193, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Mandala of Stirring Patterns
(91321, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000), -- Jar of Ancient Remedies
(92330, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);

-- Your healing spell critical strikes have a chance to grant x stat_value for x seconds.
SET @PROC_FLAG := 0 | 0x00044000;
SET @TYPE_MASK := 0 | 0x00000002;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000002;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(91137, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Tear of Blood
(91140, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000);

-- Your damage spells grant X, increasing stat_value for x seconds.
SET @PROC_FLAG_P := 0 | 0x00050000;
SET @PROC_FLAG_N := 0 | 0x00010000;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000000;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(91031, @PROC_FLAG_P, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000), -- Heart of Ignacious
(92326, @PROC_FLAG_P, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);

-- Your harmful spells have a chance to grant x stat_value for x seconds.
SET @PROC_FLAG_P := 0 | 0x00050000;
SET @PROC_FLAG_N := 0 | 0x00010000;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000000;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(91011, @PROC_FLAG_P, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000), -- Bell of Enraging Resonance
(92319, @PROC_FLAG_P, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(91025, @PROC_FLAG_N, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Theralion's Mirror
(92322, @PROC_FLAG_N, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000),
(91048, @PROC_FLAG_N, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Stump of Time
(91080, @PROC_FLAG_N, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 120000); -- Harmlight Token 

-- Your spells have a chance to grant x stat_value for x seconds.
SET @PROC_FLAG := 0 | 0x00014000;
SET @TYPE_MASK := 0 | 0x00000007;
SET @PHASE_MASK := 0 | 0x00000001;
SET @HIT_MASK := 0 | 0x00000000;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(90848, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000), -- Pelagic Prism
(90886, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Witching Hourglass
(90888, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000),
(90892, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000), -- Stonemother's Kiss
(90897, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000), -- Tendrills of Darkness
(90899, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 75000),
(90990, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000), -- Anhuur's Hymnal
(90993, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000),
(95878, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 80000); -- Talisman of Sinister Order

-- Your healing and damage periodic spells grant x stat_value each time they heal or deal damage.
SET @PROC_FLAG := 0 | 0x00040000;
SET @TYPE_MASK := 0 | 0x00000001 | 0x00000002;
SET @PHASE_MASK := 0 | 0x00000002;
SET @HIT_MASK := 0 | 0x00000000;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(90943, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000), -- Gale of Shadows
(90986, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);
