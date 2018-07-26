DELETE FROM gameobject WHERE guid IN (191963, 191961);
UPDATE `creature_template` SET `InhabitType` = '4' WHERE `entry` = 33186; 

DELETE FROM `smart_scripts` WHERE `entryorguid` = 194569;
insert into `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) values
('194569','1','0','9','62','0','100','0','10389','0','0','0','','11','64014','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 0 - Cast \"Expedition Base Camp Teleport\"'),
('194569','1','1','9','62','0','100','0','10389','1','0','0','','11','64032','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 1 - Cast \"Formation Grounds Teleport\"'),
('194569','1','2','9','62','0','100','0','10389','3','0','0','','11','64028','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 3 - Cast \"Colossal Forge Teleport\"'),
('194569','1','3','9','62','0','100','0','10389','4','0','0','','11','64031','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 4 - Cast \"Scrapyard Teleport\"'),
('194569','1','4','9','62','0','100','0','10389','5','0','0','','11','64030','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 5 - Cast \"Antechamber Teleport\"'),
('194569','1','5','9','62','0','100','0','10389','6','0','0','','11','64029','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 6 - Cast \"Shattered Walkway Teleport\"'),
('194569','1','6','9','62','0','100','0','10389','10','0','0','','11','64024','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 10 - Cast \"Conservatory Teleport\"'),
('194569','1','7','9','62','0','100','0','10389','12','0','0','','11','64025','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 12 - Cast \"Halls of Invention Teleport\"'),
('194569','1','8','9','62','0','100','0','10389','15','0','0','','11','65042','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - On gossip select 15 - Cast \"Prison of Yogg-Saron Teleport\"'),
('194569','1','9','0','61','0','100','0','0','0','0','0','','72','0','0','0','0','0','0','7','0','0','0','0','0','0','0','Ulduar Teleporter - Linked with Previous Event - Close gossip');

DELETE FROM `gameobject_template` WHERE `entry` = 194569;
insert into `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `RequiredLevel`, `AIName`, `ScriptName`, `VerifiedBuild`) values
('194569','10','8632','Ulduar Teleporter','','','','1','0','0','0','0','0','0','0','0','0','0','0','0','0','1','0','0','0','1','0','10389','1','0','0','0','0','0','0','0','0','0','0','0','0','0','SmartGameObjectAI','','17538');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` = 10389;
insert into `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) values
('15','10389','1','0','0','13','1','20','2','0','0','0','0','','Show options for gossip only if 2 Collossus death'),
('15','10389','3','0','0','13','1','0','3','2','0','0','0','','Show options for gossip only if BOSS_LEVIATHAN done'),
('15','10389','4','0','0','13','1','3','3','2','0','0','0','','Show options for gossip only if BOSS_XT002 done'),
('15','10389','5','0','0','13','1','3','3','2','0','0','0','','Show options for gossip only if BOSS_XT002 done'),
('15','10389','6','0','0','13','1','5','3','2','0','0','0','','Show options for gossip only if BOSS_KOLOGARN done'),
('15','10389','12','0','0','13','1','5','3','2','0','0','0','','Show options for gossip only if BOSS_KOLOGARN done'),
('15','10389','10','0','0','13','1','6','3','2','0','0','0','','Show options for gossip only if BOSS_AURIAYA done'),
('15','10389','15','0','0','13','1','11','3','2','0','0','0','','Show options for gossip only if BOSS_VEZAX done');

UPDATE `gameobject_template_addon` SET `flags` = '32' WHERE `entry` = '194569'; 

DELETE FROM creature WHERE id = 32871;
