DELETE FROM `spell_proc` WHERE `SpellId` IN (45092/*, 50871*/);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(45092, 0x0, 0, 0x00000000, 0x00000000, 0x00000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0, 0, 0, 0); -- Faction, Spar Buddy (SERVERSIDE) - needed to drop charge
-- (50871, 0x0, 9, 0x00000000, 0x40000000, 0x00000000, 0x0, 0x1, 0x2, 0x2, 0x0, 0, 0, 0, 0); -- Savage Rend

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_gen_aura_of_fear'/*,'spell_gen_choking_vines'*/);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(28313, 'spell_gen_aura_of_fear');
-- (35244, 'spell_gen_choking_vines');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_proc_charge_drop_only' AND `spell_id`=45092;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(45092, 'spell_gen_proc_charge_drop_only');
