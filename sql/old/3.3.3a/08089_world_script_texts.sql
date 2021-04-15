DELETE FROM `script_texts` WHERE `npc_entry`=12717;
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(12717, -1800054, 'Are you sure that you are ready? If we do not have a group of your allies to aid us, we will surely fail.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_START1'),
(12717, -1800055, 'This will be a though fight, $N. Follow me closely.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_START2'),
(12717, -1800056, 'This is the brazier, $N. Put it out. Vorsha is a beast, worthy of praise from no one!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_BRAZIER'),
(12717, -1800057, 'Now we must wait. It won''t be long before the naga realize what we have done.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_BRAZIER_WAIT'),
(12717, -1800058, 'Be on your guard, $N!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_ON_GUARD'),
(12717, -1800059, 'Perhaps we will get a moment to rest. But I will not give up until we have faced off against Vorsha!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_REST'),
(12717, -1800060, 'We have done it!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_DONE'),
(12717, -1800061, 'You have my deepest gratitude. I thank you.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_GRATITUDE'),
(12717, -1800062, 'I am going to patrol the area for a while longer and ensure that things are truly safe.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_PATROL'),
(12717, -1800063, 'Please return to Zoram''gar and report our success to the Warsong runner.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 0, 0, 1, 0, 'muglash SAY_MUG_RETURN');
