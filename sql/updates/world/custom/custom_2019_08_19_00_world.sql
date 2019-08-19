DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_item_egg_shell',
'spell_item_song_of_sorrow',
'spell_item_crescendo_of_suffering',
'spell_item_proc_armor',
'spell_item_proc_mastery_below_35',
'spell_item_hearts_judgement',
'spell_item_hearts_judgement_heroic',
'spell_item_forged_fury');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(91296, 'spell_item_egg_shell'),
(91308, 'spell_item_egg_shell'),
(90998, 'spell_item_song_of_sorrow'),
(91003, 'spell_item_song_of_sorrow'),
(90996, 'spell_item_crescendo_of_suffering'),
(91002, 'spell_item_crescendo_of_suffering'),
(92180, 'spell_item_proc_armor'),
(92185, 'spell_item_proc_armor'),
(92236, 'spell_item_proc_mastery_below_35'),
(92356, 'spell_item_proc_mastery_below_35'),
(91041, 'spell_item_hearts_judgement'),
(92328, 'spell_item_hearts_judgement_heroic'),
(92328, 'spell_item_forged_fury');

DELETE FROM `spell_proc` WHERE `SpellId` IN (90998, 91003);
SET @PROC_FLAG := 0 | 0x00010000;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0 | 0x2;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(90998, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 0),
(91003, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 0);

DELETE FROM `spell_proc` WHERE `SpellId` IN (92180, 92185, 92236, 92356);
SET @PROC_FLAG := 0 | 0x00000028;
SET @TYPE_MASK := 0 | 0x1;
SET @PHASE_MASK := 0;
SET @HIT_MASK := 0;

INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(92180, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 30000),
(92185, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 30000),
(92236, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 30000),
(92356, @PROC_FLAG, @TYPE_MASK, @PHASE_MASK, @HIT_MASK, 30000);
