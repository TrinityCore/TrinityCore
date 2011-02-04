-- Conversation between Highlord Tirion Fordring & The Ebon Watcher
-- SAI
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=30377;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30377,3037700);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30377,0,0,0,1,0,100,0,30000,60000,240000,240000,80,3037700,0,0,0,0,0,0,0,0,0,0,0,0,0,'Load script every 4 min ooc'),
(3037700,9,0,0,0,0,100,0,1000,1000,0,0,1,0,0,0,0,0,0,9,28179,0,10,0,0,0,0,'Highlord Tirion Fordring Say text 0'),
(3037700,9,1,0,0,0,100,0,6000,6000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 0'),
(3037700,9,2,0,0,0,100,0,12000,12000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 1'),
(3037700,9,3,0,0,0,100,0,12000,12000,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 2'),
(3037700,9,4,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,9,28179,0,10,0,0,0,0,'Highlord Tirion Fordring Say text 1'),
(3037700,9,5,0,0,0,100,0,6000,6000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 3'),
(3037700,9,6,0,0,0,100,0,9000,9000,0,0,1,2,0,0,0,0,0,9,28179,0,10,0,0,0,0,'Highlord Tirion Fordring Say text 2'),
(3037700,9,7,0,0,0,100,0,9000,9000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 4'),
(3037700,9,8,0,0,0,100,0,3000,3000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 5'),
(3037700,9,9,0,0,0,100,0,9000,9000,0,0,1,6,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 6'),
(3037700,9,10,0,0,0,100,0,7000,7000,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 7'),
(3037700,9,11,0,0,0,100,0,11000,11000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 8'),
(3037700,9,12,0,0,0,100,0,12000,12000,0,0,1,3,0,0,0,0,0,9,28179,0,10,0,0,0,0,'Highlord Tirion Fordring Say text 3'),
(3037700,9,13,0,0,0,100,0,13000,13000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0,'The Ebon Watcher Say text 9');
-- TEXT
DELETE FROM `creature_text` WHERE `entry` IN (28179,30377);
INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES
(28179,0,0,'The Lich King reacted swiftly to the breach. Faster than I anticipated.',0,0,100,1,0,0,'Highlord Tirion Fordring'),
(28179,1,0,'What would you have me do, Darion?',0,0,100,6,0,0,'Highlord Tirion Fordring'),
(28179,2,0,'Choose your words wisely, death knight. You stand amidst the company of the devoted.',0,0,100,1,0,0,'Highlord Tirion Fordring'),
(28179,3,0,'We will do this with honor, Darion. We will not sink to the levels of the Scourge to be victorious. To do so would make us no better than the monster that we fight to destroy!',0,0,100,1,0,0,'Highlord Tirion Fordring'),
(30377,0,0,'You are dealing with a being that holds within it the consciousness of the most cunning, intelligent, and ruthless individuals to ever live.',0,0,100,1,0,0,'The Ebon Watcher'),
(30377,1,0,'The Lich King is unlike any foe that you have ever faced, Highlord. Though you bested him upon the holy ground of Light\'s Hope Chapel, you tread now upon his domain.',0,0,100,1,0,0,'The Ebon Watcher'),
(30377,2,0,'You cannot win. Not like this...',0,0,100,274,0,0,'The Ebon Watcher'),
(30377,3,0,'Nothing. There is nothing that you can do while the Light binds you. It controls you wholly, shackling you to the ground with its virtues.',0,0,100,274,0,0,'The Ebon Watcher'),
(30377,4,0,'%s shakes his head.','2',0,100,0,0,0,'The Ebon Watcher'),
(30377,5,0,'Look upon the field, Highlord. The Lich King has halted your advance completely and won the upper hand!',0,0,100,25,0,0,'The Ebon Watcher'),
(30377,6,0,'The breach you created was sealed with Nerubian webbing almost as quickly as it was opened.',0,0,100,1,0,0,'The Ebon Watcher'),
(30377,7,0,'Your soldiers are being used as living shields to stave off artillery fire in the Valley of Echoes, allowing the forces of the Lich King to assault your base without impediment.',0,0,100,1,0,0,'The Ebon Watcher'),
(30377,8,0,'The Lich King knows your boundaries, Highlord. He knows that you will not fire on your own men. Do you not understand? He has no boundaries. No rules to abide.',0,0,100,1,0,0,'The Ebon Watcher'),
(30377,9,0,'Then you have lost, Highlord.',0,0,100,1,0,0,'The Ebon Watcher');
