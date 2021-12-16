-- Maulgar's friends should not bind player https://youtu.be/vvMn-f_5PpQ?t=135
UPDATE `creature_template` SET `flags_extra` = `flags_extra` &~ 1 WHERE `entry` IN (18832,18834,18835,18836);
