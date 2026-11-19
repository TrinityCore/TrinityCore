UPDATE `creature_template` SET `baseattacktime`=2000 WHERE `entry`=36213; -- Kor'kron Overseer
UPDATE `creature_template` SET `faction_A`=14,`faction_H`=14,`baseattacktime`=2000,`unit_flags`=33280,`speed_walk`=1 WHERE `entry`=5677; -- Summoned Succubus
UPDATE `creature_template` SET `npcflag`=1,`unit_flags`=0x300,`speed_run`=0.99206 WHERE `entry`=33238; -- Argent Squire
UPDATE `creature_template` SET `faction_A`=35,`faction_H`=35,`unit_flags`=33536 WHERE `entry`=36979; -- Lil'KT
UPDATE `creature_template` SET `exp`=0,`InhabitType`=7,`flags_extra`=`flags_extra`|2|128 WHERE `entry` IN (34286,34159,33571); -- Orbital Support, Ulduar Gauntlet Generator, Ulduar Gauntlet Generator (small radius)
UPDATE `creature_template` SET `gossip_menu_id`=5021 WHERE `entry`=13257;
UPDATE `creature_template` SET `gossip_menu_id`=7320 WHERE `entry`=16886;
UPDATE `creature_template` SET `gossip_menu_id`=5283 WHERE `entry`=13617;
UPDATE `creature_template` SET `gossip_menu_id`=5241 WHERE `entry`=12096;
UPDATE `creature_template` SET `gossip_menu_id`=2602 WHERE `entry`=10267;
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_venture_co_straggler' WHERE `entry`=27570; -- Wrongly deleted in a recent commit

UPDATE `creature_model_info` SET `bounding_radius`=0.2596,`combat_reach`=1.65,`gender`=1 WHERE `modelid`=30063; -- Kor'kron Overseer
UPDATE `creature_model_info` SET `bounding_radius`=0.6045,`combat_reach`=2.25,`gender`=1 WHERE `modelid`=10923; -- Summoned Succubus
UPDATE `creature_model_info` SET `bounding_radius`=0.06,`combat_reach`=0.3,`gender`=0 WHERE `modelid`=30507; -- Lil'KT
UPDATE `creature_model_info` SET `bounding_radius`=0.3,`combat_reach`=0,`gender`=0 WHERE `modelid`=28946; -- Argent Squire
UPDATE `creature_model_info` SET `bounding_radius`=0.3519,`combat_reach`=1.725,`gender`=0 WHERE `modelid`=26078; -- Windle Sparkshine

DELETE FROM `creature_template_addon` WHERE `entry` IN (36213,5677,33238,36979,34286,34159);
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(36213,0,0,257,0, NULL), -- Kor'kron Overseer
(5677,0,0,1,0, NULL), -- Summoned Succubus
(33238,0,0,1,0, NULL), -- Argent Squire
(36979,0,0,1,0, '69683 70050'), -- Lil'KT (Lil' K.T. Passive / [DND] Lich Pet)
(34286,0,0,1,0, NULL), -- Orbital Support
(34159,0,0,1,0, NULL); -- Ulduar Gauntlet Generator (small radius)

UPDATE `creature` SET `MovementType`=0,`spawndist`=0 WHERE `id` IN (34286,34159,33571); -- Orbital Support, Ulduar Gauntlet Generator, Ulduar Gauntlet Generator (small radius)

-- No npc should have UNIT_FLAG_PVP_ATTACKABLE
UPDATE `creature_template` SET `unit_flags`=`unit_flags`&~0x8 WHERE `unit_flags` & 0x8;

DELETE FROM `gossip_menu` WHERE `entry`=1822 AND `text_id`=2474;
DELETE FROM `gossip_menu` WHERE `entry`=1823 AND `text_id`=2482;
DELETE FROM `gossip_menu` WHERE `entry`=1824 AND `text_id`=2481;
DELETE FROM `gossip_menu` WHERE `entry`=1825 AND `text_id`=2480;
DELETE FROM `gossip_menu` WHERE `entry`=1826 AND `text_id`=2479;
DELETE FROM `gossip_menu` WHERE `entry`=1827 AND `text_id`=2478;
DELETE FROM `gossip_menu` WHERE `entry`=1828 AND `text_id`=2477;
DELETE FROM `gossip_menu` WHERE `entry`=2186 AND `text_id`=2820;
DELETE FROM `gossip_menu` WHERE `entry`=2187 AND `text_id`=2820;
DELETE FROM `gossip_menu` WHERE `entry`=3182 AND `text_id`=3937;
DELETE FROM `gossip_menu` WHERE `entry`=2602 AND `text_id`=3296;
DELETE FROM `gossip_menu` WHERE `entry`=5241 AND `text_id`=6255;
DELETE FROM `gossip_menu` WHERE `entry`=5283 AND `text_id`=6316;
DELETE FROM `gossip_menu` WHERE `entry`=5021 AND `text_id`=6073;
DELETE FROM `gossip_menu` WHERE `entry`=5627 AND `text_id`=6736;
DELETE FROM `gossip_menu` WHERE `entry`=7320 AND `text_id`=8688;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(1822, 2474), (1823, 2482), (1824, 2481),
(1825, 2480), (1826, 2479), (1827, 2478),
(1828, 2477), (2186, 2820), (2187, 2820),
(3182, 3937), (2602, 3296), (5241, 6255),
(5283, 6316), (5021, 6073), (5627, 6736),
(7320, 8688);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=1663 AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=2187 AND `id`=0;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=4558 AND `id` IN (0,1,2);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7939 AND `id` IN (0,1);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=5021 AND `id`=3;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=5241 AND `id` IN (0,2);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(1663,0,0,'Amazing! I\'ve never spoken to a ghost. I wish to learn!', 1,1,0,0,0,0,''),
(2187,0,0,'Transcribe the tablet.',1,1,0,0,0,0,''),
(4558,0,3,'I seek more training in the priestly ways.',1,1,0,0,0,0,''),
(4558,1,0,'I wish to unlearn my talents.',1,1,0,0,0,0,''),
(4558,2,0,'Learn about Dual Talent Specialization.',1,1,0,0,0,0,''),
(7939,0,2,'Show me where I can fly.',1,1,0,0,0,0,''),
(7939,1,2,'Send me to Honor Hold!',1,1,0,0,0,0,''),
(5021,3,0,'How many more supplies are needed for the next upgrade?',1,1,5627,0,0,0,''),
(5241,0,0,'How many more supplies are needed to send ground assaults?',1,1,0,0,0,0,''),
(5241,2,1,'I want to browse your goods.',1,1,0,0,0,0,'');
