-- Some of the NPC's in Sen'jin village should sometimes play the dance emote
UPDATE `creature_template_addon` SET `emote`=0 WHERE `entry`IN (3933,5942,7953);

UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (3184,3185,3186,3187,3933,5880,5942,7952,7953,10369);

DELETE FROM `smart_scripts` WHERE `entryorguid`=11814 AND `id`=2;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (3184,3185,3186,3187,3933,5880,5942,7952,7953,10369);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (318400,318500,318600,318700,393300,588000,594200,795200,795300,1036900,1181400) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3184,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,318500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Miao'zan - OoC - Run Script"),
(3185,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,318500,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mishiki - OoC - Run Script"),
(3186,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,318600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"K'waii - OoC - Run Script"),
(3187,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,318700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tai'tasi - OoC - Run Script"),
(3933,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,393300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hai'zan - OoC - Run Script"),
(5880,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,588000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Un'Thuwa - OoC - Run Script"),
(5942,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,594200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zansoa  - OoC - Run Script"),
(7952,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,795200,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zjolnir  - OoC - Run Script"),
(7953,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,795300,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Xar'Ti - OoC - Run Script"),
(10369,0,0,0,1,0,100,0,1000,60000,30000,300000,0,80,1036900,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Trayexir - OoC - Run Script"),
(11814,0,2,0,1,0,100,0,1000,60000,30000,300000,0,80,1181400,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kali Remik - OoC - Run Script"),

(318400,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Miao'zan - On Script - Set Emote State 10"),
(318400,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Miao'zan - On Script - Set Emote State 0"),

(318500,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mishiki - On Script - Set Emote State 10"),
(318500,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mishiki - On Script - Set Emote State 0"),

(318600,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"K'waii - On Script - Set Emote State 10"),
(318600,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"K'waii - On Script - Set Emote State 0"),

(318700,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tai'tasi - On Script - Set Emote State 10"),
(318700,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Tai'tasi - On Script - Set Emote State 0"),

(393300,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hai'zan - On Script - Set Emote State 10"),
(393300,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Hai'zan - On Script - Set Emote State 0"),

(588000,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Un'Thuwa - On Script - Set Emote State 10"),
(588000,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Un'Thuwa - On Script - Set Emote State 0"),

(594200,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zansoa - On Script - Set Emote State 10"),
(594200,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zansoa - On Script - Set Emote State 0"),

(795200,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zjolnir - On Script - Set Emote State 10"),
(795200,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Zjolnir - On Script - Set Emote State 0"),

(795300,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Xar'Ti - On Script - Set Emote State 10"),
(795300,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Xar'Ti - On Script - Set Emote State 0"),

(1036900,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Trayexir - On Script - Set Emote State 10"),
(1036900,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Trayexir - On Script - Set Emote State 0"),

(1181400,9,0,0,0,0,100,0,0,0,0,0,0,17,10,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kali Remik - On Script - Set Emote State 10"),
(1181400,9,1,0,0,0,100,0,30000,120000,0,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Kali Remik - On Script - Set Emote State 0");
