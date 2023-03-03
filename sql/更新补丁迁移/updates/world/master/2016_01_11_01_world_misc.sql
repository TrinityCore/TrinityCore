delete from creature where id in (56581,56359,56844,57686,57695,57694,57696);
update creature set spawnmask = 120 where id in (56099,56102,56100,56101);

update creature_template set minlevel = 87, maxlevel = 87, exp = 3, unit_flags2 = 0 where entry = 56263;

delete from gossip_menu_option where menu_id = 13295;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(13295, 0, 0, 'We are ready!', 1, 1, 0, 0, 0, 0, NULL);

delete from conditions where SourceTypeOrReferenceId = 13 and SourceEntry in (106940,105937);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 106940, 0, 0, 31, 0, 3, 56099, 0, 0, 0, '', NULL),
(13, 1, 106940, 0, 1, 31, 0, 3, 56102, 0, 0, 0, '', NULL),
(13, 1, 106940, 0, 2, 31, 0, 3, 56100, 0, 0, 0, '', NULL),
(13, 1, 106940, 0, 3, 31, 0, 3, 56101, 0, 0, 0, '', NULL),
(13, 1, 105937, 0, 3, 31, 0, 3, 56263, 0, 0, 0, '', NULL);