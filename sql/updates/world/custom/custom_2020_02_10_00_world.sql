UPDATE `creature_template_movement` SET `Rooted`= 1 WHERE `CreatureId` IN (41570, 51101, 51102, 51103);

DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_magmaw_massive_crash',
'spell_magmaw_impale_self');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(88253, 'spell_magmaw_massive_crash'),
(77907, 'spell_magmaw_impale_self');
