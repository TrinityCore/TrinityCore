DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dh_retaliation';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(203819,'spell_dh_retaliation');

DELETE FROM `spell_threat` WHERE `entry`=391159;
INSERT INTO `spell_threat` (`entry`,`flatMod`,`pctMod`,`apPctMod`) VALUES
(391159,0,4,0);
