UPDATE `creature_template` SET `ScriptName`='npc_injured_rainspeaker_oracle' WHERE `entry`=28217;

DELETE FROM `script_waypoint` WHERE `entry` = 28217;
INSERT INTO `script_waypoint` VALUES
(28217, 0, 5399.96,4509.07,-131.053, 0, ''),
(28217, 1, 5396.95,4514.84,-131.791,  0, ''),
(28217, 2, 5395.16,4524.06,-132.335,  0, ''),
(28217, 3, 5400.15,4526.84,-136.058, 0, ''),
(28217, 4, 5403.53,4527.2,-138.907, 0, ''),
(28217, 5, 5406.51,4527.47,-141.983, 0, ''),
(28217, 6, 5409.16,4526.37,-143.902,  0, ''),
(28217, 7, 5412.04,4523.05,-143.998,  0, ''),
(28217, 8, 5415.23,4521.19,-143.961,  0, ''),
(28217, 9, 5417.74,4519.74,-144.292,  0, ''),
(28217, 10, 5421.77,4519.79,-145.36, 0, ''),
(28217, 11, 5426.75,4520.53,-147.931, 0, ''),
(28217, 12, 5429.06,4521.82,-148.919,  0, ''),
(28217, 13, 5436.52,4534.63,-149.618,  0, ''),
(28217, 14, 5441.52,4542.23,-149.367,  0, ''),
(28217, 15, 5449.06,4553.47,-149.187, 0, ''),
(28217, 16, 5453.5,4565.61,-147.526,  0, ''),
(28217, 17, 5455.04,4578.6,-147.147,  0, ''),
(28217, 18, 5462.32,4591.69,-147.738,0, ''),
(28217, 19, 5470.04,4603.04,-146.044,0, ''),
(28217, 20, 5475.93,4608.86,-143.152, 0, ''),
(28217, 21, 5484.48,4613.78,-139.19, 0, ''),
(28217, 22, 5489.03,4616.56,-137.796, 0, ''),
(28217, 23, 5497.92,4629.89,-135.556, 0, ''),
(28217, 24, 5514.48,4638.82,-136.19, 0, ''),
(28217, 25, 5570,4654.5,-134.947, 0,  ''),
(28217, 26, 5578.32,4653.29,-136.896, 0, ''),
(28217, 27, 5596.56,4642.26,-136.593, 0, ''),
(28217, 28, 5634.02,4600.35,-137.291,2000,'');

INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1571000, 'You save me! We thank you. We going to go back to village now. You come too... you can stay with us! Puppy-men kind of mean anyway. ', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_injured_rainspeaker_oracle SAY_END_IRO'),
(-1571001, 'Let me know when you ready to go, okay?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_injured_rainspeaker_oracle SAY_QUEST_ACCEPT_IRO '),
(-1571002, 'Home time!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 0, 0, 'npc_injured_rainspeaker_oracle SAY_START_IRO');
