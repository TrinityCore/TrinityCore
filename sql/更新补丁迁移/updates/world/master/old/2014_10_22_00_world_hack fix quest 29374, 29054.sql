-- hack!>
update quest_template set RequiredIdCount1 = 0 where id in (29054, 29374);
-- <hack!

update creature_template set spell1 = 96026, spell6 = 96017, VehicleId = 511 where entry = 51710;
update creature_template set spell1 = 100068, spell6 = 100030, VehicleId = 511 where entry = 53761;
update creature_template set gossip_menu_id = 52548, npcflag = 1, minlevel = 31, maxlevel = 31, faction_a = 1802, faction_h = 1802 where entry = 52548;
update creature_template set gossip_menu_id = 53764, npcflag = 1, minlevel = 31, maxlevel = 31, faction_a = 1801, faction_h = 1801 where entry = 53764;

delete from gossip_menu where entry in (52548, 53764);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(52548, 52548),
(53764, 53764);

delete from gossip_menu_option where menu_id in(52548, 53764);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`) VALUES 
(52548, 0, 0, 'Я готов! Полетели бомбить Подгород!', 1, 1),
(53764, 0, 0, 'Я готов! Полетели бомбить Штормград!', 1, 1);

delete from npc_text where id in(52548, 53764);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES 
(52548, 'Тыквовин на дворе! Надеюсь, тебе нравится этот праздник.', NULL, 0, 1, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 1),
(53764, 'Когда еще почувствуешь атмосферу Тыквовина так хорошо, как не летая на метле!', NULL, 0, 1, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 1);

delete from spell_target_position where id in (96005, 100028);
INSERT INTO `spell_target_position` (`id`, `target_map`, `target_position_x`, `target_position_y`, `target_position_z`, `target_orientation`) VALUES 
(96005, 0, 1639.14, 393.865, 16.9, 6),
(100028, 0, -8992.63, 509.98, 137.7, 0.18);