UPDATE `creature_text` SET `entry`=29227 WHERE `entry`=29173 AND `groupid`=76;
UPDATE `creature_text` SET `entry`=36794 WHERE `entry`=36658 AND `groupid` IN (1,2);

DELETE FROM `creature_text` WHERE `entry` IN (18879,17491);
INSERT INTO `creature_text`(`entry`,`groupid`,`id`,`text`,`type`,`comment`) VALUES
(18879,0,0,'The %s is very weak',16,'Phase Hunter - Emote'),
(17491,0,0,'Gakarah ma!',12,'Laughing Skull Rogue'),
(17491,0,1,'We are the true Horde!',12,'Laughing Skull Rogue');

DELETE FROM `smart_scripts` WHERE `entryorguid`=26670;
INSERT INTO `smart_scripts` VALUES 
(26670,0,0,1,1,0,100,6,0,0,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - Out Of Combat - Allow Combat Movement'),
(26670,0,1,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - Out Of Combat - Start Auto Attack'),
(26670,0,2,3,4,0,100,3,0,0,0,0,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - On Aggro - Cast Shoot'),
(26670,0,3,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - On Aggro - Increment Phase'),
(26670,0,4,5,9,1,100,2,5,30,5000,8000,11,48854,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - At 5 - 30 Range - Cast Shoot'),
(26670,0,5,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - At 5 - 30 Range - Display ranged weapon'),
(26670,0,6,7,4,0,100,5,0,0,0,0,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - On Aggro - Cast Shoot'),
(26670,0,7,0,61,0,100,0,0,0,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - On Aggro - Increment Phase'),
(26670,0,8,9,9,1,100,4,5,30,5000,8000,11,59241,0,0,0,0,0,2,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - At 5 - 30 Range - Cast Shoot'),
(26670,0,9,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - At 5 - 30 Range - Display ranged weapon'),
(26670,0,10,11,9,1,100,6,25,80,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 25 - 80 Range - Allow Combat Movement'),
(26670,0,11,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 25 - 80 Range - Start Auto Attack'),
(26670,0,12,13,9,1,100,6,0,5,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 0 - 5 Range - Allow Combat Movement'),
(26670,0,13,14,61,0,100,0,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 0 - 5 Range - Display melee weapon'),
(26670,0,14,0,61,0,100,0,0,0,0,0,20,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 0 - 5 Range - Start Auto Attack'),
(26670,0,15,16,9,1,100,6,5,15,0,0,21,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 5 - 15 Range - Allow Combat Movement'),
(26670,0,16,0,61,0,100,0,0,0,0,0,20,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 5 - 15 Range - Start Auto Attack'),(26670,0,17,17,0,0,100,2,9000,14000,22000,26000,11,48871,0,0,0,0,0,5,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - In Combat - Cast Aimed Shot'),(26670,0,18,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - In Combat - Display ranged weapon'),(26670,0,19,20,0,0,100,4,9000,14000,22000,26000,11,59243,0,0,0,0,0,5,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - In Combat - Cast Aimed Shot'),(26670,0,20,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - In Combat - Display ranged weapon'),(26670,0,21,22,0,0,100,2,14000,17000,24000,27000,11,48872,1,0,0,0,0,6,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - In Combat - Cast Multi-Shot'),(26670,0,22,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Normal) - In Combat - Display ranged weapon'),(26670,0,23,24,0,0,100,4,14000,17000,24000,27000,11,59244,1,0,0,0,0,6,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - In Combat - Cast Multi-Shot'),(26670,0,24,0,61,0,100,0,0,0,0,0,40,2,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter (Heroic) - In Combat - Display ranged weapon'),(26670,0,25,0,2,0,100,7,0,15,0,0,23,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 15% HP - Increment Phase'),(26670,0,26,27,2,2,100,7,0,15,0,0,21,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 15% HP - Allow Combat Movement'),(26670,0,27,0,61,0,100,0,0,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - At 15% HP - Flee For Assist'),(26670,0,28,0,7,0,100,6,0,0,0,0,40,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Ymirjar Flesh Hunter - On Evade - Display melee weapon');

DELETE FROM `creature_text` WHERE `entry` IN (23980,23954);
INSERT INTO `creature_text`(`entry`,`groupid`,`text`,`type`,`sound`,`comment`) VALUES
(23954,0,'I\'ll paint my face with your blood!',14,13207,'ingvar SAY_AGGRO_FIRST'),
(23954,1,'Mjul orm agn gjor!',14,13212,'ingvar SAY_KILL_FIRST'),
(23954,2,'My life for the... death god!',14,13213,'ingvar SAY_DEATH_FIRST'),
(23980,0,'I return! A second chance to carve out your skull!',14,13209,'ingvar SAY_AGGRO_SECOND'),
(23980,1,'I am a warrior born!',14,13214,'ingvar SAY_KILL_SECOND'),
(23980,2,'No! I can do... better! I can...',14,13211,'ingvar SAY_DEATH_SECOND');

DELETE FROM `creature_text` WHERE `entry`=11440;
INSERT INTO `creature_text`(`entry`,`id`,`text`,`type`,`probability`,`comment`) VALUES
(11440,0,'I\'ll crush you!',12,100,'Gordok Enforcer Aggro'),
(11440,1,'Me not feel so good.',12,100,'Gordok Enforcer Aggro'),
(11440,2,'Me smash! You die!',12,100,'Gordok Enforcer Aggro'),
(11440,3,'Raaar!!! Me smash $R!',12,100,'Gordok Enforcer Aggro');
