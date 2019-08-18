DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107961, -- Item - Dragon Soul Stacking Agility Trinket
109718, -- Item - Dragon Soul Stacking Agility Trinket
109720); -- Item - Dragon Soul Stacking Agility Trinket

-- Your Attacks grant x Agility for the next x seconds.
SET @PROC_FLAG := 0 | 0x00000154;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000001;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107961, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109718, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109720, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);

DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107963, -- Item - Dragon Soul Stacking Healer Trinket
109812, -- Item - Dragon Soul Stacking Healer Trinket
109814); -- Item - Dragon Soul Stacking Healer Trinket

-- Your healing spells grant x Spirit for the next x seconds.
SET @PROC_FLAG := 0 | 0x00004000;
SET @TYPE_MASK := 0 | 0x00000002;
SET @PHASE_MASK := 0 | 0x00000001;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107963, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109812, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109814, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);

DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107967, -- Item - Dragon Soul Stacking Strength Trinket
109749, -- Item - Dragon Soul Stacking Strength Trinket
109751); -- Item - Dragon Soul Stacking Strength Trinket

-- Your melee attacks grant x Strength for the next x seconds.
SET @PROC_FLAG := 0 | 0x00000014;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000001;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107967, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109749, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109751, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);

DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107969, -- Item - Dragon Soul Stacking Dodge Trinket
109781, -- Item - Dragon Soul Stacking Dodge Trinket
109783); -- Item - Dragon Soul Stacking Dodge Trinket

-- Your melee attacks grant x dodge rating for the next x seconds.
SET @PROC_FLAG := 0 | 0x00000014;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000001;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107969, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109781, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109783, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);

DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107971, -- Item - Dragon Soul Stacking Caster Trinket
109794, -- Item - Dragon Soul Stacking Caster Trinket
109796); -- Item - Dragon Soul Stacking Caster Trinket

-- Your harmful spells grant x Intellect for the next x seconds.
SET @PROC_FLAG := 0 | 0x00010000;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000001;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107971, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109794, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000),
(109796, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 2000);
