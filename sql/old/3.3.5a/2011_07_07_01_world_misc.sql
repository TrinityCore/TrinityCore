DELETE FROM `gossip_menu_option` WHERE `menu_id`=3062 AND `id` BETWEEN 0 AND 6;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`) VALUES
(3062,0,0, 'Low spirits', 1,1),
(3062,1,0, 'Bad hang nail', 1,1),
(3062,2,0, 'Feeling underpowered', 1,1),
(3062,3,0, 'Jungle Fever', 1,1),
(3062,4,0, 'Uni-brow', 1,1),
(3062,5,0, 'Whiplash', 1,1),
(3062,6,0, 'I don''t want to go back to work', 1,1);

DELETE FROM `creature_template_addon` WHERE `entry`=10578;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(10578,0,0,257,0, NULL); -- Bom'bay

UPDATE `creature` SET `MovementType`=1,`spawndist`=5 WHERE `id`=10578; -- rand movement
UPDATE `creature_template` SET `AIName`='SmartAI',`MovementType`=1 WHERE `entry`=10578;

DELETE FROM `smart_scripts` WHERE (`entryorguid`=10578 AND `source_type`=0);
DELETE FROM `smart_scripts` WHERE (`entryorguid`=1057800 AND `source_type`=9);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(10578, 0, 0, 0, 62, 0, 100, 0, 3062, 0, 0, 0, 80, 10578*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - On gossip select 0 run timed action list'),
(10578, 0, 1, 0, 62, 0, 100, 0, 3062, 1, 0, 0, 80, 10578*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - On gossip select 1 run timed action list'),
(10578, 0, 2, 0, 62, 0, 100, 0, 3062, 2, 0, 0, 80, 10578*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - On gossip select 2 run timed action list'),
(10578, 0, 3, 0, 62, 0, 100, 0, 3062, 3, 0, 0, 80, 10578*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - On gossip select 3 run timed action list'),
(10578, 0, 4, 0, 62, 0, 100, 0, 3062, 4, 0, 0, 80, 10578*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - On gossip select 4 run timed action list'),
(10578, 0, 5, 0, 62, 0, 100, 0, 3062, 5, 0, 0, 80, 10578*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - On gossip select 5 run timed action list'),
(10578, 0, 6, 0, 62, 0, 100, 0, 3062, 6, 0, 0, 80, 10578*100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - On gossip select 6 run timed action list'),
(10578, 0, 7, 0, 1, 0, 100, 0, 1000, 1000, 20000, 40000, 10, 153, 15, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - Every 20-40 seconds do random emote'),
(1057800, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - Close gossip'),
-- could use a stop movement here
(1057800, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 4, 6482, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - Play a sound'),
(1057800, 9, 2, 0, 0, 0, 100, 0, 100, 100, 0, 0, 11, 17009, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Bom''bay - Cast Voodoo');
