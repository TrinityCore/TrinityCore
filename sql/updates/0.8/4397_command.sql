delete from command where name in('whisper2', 'nyi', 'prog', 'run','go', 'object', 'gmon', 'gmoff', 'worldport');

update command set name='playemote' where name='emote';
update command set name='setmodel' where name='displayid';
update command set name='listgm' where name='gmlist';

update command set security=1 where name in ('gogrid', 'goxy') ;
update command set security=2 where name in ('addgo', 'standstate', 'anim', 'morph');

delete from command where name in('textemote', 'taxicheat','gm','visible');
INSERT INTO `command` VALUES 
('textemote',3,'Syntax: .text #emoteid\r\n\r\nMake the selected creature to do textemote with an emote of id #emoteid.'),
('taxicheat',1,'Syntax: .taxicheat on/off\r\n\r\nTemporary grant access or remove to all taxi routes for the selected character. If no character is selected, hide or reveal all routes to you.\r\n\r\nVisited taxi nodes sill accessible after removing access.'),
('visible',1,'Syntax: .visible on/off\r\n\r\nOutput current visibility state or make GM visible(on) and invisible(off) for other players.'),
('gm', 1, 'Syntax: .gm on/off\r\n\r\nEnable or Disable GM MODE');
