DELETE FROM `command` WHERE `name`='debug play objectsound';
INSERT INTO `command` (`name`, `help`) VALUES 
('debug play objectsound', 'Syntax: .debug play objectsound #soundKitId [#broadcastTextId]\nPlay object sound with #soundKitId [and #broadcastTextId].\nSound will be played only for you. Other players will not hear this.');
