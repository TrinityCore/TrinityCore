--
/*
UPDATE `gameobject_template_addon` SET `flags`=`flags`|4 WHERE `entry` IN (SELECT `entry` FROM `gameobject_template` WHERE `type`=2 AND `data3`=0);
*/
