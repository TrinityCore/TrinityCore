DELETE FROM script_texts WHERE entry BETWEEN -1000409 AND -1000407;
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1000407, '%s howls in delight at the sight of his lunch!',0,2,0,0,'kyle EMOTE_SEE_LUNCH'),
(-1000408, '%s eats his lunch.',0,2,0,0,'kyle EMOTE_EAT_LUNCH'),
(-1000409, '%s thanks you with a special dance.',0,2,0,0,'kyle EMOTE_DANCE');

UPDATE `creature_template` SET `ScriptName`='npc_kyle_frenzied' WHERE `entry`=23616;