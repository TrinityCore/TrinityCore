DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_pri_mind_spike',
'spell_pri_harnessed_shadows');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(73510, 'spell_pri_mind_spike'),
(-33191, 'spell_pri_harnessed_shadows');

UPDATE `spell_proc` SET `ProcFlags`= 0, `SpellPhaseMask`= 1 WHERE `SpellId`= 77486;
UPDATE `spell_proc` SET `ProcFlags`= 0x00050000, `SpellPhaseMask`= 1 WHERE `SpellId`= 95740;
UPDATE `spell_proc` SET `SpellFamilyMask0`= 0, `SpellFamilyMask1`= 0, `SpellFamilyMask2`= 0, `HitMask`= 2 WHERE `SpellId`= -33191;
