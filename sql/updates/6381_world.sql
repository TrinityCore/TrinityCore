DELETE FROM `script_waypoint` WHERE `entry`=26170;
INSERT INTO `script_waypoint` VALUES
   (26170,1, 3700.08, 3574.54, 473.322, 0, ''),
   (26170,2, 3705.94, 3573.63, 476.841, 0, ''),
   (26170,3, 3714.32, 3572.3,   477.442, 0, ''),
   (26170,4, 3720.19,3563.44, 477.441,  0, ''),
   (26170,5, 3721.24,3561.95, 477.44,  0, '');

UPDATE `creature_template` SET `ScriptName`='npc_general_arlos' WHERE `entry`=25250;
UPDATE `creature_template` SET `ScriptName`='npc_leryssa' WHERE `entry`=25251;
UPDATE `creature_template` SET `ScriptName`='npc_thassarian' WHERE `entry`=26170;
UPDATE `creature_template` SET `ScriptName`='npc_image_lich_king' WHERE `entry`=26203;
UPDATE `creature_template` SET `ScriptName`='npc_counselor_talbot' WHERE `entry`=25301;

DELETE FROM `script_texts` WHERE `entry` IN (-1571004,-1571005,-1571006,-1571007,-1571008,-1571009,-1571010,-1571011,-1571012,-1571013,-1571014,-1571015,-1571016,-1571017,-1571018,-1571019,-1571020,-1571021,-1571022,-1571022,-1571023);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
    (25301 ,-1571004,'My liege, the infiltration and control of the Alliance power structure by our cultists is well underway.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26203 ,-1571005,'Your progress in this region has been impressive, Blood Prince. I am pleased...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26203 ,-1571006,'The power you''ve bestowed upon me has allowed me great mental influence over human minds. I bear these offerings as proof of my progress.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26170 ,-1571007,'Leryssa!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,''),
    (26170 ,-1571008,'What have you done to my sister, you motherless elf scum!?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,''),
    (26203 ,-1571009,'Now this is a surprise, Thassarian. I hadn''t heard from Mograine or the other death knights for months. You''ve come to rejoin the Scourge, I take it?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26170 ,-1571010,'I would sooner slit my own throat. You will pay for what you did to your own men, Arthas... for what you did to me! I swear it.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25301 ,-1571011,'Allow me to take care of the intruders, lord. I will feed their entrails to the maggots.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26203 ,-1571012,'Do not fail me, San''layn. Return to Icecrown with this fool''s head or do not bother to return.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25301 ,-1571013,'Yes, my lord!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25250 ,-1571014,'What... what happened to me?',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25250 ,-1571015,'Ugh! My head won''t stop spinning...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25251 ,-1571016,'Thassarian, you''re alive!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,1,0,0,''),
    (26170 ,-1571017,'Leryssa... you... you''re all right!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25251 ,-1571018,'I thought... I thought you were... dead.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26170 ,-1571019,'I cannot return home with you just yet, Leryssa. I am not quite done with the Scourge.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (25251,-1571020,'Don''t leave me again! You want to fight for your country, but they don''t even want you! They sent you here to die!',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26170,-1571021,'You might be right, sister. My obligations to my land and King have been fulfilled. But there is still something that I owe to myself.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26170,-1571022,'I know that look in your eye... I''m not going to be able to talk you out of this. If you die on me again...',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,''),
    (26170,-1571023,'Do not worry, Leryssa. I will come back to you when I''m done. Nothing in the world will stop me from coming home to the only family that I have left.',NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,0,0,0,0,'');
