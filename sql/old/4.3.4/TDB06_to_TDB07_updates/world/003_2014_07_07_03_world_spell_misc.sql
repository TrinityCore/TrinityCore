DELETE FROM `spell_script_names` WHERE `spell_id`=70811;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(70811,'spell_sha_item_t10_elemental_2p_bonus');
 
DELETE FROM `spell_proc_event` WHERE `entry`=70811;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(70811, 0, 11, 3, 0, 0, 0, 0, 0, 0, 0);
