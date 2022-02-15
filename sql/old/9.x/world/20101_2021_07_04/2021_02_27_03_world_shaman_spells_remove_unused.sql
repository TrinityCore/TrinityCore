-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_sha_fire_nova');
