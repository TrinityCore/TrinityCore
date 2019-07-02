-- Sister Svalna should drop gold when killed 
UPDATE `creature_template` SET `mingold`=850000,`maxgold`=950000 WHERE `entry` IN (37126);
UPDATE `creature_template` SET `mingold`=1550000,`maxgold`=1750000 WHERE `entry` IN (38258);
