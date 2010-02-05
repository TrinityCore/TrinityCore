-- Novos
DELETE FROM `script_texts` WHERE `entry` in (-1600000,-1600001,-1600002,-1600003,-1600004,-1600005);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(26631,-1600000,'The chill that you feel is the herald of your doom!',null,null,null,null,null,null,null,null,13173,1,0,0,'novos SAY_AGGRO'),
(26631,-1600001,'Such is the fate of all who oppose the Lich King.',null,null,null,null,null,null,null,null,13175,1,0,0,'novos SAY_KILL'),
(26631,-1600002,'Your efforts... are in vain.',null,null,null,null,null,null,null,null,13174,1,0,0,'novos SAY_DEATH'),
(26631,-1600003,'Bolster my defenses! Hurry, curse you!',null,null,null,null,null,null,null,null,13176,1,0,0,'novos SAY_NECRO_ADD'),
(26631,-1600004,'Surely you can see the futility of it all!',null,null,null,null,null,null,null,null,13177,1,0,0,'novos SAY_REUBBLE_1'),
(26631,-1600005,'Just give up and die already!',null,null,null,null,null,null,null,null,13178,1,0,0,'novos SAY_REUBBLE_2');

-- Trollgore
DELETE FROM `script_texts` WHERE `entry` in (-1600006,-1600007,-1600008,-1600009,-1600010);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(26630,-1600006,'More grunts, more glands, more FOOD!',null,null,null,null,null,null,null,null,13181,1,0,0,'trollgore SAY_AGGRO'),
(26630,-1600007,'You have gone, me gonna eat you!',null,null,null,null,null,null,null,null,13185,1,0,0,'trollgore SAY_KILL'),
(26630,-1600008,'So hungry! Must feed!',null,null,null,null,null,null,null,null,13182,1,0,0,'trollgore SAY_CONSUME'),
(26630,-1600009,'Corpse go boom!',null,null,null,null,null,null,null,null,13184,1,0,0,'trollgore SAY_EXPLODE'),
(26630,-1600010,'Aaaargh...',null,null,null,null,null,null,null,null,13183,1,0,0,'trollgore SAY_DEATH');

-- Tharon'ja
DELETE FROM `script_texts` WHERE `entry` in (-1600011,-1600012,-1600013,-1600014,-1600015,-1600016,-1600017,-1600018);
INSERT INTO `script_texts` (`npc_entry`,`entry`,`content_default`,`content_loc1`,`content_loc2`,`content_loc3`,`content_loc4`,`content_loc5`,`content_loc6`,`content_loc7`,`content_loc8`,`sound`,`type`,`language`,`emote`,`comment`) VALUES
(26632,-1600011,'Tharon''ja sees all! The work of mortals shall not end the eternal dynasty!',null,null,null,null,null,null,null,null,13862,1,0,0,'tharon''ja SAY_AGGRO'),
(26632,-1600012,'As Tharon''ja predicted.',null,null,null,null,null,null,null,null,13863,1,0,0,'tharon''ja SAY_KILL_1'),
(26632,-1600013,'As it was written.',null,null,null,null,null,null,null,null,13864,1,0,0,'tharon''ja SAY_KILL_2'),
(26632,-1600014,'Your flesh serves Tharon''ja now!',null,null,null,null,null,null,null,null,13865,1,0,0,'tharon''ja SAY_FLESH_1'),
(26632,-1600015,'Tharon''ja has a use for your mortal shell!',null,null,null,null,null,null,null,null,13866,1,0,0,'tharon''ja SAY_FLESH_2'),
(26632,-1600016,'No! A taste... all too brief!',null,null,null,null,null,null,null,null,13867,1,0,0,'tharon''ja SAY_SKELETON_1'),
(26632,-1600017,'Tharon''ja will have more!',null,null,null,null,null,null,null,null,13868,1,0,0,'tharon''ja SAY_SKELETON_2'),
(26632,-1600018,'I''m... impossible! Tharon''ja is eternal! Tharon''ja... is...',null,null,null,null,null,null,null,null,13869,1,0,0,'tharon''ja SAY_DEATH');