DELETE FROM `spell_proc` WHERE `SpellId`= 17007;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`) VALUES
(17007, 0, 0x00000014, 0x00000001, 0x00000002, 0x00000002, 0x0, 6000);

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_dru_leader_of_the_pack';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(17007, 'spell_dru_leader_of_the_pack');
