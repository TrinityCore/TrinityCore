UPDATE `creature_template` SET `ScriptName`='npc_second_trial_paladin' WHERE `entry` IN (17809,17810,17811,17812);
UPDATE `creature_template` SET `ScriptName`='npc_second_trial_controller' WHERE `entry` IN (17807);
UPDATE `gameobject_template` SET `ScriptName`='go_second_trial' WHERE `entry` IN (182052);

DELETE FROM `script_texts` WHERE `entry` BETWEEN -1645009 AND -1645006;
INSERT INTO `script_texts` (`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`, `type`, `language`, `comment`) VALUES
(-1645006,'Let the trial begin, Bloodwrath, attack!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,'master_kelerun_bloodmourn YELL_PHASE'),
(-1645007,'Champion Lightrend, make me proud!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,'master_kelerun_bloodmourn YELL_PHASE'),
(-1645008,'Show this upstart how a real Blood Knight fights, Swiftblade!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,'master_kelerun_bloodmourn YELL_PHASE'),
(-1645009,'Show $N the meaning of pain, Sunstriker!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,'master_kelerun_bloodmourn YELL_PHASE');

