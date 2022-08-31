-- Judgements of the Just Talent
DELETE FROM `spell_proc` WHERE `SpellId`= -53695;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(-53695, 10, 0x800000 , 0x1, 0x2, 0x0);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_pal_judgements_of_the_just';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-53695, 'spell_pal_judgements_of_the_just');
