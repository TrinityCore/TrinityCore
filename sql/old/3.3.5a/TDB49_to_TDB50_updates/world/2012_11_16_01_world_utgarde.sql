-- Areatrigger script
DELETE FROM `areatrigger_scripts` WHERE `entry`=4838;
INSERT INTO `areatrigger_scripts`(`entry`,`ScriptName`) VALUES
(4838,'SmartTrigger');

DELETE FROM `smart_scripts` WHERE `entryorguid`=4838 AND `source_type`=2;
INSERT INTO `smart_scripts`(`entryorguid`,`source_type`,`event_type`,`event_param1`,`action_type`,`action_param1`,`action_param2`,`target_type`,`target_param1`,`comment`) VALUES
(4838,2,46,4838,45,28,6,10,125946,'Areatrigger in Utgarde Keep near Ingvar - On trigger - Set data of Enslaved Proto Drake');

-- Template updates for proto drake and rider
UPDATE `creature_template` SET `AIName`='',`ScriptName`='npc_enslaved_proto_drake' WHERE `entry`=24083; -- Proto drake non heroic
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (24849,31676); -- Proto drake rider

-- Waypoints for core script
DELETE FROM `waypoint_data` WHERE `id`=125946;
INSERT INTO `waypoint_data`(`id`,`point`,`position_x`,`position_y`,`position_z`,`move_flag`) VALUES
(125946,1,210.92,-185.92,203.729,1),
(125946,2,215.397,-181.239,205.773,1),
(125946,3,219.674,-176.469,202.97,1),
(125946,4,223.183,-172.761,200.058,1),
(125946,5,228.007,-168.952,196.713,1),
(125946,6,230.514,-167.104,195.116,1),
(125946,7,235.687,-163.455,192.13,1),
(125946,8,239.569,-161.025,190.346,1);

-- Mount the rider to the drake
DELETE FROM `vehicle_template_accessory` WHERE `entry`=24083;
INSERT INTO `vehicle_template_accessory`(`entry`,`accessory_entry`,`seat_id`,`minion`,`description`,`summontype`,`summontimer`) VALUES
(24083,24849,0,0,'Proto Drake Rider mounted to Enslaved Proto Drake',6,30000);

-- Create required spellclick information
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=24083;
INSERT INTO `npc_spellclick_spells`(`npc_entry`,`spell_id`,`cast_flags`) VALUES
(24083,55074,1);

-- Remove no longer needed data
DELETE FROM `creature` WHERE `guid`=125912 AND `map`=574 AND `id`=24849;
DELETE FROM `creature_addon` WHERE `guid`=125912;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=24083;
