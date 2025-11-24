DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pri_idol_of_cthun');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(377349, 'spell_pri_idol_of_cthun');

DELETE FROM `spell_proc` WHERE `SpellId` IN (377349);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(377349,0x00,6,0x00000000,0x00080000,0x00000040,0x00000000,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0,0,0,0); -- Idol of C'Thun

UPDATE `creature_template` SET `ScriptName` = 'npc_pet_pri_void_tendril' WHERE `entry` = 192337;
UPDATE `creature_template` SET `ScriptName` = 'npc_pet_pri_void_lasher' WHERE `entry` = 198757;
