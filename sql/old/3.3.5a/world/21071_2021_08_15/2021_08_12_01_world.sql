--
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 55875;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,55875,0,0,31,0,3,29384,0,0,0,0,"","Group 0: Spell 'Captive Mechagnome Signal' (Effect 0) targets creature 'Captive Mechagnome'");

DELETE FROM `smart_scripts` WHERE `entryorguid` = 29384 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (2938400,2938401) AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUE
(29384,0,0,0,62,0,100,0,9871,0,0,0,0,11,57323,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Gossip Option 0 Selected - Cast 'Trigger Test'"),
(29384,0,1,0,62,0,100,0,9871,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Gossip Option 0 Selected - Close Gossip"),
(29384,0,2,0,8,0,100,0,55875,0,0,0,0,88,2938400,2938401,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Spellhit 'Captive Mechagnome Signal' - Run Random Script"),
(29384,0,3,0,34,0,100,0,8,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Reached Point 0 - Despawn Instant"),

(2938400,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Set Orientation Invoker"),
(2938400,9,1,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Remove NPC Flag Gossip"),
(2938400,9,2,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Set Emote State 0"),
(2938400,9,3,0,0,0,100,0,2000,2000,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Say Line 0"),
(2938400,9,4,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Set Run Off"),
(2938400,9,5,0,0,0,100,0,5000,5000,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,0,8,0,0,"Captive Mechagnome - On Script - Move Forward"),
(2938400,9,6,0,0,0,100,0,0,0,0,0,0,33,29962,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Quest Credit 'Slaves of the Stormforged'"),

(2938401,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Set Orientation Invoker"),
(2938401,9,1,0,0,0,100,0,0,0,0,0,0,83,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Remove NPC Flag Gossip"),
(2938401,9,2,0,0,0,100,0,0,0,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Set Emote State 0"),
(2938401,9,3,0,0,0,100,0,2000,2000,0,0,0,1,1,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Say Line 1"),
(2938401,9,4,0,0,0,100,0,0,0,0,0,0,33,29962,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Quest Credit 'Slaves of the Stormforged'"),
(2938401,9,5,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Captive Mechagnome - On Script - Despawn Instant");

-- Doesn't look like they have more than 2 scenarios, at least not in sniff and several videos
DELETE FROM `creature_text` WHERE `CreatureID` = 29384;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(29384,0,0,"Free again? Keeper Mimir's work awaits.",12,0,100,1,0,0,30762,0,"Captive Mechagnome"),
(29384,0,1,"Thank you, $r. I will join your struggle against the stormforged.",12,0,100,1,0,0,30763,0,"Captive Mechagnome"),
(29384,0,2,"New directive: leave mine and return to Inventor's Library.",12,0,100,1,0,0,30764,0,"Captive Mechagnome"),
(29384,0,3,"New directive: assist in the defeat of the iron dwarves.",12,0,100,1,0,0,30765,0,"Captive Mechagnome"),
(29384,1,0,"Does not compute. Unit malfunctioning. Directive: shut down.",12,0,100,25,0,0,30766,0,"Captive Mechagnome");
