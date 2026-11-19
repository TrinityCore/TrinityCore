-- 
UPDATE `smart_scripts` SET `action_type`=134, `action_param1`=56516, `target_type`=1 WHERE `entryorguid` IN (30273) AND `source_type`=0 AND `id`=0;
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|512 WHERE `entry` IN (30273,30268,30274);
UPDATE `smart_scripts` SET `target_type`=23 WHERE `entryorguid` IN (3027400) AND `source_type`=9 AND `id` IN (0,2);
UPDATE `smart_scripts` SET `action_param2`=2 WHERE `entryorguid` IN (30274) AND `source_type`=0 AND `id`=0;

DELETE FROM `creature_text` WHERE `CreatureID`=30274;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(30274,0,0,"Might grace you, $c. Let the Scourge feel the fury of a million lost souls!",12,0,100,0,0,0,30976,0,"Freed Crusader Speach"),
(30274,0,1,"Glory and strength to you, $c. I bless you with all the strength left in me. May this nightmare soon end!",12,0,100,0,0,0,30977,0,"Freed Crusader Speach"),
(30274,0,2,"Wisdom of the ages upon you, noble $c.",12,0,100,0,0,0,30978,0,"Freed Crusader Speach"),
(30274,0,3,"Thank you and farewell, friend. I must return to the Argent Vanguard.",12,0,100,0,0,0,30980,0,"Freed Crusader Speach");
