-- 228974 - Soul Leech Base
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_soul_leech_base';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(228974, 'spell_warl_soul_leech_base');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_warl_soul_leech_aura';

-- 265259 - Twist of fate
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_twist_of_fate';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(265259, 'spell_pri_twist_of_fate');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_shadowy_apparitions';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(78203, 'spell_pri_shadowy_apparitions');

DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_pri_mind_blast';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(8092, 'spell_pri_mind_blast');

-- 162452 - Shadowy Insight
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_shadowy_insight';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(162452, 'spell_pri_shadowy_insight');

-- 49821 - Shadowy Insight
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_mind_sear';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(49821, 'spell_pri_mind_sear');

-- 48045 - Mind_Sear_Base
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_pri_mind_sear_base';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(48045, 'spell_pri_mind_sear_base');

-- Exploit
DELETE FROM conditions WHERE SourceTypeOrReferenceId = 17 AND SourceEntry IN (252804);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`) VALUES
(17, 252804, 31, 1, 5, 127253);