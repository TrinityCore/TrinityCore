DELETE FROM `spell_proc` WHERE `SpellId` IN (92207, 92209);

SET @PROC_FLAG := 0 | 0x00000028;
SET @TYPE_MASK := 0 | 0x00000001;
SET @PHASE_MASK := 0 | 0x00000000;
SET @HIT_MASK := 0 | 0x00000020;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(92207, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 60000), -- Throngus' Finger
(92209, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 60000); -- Throngus' Finger
