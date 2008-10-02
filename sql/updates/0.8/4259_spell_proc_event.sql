DELETE FROM `spell_proc_event` WHERE `entry` IN (30299,30301,30302);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(30299,36,0,0,0,0,1048576,0),
(30301,36,0,0,0,0,1048576,0),
(30302,36,0,0,0,0,1048576,0); 


DELETE FROM `spell_proc_event` WHERE `entry` IN (27168);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(27168,0,0,0,0,0,64,0); 

DELETE FROM `spell_proc_event` WHERE `entry` IN (27169);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(27169,0,0,0,0,0,64,0); 

DELETE FROM `spell_proc_event` WHERE `entry` IN (33150,33154);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(33150,0,0,0,0,0,65536,0),
(33154,0,0,0,0,0,65536,0); 
