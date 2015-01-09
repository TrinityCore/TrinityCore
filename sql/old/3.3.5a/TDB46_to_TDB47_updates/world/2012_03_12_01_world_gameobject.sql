UPDATE `gameobject_template` SET `flags`=0x32 WHERE `entry` IN (202239,202240,202238,202241,201959,202339,202338,202340);

-- Set Deathbringer's Cache spawned by default
UPDATE `gameobject` SET `spawntimesecs`=604800 WHERE `id` IN (202239,202240,202238,202241);
