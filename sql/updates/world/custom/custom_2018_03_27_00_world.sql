DELETE FROM `spell_proc` WHERE `SpellId`= 52007;
INSERT INTO `spell_proc` (`SpellId`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `Cooldown`) VALUES
(52007, 0x00044000, 0x00000002, 0x00000002, 0x00000000, 0); -- Earthliving Weapon (Passive)

DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_sha_earthliving_weapon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52007, 'spell_sha_earthliving_weapon');
