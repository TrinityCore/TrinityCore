DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_mother_shahraz_fatal_attraction',
'spell_mother_shahraz_fatal_attraction_link',
'spell_mother_shahraz_saber_lash',
'spell_mother_shahraz_generic_periodic',
'spell_mother_shahraz_random_periodic');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(40869,'spell_mother_shahraz_fatal_attraction'),
(40870,'spell_mother_shahraz_fatal_attraction_link'),
(40816,'spell_mother_shahraz_saber_lash'),
(40863,'spell_mother_shahraz_generic_periodic'),
(40865,'spell_mother_shahraz_generic_periodic'),
(40866,'spell_mother_shahraz_generic_periodic'),
(40862,'spell_mother_shahraz_generic_periodic'),
(40867,'spell_mother_shahraz_random_periodic');

DELETE FROM `creature_addon` WHERE `guid`=52760;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(52760, 0, 0, 0, 0, 0, 40816);

DELETE FROM `creature_text` WHERE `CreatureID`=22947 AND `GroupID` IN(6,7);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `Comment`) VALUES
(22947, 6, 0, '%s goes into a frenzy!', 41, 0, 100, 0, 0, 0, 2384, 0, 'shahraz EMOTE_ENRAGE'),
(22947, 7, 0, '%s goes into a berserker rage!', 16, 0, 100, 0, 0, 0, 4428, 0, 'shahraz EMOTE_BERSERK');
