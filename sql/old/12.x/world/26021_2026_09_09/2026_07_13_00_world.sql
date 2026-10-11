--
UPDATE `creature_template` SET `speed_walk` = 2, `speed_run` = 1.42857, `ScriptName` = 'boss_doom_lord_kazzak' WHERE `entry` = 18728;

UPDATE `creature_model_info` SET `BoundingRadius` = 9, `CombatReach` = 15.75 WHERE `DisplayID` = 17887;

DELETE FROM `creature_text` WHERE `CreatureID` = 18728 AND `GroupID` > 4;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(18728,5,0,"Your own strength feeds me, $n!",14,0,0,0,0,0,8461,0,"kazzak SAY_SOUL"),
(18728,6,0,"%s goes into a frenzy!",16,0,0,0,0,0,1191,0,"kazzak EMOTE_FRENZY"),
(18728,7,0,"Invaders, you dangle upon the precipice of oblivion! The Burning Legion comes and with it comes your end.\n",14,0,0,0,0,0,15895,0,"kazzak SAY_UNK_1"),
(18728,8,0,"Impudent whelps, you only delay the inevitable. Where one has fallen, ten shall rise. Such is the will of Kazzak...",14,0,0,0,0,0,16432,0,"kazzak SAY_UNK_2");

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_doom_lord_kazzak_capture_soul';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48473, 'spell_doom_lord_kazzak_capture_soul');

UPDATE `spell_script_names` SET `ScriptName` = 'spell_doom_lord_kazzak_mark_of_kazzak' WHERE `ScriptName` = 'spell_mark_of_kazzak';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_doom_lord_kazzak_twisted_reflection' WHERE `ScriptName` = 'spell_twisted_reflection';
