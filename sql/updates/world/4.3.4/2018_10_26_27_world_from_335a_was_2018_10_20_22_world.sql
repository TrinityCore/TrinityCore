--
UPDATE `creature_template` SET `npcflag`=`npcflag`|1 WHERE `entry` IN (23712, 24519, 23973, 23971, 15197);
UPDATE `creature_template` SET `gossip_menu_id`=8821 WHERE `entry`=23712;
UPDATE `creature_template` SET `gossip_menu_id`=8843 WHERE `entry`=23971;
UPDATE `creature_template` SET `gossip_menu_id`=9470 WHERE `entry`=23973;
UPDATE `creature_template` SET `gossip_menu_id`=6537 WHERE `entry`=15197;

DELETE FROM `gossip_menu` WHERE (`MenuId`=8821 AND `TextId`=11358) OR (`MenuId`=9468 AND `TextId`=11177) OR (`MenuId`=9468 AND `TextId`=11143) OR (`MenuId`=8763 AND `TextId`=11145) OR (`MenuId`=8979 AND `TextId`=11356) OR (`MenuId`=9469 AND `TextId`=11143) OR (`MenuId`=9469 AND `TextId`=11177) OR (`MenuId`=8981 AND `TextId`=12119) OR (`MenuId`=8979 AND `TextId`=11359) OR (`MenuId`=14991 AND `TextId`=20326) OR (`MenuId`=9471 AND `TextId`=11473) OR (`MenuId`=8843 AND `TextId`=11477) OR (`MenuId`=9470 AND `TextId`=11473) OR (`MenuId`=9470 AND `TextId`=11177) OR (`MenuId`=9470 AND `TextId`=11147) OR (`MenuId`=9470 AND `TextId`=11145) OR (`MenuId`=12932 AND `TextId`=18190) OR (`MenuId`=6537 AND `TextId`=7740) OR (`MenuId`=18793 AND `TextId`=27340) OR (`MenuId`=18604 AND `TextId`=26986) OR (`MenuId`=20215 AND `TextId`=30340) OR (`MenuId`=19344 AND `TextId`=28502) OR (`MenuId`=11385 AND `TextId`=15856) OR (`MenuId`=19646 AND `TextId`=25240) OR (`MenuId`=20369 AND `TextId`=30462) OR (`MenuId`=18747 AND `TextId`=27251) OR (`MenuId`=18765 AND `TextId`=27288) OR (`MenuId`=19110 AND `TextId`=26451);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(8821, 11358, 22810), -- 23712 (Touring Orphan)
(9468, 11177, 22810), -- 24519 (Costumed Orphan Matron)
(9468, 11143, 22810), -- 24519 (Costumed Orphan Matron)
(8763, 11145, 22810), -- 24519 (Costumed Orphan Matron)
(8979, 11356, 22810), -- 23712 (Touring Orphan)
(9469, 11143, 22810), -- 24519 (Costumed Orphan Matron)
(9469, 11177, 22810), -- 24519 (Costumed Orphan Matron)
(8981, 12119, 22810), -- 18038 (Azuremyst Peacekeeper)
(8979, 11359, 22810), -- 23712 (Touring Orphan)
(9471, 11473, 22810), -- 23973 (Masked Orphan Matron)
(8843, 11477, 22810), -- 23971 (Traveling Orphan)
(9470, 11473, 22810), -- 23973 (Masked Orphan Matron)
(9470, 11177, 22810), -- 23973 (Masked Orphan Matron)
(9470, 11147, 22810), -- 23973 (Masked Orphan Matron)
(9470, 11145, 22810), -- 23973 (Masked Orphan Matron)
(6537, 7740, 22810); --  15197 (Darkcaller Yanka)
