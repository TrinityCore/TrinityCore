DELETE FROM `spell_proc` WHERE `SpellId` IN (77486, 95740, 77487);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(95740, 0, 6, 0x00008000, 0x0, 0x00000440, 0x00050000, 1, 2, 0, 0, 0, 10,  0, 0),
(77486, 0, 6, 0x00008000, 0x0, 0x00000440, 0x00050000, 1, 2, 0, 32, 0, 10,  0, 0),
(77487, 0, 6, 0x00002000, 0x0, 0x00010000, 0x00010000, 1, 1, 0, 0,  0, 100, 0, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pri_shadow_orbs',
'spell_pri_shadow_orb_power',
'spell_pri_shadow_orb');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(95740,'spell_pri_shadow_orbs'),
(77486,'spell_pri_shadow_orb_power'),
(77487,'spell_pri_shadow_orb');
