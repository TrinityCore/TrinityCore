DELETE FROM `script_texts` WHERE `entry` IN (-1603268,-1603267,-1603266);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(33186, -1603268, 'Razorscale grounded permanently!', NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,2,0,0, 'EMOTE_PERMA'),
(33186, -1603267, 'Razorscale takes a deep breath...', NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,2,0,0, 'EMOTE_BREATH'),
(33287, -1603266, 'Harpoon Turret is ready for use!', NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,2,0,0, 'EMOTE_HARPOON');

DELETE FROM `script_texts` WHERE `entry` IN (-1603265,-1603264,-1603263,-1603262);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(33287, -1603265, 'Fires out! Let''s rebuild those turrets!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0, 'SAY_TURRETS'),
(33287, -1603264, 'Ready to move out, keep those dwarves off of our backs!', NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0, 'SAY_AGGRO_3'),
(33287, -1603263, 'Be on the lookout! Mole machines will be surfacing soon with those nasty Iron dwarves aboard!', NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0, 'SAY_AGGRO_2'),
(33287, -1603262, 'Give us a moment to prepare to build the turrets.', NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0, 'SAY_AGGRO_1');

-- Razorscale emotes
UPDATE `script_texts` SET `content_default` = "Welcome, champions! All of our attempts at grounding her have failed. We could use a hand in bring her down with these harpoon guns.", `type`=0  WHERE `entry`=-1603260;
UPDATE `script_texts` SET `content_default` = "Move! Quickly! She won't remain grounded for long.", `type`=1  WHERE `entry`=-1603261;
