DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_deeply_rooted_elements';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES 
(378270,'spell_sha_deeply_rooted_elements');

DELETE FROM `spell_proc` WHERE `SpellId`=378270;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(378270,0x00,11,0x00000000,0x00001010,0x00000010,0x00000000,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0,0,0,0); -- Deeply Rooted Elements

UPDATE `spell_proc` SET `SpellTypeMask`=0x5,`HitMask`=0x403 WHERE `SpellId`=378268; -- Windspeaker's Lava Resurgence
