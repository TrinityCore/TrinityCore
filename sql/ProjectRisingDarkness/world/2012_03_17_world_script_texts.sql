DELETE FROM script_texts WHERE entry IN(-1658022, -1658023);
INSERT INTO script_texts (entry,content_default,sound,type,language,emote,comment) VALUES
(-1658022,'%s hurls a massive saronite boulder at you!',0,5,0,0,'garfrost EMOTE_THROW_SARONITE'), -- TODO emote only displayed to target
(-1658023,'%s casts Deep Freeze at $N.',0,3,0,0,'garfrost EMOTE_DEEP_FREEZE');