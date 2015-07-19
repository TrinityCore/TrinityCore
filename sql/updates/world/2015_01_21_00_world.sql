--
DELETE FROM `spell_script_names` WHERE `spell_id`=70903 AND `ScriptName`='spell_cultist_dark_martyrdrom';
DELETE FROM `spell_script_names` WHERE `spell_id`=71236 AND `ScriptName`='spell_cultist_dark_martyrdrom';
UPDATE `spell_script_names` SET `ScriptName`='spell_cultist_dark_martyrdom' WHERE `spell_id` IN (72495,72496,72497,72498,72499,72500);
