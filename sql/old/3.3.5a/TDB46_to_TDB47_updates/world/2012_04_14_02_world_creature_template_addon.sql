UPDATE `creature_template_addon` SET `auras`='50453' WHERE `entry`=28017;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=28017;
UPDATE `creature_template` SET `ainame` = '' WHERE `entry`=28017;