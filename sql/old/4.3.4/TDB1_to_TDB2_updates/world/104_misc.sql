DELETE FROM `npc_trainer` WHERE `entry` IN (17245, 55684, 53410, 16367, 53415, 5388, 53436, 53409);
INSERT INTO `npc_trainer` (`entry`, `spell`, `spellcost`, `reqskill`, `reqskillvalue`, `reqlevel`) VALUES
(17245, -200401, 0, 0, 0, 0), -- Blacksmith Calypso <Blacksmithing Trainer & Supplies>
(55684, -200401, 0, 0, 0, 0), -- Jordan Smith <Blacksmithing Trainer & Supplies>
(53410, -200402, 0, 0, 0, 0), -- Lissah Spellwick <Enchanting Trainer & Supplies>
(16367, -200404, 0, 0, 0, 0), -- Botanist Tyniarrel <Herbalism Trainer & Supplies>
(53415, -200405, 0, 0, 0, 0), -- Theoden Manners <Inscription Trainer & Supplies>
(5388, -200406, 0, 0, 0, 0), -- Ingo Woolybush <Jewelcrafting Trainer & Supplies>
(53436, -200407, 0, 0, 0, 0), -- Eustace Tanwell <Leatherworking Trainer & Supplies>
(53409, -200408, 0, 0, 0, 0); -- "Kobold" Kerik <Mining Trainer & Supplies>

UPDATE `creature_template` SET `trainer_type`=2 WHERE `entry` IN (55684, 53410, 53415, 53436, 53409, 5388);

DELETE FROM `gossip_menu` WHERE (`entry`=12852 AND `text_id`=18076) OR (`entry`=12848 AND `text_id`=18072) OR (`entry`=12844 AND `text_id`=18064) OR (`entry`=12843 AND `text_id`=18063);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12852, 18076), -- Eustace Tanwell
(12848, 18072), -- Ingo Woolybush
(12844, 18064), -- Theoden Manners
(12843, 18063); -- Lissah Spellwick


UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=16 WHERE `menu_id`=12852 AND `id`=0;
UPDATE `gossip_menu_option` SET `option_id`=3, `npc_option_npcflag`=128 WHERE `menu_id`=12852 AND `id`=1;
UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=16 WHERE `menu_id`=12848 AND `id`=0;
UPDATE `gossip_menu_option` SET `option_id`=3, `npc_option_npcflag`=128 WHERE `menu_id`=12848 AND `id`=2;
UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=16 WHERE `menu_id`=12844 AND `id`=0;
UPDATE `gossip_menu_option` SET `option_id`=3, `npc_option_npcflag`=128 WHERE `menu_id`=12844 AND `id`=1;
UPDATE `gossip_menu_option` SET `option_id`=5, `npc_option_npcflag`=16 WHERE `menu_id`=12843 AND `id`=0;
UPDATE `gossip_menu_option` SET `option_id`=3, `npc_option_npcflag`=128 WHERE `menu_id`=12843 AND `id`=1;


DELETE FROM `npc_text` WHERE `ID` IN (18076, 18072);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(18076, 'Good leather in the marshes, if you''ve the guts for it. Lots of crocolisks. Thinkin'' my brother and I''ll stay a while.

Somethin'' I can help you with?', '', 0, 1, 396, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 18076
(18072, 'I used ta be in the Explorers'' League, ye know.

But then I realized the only thing I really cared ta look for was GEMS.

Big, sparklin'', colorful, valuable gems... oh, how I love ye!', '', 0, 1, 396, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 18072
