-- Spell Scriptnames
DELETE FROM `spell_script_names` WHERE `ScriptName`= 'spell_gen_armor_specialization';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(86530, 'spell_gen_armor_specialization'),
(86531, 'spell_gen_armor_specialization'),
(86529, 'spell_gen_armor_specialization'),
(86528, 'spell_gen_armor_specialization'),
(86525, 'spell_gen_armor_specialization'),
(86524, 'spell_gen_armor_specialization'),
(86526, 'spell_gen_armor_specialization');

-- Correct wrong teaching spells
-- Warrior
UPDATE `npc_trainer` SET `SpellID`= 86526 WHERE `SpellID`= 87509;
-- Paladin
UPDATE `npc_trainer` SET `SpellID`= 86525 WHERE `SpellID`= 87511;
-- Death Knight
DELETE FROM `npc_trainer` WHERE `SpellID`= 86524;
INSERT INTO `npc_trainer` (`ID`, `SpellID`, `MoneyCost`, `ReqLevel`) VALUES
(200006, 86524, 22500, 50);
-- Shaman
UPDATE `npc_trainer` SET `SpellID`= 86529 WHERE `SpellID`= 87507;
-- Hunter
UPDATE `npc_trainer` SET `SpellID`= 86528 WHERE `SpellID`= 87506;
-- Rogue
UPDATE `npc_trainer` SET `SpellID`= 86531 WHERE `SpellID`= 87504;
-- Druid
UPDATE `npc_trainer` SET `SpellID`= 86530 WHERE `SpellID`= 87505;
