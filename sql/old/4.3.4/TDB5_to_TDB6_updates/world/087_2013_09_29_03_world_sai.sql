-- 4.x removed
/*
UPDATE `creature_template` SET `ainame`='SmartAI' WHERE `entry`=10541;
DELETE FROM `smart_scripts` WHERE `entryorguid`IN(-23712,-23713,-23714,-23715,-23716,10541) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-23712,0,0,1,8,0,100,0,16378,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Krakle''s Thermometer - On Spell Hit (Temperature Reading)- Say'),
(-23713,0,0,1,8,0,100,0,16378,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Krakle''s Thermometer - On Spell Hit (Temperature Reading)- Say'),
(-23714,0,0,1,8,0,100,0,16378,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Krakle''s Thermometer - On Spell Hit (Temperature Reading)- Say'),
(-23715,0,0,1,8,0,100,0,16378,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,'Krakle''s Thermometer - On Spell Hit (Temperature Reading)- Say'),
(-23716,0,0,1,8,0,100,0,16378,0,0,0,33,10541,0,0,0,0,0,7,0,0,0,0,0,0,0,'Krakle''s Thermometer - On Spell Hit (Temperature Reading)- Give Kill Credit'),
(-23716,0,1,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,'Krakle''s Thermometer - Linked with Previous Event - Say');

DELETE FROM `creature_text` WHERE `entry` =10541;

INSERT INTO `creature_text` (`entry`, `groupid`, `id`, `text`, `type`, `language`, `probability`, `emote`, `duration`, `sound`, `comment`) VALUES 
(10541, 0, 0, 'It''s 428,000 degrees Kraklenheit... What''s happening, hot stuff?', 12, 0, 100, 0, 0, 0, 'Krakle''s Thermometer'),
(10541, 0, 1, 'DING! 428,000 degrees Kraklenheit, exactly! Well, approximately. Almost. Somewhere around there...', 12, 0, 100, 0, 0, 0, 'Krakle''s Thermometer'),
(10541, 0, 2, 'Measuring by Kraklenheit, it is 428,000 dewgrees! That''s Krakley!', 12, 0, 100, 0, 0, 0, 'Krakle''s Thermometer'),
(10541, 1, 0, 'The temperature is 122 degrees Kraklenheit.', 12, 0, 100, 0, 0, 0, 'Krakle''s Thermometer'),
(10541, 1, 1, 'The temperature is 9280 degrees Kraklenheit! That''s HOT!', 12, 0, 100, 0, 0, 0, 'Krakle''s Thermometer'),
(10541, 1, 2, 'Wow, it''s 3 degrees Kraklenheit.  Keep Looking.', 12, 0, 100, 0, 0, 0, 'Krakle''s Thermometer');
*/
