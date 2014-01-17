DELETE FROM `command` WHERE `name` = 'wpgps';
INSERT INTO `command` VALUES
('wpgps', '3', 'Syntax: .wpgps\n\nOutput current position to sql developer log as partial SQL query to be used in pathing');
