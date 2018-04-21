DELETE FROM script_texts WHERE entry BETWEEN -1000506 AND -1000500;
INSERT INTO script_texts (npc_entry,entry,content_default,sound,type,language,emote,comment) VALUES
(5391, -1000500,'Help! Please, You must help me!',0,0,0,0,'Galen - periodic say'),
(5391, -1000501,'Let us leave this place.',0,0,0,0,'Galen - quest accepted'),
(5391, -1000502,'Look out! The $c attacks!',0,0,0,0,'Galen - aggro 1'),
(5391, -1000503,'Help! I\'m under attack!',0,0,0,0,'Galen - aggro 2'),
(5391, -1000504,'Thank you $N. I will remember you always. You can find my strongbox in my camp, north of Stonard.',0,0,0,0,'Galen - quest complete'),
(5391, -1000505,'%s whispers to $N the secret to opening his strongbox.',0,2,0,0,'Galen - emote whisper'),
(5391, -1000506,'%s disappears into the swamp.',0,2,0,0,'Galen - emote disapper');

