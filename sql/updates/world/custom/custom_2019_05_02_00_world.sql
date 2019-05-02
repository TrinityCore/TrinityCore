DELETE FROM `spell_threat` WHERE `entry` IN (52212, 43265);
INSERT INTO `spell_threat` (`entry`, `flatMod`, `pctMod`, `apPctMod`) VALUES
-- Death and Decay
(52212, 0, 1.9, 0);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_warr_shockwave',
'spell_warr_throw');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(46968, 'spell_warr_shockwave');

UPDATE `spell_bonus_data` SET `ap_bonus`= 0 WHERE `entry`= 46968;
