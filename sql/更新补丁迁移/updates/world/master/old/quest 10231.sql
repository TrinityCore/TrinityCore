update creature set spawntimesecs = 1 where id in (19725,19726);
update creature_template set AIName = 'SmartAI' where entry in (19720,19725,19726);
update creature_template set unit_flags = 128, ScriptName = '' where entry = 19720;
delete from script_texts where entry in ('-1000274', '-1000275', '-1000276', '-1000277', '-1000278', '-1000279'); 
delete from smart_scripts where entryorguid IN (19720,19725,19726,1972000,1972001);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
-- Larry
(19720, 0, 0, 1, 62, 0, 100, 0, 8033, 0, 0, 0, 80, 1972000, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Run Time Script'),
(19720, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Set NpcFlag 0'),
(19720, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip'),
(19720, 0, 3, 0, 2, 0, 100, 1, 1, 10, 0, 0, 80, 1972001, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Hp < 10% - Run Time Script2'),
(19720, 0, 4, 0, 11, 0, 100, 0, 0, 0, 0, 0, 42, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Set Invincibility 1%'),
(19720, 0, 5, 6, 7, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Evade - Set NpcFlag 3'),
(19720, 0, 6, 0, 61, 0, 100, 0, 0, 0, 0, 0, 2, 1194, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link Evade - Set Faction Neutral (1194)'),
-- Larry guard1
(19725, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SetData - Set Faction - Monter(14)'),
(19725, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 20, 0, 0, 0, 0, 0, 0, 'Link - Attack Start'),
(19725, 0, 2, 3, 38, 0, 100, 0, 2, 2, 0, 0, 2, 1194, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SetData2 - Set Faction - Neutral(1194)'),
(19725, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Evade'),
(19725, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 2, 1194, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Evade - Set Faction - Neutral(1194)'),
-- Larry guard2
(19726, 0, 0, 1, 38, 0, 100, 0, 1, 1, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SetData - Set Faction - Monter(14)'),
(19726, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 18, 20, 0, 0, 0, 0, 0, 0, 'Link - Attack Start'),
(19726, 0, 2, 3, 38, 0, 100, 0, 2, 2, 0, 0, 2, 1194, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SetData2 - Set Faction - Neutral(1194)'),
(19726, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Evade'),
(19726, 0, 4, 0, 7, 0, 100, 0, 0, 0, 0, 0, 2, 1194, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Faction - Neutral(1194)'),
-- Larry time script 2
(1972000, 9, 0, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Say Text 0'),
(1972000, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Say Text 1'),
(1972000, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Say Text 2'),
(1972000, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Say Text 3'),
(1972000, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Say Text 4'),
(1972000, 9, 5, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 2, 14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Faction - Monster(14)'),
(1972000, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 19, 128, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remove Unit Flag'),
(1972000, 9, 7, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 19725, 15, 0, 0, 0, 0, 0, 'SendData - Guard1'),
(1972000, 9, 8, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 1, 1, 0, 0, 0, 0, 11, 19726, 15, 0, 0, 0, 0, 0, 'SendData - Guard2'),
(1972000, 9, 9, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Attack Start - Invoker'),
-- Larry time script 2
(1972001, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 15, 10231, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Kill Credit'),
(1972001, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Say Text 5'),
(1972001, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 19725, 30, 0, 0, 0, 0, 0, 'SendData - Guard1'),
(1972001, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 45, 2, 2, 0, 0, 0, 0, 11, 19726, 30, 0, 0, 0, 0, 0, 'SendData - Guard2'),
(1972001, 9, 4, 0, 0, 0, 100, 0, 0, 0, 0, 0, 2, 1194, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'SetFaction - Neutral'),
(1972001, 9, 5, 0, 0, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Evade'),
(1972001, 9, 6, 0, 0, 0, 100, 0, 0, 0, 0, 0, 18, 128, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Unit Flag - Non Attack');

delete from gossip_menu_option where menu_id = 8033;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(8033, 0, 0, 'Ezekiel said that you might have a certain book...', 1, 1, 0, 0, 0, 0, NULL);

delete from conditions where SourceGroup = 8033 and SourceTypeOrReferenceId = 15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 8033, 0, 0, 0, 9, 0, 10231, 0, 0, 0, 0, '', NULL);

delete from creature_text where entry = 19720;
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(19720, 0, 0, 'Time to teach you a lesson in manners, little $Gboy:girl;!', 12, 0, 100, 1, 0, 0, ''),
(19720, 1, 0, 'Now I\'m gonna give you to the count of \'3\' to get out of here before I sick the dogs on you.', 12, 0, 100, 1, 0, 0, ''),
(19720, 2, 0, '1...', 12, 0, 100, 0, 0, 0, ''),
(19720, 3, 0, '2...', 12, 0, 100, 0, 0, 0, ''),
(19720, 4, 0, 'Time to meet your maker!', 12, 0, 100, 1, 0, 0, ''),
(19720, 5, 0, 'Alright, we give up! Don\'t hurt us!', 12, 0, 100, 0, 0, 0, '');

delete from locales_creature_text where entry = 19720;
INSERT INTO `locales_creature_text` (`entry`, `textGroup`, `id`, `text_loc8`) VALUES 
(19720, 1, 0, 'Считаю до трех, и если не уберешься отсюда, я спущу собак!'),
(19720, 2, 0, '1...'),
(19720, 3, 0, '2...'),
(19720, 4, 0, 'Пора тебе отправиться к праотцам!'),
(19720, 5, 0, 'Ладно, мы сдаемся! Не трогайте нас!');