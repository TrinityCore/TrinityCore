-- Eldara Dawnrunner
DELETE FROM `creature_text` WHERE `CreatureID`=25032;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25032,0,0,"$n, it's very good to see you again!",                                                                                             12,0,100,0,0,0,24086,0,'Eldara Dawnrunner'),
(25032,0,1,"Everyone look, it's $n!",                                                                                                          12,0,100,0,0,0,24087,0,'Eldara Dawnrunner'),
(25032,0,2,"Dawnblade, demons and naga beware, $n is back.",                                                                                   12,0,100,0,0,0,24088,0,'Eldara Dawnrunner'),
(25032,0,3,"$G Milord : Milady;, $n, we are fortunate to have you here with us.",                                                              12,0,100,0,0,0,24089,0,'Eldara Dawnrunner'),
(25032,0,4,"The Shattered Sun Offensive is lucky to have $n on our side.",                                                                     12,0,100,0,0,0,24098,0,'Eldara Dawnrunner'),
(25032,0,5,"If it weren't for $n, we'd all be long dead.",                                                                                     12,0,100,0,0,0,24099,0,'Eldara Dawnrunner'),
(25032,0,6,"$n, thank you again for helping us. We couldn't have achieved any of this without you.",                                           12,0,100,0,0,0,24100,0,'Eldara Dawnrunner'),
(25032,0,7,"$Three cheers for $n!",                                                                                                            12,0,100,0,0,0,24102,0,'Eldara Dawnrunner'),
(25032,0,8,"It's an honor to serve with you, $n.",                                                                                             12,0,100,0,0,0,24103,0,'Eldara Dawnrunner'),
(25032,0,9,"If I were one of those Dawnblade blood elves, I'd be swimming away from the island now that $n is here.",                          12,0,100,0,0,0,24106,0,'Eldara Dawnrunner'),
(25032,0,10,"How many wretched do you think $n has put out of their misery?",                                                                  12,0,100,0,0,0,24107,0,'Eldara Dawnrunner'),
(25032,0,11,"Snap to attention, $n, one of our finest, is here!",                                                                              12,0,100,0,0,0,24108,0,'Eldara Dawnrunner'),
(25032,0,12,"Welcome back, $n.",                                                                                                               12,0,100,0,0,0,24110,0,'Eldara Dawnrunner'),
(25032,0,13,"There's our $g hero : heroine; right there! How are you doing, $n?",                                                              12,0,100,0,0,0,24111,0,'Eldara Dawnrunner'),
(25032,0,14,"I guarantee that without $n, this whole offensive would have been a failure.",                                                    12,0,100,0,0,0,24112,0,'Eldara Dawnrunner'),
(25032,0,15,"No matter what, your efforts will always be exalted here, $n!",                                                                   12,0,100,0,0,0,24113,0,'Eldara Dawnrunner'),
(25032,0,16,"Lay waste to the demons on the Dead Scar lately, $n?",                                                                            12,0,100,0,0,0,24115,0,'Eldara Dawnrunner'),
(25032,0,17,"$n, one of these days I want to buy you a drink.",                                                                                12,0,100,0,0,0,24116,0,'Eldara Dawnrunner'),
(25032,0,18,"$n, you have no idea what a relief it is to see you!",                                                                            12,0,100,0,0,0,24119,0,'Eldara Dawnrunner'),
(25032,0,19,"What a coincidence... we were just talking about you, $n!",                                                                       12,0,100,0,0,0,24120,0,'Eldara Dawnrunner'),
(25032,0,20,"Who needs sentries? $n is here!",                                                                                                 12,0,100,0,0,0,24121,0,'Eldara Dawnrunner'),
(25032,0,21,"Hey, $n, try to leave some of the glory for us, would ya?",                                                                       12,0,100,0,0,0,24122,0,'Eldara Dawnrunner'),
(25032,0,22,"Do not fight the enemy unprepared, $n.  I can provide you with very powerful items... provided you have proven yourself to us.",  12,0,100,0,0,0,24302,0,'Eldara Dawnrunner'),
(25032,0,23,"I don't even want to think about what'll happen here if $n ever decides not to come back.",                                       12,0,100,0,0,0,24117,0,'Eldara Dawnrunner');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry`=25032;
DELETE FROM `smart_scripts` WHERE (`source_type`=0 AND `entryorguid`=25032);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25032,0,0,0,10,0,100,0,1,20,120000,120000,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Eldara Dawnrunner - OOC LOS - Say Line');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=25032;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(22, 1, 25032, 0, 0, 5, 0, 1077, 128, 0, 0, 0, 0, '', 'Smart event 0 for Eldara Dawnrunner will execute if the payer is exalted with Shattered Sun');
