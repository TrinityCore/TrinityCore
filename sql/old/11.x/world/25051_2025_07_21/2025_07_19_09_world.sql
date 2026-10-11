-- Nightelf
DELETE FROM `playercreateinfo_action` WHERE (`race`=4 AND `class`=12 AND `button`=11);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(4, 12, 11, 200175, 0); -- Felsaber

UPDATE `playercreateinfo_action` SET `action`=344862 WHERE (`race`=4 AND `class`=12 AND `button`=2); -- Chaos Strike
UPDATE `playercreateinfo_action` SET `action`=344859 WHERE (`race`=4 AND `class`=12 AND `button`=1); -- Demon's Bite
UPDATE `playercreateinfo_action` SET `action`=344865 WHERE (`race`=4 AND `class`=12 AND `button`=0); -- Fel Rush

-- Bloodelf
DELETE FROM `playercreateinfo_action` WHERE (`race`=10 AND `class`=12 AND `button`=11);
INSERT INTO `playercreateinfo_action` (`race`, `class`, `button`, `action`, `type`) VALUES
(10, 12, 11, 200175, 0); -- Felsaber

UPDATE `playercreateinfo_action` SET `action`=344862 WHERE (`race`=10 AND `class`=12 AND `button`=2); -- Chaos Strike
UPDATE `playercreateinfo_action` SET `action`=344859 WHERE (`race`=10 AND `class`=12 AND `button`=1); -- Demon's Bite
UPDATE `playercreateinfo_action` SET `action`=344865 WHERE (`race`=10 AND `class`=12 AND `button`=0); -- Fel Rush
