DELETE FROM `spell_proc_event` WHERE `entry` IN (34948, 34949);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(34948, 0, 0, 0, 0, 0, 4, 0),
(34949, 0, 0, 0, 0, 0, 4, 0);

DELETE FROM `spell_proc_event` WHERE `entry` IN (34497, 34498, 34499);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(34497, 0, 0, 0, 0, 0, 4194304, 0),
(34498, 0, 0, 0, 0, 0, 4194304, 0),
(34499, 0, 0, 0, 0, 0, 4194304, 0);


DELETE FROM `spell_proc_event` WHERE `entry` IN (34500, 34502, 34503);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(34500, 0, 0, 0, 0, 0, 4194304, 0),
(34502, 0, 0, 0, 0, 0, 4194304, 0),
(34503, 0, 0, 0, 0, 0, 4194304, 0); 

DELETE FROM `spell_proc_event` WHERE `entry` IN (30823);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(30823, 0, 0, 0, 0, 0, 1, 0);


DELETE FROM `spell_proc_event` WHERE `entry` IN (31244,31245);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(31244, 0, 0, 0, 0, 0, 2147483648, 0),
(31245, 0, 0, 0, 0, 0, 2147483648, 0);


DELETE FROM `spell_proc_event` WHERE `entry` IN (34935,34938,34939);
INSERT INTO `spell_proc_event` (entry, SchoolMask, Category, SkillID, SpellFamilyName, SpellFamilyMask, procFlags, ppmRate) VALUES 
(34935, 0, 0, 0, 0, 0, 2, 0),
(34938, 0, 0, 0, 0, 0, 2, 0), 
(34939, 0, 0, 0, 0, 0, 2, 0); 
