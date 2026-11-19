--
DELETE FROM `spell_script_names` WHERE `spell_id` IN (60291,60292,60293,60294,60295,60296,60297) AND `ScriptName` = "spell_volazj_whisper";
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(60291,"spell_volazj_whisper"),
(60292,"spell_volazj_whisper"),
(60293,"spell_volazj_whisper"),
(60294,"spell_volazj_whisper"),
(60295,"spell_volazj_whisper"),
(60296,"spell_volazj_whisper"),
(60297,"spell_volazj_whisper");

-- SLAY_ based on https://wow.gamepedia.com/Herald_Volazj and https://wow.gamepedia.com/Shath%27Yar no sniffs for obvious reasons
DELETE FROM `creature_text` WHERE `CreatureID` = 29311;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
/*     0 */ (29311,0,0,"Shgla'yos plahf mh'naus.",14,0,100,0,0,14043,32596,0,"Herald Volazj SAY_AGGRO"),
/*     0 */ (29311,1,0,"Gul'kafh an'shel. Yoq'al shn ky ywaq nuul.",14,0,100,0,0,14044,32603,0,"Herald Volazj SAY_INSANITY"),
/*     0 */ (29311,2,0,"Ywaq ma phgwa'cul hnakf.",14,0,100,0,0,14045,32598,0,"Herald Volazj SAY_SLAY_1"),
/*     0 */ (29311,3,0,"Uulwi gag erh'ongg w'ssh.",14,0,100,0,0,14046,32599,0,"Herald Volazj SAY_SLAY_2"),
/*     0 */ (29311,4,0,"Ywaq puul skshgn: on'ma yeh'glu zuq.",14,0,100,0,0,14047,32600,0,"Herald Volazj SAY_SLAY_3"),
/*     0 */ (29311,5,0,"Iilth vwah, uhn'agth fhssh za.",14,0,100,0,0,14048,32601,0,"Herald Volazj SAY_DEATH_1"),
/*     0 */ (29311,6,0,"Ywaq maq oou; ywaq maq ssaggh. Ywaq ma shg'fhn.",14,0,100,0,0,14049,32602,0,"Herald Volazj SAY_DEATH_2"),

/* 60291 */ (29311,7,0,"They who dine on lost souls know only hunger.",15,0,100,0,0,0,32597,0,"Herald Volazj WHISPER_AGGRO"),
/* 60292 */ (29311,8,0,"Gaze into the void. It is the perpetuity in which they dwell.",15,0,100,0,0,0,32604,0,"Herald Volazj WHISPER_INSANITY"),
/* 60293 */ (29311,9,0,"They are the whisper on the shivering wind.",15,0,100,0,0,0,32605,0,"Herald Volazj WHISPER_SLAY_1"),
/* 60294 */ (29311,10,0,"Their shadow will choke the land for eternity.",15,0,100,0,0,0,32606,0,"Herald Volazj WHISPER_SLAY_2"),
/* 60295 */ (29311,11,0,"They drink your fear: it is the blood of life.",15,0,100,0,0,0,32607,0,"Herald Volazj WHISPER_SLAY_3"),
/* 60296 */ (29311,12,0,"Where one falls, many shall take its place.",15,0,100,0,0,0,32608,0,"Herald Volazj WHISPER_DEATH_1"),
/* 60297 */ (29311,13,0,"They do not die; they do not live. They are outside the cycle.",15,0,100,0,0,0,32609,0,"Herald Volazj WHISPER_DEATH_2");
