--
UPDATE `smart_scripts` SET `action_type`=85 WHERE `entryorguid`=46293 AND `source_type`=0 AND `id`=0;
UPDATE `smart_scripts` SET `target_type`=19, `target_param1`=0, `target_param2`=30 WHERE `entryorguid`=73452 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_type`=85 WHERE `entryorguid`=230700 AND `source_type`=9 AND `id` IN (0,1,2);
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `Entry` IN (164819, 177673, 190549);
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=91874 WHERE `entryorguid`=3889500 AND `source_type`=9 AND `id` IN (1);
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=91873 WHERE `entryorguid`=4923000 AND `source_type`=9 AND `id` IN (1);
UPDATE `smart_scripts` SET `action_type`=85, `action_param1`=91876 WHERE `entryorguid`=4923100 AND `source_type`=9 AND `id` IN (1);
UPDATE `smart_scripts` SET `action_type`=11, `action_param1`=91945 WHERE `entryorguid`=4934000 AND `source_type`=9 AND `id` IN (1);

UPDATE `smart_scripts` SET `id`=1 WHERE `entryorguid`= 5327 AND `source_type`=0 AND `action_type`=11;                                                
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (234, 2287, 2719, 3142, 3643, 3987, 5327, 5888, 8151, 8154, 10828, 12265, 29176, 29181, 29186, 29199, 29200, 29204, 32438, 55418, 57875, 57877, 57890) AND `source_type`=0;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (3643) AND `source_type`=1;
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (13601) AND `source_type`=0 AND `id` IN (3,4,9);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN (14390) AND `source_type`=0 AND `id` IN (9);
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (14467) AND `source_type`=0 AND `id` IN (0);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN (15641) AND `source_type`=0 AND `id` IN (9);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN (16403) AND `source_type`=0 AND `id` IN (9);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN (16459) AND `source_type`=0 AND `id` IN (2);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN (16704) AND `source_type`=0 AND `id` IN (13);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN (17270) AND `source_type`=0 AND `id` IN (13);
UPDATE `smart_scripts` SET `event_type`=61 WHERE `entryorguid` IN (17670) AND `source_type`=0 AND `id` IN (13);
UPDATE `smart_scripts` SET `link`=0 WHERE `entryorguid` IN (19507) AND `source_type`=0 AND `id` IN (1);

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (15424,26213,26233,38429,45501);
DELETE FROM `creature_addon` WHERE `guid` IN (38101,38101,24084,45501,10299,92880,92881,26233,26213,23967,38429);

DELETE FROM `npc_vendor` WHERE `item`=85663;
DELETE FROM `npc_vendor` WHERE `item`=79249;

UPDATE `creature_template` SET `npcflag`=`npcflag`|2 WHERE `entry` IN (2397,3411,3467,10299,14326,16365,35087,35091,37915,38895,49230,49231,49340);
UPDATE `creature_template` SET `npcflag`=`npcflag`|128 WHERE `entry` IN (3008,8416,10666,44376);
UPDATE `npc_vendor` SET `incrtime`=7200 WHERE `item`=8409;

UPDATE `creature` SET `guid`=42567 WHERE `guid`=46; -- sync db values with 3.3.5a
UPDATE `creature` SET `guid`=88701 WHERE `guid`=453;
UPDATE `creature` SET `guid`=88703 WHERE `guid`=455;
UPDATE `creature` SET `guid`=88702 WHERE `guid`=454;
UPDATE `creature` SET `guid`=88704 WHERE `guid`=456;
UPDATE `creature` SET `guid`=86429 WHERE `guid`=536;
UPDATE `creature` SET `guid`=86436 WHERE `guid`=543;
UPDATE `creature` SET `guid`=86432 WHERE `guid`=539;
UPDATE `creature` SET `guid`=86431 WHERE `guid`=538;
UPDATE `creature` SET `guid`=86441 WHERE `guid`=548;
UPDATE `creature` SET `guid`=86439 WHERE `guid`=546;
UPDATE `creature` SET `guid`=86438 WHERE `guid`=545;
UPDATE `creature` SET `guid`=86430 WHERE `guid`=537;
UPDATE `creature` SET `guid`=86437 WHERE `guid`=544;
UPDATE `creature` SET `guid`=86435 WHERE `guid`=542;
UPDATE `creature` SET `guid`=86434 WHERE `guid`=541;
UPDATE `creature` SET `guid`=86433 WHERE `guid`=540;
UPDATE `creature` SET `guid`=86440 WHERE `guid`=547;
UPDATE `creature` SET `guid`=76296 WHERE `guid`=1042;
UPDATE `creature` SET `guid`=76297 WHERE `guid`=1043;
UPDATE `creature` SET `guid`=76298 WHERE `guid`=1044;

DELETE FROM `creature_addon` WHERE `guid` IN (453,454,455,456);

UPDATE `smart_scripts` SET `entryorguid`=88701 WHERE `entryorguid`=453;
UPDATE `smart_scripts` SET `entryorguid`=88702 WHERE `entryorguid`=454;
UPDATE `smart_scripts` SET `entryorguid`=88703 WHERE `entryorguid`=455;
UPDATE `smart_scripts` SET `entryorguid`=88704 WHERE `entryorguid`=456;

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (88701,88702,88704);
