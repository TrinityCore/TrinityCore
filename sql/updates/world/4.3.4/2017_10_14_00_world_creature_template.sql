-- fix riding trainer in stormwind / orgrimmar
UPDATE `creature_template` SET `trainer_type` = 1 WHERE `entry` IN (43769, 44919);
