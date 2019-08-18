DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107805, -- Item - Dragon Soul - Proc - Int Versatile Staff
109843, -- Item - Dragon Soul - Proc - Int Versatile Staff
109846); -- Item - Dragon Soul - Proc - Int Versatile Staff

SET @PROC_FLAG := 0 | 0x00014000;
SET @TYPE_MASK := 0 | 0x1 | 0x2;
SET @PHASE_MASK := 0 | 0x1;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107805, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 45000),
(109843, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 45000),
(109846, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 45000);

DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107824, -- Item - Dragon Soul - Proc - Agi Melee Polearm
109862, -- Item - Dragon Soul - Proc - Agi Melee Polearm
109865); -- Item - Dragon Soul - Proc - Agi Melee Polearm

SET @PROC_FLAG := 0 | 0x00000154;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0 | 0x1;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107824, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 55000),
(109862, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 55000),
(109865, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 55000);

DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107832, -- Item - Dragon Soul - Proc - Int Hit Dagger
109853, -- Item - Dragon Soul - Proc - Int Hit Dagger
109855); -- Item - Dragon Soul - Proc - Int Hit Dagger

SET @PROC_FLAG := 0 | 0x00010000;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0 | 0x1;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107832, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 15000),
(109853, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 15000),
(109855, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 15000);

DELETE FROM `spell_proc` WHERE `SpellId` IN 
(107836, -- Item - Dragon Soul - Proc - Int Spirit Mace 1H
109848, -- Item - Dragon Soul - Proc - Int Spirit Mace 1H
109850); -- Item - Dragon Soul - Proc - Int Spirit Mace 1H

SET @PROC_FLAG := 0 | 0x00044000;
SET @TYPE_MASK := 0 | 0x2;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107836, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 15000),
(109848, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 15000),
(109850, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 15000);

DELETE FROM `spell_proc` WHERE `SpellId` IN  (107983, 107987, 107989, 109710, 109712, 109743, 109745, 109775, 109777, 109788, 109790);

SET @PROC_FLAG := 0 | 0x00051154;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107983, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(107987, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(107989, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109710, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109712, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109743, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109745, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109775, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109777, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109788, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109790, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000);

DELETE FROM `spell_proc` WHERE `SpellId` IN (107984, 109803, 109805);

SET @PROC_FLAG := 0 | 0x00055554;
SET @TYPE_MASK := 0 | 0x2;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107984, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109803, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000),
(109805, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 100000);

DELETE FROM `spell_proc` WHERE `SpellId` IN (107998, 109753, 109755);

SET @PROC_FLAG := 0 | 0x00000014;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107998, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 25000),
(109753, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 25000),
(109755, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 25000);


DELETE FROM `spell_proc` WHERE `SpellId` IN (108006, 109799, 109801);

SET @PROC_FLAG := 0 | 0x00051000;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(108006, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 10000),
(109799, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 10000),
(109801, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 10000);

DELETE FROM `spell_proc` WHERE `SpellId` IN (107995, 109722, 109725);

SET @PROC_FLAG := 0 | 0x00000154;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(107995, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 10000),
(109722, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 10000),
(109725, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 10000);

DELETE FROM `spell_proc` WHERE `SpellId` IN (108002, 109823, 109826);

SET @PROC_FLAG := 0 | 0x00000154;
SET @TYPE_MASK := 0 | 0x2;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 2;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(108002, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 25000),
(109823, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 25000),
(109826, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 25000);

DELETE FROM `spell_proc` WHERE `SpellId`= 102658;

SET @PROC_FLAG := 0 | 0x00000154;
SET @TYPE_MASK := 0 | 0x2;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(102658, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000);

DELETE FROM `spell_proc` WHERE `SpellId`= 102663;

SET @PROC_FLAG := 0 | 0x00054000;
SET @TYPE_MASK := 0 | 0x2;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(102663, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000);

DELETE FROM `spell_proc` WHERE `SpellId` IN (102665, 109996, 102661, 102666);

SET @PROC_FLAG := 0 | 0x00000014;
SET @TYPE_MASK := 0 | 0x2;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(102665, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000),
(109996, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000),
(102661, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000),
(102666, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 50000);
