-- 
DELETE FROM `gameobject_template` WHERE `entry` IN (188459);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayid`, `name`, `size`, `data0`, `data1`, `data2`, `data3`,`data6`, `VerifiedBuild`) VALUES
(188459, 6, 0, 'Thor Modan Mole Machine Trap', 0.75, 0, 0, 0, 47387, -1, 0); -- From 6.x DB

SET @ENTRY := 26261;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=26786 AND `source_type`=0 AND `id` IN (1,2);
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,8,0,100,1,47394,0,0,0,80,@ENTRY*100,1,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Hills Giant - On Spellhit 'Kurun's Blessing' - Run Script"),
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,33,26261,0,0,0,0,0,7,0,0,0,0,0,0,0,"Grizzly Hills Giant - Action list - Quest Credit 'Rallying the Troops'"),
(@ENTRY*100,9,1,0,0,0,100,0,0,0,0,0,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0,"Grizzly Hills Giant - Action list - Runed Giant say text 0"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,11,47410,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Hills Giant - Action list - cast Thor Modan Mole"),
(@ENTRY*100,9,3,0,0,0,100,0,8000,8000,0,0,11,47387,0,0,0,0,0,1,0,0,0,0,0,0,0,"Grizzly Hills Giant - Action list - cast to summon iron dwarf"),
(@ENTRY,0,1,0,1,0,100,0,2000,5000,4000,6000,11,46815,0,0,0,0,0,19,26264,85,0,0,0,0,0,"Grizzly Hills Giant - Out of Combat - Cast 'Toss Boulder'"),
(@ENTRY,0,2,0,1,0,100,0,3000,9000,7000,13000,11,46815,0,0,0,0,0,19,26417,100,0,0,0,0,0,"Grizzly Hills Giant - Out of Combat - Cast 'Toss Boulder'"),
(26786,0,1,0,4,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,"Iron Rune Avenger - On aggro - say text 1"),
(26786,0,2,0,54,0,100,0,0,0,0,0,49,0,0,0,0,0,0,21,40,0,0,0,0,0,0,"Iron Rune Avenger - Just summoned - Attack closest player");


UPDATE `creature` SET `MovementType`=1, `spawndist`=10 WHERE `guid` IN ( 109947, 109949, 109944, 109940, 109942, 109950, 109953, 109939);
DELETE FROM `creature` WHERE `guid` IN (86178,86175);
DELETE FROM `creature` WHERE `id` =26786;
DELETE FROM `gameobject` WHERE `id`=188460;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND  `SourceGroup`=1 AND `ElseGroup`=1 AND `SourceEntry`=46815;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 46815, 0, 1, 31, 0, 3, 26417, 0, 0, 0, 0, '', 'Toss Boulder - only targets Dummy');

DELETE FROM `creature_text` WHERE `entry` IN (26786, 26417);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`, `BroadcastTextId`) VALUES
(26786,0,0,'For the glory of Loken!',12,0,100,0,0,0,'Iron Rune Avenger', 25984),
(26786,0,1,'No one will keep us from our destiny!',12,0,100,0,0,0,'Iron Rune Avenger', 25983),
(26786,0,2,'You are a fool to fight Kurun''s hopeless battle!',12,0,100,0,0,0,'Iron Rune Avenger', 25986),
(26786,0,3,'You will pay for your interference!',12,0,100,0,0,0,'Iron Rune Avenger', 25985),
(26786,0,4,'Your life is forfeit, ally of stone!',12,0,100,0,0,0,'Iron Rune Avenger', 25987),
(26417,0,0,'Children of iron, lend me your blades!',12,0,100,0,0,0,'Runed Giant', 25981),
(26417,0,1,'Crush the small one!',12,0,100,0,0,0,'Runed Giant', 25979),
(26417,0,2,'Iron masters, aid me in this battle!',12,0,100,0,0,0,'Runed Giant', 25967),
(26417,0,3,'The enemy grows stronger! Aid me!',12,0,100,0,0,0,'Runed Giant', 25982),
(26417,0,4,'We will destroy you, puny creature!',12,0,100,0,0,0,'Runed Giant', 25980);
