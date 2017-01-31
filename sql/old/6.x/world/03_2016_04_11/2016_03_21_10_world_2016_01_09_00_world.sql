--
-- Enable Landmine Knockback Achievement by removing it from disables
DELETE FROM `disables` WHERE `sourceType`= 4 AND `entry`= 5258;

-- Insert missing Landmine Knockback Achievement criteria data
DELETE FROM `achievement_criteria_data` WHERE `criteria_id`= 5258;
INSERT INTO `achievement_criteria_data` (`criteria_id`, `type`, `value1`, `value2`, `ScriptName`) VALUES
(5258,0,57064,0,'');

-- Update description for the linked spells 54355 and 54402
UPDATE `spell_linked_spell` SET `comment`= 'Trigger Detonation with Land Mine Knockback' WHERE `spell_trigger` = 54355;

-- Insert spell script name for spell 57099
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_landmine_knockback_achievement';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(57099,'spell_gen_landmine_knockback_achievement');
