-- Not sure about few delays & order
DELETE FROM `waypoint_data` WHERE `id` = 1242390;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(1242390,1,7907.6494,3311.5269,632.6077,2.007128715515136718,40000,0,0,0,0),
(1242390,2,7895.9673,3296.916,632.7554,3.94444,25000,0,0,0,0),
(1242390,3,7907.6494,3311.5269,632.6077,2.007128715515136718,60000,0,0,0,0),
(1242390,4,7923.843,3324.494,632.72974,0.802851438522338867,15000,0,0,0,0),
(1242390,5,7907.6494,3311.5269,632.6077,2.007128715515136718,40000,0,0,0,0),
(1242390,6,7923.843,3324.494,632.72974,0.802851438522338867,15000,0,0,0,0);

-- Default position
UPDATE `creature` SET `position_x` = 7907.6494, `position_y` = 3311.5269, `position_z` = 632.69293, `orientation` = 2.007128715515136718, `wander_distance` = 0, `MovementType` = 2, `spawntimesecs` = 30 WHERE `guid` = 124239 AND `id` = 30409;
UPDATE `creature_addon` SET `path_id` = 1242390 WHERE `guid` = 124239;

-- https://www.youtube.com/watch?v=3r-qw9eZ-u4
DELETE FROM `smart_scripts` WHERE `entryorguid` = 30409 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(30409,0,0,0,4,0,100,0,0,0,0,0,0,1,0,0,1,0,0,0,7,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - On Aggro - Say Line 0"),
(30409,0,1,0,4,0,100,0,0,0,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - On Aggro - Set Event Phase 1"),
(30409,0,2,0,0,0,100,0,0,0,3400,4800,0,11,14034,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - In Combat CMC - Cast 'Fireball'"),
(30409,0,3,0,0,0,100,0,10000,15000,15000,20000,0,11,60290,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - In Combat - Cast 'Blast Wave'"),
(30409,0,4,0,0,1,100,0,10000,10000,10000,10000,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - In Combat - Say Line 1 (Phase 1)"),
(30409,0,5,0,2,1,100,1,0,40,0,0,0,22,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - Between 0-40% Health - Set Event Phase 2 (No Repeat) (Phase 1)"),
(30409,0,6,7,0,2,100,1,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - In Combat - Say Line 2 (No Repeat) (Phase 2)"),
(30409,0,7,0,61,2,100,0,0,0,0,0,0,33,30412,0,0,0,0,0,24,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - On Link - Quest Credit 'Deep in the Bowels of The Underhalls' (Phase 2)"),
(30409,0,8,0,21,0,100,0,0,0,0,0,0,22,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Apprentice Osterkilgr - On Reached Home - Set Event Phase 0");

-- http://web.archive.org/web/20111224033613/www.wowhead.com/npc=30409
DELETE FROM `creature_text` WHERE `CreatureID` = 30409;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(30409,0,0,"You've come for the doctor's plans! You'll only find death!",12,0,100,0,0,0,31119,0,"Apprentice Osterkilgr"),
(30409,1,0,"I will never give you the information you seek!",12,0,100,0,0,0,31095,0,"Apprentice Osterkilgr"),
(30409,1,1,"You waste my time. I will tell you nothing!",12,0,100,0,0,0,31098,0,"Apprentice Osterkilgr"),
(30409,1,2,"I'll kill you little one and then I will add your body parts to what we're creating!",12,0,100,0,0,0,31104,0,"Apprentice Osterkilgr"),
(30409,1,3,"I will not let you destroy our hard work! Nergeld will be the end of you all!",12,0,100,0,0,0,31105,0,"Apprentice Osterkilgr"),
(30409,1,4,"When the doctor returns, your pitiful Shadow Vault will be laid to waste.",12,0,100,0,0,0,31106,0,"Apprentice Osterkilgr"),
(30409,1,5,"Nergeld is only the first of a new army of vargul-powered flesh giants. You've not known fear until now!",12,0,100,0,0,0,31107,0,"Apprentice Osterkilgr"),
(30409,1,6,"I have no time for this!",12,0,100,0,0,0,31108,0,"Apprentice Osterkilgr"),
(30409,1,7,"You're too late, puny one.",12,0,100,0,0,0,31109,0,"Apprentice Osterkilgr"),
(30409,2,0,"The doctor entrusted me with the plans to Nergeld, our flesh giant amalgamation made entirely of vargul! It will be the most powerful creation of its kind and a whole legion of them will be created to destroy your pitiful forces!",12,0,100,0,0,0,31090,0,"Apprentice Osterkilgr");
