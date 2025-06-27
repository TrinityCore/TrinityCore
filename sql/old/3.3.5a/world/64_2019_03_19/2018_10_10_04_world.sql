-- 
DELETE FROM `gossip_menu` WHERE (`MenuId`=10133 AND `TextId`=14069) OR (`MenuId`=10034 AND `TextId`=13944) OR (`MenuId`=10883 AND `TextId`=15119) OR (`MenuId`=9660) OR (`MenuId`=9659) OR (`MenuId`=9608 AND `TextId`=12982) OR (`MenuId`=9798 AND `TextId`=13502) OR (`MenuId`=13045 AND `TextId`=18320) OR (`MenuId`=9600 AND `TextId`=12960) OR (`MenuId`=9429 AND `TextId`=12687) OR (`MenuId`=9259 AND `TextId`=12568) OR (`MenuId`=13046 AND `TextId`=18321);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(10133, 14069, 26365), -- 31737 (Skybreaker Squad Leader)
(10034, 13944, 26365), -- 31135 (Geirrvif)
(10883, 15119, 26365), -- 30322 (Earthen Jormungar Handler)
(9660, 13083, 26365), -- 28142 (Crusader Lamoof)
(9659, 13082, 26365), -- 28136 (Crusader Jonathan)
(9608, 12982, 26365), -- 26212 (Captain Gryan Stoutmantle) need condition
(9798, 13502, 26365), -- 29244 (Jesse Masters) need condition
(13045, 18320, 26365), -- 23736 (Pricilla Winterwind)
(9600, 12960, 26365), -- 27784 (Commander Eligor Dawnbringer) need condition
(9429, 12687, 26365), -- 26619 (Fizzcrank Paratrooper)  need condition
(9259, 12568, 26365); -- 26117 (Raelorasz)

UPDATE `gossip_menu_option` SET `ActionMenuID`=9259 WHERE `OptionID`=1 AND `MenuID`=9253;
UPDATE `creature_template` SET `gossip_menu_id`=10883 WHERE `entry`=30322; -- 30322 (Earthen Jormungar Handler)
UPDATE `creature_template` SET `gossip_menu_id`=9660 WHERE `entry`=28142; -- 28142 (Crusader Lamoof)
UPDATE `creature_template` SET `gossip_menu_id`=9659 WHERE `entry`=28136; -- 28136 (Crusader Jonathan)
UPDATE `creature_template` SET `gossip_menu_id`=13045, `npcflag`=`npcflag`|1 WHERE `entry`=23736; -- 23736 (Pricilla Winterwind)
