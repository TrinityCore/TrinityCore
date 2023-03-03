-- Remove old unused spell scripts
DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_warr_concussion_blow',
'spell_warr_execute',
'spell_warr_lambs_to_the_slaughter',
'spell_warr_last_stand',
'spell_warr_overpower',
'spell_warr_rend',
'spell_warr_retaliation',
'spell_warr_second_wind_proc',
'spell_warr_second_wind_trigger',
'spell_warr_shattering_throw',
'spell_warr_slam',
'spell_warr_sword_and_board',
'spell_warr_vigilance',
'spell_warr_vigilance_trigger');
