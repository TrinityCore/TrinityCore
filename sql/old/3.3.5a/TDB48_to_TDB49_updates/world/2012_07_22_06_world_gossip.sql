-- gossip assignation from sniff
UPDATE `creature_template` SET `gossip_menu_id`=4182 WHERE `entry`=1466; -- Gretta Finespindle <Apprentice Leatherworker>
UPDATE `creature_template` SET `gossip_menu_id`=201 WHERE `entry`=3678; -- Muyoh <Disciple of Naralex>
UPDATE `creature_template` SET `gossip_menu_id`=7406 WHERE `entry`=3848; -- Kayneth Stillwind
UPDATE `creature_template` SET `gossip_menu_id`=8851 WHERE `entry`=4979; -- Theramore Guard
UPDATE `creature_template` SET `gossip_menu_id`=4862 WHERE `entry`=6771; -- Ravenholdt Assassin <Assassin's League>
UPDATE `creature_template` SET `gossip_menu_id`=3130 WHERE `entry`=10618; -- Rivern Frostwind <Wintersaber Trainer>
UPDATE `creature_template` SET `gossip_menu_id`=3441 WHERE `entry`=10857; -- Argent Quartermaster Lightspark <The Argent Crusade>
UPDATE `creature_template` SET `gossip_menu_id`=3074 WHERE `entry`=10922; -- Greta Mosshoof <Emerald Circle>
UPDATE `creature_template` SET `gossip_menu_id`=3128 WHERE `entry`=11019; -- Jessir Moonbow
UPDATE `creature_template` SET `gossip_menu_id`=3622 WHERE `entry`=11554; -- Grazle
UPDATE `creature_template` SET `gossip_menu_id`=3602 WHERE `entry`=11609; -- Alexia Ironknife
UPDATE `creature_template` SET `gossip_menu_id`=3963 WHERE `entry`=11626; -- Rigger Gizelton
UPDATE `creature_template` SET `gossip_menu_id`=4003 WHERE `entry`=12245; -- Vendor-Tron 1000
UPDATE `creature_template` SET `gossip_menu_id`=4002 WHERE `entry`=12246; -- Super-Seller 680
UPDATE `creature_template` SET `gossip_menu_id`=4922 WHERE `entry`=13085; -- Myrokos Silentform
UPDATE `creature_template` SET `gossip_menu_id`=6531 WHERE `entry`=15182; -- Vish Kozus <Captain of the Guard>
UPDATE `creature_template` SET `gossip_menu_id`=7326 WHERE `entry`=16817; -- Festival Loremaster
UPDATE `creature_template` SET `gossip_menu_id`=7405 WHERE `entry`=17287; -- Sentinel Luciel Starwhisper <Silverwing Sentinels>
UPDATE `creature_template` SET `gossip_menu_id`=7404 WHERE `entry`=17291; -- Architect Nemos
UPDATE `creature_template` SET `gossip_menu_id`=7407 WHERE `entry`=17303; -- Vindicator Vedaar <Hand of Argus>
UPDATE `creature_template` SET `gossip_menu_id`=8080 WHERE `entry`=17310; -- Gnarl <Ancient of War>
UPDATE `creature_template` SET `gossip_menu_id`=7382 WHERE `entry`=17406; -- Artificer
UPDATE `creature_template` SET `gossip_menu_id`=7735 WHERE `entry`=18538; -- Ishanah <High Priestess of the Aldor>
UPDATE `creature_template` SET `gossip_menu_id`=7734 WHERE `entry`=18596; -- Arcanist Adyria <The Scryers>
UPDATE `creature_template` SET `gossip_menu_id`=7747 WHERE `entry`=18653; -- Seth
UPDATE `creature_template` SET `gossip_menu_id`=10459 WHERE `entry`=33746; -- Silvermoon Champion
UPDATE `creature_template` SET `gossip_menu_id`=10461 WHERE `entry`=33748; -- Thunder Bluff Champion
UPDATE `creature_template` SET `gossip_menu_id`=10462 WHERE `entry`=33749; -- Undercity Champion

