--
DELETE FROM `creature_text` WHERE `CreatureID` = 17308;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(17308,0,0,"Achor she-ki!  Feast, my pet!  Eat your fill!",14,0,100,0,0,10277,17637,0,"omor SAY_SUMMON"),
(17308,1,0,"A-kreesh!",14,0,100,0,0,10278,17636,0,"omor SAY_KNOCK"),
(17308,2,0,"I will not be defeated!",14,0,100,0,0,10279,17633,0,"omor SAY_AGGRO_1"),
(17308,2,1,"You dare stand against ME?",14,0,100,0,0,10280,17634,0,"omor SAY_AGGRO_2"),
(17308,2,2,"Your insolence will be your death!",14,0,100,0,0,10281,17635,0,"omor SAY_AGGRO_3"),
(17308,3,0,"Die, weakling!",14,0,100,0,0,10282,17631,0,"omor SAY_SLAY_1"),
(17308,3,1,"I am victorious!",14,0,100,0,0,10283,17632,0,"omor SAY_SLAY_2"),
(17308,4,0,"It is... not over.",14,0,100,0,0,10284,17630,0,"omor SAY_DEATH"),
(17308,5,0,"%s grins malevolently.",16,0,100,0,0,0,14756,0,"omor EMOTE_SHIELD");

DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_omor_the_unscarred_orbital_strike_target',
'spell_omor_the_unscarred_orbital_strike_whip');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(35642, 'spell_omor_the_unscarred_orbital_strike_target'),
(32185, 'spell_omor_the_unscarred_orbital_strike_whip');
