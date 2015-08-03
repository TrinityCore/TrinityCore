SET @GUID       := 131282;

SET @QUEST      := 11705;
SET @VARIDUS    := 25618;
SET @PRISONER   := 25624;
SET @ABERRATION := 25625;
SET @GETRY      := 25729;
SET @NECROLORD  := 25730;
SET @SAURFANG   := 25751;

UPDATE `creature_template` SET `minlevel`=65, `maxlevel`=70, `exp`=2, `faction_A`=14, `faction_H`=14, `unit_flags`=33554688, `AIName`='SmartAI' WHERE `entry`=@PRISONER;
UPDATE `creature_template` SET `faction_A`=1982, `faction_H`=1982, `unit_flags`=0, `AIName`='SmartAI' WHERE `entry`=@ABERRATION;
UPDATE `creature_template` SET `speed_run`=2.28571, `faction_A`=1982, `faction_H`=1982, `unit_flags`=33536, `AIName`='SmartAI' WHERE `entry`=@NECROLORD;
UPDATE `creature_template` SET `faction_A`=1982, `faction_H`=1982, `unit_flags`=768, `AIName`= 'SmartAI', `ScriptName`='' WHERE `entry`=@VARIDUS;
UPDATE `creature_template` SET `faction_A`=1980, `faction_H`=1980, `minlevel`=70, `maxlevel`=70, `exp`=2, `unit_flags`=33024, `mindmg`=474, `maxdmg`=574, `AIName`= 'SmartAI' WHERE `entry`=@SAURFANG;
UPDATE `creature_template` SET `unit_flags`=32768, `AIName`= 'SmartAI' WHERE `entry`=@GETRY;

UPDATE `creature_model_info` SET `bounding_radius`=0.4092, `combat_reach`=1.65 WHERE `modelid`=23360;

DELETE FROM `creature_template_addon` WHERE `entry` IN(@GETRY,@PRISONER,@VARIDUS);
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`auras`) VALUES
(@VARIDUS,0x1,'45908'),
(@PRISONER,0x1,''),
(@GETRY,0x101,'');

