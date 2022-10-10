delete from creature where id = 28325;
update creature_template set npcflag = 1, AIName = 'SmartAI', ScriptName = '' where entry = 28217;
update creature_template set AIName = 'SmartAI' where entry in (28077,28325);

delete from smart_scripts where entryorguid in (28077,28217,28325,2821700);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
-- Frenzyheart Tracker
(28077, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Just Summon - Say Text'),
(28077, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link - Despawn'),
-- Ravenous Mangal Crocolisk
(28325, 0, 0, 0, 0, 0, 100, 0, 5000, 9000, 9000, 14000, 11, 34370, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Ravenous Mangal Crocolisk - Cast Jagged Tooth Snap'),
(28325, 0, 1, 2, 6, 0, 100, 0, 0, 0, 0, 0, 81, 3, 0, 0, 0, 0, 0, 11, 28217, 30, 0, 0, 0, 0, 0, 'Death - Set Npc Flag - Target'),
(28325, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 28, 51329, 0, 0, 0, 0, 0, 11, 28217, 30, 0, 0, 0, 0, 0, 'Link - Remove Aura - Target'),
(28325, 0, 3, 0, 54, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Just Summon - Attack Start'),
-- Injured Rainspeaker Oracle
(28217, 0, 0, 0, 19, 0, 100, 0, 12570, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Quest Accepted - Say Text 0'),
(28217, 0, 1, 12, 62, 0, 100, 0, 9677, 1, 0, 0, 80, 2821700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Run Time Script'),
(28217, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Link - Close Gossip'),
(28217, 0, 3, 4, 34, 0, 100, 0, 0, 11, 0, 0, 15, 12570, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'MoveInfo p11 - Quest Credit'),
(28217, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link MoveInfo - Say Text 2'),
(28217, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 12, 28077, 1, 2000, 0, 0, 0, 8, 0, 0, 0, 5625, 4611, -137, 5.3, 'Link MoveInfo - Summon Frenzyheart Tracker'),
(28217, 0, 6, 0, 23, 0, 100, 0, 51329, 0, 0, 0, 91, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Remove Aura - Remove FielFlags 7'),
(28217, 0, 7, 0, 23, 0, 100, 0, 51329, 1, 0, 0, 90, 7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'HasAura - Set Fiel Flags 7'),
(28217, 0, 8, 10, 62, 0, 100, 0, 9677, 0, 0, 0, 11, 51382, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Gossip Select - Cast Summon Huge Crocolisk'),
(28217, 0, 9, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 51329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Spawn - Cast Feign Death'),
(28217, 0, 10, 2, 61, 0, 100, 0, 0, 0, 0, 0, 22, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link Spawn - Set Event Phase 1'),
(28217, 0, 11, 0, 60, 1, 100, 1, 60000, 60000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Update 60s, 1Ph - Despawn'),
(28217, 0, 12, 2, 61, 0, 100, 0, 0, 0, 0, 0, 22, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Link Select1 - Set Event Phase 0'),
-- Time Script Oracle
(2821700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 81, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Set Npc Flag 0'),
(2821700, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Say Text 1'),
(2821700, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 53, 1, 28217, 0, 0, 1000, 1, 1, 0, 0, 0, 0, 0, 0, 0, 'Wp Start');

delete from script_waypoint where entry = 28217;
delete from waypoints where entry = 28217;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`) VALUES 
(28217, 1, 5440.32, 4599.88, -141.047),
(28217, 2, 5459.07, 4611.11, -143.692),
(28217, 3, 5476.88, 4621.58, -141.124),
(28217, 4, 5497.92, 4634.08, -134.824),
(28217, 5, 5521.39, 4644.39, -135.829),
(28217, 6, 5545.91, 4647.8, -135.454),
(28217, 7, 5572.07, 4657.78, -135.922),
(28217, 8, 5596.03, 4641.15, -136.671),
(28217, 9, 5621.28, 4617.26, -137.929),
(28217, 10, 5638.37, 4593.01, -137.758),
(28217, 11, 5646.49, 4581.31, -137.709),
(28217, 12, 5671.93, 4588.72, -134.828),
(28217, 13, 5689.64, 4590.14, -128.877),
(28217, 14, 5696.5, 4589, -125.895),
(28217, 15, 5707.49, 4580.08, -119.465),
(28217, 16, 5720.89, 4569.48, -119.832);

delete from conditions where SourceTypeOrReferenceId = 15 and SourceGroup = 9677;
delete from conditions where SourceTypeOrReferenceId = 22 and SourceEntry = 28217;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15, 9677, 0, 0, 0, 1, 1, 51329, 0, 0, 0, 0, '', NULL),
(15, 9677, 1, 0, 0, 1, 1, 51329, 0, 0, 1, 0, '', NULL),
(15, 9677, 1, 0, 0, 9, 0, 12570, 0, 0, 0, 0, '', NULL),
(22, 9, 28217, 0, 0, 29, 0, 28325, 40, 0, 1, 0, '', NULL);

delete from script_texts where npc_entry = 28217;
delete from creature_text where entry in (28217, 28077);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(28077, 0, 0, 'Dumb big-tongue lover! You not friend of Frenzyheart no more. Frenzyheart will get you good.', 14, 0, 100, 0, 0, 0, ''),
(28217, 0, 0, 'Let me know when you ready to go, okay?', 12, 0, 100, 0, 0, 0, ''),
(28217, 1, 0, 'Home time!', 12, 0, 100, 0, 0, 0, ''),
(28217, 2, 0, 'Oh no! Some puppy-men followed!', 12, 0, 100, 0, 0, 0, '');

delete from locales_creature_text where entry in (28217, 28077);
INSERT INTO `locales_creature_text` (`entry`, `textGroup`, `id`, `text_loc8`) VALUES 
(28077, 0, 0, 'Тупой дружок длинноязыких! Ты больше не друг Бешеному Сердцу. Бешеное Сердце тебе задаст!'),
(28217, 0, 0, 'Мы подождем, когда ты соберешься.'),
(28217, 1, 0, 'Пора домой!'),
(28217, 2, 0, 'О нет! Несколько волосатых пошли за нами!');

delete from gossip_menu_option where menu_id = 9677;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(9677, 0, 0, '<Reach down and pull the Injured Rainspeaker Oracle to its feet.>', 1, 1, 0, 0, 0, 0, ''),
(9677, 1, 0, 'I am ready to travel to your village now.', 1, 1, 0, 0, 0, 0, NULL);

delete from locales_gossip_menu_option where menu_id = 9677;
INSERT INTO `locales_gossip_menu_option` (`menu_id`, `id`, `option_text_loc8`) VALUES 
(9677, 0, '<Наклониться и поднять на ноги раненого оракула Прибежища Гласа Дождя.>'),
(9677, 1, 'Я готов отправиться в твою деревню.');