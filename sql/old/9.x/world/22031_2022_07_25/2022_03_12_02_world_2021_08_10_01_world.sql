-- Fizzcrank Survivor
UPDATE `creature_template` SET `unit_flags` = 33587968 WHERE `entry` = 25773;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25773 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2577300 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25773,0,0,0,63,0,100,0,0,0,0,0,0,80,2577300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fizzcrank Survivor - On Just Created - Run Script"),

(2577300,9,0,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Fizzcrank Survivor - On Script - Say Line 0"),
(2577300,9,1,0,0,0,100,0,4000,4000,0,0,0,11,34427,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fizzcrank Survivor - On Script - Cast 'Ethereal Teleport'"),
(2577300,9,2,0,0,0,100,0,2000,2000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Fizzcrank Survivor - On Script - Despawn Instant");

DELETE FROM `creature_text` WHERE `CreatureID` = 25773;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25773,0,0,"I'm flesh and blood again! Thank you, $c!",12,7,100,1,0,0,24967,0,"Fizzcrank Survivor"),
(25773,0,1,"Thank you so much! I thought I'd never wake up from that nightmare!",12,7,100,1,0,0,24968,0,"Fizzcrank Survivor"),
(25773,0,2,"Oh no, not the transmatter... it'll probably malfunction!",12,7,100,1,0,0,24969,0,"Fizzcrank Survivor"),
(25773,0,3,"But... but... I was perfect!",12,7,100,1,0,0,24970,0,"Fizzcrank Survivor"),
(25773,0,4,"Where am I? Who are you? What's that strange feeling?",12,7,100,1,0,0,24971,0,"Fizzcrank Survivor"),
(25773,0,5,"Mechazod is insane! You have to stop him before it's too late!",12,7,100,1,0,0,24972,0,"Fizzcrank Survivor"),
(25773,0,6,"It was horrible! They've all been changed!",12,7,100,1,0,0,24973,0,"Fizzcrank Survivor"),
(25773,0,7,"He called it the Curse of the Flesh. Mechazod is deranged!",12,7,100,1,0,0,24974,0,"Fizzcrank Survivor");

-- Sentry-bot 57-K
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25753 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25753,0,0,0,4,0,50,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Aggro - Say Line 0"),
-- Not at %HP
(25753,0,1,2,0,0,100,1,10000,10000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - In Combat - Say Line 1 (No Repeat)"),
(25753,0,2,3,61,0,100,0,0,0,0,0,0,11,6668,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - In Combat - Cast 'Red Firework'"),
(25753,0,3,0,61,0,100,0,0,0,0,0,0,39,25,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - In Combat - Call For Help"),
-- Should be changed later
(25753,0,4,0,8,0,100,0,46432,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Spellhit 'Power of the Storm' - Set Event Phase 1"),
(25753,0,5,0,6,1,100,0,0,0,0,0,0,11,46443,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Just Died - Cast 'Weakness to Lightning: Kill Credit Direct to Player' (Phase 1)"),
(25753,0,6,0,6,1,100,0,0,0,0,0,0,11,46444,2,0,0,0,0,7,0,0,0,0,0,0,0,0,"Sentry-bot 57-K - On Just Died - Cast 'Weakness to Lightning: Kill Credit from Pet' (Phase 1)");

DELETE FROM `creature_text` WHERE `CreatureID` = 25753;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25753,0,0,"Warning: $r incursion detected!",12,0,100,0,0,0,24978,0,"Sentry-bot 57-K"),
(25753,0,1,"Activate counter-measures. Repel intruder.",12,0,100,0,0,0,24979,0,"Sentry-bot 57-K"),
(25753,0,2,"Attention all units, $r inside the perimeter.",12,0,100,0,0,0,24980,0,"Sentry-bot 57-K"),
(25753,0,3,"You have been detected. You will be assimilated or eliminated.",12,0,100,0,0,0,24981,0,"Sentry-bot 57-K"),
(25753,1,0,"Warning! Warning! Intruder alert! Intruder alert!",14,0,100,0,0,5805,4142,0,"Sentry-bot 57-K");

-- Fizzcrank Mechagnome
UPDATE `smart_scripts` SET `event_chance` = 50, `action_param1` = 0, `action_param2` = 0, `comment` = "Fizzcrank Mechagnome - On Aggro - Say Line 0" WHERE `entryorguid` = 25814 AND `source_type` = 0 AND `id` = 0;
DELETE FROM `creature_text` WHERE `CreatureID` = 25814;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(25814,0,0,"We are Mechagnome... resistance is futile.",12,0,100,0,0,0,25000,0,"Fizzcrank Mechagnome"),
(25814,0,1,"You are cursed and we are the cure.",12,0,100,0,0,0,25001,0,"Fizzcrank Mechagnome"),
(25814,0,2,"The flesh is weak. We will make you better, stronger... faster.",12,0,100,0,0,0,25002,0,"Fizzcrank Mechagnome"),
(25814,0,3,"We can decurse you, we have the technology.",12,0,100,0,0,0,25003,0,"Fizzcrank Mechagnome"),
(25814,0,4,"The Gearmaster has plans for your weak flesh.",12,0,100,0,0,0,25004,0,"Fizzcrank Mechagnome"),
(25814,0,5,"Today, the Borean Tundra. Tomorrow, the world!",12,0,100,0,0,0,25005,0,"Fizzcrank Mechagnome"),
(25814,0,6,"You will be decursed!",12,0,100,0,0,0,25006,0,"Fizzcrank Mechagnome"),
(25814,0,7,"Come be perfect with us, $g brother : sister;.",12,0,100,0,0,0,25007,0,"Fizzcrank Mechagnome"),
(25814,0,8,"Maintenance initiated.",12,0,100,0,0,0,25008,0,"Fizzcrank Mechagnome");
