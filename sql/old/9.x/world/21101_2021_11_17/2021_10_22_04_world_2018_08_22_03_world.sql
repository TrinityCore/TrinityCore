-- 
UPDATE `creature` SET `position_x`=-327.646, `position_y`=-127.406, `position_z`=-8.013, `orientation`=1.941862  WHERE `guid`=12607;
DELETE FROM `creature` WHERE `guid` IN (12605,12606);
DELETE FROM `creature_addon` WHERE `guid` IN (12605,12606);
