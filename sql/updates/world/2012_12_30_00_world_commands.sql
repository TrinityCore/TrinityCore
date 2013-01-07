DELETE FROM `command` WHERE `name` LIKE 'disable add mmap' OR `name` LIKE 'disable remove mmap';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('disable add mmap', '3', 'Syntax: .disable add mmap $entry $flag $comment'),
('disable remove mmap', '3', 'Syntax: .disable remove mmap $entry');
