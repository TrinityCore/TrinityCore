-- Template updates
UPDATE `creature_template` SET `npcflag`=`npcflag`|3,`unit_flags`=`unit_flags`|32768,`speed_run`=1 WHERE `name`='Kwee Q. Peddlefeet' AND `IconName`!=NULL; -- Kwee Q. Peddlefeet
UPDATE `creature_template` SET `npcflag`=`npcflag`|3,`unit_flags`=`unit_flags`|512 WHERE `entry`=38066; -- Inspector Snip Snagglebolt
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=38325; -- Marion Sutton
UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry`=38293; -- Junior Inspector (NS)

-- Model data
UPDATE `creature_model_info` SET `bounding_radius`=0.29,`combat_reach`=2.5,`gender`=0 WHERE `modelid`=15990; -- Kwee Q. Peddlefeet
UPDATE `creature_model_info` SET `bounding_radius`=0.306,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=30728; -- Inspector Snip Snagglebolt
UPDATE `creature_model_info` SET `bounding_radius`=0.208,`combat_reach`=1.5,`gender`=0 WHERE `modelid`=31040; -- Marion Sutton

-- Addon data
DELETE FROM `creature_template_addon` WHERE `entry` IN (37887,38039,38040,38066,38325);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(37887,0,0,1,0, NULL), -- Kwee Q. Peddlefeet
(38039,0,0,1,0, NULL), -- Kwee Q. Peddlefeet
(38040,0,0,1,0, NULL), -- Kwee Q. Peddlefeet
(38066,0,0,257,0, NULL), -- Inspector Snip Snagglebolt
(38325,0,1,1,0, NULL); -- Marion Sutton

-- Gossip, unfinished
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10948 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(10948, 0, 0, 'I''d like a Lovely Charm Collector''s Kit.', 0, 0, '');
