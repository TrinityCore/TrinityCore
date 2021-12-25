-- 
DELETE FROM `creature_addon` WHERE `guid` IN (85585,68738,66853,66844,66893,66854,66888,66849,66883);
DELETE FROM `creature` WHERE `guid` IN (85585,68738,66853,66844,66893,66854,66888,66849,66883);
DELETE FROM `linked_respawn` WHERE `guid` IN (85585,68738,66853,66844,66893,66854,66888,66849,66883);
UPDATE `creature` SET `position_x`=-148.279526, `position_y`=-375.795654, `position_z`=17.080269, `orientation`=4.637824 WHERE `guid`= 66817; 
UPDATE `creature` SET `position_x`=-162.615082, `position_y`=-354.888336, `position_z`=17.083523, `orientation`=4.794886 WHERE `guid`= 66816; 
UPDATE `creature` SET `position_x`=-149.024673, `position_y`=-354.460236, `position_z`=17.083523, `orientation`=4.759542 WHERE `guid`= 66814; 
UPDATE `creature` SET `position_x`=-154.074249, `position_y`=-354.274414, `position_z`=17.083523, `orientation`=4.688859 WHERE `guid`= 66881; 
UPDATE `creature` SET `orientation`=4.688859 WHERE `guid`= 66845;
