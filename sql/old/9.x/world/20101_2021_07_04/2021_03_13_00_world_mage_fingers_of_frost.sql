DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_mage_fingers_of_frost';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(112965,'spell_mage_fingers_of_frost');

DELETE FROM `spell_proc` WHERE `SpellId`=112965;
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(112965,0,3,0,0x2000000,0x80,0,0x10000,0,0x1,0,0,0,0,100,0,0); -- Fingers of Frost, proc on launch of Frostbolt and Frozen Orb
