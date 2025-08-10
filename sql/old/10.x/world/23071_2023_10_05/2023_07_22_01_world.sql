DELETE FROM `spell_proc` WHERE `SpellId` IN (405554);
INSERT INTO `spell_proc` (`SpellId`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`SpellFamilyMask3`,`ProcFlags`,`ProcFlags2`,`SpellTypeMask`,`SpellPhaseMask`,`HitMask`,`AttributesMask`,`DisableEffectsMask`,`ProcsPerMinute`,`Chance`,`Cooldown`,`Charges`) VALUES
(405554,0x00,6,0x00000000,0x00000000,0x00000000,0x00400000,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0,0,0,0); -- Priest Holy 10.1 Class Set 2pc

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_pri_prayer_of_mending',        -- reassigned to different spell
'spell_pri_prayer_of_mending_aura',   -- deleted
'spell_pri_prayer_of_mending_dummy',  -- new script
'spell_pri_prayer_of_mending_heal',   -- new script
'spell_pri_holy_10_1_class_set_2pc'); -- new script
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(33076, 'spell_pri_prayer_of_mending_dummy'),
(411097, 'spell_pri_prayer_of_mending_dummy'),
(41635, 'spell_pri_prayer_of_mending'),
(33110, 'spell_pri_prayer_of_mending_heal'),
(405554, 'spell_pri_holy_10_1_class_set_2pc');
