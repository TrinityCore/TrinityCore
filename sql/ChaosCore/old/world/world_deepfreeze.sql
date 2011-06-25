DELETE FROM `playercreateinfo_spell` WHERE `Spell` IN ('71761'); 
INSERT INTO `playercreateinfo_spell` (`race`, `class`, `Spell`, `Note`) VALUES 
('1','8','71761','Deep Freeze Immunity State'), 
('5','8','71761','Deep Freeze Immunity State'), 
('7','8','71761','Deep Freeze Immunity State'), 
('8','8','71761','Deep Freeze Immunity State'), 
('10','8','71761','Deep Freeze Immunity State'),
('11','8','71761','Deep Freeze Immunity State');

DELETE FROM `spell_bonus_data` WHERE `entry` IN ('71757'); 
INSERT INTO `spell_bonus_data` (`entry`, `direct_bonus`, `dot_bonus`, `ap_bonus`, `ap_dot_bonus`, `comments`) VALUES 
('71757','2.143','0','0','0','Mage - Deep Freeze');
DELETE FROM `spell_proc_event` WHERE `entry` IN ('71761'); 
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES 
('71761','0','3','0','1048576','0','0','256','0','0','0'); -- Deep Freeze Immunity State 