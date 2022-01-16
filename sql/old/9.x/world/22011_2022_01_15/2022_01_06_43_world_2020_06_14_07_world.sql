-- Brother Sarno
DELETE FROM `smart_scripts` WHERE `entryorguid` = 1125 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(1125,2,0,1,46,0,100,0,1125,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (Cathedral of Light) - On Trigger - Store Targetlist"),
(1125,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,10,44022,7917,0,0,0,0,0,0,"Areatrigger (Cathedral of Light) - On Link - Send Target 1 (Brother Sarno)"),
(1125,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,10,44022,7917,0,0,0,0,0,0,"Areatrigger (Cathedral of Light) - On Link - Set Data 0 1 (Brother Sarno)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 1125;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(1125,"SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 7917 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(7917,0,0,1,38,0,100,0,0,1,60000,60000,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Brother Sarno - On Data Set 0 1 - Set Orientation Stored Target"),
(7917,0,1,0,61,0,100,0,0,0,0,0,0,1,0,3000,0,0,0,0,12,1,0,0,0,0,0,0,0,"Brother Sarno - On Link - Say Line 0"),
(7917,0,2,0,52,0,100,0,0,7917,0,0,0,66,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Brother Sarno - On Text Over - Set Orientation Home Position");

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 7917 AND `SourceId` = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 1125 AND `SourceId` = 2;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
-- (22,1,1125,2,0,6,0,469,0,0,0,0,0,"","Group 0: Execute SAI (Action 0) if player's faction is Alliance"),
(22,1,1125,2,0,15,0,32,0,0,1,0,0,"","Group 0: Execute SAI (Action 0) if player is not a Death Knight");

-- Karaaz
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4495 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4495,2,0,1,46,0,100,0,4495,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (The Stormspire) - On Trigger - Store Targetlist"),
(4495,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,10,71938,20242,0,0,0,0,0,0,"Areatrigger (The Stormspire) - On Link - Send Target 1 (Karaaz)"),
(4495,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,10,71938,20242,0,0,0,0,0,0,"Areatrigger (The Stormspire) - On Link - Set Data 0 1 (Karaaz)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4495;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4495,"SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 20242 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(20242,0,0,0,38,0,100,0,0,1,120000,120000,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Karaaz - On Data Set 0 1 - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 20242;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(20242,0,0,"Of course none of my goods are stolen.  But if someone asks, you didn't get them from me!",12,0,100,1,0,0,17914,0,"Karaaz"),
(20242,0,1,"The latest blueprints, patterns and schematics are available right here.  These instructions are so simple to follow they practically craft themselves!",12,0,100,1,0,0,17915,0,"Karaaz"),
(20242,0,2,"The best selection of smuggled goods is available right here, $n.  Great for the whole family!  Avoid goblin taxation and naaru prohibition - the Consortium is here to fill your every shopping need!",12,0,100,1,0,0,17916,0,"Karaaz"),
(20242,0,3,"Pssst!  I have something that might interest you, $n.  It fell off a pack mule in Nagrand!",12,0,100,1,0,0,17917,0,"Karaaz");

-- Griftah
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4389 AND `source_type` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4389,2,0,1,46,0,100,0,4389,0,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Areatrigger (The Stormspire) - On Trigger - Store Targetlist"),
(4389,2,1,2,61,0,100,0,0,0,0,0,0,100,1,0,0,0,0,0,10,68758,19227,0,0,0,0,0,0,"Areatrigger (The Stormspire) - On Link - Send Target 1 (Griftah)"),
(4389,2,2,0,61,0,100,0,0,0,0,0,0,45,0,1,0,0,0,0,10,68758,19227,0,0,0,0,0,0,"Areatrigger (The Stormspire) - On Link - Set Data 0 1 (Griftah)");

DELETE FROM `areatrigger_scripts` WHERE `entry` = 4389;
INSERT INTO `areatrigger_scripts` (`entry`,`ScriptName`) VALUES
(4389,"SmartTrigger");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 19227 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19227,0,0,0,38,0,100,0,0,1,120000,120000,0,1,0,0,0,0,0,0,12,1,0,0,0,0,0,0,0,"Griftah - On Data Set 0 1 - Say Line 0");

DELETE FROM `creature_text` WHERE `CreatureID` = 19227;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(19227,0,0,"Hey! Hey, $r! I be havin' just the thing for ya. Ya ever see a tikbalang? Frightenin' creatures. Prone to stealin' ya away. What ya need is one of my tikbalang wards. Guaranteed to ward away all tikbalangs!",12,0,100,0,0,0,16318,0,"Griftah"),
(19227,0,1,"Look over here, $c! I got somethin' for ya. Just what ya need. It's soap, right... and it's on a rope! No offense, $G man:honey;, but yer a little ripe, know what I'm sayin'?",12,0,100,0,0,0,16319,0,"Griftah"),
(19227,0,2,"Ya look lovesick. Special someone be gettin' ya down, eh? No worries, no worries. Ya get this medallion from me, ya wear it when ya see 'em, and they be all over ya, $G man:sweetheart;!",12,0,100,0,0,0,16320,0,"Griftah"),
(19227,0,3,"Dangerous out there, innit? Know what ya need? Protection. I can help ya defy death itself! Ya wear this madstone 'round yer neck, see, and then ya be able to come back if ya find yerself in the spirit world! Just a quick jaunt to yer corpse and up ya come, fresh and new!",12,0,100,0,0,0,16321,0,"Griftah"),
(19227,0,4,"Amazing amulets! Incredible curios! The newfangled jewelcrafters be havin' nothin' on the tried and true mystical methods of ol' Griftah! Improve yerself through these magical talismans for a bargain price!",12,0,100,0,0,0,16322,0,"Griftah"),
(19227,0,5,"C'mere, $r. Ya don't want to be riskin' yerself in a dungeon, do ya? Filthy work, and for what? Some worthless trinket? Nah, what ya need be one of my amulets. Guaranteed to work!",12,0,100,0,0,0,16323,0,"Griftah"),
(19227,0,6,"Ya look tired, $c. I be havin' somethin' for ya. These amulets, they can help ya leap obstacles and swim through the rivers like ya be born to it. They energize the food ya be eatin', makin' yer wounds close before yer eyes!",12,0,100,0,0,0,16324,0,"Griftah");
