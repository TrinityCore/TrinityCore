UPDATE `instance_template` SET `script` = 'instance_ramparts' WHERE `map` = 543;

UPDATE `creature_template` SET `ScriptName` = 'npc_alexstrasza_wr_gate' WHERE `entry` = 31333;

UPDATE `creature_template` SET `ScriptName` = 'npc_mist' WHERE `entry` = 3568;

DELETE FROM `script_texts` WHERE `entry` IN (-1000411, -1000412);
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000411, 'Mist! I feared I would never see you again! Yes, I am well, do not worry for me. You must rest and recover your health.', 0, 0, 7, 0, 'mist SAY_AT_HOME'),
(-1000412, 'growls in acknowledgement before straightening and making her way off into the forest.', 0, 2, 0, 0, 'mist EMOTE_AT_HOME');
