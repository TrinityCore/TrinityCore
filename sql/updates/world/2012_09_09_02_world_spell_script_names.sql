-- Gift of the Naaru
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_gift_of_naaru';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(28880,'spell_gen_gift_of_naaru'), -- SPELLFAMILY_WARRIOR
(59542,'spell_gen_gift_of_naaru'), -- SPELLFAMILY_PALADIN
(59543,'spell_gen_gift_of_naaru'), -- SPELLFAMILY_HUNTER
(59544,'spell_gen_gift_of_naaru'), -- SPELLFAMILY_PRIEST
(59545,'spell_gen_gift_of_naaru'), -- SPELLFAMILY_DEATHKNIGHT
(59547,'spell_gen_gift_of_naaru'), -- SPELLFAMILY_SHAMAN
(59548,'spell_gen_gift_of_naaru'); -- SPELLFAMILY_MAGE
