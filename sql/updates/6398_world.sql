DELETE FROM `script_texts` WHERE `entry` IN (-1571024, -1571025, -1571026, -1571027, -1571028, -1571029, -1571030);
INSERT INTO `script_texts` (`npc_entry`, `entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `sound`,`type`, `language`, `emote`, `comment`) VALUES
    (25478,-1571024,'Pathetic fool! A servant of malygos would sooner die than aid an emeny...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25478,-1571025,'Aargh! Do your worst, $C ! I''ll tell you NOTHING!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25478,-1571026,'Aahhhh! Release me! I am of no use to you. I swear it!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25478,-1571027,'Stop! I beg you, please stop. Please...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25478,-1571028,'Alright! I am beaten. Your previous archmage is held in a prison, elevated and sealed. Even if you manage to reach her, Salrand herself holds the key. Your mission is folly!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25478,-1571029,'I''ve given you the information, $C ! You''re wasting your time....',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25478,-1571030,'Noooo! This tortue is inhumane! You have what you want... why don''t you just kill me?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'');

UPDATE `creature_template` SET `ScriptName` ='npc_imprisoned_beryl_sorcerer' WHERE `entry` = 25478;
