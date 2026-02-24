DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_bladestorm_brutal_finish');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(227847,'spell_warr_bladestorm_brutal_finish'), -- Brutal Finish
(446035,'spell_warr_bladestorm_brutal_finish'); -- Brutal Finish

DELETE FROM `spell_proc` WHERE `SpellId` IN (446918);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(446918,0x00,4,0x02000000,0x00000000,0x00000000,0x00001000,0x0,0x0,0x0,0x4,0x0,0x10,0x0,0,0,0,0); -- Brutal Finish
