--
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2 WHERE `entry` IN (18374,20308,21466,21467,21600,21601,17651,21823,29281,30809,33651,34108);
-- They're only unselectable, their faction is hostile, they don't have auras
-- For now leaving feign death aura, later it should be replaced by passive react state, there's no other option
UPDATE `creature` SET `unit_flags` = 33554496 WHERE `id` = 26620 AND `unit_flags` & 33554432;
