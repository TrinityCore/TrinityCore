-- 
UPDATE `creature_template` SET `speed_walk`=1.2, `speed_run`=0.785714 WHERE `entry`=20064;
UPDATE `creature_template_movement` SET `Chase`=0 WHERE `CreatureID` IN (20064);
