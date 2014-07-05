DELETE FROM `spell_script_names` WHERE `spell_id` IN (-20254,-20138,31869,-53379);


DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_warl_banish'
);

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(710,  'spell_warl_banish');
