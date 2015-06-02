UPDATE `creature_template` SET
`spell1` = 62225, -- Claw
`spell2` = 47480, -- Thrash
`spell3` = 47481, -- Gnaw
`spell4` = 47482, -- Leap
`spell5` = 47484, -- Huddle
`spell6` = 47496 -- Explode
WHERE `entry` = 30230;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_raise_ally_initial', 'spell_dk_raise_ally', 'spell_dk_ghoul_thrash');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61999, 'spell_dk_raise_ally_initial'),  
(46619, 'spell_dk_raise_ally'),
(47480, 'spell_dk_ghoul_thrash');
