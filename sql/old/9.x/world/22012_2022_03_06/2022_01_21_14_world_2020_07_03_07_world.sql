--
DELETE FROM `creature_text` WHERE `CreatureID` = 24981;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(24981,0,0,"Objective acquired.  Initiating security routines.",12,0,100,0,0,0,24014,0,"Converted Sentry"),
(24981,0,1,"Commence location defense.",12,0,100,0,0,0,24015,0,"Converted Sentry"),
(24981,0,2,"Deployment successful.  Trespassers will be neutralized.",12,0,100,0,0,0,24016,0,"Converted Sentry");
