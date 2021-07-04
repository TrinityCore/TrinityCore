-- Fingers of Frost
DELETE FROM `spell_proc` WHERE `SpellId`=44544;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(44544,0,3,0,0,0,0x100,0x10000,0,0x4,0x3FFF,0,0,0,100,0,0); -- PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG; PROC_SPELL_PHASE_FINISH; PROC_HIT_MASK_ALL

-- mage ice lance
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_fingers_of_frost';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_ice_lance';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_ice_lance_damage';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(44544,'spell_mage_fingers_of_frost'),
(30455,'spell_mage_ice_lance'),
(228598,'spell_mage_ice_lance_damage');
