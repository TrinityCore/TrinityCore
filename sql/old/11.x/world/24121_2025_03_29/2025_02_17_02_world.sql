DELETE FROM `spell_script_names` WHERE `spell_id`=471195;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(471195, 'spell_pal_lay_on_hands');

-- Updating serverside spell 61988
UPDATE `serverside_spell` SET `DurationIndex`=3 WHERE `Id`=61988;
