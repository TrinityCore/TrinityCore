DELETE FROM script_texts WHERE entry BETWEEN -1000516 AND -1000507;
INSERT INTO script_texts (npc_entry,entry,content_default,sound,type,language,emote,comment) VALUES
(4880, -1000507,'Ok, let''s get started.',0,0,0,0,'stinky - quest accepted'),
(4880, -1000508,'Now let''s look for the herb.',0,0,0,0,'stinky - say1'),
(4880, -1000509,'Nope, not here...',0,0,0,0,'stinky - say2'),
(4880, -1000510,'There must be one around here somewhere...',0,0,0,0,'stinky - say3'),
(4880, -1000511,'Ah, there''s one! ',0,0,0,0,'stinky - say4'),
(4880, -1000512,'Come, $N!  Let''s go over there and collect it!',0,0,0,0,'stinky - say5'),
(4880, -1000513,'Ok, now let''s get out of here! ',0,0,0,0,'stinky - say6'),
(4880, -1000514,'I can make it from here.  Thanks, $N!  And talk to my employer about a reward!',0,0,0,0,'stinky - quest complete'),
(4880, -1000515,'Help! The beast is on me!',0,0,0,0,'stinky - aggro'),
(4880, -1000516,'%s disappears back into the swamp.',0,2,0,0,'stinky - emote disapper');