-- gossip from sniff
DELETE FROM `gossip_menu` WHERE (`entry`=201 AND `text_id`=698) OR (`entry`=3074 AND `text_id`=3807) OR (`entry`=3128 AND `text_id`=3864) OR (`entry`=3130 AND `text_id`=3854) OR (`entry`=3441 AND `text_id`=4193) OR (`entry`=3602 AND `text_id`=4354) OR (`entry`=3621 AND `text_id`=4394) OR (`entry`=3622 AND `text_id`=4393) OR (`entry`=3961 AND `text_id`=4813) OR (`entry`=3963 AND `text_id`=4815) OR (`entry`=4002 AND `text_id`=4856) OR (`entry`=4003 AND `text_id`=4857) OR (`entry`=4182 AND `text_id`=5276) OR (`entry`=4862 AND `text_id`=5938) OR (`entry`=4922 AND `text_id`=5981) OR (`entry`=6531 AND `text_id`=7733) OR (`entry`=6588 AND `text_id`=7801) OR (`entry`=6587 AND `text_id`=7802) OR (`entry`=6586 AND `text_id`=7803) OR (`entry`=6585 AND `text_id`=7804) OR (`entry`=7326 AND `text_id`=8703) OR (`entry`=7382 AND `text_id`=8838) OR (`entry`=7404 AND `text_id`=8873) OR (`entry`=7405 AND `text_id`=8874) OR (`entry`=7406 AND `text_id`=8875) OR (`entry`=7407 AND `text_id`=8876) OR (`entry`=7735 AND `text_id`=9457) OR (`entry`=7734 AND `text_id`=9452) OR (`entry`=7747 AND `text_id`=9486) OR (`entry`=8080 AND `text_id`=9986) OR (`entry`=8464 AND `text_id`=10573) OR (`entry`=8851 AND `text_id`=11492) OR (`entry`=10933 AND `text_id`=15194);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(201, 698), -- 3678
(3074, 3807), -- 10922
(3128, 3864), -- 11019
(3130, 3854), -- 10618
(3441, 4193), -- 10857
(3602, 4354), -- 11609
(3621, 4394), -- 11554
(3622, 4393), -- 11554
(3961, 4813), -- 11625
(3963, 4815), -- 11626
(4002, 4856), -- 12246
(4003, 4857), -- 12245
(4182, 5276), -- 1466
(4862, 5938), -- 6771
(4922, 5981), -- 13085
(6531, 7733), -- 15182
(6588, 7801), -- 15169
(6587, 7802), -- 15169
(6586, 7803), -- 15169
(6585, 7804), -- 15169
(7326, 8703), -- 16817
(7382, 8838), -- 17406
(7404, 8873), -- 17291
(7405, 8874), -- 17287
(7406, 8875), -- 3848
(7407, 8876), -- 17303
(7735, 9457), -- 18538
(7734, 9452), -- 18596
(7747, 9486), -- 18653
(8080, 9986), -- 17310
(8464, 10573), -- 185126
(8851, 11492), -- 4979
(10933, 15194); -- 37200

-- correct npc_flags for npc from sniff
UPDATE `creature_template` SET `npcflag`=0 WHERE `entry`=8151; -- Nijel's Point Guard
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry`=24393; -- The Rokk <Master of Cooking>
UPDATE `creature_template` SET `npcflag`=1 WHERE `entry`=37119; -- Highlord Tirion Fordring

-- missing gossip from sniff
DELETE FROM `gossip_menu_option` WHERE (`menu_id`=3622 AND `id`=0) OR (`menu_id`=4002 AND `id`=0) OR (`menu_id`=4003 AND `id`=0) OR (`menu_id`=6586 AND `id`=0) OR (`menu_id`=6587 AND `id`=0) OR (`menu_id`=6588 AND `id`=0) OR (`menu_id`=10456 AND `id`=0) OR (`menu_id`=10457 AND `id`=0) OR (`menu_id`=10461 AND `id`=0) OR (`menu_id`=10462 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(3622, 0, 0, 'How can I prove myself to the Timbermaw furbolg?', 1, 3, 3621, 0, 0, 0, ''), -- 11554
(4002, 0, 1, 'Let me take a look at what you have to offer.', 3, 387, 0, 0, 0, 0, ''), -- 12246
(4003, 0, 1, 'I am curious to see what a bucket of bolts has to offer.', 3, 131, 0, 0, 0, 0, ''), -- 12245
(6586, 0, 0, 'And what do you say?', 1, 1, 6585, 0, 0, 0, ''), -- 15169
(6587, 0, 0, 'What do they say?', 1, 1, 6586, 0, 0, 0, ''), -- 15169
(6588, 0, 0, 'How do you know?', 1, 1, 6587, 0, 0, 0, ''), -- 15169
(10456, 0, 0, 'I am ready to fight!', 1, 1, 0, 0, 0, 0, ''), -- 33743
(10457, 0, 0, 'I am ready to fight!', 1, 1, 0, 0, 0, 0, ''), -- 33744
(10461, 0, 0, 'I am ready to fight!', 1, 1, 0, 0, 0, 0, ''), -- 33748
(10462, 0, 0, 'I am ready to fight!', 1, 1, 0, 0, 0, 0, ''); -- 33749
