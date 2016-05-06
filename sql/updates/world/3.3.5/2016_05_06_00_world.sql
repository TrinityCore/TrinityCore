-- Blood Queen Lana'thel - fix issues with Uncontrollable Frenzy being cast on herself
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`= 70923 and `spell_effect`= 70924;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_blood_queen_uncontrollable_frenzy';
INSERT INTO `spell_script_names` VALUES (70923,'spell_blood_queen_uncontrollable_frenzy');
