-- DELETE FROM `creature_ai_scripts` WHERE `action1_type`=27; 4.x removed

-- INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`) VALUES
--   ('343001', '3430', '0', '0', '100', '0', '0', '0', '0', '0', '27', '5043', '17013', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Mangletooth - Cast Agamaggan''s Agility on Quest Complete'),
--   ('343002', '3430', '0', '0', '100', '0', '0', '0', '0', '0', '27', '5042', '16612', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Mangletooth - Cast Agamaggan''s Strength on Quest Complete'),
--   ('343003', '3430', '0', '0', '100', '0', '0', '0', '0', '0', '27', '5046', '16610', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Mangletooth - Cast Razorhide on Quest Complete'),
--   ('343004', '3430', '0', '0', '100', '0', '0', '0', '0', '0', '27', '5045', '10767', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Mangletooth - Cast Rising Spirit on Quest Complete'),
--   ('343005', '3430', '0', '0', '100', '0', '0', '0', '0', '0', '27', '889', '16618', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Mangletooth - Cast Spirit of the Wind on Quest Complete'),
--   ('343006', '3430', '0', '0', '100', '0', '0', '0', '0', '0', '27', '5044', '7764', '0', '0', '0', '0', '0', '0', '0', '0', '0', 'Mangletooth - Cast Wisdom of Agamaggan on Quest Complete');

UPDATE `smart_scripts` SET `action_type`=33, `action_param2`=0 WHERE `source_type`=0 AND `action_type`=27; -- by VM

-- all quests that used RequiredSpellCastX fields
UPDATE `quest_template` SET `SpecialFlags`=`SpecialFlags`|32 WHERE `Id` IN
(28,29,532,553,849,877,905,974,2118,2932,2994,3825,5096,5163,5165,5441,
6124,6129,6381,6395,6661,8346,8889,9066,9169,9193,9275,9294,9391,9440,
9444,9447,9489,9526,9600,9629,9667,9685,9720,9805,9824,9874,9910,10011,
10078,10087,10129,10144,10146,10182,10208,10233,10240,10305,10306,10307,
10313,10335,10345,10392,10426,10446,10447,10488,10545,10564,10598,10637,
10688,10714,10771,10792,10802,10808,10813,10833,10859,10866,10895,10913,
10923,10935,11055,11150,11205,11232,11245,11247,11258,11259,11285,11330,
11332,11421,11496,11515,11523,11542,11543,11547,11568,11576,11582,11610,
11617,11637,11656,11677,11684,11694,11713,11880,12092,12094,12096,12154,
12172,12173,12180,12213,12232,12267,12417,12449,12502,12588,12591,12598,
12641,12669,12728,12859,13110,13119,13211);
