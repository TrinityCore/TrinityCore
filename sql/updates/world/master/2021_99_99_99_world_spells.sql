-- Spell Proc
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_pal_auras', 'spell_gen_gift_of_naaru');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(317920, 'spell_pal_auras'),
(32223, 'spell_pal_auras'),
(465, 'spell_pal_auras'),
(183435, 'spell_pal_auras'),
(121093, 'spell_gen_gift_of_naaru'), -- Monk
(28880, 'spell_gen_gift_of_naaru'), -- Warrior
(59542, 'spell_gen_gift_of_naaru'), -- Paladin
(59543, 'spell_gen_gift_of_naaru'), -- Hunter
(59544, 'spell_gen_gift_of_naaru'), -- Priest
(59545, 'spell_gen_gift_of_naaru'), -- Death Knight
(59547, 'spell_gen_gift_of_naaru'), -- Shaman
(59548, 'spell_gen_gift_of_naaru'); -- Mage
