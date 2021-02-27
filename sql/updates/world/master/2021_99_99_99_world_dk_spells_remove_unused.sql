-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_unholy_blight');
