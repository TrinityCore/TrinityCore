-- Adds trigger and civilian flags_extra to Halion's Soul Consumption triggers
UPDATE `creature_template` SET `flags_extra` = `flags_extra` |2|128 WHERE `entry` IN (40673, 40674, 40675);
