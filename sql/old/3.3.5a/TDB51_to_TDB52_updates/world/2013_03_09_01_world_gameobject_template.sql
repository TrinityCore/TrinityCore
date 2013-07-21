-- Update some gameobject data that is correct in WDB, but parsed wrong for some reason
UPDATE `gameobject_template` SET `faction`=35,`data17`=1,`data18`=0 WHERE `entry`=193908;
