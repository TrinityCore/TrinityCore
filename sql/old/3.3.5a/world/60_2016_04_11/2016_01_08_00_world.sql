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

DELETE FROM `spell_dbc` WHERE `Id`=62214;
INSERT INTO `spell_dbc` (`Id`,`Attributes`,`AttributesEx`,`AttributesEx2`,`AttributesEx3`,`AttributesEx4`,`AttributesEx5`,`AttributesEx6`,`DurationIndex`,`RangeIndex`,`Effect1`,`EffectImplicitTargetA1`,`EffectApplyAuraName1`,`Comment`) VALUES
(62214,0xA9800100,0x10000420,0x10084005,0x00130000,0x00800080,0x00060008,0x00001404,21,13,6,25,279,'Mirror Name');
