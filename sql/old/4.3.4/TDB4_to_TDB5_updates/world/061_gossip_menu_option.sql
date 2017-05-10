UPDATE `gossip_menu_option` SET `option_id`=1, `npc_option_npcflag`=1 WHERE `menu_id` IN (8851, 12855, 12865);

DELETE FROM `gossip_menu` WHERE (`entry`=12854 AND `text_id`=18086) OR (`entry`=12855 AND `text_id`=17774) OR (`entry`=12857 AND `text_id`=18087) OR (`entry`=12858 AND `text_id`=18088) OR (`entry`=12859 AND `text_id`=18089) OR (`entry`=12860 AND `text_id`=18090) OR (`entry`=12861 AND `text_id`=18091) OR (`entry`=12862 AND `text_id`=18092) OR (`entry`=12863 AND `text_id`=18093) OR (`entry`=12864 AND `text_id`=18094) OR (`entry`=12865 AND `text_id`=17774) OR (`entry`=12866 AND `text_id`=18095) OR (`entry`=12867 AND `text_id`=18096) OR (`entry`=12868 AND `text_id`=18097) OR (`entry`=12869 AND `text_id`=18098) OR (`entry`=12870 AND `text_id`=18099) OR (`entry`=12871 AND `text_id`=18100) OR (`entry`=12872 AND `text_id`=18101) OR (`entry`=12873 AND `text_id`=18102) OR (`entry`=12874 AND `text_id`=18103) OR (`entry`=12875 AND `text_id`=18104) OR (`entry`=12876 AND `text_id`=18105) OR (`entry`=12877 AND `text_id`=18106) OR (`entry`=12878 AND `text_id`=18107) OR (`entry`=12879 AND `text_id`=18108);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(12854, 18086), -- Theramore Guard
(12855, 17774), -- Theramore Guard
(12857, 18087), -- Theramore Guard
(12858, 18088), -- Theramore Guard
(12859, 18089), -- Theramore Guard
(12860, 18090), -- Theramore Guard
(12861, 18091), -- Theramore Guard
(12862, 18092), -- Theramore Guard
(12863, 18093), -- Theramore Guard
(12864, 18094), -- Theramore Guard
(12865, 17774), -- Theramore Guard
(12866, 18095), -- Theramore Guard
(12867, 18096), -- Theramore Guard
(12868, 18097), -- Theramore Guard
(12869, 18098), -- Theramore Guard
(12870, 18099), -- Theramore Guard
(12871, 18100), -- Theramore Guard
(12872, 18101), -- Theramore Guard
(12873, 18102), -- Theramore Guard
(12874, 18103), -- Theramore Guard
(12875, 18104), -- Theramore Guard
(12876, 18105), -- Theramore Guard
(12877, 18106), -- Theramore Guard
(12878, 18107), -- Theramore Guard
(12879, 18108); -- Theramore Guard

UPDATE `gossip_menu_option` SET `action_menu_id`=12854, `action_poi_id`=469 WHERE `menu_id`=8851 AND `id`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=12855 WHERE `menu_id`=8851 AND `id`=2;
UPDATE `gossip_menu_option` SET `action_menu_id`=12857, `action_poi_id`=470 WHERE `menu_id`=12855 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=12858, `action_poi_id`=471 WHERE `menu_id`=12855 AND `id`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=12859, `action_poi_id`=472 WHERE `menu_id`=12855 AND `id`=2;
UPDATE `gossip_menu_option` SET `action_menu_id`=12860, `action_poi_id`=473 WHERE `menu_id`=12855 AND `id`=3;
UPDATE `gossip_menu_option` SET `action_menu_id`=12861, `action_poi_id`=474 WHERE `menu_id`=12855 AND `id`=4;
UPDATE `gossip_menu_option` SET `action_menu_id`=12862, `action_poi_id`=475 WHERE `menu_id`=12855 AND `id`=5;
UPDATE `gossip_menu_option` SET `action_menu_id`=12863, `action_poi_id`=476 WHERE `menu_id`=12855 AND `id`=6;
UPDATE `gossip_menu_option` SET `action_menu_id`=12864, `action_poi_id`=477 WHERE `menu_id`=12855 AND `id`=7;
UPDATE `gossip_menu_option` SET `action_menu_id`=12865 WHERE `menu_id`=8851 AND `id`=3;
UPDATE `gossip_menu_option` SET `action_menu_id`=12866, `action_poi_id`=478 WHERE `menu_id`=12865 AND `id`=0;
UPDATE `gossip_menu_option` SET `action_menu_id`=12867, `action_poi_id`=479 WHERE `menu_id`=12865 AND `id`=1;
UPDATE `gossip_menu_option` SET `action_menu_id`=12868, `action_poi_id`=480 WHERE `menu_id`=12865 AND `id`=2;
UPDATE `gossip_menu_option` SET `action_menu_id`=12869, `action_poi_id`=481 WHERE `menu_id`=12865 AND `id`=3;
UPDATE `gossip_menu_option` SET `action_menu_id`=12870, `action_poi_id`=482 WHERE `menu_id`=12865 AND `id`=4;
UPDATE `gossip_menu_option` SET `action_menu_id`=12871, `action_poi_id`=483 WHERE `menu_id`=12865 AND `id`=5;
UPDATE `gossip_menu_option` SET `action_menu_id`=12872, `action_poi_id`=484 WHERE `menu_id`=12865 AND `id`=6;
UPDATE `gossip_menu_option` SET `action_menu_id`=12873, `action_poi_id`=485 WHERE `menu_id`=12865 AND `id`=7;
UPDATE `gossip_menu_option` SET `action_menu_id`=12866, `action_poi_id`=486 WHERE `menu_id`=12865 AND `id`=8;
UPDATE `gossip_menu_option` SET `action_menu_id`=12874, `action_poi_id`=487 WHERE `menu_id`=12865 AND `id`=9;
UPDATE `gossip_menu_option` SET `action_menu_id`=12875, `action_poi_id`=488 WHERE `menu_id`=12865 AND `id`=10;
UPDATE `gossip_menu_option` SET `action_menu_id`=12876, `action_poi_id`=489 WHERE `menu_id`=12865 AND `id`=11;
UPDATE `gossip_menu_option` SET `action_menu_id`=12877, `action_poi_id`=490 WHERE `menu_id`=12865 AND `id`=12;
UPDATE `gossip_menu_option` SET `action_menu_id`=12878, `action_poi_id`=491 WHERE `menu_id`=12865 AND `id`=13;
UPDATE `gossip_menu_option` SET `action_menu_id`=12876, `action_poi_id`=492 WHERE `menu_id`=12865 AND `id`=14;
UPDATE `gossip_menu_option` SET `action_menu_id`=12879, `action_poi_id`=493 WHERE `menu_id`=12865 AND `id`=15;