DELETE FROM `creature` WHERE `id` IN (@PRISONER,@VARIDUS);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES 
(@GUID+0, @PRISONER, 571, 1, 1, 0, 0, 3092.136, 6516.039, 82.06012, 5.183628, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+1, @PRISONER, 571, 1, 1, 0, 0, 3089.2, 6526.226, 81.77282, 1.902409, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+2, @PRISONER, 571, 1, 1, 0, 0, 3096.962, 6510.87, 82.08541, 0.5585054, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+3, @PRISONER, 571, 1, 1, 0, 0, 3093.876, 6522.219, 81.79565, 0.01745329, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+4, @PRISONER, 571, 1, 1, 0, 0, 3098.928, 6517.495, 81.77497, 3.001966, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+5, @PRISONER, 571, 1, 1, 0, 0, 3103.036, 6504.89, 82.04672, 3.944444, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+6, @PRISONER, 571, 1, 1, 0, 0, 3104.042, 6511.731, 81.80676, 3.455752, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+7, @PRISONER, 571, 1, 1, 0, 0, 3093.038, 6547.074, 80.75952, 5.899213, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+8, @PRISONER, 571, 1, 1, 0, 0, 3096.117, 6544.481, 80.7102, 1.605703, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+9, @PRISONER, 571, 1, 1, 0, 0, 3099.3, 6541.367, 80.77256, 4.799655, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+10, @PRISONER, 571, 1, 1, 0, 0, 3090.39, 6541.875, 81.06445, 3.054326, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+11, @PRISONER, 571, 1, 1, 0, 0, 3102.454, 6538.238, 80.83416, 1.58825, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+12, @PRISONER, 571, 1, 1, 0, 0, 3093.245, 6538.743, 81.06524, 3.455752, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+13, @PRISONER, 571, 1, 1, 0, 0, 3105.601, 6534.979, 80.85965, 0.1570796, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+14, @PRISONER, 571, 1, 1, 0, 0, 3096.462, 6535.528, 81.13345, 4.921828, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+15, @PRISONER, 571, 1, 1, 0, 0, 3087.603, 6536.683, 81.36699, 4.18879, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+16, @PRISONER, 571, 1, 1, 0, 0, 3108.599, 6531.898, 80.8754, 5.462881, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+17, @PRISONER, 571, 1, 1, 0, 0, 3100.571, 6532.094, 81.16553, 6.230825, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+18, @PRISONER, 571, 1, 1, 0, 0, 3122.098, 6518.814, 80.70912, 1.815142, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+19, @PRISONER, 571, 1, 1, 0, 0, 3116.981, 6515.013, 81.07998, 5.899213, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+20, @PRISONER, 571, 1, 1, 0, 0, 3126.142, 6514.962, 80.68482, 1.954769, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+21, @PRISONER, 571, 1, 1, 0, 0, 3112.065, 6511.906, 81.3951, 5.148721, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+22, @PRISONER, 571, 1, 1, 0, 0, 3129.413, 6511.592, 80.7066, 2.722714, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+23, @PRISONER, 571, 1, 1, 0, 0, 3122.214, 6510.255, 81.00794, 2.86234, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+24, @PRISONER, 571, 1, 1, 0, 0, 3116.414, 6507.338, 81.34387, 5.811946, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+25, @PRISONER, 571, 1, 1, 0, 0, 3109.384, 6506.753, 81.68826, 6.038839, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+26, @PRISONER, 571, 1, 1, 0, 0, 3126.804, 6505.612, 81.01304, 3.909538, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+27, @PRISONER, 571, 1, 1, 0, 0, 3120.997, 6502.847, 81.33372, 3.228859, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+28, @PRISONER, 571, 1, 1, 0, 0, 3114.636, 6501.495, 81.61775, 0.3490658, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+29, @PRISONER, 571, 1, 1, 0, 0, 3109.11, 6498.783, 81.92492, 2.635447, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+30, @PRISONER, 571, 1, 1, 0, 0, 3126.413, 6498.179, 81.30205, 6.248279, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+31, @PRISONER, 571, 1, 1, 0, 0, 3120.758, 6495.855, 81.59259, 2.495821, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+32, @PRISONER, 571, 1, 1, 0, 0, 3115.22, 6492.261, 81.93079, 5.5676, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+33, @PRISONER, 571, 1, 1, 0, 0, 3126.15, 6489.568, 81.65459, 2.146755, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+34, @PRISONER, 571, 1, 1, 0, 0, 3120.454, 6486.966, 81.9426, 1.902409, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+35, @PRISONER, 571, 1, 1, 0, 0, 3095.756, 6528.297, 81.4939, 4.433136, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+36, @PRISONER, 571, 1, 1, 0, 0, 3091.309, 6532.723, 81.41476, 4.502949, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+37, @PRISONER, 571, 1, 1, 0, 0, 3104.285, 6519.577, 81.50758, 6.178465, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+38, @PRISONER, 571, 1, 1, 0, 0, 3112.36, 6527.987, 80.87508, 3.630285, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+39, @PRISONER, 571, 1, 1, 0, 0, 3104.28, 6528.084, 81.18883, 3.420845, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+40, @PRISONER, 571, 1, 1, 0, 0, 3116.763, 6524.073, 80.84852, 6.021386, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+41, @PRISONER, 571, 1, 1, 0, 0, 3099.789, 6524.306, 81.51059, 3.368485, 15, 0, 0, 1848, 0, 0, 0, 0, 0),
(@GUID+42, @VARIDUS, 571, 1, 1, 0, 0, 3126.529, 6532.781, 80.06363, 5.576992, 60, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GETRY,@VARIDUS,@NECROLORD,@PRISONER,@ABERRATION) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@VARIDUS*100 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@VARIDUS,0,0,0,38,0,100,0,0,1,0,0,69,1,0,0,0,0,0,8,0,0,0,3119.973,6539.042,80.1591, 0, 'Varidus the Flenser - On data 0 1 set - Move to position'),
(@VARIDUS,0,1,2,34,0,100,0,0,1,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,4.031711, 'Varidus the Flenser - On movement inform - Set orientation'),
(@VARIDUS,0,2,3,61,0,100,0,0,0,0,0,1,11,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On movement inform - Say line'),
(@VARIDUS,0,3,0,61,0,100,0,0,0,0,0,89,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On movement inform - Stop Random movement'),
(@VARIDUS,0,4,0,38,0,100,0,0,2,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On data 0 2 set - Say line'),
(@VARIDUS,0,5,0,52,0,100,0,0,@VARIDUS,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Varidus the Flenser - On text 0 over - Turn to'),
(@VARIDUS,0,6,7,38,0,100,0,0,3,0,0,1,1,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Varidus the Flenser - On data 0 3 set - Say line'),
(@VARIDUS,0,7,8,61,0,100,0,0,0,0,0,12,@NECROLORD,1,300000,0,0,0,8,0,0,0,3137.506,6532.551,80.40143,2.280419, 'Varidus the Flenser - On data 0 3 set - Summon En''kilah Necrolord'),
(@VARIDUS,0,8,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@NECROLORD,50,0,0,0,0,0, 'Varidus the Flenser - On data 0 3 set - Send targetlist'),
(@VARIDUS,0,9,0,38,0,100,0,0,4,0,0,80,@VARIDUS*100,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On data 0 4 set - Run script'),
(@VARIDUS,0,10,11,52,0,100,0,10,@VARIDUS,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On text 10 over - Remove unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC'),
(@VARIDUS,0,11,0,61,0,100,0,0,0,0,0,28,45908,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On text 10 over - Remove aura Shield of Suffering'),
(@VARIDUS,0,12,0,9,0,100,0,0,10,5000,8000,11,32711,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On target within 10y - Spellcast Shadow Nova'),
(@VARIDUS,0,13,0,0,0,100,0,10000,12000,10000,15000,11,50329,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On update IC - Spellcast Shied of Suffering'),
(@VARIDUS,0,14,15,6,0,100,0,0,0,0,0,45,1,3,0,0,0,0,19,@GETRY,100,0,0,0,0,0, 'Varidus the Flenser - On death - Set data 1 3 Shadowstalker Getry'),
(@VARIDUS,0,15,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On death - Despawn'),
(@VARIDUS,0,16,0,11,0,100,0,0,0,0,0,89,10,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On spawn - Random movement'),

(@PRISONER,0,0,1,6,0,100,0,0,0,0,0,11,45802,2,0,0,0,0,1,0,0,0,0,0,0,0, 'Infested Prisoner - On death - Spellcast Summoned Aberration'),
(@PRISONER,0,1,0,61,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Infested Prisoner - On death - Despawn'),

(@ABERRATION,0,0,1,11,0,100,0,0,0,0,0,53,0,@ABERRATION,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Aberration - On spawn - Start WP movement'),
(@ABERRATION,0,1,0,61,0,100,0,0,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warsong Aberration - On spawn - Set reaction aggressive'),
(@ABERRATION,0,2,0,9,0,100,0,0,5,990,3000,11,50306,2,0,0,0,0,7,0,0,0,0,0,0,0, 'Warsong Aberration - On target within 5y - Spellcast Thrash Kick'),

(@GETRY,0,0,1,19,0,100,0,@QUEST,0,0,0,64,1,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Store targetlist'),
(@GETRY,0,1,2,61,0,100,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Remove npcflag questgiver'),
(@GETRY,0,2,3,61,0,100,0,0,0,0,0,1,0,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Say line'),
(@GETRY,0,3,4,61,0,100,0,0,0,0,0,11,45924,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Spellcast On Getry''s Quest'),
(@GETRY,0,4,5,61,0,100,0,0,0,0,0,11,45924,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Spellcast On Getry''s Quest'),
(@GETRY,0,5,0,61,0,100,0,0,0,0,0,45,0,1,0,0,0,0,19,@VARIDUS,50,0,0,0,0,0, 'Shadowstalker Getry - On quest accept - Set data 0 1 Varidus the Flenser'),
(@GETRY,0,6,7,52,0,100,0,0,@GETRY,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On text 0 over - Say line'),
(@GETRY,0,7,0,61,0,100,0,0,0,0,0,53,0,@GETRY,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On text 0 over - Start WP'),
(@GETRY,0,8,0,11,0,100,0,0,0,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On spawn - Set npcflag questgiver'),
(@GETRY,0,9,0,40,0,100,0,8,@GETRY,0,0,11,34189,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP8 reached - Spellcast Stealth'),
(@GETRY,0,10,11,40,0,100,0,9,@GETRY,0,0,45,0,2,0,0,0,0,19,@VARIDUS,30,0,0,0,0,0, 'Shadowstalker Getry - On WP 9 reached - Set data 0 2 Varidus the Flenser'),
(@GETRY,0,11,0,61,0,100,0,0,0,0,0,100,1,0,0,0,0,0,19,@VARIDUS,30,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Send targetlist to Varidus the Flenser'),
(@GETRY,0,12,13,40,0,100,0,10,@GETRY,0,0,66,0,0,0,0,0,0,19,@VARIDUS,20,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Turn to'),
(@GETRY,0,13,14,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Set home position'),
(@GETRY,0,14,15,61,0,100,0,0,0,0,0,28,34189,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Remove aura Stealth'),
(@GETRY,0,15,16,61,0,100,0,0,0,0,0,11,45922,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Spellcast Shadow Prison'),
(@GETRY,0,16,17,61,0,100,0,0,0,0,0,86,45922,0,12,1,0,0,12,1,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Crosscast Shadow Prison'),
(@GETRY,0,17,0,61,0,100,0,0,0,0,0,45,0,3,0,0,0,0,19,@VARIDUS,20,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached - Set Data 0 3 Varidus the Flenser'),
(@GETRY,0,18,19,38,0,100,0,1,1,0,0,19,768,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 1 set - Remove unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC'),
(@GETRY,0,19,0,61,0,100,0,0,0,0,0,49,0,0,0,0,0,0,19,@VARIDUS,20,0,0,0,0,0, 'Shadowstalker Getry - On data 1 1 set - Start attack'),
(@GETRY,0,20,21,38,0,100,0,1,3,0,0,15,@QUEST,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 3 set - Quest credit'),
(@GETRY,0,21,0,61,0,100,0,0,0,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 3 set - Say line'),
(@GETRY,0,22,0,52,0,100,0,2,@GETRY,0,0,1,3,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On text 2 over - Say line'),
(@GETRY,0,23,0,52,0,100,0,3,@GETRY,0,0,45,1,2,0,0,0,0,19,@SAURFANG,20,0,0,0,0,0, 'Shadowstalker Getry - On text 3 over - Set data 1 2 High Overlord Saurfang'),
(@GETRY,0,24,0,38,0,100,0,1,4,0,0,53,0,@GETRY*100,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On data 1 4 set - Start WP movement'),
(@GETRY,0,26,27,40,0,100,0,10,@GETRY*100,0,0,81,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached (Return) - Set npcflag questgiver'),
(@GETRY,0,27,28,61,0,100,0,0,0,0,0,18,756,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached (Return) - Set unit_flags IMMUNE_TO_PC, IMMUNE_TO_NPC'),
(@GETRY,0,28,0,61,0,100,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On WP10 reached (Return) - Set homeposition'),
(@GETRY,0,29,30,8,0,100,0,45950,0,0,0,28,45922,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Shadowstalker Getry - On spellhit Saurfangs Rage - Remove aura Shadow Prison'),
(@GETRY,0,30,0,61,0,100,0,0,0,0,0,28,45922,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Shadowstalker Getry - On spellhit Saurfangs Rage - Remove aura Shadow Prison'),

(@NECROLORD,0,0,0,11,0,100,0,0,0,0,0,53,0,@NECROLORD,0,0,0,0,1,0,0,0,0,0,0,0, 'En''kilah Necrolord - On spawn - Start WP movement'),
(@NECROLORD,0,1,2,40,0,100,0,2,@NECROLORD,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'En''kilah Necrolord - On reached WP1 - Set home position'),
(@NECROLORD,0,2,0,61,0,100,0,0,0,0,0,45,0,4,0,0,0,0,19,@VARIDUS,10,0,0,0,0,0, 'En''kilah Necrolord - On reached WP1 - Set data 0 4 Varidus the Flenser'),
(@NECROLORD,0,3,4,38,0,100,0,0,1,0,0,66,0,0,0,0,0,0,19,@VARIDUS,10,0,0,0,0,0, 'En''kilah Necrolord - On data 0 1 set - Turn to'),
(@NECROLORD,0,4,0,61,0,100,0,0,0,0,0,36,@SAURFANG,0,0,0,0,0,1,0,0,0,0,0,0,0, 'En''kilah Necrolord - On data 0 1 set - Change entry to High Overlord Saurfang'),
(@NECROLORD,0,5,0,38,0,100,0,0,2,0,0,1,0,2500,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 2 set - Say line'),
(@NECROLORD,0,6,0,52,0,100,0,0,@SAURFANG,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On text 0 over - Turn to'),
(@NECROLORD,0,7,0,38,0,100,0,0,3,0,0,1,1,4000,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 3 set - Say line'),
(@NECROLORD,0,8,0,52,0,100,0,1,@SAURFANG,0,0,66,0,0,0,0,0,0,19,@VARIDUS,10,0,0,0,0,0, 'High Overlord Saurfang - On text 1 over - Turn to'),
(@NECROLORD,0,9,0,38,0,100,0,0,4,0,0,1,2,5000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 4 set - Say line'),
(@NECROLORD,0,10,0,52,0,100,0,2,@SAURFANG,0,0,1,3,12000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 2 over - Say line'),
(@NECROLORD,0,11,0,52,0,100,0,3,@SAURFANG,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 3 over - Say line'),
(@NECROLORD,0,13,14,38,0,100,0,1,1,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 1 set - Remove unit_flags IMMUNE_TO_NPC'),
(@NECROLORD,0,14,15,61,0,100,0,0,0,0,0,11,45950,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 1 set - Spellcast Saurfang''s Rage'),
(@NECROLORD,0,15,0,61,0,100,0,0,0,0,0,1,5,1000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 1 set - Say line'),
(@NECROLORD,0,16,0,52,0,100,0,5,@SAURFANG,0,0,1,6,1000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 5 over - Say line'),
(@NECROLORD,0,17,0,61,0,100,0,0,0,0,0,41,3000,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On text 7 over - Despawn after 3 seconds'),
(@NECROLORD,0,18,0,9,0,100,0,0,5,20000,25000,11,41097,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On target within 5y - Spellcast Whirlwind'),
(@NECROLORD,0,19,0,0,0,100,0,3000,7000,3000,8000,11,16044,0,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On update IC - Spellcast Cleave'),
(@NECROLORD,0,20,0,0,0,100,0,2000,7000,5000,7000,11,24573,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Overlord Saurfang - On update IC - Spellcast Mortal Strike'),
(@NECROLORD,0,21,0,9,0,100,0,8,25,5000,5000,11,15749,0,0,0,0,0,2,0,0,0,0,0,0,0, 'High Overlord Saurfang - On target within 8-25y - Spellcast Shield Charge'),
(@NECROLORD,0,22,0,38,0,100,0,0,5,0,0,66,0,0,0,0,0,0,12,1,0,0,0,0,0,0, 'High Overlord Saurfang - On data 0 5 set - Turn to'),
(@NECROLORD,0,23,0,38,0,100,0,1,2,0,0,1,7,3000,0,0,0,0,1,0,0,0,0,0,0,0, 'High Overlord Saurfang - On data 1 2 set - Say line'),
(@NECROLORD,0,24,17,52,0,100,0,7,@SAURFANG,0,0,45,1,4,0,0,0,0,19,@GETRY,20,0,0,0,0,0, 'High Overlord Saurfang - On text 7 over - Set data 1 4 Shadowstalker Getry'),

(@VARIDUS*100,9,0,0,0,0,100,0,0,0,0,0,45,0,5,0,0,0,0,19,@NECROLORD,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 5 En''kilah Necrolord'),
(@VARIDUS*100,9,1,0,0,0,100,0,0,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,2,0,0,0,100,0,5000,5000,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,3,0,0,0,100,0,3000,3000,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,4,0,0,0,100,0,4000,4000,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,5,0,0,0,100,0,6000,6000,0,0,66,0,0,0,0,0,0,19,@NECROLORD,10,0,0,0,0,0, 'Varidus the Flenser script - Turn to'),
(@VARIDUS*100,9,6,0,0,0,100,0,1000,1000,0,0,1,6,0,0,0,0,0,12,1,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,7,0,0,0,100,0,6000,6000,0,0,45,0,1,0,0,0,0,19,@NECROLORD,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 1 En''kilah Necrolord'),
(@VARIDUS*100,9,8,0,0,0,100,0,1000,1000,0,0,45,0,2,0,0,0,0,19,@SAURFANG,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 2 High Overlord Saurfang'),
(@VARIDUS*100,9,9,0,0,0,100,0,1500,1500,0,0,1,7,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,10,0,0,0,100,0,2000,2000,0,0,45,0,3,0,0,0,0,19,@SAURFANG,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 3 High Overlord Saurfang'),
(@VARIDUS*100,9,11,0,0,0,100,0,5000,5000,0,0,45,0,4,0,0,0,0,19,@SAURFANG,10,0,0,0,0,0, 'Varidus the Flenser script - Set data 0 4 High Overlord Saurfang'),
(@VARIDUS*100,9,12,0,0,0,100,0,13000,13000,0,0,1,8,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,13,0,0,0,100,0,10000,10000,0,0,1,9,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Say line'),
(@VARIDUS*100,9,14,0,0,0,100,0,2000,2000,0,0,1,10,2000,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser - On text 9 over - Say line'),
(@VARIDUS*100,9,15,0,0,0,100,0,0,0,0,0,11,45949,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Varidus the Flenser script - Spellcast Release Aberration'),
(@VARIDUS*100,9,16,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@GETRY,20,0,0,0,0,0, 'Varidus the Flenser script - Set data 1 1 Shadowstalker Getry'),
(@VARIDUS*100,9,17,0,0,0,100,0,0,0,0,0,45,1,1,0,0,0,0,19,@SAURFANG,20,0,0,0,0,0, 'Varidus the Flenser script - Set data 1 1 Saurfang');

DELETE FROM `creature_text` WHERE `entry` IN (@GETRY,@VARIDUS,@SAURFANG);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@GETRY,0,0,'This is it, $N. The start of the end of the world. And you''re here to see it off...',12,1,100,1,0,0,'Shadowstalker Getry'),
(@GETRY,1,0,'Let''s go...',12,1,100,0,0,0,'Shadowstalker Getry'),
(@GETRY,2,0,'I... I can''t believe it... Saurfang... I... I am honored... honored to have fought along side you, sir.',12,1,100,0,0,0,'Shadowstalker Getry'),
(@GETRY,3,0,'You should return to Warsong Hold now, friend. Hellscream will surely want to hear of what just happened here... of Saurfang...',12,1,100,0,0,0,'Shadowstalker Getry'),
(@VARIDUS,0,0,'Is this it? Is this all the mighty Horde could muster?',12,0,100,6,0,0,'Varidus the Flenser'),
(@VARIDUS,1,0,'Pathetic.',12,0,100,11,0,0,'Varidus the Flenser'),
(@VARIDUS,2,0,'I''ve never understood your type. The hero...',12,0,100,1,0,0,'Varidus the Flenser'),
(@VARIDUS,3,0,'Why won''t you just let go? Why do you fight the inevitable?',12,0,100,6,0,0,'Varidus the Flenser'),
(@VARIDUS,4,0,'The Lich King cannot be stopped. Accept it.',12,0,100,274,0,0,'Varidus the Flenser'),
(@VARIDUS,5,0,'This world is coming to an end. Let. It. Burn.',12,0,100,397,0,0,'Varidus the Flenser'),
(@VARIDUS,6,0,'Take $g him:her; away and prepare $g him:her; for reanimation.',12,0,100,1,0,0,'Varidus the Flenser'),
(@VARIDUS,7,0,'What''s this now?',12,0,100,1,0,0,'Varidus the Flenser'),
(@VARIDUS,8,0,'Then you are a fool.',12,0,100,25,0,0,'Varidus the Flenser'),
(@VARIDUS,9,0,'You? A lone orc? Against me and...',12,0,100,397,0,0,'Varidus the Flenser'),
(@VARIDUS,10,0,'RISE!',14,0,100,0,0,0,'Varidus the Flenser'),
(@VARIDUS,11,0,'I will reanimate them all as servants of the Lich King! Bring them here...',14,0,100,0,0,0,'Varidus the Flenser'),
(@SAURFANG,0,0,'I''ll rip your shriveled heart out with my bare hands before any harm comes to $N, necromancer.',12,1,100,5,0,0,'High Overlord Saurfang'),
(@SAURFANG,1,0,'You were never alone, $N.',12,1,100,1,0,0,'High Overlord Saurfang'),
(@SAURFANG,2,0,'This world that you seek to destroy is our home.',12,1,100,1,0,0,'High Overlord Saurfang'),
(@SAURFANG,3,0,'We will fight you with every fiber of our being - until we are nothing more than dust and debris. We will fight until the end.',12,1,100,1,0,0,'High Overlord Saurfang'),
(@SAURFANG,4,0,'A fool who is about to end you, necrolord. There will be nothing left of you for the Lich King to reanimate!',12,1,100,397,0,0,'High Overlord Saurfang'),
(@SAURFANG,5,0,'%s''s eyes glow red for a brief moment.',16,0,100,0,0,0,'High Overlord Saurfang'),
(@SAURFANG,6,0,'Is that the best you can do?',12,1,100,0,0,0,'High Overlord Saurfang'),
(@SAURFANG,7,0,'You''ll make no mention of me. Either of you!',12,1,100,0,0,0,'High Overlord Saurfang');

DELETE FROM `waypoints` WHERE `entry` IN (@GETRY,@NECROLORD,@GETRY*100,@ABERRATION);
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES 
(@GETRY, 1, 3109.214111,6587.148438,91.369102, 'Shadowstalker Getry'),
(@GETRY, 2, 3115.414062,6595.680176,91.362068, 'Shadowstalker Getry'),
(@GETRY, 3, 3125.109863,6590.983887,91.378548, 'Shadowstalker Getry'),
(@GETRY, 4, 3123.863281,6582.144043,88.786133, 'Shadowstalker Getry'),
(@GETRY, 5, 3117.805664,6583.018555,86.219604, 'Shadowstalker Getry'),
(@GETRY, 6, 3118.874512,6590.157715,83.402168, 'Shadowstalker Getry'),
(@GETRY, 7, 3127.298340,6589.030273,79.707741, 'Shadowstalker Getry'),
(@GETRY, 8, 3122.869,6578.715,78.051, 'Shadowstalker Getry'),
(@GETRY, 9, 3123.309,6560.647,78.61833, 'Shadowstalker Getry'),
(@GETRY, 10,  3122.208,6549.245,79.64079, 'Shadowstalker Getry'),
(@ABERRATION, 1, 3119.973,6539.042,80.1591, 'Warsong Aberration'),
(@NECROLORD, 1, 3125.963,6536.96,79.93521, 'En''kilah Necrolord'),
(@NECROLORD, 2, 3120.883,6542.995,79.95628, 'En''kilah Necrolord'),
(@GETRY*100, 1, 3123.355957,6575.417969,78.330284, 'Shadowstalker Getry'), 
(@GETRY*100, 2, 3126.639404,6584.798828,77.656845, 'Shadowstalker Getry'), 
(@GETRY*100, 3, 3127.298340,6589.030273,79.707741, 'Shadowstalker Getry'),
(@GETRY*100, 4, 3118.874512,6590.157715,83.402168, 'Shadowstalker Getry'),
(@GETRY*100, 5, 3117.805664,6583.018555,86.219604, 'Shadowstalker Getry'),
(@GETRY*100, 6, 3123.863281,6582.144043,88.786133, 'Shadowstalker Getry'),
(@GETRY*100, 7, 3125.109863,6590.983887,91.378548, 'Shadowstalker Getry'),
(@GETRY*100, 8, 3115.414062,6595.680176,91.362068, 'Shadowstalker Getry'),
(@GETRY*100, 9, 3109.214111,6587.148438,91.369102, 'Shadowstalker Getry'),
(@GETRY*100, 10, 3113.419922,6576.810059,97.090698, 'Shadowstalker Getry');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry`=45949;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=@GETRY;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13,1,45949,0,0,31,0,3,@PRISONER,0,0,0,'','Spell Release Aberration targets Infested Prisoner'),
(22,37,@GETRY,0,0,36,1,0,0,0,0,0,'','Only execute SAI if Shadowstalker Getry alive');

DELETE FROM `creature_equip_template` WHERE `entry`=@SAURFANG;
INSERT INTO `creature_equip_template` (`entry`, `id`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES 
(@SAURFANG,1,21580,0,0);

DELETE FROM `disables` WHERE `sourceType`=0 AND `entry`=45949;
INSERT INTO `disables` (`sourceType`, `entry`, `flags`, `params_0`, `params_1`, `comment`) VALUES 
(0,45949,64,'','','Ignore LOS on Release Aberration');
