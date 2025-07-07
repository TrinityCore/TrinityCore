DELETE FROM `spell_proc` WHERE `SpellId` IN (469172);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(469172,0x00,15,0x00000000,0x00000000,0x00000000,0x00000000,0x0,0x0,0x0,0x1,0x0,0x8,0x0,0,0,0,0); -- Reaper of Souls

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_soul_reaper';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_soul_reaper_reaper_of_souls';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dk_reaper_of_souls';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(343294, 'spell_dk_soul_reaper'),
(469180, 'spell_dk_soul_reaper_reaper_of_souls'),
(343294, 'spell_dk_reaper_of_souls');
