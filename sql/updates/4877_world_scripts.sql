DELETE FROM `script_texts` WHERE `entry` IN (-1602018,-1602019,-1602020,-1602021,-1602022,-1602023,-1602024,-1602025,-1602026,-1602027,-1602028,-1602029,-1602030,-1602031);
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `emote`, `comment`) VALUES
(-1602018,'What hope is there for you? None!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14162,1,0,0,'loken SAY_AGGRO0'),
(-1602019,'I have witnessed the rise and fall of empires. The birth and extinction of entire species. Over countless millennia the foolishness of mortals has remained beyond a constant. Your presence here confirms this.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14160,1,0,0,'loken SAY_INTRO_1'),
(-1602020,'My master has shown me the future, and you have no place in it. Azeroth will be reborn in darkness. Yogg-Saron shall be released! The Pantheon shall fall!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14162,1,0,0,'loken SAY_INTRO_2'),
(-1602021,'Only mortal...', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14166,1,0,0,'loken SAY_SLAY_1'),
(-1602022,'I... am... FOREVER!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14167,1,0,0,'loken SAY_SLAY_2'),
(-1602023,'What little time you had, you wasted!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14168,1,0,0,'loken SAY_SLAY_3'),
(-1602024,'My death... heralds the end of this world.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14172,1,0,0,'loken SAY_DEATH'),
(-1602025,'You cannot hide from fate!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14163,1,0,0,'loken SAY_NOVA_1'),
(-1602026,'Come closer. I will make it quick.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14164,1,0,0,'loken SAY_NOVA_2'),
(-1602027,'Your flesh cannot hold out for long.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14165,1,0,0,'loken SAY_NOVA_3'),
(-1602028,'You stare blindly into the abyss!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14169,1,0,0,'loken SAY_75HEALTH'),
(-1602029,'Your ignorance is profound. Can you not see where this path leads?', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14170,1,0,0,'loken SAY_50HEALTH'),
(-1602030,'You cross the precipice of oblivion!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,14171,1,0,0,'loken SAY_25HEALTH'),
(-1602031,'%s begins to cast Lightning Nova!', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,0,3,0,0,'loken EMOTE_NOVA');

UPDATE `creature_template` SET `ScriptName`='boss_loken' WHERE `entry`=28923;