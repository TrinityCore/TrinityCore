DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_painful_punishment';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(390686,'spell_pri_painful_punishment');

DELETE FROM `spell_proc` WHERE `SpellId` IN (390686);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(390686,0x00,6,0x00000000,0x00008000,0x00000000,0x00000000,0x0,0x0,0x1,0x2,0x403,0x0,0x0,0,0,0,0); -- Painful Punishment
