/* 4.x removed
-- Add Gossip for Harrison Jones
UPDATE `creature_template` SET `gossip_menu_id`=8932 WHERE `entry`=24358;
DELETE FROM `gossip_menu` WHERE `entry`=8932 AND `text_id`=12135;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (8932,12135);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=8932 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(8932,0,0, 'Thanks for the concern, but we intend to explore Zul''Aman.',1,1);

-- Pathing for Harrison Jones Entry: 24358
SET @NPC := 86177;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_data` WHERE `id`IN (@PATH,@PATH+1,@PATH+2);
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,112.1772,1670.18,42.02158,0,0,0,100,0),
(@PATH,2,82.44975,1655.312,42.02155,0,0,0,100,0),
(@PATH,3,114.1627,1661.469,42.02158,0,0,0,100,0),
(@PATH,4,131.8243,1644.853,42.0216,0,0,0,100,0),
(@PATH+1,1,121.897,1639.106,42.19081,0,0,0,100,0),
(@PATH+1,2,120.8522,1637.931,42.37172,0,0,0,100,0),
(@PATH+1,3,120.7898,1609.063,43.49005,0,0,0,100,0),
(@PATH+2,1,120.6967,1603.713,43.4503,0,0,0,100,0);

-- Text for Harrison Jones from sniff
DELETE FROM `creature_text` WHERE `entry` IN (24358);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24358,0,0, 'Suit yourself. At least five of you must assist me if we''re to get inside. Follow me....',14,0,100,1,0,0, 'Harrison Jones - Gong Event Say 0'),
(24358,1,0, 'According to my calculations, if enough of us bang the gong at once the seal on these doors will break and we can enter.',14,0,100,1,0,0, 'Harrison Jones - Gong Event Say 1'),
(24358,2,0, 'I''ve researched this site extensively and I won''t allow any dim-witted treasure hunters to swoop in and steal what belongs in a museum. I''ll lead this charge...',14,0,100,0,0,0, 'Harrison Jones - Gong Event Say 2'),
(24358,3,0, 'In fact, it would be best if you just stay here. You''d only get in my way....',14,0,100,0,0,0, 'Harrison Jones - Gong Event Say 3');
*/
